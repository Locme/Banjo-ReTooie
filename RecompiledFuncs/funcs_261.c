#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _ncbadie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089270: syscall     769
    recomp_syscall_handler(rdram, ctx, 0x80089270);
    return;
    // 0x80089274: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void bsbtrot_entrypoint_53(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802D40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802D44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802D48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802D4C: jal         0x80800120
    // 0x80802D50: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_80800120_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80802D50: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80802D54: jal         0x808004B4
    // 0x80802D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80802D5C: jal         0x800850A0
    // 0x80802D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoessuck_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80802D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802D64: jal         0x8008E40C
    // 0x80802D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E40C(rdram, ctx);
        goto after_3;
    // 0x80802D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802D6C: bne         $v0, $zero, L_80802D7C
    if (ctx->r2 != 0) {
        // 0x80802D70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802D7C;
    }
    // 0x80802D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D74: addiu       $t6, $zero, 0x17
    ctx->r14 = ADD32(0, 0X17);
    // 0x80802D78: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80802D7C:
    // 0x80802D7C: jal         0x808007E0
    // 0x80802D80: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808007E0_bsbtrot(rdram, ctx);
        goto after_4;
    // 0x80802D80: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80802D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D88: jal         0x8009E5C8
    // 0x80802D8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x80802D8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80802D90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802D94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802D98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802D9C: jr          $ra
    // 0x80802DA0: nop

    return;
    // 0x80802DA0: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080168C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801690: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80801694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801698: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080169C: jal         0x8008CDB8
    // 0x808016A0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x808016A0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x808016A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808016A8: jal         0x8008CA4C
    // 0x808016AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_1;
    // 0x808016AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808016B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808016B4: jal         0x8009B9B0
    // 0x808016B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808016B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808016BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808016C0: jal         0x800931AC
    // 0x808016C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800931AC(rdram, ctx);
        goto after_3;
    // 0x808016C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808016C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808016CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808016D0: jr          $ra
    // 0x808016D4: nop

    return;
    // 0x808016D4: nop

;}
RECOMP_FUNC void func_80800A78_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A7C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800A80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A8C: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x80800A90: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800A94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A98: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800A9C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800AA0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800AA4: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800AA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AAC: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    // 0x80800AB0: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80800AB4: jal         0x800DC178
    // 0x80800AB8: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800AB8: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x80800ABC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800AC0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800AC4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800AC8: jal         0x800DC178
    // 0x80800ACC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800ACC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x80800AD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800AD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800AD8: jal         0x800DC298
    // 0x80800ADC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x80800ADC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x80800AE0: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800AE4: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x80800AE8: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x80800AEC: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x80800AF0: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80800AF4: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80800AF8: jal         0x80800824
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800824_chfiregen(rdram, ctx);
        goto after_3;
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800B00: jal         0x800DA298
    // 0x80800B04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800B04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800B08: beql        $v0, $zero, L_80800B3C
    if (ctx->r2 == 0) {
        // 0x80800B0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B3C;
    }
    goto skip_0;
    // 0x80800B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800B10: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
    // 0x80800B14: lbu         $t7, 0x72($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X72);
    // 0x80800B18: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x80800B1C: addiu       $t6, $t5, -0x32
    ctx->r14 = ADD32(ctx->r13, -0X32);
    // 0x80800B20: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80800B24: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x80800B28: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800B2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800B30: sb          $t9, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r25;
    // 0x80800B34: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80800B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B3C:
    // 0x80800B3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B44: jr          $ra
    // 0x80800B48: nop

    return;
    // 0x80800B48: nop

;}
RECOMP_FUNC void func_8080018C_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800194: jal         0x80800000
    // 0x80800198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_bsride(rdram, ctx);
        goto after_0;
    // 0x80800198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080019C: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808001A0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808001A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001A8: jal         0x8008CB3C
    // 0x808001AC: addiu       $a1, $zero, 0x256
    ctx->r5 = ADD32(0, 0X256);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808001AC: addiu       $a1, $zero, 0x256
    ctx->r5 = ADD32(0, 0X256);
    after_1:
    // 0x808001B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001B4: jal         0x8009C128
    // 0x808001B8: addiu       $a1, $a0, 0x16C
    ctx->r5 = ADD32(ctx->r4, 0X16C);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x808001B8: addiu       $a1, $a0, 0x16C
    ctx->r5 = ADD32(ctx->r4, 0X16C);
    after_2:
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void _bskazjump_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083490: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083490);
    return;
    // 0x80083494: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void baanim_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C894: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C89C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8008C8A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8008C8A4: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8008C8A8: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8008C8AC: beq         $at, $zero, L_8008C914
    if (ctx->r1 == 0) {
        // 0x8008C8B0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8008C914;
    }
    // 0x8008C8B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008C8B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C8B8: addu        $at, $at, $t6
    gpr jr_addend_8008C8C0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008C8BC: lw          $t6, 0x4AB0($at)
    ctx->r14 = ADD32(ctx->r1, 0X4AB0);
    // 0x8008C8C0: jr          $t6
    // 0x8008C8C4: nop

    switch (jr_addend_8008C8C0 >> 2) {
        case 0: goto L_8008C914; break;
        case 1: goto L_8008C8E8; break;
        case 2: goto L_8008C8C8; break;
        case 3: goto L_8008C8D8; break;
        case 4: goto L_8008C8F8; break;
        default: switch_error(__func__, 0x8008C8C0, 0x80124AB0);
    }
    // 0x8008C8C4: nop

L_8008C8C8:
    // 0x8008C8C8: jal         0x8008C2A8
    // 0x8008C8CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    __baanim_update_scaleToHorizontalVelocity(rdram, ctx);
        goto after_0;
    // 0x8008C8CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8008C8D0: b           L_8008C918
    // 0x8008C8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008C918;
    // 0x8008C8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008C8D8:
    // 0x8008C8D8: jal         0x8008C37C
    // 0x8008C8DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    __baanim_update_scaleToVerticalVelocity(rdram, ctx);
        goto after_1;
    // 0x8008C8DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8008C8E0: b           L_8008C918
    // 0x8008C8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008C918;
    // 0x8008C8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008C8E8:
    // 0x8008C8E8: jal         0x8008ADE4
    // 0x8008C8EC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_8008ADE4(rdram, ctx);
        goto after_2;
    // 0x8008C8EC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_2:
    // 0x8008C8F0: b           L_8008C918
    // 0x8008C8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008C918;
    // 0x8008C8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008C8F8:
    // 0x8008C8F8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8008C8FC: jal         0x8008ADE4
    // 0x8008C900: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8008ADE4(rdram, ctx);
        goto after_3;
    // 0x8008C900: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_3:
    // 0x8008C904: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008C908: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8008C90C: jal         0x8008ADE4
    // 0x8008C910: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    func_8008ADE4(rdram, ctx);
        goto after_4;
    // 0x8008C910: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    after_4:
L_8008C914:
    // 0x8008C914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008C918:
    // 0x8008C918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C91C: jr          $ra
    // 0x8008C920: nop

    return;
    // 0x8008C920: nop

;}
RECOMP_FUNC void func_80801718_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080171C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801720: jal         0x80090A2C
    // 0x80801724: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090A2C(rdram, ctx);
        goto after_0;
    // 0x80801724: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801728: jal         0x800951B4
    // 0x8080172C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x8080172C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801730: jal         0x80800448
    // 0x80801734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80801734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080173C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801740: jr          $ra
    // 0x80801744: nop

    return;
    // 0x80801744: nop

;}
RECOMP_FUNC void func_808008E0_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808008F0: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x808008F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008FC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80800900: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800904: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800908: bgez        $t8, L_80800964
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080090C: nop
    
            goto L_80800964;
    }
    // 0x8080090C: nop

    // 0x80800910: jal         0x80089BF0
    // 0x80800914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800914: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800918: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080091C: jal         0x80101F24
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_1;
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800924: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(896, 0X11FC) << 16);
    // 0x80800928: addiu       $a1, $a1, 0x11FC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(896, 0X11FC));
    // 0x8080092C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800930: jal         0x800F3780
    // 0x80800934: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_2;
    // 0x80800934: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80800938: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080093C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800940: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800944: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800948: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080094C: nop

    // 0x80800950: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80800954: nop

    // 0x80800958: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8080095C: b           L_8080099C
    // 0x80800960: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_8080099C;
    // 0x80800960: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80800964:
    // 0x80800964: jal         0x80101F24
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_3;
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080096C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(896, 0X11FC) << 16);
    // 0x80800970: addiu       $a1, $a1, 0x11FC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(896, 0X11FC));
    // 0x80800974: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800978: jal         0x800F3780
    // 0x8080097C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_4;
    // 0x8080097C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x80800980: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800984: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800988: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080098C: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800990: nop

    // 0x80800994: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800998: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_8080099C:
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A0: jal         0x80800740
    // 0x808009A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80800740_chonearmbandit(rdram, ctx);
        goto after_5;
    // 0x808009A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x808009A8: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808009AC: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x808009B0: ori         $a1, $a1, 0x5025
    ctx->r5 = ctx->r5 | 0X5025;
    // 0x808009B4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x808009B8: bgez        $t1, L_808009D0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808009BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009D0;
    }
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C0: jal         0x8010B990
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_6;
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808009C8: b           L_808009DC
    // 0x808009CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_808009DC;
    // 0x808009CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_808009D0:
    // 0x808009D0: jal         0x8010B990
    // 0x808009D4: addiu       $a1, $zero, 0x5425
    ctx->r5 = ADD32(0, 0X5425);
    func_8010B990(rdram, ctx);
        goto after_7;
    // 0x808009D4: addiu       $a1, $zero, 0x5425
    ctx->r5 = ADD32(0, 0X5425);
    after_7:
    // 0x808009D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_808009DC:
    // 0x808009DC: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808009E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808009E4: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808009E8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x808009EC: nop

    // 0x808009F0: bc1fl       L_80800A00
    if (!c1cs) {
        // 0x808009F4: swc1        $f6, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
            goto L_80800A00;
    }
    goto skip_0;
    // 0x808009F4: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    skip_0:
    // 0x808009F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808009FC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80800A00:
    // 0x80800A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800A0C: jr          $ra
    // 0x80800A10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800A10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80800738_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080073C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800744: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800748: jal         0x80088078
    // 0x8080074C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080074C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800750: beq         $v0, $zero, L_8080077C
    if (ctx->r2 == 0) {
        // 0x80800754: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080077C;
    }
    // 0x80800754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800758: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x8080075C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800760: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800764: beq         $t6, $at, L_80800774
    if (ctx->r14 == ctx->r1) {
        // 0x80800768: nop
    
            goto L_80800774;
    }
    // 0x80800768: nop

    // 0x8080076C: jal         0x808007CC
    // 0x80800770: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808007CC_chmrsboggy(rdram, ctx);
        goto after_1;
    // 0x80800770: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80800774:
    // 0x80800774: b           L_80800780
    // 0x80800778: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800780;
    // 0x80800778: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8080077C:
    // 0x8080077C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800780:
    // 0x80800780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800788: jr          $ra
    // 0x8080078C: nop

    return;
    // 0x8080078C: nop

