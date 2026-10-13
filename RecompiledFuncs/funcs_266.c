#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800A00CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A00CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A00D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A00D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800A00D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A00DC: jal         0x8009C128
    // 0x800A00E0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800A00E0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800A00E4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800A00E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800A00EC: jal         0x800F18FC
    // 0x800A00F0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800F18FC(rdram, ctx);
        goto after_1;
    // 0x800A00F0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800A00F4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A00F8: jal         0x8009C914
    // 0x800A00FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    yaw_setIdeal(rdram, ctx);
        goto after_2;
    // 0x800A00FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800A0100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0104: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A0108: jr          $ra
    // 0x800A010C: nop

    return;
    // 0x800A010C: nop

;}
RECOMP_FUNC void _subaddieDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A490: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A490);
    return;
    // 0x8008A494: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _susubgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2A8: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2A8);
    return;
    // 0x8008A2AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808002BC_chjinjovillagecamera1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002C8: jal         0x80086B90
    // 0x808002CC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    _chjinjo_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808002CC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // 0x808002D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808002D4: beq         $v0, $at, L_80800300
    if (ctx->r2 == ctx->r1) {
        // 0x808002D8: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_80800300;
    }
    // 0x808002D8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x808002DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002E0: jal         0x800BF744
    // 0x808002E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800BF744(rdram, ctx);
        goto after_1;
    // 0x808002E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808002E8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808002EC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2028, 0X488) << 16);
    // 0x808002F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002F4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x808002F8: jal         0x800BF744
    // 0x808002FC: lbu         $a0, 0x488($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(2028, 0X488));
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x808002FC: lbu         $a0, 0x488($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(2028, 0X488));
    after_2:
L_80800300:
    // 0x80800300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800304: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800308: jr          $ra
    // 0x8080030C: nop

    return;
    // 0x8080030C: nop

;}
RECOMP_FUNC void func_800B5E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5E74: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B5E78: addiu       $v1, $v1, -0x7E80
    ctx->r3 = ADD32(ctx->r3, -0X7E80);
    // 0x800B5E7C: lbu         $v0, 0x1C($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1C);
    // 0x800B5E80: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B5E84: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800B5E88: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800B5E8C: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x800B5E90: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B5E94: beq         $at, $zero, L_800B5F8C
    if (ctx->r1 == 0) {
        // 0x800B5E98: sb          $zero, 0x1C($v1)
        MEM_B(0X1C, ctx->r3) = 0;
            goto L_800B5F8C;
    }
    // 0x800B5E98: sb          $zero, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = 0;
    // 0x800B5E9C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B5EA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5EA4: addu        $at, $at, $t7
    gpr jr_addend_800B5EAC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B5EA8: lw          $t7, 0x5640($at)
    ctx->r15 = ADD32(ctx->r1, 0X5640);
    // 0x800B5EAC: jr          $t7
    // 0x800B5EB0: nop

    switch (jr_addend_800B5EAC >> 2) {
        case 0: goto L_800B5F18; break;
        case 1: goto L_800B5EB4; break;
        case 2: goto L_800B5EC4; break;
        case 3: goto L_800B5ED4; break;
        case 4: goto L_800B5EDC; break;
        case 5: goto L_800B5EE4; break;
        case 6: goto L_800B5EF4; break;
        case 7: goto L_800B5F10; break;
        default: switch_error(__func__, 0x800B5EAC, 0x80125640);
    }
    // 0x800B5EB0: nop

L_800B5EB4:
    // 0x800B5EB4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800B5EB8: sb          $a0, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r4;
    // 0x800B5EBC: b           L_800B5FD8
    // 0x800B5EC0: sb          $t8, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r24;
        goto L_800B5FD8;
    // 0x800B5EC0: sb          $t8, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r24;
L_800B5EC4:
    // 0x800B5EC4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800B5EC8: sb          $a0, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r4;
    // 0x800B5ECC: b           L_800B5FD8
    // 0x800B5ED0: sb          $t9, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r25;
        goto L_800B5FD8;
    // 0x800B5ED0: sb          $t9, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r25;
L_800B5ED4:
    // 0x800B5ED4: b           L_800B5FD8
    // 0x800B5ED8: sb          $a0, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r4;
        goto L_800B5FD8;
    // 0x800B5ED8: sb          $a0, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r4;
L_800B5EDC:
    // 0x800B5EDC: b           L_800B5FD8
    // 0x800B5EE0: sb          $a0, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r4;
        goto L_800B5FD8;
    // 0x800B5EE0: sb          $a0, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r4;
L_800B5EE4:
    // 0x800B5EE4: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800B5EE8: sh          $a0, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r4;
    // 0x800B5EEC: b           L_800B5FD8
    // 0x800B5EF0: sb          $t0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r8;
        goto L_800B5FD8;
    // 0x800B5EF0: sb          $t0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r8;
L_800B5EF4:
    // 0x800B5EF4: lh          $t1, 0x28($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X28);
    // 0x800B5EF8: sll         $t2, $a0, 8
    ctx->r10 = S32(ctx->r4 << 8);
    // 0x800B5EFC: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800B5F00: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x800B5F04: sh          $t3, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r11;
    // 0x800B5F08: b           L_800B5FD8
    // 0x800B5F0C: sb          $t4, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r12;
        goto L_800B5FD8;
    // 0x800B5F0C: sb          $t4, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r12;
L_800B5F10:
    // 0x800B5F10: b           L_800B5FD8
    // 0x800B5F14: sh          $a0, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r4;
        goto L_800B5FD8;
    // 0x800B5F14: sh          $a0, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r4;
