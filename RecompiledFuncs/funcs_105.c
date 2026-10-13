#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808001C4_bskazmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D4: jal         0x8008E39C
    // 0x808001D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8008E39C(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001DC: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001E0: nop
    
            goto L_808001EC;
    }
    // 0x808001E0: nop

    // 0x808001E4: b           L_80800248
    // 0x808001E8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_80800248;
    // 0x808001E8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_808001EC:
    // 0x808001EC: jal         0x8009BB00
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001F4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808001F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001FC: nop

    // 0x80800200: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800204: nop

    // 0x80800208: bc1f        L_80800228
    if (!c1cs) {
        // 0x8080020C: nop
    
            goto L_80800228;
    }
    // 0x8080020C: nop

    // 0x80800210: jal         0x80097FB8
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_2;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800218: beq         $v0, $zero, L_80800244
    if (ctx->r2 == 0) {
        // 0x8080021C: addiu       $t6, $zero, 0xC4
        ctx->r14 = ADD32(0, 0XC4);
            goto L_80800244;
    }
    // 0x8080021C: addiu       $t6, $zero, 0xC4
    ctx->r14 = ADD32(0, 0XC4);
    // 0x80800220: b           L_80800244
    // 0x80800224: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_80800244;
    // 0x80800224: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800228:
    // 0x80800228: jal         0x80097FB8
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_3;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800230: beql        $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800234: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_80800248;
    }
    goto skip_0;
    // 0x80800234: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800238: jal         0x800832F8
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800240: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800244:
    // 0x80800244: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80800248:
    // 0x80800248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080024C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800254: jr          $ra
    // 0x80800258: nop

    return;
    // 0x80800258: nop

;}
RECOMP_FUNC void chboilerboss_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(932, 0X2C9C) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x2C9C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2C9C));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x2C9C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2C9C));
;}
RECOMP_FUNC void func_800EC9F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC9F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC9F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EC9F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800EC9FC: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x800ECA00: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x800ECA04: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800ECA08: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800ECA0C: lwc1        $f8, 0x60($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800ECA10: lwc1        $f10, 0x50($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800ECA14: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ECA18: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800ECA1C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ECA20: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800ECA24: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
    // 0x800ECA28: lwc1        $f6, 0x54($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800ECA2C: lwc1        $f4, 0x64($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X64);
    // 0x800ECA30: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ECA34: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800ECA38: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x800ECA3C: lwc1        $f18, 0x58($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800ECA40: lwc1        $f16, 0x68($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800ECA44: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800ECA48: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800ECA4C: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x800ECA50: lwc1        $f10, 0x5C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x800ECA54: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800ECA58: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ECA5C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800ECA60: beq         $at, $zero, L_800ECD58
    if (ctx->r1 == 0) {
        // 0x800ECA64: swc1        $f18, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
            goto L_800ECD58;
    }
    // 0x800ECA64: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
L_800ECA68:
    // 0x800ECA68: lbu         $t7, 0xC($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XC);
    // 0x800ECA6C: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800ECA70: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800ECA74: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800ECA78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ECA7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ECA80: bgez        $t7, L_800ECA94
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800ECA84: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800ECA94;
    }
    // 0x800ECA84: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800ECA88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ECA8C: nop

    // 0x800ECA90: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800ECA94:
    // 0x800ECA94: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800ECA98: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800ECA9C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ECAA0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800ECAA4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800ECAA8: nop

    // 0x800ECAAC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800ECAB0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800ECAB4: nop

    // 0x800ECAB8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800ECABC: beql        $t9, $zero, L_800ECB0C
    if (ctx->r25 == 0) {
        // 0x800ECAC0: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_800ECB0C;
    }
    goto skip_0;
    // 0x800ECAC0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x800ECAC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ECAC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800ECACC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ECAD0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800ECAD4: nop

    // 0x800ECAD8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800ECADC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800ECAE0: nop

    // 0x800ECAE4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800ECAE8: bne         $t9, $zero, L_800ECB00
    if (ctx->r25 != 0) {
        // 0x800ECAEC: nop
    
            goto L_800ECB00;
    }
    // 0x800ECAEC: nop

    // 0x800ECAF0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800ECAF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ECAF8: b           L_800ECB18
    // 0x800ECAFC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800ECB18;
    // 0x800ECAFC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800ECB00:
    // 0x800ECB00: b           L_800ECB18
    // 0x800ECB04: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800ECB18;
    // 0x800ECB04: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800ECB08: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_800ECB0C:
    // 0x800ECB0C: nop

    // 0x800ECB10: bltz        $t9, L_800ECB00
    if (SIGNED(ctx->r25) < 0) {
        // 0x800ECB14: nop
    
            goto L_800ECB00;
    }
    // 0x800ECB14: nop

L_800ECB18:
    // 0x800ECB18: sb          $t9, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r25;
    // 0x800ECB1C: lbu         $t0, 0xD($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XD);
    // 0x800ECB20: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800ECB24: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ECB28: lwc1        $f10, 0x54($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800ECB2C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800ECB30: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ECB34: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800ECB38: bgez        $t0, L_800ECB4C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800ECB3C: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800ECB4C;
    }
    // 0x800ECB3C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800ECB40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ECB44: nop

    // 0x800ECB48: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800ECB4C:
    // 0x800ECB4C: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800ECB50: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ECB54: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ECB58: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800ECB5C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800ECB60: nop

    // 0x800ECB64: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800ECB68: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800ECB6C: nop

    // 0x800ECB70: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800ECB74: beql        $t2, $zero, L_800ECBC4
    if (ctx->r10 == 0) {
        // 0x800ECB78: mfc1        $t2, $f18
        ctx->r10 = (int32_t)ctx->f18.u32l;
            goto L_800ECBC4;
    }
    goto skip_1;
    // 0x800ECB78: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x800ECB7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ECB80: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ECB84: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800ECB88: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800ECB8C: nop

    // 0x800ECB90: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800ECB94: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800ECB98: nop

    // 0x800ECB9C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800ECBA0: bne         $t2, $zero, L_800ECBB8
    if (ctx->r10 != 0) {
        // 0x800ECBA4: nop
    
            goto L_800ECBB8;
    }
    // 0x800ECBA4: nop

    // 0x800ECBA8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800ECBAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ECBB0: b           L_800ECBD0
    // 0x800ECBB4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800ECBD0;
    // 0x800ECBB4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_800ECBB8:
    // 0x800ECBB8: b           L_800ECBD0
    // 0x800ECBBC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800ECBD0;
    // 0x800ECBBC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800ECBC0: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
L_800ECBC4:
    // 0x800ECBC4: nop

    // 0x800ECBC8: bltz        $t2, L_800ECBB8
    if (SIGNED(ctx->r10) < 0) {
        // 0x800ECBCC: nop
    
            goto L_800ECBB8;
    }
    // 0x800ECBCC: nop

L_800ECBD0:
    // 0x800ECBD0: sb          $t2, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r10;
    // 0x800ECBD4: lbu         $t3, 0xE($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XE);
    // 0x800ECBD8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800ECBDC: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800ECBE0: lwc1        $f8, 0x58($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800ECBE4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800ECBE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ECBEC: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800ECBF0: bgez        $t3, L_800ECC04
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800ECBF4: cvt.s.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800ECC04;
    }
    // 0x800ECBF4: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800ECBF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ECBFC: nop

    // 0x800ECC00: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_800ECC04:
    // 0x800ECC04: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800ECC08: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ECC0C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ECC10: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800ECC14: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800ECC18: nop

    // 0x800ECC1C: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800ECC20: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800ECC24: nop

    // 0x800ECC28: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800ECC2C: beql        $t5, $zero, L_800ECC7C
    if (ctx->r13 == 0) {
        // 0x800ECC30: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_800ECC7C;
    }
    goto skip_2;
    // 0x800ECC30: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x800ECC34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ECC38: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ECC3C: sub.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800ECC40: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800ECC44: nop

    // 0x800ECC48: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800ECC4C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800ECC50: nop

    // 0x800ECC54: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800ECC58: bne         $t5, $zero, L_800ECC70
    if (ctx->r13 != 0) {
        // 0x800ECC5C: nop
    
            goto L_800ECC70;
    }
    // 0x800ECC5C: nop

    // 0x800ECC60: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800ECC64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ECC68: b           L_800ECC88
    // 0x800ECC6C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800ECC88;
    // 0x800ECC6C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800ECC70:
    // 0x800ECC70: b           L_800ECC88
    // 0x800ECC74: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800ECC88;
    // 0x800ECC74: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800ECC78: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_800ECC7C:
    // 0x800ECC7C: nop

    // 0x800ECC80: bltz        $t5, L_800ECC70
    if (SIGNED(ctx->r13) < 0) {
        // 0x800ECC84: nop
    
            goto L_800ECC70;
    }
    // 0x800ECC84: nop

