#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsblongleg_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A28: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A28);
    return;
    // 0x80082A2C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _ncbafixpos_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089340: syscall     774
    recomp_syscall_handler(rdram, ctx, 0x80089340);
    return;
    // 0x80089344: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808015E4_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808015E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015EC: jal         0x800839B8
    // 0x808015F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808015F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808015F4: jal         0x80800238
    // 0x808015F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800238_bsbansack(rdram, ctx);
        goto after_1;
    // 0x808015F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808015FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801604: jr          $ra
    // 0x80801608: nop

    return;
    // 0x80801608: nop

;}
RECOMP_FUNC void func_80800708_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800708: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080070C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800710: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800714: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800718: jal         0x8008CABC
    // 0x8080071C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080071C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    after_0:
    // 0x80800720: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80800724: jal         0x80082840
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080072C: jal         0x80084C68
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800734: jal         0x80800480
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800480_bsbeefly(rdram, ctx);
        goto after_3;
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800740: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80800744: jal         0x80084C18
    // 0x80800748: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    _bafly_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800748: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_4:
    // 0x8080074C: jal         0x80084C20
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800754: jal         0x8009BFCC
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFCC(rdram, ctx);
        goto after_6;
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800760: jal         0x80091A58
    // 0x80800764: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_7;
    // 0x80800764: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x80800768: beq         $v0, $zero, L_8080079C
    if (ctx->r2 == 0) {
        // 0x8080076C: nop
    
            goto L_8080079C;
    }
    // 0x8080076C: nop

    // 0x80800770: jal         0x8009C150
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C150(rdram, ctx);
        goto after_8;
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800778: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(76, 0XDA0) << 16);
    // 0x8080077C: lwc1        $f4, 0xDA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(76, 0XDA0));
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800784: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800788: nop

    // 0x8080078C: bc1f        L_8080079C
    if (!c1cs) {
        // 0x80800790: nop
    
            goto L_8080079C;
    }
    // 0x80800790: nop

    // 0x80800794: jal         0x80084598
    // 0x80800798: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _baboost_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800798: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
L_8080079C:
    // 0x8080079C: jal         0x80084590
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808007A4: bne         $v0, $zero, L_808007C4
    if (ctx->r2 != 0) {
        // 0x808007A8: nop
    
            goto L_808007C4;
    }
    // 0x808007A8: nop

    // 0x808007AC: jal         0x8008E35C
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_11;
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808007B4: beq         $v0, $zero, L_808007C4
    if (ctx->r2 == 0) {
        // 0x808007B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007C4;
    }
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007BC: jal         0x80084598
    // 0x808007C0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _baboost_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x808007C0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_12:
L_808007C4:
    // 0x808007C4: jal         0x80084590
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808007CC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808007D0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(76, 0XE28) << 16);
    // 0x808007D4: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x808007D8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x808007DC: lw          $a1, 0xE28($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(76, 0XE28));
    // 0x808007E0: jal         0x8008B1BC
    // 0x808007E4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    anctrl_setDuration(rdram, ctx);
        goto after_14;
    // 0x808007E4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_14:
    // 0x808007E8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x808007EC: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(76, 0XE3C) << 16);
    // 0x808007F0: addiu       $t9, $t9, 0xE3C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(76, 0XE3C));
    // 0x808007F4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808007F8: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x808007FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(76, 0XDA4) << 16);
    // 0x80800800: lwc1        $f6, 0xDA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(76, 0XDA4));
    // 0x80800804: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800808: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800814: jal         0x8009BFCC
    // 0x80800818: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    func_8009BFCC(rdram, ctx);
        goto after_15;
    // 0x80800818: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x8080081C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800824: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800828: jal         0x8009BB50
    // 0x8080082C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_16;
    // 0x8080082C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_16:
    // 0x80800830: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800834: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800838: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080083C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80800840: nop

    // 0x80800844: bc1f        L_808008B8
    if (!c1cs) {
        // 0x80800848: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_808008B8;
    }
    // 0x80800848: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080084C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800850: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(76, 0XDA8) << 16);
    // 0x80800854: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x80800858: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8080085C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800860: bc1fl       L_80800884
    if (!c1cs) {
        // 0x80800864: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_80800884;
    }
    goto skip_0;
    // 0x80800864: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    skip_0:
    // 0x80800868: lwc1        $f18, 0xDA8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(76, 0XDA8));
    // 0x8080086C: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    // 0x80800870: jal         0x800F10B4
    // 0x80800874: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_17;
    // 0x80800874: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x80800878: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080087C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800880: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
L_80800884:
    // 0x80800884: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800888: lui         $a3, 0xBE4C
    ctx->r7 = S32(0XBE4C << 16);
    // 0x8080088C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800890: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80800894: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800898: lui         $a2, 0x43B4
    ctx->r6 = S32(0X43B4 << 16);
    // 0x8080089C: bc1fl       L_808008BC
    if (!c1cs) {
        // 0x808008A0: lwc1        $f8, 0x50($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
            goto L_808008BC;
    }
    goto skip_1;
    // 0x808008A0: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    skip_1:
    // 0x808008A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808008A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808008AC: jal         0x800F10B4
    // 0x808008B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_18;
    // 0x808008B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_18:
    // 0x808008B4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_808008B8:
    // 0x808008B8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
L_808008BC:
    // 0x808008BC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x808008C0: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x808008C4: bne         $t0, $zero, L_808008F0
    if (ctx->r8 != 0) {
        // 0x808008C8: swc1        $f10, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
            goto L_808008F0;
    }
    // 0x808008C8: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D0: jal         0x800919F4
    // 0x808008D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_19;
    // 0x808008D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_19:
    // 0x808008D8: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x808008DC: lwc1        $f16, 0x50($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
            goto L_808008F0;
    }
    // 0x808008DC: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808008E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(76, 0XDAC) << 16);
    // 0x808008E4: lwc1        $f18, 0xDAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(76, 0XDAC));
    // 0x808008E8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808008EC: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
L_808008F0:
    // 0x808008F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F4: jal         0x800847B0
    // 0x808008F8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    _babuzz_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x808008F8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_20:
    // 0x808008FC: jal         0x800847A8
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babuzz_entrypoint_3(rdram, ctx);
        goto after_21;
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800904: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800908: beq         $v0, $zero, L_80800920
    if (ctx->r2 == 0) {
        // 0x8080090C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800920;
    }
    // 0x8080090C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800910: beq         $v0, $at, L_8080093C
    if (ctx->r2 == ctx->r1) {
        // 0x80800914: nop
    
            goto L_8080093C;
    }
    // 0x80800914: nop

    // 0x80800918: b           L_80800A04
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A04;
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800920:
    // 0x80800920: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80800924: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(76, 0XE3C) << 16);
    // 0x80800928: addiu       $t2, $t2, 0xE3C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(76, 0XE3C));
    // 0x8080092C: beq         $t1, $t2, L_80800A00
    if (ctx->r9 == ctx->r10) {
        // 0x80800930: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80800A00;
    }
    // 0x80800930: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800934: b           L_80800A00
    // 0x80800938: sw          $t3, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r11;
        goto L_80800A00;
    // 0x80800938: sw          $t3, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r11;
