#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void subaddielink_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80800004: jr          $ra
    // 0x80800008: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x80800008: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void bsstonehead_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D24: jal         0x80800B38
    // 0x80800D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800B38_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80800D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D2C: jal         0x80800000
    // 0x80800D30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x80800D30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D3C: jr          $ra
    // 0x80800D40: nop

    return;
    // 0x80800D40: nop

;}
RECOMP_FUNC void func_800E0414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0414: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800E0418: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800E041C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E0420: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800E0424: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x800E0428: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800E042C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E0430: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E0434: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800E0438: jr          $ra
    // 0x800E043C: add.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f16.fl;
    return;
    // 0x800E043C: add.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f16.fl;
;}
RECOMP_FUNC void func_80800A14_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A1C: lbu         $t6, 0x15D($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15D);
    // 0x80800A20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800A24: bnel        $t6, $zero, L_80800A6C
    if (ctx->r14 != 0) {
        // 0x80800A28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800A6C;
    }
    goto skip_0;
    // 0x80800A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800A2C: sb          $t7, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = ctx->r15;
    // 0x80800A30: jal         0x8009BB50
    // 0x80800A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_0;
    // 0x80800A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800A3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A40: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800A44: nop

    // 0x80800A48: bc1f        L_80800A60
    if (!c1cs) {
        // 0x80800A4C: nop
    
            goto L_80800A60;
    }
    // 0x80800A4C: nop

    // 0x80800A50: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800A54: jal         0x8009BA58
    // 0x80800A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_1;
    // 0x80800A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800A60:
    // 0x80800A60: jal         0x808003C0
    // 0x80800A64: nop

    func_808003C0_bsbansack(rdram, ctx);
        goto after_2;
    // 0x80800A64: nop

    after_2:
    // 0x80800A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A6C:
    // 0x80800A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A70: jr          $ra
    // 0x80800A74: nop

    return;
    // 0x80800A74: nop

;}
RECOMP_FUNC void func_80800DA8_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DAC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800DB0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800DB4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800DB8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800DBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DC0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800DC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800DC8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800DCC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_80800DD0:
    // 0x80800DD0: sb          $s0, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r16;
    // 0x80800DD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800DD8: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80800DDC: bne         $at, $zero, L_80800DD0
    if (ctx->r1 != 0) {
        // 0x80800DE0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800DD0;
    }
    // 0x80800DE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800DE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800DE8: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x80800DEC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_80800DF0:
    // 0x80800DF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800DF4: jal         0x800DC128
    // 0x80800DF8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x80800DF8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80800DFC: addu        $v1, $s3, $v0
    ctx->r3 = ADD32(ctx->r19, ctx->r2);
    // 0x80800E00: lb          $t6, 0x60($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X60);
    // 0x80800E04: lb          $a0, 0x60($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X60);
    // 0x80800E08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800E0C: sb          $t6, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r14;
    // 0x80800E10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800E14: bne         $s0, $s2, L_80800DF0
    if (ctx->r16 != ctx->r18) {
        // 0x80800E18: sb          $a0, 0x60($v1)
        MEM_B(0X60, ctx->r3) = ctx->r4;
            goto L_80800DF0;
    }
    // 0x80800E18: sb          $a0, 0x60($v1)
    MEM_B(0X60, ctx->r3) = ctx->r4;
    // 0x80800E1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800E20: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800E24: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800E28: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E2C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800E30: jr          $ra
    // 0x80800E34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800E34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chjiggytemple_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(784, 0X92C) << 16);
    // 0x80800318: jr          $ra
    // 0x8080031C: addiu       $v0, $v0, 0x92C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(784, 0X92C));
    return;
    // 0x8080031C: addiu       $v0, $v0, 0x92C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(784, 0X92C));
;}
RECOMP_FUNC void func_800FC2C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC2C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FC2C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC2CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC2D0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800FC2D4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800FC2D8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC2DC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800FC2E0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800FC2E4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800FC2E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FC2EC: addiu       $s1, $s1, 0x5960
    ctx->r17 = ADD32(ctx->r17, 0X5960);
    // 0x800FC2F0: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
    // 0x800FC2F4: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
L_800FC2F8:
    // 0x800FC2F8: bltzl       $a0, L_800FC324
    if (SIGNED(ctx->r4) < 0) {
        // 0x800FC2FC: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FC324;
    }
    goto skip_0;
    // 0x800FC2FC: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_0:
    // 0x800FC300: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800FC304: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800FC308: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800FC30C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800FC310: bnel        $t7, $zero, L_800FC324
    if (ctx->r15 != 0) {
        // 0x800FC314: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FC324;
    }
    goto skip_1;
    // 0x800FC314: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_1:
    // 0x800FC318: jal         0x800FCB00
    // 0x800FC31C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800FCB00(rdram, ctx);
        goto after_0;
    // 0x800FC31C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800FC320: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
L_800FC324:
    // 0x800FC324: bnel        $s0, $s1, L_800FC2F8
    if (ctx->r16 != ctx->r17) {
        // 0x800FC328: lh          $a0, 0x28($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X28);
            goto L_800FC2F8;
    }
    goto skip_2;
    // 0x800FC328: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    skip_2:
    // 0x800FC32C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FC330: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC334: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC338: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC33C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800FC340: jr          $ra
    // 0x800FC344: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FC344: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsvan_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A48: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A4C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(427, 0X1CAC) << 16);
    // 0x80800A50: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A54: jr          $ra
    // 0x80800A58: lw          $v0, 0x1CAC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CAC));
    return;
    // 0x80800A58: lw          $v0, 0x1CAC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CAC));
;}
RECOMP_FUNC void _chhellterskelter_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E38: syscall     246
    recomp_syscall_handler(rdram, ctx, 0x80085E38);
    return;
    // 0x80085E3C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bsbwhirl_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D48: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800D4C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(128, 0XFD8) << 16);
    // 0x80800D50: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D54: jr          $ra
    // 0x80800D58: lw          $v0, 0xFD8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XFD8));
    return;
    // 0x80800D58: lw          $v0, 0xFD8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XFD8));
;}
RECOMP_FUNC void ncbadie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gczoombox_entrypoint_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803A00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803A04: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80803A08: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80803A0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803A10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803A14: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80803A18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803A1C: beq         $a0, $zero, L_80803A58
    if (ctx->r4 == 0) {
        // 0x80803A20: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80803A58;
    }
    // 0x80803A20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803A24: lh          $t8, 0x172($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X172);
    // 0x80803A28: beq         $t7, $t8, L_80803A58
    if (ctx->r15 == ctx->r24) {
        // 0x80803A2C: nop
    
            goto L_80803A58;
    }
    // 0x80803A2C: nop

    // 0x80803A30: lbu         $v0, 0x171($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X171);
    // 0x80803A34: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80803A38: beq         $v0, $at, L_80803A60
    if (ctx->r2 == ctx->r1) {
        // 0x80803A3C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80803A60;
    }
    // 0x80803A3C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80803A40: beq         $v0, $at, L_80803A60
    if (ctx->r2 == ctx->r1) {
        // 0x80803A44: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80803A60;
    }
    // 0x80803A44: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80803A48: beq         $v0, $at, L_80803A60
    if (ctx->r2 == ctx->r1) {
        // 0x80803A4C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80803A60;
    }
    // 0x80803A4C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80803A50: beql        $v0, $at, L_80803A64
    if (ctx->r2 == ctx->r1) {
        // 0x80803A54: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80803A64;
    }
    goto skip_0;
    // 0x80803A54: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_0:
L_80803A58:
    // 0x80803A58: b           L_80803B10
    // 0x80803A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803B10;
    // 0x80803A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803A60:
    // 0x80803A60: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_80803A64:
    // 0x80803A64: beq         $v0, $at, L_80803A74
    if (ctx->r2 == ctx->r1) {
        // 0x80803A68: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80803A74;
    }
    // 0x80803A68: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80803A6C: bnel        $v0, $at, L_80803A88
    if (ctx->r2 != ctx->r1) {
        // 0x80803A70: lhu         $t9, 0x142($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X142);
            goto L_80803A88;
    }
    goto skip_1;
    // 0x80803A70: lhu         $t9, 0x142($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X142);
    skip_1:
L_80803A74:
    // 0x80803A74: jal         0x80803964
    // 0x80803A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gczoombox_entrypoint_36(rdram, ctx);
        goto after_0;
    // 0x80803A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80803A7C: b           L_80803B10
    // 0x80803A80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803B10;
    // 0x80803A80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80803A84: lhu         $t9, 0x142($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X142);
