#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080098C_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080098C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800990: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800994: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800998: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080099C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808009A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808009A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808009AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808009B0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x808009B4: jal         0x80087D08
    // 0x808009B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808009B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808009BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(868, 0XE4C) << 16);
    // 0x808009C0: lwc1        $f6, 0xE4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(868, 0XE4C));
    // 0x808009C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808009C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808009D0: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x808009D4: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x808009D8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x808009DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808009E0: jal         0x80087DD8
    // 0x808009E4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_1;
    // 0x808009E4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x808009E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808009EC: jal         0x80087D98
    // 0x808009F0: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_2;
    // 0x808009F0: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_2:
    // 0x808009F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009FC: jr          $ra
    // 0x80800A00: nop

    return;
    // 0x80800A00: nop

;}
RECOMP_FUNC void func_80092258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092258: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009225C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80092260: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80092264: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80092268: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x8009226C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80092270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092274: lbu         $t6, 0x88($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X88);
    // 0x80092278: beql        $t6, $zero, L_80092294
    if (ctx->r14 == 0) {
        // 0x8009227C: lbu         $t8, 0x14($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X14);
            goto L_80092294;
    }
    goto skip_0;
    // 0x8009227C: lbu         $t8, 0x14($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X14);
    skip_0:
    // 0x80092280: lbu         $t7, 0x8C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8C);
    // 0x80092284: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80092288: b           L_800922A0
    // 0x8009228C: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
        goto L_800922A0;
    // 0x8009228C: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80092290: lbu         $t8, 0x14($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X14);
L_80092294:
    // 0x80092294: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80092298: nop

    // 0x8009229C: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
L_800922A0:
    // 0x800922A0: jal         0x8009AD78
    // 0x800922A4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8009AD78(rdram, ctx);
        goto after_0;
    // 0x800922A4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x800922A8: beq         $v0, $zero, L_80092300
    if (ctx->r2 == 0) {
        // 0x800922AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80092300;
    }
    // 0x800922AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800922B0: sb          $zero, 0x33($sp)
    MEM_B(0X33, ctx->r29) = 0;
    // 0x800922B4: jal         0x80093DF4
    // 0x800922B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80093DF4(rdram, ctx);
        goto after_1;
    // 0x800922B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x800922BC: beql        $v0, $zero, L_800922F0
    if (ctx->r2 == 0) {
        // 0x800922C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800922F0;
    }
    goto skip_1;
    // 0x800922C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800922C4: jal         0x800A89F8
    // 0x800922C8: nop

    func_800A89F8(rdram, ctx);
        goto after_2;
    // 0x800922C8: nop

    after_2:
    // 0x800922CC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800922D0: jal         0x800A4C68
    // 0x800922D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_3;
    // 0x800922D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800922D8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800922DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800922E0: bnel        $v0, $t9, L_800922F0
    if (ctx->r2 != ctx->r25) {
        // 0x800922E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800922F0;
    }
    goto skip_2;
    // 0x800922E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x800922E8: sb          $t0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r8;
    // 0x800922EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800922F0:
    // 0x800922F0: jal         0x800854B8
    // 0x800922F4: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    _bainvisible_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x800922F4: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    after_4:
    // 0x800922F8: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800922FC: nop

L_80092300:
    // 0x80092300: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80092304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80092308: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8009230C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80092310: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80092314: cvt.w.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = CVT_W_S(ctx->f20.fl);
    // 0x80092318: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8009231C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80092320: nop

    // 0x80092324: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80092328: beql        $v0, $zero, L_80092378
    if (ctx->r2 == 0) {
        // 0x8009232C: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_80092378;
    }
    goto skip_3;
    // 0x8009232C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x80092330: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80092334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80092338: sub.s       $f8, $f20, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x8009233C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80092340: nop

    // 0x80092344: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80092348: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8009234C: nop

    // 0x80092350: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80092354: bne         $v0, $zero, L_8009236C
    if (ctx->r2 != 0) {
        // 0x80092358: nop
    
            goto L_8009236C;
    }
    // 0x80092358: nop

    // 0x8009235C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80092360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80092364: b           L_80092384
    // 0x80092368: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80092384;
    // 0x80092368: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8009236C:
    // 0x8009236C: b           L_80092384
    // 0x80092370: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80092384;
    // 0x80092370: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80092374: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_80092378:
    // 0x80092378: nop

    // 0x8009237C: bltz        $v0, L_8009236C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80092380: nop
    
            goto L_8009236C;
    }
    // 0x80092380: nop

L_80092384:
    // 0x80092384: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80092388: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x8009238C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80092390: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    ctx->r10 = (gpr)tooie_free_camera_player_alpha((int)ctx->r10);
    // 0x80092394: jr          $ra
    // 0x80092398: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x80092398: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
;}
RECOMP_FUNC void func_800EFA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFA98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EFA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EFAA0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EFAA4: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EFAA8: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EFAAC: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EFAB0: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EFAB4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EFAB8: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800EFABC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EFAC0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EFAC4: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800EFAC8: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x800EFACC: nop

    // 0x800EFAD0: bc1t        L_800EFB0C
    if (c1cs) {
        // 0x800EFAD4: nop
    
            goto L_800EFB0C;
    }
    // 0x800EFAD4: nop

    // 0x800EFAD8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800EFADC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EFAE0: jal         0x8002DCA0
    // 0x800EFAE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EFAE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800EFAE8: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EFAEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800EFAF0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800EFAF4: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800EFAF8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800EFAFC: jal         0x800EFA20
    // 0x800EFB00: nop

    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x800EFB00: nop

    after_1:
    // 0x800EFB04: b           L_800EFB18
    // 0x800EFB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EFB18;
    // 0x800EFB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EFB0C:
    // 0x800EFB0C: jal         0x800EE7F8
    // 0x800EFB10: nop

    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800EFB10: nop

    after_2:
    // 0x800EFB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EFB18:
    // 0x800EFB18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EFB1C: jr          $ra
    // 0x800EFB20: nop

    return;
    // 0x800EFB20: nop

;}
RECOMP_FUNC void func_80800D98_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DA4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800DA8: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x80800DAC: jal         0x800914FC
    // 0x80800DB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800914FC(rdram, ctx);
        goto after_0;
    // 0x80800DB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800DB4: jal         0x80085158
    // 0x80800DB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baspin_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800DB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800DBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DC0: bne         $v0, $at, L_80800DCC
    if (ctx->r2 != ctx->r1) {
        // 0x80800DC4: addiu       $t6, $zero, 0x2B
        ctx->r14 = ADD32(0, 0X2B);
            goto L_80800DCC;
    }
    // 0x80800DC4: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x80800DC8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800DCC:
    // 0x80800DCC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800DD0: jal         0x8009E5C8
    // 0x80800DD4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800DD4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DE0: jr          $ra
    // 0x80800DE4: nop

    return;
    // 0x80800DE4: nop

;}
RECOMP_FUNC void _bamovegoto_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E20: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084E20);
    return;
    // 0x80084E24: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void glcutDll_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080056C: jal         0x800EA05C
    // 0x80800570: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800570: nop

    after_0:
    // 0x80800574: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800578: lh          $t6, 0x75EA($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X75EA);
    // 0x8080057C: bne         $v0, $t6, L_8080059C
    if (ctx->r2 != ctx->r14) {
        // 0x80800580: nop
    
            goto L_8080059C;
    }
    // 0x80800580: nop

    // 0x80800584: jal         0x80800018
    // 0x80800588: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80800018_glcutDll(rdram, ctx);
        goto after_1;
    // 0x80800588: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x8080058C: jal         0x80800018
    // 0x80800590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800018_glcutDll(rdram, ctx);
        goto after_2;
    // 0x80800590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800594: b           L_808005A8
    // 0x80800598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808005A8;
    // 0x80800598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080059C:
    // 0x8080059C: jal         0x80800018
    // 0x808005A0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80800018_glcutDll(rdram, ctx);
        goto after_3;
    // 0x808005A0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x808005A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005A8:
    // 0x808005A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005AC: jr          $ra
    // 0x808005B0: nop

    return;
    // 0x808005B0: nop

;}
RECOMP_FUNC void func_80802594_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080259C: jal         0x800A3280
    // 0x808025A0: nop

    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x808025A0: nop

    after_0:
    // 0x808025A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808025A8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808025AC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x808025B0: lui         $t7, 0x8081
    ctx->r15 = S32(RELOC_HI16(439, 0XB080) << 16);
    // 0x808025B4: addiu       $t7, $t7, -0x4F80
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(439, 0XB080));
    // 0x808025B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808025BC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x808025C0: jr          $ra
    // 0x808025C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808025C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gcfrontend_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007CC: jal         0x80800450
    // 0x808007D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800450_gcfrontend(rdram, ctx);
        goto after_0;
    // 0x808007D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808007D4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808007D8: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x808007DC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2650, 0XD80) << 16);
    // 0x808007E0: addiu       $t7, $t7, 0xD80
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2650, 0XD80));
    // 0x808007E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808007E8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x808007EC: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x808007F0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x808007F4: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x808007F8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x808007FC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80800800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800804: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x80800808: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8080080C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80800810: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x80800814: jr          $ra
    // 0x80800818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080081C: nop

;}
RECOMP_FUNC void func_8009E9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E9D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E9DC: jr          $ra
    // 0x8009E9E0: sb          $a0, 0x704C($at)
    MEM_B(0X704C, ctx->r1) = ctx->r4;
    return;
    // 0x8009E9E0: sb          $a0, 0x704C($at)
    MEM_B(0X704C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8001C26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C26C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C274: jal         0x8001D31C
    // 0x8001C278: nop

    func_8001D31C(rdram, ctx);
        goto after_0;
    // 0x8001C278: nop

    after_0:
    // 0x8001C27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C284: jr          $ra
    // 0x8001C288: nop

    return;
    // 0x8001C288: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808000FC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80800100: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80800104: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80800108: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080010C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800110: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80800114: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800118: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8080011C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800120: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800124: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800128: lbu         $t6, 0x60($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X60);
    // 0x8080012C: lh          $t0, 0x58($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X58);
    // 0x80800130: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800134: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800138: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8080013C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800140: andi        $t7, $t6, 0xFF01
    ctx->r15 = ctx->r14 & 0XFF01;
    // 0x80800144: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800148: sh          $zero, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = 0;
    // 0x8080014C: sh          $zero, 0x5C($a0)
    MEM_H(0X5C, ctx->r4) = 0;
    // 0x80800150: sb          $t7, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r15;
    // 0x80800154: sh          $zero, 0x5E($a0)
    MEM_H(0X5E, ctx->r4) = 0;
    // 0x80800158: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x8080015C: sb          $t8, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r24;
    // 0x80800160: sw          $t9, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r25;
    // 0x80800164: addiu       $s0, $a0, 0x64
    ctx->r16 = ADD32(ctx->r4, 0X64);
    // 0x80800168: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080016C: swc1        $f20, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f20.u32l;
    // 0x80800170: swc1        $f20, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f20.u32l;
    // 0x80800174: swc1        $f20, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f20.u32l;
    // 0x80800178: swc1        $f20, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f20.u32l;
    // 0x8080017C: blez        $t0, L_80800220
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80800180: swc1        $f4, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
            goto L_80800220;
    }
    // 0x80800180: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80800184: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X1470) << 16);
    // 0x80800188: lwc1        $f28, 0x1470($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X1470));
    // 0x8080018C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X1474) << 16);
    // 0x80800190: lwc1        $f26, 0x1474($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X1474));
    // 0x80800194: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80800198: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8080019C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808001A0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808001A4: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x808001A8: nop

    // 0x808001AC: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
L_808001B0:
    // 0x808001B0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x808001B4: jal         0x800DC178
    // 0x808001B8: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x808001B8: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_0:
    // 0x808001BC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808001C0: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    // 0x808001C4: jal         0x800DC178
    // 0x808001C8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808001C8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_1:
    // 0x808001CC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x808001D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X1478) << 16);
    // 0x808001D4: lwc1        $f14, 0x1478($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X1478));
    // 0x808001D8: jal         0x800DC178
    // 0x808001DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x808001DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x808001E0: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x808001E4: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x808001E8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x808001EC: jal         0x800DC178
    // 0x808001F0: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808001F0: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_3:
    // 0x808001F4: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x808001F8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x808001FC: jal         0x800DC178
    // 0x80800200: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800200: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_4:
    // 0x80800204: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80800208: lh          $t1, 0x58($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X58);
    // 0x8080020C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800210: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x80800214: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800218: bnel        $at, $zero, L_808001B0
    if (ctx->r1 != 0) {
        // 0x8080021C: swc1        $f20, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
            goto L_808001B0;
    }
    goto skip_0;
    // 0x8080021C: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    skip_0:
L_80800220:
    // 0x80800220: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800224: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800228: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080022C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800230: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800234: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800238: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8080023C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80800240: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80800244: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800248: jr          $ra
    // 0x8080024C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080024C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void chfactoryroofbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2280, 0XA50) << 16);
    // 0x808006E0: jr          $ra
    // 0x808006E4: addiu       $v0, $v0, 0xA50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0XA50));
    return;
    // 0x808006E4: addiu       $v0, $v0, 0xA50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0XA50));
;}
RECOMP_FUNC void suexpression_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080033C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800340: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800344: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800348: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080034C: lh          $a0, 0x3A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3A);
    // 0x80800350: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800354: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800358: jal         0x8080017C
    // 0x8080035C: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    suexpression_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080035C: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80800360: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800364: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800368: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8080036C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800370: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800374: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800378: jal         0x80100074
    // 0x8080037C: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x8080037C: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    after_1:
    // 0x80800380: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800384: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800388: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080038C: lh          $a1, 0x3A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3A);
    // 0x80800390: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800394: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800398: jal         0x80800288
    // 0x8080039C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    suexpression_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x8080039C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x808003A0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808003A4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x808003A8: lbu         $t6, 0x95($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X95);
    // 0x808003AC: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x808003B0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x808003B4: andi        $t5, $t4, 0xC
    ctx->r13 = ctx->r12 & 0XC;
    // 0x808003B8: andi        $t7, $t6, 0xFFF3
    ctx->r15 = ctx->r14 & 0XFFF3;
    // 0x808003BC: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x808003C0: sb          $t8, 0x95($v1)
    MEM_B(0X95, ctx->r3) = ctx->r24;
    // 0x808003C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003C8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x808003CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003D0: jr          $ra
    // 0x808003D4: nop

    return;
    // 0x808003D4: nop

