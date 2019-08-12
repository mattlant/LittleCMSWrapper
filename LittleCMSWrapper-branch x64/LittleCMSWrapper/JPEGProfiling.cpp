#pragma managed
#include "Stdafx.h"

using namespace System::Runtime::InteropServices;

#include "iccjpeg.c"

namespace LittleCMSWrapper
{
#pragma region Static Internal Functions
	static void _JPEGErrorMgr_exit (j_common_ptr cinfo)
	{
		// struct my_error_mgr *myerr = (struct my_error_mgr *) cinfo->err;
		char buffer[JMSG_LENGTH_MAX];

		(*cinfo->err->format_message) (cinfo, buffer);
		lcmsErrorManager::SignalError(buffer);
	}

	static void _JPEGErrorMgr_output_message (j_common_ptr cinfo)
	{
		char buffer[JMSG_LENGTH_MAX];

		(*cinfo->err->format_message) (cinfo, buffer);
		lcmsErrorManager::SignalError(buffer);
	}

	//static char* GetErrorText(const char* errorMsg, ...)
	//{
 //      va_list args;

 //      va_start(args, errorMsg);
 //      
 //      char Buffer[1024];

 //      vsnprintf(Buffer, 1023, errorMsg, args);

 //      va_end(args);

 //      return Buffer;
	//}
#pragma endregion

#pragma region lcmsProfile   functions that need JPEG functionalities
	
	lcmsProfile^ lcmsProfile::OpenEmbeddedProfileFromJpeg(String^ jpegFileName)
	{
		IntPtr ptrJpegFile = Marshal::StringToCoTaskMemAnsi(jpegFileName);
		const char *fileName = (const char*)ptrJpegFile.ToPointer();		
		
		//Open the file

		FILE *jpegFile = fopen(fileName,"rb");

		if(jpegFile == NULL) return nullptr;

		//Initialize the JPEG decompression object
		struct jpeg_decompress_struct	jpegDecompressor;

		struct jpeg_error_mgr myErrorMgr;

		jpegDecompressor.err     	= jpeg_std_error(&myErrorMgr);
		myErrorMgr.error_exit		= _JPEGErrorMgr_exit;
		myErrorMgr.output_message	= _JPEGErrorMgr_output_message;

		jpeg_create_decompress(&jpegDecompressor);
		jpeg_stdio_src(&jpegDecompressor, jpegFile);

		for(int i = 0; i < 16; i++)										//TODO: Check If I can get rid of this step
			jpeg_save_markers(&jpegDecompressor,JPEG_APP0, 0xFFFF);
		
		setup_read_icc_profile(&jpegDecompressor);

		fseek(jpegFile,0, SEEK_SET);

		jpeg_read_header(&jpegDecompressor, FALSE);

		LPBYTE Buffer;
		unsigned int Len;
		void* pHandler;

		bool HasEmbeddedICCProfile = read_icc_profile(&jpegDecompressor,&Buffer,&Len) != 0;
		

		if(HasEmbeddedICCProfile) 
		{
			pHandler = cmsOpenProfileFromMem(Buffer,Len);	  //TODO: Check if the handler that cmsOpenProfileFromMem returns is valid and then return nullptr
		}

		free(Buffer);		
		jpeg_destroy_decompress(&jpegDecompressor);
		fclose(jpegFile);

		return (HasEmbeddedICCProfile) ? gcnew lcmsProfile(pHandler) : nullptr;
	}
#pragma endregion


