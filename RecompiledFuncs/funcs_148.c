#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080016C_chpumproomswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800170: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800174: addiu       $v1, $zero, 0x9E7
    ctx->r3 = ADD32(0, 0X9E7);
    // 0x80800178: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080017C: bne         $t7, $at, L_8080018C
    if (ctx->r15 != ctx->r1) {
        // 0x80800180: nop
    
            goto L_8080018C;
    }
    // 0x80800180: nop

    // 0x80800184: jr          $ra
    // 0x80800188: addiu       $v0, $zero, 0x9E6
    ctx->r2 = ADD32(0, 0X9E6);
    return;
    // 0x80800188: addiu       $v0, $zero, 0x9E6
    ctx->r2 = ADD32(0, 0X9E6);
L_8080018C:
    // 0x8080018C: jr          $ra
    // 0x80800190: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800190: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void idtwinklecolour_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800210: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800214: lh          $t6, 0x1E($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X1E);
    // 0x80800218: lh          $v0, 0x1C($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X1C);
    // 0x8080021C: bnel        $t6, $v0, L_80800244
    if (ctx->r14 != ctx->r2) {
        // 0x80800220: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80800244;
    }
    goto skip_0;
    // 0x80800220: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80800224: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x80800228: lh          $v0, 0x1C($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X1C);
    // 0x8080022C: sh          $t7, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r15;
    // 0x80800230: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x80800234: sh          $t8, 0x10($a3)
    MEM_H(0X10, ctx->r7) = ctx->r24;
    // 0x80800238: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x8080023C: sh          $t9, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r25;
    // 0x80800240: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
L_80800244:
    // 0x80800244: jr          $ra
    // 0x80800248: sh          $t0, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r8;
    return;
    // 0x80800248: sh          $t0, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void seqdefine_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80800004: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(30, 0X20) << 16);
    // 0x80800008: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080000C: jr          $ra
    // 0x80800010: lh          $v0, 0x20($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(30, 0X20));
    return;
    // 0x80800010: lh          $v0, 0x20($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(30, 0X20));
    // 0x80800014: nop

    // 0x80800018: nop

    // 0x8080001C: nop

;}
RECOMP_FUNC void plcamera_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800374: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080037C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80800380: jal         0x800F5EF8
    // 0x80800384: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x80800384: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800388: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8080038C: jal         0x80110014
    // 0x80800390: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x80800390: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800394: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80800398: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8080039C: jal         0x800F5A00
    // 0x808003A0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808003A0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x808003A4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808003A8: jal         0x801107F0
    // 0x808003AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_801107F0(rdram, ctx);
        goto after_3;
    // 0x808003AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_3:
    // 0x808003B0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808003B4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808003B8: jal         0x800EFB24
    // 0x808003BC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x808003BC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x808003C0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808003C4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x808003C8: jal         0x800EFB24
    // 0x808003CC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x808003CC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x808003D0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808003D4: jal         0x800EEAA4
    // 0x808003D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EEAA4(rdram, ctx);
        goto after_6;
    // 0x808003D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x808003DC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808003E0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808003E4: jal         0x80110720
    // 0x808003E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80110720(rdram, ctx);
        goto after_7;
    // 0x808003E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808003EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003F0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808003F4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808003F8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808003FC: nop

    // 0x80800400: bc1fl       L_8080044C
    if (!c1cs) {
        // 0x80800404: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080044C;
    }
    goto skip_0;
    // 0x80800404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800408: jal         0x80800300
    // 0x8080040C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80800300_plcamera(rdram, ctx);
        goto after_8;
    // 0x8080040C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_8:
    // 0x80800410: beq         $v0, $zero, L_80800448
    if (ctx->r2 == 0) {
        // 0x80800414: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_80800448;
    }
    // 0x80800414: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80800418: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8080041C: jal         0x800A516C
    // 0x80800420: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800A516C(rdram, ctx);
        goto after_9;
    // 0x80800420: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_9:
    // 0x80800424: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800428: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080042C: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800430: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80800434: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800438: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8080043C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x80800440: jal         0x8010FE14
    // 0x80800444: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    func_8010FE14(rdram, ctx);
        goto after_10;
    // 0x80800444: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_10:
L_80800448:
    // 0x80800448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080044C:
    // 0x8080044C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800450: jr          $ra
    // 0x80800454: nop

    return;
    // 0x80800454: nop

;}
RECOMP_FUNC void func_808021C4_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808021C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X37B8) << 16);
    // 0x808021CC: lwc1        $f4, 0x37B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X37B8));
    // 0x808021D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808021D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808021D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808021DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808021E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808021E4: jal         0x80100094
    // 0x808021E8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808021E8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808021EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808021F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808021F4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808021F8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808021FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802200: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802204: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80802208: jal         0x80105A9C
    // 0x8080220C: nop

    func_80105A9C(rdram, ctx);
        goto after_1;
    // 0x8080220C: nop

    after_1:
    // 0x80802210: jal         0x80105834
    // 0x80802214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_2;
    // 0x80802214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802218: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080221C: jal         0x800F1DCC
    // 0x80802220: lwc1        $f14, 0x4($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X4);
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x80802220: lwc1        $f14, 0x4($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X4);
    after_3:
    // 0x80802224: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802228: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080222C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802230: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80802234: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80802238: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X37BC) << 16);
    // 0x8080223C: lwc1        $f10, 0x37BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X37BC));
    // 0x80802240: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802244: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80802248: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8080224C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80802250: swc1        $f16, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f16.u32l;
    // 0x80802254: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80802258: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080225C: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x80802260: lbu         $t6, 0xE($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XE);
    // 0x80802264: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x80802268: bne         $t6, $zero, L_80802280
    if (ctx->r14 != 0) {
        // 0x8080226C: nop
    
            goto L_80802280;
    }
    // 0x8080226C: nop

    // 0x80802270: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802274: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80802278: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8080227C: sb          $t7, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r15;
L_80802280:
    // 0x80802280: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X37C0) << 16);
    // 0x80802284: lwc1        $f10, 0x37C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X37C0));
    // 0x80802288: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8080228C: lwc1        $f14, 0x44($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80802290: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80802294: jal         0x800F1DCC
    // 0x80802298: nop

    func_800F1DCC(rdram, ctx);
        goto after_4;
    // 0x80802298: nop

    after_4:
    // 0x8080229C: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808022A0: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808022A4: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808022A8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808022AC: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808022B0: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x808022B4: jal         0x800F1DCC
    // 0x808022B8: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x808022B8: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x808022BC: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808022C0: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808022C4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808022C8: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x808022CC: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x808022D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808022D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808022D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808022DC: jr          $ra
    // 0x808022E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808022E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80804238_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804238: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080423C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804240: jal         0x801065A4
    // 0x80804244: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_801065A4(rdram, ctx);
        goto after_0;
    // 0x80804244: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80804248: beq         $v0, $zero, L_80804288
    if (ctx->r2 == 0) {
        // 0x8080424C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80804288;
    }
    // 0x8080424C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804250: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80804254: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80804258: addiu       $a2, $a2, 0x6CA0
    ctx->r6 = ADD32(ctx->r6, 0X6CA0);
    // 0x8080425C: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x80804260: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80804264: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80804268: jal         0x80088660
    // 0x8080426C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080426C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80804270: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80804274: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80804278: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080427C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80804280: jal         0x80088660
    // 0x80804284: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80804284: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    after_2:
L_80804288:
    // 0x80804288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080428C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804290: jr          $ra
    // 0x80804294: nop

    return;
    // 0x80804294: nop