;}
RECOMP_FUNC void _chhotwaterpoolbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086420: syscall     323
    recomp_syscall_handler(rdram, ctx, 0x80086420);
    return;
    // 0x80086424: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gczoombox_entrypoint_43(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D34: beql        $a1, $zero, L_80803D50
    if (ctx->r5 == 0) {
        // 0x80803D38: lbu         $t9, 0x1E7($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X1E7);
            goto L_80803D50;
    }
    goto skip_0;
    // 0x80803D38: lbu         $t9, 0x1E7($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E7);
    skip_0:
    // 0x80803D3C: lbu         $t7, 0x1E7($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E7);
    // 0x80803D40: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80803D44: jr          $ra
    // 0x80803D48: sb          $t8, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r24;
    return;
    // 0x80803D48: sb          $t8, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r24;
    // 0x80803D4C: lbu         $t9, 0x1E7($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E7);
L_80803D50:
    // 0x80803D50: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x80803D54: sb          $t0, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r8;
    // 0x80803D58: jr          $ra
    // 0x80803D5C: nop

    return;
    // 0x80803D5C: nop

;}
RECOMP_FUNC void _bskazshock_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083570: syscall     66
    recomp_syscall_handler(rdram, ctx, 0x80083570);
    return;
    // 0x80083574: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800D74_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800D78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D80: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800D84: jal         0x80100094
    // 0x80800D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800D90: jal         0x800DA298
    // 0x80800D94: addiu       $a0, $zero, 0x166
    ctx->r4 = ADD32(0, 0X166);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800D94: addiu       $a0, $zero, 0x166
    ctx->r4 = ADD32(0, 0X166);
    after_1:
    // 0x80800D98: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800D9C: jal         0x800DA298
    // 0x80800DA0: addiu       $a0, $zero, 0x167
    ctx->r4 = ADD32(0, 0X167);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800DA0: addiu       $a0, $zero, 0x167
    ctx->r4 = ADD32(0, 0X167);
    after_2:
    // 0x80800DA4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800DA8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800DAC: jal         0x80087F20
    // 0x80800DB0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    _gcmapsects_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800DB0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x80800DB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800DB8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80800DBC: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80800DC0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80800DC4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80800DC8: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80800DCC: jal         0x80088848
    // 0x80800DD0: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800DD0: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    after_4:
    // 0x80800DD4: beq         $v0, $zero, L_80800DE8
    if (ctx->r2 == 0) {
        // 0x80800DD8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800DE8;
    }
    // 0x80800DD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800DDC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800DE0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80800DE4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800DE8:
    // 0x80800DE8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800DEC: beq         $t8, $zero, L_80800E00
    if (ctx->r24 == 0) {
        // 0x80800DF0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800E00;
    }
    // 0x80800DF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800DF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DF8: nop

    // 0x80800DFC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_80800E00:
    // 0x80800E00: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800E04: beq         $t9, $zero, L_80800E18
    if (ctx->r25 == 0) {
        // 0x80800E08: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800E18;
    }
    // 0x80800E08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E10: nop

    // 0x80800E14: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_80800E18:
    // 0x80800E18: jal         0x80088840
    // 0x80800E1C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x80800E1C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_5:
    // 0x80800E20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800E24: beq         $v0, $zero, L_80800E58
    if (ctx->r2 == 0) {
        // 0x80800E28: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80800E58;
    }
    // 0x80800E28: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800E2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800E30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800E34: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x80800E38: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80800E3C: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x80800E40: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x80800E44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800E48: jal         0x8008A4B0
    // 0x80800E4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800E4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800E50: b           L_80800E94
    // 0x80800E54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_80800E94;
    // 0x80800E54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800E58:
    // 0x80800E58: jal         0x80088840
    // 0x80800E5C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_7;
    // 0x80800E5C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_7:
    // 0x80800E60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800E64: beq         $v0, $zero, L_80800E90
    if (ctx->r2 == 0) {
        // 0x80800E68: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80800E90;
    }
    // 0x80800E68: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800E6C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800E70: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80800E74: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x80800E78: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80800E7C: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x80800E80: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x80800E84: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800E88: jal         0x8008A4B0
    // 0x80800E8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800E8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_80800E90:
    // 0x80800E90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800E94:
    // 0x80800E94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800E98: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800E9C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800EA0: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80800EA4: nop

    // 0x80800EA8: bc1f        L_80800EB8
    if (!c1cs) {
        // 0x80800EAC: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80800EB8;
    }
    // 0x80800EAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800EB0: b           L_80800EBC
    // 0x80800EB4: sh          $t2, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r10;
        goto L_80800EBC;
    // 0x80800EB4: sh          $t2, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r10;
L_80800EB8:
    // 0x80800EB8: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
L_80800EBC:
    // 0x80800EBC: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800EC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800EC4: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80800EC8: nop

    // 0x80800ECC: bc1fl       L_80800EE0
    if (!c1cs) {
        // 0x80800ED0: sh          $zero, 0x24($s0)
        MEM_H(0X24, ctx->r16) = 0;
            goto L_80800EE0;
    }
    goto skip_0;
    // 0x80800ED0: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    skip_0:
    // 0x80800ED4: b           L_80800EE0
    // 0x80800ED8: sh          $t3, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r11;
        goto L_80800EE0;
    // 0x80800ED8: sh          $t3, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r11;
    // 0x80800EDC: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
L_80800EE0:
    // 0x80800EE0: jal         0x800BF744
    // 0x80800EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_9;
    // 0x80800EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800EE8: lh          $t4, 0x10($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X10);
    // 0x80800EEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800EF0: beq         $t4, $zero, L_80800F00
    if (ctx->r12 == 0) {
        // 0x80800EF4: nop
    
            goto L_80800F00;
    }
    // 0x80800EF4: nop

    // 0x80800EF8: b           L_80800F00
    // 0x80800EFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800F00;
    // 0x80800EFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800F00:
    // 0x80800F00: jal         0x800BF744
    // 0x80800F04: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800BF744(rdram, ctx);
        goto after_10;
    // 0x80800F04: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x80800F08: jal         0x800BEA88
    // 0x80800F0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_11;
    // 0x80800F0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80800F10: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800F14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F1C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x80800F20: jal         0x80088888
    // 0x80800F24: addiu       $a3, $s0, 0x2E
    ctx->r7 = ADD32(ctx->r16, 0X2E);
    _glidmake_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800F24: addiu       $a3, $s0, 0x2E
    ctx->r7 = ADD32(ctx->r16, 0X2E);
    after_12:
    // 0x80800F28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800F30: addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    // 0x80800F34: jal         0x80088888
    // 0x80800F38: addiu       $a3, $s0, 0x1A
    ctx->r7 = ADD32(ctx->r16, 0X1A);
    _glidmake_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800F38: addiu       $a3, $s0, 0x1A
    ctx->r7 = ADD32(ctx->r16, 0X1A);
    after_13:
    // 0x80800F3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F40: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    // 0x80800F44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800F48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800F4C: jal         0x80088F28
    // 0x80800F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80800F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F58: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    // 0x80800F5C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800F60: jal         0x80088F28
    // 0x80800F64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_15;
    // 0x80800F64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x80800F68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800F74: jr          $ra
    // 0x80800F78: nop

    return;
    // 0x80800F78: nop

;}
RECOMP_FUNC void func_801113B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801113B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801113BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801113C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801113C4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x801113C8: jal         0x800EFD24
    // 0x801113CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x801113CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x801113D0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x801113D4: lw          $a0, 0x34($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X34);
    // 0x801113D8: jal         0x800EFD24
    // 0x801113DC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x801113DC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_1:
    // 0x801113E0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x801113E4: lw          $a0, 0x34($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X34);
    // 0x801113E8: jal         0x800EFD24
    // 0x801113EC: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x801113EC: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_2:
    // 0x801113F0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801113F4: lw          $a0, 0x34($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X34);
    // 0x801113F8: jal         0x800EFD24
    // 0x801113FC: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x801113FC: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    after_3:
    // 0x80111400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80111408: jr          $ra
    // 0x8011140C: nop

    return;
    // 0x8011140C: nop

;}
RECOMP_FUNC void func_8008E3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E3E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E3EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E3F0: jal         0x80084FE0
    // 0x8008E3F4: nop

    _bashoes_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8008E3F4: nop

    after_0:
    // 0x8008E3F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E3FC: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x8008E400: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008E404: jr          $ra
    // 0x8008E408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008E408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void chcauldronentrydoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2004, 0X550) << 16);
    // 0x808004F4: jr          $ra
    // 0x808004F8: addiu       $v0, $v0, 0x550
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2004, 0X550));
    return;
    // 0x808004F8: addiu       $v0, $v0, 0x550
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2004, 0X550));
;}
RECOMP_FUNC void _gcgoto_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A78: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087A78);
    return;
    // 0x80087A7C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808003A8_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x808003AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003B8: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x808003BC: jal         0x8001B798
    // 0x808003C0: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x808003C0: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    after_0:
    // 0x808003C4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808003C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003D0: jal         0x80089D90
    // 0x808003D4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    _suspline_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808003D4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_1:
    // 0x808003D8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808003DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003E0: jal         0x80089D90
    // 0x808003E4: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    _suspline_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808003E4: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x808003E8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808003EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003F0: jal         0x80089D90
    // 0x808003F4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    _suspline_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808003F4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x808003F8: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x808003FC: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80800400: beq         $t7, $zero, L_80800434
    if (ctx->r15 == 0) {
        // 0x80800404: nop
    
            goto L_80800434;
    }
    // 0x80800404: nop

    // 0x80800408: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8080040C: jal         0x808001F0
    // 0x80800410: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    func_808001F0_ncpoducam(rdram, ctx);
        goto after_4;
    // 0x80800410: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_4:
    // 0x80800414: beq         $v0, $zero, L_8080042C
    if (ctx->r2 == 0) {
        // 0x80800418: nop
    
            goto L_8080042C;
    }
    // 0x80800418: nop

    // 0x8080041C: jal         0x80106790
    // 0x80800420: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800420: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_5:
    // 0x80800424: b           L_80800450
    // 0x80800428: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800450;
    // 0x80800428: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080042C:
    // 0x8080042C: b           L_80800450
    // 0x80800430: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80800450;
    // 0x80800430: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800434:
    // 0x80800434: jal         0x800A5800
    // 0x80800438: lh          $a0, 0x58($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X58);
    func_800A5800(rdram, ctx);
        goto after_6;
    // 0x80800438: lh          $a0, 0x58($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X58);
    after_6:
    // 0x8080043C: jal         0x80085640
    // 0x80800440: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    _cadbfunc_entrypoint_24(rdram, ctx);
        goto after_7;
    // 0x80800440: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x80800444: jal         0x80089C80
    // 0x80800448: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _subaddiefind_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x80800448: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_8:
    // 0x8080044C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800450:
    // 0x80800450: beql        $v1, $zero, L_80800568
    if (ctx->r3 == 0) {
        // 0x80800454: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800568;
    }
    goto skip_0;
    // 0x80800454: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800458: lh          $t8, 0x48($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X48);
    // 0x8080045C: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x80800460: addiu       $a1, $v1, 0x44
    ctx->r5 = ADD32(ctx->r3, 0X44);
    // 0x80800464: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x80800468: beq         $t9, $zero, L_8080047C
    if (ctx->r25 == 0) {
        // 0x8080046C: nop
    
            goto L_8080047C;
    }
    // 0x8080046C: nop

    // 0x80800470: lbu         $t0, 0x63($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X63);
    // 0x80800474: bnel        $t0, $zero, L_808004A4
    if (ctx->r8 != 0) {
        // 0x80800478: lwc1        $f12, 0x44($v1)
        ctx->f12.u32l = MEM_W(ctx->r3, 0X44);
            goto L_808004A4;
    }
    goto skip_1;
    // 0x80800478: lwc1        $f12, 0x44($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X44);
    skip_1:
L_8080047C:
    // 0x8080047C: jal         0x800EE7F8
    // 0x80800480: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80800480: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_9:
    // 0x80800484: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80800488: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x8080048C: jal         0x800EE7F8
    // 0x80800490: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80800490: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    after_10:
    // 0x80800494: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800498: b           L_80800564
    // 0x8080049C: sb          $t1, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r9;
        goto L_80800564;
    // 0x8080049C: sb          $t1, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r9;
    // 0x808004A0: lwc1        $f12, 0x44($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X44);
