#pragma managed
#include "Stdafx.h"

namespace LittleCMSWrapper
{
	lcmsCIExyY^ lcmsCIEXYZ::ToxyY()
	{
		cmsCIEXYZ tempXYZ = this->ToCIEXYZ();
		cmsCIExyY tempxyY;

		cmsXYZ2xyY(&tempxyY,&tempXYZ); //Conversion

		return gcnew lcmsCIExyY(&tempxyY);
	}

	void lcmsCIEXYZ::FromxyY(lcmsCIExyY^ txyY)
	{
		cmsCIEXYZ tempXYZ = this->ToCIEXYZ();
		cmsCIExyY tempxyY = txyY->ToCIExyY();

		cmsxyY2XYZ(&tempXYZ, &tempxyY); //Conversion

		this->FromCIEXYZ(&tempXYZ);
	}

	lcmsCIELab^ lcmsCIEXYZ::ToLab(lcmsWhitePoint^ whitePoint)
	{
		cmsCIELab tempLab;
		cmsCIEXYZ tempXYZ = this->ToCIEXYZ();

		cmsXYZ2Lab(((whitePoint != nullptr) ? &whitePoint->WhitePointXYZ->ToCIEXYZ() : NULL),&tempLab,&tempXYZ);   //Conversion

		return gcnew lcmsCIELab(&tempLab);		
	}

	void lcmsCIEXYZ::FromLab(lcmsWhitePoint^ whitePoint, lcmsCIELab^ tLab)
	{
		cmsCIELab tempLab = tLab->ToCIELab();
		cmsCIEXYZ tempXYZ = this->ToCIEXYZ();

		cmsLab2XYZ(((whitePoint != nullptr) ? &whitePoint->WhitePointXYZ->ToCIEXYZ() : NULL),&tempXYZ,&tempLab);   //Conversion

		this->FromCIEXYZ(&tempXYZ);
	}

	lcmsCIELCh^ lcmsCIEXYZ::ToLCh(lcmsWhitePoint^ whitePoint)
	{
		return ToLab(whitePoint)->ToLCh();
	}

	void lcmsCIEXYZ::FromLCh(lcmsWhitePoint^ whitePoint, lcmsCIELCh^ tLCh)
	{
		FromLab(whitePoint,tLCh->ToLab());
	}
}