	void lcmsJPEGProfiling::_InitJPEGProfiling(lcmsJPEGProfilingArgs^ jpegArgs)
	{
		if(jpegArgs == nullptr) jpegArgs = gcnew lcmsJPEGProfilingArgs();


		_JPEGAdaptationState		= jpegArgs->ObserverAdaptationState;

		_JPEGBlackPointCompensation = jpegArgs->BlackPointCompensation;
		
		_JPEGBlackPreservationStrategy	= jpegArgs->BlackPreservationStrategy;
		
		_JPEGPrecalculationMode		= jpegArgs->PrecalculationMode;
		_JPEGCheckGamut				= jpegArgs->CheckGamut;
		_JPEGIsDeviceLink			= jpegArgs->IsDeviceLink;
		_JPEGIgnoreEmbedded			= jpegArgs->IgnoreEmbedded;
		_JPEGEmbedProfile			= jpegArgs->EmbedProfile;

		_JPEGSaveEmbedded			= jpegArgs->SaveEmbedded;

		_JPEGInputProfile			= jpegArgs->InputProfile;
		_JPEGOutputProfile			= jpegArgs->OutputProfile;
		_JPEGProofProfile			= jpegArgs->ProofProfile;

		_JPEGIntent					= jpegArgs->Intent;
		_JPEGProofingIntent			= jpegArgs->ProofingIntent;

		_JPEGQuality				= jpegArgs->JpegQuality;



		_JPEGIsITUFax = false;
		_JPEGIsPhotoshopApp13 = false;

		_JPEGInputFile = NULL;					
		_JPEGOutputFile = NULL;	

		_JPEGDecompressor = NULL;
		_JPEGCompressor = NULL;				    
		_JPEGErrorMgr = NULL;
	}

	void lcmsJPEGProfiling::_InitializeJPEG()	//Initialize compressor and decompressor
	{
		_JPEGErrorMgr = (struct jpeg_error_mgr*)malloc(sizeof(struct jpeg_error_mgr));
		memset((void*)_JPEGErrorMgr,0,sizeof(struct jpeg_error_mgr));

		_JPEGDecompressor = (struct jpeg_decompress_struct*)malloc(sizeof(struct jpeg_decompress_struct));
		memset((void*)_JPEGDecompressor,0,sizeof(struct jpeg_decompress_struct));

		_JPEGCompressor = (struct jpeg_compress_struct*)malloc(sizeof(struct jpeg_compress_struct));
		memset((void*)_JPEGCompressor,0,sizeof(struct jpeg_compress_struct));
	}

	void lcmsJPEGProfiling::_FinalizeJPEG()		//Finalize compressor and decompresor
	{
		if(_JPEGDecompressor != NULL) {
			if(_JPEGDecompressor->mem != NULL) jpeg_destroy_decompress(_JPEGDecompressor);
			free(_JPEGDecompressor);
		}

		if(_JPEGCompressor != NULL) {
			if(_JPEGCompressor->mem != NULL) jpeg_destroy_compress(_JPEGCompressor);
			free(_JPEGCompressor);
		}
		if(_JPEGErrorMgr != NULL){
			free(_JPEGErrorMgr);
		}
	}

	bool lcmsJPEGProfiling::_Done()
	{
		//_FinalizeJPEG();
		return (fclose(_JPEGInputFile) + fclose(_JPEGOutputFile) == 0);
	}

