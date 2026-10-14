#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8001A11C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A11C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A124: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A128: addiu       $a0, $a0, -0x4120
    ctx->r4 = ADD32(ctx->r4, -0X4120);
    // 0x8001A12C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A130: jal         0x8002EAD0
    // 0x8001A134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001A134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8001A138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A13C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A140: jr          $ra
    // 0x8001A144: nop

    return;
    // 0x8001A144: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E28: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E28);
    return;
    // 0x80082E2C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void _fxleaves_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088938: syscall     711
    recomp_syscall_handler(rdram, ctx, 0x80088938);
    return;
    // 0x8008893C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8001B4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B4B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001B4B4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001B4B8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001B4BC: addiu       $v0, $v0, -0x3920
    ctx->r2 = ADD32(ctx->r2, -0X3920);
    // 0x8001B4C0: addiu       $v1, $v1, -0x40E0
    ctx->r3 = ADD32(ctx->r3, -0X40E0);
    // 0x8001B4C4: sw          $zero, -0x40E8($at)
    MEM_W(-0X40E8, ctx->r1) = 0;
L_8001B4C8:
    // 0x8001B4C8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8001B4CC: sw          $zero, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = 0;
    // 0x8001B4D0: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x8001B4D4: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x8001B4D8: bne         $v1, $v0, L_8001B4C8
    if (ctx->r3 != ctx->r2) {
        // 0x8001B4DC: sw          $zero, -0x20($v1)
        MEM_W(-0X20, ctx->r3) = 0;
            goto L_8001B4C8;
    }
    // 0x8001B4DC: sw          $zero, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = 0;
    // 0x8001B4E0: jr          $ra
    // 0x8001B4E4: nop

    return;
    // 0x8001B4E4: nop

;}
RECOMP_FUNC void func_800AF5B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF5B0: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x800AF5B4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800AF5B8: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800AF5BC: jr          $ra
    // 0x800AF5C0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x800AF5C0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void _gccollectDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088010: syscall     666
    recomp_syscall_handler(rdram, ctx, 0x80088010);
    return;
    // 0x80088014: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801240_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801240: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801244: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80801248: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8080124C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801250: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x80801254: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x80801258: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x8080125C: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80801260: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80801264: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80801268: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8080126C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80801270: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80801274: jal         0x80105AE8
    // 0x80801278: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_80105AE8(rdram, ctx);
        goto after_0;
    // 0x80801278: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x8080127C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801284: jal         0x80100094
    // 0x80801288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080128C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801290: jal         0x800D7520
    // 0x80801294: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    func_800D7520(rdram, ctx);
        goto after_2;
    // 0x80801294: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_2:
    // 0x80801298: jal         0x800D8FF8
    // 0x8080129C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x8080129C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    after_3:
    // 0x808012A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3724) << 16);
    // 0x808012A4: lwc1        $f26, 0x3724($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3724));
    // 0x808012A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3728) << 16);
    // 0x808012AC: lwc1        $f24, 0x3728($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3728));
    // 0x808012B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808012B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808012B8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x808012BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808012C0: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_808012C4:
    // 0x808012C4: lbu         $t6, 0xF0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XF0);
    // 0x808012C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808012CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808012D0: bne         $t6, $at, L_80801358
    if (ctx->r14 != ctx->r1) {
        // 0x808012D4: lui         $a2, 0x437A
        ctx->r6 = S32(0X437A << 16);
            goto L_80801358;
    }
    // 0x808012D4: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    // 0x808012D8: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x808012DC: subu        $t8, $t8, $s3
    ctx->r24 = SUB32(ctx->r24, ctx->r19);
    // 0x808012E0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808012E4: addu        $s4, $s2, $t8
    ctx->r20 = ADD32(ctx->r18, ctx->r24);
    // 0x808012E8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808012EC: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x808012F0: addu        $s0, $s2, $t7
    ctx->r16 = ADD32(ctx->r18, ctx->r15);
    // 0x808012F4: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x808012F8: jal         0x800C7B7C
    // 0x808012FC: lw          $a1, 0xEC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XEC);
    func_800C7B7C(rdram, ctx);
        goto after_4;
    // 0x808012FC: lw          $a1, 0xEC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XEC);
    after_4:
    // 0x80801300: swc1        $f0, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f0.u32l;
    // 0x80801304: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    // 0x80801308: lw          $a1, 0xEC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XEC);
    // 0x8080130C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80801310: jal         0x800C7A68
    // 0x80801314: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800C7A68(rdram, ctx);
        goto after_5;
    // 0x80801314: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_5:
    // 0x80801318: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8080131C: sb          $t9, 0xF0($s1)
    MEM_B(0XF0, ctx->r17) = ctx->r25;
    // 0x80801320: lwc1        $f4, 0xDC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XDC);
    // 0x80801324: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X372C) << 16);
    // 0x80801328: swc1        $f4, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f4.u32l;
    // 0x8080132C: lwc1        $f6, 0xDC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XDC);
    // 0x80801330: lwc1        $f8, 0x372C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X372C));
    // 0x80801334: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801338: swc1        $f10, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->f10.u32l;
    // 0x8080133C: lwc1        $f16, 0xDC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XDC);
    // 0x80801340: c.lt.s      $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f24.fl < ctx->f16.fl;
    // 0x80801344: nop

    // 0x80801348: bc1fl       L_80801358
    if (!c1cs) {
        // 0x8080134C: sb          $zero, 0xE0($s1)
        MEM_B(0XE0, ctx->r17) = 0;
            goto L_80801358;
    }
    goto skip_0;
    // 0x8080134C: sb          $zero, 0xE0($s1)
    MEM_B(0XE0, ctx->r17) = 0;
    skip_0:
    // 0x80801350: swc1        $f26, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->f26.u32l;
    // 0x80801354: sb          $zero, 0xE0($s1)
    MEM_B(0XE0, ctx->r17) = 0;
L_80801358:
    // 0x80801358: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8080135C: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x80801360: bne         $at, $zero, L_808012C4
    if (ctx->r1 != 0) {
        // 0x80801364: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808012C4;
    }
    // 0x80801364: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801368: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8080136C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80801370: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80801374: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80801378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080137C:
    // 0x8080137C: lbu         $t0, 0xF0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XF0);
    // 0x80801380: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801384: bnel        $v1, $t0, L_80801424
    if (ctx->r3 != ctx->r8) {
        // 0x80801388: lbu         $t3, 0xF1($s1)
        ctx->r11 = MEM_BU(ctx->r17, 0XF1);
            goto L_80801424;
    }
    goto skip_1;
    // 0x80801388: lbu         $t3, 0xF1($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XF1);
    skip_1:
    // 0x8080138C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801390: lbu         $t2, 0xE0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0XE0);
    // 0x80801394: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80801398: mul.s       $f0, $f18, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8080139C: beq         $t2, $zero, L_808013CC
    if (ctx->r10 == 0) {
        // 0x808013A0: addu        $s0, $s2, $t1
        ctx->r16 = ADD32(ctx->r18, ctx->r9);
            goto L_808013CC;
    }
    // 0x808013A0: addu        $s0, $s2, $t1
    ctx->r16 = ADD32(ctx->r18, ctx->r9);
    // 0x808013A4: lwc1        $f4, 0xAC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x808013A8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808013AC: swc1        $f6, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f6.u32l;
    // 0x808013B0: lwc1        $f8, 0xAC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x808013B4: c.le.s      $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f8.fl <= ctx->f26.fl;
    // 0x808013B8: nop

    // 0x808013BC: bc1fl       L_808013F4
    if (!c1cs) {
        // 0x808013C0: lwc1        $f4, 0x84($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
            goto L_808013F4;
    }
    goto skip_2;
    // 0x808013C0: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    skip_2:
    // 0x808013C4: b           L_808013F0
    // 0x808013C8: sb          $zero, 0xE0($s1)
    MEM_B(0XE0, ctx->r17) = 0;
        goto L_808013F0;
    // 0x808013C8: sb          $zero, 0xE0($s1)
    MEM_B(0XE0, ctx->r17) = 0;
L_808013CC:
    // 0x808013CC: lwc1        $f10, 0xAC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x808013D0: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x808013D4: swc1        $f16, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f16.u32l;
    // 0x808013D8: lwc1        $f18, 0xAC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x808013DC: c.le.s      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.fl <= ctx->f18.fl;
    // 0x808013E0: nop

    // 0x808013E4: bc1fl       L_808013F4
    if (!c1cs) {
        // 0x808013E8: lwc1        $f4, 0x84($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
            goto L_808013F4;
    }
    goto skip_3;
    // 0x808013E8: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    skip_3:
    // 0x808013EC: sb          $v0, 0xE0($s1)
    MEM_B(0XE0, ctx->r17) = ctx->r2;
L_808013F0:
    // 0x808013F0: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
