void __OSThreadInit(void)
{
  uint uVar1;
  int iVar2;
  
  DefaultThread._712_2_ = 2;
  DefaultThread._714_2_ = 1;
  DefaultThread._724_4_ = 0x10;
  DefaultThread._720_4_ = 0x10;
  DefaultThread._716_4_ = 0;
  DefaultThread._728_4_ = 0xffffffff;
  DefaultThread._752_4_ = 0;
  OSInitThreadQueue(0x13628);
  OSInitMutexQueue(0x13634);
  uVar1 = PPCMfmsr();
  if ((uVar1 & 0x2000) == 0) {
    OSPanic(...data.0,0x11a,@15);
  }
  _DAT_800000d8 = DefaultThread;
  OSClearContext(DefaultThread);
  OSSetCurrentContext(DefaultThread);
  DefaultThread._772_4_ = &_stack_addr;
  DefaultThread._776_4_ = &_stack_end;
  __stack_end = 0xdeadbabe;
  _DAT_800000e4 = DefaultThread;
  RunQueueBits = 0;
  RunQueueHint = 0;
  for (iVar2 = 0; iVar2 < 0x20; iVar2 = iVar2 + 1) {
    OSInitThreadQueue(RunQueue + iVar2 * 8);
  }
  OSInitThreadQueue(&DAT_800000dc);
  if (_DAT_800000e0 == (undefined1 *)0x0) {
    _DAT_800000dc = DefaultThread;
  }
  else {
    *(undefined1 **)((int)_DAT_800000e0 + 0x2fc) = DefaultThread;
  }
  DefaultThread._768_4_ = _DAT_800000e0;
  DefaultThread._764_4_ = 0;
  _DAT_800000e0 = DefaultThread;
  OSClearContext(IdleContext);
  Reschedule = 0;
  return;
}

void OSInitMutexQueue(undefined4 *param_1)
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

void OSInitThreadQueue(undefined4 *param_1)
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

undefined4 OSGetCurrentThread(void)
{
  return _DAT_800000e4;
}

void __OSSwitchThread(undefined4 param_1)
{
  _DAT_800000e4 = param_1;
  OSSetCurrentContext(param_1);
  OSLoadContext(param_1);
  return;
}

undefined4 OSIsThreadSuspended(int param_1)
{
  if (0 < *(int *)(param_1 + 0x2cc)) {
    return 1;
  }
  return 0;
}

undefined4 OSIsThreadTerminated(int param_1)
{
  if ((*(short *)(param_1 + 0x2c8) != 8) && (*(short *)(param_1 + 0x2c8) != 0)) {
    return 0;
  }
  return 1;
}

undefined4 __OSIsThreadActive(int param_1)
{
  int iVar1;
  
  iVar1 = _DAT_800000dc;
  if (*(short *)(param_1 + 0x2c8) != 0) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2fc)) {
      if (param_1 == iVar1) {
        return 1;
      }
    }
  }
  return 0;
}

int OSDisableScheduler(void)
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = OSDisableInterrupts();
  iVar1 = Reschedule;
  Reschedule = Reschedule + 1;
  OSRestoreInterrupts(uVar2);
  return iVar1;
}

int OSEnableScheduler(void)
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = OSDisableInterrupts();
  iVar1 = Reschedule;
  Reschedule = Reschedule + -1;
  OSRestoreInterrupts(uVar2);
  return iVar1;
}

void SetRun(int param_1)
{
  int iVar1;
  
  if (0 < *(int *)(param_1 + 0x2cc)) {
    OSPanic(...data.0,0x1d5,@42);
  }
  if (*(short *)(param_1 + 0x2c8) != 1) {
    OSPanic(...data.0,0x1d6,@43);
  }
  if ((*(int *)(param_1 + 0x2d0) < 0) || (0x1f < *(int *)(param_1 + 0x2d0))) {
    OSPanic(...data.0,0x1d8,@44);
  }
  *(undefined1 **)(param_1 + 0x2dc) = RunQueue + *(int *)(param_1 + 0x2d0) * 8;
  iVar1 = *(int *)(*(int *)(param_1 + 0x2dc) + 4);
  if (iVar1 == 0) {
    **(int **)(param_1 + 0x2dc) = param_1;
  }
  else {
    *(int *)(iVar1 + 0x2e0) = param_1;
  }
  *(int *)(param_1 + 0x2e4) = iVar1;
  *(undefined4 *)(param_1 + 0x2e0) = 0;
  *(int *)(*(int *)(param_1 + 0x2dc) + 4) = param_1;
  RunQueueBits = RunQueueBits | 1 << (0x1fU - *(int *)(param_1 + 0x2d0) & 0x3f);
  RunQueueHint = 1;
  return;
}

