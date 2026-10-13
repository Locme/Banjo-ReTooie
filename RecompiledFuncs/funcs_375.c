#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800D14_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D20: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800D24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D28: jal         0x80100094
    // 0x80800D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D30: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800D34: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800D38: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800D3C: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800D40: beq         $t6, $at, L_80800D60
    if (ctx->r14 == ctx->r1) {
        // 0x80800D44: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800D60;
    }
    // 0x80800D44: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800D48: beq         $t6, $at, L_80800D88
    if (ctx->r14 == ctx->r1) {
        // 0x80800D4C: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_80800D88;
    }
    // 0x80800D4C: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80800D50: beq         $t6, $at, L_80800D78
    if (ctx->r14 == ctx->r1) {
        // 0x80800D54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D78;
    }
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D58: b           L_80800D8C
    // 0x80800D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800D8C;
    // 0x80800D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D60:
    // 0x80800D60: jal         0x800F54E4
    // 0x80800D64: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800D64: nop

    after_1:
    // 0x80800D68: jal         0x800F4CC0
    // 0x80800D6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_2;
    // 0x80800D6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800D70: b           L_80800D8C
    // 0x80800D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800D8C;
    // 0x80800D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D78:
    // 0x80800D78: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80800D7C: addiu       $a1, $zero, 0x8A0
    ctx->r5 = ADD32(0, 0X8A0);
    // 0x80800D80: jal         0x80103140
    // 0x80800D84: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    func_80103140(rdram, ctx);
        goto after_3;
    // 0x80800D84: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    after_3:
L_80800D88:
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D8C:
    // 0x80800D8C: jal         0x80102424
    // 0x80800D90: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800D90: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800D94: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80800D98: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800D9C: addiu       $t0, $t9, -0x3
    ctx->r8 = ADD32(ctx->r25, -0X3);
    // 0x80800DA0: sltiu       $at, $t0, 0xD
    ctx->r1 = ctx->r8 < 0XD ? 1 : 0;
    // 0x80800DA4: beq         $at, $zero, L_80800E70
    if (ctx->r1 == 0) {
        // 0x80800DA8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800E70;
    }
    // 0x80800DA8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800DAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X36D0) << 16);
    // 0x80800DB0: addu        $at, $at, $t0
    gpr jr_addend_80800DB8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800DB4: lw          $t0, 0x36D0($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X36D0));
    // 0x80800DB8: jr          $t0
    // 0x80800DBC: nop

    switch (jr_addend_80800DB8 >> 2) {
        case 0: goto L_80800DC0; break;
        case 1: goto L_80800DD0; break;
        case 2: goto L_80800E00; break;
        case 3: goto L_80800E1C; break;
        case 4: goto L_80800E68; break;
        case 5: goto L_80800E70; break;
        case 6: goto L_80800E70; break;
        case 7: goto L_80800E70; break;
        case 8: goto L_80800E70; break;
        case 9: goto L_80800E70; break;
        case 10: goto L_80800E70; break;
        case 11: goto L_80800E70; break;
        case 12: goto L_80800E70; break;
        default: switch_error(__func__, 0x80800DB8, 0x808036D0);
    }
    // 0x80800DBC: nop

L_80800DC0:
    // 0x80800DC0: jal         0x800903D0
    // 0x80800DC4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800903D0(rdram, ctx);
        goto after_5;
    // 0x80800DC4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800DC8: b           L_80800E70
    // 0x80800DCC: nop

        goto L_80800E70;
    // 0x80800DCC: nop

L_80800DD0:
    // 0x80800DD0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80800DD4: jal         0x800904F4
    // 0x80800DD8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800904F4(rdram, ctx);
        goto after_6;
    // 0x80800DD8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80800DDC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80800DE0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800DE4: jal         0x800F54E4
    // 0x80800DE8: sb          $v1, 0x100($t1)
    MEM_B(0X100, ctx->r9) = ctx->r3;
    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800DE8: sb          $v1, 0x100($t1)
    MEM_B(0X100, ctx->r9) = ctx->r3;
    after_7:
    // 0x80800DEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DF0: jal         0x800F4CEC
    // 0x80800DF4: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    func_800F4CEC(rdram, ctx);
        goto after_8;
    // 0x80800DF4: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    after_8:
    // 0x80800DF8: b           L_80800E70
    // 0x80800DFC: nop

        goto L_80800E70;
    // 0x80800DFC: nop

L_80800E00:
    // 0x80800E00: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80800E04: jal         0x800904F4
    // 0x80800E08: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800904F4(rdram, ctx);
        goto after_9;
    // 0x80800E08: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x80800E0C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80800E10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800E14: b           L_80800E70
    // 0x80800E18: sb          $v1, 0x100($t2)
    MEM_B(0X100, ctx->r10) = ctx->r3;
        goto L_80800E70;
    // 0x80800E18: sb          $v1, 0x100($t2)
    MEM_B(0X100, ctx->r10) = ctx->r3;
L_80800E1C:
    // 0x80800E1C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800E20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3704) << 16);
    // 0x80800E24: lwc1        $f4, 0x3704($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3704));
    // 0x80800E28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800E2C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800E30: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800E34: sb          $v1, 0xF0($a2)
    MEM_B(0XF0, ctx->r6) = ctx->r3;
    // 0x80800E38: sb          $v1, 0xF1($a2)
    MEM_B(0XF1, ctx->r6) = ctx->r3;
    // 0x80800E3C: addiu       $v0, $a2, 0x2
    ctx->r2 = ADD32(ctx->r6, 0X2);
    // 0x80800E40: swc1        $f4, 0xDC($a2)
    MEM_W(0XDC, ctx->r6) = ctx->f4.u32l;
L_80800E44:
    // 0x80800E44: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800E48: sb          $v1, 0xF1($v0)
    MEM_B(0XF1, ctx->r2) = ctx->r3;
    // 0x80800E4C: sb          $v1, 0xF2($v0)
    MEM_B(0XF2, ctx->r2) = ctx->r3;
    // 0x80800E50: sb          $v1, 0xF3($v0)
    MEM_B(0XF3, ctx->r2) = ctx->r3;
    // 0x80800E54: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800E58: bne         $a0, $a1, L_80800E44
    if (ctx->r4 != ctx->r5) {
        // 0x80800E5C: sb          $v1, 0xEC($v0)
        MEM_B(0XEC, ctx->r2) = ctx->r3;
            goto L_80800E44;
    }
    // 0x80800E5C: sb          $v1, 0xEC($v0)
    MEM_B(0XEC, ctx->r2) = ctx->r3;
    // 0x80800E60: b           L_80800E70
    // 0x80800E64: nop

        goto L_80800E70;
    // 0x80800E64: nop

L_80800E68:
    // 0x80800E68: jal         0x80800C64
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C64_chclockworkmouse(rdram, ctx);
        goto after_10;
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80800E70:
    // 0x80800E70: jal         0x80800CC0
    // 0x80800E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chclockworkmouse(rdram, ctx);
        goto after_11;
    // 0x80800E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E84: jr          $ra
    // 0x80800E88: nop

    return;
    // 0x80800E88: nop

;}
RECOMP_FUNC void _chusefeather_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085948: syscall     182
    recomp_syscall_handler(rdram, ctx, 0x80085948);
    return;
    // 0x8008594C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808004AC_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B4: jal         0x80085250
    // 0x808004B8: nop

    _basudie_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808004B8: nop

    after_0:
    // 0x808004BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004C4: jr          $ra
    // 0x808004C8: nop

    return;
    // 0x808004C8: nop

;}
RECOMP_FUNC void _subaddiedraw25d_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C08: syscall     806
    recomp_syscall_handler(rdram, ctx, 0x80089C08);
    return;
    // 0x80089C0C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800137F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800137F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800137F8: lwc1        $f14, 0x16D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16D4);
    // 0x800137FC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80013800: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80013804: or          $a1, $ra, $zero
    ctx->r5 = ctx->r31 | 0;
    // 0x80013808: jal         0x80013818
    // 0x8001380C: nop

    func_80013818(rdram, ctx);
        goto after_0;
    // 0x8001380C: nop

    after_0:
    // 0x80013810: jr          $ra
    // 0x80013814: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80013814: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_8080003C_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800040: lbu         $t6, 0x7611($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7611);
    // 0x80800044: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800048: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8080004C: bne         $t6, $at, L_80800068
    if (ctx->r14 != ctx->r1) {
        // 0x80800050: lui         $v0, 0x8080
        ctx->r2 = S32(RELOC_HI16(1636, 0X1202) << 16);
            goto L_80800068;
    }
    // 0x80800050: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1636, 0X1202) << 16);
    // 0x80800054: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80800058: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1636, 0X12BA) << 16);
    // 0x8080005C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80800060: jr          $ra
    // 0x80800064: lh          $v0, 0x12BA($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1636, 0X12BA));
    return;
    // 0x80800064: lh          $v0, 0x12BA($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1636, 0X12BA));
L_80800068:
    // 0x80800068: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8080006C: lh          $v0, 0x1202($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1636, 0X1202));
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_800AE160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE160: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AE164: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AE168: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AE16C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800AE170: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800AE174: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800AE178: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x800AE17C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800AE180: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800AE184: sll         $a1, $v1, 6
    ctx->r5 = S32(ctx->r3 << 6);
    // 0x800AE188: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x800AE18C: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AE190: beq         $at, $zero, L_800AE1BC
    if (ctx->r1 == 0) {
        // 0x800AE194: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800AE1BC;
    }
    // 0x800AE194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AE198: jal         0x8001B208
    // 0x800AE19C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    heap_realloc(rdram, ctx);
        goto after_0;
    // 0x800AE19C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AE1A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800AE1A4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800AE1A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AE1AC: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x800AE1B0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800AE1B4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800AE1B8: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
L_800AE1BC:
    // 0x800AE1BC: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x800AE1C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800AE1C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800AE1C8: addiu       $a2, $s0, 0x50
    ctx->r6 = ADD32(ctx->r16, 0X50);
    // 0x800AE1CC: jal         0x800AE820
    // 0x800AE1D0: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    func_800AE820(rdram, ctx);
        goto after_1;
    // 0x800AE1D0: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x800AE1D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE1D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AE1DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE1E0: jr          $ra
    // 0x800AE1E4: nop

    return;
    // 0x800AE1E4: nop

;}
RECOMP_FUNC void _bsbanpackwhack_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826A0: syscall     6
    recomp_syscall_handler(rdram, ctx, 0x800826A0);
    return;
    // 0x800826A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800044_chfactorysmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080004C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800050: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800058: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080005C: bne         $t7, $at, L_80800098
    if (ctx->r15 != ctx->r1) {
        // 0x80800060: addiu       $a0, $a0, 0x58
        ctx->r4 = ADD32(ctx->r4, 0X58);
            goto L_80800098;
    }
    // 0x80800060: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x80800064: jal         0x800D9078
    // 0x80800068: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800068: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080006C: beql        $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x80800070: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080009C;
    }
    goto skip_0;
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800074: jal         0x808000A8
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000A8_chfactorysmoke(rdram, ctx);
        goto after_1;
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080007C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1184, 0XF8) << 16);
    // 0x80800080: lwc1        $f12, 0xF8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1184, 0XF8));
    // 0x80800084: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1184, 0XFC) << 16);
    // 0x80800088: jal         0x800DC178
    // 0x8080008C: lwc1        $f14, 0xFC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1184, 0XFC));
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x8080008C: lwc1        $f14, 0xFC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1184, 0XFC));
    after_2:
    // 0x80800090: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800094: swc1        $f0, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f0.u32l;
L_80800098:
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080009C:
    // 0x8080009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_808002E0_chcanarymarycage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E8: jal         0x800DB9B0
    // 0x808002EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x808002EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002F0: bnel        $v0, $zero, L_8080032C
    if (ctx->r2 != 0) {
        // 0x808002F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080032C;
    }
    goto skip_0;
    // 0x808002F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002F8: jal         0x800DA298
    // 0x808002FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808002FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800300: beql        $v0, $zero, L_8080032C
    if (ctx->r2 == 0) {
        // 0x80800304: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080032C;
    }
    goto skip_1;
    // 0x80800304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800308: jal         0x800DA298
    // 0x8080030C: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080030C: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    after_2:
    // 0x80800310: bnel        $v0, $zero, L_8080032C
    if (ctx->r2 != 0) {
        // 0x80800314: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080032C;
    }
    goto skip_2;
    // 0x80800314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800318: jal         0x800DA544
    // 0x8080031C: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x8080031C: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_3:
    // 0x80800320: jal         0x800DA544
    // 0x80800324: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800324: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    after_4:
    // 0x80800328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080032C:
    // 0x8080032C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void chgameselect_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806C48: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(804, 0X84B4) << 16);
    // 0x80806C4C: jr          $ra
    // 0x80806C50: addiu       $v0, $v0, -0x7B4C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X84B4));
    return;
    // 0x80806C50: addiu       $v0, $v0, -0x7B4C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X84B4));
