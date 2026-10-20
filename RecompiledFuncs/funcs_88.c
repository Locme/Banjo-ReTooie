#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808003F0_vpwibble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808003F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003FC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800400: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80800404: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800408: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080040C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800410: nop

    // 0x80800414: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800418: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8080041C: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x80800420: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80800424: nop

    // 0x80800428: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080042C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80800430: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x80800434: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80800438: nop

    // 0x8080043C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800440: jal         0x800EEF94
    // 0x80800444: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_800EEF94(rdram, ctx);
        goto after_0;
    // 0x80800444: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80800448: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8080044C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800450: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800454: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800458: mul.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8080045C: jal         0x800136D0
    // 0x80800460: nop

    func_800136D0(rdram, ctx);
        goto after_1;
    // 0x80800460: nop

    after_1:
    // 0x80800464: jal         0x800137D4
    // 0x80800468: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800137D4(rdram, ctx);
        goto after_2;
    // 0x80800468: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x8080046C: lh          $t9, 0x1A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A);
    // 0x80800470: lbu         $t0, 0x33($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X33);
    // 0x80800474: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80800478: nop

    // 0x8080047C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800480: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800484: beql        $t0, $zero, L_8080050C
    if (ctx->r8 == 0) {
        // 0x80800488: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080050C;
    }
    goto skip_0;
    // 0x80800488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080048C: jal         0x80013788
    // 0x80800490: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_80013788(rdram, ctx);
        goto after_3;
    // 0x80800490: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80800494: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
    // 0x80800498: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2982, 0X6F4) << 16);
    // 0x8080049C: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808004A0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x808004A4: lwc1        $f10, 0x6F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2982, 0X6F4));
    // 0x808004A8: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808004AC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808004B0: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808004B4: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x808004B8: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808004BC: nop

    // 0x808004C0: mul.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808004C4: bc1f        L_808004F0
    if (!c1cs) {
        // 0x808004C8: lwc1        $f8, 0x28($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
            goto L_808004F0;
    }
    // 0x808004C8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808004CC: div.s       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x808004D0: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808004D4: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x808004D8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808004DC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x808004E0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808004E4: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808004E8: b           L_80800508
    // 0x808004EC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_80800508;
    // 0x808004EC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_808004F0:
    // 0x808004F0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x808004F4: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x808004F8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x808004FC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800500: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80800504: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
L_80800508:
    // 0x80800508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080050C:
    // 0x8080050C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800510: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800514: jr          $ra
    // 0x80800518: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80800518: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void func_80091290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091290: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80091294: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80091298: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8009129C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800912A0: lwc1        $f4, 0x4D28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4D28);
    // 0x800912A4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800912A8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800912AC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800912B0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800912B4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800912B8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800912BC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800912C0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800912C4: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x800912C8: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800912CC: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x800912D0: jal         0x800F10B4
    // 0x800912D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x800912D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800912D8: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x800912DC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800912E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800912E4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800912E8: jal         0x80092C90
    // 0x800912EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80092C90(rdram, ctx);
        goto after_1;
    // 0x800912EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800912F0: jal         0x800D8FF8
    // 0x800912F4: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x800912F4: nop

    after_2:
    // 0x800912F8: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800912FC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80091300: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80091304: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80091308: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x8009130C: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x80091310: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80091314: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80091318: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x8009131C: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80091320: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80091324: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80091328: mfc1        $s2, $f18
    ctx->r18 = (int32_t)ctx->f18.u32l;
    // 0x8009132C: nop

    // 0x80091330: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x80091334: nop

    // 0x80091338: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009133C: sub.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80091340: jal         0x8009FBB0
    // 0x80091344: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    func_8009FBB0(rdram, ctx);
        goto after_3;
    // 0x80091344: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x80091348: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8009134C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80091350: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x80091354: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80091358: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8009135C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80091360: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80091364: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80091368: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x8009136C: addiu       $a2, $zero, -0x32
    ctx->r6 = ADD32(0, -0X32);
    // 0x80091370: jal         0x800BA930
    // 0x80091374: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    func_800BA930(rdram, ctx);
        goto after_4;
    // 0x80091374: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    after_4:
    // 0x80091378: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8009137C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80091380: addiu       $a1, $zero, -0x32
    ctx->r5 = ADD32(0, -0X32);
    // 0x80091384: beq         $t0, $zero, L_800913EC
    if (ctx->r8 == 0) {
        // 0x80091388: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800913EC;
    }
    // 0x80091388: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009138C: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80091390: addiu       $t2, $zero, 0x46
    ctx->r10 = ADD32(0, 0X46);
    // 0x80091394: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x80091398: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8009139C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800913A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800913A4: addiu       $a2, $zero, -0x46
    ctx->r6 = ADD32(0, -0X46);
    // 0x800913A8: jal         0x800BA6B0
    // 0x800913AC: addiu       $a3, $zero, -0x32
    ctx->r7 = ADD32(0, -0X32);
    func_800BA6B0(rdram, ctx);
        goto after_5;
    // 0x800913AC: addiu       $a3, $zero, -0x32
    ctx->r7 = ADD32(0, -0X32);
    after_5:
    // 0x800913B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800913B4: lwc1        $f0, 0x4D2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4D2C);
    // 0x800913B8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800913BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800913C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800913C4: jal         0x800BA7C4
    // 0x800913C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BA7C4(rdram, ctx);
        goto after_6;
    // 0x800913C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x800913CC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800913D0: lui         $a2, 0x3E61
    ctx->r6 = S32(0X3E61 << 16);
    // 0x800913D4: ori         $a2, $a2, 0x47AE
    ctx->r6 = ctx->r6 | 0X47AE;
    // 0x800913D8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800913DC: jal         0x800BA7FC
    // 0x800913E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BA7FC(rdram, ctx);
        goto after_7;
    // 0x800913E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800913E4: b           L_80091424
    // 0x800913E8: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
        goto L_80091424;
    // 0x800913E8: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
L_800913EC:
    // 0x800913EC: lwc1        $f0, 0x4D30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4D30);
    // 0x800913F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800913F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800913F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800913FC: jal         0x800BA7C4
    // 0x80091400: nop

    func_800BA7C4(rdram, ctx);
        goto after_8;
    // 0x80091400: nop

    after_8:
    // 0x80091404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80091408: lwc1        $f0, 0x4D34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4D34);
    // 0x8009140C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80091410: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80091414: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80091418: jal         0x800BA7FC
    // 0x8009141C: nop

    func_800BA7FC(rdram, ctx);
        goto after_9;
    // 0x8009141C: nop

    after_9:
    // 0x80091420: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
L_80091424:
    // 0x80091424: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80091428: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009142C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80091430: jal         0x800BA8F8
    // 0x80091434: nop

    func_800BA8F8(rdram, ctx);
        goto after_10;
    // 0x80091434: nop

    after_10:
    // 0x80091438: blez        $s2, L_80091458
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8009143C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80091458;
    }
    // 0x8009143C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80091440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80091444:
    // 0x80091444: jal         0x800BA22C
    // 0x80091448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_11;
    // 0x80091448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8009144C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80091450: bnel        $s0, $s2, L_80091444
    if (ctx->r16 != ctx->r18) {
        // 0x80091454: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80091444;
    }
    goto skip_0;
    // 0x80091454: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80091458:
    // 0x80091458: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8009145C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80091460: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80091464: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80091468: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x8009146C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x80091470: nop

    // 0x80091474: bc1f        L_80091494
    if (!c1cs) {
        // 0x80091478: nop
    
            goto L_80091494;
    }
    // 0x80091478: nop

    // 0x8009147C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80091480: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80091484: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    // 0x80091488: jal         0x800F10B4
    // 0x8009148C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x8009148C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x80091490: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
L_80091494:
    // 0x80091494: jal         0x800D8FF8
    // 0x80091498: nop

    func_800D8FF8(rdram, ctx);
        goto after_13;
    // 0x80091498: nop

    after_13:
    // 0x8009149C: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800914A0: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800914A4: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800914A8: lw          $v0, 0x30($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X30);
    // 0x800914AC: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800914B0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800914B4: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x800914B8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800914BC: lw          $v0, 0x30($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X30);
    // 0x800914C0: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800914C4: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800914C8: mfc1        $s2, $f10
    ctx->r18 = (int32_t)ctx->f10.u32l;
    // 0x800914CC: nop

    // 0x800914D0: mtc1        $s2, $f16
    ctx->f16.u32l = ctx->r18;
    // 0x800914D4: nop

    // 0x800914D8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800914DC: sub.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800914E0: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x800914E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800914E8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800914EC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800914F0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800914F4: jr          $ra
    // 0x800914F8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800914F8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8080082C_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080082C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800830: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800834: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800838: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8080083C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800840: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800844: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800848: nop

    // 0x8080084C: bc1fl       L_80800860
    if (!c1cs) {
        // 0x80800850: lw          $t6, 0x64($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X64);
            goto L_80800860;
    }
    goto skip_0;
    // 0x80800850: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80800854: b           L_808008FC
    // 0x80800858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008FC;
    // 0x80800858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080085C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