void UnsetRun(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(short *)(param_1 + 0x2c8) != 1) {
    OSPanic(...data.0,0x1ed,@43);
  }
  if ((*(int *)(param_1 + 0x2d0) < 0) || (0x1f < *(int *)(param_1 + 0x2d0))) {
    OSPanic(...data.0,0x1ef,@44);
  }
  if (*(undefined1 **)(param_1 + 0x2dc) != RunQueue + *(int *)(param_1 + 0x2d0) * 8) {
    OSPanic(...data.0,0x1f0,@58);
  }
  piVar1 = *(int **)(param_1 + 0x2dc);
  iVar3 = *(int *)(param_1 + 0x2e0);
  iVar2 = *(int *)(param_1 + 0x2e4);
  if (iVar3 == 0) {
    piVar1[1] = iVar2;
  }
  else {
    *(int *)(iVar3 + 0x2e4) = iVar2;
  }
  if (iVar2 == 0) {
    *piVar1 = iVar3;
  }
  else {
    *(int *)(iVar2 + 0x2e0) = iVar3;
  }
  if (*piVar1 == 0) {
    RunQueueBits = RunQueueBits & ~(1 << (0x1fU - *(int *)(param_1 + 0x2d0) & 0x3f));
  }
  *(undefined4 *)(param_1 + 0x2dc) = 0;
  return;
}

int __OSGetEffectivePriority(int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0x2d4);
  for (piVar3 = *(int **)(param_1 + 0x2f4); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[4]) {
    iVar1 = *piVar3;
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2d0) < iVar2)) {
      iVar2 = *(int *)(iVar1 + 0x2d0);
    }
  }
  return iVar2;
}

undefined4 SetEffectivePriority(int param_1,undefined4 param_2)
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if (0 < *(int *)(param_1 + 0x2cc)) {
    OSPanic(...data.0,0x223,@42);
  }
  uVar1 = *(ushort *)(param_1 + 0x2c8);
  if (uVar1 != 3) {
    if (uVar1 < 3) {
      if (uVar1 == 1) {
        UnsetRun(param_1);
        *(undefined4 *)(param_1 + 0x2d0) = param_2;
        SetRun(param_1);
      }
      else if (uVar1 != 0) {
        RunQueueHint = 1;
        *(undefined4 *)(param_1 + 0x2d0) = param_2;
      }
    }
    else if (uVar1 < 5) {
      iVar3 = *(int *)(param_1 + 0x2e0);
      iVar2 = *(int *)(param_1 + 0x2e4);
      if (iVar3 == 0) {
        *(int *)(*(int *)(param_1 + 0x2dc) + 4) = iVar2;
      }
      else {
        *(int *)(iVar3 + 0x2e4) = iVar2;
      }
      if (iVar2 == 0) {
        **(int **)(param_1 + 0x2dc) = iVar3;
      }
      else {
        *(int *)(iVar2 + 0x2e0) = iVar3;
      }
      *(undefined4 *)(param_1 + 0x2d0) = param_2;
      for (iVar2 = **(int **)(param_1 + 0x2dc);
          (iVar2 != 0 && (*(int *)(iVar2 + 0x2d0) <= *(int *)(param_1 + 0x2d0)));
          iVar2 = *(int *)(iVar2 + 0x2e0)) {
      }
      if (iVar2 == 0) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x2dc) + 4);
        if (iVar2 == 0) {
          **(int **)(param_1 + 0x2dc) = param_1;
        }
        else {
          *(int *)(iVar2 + 0x2e0) = param_1;
        }
        *(int *)(param_1 + 0x2e4) = iVar2;
        *(undefined4 *)(param_1 + 0x2e0) = 0;
        *(int *)(*(int *)(param_1 + 0x2dc) + 4) = param_1;
      }
      else {
        *(int *)(param_1 + 0x2e0) = iVar2;
        iVar3 = *(int *)(iVar2 + 0x2e4);
        *(int *)(iVar2 + 0x2e4) = param_1;
        *(int *)(param_1 + 0x2e4) = iVar3;
        if (iVar3 == 0) {
          **(int **)(param_1 + 0x2dc) = param_1;
        }
        else {
          *(int *)(iVar3 + 0x2e0) = param_1;
        }
      }
      if (*(int *)(param_1 + 0x2f0) != 0) {
        if (*(int *)(*(int *)(param_1 + 0x2f0) + 8) == 0) {
          OSPanic(...data.0,0x232,@108);
        }
        return *(undefined4 *)(*(int *)(param_1 + 0x2f0) + 8);
      }
    }
  }
  return 0;
}

void UpdatePriority(int param_1)
{
  int iVar1;
  
  while( true ) {
    if (0 < *(int *)(param_1 + 0x2cc)) {
      return;
    }
    iVar1 = __OSGetEffectivePriority(param_1);
    if (*(int *)(param_1 + 0x2d0) == iVar1) break;
    param_1 = SetEffectivePriority(param_1,iVar1);
    if (param_1 == 0) {
      return;
    }
  }
  return;
}

void __OSPromoteThread(int param_1,int param_2)
{
  while( true ) {
    if (0 < *(int *)(param_1 + 0x2cc)) {
      return;
    }
    if (*(int *)(param_1 + 0x2d0) <= param_2) break;
    param_1 = SetEffectivePriority(param_1,param_2);
    if (param_1 == 0) {
      return;
    }
  }
  return;
}

