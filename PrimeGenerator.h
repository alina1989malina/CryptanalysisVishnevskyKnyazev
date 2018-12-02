#ifndef PRIMEGENERATOR_H
#define PRIMEGENERATOR_H

#include <cstdlib>

#include <assert.h>
#include <time.h>

#include <iostream>

class PrimeGenerator
{
public:
    PrimeGenerator();

    static unsigned int run(unsigned int maxIndex);
};

#endif // PRIMEGENERATOR_H
