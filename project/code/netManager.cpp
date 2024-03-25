//*****************************************************
//
// 網管理[netManager.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "netManager.h"
#include "debugproc.h"
#include "manager.h"
#include "net.h"
#include "player.h"
#include "game.h"

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
CNetManager *CNetManager::m_pNetManager = nullptr;	// 自身のポインタ

//*****************************************************
// 定数定義
//*****************************************************
namespace
{
const float TIME_Net = 1.3f;	// 花を設置する時間
const int RAND_NET = 400;	// ランダム距離最大値
const int MAX_Net = 10;	// 周辺の花の最大数
const float DIST_NEAR = 6000.0f;	// 花が近いと判断する距離
}

//=====================================================
// コンストラクタ
//=====================================================
CNetManager::CNetManager(int nPriority) : CObject(nPriority)
{
	m_fTimerNet = 0.0f;
}

//=====================================================
// デストラクタ
//=====================================================
CNetManager::~CNetManager()
{

}

//=====================================================
// 生成処理
//=====================================================
CNetManager *CNetManager::Create(void)
{
	if (m_pNetManager == nullptr)
	{
		m_pNetManager = new CNetManager;

		if (m_pNetManager != nullptr)
		{
			// 初期化
			m_pNetManager->Init();
		}
	}

	return m_pNetManager;
}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CNetManager::Init(void)
{
	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CNetManager::Uninit(void)
{
	m_pNetManager = nullptr;

	Release();
}

//=====================================================
// 更新処理
//=====================================================
void CNetManager::Update(void)
{
	if (CGame::GetState() != CGame::STATE_NORMAL)
		return;

	int nNumNetNear = 0;

	for (CNet *pNet : m_list)
	{// 花の数チェック用
		if (pNet != nullptr)
		{
			CPlayer *pPlayer = CPlayer::GetInstance();

			D3DXVECTOR3 posPlayer = { 0.0f,0.0f,0.0f };
			D3DXVECTOR3 pos = pNet->GetPosition();

			if (pPlayer != nullptr)
			{
				posPlayer = pPlayer->GetPosition();
			}

			if (universal::DistCmp(posPlayer, pos, DIST_NEAR, nullptr))
			{
				nNumNetNear++;
			}
		}
	}

	float fDeltaTime = CManager::GetDeltaTime();

	m_fTimerNet += fDeltaTime;

	if (m_fTimerNet >= TIME_Net && nNumNetNear < MAX_Net)
	{// 網の生成
		// 位置の設定
		D3DXVECTOR3 pos = { 0.0f,0.0f,0.0f };

		CPlayer *pPlayer = CPlayer::GetInstance();

		if (pPlayer != nullptr)
		{
			pos = pPlayer->GetPosition();
		}

		pos.z += universal::RandRange(RAND_NET, -RAND_NET);
		pos.x += universal::RandRange(RAND_NET, -RAND_NET);

		CNet *pNet = CNet::Create(pos);

		m_fTimerNet = 0.0f;
	}
}

//=====================================================
// 描画処理
//=====================================================
void CNetManager::Draw(void)
{
	
}