L_800ECC88:
    // 0x800ECC88: sb          $t5, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r13;
    // 0x800ECC8C: lbu         $t6, 0xF($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF);
    // 0x800ECC90: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800ECC94: lwc1        $f18, 0x10($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800ECC98: lwc1        $f16, 0x5C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x800ECC9C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800ECCA0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ECCA4: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ECCA8: bgez        $t6, L_800ECCC0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800ECCAC: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800ECCC0;
    }
    // 0x800ECCAC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800ECCB0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ECCB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ECCB8: nop

    // 0x800ECCBC: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800ECCC0:
    // 0x800ECCC0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ECCC4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ECCC8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ECCCC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800ECCD0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800ECCD4: nop

    // 0x800ECCD8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800ECCDC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800ECCE0: nop

    // 0x800ECCE4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800ECCE8: beql        $t8, $zero, L_800ECD38
    if (ctx->r24 == 0) {
        // 0x800ECCEC: mfc1        $t8, $f18
        ctx->r24 = (int32_t)ctx->f18.u32l;
            goto L_800ECD38;
    }
    goto skip_3;
    // 0x800ECCEC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    skip_3:
    // 0x800ECCF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ECCF4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ECCF8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800ECCFC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800ECD00: nop

    // 0x800ECD04: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800ECD08: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800ECD0C: nop

    // 0x800ECD10: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800ECD14: bne         $t8, $zero, L_800ECD2C
    if (ctx->r24 != 0) {
        // 0x800ECD18: nop
    
            goto L_800ECD2C;
    }
    // 0x800ECD18: nop

    // 0x800ECD1C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800ECD20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ECD24: b           L_800ECD44
    // 0x800ECD28: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800ECD44;
    // 0x800ECD28: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800ECD2C:
    // 0x800ECD2C: b           L_800ECD44
    // 0x800ECD30: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800ECD44;
    // 0x800ECD30: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800ECD34: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
L_800ECD38:
    // 0x800ECD38: nop

    // 0x800ECD3C: bltz        $t8, L_800ECD2C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800ECD40: nop
    
            goto L_800ECD2C;
    }
    // 0x800ECD40: nop

L_800ECD44:
    // 0x800ECD44: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800ECD48: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800ECD4C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800ECD50: bne         $at, $zero, L_800ECA68
    if (ctx->r1 != 0) {
        // 0x800ECD54: sb          $t8, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r24;
            goto L_800ECA68;
    }
    // 0x800ECD54: sb          $t8, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r24;
L_800ECD58:
    // 0x800ECD58: jr          $ra
    // 0x800ECD5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800ECD5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808005AC_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005B0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808005B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005B8: beq         $a1, $at, L_8080061C
    if (ctx->r5 == ctx->r1) {
        // 0x808005BC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8080061C;
    }
    // 0x808005BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005C0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808005C4: beq         $a1, $at, L_80800608
    if (ctx->r5 == ctx->r1) {
        // 0x808005C8: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80800608;
    }
    // 0x808005C8: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808005CC: beq         $a1, $at, L_80800690
    if (ctx->r5 == ctx->r1) {
        // 0x808005D0: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800690;
    }
    // 0x808005D0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808005D4: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x808005D8: beq         $a1, $at, L_80800664
    if (ctx->r5 == ctx->r1) {
        // 0x808005DC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800664;
    }
    // 0x808005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005E0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808005E4: beq         $a1, $at, L_80800630
    if (ctx->r5 == ctx->r1) {
        // 0x808005E8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800630;
    }
    // 0x808005E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005EC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808005F0: bne         $a1, $at, L_808006B4
    if (ctx->r5 != ctx->r1) {
        // 0x808005F4: nop
    
            goto L_808006B4;
    }
    // 0x808005F4: nop

    // 0x808005F8: jal         0x80089F60
    // 0x808005FC: nop

    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808005FC: nop

    after_0:
    // 0x80800600: b           L_808006C0
    // 0x80800604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006C0;
    // 0x80800604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800608:
    // 0x80800608: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080060C: jal         0x80800BF4
    // 0x80800610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800BF4_chtntmineshoot(rdram, ctx);
        goto after_1;
    // 0x80800610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800614: b           L_808006C0
    // 0x80800618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006C0;
    // 0x80800618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080061C:
    // 0x8080061C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800620: jal         0x808004BC
    // 0x80800624: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808004BC_chtntmineshoot(rdram, ctx);
        goto after_2;
    // 0x80800624: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80800628: b           L_808006C0
    // 0x8080062C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006C0;
    // 0x8080062C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800630:
    // 0x80800630: addiu       $a0, $zero, 0x2BC
    ctx->r4 = ADD32(0, 0X2BC);
    // 0x80800634: jal         0x80101180
    // 0x80800638: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x80800638: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x8080063C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800640: jal         0x808004BC
    // 0x80800644: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808004BC_chtntmineshoot(rdram, ctx);
        goto after_4;
    // 0x80800644: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80800648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080064C: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x80800650: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800654: jal         0x80800078
    // 0x80800658: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80800078_chtntmineshoot(rdram, ctx);
        goto after_5;
    // 0x80800658: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_5:
    // 0x8080065C: b           L_808006C0
    // 0x80800660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006C0;
    // 0x80800660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800664:
    // 0x80800664: addiu       $a0, $zero, 0x2BC
    ctx->r4 = ADD32(0, 0X2BC);
    // 0x80800668: jal         0x80101180
    // 0x8080066C: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x8080066C: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    after_6:
    // 0x80800670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800674: jal         0x808004BC
    // 0x80800678: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808004BC_chtntmineshoot(rdram, ctx);
        goto after_7;
    // 0x80800678: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x8080067C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800680: jal         0x80800BF4
    // 0x80800684: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800BF4_chtntmineshoot(rdram, ctx);
        goto after_8;
    // 0x80800684: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800688: b           L_808006C0
    // 0x8080068C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006C0;
    // 0x8080068C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800690:
    // 0x80800690: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x80800694: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80800698: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x8080069C: bgez        $t9, L_808006AC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808006A0: nop
    
            goto L_808006AC;
    }
    // 0x808006A0: nop

    // 0x808006A4: jal         0x80801F90
    // 0x808006A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80801F90_chtntmineshoot(rdram, ctx);
        goto after_9;
    // 0x808006A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_9:
L_808006AC:
    // 0x808006AC: jal         0x800FFAB0
    // 0x808006B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808006B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_10:
L_808006B4:
    // 0x808006B4: b           L_808006C0
    // 0x808006B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006C0;
    // 0x808006B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808006BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006C0:
    // 0x808006C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006C8: jr          $ra
    // 0x808006CC: nop

    return;
    // 0x808006CC: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A740: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A740);
    return;
    // 0x8008A744: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_80800D50_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D5C: jal         0x800D90A4
    // 0x80800D60: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80800D60: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800D64: beql        $v0, $zero, L_80800DEC
    if (ctx->r2 == 0) {
        // 0x80800D68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DEC;
    }
    goto skip_0;
    // 0x80800D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800D6C: jal         0x800F54E4
    // 0x80800D70: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800D70: nop

    after_1:
    // 0x80800D74: jal         0x800F56AC
    // 0x80800D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F56AC(rdram, ctx);
        goto after_2;
    // 0x80800D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800D7C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80800D80: bnel        $v0, $at, L_80800DEC
    if (ctx->r2 != ctx->r1) {
        // 0x80800D84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DEC;
    }
    goto skip_1;
    // 0x80800D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800D88: jal         0x800F54E4
    // 0x80800D8C: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800D8C: nop

    after_3:
    // 0x80800D90: jal         0x800F6DA0
    // 0x80800D94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6DA0(rdram, ctx);
        goto after_4;
    // 0x80800D94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800D98: bnel        $v0, $zero, L_80800DEC
    if (ctx->r2 != 0) {
        // 0x80800D9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DEC;
    }
    goto skip_2;
    // 0x80800D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800DA0: jal         0x800F54E4
    // 0x80800DA4: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800DA4: nop

    after_5:
    // 0x80800DA8: jal         0x800F6C5C
    // 0x80800DAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_6;
    // 0x80800DAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800DB0: beql        $v0, $zero, L_80800DEC
    if (ctx->r2 == 0) {
        // 0x80800DB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DEC;
    }
    goto skip_3;
    // 0x80800DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80800DB8: jal         0x800F54E4
    // 0x80800DBC: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800DBC: nop

    after_7:
    // 0x80800DC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DC4: jal         0x800F7B9C
    // 0x80800DC8: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800F7B9C(rdram, ctx);
        goto after_8;
    // 0x80800DC8: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_8:
    // 0x80800DCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DD0: bne         $v0, $at, L_80800DE8
    if (ctx->r2 != ctx->r1) {
        // 0x80800DD4: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800DE8;
    }
    // 0x80800DD4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800DD8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800DDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DE0: nop

    // 0x80800DE4: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
L_80800DE8:
    // 0x80800DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DEC:
    // 0x80800DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DF0: jr          $ra
    // 0x80800DF4: nop

    return;
    // 0x80800DF4: nop

