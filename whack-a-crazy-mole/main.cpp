/*
 * main.cpp
 *
 *  Created on: 03/01/2011
 *      Author: Danilo
 */

#include "DFCMain.h"
#include "CLevel.h"

int main( int argc, char* args[] )
{
    DFCMain Main;

    Main.Video.SetVideoMode(false, DFCVector(600.0f, 900.0f));

    CLevel Level;
    Main.AddScene(&Level);

    Main.Initialize();

    while (!Main.Ended())
    {
        Main.Loop();

        if (Main.Input.KeyPressed(SDLK_ESCAPE))
        {
            Main.Exit();
        }
        if (Main.Input.KeyPressed(SDLK_p))
        {
            if (Main.IsPaused())
            {
                Main.Resume();
            }
            else
            {
                Main.Pause();
            }
        }
    }

    Main.Release();

    return 0;
}
