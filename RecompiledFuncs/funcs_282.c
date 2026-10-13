#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chcrusher_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1624, 0XB98) << 16);
    // 0x80800060: jr          $ra
    // 0x80800064: addiu       $v0, $v0, 0xB98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1624, 0XB98));
    return;
    // 0x80800064: addiu       $v0, $v0, 0xB98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1624, 0XB98));
;}
RECOMP_FUNC void chghostdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(984, 0X268) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x268
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(984, 0X268));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x268
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(984, 0X268));
;}
RECOMP_FUNC void func_800A4C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4C48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4C50: jal         0x800A93F8
    // 0x800A4C54: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800A93F8(rdram, ctx);
        goto after_0;
    // 0x800A4C54: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x800A4C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4C60: jr          $ra
    // 0x800A4C64: nop

    return;
    // 0x800A4C64: nop

;}
RECOMP_FUNC void func_80800830_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800830: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800834: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800838: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080083C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800840: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800844: jal         0x80100094
    // 0x80800848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080084C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80800850: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800854: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800858: beq         $v1, $at, L_80800880
    if (ctx->r3 == ctx->r1) {
        // 0x8080085C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800880;
    }
    // 0x8080085C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800860: beq         $v1, $at, L_808009A0
    if (ctx->r3 == ctx->r1) {
        // 0x80800864: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808009A0;
    }
    // 0x80800864: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800868: beq         $v1, $at, L_808009C0
    if (ctx->r3 == ctx->r1) {
        // 0x8080086C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808009C0;
    }
    // 0x8080086C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800870: beq         $v1, $at, L_808009DC
    if (ctx->r3 == ctx->r1) {
        // 0x80800874: nop
    
            goto L_808009DC;
    }
    // 0x80800874: nop

    // 0x80800878: b           L_80800A04
    // 0x8080087C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
        goto L_80800A04;
    // 0x8080087C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_80800880:
    // 0x80800880: jal         0x800F54E4
    // 0x80800884: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800884: nop

    after_1:
    // 0x80800888: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080088C: jal         0x800F5A00
    // 0x80800890: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800890: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80800894: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800898: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080089C: jal         0x800EEAD4
    // 0x808008A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EEAD4(rdram, ctx);
        goto after_3;
    // 0x808008A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x808008A4: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x808008A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808008AC: jal         0x800F13F0
    // 0x808008B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F13F0(rdram, ctx);
        goto after_4;
    // 0x808008B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x808008B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X2464) << 16);
    // 0x808008B8: lwc1        $f4, 0x2464($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2204, 0X2464));
    // 0x808008BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808008C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008C4: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808008C8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808008CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X2468) << 16);
    // 0x808008D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808008D8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808008DC: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x808008E0: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x808008E4: lwc1        $f12, 0x38($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808008E8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808008EC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808008F0: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x808008F4: nop

    // 0x808008F8: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x808008FC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80800900: lwc1        $f8, 0x2468($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2204, 0X2468));
    // 0x80800904: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X246C) << 16);
    // 0x80800908: lwc1        $f4, 0x246C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2204, 0X246C));
    // 0x8080090C: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80800910: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800914: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800918: nop

    // 0x8080091C: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80800920: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800924: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800928: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x8080092C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800930: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80800934: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800938: jal         0x800EFA4C
    // 0x8080093C: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x8080093C: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80800940: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800944: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800948: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080094C: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800954: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80800958: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080095C: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80800960: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x80800964: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800968: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080096C: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80800970: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80800974: jal         0x80101CDC
    // 0x80800978: nop

    func_80101CDC(rdram, ctx);
        goto after_6;
    // 0x80800978: nop

    after_6:
    // 0x8080097C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2204, 0X2580) << 16);
    // 0x80800980: addiu       $a1, $a1, 0x2580
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2204, 0X2580));
    // 0x80800984: jal         0x800C4AF0
    // 0x80800988: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800C4AF0(rdram, ctx);
        goto after_7;
    // 0x80800988: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800990: jal         0x80800440
    // 0x80800994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800440_chtntmineshoot(rdram, ctx);
        goto after_8;
    // 0x80800994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800998: b           L_80800A00
    // 0x8080099C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_80800A00;
    // 0x8080099C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_808009A0:
    // 0x808009A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808009A4: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808009A8: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x808009AC: nop

    // 0x808009B0: bc1fl       L_80800A04
    if (!c1cs) {
        // 0x808009B4: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_80800A04;
    }
    goto skip_0;
    // 0x808009B4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x808009B8: b           L_80800A00
    // 0x808009BC: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
        goto L_80800A00;
    // 0x808009BC: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_808009C0:
    // 0x808009C0: jal         0x800EFD24
    // 0x808009C4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EFD24(rdram, ctx);
        goto after_9;
    // 0x808009C4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_9:
    // 0x808009C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808009CC: nop

    // 0x808009D0: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x808009D4: b           L_80800A00
    // 0x808009D8: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_80800A00;
    // 0x808009D8: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_808009DC:
    // 0x808009DC: jal         0x800EFD24
    // 0x808009E0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EFD24(rdram, ctx);
        goto after_10;
    // 0x808009E0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_10:
    // 0x808009E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808009F0: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x808009F4: jal         0x80800440
    // 0x808009F8: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    func_80800440_chtntmineshoot(rdram, ctx);
        goto after_11;
    // 0x808009F8: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    after_11:
    // 0x808009FC: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800A00:
    // 0x80800A00: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_80800A04:
    // 0x80800A04: sb          $v1, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r3;
    // 0x80800A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A10: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800A14: jr          $ra
    // 0x80800A18: nop

    return;
    // 0x80800A18: nop

;}
RECOMP_FUNC void func_80016BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016BDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016BE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016BE4: jal         0x80030550
    // 0x80016BE8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    osContSetCh_recomp(rdram, ctx);
        goto after_0;
    // 0x80016BE8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
    // 0x80016BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016BF4: jr          $ra
    // 0x80016BF8: nop

    return;
    // 0x80016BF8: nop

    // 0x80016BFC: nop

;}
RECOMP_FUNC void chpickups_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0X820) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x820
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X820));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x820
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X820));
;}
RECOMP_FUNC void func_80800CC8_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800CD0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CD8: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80800CDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800CE0: lwc1        $f0, 0x38($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80800CE4: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x80800CE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800CEC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800CF0: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800CF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800CF8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800CFC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1688, 0X2694) << 16);
    // 0x80800D00: addiu       $a0, $a0, 0x2694
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1688, 0X2694));
    // 0x80800D04: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800D08: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800D0C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800D10: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800D14: jal         0x8008FB10
    // 0x80800D18: nop

    func_8008FB10(rdram, ctx);
        goto after_0;
    // 0x80800D18: nop

    after_0:
    // 0x80800D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D24: jr          $ra
    // 0x80800D28: nop

    return;
    // 0x80800D28: nop

;}
RECOMP_FUNC void func_808021E4_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808021E8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808021EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808021F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808021F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808021F8: jal         0x80802210
    // 0x808021FC: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    func_80802210_changlerboss(rdram, ctx);
        goto after_0;
    // 0x808021FC: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80802200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802208: jr          $ra
    // 0x8080220C: nop

    return;
    // 0x8080220C: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897F0: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897F0);
    return;
    // 0x800897F4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _bsbswim_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BB0: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082BB0);
    return;
    // 0x80082BB4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800FE0_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FE8: jal         0x800F54E4
    // 0x80800FEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800FEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800FF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800FF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FF8: jal         0x800F64A4
    // 0x80800FFC: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80800FFC: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_1:
    // 0x80801000: bne         $v0, $zero, L_80801010
    if (ctx->r2 != 0) {
        // 0x80801004: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80801010;
    }
    // 0x80801004: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801008: b           L_80801020
    // 0x8080100C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801020;
    // 0x8080100C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801010:
    // 0x80801010: jal         0x800F640C
    // 0x80801014: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800F640C(rdram, ctx);
        goto after_2;
    // 0x80801014: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801018: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080101C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80801020:
    // 0x80801020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801028: jr          $ra
    // 0x8080102C: nop

    return;
    // 0x8080102C: nop

