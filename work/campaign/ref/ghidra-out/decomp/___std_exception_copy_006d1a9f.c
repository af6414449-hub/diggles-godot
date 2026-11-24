
/* Library Function - Single Match
    ___std_exception_copy
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___std_exception_copy(undefined4 *param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  char *_Dst;
  char *pcVar3;
  char *pcVar4;
  
  if ((*(char *)(param_1 + 1) == '\0') || (pcVar3 = (char *)*param_1, pcVar3 == (char *)0x0)) {
    *param_2 = *param_1;
    *(undefined1 *)(param_2 + 1) = 0;
  }
  else {
    pcVar1 = pcVar3 + 1;
    do {
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    _Dst = (char *)FUN_006df64c(pcVar3 + (1 - (int)pcVar1));
    pcVar4 = _Dst;
    if (_Dst != (char *)0x0) {
      _strcpy_s(_Dst,(rsize_t)(pcVar3 + (1 - (int)pcVar1)),(char *)*param_1);
      pcVar4 = (char *)0x0;
      *param_2 = _Dst;
      *(undefined1 *)(param_2 + 1) = 1;
    }
    FUN_006df631(pcVar4);
  }
  return;
}

