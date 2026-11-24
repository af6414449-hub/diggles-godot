
/* WARNING: Type propagation algorithm not settling */
/* Library Function - Single Match
    __wsetlocale_set_cat
   
   Library: Visual Studio 2019 Release */

void __wsetlocale_set_cat(int param_1,int param_2,undefined4 param_3)

{
  rsize_t _SizeInWords;
  wchar_t wVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  code *pcVar6;
  int *piVar7;
  int iVar8;
  wchar_t *pwVar9;
  int iVar10;
  uint uVar11;
  undefined4 *_Memory;
  errno_t eVar12;
  int iVar13;
  wchar_t *pwVar14;
  wchar_t *pwVar15;
  bool bVar16;
  int local_2d0;
  int local_2c8;
  undefined4 local_2c4;
  wchar_t *local_2c0;
  undefined1 local_2bc [172];
  ushort local_210 [128];
  wchar_t local_110 [132];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  iVar8 = ___acrt_getptd();
  pwVar9 = (wchar_t *)(iVar8 + 0x278);
  iVar10 = __expandlocale(param_3,local_110,0x83,local_2bc,0x55,&local_2c8);
  if (iVar10 != 0) {
    iVar10 = (param_2 + 2) * 0x10;
    pwVar14 = local_110;
    pwVar15 = *(wchar_t **)(iVar10 + param_1);
    do {
      local_2c0 = (wchar_t *)0x0;
      bVar16 = (ushort)*pwVar14 < (ushort)*pwVar15;
      if (*pwVar14 != *pwVar15) {
LAB_006e29cf:
        uVar11 = -(uint)bVar16 | 1;
        goto LAB_006e29d4;
      }
      if (*pwVar14 == L'\0') break;
      wVar1 = pwVar14[1];
      bVar16 = (ushort)wVar1 < (ushort)pwVar15[1];
      local_2c4 = (wchar_t *)CONCAT22(wVar1,(undefined2)local_2c4);
      if (wVar1 != pwVar15[1]) goto LAB_006e29cf;
      pwVar14 = pwVar14 + 2;
      pwVar15 = pwVar15 + 2;
    } while (wVar1 != L'\0');
    uVar11 = 0;
LAB_006e29d4:
    if (uVar11 != 0) {
      pwVar14 = local_110;
      do {
        wVar1 = *pwVar14;
        pwVar14 = pwVar14 + 1;
      } while (wVar1 != L'\0');
      _SizeInWords = ((int)pwVar14 - (int)(local_110 + 1) >> 1) + 1;
      _Memory = (undefined4 *)__malloc_base(_SizeInWords * 2 + 4);
      if (_Memory != (undefined4 *)0x0) {
        puVar2 = *(undefined2 **)(iVar10 + param_1);
        local_2c4 = (wchar_t *)(_Memory + 1);
        uVar3 = *(undefined4 *)(param_1 + 0xa0 + param_2 * 4);
        uVar4 = *(undefined4 *)(param_1 + 8);
        eVar12 = _wcscpy_s(local_2c4,_SizeInWords,local_110);
        if (eVar12 != 0) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson(local_2c0,local_2c0,local_2c0,(uint)local_2c0,(uintptr_t)local_2c0);
        }
        *(wchar_t **)(iVar10 + param_1) = local_2c4;
        if ((local_110[0] != L'C') || (pwVar14 = local_2c0, local_110[1] != 0)) {
          pwVar14 = (wchar_t *)___acrt_copy_locale_name(local_2bc);
        }
        *(wchar_t **)(param_1 + 0xa0 + param_2 * 4) = pwVar14;
        if (param_2 == 2) {
          *(int *)(param_1 + 8) = local_2c8;
          pwVar14 = pwVar9;
          pwVar15 = local_2c0;
          local_2d0 = *(int *)(iVar8 + 0x298);
          local_2c8 = *(int *)(iVar8 + 0x29c);
          do {
            if (*(int *)(param_1 + 8) == *(int *)pwVar14) {
              local_2c4 = pwVar14;
              if (pwVar15 != (wchar_t *)0x0) {
                *(int *)pwVar9 = *(int *)(pwVar9 + (int)pwVar15 * 4);
                *(undefined4 *)(iVar8 + 0x27c) = *(undefined4 *)(iVar8 + 0x27c + (int)pwVar15 * 8);
                *(int *)(pwVar9 + (int)pwVar15 * 4) = local_2d0;
                *(int *)(iVar8 + 0x27c + (int)pwVar15 * 8) = local_2c8;
              }
              break;
            }
            pwVar15 = (wchar_t *)((int)pwVar15 + 1);
            iVar13 = *(int *)pwVar14;
            iVar5 = *(int *)(pwVar14 + 2);
            *(int *)pwVar14 = local_2d0;
            local_2c4 = pwVar14 + 4;
            *(int *)(pwVar14 + 2) = local_2c8;
            pwVar14 = local_2c4;
            local_2d0 = iVar13;
            local_2c8 = iVar5;
          } while ((int)pwVar15 < 5);
          if (pwVar15 == (wchar_t *)&DAT_00000005) {
            iVar13 = ___acrt_GetStringTypeA
                               (local_2c0,1,&DAT_00717208,0x7f,local_210,
                                *(undefined4 *)(param_1 + 8),1);
            pwVar14 = local_2c0;
            if (iVar13 != 0) {
              do {
                local_210[(int)pwVar14] = local_210[(int)pwVar14] & 0x1ff;
                pwVar14 = (wchar_t *)((int)pwVar14 + 1);
              } while (pwVar14 < (wchar_t *)0x7f);
              iVar13 = FUN_006f3eb9(local_210,PTR_DAT_00767108,0xfe);
              pwVar14 = (wchar_t *)(uint)(iVar13 == 0);
            }
            *(wchar_t **)(iVar8 + 0x27c) = pwVar14;
            *(int *)pwVar9 = *(int *)(param_1 + 8);
          }
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar8 + 0x27c);
        }
        else if (param_2 == 1) {
          *(int *)(param_1 + 0x10) = local_2c8;
        }
        else if (param_2 == 5) {
          *(int *)(param_1 + 0x14) = local_2c8;
        }
        pcVar6 = (code *)(&PTR_TclCmd_ai_nprint_00717290)[param_2 * 3];
        guard_check_icall(param_1);
        iVar8 = (*pcVar6)();
        if (iVar8 == 0) {
          if (puVar2 != &DAT_007672d8) {
            piVar7 = *(int **)(param_1 + 0x28 + param_2 * 0x10);
            LOCK();
            iVar8 = *piVar7 + -1;
            *piVar7 = iVar8;
            UNLOCK();
            if (iVar8 == 0) {
              FID_conflict__free(*(void **)(param_1 + 0x28 + param_2 * 0x10));
              FID_conflict__free(*(void **)(param_1 + 0x24 + param_2 * 0x10));
              FID_conflict__free(*(void **)(param_1 + 0xa0 + param_2 * 4));
              *(wchar_t **)(iVar10 + param_1) = local_2c0;
              *(wchar_t **)(param_1 + 0xa0 + param_2 * 4) = local_2c0;
            }
          }
          *_Memory = 1;
          *(undefined4 **)(param_1 + 0x28 + param_2 * 0x10) = _Memory;
        }
        else {
          *(undefined2 **)(iVar10 + param_1) = puVar2;
          FID_conflict__free(*(void **)(param_1 + 0xa0 + param_2 * 4));
          *(undefined4 *)(param_1 + 0xa0 + param_2 * 4) = uVar3;
          FID_conflict__free(_Memory);
          *(undefined4 *)(param_1 + 8) = uVar4;
        }
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

