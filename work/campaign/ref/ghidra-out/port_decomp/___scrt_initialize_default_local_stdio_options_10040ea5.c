
/* Library Function - Single Match
    ___scrt_initialize_default_local_stdio_options
   
   Library: Visual Studio 2019 Release */

void ___scrt_initialize_default_local_stdio_options(void)

{
  uint *puVar1;
  
  puVar1 = (uint *)FUN_10002850();
  *puVar1 = *puVar1 | 0x24;
  puVar1[1] = puVar1[1];
  puVar1 = (uint *)FUN_10040e9f();
  *puVar1 = *puVar1 | 2;
  puVar1[1] = puVar1[1];
  return;
}

