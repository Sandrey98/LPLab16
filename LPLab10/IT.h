#pragma once

#define ID_MAXSIZE		10			//������������ ���-�� �������� � ��������������
#define TI_MAXSIZE		4096		//������������ ���-�� ����� � ��������������
#define TI_INT_DEFAULT	0x00000000	//�������� �� ��������� ��� ���� integer
#define TI_STRDEFAULT	0x00		//�������� �� ��������� ��� ���� string
#define TI_NULLIDX		0xffffffff	//��� �������� ������� ���������������
#define TI_STR_MAXSIZE	225	
#include "LT.h"
namespace IT
{
	enum IDDATATYPE { INT = 1, STR = 2, OPR=3};
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, O = 5 };   //����������, �������, �������� �������, �������

	struct Entry
	{
		int			idxfirstLE;			//������ ������ ������ � ������� ������
		char		id[ID_MAXSIZE];		//�������������	(�������������� ��������� �� ID_MAXSIZE)
		IDDATATYPE	iddatatype;			//��� ������
		IDTYPE		idtype;				//��� ��������������
		union
		{
			int vind;				//�������� integer
			struct {
				int len;						//����� string
				char str[TI_STR_MAXSIZE];		//������� string
			} vstr;								//�������� string
		}value;				//�������� ��������������
	};

	struct IdTable				//��������� ������� ���������������
	{
		int maxsize;							//������� ������� ��������������� < TI_MAXSIZE
		int size;								//������� ������ ������� ��������������� < maxsize
		Entry* table;							//������ ����� ������� ���������������
	};
	IdTable Create(								//������� ������� ���������������
		int size								//������� ������� ���������������
		);
	void Add(									//�������� ������ � ������� ���������������
		IdTable& idtable,					//��������� ������� ���������������
		Entry entry							//������ ������� ���������������
		);
	Entry GetEntry(							//�������� ������ ������� ���������������
		IdTable& idtable,				//��������� ������� ���������������
		int n							//����� ���������� ������
		);
	int IsId(							//�������: ����� ������(���� ����), TI_NULLIDX(���� ���)
		IdTable& idtable,				//��������� ������� ���������������
		char id[ID_MAXSIZE]				//�������������
		);
	void Delete(IdTable& idtable);
	int checkId(IdTable& idtable, char value[ID_MAXSIZE]);
	int IsDublId(IdTable& idtable, char id[ID_MAXSIZE]); //�������� �� ����������� ��

	int checkId(IdTable& idtable, int value);//������� ������� ������
};


//while (a[k] != '\0'&&a[k] != '=')
//{
//	/* ���� ���p����� ������ - ')' */
//	if (a[k] == ')')
//		/* �� ����������� �� ����� � �������� ��p��� */
//	{
//		/* ��� ����� ���p���� �� ��������� */
//		while ((OPERS->c) != '(')
//			/* ���p������� ������ */
//			outstring[point++] = DEL(&OPERS);
//		/* ������� �� ����� ���� ���p������� ������ */
//		DEL(&OPERS);
//	}
//	/* ���� ���p����� ������ - ����� , �� */
//	if (a[k] >= 'a'&&a[k] <= 'z')
//		/* ��p��������� � � �������� ��p��� */
//		outstring[point++] = a[k];
//	/* ���� ���p����� ������ - '(' , �� */
//	if (a[k] == '(')
//		/* ����������� � � ���� */
//		OPERS = push(OPERS, '(');
//	if (a[k] == '+' || a[k] == '-' || a[k] == '/' || a[k] == '*')
//		/* ���� ��������� ������ - ���� ���p���� , ��: */
//	{
//		/* ���� ���� ���� */
//		if (OPERS == NULL)
//			/* ���������� � ���� ���p���� */
//			OPERS = push(OPERS, a[k]);
//		/* ���� �� ���� */
//		else
//			/* ���� �p��p���� ����������� ���p���� ������
//			�p��p����� ���p���� �� ��p���� ����� */
//			if (PRIOR(OPERS->c)<PRIOR(a[k]))
//				/* ����������� ����������� ���p���� �� ���� */
//				OPERS = push(OPERS, a[k]);
//		/* ���� �p��p���� ������ */
//			else
//			{
//				while ((OPERS != NULL) && (PRIOR(OPERS->c) >= PRIOR(a[k])))
//					/* ��p��������� � �������� ��p��� ��� ���p����
//					� ������� ��� p����� �p��p������ */
//					outstring[point++] = DEL(&OPERS);
//				/* ���������� � ���� �����������  ���p���� */
//				OPERS = push(OPERS, a[k]);
//			}
//	}
//	/* ��p���� � ���������� ������� ������� ��p��� */
//	k++;
//}
///* ����� p������p���� ����� ��p������ */
//while (OPERS != NULL)
///* ��p��������� ��� ���p���� �� */
//outstring[point++] = DEL(&OPERS);
///* ����� � �������� ��p��� */
//outstring[point] = '\0';
///* � �������� � */
//printf("\n%s\n", outstring);
//fflush(stdin);
//puts("\n�����p���(y/n)?");
//  } while (getchar() != 'n');
//}