int SelectThread(int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  if (Reschedule < 1) {
    iVar1 = OSGetCurrentContext();
    iVar2 = OSGetCurrentThread();
    if (iVar1 == iVar2) {
      if (iVar2 != 0) {
        if (*(short *)(iVar2 + 0x2c8) == 2) {
          if ((param_1 == 0) && (*(int *)(iVar2 + 0x2d0) <= LZCOUNT(RunQueueBits))) {
            return 0;
          }
          *(undefined2 *)(iVar2 + 0x2c8) = 1;
          SetRun(iVar2);
        }
        if (((*(ushort *)(iVar2 + 0x1a2) & 2) == 0) && (iVar1 = OSSaveContext(iVar2), iVar1 != 0)) {
          return 0;
        }
      }
      _DAT_800000e4 = 0;
      if (RunQueueBits == 0) {
        OSSetCurrentContext(IdleContext);
        do {
          OSEnableInterrupts();
          do {
          } while (RunQueueBits == 0);
          OSDisableInterrupts();
        } while (RunQueueBits == 0);
        OSClearContext(IdleContext);
      }
      RunQueueHint = 0;
      uVar4 = LZCOUNT(RunQueueBits);
      if (0x1f < uVar4) {
        OSPanic(...data.0,0x2c6,@161);
      }
      piVar3 = (int *)(RunQueue + uVar4 * 8);
      iVar1 = *piVar3;
      iVar2 = *(int *)(iVar1 + 0x2e0);
      if (iVar2 == 0) {
        *(undefined4 *)(RunQueue + uVar4 * 8 + 4) = 0;
      }
      else {
        *(undefined4 *)(iVar2 + 0x2e4) = 0;
      }
      *piVar3 = iVar2;
      if (*(uint *)(iVar1 + 0x2d0) != uVar4) {
        OSPanic(...data.0,0x2c9,@162);
      }
      if (*piVar3 == 0) {
        RunQueueBits = RunQueueBits & ~(1 << (0x1f - uVar4 & 0x3f));
      }
      *(undefined4 *)(iVar1 + 0x2dc) = 0;
      *(undefined2 *)(iVar1 + 0x2c8) = 2;
      __OSSwitchThread(iVar1);
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

void __OSReschedule(void)
{
  if (RunQueueHint != 0) {
    SelectThread(0);
  }
  return;
}

void OSYieldThread(void)
{
  undefined4 uVar1;
  
  uVar1 = OSDisableInterrupts();
  SelectThread(1);
  OSRestoreInterrupts(uVar1);
  return;
}

undefined4
OSCreateThread(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,
              int param_6,ushort param_7)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_6 < 0) || (0x1f < param_6)) {
    OSPanic(...data.0,0x31c,@178);
  }
  if ((param_6 < 0) || (0x1f < param_6)) {
    uVar1 = 0;
  }
  else {
    *(undefined2 *)(param_1 + 0x2c8) = 1;
    *(ushort *)(param_1 + 0x2ca) = param_7 & 1;
    *(int *)(param_1 + 0x2d4) = param_6;
    *(int *)(param_1 + 0x2d0) = param_6;
    *(undefined4 *)(param_1 + 0x2cc) = 1;
    *(undefined4 *)(param_1 + 0x2d8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x2f0) = 0;
    OSInitThreadQueue(param_1 + 0x2e8);
    OSInitMutexQueue(param_1 + 0x2f4);
    puVar3 = (undefined4 *)((param_4 & 0xfffffff8) - 8);
    *puVar3 = 0;
    *(undefined4 *)((param_4 & 0xfffffff8) - 4) = 0;
    OSInitContext(param_1,param_2,puVar3);
    *(code **)(param_1 + 0x84) = OSExitThread;
    *(undefined4 *)(param_1 + 0xc) = param_3;
    *(uint *)(param_1 + 0x304) = param_4;
    *(uint *)(param_1 + 0x308) = param_4 - param_5;
    **(undefined4 **)(param_1 + 0x308) = 0xdeadbabe;
    uVar1 = OSDisableInterrupts();
    iVar2 = __OSIsThreadActive(param_1);
    if (iVar2 != 0) {
      OSPanic(...data.0,0x33b,@179,param_1);
    }
    iVar2 = param_1;
    if (_DAT_800000e0 != 0) {
      *(int *)(_DAT_800000e0 + 0x2fc) = param_1;
      iVar2 = _DAT_800000dc;
    }
    _DAT_800000dc = iVar2;
    *(int *)(param_1 + 0x300) = _DAT_800000e0;
    *(undefined4 *)(param_1 + 0x2fc) = 0;
    _DAT_800000e0 = param_1;
    OSRestoreInterrupts(uVar1);
    uVar1 = 1;
  }
  return uVar1;
}

