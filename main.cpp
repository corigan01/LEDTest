#include <iostream>
#include <raylib.h>
#include "FastLED.h"
#include <thread>

using std::cout;
using std::endl;

bool shouldJoin = false;

void looped_loop() {
    while(!shouldJoin) {
        loop();
    }
}

int main() {
    int screenWidth = 1280;
    int screenHeight = 720;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(screenWidth, screenHeight, "LEDTest");

    SetTargetFPS(60);

    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("setup()", 0, 0, 30, WHITE);
    EndDrawing();

    setup();

    std::thread m_loop(looped_loop);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();

        BeginDrawing();

        ClearBackground(BLACK);

        for (int i = 0; i < GetVectorSize(); i++) {
            DrawRectangle( (i % (screenWidth / 50)) * 50, (i / (screenWidth / 50)) * 50, 40, 40,
                           { GetVector()[i].r, GetVector()[i].g, GetVector()[i].b, 255 });

            DrawRectangleLines((i % (screenWidth / 50)) * 50, (i / (screenWidth / 50)) * 50, 40, 40, DARKGRAY);
        }

        DrawFPS(0, 0);

        EndDrawing();
    }

    BeginDrawing();
    ClearBackground(BLACK);

    DrawText("Closing Thread", 0, 0, 30, WHITE);

    EndDrawing();

    shouldJoin = true;

    CloseWindow();

    exit(0);
}
