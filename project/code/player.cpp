//*****************************************************
//
// プレイヤーの処理[player.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "main.h"
#include "player.h"
#include "collision.h"
#include "motion.h"
#include "inputManager.h"
#include "inputkeyboard.h"
#include "debugproc.h"
#include "universal.h"
#include "slow.h"
#include "camera.h"
#include "manager.h"
#include "effect3D.h"
#include "meshfield.h"
#include "cameraBehavior.h"
#include "particle.h"
#include "debrisSpawner.h"
#include "game.h"
#include "animEffect3D.h"
#include "anim3D.h"
#include "pause.h"
#include "inpact.h"
#include "sound.h"
#include "flowerPlayer.h"
#include "object3D.h"
#include "texture.h"
#include "flowerManager.h"
#include "flower.h"
#include "fan2D.h"

//*****************************************************
// 定数定義
//*****************************************************
namespace
{
const char* BODY_PATH = "data\\MOTION\\motionBeetle.txt";	// 見た目のパス
const float GRAVITY = 0.50f;	// 重力
const float SPEED_MOVE = 2.0f;	// 移動速度
const float FACT_MOVE = 0.1f;	// 移動の減衰係数
const float TIME_BLOOM = 0.6f;	// 花咲時間
const float TIME_ESCAPE = 2.0f;	// つかまり時間
const float MAXTIME_SEED = 10.0f;	// 種まき最大時間
const float RADIUS_GAUGE = 100.0f;	// ゲージ半径
}

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
CPlayer *CPlayer::m_pPlayer = nullptr;	// 自身のポインタ

//=====================================================
// 優先順位を決めるコンストラクタ
//=====================================================
CPlayer::CPlayer(int nPriority)
{
	m_pPlayer = this;

	ZeroMemory(&m_info, sizeof(CPlayer::SInfo));
	ZeroMemory(&m_param, sizeof(CPlayer::SParam));
	ZeroMemory(&m_fragMotion, sizeof(CPlayer::SFragMotion));
}

//=====================================================
// デストラクタ
//=====================================================
CPlayer::~CPlayer()
{

}

//=====================================================
// 生成処理
//=====================================================
CPlayer *CPlayer::Create(void)
{
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = new CPlayer;

		if (m_pPlayer != nullptr)
		{
			m_pPlayer->Init();
		}
	}

	return m_pPlayer;
}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CPlayer::Init(void)
{
	// モデルの設定
	CMotion::Load((char*)BODY_PATH);

	// 継承クラスの初期化
	CMotion::Init();

	m_info.rotDest = D3DXVECTOR3(0.0f, 1.57f, 0.0f);
	SetRotation(D3DXVECTOR3(0.0f, -1.57f, 0.0f));

	// 当たり判定の生成
	if (m_info.pCollisionSphere == nullptr)
	{
		m_info.pCollisionSphere = CCollisionSphere::Create(CCollision::TAG_PLAYER, CCollision::TYPE_SPHERE, this);

		if (m_info.pCollisionSphere != nullptr)
		{
			m_info.pCollisionSphere->SetRadius(50.0f);
		}
	}

	if (m_info.pClsnAttack == nullptr)
	{// 球の当たり判定生成
		m_info.pClsnAttack = CCollisionSphere::Create(CCollision::TAG_NONE, CCollision::TYPE_SPHERE, this);

		if (m_info.pClsnAttack != nullptr)
		{// 情報の設定
			m_info.pClsnAttack->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			m_info.pClsnAttack->SetRadius(0.0f);
		}
	}

	if (m_info.pCollisionCube == nullptr)
	{// 当たり判定生成
		m_info.pCollisionCube = CCollisionCube::Create(CCollision::TAG_PLAYER, this);

		if (m_info.pCollisionCube != nullptr)
		{
			D3DXVECTOR3 vtxMax = { 20.0f,100.0f,20.0f };
			D3DXVECTOR3 vtxMin = { -20.0f,0.0f,-20.0f };

			m_info.pCollisionCube->SetPosition(GetPosition());

			m_info.pCollisionCube->SetVtx(vtxMax, vtxMin);
		}
	}

	if (m_info.pGauge == nullptr)
	{
		m_info.pGauge = CFan2D::Create(6);

		if (m_info.pGauge != nullptr)
		{
			D3DXVECTOR3 pos = SCRN_MID;
			pos.x -= 100.0f;
			m_info.pGauge->SetPosition(pos);
			m_info.pGauge->SetRadius(RADIUS_GAUGE);

			m_info.pGauge->SetRateAngle(0.0f);
			m_info.pGauge->SetVtx();
		}
	}

	// パラメーターに初期値を入れる
	m_param.fInitialLife = 300.0f;
	m_info.fLife = m_param.fInitialLife;
	m_param.fSpeedMove = SPEED_MOVE;
	m_info.state = STATE_NORMAL;
	m_info.bLand = true;

	SetMotion(MOTION_WALK_FRONT);

	// カメラの行動設定
	Camera::ChangeBehavior(new CFollowPlayer);

	// 読込
	Load();

	EnableShadow(true);
	SetPosShadow(D3DXVECTOR3(0.0f, 1.0f, 0.0f));

	m_info.fLimitBloom = TIME_BLOOM;

	return S_OK;
}

