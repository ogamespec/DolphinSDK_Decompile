bool GetRTC(undefined4 *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined4 local_c [2];
  
  iVar1 = EXILock(0,1,0);
  if (iVar1 == 0) {
    bVar6 = false;
  }
  else {
    iVar1 = EXISelect(0,1,3);
    if (iVar1 == 0) {
      EXIUnlock(0);
      bVar6 = false;
    }
    else {
      local_c[0] = 0x20000000;
      iVar1 = EXIImm(0,local_c,4,1,0);
      iVar2 = EXISync(0);
      iVar3 = EXIImm(0,local_c,4,0,0);
      iVar4 = EXISync(0);
      iVar5 = EXIDeselect(0);
      EXIUnlock(0);
      *param_1 = local_c[0];
      bVar6 = (((iVar1 != 0 && iVar2 != 0) && iVar3 != 0) && iVar4 != 0) && iVar5 != 0;
    }
  }
  return bVar6;
}

undefined4 __OSGetRTC(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int local_10 [2];
  
  iVar3 = 0;
  while( true ) {
    if (0xf < iVar3) {
      return 0;
    }
    iVar1 = GetRTC(local_10);
    iVar2 = GetRTC(&local_14);
    if (iVar1 == 0 || iVar2 == 0) break;
    if (local_10[0] == local_14) {
      *param_1 = local_10[0];
      return 1;
    }
    iVar3 = iVar3 + 1;
  }
  return 0;
}

bool __OSSetRTC(undefined4 param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined4 local_10;
  undefined4 local_c [2];
  
  local_10 = param_1;
  iVar1 = EXILock(0,1,0);
  if (iVar1 == 0) {
    bVar6 = false;
  }
  else {
    iVar1 = EXISelect(0,1,3);
    if (iVar1 == 0) {
      EXIUnlock(0);
      bVar6 = false;
    }
    else {
      local_c[0] = 0xa0000000;
      iVar1 = EXIImm(0,local_c,4,1,0);
      iVar2 = EXISync(0);
      iVar3 = EXIImm(0,&local_10,4,1,0);
      iVar4 = EXISync(0);
      iVar5 = EXIDeselect(0);
      EXIUnlock(0);
      bVar6 = (((iVar1 != 0 && iVar2 != 0) && iVar3 != 0) && iVar4 != 0) && iVar5 != 0;
    }
  }
  return bVar6;
}

bool ReadSram(undefined4 param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined4 local_c;
  
  DCInvalidateRange(param_1,0x40);
  iVar1 = EXILock(0,1,0);
  if (iVar1 == 0) {
    bVar6 = false;
  }
  else {
    iVar1 = EXISelect(0,1,3);
    if (iVar1 == 0) {
      EXIUnlock(0);
      bVar6 = false;
    }
    else {
      local_c = 0x20000100;
      iVar1 = EXIImm(0,&local_c,4,1,0);
      iVar2 = EXISync(0);
      iVar3 = EXIDma(0,param_1,0x40,0,0);
      iVar4 = EXISync(0);
      iVar5 = EXIDeselect(0);
      EXIUnlock(0);
      bVar6 = (((iVar1 != 0 && iVar2 != 0) && iVar3 != 0) && iVar4 != 0) && iVar5 != 0;
    }
  }
  return bVar6;
}

void WriteSramCallback(void)
{
  if (Scb._72_4_ != 0) {
    OSPanic(@29,0xfc,@30);
  }
  Scb._76_4_ = WriteSram(Scb + Scb._64_4_,Scb._64_4_,0x40 - Scb._64_4_);
  if (Scb._76_4_ == 0) {
    OSPanic(@29,0x102,@31);
  }
  else {
    Scb._64_4_ = 0x40;
  }
  return;
}

