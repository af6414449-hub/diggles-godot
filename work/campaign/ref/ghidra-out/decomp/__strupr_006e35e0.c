
/* Library Function - Single Match
    __strupr
   
   Library: Visual Studio 2019 Release */

char * __cdecl __strupr(char *_String)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  
  if (DAT_00769d54 != 0) {
    __strupr_s_l(_String,0xffffffff,(_locale_t)0x0);
    return _String;
  }
  if (_String == (char *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    return (char *)0x0;
  }
  cVar1 = *_String;
  pcVar3 = _String;
  while (cVar1 != '\0') {
    if ((byte)(cVar1 + 0x9fU) < 0x1a) {
      *pcVar3 = cVar1 + -0x20;
    }
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
  }
  return _String;
}