;}
RECOMP_FUNC void func_8080282C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080282C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802834: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802838: jal         0x800EA05C
    // 0x8080283C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080283C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802840: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x80802844: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802848: beq         $v0, $at, L_80802BA8
    if (ctx->r2 == ctx->r1) {
        // 0x8080284C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80802BA8;
    }
    // 0x8080284C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80802850: beq         $a1, $zero, L_8080287C
    if (ctx->r5 == 0) {
        // 0x80802854: lui         $at, 0xC337
        ctx->r1 = S32(0XC337 << 16);
            goto L_8080287C;
    }
    // 0x80802854: lui         $at, 0xC337
    ctx->r1 = S32(0XC337 << 16);
    // 0x80802858: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080285C: beq         $a1, $at, L_80802944
    if (ctx->r5 == ctx->r1) {
        // 0x80802860: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802944;
    }
    // 0x80802860: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802864: beq         $a1, $at, L_80802A10
    if (ctx->r5 == ctx->r1) {
        // 0x80802868: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80802A10;
    }
    // 0x80802868: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080286C: beql        $a1, $at, L_80802AE0
    if (ctx->r5 == ctx->r1) {
        // 0x80802870: lui         $at, 0xC337
        ctx->r1 = S32(0XC337 << 16);
            goto L_80802AE0;
    }
    goto skip_0;
    // 0x80802870: lui         $at, 0xC337
    ctx->r1 = S32(0XC337 << 16);
    skip_0:
    // 0x80802874: b           L_80802C24
    // 0x80802878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802C24;
    // 0x80802878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080287C:
    // 0x8080287C: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80802880: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802884: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x80802888: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080288C: nop

    // 0x80802890: bc1fl       L_80802924
    if (!c1cs) {
        // 0x80802894: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_80802924;
    }
    goto skip_1;
    // 0x80802894: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    skip_1:
    // 0x80802898: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080289C: nop

    // 0x808028A0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808028A4: nop

    // 0x808028A8: bc1fl       L_80802924
    if (!c1cs) {
        // 0x808028AC: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_80802924;
    }
    goto skip_2;
    // 0x808028AC: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    skip_2:
    // 0x808028B0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808028B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808028B8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808028BC: beq         $t7, $at, L_808028EC
    if (ctx->r15 == ctx->r1) {
        // 0x808028C0: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_808028EC;
    }
    // 0x808028C0: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x808028C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808028C8: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x808028CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808028D0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808028D4: nop

    // 0x808028D8: bc1f        L_808028EC
    if (!c1cs) {
        // 0x808028DC: nop
    
            goto L_808028EC;
    }
    // 0x808028DC: nop

    // 0x808028E0: jal         0x80802FBC
    // 0x808028E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802FBC_chstoneballcontrol(rdram, ctx);
        goto after_1;
    // 0x808028E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808028E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808028EC:
    // 0x808028EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F20) << 16);
    // 0x808028F0: lwc1        $f16, 0x4F20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F20));
    // 0x808028F4: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x808028F8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808028FC: nop

    // 0x80802900: bc1fl       L_80802C24
    if (!c1cs) {
        // 0x80802904: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802C24;
    }
    goto skip_3;
    // 0x80802904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80802908: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080290C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F24) << 16);
    // 0x80802910: lwc1        $f16, 0x4F24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F24));
    // 0x80802914: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80802918: b           L_80802C20
    // 0x8080291C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
        goto L_80802C20;
    // 0x8080291C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80802920: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
L_80802924:
    // 0x80802924: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802928: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080292C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80802930: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80802934: jal         0x80801944
    // 0x80802938: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    func_80801944_chstoneballcontrol(rdram, ctx);
        goto after_2;
    // 0x80802938: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    after_2:
    // 0x8080293C: b           L_80802C24
    // 0x80802940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802C24;
    // 0x80802940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802944:
    // 0x80802944: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x80802948: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080294C: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80802950: lui         $at, 0xC337
    ctx->r1 = S32(0XC337 << 16);
    // 0x80802954: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80802958: nop

    // 0x8080295C: bc1fl       L_808029F0
    if (!c1cs) {
        // 0x80802960: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_808029F0;
    }
    goto skip_4;
    // 0x80802960: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    skip_4:
    // 0x80802964: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802968: nop

    // 0x8080296C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80802970: nop

    // 0x80802974: bc1fl       L_808029F0
    if (!c1cs) {
        // 0x80802978: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_808029F0;
    }
    goto skip_5;
    // 0x80802978: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    skip_5:
    // 0x8080297C: lhu         $t8, 0x72($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X72);
    // 0x80802980: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802984: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80802988: beq         $t9, $at, L_808029B8
    if (ctx->r25 == ctx->r1) {
        // 0x8080298C: lui         $at, 0x4434
        ctx->r1 = S32(0X4434 << 16);
            goto L_808029B8;
    }
    // 0x8080298C: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80802990: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802994: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80802998: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080299C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808029A0: nop

    // 0x808029A4: bc1f        L_808029B8
    if (!c1cs) {
        // 0x808029A8: nop
    
            goto L_808029B8;
    }
    // 0x808029A8: nop

    // 0x808029AC: jal         0x80802FBC
    // 0x808029B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802FBC_chstoneballcontrol(rdram, ctx);
        goto after_3;
    // 0x808029B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x808029B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808029B8:
    // 0x808029B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F28) << 16);
    // 0x808029BC: lwc1        $f8, 0x4F28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F28));
    // 0x808029C0: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x808029C4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808029C8: nop

    // 0x808029CC: bc1fl       L_80802C24
    if (!c1cs) {
        // 0x808029D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802C24;
    }
    goto skip_6;
    // 0x808029D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x808029D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808029D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F2C) << 16);
    // 0x808029DC: lwc1        $f16, 0x4F2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F2C));
    // 0x808029E0: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x808029E4: b           L_80802C20
    // 0x808029E8: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
        goto L_80802C20;
    // 0x808029E8: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x808029EC: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
L_808029F0:
    // 0x808029F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808029F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808029F8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808029FC: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80802A00: jal         0x80801944
    // 0x80802A04: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    func_80801944_chstoneballcontrol(rdram, ctx);
        goto after_4;
    // 0x80802A04: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    after_4:
    // 0x80802A08: b           L_80802C24
    // 0x80802A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802C24;
    // 0x80802A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802A10:
    // 0x80802A10: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x80802A14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802A18: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80802A1C: lui         $at, 0xC337
    ctx->r1 = S32(0XC337 << 16);
    // 0x80802A20: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80802A24: nop

    // 0x80802A28: bc1fl       L_80802ABC
    if (!c1cs) {
        // 0x80802A2C: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_80802ABC;
    }
    goto skip_7;
    // 0x80802A2C: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    skip_7:
    // 0x80802A30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802A34: nop

    // 0x80802A38: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80802A3C: nop

    // 0x80802A40: bc1fl       L_80802ABC
    if (!c1cs) {
        // 0x80802A44: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_80802ABC;
    }
    goto skip_8;
    // 0x80802A44: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    skip_8:
    // 0x80802A48: lhu         $t0, 0x72($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X72);
    // 0x80802A4C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802A50: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80802A54: beq         $t1, $at, L_80802A84
    if (ctx->r9 == ctx->r1) {
        // 0x80802A58: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_80802A84;
    }
    // 0x80802A58: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    // 0x80802A5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802A60: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80802A64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80802A68: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80802A6C: nop

    // 0x80802A70: bc1f        L_80802A84
    if (!c1cs) {
        // 0x80802A74: nop
    
            goto L_80802A84;
    }
    // 0x80802A74: nop

    // 0x80802A78: jal         0x80802FBC
    // 0x80802A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802FBC_chstoneballcontrol(rdram, ctx);
        goto after_5;
    // 0x80802A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_5:
    // 0x80802A80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80802A84:
    // 0x80802A84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F30) << 16);
    // 0x80802A88: lwc1        $f6, 0x4F30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F30));
    // 0x80802A8C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80802A90: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80802A94: nop

    // 0x80802A98: bc1fl       L_80802C24
    if (!c1cs) {
        // 0x80802A9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802C24;
    }
    goto skip_9;
    // 0x80802A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80802AA0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802AA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F34) << 16);
    // 0x80802AA8: lwc1        $f16, 0x4F34($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F34));
    // 0x80802AAC: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80802AB0: b           L_80802C20
    // 0x80802AB4: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
        goto L_80802C20;
    // 0x80802AB4: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80802AB8: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
L_80802ABC:
    // 0x80802ABC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802AC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802AC4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80802AC8: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80802ACC: jal         0x80801944
    // 0x80802AD0: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    func_80801944_chstoneballcontrol(rdram, ctx);
        goto after_6;
    // 0x80802AD0: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    after_6:
    // 0x80802AD4: b           L_80802C24
    // 0x80802AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802C24;
    // 0x80802AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802ADC: lui         $at, 0xC337
    ctx->r1 = S32(0XC337 << 16);
L_80802AE0:
    // 0x80802AE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802AE4: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80802AE8: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x80802AEC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80802AF0: nop

    // 0x80802AF4: bc1fl       L_80802B88
    if (!c1cs) {
        // 0x80802AF8: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_80802B88;
    }
    goto skip_10;
    // 0x80802AF8: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    skip_10:
    // 0x80802AFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802B00: nop

    // 0x80802B04: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80802B08: nop

    // 0x80802B0C: bc1fl       L_80802B88
    if (!c1cs) {
        // 0x80802B10: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_80802B88;
    }
    goto skip_11;
    // 0x80802B10: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    skip_11:
    // 0x80802B14: lhu         $t2, 0x72($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X72);
    // 0x80802B18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802B1C: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80802B20: beq         $t3, $at, L_80802B50
    if (ctx->r11 == ctx->r1) {
        // 0x80802B24: lui         $at, 0xC434
        ctx->r1 = S32(0XC434 << 16);
            goto L_80802B50;
    }
    // 0x80802B24: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    // 0x80802B28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802B2C: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80802B30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802B34: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80802B38: nop

    // 0x80802B3C: bc1f        L_80802B50
    if (!c1cs) {
        // 0x80802B40: nop
    
            goto L_80802B50;
    }
    // 0x80802B40: nop

    // 0x80802B44: jal         0x80802FBC
    // 0x80802B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802FBC_chstoneballcontrol(rdram, ctx);
        goto after_7;
    // 0x80802B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_7:
    // 0x80802B4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80802B50:
    // 0x80802B50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F38) << 16);
    // 0x80802B54: lwc1        $f18, 0x4F38($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F38));
    // 0x80802B58: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80802B5C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80802B60: nop

    // 0x80802B64: bc1fl       L_80802C24
    if (!c1cs) {
        // 0x80802B68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802C24;
    }
    goto skip_12;
    // 0x80802B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_12:
    // 0x80802B6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802B70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F3C) << 16);
    // 0x80802B74: lwc1        $f16, 0x4F3C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F3C));
    // 0x80802B78: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80802B7C: b           L_80802C20
    // 0x80802B80: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
        goto L_80802C20;
    // 0x80802B80: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x80802B84: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
L_80802B88:
    // 0x80802B88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802B8C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80802B90: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80802B94: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80802B98: jal         0x80801944
    // 0x80802B9C: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    func_80801944_chstoneballcontrol(rdram, ctx);
        goto after_8;
    // 0x80802B9C: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    after_8:
    // 0x80802BA0: b           L_80802C24
    // 0x80802BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802C24;
    // 0x80802BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802BA8:
    // 0x80802BA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F40) << 16);
    // 0x80802BAC: lwc1        $f16, 0x4F40($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F40));
    // 0x80802BB0: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80802BB4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F44) << 16);
    // 0x80802BB8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80802BBC: nop

    // 0x80802BC0: bc1tl       L_80802C14
    if (c1cs) {
        // 0x80802BC4: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80802C14;
    }
    goto skip_13;
    // 0x80802BC4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_13:
    // 0x80802BC8: lwc1        $f18, 0x4F44($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F44));
    // 0x80802BCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F48) << 16);
    // 0x80802BD0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80802BD4: nop

    // 0x80802BD8: bc1tl       L_80802C14
    if (c1cs) {
        // 0x80802BDC: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80802C14;
    }
    goto skip_14;
    // 0x80802BDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_14:
    // 0x80802BE0: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80802BE4: lwc1        $f4, 0x4F48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F48));
    // 0x80802BE8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F4C) << 16);
    // 0x80802BEC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80802BF0: nop

    // 0x80802BF4: bc1tl       L_80802C14
    if (c1cs) {
        // 0x80802BF8: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80802C14;
    }
    goto skip_15;
    // 0x80802BF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_15:
    // 0x80802BFC: lwc1        $f6, 0x4F4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F4C));
    // 0x80802C00: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80802C04: nop

    // 0x80802C08: bc1fl       L_80802C24
    if (!c1cs) {
        // 0x80802C0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802C24;
    }
    goto skip_16;
    // 0x80802C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_16:
    // 0x80802C10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80802C14:
    // 0x80802C14: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80802C18: jal         0x80801944
    // 0x80802C1C: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    func_80801944_chstoneballcontrol(rdram, ctx);
        goto after_9;
    // 0x80802C1C: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    after_9:
L_80802C20:
    // 0x80802C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802C24:
    // 0x80802C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802C28: jr          $ra
    // 0x80802C2C: nop

    return;
    // 0x80802C2C: nop

;}
RECOMP_FUNC void func_80802690_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802690: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802698: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080269C: lw          $a0, 0x18($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X18);
    // 0x808026A0: srl         $t6, $a0, 28
    ctx->r14 = S32(U32(ctx->r4) >> 28);
    // 0x808026A4: jal         0x8008A240
    // 0x808026A8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808026A8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x808026AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808026B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808026B4: jal         0x80100094
    // 0x808026B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808026B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808026BC: bne         $v0, $zero, L_80802718
    if (ctx->r2 != 0) {
        // 0x808026C0: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80802718;
    }
    // 0x808026C0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808026C4: jal         0x80089790
    // 0x808026C8: lbu         $a0, 0x3($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X3);
    _suexpression_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808026C8: lbu         $a0, 0x3($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X3);
    after_2:
    // 0x808026CC: beq         $v0, $zero, L_80802718
    if (ctx->r2 == 0) {
        // 0x808026D0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80802718;
    }
    // 0x808026D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808026D4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808026D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808026DC: jal         0x800897C0
    // 0x808026E0: lh          $a2, 0x2($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X2);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x808026E0: lh          $a2, 0x2($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X2);
    after_3:
    // 0x808026E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808026E8: jal         0x80100094
    // 0x808026EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808026EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808026F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808026F4: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x808026F8: jal         0x800897E8
    // 0x808026FC: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x808026FC: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_5:
    // 0x80802700: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802704: jal         0x80100094
    // 0x80802708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x80802708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080270C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802710: jal         0x80089810
    // 0x80802714: addiu       $a1, $zero, 0x960
    ctx->r5 = ADD32(0, 0X960);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_7;
    // 0x80802714: addiu       $a1, $zero, 0x960
    ctx->r5 = ADD32(0, 0X960);
    after_7:
L_80802718:
    // 0x80802718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080271C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802720: jr          $ra
    // 0x80802724: nop

    return;
    // 0x80802724: nop

;}
RECOMP_FUNC void bsdroneslide_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808002B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002C4: jal         0x8009D658
    // 0x808002C8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    func_8009D658(rdram, ctx);
        goto after_0;
    // 0x808002C8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: jal         0x800852F0
    // 0x808002D4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _batimer_decrement(rdram, ctx);
        goto after_1;
    // 0x808002D4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x808002D8: jal         0x8008E148
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_2;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002E0: beq         $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x808002E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C0;
    }
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808002EC: jal         0x80800110
    // 0x808002F0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_80800110_bsdroneslide(rdram, ctx);
        goto after_3;
    // 0x808002F0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x808002F4: beq         $v0, $zero, L_808003A8
    if (ctx->r2 == 0) {
        // 0x808002F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A8;
    }
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002FC: lbu         $t6, 0x190($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X190);
    // 0x80800300: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800304: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800308: bne         $t6, $at, L_8080034C
    if (ctx->r14 != ctx->r1) {
        // 0x8080030C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080034C;
    }
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800314: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800320: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800324: jal         0x8009C914
    // 0x80800328: nop

    yaw_setIdeal(rdram, ctx);
        goto after_4;
    // 0x80800328: nop

    after_4:
    // 0x8080032C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80800338: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080033C: jal         0x8009BF5C
    // 0x80800340: nop

    func_8009BF5C(rdram, ctx);
        goto after_5;
    // 0x80800340: nop

    after_5:
    // 0x80800344: b           L_80800364
    // 0x80800348: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
        goto L_80800364;
    // 0x80800348: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8080034C:
    // 0x8080034C: jal         0x8009C914
    // 0x80800350: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80800350: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x8009BF5C
    // 0x8080035C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8009BF5C(rdram, ctx);
        goto after_7;
    // 0x8080035C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800360: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_80800364:
    // 0x80800364: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800368: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8080036C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800370: lui         $a3, 0x4409
    ctx->r7 = S32(0X4409 << 16);
    // 0x80800374: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800378: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080037C: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80800380: jal         0x800F10B4
    // 0x80800384: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800384: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x80800388: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080038C: jal         0x8009B9B0
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_9;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: jal         0x808001F4
    // 0x8080039C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808001F4_bsdroneslide(rdram, ctx);
        goto after_10;
    // 0x8080039C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x808003A0: b           L_808003B0
    // 0x808003A4: nop

        goto L_808003B0;
    // 0x808003A4: nop

L_808003A8:
    // 0x808003A8: jal         0x8009B9B0
    // 0x808003AC: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x808003AC: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_11:
L_808003B0:
    // 0x808003B0: jal         0x80084A00
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_7(rdram, ctx);
        goto after_12;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808003B8: b           L_808003CC
    // 0x808003BC: nop

        goto L_808003CC;
    // 0x808003BC: nop

L_808003C0:
    // 0x808003C0: jal         0x80084700
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_24(rdram, ctx);
        goto after_13;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808003C8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_808003CC:
    // 0x808003CC: jal         0x8008E35C
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_14;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808003D4: beql        $v0, $zero, L_808003EC
    if (ctx->r2 == 0) {
        // 0x808003D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003EC;
    }
    goto skip_0;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808003DC: jal         0x80084700
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_24(rdram, ctx);
        goto after_15;
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808003E4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003EC:
    // 0x808003EC: jal         0x80085330
    // 0x808003F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _batimer_isZero(rdram, ctx);
        goto after_16;
    // 0x808003F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_16:
    // 0x808003F4: beq         $v0, $zero, L_80800418
    if (ctx->r2 == 0) {
        // 0x808003F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800418;
    }
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x80091A58
    // 0x80800400: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_17;
    // 0x80800400: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_17:
    // 0x80800404: beql        $v0, $zero, L_8080041C
    if (ctx->r2 == 0) {
        // 0x80800408: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080041C;
    }
    goto skip_1;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080040C: jal         0x80084708
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_25(rdram, ctx);
        goto after_18;
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800414: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80800418:
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080041C:
    // 0x8080041C: jal         0x8009E5C8
    // 0x80800420: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x80800420: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_19:
    // 0x80800424: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800428: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080042C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800430: jr          $ra
    // 0x80800434: nop

    return;
    // 0x80800434: nop

;}
RECOMP_FUNC void func_800E715C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E715C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800E7160: beq         $v0, $zero, L_800E7180
    if (ctx->r2 == 0) {
        // 0x800E7164: nop
    
            goto L_800E7180;
    }
    // 0x800E7164: nop

    // 0x800E7168: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800E716C:
    // 0x800E716C: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x800E7170: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E7174: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800E7178: bnel        $v0, $zero, L_800E716C
    if (ctx->r2 != 0) {
        // 0x800E717C: sb          $v0, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r2;
            goto L_800E716C;
    }
    goto skip_0;
    // 0x800E717C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    skip_0:
L_800E7180:
    // 0x800E7180: jr          $ra
    // 0x800E7184: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x800E7184: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8080000C_chmineproplight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800010: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800014: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800018: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080001C: addiu       $s0, $sp, 0x34
    ctx->r16 = ADD32(ctx->r29, 0X34);
    // 0x80800020: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800024: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80800028: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8080002C: jal         0x800EE904
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800034: addiu       $t6, $zero, 0x1F4
    ctx->r14 = ADD32(0, 0X1F4);
    // 0x80800038: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800044: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800048: jal         0x800882F8
    // 0x8080004C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _gccubesearch_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x8080004C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x80800050: beq         $v0, $zero, L_8080014C
    if (ctx->r2 == 0) {
        // 0x80800054: lw          $s0, 0x40($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X40);
            goto L_8080014C;
    }
    // 0x80800054: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80800058: lbu         $t9, 0xB($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XB);
    // 0x8080005C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800060: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x80800064: sb          $t1, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r9;
    // 0x80800068: andi        $t2, $t1, 0xEF
    ctx->r10 = ctx->r9 & 0XEF;
    // 0x8080006C: sb          $t2, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r10;
    // 0x80800070: jal         0x800EE88C
    // 0x80800074: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80800074: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800078: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
    // 0x8080007C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800080: bgez        $t3, L_80800098
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800084: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800098;
    }
    // 0x80800084: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800088: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080008C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800090: nop

    // 0x80800094: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80800098:
    // 0x80800098: jal         0x800136E4
    // 0x8080009C: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x8080009C: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    after_3:
    // 0x808000A0: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x808000A4: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x808000A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808000AC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x808000B0: bgez        $t4, L_808000C4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808000B4: cvt.s.w     $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
            goto L_808000C4;
    }
    // 0x808000B4: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808000B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000BC: nop

    // 0x808000C0: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
L_808000C4:
    // 0x808000C4: jal         0x800136E4
    // 0x808000C8: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x808000C8: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    after_4:
    // 0x808000CC: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x808000D0: jal         0x80088C88
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gsproplookup_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000DC: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x808000E0: jal         0x80103140
    // 0x808000E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103140(rdram, ctx);
        goto after_6;
    // 0x808000E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808000E8: lbu         $t5, 0xA($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA);
    // 0x808000EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808000F4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x808000F8: bgez        $t5, L_8080010C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808000FC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8080010C;
    }
    // 0x808000FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800100: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800104: nop

    // 0x80800108: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8080010C:
    // 0x8080010C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1580, 0X230) << 16);
    // 0x80800110: lwc1        $f6, 0x230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1580, 0X230));
    // 0x80800114: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80800118: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080011C: jal         0x80102FDC
    // 0x80800120: nop

    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x80800120: nop

    after_7:
    // 0x80800124: jal         0x80103014
    // 0x80800128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80103014(rdram, ctx);
        goto after_8;
    // 0x80800128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8080012C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800130: jal         0x80108944
    // 0x80800134: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80108944(rdram, ctx);
        goto after_9;
    // 0x80800134: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80800138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080013C: jal         0x8010A828
    // 0x80800140: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8010A828(rdram, ctx);
        goto after_10;
    // 0x80800140: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x80800144: b           L_80800158
    // 0x80800148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800158;
    // 0x80800148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080014C:
    // 0x8080014C: jal         0x800FFAB0
    // 0x80800150: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_11;
    // 0x80800150: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800154: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800158:
    // 0x80800158: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: jr          $ra
    // 0x80800164: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800164: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8080000C_chbottlesplantgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080001C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800020: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800024: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800028: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080002C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800030: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800034: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800038: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080003C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800040: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800044: jal         0x80086898
    // 0x80800048: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800048: nop

    after_0:
    // 0x8080004C: beq         $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x80800050: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800098;
    }
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: jal         0x800868B0
    // 0x80800058: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800058: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_1:
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x800868A8
    // 0x80800064: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800064: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_2:
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: jal         0x800868C0
    // 0x80800070: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800070: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080007C: jal         0x800868E0
    // 0x80800080: addiu       $a2, $zero, 0x65
    ctx->r6 = ADD32(0, 0X65);
    _chdoormake_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x80800080: addiu       $a2, $zero, 0x65
    ctx->r6 = ADD32(0, 0X65);
    after_4:
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080008C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800090: jal         0x800868C8
    // 0x80800094: addiu       $a3, $zero, 0x2900
    ctx->r7 = ADD32(0, 0X2900);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800094: addiu       $a3, $zero, 0x2900
    ctx->r7 = ADD32(0, 0X2900);
    after_5:
L_80800098:
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x8010A800
    // 0x808000A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_6;
    // 0x808000A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808000A4: jal         0x80088840
    // 0x808000A8: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_7;
    // 0x808000A8: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_7:
    // 0x808000AC: bnel        $v0, $zero, L_808000E0
    if (ctx->r2 != 0) {
        // 0x808000B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000E0;
    }
    goto skip_0;
    // 0x808000B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000B4: jal         0x800DA298
    // 0x808000B8: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808000B8: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    after_8:
    // 0x808000BC: bne         $v0, $zero, L_808000D4
    if (ctx->r2 != 0) {
        // 0x808000C0: nop
    
            goto L_808000D4;
    }
    // 0x808000C0: nop

    // 0x808000C4: jal         0x800DA298
    // 0x808000C8: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808000C8: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_9:
    // 0x808000CC: beql        $v0, $zero, L_808000E0
    if (ctx->r2 == 0) {
        // 0x808000D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000E0;
    }
    goto skip_1;
    // 0x808000D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
L_808000D4:
    // 0x808000D4: jal         0x800FFAB0
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808000DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000E0:
    // 0x808000E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80800A74_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A74: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800A78: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80800A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A80: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800A84: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x80800A88: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800A8C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800A90: bne         $t7, $zero, L_80800AC4
    if (ctx->r15 != 0) {
        // 0x80800A94: sw          $a3, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r7;
            goto L_80800AC4;
    }
    // 0x80800A94: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80800A98: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x80800A9C: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80800AA0: srl         $t9, $a1, 26
    ctx->r25 = S32(U32(ctx->r5) >> 26);
    // 0x80800AA4: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80800AA8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80800AAC: jal         0x800CC6CC
    // 0x80800AB0: addiu       $a1, $t9, -0x1
    ctx->r5 = ADD32(ctx->r25, -0X1);
    func_800CC6CC(rdram, ctx);
        goto after_0;
    // 0x80800AB0: addiu       $a1, $t9, -0x1
    ctx->r5 = ADD32(ctx->r25, -0X1);
    after_0:
    // 0x80800AB4: bnel        $v0, $zero, L_80800AC8
    if (ctx->r2 != 0) {
        // 0x80800AB8: lw          $a1, 0x50($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X50);
            goto L_80800AC8;
    }
    goto skip_0;
    // 0x80800AB8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x80800ABC: b           L_80800B9C
    // 0x80800AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B9C;
    // 0x80800AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AC4:
    // 0x80800AC4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
L_80800AC8:
    // 0x80800AC8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800ACC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800AD0: jal         0x800EE7F8
    // 0x80800AD4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800AD4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800AD8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800ADC: jal         0x800EE7F8
    // 0x80800AE0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800AE0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x80800AE4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800AE8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80800AEC: jal         0x800EF1B8
    // 0x80800AF0: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x80800AF0: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_3:
    // 0x80800AF4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80800AF8: jal         0x800EC708
    // 0x80800AFC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_800EC708(rdram, ctx);
        goto after_4;
    // 0x80800AFC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x80800B00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3230, 0X18C0) << 16);
    // 0x80800B04: lwc1        $f6, 0x18C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3230, 0X18C0));
    // 0x80800B08: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800B0C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80800B10: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800B14: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800B18: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800B1C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80800B20: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800B24: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80800B28: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x80800B2C: jal         0x800BEF00
    // 0x80800B30: lw          $a3, 0x14($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_5;
    // 0x80800B30: lw          $a3, 0x14($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X14);
    after_5:
    // 0x80800B34: beq         $v0, $zero, L_80800B98
    if (ctx->r2 == 0) {
        // 0x80800B38: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_80800B98;
    }
    // 0x80800B38: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800B3C: jal         0x800F1EA4
    // 0x80800B40: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F1EA4(rdram, ctx);
        goto after_6;
    // 0x80800B40: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x80800B44: beq         $v0, $zero, L_80800B90
    if (ctx->r2 == 0) {
        // 0x80800B48: lwc1        $f16, 0x58($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80800B90;
    }
    // 0x80800B48: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800B4C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800B50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800B54: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800B58: jal         0x800F1DCC
    // 0x80800B5C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    func_800F1DCC(rdram, ctx);
        goto after_7;
    // 0x80800B5C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_7:
    // 0x80800B60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800B64: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80800B68: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80800B6C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800B70: nop

    // 0x80800B74: bc1f        L_80800B84
    if (!c1cs) {
        // 0x80800B78: nop
    
            goto L_80800B84;
    }
    // 0x80800B78: nop

    // 0x80800B7C: b           L_80800B84
    // 0x80800B80: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_80800B84;
    // 0x80800B80: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80800B84:
    // 0x80800B84: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x80800B88: or          $t4, $t3, $v0
    ctx->r12 = ctx->r11 | ctx->r2;
    // 0x80800B8C: sh          $t4, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r12;
