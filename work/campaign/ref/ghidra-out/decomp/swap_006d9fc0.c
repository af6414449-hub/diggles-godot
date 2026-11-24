
/* Library Function - Single Match
    void __cdecl swap(char *,char *,unsigned int)
   
   Library: Visual Studio 2019 Release */

void __cdecl swap(char *param_1,char *param_2,uint param_3)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  
  if ((param_1 != param_2) && (pcVar3 = param_2, param_3 != 0)) {
    do {
      pcVar1 = pcVar3 + 1;
      cVar2 = pcVar1[(int)(param_1 + (-1 - (int)param_2))];
      pcVar1[(int)(param_1 + (-1 - (int)param_2))] = *pcVar3;
      *pcVar3 = cVar2;
      param_3 = param_3 - 1;
      pcVar3 = pcVar1;
    } while (param_3 != 0);
  }
  return;
}

