#include <iostream>
#include <fstream>
#include <string>
#include "WriteFile.h"
#include "Config.h"
#include "Cell.h"

WriteFile::WriteFile() {
    WriteFile::counter = 0;
}

WriteFile::~WriteFile() {

}

void WriteFile::write_file (Cell *cells, int N, double time) {
    std::string path = "./output/";
    const int rk_step = 0;

    std::ofstream file;
    file.open(path + "output_" + std::to_string(counter) +  ".dat");

    file << "NumXCells: " << Config::NUM_X_CELLS << std::endl;
    file << "NumGhostCells: " << Config::NUM_GHOST_CELLS << std::endl;
    file << "Time: " << time << std::endl;

    // Write the cells
    for (int i = 0; i < N; i++) {
        file << cells[i].cx << " " << cells[i].u[rk_step] << std::endl;
    }

    WriteFile::counter += 1;

}