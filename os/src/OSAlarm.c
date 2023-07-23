undefined4 OSCheckAlarmQueue(void)
{
  undefined4 uVar1;
  int iVar2;
  
  if (((AlarmQueue._0_4_ == 0) && (AlarmQueue._4_4_ == 0)) ||
     ((AlarmQueue._0_4_ != 0 && (AlarmQueue._4_4_ != 0)))) {
    if ((AlarmQueue._0_4_ == 0) || (*(int *)(AlarmQueue._0_4_ + 0x10) == 0)) {
      iVar2 = AlarmQueue._0_4_;
      if ((AlarmQueue._4_4_ == 0) || (*(int *)(AlarmQueue._4_4_ + 0x14) == 0)) {
        for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
          if ((*(int *)(iVar2 + 0x14) != 0) && (*(int *)(*(int *)(iVar2 + 0x14) + 0x10) != iVar2)) {
            OSReport(@47,0x7c);
            return 0;
          }
          if ((*(int *)(iVar2 + 0x14) == 0) && (AlarmQueue._4_4_ != iVar2)) {
            OSReport(@48,0x7d);
            return 0;
          }
        }
        uVar1 = 1;
      }
      else {
        OSReport(@46,0x79);
        uVar1 = 0;
      }
    }
    else {
      OSReport(@45,0x78);
      uVar1 = 0;
    }
  }
  else {
    OSReport(...data.0,0x77);
    uVar1 = 0;
  }
  return uVar1;
}

void SetTimer(int param_1)
{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar3 = __OSGetSystemTime();
  uVar2 = *(uint *)(param_1 + 0xc) - (uint)uVar3;
  uVar1 = *(int *)(param_1 + 8) -
          ((int)((ulonglong)uVar3 >> 0x20) + (uint)(*(uint *)(param_1 + 0xc) < (uint)uVar3));
  if ((uVar1 ^ 0x80000000) < 0x80000000) {
    PPCMtdec(0);
  }
  else {
    uVar1 = uVar1 ^ 0x80000000;
    if (uVar1 < 0x80000000 || uVar1 + 0x80000000 < (uint)(uVar2 < 0x80000000)) {
      PPCMtdec(uVar2);
    }
    else {
      PPCMtdec(0x7fffffff);
    }
  }
  return;
}

void OSInitAlarm(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)__OSGetExceptionHandler(8);
  if (pcVar1 != DecrementerExceptionHandler) {
    AlarmQueue._4_4_ = 0;
    AlarmQueue._0_4_ = 0;
    __OSSetExceptionHandler(8,DecrementerExceptionHandler);
  }
  return;
}

void OSCreateAlarm(undefined4 *param_1)
{
  *param_1 = 0;
  return;
}

void InsertAlarm(int *param_1,undefined4 param_2,uint param_3,uint param_4,int param_5)
{
  ulonglong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  bool bVar7;
  undefined8 uVar8;
  longlong lVar9;
  
  if (0x80000000 < (param_1[6] ^ 0x80000000U) ||
      0x80000000 - (param_1[6] ^ 0x80000000U) < (uint)(param_1[7] != 0)) {
    uVar8 = __OSGetSystemTime();
    uVar4 = (uint)((ulonglong)uVar8 >> 0x20);
    uVar5 = (uint)uVar8;
    param_3 = param_1[8];
    param_4 = param_1[9];
    uVar3 = uVar4 ^ 0x80000000;
    if ((param_1[8] ^ 0x80000000U) < uVar3 ||
        (param_1[8] ^ 0x80000000U) - uVar3 < (uint)((uint)param_1[9] < uVar5)) {
      lVar9 = __div2i(uVar4 - (param_1[8] + (uint)(uVar5 < (uint)param_1[9])),uVar5 - param_1[9],
                      param_1[6],param_1[7]);
      uVar1 = lVar9 + 1;
      uVar4 = param_1[7];
      uVar3 = uVar4 * (int)uVar1;
      bVar7 = CARRY4(param_4,uVar3);
      param_4 = param_4 + uVar3;
      param_3 = param_3 + param_1[6] * (int)uVar1 +
                          (int)((ulonglong)uVar4 * (uVar1 & 0xffffffff) >> 0x20) +
                          uVar4 * (int)(uVar1 >> 0x20) + (uint)bVar7;
    }
  }
  if (*param_1 != 0) {
    OSPanic(@78,0xdd,@79);
  }
  *param_1 = param_5;
  param_1[3] = param_4;
  param_1[2] = param_3;
  piVar6 = AlarmQueue._0_4_;
  while( true ) {
    if (piVar6 == (int *)0x0) {
      param_1[5] = 0;
      iVar2 = (int)AlarmQueue._4_4_;
      piVar6 = param_1;
      param_1[4] = (int)AlarmQueue._4_4_;
      AlarmQueue._4_4_ = piVar6;
      if (iVar2 == 0) {
        AlarmQueue._0_4_ = param_1;
        AlarmQueue._4_4_ = param_1;
        SetTimer(param_1);
      }
      else {
        *(int **)(iVar2 + 0x14) = param_1;
      }
      return;
    }
    if ((param_3 ^ 0x80000000) < (piVar6[2] ^ 0x80000000U) ||
        (param_3 ^ 0x80000000) - (piVar6[2] ^ 0x80000000U) < (uint)(param_4 < (uint)piVar6[3]))
    break;
    piVar6 = (int *)piVar6[5];
  }
  param_1[4] = piVar6[4];
  piVar6[4] = (int)param_1;
  param_1[5] = (int)piVar6;
  if (param_1[4] != 0) {
    *(int **)(param_1[4] + 0x14) = param_1;
    return;
  }
  AlarmQueue._0_4_ = param_1;
  SetTimer(param_1);
  return;
}

