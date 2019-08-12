#pragma once
#pragma managed

namespace LittleCMSWrapper
{
	public enum class lcmsICColorSpaceSignature : UInt32
	{
		SigXYZData                        = 0x58595A20L,  /* 'XYZ ' */
		SigLabData                        = 0x4C616220L,  /* 'Lab ' */
		SigLuvData                        = 0x4C757620L,  /* 'Luv ' */
		SigYCbCrData                      = 0x59436272L,  /* 'YCbr' */
		SigYxyData                        = 0x59787920L,  /* 'Yxy ' */
		SigRgbData                        = 0x52474220L,  /* 'RGB ' */
		SigGrayData                       = 0x47524159L,  /* 'GRAY' */
		SigHsvData                        = 0x48535620L,  /* 'HSV ' */
		SigHlsData                        = 0x484C5320L,  /* 'HLS ' */
		SigCmykData                       = 0x434D594BL,  /* 'CMYK' */
		SigCmyData                        = 0x434D5920L,  /* 'CMY ' */
		Sig2colorData                     = 0x32434C52L,  /* '2CLR' */
		Sig3colorData                     = 0x33434C52L,  /* '3CLR' */
		Sig4colorData                     = 0x34434C52L,  /* '4CLR' */
		Sig5colorData                     = 0x35434C52L,  /* '5CLR' */
		Sig6colorData                     = 0x36434C52L,  /* '6CLR' */
		Sig7colorData                     = 0x37434C52L,  /* '7CLR' */
		Sig8colorData                     = 0x38434C52L,  /* '8CLR' */
		Sig9colorData                     = 0x39434C52L,  /* '9CLR' */
		Sig10colorData                    = 0x41434C52L,  /* 'ACLR' */
		Sig11colorData                    = 0x42434C52L,  /* 'BCLR' */
		Sig12colorData                    = 0x43434C52L,  /* 'CCLR' */
		Sig13colorData                    = 0x44434C52L,  /* 'DCLR' */
		Sig14colorData                    = 0x45434C52L,  /* 'ECLR' */
		Sig15colorData                    = 0x46434C52L,  /* 'FCLR' */
		MaxEnumData                       = 0xFFFFFFFFL,  

		//Extra additions by Little CMS

		SigLuvKData							= 0x4C75764BL,  // 'LuvK'

		SigHexachromeData            		= 0x4d434836L,  // MCH6
		SigHeptachromeData           		= 0x4d434837L,  // MCH7
		SigOctachromeData            		= 0x4d434838L,  // MCH8
													 
		SigMCH5Data                  		= 0x4d434835L,  // MCH5
		SigMCH6Data                  		= 0x4d434836L,  // MCH6
		SigMCH7Data                  		= 0x4d434837L,  // MCH7
		SigMCH8Data                  		= 0x4d434838L,  // MCH8
		SigMCH9Data                  		= 0x4d434839L,  // MCH9
		SigMCHAData                  		= 0x4d434841L,  // MCHA
		SigMCHBData                  		= 0x4d434842L,  // MCHB
		SigMCHCData                  		= 0x4d434843L,  // MCHC
		SigMCHDData                  		= 0x4d434844L,  // MCHD
		SigMCHEData                  		= 0x4d434845L,  // MCHE
		SigMCHFData                  		= 0x4d434846L,  // MCHF
	};
}