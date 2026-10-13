#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800D91EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D91EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D91F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D91F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D91F8: jal         0x800D91B8
    // 0x800D91FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D91B8(rdram, ctx);
        goto after_0;
    // 0x800D91FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D9200: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D9204: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D9208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D920C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800D9210: nop

    // 0x800D9214: bc1f        L_800D9228
    if (!c1cs) {
        // 0x800D9218: nop
    
            goto L_800D9228;
    }
    // 0x800D9218: nop

    // 0x800D921C: swc1        $f2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f2.u32l;
    // 0x800D9220: b           L_800D9228
    // 0x800D9224: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D9228;
    // 0x800D9224: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9228:
    // 0x800D9228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D922C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D9230: jr          $ra
    // 0x800D9234: nop

    return;
    // 0x800D9234: nop

    // 0x800D9238: nop

    // 0x800D923C: nop

;}
RECOMP_FUNC void _chfishshootgame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A28: syscall     188
    recomp_syscall_handler(rdram, ctx, 0x80085A28);
    return;
    // 0x80085A2C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80804E1C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804E1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804E20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804E24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804E28: jal         0x800A3404
    // 0x80804E2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A3404(rdram, ctx);
        goto after_0;
    // 0x80804E2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80804E30: bne         $v0, $zero, L_80804E48
    if (ctx->r2 != 0) {
        // 0x80804E34: nop
    
            goto L_80804E48;
    }
    // 0x80804E34: nop

    // 0x80804E38: jal         0x800887B0
    // 0x80804E3C: nop

    _glcutDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80804E3C: nop

    after_1:
    // 0x80804E40: beq         $v0, $zero, L_80804E60
    if (ctx->r2 == 0) {
        // 0x80804E44: nop
    
            goto L_80804E60;
    }
    // 0x80804E44: nop

L_80804E48:
    // 0x80804E48: jal         0x80807BB8
    // 0x80804E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80804E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80804E50: jal         0x80807F5C
    // 0x80804E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807F5C_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80804E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80804E58: b           L_80804EA4
    // 0x80804E5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804EA4;
    // 0x80804E5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804E60:
    // 0x80804E60: jal         0x80807BB8
    // 0x80804E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80804E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80804E68: jal         0x80807DD4
    // 0x80804E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807DD4_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80804E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80804E70: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80804E74: ori         $a3, $a3, 0xEBEE
    ctx->r7 = ctx->r7 | 0XEBEE;
    // 0x80804E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804E7C: addiu       $a1, $zero, 0x30D
    ctx->r5 = ADD32(0, 0X30D);
    // 0x80804E80: jal         0x8008CC34
    // 0x80804E84: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loopStartingAt(rdram, ctx);
        goto after_6;
    // 0x80804E84: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_6:
    // 0x80804E88: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80804E8C: ori         $a3, $a3, 0xEBEE
    ctx->r7 = ctx->r7 | 0XEBEE;
    // 0x80804E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804E94: addiu       $a1, $zero, 0x311
    ctx->r5 = ADD32(0, 0X311);
    // 0x80804E98: jal         0x808002CC
    // 0x80804E9C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_808002CC_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80804E9C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_7:
    // 0x80804EA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804EA4:
    // 0x80804EA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804EA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804EAC: jr          $ra
    // 0x80804EB0: nop

    return;
    // 0x80804EB0: nop

;}
RECOMP_FUNC void func_800A0D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0D74: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A0D78: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0D7C: jr          $ra
    // 0x800A0D80: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x800A0D80: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800EF9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF9A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EF9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EF9B0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800EF9B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EF9B8: jal         0x800137AC
    // 0x800EF9BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800137AC(rdram, ctx);
        goto after_0;
    // 0x800EF9BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800EF9C0: jal         0x800137C4
    // 0x800EF9C4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800137C4(rdram, ctx);
        goto after_1;
    // 0x800EF9C4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800EF9C8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800EF9CC: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EF9D0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800EF9D4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EF9D8: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EF9DC: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800EF9E0: nop

    // 0x800EF9E4: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800EF9E8: nop

    // 0x800EF9EC: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800EF9F0: nop

    // 0x800EF9F4: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF9F8: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EF9FC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EFA00: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800EFA04: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EFA08: swc1        $f14, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f14.u32l;
    // 0x800EFA0C: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x800EFA10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EFA14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EFA18: jr          $ra
    // 0x800EFA1C: nop

    return;
    // 0x800EFA1C: nop

;}
RECOMP_FUNC void func_800C911C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C911C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C9120: jr          $ra
    // 0x800C9124: addiu       $v0, $v0, -0x5500
    ctx->r2 = ADD32(ctx->r2, -0X5500);
    return;
    // 0x800C9124: addiu       $v0, $v0, -0x5500
    ctx->r2 = ADD32(ctx->r2, -0X5500);
;}
RECOMP_FUNC void func_808002B8_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C8: jal         0x800DA298
    // 0x808002CC: addiu       $a0, $zero, 0x9F4
    ctx->r4 = ADD32(0, 0X9F4);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808002CC: addiu       $a0, $zero, 0x9F4
    ctx->r4 = ADD32(0, 0X9F4);
    after_0:
    // 0x808002D0: bnel        $v0, $zero, L_808002EC
    if (ctx->r2 != 0) {
        // 0x808002D4: lw          $a0, 0x6C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X6C);
            goto L_808002EC;
    }
    goto skip_0;
    // 0x808002D4: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x808002D8: jal         0x800DA544
    // 0x808002DC: addiu       $a0, $zero, 0x9F4
    ctx->r4 = ADD32(0, 0X9F4);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808002DC: addiu       $a0, $zero, 0x9F4
    ctx->r4 = ADD32(0, 0X9F4);
    after_1:
    // 0x808002E0: jal         0x80800B60
    // 0x808002E4: nop

    func_80800B60_chtransparentfish(rdram, ctx);
        goto after_2;
    // 0x808002E4: nop

    after_2:
    // 0x808002E8: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
L_808002EC:
    // 0x808002EC: srl         $t6, $a0, 21
    ctx->r14 = S32(U32(ctx->r4) >> 21);
    // 0x808002F0: jal         0x80800EE0
    // 0x808002F4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_80800EE0_chtransparentfish(rdram, ctx);
        goto after_3;
    // 0x808002F4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
    // 0x808002F8: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x808002FC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800300: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800304: andi        $t8, $v0, 0x1FF
    ctx->r24 = ctx->r2 & 0X1FF;
    // 0x80800308: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x8080030C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800310: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080031C: jal         0x80089F48
    // 0x80800320: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800320: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    after_4:
    // 0x80800324: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800328: nop

    // 0x8080032C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800330: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80800334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800338: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080033C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800340: jr          $ra
    // 0x80800344: nop

    return;
    // 0x80800344: nop

;}
RECOMP_FUNC void func_800F1738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1738: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F173C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F1740: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800F1744: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800F1748: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x800F174C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800F1750: jal         0x800F1DCC
    // 0x800F1754: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x800F1754: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x800F1758: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F175C: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F1760: jal         0x800F1DCC
    // 0x800F1764: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x800F1764: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800F1768: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800F176C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F1770: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F1774: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800F1778: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F177C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F1780: bc1fl       L_800F17BC
    if (!c1cs) {
        // 0x800F1784: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_800F17BC;
    }
    goto skip_0;
    // 0x800F1784: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_0:
    // 0x800F1788: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800F178C: nop

    // 0x800F1790: bc1fl       L_800F17A4
    if (!c1cs) {
        // 0x800F1794: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800F17A4;
    }
    goto skip_1;
    // 0x800F1794: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x800F1798: b           L_800F17E4
    // 0x800F179C: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
        goto L_800F17E4;
    // 0x800F179C: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
    // 0x800F17A0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800F17A4:
    // 0x800F17A4: nop

    // 0x800F17A8: bc1fl       L_800F17E8
    if (!c1cs) {
        // 0x800F17AC: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800F17E8;
    }
    goto skip_2;
    // 0x800F17AC: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_2:
    // 0x800F17B0: b           L_800F17E4
    // 0x800F17B4: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
        goto L_800F17E4;
    // 0x800F17B4: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
    // 0x800F17B8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_800F17BC:
    // 0x800F17BC: nop

    // 0x800F17C0: bc1fl       L_800F17D4
    if (!c1cs) {
        // 0x800F17C4: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_800F17D4;
    }
    goto skip_3;
    // 0x800F17C4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_3:
    // 0x800F17C8: b           L_800F17E4
    // 0x800F17CC: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
        goto L_800F17E4;
    // 0x800F17CC: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
    // 0x800F17D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_800F17D4:
    // 0x800F17D4: nop

    // 0x800F17D8: bc1fl       L_800F17E8
    if (!c1cs) {
        // 0x800F17DC: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800F17E8;
    }
    goto skip_4;
    // 0x800F17DC: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_4:
    // 0x800F17E0: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
L_800F17E4:
    // 0x800F17E4: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_800F17E8:
    // 0x800F17E8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800F17EC: jr          $ra
    // 0x800F17F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F17F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F17F4: nop

    // 0x800F17F8: nop

    // 0x800F17FC: nop

;}
RECOMP_FUNC void func_80800360_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800364: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800368: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080036C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800370: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800374: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800378: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8080037C: jal         0x80100094
    // 0x80800380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800384: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800388: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080038C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80800390: beq         $a2, $at, L_808003C8
    if (ctx->r6 == ctx->r1) {
        // 0x80800394: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_808003C8;
    }
    // 0x80800394: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800398: beq         $a2, $at, L_808003E4
    if (ctx->r6 == ctx->r1) {
        // 0x8080039C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_808003E4;
    }
    // 0x8080039C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808003A0: beq         $a2, $at, L_808004A8
    if (ctx->r6 == ctx->r1) {
        // 0x808003A4: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_808004A8;
    }
    // 0x808003A4: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x808003A8: beq         $a2, $at, L_80800694
    if (ctx->r6 == ctx->r1) {
        // 0x808003AC: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80800694;
    }
    // 0x808003AC: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808003B0: beq         $a2, $at, L_808006D4
    if (ctx->r6 == ctx->r1) {
        // 0x808003B4: addiu       $at, $zero, 0x49
        ctx->r1 = ADD32(0, 0X49);
            goto L_808006D4;
    }
    // 0x808003B4: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808003B8: beql        $a2, $at, L_808006EC
    if (ctx->r6 == ctx->r1) {
        // 0x808003BC: lbu         $t7, 0x39($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X39);
            goto L_808006EC;
    }
    goto skip_0;
    // 0x808003BC: lbu         $t7, 0x39($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X39);
    skip_0:
    // 0x808003C0: b           L_8080078C
    // 0x808003C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080078C;
    // 0x808003C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003C8:
    // 0x808003C8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808003CC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x808003D0: lbu         $t7, 0x79($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X79);
    // 0x808003D4: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x808003D8: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x808003DC: b           L_8080078C
    // 0x808003E0: sb          $t9, 0x79($t6)
    MEM_B(0X79, ctx->r14) = ctx->r25;
        goto L_8080078C;
    // 0x808003E0: sb          $t9, 0x79($t6)
    MEM_B(0X79, ctx->r14) = ctx->r25;
L_808003E4:
    // 0x808003E4: lbu         $v1, 0x39($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X39);
    // 0x808003E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808003EC: beql        $v1, $zero, L_80800414
    if (ctx->r3 == 0) {
        // 0x808003F0: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80800414;
    }
    goto skip_1;
    // 0x808003F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_1:
    // 0x808003F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003F8: beq         $v1, $at, L_8080041C
    if (ctx->r3 == ctx->r1) {
        // 0x808003FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080041C;
    }
    // 0x808003FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800400: beql        $v1, $at, L_80800430
    if (ctx->r3 == ctx->r1) {
        // 0x80800404: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800430;
    }
    goto skip_2;
    // 0x80800404: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_2:
    // 0x80800408: b           L_80800440
    // 0x8080040C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
        goto L_80800440;
    // 0x8080040C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800410: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80800414:
    // 0x80800414: b           L_8080043C
    // 0x80800418: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
        goto L_8080043C;
    // 0x80800418: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_8080041C:
    // 0x8080041C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800420: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800424: b           L_8080043C
    // 0x80800428: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
        goto L_8080043C;
    // 0x80800428: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8080042C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800430:
    // 0x80800430: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800434: nop

    // 0x80800438: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
L_8080043C:
    // 0x8080043C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
L_80800440:
    // 0x80800440: jal         0x80085728
    // 0x80800444: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    _capod_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80800444: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80800448: beq         $v0, $zero, L_808004A0
    if (ctx->r2 == 0) {
        // 0x8080044C: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808004A0;
    }
    // 0x8080044C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800450: lbu         $a1, 0x39($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X39);
    // 0x80800454: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80800458: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080045C: jal         0x80089AD8
    // 0x80800460: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800460: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_2:
    // 0x80800464: jal         0x80106790
    // 0x80800468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80800468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080046C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800470: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80800474: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800478: lbu         $a1, 0x39($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X39);
    // 0x8080047C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80800480: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800484: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    // 0x80800488: jal         0x8008A208
    // 0x8080048C: addiu       $a1, $a1, 0xF3E
    ctx->r5 = ADD32(ctx->r5, 0XF3E);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080048C: addiu       $a1, $a1, 0xF3E
    ctx->r5 = ADD32(ctx->r5, 0XF3E);
    after_4:
    // 0x80800490: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800494: lbu         $t3, 0x65($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X65);
    // 0x80800498: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x8080049C: sb          $t4, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r12;
L_808004A0:
    // 0x808004A0: b           L_8080078C
    // 0x808004A4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080078C;
    // 0x808004A4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808004A8:
    // 0x808004A8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808004AC: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x808004B0: slti        $at, $v1, 0xF22
    ctx->r1 = SIGNED(ctx->r3) < 0XF22 ? 1 : 0;
    // 0x808004B4: bne         $at, $zero, L_808004F8
    if (ctx->r1 != 0) {
        // 0x808004B8: addiu       $t5, $v1, -0xF3E
        ctx->r13 = ADD32(ctx->r3, -0XF3E);
            goto L_808004F8;
    }
    // 0x808004B8: addiu       $t5, $v1, -0xF3E
    ctx->r13 = ADD32(ctx->r3, -0XF3E);
    // 0x808004BC: slti        $at, $v1, 0xF23
    ctx->r1 = SIGNED(ctx->r3) < 0XF23 ? 1 : 0;
    // 0x808004C0: bne         $at, $zero, L_808004E4
    if (ctx->r1 != 0) {
        // 0x808004C4: sltiu       $at, $t5, 0x1A
        ctx->r1 = ctx->r13 < 0X1A ? 1 : 0;
            goto L_808004E4;
    }
    // 0x808004C4: sltiu       $at, $t5, 0x1A
    ctx->r1 = ctx->r13 < 0X1A ? 1 : 0;
    // 0x808004C8: beq         $at, $zero, L_80800788
    if (ctx->r1 == 0) {
        // 0x808004CC: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80800788;
    }
    // 0x808004CC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x808004D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4E1C) << 16);
    // 0x808004D4: addu        $at, $at, $t5
    gpr jr_addend_808004DC = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x808004D8: lw          $t5, 0x4E1C($at)
    ctx->r13 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E1C));
    // 0x808004DC: jr          $t5
    // 0x808004E0: nop

    switch (jr_addend_808004DC >> 2) {
        case 0: goto L_80800680; break;
        case 1: goto L_80800680; break;
        case 2: goto L_80800680; break;
        case 3: goto L_80800788; break;
        case 4: goto L_80800788; break;
        case 5: goto L_80800788; break;
        case 6: goto L_80800788; break;
        case 7: goto L_80800788; break;
        case 8: goto L_80800788; break;
        case 9: goto L_80800788; break;
        case 10: goto L_80800788; break;
        case 11: goto L_80800788; break;
        case 12: goto L_80800788; break;
        case 13: goto L_80800788; break;
        case 14: goto L_80800788; break;
        case 15: goto L_80800520; break;
        case 16: goto L_80800520; break;
        case 17: goto L_80800788; break;
        case 18: goto L_80800788; break;
        case 19: goto L_8080056C; break;
        case 20: goto L_8080056C; break;
        case 21: goto L_80800788; break;
        case 22: goto L_80800788; break;
        case 23: goto L_80800788; break;
        case 24: goto L_80800788; break;
        case 25: goto L_80800554; break;
        default: switch_error(__func__, 0x808004DC, 0x80804E1C);
    }
    // 0x808004E0: nop

