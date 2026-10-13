#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801218_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080121C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801220: jal         0x80800130
    // 0x80801224: nop

    func_80800130_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80801224: nop

    after_0:
    // 0x80801228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080122C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801230: jr          $ra
    // 0x80801234: nop

    return;
    // 0x80801234: nop

;}
RECOMP_FUNC void func_80802A50_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802A54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802A58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802A5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802A60: jal         0x80100094
    // 0x80802A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802A68: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80802A6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802A70: jal         0x80106790
    // 0x80802A74: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80802A74: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    after_1:
    // 0x80802A78: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    // 0x80802A7C: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80802A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802A84: beql        $a1, $at, L_80802AE8
    if (ctx->r5 == ctx->r1) {
        // 0x80802A88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802AE8;
    }
    goto skip_0;
    // 0x80802A88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802A8C: jal         0x80089AC8
    // 0x80802A90: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80802A90: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80802A94: beq         $v0, $zero, L_80802AC4
    if (ctx->r2 == 0) {
        // 0x80802A98: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80802AC4;
    }
    // 0x80802A98: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802A9C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80802AA0: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
    // 0x80802AA4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80802AA8: jal         0x800F4F98
    // 0x80802AAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F4F98(rdram, ctx);
        goto after_3;
    // 0x80802AAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80802AB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802AB4: jal         0x80089AF0
    // 0x80802AB8: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80802AB8: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_4:
    // 0x80802ABC: b           L_80802AD4
    // 0x80802AC0: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
        goto L_80802AD4;
    // 0x80802AC0: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
L_80802AC4:
    // 0x80802AC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802AC8: jal         0x80089AF0
    // 0x80802ACC: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80802ACC: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_5:
    // 0x80802AD0: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
L_80802AD4:
    // 0x80802AD4: sb          $t8, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r24;
    // 0x80802AD8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BE4) << 16);
    // 0x80802ADC: lwc1        $f4, 0x4BE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BE4));
    // 0x80802AE0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80802AE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802AE8:
    // 0x80802AE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802AEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802AF0: jr          $ra
    // 0x80802AF4: nop

    return;
    // 0x80802AF4: nop

;}
RECOMP_FUNC void func_800F8EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8EE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8EEC: jal         0x800F5410
    // 0x800F8EF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F5410(rdram, ctx);
        goto after_0;
    // 0x800F8EF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F8EF4: jal         0x800F88A0
    // 0x800F8EF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F88A0(rdram, ctx);
        goto after_1;
    // 0x800F8EF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800F8EFC: beq         $v0, $zero, L_800F8F14
    if (ctx->r2 == 0) {
        // 0x800F8F00: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800F8F14;
    }
    // 0x800F8F00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F8F04: jal         0x800F8914
    // 0x800F8F08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F8914(rdram, ctx);
        goto after_2;
    // 0x800F8F08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800F8F0C: b           L_800F8F30
    // 0x800F8F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F8F30;
    // 0x800F8F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F8F14:
    // 0x800F8F14: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8F18: jal         0x800B2974
    // 0x800F8F1C: addiu       $a0, $a0, 0x54F0
    ctx->r4 = ADD32(ctx->r4, 0X54F0);
    vector_push_back(rdram, ctx);
        goto after_3;
    // 0x800F8F1C: addiu       $a0, $a0, 0x54F0
    ctx->r4 = ADD32(ctx->r4, 0X54F0);
    after_3:
    // 0x800F8F20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F8F24: jal         0x800F8914
    // 0x800F8F28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F8914(rdram, ctx);
        goto after_4;
    // 0x800F8F28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x800F8F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F8F30:
    // 0x800F8F30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8F34: jr          $ra
    // 0x800F8F38: nop

    return;
    // 0x800F8F38: nop

;}
RECOMP_FUNC void func_80090B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090B98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090BA0: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80090BA4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80090BA8: sw          $v1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r3;
    // 0x80090BAC: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80090BB0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80090BB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80090BB8: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80090BBC: sb          $zero, 0x18($t8)
    MEM_B(0X18, ctx->r24) = 0;
    // 0x80090BC0: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x80090BC4: sw          $v1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r3;
    // 0x80090BC8: lw          $a1, 0x2C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2C);
    // 0x80090BCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090BD0: jal         0x8009C128
    // 0x80090BD4: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80090BD4: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x80090BD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80090BDC: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x80090BE0: sb          $zero, 0x1A($t0)
    MEM_B(0X1A, ctx->r8) = 0;
    // 0x80090BE4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80090BE8: lbu         $t1, 0x1A($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1A);
    // 0x80090BEC: sb          $t1, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r9;
    // 0x80090BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090BF8: jr          $ra
    // 0x80090BFC: nop

    return;
    // 0x80090BFC: nop

;}
RECOMP_FUNC void func_800C5FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C5FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5FD4: lbu         $t6, 0x9C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9C);
    // 0x800C5FD8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C5FDC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800C5FE0: beq         $t6, $zero, L_800C5FEC
    if (ctx->r14 == 0) {
        // 0x800C5FE4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800C5FEC;
    }
    // 0x800C5FE4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C5FE8: lwc1        $f12, 0x98($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X98);
L_800C5FEC:
    // 0x800C5FEC: beq         $a1, $zero, L_800C6010
    if (ctx->r5 == 0) {
        // 0x800C5FF0: addiu       $a0, $a3, 0x10
        ctx->r4 = ADD32(ctx->r7, 0X10);
            goto L_800C6010;
    }
    // 0x800C5FF0: addiu       $a0, $a3, 0x10
    ctx->r4 = ADD32(ctx->r7, 0X10);
    // 0x800C5FF4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800C5FF8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800C5FFC: jal         0x800FB508
    // 0x800C6000: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_800FB508(rdram, ctx);
        goto after_0;
    // 0x800C6000: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800C6004: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800C6008: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800C600C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
L_800C6010:
    // 0x800C6010: beq         $a1, $zero, L_800C6020
    if (ctx->r5 == 0) {
        // 0x800C6014: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800C6020;
    }
    // 0x800C6014: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C6018: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800C601C: sw          $t7, 0x80($a3)
    MEM_W(0X80, ctx->r7) = ctx->r15;
L_800C6020:
    // 0x800C6020: sb          $t8, 0x8F($a3)
    MEM_B(0X8F, ctx->r7) = ctx->r24;
    // 0x800C6024: swc1        $f12, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f12.u32l;
    // 0x800C6028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C602C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C6030: jr          $ra
    // 0x800C6034: nop

    return;
    // 0x800C6034: nop

;}
RECOMP_FUNC void _sulights_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8C8: syscall     854
    recomp_syscall_handler(rdram, ctx, 0x8008A8C8);
    return;
    // 0x8008A8CC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800AB0_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800ABC: jal         0x80100094
    // 0x80800AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800AC8: jal         0x808007F0
    // 0x80800ACC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808007F0_chhandcart(rdram, ctx);
        goto after_1;
    // 0x80800ACC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800AD0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AD4: lbu         $t7, 0x8F4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8F4);
    // 0x80800AD8: beql        $t7, $zero, L_80800AF4
    if (ctx->r15 == 0) {
        // 0x80800ADC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800AF4;
    }
    goto skip_0;
    // 0x80800ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800AE0: jal         0x800856B8
    // 0x80800AE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800AE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800AE8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AEC: sb          $zero, 0x8F4($t8)
    MEM_B(0X8F4, ctx->r24) = 0;
    // 0x80800AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AF4:
    // 0x80800AF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AF8: jr          $ra
    // 0x80800AFC: nop

    return;
    // 0x80800AFC: nop

;}
RECOMP_FUNC void _subaddiesect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F40: syscall     817
    recomp_syscall_handler(rdram, ctx, 0x80089F40);
    return;
    // 0x80089F44: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800778_chmricecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080077C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800780: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1224, 0X9B8) << 16);
    // 0x80800784: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1224, 0X8B0) << 16);
    // 0x80800788: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8080078C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800790: addiu       $a3, $a3, 0x8B0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1224, 0X8B0));
    // 0x80800794: addiu       $a2, $a2, 0x9B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1224, 0X9B8));
    // 0x80800798: jal         0x8008A1F0
    // 0x8080079C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x8080079C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808007A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007A8: jr          $ra
    // 0x808007AC: nop

    return;
    // 0x808007AC: nop

;}
RECOMP_FUNC void _bskazdie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833C0: syscall     58
    recomp_syscall_handler(rdram, ctx, 0x800833C0);
    return;
    // 0x800833C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800144_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080014C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800150: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800154: jal         0x80800014
    // 0x80800158: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_0;
    // 0x80800158: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080015C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800164: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800168: jal         0x80800098
    // 0x8080016C: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    func_80800098_chtrashcangame(rdram, ctx);
        goto after_1;
    // 0x8080016C: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    after_1:
    // 0x80800170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void func_800BF6B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF6B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BF6BC: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    // 0x800BF6C0: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x800BF6C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BF6C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF6CC: beq         $t6, $zero, L_800BF6F4
    if (ctx->r14 == 0) {
        // 0x800BF6D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BF6F4;
    }
    // 0x800BF6D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF6D4: jal         0x80087FC0
    // 0x800BF6D8: nop

    _gcmapsects_entrypoint_24(rdram, ctx);
        goto after_0;
    // 0x800BF6D8: nop

    after_0:
    // 0x800BF6DC: beq         $v0, $zero, L_800BF6EC
    if (ctx->r2 == 0) {
        // 0x800BF6E0: nop
    
            goto L_800BF6EC;
    }
    // 0x800BF6E0: nop

    // 0x800BF6E4: b           L_800BF6F4
    // 0x800BF6E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800BF6F4;
    // 0x800BF6E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800BF6EC:
    // 0x800BF6EC: b           L_800BF6F4
    // 0x800BF6F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800BF6F4;
    // 0x800BF6F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800BF6F4:
    // 0x800BF6F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF6F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BF6FC: jr          $ra
    // 0x800BF700: nop

    return;
    // 0x800BF700: nop

