#include "stdafx.h"
#include "FST.h"
#include <string.h>
#include <iostream>
namespace FST {
	RELATION::RELATION(char c, short ns ) {
		symbol = c;					//������ ��������
		nnode = ns;					//����� ���� ��������
	}
	NODE::NODE() {
		n_relation = 0;
		RELATION *relations = NULL;
	}
	NODE::NODE(short n, RELATION rel, ...) {
		n_relation = n;						//���-�� �����
		RELATION* buf = &rel;				//������ �� ������� ���-�� ����������
		relations = new RELATION[n];		//������ �����
		for (int i = 0; i < n_relation;i++){		//���������� ������� �����
			relations[i] = buf[i];
		}
	}
	FST::FST(char* s, short ns, NODE n, ...) {
		
		line = 0;
		pos = 0;
		string = s;							//������� �������
		nstates = ns;						//����� ���-�� ��������� ��
		position = -1;						
		NODE* buf = &n;								
		nodes = new NODE[ns];						
		for (int i = 0; i < ns; i++) {		//���������� ����� ������	
			nodes[i] = buf[i];
		}
		rstates = new short[ns];			//������ ��������� ���������� �� �� �������
		rstates[0] = 0;	
	}
	bool execute(FST& fst)
	{
		short* rstates = new short[fst.nstates];		//������ �������� ���-�� ���������
		memset(rstates, 0xff, sizeof(short)*fst.nstates);
		short lstring = strlen(fst.string);				//����� ������� �������
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
		return (rc?(fst.rstates[fst.nstates - 1] == lstring) : rc);	//true, ���� ��������� ������� ������� �����
	}																   //���-�� �������� �������� ������� �������
	
	bool step(FST& fst, short* &rstetes) {		//��, ������ ��������� ���������� �� �� �������
		bool rc = false;
		std::swap(rstetes, fst.rstates);		//������ ������� �������
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