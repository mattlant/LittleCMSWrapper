========================================================================
    DYNAMIC LINK LIBRARY : LittleCMSWrapper Project Overview
========================================================================

AppWizard has created this LittleCMSWrapper DLL for you.  

This file contains a summary of what you will find in each of the files that
make up your LittleCMSWrapper application.

LittleCMSWrapper.vcproj
    This is the main project file for VC++ projects generated using an Application Wizard. 
    It contains information about the version of Visual C++ that generated the file, and 
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

LittleCMSWrapper.cpp
    This is the main DLL source file.

LittleCMSWrapper.h
    This file contains a class declaration.

AssemblyInfo.cpp
	Contains custom attributes for modifying assembly metadata.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

Functions to implent:


		//CIELab Handling

		static double 						DeltaE(lcmsCIELab^ lab1,lcmsCIELab^ lab2);
		static double 						CIE94DeltaE(lcmsCIELab^ lab1,lcmsCIELab^ lab2);
		static double 						BFDDeltaE(lcmsCIELab^ lab1,lcmsCIELab^ lab2);
		static double 						CMCDeltaE(lcmsCIELab^ lab1,lcmsCIELab^ lab2);
		static double 						CIE2000DeltaE(lcmsCIELab^ lab1,lcmsCIELab^ lab2,double kL,double kC,double kH);

		static lcmsCIExyY^					WhitePointFromTemp(Int32 tempK);

		//LCMSAPI void          LCMSEXPORT cmsClampLab(LPcmsCIELab Lab, double amax, double amin, double bmax, double bmin);
		//
		//LCMSAPI LCMSBOOL      LCMSEXPORT cmsAdaptToIlluminant(LPcmsCIEXYZ Result,
		//                                                        LPcmsCIEXYZ SourceWhitePt,
		//                                                        LPcmsCIEXYZ Illuminant,
		//                                                        LPcmsCIEXYZ Value);
		//
		//LCMSAPI LCMSBOOL      LCMSEXPORT cmsBuildRGB2XYZtransferMatrix(LPMAT3 r,
		//                                                        LPcmsCIExyY WhitePoint,
		//                                                        LPcmsCIExyYTRIPLE Primaries);
		
//-------------------------------------------------------------------------------------------------------------------------------------------------------

		// CIECAM97s

		//LCMSAPI LCMSHANDLE    LCMSEXPORT cmsCIECAM97sInit(LPcmsViewingConditions pVC2);
		//LCMSAPI void          LCMSEXPORT cmsCIECAM97sDone(LCMSHANDLE hModel);
		//LCMSAPI void          LCMSEXPORT cmsCIECAM97sForward(LCMSHANDLE hModel, LPcmsCIEXYZ pIn, LPcmsJCh pOut);
		//LCMSAPI void          LCMSEXPORT cmsCIECAM97sReverse(LCMSHANDLE hModel, LPcmsJCh pIn,    LPcmsCIEXYZ pOut);

//-------------------------------------------------------------------------------------------------------------------------------------------------------

		// CIECAM02

		//LCMSAPI LCMSHANDLE    LCMSEXPORT cmsCIECAM02Init(LPcmsViewingConditions pVC);
		//LCMSAPI void          LCMSEXPORT cmsCIECAM02Done(LCMSHANDLE hModel);
		//LCMSAPI void          LCMSEXPORT cmsCIECAM02Forward(LCMSHANDLE hModel, LPcmsCIEXYZ pIn, LPcmsJCh pOut);
		//LCMSAPI void          LCMSEXPORT cmsCIECAM02Reverse(LCMSHANDLE hModel, LPcmsJCh pIn,    LPcmsCIEXYZ pOut);

//-------------------------------------------------------------------------------------------------------------------------------------------------------

		// Gamma

		//LCMSAPI LPGAMMATABLE  LCMSEXPORT cmsBuildGamma(int nEntries, double Gamma);
		//LCMSAPI LPGAMMATABLE  LCMSEXPORT cmsBuildParametricGamma(int nEntries, int Type, double Params[]);
		//LCMSAPI LPGAMMATABLE  LCMSEXPORT cmsAllocGamma(int nEntries);
		//LCMSAPI void          LCMSEXPORT cmsFreeGamma(LPGAMMATABLE Gamma);
		//LCMSAPI void          LCMSEXPORT cmsFreeGammaTriple(LPGAMMATABLE Gamma[3]);
		//LCMSAPI LPGAMMATABLE  LCMSEXPORT cmsDupGamma(LPGAMMATABLE Src);
		//LCMSAPI LPGAMMATABLE  LCMSEXPORT cmsReverseGamma(int nResultSamples, LPGAMMATABLE InGamma);
		//LCMSAPI LPGAMMATABLE  LCMSEXPORT cmsJoinGamma(LPGAMMATABLE InGamma,  LPGAMMATABLE OutGamma);
		//LCMSAPI LPGAMMATABLE  LCMSEXPORT cmsJoinGammaEx(LPGAMMATABLE InGamma,  LPGAMMATABLE OutGamma, int nPoints);
		//LCMSAPI LCMSBOOL      LCMSEXPORT cmsSmoothGamma(LPGAMMATABLE Tab, double lambda);
		//LCMSAPI double        LCMSEXPORT cmsEstimateGamma(LPGAMMATABLE t);
		//LCMSAPI double        LCMSEXPORT cmsEstimateGammaEx(LPWORD Table, int nEntries, double Thereshold); 
		//LCMSAPI LPGAMMATABLE  LCMSEXPORT cmsReadICCGamma(cmsHPROFILE hProfile, icTagSignature sig);
		//LCMSAPI LPGAMMATABLE  LCMSEXPORT cmsReadICCGammaReversed(cmsHPROFILE hProfile, icTagSignature sig);		

