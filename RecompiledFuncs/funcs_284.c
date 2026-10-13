#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080049C_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080049C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004AC: jal         0x8008CABC
    // 0x808004B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808004B4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808004B8: jal         0x8001210C
    // 0x808004BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x808004BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    // 0x808004C0: bne         $v0, $zero, L_808004F4
    if (ctx->r2 != 0) {
        // 0x808004C4: nop
    
            goto L_808004F4;
    }
    // 0x808004C4: nop

    // 0x808004C8: jal         0x800DC0C0
    // 0x808004CC: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x808004CC: nop

    after_2:
    // 0x808004D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808004E0: nop

    // 0x808004E4: bc1f        L_808004F4
    if (!c1cs) {
        // 0x808004E8: nop
    
            goto L_808004F4;
    }
    // 0x808004E8: nop

    // 0x808004EC: jal         0x8009FC34
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009FC34(rdram, ctx);
        goto after_3;
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808004F4:
    // 0x808004F4: jal         0x8001210C
    // 0x808004F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_4;
    // 0x808004F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_4:
    // 0x808004FC: bnel        $v0, $zero, L_80800534
    if (ctx->r2 != 0) {
        // 0x80800500: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_80800534;
    }
    goto skip_0;
    // 0x80800500: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_0:
    // 0x80800504: jal         0x800DC0C0
    // 0x80800508: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800508: nop

    after_5:
    // 0x8080050C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800510: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800514: nop

    // 0x80800518: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8080051C: nop

    // 0x80800520: bc1fl       L_80800534
    if (!c1cs) {
        // 0x80800524: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_80800534;
    }
    goto skip_1;
    // 0x80800524: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_1:
    // 0x80800528: jal         0x80800000
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bstntswim(rdram, ctx);
        goto after_6;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800530: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800534:
    // 0x80800534: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800538: jal         0x8008B348
    // 0x8080053C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x8080053C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800540: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800544: lui         $a2, 0x3F59
        ctx->r6 = S32(0X3F59 << 16);
            goto L_80800570;
    }
    // 0x80800544: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800548: lui         $a3, 0x3F93
    ctx->r7 = S32(0X3F93 << 16);
    // 0x8080054C: addiu       $t6, $zero, 0x3E80
    ctx->r14 = ADD32(0, 0X3E80);
    // 0x80800550: addiu       $t7, $zero, 0x3E80
    ctx->r15 = ADD32(0, 0X3E80);
    // 0x80800554: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800558: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080055C: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800560: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: jal         0x8009DEC0
    // 0x8080056C: addiu       $a1, $zero, 0x46F
    ctx->r5 = ADD32(0, 0X46F);
    func_8009DEC0(rdram, ctx);
        goto after_8;
    // 0x8080056C: addiu       $a1, $zero, 0x46F
    ctx->r5 = ADD32(0, 0X46F);
    after_8:
L_80800570:
    // 0x80800570: jal         0x8009EF10
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_9;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800578: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080057C: bne         $v0, $at, L_80800588
    if (ctx->r2 != ctx->r1) {
        // 0x80800580: addiu       $t8, $zero, 0x110
        ctx->r24 = ADD32(0, 0X110);
            goto L_80800588;
    }
    // 0x80800580: addiu       $t8, $zero, 0x110
    ctx->r24 = ADD32(0, 0X110);
    // 0x80800584: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80800588:
    // 0x80800588: jal         0x8008E35C
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_10;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800590: bne         $v0, $zero, L_8080059C
    if (ctx->r2 != 0) {
        // 0x80800594: addiu       $t9, $zero, 0x10C
        ctx->r25 = ADD32(0, 0X10C);
            goto L_8080059C;
    }
    // 0x80800594: addiu       $t9, $zero, 0x10C
    ctx->r25 = ADD32(0, 0X10C);
    // 0x80800598: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8080059C:
    // 0x8080059C: jal         0x80083F90
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bstnt_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808005A4: beq         $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x808005A8: addiu       $t0, $zero, 0x10E
        ctx->r8 = ADD32(0, 0X10E);
            goto L_808005B0;
    }
    // 0x808005A8: addiu       $t0, $zero, 0x10E
    ctx->r8 = ADD32(0, 0X10E);
    // 0x808005AC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_808005B0:
    // 0x808005B0: jal         0x80096500
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096500(rdram, ctx);
        goto after_12;
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808005B8: beq         $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x808005BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D4;
    }
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: jal         0x80091A58
    // 0x808005C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_13;
    // 0x808005C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
    // 0x808005C8: beq         $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x808005CC: addiu       $t1, $zero, 0x107
        ctx->r9 = ADD32(0, 0X107);
            goto L_808005D4;
    }
    // 0x808005CC: addiu       $t1, $zero, 0x107
    ctx->r9 = ADD32(0, 0X107);
    // 0x808005D0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_808005D4:
    // 0x808005D4: jal         0x80083F70
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bstnt_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: jal         0x8009E5C8
    // 0x808005E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x808005E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x808005E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005F4: jr          $ra
    // 0x808005F8: nop

    return;
    // 0x808005F8: nop

;}
RECOMP_FUNC void _bafly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BE8: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084BE8);
    return;
    // 0x80084BEC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chfactoryprop_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1124, 0XCB0) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xCB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1124, 0XCB0));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xCB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1124, 0XCB0));
;}
RECOMP_FUNC void _dbanim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879B8: syscall     645
    recomp_syscall_handler(rdram, ctx, 0x800879B8);
    return;
    // 0x800879BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bskazmove_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800930: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800934: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800938: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080093C: jal         0x800832E0
    // 0x80800940: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800940: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800944: jal         0x8009E710
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080094C: addiu       $at, $zero, 0xBC
    ctx->r1 = ADD32(0, 0XBC);
    // 0x80800950: bnel        $v0, $at, L_80800998
    if (ctx->r2 != ctx->r1) {
        // 0x80800954: sw          $zero, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = 0;
            goto L_80800998;
    }
    goto skip_0;
    // 0x80800954: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    skip_0:
    // 0x80800958: jal         0x8009BB5C
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_2;
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800960: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800964: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800968: nop

    // 0x8080096C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800970: nop

    // 0x80800974: bc1fl       L_80800998
    if (!c1cs) {
        // 0x80800978: sw          $zero, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = 0;
            goto L_80800998;
    }
    goto skip_1;
    // 0x80800978: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    skip_1:
    // 0x8080097C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800984: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800988: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080098C: jal         0x800849E0
    // 0x80800990: nop

    _badust_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800990: nop

    after_3:
    // 0x80800994: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_80800998:
    // 0x80800998: jal         0x80800754
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800754_bskazmove(rdram, ctx);
        goto after_4;
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808009A0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808009A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808009B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808009B4: jal         0x8009FFD8
    // 0x808009B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_5;
    // 0x808009B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C0: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808009C4: jal         0x8009BFE4
    // 0x808009C8: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_6;
    // 0x808009C8: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_6:
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808009D4: jal         0x8009C554
    // 0x808009D8: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_7;
    // 0x808009D8: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_7:
    // 0x808009DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808009E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009E8: jr          $ra
    // 0x808009EC: nop

    return;
    // 0x808009EC: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A8: jr          $ra
    // 0x808005AC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    return;
    // 0x808005AC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
;}
RECOMP_FUNC void chdinoboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1060, 0X2B88) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x2B88
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1060, 0X2B88));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x2B88
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1060, 0X2B88));
;}
RECOMP_FUNC void glhittableDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800178: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080017C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80800180: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80800184: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80800188: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8080018C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800190: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800194: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800198: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080019C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808001A0: jal         0x800D8F40
    // 0x808001A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800D8F40(rdram, ctx);
        goto after_0;
    // 0x808001A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x808001A8: lw          $t6, 0x24($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X24);
    // 0x808001AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001B0: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2742, 0X530) << 16);
    // 0x808001B4: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x808001B8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x808001BC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x808001C0: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x808001C4: addiu       $t4, $t4, 0x530
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2742, 0X530));
    // 0x808001C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808001CC: bne         $t0, $at, L_808001DC
    if (ctx->r8 != ctx->r1) {
        // 0x808001D0: sw          $t0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r8;
            goto L_808001DC;
    }
    // 0x808001D0: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x808001D4: b           L_80800260
    // 0x808001D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80800260;
    // 0x808001D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_808001DC:
    // 0x808001DC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x808001E0: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2742, 0X2DD4) << 16);
    // 0x808001E4: addiu       $s4, $s4, 0x2DD4
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2742, 0X2DD4));
    // 0x808001E8: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x808001EC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x808001F0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x808001F4: addu        $s3, $t3, $t4
    ctx->r19 = ADD32(ctx->r11, ctx->r12);
    // 0x808001F8: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x808001FC: addiu       $s5, $zero, 0x20
    ctx->r21 = ADD32(0, 0X20);
L_80800200:
    // 0x80800200: lhu         $t5, 0x2($s3)
    ctx->r13 = MEM_HU(ctx->r19, 0X2);
    // 0x80800204: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x80800208: sll         $t7, $s2, 3
    ctx->r15 = S32(ctx->r18 << 3);
    // 0x8080020C: addu        $s1, $s4, $t7
    ctx->r17 = ADD32(ctx->r20, ctx->r15);
    // 0x80800210: or          $v0, $t5, $t6
    ctx->r2 = ctx->r13 | ctx->r14;
    // 0x80800214: beql        $v0, $zero, L_80800254
    if (ctx->r2 == 0) {
        // 0x80800218: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800254;
    }
    goto skip_0;
    // 0x80800218: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8080021C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80800220: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800224: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800228: jalr        $t9
    // 0x8080022C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8080022C: nop

    after_1:
    // 0x80800230: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80800234: bnel        $v0, $t8, L_80800254
    if (ctx->r2 != ctx->r24) {
        // 0x80800238: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800254;
    }
    goto skip_1;
    // 0x80800238: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x8080023C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800240: andi        $t2, $s2, 0xFFFF
    ctx->r10 = ctx->r18 & 0XFFFF;
    // 0x80800244: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80800248: b           L_80800260
    // 0x8080024C: or          $v0, $t1, $t2
    ctx->r2 = ctx->r9 | ctx->r10;
        goto L_80800260;
    // 0x8080024C: or          $v0, $t1, $t2
    ctx->r2 = ctx->r9 | ctx->r10;
    // 0x80800250: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800254:
    // 0x80800254: bne         $s2, $s5, L_80800200
    if (ctx->r18 != ctx->r21) {
        // 0x80800258: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80800200;
    }
    // 0x80800258: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8080025C: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80800260:
    // 0x80800260: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800264: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800268: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080026C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800270: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800274: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800278: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8080027C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80800280: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80800284: jr          $ra
    // 0x80800288: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800288: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bainvisible_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800544: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800548: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8080054C: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80800550: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80800554: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80800558: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8080055C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800560: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800564: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800568: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8080056C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800570: lw          $t6, 0xA8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA8);
    // 0x80800574: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x80800578: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080057C: lbu         $t7, 0x1C($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1C);
    // 0x80800580: bnel        $s7, $t7, L_80800594
    if (ctx->r23 != ctx->r15) {
        // 0x80800584: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800594;
    }
    goto skip_0;
    // 0x80800584: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80800588: jal         0x808001BC
    // 0x8080058C: nop

    func_808001BC_bainvisible(rdram, ctx);
        goto after_0;
    // 0x8080058C: nop

    after_0:
    // 0x80800590: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800594:
    // 0x80800594: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800598: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8080059C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808005A0: addiu       $s6, $zero, 0x60
    ctx->r22 = ADD32(0, 0X60);
    // 0x808005A4: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x808005A8: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x808005AC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x808005B0: lw          $t8, 0xA8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XA8);
