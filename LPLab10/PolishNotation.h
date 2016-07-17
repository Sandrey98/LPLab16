#pragma once
#include "IT.h"
#include "LT.h"
#include <locale>
#include <iostream>
namespace PN {
	bool PolishNotation(int lextable_pos, LT::LexTable& lextable, IT::IdTable& idtable);
	void pn(LT::LexTable& lextable, IT::IdTable& idtable);
	int prior(char);
}
//true - выполнено успешно
//false - построение не выполнено