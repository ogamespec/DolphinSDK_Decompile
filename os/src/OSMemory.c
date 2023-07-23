undefined4 OSGetPhysicalMemSize(void)
{
  int iVar1;
  
  iVar1 = OSPhysicalToCached(0);
  return *(undefined4 *)(iVar1 + 0x28);
}

undefined4 OSGetConsoleSimulatedMemSize(void)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)OSPhysicalToCached(0xf0);
  return *puVar1;
}

void MEMIntrruptHandler(undefined4 param_1,undefined4 param_2)
{
  uint uVar1;
  
  uVar1 = (_DAT_cc004024 & 0x3ff) << 0x10 | (uint)_DAT_cc004022;
  _DAT_cc004020 = 0;
  if (_DAT_00011044 == (code *)0x0) {
    __OSUnhandledException(0xf,param_2,_DAT_cc00401e,uVar1);
  }
  else {
    (*_DAT_00011044)(0xf,param_2,_DAT_cc00401e,uVar1);
  }
  return;
}

void OSProtectRange(uint param_1,uint param_2,int param_3,uint param_4)
{
  uint uVar1;
  undefined4 uVar2;
  
  if (3 < param_1) {
    OSPanic(@14,0xcb,@15);
  }
  if ((param_4 & 0xfffffffc) != 0) {
    OSPanic(@14,0xcc,@16);
  }
  if (param_1 < 4) {
    uVar1 = param_2 + param_3 + 0x3ff;
    DCFlushRange(param_2 & 0xfffffc00,(uVar1 & 0xfffffc00) - (param_2 & 0xfffffc00));
    uVar2 = OSDisableInterrupts();
    __OSMaskInterrupts(0x80000000 >> (param_1 & 0x3f));
    *(short *)(param_1 * 4 + -0x33ffc000) = (short)(param_2 >> 10);
    *(short *)((param_1 * 2 + 1) * 2 + -0x33ffc000) = (short)(uVar1 >> 10);
    _DAT_cc004010 =
         _DAT_cc004010 & ~(ushort)(3 << ((param_1 & 0x1f) << 1)) |
         (ushort)((param_4 & 3) << ((param_1 & 0x1f) << 1));
    if ((param_4 & 3) != 3) {
      __OSUnmaskInterrupts(0x80000000 >> (param_1 & 0x3f));
    }
    OSRestoreInterrupts(uVar2);
  }
  return;
}

void Config24MB(void)
{
  uint in_MSR;
  
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  returnFromInterrupt(in_MSR,in_MSR | 0x30);
  return;
}

void Config48MB(void)
{
  uint in_MSR;
  
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  returnFromInterrupt(in_MSR,in_MSR | 0x30);
  return;
}

uint RealMode(void)
{
  uint in_MSR;
  
  returnFromInterrupt(in_MSR,in_MSR & 0xffffffcf);
  return in_MSR & 0xffffffcf;
}

void __OSInitMemoryProtection(void)
{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = OSGetConsoleSimulatedMemSize();
  uVar2 = OSDisableInterrupts();
  if (uVar1 < 0x1800001) {
    RealMode(Config24MB);
  }
  else if (uVar1 < 0x3000001) {
    RealMode(Config48MB);
  }
  _DAT_cc004020 = 0;
  _DAT_cc004010 = 0xff;
  __OSMaskInterrupts(0xf0000000);
  __OSSetInterruptHandler(0,MEMIntrruptHandler);
  __OSSetInterruptHandler(1,MEMIntrruptHandler);
  __OSSetInterruptHandler(2,MEMIntrruptHandler);
  __OSSetInterruptHandler(3,MEMIntrruptHandler);
  __OSSetInterruptHandler(4,MEMIntrruptHandler);
  OSRegisterResetFunction(ResetFunctionInfo);
  uVar1 = OSGetPhysicalMemSize();
  uVar3 = OSGetConsoleSimulatedMemSize();
  if ((uVar3 < uVar1) && (iVar4 = OSGetConsoleSimulatedMemSize(), iVar4 == 0x1800000)) {
    _DAT_cc004028 = 2;
  }
  __OSUnmaskInterrupts(0x8000000);
  OSRestoreInterrupts(uVar2);
  return;
}