;}
RECOMP_FUNC void func_80800294_bsbflap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800298: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080029C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002A0: jal         0x8008CABC
    // 0x808002A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808002A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002A8: lui         $a1, 0x3DA3
    ctx->r5 = S32(0X3DA3 << 16);
    // 0x808002AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808002B0: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x808002B4: jal         0x80800248
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800248_bsbflap(rdram, ctx);
        goto after_1;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002BC: beq         $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x808002C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002D8;
    }
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: lui         $a2, 0x3F9E
    ctx->r6 = S32(0X3F9E << 16);
    // 0x808002C8: ori         $a2, $a2, 0xB852
    ctx->r6 = ctx->r6 | 0XB852;
    // 0x808002CC: addiu       $a1, $zero, 0x4435
    ctx->r5 = ADD32(0, 0X4435);
    // 0x808002D0: jal         0x8009DB04
    // 0x808002D4: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DB04(rdram, ctx);
        goto after_2;
    // 0x808002D4: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_2:
L_808002D8:
    // 0x808002D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X71C) << 16);
    // 0x808002DC: lwc1        $f4, 0x71C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X71C));
    // 0x808002E0: lwc1        $f6, 0x170($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X170);
    // 0x808002E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808002E8: lui         $a1, 0x3F11
    ctx->r5 = S32(0X3F11 << 16);
    // 0x808002EC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808002F0: nop

    // 0x808002F4: bc1f        L_8080031C
    if (!c1cs) {
        // 0x808002F8: nop
    
            goto L_8080031C;
    }
    // 0x808002F8: nop

    // 0x808002FC: jal         0x8008B348
    // 0x80800300: ori         $a1, $a1, 0xDE6A
    ctx->r5 = ctx->r5 | 0XDE6A;
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800300: ori         $a1, $a1, 0xDE6A
    ctx->r5 = ctx->r5 | 0XDE6A;
    after_3:
    // 0x80800304: beq         $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x80800308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080031C;
    }
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: addiu       $a1, $zero, 0x4431
    ctx->r5 = ADD32(0, 0X4431);
    // 0x80800310: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800314: jal         0x8009DF18
    // 0x80800318: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF18(rdram, ctx);
        goto after_4;
    // 0x80800318: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_4:
L_8080031C:
    // 0x8080031C: jal         0x8008B264
    // 0x80800320: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_getIndex(rdram, ctx);
        goto after_5;
    // 0x80800320: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80800324: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80800328: bne         $v0, $at, L_80800368
    if (ctx->r2 != ctx->r1) {
        // 0x8080032C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800368;
    }
    // 0x8080032C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800330: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x80800334: jal         0x8008B348
    // 0x80800338: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    anctrl_isAt(rdram, ctx);
        goto after_6;
    // 0x80800338: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_6:
    // 0x8080033C: beq         $v0, $zero, L_80800368
    if (ctx->r2 == 0) {
        // 0x80800340: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(90, 0X720) << 16);
            goto L_80800368;
    }
    // 0x80800340: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X720) << 16);
    // 0x80800344: lwc1        $f12, 0x720($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X720));
    // 0x80800348: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X724) << 16);
    // 0x8080034C: jal         0x800DC178
    // 0x80800350: lwc1        $f14, 0x724($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X724));
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800350: lwc1        $f14, 0x724($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X724));
    after_7:
    // 0x80800354: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80800360: jal         0x8009DF94
    // 0x80800364: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF94(rdram, ctx);
        goto after_8;
    // 0x80800364: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_8:
L_80800368:
    // 0x80800368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080036C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800374: jr          $ra
    // 0x80800378: nop

    return;
    // 0x80800378: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800428: addiu       $a0, $zero, 0xD50
    ctx->r4 = ADD32(0, 0XD50);
    // 0x8080042C: jal         0x800DA564
    // 0x80800430: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800430: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080043C: jr          $ra
    // 0x80800440: nop

    return;
    // 0x80800440: nop

;}
RECOMP_FUNC void func_800BD64C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD64C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800BD650: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800BD654: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BD658: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BD65C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800BD660: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BD664: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800BD668: addiu       $t0, $t0, -0x7BE4
    ctx->r8 = ADD32(ctx->r8, -0X7BE4);
    // 0x800BD66C: addiu       $a3, $a3, -0x7BF0
    ctx->r7 = ADD32(ctx->r7, -0X7BF0);
    // 0x800BD670: addiu       $a1, $a1, -0x7BF0
    ctx->r5 = ADD32(ctx->r5, -0X7BF0);
    // 0x800BD674: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_800BD678:
    // 0x800BD678: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BD67C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BD680: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800BD684: nop

    // 0x800BD688: bc1fl       L_800BD6AC
    if (!c1cs) {
        // 0x800BD68C: lwc1        $f10, 0x40($a1)
        ctx->f10.u32l = MEM_W(ctx->r5, 0X40);
            goto L_800BD6AC;
    }
    goto skip_0;
    // 0x800BD68C: lwc1        $f10, 0x40($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X40);
    skip_0:
    // 0x800BD690: lwc1        $f4, 0x40($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X40);
    // 0x800BD694: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800BD698: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800BD69C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800BD6A0: b           L_800BD6C4
    // 0x800BD6A4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_800BD6C4;
    // 0x800BD6A4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800BD6A8: lwc1        $f10, 0x40($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X40);
L_800BD6AC:
    // 0x800BD6AC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800BD6B0: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800BD6B4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BD6B8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800BD6BC: nop

    // 0x800BD6C0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_800BD6C4:
    // 0x800BD6C4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800BD6C8: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x800BD6CC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BD6D0: beql        $at, $zero, L_800BD6E4
    if (ctx->r1 == 0) {
        // 0x800BD6D4: lw          $a0, 0x10($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X10);
            goto L_800BD6E4;
    }
    goto skip_1;
    // 0x800BD6D4: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    skip_1:
    // 0x800BD6D8: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x800BD6DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800BD6E0: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
L_800BD6E4:
    // 0x800BD6E4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800BD6E8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BD6EC: beq         $at, $zero, L_800BD6F8
    if (ctx->r1 == 0) {
        // 0x800BD6F0: nop
    
            goto L_800BD6F8;
    }
    // 0x800BD6F0: nop

    // 0x800BD6F4: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800BD6F8:
    // 0x800BD6F8: bne         $a3, $t0, L_800BD678
    if (ctx->r7 != ctx->r8) {
        // 0x800BD6FC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800BD678;
    }
    // 0x800BD6FC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800BD700: jr          $ra
    // 0x800BD704: nop

    return;
    // 0x800BD704: nop

