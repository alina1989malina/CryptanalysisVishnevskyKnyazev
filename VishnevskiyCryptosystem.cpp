#include "VishnevskiyCryptosystem.h"

VishnevskiyCryptosystem::VishnevskiyCryptosystem(int keySize)
{
    this->keySize = keySize;
    keyGen();
}

vector<ZZ> VishnevskiyCryptosystem::encrypt(ZZ &m)
{
  //  cout<<"m = "<<m<<endl;
    vector<ZZ>  ciphertext;
    for (int i = 0; i< keySize; i++ ){
        ciphertext.push_back( m % key[i] );
       // cout<<"key[i] = "<<key[i]<<", m % key[i] = "<<m % key[i]<<endl;
    }
    return ciphertext;

}

ZZ VishnevskiyCryptosystem::decrypt(vector<ZZ> &c)
{
    //
    assert(c.size() == key.size());

    ZZ a = c[0];
    ZZ p = key[0];

    ZZ A, P;

    for (int i = 1 ; i < c.size() ; i++ ){
        //
        A = c[i];
        P = key[i];
        CRT(a, p, A, P);
    }

    return a;

}

void VishnevskiyCryptosystem::keyGen()
{
    int density = 5;
    std::set <ZZ> localKey;
   // cout<<"Start key generation... "<<endl;
    while(localKey.size() <  keySize){
        //generate prime
        unsigned int currentPrimeInt = PrimeGenerator::run((unsigned int)keySize*density) ;

        ZZ currentPrime = to_ZZ( currentPrimeInt );
        //ZZ currentPrime = GenPrime_ZZ(keySize, 80); // keySize is bitlength, 2^-80 is probability to be not prime

       // cout<<"currentPrime = "<<currentPrime<<endl;

        //and add it ... :-)))
        localKey.insert(currentPrime);
    }

    for (std::set<ZZ>::iterator mod = localKey.begin(); mod!=localKey.end(); mod++ ){
        key.push_back( *mod);
    }
   // printKey();
}

void VishnevskiyCryptosystem::printKey(){

    cout<<endl<<"secret key is :"<<endl;
    for (int i = 0; i< keySize; i++){
        cout<<" "<< key[i] ;
    }
    cout<<endl;
}

ZZ VishnevskiyCryptosystem::getMaxPlaintext(){
    //
    ZZ res = to_ZZ(1);

    for(int i = 0; i<key.size(); i++){
        //
        res = res * key[i];
    }

    return res;
}

void printVector(vector <ZZ> &vec){
    //
    cout<<endl;
    for (int i = 0; i< vec.size(); i++){
        cout<<" "<< vec[i] ;
    }
    cout<<endl;
}

bool compareVectors(vector <ZZ> &v1, vector <ZZ> &v2){
    //
    if(v1.size()!= v2.size())
        return false;

    for(int i= 0 ; i<v1.size();i++){
        if (v1[i] != v2[i])
            return false;
    }

    return true;
}



