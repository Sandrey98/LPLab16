// LPLab10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>

#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "FST.h"
#include "LAxAnalize.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INITLOG;
	try {
	
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, L"Тест", L":без ошибок ", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		LA::Analize(in, log);
	
		
		Log::close(log);
	}
	catch(Error::ERROR e){
		std::cout << "Ошибка " << e.id << ": " << e.message << std::endl <<std::endl;
		Log::WriteError(log, e);	
	}
	
   // return 0;
}

