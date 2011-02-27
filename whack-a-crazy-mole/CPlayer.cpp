#include "CPlayer.h"

#include "DFCMain.h"
#include "CLevel.h"

CPlayer::CPlayer()
{
    p_Sprite = NULL;
    pr_Layer = NULL;
    pr_Level = NULL;
}

CPlayer::~CPlayer()
{

}

bool CPlayer::Initialize()
{
    iHealth = 3;
    GridPos = DFCVector(0,0);
    State = PS_ALIVE;

    p_Sprite = pr_Layer->CreateSprite("./images/selection.png", DFCVector(150.0f,150.0f));
    
    if (!p_Sprite)
    {
    	return false;
    }

    p_Sprite->pr_Image->SetColorKey(0,0,0);
    p_Sprite->Position = DFCVector(30.0f,22.0f);

    return true;
}

void CPlayer::Execute()
{
	switch(State)
	{
	case PS_ALIVE:
		OnAlive();
        PositionOnGrid();
		break;
	case PS_ATTACKING:
		OnAttacking();
		break;
	case PS_DEAD:
		OnDead();
		break;
	}
}

bool CPlayer::Release()
{
    if (p_Sprite)
    {
	p_Sprite->Release();
    }

    return true;
}

bool CPlayer::IsDead()
{
	if (iHealth <= 0)
		return true;
	else
		return false;
}

void CPlayer::ChangeState(PlayerState NewState)
{
	if (NewState != State)
	{
		State = NewState;
	}
}

void CPlayer::OnAlive()
{
	if (pr_Level->pr_Main->Input.KeyPressed(SDLK_RIGHT))
	{
		if (GridPos.fx < 2)
		{
			GridPos.fx++;
		}
	}

	if (pr_Level->pr_Main->Input.KeyPressed(SDLK_LEFT))
	{
		if (GridPos.fx > 0)
		{
			GridPos.fx--;
		}
	}

        if (pr_Level->pr_Main->Input.KeyPressed(SDLK_DOWN))
	{
		if (GridPos.fy < 2)
		{
			GridPos.fy++;
		}
	}

	if (pr_Level->pr_Main->Input.KeyPressed(SDLK_UP))
	{
		if (GridPos.fy > 0)
		{
			GridPos.fy--;
		}
	}

        
}

void CPlayer::OnAttacking()
{

}

void CPlayer::OnDead()
{

}

void CPlayer::Attack()
{

}

void CPlayer::LoseHealth()
{
	iHealth--;
}

void CPlayer::Die()
{
	ChangeState(PS_DEAD);
}

void CPlayer::PositionOnGrid()
{
	DFCVector v;

	v.fx = (float) (27.5f + GridPos.fx*200.0f);
	v.fy = (float) (27.5f + GridPos.fy*200.0f);

	p_Sprite->Position = v;
}