;}
RECOMP_FUNC void func_80113688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113688: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8011368C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80113690: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80113694: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80113698: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8011369C: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x801136A0: jal         0x801134F0
    // 0x801136A4: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    func_801134F0(rdram, ctx);
        goto after_0;
    // 0x801136A4: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    after_0:
    // 0x801136A8: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x801136AC: jal         0x800EEB40
    // 0x801136B0: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x801136B0: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_1:
    // 0x801136B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801136B8: lwc1        $f4, 0x65CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X65CC);
    // 0x801136BC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x801136C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801136C4: nop

    // 0x801136C8: bc1tl       L_801137D8
    if (c1cs) {
        // 0x801136CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801137D8;
    }
    goto skip_0;
    // 0x801136CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801136D0: jal         0x800EE7F8
    // 0x801136D4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x801136D4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    after_2:
    // 0x801136D8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x801136DC: jal         0x800EE7F8
    // 0x801136E0: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x801136E0: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_3:
    // 0x801136E4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801136E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801136EC: lui         $a3, 0x82
    ctx->r7 = S32(0X82 << 16);
    // 0x801136F0: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x801136F4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x801136F8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801136FC: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    // 0x80113700: jal         0x800FAB50
    // 0x80113704: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800FAB50(rdram, ctx);
        goto after_4;
    // 0x80113704: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80113708: bne         $v0, $zero, L_8011373C
    if (ctx->r2 != 0) {
        // 0x8011370C: sw          $v0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r2;
            goto L_8011373C;
    }
    // 0x8011370C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80113710: lui         $t7, 0x82
    ctx->r15 = S32(0X82 << 16);
    // 0x80113714: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x80113718: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8011371C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80113720: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80113724: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80113728: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8011372C: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    // 0x80113730: jal         0x800FB3C0
    // 0x80113734: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    func_800FB3C0(rdram, ctx);
        goto after_5;
    // 0x80113734: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    after_5:
    // 0x80113738: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_8011373C:
    // 0x8011373C: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80113740: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80113744: bne         $t8, $zero, L_80113754
    if (ctx->r24 != 0) {
        // 0x80113748: nop
    
            goto L_80113754;
    }
    // 0x80113748: nop

    // 0x8011374C: beql        $t9, $zero, L_801137D8
    if (ctx->r25 == 0) {
        // 0x80113750: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801137D8;
    }
    goto skip_1;
    // 0x80113750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_80113754:
    // 0x80113754: jal         0x800AAD28
    // 0x80113758: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800AAD28(rdram, ctx);
        goto after_6;
    // 0x80113758: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x8011375C: jal         0x80110898
    // 0x80113760: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    func_80110898(rdram, ctx);
        goto after_7;
    // 0x80113760: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_7:
    // 0x80113764: jal         0x80110060
    // 0x80113768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110060(rdram, ctx);
        goto after_8;
    // 0x80113768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x8011376C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80113770: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80113774: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80113778: beq         $t0, $zero, L_80113788
    if (ctx->r8 == 0) {
        // 0x8011377C: lw          $t1, 0x54($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X54);
            goto L_80113788;
    }
    // 0x8011377C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80113780: b           L_8011378C
    // 0x80113784: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
        goto L_8011378C;
    // 0x80113784: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
L_80113788:
    // 0x80113788: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
L_8011378C:
    // 0x8011378C: jal         0x80114CF4
    // 0x80113790: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    func_80114CF4(rdram, ctx);
        goto after_9;
    // 0x80113790: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    after_9:
    // 0x80113794: addiu       $t2, $sp, 0x74
    ctx->r10 = ADD32(ctx->r29, 0X74);
    // 0x80113798: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8011379C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x801137A0: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801137A4: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x801137A8: jal         0x801135D0
    // 0x801137AC: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    func_801135D0(rdram, ctx);
        goto after_10;
    // 0x801137AC: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    after_10:
    // 0x801137B0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801137B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801137B8: lui         $a3, 0x82
    ctx->r7 = S32(0X82 << 16);
    // 0x801137BC: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x801137C0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x801137C4: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x801137C8: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    // 0x801137CC: jal         0x800FAB50
    // 0x801137D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800FAB50(rdram, ctx);
        goto after_11;
    // 0x801137D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x801137D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801137D8:
    // 0x801137D8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x801137DC: jr          $ra
    // 0x801137E0: nop

    return;
    // 0x801137E0: nop

;}
RECOMP_FUNC void _chvolcanobits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086410: syscall     322
    recomp_syscall_handler(rdram, ctx, 0x80086410);
    return;
    // 0x80086414: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800BA6B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA6B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA6B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA6B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BA6BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BA6C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800BA6C4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800BA6C8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800BA6CC: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800BA6D0: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x800BA6D4: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800BA6D8: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800BA6DC: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BA6E0: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x800BA6E4: jal         0x800EFA6C
    // 0x800BA6E8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EFA6C(rdram, ctx);
        goto after_0;
    // 0x800BA6E8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x800BA6EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BA6F0: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x800BA6F4: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    // 0x800BA6F8: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x800BA6FC: jal         0x800EFA6C
    // 0x800BA700: addiu       $a0, $a0, 0x2E
    ctx->r4 = ADD32(ctx->r4, 0X2E);
    func_800EFA6C(rdram, ctx);
        goto after_1;
    // 0x800BA700: addiu       $a0, $a0, 0x2E
    ctx->r4 = ADD32(ctx->r4, 0X2E);
    after_1:
    // 0x800BA704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA70C: jr          $ra
    // 0x800BA710: nop

    return;
    // 0x800BA710: nop

;}
RECOMP_FUNC void func_80800198_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800198: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080019C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808001A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001AC: jal         0x80100094
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001B4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808001B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808001BC: addiu       $a0, $a0, 0x5EB8
    ctx->r4 = ADD32(ctx->r4, 0X5EB8);
    // 0x808001C0: jal         0x800DF47C
    // 0x808001C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_1;
    // 0x808001C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x808001C8: jal         0x8010347C
    // 0x808001CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_2;
    // 0x808001CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x808001D0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808001D4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808001D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001E0: jal         0x800DE448
    // 0x808001E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_3;
    // 0x808001E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x808001E8: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x808001EC: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808001F0: bgezl       $t8, L_80800244
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808001F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800244;
    }
    goto skip_0;
    // 0x808001F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808001F8: jal         0x80103AA0
    // 0x808001FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80103AA0(rdram, ctx);
        goto after_4;
    // 0x808001FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80800200: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800204: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80800208: sw          $t0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r8;
    // 0x8080020C: lbu         $v1, 0x79($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X79);
    // 0x80800210: srl         $a0, $v1, 4
    ctx->r4 = S32(U32(ctx->r3) >> 4);
    // 0x80800214: beq         $a0, $zero, L_80800240
    if (ctx->r4 == 0) {
        // 0x80800218: addiu       $t1, $a0, -0x1
        ctx->r9 = ADD32(ctx->r4, -0X1);
            goto L_80800240;
    }
    // 0x80800218: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x8080021C: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80800220: andi        $t4, $v1, 0xFF0F
    ctx->r12 = ctx->r3 & 0XFF0F;
    // 0x80800224: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80800228: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8080022C: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80800230: bne         $t7, $zero, L_80800240
    if (ctx->r15 != 0) {
        // 0x80800234: sb          $t5, 0x79($s0)
        MEM_B(0X79, ctx->r16) = ctx->r13;
            goto L_80800240;
    }
    // 0x80800234: sb          $t5, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r13;
    // 0x80800238: jal         0x80800148
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800148_chbouncycastle(rdram, ctx);
        goto after_5;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80800240:
    // 0x80800240: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800244:
    // 0x80800244: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800248: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080024C: jr          $ra
    // 0x80800250: nop

    return;
    // 0x80800250: nop

