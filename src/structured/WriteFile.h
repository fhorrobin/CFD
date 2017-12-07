#ifndef WRITEFILE_H_
#define WRITEFILE_H_
#include "Cell.h"

class WriteFile {
    public:
        static void write_file (Cell cells[][Config::NY], int NX, int NY, double time, int counter);
};

#endif
