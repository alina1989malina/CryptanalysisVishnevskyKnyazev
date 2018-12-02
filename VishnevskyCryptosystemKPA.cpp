#include "VishnevskyCryptosystemKPA.h"

VishnevskyCryptosystemKPA::VishnevskyCryptosystemKPA()
{
}

vector<ZZ> VishnevskyCryptosystemKPA::runAttack(vector<ZZ> plaintext, vector<vector<ZZ> > ciphertext){
    //
    int keySize = ciphertext[0].size();

    vector <ZZ> result;

    for(int i = 0 ; i < keySize ; i++){
        //
        ZZ d = plaintext[0] - ciphertext[0][i];

        for(int j = 0 ; j < plaintext.size(); j++){
            //
            d = GCD(d, plaintext[j] - ciphertext[j][i]);
        }

        result.push_back(d);
    }

    //
    return result;


}

bool VishnevskyCryptosystemKPA::testSingleAttack( int numOfPairs, int keySize){
    //
    VishnevskiyCryptosystem vishnevskiyCryptosystem( keySize );


    std::vector <ZZ> plaintexts;

    std::vector <std::vector <ZZ> > ciphertexts;

    //cout<<endl<<"testSingleAttack"<<endl;

    for (int i = 0;i<numOfPairs;i++){
        //
        //ZZ m;

        //RandomLen(m, bitLenOfMessages) ;
        //SetSeed(to_ZZ(time(NULL)));

        ZZ m = RandomBnd(vishnevskiyCryptosystem.getMaxPlaintext());
        plaintexts.push_back( m );

        ciphertexts.push_back( vishnevskiyCryptosystem.encrypt(m) );

       // cout<<"plaintext = "<<m<<" , ciphertext = ";
      //  printVector( ciphertexts[ciphertexts.size()-1] );
       // cout<<endl;
    }

    vector <ZZ> key = runAttack(plaintexts, ciphertexts);

  ///  cout<< " the founded vector is  ";
   // printVector(key);

    //cout<< " and the true key is ";
    //vishnevskiyCryptosystem.printKey();

 //   cout<<" ===================="<<endl;

    vector <ZZ> trueKey = vishnevskiyCryptosystem.getKey();
    return compareVectors(key, trueKey );
}

double VishnevskyCryptosystemKPA::testAttack(int numIter, int numOfPairs, int keySize){

    int numOfSuccess = 0;

    ofstream outfileTimings;
    stringstream outfileTimingsFilename;
    outfileTimingsFilename<<"numIter = "<<numIter<<", numOfPairs = "<<numOfPairs<<", keySize = "<<keySize<<".txt";

    cout<<"numIter = "<<numIter<<", numOfPairs = "<<numOfPairs<<", keySize = "<<keySize<<endl;
    outfileTimings.open (outfileTimingsFilename.str().c_str());

    // helper variables for time management
    struct timeval start, end;

    // first time cut
    gettimeofday(&start, NULL);

    for (int i = 0 ; i < numIter ;i++){
        if (testSingleAttack(numOfPairs, keySize)){
            //
            numOfSuccess++;
        }
    }

    cout<<"numOfSuccess = "<<numOfSuccess<<"/"<<numIter<<endl<<endl;

    gettimeofday(&end, NULL);//second time cut
    outfileTimings<<endl<<numIter<<" attacks is done in "<<eval_time(start,end)<<" milliseconds"<<endl;
    outfileTimings<<"average attack is done in "<<eval_time(start,end)/double(numIter)<<" milliseconds"<<endl;

    outfileTimings<<"The probability of success is "<<double(numOfSuccess)/double(numIter)<<endl;

    outfileTimings.close();
    return double(numOfSuccess)/double(numIter);

}