;}
RECOMP_FUNC void func_8010CB84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CB84: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010CB88: addiu       $a2, $a2, 0x6F50
    ctx->r6 = ADD32(ctx->r6, 0X6F50);
    // 0x8010CB8C: lh          $t6, 0xC($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XC);
    // 0x8010CB90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CB94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CB98: bne         $t6, $zero, L_8010CBA8
    if (ctx->r14 != 0) {
        // 0x8010CB9C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8010CBA8;
    }
    // 0x8010CB9C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8010CBA0: b           L_8010CBC0
    // 0x8010CBA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010CBC0;
    // 0x8010CBA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010CBA8:
    // 0x8010CBA8: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8010CBAC: nop

    // 0x8010CBB0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CBB4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010CBB8: jal         0x800F0064
    // 0x8010CBBC: nop

    func_800F0064(rdram, ctx);
        goto after_0;
    // 0x8010CBBC: nop

    after_0:
L_8010CBC0:
    // 0x8010CBC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CBC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CBC8: jr          $ra
    // 0x8010CBCC: nop

    return;
    // 0x8010CBCC: nop

;}
RECOMP_FUNC void func_800ABA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABA20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ABA24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800ABA28: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800ABA2C: lw          $s0, 0x798C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X798C);
    // 0x800ABA30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ABA34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800ABA38: beq         $s0, $zero, L_800ABA88
    if (ctx->r16 == 0) {
        // 0x800ABA3C: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_800ABA88;
    }
    // 0x800ABA3C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_800ABA40:
    // 0x800ABA40: jal         0x8001BAFC
    // 0x800ABA44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    defrag(rdram, ctx);
        goto after_0;
    // 0x800ABA44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800ABA48: beql        $v0, $s1, L_800ABA80
    if (ctx->r2 == ctx->r17) {
        // 0x800ABA4C: lw          $s0, 0x4($v0)
        ctx->r16 = MEM_W(ctx->r2, 0X4);
            goto L_800ABA80;
    }
    goto skip_0;
    // 0x800ABA4C: lw          $s0, 0x4($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x800ABA50: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800ABA54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ABA58: beq         $v1, $zero, L_800ABA68
    if (ctx->r3 == 0) {
        // 0x800ABA5C: nop
    
            goto L_800ABA68;
    }
    // 0x800ABA5C: nop

    // 0x800ABA60: b           L_800ABA6C
    // 0x800ABA64: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_800ABA6C;
    // 0x800ABA64: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800ABA68:
    // 0x800ABA68: sw          $v0, 0x798C($at)
    MEM_W(0X798C, ctx->r1) = ctx->r2;
L_800ABA6C:
    // 0x800ABA6C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800ABA70: beql        $v1, $zero, L_800ABA80
    if (ctx->r3 == 0) {
        // 0x800ABA74: lw          $s0, 0x4($v0)
        ctx->r16 = MEM_W(ctx->r2, 0X4);
            goto L_800ABA80;
    }
    goto skip_1;
    // 0x800ABA74: lw          $s0, 0x4($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x800ABA78: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800ABA7C: lw          $s0, 0x4($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X4);
L_800ABA80:
    // 0x800ABA80: bnel        $s0, $zero, L_800ABA40
    if (ctx->r16 != 0) {
        // 0x800ABA84: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_800ABA40;
    }
    goto skip_2;
    // 0x800ABA84: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    skip_2:
L_800ABA88:
    // 0x800ABA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABA8C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800ABA90: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800ABA94: jr          $ra
    // 0x800ABA98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800ABA98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8008AEDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AEDC: jr          $ra
    // 0x8008AEE0: addiu       $v0, $a0, 0x1C
    ctx->r2 = ADD32(ctx->r4, 0X1C);
    return;
    // 0x8008AEE0: addiu       $v0, $a0, 0x1C
    ctx->r2 = ADD32(ctx->r4, 0X1C);
;}
RECOMP_FUNC void func_808000E0_bsmumattack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000EC: lw          $t6, 0x164($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X164);
    // 0x808000F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000F4: beql        $t6, $zero, L_808001A4
    if (ctx->r14 == 0) {
        // 0x808000F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001A4;
    }
    goto skip_0;
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000FC: jal         0x80092C48
    // 0x80800100: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80092C48(rdram, ctx);
        goto after_0;
    // 0x80800100: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80800104: lw          $a0, 0x164($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X164);
    // 0x80800108: jal         0x800C8CB8
    // 0x8080010C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800C8CB8(rdram, ctx);
        goto after_1;
    // 0x8080010C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80800110: jal         0x8001210C
    // 0x80800114: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_2;
    // 0x80800114: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800118: beq         $v0, $zero, L_8080014C
    if (ctx->r2 == 0) {
        // 0x8080011C: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8080014C;
    }
    // 0x8080011C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800120: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800128: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x8080012C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800130: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800134: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80800138: nop

    // 0x8080013C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800140: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800144: b           L_80800170
    // 0x80800148: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80800170;
    // 0x80800148: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_8080014C:
    // 0x8080014C: lwc1        $f16, 0x16C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800150: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800154: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80800158: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8080015C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800160: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800164: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80800168: nop

    // 0x8080016C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_80800170:
    // 0x80800170: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800174: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800178: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080017C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800180: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80800184: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800188: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8080018C: jal         0x800C8D4C
    // 0x80800190: lw          $a0, 0x164($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X164);
    func_800C8D4C(rdram, ctx);
        goto after_3;
    // 0x80800190: lw          $a0, 0x164($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X164);
    after_3:
    // 0x80800194: lw          $a0, 0x164($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X164);
    // 0x80800198: jal         0x800C8E84
    // 0x8080019C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x8080019C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001A4:
    // 0x808001A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void dbmorph_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: jr          $ra
    // 0x80800054: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    return;
    // 0x80800054: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
;}
RECOMP_FUNC void func_800006A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800006A0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800006A4: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x800006A8: jal         0x80001B20
    // 0x800006AC: nop

    boot___osDisableInt(rdram, ctx);
        goto after_0;
    // 0x800006AC: nop

    after_0:
    // 0x800006B0: sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
    // 0x800006B4: jal         0x800006D4
    // 0x800006B8: nop

    func_800006D4(rdram, ctx);
        goto after_1;
    // 0x800006B8: nop

    after_1:
    // 0x800006BC: lw          $a0, 0x8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8);
    // 0x800006C0: jal         0x80001B90
    // 0x800006C4: nop

    boot___osRestoreInt(rdram, ctx);
        goto after_2;
    // 0x800006C4: nop

    after_2:
    // 0x800006C8: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x800006CC: jr          $ra
    // 0x800006D0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800006D0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void badust_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808008A4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808008A8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808008AC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808008B0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808008B4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808008B8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x808008BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008C0: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x808008C4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808008C8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808008CC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808008D0: bc1f        L_8080090C
    if (!c1cs) {
        // 0x808008D4: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_8080090C;
    }
    // 0x808008D4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808008D8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808008DC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x808008E0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808008E4: nop

    // 0x808008E8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_808008EC:
    // 0x808008EC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808008F0: jal         0x8080058C
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    badust_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808008F8: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x808008FC: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x80800900: nop

    // 0x80800904: bc1tl       L_808008EC
    if (c1cs) {
        // 0x80800908: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_808008EC;
    }
    goto skip_0;
    // 0x80800908: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
L_8080090C:
    // 0x8080090C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800910: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800914: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800918: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8080091C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800920: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800924: jr          $ra
    // 0x80800928: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800928: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80802940_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802948: jal         0x8080299C
    // 0x8080294C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080299C_chklungo(rdram, ctx);
        goto after_0;
    // 0x8080294C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802950: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80802954: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080295C: jal         0x80018820
    // 0x80802960: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_1;
    // 0x80802960: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_1:
    // 0x80802964: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80802968: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080296C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802970: jal         0x800E15CC
    // 0x80802974: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_800E15CC(rdram, ctx);
        goto after_2;
    // 0x80802974: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_2:
    // 0x80802978: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080297C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3CB8) << 16);
    // 0x80802980: addiu       $a2, $a2, 0x3CB8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3CB8));
    // 0x80802984: jal         0x80089D18
    // 0x80802988: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80802988: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x8080298C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802994: jr          $ra
    // 0x80802998: nop

    return;
    // 0x80802998: nop

