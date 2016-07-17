#include "stdafx.h"
#include "Mfst.h"
#include "LAxAnalize.h"
namespace MFST
{
	MfstState::MfstState(short pposition, MFSTSTSTACK pst, short pnrulechain) {
		lenta_posotion = pposition;
		st = pst;
		nrulechain = pnrulechain;	
	}

	Mfst::MfstDiagnosis::MfstDiagnosis(short plenta_position, RC_STEP prc_step, short pnrule, short pnrule_chain)
	{
		lenta_position = plenta_position;
		rc_step = prc_step;
		nrule = pnrule;
		nrule_chain = pnrule_chain;
	}

}