//*****************************************************
//
// Q[[game.cpp]
// Author:ûüRç
//
//*****************************************************

//*****************************************************
// CN[h
//*****************************************************
#include "manager.h"
#include "game.h"
#include "object.h"
#include "inputkeyboard.h"
#include "inputManager.h"
#include "fade.h"
#include "camera.h"
#include "sound.h"
#include "scene.h"
#include "debugproc.h"
#include <stdio.h>
#include "UIManager.h"
#include "object3D.h"
#include "texture.h"
#include "skybox.h"
#include "block.h"
#include "renderer.h"
#include "animEffect3D.h"
#include "pause.h"
#include "player.h"
#include "slow.h"
#include "blockManager.h"
#include "meshfield.h"
#include "cameraBehavior.h"
#include "particle.h"
#include "flower.h"

//*****************************************************
// }Nè`
//*****************************************************
#define TRANS_TIME	(300)	// I¹ÜÅÌ]CÌt[

//*****************************************************
// ÃIoÏé¾
//*****************************************************
CGame::STATE CGame::m_state = STATE_NONE;	// óÔ
CGame *CGame::m_pGame = nullptr;	// ©gÌ|C^

//=====================================================
// RXgN^
//=====================================================
CGame::CGame()
{
	m_nAddReward = 0;
	m_nCntState = 0;
	m_bStop = false;
}

//=====================================================
// ú»
//=====================================================
HRESULT CGame::Init(void)
{
	m_pGame = this;

	m_state = STATE_NORMAL;
	m_bStop = false;

	// UI}l[W[ÌÇÁ
	CUIManager::Create();

	// XJC{bNXÌ¶¬
	CSkybox::Create();

	// RDAj[VÇÌ¶¬
	CAnimEffect3D::Create();

	Sound::Play(CSound::LABEL_BGM_GAME);

	// tHOð©¯é
	CRenderer *pRenderer = CRenderer::GetInstance();

	if (pRenderer != nullptr)
	{
		pRenderer->EnableFog(true);
	}

	// vC[Ì¶¬
	CPlayer::Create();

	// X[ÇÌ¶¬
	CSlow::Create();

	// bVtB[h¶¬
	CMeshField::Create();

	D3DXVECTOR3 aPos[4] =
	{
		{0.0f,0.0f,15000.0f},
		{22000.0f,0.0f,0.0f},
		{0.0f,0.0f,-15000.0f},
		{-7000.0f,0.0f,0.0f},
	};
	D3DXVECTOR3 aRot[4] =
	{
		{0.0f,0.0f,0.0f},
		{0.0f,D3DX_PI * 0.5f,0.0f},
		{0.0f,D3DX_PI,0.0f},
		{0.0f,-D3DX_PI * 0.5f,0.0f},
	};

	CFlower::Create();

	return S_OK;
}

//=====================================================
// I¹
//=====================================================
void CGame::Uninit(void)
{
	// IuWFNgSü
	CObject::ReleaseAll();

	m_pGame = nullptr;
}

//=====================================================
// XV
//=====================================================
void CGame::Update(void)
{
	CFade *pFade = CFade::GetInstance();
	CInputManager *pInputManager = CInputManager::GetInstance();
	CSound* pSound = CSound::GetInstance();

	if (m_bStop == false)
	{
		// V[ÌXV
		CScene::Update();

		//CParticle::Create(D3DXVECTOR3(0.0f,0.0f,0.0f), CParticle::TYPE::TYPE_BEAM_BLADE);

		// J[\ðSÉÅè
		SetCursorPos((int)(SCREEN_WIDTH * 0.5f), (int)(SCREEN_HEIGHT * 0.5f));
	}
	else
	{
		// â~µÈ¢IuWFNgÌXV
		CObject::UpdateNotStop();
	}

	// JXV
	UpdateCamera();

	// óÔÇ
	ManageState();

//#ifdef _DEBUG
	Debug();
//#endif
}

//=====================================================
// JÌXV
//=====================================================
void CGame::UpdateCamera(void)
{
	CCamera *pCamera = CManager::GetCamera();

	if (pCamera == nullptr)
	{
		return;
	}

	pCamera->Update();
	pCamera->Quake();

	pCamera->MoveDist(0.3f);
}

//=====================================================
// óÔÇ
//=====================================================
void CGame::ManageState(void)
{
	CFade *pFade = CFade::GetInstance();

	switch (m_state)
	{
	case CGame::STATE_NORMAL:
		break;

		break;
	case CGame::STATE_END:

		m_nCntState++;

		if (m_nCntState >= TRANS_TIME && pFade != nullptr)
		{
			pFade->SetFade(CScene::MODE_TITLE);
		}

		break;
	default:
		break;
	}
}

//=====================================================
// CxgJÌÝè
//=====================================================
void CGame::SetEventCamera(float fTime, D3DXVECTOR3 posRDest, D3DXVECTOR3 posVDest)
{
	CCamera *pCamera = CManager::GetCamera();

	if (pCamera != nullptr)
	{
		pCamera->SetEventTimer(fTime);
		pCamera->SetPosRDest(posRDest);
		pCamera->SetPosVDest(posVDest);

		EnableStop(true);
	}
}

//=====================================================
// fobO
//=====================================================
void CGame::Debug(void)
{
	// üÍæ¾
	CInputKeyboard *pKeyboard = CInputKeyboard::GetInstance();

	if (pKeyboard == nullptr)
	{
		return;
	}

	if (pKeyboard->GetTrigger(DIK_F))
	{
		m_bStop = m_bStop ? false : true;

		if (m_bStop)
		{
			Camera::ChangeBehavior(new CMoveControl);
		}
		else
		{
			Camera::ChangeBehavior(new CFollowPlayer);
		}
	}
}

//=====================================================
// `æ
//=====================================================
void CGame::Draw(void)
{
#ifndef _DEBUG

	return;

#endif

	CDebugProc *pDebugProc = CDebugProc::GetInstance();

	if (pDebugProc == nullptr)
	{
		return;
	}

	char *apString[STATE::STATE_MAX] =
	{
		"NONE",
		"NORMAL",
		"END",
	};

	pDebugProc->Print("\nQ[ÌóÔ[%s]\n", apString[m_state]);
	pDebugProc->Print("â~[%d]\n", m_bStop);
}