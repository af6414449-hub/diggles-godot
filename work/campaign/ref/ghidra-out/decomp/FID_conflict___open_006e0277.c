
/* Library Function - Multiple Matches With Different Base Names
    __open
    __wopen
   
   Library: Visual Studio 2019 Release */

int __cdecl FID_conflict___open(char *_Filename,int _OpenFlag,...)

{
  int iVar1;
  int in_stack_0000000c;
  
  iVar1 = common_open<wchar_t>((wchar_t *)_Filename,_OpenFlag,in_stack_0000000c);
  return iVar1;
}

