#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bskazglide_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(244, 0XAB0) << 16);
    // 0x80800500: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800504: jr          $ra
    // 0x80800508: lw          $v0, 0xAB0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAB0));
    return;
    // 0x80800508: lw          $v0, 0xAB0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAB0));
;}
RECOMP_FUNC void func_80800A74_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A74: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800A78: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800A7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800A84: addiu       $s1, $a0, 0x1
    ctx->r17 = ADD32(ctx->r4, 0X1);
    // 0x80800A88: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(752, 0X1118) << 16);
    // 0x80800A8C: addiu       $v1, $v1, 0x1118
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(752, 0X1118));
    // 0x80800A90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800A94: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800A98: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800A9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800AA0: mflo        $t6
    ctx->r14 = lo;
    // 0x80800AA4: addu        $s0, $v1, $t6
    ctx->r16 = ADD32(ctx->r3, ctx->r14);
    // 0x80800AA8: lh          $s3, 0x0($s0)
    ctx->r19 = MEM_H(ctx->r16, 0X0);
    // 0x80800AAC: multu       $s1, $a1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800AB0: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80800AB4: mflo        $t7
    ctx->r15 = lo;
    // 0x80800AB8: addu        $s0, $v1, $t7
    ctx->r16 = ADD32(ctx->r3, ctx->r15);
    // 0x80800ABC: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80800AC0: beql        $s3, $v0, L_80800B30
    if (ctx->r19 == ctx->r2) {
        // 0x80800AC4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B30;
    }
    goto skip_0;
    // 0x80800AC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_80800AC8:
    // 0x80800AC8: bnel        $s2, $v0, L_80800B00
    if (ctx->r18 != ctx->r2) {
        // 0x80800ACC: lh          $a0, 0x2($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X2);
            goto L_80800B00;
    }
    goto skip_1;
    // 0x80800ACC: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x80800AD0: blezl       $s1, L_80800B00
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80800AD4: lh          $a0, 0x2($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X2);
            goto L_80800B00;
    }
    goto skip_2;
    // 0x80800AD4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    skip_2:
    // 0x80800AD8: lh          $t8, -0xE($s0)
    ctx->r24 = MEM_H(ctx->r16, -0XE);
    // 0x80800ADC: beql        $s2, $t8, L_80800B00
    if (ctx->r18 == ctx->r24) {
        // 0x80800AE0: lh          $a0, 0x2($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X2);
            goto L_80800B00;
    }
    goto skip_3;
    // 0x80800AE0: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    skip_3:
    // 0x80800AE4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80800AE8:
    // 0x80800AE8: blez        $s1, L_80800AFC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80800AEC: addiu       $s0, $s0, -0xE
        ctx->r16 = ADD32(ctx->r16, -0XE);
            goto L_80800AFC;
    }
    // 0x80800AEC: addiu       $s0, $s0, -0xE
    ctx->r16 = ADD32(ctx->r16, -0XE);
    // 0x80800AF0: lh          $t9, -0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, -0XE);
    // 0x80800AF4: bnel        $s2, $t9, L_80800AE8
    if (ctx->r18 != ctx->r25) {
        // 0x80800AF8: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80800AE8;
    }
    goto skip_4;
    // 0x80800AF8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_4:
L_80800AFC:
    // 0x80800AFC: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_80800B00:
    // 0x80800B00: beql        $a0, $zero, L_80800B30
    if (ctx->r4 == 0) {
        // 0x80800B04: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B30;
    }
    goto skip_5;
    // 0x80800B04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80800B08: jal         0x800C6E38
    // 0x80800B0C: nop

    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x80800B0C: nop

    after_0:
    // 0x80800B10: bnel        $v0, $zero, L_80800B30
    if (ctx->r2 != 0) {
        // 0x80800B14: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B30;
    }
    goto skip_6;
    // 0x80800B14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80800B18: lh          $v0, 0xE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE);
    // 0x80800B1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800B20: addiu       $s0, $s0, 0xE
    ctx->r16 = ADD32(ctx->r16, 0XE);
    // 0x80800B24: bne         $s3, $v0, L_80800AC8
    if (ctx->r19 != ctx->r2) {
        // 0x80800B28: nop
    
            goto L_80800AC8;
    }
    // 0x80800B28: nop

    // 0x80800B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B30:
    // 0x80800B30: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800B34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800B38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800B3C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B40: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800B44: jr          $ra
    // 0x80800B48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800B48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _gczoombox_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B68: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B68);
    return;
    // 0x80087B6C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void _chpickups_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085890: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085890);
    return;
    // 0x80085894: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void sumultiscore_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F98: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80800F9C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80800FA0: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800FA4: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80800FA8: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x80800FAC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80800FB0: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80800FB4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800FB8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80800FBC: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80800FC0: sll         $t0, $v0, 5
    ctx->r8 = S32(ctx->r2 << 5);
    // 0x80800FC4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80800FC8: jr          $ra
    // 0x80800FCC: swc1        $f12, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f12.u32l;
    return;
    // 0x80800FCC: swc1        $f12, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800C1568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1568: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800C156C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1570: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C1574: jr          $ra
    // 0x800C1578: sw          $zero, -0x74F4($at)
    MEM_W(-0X74F4, ctx->r1) = 0;
    return;
    // 0x800C1578: sw          $zero, -0x74F4($at)
    MEM_W(-0X74F4, ctx->r1) = 0;
;}
RECOMP_FUNC void _bsclimb_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F18: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082F18);
    return;
    // 0x80082F1C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800A2540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2540: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A2544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2548: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A254C: jal         0x800A25D0
    // 0x800A2550: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800A25D0(rdram, ctx);
        goto after_0;
    // 0x800A2550: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A2554: bne         $v0, $zero, L_800A2580
    if (ctx->r2 != 0) {
        // 0x800A2558: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A2580;
    }
    // 0x800A2558: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A255C: jal         0x800A1F0C
    // 0x800A2560: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800A1F0C(rdram, ctx);
        goto after_1;
    // 0x800A2560: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x800A2564: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2568: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A256C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800A2570: jal         0x800DF5D8
    // 0x800A2574: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800DF5D8(rdram, ctx);
        goto after_2;
    // 0x800A2574: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800A2578: b           L_800A25C4
    // 0x800A257C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A25C4;
    // 0x800A257C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2580:
    // 0x800A2580: lw          $v0, 0xB4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB4);
    // 0x800A2584: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x800A2588: bnel        $t6, $zero, L_800A25B0
    if (ctx->r14 != 0) {
        // 0x800A258C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A25B0;
    }
    goto skip_0;
    // 0x800A258C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_0:
    // 0x800A2590: jal         0x800A235C
    // 0x800A2594: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800A235C(rdram, ctx);
        goto after_3;
    // 0x800A2594: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_3:
    // 0x800A2598: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A259C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A25A0: lw          $t8, 0xB4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XB4);
    // 0x800A25A4: sb          $t7, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r15;
    // 0x800A25A8: lw          $v0, 0xB4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB4);
    // 0x800A25AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800A25B0:
    // 0x800A25B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A25B4: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x800A25B8: jal         0x800DF660
    // 0x800A25BC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800DF660(rdram, ctx);
        goto after_4;
    // 0x800A25BC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x800A25C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A25C4:
    // 0x800A25C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A25C8: jr          $ra
    // 0x800A25CC: nop

    return;
    // 0x800A25CC: nop

;}
RECOMP_FUNC void func_80800820_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800820: jr          $ra
    // 0x80800824: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800824: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808003D8_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: lw          $t6, 0x1E4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E4);
    // 0x808003DC: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x808003E0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808003E4: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x808003E8: bgezl       $t8, L_80800434
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808003EC: c.le.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
            goto L_80800434;
    }
    goto skip_0;
    // 0x808003EC: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    skip_0:
    // 0x808003F0: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x808003F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003F8: bc1f        L_80800404
    if (!c1cs) {
        // 0x808003FC: nop
    
            goto L_80800404;
    }
    // 0x808003FC: nop

    // 0x80800400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800404:
    // 0x80800404: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x80800408: nop
    
            goto L_80800468;
    }
    // 0x80800408: nop

    // 0x8080040C: lwc1        $f4, 0x1EC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80800410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800414: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80800418: nop

    // 0x8080041C: bc1f        L_80800428
    if (!c1cs) {
        // 0x80800420: nop
    
            goto L_80800428;
    }
    // 0x80800420: nop

    // 0x80800424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800428:
    // 0x80800428: jr          $ra
    // 0x8080042C: nop

    return;
    // 0x8080042C: nop

    // 0x80800430: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
