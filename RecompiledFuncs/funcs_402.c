#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808035EC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808035EC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808035F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808035F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808035F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808035FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803600: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803604: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80803608: jal         0x80802484
    // 0x8080360C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080360C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    after_0:
    // 0x80803610: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80803614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803618: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8080361C: jal         0x80084AC8
    // 0x80803620: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    _baeggcursor_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80803620: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_1:
    // 0x80803624: jal         0x800A4C68
    // 0x80803628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_2;
    // 0x80803628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080362C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803630: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80803634: jal         0x800C5008
    // 0x80803638: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_800C5008(rdram, ctx);
        goto after_3;
    // 0x80803638: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_3:
    // 0x8080363C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80803640: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80803644: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80803648: jal         0x800EFA4C
    // 0x8080364C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x8080364C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_4:
    // 0x80803650: jal         0x800A4C68
    // 0x80803654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_5;
    // 0x80803654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80803658: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080365C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80803660: jal         0x800C4E58
    // 0x80803664: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800C4E58(rdram, ctx);
        goto after_6;
    // 0x80803664: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_6:
    // 0x80803668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080366C: jal         0x800A4CE8
    // 0x80803670: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A4CE8(rdram, ctx);
        goto after_7;
    // 0x80803670: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80803674: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803678: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8080367C: jal         0x800EFB24
    // 0x80803680: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80803680: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_8:
    // 0x80803684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803688: jal         0x8009C15C
    // 0x8080368C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8009C15C(rdram, ctx);
        goto after_9;
    // 0x8080368C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80803690: jal         0x800EEF94
    // 0x80803694: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EEF94(rdram, ctx);
        goto after_10;
    // 0x80803694: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x80803698: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8080369C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x808036A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808036A4: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x808036A8: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x808036AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808036B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808036B4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808036B8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808036BC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x808036C0: swc1        $f18, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f18.u32l;
    // 0x808036C4: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x808036C8: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x808036CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808036D0: jal         0x800EF368
    // 0x808036D4: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    func_800EF368(rdram, ctx);
        goto after_11;
    // 0x808036D4: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    after_11:
    // 0x808036D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808036DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808036E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808036E4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808036E8: jr          $ra
    // 0x808036EC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x808036EC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void suflamefx_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800318: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080031C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800320: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80800324: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800328: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080032C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800330: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800334: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800338: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080033C: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x80800340: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80800344: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800348: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8080034C: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x80800350: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80800354: lbu         $t6, 0x47($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X47);
    // 0x80800358: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3150, 0X528) << 16);
    // 0x8080035C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800360: sb          $t6, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r14;
    // 0x80800364: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800368: sh          $t7, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r15;
    // 0x8080036C: sh          $t8, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r24;
    // 0x80800370: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80800374: lwc1        $f8, 0x528($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3150, 0X528));
    // 0x80800378: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8080037C: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80800380: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800384: sb          $zero, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = 0;
    // 0x80800388: bne         $t9, $at, L_808003AC
    if (ctx->r25 != ctx->r1) {
        // 0x8080038C: swc1        $f8, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
            goto L_808003AC;
    }
    // 0x8080038C: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80800390: jal         0x800D674C
    // 0x80800394: lh          $a0, 0x18($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X18);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80800394: lh          $a0, 0x18($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X18);
    after_0:
    // 0x80800398: jal         0x800AF5A0
    // 0x8080039C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AF5A0(rdram, ctx);
        goto after_1;
    // 0x8080039C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808003A0: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x808003A4: b           L_808003B4
    // 0x808003A8: sb          $t0, 0x1D($s2)
    MEM_B(0X1D, ctx->r18) = ctx->r8;
        goto L_808003B4;
    // 0x808003A8: sb          $t0, 0x1D($s2)
    MEM_B(0X1D, ctx->r18) = ctx->r8;
L_808003AC:
    // 0x808003AC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x808003B0: sb          $t1, 0x1D($s2)
    MEM_B(0X1D, ctx->r18) = ctx->r9;
L_808003B4:
    // 0x808003B4: lbu         $t2, 0x1B($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X1B);
    // 0x808003B8: addiu       $s0, $s2, 0x20
    ctx->r16 = ADD32(ctx->r18, 0X20);
    // 0x808003BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808003C0: blezl       $t2, L_8080040C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x808003C4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080040C;
    }
    goto skip_0;
    // 0x808003C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808003C8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808003CC: nop

    // 0x808003D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808003D4:
    // 0x808003D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003D8: jal         0x80800428
    // 0x808003DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80800428_suflamefx(rdram, ctx);
        goto after_2;
    // 0x808003DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x808003E0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808003E4: jal         0x800DC178
    // 0x808003E8: lwc1        $f14, 0x4($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X4);
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808003E8: lwc1        $f14, 0x4($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X4);
    after_3:
    // 0x808003EC: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x808003F0: lbu         $t3, 0x1B($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X1B);
    // 0x808003F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808003F8: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x808003FC: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80800400: bnel        $at, $zero, L_808003D4
    if (ctx->r1 != 0) {
        // 0x80800404: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808003D4;
    }
    goto skip_1;
    // 0x80800404: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x80800408: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080040C:
    // 0x8080040C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800410: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800414: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800418: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8080041C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800420: jr          $ra
    // 0x80800424: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800424: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800B26C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B26C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B26CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B26D0: jal         0x8001BAFC
    // 0x800B26D4: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800B26D4: nop

    after_0:
    // 0x800B26D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B26DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B26E0: jr          $ra
    // 0x800B26E4: nop

    return;
    // 0x800B26E4: nop

    // 0x800B26E8: nop

    // 0x800B26EC: nop

;}
RECOMP_FUNC void func_800B1D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1D3C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800B1D40: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800B1D44: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800B1D48: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800B1D4C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800B1D50: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800B1D54: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B1D58: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800B1D5C: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x800B1D60: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x800B1D64: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x800B1D68: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x800B1D6C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x800B1D70: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x800B1D74: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x800B1D78: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800B1D7C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800B1D80: jal         0x80019CD4
    // 0x800B1D84: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    func_80019CD4(rdram, ctx);
        goto after_0;
    // 0x800B1D84: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    after_0:
    // 0x800B1D88: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B1D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B1D90: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B1D94: jal         0x8001980C
    // 0x800B1D98: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    func_8001980C(rdram, ctx);
        goto after_1;
    // 0x800B1D98: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    after_1:
    // 0x800B1D9C: addiu       $s6, $sp, 0x9C
    ctx->r22 = ADD32(ctx->r29, 0X9C);
    // 0x800B1DA0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800B1DA4: jal         0x800193C4
    // 0x800B1DA8: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    func_800193C4(rdram, ctx);
        goto after_2;
    // 0x800B1DA8: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    after_2:
    // 0x800B1DAC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800B1DB0: lwc1        $f24, 0xCC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800B1DB4: addiu       $s7, $sp, 0x6C
    ctx->r23 = ADD32(ctx->r29, 0X6C);
    // 0x800B1DB8: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800B1DBC: lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC4);
    // 0x800B1DC0: lw          $s4, 0xD0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD0);
    // 0x800B1DC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B1DC8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B1DCC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800B1DD0: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800B1DD4: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800B1DD8: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    // 0x800B1DDC: lh          $t3, 0x4($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X4);
    // 0x800B1DE0: lh          $t1, 0x2($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X2);
    // 0x800B1DE4: addiu       $s2, $sp, 0x84
    ctx->r18 = ADD32(ctx->r29, 0X84);
    // 0x800B1DE8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B1DEC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800B1DF0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800B1DF4: addu        $s0, $t2, $t0
    ctx->r16 = ADD32(ctx->r10, ctx->r8);
    // 0x800B1DF8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B1DFC: addu        $s3, $t4, $s0
    ctx->r19 = ADD32(ctx->r12, ctx->r16);
    // 0x800B1E00: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800B1E04: beq         $at, $zero, L_800B1F4C
    if (ctx->r1 == 0) {
        // 0x800B1E08: div.s       $f24, $f24, $f20
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
            goto L_800B1F4C;
    }
    // 0x800B1E08: div.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800B1E0C: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
    // 0x800B1E10: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
L_800B1E14:
    // 0x800B1E14: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B1E18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B1E1C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B1E20: sllv        $t7, $t5, $v0
    ctx->r15 = S32(ctx->r13 << (ctx->r2 & 31));
    // 0x800B1E24: and         $t8, $t7, $s4
    ctx->r24 = ctx->r15 & ctx->r20;
    // 0x800B1E28: bnel        $t8, $zero, L_800B1F40
    if (ctx->r24 != 0) {
        // 0x800B1E2C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800B1F40;
    }
    goto skip_0;
    // 0x800B1E2C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x800B1E30: mul.s       $f26, $f24, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800B1E34: jal         0x800EE88C
    // 0x800B1E38: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x800B1E38: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    after_3:
    // 0x800B1E3C: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800B1E40: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B1E44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B1E48: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800B1E4C: lw          $a2, 0x94($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X94);
    // 0x800B1E50: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x800B1E54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B1E58: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B1E5C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B1E60: jal         0x800EFA4C
    // 0x800B1E64: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x800B1E64: nop

    after_4:
    // 0x800B1E68: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B1E6C: jal         0x800ADE2C
    // 0x800B1E70: lb          $a1, 0x9($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X9);
    func_800ADE2C(rdram, ctx);
        goto after_5;
    // 0x800B1E70: lb          $a1, 0x9($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X9);
    after_5:
    // 0x800B1E74: jal         0x80018EFC
    // 0x800B1E78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mlMtxSet(rdram, ctx);
        goto after_6;
    // 0x800B1E78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x800B1E7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B1E80: jal         0x80019224
    // 0x800B1E84: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80019224(rdram, ctx);
        goto after_7;
    // 0x800B1E84: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800B1E88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B1E8C: jal         0x80019224
    // 0x800B1E90: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80019224(rdram, ctx);
        goto after_8;
    // 0x800B1E90: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x800B1E94: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1E98: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B1E9C: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B1EA0: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800B1EA4: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B1EA8: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800B1EAC: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B1EB0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800B1EB4: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800B1EB8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800B1EBC: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B1EC0: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800B1EC4: jal         0x800EEFD4
    // 0x800B1EC8: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    func_800EEFD4(rdram, ctx);
        goto after_9;
    // 0x800B1EC8: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x800B1ECC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800B1ED0: jal         0x8002DCA0
    // 0x800B1ED4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x800B1ED4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_10:
    // 0x800B1ED8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800B1EDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B1EE0: jal         0x800EEB40
    // 0x800B1EE4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EEB40(rdram, ctx);
        goto after_11;
    // 0x800B1EE4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_11:
    // 0x800B1EE8: add.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x800B1EEC: add.s       $f4, $f26, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f26.fl + ctx->f22.fl;
    // 0x800B1EF0: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800B1EF4: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800B1EF8: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x800B1EFC: nop

    // 0x800B1F00: bc1fl       L_800B1F40
    if (!c1cs) {
        // 0x800B1F04: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800B1F40;
    }
    goto skip_1;
    // 0x800B1F04: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x800B1F08: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x800B1F0C: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    // 0x800B1F10: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800B1F14: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x800B1F18: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x800B1F1C: subu        $t6, $s0, $t0
    ctx->r14 = SUB32(ctx->r16, ctx->r8);
    // 0x800B1F20: subu        $t4, $t6, $t3
    ctx->r12 = SUB32(ctx->r14, ctx->r11);
    // 0x800B1F24: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x800B1F28: mflo        $t5
    ctx->r13 = lo;
    // 0x800B1F2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B1F30: sh          $t5, 0x7EE0($at)
    MEM_H(0X7EE0, ctx->r1) = ctx->r13;
    // 0x800B1F34: b           L_800B1F50
    // 0x800B1F38: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
        goto L_800B1F50;
    // 0x800B1F38: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x800B1F3C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800B1F40:
    // 0x800B1F40: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800B1F44: bnel        $at, $zero, L_800B1E14
    if (ctx->r1 != 0) {
        // 0x800B1F48: lbu         $v0, 0x8($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X8);
            goto L_800B1E14;
    }
    goto skip_2;
    // 0x800B1F48: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    skip_2:
L_800B1F4C:
    // 0x800B1F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B1F50:
    // 0x800B1F50: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800B1F54: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800B1F58: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800B1F5C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800B1F60: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800B1F64: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800B1F68: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800B1F6C: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F70: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800B1F74: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x800B1F78: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x800B1F7C: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800B1F80: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x800B1F84: jr          $ra
    // 0x800B1F88: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800B1F88: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void suspline_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x808001F4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x808001F8: lh          $t8, 0x68($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X68);
    // 0x808001FC: jr          $ra
    // 0x80800200: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    return;
    // 0x80800200: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
;}
RECOMP_FUNC void gczoombox_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803524: lw          $v0, 0x1E4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E4);
    // 0x80803528: sll         $t6, $v0, 13
    ctx->r14 = S32(ctx->r2 << 13);
    // 0x8080352C: jr          $ra
    // 0x80803530: srl         $v0, $t6, 31
    ctx->r2 = S32(U32(ctx->r14) >> 31);
    return;
    // 0x80803530: srl         $v0, $t6, 31
    ctx->r2 = S32(U32(ctx->r14) >> 31);
;}
RECOMP_FUNC void func_8080029C_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002A4: jal         0x80800208
    // 0x808002A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800208_bscarry(rdram, ctx);
        goto after_0;
    // 0x808002A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002AC: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808002B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808002B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002B8: jal         0x8008CB3C
    // 0x808002BC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808002BC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_1:
    // 0x808002C0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808002C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002D4: jal         0x8009FFD8
    // 0x808002D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808002D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x808002DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(132, 0X7A0) << 16);
    // 0x808002E0: lwc1        $f4, 0x7A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(132, 0X7A0));
    // 0x808002E4: lui         $a3, 0x3FE6
    ctx->r7 = S32(0X3FE6 << 16);
    // 0x808002E8: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808002EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002F0: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808002F4: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x808002F8: jal         0x8008C9F0
    // 0x808002FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_3;
    // 0x808002FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800304: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800308: jr          $ra
    // 0x8080030C: nop

    return;
    // 0x8080030C: nop

;}
RECOMP_FUNC void func_800F3ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3ED0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F3ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F3ED8: jal         0x8009E6F8
    // 0x800F3EDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F3EDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F3EE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800F3EE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F3EE8: jal         0x80095738
    // 0x800F3EEC: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x800F3EEC: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_1:
    // 0x800F3EF0: beq         $v0, $zero, L_800F3F00
    if (ctx->r2 == 0) {
        // 0x800F3EF4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800F3F00;
    }
    // 0x800F3EF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F3EF8: b           L_800F40DC
    // 0x800F3EFC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_800F40DC;
    // 0x800F3EFC: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_800F3F00:
    // 0x800F3F00: jal         0x80095738
    // 0x800F3F04: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x800F3F04: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_2:
    // 0x800F3F08: beq         $v0, $zero, L_800F3F18
    if (ctx->r2 == 0) {
        // 0x800F3F0C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800F3F18;
    }
    // 0x800F3F0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F3F10: b           L_800F40DC
    // 0x800F3F14: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800F40DC;
    // 0x800F3F14: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800F3F18:
    // 0x800F3F18: jal         0x8009CBDC
    // 0x800F3F1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009CBDC(rdram, ctx);
        goto after_3;
    // 0x800F3F1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x800F3F20: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800F3F24: bne         $v0, $at, L_800F3F34
    if (ctx->r2 != ctx->r1) {
        // 0x800F3F28: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800F3F34;
    }
    // 0x800F3F28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F3F2C: b           L_800F40DC
    // 0x800F3F30: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_800F40DC;
    // 0x800F3F30: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800F3F34:
    // 0x800F3F34: jal         0x8009CBDC
    // 0x800F3F38: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009CBDC(rdram, ctx);
        goto after_4;
    // 0x800F3F38: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x800F3F3C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800F3F40: bne         $v0, $at, L_800F3F50
    if (ctx->r2 != ctx->r1) {
        // 0x800F3F44: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800F3F50;
    }
    // 0x800F3F44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F3F48: b           L_800F40DC
    // 0x800F3F4C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_800F40DC;
    // 0x800F3F4C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_800F3F50:
    // 0x800F3F50: jal         0x8009CBDC
    // 0x800F3F54: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009CBDC(rdram, ctx);
        goto after_5;
    // 0x800F3F54: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_5:
    // 0x800F3F58: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800F3F5C: bne         $v0, $at, L_800F3F6C
    if (ctx->r2 != ctx->r1) {
        // 0x800F3F60: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800F3F6C;
    }
    // 0x800F3F60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F3F64: b           L_800F40DC
    // 0x800F3F68: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_800F40DC;
    // 0x800F3F68: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_800F3F6C:
    // 0x800F3F6C: jal         0x8009CBDC
    // 0x800F3F70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009CBDC(rdram, ctx);
        goto after_6;
    // 0x800F3F70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x800F3F74: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800F3F78: bne         $v0, $at, L_800F3F88
    if (ctx->r2 != ctx->r1) {
        // 0x800F3F7C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800F3F88;
    }
    // 0x800F3F7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F3F80: b           L_800F40DC
    // 0x800F3F84: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_800F40DC;
    // 0x800F3F84: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800F3F88:
    // 0x800F3F88: jal         0x8009CBDC
    // 0x800F3F8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009CBDC(rdram, ctx);
        goto after_7;
    // 0x800F3F8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_7:
    // 0x800F3F90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800F3F94: bne         $v0, $at, L_800F3FA4
    if (ctx->r2 != ctx->r1) {
        // 0x800F3F98: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800F3FA4;
    }
    // 0x800F3F98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F3F9C: b           L_800F40DC
    // 0x800F3FA0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800F40DC;
    // 0x800F3FA0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800F3FA4:
    // 0x800F3FA4: jal         0x80095738
    // 0x800F3FA8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    baflag_isTrue(rdram, ctx);
        goto after_8;
    // 0x800F3FA8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_8:
    // 0x800F3FAC: beq         $v0, $zero, L_800F3FBC
    if (ctx->r2 == 0) {
        // 0x800F3FB0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800F3FBC;
    }
    // 0x800F3FB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F3FB4: b           L_800F40DC
    // 0x800F3FB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F40DC;
    // 0x800F3FB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F3FBC:
    // 0x800F3FBC: jal         0x8009E674
    // 0x800F3FC0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8009E674(rdram, ctx);
        goto after_9;
    // 0x800F3FC0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_9:
    // 0x800F3FC4: beql        $v0, $zero, L_800F4014
    if (ctx->r2 == 0) {
        // 0x800F3FC8: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_800F4014;
    }
    goto skip_0;
    // 0x800F3FC8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800F3FCC: jal         0x80084FE0
    // 0x800F3FD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x800F3FD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x800F3FD4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F3FD8: beq         $v0, $at, L_800F3FF8
    if (ctx->r2 == ctx->r1) {
        // 0x800F3FDC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800F3FF8;
    }
    // 0x800F3FDC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800F3FE0: beq         $v0, $at, L_800F4000
    if (ctx->r2 == ctx->r1) {
        // 0x800F3FE4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800F4000;
    }
    // 0x800F3FE4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800F3FE8: beq         $v0, $at, L_800F4008
    if (ctx->r2 == ctx->r1) {
        // 0x800F3FEC: nop
    
            goto L_800F4008;
    }
    // 0x800F3FEC: nop

    // 0x800F3FF0: b           L_800F4014
    // 0x800F3FF4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
        goto L_800F4014;
    // 0x800F3FF4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_800F3FF8:
    // 0x800F3FF8: b           L_800F40DC
    // 0x800F3FFC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800F40DC;
    // 0x800F3FFC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800F4000:
    // 0x800F4000: b           L_800F40DC
    // 0x800F4004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_800F40DC;
    // 0x800F4004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800F4008:
    // 0x800F4008: b           L_800F40DC
    // 0x800F400C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_800F40DC;
    // 0x800F400C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800F4010: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_800F4014:
    // 0x800F4014: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4018: slti        $at, $t6, 0xA5
    ctx->r1 = SIGNED(ctx->r14) < 0XA5 ? 1 : 0;
    // 0x800F401C: bne         $at, $zero, L_800F403C
    if (ctx->r1 != 0) {
        // 0x800F4020: addiu       $at, $zero, 0xA5
        ctx->r1 = ADD32(0, 0XA5);
            goto L_800F403C;
    }
    // 0x800F4020: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x800F4024: beq         $t6, $at, L_800F4088
    if (ctx->r14 == ctx->r1) {
        // 0x800F4028: addiu       $at, $zero, 0x120
        ctx->r1 = ADD32(0, 0X120);
            goto L_800F4088;
    }
    // 0x800F4028: addiu       $at, $zero, 0x120
    ctx->r1 = ADD32(0, 0X120);
    // 0x800F402C: beq         $t6, $at, L_800F4080
    if (ctx->r14 == ctx->r1) {
        // 0x800F4030: nop
    
            goto L_800F4080;
    }
    // 0x800F4030: nop

    // 0x800F4034: b           L_800F40C0
    // 0x800F4038: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_800F40C0;
    // 0x800F4038: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_800F403C:
    // 0x800F403C: slti        $at, $t7, 0x46
    ctx->r1 = SIGNED(ctx->r15) < 0X46 ? 1 : 0;
    // 0x800F4040: bne         $at, $zero, L_800F405C
    if (ctx->r1 != 0) {
        // 0x800F4044: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_800F405C;
    }
    // 0x800F4044: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4048: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x800F404C: beq         $t7, $at, L_800F4088
    if (ctx->r15 == ctx->r1) {
        // 0x800F4050: nop
    
            goto L_800F4088;
    }
    // 0x800F4050: nop

    // 0x800F4054: b           L_800F40C0
    // 0x800F4058: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_800F40C0;
    // 0x800F4058: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_800F405C:
    // 0x800F405C: addiu       $t9, $t8, -0x8
    ctx->r25 = ADD32(ctx->r24, -0X8);
    // 0x800F4060: sltiu       $at, $t9, 0x3E
    ctx->r1 = ctx->r25 < 0X3E ? 1 : 0;
    // 0x800F4064: beq         $at, $zero, L_800F40BC
    if (ctx->r1 == 0) {
        // 0x800F4068: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800F40BC;
    }
    // 0x800F4068: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800F406C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F4070: addu        $at, $at, $t9
    gpr jr_addend_800F4078 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800F4074: lw          $t9, 0x5F78($at)
    ctx->r25 = ADD32(ctx->r1, 0X5F78);
    // 0x800F4078: jr          $t9
    // 0x800F407C: nop

    switch (jr_addend_800F4078 >> 2) {
        case 0: goto L_800F4090; break;
        case 1: goto L_800F40BC; break;
        case 2: goto L_800F40BC; break;
        case 3: goto L_800F40B4; break;
        case 4: goto L_800F40BC; break;
        case 5: goto L_800F40BC; break;
        case 6: goto L_800F4080; break;
        case 7: goto L_800F40BC; break;
        case 8: goto L_800F40BC; break;
        case 9: goto L_800F40BC; break;
        case 10: goto L_800F40BC; break;
        case 11: goto L_800F40BC; break;
        case 12: goto L_800F40BC; break;
        case 13: goto L_800F4090; break;
        case 14: goto L_800F4090; break;
        case 15: goto L_800F4090; break;
        case 16: goto L_800F40BC; break;
        case 17: goto L_800F40BC; break;
        case 18: goto L_800F4088; break;
        case 19: goto L_800F4088; break;
        case 20: goto L_800F4088; break;
        case 21: goto L_800F4088; break;
        case 22: goto L_800F4088; break;
        case 23: goto L_800F40BC; break;
        case 24: goto L_800F40BC; break;
        case 25: goto L_800F40BC; break;
        case 26: goto L_800F40BC; break;
        case 27: goto L_800F40BC; break;
        case 28: goto L_800F40BC; break;
        case 29: goto L_800F40BC; break;
        case 30: goto L_800F40BC; break;
        case 31: goto L_800F40BC; break;
        case 32: goto L_800F40BC; break;
        case 33: goto L_800F40BC; break;
        case 34: goto L_800F40BC; break;
        case 35: goto L_800F40BC; break;
        case 36: goto L_800F40BC; break;
        case 37: goto L_800F40BC; break;
        case 38: goto L_800F40BC; break;
        case 39: goto L_800F40BC; break;
        case 40: goto L_800F40BC; break;
        case 41: goto L_800F40BC; break;
        case 42: goto L_800F40BC; break;
        case 43: goto L_800F40BC; break;
        case 44: goto L_800F4080; break;
        case 45: goto L_800F40BC; break;
        case 46: goto L_800F40BC; break;
        case 47: goto L_800F40BC; break;
        case 48: goto L_800F40BC; break;
        case 49: goto L_800F40BC; break;
        case 50: goto L_800F40BC; break;
        case 51: goto L_800F40BC; break;
        case 52: goto L_800F4080; break;
        case 53: goto L_800F40BC; break;
        case 54: goto L_800F40BC; break;
        case 55: goto L_800F4080; break;
        case 56: goto L_800F40BC; break;
        case 57: goto L_800F4080; break;
        case 58: goto L_800F40BC; break;
        case 59: goto L_800F40BC; break;
        case 60: goto L_800F4080; break;
        case 61: goto L_800F4090; break;
        default: switch_error(__func__, 0x800F4078, 0x80125F78);
    }
    // 0x800F407C: nop