L_8080093C:
    // 0x8080093C: jal         0x8009BFD8
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_22;
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800944: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800948: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080094C: jal         0x800136E4
    // 0x80800950: sub.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_23;
    // 0x80800950: sub.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f6.fl;
    after_23:
    // 0x80800954: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800958: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080095C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800960: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800964: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800968: nop

    // 0x8080096C: bc1fl       L_80800998
    if (!c1cs) {
        // 0x80800970: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_80800998;
    }
    goto skip_2;
    // 0x80800970: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_2:
    // 0x80800974: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800978: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080097C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800980: nop

    // 0x80800984: bc1fl       L_80800998
    if (!c1cs) {
        // 0x80800988: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_80800998;
    }
    goto skip_3;
    // 0x80800988: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_3:
    // 0x8080098C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800990: nop

    // 0x80800994: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_80800998:
    // 0x80800998: jal         0x8009BF5C
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BF5C(rdram, ctx);
        goto after_24;
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808009A0: jal         0x80084C70
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_21(rdram, ctx);
        goto after_25;
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808009A8: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x808009AC: beql        $t4, $zero, L_808009E4
    if (ctx->r12 == 0) {
        // 0x808009B0: lw          $t5, 0x30($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X30);
            goto L_808009E4;
    }
    goto skip_4;
    // 0x808009B0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    skip_4:
    // 0x808009B4: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x808009B8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808009BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808009CC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808009D0: jal         0x8009BA58
    // 0x808009D4: nop

    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_26;
    // 0x808009D4: nop

    after_26:
    // 0x808009D8: jal         0x80800000
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbeefly(rdram, ctx);
        goto after_27;
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808009E0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
L_808009E4:
    // 0x808009E4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(76, 0XE3C) << 16);
    // 0x808009E8: addiu       $t6, $t6, 0xE3C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(76, 0XE3C));
    // 0x808009EC: bnel        $t5, $t6, L_80800A04
    if (ctx->r13 != ctx->r14) {
        // 0x808009F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A04;
    }
    goto skip_5;
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x808009F4: jal         0x80084C68
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_20(rdram, ctx);
        goto after_28;
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808009FC: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_80800A00:
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A04:
    // 0x80800A04: jal         0x800919F4
    // 0x80800A08: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_29;
    // 0x80800A08: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_29:
    // 0x80800A0C: beq         $v0, $zero, L_80800A2C
    if (ctx->r2 == 0) {
        // 0x80800A10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A2C;
    }
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A14: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(76, 0XDB0) << 16);
    // 0x80800A18: lwc1        $f0, 0xDB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(76, 0XDB0));
    // 0x80800A1C: lui         $at, 0xC4E1
    ctx->r1 = S32(0XC4E1 << 16);
    // 0x80800A20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800A24: b           L_80800A44
    // 0x80800A28: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
        goto L_80800A44;
    // 0x80800A28: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
L_80800A2C:
    // 0x80800A2C: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x80800A30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A34: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x80800A38: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800A3C: nop

    // 0x80800A40: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
L_80800A44:
    // 0x80800A44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800A48: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(76, 0XDB4) << 16);
    // 0x80800A4C: lwc1        $f10, 0xDB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(76, 0XDB4));
    // 0x80800A50: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80800A54: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x80800A58: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    // 0x80800A5C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80800A60: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80800A64: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80800A68: jal         0x80084C08
    // 0x80800A6C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    _bafly_entrypoint_8(rdram, ctx);
        goto after_30;
    // 0x80800A6C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_30:
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A74: jal         0x800919F4
    // 0x80800A78: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_31;
    // 0x80800A78: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_31:
    // 0x80800A7C: beql        $v0, $zero, L_80800AB4
    if (ctx->r2 == 0) {
        // 0x80800A80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AB4;
    }
    goto skip_6;
    // 0x80800A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x80800A84: jal         0x808000A4
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000A4_bsbeefly(rdram, ctx);
        goto after_32;
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800A8C: jal         0x8009BB00
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_33;
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80800A94: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80800A98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800AA4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800AA8: jal         0x8009B9B0
    // 0x80800AAC: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_34;
    // 0x80800AAC: nop

    after_34:
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AB4:
    // 0x80800AB4: jal         0x800919F4
    // 0x80800AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_35;
    // 0x80800AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x80800ABC: beq         $v0, $zero, L_80800ACC
    if (ctx->r2 == 0) {
        // 0x80800AC0: nop
    
            goto L_80800ACC;
    }
    // 0x80800AC0: nop

    // 0x80800AC4: jal         0x80084550
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_2(rdram, ctx);
        goto after_36;
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
L_80800ACC:
    // 0x80800ACC: jal         0x80084BD8
    // 0x80800AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_2(rdram, ctx);
        goto after_37;
    // 0x80800AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800AD4: beq         $v0, $zero, L_80800AF0
    if (ctx->r2 == 0) {
        // 0x80800AD8: nop
    
            goto L_80800AF0;
    }
    // 0x80800AD8: nop

    // 0x80800ADC: jal         0x8008E35C
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_38;
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80800AE4: bne         $v0, $zero, L_80800AF0
    if (ctx->r2 != 0) {
        // 0x80800AE8: addiu       $t7, $zero, 0x85
        ctx->r15 = ADD32(0, 0X85);
            goto L_80800AF0;
    }
    // 0x80800AE8: addiu       $t7, $zero, 0x85
    ctx->r15 = ADD32(0, 0X85);
    // 0x80800AEC: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
L_80800AF0:
    // 0x80800AF0: jal         0x800845B0
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_5(rdram, ctx);
        goto after_39;
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AFC: jal         0x8009E5C8
    // 0x80800B00: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    bs_setState(rdram, ctx);
        goto after_40;
    // 0x80800B00: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_40:
    // 0x80800B04: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B08: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800B0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800B10: jr          $ra
    // 0x80800B14: nop

    return;
    // 0x80800B14: nop

;}
RECOMP_FUNC void func_80803564_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803564: jr          $ra
    // 0x80803568: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80803568: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bsdie_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FD8: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082FD8);
    return;
    // 0x80082FDC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void scinfobar_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E8: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x808003EC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x808003F0: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x808003F4: beq         $t6, $zero, L_80800404
    if (ctx->r14 == 0) {
        // 0x808003F8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800404;
    }
    // 0x808003F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808003FC: jr          $ra
    // 0x80800400: sh          $a1, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r5;
    return;
    // 0x80800400: sh          $a1, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r5;
L_80800404:
    // 0x80800404: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3338, 0XD5C) << 16);
    // 0x80800408: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x8080040C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800410: lwc1        $f4, 0xD5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3338, 0XD5C));
    // 0x80800414: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80800418: jr          $ra
    // 0x8080041C: nop

    return;
    // 0x8080041C: nop