;}
RECOMP_FUNC void func_800F80D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F80D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F80DC: jr          $ra
    // 0x800F80E0: sw          $a0, 0x54DC($at)
    MEM_W(0X54DC, ctx->r1) = ctx->r4;
    return;
    // 0x800F80E0: sw          $a0, 0x54DC($at)
    MEM_W(0X54DC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8010D600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010D604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D608: jal         0x8010D23C
    // 0x8010D60C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010D23C(rdram, ctx);
        goto after_0;
    // 0x8010D60C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010D610: beq         $v0, $zero, L_8010D628
    if (ctx->r2 == 0) {
        // 0x8010D614: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8010D628;
    }
    // 0x8010D614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010D618: jal         0x8008FE68
    // 0x8010D61C: nop

    func_8008FE68(rdram, ctx);
        goto after_1;
    // 0x8010D61C: nop

    after_1:
    // 0x8010D620: b           L_8010D634
    // 0x8010D624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010D634;
    // 0x8010D624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010D628:
    // 0x8010D628: jal         0x800E3980
    // 0x8010D62C: nop

    func_800E3980(rdram, ctx);
        goto after_2;
    // 0x8010D62C: nop

    after_2:
    // 0x8010D630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010D634:
    // 0x8010D634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010D638: jr          $ra
    // 0x8010D63C: nop

    return;
    // 0x8010D63C: nop

;}
RECOMP_FUNC void func_800C2A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2A98: jal         0x800C2900
    // 0x800C2A9C: nop

    func_800C2900(rdram, ctx);
        goto after_0;
    // 0x800C2A9C: nop

    after_0:
    // 0x800C2AA0: jal         0x800C2A68
    // 0x800C2AA4: nop

    func_800C2A68(rdram, ctx);
        goto after_1;
    // 0x800C2AA4: nop

    after_1:
    // 0x800C2AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2AB0: jr          $ra
    // 0x800C2AB4: nop

    return;
    // 0x800C2AB4: nop

;}
RECOMP_FUNC void subaddiefind_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800728: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080072C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800730: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800734: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800738: addiu       $s2, $sp, 0x2C
    ctx->r18 = ADD32(ctx->r29, 0X2C);
    // 0x8080073C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800740: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800744: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800748: jal         0x801067C4
    // 0x8080074C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x8080074C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80800750: beql        $v0, $zero, L_80800794
    if (ctx->r2 == 0) {
        // 0x80800754: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800794;
    }
    goto skip_0;
    // 0x80800754: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800758: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
L_8080075C:
    // 0x8080075C: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800760: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800764: bne         $s1, $t8, L_80800780
    if (ctx->r17 != ctx->r24) {
        // 0x80800768: nop
    
            goto L_80800780;
    }
    // 0x80800768: nop

    // 0x8080076C: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x80800770: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x80800774: bltz        $t1, L_80800780
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800778: nop
    
            goto L_80800780;
    }
    // 0x80800778: nop

    // 0x8080077C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800780:
    // 0x80800780: jal         0x8010682C
    // 0x80800784: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8010682C(rdram, ctx);
        goto after_1;
    // 0x80800784: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80800788: bnel        $v0, $zero, L_8080075C
    if (ctx->r2 != 0) {
        // 0x8080078C: lw          $t6, 0x6C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X6C);
            goto L_8080075C;
    }
    goto skip_1;
    // 0x8080078C: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    skip_1:
    // 0x80800790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800794:
    // 0x80800794: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800798: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080079C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808007A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808007A4: jr          $ra
    // 0x808007A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808007A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808012E8_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808012EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808012F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808012F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808012F8: jal         0x80800350
    // 0x808012FC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    bsstatue_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808012FC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801300: lui         $a1, 0x3EFB
    ctx->r5 = S32(0X3EFB << 16);
    // 0x80801304: ori         $a1, $a1, 0xC01A
    ctx->r5 = ctx->r5 | 0XC01A;
    // 0x80801308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080130C: jal         0x800A2D2C
    // 0x80801310: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2D2C(rdram, ctx);
        goto after_1;
    // 0x80801310: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80801314: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x80801318: ori         $a1, $a1, 0xE00D
    ctx->r5 = ctx->r5 | 0XE00D;
    // 0x8080131C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801320: jal         0x800A2D2C
    // 0x80801324: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2D2C(rdram, ctx);
        goto after_2;
    // 0x80801324: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80801328: lui         $a1, 0x3EFB
    ctx->r5 = S32(0X3EFB << 16);
    // 0x8080132C: ori         $a1, $a1, 0xC01A
    ctx->r5 = ctx->r5 | 0XC01A;
    // 0x80801330: jal         0x8008CB10
    // 0x80801334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_3;
    // 0x80801334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801338: bne         $v0, $zero, L_80801354
    if (ctx->r2 != 0) {
        // 0x8080133C: lui         $a1, 0x3F7D
        ctx->r5 = S32(0X3F7D << 16);
            goto L_80801354;
    }
    // 0x8080133C: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x80801340: ori         $a1, $a1, 0xE00D
    ctx->r5 = ctx->r5 | 0XE00D;
    // 0x80801344: jal         0x8008CB10
    // 0x80801348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80801348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080134C: beq         $v0, $zero, L_808013BC
    if (ctx->r2 == 0) {
        // 0x80801350: nop
    
            goto L_808013BC;
    }
    // 0x80801350: nop

L_80801354:
    // 0x80801354: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
    // 0x80801358: bnel        $t6, $zero, L_808013BC
    if (ctx->r14 != 0) {
        // 0x8080135C: sw          $zero, 0x160($s0)
        MEM_W(0X160, ctx->r16) = 0;
            goto L_808013BC;
    }
    goto skip_0;
    // 0x8080135C: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    skip_0:
    // 0x80801360: jal         0x800DC0C0
    // 0x80801364: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80801364: nop

    after_5:
    // 0x80801368: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(372, 0X158C) << 16);
    // 0x8080136C: lwc1        $f4, 0x158C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(372, 0X158C));
    // 0x80801370: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801374: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(372, 0X1590) << 16);
    // 0x80801378: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080137C: nop

    // 0x80801380: bc1fl       L_808013BC
    if (!c1cs) {
        // 0x80801384: sw          $zero, 0x160($s0)
        MEM_W(0X160, ctx->r16) = 0;
            goto L_808013BC;
    }
    goto skip_1;
    // 0x80801384: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    skip_1:
    // 0x80801388: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
    // 0x8080138C: lwc1        $f12, 0x1590($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(372, 0X1590));
    // 0x80801390: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(372, 0X1594) << 16);
    // 0x80801394: jal         0x800DC178
    // 0x80801398: lwc1        $f14, 0x1594($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(372, 0X1594));
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80801398: lwc1        $f14, 0x1594($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(372, 0X1594));
    after_6:
    // 0x8080139C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808013A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013A4: addiu       $a1, $zero, 0x4A1
    ctx->r5 = ADD32(0, 0X4A1);
    // 0x808013A8: jal         0x8009DB04
    // 0x808013AC: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    func_8009DB04(rdram, ctx);
        goto after_7;
    // 0x808013AC: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    after_7:
    // 0x808013B0: b           L_808013BC
    // 0x808013B4: nop

        goto L_808013BC;
    // 0x808013B4: nop

    // 0x808013B8: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
