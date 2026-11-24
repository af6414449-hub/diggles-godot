
/* Library Function - Single Match
    void __stdcall _CallMemberFunction2(void * const,void * const,void * const,int)
   
   Library: Visual Studio 2019 Release */

void _CallMemberFunction2(void *param_1,void *param_2,void *param_3,int param_4)

{
  (*(code *)param_2)(param_3,param_4);
  return;
}

