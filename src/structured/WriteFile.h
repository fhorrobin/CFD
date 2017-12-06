#ifndef WRITEFILE_H_
#define WRITEFILE_H_
#include "Cell.h"

class WriteFile {
    private:
        static int counter;
    public:
        WriteFile();
        ~WriteFile();
        static void write_file (Cell *cells, int N, double time);
};

#endif