L_80800860:
    // 0x80800860: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800864: bgez        $t8, L_80800874
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800868: nop
    
            goto L_80800874;
    }
    // 0x80800868: nop

    // 0x8080086C: b           L_808008FC
    // 0x80800870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008FC;
    // 0x80800870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800874:
    // 0x80800874: jal         0x801072A8
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801072A8(rdram, ctx);
        goto after_0;
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080087C: beq         $v0, $zero, L_8080088C
    if (ctx->r2 == 0) {
        // 0x80800880: nop
    
            goto L_8080088C;
    }
    // 0x80800880: nop

    // 0x80800884: b           L_808008FC
    // 0x80800888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008FC;
    // 0x80800888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080088C:
    // 0x8080088C: jal         0x80089F78
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800894: bne         $v0, $zero, L_808008A4
    if (ctx->r2 != 0) {
        // 0x80800898: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808008A4;
    }
    // 0x80800898: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080089C: b           L_808008FC
    // 0x808008A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008FC;
    // 0x808008A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008A4:
    // 0x808008A4: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x808008A8: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x808008AC: addiu       $a3, $zero, -0x32
    ctx->r7 = ADD32(0, -0X32);
    // 0x808008B0: jal         0x8010C9FC
    // 0x808008B4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_8010C9FC(rdram, ctx);
        goto after_2;
    // 0x808008B4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x808008B8: bne         $v0, $zero, L_808008C8
    if (ctx->r2 != 0) {
        // 0x808008BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008C8;
    }
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C0: b           L_808008FC
    // 0x808008C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008FC;
    // 0x808008C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008C8:
    // 0x808008C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808008CC: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x808008D0: jal         0x8010C668
    // 0x808008D4: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    func_8010C668(rdram, ctx);
        goto after_3;
    // 0x808008D4: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_3:
    // 0x808008D8: bne         $v0, $zero, L_808008E8
    if (ctx->r2 != 0) {
        // 0x808008DC: nop
    
            goto L_808008E8;
    }
    // 0x808008DC: nop

    // 0x808008E0: b           L_808008FC
    // 0x808008E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008FC;
    // 0x808008E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008E8:
    // 0x808008E8: jal         0x80089EF8
    // 0x808008EC: nop

    _suchase_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808008EC: nop

    after_4:
    // 0x808008F0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x808008F4: xor         $v0, $v0, $t9
    ctx->r2 = ctx->r2 ^ ctx->r25;
    // 0x808008F8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_808008FC:
    // 0x808008FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800900: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800904: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800908: jr          $ra
    // 0x8080090C: nop

    return;
    // 0x8080090C: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D00: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083D00);
    return;
    // 0x80083D04: addi        $t0, $zero, 0x90
    ctx->r8 = ADD32(0, 0X90);
;}
RECOMP_FUNC void func_8080231C_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_klungo_fade(rdram, ctx, 0)) return;
    // 0x8080231C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802324: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802328: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080232C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80802330: jal         0x80089C90
    // 0x80802334: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80802334: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80802338: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8080233C: nop

    // 0x80802340: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802344: jal         0x800D8FF8
    // 0x80802348: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80802348: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8080234C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80802350: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80802354: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80802358: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080235C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802360: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80802364: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80802368: nop

    // 0x8080236C: bc1fl       L_80802380
    if (!c1cs) {
        // 0x80802370: trunc.w.s   $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80802380;
    }
    goto skip_0;
    // 0x80802370: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_0:
    // 0x80802374: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80802378: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8080237C: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
L_80802380:
    // 0x80802380: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802384: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80802388: jal         0x80089C98
    // 0x8080238C: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080238C: nop

    after_2:
    // 0x80802390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802394: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80802398: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080239C: jr          $ra
    // 0x808023A0: nop

    return;
    // 0x808023A0: nop

;}
RECOMP_FUNC void func_808002C8_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002D4: jal         0x80089D48
    // 0x808002D8: lbu         $a0, 0x28($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X28);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808002D8: lbu         $a0, 0x28($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X28);
    after_0:
    // 0x808002DC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808002E0: sb          $v0, 0x28($t7)
    MEM_B(0X28, ctx->r15) = ctx->r2;
    // 0x808002E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002EC: jr          $ra
    // 0x808002F0: nop

    return;
    // 0x808002F0: nop

;}
RECOMP_FUNC void func_808003A8_glsplinecs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B0: jal         0x80104248
    // 0x808003B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x808003B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003B8: bne         $v0, $zero, L_808003D8
    if (ctx->r2 != 0) {
        // 0x808003BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808003D8;
    }
    // 0x808003BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808003C0: jal         0x801042B8
    // 0x808003C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_801042B8(rdram, ctx);
        goto after_1;
    // 0x808003C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808003C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003CC: jal         0x8008AF24
    // 0x808003D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x808003D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x808003D4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_808003D8:
    // 0x808003D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

;}
RECOMP_FUNC void func_8008CFF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CFF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CFF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CFF8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8008CFFC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8008D000: lw          $a2, 0x3C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X3C);
    // 0x8008D004: beq         $a2, $zero, L_8008D01C
    if (ctx->r6 == 0) {
        // 0x8008D008: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8008D01C;
    }
    // 0x8008D008: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8008D00C: jal         0x8008ADBC
    // 0x8008D010: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8008ADBC(rdram, ctx);
        goto after_0;
    // 0x8008D010: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008D014: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008D018: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
L_8008D01C:
    // 0x8008D01C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8008D020: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8008D024: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008D028: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008D02C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8008D030: bnel        $t6, $at, L_8008D040
    if (ctx->r14 != ctx->r1) {
        // 0x8008D034: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008D040;
    }
    goto skip_0;
    // 0x8008D034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008D038: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8008D03C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008D040:
    // 0x8008D040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D044: jr          $ra
    // 0x8008D048: nop

    return;
    // 0x8008D048: nop

;}
RECOMP_FUNC void func_80800364_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080036C: lwc1        $f4, 0x1EC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80800370: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80800374: lw          $t6, 0x1E4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E4);
    // 0x80800378: sll         $t8, $t6, 30
    ctx->r24 = S32(ctx->r14 << 30);
    // 0x8080037C: bgez        $t8, L_80800394
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800380: nop
    
            goto L_80800394;
    }
    // 0x80800380: nop

    // 0x80800384: jal         0x800885F8
    // 0x80800388: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _glintrosyncDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800388: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080038C: b           L_808003A0
    // 0x80800390: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_808003A0;
    // 0x80800390: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800394:
    // 0x80800394: jal         0x800D8FF8
    // 0x80800398: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800398: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080039C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808003A0:
    // 0x808003A0: lw          $t9, 0x1E4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1E4);
    // 0x808003A4: lwc1        $f6, 0x1F0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1F0);
    // 0x808003A8: sll         $t1, $t9, 29
    ctx->r9 = S32(ctx->r25 << 29);
    // 0x808003AC: bltz        $t1, L_808003B8
    if (SIGNED(ctx->r9) < 0) {
        // 0x808003B0: div.s       $f2, $f0, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
            goto L_808003B8;
    }
    // 0x808003B0: div.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808003B4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_808003B8:
    // 0x808003B8: lwc1        $f8, 0x1EC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x808003BC: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x808003C0: swc1        $f10, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->f10.u32l;
    // 0x808003C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003C8: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808003CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003D0: jr          $ra
    // 0x808003D4: nop

    return;
    // 0x808003D4: nop

;}
RECOMP_FUNC void func_8011649C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011649C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801164A0: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801164A4: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
L_801164A8:
    // 0x801164A8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801164AC: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801164B0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801164B4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x801164B8: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801164BC: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801164C0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801164C4: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801164C8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x801164CC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801164D0: bgtz        $a2, L_801164A8
    if (SIGNED(ctx->r6) > 0) {
        // 0x801164D4: swc1        $f6, -0xC($a1)
        MEM_W(-0XC, ctx->r5) = ctx->f6.u32l;
            goto L_801164A8;
    }
    // 0x801164D4: swc1        $f6, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f6.u32l;
    // 0x801164D8: jr          $ra
    // 0x801164DC: nop

    return;
    // 0x801164DC: nop

;}
RECOMP_FUNC void subaddierouteDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800340: addiu       $sp, $sp, -0x178
    ctx->r29 = ADD32(ctx->r29, -0X178);
    // 0x80800344: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800348: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8080034C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80800350: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800354: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800358: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080035C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800360: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800364: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800368: lw          $s6, 0x70($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X70);
    // 0x8080036C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800370: srl         $t6, $s6, 25
    ctx->r14 = S32(U32(ctx->r22) >> 25);
    // 0x80800374: jal         0x801015B0
    // 0x80800378: addiu       $s6, $t6, -0x1
    ctx->r22 = ADD32(ctx->r14, -0X1);
    func_801015B0(rdram, ctx);
        goto after_0;
    // 0x80800378: addiu       $s6, $t6, -0x1
    ctx->r22 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x8080037C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80800380: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80800384: bne         $t7, $zero, L_80800394
    if (ctx->r15 != 0) {
        // 0x80800388: nop
    
            goto L_80800394;
    }
    // 0x80800388: nop

    // 0x8080038C: jal         0x80800000
    // 0x80800390: nop

    func_80800000_subaddierouteDll(rdram, ctx);
        goto after_1;
    // 0x80800390: nop

    after_1:
L_80800394:
    // 0x80800394: bgez        $s6, L_808003C0
    if (SIGNED(ctx->r22) >= 0) {
        // 0x80800398: nop
    
            goto L_808003C0;
    }
    // 0x80800398: nop

    // 0x8080039C: jal         0x80106F30
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106F30(rdram, ctx);
        goto after_2;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808003A4: beq         $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x808003A8: nop
    
            goto L_808003C0;
    }
    // 0x808003A8: nop

    // 0x808003AC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x808003B0: srl         $t8, $v1, 20
    ctx->r24 = S32(U32(ctx->r3) >> 20);
    // 0x808003B4: beq         $t8, $zero, L_808003C0
    if (ctx->r24 == 0) {
        // 0x808003B8: nop
    
            goto L_808003C0;
    }
    // 0x808003B8: nop

    // 0x808003BC: addiu       $s6, $t8, -0x1
    ctx->r22 = ADD32(ctx->r24, -0X1);
L_808003C0:
    // 0x808003C0: jal         0x800CC5F4
    // 0x808003C4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800CC5F4(rdram, ctx);
        goto after_3;
    // 0x808003C4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x808003C8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808003CC: jal         0x8001B798
    // 0x808003D0: lh          $a0, 0x0($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X0);
    func_8001B798(rdram, ctx);
        goto after_4;
    // 0x808003D0: lh          $a0, 0x0($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X0);
    after_4:
    // 0x808003D4: sll         $s4, $s6, 2
    ctx->r20 = S32(ctx->r22 << 2);
    // 0x808003D8: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
    // 0x808003DC: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x808003E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808003E8: beq         $t9, $zero, L_80800400
    if (ctx->r25 == 0) {
        // 0x808003EC: nop
    
            goto L_80800400;
    }
    // 0x808003EC: nop

    // 0x808003F0: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x808003F4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x808003F8: b           L_80800488
    // 0x808003FC: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
        goto L_80800488;
    // 0x808003FC: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
