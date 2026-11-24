
void FUN_1003eea0(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_10;
  int local_c;
  int local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar3 = *(int *)(in_ECX + 0x5c);
  if (iVar3 == 0) {
    free(*(void **)(in_ECX + 0x14));
    iVar3 = *(int *)(in_ECX + 0x5c);
  }
  iVar1 = 0;
  iVar2 = iVar3;
  if (0 < *(int *)(in_ECX + 0x18)) {
    do {
      if (iVar3 == 0) {
        free(*(void **)(*(int *)(in_ECX + 0x1c) + iVar1 * 4));
        iVar3 = *(int *)(in_ECX + 0x5c);
        iVar2 = iVar3;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0x18));
    iVar3 = *(int *)(in_ECX + 0x5c);
  }
  if (iVar2 == 0) {
    free(*(void **)(in_ECX + 0x1c));
    iVar3 = *(int *)(in_ECX + 0x5c);
  }
  if ((*(int *)(in_ECX + 0x198) != 0) && (local_8 = 0, 0 < *(int *)(in_ECX + 0x114))) {
    local_c = 0;
    do {
      iVar2 = *(int *)(in_ECX + 0x198) + local_c;
      if (*(int *)(iVar2 + 0x10) == 0) {
LAB_1003efa3:
        iVar3 = *(int *)(in_ECX + 0x5c);
        if (iVar3 == 0) {
          free(*(void **)(iVar2 + 0x14));
          iVar3 = *(int *)(in_ECX + 0x5c);
        }
      }
      else {
        local_10 = 0;
        if (0 < *(int *)((uint)*(byte *)(iVar2 + 0xd) * 0x830 + 4 + *(int *)(in_ECX + 0x88))) {
          do {
            if (*(int *)(in_ECX + 0x5c) == 0) {
              free(*(void **)(*(int *)(iVar2 + 0x10) + local_10 * 4));
            }
            local_10 = local_10 + 1;
          } while (local_10 <
                   *(int *)((uint)*(byte *)(iVar2 + 0xd) * 0x830 + 4 + *(int *)(in_ECX + 0x88)));
        }
        iVar3 = *(int *)(in_ECX + 0x5c);
        if (iVar3 == 0) {
          free(*(void **)(iVar2 + 0x10));
          goto LAB_1003efa3;
        }
      }
      local_8 = local_8 + 1;
      local_c = local_c + 0x18;
    } while (local_8 < *(int *)(in_ECX + 0x114));
  }
  if (*(int *)(in_ECX + 0x88) != 0) {
    local_10 = 0;
    if (0 < *(int *)(in_ECX + 0x84)) {
      local_c = 0;
      do {
        iVar2 = *(int *)(in_ECX + 0x88) + local_c;
        iVar3 = *(int *)(in_ECX + 0x5c);
        if (iVar3 == 0) {
          free(*(void **)(iVar2 + 8));
          iVar3 = *(int *)(in_ECX + 0x5c);
          if (iVar3 == 0) {
            free(*(void **)(iVar2 + 0x1c));
            iVar3 = *(int *)(in_ECX + 0x5c);
            if (iVar3 == 0) {
              free(*(void **)(iVar2 + 0x20));
              iVar3 = *(int *)(in_ECX + 0x5c);
              if (iVar3 == 0) {
                free(*(void **)(iVar2 + 0x824));
                iVar3 = *(int *)(in_ECX + 0x5c);
              }
            }
          }
        }
        if (iVar3 == 0) {
          free((void *)(-(uint)(*(int *)(iVar2 + 0x828) != 0) & *(int *)(iVar2 + 0x828) - 4U));
        }
        local_10 = local_10 + 1;
        local_c = local_c + 0x830;
      } while (local_10 < *(int *)(in_ECX + 0x84));
    }
    if (*(int *)(in_ECX + 0x5c) != 0) goto LAB_1003f0b3;
    free(*(void **)(in_ECX + 0x88));
    iVar3 = *(int *)(in_ECX + 0x5c);
  }
  if ((iVar3 == 0) && (free(*(void **)(in_ECX + 0x110)), *(int *)(in_ECX + 0x5c) == 0)) {
    free(*(void **)(in_ECX + 0x198));
  }
LAB_1003f0b3:
  if (*(int *)(in_ECX + 0x1a0) != 0) {
    iVar3 = 0;
    if (0 < *(int *)(in_ECX + 0x19c)) {
      local_10 = 0;
      do {
        if (*(int *)(in_ECX + 0x5c) == 0) {
          free(*(void **)(*(int *)(in_ECX + 0x1a0) + 4 + local_10));
        }
        iVar3 = iVar3 + 1;
        local_10 = local_10 + 0x28;
      } while (iVar3 < *(int *)(in_ECX + 0x19c));
    }
    if (*(int *)(in_ECX + 0x5c) == 0) {
      free(*(void **)(in_ECX + 0x1a0));
    }
  }
  local_c = 0;
  if (0 < *(int *)(in_ECX + 4)) {
    puVar4 = (undefined4 *)(in_ECX + 0x3ac);
    do {
      if (0xf < local_c) break;
      if (((*(int *)(in_ECX + 0x5c) == 0) &&
          (free((void *)puVar4[-0x20]), *(int *)(in_ECX + 0x5c) == 0)) &&
         (free((void *)*puVar4), *(int *)(in_ECX + 0x5c) == 0)) {
        free((void *)puVar4[0x11]);
      }
      local_c = local_c + 1;
      puVar4 = puVar4 + 1;
    } while (local_c < *(int *)(in_ECX + 4));
  }
  puVar4 = (undefined4 *)(in_ECX + 0x440);
  local_10 = 2;
  do {
    if (((*(int *)(in_ECX + 0x5c) == 0) && (free((void *)puVar4[-2]), *(int *)(in_ECX + 0x5c) == 0))
       && ((free((void *)*puVar4), *(int *)(in_ECX + 0x5c) == 0 &&
           ((free((void *)puVar4[2]), *(int *)(in_ECX + 0x5c) == 0 &&
            (free((void *)puVar4[4]), *(int *)(in_ECX + 0x5c) == 0)))))) {
      free((void *)puVar4[6]);
    }
    puVar4 = puVar4 + 1;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  if ((*(int *)(in_ECX + 0x28) != 0) && (*(undefined4 **)(in_ECX + 0x20) != (undefined4 *)0x0)) {
    (**(code **)**(undefined4 **)(in_ECX + 0x20))(1);
  }
  return;
}

