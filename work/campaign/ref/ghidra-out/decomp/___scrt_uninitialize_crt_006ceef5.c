
/* Library Function - Single Match
    ___scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 ___scrt_uninitialize_crt(undefined4 param_1,char param_2)

{
  if ((DAT_00769740 == '\0') || (param_2 == '\0')) {
    ___acrt_uninitialize(param_1);
    ___vcrt_uninitialize(param_1);
  }
  return 1;
}

