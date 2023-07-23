undefined4 __ReadMem(undefined *param_1,uint param_2)
{
  undefined4 uVar1;
  undefined *puVar2;
  uint uVar3;
  
  if ((uint)(dlistSize - bytesRead) < param_2) {
    uVar1 = 0;
  }
  else {
    puVar2 = dlist;
    for (uVar3 = 0; uVar3 < param_2; uVar3 = uVar3 + 1) {
      *param_1 = *puVar2;
      param_1 = param_1 + 1;
      puVar2 = puVar2 + 1;
    }
    bytesRead = bytesRead + param_2;
    dlist = dlist + param_2;
    uVar1 = 1;
  }
  return uVar1;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __SaveCPRegs(undefined param_1,uint param_2,code *param_3)
{
  int iVar1;
  
  DPF(...data.0,param_1,param_3);
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    break;
  case 5:
    ppcRam00000000[5] = param_3;
    break;
  case 6:
    ppcRam00000000[6] = param_3;
    break;
  case 7:
    ppcRam00000000[(param_2 & 0xff) + 7] = param_3;
    break;
  case 8:
    ppcRam00000000[(param_2 & 0xff) + 0xf] = param_3;
    break;
  case 9:
    ppcRam00000000[(param_2 & 0xff) + 0x17] = param_3;
    break;
  case 10:
    iVar1 = (param_2 & 0xff) - 0x15;
    if ((-1 < iVar1) && (iVar1 < 4)) {
      ppcRam00000000[(param_2 & 0xff) + 0xd] = param_3;
    }
    break;
  case 0xb:
    iVar1 = (param_2 & 0xff) - 0x15;
    if ((-1 < iVar1) && (iVar1 < 4)) {
      ppcRam00000000[(param_2 & 0xff) + 0x11] = param_3;
    }
    break;
  default:
    if (_DAT_000121c4 <= (int)ppcRam00000000[1]) {
      (**ppcRam00000000)(_DAT_000121c4,0x71,_DAT_000121c8);
    }
    OSReport(@39,param_1);
  }
  return;
}

void DPF(void)
{
  return;
}