bool WriteSram(undefined4 param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  uint local_c;
  
  iVar1 = EXILock(0,1,WriteSramCallback);
  if (iVar1 == 0) {
    bVar5 = false;
  }
  else {
    iVar1 = EXISelect(0,1,3);
    if (iVar1 == 0) {
      EXIUnlock(0);
      bVar5 = false;
    }
    else {
      local_c = param_2 * 0x40 + 0x100U | 0xa0000000;
      iVar1 = EXIImm(0,&local_c,4,1,0);
      iVar2 = EXISync(0);
      iVar3 = EXIImmEx(0,param_1,param_3,1);
      iVar4 = EXIDeselect(0);
      EXIUnlock(0);
      bVar5 = ((iVar1 != 0 && iVar2 != 0) && iVar3 != 0) && iVar4 != 0;
    }
  }
  return bVar5;
}

void __OSInitSram(void)
{
  Scb._68_4_ = 0;
  Scb._72_4_ = 0;
  Scb._76_4_ = ReadSram(Scb);
  if (Scb._76_4_ == 0) {
    OSPanic(@29,0x138,@31);
  }
  Scb._64_4_ = 0x40;
  return;
}

undefined1 * LockSram(int param_1)
{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = OSDisableInterrupts();
  if (Scb._72_4_ != 0) {
    OSPanic(@29,0x14c,@30);
  }
  if (Scb._72_4_ == 0) {
    Scb._72_4_ = 1;
    puVar2 = Scb + param_1;
    Scb._68_4_ = uVar1;
  }
  else {
    OSRestoreInterrupts(uVar1);
    puVar2 = (undefined1 *)0x0;
  }
  return puVar2;
}

void __OSLockSram(void)
{
  LockSram(0);
  return;
}

void __OSLockSramEx(void)
{
  LockSram(0x14);
  return;
}

undefined4 UnlockSram(int param_1,uint param_2)
{
  ushort *puVar1;
  
  if (Scb._72_4_ == 0) {
    OSPanic(@29,0x16e,@59);
  }
  if (param_1 != 0) {
    if (param_2 == 0) {
      if (2 < (Scb[19] & 3)) {
        Scb[19] = Scb[19] & 0xfc;
      }
      Scb._2_2_ = 0;
      Scb._0_2_ = 0;
      for (puVar1 = (ushort *)(Scb + 0xc); puVar1 < Scb + 0x14; puVar1 = puVar1 + 1) {
        Scb._0_2_ = Scb._0_2_ + *puVar1;
        Scb._2_2_ = Scb._2_2_ + ~*puVar1;
      }
    }
    if (param_2 < (uint)Scb._64_4_) {
      Scb._64_4_ = param_2;
    }
    Scb._76_4_ = WriteSram(Scb + Scb._64_4_,Scb._64_4_,0x40 - Scb._64_4_);
    if (Scb._76_4_ != 0) {
      Scb._64_4_ = 0x40;
    }
  }
  Scb._72_4_ = 0;
  OSRestoreInterrupts(Scb._68_4_);
  return Scb._76_4_;
}

void __OSUnlockSram(undefined4 param_1)
{
  UnlockSram(param_1,0);
  return;
}

void __OSUnlockSramEx(undefined4 param_1)
{
  UnlockSram(param_1,0x14);
  return;
}

undefined4 __OSSyncSram(void)
{
  return Scb._76_4_;
}

undefined4 __OSCheckSram(void)
{
  undefined4 uVar1;
  short sVar2;
  short sVar3;
  ushort *puVar4;
  
  if (Scb._72_4_ == 0) {
    OSPanic(@29,0x1bb,@59);
  }
  sVar2 = 0;
  sVar3 = 0;
  for (puVar4 = (ushort *)(Scb + 0xc); puVar4 < Scb + 0x14; puVar4 = puVar4 + 1) {
    sVar3 = sVar3 + *puVar4;
    sVar2 = sVar2 + ~*puVar4;
  }
  uVar1 = 0;
  if ((Scb._0_2_ == sVar3) && (Scb._2_2_ == sVar2)) {
    uVar1 = 1;
  }
  return uVar1;
}

