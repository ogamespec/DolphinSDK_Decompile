void GXOverflowHandler(void)
{
  if (1 < *(int *)(iRam00000000 + 4)) {
    OSReport(...data.0);
  }
  if (GXOverflowSuspendInProgress != 0) {
    OSPanic(@12,0x167,@13);
  }
  __GXOverflowCount = __GXOverflowCount + 1;
  __GXWriteFifoIntEnable(0,1);
  __GXWriteFifoIntReset(1,0);
  GXOverflowSuspendInProgress = 1;
  if (1 < *(int *)(iRam00000000 + 4)) {
    OSReport(@14);
  }
  OSSuspendThread(__GXCurrentThread);
  return;
}

void GXUnderflowHandler(void)
{
  if (1 < *(int *)(iRam00000000 + 4)) {
    OSReport(@18);
  }
  if (GXOverflowSuspendInProgress == 0) {
    OSPanic(@12,0x191,@19);
  }
  OSResumeThread(__GXCurrentThread);
  GXOverflowSuspendInProgress = 0;
  __GXWriteFifoIntReset(1,1);
  __GXWriteFifoIntEnable(1,0);
  return;
}

void GXBreakPointHandler(undefined4 param_1,undefined4 param_2)
{
  undefined auStack_2c8 [712];
  
  *(uint *)(iRam00000000 + 8) = *(uint *)(iRam00000000 + 8) & 0xffffffdf;
  *(short *)(iRam00000000 + 2) = (short)*(undefined4 *)(iRam00000000 + 8);
  if (BreakPointCB != (code *)0x0) {
    OSClearContext(auStack_2c8);
    OSSetCurrentContext(auStack_2c8);
    (*BreakPointCB)();
    OSClearContext(auStack_2c8);
    OSSetCurrentContext(param_2);
  }
  return;
}

void GXCPInterruptHandler(undefined4 param_1,undefined4 param_2)
{
  *(uint *)(puRam00000000 + 6) = (uint)*puRam00000000;
  if (((*(uint *)(puRam00000000 + 4) >> 3 & 1) != 0) &&
     ((*(uint *)(puRam00000000 + 6) >> 1 & 1) != 0)) {
    GXUnderflowHandler(param_1,param_2);
  }
  if (((*(uint *)(puRam00000000 + 4) >> 2 & 1) != 0) && ((*(uint *)(puRam00000000 + 6) & 1) != 0)) {
    GXOverflowHandler(param_1,param_2);
  }
  if (((*(uint *)(puRam00000000 + 4) >> 5 & 1) != 0) &&
     ((*(uint *)(puRam00000000 + 6) >> 4 & 1) != 0)) {
    GXBreakPointHandler(param_1,param_2);
  }
  return;
}

void GXInitFifoBase(uint *param_1,uint param_2,uint param_3)
{
  if (param_1 == CPUFifo) {
    OSPanic(@12,0x20c,@34);
  }
  if (param_1 == GPFifo) {
    OSPanic(@12,0x20e,@35);
  }
  if ((param_2 & 0x1f) != 0) {
    OSPanic(@12,0x210,@36);
  }
  if (param_2 == 0) {
    OSPanic(@12,0x212,@37);
  }
  if ((param_3 & 0x1f) != 0) {
    OSPanic(@12,0x214,@38);
  }
  if (param_3 < 0x10000) {
    OSPanic(@12,0x216,@39);
  }
  *param_1 = param_2;
  param_1[1] = param_2 + (param_3 - 4);
  param_1[2] = param_3;
  param_1[7] = 0;
  GXInitFifoLimits(param_1,param_3 - 0x4000,param_3 >> 1 & 0x7fffffe0);
  GXInitFifoPtrs(param_1,param_2,param_2);
  return;
}