L_800B5F18:
    // 0x800B5F18: addiu       $t5, $a0, -0x61
    ctx->r13 = ADD32(ctx->r4, -0X61);
    // 0x800B5F1C: sltiu       $at, $t5, 0x10
    ctx->r1 = ctx->r13 < 0X10 ? 1 : 0;
    // 0x800B5F20: beq         $at, $zero, L_800B5F84
    if (ctx->r1 == 0) {
        // 0x800B5F24: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_800B5F84;
    }
    // 0x800B5F24: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B5F28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5F2C: addu        $at, $at, $t5
    gpr jr_addend_800B5F34 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800B5F30: lw          $t5, 0x5660($at)
    ctx->r13 = ADD32(ctx->r1, 0X5660);
    // 0x800B5F34: jr          $t5
    // 0x800B5F38: nop

    switch (jr_addend_800B5F34 >> 2) {
        case 0: goto L_800B5F60; break;
        case 1: goto L_800B5F84; break;
        case 2: goto L_800B5F6C; break;
        case 3: goto L_800B5F84; break;
        case 4: goto L_800B5F84; break;
        case 5: goto L_800B5F84; break;
        case 6: goto L_800B5F84; break;
        case 7: goto L_800B5F44; break;
        case 8: goto L_800B5F78; break;
        case 9: goto L_800B5F50; break;
        case 10: goto L_800B5F84; break;
        case 11: goto L_800B5F3C; break;
        case 12: goto L_800B5F84; break;
        case 13: goto L_800B5F84; break;
        case 14: goto L_800B5F84; break;
        case 15: goto L_800B5FD8; break;
        default: switch_error(__func__, 0x800B5F34, 0x80125660);
    }
    // 0x800B5F38: nop

L_800B5F3C:
    // 0x800B5F3C: b           L_800B5FD8
    // 0x800B5F40: sb          $zero, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = 0;
        goto L_800B5FD8;
    // 0x800B5F40: sb          $zero, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = 0;
L_800B5F44:
    // 0x800B5F44: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B5F48: b           L_800B5FD8
    // 0x800B5F4C: sb          $t6, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r14;
        goto L_800B5FD8;
    // 0x800B5F4C: sb          $t6, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r14;
L_800B5F50:
    // 0x800B5F50: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800B5F54: sb          $t7, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r15;
    // 0x800B5F58: b           L_800B5FD8
    // 0x800B5F5C: sb          $zero, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = 0;
        goto L_800B5FD8;
    // 0x800B5F5C: sb          $zero, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = 0;
L_800B5F60:
    // 0x800B5F60: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800B5F64: b           L_800B5FD8
    // 0x800B5F68: sb          $t8, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r24;
        goto L_800B5FD8;
    // 0x800B5F68: sb          $t8, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r24;
L_800B5F6C:
    // 0x800B5F6C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800B5F70: b           L_800B5FD8
    // 0x800B5F74: sb          $t9, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r25;
        goto L_800B5FD8;
    // 0x800B5F74: sb          $t9, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r25;
L_800B5F78:
    // 0x800B5F78: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800B5F7C: b           L_800B5FD8
    // 0x800B5F80: sb          $t0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r8;
        goto L_800B5FD8;
    // 0x800B5F80: sb          $t0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r8;
L_800B5F84:
    // 0x800B5F84: jr          $ra
    // 0x800B5F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B5F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5F8C:
    // 0x800B5F8C: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x800B5F90: beq         $a0, $at, L_800B5FB8
    if (ctx->r4 == ctx->r1) {
        // 0x800B5F94: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800B5FB8;
    }
    // 0x800B5F94: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800B5F98: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x800B5F9C: beq         $a0, $at, L_800B5FC0
    if (ctx->r4 == ctx->r1) {
        // 0x800B5FA0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800B5FC0;
    }
    // 0x800B5FA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B5FA4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B5FA8: beq         $a0, $at, L_800B5FC8
    if (ctx->r4 == ctx->r1) {
        // 0x800B5FAC: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_800B5FC8;
    }
    // 0x800B5FAC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800B5FB0: jr          $ra
    // 0x800B5FB4: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    return;
    // 0x800B5FB4: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
L_800B5FB8:
    // 0x800B5FB8: b           L_800B5FD8
    // 0x800B5FBC: sb          $t1, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r9;
        goto L_800B5FD8;
    // 0x800B5FBC: sb          $t1, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r9;
L_800B5FC0:
    // 0x800B5FC0: b           L_800B5FD8
    // 0x800B5FC4: sb          $t2, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r10;
        goto L_800B5FD8;
    // 0x800B5FC4: sb          $t2, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r10;
L_800B5FC8:
    // 0x800B5FC8: b           L_800B5FD8
    // 0x800B5FCC: sb          $t3, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r11;
        goto L_800B5FD8;
    // 0x800B5FCC: sb          $t3, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r11;
    // 0x800B5FD0: jr          $ra
    // 0x800B5FD4: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    return;
    // 0x800B5FD4: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
L_800B5FD8:
    // 0x800B5FD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B5FDC: jr          $ra
    // 0x800B5FE0: nop

    return;
    // 0x800B5FE0: nop

;}
RECOMP_FUNC void func_800A30B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A30B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A30B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A30BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A30C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800A30C4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800A30C8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800A30CC: jal         0x800A3148
    // 0x800A30D0: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    func_800A3148(rdram, ctx);
        goto after_0;
    // 0x800A30D0: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800A30D4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A30D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A30DC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A30E0: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A30E4: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A30E8: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A30EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A30F0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800A30F4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800A30F8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800A30FC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A3100: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800A3104: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800A3108: jal         0x800EFA4C
    // 0x800A310C: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x800A310C: nop

    after_1:
    // 0x800A3110: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A3114: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A3118: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A311C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A3120: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800A3124: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A3128: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800A312C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800A3130: jal         0x800EFA4C
    // 0x800A3134: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x800A3134: nop

    after_2:
    // 0x800A3138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A313C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A3140: jr          $ra
    // 0x800A3144: nop

    return;
    // 0x800A3144: nop

;}
RECOMP_FUNC void func_80800120_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800128: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x8080012C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800130: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800134: beql        $t6, $zero, L_80800150
    if (ctx->r14 == 0) {
        // 0x80800138: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800150;
    }
    goto skip_0;
    // 0x80800138: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x8080013C: jal         0x800FC74C
    // 0x80800140: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800FC74C(rdram, ctx);
        goto after_0;
    // 0x80800140: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800144: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800148: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
    // 0x8080014C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80800150:
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800154: jal         0x8080102C
    // 0x80800158: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8080102C_chjinjo(rdram, ctx);
        goto after_1;
    // 0x80800158: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8080015C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800160: jal         0x800897C8
    // 0x80800164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080016C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800170: jr          $ra
    // 0x80800174: nop

    return;
    // 0x80800174: nop

