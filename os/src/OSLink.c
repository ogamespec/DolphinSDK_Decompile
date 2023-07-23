void OSNotifyLink(void)
{
  return;
}

void OSNotifyUnlink(void)
{
  return;
}

void OSSetStringTable(undefined4 param_1)
{
  _DAT_800030d0 = param_1;
  return;
}

undefined4 Relocate(int *param_1,int param_2)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  uint *puVar6;
  uint *unaff_r28;
  ushort *puVar7;
  
  if (param_1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *param_1;
  }
  piVar4 = *(int **)(param_2 + 0x28);
  while( true ) {
    if ((int *)(*(int *)(param_2 + 0x28) + *(int *)(param_2 + 0x2c)) <= piVar4) {
      return 0;
    }
    if (*piVar4 == iVar3) break;
    piVar4 = piVar4 + 2;
  }
  puVar7 = (ushort *)piVar4[1];
  puVar6 = (uint *)0x0;
  do {
    if (*(char *)(puVar7 + 1) == -0x35) {
      if (puVar6 != (uint *)0x0) {
        uVar2 = *puVar6;
        DCFlushRange(uVar2 & 0xfffffffe,puVar6[1]);
        ICInvalidateRange(uVar2 & 0xfffffffe,puVar6[1]);
      }
      return 1;
    }
    unaff_r28 = (uint *)((int)unaff_r28 + (uint)*puVar7);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(param_1[4] + (uint)*(byte *)((int)puVar7 + 3) * 8) & 0xfffffffe;
    }
    bVar1 = *(byte *)(puVar7 + 1);
    puVar5 = puVar6;
    if (bVar1 == 6) {
      *(ushort *)unaff_r28 =
           (short)(uVar2 + *(int *)(puVar7 + 2) >> 0x10) +
           (ushort)((uVar2 + *(int *)(puVar7 + 2) & 0x8000) != 0);
    }
    else if (bVar1 < 6) {
      if (bVar1 == 2) {
        *unaff_r28 = uVar2 + *(int *)(puVar7 + 2) & 0x3fffffc | *unaff_r28 & 0xfc000003;
      }
      else if (bVar1 < 2) {
        if (bVar1 != 0) {
          *unaff_r28 = uVar2 + *(int *)(puVar7 + 2);
        }
      }
      else if (bVar1 == 4) {
        *(short *)unaff_r28 = (short)uVar2 + (short)*(undefined4 *)(puVar7 + 2);
      }
      else if (bVar1 < 4) {
        *(short *)unaff_r28 = (short)uVar2 + (short)*(undefined4 *)(puVar7 + 2);
      }
      else {
        *(short *)unaff_r28 = (short)(uVar2 + *(int *)(puVar7 + 2) >> 0x10);
      }
    }
    else if (bVar1 != 0xc9) {
      if (bVar1 < 0xc9) {
        if (bVar1 == 10) {
          *unaff_r28 = (uVar2 + *(int *)(puVar7 + 2)) - (int)unaff_r28 & 0x3fffffc |
                       *unaff_r28 & 0xfc000003;
        }
        else {
LAB_00010218:
          OSReport(...data.0,*(undefined *)(puVar7 + 1));
        }
      }
      else {
        if (0xca < bVar1) goto LAB_00010218;
        puVar5 = (uint *)(*(int *)(param_2 + 0x10) + (uint)*(byte *)((int)puVar7 + 3) * 8);
        unaff_r28 = (uint *)(*puVar5 & 0xfffffffe);
        if (puVar6 != (uint *)0x0) {
          uVar2 = *puVar6;
          DCFlushRange(uVar2 & 0xfffffffe,puVar6[1]);
          ICInvalidateRange(uVar2 & 0xfffffffe,puVar6[1]);
        }
        if ((*puVar5 & 1) == 0) {
          puVar5 = (uint *)0x0;
        }
      }
    }
    puVar7 = puVar7 + 4;
    puVar6 = puVar5;
  } while( true );
}

