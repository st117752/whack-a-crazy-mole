#ifndef CLEVEL_H_INCLUDED
#define CLEVEL_H_INCLUDED

#include <vector>
#include "DFCScene.h"
#include "CMole.h"
#include "CPlayer.h"

//!Classe CLevel: Representa um level (stage) do jogo
class CLevel : public DFCScene
{
    private:
    //!Ponteiro para a layer de background
    DFCLayer* p_LayBG;

    //!Ponteiro para a layer das CMoles
    DFCLayer* p_LayMoles;

    //!Ponteiro para a layer do CPlayer
    DFCLayer* p_LayPlayer;

    //!Lista de Moles ativas
    vector<CMole*> ListMoles;

    //!Lista de Buracos
    vector<DFCSprite*> ListSprHoles;

    //!Ponteiro para o Player
    CPlayer* p_Player;

    CPlayer* CreatePlayer();

    public:
    /*!
     * Construtor padrão
     */
    CLevel();

    /*!
     * Destrutor padrão
     */
    ~CLevel();

    /*!
     * Libera a classe da memória
     */
    bool Release();

    /*!
     * Inicializa os componentes da Scene
     & @return true se bem sucedido, false se houve erro
     */
    bool Initialize();

    /*!
     * Executa a Scene
     */
    void Execute();

    /*!
     * Cria uma CMole e a adiciona na lista de CMoles ativas
     * @param GridPos: Posi��o da nova CMole na Grid
     * @return ponteiro para a CMole criada
     */
    CMole* CreateMole(DFCVector GridPos);

    /*!
     * Deleta CMole e a remove da lista de CMoles ativas
     * @param p_Mole: ponteiro com refer�ncia para a CMole a ser deletada
     * @return true se bem sucedido, false se houve erro
     */
    bool DeleteMole(CMole** p_Mole);

    bool DeletePlayer();

};

#endif // CLEVEL_H_INCLUDED
