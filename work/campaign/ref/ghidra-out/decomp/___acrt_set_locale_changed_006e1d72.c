
/* Library Function - Single Match
    ___acrt_set_locale_changed
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_set_locale_changed(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00769d54;
  LOCK();
  DAT_00769d54 = 1;
  UNLOCK();
  return uVar1;
}

