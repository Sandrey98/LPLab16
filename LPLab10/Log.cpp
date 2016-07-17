#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "stdafx.h"

#include <stdlib.h>
#include "Log.h"
#include <ctime>
#include "time.h"
#include "FST.h"
namespace Log {
	LOG getlog(wchar_t logfile[]) {
		LOG* p=new LOG;
		p->stream = new std::ofstream(logfile);
		if (p->stream->fail())
			throw ERROR_THROW(112);
		wcscpy_s(p->logfile, logfile);
		return *p;
	}
	void WriteLine(LOG log, char* c, ...) {
		char **p = &c;
		while (strcmp(*p,"")) {
			*(log.stream) << *p;
			p++;	
		}
	}
	void WriteLine(LOG log, wchar_t* c, ...) {
		wchar_t **p = &c;
		char tmp[PARM_MAX_SIZE];
		while (wcscmp(*p, L"")) {
			wcstombs(tmp, *p, PARM_MAX_SIZE);
			*(log.stream) << tmp;
			p++;
		}
	}
	void WriteLog(LOG log) {
		*(log.stream) << "\n---- �������� ------ ����: ";	
		time_t rawtime;
		char buffer[80];                                // ������, � ������� ����� ��������� ������� �����
		time(&rawtime);                               
		tm *k = localtime(&rawtime);
		strftime(buffer, 80, " %x %X", k);
		*(log.stream) << buffer<<"------------------";
	
	}
	void WriteParm(LOG log, Parm::PARM parm) {
		char tmp[PARM_MAX_SIZE];
		wcstombs(tmp, parm.log, sizeof(parm.log));
		*(log.stream) << "\n---- ��������� --------\n" <<"-log: " << tmp;
		wcstombs(tmp, parm.out, sizeof(parm.out));
		*(log.stream) << "\n-out: " << tmp;
		wcstombs(tmp, parm.in, sizeof(parm.in));
		*(log.stream) << "\n-in: " << tmp <<std::endl ;
	}
	void WriteIn(LOG log, In::IN in) {
		*(log.stream) << "---- �������� ������ ------ \n\n";
		/*for (int i = 0; i<in.size; i++) {
			
			 (*log.stream) << in.text[i];
		}*/
		*(log.stream) << "���������� ��������: " << in.size <<
						 "\n���������������    : " << in.ignor <<
						 "\n���������� �����   : " << in.lines<<"\n";
	}
	void WriteError(LOG log, Error::ERROR error) {
		*(log.stream) << "\n������ "<<error.id   <<": "<< error.message << ", ������ " <<
			error.intext.line << " ������� " << error.intext.col << std::endl;
		}
	void close(LOG log) {
		(log.stream)->close();
		delete log.stream;
	}
}