L_808004E4:
    // 0x808004E4: addiu       $at, $zero, 0xF22
    ctx->r1 = ADD32(0, 0XF22);
    // 0x808004E8: beql        $v1, $at, L_80800558
    if (ctx->r3 == ctx->r1) {
        // 0x808004EC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800558;
    }
    goto skip_3;
    // 0x808004EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_3:
    // 0x808004F0: b           L_8080078C
    // 0x808004F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x808004F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004F8:
    // 0x808004F8: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x808004FC: beq         $v1, $at, L_8080057C
    if (ctx->r3 == ctx->r1) {
        // 0x80800500: addiu       $at, $zero, 0xF1C
        ctx->r1 = ADD32(0, 0XF1C);
            goto L_8080057C;
    }
    // 0x80800500: addiu       $at, $zero, 0xF1C
    ctx->r1 = ADD32(0, 0XF1C);
    // 0x80800504: beq         $v1, $at, L_808005FC
    if (ctx->r3 == ctx->r1) {
        // 0x80800508: addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
            goto L_808005FC;
    }
    // 0x80800508: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x8080050C: addiu       $at, $zero, 0xF21
    ctx->r1 = ADD32(0, 0XF21);
    // 0x80800510: beql        $v1, $at, L_80800558
    if (ctx->r3 == ctx->r1) {
        // 0x80800514: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800558;
    }
    goto skip_4;
    // 0x80800514: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_4:
    // 0x80800518: b           L_8080078C
    // 0x8080051C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x8080051C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800520:
    // 0x80800520: lbu         $a1, 0x39($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X39);
    // 0x80800524: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800528: lw          $a2, 0x20($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X20);
    // 0x8080052C: jal         0x800D2054
    // 0x80800530: addiu       $a1, $a1, 0x8E
    ctx->r5 = ADD32(ctx->r5, 0X8E);
    func_800D2054(rdram, ctx);
        goto after_5;
    // 0x80800530: addiu       $a1, $a1, 0x8E
    ctx->r5 = ADD32(ctx->r5, 0X8E);
    after_5:
    // 0x80800534: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800538: bne         $v0, $at, L_80800554
    if (ctx->r2 != ctx->r1) {
        // 0x8080053C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800554;
    }
    // 0x8080053C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800540: addiu       $a1, $zero, 0xF57
    ctx->r5 = ADD32(0, 0XF57);
    // 0x80800544: jal         0x80800000
    // 0x80800548: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_chstoneballcontrol(rdram, ctx);
        goto after_6;
    // 0x80800548: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8080054C: b           L_8080078C
    // 0x80800550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x80800550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800554:
    // 0x80800554: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80800558:
    // 0x80800558: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x8080055C: jal         0x80800000
    // 0x80800560: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80800000_chstoneballcontrol(rdram, ctx);
        goto after_7;
    // 0x80800560: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_7:
    // 0x80800564: b           L_8080078C
    // 0x80800568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x80800568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080056C:
    // 0x8080056C: jal         0x80088180
    // 0x80800570: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x80800570: nop

    after_8:
    // 0x80800574: b           L_8080078C
    // 0x80800578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x80800578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080057C:
    // 0x8080057C: jal         0x800D395C
    // 0x80800580: nop

    func_800D395C(rdram, ctx);
        goto after_9;
    // 0x80800580: nop

    after_9:
    // 0x80800584: beq         $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x80800588: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_808005BC;
    }
    // 0x80800588: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080058C: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80800590: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800594: bne         $t7, $at, L_808005AC
    if (ctx->r15 != ctx->r1) {
        // 0x80800598: nop
    
            goto L_808005AC;
    }
    // 0x80800598: nop

    // 0x8080059C: jal         0x80088188
    // 0x808005A0: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x808005A0: nop

    after_10:
    // 0x808005A4: b           L_8080078C
    // 0x808005A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x808005A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005AC:
    // 0x808005AC: jal         0x80088180
    // 0x808005B0: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_11;
    // 0x808005B0: nop

    after_11:
    // 0x808005B4: b           L_8080078C
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005BC:
    // 0x808005BC: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x808005C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005C4: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    // 0x808005C8: bne         $t8, $at, L_808005EC
    if (ctx->r24 != ctx->r1) {
        // 0x808005CC: nop
    
            goto L_808005EC;
    }
    // 0x808005CC: nop

    // 0x808005D0: jal         0x800EA05C
    // 0x808005D4: nop

    func_800EA05C(rdram, ctx);
        goto after_12;
    // 0x808005D4: nop

    after_12:
    // 0x808005D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005DC: jal         0x80087A58
    // 0x808005E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x808005E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808005E4: b           L_8080078C
    // 0x808005E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x808005E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005EC:
    // 0x808005EC: jal         0x80087A58
    // 0x808005F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x808005F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x808005F4: b           L_8080078C
    // 0x808005F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x808005F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005FC:
    // 0x808005FC: jal         0x800FDC28
    // 0x80800600: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800FDC28(rdram, ctx);
        goto after_15;
    // 0x80800600: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_15:
    // 0x80800604: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800608: jal         0x80800130
    // 0x8080060C: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    func_80800130_chstoneballcontrol(rdram, ctx);
        goto after_16;
    // 0x8080060C: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    after_16:
    // 0x80800610: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800614: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800618: jal         0x80800130
    // 0x8080061C: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    func_80800130_chstoneballcontrol(rdram, ctx);
        goto after_17;
    // 0x8080061C: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    after_17:
    // 0x80800620: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80800624: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800628: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080062C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800630: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80800634: nop

    // 0x80800638: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080063C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800640: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800644: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800648: jal         0x800CE8D8
    // 0x8080064C: nop

    func_800CE8D8(rdram, ctx);
        goto after_18;
    // 0x8080064C: nop

    after_18:
    // 0x80800650: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800654: jal         0x800CE88C
    // 0x80800658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_19;
    // 0x80800658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x8080065C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800660: jal         0x80801734
    // 0x80800664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801734_chstoneballcontrol(rdram, ctx);
        goto after_20;
    // 0x80800664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80800668: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8080066C: lbu         $t1, 0x72($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X72);
    // 0x80800670: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x80800674: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80800678: b           L_80800788
    // 0x8080067C: sb          $t3, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r11;
        goto L_80800788;
    // 0x8080067C: sb          $t3, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r11;
L_80800680:
    // 0x80800680: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800684: lbu         $t4, 0x65($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X65);
    // 0x80800688: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x8080068C: b           L_80800788
    // 0x80800690: sb          $t5, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r13;
        goto L_80800788;
    // 0x80800690: sb          $t5, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r13;
L_80800694:
    // 0x80800694: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800698: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x8080069C: addiu       $at, $zero, 0xF51
    ctx->r1 = ADD32(0, 0XF51);
    // 0x808006A0: beq         $v1, $at, L_808006B8
    if (ctx->r3 == ctx->r1) {
        // 0x808006A4: addiu       $at, $zero, 0xF57
        ctx->r1 = ADD32(0, 0XF57);
            goto L_808006B8;
    }
    // 0x808006A4: addiu       $at, $zero, 0xF57
    ctx->r1 = ADD32(0, 0XF57);
    // 0x808006A8: beql        $v1, $at, L_808006C4
    if (ctx->r3 == ctx->r1) {
        // 0x808006AC: lbu         $a0, 0x39($t0)
        ctx->r4 = MEM_BU(ctx->r8, 0X39);
            goto L_808006C4;
    }
    goto skip_5;
    // 0x808006AC: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    skip_5:
    // 0x808006B0: b           L_8080078C
    // 0x808006B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x808006B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006B8:
    // 0x808006B8: b           L_8080078C
    // 0x808006BC: lbu         $v0, 0x3B($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X3B);
        goto L_8080078C;
    // 0x808006BC: lbu         $v0, 0x3B($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X3B);
    // 0x808006C0: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
L_808006C4:
    // 0x808006C4: jal         0x800D211C
    // 0x808006C8: addiu       $a0, $a0, 0x8E
    ctx->r4 = ADD32(ctx->r4, 0X8E);
    func_800D211C(rdram, ctx);
        goto after_21;
    // 0x808006C8: addiu       $a0, $a0, 0x8E
    ctx->r4 = ADD32(ctx->r4, 0X8E);
    after_21:
    // 0x808006CC: b           L_80800790
    // 0x808006D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800790;
    // 0x808006D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006D4:
    // 0x808006D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808006D8: jal         0x80800210
    // 0x808006DC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_80800210_chstoneballcontrol(rdram, ctx);
        goto after_22;
    // 0x808006DC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_22:
    // 0x808006E0: b           L_8080078C
    // 0x808006E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x808006E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808006E8: lbu         $t7, 0x39($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X39);
L_808006EC:
    // 0x808006EC: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x808006F0: beq         $at, $zero, L_80800788
    if (ctx->r1 == 0) {
        // 0x808006F4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800788;
    }
    // 0x808006F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808006F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4E84) << 16);
    // 0x808006FC: addu        $at, $at, $t7
    gpr jr_addend_80800704 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800700: lw          $t7, 0x4E84($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E84));
    // 0x80800704: jr          $t7
    // 0x80800708: nop

    switch (jr_addend_80800704 >> 2) {
        case 0: goto L_8080070C; break;
        case 1: goto L_8080070C; break;
        case 2: goto L_8080070C; break;
        case 3: goto L_80800788; break;
        case 4: goto L_80800770; break;
        default: switch_error(__func__, 0x80800704, 0x80804E84);
    }
    // 0x80800708: nop

L_8080070C:
    // 0x8080070C: jal         0x800D395C
    // 0x80800710: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800D395C(rdram, ctx);
        goto after_23;
    // 0x80800710: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_23:
    // 0x80800714: bne         $v0, $zero, L_80800760
    if (ctx->r2 != 0) {
        // 0x80800718: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_80800760;
    }
    // 0x80800718: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8080071C: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    // 0x80800720: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800724: jal         0x800DA9E4
    // 0x80800728: addiu       $a0, $a0, 0x41C
    ctx->r4 = ADD32(ctx->r4, 0X41C);
    func_800DA9E4(rdram, ctx);
        goto after_24;
    // 0x80800728: addiu       $a0, $a0, 0x41C
    ctx->r4 = ADD32(ctx->r4, 0X41C);
    after_24:
    // 0x8080072C: bne         $v0, $zero, L_80800760
    if (ctx->r2 != 0) {
        // 0x80800730: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_80800760;
    }
    // 0x80800730: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800734: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080073C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800740: jal         0x80085708
    // 0x80800744: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    _capod_entrypoint_13(rdram, ctx);
        goto after_25;
    // 0x80800744: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    after_25:
    // 0x80800748: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8080074C: lbu         $t9, 0x79($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X79);
    // 0x80800750: andi        $t6, $t9, 0xFF0F
    ctx->r14 = ctx->r25 & 0XFF0F;
    // 0x80800754: ori         $t1, $t6, 0x10
    ctx->r9 = ctx->r14 | 0X10;
    // 0x80800758: b           L_80800788
    // 0x8080075C: sb          $t1, 0x79($v1)
    MEM_B(0X79, ctx->r3) = ctx->r9;
        goto L_80800788;
    // 0x8080075C: sb          $t1, 0x79($v1)
    MEM_B(0X79, ctx->r3) = ctx->r9;
L_80800760:
    // 0x80800760: jal         0x800A54F8
    // 0x80800764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A54F8(rdram, ctx);
        goto after_26;
    // 0x80800764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x80800768: b           L_8080078C
    // 0x8080076C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x8080076C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800770:
    // 0x80800770: jal         0x8008A0A8
    // 0x80800774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _subaddiemulti_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x80800774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x80800778: b           L_8080078C
    // 0x8080077C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080078C;
    // 0x8080077C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800780: b           L_8080078C
    // 0x80800784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080078C;
    // 0x80800784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800788:
    // 0x80800788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080078C:
    // 0x8080078C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800790:
    // 0x80800790: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800794: jr          $ra
    // 0x80800798: nop

    return;
    // 0x80800798: nop

;}
RECOMP_FUNC void func_80111C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111C04: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80111C08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80111C0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80111C10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111C14: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80111C18: jal         0x801107F0
    // 0x80111C1C: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x80111C1C: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    after_0:
    // 0x80111C20: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80111C24: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80111C28: addiu       $a1, $v0, 0x68
    ctx->r5 = ADD32(ctx->r2, 0X68);
    // 0x80111C2C: jal         0x800EFB24
    // 0x80111C30: addiu       $a2, $v0, 0x5C
    ctx->r6 = ADD32(ctx->r2, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x80111C30: addiu       $a2, $v0, 0x5C
    ctx->r6 = ADD32(ctx->r2, 0X5C);
    after_1:
    // 0x80111C34: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80111C38: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80111C3C: addiu       $a1, $v0, 0x50
    ctx->r5 = ADD32(ctx->r2, 0X50);
    // 0x80111C40: jal         0x800EFB24
    // 0x80111C44: addiu       $a2, $v0, 0x5C
    ctx->r6 = ADD32(ctx->r2, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80111C44: addiu       $a2, $v0, 0x5C
    ctx->r6 = ADD32(ctx->r2, 0X5C);
    after_2:
    // 0x80111C48: jal         0x800EF2A0
    // 0x80111C4C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EF2A0(rdram, ctx);
        goto after_3;
    // 0x80111C4C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80111C50: jal         0x800EF2A0
    // 0x80111C54: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EF2A0(rdram, ctx);
        goto after_4;
    // 0x80111C54: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80111C58: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80111C5C: jal         0x800EEAA4
    // 0x80111C60: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EEAA4(rdram, ctx);
        goto after_5;
    // 0x80111C60: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x80111C64: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80111C68: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80111C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111C70: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80111C74: nop

    // 0x80111C78: bc1tl       L_80111C9C
    if (c1cs) {
        // 0x80111C7C: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_80111C9C;
    }
    goto skip_0;
    // 0x80111C7C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80111C80: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80111C84: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80111C88: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80111C8C: nop

    // 0x80111C90: bc1fl       L_80111CB4
    if (!c1cs) {
        // 0x80111C94: swc1        $f2, 0x74($v0)
        MEM_W(0X74, ctx->r2) = ctx->f2.u32l;
            goto L_80111CB4;
    }
    goto skip_1;
    // 0x80111C94: swc1        $f2, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f2.u32l;
    skip_1:
    // 0x80111C98: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_80111C9C:
    // 0x80111C9C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80111CA0: jal         0x80110770
    // 0x80111CA4: addiu       $a1, $a1, 0x5C
    ctx->r5 = ADD32(ctx->r5, 0X5C);
    func_80110770(rdram, ctx);
        goto after_6;
    // 0x80111CA4: addiu       $a1, $a1, 0x5C
    ctx->r5 = ADD32(ctx->r5, 0X5C);
    after_6:
    // 0x80111CA8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80111CAC: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80111CB0: swc1        $f2, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f2.u32l;
L_80111CB4:
    // 0x80111CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80111CB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80111CBC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80111CC0: jr          $ra
    // 0x80111CC4: nop

    return;
    // 0x80111CC4: nop

;}
RECOMP_FUNC void func_80111348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111348: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8011134C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111350: jal         0x801113B8
    // 0x80111354: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_801113B8(rdram, ctx);
        goto after_0;
    // 0x80111354: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80111358: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8011135C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80111360: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80111364: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80111368: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8011136C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80111370: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80111374: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80111378: jal         0x80111590
    // 0x8011137C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80111590(rdram, ctx);
        goto after_1;
    // 0x8011137C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80111380: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80111384: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80111388: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8011138C: jal         0x80111B8C
    // 0x80111390: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    func_80111B8C(rdram, ctx);
        goto after_2;
    // 0x80111390: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_2:
    // 0x80111394: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80111398: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    // 0x8011139C: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x801113A0: jal         0x801120CC
    // 0x801113A4: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    func_801120CC(rdram, ctx);
        goto after_3;
    // 0x801113A4: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    after_3:
    // 0x801113A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801113AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801113B0: jr          $ra
    // 0x801113B4: nop

    return;
    // 0x801113B4: nop

;}
RECOMP_FUNC void func_80805F48_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805F48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80805F4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805F50: jal         0x808061AC
    // 0x80805F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808061AC_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80805F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80805F58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80805F5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80805F60: jr          $ra
    // 0x80805F64: nop

    return;
    // 0x80805F64: nop

