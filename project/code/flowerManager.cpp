//*****************************************************
//
// �ԊǗ�[flowerManager.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "flowermanager.h"
#include "debugproc.h"
#include "manager.h"
#include "flower.h"
#include "player.h"
#include "game.h"

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
CFlowerManager *CFlowerManager::m_pFlowerManager = nullptr;	// ���g�̃|�C���^

//*****************************************************
// �萔��`
//*****************************************************
namespace
{
const float TIME_FLOWER = 0.3f;	// �Ԃ�ݒu���鎞��
const int RAND_FLOWER_MIN = 2000;	// �����_�������ŏ��l
const int RAND_FLOWER_MAX = 4000;	// �����_�������ő�l
const int MAX_FLOWER = 6;	// ���ӂ̉Ԃ̍ő吔
const float DIST_NEAR = 6000.0f;	// �Ԃ��߂��Ɣ��f���鋗��
}

//=====================================================
// �R���X�g���N�^
//=====================================================
CFlowerManager::CFlowerManager(int nPriority) : CObject(nPriority)
{
	m_fTimerFlower = 0.0f;
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CFlowerManager::~CFlowerManager()
{

}

//=====================================================
// ��������
//=====================================================
CFlowerManager *CFlowerManager::Create(void)
{
	if (m_pFlowerManager == nullptr)
	{
		m_pFlowerManager = new CFlowerManager;

		if (m_pFlowerManager != nullptr)
		{
			// ������
			m_pFlowerManager->Init();
		}
	}

	return m_pFlowerManager;
}

//=====================================================
// ����������
//=====================================================
HRESULT CFlowerManager::Init(void)
{
	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CFlowerManager::Uninit(void)
{
	m_pFlowerManager = nullptr;

	Release();
}

//=====================================================
// �X�V����
//=====================================================
void CFlowerManager::Update(void)
{
	if (CGame::GetState() != CGame::STATE_NORMAL)
		return;

	int nNumFlowerNear = 0;

	for (CFlower *pFlower : m_list)
	{// �Ԃ̐��`�F�b�N�p
		if (pFlower != nullptr)
		{
			CPlayer *pPlayer = CPlayer::GetInstance();

			D3DXVECTOR3 posPlayer = { 0.0f,0.0f,0.0f };
			D3DXVECTOR3 pos = pFlower->GetPosition();

			if (pPlayer != nullptr)
			{
				posPlayer = pPlayer->GetPosition();
			}

			if (universal::DistCmp(posPlayer, pos, DIST_NEAR, nullptr))
			{
				nNumFlowerNear++;
			}
		}
	}

	float fDeltaTime = CManager::GetDeltaTime();

	m_fTimerFlower += fDeltaTime;

	if (m_fTimerFlower >= TIME_FLOWER && nNumFlowerNear < MAX_FLOWER)
	{// ����Ԃ̐���
		CFlower *pFlower = CFlower::Create();

		// �ʒu�̐ݒ�
		D3DXVECTOR3 pos = {0.0f,0.0f,0.0f};

		CPlayer *pPlayer = CPlayer::GetInstance();

		if (pPlayer != nullptr)
		{
			pos = pPlayer->GetPosition();
		}

		if (pFlower != nullptr)
		{
			D3DXVECTOR3 vecAdd = { 0.0f,0.0f,0.0f };

			vecAdd.z += universal::RandRange(500, -500);
			vecAdd.x += universal::RandRange(500, -500);

			D3DXVec3Normalize(&vecAdd, &vecAdd);

			vecAdd *= (float)universal::RandRange(RAND_FLOWER_MAX, RAND_FLOWER_MIN);

			pos += vecAdd;

			pFlower->SetPosition(pos);
		}

		m_fTimerFlower = 0.0f;
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CFlowerManager::Draw(void)
{
	
}