;}
RECOMP_FUNC void func_800DF714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF714: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF718: jr          $ra
    // 0x800DF71C: sw          $a0, -0x3680($at)
    MEM_W(-0X3680, ctx->r1) = ctx->r4;
    return;
    // 0x800DF71C: sw          $a0, -0x3680($at)
    MEM_W(-0X3680, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _chnastycavemen_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AF0: syscall     193
    recomp_syscall_handler(rdram, ctx, 0x80085AF0);
    return;
    // 0x80085AF4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080121C_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080121C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801224: jal         0x80085148
    // 0x80801228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baspin_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080122C: jal         0x808008D8
    // 0x80801230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008D8_bssub(rdram, ctx);
        goto after_1;
    // 0x80801230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080123C: jr          $ra
    // 0x80801240: nop

    return;
    // 0x80801240: nop

;}
RECOMP_FUNC void dbskeleton_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x808000D8: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x808000DC: jr          $ra
    // 0x808000E0: lh          $v0, 0x14($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X14);
    return;
    // 0x808000E0: lh          $v0, 0x14($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X14);
    // 0x808000E4: nop

    // 0x808000E8: nop

    // 0x808000EC: nop

;}
RECOMP_FUNC void func_800B3390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3390: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800B3394: lw          $a1, 0x10($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X10);
    // 0x800B3398: addiu       $v1, $a0, 0x18
    ctx->r3 = ADD32(ctx->r4, 0X18);
    // 0x800B339C: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x800B33A0: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x800B33A4: beq         $at, $zero, L_800B33D0
    if (ctx->r1 == 0) {
        // 0x800B33A8: nop
    
            goto L_800B33D0;
    }
    // 0x800B33A8: nop

    // 0x800B33AC: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
L_800B33B0:
    // 0x800B33B0: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800B33B4: nop

    // 0x800B33B8: bc1t        L_800B33D0
    if (c1cs) {
        // 0x800B33BC: nop
    
            goto L_800B33D0;
    }
    // 0x800B33BC: nop

    // 0x800B33C0: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x800B33C4: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x800B33C8: bnel        $at, $zero, L_800B33B0
    if (ctx->r1 != 0) {
        // 0x800B33CC: lwc1        $f4, 0x18($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
            goto L_800B33B0;
    }
    goto skip_0;
    // 0x800B33CC: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    skip_0:
L_800B33D0:
    // 0x800B33D0: bnel        $v1, $a1, L_800B3404
    if (ctx->r3 != ctx->r5) {
        // 0x800B33D4: lw          $t8, 0x14($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X14);
            goto L_800B3404;
    }
    goto skip_1;
    // 0x800B33D4: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    skip_1:
    // 0x800B33D8: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800B33DC: addiu       $t7, $a1, 0x1C
    ctx->r15 = ADD32(ctx->r5, 0X1C);
    // 0x800B33E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B33E4: sltu        $at, $a1, $t6
    ctx->r1 = ctx->r5 < ctx->r14 ? 1 : 0;
    // 0x800B33E8: beq         $at, $zero, L_800B33F8
    if (ctx->r1 == 0) {
        // 0x800B33EC: nop
    
            goto L_800B33F8;
    }
    // 0x800B33EC: nop

    // 0x800B33F0: jr          $ra
    // 0x800B33F4: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    return;
    // 0x800B33F4: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
L_800B33F8:
    // 0x800B33F8: jr          $ra
    // 0x800B33FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B33FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3400: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
L_800B3404:
    // 0x800B3404: bnel        $t8, $a1, L_800B341C
    if (ctx->r24 != ctx->r5) {
        // 0x800B3408: subu        $t2, $a1, $v1
        ctx->r10 = SUB32(ctx->r5, ctx->r3);
            goto L_800B341C;
    }
    goto skip_2;
    // 0x800B3408: subu        $t2, $a1, $v1
    ctx->r10 = SUB32(ctx->r5, ctx->r3);
    skip_2:
    // 0x800B340C: addiu       $t9, $a1, -0x1C
    ctx->r25 = ADD32(ctx->r5, -0X1C);
    // 0x800B3410: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x800B3414: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800B3418: subu        $t2, $a1, $v1
    ctx->r10 = SUB32(ctx->r5, ctx->r3);
L_800B341C:
    // 0x800B341C: div         $zero, $t2, $t1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r9)));
    // 0x800B3420: mflo        $t3
    ctx->r11 = lo;
    // 0x800B3424: addiu       $a2, $a1, 0x1C
    ctx->r6 = ADD32(ctx->r5, 0X1C);
    // 0x800B3428: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800B342C: multu       $t3, $t1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3430: bne         $t1, $zero, L_800B343C
    if (ctx->r9 != 0) {
        // 0x800B3434: nop
    
            goto L_800B343C;
    }
    // 0x800B3434: nop

    // 0x800B3438: break       7
    do_break(2148217912);
L_800B343C:
    // 0x800B343C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B3440: bne         $t1, $at, L_800B3454
    if (ctx->r9 != ctx->r1) {
        // 0x800B3444: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B3454;
    }
    // 0x800B3444: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B3448: bne         $t2, $at, L_800B3454
    if (ctx->r10 != ctx->r1) {
        // 0x800B344C: nop
    
            goto L_800B3454;
    }
    // 0x800B344C: nop

    // 0x800B3450: break       6
    do_break(2148217936);
L_800B3454:
    // 0x800B3454: mflo        $a3
    ctx->r7 = lo;
    // 0x800B3458: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800B345C: blez        $a3, L_800B3484
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800B3460: addiu       $t0, $a1, -0x4
        ctx->r8 = ADD32(ctx->r5, -0X4);
            goto L_800B3484;
    }
    // 0x800B3460: addiu       $t0, $a1, -0x4
    ctx->r8 = ADD32(ctx->r5, -0X4);
L_800B3464:
    // 0x800B3464: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800B3468: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x800B346C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800B3470: addiu       $t0, $t0, -0x4
    ctx->r8 = ADD32(ctx->r8, -0X4);
    // 0x800B3474: bgtz        $a3, L_800B3464
    if (SIGNED(ctx->r7) > 0) {
        // 0x800B3478: sw          $t4, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r12;
            goto L_800B3464;
    }
    // 0x800B3478: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B347C: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x800B3480: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
L_800B3484:
    // 0x800B3484: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
    // 0x800B3488: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B348C: jr          $ra
    // 0x800B3490: nop

    return;
    // 0x800B3490: nop

;}
RECOMP_FUNC void func_8010EACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010EACC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010EAD0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8010EAD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010EAD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010EADC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8010EAE0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8010EAE4: bgez        $a1, L_8010EAF4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8010EAE8: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_8010EAF4;
    }
    // 0x8010EAE8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8010EAEC: b           L_8010EAF8
    // 0x8010EAF0: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
        goto L_8010EAF8;
    // 0x8010EAF0: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
