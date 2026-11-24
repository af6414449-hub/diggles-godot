
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl _strlwr_s_l_stat(char * const,unsigned int,struct __crt_locale_pointers * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl _strlwr_s_l_stat(char *param_1,uint param_2,__crt_locale_pointers *param_3)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  char *_Src;
  char *pcVar6;
  int iVar7;
  
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (param_1 == (char *)0x0) {
LAB_006e36cf:
    piVar3 = __errno();
    iVar7 = 0x16;
  }
  else {
    uVar4 = FUN_006e5cd8(param_1,param_2);
    if (param_2 <= uVar4) {
      *param_1 = '\0';
      goto LAB_006e36cf;
    }
    iVar7 = *(int *)(*(int *)param_3 + 0xa8);
    if (iVar7 == 0) {
      for (; cVar1 = *param_1, cVar1 != '\0'; param_1 = param_1 + 1) {
        if ((byte)(cVar1 + 0xbfU) < 0x1a) {
          *param_1 = cVar1 + ' ';
        }
      }
      goto LAB_006e3810;
    }
    _Src = (char *)0x0;
    uVar4 = ___acrt_LCMapStringA
                      (param_3,iVar7,0x100,param_1,0xffffffff,0,0,
                       *(undefined4 *)(*(int *)param_3 + 8),1);
    if (uVar4 == 0) {
      piVar3 = __errno();
      *piVar3 = 0x2a;
      __errno();
      goto LAB_006e3810;
    }
    if (uVar4 <= param_2) {
      uVar5 = -(uint)(uVar4 < uVar4 + 8) & uVar4 + 8;
      if (uVar5 != 0) {
        if (uVar5 < 0x401) {
          pcVar6 = &stack0xffffffec;
          _Src = &stack0xffffffec;
          if (&stack0x00000000 != (undefined1 *)0x14) {
LAB_006e37a7:
            _Src = pcVar6 + 8;
          }
        }
        else {
          _Src = (char *)__malloc_base(uVar5);
          if (_Src != (char *)0x0) {
            _Src[0] = -0x23;
            _Src[1] = -0x23;
            _Src[2] = '\0';
            _Src[3] = '\0';
            pcVar6 = _Src;
            goto LAB_006e37a7;
          }
        }
      }
      if (_Src == (char *)0x0) {
        piVar3 = __errno();
        *piVar3 = 0xc;
        __errno();
      }
      else {
        iVar7 = ___acrt_LCMapStringA
                          (param_3,*(undefined4 *)(*(int *)param_3 + 0xa8),0x100,param_1,0xffffffff,
                           _Src,uVar4,*(undefined4 *)(*(int *)param_3 + 8),1);
        if (iVar7 == 0) {
          piVar3 = __errno();
          *piVar3 = 0x2a;
        }
        else {
          _strcpy_s(param_1,param_2,_Src);
        }
      }
      __freea_crt(_Src);
      goto LAB_006e3810;
    }
    *param_1 = '\0';
    piVar3 = __errno();
    iVar7 = 0x22;
  }
  *piVar3 = iVar7;
  FUN_006e510d();
LAB_006e3810:
  iVar7 = __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return iVar7;
}

