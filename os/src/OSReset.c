void OSRegisterResetFunction(int *param_1)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = ResetFunctionQueue._0_4_;
  if (*param_1 == 0) {
    OSPanic(@25,0xa6,@26);
    piVar2 = ResetFunctionQueue._0_4_;
  }
  for (; (piVar2 != (int *)0x0 && ((uint)piVar2[1] <= (uint)param_1[1])); piVar2 = (int *)piVar2[2])
  {
  }
  if (piVar2 == (int *)0x0) {
    piVar2 = param_1;
    if (ResetFunctionQueue._4_4_ != (int *)0x0) {
      ResetFunctionQueue._4_4_[2] = (int)param_1;
      piVar2 = ResetFunctionQueue._0_4_;
    }
    ResetFunctionQueue._0_4_ = piVar2;
    param_1[3] = (int)ResetFunctionQueue._4_4_;
    param_1[2] = 0;
    piVar2 = ResetFunctionQueue._0_4_;
    ResetFunctionQueue._4_4_ = param_1;
  }
  else {
    param_1[2] = (int)piVar2;
    iVar1 = piVar2[3];
    piVar2[3] = (int)param_1;
    param_1[3] = iVar1;
    piVar2 = param_1;
    if (iVar1 != 0) {
      *(int **)(iVar1 + 8) = param_1;
      piVar2 = ResetFunctionQueue._0_4_;
    }
  }
  ResetFunctionQueue._0_4_ = piVar2;
  return;
}

void OSUnregisterResetFunction(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = iVar2;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0xc) = iVar2;
    iVar1 = ResetFunctionQueue._4_4_;
  }
  ResetFunctionQueue._4_4_ = iVar1;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 8) = iVar3;
    iVar3 = ResetFunctionQueue._0_4_;
  }
  ResetFunctionQueue._0_4_ = iVar3;
  return;
}

bool __OSCallResetFunctions(undefined4 param_1)
{
  byte bVar1;
  int iVar2;
  code **ppcVar3;
  
  bVar1 = 0;
  for (ppcVar3 = ResetFunctionQueue._0_4_; ppcVar3 != (code **)0x0; ppcVar3 = (code **)ppcVar3[2]) {
    iVar2 = (**ppcVar3)(param_1);
    bVar1 = bVar1 | iVar2 == 0;
  }
  iVar2 = __OSSyncSram();
  return !(bool)(bVar1 | iVar2 == 0);
}

void Reset(void)
{
  thunk_FUN_000101a0();
  return;
}

void FUN_000101a0(void)
{
  instructionSynchronize();
  sync(0);
  FUN_000101c0();
  return;
}

// TODO: asm...

void KillThreads(void)
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _DAT_800000dc;
  while (iVar3 = iVar2, iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 0x2fc);
    uVar1 = *(ushort *)(iVar3 + 0x2c8);
    if ((uVar1 == 4) || ((uVar1 < 4 && (uVar1 == 1)))) {
      OSCancelThread(iVar3);
    }
  }
  return;
}

void __OSDoHotReset(int param_1)
{
  OSDisableInterrupts();
  _DAT_cc002002 = 0;
  ICFlashInvalidate();
  Reset(param_1 << 3);
  return;
}

void OSResetSystem(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  void *pvVar2;
  undefined4 unaff_r29;
  
  OSDisableScheduler();
  __OSStopAudioSystem();
  if (param_1 == 2) {
    unaff_r29 = __PADDisableRecalibration(1);
  }
  do {
    iVar1 = __OSCallResetFunctions(0);
  } while (iVar1 == 0);
  if ((param_1 == 1) && (param_3 != 0)) {
    iVar1 = __OSLockSram();
    *(byte *)(iVar1 + 0x13) = *(byte *)(iVar1 + 0x13) | 0x40;
    __OSUnlockSram(1);
    do {
      iVar1 = __OSSyncSram();
    } while (iVar1 == 0);
  }
  OSDisableInterrupts();
  iVar1 = __OSCallResetFunctions(1);
  if (iVar1 == 0) {
    OSPanic(@25,0x171,@84);
  }
  LCDisable();
  if (param_1 == 1) {
    __OSDoHotReset(param_2);
  }
  else if (param_1 == 0) {
    KillThreads();
    OSEnableScheduler();
    __OSReboot(param_2,param_3);
  }
  KillThreads();
  pvVar2 = (void *)OSPhysicalToCached(0x40);
  memset(pvVar2,0,0x8c);
  pvVar2 = (void *)OSPhysicalToCached(0xd4);
  memset(pvVar2,0,0x14);
  pvVar2 = (void *)OSPhysicalToCached(0xf4);
  memset(pvVar2,0,4);
  pvVar2 = (void *)OSPhysicalToCached(0x3000);
  memset(pvVar2,0,0xc0);
  pvVar2 = (void *)OSPhysicalToCached(0x30c8);
  memset(pvVar2,0,0xc);
  __PADDisableRecalibration(unaff_r29);
  return;
}

uint OSGetResetCode(void)
{
  uint uVar1;
  
  if (DAT_800030e2 == '\0') {
    uVar1 = _DAT_cc003024 >> 3;
  }
  else {
    uVar1 = 0x80000000;
  }
  return uVar1;
}
