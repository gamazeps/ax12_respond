

#define 7V TRUE

void sendPacket(char* message, SerialDriver SD){
  char data[12];
  char checksum = 0x00;
  data[0] = 0xFF;
  data[1] = 0xFF;
  for(int i = 0; i< message[1]; i++){
    data[i+2] = message[i];
    checksum += message[i];
  }
  data[message[1]+2] = ~checksum;
  sdWrite(&SD, (uint8_t *) data, strlen(data));
}