L_80800434:
    // 0x80800434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800438: bc1f        L_80800444
    if (!c1cs) {
        // 0x8080043C: nop
    
            goto L_80800444;
    }
    // 0x8080043C: nop

    // 0x80800440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800444:
    // 0x80800444: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x80800448: nop
    
            goto L_80800468;
    }
    // 0x80800448: nop

    // 0x8080044C: lwc1        $f6, 0x1EC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80800450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800454: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80800458: nop

    // 0x8080045C: bc1f        L_80800468
    if (!c1cs) {
        // 0x80800460: nop
    
            goto L_80800468;
    }
    // 0x80800460: nop

    // 0x80800464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800468:
    // 0x80800468: jr          $ra
    // 0x8080046C: nop

    return;
    // 0x8080046C: nop

;}
RECOMP_FUNC void func_8080037C_chchompaslunch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800384: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1548, 0X4A4) << 16);
    // 0x80800388: addiu       $a2, $a2, 0x4A4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1548, 0X4A4));
    // 0x8080038C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800390: jal         0x80089D20
    // 0x80800394: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800394: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080039C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

    // 0x808003A8: nop

    // 0x808003AC: nop

;}
RECOMP_FUNC void bsthrow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808000B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C0: jal         0x8008CABC
    // 0x808000C4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808000C4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    after_0:
    // 0x808000C8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x808000CC: jal         0x80084D40
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bahold_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000D4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808000D8: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x808000DC: bnel        $t6, $zero, L_808000F8
    if (ctx->r14 != 0) {
        // 0x808000E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F8;
    }
    goto skip_0;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000E4: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F4;
    }
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: jal         0x80084D48
    // 0x808000F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bahold_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808000F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_808000F4:
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000F8:
    // 0x808000F8: jal         0x8009C128
    // 0x808000FC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x808000FC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800104: jal         0x800A33CC
    // 0x80800108: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800A33CC(rdram, ctx);
        goto after_4;
    // 0x80800108: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_4:
    // 0x8080010C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800110: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800114: jal         0x800F1E6C
    // 0x80800118: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800F1E6C(rdram, ctx);
        goto after_5;
    // 0x80800118: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x8009C914
    // 0x80800124: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80800124: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800128: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x8080012C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800130: jal         0x8008B348
    // 0x80800134: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80800134: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_7:
    // 0x80800138: beq         $v0, $zero, L_80800160
    if (ctx->r2 == 0) {
        // 0x8080013C: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80800160;
    }
    // 0x8080013C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800140: beq         $t7, $zero, L_80800160
    if (ctx->r15 == 0) {
        // 0x80800144: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80800160;
    }
    // 0x80800144: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800148: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x8080014C: jal         0x80106790
    // 0x80800150: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80106790(rdram, ctx);
        goto after_8;
    // 0x80800150: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80800154: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
    // 0x80800158: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x8080015C: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
L_80800160:
    // 0x80800160: jal         0x8008B324
    // 0x80800164: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_isStopped(rdram, ctx);
        goto after_9;
    // 0x80800164: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_9:
    // 0x80800168: beq         $v0, $zero, L_80800178
    if (ctx->r2 == 0) {
        // 0x8080016C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800178;
    }
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800174: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_80800178:
    // 0x80800178: jal         0x8009E5C8
    // 0x8080017C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x8080017C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x80800180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800184: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800188: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void func_800B5DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5DDC: jal         0x800B5C7C
    // 0x800B5DE0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B5C7C(rdram, ctx);
        goto after_0;
    // 0x800B5DE0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x800B5DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B5DEC: jr          $ra
    // 0x800B5DF0: nop

    return;
    // 0x800B5DF0: nop

;}
RECOMP_FUNC void subaddiecustomhits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3246, 0X350) << 16);
    // 0x8080003C: jr          $ra
    // 0x80800040: addiu       $v0, $v0, 0x350
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3246, 0X350));
    return;
    // 0x80800040: addiu       $v0, $v0, 0x350
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3246, 0X350));
;}
RECOMP_FUNC void func_8001B668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B668: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001B66C: lw          $t6, -0x40E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X40E8);
    // 0x8001B670: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B678: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001B67C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8001B680: beq         $t6, $zero, L_8001B6A4
    if (ctx->r14 == 0) {
        // 0x8001B684: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8001B6A4;
    }
    // 0x8001B684: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001B688: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001B68C: addiu       $v1, $v1, -0x40E8
    ctx->r3 = ADD32(ctx->r3, -0X40E8);
    // 0x8001B690: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
L_8001B694:
    // 0x8001B694: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001B698: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001B69C: bnel        $t7, $zero, L_8001B694
    if (ctx->r15 != 0) {
        // 0x8001B6A0: lw          $t7, 0x8($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X8);
            goto L_8001B694;
    }
    goto skip_0;
    // 0x8001B6A0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    skip_0:
L_8001B6A4:
    // 0x8001B6A4: slti        $at, $a2, 0xFA
    ctx->r1 = SIGNED(ctx->r6) < 0XFA ? 1 : 0;
    // 0x8001B6A8: beq         $at, $zero, L_8001B700
    if (ctx->r1 == 0) {
        // 0x8001B6AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001B700;
    }
    // 0x8001B6AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B6B0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8001B6B4: addiu       $t9, $t9, -0x40F0
    ctx->r25 = ADD32(ctx->r25, -0X40F0);
    // 0x8001B6B8: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x8001B6BC: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8001B6C0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8001B6C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001B6C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001B6CC: jal         0x8001ACEC
    // 0x8001B6D0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    heap_alloc_sided(rdram, ctx);
        goto after_0;
    // 0x8001B6D0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001B6D4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8001B6D8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001B6DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001B6E0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8001B6E4: jal         0x8001B3A0
    // 0x8001B6E8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    func_8001B3A0(rdram, ctx);
        goto after_1;
    // 0x8001B6E8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    after_1:
    // 0x8001B6EC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B6F0: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x8001B6F4: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001B6F8: b           L_8001B700
    // 0x8001B6FC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8001B700;
    // 0x8001B6FC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8001B700:
    // 0x8001B700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B704: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B708: jr          $ra
    // 0x8001B70C: nop

    return;
    // 0x8001B70C: nop

;}
RECOMP_FUNC void func_808005CC_chamazonstadiumguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005D4: jal         0x8010D278
    // 0x808005D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010D278(rdram, ctx);
        goto after_0;
    // 0x808005D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005DC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808005E0: bne         $v0, $at, L_80800600
    if (ctx->r2 != ctx->r1) {
        // 0x808005E4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800600;
    }
    // 0x808005E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005E8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1900, 0X770) << 16);
    // 0x808005EC: addiu       $a2, $a2, 0x770
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1900, 0X770));
    // 0x808005F0: jal         0x8008A1E8
    // 0x808005F4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808005F4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x808005F8: b           L_80800614
    // 0x808005FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x808005FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800600:
    // 0x80800600: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1900, 0X78C) << 16);
    // 0x80800604: addiu       $a2, $a2, 0x78C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1900, 0X78C));
    // 0x80800608: jal         0x8008A1E8
    // 0x8080060C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x8080060C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x80800610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800614:
    // 0x80800614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800618: jr          $ra
    // 0x8080061C: nop

    return;
    // 0x8080061C: nop

;}
RECOMP_FUNC void func_8010FFA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FFA8: jr          $ra
    // 0x8010FFAC: lh          $v0, 0x16($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X16);
    return;
    // 0x8010FFAC: lh          $v0, 0x16($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X16);
;}
RECOMP_FUNC void func_8080008C_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800090: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: addiu       $a1, $a2, 0x34
    ctx->r5 = ADD32(ctx->r6, 0X34);
    // 0x8080009C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x808000A0: jal         0x800F1DF4
    // 0x808000A4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800F1DF4(rdram, ctx);
        goto after_0;
    // 0x808000A4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x808000A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808000AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808000B0: jal         0x800F1DCC
    // 0x808000B4: lwc1        $f14, 0x44($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X44);
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x808000B4: lwc1        $f14, 0x44($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X44);
    after_1:
    // 0x808000B8: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808000BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808000C4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808000C8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808000CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808000D0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808000D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000D8: bc1tl       L_808000FC
    if (c1cs) {
        // 0x808000DC: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_808000FC;
    }
    goto skip_0;
    // 0x808000DC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_0:
    // 0x808000E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000E4: nop

    // 0x808000E8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808000EC: nop

    // 0x808000F0: bc1fl       L_80800100
    if (!c1cs) {
        // 0x808000F4: c.lt.s      $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
            goto L_80800100;
    }
    goto skip_1;
    // 0x808000F4: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    skip_1:
    // 0x808000F8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_808000FC:
    // 0x808000FC: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
