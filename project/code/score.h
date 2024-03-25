//*****************************************************
//
// スコアの処理[score.h]
// Author:髙山桃也
//
//*****************************************************

#ifndef _SCORE_H_
#define _SCORE_H_

//*****************************************************
// インクルード
//*****************************************************
#include "object.h"

//*****************************************************
// クラス定義
//*****************************************************
class CScore : public CObject
{
public:
	CScore(int nPriority = 5);	// コンストラクタ
	~CScore();	// デストラクタ

	static CScore *Create(void);
	static CScore *GetInstance(void) { return m_pScore; };
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void AddScore(int nValue);

private:
	int m_nScore;	// スコア
	static CScore *m_pScore;	// 自身のポインタ
};

#endif