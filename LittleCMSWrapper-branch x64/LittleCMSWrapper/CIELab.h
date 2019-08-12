#pragma once  
#pragma managed
#include <vcclr.h>

using namespace System;

namespace LittleCMSWrapper 
{
	public ref class lcmsCIELab : LittleCMSWrapperBase
	{
	internal:
		cmsCIELab ToCIELab() {cmsCIELab temp = {L,a,b}; return temp;}
		void FromCIELab(cmsCIELab* temp) {L = temp->L; a = temp->a; b=temp->b;}
		lcmsCIELab (cmsCIELab* temp) {FromCIELab(temp);}
	public:           
		double L;
		double a;               
		double b;
		lcmsCIELab() : L(0),a(0),b(0) {}
		lcmsCIELab(double _L, double _a, double _b) : L(_L),a(_a),b(_b) {}

		lcmsCIELCh^ ToLCh();
		void FromLCh(lcmsCIELCh^ tLCh);

		lcmsCIEXYZ^ ToXYZ(lcmsWhitePoint^ whitePoint);
		lcmsCIEXYZ^ ToXYZ() {return ToXYZ(nullptr);}
		void FromXYZ(lcmsWhitePoint^ whitePoint, lcmsCIEXYZ^ tXYZ);
		void FromXYZ(lcmsCIEXYZ^ tXYZ) {FromXYZ(nullptr, tXYZ);}

		lcmsCIExyY^ ToxyY(lcmsWhitePoint^ whitePoint);
		lcmsCIExyY^ ToxyY() {return ToxyY(nullptr);}
		void FromxyY(lcmsWhitePoint^ whitePoint, lcmsCIExyY^ txyY);
		void FromxyY(lcmsCIExyY^ txyY) {FromxyY(nullptr, txyY);}

		double DeltaE(lcmsCIELab^ lab2) {return cmsDeltaE(&this->ToCIELab(),&lab2->ToCIELab());}
		double DeltaECIE94(lcmsCIELab^ lab2) {return cmsCIE94DeltaE(&this->ToCIELab(),&lab2->ToCIELab());}
		double DeltaEBFD(lcmsCIELab^ lab2) {return cmsBFDdeltaE(&this->ToCIELab(),&lab2->ToCIELab());}
		double DeltaECMC(lcmsCIELab^ lab2) {return cmsCMCdeltaE(&this->ToCIELab(),&lab2->ToCIELab());}
		double DeltaECIE2000(lcmsCIELab^ lab2, double kL, double kC, double kH) {return cmsCIE2000DeltaE(&this->ToCIELab(),&lab2->ToCIELab(),kL,kC,kH);}

		String^ ToString(String^ sFormat, char cDivider) {return L.ToString(sFormat) + cDivider + a.ToString(sFormat) + cDivider + b.ToString(sFormat);}
		String^ ToString(String^ sFormat) {return ToString(sFormat,' ');}
		virtual String^ ToString()override {return ToString("",' ');}
	};
}