L_800F4080:
    // 0x800F4080: b           L_800F40DC
    // 0x800F4084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F40DC;
    // 0x800F4084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F4088:
    // 0x800F4088: b           L_800F40DC
    // 0x800F408C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800F40DC;
    // 0x800F408C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800F4090:
    // 0x800F4090: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F4094: jal         0x80091570
    // 0x800F4098: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bastatetimer_isActive(rdram, ctx);
        goto after_11;
    // 0x800F4098: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x800F409C: beq         $v0, $zero, L_800F40AC
    if (ctx->r2 == 0) {
        // 0x800F40A0: nop
    
            goto L_800F40AC;
    }
    // 0x800F40A0: nop

    // 0x800F40A4: b           L_800F40DC
    // 0x800F40A8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800F40DC;
    // 0x800F40A8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800F40AC:
    // 0x800F40AC: b           L_800F40DC
    // 0x800F40B0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800F40DC;
    // 0x800F40B0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800F40B4:
    // 0x800F40B4: b           L_800F40DC
    // 0x800F40B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800F40DC;
    // 0x800F40B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800F40BC:
    // 0x800F40BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_800F40C0:
    // 0x800F40C0: jal         0x8008EF3C
    // 0x800F40C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EF3C(rdram, ctx);
        goto after_12;
    // 0x800F40C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x800F40C8: beql        $v0, $zero, L_800F40DC
    if (ctx->r2 == 0) {
        // 0x800F40CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F40DC;
    }
    goto skip_1;
    // 0x800F40CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800F40D0: b           L_800F40DC
    // 0x800F40D4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_800F40DC;
    // 0x800F40D4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800F40D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F40DC:
    // 0x800F40DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F40E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F40E4: jr          $ra
    // 0x800F40E8: nop

    return;
    // 0x800F40E8: nop

;}
RECOMP_FUNC void _chnutsnbolts_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864E8: syscall     332
    recomp_syscall_handler(rdram, ctx, 0x800864E8);
    return;
    // 0x800864EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chbaddiesetup_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800474: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800478: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080047C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800480: jal         0x800A5D60
    // 0x80800484: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800A5D60(rdram, ctx);
        goto after_0;
    // 0x80800484: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800488: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080048C: jal         0x80800000
    // 0x80800490: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800000_chbaddiesetup(rdram, ctx);
        goto after_1;
    // 0x80800490: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800494: beq         $v0, $zero, L_80800568
    if (ctx->r2 == 0) {
        // 0x80800498: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800568;
    }
    // 0x80800498: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080049C: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x808004A0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x808004A4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808004A8: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x808004AC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x808004B0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x808004B4: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x808004B8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x808004BC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808004C0: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x808004C4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x808004C8: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x808004CC: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x808004D0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x808004D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808004D8: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x808004DC: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x808004E0: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x808004E4: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    // 0x808004E8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x808004EC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x808004F0: sll         $t1, $t4, 5
    ctx->r9 = S32(ctx->r12 << 5);
    // 0x808004F4: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x808004F8: sw          $t3, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r11;
    // 0x808004FC: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x80800500: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800504: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800508: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x8080050C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80800510: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x80800514: lbu         $t1, 0x4($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4);
    // 0x80800518: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8080051C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80800520: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x80800524: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80800528: sw          $t4, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r12;
    // 0x8080052C: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x80800530: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800534: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800538: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8080053C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80800540: sw          $t6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r14;
    // 0x80800544: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x80800548: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8080054C: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80800550: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80800554: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80800558: sw          $t1, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r9;
    // 0x8080055C: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x80800560: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80800564: sb          $t7, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r15;
L_80800568:
    // 0x80800568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080056C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800570: jr          $ra
    // 0x80800574: nop

    return;
    // 0x80800574: nop

;}
RECOMP_FUNC void _chdiggerground_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C98: syscall     219
    recomp_syscall_handler(rdram, ctx, 0x80085C98);
    return;
    // 0x80085C9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gccollectDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800244: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080024C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800250: jal         0x800CF87C
    // 0x80800254: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800CF87C(rdram, ctx);
        goto after_0;
    // 0x80800254: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800258: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080025C: beq         $v0, $at, L_808002B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800260: lui         $s0, 0x8080
        ctx->r16 = S32(RELOC_HI16(2626, 0XBE0) << 16);
            goto L_808002B0;
    }
    // 0x80800260: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2626, 0XBE0) << 16);
    // 0x80800264: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2626, 0XC0C) << 16);
    // 0x80800268: addiu       $s1, $s1, 0xC0C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2626, 0XC0C));
    // 0x8080026C: addiu       $s0, $s0, 0xBE0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2626, 0XBE0));
    // 0x80800270: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_80800274:
    // 0x80800274: jal         0x800D0B68
    // 0x80800278: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x80800278: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_1:
    // 0x8080027C: bnel        $v0, $zero, L_808002A8
    if (ctx->r2 != 0) {
        // 0x80800280: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808002A8;
    }
    goto skip_0;
    // 0x80800280: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800284: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80800288: jal         0x800D0A9C
    // 0x8080028C: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    func_800D0A9C(rdram, ctx);
        goto after_2;
    // 0x8080028C: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_2:
    // 0x80800290: beql        $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x80800294: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808002A8;
    }
    goto skip_1;
    // 0x80800294: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x80800298: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8080029C: jal         0x800D0B38
    // 0x808002A0: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    func_800D0B38(rdram, ctx);
        goto after_3;
    // 0x808002A0: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_3:
    // 0x808002A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808002A8:
    // 0x808002A8: bnel        $s0, $s1, L_80800274
    if (ctx->r16 != ctx->r17) {
        // 0x808002AC: lh          $a0, 0x0($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X0);
            goto L_80800274;
    }
    goto skip_2;
    // 0x808002AC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    skip_2:
L_808002B0:
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002BC: jr          $ra
    // 0x808002C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808002C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chfriesstand_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DC8: syscall     240
    recomp_syscall_handler(rdram, ctx, 0x80085DC8);
    return;
    // 0x80085DCC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080007C_chfantasylakebits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800080: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800084: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800088: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080008C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800090: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800094: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800098: beq         $t6, $at, L_808000B8
    if (ctx->r14 == ctx->r1) {
        // 0x8080009C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000B8;
    }
    // 0x8080009C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000A0: beq         $t6, $at, L_80800144
    if (ctx->r14 == ctx->r1) {
        // 0x808000A4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800144;
    }
    // 0x808000A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000A8: beq         $t6, $at, L_808001E4
    if (ctx->r14 == ctx->r1) {
        // 0x808000AC: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(2376, 0X9B8) << 16);
            goto L_808001E4;
    }
    // 0x808000AC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2376, 0X9B8) << 16);
    // 0x808000B0: b           L_808002F0
    // 0x808000B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002F0;
    // 0x808000B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000B8:
    // 0x808000B8: jal         0x800DB9B0
    // 0x808000BC: nop

    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x808000BC: nop

    after_0:
    // 0x808000C0: bne         $v0, $zero, L_808000D8
    if (ctx->r2 != 0) {
        // 0x808000C4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808000D8;
    }
    // 0x808000C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000CC: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x808000D0: jal         0x80085708
    // 0x808000D4: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808000D4: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_1:
L_808000D8:
    // 0x808000D8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x808000DC: jal         0x800D91EC
    // 0x808000E0: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    func_800D91EC(rdram, ctx);
        goto after_2;
    // 0x808000E0: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    after_2:
    // 0x808000E4: lui         $at, 0xC548
    ctx->r1 = S32(0XC548 << 16);
    // 0x808000E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000EC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808000F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808000F4: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    // 0x808000F8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808000FC: jal         0x800F10B4
    // 0x80800100: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800100: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800104: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800110: nop

    // 0x80800114: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80800118: jal         0x80800300
    // 0x8080011C: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    func_80800300_chfantasylakebits(rdram, ctx);
        goto after_4;
    // 0x8080011C: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    after_4:
    // 0x80800120: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2376, 0X934) << 16);
    // 0x80800124: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2376, 0X920) << 16);
    // 0x80800128: addiu       $a3, $a3, 0x920
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2376, 0X920));
    // 0x8080012C: addiu       $a1, $a1, 0x934
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2376, 0X934));
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80089D50
    // 0x80800138: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800138: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8080013C: b           L_808002F0
    // 0x80800140: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002F0;
    // 0x80800140: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800144:
    // 0x80800144: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800148: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080014C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800150: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2376, 0X934) << 16);
    // 0x80800154: addiu       $a0, $a0, 0x934
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2376, 0X934));
    // 0x80800158: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8080015C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800160: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800164: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800168: bc1f        L_8080017C
    if (!c1cs) {
        // 0x8080016C: lui         $t0, 0x8080
        ctx->r8 = S32(RELOC_HI16(2376, 0X940) << 16);
            goto L_8080017C;
    }
    // 0x8080016C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2376, 0X940) << 16);
    // 0x80800170: addiu       $t0, $t0, 0x940
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2376, 0X940));
    // 0x80800174: jal         0x800BBCB8
    // 0x80800178: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800BBCB8(rdram, ctx);
        goto after_6;
    // 0x80800178: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_6:
