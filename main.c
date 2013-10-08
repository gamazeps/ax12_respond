#include "ch.h"
#include "hal.h"

#include "ax12.h"
#include "receive_thread.h"

static  SerialConfig ax12cfg = {
  1000000, // AX12 communication works at 1MBPS
  0,
  0,
  (uint32_t) 8 // Value of CR3 register, configures the UART3 as half-duplex (4th bit high)
};

static  SerialConfig pccfg = {
  9600, // AX12 communication works at 1MBPS
  0,
  0,
  0
};

int main(void){
  halInit(); // initialize Hardware Abstraction Layer
  chSysInit(); // initialize ChibiOS kernel

  static WORKING_AREA(wa_receive, 256);

  sdStart(&SD3, &ax12cfg);
  sdStart(&SD1, &pccfg);

  palSetPadMode(GPIOB, 10, PAL_MODE_ALTERNATE(7)); // UART3 TX
  palSetPadMode(GPIOB, 11, PAL_MODE_ALTERNATE(7)); // UART3 RX
  palSetPadMode(GPIOB, 6, PAL_MODE_ALTERNATE(7)); // UART1 TX
  palSetPadMode(GPIOB, 7, PAL_MODE_ALTERNATE(7)); // UART1 RX


  chThdCreateStatic(wa_receive, sizeof(wa_receive), NORMALPRIO, receive_thread, NULL);

  chThdSleepMilliseconds(1000);
  for(int i=0; i<255; i++){
    writeLed(&SD3, (char) i, 0x01);
    chThdSleepMilliseconds(100);
  }

  while(1);
}
