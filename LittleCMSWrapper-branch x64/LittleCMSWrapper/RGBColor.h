#pragma once  
#pragma managed
#include <vcclr.h>

using namespace System;
using namespace System::Drawing;

namespace LittleCMSWrapper 
{
	public ref class lcmsRGBColor  : LittleCMSWrapperBase
	{
	public:
		double R;
		double G;
		double B;
		lcmsRGBColor() : R(0),G(0),B(0) {}
		lcmsRGBColor(double _R,double _G, double _B) : R(_R),G(_G),B(_B) {}
		lcmsRGBColor(Color^ color) 
		{
			R = Convert::ToDouble(color->R);
			G = Convert::ToDouble(color->G); 
			B = Convert::ToDouble(color->B);
		}
		void FromColor(lcmsRGBColor^ color)
		{
			R = color->R;
			G = color->G;
			B = color->B;
		}
		Color ToColor() { return Color::FromArgb(Convert::ToInt32(R),Convert::ToInt32(G),Convert::ToInt32(B)); }

		String^ ToString(String^ sFormat, char cDivider) {return R.ToString(sFormat) + cDivider + G.ToString(sFormat) + cDivider + B.ToString(sFormat);}
		String^ ToString(String^ sFormat) {return ToString(sFormat,' ');}
		virtual String^ ToString()override {return ToString("",' ');}
	};
}