#include <bits/stdc++.h>
#include "compress.cpp"
using namespace std;

int main(){
    char choice;
    cout<<"Compress or Decompress? (c/d): ";
    cin>>choice;
    cout<<endl;
    switch(choice){
        case 'c':
            compress();
            cout<<endl;
            cout<<endl;
            decompress();
           
            break;
        case 'd':
            decompress();
            break;
        default:
            cout<<"Invalid choice!";
    }
    //compress();
    //compress();

    //decompress();
    return 0;
}