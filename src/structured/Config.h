/**
 * Configuration constants for CFD code
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include <string>

class Config {
    public:
        static const int NUM_X_CELLS = 100;
        static const int NUM_GHOST_CELLS = 3;
        static const int NUM_RK_STEPS = 1;
        static const double STOPPING_TIME = 2.0;
        static const int MAX_TIME_ITER = 100000;
        static const double MIN_X = -1;
        static const double MAX_X = 1;
        static const double ADVECTION_VELOCITY = 1.0;
        static const double COURANT_NUMBER = 0.8;
};

#endif
