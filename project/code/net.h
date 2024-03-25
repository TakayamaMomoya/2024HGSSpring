//*****************************************************
//
// 網の処理[net.h]
// Author:髙山桃也
//
//*****************************************************

#ifndef _NET_H_
#define _NET_H_

#include "ObjectX.h"

//*****************************************************
// 前方宣言
//*****************************************************
class CCollisionSphere;
class CObject3D;

//*****************************************************
// クラスの定義
//*****************************************************
class CNet : public CObjectX
{
public:
	CNet(int nPriority = 3);	// コンストラクタ
	~CNet();	// デストラクタ

	static CNet *Create(D3DXVECTOR3 pos);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetPosition(D3DXVECTOR3 pos);

private:
	void DeleteCollision(void);

	static int m_nNumAll;	// 総数
	float m_fTimerFall;	// 落ちるまでのタイマー
	CCollisionSphere *m_pCollisionSphere;	// 球の当たり判定
	CObject3D *m_pShadow;	// 影のポインタ
};

#endif
