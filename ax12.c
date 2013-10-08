#include "ch.h"
#include "hal.h"

char data[12];
void sendData(SerialDriver *SD, char id, char* message){
  //static char data[12];
  char checksum = id;
  data[0] = 0xFF;
  data[1] = 0xFF;
  data[2] = id;
  for(int i = 0; i< message[0]; i++){
    data[i+3] = message[i];
    checksum += message[i];
  }
  data[message[0]+3] = ~checksum;
  sdWrite(SD, (uint8_t *) data, message[0]+4);
}

void enableTorque(SerialDriver *SD, char id){
  char message[4];
  message[0] = 4; // Message length
  message[1] = 0x03; // Write instruction
  message[2] = 0x18; // Torque Enable RAM address
  message[3] = 0x01; // Torque Enable
  sendData(SD, id, message);
}

void writeLed(SerialDriver *SD, char id, char on){
  char message[4];
  message[0] = 4; // Message length
  message[1] = 0x03; // Write instruction
  message[2] = 0x19; // Torque Enable RAM address
  message[3] = on; // Torque Enable
  sendData(SD, id, message);
}

void setSpeed(SerialDriver *SD, char id, uint16_t targetSpeed){
  char message[5];
  message[0] = 5; // Message length
  message[1] = 0x03; // Write instruction
  message[2] = 0x20; // Moving Speed RAM address
  message[3] = targetSpeed; // Moving Speed(L)
  message[4] = (char) (targetSpeed / 256); // Moving Speed(H)
  sendData(SD, id, message);
}

void setAngle(SerialDriver *SD, char id, uint16_t targetAngle){
  char message[5];
  message[0] = 5; // Message length
  message[1] = 0x03; // Write instruction
  message[2] = 0x1E; // Goal Position RAM address
  message[3] = targetAngle; // Goal Position(L)
  message[4] = (char) (targetAngle / 256); // Goal Position(H)
  sendData(SD, id, message);
}

void setTorqueLimit(SerialDriver *SD, char id, uint16_t torqueLimit){
  char message[5];
  message[0] = 5; // Message length
  message[1] = 0x03; // Write instruction
  message[2] = 0x1E; // Goal Position RAM address
  message[3] = torqueLimit; // Goal Position(L)
  message[4] = (char) (torqueLimit / 256); // Goal Position(H)
  sendData(SD, id, message);
}
