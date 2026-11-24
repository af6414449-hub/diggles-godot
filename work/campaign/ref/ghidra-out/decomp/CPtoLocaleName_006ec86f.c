
/* Library Function - Single Match
    wchar_t const * __cdecl CPtoLocaleName(int)
   
   Library: Visual Studio 2019 Release */

wchar_t * __cdecl CPtoLocaleName(int param_1)

{
  if (param_1 == 0x3a4) {
    return L"ja-JP";
  }
  if (param_1 == 0x3a8) {
    return L"zh-CN";
  }
  if (param_1 == 0x3b5) {
    return L"ko-KR";
  }
  if (param_1 != 0x3b6) {
    return (wchar_t *)0x0;
  }
  return L"zh-TW";
}

