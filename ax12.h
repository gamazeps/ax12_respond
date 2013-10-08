#ifndef DEF_AX12
#define DEF_AX12

void enableTorque(SerialDriver *SD, char id);
void setSpeed(SerialDriver *SD, char id, uint16_t targetSpeed);
void setAngle(SerialDriver *SD, char id, uint16_t targetAngle);
void writeLed(SerialDriver *SD, char id, char on);

#endif
