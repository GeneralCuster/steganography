#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include "CImg.h"

void bytePrint(char byte);
void writeCodeImg(std::string source, std::string destination, std::string message);
void writeCodeBytes(std::string source, std::string destination, std::string message);
void readCode(std::string source);

using namespace std;
using namespace cimg_library;

int main(int argc, char *argv[]){

  CImg<double> image("forest_tiny.bmp");

/*
  string source = argv[1];
  string destination = argv[2];
  string message = argv[3];
*/
  //writeCodeImg(source, destination, message);


  return 0;
}



/*
  HELPER METHODS
*/

void bytePrint(char byte){
  for(int i = 0; i < sizeof(byte) * CHAR_BIT; i++){
    printf("%d", !!((byte << i) & 0x80));
  }
  printf("\n");
}
/*
void writeCodeImg(string source, string destination, string message){

}

void writeCodeBytes(string source, string destination, string message){
  ifstream file;
	size_t fileSize = 0;

	file.open( source, ios::in|ios::binary|ios::ate );

  if (!file) { //Make sure file could be opened
    cerr << "Unable to open file " << source << endl;
    exit(1);
  }

  file.seekg(0, ios::end);
  fileSize = file.tellg(); //set the size, as we'll need it later
	file.seekg(0, ios::beg); // set the pointer to the beginning of the file

  char x = 0;
  char messageByte = 0;
  char out = 0;

  ofstream outputFile (destination, ofstream::binary);

  //We start at 8 to skip the initial 8 byte signature of a .PNG file
  for(int i = 0; i < message.size(); i++){
    for(int j = 6; j >= 0; j = j - 2){
    //We have j start at 6, then go down through 4, 2, and 0 because those are the distances the bits will have to be shifted to occupy only
    //the last two bits of a byte
    file.read((&x), 1);
    messageByte = message.at(i);

    printf("Image byte: ");
    bytePrint(x);
    printf("Message byte: ");
    bytePrint(messageByte);

    messageByte = messageByte << (8 - (j + 2)); //Neutralize any bits to the left of the desired bits
    messageByte = messageByte >> (j + (8 - (j + 2)));//Just moved it over (8 - (j + 2)) many bits, so move it right j + that many

    //Now we need to neutralize the two last bits of the image byte
    //So we move it two right, and then move it back.
    x = x >> 2;
    x = x << 2;

    //Now, we can XOR the bits to create our final edited bit
    out = x ^ messageByte;
    printf("Final byte: ");
    bytePrint(out);
    outputFile << out;
    }
  }

  //Print rest of bytes to output file
  for(int i = message.size(); i < fileSize; i++){
    file.read((&x), 1);
    outputFile << x;
  }

  file.close();
  outputFile.close();
}

void readCode(string source){

}
*/
