#pragma once  
#pragma managed
#include <vcclr.h>

namespace LittleCMSWrapper 
{
	public ref class lcmsCIELCh : LittleCMSWrapperBase
	{
	internal:
		cmsCIELCh ToCIELCh() {cmsCIELCh temp = {L,C,h}; return temp;}
		void FromCIELCh(cmsCIELCh* temp) {L = temp->L; C = temp->C; h=temp->h;}
		lcmsCIELCh(cmsCIELCh* temp) {FromCIELCh(temp);}
	public:           
        double L;
        double C;               
        double h;
		lcmsCIELCh() : L(0),C(0),h(0) {}
		lcmsCIELCh(double _L, double _C, double _h) : L(_L),C(_C),h(_h) {}

		lcmsCIELab^ ToLab();
		void FromLab(lcmsCIELab^ tLab);

		lcmsCIEXYZ^ ToXYZ(lcmsWhitePoint^ whitePoint);
		lcmsCIEXYZ^ ToXYZ() {return ToXYZ(nullptr);}
		void FromXYZ(lcmsWhitePoint^ whitePoint, lcmsCIEXYZ^ tXYZ);
		void FromXYZ(lcmsCIEXYZ^ tXYZ) {FromXYZ(nullptr, tXYZ);}

		lcmsCIExyY^ ToxyY(lcmsWhitePoint^ whitePoint);
		lcmsCIExyY^ ToxyY() {return ToxyY(nullptr);}
		void FromxyY(lcmsWhitePoint^ whitePoint, lcmsCIExyY^ txyY);
		void FromxyY(lcmsCIExyY^ txyY) {FromxyY(nullptr, txyY);}

		String^ ToString(String^ sFormat, char cDivider) {return L.ToString(sFormat) + cDivider + C.ToString(sFormat) + cDivider + h.ToString(sFormat);}
		String^ ToString(String^ sFormat) {return ToString(sFormat,' ');}
		virtual String^ ToString()override {return ToString("",' ');}
    };
}