L_8080017C:
    // 0x8080017C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800180: jal         0x800D91EC
    // 0x80800184: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    func_800D91EC(rdram, ctx);
        goto after_7;
    // 0x80800184: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    after_7:
    // 0x80800188: lui         $at, 0xC548
    ctx->r1 = S32(0XC548 << 16);
    // 0x8080018C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800190: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800194: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800198: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    // 0x8080019C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808001A0: jal         0x800F10B4
    // 0x808001A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808001A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x808001A8: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001AC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2376, 0X934) << 16);
    // 0x808001B0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2376, 0X920) << 16);
    // 0x808001B4: addiu       $a3, $a3, 0x920
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2376, 0X920));
    // 0x808001B8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x808001BC: addiu       $a1, $a1, 0x934
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2376, 0X934));
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808001C8: jal         0x80089D50
    // 0x808001CC: sh          $t2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r10;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x808001CC: sh          $t2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r10;
    after_9:
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: jal         0x80800300
    // 0x808001D8: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    func_80800300_chfantasylakebits(rdram, ctx);
        goto after_10;
    // 0x808001D8: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    after_10:
    // 0x808001DC: b           L_808002F0
    // 0x808001E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002F0;
    // 0x808001E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001E4:
    // 0x808001E4: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2376, 0X980) << 16);
    // 0x808001E8: addiu       $t3, $t3, 0x980
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2376, 0X980));
    // 0x808001EC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808001F0: addiu       $a0, $a0, 0x9B8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2376, 0X9B8));
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001F8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001FC: jal         0x800BBCB8
    // 0x80800200: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_11;
    // 0x80800200: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_11:
    // 0x80800204: jal         0x800D90A4
    // 0x80800208: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_12;
    // 0x80800208: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_12:
    // 0x8080020C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800210: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800214: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800218: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080021C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800220: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800224: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800228: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080022C: jal         0x800F10B4
    // 0x80800230: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x80800230: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x80800234: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2376, 0X9C4) << 16);
    // 0x80800238: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2376, 0X9D0) << 16);
    // 0x8080023C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800240: addiu       $a2, $a2, 0x9D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2376, 0X9D0));
    // 0x80800244: addiu       $a1, $a1, 0x9C4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2376, 0X9C4));
    // 0x80800248: jal         0x800EFE50
    // 0x8080024C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EFE50(rdram, ctx);
        goto after_14;
    // 0x8080024C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_14:
    // 0x80800250: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800254: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800258: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080025C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800260: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800264: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800268: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8080026C: jal         0x800F10B4
    // 0x80800270: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x80800270: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x80800274: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2376, 0X934) << 16);
    // 0x80800278: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2376, 0X928) << 16);
    // 0x8080027C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800280: addiu       $a3, $a3, 0x928
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2376, 0X928));
    // 0x80800284: addiu       $a1, $a1, 0x934
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2376, 0X934));
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x80089D50
    // 0x80800290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_16;
    // 0x80800290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x80089D30
    // 0x8080029C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x8080029C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_17:
    // 0x808002A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808002A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002A8: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808002AC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2376, 0X9B8) << 16);
    // 0x808002B0: addiu       $a0, $a0, 0x9B8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2376, 0X9B8));
    // 0x808002B4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808002C4: bc1f        L_808002D8
    if (!c1cs) {
        // 0x808002C8: lui         $t4, 0x8080
        ctx->r12 = S32(RELOC_HI16(2376, 0X9DC) << 16);
            goto L_808002D8;
    }
    // 0x808002C8: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2376, 0X9DC) << 16);
    // 0x808002CC: addiu       $t4, $t4, 0x9DC
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2376, 0X9DC));
    // 0x808002D0: jal         0x800BBCB8
    // 0x808002D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800BBCB8(rdram, ctx);
        goto after_18;
    // 0x808002D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_18:
L_808002D8:
    // 0x808002D8: jal         0x800F54E4
    // 0x808002DC: nop

    func_800F54E4(rdram, ctx);
        goto after_19;
    // 0x808002DC: nop

    after_19:
    // 0x808002E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002E4: jal         0x800F8418
    // 0x808002E8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800F8418(rdram, ctx);
        goto after_20;
    // 0x808002E8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_20:
    // 0x808002EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002F0:
    // 0x808002F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002F8: jr          $ra
    // 0x808002FC: nop

    return;
    // 0x808002FC: nop

;}
RECOMP_FUNC void func_80090590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090598: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009059C: jal         0x800F54E4
    // 0x800905A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800905A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800905A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800905A8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800905AC: jal         0x800F7CF4
    // 0x800905B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F7CF4(rdram, ctx);
        goto after_1;
    // 0x800905B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800905B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800905B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800905BC: jr          $ra
    // 0x800905C0: nop

    return;
    // 0x800905C0: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FB8: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087FB8);
    return;
    // 0x80087FBC: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void chbounce_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800684: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80800688: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8080068C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800690: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFE2) << 16);
    // 0x80800694: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800698: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080069C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808006A4: sh          $a2, 0xFE2($at)
    MEM_H((int16_t)RELOC_LO16(712, 0XFE2), ctx->r1) = ctx->r6;
    // 0x808006A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808006AC: jal         0x80800190
    // 0x808006B0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80800190_chbounce(rdram, ctx);
        goto after_0;
    // 0x808006B0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x808006B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808006B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006BC: jal         0x80100094
    // 0x808006C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808006C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808006C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808006C8: slti        $at, $a3, 0x1CD
    ctx->r1 = SIGNED(ctx->r7) < 0X1CD ? 1 : 0;
    // 0x808006CC: bne         $at, $zero, L_80800708
    if (ctx->r1 != 0) {
        // 0x808006D0: addiu       $at, $zero, 0x1F4
        ctx->r1 = ADD32(0, 0X1F4);
            goto L_80800708;
    }
    // 0x808006D0: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x808006D4: beq         $a3, $at, L_80800730
    if (ctx->r7 == ctx->r1) {
        // 0x808006D8: addiu       $at, $zero, 0x21F
        ctx->r1 = ADD32(0, 0X21F);
            goto L_80800730;
    }
    // 0x808006D8: addiu       $at, $zero, 0x21F
    ctx->r1 = ADD32(0, 0X21F);
    // 0x808006DC: beq         $a3, $at, L_808007A4
    if (ctx->r7 == ctx->r1) {
        // 0x808006E0: addiu       $at, $zero, 0x3C6
        ctx->r1 = ADD32(0, 0X3C6);
            goto L_808007A4;
    }
    // 0x808006E0: addiu       $at, $zero, 0x3C6
    ctx->r1 = ADD32(0, 0X3C6);
    // 0x808006E4: beq         $a3, $at, L_80800750
    if (ctx->r7 == ctx->r1) {
        // 0x808006E8: addiu       $at, $zero, 0x513
        ctx->r1 = ADD32(0, 0X513);
            goto L_80800750;
    }
    // 0x808006E8: addiu       $at, $zero, 0x513
    ctx->r1 = ADD32(0, 0X513);
    // 0x808006EC: beq         $a3, $at, L_80800770
    if (ctx->r7 == ctx->r1) {
        // 0x808006F0: addiu       $t1, $zero, 0x3E9
        ctx->r9 = ADD32(0, 0X3E9);
            goto L_80800770;
    }
    // 0x808006F0: addiu       $t1, $zero, 0x3E9
    ctx->r9 = ADD32(0, 0X3E9);
    // 0x808006F4: addiu       $at, $zero, 0x517
    ctx->r1 = ADD32(0, 0X517);
    // 0x808006F8: beq         $a3, $at, L_8080078C
    if (ctx->r7 == ctx->r1) {
        // 0x808006FC: addiu       $t3, $zero, 0x53D
        ctx->r11 = ADD32(0, 0X53D);
            goto L_8080078C;
    }
    // 0x808006FC: addiu       $t3, $zero, 0x53D
    ctx->r11 = ADD32(0, 0X53D);
    // 0x80800700: b           L_808007A8
    // 0x80800704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007A8;
    // 0x80800704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800708:
    // 0x80800708: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    // 0x8080070C: beq         $a3, $at, L_80800750
    if (ctx->r7 == ctx->r1) {
        // 0x80800710: addiu       $at, $zero, 0x1C9
        ctx->r1 = ADD32(0, 0X1C9);
            goto L_80800750;
    }
    // 0x80800710: addiu       $at, $zero, 0x1C9
    ctx->r1 = ADD32(0, 0X1C9);
    // 0x80800714: beq         $a3, $at, L_80800730
    if (ctx->r7 == ctx->r1) {
        // 0x80800718: addiu       $at, $zero, 0x1CA
        ctx->r1 = ADD32(0, 0X1CA);
            goto L_80800730;
    }
    // 0x80800718: addiu       $at, $zero, 0x1CA
    ctx->r1 = ADD32(0, 0X1CA);
    // 0x8080071C: beq         $a3, $at, L_80800730
    if (ctx->r7 == ctx->r1) {
        // 0x80800720: addiu       $at, $zero, 0x1CB
        ctx->r1 = ADD32(0, 0X1CB);
            goto L_80800730;
    }
    // 0x80800720: addiu       $at, $zero, 0x1CB
    ctx->r1 = ADD32(0, 0X1CB);
    // 0x80800724: beq         $a3, $at, L_80800730
    if (ctx->r7 == ctx->r1) {
        // 0x80800728: addiu       $at, $zero, 0x1CC
        ctx->r1 = ADD32(0, 0X1CC);
            goto L_80800730;
    }
    // 0x80800728: addiu       $at, $zero, 0x1CC
    ctx->r1 = ADD32(0, 0X1CC);
    // 0x8080072C: bne         $a3, $at, L_808007A4
    if (ctx->r7 != ctx->r1) {
        // 0x80800730: addiu       $t7, $zero, 0x404
        ctx->r15 = ADD32(0, 0X404);
            goto L_808007A4;
    }
L_80800730:
    // 0x80800730: addiu       $t7, $zero, 0x404
    ctx->r15 = ADD32(0, 0X404);
    // 0x80800734: sh          $t7, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r15;
    // 0x80800738: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFB8) << 16);
    // 0x8080073C: lwc1        $f4, 0xFB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFB8));
    // 0x80800740: addiu       $t8, $zero, 0x4E20
    ctx->r24 = ADD32(0, 0X4E20);
    // 0x80800744: sh          $t8, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r24;
    // 0x80800748: b           L_808007A4
    // 0x8080074C: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
        goto L_808007A4;
    // 0x8080074C: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
L_80800750:
    // 0x80800750: addiu       $t9, $zero, 0x404
    ctx->r25 = ADD32(0, 0X404);
    // 0x80800754: sh          $t9, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r25;
    // 0x80800758: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFBC) << 16);
    // 0x8080075C: lwc1        $f6, 0xFBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFBC));
    // 0x80800760: addiu       $t0, $zero, 0x4E20
    ctx->r8 = ADD32(0, 0X4E20);
    // 0x80800764: sh          $t0, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r8;
    // 0x80800768: b           L_808007A4
    // 0x8080076C: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
        goto L_808007A4;
    // 0x8080076C: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
L_80800770:
    // 0x80800770: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800774: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800778: addiu       $t2, $zero, 0x3E80
    ctx->r10 = ADD32(0, 0X3E80);
    // 0x8080077C: sh          $t1, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r9;
    // 0x80800780: sh          $t2, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r10;
    // 0x80800784: b           L_808007A4
    // 0x80800788: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
        goto L_808007A4;
    // 0x80800788: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
L_8080078C:
    // 0x8080078C: sh          $t3, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r11;
    // 0x80800790: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFC0) << 16);
    // 0x80800794: lwc1        $f10, 0xFC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFC0));
    // 0x80800798: addiu       $t4, $zero, 0x3E80
    ctx->r12 = ADD32(0, 0X3E80);
    // 0x8080079C: sh          $t4, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r12;
    // 0x808007A0: swc1        $f10, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f10.u32l;
