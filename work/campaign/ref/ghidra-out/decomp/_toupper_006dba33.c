
/* Library Function - Single Match
    _toupper
   
   Library: Visual Studio 2019 Release */

int __cdecl _toupper(int _C)

{
  if (DAT_00769d54 == 0) {
    if (_C - 0x61U < 0x1a) {
      _C = _C + -0x20;
    }
  }
  else {
    _C = __toupper_l(_C,(_locale_t)0x0);
  }
  return _C;
}

