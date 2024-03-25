//*****************************************************
//
// �Ԃ̏���[flower.h]
// Author:���R����
//
//*****************************************************

#ifndef _FLOWER_H_
#define _FLOWER_H_

#include "ObjectX.h"

//*****************************************************
// �O���錾
//*****************************************************
class CCollisionSphere;

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CFlower : public CObjectX
{
public:
	CFlower(int nPriority = 3);	// �R���X�g���N�^
	~CFlower();	// �f�X�g���N�^

	static CFlower *Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Hit(float fDamage);
	void SetPosition(D3DXVECTOR3 pos);
	bool IsDeath(void) { return m_bDeath; }

private:
	void DeleteCollision(void);

	bool m_bDeath;	// ���S����
	static int m_nNumAll;	// ����
	CCollisionSphere *m_pCollisionSphere;	// ���̓����蔻��
};

#endif