L_808004A4:
    // 0x808004A4: lwc1        $f14, 0x30($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808004A8: jal         0x800F1DCC
    // 0x808004AC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_800F1DCC(rdram, ctx);
        goto after_11;
    // 0x808004AC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_11:
    // 0x808004B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3098, 0X17D0) << 16);
    // 0x808004B4: lwc1        $f16, 0x17D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3098, 0X17D0));
    // 0x808004B8: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808004BC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x808004C0: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808004C4: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808004C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808004CC: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x808004D0: jal         0x800F1DCC
    // 0x808004D4: lwc1        $f12, 0x48($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_12;
    // 0x808004D4: lwc1        $f12, 0x48($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X48);
    after_12:
    // 0x808004D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3098, 0X17D4) << 16);
    // 0x808004DC: lwc1        $f16, 0x17D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3098, 0X17D4));
    // 0x808004E0: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808004E4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x808004E8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808004EC: lwc1        $f14, 0x38($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808004F0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x808004F4: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x808004F8: jal         0x800F1DCC
    // 0x808004FC: lwc1        $f12, 0x4C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4C);
    func_800F1DCC(rdram, ctx);
        goto after_13;
    // 0x808004FC: lwc1        $f12, 0x4C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4C);
    after_13:
    // 0x80800500: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3098, 0X17D8) << 16);
    // 0x80800504: lwc1        $f16, 0x17D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3098, 0X17D8));
    // 0x80800508: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080050C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80800510: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800514: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800518: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080051C: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800520: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800524: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x80800528: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8080052C: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80800530: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80800534: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80800538: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8080053C: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800540: sub.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x80800544: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80800548: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8080054C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80800550: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800554: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80800558: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080055C: add.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x80800560: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_80800564:
    // 0x80800564: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800568:
    // 0x80800568: addiu       $t2, $s0, 0x30
    ctx->r10 = ADD32(ctx->r16, 0X30);
    // 0x8080056C: addiu       $t3, $s0, 0x24
    ctx->r11 = ADD32(ctx->r16, 0X24);
    // 0x80800570: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80800574: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80800578: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8080057C: jal         0x800EE7F8
    // 0x80800580: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x80800580: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_14:
    // 0x80800584: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800588: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8080058C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80800590: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800594: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800598: jal         0x800EF6A8
    // 0x8080059C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800EF6A8(rdram, ctx);
        goto after_15;
    // 0x8080059C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x808005A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808005A4: jal         0x800EF04C
    // 0x808005A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_16;
    // 0x808005A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_16:
    // 0x808005AC: lh          $t4, 0x48($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X48);
    // 0x808005B0: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x808005B4: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x808005B8: bne         $t5, $zero, L_80800698
    if (ctx->r13 != 0) {
        // 0x808005BC: nop
    
            goto L_80800698;
    }
    // 0x808005BC: nop

    // 0x808005C0: jal         0x800EE7F8
    // 0x808005C4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x808005C4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_17:
    // 0x808005C8: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x808005CC: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x808005D0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808005D4: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x808005D8: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x808005DC: jal         0x800EF6A8
    // 0x808005E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800EF6A8(rdram, ctx);
        goto after_18;
    // 0x808005E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_18:
    // 0x808005E4: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x808005E8: jal         0x800EF04C
    // 0x808005EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_19;
    // 0x808005EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_19:
    // 0x808005F0: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x808005F4: jal         0x800EE7F8
    // 0x808005F8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800EE7F8(rdram, ctx);
        goto after_20;
    // 0x808005F8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_20:
    // 0x808005FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800600: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80800604: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800608: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080060C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80800610: jal         0x800EF5A0
    // 0x80800614: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_21;
    // 0x80800614: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x80800618: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8080061C: jal         0x800EF04C
    // 0x80800620: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800EF04C(rdram, ctx);
        goto after_22;
    // 0x80800620: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_22:
    // 0x80800624: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800628: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8080062C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800630: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80800634: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x80800638: jal         0x800EF6A8
    // 0x8080063C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800EF6A8(rdram, ctx);
        goto after_23;
    // 0x8080063C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_23:
    // 0x80800640: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80800644: jal         0x800EF04C
    // 0x80800648: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_24;
    // 0x80800648: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_24:
    // 0x8080064C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80800650: jal         0x800F1828
    // 0x80800654: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    func_800F1828(rdram, ctx);
        goto after_25;
    // 0x80800654: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_25:
    // 0x80800658: jal         0x800136E4
    // 0x8080065C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_26;
    // 0x8080065C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_26:
    // 0x80800660: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800664: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800668: jal         0x800F1828
    // 0x8080066C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    func_800F1828(rdram, ctx);
        goto after_27;
    // 0x8080066C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    after_27:
    // 0x80800670: jal         0x800136E4
    // 0x80800674: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_28;
    // 0x80800674: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_28:
    // 0x80800678: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x8080067C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80800680: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x80800684: jal         0x800F1DF4
    // 0x80800688: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_29;
    // 0x80800688: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_29:
    // 0x8080068C: jal         0x800136E4
    // 0x80800690: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_30;
    // 0x80800690: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_30:
    // 0x80800694: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
L_80800698:
    // 0x80800698: jal         0x8080021C
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080021C_ncpoducam(rdram, ctx);
        goto after_31;
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808006A0: beq         $v0, $zero, L_808006C8
    if (ctx->r2 == 0) {
        // 0x808006A4: addiu       $a0, $s0, 0x3C
        ctx->r4 = ADD32(ctx->r16, 0X3C);
            goto L_808006C8;
    }
    // 0x808006A4: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x808006A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808006AC: jal         0x800F18FC
    // 0x808006B0: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    func_800F18FC(rdram, ctx);
        goto after_32;
    // 0x808006B0: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_32:
    // 0x808006B4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808006B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808006BC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x808006C0: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x808006C4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_808006C8:
    // 0x808006C8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808006CC: jal         0x80089D98
    // 0x808006D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _suspline_entrypoint_4(rdram, ctx);
        goto after_33;
    // 0x808006D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x808006D4: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x808006D8: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x808006DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808006E0: bnel        $t6, $zero, L_808006F4
    if (ctx->r14 != 0) {
        // 0x808006E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808006F4;
    }
    goto skip_2;
    // 0x808006E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808006E8: jal         0x80089DA0
    // 0x808006EC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    _suspline_entrypoint_5(rdram, ctx);
        goto after_34;
    // 0x808006EC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_34:
    // 0x808006F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006F4:
    // 0x808006F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006F8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x808006FC: jr          $ra
    // 0x80800700: nop

    return;
    // 0x80800700: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801344: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080134C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801350: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801354: jal         0x808000C8
    // 0x80801358: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_808000C8_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x80801358: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x8080135C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801360: jal         0x8009D3A8
    // 0x80801364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x80801364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801368: jal         0x800839E8
    // 0x8080136C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x8080136C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801370: beql        $v0, $zero, L_80801388
    if (ctx->r2 == 0) {
        // 0x80801374: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801388;
    }
    goto skip_0;
    // 0x80801374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801378: jal         0x800839B0
    // 0x8080137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x8080137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801380: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801388:
    // 0x80801388: jal         0x8009E5C8
    // 0x8080138C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x8080138C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080139C: jr          $ra
    // 0x808013A0: nop

    return;
    // 0x808013A0: nop

;}
RECOMP_FUNC void func_80800024_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800034: jal         0x800DC298
    // 0x80800038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80800038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080003C: beq         $v0, $zero, L_80800054
    if (ctx->r2 == 0) {
        // 0x80800040: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800054;
    }
    // 0x80800040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800044: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800048: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080004C: b           L_80800064
    // 0x80800050: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
        goto L_80800064;
    // 0x80800050: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
L_80800054:
    // 0x80800054: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x80800058: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080005C: nop

    // 0x80800060: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
L_80800064:
    // 0x80800064: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800068: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080006C: jal         0x800DC298
    // 0x80800070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80800070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800074: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800078: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080008C;
    }
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080007C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800080: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800084: b           L_8080009C
    // 0x80800088: swc1        $f8, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f8.u32l;
        goto L_8080009C;
    // 0x80800088: swc1        $f8, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f8.u32l;
L_8080008C:
    // 0x8080008C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80800090: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800094: nop

    // 0x80800098: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
L_8080009C:
    // 0x8080009C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808000A0: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808000A4: bgezl       $t8, L_808000B8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000B8;
    }
    goto skip_0;
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000AC: jal         0x8010A570
    // 0x808000B0: nop

    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x808000B0: nop

    after_2:
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000B8:
    // 0x808000B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void func_800A861C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A861C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A8620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A8624: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8628: jal         0x800CA334
    // 0x800A862C: sw          $zero, 0x7678($at)
    MEM_W(0X7678, ctx->r1) = 0;
    func_800CA334(rdram, ctx);
        goto after_0;
    // 0x800A862C: sw          $zero, 0x7678($at)
    MEM_W(0X7678, ctx->r1) = 0;
    after_0:
    // 0x800A8630: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8634: addiu       $v1, $v1, 0x7688
    ctx->r3 = ADD32(ctx->r3, 0X7688);
    // 0x800A8638: sw          $v0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r2;
    // 0x800A863C: jal         0x800E42B4
    // 0x800A8640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E42B4(rdram, ctx);
        goto after_1;
    // 0x800A8640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A8644: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A8648: jal         0x800A84EC
    // 0x800A864C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A84EC(rdram, ctx);
        goto after_2;
    // 0x800A864C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800A8650: jal         0x800C5464
    // 0x800A8654: nop

    func_800C5464(rdram, ctx);
        goto after_3;
    // 0x800A8654: nop

    after_3:
    // 0x800A8658: jal         0x800A89BC
    // 0x800A865C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A89BC(rdram, ctx);
        goto after_4;
    // 0x800A865C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x800A8660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A8664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A8668: jr          $ra
    // 0x800A866C: nop

    return;
    // 0x800A866C: nop

;}
RECOMP_FUNC void gcmapDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B40: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800B44: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800B48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B4C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800B50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800B58: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80800B5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800B60:
    // 0x80800B60: jal         0x80800A94
    // 0x80800B64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800A94_gcmapDll(rdram, ctx);
        goto after_0;
    // 0x80800B64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80800B68: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800B6C: bnel        $s0, $s1, L_80800B60
    if (ctx->r16 != ctx->r17) {
        // 0x80800B70: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800B60;
    }
    goto skip_0;
    // 0x80800B70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80800B74: lw          $t6, 0xC($s2)
    ctx->r14 = MEM_W(ctx->r18, 0XC);
    // 0x80800B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B7C: beql        $t6, $zero, L_80800BA8
    if (ctx->r14 == 0) {
        // 0x80800B80: lw          $t7, 0x38($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X38);
            goto L_80800BA8;
    }
    goto skip_1;
    // 0x80800B80: lw          $t7, 0x38($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X38);
    skip_1:
    // 0x80800B84: jal         0x800D70F8
    // 0x80800B88: lhu         $a0, 0x5A($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X5A);
    func_800D70F8(rdram, ctx);
        goto after_1;
    // 0x80800B88: lhu         $a0, 0x5A($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X5A);
    after_1:
    // 0x80800B8C: lhu         $a0, 0x5A($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X5A);
    // 0x80800B90: jal         0x800D721C
    // 0x80800B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D721C(rdram, ctx);
        goto after_2;
    // 0x80800B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800B98: jal         0x800D6CEC
    // 0x80800B9C: lhu         $a0, 0x5A($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X5A);
    func_800D6CEC(rdram, ctx);
        goto after_3;
    // 0x80800B9C: lhu         $a0, 0x5A($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X5A);
    after_3:
    // 0x80800BA0: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
    // 0x80800BA4: lw          $t7, 0x38($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X38);
L_80800BA8:
    // 0x80800BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BAC: beql        $t7, $zero, L_80800BD8
    if (ctx->r15 == 0) {
        // 0x80800BB0: lw          $a0, 0x17C($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X17C);
            goto L_80800BD8;
    }
    goto skip_2;
    // 0x80800BB0: lw          $a0, 0x17C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X17C);
    skip_2:
    // 0x80800BB4: jal         0x800D70F8
    // 0x80800BB8: lhu         $a0, 0x5C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X5C);
    func_800D70F8(rdram, ctx);
        goto after_4;
    // 0x80800BB8: lhu         $a0, 0x5C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X5C);
    after_4:
    // 0x80800BBC: lhu         $a0, 0x5C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X5C);
    // 0x80800BC0: jal         0x800D721C
    // 0x80800BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D721C(rdram, ctx);
        goto after_5;
    // 0x80800BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800BC8: jal         0x800D6CEC
    // 0x80800BCC: lhu         $a0, 0x5C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X5C);
    func_800D6CEC(rdram, ctx);
        goto after_6;
    // 0x80800BCC: lhu         $a0, 0x5C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X5C);
    after_6:
    // 0x80800BD0: sw          $zero, 0x38($s2)
    MEM_W(0X38, ctx->r18) = 0;
    // 0x80800BD4: lw          $a0, 0x17C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X17C);
L_80800BD8:
    // 0x80800BD8: beq         $a0, $zero, L_80800BE8
    if (ctx->r4 == 0) {
        // 0x80800BDC: nop
    
            goto L_80800BE8;
    }
    // 0x80800BDC: nop

    // 0x80800BE0: jal         0x80088768
    // 0x80800BE4: nop

    _glzone_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800BE4: nop

    after_7:
L_80800BE8:
    // 0x80800BE8: jal         0x800DBFD8
    // 0x80800BEC: lw          $a0, 0x178($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X178);
    func_800DBFD8(rdram, ctx);
        goto after_8;
    // 0x80800BEC: lw          $a0, 0x178($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X178);
    after_8:
    // 0x80800BF0: lbu         $t8, 0x77($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X77);
    // 0x80800BF4: beql        $t8, $zero, L_80800C08
    if (ctx->r24 == 0) {
        // 0x80800BF8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C08;
    }
    goto skip_3;
    // 0x80800BF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800BFC: jal         0x80087F80
    // 0x80800C00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _gcmapsects_entrypoint_16(rdram, ctx);
        goto after_9;
    // 0x80800C00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80800C04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C08:
    // 0x80800C08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C0C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C10: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800C14: jr          $ra
    // 0x80800C18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800C18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void vector_new(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2D70: multu       $a1, $a0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2D74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B2D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2D7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B2D80: mflo        $a2
    ctx->r6 = lo;
    // 0x800B2D84: addiu       $a0, $a2, 0x10
    ctx->r4 = ADD32(ctx->r6, 0X10);
    // 0x800B2D88: jal         0x8001ACCC
    // 0x800B2D8C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800B2D8C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800B2D90: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800B2D94: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800B2D98: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800B2D9C: addu        $t8, $v1, $a2
    ctx->r24 = ADD32(ctx->r3, ctx->r6);
    // 0x800B2DA0: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x800B2DA4: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x800B2DA8: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x800B2DAC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B2DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B2DB8: jr          $ra
    // 0x800B2DBC: nop

    return;
    // 0x800B2DBC: nop

;}
RECOMP_FUNC void _bsbbilldrill_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827A0: syscall     12
    recomp_syscall_handler(rdram, ctx, 0x800827A0);
    return;
    // 0x800827A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _capod_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856F8: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856F8);
    return;
    // 0x800856FC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void bsfirstp_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805208: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080520C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805210: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80805214: jal         0x800F2100
    // 0x80805218: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x80805218: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080521C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80805220: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80805224: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA46C) << 16);
    // 0x80805228: lwc1        $f4, -0x5B94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA46C));
    // 0x8080522C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80805230: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80805234: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80805238: nop

    // 0x8080523C: bc1f        L_80805248
    if (!c1cs) {
        // 0x80805240: nop
    
            goto L_80805248;
    }
    // 0x80805240: nop

    // 0x80805244: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80805248:
    // 0x80805248: jal         0x8008CABC
    // 0x8080524C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x8080524C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80805250: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80805254: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80805258: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8080525C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80805260: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80805264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80805268: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8080526C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80805270: add.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80805274: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80805278: jal         0x8008B1BC
    // 0x8080527C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x8080527C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80805280: jal         0x8008D04C
    // 0x80805284: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8008D04C(rdram, ctx);
        goto after_3;
    // 0x80805284: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80805288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080528C: jal         0x8008B1BC
    // 0x80805290: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80805290: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80805294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80805298: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080529C: jr          $ra
    // 0x808052A0: nop

    return;
    // 0x808052A0: nop