L_808013F4:
    // 0x808013F4: c.le.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl <= ctx->f20.fl;
    // 0x808013F8: nop

    // 0x808013FC: bc1fl       L_80801424
    if (!c1cs) {
        // 0x80801400: lbu         $t3, 0xF1($s1)
        ctx->r11 = MEM_BU(ctx->r17, 0XF1);
            goto L_80801424;
    }
    goto skip_4;
    // 0x80801400: lbu         $t3, 0xF1($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XF1);
    skip_4:
    // 0x80801404: c.le.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl <= ctx->f20.fl;
    // 0x80801408: nop

    // 0x8080140C: bc1fl       L_80801420
    if (!c1cs) {
        // 0x80801410: sb          $v0, 0xF0($s1)
        MEM_B(0XF0, ctx->r17) = ctx->r2;
            goto L_80801420;
    }
    goto skip_5;
    // 0x80801410: sb          $v0, 0xF0($s1)
    MEM_B(0XF0, ctx->r17) = ctx->r2;
    skip_5:
    // 0x80801414: b           L_80801420
    // 0x80801418: sb          $zero, 0xF0($s1)
    MEM_B(0XF0, ctx->r17) = 0;
        goto L_80801420;
    // 0x80801418: sb          $zero, 0xF0($s1)
    MEM_B(0XF0, ctx->r17) = 0;
    // 0x8080141C: sb          $v0, 0xF0($s1)
    MEM_B(0XF0, ctx->r17) = ctx->r2;
L_80801420:
    // 0x80801420: lbu         $t3, 0xF1($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XF1);
L_80801424:
    // 0x80801424: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801428: bnel        $v1, $t3, L_808014C8
    if (ctx->r3 != ctx->r11) {
        // 0x8080142C: addiu       $s3, $s3, 0x2
        ctx->r19 = ADD32(ctx->r19, 0X2);
            goto L_808014C8;
    }
    goto skip_6;
    // 0x8080142C: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    skip_6:
    // 0x80801430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801434: lbu         $t5, 0xE1($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0XE1);
    // 0x80801438: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x8080143C: mul.s       $f0, $f6, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x80801440: beq         $t5, $zero, L_80801470
    if (ctx->r13 == 0) {
        // 0x80801444: addu        $s0, $s2, $t4
        ctx->r16 = ADD32(ctx->r18, ctx->r12);
            goto L_80801470;
    }
    // 0x80801444: addu        $s0, $s2, $t4
    ctx->r16 = ADD32(ctx->r18, ctx->r12);
    // 0x80801448: lwc1        $f8, 0xB0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x8080144C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80801450: swc1        $f10, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f10.u32l;
    // 0x80801454: lwc1        $f16, 0xB0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x80801458: c.le.s      $f16, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f16.fl <= ctx->f26.fl;
    // 0x8080145C: nop

    // 0x80801460: bc1fl       L_80801498
    if (!c1cs) {
        // 0x80801464: lwc1        $f8, 0x88($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
            goto L_80801498;
    }
    goto skip_7;
    // 0x80801464: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    skip_7:
    // 0x80801468: b           L_80801494
    // 0x8080146C: sb          $zero, 0xE1($s1)
    MEM_B(0XE1, ctx->r17) = 0;
        goto L_80801494;
    // 0x8080146C: sb          $zero, 0xE1($s1)
    MEM_B(0XE1, ctx->r17) = 0;
L_80801470:
    // 0x80801470: lwc1        $f18, 0xB0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x80801474: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80801478: swc1        $f4, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f4.u32l;
    // 0x8080147C: lwc1        $f6, 0xB0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x80801480: c.le.s      $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f24.fl <= ctx->f6.fl;
    // 0x80801484: nop

    // 0x80801488: bc1fl       L_80801498
    if (!c1cs) {
        // 0x8080148C: lwc1        $f8, 0x88($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
            goto L_80801498;
    }
    goto skip_8;
    // 0x8080148C: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    skip_8:
    // 0x80801490: sb          $v0, 0xE1($s1)
    MEM_B(0XE1, ctx->r17) = ctx->r2;
L_80801494:
    // 0x80801494: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
L_80801498:
    // 0x80801498: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x8080149C: nop

    // 0x808014A0: bc1fl       L_808014C8
    if (!c1cs) {
        // 0x808014A4: addiu       $s3, $s3, 0x2
        ctx->r19 = ADD32(ctx->r19, 0X2);
            goto L_808014C8;
    }
    goto skip_9;
    // 0x808014A4: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    skip_9:
    // 0x808014A8: c.le.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl <= ctx->f20.fl;
    // 0x808014AC: nop

    // 0x808014B0: bc1fl       L_808014C4
    if (!c1cs) {
        // 0x808014B4: sb          $v0, 0xF1($s1)
        MEM_B(0XF1, ctx->r17) = ctx->r2;
            goto L_808014C4;
    }
    goto skip_10;
    // 0x808014B4: sb          $v0, 0xF1($s1)
    MEM_B(0XF1, ctx->r17) = ctx->r2;
    skip_10:
    // 0x808014B8: b           L_808014C4
    // 0x808014BC: sb          $zero, 0xF1($s1)
    MEM_B(0XF1, ctx->r17) = 0;
        goto L_808014C4;
    // 0x808014BC: sb          $zero, 0xF1($s1)
    MEM_B(0XF1, ctx->r17) = 0;
    // 0x808014C0: sb          $v0, 0xF1($s1)
    MEM_B(0XF1, ctx->r17) = ctx->r2;
L_808014C4:
    // 0x808014C4: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
L_808014C8:
    // 0x808014C8: bne         $s3, $a0, L_8080137C
    if (ctx->r19 != ctx->r4) {
        // 0x808014CC: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8080137C;
    }
    // 0x808014CC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x808014D0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x808014D4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808014D8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808014DC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x808014E0: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x808014E4: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x808014E8: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808014EC: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808014F0: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x808014F4: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x808014F8: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x808014FC: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x80801500: jr          $ra
    // 0x80801504: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80801504: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800F53E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F53E4: bltz        $a0, L_800F5404
    if (SIGNED(ctx->r4) < 0) {
        // 0x800F53E8: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800F5404;
    }
    // 0x800F53E8: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800F53EC: beq         $at, $zero, L_800F5404
    if (ctx->r1 == 0) {
        // 0x800F53F0: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800F5404;
    }
    // 0x800F53F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F53F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F53F8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800F53FC: jr          $ra
    // 0x800F5400: lw          $v0, 0x5490($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5490);
    return;
    // 0x800F5400: lw          $v0, 0x5490($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5490);
L_800F5404:
    // 0x800F5404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5408: jr          $ra
    // 0x800F540C: nop

    return;
    // 0x800F540C: nop

;}
RECOMP_FUNC void func_8010D290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D290: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010D294: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010D298: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8010D29C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8010D2A0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8010D2A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010D2A8: jal         0x800F54E4
    // 0x8010D2AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8010D2AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8010D2B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010D2B4: bne         $v0, $at, L_8010D2C4
    if (ctx->r2 != ctx->r1) {
        // 0x8010D2B8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8010D2C4;
    }
    // 0x8010D2B8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8010D2BC: b           L_8010D334
    // 0x8010D2C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8010D334;
    // 0x8010D2C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8010D2C4:
    // 0x8010D2C4: jal         0x800F6438
    // 0x8010D2C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x8010D2C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8010D2CC: beq         $v0, $zero, L_8010D2EC
    if (ctx->r2 == 0) {
        // 0x8010D2D0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8010D2EC;
    }
    // 0x8010D2D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010D2D4: jal         0x800F64A4
    // 0x8010D2D8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F64A4(rdram, ctx);
        goto after_2;
    // 0x8010D2D8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x8010D2DC: bnel        $v0, $zero, L_8010D2F0
    if (ctx->r2 != 0) {
        // 0x8010D2E0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8010D2F0;
    }
    goto skip_0;
    // 0x8010D2E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x8010D2E4: b           L_8010D334
    // 0x8010D2E8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_8010D334;
    // 0x8010D2E8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8010D2EC:
    // 0x8010D2EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8010D2F0:
    // 0x8010D2F0: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_8010D2F4:
    // 0x8010D2F4: beql        $s0, $s2, L_8010D328
    if (ctx->r16 == ctx->r18) {
        // 0x8010D2F8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8010D328;
    }
    goto skip_1;
    // 0x8010D2F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8010D2FC: jal         0x800F6438
    // 0x8010D300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_3;
    // 0x8010D300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010D304: beq         $v0, $zero, L_8010D324
    if (ctx->r2 == 0) {
        // 0x8010D308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010D324;
    }
    // 0x8010D308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010D30C: jal         0x800F64A4
    // 0x8010D310: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F64A4(rdram, ctx);
        goto after_4;
    // 0x8010D310: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x8010D314: bnel        $v0, $zero, L_8010D328
    if (ctx->r2 != 0) {
        // 0x8010D318: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8010D328;
    }
    goto skip_2;
    // 0x8010D318: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8010D31C: b           L_8010D334
    // 0x8010D320: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8010D334;
    // 0x8010D320: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8010D324:
    // 0x8010D324: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8010D328:
    // 0x8010D328: bne         $s0, $s1, L_8010D2F4
    if (ctx->r16 != ctx->r17) {
        // 0x8010D32C: nop
    
            goto L_8010D2F4;
    }
    // 0x8010D32C: nop

    // 0x8010D330: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8010D334:
    // 0x8010D334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010D338: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010D33C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010D340: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8010D344: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8010D348: jr          $ra
    // 0x8010D34C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8010D34C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chghostdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(984, 0X220) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x220
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(984, 0X220));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x220
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(984, 0X220));
;}
RECOMP_FUNC void func_808017F0_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808017F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808017F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808017FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801800: jal         0x80100094
    // 0x80801804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801808: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080180C: jal         0x80101F24
    // 0x80801810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_1;
    // 0x80801810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801814: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A78) << 16);
    // 0x80801818: lwc1        $f4, 0x2A78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A78));
    // 0x8080181C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A7C) << 16);
    // 0x80801820: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801824: nop

    // 0x80801828: bc1fl       L_8080186C
    if (!c1cs) {
        // 0x8080182C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080186C;
    }
    goto skip_0;
    // 0x8080182C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801830: jal         0x800DC298
    // 0x80801834: lwc1        $f12, 0x2A7C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A7C));
    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x80801834: lwc1        $f12, 0x2A7C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A7C));
    after_2:
    // 0x80801838: beq         $v0, $zero, L_80801868
    if (ctx->r2 == 0) {
        // 0x8080183C: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80801868;
    }
    // 0x8080183C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801840: jal         0x800EE7F8
    // 0x80801844: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80801844: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80801848: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080184C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801850: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801858: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8080185C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801860: jal         0x80801B00
    // 0x80801864: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    func_80801B00_chboilerboss(rdram, ctx);
        goto after_4;
    // 0x80801864: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_4:
L_80801868:
    // 0x80801868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080186C:
    // 0x8080186C: jal         0x80101E14
    // 0x80801870: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x80801870: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80801874: beq         $v0, $zero, L_808018B0
    if (ctx->r2 == 0) {
        // 0x80801878: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_808018B0;
    }
    // 0x80801878: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8080187C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801880: jal         0x800EE7F8
    // 0x80801884: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80801884: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_6:
    // 0x80801888: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8080188C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801890: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801894: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080189C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808018A0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x808018A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808018A8: jal         0x80801A74
    // 0x808018AC: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    func_80801A74_chboilerboss(rdram, ctx);
        goto after_7;
    // 0x808018AC: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_7:
L_808018B0:
    // 0x808018B0: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x808018B4: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808018B8: jal         0x80101E14
    // 0x808018BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x808018BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808018C0: beq         $v0, $zero, L_80801910
    if (ctx->r2 == 0) {
        // 0x808018C4: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_80801910;
    }
    // 0x808018C4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808018C8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808018CC: jal         0x800EE7F8
    // 0x808018D0: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x808018D0: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_9:
    // 0x808018D4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808018D8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808018DC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808018E0: jal         0x800EE7F8
    // 0x808018E4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x808018E4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x808018E8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808018EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808018F0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808018F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018F8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808018FC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80801900: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80801904: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801908: jal         0x80801A74
    // 0x8080190C: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    func_80801A74_chboilerboss(rdram, ctx);
        goto after_11;
    // 0x8080190C: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    after_11:
L_80801910:
    // 0x80801910: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80801914: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801918: jal         0x80101E14
    // 0x8080191C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_12;
    // 0x8080191C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801920: beq         $v0, $zero, L_80801970
    if (ctx->r2 == 0) {
        // 0x80801924: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_80801970;
    }
    // 0x80801924: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80801928: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080192C: jal         0x800EE7F8
    // 0x80801930: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x80801930: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_13:
    // 0x80801934: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801938: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8080193C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80801940: jal         0x800EE7F8
    // 0x80801944: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x80801944: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x80801948: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080194C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801950: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801958: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080195C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801960: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80801964: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801968: jal         0x80801A74
    // 0x8080196C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    func_80801A74_chboilerboss(rdram, ctx);
        goto after_15;
    // 0x8080196C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_15:
L_80801970:
    // 0x80801970: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80801974: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801978: jal         0x80101E14
    // 0x8080197C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_16;
    // 0x8080197C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801980: beq         $v0, $zero, L_808019B4
    if (ctx->r2 == 0) {
        // 0x80801984: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_808019B4;
    }
    // 0x80801984: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80801988: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080198C: jal         0x800EE7F8
    // 0x80801990: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x80801990: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_17:
    // 0x80801994: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80801998: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080199C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808019A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808019A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808019AC: jal         0x80801B44
    // 0x808019B0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    func_80801B44_chboilerboss(rdram, ctx);
        goto after_18;
    // 0x808019B0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_18:
L_808019B4:
    // 0x808019B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808019B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808019BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808019C0: jr          $ra
    // 0x808019C4: nop

    return;
    // 0x808019C4: nop

;}
RECOMP_FUNC void func_8009D3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D3D0: jr          $ra
    // 0x8009D3D4: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x8009D3D4: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _bsbswim_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B98: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B98);
    return;
    // 0x80082B9C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void babee_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x808001EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001F0: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808001F4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808001F8: nop

    // 0x808001FC: bc1tl       L_80800260
    if (c1cs) {
        // 0x80800200: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800260;
    }
    goto skip_0;
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800204: lbu         $t6, 0x1C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1C);
    // 0x80800208: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8080020C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800210: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800214: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800218: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8080021C: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80800220: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800224: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x80800228: jal         0x8009C128
    // 0x8080022C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080022C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800230: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(459, 0X3BC) << 16);
    // 0x80800234: addiu       $a3, $a3, 0x3BC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(459, 0X3BC));
    // 0x80800238: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8080023C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800240: jal         0x8010D930
    // 0x80800244: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8010D930(rdram, ctx);
        goto after_1;
    // 0x80800244: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80800248: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8080024C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800250: addiu       $a0, $a0, 0x4548
    ctx->r4 = ADD32(ctx->r4, 0X4548);
    // 0x80800254: jal         0x80086D30
    // 0x80800258: lw          $a1, 0x184($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X184);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800258: lw          $a1, 0x184($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X184);
    after_2:
    // 0x8080025C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800260:
    // 0x80800260: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800264: jr          $ra
    // 0x80800268: nop

    return;
    // 0x80800268: nop