;}
RECOMP_FUNC void _bssplitup_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B10: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083B10);
    return;
    // 0x80083B14: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_800F5D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5D9C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5DA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5DA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5DAC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5DB0: jal         0x800F4200
    // 0x800F5DB4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F4200(rdram, ctx);
        goto after_0;
    // 0x800F5DB4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5DC0: jr          $ra
    // 0x800F5DC4: nop

    return;
    // 0x800F5DC4: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A858: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A858);
    return;
    // 0x8008A85C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_801125D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801125D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801125DC: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x801125E0: jr          $ra
    // 0x801125E4: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x801125E4: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chklungodoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863C8: syscall     319
    recomp_syscall_handler(rdram, ctx, 0x800863C8);
    return;
    // 0x800863CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chterryegg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086180: syscall     283
    recomp_syscall_handler(rdram, ctx, 0x80086180);
    return;
    // 0x80086184: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808003B0_chdinofamilysick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B4: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x808003B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003BC: bne         $at, $zero, L_808003D8
    if (ctx->r1 != 0) {
        // 0x808003C0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808003D8;
    }
    // 0x808003C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808003C4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003C8: beq         $a1, $at, L_808004E0
    if (ctx->r5 == ctx->r1) {
        // 0x808003CC: nop
    
            goto L_808004E0;
    }
    // 0x808003CC: nop

    // 0x808003D0: b           L_808005DC
    // 0x808003D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005DC;
    // 0x808003D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003D8:
    // 0x808003D8: addiu       $t6, $a1, -0x1F
    ctx->r14 = ADD32(ctx->r5, -0X1F);
    // 0x808003DC: sltiu       $at, $t6, 0x34
    ctx->r1 = ctx->r14 < 0X34 ? 1 : 0;
    // 0x808003E0: beq         $at, $zero, L_808005D8
    if (ctx->r1 == 0) {
        // 0x808003E4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808005D8;
    }
    // 0x808003E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808003E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2408, 0XD70) << 16);
    // 0x808003EC: addu        $at, $at, $t6
    gpr jr_addend_808003F4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808003F0: lw          $t6, 0xD70($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2408, 0XD70));
    // 0x808003F4: jr          $t6
    // 0x808003F8: nop

    switch (jr_addend_808003F4 >> 2) {
        case 0: goto L_80800470; break;
        case 1: goto L_808005D8; break;
        case 2: goto L_808005D8; break;
        case 3: goto L_808005D8; break;
        case 4: goto L_808005D8; break;
        case 5: goto L_808005D8; break;
        case 6: goto L_808005D8; break;
        case 7: goto L_808005D8; break;
        case 8: goto L_808005D8; break;
        case 9: goto L_808005D8; break;
        case 10: goto L_808005D8; break;
        case 11: goto L_808005D8; break;
        case 12: goto L_808005D8; break;
        case 13: goto L_808005D8; break;
        case 14: goto L_808005D8; break;
        case 15: goto L_808005D8; break;
        case 16: goto L_808005D8; break;
        case 17: goto L_808005D8; break;
        case 18: goto L_808005D8; break;
        case 19: goto L_808005D8; break;
        case 20: goto L_808005D8; break;
        case 21: goto L_808005D8; break;
        case 22: goto L_808005D8; break;
        case 23: goto L_808005D8; break;
        case 24: goto L_808004CC; break;
        case 25: goto L_808005D8; break;
        case 26: goto L_808005D8; break;
        case 27: goto L_808005D8; break;
        case 28: goto L_808005D8; break;
        case 29: goto L_808005D8; break;
        case 30: goto L_808005D8; break;
        case 31: goto L_808003FC; break;
        case 32: goto L_808005D8; break;
        case 33: goto L_808005D8; break;
        case 34: goto L_808005D8; break;
        case 35: goto L_808005D8; break;
        case 36: goto L_808005D8; break;
        case 37: goto L_8080045C; break;
        case 38: goto L_808005D8; break;
        case 39: goto L_808005D8; break;
        case 40: goto L_808005D8; break;
        case 41: goto L_808005D8; break;
        case 42: goto L_808005D8; break;
        case 43: goto L_808005D8; break;
        case 44: goto L_808005D8; break;
        case 45: goto L_808005D8; break;
        case 46: goto L_808005D8; break;
        case 47: goto L_808005D8; break;
        case 48: goto L_808005D8; break;
        case 49: goto L_808005D8; break;
        case 50: goto L_808005D8; break;
        case 51: goto L_808005B0; break;
        default: switch_error(__func__, 0x808003F4, 0x80800D70);
    }
    // 0x808003F8: nop

L_808003FC:
    // 0x808003FC: lhu         $v0, 0x72($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X72);
    // 0x80800400: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800404: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    // 0x80800408: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x8080040C: beq         $t7, $at, L_80800424
    if (ctx->r15 == ctx->r1) {
        // 0x80800410: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800424;
    }
    // 0x80800410: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800414: beq         $t7, $at, L_80800424
    if (ctx->r15 == ctx->r1) {
        // 0x80800418: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800424;
    }
    // 0x80800418: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080041C: bne         $t7, $at, L_80800454
    if (ctx->r15 != ctx->r1) {
        // 0x80800420: nop
    
            goto L_80800454;
    }
    // 0x80800420: nop

L_80800424:
    // 0x80800424: jal         0x800DA298
    // 0x80800428: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800428: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080042C: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800430: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080044C;
    }
    // 0x80800430: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800434: jal         0x8008A508
    // 0x80800438: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _subaddietaxi_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800438: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080043C: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800440: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080044C;
    }
    // 0x80800440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800444: jal         0x80102424
    // 0x80800448: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800448: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_8080044C:
    // 0x8080044C: b           L_808005DC
    // 0x80800450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800454:
    // 0x80800454: b           L_808005DC
    // 0x80800458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005DC;
    // 0x80800458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080045C:
    // 0x8080045C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800460: jal         0x80800244
    // 0x80800464: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800244_chdinofamilysick(rdram, ctx);
        goto after_3;
    // 0x80800464: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x80800468: b           L_808005DC
    // 0x8080046C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x8080046C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800470:
    // 0x80800470: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800474: jal         0x801015D0
    // 0x80800478: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_801015D0(rdram, ctx);
        goto after_4;
    // 0x80800478: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_4:
    // 0x8080047C: jal         0x801022E4
    // 0x80800480: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_801022E4(rdram, ctx);
        goto after_5;
    // 0x80800480: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80800484: addiu       $at, $zero, 0x3F7
    ctx->r1 = ADD32(0, 0X3F7);
    // 0x80800488: bne         $v0, $at, L_808004A4
    if (ctx->r2 != ctx->r1) {
        // 0x8080048C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_808004A4;
    }
    // 0x8080048C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800490: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800494: jal         0x800DF744
    // 0x80800498: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x80800498: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080049C: b           L_808005DC
    // 0x808004A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808004A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004A4:
    // 0x808004A4: jal         0x800DF744
    // 0x808004A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x808004A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808004AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808004B0: jal         0x800DF744
    // 0x808004B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x808004B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808004B8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808004BC: jal         0x800DF744
    // 0x808004C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_9;
    // 0x808004C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808004C4: b           L_808005DC
    // 0x808004C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808004C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004CC:
    // 0x808004CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004D0: jal         0x80101EE4
    // 0x808004D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101EE4(rdram, ctx);
        goto after_10;
    // 0x808004D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x808004D8: b           L_808005DC
    // 0x808004DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808004DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004E0:
    // 0x808004E0: jal         0x80088848
    // 0x808004E4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_11;
    // 0x808004E4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_11:
    // 0x808004E8: beq         $v0, $zero, L_80800500
    if (ctx->r2 == 0) {
        // 0x808004EC: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80800500;
    }
    // 0x808004EC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808004F0: jal         0x800FFAB0
    // 0x808004F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x808004F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_12:
    // 0x808004F8: b           L_808005DC
    // 0x808004FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808004FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800500:
    // 0x80800500: lw          $t9, 0x78($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X78);
    // 0x80800504: sll         $t1, $t9, 26
    ctx->r9 = S32(ctx->r25 << 26);
    // 0x80800508: bgez        $t1, L_8080056C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8080050C: nop
    
            goto L_8080056C;
    }
    // 0x8080050C: nop

    // 0x80800510: jal         0x800DA298
    // 0x80800514: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80800514: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_13:
    // 0x80800518: bne         $v0, $zero, L_80800530
    if (ctx->r2 != 0) {
        // 0x8080051C: nop
    
            goto L_80800530;
    }
    // 0x8080051C: nop

    // 0x80800520: jal         0x800DA298
    // 0x80800524: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80800524: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_14:
    // 0x80800528: beq         $v0, $zero, L_80800540
    if (ctx->r2 == 0) {
        // 0x8080052C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800540;
    }
    // 0x8080052C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800530:
    // 0x80800530: jal         0x800FFAB0
    // 0x80800534: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_15;
    // 0x80800534: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_15:
    // 0x80800538: b           L_808005DC
    // 0x8080053C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x8080053C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800540:
    // 0x80800540: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800544: addiu       $a2, $a2, 0x76E8
    ctx->r6 = ADD32(ctx->r6, 0X76E8);
    // 0x80800548: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080054C: jal         0x8008A560
    // 0x80800550: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddietaxi_entrypoint_13(rdram, ctx);
        goto after_16;
    // 0x80800550: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_16:
    // 0x80800554: bne         $v0, $zero, L_808005A8
    if (ctx->r2 != 0) {
        // 0x80800558: nop
    
            goto L_808005A8;
    }
    // 0x80800558: nop

    // 0x8080055C: jal         0x800FFAB0
    // 0x80800560: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_17;
    // 0x80800560: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_17:
    // 0x80800564: b           L_808005DC
    // 0x80800568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080056C:
    // 0x8080056C: jal         0x800CB3E0
    // 0x80800570: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800CB3E0(rdram, ctx);
        goto after_18;
    // 0x80800570: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_18:
    // 0x80800574: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800578: beq         $v0, $at, L_808005A0
    if (ctx->r2 == ctx->r1) {
        // 0x8080057C: nop
    
            goto L_808005A0;
    }
    // 0x8080057C: nop

    // 0x80800580: jal         0x800DA298
    // 0x80800584: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_19;
    // 0x80800584: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_19:
    // 0x80800588: bne         $v0, $zero, L_808005A0
    if (ctx->r2 != 0) {
        // 0x8080058C: nop
    
            goto L_808005A0;
    }
    // 0x8080058C: nop

    // 0x80800590: jal         0x800DA298
    // 0x80800594: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_20;
    // 0x80800594: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_20:
    // 0x80800598: beq         $v0, $zero, L_808005A8
    if (ctx->r2 == 0) {
        // 0x8080059C: nop
    
            goto L_808005A8;
    }
    // 0x8080059C: nop

