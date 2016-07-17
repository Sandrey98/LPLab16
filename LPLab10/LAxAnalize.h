#pragma once
#include "stdafx.h"
#include "iostream"
#include "In.h"
#include "Log.h"
#include "LT.h"
#include "IT.h"
#include "FST.h"

namespace LA {
	struct LEX {
		LT::LexTable lextable;
		IT::IdTable idtable;
	};
	LEX Analize(In::IN , Log::LOG);
	bool AddLex(FST::FST&, char*, char, int); //(ка, образец лексемы, лексема в таблицу, строка)

}