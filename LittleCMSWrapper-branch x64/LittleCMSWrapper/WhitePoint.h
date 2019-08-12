#pragma once  
#pragma managed
#include <vcclr.h>

using namespace System;

namespace LittleCMSWrapper 
{
	public ref class lcmsWhitePoint	 : LittleCMSWrapperBase
	{
	internal:
		lcmsWhitePoint(cmsCIExyY* txyY); 
		lcmsWhitePoint(cmsCIEXYZ* tXYZ);  
	
	private:
		lcmsCIExyY^ _WhitePoint;
		lcmsCIEXYZ^ _WhitePointXYZ;

	protected:
		lcmsWhitePoint() : _WhitePoint(nullptr),_WhitePointXYZ(nullptr) {}
	
	public:
		lcmsWhitePoint(lcmsCIExyY^ wP) : _WhitePoint(wP), _WhitePointXYZ(nullptr){}
		lcmsWhitePoint(lcmsCIEXYZ^ wP) : _WhitePointXYZ(wP), _WhitePoint(nullptr){}

		static lcmsWhitePoint^ FromTemp(Int32 tempK);
		static lcmsWhitePoint^ ICC_D50();   //Following ICC

		property lcmsCIExyY^ WhitePoint
		{
			lcmsCIExyY^ get()
			{
				if(_WhitePoint == nullptr && _WhitePointXYZ != nullptr) _WhitePoint = _WhitePointXYZ->ToxyY();
				return _WhitePoint;
			}
		}

		property lcmsCIEXYZ^ WhitePointXYZ
		{
			lcmsCIEXYZ^ get()
			{
				if(_WhitePointXYZ == nullptr && _WhitePoint != nullptr) _WhitePointXYZ = _WhitePoint->ToXYZ();
				return _WhitePointXYZ;
			}
		}
	};
}