L_808005B4:
    // 0x808005B4: addu        $s0, $t8, $s2
    ctx->r16 = ADD32(ctx->r24, ctx->r18);
    // 0x808005B8: lbu         $v0, 0x1C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1C);
    // 0x808005BC: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x808005C0: beq         $v0, $s3, L_808006F0
    if (ctx->r2 == ctx->r19) {
        // 0x808005C4: nop
    
            goto L_808006F0;
    }
    // 0x808005C4: nop

    // 0x808005C8: beq         $v0, $s4, L_808005E8
    if (ctx->r2 == ctx->r20) {
        // 0x808005CC: nop
    
            goto L_808005E8;
    }
    // 0x808005CC: nop

    // 0x808005D0: beq         $v0, $s7, L_80800628
    if (ctx->r2 == ctx->r23) {
        // 0x808005D4: nop
    
            goto L_80800628;
    }
    // 0x808005D4: nop

    // 0x808005D8: beq         $v0, $s5, L_8080069C
    if (ctx->r2 == ctx->r21) {
        // 0x808005DC: nop
    
            goto L_8080069C;
    }
    // 0x808005DC: nop

    // 0x808005E0: b           L_80800710
    // 0x808005E4: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
        goto L_80800710;
    // 0x808005E4: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
L_808005E8:
    // 0x808005E8: jal         0x800D8FF8
    // 0x808005EC: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808005EC: nop

    after_1:
    // 0x808005F0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808005F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005FC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800600: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80800604: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800608: c.lt.s      $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f8.fl < ctx->f22.fl;
    // 0x8080060C: nop

    // 0x80800610: bc1fl       L_80800710
    if (!c1cs) {
        // 0x80800614: addiu       $s2, $s2, 0x30
        ctx->r18 = ADD32(ctx->r18, 0X30);
            goto L_80800710;
    }
    goto skip_1;
    // 0x80800614: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    skip_1:
    // 0x80800618: jal         0x80800000
    // 0x8080061C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_80800000_bainvisible(rdram, ctx);
        goto after_2;
    // 0x8080061C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_2:
    // 0x80800620: b           L_80800710
    // 0x80800624: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
        goto L_80800710;
    // 0x80800624: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
L_80800628:
    // 0x80800628: jal         0x808003AC
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003AC_bainvisible(rdram, ctx);
        goto after_3;
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800630: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800634: jal         0x800915AC
    // 0x80800638: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bastatetimer_isDone(rdram, ctx);
        goto after_4;
    // 0x80800638: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x8080063C: beq         $v0, $zero, L_80800660
    if (ctx->r2 == 0) {
        // 0x80800640: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800660;
    }
    // 0x80800640: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800644: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800648: jal         0x80800000
    // 0x8080064C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80800000_bainvisible(rdram, ctx);
        goto after_5;
    // 0x8080064C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_5:
    // 0x80800650: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800658: jal         0x8009DBF0
    // 0x8080065C: addiu       $a1, $zero, 0x65D
    ctx->r5 = ADD32(0, 0X65D);
    func_8009DBF0(rdram, ctx);
        goto after_6;
    // 0x8080065C: addiu       $a1, $zero, 0x65D
    ctx->r5 = ADD32(0, 0X65D);
    after_6:
L_80800660:
    // 0x80800660: lbu         $t9, 0x1C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1C);
    // 0x80800664: beql        $t9, $zero, L_80800710
    if (ctx->r25 == 0) {
        // 0x80800668: addiu       $s2, $s2, 0x30
        ctx->r18 = ADD32(ctx->r18, 0X30);
            goto L_80800710;
    }
    goto skip_2;
    // 0x80800668: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    skip_2:
    // 0x8080066C: jal         0x800D8FF8
    // 0x80800670: nop

    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x80800670: nop

    after_7:
    // 0x80800674: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800678: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8080067C: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x80800680: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800684: c.le.s      $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f18.fl <= ctx->f22.fl;
    // 0x80800688: nop

    // 0x8080068C: bc1fl       L_80800710
    if (!c1cs) {
        // 0x80800690: addiu       $s2, $s2, 0x30
        ctx->r18 = ADD32(ctx->r18, 0X30);
            goto L_80800710;
    }
    goto skip_3;
    // 0x80800690: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    skip_3:
    // 0x80800694: b           L_8080070C
    // 0x80800698: sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
        goto L_8080070C;
    // 0x80800698: sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
L_8080069C:
    // 0x8080069C: jal         0x800D8FF8
    // 0x808006A0: nop

    func_800D8FF8(rdram, ctx);
        goto after_8;
    // 0x808006A0: nop

    after_8:
    // 0x808006A4: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808006A8: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808006AC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808006B0: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x808006B4: lwc1        $f2, 0x28($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808006B8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x808006BC: nop

    // 0x808006C0: bc1fl       L_808006D4
    if (!c1cs) {
        // 0x808006C4: mov.s       $f14, $f20
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
            goto L_808006D4;
    }
    goto skip_4;
    // 0x808006C4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    skip_4:
    // 0x808006C8: b           L_808006D4
    // 0x808006CC: div.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
        goto L_808006D4;
    // 0x808006CC: div.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    // 0x808006D0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
L_808006D4:
    // 0x808006D4: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808006D8: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808006DC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808006E0: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x808006E4: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808006E8: b           L_8080070C
    // 0x808006EC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8080070C;
    // 0x808006EC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_808006F0:
    // 0x808006F0: jal         0x808003AC
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003AC_bainvisible(rdram, ctx);
        goto after_9;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006F8: beq         $v0, $zero, L_8080070C
    if (ctx->r2 == 0) {
        // 0x808006FC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080070C;
    }
    // 0x808006FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800700: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800704: jal         0x80800000
    // 0x80800708: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_bainvisible(rdram, ctx);
        goto after_10;
    // 0x80800708: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
L_8080070C:
    // 0x8080070C: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
L_80800710:
    // 0x80800710: bnel        $s2, $s6, L_808005B4
    if (ctx->r18 != ctx->r22) {
        // 0x80800714: lw          $t8, 0xA8($s1)
        ctx->r24 = MEM_W(ctx->r17, 0XA8);
            goto L_808005B4;
    }
    goto skip_5;
    // 0x80800714: lw          $t8, 0xA8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XA8);
    skip_5:
    // 0x80800718: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8080071C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800720: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800724: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800728: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8080072C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800730: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800734: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80800738: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8080073C: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80800740: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80800744: jr          $ra
    // 0x80800748: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800748: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80800440_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800448: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800450: jal         0x80100094
    // 0x80800454: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800454: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800458: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080045C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80800460: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800464: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800468: beq         $a1, $t6, L_808004AC
    if (ctx->r5 == ctx->r14) {
        // 0x8080046C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808004AC;
    }
    // 0x8080046C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800470: beq         $v1, $zero, L_80800498
    if (ctx->r3 == 0) {
        // 0x80800474: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800498;
    }
    // 0x80800474: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800478: beq         $v1, $at, L_80800488
    if (ctx->r3 == ctx->r1) {
        // 0x8080047C: nop
    
            goto L_80800488;
    }
    // 0x8080047C: nop

    // 0x80800480: bnel        $v1, $a1, L_808004A8
    if (ctx->r3 != ctx->r5) {
        // 0x80800484: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_808004A8;
    }
    goto skip_0;
    // 0x80800484: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80800488:
    // 0x80800488: jal         0x8008A4B0
    // 0x8080048C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080048C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800490: b           L_808004A4
    // 0x80800494: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_808004A4;
    // 0x80800494: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80800498:
    // 0x80800498: jal         0x8008A4B0
    // 0x8080049C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080049C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808004A0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_808004A4:
    // 0x808004A4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_808004A8:
    // 0x808004A8: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
L_808004AC:
    // 0x808004AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004B4: jr          $ra
    // 0x808004B8: nop

    return;
    // 0x808004B8: nop

;}
RECOMP_FUNC void func_80803CC0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803CC8: jal         0x800FC660
    // 0x80803CCC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    func_800FC660(rdram, ctx);
        goto after_0;
    // 0x80803CCC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_0:
    // 0x80803CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803CD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803CD8: jr          $ra
    // 0x80803CDC: nop

    return;
    // 0x80803CDC: nop