;}
RECOMP_FUNC void func_800DF83C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF83C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF840: jr          $ra
    // 0x800DF844: sw          $a0, -0x37B8($at)
    MEM_W(-0X37B8, ctx->r1) = ctx->r4;
    return;
    // 0x800DF844: sw          $a0, -0x37B8($at)
    MEM_W(-0X37B8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800000_glcrc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800004: lui         $t6, 0x8F80
    ctx->r14 = S32(0X8F80 << 16);
    // 0x80800008: lui         $t7, 0x3108
    ctx->r15 = S32(0X3108 << 16);
    // 0x8080000C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800010: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800014: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800018: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080001C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800020: ori         $t7, $t7, 0xB3C1
    ctx->r15 = ctx->r15 | 0XB3C1;
    // 0x80800024: ori         $t6, $t6, 0x9F47
    ctx->r14 = ctx->r14 | 0X9F47;
    // 0x80800028: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8080002C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80800030: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800038: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8080003C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800040: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800044: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80800048: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8080004C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800050: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800054: beq         $at, $zero, L_808000B0
    if (ctx->r1 == 0) {
        // 0x80800058: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_808000B0;
    }
    // 0x80800058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080005C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800060: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
L_80800064:
    // 0x80800064: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80800068: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8080006C: andi        $t9, $s1, 0xF
    ctx->r25 = ctx->r17 & 0XF;
    // 0x80800070: sllv        $t0, $t8, $t9
    ctx->r8 = S32(ctx->r24 << (ctx->r25 & 31));
    // 0x80800074: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80800078: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x8080007C: sra         $t2, $t0, 31
    ctx->r10 = S32(SIGNED(ctx->r8) >> 31);
    // 0x80800080: sltu        $at, $t7, $t5
    ctx->r1 = ctx->r15 < ctx->r13 ? 1 : 0;
    // 0x80800084: addu        $t6, $at, $t2
    ctx->r14 = ADD32(ctx->r1, ctx->r10);
    // 0x80800088: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8080008C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80800090: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80800094: jal         0x801168AC
    // 0x80800098: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801168AC(rdram, ctx);
        goto after_0;
    // 0x80800098: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8080009C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808000A0: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x808000A4: bne         $s0, $s5, L_80800064
    if (ctx->r16 != ctx->r21) {
        // 0x808000A8: xor         $s3, $s3, $v0
        ctx->r19 = ctx->r19 ^ ctx->r2;
            goto L_80800064;
    }
    // 0x808000A8: xor         $s3, $s3, $v0
    ctx->r19 = ctx->r19 ^ ctx->r2;
    // 0x808000AC: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
L_808000B0:
    // 0x808000B0: addiu       $s0, $s5, -0x1
    ctx->r16 = ADD32(ctx->r21, -0X1);
    // 0x808000B4: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x808000B8: bne         $at, $zero, L_8080010C
    if (ctx->r1 != 0) {
        // 0x808000BC: addiu       $s2, $sp, 0x48
        ctx->r18 = ADD32(ctx->r29, 0X48);
            goto L_8080010C;
    }
    // 0x808000BC: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
    // 0x808000C0: addiu       $s5, $a3, -0x1
    ctx->r21 = ADD32(ctx->r7, -0X1);
L_808000C4:
    // 0x808000C4: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x808000C8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x808000CC: andi        $t8, $s1, 0xF
    ctx->r24 = ctx->r17 & 0XF;
    // 0x808000D0: sllv        $t9, $t1, $t8
    ctx->r25 = S32(ctx->r9 << (ctx->r24 & 31));
    // 0x808000D4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x808000D8: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x808000DC: sra         $t0, $t9, 31
    ctx->r8 = S32(SIGNED(ctx->r25) >> 31);
    // 0x808000E0: sltu        $at, $t5, $t3
    ctx->r1 = ctx->r13 < ctx->r11 ? 1 : 0;
    // 0x808000E4: addu        $t4, $at, $t0
    ctx->r12 = ADD32(ctx->r1, ctx->r8);
    // 0x808000E8: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x808000EC: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x808000F0: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x808000F4: jal         0x801168AC
    // 0x808000F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801168AC(rdram, ctx);
        goto after_1;
    // 0x808000F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x808000FC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80800100: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x80800104: bne         $s0, $s5, L_808000C4
    if (ctx->r16 != ctx->r21) {
        // 0x80800108: xor         $s4, $s4, $v0
        ctx->r20 = ctx->r20 ^ ctx->r2;
            goto L_808000C4;
    }
    // 0x80800108: xor         $s4, $s4, $v0
    ctx->r20 = ctx->r20 ^ ctx->r2;
L_8080010C:
    // 0x8080010C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80800110: sw          $s3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r19;
    // 0x80800114: sw          $s4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r20;
    // 0x80800118: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080011C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800120: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800124: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800128: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080012C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800130: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: jr          $ra
    // 0x80800138: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800138: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800EBC_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800EC8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800ECC: jal         0x80800630
    // 0x80800ED0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_80800630_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x80800ED0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800ED4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800ED8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800EDC: jal         0x80800654
    // 0x80800EE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80800654_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x80800EE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800EE4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800EE8: addiu       $a0, $v0, -0x18
    ctx->r4 = ADD32(ctx->r2, -0X18);
    // 0x80800EEC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800EF0: sltu        $at, $a0, $a3
    ctx->r1 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x80800EF4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EF8: bne         $at, $zero, L_80800F2C
    if (ctx->r1 != 0) {
        // 0x80800EFC: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80800F2C;
    }
    // 0x80800EFC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F00: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80800F04: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800F08: bgez        $t8, L_80800F2C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800F0C: addiu       $v1, $v1, -0x18
        ctx->r3 = ADD32(ctx->r3, -0X18);
            goto L_80800F2C;
    }
    // 0x80800F0C: addiu       $v1, $v1, -0x18
    ctx->r3 = ADD32(ctx->r3, -0X18);
L_80800F10:
    // 0x80800F10: sltu        $at, $v1, $a3
    ctx->r1 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x80800F14: bne         $at, $zero, L_80800F2C
    if (ctx->r1 != 0) {
        // 0x80800F18: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80800F2C;
    }
    // 0x80800F18: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80800F1C: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x80800F20: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x80800F24: bltzl       $t1, L_80800F10
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800F28: addiu       $v1, $v1, -0x18
        ctx->r3 = ADD32(ctx->r3, -0X18);
            goto L_80800F10;
    }
    goto skip_0;
    // 0x80800F28: addiu       $v1, $v1, -0x18
    ctx->r3 = ADD32(ctx->r3, -0X18);
    skip_0:
L_80800F2C:
    // 0x80800F2C: lh          $t2, 0x1A($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X1A);
    // 0x80800F30: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800F34: lui         $at, 0x7F
    ctx->r1 = S32(0X7F << 16);
    // 0x80800F38: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80800F3C: subu        $t3, $t2, $a2
    ctx->r11 = SUB32(ctx->r10, ctx->r6);
    // 0x80800F40: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80800F44: srl         $t5, $v0, 9
    ctx->r13 = S32(U32(ctx->r2) >> 9);
    // 0x80800F48: xor         $t6, $t4, $t5
    ctx->r14 = ctx->r12 ^ ctx->r13;
    // 0x80800F4C: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x80800F50: xor         $t8, $t7, $v0
    ctx->r24 = ctx->r15 ^ ctx->r2;
    // 0x80800F54: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80800F58: sb          $a2, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r6;
    // 0x80800F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F64: jr          $ra
    // 0x80800F68: nop

    return;
    // 0x80800F68: nop

;}
RECOMP_FUNC void func_8010D640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010D644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D648: jal         0x8010D23C
    // 0x8010D64C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010D23C(rdram, ctx);
        goto after_0;
    // 0x8010D64C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010D650: beq         $v0, $zero, L_8010D678
    if (ctx->r2 == 0) {
        // 0x8010D654: nop
    
            goto L_8010D678;
    }
    // 0x8010D654: nop

    // 0x8010D658: jal         0x800DB9B0
    // 0x8010D65C: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x8010D65C: nop

    after_1:
    // 0x8010D660: bne         $v0, $zero, L_8010D678
    if (ctx->r2 != 0) {
        // 0x8010D664: nop
    
            goto L_8010D678;
    }
    // 0x8010D664: nop

    // 0x8010D668: jal         0x8008FE68
    // 0x8010D66C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008FE68(rdram, ctx);
        goto after_2;
    // 0x8010D66C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8010D670: b           L_8010D684
    // 0x8010D674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010D684;
    // 0x8010D674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010D678:
    // 0x8010D678: jal         0x800E3980
    // 0x8010D67C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800E3980(rdram, ctx);
        goto after_3;
    // 0x8010D67C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8010D680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010D684:
    // 0x8010D684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010D688: jr          $ra
    // 0x8010D68C: nop

    return;
    // 0x8010D68C: nop

;}
RECOMP_FUNC void func_808005E8_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005F0: jal         0x80800174
    // 0x808005F4: nop

    func_80800174_bsvanswim(rdram, ctx);
        goto after_0;
    // 0x808005F4: nop

    after_0:
    // 0x808005F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800600: jr          $ra
    // 0x80800604: nop

    return;
    // 0x80800604: nop

;}
RECOMP_FUNC void func_8080012C_chquizexitdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800130: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: bne         $a1, $at, L_8080016C
    if (ctx->r5 != ctx->r1) {
        // 0x8080013C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080016C;
    }
    // 0x8080013C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800140: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800144: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800148: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080014C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80800150: jal         0x80101FDC
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: jal         0x80103110
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800164: b           L_80800170
    // 0x80800168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800170;
    // 0x80800168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080016C:
    // 0x8080016C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800170:
    // 0x80800170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void ncpod_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800CD8: jal         0x800895D0
    // 0x80800CDC: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    _ncpoddialog_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800CDC: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    after_0:
    // 0x80800CE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CE4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CE8: jal         0x800895F0
    // 0x80800CEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _ncpoddialog_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800CEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CF8: jr          $ra
    // 0x80800CFC: nop

    return;
    // 0x80800CFC: nop

;}
RECOMP_FUNC void _gcsectionskip_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AD8: syscall     653
    recomp_syscall_handler(rdram, ctx, 0x80087AD8);
    return;
    // 0x80087ADC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800AF5FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF5FC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800AF600: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800AF604: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AF608: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800AF60C: jr          $ra
    // 0x800AF610: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    return;
    // 0x800AF610: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