;}
RECOMP_FUNC void func_80800000_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80800004: jr          $ra
    // 0x80800008: sw          $t6, 0x168($a0)
    MEM_W(0X168, ctx->r4) = ctx->r14;
    return;
    // 0x80800008: sw          $t6, 0x168($a0)
    MEM_W(0X168, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80800094_chgoldstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080009C: jal         0x80089848
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_80800000_chmumbopadstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_801154A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801154A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801154A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801154AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801154B0: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x801154B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801154B8: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801154BC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801154C0: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x801154C4: nop

    // 0x801154C8: bc1fl       L_80115544
    if (!c1cs) {
        // 0x801154CC: swc1        $f2, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
            goto L_80115544;
    }
    goto skip_0;
    // 0x801154CC: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    skip_0:
    // 0x801154D0: jal         0x80115484
    // 0x801154D4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80115484(rdram, ctx);
        goto after_0;
    // 0x801154D4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x801154D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801154DC: jal         0x801107F0
    // 0x801154E0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x801154E0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x801154E4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x801154E8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x801154EC: jal         0x800EFB24
    // 0x801154F0: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x801154F0: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x801154F4: jal         0x800EEF94
    // 0x801154F8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x801154F8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x801154FC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80115500: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80115504: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80115508: nop

    // 0x8011550C: bc1fl       L_80115524
    if (!c1cs) {
        // 0x80115510: lwc1        $f6, 0xC($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80115524;
    }
    goto skip_1;
    // 0x80115510: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    skip_1:
    // 0x80115514: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    // 0x80115518: b           L_80115548
    // 0x8011551C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80115548;
    // 0x8011551C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80115520: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
L_80115524:
    // 0x80115524: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80115528: nop

    // 0x8011552C: bc1fl       L_8011554C
    if (!c1cs) {
        // 0x80115530: lwc1        $f8, 0x18($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
            goto L_8011554C;
    }
    goto skip_2;
    // 0x80115530: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    skip_2:
    // 0x80115534: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x80115538: b           L_80115548
    // 0x8011553C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80115548;
    // 0x8011553C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80115540: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
L_80115544:
    // 0x80115544: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_80115548:
    // 0x80115548: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
L_8011554C:
    // 0x8011554C: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x80115550: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80115554: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80115558: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8011555C: jr          $ra
    // 0x80115560: nop

    return;
    // 0x80115560: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A148: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A148);
    return;
    // 0x8008A14C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800FECB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FECB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FECBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FECC0: jal         0x800FEC28
    // 0x800FECC4: nop

    func_800FEC28(rdram, ctx);
        goto after_0;
    // 0x800FECC4: nop

    after_0:
    // 0x800FECC8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FECCC: addiu       $t6, $t6, 0x5A10
    ctx->r14 = ADD32(ctx->r14, 0X5A10);
    // 0x800FECD0: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800FECD4: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x800FECD8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800FECDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800FECE0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800FECE4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x800FECE8: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
    // 0x800FECEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800FECF0:
    // 0x800FECF0: bnel        $v0, $v1, L_800FECF0
    if (ctx->r2 != ctx->r3) {
        // 0x800FECF4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800FECF0;
    }
    goto skip_0;
    // 0x800FECF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x800FECF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FECFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FED00: sw          $t9, 0x3E60($at)
    MEM_W(0X3E60, ctx->r1) = ctx->r25;
    // 0x800FED04: jr          $ra
    // 0x800FED08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FED08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80017864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017864: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80017868: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001786C: addiu       $a0, $a0, -0x5160
    ctx->r4 = ADD32(ctx->r4, -0X5160);
    // 0x80017870: addiu       $v1, $v1, -0x5180
    ctx->r3 = ADD32(ctx->r3, -0X5180);
    // 0x80017874: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80017878:
    // 0x80017878: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001787C: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80017880: bne         $at, $zero, L_80017878
    if (ctx->r1 != 0) {
        // 0x80017884: sb          $v0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r2;
            goto L_80017878;
    }
    // 0x80017884: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // 0x80017888: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001788C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80017890: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80017894: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80017898: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001789C: addiu       $t8, $t8, -0x5118
    ctx->r24 = ADD32(ctx->r24, -0X5118);
    // 0x800178A0: sb          $t7, -0x5117($at)
    MEM_B(-0X5117, ctx->r1) = ctx->r15;
    // 0x800178A4: sb          $t6, -0x5118($at)
    MEM_B(-0X5118, ctx->r1) = ctx->r14;
    // 0x800178A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800178AC: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x800178B0: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x800178B4: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x800178B8: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x800178BC: jr          $ra
    // 0x800178C0: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    return;
    // 0x800178C0: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
;}
RECOMP_FUNC void glcutDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800410: lbu         $t6, 0x75F0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X75F0);
    // 0x80800414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800418: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080041C: beq         $t6, $at, L_8080042C
    if (ctx->r14 == ctx->r1) {
        // 0x80800420: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8080042C;
    }
    // 0x80800420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800424: jal         0x80800018
    // 0x80800428: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80800018_glcutDll(rdram, ctx);
        goto after_0;
    // 0x80800428: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
L_8080042C:
    // 0x8080042C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800434: jr          $ra
    // 0x80800438: nop

    return;
    // 0x80800438: nop

;}
RECOMP_FUNC void func_80109FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80109FC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80109FC8: jal         0x80106790
    // 0x80109FCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80109FCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80109FD0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80109FD4: sw          $t6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r14;
    // 0x80109FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109FE0: jr          $ra
    // 0x80109FE4: nop

    return;
    // 0x80109FE4: nop

;}
RECOMP_FUNC void func_801163A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801163A0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801163A4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x801163A8: jr          $ra
    // 0x801163AC: swc1        $f12, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x801163AC: swc1        $f12, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800774_chstinger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800778: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080077C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800780: bne         $a1, $at, L_80800798
    if (ctx->r5 != ctx->r1) {
        // 0x80800784: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800798;
    }
    // 0x80800784: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800788: jal         0x80109EEC
    // 0x8080078C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80109EEC(rdram, ctx);
        goto after_0;
    // 0x8080078C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x80800790: b           L_808007A0
    // 0x80800794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007A0;
    // 0x80800794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800798:
    // 0x80800798: b           L_808007A0
    // 0x8080079C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007A0;
    // 0x8080079C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007A0:
    // 0x808007A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007A8: jr          $ra
    // 0x808007AC: nop

    return;
    // 0x808007AC: nop

;}
RECOMP_FUNC void _glid_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088690: syscall     697
    recomp_syscall_handler(rdram, ctx, 0x80088690);
    return;
    // 0x80088694: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800C9CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9CD0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C9CD4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800C9CD8: lh          $t6, 0x4E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4E);
    // 0x800C9CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9CE0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800C9CE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C9CE8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9CEC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C9CF0: beq         $t7, $zero, L_800C9D0C
    if (ctx->r15 == 0) {
        // 0x800C9CF4: sh          $t6, 0x34($sp)
        MEM_H(0X34, ctx->r29) = ctx->r14;
            goto L_800C9D0C;
    }
    // 0x800C9CF4: sh          $t6, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r14;
    // 0x800C9CF8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800C9CFC: jal         0x800EE7F8
    // 0x800C9D00: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800C9D00: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_0:
    // 0x800C9D04: b           L_800C9D14
    // 0x800C9D08: nop

        goto L_800C9D14;
    // 0x800C9D08: nop

L_800C9D0C:
    // 0x800C9D0C: jal         0x800EFD24
    // 0x800C9D10: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x800C9D10: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
L_800C9D14:
    // 0x800C9D14: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800C9D18: addiu       $a1, $a1, -0x65C8
    ctx->r5 = ADD32(ctx->r5, -0X65C8);
    // 0x800C9D1C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C9D20: jal         0x800C9EF8
    // 0x800C9D24: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800C9EF8(rdram, ctx);
        goto after_2;
    // 0x800C9D24: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x800C9D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9D2C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C9D30: jr          $ra
    // 0x800C9D34: nop

    return;
    // 0x800C9D34: nop

;}
RECOMP_FUNC void func_80800D80_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D8C: jal         0x80088848
    // 0x80800D90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800D90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800D94: beq         $v0, $zero, L_80800DBC
    if (ctx->r2 == 0) {
        // 0x80800D98: nop
    
            goto L_80800DBC;
    }
    // 0x80800D98: nop

    // 0x80800D9C: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800DA0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800DA4: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800DA8: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80800DAC: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800DB0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800DB4: b           L_80800E44
    // 0x80800DB8: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
        goto L_80800E44;
    // 0x80800DB8: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
L_80800DBC:
    // 0x80800DBC: jal         0x800DA298
    // 0x80800DC0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800DC0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_1:
    // 0x80800DC4: beq         $v0, $zero, L_80800DF0
    if (ctx->r2 == 0) {
        // 0x80800DC8: nop
    
            goto L_80800DF0;
    }
    // 0x80800DC8: nop

    // 0x80800DCC: jal         0x800DA298
    // 0x80800DD0: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800DD0: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_2:
    // 0x80800DD4: bne         $v0, $zero, L_80800DF0
    if (ctx->r2 != 0) {
        // 0x80800DD8: nop
    
            goto L_80800DF0;
    }
    // 0x80800DD8: nop

    // 0x80800DDC: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800DE0: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80800DE4: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80800DE8: b           L_80800E44
    // 0x80800DEC: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
        goto L_80800E44;
    // 0x80800DEC: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
L_80800DF0:
    // 0x80800DF0: jal         0x800DA298
    // 0x80800DF4: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800DF4: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_3:
    // 0x80800DF8: beq         $v0, $zero, L_80800E28
    if (ctx->r2 == 0) {
        // 0x80800DFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E28;
    }
    // 0x80800DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E00: jal         0x80102424
    // 0x80800E04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800E04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800E08: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800E0C: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80800E10: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800E14: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80800E18: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x80800E1C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x80800E20: b           L_80800E44
    // 0x80800E24: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
        goto L_80800E44;
    // 0x80800E24: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
L_80800E28:
    // 0x80800E28: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800E2C: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800E30: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x80800E34: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80800E38: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80800E3C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x80800E40: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
L_80800E44:
    // 0x80800E44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E50: jr          $ra
    // 0x80800E54: nop

    return;
    // 0x80800E54: nop

