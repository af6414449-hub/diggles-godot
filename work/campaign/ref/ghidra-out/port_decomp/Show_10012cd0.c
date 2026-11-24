
/* public: void __thiscall ScreenResolutionManager::Show(void) */

void __thiscall ScreenResolutionManager::Show(ScreenResolutionManager *this)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
                    /* 0x12cd0  255  ?Show@ScreenResolutionManager@@QAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar4 = (int *)**(int **)this;
  if (piVar4 != *(int **)this) {
    do {
      piVar3 = piVar4 + 4;
      if (0xf < (uint)piVar4[9]) {
        piVar3 = (int *)*piVar3;
      }
      OutputDebugStringA((LPCSTR)piVar3);
      OutputDebugStringA("\n");
      piVar3 = (int *)piVar4[2];
      if (*(char *)((int)piVar3 + 0xd) == '\0') {
        cVar1 = *(char *)(*piVar3 + 0xd);
        piVar4 = piVar3;
        piVar3 = (int *)*piVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar3 + 0xd);
          piVar4 = piVar3;
          piVar3 = (int *)*piVar3;
        }
      }
      else {
        cVar1 = *(char *)(piVar4[1] + 0xd);
        piVar2 = (int *)piVar4[1];
        piVar3 = piVar4;
        while ((piVar4 = piVar2, cVar1 == '\0' && (piVar3 == (int *)piVar4[2]))) {
          cVar1 = *(char *)(piVar4[1] + 0xd);
          piVar2 = (int *)piVar4[1];
          piVar3 = piVar4;
        }
      }
    } while (piVar4 != *(int **)this);
  }
  return;
}