bool __OSReadROM(undefined4 param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int local_14 [2];
  
  if (0x400 < param_2) {
    OSPanic(@29,0x1da,@74);
  }
  DCInvalidateRange(param_1,param_2);
  iVar1 = EXILock(0,1,0);
  if (iVar1 == 0) {
    bVar6 = false;
  }
  else {
    iVar1 = EXISelect(0,1,3);
    if (iVar1 == 0) {
      EXIUnlock(0);
      bVar6 = false;
    }
    else {
      local_14[0] = param_3 << 6;
      iVar1 = EXIImm(0,local_14,4,1,0);
      iVar2 = EXISync(0);
      iVar3 = EXIDma(0,param_1,param_2,0,0);
      iVar4 = EXISync(0);
      iVar5 = EXIDeselect(0);
      EXIUnlock(0);
      bVar6 = (((iVar1 != 0 && iVar2 != 0) && iVar3 != 0) && iVar4 != 0) && iVar5 != 0;
    }
  }
  return bVar6;
}

void __OSReadROMCallback(undefined4 param_1)
{
  undefined4 uVar1;
  
  EXIDeselect(param_1);
  EXIUnlock(param_1);
  uVar1 = Scb._80_4_;
  if (Scb._80_4_ != 0) {
    Scb._80_4_ = 0;
    (*(code *)uVar1)();
  }
  return;
}

bool __OSReadROMAsync(undefined4 param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int local_18 [2];
  
  if (0x400 < param_2) {
    OSPanic(@29,0x215,@74);
  }
  if (param_4 == 0) {
    OSPanic(@29,0x216,@83);
  }
  DCInvalidateRange(param_1,param_2);
  Scb._80_4_ = param_4;
  iVar1 = EXILock(0,1,0);
  if (iVar1 == 0) {
    bVar4 = false;
  }
  else {
    iVar1 = EXISelect(0,1,3);
    if (iVar1 == 0) {
      EXIUnlock(0);
      bVar4 = false;
    }
    else {
      local_18[0] = param_3 << 6;
      iVar1 = EXIImm(0,local_18,4,1,0);
      iVar2 = EXISync(0);
      iVar3 = EXIDma(0,param_1,param_2,0,__OSReadROMCallback);
      bVar4 = (iVar1 != 0 && iVar2 != 0) && iVar3 != 0;
    }
  }
  return bVar4;
}

bool OSGetSoundMode(void)
{
  byte bVar1;
  int iVar2;
  
  iVar2 = __OSLockSram();
  bVar1 = *(byte *)(iVar2 + 0x13);
  __OSUnlockSram(0);
  return (bVar1 & 4) != 0;
}

void OSSetSoundMode(uint param_1)
{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    OSPanic(@29,0x252,@88);
  }
  uVar1 = (param_1 & 1) << 2;
  iVar2 = __OSLockSram();
  if (uVar1 == (*(byte *)(iVar2 + 0x13) & 4)) {
    __OSUnlockSram(0);
  }
  else {
    *(byte *)(iVar2 + 0x13) = *(byte *)(iVar2 + 0x13) & 0xfb;
    *(byte *)(iVar2 + 0x13) = *(byte *)(iVar2 + 0x13) | (byte)uVar1;
    __OSUnlockSram(1);
  }
  return;
}

byte OSGetProgressiveMode(void)
{
  byte bVar1;
  int iVar2;
  
  iVar2 = __OSLockSram();
  bVar1 = *(byte *)(iVar2 + 0x13);
  __OSUnlockSram(0);
  return bVar1 >> 7;
}

void OSSetProgressiveMode(uint param_1)
{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    OSPanic(@29,0x287,@93);
  }
  uVar1 = (param_1 & 1) << 7;
  iVar2 = __OSLockSram();
  if (uVar1 == (*(byte *)(iVar2 + 0x13) & 0x80)) {
    __OSUnlockSram(0);
  }
  else {
    *(byte *)(iVar2 + 0x13) = *(byte *)(iVar2 + 0x13) & 0x7f;
    *(byte *)(iVar2 + 0x13) = *(byte *)(iVar2 + 0x13) | (byte)uVar1;
    __OSUnlockSram(1);
  }
  return;
}

