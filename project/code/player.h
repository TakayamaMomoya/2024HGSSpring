//*****************************************************
//
// プレイヤーの処理[player.cpp]
// Author:��山桃也
//
//*****************************************************

#ifndef _PLAYER_H_
#define _PLAYER_H_

//*****************************************************
// インクルード
//*****************************************************
#include "motion.h"

//*****************************************************
// 前方宣言
//*****************************************************
class CCollisionSphere;
class CCollisionCube;
class CObject3D;

//*****************************************************
// クラスの定義
//*****************************************************
class CPlayer : public CMotion
{
public:
	enum MOTION
	{
		MOTION_NEUTRAL = 0,	// 待機
		MOTION_WALK_FRONT,	// 前歩
		MOTION_MAX
	};
	enum STATE
	{
		STATE_NONE = 0,	// 何でもない状態
		STATE_NORMAL,	// 通常状態
		STATE_BLOW,	// 吹き飛ばされている状態
		STATE_DAMAGE,	// ダメージ状態
		STATE_DEATH,	// 死亡状態
		STATE_MAX
	};
	enum PARAM
	{
		PARAM_GUN = 0,	// 銃の熱
		PARAM_MELEE,	// 近接武器の熱
		PARAM_HAND,	// 腕の熱
		PARAM_MAX
	};
	struct SParam
	{
		float fSpeedMove;		// 移動速度
		float fInitialBoost;		// ブースト残量初期値
		float fInitialLife;	// 初期体力
	};

	CPlayer(int nPriority = 4);	// コンストラクタ
	~CPlayer();	// デストラクタ

	static CPlayer *Create(void);
	static CPlayer *GetInstance(void) { return m_pPlayer; }
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Hit(float fDamage);
	float GetLife(void) { return m_info.fLife; }
	SParam GetParam(void) { return m_param; }
	void AddTimeSeed(float fTime) { m_info.fTimerSeed += fTime; }

private:
	struct SFragMotion
	{
		bool bMove;	// 移動
		bool bJump;	// ジャンプ
		bool bDodge;	// 回避
		bool bStamp;	// 踏みつけ
		bool bShot;	// 射撃
		bool bMelee;	// 近接攻撃
		bool bAddAttack;	// 追加攻撃
		bool bGrab;	// 掴み
		bool bAir;	// 滞空
		bool bStop;	// 急停止
	};
	struct SInfo
	{
		float fLife;	// 体力
		STATE state;	// 状態
		CCollisionSphere *pCollisionSphere;	// 球の当たり判定
		CCollisionSphere *pClsnAttack;	// 攻撃の当たり判定
		CCollisionCube *pCollisionCube;	// 立方体の当たり判定
		bool bLand;	// 着地しているかどうか
		D3DXVECTOR3 rotDest;	// 目標の向き
		float fTimerSeed;	// 種時間
		float fTimerBloom;	// 花咲タイマー
	};

	void Load(void);
	void Input(void);
	void InputMove(void);
	void InputCamera(void);
	void InputAttack(void);
	void Rotation(void);
	void ManageTimeSeed(void);
	void ManageCollision(void);
	void ManageState(void);
	void ManageMotion(void);
	void AddMoveForward(float fSpeed);
	void AddMoveUp(float fSpeed);
	void Event(EVENT_INFO *pEventInfo);
	void Death(void);
	void Debug(void);

	SInfo m_info;	// 自身の情報
	SParam m_param;	// パラメータ情報
	SFragMotion m_fragMotion;	// モーションのフラグ

	static CPlayer *m_pPlayer;	// 自身のポインタ
};

#endif