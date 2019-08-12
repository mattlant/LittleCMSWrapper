#pragma once  
#pragma managed
#include <vcclr.h>


using namespace System;
//using namespace System::Collections::Generic;


namespace LittleCMSWrapper {

	public ref class LittleCMSWrapperBase abstract : System::Object
	{
	private:
		static lcmsErrorManager^ _ErrorManager = nullptr;
	public:
		
		LittleCMSWrapperBase()
		{
			if(_ErrorManager == nullptr) _ErrorManager = gcnew lcmsErrorManager();		
		}

		property lcmsErrorManager^ ErrorManager
		{
			lcmsErrorManager^ get() 
			{
				if(_ErrorManager == nullptr) _ErrorManager = gcnew lcmsErrorManager();
				return _ErrorManager;
			}
		}

		static void InitErrorManager()
		{
			if(_ErrorManager == nullptr) _ErrorManager = gcnew lcmsErrorManager();			
		}
	};
}