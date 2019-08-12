#pragma once
#pragma managed

namespace LittleCMSWrapper
{
	public enum class lcmsPixelType : Int32 {
		// PIXEL TYPES
		ANY										= 0,    // Don't check colorspace
						    							// 1 & 2 are reserved
		GRAY									= 3,
		RGB										= 4,
		CMY										= 5,
		CMYK									= 6,
		YCbCr									= 7,
		YUV										= 8,      // Lu'v'
		XYZ										= 9,
		Lab										= 10,
		YUVK									= 11,     // Lu'v'K
		HSV										= 12,
		HLS										= 13,
		Yxy										= 14,
		HiFi									= 15,
		HiFi7									= 16,
		HiFi8									= 17,
		HiFi9									= 18,
		HiFi10									= 19,
		HiFi11									= 20,
		HiFi12									= 21,
		HiFi13									= 22,
		HiFi14									= 23,
		HiFi15									= 24,
	};
}