void OSExitThread(undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = OSDisableInterrupts();
  iVar3 = OSGetCurrentThread();
  if (iVar3 == 0) {
    OSPanic(...data.0,0x354,@194);
  }
  if (*(short *)(iVar3 + 0x2c8) != 2) {
    OSPanic(...data.0,0x356,@195);
  }
  iVar4 = __OSIsThreadActive(iVar3);
  if (iVar4 == 0) {
    OSPanic(...data.0,0x358,@196);
  }
  OSClearContext(iVar3);
  if ((*(ushort *)(iVar3 + 0x2ca) & 1) == 0) {
    *(undefined2 *)(iVar3 + 0x2c8) = 8;
    *(undefined4 *)(iVar3 + 0x2d8) = param_1;
  }
  else {
    iVar4 = *(int *)(iVar3 + 0x2fc);
    iVar5 = *(int *)(iVar3 + 0x300);
    iVar1 = iVar5;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x300) = iVar5;
      iVar1 = _DAT_800000e0;
    }
    _DAT_800000e0 = iVar1;
    if (iVar5 != 0) {
      *(int *)(iVar5 + 0x2fc) = iVar4;
      iVar4 = _DAT_800000dc;
    }
    _DAT_800000dc = iVar4;
    *(undefined2 *)(iVar3 + 0x2c8) = 0;
  }
  __OSUnlockAllMutex(iVar3);
  OSWakeupThread(iVar3 + 0x2e8);
  RunQueueHint = 1;
  __OSReschedule();
  OSRestoreInterrupts(uVar2);
  return;
}

void OSCancelThread(int param_1)
{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = OSDisableInterrupts();
  iVar3 = __OSIsThreadActive(param_1);
  if (iVar3 == 0) {
    OSPanic(...data.0,0x37e,@231,param_1);
  }
  uVar1 = *(ushort *)(param_1 + 0x2c8);
  if (uVar1 == 3) {
LAB_00010e48:
    OSRestoreInterrupts(uVar2);
  }
  else {
    if (uVar1 < 3) {
      if (uVar1 == 1) {
        if (*(int *)(param_1 + 0x2cc) < 1) {
          UnsetRun(param_1);
        }
      }
      else {
        if (uVar1 == 0) goto LAB_00010e48;
        RunQueueHint = 1;
      }
    }
    else {
      if (4 < uVar1) goto LAB_00010e48;
      iVar5 = *(int *)(param_1 + 0x2e0);
      iVar3 = *(int *)(param_1 + 0x2e4);
      if (iVar5 == 0) {
        *(int *)(*(int *)(param_1 + 0x2dc) + 4) = iVar3;
      }
      else {
        *(int *)(iVar5 + 0x2e4) = iVar3;
      }
      if (iVar3 == 0) {
        **(int **)(param_1 + 0x2dc) = iVar5;
      }
      else {
        *(int *)(iVar3 + 0x2e0) = iVar5;
      }
      *(undefined4 *)(param_1 + 0x2dc) = 0;
      if ((*(int *)(param_1 + 0x2cc) < 1) && (*(int *)(param_1 + 0x2f0) != 0)) {
        if (*(int *)(*(int *)(param_1 + 0x2f0) + 8) == 0) {
          OSPanic(...data.0,0x391,@108);
        }
        UpdatePriority(*(undefined4 *)(*(int *)(param_1 + 0x2f0) + 8));
      }
    }
    OSClearContext(param_1);
    if ((*(ushort *)(param_1 + 0x2ca) & 1) == 0) {
      *(undefined2 *)(param_1 + 0x2c8) = 8;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x2fc);
      iVar4 = *(int *)(param_1 + 0x300);
      iVar5 = iVar4;
      if (iVar3 != 0) {
        *(int *)(iVar3 + 0x300) = iVar4;
        iVar5 = _DAT_800000e0;
      }
      _DAT_800000e0 = iVar5;
      if (iVar4 != 0) {
        *(int *)(iVar4 + 0x2fc) = iVar3;
        iVar3 = _DAT_800000dc;
      }
      _DAT_800000dc = iVar3;
      *(undefined2 *)(param_1 + 0x2c8) = 0;
    }
    __OSUnlockAllMutex(param_1);
    OSWakeupThread(param_1 + 0x2e8);
    __OSReschedule();
    OSRestoreInterrupts(uVar2);
  }
  return;
}