void __ReconstVtxStatus(uint param_1)
{
  if ((*(uint *)(iRam00000000 + 0x14) >> 0xb & 3) != 0) {
    if ((*(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c) >> 9 & 1) == 0) {
      *(undefined *)(iRam00000000 + 0x41c) = 1;
      *(undefined *)(iRam00000000 + 0x41d) = 0;
    }
    else {
      *(undefined *)(iRam00000000 + 0x41c) = 0;
      *(undefined *)(iRam00000000 + 0x41d) = 1;
    }
  }
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010554) */
/* WARNING: Removing unreachable block (ram,0x0001063c) */
/* WARNING: Removing unreachable block (ram,0x0001072c) */
/* WARNING: Removing unreachable block (ram,0x0001081c) */
/* WARNING: Removing unreachable block (ram,0x0001090c) */
/* WARNING: Removing unreachable block (ram,0x00010894) */
/* WARNING: Removing unreachable block (ram,0x000107a4) */
/* WARNING: Removing unreachable block (ram,0x000106b4) */
/* WARNING: Removing unreachable block (ram,0x000105c0) */
/* WARNING: Removing unreachable block (ram,0x00010430) */
/* WARNING: Removing unreachable block (ram,0x00010984) */
/* WARNING: Removing unreachable block (ram,0x000104a8) */
int GetAttrSize(uint param_1,undefined4 param_2)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  switch(param_2) {
  case 0:
    if ((*(uint *)(iRam00000000 + 0x14) & 1) != 0) {
      return 1;
    }
    return 0;
  case 1:
    if ((*(uint *)(iRam00000000 + 0x14) >> 1 & 1) != 0) {
      return 1;
    }
    return 0;
  case 2:
    if ((*(uint *)(iRam00000000 + 0x14) >> 2 & 1) != 0) {
      return 1;
    }
    return 0;
  case 3:
    if ((*(uint *)(iRam00000000 + 0x14) >> 3 & 1) != 0) {
      return 1;
    }
    return 0;
  case 4:
    if ((*(uint *)(iRam00000000 + 0x14) >> 4 & 1) != 0) {
      return 1;
    }
    return 0;
  case 5:
    if ((*(uint *)(iRam00000000 + 0x14) >> 5 & 1) != 0) {
      return 1;
    }
    return 0;
  case 6:
    if ((*(uint *)(iRam00000000 + 0x14) >> 6 & 1) != 0) {
      return 1;
    }
    return 0;
  case 7:
    if ((*(uint *)(iRam00000000 + 0x14) >> 7 & 1) != 0) {
      return 1;
    }
    return 0;
  case 8:
    if ((*(uint *)(iRam00000000 + 0x14) >> 8 & 1) != 0) {
      return 1;
    }
    return 0;
  case 9:
    uVar3 = *(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c);
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 9 & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return ((uVar3 & 1) + 2) * *(int *)(vtxCompSize + (uVar3 & 0xe) * 2);
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
    break;
  case 10:
    uVar3 = *(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c);
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 0xb & 3;
    if (uVar1 == 2) {
      if (((uVar3 >> 9 & 1) != 0) && ((int)uVar3 < 0)) {
        return 3;
      }
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        if ((uVar3 >> 9 & 1) == 0) {
          iVar2 = 3;
        }
        else {
          iVar2 = 9;
        }
        return iVar2 * *(int *)(vtxCompSize + (uVar3 >> 8 & 0x1c));
      }
      return 0;
    }
    if (uVar1 < 4) {
      if (((uVar3 >> 9 & 1) != 0) && ((int)uVar3 < 0)) {
        return 6;
      }
      return 2;
    }
    break;
  case 0xb:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 0xd & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return *(int *)(clrCompSize +
                       (*(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c) >> 0xc & 0x1c));
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
    break;
  case 0xc:
    uVar1 = *(uint *)(iRam00000000 + 0x14) >> 0xf & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return *(int *)(clrCompSize +
                       (*(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c) >> 0x10 & 0x1c));
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
    break;
  case 0xd:
    uVar3 = *(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c);
    uVar1 = *(uint *)(iRam00000000 + 0x18) & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return ((uVar3 >> 0x15 & 1) + 1) * *(int *)(vtxCompSize + (uVar3 >> 0x14 & 0x1c));
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
    break;
  case 0xe:
    uVar3 = *(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c);
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 2 & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return ((uVar3 & 1) + 1) * *(int *)(vtxCompSize + (uVar3 & 0xe) * 2);
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
    break;
  case 0xf:
    uVar3 = *(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c);
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 4 & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return ((uVar3 >> 9 & 1) + 1) * *(int *)(vtxCompSize + (uVar3 >> 8 & 0x1c));
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
    break;
  case 0x10:
    uVar3 = *(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c);
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 6 & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return ((uVar3 >> 0x12 & 1) + 1) * *(int *)(vtxCompSize + (uVar3 >> 0x11 & 0x1c));
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
    break;
  case 0x11:
    uVar3 = *(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c);
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 8 & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return ((uVar3 >> 0x1b & 1) + 1) * *(int *)(vtxCompSize + (uVar3 >> 0x1a & 0x1c));
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
    break;
  case 0x12:
    uVar3 = *(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c);
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 10 & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return ((uVar3 >> 5 & 1) + 1) * *(int *)(vtxCompSize + (uVar3 >> 4 & 0x1c));
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
    break;
  case 0x13:
    uVar3 = *(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c);
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 0xc & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return ((uVar3 >> 0xe & 1) + 1) * *(int *)(vtxCompSize + (uVar3 >> 0xd & 0x1c));
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
    break;
  case 0x14:
    uVar3 = *(uint *)(iRam00000000 + (param_1 & 0xff) * 4 + 0x1c);
    uVar1 = *(uint *)(iRam00000000 + 0x18) >> 0xe & 3;
    if (uVar1 == 2) {
      return 1;
    }
    if (uVar1 < 2) {
      if (uVar1 != 0) {
        return ((uVar3 >> 0x17 & 1) + 1) * *(int *)(vtxCompSize + (uVar3 >> 0x16 & 0x1c));
      }
      return 0;
    }
    if (uVar1 < 4) {
      return 2;
    }
  }
  return 0;
}