;}
RECOMP_FUNC void gleeprom_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80800004: lw          $v0, -0x24B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X24B0);
    // 0x80800008: lui         $at, 0xBD1F
    ctx->r1 = S32(0XBD1F << 16);
    // 0x8080000C: ori         $at, $at, 0x416
    ctx->r1 = ctx->r1 | 0X416;
    // 0x80800010: xor         $t6, $v0, $at
    ctx->r14 = ctx->r2 ^ ctx->r1;
    // 0x80800014: jr          $ra
    // 0x80800018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80800018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void bstaxi_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B84: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800B88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B94: jal         0x8008CAC8
    // 0x80800B98: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    baanim_getTimer(rdram, ctx);
        goto after_0;
    // 0x80800B98: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    after_0:
    // 0x80800B9C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA4: jal         0x8009D3A8
    // 0x80800BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x80800BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800BAC: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    // 0x80800BB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB8: beq         $v0, $at, L_80800BEC
    if (ctx->r2 == ctx->r1) {
        // 0x80800BBC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800BEC;
    }
    // 0x80800BBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BC4: beq         $v0, $at, L_80800C80
    if (ctx->r2 == ctx->r1) {
        // 0x80800BC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C80;
    }
    // 0x80800BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800BD0: beq         $v0, $at, L_80800D30
    if (ctx->r2 == ctx->r1) {
        // 0x80800BD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D30;
    }
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800BDC: beq         $v0, $at, L_80800E00
    if (ctx->r2 == ctx->r1) {
        // 0x80800BE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E00;
    }
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE4: b           L_80800E90
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800E90;
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800BEC:
    // 0x80800BEC: jal         0x80098140
    // 0x80800BF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_2;
    // 0x80800BF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80800BF4: lui         $a1, 0x3DAC
    ctx->r5 = S32(0X3DAC << 16);
    // 0x80800BF8: ori         $a1, $a1, 0x831
    ctx->r5 = ctx->r5 | 0X831;
    // 0x80800BFC: jal         0x8008CB10
    // 0x80800C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_3;
    // 0x80800C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800C04: beq         $v0, $zero, L_80800C20
    if (ctx->r2 == 0) {
        // 0x80800C08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C20;
    }
    // 0x80800C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C0C: jal         0x80084538
    // 0x80800C10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _babackpack_set_state(rdram, ctx);
        goto after_4;
    // 0x80800C10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C18: jal         0x800A0CD0
    // 0x80800C1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CD0(rdram, ctx);
        goto after_5;
    // 0x80800C1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_80800C20:
    // 0x80800C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C24: jal         0x80091A58
    // 0x80800C28: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_6;
    // 0x80800C28: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x80800C2C: beq         $v0, $zero, L_80800C3C
    if (ctx->r2 == 0) {
        // 0x80800C30: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(392, 0X1F20) << 16);
            goto L_80800C3C;
    }
    // 0x80800C30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1F20) << 16);
    // 0x80800C34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800C38: sb          $t6, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = ctx->r14;
L_80800C3C:
    // 0x80800C3C: lwc1        $f4, 0x1F20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(392, 0X1F20));
    // 0x80800C40: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800C44: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800C48: nop

    // 0x80800C4C: bc1f        L_80800C60
    if (!c1cs) {
        // 0x80800C50: nop
    
            goto L_80800C60;
    }
    // 0x80800C50: nop

    // 0x80800C54: lbu         $t7, 0x15D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15D);
    // 0x80800C58: bnel        $t7, $zero, L_80800C70
    if (ctx->r15 != 0) {
        // 0x80800C5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C70;
    }
    goto skip_0;
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80800C60:
    // 0x80800C60: jal         0x8008CAEC
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_7;
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800C68: beq         $v0, $zero, L_80800E8C
    if (ctx->r2 == 0) {
        // 0x80800C6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E8C;
    }
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C70:
    // 0x80800C70: jal         0x80800A18
    // 0x80800C74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800A18_bstaxi(rdram, ctx);
        goto after_8;
    // 0x80800C74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800C78: b           L_80800E90
    // 0x80800C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800E90;
    // 0x80800C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C80:
    // 0x80800C80: jal         0x80091A58
    // 0x80800C84: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_9;
    // 0x80800C84: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_9:
    // 0x80800C88: bne         $v0, $zero, L_80800C9C
    if (ctx->r2 != 0) {
        // 0x80800C8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C9C;
    }
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C90: lbu         $t8, 0x15D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X15D);
    // 0x80800C94: beql        $t8, $zero, L_80800D10
    if (ctx->r24 == 0) {
        // 0x80800C98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D10;
    }
    goto skip_1;
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80800C9C:
    // 0x80800C9C: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
    // 0x80800CA0: jal         0x8009C128
    // 0x80800CA4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_8009C128(rdram, ctx);
        goto after_10;
    // 0x80800CA4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_10:
    // 0x80800CA8: jal         0x8009C984
    // 0x80800CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_11;
    // 0x80800CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800CB0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CB4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800CB8: jal         0x800EF1B8
    // 0x80800CBC: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_12;
    // 0x80800CBC: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    after_12:
    // 0x80800CC0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800CC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800CC8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800CCC: lui         $a3, 0x42
    ctx->r7 = S32(0X42 << 16);
    // 0x80800CD0: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80800CD4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800CD8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800CDC: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x80800CE0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800CE4: jal         0x800C6C94
    // 0x80800CE8: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    func_800C6C94(rdram, ctx);
        goto after_13;
    // 0x80800CE8: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x80800CEC: beq         $v0, $zero, L_80800D04
    if (ctx->r2 == 0) {
        // 0x80800CF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D04;
    }
    // 0x80800CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF4: jal         0x800FC6B0
    // 0x80800CF8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC6B0(rdram, ctx);
        goto after_14;
    // 0x80800CF8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_14:
    // 0x80800CFC: b           L_80800D10
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800D10;
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D04:
    // 0x80800D04: jal         0x80800A18
    // 0x80800D08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800A18_bstaxi(rdram, ctx);
        goto after_15;
    // 0x80800D08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D10:
    // 0x80800D10: jal         0x80091A30
    // 0x80800D14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_16;
    // 0x80800D14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800D18: beq         $v0, $zero, L_80800E8C
    if (ctx->r2 == 0) {
        // 0x80800D1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E8C;
    }
    // 0x80800D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D20: jal         0x80800A18
    // 0x80800D24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800A18_bstaxi(rdram, ctx);
        goto after_17;
    // 0x80800D24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
    // 0x80800D28: b           L_80800E90
    // 0x80800D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800E90;
    // 0x80800D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D30:
    // 0x80800D30: lui         $a1, 0x3E23
    ctx->r5 = S32(0X3E23 << 16);
    // 0x80800D34: jal         0x8008CB10
    // 0x80800D38: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    baanim_isAt(rdram, ctx);
        goto after_18;
    // 0x80800D38: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_18:
    // 0x80800D3C: beq         $v0, $zero, L_80800DAC
    if (ctx->r2 == 0) {
        // 0x80800D40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DAC;
    }
    // 0x80800D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D44: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800D48: jal         0x80084518
    // 0x80800D4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _babackpack_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x80800D4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80800D50: jal         0x80084768
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bapackctrl_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800D58: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D60: jal         0x80084780
    // 0x80800D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bapackctrl_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80800D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80800D68: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800D6C: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800D70: addiu       $t9, $zero, 0x6978
    ctx->r25 = ADD32(0, 0X6978);
    // 0x80800D74: addiu       $t0, $zero, 0x6D60
    ctx->r8 = ADD32(0, 0X6D60);
    // 0x80800D78: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800D7C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800D80: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800D84: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D8C: jal         0x8009DEC0
    // 0x80800D90: addiu       $a1, $zero, 0x53C
    ctx->r5 = ADD32(0, 0X53C);
    func_8009DEC0(rdram, ctx);
        goto after_22;
    // 0x80800D90: addiu       $a1, $zero, 0x53C
    ctx->r5 = ADD32(0, 0X53C);
    after_22:
    // 0x80800D94: jal         0x8009C984
    // 0x80800D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_23;
    // 0x80800D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800D9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800DA0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800DA4: jal         0x800CB5D4
    // 0x80800DA8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800CB5D4(rdram, ctx);
        goto after_24;
    // 0x80800DA8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_24:
L_80800DAC:
    // 0x80800DAC: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80800DB0: ori         $a1, $a1, 0xAE7D
    ctx->r5 = ctx->r5 | 0XAE7D;
    // 0x80800DB4: jal         0x8008CB10
    // 0x80800DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_25;
    // 0x80800DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800DBC: beq         $v0, $zero, L_80800DD8
    if (ctx->r2 == 0) {
        // 0x80800DC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DD8;
    }
    // 0x80800DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DC4: jal         0x80084538
    // 0x80800DC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_26;
    // 0x80800DC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD0: jal         0x800A0CD0
    // 0x80800DD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_27;
    // 0x80800DD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
L_80800DD8:
    // 0x80800DD8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1F24) << 16);
    // 0x80800DDC: lwc1        $f18, 0x1F24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(392, 0X1F24));
    // 0x80800DE0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800DE4: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x80800DE8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800DEC: nop

    // 0x80800DF0: bc1fl       L_80800E90
    if (!c1cs) {
        // 0x80800DF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E90;
    }
    goto skip_2;
    // 0x80800DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800DF8: b           L_80800E8C
    // 0x80800DFC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
        goto L_80800E8C;
    // 0x80800DFC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
L_80800E00:
    // 0x80800E00: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x80800E04: jal         0x8008CB10
    // 0x80800E08: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    baanim_isAt(rdram, ctx);
        goto after_28;
    // 0x80800E08: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    after_28:
    // 0x80800E0C: beq         $v0, $zero, L_80800E3C
    if (ctx->r2 == 0) {
        // 0x80800E10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E3C;
    }
    // 0x80800E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E14: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800E18: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800E1C: addiu       $t2, $zero, 0x55F0
    ctx->r10 = ADD32(0, 0X55F0);
    // 0x80800E20: addiu       $t3, $zero, 0x55F0
    ctx->r11 = ADD32(0, 0X55F0);
    // 0x80800E24: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800E28: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800E2C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800E30: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800E34: jal         0x8009DEC0
    // 0x80800E38: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    func_8009DEC0(rdram, ctx);
        goto after_29;
    // 0x80800E38: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    after_29:
L_80800E3C:
    // 0x80800E3C: lui         $a1, 0x3F01
    ctx->r5 = S32(0X3F01 << 16);
    // 0x80800E40: ori         $a1, $a1, 0x5B57
    ctx->r5 = ctx->r5 | 0X5B57;
    // 0x80800E44: jal         0x8008CB10
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_30;
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800E4C: beq         $v0, $zero, L_80800E68
    if (ctx->r2 == 0) {
        // 0x80800E50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E68;
    }
    // 0x80800E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E54: jal         0x80084538
    // 0x80800E58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_31;
    // 0x80800E58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x80800E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E60: jal         0x800A0CD0
    // 0x80800E64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_32;
    // 0x80800E64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
L_80800E68:
    // 0x80800E68: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1F28) << 16);
    // 0x80800E6C: lwc1        $f6, 0x1F28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(392, 0X1F28));
    // 0x80800E70: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800E74: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80800E78: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800E7C: nop

    // 0x80800E80: bc1fl       L_80800E90
    if (!c1cs) {
        // 0x80800E84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E90;
    }
    goto skip_3;
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800E88: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
L_80800E8C:
    // 0x80800E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E90:
    // 0x80800E90: jal         0x8009E5C8
    // 0x80800E94: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    bs_setState(rdram, ctx);
        goto after_33;
    // 0x80800E94: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_33:
    // 0x80800E98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800E9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800EA0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800EA4: jr          $ra
    // 0x80800EA8: nop

    return;
    // 0x80800EA8: nop