undefined4 OSJoinThread(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = OSDisableInterrupts();
  iVar3 = __OSIsThreadActive(param_1);
  if (iVar3 == 0) {
    OSPanic(...data.0,0x3ca,@253,param_1);
  }
  if ((((*(ushort *)(param_1 + 0x2ca) & 1) == 0) && (*(short *)(param_1 + 0x2c8) != 8)) &&
     (*(int *)(param_1 + 0x2e8) == 0)) {
    OSSleepThread(param_1 + 0x2e8);
    iVar3 = __OSIsThreadActive(param_1);
    if (iVar3 == 0) {
      OSRestoreInterrupts(uVar2);
      return 0;
    }
  }
  if (*(short *)(param_1 + 0x2c8) == 8) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x2d8);
    }
    iVar3 = *(int *)(param_1 + 0x2fc);
    iVar4 = *(int *)(param_1 + 0x300);
    iVar1 = iVar4;
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0x300) = iVar4;
      iVar1 = _DAT_800000e0;
    }
    _DAT_800000e0 = iVar1;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x2fc) = iVar3;
      iVar3 = _DAT_800000dc;
    }
    _DAT_800000dc = iVar3;
    *(undefined2 *)(param_1 + 0x2c8) = 0;
    OSRestoreInterrupts(uVar2);
    uVar2 = 1;
  }
  else {
    OSRestoreInterrupts(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}

void OSDetachThread(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = OSDisableInterrupts();
  iVar3 = __OSIsThreadActive(param_1);
  if (iVar3 == 0) {
    OSPanic(...data.0,0x3fc,@267,param_1);
  }
  *(ushort *)(param_1 + 0x2ca) = *(ushort *)(param_1 + 0x2ca) | 1;
  if (*(short *)(param_1 + 0x2c8) == 8) {
    iVar3 = *(int *)(param_1 + 0x2fc);
    iVar4 = *(int *)(param_1 + 0x300);
    iVar1 = iVar4;
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0x300) = iVar4;
      iVar1 = _DAT_800000e0;
    }
    _DAT_800000e0 = iVar1;
    if (iVar4 != 0) {
      *(int *)(iVar4 + 0x2fc) = iVar3;
      iVar3 = _DAT_800000dc;
    }
    _DAT_800000dc = iVar3;
    *(undefined2 *)(param_1 + 0x2c8) = 0;
  }
  OSWakeupThread(param_1 + 0x2e8);
  OSRestoreInterrupts(uVar2);
  return;
}

int OSResumeThread(int param_1)
{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = OSDisableInterrupts();
  iVar3 = __OSIsThreadActive(param_1);
  if (iVar3 == 0) {
    OSPanic(...data.0,0x419,@312,param_1);
  }
  if (*(short *)(param_1 + 0x2c8) == 8) {
    OSPanic(...data.0,0x41b,@313,param_1);
  }
  iVar3 = *(int *)(param_1 + 0x2cc);
  *(int *)(param_1 + 0x2cc) = iVar3 + -1;
  if (*(int *)(param_1 + 0x2cc) < 0) {
    *(undefined4 *)(param_1 + 0x2cc) = 0;
  }
  else if (*(int *)(param_1 + 0x2cc) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x2c8);
    if (uVar1 == 4) {
      if (*(int *)(param_1 + 0x2dc) == 0) {
        OSPanic(...data.0,0x42a,@314);
      }
      iVar6 = *(int *)(param_1 + 0x2e0);
      iVar5 = *(int *)(param_1 + 0x2e4);
      if (iVar6 == 0) {
        *(int *)(*(int *)(param_1 + 0x2dc) + 4) = iVar5;
      }
      else {
        *(int *)(iVar6 + 0x2e4) = iVar5;
      }
      if (iVar5 == 0) {
        **(int **)(param_1 + 0x2dc) = iVar6;
      }
      else {
        *(int *)(iVar5 + 0x2e0) = iVar6;
      }
      uVar4 = __OSGetEffectivePriority(param_1);
      *(undefined4 *)(param_1 + 0x2d0) = uVar4;
      for (iVar5 = **(int **)(param_1 + 0x2dc);
          (iVar5 != 0 && (*(int *)(iVar5 + 0x2d0) <= *(int *)(param_1 + 0x2d0)));
          iVar5 = *(int *)(iVar5 + 0x2e0)) {
      }
      if (iVar5 == 0) {
        iVar5 = *(int *)(*(int *)(param_1 + 0x2dc) + 4);
        if (iVar5 == 0) {
          **(int **)(param_1 + 0x2dc) = param_1;
        }
        else {
          *(int *)(iVar5 + 0x2e0) = param_1;
        }
        *(int *)(param_1 + 0x2e4) = iVar5;
        *(undefined4 *)(param_1 + 0x2e0) = 0;
        *(int *)(*(int *)(param_1 + 0x2dc) + 4) = param_1;
      }
      else {
        *(int *)(param_1 + 0x2e0) = iVar5;
        iVar6 = *(int *)(iVar5 + 0x2e4);
        *(int *)(iVar5 + 0x2e4) = param_1;
        *(int *)(param_1 + 0x2e4) = iVar6;
        if (iVar6 == 0) {
          **(int **)(param_1 + 0x2dc) = param_1;
        }
        else {
          *(int *)(iVar6 + 0x2e0) = param_1;
        }
      }
      if (*(int *)(param_1 + 0x2f0) != 0) {
        UpdatePriority(*(undefined4 *)(*(int *)(param_1 + 0x2f0) + 8));
      }
    }
    else if ((uVar1 < 4) && (uVar1 == 1)) {
      uVar4 = __OSGetEffectivePriority(param_1);
      *(undefined4 *)(param_1 + 0x2d0) = uVar4;
      SetRun(param_1);
    }
    __OSReschedule();
  }
  OSRestoreInterrupts(uVar2);
  return iVar3;
}