;}
RECOMP_FUNC void _ncpoducam_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089638: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089638);
    return;
    // 0x8008963C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_glintrosyncDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2738, 0X4A0) << 16);
    // 0x80800004: lw          $t6, 0x4A0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(2738, 0X4A0));
    // 0x80800008: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2738, 0X4A8) << 16);
    // 0x8080000C: bne         $a0, $t6, L_8080001C
    if (ctx->r4 != ctx->r14) {
        // 0x80800010: nop
    
            goto L_8080001C;
    }
    // 0x80800010: nop

    // 0x80800014: jr          $ra
    // 0x80800018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080001C:
    // 0x8080001C: lw          $t7, 0x4A8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(2738, 0X4A8));
    // 0x80800020: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2738, 0X4B0) << 16);
    // 0x80800024: bne         $a0, $t7, L_80800034
    if (ctx->r4 != ctx->r15) {
        // 0x80800028: nop
    
            goto L_80800034;
    }
    // 0x80800028: nop

    // 0x8080002C: jr          $ra
    // 0x80800030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800034:
    // 0x80800034: lw          $t8, 0x4B0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(2738, 0X4B0));
    // 0x80800038: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2738, 0X4B8) << 16);
    // 0x8080003C: addiu       $v0, $v0, 0x4B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2738, 0X4B8));
    // 0x80800040: bne         $a0, $t8, L_80800050
    if (ctx->r4 != ctx->r24) {
        // 0x80800044: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_80800050;
    }
    // 0x80800044: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80800048: jr          $ra
    // 0x8080004C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x8080004C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800050:
    // 0x80800050: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
L_80800054:
    // 0x80800054: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800058: bnel        $a0, $t9, L_8080006C
    if (ctx->r4 != ctx->r25) {
        // 0x8080005C: lw          $t0, 0x8($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X8);
            goto L_8080006C;
    }
    goto skip_0;
    // 0x8080005C: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x80800060: jr          $ra
    // 0x80800064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800068: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
L_8080006C:
    // 0x8080006C: bnel        $a0, $t0, L_80800080
    if (ctx->r4 != ctx->r8) {
        // 0x80800070: lw          $t1, 0x10($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X10);
            goto L_80800080;
    }
    goto skip_1;
    // 0x80800070: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    skip_1:
    // 0x80800074: jr          $ra
    // 0x80800078: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x80800078: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8080007C: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
L_80800080:
    // 0x80800080: bnel        $a0, $t1, L_80800094
    if (ctx->r4 != ctx->r9) {
        // 0x80800084: lw          $t2, 0x18($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X18);
            goto L_80800094;
    }
    goto skip_2;
    // 0x80800084: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    skip_2:
    // 0x80800088: jr          $ra
    // 0x8080008C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x8080008C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80800090: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
L_80800094:
    // 0x80800094: bnel        $a0, $t2, L_808000A8
    if (ctx->r4 != ctx->r10) {
        // 0x80800098: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_808000A8;
    }
    goto skip_3;
    // 0x80800098: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x8080009C: jr          $ra
    // 0x808000A0: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x808000A0: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x808000A4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_808000A8:
    // 0x808000A8: bne         $v1, $a1, L_80800054
    if (ctx->r3 != ctx->r5) {
        // 0x808000AC: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_80800054;
    }
    // 0x808000AC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x808000B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void _chskeletonexplode_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E00: syscall     459
    recomp_syscall_handler(rdram, ctx, 0x80086E00);
    return;
    // 0x80086E04: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800080_ncbadive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800088: jal         0x80112524
    // 0x8080008C: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x8080008C: nop

    after_0:
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void glgamedata_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003D8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808003DC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808003E0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x808003E4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808003E8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808003EC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808003F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808003F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808003F8: jal         0x808002CC
    // 0x808003FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_808002CC_glgamedata(rdram, ctx);
        goto after_0;
    // 0x808003FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800400: bne         $v0, $zero, L_80800410
    if (ctx->r2 != 0) {
        // 0x80800404: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800410;
    }
    // 0x80800404: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800408: b           L_80800494
    // 0x8080040C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800494;
    // 0x8080040C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800410:
    // 0x80800410: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2730, 0X4F0) << 16);
    // 0x80800414: addiu       $s4, $s4, 0x4F0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2730, 0X4F0));
    // 0x80800418: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_8080041C:
    // 0x8080041C: addu        $v0, $s6, $s0
    ctx->r2 = ADD32(ctx->r22, ctx->r16);
    // 0x80800420: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80800424: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x80800428: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x8080042C: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x80800430: bne         $at, $zero, L_80800440
    if (ctx->r1 != 0) {
        // 0x80800434: or          $s2, $v1, $zero
        ctx->r18 = ctx->r3 | 0;
            goto L_80800440;
    }
    // 0x80800434: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80800438: b           L_80800494
    // 0x8080043C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800494;
    // 0x8080043C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800440:
    // 0x80800440: multu       $v1, $s5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800444: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800448: mflo        $t6
    ctx->r14 = lo;
    // 0x8080044C: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x80800450: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80800454: beq         $v0, $zero, L_8080046C
    if (ctx->r2 == 0) {
        // 0x80800458: nop
    
            goto L_8080046C;
    }
    // 0x80800458: nop

    // 0x8080045C: jalr        $v0
    // 0x80800460: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80800460: nop

    after_1:
    // 0x80800464: b           L_8080046C
    // 0x80800468: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080046C;
    // 0x80800468: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080046C:
    // 0x8080046C: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x80800470: beql        $v1, $t8, L_80800484
    if (ctx->r3 == ctx->r24) {
        // 0x80800474: lbu         $t9, 0x0($s3)
        ctx->r25 = MEM_BU(ctx->r19, 0X0);
            goto L_80800484;
    }
    goto skip_0;
    // 0x80800474: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    skip_0:
    // 0x80800478: b           L_80800494
    // 0x8080047C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800494;
    // 0x8080047C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800480: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
L_80800484:
    // 0x80800484: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x80800488: bne         $s2, $zero, L_8080041C
    if (ctx->r18 != 0) {
        // 0x8080048C: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8080041C;
    }
    // 0x8080048C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80800490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800494:
    // 0x80800494: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800498: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080049C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808004A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808004A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808004A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808004AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808004B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808004B4: jr          $ra
    // 0x808004B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808004B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800148_chwaterfallfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080014C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800150: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1524, 0X458) << 16);
    // 0x80800154: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800158: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080015C: addiu       $t6, $t6, 0x458
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1524, 0X458));
    // 0x80800160: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800164: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800168: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080016C: jal         0x80089D58
    // 0x80800170: addiu       $a3, $zero, 0xC80
    ctx->r7 = ADD32(0, 0XC80);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800170: addiu       $a3, $zero, 0xC80
    ctx->r7 = ADD32(0, 0XC80);
    after_0:
    // 0x80800174: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800178: beql        $a0, $zero, L_808001B0
    if (ctx->r4 == 0) {
        // 0x8080017C: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_808001B0;
    }
    goto skip_0;
    // 0x8080017C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x80800180: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80800184: sll         $t8, $v0, 12
    ctx->r24 = S32(ctx->r2 << 12);
    // 0x80800188: bltzl       $t8, L_808001C0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080018C: sll         $t5, $v0, 11
        ctx->r13 = S32(ctx->r2 << 11);
            goto L_808001C0;
    }
    goto skip_1;
    // 0x8080018C: sll         $t5, $v0, 11
    ctx->r13 = S32(ctx->r2 << 11);
    skip_1:
    // 0x80800190: jal         0x800C3058
    // 0x80800194: addiu       $a1, $zero, 0x2AF8
    ctx->r5 = ADD32(0, 0X2AF8);
    func_800C3058(rdram, ctx);
        goto after_1;
    // 0x80800194: addiu       $a1, $zero, 0x2AF8
    ctx->r5 = ADD32(0, 0X2AF8);
    after_1:
    // 0x80800198: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x8080019C: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x808001A0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x808001A4: b           L_808001BC
    // 0x808001A8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
        goto L_808001BC;
    // 0x808001A8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x808001AC: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_808001B0:
    // 0x808001B0: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x808001B4: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x808001B8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_808001BC:
    // 0x808001BC: sll         $t5, $v0, 11
    ctx->r13 = S32(ctx->r2 << 11);
L_808001C0:
    // 0x808001C0: bltzl       $t5, L_808001D4
    if (SIGNED(ctx->r13) < 0) {
        // 0x808001C4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808001D4;
    }
    goto skip_2;
    // 0x808001C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808001C8: jal         0x808001F8
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001F8_chwaterfallfx(rdram, ctx);
        goto after_2;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001D4:
    // 0x808001D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001DC: jr          $ra
    // 0x808001E0: nop

    return;
    // 0x808001E0: nop

;}
RECOMP_FUNC void func_8080015C_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800160: beq         $a0, $at, L_808001B0
    if (ctx->r4 == ctx->r1) {
        // 0x80800164: addiu       $at, $zero, 0x4B
        ctx->r1 = ADD32(0, 0X4B);
            goto L_808001B0;
    }
    // 0x80800164: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x80800168: beq         $a0, $at, L_80800190
    if (ctx->r4 == ctx->r1) {
        // 0x8080016C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80800190;
    }
    // 0x8080016C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x80800170: beq         $a0, $at, L_80800198
    if (ctx->r4 == ctx->r1) {
        // 0x80800174: addiu       $at, $zero, 0x4D
        ctx->r1 = ADD32(0, 0X4D);
            goto L_80800198;
    }
    // 0x80800174: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x80800178: beq         $a0, $at, L_808001A0
    if (ctx->r4 == ctx->r1) {
        // 0x8080017C: addiu       $at, $zero, 0x4E
        ctx->r1 = ADD32(0, 0X4E);
            goto L_808001A0;
    }
    // 0x8080017C: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x80800180: beq         $a0, $at, L_808001A8
    if (ctx->r4 == ctx->r1) {
        // 0x80800184: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001A8;
    }
    // 0x80800184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800188: b           L_808001B8
    // 0x8080018C: nop

        goto L_808001B8;
    // 0x8080018C: nop