//=====================================================
// 読込処理
//=====================================================
void CPlayer::Load(void)
{
	char cTemp[256];
	int nThruster = 0;

	FILE *pFile = fopen("data\\TEXT\\playerParam.txt", "r");

	if (pFile != nullptr)
	{
		while (true)
		{
			// ここで読み込んだ文字によって下記のIFにかかる
			(void)fscanf(pFile, "%s", &cTemp[0]);

			if (strcmp(cTemp, "END_SCRIPT") == 0)
			{
				break;
			}
		}

		fclose(pFile);
	}
}

//=====================================================
// 終了処理
//=====================================================
void CPlayer::Uninit(void)
{
	m_pPlayer = nullptr;

	Object::DeleteObject((CObject**)&m_info.pCollisionSphere);
	Object::DeleteObject((CObject**)&m_info.pCollisionCube);
	Object::DeleteObject((CObject**)&m_info.pClsnAttack);

	// 継承クラスの終了
	CMotion::Uninit();
}

//=====================================================
// 更新処理
//=====================================================
void CPlayer::Update(void)
{
	CSlow *pSlow = CSlow::GetInstance();

	if (m_info.state != CPlayer::STATE::STATE_DEATH)
	{
		// 入力
		Input();

		// プレイヤーの回転
		Rotation();
	}

	// 位置の反映
	D3DXVECTOR3 pos = GetPosition();
	D3DXVECTOR3 move = GetMove();
	
	// 前回の位置を保存
	SetPositionOld(pos);

	pos += move;
	SetPosition(pos);

	move.x += (0 - move.x) * FACT_MOVE;
	move.z += (0 - move.z) * FACT_MOVE;

	SetMove(move);

	// 種時間管理
	ManageTimeSeed();

	// 当たり判定の管理
	ManageCollision();

	// 状態管理
	ManageState();

	// モーション管理
	ManageMotion();

	// 継承クラスの更新
	CMotion::Update();

	if (m_info.pGauge != nullptr)
	{
		// 大きさ調整
		float fRadius = m_info.pGauge->GetRadius();

		fRadius += (RADIUS_GAUGE - fRadius) * 0.1f;

		m_info.pGauge->SetRadius(fRadius);

		// 割合計算
		float fRate = m_info.fTimerSeed / MAXTIME_SEED;

		m_info.pGauge->SetRateAngle(fRate);
		m_info.pGauge->SetVtx();
	}

// デバッグ処理
#if _DEBUG
	Debug();
#endif // _DEBUG
}

//=====================================================
// 入力処理
//=====================================================
void CPlayer::Input(void)
{
	int nMotion = GetMotion();

	if (CGame::GetState() != CGame::STATE_NORMAL || nMotion == MOTION_CATCH)
		return;

	// 移動操作
	InputMove();

	// カメラ操作
	InputCamera();

	// 攻撃操作
	InputAttack();

	if (CManager::GetMode() == CScene::MODE_GAME)
	{
		CInputManager *pInputManager = CInputManager::GetInstance();

		if (pInputManager != nullptr)
		{
			if (pInputManager->GetTrigger(CInputManager::BUTTON_PAUSE))
			{
				CPause::Create();
			}
		}
	}
}

