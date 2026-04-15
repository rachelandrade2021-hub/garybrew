#include <3ds.h>
#include <stdio.h>

void garyShowPage(const char* title, const char* text);

void garyMenu() {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    int selection = 0;
    const char* items[] = {
        "About Gary",
        "Gary's Cave",
        "Gary Video",
        "Gary Facts",
        "Gary Food"
    };
    const char* pages[][2] = {
        {"About Gary",    "Gary is a cool dude\nwho runs GarySite.\nHe likes cool things."},
        {"Gary's Cave",   "Gary's Cave is where\nGary hangs out.\nVery cozy in there."},
        {"Gary Video",    "Gary makes videos\nabout stuff he likes.\nCheck them out!"},
        {"Gary Facts",    "Fact: Gary is great.\nFact: Gary is cool.\nFact: GarySite rules."},
        {"Gary Food",     "Gary enjoys:\n- Pizza\n- Snacks\n- Cool drinks"}
    };
    int count = 5;

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_DOWN) selection = (selection + 1) % count;
        if (kDown & KEY_UP)   selection = (selection - 1 + count) % count;
        if (kDown & KEY_A)    garyShowPage(pages[selection][0], pages[selection][1]);
        if (kDown & KEY_B)    break;

        consoleClear();
        printf("\x1b[2;10H=== GARYBREW MENU ===");
        printf("\x1b[3;8H(UP/DOWN to move, A to select)");

        for (int i = 0; i < count; i++) {
            if (i == selection)
                printf("\x1b[%d;8H> %s <", 6 + i, items[i]);
            else
                printf("\x1b[%d;10H%s", 6 + i, items[i]);
        }

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
}
