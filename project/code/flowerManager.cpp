//*****************************************************
//
// 花管理[flowerManager.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "flowermanager.h"
#include "debugproc.h"
#include "manager.h"
#include "flower.h"
#include "player.h"

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
CFlowerManager *CFlowerManager::m_pFlowerManager = nullptr;	// 自身のポインタ

//*****************************************************
// 定数定義
//*****************************************************
namespace
{
const float TIME_FLOWER = 1.3f;	// 花を設置する時間
const int RAND_FLOWER_MIN = 2000;	// ランダム距離最小値
const int RAND_FLOWER_MAX = 4000;	// ランダム距離最大値
}

//=====================================================
// コンストラクタ
//=====================================================
CFlowerManager::CFlowerManager(int nPriority) : CObject(nPriority)
{
	m_fTimerFlower = 0.0f;
}

//=====================================================
// デストラクタ
//=====================================================
CFlowerManager::~CFlowerManager()
{

}

//=====================================================
// 生成処理
//=====================================================
CFlowerManager *CFlowerManager::Create(void)
{
	if (m_pFlowerManager == nullptr)
	{
		m_pFlowerManager = new CFlowerManager;

		if (m_pFlowerManager != nullptr)
		{
			// 初期化
			m_pFlowerManager->Init();
		}
	}

	return m_pFlowerManager;
}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CFlowerManager::Init(void)
{
	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CFlowerManager::Uninit(void)
{
	m_pFlowerManager = nullptr;

	Release();
}

//=====================================================
// 更新処理
//=====================================================
void CFlowerManager::Update(void)
{
	for (CFlower *pFlower : m_list)
	{// 花の数チェック用
		if (pFlower != nullptr)
		{
			CDebugProc::GetInstance()->Print("\n花～～～");
		}
	}

	float fDeltaTime = CManager::GetDeltaTime();

	m_fTimerFlower += fDeltaTime;

	if (m_fTimerFlower >= TIME_FLOWER)
	{// 取れる花の生成
		CFlower *pFlower = CFlower::Create();

		// 位置の設定
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
// 描画処理
//=====================================================
void CFlowerManager::Draw(void)
{
	
}