//=====================================================
// 移動の入力
//=====================================================
void CPlayer::InputMove(void)
{
	CSlow *pSlow = CSlow::GetInstance();
	CInputManager *pInputManager = CInputManager::GetInstance();

	if (pInputManager == nullptr)
	{
		return;
	}

	// カメラ取得
	CCamera *pCamera = CManager::GetCamera();

	if (pCamera == nullptr)
	{
		return;
	}

	CCamera::Camera *pInfoCamera = pCamera->GetCamera();

	// 目標方向の設定
	CInputManager::SAxis axis = pInputManager->GetAxis();
	D3DXVECTOR3 axisMove = axis.axisMove;

	float fLengthAxis = D3DXVec3Length(&axisMove);

	int nMotion = GetMotion();

	if (fLengthAxis >= 0.3f)
	{// 通常移動時の目標向き設定
		m_info.rotDest.y = atan2f(axisMove.x, axisMove.z);

		CDebugProc *pDebugProc = CDebugProc::GetInstance();

		pDebugProc->Print("\n通常移動");
	}

	D3DXVECTOR3 vecMove = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 rot = GetRotation();

	fLengthAxis *= SPEED_MOVE;

	vecMove -= {sinf(rot.y) * fLengthAxis, 0.0f, cosf(rot.y) * fLengthAxis};

	// 移動速度の設定
	D3DXVECTOR3 move = GetMove();

	D3DXVec3Normalize(&vecMove, &vecMove);
	vecMove *= m_param.fSpeedMove;

	if (pSlow != nullptr)
	{
		float fScale = pSlow->GetScale();

		vecMove *= fScale;
	}

	float fAngleInput = atan2f(axisMove.x, axisMove.z);

	move += vecMove;

	SetMove(move);

#ifdef _DEBUG
	CInputKeyboard *pKeyboard = CInputKeyboard::GetInstance();

	if (pKeyboard != nullptr)
	{
		if (pKeyboard->GetTrigger(DIK_RETURN))
		{// スローにする
			if (pSlow != nullptr)
			{
				pSlow->SetScale(0.25f);
			}
		}

		if (pKeyboard->GetRelease(DIK_RETURN))
		{// スロー解除
			CSlow *pSlow = CSlow::GetInstance();

			if (pSlow != nullptr)
			{
				pSlow->SetScale(1.0f);
			}
		}

		if (pKeyboard->GetTrigger(DIK_O))
		{// 可動パーツリセット
			ResetEnableMotion();
		}
	}
#endif
}

//=====================================================
// カメラ操作
//=====================================================
void CPlayer::InputCamera(void)
{
	// 入力マネージャー取得
	CInputManager *pInputManager = CInputManager::GetInstance();

	if (pInputManager == nullptr)
	{
		return;
	}

	// カメラ取得
	CCamera *pCamera = CManager::GetCamera();

	if (pCamera == nullptr)
	{
		return;
	}

	CCamera::Camera *pInfoCamera = pCamera->GetCamera();
}

//=====================================================
// 攻撃の入力
//=====================================================
void CPlayer::InputAttack(void)
{
	CInputManager *pInputManager = CInputManager::GetInstance();
	int nMotion = GetMotion();

	if (pInputManager == nullptr)
	{
		return;
	}
}

//=====================================================
// 種時間管理
//=====================================================
void CPlayer::ManageTimeSeed(void)
{
	if (m_info.fTimerSeed <= 0.0f)
	{// 種時間切れ

	}
	else
	{// 種残ってる場合
		float fDeltaTime = CManager::GetDeltaTime();

		// 花を咲かせる
		m_info.fTimerBloom += fDeltaTime;

		if (m_info.fTimerBloom >= m_info.fLimitBloom)
		{
			CFlowerPlayer *pFlower = CFlowerPlayer::Create();

			if (pFlower != nullptr)
			{
				D3DXVECTOR3 pos = GetPosition();

				pos.z += universal::RandRange(500, -500);
				pos.x += universal::RandRange(500, -500);

				pFlower->SetPosition(pos);
			}

			m_info.fTimerBloom = 0.0f;
		}

		// 時間の減少
		m_info.fTimerSeed -= fDeltaTime;

		if (m_info.fTimerSeed <= 0.0f)
		{
			m_info.fTimerSeed = 0.0f;
		}
	}
}

