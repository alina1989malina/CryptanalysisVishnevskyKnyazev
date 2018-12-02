#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>


#include <limits.h>
#include <NTL/ZZ.h>

#include <NTL/ZZ_p.h>
#include <NTL/ZZ_pX.h>
#include <NTL/ZZ_pXFactoring.h>
#include <NTL/mat_poly_ZZ_p.h>
#include <NTL/vec_ZZ_p.h>
#include <NTL/mat_ZZ_p.h>


#include "VishnevskiyCryptosystemTest.h"
#include "VishnevskyCryptosystemKPA.h"

//#include "time_measurement.h"


using namespace std;
using namespace NTL;

NTL_CLIENT


int main(int argc, char *argv[])
{
    //VishnevskiyCryptosystemTest::test();
    //cout<<VishnevskyCryptosystemKPA::testSingleAttack(10, 5)<<endl;

    const int keySizeUpperBound = 500;
    int numIter = 1000;
    int startNumOfPairs = 5;

    if(argc < 2){
        cout << "invalid number of arguments, please try again"<<endl;
        //Sleep(2000);
        exit(0);
    }
    else{
        for(int i=1; i<argc; i++){
            //cout<<argv[i]<<endl;
            if (strcmp(argv[i],"-i")==0){// number of iters
                //We know the next argument *should* be the number of iters
                numIter = atoi(argv[i+1]);
                //cout<<"number of iters = "<<numIter<<endl;
                i++;
            } else if (strcmp(argv[i],"-b")==0){// key size upper bound
                //We know the next argument *should* be the key size upper bound
                keySizeUpperBound = atoi(argv[i+1]);
                //cout<<argv[i+1]<<endl;
                i++;
            } else if (strcmp(argv[i],"-p")==0){// start number of pairs
                //We know the next argument *should* be the start number of pairs
                startNumOfPairs = atoi(argv[i+1]);
                i++;
            }
            else{
                cout<<"not supported type of argument "<<argv[i]<<endl;
            }
        }
    }

    srand ( time(NULL) );
    SetSeed(to_ZZ(time(NULL)));



    ofstream outfileTimings;
    stringstream outfileTimingsFilename;
    outfileTimingsFilename<<"Statistics for numIter = "<<numIter<<".txt";

    outfileTimings.open (outfileTimingsFilename.str().c_str());


    for (int keySize = 10; keySize<keySizeUpperBound; keySize+=50){ //change keySize
        //

        double currentProbability = 0.0;
        int numOfPairs = startNumOfPairs;
        while(currentProbability<0.999){
            //int numIter, int numOfPairs, int keySize
            currentProbability = VishnevskyCryptosystemKPA::testAttack(numIter, numOfPairs, keySize);
            numOfPairs++;
        }

        cout<<endl<<endl;

        //write to file
        outfileTimings<<" for "<<keySize<<"number of modules needed number of pairs is "<<numOfPairs<<endl;

    }//end for (int keySize

    outfileTimings.close();

    system("pause");
}
