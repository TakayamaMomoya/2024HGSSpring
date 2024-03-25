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

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
CFlowerManager *CFlowerManager::m_pFlowerManager = nullptr;	// ���g�̃|�C���^

//*****************************************************
// �萔��`
//*****************************************************
namespace
{
const float TIME_FLOWER = 1.3f;	// �Ԃ�ݒu���鎞��
const int RAND_FLOWER_MIN = 2000;	// �����_�������ŏ��l
const int RAND_FLOWER_MAX = 4000;	// �����_�������ő�l
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
	for (CFlower *pFlower : m_list)
	{// �Ԃ̐��`�F�b�N�p
		if (pFlower != nullptr)
		{
			CDebugProc::GetInstance()->Print("\n�ԁ`�`�`");
		}
	}

	float fDeltaTime = CManager::GetDeltaTime();

	m_fTimerFlower += fDeltaTime;

	if (m_fTimerFlower >= TIME_FLOWER)
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