	UInt32 lcmsJPEGProfiling::_GetInputFormat()
	{
		lcmsPixelType pixelType;
		int bps;
		int extra;
		int colorChannels;
		int flavor;


		_JPEGIsITUFax			= _IsITUFax();
		_JPEGIsPhotoshopApp13	= _CanHandlePhotoshopApp13();

		colorChannels		= _JPEGDecompressor->num_components;
		extra				= 0;            // Alpha = None
		bps					= 1;            // 8 bits
		flavor				= 0;            // Vanilla

		if (_JPEGIsITUFax) 
		{
			pixelType = lcmsPixelType::Lab;
			_JPEGDecompressor->out_color_space = JCS_YCbCr;  // Fake to don't touch
		}
		else
		{
			switch (_JPEGDecompressor->jpeg_color_space) 
			{
			case JCS_GRAYSCALE:        // monochrome
				pixelType = lcmsPixelType::GRAY;
				_JPEGDecompressor->out_color_space = JCS_GRAYSCALE;
				break;

			case JCS_RGB:             // red/green/blue
				pixelType = lcmsPixelType::RGB;
				_JPEGDecompressor->out_color_space = JCS_RGB;
				break;

			case JCS_YCbCr:               // Y/Cb/Cr (also known as YUV)
				pixelType = lcmsPixelType::RGB;      // Let IJG code to do the conversion
				_JPEGDecompressor->out_color_space = JCS_RGB;   
				break;

			case JCS_CMYK:            // C/M/Y/K
				pixelType = lcmsPixelType::CMYK;
				_JPEGDecompressor->out_color_space = JCS_CMYK;
				if (_JPEGDecompressor->saw_Adobe_marker)            // Adobe keeps CMYK inverted, so change flavor
					flavor = 1;                 // from vanilla to chocolate
				break;

			case JCS_YCCK:            // Y/Cb/Cr/K              
				pixelType = lcmsPixelType::CMYK;
				_JPEGDecompressor->out_color_space = JCS_CMYK;
				if (_JPEGDecompressor->saw_Adobe_marker)            // ditto
					flavor = 1;                 
				break;

			default:
				//FatalError("Unsupported color space (0x%x)", _inputDecompressor->jpeg_color_space);
				ErrorManager->SignalError(String::Format("Unsupported color space (0x{0:X})", (Int32)_JPEGDecompressor->jpeg_color_space));
				return 0;
			}
		}  
		
		return (EXTRA_SH(extra)|
				CHANNELS_SH(colorChannels)|
				BYTES_SH(bps)|
				COLORSPACE_SH(((Int32)pixelType))|
				FLAVOR_SH(flavor));
	}

	bool lcmsJPEGProfiling::_IsITUFax()
	{
		jpeg_saved_marker_ptr ptr = _JPEGDecompressor->marker_list;

		while (ptr) 
		{
			if (ptr->marker == (JPEG_APP0 + 1) && ptr->data_length > 5)
			{
				JOCTET FAR* data = ptr -> data;

				if (GETJOCTET(data[0]) == 0x47 &&
					GETJOCTET(data[1]) == 0x33 &&
					GETJOCTET(data[2]) == 0x46 &&
					GETJOCTET(data[3]) == 0x41 &&
					GETJOCTET(data[4]) == 0x58)
					return true;
			}
			ptr = ptr->next;
		}
		return false;
	}


	bool lcmsJPEGProfiling::_CanHandlePhotoshopApp13()
	{
		jpeg_saved_marker_ptr ptr = _JPEGDecompressor->marker_list;

		while (ptr) 
		{
			if (ptr->marker == (JPEG_APP0 + 13) && ptr->data_length > 9)
			{    
				JOCTET FAR* data = ptr -> data;    

				if(GETJOCTET(data[0]) == 0x50 &&
					GETJOCTET(data[1]) == 0x68 &&
					GETJOCTET(data[2]) == 0x6F &&
					GETJOCTET(data[3]) == 0x74 &&
					GETJOCTET(data[4]) == 0x6F &&
					GETJOCTET(data[5]) == 0x73 &&
					GETJOCTET(data[6]) == 0x68 &&
					GETJOCTET(data[7]) == 0x6F &&
					GETJOCTET(data[8]) == 0x70) 
				{
					_ProcessPhotoshopApp13(data, ptr -> data_length);
					return true;
				}
			}
			ptr = ptr->next;
		}
		return false;  
	}

	//#define PS_FIXED_TO_FLOAT(h, l) ((float) (h) + ((float) (l)/(1<<16)))