;}
RECOMP_FUNC void func_800E4CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4CE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E4CEC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E4CF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E4CF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E4CF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800E4CFC: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_800E4D00:
    // 0x800E4D00: jal         0x800E4B1C
    // 0x800E4D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E4B1C(rdram, ctx);
        goto after_0;
    // 0x800E4D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800E4D08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800E4D0C: bne         $s0, $s1, L_800E4D00
    if (ctx->r16 != ctx->r17) {
        // 0x800E4D10: nop
    
            goto L_800E4D00;
    }
    // 0x800E4D10: nop

    // 0x800E4D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4D18: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E4D1C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E4D20: jr          $ra
    // 0x800E4D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800E4D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800B60_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800B64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B74: beq         $a1, $at, L_80800B90
    if (ctx->r5 == ctx->r1) {
        // 0x80800B78: sw          $a1, 0x15C($a0)
        MEM_W(0X15C, ctx->r4) = ctx->r5;
            goto L_80800B90;
    }
    // 0x80800B78: sw          $a1, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r5;
    // 0x80800B7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B80: beq         $a1, $at, L_80800C30
    if (ctx->r5 == ctx->r1) {
        // 0x80800B84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C30;
    }
    // 0x80800B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B88: b           L_80800CA0
    // 0x80800B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800CA0;
    // 0x80800B8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B90:
    // 0x80800B90: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800B94: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B9C: jal         0x8008CCBC
    // 0x80800BA0: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x80800BA0: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    after_0:
    // 0x80800BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800BB0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800BB4: jal         0x8009FFD8
    // 0x80800BB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800BB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80800BBC: lw          $a0, 0x164($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X164);
    // 0x80800BC0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800BC4: jal         0x8010114C
    // 0x80800BC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_2;
    // 0x80800BC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800BCC: jal         0x80101038
    // 0x80800BD0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_80101038(rdram, ctx);
        goto after_3;
    // 0x80800BD0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD8: jal         0x8009C128
    // 0x80800BDC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8009C128(rdram, ctx);
        goto after_4;
    // 0x80800BDC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x80800BE0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800BE4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800BE8: jal         0x800F1E6C
    // 0x80800BEC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800F1E6C(rdram, ctx);
        goto after_5;
    // 0x80800BEC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_5:
    // 0x80800BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BF4: jal         0x8009C914
    // 0x80800BF8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80800BF8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_6:
    // 0x80800BFC: jal         0x80084DB8
    // 0x80800C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C08: jal         0x80084E18
    // 0x80800C0C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _bamovegoto_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x80800C0C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x80800C10: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800C14: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800C18: jal         0x80084DF0
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800C20: jal         0x80084E20
    // 0x80800C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x80800C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800C28: b           L_80800CA0
    // 0x80800C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800CA0;
    // 0x80800C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C30:
    // 0x80800C30: lui         $a2, 0x4059
    ctx->r6 = S32(0X4059 << 16);
    // 0x80800C34: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800C38: jal         0x8008CCBC
    // 0x80800C3C: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_11;
    // 0x80800C3C: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    after_11:
    // 0x80800C40: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800C44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800C54: jal         0x8009FFD8
    // 0x80800C58: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_12;
    // 0x80800C58: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_12:
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C60: jal         0x8009B9B0
    // 0x80800C64: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_13;
    // 0x80800C64: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_13:
    // 0x80800C68: lw          $a0, 0x164($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X164);
    // 0x80800C6C: jal         0x8008F880
    // 0x80800C70: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8008F880(rdram, ctx);
        goto after_14;
    // 0x80800C70: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_14:
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C78: jal         0x8009C128
    // 0x80800C7C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8009C128(rdram, ctx);
        goto after_15;
    // 0x80800C7C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_15:
    // 0x80800C80: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800C84: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800C88: jal         0x800F1E6C
    // 0x80800C8C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800F1E6C(rdram, ctx);
        goto after_16;
    // 0x80800C8C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_16:
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C94: jal         0x8009C914
    // 0x80800C98: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    yaw_setIdeal(rdram, ctx);
        goto after_17;
    // 0x80800C98: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_17:
    // 0x80800C9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CA0:
    // 0x80800CA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CA4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800CA8: jr          $ra
    // 0x80800CAC: nop

    return;
    // 0x80800CAC: nop

;}
RECOMP_FUNC void func_80800424_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080042C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800430: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800434: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800438: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080043C: jal         0x80100094
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800444: lbu         $v1, 0x28($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X28);
    // 0x80800448: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080044C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800450: beq         $v1, $zero, L_80800474
    if (ctx->r3 == 0) {
        // 0x80800454: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80800474;
    }
    // 0x80800454: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800458: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080045C: beq         $v1, $at, L_80800488
    if (ctx->r3 == ctx->r1) {
        // 0x80800460: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800488;
    }
    // 0x80800460: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800464: beql        $v1, $at, L_80800494
    if (ctx->r3 == ctx->r1) {
        // 0x80800468: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800494;
    }
    goto skip_0;
    // 0x80800468: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080046C: b           L_808004A4
    // 0x80800470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004A4;
    // 0x80800470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800474:
    // 0x80800474: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800478: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8080047C: jal         0x800856B0
    // 0x80800480: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800480: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800484: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800488:
    // 0x80800488: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8080048C: sb          $t7, 0x28($a3)
    MEM_B(0X28, ctx->r7) = ctx->r15;
    // 0x80800490: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80800494:
    // 0x80800494: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800498: jal         0x800856D0
    // 0x8080049C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x8080049C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808004A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004A4:
    // 0x808004A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004A8: jr          $ra
    // 0x808004AC: nop

    return;
    // 0x808004AC: nop

;}
RECOMP_FUNC void func_800BEA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEA64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BEA68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BEA6C: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x800BEA70: jal         0x800BE600
    // 0x800BEA74: ori         $a1, $a1, 0x20
    ctx->r5 = ctx->r5 | 0X20;
    func_800BE600(rdram, ctx);
        goto after_0;
    // 0x800BEA74: ori         $a1, $a1, 0x20
    ctx->r5 = ctx->r5 | 0X20;
    after_0:
    // 0x800BEA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BEA7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BEA80: jr          $ra
    // 0x800BEA84: nop

    return;
    // 0x800BEA84: nop

;}
RECOMP_FUNC void func_800F0524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0524: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800F0528: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F052C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800F0530: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F0534: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800F0538: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800F053C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800F0540: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800F0544: jal         0x800EFB24
    // 0x800F0548: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800F0548: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x800F054C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800F0550: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x800F0554: jal         0x800EFB24
    // 0x800F0558: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x800F0558: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800F055C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800F0560: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800F0564: jal         0x800EE97C
    // 0x800F0568: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800EE97C(rdram, ctx);
        goto after_2;
    // 0x800F0568: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x800F056C: jal         0x800EF2A0
    // 0x800F0570: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EF2A0(rdram, ctx);
        goto after_3;
    // 0x800F0570: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x800F0574: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800F0578: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F057C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800F0580: jal         0x800F03AC
    // 0x800F0584: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    func_800F03AC(rdram, ctx);
        goto after_4;
    // 0x800F0584: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_4:
    // 0x800F0588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F058C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F0590: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800F0594: jr          $ra
    // 0x800F0598: nop

    return;
    // 0x800F0598: nop

;}
RECOMP_FUNC void func_800CF6D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF6D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF6D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF6D8: jal         0x800DA298
    // 0x800CF6DC: addiu       $a0, $zero, 0x1BF
    ctx->r4 = ADD32(0, 0X1BF);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800CF6DC: addiu       $a0, $zero, 0x1BF
    ctx->r4 = ADD32(0, 0X1BF);
    after_0:
    // 0x800CF6E0: beq         $v0, $zero, L_800CF6F0
    if (ctx->r2 == 0) {
        // 0x800CF6E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF6F0;
    }
    // 0x800CF6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF6E8: b           L_800CF6F4
    // 0x800CF6EC: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_800CF6F4;
    // 0x800CF6EC: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_800CF6F0:
    // 0x800CF6F0: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_800CF6F4:
    // 0x800CF6F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CF6F8: jr          $ra
    // 0x800CF6FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CF6FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800BA834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA83C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BA840: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BA844: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800BA848: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800BA84C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800BA850: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800BA854: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x800BA858: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800BA85C: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800BA860: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BA864: jal         0x800EFA6C
    // 0x800BA868: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    func_800EFA6C(rdram, ctx);
        goto after_0;
    // 0x800BA868: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_0:
    // 0x800BA86C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BA870: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x800BA874: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    // 0x800BA878: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x800BA87C: jal         0x800EFA6C
    // 0x800BA880: addiu       $a0, $a0, 0x46
    ctx->r4 = ADD32(ctx->r4, 0X46);
    func_800EFA6C(rdram, ctx);
        goto after_1;
    // 0x800BA880: addiu       $a0, $a0, 0x46
    ctx->r4 = ADD32(ctx->r4, 0X46);
    after_1:
    // 0x800BA884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA88C: jr          $ra
    // 0x800BA890: nop

    return;
    // 0x800BA890: nop

;}
RECOMP_FUNC void _bswasher_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843C8: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x800843C8);
    return;
    // 0x800843CC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801488_mlspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801488: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8080148C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80801490: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801494: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80801498: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8080149C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808014A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3006, 0X1C64) << 16);
    // 0x808014A4: sub.s       $f20, $f22, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x808014A8: lwc1        $f4, 0x1C64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3006, 0X1C64));
    // 0x808014AC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x808014B0: lw          $s3, 0xA0($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA0);
    // 0x808014B4: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x808014B8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x808014BC: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x808014C0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x808014C4: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x808014C8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808014CC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808014D0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x808014D4: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x808014D8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x808014DC: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808014E0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808014E4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808014E8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x808014EC: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x808014F0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808014F4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x808014F8: jal         0x8080145C
    // 0x808014FC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_8080145C_mlspline(rdram, ctx);
        goto after_0;
    // 0x808014FC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_0:
    // 0x80801500: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x80801504: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80801508: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8080150C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80801510: jal         0x8080145C
    // 0x80801514: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_8080145C_mlspline(rdram, ctx);
        goto after_1;
    // 0x80801514: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
    // 0x80801518: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080151C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801520: add.s       $f8, $f0, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f30.fl;
    // 0x80801524: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80801528: mul.s       $f24, $f20, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8080152C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80801530: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x80801534: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80801538: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8080153C: jal         0x8080145C
    // 0x80801540: add.s       $f12, $f26, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f26.fl + ctx->f24.fl;
    func_8080145C_mlspline(rdram, ctx);
        goto after_2;
    // 0x80801540: add.s       $f12, $f26, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f26.fl + ctx->f24.fl;
    after_2:
    // 0x80801544: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801548: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080154C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801550: add.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80801554: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80801558: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8080155C: lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X98);
    // 0x80801560: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80801564: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80801568: slti        $at, $s6, 0x2
    ctx->r1 = SIGNED(ctx->r22) < 0X2 ? 1 : 0;
    // 0x8080156C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801570: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80801574: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80801578: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8080157C: bne         $at, $zero, L_808016BC
    if (ctx->r1 != 0) {
        // 0x80801580: add.s       $f30, $f2, $f2
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = ctx->f2.fl + ctx->f2.fl;
            goto L_808016BC;
    }
    // 0x80801580: add.s       $f30, $f2, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80801584: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80801588: jal         0x800F2100
    // 0x8080158C: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x8080158C: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x80801590: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801594: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80801598: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8080159C: nop

    // 0x808015A0: bc1fl       L_808016C0
    if (!c1cs) {
        // 0x808015A4: slti        $at, $s4, 0x4
        ctx->r1 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
            goto L_808016C0;
    }
    goto skip_0;
    // 0x808015A4: slti        $at, $s4, 0x4
    ctx->r1 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    skip_0:
    // 0x808015A8: sub.s       $f6, $f14, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f30.fl;
    // 0x808015AC: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x808015B0: jal         0x800F2100
    // 0x808015B4: div.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x808015B4: div.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    after_4:
    // 0x808015B8: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x808015BC: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808015C0: sll         $s1, $s5, 1
    ctx->r17 = S32(ctx->r21 << 1);
    // 0x808015C4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808015C8: nop

    // 0x808015CC: bc1f        L_808016BC
    if (!c1cs) {
        // 0x808015D0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808016BC;
    }
    // 0x808015D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808015D4:
    // 0x808015D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808015D8: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808015DC: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
    // 0x808015E0: add.s       $f28, $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f20.fl;
    // 0x808015E4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808015E8: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x808015EC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808015F0: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x808015F4: mul.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x808015F8: mov.s       $f30, $f14
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 14);
    ctx->f30.fl = ctx->f14.fl;
    // 0x808015FC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80801600: bne         $at, $zero, L_80801638
    if (ctx->r1 != 0) {
        // 0x80801604: swc1        $f10, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
            goto L_80801638;
    }
    // 0x80801604: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
