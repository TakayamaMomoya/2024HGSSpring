//==============================================================
//
//ランキング処理[ranking.cpp]
//Author:佐藤根詩音
//
//==============================================================
#include "ranking.h"
#include "manager.h"
#include "score.h"
#include "input.h"
#include "inputManager.h"
#include "object2D.h"
#include "object3D.h"
#include "texture.h"
#include "number.h"
#include "game.h"
#include "fade.h"
#include "sound.h"
#include "player.h"
#include "camera.h"
#include <fstream>

//マクロ定義
#define FILE_RANK		"data\\TEXT\\ranking.txt"		//ランキングファイル
#define SCORE_WIDTH		(50.0f * 0.5f)		//一桁の横の長さ
#define SCORE_HEIGHT	(100.0f * 0.5f)		//一桁の縦の長さ
#define SCORE_INTER_U	(50.0f)				//スコアの間隔(横)
#define SCORE_INTER_V	(100.0f)			//スコアの間隔(縦)
#define NUM_TEX			(10)				//テクスチャの数字の数
#define TRANS_TIME		(60 * 10)			//遷移するまでの時間

//静的メンバ変数宣言
bool CRanking::bReset = true;						//リセットしたかどうか
CNumber *CRanking::m_apNumber[NUM_DIGIT * MAX_RANK] = {};		//数字の情報
int CRanking::m_aTexU[NUM_DIGIT] = {};
int CRanking::m_nNum = 0;			//スコアの値
int CRanking::m_nRankUpdate = -1;		//更新ランクNo,

//==============================================================
//コンストラクタ
//==============================================================
CRanking::CRanking()
{
	m_nIdxTexture = -1;

	//桁数
	for (int nCntScore = 0; nCntScore < NUM_DIGIT; nCntScore++)
	{
		m_aTexU[nCntScore] = 0;
	}

	//ランキング
	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		m_ranking[nCntRank].nRanking = 0;			//スコア
		m_ranking[nCntRank].pos = D3DXVECTOR3(SCREEN_WIDTH * 0.5f - (SCORE_WIDTH * 2.0f * 4), 200.0f, 0.0f);	//位置
	}

	m_bBgm = false;			//BGM消すか
	m_nCntTrans = 0;		//遷移するまでの時間
	m_nCntColor = 0;		//ランキングの色変更間隔
	m_bCol = true;			//色変更するか
	m_nRankUpdate = -1;
	m_pMotion = nullptr;
}

//==============================================================
//デストラクタ
//==============================================================
CRanking::~CRanking()
{

}