L_80800400:
    // 0x80800400: jal         0x8080011C
    // 0x80800404: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    func_8080011C_subaddierouteDll(rdram, ctx);
        goto after_5;
    // 0x80800404: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_5:
    // 0x80800408: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080040C: jal         0x8001B668
    // 0x80800410: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8001B668(rdram, ctx);
        goto after_6;
    // 0x80800410: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80800414: addu        $v1, $s0, $s4
    ctx->r3 = ADD32(ctx->r16, ctx->r20);
    // 0x80800418: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8080041C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800420: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    // 0x80800424: jal         0x8001B798
    // 0x80800428: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    func_8001B798(rdram, ctx);
        goto after_7;
    // 0x80800428: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    after_7:
    // 0x8080042C: blez        $s5, L_80800488
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80800430: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80800488;
    }
    // 0x80800430: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800434: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800438: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080043C: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_80800440:
    // 0x80800440: lh          $t3, 0x0($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X0);
    // 0x80800444: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
    // 0x80800448: jal         0x8001B798
    // 0x8080044C: lh          $a0, 0x0($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X0);
    func_8001B798(rdram, ctx);
        goto after_8;
    // 0x8080044C: lh          $a0, 0x0($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X0);
    after_8:
    // 0x80800450: addu        $t4, $v0, $s4
    ctx->r12 = ADD32(ctx->r2, ctx->r20);
    // 0x80800454: jal         0x8001B798
    // 0x80800458: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    func_8001B798(rdram, ctx);
        goto after_9;
    // 0x80800458: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    after_9:
    // 0x8080045C: addu        $t5, $v0, $s0
    ctx->r13 = ADD32(ctx->r2, ctx->r16);
    // 0x80800460: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80800464: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800468: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8080046C: jal         0x8080024C
    // 0x80800470: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    func_8080024C_subaddierouteDll(rdram, ctx);
        goto after_10;
    // 0x80800470: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    after_10:
    // 0x80800474: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80800478: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8080047C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80800480: bne         $s3, $s5, L_80800440
    if (ctx->r19 != ctx->r21) {
        // 0x80800484: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_80800440;
    }
    // 0x80800484: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
L_80800488:
    // 0x80800488: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080048C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800490: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800494: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800498: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080049C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808004A0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808004A4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x808004A8: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x808004AC: jr          $ra
    // 0x808004B0: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
    return;
    // 0x808004B0: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
;}
RECOMP_FUNC void func_8080026C_chbilldrillboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080026C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800274: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800278: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080027C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800280: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800284: bnel        $t7, $at, L_808002B8
    if (ctx->r15 != ctx->r1) {
        // 0x80800288: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002B8;
    }
    goto skip_0;
    // 0x80800288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080028C: jal         0x8008A4C0
    // 0x80800290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800294: beq         $v0, $zero, L_808002B4
    if (ctx->r2 == 0) {
        // 0x80800298: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002B4;
    }
    // 0x80800298: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080029C: jal         0x8010A570
    // 0x808002A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x808002A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808002A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808002AC: jal         0x80086670
    // 0x808002B0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808002B0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_2:
L_808002B4:
    // 0x808002B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002B8:
    // 0x808002B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002BC: jr          $ra
    // 0x808002C0: nop

    return;
    // 0x808002C0: nop

;}
RECOMP_FUNC void ncbaledge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080004C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800050: jal         0x80111B8C
    // 0x80800054: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_0;
    // 0x80800054: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_0:
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: jal         0x801124D0
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800068: jal         0x80115858
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80115858(rdram, ctx);
        goto after_2;
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800074: jal         0x80115870
    // 0x80800078: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80115870(rdram, ctx);
        goto after_3;
    // 0x80800078: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_3:
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void func_80801F9C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801FA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801FA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801FA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801FAC: jal         0x800845C8
    // 0x80801FB0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801FB0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801FB4: beq         $v0, $zero, L_80801FC4
    if (ctx->r2 == 0) {
        // 0x80801FB8: nop
    
            goto L_80801FC4;
    }
    // 0x80801FB8: nop

    // 0x80801FBC: jal         0x80800164
    // 0x80801FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bstnt(rdram, ctx);
        goto after_1;
    // 0x80801FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80801FC4:
    // 0x80801FC4: jal         0x80084600
    // 0x80801FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80801FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801FCC: beq         $v0, $zero, L_80801FD8
    if (ctx->r2 == 0) {
        // 0x80801FD0: addiu       $t6, $zero, 0x10C
        ctx->r14 = ADD32(0, 0X10C);
            goto L_80801FD8;
    }
    // 0x80801FD0: addiu       $t6, $zero, 0x10C
    ctx->r14 = ADD32(0, 0X10C);
    // 0x80801FD4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80801FD8:
    // 0x80801FD8: jal         0x80800F94
    // 0x80801FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstnt_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80801FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FE4: jal         0x8009E5C8
    // 0x80801FE8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80801FE8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801FF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801FF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801FF8: jr          $ra
    // 0x80801FFC: nop

    return;
    // 0x80801FFC: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012B4: lbu         $t6, 0x60($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X60);
    // 0x808012B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808012BC: andi        $t7, $t6, 0xFF01
    ctx->r15 = ctx->r14 & 0XFF01;
    // 0x808012C0: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x808012C4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808012C8: jal         0x8080134C
    // 0x808012CC: sb          $t8, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r24;
    sumumbofx_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808012CC: sb          $t8, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r24;
    after_0:
    // 0x808012D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012D8: jr          $ra
    // 0x808012DC: nop

    return;
    // 0x808012DC: nop

;}
RECOMP_FUNC void func_80800C34_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C3C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800C40: jal         0x8010A3E8
    // 0x80800C44: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_8010A3E8(rdram, ctx);
        goto after_0;
    // 0x80800C44: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_0:
    // 0x80800C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C50: jr          $ra
    // 0x80800C54: nop

    return;
    // 0x80800C54: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080068C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800690: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800694: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800698: jal         0x80800200
    // 0x8080069C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_80800200_bsbwhirl(rdram, ctx);
        goto after_0;
    // 0x8080069C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A4: jal         0x808003A8
    // 0x808006A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808003A8_bsbwhirl(rdram, ctx);
        goto after_1;
    // 0x808006A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808006AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B4: jal         0x80800430
    // 0x808006B8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80800430_bsbwhirl(rdram, ctx);
        goto after_2;
    // 0x808006B8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x808006BC: jal         0x80800008
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_bsbwhirl(rdram, ctx);
        goto after_3;
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808006C4: jal         0x8008E148
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_4;
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808006CC: beq         $v0, $zero, L_808006E0
    if (ctx->r2 == 0) {
        // 0x808006D0: nop
    
            goto L_808006E0;
    }
    // 0x808006D0: nop

    // 0x808006D4: jal         0x800848B0
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_5;
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808006DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808006E0:
    // 0x808006E0: jal         0x8008E35C
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_6;
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808006E8: beq         $v0, $zero, L_808006F8
    if (ctx->r2 == 0) {
        // 0x808006EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006F8;
    }
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F0: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x808006F4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808006F8:
    // 0x808006F8: jal         0x8009E5C8
    // 0x808006FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x808006FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800704: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800708: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080070C: jr          $ra
    // 0x80800710: nop

    return;
    // 0x80800710: nop

;}
RECOMP_FUNC void chfiregen_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X16D4) << 16);
    // 0x808000D8: jr          $ra
    // 0x808000DC: addiu       $v0, $v0, 0x16D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X16D4));
    return;
    // 0x808000DC: addiu       $v0, $v0, 0x16D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X16D4));
;}
RECOMP_FUNC void func_80110280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110280: addiu       $t6, $a0, 0x98
    ctx->r14 = ADD32(ctx->r4, 0X98);
    // 0x80110284: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80110288: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8011028C: lh          $t7, 0x7340($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7340);
    // 0x80110290: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80110294: addiu       $a2, $a2, 0x7342
    ctx->r6 = ADD32(ctx->r6, 0X7342);
    // 0x80110298: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8011029C: bgez        $a1, L_801102B0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x801102A0: andi        $t8, $a1, 0x3
        ctx->r24 = ctx->r5 & 0X3;
            goto L_801102B0;
    }
    // 0x801102A0: andi        $t8, $a1, 0x3
    ctx->r24 = ctx->r5 & 0X3;
    // 0x801102A4: beq         $t8, $zero, L_801102B0
    if (ctx->r24 == 0) {
        // 0x801102A8: nop
    
            goto L_801102B0;
    }
    // 0x801102A8: nop

    // 0x801102AC: addiu       $t8, $t8, -0x4
    ctx->r24 = ADD32(ctx->r24, -0X4);
L_801102B0:
    // 0x801102B0: beq         $t8, $zero, L_801102D8
    if (ctx->r24 == 0) {
        // 0x801102B4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_801102D8;
    }
    // 0x801102B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801102B8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801102BC: bgez        $t7, L_801102D0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801102C0: andi        $t9, $t7, 0x3
        ctx->r25 = ctx->r15 & 0X3;
            goto L_801102D0;
    }
    // 0x801102C0: andi        $t9, $t7, 0x3
    ctx->r25 = ctx->r15 & 0X3;
    // 0x801102C4: beq         $t9, $zero, L_801102D0
    if (ctx->r25 == 0) {
        // 0x801102C8: nop
    
            goto L_801102D0;
    }
    // 0x801102C8: nop

    // 0x801102CC: addiu       $t9, $t9, -0x4
    ctx->r25 = ADD32(ctx->r25, -0X4);
L_801102D0:
    // 0x801102D0: b           L_801102E0
    // 0x801102D4: subu        $t0, $t1, $t9
    ctx->r8 = SUB32(ctx->r9, ctx->r25);
        goto L_801102E0;
    // 0x801102D4: subu        $t0, $t1, $t9
    ctx->r8 = SUB32(ctx->r9, ctx->r25);
