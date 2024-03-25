//*****************************************************
//
// �^�C�}�[�̏���[timer.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "timer.h"
#include "manager.h"
#include "renderer.h"
#include "number.h"
#include "game.h"
#include "result.h"
#include "debugproc.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define NUM_PLACE	(2)	// ����
#define INITIAL_TIME	(120)	// �����̎���

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
CTimer *CTimer::m_pTimer = nullptr;	// ���g�̃|�C���^

//=====================================================
// �R���X�g���N�^
//=====================================================
CTimer::CTimer()
{
	m_pObjMinute = nullptr;
	m_pObjSecond = nullptr;
	m_nSecond = 0;
	m_nCntSecond = 0;
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CTimer::~CTimer()
{

}

//=====================================================
// ��������
//=====================================================
CTimer *CTimer::Create(void)
{
	if (m_pTimer == nullptr)
	{
		m_pTimer = new CTimer;

		m_pTimer->Init();

		if (m_pTimer->m_pObjMinute == nullptr)
		{// ���\���̏I��
			m_pTimer->m_pObjMinute = CNumber::Create(NUM_PLACE, m_pTimer->m_nSecond);
			m_pTimer->m_pObjMinute->SetPosition(D3DXVECTOR3(520.0f, 80.0f, 0.0f));
			m_pTimer->m_pObjMinute->SetSizeAll(20.0f, 50.0f);
		}

		if (m_pTimer->m_pObjSecond == nullptr)
		{// �b�\���̏I��
			m_pTimer->m_pObjSecond = CNumber::Create(NUM_PLACE, m_pTimer->m_nSecond);
			m_pTimer->m_pObjSecond->SetPosition(D3DXVECTOR3(620.0f, 80.0f, 0.0f));
			m_pTimer->m_pObjSecond->SetSizeAll(20.0f, 50.0f);
		}
	}

	return m_pTimer;
}

//=====================================================
// ����������
//=====================================================
HRESULT CTimer::Init(void)
{
	m_nSecond = INITIAL_TIME;

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CTimer::Uninit(void)
{
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
// �X�V����
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

	// ���̌v�Z
	int nMinute = m_nSecond / 60;

	// �b�̌v�Z
	int nSecond = m_nSecond % 60;

	if (m_pObjMinute != nullptr)
	{// ���\���̐���
		m_pObjMinute->SetValue(nMinute, NUM_PLACE);
	}

	if (m_pObjSecond != nullptr)
	{// �b�\���̐���
		m_pObjSecond->SetValue(nSecond, NUM_PLACE);
	}

	if (m_nSecond <= 0)
	{
		m_nSecond = 0;

		CGame::SetState(CGame::STATE_END);
	}
}

//=====================================================
// ���ԉ��Z
//=====================================================
void CTimer::AddTimer(int nValue)
{
	m_nSecond += nValue;
}

//=====================================================
// �`�揈��
//=====================================================
void CTimer::Draw(void)
{
	CDebugProc *pDebugProc = CDebugProc::GetInstance();

	if (pDebugProc == nullptr)
	{
		return;
	}

	pDebugProc->Print("\n���݂̕b��[%d]", m_nSecond);
}