#pragma once
#include "stdafx.h"
#include "Error.h"
#include "In.h"

#include <fstream>
#include <iostream>


namespace In {
	In::IN getin(wchar_t infile[]) {
		
		std::ifstream par(infile);
		if (par.fail())
		{
			throw ERROR_THROW(110);
		}
		else
		{
			
			IN ret;
			bool fl = 0;
			/*for (int i = 0; i < 256; i++) {
				std::cout << (char)i << " "<< i << std::endl;
				
			}*/
			ret.size = ret.ignor = ret.lines = 0;
			int pkck = 0;
			ret.text = new unsigned char[IN_MAX_LEN_TEXT];
			int ind;
			unsigned char tmp(' ');

			while (!par.eof()) {
				unsigned char t;

				t = par.get();
				if (par.eof()) break;
				ind = (int)t;
				//для заполнение поля text
				

				if (ret.text[ret.size - 1] == ' ' && ret.code[(int)t] == IN::V)		//если перед знаком стоит пробел
				{
					ret.text[--ret.size] = t;
					ret.size++;

					continue;
				}
				else
				if (ret.code[(int)t] == IN::V)			//перед знаком пробела нет
				{
					ret.text[ret.size] = t;
					ret.size++;
					continue;
				}
				else
				if (t == ' ' && ret.code[(int)ret.text[ret.size - 1]] == IN::V){	//если перед пробелом шел знак, то игнор
					ret.ignor++;
				continue;
				}
				else

				if (ret.text[ret.size - 1] == ' ' && ret.code[(int)t] == IN::S)
				{
					ret.text[--ret.size] = t;
					ret.size++;
					continue;

				}

				if (ret.code[(int)t] == IN::S)			//перед знаком пробела нет
				{
					ret.text[ret.size] = t;
					ret.size++;
					continue;
				}



				else if (ret.code[ind] == IN::F) {
					
					throw ERROR_THROW_IN(111, ret.lines, pkck);
				}


				else if (ret.code[ind] == IN::I) {
					pkck++;
					ret.ignor++;
					continue;
				}



				if (ret.code[ind] == IN::T)
				{
					if (int(tmp) == (int)t && int(tmp) == ' ') {
						tmp = t;
						ret.ignor++;
						continue;
					}
					if (int(t) == 10) {
						pkck = 0;
						ret.lines++;
						ret.text[ret.size] = '|';
						ret.size++;
						continue;
					}
					pkck++;
					ret.text[ret.size] = t;
					ret.size++;
					fl = 1;						//определить, или есть вообще строки

					tmp = t;

					continue;
				}
				else {
					pkck++;
					ret.text[ret.size] = ret.code[ind];
					ret.size++;
				}
			}
			if (fl)
				ret.lines++;
			ret.text[ret.size] = '\0';
			par.close();
			return ret;
		}
	};
};