void OSSetAlarm(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5)
{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  
  if ((param_3 ^ 0x80000000) < 0x80000001 &&
      (uint)(param_4 != 0) <= 0x80000000 - (param_3 ^ 0x80000000)) {
    OSPanic(@78,0x11b,@82);
  }
  if (param_5 == 0) {
    OSPanic(@78,0x11c,@83);
  }
  uVar2 = OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  lVar4 = __OSGetSystemTime();
  lVar1 = lVar4 + CONCAT44(param_3,param_4);
  InsertAlarm(param_1,(int)lVar4,(int)((ulonglong)lVar1 >> 0x20),(int)lVar1,param_5);
  iVar3 = OSCheckAlarmQueue();
  if (iVar3 == 0) {
    OSPanic(@78,0x123,@84);
  }
  OSRestoreInterrupts(uVar2);
  return;
}

void OSSetAbsAlarm(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_5 == 0) {
    OSPanic(@78,0x139,@86);
  }
  uVar1 = OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  uVar3 = __OSTimeToSystemTime(param_3,param_4);
  InsertAlarm(param_1,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3,param_5);
  iVar2 = OSCheckAlarmQueue();
  if (iVar2 == 0) {
    OSPanic(@78,0x140,@84);
  }
  OSRestoreInterrupts(uVar1);
  return;
}

void OSSetPeriodicAlarm(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       uint param_5,int param_6,int param_7)
{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((param_5 ^ 0x80000000) < 0x80000001 &&
      (uint)(param_6 != 0) <= 0x80000000 - (param_5 ^ 0x80000000)) {
    OSPanic(@78,0x158,@88);
  }
  if (param_7 == 0) {
    OSPanic(@78,0x159,@89);
  }
  uVar1 = OSDisableInterrupts();
  *(int *)(param_1 + 0x1c) = param_6;
  *(uint *)(param_1 + 0x18) = param_5;
  uVar3 = __OSTimeToSystemTime(param_3,param_4);
  *(undefined8 *)(param_1 + 0x20) = uVar3;
  InsertAlarm(param_1,(int)uVar3,0,0,param_7);
  iVar2 = OSCheckAlarmQueue();
  if (iVar2 == 0) {
    OSPanic(@78,0x161,@84);
  }
  OSRestoreInterrupts(uVar1);
  return;
}

void OSCancelAlarm(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = OSDisableInterrupts();
  if (*param_1 == 0) {
    OSRestoreInterrupts(uVar1);
  }
  else {
    iVar2 = param_1[5];
    if (iVar2 == 0) {
      AlarmQueue._4_4_ = param_1[4];
    }
    else {
      *(int *)(iVar2 + 0x10) = param_1[4];
    }
    if (param_1[4] == 0) {
      AlarmQueue._0_4_ = iVar2;
      if (iVar2 != 0) {
        SetTimer(iVar2);
      }
    }
    else {
      *(int *)(param_1[4] + 0x14) = iVar2;
    }
    *param_1 = 0;
    iVar2 = OSCheckAlarmQueue();
    if (iVar2 == 0) {
      OSPanic(@78,0x194,@84);
    }
    OSRestoreInterrupts(uVar1);
  }
  return;
}