;}
RECOMP_FUNC void bsturn_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080000C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800010: jal         0x8008CABC
    // 0x80800014: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800018: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080001C: jal         0x8008AF24
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800028: jal         0x8008AED4
    // 0x8080002C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x8080002C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_2:
    // 0x80800030: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800034: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800038: jal         0x8008B1BC
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800040: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800044: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800048: jal         0x8008B1C8
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: jal         0x8008B134
    // 0x80800058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080005C: jal         0x8008B064
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800064: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800068: jal         0x8008CA4C
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_7;
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800070: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800074: jal         0x8009C908
    // 0x80800078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_8;
    // 0x80800078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8080007C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800080: jal         0x8009D2D8
    // 0x80800084: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009D2D8(rdram, ctx);
        goto after_9;
    // 0x80800084: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800088: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080008C: jal         0x8009B800
    // 0x80800090: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baphysics_set_type(rdram, ctx);
        goto after_10;
    // 0x80800090: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800098: jal         0x8009BB24
    // 0x8080009C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009BB24(rdram, ctx);
        goto after_11;
    // 0x8080009C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_11:
    // 0x808000A0: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000A4: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808000A8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x808000AC: nop

    // 0x808000B0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x808000B4: jal         0x8002DCA0
    // 0x808000B8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x808000B8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_12:
    // 0x808000BC: swc1        $f0, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f0.u32l;
    // 0x808000C0: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x808000C4: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x808000C8: addiu       $t6, $zero, 0x7530
    ctx->r14 = ADD32(0, 0X7530);
    // 0x808000CC: addiu       $t7, $zero, 0x7D00
    ctx->r15 = ADD32(0, 0X7D00);
    // 0x808000D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808000D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000D8: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808000DC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808000E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000E4: jal         0x8009DEC0
    // 0x808000E8: addiu       $a1, $zero, 0x411
    ctx->r5 = ADD32(0, 0X411);
    func_8009DEC0(rdram, ctx);
        goto after_13;
    // 0x808000E8: addiu       $a1, $zero, 0x411
    ctx->r5 = ADD32(0, 0X411);
    after_13:
    // 0x808000EC: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x808000F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808000F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808000FC: jr          $ra
    // 0x80800100: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800100: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800008_baduo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800014: jal         0x800A4C88
    // 0x80800018: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800A4C88(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080001C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800020: jal         0x800A4C88
    // 0x80800024: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A4C88(rdram, ctx);
        goto after_1;
    // 0x80800024: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080002C: jal         0x801100E4
    // 0x80800030: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_801100E4(rdram, ctx);
        goto after_2;
    // 0x80800030: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_800CF888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF888: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800CF88C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800CF890: addiu       $v0, $v0, -0x5194
    ctx->r2 = ADD32(ctx->r2, -0X5194);
    // 0x800CF894: addiu       $v1, $v1, -0x519C
    ctx->r3 = ADD32(ctx->r3, -0X519C);
    // 0x800CF898: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
L_800CF89C:
    // 0x800CF89C: bnel        $a0, $t6, L_800CF8BC
    if (ctx->r4 != ctx->r14) {
        // 0x800CF8A0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800CF8BC;
    }
    goto skip_0;
    // 0x800CF8A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x800CF8A4: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x800CF8A8: bnel        $a1, $t7, L_800CF8BC
    if (ctx->r5 != ctx->r15) {
        // 0x800CF8AC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800CF8BC;
    }
    goto skip_1;
    // 0x800CF8AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_1:
    // 0x800CF8B0: jr          $ra
    // 0x800CF8B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800CF8B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CF8B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800CF8BC:
    // 0x800CF8BC: bnel        $v1, $v0, L_800CF89C
    if (ctx->r3 != ctx->r2) {
        // 0x800CF8C0: lh          $t6, 0x0($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X0);
            goto L_800CF89C;
    }
    goto skip_2;
    // 0x800CF8C0: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    skip_2:
    // 0x800CF8C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF8C8: jr          $ra
    // 0x800CF8CC: nop

    return;
    // 0x800CF8CC: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A140: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A140);
    return;
    // 0x8008A144: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800030_chfairgroundworker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080003C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800040: jal         0x8008A0F8
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoaster_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800048: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(840, 0X260) << 16);
    // 0x8080004C: lwc1        $f6, 0x260($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(840, 0X260));
    // 0x80800050: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080005C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800060: jal         0x80102FDC
    // 0x80800064: nop

    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x80800064: nop

    after_1:
    // 0x80800068: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8080006C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800070: jal         0x8010A3E8
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A3E8(rdram, ctx);
        goto after_2;
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800078: lbu         $t7, 0x95($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X95);
    // 0x8080007C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800080: sb          $t8, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r24;
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800088: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void chfactorydrums_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C58: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2252, 0X11CC) << 16);
    // 0x80800C5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800C64: addiu       $t6, $t6, 0x11CC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2252, 0X11CC));
    // 0x80800C68: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800C6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C74: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800C78: jal         0x800BBCB8
    // 0x80800C7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800C7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800C80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C88: jr          $ra
    // 0x80800C8C: nop

    return;
    // 0x80800C8C: nop

;}
RECOMP_FUNC void bswalk_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801268: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080126C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(435, 0X1550) << 16);
    // 0x80801270: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801274: jr          $ra
    // 0x80801278: lw          $v0, 0x1550($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(435, 0X1550));
    return;
    // 0x80801278: lw          $v0, 0x1550($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(435, 0X1550));
;}
RECOMP_FUNC void chskeletonexplode_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CF8: jal         0x80100094
    // 0x80800CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800D00: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D04: sb          $t6, 0xF4($v0)
    MEM_B(0XF4, ctx->r2) = ctx->r14;
    // 0x80800D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D10: jr          $ra
    // 0x80800D14: nop

    return;
    // 0x80800D14: nop

;}
RECOMP_FUNC void func_80800EA8_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800EAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EB0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800EB4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800EB8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EBC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80800EC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800EC4: jal         0x8080105C
    // 0x80800EC8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8080105C_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x80800EC8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800ECC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800ED0: jal         0x800D1A04
    // 0x80800ED4: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800D1A04(rdram, ctx);
        goto after_1;
    // 0x80800ED4: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_1:
    // 0x80800ED8: beq         $v0, $zero, L_80800F18
    if (ctx->r2 == 0) {
        // 0x80800EDC: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80800F18;
    }
    // 0x80800EDC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800EE0: jal         0x800D1C5C
    // 0x80800EE4: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800D1C5C(rdram, ctx);
        goto after_2;
    // 0x80800EE4: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_2:
    // 0x80800EE8: jal         0x800D27A4
    // 0x80800EEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D27A4(rdram, ctx);
        goto after_3;
    // 0x80800EEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800EF0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800EF8: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x80800EFC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800F00: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800F04: jal         0x8080190C
    // 0x80800F08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_8080190C_gcnewpause(rdram, ctx);
        goto after_4;
    // 0x80800F08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
    // 0x80800F0C: beq         $v0, $zero, L_80800F18
    if (ctx->r2 == 0) {
        // 0x80800F10: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800F18;
    }
    // 0x80800F10: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800F14: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800F18:
    // 0x80800F18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F1C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800F20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F24: jr          $ra
    // 0x80800F28: nop

    return;
    // 0x80800F28: nop

;}
RECOMP_FUNC void babounce_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800404: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800408: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080040C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800410: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800414: jal         0x8008CABC
    // 0x80800418: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800418: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080041C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800420: jal         0x8008AF24
    // 0x80800424: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800424: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: jal         0x8008AED4
    // 0x80800430: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800430: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800434: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800438: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080043C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800440: lw          $v0, 0x28($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X28);
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: lbu         $t7, 0xC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC);
    // 0x8080044C: bne         $t7, $at, L_8080047C
    if (ctx->r15 != ctx->r1) {
        // 0x80800450: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8080047C;
    }
    // 0x80800450: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800454: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800458: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800464: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80800468: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080046C: jal         0x8008B1BC
    // 0x80800470: nop

    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80800470: nop

    after_3:
    // 0x80800474: b           L_80800488
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800488;
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080047C:
    // 0x8080047C: jal         0x8008B1BC
    // 0x80800480: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800480: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_4:
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800488:
    // 0x80800488: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080048C: jal         0x8008B1D4
    // 0x80800490: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x80800490: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x8008B134
    // 0x8080049C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x8080049C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808004A0: jal         0x8008B064
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808004A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004B4: jr          $ra
    // 0x808004B8: nop

    return;
    // 0x808004B8: nop

;}
RECOMP_FUNC void _chburgerstand_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DA8: syscall     239
    recomp_syscall_handler(rdram, ctx, 0x80085DA8);
    return;
    // 0x80085DAC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chfireicestorm_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1528, 0XEF0) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xEF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1528, 0XEF0));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xEF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1528, 0XEF0));
;}
RECOMP_FUNC void scradar_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800C54: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800C58: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800C5C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800C60: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800C64: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800C68: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800C6C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800C70: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800C74: jal         0x800A946C
    // 0x80800C78: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800A946C(rdram, ctx);
        goto after_0;
    // 0x80800C78: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x80800C7C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800C80: blez        $v0, L_80800D08
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800C84: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80800D08;
    }
    // 0x80800C84: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800C88: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80800C8C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80800C90: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(3126, 0XE50) << 16);
    // 0x80800C94: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800C98: addiu       $s1, $t6, 0xE50
    ctx->r17 = ADD32(ctx->r14, (int16_t)RELOC_LO16(3126, 0XE50));
    // 0x80800C9C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80800CA0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800CA4: addu        $s2, $t7, $s1
    ctx->r18 = ADD32(ctx->r15, ctx->r17);
    // 0x80800CA8: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
