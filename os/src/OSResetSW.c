void __OSResetSWInterruptHandler(void)
{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  
  HoldDown = __OSGetSystemTime();
  do {
    uVar3 = __OSGetSystemTime();
    uVar2 = (int)((ulonglong)uVar3 >> 0x20) -
            (HoldDown._0_4_ + (uint)((uint)uVar3 < HoldDown._4_4_)) ^ 0x80000000;
    if (0x7fffffff < uVar2 &&
        (uint)((uint)uVar3 - HoldDown._4_4_ < (_DAT_800000f8 / 500000) * 100 >> 3) <=
        uVar2 + 0x80000000) break;
  } while ((_DAT_cc003000 & 0x10000) == 0);
  uVar3 = HoldDown;
  if ((_DAT_cc003000 & 0x10000) == 0) {
    Down = 1;
    LastState = 1;
    __OSMaskInterrupts(0x200);
    pcVar1 = ResetCallback;
    uVar3 = HoldDown;
    if (ResetCallback != (code *)0x0) {
      ResetCallback = (code *)0x0;
      (*pcVar1)();
      uVar3 = HoldDown;
    }
  }
  HoldDown._0_4_ = (int)((ulonglong)uVar3 >> 0x20);
  HoldDown._4_4_ = (uint)uVar3;
  _DAT_cc003000 = 2;
  return;
}

undefined4 OSSetResetCallback(int param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = OSDisableInterrupts();
  uVar1 = ResetCallback;
  ResetCallback = param_1;
  if (param_1 == 0) {
    __OSMaskInterrupts(0x200);
  }
  else {
    _DAT_cc003000 = 2;
    __OSUnmaskInterrupts(0x200);
  }
  OSRestoreInterrupts(uVar2);
  return uVar1;
}

uint OSGetResetButtonState(void)
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_r4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  
  uVar1 = OSDisableInterrupts();
  uVar8 = __OSGetSystemTime();
  uVar2 = (uint)((ulonglong)uVar8 >> 0x20);
  uVar4 = (uint)uVar8;
  if ((uVar2 ^ 0x80000000) < 0x80000000) {
    OSPanic(...data.0,0x9b,@40);
  }
  if (((HoldUp._4_4_ | HoldUp._0_4_) != 0) &&
     ((uVar2 ^ 0x80000000) <= (HoldUp._0_4_ ^ 0x80000000) &&
      (uint)(HoldUp._4_4_ < uVar4) <= (HoldUp._0_4_ ^ 0x80000000) - (uVar2 ^ 0x80000000))) {
    OSPanic(...data.0,0x9c,@41);
  }
  if (((HoldDown._4_4_ | HoldDown._0_4_) != 0) &&
     ((uVar2 ^ 0x80000000) <= (HoldDown._0_4_ ^ 0x80000000) &&
      (uint)(HoldDown._4_4_ < uVar4) <= (HoldDown._0_4_ ^ 0x80000000) - (uVar2 ^ 0x80000000))) {
    OSPanic(...data.0,0x9d,@42);
  }
  if ((_DAT_cc003000 & 0x10000) == 0) {
    if (Down == 0) {
      Down = 1;
      uVar7 = (uint)((HoldUp._4_4_ | HoldUp._0_4_) != 0);
      HoldDown = uVar8;
      uVar8 = CONCAT44(HoldUp._0_4_,HoldUp._4_4_);
    }
    else if (((HoldUp._4_4_ | HoldUp._0_4_) == 0) &&
            (uVar7 = uVar2 - (HoldDown._0_4_ + (uVar4 < HoldDown._4_4_)) ^ 0x80000000,
            uVar7 < 0x80000001 &&
            (uint)((_DAT_800000f8 / 500000) * 100 >> 3 < uVar4 - HoldDown._4_4_) <=
            0x80000000 - uVar7)) {
      uVar7 = 0;
      HoldDown = CONCAT44(HoldDown._0_4_,HoldDown._4_4_);
      uVar8 = CONCAT44(HoldUp._0_4_,HoldUp._4_4_);
    }
    else {
      uVar7 = 1;
      HoldDown = CONCAT44(HoldDown._0_4_,HoldDown._4_4_);
      uVar8 = CONCAT44(HoldUp._0_4_,HoldUp._4_4_);
    }
  }
  else if (Down == 0) {
    if (((HoldUp._4_4_ | HoldUp._0_4_) == 0) ||
       (uVar7 = uVar2 - (HoldUp._0_4_ + (uVar4 < HoldUp._4_4_)) ^ 0x80000000,
       0x7fffffff < uVar7 &&
       (uint)(uVar4 - HoldUp._4_4_ < (_DAT_800000f8 / 4000) * 0x28) <= uVar7 + 0x80000000)) {
      uVar8 = 0;
      uVar7 = 0;
      HoldDown = CONCAT44(HoldDown._0_4_,HoldDown._4_4_);
    }
    else {
      uVar7 = 1;
      HoldDown = CONCAT44(HoldDown._0_4_,HoldDown._4_4_);
      uVar8 = CONCAT44(HoldUp._0_4_,HoldUp._4_4_);
    }
  }
  else {
    Down = 0;
    uVar7 = LastState;
    if (LastState == 0) {
      HoldDown = CONCAT44(HoldDown._0_4_,HoldDown._4_4_);
      uVar8 = 0;
    }
  }
  LastState = uVar7;
  HoldUp = uVar8;
  if ((DAT_800030e3 & 0x3f) != 0) {
    uVar5 = (DAT_800030e3 & 0x3f) * 0x3c;
    uVar3 = uVar5 * (_DAT_800000f8 >> 2);
    uVar6 = uRam00000000 + uVar3;
    uVar5 = uRam00000000 + (int)((ulonglong)uVar5 * (ulonglong)(_DAT_800000f8 >> 2) >> 0x20) +
            (uint)CARRY4(uRam00000000,uVar3);
    uVar3 = uVar5 ^ 0x80000000;
    if (uVar3 < (uVar2 ^ 0x80000000) || uVar3 - (uVar2 ^ 0x80000000) < (uint)(uVar6 < uVar4)) {
      uVar8 = __div2i(uVar2 - (uVar5 + (uVar4 < uVar6)),uVar4 - uVar6,0,_DAT_800000f8 >> 2);
      __div2i((int)((ulonglong)uVar8 >> 0x20),(int)uVar8,0,2);
      if ((extraout_r4 & 1) == 0) {
        uVar7 = 1;
      }
      else {
        uVar7 = 0;
      }
    }
  }
  OSRestoreInterrupts(uVar1);
  return uVar7;
}

void OSGetResetSwitchState(void)
{
  OSGetResetButtonState();
  return;
}

void __OSSetResetButtonTimer(byte param_1)
{
  undefined4 uVar1;
  
  uVar1 = OSDisableInterrupts();
  if (0x3f < param_1) {
    param_1 = 0x3f;
  }
  DAT_800030e3 = DAT_800030e3 & 0xc0 | param_1;
  OSRestoreInterrupts(uVar1);
  return;
}