L_801102D8:
    // 0x801102D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x801102DC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_801102E0:
    // 0x801102E0: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x801102E4: addiu       $v0, $v0, 0x98
    ctx->r2 = ADD32(ctx->r2, 0X98);
    // 0x801102E8: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
L_801102EC:
    // 0x801102EC: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x801102F0: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x801102F4: addu        $t3, $a0, $v0
    ctx->r11 = ADD32(ctx->r4, ctx->r2);
    // 0x801102F8: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x801102FC: lh          $a3, 0x0($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X0);
    // 0x80110300: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x80110304: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80110308: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8011030C: bgez        $a1, L_80110320
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80110310: andi        $t6, $a1, 0x3
        ctx->r14 = ctx->r5 & 0X3;
            goto L_80110320;
    }
    // 0x80110310: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x80110314: beq         $t6, $zero, L_80110320
    if (ctx->r14 == 0) {
        // 0x80110318: nop
    
            goto L_80110320;
    }
    // 0x80110318: nop

    // 0x8011031C: addiu       $t6, $t6, -0x4
    ctx->r14 = ADD32(ctx->r14, -0X4);
L_80110320:
    // 0x80110320: beq         $t6, $zero, L_80110344
    if (ctx->r14 == 0) {
        // 0x80110324: addu        $t7, $v0, $a1
        ctx->r15 = ADD32(ctx->r2, ctx->r5);
            goto L_80110344;
    }
    // 0x80110324: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x80110328: bgez        $a3, L_8011033C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8011032C: andi        $t8, $a3, 0x3
        ctx->r24 = ctx->r7 & 0X3;
            goto L_8011033C;
    }
    // 0x8011032C: andi        $t8, $a3, 0x3
    ctx->r24 = ctx->r7 & 0X3;
    // 0x80110330: beq         $t8, $zero, L_8011033C
    if (ctx->r24 == 0) {
        // 0x80110334: nop
    
            goto L_8011033C;
    }
    // 0x80110334: nop

    // 0x80110338: addiu       $t8, $t8, -0x4
    ctx->r24 = ADD32(ctx->r24, -0X4);
L_8011033C:
    // 0x8011033C: b           L_80110348
    // 0x80110340: subu        $t0, $t1, $t8
    ctx->r8 = SUB32(ctx->r9, ctx->r24);
        goto L_80110348;
    // 0x80110340: subu        $t0, $t1, $t8
    ctx->r8 = SUB32(ctx->r9, ctx->r24);
L_80110344:
    // 0x80110344: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80110348:
    // 0x80110348: addu        $v0, $t7, $t0
    ctx->r2 = ADD32(ctx->r15, ctx->r8);
    // 0x8011034C: addu        $t9, $a0, $v0
    ctx->r25 = ADD32(ctx->r4, ctx->r2);
    // 0x80110350: addu        $t5, $a0, $t3
    ctx->r13 = ADD32(ctx->r4, ctx->r11);
    // 0x80110354: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80110358: lh          $a1, 0x2($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X2);
    // 0x8011035C: addiu       $t7, $v1, 0x2
    ctx->r15 = ADD32(ctx->r3, 0X2);
    // 0x80110360: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80110364: bgez        $a1, L_80110378
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80110368: andi        $a3, $a1, 0x3
        ctx->r7 = ctx->r5 & 0X3;
            goto L_80110378;
    }
    // 0x80110368: andi        $a3, $a1, 0x3
    ctx->r7 = ctx->r5 & 0X3;
    // 0x8011036C: beq         $a3, $zero, L_80110378
    if (ctx->r7 == 0) {
        // 0x80110370: nop
    
            goto L_80110378;
    }
    // 0x80110370: nop

    // 0x80110374: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
L_80110378:
    // 0x80110378: beq         $a3, $zero, L_80110388
    if (ctx->r7 == 0) {
        // 0x8011037C: addu        $t6, $v0, $a1
        ctx->r14 = ADD32(ctx->r2, ctx->r5);
            goto L_80110388;
    }
    // 0x8011037C: addu        $t6, $v0, $a1
    ctx->r14 = ADD32(ctx->r2, ctx->r5);
    // 0x80110380: b           L_8011038C
    // 0x80110384: subu        $t0, $t1, $a3
    ctx->r8 = SUB32(ctx->r9, ctx->r7);
        goto L_8011038C;
    // 0x80110384: subu        $t0, $t1, $a3
    ctx->r8 = SUB32(ctx->r9, ctx->r7);
L_80110388:
    // 0x80110388: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8011038C:
    // 0x8011038C: addu        $v0, $t6, $t0
    ctx->r2 = ADD32(ctx->r14, ctx->r8);
    // 0x80110390: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x80110394: addu        $t3, $a0, $t4
    ctx->r11 = ADD32(ctx->r4, ctx->r12);
    // 0x80110398: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8011039C: lh          $a1, 0x4($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X4);
    // 0x801103A0: addiu       $t6, $v1, 0x3
    ctx->r14 = ADD32(ctx->r3, 0X3);
    // 0x801103A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801103A8: bgez        $a1, L_801103BC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x801103AC: andi        $a3, $a1, 0x3
        ctx->r7 = ctx->r5 & 0X3;
            goto L_801103BC;
    }
    // 0x801103AC: andi        $a3, $a1, 0x3
    ctx->r7 = ctx->r5 & 0X3;
    // 0x801103B0: beq         $a3, $zero, L_801103BC
    if (ctx->r7 == 0) {
        // 0x801103B4: nop
    
            goto L_801103BC;
    }
    // 0x801103B4: nop

    // 0x801103B8: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
L_801103BC:
    // 0x801103BC: beq         $a3, $zero, L_801103CC
    if (ctx->r7 == 0) {
        // 0x801103C0: addu        $t9, $v0, $a1
        ctx->r25 = ADD32(ctx->r2, ctx->r5);
            goto L_801103CC;
    }
    // 0x801103C0: addu        $t9, $v0, $a1
    ctx->r25 = ADD32(ctx->r2, ctx->r5);
    // 0x801103C4: b           L_801103D0
    // 0x801103C8: subu        $t0, $t1, $a3
    ctx->r8 = SUB32(ctx->r9, ctx->r7);
        goto L_801103D0;
    // 0x801103C8: subu        $t0, $t1, $a3
    ctx->r8 = SUB32(ctx->r9, ctx->r7);
L_801103CC:
    // 0x801103CC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_801103D0:
    // 0x801103D0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x801103D4: addu        $t5, $a0, $v0
    ctx->r13 = ADD32(ctx->r4, ctx->r2);
    // 0x801103D8: addu        $t4, $a0, $t7
    ctx->r12 = ADD32(ctx->r4, ctx->r15);
    // 0x801103DC: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x801103E0: lh          $a1, 0x6($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X6);
    // 0x801103E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801103E8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x801103EC: bgez        $a1, L_80110400
    if (SIGNED(ctx->r5) >= 0) {
        // 0x801103F0: andi        $a3, $a1, 0x3
        ctx->r7 = ctx->r5 & 0X3;
            goto L_80110400;
    }
    // 0x801103F0: andi        $a3, $a1, 0x3
    ctx->r7 = ctx->r5 & 0X3;
    // 0x801103F4: beq         $a3, $zero, L_80110400
    if (ctx->r7 == 0) {
        // 0x801103F8: nop
    
            goto L_80110400;
    }
    // 0x801103F8: nop

    // 0x801103FC: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
L_80110400:
    // 0x80110400: beq         $a3, $zero, L_80110410
    if (ctx->r7 == 0) {
        // 0x80110404: addu        $t8, $v0, $a1
        ctx->r24 = ADD32(ctx->r2, ctx->r5);
            goto L_80110410;
    }
    // 0x80110404: addu        $t8, $v0, $a1
    ctx->r24 = ADD32(ctx->r2, ctx->r5);
    // 0x80110408: b           L_80110414
    // 0x8011040C: subu        $t0, $t1, $a3
    ctx->r8 = SUB32(ctx->r9, ctx->r7);
        goto L_80110414;
    // 0x8011040C: subu        $t0, $t1, $a3
    ctx->r8 = SUB32(ctx->r9, ctx->r7);
L_80110410:
    // 0x80110410: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80110414:
    // 0x80110414: bne         $v1, $t2, L_801102EC
    if (ctx->r3 != ctx->r10) {
        // 0x80110418: addu        $v0, $t8, $t0
        ctx->r2 = ADD32(ctx->r24, ctx->r8);
            goto L_801102EC;
    }
    // 0x80110418: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8011041C: jr          $ra
    // 0x80110420: nop

    return;
    // 0x80110420: nop

;}
RECOMP_FUNC void _subaddiefind_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C30: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C30);
    return;
    // 0x80089C34: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800B1110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1110: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800B1114: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800B1118: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800B111C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800B1120: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800B1124: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800B1128: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800B112C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800B1130: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800B1134: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800B1138: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800B113C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x800B1140: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x800B1144: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800B1148: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800B114C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800B1150: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800B1154: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B1158: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800B115C: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x800B1160: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B1164: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B1168: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B116C: addu        $s0, $t7, $a0
    ctx->r16 = ADD32(ctx->r15, ctx->r4);
    // 0x800B1170: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B1174: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800B1178: addu        $s2, $t9, $s0
    ctx->r18 = ADD32(ctx->r25, ctx->r16);
    // 0x800B117C: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800B1180: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800B1184: beq         $at, $zero, L_800B12DC
    if (ctx->r1 == 0) {
        // 0x800B1188: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_800B12DC;
    }
    // 0x800B1188: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800B118C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B1190: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800B1194: lwc1        $f28, 0xD8($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800B1198: addiu       $fp, $sp, 0xA4
    ctx->r30 = ADD32(ctx->r29, 0XA4);
    // 0x800B119C: lw          $s7, 0xD4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XD4);
    // 0x800B11A0: lw          $s6, 0xD0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD0);
    // 0x800B11A4: lw          $s3, 0xDC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XDC);
    // 0x800B11A8: addiu       $s1, $sp, 0xB0
    ctx->r17 = ADD32(ctx->r29, 0XB0);
    // 0x800B11AC: lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD);