	bool lcmsJPEGProfiling::_ProcessPhotoshopApp13(JOCTET FAR *data, Int32 dataLength)
	{
		int i;
		for (i = 14; i < dataLength;)
		{
			long len;
			unsigned int type;

			if (!(GETJOCTET(data[i]  ) == 0x38 &&
				GETJOCTET(data[i+1]) == 0x42 &&
				GETJOCTET(data[i+2]) == 0x49 &&
				GETJOCTET(data[i+3]) == 0x4D)) break; // Not recognized

			i += 4; // identifying string 

			type = (unsigned int) (GETJOCTET(data[i]<<8) + GETJOCTET(data[i+1]));

			i += 2; // resource type 

			i += GETJOCTET(data[i]) + ((GETJOCTET(data[i]) & 1) ? 1 : 2);   // resource name 

			len = ((((GETJOCTET(data[i]<<8) + GETJOCTET(data[i+1]))<<8) + GETJOCTET(data[i+2]))<<8) + GETJOCTET(data[i+3]);

			i += 4; // Size 

			if (type == 0x03ED && len >= 16) {
				_JPEGDecompressor->X_density = (int) _PS_FIXED_TO_FLOAT(GETJOCTET(data[i]<<8) + GETJOCTET(data[i+1]),
					GETJOCTET(data[i+2]<<8) + GETJOCTET(data[i+3]));
				_JPEGDecompressor->Y_density = (int) _PS_FIXED_TO_FLOAT(GETJOCTET(data[i+8]<<8) + GETJOCTET(data[i+9]),
					GETJOCTET(data[i+10]<<8) + GETJOCTET(data[i+11]));

				// Set the density unit to 1 since the 
				// Vertical and Horizontal resolutions 
				// are specified in Pixels per inch 

				_JPEGDecompressor->density_unit = 0x01;
				return true;

			}

			i += len + ((len & 1) ? 1 : 0);   // Alignment             
		}
		return false;
	}

	void lcmsJPEGProfiling::_WriteOutputFields(lcmsPixelType outputPixelType)
	{
		J_COLOR_SPACE in_space, jpeg_space;
		int components;

		switch (outputPixelType) 
		{
		case lcmsPixelType::GRAY: 
			in_space = jpeg_space = JCS_GRAYSCALE; 
			components = 1; 
			break;

		case lcmsPixelType::RGB:  
			in_space = JCS_RGB; 
			jpeg_space = JCS_YCbCr; 
			components = 3; 
			break;       // red/green/blue

		case lcmsPixelType::YCbCr: 
			in_space = jpeg_space = JCS_YCbCr; 
			components = 3; 
			break;               // Y/Cb/Cr (also known as YUV)

		case lcmsPixelType::CMYK: 
			in_space = JCS_CMYK; 
			jpeg_space = JCS_YCCK;  
			components = 4; 
			break;      // C/M/Y/components              

		case lcmsPixelType::Lab:  
			in_space = jpeg_space = JCS_YCbCr; 
			components = 3; 
			break;                // Fake to don't touch
		default:
			//FatalError("Unsupported output color space");
			ErrorManager->SignalError("Unsupported output color space");
			return;
		}


		if (_JPEGQuality >= 100) {
			// avoid destructive conversion when asking for lossless compression 
			jpeg_space = in_space;
		}

		_JPEGCompressor->in_color_space =  in_space;
		_JPEGCompressor->jpeg_color_space = jpeg_space;
		_JPEGCompressor->input_components = _JPEGCompressor->num_components = components;
		jpeg_set_defaults(_JPEGCompressor);
		jpeg_set_colorspace(_JPEGCompressor, jpeg_space);

		// Make sure to pass resolution through
		if (outputPixelType == lcmsPixelType::CMYK)
			_JPEGCompressor->write_JFIF_header = 1;

		//avoid sub sampling on high quality factor
		jpeg_set_quality(_JPEGCompressor, _JPEGQuality, 1);    

		if (_JPEGQuality >= 70) {
			for(int i=0; i < _JPEGCompressor->num_components; i++) 
			{
				_JPEGCompressor->comp_info[i].h_samp_factor = 1;
				_JPEGCompressor->comp_info[i].v_samp_factor = 1;
			}
		}
	}

	UInt32 lcmsJPEGProfiling::_ComputeOutputFormatDescriptor(UInt32 inputFormat, lcmsPixelType outputPixelType)
	{
		int IsPlanar  = T_PLANAR(inputFormat);
		int Channels  = 0;
		int Flavor    = 0;

		switch (outputPixelType) 
		{

		case lcmsPixelType::GRAY:
			Channels = 1;
			break;
		case lcmsPixelType::RGB:
		case lcmsPixelType::CMY:
		case lcmsPixelType::Lab:
		case lcmsPixelType::YUV:
		case lcmsPixelType::YCbCr:
			Channels = 3;
			break;

		case lcmsPixelType::CMYK:
			if (_JPEGCompressor->write_Adobe_marker)   // Adobe keeps CMYK inverted, so change flavor to chocolate
				Flavor = 1;

			Channels = 4;
			break;
		default:
			//FatalError("Unsupported output color space");
			ErrorManager->SignalError("Unsupported output color space");
			return UInt32::MaxValue;
		}

		return (COLORSPACE_SH((Int32)outputPixelType)|
				PLANAR_SH(IsPlanar)|
				CHANNELS_SH(Channels)|
				BYTES_SH(1)|
				FLAVOR_SH(Flavor));		
	}