L_80801608:
    // 0x80801608: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x8080160C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80801610: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80801614: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801618: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8080161C: mul.s       $f6, $f18, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80801620: jal         0x8080145C
    // 0x80801624: add.s       $f12, $f6, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f26.fl;
    func_8080145C_mlspline(rdram, ctx);
        goto after_5;
    // 0x80801624: add.s       $f12, $f6, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f26.fl;
    after_5:
    // 0x80801628: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8080162C: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80801630: bne         $at, $zero, L_80801608
    if (ctx->r1 != 0) {
        // 0x80801634: add.s       $f20, $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
            goto L_80801608;
    }
    // 0x80801634: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_80801638:
    // 0x80801638: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080163C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801640: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801644: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801648: mul.s       $f8, $f4, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8080164C: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80801650: slt         $at, $s5, $s6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80801654: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80801658: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8080165C: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80801660: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80801664: mul.s       $f22, $f4, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80801668: beq         $at, $zero, L_808016BC
    if (ctx->r1 == 0) {
        // 0x8080166C: mov.s       $f14, $f22
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
            goto L_808016BC;
    }
    // 0x8080166C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80801670: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80801674: jal         0x800F2100
    // 0x80801678: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x80801678: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x8080167C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801680: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80801684: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80801688: nop

    // 0x8080168C: bc1fl       L_808016C0
    if (!c1cs) {
        // 0x80801690: slti        $at, $s4, 0x4
        ctx->r1 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
            goto L_808016C0;
    }
    goto skip_1;
    // 0x80801690: slti        $at, $s4, 0x4
    ctx->r1 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    skip_1:
    // 0x80801694: sub.s       $f18, $f22, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f22.fl - ctx->f30.fl;
    // 0x80801698: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x8080169C: jal         0x800F2100
    // 0x808016A0: div.s       $f12, $f18, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f22.fl);
    mlAbsF(rdram, ctx);
        goto after_7;
    // 0x808016A0: div.s       $f12, $f18, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f22.fl);
    after_7:
    // 0x808016A4: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x808016A8: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808016AC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808016B0: nop

    // 0x808016B4: bc1tl       L_808015D4
    if (c1cs) {
        // 0x808016B8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808015D4;
    }
    goto skip_2;
    // 0x808016B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_2:
L_808016BC:
    // 0x808016BC: slti        $at, $s4, 0x4
    ctx->r1 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
L_808016C0:
    // 0x808016C0: bne         $at, $zero, L_808016E0
    if (ctx->r1 != 0) {
        // 0x808016C4: ldc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
            goto L_808016E0;
    }
    // 0x808016C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808016C8: addiu       $t6, $s4, -0x1
    ctx->r14 = ADD32(ctx->r20, -0X1);
    // 0x808016CC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x808016D0: nop

    // 0x808016D4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808016D8: mul.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x808016DC: nop

L_808016E0:
    // 0x808016E0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x808016E4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808016E8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808016EC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808016F0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808016F4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x808016F8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x808016FC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80801700: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80801704: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80801708: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8080170C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80801710: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80801714: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80801718: jr          $ra
    // 0x8080171C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    return;
    // 0x8080171C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
;}
RECOMP_FUNC void _chfactoryentrydoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870D0: syscall     512
    recomp_syscall_handler(rdram, ctx, 0x800870D0);
    return;
    // 0x800870D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsstonehead_entrypoint_42(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080151C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801520: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801524: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801528: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080152C: jal         0x8008DD04
    // 0x80801530: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8008DD04(rdram, ctx);
        goto after_0;
    // 0x80801530: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x80801534: beq         $v0, $zero, L_80801540
    if (ctx->r2 == 0) {
        // 0x80801538: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801540;
    }
    // 0x80801538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080153C: addiu       $s1, $zero, 0xAD
    ctx->r17 = ADD32(0, 0XAD);
L_80801540:
    // 0x80801540: jal         0x808003F4
    // 0x80801544: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808003F4_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x80801544: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80801548: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080154C: jal         0x8008E148
    // 0x80801550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_2;
    // 0x80801550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801554: beql        $v0, $zero, L_8080156C
    if (ctx->r2 == 0) {
        // 0x80801558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080156C;
    }
    goto skip_0;
    // 0x80801558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080155C: jal         0x800848B0
    // 0x80801560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_3;
    // 0x80801560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801564: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080156C:
    // 0x8080156C: jal         0x80091A58
    // 0x80801570: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_4;
    // 0x80801570: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x80801574: beq         $v0, $zero, L_80801580
    if (ctx->r2 == 0) {
        // 0x80801578: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801580;
    }
    // 0x80801578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080157C: addiu       $s1, $zero, 0xB4
    ctx->r17 = ADD32(0, 0XB4);
L_80801580:
    // 0x80801580: jal         0x80091A94
    // 0x80801584: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_newlyReleased(rdram, ctx);
        goto after_5;
    // 0x80801584: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80801588: beq         $v0, $zero, L_808015B0
    if (ctx->r2 == 0) {
        // 0x8080158C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015B0;
    }
    // 0x8080158C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801590: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801594: jal         0x80091940
    // 0x80801598: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bakey_func_80091940(rdram, ctx);
        goto after_6;
    // 0x80801598: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8080159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808015A4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808015A8: jal         0x80084468
    // 0x808015AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _baattach_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x808015AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_808015B0:
    // 0x808015B0: jal         0x80097AD0
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_8;
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808015B8: beql        $v0, $zero, L_808015D0
    if (ctx->r2 == 0) {
        // 0x808015BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015D0;
    }
    goto skip_1;
    // 0x808015BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808015C0: jal         0x800848A8
    // 0x808015C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_9;
    // 0x808015C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808015C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808015CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808015D0:
    // 0x808015D0: jal         0x800A02DC
    // 0x808015D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A02DC(rdram, ctx);
        goto after_10;
    // 0x808015D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x808015D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015DC: jal         0x8009E5C8
    // 0x808015E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x808015E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x808015E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808015E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808015EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808015F0: jr          $ra
    // 0x808015F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808015F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800EBB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBB50: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800EBB54: jr          $ra
    // 0x800EBB58: addiu       $v0, $v0, 0x3540
    ctx->r2 = ADD32(ctx->r2, 0X3540);
    return;
    // 0x800EBB58: addiu       $v0, $v0, 0x3540
    ctx->r2 = ADD32(ctx->r2, 0X3540);
;}
RECOMP_FUNC void bsdronelook_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001C0: jal         0x80084C98
    // 0x808001C4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808001C4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808001C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001CC: beql        $v0, $at, L_808001F4
    if (ctx->r2 == ctx->r1) {
        // 0x808001D0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808001F4;
    }
    goto skip_0;
    // 0x808001D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808001D4: jal         0x800A3404
    // 0x808001D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A3404(rdram, ctx);
        goto after_1;
    // 0x808001D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808001DC: bnel        $v0, $zero, L_808001F4
    if (ctx->r2 != 0) {
        // 0x808001E0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808001F4;
    }
    goto skip_1;
    // 0x808001E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x808001E4: jal         0x80084750
    // 0x808001E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _badata_entrypoint_34(rdram, ctx);
        goto after_2;
    // 0x808001E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808001EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808001F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808001F4:
    // 0x808001F4: jal         0x8009E5C8
    // 0x808001F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808001F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808001FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void _bacough_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084620: syscall     117
    recomp_syscall_handler(rdram, ctx, 0x80084620);
    return;
    // 0x80084624: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _gsworldDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B60: syscall     726
    recomp_syscall_handler(rdram, ctx, 0x80088B60);
    return;
    // 0x80088B64: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void changlerboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1332, 0X2EB4) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2EB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1332, 0X2EB4));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2EB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1332, 0X2EB4));
;}
RECOMP_FUNC void func_80800D0C_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800D10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D18: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800D1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D20: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80800D24: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800D28: bltz        $t8, L_80800D34
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800D2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D34;
    }
    // 0x80800D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D30: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
L_80800D34:
    // 0x80800D34: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800D38: jal         0x80086670
    // 0x80800D3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800D3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800D40: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800D44: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800D48: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800D4C: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x80800D50: jal         0x800E1610
    // 0x80800D54: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_800E1610(rdram, ctx);
        goto after_1;
    // 0x80800D54: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800D58: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800D5C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800D60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D64: jal         0x80018820
    // 0x80800D68: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80018820(rdram, ctx);
        goto after_2;
    // 0x80800D68: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
    // 0x80800D6C: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800D70: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1528, 0XF7C) << 16);
    // 0x80800D74: addiu       $a3, $a3, 0xF7C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1528, 0XF7C));
    // 0x80800D78: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x80800D7C: bgez        $t1, L_80800D90
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800D80: nop
    
            goto L_80800D90;
    }
    // 0x80800D80: nop

    // 0x80800D84: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1528, 0XF68) << 16);
    // 0x80800D88: b           L_80800D90
    // 0x80800D8C: addiu       $a3, $a3, 0xF68
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1528, 0XF68));
        goto L_80800D90;
    // 0x80800D8C: addiu       $a3, $a3, 0xF68
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1528, 0XF68));
L_80800D90:
    // 0x80800D90: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80800D94: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800D98: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800D9C: andi        $t2, $a1, 0x1
    ctx->r10 = ctx->r5 & 0X1;
    // 0x80800DA0: jal         0x8010D930
    // 0x80800DA4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_8010D930(rdram, ctx);
        goto after_3;
    // 0x80800DA4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_3:
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DAC: jal         0x80101FDC
    // 0x80800DB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800DB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800DB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800DBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800DC0: jr          $ra
    // 0x80800DC4: nop

    return;
    // 0x80800DC4: nop