;}
RECOMP_FUNC void func_800EE780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE780: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EE784: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE788: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EE78C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800EE790: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EE794: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EE798: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EE79C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800EE7A0: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EE7A4: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EE7A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EE7AC: jr          $ra
    // 0x800EE7B0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800EE7B0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800D3D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D58: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D3D5C: addiu       $v1, $v1, -0x4C10
    ctx->r3 = ADD32(ctx->r3, -0X4C10);
    // 0x800D3D60: lbu         $v0, 0x9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X9);
    // 0x800D3D64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D3D68: beq         $v0, $at, L_800D3D80
    if (ctx->r2 == ctx->r1) {
        // 0x800D3D6C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800D3D80;
    }
    // 0x800D3D6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D3D70: beq         $v0, $at, L_800D3D8C
    if (ctx->r2 == ctx->r1) {
        // 0x800D3D74: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_800D3D8C;
    }
    // 0x800D3D74: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800D3D78: b           L_800D3D9C
    // 0x800D3D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3D9C;
    // 0x800D3D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3D80:
    // 0x800D3D80: sb          $zero, 0x9($v1)
    MEM_B(0X9, ctx->r3) = 0;
    // 0x800D3D84: jr          $ra
    // 0x800D3D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800D3D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D3D8C:
    // 0x800D3D8C: sb          $t6, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r14;
    // 0x800D3D90: jr          $ra
    // 0x800D3D94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800D3D94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D3D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3D9C:
    // 0x800D3D9C: jr          $ra
    // 0x800D3DA0: nop

    return;
    // 0x800D3DA0: nop

;}
RECOMP_FUNC void func_80015184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015184: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015188: jr          $ra
    // 0x8001518C: lw          $v0, -0x6EC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6EC4);
    return;
    // 0x8001518C: lw          $v0, -0x6EC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6EC4);
;}
RECOMP_FUNC void func_8001268C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001268C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80012690: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80012694: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80012698: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8001269C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800126A0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800126A4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800126A8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800126AC: addiu       $a1, $a1, -0x6B60
    ctx->r5 = ADD32(ctx->r5, -0X6B60);
    // 0x800126B0: addiu       $a0, $a0, -0x6B78
    ctx->r4 = ADD32(ctx->r4, -0X6B78);
    // 0x800126B4: jal         0x8002E070
    // 0x800126B8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800126B8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_0:
    // 0x800126BC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800126C0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800126C4: addiu       $a1, $a1, 0x5C08
    ctx->r5 = ADD32(ctx->r5, 0X5C08);
    // 0x800126C8: addiu       $a0, $a0, 0x5BF0
    ctx->r4 = ADD32(ctx->r4, 0X5BF0);
    // 0x800126CC: jal         0x8002E070
    // 0x800126D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800126D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800126D4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800126D8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800126DC: addiu       $a1, $a1, 0x5BD0
    ctx->r5 = ADD32(ctx->r5, 0X5BD0);
    // 0x800126E0: addiu       $a0, $a0, 0x5BB8
    ctx->r4 = ADD32(ctx->r4, 0X5BB8);
    // 0x800126E4: jal         0x8002E070
    // 0x800126E8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x800126E8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800126EC: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x800126F0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800126F4: addiu       $s3, $s3, -0x5E58
    ctx->r19 = ADD32(ctx->r19, -0X5E58);
    // 0x800126F8: sb          $zero, -0x5E2E($at)
    MEM_B(-0X5E2E, ctx->r1) = 0;
    // 0x800126FC: lui         $t8, 0x8001
    ctx->r24 = S32(0X8001 << 16);
    // 0x80012700: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80012704: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80012708: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x8001270C: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80012710: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80012714: addiu       $t8, $t8, 0x2D4C
    ctx->r24 = ADD32(ctx->r24, 0X2D4C);
    // 0x80012718: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8001271C: addiu       $t0, $t0, -0x35BC
    ctx->r8 = ADD32(ctx->r8, -0X35BC);
    // 0x80012720: addiu       $t1, $t1, 0x6A78
    ctx->r9 = ADD32(ctx->r9, 0X6A78);
    // 0x80012724: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80012728: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x8001272C: sw          $t6, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r14;
    // 0x80012730: sw          $t7, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r15;
    // 0x80012734: sw          $t8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r24;
    // 0x80012738: sb          $t9, 0x1C($s3)
    MEM_B(0X1C, ctx->r19) = ctx->r25;
    // 0x8001273C: sw          $t0, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r8;
    // 0x80012740: sw          $t1, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r9;
    // 0x80012744: jal         0x8002E0A0
    // 0x80012748: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_3;
    // 0x80012748: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    after_3:
    tooie_mix_rate_frequency(rdram, ctx);
    // 0x8001274C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80012750: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
    // 0x80012754: addiu       $a0, $a0, -0x5EA8
    ctx->r4 = ADD32(ctx->r4, -0X5EA8);
    // 0x80012758: jal         0x80020D80
    // 0x8001275C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80020D80(rdram, ctx);
        goto after_4;
    // 0x8001275C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x80012760: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80012764: addiu       $v0, $v0, -0x65C0
    ctx->r2 = ADD32(ctx->r2, -0X65C0);
    // 0x80012768: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x8001276C: lui         $s0, 0x8007
    ctx->r16 = S32(0X8007 << 16);
    // 0x80012770: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80012774: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80012778: addiu       $s0, $s0, -0x65AC
    ctx->r16 = ADD32(ctx->r16, -0X65AC);
    // 0x8001277C: addiu       $s1, $s1, -0x65C0
    ctx->r17 = ADD32(ctx->r17, -0X65C0);
    // 0x80012780: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80012784:
    // 0x80012784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80012788: jal         0x80020E40
    // 0x8001278C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80020E40(rdram, ctx);
        goto after_5;
    // 0x8001278C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80012790: addiu       $t2, $zero, 0x200
    ctx->r10 = ADD32(0, 0X200);
    // 0x80012794: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80012798: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001279C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800127A0: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x800127A4: jal         0x80020EE4
    // 0x800127A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_6;
    // 0x800127A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x800127AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800127B0: slti        $at, $s2, 0x59
    ctx->r1 = SIGNED(ctx->r18) < 0X59 ? 1 : 0;
    // 0x800127B4: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x800127B8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800127BC: bne         $at, $zero, L_80012784
    if (ctx->r1 != 0) {
        // 0x800127C0: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_80012784;
    }
    // 0x800127C0: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x800127C4: addiu       $t3, $zero, 0x200
    ctx->r11 = ADD32(0, 0X200);
    // 0x800127C8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800127CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800127D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800127D4: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x800127D8: jal         0x80020EE4
    // 0x800127DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_7;
    // 0x800127DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x800127E0: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x800127E4: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800127E8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800127EC: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x800127F0: addiu       $v1, $v1, -0x5E28
    ctx->r3 = ADD32(ctx->r3, -0X5E28);
    // 0x800127F4: addiu       $s0, $s0, 0x59E0
    ctx->r16 = ADD32(ctx->r16, 0X59E0);
    // 0x800127F8: addiu       $v0, $v0, 0x3E18
    ctx->r2 = ADD32(ctx->r2, 0X3E18);
L_800127FC:
    // 0x800127FC: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x80012800: addiu       $v1, $v1, 0x4E20
    ctx->r3 = ADD32(ctx->r3, 0X4E20);
    // 0x80012804: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80012808: bne         $at, $zero, L_800127FC
    if (ctx->r1 != 0) {
        // 0x8001280C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800127FC;
    }
    // 0x8001280C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80012810: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80012814: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x80012818: lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // 0x8001281C: addiu       $s2, $s2, 0x6938
    ctx->r18 = ADD32(ctx->r18, 0X6938);
    // 0x80012820: addiu       $s1, $s1, 0x3E18
    ctx->r17 = ADD32(ctx->r17, 0X3E18);
    // 0x80012824: addiu       $s0, $s0, 0x59E0
    ctx->r16 = ADD32(ctx->r16, 0X59E0);
    // 0x80012828: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
L_8001282C:
    // 0x8001282C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80012830: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012838: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8001283C: jal         0x80020EE4
    // 0x80012840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_8;
    // 0x80012840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80012844: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80012848: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8001284C: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80012850: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80012854: sw          $v1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r3;
    // 0x80012858: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x8001285C: sw          $s1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r17;
    // 0x80012860: addiu       $s1, $s1, 0xE60
    ctx->r17 = ADD32(ctx->r17, 0XE60);
    // 0x80012864: bnel        $s1, $s2, L_8001282C
    if (ctx->r17 != ctx->r18) {
        // 0x80012868: addiu       $t4, $zero, 0x10
        ctx->r12 = ADD32(0, 0X10);
            goto L_8001282C;
    }
    goto skip_0;
    // 0x80012868: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    skip_0:
    tooie_mix_rate_buffers(rdram, ctx);
    // 0x8001286C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80012870: addiu       $t6, $t6, 0x6A78
    ctx->r14 = ADD32(ctx->r14, 0X6A78);
    // 0x80012874: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80012878: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8001287C: lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // 0x80012880: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80012884: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80012888: addiu       $a3, $a3, 0x28C0
    ctx->r7 = ADD32(ctx->r7, 0X28C0);
    // 0x8001288C: addiu       $a1, $a1, 0x5BA8
    ctx->r5 = ADD32(ctx->r5, 0X5BA8);
    // 0x80012890: addiu       $a0, $a0, 0x59F8
    ctx->r4 = ADD32(ctx->r4, 0X59F8);
    // 0x80012894: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80012898: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8001289C: jal         0x8001DCB0
    // 0x800128A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001DCB0(rdram, ctx);
        goto after_9;
    // 0x800128A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x800128A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800128A8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800128AC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800128B0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800128B4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800128B8: jr          $ra
    // 0x800128BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800128BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _suexpression_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897E8: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897E8);
    return;
    // 0x800897EC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_800D3D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D3D20: jr          $ra
    // 0x800D3D24: lbu         $v0, -0x4C0B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4C0B);
    return;
    // 0x800D3D24: lbu         $v0, -0x4C0B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4C0B);
