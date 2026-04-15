#include <3ds.h>
#include <stdio.h>
#include "gary.h"

int main(int argc, char *argv[]) {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
    
    garySplash();
    garyMenu();
    
    gfxExit();
    return 0;
}