;}
RECOMP_FUNC void _bskazshock_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083558: syscall     66
    recomp_syscall_handler(rdram, ctx, 0x80083558);
    return;
    // 0x8008355C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080256C_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080256C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80802570: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80802574: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80802578: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080257C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802580: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802584: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80802588: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8080258C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80802590: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80802594: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80802598: jal         0x80100094
    // 0x8080259C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080259C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808025A0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808025A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808025A8: jal         0x801018A4
    // 0x808025AC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_801018A4(rdram, ctx);
        goto after_1;
    // 0x808025AC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_1:
    // 0x808025B0: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x808025B4: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808025B8: bgezl       $t8, L_80802660
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808025BC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80802660;
    }
    goto skip_0;
    // 0x808025BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x808025C0: jal         0x800D674C
    // 0x808025C4: addiu       $a0, $zero, 0x9E2
    ctx->r4 = ADD32(0, 0X9E2);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x808025C4: addiu       $a0, $zero, 0x9E2
    ctx->r4 = ADD32(0, 0X9E2);
    after_2:
    // 0x808025C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808025CC: jal         0x800E2588
    // 0x808025D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800E2588(rdram, ctx);
        goto after_3;
    // 0x808025D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x808025D4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808025D8: jal         0x800E2594
    // 0x808025DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E2594(rdram, ctx);
        goto after_4;
    // 0x808025DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x808025E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X44D4) << 16);
    // 0x808025E4: lwc1        $f0, 0x44D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X44D4));
    // 0x808025E8: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x808025EC: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x808025F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808025F4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808025F8: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x808025FC: jal         0x800EFA4C
    // 0x80802600: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x80802600: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x80802604: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802608: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x8080260C: addiu       $s3, $zero, 0x3C
    ctx->r19 = ADD32(0, 0X3C);
    // 0x80802610: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_80802614:
    // 0x80802614: lbu         $v0, 0x87C($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X87C);
    // 0x80802618: beql        $v0, $zero, L_8080264C
    if (ctx->r2 == 0) {
        // 0x8080261C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080264C;
    }
    goto skip_1;
    // 0x8080261C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80802620: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802624: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80802628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080262C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802630: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80802634: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80802638: mflo        $t9
    ctx->r25 = lo;
    // 0x8080263C: addu        $a3, $s5, $t9
    ctx->r7 = ADD32(ctx->r21, ctx->r25);
    // 0x80802640: jal         0x800E2720
    // 0x80802644: addiu       $a3, $a3, 0x2DC
    ctx->r7 = ADD32(ctx->r7, 0X2DC);
    func_800E2720(rdram, ctx);
        goto after_6;
    // 0x80802644: addiu       $a3, $a3, 0x2DC
    ctx->r7 = ADD32(ctx->r7, 0X2DC);
    after_6:
    // 0x80802648: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8080264C:
    // 0x8080264C: bne         $s0, $s3, L_80802614
    if (ctx->r16 != ctx->r19) {
        // 0x80802650: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80802614;
    }
    // 0x80802650: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80802654: jal         0x800E2A14
    // 0x80802658: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800E2A14(rdram, ctx);
        goto after_7;
    // 0x80802658: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_7:
    // 0x8080265C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80802660:
    // 0x80802660: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802664: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80802668: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080266C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80802670: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80802674: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80802678: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8080267C: jr          $ra
    // 0x80802680: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80802680: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void sumumbofx_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808004C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808004CC: lh          $v1, 0x58($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X58);
    // 0x808004D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808004D4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x808004D8: addiu       $v0, $a0, 0x64
    ctx->r2 = ADD32(ctx->r4, 0X64);
    // 0x808004DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004E0: blez        $v1, L_80800590
    if (SIGNED(ctx->r3) <= 0) {
        // 0x808004E4: swc1        $f4, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
            goto L_80800590;
    }
    // 0x808004E4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x808004E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X1488) << 16);
    // 0x808004EC: lwc1        $f20, 0x1488($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X1488));
    // 0x808004F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X148C) << 16);
    // 0x808004F4: lwc1        $f18, 0x148C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X148C));
    // 0x808004F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X1490) << 16);
    // 0x808004FC: lwc1        $f16, 0x1490($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X1490));
    // 0x80800500: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800504: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800508: nop

L_8080050C:
    // 0x8080050C: lh          $t6, 0x5A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X5A);
    // 0x80800510: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800514: bnel        $at, $zero, L_80800574
    if (ctx->r1 != 0) {
        // 0x80800518: lwc1        $f10, 0x8($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
            goto L_80800574;
    }
    goto skip_0;
    // 0x80800518: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x8080051C: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80800520: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800524: nop

    // 0x80800528: bc1fl       L_80800568
    if (!c1cs) {
        // 0x8080052C: swc1        $f14, 0x28($v0)
        MEM_W(0X28, ctx->r2) = ctx->f14.u32l;
            goto L_80800568;
    }
    goto skip_1;
    // 0x8080052C: swc1        $f14, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f14.u32l;
    skip_1:
    // 0x80800530: sub.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80800534: mul.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800538: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8080053C: nop

    // 0x80800540: bc1fl       L_80800554
    if (!c1cs) {
        // 0x80800544: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80800554;
    }
    goto skip_2;
    // 0x80800544: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x80800548: b           L_80800554
    // 0x8080054C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
        goto L_80800554;
    // 0x8080054C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x80800550: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80800554:
    // 0x80800554: add.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80800558: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x8080055C: b           L_80800570
    // 0x80800560: lh          $v1, 0x58($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X58);
        goto L_80800570;
    // 0x80800560: lh          $v1, 0x58($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X58);
    // 0x80800564: swc1        $f14, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f14.u32l;
L_80800568:
    // 0x80800568: lh          $v1, 0x58($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X58);
    // 0x8080056C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80800570:
    // 0x80800570: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
L_80800574:
    // 0x80800574: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80800578: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8080057C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800580: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800584: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x80800588: bne         $at, $zero, L_8080050C
    if (ctx->r1 != 0) {
        // 0x8080058C: swc1        $f6, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
            goto L_8080050C;
    }
    // 0x8080058C: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
L_80800590:
    // 0x80800590: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80800594: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80800598: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080059C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808005A0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x808005A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808005A8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808005AC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808005B0: jal         0x800F10B4
    // 0x808005B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x808005B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x808005B8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808005BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808005C0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x808005C4: jal         0x800D8FF8
    // 0x808005C8: sh          $t8, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r24;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808005C8: sh          $t8, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r24;
    after_1:
    // 0x808005CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808005D0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808005D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005D8: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x808005DC: lh          $t9, 0x58($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X58);
    // 0x808005E0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x808005E4: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808005E8: beq         $at, $zero, L_808005F8
    if (ctx->r1 == 0) {
        // 0x808005EC: swc1        $f8, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
            goto L_808005F8;
    }
    // 0x808005EC: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x808005F0: b           L_808005F8
    // 0x808005F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F8;
    // 0x808005F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005F8:
    // 0x808005F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005FC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800600: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800604: jr          $ra
    // 0x80800608: nop

    return;
    // 0x80800608: nop

;}
RECOMP_FUNC void func_80800228_chklungoforcefield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080022C: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80800230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800234: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800238: bne         $a1, $at, L_80800274
    if (ctx->r5 != ctx->r1) {
        // 0x8080023C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800274;
    }
    // 0x8080023C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800240: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x80800244: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x80800248: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080024C: beq         $a0, $zero, L_80800264
    if (ctx->r4 == 0) {
        // 0x80800250: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80800264;
    }
    // 0x80800250: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800254: jal         0x800863E8
    // 0x80800258: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800258: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080025C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800260: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
L_80800264:
    // 0x80800264: jal         0x80089CA8
    // 0x80800268: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800268: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8080026C: b           L_80800278
    // 0x80800270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800278;
    // 0x80800270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800274:
    // 0x80800274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800278:
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080027C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800280: jr          $ra
    // 0x80800284: nop

    return;
    // 0x80800284: nop

;}
RECOMP_FUNC void suexpression_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800088: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080008C: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80800090: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800094: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800098: jal         0x80800CF4
    // 0x8080009C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80800CF4_suexpression(rdram, ctx);
        goto after_0;
    // 0x8080009C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808000A4: jal         0x80106790
    // 0x808000A8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808000A8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x808000AC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808000B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000B8: bnel        $v1, $zero, L_808000D4
    if (ctx->r3 != 0) {
        // 0x808000BC: lh          $a1, 0x2($v1)
        ctx->r5 = MEM_H(ctx->r3, 0X2);
            goto L_808000D4;
    }
    goto skip_0;
    // 0x808000BC: lh          $a1, 0x2($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X2);
    skip_0:
    // 0x808000C0: jal         0x80103DFC
    // 0x808000C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80103DFC(rdram, ctx);
        goto after_2;
    // 0x808000C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x808000C8: b           L_80800170
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800170;
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D0: lh          $a1, 0x2($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X2);
L_808000D4:
    // 0x808000D4: beql        $a1, $zero, L_8080013C
    if (ctx->r5 == 0) {
        // 0x808000D8: lwc1        $f8, 0x4($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
            goto L_8080013C;
    }
    goto skip_1;
    // 0x808000D8: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x808000DC: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
    // 0x808000E0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808000E4: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808000E8: bgezl       $t8, L_80800104
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000EC: lwc1        $f4, 0x4($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80800104;
    }
    goto skip_2;
    // 0x808000EC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    skip_2:
    // 0x808000F0: jal         0x800DBEFC
    // 0x808000F4: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_3;
    // 0x808000F4: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    after_3:
    // 0x808000F8: b           L_80800170
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800170;
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
L_80800104:
    // 0x80800104: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80800108: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x8080010C: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80800110: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800114: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80800118: nop

    // 0x8080011C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800120: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800124: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80800128: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8080012C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800130: b           L_8080016C
    // 0x80800134: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
        goto L_8080016C;
    // 0x80800134: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80800138: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