;}
RECOMP_FUNC void func_80800BD0_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800BD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BD8: jal         0x800F54E4
    // 0x80800BDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800BDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800BE4: jal         0x800F6438
    // 0x80800BE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x80800BE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800BEC: beq         $v0, $zero, L_80800C18
    if (ctx->r2 == 0) {
        // 0x80800BF0: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80800C18;
    }
    // 0x80800BF0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800BF4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800BF8: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x80800BFC: sll         $t0, $t8, 19
    ctx->r8 = S32(ctx->r24 << 19);
    // 0x80800C00: bgez        $t0, L_80800C18
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800C04: nop
    
            goto L_80800C18;
    }
    // 0x80800C04: nop

    // 0x80800C08: jal         0x800F6C5C
    // 0x80800C0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F6C5C(rdram, ctx);
        goto after_2;
    // 0x80800C0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800C10: bne         $v0, $zero, L_80800C20
    if (ctx->r2 != 0) {
        // 0x80800C14: nop
    
            goto L_80800C20;
    }
    // 0x80800C14: nop

L_80800C18:
    // 0x80800C18: b           L_80800D04
    // 0x80800C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D04;
    // 0x80800C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C20:
    // 0x80800C20: jal         0x800DA298
    // 0x80800C24: addiu       $a0, $zero, 0x67F
    ctx->r4 = ADD32(0, 0X67F);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800C24: addiu       $a0, $zero, 0x67F
    ctx->r4 = ADD32(0, 0X67F);
    after_3:
    // 0x80800C28: bne         $v0, $zero, L_80800C6C
    if (ctx->r2 != 0) {
        // 0x80800C2C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800C6C;
    }
    // 0x80800C2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C30: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800C34: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x80800C38: addiu       $a1, $zero, 0x10BA
    ctx->r5 = ADD32(0, 0X10BA);
    // 0x80800C3C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80800C40: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800C44: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800C48: jal         0x8008A208
    // 0x80800C4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800C4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80800C50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C54: jal         0x80101FDC
    // 0x80800C58: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800C58: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x80800C5C: jal         0x800DA544
    // 0x80800C60: addiu       $a0, $zero, 0x67F
    ctx->r4 = ADD32(0, 0X67F);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x80800C60: addiu       $a0, $zero, 0x67F
    ctx->r4 = ADD32(0, 0X67F);
    after_6:
    // 0x80800C64: b           L_80800D04
    // 0x80800C68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D04;
    // 0x80800C68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C6C:
    // 0x80800C6C: jal         0x80016B30
    // 0x80800C70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_7;
    // 0x80800C70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800C74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C78: beq         $v0, $at, L_80800C88
    if (ctx->r2 == ctx->r1) {
        // 0x80800C7C: nop
    
            goto L_80800C88;
    }
    // 0x80800C7C: nop

    // 0x80800C80: b           L_80800D04
    // 0x80800C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D04;
    // 0x80800C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C88:
    // 0x80800C88: jal         0x800F6B40
    // 0x80800C8C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F6B40(rdram, ctx);
        goto after_8;
    // 0x80800C8C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80800C90: beq         $v0, $zero, L_80800CA0
    if (ctx->r2 == 0) {
        // 0x80800C94: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800CA0;
    }
    // 0x80800C94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800C98: b           L_80800D04
    // 0x80800C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D04;
    // 0x80800C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CA0:
    // 0x80800CA0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800CA4: jal         0x800F4BB8
    // 0x80800CA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F4BB8(rdram, ctx);
        goto after_9;
    // 0x80800CA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800CAC: bne         $v0, $zero, L_80800CBC
    if (ctx->r2 != 0) {
        // 0x80800CB0: nop
    
            goto L_80800CBC;
    }
    // 0x80800CB0: nop

    // 0x80800CB4: b           L_80800D04
    // 0x80800CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D04;
    // 0x80800CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CBC:
    // 0x80800CBC: jal         0x800F5410
    // 0x80800CC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F5410(rdram, ctx);
        goto after_10;
    // 0x80800CC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80800CC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CC8: beq         $v0, $at, L_80800D00
    if (ctx->r2 == ctx->r1) {
        // 0x80800CCC: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_80800D00;
    }
    // 0x80800CCC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80800CD0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800CD4: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x80800CD8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800CDC: addiu       $a1, $zero, 0x10B9
    ctx->r5 = ADD32(0, 0X10B9);
    // 0x80800CE0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800CE4: jal         0x8008A208
    // 0x80800CE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80800CE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80800CEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800CF0: jal         0x80101FDC
    // 0x80800CF4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x80800CF4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_12:
    // 0x80800CF8: b           L_80800D04
    // 0x80800CFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D04;
    // 0x80800CFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D00:
    // 0x80800D00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D04:
    // 0x80800D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800D0C: jr          $ra
    // 0x80800D10: nop

    return;
    // 0x80800D10: nop

;}
RECOMP_FUNC void _baeggsetup_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A48: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A48);
    return;
    // 0x80084A4C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _badata_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846C8: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846C8);
    return;
    // 0x800846CC: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_80800B60_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800B6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800B70: jal         0x80100094
    // 0x80800B74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800B80: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800B84: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800B88: jal         0x800DC178
    // 0x80800B8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800B8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800B90: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800B94: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800B9C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80800BA0: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80800BA4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80800BA8: lw          $a0, 0x1C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1C);
    // 0x80800BAC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800BB0: jal         0x800C8B84
    // 0x80800BB4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800C8B84(rdram, ctx);
        goto after_2;
    // 0x80800BB4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800BB8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800BBC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800BC0: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80800BC4: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x80800BC8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800BCC: sw          $t0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r8;
    // 0x80800BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BD8: jr          $ra
    // 0x80800BDC: nop

    return;
    // 0x80800BDC: nop

;}
RECOMP_FUNC void gccubesearch_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808002EC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808002F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808002F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808002F8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808002FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800300: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800304: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800308: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8080030C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800310: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800314: jal         0x800BE52C
    // 0x80800318: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800BE52C(rdram, ctx);
        goto after_0;
    // 0x80800318: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8080031C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800320: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800324: sltu        $at, $a0, $t6
    ctx->r1 = ctx->r4 < ctx->r14 ? 1 : 0;
    // 0x80800328: beq         $at, $zero, L_80800360
    if (ctx->r1 == 0) {
        // 0x8080032C: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_80800360;
    }
    // 0x8080032C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
L_80800330:
    // 0x80800330: addu        $a2, $t7, $s2
    ctx->r6 = ADD32(ctx->r15, ctx->r18);
    // 0x80800334: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800338: subu        $a3, $s3, $s0
    ctx->r7 = SUB32(ctx->r19, ctx->r16);
    // 0x8080033C: jal         0x80088C40
    // 0x80800340: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    _gspropmarker_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800340: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800344: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800348: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8080034C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80800350: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80800354: sltu        $at, $a0, $t8
    ctx->r1 = ctx->r4 < ctx->r24 ? 1 : 0;
    // 0x80800358: bnel        $at, $zero, L_80800330
    if (ctx->r1 != 0) {
        // 0x8080035C: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_80800330;
    }
    goto skip_0;
    // 0x8080035C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    skip_0:
L_80800360:
    // 0x80800360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800364: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800368: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080036C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800370: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800374: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800378: jr          $ra
    // 0x8080037C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080037C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _ncbasub_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896F8: syscall     789
    recomp_syscall_handler(rdram, ctx, 0x800896F8);
    return;
    // 0x800896FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsmumswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080022C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800230: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800234: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080023C: jal         0x8008CABC
    // 0x80800240: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800240: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800244: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800248: jal         0x80083808
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsmum_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x8009BCB4
    // 0x80800258: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_2;
    // 0x80800258: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x8080025C: lui         $a1, 0xC3C7
    ctx->r5 = S32(0XC3C7 << 16);
    // 0x80800260: ori         $a1, $a1, 0xFEB8
    ctx->r5 = ctx->r5 | 0XFEB8;
    // 0x80800264: jal         0x8009BCC4
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x800961AC
    // 0x80800274: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_4;
    // 0x80800274: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x8009BC5C
    // 0x80800280: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_5;
    // 0x80800280: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_5:
    // 0x80800284: jal         0x800A046C
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A046C(rdram, ctx);
        goto after_6;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080028C: jal         0x800A3298
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3298(rdram, ctx);
        goto after_7;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800294: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800298: jal         0x8008AF24
    // 0x8080029C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_reset(rdram, ctx);
        goto after_8;
    // 0x8080029C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x808002A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002A4: jal         0x8008AED4
    // 0x808002A8: addiu       $a1, $zero, 0x9D
    ctx->r5 = ADD32(0, 0X9D);
    anctrl_setIndex(rdram, ctx);
        goto after_9;
    // 0x808002A8: addiu       $a1, $zero, 0x9D
    ctx->r5 = ADD32(0, 0X9D);
    after_9:
    // 0x808002AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002B0: jal         0x8008B134
    // 0x808002B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_10;
    // 0x808002B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x808002B8: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x808002BC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808002C0: jal         0x8008B1BC
    // 0x808002C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_11;
    // 0x808002C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x808002C8: lui         $a1, 0x3F24
    ctx->r5 = S32(0X3F24 << 16);
    // 0x808002CC: ori         $a1, $a1, 0x25AF
    ctx->r5 = ctx->r5 | 0X25AF;
    // 0x808002D0: jal         0x8008B24C
    // 0x808002D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_12;
    // 0x808002D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x808002D8: jal         0x8008B064
    // 0x808002DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_13;
    // 0x808002DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x808002E0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808002E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002E8: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x808002EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002F0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808002F4: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x808002F8: lui         $a3, 0xC396
    ctx->r7 = S32(0XC396 << 16);
    // 0x808002FC: jal         0x800F10B4
    // 0x80800300: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x80800300: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80800304: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800308: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x8080030C: jal         0x8009BA58
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_15;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800314: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800318: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800324: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800328: jal         0x8009FFD8
    // 0x8080032C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_16;
    // 0x8080032C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_16:
    // 0x80800330: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800334: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800338: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080033C: jr          $ra
    // 0x80800340: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800340: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080476C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080476C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80804770: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80804774: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80804778: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080477C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80804780: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80804784: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80804788: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080478C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80804790: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80804794: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80804798: jal         0x80106790
    // 0x8080479C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080479C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808047A0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808047A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808047A8: jal         0x80100094
    // 0x808047AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808047AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808047B0: lbu         $t6, 0x79($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X79);
    // 0x808047B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808047B8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808047BC: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x808047C0: bne         $t7, $at, L_80804860
    if (ctx->r15 != ctx->r1) {
        // 0x808047C4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80804860;
    }
    // 0x808047C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808047C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808047CC: lwc1        $f4, 0x50($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X50);
    // 0x808047D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808047D4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x808047D8: nop

    // 0x808047DC: bc1fl       L_80804830
    if (!c1cs) {
        // 0x808047E0: lwc1        $f10, 0x34($s6)
        ctx->f10.u32l = MEM_W(ctx->r22, 0X34);
            goto L_80804830;
    }
    goto skip_0;
    // 0x808047E0: lwc1        $f10, 0x34($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X34);
    skip_0:
    // 0x808047E4: jal         0x800DC128
    // 0x808047E8: lbu         $a1, 0xC5($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XC5);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x808047E8: lbu         $a1, 0xC5($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XC5);
    after_2:
    // 0x808047EC: addu        $t8, $s4, $v0
    ctx->r24 = ADD32(ctx->r20, ctx->r2);
    // 0x808047F0: lbu         $t9, 0xAC($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XAC);
    // 0x808047F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808047F8: bnel        $t9, $at, L_80804814
    if (ctx->r25 != ctx->r1) {
        // 0x808047FC: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80804814;
    }
    goto skip_1;
    // 0x808047FC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_1:
    // 0x80804800: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80804804: nop

    // 0x80804808: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080480C: swc1        $f8, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->f8.u32l;
    // 0x80804810: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_80804814:
    // 0x80804814: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80804818: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080481C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804820: jal         0x800DC178
    // 0x80804824: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80804824: nop

    after_3:
    // 0x80804828: swc1        $f0, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->f0.u32l;
    // 0x8080482C: lwc1        $f10, 0x34($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X34);
L_80804830:
    // 0x80804830: addiu       $a0, $s6, 0x4
    ctx->r4 = ADD32(ctx->r22, 0X4);
    // 0x80804834: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80804838: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8080483C: nop

    // 0x80804840: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80804844: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80804848: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8080484C: addu        $a1, $s4, $t2
    ctx->r5 = ADD32(ctx->r20, ctx->r10);
    // 0x80804850: jal         0x800F1DF4
    // 0x80804854: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    func_800F1DF4(rdram, ctx);
        goto after_4;
    // 0x80804854: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    after_4:
    // 0x80804858: b           L_8080496C
    // 0x8080485C: swc1        $f0, 0x54($s6)
    MEM_W(0X54, ctx->r22) = ctx->f0.u32l;
        goto L_8080496C;
    // 0x8080485C: swc1        $f0, 0x54($s6)
    MEM_W(0X54, ctx->r22) = ctx->f0.u32l;
L_80804860:
    // 0x80804860: jal         0x8080000C
    // 0x80804864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080000C_chdodgemcontrol(rdram, ctx);
        goto after_5;
    // 0x80804864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80804868: lbu         $t3, 0xC2($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0XC2);
    // 0x8080486C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80804870: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80804874: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80804878: bne         $at, $zero, L_808048DC
    if (ctx->r1 != 0) {
        // 0x8080487C: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_808048DC;
    }
    // 0x8080487C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80804880: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CF4) << 16);
    // 0x80804884: lwc1        $f20, 0x4CF4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CF4));
    // 0x80804888: lw          $t4, 0x6C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X6C);