L_80800100:
    // 0x80800100: nop

    // 0x80800104: bc1fl       L_80800118
    if (!c1cs) {
        // 0x80800108: sb          $zero, 0x214($a2)
        MEM_B(0X214, ctx->r6) = 0;
            goto L_80800118;
    }
    goto skip_2;
    // 0x80800108: sb          $zero, 0x214($a2)
    MEM_B(0X214, ctx->r6) = 0;
    skip_2:
    // 0x8080010C: b           L_80800118
    // 0x80800110: sb          $t6, 0x214($a2)
    MEM_B(0X214, ctx->r6) = ctx->r14;
        goto L_80800118;
    // 0x80800110: sb          $t6, 0x214($a2)
    MEM_B(0X214, ctx->r6) = ctx->r14;
    // 0x80800114: sb          $zero, 0x214($a2)
    MEM_B(0X214, ctx->r6) = 0;
L_80800118:
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080011C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void func_80800CF8_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800CFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800D04: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800D08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D0C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800D10: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800D14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800D18: jal         0x80100094
    // 0x80800D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D20: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800D24: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800D28: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80800D2C: beq         $at, $zero, L_80800FCC
    if (ctx->r1 == 0) {
        // 0x80800D30: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800FCC;
    }
    // 0x80800D30: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800D34: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2216, 0X2138) << 16);
    // 0x80800D38: addu        $at, $at, $t6
    gpr jr_addend_80800D40 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800D3C: lw          $t6, 0x2138($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2216, 0X2138));
    // 0x80800D40: jr          $t6
    // 0x80800D44: nop

    switch (jr_addend_80800D40 >> 2) {
        case 0: goto L_80800D48; break;
        case 1: goto L_80800D58; break;
        case 2: goto L_80800D70; break;
        case 3: goto L_80800DC0; break;
        case 4: goto L_80800DE8; break;
        case 5: goto L_80800E24; break;
        case 6: goto L_80800E98; break;
        case 7: goto L_80800F80; break;
        default: switch_error(__func__, 0x80800D40, 0x80802138);
    }
    // 0x80800D44: nop

L_80800D48:
    // 0x80800D48: jal         0x80800138
    // 0x80800D4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800138_chfpsgame(rdram, ctx);
        goto after_1;
    // 0x80800D4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800D50: b           L_80800FD0
    // 0x80800D54: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
        goto L_80800FD0;
    // 0x80800D54: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_80800D58:
    // 0x80800D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D60: jal         0x8080000C
    // 0x80800D64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080000C_chfpsgame(rdram, ctx);
        goto after_2;
    // 0x80800D64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800D68: b           L_80800FD0
    // 0x80800D6C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
        goto L_80800FD0;
    // 0x80800D6C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_80800D70:
    // 0x80800D70: jal         0x80800138
    // 0x80800D74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800138_chfpsgame(rdram, ctx);
        goto after_3;
    // 0x80800D74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D7C: jal         0x8010A828
    // 0x80800D80: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8010A828(rdram, ctx);
        goto after_4;
    // 0x80800D80: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_4:
    // 0x80800D84: jal         0x80801814
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801814_chfpsgame(rdram, ctx);
        goto after_5;
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800D8C: jal         0x800F54E4
    // 0x80800D90: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80800D90: nop

    after_6:
    // 0x80800D94: jal         0x800F5410
    // 0x80800D98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_7;
    // 0x80800D98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800D9C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800DA0: beq         $v0, $at, L_80800DB0
    if (ctx->r2 == ctx->r1) {
        // 0x80800DA4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80800DB0;
    }
    // 0x80800DA4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800DA8: bnel        $v0, $at, L_80800FD0
    if (ctx->r2 != ctx->r1) {
        // 0x80800DAC: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_80800FD0;
    }
    goto skip_0;
    // 0x80800DAC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    skip_0:
L_80800DB0:
    // 0x80800DB0: jal         0x800FDC28
    // 0x80800DB4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800FDC28(rdram, ctx);
        goto after_8;
    // 0x80800DB4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_8:
    // 0x80800DB8: b           L_80800FD0
    // 0x80800DBC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
        goto L_80800FD0;
    // 0x80800DBC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_80800DC0:
    // 0x80800DC0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800DC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DC8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800DD8: jal         0x8080000C
    // 0x80800DDC: swc1        $f4, 0x554($t7)
    MEM_W(0X554, ctx->r15) = ctx->f4.u32l;
    func_8080000C_chfpsgame(rdram, ctx);
        goto after_9;
    // 0x80800DDC: swc1        $f4, 0x554($t7)
    MEM_W(0X554, ctx->r15) = ctx->f4.u32l;
    after_9:
    // 0x80800DE0: b           L_80800FD0
    // 0x80800DE4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
        goto L_80800FD0;
    // 0x80800DE4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_80800DE8:
    // 0x80800DE8: jal         0x80800138
    // 0x80800DEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800138_chfpsgame(rdram, ctx);
        goto after_10;
    // 0x80800DEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DF8: jal         0x8080000C
    // 0x80800DFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080000C_chfpsgame(rdram, ctx);
        goto after_11;
    // 0x80800DFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80800E00: jal         0x808018B0
    // 0x80800E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018B0_chfpsgame(rdram, ctx);
        goto after_12;
    // 0x80800E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800E08: jal         0x80801C9C
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C9C_chfpsgame(rdram, ctx);
        goto after_13;
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800E10: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80800E14: jal         0x80101238
    // 0x80800E18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101238(rdram, ctx);
        goto after_14;
    // 0x80800E18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800E1C: b           L_80800FD0
    // 0x80800E20: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
        goto L_80800FD0;
    // 0x80800E20: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_80800E24:
    // 0x80800E24: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80800E28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E2C: blez        $t8, L_80800E5C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800E30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E5C;
    }
    // 0x80800E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E34:
    // 0x80800E34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800E38: jal         0x808013DC
    // 0x80800E3C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_808013DC_chfpsgame(rdram, ctx);
        goto after_15;
    // 0x80800E3C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_15:
    // 0x80800E40: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E44: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800E48: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80800E4C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800E50: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80800E54: bnel        $at, $zero, L_80800E34
    if (ctx->r1 != 0) {
        // 0x80800E58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E34;
    }
    goto skip_1;
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80800E5C:
    // 0x80800E5C: jal         0x800FC6B0
    // 0x80800E60: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_16;
    // 0x80800E60: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_16:
    // 0x80800E64: jal         0x800F54E4
    // 0x80800E68: nop

    func_800F54E4(rdram, ctx);
        goto after_17;
    // 0x80800E68: nop

    after_17:
    // 0x80800E6C: jal         0x800F5410
    // 0x80800E70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_18;
    // 0x80800E70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
    // 0x80800E74: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800E78: beq         $v0, $at, L_80800E88
    if (ctx->r2 == ctx->r1) {
        // 0x80800E7C: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80800E88;
    }
    // 0x80800E7C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800E80: bnel        $v0, $at, L_80800FD0
    if (ctx->r2 != ctx->r1) {
        // 0x80800E84: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_80800FD0;
    }
    goto skip_2;
    // 0x80800E84: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    skip_2:
L_80800E88:
    // 0x80800E88: jal         0x800FDC28
    // 0x80800E8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_19;
    // 0x80800E8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x80800E90: b           L_80800FD0
    // 0x80800E94: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
        goto L_80800FD0;
    // 0x80800E94: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_80800E98:
    // 0x80800E98: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800EA4: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80800EA8: jal         0x800899A8
    // 0x80800EAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_20;
    // 0x80800EAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_20:
    // 0x80800EB0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800EB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800EB8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EBC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800EC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800EC4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800EC8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800ECC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800ED0: jal         0x80089988
    // 0x80800ED4: swc1        $f6, 0x554($t1)
    MEM_W(0X554, ctx->r9) = ctx->f6.u32l;
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80800ED4: swc1        $f6, 0x554($t1)
    MEM_W(0X554, ctx->r9) = ctx->f6.u32l;
    after_21:
    // 0x80800ED8: jal         0x80088368
    // 0x80800EDC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_22;
    // 0x80800EDC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_22:
    // 0x80800EE0: blez        $v0, L_80800F38
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800EE4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800F38;
    }
    // 0x80800EE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800EE8:
    // 0x80800EE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800EEC: jal         0x800899A8
    // 0x80800EF0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_23;
    // 0x80800EF0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_23:
    // 0x80800EF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800EF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800EFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800F00: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800F04: jal         0x800899B0
    // 0x80800F08: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    _sumultiscore_entrypoint_9(rdram, ctx);
        goto after_24;
    // 0x80800F08: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_24:
    // 0x80800F0C: beq         $s0, $s3, L_80800F20
    if (ctx->r16 == ctx->r19) {
        // 0x80800F10: slt         $at, $s3, $s0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_80800F20;
    }
    // 0x80800F10: slt         $at, $s3, $s0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80800F14: beq         $at, $zero, L_80800F20
    if (ctx->r1 == 0) {
        // 0x80800F18: nop
    
            goto L_80800F20;
    }
    // 0x80800F18: nop

    // 0x80800F1C: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