L_808013BC:
    // 0x808013BC: jal         0x80800BEC
    // 0x808013C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BEC_bsstatue(rdram, ctx);
        goto after_8;
    // 0x808013C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808013C4: jal         0x8009EF10
    // 0x808013C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_9;
    // 0x808013C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808013CC: bne         $v0, $zero, L_808013E8
    if (ctx->r2 != 0) {
        // 0x808013D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013E8;
    }
    // 0x808013D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013D4: jal         0x8009BCD4
    // 0x808013D8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_10;
    // 0x808013D8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_10:
    // 0x808013DC: beq         $v0, $zero, L_808013E8
    if (ctx->r2 == 0) {
        // 0x808013E0: addiu       $t8, $zero, 0xF9
        ctx->r24 = ADD32(0, 0XF9);
            goto L_808013E8;
    }
    // 0x808013E0: addiu       $t8, $zero, 0xF9
    ctx->r24 = ADD32(0, 0XF9);
    // 0x808013E4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808013E8:
    // 0x808013E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013EC: jal         0x80091A58
    // 0x808013F0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_11;
    // 0x808013F0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_11:
    // 0x808013F4: beql        $v0, $zero, L_80801420
    if (ctx->r2 == 0) {
        // 0x808013F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801420;
    }
    goto skip_2;
    // 0x808013F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808013FC: jal         0x80800104
    // 0x80801400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800104_bsstatue(rdram, ctx);
        goto after_12;
    // 0x80801400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801404: beq         $v0, $zero, L_80801418
    if (ctx->r2 == 0) {
        // 0x80801408: addiu       $t0, $zero, 0xFC
        ctx->r8 = ADD32(0, 0XFC);
            goto L_80801418;
    }
    // 0x80801408: addiu       $t0, $zero, 0xFC
    ctx->r8 = ADD32(0, 0XFC);
    // 0x8080140C: addiu       $t9, $zero, 0xF8
    ctx->r25 = ADD32(0, 0XF8);
    // 0x80801410: b           L_8080141C
    // 0x80801414: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
        goto L_8080141C;
    // 0x80801414: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80801418:
    // 0x80801418: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_8080141C:
    // 0x8080141C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801420:
    // 0x80801420: jal         0x80091A58
    // 0x80801424: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_13;
    // 0x80801424: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
    // 0x80801428: beq         $v0, $zero, L_80801434
    if (ctx->r2 == 0) {
        // 0x8080142C: addiu       $t1, $zero, 0xFB
        ctx->r9 = ADD32(0, 0XFB);
            goto L_80801434;
    }
    // 0x8080142C: addiu       $t1, $zero, 0xFB
    ctx->r9 = ADD32(0, 0XFB);
    // 0x80801430: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80801434:
    // 0x80801434: jal         0x80800078
    // 0x80801438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800078_bsstatue(rdram, ctx);
        goto after_14;
    // 0x80801438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080143C: beq         $v0, $zero, L_8080144C
    if (ctx->r2 == 0) {
        // 0x80801440: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080144C;
    }
    // 0x80801440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801444: addiu       $t2, $zero, 0xFD
    ctx->r10 = ADD32(0, 0XFD);
    // 0x80801448: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_8080144C:
    // 0x8080144C: jal         0x8009E5C8
    // 0x80801450: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x80801450: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x80801454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801458: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080145C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801460: jr          $ra
    // 0x80801464: nop

    return;
    // 0x80801464: nop

;}
RECOMP_FUNC void func_80800170_chweldarhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080017C: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80800180: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800184: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800188: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8080018C: bnel        $t8, $at, L_808001C0
    if (ctx->r24 != ctx->r1) {
        // 0x80800190: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808001C0;
    }
    goto skip_0;
    // 0x80800190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800194: jal         0x800DC128
    // 0x80800198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x80800198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001A0: addiu       $t9, $v0, 0x1361
    ctx->r25 = ADD32(ctx->r2, 0X1361);
    // 0x808001A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1404, 0X53E) << 16);
    // 0x808001A8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1404, 0X538) << 16);
    // 0x808001AC: sh          $t9, 0x53E($at)
    MEM_H((int16_t)RELOC_LO16(1404, 0X53E), ctx->r1) = ctx->r25;
    // 0x808001B0: addiu       $a2, $a2, 0x538
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1404, 0X538));
    // 0x808001B4: jal         0x8008A1E8
    // 0x808001B8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808001B8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x808001BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808001C0:
    // 0x808001C0: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x808001C4: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    // 0x808001C8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x808001CC: jal         0x80089F18
    // 0x808001D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808001D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x808001D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001DC: jr          $ra
    // 0x808001E0: nop

    return;
    // 0x808001E0: nop

;}
RECOMP_FUNC void suexpressmorph_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800534: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080053C: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80800540: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80800544: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(3170, 0X1320) << 16);
    // 0x80800548: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080054C: addiu       $a3, $a3, 0x1320
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(3170, 0X1320));
    // 0x80800550: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800554: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800558: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8080055C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800560: mflo        $t7
    ctx->r15 = lo;
    // 0x80800564: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x80800568: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x8080056C: blezl       $t8, L_808005C8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800570: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_808005C8;
    }
    goto skip_0;
    // 0x80800570: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    skip_0:
    // 0x80800574: lbu         $t1, 0x5($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X5);
L_80800578:
    // 0x80800578: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8080057C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800580: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80800584: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80800588: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8080058C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80800590: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x80800594: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80800598: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080059C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808005A0: swc1        $f4, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f4.u32l;
    // 0x808005A4: lh          $t5, 0x2($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X2);
    // 0x808005A8: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808005AC: mflo        $t6
    ctx->r14 = lo;
    // 0x808005B0: addu        $v0, $a3, $t6
    ctx->r2 = ADD32(ctx->r7, ctx->r14);
    // 0x808005B4: lbu         $t7, 0x7($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X7);
    // 0x808005B8: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808005BC: bnel        $at, $zero, L_80800578
    if (ctx->r1 != 0) {
        // 0x808005C0: lbu         $t1, 0x5($a2)
        ctx->r9 = MEM_BU(ctx->r6, 0X5);
            goto L_80800578;
    }
    goto skip_1;
    // 0x808005C0: lbu         $t1, 0x5($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X5);
    skip_1:
    // 0x808005C4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
L_808005C8:
    // 0x808005C8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808005CC: jal         0x808002BC
    // 0x808005D0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_808002BC_suexpressmorph(rdram, ctx);
        goto after_0;
    // 0x808005D0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x808005D4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808005D8: jal         0x808000EC
    // 0x808005DC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_808000EC_suexpressmorph(rdram, ctx);
        goto after_1;
    // 0x808005DC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x808005E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808005E8: jr          $ra
    // 0x808005EC: nop

    return;
    // 0x808005EC: nop

;}
RECOMP_FUNC void bskazshoessuckspline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800450: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800454: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(280, 0X480) << 16);
    // 0x80800458: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080045C: jr          $ra
    // 0x80800460: lw          $v0, 0x480($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(280, 0X480));
    return;
    // 0x80800460: lw          $v0, 0x480($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(280, 0X480));
;}
RECOMP_FUNC void _idglowa_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D88: syscall     739
    recomp_syscall_handler(rdram, ctx, 0x80088D88);
    return;
    // 0x80088D8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800C2A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2A5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C2A60: jr          $ra
    // 0x800C2A64: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800C2A64: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_8080000C_chwarriorbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: jal         0x8008A0F8
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoaster_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: beq         $v0, $zero, L_80800074
    if (ctx->r2 == 0) {
        // 0x80800028: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_80800074;
    }
    // 0x80800028: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080002C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800030: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080003C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800040: jal         0x80102FDC
    // 0x80800044: nop

    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x80800044: nop

    after_1:
    // 0x80800048: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8080004C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800050: jal         0x8010A3E8
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A3E8(rdram, ctx);
        goto after_2;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800058: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x80800064: bltzl       $t8, L_80800078
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800068: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800078;
    }
    goto skip_0;
    // 0x80800068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080006C: jal         0x8008A148
    // 0x80800070: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800070: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_80800074:
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800078:
    // 0x80800078: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080007C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

    // 0x80800088: nop

    // 0x8080008C: nop

;}
RECOMP_FUNC void _cheggsplode_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087338: syscall     552
    recomp_syscall_handler(rdram, ctx, 0x80087338);
    return;
    // 0x8008733C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800340_sulights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800340: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800348: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8080034C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800350: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800354: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x80800358: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
L_8080035C:
    // 0x8080035C: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80800360: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800364: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800368: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8080036C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800370: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80800374: mflo        $t8
    ctx->r24 = lo;
    // 0x80800378: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8080037C: bnel        $v0, $a2, L_8080035C
    if (ctx->r2 != ctx->r6) {
        // 0x80800380: lw          $a0, 0x10($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X10);
            goto L_8080035C;
    }
    goto skip_0;
    // 0x80800380: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x80800384: jr          $ra
    // 0x80800388: nop

    return;
    // 0x80800388: nop

;}
RECOMP_FUNC void chicekey_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2452, 0XEC) << 16);
    // 0x80800098: jr          $ra
    // 0x8080009C: addiu       $v0, $v0, 0xEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2452, 0XEC));
    return;
    // 0x8080009C: addiu       $v0, $v0, 0xEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2452, 0XEC));