;}
RECOMP_FUNC void func_808000D4_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x808000DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000E4: beq         $a1, $at, L_80800110
    if (ctx->r5 == ctx->r1) {
        // 0x808000E8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800110;
    }
    // 0x808000E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000EC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808000F0: bne         $a1, $at, L_80800134
    if (ctx->r5 != ctx->r1) {
        // 0x808000F4: nop
    
            goto L_80800134;
    }
    // 0x808000F4: nop

    // 0x808000F8: jal         0x80101FDC
    // 0x808000FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x808000FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800100: jal         0x808007B8
    // 0x80800104: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808007B8_chcheatomenu(rdram, ctx);
        goto after_1;
    // 0x80800104: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800108: b           L_80800140
    // 0x8080010C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800140;
    // 0x8080010C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800110:
    // 0x80800110: jal         0x80101080
    // 0x80800114: nop

    func_80101080(rdram, ctx);
        goto after_2;
    // 0x80800114: nop

    after_2:
    // 0x80800118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800120: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    // 0x80800124: jal         0x8080052C
    // 0x80800128: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    func_8080052C_chcheatomenu(rdram, ctx);
        goto after_3;
    // 0x80800128: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    after_3:
    // 0x8080012C: b           L_80800140
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800140;
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800134:
    // 0x80800134: b           L_80800140
    // 0x80800138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800140;
    // 0x80800138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080013C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800140:
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801244: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80801248: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8080124C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80801250: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80801254: lh          $t7, 0x128($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X128);
    // 0x80801258: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8080125C: bnel        $v0, $t7, L_80801288
    if (ctx->r2 != ctx->r15) {
        // 0x80801260: sh          $v0, 0x128($v1)
        MEM_H(0X128, ctx->r3) = ctx->r2;
            goto L_80801288;
    }
    goto skip_0;
    // 0x80801260: sh          $v0, 0x128($v1)
    MEM_H(0X128, ctx->r3) = ctx->r2;
    skip_0:
    // 0x80801264: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x80801268: lh          $t9, 0x12A($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X12A);
    // 0x8080126C: bnel        $t8, $t9, L_80801288
    if (ctx->r24 != ctx->r25) {
        // 0x80801270: sh          $v0, 0x128($v1)
        MEM_H(0X128, ctx->r3) = ctx->r2;
            goto L_80801288;
    }
    goto skip_1;
    // 0x80801270: sh          $v0, 0x128($v1)
    MEM_H(0X128, ctx->r3) = ctx->r2;
    skip_1:
    // 0x80801274: lh          $t0, 0x4($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X4);
    // 0x80801278: lh          $t1, 0x12C($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X12C);
    // 0x8080127C: beq         $t0, $t1, L_80801298
    if (ctx->r8 == ctx->r9) {
        // 0x80801280: nop
    
            goto L_80801298;
    }
    // 0x80801280: nop

    // 0x80801284: sh          $v0, 0x128($v1)
    MEM_H(0X128, ctx->r3) = ctx->r2;
L_80801288:
    // 0x80801288: lh          $t2, 0x2($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X2);
    // 0x8080128C: sh          $t2, 0x12A($v1)
    MEM_H(0X12A, ctx->r3) = ctx->r10;
    // 0x80801290: lh          $t3, 0x4($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X4);
    // 0x80801294: sh          $t3, 0x12C($v1)
    MEM_H(0X12C, ctx->r3) = ctx->r11;
L_80801298:
    // 0x80801298: jr          $ra
    // 0x8080129C: nop

    return;
    // 0x8080129C: nop

;}
RECOMP_FUNC void func_808001F0_chcaptainblubber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808001F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800200: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800204: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800208: jal         0x8010C93C
    // 0x8080020C: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    func_8010C93C(rdram, ctx);
        goto after_0;
    // 0x8080020C: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_0:
    // 0x80800210: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x8080021C: bgez        $t8, L_8080023C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800220: nop
    
            goto L_8080023C;
    }
    // 0x80800220: nop

    // 0x80800224: jal         0x80100094
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080022C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800230: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800234: jal         0x800897D8
    // 0x80800238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_8080023C:
    // 0x8080023C: jal         0x800D1824
    // 0x80800240: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    func_800D1824(rdram, ctx);
        goto after_3;
    // 0x80800240: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_3:
    // 0x80800244: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800248: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x8080024C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80800250: sltiu       $at, $t1, 0xD
    ctx->r1 = ctx->r9 < 0XD ? 1 : 0;
    // 0x80800254: beq         $at, $zero, L_8080055C
    if (ctx->r1 == 0) {
        // 0x80800258: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8080055C;
    }
    // 0x80800258: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8080025C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1504) << 16);
    // 0x80800260: addu        $at, $at, $t1
    gpr jr_addend_80800268 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800264: lw          $t1, 0x1504($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1504));
    // 0x80800268: jr          $t1
    // 0x8080026C: nop

    switch (jr_addend_80800268 >> 2) {
        case 0: goto L_80800270; break;
        case 1: goto L_80800270; break;
        case 2: goto L_8080055C; break;
        case 3: goto L_8080055C; break;
        case 4: goto L_80800360; break;
        case 5: goto L_808003CC; break;
        case 6: goto L_80800438; break;
        case 7: goto L_80800494; break;
        case 8: goto L_808004CC; break;
        case 9: goto L_808004F4; break;
        case 10: goto L_8080055C; break;
        case 11: goto L_80800524; break;
        case 12: goto L_80800544; break;
        default: switch_error(__func__, 0x80800268, 0x80801504);
    }
    // 0x8080026C: nop

L_80800270:
    // 0x80800270: jal         0x800F54E4
    // 0x80800274: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800274: nop

    after_4:
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080027C: jal         0x800F64A4
    // 0x80800280: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_5;
    // 0x80800280: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_5:
    // 0x80800284: beql        $v0, $zero, L_80800318
    if (ctx->r2 == 0) {
        // 0x80800288: lwc1        $f16, 0x48($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80800318;
    }
    goto skip_0;
    // 0x80800288: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    skip_0:
    // 0x8080028C: jal         0x800DA298
    // 0x80800290: addiu       $a0, $zero, 0xDF
    ctx->r4 = ADD32(0, 0XDF);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800290: addiu       $a0, $zero, 0xDF
    ctx->r4 = ADD32(0, 0XDF);
    after_6:
    // 0x80800294: beql        $v0, $zero, L_808002DC
    if (ctx->r2 == 0) {
        // 0x80800298: lwc1        $f8, 0x48($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
            goto L_808002DC;
    }
    goto skip_1;
    // 0x80800298: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    skip_1:
    // 0x8080029C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808002A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808002A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808002A8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808002AC: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x808002B0: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x808002B4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808002B8: jal         0x8008A1E0
    // 0x808002BC: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x808002BC: nop

    after_7:
    // 0x808002C0: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x808002C4: nop
    
            goto L_8080055C;
    }
    // 0x808002C4: nop

    // 0x808002C8: jal         0x80800000
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chcaptainblubber(rdram, ctx);
        goto after_8;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808002D0: b           L_8080055C
    // 0x808002D4: nop

        goto L_8080055C;
    // 0x808002D4: nop

    // 0x808002D8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
L_808002DC:
    // 0x808002DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808002E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808002E4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808002E8: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x808002EC: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x808002F0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808002F4: jal         0x8008A1C8
    // 0x808002F8: nop

    _subaddiedialog_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x808002F8: nop

    after_9:
    // 0x808002FC: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x80800300: nop
    
            goto L_8080055C;
    }
    // 0x80800300: nop

    // 0x80800304: jal         0x80800000
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chcaptainblubber(rdram, ctx);
        goto after_10;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080030C: b           L_8080055C
    // 0x80800310: nop

        goto L_8080055C;
    // 0x80800310: nop

    // 0x80800314: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
L_80800318:
    // 0x80800318: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080031C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800320: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800324: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x80800328: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x8080032C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800330: jal         0x8008A1E0
    // 0x80800334: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_11;
    // 0x80800334: nop

    after_11:
    // 0x80800338: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x8080033C: addiu       $a1, $zero, 0x1208
        ctx->r5 = ADD32(0, 0X1208);
            goto L_8080055C;
    }
    // 0x8080033C: addiu       $a1, $zero, 0x1208
    ctx->r5 = ADD32(0, 0X1208);
    // 0x80800340: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800344: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x80800348: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080034C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800350: jal         0x8008A208
    // 0x80800354: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80800354: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x80800358: b           L_8080055C
    // 0x8080035C: nop

        goto L_8080055C;
    // 0x8080035C: nop

L_80800360:
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x80100094
    // 0x80800368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x80800368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x8080036C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80800378: jal         0x8008A0D0
    // 0x8080037C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x8080037C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_14:
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800388: jal         0x80089FE8
    // 0x8080038C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x8080038C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_15:
    // 0x80800390: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x80800394: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080055C;
    }
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: jal         0x80102424
    // 0x8080039C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x8080039C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_16:
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003A8: jal         0x80100074
    // 0x808003AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_17;
    // 0x808003AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x808003B0: jal         0x800F54E4
    // 0x808003B4: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x808003B4: nop

    after_18:
    // 0x808003B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003BC: jal         0x800F82D4
    // 0x808003C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F82D4(rdram, ctx);
        goto after_19;
    // 0x808003C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x808003C4: b           L_8080055C
    // 0x808003C8: nop

        goto L_8080055C;
    // 0x808003C8: nop

