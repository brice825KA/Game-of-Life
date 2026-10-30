// Main of Program Game of Life
#include "include/gameoflife.hpp"

int main(int argv, char **argc) {
    cout << "Begin Simulation Game of Life" << endl;
    const int height =  800;
    const int wight = 800;

    InitWindow(wight, height, "Game of Life");
    SetTargetFPS(FPS);
    Simulation sim(wight, height, CELL_SIZE);
    while (!WindowShouldClose()) {
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