void GXInitFifoPtrs(uint *param_1,uint param_2,uint param_3)
{
  undefined4 uVar1;
  
  if (param_1 == CPUFifo) {
    OSPanic(@12,0x23e,@43);
  }
  if (param_1 == GPFifo) {
    OSPanic(@12,0x240,@44);
  }
  if ((param_2 & 0x1f) != 0) {
    OSPanic(@12,0x242,@45);
  }
  if ((param_3 & 0x1f) != 0) {
    OSPanic(@12,0x244,@46);
  }
  if ((param_2 < *param_1) || (param_1[1] <= param_2)) {
    OSPanic(@12,0x247,@47);
  }
  if ((param_3 < *param_1) || (param_1[1] <= param_3)) {
    OSPanic(@12,0x24a,@48);
  }
  uVar1 = OSDisableInterrupts();
  param_1[5] = param_2;
  param_1[6] = param_3;
  param_1[7] = param_3 - param_2;
  if ((int)param_1[7] < 0) {
    param_1[7] = param_1[7] + param_1[2];
  }
  OSRestoreInterrupts(uVar1);
  return;
}

void GXInitFifoLimits(int *param_1,uint param_2,uint param_3)
{
  if (param_1 == GPFifo) {
    OSPanic(@12,0x26f,@50);
  }
  if ((param_2 & 0x1f) != 0) {
    OSPanic(@12,0x271,@51);
  }
  if ((param_3 & 0x1f) != 0) {
    OSPanic(@12,0x273,@52);
  }
  if ((uint)(param_1[1] - *param_1) <= param_2) {
    OSPanic(@12,0x275,@53);
  }
  if (param_2 <= param_3) {
    OSPanic(@12,0x277,@54);
  }
  param_1[3] = param_2;
  param_1[4] = param_3;
  return;
}

void GXSetCPUFifo(uint *param_1)
{
  undefined4 uVar1;
  
  uVar1 = OSDisableInterrupts();
  CPUFifo = param_1;
  if (param_1 == GPFifo) {
    *(uint *)(iRam00000000 + 0xc) = *param_1 & 0x3fffffff;
    *(uint *)(iRam00000000 + 0x10) = param_1[1] & 0x3fffffff;
    if (((param_1[6] & 0x3fffffff) >> 5 & 0x7e00000) != 0) {
      OSPanic(@12,0x2a1,@61);
    }
    *(uint *)(iRam00000000 + 0x14) = param_1[6] & 0x3bffffe0;
    CPGPLinked = '\x01';
    __GXWriteFifoIntReset(1,1);
    __GXWriteFifoIntEnable(1,0);
    __GXFifoLink(1);
  }
  else {
    if (CPGPLinked != '\0') {
      __GXFifoLink(0);
      CPGPLinked = '\0';
    }
    __GXWriteFifoIntEnable(0,0);
    *(uint *)(iRam00000000 + 0xc) = *param_1 & 0x3fffffff;
    *(uint *)(iRam00000000 + 0x10) = param_1[1] & 0x3fffffff;
    if (((param_1[6] & 0x3fffffff) >> 5 & 0x7e00000) != 0) {
      OSPanic(@12,0x2c4,@61);
    }
    *(uint *)(iRam00000000 + 0x14) = param_1[6] & 0x3bffffe0;
  }
  sync(0);
  OSRestoreInterrupts(uVar1);
  return;
}

void GXSetGPFifo(undefined4 *param_1)
{
  undefined4 uVar1;
  
  uVar1 = OSDisableInterrupts();
  __GXFifoReadDisable();
  __GXWriteFifoIntEnable(0,0);
  GPFifo = param_1;
  *(short *)(iRam00000000 + 0x20) = (short)*param_1;
  *(short *)(iRam00000000 + 0x24) = (short)param_1[1];
  *(short *)(iRam00000000 + 0x30) = (short)param_1[7];
  *(short *)(iRam00000000 + 0x34) = (short)param_1[6];
  *(short *)(iRam00000000 + 0x38) = (short)param_1[5];
  *(short *)(iRam00000000 + 0x28) = (short)param_1[3];
  *(short *)(iRam00000000 + 0x2c) = (short)param_1[4];
  *(ushort *)(iRam00000000 + 0x22) = (ushort)((uint)*param_1 >> 0x10) & 0x3fff;
  *(ushort *)(iRam00000000 + 0x26) = (ushort)((uint)param_1[1] >> 0x10) & 0x3fff;
  *(short *)(iRam00000000 + 0x32) = (short)((uint)param_1[7] >> 0x10);
  *(ushort *)(iRam00000000 + 0x36) = (ushort)((uint)param_1[6] >> 0x10) & 0x3fff;
  *(ushort *)(iRam00000000 + 0x3a) = (ushort)((uint)param_1[5] >> 0x10) & 0x3fff;
  *(short *)(iRam00000000 + 0x2a) = (short)((uint)param_1[3] >> 0x10);
  *(short *)(iRam00000000 + 0x2e) = (short)((uint)param_1[4] >> 0x10);
  sync(0);
  if (CPUFifo == GPFifo) {
    CPGPLinked = 1;
    __GXWriteFifoIntEnable(1,0);
    __GXFifoLink(1);
  }
  else {
    CPGPLinked = 0;
    __GXWriteFifoIntEnable(0,0);
    __GXFifoLink(0);
  }
  __GXWriteFifoIntReset(1,1);
  __GXFifoReadEnable();
  OSRestoreInterrupts(uVar1);
  return;
}

