#include <iostream>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <set>
#include <vector>

using namespace std;


int main()
{
    cout<<endl;

    srand(time(NULL)); //generate random each time

    bitset<8> bits; //creates bitset size of 8 with 1s and 0s
    for(int i = 0; i < 8; ++i)
        bits[i]= rand()%2;
    cout<<bits<<" which is "<<bits.to_ulong()<<" in decimal value!\n";
    // .to_ulong - returns Integer value with the same bit representation as the bitset object.

    bitset<8> bits2(124); //way to set bitset value to 124 in 1s and 0s in 8bits
    cout<<bits2<<" which is "<<bits2.to_ulong()<<" in decimal value!\n"<<endl;


    cout<<endl<<endl;

    set<int> myset = {0,1,3,7};
    cout<<"myset contains: [ ";
    for(auto i: myset)
        cout<<i<<" ";
    cout<<"]\n";
    vector<bitset<3> > bit3 ;
    for(auto i : myset)
        bit3.push_back(i);

    for(auto element: bit3)
        cout<<element<<"-";
    cout<<endl;


    cout<<bit3[0]<<" is  "<<bit3[0].to_ulong()<<endl;
    cout<<bit3[0]<<" is  "<<bit3[0].to_string()<<endl;
    for(auto element: bit3)
        cout<<element<<" = "<<element.to_ulong()<<endl;



    return 0;
}