;}
RECOMP_FUNC void subaddiefind_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800390: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800394: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800398: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080039C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808003A0: addiu       $s4, $sp, 0x38
    ctx->r20 = ADD32(ctx->r29, 0X38);
    // 0x808003A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808003A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808003AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808003B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003B4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808003B8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x808003BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808003C0: jal         0x801067C4
    // 0x808003C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x808003C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x808003C8: beql        $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x808003CC: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_80800420;
    }
    goto skip_0;
    // 0x808003CC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    skip_0:
    // 0x808003D0: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
L_808003D4:
    // 0x808003D4: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x808003D8: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x808003DC: bne         $s2, $t8, L_8080040C
    if (ctx->r18 != ctx->r24) {
        // 0x808003E0: nop
    
            goto L_8080040C;
    }
    // 0x808003E0: nop

    // 0x808003E4: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x808003E8: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x808003EC: bltz        $t1, L_8080040C
    if (SIGNED(ctx->r9) < 0) {
        // 0x808003F0: nop
    
            goto L_8080040C;
    }
    // 0x808003F0: nop

    // 0x808003F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808003F8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x808003FC: bne         $s1, $s3, L_8080040C
    if (ctx->r17 != ctx->r19) {
        // 0x80800400: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080040C;
    }
    // 0x80800400: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800404: b           L_80800420
    // 0x80800408: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80800420;
    // 0x80800408: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8080040C:
    // 0x8080040C: jal         0x8010682C
    // 0x80800410: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8010682C(rdram, ctx);
        goto after_1;
    // 0x80800410: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80800414: bnel        $v0, $zero, L_808003D4
    if (ctx->r2 != 0) {
        // 0x80800418: lw          $t6, 0x6C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X6C);
            goto L_808003D4;
    }
    goto skip_1;
    // 0x80800418: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    skip_1:
    // 0x8080041C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80800420:
    // 0x80800420: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800424: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800428: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080042C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800430: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800434: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800438: jr          $ra
    // 0x8080043C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080043C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bskazshoessuckspline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080042C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800430: jal         0x80800110
    // 0x80800434: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800110_bskazshoessuckspline(rdram, ctx);
        goto after_0;
    // 0x80800434: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800438: jal         0x800832E8
    // 0x8080043C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080043C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800448: jr          $ra
    // 0x8080044C: nop

    return;
    // 0x8080044C: nop

;}
RECOMP_FUNC void bsbansack_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004F8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1E10) << 16);
    // 0x808004FC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800500: jr          $ra
    // 0x80800504: lw          $v0, 0x1E10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E10));
    return;
    // 0x80800504: lw          $v0, 0x1E10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E10));
;}
RECOMP_FUNC void func_800E0AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0AFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E0B00: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800E0B04: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x800E0B08: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800E0B0C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800E0B10: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800E0B14: beq         $at, $zero, L_800E0B84
    if (ctx->r1 == 0) {
        // 0x800E0B18: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_800E0B84;
    }
    // 0x800E0B18: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800E0B1C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800E0B20: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800E0B24: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800E0B28: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E0B2C: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x800E0B30: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x800E0B34: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800E0B38: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x800E0B3C: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
    // 0x800E0B40: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800E0B44: sra         $t1, $t6, 5
    ctx->r9 = S32(SIGNED(ctx->r14) >> 5);
    // 0x800E0B48: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800E0B4C: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x800E0B50: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800E0B54: sb          $zero, 0x11($v1)
    MEM_B(0X11, ctx->r3) = 0;
    // 0x800E0B58: sb          $t6, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r14;
    // 0x800E0B5C: addu        $a3, $a0, $t2
    ctx->r7 = ADD32(ctx->r4, ctx->r10);
    // 0x800E0B60: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800E0B64: lw          $t3, 0x10($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X10);
    // 0x800E0B68: andi        $t4, $t6, 0x1F
    ctx->r12 = ctx->r14 & 0X1F;
    // 0x800E0B6C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800E0B70: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x800E0B74: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800E0B78: sw          $t7, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r15;
    // 0x800E0B7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800E0B80: sb          $t8, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r24;
L_800E0B84:
    // 0x800E0B84: jr          $ra
    // 0x800E0B88: nop

    return;
    // 0x800E0B88: nop

;}
RECOMP_FUNC void _subaddieaudioloop_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D60: syscall     810
    recomp_syscall_handler(rdram, ctx, 0x80089D60);
    return;
    // 0x80089D64: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800434_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080043C: jal         0x80800400
    // 0x80800440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800400_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80800440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800444: jal         0x80800238
    // 0x80800448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800238_bsbansack(rdram, ctx);
        goto after_1;
    // 0x80800448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080044C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800454: jr          $ra
    // 0x80800458: nop

    return;
    // 0x80800458: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D80: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D80);
    return;
    // 0x80087D84: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void _chfactorymagnet_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874D8: syscall     579
    recomp_syscall_handler(rdram, ctx, 0x800874D8);
    return;
    // 0x800874DC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800966E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800966E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800966E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800966E8: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800966EC: jal         0x800C67E8
    // 0x800966F0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C67E8(rdram, ctx);
        goto after_0;
    // 0x800966F0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800966F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800966F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800966FC: jr          $ra
    // 0x80096700: nop

    return;
    // 0x80096700: nop

;}
RECOMP_FUNC void _sumultiscore_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899A8: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x800899A8);
    return;
    // 0x800899AC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80801BC4_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801BC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801BCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801BD0: jal         0x80101080
    // 0x80801BD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80801BD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801BD8: jal         0x80106790
    // 0x80801BDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801BDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801BE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801BE8: jal         0x800866A0
    // 0x80801BEC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80801BEC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80801BF0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801BF4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801BF8: jal         0x8010114C
    // 0x80801BFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_3;
    // 0x80801BFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80801C00: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X2284) << 16);
    // 0x80801C04: addiu       $a2, $a2, 0x2284
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1324, 0X2284));
    // 0x80801C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C0C: jal         0x80089D18
    // 0x80801C10: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80801C10: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80801C14: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80801C18: beq         $a0, $zero, L_80801C28
    if (ctx->r4 == 0) {
        // 0x80801C1C: nop
    
            goto L_80801C28;
    }
    // 0x80801C1C: nop

    // 0x80801C20: jal         0x800DA544
    // 0x80801C24: nop

    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80801C24: nop

    after_5:
L_80801C28:
    // 0x80801C28: jal         0x800FFAB0
    // 0x80801C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80801C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801C38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801C3C: jr          $ra
    // 0x80801C40: nop

    return;
    // 0x80801C40: nop

    // 0x80801C44: nop

    // 0x80801C48: nop

    // 0x80801C4C: nop

;}
RECOMP_FUNC void func_80805ECC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805ECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80805ED0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805ED4: beq         $a1, $at, L_80805EF8
    if (ctx->r5 == ctx->r1) {
        // 0x80805ED8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80805EF8;
    }
    // 0x80805ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805EDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805EE0: beq         $a1, $at, L_80805F00
    if (ctx->r5 == ctx->r1) {
        // 0x80805EE4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80805F00;
    }
    // 0x80805EE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80805EE8: beq         $a1, $at, L_80805F10
    if (ctx->r5 == ctx->r1) {
        // 0x80805EEC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80805F10;
    }
    // 0x80805EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80805EF0: b           L_80805F20
    // 0x80805EF4: nop

        goto L_80805F20;
    // 0x80805EF4: nop

L_80805EF8:
    // 0x80805EF8: b           L_80805F20
    // 0x80805EFC: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
        goto L_80805F20;
    // 0x80805EFC: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80805F00:
    // 0x80805F00: jal         0x80088380
    // 0x80805F04: nop

    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80805F04: nop

    after_0:
    // 0x80805F08: b           L_80805F20
    // 0x80805F0C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80805F20;
    // 0x80805F0C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80805F10:
    // 0x80805F10: jal         0x800883A8
    // 0x80805F14: nop

    _gcstatusDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80805F14: nop

    after_1:
    // 0x80805F18: b           L_80805F20
    // 0x80805F1C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_80805F20;
    // 0x80805F1C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_80805F20:
    // 0x80805F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80805F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80805F28: jr          $ra
    // 0x80805F2C: nop

    return;
    // 0x80805F2C: nop