L_808005A0:
    // 0x808005A0: jal         0x800FFAB0
    // 0x808005A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_21;
    // 0x808005A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_21:
L_808005A8:
    // 0x808005A8: b           L_808005DC
    // 0x808005AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808005AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B0:
    // 0x808005B0: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // 0x808005B4: jal         0x80088098
    // 0x808005B8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x808005B8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_22:
    // 0x808005BC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x808005C0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2408, 0XE98) << 16);
    // 0x808005C4: addiu       $a0, $a0, 0xE98
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2408, 0XE98));
    // 0x808005C8: jal         0x80088090
    // 0x808005CC: lw          $a1, 0x38($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x808005CC: lw          $a1, 0x38($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X38);
    after_23:
    // 0x808005D0: b           L_808005DC
    // 0x808005D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808005DC;
    // 0x808005D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808005D8:
    // 0x808005D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005DC:
    // 0x808005DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005E4: jr          $ra
    // 0x808005E8: nop

    return;
    // 0x808005E8: nop

;}
RECOMP_FUNC void _idflame_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E38: syscall     743
    recomp_syscall_handler(rdram, ctx, 0x80088E38);
    return;
    // 0x80088E3C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bskazglide_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833F8: syscall     59
    recomp_syscall_handler(rdram, ctx, 0x800833F8);
    return;
    // 0x800833FC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bstntswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080061C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800620: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(408, 0X9C0) << 16);
    // 0x80800624: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800628: jr          $ra
    // 0x8080062C: lw          $v0, 0x9C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(408, 0X9C0));
    return;
    // 0x8080062C: lw          $v0, 0x9C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(408, 0X9C0));
;}
RECOMP_FUNC void bskazflamethrower_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E0: jal         0x80800094
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800094_bskazflamethrower(rdram, ctx);
        goto after_0;
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void _chpoolkids_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860F0: syscall     278
    recomp_syscall_handler(rdram, ctx, 0x800860F0);
    return;
    // 0x800860F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bskazjump_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800588: jal         0x800832E8
    // 0x8080058C: nop

    _bskaz_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080058C: nop

    after_0:
    // 0x80800590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800598: jr          $ra
    // 0x8080059C: nop

    return;
    // 0x8080059C: nop

;}
RECOMP_FUNC void _bstimeout_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F30: syscall     98
    recomp_syscall_handler(rdram, ctx, 0x80083F30);
    return;
    // 0x80083F34: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80112250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112250: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80112254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80112258: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8011225C: jal         0x80110840
    // 0x80112260: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x80112260: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x80112264: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80112268: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8011226C: jal         0x80112168
    // 0x80112270: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80112168(rdram, ctx);
        goto after_1;
    // 0x80112270: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_1:
    // 0x80112274: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80112278: jal         0x801107F0
    // 0x8011227C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_801107F0(rdram, ctx);
        goto after_2;
    // 0x8011227C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x80112280: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80112284: jal         0x800EEAD4
    // 0x80112288: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800EEAD4(rdram, ctx);
        goto after_3;
    // 0x80112288: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x8011228C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80112290: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80112294: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80112298: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8011229C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801122A0: jal         0x800EFA4C
    // 0x801122A4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x801122A4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_4:
    // 0x801122A8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x801122AC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801122B0: jal         0x800F51F0
    // 0x801122B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F51F0(rdram, ctx);
        goto after_5;
    // 0x801122B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x801122B8: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x801122BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801122C0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801122C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801122C8: lui         $a2, 0x44BB
    ctx->r6 = S32(0X44BB << 16);
    // 0x801122CC: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x801122D0: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801122D4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801122D8: jal         0x800F10B4
    // 0x801122DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x801122DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x801122E0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801122E4: jal         0x800F5AE0
    // 0x801122E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F5AE0(rdram, ctx);
        goto after_7;
    // 0x801122E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x801122EC: jal         0x80013728
    // 0x801122F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_8;
    // 0x801122F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    // 0x801122F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801122F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x801122FC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80112300: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80112304: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    // 0x80112308: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8011230C: bc1fl       L_80112330
    if (!c1cs) {
        // 0x80112310: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_80112330;
    }
    goto skip_0;
    // 0x80112310: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    skip_0:
    // 0x80112314: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80112318: jal         0x800F10B4
    // 0x8011231C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x8011231C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x80112320: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80112324: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80112328: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8011232C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
L_80112330:
    // 0x80112330: jal         0x800EF368
    // 0x80112334: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EF368(rdram, ctx);
        goto after_10;
    // 0x80112334: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x80112338: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8011233C: jal         0x800EF04C
    // 0x80112340: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80112340: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_11:
    // 0x80112344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80112348: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8011234C: jr          $ra
    // 0x80112350: nop

    return;
    // 0x80112350: nop