void DecrementerExceptionCallback(undefined4 param_1,undefined4 param_2)
{
  code **ppcVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined auStack_2e8 [716];
  
  uVar5 = __OSGetSystemTime();
  ppcVar1 = AlarmQueue._0_4_;
  if (AlarmQueue._0_4_ == (code **)0x0) {
    OSLoadContext(param_2);
  }
  uVar3 = (uint)((ulonglong)uVar5 >> 0x20) ^ 0x80000000;
  if (uVar3 < ((uint)ppcVar1[2] ^ 0x80000000) ||
      uVar3 - ((uint)ppcVar1[2] ^ 0x80000000) < (uint)((code *)uVar5 < ppcVar1[3])) {
    SetTimer(ppcVar1);
    OSLoadContext(param_2);
  }
  AlarmQueue._0_4_ = (code **)ppcVar1[5];
  if (AlarmQueue._0_4_ == (code **)0x0) {
    AlarmQueue._4_4_ = 0;
  }
  else {
    *(undefined4 *)((int)AlarmQueue._0_4_ + 0x10) = 0;
  }
  iVar2 = OSCheckAlarmQueue();
  if (iVar2 == 0) {
    OSPanic(@78,0x1ce,@84);
  }
  pcVar4 = *ppcVar1;
  *ppcVar1 = (code *)0x0;
  if (0x80000000 < ((uint)ppcVar1[6] ^ 0x80000000) ||
      0x80000000 - ((uint)ppcVar1[6] ^ 0x80000000) < (uint)(ppcVar1[7] != (code *)0x0)) {
    InsertAlarm(ppcVar1,0x80000000,0,0,pcVar4);
    iVar2 = OSCheckAlarmQueue();
    if (iVar2 == 0) {
      OSPanic(@78,0x1d8,@84);
    }
  }
  if (AlarmQueue._0_4_ != (code **)0x0) {
    SetTimer(AlarmQueue._0_4_);
  }
  OSDisableScheduler();
  OSClearContext(auStack_2e8);
  OSSetCurrentContext(auStack_2e8);
  (*pcVar4)(ppcVar1,param_2);
  OSClearContext(auStack_2e8);
  OSSetCurrentContext(param_2);
  OSEnableScheduler();
  __OSReschedule();
  OSLoadContext(param_2);
  return;
}

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DecrementerExceptionHandler()
                               assume r13 = 0x10d28
             undefined         r3:1           <RETURN>
                             DecrementerExceptionHandler                     XREF[1]:     OSInitAlarm:0001027c(*)  
        00010988 90 04 00 00     stw        r0,0x0(r4)
        0001098c 90 24 00 04     stw        r1,0x4(r4)
        00010990 90 44 00 08     stw        r2,0x8(r4)
        00010994 bc c4 00 18     stmw       r6,0x18(r4)=>AlarmQueue                          = ??
        00010998 7c 11 e2 a6     mfspr      r0,spr391
        0001099c 90 04 01 a8     stw        r0,0x1a8(r4)
        000109a0 7c 12 e2 a6     mfspr      r0,spr392
        000109a4 90 04 01 ac     stw        r0,0x1ac(r4)
        000109a8 7c 13 e2 a6     mfspr      r0,spr393
        000109ac 90 04 01 b0     stw        r0,0x1b0(r4)
        000109b0 7c 14 e2 a6     mfspr      r0,spr394
        000109b4 90 04 01 b4     stw        r0,0x1b4(r4)
        000109b8 7c 15 e2 a6     mfspr      r0,spr395
        000109bc 90 04 01 b8     stw        r0,0x1b8(r4)
        000109c0 7c 16 e2 a6     mfspr      r0,spr396
        000109c4 90 04 01 bc     stw        r0,0x1bc(r4)
        000109c8 7c 17 e2 a6     mfspr      r0,spr397
        000109cc 90 04 01 c0     stw        r0,0x1c0(r4)
        000109d0 4b ff fe 24     b          DecrementerExceptionCallback                     undefined DecrementerExceptionCa
                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
