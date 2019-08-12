#pragma managed
#include "Stdafx.h"

using namespace System::Collections::Generic;

namespace LittleCMSWrapper
{	
	bool lcmsTransform::Close(bool deleteProfiles)
	{
		if (HasValue) cmsDeleteTransform(Handler);
		Handler = nullptr;
		bool result = true;
		if(deleteProfiles)
		{
			for each(lcmsProfile^ profile in _ProfileList)  
				result =  result && profile->Close();
					
			_ProfileList->Clear();
		}
		return result;
	};
	
	void lcmsTransform::_InitTransform()
	{
		_ProfileList = gcnew List<lcmsProfile^>();

		_InputFormat = UInt32::MaxValue;
		_OutputFormat = UInt32::MaxValue;

		_Flags = lcmsFlags::EMPTY;

		_Intent = lcmsIntents::PERCEPTUAL;
		_ProofingIntent = lcmsIntents::ABSOLUTE_COLORIMETRIC;

		_AdaptationState = 0;
		_BlackPreservationStrategy = lcmsBlackPreservation::BlackInkOnly;

		_LCMS_AdaptationState = _AdaptationState;
		_LCMS_BlackPreservationStrategy = (Int32)_BlackPreservationStrategy;
	}

	lcmsTransform^ lcmsTransform::CreateTransform(lcmsProfile^ hInProfile,UInt32 inputFormat,lcmsProfile^ hOutProfile, UInt32 outputFormat, lcmsIntents intent,lcmsFlags dwFlags, lcmsTransformExtraArgs^ extraArgs)
	{
		if(hInProfile == nullptr || hOutProfile == nullptr) return nullptr;

		lcmsTransform^ tTransform = gcnew lcmsTransform(); 
		
		tTransform->_BeforeTransform(extraArgs);
		
		tTransform->Handler = cmsCreateTransform(hInProfile->Handler,inputFormat,hOutProfile->Handler,outputFormat,(Int32)intent,(UInt32)dwFlags);

		tTransform->_AfterTransform(extraArgs);

		tTransform->_ProfileList->Add(hInProfile);
		tTransform->_ProfileList->Add(hOutProfile);
		
		tTransform->_InputFormat = inputFormat;
		tTransform->_OutputFormat = outputFormat;

		tTransform->_Intent= intent;

		tTransform->_Flags = dwFlags;

		
		return tTransform;
	}

	lcmsTransform^ lcmsTransform::CreateProofingTransform(lcmsProfile^ hInProfile,UInt32 inputFormat,lcmsProfile^ hOutProfile, UInt32 outputFormat,lcmsProfile^ hProofingProfile,lcmsIntents intent,lcmsIntents proofingIntent,lcmsFlags dwFlags, lcmsTransformExtraArgs^ extraArgs)
	{
		if(hInProfile == nullptr || hOutProfile == nullptr || hProofingProfile == nullptr) return nullptr;	

		lcmsTransform^ tTransform = gcnew lcmsTransform(); 
		
		tTransform->_BeforeTransform(extraArgs);

		tTransform->Handler = cmsCreateProofingTransform(hInProfile->Handler,inputFormat,hOutProfile->Handler,outputFormat,hProofingProfile->Handler,(Int32)intent,(Int32)proofingIntent,(UInt32)dwFlags);
		
		tTransform->_AfterTransform(extraArgs);

		tTransform->_ProfileList->Add(hInProfile);
		tTransform->_ProfileList->Add(hProofingProfile);
		tTransform->_ProfileList->Add(hOutProfile);
		
		tTransform->_InputFormat = inputFormat;
		tTransform->_OutputFormat = outputFormat;

		tTransform->_Intent= intent;
		tTransform->_ProofingIntent= proofingIntent;

		tTransform->_Flags = dwFlags;

		return tTransform;
	}

	void lcmsTransform::ChangeBuffersFormat(UInt32 newInputFormat, UInt32 newOutputFormat)
	{                    
		_InputFormat = newInputFormat;
		_OutputFormat = newOutputFormat;
		cmsChangeBuffersFormat(Handler,_InputFormat,_OutputFormat);
	}

	void lcmsTransform::_BeforeTransform(lcmsTransformExtraArgs^ extraArgs)
	{
		if(extraArgs == nullptr) return;

		_AdaptationState = extraArgs->AdaptationState;
		_BlackPreservationStrategy = extraArgs->BlackPreservationStrategy;

		_LCMS_AdaptationState = cmsSetAdaptationState(_AdaptationState);
		
		if(_BlackPreservationStrategy != lcmsBlackPreservation::Off)
			_LCMS_BlackPreservationStrategy = cmsSetCMYKPreservationStrategy((Int32)_BlackPreservationStrategy);
	}

	void lcmsTransform::_AfterTransform(lcmsTransformExtraArgs^ extraArgs)
	{
		if(extraArgs == nullptr) return;

		cmsSetAdaptationState(_LCMS_AdaptationState);

		if(_BlackPreservationStrategy != lcmsBlackPreservation::Off)
			cmsSetCMYKPreservationStrategy(_LCMS_BlackPreservationStrategy);
	}


}