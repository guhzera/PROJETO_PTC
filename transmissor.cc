#include <iostream>
//#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <errno.h>
#include "Enquadramento.h"
#include "Serial.h"
 
using namespace std;
 

int main(int argc, char * argv[]) {
  string path;
 
  if (argc > 1) path = argv[1];
  else path = "transmissor.pkt";
 
  fstream arq(path);
  if (not arq.is_open()) {
    perror("ao abrir arquivo de quadros ");
    return errno;
  }
 
 Enquadramento proto(arq, 8, 32);
 char quadro[32];

  
proto.envia("abcdefgh",8);
proto.envia("12345678",8);
proto.envia("ABCDEFGH",8);

}

