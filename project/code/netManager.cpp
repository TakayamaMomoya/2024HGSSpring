//*****************************************************
//
// �ԊǗ�[netManager.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "netManager.h"
#include "debugproc.h"
#include "manager.h"
#include "net.h"
#include "player.h"
#include "game.h"

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
CNetManager *CNetManager::m_pNetManager = nullptr;	// ���g�̃|�C���^

//*****************************************************
// �萔��`
//*****************************************************
namespace
{
const float TIME_Net = 1.3f;	// �Ԃ�ݒu���鎞��
const int RAND_NET = 400;	// �����_�������ő�l
const int MAX_Net = 10;	// ���ӂ̉Ԃ̍ő吔
const float DIST_NEAR = 6000.0f;	// �Ԃ��߂��Ɣ��f���鋗��
}

//=====================================================
// �R���X�g���N�^
//=====================================================
CNetManager::CNetManager(int nPriority) : CObject(nPriority)
{
	m_fTimerNet = 0.0f;
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CNetManager::~CNetManager()
{

}

//=====================================================
// ��������
//=====================================================
CNetManager *CNetManager::Create(void)
{
	if (m_pNetManager == nullptr)
	{
		m_pNetManager = new CNetManager;

		if (m_pNetManager != nullptr)
		{
			// ������
			m_pNetManager->Init();
		}
	}

	return m_pNetManager;
}

//=====================================================
// ����������
//=====================================================
HRESULT CNetManager::Init(void)
{
	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CNetManager::Uninit(void)
{
	m_pNetManager = nullptr;

	Release();
}

//=====================================================
// �X�V����
//=====================================================
void CNetManager::Update(void)
{
	if (CGame::GetState() != CGame::STATE_NORMAL)
		return;

	int nNumNetNear = 0;

	for (CNet *pNet : m_list)
	{// �Ԃ̐��`�F�b�N�p
		if (pNet != nullptr)
		{
			CPlayer *pPlayer = CPlayer::GetInstance();

			D3DXVECTOR3 posPlayer = { 0.0f,0.0f,0.0f };
			D3DXVECTOR3 pos = pNet->GetPosition();

			if (pPlayer != nullptr)
			{
				posPlayer = pPlayer->GetPosition();
			}

			if (universal::DistCmp(posPlayer, pos, DIST_NEAR, nullptr))
			{
				nNumNetNear++;
			}
		}
	}

	float fDeltaTime = CManager::GetDeltaTime();

	m_fTimerNet += fDeltaTime;

	if (m_fTimerNet >= TIME_Net && nNumNetNear < MAX_Net)
	{// �Ԃ̐���
		// �ʒu�̐ݒ�
		D3DXVECTOR3 pos = { 0.0f,0.0f,0.0f };

		CPlayer *pPlayer = CPlayer::GetInstance();

		if (pPlayer != nullptr)
		{
			pos = pPlayer->GetPosition();
		}

		pos.z += universal::RandRange(RAND_NET, -RAND_NET);
		pos.x += universal::RandRange(RAND_NET, -RAND_NET);

		CNet *pNet = CNet::Create(pos);

		m_fTimerNet = 0.0f;
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CNetManager::Draw(void)
{
	
}