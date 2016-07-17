#include "stdafx.h"
#include "Greibach.h"
#include "Error.h"
#include "string.h"


namespace GRB {
	Rule::Chain::Chain(short psize, GRBALPHABET s, ...) {
		size = psize;
		int* tmp = (int*)&s;
		nt = new GRBALPHABET[size];
		for (int i = 0; i < size; i++)
		{
			nt[i] = (GRBALPHABET)tmp[i];
		}
	}
	Rule::Rule(GRBALPHABET pnn, int piderror, short psize, Chain c, ...) {
		nn = pnn;
		iderror = piderror;
		size = psize;
		Chain* tmp = &c;
		chains = new Chain[size];
		for (int i = 0; (i < size - 1) && tmp; i++) {
			chains[i] = tmp[i];
		}
	}
	Greibach::Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottomT, short psize, Rule r, ...) {
		startN = pstartN;
		stbottomT = pstbottomT;
		size = psize;
		rules = new Rule[size];
		Rule* p = &r;
		for (int i = 0; i < size; i++)
			rules[i] = p[i];
	}
////
	char* Rule::Chain::getChain(char* b) {
		
		for (int i = 0; i < Chain::size; i++)
		{
			b[i] = Chain::alphabet_to_char(nt[i]);
		}
		b[size] = '\0';
		return b;
	}
	char* Rule::getRule(char* b, short nchain) {
		char tmp[30];
		b[0] = GRB::Rule::Chain::alphabet_to_char(nn);
		b[1] = '-';
		b[2] = '>';
		b[3] = '\0';
		/*for (int z = 0; i < chains[nchain].size; z++,i++) {
			b[i] = GRB::Rule::Chain::alphabet_to_char(chains[nchain].nt[z]);
		}*/
		chains[nchain].getChain(tmp);
		strcat(b, tmp);
		return b;
	}
	short Rule::getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j) {
		short k = -1;
		for (j; j < size; j++)
		{
			if (chains[j].nt[0] == t)
			{
				pchain = chains[j];
				k = j;
			}
		}
		return k;
	}
////	
	short Greibach::getRule(GRBALPHABET pnn, Rule& prule) {
		int num=-1;
		for (int i = 0; i <size; i++)
		{
			if (pnn == rules[i].nn)
			{
				num = i;
				prule = rules[i];
			}
		}
		return num;
	}
	Rule Greibach::getRule(short n) {
		Rule p;
		if (n < size)
			p = rules[n];
		return p;
	}

}