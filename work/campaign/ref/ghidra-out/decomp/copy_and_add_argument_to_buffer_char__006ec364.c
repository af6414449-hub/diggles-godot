
/* Library Function - Single Match
    int __cdecl copy_and_add_argument_to_buffer<char>(char const * const,char const * const,unsigned
   int,class `anonymous namespace'::argument_list<char> &)
   
   Library: Visual Studio 2019 Release */

int __cdecl
copy_and_add_argument_to_buffer<char>
          (char *param_1,char *param_2,uint param_3,argument_list<char> *param_4)

{
  char cVar1;
  void *_Memory;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = pcVar3 + (1 - (int)(param_1 + 1));
  if ((char *)~param_3 < pcVar3) {
    iVar2 = 0xc;
  }
  else {
    pcVar4 = pcVar3 + param_3 + 1;
    _Memory = (void *)__calloc_base(pcVar4,1);
    if (param_3 != 0) {
      iVar2 = FUN_006e9950(_Memory,pcVar4,param_2,param_3);
      if (iVar2 != 0) goto LAB_006ec408;
    }
    iVar2 = FUN_006e9950((int)_Memory + param_3,(int)pcVar4 - param_3,param_1,pcVar3);
    if (iVar2 != 0) {
LAB_006ec408:
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    iVar2 = _anon_5F5C8891::argument_list<char>::expand_if_necessary(param_4);
    if (iVar2 == 0) {
      **(undefined4 **)(param_4 + 4) = _Memory;
      iVar2 = 0;
      *(int *)(param_4 + 4) = *(int *)(param_4 + 4) + 4;
    }
    else {
      FID_conflict__free(_Memory);
    }
    FID_conflict__free((void *)0x0);
  }
  return iVar2;
}

