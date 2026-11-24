
/* Library Function - Single Match
    __lseeki64
   
   Library: Visual Studio 2019 Release */

longlong __cdecl __lseeki64(int _FileHandle,longlong _Offset,int _Origin)

{
  int unaff_EBP;
  __int64 _Var1;
  
  _Var1 = common_lseek<__int64>(_FileHandle,_Offset,unaff_EBP);
  return _Var1;
}