L_8080013C:
    // 0x8080013C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80800140: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x80800144: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80800148: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8080014C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80800150: nop

    // 0x80800154: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800158: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8080015C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80800160: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x80800164: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800168: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
L_8080016C:
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800170:
    // 0x80800170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void bswasher_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801418: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080141C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1E90) << 16);
    // 0x80801420: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801424: jr          $ra
    // 0x80801428: lw          $v0, 0x1E90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E90));
    return;
    // 0x80801428: lw          $v0, 0x1E90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E90));
;}
RECOMP_FUNC void func_80102CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102CF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102CFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80102D00: lwc1        $f14, 0x54($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80102D04: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80102D08: jal         0x800F20BC
    // 0x80102D0C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800F20BC(rdram, ctx);
        goto after_0;
    // 0x80102D0C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x80102D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102D14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102D18: jr          $ra
    // 0x80102D1C: nop

    return;
    // 0x80102D1C: nop

;}
RECOMP_FUNC void func_80801344_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801348: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080134C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801350: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    // 0x80801354: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80801358: jal         0x8008FE94
    // 0x8080135C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8008FE94(rdram, ctx);
        goto after_0;
    // 0x8080135C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x80801360: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801364: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801368: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080136C: lwc1        $f4, 0x1C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80801370: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801374: jal         0x80090010
    // 0x80801378: swc1        $f8, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f8.u32l;
    func_80090010(rdram, ctx);
        goto after_1;
    // 0x80801378: swc1        $f8, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x8080137C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801380: jal         0x808013DC
    // 0x80801384: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_808013DC_chevilspirit(rdram, ctx);
        goto after_2;
    // 0x80801384: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x80801388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080138C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801390: jr          $ra
    // 0x80801394: nop

    return;
    // 0x80801394: nop

;}
RECOMP_FUNC void _chhotwaterpoolbits_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086448: syscall     323
    recomp_syscall_handler(rdram, ctx, 0x80086448);
    return;
    // 0x8008644C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void fxegg_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800360: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800364: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800368: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080036C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800370: jal         0x800B5BE4
    // 0x80800374: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800374: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_0:
    // 0x80800378: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8080037C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800380: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800384: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800388: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8080038C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800390: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800394: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800398: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8080039C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003A0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808003A4: sll         $t3, $a3, 16
    ctx->r11 = S32(ctx->r7 << 16);
    // 0x808003A8: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    // 0x808003AC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808003B0: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x808003B4: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x808003B8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x808003BC: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808003C0: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x808003C4: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x808003C8: jal         0x800BA930
    // 0x808003CC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800BA930(rdram, ctx);
        goto after_1;
    // 0x808003CC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x808003D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003D4: jal         0x800BA3FC
    // 0x808003D8: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    func_800BA3FC(rdram, ctx);
        goto after_2;
    // 0x808003D8: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    after_2:
    // 0x808003DC: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2834, 0X630) << 16);
    // 0x808003E0: addiu       $t5, $t5, 0x630
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2834, 0X630));
    // 0x808003E4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808003E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808003F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003F4: jal         0x800BABB8
    // 0x808003F8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x808003F8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x808003FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800400: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800404: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800408: jr          $ra
    // 0x8080040C: nop

    return;
    // 0x8080040C: nop

;}
RECOMP_FUNC void _gcgoto_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A60: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087A60);
    return;
    // 0x80087A64: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800FA6B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA6B8: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FA6BC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FA6C0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800FA6C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FA6C8: addiu       $t7, $t7, 0x3880
    ctx->r15 = ADD32(ctx->r15, 0X3880);
    // 0x800FA6CC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FA6D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FA6D4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA6D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800FA6DC: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x800FA6E0: jal         0x8008A598
    // 0x800FA6E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _scinfobar_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800FA6E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800FA6E8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA6EC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800FA6F0: jal         0x8008A5C0
    // 0x800FA6F4: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    _scinfobar_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x800FA6F4: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    after_1:
    // 0x800FA6F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FA6FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FA700: jr          $ra
    // 0x800FA704: nop

    return;
    // 0x800FA704: nop

;}
RECOMP_FUNC void func_808007CC_chsunlightspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808007D4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808007D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808007DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007E0: beq         $a1, $at, L_80800810
    if (ctx->r5 == ctx->r1) {
        // 0x808007E4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800810;
    }
    // 0x808007E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007E8: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x808007EC: bne         $a1, $at, L_80800820
    if (ctx->r5 != ctx->r1) {
        // 0x808007F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800820;
    }
    // 0x808007F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808007F4: jal         0x8008A490
    // 0x808007F8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808007F8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808007FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800800: jal         0x80800404
    // 0x80800804: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800404_chsunlightspell(rdram, ctx);
        goto after_1;
    // 0x80800804: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800808: b           L_80800820
    // 0x8080080C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800820;
    // 0x8080080C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800810:
    // 0x80800810: jal         0x800FFA88
    // 0x80800814: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80800814: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    after_2:
    // 0x80800818: b           L_80800820
    // 0x8080081C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800820;
    // 0x8080081C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800820:
    // 0x80800820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800828: jr          $ra
    // 0x8080082C: nop

    return;
    // 0x8080082C: nop

;}
RECOMP_FUNC void bastick_distance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EF04: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009EF08: jr          $ra
    // 0x8009EF0C: lwc1        $f0, 0x60($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X60);
    return;
    // 0x8009EF0C: lwc1        $f0, 0x60($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X60);
;}
RECOMP_FUNC void func_808000B0_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B4: slti        $at, $a1, 0xAD
    ctx->r1 = SIGNED(ctx->r5) < 0XAD ? 1 : 0;
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000C0: bne         $at, $zero, L_808000EC
    if (ctx->r1 != 0) {
        // 0x808000C4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808000EC;
    }
    // 0x808000C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808000C8: addiu       $t6, $a1, -0x167
    ctx->r14 = ADD32(ctx->r5, -0X167);
    // 0x808000CC: sltiu       $at, $t6, 0x33
    ctx->r1 = ctx->r14 < 0X33 ? 1 : 0;
    // 0x808000D0: beq         $at, $zero, L_80800134
    if (ctx->r1 == 0) {
        // 0x808000D4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800134;
    }
    // 0x808000D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808000D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1648, 0X6F0) << 16);
    // 0x808000DC: addu        $at, $at, $t6
    gpr jr_addend_808000E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808000E0: lw          $t6, 0x6F0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1648, 0X6F0));
    // 0x808000E4: jr          $t6
    // 0x808000E8: nop

    switch (jr_addend_808000E4 >> 2) {
        case 0: goto L_80800134; break;
        case 1: goto L_80800134; break;
        case 2: goto L_80800134; break;
        case 3: goto L_80800134; break;
        case 4: goto L_80800134; break;
        case 5: goto L_80800134; break;
        case 6: goto L_80800134; break;
        case 7: goto L_80800134; break;
        case 8: goto L_80800134; break;
        case 9: goto L_80800134; break;
        case 10: goto L_80800134; break;
        case 11: goto L_80800134; break;
        case 12: goto L_80800134; break;
        case 13: goto L_80800134; break;
        case 14: goto L_80800134; break;
        case 15: goto L_80800134; break;
        case 16: goto L_80800134; break;
        case 17: goto L_80800134; break;
        case 18: goto L_80800134; break;
        case 19: goto L_80800134; break;
        case 20: goto L_80800134; break;
        case 21: goto L_80800134; break;
        case 22: goto L_80800134; break;
        case 23: goto L_80800118; break;
        case 24: goto L_80800134; break;
        case 25: goto L_80800134; break;
        case 26: goto L_80800134; break;
        case 27: goto L_80800134; break;
        case 28: goto L_80800134; break;
        case 29: goto L_80800134; break;
        case 30: goto L_80800134; break;
        case 31: goto L_80800134; break;
        case 32: goto L_80800134; break;
        case 33: goto L_80800134; break;
        case 34: goto L_80800134; break;
        case 35: goto L_80800134; break;
        case 36: goto L_80800130; break;
        case 37: goto L_80800118; break;
        case 38: goto L_80800118; break;
        case 39: goto L_80800118; break;
        case 40: goto L_80800118; break;
        case 41: goto L_80800118; break;
        case 42: goto L_80800128; break;
        case 43: goto L_80800120; break;
        case 44: goto L_80800120; break;
        case 45: goto L_80800120; break;
        case 46: goto L_80800120; break;
        case 47: goto L_80800128; break;
        case 48: goto L_80800120; break;
        case 49: goto L_80800120; break;
        case 50: goto L_80800120; break;
        default: switch_error(__func__, 0x808000E4, 0x808006F0);
    }
    // 0x808000E8: nop

L_808000EC:
    // 0x808000EC: addiu       $t7, $a1, -0xA1
    ctx->r15 = ADD32(ctx->r5, -0XA1);
    // 0x808000F0: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x808000F4: beq         $at, $zero, L_80800134
    if (ctx->r1 == 0) {
        // 0x808000F8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800134;
    }
    // 0x808000F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1648, 0X7BC) << 16);
    // 0x80800100: addu        $at, $at, $t7
    gpr jr_addend_80800108 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800104: lw          $t7, 0x7BC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1648, 0X7BC));
    // 0x80800108: jr          $t7
    // 0x8080010C: nop

    switch (jr_addend_80800108 >> 2) {
        case 0: goto L_80800110; break;
        case 1: goto L_80800110; break;
        case 2: goto L_80800110; break;
        case 3: goto L_80800110; break;
        case 4: goto L_80800110; break;
        case 5: goto L_80800110; break;
        case 6: goto L_80800110; break;
        case 7: goto L_80800110; break;
        case 8: goto L_80800110; break;
        case 9: goto L_80800110; break;
        case 10: goto L_80800110; break;
        case 11: goto L_80800110; break;
        default: switch_error(__func__, 0x80800108, 0x808007BC);
    }
    // 0x8080010C: nop

L_80800110:
    // 0x80800110: b           L_80800134
    // 0x80800114: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80800134;
    // 0x80800114: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80800118:
    // 0x80800118: b           L_80800134
    // 0x8080011C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80800134;
    // 0x8080011C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80800120:
    // 0x80800120: b           L_80800134
    // 0x80800124: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80800134;
    // 0x80800124: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80800128:
    // 0x80800128: b           L_80800134
    // 0x8080012C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80800134;
    // 0x8080012C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80800130:
    // 0x80800130: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800134:
    // 0x80800134: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80800138: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1648, 0X8A8) << 16);
    // 0x8080013C: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80800140: lw          $a0, 0x8A8($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1648, 0X8A8));
    // 0x80800144: beql        $a0, $zero, L_80800164
    if (ctx->r4 == 0) {
        // 0x80800148: lbu         $t2, 0x79($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X79);
            goto L_80800164;
    }
    goto skip_0;
    // 0x80800148: lbu         $t2, 0x79($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X79);
    skip_0:
    // 0x8080014C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80800150: jal         0x80088178
    // 0x80800154: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800158: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: lbu         $t2, 0x79($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X79);