;}
RECOMP_FUNC void bsbansack_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080166C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801670: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1E80) << 16);
    // 0x80801674: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801678: jr          $ra
    // 0x8080167C: lw          $v0, 0x1E80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E80));
    return;
    // 0x8080167C: lw          $v0, 0x1E80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E80));
;}
RECOMP_FUNC void freelist_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B303C: jr          $ra
    // 0x800B3040: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    return;
    // 0x800B3040: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
;}
RECOMP_FUNC void _glcutDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887E0: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887E0);
    return;
    // 0x800887E4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D68: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D68);
    return;
    // 0x80087D6C: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void func_808069FC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808069FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806A04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80806A08: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80806A0C: lw          $t7, 0xA8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XA8);
    // 0x80806A10: bnel        $t7, $zero, L_80806A70
    if (ctx->r15 != 0) {
        // 0x80806A14: lwc1        $f12, 0xC4($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0XC4);
            goto L_80806A70;
    }
    goto skip_0;
    // 0x80806A14: lwc1        $f12, 0xC4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC4);
    skip_0:
    // 0x80806A18: lwc1        $f12, 0x180($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X180);
    // 0x80806A1C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80806A20: lw          $a2, 0x1F0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F0);
    // 0x80806A24: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80806A28: jal         0x800F122C
    // 0x80806A2C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_800F122C(rdram, ctx);
        goto after_0;
    // 0x80806A2C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x80806A30: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80806A34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80806A38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80806A3C: addiu       $v1, $v0, 0x180
    ctx->r3 = ADD32(ctx->r2, 0X180);
    // 0x80806A40: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x80806A44: beq         $t8, $zero, L_80806A64
    if (ctx->r24 == 0) {
        // 0x80806A48: nop
    
            goto L_80806A64;
    }
    // 0x80806A48: nop

    // 0x80806A4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80806A50: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80806A54: lwc1        $f10, 0x1F8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1F8);
    // 0x80806A58: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80806A5C: b           L_80806AB0
    // 0x80806A60: div.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
        goto L_80806AB0;
    // 0x80806A60: div.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
L_80806A64:
    // 0x80806A64: b           L_80806AB0
    // 0x80806A68: lwc1        $f0, 0x200($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X200);
        goto L_80806AB0;
    // 0x80806A68: lwc1        $f0, 0x200($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X200);
    // 0x80806A6C: lwc1        $f12, 0xC4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC4);
L_80806A70:
    // 0x80806A70: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80806A74: lw          $a2, 0x1F4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F4);
    // 0x80806A78: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80806A7C: jal         0x800F122C
    // 0x80806A80: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_800F122C(rdram, ctx);
        goto after_1;
    // 0x80806A80: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x80806A84: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80806A88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80806A8C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80806A90: lwc1        $f18, 0xC4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x80806A94: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80806A98: nop

    // 0x80806A9C: bc1tl       L_80806AB0
    if (c1cs) {
        // 0x80806AA0: lwc1        $f0, 0x204($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X204);
            goto L_80806AB0;
    }
    goto skip_1;
    // 0x80806AA0: lwc1        $f0, 0x204($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X204);
    skip_1:
    // 0x80806AA4: b           L_80806AB0
    // 0x80806AA8: lwc1        $f0, 0x1FC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1FC);
        goto L_80806AB0;
    // 0x80806AA8: lwc1        $f0, 0x1FC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1FC);
    // 0x80806AAC: lwc1        $f0, 0x204($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X204);
L_80806AB0:
    // 0x80806AB0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80806AB4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80806AB8: jal         0x80806AD0
    // 0x80806ABC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80806AD0_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80806ABC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80806AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806AC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806AC8: jr          $ra
    // 0x80806ACC: nop

    return;
    // 0x80806ACC: nop

;}
RECOMP_FUNC void func_800DF830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF830: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF834: jr          $ra
    // 0x800DF838: sw          $a0, -0x35D8($at)
    MEM_W(-0X35D8, ctx->r1) = ctx->r4;
    return;
    // 0x800DF838: sw          $a0, -0x35D8($at)
    MEM_W(-0X35D8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _subaddieaudioloop_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D38: syscall     810
    recomp_syscall_handler(rdram, ctx, 0x80089D38);
    return;
    // 0x80089D3C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void sucoasterflydata_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x808001E4: beq         $at, $zero, L_8080022C
    if (ctx->r1 == 0) {
        // 0x808001E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080022C;
    }
    // 0x808001E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3286, 0X27C) << 16);
    // 0x808001F4: addu        $at, $at, $t6
    gpr jr_addend_808001FC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808001F8: lw          $t6, 0x27C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3286, 0X27C));
    // 0x808001FC: jr          $t6
    // 0x80800200: nop

    switch (jr_addend_808001FC >> 2) {
        case 0: goto L_80800204; break;
        case 1: goto L_8080020C; break;
        case 2: goto L_80800214; break;
        case 3: goto L_8080021C; break;
        case 4: goto L_80800224; break;
        default: switch_error(__func__, 0x808001FC, 0x8080027C);
    }
    // 0x80800200: nop

L_80800204:
    // 0x80800204: jr          $ra
    // 0x80800208: addiu       $v0, $zero, 0x320
    ctx->r2 = ADD32(0, 0X320);
    return;
    // 0x80800208: addiu       $v0, $zero, 0x320
    ctx->r2 = ADD32(0, 0X320);
L_8080020C:
    // 0x8080020C: jr          $ra
    // 0x80800210: addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    return;
    // 0x80800210: addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
L_80800214:
    // 0x80800214: jr          $ra
    // 0x80800218: addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    return;
    // 0x80800218: addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
L_8080021C:
    // 0x8080021C: jr          $ra
    // 0x80800220: addiu       $v0, $zero, 0x4B0
    ctx->r2 = ADD32(0, 0X4B0);
    return;
    // 0x80800220: addiu       $v0, $zero, 0x4B0
    ctx->r2 = ADD32(0, 0X4B0);
L_80800224:
    // 0x80800224: jr          $ra
    // 0x80800228: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    return;
    // 0x80800228: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_8080022C:
    // 0x8080022C: jr          $ra
    // 0x80800230: nop

    return;
    // 0x80800230: nop

    // 0x80800234: nop

    // 0x80800238: nop

    // 0x8080023C: nop

;}
RECOMP_FUNC void _chwarriorbaddy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CC8: syscall     224
    recomp_syscall_handler(rdram, ctx, 0x80085CC8);
    return;
    // 0x80085CCC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bskazcrouch_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083320: syscall     54
    recomp_syscall_handler(rdram, ctx, 0x80083320);
    return;
    // 0x80083324: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800E44FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E44FC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800E4500: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E4504: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E4508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E450C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E4510: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E4514: jal         0x800CA7E4
    // 0x800E4518: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800CA7E4(rdram, ctx);
        goto after_0;
    // 0x800E4518: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x800E451C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E4520: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E4524: jal         0x800CB124
    // 0x800E4528: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800CB124(rdram, ctx);
        goto after_1;
    // 0x800E4528: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x800E452C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E4530: lui         $t7, 0xDB0E
    ctx->r15 = S32(0XDB0E << 16);
    // 0x800E4534: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E4538: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E453C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800E4540: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800E4544: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E4548: jal         0x800CA6E8
    // 0x800E454C: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA6E8(rdram, ctx);
        goto after_2;
    // 0x800E454C: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_2:
    // 0x800E4550: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800E4554: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800E4558: jal         0x800E443C
    // 0x800E455C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800E443C(rdram, ctx);
        goto after_3;
    // 0x800E455C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x800E4560: jal         0x80018BC4
    // 0x800E4564: nop

    func_80018BC4(rdram, ctx);
        goto after_4;
    // 0x800E4564: nop

    after_4:
    // 0x800E4568: beq         $v0, $zero, L_800E4590
    if (ctx->r2 == 0) {
        // 0x800E456C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800E4590;
    }
    // 0x800E456C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E4570: jal         0x800CA6E8
    // 0x800E4574: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA6E8(rdram, ctx);
        goto after_5;
    // 0x800E4574: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_5:
    // 0x800E4578: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800E457C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800E4580: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800E4584: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800E4588: jal         0x800E443C
    // 0x800E458C: nop

    func_800E443C(rdram, ctx);
        goto after_6;
    // 0x800E458C: nop

    after_6:
L_800E4590:
    // 0x800E4590: jal         0x80018C28
    // 0x800E4594: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_7;
    // 0x800E4594: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_7:
    // 0x800E4598: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E459C: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800E45A0: ori         $t9, $t9, 0x7
    ctx->r25 = ctx->r25 | 0X7;
    // 0x800E45A4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800E45A8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800E45AC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800E45B0: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x800E45B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E45B8: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x800E45BC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800E45C0: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x800E45C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E45C8: addiu       $t3, $t2, 0x40
    ctx->r11 = ADD32(ctx->r10, 0X40);
    // 0x800E45CC: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800E45D0: addiu       $t5, $t3, -0x40
    ctx->r13 = ADD32(ctx->r11, -0X40);
    // 0x800E45D4: sw          $t5, -0x2AA8($at)
    MEM_W(-0X2AA8, ctx->r1) = ctx->r13;
    // 0x800E45D8: jal         0x8002EF3C
    // 0x800E45DC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    guMtxIdent(rdram, ctx);
        goto after_8;
    // 0x800E45DC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_8:
    // 0x800E45E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E45E4: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x800E45E8: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x800E45EC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E45F0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800E45F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E45F8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800E45FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E4600: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800E4604: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800E4608: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x800E460C: addiu       $t1, $t0, 0x40
    ctx->r9 = ADD32(ctx->r8, 0X40);
    // 0x800E4610: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x800E4614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4618: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E461C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x800E4620: jr          $ra
    // 0x800E4624: nop

    return;
    // 0x800E4624: nop

;}
RECOMP_FUNC void gzpublic_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080014C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800154: jal         0x80800000
    // 0x80800158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    wait_five_seconds_gzpublic(rdram, ctx);
        goto after_0;
    // 0x80800158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080015C: jal         0x80014F38
    // 0x80800160: nop

    func_80014F38(rdram, ctx);
        goto after_1;
    // 0x80800160: nop

    after_1:
    // 0x80800164: jal         0x80015430
    // 0x80800168: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80015430(rdram, ctx);
        goto after_2;
    // 0x80800168: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080016C: jal         0x80800000
    // 0x80800170: nop

    wait_five_seconds_gzpublic(rdram, ctx);
        goto after_3;
    // 0x80800170: nop

    after_3:
L_80800174:
    // 0x80800174: jal         0x80800040
    // 0x80800178: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    func_80800040_gzpublic(rdram, ctx);
        goto after_4;
    // 0x80800178: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    after_4:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800188: jal         0x8008A950
    // 0x8080018C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _gztrace_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x8080018C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80800190: jal         0x80014F00
    // 0x80800194: nop

    func_80014F00(rdram, ctx);
        goto after_6;
    // 0x80800194: nop

    after_6:
    // 0x80800198: jal         0x8001DA60
    // 0x8080019C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001DA60(rdram, ctx);
        goto after_7;
    // 0x8080019C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808001A0: jal         0x80800000
    // 0x808001A4: nop

    wait_five_seconds_gzpublic(rdram, ctx);
        goto after_8;
    // 0x808001A4: nop

    after_8:
    // 0x808001A8: jal         0x80800040
    // 0x808001AC: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    func_80800040_gzpublic(rdram, ctx);
        goto after_9;
    // 0x808001AC: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    after_9:
    // 0x808001B0: jal         0x8008A958
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gzreg_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001B8: jal         0x80014F00
    // 0x808001BC: nop

    func_80014F00(rdram, ctx);
        goto after_11;
    // 0x808001BC: nop

    after_11:
    // 0x808001C0: jal         0x8001DA60
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001DA60(rdram, ctx);
        goto after_12;
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x808001C8: jal         0x80800000
    // 0x808001CC: nop

    wait_five_seconds_gzpublic(rdram, ctx);
        goto after_13;
    // 0x808001CC: nop

    after_13:
    // 0x808001D0: jal         0x80800040
    // 0x808001D4: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    func_80800040_gzpublic(rdram, ctx);
        goto after_14;
    // 0x808001D4: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    after_14:
    // 0x808001D8: jal         0x8008A978
    // 0x808001DC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    _gzthread_entrypoint_1(rdram, ctx);
        goto after_15;
    // 0x808001DC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_15:
    // 0x808001E0: jal         0x80014F00
    // 0x808001E4: nop

    func_80014F00(rdram, ctx);
        goto after_16;
    // 0x808001E4: nop

    after_16:
    // 0x808001E8: jal         0x8001DA60
    // 0x808001EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001DA60(rdram, ctx);
        goto after_17;
    // 0x808001EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x808001F0: jal         0x80800000
    // 0x808001F4: nop

    wait_five_seconds_gzpublic(rdram, ctx);
        goto after_18;
    // 0x808001F4: nop

    after_18:
    // 0x808001F8: jal         0x80014F38
    // 0x808001FC: nop

    func_80014F38(rdram, ctx);
        goto after_19;
    // 0x808001FC: nop

    after_19:
    // 0x80800200: jal         0x80015430
    // 0x80800204: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80015430(rdram, ctx);
        goto after_20;
    // 0x80800204: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x80800208: jal         0x80800000
    // 0x8080020C: nop

    wait_five_seconds_gzpublic(rdram, ctx);
        goto after_21;
    // 0x8080020C: nop

    after_21:
    // 0x80800210: jal         0x80014F38
    // 0x80800214: nop

    func_80014F38(rdram, ctx);
        goto after_22;
    // 0x80800214: nop

    after_22:
    // 0x80800218: jal         0x80015430
    // 0x8080021C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80015430(rdram, ctx);
        goto after_23;
    // 0x8080021C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x80800220: b           L_80800174
    // 0x80800224: nop

        goto L_80800174;
    // 0x80800224: nop

    // 0x80800228: nop

    // 0x8080022C: nop

    // 0x80800230: nop

    // 0x80800234: nop

    // 0x80800238: nop

    // 0x8080023C: nop

    // 0x80800240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800244: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800248: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080024C: jr          $ra
    // 0x80800250: nop

    return;
    // 0x80800250: nop

;}
RECOMP_FUNC void func_8009DFD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DFD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009DFD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DFDC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009DFE0: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8009DFE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009DFE8: jal         0x800DC178
    // 0x8009DFEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8009DFEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009DFF0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8009DFF4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8009DFF8: jal         0x800DC128
    // 0x8009DFFC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x8009DFFC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x8009E000: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8009E004: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8009E008: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009E00C: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009E010: lbu         $a1, 0x3($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X3);
    // 0x8009E014: jal         0x8009DCCC
    // 0x8009E018: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8009DCCC(rdram, ctx);
        goto after_2;
    // 0x8009E018: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x8009E01C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E020: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009E024: jr          $ra
    // 0x8009E028: nop

    return;
    // 0x8009E028: nop

;}
RECOMP_FUNC void func_80016C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016C00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016C04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80016C08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80016C0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80016C10: jal         0x800E9574
    // 0x80016C14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800E9574(rdram, ctx);
        goto after_0;
    // 0x80016C14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80016C18: addiu       $s1, $zero, 0x1ED7
    ctx->r17 = ADD32(0, 0X1ED7);
    // 0x80016C1C: jal         0x800D738C
    // 0x80016C20: addiu       $a0, $zero, 0x1ED7
    ctx->r4 = ADD32(0, 0X1ED7);
    func_800D738C(rdram, ctx);
        goto after_1;
    // 0x80016C20: addiu       $a0, $zero, 0x1ED7
    ctx->r4 = ADD32(0, 0X1ED7);
    after_1:
    // 0x80016C24: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80016C28: bne         $v0, $s0, L_80016C50
    if (ctx->r2 != ctx->r16) {
        // 0x80016C2C: nop
    
            goto L_80016C50;
    }
    // 0x80016C2C: nop

    // 0x80016C30: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80016C34:
    // 0x80016C34: slti        $at, $s1, 0x1DDE
    ctx->r1 = SIGNED(ctx->r17) < 0X1DDE ? 1 : 0;
    // 0x80016C38: bne         $at, $zero, L_80016C50
    if (ctx->r1 != 0) {
        // 0x80016C3C: nop
    
            goto L_80016C50;
    }
    // 0x80016C3C: nop

    // 0x80016C40: jal         0x800D738C
    // 0x80016C44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D738C(rdram, ctx);
        goto after_2;
    // 0x80016C44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80016C48: beql        $v0, $s0, L_80016C34
    if (ctx->r2 == ctx->r16) {
        // 0x80016C4C: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80016C34;
    }
    goto skip_0;
    // 0x80016C4C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