undefined4 OSLink(uint param_1,void *param_2)
{
  undefined4 uVar1;
  uint uVar2;
  void **ppvVar3;
  
  if (2 < *(uint *)(param_1 + 0x1c)) {
    OSPanic(@83,0xf8,@84);
  }
  if (((1 < *(uint *)(param_1 + 0x1c)) && (*(int *)(param_1 + 0x40) != 0)) &&
     (param_1 != (param_1 / *(uint *)(param_1 + 0x40)) * *(uint *)(param_1 + 0x40))) {
    OSPanic(@83,0xff,@85);
  }
  if (((1 < *(uint *)(param_1 + 0x1c)) && (*(int *)(param_1 + 0x44) != 0)) &&
     (param_2 != (void *)(((uint)param_2 / *(uint *)(param_1 + 0x44)) * *(uint *)(param_1 + 0x44))))
  {
    OSPanic(@83,0x102,@86);
  }
  if ((*(uint *)(param_1 + 0x1c) < 3) &&
     ((*(uint *)(param_1 + 0x1c) < 2 ||
      (((*(int *)(param_1 + 0x40) == 0 ||
        (param_1 == (param_1 / *(uint *)(param_1 + 0x40)) * *(uint *)(param_1 + 0x40))) &&
       ((*(int *)(param_1 + 0x44) == 0 ||
        (param_2 ==
         (void *)(((uint)param_2 / *(uint *)(param_1 + 0x44)) * *(uint *)(param_1 + 0x44)))))))))) {
    uVar2 = param_1;
    if (_DAT_800030cc != 0) {
      *(uint *)(_DAT_800030cc + 4) = param_1;
      uVar2 = _DAT_800030c8;
    }
    _DAT_800030c8 = uVar2;
    *(uint *)(param_1 + 8) = _DAT_800030cc;
    *(undefined4 *)(param_1 + 4) = 0;
    _DAT_800030cc = param_1;
    memset(param_2,0,*(size_t *)(param_1 + 0x20));
    *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + param_1;
    *(uint *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + param_1;
    for (uVar2 = 0; uVar2 < *(uint *)(param_1 + 0xc); uVar2 = uVar2 + 1) {
      ppvVar3 = (void **)(*(int *)(param_1 + 0x10) + uVar2 * 8);
      if (*ppvVar3 == (void *)0x0) {
        if (ppvVar3[1] != (void *)0x0) {
          *ppvVar3 = param_2;
          param_2 = (void *)((int)param_2 + (int)ppvVar3[1]);
        }
      }
      else {
        *ppvVar3 = (void *)((int)*ppvVar3 + param_1);
      }
    }
    for (uVar2 = *(uint *)(param_1 + 0x28);
        uVar2 < (uint)(*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x2c)); uVar2 = uVar2 + 8) {
      *(uint *)(uVar2 + 4) = *(int *)(uVar2 + 4) + param_1;
    }
    if (*(char *)(param_1 + 0x30) != '\0') {
      *(uint *)(param_1 + 0x34) =
           *(int *)(param_1 + 0x34) +
           (*(uint *)(*(int *)(param_1 + 0x10) + (uint)*(byte *)(param_1 + 0x30) * 8) & 0xfffffffe);
    }
    if (*(char *)(param_1 + 0x31) != '\0') {
      *(uint *)(param_1 + 0x38) =
           *(int *)(param_1 + 0x38) +
           (*(uint *)(*(int *)(param_1 + 0x10) + (uint)*(byte *)(param_1 + 0x31) * 8) & 0xfffffffe);
    }
    if (*(char *)(param_1 + 0x32) != '\0') {
      *(uint *)(param_1 + 0x3c) =
           *(int *)(param_1 + 0x3c) +
           (*(uint *)(*(int *)(param_1 + 0x10) + (uint)*(byte *)(param_1 + 0x32) * 8) & 0xfffffffe);
    }
    if (_DAT_800030d0 != 0) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + _DAT_800030d0;
    }
    Relocate(0,param_1);
    for (uVar2 = _DAT_800030c8; uVar2 != 0; uVar2 = *(uint *)(uVar2 + 4)) {
      Relocate(param_1,uVar2);
      if (uVar2 != param_1) {
        Relocate(uVar2,param_1);
      }
    }
    OSNotifyLink();
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

undefined4 Undo(int *param_1,int param_2)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  ushort *puVar6;
  uint *puVar7;
  uint *unaff_r31;
  
  if (param_1 == (int *)0x0) {
    OSPanic(@83,0x164,@119);
  }
  iVar3 = *param_1;
  if (iVar3 == 0) {
    OSPanic(@83,0x166,@120);
  }
  piVar4 = *(int **)(param_2 + 0x28);
  while( true ) {
    if ((int *)(*(int *)(param_2 + 0x28) + *(int *)(param_2 + 0x2c)) <= piVar4) {
      return 0;
    }
    if (*piVar4 == iVar3) break;
    piVar4 = piVar4 + 2;
  }
  puVar6 = (ushort *)piVar4[1];
  puVar7 = (uint *)0x0;
  do {
    if (*(char *)(puVar6 + 1) == -0x35) {
      if (puVar7 != (uint *)0x0) {
        uVar2 = *puVar7;
        DCFlushRange(uVar2 & 0xfffffffe,puVar7[1]);
        ICInvalidateRange(uVar2 & 0xfffffffe,puVar7[1]);
      }
      return 1;
    }
    unaff_r31 = (uint *)((int)unaff_r31 + (uint)*puVar6);
    uVar2 = 0;
    bVar1 = *(byte *)(puVar6 + 1);
    puVar5 = puVar7;
    if (bVar1 == 6) {
      *(undefined2 *)unaff_r31 = 0;
    }
    else if (bVar1 < 6) {
      if (bVar1 == 2) {
        *unaff_r31 = *unaff_r31 & 0xfc000003;
      }
      else if (bVar1 < 2) {
        if (bVar1 != 0) {
          *unaff_r31 = 0;
        }
      }
      else if (bVar1 == 4) {
        *(undefined2 *)unaff_r31 = 0;
      }
      else if (bVar1 < 4) {
        *(undefined2 *)unaff_r31 = 0;
      }
      else {
        *(undefined2 *)unaff_r31 = 0;
      }
    }
    else if (bVar1 != 0xc9) {
      if (bVar1 < 0xc9) {
        if (bVar1 == 10) {
          if (*(char *)(param_2 + 0x32) != '\0') {
            uVar2 = *(int *)(param_2 + 0x3c) - (int)unaff_r31;
          }
          *unaff_r31 = uVar2 & 0x3fffffc | *unaff_r31 & 0xfc000003;
        }
        else {
LAB_00010790:
          OSReport(@121,*(undefined *)(puVar6 + 1));
        }
      }
      else {
        if (0xca < bVar1) goto LAB_00010790;
        puVar5 = (uint *)(*(int *)(param_2 + 0x10) + (uint)*(byte *)((int)puVar6 + 3) * 8);
        unaff_r31 = (uint *)(*puVar5 & 0xfffffffe);
        if (puVar7 != (uint *)0x0) {
          uVar2 = *puVar7;
          DCFlushRange(uVar2 & 0xfffffffe,puVar7[1]);
          ICInvalidateRange(uVar2 & 0xfffffffe,puVar7[1]);
        }
        if ((*puVar5 & 1) == 0) {
          puVar5 = (uint *)0x0;
        }
      }
    }
    puVar6 = puVar6 + 4;
    puVar7 = puVar5;
  } while( true );
}

