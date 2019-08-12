#pragma once
#pragma managed

namespace LittleCMSWrapper
{
	public enum class lcmsICProfileClassSignature : UInt32
	{
	    SigInputClass                     = 0x73636E72L,  /* 'scnr' */
		SigDisplayClass                   = 0x6D6E7472L,  /* 'mntr' */
		SigOutputClass                    = 0x70727472L,  /* 'prtr' */
		SigLinkClass                      = 0x6C696E6BL,  /* 'link' */
		SigAbstractClass                  = 0x61627374L,  /* 'abst' */
		SigColorSpaceClass                = 0x73706163L,  /* 'spac' */
		SigNamedColorClass                = 0x6e6d636cL,  /* 'nmcl' */
		MaxEnumClass                      = 0xFFFFFFFFL, 
	};
}