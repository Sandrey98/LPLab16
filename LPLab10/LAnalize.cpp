
#include "stdafx.h"
#include <iostream>
#include "FST.h"
#include "LAxAnalize.h"
#include "LT.h"
#include "IT.h"
#include "In.h"
#include "Error.h"
#include "PolishNotation.h"

namespace LA {

	FST::NODE alllit() {
		FST::NODE p;
		p.relations = new FST::RELATION[316];
		p.n_relation = 316;
		int k = 0;
		for (int i = 0x20; i < 0x7F; i++)
		{
			if (i == 0x27) continue;

			p.relations[k].symbol = (char)i;
			p.relations[k].nnode = 2;
			k++;
			p.relations[k].symbol = (char)i;
			p.relations[k].nnode = 1;
			k++;
		};
		for (int i = 0xC0; i <= 0xFF; i++)
		{

			p.relations[k].symbol = (char)i;
			p.relations[k].nnode = 2;
			k++;
			p.relations[k].symbol = (char)i;
			p.relations[k].nnode = 1;
			k++;
		};
		p.n_relation = k;
		return p;

	}

	FST::FST fStringLiteral("", 4,
		FST::NODE(1, FST::RELATION((char)0x27, 1)),
		alllit(),
		FST::NODE(1, FST::RELATION((char)0x27, 3)),
		FST::NODE()
		);

	FST::FST fIntLit("", 2,
		FST::NODE(20,
			FST::RELATION('0', 1), FST::RELATION('0', 0),
			FST::RELATION('1', 1), FST::RELATION('1', 0),
			FST::RELATION('2', 1), FST::RELATION('2', 0),
			FST::RELATION('3', 1), FST::RELATION('3', 0),
			FST::RELATION('4', 1), FST::RELATION('4', 0),
			FST::RELATION('5', 1), FST::RELATION('5', 0),
			FST::RELATION('6', 1), FST::RELATION('6', 0),
			FST::RELATION('7', 1), FST::RELATION('7', 0),
			FST::RELATION('8', 1), FST::RELATION('8', 0),
			FST::RELATION('9', 1), FST::RELATION('9', 0)),
		FST::NODE()
		);

