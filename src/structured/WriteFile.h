#ifndef WRITEFILE_H_
#define WRITEFILE_H_
#include "Cell.h"

class WriteFile {
    public:
        static void write_file (Cell *cells, int N, double time, int counter);
};

#endif
