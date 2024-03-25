//*****************************************************
//
// �Ԃ̏���[net.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "net.h"
#include "collision.h"
#include "player.h"
#include "object3D.h"
#include "texture.h"

//*****************************************************
// �萔��`
//*****************************************************
namespace
{
const float RADIUS_COLLISION = 200.0f;	// �����蔻��̔��a
const float INITIAL_HEIGHT = 1000.0f;	// �����̐ݒ�
const float SPEED_FALL = 20.0f;	// �Ԃ������鑬�x
}

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
int CNet::m_nNumAll = 0;	// ����

//=====================================================
// �R���X�g���N�^
//=====================================================
CNet::CNet(int nPriority)
{
	m_pCollisionSphere = nullptr;
	m_pShadow = nullptr;

	m_nNumAll++;
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CNet::~CNet()
{
	m_nNumAll--;
}

//=====================================================
// ��������
//=====================================================
CNet *CNet::Create(D3DXVECTOR3 pos)
{
	CNet *pNet = nullptr;

	if (pNet == nullptr)
	{
		pNet = new CNet;

		if (pNet != nullptr)
		{
			pNet->Init();

			pos.y += INITIAL_HEIGHT;

			pNet->SetPosition(pos);
		}
	}

	return pNet;
}

//=====================================================
// ����������
//=====================================================
HRESULT CNet::Init(void)
{
	// �p���N���X�̏�����
	CObjectX::Init();

	if (m_pCollisionSphere == nullptr)
	{// �����蔻�萶��
		m_pCollisionSphere = CCollisionSphere::Create(CCollision::TAG_NET, CCollision::TYPE_SPHERE, this);

		if (m_pCollisionSphere != nullptr)
		{
			m_pCollisionSphere->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			m_pCollisionSphere->SetRadius(RADIUS_COLLISION);
		}
	}

	// ���f���Ǎ�
	int nIdx = CModel::Load("data\\MODEL\\enemy\\InsectNet.x");
	BindModel(nIdx);

	// �e����
	if (m_pShadow == nullptr)
	{
		m_pShadow = CObject3D::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		if (m_pShadow != nullptr)
		{
			int nIdxTex = Texture::GetIdx("data\\TEXTURE\\EFFECT\\effect000.png");
			m_pShadow->SetIdxTexture(nIdxTex);

			m_pShadow->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
			m_pShadow->SetSize(0.0f, 0.0f);
		}
	}

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CNet::Uninit(void)
{
	// �����蔻��폜
	DeleteCollision();

	if (m_pShadow != nullptr)
	{
		m_pShadow->Uninit();
		m_pShadow = nullptr;
	}

	// �p���N���X�̏I��
	CObjectX::Uninit();
}

//=====================================================
// �����蔻��̍폜
//=====================================================
void CNet::DeleteCollision(void)
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
void CNet::Update(void)
{
	// �p���N���X�̍X�V
	CObjectX::Update();

	D3DXVECTOR3 pos = GetPosition();

	if (pos.y >= 0.0f)
	{
		pos.y -= SPEED_FALL;

		if (pos.y <= 0.0f)
		{
			pos.y = 0.0f;

			CPlayer *pPlayer = CPlayer::GetInstance();

			D3DXVECTOR3 posPlayer = pPlayer->GetPosition();

			if (universal::DistCmp(posPlayer, posPlayer, RADIUS_COLLISION, nullptr))
			{
				pPlayer->Hit(1.0f);
			}
		}

		SetPosition(pos);
	}

	if (m_pShadow != nullptr)
	{
		float fRate = 1.0f - (pos.y / INITIAL_HEIGHT);

		m_pShadow->SetSize(RADIUS_COLLISION * fRate * 1.5f, RADIUS_COLLISION * fRate * 1.5f);
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CNet::Draw(void)
{
	// �p���N���X�̕`��
	CObjectX::Draw();
}

//=====================================================
// �ʒu�ݒ�
//=====================================================
void CNet::SetPosition(D3DXVECTOR3 pos)
{
	if (m_pCollisionSphere != nullptr)
	{
		m_pCollisionSphere->SetPosition(pos);
	}

	if (m_pShadow != nullptr)
	{
		m_pShadow->SetPosition(D3DXVECTOR3(pos.x, 1.0f, pos.z));
	}

	CObjectX::SetPosition(pos);
}