L_80800B90:
    // 0x80800B90: b           L_80800B9C
    // 0x80800B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B9C;
    // 0x80800B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B98:
    // 0x80800B98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B9C:
    // 0x80800B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800BA4: jr          $ra
    // 0x80800BA8: nop

    return;
    // 0x80800BA8: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801344: jr          $ra
    // 0x80801348: sb          $a1, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r5;
    return;
    // 0x80801348: sb          $a1, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80803358_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080335C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803360: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80803364: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80803368: beql        $t6, $zero, L_8080337C
    if (ctx->r14 == 0) {
        // 0x8080336C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080337C;
    }
    goto skip_0;
    // 0x8080336C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80803370: jal         0x800C8B84
    // 0x80803374: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x80803374: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80803378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080337C:
    // 0x8080337C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803380: jr          $ra
    // 0x80803384: nop

    return;
    // 0x80803384: nop

;}
RECOMP_FUNC void chwandglow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2164, 0X410) << 16);
    // 0x808003F4: jr          $ra
    // 0x808003F8: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2164, 0X410));
    return;
    // 0x808003F8: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2164, 0X410));
    // 0x808003FC: nop

;}
RECOMP_FUNC void func_8010D12C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D12C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010D130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D134: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8010D138: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8010D13C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8010D140: jal         0x800D8FF8
    // 0x8010D144: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8010D144: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010D148: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010D14C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010D150: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8010D154: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8010D158: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8010D15C: jal         0x800F5A00
    // 0x8010D160: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x8010D160: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8010D164: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8010D168: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8010D16C: jal         0x800F5A2C
    // 0x8010D170: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800F5A2C(rdram, ctx);
        goto after_2;
    // 0x8010D170: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x8010D174: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8010D178: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8010D17C: jal         0x800F5A2C
    // 0x8010D180: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800F5A2C(rdram, ctx);
        goto after_3;
    // 0x8010D180: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x8010D184: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8010D188: jal         0x800EF3DC
    // 0x8010D18C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800EF3DC(rdram, ctx);
        goto after_4;
    // 0x8010D18C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x8010D190: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8010D194: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8010D198: jal         0x800EFB24
    // 0x8010D19C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x8010D19C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_5:
    // 0x8010D1A0: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8010D1A4: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010D1A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8010D1AC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8010D1B0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8010D1B4: jal         0x800EF334
    // 0x8010D1B8: nop

    func_800EF334(rdram, ctx);
        goto after_6;
    // 0x8010D1B8: nop

    after_6:
    // 0x8010D1BC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8010D1C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8010D1C4: jal         0x800EE780
    // 0x8010D1C8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800EE780(rdram, ctx);
        goto after_7;
    // 0x8010D1C8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x8010D1CC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8010D1D0: jal         0x800EF04C
    // 0x8010D1D4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x8010D1D4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_8:
    // 0x8010D1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010D1DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8010D1E0: jr          $ra
    // 0x8010D1E4: nop

    return;
    // 0x8010D1E4: nop

;}
RECOMP_FUNC void chcheato_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(868, 0XE98) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xE98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0XE98));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xE98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(868, 0XE98));
;}
RECOMP_FUNC void func_808002A0_chklungospiral(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808002B0: jal         0x80088078
    // 0x808002B4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808002B4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808002B8: beq         $v0, $zero, L_808002E8
    if (ctx->r2 == 0) {
        // 0x808002BC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002E8;
    }
    // 0x808002BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002C0: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x808002C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002CC: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808002D0: beq         $t7, $at, L_808002E0
    if (ctx->r15 == ctx->r1) {
        // 0x808002D4: nop
    
            goto L_808002E0;
    }
    // 0x808002D4: nop

    // 0x808002D8: jal         0x808002FC
    // 0x808002DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808002FC_chklungospiral(rdram, ctx);
        goto after_1;
    // 0x808002DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_808002E0:
    // 0x808002E0: b           L_808002EC
    // 0x808002E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808002EC;
    // 0x808002E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808002E8:
    // 0x808002E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002EC:
    // 0x808002EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002F4: jr          $ra
    // 0x808002F8: nop

    return;
    // 0x808002F8: nop

;}
RECOMP_FUNC void func_800ABC58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABC58: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800ABC5C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800ABC60: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800ABC64: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800ABC68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800ABC6C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800ABC70: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
L_800ABC74:
    // 0x800ABC74: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800ABC78: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ABC7C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800ABC80: nop

    // 0x800ABC84: bc1fl       L_800ABCA0
    if (!c1cs) {
        // 0x800ABC88: swc1        $f2, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f2.u32l;
            goto L_800ABCA0;
    }
    goto skip_0;
    // 0x800ABC88: swc1        $f2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f2.u32l;
    skip_0:
    // 0x800ABC8C: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x800ABC90: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ABC94: b           L_800ABCA8
    // 0x800ABC98: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
        goto L_800ABCA8;
    // 0x800ABC98: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x800ABC9C: swc1        $f2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f2.u32l;
L_800ABCA0:
    // 0x800ABCA0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800ABCA4: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
L_800ABCA8:
    // 0x800ABCA8: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800ABCAC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800ABCB0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800ABCB4: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800ABCB8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800ABCBC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800ABCC0: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800ABCC4: swc1        $f10, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f10.u32l;
    // 0x800ABCC8: lwc1        $f16, -0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, -0X4);
    // 0x800ABCCC: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800ABCD0: bne         $v0, $a0, L_800ABC74
    if (ctx->r2 != ctx->r4) {
        // 0x800ABCD4: swc1        $f18, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
            goto L_800ABC74;
    }
    // 0x800ABCD4: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x800ABCD8: jr          $ra
    // 0x800ABCDC: nop

    return;
    // 0x800ABCDC: nop

;}
RECOMP_FUNC void func_8008DF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DF8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008DF90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008DF94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008DF98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008DF9C: jal         0x8008E078
    // 0x8008DFA0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    player_isStable(rdram, ctx);
        goto after_0;
    // 0x8008DFA0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008DFA4: beq         $v0, $zero, L_8008DFB4
    if (ctx->r2 == 0) {
        // 0x8008DFA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8008DFB4;
    }
    // 0x8008DFA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008DFAC: b           L_8008E064
    // 0x8008DFB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008E064;
    // 0x8008DFB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DFB4:
    // 0x8008DFB4: jal         0x800963C0
    // 0x8008DFB8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800963C0(rdram, ctx);
        goto after_1;
    // 0x8008DFB8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8008DFBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DFC0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8008DFC4: lwc1        $f4, 0x4AE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4AE4);
    // 0x8008DFC8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8008DFCC: nop

    // 0x8008DFD0: bc1f        L_8008DFF8
    if (!c1cs) {
        // 0x8008DFD4: nop
    
            goto L_8008DFF8;
    }
    // 0x8008DFD4: nop

    // 0x8008DFD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008DFDC: nop

    // 0x8008DFE0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8008DFE4: nop

    // 0x8008DFE8: bc1f        L_8008DFF8
    if (!c1cs) {
        // 0x8008DFEC: nop
    
            goto L_8008DFF8;
    }
    // 0x8008DFEC: nop

    // 0x8008DFF0: b           L_8008E064
    // 0x8008DFF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E064;
    // 0x8008DFF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008DFF8:
    // 0x8008DFF8: jal         0x8009BB50
    // 0x8008DFFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_2;
    // 0x8008DFFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008E000: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008E004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008E008: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8008E00C: nop

    // 0x8008E010: bc1f        L_8008E01C
    if (!c1cs) {
        // 0x8008E014: nop
    
            goto L_8008E01C;
    }
    // 0x8008E014: nop

    // 0x8008E018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E01C:
    // 0x8008E01C: beql        $v0, $zero, L_8008E068
    if (ctx->r2 == 0) {
        // 0x8008E020: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008E068;
    }
    goto skip_0;
    // 0x8008E020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8008E024: jal         0x8009C150
    // 0x8008E028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C150(rdram, ctx);
        goto after_3;
    // 0x8008E028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008E02C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8008E030: jal         0x80096364
    // 0x8008E034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096364(rdram, ctx);
        goto after_4;
    // 0x8008E034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008E038: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8008E03C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008E040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008E044: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8008E048: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8008E04C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8008E050: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x8008E054: nop

    // 0x8008E058: bc1fl       L_8008E068
    if (!c1cs) {
        // 0x8008E05C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008E068;
    }
    goto skip_1;
    // 0x8008E05C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8008E060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E064:
    // 0x8008E064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008E068:
    // 0x8008E068: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008E06C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008E070: jr          $ra
    // 0x8008E074: nop

    return;
    // 0x8008E074: nop

;}
RECOMP_FUNC void func_808040DC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808040DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808040E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808040E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808040E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808040EC: jal         0x80087D28
    // 0x808040F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _gcnewoption_entrypoint_18(rdram, ctx);
        goto after_0;
    // 0x808040F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808040F4: bne         $v0, $zero, L_8080412C
    if (ctx->r2 != 0) {
        // 0x808040F8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080412C;
    }
    // 0x808040F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808040FC: jal         0x80087D48
    // 0x80804100: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_22(rdram, ctx);
        goto after_1;
    // 0x80804100: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80804104: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(804, 0X83D8) << 16);
    // 0x80804108: addiu       $a2, $a2, -0x7C28
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(804, 0X83D8));
    // 0x8080410C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804110: jal         0x80087D00
    // 0x80804114: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80804114: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80804118: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080411C: beql        $t6, $zero, L_80804130
    if (ctx->r14 == 0) {
        // 0x80804120: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80804130;
    }
    goto skip_0;
    // 0x80804120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80804124: jal         0x80803CE0
    // 0x80804128: nop

    func_80803CE0_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80804128: nop

    after_3:
L_8080412C:
    // 0x8080412C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804130:
    // 0x80804130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804134: jr          $ra
    // 0x80804138: nop

    return;
    // 0x80804138: nop

;}
RECOMP_FUNC void bamovegoto_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808001BC: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808001C0: jr          $ra
    // 0x808001C4: swc1        $f12, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808001C4: swc1        $f12, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80801868_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801868: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8080186C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801870: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801874: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801878: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080187C: jal         0x80100094
    // 0x80801880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801884: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801888: jal         0x800D90A4
    // 0x8080188C: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x8080188C: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    after_1:
    // 0x80801890: addiu       $a0, $s1, 0x20
    ctx->r4 = ADD32(ctx->r17, 0X20);
    // 0x80801894: jal         0x800D90A4
    // 0x80801898: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800D90A4(rdram, ctx);
        goto after_2;
    // 0x80801898: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8080189C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808018A0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x808018A4: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x808018A8: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x808018AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808018B0: jal         0x800F10B4
    // 0x808018B4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808018B4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x808018B8: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x808018BC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808018C0: lw          $a2, 0x24($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X24);
    // 0x808018C4: lwc1        $f12, 0x20($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X20);
    // 0x808018C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808018CC: jal         0x800F10B4
    // 0x808018D0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808018D0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x808018D4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x808018D8: lw          $v1, 0x78($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X78);
    // 0x808018DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808018E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808018E4: sll         $v0, $v1, 18
    ctx->r2 = S32(ctx->r3 << 18);
    // 0x808018E8: srl         $t6, $v0, 30
    ctx->r14 = S32(U32(ctx->r2) >> 30);
    // 0x808018EC: beq         $t6, $zero, L_80801918
    if (ctx->r14 == 0) {
        // 0x808018F0: nop
    
            goto L_80801918;
    }
    // 0x808018F0: nop

    // 0x808018F4: beq         $t6, $at, L_80801964
    if (ctx->r14 == ctx->r1) {
        // 0x808018F8: sll         $v0, $v1, 20
        ctx->r2 = S32(ctx->r3 << 20);
            goto L_80801964;
    }
    // 0x808018F8: sll         $v0, $v1, 20
    ctx->r2 = S32(ctx->r3 << 20);
    // 0x808018FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801900: beq         $t6, $at, L_808019D8
    if (ctx->r14 == ctx->r1) {
        // 0x80801904: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808019D8;
    }
    // 0x80801904: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801908: beq         $t6, $at, L_80801A20
    if (ctx->r14 == ctx->r1) {
        // 0x8080190C: lwc1        $f12, 0x50($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
            goto L_80801A20;
    }
    // 0x8080190C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801910: b           L_80801B8C
    // 0x80801914: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801B8C;
    // 0x80801914: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801918:
    // 0x80801918: jal         0x800D90A4
    // 0x8080191C: nop

    func_800D90A4(rdram, ctx);
        goto after_5;
    // 0x8080191C: nop

    after_5:
    // 0x80801920: beq         $v0, $zero, L_80801B88
    if (ctx->r2 == 0) {
        // 0x80801924: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_80801B88;
    }
    // 0x80801924: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801928: lbu         $t7, 0x7A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7A);
    // 0x8080192C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X2598) << 16);
    // 0x80801930: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801934: andi        $t8, $t7, 0xFFCF
    ctx->r24 = ctx->r15 & 0XFFCF;
    // 0x80801938: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8080193C: sb          $t9, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r25;
    // 0x80801940: lwc1        $f4, 0x2598($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X2598));
    // 0x80801944: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80801948: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080194C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801950: jal         0x800F10B4
    // 0x80801954: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80801954: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80801958: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x8080195C: b           L_80801B88
    // 0x80801960: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_80801B88;
    // 0x80801960: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_80801964:
    // 0x80801964: srl         $t0, $v0, 29
    ctx->r8 = S32(U32(ctx->r2) >> 29);
    // 0x80801968: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080196C: bne         $t0, $at, L_808019B8
    if (ctx->r8 != ctx->r1) {
        // 0x80801970: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_808019B8;
    }
    // 0x80801970: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80801974: jal         0x800D90A4
    // 0x80801978: nop

    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x80801978: nop

    after_7:
    // 0x8080197C: beq         $v0, $zero, L_80801B88
    if (ctx->r2 == 0) {
        // 0x80801980: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_80801B88;
    }
    // 0x80801980: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801984: lbu         $t1, 0x7A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7A);
    // 0x80801988: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080198C: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80801990: andi        $t2, $t1, 0xFFCF
    ctx->r10 = ctx->r9 & 0XFFCF;
    // 0x80801994: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x80801998: sb          $t3, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r11;
    // 0x8080199C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808019A0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808019A4: jal         0x800F10B4
    // 0x808019A8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808019A8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_8:
    // 0x808019AC: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x808019B0: b           L_80801B88
    // 0x808019B4: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_80801B88;
    // 0x808019B4: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_808019B8:
    // 0x808019B8: lbu         $t7, 0x7A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7A);
    // 0x808019BC: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x808019C0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x808019C4: andi        $t6, $t5, 0xE
    ctx->r14 = ctx->r13 & 0XE;
    // 0x808019C8: andi        $t8, $t7, 0xFFF1
    ctx->r24 = ctx->r15 & 0XFFF1;
    // 0x808019CC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x808019D0: b           L_80801B88
    // 0x808019D4: sb          $t9, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r25;
        goto L_80801B88;
    // 0x808019D4: sb          $t9, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r25;
