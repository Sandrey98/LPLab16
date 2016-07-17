#include "stdafx.h"
#include "FST.h"
#include <string.h>
#include <iostream>
namespace FST {
	RELATION::RELATION(char c, short ns ) {
		symbol = c;					//символ перехода
		nnode = ns;					//номер узла перехода
	}
	NODE::NODE() {
		n_relation = 0;
		RELATION *relations = NULL;
	}
	NODE::NODE(short n, RELATION rel, ...) {
		n_relation = n;						//кол-во ребер
		RELATION* buf = &rel;				//первый из разного кол-во параметров
		relations = new RELATION[n];		//массив ребер
		for (int i = 0; i < n_relation;i++){		//заполнение массива ребер
			relations[i] = buf[i];
		}
	}
	FST::FST(char* s, short ns, NODE n, ...) {
		
		line = 0;
		pos = 0;
		string = s;							//входная цепочка
		nstates = ns;						//общее кол-во состояний ка
		position = -1;						
		NODE* buf = &n;								
		nodes = new NODE[ns];						
		for (int i = 0; i < ns; i++) {		//заполнение графа узлами	
			nodes[i] = buf[i];
		}
		rstates = new short[ns];			//массив возможных состочяний ка на позиции
		rstates[0] = 0;	
	}
	bool execute(FST& fst)
	{
		short* rstates = new short[fst.nstates];		//массив размером кол-ва состояний
		memset(rstates, 0xff, sizeof(short)*fst.nstates);
		short lstring = strlen(fst.string);				//длина входной цепочки
		bool rc = true;
		for (short i = 0; i < lstring &&rc; i++) 
		{
			fst.pos++;
			fst.position++;
			if (fst.string[fst.position] == IN_CODE_SEP) {
				fst.line++;
				fst.pos = 0;
			}			
			rc = step(fst, rstates);
		}

		delete[] rstates;
		return (rc?(fst.rstates[fst.nstates - 1] == lstring) : rc);	//true, если последний элемент массива равен
	}																   //кол-ву значимых символов входной цепочки
	
	bool step(FST& fst, short* &rstetes) {		//ка, массив возможных состочяний ка на позиции
		bool rc = false;
		std::swap(rstetes, fst.rstates);		//замена массива местами
		for (short i = 0; i < fst.nstates; i++)
		{
			if (rstetes[i] == fst.position) 
			{
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
				{
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					}
				}
			}
		}
		return rc;
	}
}