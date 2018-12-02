#ifndef VISHNEVSKYCRYPTOSYSTEMKPA_H
#define VISHNEVSKYCRYPTOSYSTEMKPA_H

#include <fstream>

#include "VishnevskiyCryptosystem.h"

#include "time_measurement.h"

class VishnevskyCryptosystemKPA
{
public:
    VishnevskyCryptosystemKPA();

    static std::vector<ZZ> runAttack(vector<ZZ> plaintext, vector<vector<ZZ> > ciphertext);
    static bool testSingleAttack( int numOfPairs, int keySize);
    static double testAttack(int numIter, int numOfPairs, int keySize);
};

#endif // VISHNEVSKYCRYPTOSYSTEMKPA_H
