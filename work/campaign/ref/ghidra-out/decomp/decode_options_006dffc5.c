
/* Library Function - Single Match
    struct `anonymous namespace'::file_options __cdecl decode_options(int,int,int)
   
   Library: Visual Studio 2019 Release */

int __cdecl decode_options(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  ulong uVar4;
  errno_t eVar5;
  byte in_stack_00000010;
  int local_8;
  
  uVar1 = param_2 & 3;
  *(undefined1 *)param_1 = 0;
  if (uVar1 == 0) {
    iVar3 = -0x80000000;
  }
  else if (uVar1 == 1) {
    iVar3 = (-(uint)((param_2 & 0x70000U) != 0 && (param_2 & 8U) != 0) & 0x80000000) + 0x40000000;
  }
  else if (uVar1 == 2) {
    iVar3 = -0x40000000;
  }
  else {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    iVar3 = -1;
  }
  *(int *)(param_1 + 4) = iVar3;
  uVar4 = decode_open_create_flags(param_2);
  *(ulong *)(param_1 + 8) = uVar4;
  if (param_3 == 0x10) {
    uVar1 = 0;
  }
  else if (param_3 == 0x20) {
    uVar1 = 1;
  }
  else if (param_3 == 0x30) {
    uVar1 = 2;
  }
  else if (param_3 == 0x40) {
    uVar1 = 3;
  }
  else if (param_3 == 0x80) {
    uVar1 = (uint)(*(int *)(param_1 + 4) == -0x80000000);
  }
  else {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    uVar1 = 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(uint *)(param_1 + 0xc) = uVar1;
  *(undefined4 *)(param_1 + 0x10) = 0x80;
  if ((char)param_2 < '\0') {
    *(byte *)param_1 = *(byte *)param_1 | 0x10;
  }
  if ((param_2 & 0x8000U) == 0) {
    if ((param_2 & 0x74000U) == 0) {
      eVar5 = __get_fmode(&local_8);
      if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      if (local_8 == 0x8000) goto LAB_006e00c2;
    }
    *(byte *)param_1 = *(byte *)param_1 | 0x80;
  }
LAB_006e00c2:
  if (((param_2 & 0x100U) != 0) && (-1 < (char)(~(byte)DAT_0076a1e0 & in_stack_00000010))) {
    *(undefined4 *)(param_1 + 0x10) = 1;
  }
  if ((param_2 & 0x40U) != 0) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x4000000;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10000;
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 4;
  }
  if ((param_2 & 0x1000U) != 0) {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x100;
  }
  if ((param_2 & 0x2000U) != 0) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x2000000;
  }
  if ((param_2 & 0x20U) == 0) {
    if ((param_2 & 0x10U) != 0) {
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x10000000;
    }
  }
  else {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x8000000;
  }
  return param_1;
}