L_8010EAF4:
    // 0x8010EAF4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8010EAF8:
    // 0x8010EAF8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010EAFC: addiu       $v1, $v1, 0x7080
    ctx->r3 = ADD32(ctx->r3, 0X7080);
    // 0x8010EB00: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x8010EB04: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8010EB08: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8010EB0C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8010EB10: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8010EB14: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x8010EB18: jal         0x800DF8B4
    // 0x8010EB1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8B4(rdram, ctx);
        goto after_0;
    // 0x8010EB1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8010EB20: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x8010EB24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8010EB28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010EB2C: jal         0x800B237C
    // 0x8010EB30: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800B237C(rdram, ctx);
        goto after_1;
    // 0x8010EB30: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x8010EB34: jal         0x800DF8C4
    // 0x8010EB38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8C4(rdram, ctx);
        goto after_2;
    // 0x8010EB38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8010EB3C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8010EB40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010EB44: jal         0x80019224
    // 0x8010EB48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80019224(rdram, ctx);
        goto after_3;
    // 0x8010EB48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8010EB4C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010EB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010EB54: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8010EB58: jal         0x800DF900
    // 0x8010EB5C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    func_800DF900(rdram, ctx);
        goto after_4;
    // 0x8010EB5C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8010EB60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010EB64: jal         0x800C8760
    // 0x8010EB68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8760(rdram, ctx);
        goto after_5;
    // 0x8010EB68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8010EB6C: beq         $v0, $zero, L_8010EBA0
    if (ctx->r2 == 0) {
        // 0x8010EB70: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8010EBA0;
    }
    // 0x8010EB70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8010EB74:
    // 0x8010EB74: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8010EB78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010EB7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8010EB80: jal         0x8010E924
    // 0x8010EB84: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_8010E924(rdram, ctx);
        goto after_6;
    // 0x8010EB84: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x8010EB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010EB8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010EB90: jal         0x800C878C
    // 0x8010EB94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800C878C(rdram, ctx);
        goto after_7;
    // 0x8010EB94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x8010EB98: bne         $v0, $zero, L_8010EB74
    if (ctx->r2 != 0) {
        // 0x8010EB9C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8010EB74;
    }
    // 0x8010EB9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8010EBA0:
    // 0x8010EBA0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010EBA4: addiu       $v0, $v0, 0x7080
    ctx->r2 = ADD32(ctx->r2, 0X7080);
    // 0x8010EBA8: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8010EBAC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8010EBB0: subu        $t0, $t9, $v0
    ctx->r8 = SUB32(ctx->r25, ctx->r2);
    // 0x8010EBB4: addiu       $t1, $t0, -0x1C
    ctx->r9 = ADD32(ctx->r8, -0X1C);
    // 0x8010EBB8: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8010EBBC: mflo        $t2
    ctx->r10 = lo;
    // 0x8010EBC0: sb          $t2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r10;
    // 0x8010EBC4: jal         0x80018DAC
    // 0x8010EBC8: nop

    mlMtxPop(rdram, ctx);
        goto after_8;
    // 0x8010EBC8: nop

    after_8:
    // 0x8010EBCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010EBD0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8010EBD4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8010EBD8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8010EBDC: jr          $ra
    // 0x8010EBE0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8010EBE0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bsstonehead_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801220: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801228: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080122C: jal         0x800845C8
    // 0x80801230: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801230: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80801234: beq         $v0, $zero, L_80801244
    if (ctx->r2 == 0) {
        // 0x80801238: nop
    
            goto L_80801244;
    }
    // 0x80801238: nop

    // 0x8080123C: jal         0x808000CC
    // 0x80801240: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808000CC_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x80801240: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80801244:
    // 0x80801244: jal         0x80084600
    // 0x80801248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _babounce_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80801248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080124C: beq         $v0, $zero, L_80801258
    if (ctx->r2 == 0) {
        // 0x80801250: addiu       $t6, $zero, 0xB3
        ctx->r14 = ADD32(0, 0XB3);
            goto L_80801258;
    }
    // 0x80801250: addiu       $t6, $zero, 0xB3
    ctx->r14 = ADD32(0, 0XB3);
    // 0x80801254: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80801258:
    // 0x80801258: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080125C: jal         0x8009E5C8
    // 0x80801260: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80801260: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080126C: jr          $ra
    // 0x80801270: nop

    return;
    // 0x80801270: nop

;}
RECOMP_FUNC void func_800819B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800819B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800819B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800819BC: jal         0x80081AA4
    // 0x800819C0: nop

    func_80081AA4(rdram, ctx);
        goto after_0;
    // 0x800819C0: nop

    after_0:
    // 0x800819C4: beq         $v0, $zero, L_800819D4
    if (ctx->r2 == 0) {
        // 0x800819C8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800819D4;
    }
    // 0x800819C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800819CC: jal         0x800819E4
    // 0x800819D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ovl_unload(rdram, ctx);
        goto after_1;
    // 0x800819D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_800819D4:
    // 0x800819D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800819D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800819DC: jr          $ra
    // 0x800819E0: nop

    return;
    // 0x800819E0: nop

;}
RECOMP_FUNC void ncpodfixpos_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080016C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800170: sh          $a2, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r6;
    // 0x80800174: jal         0x80800118
    // 0x80800178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800118_ncpodfixpos(rdram, ctx);
        goto after_0;
    // 0x80800178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800184: jr          $ra
    // 0x80800188: nop

    return;
    // 0x80800188: nop

;}
RECOMP_FUNC void mlwave_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080021C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800220: swc1        $f12, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f12.u32l;
    // 0x80800224: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80800228: jr          $ra
    // 0x8080022C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x8080022C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880A0: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x800880A0);
    return;
    // 0x800880A4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8080145C_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080145C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801464: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801468: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080146C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801470: beq         $a2, $at, L_8080148C
    if (ctx->r6 == ctx->r1) {
        // 0x80801474: sw          $a2, 0x5C($a0)
        MEM_W(0X5C, ctx->r4) = ctx->r6;
            goto L_8080148C;
    }
    // 0x80801474: sw          $a2, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r6;
    // 0x80801478: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080147C: beq         $a2, $at, L_808014F8
    if (ctx->r6 == ctx->r1) {
        // 0x80801480: nop
    
            goto L_808014F8;
    }
    // 0x80801480: nop

    // 0x80801484: b           L_80801510
    // 0x80801488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801510;
    // 0x80801488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080148C:
    // 0x8080148C: jal         0x80800160
    // 0x80801490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800160_ncpoducam(rdram, ctx);
        goto after_0;
    // 0x80801490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801494: jal         0x80800000
    // 0x80801498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_ncpoducam(rdram, ctx);
        goto after_1;
    // 0x80801498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080149C: jal         0x800A5854
    // 0x808014A0: lh          $a0, 0x58($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X58);
    func_800A5854(rdram, ctx);
        goto after_2;
    // 0x808014A0: lh          $a0, 0x58($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X58);
    after_2:
    // 0x808014A4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x808014A8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808014AC: beq         $v1, $at, L_808014D8
    if (ctx->r3 == ctx->r1) {
        // 0x808014B0: sb          $v0, 0x60($s0)
        MEM_B(0X60, ctx->r16) = ctx->r2;
            goto L_808014D8;
    }
    // 0x808014B0: sb          $v0, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r2;
    // 0x808014B4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808014B8: beq         $v1, $at, L_808014E8
    if (ctx->r3 == ctx->r1) {
        // 0x808014BC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_808014E8;
    }
    // 0x808014BC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808014C0: bnel        $v1, $at, L_80801510
    if (ctx->r3 != ctx->r1) {
        // 0x808014C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801510;
    }
    goto skip_0;
    // 0x808014C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808014C8: jal         0x80800D28
    // 0x808014CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D28_ncpoducam(rdram, ctx);
        goto after_3;
    // 0x808014CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808014D0: b           L_80801510
    // 0x808014D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801510;
    // 0x808014D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014D8:
    // 0x808014D8: jal         0x80801274
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801274_ncpoducam(rdram, ctx);
        goto after_4;
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808014E0: b           L_80801510
    // 0x808014E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801510;
    // 0x808014E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014E8:
    // 0x808014E8: jal         0x80800F64
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F64_ncpoducam(rdram, ctx);
        goto after_5;
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808014F0: b           L_80801510
    // 0x808014F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801510;
    // 0x808014F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014F8:
    // 0x808014F8: jal         0x80110024
    // 0x808014FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80110024(rdram, ctx);
        goto after_6;
    // 0x808014FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_6:
    // 0x80801500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801504: jal         0x80089520
    // 0x80801508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_12(rdram, ctx);
        goto after_7;
    // 0x80801508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8080150C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801510:
    // 0x80801510: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801518: jr          $ra
    // 0x8080151C: nop

    return;
    // 0x8080151C: nop

