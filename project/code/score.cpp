//*****************************************************
//
// スコアの処理[score.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "score.h"
#include "debugproc.h"
#include "number.h"
#include "UI.h"
#include "texture.h"
#include "ranking.h"

//*****************************************************
// 定数定義
//*****************************************************
namespace
{
const int NUM_PLACE = 4;	// 桁数
}

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
CScore *CScore::m_pScore = nullptr;	// 自身のポインタ

//=====================================================
// コンストラクタ
//=====================================================
CScore::CScore(int nPriority) : CObject(nPriority)
{
	m_nScore = 0;
	m_nScoreDest = 0;
	m_pObjNumber = nullptr;
}

//=====================================================
//	デストラクタ
//=====================================================
CScore::~CScore()
{

}

//=====================================================
// 生成処理
//=====================================================
CScore *CScore::Create(void)
{
	if (m_pScore == nullptr)
	{
		m_pScore = new CScore;

		if (m_pScore != nullptr)
		{
			m_pScore->Init();
		}
	}

	return m_pScore;
}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CScore::Init(void)
{
	if (m_pObjNumber == nullptr)
	{
		m_pObjNumber = CNumber::Create(NUM_PLACE, m_nScore);

		m_pObjNumber->SetPosition(D3DXVECTOR3(900.0f, 70.0f, 0.0f));
		m_pObjNumber->SetSizeAll(20.0f, 40.0f);
	}

	CUI *pUI = CUI::Create();

	if (pUI != nullptr)
	{
		pUI->SetPosition(D3DXVECTOR3(1100.0f, 70.0f, 0.0f));
		pUI->SetSize(60.0f, 40.0f);
		pUI->SetVtx();

		int nIdx = Texture::GetIdx("data\\TEXTURE\\UI\\SquareCentimeter.png");
		pUI->SetIdxTexture(nIdx);
	}

	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CScore::Uninit(void)
{
	CRanking::SetScore(GetScore());

	m_pScore = nullptr;

	Release();
}

//=====================================================
// 更新処理
//=====================================================
void CScore::Update(void)
{
	int nScoreOld = m_nScore;

	//スコア値上昇演出==============================
	if (m_nScore >= m_nScoreDest)
	{
		m_nScore = m_nScoreDest;
	}
	else
	{
		m_nScore += 100;

		if (m_nScore >= m_nScoreDest)
		{
			m_nScore = m_nScoreDest;
		}
	}

	if (m_pObjNumber != nullptr)
	{
		m_pObjNumber->SetValue(m_nScore, NUM_PLACE);
	}
}

//=====================================================
// スコア加算
//=====================================================
void CScore::AddScore(int nValue)
{
	m_nScoreDest += nValue;
}

//=====================================================
// 描画処理
//=====================================================
void CScore::Draw(void)
{
	CDebugProc *pDebug = CDebugProc::GetInstance();

	if (pDebug != nullptr)
	{
		pDebug->Print("\nスコア[%d]", m_nScore);
		pDebug->Print("\nスコア目標値[%d]", m_nScoreDest);
	}
}