L_808007A4:
    // 0x808007A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007A8:
    // 0x808007A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808007AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007B0: jr          $ra
    // 0x808007B4: nop

    return;
    // 0x808007B4: nop

;}
RECOMP_FUNC void func_800A9C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9C58: jal         0x800A8264
    // 0x800A9C5C: nop

    func_800A8264(rdram, ctx);
        goto after_0;
    // 0x800A9C5C: nop

    after_0:
    // 0x800A9C60: bne         $v0, $zero, L_800A9C88
    if (ctx->r2 != 0) {
        // 0x800A9C64: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800A9C88;
    }
    // 0x800A9C64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9C68: addiu       $v0, $v0, 0x7760
    ctx->r2 = ADD32(ctx->r2, 0X7760);
    // 0x800A9C6C: lh          $a0, 0xA($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA);
    // 0x800A9C70: jal         0x800A79D4
    // 0x800A9C74: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    func_800A79D4(rdram, ctx);
        goto after_1;
    // 0x800A9C74: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    after_1:
    // 0x800A9C78: jal         0x800A7A90
    // 0x800A9C7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A7A90(rdram, ctx);
        goto after_2;
    // 0x800A9C7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800A9C80: jal         0x800A7B18
    // 0x800A9C84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A7B18(rdram, ctx);
        goto after_3;
    // 0x800A9C84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
L_800A9C88:
    // 0x800A9C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9C8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9C90: jr          $ra
    // 0x800A9C94: nop

    return;
    // 0x800A9C94: nop

;}
RECOMP_FUNC void func_80801FAC_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80801FAC_chdinoboss");
    // 0x80801FAC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80801FB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801FB4: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80801FB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801FBC: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80801FC0: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80801FC4: jal         0x80100094
    // 0x80801FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801FCC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801FD0: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80801FD4: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x80801FD8: lh          $t7, 0x13A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X13A);
    // 0x80801FDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801FE0: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80801FE4: beql        $t7, $zero, L_80802004
    if (ctx->r15 == 0) {
        // 0x80801FE8: lh          $t9, 0x13A($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X13A);
            goto L_80802004;
    }
    goto skip_0;
    // 0x80801FE8: lh          $t9, 0x13A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X13A);
    skip_0:
    // 0x80801FEC: bnel        $t8, $zero, L_80802004
    if (ctx->r24 != 0) {
        // 0x80801FF0: lh          $t9, 0x13A($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X13A);
            goto L_80802004;
    }
    goto skip_1;
    // 0x80801FF0: lh          $t9, 0x13A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X13A);
    skip_1:
    // 0x80801FF4: jal         0x80090708
    // 0x80801FF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_1;
    // 0x80801FF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80801FFC: sh          $zero, 0x13A($s0)
    MEM_H(0X13A, ctx->r16) = 0;
    // 0x80802000: lh          $t9, 0x13A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X13A);
L_80802004:
    // 0x80802004: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80802008: bnel        $t9, $zero, L_8080202C
    if (ctx->r25 != 0) {
        // 0x8080200C: lw          $t2, 0x7C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X7C);
            goto L_8080202C;
    }
    goto skip_2;
    // 0x8080200C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    skip_2:
    // 0x80802010: beql        $t0, $zero, L_8080202C
    if (ctx->r8 == 0) {
        // 0x80802014: lw          $t2, 0x7C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X7C);
            goto L_8080202C;
    }
    goto skip_3;
    // 0x80802014: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    skip_3:
    // 0x80802018: jal         0x80090708
    // 0x8080201C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_2;
    // 0x8080201C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80802020: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80802024: sh          $t1, 0x13A($s0)
    MEM_H(0X13A, ctx->r16) = ctx->r9;
    // 0x80802028: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
L_8080202C:
    // 0x8080202C: lh          $t3, 0x138($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X138);
    // 0x80802030: addiu       $a0, $s0, 0x148
    ctx->r4 = ADD32(ctx->r16, 0X148);
    // 0x80802034: addiu       $a1, $s0, 0x154
    ctx->r5 = ADD32(ctx->r16, 0X154);
    // 0x80802038: beql        $t2, $t3, L_8080231C
    if (ctx->r10 == ctx->r11) {
        // 0x8080203C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080231C;
    }
    goto skip_4;
    // 0x8080203C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80802040: jal         0x80801E90
    // 0x80802044: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80801E90_chdinoboss(rdram, ctx);
        goto after_3;
    // 0x80802044: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x80802048: lh          $v0, 0x138($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X138);
    // 0x8080204C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802050: beq         $v0, $zero, L_80802078
    if (ctx->r2 == 0) {
        // 0x80802054: nop
    
            goto L_80802078;
    }
    // 0x80802054: nop

    // 0x80802058: beq         $v0, $at, L_8080208C
    if (ctx->r2 == ctx->r1) {
        // 0x8080205C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080208C;
    }
    // 0x8080205C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802060: beq         $v0, $at, L_8080208C
    if (ctx->r2 == ctx->r1) {
        // 0x80802064: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080208C;
    }
    // 0x80802064: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802068: beql        $v0, $at, L_80802090
    if (ctx->r2 == ctx->r1) {
        // 0x8080206C: lw          $v0, 0x7C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X7C);
            goto L_80802090;
    }
    goto skip_5;
    // 0x8080206C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    skip_5:
    // 0x80802070: b           L_80802090
    // 0x80802074: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_80802090;
    // 0x80802074: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80802078:
    // 0x80802078: jal         0x800F54E4
    // 0x8080207C: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x8080207C: nop

    after_4:
    // 0x80802080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802084: jal         0x800F7B9C
    // 0x80802088: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    func_800F7B9C(rdram, ctx);
        goto after_5;
    // 0x80802088: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    after_5:
L_8080208C:
    // 0x8080208C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80802090:
    // 0x80802090: beq         $v0, $zero, L_808020B8
    if (ctx->r2 == 0) {
        // 0x80802094: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808020B8;
    }
    // 0x80802094: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802098: beq         $v0, $at, L_80802114
    if (ctx->r2 == ctx->r1) {
        // 0x8080209C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802114;
    }
    // 0x8080209C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808020A0: beq         $v0, $at, L_808021D0
    if (ctx->r2 == ctx->r1) {
        // 0x808020A4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808021D0;
    }
    // 0x808020A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808020A8: beq         $v0, $at, L_80802258
    if (ctx->r2 == ctx->r1) {
        // 0x808020AC: nop
    
            goto L_80802258;
    }
    // 0x808020AC: nop

    // 0x808020B0: b           L_80802274
    // 0x808020B4: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
        goto L_80802274;
    // 0x808020B4: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
L_808020B8:
    // 0x808020B8: jal         0x8008FE68
    // 0x808020BC: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_8008FE68(rdram, ctx);
        goto after_6;
    // 0x808020BC: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_6:
    // 0x808020C0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808020C4: jal         0x80801E90
    // 0x808020C8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80801E90_chdinoboss(rdram, ctx);
        goto after_7;
    // 0x808020C8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x808020CC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808020D0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808020D4: jal         0x800EFB24
    // 0x808020D8: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x808020D8: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_8:
    // 0x808020DC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808020E0: jal         0x800EF368
    // 0x808020E4: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    func_800EF368(rdram, ctx);
        goto after_9;
    // 0x808020E4: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_9:
    // 0x808020E8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x808020EC: jal         0x800EF04C
    // 0x808020F0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x808020F0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_10:
    // 0x808020F4: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x808020F8: jal         0x80801ECC
    // 0x808020FC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80801ECC_chdinoboss(rdram, ctx);
        goto after_11;
    // 0x808020FC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x80802100: jal         0x80801F44
    // 0x80802104: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80801F44_chdinoboss(rdram, ctx);
        goto after_12;
    // 0x80802104: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x80802108: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8080210C: b           L_80802270
    // 0x80802110: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_80802270;
    // 0x80802110: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80802114:
    // 0x80802114: jal         0x80801F44
    // 0x80802118: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80801F44_chdinoboss(rdram, ctx);
        goto after_13;
    // 0x80802118: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_13:
    // 0x8080211C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80802120: jal         0x80102D78
    // 0x80802124: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80102D78(rdram, ctx);
        goto after_14;
    // 0x80802124: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_14:
    // 0x80802128: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8080212C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80802130: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80802134: jal         0x800F1EA4
    // 0x80802138: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F1EA4(rdram, ctx);
        goto after_15;
    // 0x80802138: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_15:
    // 0x8080213C: bne         $v0, $zero, L_8080214C
    if (ctx->r2 != 0) {
        // 0x80802140: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_8080214C;
    }
    // 0x80802140: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80802144: lwc1        $f4, 0x48($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X48);
    // 0x80802148: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
L_8080214C:
    // 0x8080214C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80802150: jal         0x800F1DCC
    // 0x80802154: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    func_800F1DCC(rdram, ctx);
        goto after_16;
    // 0x80802154: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    after_16:
    // 0x80802158: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080215C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80802160: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802164: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80802168: nop

    // 0x8080216C: bc1fl       L_80802188
    if (!c1cs) {
        // 0x80802170: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80802188;
    }
    goto skip_6;
    // 0x80802170: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_6:
    // 0x80802174: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80802178: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080217C: b           L_80802190
    // 0x80802180: swc1        $f8, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f8.u32l;
        goto L_80802190;
    // 0x80802180: swc1        $f8, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f8.u32l;
    // 0x80802184: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80802188:
    // 0x80802188: nop

    // 0x8080218C: swc1        $f10, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f10.u32l;
L_80802190:
    // 0x80802190: lh          $t5, 0x164($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X164);
    // 0x80802194: beql        $t5, $zero, L_808021A8
    if (ctx->r13 == 0) {
        // 0x80802198: lw          $t6, 0x78($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X78);
            goto L_808021A8;
    }
    goto skip_7;
    // 0x80802198: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    skip_7:
    // 0x8080219C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x808021A0: sh          $zero, 0x164($s0)
    MEM_H(0X164, ctx->r16) = 0;
    // 0x808021A4: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
L_808021A8:
    // 0x808021A8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808021AC: lhu         $v0, 0x72($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X72);
    // 0x808021B0: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x808021B4: beq         $t7, $at, L_808021C4
    if (ctx->r15 == ctx->r1) {
        // 0x808021B8: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_808021C4;
    }
    // 0x808021B8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808021BC: bne         $t7, $at, L_808021C8
    if (ctx->r15 != ctx->r1) {
        // 0x808021C0: nop
    
            goto L_808021C8;
    }
    // 0x808021C0: nop

L_808021C4:
    // 0x808021C4: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
L_808021C8:
    // 0x808021C8: b           L_80802270
    // 0x808021CC: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_80802270;
    // 0x808021CC: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_808021D0:
    // 0x808021D0: jal         0x80801F44
    // 0x808021D4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80801F44_chdinoboss(rdram, ctx);
        goto after_17;
    // 0x808021D4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_17:
    // 0x808021D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808021DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808021E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808021E4: jal         0x800DC298
    // 0x808021E8: swc1        $f16, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f16.u32l;
    func_800DC298(rdram, ctx);
        goto after_18;
    // 0x808021E8: swc1        $f16, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f16.u32l;
    after_18:
    // 0x808021EC: beq         $v0, $zero, L_80802204
    if (ctx->r2 == 0) {
        // 0x808021F0: lw          $t9, 0x78($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X78);
            goto L_80802204;
    }
    // 0x808021F0: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x808021F4: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x808021F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808021FC: b           L_80802214
    // 0x80802200: lwc1        $f18, 0x48($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X48);
        goto L_80802214;
    // 0x80802200: lwc1        $f18, 0x48($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X48);
L_80802204:
    // 0x80802204: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80802208: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080220C: nop

    // 0x80802210: lwc1        $f18, 0x48($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X48);
