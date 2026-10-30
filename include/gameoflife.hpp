#ifndef _GAME_OF_LIFE_
    #define _GAME_OF_LIFE_

    #include <iostream>
    #include <raylib.h>
    #include <vector>
    #include <utility>
    #pragma once
    using namespace std;

    #define FPS 10
    #define GREY Color (19, 19, 19, 225)
    #define CELL_SIZE 4
    #define RE return

class Grid {
    public:
        Grid(int width, int height, int cellsize)
        : rows(height/cellsize), colums(width/cellsize),
          cellsize(cellsize), cells(rows, vector<int>(colums, 0)){};
        void Draw(void);
        void SetValue(int row, int column, int value);
        int GetValue(int row, int col);
        bool Iswidthbounds(int row, int col);
        int getrows() {return rows;};
        int getcol() {return colums;}
        void FillRandom();
    private:
        int rows;
        int colums;
        int cellsize;
        vector<vector<int>> cells;
};

class Simulation {
    public:
        Simulation(int width, int height, int cellsize)
        : grid(width, height, cellsize), tempgrid(width, height, CELL_SIZE) {grid.FillRandom();};
        void draw(void);
        void setcellvalue(int row, int column, int value);
        int countliveweighbors(int row, int col);
        void update();
    private:
        Grid grid;
        Grid tempgrid;
};

#endif