L_80800F20:
    // 0x80800F20: jal         0x80088368
    // 0x80800F24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_25;
    // 0x80800F24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_25:
    // 0x80800F28: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800F2C: bnel        $at, $zero, L_80800EE8
    if (ctx->r1 != 0) {
        // 0x80800F30: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800EE8;
    }
    goto skip_3;
    // 0x80800F30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_3:
    // 0x80800F34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80800F38:
    // 0x80800F38: jal         0x80088368
    // 0x80800F3C: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_26;
    // 0x80800F3C: nop

    after_26:
    // 0x80800F40: blez        $v0, L_80800FCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800F44: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800FCC;
    }
    // 0x80800F44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800F48:
    // 0x80800F48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800F4C: jal         0x800899A8
    // 0x80800F50: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_27;
    // 0x80800F50: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_27:
    // 0x80800F54: bne         $v0, $s3, L_80800F64
    if (ctx->r2 != ctx->r19) {
        // 0x80800F58: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800F64;
    }
    // 0x80800F58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800F5C: jal         0x800899B8
    // 0x80800F60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _sumultiscore_entrypoint_10(rdram, ctx);
        goto after_28;
    // 0x80800F60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_28:
L_80800F64:
    // 0x80800F64: jal         0x80088368
    // 0x80800F68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_29;
    // 0x80800F68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_29:
    // 0x80800F6C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800F70: bnel        $at, $zero, L_80800F48
    if (ctx->r1 != 0) {
        // 0x80800F74: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800F48;
    }
    goto skip_4;
    // 0x80800F74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_4:
    // 0x80800F78: b           L_80800FD0
    // 0x80800F7C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
        goto L_80800FD0;
    // 0x80800F7C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_80800F80:
    // 0x80800F80: jal         0x80088368
    // 0x80800F84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_30;
    // 0x80800F84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_30:
    // 0x80800F88: blez        $v0, L_80800FC4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800F8C: lw          $s2, 0x2C($sp)
        ctx->r18 = MEM_W(ctx->r29, 0X2C);
            goto L_80800FC4;
    }
    // 0x80800F8C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F90: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80800F94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800F98:
    // 0x80800F98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800F9C: jal         0x800899A8
    // 0x80800FA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_31;
    // 0x80800FA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_31:
    // 0x80800FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA8: jal         0x800AA20C
    // 0x80800FAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800AA20C(rdram, ctx);
        goto after_32;
    // 0x80800FAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_32:
    // 0x80800FB0: jal         0x80088368
    // 0x80800FB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_33;
    // 0x80800FB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_33:
    // 0x80800FB8: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800FBC: bnel        $at, $zero, L_80800F98
    if (ctx->r1 != 0) {
        // 0x80800FC0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800F98;
    }
    goto skip_5;
    // 0x80800FC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_5:
L_80800FC4:
    // 0x80800FC4: jal         0x80088180
    // 0x80800FC8: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_34;
    // 0x80800FC8: nop

    after_34:
L_80800FCC:
    // 0x80800FCC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
L_80800FD0:
    // 0x80800FD0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FD4: sw          $t2, 0x550($t3)
    MEM_W(0X550, ctx->r11) = ctx->r10;
    // 0x80800FD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800FDC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800FE0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800FE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800FEC: jr          $ra
    // 0x80800FF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800FF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bsbbarge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082788: syscall     11
    recomp_syscall_handler(rdram, ctx, 0x80082788);
    return;
    // 0x8008278C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808016C0_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808016C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808016C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808016CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808016D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808016D4: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x808016D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A2C) << 16);
    // 0x808016DC: lui         $a3, 0x3F70
    ctx->r7 = S32(0X3F70 << 16);
    // 0x808016E0: ori         $a3, $a3, 0xA3D7
    ctx->r7 = ctx->r7 | 0XA3D7;
    // 0x808016E4: addiu       $a2, $a2, 0x2A2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A2C));
    // 0x808016E8: jal         0x80089D20
    // 0x808016EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808016EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x808016F0: beq         $v0, $zero, L_8080171C
    if (ctx->r2 == 0) {
        // 0x808016F4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080171C;
    }
    // 0x808016F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808016F8: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808016FC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801700: jal         0x800E15CC
    // 0x80801704: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_1;
    // 0x80801704: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_1:
    // 0x80801708: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8080170C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801714: jal         0x80018820
    // 0x80801718: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_2;
    // 0x80801718: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
L_8080171C:
    // 0x8080171C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2BEC) << 16);
    // 0x80801720: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1060, 0X2C28) << 16);
    // 0x80801724: addiu       $a3, $a3, 0x2C28
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1060, 0X2C28));
    // 0x80801728: addiu       $a2, $a2, 0x2BEC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2BEC));
    // 0x8080172C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801730: jal         0x80089D28
    // 0x80801734: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80801734: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80801738: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A48) << 16);
    // 0x8080173C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1060, 0X2C14) << 16);
    // 0x80801740: addiu       $a3, $a3, 0x2C14
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1060, 0X2C14));
    // 0x80801744: addiu       $a2, $a2, 0x2A48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A48));
    // 0x80801748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080174C: jal         0x80089D28
    // 0x80801750: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80801750: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80801754: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2BF4) << 16);
    // 0x80801758: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1060, 0X2C34) << 16);
    // 0x8080175C: addiu       $a3, $a3, 0x2C34
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1060, 0X2C34));
    // 0x80801760: addiu       $a2, $a2, 0x2BF4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2BF4));
    // 0x80801764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801768: jal         0x80089D28
    // 0x8080176C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x8080176C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80801770: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2C04) << 16);
    // 0x80801774: lui         $a3, 0x3D8F
    ctx->r7 = S32(0X3D8F << 16);
    // 0x80801778: ori         $a3, $a3, 0x5C29
    ctx->r7 = ctx->r7 | 0X5C29;
    // 0x8080177C: addiu       $a2, $a2, 0x2C04
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2C04));
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801784: jal         0x80089D20
    // 0x80801788: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80801788: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8080178C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801790: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801794: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801798: jr          $ra
    // 0x8080179C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080179C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bswalk_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801284: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801288: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080128C: lui         $a2, 0x3EDC
    ctx->r6 = S32(0X3EDC << 16);
    // 0x80801290: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801294: ori         $a2, $a2, 0x28F6
    ctx->r6 = ctx->r6 | 0X28F6;
    // 0x80801298: jal         0x8008CB3C
    // 0x8080129C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x8080129C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x808012A0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808012A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808012A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808012AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808012B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808012B4: jal         0x8009FFD8
    // 0x808012B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x808012B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x808012BC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808012C0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808012C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808012C8: jal         0x8008C9BC
    // 0x808012CC: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_2;
    // 0x808012CC: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_2:
    // 0x808012D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X1508) << 16);
    // 0x808012D4: lwc1        $f4, 0x1508($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0X1508));
    // 0x808012D8: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x808012DC: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808012E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808012E4: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808012E8: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x808012EC: jal         0x8008C9F0
    // 0x808012F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_3;
    // 0x808012F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808012F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808012F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808012FC: jr          $ra
    // 0x80801300: nop

    return;
    // 0x80801300: nop

;}
RECOMP_FUNC void func_800E9E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9E8C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800E9E90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9E94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9E98: lw          $a0, 0x2DB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB4);
    // 0x800E9E9C: jal         0x800B42A0
    // 0x800E9EA0: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800B42A0(rdram, ctx);
        goto after_0;
    // 0x800E9EA0: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_0:
    // 0x800E9EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9EAC: jr          $ra
    // 0x800E9EB0: nop

    return;
    // 0x800E9EB0: nop

;}
RECOMP_FUNC void func_800E0A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E0A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E0A78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E0A7C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800E0A80: jal         0x8001B754
    // 0x800E0A84: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B754(rdram, ctx);
        goto after_0;
    // 0x800E0A84: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x800E0A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E0A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E0A90: jr          $ra
    // 0x800E0A94: nop

    return;
    // 0x800E0A94: nop

;}
RECOMP_FUNC void func_80802A00_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802A04: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80802A08: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80802A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802A10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802A14: jal         0x80802A2C
    // 0x80802A18: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    func_80802A2C_chinflatableboss(rdram, ctx);
        goto after_0;
    // 0x80802A18: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80802A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802A24: jr          $ra
    // 0x80802A28: nop

    return;
    // 0x80802A28: nop

