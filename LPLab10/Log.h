
#pragma once
#include <fstream>
#include "In.h"
#include "Parm.h"
#include "Error.h"
namespace Log {
	struct LOG {
		wchar_t logfile[PARM_MAX_SIZE];
		std::ofstream* stream;
	};
	static const LOG INITLOG = { L"", NULL };			
	LOG getlog(wchar_t logfile[]);						//начальная инициализация LOG
	void WriteLine(LOG log, char* c, ...);				//сформировать структуру LOG
	void WriteLine(LOG log, wchar_t* c, ...);			//вывести в протокол конкатенацию строк
	void WriteLog(LOG log);								//вывести в протокол конкатенацию строк
	void WriteParm(LOG log, Parm::PARM parm);			//вывести в протокол информацию о входных данных
	void WriteIn(LOG log, In::IN in);					//вывести в протокол информациб о входном потоке
	void WriteError(LOG log, Error::ERROR error);		//вывести в протокол информациб об ошибке
	void close(LOG log);								//закрыть протокол
};