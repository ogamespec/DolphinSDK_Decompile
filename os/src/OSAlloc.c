undefined4 * DLAddFront(undefined4 *param_1,undefined4 *param_2)
{
  param_2[1] = param_1;
  *param_2 = 0;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = param_2;
  }
  return param_2;
}

int DLLookup(int param_1,int param_2)
{
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 == param_2) break;
    param_1 = *(int *)(param_1 + 4);
  }
  return param_1;
}

int DLExtract(int param_1,int *param_2)
{
  if (param_2[1] != 0) {
    *(int *)param_2[1] = *param_2;
  }
  if (*param_2 == 0) {
    return param_2[1];
  }
  *(int *)(*param_2 + 4) = param_2[1];
  return param_1;
}

uint ** DLInsert(uint **param_1,uint **param_2)
{
  uint **ppuVar1;
  uint **ppuVar2;
  uint **ppuVar3;
  
  ppuVar2 = (uint **)0x0;
  for (ppuVar3 = param_1; (ppuVar3 != (uint **)0x0 && (ppuVar3 < param_2));
      ppuVar3 = (uint **)ppuVar3[1]) {
    ppuVar2 = ppuVar3;
  }
  param_2[1] = (uint *)ppuVar3;
  *param_2 = (uint *)ppuVar2;
  if ((ppuVar3 != (uint **)0x0) &&
     (*ppuVar3 = (uint *)param_2, (uint **)((int)param_2 + (int)param_2[2]) == ppuVar3)) {
    param_2[2] = (uint *)((int)param_2[2] + (int)ppuVar3[2]);
    ppuVar3 = (uint **)ppuVar3[1];
    param_2[1] = (uint *)ppuVar3;
    if (ppuVar3 != (uint **)0x0) {
      *ppuVar3 = (uint *)param_2;
    }
  }
  ppuVar1 = param_2;
  if ((ppuVar2 != (uint **)0x0) &&
     (ppuVar2[1] = (uint *)param_2, ppuVar1 = param_1,
     (uint **)((int)ppuVar2 + (int)ppuVar2[2]) == param_2)) {
    ppuVar2[2] = (uint *)((int)ppuVar2[2] + (int)param_2[2]);
    ppuVar2[1] = (uint *)ppuVar3;
    if (ppuVar3 != (uint **)0x0) {
      *ppuVar3 = (uint *)ppuVar2;
    }
  }
  return ppuVar1;
}

undefined4 DLOverlap(uint param_1,uint param_2,uint param_3)
{
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    if (((param_2 <= param_1) && (param_1 < param_3)) ||
       ((param_2 < param_1 + *(int *)(param_1 + 8) && (param_1 + *(int *)(param_1 + 8) <= param_3)))
       ) break;
    param_1 = *(uint *)(param_1 + 4);
  }
  return 1;
}

int DLSize(int param_1)
{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 4)) {
    iVar1 = iVar1 + *(int *)(param_1 + 8);
  }
  return iVar1;
}

