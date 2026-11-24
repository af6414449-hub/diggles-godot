
/* Library Function - Single Match
    public: void __thiscall
   _expandlocale_locale_name_cache::commit_locale_name_cache_already_updated(wchar_t const *
   const,unsigned int)
   
   Library: Visual Studio 2019 Release */

void __thiscall
_expandlocale_locale_name_cache::commit_locale_name_cache_already_updated
          (_expandlocale_locale_name_cache *this,wchar_t *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = FUN_006ed6af(*(undefined4 *)this,*(undefined4 *)(this + 4),param_1,param_2);
  if (iVar1 == 0) {
    this[0xc] = (_expandlocale_locale_name_cache)0x1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}

