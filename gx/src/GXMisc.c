void GXSetMisc(int param_1,int param_2)
{
  if (param_1 == 1) {
    puRam00000000[2] = (ushort)param_2;
    *puRam00000000 = (ushort)(puRam00000000[2] == 0);
    puRam00000000[1] = 1;
    if (puRam00000000[2] != 0) {
      *(uint *)(puRam00000000 + 0x27a) = *(uint *)(puRam00000000 + 0x27a) | 8;
    }
  }
  else {
    if (param_1 < 1) {
      if (-1 < param_1) {
        return;
      }
    }
    else if (param_1 < 3) {
      if (*(char *)(puRam00000000 + 0x278) != '\0') {
        OSPanic(...data.0,0xd2,@15);
      }
      *(char *)((int)puRam00000000 + 0x4f1) = '\x01' - (param_2 == 0);
      return;
    }
    OSReport(@16,param_1,param_2);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXFlush(void)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0xfd,@20);
  }
  if (*(int *)(iRam00000000 + 0x4f4) != 0) {
    __GXSetDirtyState();
  }
  _DAT_cc008000 = 0;
  PPCSync();
  return;
}

void GXResetWriteGatherPipe(void)
{
  uint uVar1;
  
  do {
    uVar1 = PPCMfwpar();
  } while ((uVar1 & 1) != 0);
  OSUncachedToPhysical(&DAT_cc008000);
  PPCMtwpar();
  return;
}

void __GXAbort(void)
{
  *(undefined4 *)(iRam00000000 + 0x18) = 1;
  __GXAbortWait(200);
  *(undefined4 *)(iRam00000000 + 0x18) = 0;
  __GXAbortWait(0x14);
  return;
}

void __GXAbortWait(uint param_1)
{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = OSGetTime();
  do {
    uVar3 = OSGetTime();
    uVar1 = (int)((ulonglong)uVar3 >> 0x20) -
            ((int)((ulonglong)uVar2 >> 0x20) + (uint)((uint)uVar3 < (uint)uVar2)) ^ 0x80000000;
  } while (uVar1 < 0x80000001 &&
           (uint)(param_1 >> 2 < (uint)uVar3 - (uint)uVar2) <= 0x80000000 - uVar1);
  return;
}

void GXAbortFrame(void)
{
  __GXAbort();
  __GXCleanGPFifo();
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010344) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetDrawSync(uint param_1)
{
  undefined4 uVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x17b,@35);
  }
  uVar1 = OSDisableInterrupts();
  *(uint *)(iRam00000000 + 0xde8) = param_1 & 0xffff | 0x48000000;
  _DAT_cc008000 = param_1 & 0xffff | 0x47000000;
  *(uint *)(iRam00000000 + 0xde4) = _DAT_cc008000;
  GXFlush();
  OSRestoreInterrupts(uVar1);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

undefined2 GXReadDrawSync(void)
{
  return *(undefined2 *)(iRam00000000 + 0xe);
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetDrawDone(void)
{
  undefined4 uVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x1b5,@39);
  }
  uVar1 = OSDisableInterrupts();
  _DAT_cc008000 = 0x45000002;
  *(undefined4 *)(iRam00000000 + 0xddc) = 0x45000002;
  GXFlush();
  DrawDone = 0;
  OSRestoreInterrupts(uVar1);
  return;
}

void GXWaitDrawDone(void)
{
  undefined4 uVar1;
  
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x1e3,@45);
  }
  uVar1 = OSDisableInterrupts();
  while (DrawDone == '\0') {
    OSSleepThread(&FinishQueue);
  }
  OSRestoreInterrupts(uVar1);
  return;
}

void GXDrawDone(void)
{
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x203,@47);
  }
  GXSetDrawDone();
  GXWaitDrawDone();
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXPixModeSync(void)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x226,@49);
  }
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1dc);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1dc) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1dc);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXTexModeSync(void)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x23e,@51);
  }
  _DAT_cc008000 = 0x63000000;
  *(undefined4 *)(iRam00000000 + 0xe54) = 0x63000000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXBypass(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x254,@53);
  }
  _DAT_cc008000 = param_1;
  *(uint *)(iRam00000000 + (param_1 >> 0x16 & 0x3fc) + 0xcc8) = param_1;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

undefined2 __GXReadPEReg(int param_1)
{
  return *(undefined2 *)(iRam00000000 + param_1 * 2);
}

void GXPokeAlphaMode(int param_1,ushort param_2)
{
  *(ushort *)(iRam00000000 + 6) = (ushort)(param_1 << 8) | param_2 & 0xff;
  return;
}

void GXPokeAlphaRead(uint param_1)
{
  if ((param_1 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x282,@36);
  }
  *(ushort *)(iRam00000000 + 8) = (ushort)param_1 & 0xfffb | 4;
  return;
}

void GXPokeAlphaUpdate(uint param_1)
{
  ushort uVar1;
  
  uVar1 = *(ushort *)(iRam00000000 + 2);
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x28d,@36);
  }
  *(ushort *)(iRam00000000 + 2) = uVar1 & 0xffef | (ushort)(param_1 << 4) & 0xff0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x0001080c) */