L_80800164:
    // 0x80800164: sll         $t1, $v1, 4
    ctx->r9 = S32(ctx->r3 << 4);
    // 0x80800168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080016C: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80800170: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800174: sb          $t4, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r12;
    // 0x80800178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080017C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void chlagoonbits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1052, 0X924) << 16);
    // 0x80800034: jr          $ra
    // 0x80800038: addiu       $v0, $v0, 0x924
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1052, 0X924));
    return;
    // 0x80800038: addiu       $v0, $v0, 0x924
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1052, 0X924));
;}
RECOMP_FUNC void _capod_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085720: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085720);
    return;
    // 0x80085724: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _badata_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846B0: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846B0);
    return;
    // 0x800846B4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80801178_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080117C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801180: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    // 0x80801184: jal         0x8080101C
    // 0x80801188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080101C_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080118C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801194: jr          $ra
    // 0x80801198: nop

    return;
    // 0x80801198: nop

;}
RECOMP_FUNC void gcegg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2678, 0X200) << 16);
    // 0x80800004: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2678, 0X270) << 16);
    // 0x80800008: addiu       $v0, $v0, 0x270
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2678, 0X270));
    // 0x8080000C: addiu       $v1, $v1, 0x200
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2678, 0X200));
    // 0x80800010: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
L_80800014:
    // 0x80800014: bnel        $a0, $t6, L_80800028
    if (ctx->r4 != ctx->r14) {
        // 0x80800018: lh          $t7, 0xE($v1)
        ctx->r15 = MEM_H(ctx->r3, 0XE);
            goto L_80800028;
    }
    goto skip_0;
    // 0x80800018: lh          $t7, 0xE($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XE);
    skip_0:
    // 0x8080001C: jr          $ra
    // 0x80800020: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    return;
    // 0x80800020: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x80800024: lh          $t7, 0xE($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XE);
L_80800028:
    // 0x80800028: bnel        $a0, $t7, L_8080003C
    if (ctx->r4 != ctx->r15) {
        // 0x8080002C: lh          $t8, 0x1C($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X1C);
            goto L_8080003C;
    }
    goto skip_1;
    // 0x8080002C: lh          $t8, 0x1C($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X1C);
    skip_1:
    // 0x80800030: jr          $ra
    // 0x80800034: lbu         $v0, 0x16($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X16);
    return;
    // 0x80800034: lbu         $v0, 0x16($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X16);
    // 0x80800038: lh          $t8, 0x1C($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X1C);
L_8080003C:
    // 0x8080003C: bnel        $a0, $t8, L_80800050
    if (ctx->r4 != ctx->r24) {
        // 0x80800040: lh          $t9, 0x2A($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X2A);
            goto L_80800050;
    }
    goto skip_2;
    // 0x80800040: lh          $t9, 0x2A($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2A);
    skip_2:
    // 0x80800044: jr          $ra
    // 0x80800048: lbu         $v0, 0x24($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X24);
    return;
    // 0x80800048: lbu         $v0, 0x24($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X24);
    // 0x8080004C: lh          $t9, 0x2A($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2A);
L_80800050:
    // 0x80800050: bnel        $a0, $t9, L_80800064
    if (ctx->r4 != ctx->r25) {
        // 0x80800054: addiu       $v1, $v1, 0x38
        ctx->r3 = ADD32(ctx->r3, 0X38);
            goto L_80800064;
    }
    goto skip_3;
    // 0x80800054: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    skip_3:
    // 0x80800058: jr          $ra
    // 0x8080005C: lbu         $v0, 0x32($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X32);
    return;
    // 0x8080005C: lbu         $v0, 0x32($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X32);
    // 0x80800060: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
L_80800064:
    // 0x80800064: bnel        $v1, $v0, L_80800014
    if (ctx->r3 != ctx->r2) {
        // 0x80800068: lh          $t6, 0x0($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X0);
            goto L_80800014;
    }
    goto skip_4;
    // 0x80800068: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    skip_4:
    // 0x8080006C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_8080000C_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800020: jal         0x80100094
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800028: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080002C: jal         0x800DA524
    // 0x80800030: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800034: jal         0x800DA524
    // 0x80800038: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8080003C: jal         0x800DA524
    // 0x80800040: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x80800040: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x80800044: jal         0x800DA524
    // 0x80800048: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x80800048: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x8080004C: jal         0x800DA524
    // 0x80800050: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800DA524(rdram, ctx);
        goto after_5;
    // 0x80800050: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x80800054: jal         0x800DA298
    // 0x80800058: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800058: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    after_6:
    // 0x8080005C: beql        $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x80800060: lui         $a1, 0x3FB3
        ctx->r5 = S32(0X3FB3 << 16);
            goto L_80800098;
    }
    goto skip_0;
    // 0x80800060: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    skip_0:
    // 0x80800064: jal         0x80088848
    // 0x80800068: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_7;
    // 0x80800068: nop

    after_7:
    // 0x8080006C: bnel        $v0, $zero, L_80800098
    if (ctx->r2 != 0) {
        // 0x80800070: lui         $a1, 0x3FB3
        ctx->r5 = S32(0X3FB3 << 16);
            goto L_80800098;
    }
    goto skip_1;
    // 0x80800070: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    skip_1:
    // 0x80800074: jal         0x800DA544
    // 0x80800078: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x80800078: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
    // 0x8080007C: jal         0x800861A8
    // 0x80800080: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800080: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x80800084: jal         0x800FFAB0
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080008C: b           L_808003F8
    // 0x80800090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003F8;
    // 0x80800090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800094: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
L_80800098:
    // 0x80800098: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080009C: jal         0x80102FDC
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_11;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808000A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000A8: sb          $t6, 0x494($s1)
    MEM_B(0X494, ctx->r17) = ctx->r14;
    // 0x808000AC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(832, 0X2D8C) << 16);
    // 0x808000B0: lh          $t7, 0x2D8C($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(832, 0X2D8C));
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2B40) << 16);
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: sb          $t7, 0x495($s1)
    MEM_B(0X495, ctx->r17) = ctx->r15;
    // 0x808000C0: lwc1        $f4, 0x2B40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(832, 0X2B40));
    // 0x808000C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C8: jal         0x80109FE8
    // 0x808000CC: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    func_80109FE8(rdram, ctx);
        goto after_12;
    // 0x808000CC: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    after_12:
    // 0x808000D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808000D8: jal         0x800EE7F8
    // 0x808000DC: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x808000DC: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    after_13:
    // 0x808000E0: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x808000E4: jal         0x800EE7F8
    // 0x808000E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x808000E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_14:
    // 0x808000EC: addiu       $a0, $s1, 0x34
    ctx->r4 = ADD32(ctx->r17, 0X34);
    // 0x808000F0: jal         0x800EE7F8
    // 0x808000F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x808000F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_15:
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800100:
    // 0x80800100: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800104: jal         0x80802AD8
    // 0x80800108: sw          $a1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r5;
    func_80802AD8_chinflatableboss(rdram, ctx);
        goto after_16;
    // 0x80800108: sw          $a1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r5;
    after_16:
    // 0x8080010C: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x80800110: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800114: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800118: bnel        $a1, $at, L_80800100
    if (ctx->r5 != ctx->r1) {
        // 0x8080011C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800100;
    }
    goto skip_2;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800120: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    // 0x80800124: jal         0x8008A4E0
    // 0x80800128: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieDll_entrypoint_10(rdram, ctx);
        goto after_17;
    // 0x80800128: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_17:
    // 0x8080012C: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    // 0x80800130: jal         0x8008A4E0
    // 0x80800134: addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    _subaddieDll_entrypoint_10(rdram, ctx);
        goto after_18;
    // 0x80800134: addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    after_18:
    // 0x80800138: jal         0x8080183C
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080183C_chinflatableboss(rdram, ctx);
        goto after_19;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x8010A85C
    // 0x80800148: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A85C(rdram, ctx);
        goto after_20;
    // 0x80800148: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_20:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800154: jal         0x800897C0
    // 0x80800158: addiu       $a2, $zero, 0x3A
    ctx->r6 = ADD32(0, 0X3A);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_21;
    // 0x80800158: addiu       $a2, $zero, 0x3A
    ctx->r6 = ADD32(0, 0X3A);
    after_21:
    // 0x8080015C: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80800160: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: addiu       $a1, $zero, 0x437
    ctx->r5 = ADD32(0, 0X437);
    // 0x8080016C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80800170: jal         0x8008A0C8
    // 0x80800174: addiu       $a3, $s1, 0x70
    ctx->r7 = ADD32(ctx->r17, 0X70);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x80800174: addiu       $a3, $s1, 0x70
    ctx->r7 = ADD32(ctx->r17, 0X70);
    after_22:
    // 0x80800178: sw          $v0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->r2;
    // 0x8080017C: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80800180: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: addiu       $a1, $zero, 0x437
    ctx->r5 = ADD32(0, 0X437);
    // 0x8080018C: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x80800190: jal         0x8008A0C8
    // 0x80800194: addiu       $a3, $s1, 0x254
    ctx->r7 = ADD32(ctx->r17, 0X254);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_23;
    // 0x80800194: addiu       $a3, $s1, 0x254
    ctx->r7 = ADD32(ctx->r17, 0X254);
    after_23:
    // 0x80800198: sw          $v0, 0x250($s1)
    MEM_W(0X250, ctx->r17) = ctx->r2;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: addiu       $a1, $zero, 0x3DA
    ctx->r5 = ADD32(0, 0X3DA);
    // 0x808001A4: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x808001A8: jal         0x8008A0C0
    // 0x808001AC: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    _subaddiemarker_entrypoint_0(rdram, ctx);
        goto after_24;
    // 0x808001AC: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_24:
    // 0x808001B0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x808001B4: blez        $v0, L_80800228
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808001B8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800228;
    }
    // 0x808001B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001BC: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
L_808001C0:
    // 0x808001C0: blez        $a3, L_808001E8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x808001C4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808001E8;
    }
    // 0x808001C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808001C8: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