//-------------------------------------------------------------------------------------------------------------------------------------------------------

		// Translate form/to our notation to ICC 

		static lcmsICColorSpaceSignature	ICCcolorSpace(lcmsPixelType ourNotation);
		//LCMSAPI int                   LCMSEXPORT _cmsLCMScolorSpace(icColorSpaceSignature ProfileSpace);
		//LCMSAPI int                   LCMSEXPORT _cmsChannelsOf(icColorSpaceSignature ColorSpace);
		//LCMSAPI LCMSBOOL              LCMSEXPORT _cmsIsMatrixShaper(cmsHPROFILE hProfile);
		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		//// Named color support
		//
		//LCMSAPI int      LCMSEXPORT cmsNamedColorCount(cmsHTRANSFORM xform);
		//LCMSAPI LCMSBOOL LCMSEXPORT cmsNamedColorInfo(cmsHTRANSFORM xform, int nColor, char* Name, char* Prefix, char* Suffix);
		//LCMSAPI int      LCMSEXPORT cmsNamedColorIndex(cmsHTRANSFORM xform, const char* Name);
		//
		//// Colorant tables
		//
		//LCMSAPI LPcmsNAMEDCOLORLIST LCMSEXPORT cmsReadColorantTable(cmsHPROFILE hProfile, icTagSignature sig);
		//
		//// Profile creation 
		//
		//LCMSAPI LCMSBOOL LCMSEXPORT cmsAddTag(cmsHPROFILE hProfile, icTagSignature sig, const void* data);
		//
		//
		//// Set the 'save as 8-bit' flag
		//LCMSAPI void LCMSEXPORT _cmsSetLUTdepth(cmsHPROFILE hProfile, int depth);
		//
		//		
		
		
		
	
		//
		//// PostScript ColorRenderingDictionary and ColorSpaceArray
		//
		//LCMSAPI DWORD LCMSEXPORT cmsGetPostScriptCSA(cmsHPROFILE hProfile, int Intent, LPVOID Buffer, DWORD dwBufferLen);
		//LCMSAPI DWORD LCMSEXPORT cmsGetPostScriptCRD(cmsHPROFILE hProfile, int Intent, LPVOID Buffer, DWORD dwBufferLen);
		//LCMSAPI DWORD LCMSEXPORT cmsGetPostScriptCRDEx(cmsHPROFILE hProfile, int Intent, DWORD dwFlags, LPVOID Buffer, DWORD dwBufferLen);

		// Error handling
		//
		//LCMSAPI int LCMSEXPORT cmsErrorAction(int nAction);
		//
		//
		//LCMSAPI void LCMSEXPORT cmsSetErrorHandler(cmsErrorHandlerFunction Fn);
		//
		//// LUT manipulation
		//
		//
		//LCMSAPI LPLUT  LCMSEXPORT cmsAllocLUT(void);
		//LCMSAPI LPLUT  LCMSEXPORT cmsAllocLinearTable(LPLUT NewLUT, LPGAMMATABLE Tables[], int nTable);
		//LCMSAPI LPLUT  LCMSEXPORT cmsAlloc3DGrid(LPLUT Lut, int clutPoints, int inputChan, int outputChan);
		//LCMSAPI LPLUT  LCMSEXPORT cmsSetMatrixLUT(LPLUT Lut, LPMAT3 M);
		//LCMSAPI LPLUT  LCMSEXPORT cmsSetMatrixLUT4(LPLUT Lut, LPMAT3 M, LPVEC3 off, DWORD dwFlags);
		//LCMSAPI void   LCMSEXPORT cmsFreeLUT(LPLUT Lut);
		//LCMSAPI void   LCMSEXPORT cmsEvalLUT(LPLUT Lut, WORD In[], WORD Out[]);
		//LCMSAPI double LCMSEXPORT cmsEvalLUTreverse(LPLUT Lut, WORD Target[], WORD Result[], LPWORD Hint);
		//LCMSAPI LPLUT  LCMSEXPORT cmsReadICCLut(cmsHPROFILE hProfile, icTagSignature sig);
		//LCMSAPI LPLUT  LCMSEXPORT cmsDupLUT(LPLUT Orig);
		//
		//
		//// LUT Sampling
		//
		//LCMSAPI int LCMSEXPORT cmsSample3DGrid(LPLUT Lut, _cmsSAMPLER Sampler, LPVOID Cargo, DWORD dwFlags);
		//
		//// Formatters
		//
		//LCMSAPI void LCMSEXPORT cmsSetUserFormatters(cmsHTRANSFORM hTransform, DWORD dwInput,  cmsFORMATTER Input,
		//                                                               DWORD dwOutput, cmsFORMATTER Output);
		//
		//LCMSAPI void LCMSEXPORT cmsGetUserFormatters(cmsHTRANSFORM hTransform, 
		//                                                               LPDWORD InputFormat, cmsFORMATTER* Input, 
		//                                                               LPDWORD OutputFormat, cmsFORMATTER* Output);
		//
		//// IT8.7 / CGATS.17-200x handling
		//
		//LCMSAPI LCMSHANDLE      LCMSEXPORT cmsIT8Alloc(void);
		//LCMSAPI void            LCMSEXPORT cmsIT8Free(LCMSHANDLE IT8);
		//
		//// Tables
		//
		//LCMSAPI int             LCMSEXPORT cmsIT8TableCount(LCMSHANDLE IT8);
		//LCMSAPI int             LCMSEXPORT cmsIT8SetTable(LCMSHANDLE IT8, int nTable);
		//
		//// Persistence
		//LCMSAPI LCMSHANDLE      LCMSEXPORT cmsIT8LoadFromFile(const char* cFileName);
		//LCMSAPI LCMSHANDLE      LCMSEXPORT cmsIT8LoadFromMem(void *Ptr, size_t len);
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SaveToFile(LCMSHANDLE IT8, const char* cFileName);
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SaveToMem(LCMSHANDLE hIT8, void *MemPtr, size_t* BytesNeeded);
		//
		//// Properties
		//LCMSAPI const char*     LCMSEXPORT cmsIT8GetSheetType(LCMSHANDLE hIT8);
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetSheetType(LCMSHANDLE hIT8, const char* Type);
		//
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetComment(LCMSHANDLE hIT8, const char* cComment);
		//
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetPropertyStr(LCMSHANDLE hIT8, const char* cProp, const char *Str);
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetPropertyDbl(LCMSHANDLE hIT8, const char* cProp, double Val);
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetPropertyHex(LCMSHANDLE hIT8, const char* cProp, int Val);
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetPropertyUncooked(LCMSHANDLE hIT8, const char* Key, const char* Buffer);
		//
		//
		//LCMSAPI const char*     LCMSEXPORT cmsIT8GetProperty(LCMSHANDLE hIT8, const char* cProp);
		//LCMSAPI double          LCMSEXPORT cmsIT8GetPropertyDbl(LCMSHANDLE hIT8, const char* cProp);
		//LCMSAPI int             LCMSEXPORT cmsIT8EnumProperties(LCMSHANDLE hIT8, const char ***PropertyNames);
		//
		//// Datasets
		//
		//LCMSAPI const char*     LCMSEXPORT cmsIT8GetDataRowCol(LCMSHANDLE IT8, int row, int col);                                                
		//LCMSAPI double          LCMSEXPORT cmsIT8GetDataRowColDbl(LCMSHANDLE IT8, int row, int col);
		//
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetDataRowCol(LCMSHANDLE hIT8, int row, int col, 
		//                                                const char* Val);
		//
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetDataRowColDbl(LCMSHANDLE hIT8, int row, int col, 
		//                                                double Val);
		//
		//LCMSAPI const char*     LCMSEXPORT cmsIT8GetData(LCMSHANDLE IT8, const char* cPatch, const char* cSample);                                                
		//
		//
		//LCMSAPI double          LCMSEXPORT cmsIT8GetDataDbl(LCMSHANDLE IT8, const char* cPatch, const char* cSample);
		//
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetData(LCMSHANDLE IT8, const char* cPatch,
		//                                                const char* cSample,
		//                                                const char *Val);
		//
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetDataDbl(LCMSHANDLE hIT8, const char* cPatch,
		//                                                const char* cSample,
		//                                                double Val);
		//
		//LCMSAPI int             LCMSEXPORT cmsIT8GetDataFormat(LCMSHANDLE hIT8, const char* cSample);
		//LCMSAPI LCMSBOOL        LCMSEXPORT cmsIT8SetDataFormat(LCMSHANDLE IT8, int n, const char *Sample);
		//LCMSAPI int             LCMSEXPORT cmsIT8EnumDataFormat(LCMSHANDLE IT8, char ***SampleNames);
		//
		//
		//LCMSAPI const char*     LCMSEXPORT cmsIT8GetPatchName(LCMSHANDLE hIT8, int nPatch, char* buffer);
		//
		//// The LABEL extension
		//
		//LCMSAPI int             LCMSEXPORT cmsIT8SetTableByLabel(LCMSHANDLE hIT8, const char* cSet, const char* cField, const char* ExpectedType);
		//
		//
		//// Formatter for double
		//LCMSAPI void            LCMSEXPORT cmsIT8DefineDblFormat(LCMSHANDLE IT8, const char* Formatter);

		