;}
RECOMP_FUNC void _bsturn_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840F8: syscall     103
    recomp_syscall_handler(rdram, ctx, 0x800840F8);
    return;
    // 0x800840FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801588_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080158C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801590: jal         0x808002D4
    // 0x80801594: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801594: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801598: jal         0x80082FE0
    // 0x8080159C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080159C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808015A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808015A8: jr          $ra
    // 0x808015AC: nop

    return;
    // 0x808015AC: nop

;}
RECOMP_FUNC void func_808010D8_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808010E4: jal         0x80100094
    // 0x808010E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808010E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808010EC: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    // 0x808010F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808010F4: jal         0x800899C8
    // 0x808010F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x808010F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x808010FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801104: jr          $ra
    // 0x80801108: nop

    return;
    // 0x80801108: nop

;}
RECOMP_FUNC void func_800A1F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1F78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1F7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1F80: jal         0x800EA05C
    // 0x800A1F84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800A1F84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A1F88: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800A1F8C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A1F90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A1F94: lw          $t6, 0x108($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X108);
    // 0x800A1F98: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A1F9C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A1FA0: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    // 0x800A1FA4: lw          $t7, 0x108($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X108);
    // 0x800A1FA8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A1FAC: addiu       $v1, $t2, -0x6DA0
    ctx->r3 = ADD32(ctx->r10, -0X6DA0);
    // 0x800A1FB0: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x800A1FB4: lw          $t8, 0x108($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X108);
    // 0x800A1FB8: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    // 0x800A1FBC: lw          $t0, 0x108($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X108);
    // 0x800A1FC0: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x800A1FC4: lh          $t1, -0x6DA0($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6DA0);
    // 0x800A1FC8: beql        $t1, $zero, L_800A2000
    if (ctx->r9 == 0) {
        // 0x800A1FCC: lw          $v0, 0x108($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X108);
            goto L_800A2000;
    }
    goto skip_0;
    // 0x800A1FCC: lw          $v0, 0x108($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X108);
    skip_0:
    // 0x800A1FD0: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
L_800A1FD4:
    // 0x800A1FD4: bnel        $v0, $a0, L_800A1FF0
    if (ctx->r2 != ctx->r4) {
        // 0x800A1FD8: lh          $a0, 0x2($v1)
        ctx->r4 = MEM_H(ctx->r3, 0X2);
            goto L_800A1FF0;
    }
    goto skip_1;
    // 0x800A1FD8: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    skip_1:
    // 0x800A1FDC: lw          $t4, 0x108($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X108);
    // 0x800A1FE0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800A1FE4: b           L_800A1FFC
    // 0x800A1FE8: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
        goto L_800A1FFC;
    // 0x800A1FE8: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    // 0x800A1FEC: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
L_800A1FF0:
    // 0x800A1FF0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800A1FF4: bne         $a0, $zero, L_800A1FD4
    if (ctx->r4 != 0) {
        // 0x800A1FF8: nop
    
            goto L_800A1FD4;
    }
    // 0x800A1FF8: nop

L_800A1FFC:
    // 0x800A1FFC: lw          $v0, 0x108($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X108);
L_800A2000:
    // 0x800A2000: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x800A2004: sb          $t5, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r13;
    // 0x800A2008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A200C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A2010: jr          $ra
    // 0x800A2014: nop

    return;
    // 0x800A2014: nop

;}
RECOMP_FUNC void func_80800000_chtoxicroomprops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800004: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080000C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800018: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080001C: beq         $t6, $at, L_80800038
    if (ctx->r14 == ctx->r1) {
        // 0x80800020: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800038;
    }
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800028: beq         $t6, $at, L_80800048
    if (ctx->r14 == ctx->r1) {
        // 0x8080002C: addiu       $a0, $zero, 0x178
        ctx->r4 = ADD32(0, 0X178);
            goto L_80800048;
    }
    // 0x8080002C: addiu       $a0, $zero, 0x178
    ctx->r4 = ADD32(0, 0X178);
    // 0x80800030: b           L_808002FC
    // 0x80800034: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808002FC;
    // 0x80800034: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800038:
    // 0x80800038: jal         0x80103110
    // 0x8080003C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x8080003C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800040: b           L_808002FC
    // 0x80800044: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808002FC;
    // 0x80800044: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800048:
    // 0x80800048: jal         0x80089C30
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800050: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800054: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80800058: lui         $at, 0x4341
    ctx->r1 = S32(0X4341 << 16);
    // 0x8080005C: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80800060: bltz        $t9, L_808000AC
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800064: nop
    
            goto L_808000AC;
    }
    // 0x80800064: nop

    // 0x80800068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080006C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800070: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800074: nop

    // 0x80800078: bc1f        L_808000AC
    if (!c1cs) {
        // 0x8080007C: nop
    
            goto L_808000AC;
    }
    // 0x8080007C: nop

    // 0x80800080: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x80800084: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x80800088: jal         0x80086B58
    // 0x8080008C: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080008C: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
    after_2:
    // 0x80800090: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800094: addiu       $t3, $zero, 0xA3
    ctx->r11 = ADD32(0, 0XA3);
    // 0x80800098: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080009C: addiu       $a1, $zero, 0x133D
    ctx->r5 = ADD32(0, 0X133D);
    // 0x808000A0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808000A4: jal         0x8008A208
    // 0x808000A8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808000A8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_3:
L_808000AC:
    // 0x808000AC: jal         0x800DC0C0
    // 0x808000B0: nop

    func_800DC0C0(rdram, ctx);
        goto after_4;
    // 0x808000B0: nop

    after_4:
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2492, 0X970) << 16);
    // 0x808000B8: lwc1        $f8, 0x970($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2492, 0X970));
    // 0x808000BC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808000C0: nop

    // 0x808000C4: bc1f        L_80800258
    if (!c1cs) {
        // 0x808000C8: nop
    
            goto L_80800258;
    }
    // 0x808000C8: nop

    // 0x808000CC: jal         0x80089C90
    // 0x808000D0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808000D0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_5:
    // 0x808000D4: slti        $at, $v0, 0x51
    ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
    // 0x808000D8: bne         $at, $zero, L_80800258
    if (ctx->r1 != 0) {
        // 0x808000DC: addiu       $t4, $sp, 0x40
        ctx->r12 = ADD32(ctx->r29, 0X40);
            goto L_80800258;
    }
    // 0x808000DC: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x808000E0: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2492, 0X9A0) << 16);
    // 0x808000E4: addiu       $t5, $t5, 0x9A0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2492, 0X9A0));
    // 0x808000E8: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x808000EC: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x808000F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808000F4: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x808000F8: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x808000FC: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80800100: jal         0x800B53A4
    // 0x80800104: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    func_800B53A4(rdram, ctx);
        goto after_6;
    // 0x80800104: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    after_6:
    // 0x80800108: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2492, 0X9AC) << 16);
    // 0x8080010C: addiu       $t8, $t8, 0x9AC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2492, 0X9AC));
    // 0x80800110: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800114: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080011C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800124: jal         0x800BABB8
    // 0x80800128: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800128: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_7:
    // 0x8080012C: lui         $at, 0x4341
    ctx->r1 = S32(0X4341 << 16);
    // 0x80800130: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800134: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800138: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    // 0x8080013C: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80800140: nop

    // 0x80800144: bc1fl       L_8080017C
    if (!c1cs) {
        // 0x80800148: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8080017C;
    }
    goto skip_0;
    // 0x80800148: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x8080014C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800150: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800154: jal         0x800F1214
    // 0x80800158: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    func_800F1214(rdram, ctx);
        goto after_8;
    // 0x80800158: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    after_8:
    // 0x8080015C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800160: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80800164: nop

    // 0x80800168: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8080016C: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x80800170: b           L_808001A0
    // 0x80800174: sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8 << 1);
        goto L_808001A0;
    // 0x80800174: sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8 << 1);
    // 0x80800178: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8080017C:
    // 0x8080017C: jal         0x800F1214
    // 0x80800180: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    func_800F1214(rdram, ctx);
        goto after_9;
    // 0x80800180: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    after_9:
    // 0x80800184: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800188: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8080018C: nop

    // 0x80800190: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80800194: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80800198: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8080019C: negu        $v1, $t2
    ctx->r3 = SUB32(0, ctx->r10);
L_808001A0:
    // 0x808001A0: lui         $at, 0x4341
    ctx->r1 = S32(0X4341 << 16);
    // 0x808001A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001A8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001AC: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    // 0x808001B0: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x808001B4: nop

    // 0x808001B8: bc1fl       L_808001F8
    if (!c1cs) {
        // 0x808001BC: lwc1        $f12, 0x24($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
            goto L_808001F8;
    }
    goto skip_1;
    // 0x808001BC: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x808001C0: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808001C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001C8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x808001CC: jal         0x800F1214
    // 0x808001D0: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    func_800F1214(rdram, ctx);
        goto after_10;
    // 0x808001D0: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    after_10:
    // 0x808001D4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808001D8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808001DC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x808001E0: nop

    // 0x808001E4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808001E8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x808001EC: b           L_80800224
    // 0x808001F0: sll         $v0, $t6, 1
    ctx->r2 = S32(ctx->r14 << 1);
        goto L_80800224;
    // 0x808001F0: sll         $v0, $t6, 1
    ctx->r2 = S32(ctx->r14 << 1);
    // 0x808001F4: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
L_808001F8:
    // 0x808001F8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001FC: jal         0x800F1214
    // 0x80800200: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800F1214(rdram, ctx);
        goto after_11;
    // 0x80800200: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_11:
    // 0x80800204: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800208: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8080020C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80800210: nop

    // 0x80800214: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80800218: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x8080021C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80800220: negu        $v0, $t5
    ctx->r2 = SUB32(0, ctx->r13);
L_80800224:
    // 0x80800224: sll         $a3, $v1, 16
    ctx->r7 = S32(ctx->r3 << 16);
    // 0x80800228: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8080022C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80800230: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080023C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800240: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800244: jal         0x800BA450
    // 0x80800248: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800BA450(rdram, ctx);
        goto after_12;
    // 0x80800248: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_12:
    // 0x8080024C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800250: jal         0x800BA22C
    // 0x80800254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_13;
    // 0x80800254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
L_80800258:
    // 0x80800258: jal         0x800DA298
    // 0x8080025C: addiu       $a0, $zero, 0x1BC
    ctx->r4 = ADD32(0, 0X1BC);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x8080025C: addiu       $a0, $zero, 0x1BC
    ctx->r4 = ADD32(0, 0X1BC);
    after_14:
    // 0x80800260: bne         $v0, $zero, L_8080029C
    if (ctx->r2 != 0) {
        // 0x80800264: lui         $at, 0x4341
        ctx->r1 = S32(0X4341 << 16);
            goto L_8080029C;
    }
    // 0x80800264: lui         $at, 0x4341
    ctx->r1 = S32(0X4341 << 16);
    // 0x80800268: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080026C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800270: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80800274: nop

    // 0x80800278: bc1fl       L_808002A0
    if (!c1cs) {
        // 0x8080027C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A0;
    }
    goto skip_2;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800280: jal         0x800DA544
    // 0x80800284: addiu       $a0, $zero, 0x1BC
    ctx->r4 = ADD32(0, 0X1BC);
    func_800DA544(rdram, ctx);
        goto after_15;
    // 0x80800284: addiu       $a0, $zero, 0x1BC
    ctx->r4 = ADD32(0, 0X1BC);
    after_15:
    // 0x80800288: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080028C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800290: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800294: jal         0x80085708
    // 0x80800298: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    _capod_entrypoint_13(rdram, ctx);
        goto after_16;
    // 0x80800298: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    after_16:
L_8080029C:
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002A0:
    // 0x808002A0: jal         0x80800390
    // 0x808002A4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80800390_chtoxicroomprops(rdram, ctx);
        goto after_17;
    // 0x808002A4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_17:
    // 0x808002A8: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x808002AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002B0: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808002B4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x808002B8: nop

    // 0x808002BC: bc1fl       L_808002FC
    if (!c1cs) {
        // 0x808002C0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808002FC;
    }
    goto skip_3;
    // 0x808002C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808002C4: jal         0x80089C90
    // 0x808002C8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x808002C8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_18:
    // 0x808002CC: beq         $v0, $zero, L_808002F8
    if (ctx->r2 == 0) {
        // 0x808002D0: lui         $at, 0x4341
        ctx->r1 = S32(0X4341 << 16);
            goto L_808002F8;
    }
    // 0x808002D0: lui         $at, 0x4341
    ctx->r1 = S32(0X4341 << 16);
    // 0x808002D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002D8: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808002DC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808002E0: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x808002E4: nop

    // 0x808002E8: bc1fl       L_808002FC
    if (!c1cs) {
        // 0x808002EC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808002FC;
    }
    goto skip_4;
    // 0x808002EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x808002F0: jal         0x80089CC0
    // 0x808002F4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    _subaddiefade_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x808002F4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_19:
L_808002F8:
    // 0x808002F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002FC:
    // 0x808002FC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800300: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800304: jr          $ra
    // 0x80800308: nop

    return;
    // 0x80800308: nop

;}
RECOMP_FUNC void func_8010FD38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FD38: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8010FD3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010FD40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010FD44: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8010FD48: jal         0x80114CB0
    // 0x8010FD4C: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    func_80114CB0(rdram, ctx);
        goto after_0;
    // 0x8010FD4C: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    after_0:
    // 0x8010FD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010FD54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010FD58: jr          $ra
    // 0x8010FD5C: nop

    return;
    // 0x8010FD5C: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808034F8: beql        $a1, $zero, L_80803514
    if (ctx->r5 == 0) {
        // 0x808034FC: lbu         $t9, 0x1E5($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X1E5);
            goto L_80803514;
    }
    goto skip_0;
    // 0x808034FC: lbu         $t9, 0x1E5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E5);
    skip_0:
    // 0x80803500: lbu         $t7, 0x1E5($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E5);
    // 0x80803504: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x80803508: jr          $ra
    // 0x8080350C: sb          $t8, 0x1E5($a0)
    MEM_B(0X1E5, ctx->r4) = ctx->r24;
    return;
    // 0x8080350C: sb          $t8, 0x1E5($a0)
    MEM_B(0X1E5, ctx->r4) = ctx->r24;
    // 0x80803510: lbu         $t9, 0x1E5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E5);
L_80803514:
    // 0x80803514: andi        $t0, $t9, 0xFFFB
    ctx->r8 = ctx->r25 & 0XFFFB;
    // 0x80803518: sb          $t0, 0x1E5($a0)
    MEM_B(0X1E5, ctx->r4) = ctx->r8;
    // 0x8080351C: jr          $ra
    // 0x80803520: nop

    return;
    // 0x80803520: nop

;}
RECOMP_FUNC void func_801124D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801124D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801124D4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801124D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801124DC: bne         $a1, $at, L_80112500
    if (ctx->r5 != ctx->r1) {
        // 0x801124E0: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80112500;
    }
    // 0x801124E0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801124E4: lw          $a1, 0x30($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X30);
    // 0x801124E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x801124EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801124F0: jal         0x801121B8
    // 0x801124F4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_801121B8(rdram, ctx);
        goto after_0;
    // 0x801124F4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_0:
    // 0x801124F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801124FC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_80112500:
    // 0x80112500: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80112504: sw          $a2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r6;
    // 0x80112508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011250C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80112510: jr          $ra
    // 0x80112514: nop

    return;
    // 0x80112514: nop

;}
RECOMP_FUNC void _babackpack_set_state(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084538: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x80084538);
    return;
    // 0x8008453C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void chlensflare_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800EA05C
    // 0x8080000C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800010: jal         0x80088070
    // 0x80800014: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    _gcskyDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800014: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800018: bne         $v0, $zero, L_80800028
    if (ctx->r2 != 0) {
        // 0x8080001C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800028;
    }
    // 0x8080001C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: b           L_80800074
    // 0x80800024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800074;
    // 0x80800024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800028:
    // 0x80800028: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2296, 0X8F0) << 16);
    // 0x8080002C: lw          $t6, 0x8F0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(2296, 0X8F0));
    // 0x80800030: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800034: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800038: beq         $a0, $t6, L_80800070
    if (ctx->r4 == ctx->r14) {
        // 0x8080003C: sll         $t8, $t7, 3
        ctx->r24 = S32(ctx->r15 << 3);
            goto L_80800070;
    }
    // 0x8080003C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800040: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2296, 0X8F0) << 16);
    // 0x80800044: addiu       $t9, $t9, 0x8F0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2296, 0X8F0));
    // 0x80800048: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8080004C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_80800050:
    // 0x80800050: bnel        $a1, $v1, L_80800064
    if (ctx->r5 != ctx->r3) {
        // 0x80800054: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_80800064;
    }
    goto skip_0;
    // 0x80800054: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x80800058: b           L_80800074
    // 0x8080005C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800074;
    // 0x8080005C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800060: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_80800064:
    // 0x80800064: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80800068: bne         $a0, $v1, L_80800050
    if (ctx->r4 != ctx->r3) {
        // 0x8080006C: nop
    
            goto L_80800050;
    }
    // 0x8080006C: nop

