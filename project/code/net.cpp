//*****************************************************
//
// 網の処理[net.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "net.h"
#include "collision.h"
#include "player.h"
#include "object3D.h"
#include "texture.h"
#include "manager.h"
#include "particle.h"

//*****************************************************
// 定数定義
//*****************************************************
namespace
{
const float RADIUS_COLLISION = 600.0f;	// 当たり判定の半径
const float INITIAL_HEIGHT = 1500.0f;	// 高さの設定
const float SPEED_FALL = 90.0f;	// 網が落ちる速度
const float TIME_FALL = 2.0f;	// 落ちてくるまでの時間
}

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
int CNet::m_nNumAll = 0;	// 総数

//=====================================================
// コンストラクタ
//=====================================================
CNet::CNet(int nPriority)
{
	m_pCollisionSphere = nullptr;
	m_pShadow = nullptr;
	m_fTimerFall = 0.0f;

	m_nNumAll++;
}

//=====================================================
// デストラクタ
//=====================================================
CNet::~CNet()
{
	m_nNumAll--;
}

//=====================================================
// 生成処理
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
// 初期化処理
//=====================================================
HRESULT CNet::Init(void)
{
	// 継承クラスの初期化
	CObjectX::Init();

	if (m_pCollisionSphere == nullptr)
	{// 当たり判定生成
		m_pCollisionSphere = CCollisionSphere::Create(CCollision::TAG_NET, CCollision::TYPE_SPHERE, this);

		if (m_pCollisionSphere != nullptr)
		{
			m_pCollisionSphere->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			m_pCollisionSphere->SetRadius(RADIUS_COLLISION);
		}
	}

	// モデル読込
	int nIdx = CModel::Load("data\\MODEL\\enemy\\InsectNet.x");
	BindModel(nIdx);

	// 影生成
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
// 終了処理
//=====================================================
void CNet::Uninit(void)
{
	// 当たり判定削除
	DeleteCollision();

	if (m_pShadow != nullptr)
	{
		m_pShadow->Uninit();
		m_pShadow = nullptr;
	}

	// 継承クラスの終了
	CObjectX::Uninit();
}

//=====================================================
// 当たり判定の削除
//=====================================================
void CNet::DeleteCollision(void)
{
	if (m_pCollisionSphere != nullptr)
	{// 当たり判定の消去
		m_pCollisionSphere->Uninit();

		m_pCollisionSphere = nullptr;
	}
}

//=====================================================
// 更新処理
//=====================================================
void CNet::Update(void)
{
	// 継承クラスの更新
	CObjectX::Update();

	if (m_fTimerFall >= TIME_FALL)
	{
		D3DXVECTOR3 pos = GetPosition();

		if (pos.y > 0.0f)
		{// 落ちている時
			pos.y -= SPEED_FALL;

			if (pos.y <= 0.0f)
			{
				pos.y = 0.0f;

				CPlayer *pPlayer = CPlayer::GetInstance();

				D3DXVECTOR3 posPlayer = pPlayer->GetPosition();

				if (universal::DistCmp(pos, posPlayer, RADIUS_COLLISION, nullptr))
				{
					pPlayer->Hit(1.0f);

					// ここでパーティクル
					CParticle::Create(posPlayer, CParticle::TYPE::TYPE_TURN_EXPLOSION);
				}

				SetEmissiveCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			}

			SetPosition(pos);
		}
		else
		{// 落ちきっているとき
			D3DXCOLOR col = GetEmissiveCol();

			col.a -= 0.1f;

			if (col.a <= 0.0f)
			{
				Uninit();
			}

			SetEmissiveCol(col);
		}
	}
	else
	{
		float fDeltaTime = CManager::GetDeltaTime();

		m_fTimerFall += fDeltaTime;

		if (m_pShadow != nullptr)
		{// 影の調整
			float fRate = (m_fTimerFall / TIME_FALL);

			m_pShadow->SetSize(RADIUS_COLLISION * fRate, RADIUS_COLLISION * fRate);
		}
	}
}

//=====================================================
// 描画処理
//=====================================================
void CNet::Draw(void)
{
	// 継承クラスの描画
	CObjectX::Draw();
}

//=====================================================
// 位置設定
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