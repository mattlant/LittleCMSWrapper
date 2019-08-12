#pragma once
#pragma managed

namespace LittleCMSWrapper
{
	public enum class lcmsICTagSignature : UInt32 {
    	SigAToB0Tag                       = 0x41324230L,  /* 'A2B0' */ 
    	SigAToB1Tag                       = 0x41324231L,  /* 'A2B1' */
    	SigAToB2Tag                       = 0x41324232L,  /* 'A2B2' */ 
    	SigBlueColorantTag                = 0x6258595AL,  /* 'bXYZ' */
    	SigBlueTRCTag                     = 0x62545243L,  /* 'bTRC' */
    	SigBToA0Tag                       = 0x42324130L,  /* 'B2A0' */
    	SigBToA1Tag                       = 0x42324131L,  /* 'B2A1' */
    	SigBToA2Tag                       = 0x42324132L,  /* 'B2A2' */
    	SigCalibrationDateTimeTag         = 0x63616C74L,  /* 'calt' */
    	SigCharTargetTag                  = 0x74617267L,  /* 'targ' */ 
    	SigCopyrightTag                   = 0x63707274L,  /* 'cprt' */
    	SigCrdInfoTag                     = 0x63726469L,  /* 'crdi' */
    	SigDeviceMfgDescTag               = 0x646D6E64L,  /* 'dmnd' */
    	SigDeviceModelDescTag             = 0x646D6464L,  /* 'dmdd' */
    	SigGamutTag                       = 0x67616D74L,  /* 'gamt ' */
    	SigGrayTRCTag                     = 0x6b545243L,  /* 'kTRC' */
    	SigGreenColorantTag               = 0x6758595AL,  /* 'gXYZ' */
    	SigGreenTRCTag                    = 0x67545243L,  /* 'gTRC' */
    	SigLuminanceTag                   = 0x6C756d69L,  /* 'lumi' */
    	SigMeasurementTag                 = 0x6D656173L,  /* 'meas' */
    	SigMediaBlackPointTag             = 0x626B7074L,  /* 'bkpt' */
    	SigMediaWhitePointTag             = 0x77747074L,  /* 'wtpt' */
    	SigNamedColorTag                  = 0x6E636f6CL,  /* 'ncol' 
    	                                                     * OBSOLETE, use ncl2 */
    	SigNamedColor2Tag                 = 0x6E636C32L,  /* 'ncl2' */
    	SigPreview0Tag                    = 0x70726530L,  /* 'pre0' */
    	SigPreview1Tag                    = 0x70726531L,  /* 'pre1' */
    	SigPreview2Tag                    = 0x70726532L,  /* 'pre2' */
    	SigProfileDescriptionTag          = 0x64657363L,  /* 'desc' */
    	SigProfileSequenceDescTag         = 0x70736571L,  /* 'pseq' */
    	SigPs2CRD0Tag                     = 0x70736430L,  /* 'psd0' */
    	SigPs2CRD1Tag                     = 0x70736431L,  /* 'psd1' */
    	SigPs2CRD2Tag                     = 0x70736432L,  /* 'psd2' */
    	SigPs2CRD3Tag                     = 0x70736433L,  /* 'psd3' */
    	SigPs2CSATag                      = 0x70733273L,  /* 'ps2s' */
    	SigPs2RenderingIntentTag          = 0x70733269L,  /* 'ps2i' */
    	SigRedColorantTag                 = 0x7258595AL,  /* 'rXYZ' */
    	SigRedTRCTag                      = 0x72545243L,  /* 'rTRC' */
    	SigScreeningDescTag               = 0x73637264L,  /* 'scrd' */
    	SigScreeningTag                   = 0x7363726EL,  /* 'scrn' */
    	SigTechnologyTag                  = 0x74656368L,  /* 'tech' */
    	SigUcrBgTag                       = 0x62666420L,  /* 'bfd ' */
    	SigViewingCondDescTag             = 0x76756564L,  /* 'vued' */
    	SigViewingConditionsTag           = 0x76696577L,  /* 'view' */
    	MaxEnumTag                        = 0xFFFFFFFFL, 
	};
}