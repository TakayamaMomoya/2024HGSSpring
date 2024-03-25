//*****************************************************
//
// �X�R�A�̏���[score.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "score.h"
#include "debugproc.h"
#include "number.h"
#include "UI.h"
#include "texture.h"
#include "ranking.h"

//*****************************************************
// �萔��`
//*****************************************************
namespace
{
const int NUM_PLACE = 4;	// ����
}

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
CScore *CScore::m_pScore = nullptr;	// ���g�̃|�C���^

//=====================================================
// �R���X�g���N�^
//=====================================================
CScore::CScore(int nPriority) : CObject(nPriority)
{
	m_nScore = 0;
	m_nScoreDest = 0;
	m_pObjNumber = nullptr;
}

//=====================================================
//	�f�X�g���N�^
//=====================================================
CScore::~CScore()
{

}

//=====================================================
// ��������
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
// ����������
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
// �I������
//=====================================================
void CScore::Uninit(void)
{
	CRanking::SetScore(GetScore());

	m_pScore = nullptr;

	Release();
}

//=====================================================
// �X�V����
//=====================================================
void CScore::Update(void)
{
	int nScoreOld = m_nScore;

	//�X�R�A�l�㏸���o==============================
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
// �X�R�A���Z
//=====================================================
void CScore::AddScore(int nValue)
{
	m_nScoreDest += nValue;
}

//=====================================================
// �`�揈��
//=====================================================
void CScore::Draw(void)
{
	CDebugProc *pDebug = CDebugProc::GetInstance();

	if (pDebug != nullptr)
	{
		pDebug->Print("\n�X�R�A[%d]", m_nScore);
		pDebug->Print("\n�X�R�A�ڕW�l[%d]", m_nScoreDest);
	}
}