#pragma managed
#include "Stdafx.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace LittleCMSWrapper
{	
	static int _lcmsErrorHandlingFunction (int ErrorCode, const char *ErrorText)
	{
		String^ sErrorCode;

		switch (ErrorCode)
		{
		case LCMS_ERRC_ABORTED: 
			sErrorCode = "ERROR";
			break;
		case LCMS_ERRC_RECOVERABLE:
			sErrorCode = "RECOVERABLE ERROR";
			break;
		case LCMS_ERRC_WARNING:
			sErrorCode = "WARNING";
			break;
		default:
			sErrorCode = "UNKNOWN ERROR";
		}

		if(!lcmsErrorManager::_IgnoreErrors && (ErrorCode = LCMS_ERRC_ABORTED || !lcmsErrorManager::_OnlyAbortedErrors)) 
			throw gcnew System::Exception(String::Format("{0}: {1}",sErrorCode,gcnew String(ErrorText)));

		return 1;  //True
	}

	lcmsErrorManager::lcmsErrorManager()
	{
		if(!_ErrorIsSet) {
			cmsErrorAction(LCMS_ERROR_ABORT);
			cmsSetErrorHandler(&_lcmsErrorHandlingFunction);
			_ErrorIsSet = true;
		}
	}

	void lcmsErrorManager::SignalError(lcmsErrorCode errorCode, String^ errorMsg)
	{
		IntPtr ptrErrorMsg = Marshal::StringToCoTaskMemAnsi(errorMsg);
		const char *ErrorText = (const char*)ptrErrorMsg.ToPointer();

		SignalError(errorCode,ErrorText);
	}

	void lcmsErrorManager::SignalError(lcmsErrorCode errorCode, const char* errorMsg)
	{
		int r = _lcmsErrorHandlingFunction((Int32)errorCode,errorMsg);
	}
}