void __ParseVertexData(undefined param_1)
{
  char cVar2;
  int iVar1;
  int iVar3;
  int iVar4;
  ushort local_e [3];
  
  cVar2 = __ReadMem(local_e,2);
  if (cVar2 != '\0') {
    iVar3 = 0;
    for (iVar4 = 0; iVar4 < 0x1a; iVar4 = iVar4 + 1) {
      if (iVar4 != 0x19) {
        iVar1 = GetAttrSize(param_1,iVar4);
        iVar3 = iVar3 + iVar1;
      }
    }
    dlist = dlist + iVar3 * (uint)local_e[0];
    bytesRead = bytesRead + iVar3 * (uint)local_e[0];
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXShadowDispList(undefined4 param_1,uint param_2)
{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  byte local_30 [4];
  code *local_2c;
  uint local_28;
  byte local_24 [4];
  
  if (ppcRam00000000[1] == (code *)0x0) {
    return;
  }
  bytesRead = 0;
  dlist = param_1;
  dlistSize = param_2;
  DPF(@207);
  do {
    if ((dlistSize <= bytesRead) || (cVar2 = __ReadMem(local_24,1), cVar2 == '\0')) {
      DPF(@213);
      return;
    }
    bVar1 = local_24[0] >> 3;
    bVar5 = local_24[0] & 7;
    switch(bVar1) {
    case 0:
    case 9:
      break;
    case 1:
      cVar2 = __ReadMem(local_30,1);
      if ((cVar2 != '\0') && (cVar2 = __ReadMem(&local_2c,4), cVar2 != '\0')) {
        __SaveCPRegs(local_30[0] >> 4,local_30[0] & 0xf,local_2c);
      }
      break;
    case 2:
      cVar2 = __ReadMem(&local_28,4);
      if (cVar2 != '\0') {
        uVar3 = (local_28 >> 0x10 & 0xf) + 1;
        uVar6 = local_28 & 0xffff;
        DPF(@208,uVar6,uVar3);
        for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + 1) {
          cVar2 = __ReadMem(&local_2c,4);
          if (cVar2 != '\0') {
            DPF(@209,local_2c);
            if (uVar6 < 0x400) {
              ppcRam00000000[uVar6 + 0x52] = local_2c;
              *(undefined *)((int)ppcRam00000000 + uVar6 + 0x1118) = 1;
            }
            else if (uVar6 < 0x500) {
              ppcRam00000000[uVar6 - 0x2ae] = local_2c;
              *(undefined *)((int)ppcRam00000000 + uVar6 + 0xe18) = 1;
            }
            else if (uVar6 < 0x600) {
              ppcRam00000000[uVar6 - 0x34e] = local_2c;
              *(undefined *)((int)ppcRam00000000 + uVar6 + 0xd78) = 1;
            }
            else if (uVar6 < 0x680) {
              ppcRam00000000[uVar6 - 0x34e] = local_2c;
              *(undefined *)((int)ppcRam00000000 + uVar6 + 0xd78) = 1;
            }
            else if ((-1 < (int)(uVar6 - 0x1000)) && ((int)(uVar6 - 0x1000) < 0x50)) {
              ppcRam00000000[uVar6 - 0xffe] = local_2c;
              *(undefined *)((int)ppcRam00000000 + uVar6 + 200) = 1;
            }
            uVar6 = uVar6 + 1;
          }
        }
      }
      break;
    default:
      if (_DAT_000121c4 <= (int)ppcRam00000000[1]) {
        (**ppcRam00000000)(_DAT_000121c4,0x71,_DAT_000121c8);
      }
      OSReport(@212,bVar1);
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      cVar2 = __ReadMem(&local_28,4);
      if (cVar2 != '\0') {
        DPF(@210,local_28);
        __GXShadowIndexState(bVar1,local_28);
      }
      break;
    case 8:
      if ((int)ppcRam00000000[1] < _DAT_000121c8) {
        return;
      }
      (**ppcRam00000000)(_DAT_000121c8,0x72,_DAT_000121cc);
      return;
    case 0xc:
    case 0xd:
      cVar2 = __ReadMem(&local_28,4);
      if (cVar2 != '\0') {
        DPF(@211,local_28);
        *(uint *)((int)ppcRam00000000 + (local_28 >> 0x16 & 0x3fc) + 0xcc8) = local_28;
      }
      break;
    case 0x10:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
      __ReconstVtxStatus(bVar5);
      __GXVerifyState(bVar5);
      __ParseVertexData(bVar5);
    }
  } while( true );
}

void __GXShadowIndexState(int param_1,uint param_2)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = OSPhysicalToCached(*(undefined4 *)(iRam00000000 + (param_1 + -4) * 4 + 0x88));
  iVar4 = *(int *)(iRam00000000 + (param_1 + -4) * 4 + 0x98);
  uVar6 = param_2 & 0xfff;
  puVar5 = (undefined4 *)(iVar3 + (param_2 >> 0x10) * iVar4);
  iVar3 = (param_2 >> 0xc & 0xf) + 1;
  while (bVar1 = iVar3 != 0, iVar3 = iVar3 + -1, bVar1) {
    uVar2 = *puVar5;
    if (uVar6 < 0x400) {
      *(undefined4 *)(iRam00000000 + uVar6 * 4 + 0x148) = uVar2;
      *(undefined *)(iRam00000000 + uVar6 + 0x1118) = 1;
    }
    else if (uVar6 < 0x500) {
      *(undefined4 *)(iRam00000000 + (uVar6 - 0x400) * 4 + 0x548) = uVar2;
      *(undefined *)(iRam00000000 + uVar6 + 0xe18) = 1;
    }
    else if (uVar6 < 0x600) {
      *(undefined4 *)(iRam00000000 + (uVar6 - 0x500) * 4 + 0x6c8) = uVar2;
      *(undefined *)(iRam00000000 + uVar6 + 0xd78) = 1;
    }
    else if (uVar6 < 0x680) {
      *(undefined4 *)(iRam00000000 + (uVar6 - 0x600) * 4 + 0xac8) = uVar2;
      *(undefined *)(iRam00000000 + uVar6 + 0xd78) = 1;
    }
    else {
      iVar7 = uVar6 - 0x1000;
      if ((-1 < iVar7) && (iVar7 < 0x50)) {
        *(undefined4 *)(iRam00000000 + iVar7 * 4 + 8) = uVar2;
        *(undefined *)(iRam00000000 + uVar6 + 200) = 1;
      }
    }
    puVar5 = (undefined4 *)((int)puVar5 + iVar4);
    uVar6 = uVar6 + 1;
  }
  return;
}