L_80802214:
    // 0x80802214: jal         0x800136E4
    // 0x80802218: add.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_19;
    // 0x80802218: add.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f0.fl;
    after_19:
    // 0x8080221C: addiu       $a0, $s0, 0x16C
    ctx->r4 = ADD32(ctx->r16, 0X16C);
    // 0x80802220: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802224: lui         $a2, 0x45BB
    ctx->r6 = S32(0X45BB << 16);
    // 0x80802228: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8080222C: jal         0x800EEB9C
    // 0x80802230: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EEB9C(rdram, ctx);
        goto after_20;
    // 0x80802230: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_20:
    // 0x80802234: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80802238: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080223C: jal         0x800EF04C
    // 0x80802240: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_21;
    // 0x80802240: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_21:
    // 0x80802244: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80802248: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x8080224C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80802250: b           L_80802270
    // 0x80802254: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_80802270;
    // 0x80802254: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80802258:
    // 0x80802258: jal         0x80801F44
    // 0x8080225C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80801F44_chdinoboss(rdram, ctx);
        goto after_22;
    // 0x8080225C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_22:
    // 0x80802260: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80802264: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80802268: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8080226C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80802270:
    // 0x80802270: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
L_80802274:
    // 0x80802274: beql        $t2, $zero, L_808022B8
    if (ctx->r10 == 0) {
        // 0x80802278: lw          $t5, 0x64($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X64);
            goto L_808022B8;
    }
    goto skip_8;
    // 0x80802278: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    skip_8:
    // 0x8080227C: lh          $t3, 0x13C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X13C);
    // 0x80802280: bnel        $t3, $zero, L_808022B8
    if (ctx->r11 != 0) {
        // 0x80802284: lw          $t5, 0x64($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X64);
            goto L_808022B8;
    }
    goto skip_9;
    // 0x80802284: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    skip_9:
    // 0x80802288: jal         0x800EA05C
    // 0x8080228C: nop

    func_800EA05C(rdram, ctx);
        goto after_23;
    // 0x8080228C: nop

    after_23:
    // 0x80802290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802294: jal         0x800887D8
    // 0x80802298: addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_24;
    // 0x80802298: addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
    after_24:
    // 0x8080229C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808022A0: jal         0x800C52F4
    // 0x808022A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C52F4(rdram, ctx);
        goto after_25;
    // 0x808022A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_25:
    // 0x808022A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808022AC: sh          $t4, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r12;
    // 0x808022B0: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x808022B4: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
L_808022B8:
    // 0x808022B8: bnel        $t5, $zero, L_808022EC
    if (ctx->r13 != 0) {
        // 0x808022BC: sh          $v0, 0x138($s0)
        MEM_H(0X138, ctx->r16) = ctx->r2;
            goto L_808022EC;
    }
    goto skip_10;
    // 0x808022BC: sh          $v0, 0x138($s0)
    MEM_H(0X138, ctx->r16) = ctx->r2;
    skip_10:
    // 0x808022C0: lh          $t6, 0x13C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X13C);
    // 0x808022C4: beql        $t6, $zero, L_808022EC
    if (ctx->r14 == 0) {
        // 0x808022C8: sh          $v0, 0x138($s0)
        MEM_H(0X138, ctx->r16) = ctx->r2;
            goto L_808022EC;
    }
    goto skip_11;
    // 0x808022C8: sh          $v0, 0x138($s0)
    MEM_H(0X138, ctx->r16) = ctx->r2;
    skip_11:
    // 0x808022CC: jal         0x80088830
    // 0x808022D0: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_26;
    // 0x808022D0: nop

    after_26:
    // 0x808022D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808022D8: jal         0x800C53EC
    // 0x808022DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C53EC(rdram, ctx);
        goto after_27;
    // 0x808022DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_27:
    // 0x808022E0: sh          $zero, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = 0;
    // 0x808022E4: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x808022E8: sh          $v0, 0x138($s0)
    MEM_H(0X138, ctx->r16) = ctx->r2;
L_808022EC:
    // 0x808022EC: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x808022F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808022F4: beql        $t7, $zero, L_80802318
    if (ctx->r15 == 0) {
        // 0x808022F8: sh          $zero, 0x13E($s0)
        MEM_H(0X13E, ctx->r16) = 0;
            goto L_80802318;
    }
    goto skip_12;
    // 0x808022F8: sh          $zero, 0x13E($s0)
    MEM_H(0X13E, ctx->r16) = 0;
    skip_12:
    // 0x808022FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80802300: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802304: sh          $t8, 0x13E($s0)
    MEM_H(0X13E, ctx->r16) = ctx->r24;
    // 0x80802308: swc1        $f0, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f0.u32l;
    // 0x8080230C: b           L_80802318
    // 0x80802310: swc1        $f0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f0.u32l;
        goto L_80802318;
    // 0x80802310: swc1        $f0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f0.u32l;
    // 0x80802314: sh          $zero, 0x13E($s0)
    MEM_H(0X13E, ctx->r16) = 0;
L_80802318:
    // 0x80802318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080231C:
    // 0x8080231C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802320: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80802324: jr          $ra
    // 0x80802328: nop

    return;
    // 0x80802328: nop

;}
RECOMP_FUNC void chtntdetonator_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005EC: jal         0x800DA298
    // 0x808005F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808005F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808005F4: beq         $v0, $zero, L_80800630
    if (ctx->r2 == 0) {
        // 0x808005F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800630;
    }
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: addiu       $a1, $zero, 0x149
    ctx->r5 = ADD32(0, 0X149);
    // 0x80800604: jal         0x80089C58
    // 0x80800608: addiu       $a2, $zero, 0x320
    ctx->r6 = ADD32(0, 0X320);
    _subaddiefind_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800608: addiu       $a2, $zero, 0x320
    ctx->r6 = ADD32(0, 0X320);
    after_1:
    // 0x8080060C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800610: beq         $v0, $at, L_80800620
    if (ctx->r2 == ctx->r1) {
        // 0x80800614: nop
    
            goto L_80800620;
    }
    // 0x80800614: nop

    // 0x80800618: jal         0x800FFA88
    // 0x8080061C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x8080061C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
L_80800620:
    // 0x80800620: jal         0x800FFAB0
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800628: b           L_80800664
    // 0x8080062C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800664;
    // 0x8080062C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800630:
    // 0x80800630: addiu       $a1, $zero, 0x149
    ctx->r5 = ADD32(0, 0X149);
    // 0x80800634: jal         0x80089C58
    // 0x80800638: addiu       $a2, $zero, 0x320
    ctx->r6 = ADD32(0, 0X320);
    _subaddiefind_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800638: addiu       $a2, $zero, 0x320
    ctx->r6 = ADD32(0, 0X320);
    after_4:
    // 0x8080063C: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x80800640: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800654;
    }
    // 0x80800640: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800644: jal         0x80106790
    // 0x80800648: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800648: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_5:
    // 0x8080064C: b           L_80800654
    // 0x80800650: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800654;
    // 0x80800650: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800654:
    // 0x80800654: beq         $v1, $zero, L_80800664
    if (ctx->r3 == 0) {
        // 0x80800658: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800664;
    }
    // 0x80800658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080065C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80800660: sw          $t6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r14;
L_80800664:
    // 0x80800664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080066C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800670: jr          $ra
    // 0x80800674: nop

    return;
    // 0x80800674: nop

    // 0x80800678: nop

    // 0x8080067C: nop

;}
RECOMP_FUNC void func_80802C6C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802C78: jal         0x800FC660
    // 0x80802C7C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_0;
    // 0x80802C7C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x80802C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802C88: jr          $ra
    // 0x80802C8C: nop

    return;
    // 0x80802C8C: nop

;}
RECOMP_FUNC void _bsvan_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084188: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084188);
    return;
    // 0x8008418C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840B8: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x800840B8);
    return;
    // 0x800840BC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _bskazmove_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834C8: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x800834C8);
    return;
    // 0x800834CC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chflysaucer_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808014D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014DC: jal         0x80106790
    // 0x808014E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808014E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808014E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014E8: jal         0x80100094
    // 0x808014EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808014EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808014F0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x808014F4: beql        $t6, $zero, L_80801528
    if (ctx->r14 == 0) {
        // 0x808014F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801528;
    }
    goto skip_0;
    // 0x808014F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808014FC: jal         0x80104200
    // 0x80801500: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    func_80104200(rdram, ctx);
        goto after_2;
    // 0x80801500: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_2:
    // 0x80801504: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801508: jal         0x8008B264
    // 0x8080150C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_3;
    // 0x8080150C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80801510: addiu       $at, $zero, 0x486
    ctx->r1 = ADD32(0, 0X486);
    // 0x80801514: bne         $v0, $at, L_80801524
    if (ctx->r2 != ctx->r1) {
        // 0x80801518: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80801524;
    }
    // 0x80801518: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080151C: jal         0x8008B10C
    // 0x80801520: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8008B10C(rdram, ctx);
        goto after_4;
    // 0x80801520: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
L_80801524:
    // 0x80801524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801528:
    // 0x80801528: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080152C: jr          $ra
    // 0x80801530: nop

    return;
    // 0x80801530: nop

;}
RECOMP_FUNC void func_808065C0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808065C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808065C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808065C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808065CC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x808065D0: jal         0x80803D00
    // 0x808065D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808065D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808065D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808065DC: jal         0x80108B04
    // 0x808065E0: addiu       $a1, $zero, 0x4B6
    ctx->r5 = ADD32(0, 0X4B6);
    func_80108B04(rdram, ctx);
        goto after_1;
    // 0x808065E0: addiu       $a1, $zero, 0x4B6
    ctx->r5 = ADD32(0, 0X4B6);
    after_1:
    // 0x808065E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808065E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808065EC: jr          $ra
    // 0x808065F0: nop

    return;
    // 0x808065F0: nop

;}
RECOMP_FUNC void func_80801108_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080110C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801110: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801114: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80801118: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1636, 0X1590) << 16);
    // 0x8080111C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801120: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80801124: bltz        $t8, L_80801170
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801128: addiu       $a2, $a2, 0x1590
        ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1636, 0X1590));
            goto L_80801170;
    }
    // 0x80801128: addiu       $a2, $a2, 0x1590
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1636, 0X1590));
    // 0x8080112C: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    // 0x80801130: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80801134: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801138: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x8080113C: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    // 0x80801140: slti        $at, $a1, 0xF6
    ctx->r1 = SIGNED(ctx->r5) < 0XF6 ? 1 : 0;
    // 0x80801144: bnel        $at, $zero, L_80801158
    if (ctx->r1 != 0) {
        // 0x80801148: slti        $at, $a1, 0xA
        ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
            goto L_80801158;
    }
    goto skip_0;
    // 0x80801148: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    skip_0:
    // 0x8080114C: b           L_80801164
    // 0x80801150: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
        goto L_80801164;
    // 0x80801150: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80801154: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
L_80801158:
    // 0x80801158: beq         $at, $zero, L_80801164
    if (ctx->r1 == 0) {
        // 0x8080115C: nop
    
            goto L_80801164;
    }
    // 0x8080115C: nop

    // 0x80801160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80801164:
    // 0x80801164: jal         0x800B99CC
    // 0x80801168: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800B99CC(rdram, ctx);
        goto after_0;
    // 0x80801168: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080116C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80801170:
    // 0x80801170: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801174: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801178: jal         0x80800F50
    // 0x8080117C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80800F50_chcredits(rdram, ctx);
        goto after_1;
    // 0x8080117C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80801180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801184: jal         0x80800C84
    // 0x80801188: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800C84_chcredits(rdram, ctx);
        goto after_2;
    // 0x80801188: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8080118C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801194: jr          $ra
    // 0x80801198: nop

    return;
    // 0x80801198: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843A8: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800843A8);
    return;
    // 0x800843AC: addi        $t0, $zero, 0x90
    ctx->r8 = ADD32(0, 0X90);
