#include "StdAfx.h"
#include "uistateform.h"
#include "uiformmgr.h"
#include "uilabel.h"
#include "uitextbutton.h"
#include "gameapp.h"
#include "character.h"
#include "uiprogressbar.h"
#include "commfunc.h"
#include "ChaAttr.h"
#include "procirculate.h"
#include "packetcmd.h"
#include "tools.h"
#include "GuildData.h"
#include "uiboatform.h"
#include "UIBoxForm.h"
using namespace std;
using namespace GUI;
//---------------------------------------------------------------------------
// class CStateMgr
//---------------------------------------------------------------------------
bool CStateMgr::Init()
{
	CFormMgr &mgr = CFormMgr::s_Mgr;

	frmState = _FindForm("frmState");  //���Ա��� 
	if( !frmState )		return false;
	frmState->evtShow = _evtMainShow;
	const auto btnChangeName = dynamic_cast<CTextButton*>(frmState->Find("btnChangeName"));
	if(!btnChangeName)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "btnChangeName");
	btnChangeName->evtMouseClick = _ClickChangeName;
	//frmState �ڵĿؼ��б�
	labStateName  = dynamic_cast<CLabelEx*>(frmState->Find("labStateName"));    
	if( !labStateName )		return Error( g_oLangRec.GetString(45), frmState->GetName(), "labStateName" );
	labStateName->SetIsCenter(true);

	FORM_CONTROL_LOADING_CHECK(labGuildName,frmState,CLabelEx,"preperty.clu","labStateGuid");

	labStateJob  = dynamic_cast<CLabelEx*>(frmState->Find("labStateJob"));    
	if( !labStateJob )		return Error( g_oLangRec.GetString(45), frmState->GetName(), "labStateJob" );

	labStateLevel  = dynamic_cast<CLabelEx*>(frmState->Find("labStateLevel"));    
	if( !labStateLevel)		return Error( g_oLangRec.GetString(45), frmState->GetName(), "labStateLevel" );

	labStatePoint  = dynamic_cast<CLabelEx*>(frmState->Find("labStatePoint"));    
	if( !labStatePoint )	return Error( g_oLangRec.GetString(45), frmState->GetName(), "labStatePoint" );
	
	labSkillPoint  = dynamic_cast<CLabelEx*>(frmState->Find("labSkillPoint"));    
	if( !labSkillPoint )	return Error( g_oLangRec.GetString(45), frmState->GetName(), "labSkillPoint" );

	labFameShow  = dynamic_cast<CLabelEx*>(frmState->Find("labFameShow"));    
	if( !labFameShow )   	return Error( g_oLangRec.GetString(45), frmState->GetName(), "labFameShow" );

	//6��
	btnStr  = dynamic_cast<CTextButton *>(frmState->Find("btnStr"));    
	if( !btnStr )   		return Error( g_oLangRec.GetString(45), frmState->GetName(), "btnStr" );
	btnStr->evtMouseClick = MainMouseDown;

	btnAgi  = dynamic_cast<CTextButton *>(frmState->Find("btnAgi"));    
	if( !btnAgi )			return Error( g_oLangRec.GetString(45), frmState->GetName(), "btnAgi" );
	btnAgi->evtMouseClick = MainMouseDown;

	btnCon  = dynamic_cast<CTextButton *>(frmState->Find("btnCon"));    
	if( !btnCon )			return Error( g_oLangRec.GetString(45), frmState->GetName(), "btnCon" );
	btnCon->evtMouseClick = MainMouseDown;

	btnSta  = dynamic_cast<CTextButton *>(frmState->Find("btnSta"));    
	if( !btnSta )			return Error( g_oLangRec.GetString(45), frmState->GetName(), "btnSta" );
	btnSta->evtMouseClick = MainMouseDown;

	//btnLuk  = dynamic_cast<CTextButton *>(frmState->Find("btnLuk"));    
	//if( !btnLuk )			return Error( "msgui.clu����<%s>���Ҳ����ؼ�<%s>", frmState->GetName(), "btnLuk" );
	//btnLuk->evtMouseClick = MainMouseDown;

	btnDex  = dynamic_cast<CTextButton *>(frmState->Find("btnDex"));    
	if( !btnDex )			return Error( g_oLangRec.GetString(45), frmState->GetName(), "btnDex" );
	btnDex->evtMouseClick = MainMouseDown;

	//frmState�µĽ������ؼ�
	labStateEXP  = dynamic_cast<CLabelEx*>(frmState->Find("labStateEXP"));    
	if( !labStateEXP )
		return Error( g_oLangRec.GetString(45), frmState->GetName(), "labStateEXP" );
	labStateEXP->SetIsCenter(true);

	labStateHP  = dynamic_cast<CLabelEx*>(frmState->Find("labStateHP"));    
	if( !labStateHP )
		return Error( g_oLangRec.GetString(45), frmState->GetName(), "labStateHP" );
	labStateHP->SetIsCenter(true);

	labStateSP  = dynamic_cast<CLabelEx*>(frmState->Find("labStateSP"));    
	if( !labStateSP )
		return Error( g_oLangRec.GetString(45), frmState->GetName(), "labStateSP" );
	labStateSP->SetIsCenter(true);



	//6����������
	labStrshow  = 	( CLabelEx *)frmState->Find( "labStrshow" );
	labDexshow  = 	( CLabelEx *)frmState->Find( "labDexshow" );
	labAgishow  = 	( CLabelEx *)frmState->Find( "labAgishow" );
	labConshow  = 	( CLabelEx *)frmState->Find( "labConshow" );
	labStashow  = 	( CLabelEx *)frmState->Find( "labStashow" );
	//labLukshow  = 	( CLabelEx *)frmState->Find( "labLukshow" );
	labSailLevel  = 	( CLabelEx *)frmState->Find( "labSailLevel" );
	labSailEXP  = 	( CLabelEx *)frmState->Find( "labSailEXP" );

	//8����������
	labMinAtackShow  = 	( CLabelEx *)frmState->Find( "labMinAtackShow" );
	labMaxAtackShow  = 	( CLabelEx *)frmState->Find( "labMaxAtackShow" );
	labFleeShow      = 	( CLabelEx *)frmState->Find( "labFleeShow" );
	labAspeedShow    = 	( CLabelEx *)frmState->Find( "labAspeedShow" );
	labMspeedShow    = 	( CLabelEx *)frmState->Find( "labMspeedShow" );
	labHitShow       = 	( CLabelEx *)frmState->Find( "labHitShow" );
	labDefenceShow   = 	( CLabelEx *)frmState->Find( "labDefenceShow" );
	//labCriticalShow  = 	( CLabelEx *)frmState->Find( "labCriticalShow" );
	//labMfShow        = 	( CLabelEx *)frmState->Find( "labMfShow" );
	labPhysDefineShow=  ( CLabelEx *)frmState->Find( "labPhysDefineShow" );

	//here add custom new labels 
	//RankArenaLabel
	/*if (RankArenaLabel = dynamic_cast<CLabelEx*>(frmState->Find("RankArenaLabel")); !RankArenaLabel)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "RankArenaLabel");
	//ArenaBattle
	if (ArenaBattle = dynamic_cast<CLabelEx*>(frmState->Find("ArenaBattle")); !ArenaBattle)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ArenaBattle");
	//ArenaVictory
	if (ArenaVictory = dynamic_cast<CLabelEx*>(frmState->Find("ArenaVictory")); !ArenaVictory)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ArenaVictory");
	//ArenaKill
	if (ArenaKill = dynamic_cast<CLabelEx*>(frmState->Find("ArenaKill")); !ArenaKill)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ArenaKill");
	//ArenaDeath
	if (ArenaDeath = dynamic_cast<CLabelEx*>(frmState->Find("ArenaDeath")); !ArenaDeath)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ArenaDeath");
	//ArenaPoint
	if (ArenaPoint = dynamic_cast<CLabelEx*>(frmState->Find("ArenaPoint")); !ArenaPoint)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ArenaPoint");
	//ChaosRank
	if (ChaosRank = dynamic_cast<CLabelEx*>(frmState->Find("ChaosRank")); !ChaosRank)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ChaosRank");
	//ChaosBattle
	if (ChaosBattle = dynamic_cast<CLabelEx*>(frmState->Find("ChaosBattle")); !ChaosBattle)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ChaosBattle");
	//ChaosVictory
	if (ChaosVictory = dynamic_cast<CLabelEx*>(frmState->Find("ChaosVictory")); !ChaosVictory)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ChaosVictory");
	//ChaosKill
	if (ChaosKill = dynamic_cast<CLabelEx*>(frmState->Find("ChaosKill")); !ChaosKill)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ChaosKill");
	//ChaosDeath
	if (ChaosDeath = dynamic_cast<CLabelEx*>(frmState->Find("ChaosDeath")); !ChaosDeath)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ChaosDeath");*/
	//ChaosPoint
	if (ChaosPoint = dynamic_cast<CLabelEx*>(frmState->Find("ChaosPoint")); !ChaosPoint)
		return Error(g_oLangRec.GetString(45), frmState->GetName(), "ChaosPoint");
	//add more labels here same way copy past rename name 

	//end of custom labels 

	return true;


}