L_808003CC:
    // 0x808003CC: jal         0x80101DDC
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_20;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808003D4: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x808003D8: addiu       $a1, $zero, 0x100B
        ctx->r5 = ADD32(0, 0X100B);
            goto L_8080055C;
    }
    // 0x808003D8: addiu       $a1, $zero, 0x100B
    ctx->r5 = ADD32(0, 0X100B);
    // 0x808003DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808003E0: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x808003E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003E8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808003EC: jal         0x8008A208
    // 0x808003F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x808003F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x808003F4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800400: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x80800404: jal         0x80102424
    // 0x80800408: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x80800408: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_22:
    // 0x8080040C: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x80800410: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800414: lui         $at, 0xC204
    ctx->r1 = S32(0XC204 << 16);
    // 0x80800418: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080041C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800420: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800424: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800428: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8080042C: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80800430: b           L_8080055C
    // 0x80800434: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8080055C;
    // 0x80800434: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_80800438:
    // 0x80800438: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8080043C: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800440: jal         0x80101E14
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_23;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800448: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x8080044C: nop
    
            goto L_8080055C;
    }
    // 0x8080044C: nop

    // 0x80800450: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800454: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x80800458: bgez        $t1, L_8080055C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8080045C: nop
    
            goto L_8080055C;
    }
    // 0x8080045C: nop

    // 0x80800460: jal         0x800F54E4
    // 0x80800464: nop

    func_800F54E4(rdram, ctx);
        goto after_24;
    // 0x80800464: nop

    after_24:
    // 0x80800468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080046C: jal         0x800F82D4
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_25;
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800478: jal         0x80102424
    // 0x8080047C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x8080047C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_26:
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: jal         0x80105A9C
    // 0x80800488: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_80105A9C(rdram, ctx);
        goto after_27;
    // 0x80800488: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_27:
    // 0x8080048C: b           L_8080055C
    // 0x80800490: nop

        goto L_8080055C;
    // 0x80800490: nop

L_80800494:
    // 0x80800494: jal         0x80105834
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_28;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8080049C: jal         0x800A54C0
    // 0x808004A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800A54C0(rdram, ctx);
        goto after_29;
    // 0x808004A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_29:
    // 0x808004A4: lui         $a1, 0x3F57
    ctx->r5 = S32(0X3F57 << 16);
    // 0x808004A8: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    // 0x808004AC: jal         0x80105998
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105998(rdram, ctx);
        goto after_30;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808004B4: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x808004B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080055C;
    }
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: jal         0x80102424
    // 0x808004C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_31;
    // 0x808004C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_31:
    // 0x808004C4: b           L_8080055C
    // 0x808004C8: nop

        goto L_8080055C;
    // 0x808004C8: nop

L_808004CC:
    // 0x808004CC: jal         0x800A54C0
    // 0x808004D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800A54C0(rdram, ctx);
        goto after_32;
    // 0x808004D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_32:
    // 0x808004D4: jal         0x80101DDC
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_33;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x808004DC: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x808004E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080055C;
    }
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E4: jal         0x80102424
    // 0x808004E8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80102424(rdram, ctx);
        goto after_34;
    // 0x808004E8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_34:
    // 0x808004EC: b           L_8080055C
    // 0x808004F0: nop

        goto L_8080055C;
    // 0x808004F0: nop

L_808004F4:
    // 0x808004F4: jal         0x80105834
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_35;
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808004FC: jal         0x80105A5C
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_36;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800504: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x80800508: nop
    
            goto L_8080055C;
    }
    // 0x80800508: nop

    // 0x8080050C: jal         0x80085750
    // 0x80800510: nop

    _capod_entrypoint_22(rdram, ctx);
        goto after_37;
    // 0x80800510: nop

    after_37:
    // 0x80800514: jal         0x800FFA88
    // 0x80800518: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_38;
    // 0x80800518: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_38:
    // 0x8080051C: b           L_8080055C
    // 0x80800520: nop

        goto L_8080055C;
    // 0x80800520: nop

L_80800524:
    // 0x80800524: jal         0x80101DDC
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_39;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x8080052C: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x80800530: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080055C;
    }
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: jal         0x80102424
    // 0x80800538: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80102424(rdram, ctx);
        goto after_40;
    // 0x80800538: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_40:
    // 0x8080053C: b           L_8080055C
    // 0x80800540: nop

        goto L_8080055C;
    // 0x80800540: nop

L_80800544:
    // 0x80800544: jal         0x80101DDC
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_41;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x8080054C: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x80800550: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080055C;
    }
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: jal         0x80102424
    // 0x80800558: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80102424(rdram, ctx);
        goto after_42;
    // 0x80800558: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_42:
L_8080055C:
    // 0x8080055C: jal         0x80800A1C
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A1C_chcaptainblubber(rdram, ctx);
        goto after_43;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80800564: jal         0x8080143C
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080143C_chcaptainblubber(rdram, ctx);
        goto after_44;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x8080056C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800570: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800574: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800578: jr          $ra
    // 0x8080057C: nop

    return;
    // 0x8080057C: nop

;}
RECOMP_FUNC void _bsledge_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837C8: syscall     74
    recomp_syscall_handler(rdram, ctx, 0x800837C8);
    return;
    // 0x800837CC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808011A8_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808011AC: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x808011B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808011B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808011BC: beq         $a1, $at, L_808011E0
    if (ctx->r5 == ctx->r1) {
        // 0x808011C0: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808011E0;
    }
    // 0x808011C0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808011C4: addiu       $at, $zero, 0x10CF
    ctx->r1 = ADD32(0, 0X10CF);
    // 0x808011C8: beq         $a1, $at, L_808011F4
    if (ctx->r5 == ctx->r1) {
        // 0x808011CC: addiu       $at, $zero, 0x10D0
        ctx->r1 = ADD32(0, 0X10D0);
            goto L_808011F4;
    }
    // 0x808011CC: addiu       $at, $zero, 0x10D0
    ctx->r1 = ADD32(0, 0X10D0);
    // 0x808011D0: beq         $a1, $at, L_808011F4
    if (ctx->r5 == ctx->r1) {
        // 0x808011D4: nop
    
            goto L_808011F4;
    }
    // 0x808011D4: nop

    // 0x808011D8: b           L_80801244
    // 0x808011DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801244;
    // 0x808011DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011E0:
    // 0x808011E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808011E4: jal         0x80800970
    // 0x808011E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800970_chballoonburst(rdram, ctx);
        goto after_0;
    // 0x808011E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808011EC: b           L_80801244
    // 0x808011F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801244;
    // 0x808011F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011F4:
    // 0x808011F4: jal         0x80088368
    // 0x808011F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808011F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_1:
    // 0x808011FC: blez        $v0, L_80801224
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801200: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801224;
    }
    // 0x80801200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801204:
    // 0x80801204: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x80801208: jal         0x800F7C58
    // 0x8080120C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F7C58(rdram, ctx);
        goto after_2;
    // 0x8080120C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80801210: jal         0x80088368
    // 0x80801214: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80801214: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_3:
    // 0x80801218: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080121C: bnel        $at, $zero, L_80801204
    if (ctx->r1 != 0) {
        // 0x80801220: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801204;
    }
    goto skip_0;
    // 0x80801220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80801224:
    // 0x80801224: jal         0x8008A098
    // 0x80801228: nop

    _subaddiemulti_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80801228: nop

    after_4:
    // 0x8080122C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801230: jal         0x80101FDC
    // 0x80801234: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80801234: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x80801238: jal         0x80088180
    // 0x8080123C: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x8080123C: nop

    after_6:
    // 0x80801240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801244:
    // 0x80801244: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801248: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080124C: jr          $ra
    // 0x80801250: nop

    return;
    // 0x80801250: nop