void GXSaveCPUFifo(int param_1)
{
  if (param_1 != CPUFifo) {
    OSPanic(@12,0x32e,@67);
  }
  __GXSaveCPUFifoAux(param_1);
  return;
}

void __GXSaveCPUFifoAux(undefined4 *param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = OSDisableInterrupts();
  GXFlush();
  uVar2 = OSPhysicalToCached(*(undefined4 *)(iRam00000000 + 0xc));
  *param_1 = uVar2;
  uVar2 = OSPhysicalToCached(*(undefined4 *)(iRam00000000 + 0x10));
  param_1[1] = uVar2;
  uVar2 = OSPhysicalToCached(*(uint *)(iRam00000000 + 0x14) & 0xfbffffff);
  param_1[6] = uVar2;
  if (CPGPLinked == '\0') {
    param_1[7] = param_1[6] - param_1[5];
    if ((int)param_1[7] < 0) {
      param_1[7] = param_1[7] + param_1[2];
    }
  }
  else {
    uVar2 = OSPhysicalToCached(CONCAT22(*(undefined2 *)(iRam00000000 + 0x3a),
                                        *(undefined2 *)(iRam00000000 + 0x38)));
    param_1[5] = uVar2;
    param_1[7] = CONCAT22(*(undefined2 *)(iRam00000000 + 0x32),*(undefined2 *)(iRam00000000 + 0x30))
    ;
  }
  OSRestoreInterrupts(uVar1);
  return;
}

void GXSaveGPFifo(int param_1)
{
  undefined4 uVar1;
  
  if (param_1 != GPFifo) {
    OSPanic(@12,0x377,@75);
  }
  if ((*puRam00000000 >> 2 & 1) == 0) {
    OSPanic(@12,0x37e,@76);
  }
  uVar1 = OSPhysicalToCached(CONCAT22(puRam00000000[0x1d],puRam00000000[0x1c]));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  *(uint *)(param_1 + 0x1c) = CONCAT22(puRam00000000[0x19],puRam00000000[0x18]);
  return;
}

void GXGetGPStatus(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)
{
  *(uint *)(puRam00000000 + 6) = (uint)*puRam00000000;
  *param_1 = (byte)*(undefined4 *)(puRam00000000 + 6) & 1;
  *param_2 = (byte)(*(uint *)(puRam00000000 + 6) >> 1) & 1;
  *param_3 = (byte)(*(uint *)(puRam00000000 + 6) >> 2) & 1;
  *param_4 = (byte)(*(uint *)(puRam00000000 + 6) >> 3) & 1;
  *param_5 = (byte)(*(uint *)(puRam00000000 + 6) >> 4) & 1;
  return;
}