L_80800CAC:
    // 0x80800CAC: beql        $t8, $zero, L_80800CF8
    if (ctx->r24 == 0) {
        // 0x80800CB0: addiu       $s1, $s1, 0xF0
        ctx->r17 = ADD32(ctx->r17, 0XF0);
            goto L_80800CF8;
    }
    goto skip_0;
    // 0x80800CB0: addiu       $s1, $s1, 0xF0
    ctx->r17 = ADD32(ctx->r17, 0XF0);
    skip_0:
    // 0x80800CB4: jal         0x800E253C
    // 0x80800CB8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800E253C(rdram, ctx);
        goto after_1;
    // 0x80800CB8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80800CBC: jal         0x800E257C
    // 0x80800CC0: lbu         $a0, 0x8($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X8);
    func_800E257C(rdram, ctx);
        goto after_2;
    // 0x80800CC0: lbu         $a0, 0x8($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X8);
    after_2:
    // 0x80800CC4: jal         0x800E2434
    // 0x80800CC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2434(rdram, ctx);
        goto after_3;
    // 0x80800CC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800CCC: jal         0x800A7180
    // 0x80800CD0: nop

    func_800A7180(rdram, ctx);
        goto after_4;
    // 0x80800CD0: nop

    after_4:
    // 0x80800CD4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800CD8: jal         0x800D674C
    // 0x80800CDC: lh          $a0, 0xA($s1)
    ctx->r4 = MEM_H(ctx->r17, 0XA);
    func_800D674C(rdram, ctx);
        goto after_5;
    // 0x80800CDC: lh          $a0, 0xA($s1)
    ctx->r4 = MEM_H(ctx->r17, 0XA);
    after_5:
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800CE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800CEC: jal         0x800E30E0
    // 0x80800CF0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_800E30E0(rdram, ctx);
        goto after_6;
    // 0x80800CF0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_6:
    // 0x80800CF4: addiu       $s1, $s1, 0xF0
    ctx->r17 = ADD32(ctx->r17, 0XF0);
L_80800CF8:
    // 0x80800CF8: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80800CFC: bnel        $at, $zero, L_80800CAC
    if (ctx->r1 != 0) {
        // 0x80800D00: lh          $t8, 0xC($s1)
        ctx->r24 = MEM_H(ctx->r17, 0XC);
            goto L_80800CAC;
    }
    goto skip_1;
    // 0x80800D00: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    skip_1:
    // 0x80800D04: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80800D08:
    // 0x80800D08: jal         0x800B9990
    // 0x80800D0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800B9990(rdram, ctx);
        goto after_7;
    // 0x80800D0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x80800D10: blez        $s5, L_80800DA4
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80800D14: lui         $s1, 0x8080
        ctx->r17 = S32(RELOC_HI16(3126, 0XE50) << 16);
            goto L_80800DA4;
    }
    // 0x80800D14: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(3126, 0XE50) << 16);
    // 0x80800D18: addiu       $s1, $s1, 0xE50
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(3126, 0XE50));
L_80800D1C:
    // 0x80800D1C: lh          $v0, 0xC($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XC);
    // 0x80800D20: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80800D24: beql        $v0, $zero, L_80800D9C
    if (ctx->r2 == 0) {
        // 0x80800D28: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80800D9C;
    }
    goto skip_2;
    // 0x80800D28: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_2:
    // 0x80800D2C: blez        $v0, L_80800D64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800D30: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800D64;
    }
    // 0x80800D30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800D34: sll         $t9, $s0, 4
    ctx->r25 = S32(ctx->r16 << 4);
L_80800D38:
    // 0x80800D38: addu        $a2, $s1, $t9
    ctx->r6 = ADD32(ctx->r17, ctx->r25);
    // 0x80800D3C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800D40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800D44: jal         0x80800000
    // 0x80800D48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800000_scradar(rdram, ctx);
        goto after_8;
    // 0x80800D48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80800D4C: lh          $t0, 0xC($s2)
    ctx->r8 = MEM_H(ctx->r18, 0XC);
    // 0x80800D50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800D54: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80800D58: bnel        $at, $zero, L_80800D38
    if (ctx->r1 != 0) {
        // 0x80800D5C: sll         $t9, $s0, 4
        ctx->r25 = S32(ctx->r16 << 4);
            goto L_80800D38;
    }
    goto skip_3;
    // 0x80800D5C: sll         $t9, $s0, 4
    ctx->r25 = S32(ctx->r16 << 4);
    skip_3:
    // 0x80800D60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800D64:
    // 0x80800D64: lh          $t1, 0xE($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XE);
    // 0x80800D68: blez        $t1, L_80800D98
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80800D6C: sll         $t2, $s0, 4
        ctx->r10 = S32(ctx->r16 << 4);
            goto L_80800D98;
    }
    // 0x80800D6C: sll         $t2, $s0, 4
    ctx->r10 = S32(ctx->r16 << 4);
L_80800D70:
    // 0x80800D70: addu        $a2, $s1, $t2
    ctx->r6 = ADD32(ctx->r17, ctx->r10);
    // 0x80800D74: addiu       $a2, $a2, 0x70
    ctx->r6 = ADD32(ctx->r6, 0X70);
    // 0x80800D78: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800D7C: jal         0x80800000
    // 0x80800D80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800000_scradar(rdram, ctx);
        goto after_9;
    // 0x80800D80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80800D84: lh          $t3, 0xE($s2)
    ctx->r11 = MEM_H(ctx->r18, 0XE);
    // 0x80800D88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800D8C: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80800D90: bnel        $at, $zero, L_80800D70
    if (ctx->r1 != 0) {
        // 0x80800D94: sll         $t2, $s0, 4
        ctx->r10 = S32(ctx->r16 << 4);
            goto L_80800D70;
    }
    goto skip_4;
    // 0x80800D94: sll         $t2, $s0, 4
    ctx->r10 = S32(ctx->r16 << 4);
    skip_4:
L_80800D98:
    // 0x80800D98: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80800D9C:
    // 0x80800D9C: bne         $s4, $s5, L_80800D1C
    if (ctx->r20 != ctx->r21) {
        // 0x80800DA0: addiu       $s1, $s1, 0xF0
        ctx->r17 = ADD32(ctx->r17, 0XF0);
            goto L_80800D1C;
    }
    // 0x80800DA0: addiu       $s1, $s1, 0xF0
    ctx->r17 = ADD32(ctx->r17, 0XF0);
L_80800DA4:
    // 0x80800DA4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80800DA8: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80800DAC: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80800DB0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80800DB4: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80800DB8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800DBC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80800DC0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80800DC4: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80800DC8: lui         $t8, 0x10
    ctx->r24 = S32(0X10 << 16);
    // 0x80800DCC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800DD0: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80800DD4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80800DD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80800DDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800DE0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800DE4: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DE8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800DEC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800DF0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800DF4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DF8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800DFC: jr          $ra
    // 0x80800E00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800E00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800E04: nop

    // 0x80800E08: nop

    // 0x80800E0C: nop

;}
RECOMP_FUNC void _baspin_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085140: syscall     152
    recomp_syscall_handler(rdram, ctx, 0x80085140);
    return;
    // 0x80085144: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80801A94_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A94: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A9C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801AA0: jal         0x80100094
    // 0x80801AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801AA8: jal         0x801040D0
    // 0x80801AAC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_801040D0(rdram, ctx);
        goto after_1;
    // 0x80801AAC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801AB0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801AB4: jal         0x801015D0
    // 0x80801AB8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_801015D0(rdram, ctx);
        goto after_2;
    // 0x80801AB8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x80801ABC: jal         0x800DF41C
    // 0x80801AC0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800DF41C(rdram, ctx);
        goto after_3;
    // 0x80801AC0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80801AC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801AC8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80801ACC: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x80801AD0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801AD4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801AD8: jal         0x800EFA4C
    // 0x80801ADC: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80801ADC: nop

    after_4:
    // 0x80801AE0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801AE4: jal         0x800D93A0
    // 0x80801AE8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800D93A0(rdram, ctx);
        goto after_5;
    // 0x80801AE8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80801AEC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801AF0: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x80801AF4: jal         0x800DFF2C
    // 0x80801AF8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800DFF2C(rdram, ctx);
        goto after_6;
    // 0x80801AF8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_6:
    // 0x80801AFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801B00: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80801B04: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80801B08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801B0C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801B10: jal         0x800EFA4C
    // 0x80801B14: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x80801B14: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    after_7:
    // 0x80801B18: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801B1C: jal         0x800D93A0
    // 0x80801B20: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800D93A0(rdram, ctx);
        goto after_8;
    // 0x80801B20: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x80801B24: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801B28: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x80801B2C: jal         0x800DFF2C
    // 0x80801B30: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800DFF2C(rdram, ctx);
        goto after_9;
    // 0x80801B30: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_9:
    // 0x80801B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801B3C: jr          $ra
    // 0x80801B40: nop

    return;
    // 0x80801B40: nop

;}
RECOMP_FUNC void func_80800270_bskazspring(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800278: jal         0x800832E0
    // 0x8080027C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080027C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800280: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800288: jal         0x80800064
    // 0x8080028C: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    func_80800064_bskazspring(rdram, ctx);
        goto after_1;
    // 0x8080028C: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void func_808007D8_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007E0: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x808007E4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808007E8: addiu       $a0, $a3, 0x18
    ctx->r4 = ADD32(ctx->r7, 0X18);
    // 0x808007EC: srl         $t6, $v0, 25
    ctx->r14 = S32(U32(ctx->r2) >> 25);
    // 0x808007F0: bne         $t6, $zero, L_80800800
    if (ctx->r14 != 0) {
        // 0x808007F4: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800800;
    }
    // 0x808007F4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808007F8: b           L_80800814
    // 0x808007FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800814;
    // 0x808007FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800800:
    // 0x80800800: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80800804: jal         0x800CC338
    // 0x80800808: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CC338(rdram, ctx);
        goto after_0;
    // 0x80800808: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8080080C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80800810: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
L_80800814:
    // 0x80800814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080081C: jr          $ra
    // 0x80800820: nop

    return;
    // 0x80800820: nop

;}
RECOMP_FUNC void func_800F817C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F817C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8184: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F818C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8190: jal         0x8009337C
    // 0x800F8194: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009337C(rdram, ctx);
        goto after_0;
    // 0x800F8194: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F8198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F819C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F81A0: jr          $ra
    // 0x800F81A4: nop

    return;
    // 0x800F81A4: nop

