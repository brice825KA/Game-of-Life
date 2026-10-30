#include "../include/gameoflife.hpp"

void Grid::Draw(void) {
    for (auto row = 0; row < rows; row ++) {
        for (auto column = 0; column < colums; column ++) {
            Color color = cells[row][column] ? Color(0, 225, 0, 225) : Color(55, 55, 55, 225);
            DrawRectangle(column * cellsize, row * cellsize, cellsize - 1, cellsize - 1, color);
        } 
    }
}

void Grid::SetValue(int row, int column, int value) {
    if (Iswidthbounds(row, column))
        cells[row][column] = value;
}

int Grid::GetValue(int row, int col) {
    if (Iswidthbounds(row, col))
        RE cells[row][col];
    RE 0;
}

bool Grid::Iswidthbounds(int row, int col) {
    if ((row >= 0 && row < rows) && (col >= 0 && col < colums))
        RE true;
    RE false;
}

void Grid::FillRandom(){
    for (int row = 0; row < rows; row ++) {
        for (int col = 0; col < colums; col += 1) {
            int randomval = GetRandomValue(0, 1);
            cells[row][col] = (randomval);
        }
    }
}