L_80800070:
    // 0x80800070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800074:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void _badata_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084758: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084758);
    return;
    // 0x8008475C: addi        $t0, $zero, 0x8C
    ctx->r8 = ADD32(0, 0X8C);
;}
RECOMP_FUNC void bsbwhirl_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D64: jal         0x80082FE0
    // 0x80800D68: nop

    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800D68: nop

    after_0:
    // 0x80800D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D74: jr          $ra
    // 0x80800D78: nop

    return;
    // 0x80800D78: nop

;}
RECOMP_FUNC void gccollectDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080072C: jal         0x800CF87C
    // 0x80800730: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CF87C(rdram, ctx);
        goto after_0;
    // 0x80800730: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800734: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800738: bne         $v0, $at, L_80800748
    if (ctx->r2 != ctx->r1) {
        // 0x8080073C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800748;
    }
    // 0x8080073C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800740: b           L_8080076C
    // 0x80800744: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8080076C;
    // 0x80800744: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80800748:
    // 0x80800748: jal         0x800CF87C
    // 0x8080074C: nop

    func_800CF87C(rdram, ctx);
        goto after_1;
    // 0x8080074C: nop

    after_1:
    // 0x80800750: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x80800754: bne         $v0, $at, L_80800764
    if (ctx->r2 != ctx->r1) {
        // 0x80800758: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800764;
    }
    // 0x80800758: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080075C: b           L_8080076C
    // 0x80800760: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8080076C;
    // 0x80800760: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80800764:
    // 0x80800764: jal         0x808003E0
    // 0x80800768: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_808003E0_gccollectDll(rdram, ctx);
        goto after_2;
    // 0x80800768: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_8080076C:
    // 0x8080076C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800774: jr          $ra
    // 0x80800778: nop

    return;
    // 0x80800778: nop

;}
RECOMP_FUNC void chbounce_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808009C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009CC: jal         0x80104580
    // 0x808009D0: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    func_80104580(rdram, ctx);
        goto after_0;
    // 0x808009D0: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009D4: jal         0x800D8FF8
    // 0x808009D8: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808009D8: nop

    after_1:
    // 0x808009DC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x808009E0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808009E4: jal         0x80100094
    // 0x808009E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808009E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808009EC: lbu         $t6, 0x24($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X24);
    // 0x808009F0: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(712, 0XFE0) << 16);
    // 0x808009F4: addiu       $t9, $t9, 0xFE0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(712, 0XFE0));
    // 0x808009F8: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x808009FC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800A00: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800A04: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A08: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800A0C: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80800A10: lhu         $v1, 0x26($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X26);
    // 0x80800A14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A1C: srl         $t1, $v1, 13
    ctx->r9 = S32(U32(ctx->r3) >> 13);
    // 0x80800A20: beq         $t1, $at, L_80800A3C
    if (ctx->r9 == ctx->r1) {
        // 0x80800A24: lwc1        $f6, 0x74($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
            goto L_80800A3C;
    }
    // 0x80800A24: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800A28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A2C: beql        $t1, $at, L_80800DE8
    if (ctx->r9 == ctx->r1) {
        // 0x80800A30: lw          $t1, 0x6C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X6C);
            goto L_80800DE8;
    }
    goto skip_0;
    // 0x80800A30: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x80800A34: b           L_80800EBC
    // 0x80800A38: nop

        goto L_80800EBC;
    // 0x80800A38: nop

L_80800A3C:
    // 0x80800A3C: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800A40: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800A44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800A48: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800A4C: jal         0x800EE7F8
    // 0x80800A50: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800A50: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x80800A54: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80800A58: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80800A5C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800A60: jal         0x800EFA20
    // 0x80800A64: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    func_800EFA20(rdram, ctx);
        goto after_4;
    // 0x80800A64: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    after_4:
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A6C: jal         0x800EF04C
    // 0x80800A70: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800A70: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_5:
    // 0x80800A74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFC8) << 16);
    // 0x80800A78: lwc1        $f0, 0xFC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFC8));
    // 0x80800A7C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800A80: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80800A84: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800A88: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800A8C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x80800A90: bc1fl       L_80800AA8
    if (!c1cs) {
        // 0x80800A94: lw          $t5, 0x6C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X6C);
            goto L_80800AA8;
    }
    goto skip_1;
    // 0x80800A94: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    skip_1:
    // 0x80800A98: lbu         $t3, 0x24($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X24);
    // 0x80800A9C: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x80800AA0: sb          $t4, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r12;
    // 0x80800AA4: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
L_80800AA8:
    // 0x80800AA8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800AAC: lhu         $v0, 0x0($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X0);
    // 0x80800AB0: andi        $t6, $v0, 0x40
    ctx->r14 = ctx->r2 & 0X40;
    // 0x80800AB4: beq         $t6, $zero, L_80800AD0
    if (ctx->r14 == 0) {
        // 0x80800AB8: andi        $t7, $v0, 0x8
        ctx->r15 = ctx->r2 & 0X8;
            goto L_80800AD0;
    }
    // 0x80800AB8: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    // 0x80800ABC: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800AC0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800AC4: nop

    // 0x80800AC8: bc1tl       L_80800D6C
    if (c1cs) {
        // 0x80800ACC: andi        $t9, $v0, 0x100
        ctx->r25 = ctx->r2 & 0X100;
            goto L_80800D6C;
    }
    goto skip_2;
    // 0x80800ACC: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    skip_2:
L_80800AD0:
    // 0x80800AD0: jal         0x808007B8
    // 0x80800AD4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_808007B8_chbounce(rdram, ctx);
        goto after_6;
    // 0x80800AD4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_6:
    // 0x80800AD8: bne         $v0, $zero, L_80800B30
    if (ctx->r2 != 0) {
        // 0x80800ADC: lw          $v1, 0x6C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X6C);
            goto L_80800B30;
    }
    // 0x80800ADC: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80800AE0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80800AE4: andi        $t8, $v0, 0x200
    ctx->r24 = ctx->r2 & 0X200;
    // 0x80800AE8: beql        $t8, $zero, L_80800D6C
    if (ctx->r24 == 0) {
        // 0x80800AEC: andi        $t9, $v0, 0x100
        ctx->r25 = ctx->r2 & 0X100;
            goto L_80800D6C;
    }
    goto skip_3;
    // 0x80800AEC: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    skip_3:
    // 0x80800AF0: lh          $t9, 0x14($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X14);
    // 0x80800AF4: lh          $t1, 0x12($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X12);
    // 0x80800AF8: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800AFC: bgez        $t9, L_80800B0C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800B00: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_80800B0C;
    }
    // 0x80800B00: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80800B04: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x80800B08: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_80800B0C:
    // 0x80800B0C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80800B10: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80800B14: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800B18: nop

    // 0x80800B1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800B20: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80800B24: nop

    // 0x80800B28: bc1fl       L_80800D6C
    if (!c1cs) {
        // 0x80800B2C: andi        $t9, $v0, 0x100
        ctx->r25 = ctx->r2 & 0X100;
            goto L_80800D6C;
    }
    goto skip_4;
    // 0x80800B2C: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    skip_4:
L_80800B30:
    // 0x80800B30: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80800B34: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x80800B38: andi        $t5, $t4, 0x204
    ctx->r13 = ctx->r12 & 0X204;
    // 0x80800B3C: beql        $t5, $zero, L_80800B64
    if (ctx->r13 == 0) {
        // 0x80800B40: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800B64;
    }
    goto skip_5;
    // 0x80800B40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_5:
    // 0x80800B44: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800B48: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800B4C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800B50: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800B54: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80800B58: jal         0x800EFA4C
    // 0x80800B5C: nop

    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x80800B5C: nop

    after_7:
    // 0x80800B60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80800B64:
    // 0x80800B64: jal         0x800EF334
    // 0x80800B68: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    func_800EF334(rdram, ctx);
        goto after_8;
    // 0x80800B68: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    after_8:
    // 0x80800B6C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800B70: jal         0x800EEAA4
    // 0x80800B74: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EEAA4(rdram, ctx);
        goto after_9;
    // 0x80800B74: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_9:
    // 0x80800B78: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800B7C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800B80: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800B84: jal         0x800EF334
    // 0x80800B88: nop

    func_800EF334(rdram, ctx);
        goto after_10;
    // 0x80800B88: nop

    after_10:
    // 0x80800B8C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800B90: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800B94: jal         0x800EFB24
    // 0x80800B98: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_800EFB24(rdram, ctx);
        goto after_11;
    // 0x80800B98: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_11:
    // 0x80800B9C: lh          $t6, 0x30($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X30);
    // 0x80800BA0: lh          $t8, 0x28($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X28);
    // 0x80800BA4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800BA8: beq         $t8, $zero, L_80800C68
    if (ctx->r24 == 0) {
        // 0x80800BAC: sh          $t7, 0x30($s0)
        MEM_H(0X30, ctx->r16) = ctx->r15;
            goto L_80800C68;
    }
    // 0x80800BAC: sh          $t7, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r15;
    // 0x80800BB0: lhu         $t9, 0x32($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X32);
    // 0x80800BB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800BB8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800BBC: andi        $t0, $t9, 0x2000
    ctx->r8 = ctx->r25 & 0X2000;
    // 0x80800BC0: beql        $t0, $zero, L_80800BFC
    if (ctx->r8 == 0) {
        // 0x80800BC4: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80800BFC;
    }
    goto skip_6;
    // 0x80800BC4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_6:
    // 0x80800BC8: lh          $t1, 0x30($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X30);
    // 0x80800BCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800BD0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800BD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFCC) << 16);
    // 0x80800BD8: lwc1        $f16, 0xFCC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFCC));
    // 0x80800BDC: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80800BE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800BE4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80800BE8: jal         0x800F10B4
    // 0x80800BEC: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x80800BEC: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_12:
    // 0x80800BF0: b           L_80800C00
    // 0x80800BF4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800C00;
    // 0x80800BF4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800BF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80800BFC:
    // 0x80800BFC: nop

L_80800C00:
    // 0x80800C00: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800C04: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x80800C08: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80800C0C: jal         0x800C4B64
    // 0x80800C10: nop

    func_800C4B64(rdram, ctx);
        goto after_13;
    // 0x80800C10: nop

    after_13:
    // 0x80800C14: lh          $t2, 0x2A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2A);
    // 0x80800C18: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800C1C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80800C20: nop

    // 0x80800C24: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800C28: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80800C2C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800C30: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80800C34: jal         0x800C4B70
    // 0x80800C38: nop

    func_800C4B70(rdram, ctx);
        goto after_14;
    // 0x80800C38: nop

    after_14:
    // 0x80800C3C: jal         0x800C4B7C
    // 0x80800C40: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    func_800C4B7C(rdram, ctx);
        goto after_15;
    // 0x80800C40: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    after_15:
    // 0x80800C44: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80800C48: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(712, 0X14AC) << 16);
    // 0x80800C4C: addiu       $a3, $a3, 0x14AC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(712, 0X14AC));
    // 0x80800C50: lw          $a1, 0x70($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X70);
    // 0x80800C54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800C58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800C5C: andi        $t5, $a1, 0x1
    ctx->r13 = ctx->r5 & 0X1;
    // 0x80800C60: jal         0x8010D930
    // 0x80800C64: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    func_8010D930(rdram, ctx);
        goto after_16;
    // 0x80800C64: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_16:
L_80800C68:
    // 0x80800C68: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80800C6C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800C70: jal         0x800EF334
    // 0x80800C74: lw          $a1, 0x1C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1C);
    func_800EF334(rdram, ctx);
        goto after_17;
    // 0x80800C74: lw          $a1, 0x1C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1C);
    after_17:
    // 0x80800C78: jal         0x800EEF94
    // 0x80800C7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800EEF94(rdram, ctx);
        goto after_18;
    // 0x80800C7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_18:
    // 0x80800C80: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800C84: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C88: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800C8C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800C90: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800C94: nop

    // 0x80800C98: bc1fl       L_80800CB4
    if (!c1cs) {
        // 0x80800C9C: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80800CB4;
    }
    goto skip_7;
    // 0x80800C9C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    skip_7:
    // 0x80800CA0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800CA4: jal         0x800EF368
    // 0x80800CA8: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    func_800EF368(rdram, ctx);
        goto after_19;
    // 0x80800CA8: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    after_19:
    // 0x80800CAC: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800CB0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_80800CB4:
    // 0x80800CB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800CB8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800CBC: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800CC0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80800CC4: nop

    // 0x80800CC8: bc1fl       L_80800CE8
    if (!c1cs) {
        // 0x80800CCC: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80800CE8;
    }
    goto skip_8;
    // 0x80800CCC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_8:
    // 0x80800CD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800CD4: nop

    // 0x80800CD8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80800CDC: nop

    // 0x80800CE0: bc1t        L_80800D00
    if (c1cs) {
        // 0x80800CE4: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80800D00;
    }
    // 0x80800CE4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_80800CE8:
    // 0x80800CE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800CEC: nop

    // 0x80800CF0: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80800CF4: nop

    // 0x80800CF8: bc1fl       L_80800D3C
    if (!c1cs) {
        // 0x80800CFC: lw          $t6, 0x6C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X6C);
            goto L_80800D3C;
    }
    goto skip_9;
    // 0x80800CFC: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    skip_9:
L_80800D00:
    // 0x80800D00: lbu         $t7, 0x26($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X26);
    // 0x80800D04: lbu         $t1, 0x24($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X24);
    // 0x80800D08: andi        $t8, $t7, 0xFF1F
    ctx->r24 = ctx->r15 & 0XFF1F;
    // 0x80800D0C: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x80800D10: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80800D14: sb          $t9, 0x26($s0)
    MEM_B(0X26, ctx->r16) = ctx->r25;
    // 0x80800D18: sb          $t2, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r10;
    // 0x80800D1C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80800D20: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80800D24: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80800D28: beql        $t5, $zero, L_80800D3C
    if (ctx->r13 == 0) {
        // 0x80800D2C: lw          $t6, 0x6C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X6C);
            goto L_80800D3C;
    }
    goto skip_10;
    // 0x80800D2C: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    skip_10:
    // 0x80800D30: jal         0x8010A63C
    // 0x80800D34: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_8010A63C(rdram, ctx);
        goto after_20;
    // 0x80800D34: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_20:
    // 0x80800D38: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
L_80800D3C:
    // 0x80800D3C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80800D40: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x80800D44: beql        $t8, $zero, L_80800DD0
    if (ctx->r24 == 0) {
        // 0x80800D48: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80800DD0;
    }
    goto skip_11;
    // 0x80800D48: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    skip_11:
    // 0x80800D4C: jal         0x80105494
    // 0x80800D50: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80105494(rdram, ctx);
        goto after_21;
    // 0x80800D50: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_21:
    // 0x80800D54: beql        $v0, $zero, L_80800DD0
    if (ctx->r2 == 0) {
        // 0x80800D58: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80800DD0;
    }
    goto skip_12;
    // 0x80800D58: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    skip_12:
    // 0x80800D5C: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80800D60: b           L_80800DCC
    // 0x80800D64: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
        goto L_80800DCC;
    // 0x80800D64: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80800D68: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
L_80800D6C:
    // 0x80800D6C: beq         $t9, $zero, L_80800D90
    if (ctx->r25 == 0) {
        // 0x80800D70: lwc1        $f0, 0x10($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
            goto L_80800D90;
    }
    // 0x80800D70: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800D74: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80800D78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800D7C: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800D80: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800D84: sub.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800D88: b           L_80800DCC
    // 0x80800D8C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
        goto L_80800DCC;
    // 0x80800D8C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
L_80800D90:
    // 0x80800D90: andi        $t0, $v0, 0x800
    ctx->r8 = ctx->r2 & 0X800;
    // 0x80800D94: beq         $t0, $zero, L_80800DB8
    if (ctx->r8 == 0) {
        // 0x80800D98: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(712, 0XFD4) << 16);
            goto L_80800DB8;
    }
    // 0x80800D98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFD4) << 16);
    // 0x80800D9C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFD0) << 16);
    // 0x80800DA0: lwc1        $f6, 0xFD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFD0));
    // 0x80800DA4: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800DA8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800DAC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80800DB0: b           L_80800DCC
    // 0x80800DB4: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
        goto L_80800DCC;
    // 0x80800DB4: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
