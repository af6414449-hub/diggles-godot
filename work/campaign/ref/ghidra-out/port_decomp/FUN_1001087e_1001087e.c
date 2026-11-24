
void FUN_1001087e(void)

{
  int *piVar1;
  char in_AL;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  if ((in_AL == '\0') && (unaff_ESI != 0)) {
    do {
      piVar1 = *(int **)(unaff_EDI + -4 + unaff_ESI * 4);
      if (piVar1 != (int *)0x0) {
        *(undefined4 *)(unaff_EDI + -4 + unaff_ESI * 4) = 0;
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      unaff_ESI = unaff_ESI + -1;
    } while (unaff_ESI != 0);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
  }
  return;
}

