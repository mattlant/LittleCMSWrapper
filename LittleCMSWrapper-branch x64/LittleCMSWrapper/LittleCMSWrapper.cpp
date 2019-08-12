// This is the main DLL file.

#include "stdafx.h"

//using namespace System::Runtime::InteropServices;

namespace LittleCMSWrapper 
{
	lcmsICColorSpaceSignature lcmsWrapper::ICCcolorSpace(lcmsPixelType ourNotation)
	{
		return (lcmsICColorSpaceSignature)_cmsICCcolorSpace((Int32)ourNotation);
	}
}
