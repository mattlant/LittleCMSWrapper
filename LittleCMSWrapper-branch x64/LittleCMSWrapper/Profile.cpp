#pragma managed
#include "Stdafx.h"



using namespace System::Runtime::InteropServices;

namespace LittleCMSWrapper
{
	bool lcmsProfile::Close()
	{
		bool result = HasValue ? (cmsCloseProfile(Handler) != 0) : true;
		Handler = nullptr;
		return result;
	};

	lcmsProfile^ lcmsProfile::CreateLabProfile(lcmsWhitePoint ^whitePoint) 
	{
		lcmsProfile^ temp = gcnew lcmsProfile((whitePoint != nullptr ) ? cmsCreateLabProfile(&whitePoint->WhitePoint->ToCIExyY()) : cmsCreateLabProfile(NULL));
		temp->_WhitePoint = whitePoint;
		return temp;
	}     
		
	lcmsProfile^ lcmsProfile::CreateLab4Profile(lcmsWhitePoint^ whitePoint) 
	{
		lcmsProfile^ temp = gcnew lcmsProfile((whitePoint != nullptr ) ? cmsCreateLab4Profile(&whitePoint->WhitePoint->ToCIExyY()) : cmsCreateLab4Profile(NULL));
		temp->_WhitePoint = whitePoint;
		return temp;
	}     


	lcmsProfile^ lcmsProfile::OpenProfileFromFile(String ^sIccProfileFileName, String^ sAccess)
	{
		IntPtr ptrICCProfile = Marshal::StringToCoTaskMemAnsi(sIccProfileFileName);
		IntPtr ptrAccess = Marshal::StringToCoTaskMemAnsi(sAccess);

		const char *fileName = (const char*)ptrICCProfile.ToPointer();
		const char *access = (const char*)ptrAccess.ToPointer();

		return gcnew lcmsProfile(cmsOpenProfileFromFile(fileName,access));
	}


	bool lcmsProfile::SaveProfile(String^ fileName)	  //Note Close the Profile on exit
	{
		if(!HasValue) return false;

		IntPtr ptrFileName	 = Marshal::StringToCoTaskMemAnsi(fileName);
		const char *ccFileName = (const char*)ptrFileName.ToPointer();

		return _cmsSaveProfile(Handler,ccFileName) != 0;
	}


	Int32 lcmsProfile::SaveProfileToMem(IntPtr^ memPtr)
	{
		if(!HasValue) return -1;

		size_t bytesNeeded; 
		void* buffer = memPtr->ToPointer();
		if(_cmsSaveProfileToMem(Handler,NULL,&bytesNeeded)){
			buffer = _cmsMalloc(bytesNeeded);
			return _cmsSaveProfileToMem(Handler,buffer,&bytesNeeded)!=0 ? bytesNeeded : -1;
		}
		return -1;
	}

	void lcmsProfile::_InitValues()
	{
		_WhitePoint = nullptr; 
		_BlackPoint = nullptr;
		_Iluminant = nullptr;

		_HeaderFlags = UInt32::MaxValue;
		_HeaderAttributes = UInt32::MaxValue;

		_ProductName = nullptr;
		_ProductDescription = nullptr;
		_ProductInfo = nullptr;
		_Manufacturer = nullptr;
		_Model = nullptr;
		_Copyright = nullptr;
		
		_ProfileID = nullptr;

		_CreationDateTime = nullptr;
		_CalibrationDateTime = nullptr;

		_RenderingIntent = (lcmsIntents)(-1);

		_PixelType = (lcmsPixelType)icMaxEnumData;

		_ColorSpace = lcmsICColorSpaceSignature::MaxEnumData;
		_DeviceClass = lcmsICProfileClassSignature::MaxEnumClass;
	}

	lcmsWhitePoint^ lcmsProfile::_TakeMediaWhitePoint()
	{
		if(!HasValue) return nullptr;
		cmsCIEXYZ tXYZ;
		return (cmsTakeMediaWhitePoint(&tXYZ,Handler) != 0) ? gcnew lcmsWhitePoint(&tXYZ) : nullptr;
	}

	lcmsCIEXYZ^	lcmsProfile::_TakeMediaBlackPoint()
	{
		if(!HasValue) return nullptr;
		cmsCIEXYZ tXYZ;
		return (cmsTakeMediaBlackPoint(&tXYZ,Handler) != 0) ? gcnew lcmsCIEXYZ(&tXYZ) : nullptr;
	}

	lcmsCIEXYZ^ lcmsProfile::_TakeIluminant()
	{
		if(!HasValue) return nullptr;
		cmsCIEXYZ tXYZ;
		return (cmsTakeIluminant(&tXYZ,Handler) != 0) ? gcnew lcmsCIEXYZ(&tXYZ) : nullptr;
	}

	UInt32 lcmsProfile::_TakeHeaderFlags()
	{
		return HasValue ? cmsTakeHeaderFlags(Handler) : UInt32::MaxValue;
	}