;}
RECOMP_FUNC void func_800B7174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7174: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7178: addiu       $v0, $v0, -0x7E80
    ctx->r2 = ADD32(ctx->r2, -0X7E80);
    // 0x800B717C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7184: sb          $zero, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = 0;
    // 0x800B7188: sb          $zero, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = 0;
    // 0x800B718C: sb          $zero, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = 0;
    // 0x800B7190: lhu         $t8, 0x6($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6);
    // 0x800B7194: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800B7198: addiu       $a1, $a2, 0x10
    ctx->r5 = ADD32(ctx->r6, 0X10);
    // 0x800B719C: srl         $t9, $t8, 12
    ctx->r25 = S32(U32(ctx->r24) >> 12);
    // 0x800B71A0: sb          $t9, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r25;
    // 0x800B71A4: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x800B71A8: sh          $t0, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r8;
    // 0x800B71AC: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x800B71B0: sll         $t2, $t1, 20
    ctx->r10 = S32(ctx->r9 << 20);
    // 0x800B71B4: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x800B71B8: sb          $t3, 0x21($v0)
    MEM_B(0X21, ctx->r2) = ctx->r11;
    // 0x800B71BC: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
    // 0x800B71C0: sh          $zero, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = 0;
    // 0x800B71C4: lh          $t7, 0x2A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2A);
    // 0x800B71C8: sll         $t5, $t4, 22
    ctx->r13 = S32(ctx->r12 << 22);
    // 0x800B71CC: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x800B71D0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B71D4: sb          $t6, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r14;
    // 0x800B71D8: addiu       $a0, $a0, -0x7E5C
    ctx->r4 = ADD32(ctx->r4, -0X7E5C);
    // 0x800B71DC: jal         0x800F2EBC
    // 0x800B71E0: sh          $t7, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r15;
    func_800F2EBC(rdram, ctx);
        goto after_0;
    // 0x800B71E0: sh          $t7, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r15;
    after_0:
    // 0x800B71E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B71E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B71EC: jr          $ra
    // 0x800B71F0: nop

    return;
    // 0x800B71F0: nop

;}
RECOMP_FUNC void _ncba1p_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089408: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x80089408);
    return;
    // 0x8008940C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_808013C8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013D0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808013D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808013D8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808013DC: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808013E0: bgez        $t8, L_808013F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808013E4: slti        $at, $a1, 0x3
        ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_808013F0;
    }
    // 0x808013E4: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x808013E8: beql        $at, $zero, L_80801450
    if (ctx->r1 == 0) {
        // 0x808013EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801450;
    }
    goto skip_0;
    // 0x808013EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_808013F0:
    // 0x808013F0: lbu         $t2, 0x79($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X79);
    // 0x808013F4: sll         $t1, $a3, 4
    ctx->r9 = S32(ctx->r7 << 4);
    // 0x808013F8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x808013FC: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80801400: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80801404: andi        $a1, $t4, 0xFF
    ctx->r5 = ctx->r12 & 0XFF;
    // 0x80801408: sb          $t4, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r12;
    // 0x8080140C: srl         $t5, $a1, 4
    ctx->r13 = S32(U32(ctx->r5) >> 4);
    // 0x80801410: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80801414: jal         0x80101238
    // 0x80801418: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80101238(rdram, ctx);
        goto after_0;
    // 0x80801418: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080141C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801424: lhu         $t6, 0x6E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6E);
    // 0x80801428: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x8080142C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80801430: jal         0x80102424
    // 0x80801434: sh          $t8, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r24;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80801434: sh          $t8, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r24;
    after_1:
    // 0x80801438: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080143C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801440: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801444: nop

    // 0x80801448: swc1        $f4, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f4.u32l;
    // 0x8080144C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801450:
    // 0x80801450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801454: jr          $ra
    // 0x80801458: nop

    return;
    // 0x80801458: nop

;}
RECOMP_FUNC void _baboost_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845B0: syscall     115
    recomp_syscall_handler(rdram, ctx, 0x800845B0);
    return;
    // 0x800845B4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800C3584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3588: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C358C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3590: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C3594: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C3598: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C359C: beq         $t6, $zero, L_800C35D8
    if (ctx->r14 == 0) {
        // 0x800C35A0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C35D8;
    }
    // 0x800C35A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C35A4: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    // 0x800C35A8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x800C35AC: jal         0x800C1414
    // 0x800C35B0: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C35B0: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800C35B4: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C35B8: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C35BC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C35C0: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C35C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C35C8: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C35CC: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800C35D0: jal         0x800C368C
    // 0x800C35D4: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    func_800C368C(rdram, ctx);
        goto after_1;
    // 0x800C35D4: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    after_1:
L_800C35D8:
    // 0x800C35D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C35DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C35E0: jr          $ra
    // 0x800C35E4: nop

    return;
    // 0x800C35E4: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083280: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083280);
    return;
    // 0x80083284: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_808003F4_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003F8: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808003FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800400: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800404: beq         $a1, $at, L_80800524
    if (ctx->r5 == ctx->r1) {
        // 0x80800408: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800524;
    }
    // 0x80800408: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080040C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80800410: beq         $a1, $at, L_808005B8
    if (ctx->r5 == ctx->r1) {
        // 0x80800414: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808005B8;
    }
    // 0x80800414: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800418: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x8080041C: beq         $a1, $at, L_808005F8
    if (ctx->r5 == ctx->r1) {
        // 0x80800420: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808005F8;
    }
    // 0x80800420: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800424: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800428: beq         $a1, $at, L_80800450
    if (ctx->r5 == ctx->r1) {
        // 0x8080042C: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_80800450;
    }
    // 0x8080042C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80800430: addiu       $at, $zero, 0x76
    ctx->r1 = ADD32(0, 0X76);
    // 0x80800434: beq         $a1, $at, L_80800638
    if (ctx->r5 == ctx->r1) {
        // 0x80800438: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800638;
    }
    // 0x80800438: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080043C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800440: beql        $a1, $at, L_80800578
    if (ctx->r5 == ctx->r1) {
        // 0x80800444: lw          $v0, 0x6C($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X6C);
            goto L_80800578;
    }
    goto skip_0;
    // 0x80800444: lw          $v0, 0x6C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X6C);
    skip_0:
    // 0x80800448: b           L_80800660
    // 0x8080044C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800660;
    // 0x8080044C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800450:
    // 0x80800450: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
    // 0x80800454: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800458: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080045C: srl         $t6, $a0, 5
    ctx->r14 = S32(U32(ctx->r4) >> 5);
    // 0x80800460: jal         0x800F4B4C
    // 0x80800464: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F4B4C(rdram, ctx);
        goto after_0;
    // 0x80800464: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80800468: bne         $v0, $zero, L_80800478
    if (ctx->r2 != 0) {
        // 0x8080046C: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800478;
    }
    // 0x8080046C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800470: b           L_80800660
    // 0x80800474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800660;
    // 0x80800474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800478:
    // 0x80800478: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8080047C: addiu       $at, $zero, 0x1D4
    ctx->r1 = ADD32(0, 0X1D4);
    // 0x80800480: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800484: lw          $v0, 0x24($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X24);
    // 0x80800488: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x8080048C: srl         $t8, $v0, 22
    ctx->r24 = S32(U32(ctx->r2) >> 22);
    // 0x80800490: beq         $t8, $at, L_808004BC
    if (ctx->r24 == ctx->r1) {
        // 0x80800494: addiu       $at, $zero, 0x1D9
        ctx->r1 = ADD32(0, 0X1D9);
            goto L_808004BC;
    }
    // 0x80800494: addiu       $at, $zero, 0x1D9
    ctx->r1 = ADD32(0, 0X1D9);
    // 0x80800498: beq         $t8, $at, L_808004AC
    if (ctx->r24 == ctx->r1) {
        // 0x8080049C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808004AC;
    }
    // 0x8080049C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004A0: addiu       $at, $zero, 0x1DA
    ctx->r1 = ADD32(0, 0X1DA);
    // 0x808004A4: bne         $t8, $at, L_80800514
    if (ctx->r24 != ctx->r1) {
        // 0x808004A8: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800514;
    }
    // 0x808004A8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_808004AC:
    // 0x808004AC: jal         0x80800670
    // 0x808004B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800670_chnests(rdram, ctx);
        goto after_1;
    // 0x808004B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808004B4: b           L_80800660
    // 0x808004B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x808004B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004BC:
    // 0x808004BC: lhu         $a0, 0x1A($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X1A);
    // 0x808004C0: lw          $a2, 0x48($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X48);
    // 0x808004C4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x808004C8: srl         $t0, $a0, 5
    ctx->r8 = S32(U32(ctx->r4) >> 5);
    // 0x808004CC: jal         0x800F7C0C
    // 0x808004D0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800F7C0C(rdram, ctx);
        goto after_2;
    // 0x808004D0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
    // 0x808004D4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808004D8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808004DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808004E0: lhu         $t1, 0x76($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X76);
    // 0x808004E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004E8: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x808004EC: bne         $t2, $at, L_80800504
    if (ctx->r10 != ctx->r1) {
        // 0x808004F0: nop
    
            goto L_80800504;
    }
    // 0x808004F0: nop

    // 0x808004F4: jal         0x808001F0
    // 0x808004F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808001F0_chnests(rdram, ctx);
        goto after_3;
    // 0x808004F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x808004FC: b           L_80800660
    // 0x80800500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x80800500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800504:
    // 0x80800504: jal         0x80800324
    // 0x80800508: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800324_chnests(rdram, ctx);
        goto after_4;
    // 0x80800508: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x8080050C: b           L_80800660
    // 0x80800510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x80800510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800514:
    // 0x80800514: jal         0x808001F0
    // 0x80800518: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808001F0_chnests(rdram, ctx);
        goto after_5;
    // 0x80800518: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
    // 0x8080051C: b           L_80800660
    // 0x80800520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x80800520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800524:
    // 0x80800524: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800528: jal         0x80801014
    // 0x8080052C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80801014_chnests(rdram, ctx);
        goto after_6;
    // 0x8080052C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_6:
    // 0x80800530: beq         $v0, $zero, L_8080054C
    if (ctx->r2 == 0) {
        // 0x80800534: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_8080054C;
    }
    // 0x80800534: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800538: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080053C: jal         0x8080093C
    // 0x80800540: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8080093C_chnests(rdram, ctx);
        goto after_7;
    // 0x80800540: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800544: b           L_80800660
    // 0x80800548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x80800548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080054C:
    // 0x8080054C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800550: jal         0x808010A0
    // 0x80800554: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_808010A0_chnests(rdram, ctx);
        goto after_8;
    // 0x80800554: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_8:
    // 0x80800558: beq         $v0, $zero, L_8080065C
    if (ctx->r2 == 0) {
        // 0x8080055C: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_8080065C;
    }
    // 0x8080055C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800560: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800564: jal         0x808009D4
    // 0x80800568: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_808009D4_chnests(rdram, ctx);
        goto after_9;
    // 0x80800568: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_9:
    // 0x8080056C: b           L_80800660
    // 0x80800570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x80800570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800574: lw          $v0, 0x6C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X6C);
L_80800578:
    // 0x80800578: addiu       $at, $zero, 0x1E9
    ctx->r1 = ADD32(0, 0X1E9);
    // 0x8080057C: sll         $t3, $v0, 11
    ctx->r11 = S32(ctx->r2 << 11);
    // 0x80800580: srl         $t4, $t3, 20
    ctx->r12 = S32(U32(ctx->r11) >> 20);
    // 0x80800584: beq         $t4, $at, L_808005A4
    if (ctx->r12 == ctx->r1) {
        // 0x80800588: addiu       $at, $zero, 0x4A6
        ctx->r1 = ADD32(0, 0X4A6);
            goto L_808005A4;
    }
    // 0x80800588: addiu       $at, $zero, 0x4A6
    ctx->r1 = ADD32(0, 0X4A6);
    // 0x8080058C: beq         $t4, $at, L_808005A4
    if (ctx->r12 == ctx->r1) {
        // 0x80800590: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808005A4;
    }
    // 0x80800590: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800598: jal         0x80103110
    // 0x8080059C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80103110(rdram, ctx);
        goto after_10;
    // 0x8080059C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_10:
    // 0x808005A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_808005A4:
    // 0x808005A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808005A8: jal         0x80109EEC
    // 0x808005AC: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_80109EEC(rdram, ctx);
        goto after_11;
    // 0x808005AC: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_11:
    // 0x808005B0: b           L_80800660
    // 0x808005B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x808005B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B8:
    // 0x808005B8: jal         0x80801014
    // 0x808005BC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80801014_chnests(rdram, ctx);
        goto after_12;
    // 0x808005BC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_12:
    // 0x808005C0: beq         $v0, $zero, L_808005D8
    if (ctx->r2 == 0) {
        // 0x808005C4: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_808005D8;
    }
    // 0x808005C4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808005C8: jal         0x8010DC50
    // 0x808005CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8010DC50(rdram, ctx);
        goto after_13;
    // 0x808005CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x808005D0: b           L_80800660
    // 0x808005D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x808005D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005D8:
    // 0x808005D8: jal         0x808010A0
    // 0x808005DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808010A0_chnests(rdram, ctx);
        goto after_14;
    // 0x808005DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_14:
    // 0x808005E0: beql        $v0, $zero, L_80800660
    if (ctx->r2 == 0) {
        // 0x808005E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800660;
    }
    goto skip_1;
    // 0x808005E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808005E8: jal         0x8010DC50
    // 0x808005EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8010DC50(rdram, ctx);
        goto after_15;
    // 0x808005EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x808005F0: b           L_80800660
    // 0x808005F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x808005F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F8:
    // 0x808005F8: jal         0x80801014
    // 0x808005FC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80801014_chnests(rdram, ctx);
        goto after_16;
    // 0x808005FC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_16:
    // 0x80800600: beq         $v0, $zero, L_80800618
    if (ctx->r2 == 0) {
        // 0x80800604: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800618;
    }
    // 0x80800604: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800608: jal         0x8010DCB4
    // 0x8080060C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8010DCB4(rdram, ctx);
        goto after_17;
    // 0x8080060C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x80800610: b           L_80800660
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800618:
    // 0x80800618: jal         0x808010A0
    // 0x8080061C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808010A0_chnests(rdram, ctx);
        goto after_18;
    // 0x8080061C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_18:
    // 0x80800620: beql        $v0, $zero, L_80800660
    if (ctx->r2 == 0) {
        // 0x80800624: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800660;
    }
    goto skip_2;
    // 0x80800624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800628: jal         0x8010DCB4
    // 0x8080062C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8010DCB4(rdram, ctx);
        goto after_19;
    // 0x8080062C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x80800630: b           L_80800660
    // 0x80800634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x80800634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800638:
    // 0x80800638: jal         0x8080034C
    // 0x8080063C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8080034C_chnests(rdram, ctx);
        goto after_20;
    // 0x8080063C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_20:
    // 0x80800640: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800644: jal         0x80101FDC
    // 0x80800648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_21;
    // 0x80800648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x8080064C: b           L_80800660
    // 0x80800650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800660;
    // 0x80800650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800654: b           L_80800660
    // 0x80800658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800660;
    // 0x80800658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080065C:
    // 0x8080065C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800660:
    // 0x80800660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800664: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800668: jr          $ra
    // 0x8080066C: nop

    return;
    // 0x8080066C: nop

