#ifndef VISHNEVSKIYCRYPTOSYSTEM_H
#define VISHNEVSKIYCRYPTOSYSTEM_H

#include <cstdlib>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>

#include <set>

#include "PrimeGenerator.h"

#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

NTL_CLIENT

class VishnevskiyCryptosystem{
    private:
        vector <ZZ> key;

        int keySize;

    public:
        VishnevskiyCryptosystem(int keySize);

        vector<ZZ> encrypt(ZZ &m);

        ZZ decrypt(std::vector<ZZ> &c);

        void printKey();
        std::vector <ZZ> getKey(){
            //
            return key;
        }

        ZZ getMaxPlaintext();

        void keyGen();


};

void printVector(vector <ZZ> &vec);

bool compareVectors(vector <ZZ> &v1, vector <ZZ> &v2);

#endif // VISHNEVSKIYCRYPTOSYSTEM_H