L_80800190:
    // 0x80800190: jr          $ra
    // 0x80800194: addiu       $v0, $zero, 0x197
    ctx->r2 = ADD32(0, 0X197);
    return;
    // 0x80800194: addiu       $v0, $zero, 0x197
    ctx->r2 = ADD32(0, 0X197);
L_80800198:
    // 0x80800198: jr          $ra
    // 0x8080019C: addiu       $v0, $zero, 0x198
    ctx->r2 = ADD32(0, 0X198);
    return;
    // 0x8080019C: addiu       $v0, $zero, 0x198
    ctx->r2 = ADD32(0, 0X198);
L_808001A0:
    // 0x808001A0: jr          $ra
    // 0x808001A4: addiu       $v0, $zero, 0x199
    ctx->r2 = ADD32(0, 0X199);
    return;
    // 0x808001A4: addiu       $v0, $zero, 0x199
    ctx->r2 = ADD32(0, 0X199);
L_808001A8:
    // 0x808001A8: jr          $ra
    // 0x808001AC: addiu       $v0, $zero, 0x19A
    ctx->r2 = ADD32(0, 0X19A);
    return;
    // 0x808001AC: addiu       $v0, $zero, 0x19A
    ctx->r2 = ADD32(0, 0X19A);
L_808001B0:
    // 0x808001B0: jr          $ra
    // 0x808001B4: addiu       $v0, $zero, 0x19B
    ctx->r2 = ADD32(0, 0X19B);
    return;
    // 0x808001B4: addiu       $v0, $zero, 0x19B
    ctx->r2 = ADD32(0, 0X19B);
L_808001B8:
    // 0x808001B8: jr          $ra
    // 0x808001BC: nop

    return;
    // 0x808001BC: nop

;}
RECOMP_FUNC void sumole_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080142C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801430: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801434: jal         0x80106790
    // 0x80801438: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801438: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x8080143C: jal         0x800C064C
    // 0x80801440: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C064C(rdram, ctx);
        goto after_1;
    // 0x80801440: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801444: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801448: bne         $v0, $a0, L_8080149C
    if (ctx->r2 != ctx->r4) {
        // 0x8080144C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8080149C;
    }
    // 0x8080144C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801450: lw          $t7, 0x64($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X64);
    // 0x80801454: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801458: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8080145C: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80801460: bnel        $t9, $at, L_808014A0
    if (ctx->r25 != ctx->r1) {
        // 0x80801464: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808014A0;
    }
    goto skip_0;
    // 0x80801464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80801468: lw          $t0, 0x3C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X3C);
    // 0x8080146C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801470: beql        $t0, $zero, L_808014A0
    if (ctx->r8 == 0) {
        // 0x80801474: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808014A0;
    }
    goto skip_1;
    // 0x80801474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80801478: beq         $v1, $a0, L_80801494
    if (ctx->r3 == ctx->r4) {
        // 0x8080147C: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_80801494;
    }
    // 0x8080147C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80801480: lbu         $t4, 0x72($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X72);
    // 0x80801484: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80801488: andi        $t5, $t4, 0xFF03
    ctx->r13 = ctx->r12 & 0XFF03;
    // 0x8080148C: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80801490: sb          $t6, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r14;
L_80801494:
    // 0x80801494: b           L_808014A0
    // 0x80801498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808014A0;
    // 0x80801498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080149C:
    // 0x8080149C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808014A0:
    // 0x808014A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808014A8: jr          $ra
    // 0x808014AC: nop

    return;
    // 0x808014AC: nop

;}
RECOMP_FUNC void bsclimb_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800838: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(144, 0X91C) << 16);
    // 0x8080083C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800840: jr          $ra
    // 0x80800844: lw          $v0, 0x91C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(144, 0X91C));
    return;
    // 0x80800844: lw          $v0, 0x91C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(144, 0X91C));
;}
RECOMP_FUNC void func_800B2868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2868: lw          $v1, 0x34($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X34);
    // 0x800B286C: bne         $v1, $zero, L_800B287C
    if (ctx->r3 != 0) {
        // 0x800B2870: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B287C;
    }
    // 0x800B2870: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B2874: jr          $ra
    // 0x800B2878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B2878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B287C:
    // 0x800B287C: jr          $ra
    // 0x800B2880: nop

    return;
    // 0x800B2880: nop

    // 0x800B2884: nop

    // 0x800B2888: nop

    // 0x800B288C: nop

;}
RECOMP_FUNC void func_8002039C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002039C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800203A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800203A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800203A8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800203AC: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x800203B0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800203B4: jal         0x8002FEC0
    // 0x800203B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800203B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800203BC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800203C0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800203C4: lw          $t8, 0x11D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11D8);
    // 0x800203C8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800203CC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800203D0: beq         $t9, $zero, L_800205A8
    if (ctx->r25 == 0) {
        // 0x800203D4: nop
    
            goto L_800205A8;
    }
    // 0x800203D4: nop

    // 0x800203D8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800203DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800203E0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800203E4: sw          $t1, 0x11D8($at)
    MEM_W(0X11D8, ctx->r1) = ctx->r9;
    // 0x800203E8: jal         0x80020E74
    // 0x800203EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80020E74(rdram, ctx);
        goto after_1;
    // 0x800203EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800203F0: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800203F4: lw          $t2, 0x11D0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11D0);
    // 0x800203F8: beq         $t2, $zero, L_80020438
    if (ctx->r10 == 0) {
        // 0x800203FC: nop
    
            goto L_80020438;
    }
    // 0x800203FC: nop

    // 0x80020400: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80020404: lw          $t3, 0x11D0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11D0);
    // 0x80020408: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8002040C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80020410: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80020414: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80020418: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002041C: lw          $t7, 0x11D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11D0);
    // 0x80020420: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80020424: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80020428: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002042C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020430: b           L_80020464
    // 0x80020434: sw          $t8, 0x11D0($at)
    MEM_W(0X11D0, ctx->r1) = ctx->r24;
        goto L_80020464;
    // 0x80020434: sw          $t8, 0x11D0($at)
    MEM_W(0X11D0, ctx->r1) = ctx->r24;
L_80020438:
    // 0x80020438: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002043C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80020440: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80020444: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80020448: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x8002044C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80020450: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020454: sw          $t2, 0x11D0($at)
    MEM_W(0X11D0, ctx->r1) = ctx->r10;
    // 0x80020458: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002045C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020460: sw          $t3, 0x11D4($at)
    MEM_W(0X11D4, ctx->r1) = ctx->r11;
L_80020464:
    // 0x80020464: jal         0x8002FEC0
    // 0x80020468: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80020468: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8002046C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80020470: jal         0x800E9070
    // 0x80020474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800E9070(rdram, ctx);
        goto after_3;
    // 0x80020474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80020478: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8002047C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80020480: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80020484: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80020488: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002048C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80020490: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80020494: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80020498: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002049C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800204A0: addiu       $t1, $t9, 0x40
    ctx->r9 = ADD32(ctx->r25, 0X40);
    // 0x800204A4: sb          $t1, 0x40($t0)
    MEM_B(0X40, ctx->r8) = ctx->r9;
    // 0x800204A8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800204AC: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800204B0: sb          $t2, 0x45($t3)
    MEM_B(0X45, ctx->r11) = ctx->r10;
    // 0x800204B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800204B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800204BC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800204C0: swc1        $f4, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f4.u32l;
    // 0x800204C4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800204C8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800204CC: sw          $t5, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r13;
    // 0x800204D0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800204D4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800204D8: lbu         $t8, 0x3($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X3);
    // 0x800204DC: andi        $t9, $t8, 0xF0
    ctx->r25 = ctx->r24 & 0XF0;
    // 0x800204E0: sb          $t9, 0x44($t1)
    MEM_B(0X44, ctx->r9) = ctx->r25;
    // 0x800204E4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800204E8: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x800204EC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800204F0: lbu         $t3, 0x44($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X44);
    // 0x800204F4: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x800204F8: beq         $t4, $zero, L_80020534
    if (ctx->r12 == 0) {
        // 0x800204FC: nop
    
            goto L_80020534;
    }
    // 0x800204FC: nop

    // 0x80020500: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80020504: lbu         $a0, 0x4($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X4);
    // 0x80020508: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x8002050C: sll         $a0, $at, 2
    ctx->r4 = S32(ctx->r1 << 2);
    // 0x80020510: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x80020514: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80020518: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8002051C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80020520: jal         0x80027170
    // 0x80020524: addiu       $a0, $a0, -0x1770
    ctx->r4 = ADD32(ctx->r4, -0X1770);
    func_80027170(rdram, ctx);
        goto after_4;
    // 0x80020524: addiu       $a0, $a0, -0x1770
    ctx->r4 = ADD32(ctx->r4, -0X1770);
    after_4:
    // 0x80020528: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002052C: b           L_80020568
    // 0x80020530: swc1        $f0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f0.u32l;
        goto L_80020568;
    // 0x80020530: swc1        $f0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f0.u32l;