	void lcmsJPEGProfiling::_DoTransform(lcmsTransform^ hTransform)
	{
		if(!hTransform->HasValue) return;

		JSAMPROW ScanLineIn;
		JSAMPROW ScanLineOut;


		//Preserve resolution values from the original
		// (Thanks to robert bergs for finding out this bug)

		_JPEGCompressor->density_unit = _JPEGDecompressor->density_unit;
		_JPEGCompressor->X_density    = _JPEGDecompressor->X_density;
		_JPEGCompressor->Y_density    = _JPEGDecompressor->Y_density;

		//  Compressor.write_JFIF_header = 1;

		jpeg_start_decompress(_JPEGDecompressor);
		jpeg_start_compress(_JPEGCompressor, TRUE);

		// Embed the profile if needed
		if(_JPEGEmbedProfile) {
			_DoEmbedProfile(hTransform->OutputProfile);
		}

		ScanLineIn  = (JSAMPROW) _cmsMalloc(_JPEGDecompressor->output_width * _JPEGDecompressor->num_components);
		ScanLineOut = (JSAMPROW) _cmsMalloc(_JPEGCompressor->image_width * _JPEGCompressor->num_components);

		while (_JPEGDecompressor->output_scanline < _JPEGDecompressor->output_height) 
		{
				jpeg_read_scanlines(_JPEGDecompressor, &ScanLineIn, 1);

				cmsDoTransform(hTransform->Handler, ScanLineIn, ScanLineOut, _JPEGDecompressor->output_width);

				jpeg_write_scanlines(_JPEGCompressor, &ScanLineOut, 1);
		}

		_cmsFree(ScanLineIn); 
		_cmsFree(ScanLineOut);

		jpeg_finish_decompress(_JPEGDecompressor);
		jpeg_finish_compress(_JPEGCompressor);
	}


	void lcmsJPEGProfiling::_DoEmbedProfile(lcmsProfile^ hProfile)
	{
		if(hProfile == nullptr || !hProfile->HasValue) return;

		LPBYTE embedBuffer;
		size_t bufferSize;

		if(_cmsSaveProfileToMem(hProfile->Handler,NULL,&bufferSize))
		{
			embedBuffer = (LPBYTE)_cmsMalloc(bufferSize);
			_cmsSaveProfileToMem(hProfile->Handler,embedBuffer,&bufferSize);
			//embedBuffer[bufferSize] = 0;
			write_icc_profile (_JPEGCompressor, embedBuffer, bufferSize);		   
			_cmsFree(embedBuffer);
		}
	}


