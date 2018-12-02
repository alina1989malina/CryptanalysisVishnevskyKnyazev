#include "VishnevskiyCryptosystemTest.h"

VishnevskiyCryptosystemTest::VishnevskiyCryptosystemTest()
{
}

void VishnevskiyCryptosystemTest::test(){
    //
    VishnevskiyCryptosystem vishnevskiyCryptosystem(3);

    vishnevskiyCryptosystem.printKey();


    srand (time(NULL));
    ZZ message = to_ZZ(std::rand())% (vishnevskiyCryptosystem.getMaxPlaintext());
    vector <ZZ> ciphertext = vishnevskiyCryptosystem.encrypt(message);

    cout<<" ciphertext: "<<endl;
    for (int i = 0; i<ciphertext.size(); i++){
        //
        cout<<ciphertext[i]<<" ";
    }
    cout<<endl;


    assert( vishnevskiyCryptosystem.decrypt( ciphertext ) == message );

    cout<<"decrypt results: "<<vishnevskiyCryptosystem.decrypt( ciphertext )<<endl;

}