L_808019D8:
    // 0x808019D8: jal         0x800D90A4
    // 0x808019DC: nop

    func_800D90A4(rdram, ctx);
        goto after_9;
    // 0x808019DC: nop

    after_9:
    // 0x808019E0: beq         $v0, $zero, L_80801B88
    if (ctx->r2 == 0) {
        // 0x808019E4: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_80801B88;
    }
    // 0x808019E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808019E8: lbu         $t1, 0x7A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7A);
    // 0x808019EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X259C) << 16);
    // 0x808019F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808019F4: ori         $t2, $t1, 0x30
    ctx->r10 = ctx->r9 | 0X30;
    // 0x808019F8: sb          $t2, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r10;
    // 0x808019FC: lwc1        $f6, 0x259C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X259C));
    // 0x80801A00: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80801A04: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801A08: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801A0C: jal         0x800F10B4
    // 0x80801A10: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x80801A10: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80801A14: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x80801A18: b           L_80801B88
    // 0x80801A1C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_80801B88;
    // 0x80801A1C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_80801A20:
    // 0x80801A20: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801A24: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801A28: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801A2C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80801A30: jal         0x800F10B4
    // 0x80801A34: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x80801A34: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x80801A38: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801A3C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801A40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801A44: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801A48: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80801A4C: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80801A50: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801A54: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80801A58: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80801A5C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801A60: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801A64: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801A68: jal         0x800F10B4
    // 0x80801A6C: nop

    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x80801A6C: nop

    after_12:
    // 0x80801A70: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80801A74: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801A78: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80801A7C: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x80801A80: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801A84: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80801A88: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80801A8C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801A90: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80801A94: nop

    // 0x80801A98: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80801A9C: beql        $t5, $zero, L_80801AEC
    if (ctx->r13 == 0) {
        // 0x80801AA0: mfc1        $t5, $f4
        ctx->r13 = (int32_t)ctx->f4.u32l;
            goto L_80801AEC;
    }
    goto skip_0;
    // 0x80801AA0: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80801AA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801AA8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801AAC: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80801AB0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80801AB4: nop

    // 0x80801AB8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80801ABC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80801AC0: nop

    // 0x80801AC4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80801AC8: bne         $t5, $zero, L_80801AE0
    if (ctx->r13 != 0) {
        // 0x80801ACC: nop
    
            goto L_80801AE0;
    }
    // 0x80801ACC: nop

    // 0x80801AD0: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80801AD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801AD8: b           L_80801AF8
    // 0x80801ADC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80801AF8;
    // 0x80801ADC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80801AE0:
    // 0x80801AE0: b           L_80801AF8
    // 0x80801AE4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80801AF8;
    // 0x80801AE4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801AE8: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
L_80801AEC:
    // 0x80801AEC: nop

    // 0x80801AF0: bltz        $t5, L_80801AE0
    if (SIGNED(ctx->r13) < 0) {
        // 0x80801AF4: nop
    
            goto L_80801AE0;
    }
    // 0x80801AF4: nop

L_80801AF8:
    // 0x80801AF8: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    // 0x80801AFC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80801B00: andi        $t8, $t6, 0xE
    ctx->r24 = ctx->r14 & 0XE;
    // 0x80801B04: andi        $t0, $t9, 0xFFF1
    ctx->r8 = ctx->r25 & 0XFFF1;
    // 0x80801B08: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80801B0C: sb          $t1, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r9;
    // 0x80801B10: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80801B14: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80801B18: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80801B1C: beq         $t2, $zero, L_80801B88
    if (ctx->r10 == 0) {
        // 0x80801B20: or          $t6, $t1, $zero
        ctx->r14 = ctx->r9 | 0;
            goto L_80801B88;
    }
    // 0x80801B20: or          $t6, $t1, $zero
    ctx->r14 = ctx->r9 | 0;
    // 0x80801B24: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80801B28: andi        $t7, $t5, 0xE
    ctx->r15 = ctx->r13 & 0XE;
    // 0x80801B2C: andi        $t9, $t6, 0xF1
    ctx->r25 = ctx->r14 & 0XF1;
    // 0x80801B30: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80801B34: sb          $t0, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r8;
    // 0x80801B38: andi        $t1, $t0, 0xCF
    ctx->r9 = ctx->r8 & 0XCF;
    // 0x80801B3C: sb          $t1, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r9;
    // 0x80801B40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X25A0) << 16);
    // 0x80801B44: lwc1        $f6, 0x25A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X25A0));
    // 0x80801B48: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801B4C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801B50: jal         0x800F10B4
    // 0x80801B54: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x80801B54: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x80801B58: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x80801B5C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x80801B60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801B64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801B68: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B70: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80801B74: nop

    // 0x80801B78: bc1fl       L_80801B8C
    if (!c1cs) {
        // 0x80801B7C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801B8C;
    }
    goto skip_1;
    // 0x80801B7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80801B80: jal         0x80801324
    // 0x80801B84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801324_chaliendad(rdram, ctx);
        goto after_14;
    // 0x80801B84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
L_80801B88:
    // 0x80801B88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801B8C:
    // 0x80801B8C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B90: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801B94: jr          $ra
    // 0x80801B98: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80801B98: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8080105C_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080105C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801060: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80801064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801068: beq         $a1, $at, L_80801098
    if (ctx->r5 == ctx->r1) {
        // 0x8080106C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801098;
    }
    // 0x8080106C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801070: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80801074: beq         $a1, $at, L_808010B0
    if (ctx->r5 == ctx->r1) {
        // 0x80801078: addiu       $v0, $sp, 0x20
        ctx->r2 = ADD32(ctx->r29, 0X20);
            goto L_808010B0;
    }
    // 0x80801078: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x8080107C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80801080: beq         $a1, $at, L_808010C4
    if (ctx->r5 == ctx->r1) {
        // 0x80801084: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808010C4;
    }
    // 0x80801084: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801088: beq         $a1, $at, L_808010D4
    if (ctx->r5 == ctx->r1) {
        // 0x8080108C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808010D4;
    }
    // 0x8080108C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801090: b           L_808010F8
    // 0x80801094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808010F8;
    // 0x80801094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801098:
    // 0x80801098: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x8080109C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808010A0: jal         0x80801108
    // 0x808010A4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80801108_chfactorytwinklies(rdram, ctx);
        goto after_0;
    // 0x808010A4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x808010A8: b           L_808010F8
    // 0x808010AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808010F8;
    // 0x808010AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808010B0:
    // 0x808010B0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808010B4: jal         0x80801174
    // 0x808010B8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80801174_chfactorytwinklies(rdram, ctx);
        goto after_1;
    // 0x808010B8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x808010BC: b           L_808010FC
    // 0x808010C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808010FC;
    // 0x808010C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808010C4:
    // 0x808010C4: jal         0x80800A84
    // 0x808010C8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800A84_chfactorytwinklies(rdram, ctx);
        goto after_2;
    // 0x808010C8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808010CC: b           L_808010F8
    // 0x808010D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808010F8;
    // 0x808010D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808010D4:
    // 0x808010D4: jal         0x8008A090
    // 0x808010D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiemulti_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808010D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808010DC: jal         0x8008A0A8
    // 0x808010E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _subaddiemulti_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808010E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x808010E4: b           L_808010F8
    // 0x808010E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808010F8;
    // 0x808010E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808010EC: b           L_808010F8
    // 0x808010F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808010F8;
    // 0x808010F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808010F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808010F8:
    // 0x808010F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808010FC:
    // 0x808010FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801100: jr          $ra
    // 0x80801104: nop

    return;
    // 0x80801104: nop

;}
RECOMP_FUNC void func_80800F34_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800F38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F40: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800F44: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800F48: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800F4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F50: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800F54: bltzl       $t8, L_80800FFC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800F58: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800FFC;
    }
    goto skip_0;
    // 0x80800F58: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80800F5C: jal         0x8010CD28
    // 0x80800F60: nop

    func_8010CD28(rdram, ctx);
        goto after_0;
    // 0x80800F60: nop

    after_0:
    // 0x80800F64: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800F68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800F6C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800F70: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800F74: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800F78: jal         0x800EFA4C
    // 0x80800F7C: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x80800F7C: nop

    after_1:
    // 0x80800F80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800F84: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80800F88: jal         0x800856B0
    // 0x80800F8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _capod_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800F8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800F90: jal         0x800856E0
    // 0x80800F94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800F94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800F98: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(780, 0X134C) << 16);
    // 0x80800F9C: addiu       $a1, $a1, 0x134C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(780, 0X134C));
    // 0x80800FA0: jal         0x800856E8
    // 0x80800FA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800FA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80800FA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800FAC: jal         0x800856F0
    // 0x80800FB0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _capod_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800FB0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800FB4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80800FB8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800FBC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80800FC0: bne         $t9, $at, L_80800FD0
    if (ctx->r25 != ctx->r1) {
        // 0x80800FC4: nop
    
            goto L_80800FD0;
    }
    // 0x80800FC4: nop

    // 0x80800FC8: b           L_80800FD0
    // 0x80800FCC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
        goto L_80800FD0;
    // 0x80800FCC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
L_80800FD0:
    // 0x80800FD0: jal         0x800856F8
    // 0x80800FD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800FD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80800FD8: jal         0x800880B8
    // 0x80800FDC: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80800FDC: nop

    after_7:
    // 0x80800FE0: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800FEC: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80800FF0: jal         0x8008A4B0
    // 0x80800FF4: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800FF4: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    after_8:
    // 0x80800FF8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_80800FFC:
    // 0x80800FFC: jal         0x800856D8
    // 0x80801000: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _capod_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x80801000: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_9:
    // 0x80801004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801008: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080100C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801010: jr          $ra
    // 0x80801014: nop

    return;
    // 0x80801014: nop

;}
RECOMP_FUNC void _chdiggerbossdeflect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868F0: syscall     395
    recomp_syscall_handler(rdram, ctx, 0x800868F0);
    return;
    // 0x800868F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsbeggass_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800248: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080024C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800250: jal         0x80098140
    // 0x80800254: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x80800254: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800258: jal         0x8009BC6C
    // 0x8080025C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x8080025C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800264: jal         0x800A0CDC
    // 0x80800268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CDC(rdram, ctx);
        goto after_2;
    // 0x80800268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080026C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800270: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800274: jr          $ra
    // 0x80800278: nop

    return;
    // 0x80800278: nop

;}
RECOMP_FUNC void func_80800224_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800228: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080022C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800230: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800234: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800238: addiu       $s1, $a0, 0x18
    ctx->r17 = ADD32(ctx->r4, 0X18);
    // 0x8080023C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800244: lui         $a1, 0xC37A
    ctx->r5 = S32(0XC37A << 16);
    // 0x80800248: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080024C: jal         0x800EFA4C
    // 0x80800250: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800250: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_0:
    // 0x80800254: addiu       $s2, $s0, 0x28
    ctx->r18 = ADD32(ctx->r16, 0X28);
    // 0x80800258: lui         $a3, 0xC46D
    ctx->r7 = S32(0XC46D << 16);
    // 0x8080025C: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800260: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800264: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x80800268: jal         0x800EFA4C
    // 0x8080026C: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x8080026C: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    after_1:
    // 0x80800270: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800274: jal         0x800EF334
    // 0x80800278: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_800EF334(rdram, ctx);
        goto after_2;
    // 0x80800278: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8080027C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800280: jal         0x800EF334
    // 0x80800284: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80800284: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x80800288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080028C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800290: jal         0x800EF934
    // 0x80800294: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    func_800EF934(rdram, ctx);
        goto after_4;
    // 0x80800294: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    after_4:
    // 0x80800298: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080029C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808002A0: jal         0x800EF934
    // 0x808002A4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    func_800EF934(rdram, ctx);
        goto after_5;
    // 0x808002A4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    after_5:
    // 0x808002A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808002B0: jal         0x800EF04C
    // 0x808002B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x808002B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x808002B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808002BC: jal         0x800EF04C
    // 0x808002C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x808002C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x808002C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808002C8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808002CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_808002D0:
    // 0x808002D0: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808002D4: lwc1        $f12, 0x28($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X28);
    // 0x808002D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808002DC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x808002E0: nop

    // 0x808002E4: bc1f        L_808002F4
    if (!c1cs) {
        // 0x808002E8: nop
    
            goto L_808002F4;
    }
    // 0x808002E8: nop

    // 0x808002EC: swc1        $f2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f2.u32l;
    // 0x808002F0: swc1        $f12, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f12.u32l;