L_800B11B0:
    // 0x800B11B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B11B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B11B8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B11BC: sllv        $t1, $t0, $v0
    ctx->r9 = S32(ctx->r8 << (ctx->r2 & 31));
    // 0x800B11C0: and         $t2, $t1, $s3
    ctx->r10 = ctx->r9 & ctx->r19;
    // 0x800B11C4: bne         $t2, $zero, L_800B12CC
    if (ctx->r10 != 0) {
        // 0x800B11C8: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_800B12CC;
    }
    // 0x800B11C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800B11CC: jal         0x800EE88C
    // 0x800B11D0: div.s       $f20, $f28, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = DIV_S(ctx->f28.fl, ctx->f26.fl);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x800B11D0: div.s       $f20, $f28, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = DIV_S(ctx->f28.fl, ctx->f26.fl);
    after_0:
    // 0x800B11D4: lbu         $t3, 0xA($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XA);
    // 0x800B11D8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800B11DC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800B11E0: nop

    // 0x800B11E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B11E8: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x800B11EC: lbu         $t5, 0xB($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XB);
    // 0x800B11F0: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800B11F4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800B11F8: nop

    // 0x800B11FC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B1200: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x800B1204: lbu         $t7, 0xC($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XC);
    // 0x800B1208: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B120C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B1210: nop

    // 0x800B1214: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B1218: swc1        $f18, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f18.u32l;
    // 0x800B121C: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800B1220: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x800B1224: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B1228: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800B122C: cvt.s.w     $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    ctx->f24.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B1230: jal         0x80019CD4
    // 0x800B1234: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    func_80019CD4(rdram, ctx);
        goto after_1;
    // 0x800B1234: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    after_1:
    // 0x800B1238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B123C: jal         0x80019924
    // 0x800B1240: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_80019924(rdram, ctx);
        goto after_2;
    // 0x800B1240: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_2:
    // 0x800B1244: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800B1248: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B124C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800B1250: jal         0x8001980C
    // 0x800B1254: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_8001980C(rdram, ctx);
        goto after_3;
    // 0x800B1254: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_3:
    // 0x800B1258: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800B125C: jal         0x800193C4
    // 0x800B1260: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800193C4(rdram, ctx);
        goto after_4;
    // 0x800B1260: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_4:
    // 0x800B1264: mul.s       $f0, $f22, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x800B1268: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B126C: sub.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x800B1270: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x800B1274: nop

    // 0x800B1278: bc1tl       L_800B12D0
    if (c1cs) {
        // 0x800B127C: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800B12D0;
    }
    goto skip_0;
    // 0x800B127C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_0:
    // 0x800B1280: add.s       $f16, $f2, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x800B1284: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B1288: lwc1        $f12, 0x88($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B128C: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800B1290: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x800B1294: nop

    // 0x800B1298: bc1tl       L_800B12D0
    if (c1cs) {
        // 0x800B129C: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800B12D0;
    }
    goto skip_1;
    // 0x800B129C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_1:
    // 0x800B12A0: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B12A4: add.s       $f0, $f20, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x800B12A8: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800B12AC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B12B0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B12B4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x800B12B8: nop

    // 0x800B12BC: bc1tl       L_800B12D0
    if (c1cs) {
        // 0x800B12C0: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800B12D0;
    }
    goto skip_2;
    // 0x800B12C0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_2:
    // 0x800B12C4: b           L_800B12E0
    // 0x800B12C8: lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD);
        goto L_800B12E0;
    // 0x800B12C8: lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD);
L_800B12CC:
    // 0x800B12CC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_800B12D0:
    // 0x800B12D0: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800B12D4: bnel        $at, $zero, L_800B11B0
    if (ctx->r1 != 0) {
        // 0x800B12D8: lbu         $v0, 0xD($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0XD);
            goto L_800B11B0;
    }
    goto skip_3;
    // 0x800B12D8: lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD);
    skip_3:
L_800B12DC:
    // 0x800B12DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B12E0:
    // 0x800B12E0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800B12E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800B12E8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800B12EC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800B12F0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800B12F4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800B12F8: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x800B12FC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800B1300: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800B1304: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800B1308: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800B130C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800B1310: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800B1314: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800B1318: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800B131C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800B1320: jr          $ra
    // 0x800B1324: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800B1324: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_80800CE0_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CE8: jal         0x80084C40
    // 0x80800CEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bafly_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x80800CEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CF0: jal         0x808002E4
    // 0x80800CF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808002E4_bsbeefly(rdram, ctx);
        goto after_1;
    // 0x80800CF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800CF8: jal         0x80082830
    // 0x80800CFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800CFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D08: jr          $ra
    // 0x80800D0C: nop

    return;
    // 0x80800D0C: nop

;}
RECOMP_FUNC void func_80801180_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801180: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801184: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80801188: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080118C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80801190: beq         $a1, $at, L_808011B8
    if (ctx->r5 == ctx->r1) {
        // 0x80801194: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_808011B8;
    }
    // 0x80801194: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80801198: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080119C: beq         $a1, $at, L_808012C8
    if (ctx->r5 == ctx->r1) {
        // 0x808011A0: addiu       $a0, $zero, 0x358
        ctx->r4 = ADD32(0, 0X358);
            goto L_808012C8;
    }
    // 0x808011A0: addiu       $a0, $zero, 0x358
    ctx->r4 = ADD32(0, 0X358);
    // 0x808011A4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808011A8: beq         $a1, $at, L_808012A0
    if (ctx->r5 == ctx->r1) {
        // 0x808011AC: addiu       $a0, $zero, 0x359
        ctx->r4 = ADD32(0, 0X359);
            goto L_808012A0;
    }
    // 0x808011AC: addiu       $a0, $zero, 0x359
    ctx->r4 = ADD32(0, 0X359);
    // 0x808011B0: b           L_80801328
    // 0x808011B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801328;
    // 0x808011B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011B8:
    // 0x808011B8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x808011BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808011C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808011C4: jal         0x800EE7F8
    // 0x808011C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808011C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808011CC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x808011D0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808011D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808011D8: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x808011DC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808011E0: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x808011E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808011E8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808011EC: jal         0x800EF1B8
    // 0x808011F0: nop

    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808011F0: nop

    after_1:
    // 0x808011F4: jal         0x800F54E4
    // 0x808011F8: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808011F8: nop

    after_2:
    // 0x808011FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801200: jal         0x800F77E8
    // 0x80801204: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F77E8(rdram, ctx);
        goto after_3;
    // 0x80801204: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80801208: jal         0x800F54E4
    // 0x8080120C: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x8080120C: nop

    after_4:
    // 0x80801210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801214: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801218: jal         0x800F8300
    // 0x8080121C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800F8300(rdram, ctx);
        goto after_5;
    // 0x8080121C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80801220: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80801224: jal         0x80102424
    // 0x80801228: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80801228: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x8080122C: jal         0x8010A570
    // 0x80801230: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x80801230: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_7:
    // 0x80801234: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80801238: jal         0x80106790
    // 0x8080123C: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    func_80106790(rdram, ctx);
        goto after_8;
    // 0x8080123C: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    after_8:
    // 0x80801240: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80801244: jal         0x80106790
    // 0x80801248: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    func_80106790(rdram, ctx);
        goto after_9;
    // 0x80801248: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    after_9:
    // 0x8080124C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80801250: jal         0x8010A624
    // 0x80801254: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8010A624(rdram, ctx);
        goto after_10;
    // 0x80801254: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_10:
    // 0x80801258: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8080125C: jal         0x80102424
    // 0x80801260: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80801260: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80801264: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80801268: jal         0x80103110
    // 0x8080126C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_12;
    // 0x8080126C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80801270: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80801274: addiu       $a0, $zero, 0xBC
    ctx->r4 = ADD32(0, 0XBC);
    // 0x80801278: lbu         $t0, 0x65($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X65);
    // 0x8080127C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80801280: jal         0x800DA544
    // 0x80801284: sb          $t1, 0x65($t8)
    MEM_B(0X65, ctx->r24) = ctx->r9;
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x80801284: sb          $t1, 0x65($t8)
    MEM_B(0X65, ctx->r24) = ctx->r9;
    after_13:
    // 0x80801288: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080128C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80801290: jal         0x808008B4
    // 0x80801294: addiu       $a2, $zero, 0x820
    ctx->r6 = ADD32(0, 0X820);
    func_808008B4_chtiptup(rdram, ctx);
        goto after_14;
    // 0x80801294: addiu       $a2, $zero, 0x820
    ctx->r6 = ADD32(0, 0X820);
    after_14:
    // 0x80801298: b           L_80801328
    // 0x8080129C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801328;
    // 0x8080129C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808012A0:
    // 0x808012A0: jal         0x80089C30
    // 0x808012A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x808012A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x808012A8: beq         $v0, $zero, L_808012C0
    if (ctx->r2 == 0) {
        // 0x808012AC: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_808012C0;
    }
    // 0x808012AC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x808012B0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x808012B4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x808012B8: b           L_80801324
    // 0x808012BC: sw          $t2, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->r10;
        goto L_80801324;
    // 0x808012BC: sw          $t2, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->r10;
L_808012C0:
    // 0x808012C0: b           L_80801324
    // 0x808012C4: sw          $zero, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = 0;
        goto L_80801324;
    // 0x808012C4: sw          $zero, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = 0;