int * OSAllocFromHeap(int param_1,int param_2)
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  if (HeapArray == 0) {
    OSPanic(...data.0,0x14d,@75);
  }
  if (param_2 < 1) {
    OSPanic(...data.0,0x14e,@76);
  }
  if ((param_1 < 0) || (NumHeaps <= param_1)) {
    OSPanic(...data.0,0x14f,@77);
  }
  if (*(int *)(HeapArray + param_1 * 0x18) < 0) {
    OSPanic(...data.0,0x150,@77);
  }
  iVar5 = HeapArray + param_1 * 0x18;
  uVar1 = param_2 + 0x3fU & 0xffffffe0;
  for (piVar6 = *(int **)(iVar5 + 4); (piVar6 != (int *)0x0 && (piVar6[2] < (int)uVar1));
      piVar6 = (int *)piVar6[1]) {
  }
  if (piVar6 == (int *)0x0) {
    OSReport(@78,uVar1);
    piVar6 = (int *)0x0;
  }
  else {
    if (((uint)piVar6 & 0x1f) != 0) {
      OSPanic(...data.0,0x168,@79);
    }
    if (piVar6[3] != 0) {
      OSPanic(...data.0,0x169,@79);
    }
    iVar2 = piVar6[2];
    if (iVar2 - uVar1 < 0x40) {
      uVar3 = DLExtract(*(undefined4 *)(iVar5 + 4),piVar6);
      *(undefined4 *)(iVar5 + 4) = uVar3;
    }
    else {
      piVar6[2] = uVar1;
      piVar4 = (int *)((int)piVar6 + uVar1);
      piVar4[2] = iVar2 - uVar1;
      piVar4[3] = 0;
      *piVar4 = *piVar6;
      piVar4[1] = piVar6[1];
      if (piVar4[1] != 0) {
        *(int **)piVar4[1] = piVar4;
      }
      if (*piVar4 == 0) {
        if (*(int **)(iVar5 + 4) != piVar6) {
          OSPanic(...data.0,0x186,@79);
        }
        *(int **)(iVar5 + 4) = piVar4;
      }
      else {
        *(int **)(*piVar4 + 4) = piVar4;
      }
    }
    uVar3 = DLAddFront(*(undefined4 *)(iVar5 + 8),piVar6);
    *(undefined4 *)(iVar5 + 8) = uVar3;
    piVar6[3] = iVar5;
    piVar6[4] = param_2;
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 0x20;
    *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + (piVar6[2] - (param_2 + 0x20));
    *(int *)(iVar5 + 0x14) = *(int *)(iVar5 + 0x14) + param_2;
    piVar6 = piVar6 + 8;
  }
  return piVar6;
}

