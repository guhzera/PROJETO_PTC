#include <iostream>
#include "Serial.h"
 #include "Enquadramento.h"
 
using namespace std;
 
int main() {
  Serial rf("/dev/ttyUSB0", B9600);
  string msg = "um teste ...";
 
 Enquadramento proto(rf, 8, 32);
 char quadro[32];
 proto.envia("abcdefgh",8);
 
  //int n = rf.write(msg.c_str(), msg.size());
 
  //cout << "Enviou " << n << " bytes" << endl;
 
  //n = rf.read(buffer, 32);
 
  //cout << "Recebeu " << n << " bytes: ";
 
  //cout.write(buffer, n);
 
  //cout << endl;
}