//=====================================================
// プレイヤーの回転
//=====================================================
void CPlayer::Rotation(void)
{
	// 移動方向の取得
	D3DXVECTOR3 move = GetMove();

	float fAngleMove = atan2f(-move.x, -move.z);
	float fLenghtMove = sqrtf(move.x * move.x + move.z * move.z);

	int nMotion = GetMotion();

	if (fLenghtMove >= 6.0f)
	{
		// 向きの補正
		D3DXVECTOR3 rot = GetRotation();

		SetRotation(rot);

		if (m_info.bLand)
		{
			m_fragMotion.bMove = true;
		}
	}
	else
	{
		m_fragMotion.bMove = false;
	}

	m_info.rotDest.x = 0.0f;

	// 向きの補正
	D3DXVECTOR3 rot = GetRotation();

	float fFact = 0.1f;

	universal::FactingRot(&rot.y, m_info.rotDest.y + D3DX_PI, fFact);
	universal::FactingRot(&rot.x, m_info.rotDest.x, fFact);

	SetRotation(rot);
}

//=====================================================
// 状態管理
//=====================================================
void CPlayer::ManageState(void)
{
	switch (m_info.state)
	{
	case STATE_NORMAL:
	{// 通常状態

	}
		break;
	case STATE_DAMAGE:
	{// ダメージ状態

	}
		break;
	case STATE_DEATH:
	{// 死亡状態

	}
		break;
	default:
		break;
	}
}

//=====================================================
// 当たり判定管理
//=====================================================
void CPlayer::ManageCollision(void)
{
	// 当たり判定の追従
	if (m_info.pCollisionSphere != nullptr)
	{
		int nMotion = GetMotion();

		D3DXVECTOR3 pos = GetPosition();
		D3DXVECTOR3 posWaist = GetMtxPos(0);
		D3DXVECTOR3 move = GetMove();

		m_info.pCollisionSphere->SetPositionOld(m_info.pCollisionSphere->GetPosition());
		m_info.pCollisionSphere->SetPosition(pos);

		if (m_info.pCollisionSphere->IsTriggerEnter(CCollision::TAG_FLOWER))
		{// 花との判定
			CObject *pObj = nullptr;

			pObj = m_info.pCollisionSphere->GetOther();

			if (pObj != nullptr)
			{
				pObj->Hit(1.0f);
			}

			AddLimitBloom(-0.05f);

			if (m_info.pGauge != nullptr)
			{
				m_info.pGauge->SetRadius(RADIUS_GAUGE * 1.3f);
			}

			// ここでパーティクル
			CParticle::Create(pos, CParticle::TYPE::TYPE_EXPLOSION);
		}

		if (m_info.pCollisionCube != nullptr)
		{
			pos = GetPosition();
			D3DXVECTOR3 posCollision = m_info.pCollisionCube->GetPosition();

			// 判定の追従
			m_info.pCollisionCube->SetPositionOld(posCollision);
			m_info.pCollisionCube->SetPosition(pos);

			// メッシュフィールドとの当たり判定
			pos = GetPosition();
			D3DXVECTOR3 posOld = GetPositionOld();

			CMeshField *pMesh = CMeshField::GetInstance();

			if (pMesh != nullptr)
			{
				float fHeight = pMesh->GetHeight(pos,&move);

				if (pos.y <= fHeight)
				{
					pos.y = fHeight;
					move.y = 0.0f;

					SetPosition(pos);
				}
			}

			SetMove(move);
		}

		SetPosition(pos);
	}
}

//=====================================================
// モーション管理
//=====================================================
void CPlayer::ManageMotion(void)
{
	int nMotion = GetMotion();
	bool bFinish = IsFinish();

	if (m_fragMotion.bCatch)
	{
		if (nMotion != MOTION_CATCH)
		{
			SetMotion(MOTION_CATCH);
		}

		m_info.fTimerCatch += CManager::GetDeltaTime();

		if (TIME_ESCAPE < m_info.fTimerCatch)
		{
			m_info.fTimerCatch = 0.0f;

			m_fragMotion.bCatch = false;
		}
	}
	else if (m_fragMotion.bMove)
	{// 歩きモーション
		if (nMotion != MOTION_WALK_FRONT)
		{
			SetMotion(MOTION_WALK_FRONT);
		}
	}
	else
	{// 待機モーション
		if (nMotion != MOTION_NEUTRAL)
		{
			SetMotion(MOTION_NEUTRAL);
		}
	}
}

