#include "ch.h"
#include "hal.h"

__attribute__((noreturn)) msg_t receive_thread(void *arg){
  while(1){
    sdPut(&SD1, sdGet(&SD3));
  }
}
