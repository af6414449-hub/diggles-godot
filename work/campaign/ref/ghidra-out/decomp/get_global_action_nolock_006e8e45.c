
/* Library Function - Single Match
    void (__cdecl** __cdecl get_global_action_nolock(int))(int)
   
   Library: Visual Studio 2019 Release */

_func_void_int ** __cdecl get_global_action_nolock(int param_1)

{
  if (param_1 == 2) {
    return (_func_void_int **)&DAT_0076a1c0;
  }
  if (param_1 != 6) {
    if (param_1 == 0xf) {
      return (_func_void_int **)&DAT_0076a1cc;
    }
    if (param_1 == 0x15) {
      return (_func_void_int **)&DAT_0076a1c4;
    }
    if (param_1 != 0x16) {
      return (_func_void_int **)0x0;
    }
  }
  return (_func_void_int **)&DAT_0076a1c8;
}