;}
RECOMP_FUNC void func_800F6B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6B48: jal         0x800F690C
    // 0x800F6B4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F690C(rdram, ctx);
        goto after_0;
    // 0x800F6B4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6B50: beq         $v0, $zero, L_800F6B60
    if (ctx->r2 == 0) {
        // 0x800F6B54: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_800F6B60;
    }
    // 0x800F6B54: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800F6B58: b           L_800F6B84
    // 0x800F6B5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F6B84;
    // 0x800F6B5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F6B60:
    // 0x800F6B60: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800F6B64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6B68: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F6B6C: jal         0x800A4CA8
    // 0x800F6B70: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A4CA8(rdram, ctx);
        goto after_1;
    // 0x800F6B70: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_1:
    // 0x800F6B74: jal         0x80089418
    // 0x800F6B78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncba1p_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x800F6B78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800F6B7C: xori        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 ^ 0X3;
    // 0x800F6B80: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
L_800F6B84:
    // 0x800F6B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6B8C: jr          $ra
    // 0x800F6B90: nop

    return;
    // 0x800F6B90: nop

;}
RECOMP_FUNC void _chflamer_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860C8: syscall     277
    recomp_syscall_handler(rdram, ctx, 0x800860C8);
    return;
    // 0x800860CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80803A88_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803A90: jal         0x80088350
    // 0x80803A94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80803A94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80803A98: jal         0x80088348
    // 0x80803A9C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80803A9C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80803AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803AA8: jr          $ra
    // 0x80803AAC: nop

    return;
    // 0x80803AAC: nop

;}
RECOMP_FUNC void func_8008F4F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F4F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008F4F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F4F8: jal         0x8008EF3C
    // 0x8008F4FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8008EF3C(rdram, ctx);
        goto after_0;
    // 0x8008F4FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008F500: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8008F504: bne         $v0, $at, L_8008F52C
    if (ctx->r2 != ctx->r1) {
        // 0x8008F508: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008F52C;
    }
    // 0x8008F508: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008F50C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F510: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x8008F514: jal         0x80095738
    // 0x8008F518: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x8008F518: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8008F51C: beq         $v0, $zero, L_8008F52C
    if (ctx->r2 == 0) {
        // 0x8008F520: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8008F52C;
    }
    // 0x8008F520: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F524: b           L_8008F558
    // 0x8008F528: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8008F558;
    // 0x8008F528: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8008F52C:
    // 0x8008F52C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F530: bne         $v1, $at, L_8008F554
    if (ctx->r3 != ctx->r1) {
        // 0x8008F534: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8008F554;
    }
    // 0x8008F534: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F538: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    // 0x8008F53C: jal         0x80095738
    // 0x8008F540: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x8008F540: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8008F544: beq         $v0, $zero, L_8008F554
    if (ctx->r2 == 0) {
        // 0x8008F548: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8008F554;
    }
    // 0x8008F548: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F54C: b           L_8008F558
    // 0x8008F550: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8008F558;
    // 0x8008F550: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8008F554:
    // 0x8008F554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F558:
    // 0x8008F558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F55C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008F560: jr          $ra
    // 0x8008F564: nop

    return;
    // 0x8008F564: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CA8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CA8);
    return;
    // 0x80087CAC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801E80_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801E88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801E8C: jal         0x80100094
    // 0x80801E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801E94: beq         $v0, $zero, L_80801EA4
    if (ctx->r2 == 0) {
        // 0x80801E98: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801EA4;
    }
    // 0x80801E98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801E9C: jal         0x800897C8
    // 0x80801EA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80801EA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80801EA4:
    // 0x80801EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801EAC: jr          $ra
    // 0x80801EB0: nop

    return;
    // 0x80801EB0: nop

;}
RECOMP_FUNC void func_8080091C_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080091C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800924: jal         0x80800B28
    // 0x80800928: nop

    func_80800B28_chboggygirl(rdram, ctx);
        goto after_0;
    // 0x80800928: nop

    after_0:
    // 0x8080092C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800934: jr          $ra
    // 0x80800938: nop

    return;
    // 0x80800938: nop

;}
RECOMP_FUNC void func_80800420_chstinger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800420: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800424: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800428: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080042C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800430: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800434: jal         0x80100094
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080043C: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800440: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800444: jal         0x800D8FF8
    // 0x80800448: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800448: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080044C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80800450: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800454: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800458: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080045C: beq         $t6, $at, L_8080047C
    if (ctx->r14 == ctx->r1) {
        // 0x80800460: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080047C;
    }
    // 0x80800460: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800464: beq         $t6, $at, L_8080059C
    if (ctx->r14 == ctx->r1) {
        // 0x80800468: addiu       $t7, $s0, 0x4
        ctx->r15 = ADD32(ctx->r16, 0X4);
            goto L_8080059C;
    }
    // 0x80800468: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x8080046C: addiu       $t8, $s1, 0x18
    ctx->r24 = ADD32(ctx->r17, 0X18);
    // 0x80800470: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80800474: b           L_808005B4
    // 0x80800478: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_808005B4;
    // 0x80800478: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080047C:
    // 0x8080047C: lbu         $t9, 0x28($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X28);
    // 0x80800480: beql        $t9, $zero, L_80800498
    if (ctx->r25 == 0) {
        // 0x80800484: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800498;
    }
    goto skip_0;
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800488: sb          $zero, 0x28($s1)
    MEM_B(0X28, ctx->r17) = 0;
    // 0x8080048C: b           L_808004B4
    // 0x80800490: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
        goto L_808004B4;
    // 0x80800490: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800498:
    // 0x80800498: jal         0x8008A798
    // 0x8080049C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _sumissilehome_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x8080049C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808004A0: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x808004A4: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    // 0x808004A8: jal         0x8010B990
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_3;
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808004B0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_808004B4:
    // 0x808004B4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x808004B8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x808004BC: bnel        $t0, $at, L_808004D0
    if (ctx->r8 != ctx->r1) {
        // 0x808004C0: addiu       $t1, $s0, 0x4
        ctx->r9 = ADD32(ctx->r16, 0X4);
            goto L_808004D0;
    }
    goto skip_1;
    // 0x808004C0: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x808004C4: jal         0x8010AA78
    // 0x808004C8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_8010AA78(rdram, ctx);
        goto after_4;
    // 0x808004C8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808004CC: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
L_808004D0:
    // 0x808004D0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x808004D4: jal         0x80800218
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800218_chstinger(rdram, ctx);
        goto after_5;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808004DC: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x808004E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004E4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808004E8: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808004EC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808004F0: jal         0x800136E4
    // 0x808004F4: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x808004F4: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_6:
    // 0x808004F8: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x808004FC: jal         0x80103014
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_7;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800504: jal         0x8010A590
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_8;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080050C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800510: jal         0x800CB840
    // 0x80800514: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800CB840(rdram, ctx);
        goto after_9;
    // 0x80800514: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80800518: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080051C: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // 0x80800520: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800524: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800528: jal         0x800CD820
    // 0x8080052C: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    func_800CD820(rdram, ctx);
        goto after_10;
    // 0x8080052C: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_10:
    // 0x80800530: jal         0x800CB870
    // 0x80800534: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800CB870(rdram, ctx);
        goto after_11;
    // 0x80800534: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_11:
    // 0x80800538: jal         0x8010A570
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_12;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800540: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80800544: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80800548: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8080054C: beq         $t2, $at, L_80800570
    if (ctx->r10 == ctx->r1) {
        // 0x80800550: sltu        $t4, $zero, $t3
        ctx->r12 = 0 < ctx->r11 ? 1 : 0;
            goto L_80800570;
    }
    // 0x80800550: sltu        $t4, $zero, $t3
    ctx->r12 = 0 < ctx->r11 ? 1 : 0;
    // 0x80800554: bne         $t4, $zero, L_80800570
    if (ctx->r12 != 0) {
        // 0x80800558: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2152, 0X7C0) << 16);
            goto L_80800570;
    }
    // 0x80800558: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2152, 0X7C0) << 16);
    // 0x8080055C: lwc1        $f18, 0x7C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2152, 0X7C0));
    // 0x80800560: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80800564: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800568: nop

    // 0x8080056C: bc1f        L_8080057C
    if (!c1cs) {
        // 0x80800570: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080057C;
    }
L_80800570:
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800574: jal         0x8080015C
    // 0x80800578: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080015C_chstinger(rdram, ctx);
        goto after_13;
    // 0x80800578: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
L_8080057C:
    // 0x8080057C: jal         0x808003B0
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003B0_chstinger(rdram, ctx);
        goto after_14;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800584: beq         $v0, $zero, L_808005B4
    if (ctx->r2 == 0) {
        // 0x80800588: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005B4;
    }
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080058C: jal         0x8080015C
    // 0x80800590: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080015C_chstinger(rdram, ctx);
        goto after_15;
    // 0x80800590: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x80800594: b           L_808005B8
    // 0x80800598: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
        goto L_808005B8;
    // 0x80800598: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
L_8080059C:
    // 0x8080059C: jal         0x800FFAB0
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_16;
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808005A4: addiu       $t5, $s0, 0x4
    ctx->r13 = ADD32(ctx->r16, 0X4);
    // 0x808005A8: addiu       $t6, $s1, 0x18
    ctx->r14 = ADD32(ctx->r17, 0X18);
    // 0x808005AC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x808005B0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_808005B4:
    // 0x808005B4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