L_808012C8:
    // 0x808012C8: jal         0x80089C30
    // 0x808012CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x808012CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808012D0: beql        $v0, $zero, L_80801328
    if (ctx->r2 == 0) {
        // 0x808012D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801328;
    }
    goto skip_0;
    // 0x808012D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808012D8: lhu         $t5, 0x72($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X72);
    // 0x808012DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808012E0: addiu       $a1, $zero, 0x1045
    ctx->r5 = ADD32(0, 0X1045);
    // 0x808012E4: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x808012E8: bne         $t6, $at, L_80801324
    if (ctx->r14 != ctx->r1) {
        // 0x808012EC: addiu       $a2, $zero, 0xE
        ctx->r6 = ADD32(0, 0XE);
            goto L_80801324;
    }
    // 0x808012EC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808012F0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808012F4: addiu       $t7, $zero, 0x54
    ctx->r15 = ADD32(0, 0X54);
    // 0x808012F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808012FC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801300: jal         0x8008A208
    // 0x80801304: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x80801304: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_17:
    // 0x80801308: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080130C: jal         0x80102424
    // 0x80801310: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x80801310: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x80801314: b           L_80801328
    // 0x80801318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801328;
    // 0x80801318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080131C: b           L_80801328
    // 0x80801320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801328;
    // 0x80801320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801324:
    // 0x80801324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801328:
    // 0x80801328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080132C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801330: jr          $ra
    // 0x80801334: nop

    return;
    // 0x80801334: nop

    // 0x80801338: nop

    // 0x8080133C: nop

;}
RECOMP_FUNC void _chlavatraindoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F10: syscall     473
    recomp_syscall_handler(rdram, ctx, 0x80086F10);
    return;
    // 0x80086F14: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800350_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800358: jal         0x800DC0C0
    // 0x8080035C: nop

    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x8080035C: nop

    after_0:
    // 0x80800360: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800364: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800368: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X49B4) << 16);
    // 0x8080036C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800370: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800374: nop

    // 0x80800378: bc1f        L_80800388
    if (!c1cs) {
        // 0x8080037C: nop
    
            goto L_80800388;
    }
    // 0x8080037C: nop

    // 0x80800380: b           L_808003A8
    // 0x80800384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003A8;
    // 0x80800384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800388:
    // 0x80800388: lwc1        $f6, 0x49B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X49B4));
    // 0x8080038C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80800390: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800394: nop

    // 0x80800398: bc1f        L_808003A8
    if (!c1cs) {
        // 0x8080039C: nop
    
            goto L_808003A8;
    }
    // 0x8080039C: nop

    // 0x808003A0: b           L_808003A8
    // 0x808003A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003A8;
    // 0x808003A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A8:
    // 0x808003A8: jr          $ra
    // 0x808003AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808003AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void chgameselect_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808078E4: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(804, 0X8504) << 16);
    // 0x808078E8: jr          $ra
    // 0x808078EC: addiu       $v0, $v0, -0x7AFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X8504));
    return;
    // 0x808078EC: addiu       $v0, $v0, -0x7AFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X8504));
;}
RECOMP_FUNC void func_808006E4_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006F4: jal         0x8008CABC
    // 0x808006F8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808006F8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808006FC: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x80800700: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800704: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80800708: jal         0x8008B348
    // 0x8080070C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x8080070C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800710: beq         $v0, $zero, L_80800720
    if (ctx->r2 == 0) {
        // 0x80800714: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800720;
    }
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800718: jal         0x8009FD24
    // 0x8080071C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009FD24(rdram, ctx);
        goto after_2;
    // 0x8080071C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800720:
    // 0x80800720: lui         $a1, 0x3F61
    ctx->r5 = S32(0X3F61 << 16);
    // 0x80800724: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x80800728: jal         0x8008B348
    // 0x8080072C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x8080072C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800730: beq         $v0, $zero, L_80800740
    if (ctx->r2 == 0) {
        // 0x80800734: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800740;
    }
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800738: jal         0x8009FD24
    // 0x8080073C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009FD24(rdram, ctx);
        goto after_4;
    // 0x8080073C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80800740:
    // 0x80800740: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800744: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800748: jal         0x8008B348
    // 0x8080074C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x8080074C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800750: beq         $v0, $zero, L_80800770
    if (ctx->r2 == 0) {
        // 0x80800754: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_80800770;
    }
    // 0x80800754: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800758: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x8080075C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800760: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800768: jal         0x8009DE74
    // 0x8080076C: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_8009DE74(rdram, ctx);
        goto after_6;
    // 0x8080076C: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_6:
L_80800770:
    // 0x80800770: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800774: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800778: jal         0x8008B348
    // 0x8080077C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x8080077C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80800780: beq         $v0, $zero, L_808007A0
    if (ctx->r2 == 0) {
        // 0x80800784: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_808007A0;
    }
    // 0x80800784: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800788: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x8080078C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800790: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: jal         0x8009DE74
    // 0x8080079C: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_8009DE74(rdram, ctx);
        goto after_8;
    // 0x8080079C: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_8:
L_808007A0:
    // 0x808007A0: jal         0x808000B0
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B0_bstntswim(rdram, ctx);
        goto after_9;
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808007A8: jal         0x8009EF10
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_10;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808007B0: bne         $v0, $zero, L_808007BC
    if (ctx->r2 != 0) {
        // 0x808007B4: addiu       $t6, $zero, 0x10F
        ctx->r14 = ADD32(0, 0X10F);
            goto L_808007BC;
    }
    // 0x808007B4: addiu       $t6, $zero, 0x10F
    ctx->r14 = ADD32(0, 0X10F);
    // 0x808007B8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808007BC:
    // 0x808007BC: jal         0x8008E35C
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_11;
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808007C4: bne         $v0, $zero, L_808007D0
    if (ctx->r2 != 0) {
        // 0x808007C8: addiu       $t7, $zero, 0x10C
        ctx->r15 = ADD32(0, 0X10C);
            goto L_808007D0;
    }
    // 0x808007C8: addiu       $t7, $zero, 0x10C
    ctx->r15 = ADD32(0, 0X10C);
    // 0x808007CC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808007D0:
    // 0x808007D0: jal         0x80083F90
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bstnt_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808007D8: beq         $v0, $zero, L_808007E4
    if (ctx->r2 == 0) {
        // 0x808007DC: addiu       $t8, $zero, 0x10E
        ctx->r24 = ADD32(0, 0X10E);
            goto L_808007E4;
    }
    // 0x808007DC: addiu       $t8, $zero, 0x10E
    ctx->r24 = ADD32(0, 0X10E);
    // 0x808007E0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808007E4:
    // 0x808007E4: jal         0x80096500
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096500(rdram, ctx);
        goto after_13;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808007EC: beq         $v0, $zero, L_80800808
    if (ctx->r2 == 0) {
        // 0x808007F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800808;
    }
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F4: jal         0x80091A58
    // 0x808007F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_14;
    // 0x808007F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_14:
    // 0x808007FC: beq         $v0, $zero, L_80800808
    if (ctx->r2 == 0) {
        // 0x80800800: addiu       $t9, $zero, 0x107
        ctx->r25 = ADD32(0, 0X107);
            goto L_80800808;
    }
    // 0x80800800: addiu       $t9, $zero, 0x107
    ctx->r25 = ADD32(0, 0X107);
    // 0x80800804: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800808:
    // 0x80800808: jal         0x80083F70
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bstnt_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800814: jal         0x8009E5C8
    // 0x80800818: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_16;
    // 0x80800818: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_16:
    // 0x8080081C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800820: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800824: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800828: jr          $ra
    // 0x8080082C: nop

    return;
    // 0x8080082C: nop

;}
RECOMP_FUNC void baflamethrower_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080015C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800160: jal         0x80800088
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800088_baflamethrower(rdram, ctx);
        goto after_0;
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800168: jal         0x80084B68
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _baflameline_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
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
RECOMP_FUNC void func_808012EC_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808012F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808012F4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808012F8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808012FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80801300: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80801304: lw          $a1, 0x18($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X18);
    // 0x80801308: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080130C: sll         $t7, $a1, 11
    ctx->r15 = S32(ctx->r5 << 11);
    // 0x80801310: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x80801314: jal         0x80801904
    // 0x80801318: addiu       $a1, $t8, -0x3
    ctx->r5 = ADD32(ctx->r24, -0X3);
    func_80801904_chinflatableboss(rdram, ctx);
        goto after_0;
    // 0x80801318: addiu       $a1, $t8, -0x3
    ctx->r5 = ADD32(ctx->r24, -0X3);
    after_0:
    // 0x8080131C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801320: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80801324: jal         0x800EFB24
    // 0x80801328: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x80801328: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8080132C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80801330: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801334: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801338: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8080133C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801340: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801344: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801348: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8080134C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801350: jal         0x800EF368
    // 0x80801354: nop

    func_800EF368(rdram, ctx);
        goto after_2;
    // 0x80801354: nop

    after_2:
    // 0x80801358: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080135C: jal         0x800EF04C
    // 0x80801360: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80801360: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x80801364: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80801368: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(832, 0X2F2C) << 16);
    // 0x8080136C: addiu       $t1, $t1, 0x2F2C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(832, 0X2F2C));
    // 0x80801370: lw          $a3, 0x38($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X38);
    // 0x80801374: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801378: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080137C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80801380: jal         0x800BABB8
    // 0x80801384: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80801384: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80801388: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2D44) << 16);
    // 0x8080138C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801390: lwc1        $f10, 0x2D44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(832, 0X2D44));
    // 0x80801394: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2D48) << 16);
    // 0x80801398: lwc1        $f4, 0x2D48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(832, 0X2D48));
    // 0x8080139C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808013A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808013A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808013A8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808013AC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808013B0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808013B4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808013B8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808013BC: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x808013C0: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    // 0x808013C4: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x808013C8: jal         0x800BA714
    // 0x808013CC: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    func_800BA714(rdram, ctx);
        goto after_5;
    // 0x808013CC: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    after_5:
    // 0x808013D0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x808013D4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(832, 0X2F0E) << 16);
    // 0x808013D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808013DC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x808013E0: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x808013E4: sll         $t1, $t0, 11
    ctx->r9 = S32(ctx->r8 << 11);
    // 0x808013E8: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x808013EC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x808013F0: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x808013F4: jal         0x800BA670
    // 0x808013F8: lh          $a1, 0x2F0E($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(832, 0X2F0E));
    func_800BA670(rdram, ctx);
        goto after_6;
    // 0x808013F8: lh          $a1, 0x2F0E($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(832, 0X2F0E));
    after_6:
    // 0x808013FC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801400: jal         0x800BA22C
    // 0x80801404: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x80801404: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x80801408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080140C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801410: jr          $ra
    // 0x80801414: nop

    return;
    // 0x80801414: nop

