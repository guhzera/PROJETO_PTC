#include <iostream>
//#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "Enquadramento.h"
 
using namespace std;
 
int main(int argc, char * argv[]) {
  string path;
 
  if (argc > 1) path = argv[1];
  else path = "normal.pkt";
 
  fstream arq(path);
  if (not arq.is_open()) {
    perror("ao abrir arquivo de quadros ");
    return errno;
  }
  Enquadramento proto(arq, 8, 32);
  char quadro[32];

	while(true){
		try{
  		int bytes = proto.recebe(quadro);
			if(bytes==0)break;
		}catch(exception e){
			cerr<< "erro ao receber quadro!"<<endl;
		}
	}

}