L_80803A88:
    // 0x80803A88: beql        $t9, $zero, L_80803A98
    if (ctx->r25 == 0) {
        // 0x80803A8C: lhu         $v0, 0x140($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X140);
            goto L_80803A98;
    }
    goto skip_2;
    // 0x80803A8C: lhu         $v0, 0x140($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X140);
    skip_2:
    // 0x80803A90: sh          $zero, 0x142($s0)
    MEM_H(0X142, ctx->r16) = 0;
    // 0x80803A94: lhu         $v0, 0x140($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X140);
L_80803A98:
    // 0x80803A98: beql        $v0, $zero, L_80803AA8
    if (ctx->r2 == 0) {
        // 0x80803A9C: lb          $t0, 0x1B7($s0)
        ctx->r8 = MEM_B(ctx->r16, 0X1B7);
            goto L_80803AA8;
    }
    goto skip_3;
    // 0x80803A9C: lb          $t0, 0x1B7($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1B7);
    skip_3:
    // 0x80803AA0: sh          $v0, 0x142($s0)
    MEM_H(0X142, ctx->r16) = ctx->r2;
    // 0x80803AA4: lb          $t0, 0x1B7($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1B7);
L_80803AA8:
    // 0x80803AA8: lb          $t1, 0x1B8($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1B8);
    // 0x80803AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803AB0: sb          $t0, 0x1B9($s0)
    MEM_B(0X1B9, ctx->r16) = ctx->r8;
    // 0x80803AB4: sb          $t1, 0x1BA($s0)
    MEM_B(0X1BA, ctx->r16) = ctx->r9;
    // 0x80803AB8: jal         0x80802B94
    // 0x80803ABC: sh          $a1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r5;
    func_80802B94_gczoombox(rdram, ctx);
        goto after_1;
    // 0x80803ABC: sh          $a1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r5;
    after_1:
    // 0x80803AC0: lh          $a0, 0x26($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X26);
    // 0x80803AC4: addiu       $a1, $s0, 0x1B7
    ctx->r5 = ADD32(ctx->r16, 0X1B7);
    // 0x80803AC8: jal         0x80088420
    // 0x80803ACC: addiu       $a2, $s0, 0x1B8
    ctx->r6 = ADD32(ctx->r16, 0X1B8);
    _gczoomboxdata_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80803ACC: addiu       $a2, $s0, 0x1B8
    ctx->r6 = ADD32(ctx->r16, 0X1B8);
    after_2:
    // 0x80803AD0: jal         0x80800000
    // 0x80803AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_gczoombox(rdram, ctx);
        goto after_3;
    // 0x80803AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80803AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803ADC: jal         0x80802C80
    // 0x80803AE0: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    func_80802C80_gczoombox(rdram, ctx);
        goto after_4;
    // 0x80803AE0: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_4:
    // 0x80803AE4: lbu         $t4, 0x1E6($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1E6);
    // 0x80803AE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803AEC: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x80803AF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803AF4: ori         $t7, $t4, 0x40
    ctx->r15 = ctx->r12 | 0X40;
    // 0x80803AF8: sb          $t7, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r15;
    // 0x80803AFC: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80803B00: sb          $t8, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r24;
    // 0x80803B04: sh          $t2, 0x172($s0)
    MEM_H(0X172, ctx->r16) = ctx->r10;
    // 0x80803B08: swc1        $f4, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->f4.u32l;
    // 0x80803B0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803B10:
    // 0x80803B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803B14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803B1C: jr          $ra
    // 0x80803B20: nop

    return;
    // 0x80803B20: nop

;}
RECOMP_FUNC void func_8080003C_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: jal         0x80091A58
    // 0x80800048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80800048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void func_808011F8_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801200: jal         0x80102424
    // 0x80801204: nop

    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80801204: nop

    after_0:
    // 0x80801208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080120C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801210: jr          $ra
    // 0x80801214: nop

    return;
    // 0x80801214: nop

;}
RECOMP_FUNC void _fxegg_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A88: syscall     719
    recomp_syscall_handler(rdram, ctx, 0x80088A88);
    return;
    // 0x80088A8C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800650_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800650: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800658: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080065C: jal         0x8008CABC
    // 0x80800660: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800660: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800664: jal         0x8008B324
    // 0x80800668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_1;
    // 0x80800668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080066C: beq         $v0, $zero, L_80800678
    if (ctx->r2 == 0) {
        // 0x80800670: addiu       $t6, $zero, 0xBE
        ctx->r14 = ADD32(0, 0XBE);
            goto L_80800678;
    }
    // 0x80800670: addiu       $t6, $zero, 0xBE
    ctx->r14 = ADD32(0, 0XBE);
    // 0x80800674: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800678:
    // 0x80800678: jal         0x8008E078
    // 0x8080067C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x8080067C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800680: beq         $v0, $zero, L_8080068C
    if (ctx->r2 == 0) {
        // 0x80800684: addiu       $t7, $zero, 0xBB
        ctx->r15 = ADD32(0, 0XBB);
            goto L_8080068C;
    }
    // 0x80800684: addiu       $t7, $zero, 0xBB
    ctx->r15 = ADD32(0, 0XBB);
    // 0x80800688: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8080068C:
    // 0x8080068C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800690: jal         0x8009E5C8
    // 0x80800694: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80800694: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080069C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006A0: jr          $ra
    // 0x808006A4: nop

    return;
    // 0x808006A4: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C30: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800C34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C3C: jal         0x80800D38
    // 0x80800C40: sb          $zero, 0x10($t6)
    MEM_B(0X10, ctx->r14) = 0;
    bafpctrl_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800C40: sb          $zero, 0x10($t6)
    MEM_B(0X10, ctx->r14) = 0;
    after_0:
    // 0x80800C44: lw          $a0, 0x90($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X90);
    // 0x80800C48: jal         0x800EFD24
    // 0x80800C4C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800C4C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800C50: lw          $t7, 0x90($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X90);
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C5C: jal         0x80800CA0
    // 0x80800C60: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    bafpctrl_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800C60: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    after_2:
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C68: jal         0x80800CAC
    // 0x80800C6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bafpctrl_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800C6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C74: jal         0x80800D14
    // 0x80800C78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bafpctrl_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800C78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800C7C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800C80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C84: lw          $t8, 0x90($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X90);
    // 0x80800C88: swc1        $f4, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f4.u32l;
    // 0x80800C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C98: jr          $ra
    // 0x80800C9C: nop

    return;
    // 0x80800C9C: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089920: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089920);
    return;
    // 0x80089924: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void func_80800E74_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E74: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800E78: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80800E7C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80800E80: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80800E84: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80800E88: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800E8C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80800E90: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80800E94: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80800E98: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80800E9C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80800EA0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80800EA4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80800EA8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80800EAC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800EB0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800EB4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800EB8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800EBC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800EC0: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80800EC4: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x80800EC8: jal         0x80100094
    // 0x80800ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800ED0: lw          $t6, 0x6C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X6C);
    // 0x80800ED4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800ED8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800EDC: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800EE0: beql        $t7, $zero, L_80801164
    if (ctx->r15 == 0) {
        // 0x80800EE4: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80801164;
    }
    goto skip_0;
    // 0x80800EE4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x80800EE8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800EEC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800EF0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800EF4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800EF8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800EFC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800F00: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800F04: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800F08: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800F0C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800F10: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80800F14: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
L_80800F18:
    // 0x80800F18: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800F1C: jal         0x80087A28
    // 0x80800F20: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800F20: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    after_1:
    // 0x80800F24: lwc1        $f4, 0x58($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80800F28: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800F2C: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80800F30: c.eq.s      $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f28.fl == ctx->f4.fl;
    // 0x80800F34: sb          $t8, 0x5C($s1)
    MEM_B(0X5C, ctx->r17) = ctx->r24;
    // 0x80800F38: bc1fl       L_80800F48
    if (!c1cs) {
        // 0x80800F3C: lw          $t9, 0x8C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X8C);
            goto L_80800F48;
    }
    goto skip_1;
    // 0x80800F3C: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    skip_1:
    // 0x80800F40: swc1        $f30, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f30.u32l;
    // 0x80800F44: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
