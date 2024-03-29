//*****************************************************
//
// タイマーの処理[timer.h]
// Author:��山桃也
//
//*****************************************************

#ifndef _TIMER_H_
#define _TIMER_H_

//*****************************************************
// インクルード
//*****************************************************
#include "main.h"
#include "object.h"

//*****************************************************
// 前方宣言
//*****************************************************
class CNumber;

//*****************************************************
// クラスの定義
//*****************************************************
class CTimer : public CObject
{
public:
	CTimer();	// コンストラクタ
	~CTimer();	// デストラクタ

	static CTimer *Create(void);
	static CTimer *GetInstance(void) { return m_pTimer; }
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void AddTimer(int nValue);
	void SetPosition(D3DXVECTOR3 pos) {};
	D3DXVECTOR3 GetPosition(void) { return D3DXVECTOR3(); }
	D3DXVECTOR3 GetPositionOld(void) { return D3DXVECTOR3(); };	// 位置取得処理
	float GetWidth(void) { return 0.0f; }	// サイズ取得
	float GetHeight(void) { return 0.0f; }	// サイズ取得
	int GetSecond(void) { return m_nSecond; }	// 時間取得

private:
	CNumber *m_pObjMinute;	// 分表示のポインタ
	CNumber *m_pObjSecond;	// 秒表示のポインタ
	int m_nSecond;	// 現在の時間(秒)
	int m_nCntSecond;	// 一秒計測用カウンター

	static CTimer *m_pTimer;	// 自身のポインタ
};

#endif