void GXGetFifoStatus(int param_1,undefined *param_2,undefined *param_3,undefined4 *param_4,
                    undefined4 param_5,undefined4 param_6,byte *param_7)
{
  undefined4 uVar1;
  
  *param_3 = 0;
  *param_2 = 0;
  *param_4 = 0;
  *param_7 = 0;
  if (param_1 == GPFifo) {
    uVar1 = OSPhysicalToCached(CONCAT22(*(undefined2 *)(iRam00000000 + 0x3a),
                                        *(undefined2 *)(iRam00000000 + 0x38)));
    *(undefined4 *)(param_1 + 0x14) = uVar1;
    *(uint *)(param_1 + 0x1c) =
         CONCAT22(*(undefined2 *)(iRam00000000 + 0x32),*(undefined2 *)(iRam00000000 + 0x30));
  }
  if (param_1 == CPUFifo) {
    __GXSaveCPUFifoAux(param_1);
    *param_7 = (byte)((uint)*(undefined4 *)(iRam00000000 + 0x14) >> 0x1a) & 1;
  }
  *param_2 = *(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 0x1c);
  *param_3 = *(uint *)(param_1 + 0x1c) < *(uint *)(param_1 + 0x10);
  *param_4 = *(undefined4 *)(param_1 + 0x1c);
  *(bool *)param_5 = param_1 == CPUFifo;
  *(bool *)param_6 = param_1 == GPFifo;
  return;
}

void GXGetFifoPtrs(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  undefined4 uVar1;
  
  if (param_1 == CPUFifo) {
    uVar1 = OSPhysicalToCached(*(uint *)(iRam00000000 + 0x14) & 0xfbffffff);
    *(undefined4 *)(param_1 + 0x18) = uVar1;
  }
  if (param_1 == GPFifo) {
    uVar1 = OSPhysicalToCached(CONCAT22(*(undefined2 *)(iRam00000000 + 0x3a),
                                        *(undefined2 *)(iRam00000000 + 0x38)));
    *(undefined4 *)(param_1 + 0x14) = uVar1;
    *(uint *)(param_1 + 0x1c) =
         CONCAT22(*(undefined2 *)(iRam00000000 + 0x32),*(undefined2 *)(iRam00000000 + 0x30));
  }
  else {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);
    if (*(int *)(param_1 + 0x1c) < 0) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 8);
    }
  }
  *param_2 = *(undefined4 *)(param_1 + 0x14);
  *param_3 = *(undefined4 *)(param_1 + 0x18);
  return;
}

undefined4 GXGetFifoBase(undefined4 *param_1)
{
  return *param_1;
}

