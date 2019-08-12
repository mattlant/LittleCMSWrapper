#pragma once  
#pragma managed
#include <vcclr.h>


namespace LittleCMSWrapper 
{
	public ref class lcmsCIExyY	: LittleCMSWrapperBase
    {
	internal:
		void FromCIExyY(cmsCIExyY* temp) {x = temp->x; y = temp->y; Y = temp->Y;}
		cmsCIExyY ToCIExyY() {cmsCIExyY temp = {x,y,Y}; return temp;}
		lcmsCIExyY(cmsCIExyY* temp) {FromCIExyY(temp);}
	public:
		double x;
        double y;
        double Y;
		lcmsCIExyY() : x(0),y(0),Y(0) {}
		lcmsCIExyY(double _x, double _y, double _Y) : x(_x),y(_y),Y(_Y) {}

		lcmsCIEXYZ^ ToXYZ();
		void FromXYZ(lcmsCIEXYZ^ tXYZ);

		lcmsCIELab^ ToLab(lcmsWhitePoint^ whitePoint);
		lcmsCIELab^ ToLab() {return ToLab(nullptr);}
		void FromLab(lcmsWhitePoint^ whitePoint, lcmsCIELab^ tLab);
		void FromLab(lcmsCIELab^ tLab) {FromLab(nullptr,tLab);}

		lcmsCIELCh^ ToLCh(lcmsWhitePoint^ whitePoint);
		lcmsCIELCh^ ToLCh() {return ToLCh(nullptr);}
		void FromLCh(lcmsWhitePoint^ whitePoint, lcmsCIELCh^ tLCh);
		void FromLCh(lcmsCIELCh^ tLCh) {FromLCh(nullptr,tLCh);}

		String^ ToString(String^ sFormat, char cDivider) {return x.ToString(sFormat) + cDivider + y.ToString(sFormat) + cDivider + Y.ToString(sFormat);}
		String^ ToString(String^ sFormat) {return ToString(sFormat,' ');}
		virtual String^ ToString()override {return ToString("",' ');}
    };
}