;}
RECOMP_FUNC void func_80101068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101068: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010106C: jr          $ra
    // 0x80101070: lwc1        $f0, 0x5A7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A7C);
    return;
    // 0x80101070: lwc1        $f0, 0x5A7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5A7C);
;}
RECOMP_FUNC void fxgenlist_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2850, 0XD0) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2850, 0XD0));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2850, 0XD0));
;}
RECOMP_FUNC void bsbwhirl_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800900: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800904: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800908: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080090C: jal         0x8008CABC
    // 0x80800910: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800910: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800914: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800918: jal         0x8008AF24
    // 0x8080091C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x8080091C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800924: jal         0x8008AED4
    // 0x80800928: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800928: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_2:
    // 0x8080092C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800930: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800934: jal         0x8008B1BC
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080093C: lui         $a1, 0x3E09
    ctx->r5 = S32(0X3E09 << 16);
    // 0x80800940: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x80800944: jal         0x8008B1C8
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080094C: lui         $a1, 0x3E0F
    ctx->r5 = S32(0X3E0F << 16);
    // 0x80800950: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x80800954: jal         0x8008B24C
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_5;
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080095C: lui         $a2, 0x3EE6
    ctx->r6 = S32(0X3EE6 << 16);
    // 0x80800960: ori         $a2, $a2, 0x24DD
    ctx->r6 = ctx->r6 | 0X24DD;
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800968: jal         0x8008B1D4
    // 0x8080096C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x8080096C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800974: jal         0x8008B134
    // 0x80800978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80800978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8080097C: jal         0x8008B064
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800984: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800988: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080098C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800990: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800994: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800998: jal         0x8009FFD8
    // 0x8080099C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x8080099C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x808009A0: jal         0x8009EF04
    // 0x808009A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_10;
    // 0x808009A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x808009A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808009AC: nop

    // 0x808009B0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808009B4: nop

    // 0x808009B8: bc1t        L_808009D4
    if (c1cs) {
        // 0x808009BC: nop
    
            goto L_808009D4;
    }
    // 0x808009BC: nop

    // 0x808009C0: jal         0x8009EEB8
    // 0x808009C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_11;
    // 0x808009C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x808009C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808009CC: jal         0x8009C914
    // 0x808009D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_12;
    // 0x808009D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
L_808009D4:
    // 0x808009D4: jal         0x8009C990
    // 0x808009D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_13;
    // 0x808009D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x808009DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808009E0: jal         0x8009B9C0
    // 0x808009E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_14;
    // 0x808009E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x808009E8: jal         0x80800114
    // 0x808009EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800114_bsbwhirl(rdram, ctx);
        goto after_15;
    // 0x808009EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x808009F0: jal         0x8009C990
    // 0x808009F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_16;
    // 0x808009F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x808009F8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808009FC: jal         0x8009BB00
    // 0x80800A00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800A00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800A04: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800A08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A0C: jal         0x8009BA68
    // 0x80800A10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800A10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x80800A14: lui         $a1, 0x442D
    ctx->r5 = S32(0X442D << 16);
    // 0x80800A18: ori         $a1, $a1, 0x6000
    ctx->r5 = ctx->r5 | 0X6000;
    // 0x80800A1C: jal         0x8009BA58
    // 0x80800A20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_19;
    // 0x80800A20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80800A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A28: jal         0x8009BCB4
    // 0x80800A2C: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_20;
    // 0x80800A2C: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_20:
    // 0x80800A30: lui         $a1, 0x3F68
    ctx->r5 = S32(0X3F68 << 16);
    // 0x80800A34: lui         $a2, 0x3F8B
    ctx->r6 = S32(0X3F8B << 16);
    // 0x80800A38: ori         $a2, $a2, 0x851F
    ctx->r6 = ctx->r6 | 0X851F;
    // 0x80800A3C: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x80800A40: jal         0x8009D7A4
    // 0x80800A44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009D7A4(rdram, ctx);
        goto after_21;
    // 0x80800A44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x80800A48: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800A4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A50: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800A54: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A58: jr          $ra
    // 0x80800A5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800A5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chexploder_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086688: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x80086688);
    return;
    // 0x8008668C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800560_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800568: jal         0x80082FF0
    // 0x8080056C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080056C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800570: jal         0x8080016C
    // 0x80800574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsmum_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080057C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800580: jr          $ra
    // 0x80800584: nop

    return;
    // 0x80800584: nop

;}
RECOMP_FUNC void func_80801054_subaddiestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801054: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801058: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080105C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801060: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801064: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801068: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080106C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801070: lw          $s2, 0x6C($a1)
    ctx->r18 = MEM_W(ctx->r5, 0X6C);
    // 0x80801074: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80801078: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8080107C: srl         $t6, $s2, 21
    ctx->r14 = S32(U32(ctx->r18) >> 21);
    // 0x80801080: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80801084: addiu       $s1, $a0, 0x4
    ctx->r17 = ADD32(ctx->r4, 0X4);
    // 0x80801088: blez        $t7, L_808010D4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8080108C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808010D4;
    }
    // 0x8080108C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801090: lw          $t8, 0x6C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X6C);
L_80801094:
    // 0x80801094: srl         $t9, $t8, 21
    ctx->r25 = S32(U32(ctx->r24) >> 21);
    // 0x80801098: bne         $s2, $t9, L_808010B0
    if (ctx->r18 != ctx->r25) {
        // 0x8080109C: nop
    
            goto L_808010B0;
    }
    // 0x8080109C: nop

    // 0x808010A0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808010A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808010A8: b           L_80801114
    // 0x808010AC: sw          $s1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r17;
        goto L_80801114;
    // 0x808010AC: sw          $s1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r17;