;}
RECOMP_FUNC void func_80804C30_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804C30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80804C34: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80804C38: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80804C3C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80804C40: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80804C44: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80804C48: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80804C4C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80804C50: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80804C54: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80804C58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80804C5C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80804C60: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80804C64: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    // 0x80804C68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80804C6C: jal         0x80802D40
    // 0x80804C70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802D40_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804C70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80804C74: lui         $s1, 0x8081
    ctx->r17 = S32(RELOC_HI16(804, 0X83E8) << 16);
    // 0x80804C78: addiu       $s1, $s1, -0x7C18
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(804, 0X83E8));
    // 0x80804C7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80804C80: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_80804C84:
    // 0x80804C84: jal         0x80088138
    // 0x80804C88: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    _gcfrontend_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80804C88: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    after_1:
    // 0x80804C8C: beq         $v0, $zero, L_80804CC8
    if (ctx->r2 == 0) {
        // 0x80804C90: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80804CC8;
    }
    // 0x80804C90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80804C94: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x80804C98: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x80804C9C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80804CA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80804CA4: addiu       $a2, $s0, 0xA
    ctx->r6 = ADD32(ctx->r16, 0XA);
    // 0x80804CA8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80804CAC: jal         0x80802DB4
    // 0x80804CB0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_80802DB4_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80804CB0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x80804CB4: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x80804CB8: bnel        $s4, $t8, L_80804CC8
    if (ctx->r20 != ctx->r24) {
        // 0x80804CBC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80804CC8;
    }
    goto skip_0;
    // 0x80804CBC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80804CC0: or          $s6, $s2, $zero
    ctx->r22 = ctx->r18 | 0;
    // 0x80804CC4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80804CC8:
    // 0x80804CC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80804CCC: bne         $s0, $s5, L_80804C84
    if (ctx->r16 != ctx->r21) {
        // 0x80804CD0: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_80804C84;
    }
    // 0x80804CD0: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x80804CD4: lbu         $t9, 0x79($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X79);
    // 0x80804CD8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(804, 0X7DB0) << 16);
    // 0x80804CDC: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x80804CE0: srl         $t0, $t9, 4
    ctx->r8 = S32(U32(ctx->r25) >> 4);
    // 0x80804CE4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80804CE8: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80804CEC: lh          $a1, 0x7DB0($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(804, 0X7DB0));
    // 0x80804CF0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80804CF4: jal         0x80802E38
    // 0x80804CF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80802E38_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80804CF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80804CFC: lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X2C);
    // 0x80804D00: jal         0x808026C8
    // 0x80804D04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80804D04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80804D08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80804D0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80804D10: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80804D14: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80804D18: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80804D1C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80804D20: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80804D24: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80804D28: jr          $ra
    // 0x80804D2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80804D2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _chfaircoinbox_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087278: syscall     541
    recomp_syscall_handler(rdram, ctx, 0x80087278);
    return;
    // 0x8008727C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bskazglide_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800930: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800934: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(244, 0XAD0) << 16);
    // 0x80800938: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080093C: jr          $ra
    // 0x80800940: lw          $v0, 0xAD0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAD0));
    return;
    // 0x80800940: lw          $v0, 0xAD0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAD0));
;}
RECOMP_FUNC void func_800DA1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA1E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DA1E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DA1E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DA1EC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800DA1F0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800DA1F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DA1F8: addiu       $s1, $s1, -0x3884
    ctx->r17 = ADD32(ctx->r17, -0X3884);
    // 0x800DA1FC: addiu       $s0, $s0, -0x3890
    ctx->r16 = ADD32(ctx->r16, -0X3890);
    // 0x800DA200: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800DA204:
    // 0x800DA204: beql        $a0, $zero, L_800DA21C
    if (ctx->r4 == 0) {
        // 0x800DA208: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800DA21C;
    }
    goto skip_0;
    // 0x800DA208: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800DA20C: jal         0x8001BAFC
    // 0x800DA210: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800DA210: nop

    after_0:
    // 0x800DA214: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800DA218: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800DA21C:
    // 0x800DA21C: bnel        $s0, $s1, L_800DA204
    if (ctx->r16 != ctx->r17) {
        // 0x800DA220: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800DA204;
    }
    goto skip_1;
    // 0x800DA220: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800DA224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA228: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DA22C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DA230: jr          $ra
    // 0x800DA234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800DA234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800448_chbabydino(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800448: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080044C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800450: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800454: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800458: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8080045C: jal         0x800DA298
    // 0x80800460: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800460: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    after_0:
    // 0x80800464: beq         $v0, $zero, L_80800540
    if (ctx->r2 == 0) {
        // 0x80800468: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800540;
    }
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800470: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800474: bltz        $t8, L_80800540
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800478: nop
    
            goto L_80800540;
    }
    // 0x80800478: nop

    // 0x8080047C: jal         0x800DB9B0
    // 0x80800480: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x80800480: nop

    after_1:
    // 0x80800484: bnel        $v0, $zero, L_80800568
    if (ctx->r2 != 0) {
        // 0x80800488: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_80800568;
    }
    goto skip_0;
    // 0x80800488: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080048C: jal         0x800DA544
    // 0x80800490: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800490: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_2:
    // 0x80800494: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800498: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8080049C: jal         0x800F54E4
    // 0x808004A0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808004A0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_3:
    // 0x808004A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A8: jal         0x800F82D4
    // 0x808004AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_4;
    // 0x808004AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808004B0: jal         0x800DA298
    // 0x808004B4: addiu       $a0, $zero, 0x4EE
    ctx->r4 = ADD32(0, 0X4EE);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808004B4: addiu       $a0, $zero, 0x4EE
    ctx->r4 = ADD32(0, 0X4EE);
    after_5:
    // 0x808004B8: beq         $v0, $zero, L_80800510
    if (ctx->r2 == 0) {
        // 0x808004BC: addiu       $a1, $zero, 0x107F
        ctx->r5 = ADD32(0, 0X107F);
            goto L_80800510;
    }
    // 0x808004BC: addiu       $a1, $zero, 0x107F
    ctx->r5 = ADD32(0, 0X107F);
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: jal         0x80102424
    // 0x808004C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808004C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: jal         0x8008A4B0
    // 0x808004D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x808004D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808004D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004DC: addiu       $t2, $zero, 0x39
    ctx->r10 = ADD32(0, 0X39);
    // 0x808004E0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808004E4: addiu       $a1, $zero, 0x107E
    ctx->r5 = ADD32(0, 0X107E);
    // 0x808004E8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808004EC: jal         0x8008A208
    // 0x808004F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x808004F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x808004F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004FC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800500: jal         0x80085708
    // 0x80800504: addiu       $a3, $zero, 0x31
    ctx->r7 = ADD32(0, 0X31);
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x80800504: addiu       $a3, $zero, 0x31
    ctx->r7 = ADD32(0, 0X31);
    after_9:
    // 0x80800508: b           L_80800568
    // 0x8080050C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_80800568;
    // 0x8080050C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_80800510:
    // 0x80800510: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800514: addiu       $t3, $zero, 0x39
    ctx->r11 = ADD32(0, 0X39);
    // 0x80800518: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080051C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800520: jal         0x8008A208
    // 0x80800524: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800524: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: jal         0x80102424
    // 0x80800530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800534: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800538: b           L_80800564
    // 0x8080053C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
        goto L_80800564;
    // 0x8080053C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_80800540:
    // 0x80800540: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(848, 0X7D4) << 16);
    // 0x80800544: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(848, 0X700) << 16);
    // 0x80800548: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8080054C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800550: addiu       $a3, $a3, 0x700
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(848, 0X700));
    // 0x80800554: addiu       $a2, $a2, 0x7D4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(848, 0X7D4));
    // 0x80800558: jal         0x8008A1F0
    // 0x8080055C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x8080055C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x80800560: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80800564:
    // 0x80800564: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_80800568:
    // 0x80800568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080056C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80800570: beq         $t6, $zero, L_8080058C
    if (ctx->r14 == 0) {
        // 0x80800574: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8080058C;
    }
    // 0x80800574: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800578: jal         0x80085748
    // 0x8080057C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_21(rdram, ctx);
        goto after_13;
    // 0x8080057C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_13:
    // 0x80800580: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800584: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800588: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_8080058C:
    // 0x8080058C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800590: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800594: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800598: jr          $ra
    // 0x8080059C: nop

    return;
    // 0x8080059C: nop

