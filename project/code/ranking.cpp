//==============================================================
//
//�����L���O����[ranking.cpp]
//Author:����������
//
//==============================================================
#include "ranking.h"
#include "manager.h"
#include "score.h"
#include "input.h"
#include "inputkeyboard.h"
#include "inputManager.h"
#include "object2D.h"
#include "texture.h"
#include "number.h"
#include "game.h"
#include "fade.h"
#include "sound.h"
#include "player.h"
#include <fstream>

//�}�N����`
#define FILE_RANK		"data\\TEXT\\ranking.txt"		//�����L���O�t�@�C��
#define SCORE_WIDTH		(50.0f * 0.5f)		//�ꌅ�̉��̒���
#define SCORE_HEIGHT	(100.0f * 0.5f)		//�ꌅ�̏c�̒���
#define SCORE_INTER_U	(50.0f)				//�X�R�A�̊Ԋu(��)
#define SCORE_INTER_V	(100.0f)			//�X�R�A�̊Ԋu(�c)
#define NUM_TEX			(10)				//�e�N�X�`���̐����̐�
#define TRANS_TIME		(60 * 10)			//�J�ڂ���܂ł̎���

//�ÓI�����o�ϐ��錾
bool CRanking::bReset = true;						//���Z�b�g�������ǂ���
CNumber *CRanking::m_apNumber[NUM_DIGIT * MAX_RANK] = {};		//�����̏��
int CRanking::m_aTexU[NUM_DIGIT] = {};
int CRanking::m_nNum = 0;			//�X�R�A�̒l
int CRanking::m_nRankUpdate = -1;		//�X�V�����NNo,

//==============================================================
//�R���X�g���N�^
//==============================================================
CRanking::CRanking()
{
	m_nIdxTexture = -1;

	//����
	for (int nCntScore = 0; nCntScore < NUM_DIGIT; nCntScore++)
	{
		m_aTexU[nCntScore] = 0;
	}

	//�����L���O
	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		m_ranking[nCntRank].nRanking = 0;			//�X�R�A
		m_ranking[nCntRank].pos = D3DXVECTOR3(SCREEN_WIDTH * 0.5f - (SCORE_WIDTH * 2.0f * 4), 200.0f, 0.0f);	//�ʒu
	}

	m_bBgm = false;			//BGM������
	m_nCntTrans = 0;		//�J�ڂ���܂ł̎���
	m_nCntColor = 0;		//�����L���O�̐F�ύX�Ԋu
	m_bCol = true;			//�F�ύX���邩
	m_nRankUpdate = -1;
}

//==============================================================
//�f�X�g���N�^
//==============================================================
CRanking::~CRanking()
{

}

//==============================================================
//����������
//==============================================================
HRESULT CRanking::Init(void)
{
	D3DXVECTOR3 posScore = D3DXVECTOR3(SCREEN_WIDTH * 0.5f - (SCORE_WIDTH * 2.0f * 3.5f), 200.0f, 0.0f);	//�ʒu
	m_nNum = CScene::GetScore();		//�X�R�A���

	int nDigit;		//����

	// ���o���̐���
	CObject2D* pCaption = nullptr;

	pCaption = CObject2D::Create(4);

	if (pCaption != nullptr)
	{
		pCaption->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
		pCaption->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		pCaption->SetVtx();

		int nIdx = Texture::GetIdx("data\\TEXTURE\\BG\\ranking.jpg");
		pCaption->SetIdxTexture(nIdx);
	}

	//���Z�b�g����
	CRanking::Reset();

	//�ݒ菈��
	//if (CManager::GetInstance()->GetBgm() == false)
	{
		CRanking::Set(m_nNum);
	}

	//����������
	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{//�����L���O�̐���

		for (int nCntScore = 0; nCntScore < NUM_DIGIT; nCntScore++)
		{//�X�R�A�̌�����

			int nCnt = nCntScore + (nCntRank * NUM_DIGIT);

			if (m_apNumber[nCnt] == NULL)
			{//�g�p����ĂȂ��Ƃ�

				//��������
				m_apNumber[nCnt] = CNumber::Create(8, m_ranking[nCntRank].nRanking);

				if (m_apNumber[nCnt] != NULL)
				{//�����o������

					nDigit = (int)pow(10, (NUM_DIGIT - nCntScore));		//����

					//m_aTexU[nCntScore] = (int)(m_ranking[nCntRank].nRanking % nDigit / (nDigit * 0.1f));

					//�傫���ݒ�
					m_apNumber[nCnt]->SetSizeAll(SCORE_WIDTH, SCORE_HEIGHT);

					//�e�N�X�`�����蓖��
					m_apNumber[nCnt]->SetTex("data\\TEXTURE\\UI\\number02.png");

					m_apNumber[nCnt]->SetPosition(D3DXVECTOR3(posScore.x, posScore.y + (nCntRank * SCORE_INTER_V), posScore.z));

				}
			}
		}
	}

	// �v���C���[���f���̐ݒu
	/*m_pMotion = CMotion::Create("data\\MOTION\\motionBeetle.txt");

	if (m_pMotion != nullptr)
	{
		m_pMotion->SetPosition(POS_PLAYER);
		m_pMotion->SetMotion(CPlayer::MOTION::MOTION_NEUTRAL);
		m_pMotion->InitPose(CPlayer::MOTION::MOTION_NEUTRAL);
	}*/

	return S_OK;
}

