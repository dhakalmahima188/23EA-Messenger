#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "compress.cpp"
#include "convert_to_hex.cpp"
#include "convert_to_binary.cpp"
using namespace std;


void decompress(){
	fstream receiverFile;
	receiverFile.open("../data/decompressThis/compressed.bin", ios::in);
	
	while(!receiverFile.eof()){
		huffmanTable h;
		receiverFile>>h;
		//h.PrintHuffmanCode(h.rawstring);
		//h.printHuffmanTable();
		cout<<h.rawstring<<endl;
		
	}
	receiverFile.close();
}