L_80016C50:
    // 0x80016C50: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80016C54: addiu       $t6, $s1, -0x1DDC
    ctx->r14 = ADD32(ctx->r17, -0X1DDC);
    // 0x80016C58: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016C5C: addiu       $s2, $s2, -0x51A8
    ctx->r18 = ADD32(ctx->r18, -0X51A8);
    // 0x80016C60: sh          $t6, -0x5188($at)
    MEM_H(-0X5188, ctx->r1) = ctx->r14;
    // 0x80016C64: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x80016C68: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x80016C6C: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80016C70: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80016C74: sw          $t8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r24;
    // 0x80016C78: jal         0x80012EDC
    // 0x80016C7C: sb          $t9, 0x8($s2)
    MEM_B(0X8, ctx->r18) = ctx->r25;
    func_80012EDC(rdram, ctx);
        goto after_3;
    // 0x80016C7C: sb          $t9, 0x8($s2)
    MEM_B(0X8, ctx->r18) = ctx->r25;
    after_3:
    // 0x80016C80: sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    // 0x80016C84: sw          $zero, 0x10($s2)
    MEM_W(0X10, ctx->r18) = 0;
    // 0x80016C88: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    // 0x80016C8C: sw          $zero, 0x18($s2)
    MEM_W(0X18, ctx->r18) = 0;
    // 0x80016C90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80016C94: jal         0x80022084
    // 0x80016C98: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_80022084(rdram, ctx);
        goto after_4;
    // 0x80016C98: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_4:
    // 0x80016C9C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80016CA0: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80016CA4: addiu       $s1, $s1, -0x4FC8
    ctx->r17 = ADD32(ctx->r17, -0X4FC8);
    // 0x80016CA8: addiu       $s0, $s0, -0x5E80
    ctx->r16 = ADD32(ctx->r16, -0X5E80);
    // 0x80016CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80016CB0:
    // 0x80016CB0: jal         0x800221B0
    // 0x80016CB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800221B0(rdram, ctx);
        goto after_5;
    // 0x80016CB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80016CB8: addiu       $s0, $s0, 0x274
    ctx->r16 = ADD32(ctx->r16, 0X274);
    // 0x80016CBC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80016CC0: bnel        $at, $zero, L_80016CB0
    if (ctx->r1 != 0) {
        // 0x80016CC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80016CB0;
    }
    goto skip_1;
    // 0x80016CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80016CC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016CCC: sb          $zero, -0x605E($at)
    MEM_B(-0X605E, ctx->r1) = 0;
    // 0x80016CD0: sb          $zero, -0x605D($at)
    MEM_B(-0X605D, ctx->r1) = 0;
    // 0x80016CD4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016CD8: sh          $zero, -0x5DF2($at)
    MEM_H(-0X5DF2, ctx->r1) = 0;
    // 0x80016CDC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016CE0: sb          $zero, -0x605C($at)
    MEM_B(-0X605C, ctx->r1) = 0;
    // 0x80016CE4: sb          $zero, -0x605B($at)
    MEM_B(-0X605B, ctx->r1) = 0;
    // 0x80016CE8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80016CEC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016CF0: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80016CF4: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80016CF8: sb          $zero, -0x5DEA($at)
    MEM_B(-0X5DEA, ctx->r1) = 0;
    // 0x80016CFC: sb          $zero, -0x5DE9($at)
    MEM_B(-0X5DE9, ctx->r1) = 0;
    // 0x80016D00: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80016D04: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016D08: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80016D0C: sh          $zero, -0x5B7E($at)
    MEM_H(-0X5B7E, ctx->r1) = 0;
    // 0x80016D10: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80016D14: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016D18: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80016D1C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80016D20: addiu       $t1, $t1, -0x6060
    ctx->r9 = ADD32(ctx->r9, -0X6060);
    // 0x80016D24: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80016D28: sb          $zero, -0x5DE8($at)
    MEM_B(-0X5DE8, ctx->r1) = 0;
    // 0x80016D2C: sb          $zero, -0x5DE7($at)
    MEM_B(-0X5DE7, ctx->r1) = 0;
    // 0x80016D30: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80016D34: sb          $zero, 0x276($v0)
    MEM_B(0X276, ctx->r2) = 0;
    // 0x80016D38: sb          $zero, 0x277($v0)
    MEM_B(0X277, ctx->r2) = 0;
    // 0x80016D3C: sh          $zero, 0x4E2($v0)
    MEM_H(0X4E2, ctx->r2) = 0;
    // 0x80016D40: sb          $zero, 0x278($v0)
    MEM_B(0X278, ctx->r2) = 0;
    // 0x80016D44: sb          $zero, 0x279($v0)
    MEM_B(0X279, ctx->r2) = 0;
    // 0x80016D48: sb          $zero, 0x4EA($v0)
    MEM_B(0X4EA, ctx->r2) = 0;
    // 0x80016D4C: sb          $zero, 0x4EB($v0)
    MEM_B(0X4EB, ctx->r2) = 0;
    // 0x80016D50: sh          $zero, 0x756($v0)
    MEM_H(0X756, ctx->r2) = 0;
    // 0x80016D54: sb          $zero, 0x4EC($v0)
    MEM_B(0X4EC, ctx->r2) = 0;
    // 0x80016D58: sb          $zero, 0x4ED($v0)
    MEM_B(0X4ED, ctx->r2) = 0;
    // 0x80016D5C: sb          $zero, 0x75E($v0)
    MEM_B(0X75E, ctx->r2) = 0;
    // 0x80016D60: sb          $zero, 0x75F($v0)
    MEM_B(0X75F, ctx->r2) = 0;
    // 0x80016D64: sh          $zero, 0x9CA($v0)
    MEM_H(0X9CA, ctx->r2) = 0;
    // 0x80016D68: sb          $zero, 0x760($v0)
    MEM_B(0X760, ctx->r2) = 0;
    // 0x80016D6C: sb          $zero, 0x761($v0)
    MEM_B(0X761, ctx->r2) = 0;
    // 0x80016D70: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x80016D74: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80016D78: sh          $zero, 0x26E($v0)
    MEM_H(0X26E, ctx->r2) = 0;
    // 0x80016D7C: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x80016D80: jal         0x80017244
    // 0x80016D84: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    func_80017244(rdram, ctx);
        goto after_6;
    // 0x80016D84: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    after_6:
    // 0x80016D88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80016D8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016D90: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80016D94: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80016D98: jr          $ra
    // 0x80016D9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80016D9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chjiggybeam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BF0: syscall     206
    recomp_syscall_handler(rdram, ctx, 0x80085BF0);
    return;
    // 0x80085BF4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808025DC_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808025E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808025E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808025E8: jal         0x80100094
    // 0x808025EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808025EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808025F0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808025F4: lbu         $t6, 0x57($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X57);
    // 0x808025F8: beql        $t6, $zero, L_80802684
    if (ctx->r14 == 0) {
        // 0x808025FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802684;
    }
    goto skip_0;
    // 0x808025FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802600: jal         0x800F54E4
    // 0x80802604: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80802604: nop

    after_1:
    // 0x80802608: jal         0x80087908
    // 0x8080260C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plcamera_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x8080260C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80802610: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80802614: beq         $v0, $at, L_80802628
    if (ctx->r2 == ctx->r1) {
        // 0x80802618: lw          $a1, 0x38($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X38);
            goto L_80802628;
    }
    // 0x80802618: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8080261C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80802620: b           L_80802680
    // 0x80802624: sb          $zero, 0x57($t7)
    MEM_B(0X57, ctx->r15) = 0;
        goto L_80802680;
    // 0x80802624: sb          $zero, 0x57($t7)
    MEM_B(0X57, ctx->r15) = 0;
