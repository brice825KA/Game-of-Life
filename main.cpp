// Main of Program Game of Life
#include "include/gameoflife.hpp"

int main(int argv, char **argc) {
    cout << "Begin Simulation Game of Life" << endl;
    const int height =  800;
    const int wight = 800;
    int fps = 12;

    InitWindow(wight, height, "Game of Life");
    SetTargetFPS(fps);
    Simulation sim(wight, height, CELL_SIZE);
    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            Vector2 moupos = GetMousePosition();
            int row = moupos.y / CELL_SIZE;
            int col = moupos.x / CELL_SIZE;
            sim.ToggleCell(row, col);
        }
        if (IsKeyPressed(KEY_ENTER)) {
            sim.Start();
            SetWindowTitle("Game life is Runnig .... ");
        }
        else if (IsKeyPressed(KEY_SPACE)) {
            sim.Stop();
            SetWindowTitle("Game of life has stopped");
        }
        else if (IsKeyPressed(KEY_F)) {
            fps += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyPressed(KEY_S)) {
            if (fps > 5)
                fps -= 2;
            SetTargetFPS(fps);
        }
        else if (IsKeyPressed(KEY_R)) {
            sim.CreateRandState();
        }
        else if (IsKeyPressed(KEY_C)) {
            sim.ClearGrid();
        }
        sim.update(); 
        BeginDrawing();
        ClearBackground(GREY);
        sim.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

// Simulation Loop
// Event Handling
// Updating State
// Drawing Objet