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
#include "game.h"

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
CFlowerManager *CFlowerManager::m_pFlowerManager = nullptr;	// 自身のポインタ

//*****************************************************
// 定数定義
//*****************************************************
namespace
{
const float TIME_FLOWER = 0.3f;	// 花を設置する時間
const int RAND_FLOWER_MIN = 2000;	// ランダム距離最小値
const int RAND_FLOWER_MAX = 4000;	// ランダム距離最大値
const int MAX_FLOWER = 6;	// 周辺の花の最大数
const float DIST_NEAR = 6000.0f;	// 花が近いと判断する距離
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
	if (CGame::GetState() != CGame::STATE_NORMAL)
		return;

	int nNumFlowerNear = 0;

	for (CFlower *pFlower : m_list)
	{// 花の数チェック用
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