int * OSAllocFixed(int **param_1,int **param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int **ppiVar4;
  int **ppiVar5;
  int **ppiVar6;
  int **ppiVar7;
  
  ppiVar5 = (int **)((uint)*param_1 & 0xffffffe0);
  ppiVar6 = (int **)((int)*param_2 + 0x1fU & 0xffffffe0);
  if (HeapArray == 0) {
    OSPanic(...data.0,0x1b0,@132);
  }
  if (ppiVar6 <= ppiVar5) {
    OSPanic(...data.0,0x1b1,@133);
  }
  if ((ppiVar5 < ArenaStart) || (ArenaEnd < ppiVar6)) {
    OSPanic(...data.0,0x1b3,@133);
  }
  for (iVar2 = 0; iVar2 < NumHeaps; iVar2 = iVar2 + 1) {
    piVar3 = (int *)(HeapArray + iVar2 * 0x18);
    if ((-1 < *piVar3) && (iVar1 = DLOverlap(piVar3[2],ppiVar5,ppiVar6), iVar1 != 0)) {
      OSReport(@134,ppiVar5,ppiVar6);
      return (int *)0x0;
    }
  }
  iVar2 = 0;
  do {
    if (NumHeaps <= iVar2) {
      if (((uint)ppiVar5 & 0x1f) != 0) {
        OSPanic(...data.0,0x225,@138);
      }
      if (((uint)ppiVar6 & 0x1f) != 0) {
        OSPanic(...data.0,0x226,@139);
      }
      if (ppiVar6 <= ppiVar5) {
        OSPanic(...data.0,0x227,@140);
      }
      *param_1 = (int *)ppiVar5;
      *param_2 = (int *)ppiVar6;
      return *param_1;
    }
    piVar3 = (int *)(HeapArray + iVar2 * 0x18);
    if (-1 < *piVar3) {
      for (ppiVar7 = (int **)piVar3[1]; ppiVar7 != (int **)0x0; ppiVar7 = (int **)ppiVar7[1]) {
        ppiVar4 = (int **)((int)ppiVar7 + (int)ppiVar7[2]);
        if (ppiVar5 < ppiVar4) {
          if (ppiVar6 <= ppiVar7) break;
          if ((((ppiVar7 < ppiVar5 + -8) || (ppiVar6 <= ppiVar7)) || (ppiVar4 < ppiVar5)) ||
             (ppiVar6 + 0x10 <= ppiVar4)) {
            if ((ppiVar5 + -8 <= ppiVar7) && (ppiVar7 < ppiVar6)) {
              if (ppiVar7 < ppiVar5) {
                ppiVar5 = ppiVar7;
              }
              if ((uint)((int)ppiVar4 - (int)ppiVar6) < 0x40) {
                OSPanic(...data.0,499,@135);
              }
              ppiVar6[2] = (int *)((int)ppiVar4 - (int)ppiVar6);
              ppiVar6[3] = (int *)0x0;
              ppiVar6[1] = ppiVar7[1];
              if (ppiVar6[1] != (int *)0x0) {
                *ppiVar6[1] = (int)ppiVar6;
              }
              *ppiVar6 = *ppiVar7;
              if (*ppiVar6 == (int *)0x0) {
                piVar3[1] = (int)ppiVar6;
              }
              else {
                (*ppiVar6)[1] = (int)ppiVar6;
              }
              *piVar3 = *piVar3 - ((int)ppiVar6 - (int)ppiVar7);
              break;
            }
            if ((ppiVar4 < ppiVar5) || (ppiVar6 + 0x10 <= ppiVar4)) {
              if ((uint)((int)ppiVar4 - (int)ppiVar6) < 0x40) {
                OSPanic(...data.0,0x213,@135);
              }
              ppiVar6[2] = (int *)((int)ppiVar4 - (int)ppiVar6);
              ppiVar6[3] = (int *)0x0;
              ppiVar6[1] = ppiVar7[1];
              if (ppiVar6[1] != (int *)0x0) {
                *ppiVar6[1] = (int)ppiVar6;
              }
              *ppiVar6 = (int *)ppiVar7;
              ppiVar7[1] = (int *)ppiVar6;
              ppiVar7[2] = (int *)((int)ppiVar5 - (int)ppiVar7);
              *piVar3 = *piVar3 - ((int)ppiVar6 - (int)ppiVar5);
              break;
            }
            if (ppiVar6 < ppiVar4) {
              ppiVar6 = ppiVar4;
            }
            if ((uint)((int)ppiVar5 - (int)ppiVar7) < 0x40) {
              OSPanic(...data.0,0x20c,@136);
            }
            *piVar3 = *piVar3 - ((int)ppiVar4 - (int)ppiVar5);
            ppiVar7[2] = (int *)((int)ppiVar5 - (int)ppiVar7);
          }
          else {
            if (ppiVar7 < ppiVar5) {
              ppiVar5 = ppiVar7;
            }
            if (ppiVar6 < ppiVar4) {
              ppiVar6 = ppiVar4;
            }
            iVar1 = DLExtract(piVar3[1],ppiVar7);
            piVar3[1] = iVar1;
            *piVar3 = *piVar3 - (int)ppiVar7[2];
          }
        }
      }
      if (*piVar3 < 0) {
        OSPanic(...data.0,0x222,@137);
      }
    }
    iVar2 = iVar2 + 1;
  } while( true );
}