;}
RECOMP_FUNC void bawasher_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800074: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080007C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800080: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800084: jal         0x800F0DC0
    // 0x80800088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F0DC0(rdram, ctx);
        goto after_0;
    // 0x80800088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080008C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: lw          $t7, 0x14C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14C);
    // 0x80800094: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_8080000C_chicywind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8080001C: jal         0x800D0B68
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D0B68(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: beql        $v0, $zero, L_80800038
    if (ctx->r2 == 0) {
        // 0x80800028: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800038;
    }
    goto skip_0;
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080002C: jal         0x800FFAB0
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800038:
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_8080137C_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080137C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801384: jal         0x800839B8
    // 0x80801388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80801388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080138C: jal         0x808000F0
    // 0x80801390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_bswasher(rdram, ctx);
        goto after_1;
    // 0x80801390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080139C: jr          $ra
    // 0x808013A0: nop

    return;
    // 0x808013A0: nop

;}
RECOMP_FUNC void func_80800000_bsstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80800004: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(368, 0XD90) << 16);
    // 0x80800008: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8080000C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80800010: jr          $ra
    // 0x80800014: lw          $v0, 0xD90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(368, 0XD90));
    return;
    // 0x80800014: lw          $v0, 0xD90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(368, 0XD90));
;}
RECOMP_FUNC void func_80099A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099A34: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x80099A38: jr          $ra
    // 0x80099A3C: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    return;
    // 0x80099A3C: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void _gcdialogexec_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E50: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E50);
    return;
    // 0x80087E54: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void bamovespline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D8: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808002DC: lbu         $v0, 0x90($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X90);
    // 0x808002E0: xori        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 ^ 0X4;
    // 0x808002E4: jr          $ra
    // 0x808002E8: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    return;
    // 0x808002E8: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80800940_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800940: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800944: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800948: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080094C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800950: addiu       $a0, $zero, 0x32C
    ctx->r4 = ADD32(0, 0X32C);
    // 0x80800954: jal         0x801084B0
    // 0x80800958: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80800958: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8080095C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800960: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800964: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800968: jal         0x80102FDC
    // 0x8080096C: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x8080096C: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_1:
    // 0x80800970: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800974: jal         0x80089CD8
    // 0x80800978: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800978: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800980: jal         0x80089CE8
    // 0x80800984: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800984: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x80800988: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8080098C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800990: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
    // 0x80800994: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800998: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x8080099C: lhu         $t1, 0x64($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X64);
    // 0x808009A0: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x808009A4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x808009A8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808009AC: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x808009B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808009BC: jr          $ra
    // 0x808009C0: nop

    return;
    // 0x808009C0: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D44: lw          $v1, 0x90($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X90);
    // 0x80800D48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800D4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D50: lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X10);
    // 0x80800D54: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800D58: beq         $v0, $a2, L_80800D70
    if (ctx->r2 == ctx->r6) {
        // 0x80800D5C: nop
    
            goto L_80800D70;
    }
    // 0x80800D5C: nop

    // 0x80800D60: beq         $v0, $at, L_80800D80
    if (ctx->r2 == ctx->r1) {
        // 0x80800D64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D80;
    }
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D68: b           L_80800D94
    // 0x80800D6C: nop

        goto L_80800D94;
    // 0x80800D6C: nop

L_80800D70:
    // 0x80800D70: bne         $a1, $a2, L_80800D94
    if (ctx->r5 != ctx->r6) {
        // 0x80800D74: nop
    
            goto L_80800D94;
    }
    // 0x80800D74: nop

    // 0x80800D78: b           L_80800E20
    // 0x80800D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800E20;
    // 0x80800D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D80:
    // 0x80800D80: jal         0x8080064C
    // 0x80800D84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8080064C_bafpctrl(rdram, ctx);
        goto after_0;
    // 0x80800D84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800D88: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800D8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800D90: lw          $v1, 0x90($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X90);
L_80800D94:
    // 0x80800D94: beq         $a1, $a2, L_80800DBC
    if (ctx->r5 == ctx->r6) {
        // 0x80800D98: sb          $a1, 0x10($v1)
        MEM_B(0X10, ctx->r3) = ctx->r5;
            goto L_80800DBC;
    }
    // 0x80800D98: sb          $a1, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r5;
    // 0x80800D9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DA0: beq         $a1, $at, L_80800DF4
    if (ctx->r5 == ctx->r1) {
        // 0x80800DA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DF4;
    }
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DA8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800DAC: beq         $a1, $at, L_80800E08
    if (ctx->r5 == ctx->r1) {
        // 0x80800DB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E08;
    }
    // 0x80800DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DB4: b           L_80800E20
    // 0x80800DB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800E20;
    // 0x80800DB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800DBC:
    // 0x80800DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DC0: jal         0x80800CA0
    // 0x80800DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bafpctrl_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DCC: jal         0x80800CAC
    // 0x80800DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bafpctrl_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800DD4: lw          $t6, 0x90($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X90);
    // 0x80800DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DDC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800DE4: jal         0x8009ADF0
    // 0x80800DE8: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    func_8009ADF0(rdram, ctx);
        goto after_3;
    // 0x80800DE8: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    after_3:
    // 0x80800DEC: b           L_80800E20
    // 0x80800DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800E20;
    // 0x80800DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800DF4:
    // 0x80800DF4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800DF8: jal         0x8009ADF0
    // 0x80800DFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_4;
    // 0x80800DFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800E00: b           L_80800E20
    // 0x80800E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800E20;
    // 0x80800E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E08:
    // 0x80800E08: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800E0C: jal         0x8009ADF0
    // 0x80800E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_5;
    // 0x80800E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80800E14: jal         0x80800704
    // 0x80800E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800704_bafpctrl(rdram, ctx);
        goto after_6;
    // 0x80800E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800E1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E20:
    // 0x80800E20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E28: jr          $ra
    // 0x80800E2C: nop

    return;
    // 0x80800E2C: nop

;}
RECOMP_FUNC void chTalTorpWall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2040, 0X98) << 16);
    // 0x8080006C: jr          $ra
    // 0x80800070: addiu       $v0, $v0, 0x98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2040, 0X98));
    return;
    // 0x80800070: addiu       $v0, $v0, 0x98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2040, 0X98));
    // 0x80800074: nop

    // 0x80800078: nop

    // 0x8080007C: nop

;}
RECOMP_FUNC void _gcstatusDll_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088380: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088380);
    return;
    // 0x80088384: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800CA6D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA6D4: lwc1        $f4, 0xEC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x800CA6D8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800CA6DC: lwc1        $f6, 0xF0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XF0);
    // 0x800CA6E0: jr          $ra
    // 0x800CA6E4: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    return;
    // 0x800CA6E4: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
;}
RECOMP_FUNC void _susubgame_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2F0: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2F0);
    return;
    // 0x8008A2F4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void bsrest_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004C8: jal         0x808003FC
    // 0x808004CC: nop

    static_344_808003FC(rdram, ctx);
        goto after_0;
    // 0x808004CC: nop

    after_0:
    // 0x808004D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004D8: jr          $ra
    // 0x808004DC: nop

    return;
    // 0x808004DC: nop

;}
RECOMP_FUNC void func_80800980_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800988: jal         0x8080016C
    // 0x8080098C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsmum_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080098C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800990: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800994: jal         0x808007A0
    // 0x80800998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808007A0_bsmum(rdram, ctx);
        goto after_1;
    // 0x80800998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080099C: jal         0x8009E704
    // 0x808009A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bs_getNextState(rdram, ctx);
        goto after_2;
    // 0x808009A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808009A4: addiu       $at, $zero, 0xEF
    ctx->r1 = ADD32(0, 0XEF);
    // 0x808009A8: bne         $v0, $at, L_808009B8
    if (ctx->r2 != ctx->r1) {
        // 0x808009AC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808009B8;
    }
    // 0x808009AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808009B0: jal         0x8009B9B0
    // 0x808009B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x808009B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
L_808009B8:
    // 0x808009B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009C0: jr          $ra
    // 0x808009C4: nop

    return;
    // 0x808009C4: nop

;}
RECOMP_FUNC void chheggy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019C0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2456, 0X1E9C) << 16);
    // 0x808019C4: jr          $ra
    // 0x808019C8: addiu       $v0, $v0, 0x1E9C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2456, 0X1E9C));
    return;
    // 0x808019C8: addiu       $v0, $v0, 0x1E9C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2456, 0X1E9C));
;}
RECOMP_FUNC void func_8009105C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009105C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091064: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80091068: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009106C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80091070: sb          $zero, 0xC($t6)
    MEM_B(0XC, ctx->r14) = 0;
    // 0x80091074: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x80091078: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009107C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80091080: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x80091084: lw          $t8, 0x30($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X30);
    // 0x80091088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009108C: sb          $zero, 0xE($t8)
    MEM_B(0XE, ctx->r24) = 0;
    // 0x80091090: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x80091094: swc1        $f0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f0.u32l;
    // 0x80091098: lw          $t0, 0x30($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X30);
    // 0x8009109C: swc1        $f0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f0.u32l;
    // 0x800910A0: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x800910A4: jal         0x800910BC
    // 0x800910A8: sb          $t1, 0xF($t2)
    MEM_B(0XF, ctx->r10) = ctx->r9;
    func_800910BC(rdram, ctx);
        goto after_0;
    // 0x800910A8: sb          $t1, 0xF($t2)
    MEM_B(0XF, ctx->r10) = ctx->r9;
    after_0:
    // 0x800910AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800910B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800910B4: jr          $ra
    // 0x800910B8: nop

    return;
    // 0x800910B8: nop

;}
RECOMP_FUNC void suegg_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B1C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800B20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800B24: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80800B28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B2C: jal         0x80100094
    // 0x80800B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B34: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B38: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800B3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B40: beq         $a3, $at, L_80800B74
    if (ctx->r7 == ctx->r1) {
        // 0x80800B44: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800B74;
    }
    // 0x80800B44: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800B48: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80800B4C: beq         $a3, $at, L_80800B8C
    if (ctx->r7 == ctx->r1) {
        // 0x80800B50: addiu       $at, $zero, 0x92
        ctx->r1 = ADD32(0, 0X92);
            goto L_80800B8C;
    }
    // 0x80800B50: addiu       $at, $zero, 0x92
    ctx->r1 = ADD32(0, 0X92);
    // 0x80800B54: beq         $a3, $at, L_80800BB0
    if (ctx->r7 == ctx->r1) {
        // 0x80800B58: addiu       $at, $zero, 0x98
        ctx->r1 = ADD32(0, 0X98);
            goto L_80800BB0;
    }
    // 0x80800B58: addiu       $at, $zero, 0x98
    ctx->r1 = ADD32(0, 0X98);
    // 0x80800B5C: beq         $a3, $at, L_80800BC0
    if (ctx->r7 == ctx->r1) {
        // 0x80800B60: addiu       $at, $zero, 0x9F
        ctx->r1 = ADD32(0, 0X9F);
            goto L_80800BC0;
    }
    // 0x80800B60: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x80800B64: beq         $a3, $at, L_80800BD0
    if (ctx->r7 == ctx->r1) {
        // 0x80800B68: nop
    
            goto L_80800BD0;
    }
    // 0x80800B68: nop

    // 0x80800B6C: b           L_80800BEC
    // 0x80800B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BEC;
    // 0x80800B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B74:
    // 0x80800B74: lbu         $t7, 0x39($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X39);
    // 0x80800B78: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80800B7C: jal         0x8010A570
    // 0x80800B80: sb          $t8, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r24;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80800B80: sb          $t8, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r24;
    after_1:
    // 0x80800B84: b           L_80800BEC
    // 0x80800B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BEC;
    // 0x80800B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B8C:
    // 0x80800B8C: lbu         $t0, 0x39($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X39);
    // 0x80800B90: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x80800B94: sb          $t1, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r9;
    // 0x80800B98: jal         0x8010A570
    // 0x80800B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800BA0: jal         0x800FFAB0
    // 0x80800BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800BA8: b           L_80800BEC
    // 0x80800BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BEC;
    // 0x80800BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BB0:
    // 0x80800BB0: lbu         $t3, 0x39($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X39);
    // 0x80800BB4: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80800BB8: b           L_80800BE8
    // 0x80800BBC: sb          $t4, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r12;
        goto L_80800BE8;
    // 0x80800BBC: sb          $t4, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r12;