L_80802628:
    // 0x80802628: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080262C: jal         0x800EE7F8
    // 0x80802630: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80802630: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x80802634: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80802638: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080263C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80802640: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802644: jal         0x800F54E4
    // 0x80802648: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80802648: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8080264C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802650: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80802654: jal         0x80087900
    // 0x80802658: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _plcamera_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80802658: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_5:
    // 0x8080265C: jal         0x800F54E4
    // 0x80802660: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80802660: nop

    after_6:
    // 0x80802664: jal         0x800F5EF8
    // 0x80802668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_7;
    // 0x80802668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x8080266C: jal         0x80110014
    // 0x80802670: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_8;
    // 0x80802670: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80802674: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802678: jal         0x80116088
    // 0x8080267C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80116088(rdram, ctx);
        goto after_9;
    // 0x8080267C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_9:
L_80802680:
    // 0x80802680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802684:
    // 0x80802684: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802688: jr          $ra
    // 0x8080268C: nop

    return;
    // 0x8080268C: nop

;}
RECOMP_FUNC void func_8001592C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001592C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80015930: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80015934: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001593C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80015940: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80015944: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80015948: addiu       $v0, $v0, -0x68F0
    ctx->r2 = ADD32(ctx->r2, -0X68F0);
    // 0x8001594C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80015950: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80015954:
    // 0x80015954: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80015958: beql        $t6, $zero, L_80015970
    if (ctx->r14 == 0) {
        // 0x8001595C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80015970;
    }
    goto skip_0;
    // 0x8001595C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_0:
    // 0x80015960: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80015964: bne         $v1, $a0, L_80015954
    if (ctx->r3 != ctx->r4) {
        // 0x80015968: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80015954;
    }
    // 0x80015968: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001596C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80015970:
    // 0x80015970: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80015974: jal         0x80015828
    // 0x80015978: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80015828(rdram, ctx);
        goto after_0;
    // 0x80015978: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001597C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80015980: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80015984: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80015988: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x8001598C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80015990: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80015994: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80015998: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001599C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800159A0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800159A4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800159A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800159AC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800159B0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800159B4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800159B8: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800159BC: addiu       $t9, $t9, -0x68E8
    ctx->r25 = ADD32(ctx->r25, -0X68E8);
    // 0x800159C0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800159C4: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x800159C8: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800159CC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800159D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800159D4: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800159D8: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800159DC: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800159E0: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x800159E4: addiu       $t5, $t5, -0x6848
    ctx->r13 = ADD32(ctx->r13, -0X6848);
    // 0x800159E8: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x800159EC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x800159F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800159F4: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x800159F8: sh          $a3, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r7;
    // 0x800159FC: sh          $t2, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r10;
    // 0x80015A00: sh          $t0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r8;
    // 0x80015A04: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80015A08: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80015A0C: sh          $t3, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r11;
    // 0x80015A10: addiu       $t1, $zero, 0x1FF
    ctx->r9 = ADD32(0, 0X1FF);
    // 0x80015A14: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80015A18: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x80015A1C: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x80015A20: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x80015A24: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80015A28: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x80015A2C: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    // 0x80015A30: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x80015A34: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80015A38: sh          $t1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r9;
    // 0x80015A3C: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x80015A40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80015A44: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x80015A48: sh          $t9, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r25;
    // 0x80015A4C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80015A50: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80015A54: jal         0x8002E660
    // 0x80015A58: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x80015A58: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
    after_1:
    // 0x80015A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015A60: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80015A64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80015A68: jr          $ra
    // 0x80015A6C: nop

    return;
    // 0x80015A6C: nop

;}
RECOMP_FUNC void gcfrontend_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080013C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800140: jal         0x80800450
    // 0x80800144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800450_gcfrontend(rdram, ctx);
        goto after_0;
    // 0x80800144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800148: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8080014C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80800150: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2650, 0XD80) << 16);
    // 0x80800154: addiu       $t7, $t7, 0xD80
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2650, 0XD80));
    // 0x80800158: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080015C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800160: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80800164: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800168: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x8080016C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800170: jal         0x800DA298
    // 0x80800174: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800174: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    after_1:
    // 0x80800178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080017C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void func_800A87FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A87FC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A8800: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A8804: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A8808: addiu       $t7, $t7, 0x7688
    ctx->r15 = ADD32(ctx->r15, 0X7688);
    // 0x800A880C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A8810: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800A8814: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800A8818: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A881C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A8820: bne         $a1, $zero, L_800A8830
    if (ctx->r5 != 0) {
        // 0x800A8824: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800A8830;
    }
    // 0x800A8824: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A8828: b           L_800A88B4
    // 0x800A882C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A88B4;
    // 0x800A882C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A8830:
    // 0x800A8830: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A8834: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800A8838: jal         0x800158E4
    // 0x800A883C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800158E4(rdram, ctx);
        goto after_0;
    // 0x800A883C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A8840: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8844: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800A8848: addiu       $v1, $v1, 0x7670
    ctx->r3 = ADD32(ctx->r3, 0X7670);
    // 0x800A884C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A8850: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A8854: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800A8858: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800A885C: bne         $t8, $v0, L_800A88A0
    if (ctx->r24 != ctx->r2) {
        // 0x800A8860: sw          $zero, 0x4($a2)
        MEM_W(0X4, ctx->r6) = 0;
            goto L_800A88A0;
    }
    // 0x800A8860: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800A8864: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800A8868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A886C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A8870: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_800A8874:
    // 0x800A8874: beq         $a1, $zero, L_800A8888
    if (ctx->r5 == 0) {
        // 0x800A8878: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800A8888;
    }
    // 0x800A8878: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A887C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800A8880: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800A8884: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800A8888:
    // 0x800A8888: bne         $v0, $a0, L_800A8874
    if (ctx->r2 != ctx->r4) {
        // 0x800A888C: nop
    
            goto L_800A8874;
    }
    // 0x800A888C: nop

    // 0x800A8890: jal         0x800A85A8
    // 0x800A8894: nop

    func_800A85A8(rdram, ctx);
        goto after_1;
    // 0x800A8894: nop

    after_1:
    // 0x800A8898: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A889C: lw          $v0, 0x7670($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7670);
L_800A88A0:
    // 0x800A88A0: bne         $v0, $zero, L_800A88B0
    if (ctx->r2 != 0) {
        // 0x800A88A4: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A88B0;
    }
    // 0x800A88A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A88A8: jal         0x800E42B4
    // 0x800A88AC: lw          $a0, 0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X76BC);
    func_800E42B4(rdram, ctx);
        goto after_2;
    // 0x800A88AC: lw          $a0, 0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X76BC);
    after_2:
L_800A88B0:
    // 0x800A88B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A88B4:
    // 0x800A88B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A88B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A88BC: jr          $ra
    // 0x800A88C0: nop

    return;
    // 0x800A88C0: nop

;}
RECOMP_FUNC void suegg_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800558: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080055C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800560: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800564: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800568: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080056C: jal         0x80100094
    // 0x80800570: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800570: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800574: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800578: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: jal         0x80800390
    // 0x80800584: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    func_80800390_suegg(rdram, ctx);
        goto after_1;
    // 0x80800584: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_1:
    // 0x80800588: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080058C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800590: jal         0x800CB840
    // 0x80800594: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800CB840(rdram, ctx);
        goto after_2;
    // 0x80800594: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800598: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808005A4: jal         0x80800BFC
    // 0x808005A8: sh          $zero, 0x20($t7)
    MEM_H(0X20, ctx->r15) = 0;
    suegg_entrypoint_18(rdram, ctx);
        goto after_3;
    // 0x808005A8: sh          $zero, 0x20($t7)
    MEM_H(0X20, ctx->r15) = 0;
    after_3:
    // 0x808005AC: jal         0x8010A590
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_4;
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808005B4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808005B8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808005BC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808005C0: jal         0x800CD820
    // 0x808005C4: lui         $a3, 0x4218
    ctx->r7 = S32(0X4218 << 16);
    func_800CD820(rdram, ctx);
        goto after_5;
    // 0x808005C4: lui         $a3, 0x4218
    ctx->r7 = S32(0X4218 << 16);
    after_5:
    // 0x808005C8: beq         $v0, $zero, L_80800630
    if (ctx->r2 == 0) {
        // 0x808005CC: sw          $v0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r2;
            goto L_80800630;
    }
    // 0x808005CC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x808005D0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808005D4: bltzl       $t8, L_80800634
    if (SIGNED(ctx->r24) < 0) {
        // 0x808005D8: lw          $t0, 0x48($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X48);
            goto L_80800634;
    }
    goto skip_0;
    // 0x808005D8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x808005DC: jal         0x80106790
    // 0x808005E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x808005E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808005E4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808005E8: jal         0x800EEB40
    // 0x808005EC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_7;
    // 0x808005EC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_7:
    // 0x808005F0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808005F4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808005F8: jal         0x800F5A00
    // 0x808005FC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_8;
    // 0x808005FC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_8:
    // 0x80800600: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800604: jal         0x800EEB40
    // 0x80800608: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800EEB40(rdram, ctx);
        goto after_9;
    // 0x80800608: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_9:
    // 0x8080060C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800610: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800614: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800618: nop

    // 0x8080061C: bc1fl       L_80800630
    if (!c1cs) {
        // 0x80800620: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_80800630;
    }
    goto skip_1;
    // 0x80800620: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    skip_1:
    // 0x80800624: b           L_80800630
    // 0x80800628: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
        goto L_80800630;
    // 0x80800628: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8080062C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800630:
    // 0x80800630: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
