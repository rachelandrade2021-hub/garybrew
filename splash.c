#include <3ds.h>
#include <stdio.h>

void garySplash() {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_A) break;

        consoleClear();
        printf("\x1b[10;8H  === THE GARYBREW LAUNCHER ===");
        printf("\x1b[13;10H   A GarySite-inspired app");
        printf("\x1b[17;12H  Press A to continue");

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
}
