//*****************************************************
//
// プレイヤー花の処理[FlowerPlayerPlayer.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "FlowerPlayer.h"
#include "score.h"

//*****************************************************
// 定数定義
//*****************************************************
namespace
{
const float SPEED_APPER = 0.1f;	// 出現速度
const int ADD_SCORE = 10;	// スコア加算量
}

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
int CFlowerPlayer::m_nNumAll = 0;	// 総数

//=====================================================
// コンストラクタ
//=====================================================
CFlowerPlayer::CFlowerPlayer(int nPriority)
{
	m_nNumAll++;
}

//=====================================================
// デストラクタ
//=====================================================
CFlowerPlayer::~CFlowerPlayer()
{
	m_nNumAll--;
}

//=====================================================
// 生成処理
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
// 初期化処理
//=====================================================
HRESULT CFlowerPlayer::Init(void)
{
	// 継承クラスの初期化
	CObjectX::Init();

	// 影の有効化
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
// 終了処理
//=====================================================
void CFlowerPlayer::Uninit(void)
{
	// 継承クラスの終了
	CObjectX::Uninit();
}

//=====================================================
// 更新処理
//=====================================================
void CFlowerPlayer::Update(void)
{
	// 継承クラスの更新
	CObjectX::Update();

	// スケールの管理
	float fScale = GetScale();

	fScale += (1.0f - fScale) * SPEED_APPER;

	SetScale(fScale);
}

//=====================================================
// 描画処理
//=====================================================
void CFlowerPlayer::Draw(void)
{
	// 継承クラスの描画
	CObjectX::Draw();
}