L_80800F48:
    // 0x80800F48: lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X88);
    // 0x80800F4C: blezl       $t9, L_80801130
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80800F50: lwc1        $f18, 0x48($s1)
        ctx->f18.u32l = MEM_W(ctx->r17, 0X48);
            goto L_80801130;
    }
    goto skip_2;
    // 0x80800F50: lwc1        $f18, 0x48($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X48);
    skip_2:
    // 0x80800F54: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
L_80800F58:
    // 0x80800F58: bnel        $fp, $t0, L_8080111C
    if (ctx->r30 != ctx->r8) {
        // 0x80800F5C: lw          $t9, 0x8C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X8C);
            goto L_8080111C;
    }
    goto skip_3;
    // 0x80800F5C: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    skip_3:
    // 0x80800F60: lwc1        $f6, 0x48($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80800F64: lwc1        $f8, 0x4($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80800F68: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800F6C: sb          $t1, 0x5C($s1)
    MEM_B(0X5C, ctx->r17) = ctx->r9;
    // 0x80800F70: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800F74: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80800F78: swc1        $f10, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f10.u32l;
    // 0x80800F7C: lb          $t2, 0x8($s6)
    ctx->r10 = MEM_B(ctx->r22, 0X8);
    // 0x80800F80: sb          $t2, 0x5D($s1)
    MEM_B(0X5D, ctx->r17) = ctx->r10;
    // 0x80800F84: lb          $t3, 0x9($s6)
    ctx->r11 = MEM_B(ctx->r22, 0X9);
    // 0x80800F88: sb          $t3, 0x5E($s1)
    MEM_B(0X5E, ctx->r17) = ctx->r11;
    // 0x80800F8C: lb          $v1, 0x5E($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X5E);
    // 0x80800F90: bltz        $v1, L_80801020
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800F94: nop
    
            goto L_80801020;
    }
    // 0x80800F94: nop

    // 0x80800F98: lw          $t4, 0x6C($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X6C);
    // 0x80800F9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800FA0: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x80800FA4: beq         $t5, $zero, L_80801118
    if (ctx->r13 == 0) {
        // 0x80800FA8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80801118;
    }
    // 0x80800FA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800FAC:
    // 0x80800FAC: jal         0x80087A28
    // 0x80800FB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800FB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800FB4: lb          $t6, 0x5E($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X5E);
    // 0x80800FB8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FC0: bne         $v0, $t6, L_80801000
    if (ctx->r2 != ctx->r14) {
        // 0x80800FC4: sll         $s2, $s0, 2
        ctx->r18 = S32(ctx->r16 << 2);
            goto L_80801000;
    }
    // 0x80800FC4: sll         $s2, $s0, 2
    ctx->r18 = S32(ctx->r16 << 2);
    // 0x80800FC8: subu        $s2, $s2, $s0
    ctx->r18 = SUB32(ctx->r18, ctx->r16);
    // 0x80800FCC: sll         $s2, $s2, 5
    ctx->r18 = S32(ctx->r18 << 5);
    // 0x80800FD0: jal         0x80100094
    // 0x80800FD4: addiu       $s3, $s1, 0xC
    ctx->r19 = ADD32(ctx->r17, 0XC);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800FD4: addiu       $s3, $s1, 0xC
    ctx->r19 = ADD32(ctx->r17, 0XC);
    after_3:
    // 0x80800FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FDC: addu        $a1, $v0, $s2
    ctx->r5 = ADD32(ctx->r2, ctx->r18);
    // 0x80800FE0: jal         0x800F18FC
    // 0x80800FE4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800F18FC(rdram, ctx);
        goto after_4;
    // 0x80800FE4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_4:
    // 0x80800FE8: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80800FEC: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80800FF0: swc1        $f22, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f22.u32l;
    // 0x80800FF4: sub.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x80800FF8: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
    // 0x80800FFC: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
L_80801000:
    // 0x80801000: lw          $t7, 0x6C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X6C);
    // 0x80801004: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801008: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8080100C: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x80801010: bnel        $at, $zero, L_80800FAC
    if (ctx->r1 != 0) {
        // 0x80801014: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800FAC;
    }
    goto skip_4;
    // 0x80801014: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_4:
    // 0x80801018: b           L_8080111C
    // 0x8080101C: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
        goto L_8080111C;
    // 0x8080101C: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
L_80801020:
    // 0x80801020: beq         $v1, $at, L_80801078
    if (ctx->r3 == ctx->r1) {
        // 0x80801024: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_80801078;
    }
    // 0x80801024: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80801028: beq         $v1, $at, L_80801048
    if (ctx->r3 == ctx->r1) {
        // 0x8080102C: addiu       $at, $zero, -0x3
        ctx->r1 = ADD32(0, -0X3);
            goto L_80801048;
    }
    // 0x8080102C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80801030: beq         $v1, $at, L_808010B0
    if (ctx->r3 == ctx->r1) {
        // 0x80801034: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_808010B0;
    }
    // 0x80801034: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80801038: beql        $v1, $at, L_808010EC
    if (ctx->r3 == ctx->r1) {
        // 0x8080103C: lwc1        $f10, 0x48($s1)
        ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
            goto L_808010EC;
    }
    goto skip_5;
    // 0x8080103C: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
    skip_5:
    // 0x80801040: b           L_8080111C
    // 0x80801044: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
        goto L_8080111C;
    // 0x80801044: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
L_80801048:
    // 0x80801048: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
    // 0x8080104C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80801050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801054: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80801058: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x8080105C: lw          $a2, 0x48($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X48);
    // 0x80801060: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801064: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801068: jal         0x800EF214
    // 0x8080106C: nop

    func_800EF214(rdram, ctx);
        goto after_5;
    // 0x8080106C: nop

    after_5:
    // 0x80801070: b           L_8080111C
    // 0x80801074: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
        goto L_8080111C;
    // 0x80801074: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
L_80801078:
    // 0x80801078: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
    // 0x8080107C: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80801080: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80801084: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80801088: add.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f26.fl;
    // 0x8080108C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801090: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80801094: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80801098: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8080109C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808010A0: jal         0x800EF214
    // 0x808010A4: nop

    func_800EF214(rdram, ctx);
        goto after_6;
    // 0x808010A4: nop

    after_6:
    // 0x808010A8: b           L_8080111C
    // 0x808010AC: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
        goto L_8080111C;
    // 0x808010AC: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
L_808010B0:
    // 0x808010B0: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
    // 0x808010B4: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x808010B8: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x808010BC: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x808010C0: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x808010C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010C8: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x808010CC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808010D0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x808010D4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808010D8: jal         0x800EF214
    // 0x808010DC: nop

    func_800EF214(rdram, ctx);
        goto after_7;
    // 0x808010DC: nop

    after_7:
    // 0x808010E0: b           L_8080111C
    // 0x808010E4: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
        goto L_8080111C;
    // 0x808010E4: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x808010E8: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
L_808010EC:
    // 0x808010EC: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x808010F0: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x808010F4: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x808010F8: sub.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x808010FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801100: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80801104: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80801108: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8080110C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80801110: jal         0x800EF214
    // 0x80801114: nop

    func_800EF214(rdram, ctx);
        goto after_8;
    // 0x80801114: nop

    after_8:
L_80801118:
    // 0x80801118: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
L_8080111C:
    // 0x8080111C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80801120: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
    // 0x80801124: bnel        $s7, $t9, L_80800F58
    if (ctx->r23 != ctx->r25) {
        // 0x80801128: lw          $t0, 0x0($s6)
        ctx->r8 = MEM_W(ctx->r22, 0X0);
            goto L_80800F58;
    }
    goto skip_6;
    // 0x80801128: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    skip_6:
    // 0x8080112C: lwc1        $f18, 0x48($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X48);
