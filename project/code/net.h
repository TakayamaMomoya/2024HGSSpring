//*****************************************************
//
// �Ԃ̏���[net.h]
// Author:���R����
//
//*****************************************************

#ifndef _NET_H_
#define _NET_H_

#include "ObjectX.h"

//*****************************************************
// �O���錾
//*****************************************************
class CCollisionSphere;
class CObject3D;

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CNet : public CObjectX
{
public:
	CNet(int nPriority = 3);	// �R���X�g���N�^
	~CNet();	// �f�X�g���N�^

	static CNet *Create(D3DXVECTOR3 pos);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetPosition(D3DXVECTOR3 pos);

private:
	void DeleteCollision(void);

	static int m_nNumAll;	// ����
	float m_fTimerFall;	// ������܂ł̃^�C�}�[
	CCollisionSphere *m_pCollisionSphere;	// ���̓����蔻��
	CObject3D *m_pShadow;	// �e�̃|�C���^
};

#endif