	void lcmsJPEGProfiling::_Jcopy_markers_execute()
	{
		j_decompress_ptr srcinfo	= _JPEGDecompressor;
		j_compress_ptr dstinfo		= _JPEGCompressor;


		jpeg_saved_marker_ptr marker;

		/* In the current implementation, we don't actually need to examine the
		* option flag here; we just copy everything that got saved.
		* But to avoid confusion, we do not output JFIF and Adobe APP14 markers
		* if the encoder library already wrote one.
		*/
		for (marker = srcinfo->marker_list; marker != NULL; marker = marker->next) {
			if (dstinfo->write_JFIF_header &&
				marker->marker == JPEG_APP0 &&
				marker->data_length >= 5 &&
				GETJOCTET(marker->data[0]) == 0x4A &&
				GETJOCTET(marker->data[1]) == 0x46 &&
				GETJOCTET(marker->data[2]) == 0x49 &&
				GETJOCTET(marker->data[3]) == 0x46 &&
				GETJOCTET(marker->data[4]) == 0)
				continue;         /* reject duplicate JFIF */

			if (dstinfo->write_Adobe_marker &&
				marker->marker == JPEG_APP0+14 &&
				marker->data_length >= 5 &&
				GETJOCTET(marker->data[0]) == 0x41 &&
				GETJOCTET(marker->data[1]) == 0x64 &&
				GETJOCTET(marker->data[2]) == 0x6F &&
				GETJOCTET(marker->data[3]) == 0x62 &&
				GETJOCTET(marker->data[4]) == 0x65)
				continue;         /* reject duplicate Adobe */

#ifdef NEED_FAR_POINTERS
			/* We could use jpeg_write_marker if the data weren't FAR... */
			{
				unsigned int i;

				jpeg_write_m_header(dstinfo, marker->marker, marker->data_length);
				for (i = 0; i < marker->data_length; i++)
					jpeg_write_m_byte(dstinfo, marker->data[i]);
			}
#else
			jpeg_write_marker(dstinfo, marker->marker, marker->data, marker->data_length);
#endif
		}
	}

	bool lcmsJPEGProfiling::_SaveEmbeddedProfile(const BYTE* buffer, UInt32 bufferLength)
	{
		IntPtr ptrFileName	 = Marshal::StringToCoTaskMemAnsi(_JPEGSaveEmbedded);
		const char *ccFileName = (const char*)ptrFileName.ToPointer();

		FILE* out = fopen(ccFileName, "wb");
		if (out == NULL) 
		{
			ErrorManager->SignalError(String::Format("Cannot create {0}.", gcnew String(ccFileName)));
			return false;//FatalError("Cannot create '%s'", Filename);
		}

		if (fwrite(buffer, 1, bufferLength, out) != bufferLength)
		{
			ErrorManager->SignalError(String::Format("Cannot write {0:D} bytes to {1}.", gcnew String(ccFileName)));
			return false; //FatalError("Cannot write %ld bytes to %s", dwLen, Filename);
		}

		if (fclose(out) != 0) 
		{
			ErrorManager->SignalError(String::Format("Error flushing file {0}.", gcnew String(ccFileName)));
			return false; //FatalError("Error flushing file '%s'", Filename);
		}

		return true;  //Success
	}

	lcmsProfile^ lcmsJPEGProfiling::_OpenStockProfile(String^ profile)
	{
		if(String::IsNullOrEmpty(profile)) 
			return lcmsProfile::Create_sRGBProfile();

		if(profile->Equals("*Lab",StringComparison::OrdinalIgnoreCase))
			return lcmsProfile::CreateLabProfile(nullptr);

		if(profile->Equals("*Lab4",StringComparison::OrdinalIgnoreCase))
			return lcmsProfile::CreateLab4Profile(nullptr);

		if(profile->Equals("*LabD65",StringComparison::OrdinalIgnoreCase))
		{
			lcmsWhitePoint^ whitePoint = lcmsWhitePoint::FromTemp(6504);
			return lcmsProfile::CreateLabProfile(whitePoint);
		}

		if(profile->Equals("*XYZ",StringComparison::OrdinalIgnoreCase))
			return lcmsProfile::CreateXYZProfile();

		if(profile->Equals("*sRGB",StringComparison::OrdinalIgnoreCase))
			return lcmsProfile::Create_sRGBProfile();

		if(profile->Equals("*NULL",StringComparison::OrdinalIgnoreCase))
			return lcmsProfile::CreateNULLProfile();

		if(profile->Equals("*Gray22",StringComparison::OrdinalIgnoreCase))
		{
			//TODO: Change this later to use lcmsProfile::functions
           LPGAMMATABLE Gamma = cmsBuildGamma(256, 2.2);
           void*  pHandler = cmsCreateGrayProfile(cmsD50_xyY(), Gamma);
           cmsFreeGamma(Gamma);
			
		   //TODO: Check if the handler that cmsOpenProfileFromFile returns is valid and then return nullptr

		   return gcnew lcmsProfile(pHandler);
		}

		return lcmsProfile::OpenProfileFromFile(profile);
	}


