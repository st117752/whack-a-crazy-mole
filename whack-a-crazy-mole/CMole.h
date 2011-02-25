#ifndef CMOLE_H_INCLUDED
#define CMOLE_H_INCLUDED

#include "DFCSprite.h"

// Protótipos
class CLevel;

//!Classe CMole: Representa as toupeiras saltitantes
class CMole : public DFCObject
{
    typedef enum eMoleState
    {
        MS_WAITING,
        MS_APPEARING,
        MS_JUMPING,
        MS_ATTACKING,
        MS_RETURNING,
        MS_DISAPPEARING,
        MS_DYING
    } MoleState;

    // ---- MEMBERS ---- //
    private:
    MoleState State;

    public:
    DFCSprite* p_Sprite;
    CLevel* pr_Level;
    DFCLayer* pr_Layer;
    DFCVector GridPos;
    bool bVulnerable;


    // ---- METHODS ---- //
    private:
    void ChangeState(MoleState NewState);
    void OnWaiting();
    void OnAppearing();

    public:
    CMole();
    ~CMole();
    bool Initialize();
    void Execute();
    bool Release();

};


#endif // CMOLE_H_INCLUDED