void OSFreeToHeap(int param_1,uint param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (HeapArray == 0) {
    OSPanic(...data.0,0x23d,@142);
  }
  if (ArenaStart + 0x20U <= param_2) {
    if (param_2 < ArenaEnd) goto LAB_0001086c;
  }
  OSPanic(...data.0,0x23f,@143);
LAB_0001086c:
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0x240,@143);
  }
  if (*(int *)(HeapArray + param_1 * 0x18) < 0) {
    OSPanic(...data.0,0x241,@144);
  }
  iVar3 = param_2 - 0x20;
  iVar4 = HeapArray + param_1 * 0x18;
  if (*(int *)(param_2 - 0x14) != iVar4) {
    OSPanic(...data.0,0x246,@143);
  }
  iVar1 = DLLookup(*(undefined4 *)(iVar4 + 8),iVar3);
  if (iVar1 == 0) {
    OSPanic(...data.0,0x247,@143);
  }
  *(undefined4 *)(param_2 - 0x14) = 0;
  *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + -0x20;
  *(int *)(iVar4 + 0xc) =
       *(int *)(iVar4 + 0xc) - (*(int *)(param_2 - 0x18) - (*(int *)(param_2 - 0x10) + 0x20));
  *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) - *(int *)(param_2 - 0x10);
  uVar2 = DLExtract(*(undefined4 *)(iVar4 + 8),iVar3);
  *(undefined4 *)(iVar4 + 8) = uVar2;
  uVar2 = DLInsert(*(undefined4 *)(iVar4 + 4),iVar3);
  *(undefined4 *)(iVar4 + 4) = uVar2;
  return;
}

undefined4 OSSetCurrentHeap(int param_1)
{
  undefined4 uVar1;
  
  if (HeapArray == 0) {
    OSPanic(...data.0,0x267,@146);
  }
  if ((param_1 < 0) || (NumHeaps <= param_1)) {
    OSPanic(...data.0,0x268,@147);
  }
  if (*(int *)(HeapArray + param_1 * 0x18) < 0) {
    OSPanic(...data.0,0x269,@147);
  }
  uVar1 = __OSCurrHeap;
  __OSCurrHeap = param_1;
  return uVar1;
}

uint OSInitAlloc(uint param_1,uint param_2,uint param_3)
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((int)param_3 < 1) {
    OSPanic(...data.0,0x283,@154);
  }
  if (param_2 <= param_1) {
    OSPanic(...data.0,0x285,@155);
  }
  if ((param_2 - param_1) / 0x18 < param_3) {
    OSPanic(...data.0,0x288,@156);
  }
  HeapArray = param_1;
  NumHeaps = param_3;
  for (iVar2 = 0; iVar2 < (int)NumHeaps; iVar2 = iVar2 + 1) {
    puVar3 = (undefined4 *)(HeapArray + iVar2 * 0x18);
    *puVar3 = 0xffffffff;
    puVar3[2] = 0;
    puVar3[1] = 0;
    puVar3[5] = 0;
    puVar3[4] = 0;
    puVar3[3] = 0;
  }
  __OSCurrHeap = 0xffffffff;
  uVar1 = HeapArray + param_3 * 0x18 + 0x1f & 0xffffffe0;
  ArenaEnd = param_2 & 0xffffffe0;
  ArenaStart = uVar1;
  if (ArenaEnd - uVar1 < 0x40) {
    OSPanic(...data.0,0x2a4,@156);
  }
  return uVar1;
}

int OSCreateHeap(uint param_1,uint param_2)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (HeapArray == 0) {
    OSPanic(...data.0,0x2bd,@172);
  }
  if (param_2 <= param_1) {
    OSPanic(...data.0,0x2be,@173);
  }
  puVar1 = (undefined4 *)(param_1 + 0x1f & 0xffffffe0);
  puVar2 = (undefined4 *)(param_2 & 0xffffffe0);
  if (puVar2 <= puVar1) {
    OSPanic(...data.0,0x2c1,@173);
  }
  if ((puVar1 < ArenaStart) || (ArenaEnd < puVar2)) {
    OSPanic(...data.0,0x2c3,@173);
  }
  if ((uint)((int)puVar2 - (int)puVar1) < 0x40) {
    OSPanic(...data.0,0x2c5,@174);
  }
  for (iVar5 = 0; iVar5 < NumHeaps; iVar5 = iVar5 + 1) {
    if (-1 < *(int *)(HeapArray + iVar5 * 0x18)) {
      iVar3 = DLOverlap(*(undefined4 *)(HeapArray + iVar5 * 0x18 + 4),puVar1,puVar2);
      if (iVar3 != 0) {
        OSPanic(...data.0,0x2cf,@173);
      }
      iVar3 = DLOverlap(*(undefined4 *)(HeapArray + iVar5 * 0x18 + 8),puVar1,puVar2);
      if (iVar3 != 0) {
        OSPanic(...data.0,0x2d1,@173);
      }
    }
  }
  iVar5 = 0;
  while( true ) {
    if (NumHeaps <= iVar5) {
      OSReport(@175);
      return -1;
    }
    piVar4 = (int *)(HeapArray + iVar5 * 0x18);
    if (*piVar4 < 0) break;
    iVar5 = iVar5 + 1;
  }
  *piVar4 = (int)puVar2 - (int)puVar1;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = *piVar4;
  puVar1[3] = 0;
  piVar4[1] = (int)puVar1;
  piVar4[2] = 0;
  piVar4[5] = 0;
  piVar4[4] = 0;
  piVar4[3] = 0;
  return iVar5;
}