L_80800BC0:
    // 0x80800BC0: lbu         $t6, 0x39($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X39);
    // 0x80800BC4: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x80800BC8: b           L_80800BE8
    // 0x80800BCC: sb          $t7, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r15;
        goto L_80800BE8;
    // 0x80800BCC: sb          $t7, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r15;
L_80800BD0:
    // 0x80800BD0: jal         0x80800DC0
    // 0x80800BD4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800DC0_suegg(rdram, ctx);
        goto after_4;
    // 0x80800BD4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800BD8: b           L_80800BEC
    // 0x80800BDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BEC;
    // 0x80800BDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800BE0: b           L_80800BEC
    // 0x80800BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BEC;
    // 0x80800BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BE8:
    // 0x80800BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BEC:
    // 0x80800BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BF4: jr          $ra
    // 0x80800BF8: nop

    return;
    // 0x80800BF8: nop

;}
RECOMP_FUNC void func_80801040_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801040: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801044: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080104C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801050: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80801054: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80801058: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x8080105C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80801060: jal         0x800EFA4C
    // 0x80801064: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80801064: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x80801068: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8080106C: addiu       $a0, $a0, 0x15D0
    ctx->r4 = ADD32(ctx->r4, 0X15D0);
    // 0x80801070: jal         0x800DF47C
    // 0x80801074: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_1;
    // 0x80801074: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80801078: jal         0x8010347C
    // 0x8080107C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_2;
    // 0x8080107C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80801080: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80801084: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80801088: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080108C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80801090: jal         0x800DE448
    // 0x80801094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_3;
    // 0x80801094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80801098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080109C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808010A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808010A4: jr          $ra
    // 0x808010A8: nop

    return;
    // 0x808010A8: nop

;}
RECOMP_FUNC void func_80801640_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801640: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801644: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801648: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080164C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801650: jal         0x8008CABC
    // 0x80801654: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801654: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801658: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080165C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801660: jal         0x8009D3A8
    // 0x80801664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x80801664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801668: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x8080166C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801670: beq         $v0, $zero, L_80801690
    if (ctx->r2 == 0) {
        // 0x80801674: nop
    
            goto L_80801690;
    }
    // 0x80801674: nop

    // 0x80801678: beq         $v0, $at, L_80801740
    if (ctx->r2 == ctx->r1) {
        // 0x8080167C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801740;
    }
    // 0x8080167C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801680: beq         $v0, $at, L_8080176C
    if (ctx->r2 == ctx->r1) {
        // 0x80801684: nop
    
            goto L_8080176C;
    }
    // 0x80801684: nop

    // 0x80801688: b           L_80801794
    // 0x8080168C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801794;
    // 0x8080168C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801690:
    // 0x80801690: jal         0x80801550
    // 0x80801694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801550_bskazfly(rdram, ctx);
        goto after_2;
    // 0x80801694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801698: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8080169C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808016A0: jal         0x8008B348
    // 0x808016A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x808016A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808016A8: beq         $v0, $zero, L_80801710
    if (ctx->r2 == 0) {
        // 0x808016AC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801710;
    }
    // 0x808016AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808016B0: jal         0x800F8B64
    // 0x808016B4: nop

    func_800F8B64(rdram, ctx);
        goto after_4;
    // 0x808016B4: nop

    after_4:
    // 0x808016B8: beql        $v0, $zero, L_80801794
    if (ctx->r2 == 0) {
        // 0x808016BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801794;
    }
    goto skip_0;
    // 0x808016BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808016C0: jal         0x800A0180
    // 0x808016C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0180(rdram, ctx);
        goto after_5;
    // 0x808016C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808016C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016CC: jal         0x800A4DFC
    // 0x808016D0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DFC(rdram, ctx);
        goto after_6;
    // 0x808016D0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x808016D4: jal         0x800A4CA8
    // 0x808016D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_7;
    // 0x808016D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808016DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808016E0: jal         0x80089288
    // 0x808016E4: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808016E4: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_8:
    // 0x808016E8: jal         0x80085208
    // 0x808016EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808016EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808016F0: lui         $a2, 0x404C
    ctx->r6 = S32(0X404C << 16);
    // 0x808016F4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808016F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016FC: jal         0x80085338
    // 0x80801700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_10;
    // 0x80801700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80801704: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801708: b           L_80801790
    // 0x8080170C: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
        goto L_80801790;
    // 0x8080170C: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
L_80801710:
    // 0x80801710: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x80801714: jal         0x8008B348
    // 0x80801718: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x80801718: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    after_11:
    // 0x8080171C: beq         $v0, $zero, L_80801790
    if (ctx->r2 == 0) {
        // 0x80801720: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801790;
    }
    // 0x80801720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801724: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x80801728: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080172C: jal         0x8008CCBC
    // 0x80801730: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_12;
    // 0x80801730: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    after_12:
    // 0x80801734: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801738: b           L_80801790
    // 0x8080173C: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
        goto L_80801790;
    // 0x8080173C: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
L_80801740:
    // 0x80801740: jal         0x8008B324
    // 0x80801744: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_13;
    // 0x80801744: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_13:
    // 0x80801748: beq         $v0, $zero, L_80801754
    if (ctx->r2 == 0) {
        // 0x8080174C: addiu       $t8, $zero, 0xBB
        ctx->r24 = ADD32(0, 0XBB);
            goto L_80801754;
    }
    // 0x8080174C: addiu       $t8, $zero, 0xBB
    ctx->r24 = ADD32(0, 0XBB);
    // 0x80801750: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80801754:
    // 0x80801754: jal         0x8008DD04
    // 0x80801758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_14;
    // 0x80801758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080175C: beq         $v0, $zero, L_80801790
    if (ctx->r2 == 0) {
        // 0x80801760: addiu       $t9, $zero, 0xDF
        ctx->r25 = ADD32(0, 0XDF);
            goto L_80801790;
    }
    // 0x80801760: addiu       $t9, $zero, 0xDF
    ctx->r25 = ADD32(0, 0XDF);
    // 0x80801764: b           L_80801790
    // 0x80801768: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
        goto L_80801790;
    // 0x80801768: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_8080176C:
    // 0x8080176C: jal         0x80801550
    // 0x80801770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801550_bskazfly(rdram, ctx);
        goto after_15;
    // 0x80801770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801778: jal         0x800852F0
    // 0x8080177C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_16;
    // 0x8080177C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80801780: beql        $v0, $zero, L_80801794
    if (ctx->r2 == 0) {
        // 0x80801784: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801794;
    }
    goto skip_1;
    // 0x80801784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80801788: jal         0x80085200
    // 0x8080178C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x8080178C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_80801790:
    // 0x80801790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801794:
    // 0x80801794: jal         0x8009E5C8
    // 0x80801798: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_18;
    // 0x80801798: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_18:
    // 0x8080179C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808017A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808017A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808017A8: jr          $ra
    // 0x808017AC: nop

    return;
    // 0x808017AC: nop

;}
RECOMP_FUNC void func_80800000_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800008: bne         $a0, $at, L_80800048
    if (ctx->r4 != ctx->r1) {
        // 0x8080000C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800048;
    }
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x8009EA2C
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA2C(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800018: beq         $v0, $zero, L_80800028
    if (ctx->r2 == 0) {
        // 0x8080001C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800028;
    }
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: b           L_80800060
    // 0x80800024: addiu       $v0, $zero, 0x838
    ctx->r2 = ADD32(0, 0X838);
        goto L_80800060;
    // 0x80800024: addiu       $v0, $zero, 0x838
    ctx->r2 = ADD32(0, 0X838);
L_80800028:
    // 0x80800028: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080002C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800030: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80800034: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2484, 0X7000) << 16);
    // 0x80800038: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8080003C: lw          $v1, 0x7000($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(2484, 0X7000));
    // 0x80800040: b           L_80800060
    // 0x80800044: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800060;
    // 0x80800044: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800048:
    // 0x80800048: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8080004C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80800050: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80800054: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2484, 0X7000) << 16);
    // 0x80800058: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8080005C: lw          $v0, 0x7000($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7000));
L_80800060:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void func_800D0BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0BD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D0BD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D0BDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D0BE0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D0BE4: jal         0x800D0A80
    // 0x800D0BE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800D0A80(rdram, ctx);
        goto after_0;
    // 0x800D0BE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D0BEC: beq         $v0, $zero, L_800D0C64
    if (ctx->r2 == 0) {
        // 0x800D0BF0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D0C64;
    }
    // 0x800D0BF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D0BF4: jal         0x800DA544
    // 0x800D0BF8: nop

    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x800D0BF8: nop

    after_1:
    // 0x800D0BFC: beq         $s0, $zero, L_800D0C4C
    if (ctx->r16 == 0) {
        // 0x800D0C00: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800D0C4C;
    }
    // 0x800D0C00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0C04: beq         $s0, $at, L_800D0C34
    if (ctx->r16 == ctx->r1) {
        // 0x800D0C08: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800D0C34;
    }
    // 0x800D0C08: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800D0C0C: bnel        $s0, $at, L_800D0C68
    if (ctx->r16 != ctx->r1) {
        // 0x800D0C10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D0C68;
    }
    goto skip_0;
    // 0x800D0C10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800D0C14: jal         0x800D035C
    // 0x800D0C18: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800D035C(rdram, ctx);
        goto after_2;
    // 0x800D0C18: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_2:
    // 0x800D0C1C: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x800D0C20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D0C24: jal         0x800D24E8
    // 0x800D0C28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_3;
    // 0x800D0C28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800D0C2C: b           L_800D0C68
    // 0x800D0C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800D0C68;
    // 0x800D0C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D0C34:
    // 0x800D0C34: jal         0x800D035C
    // 0x800D0C38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_4;
    // 0x800D0C38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800D0C3C: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x800D0C40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D0C44: jal         0x800D24E8
    // 0x800D0C48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_5;
    // 0x800D0C48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_800D0C4C:
    // 0x800D0C4C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D0C50: andi        $t8, $s0, 0xFFFF
    ctx->r24 = ctx->r16 & 0XFFFF;
    // 0x800D0C54: addiu       $a0, $zero, 0xB7
    ctx->r4 = ADD32(0, 0XB7);
    // 0x800D0C58: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800D0C5C: jal         0x80101238
    // 0x800D0C60: or          $a1, $t7, $t8
    ctx->r5 = ctx->r15 | ctx->r24;
    func_80101238(rdram, ctx);
        goto after_6;
    // 0x800D0C60: or          $a1, $t7, $t8
    ctx->r5 = ctx->r15 | ctx->r24;
    after_6:
L_800D0C64:
    // 0x800D0C64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D0C68:
    // 0x800D0C68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D0C6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D0C70: jr          $ra
    // 0x800D0C74: nop

    return;
    // 0x800D0C74: nop

;}
