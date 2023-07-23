void OSReport(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
             char *param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
             undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)
{
  byte in_cr1;
  char *local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_14;
  undefined *local_10;
  char **local_c;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_58 = param_1;
    local_50 = param_2;
    local_48 = param_3;
    local_40 = param_4;
    local_38 = param_5;
    local_30 = param_6;
    local_28 = param_7;
    local_20 = param_8;
  }
  local_14 = 0x1000000;
  local_10 = &stack0x00000008;
  local_c = &local_78;
  local_78 = param_9;
  local_74 = param_10;
  local_70 = param_11;
  local_6c = param_12;
  local_68 = param_13;
  local_64 = param_14;
  local_60 = param_15;
  local_5c = param_16;
  vprintf(param_9,&local_14);
  return;
}

void OSPanic(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
            undefined4 param_9,undefined4 param_10,char *param_11,undefined4 param_12,
            undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)
{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  byte in_cr1;
  undefined4 local_88;
  undefined4 local_84;
  char *local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c;
  undefined *local_18;
  undefined4 *local_14;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_68 = param_1;
    local_60 = param_2;
    local_58 = param_3;
    local_50 = param_4;
    local_48 = param_5;
    local_40 = param_6;
    local_38 = param_7;
    local_30 = param_8;
  }
  local_88 = param_9;
  local_84 = param_10;
  local_80 = param_11;
  local_7c = param_12;
  local_78 = param_13;
  local_74 = param_14;
  local_70 = param_15;
  local_6c = param_16;
  local_28 = param_9;
  local_24 = param_10;
  OSDisableInterrupts();
  local_1c = 0x3000000;
  local_18 = &stack0x00000008;
  local_14 = &local_88;
  vprintf(param_11,&local_1c);
  OSReport(...data.0,local_28,local_24);
  OSReport(@11);
  uVar3 = 0;
  puVar2 = (undefined4 *)OSGetStackPointer();
  while (((puVar2 != (undefined4 *)0x0 && (puVar2 != (undefined4 *)0xffffffff)) &&
         (bVar1 = uVar3 < 0x10, uVar3 = uVar3 + 1, bVar1))) {
    OSReport(@12,puVar2,*puVar2,puVar2[1]);
    puVar2 = (undefined4 *)*puVar2;
  }
  PPCHalt();
  return;
}

undefined4 OSSetErrorHandler(ushort param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  if (0xf < param_1) {
    OSPanic(@14,0x98,@15);
  }
  uVar1 = *(undefined4 *)(__OSErrorTable + (uint)param_1 * 4);
  *(undefined4 *)(__OSErrorTable + (uint)param_1 * 4) = param_2;
  return uVar1;
}

void __OSUnhandledException(byte param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  undefined8 uVar1;
  
  if ((*(uint *)(param_2 + 0x19c) & 2) == 0) {
    OSReport(@30,param_1);
  }
  else {
    if (*(int *)(__OSErrorTable + (uint)param_1 * 4) != 0) {
      OSDisableScheduler();
      (**(code **)(__OSErrorTable + (uint)param_1 * 4))(param_1,param_2,param_3,param_4);
      OSEnableScheduler();
      __OSReschedule();
      OSLoadContext(param_2);
    }
    if (param_1 == 8) {
      OSLoadContext(param_2);
    }
    OSReport(@31,param_1);
  }
  OSReport(&@32,*(undefined4 *)(&__OSExceptionNames + (uint)param_1 * 4));
  OSReport(&@33);
  OSDumpContext(param_2);
  OSReport(@34,param_3,param_4);
  uVar1 = OSGetTime();
  OSReport(@35,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20),(int)uVar1);
  switch(param_1) {
  case 2:
    OSReport(@36,*(undefined4 *)(param_2 + 0x198),param_4);
    break;
  case 3:
    OSReport(@37,*(undefined4 *)(param_2 + 0x198));
    break;
  case 5:
    OSReport(@38,*(undefined4 *)(param_2 + 0x198),param_4);
    break;
  case 6:
    OSReport(@39,*(undefined4 *)(param_2 + 0x198),param_4);
    break;
  case 0xf:
    OSReport(&@33);
    OSReport(@40,_DAT_cc005030,_DAT_cc005032);
    OSReport(@41,_DAT_cc005020,_DAT_cc005022);
    OSReport(@42,_DAT_cc006014);
  }
  OSReport(@43,(int)uRam00000000._0_2_,uRam00000000);
  PPCHalt();
  return;
}