;}
RECOMP_FUNC void anseq_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800390: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800394: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800398: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080039C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808003A0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808003A4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808003A8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808003AC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808003B0: jal         0x800B2890
    // 0x808003B4: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    func_800B2890(rdram, ctx);
        goto after_0;
    // 0x808003B4: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    after_0:
    // 0x808003B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808003BC: jal         0x800B28C4
    // 0x808003C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x808003C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808003C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003C8: jal         0x800B296C
    // 0x808003CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    vector_end(rdram, ctx);
        goto after_2;
    // 0x808003CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808003D0: beq         $v0, $s0, L_80800424
    if (ctx->r2 == ctx->r16) {
        // 0x808003D4: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80800424;
    }
    // 0x808003D4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808003D8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808003DC: nop

    // 0x808003E0: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
L_808003E4:
    // 0x808003E4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x808003E8: nop

    // 0x808003EC: bc1tl       L_80800408
    if (c1cs) {
        // 0x808003F0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800408;
    }
    goto skip_0;
    // 0x808003F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x808003F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003F8: jal         0x8008B348
    // 0x808003FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x808003FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80800400: beq         $v0, $zero, L_80800410
    if (ctx->r2 == 0) {
        // 0x80800404: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800410;
    }
    // 0x80800404: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800408:
    // 0x80800408: jal         0x80800000
    // 0x8080040C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800000_anseq(rdram, ctx);
        goto after_4;
    // 0x8080040C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
L_80800410:
    // 0x80800410: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80800414: jal         0x800B296C
    // 0x80800418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    vector_end(rdram, ctx);
        goto after_5;
    // 0x80800418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8080041C: bnel        $v0, $s0, L_808003E4
    if (ctx->r2 != ctx->r16) {
        // 0x80800420: lwc1        $f0, 0x0($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
            goto L_808003E4;
    }
    goto skip_1;
    // 0x80800420: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80800424:
    // 0x80800424: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800428: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8080042C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800430: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800434: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800438: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8080043C: jr          $ra
    // 0x80800440: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800440: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800000_chfactorystationdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80088840
    // 0x80800010: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_0:
    // 0x80800014: bnel        $v0, $zero, L_80800048
    if (ctx->r2 != 0) {
        // 0x80800018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800048;
    }
    goto skip_0;
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080001C: jal         0x800DA298
    // 0x80800020: addiu       $a0, $zero, 0x163
    ctx->r4 = ADD32(0, 0X163);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a0, $zero, 0x163
    ctx->r4 = ADD32(0, 0X163);
    after_1:
    // 0x80800024: beq         $v0, $zero, L_8080003C
    if (ctx->r2 == 0) {
        // 0x80800028: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080003C;
    }
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080002C: jal         0x800FFAB0
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800034: b           L_80800048
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800048;
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080003C:
    // 0x8080003C: jal         0x80101FDC
    // 0x80800040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800048:
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void mlMtxRotatePYR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019118: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8001911C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80019120: jal         0x80018FE8
    // 0x80019124: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    mlMtxRotYaw(rdram, ctx);
        goto after_0;
    // 0x80019124: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_0:
    // 0x80019128: jal         0x80018F50
    // 0x8001912C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    mlMtxRotPitch(rdram, ctx);
        goto after_1;
    // 0x8001912C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80019130: jal         0x8001907C
    // 0x80019134: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    mlMtxRotRoll(rdram, ctx);
        goto after_2;
    // 0x80019134: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80019138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001913C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019140: jr          $ra
    // 0x80019144: nop

    return;
    // 0x80019144: nop

;}
RECOMP_FUNC void func_800B26F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B26F0: lw          $v1, 0x28($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X28);
    // 0x800B26F4: bne         $v1, $zero, L_800B2704
    if (ctx->r3 != 0) {
        // 0x800B26F8: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B2704;
    }
    // 0x800B26F8: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B26FC: jr          $ra
    // 0x800B2700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B2700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2704:
    // 0x800B2704: jr          $ra
    // 0x800B2708: nop

    return;
    // 0x800B2708: nop

;}
RECOMP_FUNC void bashoessuck_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001CC: jal         0x800932CC
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800932CC(rdram, ctx);
        goto after_0;
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001D8: jal         0x8009BF5C
    // 0x808001DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x808001DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x808001E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001E4: jal         0x8009C4CC
    // 0x808001E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x808001E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808001EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: jal         0x800961AC
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808001F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800200: jr          $ra
    // 0x80800204: nop

    return;
    // 0x80800204: nop

;}
RECOMP_FUNC void ncbasub_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: jal         0x801124D0
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: jal         0x80115858
    // 0x80800024: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80115858(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080002C: jal         0x80115870
    // 0x80800030: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80115870(rdram, ctx);
        goto after_2;
    // 0x80800030: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void bsdronesuckunder_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800068: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800074: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800078: jal         0x80084660
    // 0x8080007C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080007C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800088: jal         0x8008CB3C
    // 0x8080008C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080008C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800090: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80800094: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000A4: jal         0x8009FFD8
    // 0x808000A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808000A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808000AC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x808000B0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x80085338
    // 0x808000BC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _batimer_set(rdram, ctx);
        goto after_3;
    // 0x808000BC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x800961A0
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961A0(rdram, ctx);
        goto after_4;
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808000CC: jal         0x80800000
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsdronesuckunder(rdram, ctx);
        goto after_5;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

;}
RECOMP_FUNC void func_8009CBDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CBDC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8009CBE0: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8009CBE4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009CBE8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8009CBEC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8009CBF0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009CBF4: jr          $ra
    // 0x8009CBF8: lh          $v0, 0x7F32($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7F32);
    return;
    // 0x8009CBF8: lh          $v0, 0x7F32($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7F32);
;}
RECOMP_FUNC void gczoombox_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808033A0: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x808033A4: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x808033A8: jr          $ra
    // 0x808033AC: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x808033AC: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void basquash_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: jr          $ra
    // 0x808000E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chfactorymaindoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800410: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2320, 0X51C) << 16);
    // 0x80800414: jr          $ra
    // 0x80800418: addiu       $v0, $v0, 0x51C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2320, 0X51C));
    return;
    // 0x80800418: addiu       $v0, $v0, 0x51C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2320, 0X51C));
;}
RECOMP_FUNC void func_800F5E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5E24: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5E2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5E34: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5E38: jal         0x800966BC
    // 0x800F5E3C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800966BC(rdram, ctx);
        goto after_0;
    // 0x800F5E3C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5E48: jr          $ra
    // 0x800F5E4C: nop

    return;
    // 0x800F5E4C: nop

