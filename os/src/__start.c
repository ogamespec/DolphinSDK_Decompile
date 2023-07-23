void __check_pad3(void)
{
  if ((_DAT_800030e4 & 0xeef) == 0xeef) {
    OSResetSystem(0,0,0);
  }
  return;
}

void __start(void)
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined8 uVar7;
  
  __init_registers();
  __init_hardware();
  uVar7 = __init_data();
  _DAT_80000044 = 0;
  if (_DAT_800000f4 != 0) {
    uVar2 = 0;
    if (*(int *)(_DAT_800000f4 + 0xc) != 2) {
      if (*(int *)(_DAT_800000f4 + 0xc) != 3) goto LAB_000100ac;
      uVar2 = 1;
    }
    InitMetroTRK((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,uVar2);
  }
LAB_000100ac:
  iVar1 = _DAT_800000f4;
  if (_DAT_800000f4 != 0) {
    if (*(int *)(_DAT_800000f4 + 8) != 0) {
      piVar3 = (int *)(_DAT_800000f4 + *(int *)(_DAT_800000f4 + 8));
      iVar4 = *piVar3;
      if (iVar4 != 0) {
        piVar5 = piVar3 + 1;
        iVar6 = iVar4;
        do {
          piVar3 = piVar3 + 1;
          *piVar3 = *piVar3 + iVar1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        _DAT_80000034 = (uint)piVar5 & 0xffffffe0;
        goto LAB_00010114;
      }
    }
  }
  iVar4 = 0;
  piVar5 = (int *)0x0;
LAB_00010114:
  DBInit();
  OSInit();
  if (((_DAT_800030e6 & 0x8000) == 0) || ((_DAT_800030e6 & 0x7fff) == 1)) {
    __check_pad3();
  }
  __init_user();
  iVar1 = main(iVar4,piVar5);
                    /* WARNING: Subroutine does not return */
  exit(iVar1);
}

void __copy_rom_section(void *param_1,void *param_2,size_t param_3)
{
  if ((param_3 != 0) && (param_1 != param_2)) {
    memcpy(param_1,param_2,param_3);
    __flush_cache(param_1,param_3);
  }
  return;
}

void __init_bss_section(void *param_1,size_t param_2)
{
  if (param_2 != 0) {
    memset(param_1,0,param_2);
  }
  return;
}

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __init_registers()
             undefined         r3:1           <RETURN>
                             __init_registers                                XREF[1]:     __start:00010040(c)  
        000101f4 3c 20 00 01     lis        r1,0x1
        000101f8 60 21 10 00     ori        r1,r1,0x1000
        000101fc 3c 40 00 01     lis        r2,0x1
        00010200 60 42 10 20     ori        r2,r2,0x1020
        00010204 3d a0 00 01     lis        r13,0x1
        00010208 61 ad 10 1c     ori        r13,r13,0x101c
        0001020c 4e 80 00 20     blr

void __init_data(void)
{
  undefined4 *puVar1;
  
  for (puVar1 = (undefined4 *)&_rom_copy_info; puVar1[2] != 0; puVar1 = puVar1 + 3) {
    __copy_rom_section(puVar1[1],*puVar1,puVar1[2]);
  }
  for (puVar1 = (undefined4 *)&_bss_init_info; puVar1[1] != 0; puVar1 = puVar1 + 2) {
    __init_bss_section(*puVar1,puVar1[1]);
  }
  return;
}