void CStateMgr::_ClickChangeName(CGuiData* pSender, int x, int y, DWORD key) {
	g_pGameApp->SysInfo("Make Sure you have Change Name Card!");
	if (CCharacter* pMain = CGameScene::GetMainCha(); !pMain->IsPlayer()) {
		g_pGameApp->ShowMidText("You must be in safe zone to use Change Name function ");
		return;
	}
	CBoxMgr::ShowNumberBox(_evtChangeName, -1, "Enter Your New Name:", false);
}
void CStateMgr::_evtChangeName(CCompent* pSender, const int nMsgType, int x, int y, DWORD dwKey) {
	if (nMsgType != static_cast<int>(CForm::eModalResult::mrYes))
		return;

	const auto nameBox = static_cast<stNumBox*>(pSender->GetForm()->GetPointer());
	if (!nameBox)
		return;
	// char* strName;
	std::string strName;
	nameBox->GetString(strName);
	CS_BeginAction(g_stUIBoat.GetHuman(), enumACTION_ChangepName, &strName);
}


void CStateMgr::End()
{
}

void CStateMgr::FrameMove(DWORD dwTime)
{
	if( frmState->GetIsShow() )
	{
		static CTimeWork time(100);
		if( time.IsTimeOut( dwTime ) )
			RefreshStateFrm();
	}
}

