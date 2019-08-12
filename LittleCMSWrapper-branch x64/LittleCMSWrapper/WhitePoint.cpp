#pragma managed
#include "Stdafx.h"

namespace LittleCMSWrapper
{
	lcmsWhitePoint::lcmsWhitePoint(cmsCIExyY* txyY) 
	{
		_WhitePoint = gcnew lcmsCIExyY(txyY); 
		_WhitePointXYZ = _WhitePoint->ToXYZ();
	}
		
	lcmsWhitePoint::lcmsWhitePoint(cmsCIEXYZ* tXYZ) 
	{
		_WhitePointXYZ = gcnew lcmsCIEXYZ(tXYZ); 
		_WhitePoint = _WhitePointXYZ->ToxyY();
	}

	lcmsWhitePoint^ lcmsWhitePoint::FromTemp(Int32 tempK)
	{
		cmsCIExyY whitePoint;

		if((cmsWhitePointFromTemp(tempK,&whitePoint) == 1)) return gcnew lcmsWhitePoint(&whitePoint);
		
		return nullptr;
	}

	lcmsWhitePoint^ lcmsWhitePoint::ICC_D50()
	{
		lcmsWhitePoint^ temp = gcnew lcmsWhitePoint();
		temp->_WhitePoint = gcnew lcmsCIExyY(cmsD50_xyY());
		temp->_WhitePointXYZ = gcnew lcmsCIEXYZ(cmsD50_XYZ());
		return temp;
	}
}