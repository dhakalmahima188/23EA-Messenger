#include <iostream>
#include <fstream>
#include <string>

int main ()
{
  std::ifstream file("./data/decompressThis/size.bin");
  std::string str;
  while (std::getline(file, str)) {
    std::cout << str << "\n";
  }
}