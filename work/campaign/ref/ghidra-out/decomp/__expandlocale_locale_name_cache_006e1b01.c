
/* Library Function - Single Match
    public: __thiscall _expandlocale_locale_name_cache::~_expandlocale_locale_name_cache(void)
   
   Library: Visual Studio 2019 Release */

void __thiscall
_expandlocale_locale_name_cache::~_expandlocale_locale_name_cache
          (_expandlocale_locale_name_cache *this)

{
  int iVar1;
  
  if (this[0xc] == (_expandlocale_locale_name_cache)0x0) {
    iVar1 = FUN_006ed6af(*(int *)(this + 8) + 0x250,0x55,*(undefined4 *)this,
                         *(undefined4 *)(this + 4));
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
  return;
}