	FST::FST fInteger("", 8,
		FST::NODE(1, FST::RELATION('i', 1)),
		FST::NODE(1, FST::RELATION('n', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE(1, FST::RELATION('g', 5)),
		FST::NODE(1, FST::RELATION('e', 6)),
		FST::NODE(1, FST::RELATION('r', 7)),
		FST::NODE()
		);

	FST::FST fString("", 7,
		FST::NODE(1, FST::RELATION('s', 1)),
		FST::NODE(1, FST::RELATION('t', 2)),
		FST::NODE(1, FST::RELATION('r', 3)),
		FST::NODE(1, FST::RELATION('i', 4)),
		FST::NODE(1, FST::RELATION('n', 5)),
		FST::NODE(1, FST::RELATION('g', 6)),
		FST::NODE()
		);

	FST::FST fDeclare("", 8,
		FST::NODE(1, FST::RELATION('d', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('c', 3)),
		FST::NODE(1, FST::RELATION('l', 4)),
		FST::NODE(1, FST::RELATION('a', 5)),
		FST::NODE(1, FST::RELATION('r', 6)),
		FST::NODE(1, FST::RELATION('e', 7)),
		FST::NODE()
		);

	FST::FST fReturn("", 7,
		FST::NODE(1, FST::RELATION('r', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('u', 4)),
		FST::NODE(1, FST::RELATION('r', 5)),
		FST::NODE(1, FST::RELATION('n', 6)),
		FST::NODE()
		);

	FST::FST fFunction("function", 9,
		FST::NODE(1, FST::RELATION('f', 1)),
		FST::NODE(1, FST::RELATION('u', 2)),
		FST::NODE(1, FST::RELATION('n', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE(1, FST::RELATION('i', 6)),
		FST::NODE(1, FST::RELATION('o', 7)),
		FST::NODE(1, FST::RELATION('n', 8)),
		FST::NODE()
		);

	FST::FST fMain("", 5,
		FST::NODE(1, FST::RELATION('m', 1)),
		FST::NODE(1, FST::RELATION('a', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE()
		);

	FST::FST fPrint("", 6,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE()
		);

	FST::FST fSemicolon("", 2,
		FST::NODE(1, FST::RELATION(';', 1)),
		FST::NODE());

	FST::FST fComma("", 2,
		FST::NODE(1, FST::RELATION(',', 1)),
		FST::NODE());

	FST::FST fLeftBrace("", 2,
		FST::NODE(1, FST::RELATION('{', 1)),
		FST::NODE());

	FST::FST fRightBrace("", 2,
		FST::NODE(1, FST::RELATION('}', 1)),
		FST::NODE());

	FST::FST fLeftThesis("", 2,
		FST::NODE(1, FST::RELATION('(', 1)),
		FST::NODE());

	FST::FST fRightThesis("", 2,
		FST::NODE(1, FST::RELATION(')', 1)),
		FST::NODE());

	FST::FST fravno("", 2,
		FST::NODE(1, FST::RELATION('=', 1)),
		FST::NODE());

	FST::FST fV("", 2,
		FST::NODE(4,
			FST::RELATION('+', 1),
			FST::RELATION('-', 1),
			FST::RELATION('*', 1),
			FST::RELATION('/', 1)),
		FST::NODE());

	FST::FST fIdent("", 2,
		FST::NODE(52,
			FST::RELATION('a', 0), FST::RELATION('a', 1),
			FST::RELATION('b', 0), FST::RELATION('b', 1),
			FST::RELATION('c', 0), FST::RELATION('c', 1),
			FST::RELATION('d', 0), FST::RELATION('d', 1),
			FST::RELATION('e', 0), FST::RELATION('e', 1),
			FST::RELATION('f', 0), FST::RELATION('f', 1),
			FST::RELATION('g', 0), FST::RELATION('g', 1),
			FST::RELATION('h', 0), FST::RELATION('h', 1),
			FST::RELATION('i', 0), FST::RELATION('i', 1),
			FST::RELATION('j', 0), FST::RELATION('j', 1),
			FST::RELATION('k', 0), FST::RELATION('k', 1),
			FST::RELATION('l', 0), FST::RELATION('l', 1),
			FST::RELATION('m', 0), FST::RELATION('m', 1),
			FST::RELATION('n', 0), FST::RELATION('n', 1),
			FST::RELATION('o', 0), FST::RELATION('o', 1),
			FST::RELATION('p', 0), FST::RELATION('p', 1),
			FST::RELATION('q', 0), FST::RELATION('q', 1),
			FST::RELATION('r', 0), FST::RELATION('r', 1),
			FST::RELATION('s', 0), FST::RELATION('s', 1),
			FST::RELATION('t', 0), FST::RELATION('t', 1),
			FST::RELATION('u', 0), FST::RELATION('u', 1),
			FST::RELATION('v', 0), FST::RELATION('v', 1),
			FST::RELATION('w', 0), FST::RELATION('w', 1),
			FST::RELATION('x', 0), FST::RELATION('x', 1),
			FST::RELATION('y', 0), FST::RELATION('y', 1),
			FST::RELATION('z', 0), FST::RELATION('z', 1)),
		FST::NODE()
		);

	LT::LexTable lexT = LT::Create(LT_MAXSIZE);
	IT::IdTable idT = IT::Create(TI_MAXSIZE);
	bool AddLex(FST::FST& fst, char* lex_for_cmp, char lexema, int position) {
		LT::Entry tmp;
		tmp.lexema = lexema;
		tmp.sn = position;
		
	    tmp.idxTI = -1;
		fst.string = lex_for_cmp;
		fst.rstates[0] = 0;
		fst.position = -1;
		bool p = false;
		
		if (execute(fst)) {
			LT::Add(lexT, tmp);
			p = true;
		}
		if (p && lexema == 'i')
			position++;
		return p;
	}

	struct ERR_MAS {
		int ernum;
		int line;
		int position;
		
		//ERR_MAS(int e, int l, int p);
	};
	/*ERR_MAS::ERR_MAS(int e, int l, int p) {
		ernum = e;
		line = l;
		position = p;
	}*/

	LEX Analize(In::IN in, Log::LOG log) {
		char* templex = new char[255];					//лексема
		char* tempid = new char[10];					//имя переменной
		char* tempval = new char[255];					//значение переменной
		char* prefix = new char[5];						//текущий префикс
		char* subprefix = new char[5];					//буфернвй префикс
		char* tempprefix = new char[5];					//префикс функции, в который сейчас
		LEX ret;
										
		int size_of_lex_str = 0, line = 0;				//текущая длина лексемы/ номер строки
		int numb_of_lit = 0;							//текущий нмоер лексемы
		int position = -1;								//текущая позиция в исходном коде

		bool forFunction = false;						//дли инициализации типа ид в таблице идентификаторов
		bool fl_for_id = false;							//есть ли перед ид определение (true - есть, false - использование)						
		bool infunction = false;						//для взятия перфикса (есть ли перед текущей позицией слово function)
		bool fc = false;								//нахождение в функции
		bool exitSub = false;							//вышли ли из внутренней функции
		bool ismain = false;							//есть ли в коде точка входа main
		bool flerror = false;								//проверка на наличие ошибок
		ERR_MAS ermas[100],h;							//массив ошибок
		int erind = 0;									//индексы массива ошибок		
		for (int i = 0; i < in.size; i++) {
			
				bool fl = false;


				if (in.text[i] == '|')
				{
					position = -1;
					line++;									//номер строки
					continue;
				}
				if (in.text[i] != LEX_SEMICOLON &&
					in.text[i] != LEX_COMMA &&
					in.text[i] != LEX_LEFTBRACE &&
					in.text[i] != LEX_RIGHTBRACE &&
					in.text[i] != LEX_LEFTHESIS &&
					in.text[i] != LEX_RIGHTHESIS &&
					in.text[i] != '|' &&
					in.text[i] != ' ' &&
					in.text[i] != '='&&
					in.text[i] != '+' &&
					in.text[i] != '-' &&
					in.text[i] != '*' &&
					in.text[i] != '/')						//обрывание слова на любом из сепараторов
				{
					templex[size_of_lex_str] = in.text[i];
					size_of_lex_str++;
				}
				else {
					templex[size_of_lex_str] = '\0';		//заканчиваем временное слово
					size_of_lex_str = 0;					//обнулить новую длину строки
					if (!fl) {
						fl = (AddLex(fInteger, templex, LEX_INTEGER, line));			//определение типа данных идентификатора
						if (fl) {
							idT.table[idT.size].idxfirstLE = line;
							idT.table[idT.size].iddatatype = IT::INT;
							if (lexT.table[lexT.size - 2].lexema == LEX_DECLARE) {
								idT.table[idT.size].idtype = IT::V;
								idT.table[idT.size].value.vind = 0;
							}
							if (lexT.table[lexT.size - 2].lexema == LEX_LEFTHESIS || lexT.table[lexT.size - 2].lexema == LEX_COMMA)
								idT.table[idT.size].idtype = IT::P;
							idT.size++;
							fl_for_id = true;
						}
					}
					if (!fl) {
						fl = (AddLex(fString, templex, LEX_STRING, line));
						if (fl) {
							idT.table[idT.size].idxfirstLE = line;
							idT.table[idT.size].iddatatype = IT::STR;

							if (lexT.table[lexT.size - 2].lexema == LEX_DECLARE) {
								idT.table[idT.size].idtype = IT::V;
								memset(idT.table[idT.size].value.vstr.str, TI_STRDEFAULT, 225);

							}
							if (lexT.table[lexT.size - 2].lexema == LEX_LEFTHESIS || lexT.table[lexT.size - 2].lexema == LEX_COMMA)
								idT.table[idT.size].idtype = IT::P;
							idT.table[idT.size].value.vstr.str[0] = NULL;
							idT.size++;
							fl_for_id = true;
						}
					}
					if (!fl) {
						fl = (AddLex(fMain, templex, LEX_MAIN, line));
						if (fl) {
							ismain = true;
							forFunction = true;
							infunction = true;
							strncpy(prefix, templex, 5);
							prefix[5] = '\0';
							infunction = false;
							strcpy(tempprefix, prefix);

							lexT.table[lexT.size - 1].sn--;								//не трогать. перенос строки для скобки посде main
						}
					}
					if (!fl) {
						fl = (AddLex(fDeclare, templex, LEX_DECLARE, line));
					}
					if (!fl) {
						fl = (AddLex(fFunction, templex, LEX_FUNCTION, line));
						if (fl) {
							forFunction = true;										//для определение типа идетификатора
							infunction = true;										//для взятия префикса
							if (fc)													//для определение нахождения текущей функции(внутренняя или внешняя)
								exitSub = true;
						}
					}
					if (!fl) {
						fl = (AddLex(fReturn, templex, LEX_RETURN, line));
					}
					if (!fl) {
						fl = (AddLex(fPrint, templex, LEX_PRINT, line));
					}
					if (!fl) {
						fl = (AddLex(fIdent, templex, LEX_ID, line));
						if (fl) {
							if (strlen(templex) > 5) {
								strncpy(tempid, templex, 5);
								tempid[5] = '\0';
							}
							else
								strcpy(tempid, templex);

							if (exitSub && infunction) {
								strcpy(subprefix, prefix);										   //создание буферного префикса
							}
							if (forFunction)
							{
								idT.table[idT.size - 1].idtype = IT::F;							   //в табилце ид значение функции
								forFunction = false;
							}

							if (!infunction && !exitSub)
							{
								strcpy(prefix, tempprefix);										   //замена префикса после субфункции
							}

							if (!infunction && !fl_for_id && strlen(prefix) <= 5)
							{
								strcpy(prefix, tempprefix);											//не трогать. замена префикса
							}

							if (infunction)
							{														//создание префикса, если есть флаг на функию
								strcpy(prefix, tempid);
								if (!exitSub)
									strcpy(tempprefix, tempid);
								prefix[5] = '\0';
								infunction = false;
							}
							templex[5] = '\0';

							int d = IT::IsId(idT, tempid);
							if (d != -1)																						//содание ссылки на функцию
							{
								idT.table[idT.size] = idT.table[d];
								idT.size++;
							
							}
							
							if (!fl_for_id)
							{
								strcpy(idT.table[idT.size].id, prefix);
								strncpy(idT.table[idT.size].id + strlen(prefix), templex, 5);
								int d = IT::IsId(idT, idT.table[idT.size].id);
								if (d != -1) {																				//создание ссылки на идентификатор
									idT.table[idT.size] = idT.table[d];
									lexT.table[i].idxTI = idT.size;
									idT.size++;
								}
							/*	else {
									h.ernum = 122;
									h.line = line;
									h.position = position;
									ermas[erind++] = h;
									flerror = true;
								}*/
								//	throw ERROR_THROW_IN(122,line,position);												//тут сделать ошибку на не определенный идентификатор

							}
							if (fl_for_id) { 
								if (lexT.table[lexT.size - 2].lexema != LEX_FUNCTION) {
									strcpy(idT.table[idT.size - 1].id, prefix);
									strncpy(idT.table[idT.size - 1].id + strlen(idT.table[idT.size - 1].id), templex, 5);		//имя ид для идентификатора
								}
								else
								{
									strcpy(idT.table[idT.size - 1].id, prefix);													//имя ид для функции
								}
								int d = IT::IsDublId(idT, idT.table[idT.size - 1].id);
								if (d != TI_NULLIDX) {
									h.ernum = 120;
									h.line = line;
									h.position = position;
									ermas[erind++] = h;
									flerror = true;

								}
									//ERROR_THROW_IN(120, line, position);													//проверка на дублирование идентификатора
								fl_for_id = false;
							}
						}
					}
					if (!fl) {
						fl = (AddLex(fIntLit, templex, LEX_LITERAL, line));
						if (fl) {
							memset(tempval, '\0', 255);
							for (unsigned int i = 0; i < strlen(templex); i++) {
								tempval[i] = templex[i];
							}
							int i = IT::checkId(idT, atoi(tempval));
							if (i != TI_NULLIDX) {										//создание ссылки на литерал
								idT.table[idT.size] = idT.table[i];
								idT.size++;
							}
							else {
								idT.table[idT.size].iddatatype = IT::INT;
								idT.table[idT.size].idtype = IT::L;
								idT.table[idT.size].idxfirstLE = line;
								idT.table[idT.size].value.vind = atoi(tempval);
								tempval[0] = 'L';
								tempval[1] = (char)numb_of_lit + 0x30;
								strcpy(idT.table[idT.size].id, tempval);
								numb_of_lit++;									//инкремента номера литерала
								idT.size++;
							}
						}
					}
					memset(templex, '\0', 255);												//обнуление 
				}
				if (in.text[i] == LEX_SEMICOLON || in.text[i] == LEX_LEFTHESIS ||			//создание лексем для всяких там скобок и прочей херни
					in.text[i] == LEX_RIGHTHESIS || in.text[i] == LEX_LEFTBRACE ||
					in.text[i] == LEX_RIGHTBRACE || in.text[i] == LEX_COMMA)
				{
					int fl = false;
					templex[0] = in.text[i];
					templex[1] = '\0';
					if (!fl)
					{
						fl = AddLex(fSemicolon, templex, LEX_SEMICOLON, line);
						if (fl)
							exitSub = false;
					}
					if (!fl)
					{
						fl = AddLex(fLeftBrace, templex, LEX_LEFTBRACE, line);
						if (fl)
							fc = true;
					}
					if (!fl)
					{
						fl = AddLex(fRightBrace, templex, LEX_RIGHTBRACE, line);				//закрывает флаг на функцию
						if (fl) {
							fc = false;
							memset(prefix, '\0', 5);
						}
					}
					if (!fl)
					{
						fl = AddLex(fComma, templex, LEX_COMMA, line);
					}
					if (!fl)
					{
						fl = AddLex(fLeftThesis, templex, LEX_LEFTHESIS, line);
					}
					if (!fl)
					{
						fl = AddLex(fRightThesis, templex, LEX_RIGHTHESIS, line);				//закрывает флаг на субфункцию
						if (fl)
							exitSub = false;
					}
				}
				if (in.text[i] == '-' || in.text[i] == '+' || in.text[i] == '/' ||			//создание лексемы для знаков
					in.text[i] == '*' || in.text[i] == '=') {
					templex[0] = in.text[i];
					templex[1] = '\0';
					bool fl = false;
					if (!fl)
						fl = AddLex(fV, templex, 'v', line);
					LT::Entry e;
					if (in.text[i] == '=') {
						e.lexema = '=';
						e.idxTI = -1;
						e.sn = line;
						LT::Add(lexT, e);
						fl = true;

					}
					else {
						idT.table[idT.size].idxfirstLE = line;
						idT.table[idT.size].iddatatype = IT::OPR;
						idT.table[idT.size].idtype = IT::O;
						idT.table[idT.size].id[0] = templex[0];
						idT.table[idT.size].id[1] = '\0';
						idT.size++;
					}
				}
				if (in.text[i] == '\'') {
					templex[size_of_lex_str] = in.text[i++];								//записывает строку между кавычками
					while (in.text[i] != '\'') {
						templex[size_of_lex_str++] = in.text[i++];
					}
					templex[size_of_lex_str++] = '\'';
					templex[size_of_lex_str++] = '\0';
					if (!fl)
						fl = AddLex(fStringLiteral, templex, LEX_LITERAL, line);
					if (fl) {
						int d = IT::checkId(idT, templex);
						if (d != -1) {
							idT.table[idT.size] = idT.table[d];
							idT.size++;
						}
						else {
							memset(idT.table[idT.size].value.vstr.str, '\0', 255);
							idT.table[idT.size].iddatatype = IT::STR;
							idT.table[idT.size].idtype = IT::L;
							idT.table[idT.size].idxfirstLE = line;
							for (unsigned int i = 0; i < strlen(templex); i++) {
								idT.table[idT.size].value.vstr.str[i] = templex[i];
							}
							idT.table[idT.size].value.vstr.len = size_of_lex_str - 1;
							tempval[0] = 'L';
							tempval[1] = (char)numb_of_lit + 0x30;
							tempval[2] = '\0';
							strcpy(idT.table[idT.size].id, tempval);
							numb_of_lit++;
							idT.size++;
						}
					}
				}
				position++;				//инкремента теукущей позиции

			
		}
		if (!ismain) {
			h.ernum = 121;
			h.line = -1;
			h.position = -1;
			ermas[erind++]=h;
			flerror = true;

		
		
		}
		if (flerror) {
			std::cout << "Были обнаружены ошибки.\nПодробнее в журнале log.\n";
			for (int i = 0; i < erind; i++) {
				Error::ERROR e;
				e = ERROR_THROW_IN(ermas[i].ernum, ermas[i].line, ermas[i].position);
				Log::WriteError(log, e);
			
			
			}
		}
		else {
			int indT = 0;
			for (int i = 0; i < lexT.size; i++) {
				if (lexT.table[i].lexema == 'i' || lexT.table[i].lexema == 'v' || lexT.table[i].lexema == 'l') {				//связывание аблицы лексем и идентификаторов
					lexT.table[i].idxTI = indT;
					indT++;
				}



			}
	/**/		PN::pn(lexT, idT);													//вызов польской нотации
			int k = 0;
			*(log.stream) << "\n\n0: ";
			for (int i = 0; i < lexT.size; i++) {
				if (lexT.table[i].sn != k) {
					*(log.stream) << "\n" << lexT.table[i].sn << ": ";

					k = lexT.table[i].sn;
					*(log.stream) << lexT.table[i].lexema;

				}
				else
					*(log.stream) << lexT.table[i].lexema;
			}
			
			/*for (int i = 0; i < lexT.size; i++)
				if(lexT.table[i].idxTI!=-1)
				std::cout << "\n" << lexT.table[i].lexema << "   "<<idT.table[lexT.table[i].idxTI].id<<" " << lexT.table[i].idxTI;
			*/
			for (int i = 0; i < idT.size; i++) {
				std::cout << "\n\nИдентификатор №" << i << ": " << idT.table[i].id;
				//std::cout << "\nНомер в таблице идентификаторов: " << lexT.table[i].idxTI;
				std::cout << "\nСтрока: " << idT.table[i].idxfirstLE;
				if (idT.table[i].iddatatype == IT::INT)
					std::cout << "\nТип данных: integer";
				else if (idT.table[i].iddatatype == IT::STR)
					std::cout << "\nТип данных: string";
				else
					std::cout << "\nТип данных: operator";
				if (idT.table[i].idtype == IT::F)
					std::cout << "\nТип ид: F";
				else if (idT.table[i].idtype == IT::V)
					std::cout << "\nТип ид: V";
				else if (idT.table[i].idtype == IT::P)
					std::cout << "\nТип ид: P";
				else if (idT.table[i].idtype == IT::L)
					std::cout << "\nТип ид: L";
				else
					std::cout << "\nТип ид: O";

				if ((idT.table[i].iddatatype == IT::INT && idT.table[i].idtype == IT::V) ||
					(idT.table[i].iddatatype == IT::INT && idT.table[i].idtype == IT::L))
					std::cout << "\nЗначение: " << idT.table[i].value.vind;
				else if ((idT.table[i].iddatatype == IT::STR && idT.table[i].idtype == IT::V) ||
					(idT.table[i].iddatatype == IT::STR && idT.table[i].idtype == IT::L))
				{
					if (idT.table[i].value.vstr.str[0] == NULL)
						std::cout << "\nСтрока: NULL";
					else {
						std::cout << "\nСтрока: " << idT.table[i].value.vstr.str;
						std::cout << "\nДлина строки: " << idT.table[i].value.vstr.len;
					}
				}
			}
		}
		ret.idtable = idT;
		ret.lextable = lexT;
		return ret;
	}
}

//int fc(){
//
//#include "stdafx.h"
//#include <iostream>
//#include "FST.h"
//#include "LAxAnalize.h"
//#include "LT.h"
//#include "IT.h"
//#include "In.h"
//#include "Error.h"
//#include "PolishNotation.h"
//
//	namespace LA {
//
//		FST::NODE alllit() {
//			FST::NODE p;
//			p.relations = new FST::RELATION[316];
//			p.n_relation = 316;
//			int k = 0;
//			for (int i = 0x20; i < 0x7F; i++)
//			{
//				if (i == 0x27) continue;
//
//				p.relations[k].symbol = (char)i;
//				p.relations[k].nnode = 2;
//				k++;
//				p.relations[k].symbol = (char)i;
//				p.relations[k].nnode = 1;
//				k++;
//			};
//			for (int i = 0xC0; i <= 0xFF; i++)
//			{
//
//				p.relations[k].symbol = (char)i;
//				p.relations[k].nnode = 2;
//				k++;
//				p.relations[k].symbol = (char)i;
//				p.relations[k].nnode = 1;
//				k++;
//			};
//			p.n_relation = k;
//			return p;
//
//		}
//
//		FST::FST fStringLiteral("", 4,
//			FST::NODE(1, FST::RELATION((char)0x27, 1)),
//			alllit(),
//			FST::NODE(1, FST::RELATION((char)0x27, 3)),
//			FST::NODE()
//			);
//
//		FST::FST fIntLit("", 2,
//			FST::NODE(20,
//				FST::RELATION('0', 1), FST::RELATION('0', 0),
//				FST::RELATION('1', 1), FST::RELATION('1', 0),
//				FST::RELATION('2', 1), FST::RELATION('2', 0),
//				FST::RELATION('3', 1), FST::RELATION('3', 0),
//				FST::RELATION('4', 1), FST::RELATION('4', 0),
//				FST::RELATION('5', 1), FST::RELATION('5', 0),
//				FST::RELATION('6', 1), FST::RELATION('6', 0),
//				FST::RELATION('7', 1), FST::RELATION('7', 0),
//				FST::RELATION('8', 1), FST::RELATION('8', 0),
//				FST::RELATION('9', 1), FST::RELATION('9', 0)),
//			FST::NODE()
//			);
//
//		FST::FST fInteger("", 8,
//			FST::NODE(1, FST::RELATION('i', 1)),
//			FST::NODE(1, FST::RELATION('n', 2)),
//			FST::NODE(1, FST::RELATION('t', 3)),
//			FST::NODE(1, FST::RELATION('e', 4)),
//			FST::NODE(1, FST::RELATION('g', 5)),
//			FST::NODE(1, FST::RELATION('e', 6)),
//			FST::NODE(1, FST::RELATION('r', 7)),
//			FST::NODE()
//			);
//
//		FST::FST fString("", 7,
//			FST::NODE(1, FST::RELATION('s', 1)),
//			FST::NODE(1, FST::RELATION('t', 2)),
//			FST::NODE(1, FST::RELATION('r', 3)),
//			FST::NODE(1, FST::RELATION('i', 4)),
//			FST::NODE(1, FST::RELATION('n', 5)),
//			FST::NODE(1, FST::RELATION('g', 6)),
//			FST::NODE()
//			);
//
//		FST::FST fDeclare("", 8,
//			FST::NODE(1, FST::RELATION('d', 1)),
//			FST::NODE(1, FST::RELATION('e', 2)),
//			FST::NODE(1, FST::RELATION('c', 3)),
//			FST::NODE(1, FST::RELATION('l', 4)),
//			FST::NODE(1, FST::RELATION('a', 5)),
//			FST::NODE(1, FST::RELATION('r', 6)),
//			FST::NODE(1, FST::RELATION('e', 7)),
//			FST::NODE()
//			);
//
//		FST::FST fReturn("", 7,
//			FST::NODE(1, FST::RELATION('r', 1)),
//			FST::NODE(1, FST::RELATION('e', 2)),
//			FST::NODE(1, FST::RELATION('t', 3)),
//			FST::NODE(1, FST::RELATION('u', 4)),
//			FST::NODE(1, FST::RELATION('r', 5)),
//			FST::NODE(1, FST::RELATION('n', 6)),
//			FST::NODE()
//			);
//
//		FST::FST fFunction("function", 9,
//			FST::NODE(1, FST::RELATION('f', 1)),
//			FST::NODE(1, FST::RELATION('u', 2)),
//			FST::NODE(1, FST::RELATION('n', 3)),
//			FST::NODE(1, FST::RELATION('c', 4)),
//			FST::NODE(1, FST::RELATION('t', 5)),
//			FST::NODE(1, FST::RELATION('i', 6)),
//			FST::NODE(1, FST::RELATION('o', 7)),
//			FST::NODE(1, FST::RELATION('n', 8)),
//			FST::NODE()
//			);
//
//		FST::FST fMain("", 5,
//			FST::NODE(1, FST::RELATION('m', 1)),
//			FST::NODE(1, FST::RELATION('a', 2)),
//			FST::NODE(1, FST::RELATION('i', 3)),
//			FST::NODE(1, FST::RELATION('n', 4)),
//			FST::NODE()
//			);
//
//		FST::FST fPrint("", 6,
//			FST::NODE(1, FST::RELATION('p', 1)),
//			FST::NODE(1, FST::RELATION('r', 2)),
//			FST::NODE(1, FST::RELATION('i', 3)),
//			FST::NODE(1, FST::RELATION('n', 4)),
//			FST::NODE(1, FST::RELATION('t', 5)),
//			FST::NODE()
//			);
//
//		FST::FST fSemicolon("", 2,
//			FST::NODE(1, FST::RELATION(';', 1)),
//			FST::NODE());
//
//		FST::FST fComma("", 2,
//			FST::NODE(1, FST::RELATION(',', 1)),
//			FST::NODE());
//
//		FST::FST fLeftBrace("", 2,
//			FST::NODE(1, FST::RELATION('{', 1)),
//			FST::NODE());
//
//		FST::FST fRightBrace("", 2,
//			FST::NODE(1, FST::RELATION('}', 1)),
//			FST::NODE());
//
//		FST::FST fLeftThesis("", 2,
//			FST::NODE(1, FST::RELATION('(', 1)),
//			FST::NODE());
//
//		FST::FST fRightThesis("", 2,
//			FST::NODE(1, FST::RELATION(')', 1)),
//			FST::NODE());
//
//		FST::FST fravno("", 2,
//			FST::NODE(1, FST::RELATION('=', 1)),
//			FST::NODE());
//
//		FST::FST fV("", 2,
//			FST::NODE(4,
//				FST::RELATION('+', 1),
//				FST::RELATION('-', 1),
//				FST::RELATION('*', 1),
//				FST::RELATION('/', 1)),
//			FST::NODE());
//
//		FST::FST fIdent("", 2,
//			FST::NODE(52,
//				FST::RELATION('a', 0), FST::RELATION('a', 1),
//				FST::RELATION('b', 0), FST::RELATION('b', 1),
//				FST::RELATION('c', 0), FST::RELATION('c', 1),
//				FST::RELATION('d', 0), FST::RELATION('d', 1),
//				FST::RELATION('e', 0), FST::RELATION('e', 1),
//				FST::RELATION('f', 0), FST::RELATION('f', 1),
//				FST::RELATION('g', 0), FST::RELATION('g', 1),
//				FST::RELATION('h', 0), FST::RELATION('h', 1),
//				FST::RELATION('i', 0), FST::RELATION('i', 1),
//				FST::RELATION('j', 0), FST::RELATION('j', 1),
//				FST::RELATION('k', 0), FST::RELATION('k', 1),
//				FST::RELATION('l', 0), FST::RELATION('l', 1),
//				FST::RELATION('m', 0), FST::RELATION('m', 1),
//				FST::RELATION('n', 0), FST::RELATION('n', 1),
//				FST::RELATION('o', 0), FST::RELATION('o', 1),
//				FST::RELATION('p', 0), FST::RELATION('p', 1),
//				FST::RELATION('q', 0), FST::RELATION('q', 1),
//				FST::RELATION('r', 0), FST::RELATION('r', 1),
//				FST::RELATION('s', 0), FST::RELATION('s', 1),
//				FST::RELATION('t', 0), FST::RELATION('t', 1),
//				FST::RELATION('u', 0), FST::RELATION('u', 1),
//				FST::RELATION('v', 0), FST::RELATION('v', 1),
//				FST::RELATION('w', 0), FST::RELATION('w', 1),
//				FST::RELATION('x', 0), FST::RELATION('x', 1),
//				FST::RELATION('y', 0), FST::RELATION('y', 1),
//				FST::RELATION('z', 0), FST::RELATION('z', 1)),
//			FST::NODE()
//			);
//
//		LT::LexTable lexT = LT::Create(LT_MAXSIZE);
//		IT::IdTable idT = IT::Create(TI_MAXSIZE);
//		bool AddLex(FST::FST& fst, char* lex_for_cmp, char lexema, int position) {
//			LT::Entry tmp;
//			tmp.lexema = lexema;
//			tmp.sn = position;
//
//			tmp.idxTI = -1;
//			fst.string = lex_for_cmp;
//			fst.rstates[0] = 0;
//			fst.position = -1;
//			bool p = false;
//
//			if (execute(fst)) {
//				LT::Add(lexT, tmp);
//				p = true;
//			}
//			if (p && lexema == 'i')
//				position++;
//			return p;
//		}
//
//		struct ERR_MAS {
//			int ernum;
//			int line;
//			int position;
//
//			//ERR_MAS(int e, int l, int p);
//		};
//		/*ERR_MAS::ERR_MAS(int e, int l, int p) {
//		ernum = e;
//		line = l;
//		position = p;
//		}*/
//
//		LEX Analize(In::IN in, Log::LOG log) {
//			char* templex = new char[255];					//лексема
//			char* tempid = new char[10];					//имя переменной
//			char* tempval = new char[255];					//значение переменной
//			char* prefix = new char[5];						//текущий префикс
//			char* subprefix = new char[5];					//буфернвй префикс
//			char* tempprefix = new char[5];					//префикс функции, в который сейчас
//			LEX ret;
//
//			int size_of_lex_str = 0, line = 0;				//текущая длина лексемы/ номер строки
//			int numb_of_lit = 0;							//текущий нмоер лексемы
//			int position = -1;								//текущая позиция в исходном коде
//
//			bool forFunction = false;						//дли инициализации типа ид в таблице идентификаторов
//			bool fl_for_id = false;							//есть ли перед ид определение (true - есть, false - использование)						
//			bool infunction = false;						//для взятия перфикса (есть ли перед текущей позицией слово function)
//			bool fc = false;								//нахождение в функции
//			bool exitSub = false;							//вышли ли из внутренней функции
//			bool ismain = false;							//есть ли в коде точка входа main
//			bool flerror = false;								//проверка на наличие ошибок
//			ERR_MAS ermas[100], h;							//массив ошибок
//			int erind = 0;									//индексы массива ошибок		
//			for (int i = 0; i < in.size; i++) {
//
//				bool fl = false;
//
//
//				if (in.text[i] == '|')
//				{
//					position = -1;
//					line++;									//номер строки
//					continue;
//				}
//				if (in.text[i] != LEX_SEMICOLON &&
//					in.text[i] != LEX_COMMA &&
//					in.text[i] != LEX_LEFTBRACE &&
//					in.text[i] != LEX_RIGHTBRACE &&
//					in.text[i] != LEX_LEFTHESIS &&
//					in.text[i] != LEX_RIGHTHESIS &&
//					in.text[i] != '|' &&
//					in.text[i] != ' ' &&
//					in.text[i] != '='&&
//					in.text[i] != '+' &&
//					in.text[i] != '-' &&
//					in.text[i] != '*' &&
//					in.text[i] != '/')						//обрывание слова на любом из сепараторов
//				{
//					templex[size_of_lex_str] = in.text[i];
//					size_of_lex_str++;
//				}
//				else {
//					templex[size_of_lex_str] = '\0';		//заканчиваем временное слово
//					size_of_lex_str = 0;					//обнулить новую длину строки
//					if (!fl) {
//						fl = (AddLex(fInteger, templex, LEX_INTEGER, line));			//определение типа данных идентификатора
//						if (fl) {
//							idT.table[idT.size].idxfirstLE = line;
//							idT.table[idT.size].iddatatype = IT::INT;
//							if (lexT.table[lexT.size - 2].lexema == LEX_DECLARE) {
//								idT.table[idT.size].idtype = IT::V;
//								idT.table[idT.size].value.vind = 0;
//							}
//							if (lexT.table[lexT.size - 2].lexema == LEX_LEFTHESIS || lexT.table[lexT.size - 2].lexema == LEX_COMMA)
//								idT.table[idT.size].idtype = IT::P;
//							idT.size++;
//							fl_for_id = true;
//						}
//					}
//					if (!fl) {
//						fl = (AddLex(fString, templex, LEX_STRING, line));
//						if (fl) {
//							idT.table[idT.size].idxfirstLE = line;
//							idT.table[idT.size].iddatatype = IT::STR;
//
//							if (lexT.table[lexT.size - 2].lexema == LEX_DECLARE) {
//								idT.table[idT.size].idtype = IT::V;
//								memset(idT.table[idT.size].value.vstr.str, TI_STRDEFAULT, 225);
//
//							}
//							if (lexT.table[lexT.size - 2].lexema == LEX_LEFTHESIS || lexT.table[lexT.size - 2].lexema == LEX_COMMA)
//								idT.table[idT.size].idtype = IT::P;
//							idT.table[idT.size].value.vstr.str[0] = NULL;
//							idT.size++;
//							fl_for_id = true;
//						}
//					}
//					if (!fl) {
//						fl = (AddLex(fMain, templex, LEX_MAIN, line));
//						if (fl) {
//							ismain = true;
//							forFunction = true;
//							infunction = true;
//							strncpy(prefix, templex, 5);
//							prefix[5] = '\0';
//							infunction = false;
//							strcpy(tempprefix, prefix);
//
//							lexT.table[lexT.size - 1].sn--;								//не трогать. перенос строки для скобки посде main
//						}
//					}
//					if (!fl) {
//						fl = (AddLex(fDeclare, templex, LEX_DECLARE, line));
//					}
//					if (!fl) {
//						fl = (AddLex(fFunction, templex, LEX_FUNCTION, line));
//						if (fl) {
//							forFunction = true;										//для определение типа идетификатора
//							infunction = true;										//для взятия префикса
//							if (fc)													//для определение нахождения текущей функции(внутренняя или внешняя)
//								exitSub = true;
//						}
//					}
//					if (!fl) {
//						fl = (AddLex(fReturn, templex, LEX_RETURN, line));
//					}
//					if (!fl) {
//						fl = (AddLex(fPrint, templex, LEX_PRINT, line));
//					}
//					if (!fl) {
//						fl = (AddLex(fIdent, templex, LEX_ID, line));
//						if (fl) {
//							if (strlen(templex) > 5) {
//								strncpy(tempid, templex, 5);
//								tempid[5] = '\0';
//							}
//							else
//								strcpy(tempid, templex);
//
//							if (exitSub && infunction) {
//								strcpy(subprefix, prefix);										   //создание буферного префикса
//							}
//							if (forFunction)
//							{
//								idT.table[idT.size - 1].idtype = IT::F;							   //в табилце ид значение функции
//								forFunction = false;
//							}
//
//							if (!infunction && !exitSub)
//							{
//								strcpy(prefix, tempprefix);										   //замена префикса после субфункции
//							}
//
//							if (!infunction && !fl_for_id && strlen(prefix) <= 5)
//							{
//								strcpy(prefix, tempprefix);											//не трогать. замена префикса
//							}
//
//							if (infunction)
//							{														//создание префикса, если есть флаг на функию
//								strcpy(prefix, tempid);
//								if (!exitSub)
//									strcpy(tempprefix, tempid);
//								prefix[5] = '\0';
//								infunction = false;
//							}
//							templex[5] = '\0';
//
//							int d = IT::IsId(idT, tempid);
//							if (d != -1)																						//содание ссылки на функцию
//							{
//								idT.table[idT.size] = idT.table[d];
//								idT.size++;
//
//							}
//
//							if (!fl_for_id)
//							{
//								strcpy(idT.table[idT.size].id, prefix);
//								strncpy(idT.table[idT.size].id + strlen(prefix), templex, 5);
//								int d = IT::IsId(idT, idT.table[idT.size].id);
//								if (d != -1) {																				//создание ссылки на идентификатор
//									idT.table[idT.size] = idT.table[d];
//									lexT.table[i].idxTI = idT.size;
//									idT.size++;
//								}
//								/*	else {
//								h.ernum = 122;
//								h.line = line;
//								h.position = position;
//								ermas[erind++] = h;
//								flerror = true;
//								}*/
//								//	throw ERROR_THROW_IN(122,line,position);												//тут сделать ошибку на не определенный идентификатор
//
//							}
//							if (fl_for_id) {
//								if (lexT.table[lexT.size - 2].lexema != LEX_FUNCTION) {
//									strcpy(idT.table[idT.size - 1].id, prefix);
//									strncpy(idT.table[idT.size - 1].id + strlen(idT.table[idT.size - 1].id), templex, 5);		//имя ид для идентификатора
//								}
//								else
//								{
//									strcpy(idT.table[idT.size - 1].id, prefix);													//имя ид для функции
//								}
//								int d = IT::IsDublId(idT, idT.table[idT.size - 1].id);
//								if (d != TI_NULLIDX) {
//									h.ernum = 120;
//									h.line = line;
//									h.position = position;
//									ermas[erind++] = h;
//									flerror = true;
//
//								}
//								//ERROR_THROW_IN(120, line, position);													//проверка на дублирование идентификатора
//								fl_for_id = false;
//							}
//						}
//					}
//					if (!fl) {
//						fl = (AddLex(fIntLit, templex, LEX_LITERAL, line));
//						if (fl) {
//							memset(tempval, '\0', 255);
//							for (int i = 0; i < strlen(templex); i++) {
//								tempval[i] = templex[i];
//							}
//							int i = IT::checkId(idT, atoi(tempval));
//							if (i != TI_NULLIDX) {										//создание ссылки на литерал
//								idT.table[idT.size] = idT.table[i];
//								idT.size++;
//							}
//							else {
//								idT.table[idT.size].iddatatype = IT::INT;
//								idT.table[idT.size].idtype = IT::L;
//								idT.table[idT.size].idxfirstLE = line;
//								idT.table[idT.size].value.vind = atoi(tempval);
//								tempval[0] = 'L';
//								tempval[1] = (char)numb_of_lit + 0x30;
//								strcpy(idT.table[idT.size].id, tempval);
//								numb_of_lit++;									//инкремента номера литерала
//								idT.size++;
//							}
//						}
//					}
//					memset(templex, '\0', 255);												//обнуление 
//				}
//				if (in.text[i] == LEX_SEMICOLON || in.text[i] == LEX_LEFTHESIS ||			//создание лексем для всяких там скобок и прочей херни
//					in.text[i] == LEX_RIGHTHESIS || in.text[i] == LEX_LEFTBRACE ||
//					in.text[i] == LEX_RIGHTBRACE || in.text[i] == LEX_COMMA)
//				{
//					int fl = false;
//					templex[0] = in.text[i];
//					templex[1] = '\0';
//					if (!fl)
//					{
//						fl = AddLex(fSemicolon, templex, LEX_SEMICOLON, line);
//						if (fl)
//							exitSub = false;
//					}
//					if (!fl)
//					{
//						fl = AddLex(fLeftBrace, templex, LEX_LEFTBRACE, line);
//						if (fl)
//							fc = true;
//					}
//					if (!fl)
//					{
//						fl = AddLex(fRightBrace, templex, LEX_RIGHTBRACE, line);				//закрывает флаг на функцию
//						if (fl) {
//							fc = false;
//							memset(prefix, '\0', 5);
//						}
//					}
//					if (!fl)
//					{
//						fl = AddLex(fComma, templex, LEX_COMMA, line);
//					}
//					if (!fl)
//					{
//						fl = AddLex(fLeftThesis, templex, LEX_LEFTHESIS, line);
//					}
//					if (!fl)
//					{
//						fl = AddLex(fRightThesis, templex, LEX_RIGHTHESIS, line);				//закрывает флаг на субфункцию
//						if (fl)
//							exitSub = false;
//					}
//				}
//				if (in.text[i] == '-' || in.text[i] == '+' || in.text[i] == '/' ||			//создание лексемы для знаков
//					in.text[i] == '*' || in.text[i] == '=') {
//					templex[0] = in.text[i];
//					templex[1] = '\0';
//					bool fl = false;
//					if (!fl)
//						fl = AddLex(fV, templex, 'v', line);
//					LT::Entry e;
//					if (in.text[i] == '=') {
//						e.lexema = '=';
//						e.idxTI = -1;
//						e.sn = line;
//						LT::Add(lexT, e);
//						fl = true;
//
//					}
//					else {
//						idT.table[idT.size].idxfirstLE = line;
//						idT.table[idT.size].iddatatype = IT::OPR;
//						idT.table[idT.size].idtype = IT::O;
//						idT.table[idT.size].id[0] = templex[0];
//						idT.table[idT.size].id[1] = '\0';
//						idT.size++;
//					}
//				}
//				if (in.text[i] == '\'') {
//					templex[size_of_lex_str] = in.text[i++];								//записывает строку между кавычками
//					while (in.text[i] != '\'') {
//						templex[size_of_lex_str++] = in.text[i++];
//					}
//					templex[size_of_lex_str++] = '\'';
//					templex[size_of_lex_str++] = '\0';
//					if (!fl)
//						fl = AddLex(fStringLiteral, templex, LEX_LITERAL, line);
//					if (fl) {
//						int d = IT::checkId(idT, templex);
//						if (d != -1) {
//							idT.table[idT.size] = idT.table[d];
//							idT.size++;
//						}
//						else {
//							memset(idT.table[idT.size].value.vstr.str, '\0', 255);
//							idT.table[idT.size].iddatatype = IT::STR;
//							idT.table[idT.size].idtype = IT::L;
//							idT.table[idT.size].idxfirstLE = line;
//							for (int i = 0; i < strlen(templex); i++) {
//								idT.table[idT.size].value.vstr.str[i] = templex[i];
//							}
//							idT.table[idT.size].value.vstr.len = size_of_lex_str - 1;
//							tempval[0] = 'L';
//							tempval[1] = (char)numb_of_lit + 0x30;
//							tempval[2] = '\0';
//							strcpy(idT.table[idT.size].id, tempval);
//							numb_of_lit++;
//							idT.size++;
//						}
//					}
//				}
//				position++;				//инкремента теукущей позиции
//
//
//			}
//			if (!ismain) {
//				h.ernum = 121;
//				h.line = -1;
//				h.position = -1;
//				ermas[erind++] = h;
//				flerror = true;
//
//
//
//			}
//			if (flerror) {
//				std::cout << "Были обнаружены ошибки.\nПодробнее в журнале log.\n";
//				for (int i = 0; i < erind; i++) {
//					Error::ERROR e;
//					e = ERROR_THROW_IN(ermas[i].ernum, ermas[i].line, ermas[i].position);
//					Log::WriteError(log, e);
//
//
//				}
//			}
//			else {
//				int indT = 0;
//				for (int i = 0; i < lexT.size; i++) {
//					if (lexT.table[i].lexema == 'i' || lexT.table[i].lexema == 'v' || lexT.table[i].lexema == 'l') {				//связывание аблицы лексем и идентификаторов
//						lexT.table[i].idxTI = indT;
//						indT++;
//					}
//
//
//
//				}
//				PN::pn(lexT, idT);													//вызов польской нотации
//				int k = 0;
//				*(log.stream) << "\n\n0: ";
//				for (int i = 0; i < lexT.size; i++) {
//					if (lexT.table[i].sn != k) {
//						*(log.stream) << "\n" << lexT.table[i].sn << ": ";
//
//						k = lexT.table[i].sn;
//						*(log.stream) << lexT.table[i].lexema;
//
//					}
//					else
//						*(log.stream) << lexT.table[i].lexema;
//				}
//
//				/*for (int i = 0; i < lexT.size; i++)
//				if(lexT.table[i].idxTI!=-1)
//				std::cout << "\n" << lexT.table[i].lexema << "   "<<idT.table[lexT.table[i].idxTI].id<<" " << lexT.table[i].idxTI;
//				*/
//				//for (int i = 0; i < idT.size; i++) {
//				//	std::cout << "\n\nИдентификатор №" << i << ": " << idT.table[i].id;
//				//	//std::cout << "\nНомер в таблице идентификаторов: " << lexT.table[i].idxTI;
//				//	std::cout << "\nСтрока: " << idT.table[i].idxfirstLE;
//				//	if (idT.table[i].iddatatype == IT::INT)
//				//		std::cout << "\nТип данных: integer";
//				//	else if (idT.table[i].iddatatype == IT::STR)
//				//		std::cout << "\nТип данных: string";
//				//	else
//				//		std::cout << "\nТип данных: operator";
//				//	if (idT.table[i].idtype == IT::F)
//				//		std::cout << "\nТип ид: F";
//				//	else if (idT.table[i].idtype == IT::V)
//				//		std::cout << "\nТип ид: V";
//				//	else if (idT.table[i].idtype == IT::P)
//				//		std::cout << "\nТип ид: P";
//				//	else if (idT.table[i].idtype == IT::L)
//				//		std::cout << "\nТип ид: L";
//				//	else
//				//		std::cout << "\nТип ид: O";
//
//				//	if ((idT.table[i].iddatatype == IT::INT && idT.table[i].idtype == IT::V) ||
//				//		(idT.table[i].iddatatype == IT::INT && idT.table[i].idtype == IT::L))
//				//		std::cout << "\nЗначение: " << idT.table[i].value.vind;
//				//	else if ((idT.table[i].iddatatype == IT::STR && idT.table[i].idtype == IT::V) ||
//				//		(idT.table[i].iddatatype == IT::STR && idT.table[i].idtype == IT::L))
//				//	{
//				//		if (idT.table[i].value.vstr.str[0] == NULL)
//				//			std::cout << "\nСтрока: NULL";
//				//		else {
//				//			std::cout << "\nСтрока: " << idT.table[i].value.vstr.str;
//				//			std::cout << "\nДлина строки: " << idT.table[i].value.vstr.len;
//				//		}
//				//	}
//				//}
//			}
//			return;
//		}
//	}
//
//}