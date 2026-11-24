
void FUN_10011ad0(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  code *pcVar4;
  int *piVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 in_EDX;
  int *piVar10;
  undefined1 local_34 [12];
  undefined4 *local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004251d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170b81,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  local_14 = DAT_1416ee94;
  if (param_1 != param_2) {
    do {
      puVar6 = (undefined8 *)FUN_10011d90(local_34,local_14,param_1);
      piVar5 = DAT_1416ee94;
      local_20 = *puVar6;
      local_18 = *(undefined4 *)(puVar6 + 1);
      if ((char)local_18 == '\0') {
        if (DAT_1416ee98 == 0xccccccc) {
          FUN_10002ad0();
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        local_28 = &DAT_1416ee94;
        local_8 = 0;
        local_24 = 0;
        puVar7 = (undefined4 *)FUN_1003ff62(0x14);
        local_8 = 0xffffffff;
        local_24 = 0;
        *(undefined4 *)((int)puVar7 + 0xe) = *param_1;
        *puVar7 = piVar5;
        puVar7[1] = piVar5;
        puVar7[2] = piVar5;
        *(undefined2 *)(puVar7 + 3) = 0;
        piVar5 = DAT_1416ee94;
        DAT_1416ee98 = DAT_1416ee98 + 1;
        puVar7[1] = (int *)local_20;
        if ((int *)local_20 == piVar5) {
          *piVar5 = (int)puVar7;
          piVar5[1] = (int)puVar7;
          piVar5[2] = (int)puVar7;
          *(undefined1 *)(puVar7 + 3) = 1;
        }
        else {
          if (local_20._4_4_ == 0) {
            ((int *)local_20)[2] = (int)puVar7;
            if ((int *)local_20 == (int *)piVar5[2]) {
              piVar5[2] = (int)puVar7;
            }
          }
          else {
            *(int *)local_20 = (int)puVar7;
            if ((int *)local_20 == (int *)*piVar5) {
              *piVar5 = (int)puVar7;
            }
          }
          cVar1 = *(char *)(puVar7[1] + 0xc);
          while (cVar1 == '\0') {
            puVar2 = (undefined4 *)puVar7[1];
            puVar8 = *(undefined4 **)puVar2[1];
            if (puVar2 == puVar8) {
              puVar8 = (undefined4 *)((undefined4 *)puVar2[1])[2];
              if (*(char *)(puVar8 + 3) != '\0') {
                if (puVar7 == (undefined4 *)puVar2[2]) {
                  FUN_10004000(puVar2);
                  puVar7 = puVar2;
                }
                *(undefined1 *)(puVar7[1] + 0xc) = 1;
                *(undefined1 *)(*(int *)(puVar7[1] + 4) + 0xc) = 0;
                piVar9 = *(int **)(puVar7[1] + 4);
                piVar10 = (int *)*piVar9;
                *piVar9 = piVar10[2];
                if (*(char *)(piVar10[2] + 0xd) == '\0') {
                  *(int **)(piVar10[2] + 4) = piVar9;
                }
                piVar10[1] = piVar9[1];
                if (piVar9 == (int *)DAT_1416ee94[1]) {
                  DAT_1416ee94[1] = (int)piVar10;
                  piVar10[2] = (int)piVar9;
                }
                else {
                  piVar3 = (int *)piVar9[1];
                  if (piVar9 == (int *)piVar3[2]) {
                    piVar3[2] = (int)piVar10;
                    piVar10[2] = (int)piVar9;
                  }
                  else {
                    *piVar3 = (int)piVar10;
                    piVar10[2] = (int)piVar9;
                  }
                }
                goto LAB_10011ce9;
              }
LAB_10011c6f:
              *(undefined1 *)(puVar2 + 3) = 1;
              *(undefined1 *)(puVar8 + 3) = 1;
              *(undefined1 *)(*(int *)(puVar7[1] + 4) + 0xc) = 0;
              puVar7 = *(undefined4 **)(puVar7[1] + 4);
            }
            else {
              if (*(char *)(puVar8 + 3) == '\0') goto LAB_10011c6f;
              if (puVar7 == (undefined4 *)*puVar2) {
                FUN_10003f90(puVar2);
                puVar7 = puVar2;
              }
              *(undefined1 *)(puVar7[1] + 0xc) = 1;
              *(undefined1 *)(*(int *)(puVar7[1] + 4) + 0xc) = 0;
              piVar9 = *(int **)(puVar7[1] + 4);
              piVar10 = (int *)piVar9[2];
              piVar9[2] = *piVar10;
              if (*(char *)(*piVar10 + 0xd) == '\0') {
                *(int **)(*piVar10 + 4) = piVar9;
              }
              piVar10[1] = piVar9[1];
              if (piVar9 == (int *)DAT_1416ee94[1]) {
                DAT_1416ee94[1] = (int)piVar10;
              }
              else {
                piVar3 = (int *)piVar9[1];
                if (piVar9 == (int *)*piVar3) {
                  *piVar3 = (int)piVar10;
                }
                else {
                  piVar3[2] = (int)piVar10;
                }
              }
              *piVar10 = (int)piVar9;
LAB_10011ce9:
              piVar9[1] = (int)piVar10;
            }
            cVar1 = *(char *)(puVar7[1] + 0xc);
          }
          *(undefined1 *)(piVar5[1] + 0xc) = 1;
        }
      }
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  ExceptionList = local_10;
  return;
}

