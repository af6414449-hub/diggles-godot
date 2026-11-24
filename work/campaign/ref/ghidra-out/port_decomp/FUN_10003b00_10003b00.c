
void FUN_10003b00(int *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  code *pcVar6;
  undefined8 *puVar7;
  int *piVar8;
  int *in_ECX;
  int *piVar9;
  int *piVar10;
  undefined4 in_EDX;
  undefined1 local_38 [16];
  undefined4 local_28;
  undefined8 local_24;
  undefined4 local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100417bd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  __CheckForDebuggerJustMyCode(&DAT_14170b81,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  local_18 = *in_ECX;
  do {
    if (local_14 == param_2) {
      ExceptionList = local_10;
      return;
    }
    puVar7 = (undefined8 *)FUN_10004330(local_38,local_18,local_14);
    local_24 = *puVar7;
    local_1c = *(undefined4 *)(puVar7 + 1);
    if ((char)local_1c == '\0') {
      if (in_ECX[1] == 0xaaaaaaa) {
        FUN_10002ad0();
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      iVar2 = *in_ECX;
      local_8 = 0;
      local_28 = 0;
      piVar8 = (int *)FUN_1003ff62(0x18);
      local_8 = 0xffffffff;
      local_28 = 0;
      iVar3 = local_14[1];
      piVar8[4] = *local_14;
      piVar8[5] = iVar3;
      *piVar8 = iVar2;
      piVar8[1] = iVar2;
      piVar8[2] = iVar2;
      *(undefined2 *)(piVar8 + 3) = 0;
      in_ECX[1] = in_ECX[1] + 1;
      piVar4 = (int *)*in_ECX;
      piVar8[1] = (int)(int *)local_24;
      if ((int *)local_24 == piVar4) {
        *piVar4 = (int)piVar8;
        piVar4[1] = (int)piVar8;
        piVar4[2] = (int)piVar8;
        *(undefined1 *)(piVar8 + 3) = 1;
      }
      else {
        if (local_24._4_4_ == 0) {
          ((int *)local_24)[2] = (int)piVar8;
          if ((int *)local_24 == (int *)piVar4[2]) {
            piVar4[2] = (int)piVar8;
          }
        }
        else {
          *(int *)local_24 = (int)piVar8;
          if ((int *)local_24 == (int *)*piVar4) {
            *piVar4 = (int)piVar8;
          }
        }
        cVar1 = *(char *)(piVar8[1] + 0xc);
        while (cVar1 == '\0') {
          piVar10 = (int *)piVar8[1];
          piVar9 = *(int **)piVar10[1];
          if (piVar10 == piVar9) {
            piVar9 = (int *)((undefined4 *)piVar10[1])[2];
            if ((char)piVar9[3] == '\0') goto LAB_10003c98;
            if (piVar8 == (int *)piVar10[2]) {
              FUN_10004000(piVar10);
              piVar8 = piVar10;
            }
            *(undefined1 *)(piVar8[1] + 0xc) = 1;
            *(undefined1 *)(*(int *)(piVar8[1] + 4) + 0xc) = 0;
            piVar10 = *(int **)(piVar8[1] + 4);
            piVar9 = (int *)*piVar10;
            *piVar10 = piVar9[2];
            if (*(char *)(piVar9[2] + 0xd) == '\0') {
              *(int **)(piVar9[2] + 4) = piVar10;
            }
            piVar9[1] = piVar10[1];
            if (piVar10 == *(int **)(*in_ECX + 4)) {
              *(int **)(*in_ECX + 4) = piVar9;
              piVar9[2] = (int)piVar10;
            }
            else {
              piVar5 = (int *)piVar10[1];
              if (piVar10 == (int *)piVar5[2]) {
                piVar5[2] = (int)piVar9;
                piVar9[2] = (int)piVar10;
              }
              else {
                *piVar5 = (int)piVar9;
                piVar9[2] = (int)piVar10;
              }
            }
LAB_10003d0c:
            piVar10[1] = (int)piVar9;
          }
          else {
            if ((char)piVar9[3] != '\0') {
              if (piVar8 == (int *)*piVar10) {
                FUN_10003f90(piVar10);
                piVar8 = piVar10;
              }
              *(undefined1 *)(piVar8[1] + 0xc) = 1;
              *(undefined1 *)(*(int *)(piVar8[1] + 4) + 0xc) = 0;
              piVar10 = *(int **)(piVar8[1] + 4);
              piVar9 = (int *)piVar10[2];
              piVar10[2] = *piVar9;
              if (*(char *)(*piVar9 + 0xd) == '\0') {
                *(int **)(*piVar9 + 4) = piVar10;
              }
              piVar9[1] = piVar10[1];
              if (piVar10 == *(int **)(*in_ECX + 4)) {
                *(int **)(*in_ECX + 4) = piVar9;
              }
              else {
                piVar5 = (int *)piVar10[1];
                if (piVar10 == (int *)*piVar5) {
                  *piVar5 = (int)piVar9;
                }
                else {
                  piVar5[2] = (int)piVar9;
                }
              }
              *piVar9 = (int)piVar10;
              goto LAB_10003d0c;
            }
LAB_10003c98:
            *(undefined1 *)(piVar10 + 3) = 1;
            *(undefined1 *)(piVar9 + 3) = 1;
            *(undefined1 *)(*(int *)(piVar8[1] + 4) + 0xc) = 0;
            piVar8 = *(int **)(piVar8[1] + 4);
          }
          cVar1 = *(char *)(piVar8[1] + 0xc);
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
      }
    }
    local_14 = local_14 + 2;
  } while( true );
}

