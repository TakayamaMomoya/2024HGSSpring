//*****************************************************
//
// プレイヤー花の処理[flowerPlayer.h]
// Author:髙山桃也
//
//*****************************************************

#ifndef _FLOWERPLAYER_H_
#define _FLOWERPLAYER_H_

#include "ObjectX.h"

//*****************************************************
// 前方宣言
//*****************************************************

//*****************************************************
// クラスの定義
//*****************************************************
class CFlowerPlayer : public CObjectX
{
public:
	CFlowerPlayer(int nPriority = 3);	// コンストラクタ
	~CFlowerPlayer();	// デストラクタ

	static CFlowerPlayer *Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	static int m_nNumAll;	// 総数
};

#endif
