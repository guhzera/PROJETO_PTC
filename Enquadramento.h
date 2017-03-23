#include <cstdint>
#include "Serial.h"
#include <fstream>
#include <string.h>
#include <assert.h>

#ifndef FRAMMING_H_
#define FRAMMING_H_

#define MAX_SIZE 4096
#define PPPINITFCS16    0xffff  /* Initial FCS value */
#define PPPGOODFCS16    0xf0b8  /* Good final FCS value */


//para compilar
//g++ -o teste Enquadramento.cc main.cc -std=c++11

using namespace std;

class Enquadramento {
 public:
  Enquadramento(Serial & dev, int bytes_min, int bytes_max);
 // Enquadramento(fstream & dev, int bytes_min, int bytes_max);
 // virtual ~Enquadramento();
 
  // envia o quadro apontado por buffer
  // o tamanho do quadro é dado por bytes
  void envia(char const * buffer, int bytes);
 
  // espera e recebe um quadro, armazenando-o em buffer
  // retorna o tamanho do quadro recebido
  int recebe(char * buffer);
 
 private:
  int min_bytes, max_bytes;//preenchimento de octeto  
  //fstream & porta;
  Serial & porta;
  unsigned char buffer[MAX_SIZE];//buffer de armazenamento dos quadros recebidos
  enum Estados {Q0, Q1, Q2};//tipos de estados   
  int n_bytes; // bytes recebidos pela MEF até o momento   
  int estado;// estado atual da MEF
 
  // aqui se implementa a máquina de estados de recepção
  // retorna true se reconheceu um quadro completo
  bool handle(char byte);

  // verifica o CRC do conteúdo contido em "buffer". Os dois últimos 
  // bytes desse buffer contém o valor de CRC
  bool check_crc(unsigned char * buffer, int len);
  // gera o valor de CRC dos bytes contidos em buffer. O valor de CRC
  // é escrito em buffer[len] e buffer[len+1]
  void gen_crc(unsigned char * buffer, int len);
  // calcula o valor de CRC dos bytes contidos em "cp".
  // "fcs" deve ter o valor PPPINITFCS16
  // O resultado é o valor de CRC (16 bits)
  // OBS: adaptado da RFC 1662 (enquadramento no PPP)
  uint16_t pppfcs16(uint16_t fcs, unsigned char * cp, int len);
  
  void dump(unsigned char * buffer, int len);
 


};

#endif /* FRAMMING_H_ */