undefined4 GXGetFifoSize(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

void GXGetFifoLimits(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  *param_3 = *(undefined4 *)(param_1 + 0x10);
  return;
}

undefined4 GXSetBreakPtCallback(undefined4 param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = BreakPointCB;
  uVar2 = OSDisableInterrupts();
  BreakPointCB = param_1;
  OSRestoreInterrupts(uVar2);
  return uVar1;
}

void GXEnableBreakPt(undefined4 param_1)
{
  undefined4 uVar1;
  
  uVar1 = OSDisableInterrupts();
  __GXFifoReadDisable();
  *(short *)(iRam00000000 + 0x3c) = (short)param_1;
  *(ushort *)(iRam00000000 + 0x3e) = (ushort)((uint)param_1 >> 0x10) & 0x3fff;
  *(uint *)(iRam00000000 + 8) = *(uint *)(iRam00000000 + 8) & 0xfffffffd | 2;
  *(uint *)(iRam00000000 + 8) = *(uint *)(iRam00000000 + 8) & 0xffffffdf | 0x20;
  *(short *)(iRam00000000 + 2) = (short)*(undefined4 *)(iRam00000000 + 8);
  __GXCurrentBP = param_1;
  __GXFifoReadEnable();
  OSRestoreInterrupts(uVar1);
  return;
}

void GXDisableBreakPt(void)
{
  undefined4 uVar1;
  
  uVar1 = OSDisableInterrupts();
  *(uint *)(iRam00000000 + 8) = *(uint *)(iRam00000000 + 8) & 0xfffffffd;
  *(uint *)(iRam00000000 + 8) = *(uint *)(iRam00000000 + 8) & 0xffffffdf;
  *(short *)(iRam00000000 + 2) = (short)*(undefined4 *)(iRam00000000 + 8);
  __GXCurrentBP = 0;
  OSRestoreInterrupts(uVar1);
  return;
}

void __GXFifoInit(void)
{
  __OSSetInterruptHandler(0x11,GXCPInterruptHandler);
  __OSUnmaskInterrupts(0x4000);
  __GXCurrentThread = OSGetCurrentThread();
  GXOverflowSuspendInProgress = 0;
  CPUFifo = 0;
  GPFifo = 0;
  return;
}


void __GXFifoReadEnable(void)
{
  *(uint *)(iRam00000000 + 8) = *(uint *)(iRam00000000 + 8) & 0xfffffffe | 1;
  *(short *)(iRam00000000 + 2) = (short)*(undefined4 *)(iRam00000000 + 8);
  return;
}

void __GXFifoReadDisable(void)
{
  *(uint *)(iRam00000000 + 8) = *(uint *)(iRam00000000 + 8) & 0xfffffffe;
  *(short *)(iRam00000000 + 2) = (short)*(undefined4 *)(iRam00000000 + 8);
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010fe4) */
void __GXFifoLink(char param_1)
{
  *(uint *)(iRam00000000 + 8) =
       *(uint *)(iRam00000000 + 8) & 0xffffffef | (uint)(param_1 != '\0') << 4;
  *(short *)(iRam00000000 + 2) = (short)*(undefined4 *)(iRam00000000 + 8);
  return;
}

void __GXWriteFifoIntEnable(uint param_1,uint param_2)
{
  if ((param_1 & 0xfe) != 0) {
    OSPanic(@12,0x4da,@61);
  }
  *(uint *)(iRam00000000 + 8) = *(uint *)(iRam00000000 + 8) & 0xfffffffb | (param_1 & 0xff) << 2;
  if ((param_2 & 0xfe) != 0) {
    OSPanic(@12,0x4db,@61);
  }
  *(uint *)(iRam00000000 + 8) = *(uint *)(iRam00000000 + 8) & 0xfffffff7 | (param_2 & 0xff) << 3;
  *(short *)(iRam00000000 + 2) = (short)*(undefined4 *)(iRam00000000 + 8);
  return;
}

void __GXWriteFifoIntReset(uint param_1,uint param_2)
{
  if ((param_1 & 0xfe) != 0) {
    OSPanic(@12,0x4f2,@61);
  }
  *(uint *)(iRam00000000 + 0x10) = *(uint *)(iRam00000000 + 0x10) & 0xfffffffe | param_1 & 0xff;
  if ((param_2 & 0xfe) != 0) {
    OSPanic(@12,0x4f3,@61);
  }
  *(uint *)(iRam00000000 + 0x10) =
       *(uint *)(iRam00000000 + 0x10) & 0xfffffffd | (param_2 & 0xff) << 1;
  *(short *)(iRam00000000 + 4) = (short)*(undefined4 *)(iRam00000000 + 0x10);
  return;
}

void __GXInsaneWatermark(void)
{
  int iVar1;
  
  iVar1 = GPFifo;
  *(int *)(GPFifo + 0xc) = *(int *)(GPFifo + 0x10) + 0x200;
  *(short *)(iRam00000000 + 0x28) = (short)*(undefined4 *)(iVar1 + 0xc);
  *(ushort *)(iRam00000000 + 0x2a) = (ushort)((uint)*(undefined4 *)(iVar1 + 0xc) >> 0x10) & 0x3fff;
  return;
}

void __GXCleanGPFifo(void)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 local_90 [33];
  
  iVar2 = GXGetGPFifo();
  iVar3 = GXGetCPUFifo();
  uVar4 = GXGetFifoBase(iVar2);
  iVar7 = 0x10;
  puVar5 = (undefined4 *)(iVar2 + -8);
  puVar6 = (undefined4 *)&stack0xffffff68;
  do {
    uVar1 = puVar5[3];
    puVar6[2] = puVar5[2];
    puVar6[3] = uVar1;
    iVar7 = iVar7 + -1;
    puVar5 = puVar5 + 2;
    puVar6 = puVar6 + 2;
  } while (iVar7 != 0);
  GXInitFifoPtrs(local_90,uVar4,uVar4);
  GXSetGPFifo(local_90);
  if (iVar3 == iVar2) {
    GXSetCPUFifo(local_90);
  }
  GXInitFifoPtrs(iVar2,uVar4,uVar4);
  GXSetGPFifo(iVar2);
  if (iVar3 == iVar2) {
    GXSetCPUFifo(iVar3);
  }
  return;
}

