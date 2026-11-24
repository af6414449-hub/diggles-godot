
int FUN_100267d0(int *param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *in_ECX;
  int iVar4;
  int in_EDX;
  int iVar5;
  int iVar6;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  iVar5 = 0;
  local_10 = 0;
  if (0 < in_EDX + -4) {
    do {
      if ((*in_ECX == -1) &&
         ((((bVar1 = in_ECX[1], (bVar1 & 0xf0) == 0xf0 || ((bVar1 & 0xfe) == 0xe2)) &&
           ((bVar1 & 6) != 0)) && (((in_ECX[2] & 0xf0U) != 0xf0 && ((in_ECX[2] & 0xcU) != 0xc))))))
      {
        iVar5 = FUN_10021630();
        if ((in_ECX[2] & 2U) == 0) {
          local_8 = 0;
        }
        else {
          local_8 = 1;
          if ((in_ECX[1] & 6U) == 6) {
            local_8 = 4;
          }
        }
        local_8 = local_8 + iVar5;
        iVar6 = 4;
        if (iVar5 == 0) {
          iVar5 = local_10 + 8;
          local_14 = 0;
          do {
            if (0x8ff < iVar6) goto LAB_10026a15;
            if (in_EDX + -4 <= iVar5) {
              if (local_14 == 0) goto LAB_10026a15;
              break;
            }
            iVar3 = FUN_10021570();
            if (iVar3 != 0) {
              if ((in_ECX[2] & 2U) == 0) {
                iVar3 = 0;
              }
              else {
                iVar3 = 1;
                if ((in_ECX[1] & 6U) == 6) {
                  iVar3 = 4;
                }
              }
              iVar3 = iVar6 - iVar3;
              if ((in_ECX[iVar6 + 2] & 2U) == 0) {
                iVar4 = 0;
              }
              else {
                iVar4 = 1;
                if ((in_ECX[iVar6 + 1] & 6U) == 6) {
                  iVar4 = 4;
                }
              }
              if ((local_10 + 4 + iVar4 + iVar3 + iVar6 <= in_EDX) &&
                 (iVar4 = FUN_10021570(), iVar4 != 0)) {
                *param_1 = iVar3;
                local_14 = iVar3;
                local_8 = iVar6;
              }
            }
            iVar6 = iVar6 + 1;
            iVar5 = iVar5 + 2;
          } while (local_14 == 0);
        }
        if (local_10 + local_8 <= in_EDX) {
          iVar5 = 0;
          local_18 = 0;
          while( true ) {
            if ((in_ECX[local_18 + 2] & 2U) == 0) {
              iVar6 = 0;
            }
            else {
              iVar6 = 1;
              if ((in_ECX[local_18 + 1] & 6U) == 6) {
                iVar6 = 4;
              }
            }
            iVar3 = FUN_10021630();
            local_18 = local_18 + iVar3 + iVar6;
            if (in_EDX - local_10 < local_18 + 4) break;
            if ((((in_ECX[local_18] != -1) ||
                 (((bVar1 = in_ECX[local_18 + 1], (bVar1 & 0xf0) != 0xf0 && ((bVar1 & 0xfe) != 0xe2)
                   ) || ((bVar1 & 6) == 0)))) ||
                (((bVar2 = in_ECX[local_18 + 2], (bVar2 & 0xf0) == 0xf0 || ((bVar2 & 0xc) == 0xc))
                 || (((in_ECX[1] ^ bVar1) & 0xfe) != 0)))) ||
               ((((bVar2 ^ in_ECX[2]) & 0xc) != 0 ||
                (((bVar2 & 0xf0) == 0) != ((in_ECX[2] & 0xf0U) == 0))))) goto LAB_10026a15;
            iVar5 = iVar5 + 1;
            if (9 < iVar5) goto LAB_10026a4e;
          }
          if (0 < iVar5) goto LAB_10026a4e;
        }
LAB_10026a15:
        if ((local_10 == 0) && (local_8 == in_EDX)) {
LAB_10026a4e:
          *param_2 = local_8;
          return local_10;
        }
        *param_1 = 0;
      }
      iVar5 = local_10 + 1;
      in_ECX = in_ECX + 1;
      local_10 = iVar5;
    } while (iVar5 < in_EDX + -4);
  }
  *param_2 = 0;
  return iVar5;
}

