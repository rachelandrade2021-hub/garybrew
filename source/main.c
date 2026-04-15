#include <3ds.h>

int main(int argc, char *argv[]) {
    gfxInitDefault();
    
    // Your application logic here
    
    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();
        
        if (kDown & KEY_START)
            break;
        
        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }
    
    gfxExit();
    return 0;
}