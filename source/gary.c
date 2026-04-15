#include <3ds.h>
#include <stdio.h>
#include "gary.h"

void garySplash(void) {
    // Display splash screen
    printf("=====================================");
    printf("      GaryBrew 3DS v1.0\n");
    printf("  A GarySite-inspired homebrew app\n");
    printf("=====================================
\n");
    svcSleepThread(3000000000); // Sleep for 3 seconds
}

void garyMenu(void) {
    // Display main menu
    printf("Main Menu:\n");
    printf("1. Show Page\n");
    printf("2. Exit\n");
    garyShowPage();
}

void garyShowPage(void) {
    // Display page content
    printf("\nGary's Page\n");
    printf("Welcome to GaryBrew!\n");
}