L_808010B0:
    // 0x808010B0: jal         0x80800FD0
    // 0x808010B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800FD0_subaddiestore(rdram, ctx);
        goto after_0;
    // 0x808010B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x808010B8: lh          $t1, 0x0($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X0);
    // 0x808010BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808010C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808010C4: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808010C8: bnel        $at, $zero, L_80801094
    if (ctx->r1 != 0) {
        // 0x808010CC: lw          $t8, 0x6C($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X6C);
            goto L_80801094;
    }
    goto skip_0;
    // 0x808010CC: lw          $t8, 0x6C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X6C);
    skip_0:
    // 0x808010D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808010D4:
    // 0x808010D4: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x808010D8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x808010DC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x808010E0: blezl       $v1, L_80801114
    if (SIGNED(ctx->r3) <= 0) {
        // 0x808010E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801114;
    }
    goto skip_1;
    // 0x808010E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_808010E8:
    // 0x808010E8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x808010EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808010F0: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808010F4: bne         $s2, $t2, L_80801108
    if (ctx->r18 != ctx->r10) {
        // 0x808010F8: nop
    
            goto L_80801108;
    }
    // 0x808010F8: nop

    // 0x808010FC: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x80801100: b           L_80801114
    // 0x80801104: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80801114;
    // 0x80801104: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80801108:
    // 0x80801108: bne         $at, $zero, L_808010E8
    if (ctx->r1 != 0) {
        // 0x8080110C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_808010E8;
    }
    // 0x8080110C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801114:
    // 0x80801114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801118: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080111C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801120: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801124: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801128: jr          $ra
    // 0x8080112C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080112C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bsow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083928: syscall     82
    recomp_syscall_handler(rdram, ctx, 0x80083928);
    return;
    // 0x8008392C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F640C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F640C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6414: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F641C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6420: jal         0x8008F828
    // 0x800F6424: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008F828(rdram, ctx);
        goto after_0;
    // 0x800F6424: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F6428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F642C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6430: jr          $ra
    // 0x800F6434: nop

    return;
    // 0x800F6434: nop

;}
RECOMP_FUNC void chcheatomenu_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1708, 0X89C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x89C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1708, 0X89C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x89C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1708, 0X89C));
;}
RECOMP_FUNC void _ncfixposrot_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891E8: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x800891E8);
    return;
    // 0x800891EC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chexploder_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080199C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808019A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808019A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808019AC: jal         0x80100094
    // 0x808019B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808019B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808019B4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808019B8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808019BC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x808019C0: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x808019C4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808019C8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808019CC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808019D0: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x808019D4: nop

    // 0x808019D8: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
    // 0x808019DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808019E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808019E4: jr          $ra
    // 0x808019E8: nop

    return;
    // 0x808019E8: nop

;}
RECOMP_FUNC void func_808000BC_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000C8: jal         0x8009C908
    // 0x808000CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_0;
    // 0x808000CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808000D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000D4: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808000D8: jal         0x8009C99C
    // 0x808000DC: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_1;
    // 0x808000DC: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    after_1:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_8010C710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C710: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010C714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C718: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8010C71C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010C720: addiu       $a2, $a2, 0x6F50
    ctx->r6 = ADD32(ctx->r6, 0X6F50);
    // 0x8010C724: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x8010C728: jal         0x800EFB24
    // 0x8010C72C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x8010C72C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8010C730: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8010C734: jal         0x800EEAA4
    // 0x8010C738: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_1;
    // 0x8010C738: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_1:
    // 0x8010C73C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010C740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010C748: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8010C74C: jr          $ra
    // 0x8010C750: nop

    return;
    // 0x8010C750: nop

;}
RECOMP_FUNC void _chwitchyentrygates_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870C8: syscall     511
    recomp_syscall_handler(rdram, ctx, 0x800870C8);
    return;
    // 0x800870CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _dbpalette_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087960: syscall     641
    recomp_syscall_handler(rdram, ctx, 0x80087960);
    return;
    // 0x80087964: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800354_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080035C: jal         0x8010CD28
    // 0x80800360: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010CD28(rdram, ctx);
        goto after_0;
    // 0x80800360: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800364: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800368: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8080036C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800370: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800374: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1064, 0XB34) << 16);
    // 0x80800378: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    // 0x8080037C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800380: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x80800384: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x80800388: lwc1        $f12, 0xB34($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1064, 0XB34));
    // 0x8080038C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800390: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800394: jal         0x800DC178
    // 0x80800398: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800398: nop

    after_1:
    // 0x8080039C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003A0: swc1        $f0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f0.u32l;
    // 0x808003A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003AC: jr          $ra
    // 0x808003B0: nop

    return;
    // 0x808003B0: nop

;}
RECOMP_FUNC void func_80800150_bsdronegoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800154: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800158: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080015C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800160: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800164: jal         0x80084648
    // 0x80800168: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    _badata_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800168: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800174: jal         0x8008CB3C
    // 0x80800178: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800178: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800184: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80800188: jal         0x80084828
    // 0x8080018C: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    _badrone_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x8080018C: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x80800190: jal         0x80084DB8
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x80084E18
    // 0x808001A0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _bamovegoto_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x808001A0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x808001A4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808001A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808001B8: nop

    // 0x808001BC: bc1t        L_808001E0
    if (c1cs) {
        // 0x808001C0: nop
    
            goto L_808001E0;
    }
    // 0x808001C0: nop

    // 0x808001C4: jal         0x80084E00
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80084DF0
    // 0x808001D4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    _bamovegoto_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x808001D4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_6:
    // 0x808001D8: b           L_808001F8
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808001F8;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001E0:
    // 0x808001E0: jal         0x80084E00
    // 0x808001E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bamovegoto_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808001E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: jal         0x80084DF8
    // 0x808001F0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _bamovegoto_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x808001F0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001F8:
    // 0x808001F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800200: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800204: jal         0x8009FFD8
    // 0x80800208: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80800208: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x8080020C: jal         0x80095898
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095898(rdram, ctx);
        goto after_10;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800214: sw          $v0, 0x198($s0)
    MEM_W(0X198, ctx->r16) = ctx->r2;
    // 0x80800218: jal         0x80084820
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_7(rdram, ctx);
        goto after_11;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800220: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800224: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800248;
    }
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: jal         0x800961A0
    // 0x80800230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800961A0(rdram, ctx);
        goto after_12;
    // 0x80800230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: jal         0x80084E08
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bamovegoto_entrypoint_10(rdram, ctx);
        goto after_13;
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800240: b           L_80800250
    // 0x80800244: nop

        goto L_80800250;
    // 0x80800244: nop