L_80800DB8:
    // 0x80800DB8: lwc1        $f4, 0xFD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFD4));
    // 0x80800DBC: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800DC0: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80800DC4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800DC8: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
L_80800DCC:
    // 0x80800DCC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_80800DD0:
    // 0x80800DD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800DD4: jal         0x800EE7F8
    // 0x80800DD8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_22;
    // 0x80800DD8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_22:
    // 0x80800DDC: b           L_80800EBC
    // 0x80800DE0: nop

        goto L_80800EBC;
    // 0x80800DE0: nop

    // 0x80800DE4: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
L_80800DE8:
    // 0x80800DE8: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800DEC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80800DF0: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80800DF4: beq         $t3, $zero, L_80800E80
    if (ctx->r11 == 0) {
        // 0x80800DF8: nop
    
            goto L_80800E80;
    }
    // 0x80800DF8: nop

    // 0x80800DFC: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80800E00: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800E04: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800E08: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800E0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800E10: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800E14: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800E18: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80800E1C: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800E20: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80800E24: nop

    // 0x80800E28: bc1fl       L_80800E50
    if (!c1cs) {
        // 0x80800E2C: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80800E50;
    }
    goto skip_13;
    // 0x80800E2C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_13:
    // 0x80800E30: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
L_80800E34:
    // 0x80800E34: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x80800E38: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800E3C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80800E40: nop

    // 0x80800E44: bc1tl       L_80800E34
    if (c1cs) {
        // 0x80800E48: sub.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80800E34;
    }
    goto skip_14;
    // 0x80800E48: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    skip_14:
    // 0x80800E4C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80800E50:
    // 0x80800E50: nop

    // 0x80800E54: bc1fl       L_80800E7C
    if (!c1cs) {
        // 0x80800E58: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_80800E7C;
    }
    goto skip_15;
    // 0x80800E58: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    skip_15:
    // 0x80800E5C: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
L_80800E60:
    // 0x80800E60: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x80800E64: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800E68: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80800E6C: nop

    // 0x80800E70: bc1tl       L_80800E60
    if (c1cs) {
        // 0x80800E74: add.s       $f10, $f0, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_80800E60;
    }
    goto skip_16;
    // 0x80800E74: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    skip_16:
    // 0x80800E78: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
L_80800E7C:
    // 0x80800E7C: swc1        $f0, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f0.u32l;
L_80800E80:
    // 0x80800E80: jal         0x800F2100
    // 0x80800E84: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    mlAbsF(rdram, ctx);
        goto after_23;
    // 0x80800E84: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    after_23:
    // 0x80800E88: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0XFD8) << 16);
    // 0x80800E8C: lwc1        $f16, 0xFD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(712, 0XFD8));
    // 0x80800E90: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80800E94: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800E98: nop

    // 0x80800E9C: bc1t        L_80800EB4
    if (c1cs) {
        // 0x80800EA0: nop
    
            goto L_80800EB4;
    }
    // 0x80800EA0: nop

    // 0x80800EA4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80800EA8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80800EAC: bne         $t7, $zero, L_80800EBC
    if (ctx->r15 != 0) {
        // 0x80800EB0: nop
    
            goto L_80800EBC;
    }
    // 0x80800EB0: nop

L_80800EB4:
    // 0x80800EB4: jal         0x80800F74
    // 0x80800EB8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80800F74_chbounce(rdram, ctx);
        goto after_24;
    // 0x80800EB8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_24:
L_80800EBC:
    // 0x80800EBC: jal         0x800BECCC
    // 0x80800EC0: nop

    func_800BECCC(rdram, ctx);
        goto after_25;
    // 0x80800EC0: nop

    after_25:
    // 0x80800EC4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800EC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800ECC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800ED0: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    // 0x80800ED4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800ED8: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800EDC: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80800EE0: nop

    // 0x80800EE4: bc1fl       L_80800F18
    if (!c1cs) {
        // 0x80800EE8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800F18;
    }
    goto skip_17;
    // 0x80800EE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_17:
    // 0x80800EEC: jal         0x8010108C
    // 0x80800EF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_26;
    // 0x80800EF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_26:
    // 0x80800EF4: blez        $v0, L_80800F0C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800EF8: nop
    
            goto L_80800F0C;
    }
    // 0x80800EF8: nop

    // 0x80800EFC: jal         0x80800F74
    // 0x80800F00: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80800F74_chbounce(rdram, ctx);
        goto after_27;
    // 0x80800F00: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_27:
    // 0x80800F04: b           L_80800F18
    // 0x80800F08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800F18;
    // 0x80800F08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F0C:
    // 0x80800F0C: jal         0x800FFAB0
    // 0x80800F10: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_800FFAB0(rdram, ctx);
        goto after_28;
    // 0x80800F10: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_28:
    // 0x80800F14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F18:
    // 0x80800F18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F1C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80800F20: jr          $ra
    // 0x80800F24: nop

    return;
    // 0x80800F24: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FD0: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087FD0);
    return;
    // 0x80087FD4: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void func_808021F4_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808021F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808021FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802200: jal         0x80100094
    // 0x80802204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80802208: beq         $v0, $zero, L_80802218
    if (ctx->r2 == 0) {
        // 0x8080220C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80802218;
    }
    // 0x8080220C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802210: jal         0x800897C8
    // 0x80802214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80802214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80802218:
    // 0x80802218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080221C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802220: jr          $ra
    // 0x80802224: nop

    return;
    // 0x80802224: nop

;}
RECOMP_FUNC void func_80800AB4_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800ABC: beq         $a3, $zero, L_80800AD8
    if (ctx->r7 == 0) {
        // 0x80800AC0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800AD8;
    }
    // 0x80800AC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800AC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AC8: beq         $a3, $at, L_80800AE8
    if (ctx->r7 == ctx->r1) {
        // 0x80800ACC: nop
    
            goto L_80800AE8;
    }
    // 0x80800ACC: nop

    // 0x80800AD0: b           L_80800AF4
    // 0x80800AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800AF4;
    // 0x80800AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AD8:
    // 0x80800AD8: jal         0x80800A04
    // 0x80800ADC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800A04_chcheato(rdram, ctx);
        goto after_0;
    // 0x80800ADC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800AE0: b           L_80800AF4
    // 0x80800AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800AF4;
    // 0x80800AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AE8:
    // 0x80800AE8: jal         0x80102424
    // 0x80800AEC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800AEC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80800AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AF4:
    // 0x80800AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AF8: jr          $ra
    // 0x80800AFC: nop

    return;
    // 0x80800AFC: nop

;}
RECOMP_FUNC void func_80800058_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080005C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800064: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080006C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800070: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80800074: jal         0x80800B78
    // 0x80800078: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    func_80800B78_chhoneyb(rdram, ctx);
        goto after_0;
    // 0x80800078: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    after_0:
    // 0x8080007C: jal         0x80088400
    // 0x80800080: addiu       $s0, $v0, 0x1
    ctx->r16 = ADD32(ctx->r2, 0X1);
    _gcextra_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800080: addiu       $s0, $v0, 0x1
    ctx->r16 = ADD32(ctx->r2, 0X1);
    after_1:
    // 0x80800084: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80800088: bnel        $at, $zero, L_808000F0
    if (ctx->r1 != 0) {
        // 0x8080008C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808000F0;
    }
    goto skip_0;
    // 0x8080008C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80800090:
    // 0x80800090: jal         0x80800B58
    // 0x80800094: nop

    func_80800B58_chhoneyb(rdram, ctx);
        goto after_2;
    // 0x80800094: nop

    after_2:
    // 0x80800098: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080009C: jal         0x80800B98
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B98_chhoneyb(rdram, ctx);
        goto after_3;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000A4: lw          $t6, 0x2C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2C);
    // 0x808000A8: subu        $t7, $s2, $t6
    ctx->r15 = SUB32(ctx->r18, ctx->r14);
    // 0x808000AC: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808000B0: bne         $at, $zero, L_808000D8
    if (ctx->r1 != 0) {
        // 0x808000B4: nop
    
            goto L_808000D8;
    }
    // 0x808000B4: nop

    // 0x808000B8: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x808000C4: jal         0x80800B98
    // 0x808000C8: sw          $t9, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r25;
    func_80800B98_chhoneyb(rdram, ctx);
        goto after_4;
    // 0x808000C8: sw          $t9, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r25;
    after_4:
    // 0x808000CC: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    // 0x808000D0: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x808000D4: sw          $t1, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r9;
L_808000D8:
    // 0x808000D8: jal         0x80088400
    // 0x808000DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcextra_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808000DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_5:
    // 0x808000E0: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x808000E4: beq         $at, $zero, L_80800090
    if (ctx->r1 == 0) {
        // 0x808000E8: nop
    
            goto L_80800090;
    }
    // 0x808000E8: nop

    // 0x808000EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808000F0:
    // 0x808000F0: jal         0x80100094
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000F8: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x808000FC: jal         0x80089FD8
    // 0x80800100: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    _subaddieitem_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800100: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    after_7:
    // 0x80800104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800114: jr          $ra
    // 0x80800118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chmineentrygrille_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1996, 0X194) << 16);
    // 0x80800134: jr          $ra
    // 0x80800138: addiu       $v0, $v0, 0x194
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1996, 0X194));
    return;
    // 0x80800138: addiu       $v0, $v0, 0x194
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1996, 0X194));
;}
RECOMP_FUNC void _bskazmove_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834E0: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x800834E0);
    return;
    // 0x800834E4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chfoodwarn_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2084, 0X2A8) << 16);
    // 0x80800264: jr          $ra
    // 0x80800268: addiu       $v0, $v0, 0x2A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2084, 0X2A8));
    return;
    // 0x80800268: addiu       $v0, $v0, 0x2A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2084, 0X2A8));
    // 0x8080026C: nop

;}
RECOMP_FUNC void _chballoonbomb_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C58: syscall     214
    recomp_syscall_handler(rdram, ctx, 0x80085C58);
    return;
    // 0x80085C5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A4A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4A1C: jal         0x800A4338
    // 0x800A4A20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A4338(rdram, ctx);
        goto after_0;
    // 0x800A4A20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A4A24: bnel        $v0, $zero, L_800A4A40
    if (ctx->r2 != 0) {
        // 0x800A4A28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A4A40;
    }
    goto skip_0;
    // 0x800A4A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A4A2C: jal         0x800A4190
    // 0x800A4A30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4190(rdram, ctx);
        goto after_1;
    // 0x800A4A30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A4A34: jal         0x800A4878
    // 0x800A4A38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4878(rdram, ctx);
        goto after_2;
    // 0x800A4A38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800A4A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A4A40:
    // 0x800A4A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4A44: jr          $ra
    // 0x800A4A48: nop

    return;
    // 0x800A4A48: nop

;}
RECOMP_FUNC void func_80091054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091054: jr          $ra
    // 0x80091058: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80091058: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808012C8_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808012D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012D4: beq         $a0, $at, L_80801304
    if (ctx->r4 == ctx->r1) {
        // 0x808012D8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80801304;
    }
    // 0x808012D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808012DC: beq         $a0, $zero, L_808012F4
    if (ctx->r4 == 0) {
        // 0x808012E0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808012F4;
    }
    // 0x808012E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808012E4: beq         $a0, $at, L_808012FC
    if (ctx->r4 == ctx->r1) {
        // 0x808012E8: nop
    
            goto L_808012FC;
    }
    // 0x808012E8: nop

    // 0x808012EC: b           L_80801308
    // 0x808012F0: nop

        goto L_80801308;
    // 0x808012F0: nop

L_808012F4:
    // 0x808012F4: b           L_80801308
    // 0x808012F8: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
        goto L_80801308;
    // 0x808012F8: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
L_808012FC:
    // 0x808012FC: b           L_80801308
    // 0x80801300: addiu       $a1, $zero, 0x97
    ctx->r5 = ADD32(0, 0X97);
        goto L_80801308;
    // 0x80801300: addiu       $a1, $zero, 0x97
    ctx->r5 = ADD32(0, 0X97);
L_80801304:
    // 0x80801304: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
L_80801308:
    // 0x80801308: beql        $a1, $zero, L_8080131C
    if (ctx->r5 == 0) {
        // 0x8080130C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080131C;
    }
    goto skip_0;
    // 0x8080130C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801310: jal         0x800FC6B0
    // 0x80801314: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800FC6B0(rdram, ctx);
        goto after_0;
    // 0x80801314: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80801318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080131C:
    // 0x8080131C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801320: jr          $ra
    // 0x80801324: nop

    return;
    // 0x80801324: nop

;}
RECOMP_FUNC void func_80800118_chfloaty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080011C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800120: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800124: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800128: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080012C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800130: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800134: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80800138: beq         $at, $zero, L_80800698
    if (ctx->r1 == 0) {
        // 0x8080013C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800698;
    }
    // 0x8080013C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800140: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2416, 0XDC0) << 16);
    // 0x80800144: addu        $at, $at, $t8
    gpr jr_addend_8080014C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800148: lw          $t8, 0xDC0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2416, 0XDC0));
    // 0x8080014C: jr          $t8
    // 0x80800150: nop

    switch (jr_addend_8080014C >> 2) {
        case 0: goto L_80800154; break;
        case 1: goto L_8080017C; break;
        case 2: goto L_808001D4; break;
        case 3: goto L_80800468; break;
        case 4: goto L_80800698; break;
        case 5: goto L_80800564; break;
        default: switch_error(__func__, 0x8080014C, 0x80800DC0);
    }
    // 0x80800150: nop

L_80800154:
    // 0x80800154: jal         0x800878B0
    // 0x80800158: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800158: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x8080015C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800160: beq         $v0, $at, L_80800698
    if (ctx->r2 == ctx->r1) {
        // 0x80800164: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800698;
    }
    // 0x80800164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800168: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8080016C: jal         0x800F7BC8
    // 0x80800170: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F7BC8(rdram, ctx);
        goto after_1;
    // 0x80800170: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80800174: b           L_8080069C
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080069C;
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080017C:
    // 0x8080017C: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    // 0x80800180: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80800184: jal         0x80101E14
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080018C: beq         $v0, $zero, L_808001B4
    if (ctx->r2 == 0) {
        // 0x80800190: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B4;
    }
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: jal         0x80108B04
    // 0x80800198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x80800198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080019C: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x808001A0: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x808001A4: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808001A8: ori         $a0, $a0, 0x5D61
    ctx->r4 = ctx->r4 | 0X5D61;
    // 0x808001AC: jal         0x800C4140
    // 0x808001B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_4;
    // 0x808001B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