;}
RECOMP_FUNC void func_8002C5B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C5B4: jr          $ra
    // 0x8002C5B8: nop

    return;
    // 0x8002C5B8: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E38: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E38);
    return;
    // 0x80083E3C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80800000_chmole_overworld(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: bne         $a1, $at, L_808000C4
    if (ctx->r5 != ctx->r1) {
        // 0x80800018: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808000C4;
    }
    // 0x80800018: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080001C: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80800020: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800024: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800028: bne         $t6, $at, L_808000B0
    if (ctx->r14 != ctx->r1) {
        // 0x8080002C: lui         $a3, 0x8080
        ctx->r7 = S32(RELOC_HI16(1784, 0X190) << 16);
            goto L_808000B0;
    }
    // 0x8080002C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1784, 0X190) << 16);
    // 0x80800030: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80800034: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1784, 0X1E0) << 16);
    // 0x80800038: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080003C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80800040: nop

    // 0x80800044: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800048: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8080004C: jal         0x800D1A6C
    // 0x80800050: lw          $a0, 0x1E0($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1784, 0X1E0));
    func_800D1A6C(rdram, ctx);
        goto after_0;
    // 0x80800050: lw          $a0, 0x1E0($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1784, 0X1E0));
    after_0:
    // 0x80800054: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800058: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8080005C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1784, 0X1E0) << 16);
    // 0x80800060: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800064: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80800068: nop

    // 0x8080006C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800070: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80800074: jal         0x800D1A04
    // 0x80800078: lw          $a0, 0x1E0($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1784, 0X1E0));
    func_800D1A04(rdram, ctx);
        goto after_1;
    // 0x80800078: lw          $a0, 0x1E0($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1784, 0X1E0));
    after_1:
    // 0x8080007C: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800080: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800084: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1784, 0X1E0) << 16);
    // 0x80800088: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080008C: subu        $a1, $t6, $v0
    ctx->r5 = SUB32(ctx->r14, ctx->r2);
    // 0x80800090: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80800094: nop

    // 0x80800098: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8080009C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x808000A0: jal         0x800D175C
    // 0x808000A4: lw          $a0, 0x1E0($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1784, 0X1E0));
    func_800D175C(rdram, ctx);
        goto after_2;
    // 0x808000A4: lw          $a0, 0x1E0($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1784, 0X1E0));
    after_2:
    // 0x808000A8: b           L_808000E0
    // 0x808000AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000E0;
    // 0x808000AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000B0:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x800899E8
    // 0x808000B8: addiu       $a3, $a3, 0x190
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1784, 0X190));
    _sumole_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808000B8: addiu       $a3, $a3, 0x190
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1784, 0X190));
    after_3:
    // 0x808000BC: b           L_808000E4
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000E4;
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C4:
    // 0x808000C4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1784, 0X190) << 16);
    // 0x808000C8: addiu       $a3, $a3, 0x190
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1784, 0X190));
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x800899E8
    // 0x808000D4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _sumole_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808000D4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x808000D8: b           L_808000E4
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000E4;
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000E0:
    // 0x808000E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000E4:
    // 0x808000E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void func_808000E4_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808000E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F4: jal         0x8008FE68
    // 0x808000F8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8008FE68(rdram, ctx);
        goto after_0;
    // 0x808000F8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x808000FC: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x80800100: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X1170) << 16);
    // 0x80800104: lwc1        $f14, 0x1170($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X1170));
    // 0x80800108: lwc1        $f12, 0x8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8080010C: jal         0x800F0F9C
    // 0x80800110: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    func_800F0F9C(rdram, ctx);
        goto after_1;
    // 0x80800110: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80800114: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800118: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080011C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800120: mul.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800124: jal         0x800137F4
    // 0x80800128: nop

    func_800137F4(rdram, ctx);
        goto after_2;
    // 0x80800128: nop

    after_2:
    // 0x8080012C: jal         0x80013788
    // 0x80800130: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_80013788(rdram, ctx);
        goto after_3;
    // 0x80800130: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80800134: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800138: lw          $t7, 0x18C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18C);
    // 0x8080013C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800140: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800144: lwc1        $f8, 0x18($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X18);
    // 0x80800148: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X1174) << 16);
    // 0x8080014C: lwc1        $f14, 0x1174($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X1174));
    // 0x80800150: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800154: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800158: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8080015C: jal         0x800F0F9C
    // 0x80800160: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_800F0F9C(rdram, ctx);
        goto after_4;
    // 0x80800160: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80800164: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800168: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080016C: jal         0x800F1214
    // 0x80800170: lui         $a2, 0x4302
    ctx->r6 = S32(0X4302 << 16);
    func_800F1214(rdram, ctx);
        goto after_5;
    // 0x80800170: lui         $a2, 0x4302
    ctx->r6 = S32(0X4302 << 16);
    after_5:
    // 0x80800174: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800178: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080017C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800180: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800184: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800190: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80800194: lw          $t8, 0x18C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18C);
    // 0x80800198: lwc1        $f16, 0x18($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8080019C: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x808001A0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808001A4: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x808001A8: lw          $t9, 0x18C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18C);
    // 0x808001AC: jal         0x80800050
    // 0x808001B0: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    func_80800050_bsdronexform(rdram, ctx);
        goto after_6;
    // 0x808001B0: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    after_6:
    // 0x808001B4: lw          $t0, 0x18C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18C);
    // 0x808001B8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808001BC: jal         0x800BA75C
    // 0x808001C0: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    func_800BA75C(rdram, ctx);
        goto after_7;
    // 0x808001C0: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    after_7:
    // 0x808001C4: lw          $t1, 0x18C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18C);
    // 0x808001C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001CC: jal         0x800BA22C
    // 0x808001D0: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    func_800BA22C(rdram, ctx);
        goto after_8;
    // 0x808001D0: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    after_8:
    // 0x808001D4: jal         0x8008FE68
    // 0x808001D8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8008FE68(rdram, ctx);
        goto after_9;
    // 0x808001D8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x808001DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808001E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001E4: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808001E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001F0: jal         0x800F13C4
    // 0x808001F4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800F13C4(rdram, ctx);
        goto after_10;
    // 0x808001F4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_10:
    // 0x808001F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800200: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800204: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800208: sub.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8080020C: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800210: jal         0x80013970
    // 0x80800214: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    func_80013970(rdram, ctx);
        goto after_11;
    // 0x80800214: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    after_11:
    // 0x80800218: lw          $t2, 0x18C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X18C);
    // 0x8080021C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800220: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X1178) << 16);
    // 0x80800224: lwc1        $f4, 0x18($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X18);
    // 0x80800228: lwc1        $f14, 0x1178($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X1178));
    // 0x8080022C: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800230: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800234: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80800238: jal         0x800F0F9C
    // 0x8080023C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    func_800F0F9C(rdram, ctx);
        goto after_12;
    // 0x8080023C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x80800240: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80800244: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800248: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080024C: jal         0x800F1214
    // 0x80800250: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F1214(rdram, ctx);
        goto after_13;
    // 0x80800250: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_13:
    // 0x80800254: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800258: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080025C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80800260: jal         0x800138D0
    // 0x80800264: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    func_800138D0(rdram, ctx);
        goto after_14;
    // 0x80800264: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x80800268: lw          $t3, 0x18C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X18C);
    // 0x8080026C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: lwc1        $f18, 0x18($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X18);
    // 0x80800278: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8080027C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80800280: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800284: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800288: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8080028C: lw          $t4, 0x18C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18C);
    // 0x80800290: jal         0x80800050
    // 0x80800294: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    func_80800050_bsdronexform(rdram, ctx);
        goto after_15;
    // 0x80800294: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    after_15:
    // 0x80800298: lw          $t5, 0x18C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X18C);
    // 0x8080029C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808002A0: jal         0x800BA75C
    // 0x808002A4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    func_800BA75C(rdram, ctx);
        goto after_16;
    // 0x808002A4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_16:
    // 0x808002A8: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x808002AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002B0: jal         0x800BA22C
    // 0x808002B4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BA22C(rdram, ctx);
        goto after_17;
    // 0x808002B4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_17:
    // 0x808002B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

;}
RECOMP_FUNC void chbkcart_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800750: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2464, 0X880) << 16);
    // 0x80800754: jr          $ra
    // 0x80800758: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2464, 0X880));
    return;
    // 0x80800758: addiu       $v0, $v0, 0x880
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2464, 0X880));
    // 0x8080075C: nop

;}
RECOMP_FUNC void func_800295D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800295D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800295D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800295D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800295DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800295E0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800295E4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800295E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800295EC: jal         0x8002C230
    // 0x800295F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8002C230(rdram, ctx);
        goto after_0;
    // 0x800295F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x800295F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800295F8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800295FC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80029600: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80029604: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80029608: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002960C: lui         $t9, 0xD00
    ctx->r25 = S32(0XD00 << 16);
    // 0x80029610: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80029614: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80029618: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8002961C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80029620: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80029624: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80029628: lui         $t3, 0x62E
    ctx->r11 = S32(0X62E << 16);
    // 0x8002962C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80029630: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80029634: lw          $t5, 0x11F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11F4);
    // 0x80029638: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002963C: lw          $t6, 0x48($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X48);
    // 0x80029640: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80029644: b           L_80029654
    // 0x80029648: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_80029654;
    // 0x80029648: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8002964C: b           L_80029654
    // 0x80029650: nop

        goto L_80029654;
    // 0x80029650: nop

L_80029654:
    // 0x80029654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029658: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002965C: jr          $ra
    // 0x80029660: nop

    return;
    // 0x80029660: nop

    // 0x80029664: nop

    // 0x80029668: nop

    // 0x8002966C: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A110: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A110);
    return;
    // 0x8008A114: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801590_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801590: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80801594: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801598: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080159C: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x808015A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808015A4: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x808015A8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808015AC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x808015B0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808015B4: jal         0x800EFB24
    // 0x808015B8: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x808015B8: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_0:
    // 0x808015BC: jal         0x800EEF94
    // 0x808015C0: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    func_800EEF94(rdram, ctx);
        goto after_1;
    // 0x808015C0: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_1:
    // 0x808015C4: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808015C8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808015CC: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x808015D0: add.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x808015D4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808015D8: nop

    // 0x808015DC: bc1f        L_80801610
    if (!c1cs) {
        // 0x808015E0: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80801610;
    }
    // 0x808015E0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808015E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808015E8: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x808015EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808015F0: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x808015F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808015F8: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x808015FC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801600: jal         0x80801324
    // 0x80801604: nop

    func_80801324_chwaspnestgame(rdram, ctx);
        goto after_2;
    // 0x80801604: nop

    after_2:
    // 0x80801608: b           L_80801630
    // 0x8080160C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
        goto L_80801630;
    // 0x8080160C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
L_80801610:
    // 0x80801610: add.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f16.fl;
    // 0x80801614: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80801618: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8080161C: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x80801620: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80801624: jal         0x80801324
    // 0x80801628: nop

    func_80801324_chwaspnestgame(rdram, ctx);
        goto after_3;
    // 0x80801628: nop

    after_3:
    // 0x8080162C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
L_80801630:
    // 0x80801630: jal         0x800EE7F8
    // 0x80801634: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80801634: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80801638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080163C: jal         0x808014BC
    // 0x80801640: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_808014BC_chwaspnestgame(rdram, ctx);
        goto after_5;
    // 0x80801640: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_5:
    // 0x80801644: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80801648: jal         0x800EEF94
    // 0x8080164C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EEF94(rdram, ctx);
        goto after_6;
    // 0x8080164C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_6:
    // 0x80801650: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80801654: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801658: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8080165C: nop

    // 0x80801660: bc1fl       L_8080167C
    if (!c1cs) {
        // 0x80801664: addiu       $a0, $sp, 0x4C
        ctx->r4 = ADD32(ctx->r29, 0X4C);
            goto L_8080167C;
    }
    goto skip_0;
    // 0x80801664: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    skip_0:
    // 0x80801668: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080166C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80801670: jal         0x80801324
    // 0x80801674: nop

    func_80801324_chwaspnestgame(rdram, ctx);
        goto after_7;
    // 0x80801674: nop

    after_7:
    // 0x80801678: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
L_8080167C:
    // 0x8080167C: jal         0x800EE7F8
    // 0x80801680: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80801680: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80801684: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80801688: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080168C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80801690: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80801694: bgez        $t8, L_808016AC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801698: nop
    
            goto L_808016AC;
    }
    // 0x80801698: nop

    // 0x8080169C: jal         0x800EE7F8
    // 0x808016A0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x808016A0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_9:
    // 0x808016A4: b           L_808016C4
    // 0x808016A8: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
        goto L_808016C4;
    // 0x808016A8: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
L_808016AC:
    // 0x808016AC: jal         0x800EE7F8
    // 0x808016B0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x808016B0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_10:
    // 0x808016B4: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x808016B8: jal         0x800EE7F8
    // 0x808016BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x808016BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x808016C0: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