//==============================================================
//�I������
//==============================================================
void CRanking::Uninit(void)
{
	//CSound *pSound = CManager::GetInstance()->GetSound();

	//if (CManager::GetInstance()->GetBgm() == false)
	//{
	//	//BGM�̒�~
	//	pSound->Stop();
	//}
	
	for (int nCntScore = 0; nCntScore < NUM_DIGIT * MAX_RANK; nCntScore++)
	{
		if (m_apNumber[nCntScore] != NULL)
		{//�g�p����Ă�Ƃ�

			//�I������
			m_apNumber[nCntScore]->Uninit();
			m_apNumber[nCntScore] = NULL;

		}
	}

	//�I�u�W�F�N�g�i�������g�̔j���j
	CObject::ReleaseAll();
}

//==============================================================
//�X�V����
//==============================================================
void CRanking::Update(void)
{
	//CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();		//�L�[�{�[�h�̏��擾
	//CInputJoyPad *pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();			//�p�b�h�̏��擾
	CFade* pFade = CFade::GetInstance();
	CInputManager* pInputManager = CInputManager::GetInstance();
	CInputKeyboard* pKeyboard = CInputKeyboard::GetInstance();

	if (pInputManager == nullptr)
	{
		return;
	}
	m_nCntColor++;

	if (((pKeyboard->GetTrigger(DIK_RETURN) == true/* || pInputManager->GetTrigger(CInputManager::BUTTON_A, 0) == true*/)) ||
		m_nCntTrans >= TRANS_TIME)
	{//ENTER�L�[��������

		CScene::SetScore(NULL);

		//�^�C�g�����
		pFade->SetFade(CScene::MODE_TITLE);
		bReset = true;
	}

	//if (CManager::GetInstance()->GetBgm() == false)
	{
		if ((m_nCntColor % 40) == 0 && m_nRankUpdate >= 0)
		{//��莞�Ԃ�������

			m_bCol = m_bCol ? false : true;

			if (m_bCol == true)
			{
				//���݂̃X�R�A�̐F�߂�
				for (int nCntScore = 0; nCntScore < NUM_DIGIT; nCntScore++)
				{
					int nCnt = nCntScore + (m_nRankUpdate * NUM_DIGIT);

					m_apNumber[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

				}
			}
			else
			{
				//���݂̃X�R�A�̐F�ύX
				for (int nCntScore = 0; nCntScore < NUM_DIGIT; nCntScore++)
				{
					int nCnt = nCntScore + (m_nRankUpdate * NUM_DIGIT);

					m_apNumber[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));

				}
			}

			m_nCntColor = 0;
		}
	}

	m_nCntTrans++;		//�J�ڂ���܂ł̎���
}

//==============================================================
//�`�揈��
//==============================================================
void CRanking::Draw(void)
{

}

//==============================================================
//�����L���O�̐ݒ菈��
//==============================================================
void CRanking::Set(int nNum)
{
	FILE *pFile;
	int nNewRanking;
	int nTemp;

	nNewRanking = nNum;

	if (nNewRanking > m_ranking[MAX_RANK - 1].nRanking)
	{//�V�����X�R�A���ŉ��ʂ�荂��������

		m_ranking[MAX_RANK - 1].nRanking = nNewRanking;		//�ŉ��ʂɐV�����X�R�A���

		//���݂̏���
		for (int nCntRank = 0; nCntRank < MAX_RANK - 1; nCntRank++)
		{
			//���̏���
			for (int nCntData = nCntRank + 1; nCntData < MAX_RANK; nCntData++)
			{
				if (m_ranking[nCntRank].nRanking < m_ranking[nCntData].nRanking)
				{//�X�R�A����������

					//�X�R�A����ւ�
					nTemp = m_ranking[nCntRank].nRanking;
					m_ranking[nCntRank].nRanking = m_ranking[nCntData].nRanking;
					m_ranking[nCntData].nRanking = nTemp;
				}
			}
		}

		//�X�V�����NNo.�ύX
		for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{
			//�����L���O�X�R�A�̕��בւ�
			if (nNewRanking == m_ranking[nCntRank].nRanking)
			{
				m_nRankUpdate = nCntRank;
			}
		}
	}

	//�����L���O�ۑ�
	pFile = fopen(FILE_RANK, "w");			//�t�@�C���ǂݍ���

	if (pFile != NULL)
	{//�t�@�C��������ꍇ

		for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{//�f�[�^���Z�[�u����

			fprintf(pFile, "%d\n", m_ranking[nCntRank].nRanking);
		}

		//�t�@�C�������
		fclose(pFile);
	}
}

//==============================================================
//�����L���O�̃��Z�b�g
//==============================================================
void CRanking::Reset(void)
{
	FILE *pFile;
	int nCntRank;

	//�����L���O���̏����ݒ�
	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		m_ranking[nCntRank].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�ʒu�̏�����
		m_ranking[nCntRank].nRanking = 0;								//�����L���O�̏�����
	}

	//�t�@�C����ǂݍ���
	pFile = fopen(FILE_RANK, "r");

	if (pFile != NULL)
	{//�t�@�C��������ꍇ

		for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{
			fscanf(pFile, "%d", &m_ranking[nCntRank].nRanking);
		}

		//�t�@�C�������
		fclose(pFile);
	}
}