#pragma once
#define LEXEMA_FIXZISE 1        //������������� ������ �������
#define LT_MAXSIZE 4096			//������������ ���-�� ����� � ������� ������
#define LT_TI_NULLIDX 0xffffffff //��� �������� ������� ���������������
#define LEX_INTEGER		't'				//	integer
#define LEX_STRING		't'				//	string
#define LEX_ID			'i'				//	�������������
#define LEX_LITERAL		'l'				//	�������
#define LEX_FUNCTION	'f'				//	�������
#define LEX_DECLARE		'd'				//	declare
#define LEX_RETURN		'r'				//	return
#define LEX_PRINT		'p'				//	print
#define LEX_SEMICOLON	';'				//	;
#define LEX_COMMA		','				//	,
#define LEX_LEFTBRACE	'{'				//	{
#define LEX_RIGHTBRACE	'}'				//	}
#define LEX_LEFTHESIS	'('				//	(
#define LEX_RIGHTHESIS	')'				//	)
#define LEX_PLUS		'v'				//	+
#define LEX_MINUS		'v'				//	-
#define LEX_STAR		'v'				//	*
#define LEX_DIRSLASH	'v'				//  /
#define LEX_MAIN		'm'				//	main
#define LEX_ZAMENA        '@'


namespace LT {								//������� ������
	struct Entry
	{
		char lexema;		//�������
		int sn;								//����� ������ � �������� ����
		int idxTI;							//������ � ������� ��������������� 
	};
	struct LexTable 
	{
		int maxize;							//������� ������� ������ 
		int size;							//������� ������ ������� ������
		Entry* table;						//������ ����� ������� ������	
	};
	
	LexTable Create(						//������� ������
		int size							//�������
		);
	Entry GetEntry(LexTable& lextable,int n);
	Entry Add(								//�������� ������ ������� ������
		LexTable& lextable,					//��������� �������
		Entry entry							//������ ������ ������
		);
	void Delete(LexTable& lextable);	//������� ������� ������
}





