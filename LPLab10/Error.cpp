#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h" 
#include <string.h>
#include "Error.h"
#include <iostream>

namespace Error
{
	//	серии ошибок:	0	-	99	-	системные ошибки
	//	100	-	109	-	ошибки парметров
	//	110	-	119	-	ошибки открытия и	чтения файлов
	//	120 -   200 -	ошибки лексическог анализа
	ERROR errors[ERROR_MAX_ENTRY] = //таблица ошибок
	{
		ERROR_ENTRY(0, "Недопустимый код ошибки"), // код ошибки вне диапазона 0 - ERROR_MAX_ENTRY
		ERROR_ENTRY(1, "Системный сбой"),
		ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Параметр -in должен быть задан"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102),ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "Превышена длина входного параметра"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "Ошибка при открытии файла с исходным кодом (-in)"),
		ERROR_ENTRY(111, "Недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(112, "Ошибка при создании файла протокола(-log)"),
		ERROR_ENTRY(113, "Цепочка не разобрана"),
		ERROR_ENTRY_NODEF(114),
		ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY(120,"Дублирование идентификатора"),
		ERROR_ENTRY(121, "Нет функции main"),
		ERROR_ENTRY(122, "Идентификатор не определен"),
		ERROR_ENTRY_NODEF(123),ERROR_ENTRY_NODEF(124),
		ERROR_ENTRY_NODEF(125),ERROR_ENTRY_NODEF(126),ERROR_ENTRY_NODEF(127),ERROR_ENTRY_NODEF(128),
		ERROR_ENTRY_NODEF(129),
		ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "Неверная структура программы"),
		ERROR_ENTRY(601, "Ошибочный оператор"),
		ERROR_ENTRY(602, "Ошибка в выражении"),
		ERROR_ENTRY(603, "Ошибка в параметрах функции"),
		ERROR_ENTRY(604, "Ошибка в параметрах вызываемой функции"),
		ERROR_ENTRY_NODEF(605),
		ERROR_ENTRY_NODEF(606),ERROR_ENTRY_NODEF(607),ERROR_ENTRY_NODEF(608),ERROR_ENTRY_NODEF(609),
		ERROR_ENTRY_NODEF10(610),ERROR_ENTRY_NODEF10(620),ERROR_ENTRY_NODEF10(630),ERROR_ENTRY_NODEF10(640),
		ERROR_ENTRY_NODEF10(650),ERROR_ENTRY_NODEF10(660),ERROR_ENTRY_NODEF10(670),ERROR_ENTRY_NODEF10(680),
		ERROR_ENTRY_NODEF10(690),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};

	ERROR geterror(int id) {
		
		if ((id > 0) && (id < ERROR_MAX_ENTRY)) {
			/*p.id = id;
			strcpy_s(p.message, "Недопустимый код ошибки");*/
			return errors[id];
		}
		else {
				return errors[0];
			
		}
		/*p.id = id;
		strcpy_s(p.message, "Недопустимый код ошибки");
		return p;

		*/
	}
	ERROR geterrorin(int id, int line = -1, int col = -1) {
		if ((id > 0) && (id < ERROR_MAX_ENTRY)) {
			errors[id].intext.line = line;
			errors[id].intext.col = col;
			return errors[id];
			 
		}
		else {
			errors[0].intext.line = line;
			errors[0].intext.col = col;
			return errors[0];
		}
		/*p.id = id;
		p.intext.col = col;
		p.intext.line = line;
		strcpy_s(p.message, "Недопустимый код ошибки");
		return p;*/
	}
};