/* WARNING: Removing unreachable block (ram,0x00010854) */
/* WARNING: Removing unreachable block (ram,0x00010894) */
void GXPokeBlendMode(int param_1,uint param_2,uint param_3,uint param_4)
{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *(ushort *)(iRam00000000 + 2);
  uVar2 = 0;
  if ((param_1 == 1) || (param_1 == 3)) {
    uVar2 = 1;
  }
  if ((param_4 & 0xfffffff0) != 0) {
    OSPanic(...data.0,0x2a1,@36);
  }
  if ((param_2 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x2a2,@36);
  }
  if ((param_3 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x2a3,@36);
  }
  *(ushort *)(iRam00000000 + 2) =
       uVar1 & 0x1c | uVar2 | (ushort)(LZCOUNT(3 - param_1) << 6) & 0xf800 |
       (ushort)((uint)LZCOUNT(2 - param_1) >> 4) & 0xfffe | (ushort)(param_4 << 0xc) |
       (ushort)(param_2 << 8) | (ushort)(param_3 << 5);
  return;
}

void GXPokeColorUpdate(uint param_1)
{
  ushort uVar1;
  
  uVar1 = *(ushort *)(iRam00000000 + 2);
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x2af,@36);
  }
  *(ushort *)(iRam00000000 + 2) = uVar1 & 0xfff7 | (ushort)(param_1 << 3) & 0x7f8;
  return;
}

/* WARNING: Removing unreachable block (ram,0x000109f4) */
void GXPokeDstAlpha(uint param_1,ushort param_2)
{
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x2b9,@36);
  }
  *(ushort *)(iRam00000000 + 4) = param_2 & 0xff | (ushort)(param_1 << 8);
  return;
}

void GXPokeDither(uint param_1)
{
  ushort uVar1;
  
  uVar1 = *(ushort *)(iRam00000000 + 2);
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x2c3,@36);
  }
  *(ushort *)(iRam00000000 + 2) = uVar1 & 0xfffb | (ushort)(param_1 << 2) & 0x3fc;
  return;
}

void GXPokeZMode(ushort param_1,uint param_2,uint param_3)
{
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x2cc,@36);
  }
  if ((param_2 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x2cd,@36);
  }
  if ((param_3 & 0xfe) != 0) {
    OSPanic(...data.0,0x2ce,@36);
  }
  *puRam00000000 =
       (param_1 & 0xf1 | (ushort)(param_2 << 1)) & 0xffef | (ushort)(param_3 << 4) & 0xff0;
  return;
}

void GXPeekARGB(uint param_1,uint param_2,undefined4 *param_3)
{
  uint uVar1;
  
  uVar1 = OSPhysicalToUncached(0x8000000);
  if ((param_1 & 0xfc00) != 0) {
    OSPanic(...data.0,0x2e5,@36);
  }
  if ((param_2 & 0xfc00) != 0) {
    OSPanic(...data.0,0x2e6,@36);
  }
  *param_3 = *(undefined4 *)
              (((uVar1 & 0xfffff003 | (param_1 & 0xffff) << 2) & 0xffc00fff |
               (param_2 & 0xffff) << 0xc) & 0xff3fffff);
  return;
}

void GXPokeARGB(uint param_1,uint param_2,undefined4 param_3)
{
  uint uVar1;
  
  uVar1 = OSPhysicalToUncached(0x8000000);
  if ((param_1 & 0xfc00) != 0) {
    OSPanic(...data.0,0x2ef,@36);
  }
  if ((param_2 & 0xfc00) != 0) {
    OSPanic(...data.0,0x2f0,@36);
  }
  *(undefined4 *)
   (((uVar1 & 0xfffff003 | (param_1 & 0xffff) << 2) & 0xffc00fff | (param_2 & 0xffff) << 0xc) &
   0xff3fffff) = param_3;
  return;
}

void GXPeekZ(uint param_1,uint param_2,undefined4 *param_3)
{
  uint uVar1;
  
  uVar1 = OSPhysicalToUncached(0x8000000);
  if ((param_1 & 0xfc00) != 0) {
    OSPanic(...data.0,0x2f9,@36);
  }
  if ((param_2 & 0xfc00) != 0) {
    OSPanic(...data.0,0x2fa,@36);
  }
  *param_3 = *(undefined4 *)
              (((uVar1 & 0xfffff003 | (param_1 & 0xffff) << 2) & 0xffc00fff |
               (param_2 & 0xffff) << 0xc) & 0xff3fffff | 0x400000);
  return;
}

void GXPokeZ(uint param_1,uint param_2,undefined4 param_3)
{
  uint uVar1;
  
  uVar1 = OSPhysicalToUncached(0x8000000);
  if ((param_1 & 0xfc00) != 0) {
    OSPanic(...data.0,0x303,@36);
  }
  if ((param_2 & 0xfc00) != 0) {
    OSPanic(...data.0,0x304,@36);
  }
  *(undefined4 *)
   (((uVar1 & 0xfffff003 | (param_1 & 0xffff) << 2) & 0xffc00fff | (param_2 & 0xffff) << 0xc) &
    0xff3fffff | 0x400000) = param_3;
  return;
}

