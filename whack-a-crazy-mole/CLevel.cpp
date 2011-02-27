#include "CLevel.h"

//------------------------------------------------
// Nome: CLevel()
// Desc: Construtor padr�o
// Pams: nenhum
//------------------------------------------------
CLevel::CLevel()
{
    p_LayBG = NULL;
    p_LayMoles = NULL;
    p_Player = NULL;
}

//------------------------------------------------
// Nome: ~CLevel()
// Desc: Destrutor padr�o
// Pams: nenhum
//------------------------------------------------
CLevel::~CLevel()
{
    Release();
}

//------------------------------------------------
// Nome: Initialize()
// Desc: Inicializa os componentes da Scene
// Pams: nenhum
//------------------------------------------------
bool CLevel::Initialize()
{
    int iImageBG = AddTileImage("./images/background.png", DFCVector(600,600));
    p_LayBG = CreateLayer(DFCVector(600,600), DFCVector(1,1));
    p_LayBG->SetBrick(DFCVector(0,0), iImageBG, 0);
    p_LayMoles = CreateLayer(DFCVector(600,600), DFCVector(1,1));
    p_LayPlayer = CreateLayer(DFCVector(600,600), DFCVector(1,1));
    p_Player = CreatePlayer();

    int j = 0;
    for (int i = 0; i < (int)ListSprHoles.size(); i++)
    {
    	ListSprHoles[i] = p_LayBG->CreateSprite("./images/hole.png", DFCVector(150,150));
    	ListSprHoles[i]->Position.fx = 27.5f + i*200.0f;
    	ListSprHoles[i]->Position.fy = 27.5f + j*200.0f;
    	if ((i+1) % 3) j++;
    }

    return true;

    CreateMole(DFCVector(0,0));
}

//------------------------------------------------
// Nome: Execute()
// Desc: Executa a Scene
// Pams: nenhum
//------------------------------------------------
void CLevel::Execute()
{
    for (int i = 0; i < (int) ListMoles.size(); i++)
    {
        ListMoles[i]->Execute();
    }

    if (p_Player)
    {
    	p_Player->Execute();
    }
}

//------------------------------------------------
// Nome: Release()
// Desc: Libera a classe da mem�ria
// Pams: nenhum
//------------------------------------------------
bool CLevel::Release()
{
    for (int i = (int) ListMoles.size()-1; i>=0; i--)
    {
        ListMoles[i]->Release();
        delete ListMoles[i];
    }

    ListMoles.clear();

    DeletePlayer();

    DFCScene::Release();

    return true;
}

//------------------------------------------------
// Nome: CreateMole(DFCVector GridPos)
// Desc: Cria uma CMole e a adiciona na lista de CMoles ativas
// Pams: GridPos: Posi��o da nova CMole na Grid
//------------------------------------------------
CMole* CLevel::CreateMole(DFCVector GridPos)
{
    CMole* p_Mole = new CMole();

    if (p_Mole)
    {
        p_Mole->bVulnerable = false;
        p_Mole->GridPos = GridPos;
        p_Mole->pr_Layer = p_LayMoles;
        p_Mole->pr_Level = this;
        p_Mole->Initialize();
        ListMoles.push_back(p_Mole);
        return p_Mole;
    }

    return NULL;
}

//------------------------------------------------
// Nome: DeleteMole(CMole** p_Mole)
// Desc: Deleta CMole e a remove da lista de CMoles ativas
// Pams: p_Mole: ponteiro com refer�ncia para a CMole a ser deletada
//------------------------------------------------
bool CLevel::DeleteMole(CMole** p_Mole)
{
    if (p_Mole && *p_Mole)
    {
        int iSize = (int) ListMoles.size();

        for (int i = iSize-1; i >= 0; i--)
        {
            ListMoles[i]->Release();
            delete ListMoles[i];
            *p_Mole = NULL;
            ListMoles.erase(ListMoles.begin()+i);
            return true;
        }
    }

    return false;
}

//------------------------------------------------
// Nome: CreatePlayer()
// Desc: Cria o CPlayer
// Pams: nenhum
//------------------------------------------------
CPlayer* CLevel::CreatePlayer()
{
	CPlayer* p_PlayerTemp = new CPlayer();

	p_PlayerTemp->pr_Level = this;
	p_PlayerTemp->pr_Layer = p_LayPlayer;
	p_PlayerTemp->Initialize();

	return p_PlayerTemp;
}

bool CLevel::DeletePlayer()
{
    if (p_Player)
    {
	p_Player->Release();
	p_Player = NULL;
    }

    return true;
}