L_808016C4:
    // 0x808016C4: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x808016C8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x808016CC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808016D0: jal         0x800BEF00
    // 0x808016D4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800BEF00(rdram, ctx);
        goto after_12;
    // 0x808016D4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_12:
    // 0x808016D8: beq         $v0, $zero, L_808017A0
    if (ctx->r2 == 0) {
        // 0x808016DC: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_808017A0;
    }
    // 0x808016DC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808016E0: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x808016E4: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    // 0x808016E8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808016EC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x808016F0: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x808016F4: xori        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 ^ 0X1;
    // 0x808016F8: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x808016FC: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x80801700: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80801704: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80801708: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    // 0x8080170C: jal         0x800F1988
    // 0x80801710: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800F1988(rdram, ctx);
        goto after_13;
    // 0x80801710: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_13:
    // 0x80801714: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801718: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(776, 0X2044) << 16);
    // 0x8080171C: addiu       $t9, $t9, 0x2044
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(776, 0X2044));
    // 0x80801720: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801724: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801728: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8080172C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801730: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801734: jal         0x800BABB8
    // 0x80801738: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    func_800BABB8(rdram, ctx);
        goto after_14;
    // 0x80801738: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x8080173C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801740: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801744: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801748: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080174C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801750: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801754: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80801758: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080175C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80801760: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80801764: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x80801768: sra         $a1, $t1, 16
    ctx->r5 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8080176C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80801770: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x80801774: sra         $a2, $t4, 16
    ctx->r6 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80801778: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x8080177C: jal         0x800BA77C
    // 0x80801780: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_15;
    // 0x80801780: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    after_15:
    // 0x80801784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801788: jal         0x800BA22C
    // 0x8080178C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_16;
    // 0x8080178C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80801790: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(776, 0X2068) << 16);
    // 0x80801794: addiu       $a1, $a1, 0x2068
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(776, 0X2068));
    // 0x80801798: jal         0x800C4AF0
    // 0x8080179C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800C4AF0(rdram, ctx);
        goto after_17;
    // 0x8080179C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_17:
L_808017A0:
    // 0x808017A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808017A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808017A8: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808017AC: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808017B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808017B4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808017B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808017BC: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x808017C0: nop

    // 0x808017C4: bc1fl       L_808017D4
    if (!c1cs) {
        // 0x808017C8: lw          $s0, 0x20($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X20);
            goto L_808017D4;
    }
    goto skip_1;
    // 0x808017C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x808017CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808017D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
L_808017D4:
    // 0x808017D4: jr          $ra
    // 0x808017D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x808017D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800C8F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8F10: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8F14: beq         $a0, $zero, L_800C8F34
    if (ctx->r4 == 0) {
        // 0x800C8F18: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800C8F34;
    }
    // 0x800C8F18: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C8F1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8F20: addiu       $a0, $a0, -0x54E4
    ctx->r4 = ADD32(ctx->r4, -0X54E4);
    // 0x800C8F24: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800C8F28: jal         0x800EE830
    // 0x800C8F2C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x800C8F2C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C8F30: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800C8F34:
    // 0x800C8F34: beq         $a3, $zero, L_800C8F54
    if (ctx->r7 == 0) {
        // 0x800C8F38: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800C8F54;
    }
    // 0x800C8F38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8F3C: addiu       $a0, $a0, -0x54D8
    ctx->r4 = ADD32(ctx->r4, -0X54D8);
    // 0x800C8F40: jal         0x800EE7F8
    // 0x800C8F44: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800C8F44: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x800C8F48: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8F4C: jal         0x800EF2A0
    // 0x800C8F50: addiu       $a0, $a0, -0x54D8
    ctx->r4 = ADD32(ctx->r4, -0X54D8);
    func_800EF2A0(rdram, ctx);
        goto after_2;
    // 0x800C8F50: addiu       $a0, $a0, -0x54D8
    ctx->r4 = ADD32(ctx->r4, -0X54D8);
    after_2:
L_800C8F54:
    // 0x800C8F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8F5C: jr          $ra
    // 0x800C8F60: nop

    return;
    // 0x800C8F60: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AC0: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AC0);
    return;
    // 0x80089AC4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chlagoonufoint_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A68: syscall     190
    recomp_syscall_handler(rdram, ctx, 0x80085A68);
    return;
    // 0x80085A6C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80802C0C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C14: jal         0x80802248
    // 0x80802C18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80802C18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802C1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802C20: jal         0x800F4AF4
    // 0x80802C24: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_800F4AF4(rdram, ctx);
        goto after_1;
    // 0x80802C24: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x80802C28: jal         0x80802C40
    // 0x80802C2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80802C40_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80802C2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80802C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802C34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802C38: jr          $ra
    // 0x80802C3C: nop

    return;
    // 0x80802C3C: nop

;}
RECOMP_FUNC void func_800F31DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F31DC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800F31E0: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x800F31E4: jr          $ra
    // 0x800F31E8: sw          $a3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r7;
    return;
    // 0x800F31E8: sw          $a3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void basub_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800998: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080099C: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x808009A0: jr          $ra
    // 0x808009A4: swc1        $f12, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808009A4: swc1        $f12, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800902BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800902BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800902C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800902C4: jal         0x800F54E4
    // 0x800902C8: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800902C8: nop

    after_0:
    // 0x800902CC: jal         0x800F70EC
    // 0x800902D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F70EC(rdram, ctx);
        goto after_1;
    // 0x800902D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800902D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800902D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800902DC: jr          $ra
    // 0x800902E0: nop

    return;
    // 0x800902E0: nop

;}
RECOMP_FUNC void func_80801118_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080111C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801124: lbu         $a1, 0x5F($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X5F);
    // 0x80801128: beql        $a1, $zero, L_80801154
    if (ctx->r5 == 0) {
        // 0x8080112C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801154;
    }
    goto skip_0;
    // 0x8080112C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801130: jal         0x800C3D78
    // 0x80801134: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    func_800C3D78(rdram, ctx);
        goto after_0;
    // 0x80801134: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_0:
    // 0x80801138: bne         $v0, $zero, L_80801150
    if (ctx->r2 != 0) {
        // 0x8080113C: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80801150;
    }
    // 0x8080113C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80801140: jal         0x800C2FDC
    // 0x80801144: lbu         $a0, 0x5F($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X5F);
    func_800C2FDC(rdram, ctx);
        goto after_1;
    // 0x80801144: lbu         $a0, 0x5F($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X5F);
    after_1:
    // 0x80801148: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080114C: sb          $zero, 0x5F($t8)
    MEM_B(0X5F, ctx->r24) = 0;
L_80801150:
    // 0x80801150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801154:
    // 0x80801154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801158: jr          $ra
    // 0x8080115C: nop

    return;
    // 0x8080115C: nop

;}
RECOMP_FUNC void func_800DC628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC628: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800DC62C: jr          $ra
    // 0x800DC630: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800DC630: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void bskaz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000DC: jal         0x8008E430
    // 0x808000E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E430(rdram, ctx);
        goto after_0;
    // 0x808000E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000E4: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000E8: nop
    
            goto L_808000F4;
    }
    // 0x808000E8: nop

    // 0x808000EC: b           L_80800138
    // 0x808000F0: addiu       $v0, $zero, 0x186
    ctx->r2 = ADD32(0, 0X186);
        goto L_80800138;
    // 0x808000F0: addiu       $v0, $zero, 0x186
    ctx->r2 = ADD32(0, 0X186);
L_808000F4:
    // 0x808000F4: jal         0x8008D3B0
    // 0x808000F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D3B0(rdram, ctx);
        goto after_1;
    // 0x808000F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000FC: beq         $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x80800100: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080010C;
    }
    // 0x80800100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: b           L_80800138
    // 0x80800108: addiu       $v0, $zero, 0x161
    ctx->r2 = ADD32(0, 0X161);
        goto L_80800138;
    // 0x80800108: addiu       $v0, $zero, 0x161
    ctx->r2 = ADD32(0, 0X161);
L_8080010C:
    // 0x8080010C: jal         0x800919F4
    // 0x80800110: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_2;
    // 0x80800110: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800114: beql        $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x80800118: addiu       $v0, $zero, 0xBD
        ctx->r2 = ADD32(0, 0XBD);
            goto L_80800138;
    }
    goto skip_0;
    // 0x80800118: addiu       $v0, $zero, 0xBD
    ctx->r2 = ADD32(0, 0XBD);
    skip_0:
    // 0x8080011C: jal         0x800C6E38
    // 0x80800120: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_800C6E38(rdram, ctx);
        goto after_3;
    // 0x80800120: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_3:
    // 0x80800124: beql        $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x80800128: addiu       $v0, $zero, 0xBD
        ctx->r2 = ADD32(0, 0XBD);
            goto L_80800138;
    }
    goto skip_1;
    // 0x80800128: addiu       $v0, $zero, 0xBD
    ctx->r2 = ADD32(0, 0XBD);
    skip_1:
    // 0x8080012C: b           L_80800138
    // 0x80800130: addiu       $v0, $zero, 0xC6
    ctx->r2 = ADD32(0, 0XC6);
        goto L_80800138;
    // 0x80800130: addiu       $v0, $zero, 0xC6
    ctx->r2 = ADD32(0, 0XC6);
    // 0x80800134: addiu       $v0, $zero, 0xBD
    ctx->r2 = ADD32(0, 0XBD);
L_80800138:
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080013C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void func_80802950_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802958: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8080295C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80802960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802964: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802968: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080296C: jal         0x80102BAC
    // 0x80802970: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    func_80102BAC(rdram, ctx);
        goto after_0;
    // 0x80802970: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_0:
    // 0x80802974: jal         0x80102CCC
    // 0x80802978: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80102CCC(rdram, ctx);
        goto after_1;
    // 0x80802978: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080297C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802984: jr          $ra
    // 0x80802988: nop

    return;
    // 0x80802988: nop

