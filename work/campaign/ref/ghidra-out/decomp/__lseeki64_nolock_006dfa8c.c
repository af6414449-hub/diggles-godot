
/* Library Function - Single Match
    __lseeki64_nolock
   
   Library: Visual Studio 2019 Release */

longlong __cdecl __lseeki64_nolock(int _FileHandle,longlong _Offset,int _Origin)

{
  int unaff_EBP;
  __int64 _Var1;
  
  _Var1 = common_lseek_nolock<__int64>(_FileHandle,_Offset,unaff_EBP);
  return _Var1;
}