L_80800634:
    // 0x80800634: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80800638: beql        $t0, $zero, L_8080066C
    if (ctx->r8 == 0) {
        // 0x8080063C: lw          $t6, 0x34($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X34);
            goto L_8080066C;
    }
    goto skip_2;
    // 0x8080063C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80800640: beq         $t1, $zero, L_8080065C
    if (ctx->r9 == 0) {
        // 0x80800644: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_8080065C;
    }
    // 0x80800644: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80800648: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8080064C: jal         0x80088610
    // 0x80800650: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    _glhittableDll_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800650: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_10:
    // 0x80800654: b           L_8080066C
    // 0x80800658: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
        goto L_8080066C;
    // 0x80800658: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
L_8080065C:
    // 0x8080065C: lbu         $t4, 0x39($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X39);
    // 0x80800660: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x80800664: sb          $t5, 0x39($t2)
    MEM_B(0X39, ctx->r10) = ctx->r13;
    // 0x80800668: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
L_8080066C:
    // 0x8080066C: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    // 0x80800670: bltz        $t6, L_80800690
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800674: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80800690;
    }
    // 0x80800674: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800678: jal         0x800F7BC8
    // 0x8080067C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_800F7BC8(rdram, ctx);
        goto after_11;
    // 0x8080067C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_11:
    // 0x80800680: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80800684: lbu         $t9, 0x39($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X39);
    // 0x80800688: ori         $t1, $t9, 0x80
    ctx->r9 = ctx->r25 | 0X80;
    // 0x8080068C: sb          $t1, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r9;
L_80800690:
    // 0x80800690: jal         0x800CB870
    // 0x80800694: nop

    func_800CB870(rdram, ctx);
        goto after_12;
    // 0x80800694: nop

    after_12:
    // 0x80800698: jal         0x8010A570
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_13;
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808006A0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x808006A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006AC: lbu         $v0, 0x39($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X39);
    // 0x808006B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808006B4: srl         $t3, $v0, 7
    ctx->r11 = S32(U32(ctx->r2) >> 7);
    // 0x808006B8: jr          $ra
    // 0x808006BC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    return;
    // 0x808006BC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
;}
RECOMP_FUNC void func_80800748_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800748: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080074C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800750: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800754: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800758: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080075C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800760: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800764: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800768: jal         0x800EE7F8
    // 0x8080076C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080076C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800770: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800774: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800778: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080077C: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80800780: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800784: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800788: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8080078C: jal         0x800B53A4
    // 0x80800790: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x80800790: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80800794: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800798: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080079C: jal         0x800BA3FC
    // 0x808007A0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800BA3FC(rdram, ctx);
        goto after_2;
    // 0x808007A0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x808007A4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x808007A8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1064, 0XC5C) << 16);
    // 0x808007AC: addiu       $t8, $t8, 0xC5C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1064, 0XC5C));
    // 0x808007B0: lw          $a3, 0x38($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X38);
    // 0x808007B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808007B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808007C0: jal         0x800BABB8
    // 0x808007C4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x808007C4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x808007C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1064, 0XC88) << 16);
    // 0x808007CC: addiu       $a2, $a2, 0xC88
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1064, 0XC88));
    // 0x808007D0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808007D4: jal         0x80089D18
    // 0x808007D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808007D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808007DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808007E4: jr          $ra
    // 0x808007E8: nop

    return;
    // 0x808007E8: nop

;}
RECOMP_FUNC void ncbadeflect_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800188: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080018C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80800190: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80800194: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80800198: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8080019C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808001A0: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x808001A4: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x808001A8: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x808001AC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x808001B0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808001B4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808001B8: jal         0x800EFA4C
    // 0x808001BC: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x808001BC: nop

    after_0:
    // 0x808001C0: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808001C4: jal         0x80111094
    // 0x808001C8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80111094(rdram, ctx);
        goto after_1;
    // 0x808001C8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_1:
    // 0x808001CC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808001D0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808001D4: jal         0x800EFB24
    // 0x808001D8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x808001D8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x808001DC: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808001E0: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808001E4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808001E8: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x808001EC: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808001F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001F4: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x808001F8: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808001FC: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800200: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800204: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800208: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8080020C: add.s       $f20, $f18, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80800210: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x80800214: nop

    // 0x80800218: bc1tl       L_808002B4
    if (c1cs) {
        // 0x8080021C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002B4;
    }
    goto skip_0;
    // 0x8080021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800220: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800224: jal         0x8002DCA0
    // 0x80800228: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80800228: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8080022C: jal         0x800D8FF8
    // 0x80800230: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80800230: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_4:
    // 0x80800234: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800238: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080023C: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800240: jal         0x800F13F0
    // 0x80800244: sub.s       $f14, $f2, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f20.fl;
    func_800F13F0(rdram, ctx);
        goto after_5;
    // 0x80800244: sub.s       $f14, $f2, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f20.fl;
    after_5:
    // 0x80800248: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080024C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80800250: c.eq.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl == ctx->f18.fl;
    // 0x80800254: nop

    // 0x80800258: bc1fl       L_80800290
    if (!c1cs) {
        // 0x8080025C: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_80800290;
    }
    goto skip_1;
    // 0x8080025C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    skip_1:
    // 0x80800260: jal         0x800DC0C0
    // 0x80800264: nop

    func_800DC0C0(rdram, ctx);
        goto after_6;
    // 0x80800264: nop

    after_6:
    // 0x80800268: jal         0x800DC0C0
    // 0x8080026C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x8080026C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_7:
    // 0x80800270: jal         0x800DC0C0
    // 0x80800274: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x80800274: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80800278: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080027C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800280: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800284: jal         0x800EFA4C
    // 0x80800288: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80800288: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x8080028C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
L_80800290:
    // 0x80800290: jal         0x800EF368
    // 0x80800294: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800EF368(rdram, ctx);
        goto after_10;
    // 0x80800294: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_10:
    // 0x80800298: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080029C: jal         0x800EF04C
    // 0x808002A0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x808002A0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_11:
    // 0x808002A4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808002A8: jal         0x801110C4
    // 0x808002AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_801110C4(rdram, ctx);
        goto after_12;
    // 0x808002AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_12:
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002B4:
    // 0x808002B4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808002B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x808002BC: jr          $ra
    // 0x808002C0: nop

    return;
    // 0x808002C0: nop

    // 0x808002C4: nop

    // 0x808002C8: nop

    // 0x808002CC: nop

;}
RECOMP_FUNC void func_808000A4_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: jr          $ra
    // 0x808000A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8008B4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B4D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B4D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B4DC: jal         0x8008C27C
    // 0x8008B4E0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_8008C27C(rdram, ctx);
        goto after_0;
    // 0x8008B4E0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8008B4E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B4E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B4EC: jr          $ra
    // 0x8008B4F0: nop

    return;
    // 0x8008B4F0: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7C8: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A7C8);
    return;
    // 0x8008A7CC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
