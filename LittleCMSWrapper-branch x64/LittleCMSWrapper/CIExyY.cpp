#pragma managed
#include "Stdafx.h"

namespace LittleCMSWrapper
{
	lcmsCIEXYZ^ lcmsCIExyY::ToXYZ()
	{
		cmsCIEXYZ tempXYZ;
		cmsCIExyY tempxyY = this->ToCIExyY();

		cmsxyY2XYZ(&tempXYZ, &tempxyY); //Conversion

		return gcnew lcmsCIEXYZ(&tempXYZ);
	}

	void lcmsCIExyY::FromXYZ(lcmsCIEXYZ^ tXYZ)
	{
		cmsCIEXYZ tempXYZ = tXYZ->ToCIEXYZ();
		cmsCIExyY tempxyY = this->ToCIExyY();

		cmsXYZ2xyY(&tempxyY,&tempXYZ); //Conversion

		this->FromCIExyY(&tempxyY);
	}

	lcmsCIELab^ lcmsCIExyY::ToLab(lcmsWhitePoint^ whitePoint)
	{
		return ToXYZ()->ToLab(whitePoint);
	}	
		
	void lcmsCIExyY::FromLab(lcmsWhitePoint^ whitePoint, lcmsCIELab^ tLab)
	{
		FromXYZ(tLab->ToXYZ(whitePoint));
	}

	lcmsCIELCh^ lcmsCIExyY::ToLCh(lcmsWhitePoint^ whitePoint)
	{
		return ToLab(whitePoint)->ToLCh();
	}	

	void lcmsCIExyY::FromLCh(lcmsWhitePoint^ whitePoint, lcmsCIELCh^ tLCh)
	{
		FromXYZ(tLCh->ToLab()->ToXYZ(whitePoint));
	}
}