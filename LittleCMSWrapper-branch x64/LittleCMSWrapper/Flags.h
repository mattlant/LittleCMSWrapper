#pragma once
#pragma managed

using namespace System;

namespace LittleCMSWrapper
{
    [Flags]
	public enum class lcmsFlags : UInt32 {
	// FLAGS
		EMPTY								= 0,
        MATRIXINPUT							= 0x0001,
        MATRIXOUTPUT						= 0x0002,
        MATRIXONLY							= MATRIXINPUT | MATRIXOUTPUT,
        
		NOWHITEONWHITEFIXUP					= 0x0004,   // Don't hot fix scum dot  
        NOPRELINEARIZATION					= 0x0010,	// Don't create prelinearization tables
															// on precalculated transforms (internal use)

		GUESSDEVICECLASS					= 0x0020,   // Guess device class (for transform2devicelink)

		NOTCACHE							= 0x0040,   // Inhibit 1-pixel cache

        NOTPRECALC							= 0x0100,
        NULLTRANSFORM						= 0x0200,	// Don't transform anyway

        HIGHRESPRECALC						= 0x0400,	// Use more memory to give better accurancy
        LOWRESPRECALC						= 0x0800,	// Use less memory to minimize resouces

        WHITEBLACKCOMPENSATION				= 0x2000,
        BLACKPOINTCOMPENSATION				= WHITEBLACKCOMPENSATION,

		//Proofing Flags
        GAMUTCHECK							= 0x1000,	// Mark Out of Gamut as alarm color (on proofing transform)
        SOFTPROOFING						= 0x4000,	// Softproof of proofing profile

		// Black preservation         

		PRESERVEBLACK						= 0x8000,

		// CRD special
        NODEFAULTRESOURCEDEF				= 0x01000000,	// PostScript
	};
}