void OSDestroyHeap(int param_1)
{
  int iVar1;
  int *piVar2;
  
  if (HeapArray == 0) {
    OSPanic(...data.0,0x30a,@181);
  }
  if ((param_1 < 0) || (NumHeaps <= param_1)) {
    OSPanic(...data.0,0x30b,@182);
  }
  if (*(int *)(HeapArray + param_1 * 0x18) < 0) {
    OSPanic(...data.0,0x30c,@182);
  }
  piVar2 = (int *)(HeapArray + param_1 * 0x18);
  iVar1 = DLSize(piVar2[1]);
  if (*piVar2 != iVar1) {
    OSReport(@183,param_1,iVar1,*piVar2);
  }
  *piVar2 = -1;
  piVar2[5] = 0;
  piVar2[4] = 0;
  piVar2[3] = 0;
  if (__OSCurrHeap == param_1) {
    __OSCurrHeap = -1;
  }
  return;
}

void OSAddToHeap(int param_1,uint param_2,uint param_3)
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (HeapArray == 0) {
    OSPanic(...data.0,0x339,@192);
  }
  if ((param_1 < 0) || (NumHeaps <= param_1)) {
    OSPanic(...data.0,0x33a,@193);
  }
  if (*(int *)(HeapArray + param_1 * 0x18) < 0) {
    OSPanic(...data.0,0x33b,@193);
  }
  piVar3 = (int *)(HeapArray + param_1 * 0x18);
  if (param_3 <= param_2) {
    OSPanic(...data.0,0x33f,@194);
  }
  uVar1 = param_2 + 0x1f & 0xffffffe0;
  param_3 = param_3 & 0xffffffe0;
  if (param_3 - uVar1 < 0x40) {
    OSPanic(...data.0,0x343,@195);
  }
  if ((uVar1 < ArenaStart) || (ArenaEnd < param_3)) {
    OSPanic(...data.0,0x345,@194);
  }
  for (iVar4 = 0; iVar4 < NumHeaps; iVar4 = iVar4 + 1) {
    if (-1 < *(int *)(HeapArray + iVar4 * 0x18)) {
      iVar2 = DLOverlap(*(undefined4 *)(HeapArray + iVar4 * 0x18 + 4),uVar1,param_3);
      if (iVar2 != 0) {
        OSPanic(...data.0,0x34f,@194);
      }
      iVar2 = DLOverlap(*(undefined4 *)(HeapArray + iVar4 * 0x18 + 8),uVar1,param_3);
      if (iVar2 != 0) {
        OSPanic(...data.0,0x351,@194);
      }
    }
  }
  *(uint *)(uVar1 + 8) = param_3 - uVar1;
  *(undefined4 *)(uVar1 + 0xc) = 0;
  *piVar3 = *piVar3 + *(int *)(uVar1 + 8);
  iVar4 = DLInsert(piVar3[1],uVar1);
  piVar3[1] = iVar4;
  return;
}