L_8080488C:
    // 0x8080488C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80804890: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80804894: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x80804898: beql        $s0, $t5, L_808048CC
    if (ctx->r16 == ctx->r13) {
        // 0x8080489C: lbu         $t6, 0xC2($s4)
        ctx->r14 = MEM_BU(ctx->r20, 0XC2);
            goto L_808048CC;
    }
    goto skip_2;
    // 0x8080489C: lbu         $t6, 0xC2($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0XC2);
    skip_2:
    // 0x808048A0: jal         0x8080000C
    // 0x808048A4: addiu       $s1, $s5, 0x4
    ctx->r17 = ADD32(ctx->r21, 0X4);
    func_8080000C_chdodgemcontrol(rdram, ctx);
        goto after_6;
    // 0x808048A4: addiu       $s1, $s5, 0x4
    ctx->r17 = ADD32(ctx->r21, 0X4);
    after_6:
    // 0x808048A8: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x808048AC: jal         0x800EEB40
    // 0x808048B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEB40(rdram, ctx);
        goto after_7;
    // 0x808048B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x808048B4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808048B8: nop

    // 0x808048BC: bc1fl       L_808048CC
    if (!c1cs) {
        // 0x808048C0: lbu         $t6, 0xC2($s4)
        ctx->r14 = MEM_BU(ctx->r20, 0XC2);
            goto L_808048CC;
    }
    goto skip_3;
    // 0x808048C0: lbu         $t6, 0xC2($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0XC2);
    skip_3:
    // 0x808048C4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808048C8: lbu         $t6, 0xC2($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0XC2);
L_808048CC:
    // 0x808048CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808048D0: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x808048D4: bnel        $at, $zero, L_8080488C
    if (ctx->r1 != 0) {
        // 0x808048D8: lw          $t4, 0x6C($s6)
        ctx->r12 = MEM_W(ctx->r22, 0X6C);
            goto L_8080488C;
    }
    goto skip_4;
    // 0x808048D8: lw          $t4, 0x6C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X6C);
    skip_4:
L_808048DC:
    // 0x808048DC: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x808048E0: bne         $at, $zero, L_80804960
    if (ctx->r1 != 0) {
        // 0x808048E4: addiu       $a0, $s6, 0x4
        ctx->r4 = ADD32(ctx->r22, 0X4);
            goto L_80804960;
    }
    // 0x808048E4: addiu       $a0, $s6, 0x4
    ctx->r4 = ADD32(ctx->r22, 0X4);
    // 0x808048E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808048EC: lwc1        $f18, 0x50($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X50);
    // 0x808048F0: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x808048F4: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x808048F8: nop

    // 0x808048FC: bc1fl       L_80804970
    if (!c1cs) {
        // 0x80804900: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80804970;
    }
    goto skip_5;
    // 0x80804900: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_5:
    // 0x80804904: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80804908: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080490C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804910: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80804914: jal         0x800DC178
    // 0x80804918: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80804918: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_8:
    // 0x8080491C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80804920: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804924: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80804928: jal         0x800DC178
    // 0x8080492C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x8080492C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_9:
    // 0x80804930: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80804934: addiu       $a0, $s6, 0x4
    ctx->r4 = ADD32(ctx->r22, 0X4);
    // 0x80804938: jal         0x800F1DF4
    // 0x8080493C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800F1DF4(rdram, ctx);
        goto after_10;
    // 0x8080493C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_10:
    // 0x80804940: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80804944: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80804948: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080494C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804950: jal         0x800DC178
    // 0x80804954: swc1        $f0, 0x54($s6)
    MEM_W(0X54, ctx->r22) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80804954: swc1        $f0, 0x54($s6)
    MEM_W(0X54, ctx->r22) = ctx->f0.u32l;
    after_11:
    // 0x80804958: b           L_8080496C
    // 0x8080495C: swc1        $f0, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->f0.u32l;
        goto L_8080496C;
    // 0x8080495C: swc1        $f0, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->f0.u32l;
L_80804960:
    // 0x80804960: jal         0x800F1DF4
    // 0x80804964: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_12;
    // 0x80804964: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    after_12:
    // 0x80804968: swc1        $f0, 0x54($s6)
    MEM_W(0X54, ctx->r22) = ctx->f0.u32l;
L_8080496C:
    // 0x8080496C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80804970:
    // 0x80804970: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80804974: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80804978: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8080497C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80804980: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80804984: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80804988: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8080498C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80804990: jr          $ra
    // 0x80804994: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80804994: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800D225C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D225C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D2260: addiu       $t7, $t7, -0x4BA4
    ctx->r15 = ADD32(ctx->r15, -0X4BA4);
    // 0x800D2264: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D2268: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800D226C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800D2270: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800D2274: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800D2278: addiu       $a2, $a2, -0x4D40
    ctx->r6 = ADD32(ctx->r6, -0X4D40);
    // 0x800D227C: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    // 0x800D2280: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800D2284: beq         $at, $zero, L_800D22BC
    if (ctx->r1 == 0) {
        // 0x800D2288: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_800D22BC;
    }
    // 0x800D2288: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800D228C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
L_800D2290:
    // 0x800D2290: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D2294: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800D2298: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800D229C: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x800D22A0: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800D22A4: bne         $a0, $t1, L_800D22B4
    if (ctx->r4 != ctx->r9) {
        // 0x800D22A8: nop
    
            goto L_800D22B4;
    }
    // 0x800D22A8: nop

    // 0x800D22AC: jr          $ra
    // 0x800D22B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D22B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D22B4:
    // 0x800D22B4: bnel        $at, $zero, L_800D2290
    if (ctx->r1 != 0) {
        // 0x800D22B8: lbu         $v1, 0x0($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X0);
            goto L_800D2290;
    }
    goto skip_0;
    // 0x800D22B8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    skip_0:
L_800D22BC:
    // 0x800D22BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800D22C0: jr          $ra
    // 0x800D22C4: nop

    return;
    // 0x800D22C4: nop

;}
RECOMP_FUNC void _bawandglow_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853E8: syscall     160
    recomp_syscall_handler(rdram, ctx, 0x800853E8);
    return;
    // 0x800853EC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800760_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800760: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800764: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800768: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080076C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800770: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800774: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x80800778: jal         0x8008A0E0
    // 0x8080077C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080077C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800780: beql        $v0, $zero, L_808008B8
    if (ctx->r2 == 0) {
        // 0x80800784: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008B8;
    }
    goto skip_0;
    // 0x80800784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800788: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8080078C: beql        $a0, $zero, L_808008B8
    if (ctx->r4 == 0) {
        // 0x80800790: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008B8;
    }
    goto skip_1;
    // 0x80800790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800794: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800798: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080079C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2276, 0X1B3C) << 16);
    // 0x808007A0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808007A4: beq         $t6, $at, L_808007B8
    if (ctx->r14 == ctx->r1) {
        // 0x808007A8: addiu       $t8, $t8, 0x1B3C
        ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2276, 0X1B3C));
            goto L_808007B8;
    }
    // 0x808007A8: addiu       $t8, $t8, 0x1B3C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2276, 0X1B3C));
    // 0x808007AC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x808007B0: bnel        $t6, $at, L_80800804
    if (ctx->r14 != ctx->r1) {
        // 0x808007B4: lbu         $t1, 0x79($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X79);
            goto L_80800804;
    }
    goto skip_2;
    // 0x808007B4: lbu         $t1, 0x79($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X79);
    skip_2:
L_808007B8:
    // 0x808007B8: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x808007BC: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x808007C0: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x808007C4: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x808007C8: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x808007CC: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x808007D0: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x808007D4: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x808007D8: jal         0x800C8CB8
    // 0x808007DC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    func_800C8CB8(rdram, ctx);
        goto after_1;
    // 0x808007DC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_1:
    // 0x808007E0: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x808007E4: jal         0x800C8E84
    // 0x808007E8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800C8E84(rdram, ctx);
        goto after_2;
    // 0x808007E8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x808007EC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x808007F0: jal         0x800C8FE0
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_3;
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808007F8: b           L_808008B8
    // 0x808007FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008B8;
    // 0x808007FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800800: lbu         $t1, 0x79($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X79);
L_80800804:
    // 0x80800804: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2276, 0X1B48) << 16);
    // 0x80800808: addiu       $t4, $t4, 0x1B48
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2276, 0X1B48));
    // 0x8080080C: srl         $t2, $t1, 4
    ctx->r10 = S32(U32(ctx->r9) >> 4);
    // 0x80800810: beq         $t2, $zero, L_808008AC
    if (ctx->r10 == 0) {
        // 0x80800814: addiu       $t3, $sp, 0x38
        ctx->r11 = ADD32(ctx->r29, 0X38);
            goto L_808008AC;
    }
    // 0x80800814: addiu       $t3, $sp, 0x38
    ctx->r11 = ADD32(ctx->r29, 0X38);
    // 0x80800818: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x8080081C: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x80800820: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2276, 0X1B54) << 16);
    // 0x80800824: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80800828: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x8080082C: addiu       $t7, $t7, 0x1B54
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2276, 0X1B54));
    // 0x80800830: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80800834: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x80800838: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8080083C: addiu       $t9, $sp, 0x2C
    ctx->r25 = ADD32(ctx->r29, 0X2C);
    // 0x80800840: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800844: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80800848: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8080084C: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80800850: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x80800854: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2276, 0X1890) << 16);
    // 0x80800858: lwc1        $f12, 0x1890($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2276, 0X1890));
    // 0x8080085C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800860: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800864: jal         0x800DC178
    // 0x80800868: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800868: nop

    after_4:
    // 0x8080086C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800870: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800874: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800878: jal         0x800F3214
    // 0x8080087C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800F3214(rdram, ctx);
        goto after_5;
    // 0x8080087C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80800880: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80800884: jal         0x800C8CB8
    // 0x80800888: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800C8CB8(rdram, ctx);
        goto after_6;
    // 0x80800888: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_6:
    // 0x8080088C: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80800890: jal         0x800C8E84
    // 0x80800894: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800C8E84(rdram, ctx);
        goto after_7;
    // 0x80800894: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_7:
    // 0x80800898: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8080089C: jal         0x800C8FE0
    // 0x808008A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_8;
    // 0x808008A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808008A4: b           L_808008B8
    // 0x808008A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008B8;
    // 0x808008A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008AC:
    // 0x808008AC: jal         0x800C8FE0
    // 0x808008B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_9;
    // 0x808008B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808008B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008B8:
    // 0x808008B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x808008C0: jr          $ra
    // 0x808008C4: nop

    return;
    // 0x808008C4: nop

;}
RECOMP_FUNC void chstarspinnerctrl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002FC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800300: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800304: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800308: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080030C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80800310: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800314: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800318: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080031C: jal         0x80106790
    // 0x80800320: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800320: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80800324: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800328: jal         0x80100094
    // 0x8080032C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080032C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800330: blez        $s0, L_80800358
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80800334: lwc1        $f20, 0x18($v0)
        ctx->f20.u32l = MEM_W(ctx->r2, 0X18);
            goto L_80800358;
    }
    // 0x80800334: lwc1        $f20, 0x18($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X18);
L_80800338:
    // 0x80800338: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8080033C: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x80800340: jal         0x800F2FD0
    // 0x80800344: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    func_800F2FD0(rdram, ctx);
        goto after_2;
    // 0x80800344: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    after_2:
    // 0x80800348: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8080034C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80800350: bgtz        $s0, L_80800338
    if (SIGNED(ctx->r16) > 0) {
        // 0x80800354: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800338;
    }
    // 0x80800354: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80800358:
    // 0x80800358: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080035C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800360: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800364: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800368: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080036C: jr          $ra
    // 0x80800370: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800370: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080102C_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080102C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801034: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801038: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8080103C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801044: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80801048: bgez        $t8, L_80801088
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080104C: nop
    
            goto L_80801088;
    }
    // 0x8080104C: nop

    // 0x80801050: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x80801054: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80801058: andi        $t9, $a0, 0x1FF
    ctx->r25 = ctx->r4 & 0X1FF;
    // 0x8080105C: jal         0x800D0CC8
    // 0x80801060: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800D0CC8(rdram, ctx);
        goto after_0;
    // 0x80801060: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80801064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801068: jal         0x80800178
    // 0x8080106C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    chjinjo_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080106C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80801070: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801078: lbu         $t0, 0x74($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X74);
    // 0x8080107C: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x80801080: b           L_80801088
    // 0x80801084: sb          $t1, 0x74($a2)
    MEM_B(0X74, ctx->r6) = ctx->r9;
        goto L_80801088;
    // 0x80801084: sb          $t1, 0x74($a2)
    MEM_B(0X74, ctx->r6) = ctx->r9;
L_80801088:
    // 0x80801088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080108C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801090: jr          $ra
    // 0x80801094: nop

    return;
    // 0x80801094: nop

;}
RECOMP_FUNC void func_80809198_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080919C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808091A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808091A4: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x808091A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808091AC: lw          $v0, 0x108($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X108);
    // 0x808091B0: beq         $v0, $zero, L_808091C8
    if (ctx->r2 == 0) {
        // 0x808091B4: nop
    
            goto L_808091C8;
    }
    // 0x808091B4: nop

    // 0x808091B8: beq         $v0, $at, L_808091F8
    if (ctx->r2 == ctx->r1) {
        // 0x808091BC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808091F8;
    }
    // 0x808091BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808091C0: b           L_80809244
    // 0x808091C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80809244;
    // 0x808091C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808091C8:
    // 0x808091C8: jal         0x800D9004
    // 0x808091CC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x808091CC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x808091D0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808091D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808091D8: jal         0x800F1574
    // 0x808091DC: addiu       $a0, $v1, 0x10C
    ctx->r4 = ADD32(ctx->r3, 0X10C);
    func_800F1574(rdram, ctx);
        goto after_1;
    // 0x808091DC: addiu       $a0, $v1, 0x10C
    ctx->r4 = ADD32(ctx->r3, 0X10C);
    after_1:
    // 0x808091E0: beq         $v0, $zero, L_80809240
    if (ctx->r2 == 0) {
        // 0x808091E4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80809240;
    }
    // 0x808091E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808091E8: jal         0x8080911C
    // 0x808091EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080911C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808091EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808091F0: b           L_80809244
    // 0x808091F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80809244;
    // 0x808091F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808091F8:
    // 0x808091F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808091FC: jal         0x8009E674
    // 0x80809200: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8009E674(rdram, ctx);
        goto after_3;
    // 0x80809200: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80809204: beq         $v0, $zero, L_80809218
    if (ctx->r2 == 0) {
        // 0x80809208: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80809218;
    }
    // 0x80809208: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080920C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80809210: b           L_80809238
    // 0x80809214: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_80809238;
    // 0x80809214: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80809218:
    // 0x80809218: lw          $t7, 0x104($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X104);
    // 0x8080921C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA660) << 16);
    // 0x80809220: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80809224: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80809228: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080922C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80809230: lwc1        $f0, -0x59A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA660));
    // 0x80809234: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80809238:
    // 0x80809238: jal         0x8080633C
    // 0x8080923C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8080633C_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x8080923C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
