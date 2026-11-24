
/* Library Function - Single Match
    class __crt_stdio_stream __cdecl __acrt_stdio_allocate_stream(void)
   
   Library: Visual Studio 2019 Release */

undefined4 * __cdecl __acrt_stdio_allocate_stream(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007636c8,0xc);
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *puVar1 = 0;
  ___acrt_lock(8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar2 = (undefined4 *)find_or_allocate_unused_stream_nolock();
  puVar2 = (undefined4 *)*puVar2;
  *puVar1 = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[2] = 0;
    puVar2[7] = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[4] = 0xffffffff;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e51b1();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return puVar1;
}