void CStateMgr::_evtMainShow(CGuiData *pSender)
{
	g_stUIState.RefreshStateFrm();
}

void CStateMgr::RefreshStateFrm()
{
	CForm * f = g_stUIState.frmState;
	if( !f->GetIsShow() )	return;

	CCharacter* pCha = g_stUIBoat.GetHuman();
	if( !pCha )			return;

	SGameAttr* pCChaAttr = pCha->getGameAttr();
	if (!pCChaAttr )	return;

	char  pszCha[256] = { 0 };

	// Ѫ��
	if (labStateHP)     
	{
		sprintf( pszCha , "%d/%d", pCChaAttr->get(ATTR_HP), pCChaAttr->get(ATTR_MXHP) );
		labStateHP->SetCaption( pszCha );
	}

	// ��Ҿ���
	int num = pCChaAttr->get(ATTR_CEXP);
	int curlev = pCChaAttr->get( ATTR_CLEXP);
	int nextlev = pCChaAttr->get( ATTR_NLEXP);

	int max = nextlev - curlev;
	num = num - curlev;
	if ( num < 0 ) num = 0;


	if ( labStateEXP)
	{
		if (max!=0)
			sprintf( pszCha , "%4.2f%%" , num*100.0f/max );	
		else 
			sprintf( pszCha , "0.00%");

		labStateEXP->SetCaption( pszCha );
	}
	
	// ħ��
	num = pCChaAttr->get(ATTR_SP);
	max = pCChaAttr->get(ATTR_MXSP);
	if (labStateSP)
	{
		sprintf( pszCha, "%d/%d", num, max );
        labStateSP->SetCaption( pszCha );	
	}

	//�������
	if(labStateName)		
	{
		sprintf( pszCha , "%s", pCha->getName());
		labStateName->SetCaption( (const char* ) pszCha) ;
	}

	//����
	if (labGuildName)
	{
		if (CGuildData::GetGuildID())
		{
			labGuildName->SetCaption(CGuildData::GetGuildName().c_str());
		}
		else
		{
			labGuildName->SetCaption("");
		}
	}

	//���ְҵ
	if(labStateJob)			
	{
		sprintf(pszCha,"%s",	g_GetJobName((short)pCChaAttr->get(ATTR_JOB)));
		labStateJob->SetCaption( (const char* ) pszCha);
	}

	//��ҵȼ�
	if(labStateLevel)		
	{
		sprintf( pszCha , "%d", pCChaAttr->get(ATTR_LV));				 //��ʾ��ɫ�ȼ�
		labStateLevel->SetCaption( (const char* ) pszCha);
	}

	//������Ե�
	if(labStatePoint)		
	{
		sprintf( pszCha , "%d", pCChaAttr->get(ATTR_AP) );				//��ʾ��ɫ�����Ե�			
		labStatePoint->SetCaption( (const char* ) pszCha);
	}

	if(labSkillPoint)		
	{
		sprintf( pszCha , "%d", pCChaAttr->get(ATTR_TP));	             //��ʾ��ɫ�ļ��ܵ�		
		labSkillPoint->SetCaption( (const char* ) pszCha);
	}

	//���Ե����0������ʾ6���������԰�ť
	if ( pCChaAttr->get(ATTR_AP)>0  )	
	{
		btnStr->SetIsShow(true);
		btnAgi->SetIsShow(true); 
		btnCon->SetIsShow(true); 
		btnSta->SetIsShow(true); 
		//btnLuk->SetIsShow(true); 
		btnDex->SetIsShow(true);
	}
	else
	{
		btnStr->SetIsShow(false);
		btnAgi->SetIsShow(false); 
		btnCon->SetIsShow(false); 
		btnSta->SetIsShow(false); 
		//btnLuk->SetIsShow(false); 
		btnDex->SetIsShow(false);
	}
	//6����������
	if(labStrshow)		
	{
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_STR));
		labStrshow->SetCaption( (const char* ) pszCha);
	}

	if(labDexshow)		
	{
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_DEX));
		labDexshow->SetCaption( (const char* ) pszCha);
	}

	if(labAgishow)		
	{
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_AGI));
		labAgishow->SetCaption( (const char* ) pszCha);
	}

	if(labConshow)		
	{
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_CON));
		labConshow->SetCaption( (const char* ) pszCha);
	}

	if(labStashow)		
	{
		sprintf( pszCha, "%d" , pCChaAttr->get(ATTR_STA));
		labStashow->SetCaption( (const char* ) pszCha);
	}

	if(labSailLevel)		
	{
		sprintf( pszCha, "%d" , pCChaAttr->get(ATTR_SAILLV));
		labSailLevel->SetCaption( (const char* ) pszCha);
	}

	if(labSailEXP)		
	{
		sprintf( pszCha, "%d" , pCChaAttr->get(ATTR_CSAILEXP));
		labSailEXP->SetCaption( (const char* ) pszCha);
	}

	//sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_LUK));
	//if(labLukshow)		labLukshow->SetCaption( (const char* ) pszCha);

	//8����������
	if(labMinAtackShow)		
	{
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_MNATK));// ��С������		
		labMinAtackShow->SetCaption( (const char* ) pszCha);
	}

	if(labMaxAtackShow)		
	{
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_MXATK));// ��󹥻���
		labMaxAtackShow->SetCaption( (const char* ) pszCha);
	}

	if(labFleeShow)			
	{
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_FLEE)); // ������
		labFleeShow->SetCaption( (const char* ) pszCha);
	}

	if(labAspeedShow)		
	{		
		int v = pCChaAttr->get(ATTR_ASPD);
		if( v==0 )
			sprintf( pszCha , "-1" );
		else
			sprintf( pszCha , "%d" , 100000 / v);// �������

		labAspeedShow->SetCaption( (const char* ) pszCha);
	}
	
	if(labMspeedShow)		
	{		
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_MSPD));
		labMspeedShow->SetCaption( (const char* ) pszCha);
	}

	if(labHitShow)			
	{
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_HIT)); // ������
		labHitShow->SetCaption( (const char* ) pszCha);
	}

	if(labDefenceShow)		
	{
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_DEF)); // ������
		labDefenceShow->SetCaption( (const char* ) pszCha);
	}

	//if(labCriticalShow)		
	//{
	//	sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_CRT)); // ������
	//	labCriticalShow->SetCaption( (const char* ) pszCha);
	//}

	//if(labMfShow)			
	//{
	//	sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_MF));	 // Ѱ����
	//	labMfShow->SetCaption( (const char* ) pszCha);
	//}

	if(labPhysDefineShow)			
	{
		sprintf( pszCha , "%d" , pCChaAttr->get(ATTR_PDEF)); // �����ֿ�
		labPhysDefineShow->SetCaption( (const char* ) pszCha);
	}
	if(labFameShow)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_FAME));	// ����
		labFameShow->SetCaption( (const char* ) pszCha);
	}

	//add custom labels show here 
	//show rank arena label 
	if (RankArenaLabel)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_ARENA_RANK));
		RankArenaLabel->SetCaption((const char*)pszCha);
	}

	if (ArenaBattle)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_ARENA_BATTLE));
		ArenaBattle->SetCaption((const char*)pszCha);
	}

	if (ArenaVictory)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_ARENA_VICTORY));
		ArenaVictory->SetCaption((const char*)pszCha);
	}
	if (ArenaKill)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_ARENA_KILL));
		ArenaKill->SetCaption((const char*)pszCha);
	}
	if (ArenaDeath)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_ARENA_DEATH));
		ArenaDeath->SetCaption((const char*)pszCha);
	}
	if (ArenaPoint)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_ARENA_POINT));
		ArenaPoint->SetCaption((const char*)pszCha);
	}
	if (ChaosRank)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_CHAOS_RANK));
		ChaosRank->SetCaption((const char*)pszCha);
	}
	if (ChaosBattle)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_CHAOS_BATTLE));
		ChaosBattle->SetCaption((const char*)pszCha);
	}
	if (ChaosVictory)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_CHAOS_VICTORY));
		ChaosVictory->SetCaption((const char*)pszCha);
	}
	if (ChaosKill)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_CHAOS_KILL));
		ChaosKill->SetCaption((const char*)pszCha);
	}
	if (ChaosDeath)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_CHAOS_DEATH));
		ChaosDeath->SetCaption((const char*)pszCha);
	}
	if (ChaosPoint)
	{
		sprintf(pszCha, "%d", pCChaAttr->get(ATTR_CHAOS_POINT));
		ChaosPoint->SetCaption((const char*)pszCha);
	}
	//end custom labels 
}

