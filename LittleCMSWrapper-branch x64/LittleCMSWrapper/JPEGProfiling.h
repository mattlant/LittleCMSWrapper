#pragma once  
#pragma managed
#include <vcclr.h>

using namespace System::Collections::Generic;
using namespace System;

namespace LittleCMSWrapper 
{
	public ref class lcmsJPEGProfilingArgs
	{
	public:
		double						ObserverAdaptationState;	
		bool						BlackPointCompensation;	
		lcmsBlackPreservation		BlackPreservationStrategy;			
		lcmsPrecalculationMode		PrecalculationMode;		
		bool						CheckGamut;				
		bool 						IsDeviceLink;			
		bool 						IgnoreEmbedded;			
		bool						EmbedProfile;			

		String^ 					SaveEmbedded;				//Profile Name for saving the embedded profile

		String^ 					InputProfile;				//Profiles File Names or Profiles Descriptions used in OpenStockProfile
		String^ 					OutputProfile;			
		String^ 					ProofProfile;			

		lcmsIntents					Intent;
		lcmsIntents					ProofingIntent;
		UInt32						JpegQuality;				//We can put later an enum on this

		lcmsJPEGProfilingArgs() 
		{
			ObserverAdaptationState = 0;
			BlackPointCompensation = false;
			BlackPreservationStrategy = lcmsBlackPreservation::Off;
			PrecalculationMode = lcmsPrecalculationMode::Normal;
			CheckGamut = false;
			IsDeviceLink = false;
			IgnoreEmbedded = false;
			EmbedProfile = false;

			SaveEmbedded = nullptr;
			InputProfile = nullptr;
			OutputProfile = nullptr;

			Intent = lcmsIntents::PERCEPTUAL;
			ProofingIntent = lcmsIntents::PERCEPTUAL;

			JpegQuality = 75;
		}
	};

	
	public ref class lcmsJPEGProfiling	  : LittleCMSWrapperBase
	{
	private:
#pragma region Private Fields
		
		double						_JPEGAdaptationState;
		bool						_JPEGBlackPointCompensation;	
		lcmsBlackPreservation		_JPEGBlackPreservationStrategy;		
		lcmsPrecalculationMode		_JPEGPrecalculationMode;		
		bool						_JPEGCheckGamut;				
		bool 						_JPEGIsDeviceLink;			
		bool 						_JPEGIgnoreEmbedded;			
		bool						_JPEGEmbedProfile;			

		String^ 					_JPEGSaveEmbedded;					//Profile Name for saving the embedded profile

		String^ 					_JPEGInputFileName;				
		String^ 					_JPEGOutputFileName;			

		String^ 					_JPEGInputProfile;				//Profiles File Names or Profiles Descriptions used in OpenStockProfile
		String^ 					_JPEGOutputProfile;			
		String^ 					_JPEGProofProfile;			

		lcmsIntents					_JPEGIntent;
		lcmsIntents					_JPEGProofingIntent;
		UInt32						_JPEGQuality;									//We can put later an enum on this
		
		//-------------------------------------------------------------------------------------

		bool						_JPEGIsITUFax;
		bool						_JPEGIsPhotoshopApp13;

		FILE*						_JPEGInputFile;					
		FILE*						_JPEGOutputFile;							

		struct jpeg_decompress_struct*	_JPEGDecompressor;
		struct jpeg_compress_struct*	_JPEGCompressor;				    
		struct jpeg_error_mgr*			_JPEGErrorMgr;
#pragma endregion

#pragma region Private Funtions

	    void                        _InitJPEGProfiling(lcmsJPEGProfilingArgs^ jpegArgs);

		void						_InitializeJPEG();	//Initialize compressor and decompressor
		void						_FinalizeJPEG();		//Finalize compressor and decompresor
		
		UInt32						_GetInputFormat();	//Get the Input Pixel Type Format for the Transform
		bool						_IsITUFax();
		bool						_CanHandlePhotoshopApp13();
		bool						_ProcessPhotoshopApp13(JOCTET FAR *data, Int32 dataLength);

		float						_PS_FIXED_TO_FLOAT(Int32 h,Int32 l)		{return ((float) (h) + ((float) (l)/(1<<16)));}

		

		void						_WriteOutputFields(lcmsPixelType outputPixelType);
		UInt32						_ComputeOutputFormatDescriptor(UInt32 inputFormat, lcmsPixelType outputPixelType);
		void						_DoTransform(lcmsTransform^ hTransform);
		void						_DoEmbedProfile(lcmsProfile^ hProfile);
		void						_Jcopy_markers_execute();
		bool						_SaveEmbeddedProfile(const BYTE* buffer, UInt32 bufferLength);


		lcmsProfile^				_OpenStockProfile(String^ profile);
		bool						_OpenInput();  //Open the input jpeg
		bool						_OpenOutput(); //Creates the output jpeg
		bool						_Done();		//Closes everything after the Transformation ends.

#pragma endregion

	public:
		lcmsJPEGProfiling() : _JPEGInputFileName(""),_JPEGOutputFileName("") {_InitJPEGProfiling(nullptr);}

		lcmsJPEGProfiling(String^ inputJPEGFilename, String^ outputJPEGFileName) : _JPEGInputFileName(inputJPEGFilename),_JPEGOutputFileName(outputJPEGFileName) 
			{_InitJPEGProfiling(nullptr);}

		lcmsJPEGProfiling(String^ inputJPEGFilename, String^ outputJPEGFileName, lcmsJPEGProfilingArgs^ jpegArgs) : _JPEGInputFileName(inputJPEGFilename),_JPEGOutputFileName(outputJPEGFileName) 
			{_InitJPEGProfiling(jpegArgs);}

#pragma region Properties

		property double ObserverAdaptationState
		{
			double get() { return _JPEGAdaptationState; }
			void set(double value) { _JPEGAdaptationState = value; }
		}
		

		property bool BlackPointCompensation
		{
			bool get() { return _JPEGBlackPointCompensation; }
			void set(bool value) { _JPEGBlackPointCompensation = value; }
		}

		property lcmsBlackPreservation BlackPreservationStrategy
		{
			lcmsBlackPreservation get() { return _JPEGBlackPreservationStrategy; }
			void set(lcmsBlackPreservation value) { _JPEGBlackPreservationStrategy = value; }
		}
		

		property lcmsPrecalculationMode PrecalculationMode
		{
			lcmsPrecalculationMode get() { return _JPEGPrecalculationMode; }
			void set(lcmsPrecalculationMode value) { _JPEGPrecalculationMode = value; }
		}

		property bool CheckGamut
		{
			bool get() { return _JPEGCheckGamut; }
			void set(bool value) { _JPEGCheckGamut = value; }
		}

		property bool IsDeviceLink
		{
			bool get() { return _JPEGIsDeviceLink; }
			void set(bool value) { _JPEGIsDeviceLink = value; }
		}

		property bool IgnoreEmbedded
		{
			bool get() { return _JPEGIgnoreEmbedded; }
			void set(bool value) { _JPEGIgnoreEmbedded = value; }
		}
		
		property bool EmbedProfile
		{
			bool get() { return _JPEGEmbedProfile; }
			void set(bool value) { _JPEGEmbedProfile = value; }
		}

		property String^ SaveEmbedded
		{
			String^ get() { return _JPEGSaveEmbedded; }
			void set(String ^value) { _JPEGSaveEmbedded = value; }
		}
		
		property String^ InputFileName
		{
			String^ get() { return _JPEGInputFileName; }
			void set(String ^value) { _JPEGInputFileName = value; }
		}

		property String^ OutputFileName
		{
			String^ get() { return _JPEGOutputFileName; }
			void set(String ^value) { _JPEGOutputFileName = value; }
		}

		property String^ InputProfileS
		{
			String^ get() { return _JPEGInputProfile; }
			void set(String ^value) { _JPEGInputProfile = value; }
		}

		property String^ OutputProfileS
		{
			String^ get() { return _JPEGOutputProfile; }
			void set(String ^value) { _JPEGOutputProfile = value; }
		}

		property String^ ProofProfileS
		{
			String^ get() { return _JPEGProofProfile; }
			void set(String ^value) { _JPEGProofProfile = value; }
		}
		
		property lcmsIntents Intent
		{
			lcmsIntents get() { return _JPEGIntent; }               
			void set(lcmsIntents value) { _JPEGIntent = value; }
		}

		property lcmsIntents ProofingIntent
		{
			lcmsIntents get() { return _JPEGProofingIntent; }               
			void set(lcmsIntents value) { _JPEGProofingIntent = value; }
		}		

		property UInt32 JpegQuality
		{
			UInt32 get() { return _JPEGQuality; }
			void set(UInt32 value) { _JPEGQuality = value; }
		}
		
		
#pragma endregion
		bool CheckValues();

		bool TransformImage();
	};
}