//==============================================================
//初期化処理
//==============================================================
HRESULT CRanking::Init(void)
{
	D3DXVECTOR3 posScore = D3DXVECTOR3(SCREEN_WIDTH * 0.5f - (SCORE_WIDTH * 3.0f), 200.0f, 0.0f);	//位置

	int nDigit;		//桁数

		// サウンドインスタンスの取得
	CSound* pSound = CSound::GetInstance();

	if (pSound != nullptr)
	{
		// BGMの再生
		pSound->Play(pSound->LABEL_BGM_RANKING);
	}
	else if (pSound == nullptr)
	{
		return E_FAIL;
	}

	// 見出しの生成
	CObject2D* pCaption = nullptr;

	pCaption = CObject2D::Create(0);

	if (pCaption != nullptr)
	{
		pCaption->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, 80.0f, 0.0f));
		pCaption->SetSize(200.0f, 60.0f);
		pCaption->SetVtx();

		int nIdx = Texture::GetIdx("data\\TEXTURE\\UI\\ranking001.png");
		pCaption->SetIdxTexture(nIdx);
	}

	//背景生成
	CObject3D* pBg = nullptr;

	pBg = CObject3D::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	pBg->EnableLighting(false);

	if(pBg != nullptr)
	{
		pBg->SetSize(SCREEN_WIDTH * 10.0f, SCREEN_HEIGHT * 6.0f);
		pBg->SetPosition(D3DXVECTOR3(700.0f, 400.0f, -400.0f));
		pBg->SetBgRotation(D3DXVECTOR3(0.5f * D3DX_PI, 0.0f, 0.0f));

		int nIdx = Texture::GetIdx("data\\TEXTURE\\BG\\ranking000.jpg");
		pBg->SetIdxTexture(nIdx);
	}

	//リセット処理
	CRanking::Reset();

	//設定処理
	//if (CManager::GetInstance()->GetBgm() == false)
	{
		CRanking::Set(m_nNum);
	}

	//初期化処理
	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{//ランキングの数分

		for (int nCntScore = 0; nCntScore < NUM_DIGIT; nCntScore++)
		{//スコアの桁数分

			int nCnt = nCntScore + (nCntRank * NUM_DIGIT);

			if (m_apNumber[nCnt] == NULL)
			{//使用されてないとき

				//数字生成
				m_apNumber[nCnt] = CNumber::Create(4, m_ranking[nCntRank].nRanking);

				if (m_apNumber[nCnt] != NULL)
				{//生成出来たら

					//大きさ設定
					m_apNumber[nCnt]->SetSizeAll(SCORE_WIDTH, SCORE_HEIGHT);

					//テクスチャ割り当て
					m_apNumber[nCnt]->SetTex("data\\TEXTURE\\UI\\number02.png");

					m_apNumber[nCnt]->SetPosition(D3DXVECTOR3(posScore.x, posScore.y + (nCntRank * SCORE_INTER_V), posScore.z));

				}
			}
		}
	}

	CCamera* pCamera = CManager::GetCamera();
	if (pCamera == nullptr)
		return E_FAIL;

	CCamera::Camera* pInfoCamera = pCamera->GetCamera();

	pInfoCamera->posV = { 700.0f, 400.0f, 1300.0f };
	pInfoCamera->posR = { 700.0f, 400.0f, -300.0f };

	// プレイヤーモデルの設置
	m_pMotion = CMotion::Create("data\\MOTION\\motionBeetle.txt");

	if (m_pMotion != nullptr)
	{
		m_pMotion->SetPosition(D3DXVECTOR3(0.0f, 400.0f, -300.0f));
		m_pMotion->Rotation(D3DXVECTOR3(0.5f * D3DX_PI, 0.0f, 0.0f));
		m_pMotion->SetMotion(CPlayer::MOTION::MOTION_NEUTRAL);
		m_pMotion->InitPose(CPlayer::MOTION::MOTION_NEUTRAL);
	}

	return S_OK;
}

//==============================================================
//終了処理
//==============================================================
void CRanking::Uninit(void)
{
	//CSound *pSound = CManager::GetInstance()->GetSound();

	//if (CManager::GetInstance()->GetBgm() == false)
	//{
	//	//BGMの停止
	//	pSound->Stop();
	//}
	
	m_nNum = 0;

	for (int nCntScore = 0; nCntScore < NUM_DIGIT * MAX_RANK; nCntScore++)
	{
		if (m_apNumber[nCntScore] != NULL)
		{//使用されてるとき

			//終了処理
			m_apNumber[nCntScore]->Uninit();
			m_apNumber[nCntScore] = NULL;

		}
	}

	//オブジェクト（自分自身の破棄）
	CObject::ReleaseAll();
}

