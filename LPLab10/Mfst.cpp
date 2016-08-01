#include "stdafx.h"
#include "Mfst.h"
#include "LAxAnalize.h"
#define COD(x) lex_to_lenta(x)
GRBALPHABET lex_to_lenta(char t) {
	using namespace  GRB;
	{
		if (Rule::Chain::isT(t))
			return Rule::Chain::T(t);
		else 
			if(Rule::Chain::isN(t))
			return Rule::Chain::N(t);
			else return 0;
	}
}
namespace MFST
{
	MfstState::MfstState(short pposition, MFSTSTSTACK pst, short pnrulechain) {
		lenta_position = pposition;
		st = pst;
		nrulechain = pnrulechain;	
	}
	MfstState::MfstState() {
		lenta_position = 0;
		nrulechain = -1;
		
	
	}
	Mfst::MfstDiagnosis::MfstDiagnosis(short plenta_position, RC_STEP prc_step, short pnrule, short pnrule_chain)
	{
		lenta_position = plenta_position;
		rc_step = prc_step;
		nrule_chain = pnrule_chain;
		nrule = pnrule;
		
	}
	Mfst::MfstDiagnosis::MfstDiagnosis() 
	{
		lenta_position = -1;
		nrule_chain = -1;
		nrule = -1;
		rc_step = SURPRISE;
	
	}
	
	Mfst::Mfst() {
		lenta_position = 0;
		lenta_size = 0;
		lenta = NULL;

	
	}
	Mfst::Mfst(LA::LEX plex, GRB::Greibach pgrebach) {
		lex = plex;
		grebach = pgrebach;
		lenta = new GRBALPHABET[lex.lextable.size];
		lenta_size = lex.lextable.size;
		for (int i = 0; i < lenta_size; i++)
			lenta[i] = COD(lex.lextable.table[i].lexema);
		lenta_position = 0;
		st.push(grebach.stbottomT);
		st.push(grebach.startN);
		nrulechain = -1;
	}
	
	char* Mfst::getCSt(char* buf) {
		for (int i = st.size()-1, j=0; i>=0; --i,j++)
		{
			buf[j] = GRB::Rule::Chain::alphabet_to_char(st._Get_container()[i]);
		}
		buf[st.size()] = '\0';
		return buf;
	
	
	}
	char* Mfst::getCLenta(char* buf, short pos, short n)
	{
		int end;														//конец на ленте
		if ((pos + n) < lenta_size)										//если норм, то конец на pos+n
			end = pos + n;
		else
			end = lenta_size;											//если превышает, то на конце ленты
		for (int i = pos, j=0; i < end; i++,j++)
		{
			buf[j] = GRB::Rule::Chain::alphabet_to_char(lenta[i]);
		}
		buf[end] = '\0';
		return buf;
	}
/*--*/char* getDiagnosis(short n, char* buf) 
	{

		return buf;
	}
	bool Mfst::saveState() {

		storestate.push(MfstState(lenta_position, st, nrulechain));	//сохраняет текущее положение мпка в стек ка
		return true;
	}


}