undefined4 GXSetDrawSyncCallback(undefined4 param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = TokenCB;
  uVar2 = OSDisableInterrupts();
  TokenCB = param_1;
  OSRestoreInterrupts(uVar2);
  return uVar1;
}

void GXTokenInterruptHandler(undefined4 param_1,undefined4 param_2)
{
  undefined2 uVar1;
  undefined auStack_2d0 [712];
  
  uVar1 = *(undefined2 *)(iRam00000000 + 0xe);
  if (TokenCB != (code *)0x0) {
    OSClearContext(auStack_2d0);
    OSSetCurrentContext(auStack_2d0);
    (*TokenCB)(uVar1);
    OSClearContext(auStack_2d0);
    OSSetCurrentContext(param_2);
  }
  *(ushort *)(iRam00000000 + 10) = *(ushort *)(iRam00000000 + 10) & 0xfffb | 4;
  return;
}

undefined4 GXSetDrawDoneCallback(undefined4 param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DrawDoneCB;
  uVar2 = OSDisableInterrupts();
  DrawDoneCB = param_1;
  OSRestoreInterrupts(uVar2);
  return uVar1;
}

void GXFinishInterruptHandler(undefined4 param_1,undefined4 param_2)
{
  undefined auStack_2d0 [716];
  
  *(ushort *)(iRam00000000 + 10) = *(ushort *)(iRam00000000 + 10) & 0xfff7 | 8;
  DrawDone = 1;
  if (DrawDoneCB != (code *)0x0) {
    OSClearContext(auStack_2d0);
    OSSetCurrentContext(auStack_2d0);
    (*DrawDoneCB)();
    OSClearContext(auStack_2d0);
    OSSetCurrentContext(param_2);
  }
  OSWakeupThread(&FinishQueue);
  return;
}

void __GXPEInit(void)
{
  __OSSetInterruptHandler(0x12,GXTokenInterruptHandler);
  __OSSetInterruptHandler(0x13,GXFinishInterruptHandler);
  OSInitThreadQueue(&FinishQueue);
  __OSUnmaskInterrupts(0x2000);
  __OSUnmaskInterrupts(0x1000);
  *(ushort *)(iRam00000000 + 10) = *(ushort *)(iRam00000000 + 10) & 0xfff0 | 0xf;
  return;
}

uint GXCompressZ16(uint param_1,int param_2)
{
  uint unaff_r29;
  uint uVar1;
  uint uVar2;
  
  uVar2 = LZCOUNT(~(param_1 << 8));
  if (param_2 == 2) {
    if (7 < uVar2) {
      uVar2 = 7;
    }
    if (uVar2 == 7) {
      uVar1 = 4;
    }
    else {
      uVar1 = 10 - uVar2;
    }
    return uVar2 << 0xd | param_1 >> (uVar1 & 0x3f) & 0x1fff;
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return param_1 >> 8 & 0xffff;
    }
    if (-1 < param_2) {
      if (3 < uVar2) {
        uVar2 = 3;
      }
      if (uVar2 == 3) {
        uVar1 = 7;
      }
      else {
        uVar1 = 9 - uVar2;
      }
      return uVar2 << 0xe | param_1 >> (uVar1 & 0x3f) & 0x3fff;
    }
  }
  else if (param_2 < 4) {
    if (0xc < uVar2) {
      uVar2 = 0xc;
    }
    if (uVar2 == 0xc) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xb - uVar2;
    }
    return uVar2 << 0xc | param_1 >> (uVar1 & 0x3f) & 0xfff;
  }
  OSPanic(...data.0,0x3b9,@83);
  return unaff_r29;
}

uint GXDecompressZ16(uint param_1,int param_2)
{
  uint unaff_r27;
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 2) {
    uVar2 = param_1 >> 0xd & 7;
    if (uVar2 == 7) {
      uVar1 = 4;
    }
    else {
      uVar1 = 10 - uVar2;
    }
    return (-1 << (0x18 - uVar2 & 0x3f) | (param_1 & 0x1fff) << (uVar1 & 0x3f)) & 0xffffff;
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return (param_1 & 0xffff) << 8;
    }
    if (-1 < param_2) {
      uVar2 = param_1 >> 0xe & 3;
      if (uVar2 == 3) {
        uVar1 = 7;
      }
      else {
        uVar1 = 9 - uVar2;
      }
      return (-1 << (0x18 - uVar2 & 0x3f) | (param_1 & 0x3fff) << (uVar1 & 0x3f)) & 0xffffff;
    }
  }
  else if (param_2 < 4) {
    uVar2 = param_1 >> 0xc & 0xf;
    if (uVar2 == 0xc) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xb - uVar2;
    }
    return (-1 << (0x18 - uVar2 & 0x3f) | (param_1 & 0xfff) << (uVar1 & 0x3f)) & 0xffffff;
  }
  OSPanic(...data.0,0x3eb,@91);
  return unaff_r27;
}