L_80801130:
    // 0x80801130: lwc1        $f4, 0x34($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X34);
    // 0x80801134: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80801138: addiu       $s1, $s1, 0x60
    ctx->r17 = ADD32(ctx->r17, 0X60);
    // 0x8080113C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80801140: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80801144: swc1        $f6, -0x18($s1)
    MEM_W(-0X18, ctx->r17) = ctx->f6.u32l;
    // 0x80801148: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8080114C: lw          $t0, 0x6C($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X6C);
    // 0x80801150: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x80801154: sltu        $at, $v0, $t1
    ctx->r1 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x80801158: bnel        $at, $zero, L_80800F18
    if (ctx->r1 != 0) {
        // 0x8080115C: lw          $a1, 0x74($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X74);
            goto L_80800F18;
    }
    goto skip_7;
    // 0x8080115C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    skip_7:
    // 0x80801160: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80801164:
    // 0x80801164: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801168: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080116C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80801170: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80801174: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80801178: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8080117C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80801180: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80801184: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80801188: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8080118C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80801190: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80801194: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80801198: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8080119C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x808011A0: jr          $ra
    // 0x808011A4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x808011A4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void _bskazstilt_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836B8: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836B8);
    return;
    // 0x800836BC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void bamovethrust_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: jr          $ra
    // 0x8080005C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080005C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800310_chjinjovillagecamera1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800310: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800318: jal         0x808002BC
    // 0x8080031C: nop

    func_808002BC_chjinjovillagecamera1(rdram, ctx);
        goto after_0;
    // 0x8080031C: nop

    after_0:
    // 0x80800320: jal         0x800EA05C
    // 0x80800324: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800324: nop

    after_1:
    // 0x80800328: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x8080032C: beql        $v0, $at, L_808003B4
    if (ctx->r2 == ctx->r1) {
        // 0x80800330: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003B4;
    }
    goto skip_0;
    // 0x80800330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800334: jal         0x80086B90
    // 0x80800338: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    _chjinjo_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800338: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_2:
    // 0x8080033C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800340: jal         0x800D1338
    // 0x80800344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1338(rdram, ctx);
        goto after_3;
    // 0x80800344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800348: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080034C: jal         0x800D129C
    // 0x80800350: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800D129C(rdram, ctx);
        goto after_4;
    // 0x80800350: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800354: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800358: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080035C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    // 0x80800360: xor         $v1, $t6, $v0
    ctx->r3 = ctx->r14 ^ ctx->r2;
    // 0x80800364: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800368: jal         0x80088840
    // 0x8080036C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x8080036C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_5:
    // 0x80800370: beq         $v0, $zero, L_808003A0
    if (ctx->r2 == 0) {
        // 0x80800374: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_808003A0;
    }
    // 0x80800374: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800378: beq         $v1, $zero, L_80800388
    if (ctx->r3 == 0) {
        // 0x8080037C: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80800388;
    }
    // 0x8080037C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800384: bne         $t7, $at, L_808003B0
    if (ctx->r15 != ctx->r1) {
        // 0x80800388: addiu       $a0, $zero, 0x48F
        ctx->r4 = ADD32(0, 0X48F);
            goto L_808003B0;
    }
L_80800388:
    // 0x80800388: addiu       $a0, $zero, 0x48F
    ctx->r4 = ADD32(0, 0X48F);
    // 0x8080038C: addiu       $a1, $zero, 0x7E
    ctx->r5 = ADD32(0, 0X7E);
    // 0x80800390: jal         0x80101180
    // 0x80800394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800398: b           L_808003B4
    // 0x8080039C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003B4;
    // 0x8080039C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003A0:
    // 0x808003A0: beql        $v1, $zero, L_808003B4
    if (ctx->r3 == 0) {
        // 0x808003A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003B4;
    }
    goto skip_1;
    // 0x808003A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808003A8: jal         0x800FDC28
    // 0x808003AC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800FDC28(rdram, ctx);
        goto after_7;
    // 0x808003AC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_7:
L_808003B0:
    // 0x808003B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B4:
    // 0x808003B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003B8: jr          $ra
    // 0x808003BC: nop

    return;
    // 0x808003BC: nop

;}
RECOMP_FUNC void func_80014E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014E14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80014E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014E1C: addiu       $a0, $a1, 0x40
    ctx->r4 = ADD32(ctx->r5, 0X40);
    // 0x80014E20: jal         0x8001ACEC
    // 0x80014E24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    heap_alloc_sided(rdram, ctx);
        goto after_0;
    // 0x80014E24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80014E28: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80014E2C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014E30: andi        $t8, $v0, 0x3F
    ctx->r24 = ctx->r2 & 0X3F;
    // 0x80014E34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80014E38: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80014E3C: sw          $v0, -0x7090($at)
    MEM_W(-0X7090, ctx->r1) = ctx->r2;
    // 0x80014E40: beq         $t8, $zero, L_80014E58
    if (ctx->r24 == 0) {
        // 0x80014E44: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80014E58;
    }
    // 0x80014E44: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80014E48: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80014E4C:
    // 0x80014E4C: andi        $t9, $v1, 0x3F
    ctx->r25 = ctx->r3 & 0X3F;
    // 0x80014E50: bnel        $t9, $zero, L_80014E4C
    if (ctx->r25 != 0) {
        // 0x80014E54: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80014E4C;
    }
    goto skip_0;
    // 0x80014E54: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_80014E58:
    // 0x80014E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80014E60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80014E64: jr          $ra
    // 0x80014E68: nop

    return;
    // 0x80014E68: nop

;}
RECOMP_FUNC void func_80800D68_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D70: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800D74: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800D78: bgezl       $t8, L_80800DAC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800D7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DAC;
    }
    goto skip_0;
    // 0x80800D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800D80: jal         0x80100094
    // 0x80800D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D88: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x80800D8C: beql        $t9, $zero, L_80800DAC
    if (ctx->r25 == 0) {
        // 0x80800D90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DAC;
    }
    goto skip_1;
    // 0x80800D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800D94: jal         0x80106790
    // 0x80800D98: lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X30);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800D98: lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X30);
    after_1:
    // 0x80800D9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DA0: jal         0x8010A764
    // 0x80800DA4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8010A764(rdram, ctx);
        goto after_2;
    // 0x80800DA4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DAC:
    // 0x80800DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DB0: jr          $ra
    // 0x80800DB4: nop

    return;
    // 0x80800DB4: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8080068C: addiu       $v1, $v1, 0x75E8
    ctx->r3 = ADD32(ctx->r3, 0X75E8);
    // 0x80800690: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x80800694: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80800698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080069C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A0: beql        $t6, $t7, L_808006D0
    if (ctx->r14 == ctx->r15) {
        // 0x808006A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808006D0;
    }
    goto skip_0;
    // 0x808006A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808006A8: jal         0x800EA05C
    // 0x808006AC: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808006AC: nop

    after_0:
    // 0x808006B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x808006B4: addiu       $v1, $v1, 0x75E8
    ctx->r3 = ADD32(ctx->r3, 0X75E8);
    // 0x808006B8: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x808006BC: bnel        $v0, $t8, L_808006D0
    if (ctx->r2 != ctx->r24) {
        // 0x808006C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808006D0;
    }
    goto skip_1;
    // 0x808006C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x808006C4: b           L_808006D0
    // 0x808006C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006D0;
    // 0x808006C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808006CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006D0:
    // 0x808006D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006D8: jr          $ra
    // 0x808006DC: nop

    return;
    // 0x808006DC: nop

;}
RECOMP_FUNC void _subaddieDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A498: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A498);
    return;
    // 0x8008A49C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _susubgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2A0: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2A0);
    return;
    // 0x8008A2A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801090_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801090: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801094: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801098: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080109C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808010A0: lbu         $a2, 0x5F($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X5F);
    // 0x808010A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010A8: bnel        $a2, $zero, L_808010D0
    if (ctx->r6 != 0) {
        // 0x808010AC: addiu       $t6, $s0, 0x4
        ctx->r14 = ADD32(ctx->r16, 0X4);
            goto L_808010D0;
    }
    goto skip_0;
    // 0x808010AC: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x808010B0: jal         0x80089D10
    // 0x808010B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808010B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x808010B8: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x808010BC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808010C0: jal         0x800C330C
    // 0x808010C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_1;
    // 0x808010C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808010C8: lbu         $a2, 0x5F($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X5F);
    // 0x808010CC: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
L_808010D0:
    // 0x808010D0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x808010D4: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x808010D8: jal         0x800C3058
    // 0x808010DC: addiu       $a1, $zero, 0x55F0
    ctx->r5 = ADD32(0, 0X55F0);
    func_800C3058(rdram, ctx);
        goto after_2;
    // 0x808010DC: addiu       $a1, $zero, 0x55F0
    ctx->r5 = ADD32(0, 0X55F0);
    after_2:
    // 0x808010E0: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808010E4: jal         0x800C31DC
    // 0x808010E8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x808010E8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x808010EC: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808010F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808010F4: jal         0x800C4350
    // 0x808010F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800C4350(rdram, ctx);
        goto after_4;
    // 0x808010F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x808010FC: jal         0x800C3BDC
    // 0x80801100: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_5;
    // 0x80801100: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_5:
    // 0x80801104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080110C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801110: jr          $ra
    // 0x80801114: nop

    return;
    // 0x80801114: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808040F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808040F4: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB4D0) << 16);
    // 0x808040F8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808040FC: jr          $ra
    // 0x80804100: lw          $v0, -0x4B30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB4D0));
    return;
    // 0x80804100: lw          $v0, -0x4B30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB4D0));
