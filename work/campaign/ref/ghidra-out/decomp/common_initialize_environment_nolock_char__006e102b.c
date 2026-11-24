
/* Library Function - Single Match
    int __cdecl common_initialize_environment_nolock<char>(void)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_initialize_environment_nolock<char>(void)

{
  char *_Memory;
  char **ppcVar1;
  int iVar2;
  
  if (DAT_00769d20 != (char **)0x0) {
    return 0;
  }
  ___acrt_initialize_multibyte();
  _Memory = (char *)___dcrt_get_narrow_environment_from_os();
  if (_Memory == (char *)0x0) {
    iVar2 = -1;
  }
  else {
    ppcVar1 = create_environment<char>(_Memory);
    if (ppcVar1 == (char **)0x0) {
      iVar2 = -1;
    }
    else {
      iVar2 = 0;
      DAT_00769d20 = ppcVar1;
      DAT_00769d2c = ppcVar1;
    }
    FID_conflict__free((void *)0x0);
  }
  FID_conflict__free(_Memory);
  return iVar2;
}

