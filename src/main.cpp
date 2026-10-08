#include "raylib.h"

int main() {
    // Window Inicialization
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "TopDownProject");

    SetTargetFPS(60);

    // Game Loop 
    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK); // Cleaning the screen every frame

        EndDrawing();
    }

    // Memory Cleaning
    CloseWindow();

    return 0;
}