void __GXPrintShadowState(void)
{
  uint uVar1;
  uint uVar2;
  
  OSReport(@284);
  OSReport(@285,*(undefined4 *)(iRam00000000 + 0x14));
  OSReport(@286,*(undefined4 *)(iRam00000000 + 0x18));
  OSReport(@287,*(undefined *)(iRam00000000 + 0x41d));
  for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
    OSReport(@288,uVar2);
    OSReport(@289,*(undefined4 *)(iRam00000000 + uVar2 * 4 + 0x1c));
    OSReport(@290,*(undefined4 *)(iRam00000000 + uVar2 * 4 + 0x3c));
    OSReport(@291,*(undefined4 *)(iRam00000000 + uVar2 * 4 + 0x5c));
  }
  OSReport(@292);
  OSReport(@293);
  for (uVar2 = 0; uVar2 < 0x100; uVar2 = uVar2 + 4) {
    if (*(char *)(iRam00000000 + uVar2 + 0x1118) != '\0') {
      OSReport(@294,uVar2);
      OSReport((double)*(float *)(iRam00000000 + uVar2 * 4 + 0x148),
               (double)*(float *)(iRam00000000 + (uVar2 + 1) * 4 + 0x148),
               (double)*(float *)(iRam00000000 + (uVar2 + 2) * 4 + 0x148),
               (double)*(float *)(iRam00000000 + (uVar2 + 3) * 4 + 0x148),@295);
    }
  }
  OSReport(@292);
  OSReport(@296);
  for (uVar2 = 0; uVar2 < 0x60; uVar2 = uVar2 + 3) {
    if (*(char *)(iRam00000000 + uVar2 + 0x1218) != '\0') {
      OSReport(@297,uVar2);
      OSReport((double)*(float *)(iRam00000000 + uVar2 * 4 + 0x148),
               (double)*(float *)(iRam00000000 + (uVar2 + 1) * 4 + 0x148),
               (double)*(float *)(iRam00000000 + (uVar2 + 2) * 4 + 0x148),@298);
    }
  }
  OSReport(@292);
  OSReport(@299);
  for (uVar2 = 0; uVar2 < 0x80; uVar2 = uVar2 + 0x10) {
    if (*(char *)(iRam00000000 + uVar2 + 0x1378) != '\0') {
      OSReport(@300,uVar2 >> 4);
      for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1) {
        OSReport(@301,uVar1,*(undefined4 *)(iRam00000000 + (uVar2 + uVar1) * 4 + 0xac8));
      }
      for (uVar1 = 4; uVar1 < 0x10; uVar1 = uVar1 + 1) {
        OSReport((double)*(float *)(iRam00000000 + (uVar2 + uVar1) * 4 + 0xac8),@302,uVar1);
      }
    }
  }
  OSReport(@292);
  OSReport(@303);
  for (uVar2 = 0; uVar2 < 0x50; uVar2 = uVar2 + 1) {
    if (*(char *)(iRam00000000 + uVar2 + 0x10c8) != '\0') {
      OSReport((double)*(float *)(iRam00000000 + uVar2 * 4 + 8),@304,uVar2,
               *(undefined4 *)(iRam00000000 + uVar2 * 4 + 8));
    }
  }
  OSReport(@292);
  OSReport(@305);
  for (uVar2 = 0; uVar2 < 0x100; uVar2 = uVar2 + 1) {
    OSReport(@306,uVar2,*(undefined4 *)(iRam00000000 + uVar2 * 4 + 0xcc8));
  }
  OSReport(@292);
  return;
}
