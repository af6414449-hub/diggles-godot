
/* Library Function - Single Match
    ___acrt_stdio_end_temporary_buffering_nolock
   
   Library: Visual Studio 2019 Release */

void ___acrt_stdio_end_temporary_buffering_nolock(char param_1,undefined4 *param_2)

{
  uint *puVar1;
  
  if ((param_1 != '\0') && (puVar1 = param_2 + 3, (*puVar1 >> 9 & 1) != 0)) {
    ___acrt_stdio_flush_nolock(param_2);
    LOCK();
    *puVar1 = *puVar1 & 0xfffffd7f;
    UNLOCK();
    param_2[6] = 0;
    param_2[1] = 0;
    *param_2 = 0;
  }
  return;
}