L_808001B4:
    // 0x808001B4: jal         0x80101DDC
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001BC: beql        $v0, $zero, L_8080069C
    if (ctx->r2 == 0) {
        // 0x808001C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080069C;
    }
    goto skip_0;
    // 0x808001C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808001C4: jal         0x800FFA88
    // 0x808001C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_6;
    // 0x808001C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x808001CC: b           L_8080069C
    // 0x808001D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080069C;
    // 0x808001D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001D4:
    // 0x808001D4: jal         0x800D90A4
    // 0x808001D8: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x808001D8: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    after_7:
    // 0x808001DC: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x808001E0: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8080022C;
    }
    // 0x808001E0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808001E4: jal         0x800DA298
    // 0x808001E8: addiu       $a0, $zero, 0x340
    ctx->r4 = ADD32(0, 0X340);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808001E8: addiu       $a0, $zero, 0x340
    ctx->r4 = ADD32(0, 0X340);
    after_8:
    // 0x808001EC: bnel        $v0, $zero, L_8080021C
    if (ctx->r2 != 0) {
        // 0x808001F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080021C;
    }
    goto skip_1;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808001F4: jal         0x800DA544
    // 0x808001F8: addiu       $a0, $zero, 0x340
    ctx->r4 = ADD32(0, 0X340);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x808001F8: addiu       $a0, $zero, 0x340
    ctx->r4 = ADD32(0, 0X340);
    after_9:
    // 0x808001FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800200: addiu       $t9, $zero, 0x6F
    ctx->r25 = ADD32(0, 0X6F);
    // 0x80800204: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800208: addiu       $a1, $zero, 0x1431
    ctx->r5 = ADD32(0, 0X1431);
    // 0x8080020C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800210: jal         0x8008A208
    // 0x80800214: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800214: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080021C:
    // 0x8080021C: jal         0x808006AC
    // 0x80800220: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808006AC_chfloaty(rdram, ctx);
        goto after_11;
    // 0x80800220: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800224: b           L_80800450
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800450;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080022C:
    // 0x8080022C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800230: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800234: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800238: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8080023C: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x80800240: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800244: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800248: jal         0x800F10B4
    // 0x8080024C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x8080024C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80800250: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800254: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800258: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080025C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800260: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800264: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800268: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    // 0x8080026C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800270: jal         0x800F10B4
    // 0x80800274: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x80800274: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x80800278: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8080027C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800280: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800284: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800288: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8080028C: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800290: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800294: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800298: jal         0x800F10B4
    // 0x8080029C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x8080029C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x808002A0: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x808002A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808002A8: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808002AC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x808002B0: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808002B4: jal         0x80013970
    // 0x808002B8: nop

    func_80013970(rdram, ctx);
        goto after_15;
    // 0x808002B8: nop

    after_15:
    // 0x808002BC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808002C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808002C4: nop

    // 0x808002C8: mul.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808002CC: jal         0x800F2100
    // 0x808002D0: nop

    mlAbsF(rdram, ctx);
        goto after_16;
    // 0x808002D0: nop

    after_16:
    // 0x808002D4: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808002D8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808002DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002E0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808002E4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808002E8: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808002EC: jal         0x80013970
    // 0x808002F0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    func_80013970(rdram, ctx);
        goto after_17;
    // 0x808002F0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x808002F4: jal         0x800F2100
    // 0x808002F8: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_18;
    // 0x808002F8: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    after_18:
    // 0x808002FC: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800300: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800304: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800308: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080030C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800310: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800314: jal         0x80013970
    // 0x80800318: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    func_80013970(rdram, ctx);
        goto after_19;
    // 0x80800318: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_19:
    // 0x8080031C: jal         0x800F2100
    // 0x80800320: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_20;
    // 0x80800320: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    after_20:
    // 0x80800324: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800328: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8080032C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800330: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80800334: jal         0x8010262C
    // 0x80800338: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010262C(rdram, ctx);
        goto after_21;
    // 0x80800338: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_21:
    // 0x8080033C: beq         $v0, $zero, L_80800444
    if (ctx->r2 == 0) {
        // 0x80800340: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800444;
    }
    // 0x80800340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800344: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800348: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8080034C: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800350: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800354: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800358: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8080035C: jal         0x800E0B8C
    // 0x80800360: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_22;
    // 0x80800360: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x80800364: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800368: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080036C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80800370: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800374: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800378: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8080037C: jal         0x800E0B8C
    // 0x80800380: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_23;
    // 0x80800380: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x80800384: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800388: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080038C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x80800390: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800394: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800398: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8080039C: jal         0x800E0B8C
    // 0x808003A0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_24;
    // 0x808003A0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_24:
    // 0x808003A4: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808003A8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808003AC: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x808003B0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808003B4: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x808003B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808003BC: jal         0x800E0B8C
    // 0x808003C0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_25;
    // 0x808003C0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x808003C4: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808003C8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808003CC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x808003D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808003D4: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x808003D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808003DC: jal         0x800E0B8C
    // 0x808003E0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_26;
    // 0x808003E0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_26:
    // 0x808003E4: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808003E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808003EC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x808003F0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808003F4: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x808003F8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808003FC: jal         0x800E0B8C
    // 0x80800400: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_27;
    // 0x80800400: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_27:
    // 0x80800404: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800408: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080040C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x80800410: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800414: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800418: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8080041C: jal         0x800E0B8C
    // 0x80800420: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_28;
    // 0x80800420: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_28:
    // 0x80800424: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800428: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080042C: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x80800430: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800434: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800438: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8080043C: jal         0x800E0B8C
    // 0x80800440: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_29;
    // 0x80800440: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_29:
L_80800444:
    // 0x80800444: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800448: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800450:
    // 0x80800450: jal         0x80800BD8
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800BD8_chfloaty(rdram, ctx);
        goto after_30;
    // 0x80800454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80800458: jal         0x8010C964
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C964(rdram, ctx);
        goto after_31;
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800460: b           L_8080069C
    // 0x80800464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080069C;
    // 0x80800464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800468:
    // 0x80800468: jal         0x800F54E4
    // 0x8080046C: nop

    func_800F54E4(rdram, ctx);
        goto after_32;
    // 0x8080046C: nop

    after_32:
    // 0x80800470: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800474: jal         0x800F64A4
    // 0x80800478: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800F64A4(rdram, ctx);
        goto after_33;
    // 0x80800478: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_33:
    // 0x8080047C: beq         $v0, $zero, L_808004D8
    if (ctx->r2 == 0) {
        // 0x80800480: nop
    
            goto L_808004D8;
    }
    // 0x80800480: nop

    // 0x80800484: jal         0x800DA298
    // 0x80800488: addiu       $a0, $zero, 0x6DD
    ctx->r4 = ADD32(0, 0X6DD);
    func_800DA298(rdram, ctx);
        goto after_34;
    // 0x80800488: addiu       $a0, $zero, 0x6DD
    ctx->r4 = ADD32(0, 0X6DD);
    after_34:
    // 0x8080048C: bne         $v0, $zero, L_80800524
    if (ctx->r2 != 0) {
        // 0x80800490: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800524;
    }
    // 0x80800490: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800494: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x80800498: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080049C: jal         0x8008A1D0
    // 0x808004A0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_35;
    // 0x808004A0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_35:
    // 0x808004A4: beq         $v0, $zero, L_80800524
    if (ctx->r2 == 0) {
        // 0x808004A8: nop
    
            goto L_80800524;
    }
    // 0x808004A8: nop

    // 0x808004AC: jal         0x800DA544
    // 0x808004B0: addiu       $a0, $zero, 0x6DD
    ctx->r4 = ADD32(0, 0X6DD);
    func_800DA544(rdram, ctx);
        goto after_36;
    // 0x808004B0: addiu       $a0, $zero, 0x6DD
    ctx->r4 = ADD32(0, 0X6DD);
    after_36:
    // 0x808004B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004B8: addiu       $t0, $zero, 0x6F
    ctx->r8 = ADD32(0, 0X6F);
    // 0x808004BC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808004C0: addiu       $a1, $zero, 0x1432
    ctx->r5 = ADD32(0, 0X1432);
    // 0x808004C4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808004C8: jal         0x8008A208
    // 0x808004CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_37;
    // 0x808004CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_37:
    // 0x808004D0: b           L_80800524
    // 0x808004D4: nop

        goto L_80800524;
    // 0x808004D4: nop

L_808004D8:
    // 0x808004D8: jal         0x800DA298
    // 0x808004DC: addiu       $a0, $zero, 0x6DE
    ctx->r4 = ADD32(0, 0X6DE);
    func_800DA298(rdram, ctx);
        goto after_38;
    // 0x808004DC: addiu       $a0, $zero, 0x6DE
    ctx->r4 = ADD32(0, 0X6DE);
    after_38:
    // 0x808004E0: bne         $v0, $zero, L_80800524
    if (ctx->r2 != 0) {
        // 0x808004E4: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800524;
    }
    // 0x808004E4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808004E8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x808004EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004F0: jal         0x8008A1D0
    // 0x808004F4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_39;
    // 0x808004F4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_39:
    // 0x808004F8: beq         $v0, $zero, L_80800524
    if (ctx->r2 == 0) {
        // 0x808004FC: nop
    
            goto L_80800524;
    }
    // 0x808004FC: nop

    // 0x80800500: jal         0x800DA544
    // 0x80800504: addiu       $a0, $zero, 0x6DE
    ctx->r4 = ADD32(0, 0X6DE);
    func_800DA544(rdram, ctx);
        goto after_40;
    // 0x80800504: addiu       $a0, $zero, 0x6DE
    ctx->r4 = ADD32(0, 0X6DE);
    after_40:
    // 0x80800508: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080050C: addiu       $t1, $zero, 0x6F
    ctx->r9 = ADD32(0, 0X6F);
    // 0x80800510: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800514: addiu       $a1, $zero, 0x1433
    ctx->r5 = ADD32(0, 0X1433);
    // 0x80800518: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080051C: jal         0x8008A208
    // 0x80800520: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_41;
    // 0x80800520: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_41:
L_80800524:
    // 0x80800524: jal         0x8010CD28
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_42;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8080052C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800530: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800534: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080053C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800540: jal         0x80102BAC
    // 0x80800544: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    func_80102BAC(rdram, ctx);
        goto after_43;
    // 0x80800544: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    after_43:
    // 0x80800548: jal         0x8010C964
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C964(rdram, ctx);
        goto after_44;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: jal         0x80800BD8
    // 0x80800558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800BD8_chfloaty(rdram, ctx);
        goto after_45;
    // 0x80800558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_45:
    // 0x8080055C: b           L_8080069C
    // 0x80800560: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080069C;
    // 0x80800560: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800564:
    // 0x80800564: jal         0x800D90A4
    // 0x80800568: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800D90A4(rdram, ctx);
        goto after_46;
    // 0x80800568: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_46:
    // 0x8080056C: beq         $v0, $zero, L_808005A8
    if (ctx->r2 == 0) {
        // 0x80800570: lui         $at, 0x40E0
        ctx->r1 = S32(0X40E0 << 16);
            goto L_808005A8;
    }
    // 0x80800570: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: jal         0x8008A4B0
    // 0x8080057C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_47;
    // 0x8080057C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_47:
    // 0x80800580: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800588: srl         $t2, $a1, 7
    ctx->r10 = S32(U32(ctx->r5) >> 7);
    // 0x8080058C: jal         0x8008A520
    // 0x80800590: addiu       $a1, $t2, -0x25
    ctx->r5 = ADD32(ctx->r10, -0X25);
    _subaddietaxi_entrypoint_5(rdram, ctx);
        goto after_48;
    // 0x80800590: addiu       $a1, $t2, -0x25
    ctx->r5 = ADD32(ctx->r10, -0X25);
    after_48:
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: jal         0x808006AC
    // 0x8080059C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808006AC_chfloaty(rdram, ctx);
        goto after_49;
    // 0x8080059C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_49:
    // 0x808005A0: b           L_80800644
    // 0x808005A4: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
        goto L_80800644;
    // 0x808005A4: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
L_808005A8:
    // 0x808005A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808005AC: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808005B0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808005B4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808005B8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x808005BC: nop

    // 0x808005C0: bc1fl       L_80800648
    if (!c1cs) {
        // 0x808005C4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800648;
    }
    goto skip_2;
    // 0x808005C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_2:
    // 0x808005C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808005D8: jal         0x800F12D4
    // 0x808005DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F12D4(rdram, ctx);
        goto after_50;
    // 0x808005DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_50:
    // 0x808005E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005EC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x808005F0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808005F4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808005F8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808005FC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800600: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x80800604: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800608: jal         0x800EFE50
    // 0x8080060C: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    func_800EFE50(rdram, ctx);
        goto after_51;
    // 0x8080060C: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    after_51:
    // 0x80800610: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800614: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800618: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080061C: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800620: jal         0x80013970
    // 0x80800624: nop

    func_80013970(rdram, ctx);
        goto after_52;
    // 0x80800624: nop

    after_52:
    // 0x80800628: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080062C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800630: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800634: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800638: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080063C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800640: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_80800644:
    // 0x80800644: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800648:
    // 0x80800648: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080064C: nop

    // 0x80800650: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80800654: nop

    // 0x80800658: bc1f        L_80800684
    if (!c1cs) {
        // 0x8080065C: nop
    
            goto L_80800684;
    }
    // 0x8080065C: nop

    // 0x80800660: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800664: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800668: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080066C: jal         0x800F12D4
    // 0x80800670: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F12D4(rdram, ctx);
        goto after_53;
    // 0x80800670: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_53:
    // 0x80800674: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800678: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8080067C: nop

    // 0x80800680: sb          $t4, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r12;
L_80800684:
    // 0x80800684: jal         0x8010C964
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C964(rdram, ctx);
        goto after_54;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: jal         0x80800BD8
    // 0x80800694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800BD8_chfloaty(rdram, ctx);
        goto after_55;
    // 0x80800694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_55:
L_80800698:
    // 0x80800698: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080069C:
    // 0x8080069C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006A0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808006A4: jr          $ra
    // 0x808006A8: nop

    return;
    // 0x808006A8: nop

;}
RECOMP_FUNC void _chlakemonster_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CE0: syscall     444
    recomp_syscall_handler(rdram, ctx, 0x80086CE0);
    return;
    // 0x80086CE4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bsfirstp_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084390: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084390);
    return;
    // 0x80084394: addi        $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
;}
RECOMP_FUNC void _chswampplatform_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087470: syscall     575
    recomp_syscall_handler(rdram, ctx, 0x80087470);
    return;
    // 0x80087474: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _ncbaspline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089380: syscall     776
    recomp_syscall_handler(rdram, ctx, 0x80089380);
    return;
    // 0x80089384: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80113978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113978: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8011397C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80113980: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80113984: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80113988: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x8011398C: jal         0x80110840
    // 0x80113990: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x80113990: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80113994: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80113998: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x8011399C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801139A0: jal         0x80110898
    // 0x801139A4: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    func_80110898(rdram, ctx);
        goto after_1;
    // 0x801139A4: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801139A8: jal         0x8010FF80
    // 0x801139AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FF80(rdram, ctx);
        goto after_2;
    // 0x801139AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x801139B0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x801139B4: jal         0x800F711C
    // 0x801139B8: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    func_800F711C(rdram, ctx);
        goto after_3;
    // 0x801139B8: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_3:
    // 0x801139BC: beql        $v0, $zero, L_801139DC
    if (ctx->r2 == 0) {
        // 0x801139C0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_801139DC;
    }
    goto skip_0;
    // 0x801139C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x801139C4: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x801139C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801139CC: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x801139D0: beq         $t7, $zero, L_801139E4
    if (ctx->r15 == 0) {
        // 0x801139D4: nop
    
            goto L_801139E4;
    }
    // 0x801139D4: nop

    // 0x801139D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_801139DC:
    // 0x801139DC: b           L_80113D20
    // 0x801139E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80113D20;
    // 0x801139E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801139E4:
    // 0x801139E4: jal         0x80112550
    // 0x801139E8: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    func_80112550(rdram, ctx);
        goto after_4;
    // 0x801139E8: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_4:
    // 0x801139EC: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x801139F0: jal         0x800CA7E4
    // 0x801139F4: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    func_800CA7E4(rdram, ctx);
        goto after_5;
    // 0x801139F4: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_5:
    // 0x801139F8: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x801139FC: beql        $t8, $zero, L_80113C20
    if (ctx->r24 == 0) {
        // 0x80113A00: lw          $t3, 0xA8($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XA8);
            goto L_80113C20;
    }
    goto skip_1;
    // 0x80113A00: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    skip_1:
    // 0x80113A04: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80113A08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80113A0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80113A10: lw          $t9, 0x40($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X40);
    // 0x80113A14: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80113A18: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80113A1C: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80113A20: bnel        $at, $zero, L_80113A34
    if (ctx->r1 != 0) {
        // 0x80113A24: lw          $t2, 0x48($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X48);
            goto L_80113A34;
    }
    goto skip_2;
    // 0x80113A24: lw          $t2, 0x48($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X48);
    skip_2:
    // 0x80113A28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80113A2C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80113A30: lw          $t2, 0x48($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X48);