;}
RECOMP_FUNC void func_80802214_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802218: addiu       $at, $zero, 0x1359
    ctx->r1 = ADD32(0, 0X1359);
    // 0x8080221C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802220: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802224: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802228: bne         $a1, $at, L_8080224C
    if (ctx->r5 != ctx->r1) {
        // 0x8080222C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8080224C;
    }
    // 0x8080222C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80802230: jal         0x800C064C
    // 0x80802234: nop

    func_800C064C(rdram, ctx);
        goto after_0;
    // 0x80802234: nop

    after_0:
    // 0x80802238: addiu       $at, $zero, 0x1358
    ctx->r1 = ADD32(0, 0X1358);
    // 0x8080223C: bnel        $v0, $at, L_80802250
    if (ctx->r2 != ctx->r1) {
        // 0x80802240: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80802250;
    }
    goto skip_0;
    // 0x80802240: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80802244: jal         0x800C067C
    // 0x80802248: addiu       $a0, $zero, 0x1358
    ctx->r4 = ADD32(0, 0X1358);
    func_800C067C(rdram, ctx);
        goto after_1;
    // 0x80802248: addiu       $a0, $zero, 0x1358
    ctx->r4 = ADD32(0, 0X1358);
    after_1:
L_8080224C:
    // 0x8080224C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_80802250:
    // 0x80802250: addiu       $t8, $zero, 0xB5
    ctx->r24 = ADD32(0, 0XB5);
    // 0x80802254: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802258: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8080225C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802260: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80802264: jal         0x8008A208
    // 0x80802268: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80802268: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_2:
    // 0x8080226C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802274: jr          $ra
    // 0x80802278: nop

    return;
    // 0x80802278: nop

;}
RECOMP_FUNC void func_80800CAC_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800CB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800CB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800CBC: jal         0x8080076C
    // 0x80800CC0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_8080076C_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80800CC0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800CC4: jal         0x8080078C
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080078C_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800CCC: jal         0x8080016C
    // 0x80800CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080016C_bskaztorpedo(rdram, ctx);
        goto after_2;
    // 0x80800CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800CD4: jal         0x8080024C
    // 0x80800CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080024C_bskaztorpedo(rdram, ctx);
        goto after_3;
    // 0x80800CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800CDC: jal         0x808002E0
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002E0_bskaztorpedo(rdram, ctx);
        goto after_4;
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800CE4: jal         0x80800034
    // 0x80800CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800034_bskaztorpedo(rdram, ctx);
        goto after_5;
    // 0x80800CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800CEC: jal         0x80800000
    // 0x80800CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskaztorpedo(rdram, ctx);
        goto after_6;
    // 0x80800CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800CF4: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80800CF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800CFC: addiu       $t6, $zero, 0x159
    ctx->r14 = ADD32(0, 0X159);
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D04: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800D08: nop

    // 0x80800D0C: bc1f        L_80800D18
    if (!c1cs) {
        // 0x80800D10: nop
    
            goto L_80800D18;
    }
    // 0x80800D10: nop

    // 0x80800D14: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800D18:
    // 0x80800D18: jal         0x8009E5C8
    // 0x80800D1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80800D1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800D2C: jr          $ra
    // 0x80800D30: nop

    return;
    // 0x80800D30: nop

;}
RECOMP_FUNC void func_800A2CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A2CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2CF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A2CF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A2CF8: jal         0x8008CABC
    // 0x800A2CFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x800A2CFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A2D00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A2D04: jal         0x8008B348
    // 0x800A2D08: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x800A2D08: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800A2D0C: beq         $v0, $zero, L_800A2D1C
    if (ctx->r2 == 0) {
        // 0x800A2D10: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800A2D1C;
    }
    // 0x800A2D10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A2D14: jal         0x800A2EEC
    // 0x800A2D18: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800A2EEC(rdram, ctx);
        goto after_2;
    // 0x800A2D18: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
L_800A2D1C:
    // 0x800A2D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A2D24: jr          $ra
    // 0x800A2D28: nop

    return;
    // 0x800A2D28: nop

;}
RECOMP_FUNC void func_8001BD30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BD30: andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // 0x8001BD34: beq         $v0, $zero, L_8001BD48
    if (ctx->r2 == 0) {
        // 0x8001BD38: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8001BD48;
    }
    // 0x8001BD38: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8001BD3C: subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // 0x8001BD40: jr          $ra
    // 0x8001BD44: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    return;
    // 0x8001BD44: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
L_8001BD48:
    // 0x8001BD48: jr          $ra
    // 0x8001BD4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001BD4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808018D0_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018D8: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x808018DC: jal         0x80084C38
    // 0x808018E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bafly_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808018E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x808018E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018EC: jr          $ra
    // 0x808018F0: nop

    return;
    // 0x808018F0: nop

;}
RECOMP_FUNC void subaddiemarker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808000E0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808000E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808000E8: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x808000EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808000F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000F4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3266, 0X1E0) << 16);
    // 0x808000F8: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x808000FC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800100: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800104: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800108: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080010C: addiu       $a1, $a1, 0x1E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3266, 0X1E0));
    // 0x80800110: jal         0x800882C0
    // 0x80800114: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800114: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x80800118: blez        $v0, L_808001B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080011C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_808001B0;
    }
    // 0x8080011C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800120: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(3266, 0X1E0) << 16);
    // 0x80800124: addiu       $s0, $t6, 0x1E0
    ctx->r16 = ADD32(ctx->r14, (int16_t)RELOC_LO16(3266, 0X1E0));
    // 0x80800128: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8080012C: addu        $s4, $t7, $s0
    ctx->r20 = ADD32(ctx->r15, ctx->r16);
    // 0x80800130: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800134:
    // 0x80800134: lhu         $t8, 0x6($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6);
    // 0x80800138: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x8080013C: bnel        $s5, $t9, L_808001A4
    if (ctx->r21 != ctx->r25) {
        // 0x80800140: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808001A4;
    }
    goto skip_0;
    // 0x80800140: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800144: jal         0x80088C50
    // 0x80800148: nop

    _gspropmarker_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800148: nop

    after_1:
    // 0x8080014C: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
    // 0x80800150: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800154: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800158: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8080015C: srl         $t2, $t1, 23
    ctx->r10 = S32(U32(ctx->r9) >> 23);
    // 0x80800160: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80800164: bgez        $t2, L_80800178
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800168: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800178;
    }
    // 0x80800168: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080016C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800170: nop

    // 0x80800174: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800178:
    // 0x80800178: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    // 0x8080017C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80800180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800184: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x80800188: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x8080018C: sw          $t5, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r13;
    // 0x80800190: jal         0x800EE88C
    // 0x80800194: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80800194: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80800198: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x8080019C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808001A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808001A4:
    // 0x808001A4: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x808001A8: bnel        $at, $zero, L_80800134
    if (ctx->r1 != 0) {
        // 0x808001AC: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80800134;
    }
    goto skip_1;
    // 0x808001AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_808001B0:
    // 0x808001B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808001B4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x808001B8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808001BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808001C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808001C8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808001CC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808001D0: jr          $ra
    // 0x808001D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808001D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001D8: nop

    // 0x808001DC: nop