byte OSGetVideoMode(void)
{
  int iVar1;
  byte bVar2;
  
  iVar1 = __OSLockSram();
  bVar2 = *(byte *)(iVar1 + 0x13) & 3;
  __OSUnlockSram(0);
  if (2 < bVar2) {
    bVar2 = 0;
  }
  return bVar2;
}

void OSSetVideoMode(uint param_1)
{
  int iVar1;
  
  if (2 < param_1) {
    OSPanic(@29,0x2c4,@102);
    param_1 = 0;
  }
  iVar1 = __OSLockSram();
  if (param_1 == (*(byte *)(iVar1 + 0x13) & 3)) {
    __OSUnlockSram(0);
  }
  else {
    *(byte *)(iVar1 + 0x13) = *(byte *)(iVar1 + 0x13) & 0xfc;
    *(byte *)(iVar1 + 0x13) = *(byte *)(iVar1 + 0x13) | (byte)param_1;
    __OSUnlockSram(1);
  }
  return;
}

undefined OSGetLanguage(void)
{
  undefined uVar1;
  int iVar2;
  
  iVar2 = __OSLockSram();
  uVar1 = *(undefined *)(iVar2 + 0x12);
  __OSUnlockSram(0);
  return uVar1;
}

void OSSetLanguage(char param_1)
{
  int iVar1;
  
  iVar1 = __OSLockSram();
  if (param_1 == *(char *)(iVar1 + 0x12)) {
    __OSUnlockSram(0);
  }
  else {
    *(char *)(iVar1 + 0x12) = param_1;
    __OSUnlockSram(1);
  }
  return;
}

byte __OSGetBootMode(void)
{
  byte bVar1;
  int iVar2;
  
  iVar2 = __OSLockSram();
  bVar1 = *(byte *)(iVar2 + 0x11);
  __OSUnlockSram(0);
  return bVar1 & 0x80;
}

void __OSSetBootMode(byte param_1)
{
  int iVar1;
  
  iVar1 = __OSLockSram();
  if ((param_1 & 0x80) == (*(byte *)(iVar1 + 0x11) & 0x80)) {
    __OSUnlockSram(0);
  }
  else {
    *(byte *)(iVar1 + 0x11) = *(byte *)(iVar1 + 0x11) & 0x7f;
    *(byte *)(iVar1 + 0x11) = *(byte *)(iVar1 + 0x11) | param_1 & 0x80;
    __OSUnlockSram(1);
  }
  return;
}

byte OSGetEuRgb60Mode(void)
{
  byte bVar1;
  int iVar2;
  
  iVar2 = __OSLockSram();
  bVar1 = *(byte *)(iVar2 + 0x11);
  __OSUnlockSram(0);
  return bVar1 >> 6 & 1;
}

void OSSetEuRgb60Mode(uint param_1)
{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 != 1)) {
    OSPanic(@29,0x368,@115);
  }
  uVar1 = (param_1 & 1) << 6;
  iVar2 = __OSLockSram();
  if (uVar1 == (*(byte *)(iVar2 + 0x11) & 0x40)) {
    __OSUnlockSram(0);
  }
  else {
    *(byte *)(iVar2 + 0x11) = *(byte *)(iVar2 + 0x11) & 0xbf;
    *(byte *)(iVar2 + 0x11) = *(byte *)(iVar2 + 0x11) | (byte)uVar1;
    __OSUnlockSram(1);
  }
  return;
}

undefined2 OSGetWirelessID(int param_1)
{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = __OSLockSramEx();
  uVar1 = *(undefined2 *)(iVar2 + param_1 * 2 + 0x1c);
  __OSUnlockSramEx(0);
  return uVar1;
}

void OSSetWirelessID(int param_1,short param_2)
{
  int iVar1;
  
  iVar1 = __OSLockSramEx();
  if (*(short *)(iVar1 + param_1 * 2 + 0x1c) == param_2) {
    __OSUnlockSramEx(0);
  }
  else {
    *(short *)(iVar1 + param_1 * 2 + 0x1c) = param_2;
    __OSUnlockSramEx(1);
  }
  return;
}
