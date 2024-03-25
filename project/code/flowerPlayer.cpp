//*****************************************************
//
// �v���C���[�Ԃ̏���[FlowerPlayerPlayer.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "FlowerPlayer.h"
#include "score.h"

//*****************************************************
// �萔��`
//*****************************************************
namespace
{
const float SPEED_APPER = 0.1f;	// �o�����x
const int ADD_SCORE = 10;	// �X�R�A���Z��
}

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
int CFlowerPlayer::m_nNumAll = 0;	// ����

//=====================================================
// �R���X�g���N�^
//=====================================================
CFlowerPlayer::CFlowerPlayer(int nPriority)
{
	m_nNumAll++;
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CFlowerPlayer::~CFlowerPlayer()
{
	m_nNumAll--;
}

//=====================================================
// ��������
//=====================================================
CFlowerPlayer *CFlowerPlayer::Create(void)
{
	CFlowerPlayer *pFlowerPlayer = nullptr;

	if (pFlowerPlayer == nullptr)
	{
		pFlowerPlayer = new CFlowerPlayer;

		if (pFlowerPlayer != nullptr)
		{
			pFlowerPlayer->Init();
		}
	}

	return pFlowerPlayer;
}

//=====================================================
// ����������
//=====================================================
HRESULT CFlowerPlayer::Init(void)
{
	// �p���N���X�̏�����
	CObjectX::Init();

	// �e�̗L����
	EnableShadow(true);

	SetScale(0.0f);

	CScore *pScore = CScore::GetInstance();

	if (pScore != nullptr)
	{
		pScore->AddScore(ADD_SCORE);
	}

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CFlowerPlayer::Uninit(void)
{
	// �p���N���X�̏I��
	CObjectX::Uninit();
}

//=====================================================
// �X�V����
//=====================================================
void CFlowerPlayer::Update(void)
{
	// �p���N���X�̍X�V
	CObjectX::Update();

	// �X�P�[���̊Ǘ�
	float fScale = GetScale();

	fScale += (1.0f - fScale) * SPEED_APPER;

	SetScale(fScale);
}

//=====================================================
// �`�揈��
//=====================================================
void CFlowerPlayer::Draw(void)
{
	// �p���N���X�̕`��
	CObjectX::Draw();
}