#pragma once  
#pragma managed
#include <vcclr.h>

using namespace System;

namespace LittleCMSWrapper {

	public ref class lcmsProfile: lcmsHandler
	{
	internal:
		lcmsProfile(void* hProfile) : lcmsHandler(hProfile) {_InitValues();}

	private:
#pragma region Private Fields
		lcmsWhitePoint^ _WhitePoint; 
		lcmsCIEXYZ^		_BlackPoint;
		lcmsCIEXYZ^		_Iluminant;

		UInt32			_HeaderFlags;
		UInt32			_HeaderAttributes;

		String^			_ProductName;
		String^			_ProductDescription;
		String^			_ProductInfo;
		String^			_Manufacturer;
		String^			_Model;
		String^			_Copyright;
		
		array<Byte>^	_ProfileID;

		DateTime^		_CreationDateTime;
		DateTime^		_CalibrationDateTime;

		lcmsIntents		_RenderingIntent;

		lcmsICColorSpaceSignature   _ColorSpace;
		lcmsICProfileClassSignature _DeviceClass;

		lcmsPixelType	_PixelType;
#pragma endregion
		
#pragma region Private Functions

		void			_InitValues();

		lcmsWhitePoint^ _TakeMediaWhitePoint();
		lcmsCIEXYZ^		_TakeMediaBlackPoint();


		//int cdecl cmsDetectBlackPoint(LPcmsCIEXYZ BlackPoint, cmsHPROFILE hProfile, int Intent, DWORD dwFlags);
		lcmsCIEXYZ^ 	_TakeIluminant();
		////LCMSAPI LCMSBOOL      LCMSEXPORT cmsTakeColorants(LPcmsCIEXYZTRIPLE Dest, cmsHPROFILE hProfile);
		UInt32	        _TakeHeaderFlags();
		UInt32			_TakeHeaderAttributes();

		//LCMSAPI void          LCMSEXPORT cmsSetLanguage(const char LanguageCode[4], const char CountryCode[4]);
		String^			_TakeProductName();
		String^			_TakeProductDesc();
		String^			_TakeProductInfo();
		String^			_TakeManufacturer();
		String^			_TakeModel();
		String^			_TakeCopyright();

		array<Byte>^	_TakeProfileID();

		DateTime^		_TakeCreationDateTime();
		DateTime^		_TakeCalibrationDateTime();

		
		lcmsIntents		_TakeRenderingIntent();

		
		
		//LCMSAPI LCMSBOOL      LCMSEXPORT cmsTakeCharTargetData(cmsHPROFILE hProfile, char** Data, size_t* len);
		//                                                  
		//LCMSAPI int           LCMSEXPORT cmsReadICCTextEx(cmsHPROFILE hProfile, icTagSignature sig, char *Text, size_t size);
		//LCMSAPI int           LCMSEXPORT cmsReadICCText(cmsHPROFILE hProfile, icTagSignature sig, char *Text);

		//LCMSAPI LPcmsSEQ      LCMSEXPORT cmsReadProfileSequenceDescription(cmsHPROFILE hProfile);
		//LCMSAPI void          LCMSEXPORT cmsFreeProfileSequenceDescription(LPcmsSEQ pseq);

		//How Profiles May be used

		lcmsICColorSpaceSignature	_GetColorSpace();
		lcmsICProfileClassSignature	_GetDeviceClass();

		//LCMSAPI icColorSpaceSignature   LCMSEXPORT cmsGetPCS(cmsHPROFILE hProfile);
		//LCMSAPI DWORD                   LCMSEXPORT cmsGetProfileICCversion(cmsHPROFILE hProfile);
		//LCMSAPI void                    LCMSEXPORT cmsSetProfileICCversion(cmsHPROFILE hProfile, DWORD Version);
		//LCMSAPI icInt32Number           LCMSEXPORT cmsGetTagCount(cmsHPROFILE hProfile);
		//LCMSAPI icTagSignature          LCMSEXPORT cmsGetTagSignature(cmsHPROFILE hProfile, icInt32Number n);


		//LCMSAPI void          LCMSEXPORT cmsSetDeviceClass(cmsHPROFILE hProfile, icProfileClassSignature sig);
		//LCMSAPI void          LCMSEXPORT cmsSetColorSpace(cmsHPROFILE hProfile, icColorSpaceSignature sig);
		//LCMSAPI void          LCMSEXPORT cmsSetPCS(cmsHPROFILE hProfile, icColorSpaceSignature pcs);
		//LCMSAPI void          LCMSEXPORT cmsSetRenderingIntent(cmsHPROFILE hProfile, int RenderingIntent);
		//LCMSAPI void          LCMSEXPORT cmsSetHeaderFlags(cmsHPROFILE hProfile, DWORD Flags);
		//LCMSAPI void          LCMSEXPORT cmsSetHeaderAttributes(cmsHPROFILE hProfile, DWORD Flags);
		//LCMSAPI void          LCMSEXPORT cmsSetProfileID(cmsHPROFILE hProfile, LPBYTE ProfileID);

		lcmsPixelType		_GetPixelType();
#pragma endregion

	public:

#pragma region Properties
		
		property lcmsWhitePoint^ WhitePoint
		{
			lcmsWhitePoint^ get() 
			{ 
				if(_WhitePoint == nullptr) _WhitePoint = _TakeMediaWhitePoint();
				return _WhitePoint; 
			}
		}

		property lcmsCIEXYZ^ BlackPoint
		{
			lcmsCIEXYZ^ get() 
			{ 
				if(_BlackPoint == nullptr) _BlackPoint = _TakeMediaBlackPoint();
				return _BlackPoint; 
			}
		}

		property lcmsCIEXYZ^ Iluminant
		{
			lcmsCIEXYZ^ get() 
			{ 
				if(_Iluminant == nullptr) _Iluminant = _TakeIluminant();
				return _Iluminant; 
			}
		}

		property UInt32 HeaderFlags
		{
			UInt32 get()
			{
				if(_HeaderFlags==UInt32::MaxValue) _HeaderFlags = _TakeHeaderFlags();
				return _HeaderFlags;
			}
		}

		property UInt32 HeaderAttributes
		{
			UInt32 get()
			{
				if(_HeaderAttributes==UInt32::MaxValue) _HeaderAttributes = _TakeHeaderAttributes();
				return _HeaderAttributes;
			}
		}

		property String^ ProductName
		{
			String^ get()
			{
				if(_ProductName == nullptr) _ProductName = _TakeProductName();
				return _ProductName;
			}
		}

		property String^ ProductDescription
		{
			String^ get()
			{
				if(_ProductDescription == nullptr) _ProductDescription = _TakeProductDesc();
				return _ProductDescription;
			}
		}
		
		property String^ ProductInfo
		{
			String^ get()
			{
				if(_ProductInfo == nullptr) _ProductInfo = _TakeProductInfo();
				return _ProductInfo;
			}
		}

		property String^ Manufacturer
		{
			String^ get()
			{
				if(_Manufacturer == nullptr) _Manufacturer = _TakeManufacturer();
				return _Manufacturer;
			}
		}

		property String^ Model
		{
			String^ get()
			{
				if(_Model == nullptr) _Model = _TakeModel();
				return _Model;
			}
		}

		property String^ Copyright
		{
			String^ get()
			{
				if(_Copyright == nullptr) _Copyright = _TakeCopyright();
				return _Copyright;
			}
		}

		property array<Byte>^ ProfileID
		{
			array<Byte>^ get()
			{
				if(_ProfileID == nullptr) _ProfileID = _TakeProfileID();
				return _ProfileID;
			}
		}

		property DateTime^ CreationDateTime
		{
			DateTime^ get()
			{
				if(_CreationDateTime == nullptr) _CreationDateTime = _TakeCreationDateTime();
				return _CreationDateTime;
			}
		}
		
		property DateTime^ CalibrationDateTime
		{
			DateTime^ get()
			{
				if(_CalibrationDateTime == nullptr) _CalibrationDateTime = _TakeCalibrationDateTime();
				return _CalibrationDateTime;
			}
		}

		property lcmsIntents RenderingIntent
		{
			lcmsIntents get()
			{
				if((Int32)_RenderingIntent == -1) _RenderingIntent = _TakeRenderingIntent();
				return _RenderingIntent;
			}
		}
		
		property lcmsICColorSpaceSignature ColorSpace
		{
			lcmsICColorSpaceSignature get()
			{
				if(_ColorSpace == lcmsICColorSpaceSignature::MaxEnumData) _ColorSpace = _GetColorSpace();
				return _ColorSpace;
			}
		}

		property lcmsICProfileClassSignature DeviceClass
		{
			lcmsICProfileClassSignature get()
			{
				if(_DeviceClass == lcmsICProfileClassSignature::MaxEnumClass) _DeviceClass = _GetDeviceClass();
				return _DeviceClass;
			}
		}

		property lcmsPixelType PixelType
		{
			lcmsPixelType get()
			{
				if(_PixelType == (lcmsPixelType)icMaxEnumData)   _PixelType = _GetPixelType();
				return _PixelType;
			}
		}

		
#pragma endregion

		static lcmsProfile^ OpenProfileFromFile(String ^sIccProfileFileName, String^ sAccess);

		static lcmsProfile^ OpenProfileFromFile(String ^sIccProfileFileName) {return OpenProfileFromFile(sIccProfileFileName,"r");}   

		static lcmsProfile^ OpenProfileFromMem(IntPtr^ memPtr, UInt32 size)  {return gcnew lcmsProfile(cmsOpenProfileFromMem(memPtr->ToPointer(),size));}

		static lcmsProfile^ OpenEmbeddedProfileFromJpeg(String^ jpegFileName);

		// Predefined run-time Profiles

		//LCMSAPI cmsHPROFILE   LCMSEXPORT cmsCreateRGBProfile(LPcmsCIExyY WhitePoint,
		//										LPcmsCIExyYTRIPLE Primaries,
		//										LPGAMMATABLE TransferFunction[3]);

		//LCMSAPI cmsHPROFILE   LCMSEXPORT cmsCreateGrayProfile(LPcmsCIExyY WhitePoint,
		//											  LPGAMMATABLE TransferFunction);

		//LCMSAPI cmsHPROFILE   LCMSEXPORT cmsCreateLinearizationDeviceLink(icColorSpaceSignature ColorSpace,
		//														LPGAMMATABLE TransferFunctions[]);

		//LCMSAPI cmsHPROFILE   LCMSEXPORT cmsCreateInkLimitingDeviceLink(icColorSpaceSignature ColorSpace,
		//													  double Limit);

		static lcmsProfile^	CreateLabProfile(lcmsWhitePoint ^whitePoint);

		static lcmsProfile^	CreateLab4Profile(lcmsWhitePoint^ whitePoint);

		static lcmsProfile^ CreateXYZProfile() { return gcnew lcmsProfile(cmsCreateXYZProfile());}

		static lcmsProfile^	Create_sRGBProfile() {return gcnew lcmsProfile(cmsCreate_sRGBProfile());}

		static lcmsProfile^	CreateNULLProfile() {return gcnew lcmsProfile(cmsCreateNULLProfile());}

		//LCMSAPI cmsHPROFILE   LCMSEXPORT cmsCreateBCHSWabstractProfile(int nLUTPoints,
		//													 double Bright, 
		//													 double Contrast,
		//													 double Hue,
		//													 double Saturation,
		//													 int TempSrc, 
		//													 int TempDest);		

		virtual bool Close() override; 

		//Shouldn't be used --- Use OpenProfileFromFile with "w" as access
		bool SaveProfile(String^ fileName);
		Int32 SaveProfileToMem(IntPtr^ memPtr);

		//Other functions 

		bool			IsTag(lcmsICTagSignature tagSignature);
		bool			IsIntentSupported(lcmsIntents Intent, lcmsUsedDirection UsedDirection);
	};
}