L_80800248:
    // 0x80800248: jal         0x800961A0
    // 0x8080024C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961A0(rdram, ctx);
        goto after_14;
    // 0x8080024C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
L_80800250:
    // 0x80800250: jal         0x80084E20
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_13(rdram, ctx);
        goto after_15;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800258: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080025C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800260: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800264: jr          $ra
    // 0x80800268: nop

    return;
    // 0x80800268: nop

;}
RECOMP_FUNC void baspin_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800254: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800258: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080025C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800260: lw          $v0, 0x118($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X118);
    // 0x80800264: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800268: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080026C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80800270: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800274: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80800278: bgez        $t6, L_80800290
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080027C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800290;
    }
    // 0x8080027C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800280: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800284: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800288: nop

    // 0x8080028C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80800290:
    // 0x80800290: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800294: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800298: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080029C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x808002A8: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x808002AC: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x808002B0: jal         0x80085300
    // 0x808002B4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    _batimer_get(rdram, ctx);
        goto after_0;
    // 0x808002B4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808002B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808002BC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808002C4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x808002C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808002CC: jal         0x800F10B4
    // 0x808002D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808002D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x808002D4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808002D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808002DC: nop

    // 0x808002E0: mul.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808002E4: jal         0x80013970
    // 0x808002E8: nop

    func_80013970(rdram, ctx);
        goto after_2;
    // 0x808002E8: nop

    after_2:
    // 0x808002EC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808002F8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808002FC: jal         0x8009328C
    // 0x80800300: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_8009328C(rdram, ctx);
        goto after_3;
    // 0x80800300: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x80800304: lw          $t7, 0x118($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X118);
    // 0x80800308: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080030C: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80800310: bnel        $t8, $at, L_80800340
    if (ctx->r24 != ctx->r1) {
        // 0x80800314: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800340;
    }
    goto skip_0;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800318: jal         0x80084C98
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800320: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800324: bne         $v0, $at, L_8080033C
    if (ctx->r2 != ctx->r1) {
        // 0x80800328: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080033C;
    }
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: jal         0x8009C914
    // 0x80800330: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    yaw_setIdeal(rdram, ctx);
        goto after_5;
    // 0x80800330: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800334: jal         0x8009C974
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_6;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_8080033C:
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800340:
    // 0x80800340: jal         0x800852F0
    // 0x80800344: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _batimer_decrement(rdram, ctx);
        goto after_7;
    // 0x80800344: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_7:
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: jal         0x8008CB10
    // 0x80800350: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x80800350: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_8:
    // 0x80800354: beql        $v0, $zero, L_80800368
    if (ctx->r2 == 0) {
        // 0x80800358: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800368;
    }
    goto skip_1;
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080035C: jal         0x800951B4
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_9;
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800368:
    // 0x80800368: jal         0x80085300
    // 0x8080036C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _batimer_get(rdram, ctx);
        goto after_10;
    // 0x8080036C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_10:
    // 0x80800370: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800374: nop

    // 0x80800378: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8080037C: nop

    // 0x80800380: bc1fl       L_808003A4
    if (!c1cs) {
        // 0x80800384: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808003A4;
    }
    goto skip_2;
    // 0x80800384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800388: jal         0x8008CAEC
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_11;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800390: beql        $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x80800394: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808003A4;
    }
    goto skip_3;
    // 0x80800394: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800398: b           L_808003A4
    // 0x8080039C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808003A4;
    // 0x8080039C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x808003A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A4:
    // 0x808003A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003B0: jr          $ra
    // 0x808003B4: nop

    return;
    // 0x808003B4: nop

    // 0x808003B8: nop

    // 0x808003BC: nop

;}
RECOMP_FUNC void bsbswim_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D50: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801D54: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1F98) << 16);
    // 0x80801D58: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801D5C: jr          $ra
    // 0x80801D60: lw          $v0, 0x1F98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1F98));
    return;
    // 0x80801D60: lw          $v0, 0x1F98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1F98));
    // 0x80801D64: nop

    // 0x80801D68: nop

    // 0x80801D6C: nop

;}
RECOMP_FUNC void func_80107B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107B78: jal         0x80106F30
    // 0x80107B7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106F30(rdram, ctx);
        goto after_0;
    // 0x80107B7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80107B80: bne         $v0, $zero, L_80107B90
    if (ctx->r2 != 0) {
        // 0x80107B84: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80107B90;
    }
    // 0x80107B84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80107B88: b           L_80107BA0
    // 0x80107B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80107BA0;
    // 0x80107B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80107B90:
    // 0x80107B90: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80107B94: jal         0x800EE88C
    // 0x80107B98: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x80107B98: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    after_1:
    // 0x80107B9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80107BA0:
    // 0x80107BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107BA8: jr          $ra
    // 0x80107BAC: nop

    return;
    // 0x80107BAC: nop

;}
RECOMP_FUNC void func_8080082C_chbadshad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080082C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800834: lw          $a1, 0x40($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X40);
    // 0x80800838: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080083C: beq         $a1, $zero, L_80800854
    if (ctx->r5 == 0) {
        // 0x80800840: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800854;
    }
    // 0x80800840: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800844: jal         0x80106790
    // 0x80800848: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800848: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080084C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800850: sw          $zero, 0x40($v0)
    MEM_W(0X40, ctx->r2) = 0;
L_80800854:
    // 0x80800854: jal         0x800FFAB0
    // 0x80800858: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800858: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8080085C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800864: jr          $ra
    // 0x80800868: nop

    return;
    // 0x80800868: nop

