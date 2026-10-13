#include "raylib.h"
#include "Entities/Player.h"

int main() {
    // Window Inicialization
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "TopDownProject");

    SetTargetFPS(60);

    Player p({ screenWidth/2,screenHeight/2 }, 50, 50, RED);

    // Game Loop 
    while (!WindowShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();
        p.update(deltaTime);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK); // Cleaning the screen every frame

        p.draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Memory Cleaning
    CloseWindow();

    return 0;
}