L_80809240:
    // 0x80809240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80809244:
    // 0x80809244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80809248: jr          $ra
    // 0x8080924C: nop

    return;
    // 0x8080924C: nop

;}
RECOMP_FUNC void func_80803080_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80803080_chweldarboss");
    // 0x80803080: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80803084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803088: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8080308C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80803090: jal         0x80100094
    // 0x80803094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803098: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8080309C: jal         0x800F6478
    // 0x808030A0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x808030A0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_1:
    // 0x808030A4: beql        $v0, $zero, L_80803178
    if (ctx->r2 == 0) {
        // 0x808030A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803178;
    }
    goto skip_0;
    // 0x808030A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808030AC: jal         0x800F6590
    // 0x808030B0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    func_800F6590(rdram, ctx);
        goto after_2;
    // 0x808030B0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_2:
    // 0x808030B4: bne         $v0, $zero, L_80803174
    if (ctx->r2 != 0) {
        // 0x808030B8: lw          $a0, 0x64($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X64);
            goto L_80803174;
    }
    // 0x808030B8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808030BC: jal         0x800F5A00
    // 0x808030C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x808030C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x808030C4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x808030C8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808030CC: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    // 0x808030D0: jal         0x800EE7F8
    // 0x808030D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808030D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x808030D8: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x808030DC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808030E0: lui         $a2, 0xC416
    ctx->r6 = S32(0XC416 << 16);
    // 0x808030E4: jal         0x800EF1B8
    // 0x808030E8: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_5;
    // 0x808030E8: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_5:
    // 0x808030EC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808030F0: jal         0x800EEAD4
    // 0x808030F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x808030F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808030F8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808030FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803100: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80803104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803108: lui         $a2, 0x453B
    ctx->r6 = S32(0X453B << 16);
    // 0x8080310C: lui         $a3, 0x4409
    ctx->r7 = S32(0X4409 << 16);
    // 0x80803110: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80803114: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80803118: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080311C: jal         0x800F10B4
    // 0x80803120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80803120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80803124: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80803128: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8080312C: jal         0x800F5D9C
    // 0x80803130: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F5D9C(rdram, ctx);
        goto after_8;
    // 0x80803130: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_8:
    // 0x80803134: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80803138: jal         0x800F1DF4
    // 0x8080313C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F1DF4(rdram, ctx);
        goto after_9;
    // 0x8080313C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_9:
    // 0x80803140: jal         0x800D8FF8
    // 0x80803144: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_10;
    // 0x80803144: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x80803148: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080314C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80803150: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80803154: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80803158: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8080315C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80803160: jal         0x800EF1B8
    // 0x80803164: nop

    func_800EF1B8(rdram, ctx);
        goto after_11;
    // 0x80803164: nop

    after_11:
    // 0x80803168: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8080316C: jal         0x800F8418
    // 0x80803170: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F8418(rdram, ctx);
        goto after_12;
    // 0x80803170: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_12:
L_80803174:
    // 0x80803174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803178:
    // 0x80803178: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080317C: jr          $ra
    // 0x80803180: nop

    return;
    // 0x80803180: nop

;}
RECOMP_FUNC void func_80803B28_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803B30: jal         0x80803A24
    // 0x80803B34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80803A24_chevilmumbo(rdram, ctx);
        goto after_0;
    // 0x80803B34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80803B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803B3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803B40: jr          $ra
    // 0x80803B44: nop

    return;
    // 0x80803B44: nop

;}
RECOMP_FUNC void func_808003D8_cadbmgrDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808003E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003E4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808003E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808003EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808003F4: beq         $a2, $zero, L_80800464
    if (ctx->r6 == 0) {
        // 0x808003F8: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80800464;
    }
    // 0x808003F8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808003FC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800400: addu        $s2, $a0, $t7
    ctx->r18 = ADD32(ctx->r4, ctx->r15);
    // 0x80800404: lw          $t8, -0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, -0X4);
    // 0x80800408: beq         $t8, $zero, L_80800440
    if (ctx->r24 == 0) {
        // 0x8080040C: nop
    
            goto L_80800440;
    }
    // 0x8080040C: nop

    // 0x80800410: jal         0x800A57EC
    // 0x80800414: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800A57EC(rdram, ctx);
        goto after_0;
    // 0x80800414: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800418: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8080041C: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x80800420: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x80800424: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800428: lh          $a0, 0x1E($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X1E);
    // 0x8080042C: mflo        $a1
    ctx->r5 = lo;
    // 0x80800430: jal         0x8001B710
    // 0x80800434: nop

    func_8001B710(rdram, ctx);
        goto after_1;
    // 0x80800434: nop

    after_1:
    // 0x80800438: b           L_80800498
    // 0x8080043C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
        goto L_80800498;
    // 0x8080043C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_80800440:
    // 0x80800440: jal         0x800A57EC
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A57EC(rdram, ctx);
        goto after_2;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800448: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080044C: jal         0x8001B668
    // 0x80800450: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8001B668(rdram, ctx);
        goto after_3;
    // 0x80800450: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80800454: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x80800458: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x8080045C: b           L_80800494
    // 0x80800460: sh          $v0, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r2;
        goto L_80800494;
    // 0x80800460: sh          $v0, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r2;
L_80800464:
    // 0x80800464: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80800468: addu        $s2, $s1, $t4
    ctx->r18 = ADD32(ctx->r17, ctx->r12);
    // 0x8080046C: lw          $t5, -0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, -0X4);
    // 0x80800470: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x80800474: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x80800478: beql        $t5, $zero, L_80800498
    if (ctx->r13 == 0) {
        // 0x8080047C: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_80800498;
    }
    goto skip_0;
    // 0x8080047C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80800480: lh          $a0, 0x1E($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X1E);
    // 0x80800484: jal         0x8001B754
    // 0x80800488: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8001B754(rdram, ctx);
        goto after_4;
    // 0x80800488: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x8080048C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800490: sh          $zero, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = 0;
L_80800494:
    // 0x80800494: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_80800498:
    // 0x80800498: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8080049C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004A0: sw          $t7, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r15;
    // 0x808004A4: sw          $t8, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r24;
    // 0x808004A8: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
    // 0x808004AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808004B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808004B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004BC: jr          $ra
    // 0x808004C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808004C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chconga_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DE0: syscall     242
    recomp_syscall_handler(rdram, ctx, 0x80085DE0);
    return;
    // 0x80085DE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8002AD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD60: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002AD64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002AD68: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8002AD6C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8002AD70: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8002AD74: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8002AD78: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8002AD7C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8002AD80: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8002AD84: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8002AD88: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8002AD8C: sh          $zero, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = 0;
    // 0x8002AD90: addiu       $t9, $zero, 0xB8
    ctx->r25 = ADD32(0, 0XB8);
    // 0x8002AD94: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8002AD98: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x8002AD9C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002ADA0: lw          $t1, 0x7C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X7C);
    // 0x8002ADA4: beq         $t1, $zero, L_8002B620
    if (ctx->r9 == 0) {
        // 0x8002ADA8: nop
    
            goto L_8002B620;
    }
    // 0x8002ADA8: nop

L_8002ADAC:
    // 0x8002ADAC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002ADB0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8002ADB4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002ADB8: lw          $t4, 0x7C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X7C);
    // 0x8002ADBC: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8002ADC0: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8002ADC4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002ADC8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8002ADCC: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x8002ADD0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8002ADD4: addiu       $t9, $t8, 0xB7
    ctx->r25 = ADD32(ctx->r24, 0XB7);
    // 0x8002ADD8: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8002ADDC: mflo        $t0
    ctx->r8 = lo;
    // 0x8002ADE0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002ADE4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8002ADE8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002ADEC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8002ADF0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002ADF4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8002ADF8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8002ADFC: bne         $t2, $zero, L_8002AE0C
    if (ctx->r10 != 0) {
        // 0x8002AE00: nop
    
            goto L_8002AE0C;
    }
    // 0x8002AE00: nop

    // 0x8002AE04: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8002AE08: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_8002AE0C:
    // 0x8002AE0C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8002AE10: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002AE14: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002AE18: beq         $at, $zero, L_8002AE28
    if (ctx->r1 == 0) {
        // 0x8002AE1C: nop
    
            goto L_8002AE28;
    }
    // 0x8002AE1C: nop

    // 0x8002AE20: b           L_8002B620
    // 0x8002AE24: nop

        goto L_8002B620;
    // 0x8002AE24: nop

L_8002AE28:
    // 0x8002AE28: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002AE2C: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x8002AE30: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8002AE34: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x8002AE38: beq         $at, $zero, L_8002B570
    if (ctx->r1 == 0) {
        // 0x8002AE3C: nop
    
            goto L_8002B570;
    }
    // 0x8002AE3C: nop

    // 0x8002AE40: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002AE44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002AE48: addu        $at, $at, $t8
    gpr jr_addend_8002AE50 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8002AE4C: lw          $t8, 0x1D40($at)
    ctx->r24 = ADD32(ctx->r1, 0X1D40);
    // 0x8002AE50: jr          $t8
    // 0x8002AE54: nop

    switch (jr_addend_8002AE50 >> 2) {
        case 0: goto L_8002B498; break;
        case 1: goto L_8002B570; break;
        case 2: goto L_8002B570; break;
        case 3: goto L_8002B570; break;
        case 4: goto L_8002B570; break;
        case 5: goto L_8002B530; break;
        case 6: goto L_8002B570; break;
        case 7: goto L_8002B4C4; break;
        case 8: goto L_8002B4FC; break;
        case 9: goto L_8002B570; break;
        case 10: goto L_8002B570; break;
        case 11: goto L_8002B0CC; break;
        case 12: goto L_8002B0CC; break;
        case 13: goto L_8002AE58; break;
        case 14: goto L_8002B410; break;
        case 15: goto L_8002B460; break;
        case 16: goto L_8002B0CC; break;
        default: switch_error(__func__, 0x8002AE50, 0x80041D40);
    }
    // 0x8002AE54: nop

L_8002AE58:
    // 0x8002AE58: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002AE5C: lw          $t0, 0x7C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X7C);
    // 0x8002AE60: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8002AE64: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AE68: lh          $t2, 0xA($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XA);
    // 0x8002AE6C: beq         $t2, $zero, L_8002AE80
    if (ctx->r10 == 0) {
        // 0x8002AE70: nop
    
            goto L_8002AE80;
    }
    // 0x8002AE70: nop

    // 0x8002AE74: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002AE78: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002AE7C: sw          $t3, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->r11;
L_8002AE80:
    // 0x8002AE80: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AE84: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002AE88: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002AE8C: jal         0x8002CC9C
    // 0x8002AE90: lw          $a2, 0x20($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X20);
    func_8002CC9C(rdram, ctx);
        goto after_0;
    // 0x8002AE90: lw          $a2, 0x20($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X20);
    after_0:
    // 0x8002AE94: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002AE98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002AE9C: sw          $t6, 0x84($t7)
    MEM_W(0X84, ctx->r15) = ctx->r14;
    // 0x8002AEA0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002AEA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002AEA8: sw          $t8, 0x78($t9)
    MEM_W(0X78, ctx->r25) = ctx->r24;
    // 0x8002AEAC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002AEB0: sw          $zero, 0x70($t0)
    MEM_W(0X70, ctx->r8) = 0;
    // 0x8002AEB4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AEB8: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x8002AEBC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002AEC0: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x8002AEC4: addiu       $t3, $t2, 0xB7
    ctx->r11 = ADD32(ctx->r10, 0XB7);
    // 0x8002AEC8: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x8002AECC: mflo        $t4
    ctx->r12 = lo;
    // 0x8002AED0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002AED4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8002AED8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002AEDC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8002AEE0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002AEE4: sw          $t5, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r13;
    // 0x8002AEE8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AEEC: lh          $t8, 0x10($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X10);
    // 0x8002AEF0: addu        $t9, $t8, $t8
    ctx->r25 = ADD32(ctx->r24, ctx->r24);
    // 0x8002AEF4: bgez        $t9, L_8002AF04
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8002AEF8: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8002AF04;
    }
    // 0x8002AEF8: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8002AEFC: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8002AF00: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8002AF04:
    // 0x8002AF04: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8002AF08: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002AF0C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002AF10: sh          $t1, 0x5A($t2)
    MEM_H(0X5A, ctx->r10) = ctx->r9;
    // 0x8002AF14: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AF18: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002AF1C: lbu         $t4, 0x12($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X12);
    // 0x8002AF20: sh          $t4, 0x58($t5)
    MEM_H(0X58, ctx->r13) = ctx->r12;
    // 0x8002AF24: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AF28: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8002AF2C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002AF30: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8002AF34: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x8002AF38: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8002AF3C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002AF40: lh          $t0, 0x1290($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X1290);
    // 0x8002AF44: sra         $t2, $t7, 7
    ctx->r10 = S32(SIGNED(ctx->r15) >> 7);
    // 0x8002AF48: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x8002AF4C: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8002AF50: sh          $t3, 0x60($t4)
    MEM_H(0X60, ctx->r12) = ctx->r11;
    // 0x8002AF54: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8002AF58: lbu         $t5, -0x15D0($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X15D0);
    // 0x8002AF5C: bne         $t5, $zero, L_8002AF74
    if (ctx->r13 != 0) {
        // 0x8002AF60: nop
    
            goto L_8002AF74;
    }
    // 0x8002AF60: nop

    // 0x8002AF64: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002AF68: lh          $t8, 0x60($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X60);
    // 0x8002AF6C: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x8002AF70: sh          $t9, 0x60($t6)
    MEM_H(0X60, ctx->r14) = ctx->r25;