;}
RECOMP_FUNC void func_8001E7E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E7EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E7F0: jal         0x8001E7E0
    // 0x8001E7F4: nop

    func_8001E7E0(rdram, ctx);
        goto after_0;
    // 0x8001E7F4: nop

    after_0:
    // 0x8001E7F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E7FC: jal         0x8001E830
    // 0x8001E800: sw          $v0, -0x1668($at)
    MEM_W(-0X1668, ctx->r1) = ctx->r2;
    func_8001E830(rdram, ctx);
        goto after_1;
    // 0x8001E800: sw          $v0, -0x1668($at)
    MEM_W(-0X1668, ctx->r1) = ctx->r2;
    after_1:
    // 0x8001E804: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001E808: lw          $t6, -0x1668($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1668);
    // 0x8001E80C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E810: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001E814: addiu       $v1, $v1, -0x1670
    ctx->r3 = ADD32(ctx->r3, -0X1670);
    // 0x8001E818: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x8001E81C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001E820: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E824: sw          $t7, -0x166C($at)
    MEM_W(-0X166C, ctx->r1) = ctx->r15;
    // 0x8001E828: jr          $ra
    // 0x8001E82C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001E82C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gcstatusDll_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x808001A4: jr          $ra
    // 0x808001A8: lbu         $v0, -0x4BEF($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X4BEF);
    return;
    // 0x808001A8: lbu         $v0, -0x4BEF($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X4BEF);
;}
RECOMP_FUNC void _gccubesearch_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088290: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x80088290);
    return;
    // 0x80088294: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bitfield_set_bit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9F18: beq         $a2, $zero, L_800D9F50
    if (ctx->r6 == 0) {
        // 0x800D9F1C: andi        $t4, $a1, 0x7
        ctx->r12 = ctx->r5 & 0X7;
            goto L_800D9F50;
    }
    // 0x800D9F1C: andi        $t4, $a1, 0x7
    ctx->r12 = ctx->r5 & 0X7;
    // 0x800D9F20: bgez        $a1, L_800D9F30
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800D9F24: sra         $t6, $a1, 3
        ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
            goto L_800D9F30;
    }
    // 0x800D9F24: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800D9F28: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x800D9F2C: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_800D9F30:
    // 0x800D9F30: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x800D9F34: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800D9F38: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x800D9F3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D9F40: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x800D9F44: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x800D9F48: jr          $ra
    // 0x800D9F4C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    return;
    // 0x800D9F4C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_800D9F50:
    // 0x800D9F50: bgez        $a1, L_800D9F60
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800D9F54: sra         $t2, $a1, 3
        ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
            goto L_800D9F60;
    }
    // 0x800D9F54: sra         $t2, $a1, 3
    ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800D9F58: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x800D9F5C: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_800D9F60:
    // 0x800D9F60: addu        $v0, $t2, $a0
    ctx->r2 = ADD32(ctx->r10, ctx->r4);
    // 0x800D9F64: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x800D9F68: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D9F6C: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x800D9F70: nor         $t9, $t6, $zero
    ctx->r25 = ~(ctx->r14 | 0);
    // 0x800D9F74: and         $t8, $t3, $t9
    ctx->r24 = ctx->r11 & ctx->r25;
    // 0x800D9F78: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800D9F7C: jr          $ra
    // 0x800D9F80: nop

    return;
    // 0x800D9F80: nop

;}
RECOMP_FUNC void _ncfixposrot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891E0: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x800891E0);
    return;
    // 0x800891E4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801C10_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C10: jr          $ra
    // 0x80801C14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80801C14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void bsbswim_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808018DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1F10) << 16);
    // 0x808018E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808018E4: jr          $ra
    // 0x808018E8: lw          $v0, 0x1F10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1F10));
    return;
    // 0x808018E8: lw          $v0, 0x1F10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1F10));
;}
RECOMP_FUNC void func_800D6378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6378: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D637C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D6380: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D6384: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D6388: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D638C: sll         $t7, $t6, 27
    ctx->r15 = S32(ctx->r14 << 27);
    // 0x800D6390: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800D6394: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800D6398: sltiu       $at, $t9, 0x9
    ctx->r1 = ctx->r25 < 0X9 ? 1 : 0;
    // 0x800D639C: beq         $at, $zero, L_800D63EC
    if (ctx->r1 == 0) {
        // 0x800D63A0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800D63EC;
    }
    // 0x800D63A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D63A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D63A8: addu        $at, $at, $t9
    gpr jr_addend_800D63B0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800D63AC: lw          $t9, 0x5C30($at)
    ctx->r25 = ADD32(ctx->r1, 0X5C30);
    // 0x800D63B0: jr          $t9
    // 0x800D63B4: nop

    switch (jr_addend_800D63B0 >> 2) {
        case 0: goto L_800D63EC; break;
        case 1: goto L_800D63B8; break;
        case 2: goto L_800D63E0; break;
        case 3: goto L_800D63E0; break;
        case 4: goto L_800D63E0; break;
        case 5: goto L_800D63E0; break;
        case 6: goto L_800D63E0; break;
        case 7: goto L_800D63E0; break;
        case 8: goto L_800D63E0; break;
        default: switch_error(__func__, 0x800D63B0, 0x80125C30);
    }
    // 0x800D63B4: nop

L_800D63B8:
    // 0x800D63B8: jal         0x800D56C4
    // 0x800D63BC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D56C4(rdram, ctx);
        goto after_0;
    // 0x800D63BC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x800D63C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800D63C4: lbu         $v1, 0xB($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XB);
    // 0x800D63C8: beq         $v1, $zero, L_800D63EC
    if (ctx->r3 == 0) {
        // 0x800D63CC: nop
    
            goto L_800D63EC;
    }
    // 0x800D63CC: nop

    // 0x800D63D0: jal         0x800DBB9C
    // 0x800D63D4: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    func_800DBB9C(rdram, ctx);
        goto after_1;
    // 0x800D63D4: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    after_1:
    // 0x800D63D8: b           L_800D63EC
    // 0x800D63DC: sb          $zero, 0xB($s0)
    MEM_B(0XB, ctx->r16) = 0;
        goto L_800D63EC;
    // 0x800D63DC: sb          $zero, 0xB($s0)
    MEM_B(0XB, ctx->r16) = 0;
L_800D63E0:
    // 0x800D63E0: jal         0x800D56C4
    // 0x800D63E4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_800D56C4(rdram, ctx);
        goto after_2;
    // 0x800D63E4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x800D63E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_800D63EC:
    // 0x800D63EC: jal         0x800D61B4
    // 0x800D63F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D61B4(rdram, ctx);
        goto after_3;
    // 0x800D63F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800D63F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D63F8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800D63FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D6400: jr          $ra
    // 0x800D6404: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D6404: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80020AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020AD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80020AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020AD8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80020ADC: jal         0x8002FEC0
    // 0x80020AE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80020AE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80020AE4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80020AE8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80020AEC: lw          $t6, 0x11D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11D0);
    // 0x80020AF0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80020AF4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80020AF8: beq         $t7, $zero, L_80020B70
    if (ctx->r15 == 0) {
        // 0x80020AFC: nop
    
            goto L_80020B70;
    }
    // 0x80020AFC: nop

L_80020B00:
    // 0x80020B00: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x80020B04: sh          $t8, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r24;
    // 0x80020B08: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80020B0C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80020B10: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80020B14: lbu         $t2, 0x33($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X33);
    // 0x80020B18: lbu         $t1, 0x44($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X44);
    // 0x80020B1C: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80020B20: bne         $t3, $t2, L_80020B58
    if (ctx->r11 != ctx->r10) {
        // 0x80020B24: nop
    
            goto L_80020B58;
    }
    // 0x80020B24: nop

    // 0x80020B28: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80020B2C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80020B30: lbu         $t5, 0x44($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X44);
    // 0x80020B34: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80020B38: sb          $t6, 0x44($t4)
    MEM_B(0X44, ctx->r12) = ctx->r14;
    // 0x80020B3C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020B40: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x80020B44: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80020B48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80020B4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80020B50: jal         0x80026500
    // 0x80020B54: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_1;
    // 0x80020B54: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