;}
RECOMP_FUNC void func_800D9AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9AD4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D9AD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D9ADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D9AE0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800D9AE4: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800D9AE8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800D9AEC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800D9AF0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D9AF4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800D9AF8: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800D9AFC: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800D9B00: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800D9B04: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x800D9B08: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800D9B0C: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800D9B10: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D9B14: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D9B18: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800D9B1C: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800D9B20: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800D9B24: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800D9B28: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800D9B2C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800D9B30: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800D9B34: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800D9B38: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800D9B3C: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800D9B40: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D9B44: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800D9B48: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800D9B4C: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800D9B50: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800D9B54: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800D9B58: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800D9B5C: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800D9B60: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800D9B64: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800D9B68: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800D9B6C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D9B70: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800D9B74: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800D9B78: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800D9B7C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800D9B80: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D9B84: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800D9B88: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800D9B8C: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800D9B90: mul.s       $f16, $f18, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800D9B94: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800D9B98: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D9B9C: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800D9BA0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800D9BA4: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800D9BA8: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800D9BAC: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800D9BB0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800D9BB4: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800D9BB8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800D9BBC: add.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800D9BC0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800D9BC4: nop

    // 0x800D9BC8: bc1fl       L_800D9BE8
    if (!c1cs) {
        // 0x800D9BCC: lwc1        $f8, 0x0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
            goto L_800D9BE8;
    }
    goto skip_0;
    // 0x800D9BCC: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800D9BD0: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800D9BD4: jal         0x800D9888
    // 0x800D9BD8: nop

    func_800D9888(rdram, ctx);
        goto after_0;
    // 0x800D9BD8: nop

    after_0:
    // 0x800D9BDC: b           L_800D9C24
    // 0x800D9BE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800D9C24;
    // 0x800D9BE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9BE4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
L_800D9BE8:
    // 0x800D9BE8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800D9BEC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800D9BF0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800D9BF4: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x800D9BF8: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800D9BFC: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
    // 0x800D9C00: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800D9C04: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800D9C08: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800D9C0C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800D9C10: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800D9C14: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800D9C18: jal         0x800D9888
    // 0x800D9C1C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_800D9888(rdram, ctx);
        goto after_1;
    // 0x800D9C1C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800D9C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D9C24:
    // 0x800D9C24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D9C28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800D9C2C: jr          $ra
    // 0x800D9C30: nop

    return;
    // 0x800D9C30: nop

;}
RECOMP_FUNC void _fxstep_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A48: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A48);
    return;
    // 0x80088A4C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _chbaddiesetup_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D48: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D48);
    return;
    // 0x80086D4C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80020EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020EE4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80020EE8: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80020EEC: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80020EF0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80020EF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80020EF8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80020EFC: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80020F00: mflo        $t7
    ctx->r15 = lo;
    // 0x80020F04: addiu       $t8, $t7, 0xF
    ctx->r24 = ADD32(ctx->r15, 0XF);
    // 0x80020F08: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80020F0C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80020F10: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x80020F14: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80020F18: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80020F1C: lw          $t4, 0x8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8);
    // 0x80020F20: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80020F24: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80020F28: sltu        $at, $t5, $t2
    ctx->r1 = ctx->r13 < ctx->r10 ? 1 : 0;
    // 0x80020F2C: bne         $at, $zero, L_80020F50
    if (ctx->r1 != 0) {
        // 0x80020F30: nop
    
            goto L_80020F50;
    }
    // 0x80020F30: nop

    // 0x80020F34: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x80020F38: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x80020F3C: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x80020F40: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80020F44: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80020F48: b           L_80020F50
    // 0x80020F4C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
        goto L_80020F50;
    // 0x80020F4C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
L_80020F50:
    // 0x80020F50: b           L_80020F60
    // 0x80020F54: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
        goto L_80020F60;
    // 0x80020F54: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80020F58: b           L_80020F60
    // 0x80020F5C: nop

        goto L_80020F60;
    // 0x80020F5C: nop

L_80020F60:
    // 0x80020F60: jr          $ra
    // 0x80020F64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80020F64: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80020F68: nop

    // 0x80020F6C: nop

;}
RECOMP_FUNC void func_8009224C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009224C: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092250: jr          $ra
    // 0x80092254: lbu         $v0, 0x1A($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1A);
    return;
    // 0x80092254: lbu         $v0, 0x1A($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1A);
;}
RECOMP_FUNC void bsbeemain_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A94: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A98: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(80, 0X1290) << 16);
    // 0x80800A9C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800AA0: jr          $ra
    // 0x80800AA4: lw          $v0, 0x1290($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X1290));
    return;
    // 0x80800AA4: lw          $v0, 0x1290($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X1290));
;}
RECOMP_FUNC void func_80800224_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800228: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080022C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800230: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800234: jal         0x80100094
    // 0x80800238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080023C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800240: jal         0x80800FE0
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800FE0_chstonepillar(rdram, ctx);
        goto after_1;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: jal         0x80801374
    // 0x80800250: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801374_chstonepillar(rdram, ctx);
        goto after_2;
    // 0x80800250: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800254: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800258: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080025C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800260: bnel        $t7, $at, L_8080030C
    if (ctx->r15 != ctx->r1) {
        // 0x80800264: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080030C;
    }
    goto skip_0;
    // 0x80800264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800268: jal         0x80800C10
    // 0x8080026C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_80800C10_chstonepillar(rdram, ctx);
        goto after_3;
    // 0x8080026C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800270: jal         0x80801238
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801238_chstonepillar(rdram, ctx);
        goto after_4;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800278: bne         $v0, $zero, L_80800308
    if (ctx->r2 != 0) {
        // 0x8080027C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800308;
    }
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x80101FDC
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800288: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8080028C: jal         0x800D0B68
    // 0x80800290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_6;
    // 0x80800290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800294: bnel        $v0, $zero, L_8080030C
    if (ctx->r2 != 0) {
        // 0x80800298: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080030C;
    }
    goto skip_1;
    // 0x80800298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080029C: jal         0x800DA298
    // 0x808002A0: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808002A0: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    after_7:
    // 0x808002A4: bne         $v0, $zero, L_808002C0
    if (ctx->r2 != 0) {
        // 0x808002A8: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_808002C0;
    }
    // 0x808002A8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808002AC: lh          $t9, 0x2C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2C);
    // 0x808002B0: bne         $t9, $zero, L_808002C0
    if (ctx->r25 != 0) {
        // 0x808002B4: nop
    
            goto L_808002C0;
    }
    // 0x808002B4: nop

    // 0x808002B8: jal         0x800DA544
    // 0x808002BC: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x808002BC: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    after_8:
L_808002C0:
    // 0x808002C0: jal         0x800DA298
    // 0x808002C4: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808002C4: addiu       $a0, $zero, 0x9D8
    ctx->r4 = ADD32(0, 0X9D8);
    after_9:
    // 0x808002C8: beq         $v0, $zero, L_80800300
    if (ctx->r2 == 0) {
        // 0x808002CC: nop
    
            goto L_80800300;
    }
    // 0x808002CC: nop

    // 0x808002D0: jal         0x8080112C
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080112C_chstonepillar(rdram, ctx);
        goto after_10;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808002D8: beq         $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x808002DC: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80800308;
    }
    // 0x808002DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x808002E0: lh          $t1, 0x2C($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2C);
    // 0x808002E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808002E8: beql        $t1, $at, L_8080030C
    if (ctx->r9 == ctx->r1) {
        // 0x808002EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080030C;
    }
    goto skip_2;
    // 0x808002EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808002F0: jal         0x80800E30
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E30_chstonepillar(rdram, ctx);
        goto after_11;
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808002F8: b           L_8080030C
    // 0x808002FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080030C;
    // 0x808002FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800300:
    // 0x80800300: jal         0x80800DA4
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DA4_chstonepillar(rdram, ctx);
        goto after_12;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_80800308:
    // 0x80800308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080030C:
    // 0x8080030C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800310: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800314: jr          $ra
    // 0x80800318: nop

    return;
    // 0x80800318: nop

