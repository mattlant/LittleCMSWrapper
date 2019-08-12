// LittleCMSWrapper.h

#pragma once  
#pragma managed
#include <vcclr.h>


//using namespace System;
//using namespace System::Collections::Generic;


namespace LittleCMSWrapper {
	
	// for now here goes all the general functio till I figure it out where to put them 

	public ref class lcmsWrapper  : LittleCMSWrapperBase
	{
	public:
		static lcmsICColorSpaceSignature	ICCcolorSpace(lcmsPixelType ourNotation);
	};
}
