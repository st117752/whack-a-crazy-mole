#include "CMole.h"
#include "CLevel.h"
#include "DFCMain.h"

CMole::CMole()
{
    p_Sprite = NULL;
    pr_Level = NULL;
}

CMole::~CMole()
{
    Release();
}

bool CMole::Initialize()
{
    p_Sprite = pr_Layer->CreateSprite("./images/spr_Kangoo.bmp", DFCVector(75.0f,90.0f));
    p_Sprite->pr_Image->SetColorKey(0xFF, 0x0, 0xFF);
    p_Sprite->Position = DFCVector(0,0);
    p_Sprite->AddAnimation(10, true, 6, 0, 1, 2, 3, 4, 5);
    p_Sprite->AddAnimation(10, false, 6, 6, 7, 8, 9, 10, 11);
    p_Sprite->SetCurrentAnimation(1);

    State = MS_WAITING;

    return true;
}

void CMole::Execute()
{
    switch(State)
    {
        case MS_WAITING:
            OnWaiting();
            break;
        case MS_APPEARING:
            OnAppearing();
            break;
        case MS_JUMPING:
            break;
        case MS_ATTACKING:
            break;
        case MS_RETURNING:
            break;
        case MS_DISAPPEARING:
            break;
        case MS_DYING:
            break;
    }
}

bool CMole::Release()
{
	p_Sprite->Release();
    return true;
}

void CMole::ChangeState(MoleState NewState)
{
    if (State != NewState)
    {
        State = NewState;
    }
}

void CMole::OnWaiting()
{
    p_Sprite->SetCurrentAnimation(0);

    if (pr_Level->pr_Main->Input.KeyPressed(SDLK_SPACE))
    {
        ChangeState(MS_APPEARING);
    }

    if (pr_Level->pr_Main->Input.KeyPressed((SDLK_RIGHT)))
    {
        p_Sprite->Position.fx++;
    }

    if (pr_Level->pr_Main->Input.KeyPressed((SDLK_LEFT)))
    {
        p_Sprite->Position.fx--;
    }

    if (pr_Level->pr_Main->Input.KeyPressed((SDLK_DOWN)))
    {
        p_Sprite->Position.fy++;
    }

    if (pr_Level->pr_Main->Input.KeyPressed((SDLK_UP)))
    {
        p_Sprite->Position.fy--;
    }
}

void CMole::OnAppearing()
{
    p_Sprite->SetCurrentAnimation(1);

    if (p_Sprite->Animations[1]->Ended())
    {
        ChangeState(MS_WAITING);
    }
}