	bool lcmsJPEGProfiling::_OpenInput()
	{
		IntPtr ptrFileName	   = Marshal::StringToCoTaskMemAnsi(_JPEGInputFileName);
		const char *ccFileName = (const char*)ptrFileName.ToPointer();

		_JPEGIsITUFax = false;   
		_JPEGInputFile  = fopen(ccFileName, "rb");
		if (_JPEGInputFile == NULL) {
			ErrorManager->SignalError(String::Format("Cannot open {0}.", gcnew String(ccFileName)));
			//FatalError("Cannot open '%s'", FileName);
			return false;
		}

		// Now we can initialize the JPEG decompression object.

		_JPEGDecompressor->err	   = jpeg_std_error(_JPEGErrorMgr);
		_JPEGErrorMgr->error_exit      = _JPEGErrorMgr_exit;
		_JPEGErrorMgr->output_message  = _JPEGErrorMgr_output_message;

		jpeg_create_decompress(_JPEGDecompressor);
		jpeg_stdio_src(_JPEGDecompressor, _JPEGInputFile);

		for (int m = 0; m < 16; m++)
			jpeg_save_markers(_JPEGDecompressor, JPEG_APP0 + m, 0xFFFF);

		setup_read_icc_profile(_JPEGDecompressor);  

		fseek(_JPEGInputFile, 0, SEEK_SET);
		jpeg_read_header(_JPEGDecompressor, TRUE);

		return true;		
	}

	bool lcmsJPEGProfiling::_OpenOutput()
	{
		IntPtr ptrFileName	   = Marshal::StringToCoTaskMemAnsi(_JPEGOutputFileName);
		const char *ccFileName = (const char*)ptrFileName.ToPointer();

        _JPEGOutputFile = fopen(ccFileName, "wb");
        if (_JPEGOutputFile == NULL) {
			ErrorManager->SignalError(String::Format("Cannot create {0}.", gcnew String(ccFileName)));
			//FatalError("Cannot create '%s'", FileName);
            return false;
        }

        _JPEGCompressor->err          = jpeg_std_error(_JPEGErrorMgr);
		_JPEGErrorMgr->error_exit      = _JPEGErrorMgr_exit;
		_JPEGErrorMgr->output_message  = _JPEGErrorMgr_output_message;

        _JPEGCompressor->input_components = _JPEGCompressor->num_components = 4;
        
        jpeg_create_compress(_JPEGCompressor);
        jpeg_stdio_dest(_JPEGCompressor, _JPEGOutputFile);  
        
		return true;
	}

