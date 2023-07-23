void OSGetTime(void)
{
  return;
}

void OSGetTick(void)
{
  return;
}

void __SetTime(void)
{
  return;
}

void __OSSetTime(int param_1,uint param_2)
{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  undefined8 uVar4;
  
  uVar1 = OSDisableInterrupts();
  uVar4 = OSGetTime();
  uVar2 = (uint)uVar4 - param_2;
  bVar3 = CARRY4(_DAT_800030dc,uVar2);
  _DAT_800030dc = _DAT_800030dc + uVar2;
  _DAT_800030d8 =
       _DAT_800030d8 + ((int)((ulonglong)uVar4 >> 0x20) - (param_1 + (uint)((uint)uVar4 < param_2)))
       + (uint)bVar3;
  __SetTime(param_1,param_2);
  EXIProbeReset();
  OSRestoreInterrupts(uVar1);
  return;
}

longlong __OSGetSystemTime(void)
{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  uVar2 = OSDisableInterrupts();
  lVar3 = OSGetTime();
  lVar1 = CONCAT44(_DAT_800030d8,_DAT_800030dc);
  OSRestoreInterrupts(uVar2);
  return lVar3 + lVar1;
}

undefined8 __OSTimeToSystemTime(int param_1,uint param_2)
{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  
  uVar1 = OSDisableInterrupts();
  bVar3 = CARRY4(_DAT_800030dc,param_2);
  iVar2 = _DAT_800030dc + param_2;
  param_1 = _DAT_800030d8 + param_1;
  OSRestoreInterrupts(uVar1);
  return CONCAT44(param_1 + (uint)bVar3,iVar2);
}

void __OSSetTick(void)
{
  return;
}