;}
RECOMP_FUNC void func_8080111C_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080111C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801120: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801124: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801128: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080112C: jal         0x8008CABC
    // 0x80801130: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801130: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80801134: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801138: jal         0x8008AF24
    // 0x8080113C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x8080113C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801140: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80801144: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801148: jal         0x8008B1C8
    // 0x8080114C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_2;
    // 0x8080114C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80801150: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801154: jal         0x8008AED4
    // 0x80801158: addiu       $a1, $zero, 0x288
    ctx->r5 = ADD32(0, 0X288);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80801158: addiu       $a1, $zero, 0x288
    ctx->r5 = ADD32(0, 0X288);
    after_3:
    // 0x8080115C: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
    // 0x80801160: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80801164: jal         0x8008B1BC
    // 0x80801168: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80801168: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8080116C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801170: jal         0x8008B134
    // 0x80801174: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80801174: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80801178: jal         0x8008B064
    // 0x8080117C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x8080117C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80801180: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80801184: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080118C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801190: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801194: jal         0x8009FFD8
    // 0x80801198: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_7;
    // 0x80801198: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x8080119C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011A0: jal         0x800A0CF4
    // 0x808011A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_8;
    // 0x808011A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808011A8: jal         0x80800128
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800128_bskazfly(rdram, ctx);
        goto after_9;
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808011B0: jal         0x80095A40
    // 0x808011B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_10;
    // 0x808011B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011BC: jal         0x800961AC
    // 0x808011C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_11;
    // 0x808011C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808011C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C8: jal         0x8009C4CC
    // 0x808011CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_12;
    // 0x808011CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_12:
    // 0x808011D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011D4: jal         0x8009BF5C
    // 0x808011D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_13;
    // 0x808011D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_13:
    // 0x808011DC: jal         0x8009BC6C
    // 0x808011E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_14;
    // 0x808011E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808011E4: jal         0x8009BC90
    // 0x808011E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_15;
    // 0x808011E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808011EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011F0: jal         0x80093360
    // 0x808011F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_16;
    // 0x808011F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_16:
    // 0x808011F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011FC: addiu       $a1, $zero, 0x442F
    ctx->r5 = ADD32(0, 0X442F);
    // 0x80801200: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801204: jal         0x8009DF94
    // 0x80801208: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF94(rdram, ctx);
        goto after_17;
    // 0x80801208: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_17:
    // 0x8080120C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801210: addiu       $a1, $zero, 0x444
    ctx->r5 = ADD32(0, 0X444);
    // 0x80801214: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801218: jal         0x8009DB04
    // 0x8080121C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_18;
    // 0x8080121C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_18:
    // 0x80801220: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(236, 0X1C00) << 16);
    // 0x80801224: lwc1        $f4, 0x1C00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(236, 0X1C00));
    // 0x80801228: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x8080122C: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x80801230: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80801234: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801238: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080123C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801240: jr          $ra
    // 0x80801244: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801244: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _idwibble_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E90: syscall     745
    recomp_syscall_handler(rdram, ctx, 0x80088E90);
    return;
    // 0x80088E94: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800758_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800758: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080075C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800760: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800764: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80800768: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8080076C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80800770: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800774: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800778: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080077C: beq         $a0, $s1, L_808007A8
    if (ctx->r4 == ctx->r17) {
        // 0x80800780: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808007A8;
    }
    // 0x80800780: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800784: addiu       $s2, $sp, 0x2A
    ctx->r18 = ADD32(ctx->r29, 0X2A);
L_80800788:
    // 0x80800788: jal         0x800A5800
    // 0x8080078C: sh          $a0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r4;
    func_800A5800(rdram, ctx);
        goto after_0;
    // 0x8080078C: sh          $a0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800790: jal         0x80085600
    // 0x80800794: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _cadbfunc_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800794: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80800798: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    // 0x8080079C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808007A0: bne         $a0, $s1, L_80800788
    if (ctx->r4 != ctx->r17) {
        // 0x808007A4: nop
    
            goto L_80800788;
    }
    // 0x808007A4: nop

L_808007A8:
    // 0x808007A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007AC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808007B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808007B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808007BC: jr          $ra
    // 0x808007C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808007C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chanim_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080028C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800290: jal         0x80104248
    // 0x80800294: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80800294: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800298: beq         $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x8080029C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002BC;
    }
    // 0x8080029C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002A0: jal         0x80100094
    // 0x808002A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808002A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808002A8: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x808002AC: beql        $t6, $zero, L_808002C0
    if (ctx->r14 == 0) {
        // 0x808002B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002C0;
    }
    goto skip_0;
    // 0x808002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002B4: jal         0x800DF758
    // 0x808002B8: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    func_800DF758(rdram, ctx);
        goto after_2;
    // 0x808002B8: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    after_2:
L_808002BC:
    // 0x808002BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002C0:
    // 0x808002C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

;}
RECOMP_FUNC void func_80801864_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801868: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080186C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801870: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801874: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x80801878: jal         0x800DA564
    // 0x8080187C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x8080187C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80801880: blez        $v0, L_8080189C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801884: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080189C;
    }
    // 0x80801884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801888: jal         0x80102424
    // 0x8080188C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080188C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80801890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801894: jal         0x80103110
    // 0x80801898: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x80801898: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8080189C:
    // 0x8080189C: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x808018A0: jal         0x800DA564
    // 0x808018A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_3;
    // 0x808018A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808018A8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x808018AC: bne         $at, $zero, L_808018C0
    if (ctx->r1 != 0) {
        // 0x808018B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808018C0;
    }
    // 0x808018B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018B4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808018B8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808018BC: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_808018C0:
    // 0x808018C0: jal         0x8010A800
    // 0x808018C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_4;
    // 0x808018C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808018C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808018CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808018D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808018D4: jr          $ra
    // 0x808018D8: nop

    return;
    // 0x808018D8: nop

;}
RECOMP_FUNC void func_80801054_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801054: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80801058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080105C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801064: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80801068: jal         0x80101E14
    // 0x8080106C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x8080106C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801070: beq         $v0, $zero, L_80801080
    if (ctx->r2 == 0) {
        // 0x80801074: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801080;
    }
    // 0x80801074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801078: jal         0x80801090
    // 0x8080107C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80801090_chbadjinjo(rdram, ctx);
        goto after_1;
    // 0x8080107C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80801080:
    // 0x80801080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801088: jr          $ra
    // 0x8080108C: nop

    return;
    // 0x8080108C: nop

