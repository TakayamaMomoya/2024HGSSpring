//*****************************************************
//
// �Ԃ̏���[flower.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "flower.h"
#include "collision.h"
#include "player.h"
#include "flowerManager.h"

//*****************************************************
// �萔��`
//*****************************************************
namespace
{
const float RADIUS_COLLISION = 100.0f;	// �����蔻��̔��a
const float ADD_SEED = 5.0f;	// ��t�^����
}

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
int CFlower::m_nNumAll = 0;	// ����

//=====================================================
// �R���X�g���N�^
//=====================================================
CFlower::CFlower(int nPriority)
{
	m_pCollisionSphere = nullptr;
	m_bDeath = false;

	m_nNumAll++;

	CFlowerManager *pManager = CFlowerManager::GetInstance();

	if (pManager != nullptr)
	{
		pManager->PushBack(this);
	}
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CFlower::~CFlower()
{
	m_nNumAll--;

	CFlowerManager *pManager = CFlowerManager::GetInstance();

	if (pManager != nullptr)
	{
		pManager->Remove(this);
	}
}

//=====================================================
// ��������
//=====================================================
CFlower *CFlower::Create(void)
{
	CFlower *pFlower = nullptr;

	if (pFlower == nullptr)
	{
		pFlower = new CFlower;

		if (pFlower != nullptr)
		{
			pFlower->Init();
		}
	}

	return pFlower;
}

//=====================================================
// ����������
//=====================================================
HRESULT CFlower::Init(void)
{
	// �p���N���X�̏�����
	CObjectX::Init();

	// �e�̗L����
	EnableShadow(true);

	if (m_pCollisionSphere == nullptr)
	{// �����蔻�萶��
		m_pCollisionSphere = CCollisionSphere::Create(CCollision::TAG_FLOWER, CCollision::TYPE_SPHERE, this);

		if (m_pCollisionSphere != nullptr)
		{
			m_pCollisionSphere->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			m_pCollisionSphere->SetRadius(RADIUS_COLLISION);
		}
	}

	int nIdx = CModel::Load("data\\MODEL\\flower\\BigFlower.x");

	// ���f���Ǎ�
	BindModel(nIdx);

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CFlower::Uninit(void)
{
	// �����蔻��폜
	DeleteCollision();

	// �p���N���X�̏I��
	CObjectX::Uninit();
}

//=====================================================
// �����蔻��̍폜
//=====================================================
void CFlower::DeleteCollision(void)
{
	if (m_pCollisionSphere != nullptr)
	{// �����蔻��̏���
		m_pCollisionSphere->Uninit();

		m_pCollisionSphere = nullptr;
	}
}

//=====================================================
// �X�V����
//=====================================================
void CFlower::Update(void)
{
	// �p���N���X�̍X�V
	CObjectX::Update();

	if (m_bDeath)
	{
		D3DXCOLOR col = GetEmissiveCol();

		col.a -= 0.1f;

		if (col.a <= 0.0f)
		{
			Uninit();
		}

		SetEmissiveCol(col);
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CFlower::Draw(void)
{
	// �p���N���X�̕`��
	CObjectX::Draw();
}

//=====================================================
// �ʒu�ݒ�
//=====================================================
void CFlower::SetPosition(D3DXVECTOR3 pos)
{
	if (m_pCollisionSphere != nullptr)
	{
		m_pCollisionSphere->SetPosition(pos);
	}

	CObjectX::SetPosition(pos);
}

//=====================================================
// �q�b�g����
//=====================================================
void CFlower::Hit(float fDamage)
{
	if (m_pCollisionSphere == nullptr)
	{
		return;
	}

	m_bDeath = true;

	SetEmissiveCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	DeleteCollision();

	CPlayer *pPlayer = CPlayer::GetInstance();

	if (pPlayer != nullptr)
	{
		pPlayer->AddTimeSeed(ADD_SEED);
	}
}