undefined4 GXSetCurrentGXThread(void)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = OSDisableInterrupts();
  uVar1 = __GXCurrentThread;
  if (GXOverflowSuspendInProgress != 0) {
    OSPanic(@12,0x546,@110);
  }
  __GXCurrentThread = OSGetCurrentThread();
  OSRestoreInterrupts(uVar2);
  return uVar1;
}

undefined4 GXGetCurrentGXThread(void)
{
  return __GXCurrentThread;
}

undefined4 GXGetCPUFifo(void)
{
  return CPUFifo;
}

undefined4 GXGetGPFifo(void)
{
  return GPFifo;
}

undefined4 GXGetOverflowCount(void)
{
  return __GXOverflowCount;
}

undefined4 GXResetOverflowCount(void)
{
  undefined4 uVar1;
  
  uVar1 = __GXOverflowCount;
  __GXOverflowCount = 0;
  return uVar1;
}

undefined * GXRedirectWriteGatherPipe(uint param_1)
{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = OSDisableInterrupts();
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@12,0x5ba,@123);
  }
  if ((param_1 & 0x1f) != 0) {
    OSPanic(@12,0x5bb,@124);
  }
  if (IsWGPipeRedirected != 0) {
    OSPanic(@12,0x5bd,@125);
  }
  IsWGPipeRedirected = 1;
  GXFlush();
  do {
    uVar2 = PPCMfwpar();
  } while ((uVar2 & 1) != 0);
  OSUncachedToPhysical(&DAT_cc008000);
  PPCMtwpar();
  if (CPGPLinked != '\0') {
    __GXFifoLink(0);
    __GXWriteFifoIntEnable(0,0);
  }
  uVar3 = OSPhysicalToCached(*(uint *)(iRam00000000 + 0x14) & 0xfbffffff);
  *(undefined4 *)(CPUFifo + 0x18) = uVar3;
  *(undefined4 *)(iRam00000000 + 0xc) = 0;
  *(undefined4 *)(iRam00000000 + 0x10) = 0x4000000;
  if ((param_1 >> 5 & 0x1e00000) != 0) {
    OSPanic(@12,0x5dc,@61);
  }
  *(uint *)(iRam00000000 + 0x14) = param_1 & 0x3bffffe0;
  sync(0);
  OSRestoreInterrupts(uVar1);
  return &DAT_cc008000;
}

void GXRestoreWriteGatherPipe(void)
{
  undefined4 uVar1;
  uint uVar2;
  
  if (IsWGPipeRedirected == 0) {
    OSPanic(@12,0x5f5,@138);
  }
  IsWGPipeRedirected = 0;
  uVar1 = OSDisableInterrupts();
  for (uVar2 = 0; uVar2 < 0x1f; uVar2 = uVar2 + 1) {
    DAT_cc008000 = 0;
  }
  PPCSync();
  do {
    uVar2 = PPCMfwpar();
  } while ((uVar2 & 1) != 0);
  OSUncachedToPhysical(&DAT_cc008000);
  PPCMtwpar();
  *(uint *)(iRam00000000 + 0xc) = *CPUFifo & 0x3fffffff;
  *(uint *)(iRam00000000 + 0x10) = CPUFifo[1] & 0x3fffffff;
  if (((CPUFifo[6] & 0x3fffffff) >> 5 & 0x7e00000) != 0) {
    OSPanic(@12,0x60f,@61);
  }
  *(uint *)(iRam00000000 + 0x14) = CPUFifo[6] & 0x3bffffe0;
  if (CPGPLinked != '\0') {
    __GXWriteFifoIntReset(1,1);
    __GXWriteFifoIntEnable(1,0);
    __GXFifoLink(1);
  }
  sync(0);
  OSRestoreInterrupts(uVar1);
  return;
}
