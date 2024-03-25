//*****************************************************
//
// �`���[�g���A������[tutorial.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "tutorial.h"
#include "object.h"
#include "player.h"
#include "slow.h"
#include "manager.h"
#include "camera.h"
#include "cameraBehavior.h"
#include "UIManager.h"
#include "UI.h"
#include "meshfield.h"
#include "object3D.h"
#include "renderer.h"
#include "texture.h"
#include "animEffect3D.h"
#include "inputManager.h"
#include "fade.h"

//*****************************************************
// �萔��`
//*****************************************************
namespace
{
const float TIME_SPAWN = 3.0f;	// �X�|�[���܂ł̊Ԋu
const D3DXVECTOR3 POS_SKIP = { SCREEN_WIDTH * 0.9f,SCREEN_HEIGHT * 0.85f, 0.0f };	// �X�L�b�v�\���̈ʒu
const D3DXVECTOR3 POS_GAUGE = { POS_SKIP.x + 2.0f,POS_SKIP.y + 28.0f, 0.0f };	// �X�L�b�v�\���̈ʒu
const D3DXVECTOR2 SIZE_SKIP = { 80.0f,60.0f };	// �X�L�b�v�\���̃T�C�Y
const D3DXVECTOR2 SIZE_GAUGE = { 70.0f,26.0f };	// �X�L�b�v�Q�[�W�̃T�C�Y
const char* PATH_SKIP = "data\\TEXTURE\\UI\\tutorial06.png";	// �X�L�b�v�\���̃p�X
const float TIME_SKIP = 2.0f;	// �X�L�b�v�ɂ����鎞��
}

//=====================================================
// �R���X�g���N�^
//=====================================================
CTutorial::CTutorial()
{

}

//=====================================================
// �f�X�g���N�^
//=====================================================
CTutorial::~CTutorial()
{

}

//=====================================================
// ����������
//=====================================================
HRESULT CTutorial::Init(void)
{
	// ���o���̐���
	CObject2D* pCaption = nullptr;

	pCaption = CObject2D::Create(0);

	if (pCaption != nullptr)
	{
		pCaption->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
		pCaption->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		pCaption->SetVtx();

		int nIdx = Texture::GetIdx("data\\TEXTURE\\BG\\tutorial.jpg");
		pCaption->SetIdxTexture(nIdx);
	}

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CTutorial::Uninit(void)
{
	// �I�u�W�F�N�g�S��
	CObject::ReleaseAll();
}

//=====================================================
// �X�V����
//=====================================================
void CTutorial::Update(void)
{
	CInputManager* pInputManager = CInputManager::GetInstance();
	CFade* pFade = CFade::GetInstance();

	if (pInputManager == nullptr)
	{
		return;
	}

	if (pInputManager->GetTrigger(CInputManager::BUTTON_ENTER))
	{//ENTER�L�[��������

		CScene::SetScore(NULL);

		//�^�C�g�����
		pFade->SetFade(CScene::MODE_TITLE);
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CTutorial::Draw(void)
{

}