int OSSuspendThread(int param_1)
{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = OSDisableInterrupts();
  iVar3 = __OSIsThreadActive(param_1);
  if (iVar3 == 0) {
    OSPanic(...data.0,0x44c,@341,param_1);
  }
  if (*(short *)(param_1 + 0x2c8) == 8) {
    OSPanic(...data.0,0x44e,@342,param_1);
  }
  iVar3 = *(int *)(param_1 + 0x2cc);
  *(int *)(param_1 + 0x2cc) = iVar3 + 1;
  if (iVar3 == 0) {
    uVar1 = *(ushort *)(param_1 + 0x2c8);
    if (uVar1 != 3) {
      if (uVar1 < 3) {
        if (uVar1 == 1) {
          UnsetRun(param_1);
        }
        else if (uVar1 != 0) {
          RunQueueHint = 1;
          *(undefined2 *)(param_1 + 0x2c8) = 1;
        }
      }
      else if (uVar1 < 5) {
        iVar5 = *(int *)(param_1 + 0x2e0);
        iVar4 = *(int *)(param_1 + 0x2e4);
        if (iVar5 == 0) {
          *(int *)(*(int *)(param_1 + 0x2dc) + 4) = iVar4;
        }
        else {
          *(int *)(iVar5 + 0x2e4) = iVar4;
        }
        if (iVar4 == 0) {
          **(int **)(param_1 + 0x2dc) = iVar5;
        }
        else {
          *(int *)(iVar4 + 0x2e0) = iVar5;
        }
        *(undefined4 *)(param_1 + 0x2d0) = 0x20;
        iVar4 = *(int *)(*(int *)(param_1 + 0x2dc) + 4);
        if (iVar4 == 0) {
          **(int **)(param_1 + 0x2dc) = param_1;
        }
        else {
          *(int *)(iVar4 + 0x2e0) = param_1;
        }
        *(int *)(param_1 + 0x2e4) = iVar4;
        *(undefined4 *)(param_1 + 0x2e0) = 0;
        *(int *)(*(int *)(param_1 + 0x2dc) + 4) = param_1;
        if (*(int *)(param_1 + 0x2f0) != 0) {
          if (*(int *)(*(int *)(param_1 + 0x2f0) + 8) == 0) {
            OSPanic(...data.0,0x463,@108);
          }
          UpdatePriority(*(undefined4 *)(*(int *)(param_1 + 0x2f0) + 8));
        }
      }
    }
    __OSReschedule();
  }
  OSRestoreInterrupts(uVar2);
  return iVar3;
}

void OSSleepThread(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = OSDisableInterrupts();
  iVar2 = OSGetCurrentThread();
  if (iVar2 == 0) {
    OSPanic(...data.0,0x484,@367);
  }
  iVar3 = __OSIsThreadActive(iVar2);
  if (iVar3 == 0) {
    OSPanic(...data.0,0x486,@368,iVar2);
  }
  if (*(short *)(iVar2 + 0x2c8) != 2) {
    OSPanic(...data.0,0x488,@369,iVar2);
  }
  if (0 < *(int *)(iVar2 + 0x2cc)) {
    OSPanic(...data.0,0x48a,@370,iVar2);
  }
  *(undefined2 *)(iVar2 + 0x2c8) = 4;
  *(int **)(iVar2 + 0x2dc) = param_1;
  for (iVar3 = *param_1; (iVar3 != 0 && (*(int *)(iVar3 + 0x2d0) <= *(int *)(iVar2 + 0x2d0)));
      iVar3 = *(int *)(iVar3 + 0x2e0)) {
  }
  if (iVar3 == 0) {
    iVar3 = param_1[1];
    if (iVar3 == 0) {
      *param_1 = iVar2;
    }
    else {
      *(int *)(iVar3 + 0x2e0) = iVar2;
    }
    *(int *)(iVar2 + 0x2e4) = iVar3;
    *(undefined4 *)(iVar2 + 0x2e0) = 0;
    param_1[1] = iVar2;
  }
  else {
    *(int *)(iVar2 + 0x2e0) = iVar3;
    iVar4 = *(int *)(iVar3 + 0x2e4);
    *(int *)(iVar3 + 0x2e4) = iVar2;
    *(int *)(iVar2 + 0x2e4) = iVar4;
    if (iVar4 == 0) {
      *param_1 = iVar2;
    }
    else {
      *(int *)(iVar4 + 0x2e0) = iVar2;
    }
  }
  RunQueueHint = 1;
  __OSReschedule();
  OSRestoreInterrupts(uVar1);
  return;
}

