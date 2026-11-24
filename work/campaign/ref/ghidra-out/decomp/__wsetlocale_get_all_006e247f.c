
/* Library Function - Single Match
    __wsetlocale_get_all
   
   Library: Visual Studio 2019 Release */

undefined4 * __wsetlocale_get_all(int param_1)

{
  wchar_t *_Dst;
  int iVar1;
  ushort uVar2;
  ushort *puVar3;
  int *piVar4;
  bool bVar5;
  undefined4 *_Memory;
  undefined4 *puVar6;
  errno_t eVar7;
  ushort *puVar8;
  uint uVar9;
  ushort *puVar10;
  bool bVar11;
  undefined4 *local_10;
  undefined **local_8;
  
  bVar5 = true;
  _Memory = (undefined4 *)__malloc_base(0x6a6);
  puVar6 = (undefined4 *)0x0;
  if (_Memory != (undefined4 *)0x0) {
    _Dst = (wchar_t *)(_Memory + 1);
    *_Dst = L'\0';
    *_Memory = 1;
    __wcscats(_Dst,0x351,3,L"LC_COLLATE",&DAT_00717358,*(undefined4 *)(param_1 + 0x30));
    local_8 = &PTR_u_LC_COLLATE_00717294;
    local_10 = (undefined4 *)(param_1 + 0x30);
    do {
      eVar7 = _wcscat_s(_Dst,0x351,L";");
      if (eVar7 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      puVar8 = (ushort *)*local_10;
      puVar3 = (ushort *)local_10[4];
      puVar10 = puVar3;
      do {
        uVar2 = *puVar8;
        bVar11 = uVar2 < *puVar10;
        if (uVar2 != *puVar10) {
LAB_006e252e:
          uVar9 = -(uint)bVar11 | 1;
          goto LAB_006e2533;
        }
        if (uVar2 == 0) break;
        uVar2 = puVar8[1];
        bVar11 = uVar2 < puVar10[1];
        if (uVar2 != puVar10[1]) goto LAB_006e252e;
        puVar8 = puVar8 + 2;
        puVar10 = puVar10 + 2;
      } while (uVar2 != 0);
      uVar9 = 0;
LAB_006e2533:
      bVar5 = (bool)(bVar5 & ~(uVar9 != 0));
      local_8 = local_8 + 3;
      __wcscats(_Dst,0x351,3,*local_8,&DAT_00717358,puVar3);
      local_10 = local_10 + 4;
    } while ((int)local_8 < 0x7172c4);
    if (bVar5) {
      FID_conflict__free(_Memory);
      piVar4 = *(int **)(param_1 + 0x28);
      if (piVar4 != (int *)0x0) {
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = iVar1 + -1;
        UNLOCK();
        if (iVar1 + -1 == 0) {
          FID_conflict__free(*(void **)(param_1 + 0x28));
        }
      }
      piVar4 = *(int **)(param_1 + 0x24);
      if (piVar4 != (int *)0x0) {
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = *piVar4 + -1;
        UNLOCK();
        if (iVar1 == 1) {
          FID_conflict__free(*(void **)(param_1 + 0x24));
        }
      }
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x28) = 0;
      *(undefined4 *)(param_1 + 0x20) = 0;
      puVar6 = *(undefined4 **)(param_1 + 0x40);
    }
    else {
      piVar4 = *(int **)(param_1 + 0x28);
      if (piVar4 != (int *)0x0) {
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = iVar1 + -1;
        UNLOCK();
        if (iVar1 + -1 == 0) {
          FID_conflict__free(*(void **)(param_1 + 0x28));
        }
      }
      piVar4 = *(int **)(param_1 + 0x24);
      if (piVar4 != (int *)0x0) {
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = *piVar4 + -1;
        UNLOCK();
        if (iVar1 == 1) {
          FID_conflict__free(*(void **)(param_1 + 0x24));
        }
      }
      *(undefined4 *)(param_1 + 0x24) = 0;
      puVar6 = _Memory + 1;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 **)(param_1 + 0x28) = _Memory;
      *(undefined4 **)(param_1 + 0x20) = puVar6;
    }
  }
  return puVar6;
}