L_80020534:
    // 0x80020534: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80020538: lbu         $t8, 0x4($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X4);
    // 0x8002053C: lb          $t1, 0x5($t7)
    ctx->r9 = MEM_B(ctx->r15, 0X5);
    // 0x80020540: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80020544: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80020548: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002054C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80020550: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80020554: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x80020558: jal         0x80027170
    // 0x8002055C: addiu       $a0, $a0, -0x1770
    ctx->r4 = ADD32(ctx->r4, -0X1770);
    func_80027170(rdram, ctx);
        goto after_5;
    // 0x8002055C: addiu       $a0, $a0, -0x1770
    ctx->r4 = ADD32(ctx->r4, -0X1770);
    after_5:
    // 0x80020560: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80020564: swc1        $f0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f0.u32l;
L_80020568:
    // 0x80020568: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8002056C: beq         $t2, $zero, L_80020584
    if (ctx->r10 == 0) {
        // 0x80020570: nop
    
            goto L_80020584;
    }
    // 0x80020570: nop

    // 0x80020574: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80020578: lbu         $t4, 0x44($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X44);
    // 0x8002057C: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80020580: sb          $t5, 0x44($t3)
    MEM_B(0X44, ctx->r11) = ctx->r13;
L_80020584:
    // 0x80020584: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80020588: sb          $zero, 0x42($t6)
    MEM_B(0X42, ctx->r14) = 0;
    // 0x8002058C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80020590: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80020594: sb          $t8, 0x41($t7)
    MEM_B(0X41, ctx->r15) = ctx->r24;
    // 0x80020598: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8002059C: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800205A0: b           L_800205B0
    // 0x800205A4: sh          $t9, 0x38($t1)
    MEM_H(0X38, ctx->r9) = ctx->r25;
        goto L_800205B0;
    // 0x800205A4: sh          $t9, 0x38($t1)
    MEM_H(0X38, ctx->r9) = ctx->r25;
L_800205A8:
    // 0x800205A8: jal         0x8002FEC0
    // 0x800205AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800205AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
L_800205B0:
    // 0x800205B0: b           L_800205C0
    // 0x800205B4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_800205C0;
    // 0x800205B4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800205B8: b           L_800205C0
    // 0x800205BC: nop

        goto L_800205C0;
    // 0x800205BC: nop

L_800205C0:
    // 0x800205C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800205C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800205C8: jr          $ra
    // 0x800205CC: nop

    return;
    // 0x800205CC: nop

;}
RECOMP_FUNC void _idflasha_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D60: syscall     738
    recomp_syscall_handler(rdram, ctx, 0x80088D60);
    return;
    // 0x80088D64: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _baflamethrower_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BB0: syscall     131
    recomp_syscall_handler(rdram, ctx, 0x80084BB0);
    return;
    // 0x80084BB4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808003DC_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808003E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003E8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808003EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003F0: jal         0x80100094
    // 0x808003F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003F8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808003FC: lbu         $v1, 0x90($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X90);
    // 0x80800400: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800404: beq         $v1, $at, L_80800428
    if (ctx->r3 == ctx->r1) {
        // 0x80800408: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800428;
    }
    // 0x80800408: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080040C: beq         $v1, $at, L_80800438
    if (ctx->r3 == ctx->r1) {
        // 0x80800410: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800438;
    }
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800418: beq         $v1, $at, L_80800458
    if (ctx->r3 == ctx->r1) {
        // 0x8080041C: nop
    
            goto L_80800458;
    }
    // 0x8080041C: nop

    // 0x80800420: b           L_80800480
    // 0x80800424: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
        goto L_80800480;
    // 0x80800424: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_80800428:
    // 0x80800428: jal         0x80090708
    // 0x8080042C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_1;
    // 0x8080042C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800430: b           L_80800480
    // 0x80800434: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
        goto L_80800480;
    // 0x80800434: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_80800438:
    // 0x80800438: jal         0x80100094
    // 0x8080043C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8080043C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800440: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800444: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800448: jal         0x800897E8
    // 0x8080044C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x8080044C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
    // 0x80800450: b           L_80800480
    // 0x80800454: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
        goto L_80800480;
    // 0x80800454: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_80800458:
    // 0x80800458: jal         0x800F54E4
    // 0x8080045C: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x8080045C: nop

    after_4:
    // 0x80800460: jal         0x800F4CC0
    // 0x80800464: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_5;
    // 0x80800464: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800468: jal         0x800FDC28
    // 0x8080046C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800FDC28(rdram, ctx);
        goto after_6;
    // 0x8080046C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_6:
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: jal         0x80800ECC
    // 0x80800478: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800ECC_chevilmumbo(rdram, ctx);
        goto after_7;
    // 0x80800478: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8080047C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_80800480:
    // 0x80800480: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80800484: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80800488: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x8080048C: beq         $at, $zero, L_8080065C
    if (ctx->r1 == 0) {
        // 0x80800490: sb          $t6, 0x90($t7)
        MEM_B(0X90, ctx->r15) = ctx->r14;
            goto L_8080065C;
    }
    // 0x80800490: sb          $t6, 0x90($t7)
    MEM_B(0X90, ctx->r15) = ctx->r14;
    // 0x80800494: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800498: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3D00) << 16);
    // 0x8080049C: addu        $at, $at, $t8
    gpr jr_addend_808004A4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808004A0: lw          $t8, 0x3D00($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3D00));
    // 0x808004A4: jr          $t8
    // 0x808004A8: nop

    switch (jr_addend_808004A4 >> 2) {
        case 0: goto L_808004AC; break;
        case 1: goto L_8080065C; break;
        case 2: goto L_8080065C; break;
        case 3: goto L_8080054C; break;
        case 4: goto L_80800600; break;
        case 5: goto L_80800500; break;
        case 6: goto L_80800640; break;
        case 7: goto L_80800534; break;
        case 8: goto L_808005B4; break;
        case 9: goto L_808004E8; break;
        default: switch_error(__func__, 0x808004A4, 0x80803D00);
    }
    // 0x808004A8: nop

L_808004AC:
    // 0x808004AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808004B0: jal         0x80090734
    // 0x808004B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80090734(rdram, ctx);
        goto after_8;
    // 0x808004B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x808004B8: jal         0x800F54E4
    // 0x808004BC: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x808004BC: nop

    after_9:
    // 0x808004C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004C4: jal         0x800F4CEC
    // 0x808004C8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    func_800F4CEC(rdram, ctx);
        goto after_10;
    // 0x808004C8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_10:
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808004D4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x808004D8: jal         0x808001F4
    // 0x808004DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808001F4_chevilmumbo(rdram, ctx);
        goto after_11;
    // 0x808004DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x808004E0: b           L_80800660
    // 0x808004E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800660;
    // 0x808004E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004E8:
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: addiu       $a1, $zero, 0x11E0
    ctx->r5 = ADD32(0, 0X11E0);
    // 0x808004F0: jal         0x80800354
    // 0x808004F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800354_chevilmumbo(rdram, ctx);
        goto after_12;
    // 0x808004F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x808004F8: b           L_80800660
    // 0x808004FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800660;
    // 0x808004FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800500:
    // 0x80800500: jal         0x800DA544
    // 0x80800504: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x80800504: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    after_13:
    // 0x80800508: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800514: lbu         $t0, 0x96($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X96);
    // 0x80800518: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8080051C: bnel        $t0, $zero, L_80800660
    if (ctx->r8 != 0) {
        // 0x80800520: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800660;
    }
    goto skip_0;
    // 0x80800520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800524: jal         0x808001F4
    // 0x80800528: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808001F4_chevilmumbo(rdram, ctx);
        goto after_14;
    // 0x80800528: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x8080052C: b           L_80800660
    // 0x80800530: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800660;
    // 0x80800530: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800534:
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: addiu       $a1, $zero, 0x11E3
    ctx->r5 = ADD32(0, 0X11E3);
    // 0x8080053C: jal         0x80800354
    // 0x80800540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800354_chevilmumbo(rdram, ctx);
        goto after_15;
    // 0x80800540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80800544: b           L_80800660
    // 0x80800548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800660;
    // 0x80800548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080054C:
    // 0x8080054C: jal         0x8010A570
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_16;
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800554: jal         0x800D395C
    // 0x80800558: nop

    func_800D395C(rdram, ctx);
        goto after_17;
    // 0x80800558: nop

    after_17:
    // 0x8080055C: bne         $v0, $zero, L_808005A4
    if (ctx->r2 != 0) {
        // 0x80800560: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005A4;
    }
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800564: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80800568: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x8080056C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800574: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800578: jal         0x800D1000
    // 0x8080057C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800D1000(rdram, ctx);
        goto after_18;
    // 0x8080057C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_18:
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80800588: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8080058C: jal         0x808001F4
    // 0x80800590: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808001F4_chevilmumbo(rdram, ctx);
        goto after_19;
    // 0x80800590: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_19:
    // 0x80800594: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080059C: b           L_8080065C
    // 0x808005A0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_8080065C;
    // 0x808005A0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808005A4:
    // 0x808005A4: jal         0x808003DC
    // 0x808005A8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808003DC_chevilmumbo(rdram, ctx);
        goto after_20;
    // 0x808005A8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_20:
    // 0x808005AC: b           L_80800660
    // 0x808005B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800660;
    // 0x808005B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005B4:
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x808005BC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x808005C0: jal         0x808001F4
    // 0x808005C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808001F4_chevilmumbo(rdram, ctx);
        goto after_21;
    // 0x808005C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_21:
    // 0x808005C8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808005CC: jal         0x800EE7F8
    // 0x808005D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_22;
    // 0x808005D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x808005D4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808005D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005DC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808005E8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808005EC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808005F0: jal         0x80086670
    // 0x808005F4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x808005F4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_23:
    // 0x808005F8: b           L_80800660
    // 0x808005FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800660;
    // 0x808005FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800600:
    // 0x80800600: jal         0x800D395C
    // 0x80800604: nop

    func_800D395C(rdram, ctx);
        goto after_24;
    // 0x80800604: nop

    after_24:
    // 0x80800608: beq         $v0, $zero, L_80800620
    if (ctx->r2 == 0) {
        // 0x8080060C: nop
    
            goto L_80800620;
    }
    // 0x8080060C: nop

    // 0x80800610: jal         0x80088180
    // 0x80800614: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_25;
    // 0x80800614: nop

    after_25:
    // 0x80800618: b           L_80800630
    // 0x8080061C: nop

        goto L_80800630;
    // 0x8080061C: nop