;}
RECOMP_FUNC void func_80021C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021C10: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80021C14: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80021C18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80021C1C: lwc1        $f4, 0x1990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1990);
    // 0x80021C20: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x80021C24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80021C28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80021C2C: nop

    // 0x80021C30: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x80021C34: beq         $a0, $zero, L_80021C74
    if (ctx->r4 == 0) {
        // 0x80021C38: nop
    
            goto L_80021C74;
    }
    // 0x80021C38: nop

L_80021C3C:
    // 0x80021C3C: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x80021C40: beq         $t6, $zero, L_80021C58
    if (ctx->r14 == 0) {
        // 0x80021C44: nop
    
            goto L_80021C58;
    }
    // 0x80021C44: nop

    // 0x80021C48: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80021C4C: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80021C50: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80021C54: swc1        $f16, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f16.u32l;
L_80021C58:
    // 0x80021C58: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80021C5C: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80021C60: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x80021C64: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x80021C68: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80021C6C: bne         $a0, $zero, L_80021C3C
    if (ctx->r4 != 0) {
        // 0x80021C70: nop
    
            goto L_80021C3C;
    }
    // 0x80021C70: nop

L_80021C74:
    // 0x80021C74: b           L_80021C84
    // 0x80021C78: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
        goto L_80021C84;
    // 0x80021C78: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80021C7C: b           L_80021C84
    // 0x80021C80: nop

        goto L_80021C84;
    // 0x80021C80: nop

L_80021C84:
    // 0x80021C84: jr          $ra
    // 0x80021C88: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80021C88: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void ncbadolly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: jr          $ra
    // 0x80800038: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800038: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808014BC_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808014C8: jal         0x800D8FF8
    // 0x808014CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808014CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808014D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808014D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808014D8: lwc1        $f2, 0x28($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X28);
    // 0x808014DC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x808014E0: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x808014E4: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808014E8: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x808014EC: lwc1        $f14, 0x30($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X30);
    // 0x808014F0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808014F4: nop

    // 0x808014F8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808014FC: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80801500: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80801504: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80801508: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8080150C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80801510: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80801514: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80801518: nop

    // 0x8080151C: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80801520: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80801524: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80801528: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8080152C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x80801530: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80801534: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80801538: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8080153C: nop

    // 0x80801540: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80801544: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80801548: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8080154C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80801550: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80801554: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80801558: add.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8080155C: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x80801560: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80801564: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80801568: add.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8080156C: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
    // 0x80801570: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80801574: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80801578: add.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8080157C: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x80801580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801588: jr          $ra
    // 0x8080158C: nop

    return;
    // 0x8080158C: nop

;}
RECOMP_FUNC void func_8080015C_bskazow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800164: jal         0x800845D0
    // 0x80800168: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800168: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080016C: jal         0x800832E8
    // 0x80800170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void _glhittableDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088620: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088620);
    return;
    // 0x80088624: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800EC370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC370: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800EC374: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x800EC378: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x800EC37C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800EC380: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x800EC384: sh          $t9, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r25;
    // 0x800EC388: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800EC38C: lh          $t1, 0x8($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X8);
    // 0x800EC390: jr          $ra
    // 0x800EC394: sh          $t1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r9;
    return;
    // 0x800EC394: sh          $t1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void func_800C0658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C065C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0660: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0664: jal         0x80087E38
    // 0x800C0668: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    _gcdialogexec_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800C0668: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    after_0:
    // 0x800C066C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0674: jr          $ra
    // 0x800C0678: nop

    return;
    // 0x800C0678: nop

;}
RECOMP_FUNC void _chdragonbrothers_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EF0: syscall     470
    recomp_syscall_handler(rdram, ctx, 0x80086EF0);
    return;
    // 0x80086EF4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800BA894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA894: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA89C: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800BA8A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BA8A4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BA8A8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BA8AC: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800BA8B0: swc1        $f12, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f12.u32l;
    // 0x800BA8B4: swc1        $f14, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f14.u32l;
    // 0x800BA8B8: bc1tl       L_800BA8D4
    if (c1cs) {
        // 0x800BA8BC: lwc1        $f12, 0x54($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X54);
            goto L_800BA8D4;
    }
    goto skip_0;
    // 0x800BA8BC: lwc1        $f12, 0x54($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X54);
    skip_0:
    // 0x800BA8C0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800BA8C4: nop

    // 0x800BA8C8: bc1fl       L_800BA8EC
    if (!c1cs) {
        // 0x800BA8CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BA8EC;
    }
    goto skip_1;
    // 0x800BA8CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800BA8D0: lwc1        $f12, 0x54($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X54);
L_800BA8D4:
    // 0x800BA8D4: lwc1        $f14, 0x58($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800BA8D8: jal         0x800DC178
    // 0x800BA8DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x800BA8DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BA8E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BA8E4: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x800BA8E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BA8EC:
    // 0x800BA8EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA8F0: jr          $ra
    // 0x800BA8F4: nop

    return;
    // 0x800BA8F4: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003C8: jal         0x808000C8
    // 0x808003CC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_808000C8_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x808003CC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808003D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003D8: jal         0x8009D2F0
    // 0x808003DC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_1;
    // 0x808003DC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_1:
    // 0x808003E0: jal         0x8008CAEC
    // 0x808003E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baanim_isStopped(rdram, ctx);
        goto after_2;
    // 0x808003E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808003E8: beq         $v0, $zero, L_808003F4
    if (ctx->r2 == 0) {
        // 0x808003EC: addiu       $t6, $zero, 0x48
        ctx->r14 = ADD32(0, 0X48);
            goto L_808003F4;
    }
    // 0x808003EC: addiu       $t6, $zero, 0x48
    ctx->r14 = ADD32(0, 0X48);
    // 0x808003F0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808003F4:
    // 0x808003F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003F8: jal         0x8009E5C8
    // 0x808003FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808003FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800404: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800408: jr          $ra
    // 0x8080040C: nop

    return;
    // 0x8080040C: nop

;}
RECOMP_FUNC void func_8080000C_chpumproomgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8080005C_chcamwaypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_8080005C_chcamwaypoint");
    // 0x8080005C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: jal         0x8008FFE8
    // 0x80800068: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800068: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080006C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800070: jal         0x8010FAE4
    // 0x80800074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FAE4(rdram, ctx);
        goto after_1;
    // 0x80800074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800078: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080007C: bnel        $v0, $at, L_8080011C
    if (ctx->r2 != ctx->r1) {
        // 0x80800080: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080011C;
    }
    goto skip_0;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800084: jal         0x80110014
    // 0x80800088: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80110014(rdram, ctx);
        goto after_2;
    // 0x80800088: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8080008C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800090: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800094: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800098: lhu         $t7, 0x76($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X76);
    // 0x8080009C: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808000A0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808000A4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808000A8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x808000AC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x808000B0: nop

    // 0x808000B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000B8: jal         0x8008FE68
    // 0x808000BC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_8008FE68(rdram, ctx);
        goto after_3;
    // 0x808000BC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x808000C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808000C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808000C8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x808000CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000D0: jal         0x800EFFB4
    // 0x808000D4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800EFFB4(rdram, ctx);
        goto after_4;
    // 0x808000D4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_4:
    // 0x808000D8: bne         $v0, $zero, L_80800100
    if (ctx->r2 != 0) {
        // 0x808000DC: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80800100;
    }
    // 0x808000DC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808000E0: jal         0x801107F0
    // 0x808000E4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801107F0(rdram, ctx);
        goto after_5;
    // 0x808000E4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x808000E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808000EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F0: jal         0x800EFFB4
    // 0x808000F4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800EFFB4(rdram, ctx);
        goto after_6;
    // 0x808000F4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_6:
    // 0x808000F8: beql        $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x808000FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080011C;
    }
    goto skip_1;
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_80800100:
    // 0x80800100: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800104: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800108: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080010C: addiu       $a2, $t0, 0x18
    ctx->r6 = ADD32(ctx->r8, 0X18);
    // 0x80800110: jal         0x80089460
    // 0x80800114: lw          $a3, 0x24($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X24);
    _ncbawaypoint_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800114: lw          $a3, 0x24($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X24);
    after_7:
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080011C:
    // 0x8080011C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

    // 0x80800128: nop

    // 0x8080012C: nop

;}
RECOMP_FUNC void _chbanjocurrent_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AE0: syscall     192
    recomp_syscall_handler(rdram, ctx, 0x80085AE0);
    return;
    // 0x80085AE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800C6A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6A28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C6A2C: addiu       $v0, $v0, -0x55C0
    ctx->r2 = ADD32(ctx->r2, -0X55C0);
    // 0x800C6A30: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
    // 0x800C6A34: sw          $a0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r4;
    // 0x800C6A38: lw          $t7, 0x80($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X80);
    // 0x800C6A3C: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x800C6A40: lw          $t8, 0x80($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X80);
    // 0x800C6A44: sw          $a2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r6;
    // 0x800C6A48: lw          $t9, 0x80($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X80);
    // 0x800C6A4C: sw          $a3, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r7;
    // 0x800C6A50: lw          $t0, 0x80($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X80);
    // 0x800C6A54: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800C6A58: jr          $ra
    // 0x800C6A5C: sw          $t1, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r9;
    return;
    // 0x800C6A5C: sw          $t1, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void func_8008FC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FC50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FC54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FC58: jal         0x8008FB94
    // 0x8008FC5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FB94(rdram, ctx);
        goto after_0;
    // 0x8008FC5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8008FC60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FC64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FC68: jr          $ra
    // 0x8008FC6C: nop

    return;
    // 0x8008FC6C: nop

