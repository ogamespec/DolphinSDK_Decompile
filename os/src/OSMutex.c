void OSInitMutex(int param_1)
{
  OSInitThreadQueue(param_1);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

void OSLockMutex(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = OSDisableInterrupts();
  iVar2 = OSGetCurrentThread();
  if (iVar2 == 0) {
    OSPanic(...data.0,0x8c,@22);
  }
  if (*(short *)(iVar2 + 0x2c8) != 2) {
    OSPanic(...data.0,0x8e,@23);
  }
  do {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = iVar2;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      iVar3 = *(int *)(iVar2 + 0x2f8);
      if (iVar3 == 0) {
        *(int *)(iVar2 + 0x2f4) = param_1;
      }
      else {
        *(int *)(iVar3 + 0x10) = param_1;
      }
      *(int *)(param_1 + 0x14) = iVar3;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(int *)(iVar2 + 0x2f8) = param_1;
LAB_0001015c:
      OSRestoreInterrupts(uVar1);
      return;
    }
    if (*(int *)(param_1 + 8) == iVar2) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      goto LAB_0001015c;
    }
    *(int *)(iVar2 + 0x2f0) = param_1;
    __OSPromoteThread(*(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar2 + 0x2d0));
    iVar3 = __OSCheckDeadLock(iVar2);
    if (iVar3 != 0) {
      OSPanic(...data.0,0xa4,@24,iVar2,param_1);
    }
    OSSleepThread(param_1);
    *(undefined4 *)(iVar2 + 0x2f0) = 0;
  } while( true );
}

void OSUnlockMutex(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar2 = OSDisableInterrupts();
  iVar3 = OSGetCurrentThread();
  if (iVar3 == 0) {
    OSPanic(...data.0,0xbd,@41);
  }
  if (*(short *)(iVar3 + 0x2c8) != 2) {
    OSPanic(...data.0,0xbf,@42);
  }
  if (*(int *)(param_1 + 8) != iVar3) {
    OSPanic(...data.0,0xc2,@43,iVar3,param_1);
  }
  if (*(int *)(param_1 + 8) == iVar3) {
    iVar1 = *(int *)(param_1 + 0xc) + -1;
    *(int *)(param_1 + 0xc) = iVar1;
    if (iVar1 == 0) {
      iVar5 = *(int *)(param_1 + 0x10);
      iVar1 = *(int *)(param_1 + 0x14);
      if (iVar5 == 0) {
        *(int *)(iVar3 + 0x2f8) = iVar1;
      }
      else {
        *(int *)(iVar5 + 0x14) = iVar1;
      }
      if (iVar1 == 0) {
        *(int *)(iVar3 + 0x2f4) = iVar5;
      }
      else {
        *(int *)(iVar1 + 0x10) = iVar5;
      }
      *(undefined4 *)(param_1 + 8) = 0;
      if (*(int *)(iVar3 + 0x2d0) < *(int *)(iVar3 + 0x2d4)) {
        uVar4 = __OSGetEffectivePriority(iVar3);
        *(undefined4 *)(iVar3 + 0x2d0) = uVar4;
      }
      OSWakeupThread(param_1);
    }
  }
  OSRestoreInterrupts(uVar2);
  return;
}

void __OSUnlockAllMutex(int param_1)
{
  int iVar1;
  int iVar2;
  
  while (*(int *)(param_1 + 0x2f4) != 0) {
    iVar2 = *(int *)(param_1 + 0x2f4);
    iVar1 = *(int *)(iVar2 + 0x10);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x2f8) = 0;
    }
    else {
      *(undefined4 *)(iVar1 + 0x14) = 0;
    }
    *(int *)(param_1 + 0x2f4) = iVar1;
    if (*(int *)(iVar2 + 8) != param_1) {
      OSPanic(...data.0,0xe5,@56);
    }
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 8) = 0;
    OSWakeupThread(iVar2);
  }
  return;
}