L_80800620:
    // 0x80800620: jal         0x80800290
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800290_chevilmumbo(rdram, ctx);
        goto after_26;
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800628: jal         0x80090708
    // 0x8080062C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_27;
    // 0x8080062C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
L_80800630:
    // 0x80800630: jal         0x800FFAB0
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_28;
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800638: b           L_80800660
    // 0x8080063C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800660;
    // 0x8080063C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800640:
    // 0x80800640: jal         0x800DA544
    // 0x80800644: addiu       $a0, $zero, 0xA32
    ctx->r4 = ADD32(0, 0XA32);
    func_800DA544(rdram, ctx);
        goto after_29;
    // 0x80800644: addiu       $a0, $zero, 0xA32
    ctx->r4 = ADD32(0, 0XA32);
    after_29:
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800650: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80800654: jal         0x808001F4
    // 0x80800658: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808001F4_chevilmumbo(rdram, ctx);
        goto after_30;
    // 0x80800658: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_30:
L_8080065C:
    // 0x8080065C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800660:
    // 0x80800660: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800664: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800668: jr          $ra
    // 0x8080066C: nop

    return;
    // 0x8080066C: nop

;}
RECOMP_FUNC void glsavegame_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004DC: jal         0x80800000
    // 0x808004E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80800000_glsavegame(rdram, ctx);
        goto after_0;
    // 0x808004E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808004E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x808004EC: addiu       $a1, $a1, 0x7618
    ctx->r5 = ADD32(ctx->r5, 0X7618);
    // 0x808004F0: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x808004F4: lb          $t6, 0xC($v1)
    ctx->r14 = MEM_B(ctx->r3, 0XC);
    // 0x808004F8: lb          $t7, 0xF($a1)
    ctx->r15 = MEM_B(ctx->r5, 0XF);
    // 0x808004FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800500: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80800504: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80800508: jal         0x808004B8
    // 0x8080050C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_808004B8_glsavegame(rdram, ctx);
        goto after_1;
    // 0x8080050C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_1:
    // 0x80800510: jal         0x80088578
    // 0x80800514: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _glgamedata_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800514: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800518: jal         0x808004C4
    // 0x8080051C: nop

    func_808004C4_glsavegame(rdram, ctx);
        goto after_3;
    // 0x8080051C: nop

    after_3:
    // 0x80800520: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800524: jal         0x808002E0
    // 0x80800528: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808002E0_glsavegame(rdram, ctx);
        goto after_4;
    // 0x80800528: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8080052C: bne         $v0, $zero, L_80800540
    if (ctx->r2 != 0) {
        // 0x80800530: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800540;
    }
    // 0x80800530: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800534: jal         0x8080036C
    // 0x80800538: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080036C_glsavegame(rdram, ctx);
        goto after_5;
    // 0x80800538: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8080053C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800540:
    // 0x80800540: bne         $v0, $zero, L_8080055C
    if (ctx->r2 != 0) {
        // 0x80800544: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_8080055C;
    }
    // 0x80800544: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800548: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8080054C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800550: sb          $t8, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r24;
    // 0x80800554: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800558: sb          $t0, 0x7627($at)
    MEM_B(0X7627, ctx->r1) = ctx->r8;
L_8080055C:
    // 0x8080055C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800560: jal         0x8001B084
    // 0x80800564: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    heap_free(rdram, ctx);
        goto after_6;
    // 0x80800564: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_6:
    // 0x80800568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080056C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800570: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800574: jr          $ra
    // 0x80800578: nop

    return;
    // 0x80800578: nop

;}
RECOMP_FUNC void func_80800180_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800184: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800188: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080018C: jal         0x80103EF4
    // 0x80800190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80103EF4(rdram, ctx);
        goto after_0;
    // 0x80800190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800194: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800198: jal         0x80103EAC
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_1;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001A0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001A4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001A8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x808001AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808001B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808001B8: jal         0x80089F20
    // 0x808001BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808001BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x808001C0: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808001C4: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808001C8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x808001CC: sltiu       $at, $t9, 0xF
    ctx->r1 = ctx->r25 < 0XF ? 1 : 0;
    // 0x808001D0: beq         $at, $zero, L_808003AC
    if (ctx->r1 == 0) {
        // 0x808001D4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808003AC;
    }
    // 0x808001D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808001D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2D30) << 16);
    // 0x808001DC: addu        $at, $at, $t9
    gpr jr_addend_808001E4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808001E0: lw          $t9, 0x2D30($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2D30));
    // 0x808001E4: jr          $t9
    // 0x808001E8: nop

    switch (jr_addend_808001E4 >> 2) {
        case 0: goto L_808001EC; break;
        case 1: goto L_808003AC; break;
        case 2: goto L_8080020C; break;
        case 3: goto L_808003AC; break;
        case 4: goto L_808003AC; break;
        case 5: goto L_808003AC; break;
        case 6: goto L_808003AC; break;
        case 7: goto L_80800258; break;
        case 8: goto L_80800334; break;
        case 9: goto L_808003AC; break;
        case 10: goto L_80800334; break;
        case 11: goto L_808003AC; break;
        case 12: goto L_80800360; break;
        case 13: goto L_80800384; break;
        case 14: goto L_808003A4; break;
        default: switch_error(__func__, 0x808001E4, 0x80802D30);
    }
    // 0x808001E8: nop

L_808001EC:
    // 0x808001EC: jal         0x800D90A4
    // 0x808001F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x808001F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x808001F4: beq         $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x808001F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: jal         0x808003D0
    // 0x80800200: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_4;
    // 0x80800200: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800204: b           L_808003AC
    // 0x80800208: nop

        goto L_808003AC;
    // 0x80800208: nop

L_8080020C:
    // 0x8080020C: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x80800210: jal         0x800D0A9C
    // 0x80800214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_5;
    // 0x80800214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800218: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x8080021C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080022C;
    }
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: addiu       $t0, $zero, 0x13F0
    ctx->r8 = ADD32(0, 0X13F0);
    // 0x80800224: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X3096) << 16);
    // 0x80800228: sh          $t0, 0x3096($at)
    MEM_H((int16_t)RELOC_LO16(2384, 0X3096), ctx->r1) = ctx->r8;
L_8080022C:
    // 0x8080022C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2384, 0X3090) << 16);
    // 0x80800230: addiu       $a2, $a2, 0x3090
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2384, 0X3090));
    // 0x80800234: jal         0x8008A1E8
    // 0x80800238: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800238: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x8080023C: beq         $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x80800240: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800248: jal         0x80801740
    // 0x8080024C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801740_chtrashcangame(rdram, ctx);
        goto after_7;
    // 0x8080024C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800250: b           L_808003AC
    // 0x80800254: nop

        goto L_808003AC;
    // 0x80800254: nop

L_80800258:
    // 0x80800258: jal         0x800D90A4
    // 0x8080025C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_8;
    // 0x8080025C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x80800260: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800264: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2384, 0X2D6C) << 16);
            goto L_8080027C;
    }
    // 0x80800264: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2D6C) << 16);
    // 0x80800268: lwc1        $f4, 0x2D6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2D6C));
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800274: jal         0x80108B04
    // 0x80800278: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80108B04(rdram, ctx);
        goto after_9;
    // 0x80800278: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_9:
