#include "../include/gameoflife.hpp"

void Simulation::draw(void) {
    grid.Draw();
}

void Simulation::setcellvalue(int row, int column, int value) {
    grid.SetValue(row, column, value);
}

int Simulation::countliveweighbors(int row, int col) {
    auto liveweighbors = 0;
    vector<pair<int, int>> neighborsoffsets = {
        {-1, 0}, // directly above
        {1, 0}, // directly below
        {0, -1}, // to the left
        {0, 1}, // to the right
        {-1, -1}, // diagonal upper left
        {-1, 1}, // diagonal upper right
        {1, -1}, // diagonal lower left
        {1, 1} // diagonal lower right
    };

    for (const auto& offset: neighborsoffsets) {
        int neighborrow = (row + offset.first + grid.getrows()) % grid.getrows();
        int neighborcolumn = (col + offset.second + grid.getcol()) % grid.getcol();
        liveweighbors += grid.GetValue(neighborrow, neighborcolumn);
    }
    RE liveweighbors;
}

void Simulation::update() {
    for (int i = 0; i < grid.getrows(); i += 1) {
        for (int j = 0; j < grid.getcol(); j += 1) {
            int liveweighbors = countliveweighbors(i, j);
            int cellvalue = grid.GetValue(i, j);

            if (cellvalue == 1) {
                if (liveweighbors > 3 || liveweighbors < 2)
                    tempgrid.SetValue(i, j, 0);
                else
                    tempgrid.SetValue(i, j, 1);
            }
            else {
                if (liveweighbors == 3)
                    tempgrid.SetValue(i, j, 1);
                else
                    tempgrid.SetValue(i, j, 0);
            }
        }
    }
    grid = tempgrid;
}