;}
RECOMP_FUNC void func_80800EC8_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800ECC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800ED0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800ED4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800ED8: jal         0x800C6DA0
    // 0x80800EDC: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    func_800C6DA0(rdram, ctx);
        goto after_0;
    // 0x80800EDC: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_0:
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80800EE8: jal         0x8008CCBC
    // 0x80800EEC: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80800EEC: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_1:
    // 0x80800EF0: jal         0x80800000
    // 0x80800EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbswim(rdram, ctx);
        goto after_2;
    // 0x80800EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EFC: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800F00: jal         0x8009C99C
    // 0x80800F04: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80800F04: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_3:
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F0C: jal         0x8009B94C
    // 0x80800F10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_4;
    // 0x80800F10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800F14: jal         0x80800030
    // 0x80800F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_5;
    // 0x80800F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F20: jal         0x800852B8
    // 0x80800F24: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800F24: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F2C: jal         0x800852A8
    // 0x80800F30: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    _baswim_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80800F30: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_7:
    // 0x80800F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F38: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800F3C: jal         0x8009BFE4
    // 0x80800F40: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_8;
    // 0x80800F40: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    after_8:
    // 0x80800F44: jal         0x8009D874
    // 0x80800F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_9;
    // 0x80800F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800F4C: sb          $zero, 0x164($s0)
    MEM_B(0X164, ctx->r16) = 0;
    // 0x80800F50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F5C: jr          $ra
    // 0x80800F60: nop

    return;
    // 0x80800F60: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080179C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808017A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808017A4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808017A8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808017AC: jal         0x80802484
    // 0x808017B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808017B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808017B4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x808017B8: jal         0x800A4CA8
    // 0x808017BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_1;
    // 0x808017BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808017C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808017C4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808017C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808017CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808017D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808017D4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808017D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808017DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808017E0: jal         0x80111590
    // 0x808017E4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80111590(rdram, ctx);
        goto after_2;
    // 0x808017E4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x808017E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017EC: jal         0x80110730
    // 0x808017F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80110730(rdram, ctx);
        goto after_3;
    // 0x808017F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808017F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808017F8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808017FC: jal         0x808015C0
    // 0x80801800: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_808015C0_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80801800: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80801804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801808: jal         0x800893F8
    // 0x8080180C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _ncba1p_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x8080180C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x80801810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801814: jal         0x80089400
    // 0x80801818: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _ncba1p_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80801818: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x8080181C: jal         0x800A3404
    // 0x80801820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A3404(rdram, ctx);
        goto after_7;
    // 0x80801820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80801824: beq         $v0, $zero, L_80801840
    if (ctx->r2 == 0) {
        // 0x80801828: nop
    
            goto L_80801840;
    }
    // 0x80801828: nop

    // 0x8080182C: jal         0x800893D8
    // 0x80801830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _ncba1p_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80801830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801838: jal         0x800893E8
    // 0x8080183C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncba1p_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x8080183C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
L_80801840:
    // 0x80801840: jal         0x800A4C88
    // 0x80801844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A4C88(rdram, ctx);
        goto after_10;
    // 0x80801844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80801848: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8080184C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801850: jal         0x8010FD60
    // 0x80801854: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8010FD60(rdram, ctx);
        goto after_11;
    // 0x80801854: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_11:
    // 0x80801858: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8080185C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801860: jal         0x80801668
    // 0x80801864: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    func_80801668_bsfirstp(rdram, ctx);
        goto after_12;
    // 0x80801864: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    after_12:
    // 0x80801868: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080186C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801870: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801874: jr          $ra
    // 0x80801878: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801878: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void bstrexlarge_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B18: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B1C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X19C0) << 16);
    // 0x80800B20: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B24: jr          $ra
    // 0x80800B28: lw          $v0, 0x19C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X19C0));
    return;
    // 0x80800B28: lw          $v0, 0x19C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X19C0));
;}
RECOMP_FUNC void chtoxicroombits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800404: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2308, 0XFB0) << 16);
    // 0x80800408: jr          $ra
    // 0x8080040C: addiu       $v0, $v0, 0xFB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2308, 0XFB0));
    return;
    // 0x8080040C: addiu       $v0, $v0, 0xFB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2308, 0XFB0));
;}
RECOMP_FUNC void _capod_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856E8: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856E8);
    return;
    // 0x800856EC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void suegg_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800D10: jal         0x80100094
    // 0x80800D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D18: lw          $t6, 0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3C);
    // 0x80800D1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800D20: lui         $a1, 0x43E1
    ctx->r5 = S32(0X43E1 << 16);
    // 0x80800D24: beq         $t6, $zero, L_80800D78
    if (ctx->r14 == 0) {
        // 0x80800D28: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80800D78;
    }
    // 0x80800D28: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800D2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800D30: jal         0x800E3E8C
    // 0x80800D34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800E3E8C(rdram, ctx);
        goto after_1;
    // 0x80800D34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800D38: bne         $v0, $zero, L_80800D58
    if (ctx->r2 != 0) {
        // 0x80800D3C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80800D58;
    }
    // 0x80800D3C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800D40: addiu       $a0, $v1, 0x40
    ctx->r4 = ADD32(ctx->r3, 0X40);
    // 0x80800D44: lui         $a1, 0x43E1
    ctx->r5 = S32(0X43E1 << 16);
    // 0x80800D48: jal         0x800E3E8C
    // 0x80800D4C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800E3E8C(rdram, ctx);
        goto after_2;
    // 0x80800D4C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800D50: beq         $v0, $zero, L_80800D78
    if (ctx->r2 == 0) {
        // 0x80800D54: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80800D78;
    }
    // 0x80800D54: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80800D58:
    // 0x80800D58: lw          $a0, 0x3C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X3C);
    // 0x80800D5C: addiu       $t7, $v1, 0x40
    ctx->r15 = ADD32(ctx->r3, 0X40);
    // 0x80800D60: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80800D64: jal         0x800C8CB8
    // 0x80800D68: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C8CB8(rdram, ctx);
        goto after_3;
    // 0x80800D68: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800D6C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D70: jal         0x800EE7F8
    // 0x80800D74: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800D74: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