;}
RECOMP_FUNC void func_800D9600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9600: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800D9604: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800D9608: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800D960C: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800D9610: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800D9614: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800D9618: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800D961C: jr          $ra
    // 0x800D9620: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800D9620: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void _chintrochar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C98: syscall     440
    recomp_syscall_handler(rdram, ctx, 0x80086C98);
    return;
    // 0x80086C9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gczoombox_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B58: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B58);
    return;
    // 0x80087B5C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_808005F8_chweldarbossfusebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800600: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800604: jal         0x8001210C
    // 0x80800608: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80800608: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8080060C: beq         $v0, $zero, L_80800634
    if (ctx->r2 == 0) {
        // 0x80800610: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800634;
    }
    // 0x80800610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800614: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1380, 0X7BC) << 16);
    // 0x80800618: addiu       $t6, $t6, 0x7BC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1380, 0X7BC));
    // 0x8080061C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800620: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800628: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080062C: jal         0x800BBCB8
    // 0x80800630: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80800630: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
L_80800634:
    // 0x80800634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800638: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080063C: jr          $ra
    // 0x80800640: nop

    return;
    // 0x80800640: nop

    // 0x80800644: nop

    // 0x80800648: nop

    // 0x8080064C: nop

;}
RECOMP_FUNC void func_800F35AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F35AC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800F35B0: bgez        $v0, L_800F35C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F35B4: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_800F35C0;
    }
    // 0x800F35B4: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800F35B8: b           L_800F35D4
    // 0x800F35BC: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
        goto L_800F35D4;
    // 0x800F35BC: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_800F35C0:
    // 0x800F35C0: bne         $at, $zero, L_800F35D0
    if (ctx->r1 != 0) {
        // 0x800F35C4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F35D0;
    }
    // 0x800F35C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F35C8: b           L_800F35D0
    // 0x800F35CC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_800F35D0;
    // 0x800F35CC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800F35D0:
    // 0x800F35D0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_800F35D4:
    // 0x800F35D4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800F35D8: bgez        $v0, L_800F35E8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F35DC: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_800F35E8;
    }
    // 0x800F35DC: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800F35E0: b           L_800F35FC
    // 0x800F35E4: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
        goto L_800F35FC;
    // 0x800F35E4: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_800F35E8:
    // 0x800F35E8: bne         $at, $zero, L_800F35F8
    if (ctx->r1 != 0) {
        // 0x800F35EC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F35F8;
    }
    // 0x800F35EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F35F0: b           L_800F35F8
    // 0x800F35F4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_800F35F8;
    // 0x800F35F4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800F35F8:
    // 0x800F35F8: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
L_800F35FC:
    // 0x800F35FC: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800F3600: bgez        $v0, L_800F3610
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F3604: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_800F3610;
    }
    // 0x800F3604: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800F3608: jr          $ra
    // 0x800F360C: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    return;
    // 0x800F360C: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
L_800F3610:
    // 0x800F3610: bne         $at, $zero, L_800F3620
    if (ctx->r1 != 0) {
        // 0x800F3614: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F3620;
    }
    // 0x800F3614: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F3618: b           L_800F3620
    // 0x800F361C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_800F3620;
    // 0x800F361C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800F3620:
    // 0x800F3620: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
    // 0x800F3624: jr          $ra
    // 0x800F3628: nop

    return;
    // 0x800F3628: nop

;}
RECOMP_FUNC void func_8080245C_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080245C: jr          $ra
    // 0x80802460: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80802460: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800E9AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9AC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E9AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9AC8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800E9ACC: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800E9AD0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800E9AD4: sll         $t8, $t7, 30
    ctx->r24 = S32(ctx->r15 << 30);
    // 0x800E9AD8: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x800E9ADC: jal         0x800E9E88
    // 0x800E9AE0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x800E9AE0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x800E9AE4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800E9AE8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800E9AEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9AF0: subu        $a2, $t2, $v0
    ctx->r6 = SUB32(ctx->r10, ctx->r2);
    // 0x800E9AF4: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x800E9AF8: addiu       $a0, $a0, 0x2DB4
    ctx->r4 = ADD32(ctx->r4, 0X2DB4);
    // 0x800E9AFC: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800E9B00: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800E9B04: mflo        $a2
    ctx->r6 = lo;
    // 0x800E9B08: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800E9B0C: lh          $t1, 0x4($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X4);
    // 0x800E9B10: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x800E9B14: jal         0x800B3FD0
    // 0x800E9B18: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_800B3FD0(rdram, ctx);
        goto after_1;
    // 0x800E9B18: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_1:
    // 0x800E9B1C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800E9B20: lw          $t5, 0x2DB4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2DB4);
    // 0x800E9B24: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9B28: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800E9B2C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800E9B30: beql        $t4, $t5, L_800E9B4C
    if (ctx->r12 == ctx->r13) {
        // 0x800E9B34: lh          $t8, 0x4($a3)
        ctx->r24 = MEM_H(ctx->r7, 0X4);
            goto L_800E9B4C;
    }
    goto skip_0;
    // 0x800E9B34: lh          $t8, 0x4($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X4);
    skip_0:
    // 0x800E9B38: jal         0x800BE4C4
    // 0x800E9B3C: nop

    func_800BE4C4(rdram, ctx);
        goto after_2;
    // 0x800E9B3C: nop

    after_2:
    // 0x800E9B40: b           L_800E9B64
    // 0x800E9B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E9B64;
    // 0x800E9B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9B48: lh          $t8, 0x4($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X4);
L_800E9B4C:
    // 0x800E9B4C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800E9B50: beql        $t7, $t8, L_800E9B64
    if (ctx->r15 == ctx->r24) {
        // 0x800E9B54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E9B64;
    }
    goto skip_1;
    // 0x800E9B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800E9B58: jal         0x800E9CF4
    // 0x800E9B5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800E9CF4(rdram, ctx);
        goto after_3;
    // 0x800E9B5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x800E9B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E9B64:
    // 0x800E9B64: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800E9B68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E9B6C: jr          $ra
    // 0x800E9B70: nop

    return;
    // 0x800E9B70: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FE4: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x80800FE8: ori         $a1, $a1, 0x5410
    ctx->r5 = ctx->r5 | 0X5410;
    // 0x80800FEC: jal         0x8010BA80
    // 0x80800FF0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8010BA80(rdram, ctx);
        goto after_0;
    // 0x80800FF0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_0:
    // 0x80800FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FFC: jr          $ra
    // 0x80801000: nop

    return;
    // 0x80801000: nop

;}
RECOMP_FUNC void chklungodoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1252, 0X4C0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x4C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1252, 0X4C0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x4C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1252, 0X4C0));
;}
RECOMP_FUNC void bsthrow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(396, 0X2F0) << 16);
    // 0x808001F0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808001F4: jr          $ra
    // 0x808001F8: lw          $v0, 0x2F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(396, 0X2F0));
    return;
    // 0x808001F8: lw          $v0, 0x2F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(396, 0X2F0));
;}
RECOMP_FUNC void func_8010B514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B514: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010B518: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010B51C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010B520: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010B524: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8010B528: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8010B52C: jal         0x8010C460
    // 0x8010B530: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_8010C460(rdram, ctx);
        goto after_0;
    // 0x8010B530: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B534: jal         0x800D8FF8
    // 0x8010B538: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8010B538: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8010B53C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8010B540: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8010B544: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010B548: jal         0x800EE7F8
    // 0x8010B54C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8010B54C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x8010B550: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010B554: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010B558: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8010B55C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8010B560: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010B564: jal         0x800EE7F8
    // 0x8010B568: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x8010B568: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8010B56C: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8010B570: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8010B574: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8010B578: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8010B57C: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8010B580: jal         0x800F13F0
    // 0x8010B584: nop

    func_800F13F0(rdram, ctx);
        goto after_4;
    // 0x8010B584: nop

    after_4:
    // 0x8010B588: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010B58C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8010B590: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010B594: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8010B598: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8010B59C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010B5A0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010B5A4: addiu       $a2, $a2, 0x6F40
    ctx->r6 = ADD32(ctx->r6, 0X6F40);
    // 0x8010B5A8: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8010B5AC: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8010B5B0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8010B5B4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8010B5B8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8010B5BC: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8010B5C0: jal         0x800BEF00
    // 0x8010B5C4: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    func_800BEF00(rdram, ctx);
        goto after_5;
    // 0x8010B5C4: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    after_5:
    // 0x8010B5C8: beql        $v0, $zero, L_8010B660
    if (ctx->r2 == 0) {
        // 0x8010B5CC: lwc1        $f8, 0x8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
            goto L_8010B660;
    }
    goto skip_0;
    // 0x8010B5CC: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x8010B5D0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010B5D4: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8010B5D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B5DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010B5E0: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8010B5E4: jal         0x8010C3E8
    // 0x8010B5E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8010C3E8(rdram, ctx);
        goto after_6;
    // 0x8010B5E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_6:
    // 0x8010B5EC: beq         $v0, $zero, L_8010B5FC
    if (ctx->r2 == 0) {
        // 0x8010B5F0: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_8010B5FC;
    }
    // 0x8010B5F0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8010B5F4: b           L_8010B688
    // 0x8010B5F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8010B688;
    // 0x8010B5F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8010B5FC:
    // 0x8010B5FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8010B600: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010B604: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010B608: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x8010B60C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010B610: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8010B614: addiu       $a1, $a1, 0x6F40
    ctx->r5 = ADD32(ctx->r5, 0X6F40);
    // 0x8010B618: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8010B61C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B620: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8010B624: bc1fl       L_8010B644
    if (!c1cs) {
        // 0x8010B628: lh          $t6, 0x8E($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X8E);
            goto L_8010B644;
    }
    goto skip_1;
    // 0x8010B628: lh          $t6, 0x8E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8E);
    skip_1:
    // 0x8010B62C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010B630: nop

    // 0x8010B634: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x8010B638: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010B63C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8010B640: lh          $t6, 0x8E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8E);
