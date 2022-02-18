#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    string a;
    int insize;
    fstream f;
    f.open("../data/decompressThis/size.bin", ios::in);
    while(!f.eof()){
		// gets(a);
		// insize= atoi(a.c_str());
    cout<<"First"<<endl;
		getline(f,a);
		insize= atoi(a.c_str());
		cout<<insize<<endl;
    cout<<"Hello"<<endl;
    }
    cout<<"Endl"<<endl;
    f.close();
}