L_80113A34:
    // 0x80113A34: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80113A38: bne         $at, $zero, L_80113A48
    if (ctx->r1 != 0) {
        // 0x80113A3C: nop
    
            goto L_80113A48;
    }
    // 0x80113A3C: nop

    // 0x80113A40: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80113A44: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80113A48:
    // 0x80113A48: beq         $v1, $zero, L_80113AEC
    if (ctx->r3 == 0) {
        // 0x80113A4C: swc1        $f6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
            goto L_80113AEC;
    }
    // 0x80113A4C: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x80113A50: bne         $t0, $zero, L_80113A7C
    if (ctx->r8 != 0) {
        // 0x80113A54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80113A7C;
    }
    // 0x80113A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80113A58: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80113A5C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80113A60: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x80113A64: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x80113A68: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80113A6C: beq         $at, $zero, L_80113A7C
    if (ctx->r1 == 0) {
        // 0x80113A70: nop
    
            goto L_80113A7C;
    }
    // 0x80113A70: nop

    // 0x80113A74: b           L_80113A7C
    // 0x80113A78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80113A7C;
    // 0x80113A78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80113A7C:
    // 0x80113A7C: bgez        $t0, L_80113ABC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80113A80: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_80113ABC;
    }
    // 0x80113A80: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80113A84: addiu       $t5, $sp, 0x6C
    ctx->r13 = ADD32(ctx->r29, 0X6C);
    // 0x80113A88: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80113A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80113A90: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80113A94: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x80113A98: addiu       $a3, $v0, 0x58
    ctx->r7 = ADD32(ctx->r2, 0X58);
    // 0x80113A9C: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    // 0x80113AA0: jal         0x801137E4
    // 0x80113AA4: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    func_801137E4(rdram, ctx);
        goto after_6;
    // 0x80113AA4: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_6:
    // 0x80113AA8: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80113AAC: beq         $v0, $zero, L_80113AEC
    if (ctx->r2 == 0) {
        // 0x80113AB0: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_80113AEC;
    }
    // 0x80113AB0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80113AB4: b           L_80113AEC
    // 0x80113AB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80113AEC;
    // 0x80113AB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80113ABC:
    // 0x80113ABC: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x80113AC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80113AC4: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80113AC8: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x80113ACC: addiu       $a3, $v0, 0x70
    ctx->r7 = ADD32(ctx->r2, 0X70);
    // 0x80113AD0: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    // 0x80113AD4: jal         0x801137E4
    // 0x80113AD8: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    func_801137E4(rdram, ctx);
        goto after_7;
    // 0x80113AD8: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_7:
    // 0x80113ADC: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80113AE0: beq         $v0, $zero, L_80113AEC
    if (ctx->r2 == 0) {
        // 0x80113AE4: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_80113AEC;
    }
    // 0x80113AE4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80113AE8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80113AEC:
    // 0x80113AEC: beq         $t1, $zero, L_80113BDC
    if (ctx->r9 == 0) {
        // 0x80113AF0: addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
            goto L_80113BDC;
    }
    // 0x80113AF0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80113AF4: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80113AF8: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x80113AFC: jal         0x800EFB24
    // 0x80113B00: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80113B00: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    after_8:
    // 0x80113B04: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80113B08: jal         0x800F1A88
    // 0x80113B0C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800F1A88(rdram, ctx);
        goto after_9;
    // 0x80113B0C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_9:
    // 0x80113B10: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80113B14: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80113B18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80113B1C: bgezl       $t0, L_80113B38
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80113B20: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80113B38;
    }
    goto skip_3;
    // 0x80113B20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_3:
    // 0x80113B24: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80113B28: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80113B2C: b           L_80113B3C
    // 0x80113B30: nop

        goto L_80113B3C;
    // 0x80113B30: nop

    // 0x80113B34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80113B38:
    // 0x80113B38: nop

L_80113B3C:
    // 0x80113B3C: mul.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80113B40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80113B44: lwc1        $f10, 0x65D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65D0);
    // 0x80113B48: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80113B4C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80113B50: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    // 0x80113B54: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80113B58: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80113B5C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80113B60: jal         0x800EF934
    // 0x80113B64: nop

    func_800EF934(rdram, ctx);
        goto after_10;
    // 0x80113B64: nop

    after_10:
    // 0x80113B68: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80113B6C: jal         0x800EF04C
    // 0x80113B70: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80113B70: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_11:
    // 0x80113B74: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80113B78: jal         0x8011349C
    // 0x80113B7C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_8011349C(rdram, ctx);
        goto after_12;
    // 0x80113B7C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_12:
    // 0x80113B80: beq         $v0, $zero, L_80113C1C
    if (ctx->r2 == 0) {
        // 0x80113B84: lw          $t0, 0x78($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X78);
            goto L_80113C1C;
    }
    // 0x80113B84: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80113B88: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80113B8C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80113B90: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    // 0x80113B94: jal         0x800136E4
    // 0x80113B98: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_13;
    // 0x80113B98: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_13:
    // 0x80113B9C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80113BA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80113BA4: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80113BA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80113BAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80113BB0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80113BB4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80113BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80113BBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80113BC0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80113BC4: jal         0x80112D90
    // 0x80113BC8: nop

    func_80112D90(rdram, ctx);
        goto after_14;
    // 0x80113BC8: nop

    after_14:
    // 0x80113BCC: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80113BD0: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x80113BD4: b           L_80113C1C
    // 0x80113BD8: sw          $t0, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = ctx->r8;
        goto L_80113C1C;
    // 0x80113BD8: sw          $t0, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = ctx->r8;
L_80113BDC:
    // 0x80113BDC: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x80113BE0: lw          $v0, 0x7C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X7C);
    // 0x80113BE4: beql        $v0, $zero, L_80113C20
    if (ctx->r2 == 0) {
        // 0x80113BE8: lw          $t3, 0xA8($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XA8);
            goto L_80113C20;
    }
    goto skip_4;
    // 0x80113BE8: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    skip_4:
    // 0x80113BEC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80113BF0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80113BF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80113BF8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80113BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80113C00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80113C04: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80113C08: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80113C0C: jal         0x80112E50
    // 0x80113C10: nop

    func_80112E50(rdram, ctx);
        goto after_15;
    // 0x80113C10: nop

    after_15:
    // 0x80113C14: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x80113C18: sw          $zero, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = 0;
L_80113C1C:
    // 0x80113C1C: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
L_80113C20:
    // 0x80113C20: beql        $t3, $zero, L_80113D1C
    if (ctx->r11 == 0) {
        // 0x80113C24: lwc1        $f0, 0x80($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
            goto L_80113D1C;
    }
    goto skip_5;
    // 0x80113C24: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    skip_5:
    // 0x80113C28: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80113C2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80113C30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80113C34: lw          $t4, 0x44($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X44);
    // 0x80113C38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80113C3C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80113C40: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80113C44: bnel        $at, $zero, L_80113C58
    if (ctx->r1 != 0) {
        // 0x80113C48: lw          $t5, 0x3C($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X3C);
            goto L_80113C58;
    }
    goto skip_6;
    // 0x80113C48: lw          $t5, 0x3C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X3C);
    skip_6:
    // 0x80113C4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80113C50: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80113C54: lw          $t5, 0x3C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X3C);
L_80113C58:
    // 0x80113C58: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80113C5C: bne         $at, $zero, L_80113C6C
    if (ctx->r1 != 0) {
        // 0x80113C60: nop
    
            goto L_80113C6C;
    }
    // 0x80113C60: nop

    // 0x80113C64: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80113C68: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80113C6C:
    // 0x80113C6C: beq         $a0, $zero, L_80113D00
    if (ctx->r4 == 0) {
        // 0x80113C70: swc1        $f8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
            goto L_80113D00;
    }
    // 0x80113C70: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80113C74: bne         $v1, $zero, L_80113CA0
    if (ctx->r3 != 0) {
        // 0x80113C78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80113CA0;
    }
    // 0x80113C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80113C7C: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80113C80: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80113C84: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80113C88: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x80113C8C: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80113C90: beq         $at, $zero, L_80113CA0
    if (ctx->r1 == 0) {
        // 0x80113C94: nop
    
            goto L_80113CA0;
    }
    // 0x80113C94: nop

    // 0x80113C98: b           L_80113CA0
    // 0x80113C9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80113CA0;
    // 0x80113C9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80113CA0:
    // 0x80113CA0: bgez        $v1, L_80113CD8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80113CA4: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_80113CD8;
    }
    // 0x80113CA4: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80113CA8: addiu       $t8, $sp, 0x38
    ctx->r24 = ADD32(ctx->r29, 0X38);
    // 0x80113CAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80113CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80113CB4: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80113CB8: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x80113CBC: addiu       $a3, $v0, 0x64
    ctx->r7 = ADD32(ctx->r2, 0X64);
    // 0x80113CC0: jal         0x801137E4
    // 0x80113CC4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_801137E4(rdram, ctx);
        goto after_16;
    // 0x80113CC4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_16:
    // 0x80113CC8: beq         $v0, $zero, L_80113D00
    if (ctx->r2 == 0) {
        // 0x80113CCC: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_80113D00;
    }
    // 0x80113CCC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80113CD0: b           L_80113D00
    // 0x80113CD4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80113D00;
    // 0x80113CD4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80113CD8:
    // 0x80113CD8: addiu       $t9, $sp, 0x38
    ctx->r25 = ADD32(ctx->r29, 0X38);
    // 0x80113CDC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80113CE0: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80113CE4: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x80113CE8: addiu       $a3, $v0, 0x4C
    ctx->r7 = ADD32(ctx->r2, 0X4C);
    // 0x80113CEC: jal         0x801137E4
    // 0x80113CF0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_801137E4(rdram, ctx);
        goto after_17;
    // 0x80113CF0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_17:
    // 0x80113CF4: beq         $v0, $zero, L_80113D00
    if (ctx->r2 == 0) {
        // 0x80113CF8: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_80113D00;
    }
    // 0x80113CF8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80113CFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80113D00:
    // 0x80113D00: beq         $t0, $zero, L_80113D18
    if (ctx->r8 == 0) {
        // 0x80113D04: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80113D18;
    }
    // 0x80113D04: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80113D08: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80113D0C: jal         0x800F0DC0
    // 0x80113D10: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    func_800F0DC0(rdram, ctx);
        goto after_18;
    // 0x80113D10: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_18:
    // 0x80113D14: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
L_80113D18:
    // 0x80113D18: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
L_80113D1C:
    // 0x80113D1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80113D20:
    // 0x80113D20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80113D24: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80113D28: jr          $ra
    // 0x80113D2C: nop

    return;
    // 0x80113D2C: nop

;}
RECOMP_FUNC void _gcdialogexec_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E68: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E68);
    return;
    // 0x80087E6C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void bawasher_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800100: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800104: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800108: jal         0x80092CDC
    // 0x8080010C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80092CDC(rdram, ctx);
        goto after_0;
    // 0x8080010C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80800110: beq         $v0, $zero, L_80800150
    if (ctx->r2 == 0) {
        // 0x80800114: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800150;
    }
    // 0x80800114: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800118: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8080011C: jal         0x80092CDC
    // 0x80800120: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80092CDC(rdram, ctx);
        goto after_1;
    // 0x80800120: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x80800124: beq         $v0, $zero, L_80800150
    if (ctx->r2 == 0) {
        // 0x80800128: addiu       $s0, $sp, 0x24
        ctx->r16 = ADD32(ctx->r29, 0X24);
            goto L_80800150;
    }
    // 0x80800128: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800134: jal         0x800EFB24
    // 0x80800138: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80800138: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x800EF368
    // 0x80800144: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    func_800EF368(rdram, ctx);
        goto after_3;
    // 0x80800144: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    after_3:
    // 0x80800148: b           L_80800198
    // 0x8080014C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80800198;
    // 0x8080014C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800150:
    // 0x80800150: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x80800154: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800158: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080015C: jal         0x80084B28
    // 0x80800160: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _baeggfire_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800160: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x800EF368
    // 0x8080016C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_800EF368(rdram, ctx);
        goto after_5;
    // 0x8080016C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_5:
    // 0x80800170: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800174: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800178: jal         0x800EE780
    // 0x8080017C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_6;
    // 0x8080017C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x800EF368
    // 0x80800188: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    func_800EF368(rdram, ctx);
        goto after_7;
    // 0x80800188: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    after_7:
    // 0x8080018C: jal         0x80084AF0
    // 0x80800190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _baeggcursor_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x80800190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80800194: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800198:
    // 0x80800198: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8080019C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x808001A0: jal         0x808001BC
    // 0x808001A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    bawasher_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x808001A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_9:
    // 0x808001A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808001B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808001B4: jr          $ra
    // 0x808001B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808001B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800EA364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA364: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA368: jr          $ra
    // 0x800EA36C: lhu         $v0, 0x2DCE($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2DCE);
    return;
    // 0x800EA36C: lhu         $v0, 0x2DCE($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2DCE);
;}
RECOMP_FUNC void sudeathmatch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80800004: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8080000C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800010: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800014: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800018: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8080001C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80800020: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80800024: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80800028: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8080002C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800030: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800034: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800038: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x8080003C: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x80800040: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800044: jal         0x800F5898
    // 0x80800048: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_0;
    // 0x80800048: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_0:
    // 0x8080004C: blez        $v0, L_808000A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800050: addiu       $s2, $zero, 0xC
        ctx->r18 = ADD32(0, 0XC);
            goto L_808000A0;
    }
    // 0x80800050: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x80800054: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
L_80800058:
    // 0x80800058: beq         $s1, $s4, L_8080008C
    if (ctx->r17 == ctx->r20) {
        // 0x8080005C: nop
    
            goto L_8080008C;
    }
    // 0x8080005C: nop

    // 0x80800060: jal         0x800F6438
    // 0x80800064: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x80800064: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800068: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x8080006C: nop
    
            goto L_8080008C;
    }
    // 0x8080006C: nop

    // 0x80800070: multu       $s3, $s2
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800074: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80800078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080007C: mflo        $t6
    ctx->r14 = lo;
    // 0x80800080: addu        $a1, $s0, $t6
    ctx->r5 = ADD32(ctx->r16, ctx->r14);
    // 0x80800084: jal         0x800F5A00
    // 0x80800088: nop

    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800088: nop

    after_2:
L_8080008C:
    // 0x8080008C: jal         0x800F5898
    // 0x80800090: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_800F5898(rdram, ctx);
        goto after_3;
    // 0x80800090: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_3:
    // 0x80800094: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800098: bne         $at, $zero, L_80800058
    if (ctx->r1 != 0) {
        // 0x8080009C: nop
    
            goto L_80800058;
    }
    // 0x8080009C: nop

L_808000A0:
    // 0x808000A0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3318, 0X300) << 16);
    // 0x808000A4: addiu       $a1, $a1, 0x300
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3318, 0X300));
    // 0x808000A8: addiu       $a0, $zero, 0x2B7
    ctx->r4 = ADD32(0, 0X2B7);
    // 0x808000AC: jal         0x800882C0
    // 0x808000B0: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x808000B0: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_4:
    // 0x808000B4: bne         $v0, $zero, L_808000C4
    if (ctx->r2 != 0) {
        // 0x808000B8: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_808000C4;
    }
    // 0x808000B8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808000BC: b           L_808002B8
    // 0x808000C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002B8;
    // 0x808000C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000C4:
    // 0x808000C4: blez        $v0, L_8080012C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808000C8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8080012C;
    }
    // 0x808000C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808000CC: andi        $a1, $v0, 0x3
    ctx->r5 = ctx->r2 & 0X3;
    // 0x808000D0: beq         $a1, $zero, L_808000F8
    if (ctx->r5 == 0) {
        // 0x808000D4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_808000F8;
    }
    // 0x808000D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808000D8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3318, 0X3A0) << 16);
    // 0x808000DC: addiu       $t7, $t7, 0x3A0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3318, 0X3A0));
    // 0x808000E0: addu        $v1, $zero, $t7
    ctx->r3 = ADD32(0, ctx->r15);
L_808000E4:
    // 0x808000E4: sb          $s1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r17;
    // 0x808000E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808000EC: bne         $a0, $s1, L_808000E4
    if (ctx->r4 != ctx->r17) {
        // 0x808000F0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808000E4;
    }
    // 0x808000F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808000F4: beq         $s1, $v0, L_8080012C
    if (ctx->r17 == ctx->r2) {
        // 0x808000F8: lui         $t8, 0x8080
        ctx->r24 = S32(RELOC_HI16(3318, 0X3A0) << 16);
            goto L_8080012C;
    }
L_808000F8:
    // 0x808000F8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(3318, 0X3A0) << 16);
    // 0x808000FC: addiu       $t8, $t8, 0x3A0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(3318, 0X3A0));
    // 0x80800100: addu        $v1, $s1, $t8
    ctx->r3 = ADD32(ctx->r17, ctx->r24);