L_808002F4:
    // 0x808002F4: bne         $v1, $a0, L_808002D0
    if (ctx->r3 != ctx->r4) {
        // 0x808002F8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_808002D0;
    }
    // 0x808002F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808002FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800300: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800304: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800308: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080030C: jr          $ra
    // 0x80800310: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800310: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800000_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x8080000C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800010: addiu       $a1, $zero, 0x41F
    ctx->r5 = ADD32(0, 0X41F);
    // 0x80800014: jal         0x8009DF18
    // 0x80800018: addiu       $a3, $zero, 0x1F40
    ctx->r7 = ADD32(0, 0X1F40);
    func_8009DF18(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a3, $zero, 0x1F40
    ctx->r7 = ADD32(0, 0X1F40);
    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void func_800EC3C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC3C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC3C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC3CC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800EC3D0: jalr        $t9
    // 0x800EC3D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800EC3D4: nop

    after_0:
    // 0x800EC3D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EC3DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EC3E0: jr          $ra
    // 0x800EC3E4: nop

    return;
    // 0x800EC3E4: nop

;}
RECOMP_FUNC void func_808000BC_chtrashcompactor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x808000C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000C8: jal         0x800F54E4
    // 0x808000CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808000CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000D0: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x808000D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D8: jal         0x800F64A4
    // 0x808000DC: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x808000DC: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_1:
    // 0x808000E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808000E4: bne         $v0, $zero, L_808001F4
    if (ctx->r2 != 0) {
        // 0x808000E8: sw          $zero, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = 0;
            goto L_808001F4;
    }
    // 0x808000E8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x808000EC: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    // 0x808000F0: jal         0x800DA298
    // 0x808000F4: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808000F4: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    after_2:
    // 0x808000F8: bne         $v0, $zero, L_808001F4
    if (ctx->r2 != 0) {
        // 0x808000FC: lw          $v1, 0x80($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X80);
            goto L_808001F4;
    }
    // 0x808000FC: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80800100: jal         0x800F6438
    // 0x80800104: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    func_800F6438(rdram, ctx);
        goto after_3;
    // 0x80800104: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_3:
    // 0x80800108: beql        $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x8080010C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_808001F4;
    }
    goto skip_0;
    // 0x8080010C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_0:
    // 0x80800110: jal         0x800F6478
    // 0x80800114: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    func_800F6478(rdram, ctx);
        goto after_4;
    // 0x80800114: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_4:
    // 0x80800118: beql        $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x8080011C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_808001F4;
    }
    goto skip_1;
    // 0x8080011C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_1:
    // 0x80800120: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800124: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800128: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x8080012C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800130: bnel        $t7, $at, L_808001F4
    if (ctx->r15 != ctx->r1) {
        // 0x80800134: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_808001F4;
    }
    goto skip_2;
    // 0x80800134: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_2:
    // 0x80800138: jal         0x800F5A00
    // 0x8080013C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_800F5A00(rdram, ctx);
        goto after_5;
    // 0x8080013C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_5:
    // 0x80800140: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1128, 0X890) << 16);
    // 0x80800144: lwc1        $f4, 0x890($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1128, 0X890));
    // 0x80800148: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8080014C: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x80800150: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800154: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800158: nop

    // 0x8080015C: bc1fl       L_808001F4
    if (!c1cs) {
        // 0x80800160: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_808001F4;
    }
    goto skip_3;
    // 0x80800160: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_3:
    // 0x80800164: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080016C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80800170: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800174: nop

    // 0x80800178: bc1fl       L_808001F4
    if (!c1cs) {
        // 0x8080017C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_808001F4;
    }
    goto skip_4;
    // 0x8080017C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_4:
    // 0x80800180: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800184: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800188: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8080018C: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x80800190: jal         0x80085708
    // 0x80800194: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x80800194: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_6:
    // 0x80800198: addiu       $a0, $zero, 0x3A7
    ctx->r4 = ADD32(0, 0X3A7);
    // 0x8080019C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808001A0: jal         0x80101180
    // 0x808001A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x808001A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x808001A8: jal         0x80086B58
    // 0x808001AC: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x808001AC: nop

    after_8:
    // 0x808001B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001B4: addiu       $t1, $zero, 0xA3
    ctx->r9 = ADD32(0, 0XA3);
    // 0x808001B8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808001BC: addiu       $a1, $zero, 0x1334
    ctx->r5 = ADD32(0, 0X1334);
    // 0x808001C0: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x808001C4: jal         0x8008A208
    // 0x808001C8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x808001C8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x808001CC: jal         0x800DA544
    // 0x808001D0: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x808001D0: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    after_10:
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x80101FDC
    // 0x808001DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x808001DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808001E0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808001E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001E8: nop

    // 0x808001EC: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x808001F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808001F4:
    // 0x808001F4: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
    // 0x808001F8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1128, 0X9F0) << 16);
    // 0x808001FC: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800200: srl         $t2, $a2, 10
    ctx->r10 = S32(U32(ctx->r6) >> 10);
    // 0x80800204: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80800208: sltu        $a2, $zero, $t3
    ctx->r6 = 0 < ctx->r11 ? 1 : 0;
    // 0x8080020C: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    // 0x80800210: addiu       $a1, $a1, 0x9F0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1128, 0X9F0));
    // 0x80800214: jal         0x80089D70
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080021C: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
    // 0x80800220: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80800224: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800228: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x8080022C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80800230: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80800234: beq         $at, $zero, L_808005E8
    if (ctx->r1 == 0) {
        // 0x80800238: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808005E8;
    }
    // 0x80800238: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080023C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1128, 0X894) << 16);
    // 0x80800240: addu        $at, $at, $t6
    gpr jr_addend_80800248 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800244: lw          $t6, 0x894($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1128, 0X894));
    // 0x80800248: jr          $t6
    // 0x8080024C: nop

    switch (jr_addend_80800248 >> 2) {
        case 0: goto L_80800250; break;
        case 1: goto L_808002F0; break;
        case 2: goto L_80800328; break;
        case 3: goto L_80800404; break;
        case 4: goto L_80800460; break;
        case 5: goto L_80800488; break;
        case 6: goto L_8080050C; break;
        case 7: goto L_808005C8; break;
        default: switch_error(__func__, 0x80800248, 0x80800894);
    }
    // 0x8080024C: nop

L_80800250:
    // 0x80800250: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800254: bne         $v1, $zero, L_808005E8
    if (ctx->r3 != 0) {
        // 0x80800258: sw          $t7, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r15;
            goto L_808005E8;
    }
    // 0x80800258: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x8080025C: jal         0x80090248
    // 0x80800260: nop

    func_80090248(rdram, ctx);
        goto after_13;
    // 0x80800260: nop

    after_13:
    // 0x80800264: beql        $v0, $zero, L_808005EC
    if (ctx->r2 == 0) {
        // 0x80800268: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_808005EC;
    }
    goto skip_5;
    // 0x80800268: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_5:
    // 0x8080026C: jal         0x8008FDC4
    // 0x80800270: nop

    func_8008FDC4(rdram, ctx);
        goto after_14;
    // 0x80800270: nop

    after_14:
    // 0x80800274: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80800278: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x8080027C: beql        $t9, $zero, L_808005EC
    if (ctx->r25 == 0) {
        // 0x80800280: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_808005EC;
    }
    goto skip_6;
    // 0x80800280: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_6:
    // 0x80800284: jal         0x80090150
    // 0x80800288: nop

    func_80090150(rdram, ctx);
        goto after_15;
    // 0x80800288: nop

    after_15:
    // 0x8080028C: beql        $v0, $zero, L_808005EC
    if (ctx->r2 == 0) {
        // 0x80800290: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_808005EC;
    }
    goto skip_7;
    // 0x80800290: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_7:
    // 0x80800294: jal         0x80090708
    // 0x80800298: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_16;
    // 0x80800298: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_16:
    // 0x8080029C: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808002A0: lhu         $t3, 0x76($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X76);
    // 0x808002A4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808002A8: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x808002AC: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x808002B0: bne         $t4, $at, L_808002C0
    if (ctx->r12 != ctx->r1) {
        // 0x808002B4: sb          $t2, 0x65($s0)
        MEM_B(0X65, ctx->r16) = ctx->r10;
            goto L_808002C0;
    }
    // 0x808002B4: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x808002B8: b           L_808002C4
    // 0x808002BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_808002C4;
    // 0x808002BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_808002C0:
    // 0x808002C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_808002C4:
    // 0x808002C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002CC: jal         0x80085708
    // 0x808002D0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    _capod_entrypoint_13(rdram, ctx);
        goto after_17;
    // 0x808002D0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_17:
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: jal         0x80101FDC
    // 0x808002DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_18;
    // 0x808002DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_18:
    // 0x808002E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1128, 0X8B4) << 16);
    // 0x808002E4: lwc1        $f18, 0x8B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1128, 0X8B4));
    // 0x808002E8: b           L_808005E8
    // 0x808002EC: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_808005E8;
    // 0x808002EC: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_808002F0:
    // 0x808002F0: jal         0x800D9078
    // 0x808002F4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_19;
    // 0x808002F4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_19:
    // 0x808002F8: beql        $v0, $zero, L_808005EC
    if (ctx->r2 == 0) {
        // 0x808002FC: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_808005EC;
    }
    goto skip_8;
    // 0x808002FC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_8:
    // 0x80800300: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080030C: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80800310: jal         0x80101FDC
    // 0x80800314: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    func_80101FDC(rdram, ctx);
        goto after_20;
    // 0x80800314: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    after_20:
    // 0x80800318: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1128, 0X8B8) << 16);
    // 0x8080031C: lwc1        $f4, 0x8B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1128, 0X8B8));
    // 0x80800320: b           L_808005E8
    // 0x80800324: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808005E8;
    // 0x80800324: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800328:
    // 0x80800328: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    // 0x8080032C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80800330: jal         0x800D9078
    // 0x80800334: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_21;
    // 0x80800334: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_21:
    // 0x80800338: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080033C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80800340: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800344: lui         $a2, 0x3EE6
    ctx->r6 = S32(0X3EE6 << 16);
    // 0x80800348: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080034C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800350: jal         0x800F12D4
    // 0x80800354: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_22;
    // 0x80800354: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_22:
    // 0x80800358: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080035C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800360: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800364: jal         0x800EFE50
    // 0x80800368: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    func_800EFE50(rdram, ctx);
        goto after_23;
    // 0x80800368: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_23:
    // 0x8080036C: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800378: beq         $t9, $zero, L_808005E8
    if (ctx->r25 == 0) {
        // 0x8080037C: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1128, 0X9FC) << 16);
            goto L_808005E8;
    }
    // 0x8080037C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1128, 0X9FC) << 16);
    // 0x80800380: jal         0x80089D18
    // 0x80800384: addiu       $a2, $a2, 0x9FC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1128, 0X9FC));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x80800384: addiu       $a2, $a2, 0x9FC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1128, 0X9FC));
    after_24:
    // 0x80800388: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1128, 0XA0C) << 16);
    // 0x8080038C: addiu       $a2, $a2, 0xA0C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1128, 0XA0C));
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: jal         0x80089D18
    // 0x80800398: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x80800398: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_25:
    // 0x8080039C: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x808003A0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808003A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808003A8: jal         0x800E15CC
    // 0x808003AC: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_26;
    // 0x808003AC: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    after_26:
    // 0x808003B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808003B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003BC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x808003C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808003C8: jal         0x800187B4
    // 0x808003CC: nop

    func_800187B4(rdram, ctx);
        goto after_27;
    // 0x808003CC: nop

    after_27:
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: jal         0x80101FDC
    // 0x808003D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_28;
    // 0x808003D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_28:
    // 0x808003DC: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x808003E0: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x808003E4: bltz        $t2, L_808003F4
    if (SIGNED(ctx->r10) < 0) {
        // 0x808003E8: nop
    
            goto L_808003F4;
    }
    // 0x808003E8: nop

    // 0x808003EC: jal         0x800904C8
    // 0x808003F0: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    func_800904C8(rdram, ctx);
        goto after_29;
    // 0x808003F0: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    after_29:
L_808003F4:
    // 0x808003F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1128, 0X8BC) << 16);
    // 0x808003F8: lwc1        $f6, 0x8BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1128, 0X8BC));
    // 0x808003FC: b           L_808005E8
    // 0x80800400: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808005E8;
    // 0x80800400: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800404:
    // 0x80800404: jal         0x800D9078
    // 0x80800408: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_30;
    // 0x80800408: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_30:
    // 0x8080040C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800410: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800414: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80800418: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080041C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800420: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800424: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800428: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    // 0x8080042C: jal         0x800F10B4
    // 0x80800430: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_31;
    // 0x80800430: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_31:
    // 0x80800434: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800438: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: beql        $t3, $zero, L_808005EC
    if (ctx->r11 == 0) {
        // 0x80800444: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_808005EC;
    }
    goto skip_9;
    // 0x80800444: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_9:
    // 0x80800448: jal         0x80101FDC
    // 0x8080044C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_32;
    // 0x8080044C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_32:
    // 0x80800450: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1128, 0X8C0) << 16);
    // 0x80800454: lwc1        $f10, 0x8C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1128, 0X8C0));
    // 0x80800458: b           L_808005E8
    // 0x8080045C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_808005E8;
    // 0x8080045C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80800460:
    // 0x80800460: jal         0x800D9078
    // 0x80800464: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_33;
    // 0x80800464: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_33:
    // 0x80800468: beq         $v0, $zero, L_808005E8
    if (ctx->r2 == 0) {
        // 0x8080046C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005E8;
    }
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: jal         0x80101FDC
    // 0x80800474: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_34;
    // 0x80800474: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_34:
    // 0x80800478: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1128, 0X8C4) << 16);
    // 0x8080047C: lwc1        $f16, 0x8C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1128, 0X8C4));
    // 0x80800480: b           L_808005E8
    // 0x80800484: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_808005E8;
    // 0x80800484: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80800488:
    // 0x80800488: jal         0x800D9078
    // 0x8080048C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_35;
    // 0x8080048C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_35:
    // 0x80800490: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800494: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800498: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8080049C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808004A0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808004A4: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x808004A8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808004AC: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    // 0x808004B0: jal         0x800F10B4
    // 0x808004B4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_36;
    // 0x808004B4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_36:
    // 0x808004B8: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x808004BC: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x808004C0: beql        $t4, $zero, L_808005EC
    if (ctx->r12 == 0) {
        // 0x808004C4: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_808005EC;
    }
    goto skip_10;
    // 0x808004C4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_10:
    // 0x808004C8: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x808004CC: sll         $t7, $t5, 11
    ctx->r15 = S32(ctx->r13 << 11);
    // 0x808004D0: bltzl       $t7, L_808004F4
    if (SIGNED(ctx->r15) < 0) {
        // 0x808004D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F4;
    }
    goto skip_11;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_11:
    // 0x808004D8: jal         0x80090708
    // 0x808004DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_37;
    // 0x808004DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_37:
    // 0x808004E0: jal         0x800904C8
    // 0x808004E4: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    func_800904C8(rdram, ctx);
        goto after_38;
    // 0x808004E4: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_38:
    // 0x808004E8: jal         0x80090658
    // 0x808004EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_39;
    // 0x808004EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_39:
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004F4:
    // 0x808004F4: jal         0x80101FDC
    // 0x808004F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_40;
    // 0x808004F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_40:
    // 0x808004FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800504: b           L_808005E8
    // 0x80800508: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808005E8;
    // 0x80800508: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_8080050C:
    // 0x8080050C: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    // 0x80800510: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80800514: jal         0x800D9078
    // 0x80800518: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_41;
    // 0x80800518: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_41:
    // 0x8080051C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800520: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800524: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800528: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8080052C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800530: lui         $a2, 0x3EE6
    ctx->r6 = S32(0X3EE6 << 16);
    // 0x80800534: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800538: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080053C: jal         0x800F12D4
    // 0x80800540: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F12D4(rdram, ctx);
        goto after_42;
    // 0x80800540: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_42:
    // 0x80800544: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800548: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080054C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800550: jal         0x800EFE50
    // 0x80800554: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    func_800EFE50(rdram, ctx);
        goto after_43;
    // 0x80800554: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_43:
    // 0x80800558: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8080055C: beql        $t9, $zero, L_808005EC
    if (ctx->r25 == 0) {
        // 0x80800560: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_808005EC;
    }
    goto skip_12;
    // 0x80800560: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_12:
    // 0x80800564: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80800568: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x8080056C: bltzl       $t2, L_808005A4
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800570: lbu         $t8, 0x65($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X65);
            goto L_808005A4;
    }
    goto skip_13;
    // 0x80800570: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    skip_13:
    // 0x80800574: jal         0x80090658
    // 0x80800578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_44;
    // 0x80800578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_44:
    // 0x8080057C: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80800580: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80800584: bgezl       $t5, L_808005A4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800588: lbu         $t8, 0x65($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X65);
            goto L_808005A4;
    }
    goto skip_14;
    // 0x80800588: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    skip_14:
    // 0x8080058C: jal         0x80085710
    // 0x80800590: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_45;
    // 0x80800590: nop

    after_45:
    // 0x80800594: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800598: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x8080059C: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x808005A0: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
L_808005A4:
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808005AC: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x808005B0: jal         0x80101FDC
    // 0x808005B4: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_80101FDC(rdram, ctx);
        goto after_46;
    // 0x808005B4: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_46:
    // 0x808005B8: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x808005BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005C0: b           L_808005E8
    // 0x808005C4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_808005E8;
    // 0x808005C4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_808005C8:
    // 0x808005C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808005CC: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x808005D0: jal         0x800D9078
    // 0x808005D4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_47;
    // 0x808005D4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_47:
    // 0x808005D8: beq         $v0, $zero, L_808005E8
    if (ctx->r2 == 0) {
        // 0x808005DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005E8;
    }
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: jal         0x80101FDC
    // 0x808005E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_48;
    // 0x808005E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_48:
L_808005E8:
    // 0x808005E8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
L_808005EC:
    // 0x808005EC: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x808005F0: beql        $a0, $zero, L_80800628
    if (ctx->r4 == 0) {
        // 0x808005F4: lw          $t2, 0x7C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X7C);
            goto L_80800628;
    }
    goto skip_15;
    // 0x808005F4: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    skip_15:
    // 0x808005F8: jal         0x80106790
    // 0x808005FC: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    func_80106790(rdram, ctx);
        goto after_49;
    // 0x808005FC: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_49:
    // 0x80800600: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800604: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800608: jal         0x800EE7F8
    // 0x8080060C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_50;
    // 0x8080060C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_50:
    // 0x80800610: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80800614: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800618: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8080061C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800620: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x80800624: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
L_80800628:
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800630: beq         $t2, $zero, L_80800670
    if (ctx->r10 == 0) {
        // 0x80800634: addiu       $a2, $sp, 0x38
        ctx->r6 = ADD32(ctx->r29, 0X38);
            goto L_80800670;
    }
    // 0x80800634: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80800638: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    // 0x8080063C: jal         0x80104004
    // 0x80800640: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    func_80104004(rdram, ctx);
        goto after_51;
    // 0x80800640: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    after_51:
    // 0x80800644: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: jal         0x800EF04C
    // 0x80800650: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_52;
    // 0x80800650: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_52:
    // 0x80800654: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800658: jal         0x800EF04C
    // 0x8080065C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_53;
    // 0x8080065C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_53:
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800664: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800668: jal         0x80089F28
    // 0x8080066C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _sudeflect_entrypoint_2(rdram, ctx);
        goto after_54;
    // 0x8080066C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_54:
L_80800670:
    // 0x80800670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800674: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800678: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8080067C: jr          $ra
    // 0x80800680: nop

    return;
    // 0x80800680: nop

;}
RECOMP_FUNC void func_800E1DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1DF4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E1DF8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E1DFC: lui         $t7, 0x12
    ctx->r15 = S32(0X12 << 16);
    // 0x800E1E00: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E1E04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E1E08: addiu       $t7, $t7, 0x31B0
    ctx->r15 = ADD32(ctx->r15, 0X31B0);
    // 0x800E1E0C: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x800E1E10: addiu       $v1, $v1, -0x2B90
    ctx->r3 = ADD32(ctx->r3, -0X2B90);
    // 0x800E1E14: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800E1E18: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800E1E1C: lbu         $t8, 0x1F($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1F);
    // 0x800E1E20: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800E1E24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E1E28: bne         $t8, $zero, L_800E1E48
    if (ctx->r24 != 0) {
        // 0x800E1E2C: lui         $t1, 0xFA00
        ctx->r9 = S32(0XFA00 << 16);
            goto L_800E1E48;
    }
    // 0x800E1E2C: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800E1E30: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800E1E34: ori         $t9, $t9, 0x1801
    ctx->r25 = ctx->r25 | 0X1801;
    // 0x800E1E38: addiu       $t0, $zero, 0xC0
    ctx->r8 = ADD32(0, 0XC0);
    // 0x800E1E3C: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800E1E40: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800E1E44: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E1E48:
    // 0x800E1E48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E1E4C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800E1E50: lw          $t2, 0x18($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X18);
    // 0x800E1E54: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x800E1E58: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x800E1E5C: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800E1E60: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x800E1E64: lh          $t3, 0x1C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X1C);
    // 0x800E1E68: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800E1E6C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800E1E70: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800E1E74: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800E1E78: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x800E1E7C: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x800E1E80: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x800E1E84: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800E1E88: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800E1E8C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800E1E90: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800E1E94: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800E1E98: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800E1E9C: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800E1EA0: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x800E1EA4: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800E1EA8: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x800E1EAC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800E1EB0: sll         $t3, $t1, 24
    ctx->r11 = S32(ctx->r9 << 24);
    // 0x800E1EB4: or          $t2, $t0, $t3
    ctx->r10 = ctx->r8 | ctx->r11;
    // 0x800E1EB8: sll         $t4, $t6, 16
    ctx->r12 = S32(ctx->r14 << 16);
    // 0x800E1EBC: or          $t7, $t2, $t4
    ctx->r15 = ctx->r10 | ctx->r12;
    // 0x800E1EC0: ori         $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 | 0XFF;
    // 0x800E1EC4: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800E1EC8: lbu         $a3, 0x1E($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X1E);
    // 0x800E1ECC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800E1ED0: blez        $a3, L_800E1FBC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800E1ED4: slti        $at, $a3, 0x5
        ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
            goto L_800E1FBC;
    }
    // 0x800E1ED4: slti        $at, $a3, 0x5
    ctx->r1 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x800E1ED8: beq         $at, $zero, L_800E1FBC
    if (ctx->r1 == 0) {
        // 0x800E1EDC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800E1FBC;
    }
    // 0x800E1EDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E1EE0: lui         $t8, 0xD9FF
    ctx->r24 = S32(0XD9FF << 16);
    // 0x800E1EE4: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800E1EE8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800E1EEC: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x800E1EF0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800E1EF4: lbu         $a2, 0x1E($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1E);
    // 0x800E1EF8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800E1EFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E1F00: beq         $a2, $at, L_800E1F34
    if (ctx->r6 == ctx->r1) {
        // 0x800E1F04: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800E1F34;
    }
    // 0x800E1F04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E1F08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E1F0C: beq         $a2, $at, L_800E1F54
    if (ctx->r6 == ctx->r1) {
        // 0x800E1F10: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800E1F54;
    }
    // 0x800E1F10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E1F14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E1F18: beq         $a2, $at, L_800E1F74
    if (ctx->r6 == ctx->r1) {
        // 0x800E1F1C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800E1F74;
    }
    // 0x800E1F1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E1F20: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E1F24: beq         $a2, $at, L_800E1F9C
    if (ctx->r6 == ctx->r1) {
        // 0x800E1F28: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800E1F9C;
    }
    // 0x800E1F28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E1F2C: b           L_800E200C
    // 0x800E1F30: lbu         $t6, 0x20($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X20);
        goto L_800E200C;
    // 0x800E1F30: lbu         $t6, 0x20($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X20);
L_800E1F34:
    // 0x800E1F34: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x800E1F38: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x800E1F3C: ori         $t3, $t3, 0x4A50
    ctx->r11 = ctx->r11 | 0X4A50;
    // 0x800E1F40: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x800E1F44: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800E1F48: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x800E1F4C: b           L_800E2008
    // 0x800E1F50: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800E2008;
    // 0x800E1F50: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E1F54:
    // 0x800E1F54: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x800E1F58: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x800E1F5C: ori         $t6, $t6, 0x4250
    ctx->r14 = ctx->r14 | 0X4250;
    // 0x800E1F60: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x800E1F64: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800E1F68: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800E1F6C: b           L_800E2008
    // 0x800E1F70: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800E2008;
    // 0x800E1F70: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E1F74:
    // 0x800E1F74: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x800E1F78: lui         $t4, 0x50
    ctx->r12 = S32(0X50 << 16);
    // 0x800E1F7C: ori         $t4, $t4, 0x4A70
    ctx->r12 = ctx->r12 | 0X4A70;
    // 0x800E1F80: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x800E1F84: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800E1F88: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800E1F8C: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800E1F90: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800E1F94: b           L_800E2008
    // 0x800E1F98: sb          $t7, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r15;
        goto L_800E2008;
    // 0x800E1F98: sb          $t7, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r15;
L_800E1F9C:
    // 0x800E1F9C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800E1FA0: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x800E1FA4: ori         $t8, $t8, 0x4B70
    ctx->r24 = ctx->r24 | 0X4B70;
    // 0x800E1FA8: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800E1FAC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800E1FB0: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800E1FB4: b           L_800E2008
    // 0x800E1FB8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800E2008;
    // 0x800E1FB8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E1FBC:
    // 0x800E1FBC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E1FC0: bne         $a3, $at, L_800E1FEC
    if (ctx->r7 != ctx->r1) {
        // 0x800E1FC4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800E1FEC;
    }
    // 0x800E1FC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E1FC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E1FCC: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x800E1FD0: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x800E1FD4: ori         $t0, $t0, 0x4340
    ctx->r8 = ctx->r8 | 0X4340;
    // 0x800E1FD8: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x800E1FDC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800E1FE0: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800E1FE4: b           L_800E2008
    // 0x800E1FE8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800E2008;
    // 0x800E1FE8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E1FEC:
    // 0x800E1FEC: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x800E1FF0: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x800E1FF4: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x800E1FF8: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x800E1FFC: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800E2000: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800E2004: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E2008:
    // 0x800E2008: lbu         $t6, 0x20($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X20);
L_800E200C:
    // 0x800E200C: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x800E2010: ori         $t2, $t2, 0x1E01
    ctx->r10 = ctx->r10 | 0X1E01;
    // 0x800E2014: beq         $t6, $zero, L_800E2044
    if (ctx->r14 == 0) {
        // 0x800E2018: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800E2044;
    }
    // 0x800E2018: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E201C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800E2020: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800E2024: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800E2028: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800E202C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800E2030: lui         $t7, 0xF900
    ctx->r15 = S32(0XF900 << 16);
    // 0x800E2034: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800E2038: lbu         $t8, 0x20($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X20);
    // 0x800E203C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800E2040: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
L_800E2044:
    // 0x800E2044: jr          $ra
    // 0x800E2048: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x800E2048: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800E9CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9CF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E9CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9CFC: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x800E9D00: beql        $t6, $zero, L_800E9D5C
    if (ctx->r14 == 0) {
        // 0x800E9D04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E9D5C;
    }
    goto skip_0;
    // 0x800E9D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E9D08: jal         0x800E9E88
    // 0x800E9D0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x800E9D0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E9D10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E9D14: jal         0x800E9EB4
    // 0x800E9D18: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800E9EB4(rdram, ctx);
        goto after_1;
    // 0x800E9D18: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E9D1C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9D20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E9D24: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800E9D28: beq         $at, $zero, L_800E9D58
    if (ctx->r1 == 0) {
        // 0x800E9D2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800E9D58;
    }
    // 0x800E9D2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E9D30: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
L_800E9D34:
    // 0x800E9D34: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800E9D38: bnel        $v0, $t8, L_800E9D4C
    if (ctx->r2 != ctx->r24) {
        // 0x800E9D3C: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_800E9D4C;
    }
    goto skip_1;
    // 0x800E9D3C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    skip_1:
    // 0x800E9D40: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800E9D44: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    // 0x800E9D48: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_800E9D4C:
    // 0x800E9D4C: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800E9D50: bnel        $at, $zero, L_800E9D34
    if (ctx->r1 != 0) {
        // 0x800E9D54: lw          $t7, 0x8($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X8);
            goto L_800E9D34;
    }
    goto skip_2;
    // 0x800E9D54: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    skip_2:
L_800E9D58:
    // 0x800E9D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E9D5C:
    // 0x800E9D5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E9D60: jr          $ra
    // 0x800E9D64: nop

    return;
    // 0x800E9D64: nop

;}
RECOMP_FUNC void func_8080003C_chfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800048: jal         0x80100094
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800050: jal         0x8008A040
    // 0x80800054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800058: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800060: lbu         $a1, 0x79($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X79);
    // 0x80800064: srl         $t7, $a1, 4
    ctx->r15 = S32(U32(ctx->r5) >> 4);
    // 0x80800068: jal         0x8010A828
    // 0x8080006C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8010A828(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_2:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void func_8009CC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CC18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CC1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CC20: lw          $v0, 0xF0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CC24: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8009CC28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8009CC2C: lbu         $t6, 0x80($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X80);
    // 0x8009CC30: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8009CC34: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x8009CC38: lbu         $t8, -0xF($v1)
    ctx->r24 = MEM_BU(ctx->r3, -0XF);
    // 0x8009CC3C: bne         $t8, $zero, L_8009CC4C
    if (ctx->r24 != 0) {
        // 0x8009CC40: nop
    
            goto L_8009CC4C;
    }
    // 0x8009CC40: nop

    // 0x8009CC44: b           L_8009CC58
    // 0x8009CC48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009CC58;
    // 0x8009CC48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009CC4C:
    // 0x8009CC4C: jal         0x800EE7F8
    // 0x8009CC50: addiu       $a1, $v1, -0xC
    ctx->r5 = ADD32(ctx->r3, -0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009CC50: addiu       $a1, $v1, -0xC
    ctx->r5 = ADD32(ctx->r3, -0XC);
    after_0:
    // 0x8009CC54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009CC58:
    // 0x8009CC58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CC5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CC60: jr          $ra
    // 0x8009CC64: nop

    return;
    // 0x8009CC64: nop

;}
RECOMP_FUNC void _bssub_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D48: syscall     93
    recomp_syscall_handler(rdram, ctx, 0x80083D48);
    return;
    // 0x80083D4C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsbwhirl_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E40: jal         0x80800200
    // 0x80800E44: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_80800200_bsbwhirl(rdram, ctx);
        goto after_0;
    // 0x80800E44: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800E48: jal         0x80800008
    // 0x80800E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_bsbwhirl(rdram, ctx);
        goto after_1;
    // 0x80800E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800E50: jal         0x800839E8
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800E58: beql        $v0, $zero, L_80800E70
    if (ctx->r2 == 0) {
        // 0x80800E5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E70;
    }
    goto skip_0;
    // 0x80800E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800E60: jal         0x800839B0
    // 0x80800E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800E68: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E70:
    // 0x80800E70: jal         0x8009E5C8
    // 0x80800E74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80800E74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E84: jr          $ra
    // 0x80800E88: nop

    return;
    // 0x80800E88: nop

;}
RECOMP_FUNC void func_80801438_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801438: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080143C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801440: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801444: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801448: jal         0x808005DC
    // 0x8080144C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080144C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801450: jal         0x800DB9B0
    // 0x80801454: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x80801454: nop

    after_1:
    // 0x80801458: beql        $v0, $zero, L_80801480
    if (ctx->r2 == 0) {
        // 0x8080145C: lbu         $v0, 0x15C($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X15C);
            goto L_80801480;
    }
    goto skip_0;
    // 0x8080145C: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    skip_0:
    // 0x80801460: jal         0x8009D2E4
    // 0x80801464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D2E4(rdram, ctx);
        goto after_2;
    // 0x80801464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801468: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8080146C: bne         $v0, $at, L_8080147C
    if (ctx->r2 != ctx->r1) {
        // 0x80801470: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080147C;
    }
    // 0x80801470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801474: jal         0x8009D2D8
    // 0x80801478: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009D2D8(rdram, ctx);
        goto after_3;
    // 0x80801478: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_8080147C:
    // 0x8080147C: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
L_80801480:
    // 0x80801480: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801488: beq         $v0, $at, L_808014B0
    if (ctx->r2 == ctx->r1) {
        // 0x8080148C: lui         $a1, 0x3E05
        ctx->r5 = S32(0X3E05 << 16);
            goto L_808014B0;
    }
    // 0x8080148C: lui         $a1, 0x3E05
    ctx->r5 = S32(0X3E05 << 16);
    // 0x80801490: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801494: beq         $v0, $at, L_80801528
    if (ctx->r2 == ctx->r1) {
        // 0x80801498: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801528;
    }
    // 0x80801498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080149C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808014A0: beq         $v0, $at, L_80801558
    if (ctx->r2 == ctx->r1) {
        // 0x808014A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801558;
    }
    // 0x808014A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014A8: b           L_8080158C
    // 0x808014AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080158C;
    // 0x808014AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808014B0:
    // 0x808014B0: jal         0x8008CB10
    // 0x808014B4: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x808014B4: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    after_4:
    // 0x808014B8: beq         $v0, $zero, L_808014C8
    if (ctx->r2 == 0) {
        // 0x808014BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808014C8;
    }
    // 0x808014BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014C0: jal         0x808000C8
    // 0x808014C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808000C8_bstrexsmall(rdram, ctx);
        goto after_5;
    // 0x808014C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_808014C8:
    // 0x808014C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014CC: jal         0x80091A94
    // 0x808014D0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_newlyReleased(rdram, ctx);
        goto after_6;
    // 0x808014D0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x808014D4: beq         $v0, $zero, L_808014E0
    if (ctx->r2 == 0) {
        // 0x808014D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808014E0;
    }
    // 0x808014D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014DC: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
L_808014E0:
    // 0x808014E0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808014E4: jal         0x8008CB10
    // 0x808014E8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    baanim_isAt(rdram, ctx);
        goto after_7;
    // 0x808014E8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_7:
    // 0x808014EC: beql        $v0, $zero, L_8080158C
    if (ctx->r2 == 0) {
        // 0x808014F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080158C;
    }
    goto skip_1;
    // 0x808014F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808014F4: lbu         $t6, 0x15D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15D);
    // 0x808014F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808014FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801500: beq         $t6, $zero, L_80801518
    if (ctx->r14 == 0) {
        // 0x80801504: nop
    
            goto L_80801518;
    }
    // 0x80801504: nop

    // 0x80801508: jal         0x80801294
    // 0x8080150C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801294_bstrexsmall(rdram, ctx);
        goto after_8;
    // 0x8080150C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801510: b           L_8080158C
    // 0x80801514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080158C;
    // 0x80801514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801518:
    // 0x80801518: jal         0x80801294
    // 0x8080151C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801294_bstrexsmall(rdram, ctx);
        goto after_9;
    // 0x8080151C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80801520: b           L_8080158C
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080158C;
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801528:
    // 0x80801528: jal         0x8008CB10
    // 0x8080152C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    baanim_isAt(rdram, ctx);
        goto after_10;
    // 0x8080152C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_10:
    // 0x80801530: beq         $v0, $zero, L_80801540
    if (ctx->r2 == 0) {
        // 0x80801534: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801540;
    }
    // 0x80801534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801538: jal         0x808000C8
    // 0x8080153C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808000C8_bstrexsmall(rdram, ctx);
        goto after_11;
    // 0x8080153C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
L_80801540:
    // 0x80801540: jal         0x8008CAEC
    // 0x80801544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_12;
    // 0x80801544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801548: beq         $v0, $zero, L_80801588
    if (ctx->r2 == 0) {
        // 0x8080154C: addiu       $t7, $zero, 0x145
        ctx->r15 = ADD32(0, 0X145);
            goto L_80801588;
    }
    // 0x8080154C: addiu       $t7, $zero, 0x145
    ctx->r15 = ADD32(0, 0X145);
    // 0x80801550: b           L_80801588
    // 0x80801554: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80801588;
    // 0x80801554: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80801558:
    // 0x80801558: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x8080155C: jal         0x8008CB10
    // 0x80801560: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    baanim_isAt(rdram, ctx);
        goto after_13;
    // 0x80801560: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_13:
    // 0x80801564: beq         $v0, $zero, L_80801574
    if (ctx->r2 == 0) {
        // 0x80801568: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801574;
    }
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080156C: jal         0x808000C8
    // 0x80801570: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808000C8_bstrexsmall(rdram, ctx);
        goto after_14;
    // 0x80801570: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
L_80801574:
    // 0x80801574: jal         0x8008CAEC
    // 0x80801578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_15;
    // 0x80801578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080157C: beq         $v0, $zero, L_80801588
    if (ctx->r2 == 0) {
        // 0x80801580: addiu       $t8, $zero, 0x145
        ctx->r24 = ADD32(0, 0X145);
            goto L_80801588;
    }
    // 0x80801580: addiu       $t8, $zero, 0x145
    ctx->r24 = ADD32(0, 0X145);
    // 0x80801584: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80801588:
    // 0x80801588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080158C:
    // 0x8080158C: jal         0x8009E5C8
    // 0x80801590: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_16;
    // 0x80801590: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_16:
    // 0x80801594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801598: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080159C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808015A0: jr          $ra
    // 0x808015A4: nop

    return;
    // 0x808015A4: nop

;}
RECOMP_FUNC void func_800A5854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5854: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5858: lw          $t6, -0x6AC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6AC0);
    // 0x800A585C: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x800A5860: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A5864: jr          $ra
    // 0x800A5868: lbu         $v0, 0x3C($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X3C);
    return;
    // 0x800A5868: lbu         $v0, 0x3C($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X3C);
;}
RECOMP_FUNC void badust_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A24: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800A28: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800A2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XCA4) << 16);
    // 0x80800A30: lwc1        $f24, 0xCA4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XCA4));
    // 0x80800A34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800A38: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800A3C: mtc1        $a1, $f26
    ctx->f26.u32l = ctx->r5;
    // 0x80800A40: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80800A44: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80800A48: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800A4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A50: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800A54: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80800A58: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800A5C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800A60: bc1f        L_80800ABC
    if (!c1cs) {
        // 0x80800A64: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80800ABC;
    }
    // 0x80800A64: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800A68: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800A6C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800A70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XCA8) << 16);
    // 0x80800A74: lwc1        $f28, 0xCA8($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XCA8));
    // 0x80800A78: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800A7C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800A80: nop

    // 0x80800A84: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
L_80800A88:
    // 0x80800A88: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800A8C: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A94: jal         0x8080062C
    // 0x80800A98: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    badust_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800A98: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    after_0:
    // 0x80800A9C: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80800AA0: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x80800AA4: nop

    // 0x80800AA8: bc1tl       L_80800A88
    if (c1cs) {
        // 0x80800AAC: mfc1        $a1, $f26
        ctx->r5 = (int32_t)ctx->f26.u32l;
            goto L_80800A88;
    }
    goto skip_0;
    // 0x80800AAC: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    skip_0:
    // 0x80800AB0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800AB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800AB8: nop

L_80800ABC:
    // 0x80800ABC: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80800AC0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800AC4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800AC8: lui         $at, 0x43D7
    ctx->r1 = S32(0X43D7 << 16);
    // 0x80800ACC: bc1fl       L_80800B24
    if (!c1cs) {
        // 0x80800AD0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80800B24;
    }
    goto skip_1;
    // 0x80800AD0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x80800AD4: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800AD8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800ADC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800AE0: nop

L_80800AE4:
    // 0x80800AE4: jal         0x800136E4
    // 0x80800AE8: add.s       $f12, $f20, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f28.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80800AE8: add.s       $f12, $f20, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f28.fl;
    after_1:
    // 0x80800AEC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800AF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800AF4: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80800AF8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800AFC: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B04: jal         0x8080062C
    // 0x80800B08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    badust_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800B08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800B0C: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80800B10: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x80800B14: nop

    // 0x80800B18: bc1t        L_80800AE4
    if (c1cs) {
        // 0x80800B1C: nop
    
            goto L_80800AE4;
    }
    // 0x80800B1C: nop

    // 0x80800B20: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80800B24:
    // 0x80800B24: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800B28: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800B2C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800B30: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800B34: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80800B38: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80800B3C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80800B40: jr          $ra
    // 0x80800B44: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800B44: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void gcsectionDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800180: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800184: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800188: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2666, 0X212) << 16);
    // 0x8080018C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80800190: lh          $t7, 0x212($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(2666, 0X212));
    // 0x80800194: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800198: and         $t8, $t7, $a1
    ctx->r24 = ctx->r15 & ctx->r5;
    // 0x8080019C: beq         $t8, $zero, L_808001AC
    if (ctx->r24 == 0) {
        // 0x808001A0: nop
    
            goto L_808001AC;
    }
    // 0x808001A0: nop

    // 0x808001A4: jr          $ra
    // 0x808001A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808001A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001AC:
    // 0x808001AC: jr          $ra
    // 0x808001B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808001B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80802D38_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802D40: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80802D44: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80802D48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802D4C: beql        $t6, $zero, L_80802D68
    if (ctx->r14 == 0) {
        // 0x80802D50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802D68;
    }
    goto skip_0;
    // 0x80802D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802D54: jal         0x800856B8
    // 0x80802D58: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80802D58: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802D5C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80802D60: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x80802D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802D68:
    // 0x80802D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802D6C: jr          $ra
    // 0x80802D70: nop

    return;
    // 0x80802D70: nop

;}
RECOMP_FUNC void func_80801B10_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B18: jal         0x808000F0
    // 0x80801B1C: nop

    func_808000F0_bswasher(rdram, ctx);
        goto after_0;
    // 0x80801B1C: nop

    after_0:
    // 0x80801B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B28: jr          $ra
    // 0x80801B2C: nop

    return;
    // 0x80801B2C: nop

;}
RECOMP_FUNC void _fxrain_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088928: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x80088928);
    return;
    // 0x8008892C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