undefined4 OSTryLockMutex(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = OSDisableInterrupts();
  iVar2 = OSGetCurrentThread();
  if (iVar2 == 0) {
    OSPanic(...data.0,0xff,@71);
  }
  if (*(short *)(iVar2 + 0x2c8) != 2) {
    OSPanic(...data.0,0x101,@72);
  }
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = iVar2;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    iVar3 = *(int *)(iVar2 + 0x2f8);
    if (iVar3 == 0) {
      *(int *)(iVar2 + 0x2f4) = param_1;
    }
    else {
      *(int *)(iVar3 + 0x10) = param_1;
    }
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(int *)(iVar2 + 0x2f8) = param_1;
    uVar4 = 1;
  }
  else if (*(int *)(param_1 + 8) == iVar2) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  OSRestoreInterrupts(uVar1);
  return uVar4;
}

void OSInitCond(undefined4 param_1)
{
  OSInitThreadQueue(param_1);
  return;
}

void OSWaitCond(undefined4 param_1,int param_2)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = OSDisableInterrupts();
  iVar2 = OSGetCurrentThread();
  if (iVar2 == 0) {
    OSPanic(...data.0,0x139,@89);
  }
  if (*(short *)(iVar2 + 0x2c8) != 2) {
    OSPanic(...data.0,0x13b,@90);
  }
  if (*(int *)(param_2 + 8) != iVar2) {
    OSPanic(...data.0,0x13e,@91,iVar2,param_2);
  }
  if (*(int *)(param_2 + 8) == iVar2) {
    uVar4 = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_2 + 0xc) = 0;
    iVar6 = *(int *)(param_2 + 0x10);
    iVar5 = *(int *)(param_2 + 0x14);
    if (iVar6 == 0) {
      *(int *)(iVar2 + 0x2f8) = iVar5;
    }
    else {
      *(int *)(iVar6 + 0x14) = iVar5;
    }
    if (iVar5 == 0) {
      *(int *)(iVar2 + 0x2f4) = iVar6;
    }
    else {
      *(int *)(iVar5 + 0x10) = iVar6;
    }
    *(undefined4 *)(param_2 + 8) = 0;
    if (*(int *)(iVar2 + 0x2d0) < *(int *)(iVar2 + 0x2d4)) {
      uVar3 = __OSGetEffectivePriority(iVar2);
      *(undefined4 *)(iVar2 + 0x2d0) = uVar3;
    }
    OSDisableScheduler();
    OSWakeupThread(param_2);
    OSEnableScheduler();
    OSSleepThread(param_1);
    OSLockMutex(param_2);
    *(undefined4 *)(param_2 + 0xc) = uVar4;
  }
  OSRestoreInterrupts(uVar1);
  return;
}

void OSSignalCond(undefined4 param_1)
{
  OSWakeupThread(param_1);
  return;
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
    iVar1 = *(int *)(iVar1 + 0x10);
  }
  return 1;
}

undefined4 __OSCheckMutex(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if ((*param_1 == 0) || (*(int *)(*param_1 + 0x2e4) == 0)) {
    if ((param_1[1] == 0) || (*(int *)(param_1[1] + 0x2e0) == 0)) {
      for (iVar3 = *param_1; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x2e0)) {
        if ((*(int *)(iVar3 + 0x2e0) != 0) && (iVar3 != *(int *)(*(int *)(iVar3 + 0x2e0) + 0x2e4)))
        {
          return 0;
        }
        if ((*(int *)(iVar3 + 0x2e4) != 0) && (iVar3 != *(int *)(*(int *)(iVar3 + 0x2e4) + 0x2e0)))
        {
          return 0;
        }
        if (*(short *)(iVar3 + 0x2c8) != 4) {
          return 0;
        }
        if (*(int *)(iVar3 + 0x2d0) < iVar2) {
          return 0;
        }
        iVar2 = *(int *)(iVar3 + 0x2d0);
      }
      if (param_1[2] == 0) {
        if (param_1[3] != 0) {
          return 0;
        }
      }
      else if (param_1[3] < 1) {
        return 0;
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

undefined4 __OSCheckDeadLock(int param_1)
{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x2f0); (iVar1 != 0 && (*(int *)(iVar1 + 8) != 0));
      iVar1 = *(int *)(*(int *)(iVar1 + 8) + 0x2f0)) {
    if (*(int *)(iVar1 + 8) == param_1) {
      return 1;
    }
  }
  return 0;
}

undefined4 __OSCheckMutexes(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x2f4);
  while( true ) {
    if (iVar2 == 0) {
      return 1;
    }
    if (*(int *)(iVar2 + 8) != param_1) break;
    iVar1 = __OSCheckMutex(iVar2);
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x10);
  }
  return 0;
}