L_808001CC:
    // 0x808001CC: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x808001D0: addiu       $t0, $a2, 0x32
    ctx->r8 = ADD32(ctx->r6, 0X32);
    // 0x808001D4: beql        $t0, $t1, L_808001EC
    if (ctx->r8 == ctx->r9) {
        // 0x808001D8: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_808001EC;
    }
    goto skip_3;
    // 0x808001D8: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    skip_3:
    // 0x808001DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808001E0: bne         $v1, $a3, L_808001CC
    if (ctx->r3 != ctx->r7) {
        // 0x808001E4: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_808001CC;
    }
    // 0x808001E4: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
L_808001E8:
    // 0x808001E8: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
L_808001EC:
    // 0x808001EC: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x808001F0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x808001F4: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x808001F8: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x808001FC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800200: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80800204: jal         0x800EE7F8
    // 0x80800208: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800EE7F8(rdram, ctx);
        goto after_25;
    // 0x80800208: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_25:
    // 0x8080020C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80800210: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80800214: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800218: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8080021C: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80800220: bne         $at, $zero, L_808001C0
    if (ctx->r1 != 0) {
        // 0x80800224: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_808001C0;
    }
    // 0x80800224: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
L_80800228:
    // 0x80800228: jal         0x800DA298
    // 0x8080022C: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    func_800DA298(rdram, ctx);
        goto after_26;
    // 0x8080022C: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    after_26:
    // 0x80800230: beq         $v0, $zero, L_80800244
    if (ctx->r2 == 0) {
        // 0x80800234: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80800244;
    }
    // 0x80800234: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800238: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8080023C: b           L_80800248
    // 0x80800240: sb          $t4, 0x498($s1)
    MEM_B(0X498, ctx->r17) = ctx->r12;
        goto L_80800248;
    // 0x80800240: sb          $t4, 0x498($s1)
    MEM_B(0X498, ctx->r17) = ctx->r12;
L_80800244:
    // 0x80800244: sb          $t5, 0x498($s1)
    MEM_B(0X498, ctx->r17) = ctx->r13;
L_80800248:
    // 0x80800248: jal         0x800F54E4
    // 0x8080024C: nop

    func_800F54E4(rdram, ctx);
        goto after_27;
    // 0x8080024C: nop

    after_27:
    // 0x80800250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800254: jal         0x800F64A4
    // 0x80800258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_28;
    // 0x80800258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x8080025C: bne         $v0, $zero, L_80800268
    if (ctx->r2 != 0) {
        // 0x80800260: nop
    
            goto L_80800268;
    }
    // 0x80800260: nop

    // 0x80800264: sb          $zero, 0x498($s1)
    MEM_B(0X498, ctx->r17) = 0;
L_80800268:
    // 0x80800268: jal         0x80088848
    // 0x8080026C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_29;
    // 0x8080026C: nop

    after_29:
    // 0x80800270: beq         $v0, $zero, L_808002AC
    if (ctx->r2 == 0) {
        // 0x80800274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002AC;
    }
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x8010A85C
    // 0x8080027C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_30;
    // 0x8080027C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80800280: jal         0x80086B18
    // 0x80800284: nop

    _chcredits_entrypoint_1(rdram, ctx);
        goto after_31;
    // 0x80800284: nop

    after_31:
    // 0x80800288: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x8080028C: bne         $v0, $at, L_8080029C
    if (ctx->r2 != ctx->r1) {
        // 0x80800290: addiu       $a1, $zero, 0x13
        ctx->r5 = ADD32(0, 0X13);
            goto L_8080029C;
    }
    // 0x80800290: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80800294: b           L_8080029C
    // 0x80800298: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
        goto L_8080029C;
    // 0x80800298: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
L_8080029C:
    // 0x8080029C: jal         0x80800F84
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_32;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x808002A4: b           L_808003F8
    // 0x808002A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003F8;
    // 0x808002A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002AC:
    // 0x808002AC: lbu         $t6, 0x498($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X498);
    // 0x808002B0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808002B4: bne         $t6, $at, L_80800364
    if (ctx->r14 != ctx->r1) {
        // 0x808002B8: nop
    
            goto L_80800364;
    }
    // 0x808002B8: nop

    // 0x808002BC: jal         0x800F54E4
    // 0x808002C0: nop

    func_800F54E4(rdram, ctx);
        goto after_33;
    // 0x808002C0: nop

    after_33:
    // 0x808002C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808002C8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808002CC: sb          $v1, 0x49C($s1)
    MEM_B(0X49C, ctx->r17) = ctx->r3;
    // 0x808002D0: sb          $v1, 0x496($s1)
    MEM_B(0X496, ctx->r17) = ctx->r3;
    // 0x808002D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D8: jal         0x800F608C
    // 0x808002DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_34;
    // 0x808002DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
    // 0x808002E0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002E4: jal         0x800F8294
    // 0x808002E8: addiu       $a1, $s1, 0x54
    ctx->r5 = ADD32(ctx->r17, 0X54);
    func_800F8294(rdram, ctx);
        goto after_35;
    // 0x808002E8: addiu       $a1, $s1, 0x54
    ctx->r5 = ADD32(ctx->r17, 0X54);
    after_35:
    // 0x808002EC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808002F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002F4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808002F8: jal         0x800F8300
    // 0x808002FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F8300(rdram, ctx);
        goto after_36;
    // 0x808002FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_36:
    // 0x80800300: jal         0x800F497C
    // 0x80800304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F497C(rdram, ctx);
        goto after_37;
    // 0x80800304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_37:
    // 0x80800308: jal         0x800878F8
    // 0x8080030C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _plcamera_entrypoint_8(rdram, ctx);
        goto after_38;
    // 0x8080030C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_38:
    // 0x80800310: jal         0x800DA544
    // 0x80800314: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DA544(rdram, ctx);
        goto after_39;
    // 0x80800314: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_39:
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80800320: jal         0x80802A00
    // 0x80800324: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_40;
    // 0x80800324: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_40:
    // 0x80800328: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080032C: addiu       $t7, $zero, 0x3A
    ctx->r15 = ADD32(0, 0X3A);
    // 0x80800330: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800334: addiu       $a1, $zero, 0x1087
    ctx->r5 = ADD32(0, 0X1087);
    // 0x80800338: addiu       $a2, $zero, 0x107
    ctx->r6 = ADD32(0, 0X107);
    // 0x8080033C: jal         0x8008A208
    // 0x80800340: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_41;
    // 0x80800340: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_41:
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x80800F84
    // 0x8080034C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_42;
    // 0x8080034C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_42:
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: jal         0x8010A85C
    // 0x80800358: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_43;
    // 0x80800358: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_43:
    // 0x8080035C: b           L_808003F8
    // 0x80800360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003F8;
    // 0x80800360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800364:
    // 0x80800364: jal         0x800D395C
    // 0x80800368: nop

    func_800D395C(rdram, ctx);
        goto after_44;
    // 0x80800368: nop

    after_44:
    // 0x8080036C: beql        $v0, $zero, L_808003E4
    if (ctx->r2 == 0) {
        // 0x80800370: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_808003E4;
    }
    goto skip_4;
    // 0x80800370: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_4:
    // 0x80800374: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800378: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8080037C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80800380: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800384: jal         0x800F54E4
    // 0x80800388: sb          $t1, 0x498($s1)
    MEM_B(0X498, ctx->r17) = ctx->r9;
    func_800F54E4(rdram, ctx);
        goto after_45;
    // 0x80800388: sb          $t1, 0x498($s1)
    MEM_B(0X498, ctx->r17) = ctx->r9;
    after_45:
    // 0x8080038C: jal         0x800F497C
    // 0x80800390: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F497C(rdram, ctx);
        goto after_46;
    // 0x80800390: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_46:
    // 0x80800394: jal         0x800F54E4
    // 0x80800398: nop

    func_800F54E4(rdram, ctx);
        goto after_47;
    // 0x80800398: nop

    after_47:
    // 0x8080039C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x808003A0: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x808003A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003A8: jal         0x800F49D4
    // 0x808003AC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_48;
    // 0x808003AC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_48:
    // 0x808003B0: jal         0x800F54E4
    // 0x808003B4: nop

    func_800F54E4(rdram, ctx);
        goto after_49;
    // 0x808003B4: nop

    after_49:
    // 0x808003B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003BC: addiu       $a1, $s1, 0x48
    ctx->r5 = ADD32(ctx->r17, 0X48);
    // 0x808003C0: jal         0x800F4A58
    // 0x808003C4: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800F4A58(rdram, ctx);
        goto after_50;
    // 0x808003C4: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_50:
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x808003D0: jal         0x80802A00
    // 0x808003D4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_51;
    // 0x808003D4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_51:
    // 0x808003D8: b           L_808003F8
    // 0x808003DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003F8;
    // 0x808003DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003E0: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_808003E4:
    // 0x808003E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003E8: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x808003EC: jal         0x800861A8
    // 0x808003F0: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_52;
    // 0x808003F0: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    after_52:
    // 0x808003F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003F8:
    // 0x808003F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808003FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800400: jr          $ra
    // 0x80800404: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80800404: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800D4D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4D5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D4D60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D4D64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D4D68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800D4D6C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D4D70: jal         0x800EA600
    // 0x800D4D74: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    func_800EA600(rdram, ctx);
        goto after_0;
    // 0x800D4D74: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    after_0:
    // 0x800D4D78: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x800D4D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4D80: jalr        $t9
    // 0x800D4D84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D4D84: nop

    after_1:
    // 0x800D4D88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800D4D8C: jal         0x800C68AC
    // 0x800D4D90: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C68AC(rdram, ctx);
        goto after_2;
    // 0x800D4D90: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800D4D94: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800D4D98: jal         0x800C68CC
    // 0x800D4D9C: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    func_800C68CC(rdram, ctx);
        goto after_3;
    // 0x800D4D9C: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    after_3:
    // 0x800D4DA0: jal         0x800C65E0
    // 0x800D4DA4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800C65E0(rdram, ctx);
        goto after_4;
    // 0x800D4DA4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x800D4DA8: jal         0x800EA614
    // 0x800D4DAC: nop

    func_800EA614(rdram, ctx);
        goto after_5;
    // 0x800D4DAC: nop

    after_5:
    // 0x800D4DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4DB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4DB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D4DBC: jr          $ra
    // 0x800D4DC0: nop

    return;
    // 0x800D4DC0: nop

    // 0x800D4DC4: nop

    // 0x800D4DC8: nop

    // 0x800D4DCC: nop

;}