;}
RECOMP_FUNC void func_80800000_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80100094
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800014: beq         $v0, $zero, L_80800024
    if (ctx->r2 == 0) {
        // 0x80800018: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800024;
    }
    // 0x80800018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: jal         0x80087CC8
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80800024:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void _badata_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084718: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084718);
    return;
    // 0x8008471C: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_800E6A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6A58: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E6A5C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800E6A60: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800E6A64: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800E6A68: beql        $t7, $zero, L_800E6A84
    if (ctx->r15 == 0) {
        // 0x800E6A6C: sb          $a1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r5;
            goto L_800E6A84;
    }
    goto skip_0;
    // 0x800E6A6C: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    skip_0:
    // 0x800E6A70: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
L_800E6A74:
    // 0x800E6A74: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E6A78: bnel        $t8, $zero, L_800E6A74
    if (ctx->r24 != 0) {
        // 0x800E6A7C: lbu         $t8, 0x1($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X1);
            goto L_800E6A74;
    }
    goto skip_1;
    // 0x800E6A7C: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x800E6A80: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
L_800E6A84:
    // 0x800E6A84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E6A88: jr          $ra
    // 0x800E6A8C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x800E6A8C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void _bawobble_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085468: syscall     162
    recomp_syscall_handler(rdram, ctx, 0x80085468);
    return;
    // 0x8008546C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808024F0_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024F0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808024F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808024F8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808024FC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80802500: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80802504: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80802508: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080250C: jal         0x800E81D0
    // 0x80802510: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800E81D0(rdram, ctx);
        goto after_0;
    // 0x80802510: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80802514: beq         $v0, $zero, L_8080283C
    if (ctx->r2 == 0) {
        // 0x80802518: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_8080283C;
    }
    // 0x80802518: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x8080251C: jal         0x800A9CD0
    // 0x80802520: nop

    func_800A9CD0(rdram, ctx);
        goto after_1;
    // 0x80802520: nop

    after_1:
    // 0x80802524: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802528: bnel        $v0, $at, L_80802840
    if (ctx->r2 != ctx->r1) {
        // 0x8080252C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80802840;
    }
    goto skip_0;
    // 0x8080252C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80802530: jal         0x80802464
    // 0x80802534: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80802464_chjiggygamenew(rdram, ctx);
        goto after_2;
    // 0x80802534: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x80802538: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080253C: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80802540: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80802544: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80802548: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080254C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80802550: jal         0x800EFA4C
    // 0x80802554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80802554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802558: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080255C: addiu       $s1, $sp, 0x64
    ctx->r17 = ADD32(ctx->r29, 0X64);
    // 0x80802560: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802564: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80802568: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080256C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80802570: jal         0x800EFA4C
    // 0x80802574: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80802574: nop

    after_4:
    // 0x80802578: jal         0x800DF830
    // 0x8080257C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_5;
    // 0x8080257C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80802580: jal         0x800D674C
    // 0x80802584: addiu       $a0, $zero, 0x866
    ctx->r4 = ADD32(0, 0X866);
    func_800D674C(rdram, ctx);
        goto after_6;
    // 0x80802584: addiu       $a0, $zero, 0x866
    ctx->r4 = ADD32(0, 0X866);
    after_6:
    // 0x80802588: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080258C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802590: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802594: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80802598: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8080259C: jal         0x800DE498
    // 0x808025A0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800DE498(rdram, ctx);
        goto after_7;
    // 0x808025A0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_7:
    // 0x808025A4: jal         0x800D674C
    // 0x808025A8: addiu       $a0, $zero, 0x865
    ctx->r4 = ADD32(0, 0X865);
    func_800D674C(rdram, ctx);
        goto after_8;
    // 0x808025A8: addiu       $a0, $zero, 0x865
    ctx->r4 = ADD32(0, 0X865);
    after_8:
    // 0x808025AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808025B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808025B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808025B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808025BC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x808025C0: jal         0x800DE498
    // 0x808025C4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800DE498(rdram, ctx);
        goto after_9;
    // 0x808025C4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_9:
    // 0x808025C8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x808025CC: lui         $s1, 0xE300
    ctx->r17 = S32(0XE300 << 16);
    // 0x808025D0: ori         $s1, $s1, 0x1201
    ctx->r17 = ctx->r17 | 0X1201;
    // 0x808025D4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x808025D8: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x808025DC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x808025E0: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x808025E4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x808025E8: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x808025EC: ori         $t8, $t8, 0x1801
    ctx->r24 = ctx->r24 | 0X1801;
    // 0x808025F0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x808025F4: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x808025F8: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x808025FC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80802600: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80802604: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    // 0x80802608: beq         $a2, $zero, L_80802618
    if (ctx->r6 == 0) {
        // 0x8080260C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80802618;
    }
    // 0x8080260C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802610: jal         0x80803928
    // 0x80802614: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80803928_chjiggygamenew(rdram, ctx);
        goto after_10;
    // 0x80802614: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_10:
L_80802618:
    // 0x80802618: jal         0x800E7C28
    // 0x8080261C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E7C28(rdram, ctx);
        goto after_11;
    // 0x8080261C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x80802620: jal         0x800E7CF4
    // 0x80802624: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E7CF4(rdram, ctx);
        goto after_12;
    // 0x80802624: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x80802628: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8080262C: lui         $t1, 0xDB06
    ctx->r9 = S32(0XDB06 << 16);
    // 0x80802630: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x80802634: addiu       $t0, $s0, 0x8
    ctx->r8 = ADD32(ctx->r16, 0X8);
    // 0x80802638: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x8080263C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80802640: jal         0x8002E330
    // 0x80802644: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_13;
    // 0x80802644: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_13:
    // 0x80802648: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8080264C: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x80802650: jal         0x80102FDC
    // 0x80802654: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80102FDC(rdram, ctx);
        goto after_14;
    // 0x80802654: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80802658: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080265C: jal         0x80101870
    // 0x80802660: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80101870(rdram, ctx);
        goto after_15;
    // 0x80802660: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_15:
    // 0x80802664: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80802668: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x8080266C: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x80802670: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80802674: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80802678: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8080267C: sw          $s1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r17;
    // 0x80802680: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80802684: ori         $t5, $t5, 0x1801
    ctx->r13 = ctx->r13 | 0X1801;
    // 0x80802688: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080268C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80802690: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80802694: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80802698: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8080269C: jal         0x80803668
    // 0x808026A0: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    func_80803668_chjiggygamenew(rdram, ctx);
        goto after_16;
    // 0x808026A0: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    after_16:
    // 0x808026A4: jal         0x808019E0
    // 0x808026A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_808019E0_chjiggygamenew(rdram, ctx);
        goto after_17;
    // 0x808026A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x808026AC: sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
    // 0x808026B0: jal         0x808024C8
    // 0x808026B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808024C8_chjiggygamenew(rdram, ctx);
        goto after_18;
    // 0x808026B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_18:
    // 0x808026B8: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
    // 0x808026BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808026C0: beq         $v0, $at, L_808026D0
    if (ctx->r2 == ctx->r1) {
        // 0x808026C4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808026D0;
    }
    // 0x808026C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808026C8: bnel        $v0, $at, L_80802840
    if (ctx->r2 != ctx->r1) {
        // 0x808026CC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80802840;
    }
    goto skip_1;
    // 0x808026CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_808026D0:
    // 0x808026D0: jal         0x80088B20
    // 0x808026D4: nop

    _fxkern_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x808026D4: nop

    after_19:
    // 0x808026D8: lw          $t6, 0x28($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X28);
    // 0x808026DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808026E0: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x808026E4: bnel        $t6, $at, L_808026F8
    if (ctx->r14 != ctx->r1) {
        // 0x808026E8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_808026F8;
    }
    goto skip_2;
    // 0x808026E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_2:
    // 0x808026EC: b           L_8080271C
    // 0x808026F0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
        goto L_8080271C;
    // 0x808026F0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x808026F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808026F8:
    // 0x808026F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808026FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802700: lwc1        $f12, 0x18($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X18);
    // 0x80802704: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802708: jal         0x800F10B4
    // 0x8080270C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_20;
    // 0x8080270C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x80802710: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80802714: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80802718: nop

