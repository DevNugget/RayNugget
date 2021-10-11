#include "raylib.h"

int main(void)
{

    // Initialization -------------------
    // Setup Init ::
    const int fps = 60;

    const int screenWidth = 800;
    const int screenHeight = 600;

    const char windowTitle[9] = "RayNugget";

    InitWindow(screenWidth, screenHeight, windowTitle);

    SetTargetFPS(fps);

    // Game Init ::
    float speed = 4.0f;

    Vector2 playerPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    //-----------------------------------

    // Loading --------------------------
    Texture2D player = LoadTexture("textures/playerSprite.png");
    //-----------------------------------

    // Main Game Loop -------------------
    while (!WindowShouldClose())
    {
        // Update
        //-------------------------------
        if (IsKeyDown(KEY_D)) playerPosition.x += speed;
        if (IsKeyDown(KEY_A)) playerPosition.x -= speed;
        if (IsKeyDown(KEY_W)) playerPosition.y -= speed;
        if (IsKeyDown(KEY_S)) playerPosition.y += speed;
        //-------------------------------

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            DrawText("RayNugget", screenHeight/2, screenWidth/2, 30, LIGHTGRAY);
            DrawText("Movement Test", 10, 10, 30, LIGHTGRAY);

            DrawTextureV(player, playerPosition, WHITE);

        EndDrawing();

    } //---------------------------------

    // De-Initialization
    UnloadTexture(player);

    CloseWindow();

    return 0;

}