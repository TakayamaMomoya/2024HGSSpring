//*****************************************************
//
// タイマーの処理[timer.cpp]
// Author:��山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "timer.h"
#include "manager.h"
#include "renderer.h"
#include "number.h"
#include "game.h"
#include "result.h"
#include "debugproc.h"
#include "ranking.h"
#include "score.h"
#include "UI.h"
#include "texture.h"

//*****************************************************
// マクロ定義
//*****************************************************
#define NUM_PLACE	(2)	// 桁数
#define INITIAL_TIME	(60)	// 初期の時間

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
CTimer *CTimer::m_pTimer = nullptr;	// 自身のポインタ

//=====================================================
// コンストラクタ
//=====================================================
CTimer::CTimer()
{
	m_pObjMinute = nullptr;
	m_pObjSecond = nullptr;
	m_nSecond = 0;
	m_nCntSecond = 0;
}

//=====================================================
// デストラクタ
//=====================================================
CTimer::~CTimer()
{

}

//=====================================================
// 生成処理
//=====================================================
CTimer *CTimer::Create(void)
{
	if (m_pTimer == nullptr)
	{
		m_pTimer = new CTimer;

		m_pTimer->Init();

		if (m_pTimer->m_pObjMinute == nullptr)
		{// 分表示の終了
			m_pTimer->m_pObjMinute = CNumber::Create(NUM_PLACE, m_pTimer->m_nSecond);
			m_pTimer->m_pObjMinute->SetPosition(D3DXVECTOR3(520.0f, 80.0f, 0.0f));
			m_pTimer->m_pObjMinute->SetSizeAll(20.0f, 50.0f);
		}

		if (m_pTimer->m_pObjSecond == nullptr)
		{// 秒表示の終了
			m_pTimer->m_pObjSecond = CNumber::Create(NUM_PLACE, m_pTimer->m_nSecond);
			m_pTimer->m_pObjSecond->SetPosition(D3DXVECTOR3(620.0f, 80.0f, 0.0f));
			m_pTimer->m_pObjSecond->SetSizeAll(20.0f, 50.0f);
		}
	}

	return m_pTimer;
}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CTimer::Init(void)
{
	m_nSecond = INITIAL_TIME;

	CUI *pUI = CUI::Create();

	if (pUI != nullptr)
	{
		pUI->SetPosition(D3DXVECTOR3(400.0f, 80.0f, 0.0f));
		pUI->SetSize(100.0f, 60.0f);
		pUI->SetVtx();

		int nIdx = Texture::GetIdx("data\\TEXTURE\\UI\\lifespan.png");
		pUI->SetIdxTexture(nIdx);
	}

	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CTimer::Uninit(void)
{
	m_pTimer = nullptr;

	if (m_pObjMinute != nullptr)
	{
		m_pObjMinute = nullptr;
	}

	if (m_pObjSecond != nullptr)
	{
		m_pObjSecond = nullptr;
	}

	Release();
}

//=====================================================
// 更新処理
//=====================================================
void CTimer::Update(void)
{
	if (CGame::GetState() != CGame::STATE_NORMAL)
	{
		return;
	}

	m_nCntSecond++;

	if (m_nCntSecond > 60)
	{
		m_nCntSecond = 0;
		
		if (m_nSecond >= 1)
		{
			m_nSecond--;
		}
	}

	// 分の計算
	int nMinute = m_nSecond / 60;

	// 秒の計算
	int nSecond = m_nSecond % 60;

	if (m_pObjMinute != nullptr)
	{// 分表示の制御
		m_pObjMinute->SetValue(nMinute, NUM_PLACE);
	}

	if (m_pObjSecond != nullptr)
	{// 秒表示の制御
		m_pObjSecond->SetValue(nSecond, NUM_PLACE);
	}

	if (m_nSecond <= 0)
	{
		m_nSecond = 0;

		CGame::SetState(CGame::STATE_RESULT);
	}
}

//=====================================================
// 時間加算
//=====================================================
void CTimer::AddTimer(int nValue)
{
	m_nSecond += nValue;
}

//=====================================================
// 描画処理
//=====================================================
void CTimer::Draw(void)
{
	CDebugProc *pDebugProc = CDebugProc::GetInstance();

	if (pDebugProc == nullptr)
	{
		return;
	}

	pDebugProc->Print("\n現在の秒数[%d]", m_nSecond);
}