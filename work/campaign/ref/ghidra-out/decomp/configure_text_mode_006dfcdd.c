
/* Library Function - Single Match
    int __cdecl configure_text_mode(int,struct `anonymous namespace'::file_options,int,enum
   __crt_lowio_text_mode &)
   
   Library: Visual Studio 2019 Release */

int __cdecl configure_text_mode(uint param_1,byte param_2,uint param_3,uint param_4)

{
  bool bVar1;
  errno_t eVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined *in_ECX;
  uint uVar7;
  int iVar8;
  int unaff_EDI;
  longlong lVar9;
  uint in_stack_00000020;
  char *in_stack_00000024;
  undefined *local_8;
  
  iVar8 = 0;
  *in_stack_00000024 = '\0';
  if (-1 < *(char *)((&DAT_00769d80)[(int)param_1 >> 6] + 0x28 + (param_1 & 0x3f) * 0x38)) {
    return 0;
  }
  local_8 = in_ECX;
  if ((in_stack_00000020 & 0x74000) == 0) {
    local_8 = (undefined *)0x0;
    eVar2 = __get_fmode((int *)&local_8);
    if (eVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    if (((uint)local_8 & 0x74000) == 0) {
      in_stack_00000020 = in_stack_00000020 | 0x4000;
    }
    else {
      in_stack_00000020 = in_stack_00000020 | (uint)local_8 & 0x74000;
    }
  }
  uVar3 = in_stack_00000020 & 0x74000;
  if (uVar3 == 0x4000) {
    *in_stack_00000024 = '\0';
  }
  else if ((uVar3 == 0x10000) || (uVar3 == 0x14000)) {
    if ((in_stack_00000020 & 0x301) == 0x301) goto LAB_006dfd8b;
  }
  else if ((uVar3 == 0x20000) || (uVar3 == 0x24000)) {
LAB_006dfd8b:
    *in_stack_00000024 = '\x02';
  }
  else if ((uVar3 == 0x40000) || (uVar3 == 0x44000)) {
    *in_stack_00000024 = '\x01';
  }
  if ((in_stack_00000020 & 0x70000) == 0) {
    return 0;
  }
  if ((param_2 & 0x40) != 0) {
    return 0;
  }
  uVar3 = param_3 & 0xc0000000;
  uVar7 = 0;
  bVar1 = false;
  if (uVar3 == 0x40000000) {
LAB_006dfdcc:
    if (param_4 == 0) {
      return 0;
    }
    if (param_4 < 3) {
LAB_006dfdea:
      bVar1 = true;
LAB_006dfded:
      if (uVar7 != 0) goto LAB_006dfdf5;
      goto LAB_006dfec9;
    }
    if (4 < param_4) {
      if (param_4 != 5) {
        return 0;
      }
      goto LAB_006dfdea;
    }
    lVar9 = __lseeki64_nolock(param_1,0x200000000,unaff_EDI);
    if (lVar9 != 0) {
      lVar9 = __lseeki64_nolock(param_1,0,unaff_EDI);
      if (lVar9 == -1) goto LAB_006dfe64;
      uVar7 = param_3 >> 0x1f;
      goto LAB_006dfded;
    }
  }
  else {
    if (uVar3 != 0x80000000) {
      if (uVar3 != 0xc0000000) {
        return 0;
      }
      goto LAB_006dfdcc;
    }
LAB_006dfdf5:
    local_8 = (undefined *)0x0;
    iVar4 = __read_nolock(param_1,&local_8,3);
    if (0 < iVar4) {
      bVar1 = (bool)(bVar1 & !bVar1);
    }
    if (iVar4 == -1) goto LAB_006dfe64;
    if (iVar4 == 2) {
LAB_006dfe7b:
      if (((uint)local_8 & 0xffff) == 0xfffe) {
        piVar5 = __errno();
        *piVar5 = 0x16;
        goto LAB_006dfe64;
      }
      if (((uint)local_8 & 0xffff) == 0xfeff) {
        lVar9 = __lseeki64_nolock(param_1,0,unaff_EDI);
        if (lVar9 == -1) goto LAB_006dfe64;
        *in_stack_00000024 = '\x02';
        goto LAB_006dfec9;
      }
    }
    else if (iVar4 == 3) {
      if (local_8 == &DAT_00bfbbef) {
        *in_stack_00000024 = '\x01';
        goto LAB_006dfec9;
      }
      goto LAB_006dfe7b;
    }
    lVar9 = __lseeki64_nolock(param_1,0,unaff_EDI);
    if (lVar9 == -1) goto LAB_006dfe64;
LAB_006dfec9:
    if (!bVar1) {
      return 0;
    }
  }
  iVar4 = 0;
  local_8 = (undefined *)0x0;
  if (*in_stack_00000024 == '\x01') {
    local_8 = &DAT_00bfbbef;
    iVar4 = 3;
LAB_006dfef5:
    if (iVar4 == 0) {
      return 0;
    }
  }
  else {
    if (*in_stack_00000024 != '\x02') goto LAB_006dfef5;
    local_8 = (undefined *)0xfeff;
    iVar4 = 2;
  }
  while (iVar6 = __write(param_1,(void *)((int)&local_8 + iVar8),iVar4 - iVar8), iVar6 != -1) {
    iVar8 = iVar8 + iVar6;
    if (iVar4 <= iVar8) {
      return 0;
    }
  }
LAB_006dfe64:
  piVar5 = __errno();
  return *piVar5;
}