	UInt32	lcmsProfile::_TakeHeaderAttributes()
	{
		return HasValue ? cmsTakeHeaderAttributes(Handler) : UInt32::MaxValue;
	}


	String^	lcmsProfile::_TakeProductName()
	{
		return HasValue ? gcnew String(cmsTakeProductName(Handler)) : nullptr;
	}

	String^	lcmsProfile::_TakeProductDesc()
	{
		return HasValue ? gcnew String(cmsTakeProductDesc(Handler)) : nullptr;
	}
	
	String^	lcmsProfile::_TakeProductInfo()
	{
		return HasValue ? gcnew String(cmsTakeProductInfo(Handler)) : nullptr;
	}

	String^	lcmsProfile::_TakeManufacturer()
	{
		return HasValue ? gcnew String(cmsTakeManufacturer(Handler)) : nullptr;
	}

	String^	lcmsProfile::_TakeModel()
	{
		return HasValue ? gcnew String(cmsTakeModel(Handler)) : nullptr;
	}

	String^	lcmsProfile::_TakeCopyright()
	{
		return HasValue ? gcnew String(cmsTakeCopyright(Handler)) : nullptr;
	}

	array<Byte>^ lcmsProfile::_TakeProfileID()
	{
		if(!HasValue) return nullptr;

		const BYTE* result = cmsTakeProfileID(Handler);

		array<Byte>^ lResult = gcnew array<Byte>(16);

		for(int i=0;i<16;i++) lResult[i] = result[0];

		return lResult;
	}

	DateTime^ lcmsProfile::_TakeCreationDateTime()
	{
		if(!HasValue) return nullptr;
		struct tm dateTime;
		return (cmsTakeCreationDateTime(&dateTime,Handler) !=0) ? gcnew DateTime(dateTime.tm_year+1900,dateTime.tm_mon+1,dateTime.tm_mday,dateTime.tm_hour,dateTime.tm_min,dateTime.tm_sec) : nullptr;
	}

	DateTime^ lcmsProfile::_TakeCalibrationDateTime()
	{
		if(!HasValue) return nullptr;
		struct tm dateTime;
		return (cmsTakeCalibrationDateTime(&dateTime,Handler) !=0) ? gcnew DateTime(dateTime.tm_year+1900,dateTime.tm_mon+1,dateTime.tm_mday,dateTime.tm_hour,dateTime.tm_min,dateTime.tm_sec) : nullptr;
	}

		
	lcmsIntents lcmsProfile::_TakeRenderingIntent()
	{
		return (lcmsIntents)(HasValue ? cmsTakeRenderingIntent(Handler) : (-1));
	}
		
	lcmsICColorSpaceSignature	lcmsProfile::_GetColorSpace()
	{
		return HasValue ? (lcmsICColorSpaceSignature)cmsGetColorSpace(Handler) : lcmsICColorSpaceSignature::MaxEnumData;
	}
	
	lcmsICProfileClassSignature	lcmsProfile::_GetDeviceClass()
	{
		return HasValue ? (lcmsICProfileClassSignature)cmsGetDeviceClass(Handler) : lcmsICProfileClassSignature::MaxEnumClass;
	}

	bool lcmsProfile::IsTag(lcmsICTagSignature tagSignature)
	{
		return HasValue ? (cmsIsTag(Handler,(icTagSignature)tagSignature) != 0) : false;
	}
		
	bool lcmsProfile::IsIntentSupported(lcmsIntents Intent, lcmsUsedDirection UsedDirection)
	{
		return HasValue ? (cmsIsIntentSupported(Handler,(Int32)Intent,(Int32)UsedDirection) != 0) : false;
	}

	lcmsPixelType lcmsProfile::_GetPixelType()
	{
		if(!HasValue) return (lcmsPixelType)icMaxEnumData;

		switch ((icColorSpaceSignature)ColorSpace) 
		{
		case icSigGrayData: 
			return  lcmsPixelType::GRAY;
		case icSigRgbData:  
			return  lcmsPixelType::RGB;
		case icSigCmyData:  
			return  lcmsPixelType::CMY;
		case icSigCmykData: 
			return  lcmsPixelType::CMYK;
		case icSigYCbCrData:
			return  lcmsPixelType::YCbCr;
		case icSigLuvData:  
			return  lcmsPixelType::YUV;
		case icSigXYZData:  
			return  lcmsPixelType::XYZ;
		case icSigLabData:  
			return  lcmsPixelType::Lab;
		case icSigLuvKData: 
			return  lcmsPixelType::YUVK;
		case icSigHsvData:  
			return  lcmsPixelType::HSV;
		case icSigHlsData:  
			return  lcmsPixelType::HLS;
		case icSigYxyData:  
			return  lcmsPixelType::Yxy;
		case icSigHexachromeData: 
			return  lcmsPixelType::HiFi;
		default:  
			return (lcmsPixelType)icMaxEnumData;
		}		
	}
}