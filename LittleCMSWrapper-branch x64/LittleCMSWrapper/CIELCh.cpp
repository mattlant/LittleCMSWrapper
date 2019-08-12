#pragma managed
#include "Stdafx.h"

namespace LittleCMSWrapper
{
	lcmsCIELab^ lcmsCIELCh::ToLab()
	{
		cmsCIELab tempLab;
		cmsCIELCh tempLCh = this->ToCIELCh();

		cmsLCh2Lab(&tempLab, &tempLCh);

		return gcnew lcmsCIELab(&tempLab);
	}

	void lcmsCIELCh::FromLab(lcmsCIELab^ tLab)
	{
		cmsCIELab tempLab = tLab->ToCIELab();
		cmsCIELCh tempLCh = this->ToCIELCh();

		cmsLab2LCh(&tempLCh,&tempLab);

		this->FromCIELCh(&tempLCh);
	}

	lcmsCIEXYZ^ lcmsCIELCh::ToXYZ(lcmsWhitePoint^ whitePoint)
	{
		return ToLab()->ToXYZ(whitePoint);
	}

	void lcmsCIELCh::FromXYZ(lcmsWhitePoint^ whitePoint, lcmsCIEXYZ^ tXYZ)
	{
		FromLab(tXYZ->ToLab(whitePoint));
	}


	lcmsCIExyY^ lcmsCIELCh::ToxyY(lcmsWhitePoint^ whitePoint)
	{
		return ToXYZ(whitePoint)->ToxyY();
	}

	void lcmsCIELCh::FromxyY(lcmsWhitePoint^ whitePoint, lcmsCIExyY^ txyY)
	{
		FromLab(txyY->ToLab(whitePoint));
	}

}