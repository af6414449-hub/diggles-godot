
FILE * FUN_1003fb70(void)

{
  long _Offset;
  FILE *pFVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  pFVar1 = *(FILE **)(in_ECX + 4);
  if (pFVar1 == (FILE *)0x0) {
    return pFVar1;
  }
  _Offset = ftell(pFVar1);
  fseek(*(FILE **)(in_ECX + 4),0,2);
  pFVar1 = (FILE *)ftell(*(FILE **)(in_ECX + 4));
  fseek(*(FILE **)(in_ECX + 4),_Offset,0);
  return pFVar1;
}

