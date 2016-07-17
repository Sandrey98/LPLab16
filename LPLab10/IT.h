#pragma once

#define ID_MAXSIZE		10			//максимальное кол-во символов в идентификаторе
#define TI_MAXSIZE		4096		//максимальное кол-во строк в идентификаторе
#define TI_INT_DEFAULT	0x00000000	//значение по умолчанию для типа integer
#define TI_STRDEFAULT	0x00		//значение по умолчанию для типа string
#define TI_NULLIDX		0xffffffff	//нет элемента таблицы идентификаторов
#define TI_STR_MAXSIZE	225	
#include "LT.h"
namespace IT
{
	enum IDDATATYPE { INT = 1, STR = 2, OPR=3};
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, O = 5 };   //переменная, функция, параметр функции, литерал

	struct Entry
	{
		int			idxfirstLE;			//индекс первой строки в таблице лексем
		char		id[ID_MAXSIZE];		//идентификатор	(автоматические усекается до ID_MAXSIZE)
		IDDATATYPE	iddatatype;			//тип данных
		IDTYPE		idtype;				//тип идентификатора
		union
		{
			int vind;				//значение integer
			struct {
				int len;						//длина string
				char str[TI_STR_MAXSIZE];		//символы string
			} vstr;								//значение string
		}value;				//значение идентификатора
	};

	struct IdTable				//экземпляр таблицы идентификаторов
	{
		int maxsize;							//емкость таблицы идентификаторов < TI_MAXSIZE
		int size;								//текущий размер таблицы идентификаторов < maxsize
		Entry* table;							//массив строк таблицы идентификаторов
	};
	IdTable Create(								//создать таблицу идентификаторов
		int size								//емкость таблицы идентификаторов
		);
	void Add(									//добавить строку в таблицу идентификаторов
		IdTable& idtable,					//экземпляр таблицы идентификаторов
		Entry entry							//строка таблицы идентификаторов
		);
	Entry GetEntry(							//получить строку таблицы идентификаторов
		IdTable& idtable,				//экземпляр таблицы идентификаторов
		int n							//номер получаемой строки
		);
	int IsId(							//возврат: номер строки(если есть), TI_NULLIDX(если нет)
		IdTable& idtable,				//экземпляр таблицы идентификаторов
		char id[ID_MAXSIZE]				//идентафикатор
		);
	void Delete(IdTable& idtable);
	int checkId(IdTable& idtable, char value[ID_MAXSIZE]);
	int IsDublId(IdTable& idtable, char id[ID_MAXSIZE]); //проверка на дублирвание ид

	int checkId(IdTable& idtable, int value);//удалить таблицу лексем
};


//while (a[k] != '\0'&&a[k] != '=')
//{
//	/* Если очеpедной символ - ')' */
//	if (a[k] == ')')
//		/* то выталкиваем из стека в выходную стpоку */
//	{
//		/* все знаки опеpаций до ближайшей */
//		while ((OPERS->c) != '(')
//			/* откpывающей скобки */
//			outstring[point++] = DEL(&OPERS);
//		/* Удаляем из стека саму откpывающую скобку */
//		DEL(&OPERS);
//	}
//	/* Если очеpедной символ - буква , то */
//	if (a[k] >= 'a'&&a[k] <= 'z')
//		/* пеpеписываем её в выходную стpоку */
//		outstring[point++] = a[k];
//	/* Если очеpедной символ - '(' , то */
//	if (a[k] == '(')
//		/* заталкиваем её в стек */
//		OPERS = push(OPERS, '(');
//	if (a[k] == '+' || a[k] == '-' || a[k] == '/' || a[k] == '*')
//		/* Если следующий символ - знак опеpации , то: */
//	{
//		/* если стек пуст */
//		if (OPERS == NULL)
//			/* записываем в него опеpацию */
//			OPERS = push(OPERS, a[k]);
//		/* если не пуст */
//		else
//			/* если пpиоpитет поступившей опеpации больше
//			пpиоpитета опеpации на веpшине стека */
//			if (PRIOR(OPERS->c)<PRIOR(a[k]))
//				/* заталкиваем поступившую опеpацию на стек */
//				OPERS = push(OPERS, a[k]);
//		/* если пpиоpитет меньше */
//			else
//			{
//				while ((OPERS != NULL) && (PRIOR(OPERS->c) >= PRIOR(a[k])))
//					/* пеpеписываем в выходную стpоку все опеpации
//					с большим или pавным пpиоpитетом */
//					outstring[point++] = DEL(&OPERS);
//				/* записываем в стек поступившую  опеpацию */
//				OPERS = push(OPERS, a[k]);
//			}
//	}
//	/* Пеpеход к следующему символу входной стpоки */
//	k++;
//}
///* после pассмотpения всего выpажения */
//while (OPERS != NULL)
///* Пеpеписываем все опеpации из */
//outstring[point++] = DEL(&OPERS);
///* стека в выходную стpоку */
//outstring[point] = '\0';
///* и печатаем её */
//printf("\n%s\n", outstring);
//fflush(stdin);
//puts("\nПовтоpить(y/n)?");
//  } while (getchar() != 'n');
//}