void CStateMgr::MainMouseDown(CGuiData *pSender, int x, int y, DWORD key)
{
	CCharacter* pCha = g_stUIBoat.GetHuman();
	if( !pCha ) return;	        
	
	if ( pCha->getGameAttr()->get(ATTR_AP)<=0  ) return;

	CChaAttr attr;
	attr.ResetChangeFlag();
	
	std::string name = pSender->GetName();
	if (name =="btnStr")
	{	
		attr.DirectSetAttr( ATTR_STR, 1);
		attr.SetChangeBitFlag( ATTR_STR );
		CProCirculateCS* proCir = (CProCirculateCS *)g_NetIF->GetProCir();
		proCir->SynBaseAttribute( &attr );		
	}
	else if (name =="btnAgi")
	{						
		attr.DirectSetAttr( ATTR_AGI, 1);
		attr.SetChangeBitFlag( ATTR_AGI );						
		CProCirculateCS* proCir = (CProCirculateCS *)g_NetIF->GetProCir();
		proCir->SynBaseAttribute( &attr );		
	}
	else if (name =="btnCon")
	{
		attr.DirectSetAttr( ATTR_CON, 1);
		attr.SetChangeBitFlag( ATTR_CON );				
		CProCirculateCS* proCir = (CProCirculateCS *)g_NetIF->GetProCir();
		proCir->SynBaseAttribute( &attr );

	}
	else if (name =="btnSta")
	{
		attr.DirectSetAttr( ATTR_STA, 1);
		attr.SetChangeBitFlag( ATTR_STA );	
		CProCirculateCS* proCir = (CProCirculateCS *)g_NetIF->GetProCir();
		proCir->SynBaseAttribute( &attr );
	}
	//else if (name =="btnLuk")
	//{
	//	attr.DirectSetAttr( ATTR_LUK, 1);
	//	attr.SetChangeBitFlag( ATTR_LUK );		
	//	CProCirculateCS* proCir = (CProCirculateCS *)g_NetIF->GetProCir();
	//	proCir->SynBaseAttribute( &attr );

	//}
	else if (name =="btnDex")
	{
		attr.DirectSetAttr( ATTR_DEX, 1);
		attr.SetChangeBitFlag( ATTR_DEX );			
		CProCirculateCS* proCir = (CProCirculateCS *)g_NetIF->GetProCir();
		proCir->SynBaseAttribute( &attr );
	}
}