;}
RECOMP_FUNC void chboggy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800628: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2072, 0X840) << 16);
    // 0x8080062C: jr          $ra
    // 0x80800630: addiu       $v0, $v0, 0x840
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2072, 0X840));
    return;
    // 0x80800630: addiu       $v0, $v0, 0x840
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2072, 0X840));
;}
RECOMP_FUNC void _gsmaker_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825A0: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825A0);
    return;
    // 0x800825A4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_808001F8_chballoonbomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001FC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: bne         $a1, $at, L_8080021C
    if (ctx->r5 != ctx->r1) {
        // 0x80800208: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080021C;
    }
    // 0x80800208: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080020C: jal         0x80800294
    // 0x80800210: nop

    func_80800294_chballoonbomb(rdram, ctx);
        goto after_0;
    // 0x80800210: nop

    after_0:
    // 0x80800214: b           L_80800220
    // 0x80800218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800220;
    // 0x80800218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080021C:
    // 0x8080021C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800220:
    // 0x80800220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800228: jr          $ra
    // 0x8080022C: nop

    return;
    // 0x8080022C: nop

;}
RECOMP_FUNC void func_800F8004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8004: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F8008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F800C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F8010: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8014: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x800F8018: lw          $s0, 0x5490($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5490);
    // 0x800F801C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F8020: jal         0x80091D00
    // 0x800F8024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bakey_getBitfield(rdram, ctx);
        goto after_0;
    // 0x800F8024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800F8028: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F802C: bnel        $a1, $zero, L_800F8044
    if (ctx->r5 != 0) {
        // 0x800F8030: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800F8044;
    }
    goto skip_0;
    // 0x800F8030: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    skip_0:
    // 0x800F8034: jal         0x80091964
    // 0x800F8038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bakey_func_80091964(rdram, ctx);
        goto after_1;
    // 0x800F8038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800F803C: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F8040: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
L_800F8044:
    // 0x800F8044: jal         0x8009F1A4
    // 0x800F8048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_func_8009F1A4(rdram, ctx);
        goto after_2;
    // 0x800F8048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800F804C: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F8050: bnel        $a1, $zero, L_800F8068
    if (ctx->r5 != 0) {
        // 0x800F8054: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_800F8068;
    }
    goto skip_1;
    // 0x800F8054: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800F8058: jal         0x8009EEF8
    // 0x800F805C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_func_8009EEF8(rdram, ctx);
        goto after_3;
    // 0x800F805C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800F8060: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F8064: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_800F8068:
    // 0x800F8068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F806C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F8070: beq         $t7, $zero, L_800F807C
    if (ctx->r15 == 0) {
        // 0x800F8074: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800F807C;
    }
    // 0x800F8074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F8078: sltu        $v0, $zero, $a1
    ctx->r2 = 0 < ctx->r5 ? 1 : 0;
L_800F807C:
    // 0x800F807C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F8080: jr          $ra
    // 0x800F8084: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F8084: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808002F0_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808002FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800300: jal         0x80100094
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800308: lw          $a2, 0x94($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X94);
    // 0x8080030C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800314: beql        $a2, $zero, L_80800340
    if (ctx->r6 == 0) {
        // 0x80800318: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800340;
    }
    goto skip_0;
    // 0x80800318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080031C: jal         0x80100094
    // 0x80800320: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800320: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800324: lbu         $t6, 0x99($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X99);
    // 0x80800328: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8080032C: beq         $t6, $zero, L_8080033C
    if (ctx->r14 == 0) {
        // 0x80800330: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8080033C;
    }
    // 0x80800330: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800334: jal         0x80087CA0
    // 0x80800338: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _gcnewoption_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800338: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
L_8080033C:
    // 0x8080033C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800340:
    // 0x80800340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800344: jr          $ra
    // 0x80800348: nop

    return;
    // 0x80800348: nop

;}
RECOMP_FUNC void _subaddiefind_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C70: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C70);
    return;
    // 0x80089C74: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_808061A8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808061A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808061AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808061B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808061B4: jal         0x80088360
    // 0x808061B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808061B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808061BC: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x808061C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808061C4: addiu       $a1, $zero, 0x18EF
    ctx->r5 = ADD32(0, 0X18EF);
    // 0x808061C8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808061CC: jal         0x80802AD4
    // 0x808061D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80802AD4_chgameselect(rdram, ctx);
        goto after_1;
    // 0x808061D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x808061D4: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x808061D8: jal         0x80802D04
    // 0x808061DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802D04_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808061DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808061E0: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x808061E4: jal         0x808026C8
    // 0x808061E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_3;
    // 0x808061E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
    // 0x808061EC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x808061F0: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x808061F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808061F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808061FC: jal         0x80100074
    // 0x80806200: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_80100074(rdram, ctx);
        goto after_4;
    // 0x80806200: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_4:
    // 0x80806204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80806208: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080620C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80806210: jr          $ra
    // 0x80806214: nop

    return;
    // 0x80806214: nop

;}
RECOMP_FUNC void func_800F73C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F73C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F73C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F73CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F73D0: addiu       $a1, $a1, 0x5490
    ctx->r5 = ADD32(ctx->r5, 0X5490);
    // 0x800F73D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F73D8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F73DC: addiu       $v1, $t6, 0x5490
    ctx->r3 = ADD32(ctx->r14, 0X5490);
    // 0x800F73E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F73E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F73E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F73EC: sb          $zero, 0x4A($a1)
    MEM_B(0X4A, ctx->r5) = 0;
    // 0x800F73F0: sb          $zero, 0x49($a1)
    MEM_B(0X49, ctx->r5) = 0;
    // 0x800F73F4: addiu       $a0, $a0, 0x5498
    ctx->r4 = ADD32(ctx->r4, 0X5498);
    // 0x800F73F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800F73FC:
    // 0x800F73FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F7400: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800F7404: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800F7408: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800F740C: bne         $at, $zero, L_800F73FC
    if (ctx->r1 != 0) {
        // 0x800F7410: sb          $zero, 0x1F($v1)
        MEM_B(0X1F, ctx->r3) = 0;
            goto L_800F73FC;
    }
    // 0x800F7410: sb          $zero, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = 0;
    // 0x800F7414: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800F7418: sh          $t7, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r15;
    // 0x800F741C: lh          $t8, 0x52($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X52);
    // 0x800F7420: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800F7424: jal         0x800F80D8
    // 0x800F7428: sh          $t8, 0x50($a1)
    MEM_H(0X50, ctx->r5) = ctx->r24;
    func_800F80D8(rdram, ctx);
        goto after_0;
    // 0x800F7428: sh          $t8, 0x50($a1)
    MEM_H(0X50, ctx->r5) = ctx->r24;
    after_0:
    // 0x800F742C: jal         0x800DB9B0
    // 0x800F7430: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x800F7430: nop

    after_1:
    // 0x800F7434: bne         $v0, $zero, L_800F7478
    if (ctx->r2 != 0) {
        // 0x800F7438: nop
    
            goto L_800F7478;
    }
    // 0x800F7438: nop

    // 0x800F743C: jal         0x800887B0
    // 0x800F7440: nop

    _glcutDll_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x800F7440: nop

    after_2:
    // 0x800F7444: bne         $v0, $zero, L_800F7478
    if (ctx->r2 != 0) {
        // 0x800F7448: nop
    
            goto L_800F7478;
    }
    // 0x800F7448: nop

    // 0x800F744C: jal         0x800F99E8
    // 0x800F7450: nop

    func_800F99E8(rdram, ctx);
        goto after_3;
    // 0x800F7450: nop

    after_3:
    // 0x800F7454: bne         $v0, $zero, L_800F7478
    if (ctx->r2 != 0) {
        // 0x800F7458: nop
    
            goto L_800F7478;
    }
    // 0x800F7458: nop

    // 0x800F745C: blez        $s1, L_800F7478
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800F7460: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800F7478;
    }
    // 0x800F7460: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800F7464:
    // 0x800F7464: jal         0x800F61E4
    // 0x800F7468: nop

    func_800F61E4(rdram, ctx);
        goto after_4;
    // 0x800F7468: nop

    after_4:
    // 0x800F746C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800F7470: bne         $s0, $s1, L_800F7464
    if (ctx->r16 != ctx->r17) {
        // 0x800F7474: nop
    
            goto L_800F7464;
    }
    // 0x800F7474: nop

L_800F7478:
    // 0x800F7478: jal         0x800F8B94
    // 0x800F747C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F8B94(rdram, ctx);
        goto after_5;
    // 0x800F747C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_5:
    // 0x800F7480: jal         0x800F5898
    // 0x800F7484: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_6;
    // 0x800F7484: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_6:
    // 0x800F7488: blez        $v0, L_800F74B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800F748C: nop
    
            goto L_800F74B8;
    }
    // 0x800F748C: nop