int OSCheckHeap(int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar2 = 0;
  iVar1 = 0;
  if (HeapArray == 0) {
    OSReport(@349,0x37d);
    iVar1 = -1;
  }
  else if ((param_1 < 0) || (NumHeaps <= param_1)) {
    OSReport(@350,0x37e);
    iVar1 = -1;
  }
  else {
    piVar3 = (int *)(HeapArray + param_1 * 0x18);
    if (*piVar3 < 0) {
      OSReport(@351,0x381);
      iVar1 = -1;
    }
    else if ((piVar3[2] == 0) || (*(int *)piVar3[2] == 0)) {
      for (uVar4 = piVar3[2]; uVar4 != 0; uVar4 = *(uint *)(uVar4 + 4)) {
        if ((uVar4 < ArenaStart) || (ArenaEnd <= uVar4)) {
          OSReport(@353,0x386);
          return -1;
        }
        if ((uVar4 & 0x1f) != 0) {
          OSReport(@354,0x387);
          return -1;
        }
        if ((*(int *)(uVar4 + 4) != 0) && (**(uint **)(uVar4 + 4) != uVar4)) {
          OSReport(@355,0x388);
          return -1;
        }
        if (*(uint *)(uVar4 + 8) < 0x40) {
          OSReport(@356,0x389);
          return -1;
        }
        if ((*(uint *)(uVar4 + 8) & 0x1f) != 0) {
          OSReport(@357,0x38a);
          return -1;
        }
        iVar2 = iVar2 + *(int *)(uVar4 + 8);
        if ((iVar2 < 1) || (*piVar3 < iVar2)) {
          OSReport(@358,0x38d);
          return -1;
        }
        if (*(int **)(uVar4 + 0xc) != piVar3) {
          OSReport(@359,0x390);
          return -1;
        }
        if (*(uint *)(uVar4 + 8) < *(int *)(uVar4 + 0x10) + 0x20U) {
          OSReport(@360,0x391);
          return -1;
        }
      }
      if ((piVar3[1] == 0) || (*(int *)piVar3[1] == 0)) {
        for (uVar4 = piVar3[1]; uVar4 != 0; uVar4 = *(uint *)(uVar4 + 4)) {
          if ((uVar4 < ArenaStart) || (ArenaEnd <= uVar4)) {
            OSReport(@353,0x398);
            return -1;
          }
          if ((uVar4 & 0x1f) != 0) {
            OSReport(@354,0x399);
            return -1;
          }
          if ((*(int *)(uVar4 + 4) != 0) && (**(uint **)(uVar4 + 4) != uVar4)) {
            OSReport(@355,0x39a);
            return -1;
          }
          if (*(uint *)(uVar4 + 8) < 0x40) {
            OSReport(@356,0x39b);
            return -1;
          }
          if ((*(uint *)(uVar4 + 8) & 0x1f) != 0) {
            OSReport(@357,0x39c);
            return -1;
          }
          if ((*(int *)(uVar4 + 4) != 0) && (*(uint *)(uVar4 + 4) <= uVar4 + *(int *)(uVar4 + 8))) {
            OSReport(@362,0x39d);
            return -1;
          }
          iVar2 = iVar2 + *(int *)(uVar4 + 8);
          iVar1 = *(int *)(uVar4 + 8) + iVar1 + -0x20;
          if ((iVar2 < 1) || (*piVar3 < iVar2)) {
            OSReport(@358,0x3a1);
            return -1;
          }
          if (*(int *)(uVar4 + 0xc) != 0) {
            OSReport(@363,0x3a4);
            return -1;
          }
        }
        if (iVar2 != *piVar3) {
          OSReport(@364,0x3a8);
          iVar1 = -1;
        }
      }
      else {
        OSReport(@361,0x395);
        iVar1 = -1;
      }
    }
    else {
      OSReport(@352,899);
      iVar1 = -1;
    }
  }
  return iVar1;
}

