void OSInitStopwatch(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[7] = 0xffffffff;
  param_1[6] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  return;
}

void OSStartStopwatch(int param_1)
{
  undefined8 uVar1;
  
  *(undefined4 *)(param_1 + 0x30) = 1;
  uVar1 = OSGetTime();
  *(undefined8 *)(param_1 + 0x28) = uVar1;
  return;
}

void OSStopStopwatch(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  if (*(int *)(param_1 + 0x30) != 0) {
    uVar4 = OSGetTime();
    uVar3 = (uint)uVar4 - *(uint *)(param_1 + 0x2c);
    uVar2 = (int)((ulonglong)uVar4 >> 0x20) -
            (*(int *)(param_1 + 0x28) + (uint)((uint)uVar4 < *(uint *)(param_1 + 0x2c)));
    uVar1 = *(uint *)(param_1 + 0xc);
    *(uint *)(param_1 + 0xc) = uVar1 + uVar3;
    *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar2 + (uint)CARRY4(uVar1,uVar3);
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    uVar1 = *(uint *)(param_1 + 0x20) ^ 0x80000000;
    if (uVar1 < (uVar2 ^ 0x80000000) ||
        uVar1 - (uVar2 ^ 0x80000000) < (uint)(*(uint *)(param_1 + 0x24) < uVar3)) {
      *(uint *)(param_1 + 0x24) = uVar3;
      *(uint *)(param_1 + 0x20) = uVar2;
    }
    uVar1 = *(uint *)(param_1 + 0x18) ^ 0x80000000;
    if ((uVar2 ^ 0x80000000) < uVar1 ||
        (uVar2 ^ 0x80000000) - uVar1 < (uint)(uVar3 < *(uint *)(param_1 + 0x1c))) {
      *(uint *)(param_1 + 0x1c) = uVar3;
      *(uint *)(param_1 + 0x18) = uVar2;
    }
  }
  return;
}

undefined8 OSCheckStopwatch(int param_1)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined8 uVar5;
  
  iVar2 = *(int *)(param_1 + 8);
  uVar3 = *(uint *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0x30) != 0) {
    uVar5 = OSGetTime();
    uVar1 = (uint)uVar5 - *(uint *)(param_1 + 0x2c);
    bVar4 = CARRY4(uVar3,uVar1);
    uVar3 = uVar3 + uVar1;
    iVar2 = iVar2 + ((int)((ulonglong)uVar5 >> 0x20) -
                    (*(int *)(param_1 + 0x28) + (uint)((uint)uVar5 < *(uint *)(param_1 + 0x2c)))) +
            (uint)bVar4;
  }
  return CONCAT44(iVar2,uVar3);
}

void OSResetStopwatch(undefined4 *param_1)
{
  OSInitStopwatch(param_1,*param_1);
  return;
}

void OSDumpStopwatch(undefined4 *param_1)
{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  OSReport(...data.0,*param_1);
  uVar2 = __div2i(param_1[2] * 8 + (int)((ulonglong)(uint)param_1[3] * 8 >> 0x20),param_1[3] * 8,0,
                  _DAT_800000f8 / 500000);
  OSReport(@16,(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar2);
  OSReport(@17,param_1[4]);
  uVar2 = __div2i(param_1[6] * 8 + (int)((ulonglong)(uint)param_1[7] * 8 >> 0x20),param_1[7] * 8,0,
                  _DAT_800000f8 / 500000);
  OSReport(@18,(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar2);
  uVar2 = __div2i(param_1[8] * 8 + (int)((ulonglong)(uint)param_1[9] * 8 >> 0x20),param_1[9] * 8,0,
                  _DAT_800000f8 / 500000);
  OSReport(@19,(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar2);
  uVar1 = _DAT_800000f8 / 500000;
  lVar3 = __div2i(param_1[2],param_1[3],0,param_1[4]);
  uVar2 = __div2i((int)((ulonglong)(lVar3 * 8) >> 0x20),(int)(lVar3 * 8),0,uVar1);
  OSReport(@20,(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar2);
  return;
}