L_8080271C:
    // 0x8080271C: jal         0x800B8C8C
    // 0x80802720: nop

    func_800B8C8C(rdram, ctx);
        goto after_21;
    // 0x80802720: nop

    after_21:
    // 0x80802724: jal         0x800B8CE0
    // 0x80802728: addiu       $a0, $zero, 0xC26
    ctx->r4 = ADD32(0, 0XC26);
    func_800B8CE0(rdram, ctx);
        goto after_22;
    // 0x80802728: addiu       $a0, $zero, 0xC26
    ctx->r4 = ADD32(0, 0XC26);
    after_22:
    // 0x8080272C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3A18) << 16);
    // 0x80802730: jal         0x80088B28
    // 0x80802734: lwc1        $f12, 0x3A18($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3A18));
    _fxkern_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x80802734: lwc1        $f12, 0x3A18($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3A18));
    after_23:
    // 0x80802738: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080273C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802740: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80802744:
    // 0x80802744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802748: jal         0x80100094
    // 0x8080274C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_80100094(rdram, ctx);
        goto after_24;
    // 0x8080274C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_24:
    // 0x80802750: addu        $t8, $v0, $s0
    ctx->r24 = ADD32(ctx->r2, ctx->r16);
    // 0x80802754: lbu         $t9, 0x21C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X21C);
    // 0x80802758: addiu       $s0, $s0, 0x1E
    ctx->r16 = ADD32(ctx->r16, 0X1E);
    // 0x8080275C: slti        $at, $s0, 0x5A
    ctx->r1 = SIGNED(ctx->r16) < 0X5A ? 1 : 0;
    // 0x80802760: beq         $t9, $zero, L_8080276C
    if (ctx->r25 == 0) {
        // 0x80802764: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_8080276C;
    }
    // 0x80802764: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80802768: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8080276C:
    // 0x8080276C: bnel        $at, $zero, L_80802744
    if (ctx->r1 != 0) {
        // 0x80802770: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80802744;
    }
    goto skip_3;
    // 0x80802770: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_3:
    // 0x80802774: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080277C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80802780: jal         0x80100094
    // 0x80802784: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    func_80100094(rdram, ctx);
        goto after_25;
    // 0x80802784: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    after_25:
    // 0x80802788: lbu         $t0, 0x21C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X21C);
    // 0x8080278C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80802790: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80802794: beq         $t0, $zero, L_8080283C
    if (ctx->r8 == 0) {
        // 0x80802798: sll         $s0, $a2, 4
        ctx->r16 = S32(ctx->r6 << 4);
            goto L_8080283C;
    }
    // 0x80802798: sll         $s0, $a2, 4
    ctx->r16 = S32(ctx->r6 << 4);
    // 0x8080279C: sll         $s1, $a2, 2
    ctx->r17 = S32(ctx->r6 << 2);
    // 0x808027A0: subu        $s1, $s1, $a2
    ctx->r17 = SUB32(ctx->r17, ctx->r6);
    // 0x808027A4: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x808027A8: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x808027AC: subu        $s0, $s0, $a2
    ctx->r16 = SUB32(ctx->r16, ctx->r6);
    // 0x808027B0: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x808027B4: bgez        $v1, L_808027C4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x808027B8: sra         $t1, $v1, 1
        ctx->r9 = S32(SIGNED(ctx->r3) >> 1);
            goto L_808027C4;
    }
    // 0x808027B8: sra         $t1, $v1, 1
    ctx->r9 = S32(SIGNED(ctx->r3) >> 1);
    // 0x808027BC: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x808027C0: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_808027C4:
    // 0x808027C4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x808027C8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x808027CC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x808027D0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x808027D4: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x808027D8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x808027DC: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x808027E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808027E4:
    // 0x808027E4: jal         0x80100094
    // 0x808027E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_26;
    // 0x808027E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x808027EC: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x808027F0: jal         0x800E71B8
    // 0x808027F4: addiu       $a0, $a0, 0x21C
    ctx->r4 = ADD32(ctx->r4, 0X21C);
    func_800E71B8(rdram, ctx);
        goto after_27;
    // 0x808027F4: addiu       $a0, $a0, 0x21C
    ctx->r4 = ADD32(ctx->r4, 0X21C);
    after_27:
    // 0x808027F8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x808027FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802800: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80802804: jal         0x80088B18
    // 0x80802808: addu        $a1, $t5, $s1
    ctx->r5 = ADD32(ctx->r13, ctx->r17);
    _fxkern_entrypoint_1(rdram, ctx);
        goto after_28;
    // 0x80802808: addu        $a1, $t5, $s1
    ctx->r5 = ADD32(ctx->r13, ctx->r17);
    after_28:
    // 0x8080280C: addiu       $s0, $s0, 0x1E
    ctx->r16 = ADD32(ctx->r16, 0X1E);
    // 0x80802810: addiu       $s1, $s1, 0x19
    ctx->r17 = ADD32(ctx->r17, 0X19);
    // 0x80802814: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802818: jal         0x80100094
    // 0x8080281C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_29;
    // 0x8080281C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80802820: addu        $t6, $v0, $s0
    ctx->r14 = ADD32(ctx->r2, ctx->r16);
    // 0x80802824: lbu         $t7, 0x21C($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X21C);
    // 0x80802828: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x8080282C: beql        $t7, $zero, L_80802840
    if (ctx->r15 == 0) {
        // 0x80802830: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80802840;
    }
    goto skip_4;
    // 0x80802830: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80802834: bnel        $s1, $at, L_808027E4
    if (ctx->r17 != ctx->r1) {
        // 0x80802838: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808027E4;
    }
    goto skip_5;
    // 0x80802838: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_5:
L_8080283C:
    // 0x8080283C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80802840:
    // 0x80802840: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80802844: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80802848: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8080284C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80802850: jr          $ra
    // 0x80802854: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80802854: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_808000D4_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000DC: jal         0x80101080
    // 0x808000E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x808000E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000E4: jal         0x80106790
    // 0x808000E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808000E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000F0: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    // 0x808000F4: jal         0x80086688
    // 0x808000F8: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808000F8: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_2:
    // 0x808000FC: jal         0x800DA544
    // 0x80800100: addiu       $a0, $zero, 0x196
    ctx->r4 = ADD32(0, 0X196);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800100: addiu       $a0, $zero, 0x196
    ctx->r4 = ADD32(0, 0X196);
    after_3:
    // 0x80800104: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800108: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2280, 0X920) << 16);
    // 0x8080010C: addiu       $t6, $t6, 0x920
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2280, 0X920));
    // 0x80800110: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80800114: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x80800118: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080011C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800120: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800124: jal         0x800BABB8
    // 0x80800128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8080012C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2280, 0X968) << 16);
    // 0x80800130: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800134: addiu       $a2, $a2, 0x968
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2280, 0X968));
    // 0x80800138: jal         0x80089D18
    // 0x8080013C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x8080013C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800144: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void _chinflatableboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C50: syscall     213
    recomp_syscall_handler(rdram, ctx, 0x80085C50);
    return;
    // 0x80085C54: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
