//*****************************************************
//
// 網管理[netManager.h]
// Author:髙山桃也
//
//*****************************************************

#ifndef _NETMANAGER_H_
#define _NETMANAGER_H_

//*****************************************************
// インクルード
//*****************************************************
#include "object.h"
#include <list>

//*****************************************************
// 前方宣言
//*****************************************************
class CNet;

//*****************************************************
// クラスの定義
//*****************************************************
class CNetManager : public CObject
{
public:
	CNetManager(int nPriority = 3);	// コンストラクタ
	~CNetManager();	// デストラクタ

	static CNetManager *Create(void);
	static CNetManager *GetInstance(void) { return m_pNetManager; }
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	std::list<CNet*> GetList(void) { return m_list; }
	void PushBack(CNet *pNet) { m_list.push_back(pNet); }
	void Remove(CNet *pNet) { m_list.remove(pNet); }

private:
	float m_fTimerNet;	// 花設置タイマー

	std::list<CNet*> m_list;	// 花のリスト
	static CNetManager *m_pNetManager;	// 自身のポインタ
};

#endif