void OSWakeupThread(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = OSDisableInterrupts();
  while (*param_1 != 0) {
    iVar3 = *param_1;
    iVar2 = *(int *)(iVar3 + 0x2e0);
    if (iVar2 == 0) {
      param_1[1] = 0;
    }
    else {
      *(undefined4 *)(iVar2 + 0x2e4) = 0;
    }
    *param_1 = iVar2;
    iVar2 = __OSIsThreadActive(iVar3);
    if (iVar2 == 0) {
      OSPanic(...data.0,0x4a7,@385);
    }
    if (*(short *)(iVar3 + 0x2c8) == 8) {
      OSPanic(...data.0,0x4a8,@386);
    }
    if (*(int **)(iVar3 + 0x2dc) != param_1) {
      OSPanic(...data.0,0x4a9,@387);
    }
    *(undefined2 *)(iVar3 + 0x2c8) = 1;
    if (*(int *)(iVar3 + 0x2cc) < 1) {
      SetRun(iVar3);
    }
  }
  __OSReschedule();
  OSRestoreInterrupts(uVar1);
  return;
}

undefined4 OSSetThreadPriority(int param_1,int param_2)
{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 < 0) || (0x1f < param_2)) {
    OSPanic(...data.0,0x4c3,@394);
  }
  if ((param_2 < 0) || (0x1f < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = OSDisableInterrupts();
    iVar2 = __OSIsThreadActive(param_1);
    if (iVar2 == 0) {
      OSPanic(...data.0,0x4ca,@395,param_1);
    }
    if (*(short *)(param_1 + 0x2c8) == 8) {
      OSPanic(...data.0,0x4cc,@396,param_1);
    }
    if (*(int *)(param_1 + 0x2d4) != param_2) {
      *(int *)(param_1 + 0x2d4) = param_2;
      UpdatePriority(param_1);
      __OSReschedule();
    }
    OSRestoreInterrupts(uVar1);
    uVar1 = 1;
  }
  return uVar1;
}

undefined4 OSGetThreadPriority(int param_1)
{
  return *(undefined4 *)(param_1 + 0x2d4);
}

undefined1 * OSSetIdleFunction(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  if (param_1 == 0) {
    if (IdleThread._712_2_ != 0) {
      OSCancelThread(IdleThread);
    }
  }
  else if (IdleThread._712_2_ == 0) {
    OSCreateThread(IdleThread,param_1,param_2,param_3,param_4,0x1f,1);
    OSResumeThread(IdleThread);
    return IdleThread;
  }
  return (undefined1 *)0x0;
}

undefined1 * OSGetIdleFunction(void)
{
  if (IdleThread._712_2_ != 0) {
    return IdleThread;
  }
  return (undefined1 *)0x0;
}

undefined4 CheckThreadQueue(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*param_1 == 0) || (*(int *)(*param_1 + 0x2e4) == 0)) {
    if ((param_1[1] == 0) || (*(int *)(param_1[1] + 0x2e0) == 0)) {
      for (iVar2 = *param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x2e0)) {
        if ((*(int *)(iVar2 + 0x2e0) != 0) && (iVar2 != *(int *)(*(int *)(iVar2 + 0x2e0) + 0x2e4)))
        {
          return 0;
        }
        if ((*(int *)(iVar2 + 0x2e4) != 0) && (iVar2 != *(int *)(*(int *)(iVar2 + 0x2e4) + 0x2e0)))
        {
          return 0;
        }
      }
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

undefined4 IsMember(int *param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *param_1;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_2 == iVar1) break;
    iVar1 = *(int *)(iVar1 + 0x2e0);
  }
  return 1;
}

