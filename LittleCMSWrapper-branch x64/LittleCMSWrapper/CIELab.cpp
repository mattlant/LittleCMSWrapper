#pragma managed
#include "Stdafx.h"

namespace LittleCMSWrapper
{
	lcmsCIELCh^ lcmsCIELab::ToLCh()
	{
		cmsCIELab tempLab = this->ToCIELab();
		cmsCIELCh tempLCh;

		cmsLab2LCh(&tempLCh,&tempLab);

		return gcnew lcmsCIELCh(&tempLCh);
	}

	void lcmsCIELab::FromLCh(lcmsCIELCh^ tLCh)
	{
		cmsCIELab tempLab = this->ToCIELab();
		cmsCIELCh tempLCh = tLCh->ToCIELCh();

		cmsLCh2Lab(&tempLab, &tempLCh);

		this->FromCIELab(&tempLab);
	}

	lcmsCIEXYZ^ lcmsCIELab::ToXYZ(lcmsWhitePoint^ whitePoint)
	{
		cmsCIELab tempLab = this->ToCIELab();
		cmsCIEXYZ tempXYZ;
		
		cmsLab2XYZ(((whitePoint != nullptr) ? &whitePoint->WhitePointXYZ->ToCIEXYZ() : NULL),&tempXYZ,&tempLab);   //Conversion

		return gcnew lcmsCIEXYZ(&tempXYZ);
	}

	void lcmsCIELab::FromXYZ(lcmsWhitePoint^ whitePoint, lcmsCIEXYZ^ tXYZ)
	{
		cmsCIELab tempLab = this->ToCIELab();
		cmsCIEXYZ tempXYZ = tXYZ->ToCIEXYZ();

		cmsXYZ2Lab(((whitePoint != nullptr) ? &whitePoint->WhitePointXYZ->ToCIEXYZ() : NULL),&tempLab,&tempXYZ);   //Conversion
		
		
		this->FromCIELab(&tempLab);
	}

	lcmsCIExyY^ lcmsCIELab::ToxyY(lcmsWhitePoint^ whitePoint)
	{
		return ToXYZ(whitePoint)->ToxyY();
	}

	void lcmsCIELab::FromxyY(lcmsWhitePoint^ whitePoint, lcmsCIExyY^ txyY)
	{
		FromXYZ(whitePoint,txyY->ToXYZ());
	}
}