L_80800D78:
    // 0x80800D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800D80: jr          $ra
    // 0x80800D84: nop

    return;
    // 0x80800D84: nop

;}
RECOMP_FUNC void _bamoveledge_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E60: syscall     139
    recomp_syscall_handler(rdram, ctx, 0x80084E60);
    return;
    // 0x80084E64: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsstatue_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BB8: syscall     91
    recomp_syscall_handler(rdram, ctx, 0x80083BB8);
    return;
    // 0x80083BBC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80114D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114D90: jr          $ra
    // 0x80114D94: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80114D94: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bsbtrot_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800EB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800EB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800EBC: jal         0x80800DC4
    // 0x80800EC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800DC4_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80800EC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800EC4: lui         $a2, 0x3F07
    ctx->r6 = S32(0X3F07 << 16);
    // 0x80800EC8: ori         $a2, $a2, 0xAE14
    ctx->r6 = ctx->r6 | 0XAE14;
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED0: jal         0x8008CB3C
    // 0x80800ED4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800ED4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800ED8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800EDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800EEC: jal         0x8009FFD8
    // 0x80800EF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800EF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800EF4: jal         0x80800538
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_3;
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800EFC: jal         0x80800DF4
    // 0x80800F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DF4_bsbtrot(rdram, ctx);
        goto after_4;
    // 0x80800F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800F04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F10: jr          $ra
    // 0x80800F14: nop

    return;
    // 0x80800F14: nop

;}
RECOMP_FUNC void func_800C401C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C401C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C4020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C4024: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x800C4028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C402C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C4030: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C4034: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C4038: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C403C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800C4040: jal         0x800C1070
    // 0x800C4044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C1070(rdram, ctx);
        goto after_0;
    // 0x800C4044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C4048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C404C: jal         0x800EEAD4
    // 0x800C4050: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800EEAD4(rdram, ctx);
        goto after_1;
    // 0x800C4050: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x800C4054: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C4058: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800C405C: nop

    // 0x800C4060: bc1tl       L_800C40F4
    if (c1cs) {
        // 0x800C4064: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C40F4;
    }
    goto skip_0;
    // 0x800C4064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800C4068: jal         0x800C2E04
    // 0x800C406C: nop

    func_800C2E04(rdram, ctx);
        goto after_2;
    // 0x800C406C: nop

    after_2:
    // 0x800C4070: beq         $v0, $zero, L_800C40F0
    if (ctx->r2 == 0) {
        // 0x800C4074: andi        $s0, $v0, 0xFF
        ctx->r16 = ctx->r2 & 0XFF;
            goto L_800C40F0;
    }
    // 0x800C4074: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800C4078: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C407C: jal         0x800C3418
    // 0x800C4080: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800C3418(rdram, ctx);
        goto after_3;
    // 0x800C4080: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x800C4084: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C4088: jal         0x800C301C
    // 0x800C408C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800C301C(rdram, ctx);
        goto after_4;
    // 0x800C408C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x800C4090: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C4094: jal         0x800C3058
    // 0x800C4098: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800C3058(rdram, ctx);
        goto after_5;
    // 0x800C4098: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x800C409C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C40A0: jal         0x800C31DC
    // 0x800C40A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800C31DC(rdram, ctx);
        goto after_6;
    // 0x800C40A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x800C40A8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C40AC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800C40B0: jal         0x800C3584
    // 0x800C40B4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_800C3584(rdram, ctx);
        goto after_7;
    // 0x800C40B4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_7:
    // 0x800C40B8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C40BC: jal         0x800C35E8
    // 0x800C40C0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800C35E8(rdram, ctx);
        goto after_8;
    // 0x800C40C0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_8:
    // 0x800C40C4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C40C8: jal         0x800C330C
    // 0x800C40CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C330C(rdram, ctx);
        goto after_9;
    // 0x800C40CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x800C40D0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C40D4: jal         0x800C33DC
    // 0x800C40D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C33DC(rdram, ctx);
        goto after_10;
    // 0x800C40D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x800C40DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C40E0: jal         0x800C36F4
    // 0x800C40E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C36F4(rdram, ctx);
        goto after_11;
    // 0x800C40E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x800C40E8: jal         0x800C3BDC
    // 0x800C40EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C3BDC(rdram, ctx);
        goto after_12;
    // 0x800C40EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_12:
L_800C40F0:
    // 0x800C40F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C40F4:
    // 0x800C40F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C40F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C40FC: jr          $ra
    // 0x800C4100: nop

    return;
    // 0x800C4100: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089578: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089578);
    return;
    // 0x8008957C: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void bskazstilt_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DF8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800DFC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(292, 0X1240) << 16);
    // 0x80800E00: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800E04: jr          $ra
    // 0x80800E08: lw          $v0, 0x1240($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1240));
    return;
    // 0x80800E08: lw          $v0, 0x1240($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1240));
;}
RECOMP_FUNC void _bssplitup_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AB8: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AB8);
    return;
    // 0x80083ABC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800368_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080036C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800370: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800374: jal         0x8008DF8C
    // 0x80800378: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_8008DF8C(rdram, ctx);
        goto after_0;
    // 0x80800378: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x8080037C: beq         $v0, $zero, L_8080039C
    if (ctx->r2 == 0) {
        // 0x80800380: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080039C;
    }
    // 0x80800380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800384: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080038C: jal         0x8009D2F0
    // 0x80800390: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_1;
    // 0x80800390: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_1:
    // 0x80800394: b           L_808003B4
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003B4;
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080039C:
    // 0x8080039C: jal         0x8009BF5C
    // 0x808003A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_2;
    // 0x808003A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808003A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003A8: jal         0x8009C4CC
    // 0x808003AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_3;
    // 0x808003AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808003B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B4:
    // 0x808003B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003B8: jr          $ra
    // 0x808003BC: nop

    return;
    // 0x808003BC: nop

;}
RECOMP_FUNC void chmole_maya_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1596, 0X210) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0x210
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1596, 0X210));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0x210
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1596, 0X210));
;}