L_800F7490:
    // 0x800F7490: jal         0x800F6BE4
    // 0x800F7494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_7;
    // 0x800F7494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800F7498: beq         $v0, $zero, L_800F74A4
    if (ctx->r2 == 0) {
        // 0x800F749C: nop
    
            goto L_800F74A4;
    }
    // 0x800F749C: nop

    // 0x800F74A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800F74A4:
    // 0x800F74A4: jal         0x800F5898
    // 0x800F74A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_8;
    // 0x800F74A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_8:
    // 0x800F74AC: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F74B0: bne         $at, $zero, L_800F7490
    if (ctx->r1 != 0) {
        // 0x800F74B4: nop
    
            goto L_800F7490;
    }
    // 0x800F74B4: nop

L_800F74B8:
    // 0x800F74B8: bne         $s1, $zero, L_800F74D4
    if (ctx->r17 != 0) {
        // 0x800F74BC: nop
    
            goto L_800F74D4;
    }
    // 0x800F74BC: nop

    // 0x800F74C0: jal         0x800F61E4
    // 0x800F74C4: nop

    func_800F61E4(rdram, ctx);
        goto after_9;
    // 0x800F74C4: nop

    after_9:
    // 0x800F74C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F74CC: jal         0x800F7E64
    // 0x800F74D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800F7E64(rdram, ctx);
        goto after_10;
    // 0x800F74D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
L_800F74D4:
    // 0x800F74D4: jal         0x800F8B88
    // 0x800F74D8: nop

    func_800F8B88(rdram, ctx);
        goto after_11;
    // 0x800F74D8: nop

    after_11:
    // 0x800F74DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F74E0: bne         $v0, $at, L_800F7554
    if (ctx->r2 != ctx->r1) {
        // 0x800F74E4: nop
    
            goto L_800F7554;
    }
    // 0x800F74E4: nop

    // 0x800F74E8: jal         0x800878A0
    // 0x800F74EC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x800F74EC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_12:
    // 0x800F74F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800F74F4: jal         0x800878A0
    // 0x800F74F8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x800F74F8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_13:
    // 0x800F74FC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800F7500: beq         $s1, $v1, L_800F7554
    if (ctx->r17 == ctx->r3) {
        // 0x800F7504: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800F7554;
    }
    // 0x800F7504: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800F7508: beq         $v0, $v1, L_800F7554
    if (ctx->r2 == ctx->r3) {
        // 0x800F750C: nop
    
            goto L_800F7554;
    }
    // 0x800F750C: nop

    // 0x800F7510: jal         0x800F65D0
    // 0x800F7514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F65D0(rdram, ctx);
        goto after_14;
    // 0x800F7514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x800F7518: beq         $v0, $zero, L_800F7528
    if (ctx->r2 == 0) {
        // 0x800F751C: nop
    
            goto L_800F7528;
    }
    // 0x800F751C: nop

    // 0x800F7520: b           L_800F754C
    // 0x800F7524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800F754C;
    // 0x800F7524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800F7528:
    // 0x800F7528: jal         0x800F65D0
    // 0x800F752C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F65D0(rdram, ctx);
        goto after_15;
    // 0x800F752C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x800F7530: beq         $v0, $zero, L_800F7540
    if (ctx->r2 == 0) {
        // 0x800F7534: nop
    
            goto L_800F7540;
    }
    // 0x800F7534: nop

    // 0x800F7538: b           L_800F754C
    // 0x800F753C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800F754C;
    // 0x800F753C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800F7540:
    // 0x800F7540: jal         0x800878A0
    // 0x800F7544: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x800F7544: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_16:
    // 0x800F7548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800F754C:
    // 0x800F754C: jal         0x800F8128
    // 0x800F7550: nop

    func_800F8128(rdram, ctx);
        goto after_17;
    // 0x800F7550: nop

    after_17:
L_800F7554:
    // 0x800F7554: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F7558: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F755C: addiu       $s0, $s0, 0x54B0
    ctx->r16 = ADD32(ctx->r16, 0X54B0);
    // 0x800F7560: addiu       $v0, $v0, 0x5490
    ctx->r2 = ADD32(ctx->r2, 0X5490);
    // 0x800F7564: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
L_800F7568:
    // 0x800F7568: beql        $a0, $zero, L_800F7580
    if (ctx->r4 == 0) {
        // 0x800F756C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800F7580;
    }
    goto skip_0;
    // 0x800F756C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x800F7570: jal         0x80084FB0
    // 0x800F7574: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    _basetup_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x800F7574: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_18:
    // 0x800F7578: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800F757C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800F7580:
    // 0x800F7580: bnel        $v0, $s0, L_800F7568
    if (ctx->r2 != ctx->r16) {
        // 0x800F7584: lw          $a0, 0x0($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X0);
            goto L_800F7568;
    }
    goto skip_1;
    // 0x800F7584: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x800F7588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F758C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F7590: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F7594: jr          $ra
    // 0x800F7598: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800F7598: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8008AC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AC4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008AC50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008AC54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008AC58: jal         0x8008AEDC
    // 0x8008AC5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_0;
    // 0x8008AC5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8008AC60: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8008AC64: jal         0x8008AA0C
    // 0x8008AC68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AA0C(rdram, ctx);
        goto after_1;
    // 0x8008AC68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8008AC6C: jal         0x8008C0C8
    // 0x8008AC70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008C0C8(rdram, ctx);
        goto after_2;
    // 0x8008AC70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8008AC74: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8008AC78: jal         0x8008A990
    // 0x8008AC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008A990(rdram, ctx);
        goto after_3;
    // 0x8008AC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008AC80: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8008AC84: jal         0x8008B2AC
    // 0x8008AC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B2AC(rdram, ctx);
        goto after_4;
    // 0x8008AC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008AC8C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008AC90: lb          $t7, 0x1B($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1B);
    // 0x8008AC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AC98: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8008AC9C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008ACA0: bltz        $t7, L_8008ACAC
    if (SIGNED(ctx->r15) < 0) {
        // 0x8008ACA4: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_8008ACAC;
    }
    // 0x8008ACA4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8008ACA8: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8008ACAC:
    // 0x8008ACAC: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8008ACB0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8008ACB4: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8008ACB8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8008ACBC: nop

    // 0x8008ACC0: bc1fl       L_8008ACDC
    if (!c1cs) {
        // 0x8008ACC4: lwc1        $f2, 0x8($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
            goto L_8008ACDC;
    }
    goto skip_0;
    // 0x8008ACC4: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x8008ACC8: jal         0x8008B134
    // 0x8008ACCC: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x8008ACCC: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_5:
    // 0x8008ACD0: b           L_8008AD60
    // 0x8008ACD4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
        goto L_8008AD60;
    // 0x8008ACD4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8008ACD8: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
L_8008ACDC:
    // 0x8008ACDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ACE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008ACE4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8008ACE8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8008ACEC: bc1tl       L_8008AD0C
    if (c1cs) {
        // 0x8008ACF0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8008AD0C;
    }
    goto skip_1;
    // 0x8008ACF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x8008ACF4: lwc1        $f12, 0x4A94($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4A94);
    // 0x8008ACF8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8008ACFC: nop

    // 0x8008AD00: bc1fl       L_8008AD48
    if (!c1cs) {
        // 0x8008AD04: trunc.w.s   $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8008AD48;
    }
    goto skip_2;
    // 0x8008AD04: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_2:
    // 0x8008AD08: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8008AD0C:
    // 0x8008AD0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AD10: lwc1        $f12, 0x4A98($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4A98);
    // 0x8008AD14: bc1fl       L_8008AD24
    if (!c1cs) {
        // 0x8008AD18: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_8008AD24;
    }
    goto skip_3;
    // 0x8008AD18: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_3:
    // 0x8008AD1C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8008AD20: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_8008AD24:
    // 0x8008AD24: nop

    // 0x8008AD28: bc1f        L_8008AD34
    if (!c1cs) {
        // 0x8008AD2C: nop
    
            goto L_8008AD34;
    }
    // 0x8008AD2C: nop

    // 0x8008AD30: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8008AD34:
    // 0x8008AD34: jal         0x8008B134
    // 0x8008AD38: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x8008AD38: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8008AD3C: b           L_8008AD60
    // 0x8008AD40: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
        goto L_8008AD60;
    // 0x8008AD40: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8008AD44: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
L_8008AD48:
    // 0x8008AD48: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8008AD4C: nop

    // 0x8008AD50: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8008AD54: nop

    // 0x8008AD58: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008AD5C: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
L_8008AD60:
    // 0x8008AD60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008AD64: jal         0x8008C1C0
    // 0x8008AD68: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008C1C0(rdram, ctx);
        goto after_7;
    // 0x8008AD68: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x8008AD6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AD70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AD74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008AD78: jr          $ra
    // 0x8008AD7C: nop

    return;
    // 0x8008AD7C: nop

;}