L_80020B58:
    // 0x80020B58: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80020B5C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80020B60: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80020B64: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80020B68: bne         $t9, $zero, L_80020B00
    if (ctx->r25 != 0) {
        // 0x80020B6C: nop
    
            goto L_80020B00;
    }
    // 0x80020B6C: nop

L_80020B70:
    // 0x80020B70: jal         0x8002FEC0
    // 0x80020B74: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80020B74: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80020B78: b           L_80020B80
    // 0x80020B7C: nop

        goto L_80020B80;
    // 0x80020B7C: nop

L_80020B80:
    // 0x80020B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020B84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80020B88: jr          $ra
    // 0x80020B8C: nop

    return;
    // 0x80020B8C: nop

;}
RECOMP_FUNC void _chlavaarchgrill3switches_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087110: syscall     517
    recomp_syscall_handler(rdram, ctx, 0x80087110);
    return;
    // 0x80087114: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080000C_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800020: beq         $a1, $at, L_80800050
    if (ctx->r5 == ctx->r1) {
        // 0x80800024: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800050;
    }
    // 0x80800024: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800028: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080002C: beq         $a1, $at, L_80800060
    if (ctx->r5 == ctx->r1) {
        // 0x80800030: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800060;
    }
    // 0x80800030: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800034: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800038: beq         $a1, $at, L_808000E4
    if (ctx->r5 == ctx->r1) {
        // 0x8080003C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808000E4;
    }
    // 0x8080003C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800040: beq         $a1, $at, L_80800080
    if (ctx->r5 == ctx->r1) {
        // 0x80800044: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800080;
    }
    // 0x80800044: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800048: b           L_80800178
    // 0x8080004C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
        goto L_80800178;
    // 0x8080004C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_80800050:
    // 0x80800050: jal         0x800DA524
    // 0x80800054: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x80800054: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800058: b           L_80800178
    // 0x8080005C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
        goto L_80800178;
    // 0x8080005C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_80800060:
    // 0x80800060: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80800064: jal         0x800CE8D8
    // 0x80800068: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_800CE8D8(rdram, ctx);
        goto after_1;
    // 0x80800068: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_1:
    // 0x8080006C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800070: jal         0x800CE88C
    // 0x80800074: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x80800074: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800078: b           L_80800178
    // 0x8080007C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
        goto L_80800178;
    // 0x8080007C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_80800080:
    // 0x80800080: jal         0x800CE88C
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_3;
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800088: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8080008C: jal         0x800FC63C
    // 0x80800090: addiu       $a1, $zero, 0x6D60
    ctx->r5 = ADD32(0, 0X6D60);
    func_800FC63C(rdram, ctx);
        goto after_4;
    // 0x80800090: addiu       $a1, $zero, 0x6D60
    ctx->r5 = ADD32(0, 0X6D60);
    after_4:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x80100094
    // 0x8080009C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x8080009C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x808000AC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x808000B0: jal         0x8008A2D0
    // 0x808000B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x808000B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x808000B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000BC: addiu       $t7, $zero, 0x62
    ctx->r15 = ADD32(0, 0X62);
    // 0x808000C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808000C4: addiu       $a1, $zero, 0xFF5
    ctx->r5 = ADD32(0, 0XFF5);
    // 0x808000C8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x808000CC: jal         0x8008A208
    // 0x808000D0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808000D0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x808000D4: jal         0x800DA544
    // 0x808000D8: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x808000D8: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    after_8:
    // 0x808000DC: b           L_80800178
    // 0x808000E0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
        goto L_80800178;
    // 0x808000E0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_808000E4:
    // 0x808000E4: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x808000E8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x808000EC: addiu       $a1, $zero, 0x6D60
    ctx->r5 = ADD32(0, 0X6D60);
    // 0x808000F0: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x808000F4: jal         0x800FC63C
    // 0x808000F8: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
    func_800FC63C(rdram, ctx);
        goto after_9;
    // 0x808000F8: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
    after_9:
    // 0x808000FC: jal         0x800DA544
    // 0x80800100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x80800100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80800104: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800108: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X18E0) << 16);
    // 0x8080010C: addiu       $a0, $zero, 0x9EF
    ctx->r4 = ADD32(0, 0X9EF);
    // 0x80800110: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80800114: lwc1        $f6, 0x18E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X18E0));
    // 0x80800118: jal         0x800DA298
    // 0x8080011C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x8080011C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_11:
    // 0x80800120: bne         $v0, $zero, L_80800164
    if (ctx->r2 != 0) {
        // 0x80800124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800164;
    }
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x80100094
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800138: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080013C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80800140: jal         0x8008A2D0
    // 0x80800144: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x80800144: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x80800148: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080014C: addiu       $t0, $zero, 0x62
    ctx->r8 = ADD32(0, 0X62);
    // 0x80800150: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800154: addiu       $a1, $zero, 0xFF4
    ctx->r5 = ADD32(0, 0XFF4);
    // 0x80800158: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8080015C: jal         0x8008A208
    // 0x80800160: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80800160: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_14:
L_80800164:
    // 0x80800164: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800168: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080016C: nop

    // 0x80800170: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80800174: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_80800178:
    // 0x80800178: lbu         $t5, 0x72($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X72);
    // 0x8080017C: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80800180: andi        $t6, $t5, 0xFF03
    ctx->r14 = ctx->r13 & 0XFF03;
    // 0x80800184: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80800188: sb          $t7, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r15;
    // 0x8080018C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800190: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800194: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800198: jr          $ra
    // 0x8080019C: nop

    return;
    // 0x8080019C: nop

;}
RECOMP_FUNC void func_80800B40_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B48: jal         0x80800A04
    // 0x80800B4C: nop

    func_80800A04_chfactoryworkerdirty(rdram, ctx);
        goto after_0;
    // 0x80800B4C: nop

    after_0:
    // 0x80800B50: addiu       $a0, $zero, 0x42D
    ctx->r4 = ADD32(0, 0X42D);
    // 0x80800B54: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x80800B58: jal         0x800DA7A8
    // 0x80800B5C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800DA7A8(rdram, ctx);
        goto after_1;
    // 0x80800B5C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x80800B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B68: jr          $ra
    // 0x80800B6C: nop

    return;
    // 0x80800B6C: nop

;}
RECOMP_FUNC void func_80110060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110060: jr          $ra
    // 0x80110064: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    return;
    // 0x80110064: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
