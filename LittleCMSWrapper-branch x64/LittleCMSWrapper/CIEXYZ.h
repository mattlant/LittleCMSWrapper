#pragma once  
#pragma managed
#include <vcclr.h>


namespace LittleCMSWrapper 
{
	public ref class lcmsCIEXYZ	 : LittleCMSWrapperBase
	{
	internal:
		void FromCIEXYZ(cmsCIEXYZ* temp) {X=temp->X; Y=temp->Y; Z=temp->Z;}
		cmsCIEXYZ ToCIEXYZ() {cmsCIEXYZ temp = {X,Y,Z}; return temp;}
		lcmsCIEXYZ(cmsCIEXYZ* temp) {FromCIEXYZ(temp);}
	public:
		double X;
		double Y;
		double Z;
		lcmsCIEXYZ() : X(0),Y(0),Z(0) {}
		lcmsCIEXYZ(double _X, double _Y, double _Z) : X(_X),Y(_Y),Z(_Z) {}

		lcmsCIExyY^ ToxyY();
		void FromxyY(lcmsCIExyY^ txyY);

		lcmsCIELab^ ToLab(lcmsWhitePoint^ whitePoint);
		lcmsCIELab^ ToLab() {return ToLab(nullptr);}
		void FromLab(lcmsWhitePoint^ whitePoint, lcmsCIELab^ tLab);
		void FromLab(lcmsCIELab^ tLab) {FromLab(nullptr,tLab);}

		lcmsCIELCh^ ToLCh(lcmsWhitePoint^ whitePoint);
		lcmsCIELCh^ ToLCh() {return ToLCh(nullptr);}
		void FromLCh(lcmsWhitePoint^ whitePoint, lcmsCIELCh^ tLCh);
		void FromLCh(lcmsCIELCh^ tLCh) {FromLCh(nullptr,tLCh);}

		String^ ToString(String^ sFormat, char cDivider) {return X.ToString(sFormat) + cDivider + Y.ToString(sFormat) + cDivider + Z.ToString(sFormat);}
		String^ ToString(String^ sFormat) {return ToString(sFormat,' ');}
		virtual String^ ToString()override {return ToString("",' ');}
	};
}