L_808005B8:
    // 0x808005B8: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808005BC: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808005C0: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
    // 0x808005C4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808005C8: jal         0x800EEAD4
    // 0x808005CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800EEAD4(rdram, ctx);
        goto after_17;
    // 0x808005CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x808005D0: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x808005D4: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x808005D8: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x808005DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808005E0: jal         0x800EE7F8
    // 0x808005E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_18;
    // 0x808005E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_18:
    // 0x808005E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808005F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808005F4: jr          $ra
    // 0x808005F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808005F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _ncpodfixpos_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896C0: syscall     786
    recomp_syscall_handler(rdram, ctx, 0x800896C0);
    return;
    // 0x800896C4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800A5B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5B9C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5BA0: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x800A5BA4: jr          $ra
    // 0x800A5BA8: lbu         $v0, 0x8($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X8);
    return;
    // 0x800A5BA8: lbu         $v0, 0x8($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X8);
;}
RECOMP_FUNC void func_80800DA4_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800DB0: jal         0x800DA298
    // 0x80800DB4: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800DB4: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    after_0:
    // 0x80800DB8: bnel        $v0, $zero, L_80800DCC
    if (ctx->r2 != 0) {
        // 0x80800DBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DCC;
    }
    goto skip_0;
    // 0x80800DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800DC0: jal         0x800DA544
    // 0x80800DC4: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800DC4: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    after_1:
    // 0x80800DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DCC:
    // 0x80800DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DD0: jr          $ra
    // 0x80800DD4: nop

    return;
    // 0x80800DD4: nop

;}
RECOMP_FUNC void func_808003E8_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808003F8: jal         0x800A5854
    // 0x808003FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A5854(rdram, ctx);
        goto after_0;
    // 0x808003FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800400: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800404: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800408: beq         $v0, $at, L_80800444
    if (ctx->r2 == ctx->r1) {
        // 0x8080040C: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80800444;
    }
    // 0x8080040C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800410: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800414: beq         $v0, $at, L_80800430
    if (ctx->r2 == ctx->r1) {
        // 0x80800418: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800430;
    }
    // 0x80800418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080041C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800420: beq         $v0, $at, L_80800430
    if (ctx->r2 == ctx->r1) {
        // 0x80800424: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800430;
    }
    // 0x80800424: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800428: bnel        $v0, $at, L_80800458
    if (ctx->r2 != ctx->r1) {
        // 0x8080042C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800458;
    }
    goto skip_0;
    // 0x8080042C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80800430:
    // 0x80800430: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80800434: jal         0x80085708
    // 0x80800438: addiu       $a3, $zero, 0x834
    ctx->r7 = ADD32(0, 0X834);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800438: addiu       $a3, $zero, 0x834
    ctx->r7 = ADD32(0, 0X834);
    after_1:
    // 0x8080043C: b           L_80800458
    // 0x80800440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800458;
    // 0x80800440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800444:
    // 0x80800444: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80800448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080044C: jal         0x80085748
    // 0x80800450: addiu       $a3, $zero, 0x814
    ctx->r7 = ADD32(0, 0X814);
    _capod_entrypoint_21(rdram, ctx);
        goto after_2;
    // 0x80800450: addiu       $a3, $zero, 0x814
    ctx->r7 = ADD32(0, 0X814);
    after_2:
    // 0x80800454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800458:
    // 0x80800458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080045C: jr          $ra
    // 0x80800460: nop

    return;
    // 0x80800460: nop

;}
RECOMP_FUNC void func_80800308_chtimetable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800308: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080030C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800310: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800314: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1592, 0X730) << 16);
    // 0x80800318: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1592, 0X80C) << 16);
    // 0x8080031C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800320: addiu       $s1, $s1, 0x80C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1592, 0X80C));
    // 0x80800324: addiu       $s0, $s0, 0x730
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1592, 0X730));
L_80800328:
    // 0x80800328: jal         0x800DA298
    // 0x8080032C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080032C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x80800330: beql        $v0, $zero, L_80800344
    if (ctx->r2 == 0) {
        // 0x80800334: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_80800344;
    }
    goto skip_0;
    // 0x80800334: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_0:
    // 0x80800338: b           L_80800350
    // 0x8080033C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80800350;
    // 0x8080033C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800340: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_80800344:
    // 0x80800344: bne         $s0, $s1, L_80800328
    if (ctx->r16 != ctx->r17) {
        // 0x80800348: nop
    
            goto L_80800328;
    }
    // 0x80800348: nop

    // 0x8080034C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800350:
    // 0x80800350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800354: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800358: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080035C: jr          $ra
    // 0x80800360: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800360: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800300_chklungodoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800300: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800308: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080030C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800314: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800318: beq         $a1, $at, L_808003C0
    if (ctx->r5 == ctx->r1) {
        // 0x8080031C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_808003C0;
    }
    // 0x8080031C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800320: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800324: beq         $a1, $at, L_808003F0
    if (ctx->r5 == ctx->r1) {
        // 0x80800328: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_808003F0;
    }
    // 0x80800328: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x8080032C: beq         $a1, $at, L_80800420
    if (ctx->r5 == ctx->r1) {
        // 0x80800330: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800420;
    }
    // 0x80800330: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800334: bnel        $a1, $at, L_8080045C
    if (ctx->r5 != ctx->r1) {
        // 0x80800338: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080045C;
    }
    goto skip_0;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080033C: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800340: addiu       $at, $zero, 0x41F
    ctx->r1 = ADD32(0, 0X41F);
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x8080034C: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80800350: beq         $t7, $at, L_80800368
    if (ctx->r15 == ctx->r1) {
        // 0x80800354: addiu       $at, $zero, 0x420
        ctx->r1 = ADD32(0, 0X420);
            goto L_80800368;
    }
    // 0x80800354: addiu       $at, $zero, 0x420
    ctx->r1 = ADD32(0, 0X420);
    // 0x80800358: beq         $t7, $at, L_80800394
    if (ctx->r15 == ctx->r1) {
        // 0x8080035C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800394;
    }
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800360: b           L_8080045C
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080045C;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800368:
    // 0x80800368: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x8080036C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800370: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1252, 0X498) << 16);
    // 0x80800374: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800378: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8080037C: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    // 0x80800380: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800384: jal         0x80103140
    // 0x80800388: lhu         $a1, 0x498($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1252, 0X498));
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800388: lhu         $a1, 0x498($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1252, 0X498));
    after_0:
    // 0x8080038C: b           L_80800458
    // 0x80800390: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
        goto L_80800458;
    // 0x80800390: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
L_80800394:
    // 0x80800394: lw          $t1, 0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28);
    // 0x80800398: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8080039C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1252, 0X49A) << 16);
    // 0x808003A0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x808003A4: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x808003A8: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    // 0x808003AC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808003B0: jal         0x80103140
    // 0x808003B4: lhu         $a1, 0x49A($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1252, 0X49A));
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x808003B4: lhu         $a1, 0x49A($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1252, 0X49A));
    after_1:
    // 0x808003B8: b           L_80800458
    // 0x808003BC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
        goto L_80800458;
    // 0x808003BC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
L_808003C0:
    // 0x808003C0: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x808003C4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1252, 0X49E) << 16);
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x808003D0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x808003D4: lbu         $t6, 0x49E($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(1252, 0X49E));
    // 0x808003D8: beql        $t6, $zero, L_8080045C
    if (ctx->r14 == 0) {
        // 0x808003DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080045C;
    }
    goto skip_1;
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808003E0: jal         0x8010A570
    // 0x808003E4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x808003E4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_2:
    // 0x808003E8: b           L_80800458
    // 0x808003EC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
        goto L_80800458;
    // 0x808003EC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
L_808003F0:
    // 0x808003F0: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x808003F4: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1252, 0X49E) << 16);
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80800400: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80800404: lbu         $t9, 0x49E($t9)
    ctx->r25 = MEM_BU(ctx->r25, (int16_t)RELOC_LO16(1252, 0X49E));
    // 0x80800408: beql        $t9, $zero, L_8080045C
    if (ctx->r25 == 0) {
        // 0x8080040C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080045C;
    }
    goto skip_2;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800410: jal         0x8010A570
    // 0x80800414: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x80800414: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800418: b           L_80800458
    // 0x8080041C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
        goto L_80800458;
    // 0x8080041C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