;}
RECOMP_FUNC void baspin_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808000AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000B4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808000B8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x808000BC: lw          $t7, 0x118($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X118);
    // 0x808000C0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x808000C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C8: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x808000CC: lw          $t8, 0x118($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X118);
    // 0x808000D0: jal         0x80099A58
    // 0x808000D4: sb          $a3, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r7;
    func_80099A58(rdram, ctx);
        goto after_0;
    // 0x808000D4: sb          $a3, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r7;
    after_0:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x80084F78
    // 0x808000E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bareact_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x808000EC: jal         0x8008CDB8
    // 0x808000F0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    baanim_playForDuration_once(rdram, ctx);
        goto after_2;
    // 0x808000F0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    after_2:
    // 0x808000F4: jal         0x800A32EC
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A32EC(rdram, ctx);
        goto after_3;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800100: beql        $v0, $at, L_80800114
    if (ctx->r2 == ctx->r1) {
        // 0x80800104: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800114;
    }
    goto skip_0;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800108: jal         0x8009D9D4
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_4;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800114:
    // 0x80800114: jal         0x8009C128
    // 0x80800118: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_5;
    // 0x80800118: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x800A32C4
    // 0x80800124: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800A32C4(rdram, ctx);
        goto after_6;
    // 0x80800124: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x80800128: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080012C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800130: jal         0x800F1E6C
    // 0x80800134: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800F1E6C(rdram, ctx);
        goto after_7;
    // 0x80800134: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: jal         0x8009C914
    // 0x80800140: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    yaw_setIdeal(rdram, ctx);
        goto after_8;
    // 0x80800140: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_8:
    // 0x80800144: jal         0x8009C974
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_9;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x8009C4CC
    // 0x80800154: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_10;
    // 0x80800154: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x8009BF5C
    // 0x80800160: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_11;
    // 0x80800160: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x80800164: jal         0x8009C984
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_12;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080016C: lw          $t9, 0x118($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X118);
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800178: jal         0x800931AC
    // 0x8080017C: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    func_800931AC(rdram, ctx);
        goto after_13;
    // 0x8080017C: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    after_13:
    // 0x80800180: lw          $t0, 0x118($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X118);
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x8009328C
    // 0x8080018C: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    func_8009328C(rdram, ctx);
        goto after_14;
    // 0x8080018C: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    after_14:
    // 0x80800190: jal         0x80084F90
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800198: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080019C: jal         0x8009B9B0
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x8009B9C0
    // 0x808001AC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_17;
    // 0x808001AC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_17:
    // 0x808001B0: jal         0x8009BB00
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808001B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x8009BA68
    // 0x808001C4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x808001C4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_19:
    // 0x808001C8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x808001CC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808001DC: jal         0x8009FFD8
    // 0x808001E0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_20;
    // 0x808001E0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_20:
    // 0x808001E4: jal         0x8008E944
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_21;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808001EC: jal         0x8009514C
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_22;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x808001FC: jal         0x80085338
    // 0x80800200: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    _batimer_set(rdram, ctx);
        goto after_23;
    // 0x80800200: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_23:
    // 0x80800204: lw          $t2, 0x118($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X118);
    // 0x80800208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080020C: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x80800210: bnel        $t3, $at, L_80800244
    if (ctx->r11 != ctx->r1) {
        // 0x80800214: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800244;
    }
    goto skip_1;
    // 0x80800214: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800218: jal         0x80084C98
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_24;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800220: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800224: bnel        $v0, $at, L_80800244
    if (ctx->r2 != ctx->r1) {
        // 0x80800228: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800244;
    }
    goto skip_2;
    // 0x80800228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8080022C: jal         0x800A4CA8
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_25;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800234: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800238: jal         0x800893E8
    // 0x8080023C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncba1p_entrypoint_4(rdram, ctx);
        goto after_26;
    // 0x8080023C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80800240: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800244:
    // 0x80800244: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800248: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8080024C: jr          $ra
    // 0x80800250: nop

    return;
    // 0x80800250: nop

;}
RECOMP_FUNC void _bamovehover_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E30: syscall     138
    recomp_syscall_handler(rdram, ctx, 0x80084E30);
    return;
    // 0x80084E34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802470_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802470: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802474: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802478: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080247C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80802480: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80802484: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80802488: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x8080248C: bgezl       $t8, L_808024A0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80802490: lw          $a0, 0x3C($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X3C);
            goto L_808024A0;
    }
    goto skip_0;
    // 0x80802490: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    skip_0:
    // 0x80802494: b           L_808025C0
    // 0x80802498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808025C0;
    // 0x80802498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080249C: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
L_808024A0:
    // 0x808024A0: bne         $a0, $zero, L_808024B0
    if (ctx->r4 != 0) {
        // 0x808024A4: nop
    
            goto L_808024B0;
    }
    // 0x808024A4: nop

    // 0x808024A8: b           L_808025C0
    // 0x808024AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808025C0;
    // 0x808024AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808024B0:
    // 0x808024B0: jal         0x80106790
    // 0x808024B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808024B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x808024B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808024BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808024C0: jal         0x80100094
    // 0x808024C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808024C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808024C8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x808024CC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x808024D0: beql        $t9, $zero, L_80802560
    if (ctx->r25 == 0) {
        // 0x808024D4: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_80802560;
    }
    goto skip_1;
    // 0x808024D4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x808024D8: lbu         $t1, 0x12($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X12);
    // 0x808024DC: beql        $t1, $zero, L_80802560
    if (ctx->r9 == 0) {
        // 0x808024E0: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_80802560;
    }
    goto skip_2;
    // 0x808024E0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x808024E4: lbu         $t2, 0x13($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X13);
    // 0x808024E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808024EC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808024F0: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x808024F4: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x808024F8: bne         $t4, $zero, L_8080255C
    if (ctx->r12 != 0) {
        // 0x808024FC: sb          $t3, 0x13($v0)
        MEM_B(0X13, ctx->r2) = ctx->r11;
            goto L_8080255C;
    }
    // 0x808024FC: sb          $t3, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r11;
    // 0x80802500: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802504: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80802508: jal         0x80085708
    // 0x8080250C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x8080250C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_2:
    // 0x80802510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802514: jal         0x80101FDC
    // 0x80802518: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80802518: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
    // 0x8080251C: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80802520: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802524: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802528: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x8080252C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x80802530: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80802534: jal         0x800FC660
    // 0x80802538: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x80802538: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x8080253C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802540: addiu       $t7, $zero, 0xA3
    ctx->r15 = ADD32(0, 0XA3);
    // 0x80802544: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802548: addiu       $a1, $zero, 0x137B
    ctx->r5 = ADD32(0, 0X137B);
    // 0x8080254C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80802550: jal         0x8008A208
    // 0x80802554: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80802554: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80802558: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
L_8080255C:
    // 0x8080255C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80802560:
    // 0x80802560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802564: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80802568: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x8080256C: lbu         $a2, 0x10($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X10);
    // 0x80802570: blez        $a2, L_808025BC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80802574: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808025BC;
    }
    // 0x80802574: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802578: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
L_8080257C:
    // 0x8080257C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80802580: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80802584: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80802588: bne         $a1, $t8, L_808025B4
    if (ctx->r5 != ctx->r24) {
        // 0x8080258C: nop
    
            goto L_808025B4;
    }
    // 0x8080258C: nop

    // 0x80802590: addiu       $a0, $a2, -0x1
    ctx->r4 = ADD32(ctx->r6, -0X1);
    // 0x80802594: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x80802598: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8080259C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x808025A0: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x808025A4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x808025A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808025AC: b           L_808025C0
    // 0x808025B0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_808025C0;
    // 0x808025B0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_808025B4:
    // 0x808025B4: bne         $at, $zero, L_8080257C
    if (ctx->r1 != 0) {
        // 0x808025B8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8080257C;
    }
    // 0x808025B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_808025BC:
    // 0x808025BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808025C0:
    // 0x808025C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808025C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808025C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808025CC: jr          $ra
    // 0x808025D0: nop

    return;
    // 0x808025D0: nop

;}
RECOMP_FUNC void func_808000B8_chcauldronenergybars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000C4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000D4: beq         $t6, $at, L_808000EC
    if (ctx->r14 == ctx->r1) {
        // 0x808000D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000EC;
    }
    // 0x808000D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000DC: beq         $t6, $at, L_80800124
    if (ctx->r14 == ctx->r1) {
        // 0x808000E0: nop
    
            goto L_80800124;
    }
    // 0x808000E0: nop

    // 0x808000E4: b           L_808001B4
    // 0x808000E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001B4;
    // 0x808000E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000EC:
    // 0x808000EC: jal         0x800D9078
    // 0x808000F0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808000F0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_0:
    // 0x808000F4: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000F8: nop
    
            goto L_80800104;
    }
    // 0x808000F8: nop

    // 0x808000FC: jal         0x8010A590
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80800104:
    // 0x80800104: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2024, 0X2C0) << 16);
    // 0x80800108: addiu       $a3, $a3, 0x2C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2024, 0X2C0));
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800114: jal         0x80089D50
    // 0x80800118: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800118: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8080011C: b           L_808001B4
    // 0x80800120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001B4;
    // 0x80800120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800124:
    // 0x80800124: jal         0x800D90A4
    // 0x80800128: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x80800128: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x8080012C: beq         $v0, $zero, L_8080013C
    if (ctx->r2 == 0) {
        // 0x80800130: nop
    
            goto L_8080013C;
    }
    // 0x80800130: nop

    // 0x80800134: jal         0x800FFAB0
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8080013C:
    // 0x8080013C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2024, 0X2C0) << 16);
    // 0x80800140: addiu       $a3, $a3, 0x2C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2024, 0X2C0));
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080014C: jal         0x80089D50
    // 0x80800150: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800150: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80800154: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2024, 0X2B0) << 16);
    // 0x80800158: lwc1        $f4, 0x2B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2024, 0X2B0));
    // 0x8080015C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800160: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800164: lui         $a3, 0x3FB3
    ctx->r7 = S32(0X3FB3 << 16);
    // 0x80800168: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8080016C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800170: jal         0x800F10B4
    // 0x80800174: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800174: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800178: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080017C: jal         0x80089D30
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800184: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800188: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080018C: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800190: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800194: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800198: jal         0x800F10B4
    // 0x8080019C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x8080019C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x808001A0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001A4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x808001A8: nop

    // 0x808001AC: sb          $t8, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r24;
    // 0x808001B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001B4:
    // 0x808001B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
