#pragma once
#include <stack>
#include "LAxAnalize.h"
#include "Greibach.h"
#define MFST_DIAGN_NUMBER 3
typedef std::stack<short> MFSTSTSTACK;
namespace MFST
{
	struct MfstState 
	{
		short lenta_posotion;
		short nrulechain;
		MFSTSTSTACK st;
		MfstState();
		MfstState(short pposition, MFSTSTSTACK pst, short pnrulechain);
	};
	struct Mfst 
	{
		enum RC_STEP {					//код возврата функции step
						NS_OK,			//найдено правило и цепочка, цепочка записана в стек
						NS_NORULE,		//не найдено прввило грамматики(ошибка в грамматике)
						NS_NORULECHAIN,	//не найдена подходящая цепочка правила(ошибка в исходном коде)
						NS_ERROR,		//неизвестный нетерминальный символ грамматики
						TS_OK,			//тек. символ ленты == вершине стека, продвиналась лента, pop(0) стека
						TS_NOK,			//тек. символ ленты != вершине стек, восстановлено расстояние 
						LENTA_END,		//текущая позиция ленты >= lenta_size
						SURPRISE		//деожиданно код возврата (ошибка в step)
		};
		struct MfstDiagnosis
		{
			short lenta_position;
			RC_STEP rc_step;
			short nrule;
			short nrule_chain;
			MfstDiagnosis();
			MfstDiagnosis(short plenta_position, RC_STEP prc_step, short pnrule,  short pnrule_chain);
		}diagnosis[MFST_DIAGN_NUMBER];
		GRBALPHABET* lenta;
		short lenta_position;
		short nrule;
		short nrulechain;
		short lenta_size;
		GRB::Greibach grebach;
		LA::LEX lex;
		MFSTSTSTACK st;
		std::stack<MfstState> storestate;
		Mfst();
		Mfst(LA::LEX plex,GRB::Greibach pgrebach);
		char* getCSt(char* buf);
		char* getCLenta(char* buf, short pos, short n = 25);
		char* getDiagnosis(short n, char* buf);
		bool saveState();
		bool reststate();
		bool push_chain(GRB::Rule::Chain chain);
		RC_STEP step();
		bool savediagnosis(RC_STEP pprc_step);

	};
}