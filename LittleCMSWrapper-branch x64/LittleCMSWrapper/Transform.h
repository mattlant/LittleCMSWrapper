#pragma once  
#pragma managed
#include <vcclr.h>

using namespace System::Collections::Generic;
using namespace System;

namespace LittleCMSWrapper {
	
	public ref struct lcmsTransformExtraArgs
	{
		double AdaptationState;
		lcmsBlackPreservation BlackPreservationStrategy;

		lcmsTransformExtraArgs(double adaptationState, lcmsBlackPreservation blackPreservation)
			: AdaptationState(adaptationState),BlackPreservationStrategy(blackPreservation) {}
		
		lcmsTransformExtraArgs(double adaptationState) : AdaptationState(adaptationState),BlackPreservationStrategy(lcmsBlackPreservation::BlackInkOnly) {}
	};


	public ref class lcmsTransform: lcmsHandler
	{
	internal:
		lcmsTransform(void* hTransform) : lcmsHandler(hTransform) {_InitTransform();}

	protected:

#pragma region Protected Fields
		List<lcmsProfile^> ^_ProfileList;

		UInt32 _InputFormat;
		UInt32 _OutputFormat;	

		lcmsIntents _Intent;  
		lcmsIntents _ProofingIntent;	 

		lcmsFlags _Flags;  

		double _AdaptationState;

		lcmsBlackPreservation _BlackPreservationStrategy;

		double _LCMS_AdaptationState;

		int _LCMS_BlackPreservationStrategy;
#pragma endregion

#pragma region Protected Functions
		void _InitTransform();  

		void _BeforeTransform(lcmsTransformExtraArgs^ extraArgs);

		void _AfterTransform(lcmsTransformExtraArgs^ extraArgs); 
#pragma endregion

	public:
		lcmsTransform() : lcmsHandler() {_InitTransform();}
		
#pragma region Properties
		property double AdaptationState
		{
			double get() { return _AdaptationState; }
		}

		property lcmsBlackPreservation BlackPreservationStrategy
		{
			lcmsBlackPreservation get() { return _BlackPreservationStrategy; }
		}

		property UInt32 InputFormat
		{
			UInt32 get() { return _InputFormat; }
		}


		property UInt32 OutputFormat
		{
			UInt32 get() { return _OutputFormat; }
		}


		property lcmsIntents Intent
		{
			lcmsIntents get() { return _Intent; }
		}


		property lcmsIntents ProofingIntent
		{
			lcmsIntents get() { return _ProofingIntent; }
		}


		property lcmsFlags Flags
		{
			lcmsFlags get() { return _Flags; }
		}


		property Int32 ProfileCount	
		{
			Int32 get() { return _ProfileList->Count; }
		}

		property lcmsProfile^ InputProfile 
		{
			lcmsProfile^ get(){	return (ProfileCount>0) ? _ProfileList[0] : nullptr;}
		}

		property lcmsProfile^ ProofingProfile 
		{
			lcmsProfile^ get(){return (ProfileCount==3) ? _ProfileList[1] : nullptr;}
		}

		property lcmsProfile^ OutputProfile 
		{
			lcmsProfile^ get(){return (ProfileCount>1) ? _ProfileList[ProfileCount-1] : nullptr;}
		}
#pragma endregion

		//TODO: ProfileList[index]
		
		virtual bool Close() override {return Close(true);}
		bool Close(bool deleteProfiles);

		static lcmsTransform^ CreateTransform(lcmsProfile^ hInProfile,UInt32 inputFormat,lcmsProfile^ hOutProfile, UInt32 outputFormat, lcmsIntents intent,lcmsFlags dwFlags, lcmsTransformExtraArgs^ extraArgs);		
				
		static lcmsTransform^ CreateProofingTransform(lcmsProfile^ hInProfile,UInt32 inputFormat,lcmsProfile^ hOutProfile, UInt32 outputFormat,lcmsProfile^ hProofingProfile,lcmsIntents intent,lcmsIntents proofingIntent,lcmsFlags dwFlags, lcmsTransformExtraArgs^ extraArgs);
		
		//LCMSAPI cmsHTRANSFORM LCMSEXPORT cmsCreateMultiprofileTransform(cmsHPROFILE hProfiles[],
		//																int nProfiles,
		//																DWORD InputFormat,
		//																DWORD OutputFormat,
		//																int Intent,
		//																DWORD dwFlags);


		// Converts a transform to a device link profile
		lcmsProfile^ ToDeviceLink() {return gcnew lcmsProfile(cmsTransform2DeviceLink(Handler,(UInt32)_Flags));}
		lcmsProfile^ ToDeviceLink(lcmsFlags dwFlags) {return gcnew lcmsProfile(cmsTransform2DeviceLink(Handler,(UInt32)dwFlags));}

		void ChangeBuffersFormat(UInt32 newInputFormat, UInt32 newOutputFormat);

		void DoTransform(IntPtr^ inputBuffer, IntPtr^ outputBuffer, UInt32 sizeInPixels) {cmsDoTransform(Handler,inputBuffer->ToPointer(),outputBuffer->ToPointer(),sizeInPixels);}

		//LCMSAPI void         LCMSEXPORT cmsSetAlarmCodes(int r, int g, int b);
		//LCMSAPI void         LCMSEXPORT cmsGetAlarmCodes(int *r, int *g, int *b);
	};
}