undefined4 OSUnlink(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (2 < *(uint *)(param_1 + 0x1c)) {
    OSPanic(@83,0x1c7,@138);
  }
  iVar3 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = iVar2;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 8) = iVar2;
    iVar1 = _DAT_800030cc;
  }
  _DAT_800030cc = iVar1;
  iVar1 = iVar3;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 4) = iVar3;
    iVar3 = _DAT_800030c8;
    iVar1 = _DAT_800030c8;
  }
  for (; _DAT_800030c8 = iVar1, iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    Undo(param_1,iVar3);
    iVar1 = _DAT_800030c8;
  }
  OSNotifyUnlink();
  return 1;
}

void __OSModuleInit(void)
{
  _DAT_800030cc = 0;
  _DAT_800030c8 = 0;
  _DAT_800030d0 = 0;
  return;
}

int OSSearchModule(uint param_1,uint *param_2,int *param_3)
{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = _DAT_800030c8;
  if (param_1 != 0) {
    for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
      puVar3 = *(uint **)(iVar4 + 0x10);
      for (uVar2 = 0; uVar2 < *(uint *)(iVar4 + 0xc); uVar2 = uVar2 + 1) {
        if (((puVar3[1] != 0) && (uVar1 = *puVar3 & 0xfffffffe, uVar1 <= param_1)) &&
           (param_1 < uVar1 + puVar3[1])) {
          if (param_2 != (uint *)0x0) {
            *param_2 = uVar2;
          }
          if (param_3 != (int *)0x0) {
            *param_3 = param_1 - uVar1;
            return iVar4;
          }
          return iVar4;
        }
        puVar3 = puVar3 + 2;
      }
    }
  }
  return 0;
}
