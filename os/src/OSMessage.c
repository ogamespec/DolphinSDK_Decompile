void OSInitMessageQueue(int param_1,undefined4 param_2,undefined4 param_3)
{
  OSInitThreadQueue(param_1);
  OSInitThreadQueue(param_1 + 8);
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}

undefined4 OSSendMessage(int param_1,undefined4 param_2,uint param_3)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = OSDisableInterrupts();
  while( true ) {
    if (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x14)) {
      iVar2 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x1c);
      *(undefined4 *)
       (*(int *)(param_1 + 0x10) +
       (iVar2 - (iVar2 / *(int *)(param_1 + 0x14)) * *(int *)(param_1 + 0x14)) * 4) = param_2;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      OSWakeupThread(param_1 + 8);
      OSRestoreInterrupts(uVar1);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    OSSleepThread(param_1);
  }
  OSRestoreInterrupts(uVar1);
  return 0;
}

undefined4 OSReceiveMessage(int param_1,undefined4 *param_2,uint param_3)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = OSDisableInterrupts();
  while( true ) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4);
      }
      iVar2 = *(int *)(param_1 + 0x18) + 1;
      *(int *)(param_1 + 0x18) =
           iVar2 - (iVar2 / *(int *)(param_1 + 0x14)) * *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
      OSWakeupThread(param_1);
      OSRestoreInterrupts(uVar1);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    OSSleepThread(param_1 + 8);
  }
  OSRestoreInterrupts(uVar1);
  return 0;
}

undefined4 OSJamMessage(int param_1,undefined4 param_2,uint param_3)
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = OSDisableInterrupts();
  while( true ) {
    if (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x14)) {
      iVar2 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x14) + -1;
      *(int *)(param_1 + 0x18) =
           iVar2 - (iVar2 / *(int *)(param_1 + 0x14)) * *(int *)(param_1 + 0x14);
      *(undefined4 *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4) = param_2;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      OSWakeupThread(param_1 + 8);
      OSRestoreInterrupts(uVar1);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    OSSleepThread(param_1);
  }
  OSRestoreInterrupts(uVar1);
  return 0;
}
