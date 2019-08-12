#pragma once  
#pragma managed
#include <vcclr.h>

using namespace System;

namespace LittleCMSWrapper {
	///<sumary>
	///  Base class for a Profile and a Transform
	///</sumary>
	public ref class lcmsHandler abstract : LittleCMSWrapperBase
	{
	internal:
		void* _Handler;
		lcmsHandler(void* hPointer) : _Handler(hPointer) {}	  		
		
		property void* Handler
		{
			void* get()
			{
				return _Handler;
			}
			void set(void* value)
			{
				_Handler = value;
			}
		}
	public:
		lcmsHandler(): _Handler(nullptr) {}

		~lcmsHandler() { if(HasValue) Close();}
		/// <sumary>
		/// Shouldn't be use in C#
		/// </sumary>

		property bool HasValue
		{
			bool get() {return _Handler != nullptr || _Handler != NULL; }
		}

		virtual bool Close() 
		{
			if(HasValue) delete _Handler;
			_Handler = nullptr;
			return true;
		}
				
	};
}