int OSReferentSize(uint param_1)
{
  int iVar1;
  uint uVar2;
  
  if (HeapArray == 0) {
    OSPanic(...data.0,0x3bb,@366);
  }
  if (ArenaStart + 0x20U <= param_1) {
    if (param_1 < ArenaEnd) goto LAB_00011528;
  }
  OSPanic(...data.0,0x3bd,@367);
LAB_00011528:
  if ((param_1 & 0x1f) != 0) {
    OSPanic(...data.0,0x3be,@367);
  }
  if (*(int *)(param_1 - 0x14) == 0) {
    OSPanic(...data.0,0x3c2,@367);
  }
  uVar2 = *(int *)(param_1 - 0x14) - HeapArray;
  if (uVar2 != (uVar2 / 0x18) * 0x18) {
    OSPanic(...data.0,0x3c4,@367);
  }
  if ((*(uint *)(param_1 - 0x14) < HeapArray) ||
     (HeapArray + NumHeaps * 0x18 <= *(uint *)(param_1 - 0x14))) {
    OSPanic(...data.0,0x3c6,@367);
  }
  if (**(int **)(param_1 - 0x14) < 0) {
    OSPanic(...data.0,0x3c7,@367);
  }
  iVar1 = DLLookup(*(undefined4 *)(*(int *)(param_1 - 0x14) + 8),param_1 - 0x20);
  if (iVar1 == 0) {
    OSPanic(...data.0,0x3c9,@367);
  }
  return *(int *)(param_1 - 0x18) + -0x20;
}

void OSDumpHeap(int param_1)
{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  
  OSReport(@381,param_1);
  if (HeapArray == 0) {
    OSPanic(...data.0,0x3de,@382);
  }
  if ((param_1 < 0) || (NumHeaps <= param_1)) {
    OSPanic(...data.0,0x3df,@383);
  }
  puVar2 = (uint *)(HeapArray + param_1 * 0x18);
  if ((int)*puVar2 < 0) {
    OSReport(@384);
  }
  else {
    iVar1 = OSCheckHeap(param_1);
    if (iVar1 < 0) {
      OSPanic(...data.0,1000,@385);
    }
    OSReport((@387 * ((double)CONCAT44(0x43300000,puVar2[3]) - @393)) /
             ((double)CONCAT44(0x43300000,*puVar2 ^ 0x80000000) - @395),
             (@387 * ((double)CONCAT44(0x43300000,puVar2[4]) - @393)) /
             ((double)CONCAT44(0x43300000,*puVar2 ^ 0x80000000) - @395),
             (@387 * ((double)CONCAT44(0x43300000,puVar2[5]) - @393)) /
             ((double)CONCAT44(0x43300000,*puVar2 ^ 0x80000000) - @395),@386,puVar2[3],puVar2[4],
             puVar2[5]);
    OSReport(@388);
    OSReport(@389);
    if ((puVar2[2] != 0) && (*(int *)puVar2[2] != 0)) {
      OSPanic(...data.0,0x3f5,@385);
    }
    for (puVar3 = (undefined4 *)puVar2[2]; puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)puVar3[1]) {
      OSReport(@390,puVar3,puVar3[2],(int)puVar3 + puVar3[2],*puVar3,puVar3[1]);
    }
    OSReport(@391);
    for (puVar3 = (undefined4 *)puVar2[1]; puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)puVar3[1]) {
      OSReport(@390,puVar3,puVar3[2],(int)puVar3 + puVar3[2],*puVar3,puVar3[1]);
    }
  }
  return;
}

void OSVisitAllocated(code *param_1)
{
  uint uVar1;
  int iVar2;
  
  for (uVar1 = 0; uVar1 < NumHeaps; uVar1 = uVar1 + 1) {
    if (-1 < *(int *)(HeapArray + uVar1 * 0x18)) {
      for (iVar2 = *(int *)(HeapArray + uVar1 * 0x18 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4))
      {
        (*param_1)(iVar2 + 0x20,*(undefined4 *)(iVar2 + 8));
      }
    }
  }
  return;
}