L_80800420:
    // 0x80800420: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800424: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800428: jal         0x800EC75C
    // 0x8080042C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EC75C(rdram, ctx);
        goto after_4;
    // 0x8080042C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_4:
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800434: jal         0x800862B8
    // 0x80800438: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _chelectricfence_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800438: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x8080043C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1252, 0X484) << 16);
    // 0x80800440: lwc1        $f4, 0x484($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1252, 0X484));
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: jal         0x8010A570
    // 0x8080044C: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x8080044C: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    after_6:
    // 0x80800450: b           L_80800468
    // 0x80800454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800468;
    // 0x80800454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800458:
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080045C:
    // 0x8080045C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800460: jal         0x80086248
    // 0x80800464: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800464: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_7:
L_80800468:
    // 0x80800468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080046C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800470: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800474: jr          $ra
    // 0x80800478: nop

    return;
    // 0x80800478: nop

    // 0x8080047C: nop

;}
RECOMP_FUNC void func_80800474_glrtc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800474: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800478: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080047C: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800480: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80800484: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800488: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8080048C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800490: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800494: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800498: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080049C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x808004A0: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x808004A4: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x808004A8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808004AC: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x808004B0: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x808004B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808004B8: sb          $t7, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r15;
    // 0x808004BC: lbu         $t8, 0x1($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X1);
    // 0x808004C0: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x808004C4: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x808004C8: sb          $t8, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r24;
    // 0x808004CC: lbu         $t9, 0x2($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X2);
    // 0x808004D0: addiu       $s7, $sp, 0x54
    ctx->r23 = ADD32(ctx->r29, 0X54);
    // 0x808004D4: addiu       $s2, $s2, 0x5
    ctx->r18 = ADD32(ctx->r18, 0X5);
    // 0x808004D8: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x808004DC: sb          $t0, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r8;
    // 0x808004E0: lbu         $t1, -0x3($s2)
    ctx->r9 = MEM_BU(ctx->r18, -0X3);
    // 0x808004E4: sb          $t1, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r9;
    // 0x808004E8: lbu         $t2, -0x2($s2)
    ctx->r10 = MEM_BU(ctx->r18, -0X2);
    // 0x808004EC: sb          $t2, 0x5E($sp)
    MEM_B(0X5E, ctx->r29) = ctx->r10;
    // 0x808004F0: lbu         $t3, -0x1($s2)
    ctx->r11 = MEM_BU(ctx->r18, -0X1);
    // 0x808004F4: sb          $t3, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r11;
    // 0x808004F8: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    // 0x808004FC: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x80800500: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
    // 0x80800504: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_80800508:
    // 0x80800508: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8080050C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800510: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80800514: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x80800518: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8080051C: srl         $t1, $a1, 5
    ctx->r9 = S32(U32(ctx->r5) >> 5);
    // 0x80800520: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80800524: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80800528: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8080052C: sw          $t1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r9;
    // 0x80800530: sb          $t0, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r8;
    // 0x80800534: bne         $t7, $t0, L_80800544
    if (ctx->r15 != ctx->r8) {
        // 0x80800538: sb          $t7, 0x50($sp)
        MEM_B(0X50, ctx->r29) = ctx->r15;
            goto L_80800544;
    }
    // 0x80800538: sb          $t7, 0x50($sp)
    MEM_B(0X50, ctx->r29) = ctx->r15;
    // 0x8080053C: b           L_80800554
    // 0x80800540: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
        goto L_80800554;
    // 0x80800540: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_80800544:
    // 0x80800544: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800548: jal         0x80031BF0
    // 0x8080054C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    _bcopy(rdram, ctx);
        goto after_0;
    // 0x8080054C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_0:
    // 0x80800550: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80800554:
    // 0x80800554: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80800558: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080055C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x80800560: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80800564: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80800568: jal         0x808005B0
    // 0x8080056C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_808005B0_glrtc(rdram, ctx);
        goto after_1;
    // 0x8080056C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x80800570: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800574: bnel        $s0, $s6, L_80800508
    if (ctx->r16 != ctx->r22) {
        // 0x80800578: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_80800508;
    }
    goto skip_0;
    // 0x80800578: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x8080057C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80800580: sw          $s2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r18;
    // 0x80800584: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800588: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8080058C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80800590: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800594: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800598: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8080059C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808005A0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808005A4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808005A8: jr          $ra
    // 0x808005AC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x808005AC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_808001F0_bsmumstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001F8: jal         0x80083800
    // 0x808001FC: nop

    _bsmum_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808001FC: nop

    after_0:
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void func_800EA170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA178: jal         0x800C718C
    // 0x800EA17C: nop

    func_800C718C(rdram, ctx);
        goto after_0;
    // 0x800EA17C: nop

    after_0:
    // 0x800EA180: jal         0x800D8744
    // 0x800EA184: nop

    func_800D8744(rdram, ctx);
        goto after_1;
    // 0x800EA184: nop

    after_1:
    // 0x800EA188: jal         0x800FA2C0
    // 0x800EA18C: nop

    func_800FA2C0(rdram, ctx);
        goto after_2;
    // 0x800EA18C: nop

    after_2:
    // 0x800EA190: jal         0x800A8184
    // 0x800EA194: nop

    func_800A8184(rdram, ctx);
        goto after_3;
    // 0x800EA194: nop

    after_3:
    // 0x800EA198: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800EA19C: beq         $v0, $at, L_800EA1AC
    if (ctx->r2 == ctx->r1) {
        // 0x800EA1A0: nop
    
            goto L_800EA1AC;
    }
    // 0x800EA1A0: nop

    // 0x800EA1A4: jal         0x800B7E38
    // 0x800EA1A8: nop

    func_800B7E38(rdram, ctx);
        goto after_4;
    // 0x800EA1A8: nop

    after_4:
L_800EA1AC:
    // 0x800EA1AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800EA1B0: lh          $t6, 0x2DCA($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2DCA);
    // 0x800EA1B4: bne         $t6, $zero, L_800EA1C4
    if (ctx->r14 != 0) {
        // 0x800EA1B8: nop
    
            goto L_800EA1C4;
    }
    // 0x800EA1B8: nop

    // 0x800EA1BC: b           L_800EA324
    // 0x800EA1C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EA324;
    // 0x800EA1C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EA1C4:
    // 0x800EA1C4: jal         0x800FFBE4
    // 0x800EA1C8: nop

    func_800FFBE4(rdram, ctx);
        goto after_5;
    // 0x800EA1C8: nop

    after_5:
    // 0x800EA1CC: jal         0x800EE718
    // 0x800EA1D0: nop

    func_800EE718(rdram, ctx);
        goto after_6;
    // 0x800EA1D0: nop

    after_6:
    // 0x800EA1D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800EA1D8: lw          $t7, 0x7EF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EF8);
    // 0x800EA1DC: beq         $t7, $zero, L_800EA1EC
    if (ctx->r15 == 0) {
        // 0x800EA1E0: nop
    
            goto L_800EA1EC;
    }
    // 0x800EA1E0: nop

    // 0x800EA1E4: jal         0x80088F18
    // 0x800EA1E8: nop

    _idworld_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x800EA1E8: nop

    after_7:
L_800EA1EC:
    // 0x800EA1EC: jal         0x800E97C0
    // 0x800EA1F0: nop

    func_800E97C0(rdram, ctx);
        goto after_8;
    // 0x800EA1F0: nop

    after_8:
    // 0x800EA1F4: jal         0x8010D7EC
    // 0x800EA1F8: nop

    func_8010D7EC(rdram, ctx);
        goto after_9;
    // 0x800EA1F8: nop

    after_9:
    // 0x800EA1FC: jal         0x800EE748
    // 0x800EA200: nop

    func_800EE748(rdram, ctx);
        goto after_10;
    // 0x800EA200: nop

    after_10:
    // 0x800EA204: jal         0x800F84FC
    // 0x800EA208: nop

    func_800F84FC(rdram, ctx);
        goto after_11;
    // 0x800EA208: nop

    after_11:
    // 0x800EA20C: jal         0x800BF710
    // 0x800EA210: nop

    func_800BF710(rdram, ctx);
        goto after_12;
    // 0x800EA210: nop

    after_12:
    // 0x800EA214: jal         0x800B592C
    // 0x800EA218: nop

    func_800B592C(rdram, ctx);
        goto after_13;
    // 0x800EA218: nop

    after_13:
    // 0x800EA21C: jal         0x8008B850
    // 0x800EA220: nop

    func_8008B850(rdram, ctx);
        goto after_14;
    // 0x800EA220: nop

    after_14:
    // 0x800EA224: jal         0x800E1804
    // 0x800EA228: nop

    func_800E1804(rdram, ctx);
        goto after_15;
    // 0x800EA228: nop

    after_15:
    // 0x800EA22C: jal         0x800A8E9C
    // 0x800EA230: nop

    func_800A8E9C(rdram, ctx);
        goto after_16;
    // 0x800EA230: nop

    after_16:
    // 0x800EA234: jal         0x800CF264
    // 0x800EA238: nop

    func_800CF264(rdram, ctx);
        goto after_17;
    // 0x800EA238: nop

    after_17:
    // 0x800EA23C: jal         0x800CE628
    // 0x800EA240: nop

    func_800CE628(rdram, ctx);
        goto after_18;
    // 0x800EA240: nop

    after_18:
    // 0x800EA244: jal         0x800D2574
    // 0x800EA248: nop

    func_800D2574(rdram, ctx);
        goto after_19;
    // 0x800EA248: nop

    after_19:
    // 0x800EA24C: jal         0x800EA09C
    // 0x800EA250: nop

    func_800EA09C(rdram, ctx);
        goto after_20;
    // 0x800EA250: nop

    after_20:
    // 0x800EA254: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EA258: bne         $v0, $at, L_800EA270
    if (ctx->r2 != ctx->r1) {
        // 0x800EA25C: nop
    
            goto L_800EA270;
    }
    // 0x800EA25C: nop

    // 0x800EA260: jal         0x800A1450
    // 0x800EA264: nop

    func_800A1450(rdram, ctx);
        goto after_21;
    // 0x800EA264: nop

    after_21:
    // 0x800EA268: jal         0x800DAE9C
    // 0x800EA26C: nop

    func_800DAE9C(rdram, ctx);
        goto after_22;
    // 0x800EA26C: nop

    after_22:
L_800EA270:
    // 0x800EA270: jal         0x800C57F0
    // 0x800EA274: nop

    func_800C57F0(rdram, ctx);
        goto after_23;
    // 0x800EA274: nop

    after_23:
    // 0x800EA278: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800EA27C: lw          $t8, 0x7EF0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7EF0);
    // 0x800EA280: beq         $t8, $zero, L_800EA290
    if (ctx->r24 == 0) {
        // 0x800EA284: nop
    
            goto L_800EA290;
    }
    // 0x800EA284: nop

    // 0x800EA288: jal         0x8008A8E8
    // 0x800EA28C: nop

    _sulights_entrypoint_9(rdram, ctx);
        goto after_24;
    // 0x800EA28C: nop

    after_24:
L_800EA290:
    // 0x800EA290: jal         0x800BFCC4
    // 0x800EA294: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BFCC4(rdram, ctx);
        goto after_25;
    // 0x800EA294: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_25:
    // 0x800EA298: jal         0x8001B50C
    // 0x800EA29C: nop

    func_8001B50C(rdram, ctx);
        goto after_26;
    // 0x800EA29C: nop

    after_26:
    // 0x800EA2A0: jal         0x800D6E54
    // 0x800EA2A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D6E54(rdram, ctx);
        goto after_27;
    // 0x800EA2A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_27:
    // 0x800EA2A8: jal         0x800ABA9C
    // 0x800EA2AC: nop

    func_800ABA9C(rdram, ctx);
        goto after_28;
    // 0x800EA2AC: nop

    after_28:
    // 0x800EA2B0: jal         0x800BFF70
    // 0x800EA2B4: nop

    func_800BFF70(rdram, ctx);
        goto after_29;
    // 0x800EA2B4: nop

    after_29:
    // 0x800EA2B8: jal         0x800B50F0
    // 0x800EA2BC: nop

    func_800B50F0(rdram, ctx);
        goto after_30;
    // 0x800EA2BC: nop

    after_30:
    // 0x800EA2C0: jal         0x800DBC68
    // 0x800EA2C4: nop

    func_800DBC68(rdram, ctx);
        goto after_31;
    // 0x800EA2C4: nop

    after_31:
    // 0x800EA2C8: jal         0x800E8A68
    // 0x800EA2CC: nop

    func_800E8A68(rdram, ctx);
        goto after_32;
    // 0x800EA2CC: nop

    after_32:
    // 0x800EA2D0: jal         0x800D5270
    // 0x800EA2D4: nop

    func_800D5270(rdram, ctx);
        goto after_33;
    // 0x800EA2D4: nop

    after_33:
    // 0x800EA2D8: jal         0x800C0438
    // 0x800EA2DC: nop

    func_800C0438(rdram, ctx);
        goto after_34;
    // 0x800EA2DC: nop

    after_34:
    // 0x800EA2E0: jal         0x800FFD10
    // 0x800EA2E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FFD10(rdram, ctx);
        goto after_35;
    // 0x800EA2E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x800EA2E8: jal         0x800C7494
    // 0x800EA2EC: nop

    func_800C7494(rdram, ctx);
        goto after_36;
    // 0x800EA2EC: nop

    after_36:
    // 0x800EA2F0: jal         0x80100534
    // 0x800EA2F4: nop

    func_80100534(rdram, ctx);
        goto after_37;
    // 0x800EA2F4: nop

    after_37:
    // 0x800EA2F8: jal         0x80100C74
    // 0x800EA2FC: nop

    func_80100C74(rdram, ctx);
        goto after_38;
    // 0x800EA2FC: nop

    after_38:
    // 0x800EA300: jal         0x800FFBEC
    // 0x800EA304: nop

    func_800FFBEC(rdram, ctx);
        goto after_39;
    // 0x800EA304: nop

    after_39:
    // 0x800EA308: jal         0x800BF7E0
    // 0x800EA30C: nop

    func_800BF7E0(rdram, ctx);
        goto after_40;
    // 0x800EA30C: nop

    after_40:
    // 0x800EA310: jal         0x800C8A08
    // 0x800EA314: nop

    func_800C8A08(rdram, ctx);
        goto after_41;
    // 0x800EA314: nop

    after_41:
    // 0x800EA318: jal         0x800D154C
    // 0x800EA31C: nop

    func_800D154C(rdram, ctx);
        goto after_42;
    // 0x800EA31C: nop

    after_42:
    // 0x800EA320: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EA324:
    // 0x800EA324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA32C: jr          $ra
    // 0x800EA330: nop

    return;
    // 0x800EA330: nop

;}
RECOMP_FUNC void func_808000B4_chtemplelobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: jr          $ra
    // 0x808000B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void baanim_getAnimCtrlPtr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CABC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CAC0: jr          $ra
    // 0x8008CAC4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    return;
    // 0x8008CAC4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void func_80091E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091E18: jr          $ra
    // 0x80091E1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80091E1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _chfiregen_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869A0: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869A0);
    return;
    // 0x800869A4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80803604_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803608: beq         $a2, $zero, L_80803620
    if (ctx->r6 == 0) {
        // 0x8080360C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80803620;
    }
    // 0x8080360C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803610: jal         0x8080407C
    // 0x80803614: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_8080407C_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80803614: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80803618: b           L_8080362C
    // 0x8080361C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080362C;
    // 0x8080361C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803620:
    // 0x80803620: jal         0x808040DC
    // 0x80803624: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_808040DC_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80803624: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_1:
    // 0x80803628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080362C:
    // 0x8080362C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803630: jr          $ra
    // 0x80803634: nop

    return;
    // 0x80803634: nop

;}
RECOMP_FUNC void func_80800000_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x801015B0
    // 0x8080000C: nop

    func_801015B0(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: jal         0x800CC5E8
    // 0x80800014: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800CC5E8(rdram, ctx);
        goto after_1;
    // 0x80800014: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800018: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800020: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x80800024: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x80800028: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8080002C: beq         $t6, $zero, L_80800068
    if (ctx->r14 == 0) {
        // 0x80800030: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80800068;
    }
    // 0x80800030: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80800034: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80800038: jal         0x8001B668
    // 0x8080003C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8001B668(rdram, ctx);
        goto after_2;
    // 0x8080003C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_2:
    // 0x80800040: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800044: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080004C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80800050: jal         0x8001B7F0
    // 0x80800054: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    func_8001B7F0(rdram, ctx);
        goto after_3;
    // 0x80800054: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    after_3:
    // 0x80800058: jal         0x801015BC
    // 0x8080005C: nop

    func_801015BC(rdram, ctx);
        goto after_4;
    // 0x8080005C: nop

    after_4:
    // 0x80800060: b           L_80800070
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800070;
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800068:
    // 0x80800068: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800070:
    // 0x80800070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void bamum_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800220: beq         $a1, $zero, L_80800248
    if (ctx->r5 == 0) {
        // 0x80800224: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800248;
    }
    // 0x80800224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800228: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080022C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800230: jal         0x8009ADF0
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009ADF0(rdram, ctx);
        goto after_0;
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800238: jal         0x80800008
    // 0x8080023C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800008_bamum(rdram, ctx);
        goto after_1;
    // 0x8080023C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800240: b           L_80800258
    // 0x80800244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800258;
    // 0x80800244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800248:
    // 0x80800248: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080024C: jal         0x8009ADF0
    // 0x80800250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009ADF0(rdram, ctx);
        goto after_2;
    // 0x80800250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800258:
    // 0x80800258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DE0: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DE0);
    return;
    // 0x80082DE4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