;}
RECOMP_FUNC void func_808013E4_subaddiedialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013E8: andi        $t6, $a1, 0x40
    ctx->r14 = ctx->r5 & 0X40;
    // 0x808013EC: beq         $t6, $zero, L_80801404
    if (ctx->r14 == 0) {
        // 0x808013F0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80801404;
    }
    // 0x808013F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013F4: lbu         $t8, 0x74($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X74);
    // 0x808013F8: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x808013FC: b           L_8080140C
    // 0x80801400: sb          $t9, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r25;
        goto L_8080140C;
    // 0x80801400: sb          $t9, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r25;
L_80801404:
    // 0x80801404: jal         0x800DA544
    // 0x80801408: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80801408: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
L_8080140C:
    // 0x8080140C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801414: jr          $ra
    // 0x80801418: nop

    return;
    // 0x80801418: nop

;}
RECOMP_FUNC void func_808073AC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808073AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808073B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808073B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808073B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808073BC: jal         0x80106790
    // 0x808073C0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808073C0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808073C4: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x808073C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808073CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808073D0: jal         0x80100094
    // 0x808073D4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808073D4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_1:
    // 0x808073D8: jal         0x800AA0D0
    // 0x808073DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_800AA0D0(rdram, ctx);
        goto after_2;
    // 0x808073DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_2:
    // 0x808073E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808073E4: bne         $v0, $at, L_8080741C
    if (ctx->r2 != ctx->r1) {
        // 0x808073E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080741C;
    }
    // 0x808073E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808073EC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x808073F0: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x808073F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808073F8: addiu       $a1, $a1, -0x5E80
    ctx->r5 = ADD32(ctx->r5, -0X5E80);
    // 0x808073FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80807404: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x80807408: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8080740C: jal         0x8080714C
    // 0x80807410: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_8080714C_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80807410: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_3:
    // 0x80807414: b           L_80807444
    // 0x80807418: nop

        goto L_80807444;
    // 0x80807418: nop

L_8080741C:
    // 0x8080741C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80807420: addiu       $t8, $zero, 0x21
    ctx->r24 = ADD32(0, 0X21);
    // 0x80807424: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80807428: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8080742C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80807430: addiu       $a1, $a1, -0x5E80
    ctx->r5 = ADD32(ctx->r5, -0X5E80);
    // 0x80807434: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80807438: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8080743C: jal         0x8080714C
    // 0x80807440: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_8080714C_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80807440: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_4:
L_80807444:
    // 0x80807444: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(804, 0X8570) << 16);
    // 0x80807448: addiu       $a2, $a2, -0x7A90
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(804, 0X8570));
    // 0x8080744C: addiu       $t0, $zero, 0x18E4
    ctx->r8 = ADD32(0, 0X18E4);
    // 0x80807450: jal         0x800AA148
    // 0x80807454: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    func_800AA148(rdram, ctx);
        goto after_5;
    // 0x80807454: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    after_5:
    // 0x80807458: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080745C: jal         0x80088158
    // 0x80807460: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80807460: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80807464: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80807468: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(804, 0X8570) << 16);
    // 0x8080746C: addiu       $a2, $a2, -0x7A90
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(804, 0X8570));
    // 0x80807470: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80807474: addiu       $t3, $zero, 0x18F3
    ctx->r11 = ADD32(0, 0X18F3);
    // 0x80807478: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8080747C: subu        $t2, $t1, $v0
    ctx->r10 = SUB32(ctx->r9, ctx->r2);
    // 0x80807480: sh          $t2, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r10;
    // 0x80807484: sh          $t3, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r11;
    // 0x80807488: sh          $t4, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r12;
    // 0x8080748C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80807490: jal         0x80803F90
    // 0x80807494: lw          $a0, 0x20($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X20);
    func_80803F90_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80807494: lw          $a0, 0x20($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X20);
    after_7:
    // 0x80807498: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8080749C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808074A0: jal         0x80802730
    // 0x808074A4: lw          $a1, 0x20($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X20);
    func_80802730_chgameselect(rdram, ctx);
        goto after_8;
    // 0x808074A4: lw          $a1, 0x20($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X20);
    after_8:
    // 0x808074A8: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808074AC: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x808074B0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x808074B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808074B8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808074BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808074C0: jr          $ra
    // 0x808074C4: nop

    return;
    // 0x808074C4: nop

;}
RECOMP_FUNC void func_80800630_chboxingglove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800634: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800638: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080063C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800640: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800644: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800648: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080064C: jal         0x80100094
    // 0x80800650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800654: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800658: addiu       $a0, $zero, 0x34D
    ctx->r4 = ADD32(0, 0X34D);
    // 0x8080065C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800660: jal         0x80089C40
    // 0x80800664: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800664: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80800668: blez        $v0, L_808006B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080066C: lw          $s1, 0x3C($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X3C);
            goto L_808006B4;
    }
    // 0x8080066C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800670: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800674: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x80800678: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8080067C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800680: addu        $s3, $t7, $s0
    ctx->r19 = ADD32(ctx->r15, ctx->r16);
L_80800684:
    // 0x80800684: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080068C: jal         0x800EE7F8
    // 0x80800690: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800690: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800694: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80800698: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080069C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x808006A0: lwc1        $f4, 0x38($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X38);
    // 0x808006A4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808006A8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808006AC: bne         $at, $zero, L_80800684
    if (ctx->r1 != 0) {
        // 0x808006B0: swc1        $f6, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f6.u32l;
            goto L_80800684;
    }
    // 0x808006B0: swc1        $f6, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f6.u32l;
L_808006B4:
    // 0x808006B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808006B8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808006BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808006C0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808006C4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808006C8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808006CC: jr          $ra
    // 0x808006D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808006D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808006D4: nop

    // 0x808006D8: nop

    // 0x808006DC: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082610: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082610);
    return;
    // 0x80082614: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void gcnewoption_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808018BC: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x808018C0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x808018C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018C8: sh          $a1, 0x236($a0)
    MEM_H(0X236, ctx->r4) = ctx->r5;
    // 0x808018CC: jal         0x80087C08
    // 0x808018D0: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    _gczoombox_entrypoint_37(rdram, ctx);
        goto after_0;
    // 0x808018D0: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    after_0:
    // 0x808018D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018DC: jr          $ra
    // 0x808018E0: nop

    return;
    // 0x808018E0: nop