undefined4 IsLeapYear(uint param_1)
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 == (((int)param_1 >> 2) + (uint)((int)param_1 < 0 && (param_1 & 3) != 0)) * 4) &&
      ((int)param_1 % 100 != 0)) || ((int)param_1 % 400 == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

undefined4 GetYearDays(undefined4 param_1,int param_2)
{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = IsLeapYear(param_1);
  if (iVar1 == 0) {
    puVar2 = YearDays;
  }
  else {
    puVar2 = &LeapYearDays;
  }
  return *(undefined4 *)(puVar2 + param_2 * 4);
}

int GetLeapDays(int param_1)
{
  uint uVar1;
  int iVar2;
  
  if (param_1 < 0) {
    OSPanic(s_OOSTime.c_00010b0f + 1,0x11e,@11);
  }
  if (param_1 < 1) {
    iVar2 = 0;
  }
  else {
    uVar1 = param_1 + 3;
    iVar2 = (param_1 + -1) / 400 +
            ((((int)uVar1 >> 2) + (uint)((int)uVar1 < 0 && (uVar1 & 3) != 0)) - (param_1 + -1) / 100
            );
  }
  return iVar2;
}

void GetDates(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar3 = YearDays;
  if (param_1 < 0) {
    OSPanic(s_OOSTime.c_00010b0f + 1,0x137,@23);
  }
  *(int *)(param_2 + 0x18) = (param_1 + 6) % 7;
  iVar2 = param_1 / 0x16d;
  while( true ) {
    iVar1 = GetLeapDays(iVar2);
    iVar1 = iVar2 * 0x16d + iVar1;
    if (iVar1 <= param_1) break;
    iVar2 = iVar2 + -1;
  }
  param_1 = param_1 - iVar1;
  *(int *)(param_2 + 0x14) = iVar2;
  *(int *)(param_2 + 0x1c) = param_1;
  iVar2 = IsLeapYear(iVar2);
  if (iVar2 != 0) {
    puVar3 = &LeapYearDays;
  }
  iVar2 = 0xc;
  do {
    iVar2 = iVar2 + -1;
  } while (param_1 < *(int *)(puVar3 + iVar2 * 4));
  *(int *)(param_2 + 0x10) = iVar2;
  *(int *)(param_2 + 0xc) = (param_1 - *(int *)(puVar3 + iVar2 * 4)) + 1;
  return;
}

void OSTicksToCalendarTime(int param_1,uint param_2,int *param_3)
{
  uint uVar1;
  uint uVar2;
  int extraout_r4;
  int extraout_r4_00;
  int extraout_r4_01;
  int extraout_r4_02;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  
  lVar6 = __mod2i(param_1,param_2,0,_DAT_800000f8 >> 2);
  uVar2 = (uint)((ulonglong)lVar6 >> 0x20);
  lVar8 = lVar6;
  if ((uVar2 ^ 0x80000000) < 0x80000000) {
    uVar1 = _DAT_800000f8 >> 2;
    lVar8 = lVar6 + (ulonglong)uVar1;
    if ((uVar2 + CARRY4((uint)lVar6,uVar1) ^ 0x80000000) < 0x80000000) {
      OSPanic(s_OOSTime.c_00010b0f + 1,0x164,@29);
      lVar8 = lVar6 + (ulonglong)uVar1;
    }
  }
  iVar5 = (int)((ulonglong)lVar8 >> 0x20);
  uVar2 = (uint)lVar8;
  uVar7 = __div2i((int)((ulonglong)(lVar8 * 8) >> 0x20),(int)(lVar8 * 8),0,_DAT_800000f8 / 500000);
  __mod2i((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0,1000);
  param_3[9] = extraout_r4;
  uVar7 = __div2i(iVar5,uVar2,0,_DAT_800000f8 / 4000);
  __mod2i((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0,1000);
  param_3[8] = extraout_r4_00;
  if (param_3[9] < 0) {
    OSPanic(s_OOSTime.c_00010b0f + 1,0x168,@30);
  }
  if (param_3[8] < 0) {
    OSPanic(s_OOSTime.c_00010b0f + 1,0x169,@31);
  }
  iVar4 = param_2 - uVar2;
  param_1 = param_1 - (iVar5 + (uint)(param_2 < uVar2));
  lVar8 = __mod2i(param_1,iVar4,0,_DAT_800000f8 >> 2);
  if (lVar8 != 0) {
    OSPanic(s_OOSTime.c_00010b0f + 1,0x16c,@32);
  }
  uVar7 = __div2i(param_1,iVar4,0,_DAT_800000f8 >> 2);
  uVar7 = __div2i((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0,0x15180);
  if (0x7fffffff < ((int)((ulonglong)uVar7 >> 0x20) + (uint)(0xfff4da8a < (uint)uVar7) ^ 0x80000000)
     ) {
    uVar7 = __div2i(param_1,iVar4,0,_DAT_800000f8 >> 2);
    lVar8 = __div2i((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0,0x15180);
    uVar2 = (uint)((ulonglong)(lVar8 + 0xb2575) >> 0x20) ^ 0x80000000;
    if (uVar2 < 0x80000001 && (uint)(0x7fffffff < (uint)(lVar8 + 0xb2575)) <= 0x80000000 - uVar2)
    goto LAB_00010704;
  }
  OSPanic(s_OOSTime.c_00010b0f + 1,0x170,@33);
LAB_00010704:
  uVar7 = __div2i(param_1,iVar4,0,_DAT_800000f8 >> 2);
  __div2i((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0,0x15180);
  iVar3 = extraout_r4_01 + 0xb2575;
  uVar7 = __div2i(param_1,iVar4,0,_DAT_800000f8 >> 2);
  __mod2i((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0,0x15180);
  iVar5 = extraout_r4_02;
  if (extraout_r4_02 < 0) {
    iVar3 = extraout_r4_01 + 0xb2574;
    iVar5 = extraout_r4_02 + 0x15180;
    if (iVar5 < 0) {
      OSPanic(s_OOSTime.c_00010b0f + 1,0x177,@34);
    }
  }
  GetDates(iVar3,param_3);
  param_3[2] = iVar5 / 0xe10;
  param_3[1] = (iVar5 / 0x3c) % 0x3c;
  *param_3 = iVar5 % 0x3c;
  return;
}

longlong OSCalendarTimeToTicks(uint *param_1)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  longlong lVar17;
  
  iVar16 = (int)param_1[4] / 0xc;
  iVar15 = param_1[4] + iVar16 * -0xc;
  if (iVar15 < 0) {
    iVar15 = iVar15 + 0xc;
    iVar16 = iVar16 + -1;
  }
  if (((0 < iVar16) || ((int)(param_1[5] + iVar16) < 0)) &&
     ((iVar16 < 1 || (0x7fffffff - iVar16 < (int)param_1[5])))) {
    OSPanic(s_OOSTime.c_00010b0f + 1,0x19c,@38);
  }
  uVar14 = param_1[5] + iVar16;
  iVar15 = GetYearDays(uVar14,iVar15);
  iVar16 = GetLeapDays(uVar14);
  uVar4 = iVar16 + iVar15 + param_1[3] + -1;
  uVar8 = uVar14 * 0x1e13380 + uVar4 * 0x15180;
  uVar5 = param_1[2];
  uVar9 = uVar5 * 0xe10 + uVar8;
  uVar6 = param_1[1];
  uVar2 = uVar6 * 0x3c + uVar9;
  uVar1 = *param_1;
  uVar3 = uVar1 + uVar2;
  uVar13 = uVar3 + 0x4e1e4080;
  uVar11 = param_1[9];
  uVar7 = _DAT_800000f8 / 500000;
  lVar17 = __div2i(((int)uVar11 >> 0x1f) * uVar7 +
                   (int)((ulonglong)uVar11 * (ulonglong)uVar7 >> 0x20),uVar11 * uVar7,0,8);
  uVar7 = _DAT_800000f8 >> 2;
  uVar12 = uVar13 * uVar7;
  uVar10 = param_1[8];
  uVar11 = _DAT_800000f8 / 4000;
  return lVar17 + CONCAT44((((int)uVar1 >> 0x1f) +
                            ((int)uVar6 >> 0x1f) * 0x3c + (int)((ulonglong)uVar6 * 0x3c >> 0x20) +
                            ((int)uVar5 >> 0x1f) * 0xe10 + (int)((ulonglong)uVar5 * 0xe10 >> 0x20) +
                            ((int)uVar14 >> 0x1f) * 0x1e13380 +
                            (int)((ulonglong)uVar14 * 0x1e13380 >> 0x20) +
                            ((int)uVar4 >> 0x1f) * 0x15180 +
                            (int)((ulonglong)uVar4 * 0x15180 >> 0x20) +
                            (uint)CARRY4(uVar14 * 0x1e13380,uVar4 * 0x15180) +
                            (uint)CARRY4(uVar5 * 0xe10,uVar8) + (uint)CARRY4(uVar6 * 0x3c,uVar9) +
                            (uint)CARRY4(uVar1,uVar2) + -0xf + (uint)(0xb1e1bf7f < uVar3)) * uVar7 +
                           (int)((ulonglong)uVar13 * (ulonglong)uVar7 >> 0x20) +
                           ((int)uVar10 >> 0x1f) * uVar11 +
                           (int)((ulonglong)uVar10 * (ulonglong)uVar11 >> 0x20) +
                           (uint)CARRY4(uVar12,uVar10 * uVar11),uVar12 + uVar10 * uVar11);
}
