#pragma once  
#pragma managed
#include <vcclr.h>


using namespace System;
//using namespace System::Runtime::InteropServices;
//using namespace System::Collections::Generic;


namespace LittleCMSWrapper 
{
	public enum class lcmsErrorCode {
		Warning		= 0x1000,
		Recoverable = 0x2000,
		Error		= 0x3000,
	};

	public ref class lcmsErrorManager
	{
	internal:
		static bool _ErrorIsSet = false;

		lcmsErrorManager();

		static bool _IgnoreErrors = false;
		static bool _OnlyAbortedErrors = true;

		static void SignalError(lcmsErrorCode errorCode, const char* errorMsg);
		static void SignalError(const char* errorMsg) { SignalError(lcmsErrorCode::Error, errorMsg);}

	public:


		property bool IsErrorHandlingActive	 //Always should return true
		{
			bool get() { return _ErrorIsSet; }
		}

		property bool IgnoreErrors 
		{
			bool get() { return _IgnoreErrors; }
		}

		property bool OnlyAbortedErrors 
		{
			bool get() { return _OnlyAbortedErrors; }
		}

		void SignalError(lcmsErrorCode errorCode, String^ errorMsg);
		void SignalError(String^ errorMsg) { SignalError(lcmsErrorCode::Error, errorMsg);}
	};		
}