int OSCheckActiveThreads(void)
{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  uVar2 = OSDisableInterrupts();
  for (iVar5 = 0; iVar5 < 0x20; iVar5 = iVar5 + 1) {
    if ((RunQueueBits & 1 << (0x1fU - iVar5 & 0x3f)) == 0) {
      if ((*(int *)(RunQueue + iVar5 * 8) != 0) || (*(int *)(RunQueue + iVar5 * 8 + 4) != 0)) {
        OSReport(@618,0x56b);
        OSPanic(...data.0,0x56b,&@617);
      }
    }
    else if ((*(int *)(RunQueue + iVar5 * 8) == 0) || (*(int *)(RunQueue + iVar5 * 8 + 4) == 0)) {
      OSReport(@616,0x566);
      OSPanic(...data.0,0x566,&@617);
    }
    iVar3 = CheckThreadQueue(RunQueue + iVar5 * 8);
    if (iVar3 == 0) {
      OSReport(@619,0x56d);
      OSPanic(...data.0,0x56d,&@617);
    }
  }
  if ((_DAT_800000dc != 0) && (*(int *)(_DAT_800000dc + 0x300) != 0)) {
    OSReport(@620,0x572);
    OSPanic(...data.0,0x572,&@617);
  }
  iVar5 = _DAT_800000dc;
  if ((_DAT_800000e0 != 0) && (*(int *)(_DAT_800000e0 + 0x2fc) != 0)) {
    OSReport(@621,0x574);
    OSPanic(...data.0,0x574,&@617);
    iVar5 = _DAT_800000dc;
  }
  do {
    if (iVar5 == 0) {
      OSRestoreInterrupts(uVar2);
      return iVar4;
    }
    iVar4 = iVar4 + 1;
    if ((*(int *)(iVar5 + 0x2fc) != 0) && (iVar5 != *(int *)(*(int *)(iVar5 + 0x2fc) + 0x300))) {
      OSReport(@622,0x57c);
      OSPanic(...data.0,0x57c,&@617);
    }
    if ((*(int *)(iVar5 + 0x300) != 0) && (iVar5 != *(int *)(*(int *)(iVar5 + 0x300) + 0x2fc))) {
      OSReport(@623,0x57e);
      OSPanic(...data.0,0x57e,&@617);
    }
    if (**(int **)(iVar5 + 0x308) != -0x21524542) {
      OSReport(@624,0x581);
      OSPanic(...data.0,0x581,&@617);
    }
    if ((*(int *)(iVar5 + 0x2d0) < 0) || (0x20 < *(int *)(iVar5 + 0x2d0))) {
      OSReport(@625,0x584);
      OSPanic(...data.0,0x584,&@617);
    }
    if (*(int *)(iVar5 + 0x2cc) < 0) {
      OSReport(@626,0x585);
      OSPanic(...data.0,0x585,&@617);
    }
    iVar3 = CheckThreadQueue(iVar5 + 0x2e8);
    if (iVar3 == 0) {
      OSReport(@627,0x586);
      OSPanic(...data.0,0x586,&@617);
    }
    uVar1 = *(ushort *)(iVar5 + 0x2c8);
    if (uVar1 == 4) {
      if (*(int *)(iVar5 + 0x2dc) == 0) {
        OSReport(@633,0x597);
        OSPanic(...data.0,0x597,&@617);
      }
      iVar3 = CheckThreadQueue(*(undefined4 *)(iVar5 + 0x2dc));
      if (iVar3 == 0) {
        OSReport(@634,0x598);
        OSPanic(...data.0,0x598,&@617);
      }
      iVar3 = IsMember(*(undefined4 *)(iVar5 + 0x2dc),iVar5);
      if (iVar3 == 0) {
        OSReport(@635,0x599);
        OSPanic(...data.0,0x599,&@617);
      }
      if (*(int *)(iVar5 + 0x2cc) < 1) {
        iVar3 = __OSGetEffectivePriority(iVar5);
        if (*(int *)(iVar5 + 0x2d0) != iVar3) {
          OSReport(@630,0x59c);
          OSPanic(...data.0,0x59c,&@617);
        }
      }
      else if (*(int *)(iVar5 + 0x2d0) != 0x20) {
        OSReport(@636,0x5a0);
        OSPanic(...data.0,0x5a0,&@617);
      }
      iVar3 = __OSCheckDeadLock(iVar5);
      if (iVar3 != 0) {
        OSReport(@637,0x5a2);
        OSPanic(...data.0,0x5a2,&@617);
      }
    }
    else if (uVar1 < 4) {
      if (uVar1 == 2) {
        if (0 < *(int *)(iVar5 + 0x2cc)) {
          OSReport(@631,0x592);
          OSPanic(...data.0,0x592,&@617);
        }
        if (*(int *)(iVar5 + 0x2dc) != 0) {
          OSReport(@632,0x593);
          OSPanic(...data.0,0x593,&@617);
        }
        iVar3 = __OSGetEffectivePriority(iVar5);
        if (*(int *)(iVar5 + 0x2d0) != iVar3) {
          OSReport(@630,0x594);
          OSPanic(...data.0,0x594,&@617);
        }
      }
      else {
        if ((1 < uVar1) || (uVar1 == 0)) goto LAB_0001206c;
        if (*(int *)(iVar5 + 0x2cc) < 1) {
          if (*(undefined1 **)(iVar5 + 0x2dc) != RunQueue + *(int *)(iVar5 + 0x2d0) * 8) {
            OSReport(@628,0x58c);
            OSPanic(...data.0,0x58c,&@617);
          }
          iVar3 = IsMember(RunQueue + *(int *)(iVar5 + 0x2d0) * 8,iVar5);
          if (iVar3 == 0) {
            OSReport(@629,0x58d);
            OSPanic(...data.0,0x58d,&@617);
          }
          iVar3 = __OSGetEffectivePriority(iVar5);
          if (*(int *)(iVar5 + 0x2d0) != iVar3) {
            OSReport(@630,0x58e);
            OSPanic(...data.0,0x58e,&@617);
          }
        }
      }
    }
    else if (uVar1 == 8) {
      if ((*(int *)(iVar5 + 0x2f4) != 0) || (*(int *)(iVar5 + 0x2f8) != 0)) {
        OSReport(@638,0x5a6);
        OSPanic(...data.0,0x5a6,&@617);
      }
    }
    else {
LAB_0001206c:
      OSReport(@639,*(undefined2 *)(iVar5 + 0x2c8),iVar5);
      OSPanic(...data.0,0x5ac,&@617);
    }
    iVar3 = __OSCheckMutexes(iVar5);
    if (iVar3 == 0) {
      OSReport(@640,0x5b1);
      OSPanic(...data.0,0x5b1,&@617);
    }
    iVar5 = *(int *)(iVar5 + 0x2fc);
  } while( true );
}