//=====================================================
// 前方に移動量を加える
//=====================================================
void CPlayer::AddMoveForward(float fSpeed)
{
	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR3 vecMove = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 rot = GetRotation();

	vecMove =
	{
		sinf(rot.x - D3DX_PI * 0.5f) * sinf(rot.y) * fSpeed,
		cosf(rot.x - D3DX_PI * 0.5f) * fSpeed,
		sinf(rot.x - D3DX_PI * 0.5f) * cosf(rot.y) * fSpeed
	};

	move += vecMove;

	SetMove(move);
}

//=====================================================
// 上に移動量を加える
//=====================================================
void CPlayer::AddMoveUp(float fSpeed)
{
	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR3 vecMove = { 0.0f,0.0f,0.0f };

	vecMove.y += fSpeed;

	move += vecMove;

	SetMove(move);
}

//=====================================================
// イベントの管理
//=====================================================
void CPlayer::Event(EVENT_INFO *pEventInfo)
{
	int nMotion = GetMotion();

	D3DXVECTOR3 offset = pEventInfo->offset;
	D3DXMATRIX mtxParent;
	D3DXMATRIX mtxPart = *GetParts(pEventInfo->nIdxParent)->pParts->GetMatrix();

	universal::SetOffSet(&mtxParent, mtxPart, offset);

	D3DXVECTOR3 pos = { mtxParent._41,mtxParent._42 ,mtxParent._43 };

}

//=====================================================
// 描画処理
//=====================================================
void CPlayer::Draw(void)
{
	// 継承クラスの描画
	CMotion::Draw();

	// デバッグ表示
	Debug();
}

//=====================================================
// ヒット処理
//=====================================================
void CPlayer::Hit(float fDamage)
{
	m_fragMotion.bCatch = true;
}

//=====================================================
// 死亡処理
//=====================================================
void CPlayer::Death(void)
{
	CSound *pSound = CSound::GetInstance();

	if (pSound != nullptr)
	{
		pSound->Stop(CSound::LABEL_SE_WARNING00);
	}

	Sound::Play(CSound::LABEL_SE_EXPLOSION01);

	D3DXVECTOR3 pos = GetMtxPos(0);

	// エフェクト発生
	CAnimEffect3D *pAnimManager = CAnimEffect3D::GetInstance();

	if (pAnimManager != nullptr)
	{
		CAnim3D *pAnim = pAnimManager->CreateEffect(pos, CAnimEffect3D::TYPE_EXPLOSION);

		if (pAnim != nullptr)
		{
			pAnim->SetSize(600.0f, 600.0f);
		}
	}

	// 破片生成
	CDebrisSpawner::Create(pos, CDebrisSpawner::TYPE::TYPE_DEATH);
	
	Uninit();
}

//=====================================================
// デバッグ表示
//=====================================================
void CPlayer::Debug(void)
{
#ifndef _DEBUG

	return;

#endif

	CDebugProc *pDebugProc = CDebugProc::GetInstance();

	if (pDebugProc == nullptr)
	{
		return;
	}

	pDebugProc->Print("\nプレイヤーの位置[%f,%f,%f]", GetPosition().x, GetPosition().y, GetPosition().z);
	pDebugProc->Print("\nプレイヤーの移動量[%f,%f,%f]", GetMove().x, GetMove().y, GetMove().z);
	pDebugProc->Print("\n種時間[%f]", m_info.fTimerSeed);
	for (int i = 0; i < PARAM_MAX; i++)

	int nMotion = GetMotion();

	pDebugProc->Print("\n着地[%d]", m_info.bLand);

	CInputKeyboard *pKey = CInputKeyboard::GetInstance();

	if (pKey != nullptr)
	{
		if (pKey->GetTrigger(DIK_O))
		{
			m_info.fLife = 1.0f;
		}
	}
}