//==============================================================
//更新処理
//==============================================================
void CRanking::Update(void)
{
	CFade* pFade = CFade::GetInstance();
	CInputManager* pInputManager = CInputManager::GetInstance();

	if (pInputManager == nullptr)
	{
		return;
	}
	m_nCntColor++;

	if (pInputManager->GetTrigger(CInputManager::BUTTON_ENTER) ||
		m_nCntTrans >= TRANS_TIME)
	{//ENTERキー押したら

		CScene::SetScore(NULL);

		//タイトル画面
		pFade->SetFade(CScene::MODE_TITLE);
		bReset = true;
	}

	//if (CManager::GetInstance()->GetBgm() == false)
	{
		if ((m_nCntColor % 40) == 0 && m_nRankUpdate >= 0)
		{//一定時間たったら

			m_bCol = m_bCol ? false : true;

			if (m_bCol == true)
			{
				//現在のスコアの色戻す
				for (int nCntScore = 0; nCntScore < NUM_DIGIT; nCntScore++)
				{
					int nCnt = nCntScore + (m_nRankUpdate * NUM_DIGIT);

					m_apNumber[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

				}
			}
			else
			{
				//現在のスコアの色変更
				for (int nCntScore = 0; nCntScore < NUM_DIGIT; nCntScore++)
				{
					int nCnt = nCntScore + (m_nRankUpdate * NUM_DIGIT);

					m_apNumber[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));

				}
			}

			m_nCntColor = 0;
		}
	}

	//float fRot = m_pMotion->GetRotation().x + 0.000001f;

	//差分を修正
	/*if (fRot < -D3DX_PI)
	{
		fRot += D3DX_PI * 2;
	}
	else if (fRot > D3DX_PI)
	{
		fRot -= D3DX_PI * 2;
	}*/

	m_pMotion->Rotation(D3DXVECTOR3(0.0f, 0.0f, 0.1f));

	m_nCntTrans++;		//遷移するまでの時間
}

//==============================================================
//描画処理
//==============================================================
void CRanking::Draw(void)
{

}

//==============================================================
//ランキングの設定処理
//==============================================================
void CRanking::Set(int nNum)
{
	FILE *pFile;
	int nNewRanking;
	int nTemp;

	nNewRanking = nNum;

	if (nNewRanking > m_ranking[MAX_RANK - 1].nRanking)
	{//新しいスコアが最下位より高かったら

		m_ranking[MAX_RANK - 1].nRanking = nNewRanking;		//最下位に新しいスコア代入

		//現在の順位
		for (int nCntRank = 0; nCntRank < MAX_RANK - 1; nCntRank++)
		{
			//次の順位
			for (int nCntData = nCntRank + 1; nCntData < MAX_RANK; nCntData++)
			{
				if (m_ranking[nCntRank].nRanking < m_ranking[nCntData].nRanking)
				{//スコア高かったら

					//スコア入れ替え
					nTemp = m_ranking[nCntRank].nRanking;
					m_ranking[nCntRank].nRanking = m_ranking[nCntData].nRanking;
					m_ranking[nCntData].nRanking = nTemp;
				}
			}
		}

		//更新ランクNo.変更
		for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{
			//ランキングスコアの並べ替え
			if (nNewRanking == m_ranking[nCntRank].nRanking)
			{
				m_nRankUpdate = nCntRank;
			}
		}
	}

	//ランキング保存
	pFile = fopen(FILE_RANK, "w");			//ファイル読み込み

	if (pFile != NULL)
	{//ファイルがある場合

		for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{//データをセーブする

			fprintf(pFile, "%d\n", m_ranking[nCntRank].nRanking);
		}

		//ファイルを閉じる
		fclose(pFile);
	}
}

//==============================================================
//ランキングのリセット
//==============================================================
void CRanking::Reset(void)
{
	FILE *pFile;
	int nCntRank;

	//ランキング情報の初期設定
	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		m_ranking[nCntRank].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//位置の初期化
		m_ranking[nCntRank].nRanking = 0;								//ランキングの初期化
	}

	//ファイルを読み込む
	pFile = fopen(FILE_RANK, "r");

	if (pFile != NULL)
	{//ファイルがある場合

		for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{
			fscanf(pFile, "%d", &m_ranking[nCntRank].nRanking);
		}

		//ファイルを閉じる
		fclose(pFile);
	}
}