L_8010B644:
    // 0x8010B644: beq         $t6, $zero, L_8010B654
    if (ctx->r14 == 0) {
        // 0x8010B648: nop
    
            goto L_8010B654;
    }
    // 0x8010B648: nop

    // 0x8010B64C: jal         0x801045AC
    // 0x8010B650: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    func_801045AC(rdram, ctx);
        goto after_7;
    // 0x8010B650: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    after_7:
L_8010B654:
    // 0x8010B654: b           L_8010B688
    // 0x8010B658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010B688;
    // 0x8010B658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010B65C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
L_8010B660:
    // 0x8010B660: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8010B664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B668: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8010B66C: jal         0x8010C3E8
    // 0x8010B670: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    func_8010C3E8(rdram, ctx);
        goto after_8;
    // 0x8010B670: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x8010B674: beql        $v0, $zero, L_8010B688
    if (ctx->r2 == 0) {
        // 0x8010B678: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010B688;
    }
    goto skip_2;
    // 0x8010B678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8010B67C: b           L_8010B688
    // 0x8010B680: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8010B688;
    // 0x8010B680: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8010B684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010B688:
    // 0x8010B688: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B68C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010B690: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8010B694: jr          $ra
    // 0x8010B698: nop

    return;
    // 0x8010B698: nop

;}
RECOMP_FUNC void func_800E24F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E24F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E24FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E2500: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E2504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E2508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E250C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800E2510: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E2514: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E2518: jal         0x800F31DC
    // 0x800E251C: addiu       $a0, $a0, -0x2B80
    ctx->r4 = ADD32(ctx->r4, -0X2B80);
    func_800F31DC(rdram, ctx);
        goto after_0;
    // 0x800E251C: addiu       $a0, $a0, -0x2B80
    ctx->r4 = ADD32(ctx->r4, -0X2B80);
    after_0:
    // 0x800E2520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E2524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E2528: jr          $ra
    // 0x800E252C: nop

    return;
    // 0x800E252C: nop

;}
RECOMP_FUNC void func_8080449C_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080449C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808044A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808044A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808044A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808044AC: jal         0x80100094
    // 0x808044B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808044B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808044B4: lui         $a2, 0x451C
    ctx->r6 = S32(0X451C << 16);
    // 0x808044B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808044BC: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x808044C0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808044C4: jal         0x800EEBF0
    // 0x808044C8: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    func_800EEBF0(rdram, ctx);
        goto after_1;
    // 0x808044C8: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_1:
    // 0x808044CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808044D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808044D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808044D8: jal         0x8010A590
    // 0x808044DC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_8010A590(rdram, ctx);
        goto after_2;
    // 0x808044DC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x808044E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x808044E4: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    // 0x808044E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808044EC: lbu         $t7, 0x2A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2A);
    // 0x808044F0: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x808044F4: jal         0x80089C30
    // 0x808044F8: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808044F8: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    after_3:
    // 0x808044FC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80804500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804504: jal         0x80100094
    // 0x80804508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80804508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080450C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80804510: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80804514: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80804518: jal         0x800EA05C
    // 0x8080451C: sw          $t0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r8;
    func_800EA05C(rdram, ctx);
        goto after_5;
    // 0x8080451C: sw          $t0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r8;
    after_5:
    // 0x80804520: addiu       $at, $zero, 0x12B
    ctx->r1 = ADD32(0, 0X12B);
    // 0x80804524: bne         $v0, $at, L_8080453C
    if (ctx->r2 != ctx->r1) {
        // 0x80804528: lui         $t9, 0x8080
        ctx->r25 = S32(RELOC_HI16(1852, 0X58F0) << 16);
            goto L_8080453C;
    }
    // 0x80804528: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1852, 0X58F0) << 16);
    // 0x8080452C: lbu         $t1, 0x7A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7A);
    // 0x80804530: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x80804534: b           L_80804548
    // 0x80804538: sb          $t2, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r10;
        goto L_80804548;
    // 0x80804538: sb          $t2, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r10;
L_8080453C:
    // 0x8080453C: lbu         $t4, 0x7A($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X7A);
    // 0x80804540: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80804544: sb          $t5, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r13;
L_80804548:
    // 0x80804548: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x8080454C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80804550: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80804554: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80804558: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8080455C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80804560: lh          $t9, 0x58F0($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(1852, 0X58F0));
    // 0x80804564: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80804568: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080456C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804570: jal         0x800DC178
    // 0x80804574: sh          $t9, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r25;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80804574: sh          $t9, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r25;
    after_6:
    // 0x80804578: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080457C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80804580: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80804584: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804588: jal         0x800DC178
    // 0x8080458C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x8080458C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_7:
    // 0x80804590: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80804594: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80804598: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080459C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808045A0: jal         0x800DC178
    // 0x808045A4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808045A4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    after_8:
    // 0x808045A8: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x808045AC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808045B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808045B4: nop

    // 0x808045B8: swc1        $f6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f6.u32l;
    // 0x808045BC: jal         0x800EC3E8
    // 0x808045C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800EC3E8(rdram, ctx);
        goto after_9;
    // 0x808045C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x808045C4: jal         0x800AF5A0
    // 0x808045C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AF5A0(rdram, ctx);
        goto after_10;
    // 0x808045C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x808045CC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x808045D0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808045D4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808045D8: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    // 0x808045DC: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x808045E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808045E4: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x808045E8: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x808045EC: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    // 0x808045F0: lb          $t6, 0x60($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X60);
    // 0x808045F4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x808045F8: sb          $t7, 0x60($v1)
    MEM_B(0X60, ctx->r3) = ctx->r15;
    // 0x808045FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804600: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804604: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80804608: jr          $ra
    // 0x8080460C: nop

    return;
    // 0x8080460C: nop

;}
RECOMP_FUNC void subaddiecustomhits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800184: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800188: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080018C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800190: jal         0x80103DFC
    // 0x80800194: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80103DFC(rdram, ctx);
        goto after_0;
    // 0x80800194: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800198: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080019C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808001A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808001A4: lhu         $t6, 0x6A($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X6A);
    // 0x808001A8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808001AC: bgez        $t6, L_808001C0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808001B0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808001C0;
    }
    // 0x808001B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001B8: nop

    // 0x808001BC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808001C0:
    // 0x808001C0: lwc1        $f10, 0x38($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X38);
    // 0x808001C4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808001C8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808001CC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808001D0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808001D4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808001D8: jal         0x800EFFB4
    // 0x808001DC: nop

    func_800EFFB4(rdram, ctx);
        goto after_1;
    // 0x808001DC: nop

    after_1:
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001E4: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808001E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x808001EC: jr          $ra
    // 0x808001F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808001F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80098530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098530: jr          $ra
    // 0x80098534: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    return;
    // 0x80098534: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80801A88_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801A8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801A94: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801A98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801A9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801AA0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801AA4: bnel        $t7, $at, L_80801AF8
    if (ctx->r15 != ctx->r1) {
        // 0x80801AA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801AF8;
    }
    goto skip_0;
    // 0x80801AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801AAC: jal         0x8008A4C0
    // 0x80801AB0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _subaddieDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80801AB0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x80801AB4: beql        $v0, $zero, L_80801AF8
    if (ctx->r2 == 0) {
        // 0x80801AB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801AF8;
    }
    goto skip_1;
    // 0x80801AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801ABC: jal         0x8010A570
    // 0x80801AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80801AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801AC4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80801AC8: jal         0x800EE7F8
    // 0x80801ACC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80801ACC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80801AD0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801AD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801AD8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AE0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80801AE4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801AE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801AEC: jal         0x80086670
    // 0x80801AF0: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80801AF0: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80801AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801AF8:
    // 0x80801AF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801AFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801B00: jr          $ra
    // 0x80801B04: nop

    return;
    // 0x80801B04: nop

;}
RECOMP_FUNC void _gclightsDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E88: syscall     660
    recomp_syscall_handler(rdram, ctx, 0x80087E88);
    return;
    // 0x80087E8C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
