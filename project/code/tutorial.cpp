//*****************************************************
//
// チュートリアル処理[tutorial.cpp]
// Author:��山桃也
//
//*****************************************************

//*****************************************************
// インクルード
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
// 定数定義
//*****************************************************
namespace
{
const float TIME_SPAWN = 3.0f;	// スポーンまでの間隔
const D3DXVECTOR3 POS_SKIP = { SCREEN_WIDTH * 0.9f,SCREEN_HEIGHT * 0.85f, 0.0f };	// スキップ表示の位置
const D3DXVECTOR3 POS_GAUGE = { POS_SKIP.x + 2.0f,POS_SKIP.y + 28.0f, 0.0f };	// スキップ表示の位置
const D3DXVECTOR2 SIZE_SKIP = { 80.0f,60.0f };	// スキップ表示のサイズ
const D3DXVECTOR2 SIZE_GAUGE = { 70.0f,26.0f };	// スキップゲージのサイズ
const char* PATH_SKIP = "data\\TEXTURE\\UI\\tutorial06.png";	// スキップ表示のパス
const float TIME_SKIP = 2.0f;	// スキップにかかる時間
}

//=====================================================
// コンストラクタ
//=====================================================
CTutorial::CTutorial()
{

}

//=====================================================
// デストラクタ
//=====================================================
CTutorial::~CTutorial()
{

}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CTutorial::Init(void)
{
	// 見出しの生成
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
// 終了処理
//=====================================================
void CTutorial::Uninit(void)
{
	// オブジェクト全棄
	CObject::ReleaseAll();
}

//=====================================================
// 更新処理
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
	{//ENTERキー押したら

		CScene::SetScore(NULL);

		//タイトル画面
		pFade->SetFade(CScene::MODE_GAME);
	}
}

//=====================================================
// 描画処理
//=====================================================
void CTutorial::Draw(void)
{

}