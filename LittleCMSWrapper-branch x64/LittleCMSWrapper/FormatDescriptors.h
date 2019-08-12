#pragma once
#pragma managed

using namespace System;

namespace LittleCMSWrapper
{
	public ref class lcmsDefs
	{
	internal:
		// Format of pixel is defined by one DWORD, using bit fields as follows
		//
		//            D TTTTT - Y F P X S EEE CCCC BBB
		//
		//            D: Use dither (8 bits only)
		//            T: Pixeltype
		//            F: Flavor  0=MinIsBlack(Chocolate) 1=MinIsWhite(Vanilla)
		//            P: Planar? 0=Chunky, 1=Planar
		//            X: swap 16 bps endianess?
		//            S: Do swap? ie, BGR, KYMC
		//            E: Extra samples
		//            C: Channels (Samples per pixel)
		//            B: Bytes per sample
		//            Y: Swap first - changes ABGR to BGRA and KCMY to CMYK

		// Helping functions to build format descriptos

		static Int32 DITHER_SH(Int32 s)				{return s << 22;}
		static Int32 COLORSPACE_SH(lcmsPixelType pt){return ((Int32)pt) << 16;}
		//static Int32 COLORSPACE_SH(Int32 s)			{return s << 16;}
		static Int32 SWAPFIRST_SH(Int32 s)			{return s << 14;}
		static Int32 FLAVOR_SH(Int32 s)				{return s << 13;}
		static Int32 PLANAR_SH(Int32 p)				{return p << 12;}
		static Int32 ENDIAN16_SH(Int32 e)			{return e << 11;}
		static Int32 DOSWAP_SH(Int32 e)				{return e << 10;}
		static Int32 EXTRA_SH(Int32 e)				{return e << 7;}
		static Int32 CHANNELS_SH(Int32 c)			{return c << 3;}
		static Int32 BYTES_SH(Int32 b)				{return b;}

		static Int32 NOCOLORSPACECHECK(Int32 x)		{return x & 0xFFFF;}

		// Gridpoints

		static Int32 cmsFLAGS_GRIDPOINTS(Int32 n)	{return (n & 0xFF) << 16;}

	public:
	//EXTRAS
		//TODO: Put here everything else

	//FORMAT DESCRIPTORS
		static UInt32 TYPE_GRAY_8								= (COLORSPACE_SH(lcmsPixelType::GRAY)|CHANNELS_SH(1)|BYTES_SH(1));
		static UInt32 TYPE_GRAY_8_REV       					= (COLORSPACE_SH(lcmsPixelType::GRAY)|CHANNELS_SH(1)|BYTES_SH(1)|FLAVOR_SH(1));
		static UInt32 TYPE_GRAY_16           					= (COLORSPACE_SH(lcmsPixelType::GRAY)|CHANNELS_SH(1)|BYTES_SH(2));
		static UInt32 TYPE_GRAY_16_REV       					= (COLORSPACE_SH(lcmsPixelType::GRAY)|CHANNELS_SH(1)|BYTES_SH(2)|FLAVOR_SH(1));
		static UInt32 TYPE_GRAY_16_SE        					= (COLORSPACE_SH(lcmsPixelType::GRAY)|CHANNELS_SH(1)|BYTES_SH(2)|ENDIAN16_SH(1));
		static UInt32 TYPE_GRAYA_8           					= (COLORSPACE_SH(lcmsPixelType::GRAY)|EXTRA_SH(1)|CHANNELS_SH(1)|BYTES_SH(1));
		static UInt32 TYPE_GRAYA_16          					= (COLORSPACE_SH(lcmsPixelType::GRAY)|EXTRA_SH(1)|CHANNELS_SH(1)|BYTES_SH(2));
		static UInt32 TYPE_GRAYA_16_SE       					= (COLORSPACE_SH(lcmsPixelType::GRAY)|EXTRA_SH(1)|CHANNELS_SH(1)|BYTES_SH(2)|ENDIAN16_SH(1));
		static UInt32 TYPE_GRAYA_8_PLANAR    					= (COLORSPACE_SH(lcmsPixelType::GRAY)|EXTRA_SH(1)|CHANNELS_SH(1)|BYTES_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_GRAYA_16_PLANAR   					= (COLORSPACE_SH(lcmsPixelType::GRAY)|EXTRA_SH(1)|CHANNELS_SH(1)|BYTES_SH(2)|PLANAR_SH(1));

		static UInt32 TYPE_RGB_8             					= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(1));
		static UInt32 TYPE_RGB_8_PLANAR      					= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_BGR_8             					= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_BGR_8_PLANAR      					= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(1)|DOSWAP_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_RGB_16            					= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(2));
		static UInt32 TYPE_RGB_16_PLANAR     					= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(2)|PLANAR_SH(1));
		static UInt32 TYPE_RGB_16_SE         					= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(2)|ENDIAN16_SH(1));
		static UInt32 TYPE_BGR_16            					= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(2)|DOSWAP_SH(1));
		static UInt32 TYPE_BGR_16_PLANAR     					= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(2)|DOSWAP_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_BGR_16_SE         					= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(2)|DOSWAP_SH(1)|ENDIAN16_SH(1));

		static UInt32 TYPE_RGBA_8            					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(1));
		static UInt32 TYPE_RGBA_8_PLANAR     					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_RGBA_16           					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(2));
		static UInt32 TYPE_RGBA_16_PLANAR    					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(2)|PLANAR_SH(1));
		static UInt32 TYPE_RGBA_16_SE        					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(2)|ENDIAN16_SH(1));

		static UInt32 TYPE_ARGB_8            					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(1)|SWAPFIRST_SH(1));
		static UInt32 TYPE_ARGB_16           					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(2)|SWAPFIRST_SH(1));

		static UInt32 TYPE_ABGR_8            					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_ABGR_16           					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(2)|DOSWAP_SH(1));
		static UInt32 TYPE_ABGR_16_PLANAR    					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(2)|DOSWAP_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_ABGR_16_SE        					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(2)|DOSWAP_SH(1)|ENDIAN16_SH(1));

		static UInt32 TYPE_BGRA_8            					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(1)|DOSWAP_SH(1)|SWAPFIRST_SH(1));
		static UInt32 TYPE_BGRA_16           					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(2)|DOSWAP_SH(1)|SWAPFIRST_SH(1));
		static UInt32 TYPE_BGRA_16_SE        					= (COLORSPACE_SH(lcmsPixelType::RGB)|EXTRA_SH(1)|CHANNELS_SH(3)|BYTES_SH(2)|ENDIAN16_SH(1)|SWAPFIRST_SH(1));

		static UInt32 TYPE_CMY_8             					= (COLORSPACE_SH(lcmsPixelType::CMY)|CHANNELS_SH(3)|BYTES_SH(1));
		static UInt32 TYPE_CMY_8_PLANAR      					= (COLORSPACE_SH(lcmsPixelType::CMY)|CHANNELS_SH(3)|BYTES_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_CMY_16            					= (COLORSPACE_SH(lcmsPixelType::CMY)|CHANNELS_SH(3)|BYTES_SH(2));
		static UInt32 TYPE_CMY_16_PLANAR     					= (COLORSPACE_SH(lcmsPixelType::CMY)|CHANNELS_SH(3)|BYTES_SH(2)|PLANAR_SH(1));
		static UInt32 TYPE_CMY_16_SE         					= (COLORSPACE_SH(lcmsPixelType::CMY)|CHANNELS_SH(3)|BYTES_SH(2)|ENDIAN16_SH(1));

		static UInt32 TYPE_CMYK_8            					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(1));
		static UInt32 TYPE_CMYKA_8           					= (COLORSPACE_SH(lcmsPixelType::CMYK)|EXTRA_SH(1)|CHANNELS_SH(4)|BYTES_SH(1));
		static UInt32 TYPE_CMYK_8_REV        					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(1)|FLAVOR_SH(1));
		static UInt32 TYPE_YUVK_8            					= TYPE_CMYK_8_REV;
		static UInt32 TYPE_CMYK_8_PLANAR     					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_CMYK_16           					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(2));
		static UInt32 TYPE_CMYK_16_REV       					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(2)|FLAVOR_SH(1));
		static UInt32 TYPE_YUVK_16           					= TYPE_CMYK_16_REV;
		static UInt32 TYPE_CMYK_16_PLANAR    					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(2)|PLANAR_SH(1));
		static UInt32 TYPE_CMYK_16_SE        					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(2)|ENDIAN16_SH(1));

		static UInt32 TYPE_KYMC_8            					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC_16           					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(2)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC_16_SE        					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(2)|DOSWAP_SH(1)|ENDIAN16_SH(1));

		static UInt32 TYPE_KCMY_8            					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(1)|SWAPFIRST_SH(1));
		static UInt32 TYPE_KCMY_8_REV        					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(1)|FLAVOR_SH(1)|SWAPFIRST_SH(1));
		static UInt32 TYPE_KCMY_16           					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(2)|SWAPFIRST_SH(1));
		static UInt32 TYPE_KCMY_16_REV       					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(2)|FLAVOR_SH(1)|SWAPFIRST_SH(1));
		static UInt32 TYPE_KCMY_16_SE        					= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(2)|ENDIAN16_SH(1)|SWAPFIRST_SH(1));


		// HiFi separations, Thanks to Steven Greaves for providing the code,
		// the colorspace is not checked
		static UInt32 TYPE_CMYK5_8           					= (CHANNELS_SH(5)|BYTES_SH(1));
		static UInt32 TYPE_CMYK5_16          					= (CHANNELS_SH(5)|BYTES_SH(2));
		static UInt32 TYPE_CMYK5_16_SE       					= (CHANNELS_SH(5)|BYTES_SH(2)|ENDIAN16_SH(1));
		static UInt32 TYPE_KYMC5_8           					= (CHANNELS_SH(5)|BYTES_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC5_16          					= (CHANNELS_SH(5)|BYTES_SH(2)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC5_16_SE       					= (CHANNELS_SH(5)|BYTES_SH(2)|DOSWAP_SH(1)|ENDIAN16_SH(1));

		static UInt32 TYPE_CMYKcm_8          					= (CHANNELS_SH(6)|BYTES_SH(1));
		static UInt32 TYPE_CMYKcm_8_PLANAR   					= (CHANNELS_SH(6)|BYTES_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_CMYKcm_16         					= (CHANNELS_SH(6)|BYTES_SH(2));
		static UInt32 TYPE_CMYKcm_16_PLANAR  					= (CHANNELS_SH(6)|BYTES_SH(2)|PLANAR_SH(1));
		static UInt32 TYPE_CMYKcm_16_SE      					= (CHANNELS_SH(6)|BYTES_SH(2)|ENDIAN16_SH(1));

		// Separations with more than 6 channels aren't very standarized,
		// Except most start with CMYK and add other colors, so I just used
		// then total number of channels after CMYK i.e CMYK8_8

		static UInt32 TYPE_CMYK7_8           					= (CHANNELS_SH(7)|BYTES_SH(1));
		static UInt32 TYPE_CMYK7_16          					= (CHANNELS_SH(7)|BYTES_SH(2));
		static UInt32 TYPE_CMYK7_16_SE       					= (CHANNELS_SH(7)|BYTES_SH(2)|ENDIAN16_SH(1));
		static UInt32 TYPE_KYMC7_8           					= (CHANNELS_SH(7)|BYTES_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC7_16          					= (CHANNELS_SH(7)|BYTES_SH(2)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC7_16_SE       					= (CHANNELS_SH(7)|BYTES_SH(2)|DOSWAP_SH(1)|ENDIAN16_SH(1));
		static UInt32 TYPE_CMYK8_8           					= (CHANNELS_SH(8)|BYTES_SH(1));
		static UInt32 TYPE_CMYK8_16          					= (CHANNELS_SH(8)|BYTES_SH(2));
		static UInt32 TYPE_CMYK8_16_SE       					= (CHANNELS_SH(8)|BYTES_SH(2)|ENDIAN16_SH(1));
		static UInt32 TYPE_KYMC8_8           					= (CHANNELS_SH(8)|BYTES_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC8_16          					= (CHANNELS_SH(8)|BYTES_SH(2)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC8_16_SE       					= (CHANNELS_SH(8)|BYTES_SH(2)|DOSWAP_SH(1)|ENDIAN16_SH(1));
		static UInt32 TYPE_CMYK9_8           					= (CHANNELS_SH(9)|BYTES_SH(1));
		static UInt32 TYPE_CMYK9_16          					= (CHANNELS_SH(9)|BYTES_SH(2));
		static UInt32 TYPE_CMYK9_16_SE       					= (CHANNELS_SH(9)|BYTES_SH(2)|ENDIAN16_SH(1));
		static UInt32 TYPE_KYMC9_8           					= (CHANNELS_SH(9)|BYTES_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC9_16          					= (CHANNELS_SH(9)|BYTES_SH(2)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC9_16_SE       					= (CHANNELS_SH(9)|BYTES_SH(2)|DOSWAP_SH(1)|ENDIAN16_SH(1));
		static UInt32 TYPE_CMYK10_8          					= (CHANNELS_SH(10)|BYTES_SH(1));
		static UInt32 TYPE_CMYK10_16         					= (CHANNELS_SH(10)|BYTES_SH(2));
		static UInt32 TYPE_CMYK10_16_SE      					= (CHANNELS_SH(10)|BYTES_SH(2)|ENDIAN16_SH(1));
		static UInt32 TYPE_KYMC10_8          					= (CHANNELS_SH(10)|BYTES_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC10_16         					= (CHANNELS_SH(10)|BYTES_SH(2)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC10_16_SE      					= (CHANNELS_SH(10)|BYTES_SH(2)|DOSWAP_SH(1)|ENDIAN16_SH(1));
		static UInt32 TYPE_CMYK11_8          					= (CHANNELS_SH(11)|BYTES_SH(1));
		static UInt32 TYPE_CMYK11_16         					= (CHANNELS_SH(11)|BYTES_SH(2));
		static UInt32 TYPE_CMYK11_16_SE      					= (CHANNELS_SH(11)|BYTES_SH(2)|ENDIAN16_SH(1));
		static UInt32 TYPE_KYMC11_8          					= (CHANNELS_SH(11)|BYTES_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC11_16         					= (CHANNELS_SH(11)|BYTES_SH(2)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC11_16_SE      					= (CHANNELS_SH(11)|BYTES_SH(2)|DOSWAP_SH(1)|ENDIAN16_SH(1));
		static UInt32 TYPE_CMYK12_8          					= (CHANNELS_SH(12)|BYTES_SH(1));
		static UInt32 TYPE_CMYK12_16         					= (CHANNELS_SH(12)|BYTES_SH(2));
		static UInt32 TYPE_CMYK12_16_SE      					= (CHANNELS_SH(12)|BYTES_SH(2)|ENDIAN16_SH(1));
		static UInt32 TYPE_KYMC12_8          					= (CHANNELS_SH(12)|BYTES_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC12_16         					= (CHANNELS_SH(12)|BYTES_SH(2)|DOSWAP_SH(1));
		static UInt32 TYPE_KYMC12_16_SE      					= (CHANNELS_SH(12)|BYTES_SH(2)|DOSWAP_SH(1)|ENDIAN16_SH(1));

		// Colorimetric

		static UInt32 TYPE_XYZ_16            					= (COLORSPACE_SH(lcmsPixelType::XYZ)|CHANNELS_SH(3)|BYTES_SH(2));
		static UInt32 TYPE_Lab_8             					= (COLORSPACE_SH(lcmsPixelType::Lab)|CHANNELS_SH(3)|BYTES_SH(1));
		static UInt32 TYPE_ALab_8            					= (COLORSPACE_SH(lcmsPixelType::Lab)|CHANNELS_SH(3)|BYTES_SH(1)|EXTRA_SH(1)|DOSWAP_SH(1));
		static UInt32 TYPE_Lab_16            					= (COLORSPACE_SH(lcmsPixelType::Lab)|CHANNELS_SH(3)|BYTES_SH(2));
		static UInt32 TYPE_Yxy_16            					= (COLORSPACE_SH(lcmsPixelType::Yxy)|CHANNELS_SH(3)|BYTES_SH(2));

		// YCbCr

		static UInt32 TYPE_YCbCr_8           					= (COLORSPACE_SH(lcmsPixelType::YCbCr)|CHANNELS_SH(3)|BYTES_SH(1));
		static UInt32 TYPE_YCbCr_8_PLANAR    					= (COLORSPACE_SH(lcmsPixelType::YCbCr)|CHANNELS_SH(3)|BYTES_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_YCbCr_16          					= (COLORSPACE_SH(lcmsPixelType::YCbCr)|CHANNELS_SH(3)|BYTES_SH(2));
		static UInt32 TYPE_YCbCr_16_PLANAR   					= (COLORSPACE_SH(lcmsPixelType::YCbCr)|CHANNELS_SH(3)|BYTES_SH(2)|PLANAR_SH(1));
		static UInt32 TYPE_YCbCr_16_SE       					= (COLORSPACE_SH(lcmsPixelType::YCbCr)|CHANNELS_SH(3)|BYTES_SH(2)|ENDIAN16_SH(1));

		// YUV

		static UInt32 TYPE_YUV_8           						= (COLORSPACE_SH(lcmsPixelType::YUV)|CHANNELS_SH(3)|BYTES_SH(1));
		static UInt32 TYPE_YUV_8_PLANAR    						= (COLORSPACE_SH(lcmsPixelType::YUV)|CHANNELS_SH(3)|BYTES_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_YUV_16          						= (COLORSPACE_SH(lcmsPixelType::YUV)|CHANNELS_SH(3)|BYTES_SH(2));
		static UInt32 TYPE_YUV_16_PLANAR   						= (COLORSPACE_SH(lcmsPixelType::YUV)|CHANNELS_SH(3)|BYTES_SH(2)|PLANAR_SH(1));
		static UInt32 TYPE_YUV_16_SE       						= (COLORSPACE_SH(lcmsPixelType::YUV)|CHANNELS_SH(3)|BYTES_SH(2)|ENDIAN16_SH(1));

		// HLS

		static UInt32 TYPE_HLS_8           						= (COLORSPACE_SH(lcmsPixelType::HLS)|CHANNELS_SH(3)|BYTES_SH(1));
		static UInt32 TYPE_HLS_8_PLANAR    						= (COLORSPACE_SH(lcmsPixelType::HLS)|CHANNELS_SH(3)|BYTES_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_HLS_16          						= (COLORSPACE_SH(lcmsPixelType::HLS)|CHANNELS_SH(3)|BYTES_SH(2));
		static UInt32 TYPE_HLS_16_PLANAR   						= (COLORSPACE_SH(lcmsPixelType::HLS)|CHANNELS_SH(3)|BYTES_SH(2)|PLANAR_SH(1));
		static UInt32 TYPE_HLS_16_SE       						= (COLORSPACE_SH(lcmsPixelType::HLS)|CHANNELS_SH(3)|BYTES_SH(2)|ENDIAN16_SH(1));


		// HSV

		static UInt32 TYPE_HSV_8           						= (COLORSPACE_SH(lcmsPixelType::HSV)|CHANNELS_SH(3)|BYTES_SH(1));
		static UInt32 TYPE_HSV_8_PLANAR    						= (COLORSPACE_SH(lcmsPixelType::HSV)|CHANNELS_SH(3)|BYTES_SH(1)|PLANAR_SH(1));
		static UInt32 TYPE_HSV_16          						= (COLORSPACE_SH(lcmsPixelType::HSV)|CHANNELS_SH(3)|BYTES_SH(2));
		static UInt32 TYPE_HSV_16_PLANAR   						= (COLORSPACE_SH(lcmsPixelType::HSV)|CHANNELS_SH(3)|BYTES_SH(2)|PLANAR_SH(1));
		static UInt32 TYPE_HSV_16_SE       						= (COLORSPACE_SH(lcmsPixelType::HSV)|CHANNELS_SH(3)|BYTES_SH(2)|ENDIAN16_SH(1));

		// Named color index. Only 16 bits allowed (don't check colorspace) 

		static UInt32 TYPE_NAMED_COLOR_INDEX					= (CHANNELS_SH(1)|BYTES_SH(2));

		// Double values. Painful slow, but sometimes helpful. NOTE THAT 'BYTES' FIELD IS SET TO ZERO!

		static UInt32 TYPE_XYZ_DBL        						= (COLORSPACE_SH(lcmsPixelType::XYZ)|CHANNELS_SH(3)|BYTES_SH(0));
		static UInt32 TYPE_Lab_DBL        						= (COLORSPACE_SH(lcmsPixelType::Lab)|CHANNELS_SH(3)|BYTES_SH(0));
		static UInt32 TYPE_GRAY_DBL       						= (COLORSPACE_SH(lcmsPixelType::GRAY)|CHANNELS_SH(1)|BYTES_SH(0));
		static UInt32 TYPE_RGB_DBL        						= (COLORSPACE_SH(lcmsPixelType::RGB)|CHANNELS_SH(3)|BYTES_SH(0));
		static UInt32 TYPE_CMYK_DBL       						= (COLORSPACE_SH(lcmsPixelType::CMYK)|CHANNELS_SH(4)|BYTES_SH(0));



	//VIEWING CONDITIONS
		static Int32 AVG_SURROUND_4     						= 0;
		static Int32 AVG_SURROUND       						= 1;
		static Int32 DIM_SURROUND       						= 2;
		static Int32 DARK_SURROUND      						= 3;
		static Int32 CUTSHEET_SURROUND  						= 4;

		static Int32 D_CALCULATE             					= (-1);
		static Int32 D_CALCULATE_DISCOUNT    					= (-2);


	// Added by lcms
        static UInt32 lcmsSignature								= 0x6c636d73;
        //static UInt32 icSigLuvKData								= 0x4C75764B;	// 'LuvK'
        static UInt32 icSigChromaticityTag						= 0x6368726d;	// As per Addendum 2 to Spec. ICC.1:1998-09
        static UInt32 icSigChromaticAdaptationTag				= 0x63686164;

		/*static Int32 lcmsParametricCurveExp						= 0;
        static Int32 lcmsParametricCurveCIE_122_1966			= 1;
        static Int32 lcmsParametricCurveIEC_61966_3				= 2;
        static Int32 lcmsParametricCurveIEC_61966_2_1			= 3;*/

     // Error handling
        static Int32 LCMS_ERROR_ABORT							= 0;
        static Int32 LCMS_ERROR_SHOW							= 1;
        static Int32 LCMS_ERROR_IGNORE							= 2;
	};
}