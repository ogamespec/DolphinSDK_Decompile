void __get_clock(void)
{
  __OSGetSystemTime();
  return;
}

int __get_time(void)
{
  uint uVar1;
  int extraout_r4;
  undefined8 uVar2;
  
  uVar1 = _DAT_800000f8 >> 2;
  uVar2 = OSGetTime();
  __div2i((int)((ulonglong)uVar2 >> 0x20),(int)uVar2,0,uVar1);
  return extraout_r4 + -0x43e83e00;
}

undefined4 __to_gm_time(void)
{
  return 0;
}