L_8080027C:
    // 0x8080027C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800280: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x80800284: jal         0x8008A1D0
    // 0x80800288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8080028C: beq         $v0, $zero, L_808002F8
    if (ctx->r2 == 0) {
        // 0x80800290: addiu       $a0, $zero, 0x4E
        ctx->r4 = ADD32(0, 0X4E);
            goto L_808002F8;
    }
    // 0x80800290: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x80800294: jal         0x800D0A9C
    // 0x80800298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_11;
    // 0x80800298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8080029C: beq         $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808002A0: addiu       $a0, $zero, 0x1401
        ctx->r4 = ADD32(0, 0X1401);
            goto L_808002D4;
    }
    // 0x808002A0: addiu       $a0, $zero, 0x1401
    ctx->r4 = ADD32(0, 0X1401);
    // 0x808002A4: addiu       $a0, $zero, 0x1403
    ctx->r4 = ADD32(0, 0X1403);
    // 0x808002A8: jal         0x800DC128
    // 0x808002AC: addiu       $a1, $zero, 0x1405
    ctx->r5 = ADD32(0, 0X1405);
    func_800DC128(rdram, ctx);
        goto after_12;
    // 0x808002AC: addiu       $a1, $zero, 0x1405
    ctx->r5 = ADD32(0, 0X1405);
    after_12:
    // 0x808002B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002B4: addiu       $t1, $zero, 0x6A
    ctx->r9 = ADD32(0, 0X6A);
    // 0x808002B8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808002BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808002C0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808002C4: jal         0x8008A208
    // 0x808002C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x808002C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x808002CC: b           L_808002F8
    // 0x808002D0: nop

        goto L_808002F8;
    // 0x808002D0: nop

L_808002D4:
    // 0x808002D4: jal         0x800DC128
    // 0x808002D8: addiu       $a1, $zero, 0x1405
    ctx->r5 = ADD32(0, 0X1405);
    func_800DC128(rdram, ctx);
        goto after_14;
    // 0x808002D8: addiu       $a1, $zero, 0x1405
    ctx->r5 = ADD32(0, 0X1405);
    after_14:
    // 0x808002DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002E0: addiu       $t2, $zero, 0x6A
    ctx->r10 = ADD32(0, 0X6A);
    // 0x808002E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808002E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808002EC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808002F0: jal         0x8008A208
    // 0x808002F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x808002F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_15:
L_808002F8:
    // 0x808002F8: jal         0x800CEAD0
    // 0x808002FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_16;
    // 0x808002FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x80800300: beql        $v0, $zero, L_80800314
    if (ctx->r2 == 0) {
        // 0x80800304: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800314;
    }
    goto skip_0;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800308: jal         0x80800728
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800728_chtrashcangame(rdram, ctx);
        goto after_17;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800314:
    // 0x80800314: jal         0x80800014
    // 0x80800318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_18;
    // 0x80800318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x8080031C: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    // 0x80800320: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800324: jal         0x800D2498
    // 0x80800328: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_19;
    // 0x80800328: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x8080032C: b           L_808003AC
    // 0x80800330: nop

        goto L_808003AC;
    // 0x80800330: nop

L_80800334:
    // 0x80800334: jal         0x8010CEAC
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CEAC(rdram, ctx);
        goto after_20;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x80800014
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_21;
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80800348: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    // 0x8080034C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800350: jal         0x800D2498
    // 0x80800354: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_22;
    // 0x80800354: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x80800358: b           L_808003AC
    // 0x8080035C: nop

        goto L_808003AC;
    // 0x8080035C: nop

L_80800360:
    // 0x80800360: addiu       $a0, $zero, 0x21F
    ctx->r4 = ADD32(0, 0X21F);
    // 0x80800364: jal         0x80089C30
    // 0x80800368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_23;
    // 0x80800368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x8080036C: bne         $v0, $zero, L_808003AC
    if (ctx->r2 != 0) {
        // 0x80800370: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: jal         0x808003D0
    // 0x80800378: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_24;
    // 0x80800378: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_24:
    // 0x8080037C: b           L_808003AC
    // 0x80800380: nop

        goto L_808003AC;
    // 0x80800380: nop

L_80800384:
    // 0x80800384: jal         0x800D90A4
    // 0x80800388: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_25;
    // 0x80800388: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_25:
    // 0x8080038C: beq         $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x80800390: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: jal         0x808003D0
    // 0x80800398: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_26;
    // 0x80800398: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_26:
    // 0x8080039C: b           L_808003AC
    // 0x808003A0: nop

        goto L_808003AC;
    // 0x808003A0: nop

L_808003A4:
    // 0x808003A4: jal         0x8010CEAC
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CEAC(rdram, ctx);
        goto after_27;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
L_808003AC:
    // 0x808003AC: jal         0x80800BA8
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BA8_chtrashcangame(rdram, ctx);
        goto after_28;
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808003B4: jal         0x808018E4
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018E4_chtrashcangame(rdram, ctx);
        goto after_29;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808003BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003C8: jr          $ra
    // 0x808003CC: nop

    return;
    // 0x808003CC: nop

;}
RECOMP_FUNC void func_80800000_chminegrill2switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80085808
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800018: jal         0x80085810
    // 0x8080001C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080001C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_8010FB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FB34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010FB38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010FB3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8010FB40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010FB44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010FB48: jal         0x8001ACCC
    // 0x8010FB4C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8010FB4C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x8010FB50: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8010FB54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010FB58: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
    // 0x8010FB5C: sb          $zero, 0x19($v0)
    MEM_B(0X19, ctx->r2) = 0;
    // 0x8010FB60: sb          $zero, 0x20($v0)
    MEM_B(0X20, ctx->r2) = 0;
    // 0x8010FB64: jal         0x80114BD4
    // 0x8010FB68: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    func_80114BD4(rdram, ctx);
        goto after_1;
    // 0x8010FB68: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_1:
    // 0x8010FB6C: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8010FB70: jal         0x800DA298
    // 0x8010FB74: addiu       $a0, $zero, 0x6B5
    ctx->r4 = ADD32(0, 0X6B5);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8010FB74: addiu       $a0, $zero, 0x6B5
    ctx->r4 = ADD32(0, 0X6B5);
    after_2:
    // 0x8010FB78: beql        $v0, $zero, L_8010FB94
    if (ctx->r2 == 0) {
        // 0x8010FB7C: sw          $zero, 0xC($s0)
        MEM_W(0XC, ctx->r16) = 0;
            goto L_8010FB94;
    }
    goto skip_0;
    // 0x8010FB7C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    skip_0:
    // 0x8010FB80: jal         0x80115118
    // 0x8010FB84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115118(rdram, ctx);
        goto after_3;
    // 0x8010FB84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010FB88: b           L_8010FB94
    // 0x8010FB8C: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_8010FB94;
    // 0x8010FB8C: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8010FB90: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
L_8010FB94:
    // 0x8010FB94: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8010FB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010FB9C: jal         0x80110424
    // 0x8010FBA0: sw          $a1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r5;
    func_80110424(rdram, ctx);
        goto after_4;
    // 0x8010FBA0: sw          $a1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r5;
    after_4:
    // 0x8010FBA4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8010FBA8: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8010FBAC: sh          $zero, 0x14($s0)
    MEM_H(0X14, ctx->r16) = 0;
    // 0x8010FBB0: sh          $zero, 0x16($s0)
    MEM_H(0X16, ctx->r16) = 0;
    // 0x8010FBB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010FBB8: jal         0x8010F9C0
    // 0x8010FBBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010F9C0(rdram, ctx);
        goto after_5;
    // 0x8010FBBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8010FBC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010FBC4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8010FBC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010FBCC: jr          $ra
    // 0x8010FBD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010FBD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800070_chgobicommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800078: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8080007C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1448, 0X21C) << 16);
    // 0x80800080: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1448, 0X244) << 16);
    // 0x80800084: addiu       $a3, $a3, 0x244
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1448, 0X244));
    // 0x80800088: addiu       $a2, $a2, 0x21C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1448, 0X21C));
    // 0x8080008C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800090: jal         0x80089D28
    // 0x80800094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800098: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1448, 0X22C) << 16);
    // 0x8080009C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1448, 0X254) << 16);
    // 0x808000A0: addiu       $a3, $a3, 0x254
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1448, 0X254));
    // 0x808000A4: addiu       $a2, $a2, 0x22C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1448, 0X22C));
    // 0x808000A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000AC: jal         0x80089D28
    // 0x808000B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808000B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808000B4: jal         0x800C0638
    // 0x808000B8: nop

    func_800C0638(rdram, ctx);
        goto after_2;
    // 0x808000B8: nop

    after_2:
    // 0x808000BC: bne         $v0, $zero, L_808000DC
    if (ctx->r2 != 0) {
        // 0x808000C0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000DC;
    }
    // 0x808000C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1448, 0X238) << 16);
    // 0x808000C8: lui         $a3, 0x3CF5
    ctx->r7 = S32(0X3CF5 << 16);
    // 0x808000CC: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x808000D0: addiu       $a2, $a2, 0x238
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1448, 0X238));
    // 0x808000D4: jal         0x80089D20
    // 0x808000D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808000D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_808000DC:
    // 0x808000DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void func_800F66F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F66F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F66F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F66F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F66FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6700: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6704: jal         0x8009E6F8
    // 0x800F6708: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F6708: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F670C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6710: xori        $t7, $v0, 0x6F
    ctx->r15 = ctx->r2 ^ 0X6F;
    // 0x800F6714: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F6718: jr          $ra
    // 0x800F671C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F671C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gcdialogcamera_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080024C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800250: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800254: jal         0x800856F8
    // 0x80800258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080025C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800264: jr          $ra
    // 0x80800268: nop

    return;
    // 0x80800268: nop

;}