;}
RECOMP_FUNC void func_8080006C_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800074: jal         0x800DA298
    // 0x80800078: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800078: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    after_0:
    // 0x8080007C: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800080: addiu       $a0, $zero, 0x3E5
        ctx->r4 = ADD32(0, 0X3E5);
            goto L_8080008C;
    }
    // 0x80800080: addiu       $a0, $zero, 0x3E5
    ctx->r4 = ADD32(0, 0X3E5);
    // 0x80800084: b           L_80800090
    // 0x80800088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800090;
    // 0x80800088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080008C:
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800090:
    // 0x80800090: jal         0x800DA298
    // 0x80800094: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800094: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800098: beq         $v0, $zero, L_808000A8
    if (ctx->r2 == 0) {
        // 0x8080009C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_808000A8;
    }
    // 0x8080009C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: b           L_808000AC
    // 0x808000A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_808000AC;
    // 0x808000A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808000A8:
    // 0x808000A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808000AC:
    // 0x808000AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B4: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void glid_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800324: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800328: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080032C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800330: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800334: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800338: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8080033C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800340: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800344: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800348: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080034C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800350: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800354: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800358: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8080035C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80800360: jal         0x800B2190
    // 0x80800364: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    func_800B2190(rdram, ctx);
        goto after_0;
    // 0x80800364: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    after_0:
    // 0x80800368: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8080036C: jal         0x800D674C
    // 0x80800370: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80800370: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x80800374: jal         0x800B27A0
    // 0x80800378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27A0(rdram, ctx);
        goto after_2;
    // 0x80800378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080037C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80800380: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80800384: addiu       $v1, $s1, 0x1C
    ctx->r3 = ADD32(ctx->r17, 0X1C);
    // 0x80800388: blez        $a1, L_80800440
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8080038C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800440;
    }
    // 0x8080038C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800390:
    // 0x80800390: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80800394: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800398: bnel        $s0, $t6, L_80800434
    if (ctx->r16 != ctx->r14) {
        // 0x8080039C: lw          $t3, 0x4($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X4);
            goto L_80800434;
    }
    goto skip_0;
    // 0x8080039C: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x808003A0: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x808003A4: addiu       $s6, $v1, 0x8
    ctx->r22 = ADD32(ctx->r3, 0X8);
    // 0x808003A8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808003AC: addu        $s7, $t8, $v1
    ctx->r23 = ADD32(ctx->r24, ctx->r3);
    // 0x808003B0: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
    // 0x808003B4: sltu        $at, $s6, $s7
    ctx->r1 = ctx->r22 < ctx->r23 ? 1 : 0;
    // 0x808003B8: beq         $at, $zero, L_80800440
    if (ctx->r1 == 0) {
        // 0x808003BC: or          $s2, $s7, $zero
        ctx->r18 = ctx->r23 | 0;
            goto L_80800440;
    }
    // 0x808003BC: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x808003C0: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_808003C4:
    // 0x808003C4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x808003C8: lh          $t1, 0x2($s6)
    ctx->r9 = MEM_H(ctx->r22, 0X2);
    // 0x808003CC: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x808003D0: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x808003D4: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x808003D8: addu        $s3, $t2, $s0
    ctx->r19 = ADD32(ctx->r10, ctx->r16);
    // 0x808003DC: jal         0x800879F0
    // 0x808003E0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    _dbvtxnormal_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808003E0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_3:
    // 0x808003E4: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x808003E8: beq         $at, $zero, L_80800418
    if (ctx->r1 == 0) {
        // 0x808003EC: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80800418;
    }
    // 0x808003EC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_808003F0:
    // 0x808003F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808003F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003F8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x808003FC: jalr        $s5
    // 0x80800400: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r21)(rdram, ctx);
        goto after_4;
    // 0x80800400: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_4:
    // 0x80800404: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800408: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8080040C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80800410: bne         $at, $zero, L_808003F0
    if (ctx->r1 != 0) {
        // 0x80800414: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808003F0;
    }
    // 0x80800414: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80800418:
    // 0x80800418: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8080041C: sltu        $at, $s6, $s7
    ctx->r1 = ctx->r22 < ctx->r23 ? 1 : 0;
    // 0x80800420: bnel        $at, $zero, L_808003C4
    if (ctx->r1 != 0) {
        // 0x80800424: lh          $a1, 0x0($s6)
        ctx->r5 = MEM_H(ctx->r22, 0X0);
            goto L_808003C4;
    }
    goto skip_1;
    // 0x80800424: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    skip_1:
    // 0x80800428: b           L_80800444
    // 0x8080042C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80800444;
    // 0x8080042C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800430: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
L_80800434:
    // 0x80800434: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800438: bne         $at, $zero, L_80800390
    if (ctx->r1 != 0) {
        // 0x8080043C: addu        $v1, $v1, $t3
        ctx->r3 = ADD32(ctx->r3, ctx->r11);
            goto L_80800390;
    }
    // 0x8080043C: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
L_80800440:
    // 0x80800440: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800444:
    // 0x80800444: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800448: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080044C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800450: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800454: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800458: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8080045C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800460: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800464: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800468: jr          $ra
    // 0x8080046C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080046C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_808004DC_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808004E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808004EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004F0: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x808004F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(936, 0XD7C) << 16);
    // 0x808004F8: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x808004FC: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800500: addiu       $a2, $a2, 0xD7C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XD7C));
    // 0x80800504: jal         0x80089D20
    // 0x80800508: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800508: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8080050C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(936, 0XD88) << 16);
    // 0x80800510: lui         $a3, 0x3D23
    ctx->r7 = S32(0X3D23 << 16);
    // 0x80800514: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800518: addiu       $a2, $a2, 0xD88
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XD88));
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: jal         0x80089D20
    // 0x80800524: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800524: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80800528: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(936, 0XD94) << 16);
    // 0x8080052C: lui         $a3, 0x3DE1
    ctx->r7 = S32(0X3DE1 << 16);
    // 0x80800530: ori         $a3, $a3, 0x47AE
    ctx->r7 = ctx->r7 | 0X47AE;
    // 0x80800534: addiu       $a2, $a2, 0xD94
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XD94));
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080053C: jal         0x80089D20
    // 0x80800540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800544: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(936, 0XD60) << 16);
    // 0x80800548: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(936, 0XDAC) << 16);
    // 0x8080054C: addiu       $a3, $a3, 0xDAC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(936, 0XDAC));
    // 0x80800550: addiu       $a2, $a2, 0xD60
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XD60));
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800558: jal         0x80089D28
    // 0x8080055C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x8080055C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800560: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(936, 0XD6C) << 16);
    // 0x80800564: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(936, 0XDB8) << 16);
    // 0x80800568: addiu       $a3, $a3, 0xDB8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(936, 0XDB8));
    // 0x8080056C: addiu       $a2, $a2, 0xD6C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XD6C));
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800574: jal         0x80089D28
    // 0x80800578: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800578: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8080057C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(936, 0XDA0) << 16);
    // 0x80800580: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(936, 0XDCC) << 16);
    // 0x80800584: addiu       $a3, $a3, 0xDCC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(936, 0XDCC));
    // 0x80800588: addiu       $a2, $a2, 0xDA0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XDA0));
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: jal         0x80089D28
    // 0x80800594: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800594: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80800598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080059C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808005A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808005A4: jr          $ra
    // 0x808005A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808005A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _babackpack_get_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084520: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x80084520);
    return;
    // 0x80084524: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8080008C_chlagoonentrygate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800094: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800098: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080009C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808000A0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000A4: bne         $t7, $at, L_80800124
    if (ctx->r15 != ctx->r1) {
        // 0x808000A8: nop
    
            goto L_80800124;
    }
    // 0x808000A8: nop

    // 0x808000AC: lw          $t8, 0x64($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X64);
    // 0x808000B0: addiu       $a0, $a1, 0x34
    ctx->r4 = ADD32(ctx->r5, 0X34);
    // 0x808000B4: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x808000B8: bltz        $t0, L_808000F0
    if (SIGNED(ctx->r8) < 0) {
        // 0x808000BC: nop
    
            goto L_808000F0;
    }
    // 0x808000BC: nop

    // 0x808000C0: lui         $a0, 0x6650
    ctx->r4 = S32(0X6650 << 16);
    // 0x808000C4: ori         $a0, $a0, 0x9D6D
    ctx->r4 = ctx->r4 | 0X9D6D;
    // 0x808000C8: jal         0x800C3F48
    // 0x808000CC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800C3F48(rdram, ctx);
        goto after_0;
    // 0x808000CC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000D0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000D4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808000D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000DC: lbu         $t2, 0x65($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X65);
    // 0x808000E0: swc1        $f4, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f4.u32l;
    // 0x808000E4: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x808000E8: b           L_80800124
    // 0x808000EC: sb          $t3, 0x65($a1)
    MEM_B(0X65, ctx->r5) = ctx->r11;
        goto L_80800124;
    // 0x808000EC: sb          $t3, 0x65($a1)
    MEM_B(0X65, ctx->r5) = ctx->r11;
L_808000F0:
    // 0x808000F0: jal         0x800D90A4
    // 0x808000F4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x808000F4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x808000F8: beq         $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x808000FC: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800124;
    }
    // 0x808000FC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800100: lui         $a0, 0x6650
    ctx->r4 = S32(0X6650 << 16);
    // 0x80800104: ori         $a0, $a0, 0x9CA1
    ctx->r4 = ctx->r4 | 0X9CA1;
    // 0x80800108: jal         0x800C3F48
    // 0x8080010C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800C3F48(rdram, ctx);
        goto after_2;
    // 0x8080010C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800110: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800114: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080011C: nop

    // 0x80800120: swc1        $f6, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f6.u32l;
L_80800124:
    // 0x80800124: jal         0x80086240
    // 0x80800128: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800128: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void func_80800000_chmoley(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080000C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800010: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800014: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800018: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x8080001C: bgez        $t8, L_8080002C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800020: nop
    
            goto L_8080002C;
    }
    // 0x80800020: nop

    // 0x80800024: b           L_8080009C
    // 0x80800028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080009C;
    // 0x80800028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080002C:
    // 0x8080002C: beq         $a1, $at, L_80800054
    if (ctx->r5 == ctx->r1) {
        // 0x80800030: addiu       $at, $zero, 0x2F
        ctx->r1 = ADD32(0, 0X2F);
            goto L_80800054;
    }
    // 0x80800030: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80800034: beq         $a1, $at, L_80800054
    if (ctx->r5 == ctx->r1) {
        // 0x80800038: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_80800054;
    }
    // 0x80800038: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x8080003C: beq         $a1, $at, L_80800054
    if (ctx->r5 == ctx->r1) {
        // 0x80800040: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800054;
    }
    // 0x80800040: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800044: beq         $a1, $at, L_80800080
    if (ctx->r5 == ctx->r1) {
        // 0x80800048: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1556, 0XBD0) << 16);
            goto L_80800080;
    }
    // 0x80800048: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1556, 0XBD0) << 16);
    // 0x8080004C: b           L_8080009C
    // 0x80800050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080009C;
    // 0x80800050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800054:
    // 0x80800054: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    // 0x80800058: jal         0x80106790
    // 0x8080005C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080005C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800060: jal         0x80086938
    // 0x80800064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _chmolehill_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800068: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080006C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800070: jal         0x8010114C
    // 0x80800074: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_8010114C(rdram, ctx);
        goto after_2;
    // 0x80800074: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800078: b           L_808000A0
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000A0;
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800080:
    // 0x80800080: addiu       $a0, $a0, 0xBD0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1556, 0XBD0));
    // 0x80800084: jal         0x80088090
    // 0x80800088: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800088: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x8080008C: b           L_8080009C
    // 0x80800090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080009C;
    // 0x80800090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800094: b           L_8080009C
    // 0x80800098: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080009C;
    // 0x80800098: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080009C:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000A0:
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
