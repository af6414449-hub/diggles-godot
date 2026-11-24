
/* Library Function - Single Match
    void __cdecl free_environment<char>(char * * const)
   
   Library: Visual Studio 2019 Release */

void __cdecl free_environment<char>(char **param_1)

{
  char *_Memory;
  char **ppcVar1;
  
  if (param_1 != (char **)0x0) {
    _Memory = *param_1;
    ppcVar1 = param_1;
    while (_Memory != (char *)0x0) {
      FID_conflict__free(_Memory);
      ppcVar1 = ppcVar1 + 1;
      _Memory = *ppcVar1;
    }
    FID_conflict__free(param_1);
  }
  return;
}

