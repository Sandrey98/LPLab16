#pragma once
#include "stdafx.h"
#define IN_CODE_SEP ';'
namespace FST {
	struct RELATION {					//ребро: символ - > графа переходов КА
		char symbol;					//символ перехода
		short nnode;					//нмоер смежной вершины
		RELATION(char c = 0x00,
			short ns = NULL);
	};
	struct NODE						//вершина графа перезродов 
	{
		short n_relation;				//количество идентичных ребер
		RELATION* relations;			//инцидентые ребра
		NODE();
		NODE(short n,					//кол-во инцидентных ребер
			RELATION rel,				//список ребер
			...);	//
	};
	struct FST						//недетерминированный конечный автомат
	{
		int line;
		int pos;
		char* string;				//цепочка (строка завершается 0х00)
		short position;				//текущая позиция в цепочке
		short nstates;				//количество состояний автомата
		NODE* nodes;				//граф переходов: [0] - начальное состояние, [nstate-1] - конечное 
		short* rstates;				//возможные состояния автомата на данный позиции
		FST(
			char* s,				//цепочка(строка завершается 0х00)
			short ns,				//кол-во состояний автомата
			NODE n, ...);			//список состояний(графа переходов)
	};			//недетерменированный конечный автомат
	bool execute(					//выполнить распознавание цепочки
		FST& fst);					//недетерминированный КА
	bool step(FST&, short*&);
};
