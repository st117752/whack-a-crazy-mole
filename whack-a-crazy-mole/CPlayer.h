#ifndef CPLAYER_H_INCLUDED
#define CPLAYER_H_INCLUDED

#include "DFCObject.h"
#include "DFCVector.h"


// Protótipo de classe
class CLevel;
class DFCSprite;
class DFCLayer;

class CPlayer : public DFCObject
{
    typedef enum ePlayerState
    {
        PS_ALIVE,
        PS_ATTACKING,
        PS_DEAD
    } PlayerState;

    // ---- MEMBERS ---- //
    private:
    DFCVector GridPos;
    int iHealth;
    PlayerState State;

    public:
    DFCSprite* p_Sprite;
    DFCLayer* pr_Layer;
    CLevel* pr_Level;

    // ---- METHODS ---- //
    private:
    void ChangeState(PlayerState NewState);
    void OnAlive();
    void OnAttacking();
    void OnDead();
    void Attack();
    void LoseHealth();
    void Die();

    public:
    CPlayer();
    ~CPlayer();
    bool Initialize();
    void Execute();
    bool Release();
    bool IsDead();
    void PositionOnGrid();
};



#endif // CPLAYER_H_INCLUDED
