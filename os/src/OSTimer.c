undefined4 OSSetTimerCallback(undefined4 param_1)
{
  undefined4 uVar1;
  
  if (Timer._20_4_ == 0) {
    OSPanic(...data.0,0x7f,"OSSetTimerCallback(): timer is not initialized.");
  }
  uVar1 = Timer._0_4_;
  Timer._16_4_ = 1;
  Timer._0_4_ = param_1;
  return uVar1;
}

void OSInitTimer(uint param_1,undefined2 param_2)
{
  if (0x7fffffff < param_1) {
    OSPanic(...data.0,0x97,"OSInitTimer(): time param must be less than 0x80000000.");
  }
  Timer._16_4_ = 1;
  Timer._4_4_ = param_1;
  Timer._8_4_ = param_1;
  Timer._12_2_ = param_2;
  if (Timer._20_4_ == 0) {
    __OSSetExceptionHandler(8,DecrementerExceptionHandler);
    Timer._20_4_ = 1;
    Timer._0_4_ = 0;
    OSReport("Timer initialized\n");
  }
  return;
}

void OSStartTimer(void)
{
  undefined4 uVar1;
  
  if (Timer._20_4_ == 0) {
    OSPanic(...data.0,0xb8,"OSStartTimer(): timer is not initialized.");
  }
  uVar1 = OSDisableInterrupts();
  PPCMtdec(Timer._4_4_);
  Timer._16_4_ = 0;
  OSRestoreInterrupts(uVar1);
  return;
}

void OSStopTimer(void)
{
  undefined4 uVar1;
  
  if (Timer._20_4_ == 0) {
    OSPanic(...data.0,0xd0,"OSStopTimer(): timer is not initialized.");
  }
  uVar1 = OSDisableInterrupts();
  if (Timer._16_4_ == 0) {
    Timer._16_4_ = 1;
    Timer._4_4_ = PPCMfdec();
    if ((Timer._4_4_ & 0x80000000) != 0) {
      Timer._4_4_ = 0;
    }
  }
  OSRestoreInterrupts(uVar1);
  return;
}

void DecrementerExceptionCallback(undefined4 param_1,undefined4 param_2)
{
  undefined auStack_2d0 [712];
  
  OSClearContext(auStack_2d0);
  OSSetCurrentContext(auStack_2d0);
  if (Timer._16_4_ == 0) {
    if (Timer._12_2_ == 1) {
      PPCMtdec(Timer._8_4_);
    }
    if (Timer._12_2_ == 2) {
      Timer._16_4_ = 1;
    }
    if (Timer._0_4_ != 0) {
      (*(code *)Timer._0_4_)();
    }
  }
  OSClearContext(auStack_2d0);
  OSSetCurrentContext(param_2);
  OSLoadContext(param_2);
  return;
}

void DecrementerExceptionHandler
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  undefined4 in_r0;
  undefined4 unaff_r2;
  undefined4 in_r11;
  undefined4 in_r12;
  undefined4 unaff_r13;
  undefined4 unaff_r14;
  undefined4 unaff_r15;
  undefined4 unaff_r16;
  undefined4 unaff_r17;
  undefined4 unaff_r18;
  undefined4 unaff_r19;
  undefined4 unaff_r20;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  undefined4 unaff_r23;
  undefined4 unaff_r24;
  undefined4 unaff_r25;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  undefined4 in_spr391;
  undefined4 in_spr392;
  undefined4 in_spr393;
  undefined4 in_spr394;
  undefined4 in_spr395;
  undefined4 in_spr396;
  undefined4 in_spr397;
  
  *param_2 = in_r0;
  param_2[1] = register0x00000004;
  param_2[2] = unaff_r2;
  param_2[6] = param_4;
  param_2[7] = param_5;
  param_2[8] = param_6;
  param_2[9] = param_7;
  param_2[10] = param_8;
  param_2[0xb] = in_r11;
  param_2[0xc] = in_r12;
  param_2[0xd] = unaff_r13;
  param_2[0xe] = unaff_r14;
  param_2[0xf] = unaff_r15;
  param_2[0x10] = unaff_r16;
  param_2[0x11] = unaff_r17;
  param_2[0x12] = unaff_r18;
  param_2[0x13] = unaff_r19;
  param_2[0x14] = unaff_r20;
  param_2[0x15] = unaff_r21;
  param_2[0x16] = unaff_r22;
  param_2[0x17] = unaff_r23;
  param_2[0x18] = unaff_r24;
  param_2[0x19] = unaff_r25;
  param_2[0x1a] = unaff_r26;
  param_2[0x1b] = unaff_r27;
  param_2[0x1c] = unaff_r28;
  param_2[0x1d] = unaff_r29;
  param_2[0x1e] = unaff_r30;
  param_2[0x1f] = unaff_r31;
  param_2[0x6a] = in_spr391;
  param_2[0x6b] = in_spr392;
  param_2[0x6c] = in_spr393;
  param_2[0x6d] = in_spr394;
  param_2[0x6e] = in_spr395;
  param_2[0x6f] = in_spr396;
  param_2[0x70] = in_spr397;
  DecrementerExceptionCallback();
  return;
}