L_80800104:
    // 0x80800104: addiu       $t9, $s1, 0x1
    ctx->r25 = ADD32(ctx->r17, 0X1);
    // 0x80800108: addiu       $t0, $s1, 0x2
    ctx->r8 = ADD32(ctx->r17, 0X2);
    // 0x8080010C: addiu       $t1, $s1, 0x3
    ctx->r9 = ADD32(ctx->r17, 0X3);
    // 0x80800110: sb          $s1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r17;
    // 0x80800114: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800118: sb          $t1, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r9;
    // 0x8080011C: sb          $t0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r8;
    // 0x80800120: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    // 0x80800124: bne         $s1, $s4, L_80800104
    if (ctx->r17 != ctx->r20) {
        // 0x80800128: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800104;
    }
    // 0x80800128: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8080012C:
    // 0x8080012C: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(3318, 0X3A0) << 16);
    // 0x80800130: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(3318, 0X3C8) << 16);
    // 0x80800134: lw          $t4, 0x3C8($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(3318, 0X3C8));
    // 0x80800138: addiu       $s6, $s6, 0x3A0
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(3318, 0X3A0));
    // 0x8080013C: addiu       $s4, $v0, -0x1
    ctx->r20 = ADD32(ctx->r2, -0X1);
    // 0x80800140: addu        $t2, $s6, $s4
    ctx->r10 = ADD32(ctx->r22, ctx->r20);
    // 0x80800144: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80800148: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x8080014C: blez        $s4, L_808002B4
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80800150: sb          $t3, 0x0($t5)
        MEM_B(0X0, ctx->r13) = ctx->r11;
            goto L_808002B4;
    }
    // 0x80800150: sb          $t3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r11;
    // 0x80800154: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3318, 0X2F0) << 16);
    // 0x80800158: lwc1        $f20, 0x2F0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3318, 0X2F0));
    // 0x8080015C: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
    // 0x80800160: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
L_80800164:
    // 0x80800164: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800168: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080016C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800170: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800174: jal         0x800DC0C0
    // 0x80800178: sub.s       $f22, $f6, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f8.fl;
    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800178: sub.s       $f22, $f6, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f8.fl;
    after_5:
    // 0x8080017C: mul.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80800180: lui         $s7, 0x8080
    ctx->r23 = S32(RELOC_HI16(3318, 0X300) << 16);
    // 0x80800184: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800188: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8080018C: mfc1        $s5, $f16
    ctx->r21 = (int32_t)ctx->f16.u32l;
    // 0x80800190: nop

    // 0x80800194: addu        $t7, $s6, $s5
    ctx->r15 = ADD32(ctx->r22, ctx->r21);
    // 0x80800198: lbu         $fp, 0x0($t7)
    ctx->r30 = MEM_BU(ctx->r15, 0X0);
    // 0x8080019C: sll         $t8, $fp, 2
    ctx->r24 = S32(ctx->r30 << 2);
    // 0x808001A0: addu        $s7, $s7, $t8
    ctx->r23 = ADD32(ctx->r23, ctx->r24);
    // 0x808001A4: lw          $s7, 0x300($s7)
    ctx->r23 = MEM_W(ctx->r23, (int16_t)RELOC_LO16(3318, 0X300));
    // 0x808001A8: jal         0x80088C00
    // 0x808001AC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808001AC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_6:
    // 0x808001B0: blez        $s3, L_8080020C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x808001B4: addiu       $s0, $sp, 0x98
        ctx->r16 = ADD32(ctx->r29, 0X98);
            goto L_8080020C;
    }
    // 0x808001B4: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
L_808001B8:
    // 0x808001B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808001BC: jal         0x800EFC7C
    // 0x808001C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_7;
    // 0x808001C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x808001C4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808001C8: nop

    // 0x808001CC: bc1f        L_808001FC
    if (!c1cs) {
        // 0x808001D0: slti        $at, $s4, 0x2
        ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
            goto L_808001FC;
    }
    // 0x808001D0: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    // 0x808001D4: bne         $at, $zero, L_808001F4
    if (ctx->r1 != 0) {
        // 0x808001D8: addiu       $v0, $s4, -0x1
        ctx->r2 = ADD32(ctx->r20, -0X1);
            goto L_808001F4;
    }
    // 0x808001D8: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x808001DC: addu        $t9, $s6, $v0
    ctx->r25 = ADD32(ctx->r22, ctx->r2);
    // 0x808001E0: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x808001E4: addu        $t1, $s6, $s5
    ctx->r9 = ADD32(ctx->r22, ctx->r21);
    // 0x808001E8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808001EC: b           L_8080020C
    // 0x808001F0: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
        goto L_8080020C;
    // 0x808001F0: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
L_808001F4:
    // 0x808001F4: b           L_8080020C
    // 0x808001F8: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
        goto L_8080020C;
    // 0x808001F8: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_808001FC:
    // 0x808001FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800200: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80800204: bne         $at, $zero, L_808001B8
    if (ctx->r1 != 0) {
        // 0x80800208: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808001B8;
    }
    // 0x80800208: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_8080020C:
    // 0x8080020C: bne         $s1, $s3, L_808002AC
    if (ctx->r17 != ctx->r19) {
        // 0x80800210: nop
    
            goto L_808002AC;
    }
    // 0x80800210: nop

    // 0x80800214: jal         0x80088BE8
    // 0x80800218: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x80800218: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_8:
    // 0x8080021C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800220: jal         0x80088C08
    // 0x80800224: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_9;
    // 0x80800224: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x80800228: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080022C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800230: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800234: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800238: jal         0x800DC178
    // 0x8080023C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x8080023C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_10:
    // 0x80800240: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x80800244: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800248: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080024C: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800250: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800254: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800258: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080025C: swc1        $f22, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f22.u32l;
    // 0x80800260: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800264: jal         0x800DC178
    // 0x80800268: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80800268: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x8080026C: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800270: lw          $a0, 0x104($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X104);
    // 0x80800274: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800278: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8080027C: jal         0x800EE780
    // 0x80800280: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    func_800EE780(rdram, ctx);
        goto after_12;
    // 0x80800280: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x80800284: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80800288: lw          $v1, 0x108($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X108);
    // 0x8080028C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3318, 0X3C8) << 16);
    // 0x80800290: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800294: swc1        $f22, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f22.u32l;
    // 0x80800298: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
    // 0x8080029C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002A0: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x808002A4: b           L_808002B8
    // 0x808002A8: sw          $fp, 0x3C8($at)
    MEM_W((int16_t)RELOC_LO16(3318, 0X3C8), ctx->r1) = ctx->r30;
        goto L_808002B8;
    // 0x808002A8: sw          $fp, 0x3C8($at)
    MEM_W((int16_t)RELOC_LO16(3318, 0X3C8), ctx->r1) = ctx->r30;
L_808002AC:
    // 0x808002AC: bgtzl       $s4, L_80800164
    if (SIGNED(ctx->r20) > 0) {
        // 0x808002B0: mtc1        $s4, $f4
        ctx->f4.u32l = ctx->r20;
            goto L_80800164;
    }
    goto skip_0;
    // 0x808002B0: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    skip_0:
L_808002B4:
    // 0x808002B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002B8:
    // 0x808002B8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x808002BC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808002C0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808002C4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808002C8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808002CC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808002D0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808002D4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808002D8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x808002DC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x808002E0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x808002E4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x808002E8: jr          $ra
    // 0x808002EC: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x808002EC: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_80800244_chsmalltrexdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800248: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x8080024C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800250: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800254: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800258: beq         $a1, $at, L_8080026C
    if (ctx->r5 == ctx->r1) {
        // 0x8080025C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080026C;
    }
    // 0x8080025C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800260: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80800264: bnel        $a1, $at, L_808002B8
    if (ctx->r5 != ctx->r1) {
        // 0x80800268: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808002B8;
    }
    goto skip_0;
    // 0x80800268: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
L_8080026C:
    // 0x8080026C: jal         0x800F54E4
    // 0x80800270: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800270: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800274: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080027C: jal         0x800F52B8
    // 0x80800280: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    func_800F52B8(rdram, ctx);
        goto after_1;
    // 0x80800280: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    after_1:
    // 0x80800284: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800288: bne         $v0, $at, L_808002B4
    if (ctx->r2 != ctx->r1) {
        // 0x8080028C: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_808002B4;
    }
    // 0x8080028C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800290: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800294: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800298: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080029C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808002A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002A4: jal         0x80086248
    // 0x808002A8: swc1        $f4, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f4.u32l;
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808002A8: swc1        $f4, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f4.u32l;
    after_2:
    // 0x808002AC: b           L_808002C8
    // 0x808002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002C8;
    // 0x808002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002B4:
    // 0x808002B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_808002B8:
    // 0x808002B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808002BC: jal         0x80086248
    // 0x808002C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808002C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808002C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002C8:
    // 0x808002C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002CC: jr          $ra
    // 0x808002D0: nop

    return;
    // 0x808002D0: nop

;}
RECOMP_FUNC void func_80800674_chmumbopad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800674: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800678: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080067C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800680: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800684: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800688: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x8080068C: jal         0x800F7CF4
    // 0x80800690: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800F7CF4(rdram, ctx);
        goto after_0;
    // 0x80800690: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_0:
    // 0x80800694: jal         0x800C067C
    // 0x80800698: addiu       $a0, $zero, 0x11DD
    ctx->r4 = ADD32(0, 0X11DD);
    func_800C067C(rdram, ctx);
        goto after_1;
    // 0x80800698: addiu       $a0, $zero, 0x11DD
    ctx->r4 = ADD32(0, 0X11DD);
    after_1:
    // 0x8080069C: jal         0x80800048
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800048_chmumbopad(rdram, ctx);
        goto after_2;
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808006A4: bne         $v0, $zero, L_808006CC
    if (ctx->r2 != 0) {
        // 0x808006A8: addiu       $a1, $zero, 0x11DE
        ctx->r5 = ADD32(0, 0X11DE);
            goto L_808006CC;
    }
    // 0x808006A8: addiu       $a1, $zero, 0x11DE
    ctx->r5 = ADD32(0, 0X11DE);
    // 0x808006AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808006B4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808006B8: jal         0x8008A208
    // 0x808006BC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808006BC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808006C0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808006C4: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x808006C8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_808006CC:
    // 0x808006CC: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808006D0: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x808006D4: addiu       $a0, $zero, 0x11DD
    ctx->r4 = ADD32(0, 0X11DD);
    // 0x808006D8: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x808006DC: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x808006E0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x808006E4: jal         0x800C067C
    // 0x808006E8: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    func_800C067C(rdram, ctx);
        goto after_4;
    // 0x808006E8: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    after_4:
    // 0x808006EC: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
    // 0x808006F0: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x808006F4: sltiu       $at, $t5, 0x11
    ctx->r1 = ctx->r13 < 0X11 ? 1 : 0;
    // 0x808006F8: beq         $at, $zero, L_8080088C
    if (ctx->r1 == 0) {
        // 0x808006FC: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8080088C;
    }
    // 0x808006FC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800700: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1720, 0XFCC) << 16);
    // 0x80800704: addu        $at, $at, $t5
    gpr jr_addend_8080070C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80800708: lw          $t5, 0xFCC($at)
    ctx->r13 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1720, 0XFCC));
    // 0x8080070C: jr          $t5
    // 0x80800710: nop

    switch (jr_addend_8080070C >> 2) {
        case 0: goto L_8080088C; break;
        case 1: goto L_8080088C; break;
        case 2: goto L_80800714; break;
        case 3: goto L_80800724; break;
        case 4: goto L_8080073C; break;
        case 5: goto L_80800754; break;
        case 6: goto L_8080076C; break;
        case 7: goto L_80800784; break;
        case 8: goto L_8080079C; break;
        case 9: goto L_808007B4; break;
        case 10: goto L_808007F4; break;
        case 11: goto L_808007D4; break;
        case 12: goto L_80800814; break;
        case 13: goto L_80800834; break;
        case 14: goto L_8080084C; break;
        case 15: goto L_80800864; break;
        case 16: goto L_8080087C; break;
        default: switch_error(__func__, 0x8080070C, 0x80800FCC);
    }
    // 0x80800710: nop

L_80800714:
    // 0x80800714: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800718: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x8080071C: b           L_8080088C
    // 0x80800720: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_8080088C;
    // 0x80800720: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_80800724:
    // 0x80800724: addiu       $a0, $zero, 0x337
    ctx->r4 = ADD32(0, 0X337);
    // 0x80800728: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8080072C: jal         0x80101180
    // 0x80800730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x80800730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800734: b           L_80800890
    // 0x80800738: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800738: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_8080073C:
    // 0x8080073C: addiu       $a0, $zero, 0x39D
    ctx->r4 = ADD32(0, 0X39D);
    // 0x80800740: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800744: jal         0x80101180
    // 0x80800748: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800748: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8080074C: b           L_80800890
    // 0x80800750: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800750: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_80800754:
    // 0x80800754: addiu       $a0, $zero, 0x39C
    ctx->r4 = ADD32(0, 0X39C);
    // 0x80800758: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8080075C: jal         0x80101180
    // 0x80800760: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80800760: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800764: b           L_80800890
    // 0x80800768: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800768: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_8080076C:
    // 0x8080076C: addiu       $a0, $zero, 0x297
    ctx->r4 = ADD32(0, 0X297);
    // 0x80800770: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x80800774: jal         0x80101180
    // 0x80800778: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_8;
    // 0x80800778: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8080077C: b           L_80800890
    // 0x80800780: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800780: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_80800784:
    // 0x80800784: addiu       $a0, $zero, 0x292
    ctx->r4 = ADD32(0, 0X292);
    // 0x80800788: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8080078C: jal         0x80101180
    // 0x80800790: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_9;
    // 0x80800790: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800794: b           L_80800890
    // 0x80800798: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800798: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_8080079C:
    // 0x8080079C: addiu       $a0, $zero, 0x28E
    ctx->r4 = ADD32(0, 0X28E);
    // 0x808007A0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x808007A4: jal         0x80101180
    // 0x808007A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80101180(rdram, ctx);
        goto after_10;
    // 0x808007A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_10:
    // 0x808007AC: b           L_80800890
    // 0x808007B0: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x808007B0: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_808007B4:
    // 0x808007B4: addiu       $a0, $zero, 0x28D
    ctx->r4 = ADD32(0, 0X28D);
    // 0x808007B8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x808007BC: jal         0x80101180
    // 0x808007C0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_80101180(rdram, ctx);
        goto after_11;
    // 0x808007C0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_11:
    // 0x808007C4: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x808007C8: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x808007CC: b           L_8080088C
    // 0x808007D0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_8080088C;
    // 0x808007D0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_808007D4:
    // 0x808007D4: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    // 0x808007D8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x808007DC: jal         0x80101180
    // 0x808007E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_12;
    // 0x808007E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x808007E4: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808007E8: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x808007EC: b           L_8080088C
    // 0x808007F0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_8080088C;
    // 0x808007F0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_808007F4:
    // 0x808007F4: addiu       $a0, $zero, 0x3F5
    ctx->r4 = ADD32(0, 0X3F5);
    // 0x808007F8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x808007FC: jal         0x80101180
    // 0x80800800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_13;
    // 0x80800800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80800804: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800808: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x8080080C: b           L_8080088C
    // 0x80800810: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_8080088C;
    // 0x80800810: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800814:
    // 0x80800814: addiu       $a0, $zero, 0x40E
    ctx->r4 = ADD32(0, 0X40E);
    // 0x80800818: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8080081C: jal         0x80101180
    // 0x80800820: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_80101180(rdram, ctx);
        goto after_14;
    // 0x80800820: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_14:
    // 0x80800824: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800828: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x8080082C: b           L_8080088C
    // 0x80800830: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_8080088C;
    // 0x80800830: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80800834:
    // 0x80800834: addiu       $a0, $zero, 0x346
    ctx->r4 = ADD32(0, 0X346);
    // 0x80800838: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8080083C: jal         0x80101180
    // 0x80800840: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_15;
    // 0x80800840: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80800844: b           L_80800890
    // 0x80800848: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800848: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_8080084C:
    // 0x8080084C: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    // 0x80800850: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x80800854: jal         0x80101180
    // 0x80800858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_16;
    // 0x80800858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x8080085C: b           L_80800890
    // 0x80800860: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800860: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_80800864:
    // 0x80800864: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    // 0x80800868: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8080086C: jal         0x80101180
    // 0x80800870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_17;
    // 0x80800870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80800874: b           L_80800890
    // 0x80800878: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800878: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_8080087C:
    // 0x8080087C: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    // 0x80800880: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x80800884: jal         0x80101180
    // 0x80800888: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_18;
    // 0x80800888: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
L_8080088C:
    // 0x8080088C: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_80800890:
    // 0x80800890: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800894: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x80800898: lbu         $t2, 0x2A($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2A);
    // 0x8080089C: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x808008A0: sltiu       $t9, $t7, 0x1
    ctx->r25 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x808008A4: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x808008A8: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x808008AC: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x808008B0: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x808008B4: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x808008B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008C4: jr          $ra
    // 0x808008C8: nop

    return;
    // 0x808008C8: nop

;}
RECOMP_FUNC void func_80800734_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800734: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800738: jr          $ra
    // 0x8080073C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8080073C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
;}
