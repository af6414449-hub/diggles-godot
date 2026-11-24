
/* Library Function - Single Match
    _fopen
   
   Library: Visual Studio 2019 Release */

FILE * __cdecl _fopen(char *_Filename,char *_Mode)

{
  _iobuf *p_Var1;
  
  p_Var1 = common_fsopen<char>(_Filename,_Mode,0x40);
  return p_Var1;
}

