#include <3ds.h>
#include <stdio.h>

void garyShowPage(const char* title, const char* text) {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_B) break;

        consoleClear();
        printf("\x1b[2;10H%s", title);
        printf("\x1b[5;4H%s", text);
        printf("\x1b[28;4HPress B to return");

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
}
