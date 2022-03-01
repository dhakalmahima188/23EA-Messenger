#include "linkedlist.cpp"
#include "compress.cpp"
#include "login.cpp"

string decodedString = "";
string decode(string sdr, string rec){
    string path="../data/decompressThis/";
    string extension= ".bin";
    fstream receiverFile;
    receiverFile.open((path+rec+"/"+sdr+extension).c_str(), ios::in);
    while(!receiverFile.eof()){
        huffmanTable hTable;
        receiverFile>>hTable;
        string encodedString;

        encodedString=hTable.rawstring;
        LinkList l;
        int hTableSize = l.getSize();
        l.initialize(hTableSize);

        
        hTable.printHuffmanTable();
        cout<<encodedString<<endl;

        int i = 0;
        while(encodedString.length() > 0){
            char c = encodedString[0];
            for(int k = 0 ; k < l.getSize() ; k++){
                cout<<"k: "<<k<<endl;
                cout<<"code: "<<hTable.huffTable[l.getdataatindex(k)].code[i]<<endl;
                cout<<"tableindex: "<<l.getdataatindex(k)<<endl;
                if(hTable.huffTable[l.getdataatindex(k)].code[i] != c){
                    l.removeatindex(k);
                }
            }
            ++i;
            if(l.getSize() == 1){
                decodedString += hTable.huffTable[l.getHeadIndex()].data;
                i = 0;
                l.deleteallnode();
                l.initialize(hTableSize);
            }
            encodedString = encodedString.substr(1);
        }
        
        
    }
    return decodedString;
};