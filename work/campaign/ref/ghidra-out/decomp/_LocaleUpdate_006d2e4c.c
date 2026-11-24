
/* Library Function - Single Match
    public: __thiscall _LocaleUpdate::_LocaleUpdate(struct __crt_locale_pointers * const)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_LocaleUpdate * __thiscall
_LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this,__crt_locale_pointers *param_1)

{
  _LocaleUpdate *p_Var1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  
  this[0xc] = (_LocaleUpdate)0x0;
  p_Var1 = this + 4;
  if (param_1 == (__crt_locale_pointers *)0x0) {
    if (DAT_00769d54 != 0) {
      iVar4 = ___acrt_getptd();
      *(int *)this = iVar4;
      *(undefined4 *)p_Var1 = *(undefined4 *)(iVar4 + 0x4c);
      *(undefined4 *)(this + 8) = *(undefined4 *)(iVar4 + 0x48);
      ___acrt_update_locale_info(iVar4,p_Var1);
      ___acrt_update_multibyte_info(*(undefined4 *)this,this + 8);
      uVar2 = *(uint *)(*(int *)this + 0x350);
      if ((uVar2 & 2) != 0) {
        return this;
      }
      *(uint *)(*(int *)this + 0x350) = uVar2 | 2;
      this[0xc] = (_LocaleUpdate)0x1;
      return this;
    }
    *(undefined **)p_Var1 = PTR_PTR_007672d0;
    puVar3 = PTR_DAT_007672d4;
  }
  else {
    *(undefined4 *)p_Var1 = *(undefined4 *)param_1;
    puVar3 = *(undefined **)(param_1 + 4);
  }
  *(undefined **)(this + 8) = puVar3;
  return this;
}