;}
RECOMP_FUNC void func_800A8670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8670: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A8674: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A8678: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A867C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A8680: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A8684: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A8688: addiu       $s1, $s1, 0x7688
    ctx->r17 = ADD32(ctx->r17, 0X7688);
    // 0x800A868C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A8690: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
L_800A8694:
    // 0x800A8694: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800A8698: beql        $t6, $zero, L_800A86B8
    if (ctx->r14 == 0) {
        // 0x800A869C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800A86B8;
    }
    goto skip_0;
    // 0x800A869C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800A86A0: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800A86A4: beql        $t7, $zero, L_800A86B8
    if (ctx->r15 == 0) {
        // 0x800A86A8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800A86B8;
    }
    goto skip_1;
    // 0x800A86A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x800A86AC: jal         0x800C54F0
    // 0x800A86B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C54F0(rdram, ctx);
        goto after_0;
    // 0x800A86B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A86B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800A86B8:
    // 0x800A86B8: bne         $s0, $s2, L_800A8694
    if (ctx->r16 != ctx->r18) {
        // 0x800A86BC: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800A8694;
    }
    // 0x800A86BC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800A86C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A86C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A86C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A86CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A86D0: jr          $ra
    // 0x800A86D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A86D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808018F8_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808018FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801900: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801904: jal         0x80800110
    // 0x80801908: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80800110_chchuffy(rdram, ctx);
        goto after_0;
    // 0x80801908: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x8080190C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80801910: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1700, 0X247C) << 16);
    // 0x80801914: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80801918: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080191C: jal         0x800DA298
    // 0x80801920: lh          $a0, 0x247C($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1700, 0X247C));
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801920: lh          $a0, 0x247C($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1700, 0X247C));
    after_1:
    // 0x80801924: beq         $v0, $zero, L_80801960
    if (ctx->r2 == 0) {
        // 0x80801928: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80801960;
    }
    // 0x80801928: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8080192C: jal         0x80800264
    // 0x80801930: nop

    func_80800264_chchuffy(rdram, ctx);
        goto after_2;
    // 0x80801930: nop

    after_2:
    // 0x80801934: beq         $v0, $zero, L_80801950
    if (ctx->r2 == 0) {
        // 0x80801938: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801950;
    }
    // 0x80801938: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080193C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801940: jal         0x808017D4
    // 0x80801944: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_3;
    // 0x80801944: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80801948: b           L_80801998
    // 0x8080194C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801998;
    // 0x8080194C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801950:
    // 0x80801950: jal         0x808017D4
    // 0x80801954: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_4;
    // 0x80801954: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80801958: b           L_80801998
    // 0x8080195C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801998;
    // 0x8080195C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801960:
    // 0x80801960: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80801964: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1700, 0X247E) << 16);
    // 0x80801968: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8080196C: jal         0x800DA298
    // 0x80801970: lh          $a0, 0x247E($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1700, 0X247E));
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80801970: lh          $a0, 0x247E($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1700, 0X247E));
    after_5:
    // 0x80801974: beq         $v0, $zero, L_8080198C
    if (ctx->r2 == 0) {
        // 0x80801978: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080198C;
    }
    // 0x80801978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080197C: jal         0x808017D4
    // 0x80801980: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_6;
    // 0x80801980: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x80801984: b           L_80801998
    // 0x80801988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801998;
    // 0x80801988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080198C:
    // 0x8080198C: jal         0x800FFAB0
    // 0x80801990: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x80801990: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80801994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801998:
    // 0x80801998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080199C: jr          $ra
    // 0x808019A0: nop

    return;
    // 0x808019A0: nop

;}
RECOMP_FUNC void func_80800350_chdingpot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800354: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800358: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1176, 0X5C8) << 16);
    // 0x8080035C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1176, 0X4B0) << 16);
    // 0x80800360: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80800364: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800368: addiu       $a3, $a3, 0x4B0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1176, 0X4B0));
    // 0x8080036C: addiu       $a2, $a2, 0x5C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1176, 0X5C8));
    // 0x80800370: jal         0x8008A1F0
    // 0x80800374: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800374: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080037C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

;}
RECOMP_FUNC void func_80800C70_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C80: jal         0x800DA298
    // 0x80800C84: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800C84: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    after_0:
    // 0x80800C88: beq         $v0, $zero, L_80800CB0
    if (ctx->r2 == 0) {
        // 0x80800C8C: nop
    
            goto L_80800CB0;
    }
    // 0x80800C8C: nop

    // 0x80800C90: jal         0x80088848
    // 0x80800C94: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800C94: nop

    after_1:
    // 0x80800C98: bne         $v0, $zero, L_80800CB0
    if (ctx->r2 != 0) {
        // 0x80800C9C: nop
    
            goto L_80800CB0;
    }
    // 0x80800C9C: nop

    // 0x80800CA0: jal         0x800FFAB0
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800CA8: b           L_80800D68
    // 0x80800CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D68;
    // 0x80800CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CB0:
    // 0x80800CB0: jal         0x80089F48
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800CB8: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800CBC: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC4: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800CC8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800CCC: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x80800CD0: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80800CD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800CD8: andi        $t1, $a1, 0x1FF
    ctx->r9 = ctx->r5 & 0X1FF;
    // 0x80800CDC: jal         0x80089F50
    // 0x80800CE0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800CE0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_4:
    // 0x80800CE4: jal         0x80088848
    // 0x80800CE8: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x80800CE8: nop

    after_5:
    // 0x80800CEC: beq         $v0, $zero, L_80800D04
    if (ctx->r2 == 0) {
        // 0x80800CF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D04;
    }
    // 0x80800CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF4: jal         0x80102424
    // 0x80800CF8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800CF8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_6:
    // 0x80800CFC: b           L_80800D50
    // 0x80800D00: nop

        goto L_80800D50;
    // 0x80800D00: nop

L_80800D04:
    // 0x80800D04: jal         0x800DA298
    // 0x80800D08: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800D08: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    after_7:
    // 0x80800D0C: beq         $v0, $zero, L_80800D30
    if (ctx->r2 == 0) {
        // 0x80800D10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D30;
    }
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D18: jal         0x80102424
    // 0x80800D1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800D1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800D20: jal         0x8010A590
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_9;
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800D28: b           L_80800D50
    // 0x80800D2C: nop

        goto L_80800D50;
    // 0x80800D2C: nop

L_80800D30:
    // 0x80800D30: jal         0x80102424
    // 0x80800D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x80800D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D3C: jal         0x80103110
    // 0x80800D40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_11;
    // 0x80800D40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800D44: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800D48: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x80800D4C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800D50:
    // 0x80800D50: jal         0x80105BAC
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_12;
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800D58: lbu         $t5, 0x95($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X95);
    // 0x80800D5C: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80800D60: sb          $t6, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r14;
    // 0x80800D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D68:
    // 0x80800D68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D70: jr          $ra
    // 0x80800D74: nop

    return;
    // 0x80800D74: nop

;}
RECOMP_FUNC void _chhoneyb_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B98: syscall     204
    recomp_syscall_handler(rdram, ctx, 0x80085B98);
    return;
    // 0x80085B9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800610_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800610: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800614: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800618: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080061C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1080, 0XB14) << 16);
    // 0x80800620: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800624: jal         0x80086040
    // 0x80800628: addiu       $a1, $a1, 0xB14
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1080, 0XB14));
    _chpowerhut_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800628: addiu       $a1, $a1, 0xB14
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1080, 0XB14));
    after_0:
    // 0x8080062C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800630: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800638: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080063C: beq         $t6, $at, L_8080064C
    if (ctx->r14 == ctx->r1) {
        // 0x80800640: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080064C;
    }
    // 0x80800640: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800644: bnel        $t6, $at, L_8080072C
    if (ctx->r14 != ctx->r1) {
        // 0x80800648: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080072C;
    }
    goto skip_0;
    // 0x80800648: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8080064C:
    // 0x8080064C: jal         0x80100094
    // 0x80800650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800654: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x80800658: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080065C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800660: bnel        $t7, $at, L_80800694
    if (ctx->r15 != ctx->r1) {
        // 0x80800664: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800694;
    }
    goto skip_1;
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800668: jal         0x800BF744
    // 0x8080066C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x8080066C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800670: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800674: jal         0x800BF744
    // 0x80800678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_3;
    // 0x80800678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800680: jal         0x80100094
    // 0x80800684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800688: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080068C: sb          $t8, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r24;
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800694:
    // 0x80800694: jal         0x80100094
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080069C: lbu         $t9, 0x19($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X19);
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A4: bnel        $t9, $zero, L_8080072C
    if (ctx->r25 != 0) {
        // 0x808006A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080072C;
    }
    goto skip_2;
    // 0x808006A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808006AC: jal         0x80100094
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808006B4: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006C0: jal         0x80100094
    // 0x808006C4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x808006C4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x808006C8: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x808006CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808006D0: bnel        $t0, $at, L_808006E4
    if (ctx->r8 != ctx->r1) {
        // 0x808006D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006E4;
    }
    goto skip_3;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808006D8: jal         0x808009FC
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009FC_chpowerhutwitchy(rdram, ctx);
        goto after_8;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006E4:
    // 0x808006E4: jal         0x80100094
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808006EC: lh          $t1, 0xC($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XC);
    // 0x808006F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006F4: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808006F8: bne         $t1, $at, L_80800728
    if (ctx->r9 != ctx->r1) {
        // 0x808006FC: lui         $a3, 0x3E99
        ctx->r7 = S32(0X3E99 << 16);
            goto L_80800728;
    }
    // 0x808006FC: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80800700: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800704: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800708: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080070C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800710: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800714: jal         0x800F10B4
    // 0x80800718: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x80800718: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x8080071C: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800720: jal         0x80800890
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800890_chpowerhutwitchy(rdram, ctx);
        goto after_11;
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_80800728:
    // 0x80800728: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080072C:
    // 0x8080072C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800730: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800734: jr          $ra
    // 0x80800738: nop

    return;
    // 0x80800738: nop

;}
