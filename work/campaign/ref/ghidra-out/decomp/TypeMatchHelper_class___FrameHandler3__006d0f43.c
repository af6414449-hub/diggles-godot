
/* Library Function - Single Match
    int __cdecl TypeMatchHelper<class __FrameHandler3>(struct _s_HandlerType const *,struct
   _s_CatchableType const *,struct _s_ThrowInfo const *)
   
   Library: Visual Studio 2019 Release */

int __cdecl
TypeMatchHelper<class___FrameHandler3>
          (_s_HandlerType *param_1,_s_CatchableType *param_2,_s_ThrowInfo *param_3)

{
  byte bVar1;
  byte bVar2;
  TypeDescriptor *pTVar3;
  uint uVar4;
  TypeDescriptor *pTVar5;
  int iVar6;
  bool bVar7;
  
  pTVar3 = param_1->pType;
  if (((pTVar3 == (TypeDescriptor *)0x0) ||
      (pTVar5 = pTVar3 + 1, *(char *)&pTVar5->pVFTable == '\0')) ||
     (((param_1->adjectives & 0x80) != 0 && (((byte)*param_2 & 0x10) != 0)))) {
    iVar6 = 1;
  }
  else {
    iVar6 = 0;
    if (pTVar3 != *(TypeDescriptor **)(param_2 + 4)) {
      pTVar3 = *(TypeDescriptor **)(param_2 + 4) + 1;
      do {
        bVar1 = *(byte *)&pTVar5->pVFTable;
        bVar7 = bVar1 < *(byte *)&pTVar3->pVFTable;
        if (bVar1 != *(byte *)&pTVar3->pVFTable) {
LAB_006d0f94:
          uVar4 = -(uint)bVar7 | 1;
          goto LAB_006d0f99;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)&pTVar5->pVFTable + 1);
        bVar2 = *(byte *)((int)&pTVar3->pVFTable + 1);
        bVar7 = bVar1 < bVar2;
        if (bVar1 != bVar2) goto LAB_006d0f94;
        pTVar5 = (TypeDescriptor *)((int)&pTVar5->pVFTable + 2);
        pTVar3 = (TypeDescriptor *)((int)&pTVar3->pVFTable + 2);
      } while (bVar1 != 0);
      uVar4 = 0;
LAB_006d0f99:
      if (uVar4 != 0) {
        return 0;
      }
    }
    if (((((byte)*param_2 & 2) == 0) || ((param_1->adjectives & 8) != 0)) &&
       (((((byte)*param_3 & 1) == 0 || ((param_1->adjectives & 1) != 0)) &&
        ((((byte)*param_3 & 2) == 0 || ((param_1->adjectives & 2) != 0)))))) {
      iVar6 = 1;
    }
  }
  return iVar6;
}