L_8002AF74:
    // 0x8002AF74: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AF78: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8002AF7C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002AF80: lbu         $t7, 0x13($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X13);
    // 0x8002AF84: andi        $t1, $t7, 0x7F
    ctx->r9 = ctx->r15 & 0X7F;
    // 0x8002AF88: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8002AF8C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8002AF90: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8002AF94: lh          $t4, 0x138E($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X138E);
    // 0x8002AF98: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x8002AF9C: sh          $t5, 0x62($t8)
    MEM_H(0X62, ctx->r24) = ctx->r13;
    // 0x8002AFA0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8002AFA4: lbu         $t9, -0x15CE($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X15CE);
    // 0x8002AFA8: beq         $t9, $zero, L_8002AFC8
    if (ctx->r25 == 0) {
        // 0x8002AFAC: nop
    
            goto L_8002AFC8;
    }
    // 0x8002AFAC: nop

    // 0x8002AFB0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002AFB4: lh          $t0, 0x58($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X58);
    // 0x8002AFB8: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8002AFBC: addiu       $t1, $t7, 0x20
    ctx->r9 = ADD32(ctx->r15, 0X20);
    // 0x8002AFC0: b           L_8002AFE4
    // 0x8002AFC4: sh          $t1, 0x58($t6)
    MEM_H(0X58, ctx->r14) = ctx->r9;
        goto L_8002AFE4;
    // 0x8002AFC4: sh          $t1, 0x58($t6)
    MEM_H(0X58, ctx->r14) = ctx->r9;
L_8002AFC8:
    // 0x8002AFC8: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8002AFCC: lbu         $t2, -0x15CF($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X15CF);
    // 0x8002AFD0: beq         $t2, $zero, L_8002AFE4
    if (ctx->r10 == 0) {
        // 0x8002AFD4: nop
    
            goto L_8002AFE4;
    }
    // 0x8002AFD4: nop

    // 0x8002AFD8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002AFDC: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x8002AFE0: sh          $t3, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r11;
L_8002AFE4:
    // 0x8002AFE4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AFE8: lw          $t8, 0x1C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1C);
    // 0x8002AFEC: beq         $t8, $zero, L_8002B010
    if (ctx->r24 == 0) {
        // 0x8002AFF0: nop
    
            goto L_8002B010;
    }
    // 0x8002AFF0: nop

    // 0x8002AFF4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002AFF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002AFFC: sh          $t9, 0x5C($t0)
    MEM_H(0X5C, ctx->r8) = ctx->r25;
    // 0x8002B000: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002B004: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002B008: b           L_8002B06C
    // 0x8002B00C: sh          $t7, 0x5E($t1)
    MEM_H(0X5E, ctx->r9) = ctx->r15;
        goto L_8002B06C;
    // 0x8002B00C: sh          $t7, 0x5E($t1)
    MEM_H(0X5E, ctx->r9) = ctx->r15;
L_8002B010:
    // 0x8002B010: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B014: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8002B018: lh          $t2, 0x58($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X58);
    // 0x8002B01C: lh          $t5, 0x5A($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X5A);
    // 0x8002B020: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8002B024: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8002B028: lh          $t4, 0x1290($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X1290);
    // 0x8002B02C: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B030: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B034: sra         $t9, $t8, 15
    ctx->r25 = S32(SIGNED(ctx->r24) >> 15);
    // 0x8002B038: sh          $t9, 0x5C($t6)
    MEM_H(0X5C, ctx->r14) = ctx->r25;
    // 0x8002B03C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B040: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8002B044: lh          $t7, 0x58($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X58);
    // 0x8002B048: lh          $t4, 0x5A($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X5A);
    // 0x8002B04C: negu        $t1, $t7
    ctx->r9 = SUB32(0, ctx->r15);
    // 0x8002B050: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002B054: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8002B058: lh          $t3, 0x138E($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X138E);
    // 0x8002B05C: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B060: mflo        $t5
    ctx->r13 = lo;
    // 0x8002B064: sra         $t8, $t5, 15
    ctx->r24 = S32(SIGNED(ctx->r13) >> 15);
    // 0x8002B068: sh          $t8, 0x5E($t0)
    MEM_H(0X5E, ctx->r8) = ctx->r24;
L_8002B06C:
    // 0x8002B06C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B070: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B074: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8002B078: swc1        $f4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f4.u32l;
    // 0x8002B07C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B080: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002B084: lbu         $t1, 0x15($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X15);
    // 0x8002B088: sh          $t1, 0x92($t2)
    MEM_H(0X92, ctx->r10) = ctx->r9;
    // 0x8002B08C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B090: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002B094: lwc1        $f6, 0x18($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8002B098: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8002B09C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8002B0A0: nop

    // 0x8002B0A4: sh          $t5, 0x90($t8)
    MEM_H(0X90, ctx->r24) = ctx->r13;
    // 0x8002B0A8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B0AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002B0B0: sw          $t0, 0xB8($t9)
    MEM_W(0XB8, ctx->r25) = ctx->r8;
    // 0x8002B0B4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B0B8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002B0BC: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x8002B0C0: sb          $t7, 0x8C($t1)
    MEM_B(0X8C, ctx->r9) = ctx->r15;
    // 0x8002B0C4: b           L_8002B5B0
    // 0x8002B0C8: nop

        goto L_8002B5B0;
    // 0x8002B0C8: nop

L_8002B0CC:
    // 0x8002B0CC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8002B0D0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B0D4: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B0D8: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B0DC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B0E0: jal         0x8002B7C8
    // 0x8002B0E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_8002B7C8(rdram, ctx);
        goto after_1;
    // 0x8002B0E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x8002B0E8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B0EC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002B0F0: lw          $t4, 0x70($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X70);
    // 0x8002B0F4: lw          $t5, 0x74($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X74);
    // 0x8002B0F8: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002B0FC: bne         $at, $zero, L_8002B188
    if (ctx->r1 != 0) {
        // 0x8002B100: nop
    
            goto L_8002B188;
    }
    // 0x8002B100: nop

    // 0x8002B104: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002B108: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002B10C: lh          $t0, 0x58($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X58);
    // 0x8002B110: lh          $t7, 0x5A($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X5A);
    // 0x8002B114: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x8002B118: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B11C: lh          $t6, 0x1290($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1290);
    // 0x8002B120: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B124: mflo        $t1
    ctx->r9 = lo;
    // 0x8002B128: sra         $t2, $t1, 15
    ctx->r10 = S32(SIGNED(ctx->r9) >> 15);
    // 0x8002B12C: sh          $t2, 0x68($t8)
    MEM_H(0X68, ctx->r24) = ctx->r10;
    // 0x8002B130: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002B134: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8002B138: lh          $t4, 0x58($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X58);
    // 0x8002B13C: lh          $t6, 0x5A($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X5A);
    // 0x8002B140: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x8002B144: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
    // 0x8002B148: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8002B14C: lh          $t9, 0x138E($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X138E);
    // 0x8002B150: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B154: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B158: sra         $t1, $t7, 15
    ctx->r9 = S32(SIGNED(ctx->r15) >> 15);
    // 0x8002B15C: sh          $t1, 0x6E($t3)
    MEM_H(0X6E, ctx->r11) = ctx->r9;
    // 0x8002B160: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002B164: lw          $t8, 0x74($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X74);
    // 0x8002B168: sw          $t8, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->r24;
    // 0x8002B16C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002B170: lh          $t5, 0x68($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X68);
    // 0x8002B174: sh          $t5, 0x5C($t4)
    MEM_H(0X5C, ctx->r12) = ctx->r13;
    // 0x8002B178: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B17C: lh          $t9, 0x6E($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6E);
    // 0x8002B180: b           L_8002B1C8
    // 0x8002B184: sh          $t9, 0x5E($t0)
    MEM_H(0X5E, ctx->r8) = ctx->r25;
        goto L_8002B1C8;
    // 0x8002B184: sh          $t9, 0x5E($t0)
    MEM_H(0X5E, ctx->r8) = ctx->r25;
L_8002B188:
    // 0x8002B188: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B18C: lh          $a0, 0x5C($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X5C);
    // 0x8002B190: lw          $a1, 0x70($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X70);
    // 0x8002B194: lh          $a2, 0x66($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X66);
    // 0x8002B198: jal         0x8002BCBC
    // 0x8002B19C: lhu         $a3, 0x64($t6)
    ctx->r7 = MEM_HU(ctx->r14, 0X64);
    func_8002BCBC(rdram, ctx);
        goto after_2;
    // 0x8002B19C: lhu         $a3, 0x64($t6)
    ctx->r7 = MEM_HU(ctx->r14, 0X64);
    after_2:
    // 0x8002B1A0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1A4: sh          $v0, 0x5C($t7)
    MEM_H(0X5C, ctx->r15) = ctx->r2;
    // 0x8002B1A8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1AC: lh          $a0, 0x5E($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X5E);
    // 0x8002B1B0: lw          $a1, 0x70($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X70);
    // 0x8002B1B4: lh          $a2, 0x6C($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X6C);
    // 0x8002B1B8: jal         0x8002BCBC
    // 0x8002B1BC: lhu         $a3, 0x6A($t1)
    ctx->r7 = MEM_HU(ctx->r9, 0X6A);
    func_8002BCBC(rdram, ctx);
        goto after_3;
    // 0x8002B1BC: lhu         $a3, 0x6A($t1)
    ctx->r7 = MEM_HU(ctx->r9, 0X6A);
    after_3:
    // 0x8002B1C0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1C4: sh          $v0, 0x5E($t3)
    MEM_H(0X5E, ctx->r11) = ctx->r2;
L_8002B1C8:
    // 0x8002B1C8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1CC: lh          $t2, 0x5C($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X5C);
    // 0x8002B1D0: bne         $t2, $zero, L_8002B1E4
    if (ctx->r10 != 0) {
        // 0x8002B1D4: nop
    
            goto L_8002B1E4;
    }
    // 0x8002B1D4: nop

    // 0x8002B1D8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002B1E0: sh          $t5, 0x5C($t4)
    MEM_H(0X5C, ctx->r12) = ctx->r13;
L_8002B1E4:
    // 0x8002B1E4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1E8: lh          $t0, 0x5E($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X5E);
    // 0x8002B1EC: bne         $t0, $zero, L_8002B200
    if (ctx->r8 != 0) {
        // 0x8002B1F0: nop
    
            goto L_8002B200;
    }
    // 0x8002B1F0: nop

    // 0x8002B1F4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002B1FC: sh          $t6, 0x5E($t7)
    MEM_H(0X5E, ctx->r15) = ctx->r14;
L_8002B200:
    // 0x8002B200: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002B204: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8002B208: lw          $t3, 0x7C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X7C);
    // 0x8002B20C: lh          $t8, 0x8($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X8);
    // 0x8002B210: bne         $t8, $at, L_8002B274
    if (ctx->r24 != ctx->r1) {
        // 0x8002B214: nop
    
            goto L_8002B274;
    }
    // 0x8002B214: nop

    // 0x8002B218: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8002B21C: lbu         $t2, -0x15CE($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X15CE);
    // 0x8002B220: beq         $t2, $zero, L_8002B244
    if (ctx->r10 == 0) {
        // 0x8002B224: nop
    
            goto L_8002B244;
    }
    // 0x8002B224: nop

    // 0x8002B228: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002B22C: lw          $t4, 0x7C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X7C);
    // 0x8002B230: lh          $t9, 0xE($t4)
    ctx->r25 = MEM_H(ctx->r12, 0XE);
    // 0x8002B234: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8002B238: addiu       $t6, $t0, 0x20
    ctx->r14 = ADD32(ctx->r8, 0X20);
    // 0x8002B23C: b           L_8002B274
    // 0x8002B240: sh          $t6, 0x58($t5)
    MEM_H(0X58, ctx->r13) = ctx->r14;
        goto L_8002B274;
    // 0x8002B240: sh          $t6, 0x58($t5)
    MEM_H(0X58, ctx->r13) = ctx->r14;
L_8002B244:
    // 0x8002B244: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8002B248: lbu         $t7, -0x15CF($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X15CF);
    // 0x8002B24C: beq         $t7, $zero, L_8002B264
    if (ctx->r15 == 0) {
        // 0x8002B250: nop
    
            goto L_8002B264;
    }
    // 0x8002B250: nop

    // 0x8002B254: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002B258: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8002B25C: b           L_8002B274
    // 0x8002B260: sh          $t1, 0x58($t3)
    MEM_H(0X58, ctx->r11) = ctx->r9;
        goto L_8002B274;
    // 0x8002B260: sh          $t1, 0x58($t3)
    MEM_H(0X58, ctx->r11) = ctx->r9;
L_8002B264:
    // 0x8002B264: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002B268: lw          $t2, 0x7C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X7C);
    // 0x8002B26C: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x8002B270: sh          $t4, 0x58($t8)
    MEM_H(0X58, ctx->r24) = ctx->r12;
L_8002B274:
    // 0x8002B274: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B278: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8002B27C: lw          $t0, 0x7C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X7C);
    // 0x8002B280: lh          $t6, 0x8($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X8);
    // 0x8002B284: bne         $t6, $at, L_8002B300
    if (ctx->r14 != ctx->r1) {
        // 0x8002B288: nop
    
            goto L_8002B300;
    }
    // 0x8002B288: nop

    // 0x8002B28C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002B290: sw          $zero, 0x70($t5)
    MEM_W(0X70, ctx->r13) = 0;
    // 0x8002B294: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002B298: lw          $t1, 0x7C($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X7C);
    // 0x8002B29C: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x8002B2A0: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8002B2A4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8002B2A8: addu        $t4, $t2, $t2
    ctx->r12 = ADD32(ctx->r10, ctx->r10);
    // 0x8002B2AC: bgez        $t4, L_8002B2BC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8002B2B0: sra         $t8, $t4, 1
        ctx->r24 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8002B2BC;
    }
    // 0x8002B2B0: sra         $t8, $t4, 1
    ctx->r24 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8002B2B4: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8002B2B8: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8002B2BC:
    // 0x8002B2BC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8002B2C0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8002B2C4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B2C8: sh          $t9, 0x5A($t0)
    MEM_H(0X5A, ctx->r8) = ctx->r25;
    // 0x8002B2CC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B2D0: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x8002B2D4: lw          $t5, 0x7C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X7C);
    // 0x8002B2D8: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8002B2DC: addiu       $t1, $t7, 0xB7
    ctx->r9 = ADD32(ctx->r15, 0XB7);
    // 0x8002B2E0: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8002B2E4: mflo        $t3
    ctx->r11 = lo;
    // 0x8002B2E8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8002B2EC: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8002B2F0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8002B2F4: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8002B2F8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8002B2FC: sw          $t2, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r10;
