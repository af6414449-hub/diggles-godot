
/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 2019 Release */

int __cdecl _tolower(int _C)

{
  if (DAT_00769d54 == 0) {
    if (_C - 0x41U < 0x1a) {
      _C = _C + 0x20;
    }
  }
  else {
    _C = __tolower_l(_C,(_locale_t)0x0);
  }
  return _C;
}