	bool lcmsJPEGProfiling::TransformImage()
	{
		if(!CheckValues()) return false;

		_InitializeJPEG();


		if(!(_OpenInput() && _OpenOutput())) return false;


		//Internal vars
		lcmsProfile^ 	hInput;
		lcmsProfile^ 	hOutput;
		lcmsProfile^ 	hProof;
		
		lcmsTransform^  hTransform;

		UInt32		 	inputFormat;
		UInt32			outputFormat;
		lcmsFlags		flags = lcmsFlags::EMPTY;
		lcmsPixelType	outputPixelType;
		unsigned int	embedLength;
		LPBYTE			embedBuffer;

		//Code
		//SetAdaptationState(_observerAdaptationState);
		lcmsTransformExtraArgs^ extraArgs = gcnew lcmsTransformExtraArgs(_JPEGAdaptationState,_JPEGBlackPreservationStrategy);
			

		if (_JPEGBlackPointCompensation) 
			flags = flags | lcmsFlags::BLACKPOINTCOMPENSATION; //cmsFLAGS_BLACKPOINTCOMPENSATION;            

		if (_JPEGBlackPreservationStrategy != lcmsBlackPreservation::Off) {
		   flags = flags | lcmsFlags::PRESERVEBLACK;
		   if (_JPEGPrecalculationMode == lcmsPrecalculationMode::Off) _JPEGPrecalculationMode = lcmsPrecalculationMode::Normal;
		   //SetCMYKPreservationStrategy(_preserveBlack);	 //Originalmente -1 check this later
		}

		
		switch (_JPEGPrecalculationMode) 
		{
			case lcmsPrecalculationMode::Off: 
				flags = flags | lcmsFlags::NOTPRECALC; 
				break;
			case lcmsPrecalculationMode::Hi_Res: 
				flags = flags | lcmsFlags::HIGHRESPRECALC; 
				break;
			case lcmsPrecalculationMode::Low_Res: 
				flags = flags | lcmsFlags::LOWRESPRECALC; 
				break;
			default:;
		}
		      

		if (_JPEGCheckGamut)
			flags = flags | lcmsFlags::GAMUTCHECK;
		      

		if (_JPEGIsDeviceLink) 
		{
			hInput	= lcmsProfile::OpenProfileFromFile(_JPEGInputProfile);
			hOutput = gcnew lcmsProfile(NULL);
			hProof	= gcnew lcmsProfile(NULL);
		}
		else {
			if (!_JPEGIgnoreEmbedded && read_icc_profile(_JPEGDecompressor, &embedBuffer, &embedLength))
			{
				//hInput = OpenEmbeddedProfileFromJpeg(_inputJpgFileName);  //To be changed in the future
				//hIn = cmsOpenProfileFromMem(EmbedBuffer, EmbedLen);
				hInput = gcnew lcmsProfile(cmsOpenProfileFromMem(embedBuffer, embedLength));
				if (hInput != nullptr && !String::IsNullOrEmpty(_JPEGSaveEmbedded))
					_SaveEmbeddedProfile(embedBuffer, embedLength); //Save the embedded profile 
					//It could be also hInput->SaveProfile(_JPEGSaveEmbedded)

				_cmsFree(embedBuffer);
			}
			else
			{
				hInput = _OpenStockProfile(_JPEGInputProfile);
			}

			hOutput = _OpenStockProfile(_JPEGOutputProfile);
			
			if (!String::IsNullOrEmpty(_JPEGProofProfile)) 
			{
				hProof = _OpenStockProfile(_JPEGProofProfile);
				flags = flags | lcmsFlags::SOFTPROOFING;
			}
			else
			{
				hProof = gcnew lcmsProfile(NULL);
			}

		}

		// Take input color space
		inputFormat = _GetInputFormat();

		// Assure both, input profile and input JPEG are on same colorspace

		     
		if (hInput->ColorSpace != lcmsWrapper::ICCcolorSpace((lcmsPixelType)(T_COLORSPACE(inputFormat))))
		{
			ErrorManager->SignalError("Input profile is not operating in proper color space.");
		    return false;//FatalError("Input profile is not operating in proper color space");
		}
		     

		// Output colorspace is given by output profile

		if (_JPEGIsDeviceLink) 
		{
			outputPixelType = (lcmsPixelType)(T_COLORSPACE(inputFormat));
		}
		else 
		{
			outputPixelType = hOutput->PixelType;
		}

		jpeg_copy_critical_parameters(_JPEGDecompressor, _JPEGCompressor);
		 
		_WriteOutputFields(outputPixelType);               
		     
		outputFormat = _ComputeOutputFormatDescriptor(inputFormat, outputPixelType);
		     
		hTransform = lcmsTransform::CreateProofingTransform(hInput, inputFormat, 
															hOutput, outputFormat, 
															hProof, _JPEGIntent, 
															_JPEGProofingIntent, flags, extraArgs);

		// Handle tile by tile or strip by strip strtok

		_DoTransform(hTransform);

		     
		_Jcopy_markers_execute();
		     
		hTransform->Close();  //This Closes the transform and its Profiles
		     
		_FinalizeJPEG();

		bool result = _Done();

		_InitJPEGProfiling(nullptr);

		return result;
	}

	bool lcmsJPEGProfiling::CheckValues()
	{
		return !(String::IsNullOrEmpty(_JPEGInputFileName) || String::IsNullOrEmpty(_JPEGOutputFileName));
	}
	
}