L_8002B300:
    // 0x8002B300: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002B304: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8002B308: lw          $t8, 0x7C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X7C);
    // 0x8002B30C: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x8002B310: bne         $t9, $at, L_8002B3FC
    if (ctx->r25 != ctx->r1) {
        // 0x8002B314: nop
    
            goto L_8002B3FC;
    }
    // 0x8002B314: nop

    // 0x8002B318: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B31C: lw          $t2, 0x7C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X7C);
    // 0x8002B320: lh          $t5, 0x60($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X60);
    // 0x8002B324: lh          $t7, 0x62($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X62);
    // 0x8002B328: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x8002B32C: xor         $t1, $t5, $t7
    ctx->r9 = ctx->r13 ^ ctx->r15;
    // 0x8002B330: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x8002B334: sra         $t8, $t4, 7
    ctx->r24 = S32(SIGNED(ctx->r12) >> 7);
    // 0x8002B338: andi        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 & 0X1;
    // 0x8002B33C: xor         $t9, $t3, $t8
    ctx->r25 = ctx->r11 ^ ctx->r24;
    // 0x8002B340: beq         $t9, $zero, L_8002B390
    if (ctx->r25 == 0) {
        // 0x8002B344: nop
    
            goto L_8002B390;
    }
    // 0x8002B344: nop

    // 0x8002B348: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8002B34C: lbu         $t5, -0x15D0($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X15D0);
    // 0x8002B350: beq         $t5, $zero, L_8002B390
    if (ctx->r13 == 0) {
        // 0x8002B354: nop
    
            goto L_8002B390;
    }
    // 0x8002B354: nop

    // 0x8002B358: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002B35C: lh          $t1, 0x58($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X58);
    // 0x8002B360: slti        $at, $t1, 0x41
    ctx->r1 = SIGNED(ctx->r9) < 0X41 ? 1 : 0;
    // 0x8002B364: bne         $at, $zero, L_8002B380
    if (ctx->r1 != 0) {
        // 0x8002B368: nop
    
            goto L_8002B380;
    }
    // 0x8002B368: nop

    // 0x8002B36C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B370: lh          $t2, 0x60($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X60);
    // 0x8002B374: xori        $t6, $t2, 0x1
    ctx->r14 = ctx->r10 ^ 0X1;
    // 0x8002B378: b           L_8002B390
    // 0x8002B37C: sh          $t6, 0x60($t0)
    MEM_H(0X60, ctx->r8) = ctx->r14;
        goto L_8002B390;
    // 0x8002B37C: sh          $t6, 0x60($t0)
    MEM_H(0X60, ctx->r8) = ctx->r14;
L_8002B380:
    // 0x8002B380: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002B384: lh          $t3, 0x62($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X62);
    // 0x8002B388: xori        $t8, $t3, 0x1
    ctx->r24 = ctx->r11 ^ 0X1;
    // 0x8002B38C: sh          $t8, 0x62($t4)
    MEM_H(0X62, ctx->r12) = ctx->r24;
L_8002B390:
    // 0x8002B390: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B394: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002B398: lw          $t5, 0x7C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X7C);
    // 0x8002B39C: lh          $t3, 0x60($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X60);
    // 0x8002B3A0: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x8002B3A4: andi        $t8, $t3, 0x1
    ctx->r24 = ctx->r11 & 0X1;
    // 0x8002B3A8: andi        $t1, $t7, 0x7F
    ctx->r9 = ctx->r15 & 0X7F;
    // 0x8002B3AC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002B3B0: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x8002B3B4: lh          $t6, 0x1290($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1290);
    // 0x8002B3B8: andi        $t0, $t6, 0xFFFE
    ctx->r8 = ctx->r14 & 0XFFFE;
    // 0x8002B3BC: or          $t4, $t0, $t8
    ctx->r12 = ctx->r8 | ctx->r24;
    // 0x8002B3C0: sh          $t4, 0x60($t9)
    MEM_H(0X60, ctx->r25) = ctx->r12;
    // 0x8002B3C4: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002B3C8: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8002B3CC: lw          $t7, 0x7C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X7C);
    // 0x8002B3D0: lh          $t4, 0x62($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X62);
    // 0x8002B3D4: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x8002B3D8: andi        $t9, $t4, 0x1
    ctx->r25 = ctx->r12 & 0X1;
    // 0x8002B3DC: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x8002B3E0: negu        $t6, $t2
    ctx->r14 = SUB32(0, ctx->r10);
    // 0x8002B3E4: sll         $t3, $t6, 1
    ctx->r11 = S32(ctx->r14 << 1);
    // 0x8002B3E8: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x8002B3EC: lh          $t0, 0x138E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X138E);
    // 0x8002B3F0: andi        $t8, $t0, 0xFFFE
    ctx->r24 = ctx->r8 & 0XFFFE;
    // 0x8002B3F4: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8002B3F8: sh          $t7, 0x62($t5)
    MEM_H(0X62, ctx->r13) = ctx->r15;
L_8002B3FC:
    // 0x8002B3FC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002B400: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002B404: sw          $t1, 0x78($t2)
    MEM_W(0X78, ctx->r10) = ctx->r9;
    // 0x8002B408: b           L_8002B5B0
    // 0x8002B40C: nop

        goto L_8002B5B0;
    // 0x8002B40C: nop

L_8002B410:
    // 0x8002B410: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B414: lw          $t3, 0x7C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X7C);
    // 0x8002B418: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8002B41C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002B420: lh          $t4, 0xA($t0)
    ctx->r12 = MEM_H(ctx->r8, 0XA);
    // 0x8002B424: beq         $t4, $zero, L_8002B438
    if (ctx->r12 == 0) {
        // 0x8002B428: nop
    
            goto L_8002B438;
    }
    // 0x8002B428: nop

    // 0x8002B42C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B430: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002B434: sw          $t8, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r24;
L_8002B438:
    // 0x8002B438: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002B43C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B440: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002B444: jal         0x8002CC9C
    // 0x8002B448: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    func_8002CC9C(rdram, ctx);
        goto after_4;
    // 0x8002B448: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    after_4:
    // 0x8002B44C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002B450: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002B454: sw          $t5, 0x84($t1)
    MEM_W(0X84, ctx->r9) = ctx->r13;
    // 0x8002B458: b           L_8002B5B0
    // 0x8002B45C: nop

        goto L_8002B5B0;
    // 0x8002B45C: nop

L_8002B460:
    // 0x8002B460: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8002B464: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B468: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B46C: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B470: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B474: jal         0x8002B7C8
    // 0x8002B478: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_8002B7C8(rdram, ctx);
        goto after_5;
    // 0x8002B478: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_5:
    // 0x8002B47C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B480: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B484: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002B488: jal         0x8002B684
    // 0x8002B48C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8002B684(rdram, ctx);
        goto after_6;
    // 0x8002B48C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8002B490: b           L_8002B5B0
    // 0x8002B494: nop

        goto L_8002B5B0;
    // 0x8002B494: nop

L_8002B498:
    // 0x8002B498: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B49C: lw          $t3, 0x7C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X7C);
    // 0x8002B4A0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8002B4A4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002B4A8: lw          $t4, 0xC($t0)
    ctx->r12 = MEM_W(ctx->r8, 0XC);
    // 0x8002B4AC: sw          $zero, 0x88($t4)
    MEM_W(0X88, ctx->r12) = 0;
    // 0x8002B4B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002B4B4: jal         0x80021884
    // 0x8002B4B8: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    func_80021884(rdram, ctx);
        goto after_7;
    // 0x8002B4B8: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    after_7:
    // 0x8002B4BC: b           L_8002B5B0
    // 0x8002B4C0: nop

        goto L_8002B5B0;
    // 0x8002B4C0: nop

L_8002B4C4:
    // 0x8002B4C4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8002B4C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B4CC: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B4D0: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B4D4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B4D8: jal         0x8002B7C8
    // 0x8002B4DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8002B7C8(rdram, ctx);
        goto after_8;
    // 0x8002B4DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_8:
    // 0x8002B4E0: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B4E4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002B4E8: lw          $t5, 0x7C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X7C);
    // 0x8002B4EC: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8002B4F0: swc1        $f10, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f10.u32l;
    // 0x8002B4F4: b           L_8002B5B0
    // 0x8002B4F8: nop

        goto L_8002B5B0;
    // 0x8002B4F8: nop

L_8002B4FC:
    // 0x8002B4FC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8002B500: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B504: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B508: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B50C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B510: jal         0x8002B7C8
    // 0x8002B514: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_8002B7C8(rdram, ctx);
        goto after_9;
    // 0x8002B514: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_9:
    // 0x8002B518: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B51C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B520: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002B524: sw          $t2, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r10;
    // 0x8002B528: b           L_8002B5B0
    // 0x8002B52C: nop

        goto L_8002B5B0;
    // 0x8002B52C: nop

L_8002B530:
    // 0x8002B530: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8002B534: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B538: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B53C: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B540: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B544: jal         0x8002B7C8
    // 0x8002B548: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8002B7C8(rdram, ctx);
        goto after_10;
    // 0x8002B548: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_10:
    // 0x8002B54C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B550: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B554: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002B558: lw          $t4, 0x7C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X7C);
    // 0x8002B55C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8002B560: jal         0x8002CC9C
    // 0x8002B564: lw          $a2, 0xC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XC);
    func_8002CC9C(rdram, ctx);
        goto after_11;
    // 0x8002B564: lw          $a2, 0xC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XC);
    after_11:
    // 0x8002B568: b           L_8002B5B0
    // 0x8002B56C: nop

        goto L_8002B5B0;
    // 0x8002B56C: nop

L_8002B570:
    // 0x8002B570: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8002B574: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B578: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B57C: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B580: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B584: jal         0x8002B7C8
    // 0x8002B588: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8002B7C8(rdram, ctx);
        goto after_12;
    // 0x8002B588: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_12:
    // 0x8002B58C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B590: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B594: lw          $t5, 0x7C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X7C);
    // 0x8002B598: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8002B59C: lh          $a1, 0x8($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X8);
    // 0x8002B5A0: jal         0x8002B684
    // 0x8002B5A4: lw          $a2, 0xC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XC);
    func_8002B684(rdram, ctx);
        goto after_13;
    // 0x8002B5A4: lw          $a2, 0xC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XC);
    after_13:
    // 0x8002B5A8: b           L_8002B5B0
    // 0x8002B5AC: nop

        goto L_8002B5B0;
    // 0x8002B5AC: nop

L_8002B5B0:
    // 0x8002B5B0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8002B5B4: lh          $t7, 0x3E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3E);
    // 0x8002B5B8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002B5BC: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x8002B5C0: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8002B5C4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8002B5C8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8002B5CC: subu        $t4, $t3, $t0
    ctx->r12 = SUB32(ctx->r11, ctx->r8);
    // 0x8002B5D0: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8002B5D4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002B5D8: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x8002B5DC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8002B5E0: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002B5E4: lw          $t1, 0x7C($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X7C);
    // 0x8002B5E8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8002B5EC: sw          $t7, 0x7C($t5)
    MEM_W(0X7C, ctx->r13) = ctx->r15;
    // 0x8002B5F0: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002B5F4: lw          $t6, 0x7C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X7C);
    // 0x8002B5F8: bne         $t6, $zero, L_8002B608
    if (ctx->r14 != 0) {
        // 0x8002B5FC: nop
    
            goto L_8002B608;
    }
    // 0x8002B5FC: nop

    // 0x8002B600: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002B604: sw          $zero, 0x80($t3)
    MEM_W(0X80, ctx->r11) = 0;
L_8002B608:
    // 0x8002B608: jal         0x800217F4
    // 0x8002B60C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800217F4(rdram, ctx);
        goto after_14;
    // 0x8002B60C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_14:
    // 0x8002B610: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B614: lw          $t4, 0x7C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X7C);
    // 0x8002B618: bne         $t4, $zero, L_8002ADAC
    if (ctx->r12 != 0) {
        // 0x8002B61C: nop
    
            goto L_8002ADAC;
    }
    // 0x8002B61C: nop

L_8002B620:
    // 0x8002B620: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8002B624: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B628: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B62C: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B630: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8002B634: jal         0x8002B7C8
    // 0x8002B638: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8002B7C8(rdram, ctx);
        goto after_15;
    // 0x8002B638: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_15:
    // 0x8002B63C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B640: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B644: lw          $t1, 0x70($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X70);
    // 0x8002B648: lw          $t7, 0x74($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X74);
    // 0x8002B64C: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002B650: beq         $at, $zero, L_8002B664
    if (ctx->r1 == 0) {
        // 0x8002B654: nop
    
            goto L_8002B664;
    }
    // 0x8002B654: nop

    // 0x8002B658: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002B65C: lw          $t2, 0x74($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X74);
    // 0x8002B660: sw          $t2, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->r10;
L_8002B664:
    // 0x8002B664: b           L_8002B674
    // 0x8002B668: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
        goto L_8002B674;
    // 0x8002B668: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x8002B66C: b           L_8002B674
    // 0x8002B670: nop

        goto L_8002B674;
    // 0x8002B670: nop

L_8002B674:
    // 0x8002B674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B678: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8002B67C: jr          $ra
    // 0x8002B680: nop

    return;
    // 0x8002B680: nop

;}
RECOMP_FUNC void bsledge_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801258: jal         0x800839B8
    // 0x8080125C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x8080125C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801260: jal         0x808001A8
    // 0x80801264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808001A8_bsledge(rdram, ctx);
        goto after_1;
    // 0x80801264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080126C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801270: jr          $ra
    // 0x80801274: nop

    return;
    // 0x80801274: nop

;}
