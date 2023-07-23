void OSInitSemaphore(undefined4 *param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  uVar1 = OSDisableInterrupts();
  OSInitThreadQueue(param_1 + 1);
  *param_1 = param_2;
  OSRestoreInterrupts(uVar1);
  return;
}

int OSWaitSemaphore(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = OSDisableInterrupts();
  while (iVar2 = *param_1, iVar2 < 1) {
    OSSleepThread(param_1 + 1);
  }
  *param_1 = *param_1 + -1;
  OSRestoreInterrupts(uVar1);
  return iVar2;
}

int OSTryWaitSemaphore(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = OSDisableInterrupts();
  iVar2 = *param_1;
  if (0 < *param_1) {
    *param_1 = *param_1 + -1;
  }
  OSRestoreInterrupts(uVar1);
  return iVar2;
}

int OSSignalSemaphore(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = OSDisableInterrupts();
  iVar2 = *param_1;
  *param_1 = *param_1 + 1;
  OSWakeupThread(param_1 + 1);
  OSRestoreInterrupts(uVar1);
  return iVar2;
}

undefined4 OSGetSemaphoreCount(undefined4 *param_1)
{
  return *param_1;
}