RECOMP_FUNC void chglowbo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A3C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1628, 0X14C0) << 16);
    // 0x80800A40: jr          $ra
    // 0x80800A44: addiu       $v0, $v0, 0x14C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1628, 0X14C0));
    return;
    // 0x80800A44: addiu       $v0, $v0, 0x14C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1628, 0X14C0));
;}
RECOMP_FUNC void func_80800DDC_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DE4: lw          $a2, 0x2C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X2C);
    // 0x80800DE8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800DEC: beq         $a2, $zero, L_80800E04
    if (ctx->r6 == 0) {
        // 0x80800DF0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800E04;
    }
    // 0x80800DF0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800DF4: jal         0x800B5450
    // 0x80800DF8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800B5450(rdram, ctx);
        goto after_0;
    // 0x80800DF8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800DFC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800E00: sw          $zero, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = 0;
L_80800E04:
    // 0x80800E04: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x80800E08: beq         $v0, $zero, L_80800E20
    if (ctx->r2 == 0) {
        // 0x80800E0C: addiu       $a0, $v0, -0x1
        ctx->r4 = ADD32(ctx->r2, -0X1);
            goto L_80800E20;
    }
    // 0x80800E0C: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80800E10: jal         0x800E1720
    // 0x80800E14: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800E1720(rdram, ctx);
        goto after_1;
    // 0x80800E14: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800E18: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800E1C: sw          $zero, 0x30($a1)
    MEM_W(0X30, ctx->r5) = 0;
L_80800E20:
    // 0x80800E20: lbu         $a0, 0x24($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X24);
    // 0x80800E24: beql        $a0, $zero, L_80800E40
    if (ctx->r4 == 0) {
        // 0x80800E28: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80800E40;
    }
    goto skip_0;
    // 0x80800E28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x80800E2C: jal         0x80089D48
    // 0x80800E30: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800E30: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800E34: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800E38: sb          $v0, 0x24($a1)
    MEM_B(0X24, ctx->r5) = ctx->r2;
    // 0x80800E3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800E40:
    // 0x80800E40: nop

    // 0x80800E44: swc1        $f4, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f4.u32l;
    // 0x80800E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E50: jr          $ra
    // 0x80800E54: nop

    return;
    // 0x80800E54: nop

;}
RECOMP_FUNC void func_80804680_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804680: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80804684: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804688: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8080468C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80804690: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80804694: jal         0x8008A0E0
    // 0x80804698: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80804698: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x8080469C: beq         $v0, $zero, L_80804774
    if (ctx->r2 == 0) {
        // 0x808046A0: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_80804774;
    }
    // 0x808046A0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808046A4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x808046A8: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x808046AC: jal         0x800EF1B8
    // 0x808046B0: lw          $a1, 0x48($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808046B0: lw          $a1, 0x48($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X48);
    after_1:
    // 0x808046B4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x808046B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808046BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808046C0: lwc1        $f4, 0x48($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X48);
    // 0x808046C4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808046C8: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x808046CC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808046D0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808046D4: jal         0x800EEB9C
    // 0x808046D8: nop

    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x808046D8: nop

    after_2:
    // 0x808046DC: lui         $a2, 0x4422
    ctx->r6 = S32(0X4422 << 16);
    // 0x808046E0: lui         $a3, 0x43A2
    ctx->r7 = S32(0X43A2 << 16);
    // 0x808046E4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808046E8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808046EC: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x808046F0: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x808046F4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808046F8: jal         0x8010D490
    // 0x808046FC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8010D490(rdram, ctx);
        goto after_3;
    // 0x808046FC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x80804700: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80804704: beq         $v0, $at, L_80804774
    if (ctx->r2 == ctx->r1) {
        // 0x80804708: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80804774;
    }
    // 0x80804708: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080470C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80804710: jal         0x800F5A00
    // 0x80804714: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x80804714: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80804718: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8080471C: jal         0x800EFB8C
    // 0x80804720: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EFB8C(rdram, ctx);
        goto after_5;
    // 0x80804720: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_5:
    // 0x80804724: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80804728: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080472C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80804730: lui         $a2, 0x4422
    ctx->r6 = S32(0X4422 << 16);
    // 0x80804734: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80804738: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080473C: lui         $a3, 0x44AF
    ctx->r7 = S32(0X44AF << 16);
    // 0x80804740: jal         0x800F10B4
    // 0x80804744: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80804744: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80804748: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8080474C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80804750: jal         0x800F1DF4
    // 0x80804754: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800F1DF4(rdram, ctx);
        goto after_7;
    // 0x80804754: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_7:
    // 0x80804758: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080475C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80804760: jal         0x800EEB9C
    // 0x80804764: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_800EEB9C(rdram, ctx);
        goto after_8;
    // 0x80804764: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80804768: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8080476C: jal         0x800F48BC
    // 0x80804770: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F48BC(rdram, ctx);
        goto after_9;
    // 0x80804770: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_9:
L_80804774:
    // 0x80804774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804778: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080477C: jr          $ra
    // 0x80804780: nop

    return;
    // 0x80804780: nop

;}
RECOMP_FUNC void func_808008CC_bsstonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808008D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808008D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808008DC: beq         $a1, $zero, L_808009C4
    if (ctx->r5 == 0) {
        // 0x808008E0: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_808009C4;
    }
    // 0x808008E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808008E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008E8: beq         $a1, $at, L_8080090C
    if (ctx->r5 == ctx->r1) {
        // 0x808008EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080090C;
    }
    // 0x808008EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008F0: beq         $a1, $at, L_80800998
    if (ctx->r5 == ctx->r1) {
        // 0x808008F4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800998;
    }
    // 0x808008F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808008FC: beq         $a1, $at, L_808009B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800900: nop
    
            goto L_808009B0;
    }
    // 0x80800900: nop

    // 0x80800904: b           L_808009C8
    // 0x80800908: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
        goto L_808009C8;
    // 0x80800908: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_8080090C:
    // 0x8080090C: jal         0x8008CABC
    // 0x80800910: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800910: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
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
    // 0x80800928: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800928: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    after_2:
    // 0x8080092C: lui         $a1, 0x3F22
    ctx->r5 = S32(0X3F22 << 16);
    // 0x80800930: ori         $a1, $a1, 0xEB1C
    ctx->r5 = ctx->r5 | 0XEB1C;
    // 0x80800934: jal         0x8008B24C
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_3;
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080093C: lui         $a1, 0x3F22
    ctx->r5 = S32(0X3F22 << 16);
    // 0x80800940: lui         $a2, 0x3F41
    ctx->r6 = S32(0X3F41 << 16);
    // 0x80800944: ori         $a2, $a2, 0xF213
    ctx->r6 = ctx->r6 | 0XF213;
    // 0x80800948: ori         $a1, $a1, 0xEB1C
    ctx->r5 = ctx->r5 | 0XEB1C;
    // 0x8080094C: jal         0x8008B1D4
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800958: jal         0x8008B1BC
    // 0x8080095C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x8080095C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_5:
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800964: jal         0x8008B134
    // 0x80800968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080096C: jal         0x8008B064
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800974: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80800978: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080097C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800984: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800988: jal         0x8009FFD8
    // 0x8080098C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x8080098C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x80800990: b           L_808009C8
    // 0x80800994: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
        goto L_808009C8;
    // 0x80800994: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80800998:
    // 0x80800998: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080099C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808009A0: jal         0x8008CF1C
    // 0x808009A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_9;
    // 0x808009A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
    // 0x808009A8: b           L_808009C8
    // 0x808009AC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
        goto L_808009C8;
    // 0x808009AC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_808009B0:
    // 0x808009B0: jal         0x800A2E18
    // 0x808009B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800A2E18(rdram, ctx);
        goto after_10;
    // 0x808009B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x808009B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009BC: jal         0x8009B9B0
    // 0x808009C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x808009C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
L_808009C4:
    // 0x808009C4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_808009C8:
    // 0x808009C8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x808009CC: sw          $t8, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->r24;
    // 0x808009D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808009D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009DC: jr          $ra
    // 0x808009E0: nop

    return;
    // 0x808009E0: nop

;}
