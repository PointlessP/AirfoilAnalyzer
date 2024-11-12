#include <stdio.h>
#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "filehandle.h"

int main()
{
    int screenWidth = 1920/2;
    int screenHeight = 1080/2;
    const char* title = "Airfoil Analyzer V 0.0.1";
    Vector2 midOffset = {screenWidth*0.125f, screenHeight/2};

    // Open and Initialize Window
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, title);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    SetTargetFPS(60);

    // Set GUI Style
    GuiSetStyle(CHECKBOX, TEXT_ALIGNMENT, TEXT_ALIGN_LEFT);
    GuiSetStyle(COLORPICKER, HUEBAR_PADDING, -125);
    
    // Get Airfoil
    char* filename = "airfoilData/naca0012.dat";
    AirfoilFile* airfoil = readAirfoilFile(filename);

    
    while (!WindowShouldClose())
    {
        if (IsWindowResized()) // Handle Window Resizing
        {
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
            Vector2 newOffset = {screenWidth*0.125f, screenHeight/2};
            midOffset = newOffset;
        }
        
        // Rendering Stuff
        BeginDrawing();
            ClearBackground(BLACK);

            for (int i = 0; i < airfoil->pointCount-1; i++) {
                DrawLineV(Vector2Add(Vector2Scale(airfoil->points[i], screenWidth * 0.75f), midOffset), Vector2Add(Vector2Scale(airfoil->points[i+1], screenWidth * 0.75f), midOffset), WHITE);
            }

        EndDrawing();
    }
    
    CloseWindow();
    freeAirfoilFile(airfoil);

    return 0;
}