;}
RECOMP_FUNC void _chstoneballcontrol_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A58: syscall     409
    recomp_syscall_handler(rdram, ctx, 0x80086A58);
    return;
    // 0x80086A5C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085690: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085690);
    return;
    // 0x80085694: addi        $t0, $zero, 0x88
    ctx->r8 = ADD32(0, 0X88);
;}
RECOMP_FUNC void _chcrusher_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AB8: syscall     413
    recomp_syscall_handler(rdram, ctx, 0x80086AB8);
    return;
    // 0x80086ABC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bashoes_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085070: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085070);
    return;
    // 0x80085074: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_808012D0_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808012D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808012DC: jal         0x8010D600
    // 0x808012E0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D600(rdram, ctx);
        goto after_0;
    // 0x808012E0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808012E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808012E8: jal         0x80102D78
    // 0x808012EC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x808012EC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x808012F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808012F4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808012F8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808012FC: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80801300: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    // 0x80801304: jal         0x80102BF8
    // 0x80801308: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102BF8(rdram, ctx);
        goto after_2;
    // 0x80801308: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x8080130C: jal         0x808012C8
    // 0x80801310: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808012C8_chwaspnestgame(rdram, ctx);
        goto after_3;
    // 0x80801310: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80801314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801318: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080131C: jr          $ra
    // 0x80801320: nop

    return;
    // 0x80801320: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X1630) << 16);
    // 0x808005E4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005E8: jr          $ra
    // 0x808005EC: lw          $v0, 0x1630($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1630));
    return;
    // 0x808005EC: lw          $v0, 0x1630($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1630));
;}
RECOMP_FUNC void func_80800714_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800714: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080071C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800720: jal         0x80084800
    // 0x80800724: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _badrone_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800724: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800728: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080072C: bne         $v0, $at, L_8080074C
    if (ctx->r2 != ctx->r1) {
        // 0x80800730: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080074C;
    }
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: jal         0x80084CC8
    // 0x80800738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafpctrl_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800740: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800744: jal         0x800947EC
    // 0x80800748: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_2;
    // 0x80800748: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_8080074C:
    // 0x8080074C: jal         0x808000F0
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000F0_bswasher(rdram, ctx);
        goto after_3;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800754: jal         0x80082FF0
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080075C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800760: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800764: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800768: jr          $ra
    // 0x8080076C: nop

    return;
    // 0x8080076C: nop

;}
RECOMP_FUNC void func_808079D0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808079D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808079D4: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x808079D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808079DC: bne         $a1, $at, L_808079F8
    if (ctx->r5 != ctx->r1) {
        // 0x808079E0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808079F8;
    }
    // 0x808079E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808079E4: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    // 0x808079E8: jal         0x80807A10
    // 0x808079EC: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    func_80807A10_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808079EC: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    after_0:
    // 0x808079F0: b           L_80807A00
    // 0x808079F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80807A00;
    // 0x808079F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808079F8:
    // 0x808079F8: b           L_80807A00
    // 0x808079FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80807A00;
    // 0x808079FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80807A00:
    // 0x80807A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807A08: jr          $ra
    // 0x80807A0C: nop

    return;
    // 0x80807A0C: nop

;}
RECOMP_FUNC void func_8008D304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D30C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D310: jal         0x80095748
    // 0x8008D314: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baflag_isFalse(rdram, ctx);
        goto after_0;
    // 0x8008D314: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_0:
    // 0x8008D318: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D31C: beq         $t6, $zero, L_8008D360
    if (ctx->r14 == 0) {
        // 0x8008D320: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D360;
    }
    // 0x8008D320: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D324: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D328: jal         0x80095748
    // 0x8008D32C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_isFalse(rdram, ctx);
        goto after_1;
    // 0x8008D32C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x8008D330: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D334: beq         $t7, $zero, L_8008D360
    if (ctx->r15 == 0) {
        // 0x8008D338: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8008D360;
    }
    // 0x8008D338: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8008D33C: jal         0x800C6E38
    // 0x8008D340: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x8008D340: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x8008D344: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D348: beq         $t8, $zero, L_8008D360
    if (ctx->r24 == 0) {
        // 0x8008D34C: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8008D360;
    }
    // 0x8008D34C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8008D350: jal         0x800A3304
    // 0x8008D354: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_3;
    // 0x8008D354: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8008D358: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D35C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8008D360:
    // 0x8008D360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D368: jr          $ra
    // 0x8008D36C: nop

    return;
    // 0x8008D36C: nop

;}
RECOMP_FUNC void gcdialogexec_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D7C: jal         0x80800A50
    // 0x80801D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x80801D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80801D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D8C: jr          $ra
    // 0x80801D90: nop

    return;
    // 0x80801D90: nop

;}
RECOMP_FUNC void func_8009CD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CD70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CD74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CD78: lw          $v0, 0xF0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CD7C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009CD80: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8009CD84: lbu         $t7, 0x80($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X80);
    // 0x8009CD88: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8009CD8C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8009CD90: beq         $a1, $zero, L_8009CDB8
    if (ctx->r5 == 0) {
        // 0x8009CD94: sb          $t6, -0xF($t9)
        MEM_B(-0XF, ctx->r25) = ctx->r14;
            goto L_8009CDB8;
    }
    // 0x8009CD94: sb          $t6, -0xF($t9)
    MEM_B(-0XF, ctx->r25) = ctx->r14;
    // 0x8009CD98: lw          $v0, 0xF0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CD9C: lbu         $t0, 0x80($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X80);
    // 0x8009CDA0: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8009CDA4: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    // 0x8009CDA8: jal         0x800EE7F8
    // 0x8009CDAC: addiu       $a0, $a0, -0xC
    ctx->r4 = ADD32(ctx->r4, -0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009CDAC: addiu       $a0, $a0, -0xC
    ctx->r4 = ADD32(ctx->r4, -0XC);
    after_0:
    // 0x8009CDB0: b           L_8009CDD4
    // 0x8009CDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009CDD4;
    // 0x8009CDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CDB8:
    // 0x8009CDB8: lw          $v0, 0xF0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XF0);
    // 0x8009CDBC: lbu         $t2, 0x80($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X80);
    // 0x8009CDC0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8009CDC4: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x8009CDC8: jal         0x800EFD24
    // 0x8009CDCC: addiu       $a0, $a0, -0xC
    ctx->r4 = ADD32(ctx->r4, -0XC);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8009CDCC: addiu       $a0, $a0, -0xC
    ctx->r4 = ADD32(ctx->r4, -0XC);
    after_1:
    // 0x8009CDD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CDD4:
    // 0x8009CDD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CDD8: jr          $ra
    // 0x8009CDDC: nop

    return;
    // 0x8009CDDC: nop

;}
RECOMP_FUNC void _bssub_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D78: syscall     93
    recomp_syscall_handler(rdram, ctx, 0x80083D78);
    return;
    // 0x80083D7C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bsstand_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B28: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B28);
    return;
    // 0x80083B2C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _sumultiscore_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899B8: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x800899B8);
    return;
    // 0x800899BC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void ncpoducam_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: jr          $ra
    // 0x8080015C: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    return;
    // 0x8080015C: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
;}
RECOMP_FUNC void bsbswim_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DE8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800DEC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1EB0) << 16);
    // 0x80800DF0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800DF4: jr          $ra
    // 0x80800DF8: lw          $v0, 0x1EB0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1EB0));
    return;
    // 0x80800DF8: lw          $v0, 0x1EB0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1EB0));
;}
