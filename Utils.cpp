#include <Arduino.h>
#include <Time.h>

#include "Utils.h"
#include "Config.h"

//-----------------
// Function: nowDST
//-----------------
time_t NowDST()
{
  time_t timeNow = now();
  int cfgDST ;

  config.GetCfgItem(CFG_DST, &cfgDST, sizeof(cfgDST));
  if(cfgDST == CFG_DST_ON)
  {
    timeNow += 3600; // Add on an hour
  }

  return timeNow;
}

//------------------
// Function: FreeRam
//------------------
uint32_t FreeRam()
{
    uint32_t stackTop;
    uint32_t heapTop;

    // current position of the stack.
    stackTop = (uint32_t) &stackTop;

    // current position of heap.
    void* hTop = malloc(1);
    heapTop = (uint32_t) hTop;
    free(hTop);

    // The difference is the free, available ram.
    return stackTop - heapTop;
}
