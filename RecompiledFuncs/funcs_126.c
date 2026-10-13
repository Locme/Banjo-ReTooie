#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801F10_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801F18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801F1C: jal         0x800DA298
    // 0x80801F20: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80801F20: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_0:
    // 0x80801F24: beql        $v0, $zero, L_80801F38
    if (ctx->r2 == 0) {
        // 0x80801F28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801F38;
    }
    goto skip_0;
    // 0x80801F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801F2C: jal         0x800FFAB0
    // 0x80801F30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80801F30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801F38:
    // 0x80801F38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801F3C: jr          $ra
    // 0x80801F40: nop

    return;
    // 0x80801F40: nop

;}
RECOMP_FUNC void susplinet_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800370: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80800374: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800378: lh          $t8, 0x3E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X3E);
    // 0x8080037C: jr          $ra
    // 0x80800380: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    return;
    // 0x80800380: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
;}
RECOMP_FUNC void func_8009FFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FFD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009FFDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009FFE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009FFE4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009FFE8: jal         0x8008CA4C
    // 0x8009FFEC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8008CA4C(rdram, ctx);
        goto after_0;
    // 0x8009FFEC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8009FFF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009FFF4: jal         0x8009C908
    // 0x8009FFF8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    yaw_setUpdateType(rdram, ctx);
        goto after_1;
    // 0x8009FFF8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8009FFFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A0000: jal         0x8009D2D8
    // 0x800A0004: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009D2D8(rdram, ctx);
        goto after_2;
    // 0x800A0004: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800A0008: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A000C: jal         0x8009B800
    // 0x800A0010: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_type(rdram, ctx);
        goto after_3;
    // 0x800A0010: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x800A0014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A001C: jr          $ra
    // 0x800A0020: nop

    return;
    // 0x800A0020: nop

;}
RECOMP_FUNC void func_808017DC_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017DC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808017E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808017E4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808017E8: neg.s       $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = -ctx->f12.fl;
    // 0x808017EC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808017F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017F4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808017F8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808017FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801800: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801804: jal         0x800EFA4C
    // 0x80801808: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80801808: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x8080180C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80801810: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801814: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80801818: jal         0x800EE7F8
    // 0x8080181C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080181C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80801820: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80801824: jal         0x808014BC
    // 0x80801828: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_808014BC_chwaspnestgame(rdram, ctx);
        goto after_2;
    // 0x80801828: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x8080182C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80801830: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801834: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801838: beq         $t6, $zero, L_8080186C
    if (ctx->r14 == 0) {
        // 0x8080183C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8080186C;
    }
    // 0x8080183C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801840: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80801844: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80801848: jal         0x800BEF00
    // 0x8080184C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800BEF00(rdram, ctx);
        goto after_3;
    // 0x8080184C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80801850: beql        $v0, $zero, L_80801864
    if (ctx->r2 == 0) {
        // 0x80801854: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801864;
    }
    goto skip_0;
    // 0x80801854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80801858: b           L_8080186C
    // 0x8080185C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8080186C;
    // 0x8080185C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80801860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801864:
    // 0x80801864: b           L_8080186C
    // 0x80801868: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080186C;
    // 0x80801868: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080186C:
    // 0x8080186C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801870: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801874: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801878: jr          $ra
    // 0x8080187C: nop

    return;
    // 0x8080187C: nop

;}
RECOMP_FUNC void func_80802724_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802724: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080272C: lw          $t6, 0x7C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X7C);
    // 0x80802730: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80802734: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80802738: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8080273C: beq         $t7, $zero, L_80802758
    if (ctx->r15 == 0) {
        // 0x80802740: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80802758;
    }
    // 0x80802740: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802744: jal         0x80105AE8
    // 0x80802748: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80105AE8(rdram, ctx);
        goto after_0;
    // 0x80802748: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080274C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802750: b           L_80802760
    // 0x80802754: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80802760;
    // 0x80802754: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80802758:
    // 0x80802758: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080275C: nop

L_80802760:
    // 0x80802760: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802764: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80802768: jal         0x80105AE8
    // 0x8080276C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80105AE8(rdram, ctx);
        goto after_1;
    // 0x8080276C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80802770: jal         0x800D8FF8
    // 0x80802774: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80802774: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80802778: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3818) << 16);
    // 0x8080277C: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80802780: lwc1        $f4, 0x3818($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3818));
    // 0x80802784: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802788: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8080278C: sub.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80802790: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80802794: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802798: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    // 0x8080279C: sll         $t8, $v0, 12
    ctx->r24 = S32(ctx->r2 << 12);
    // 0x808027A0: srl         $v0, $t8, 31
    ctx->r2 = S32(U32(ctx->r24) >> 31);
    // 0x808027A4: bc1f        L_808027BC
    if (!c1cs) {
        // 0x808027A8: nop
    
            goto L_808027BC;
    }
    // 0x808027A8: nop

    // 0x808027AC: jal         0x808026E0
    // 0x808027B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_3;
    // 0x808027B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x808027B4: b           L_80802970
    // 0x808027B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802970;
    // 0x808027B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808027BC:
    // 0x808027BC: beq         $v0, $zero, L_808027D0
    if (ctx->r2 == 0) {
        // 0x808027C0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1564, 0X3820) << 16);
            goto L_808027D0;
    }
    // 0x808027C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3820) << 16);
    // 0x808027C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X381C) << 16);
    // 0x808027C8: b           L_808027D4
    // 0x808027CC: lwc1        $f2, 0x381C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X381C));
        goto L_808027D4;
    // 0x808027CC: lwc1        $f2, 0x381C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X381C));
L_808027D0:
    // 0x808027D0: lwc1        $f2, 0x3820($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3820));
L_808027D4:
    // 0x808027D4: sub.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x808027D8: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x808027DC: nop

    // 0x808027E0: bc1f        L_80802870
    if (!c1cs) {
        // 0x808027E4: nop
    
            goto L_80802870;
    }
    // 0x808027E4: nop

    // 0x808027E8: beq         $v0, $zero, L_80802800
    if (ctx->r2 == 0) {
        // 0x808027EC: lui         $at, 0x4325
        ctx->r1 = S32(0X4325 << 16);
            goto L_80802800;
    }
    // 0x808027EC: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x808027F0: lui         $at, 0x4339
    ctx->r1 = S32(0X4339 << 16);
    // 0x808027F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808027F8: b           L_80802808
    // 0x808027FC: nop

        goto L_80802808;
    // 0x808027FC: nop

L_80802800:
    // 0x80802800: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802804: nop

L_80802808:
    // 0x80802808: beq         $v0, $zero, L_80802820
    if (ctx->r2 == 0) {
        // 0x8080280C: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_80802820;
    }
    // 0x8080280C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80802810: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80802814: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80802818: b           L_8080282C
    // 0x8080281C: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
        goto L_8080282C;
    // 0x8080281C: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
L_80802820:
    // 0x80802820: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80802824: nop

    // 0x80802828: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
L_8080282C:
    // 0x8080282C: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80802830: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80802834: nop

    // 0x80802838: bc1fl       L_80802970
    if (!c1cs) {
        // 0x8080283C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802970;
    }
    goto skip_0;
    // 0x8080283C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802840: beq         $v0, $zero, L_80802858
    if (ctx->r2 == 0) {
        // 0x80802844: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_80802858;
    }
    // 0x80802844: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80802848: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8080284C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80802850: b           L_80802860
    // 0x80802854: nop

        goto L_80802860;
    // 0x80802854: nop

L_80802858:
    // 0x80802858: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080285C: nop

L_80802860:
    // 0x80802860: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80802864: sub.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80802868: b           L_8080296C
    // 0x8080286C: swc1        $f18, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f18.u32l;
        goto L_8080296C;
    // 0x8080286C: swc1        $f18, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f18.u32l;
L_80802870:
    // 0x80802870: beq         $v0, $zero, L_80802884
    if (ctx->r2 == 0) {
        // 0x80802874: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1564, 0X3828) << 16);
            goto L_80802884;
    }
    // 0x80802874: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3828) << 16);
    // 0x80802878: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3824) << 16);
    // 0x8080287C: b           L_80802888
    // 0x80802880: lwc1        $f2, 0x3824($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3824));
        goto L_80802888;
    // 0x80802880: lwc1        $f2, 0x3824($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3824));
L_80802884:
    // 0x80802884: lwc1        $f2, 0x3828($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3828));
L_80802888:
    // 0x80802888: add.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8080288C: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80802890: nop

    // 0x80802894: bc1f        L_8080290C
    if (!c1cs) {
        // 0x80802898: nop
    
            goto L_8080290C;
    }
    // 0x80802898: nop

    // 0x8080289C: beq         $v0, $zero, L_808028B4
    if (ctx->r2 == 0) {
        // 0x808028A0: lui         $at, 0x4325
        ctx->r1 = S32(0X4325 << 16);
            goto L_808028B4;
    }
    // 0x808028A0: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x808028A4: lui         $at, 0x4339
    ctx->r1 = S32(0X4339 << 16);
    // 0x808028A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808028AC: b           L_808028C0
    // 0x808028B0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
        goto L_808028C0;
    // 0x808028B0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_808028B4:
    // 0x808028B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808028B8: nop

    // 0x808028BC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_808028C0:
    // 0x808028C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808028C4: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
    // 0x808028C8: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x808028CC: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x808028D0: nop

    // 0x808028D4: bc1fl       L_80802970
    if (!c1cs) {
        // 0x808028D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802970;
    }
    goto skip_1;
    // 0x808028D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808028DC: beq         $v0, $zero, L_808028F4
    if (ctx->r2 == 0) {
        // 0x808028E0: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_808028F4;
    }
    // 0x808028E0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808028E4: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x808028E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808028EC: b           L_808028FC
    // 0x808028F0: nop

        goto L_808028FC;
    // 0x808028F0: nop

L_808028F4:
    // 0x808028F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808028F8: nop

L_808028FC:
    // 0x808028FC: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80802900: add.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80802904: b           L_8080296C
    // 0x80802908: swc1        $f16, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f16.u32l;
        goto L_8080296C;
    // 0x80802908: swc1        $f16, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f16.u32l;
L_8080290C:
    // 0x8080290C: beq         $v0, $zero, L_80802924
    if (ctx->r2 == 0) {
        // 0x80802910: lui         $at, 0x4325
        ctx->r1 = S32(0X4325 << 16);
            goto L_80802924;
    }
    // 0x80802910: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x80802914: lui         $at, 0x4339
    ctx->r1 = S32(0X4339 << 16);
    // 0x80802918: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080291C: b           L_80802930
    // 0x80802920: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
        goto L_80802930;
    // 0x80802920: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
L_80802924:
    // 0x80802924: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80802928: nop

    // 0x8080292C: lwc1        $f12, 0x24($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X24);
L_80802930:
    // 0x80802930: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80802934: nop

    // 0x80802938: bc1fl       L_80802970
    if (!c1cs) {
        // 0x8080293C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802970;
    }
    goto skip_2;
    // 0x8080293C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80802940: beq         $v0, $zero, L_80802958
    if (ctx->r2 == 0) {
        // 0x80802944: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_80802958;
    }
    // 0x80802944: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80802948: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8080294C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80802950: b           L_80802960
    // 0x80802954: nop

        goto L_80802960;
    // 0x80802954: nop

L_80802958:
    // 0x80802958: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080295C: nop

L_80802960:
    // 0x80802960: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80802964: add.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x80802968: swc1        $f4, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f4.u32l;
L_8080296C:
    // 0x8080296C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802970:
    // 0x80802970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802974: jr          $ra
    // 0x80802978: nop

    return;
    // 0x80802978: nop

;}
RECOMP_FUNC void _chjinjovillagecamera1_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870F8: syscall     515
    recomp_syscall_handler(rdram, ctx, 0x800870F8);
    return;
    // 0x800870FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80091E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091E20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091E24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091E28: lw          $t6, 0x48($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X48);
    // 0x80091E2C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80091E30: jal         0x80091E48
    // 0x80091E34: sb          $zero, 0x3($t6)
    MEM_B(0X3, ctx->r14) = 0;
    func_80091E48(rdram, ctx);
        goto after_0;
    // 0x80091E34: sb          $zero, 0x3($t6)
    MEM_B(0X3, ctx->r14) = 0;
    after_0:
    // 0x80091E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091E3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091E40: jr          $ra
    // 0x80091E44: nop

    return;
    // 0x80091E44: nop

;}
RECOMP_FUNC void func_80800404_chtimetable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800404: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800408: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080040C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800410: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80800414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800418: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8080041C: bltzl       $t8, L_80800570
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800420: lhu         $t5, 0x72($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X72);
            goto L_80800570;
    }
    goto skip_0;
    // 0x80800420: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800424: jal         0x8010D254
    // 0x80800428: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800428: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x8080042C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800430: lui         $a1, 0xC3FA
    ctx->r5 = S32(0XC3FA << 16);
    // 0x80800434: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800438: jal         0x800EFA4C
    // 0x8080043C: lui         $a3, 0xC42F
    ctx->r7 = S32(0XC42F << 16);
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x8080043C: lui         $a3, 0xC42F
    ctx->r7 = S32(0XC42F << 16);
    after_1:
    // 0x80800440: lui         $a2, 0x44BB
    ctx->r6 = S32(0X44BB << 16);
    // 0x80800444: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80800448: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080044C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800450: jal         0x800EFA4C
    // 0x80800454: lui         $a3, 0x442F
    ctx->r7 = S32(0X442F << 16);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80800454: lui         $a3, 0x442F
    ctx->r7 = S32(0X442F << 16);
    after_2:
    // 0x80800458: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x8080045C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800460: jal         0x800EF04C
    // 0x80800464: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80800464: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80800468: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080046C: jal         0x800EF04C
    // 0x80800470: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80800470: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800474: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800478: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080047C: jal         0x800EFED0
    // 0x80800480: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800EFED0(rdram, ctx);
        goto after_5;
    // 0x80800480: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x80800484: beql        $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x80800488: lbu         $t5, 0x65($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X65);
            goto L_808004C0;
    }
    goto skip_1;
    // 0x80800488: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    skip_1:
    // 0x8080048C: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: addiu       $a1, $zero, 0xD07
    ctx->r5 = ADD32(0, 0XD07);
    // 0x80800498: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x8080049C: bltzl       $t1, L_808004CC
    if (SIGNED(ctx->r9) < 0) {
        // 0x808004A0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_808004CC;
    }
    goto skip_2;
    // 0x808004A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_2:
    // 0x808004A4: jal         0x80800364
    // 0x808004A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800364_chtimetable(rdram, ctx);
        goto after_6;
    // 0x808004A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x808004AC: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808004B0: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x808004B4: b           L_808004C8
    // 0x808004B8: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
        goto L_808004C8;
    // 0x808004B8: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x808004BC: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
L_808004C0:
    // 0x808004C0: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x808004C4: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
L_808004C8:
    // 0x808004C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808004CC:
    // 0x808004CC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808004D0: lui         $a3, 0xC42F
    ctx->r7 = S32(0XC42F << 16);
    // 0x808004D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004DC: jal         0x800EFA4C
    // 0x808004E0: nop

    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x808004E0: nop

    after_7:
    // 0x808004E4: lui         $a2, 0x44BB
    ctx->r6 = S32(0X44BB << 16);
    // 0x808004E8: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x808004EC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808004F0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808004F4: jal         0x800EFA4C
    // 0x808004F8: lui         $a3, 0x442F
    ctx->r7 = S32(0X442F << 16);
    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x808004F8: lui         $a3, 0x442F
    ctx->r7 = S32(0X442F << 16);
    after_8:
    // 0x808004FC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800500: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800504: jal         0x800EF04C
    // 0x80800508: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x80800508: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x8080050C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800510: jal         0x800EF04C
    // 0x80800514: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x80800514: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_10:
    // 0x80800518: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8080051C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800520: jal         0x800EFED0
    // 0x80800524: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800EFED0(rdram, ctx);
        goto after_11;
    // 0x80800524: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x80800528: beql        $v0, $zero, L_80800564
    if (ctx->r2 == 0) {
        // 0x8080052C: lbu         $t3, 0x65($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X65);
            goto L_80800564;
    }
    goto skip_3;
    // 0x8080052C: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    skip_3:
    // 0x80800530: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: addiu       $a1, $zero, 0xD07
    ctx->r5 = ADD32(0, 0XD07);
    // 0x8080053C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80800540: bltzl       $t9, L_80800570
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800544: lhu         $t5, 0x72($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X72);
            goto L_80800570;
    }
    goto skip_4;
    // 0x80800544: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
    skip_4:
    // 0x80800548: jal         0x80800364
    // 0x8080054C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800364_chtimetable(rdram, ctx);
        goto after_12;
    // 0x8080054C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80800550: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800554: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80800558: b           L_8080056C
    // 0x8080055C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_8080056C;
    // 0x8080055C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x80800560: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
L_80800564:
    // 0x80800564: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x80800568: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_8080056C:
    // 0x8080056C: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
L_80800570:
    // 0x80800570: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800574: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800578: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x8080057C: bne         $t6, $at, L_808005A4
    if (ctx->r14 != ctx->r1) {
        // 0x80800580: addiu       $a1, $zero, 0xFA
        ctx->r5 = ADD32(0, 0XFA);
            goto L_808005A4;
    }
    // 0x80800580: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x80800584: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x80800588: jal         0x8008A1D8
    // 0x8080058C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x8080058C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x80800590: beq         $v0, $zero, L_808005A4
    if (ctx->r2 == 0) {
        // 0x80800594: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005A4;
    }
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080059C: jal         0x80800364
    // 0x808005A0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_80800364_chtimetable(rdram, ctx);
        goto after_14;
    // 0x808005A0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_14:
L_808005A4:
    // 0x808005A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808005B0: jr          $ra
    // 0x808005B4: nop

    return;
    // 0x808005B4: nop

;}
RECOMP_FUNC void func_800CE59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE59C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800CE5A0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CE5A4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800CE5A8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800CE5AC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800CE5B0: beq         $a1, $zero, L_800CE5CC
    if (ctx->r5 == 0) {
        // 0x800CE5B4: lhu         $v0, -0x55CC($v0)
        ctx->r2 = MEM_HU(ctx->r2, -0X55CC);
            goto L_800CE5CC;
    }
    // 0x800CE5B4: lhu         $v0, -0x55CC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X55CC);
    // 0x800CE5B8: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x800CE5BC: beq         $t7, $zero, L_800CE5CC
    if (ctx->r15 == 0) {
        // 0x800CE5C0: nop
    
            goto L_800CE5CC;
    }
    // 0x800CE5C0: nop

    // 0x800CE5C4: jr          $ra
    // 0x800CE5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE5CC:
    // 0x800CE5CC: beq         $a2, $zero, L_800CE5E4
    if (ctx->r6 == 0) {
        // 0x800CE5D0: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_800CE5E4;
    }
    // 0x800CE5D0: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800CE5D4: beq         $t8, $zero, L_800CE5E4
    if (ctx->r24 == 0) {
        // 0x800CE5D8: nop
    
            goto L_800CE5E4;
    }
    // 0x800CE5D8: nop

    // 0x800CE5DC: jr          $ra
    // 0x800CE5E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE5E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE5E4:
    // 0x800CE5E4: beq         $a3, $zero, L_800CE5FC
    if (ctx->r7 == 0) {
        // 0x800CE5E8: andi        $t9, $v0, 0x2
        ctx->r25 = ctx->r2 & 0X2;
            goto L_800CE5FC;
    }
    // 0x800CE5E8: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x800CE5EC: beql        $t9, $zero, L_800CE600
    if (ctx->r25 == 0) {
        // 0x800CE5F0: lw          $t0, 0x10($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X10);
            goto L_800CE600;
    }
    goto skip_0;
    // 0x800CE5F0: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    skip_0:
    // 0x800CE5F4: jr          $ra
    // 0x800CE5F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE5F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE5FC:
    // 0x800CE5FC: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
L_800CE600:
    // 0x800CE600: andi        $t1, $v0, 0x8
    ctx->r9 = ctx->r2 & 0X8;
    // 0x800CE604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CE608: beq         $t0, $zero, L_800CE620
    if (ctx->r8 == 0) {
        // 0x800CE60C: nop
    
            goto L_800CE620;
    }
    // 0x800CE60C: nop

    // 0x800CE610: beq         $t1, $zero, L_800CE620
    if (ctx->r9 == 0) {
        // 0x800CE614: nop
    
            goto L_800CE620;
    }
    // 0x800CE614: nop

    // 0x800CE618: jr          $ra
    // 0x800CE61C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE61C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE620:
    // 0x800CE620: jr          $ra
    // 0x800CE624: nop

    return;
    // 0x800CE624: nop

;}
RECOMP_FUNC void func_80800C8C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C8C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800C90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800C94: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x80800C98: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x80800C9C: lbu         $a3, 0x0($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X0);
    // 0x80800CA0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_80800CA4:
    // 0x80800CA4: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800CA8: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80800CAC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80800CB0: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80800CB4: lbu         $a2, 0x0($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X0);
    // 0x80800CB8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80800CBC: mflo        $t7
    ctx->r15 = lo;
    // 0x80800CC0: addu        $v1, $a3, $t7
    ctx->r3 = ADD32(ctx->r7, ctx->r15);
    // 0x80800CC4: addiu       $v1, $v1, -0x30
    ctx->r3 = ADD32(ctx->r3, -0X30);
    // 0x80800CC8: beq         $t1, $a2, L_80800CD8
    if (ctx->r9 == ctx->r6) {
        // 0x80800CCC: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80800CD8;
    }
    // 0x80800CCC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800CD0: bne         $a2, $zero, L_80800CA4
    if (ctx->r6 != 0) {
        // 0x80800CD4: nop
    
            goto L_80800CA4;
    }
    // 0x80800CD4: nop

L_80800CD8:
    // 0x80800CD8: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80800CDC: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80800CE0: jr          $ra
    // 0x80800CE4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x80800CE4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
;}
RECOMP_FUNC void ncbafixpos_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x80800014: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080001C: jal         0x801124D0
    // 0x80800020: sb          $t6, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = ctx->r14;
    func_801124D0(rdram, ctx);
        goto after_0;
    // 0x80800020: sb          $t6, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = ctx->r14;
    after_0:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void chpufferfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2240, 0X12A8) << 16);
    // 0x80801100: jr          $ra
    // 0x80801104: addiu       $v0, $v0, 0x12A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2240, 0X12A8));
    return;
    // 0x80801104: addiu       $v0, $v0, 0x12A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2240, 0X12A8));
    // 0x80801108: nop

    // 0x8080110C: nop

;}
RECOMP_FUNC void func_808000CC_chlavaentrydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000D8: jal         0x8008A738
    // 0x808000DC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    _sujiggy_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808000DC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x808000E0: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x808000E4: nop
    
            goto L_80800100;
    }
    // 0x808000E4: nop

    // 0x808000E8: jal         0x800DA544
    // 0x808000EC: addiu       $a0, $zero, 0x398
    ctx->r4 = ADD32(0, 0X398);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808000EC: addiu       $a0, $zero, 0x398
    ctx->r4 = ADD32(0, 0X398);
    after_1:
    // 0x808000F0: jal         0x800FFAB0
    // 0x808000F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808000F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808000F8: b           L_8080012C
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080012C;
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800100:
    // 0x80800100: jal         0x800D3E40
    // 0x80800104: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_3;
    // 0x80800104: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_3:
    // 0x80800108: beql        $v0, $zero, L_8080012C
    if (ctx->r2 == 0) {
        // 0x8080010C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080012C;
    }
    goto skip_0;
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800110: jal         0x80088840
    // 0x80800114: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800114: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_4:
    // 0x80800118: bnel        $v0, $zero, L_8080012C
    if (ctx->r2 != 0) {
        // 0x8080011C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080012C;
    }
    goto skip_1;
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800120: jal         0x800FFAB0
    // 0x80800124: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800124: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80800128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080012C:
    // 0x8080012C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800130: jr          $ra
    // 0x80800134: nop

    return;
    // 0x80800134: nop

;}
RECOMP_FUNC void func_800F1884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F188C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800F1890: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1894: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F1898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F189C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F18A0: nop

    // 0x800F18A4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F18A8: jal         0x8002DCA0
    // 0x800F18AC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F18AC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800F18B0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F18B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800F18B8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x800F18BC: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800F18C0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800F18C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F18C8: bc1f        L_800F18D8
    if (!c1cs) {
        // 0x800F18CC: nop
    
            goto L_800F18D8;
    }
    // 0x800F18CC: nop

    // 0x800F18D0: b           L_800F18EC
    // 0x800F18D4: swc1        $f2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f2.u32l;
        goto L_800F18EC;
    // 0x800F18D4: swc1        $f2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f2.u32l;
L_800F18D8:
    // 0x800F18D8: jal         0x80013B7C
    // 0x800F18DC: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    func_80013B7C(rdram, ctx);
        goto after_1;
    // 0x800F18DC: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    after_1:
    // 0x800F18E0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800F18E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F18E8: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
L_800F18EC:
    // 0x800F18EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F18F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F18F4: jr          $ra
    // 0x800F18F8: nop

    return;
    // 0x800F18F8: nop

;}
RECOMP_FUNC void func_8080145C_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080145C: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80801460: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801464: lui         $t7, 0x2000
    ctx->r15 = S32(0X2000 << 16);
    // 0x80801468: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x8080146C: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x80801470: beq         $v0, $zero, L_80801494
    if (ctx->r2 == 0) {
        // 0x80801474: sw          $v0, 0x2C($a0)
        MEM_W(0X2C, ctx->r4) = ctx->r2;
            goto L_80801494;
    }
    // 0x80801474: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // 0x80801478: beq         $v0, $at, L_8080149C
    if (ctx->r2 == ctx->r1) {
        // 0x8080147C: lui         $t8, 0x1000
        ctx->r24 = S32(0X1000 << 16);
            goto L_8080149C;
    }
    // 0x8080147C: lui         $t8, 0x1000
    ctx->r24 = S32(0X1000 << 16);
    // 0x80801480: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801484: beq         $v0, $at, L_808014A4
    if (ctx->r2 == ctx->r1) {
        // 0x80801488: lui         $t9, 0x800
        ctx->r25 = S32(0X800 << 16);
            goto L_808014A4;
    }
    // 0x80801488: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8080148C: jr          $ra
    // 0x80801490: nop

    return;
    // 0x80801490: nop

L_80801494:
    // 0x80801494: jr          $ra
    // 0x80801498: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    return;
    // 0x80801498: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
L_8080149C:
    // 0x8080149C: jr          $ra
    // 0x808014A0: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    return;
    // 0x808014A0: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
L_808014A4:
    // 0x808014A4: sw          $t9, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r25;
    // 0x808014A8: jr          $ra
    // 0x808014AC: nop

    return;
    // 0x808014AC: nop

;}
RECOMP_FUNC void babee_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800064: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800068: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080006C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800070: jal         0x800F53D0
    // 0x80800074: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80800074: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800078: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080007C: lw          $s1, 0x1C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X1C);
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800084: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80800088: jal         0x80092CDC
    // 0x8080008C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80092CDC(rdram, ctx);
        goto after_1;
    // 0x8080008C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80800090: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800094: jal         0x80092EB0
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092EB0(rdram, ctx);
        goto after_2;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080009C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x808000A8: beq         $t6, $zero, L_80800140
    if (ctx->r14 == 0) {
        // 0x808000AC: nop
    
            goto L_80800140;
    }
    // 0x808000AC: nop

    // 0x808000B0: beq         $v0, $zero, L_80800140
    if (ctx->r2 == 0) {
        // 0x808000B4: nop
    
            goto L_80800140;
    }
    // 0x808000B4: nop

    // 0x808000B8: jal         0x8008E078
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000C0: beq         $v0, $zero, L_808000D4
    if (ctx->r2 == 0) {
        // 0x808000C4: nop
    
            goto L_808000D4;
    }
    // 0x808000C4: nop

    // 0x808000C8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808000CC: b           L_808000E4
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808000E4;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000D4:
    // 0x808000D4: jal         0x8009BFCC
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFCC(rdram, ctx);
        goto after_4;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000DC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000E4:
    // 0x808000E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808000E8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x808000EC: jal         0x800F3BD0
    // 0x808000F0: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_800F3BD0(rdram, ctx);
        goto after_5;
    // 0x808000F0: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x808000F4: jal         0x8009C984
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_6;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000FC: lbu         $t7, 0x1C($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1C);
    // 0x80800100: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800104: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800108: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8080010C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800110: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800114: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80800118: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080011C: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x80800120: jal         0x800EEC30
    // 0x80800124: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EEC30(rdram, ctx);
        goto after_7;
    // 0x80800124: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_7:
    // 0x80800128: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8080012C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800130: jal         0x80800008
    // 0x80800134: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_80800008_babee(rdram, ctx);
        goto after_8;
    // 0x80800134: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x80800138: b           L_808001A0
    // 0x8080013C: lbu         $t3, 0x1C($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X1C);
        goto L_808001A0;
    // 0x8080013C: lbu         $t3, 0x1C($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X1C);
L_80800140:
    // 0x80800140: jal         0x80084B28
    // 0x80800144: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    _baeggfire_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800144: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_9:
    // 0x80800148: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8080014C: jal         0x800EF368
    // 0x80800150: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_800EF368(rdram, ctx);
        goto after_10;
    // 0x80800150: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_10:
    // 0x80800154: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800158: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8080015C: jal         0x800EE780
    // 0x80800160: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800EE780(rdram, ctx);
        goto after_11;
    // 0x80800160: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_11:
    // 0x80800164: lbu         $t0, 0x1C($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1C);
    // 0x80800168: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8080016C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800170: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80800174: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800178: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x8080017C: jal         0x800EF368
    // 0x80800180: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    func_800EF368(rdram, ctx);
        goto after_12;
    // 0x80800180: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    after_12:
    // 0x80800184: jal         0x80084AF0
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggcursor_entrypoint_8(rdram, ctx);
        goto after_13;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080018C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800190: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800194: jal         0x80800008
    // 0x80800198: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_80800008_babee(rdram, ctx);
        goto after_14;
    // 0x80800198: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_14:
    // 0x8080019C: lbu         $t3, 0x1C($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X1C);
L_808001A0:
    // 0x808001A0: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x808001A4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808001A8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x808001AC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x808001B0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x808001B4: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x808001B8: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x808001BC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x808001C0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x808001C4: jal         0x800872C0
    // 0x808001C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    _chstinger_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x808001C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_15:
    // 0x808001CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001D0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808001D8: jr          $ra
    // 0x808001DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808001DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void suquiz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800234: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800238: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080023C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800240: jal         0x800D9004
    // 0x80800244: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x80800244: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800248: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3370, 0X10E0) << 16);
    // 0x8080024C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80800250: addiu       $t7, $t7, 0x10E0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3370, 0X10E0));
    // 0x80800254: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800258: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8080025C: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x80800260: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800264: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800268: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8080026C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800270: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80800274: addiu       $s2, $s2, 0x7614
    ctx->r18 = ADD32(ctx->r18, 0X7614);
    // 0x80800278: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x8080027C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800280: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80800284: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800288: beql        $v0, $zero, L_80800480
    if (ctx->r2 == 0) {
        // 0x8080028C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800480;
    }
    goto skip_0;
    // 0x8080028C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800290: jal         0x800D3948
    // 0x80800294: lbu         $s0, 0x24($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X24);
    func_800D3948(rdram, ctx);
        goto after_1;
    // 0x80800294: lbu         $s0, 0x24($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X24);
    after_1:
    // 0x80800298: beq         $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x8080029C: sltu        $v1, $zero, $s0
        ctx->r3 = 0 < ctx->r16 ? 1 : 0;
            goto L_808002D8;
    }
    // 0x8080029C: sltu        $v1, $zero, $s0
    ctx->r3 = 0 < ctx->r16 ? 1 : 0;
    // 0x808002A0: beql        $v1, $zero, L_808002D8
    if (ctx->r3 == 0) {
        // 0x808002A4: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_808002D8;
    }
    goto skip_1;
    // 0x808002A4: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    skip_1:
    // 0x808002A8: jal         0x80088398
    // 0x808002AC: nop

    _gcstatusDll_entrypoint_17(rdram, ctx);
        goto after_2;
    // 0x808002AC: nop

    after_2:
    // 0x808002B0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x808002B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808002BC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808002C0: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x808002C4: nop

    // 0x808002C8: bc1fl       L_808002D8
    if (!c1cs) {
        // 0x808002CC: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_808002D8;
    }
    goto skip_2;
    // 0x808002CC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    skip_2:
    // 0x808002D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808002D4: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_808002D8:
    // 0x808002D8: beql        $s0, $zero, L_80800348
    if (ctx->r16 == 0) {
        // 0x808002DC: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80800348;
    }
    goto skip_3;
    // 0x808002DC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_3:
    // 0x808002E0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x808002E4: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808002E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808002EC: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x808002F0: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x808002F4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808002F8: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x808002FC: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80800300: lwc1        $f0, 0x20($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X20);
    // 0x80800304: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80800308: nop

    // 0x8080030C: bc1fl       L_80800330
    if (!c1cs) {
        // 0x80800310: trunc.w.s   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_80800330;
    }
    goto skip_4;
    // 0x80800310: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_4:
    // 0x80800314: jal         0x800C3F48
    // 0x80800318: ori         $a0, $a0, 0xFE90
    ctx->r4 = ctx->r4 | 0XFE90;
    func_800C3F48(rdram, ctx);
        goto after_3;
    // 0x80800318: ori         $a0, $a0, 0xFE90
    ctx->r4 = ctx->r4 | 0XFE90;
    after_3:
    // 0x8080031C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80800320: sb          $zero, 0x24($t2)
    MEM_B(0X24, ctx->r10) = 0;
    // 0x80800324: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80800328: lwc1        $f0, 0x20($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X20);
    // 0x8080032C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
L_80800330:
    // 0x80800330: addiu       $a0, $zero, 0x117
    ctx->r4 = ADD32(0, 0X117);
    // 0x80800334: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800338: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080033C: jal         0x800D2498
    // 0x80800340: nop

    func_800D2498(rdram, ctx);
        goto after_4;
    // 0x80800340: nop

    after_4:
    // 0x80800344: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80800348:
    // 0x80800348: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080034C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800350: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80800354: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800358: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x8080035C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80800360: lb          $t9, 0x28($t5)
    ctx->r25 = MEM_B(ctx->r13, 0X28);
    // 0x80800364: bnel        $t9, $at, L_80800480
    if (ctx->r25 != ctx->r1) {
        // 0x80800368: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800480;
    }
    goto skip_5;
    // 0x80800368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x8080036C: jal         0x800D3948
    // 0x80800370: nop

    func_800D3948(rdram, ctx);
        goto after_5;
    // 0x80800370: nop

    after_5:
    // 0x80800374: beq         $v0, $zero, L_80800388
    if (ctx->r2 == 0) {
        // 0x80800378: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80800388;
    }
    // 0x80800378: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8080037C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800380: b           L_8080038C
    // 0x80800384: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
        goto L_8080038C;
    // 0x80800384: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_80800388:
    // 0x80800388: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080038C:
    // 0x8080038C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800390: bne         $at, $zero, L_808003F4
    if (ctx->r1 != 0) {
        // 0x80800394: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808003F4;
    }
    // 0x80800394: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800398: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8080039C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x808003A0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
L_808003A4:
    // 0x808003A4: lb          $t7, 0x29($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X29);
    // 0x808003A8: beql        $s0, $t7, L_808003E8
    if (ctx->r16 == ctx->r15) {
        // 0x808003AC: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_808003E8;
    }
    goto skip_6;
    // 0x808003AC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    skip_6:
    // 0x808003B0: jal         0x8080074C
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    suquiz_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003B8: beql        $v0, $zero, L_808003E8
    if (ctx->r2 == 0) {
        // 0x808003BC: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_808003E8;
    }
    goto skip_7;
    // 0x808003BC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    skip_7:
    // 0x808003C0: jal         0x8080070C
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    suquiz_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808003C8: jal         0x808000C4
    // 0x808003CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808000C4_suquiz(rdram, ctx);
        goto after_8;
    // 0x808003CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x808003D0: beq         $v0, $zero, L_808003E4
    if (ctx->r2 == 0) {
        // 0x808003D4: sll         $t0, $s1, 2
        ctx->r8 = S32(ctx->r17 << 2);
            goto L_808003E4;
    }
    // 0x808003D4: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x808003D8: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x808003DC: sw          $s0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r16;
    // 0x808003E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808003E4:
    // 0x808003E4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
L_808003E8:
    // 0x808003E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808003EC: bnel        $t2, $s0, L_808003A4
    if (ctx->r10 != ctx->r16) {
        // 0x808003F0: lw          $t6, 0x0($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X0);
            goto L_808003A4;
    }
    goto skip_8;
    // 0x808003F0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    skip_8:
L_808003F4:
    // 0x808003F4: beq         $s1, $zero, L_80800418
    if (ctx->r17 == 0) {
        // 0x808003F8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800418;
    }
    // 0x808003F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003FC: jal         0x800DC128
    // 0x80800400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800DC128(rdram, ctx);
        goto after_9;
    // 0x80800400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80800404: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80800408: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x8080040C: lw          $t4, 0x3C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3C);
    // 0x80800410: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80800414: sb          $t4, 0x28($t5)
    MEM_B(0X28, ctx->r13) = ctx->r12;
L_80800418:
    // 0x80800418: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8080041C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800420: lb          $t9, 0x28($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X28);
    // 0x80800424: bne         $t9, $at, L_8080044C
    if (ctx->r25 != ctx->r1) {
        // 0x80800428: nop
    
            goto L_8080044C;
    }
    // 0x80800428: nop

    // 0x8080042C: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80800430: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800434: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x80800438: nop

    // 0x8080043C: bc1f        L_8080044C
    if (!c1cs) {
        // 0x80800440: nop
    
            goto L_8080044C;
    }
    // 0x80800440: nop

    // 0x80800444: lb          $t8, 0x26($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X26);
    // 0x80800448: sb          $t8, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r24;
L_8080044C:
    // 0x8080044C: jal         0x800DB9B0
    // 0x80800450: nop

    func_800DB9B0(rdram, ctx);
        goto after_10;
    // 0x80800450: nop

    after_10:
    // 0x80800454: beql        $v0, $zero, L_80800480
    if (ctx->r2 == 0) {
        // 0x80800458: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800480;
    }
    goto skip_9;
    // 0x80800458: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x8080045C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80800460: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800464: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800468: lb          $a1, 0x28($t6)
    ctx->r5 = MEM_B(ctx->r14, 0X28);
    // 0x8080046C: beql        $a1, $at, L_80800480
    if (ctx->r5 == ctx->r1) {
        // 0x80800470: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800480;
    }
    goto skip_10;
    // 0x80800470: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x80800474: jal         0x80800DF0
    // 0x80800478: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    suquiz_entrypoint_28(rdram, ctx);
        goto after_11;
    // 0x80800478: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8080047C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800480:
    // 0x80800480: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800484: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800488: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080048C: jr          $ra
    // 0x80800490: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800490: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _bsbswim_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BA0: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082BA0);
    return;
    // 0x80082BA4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800000_badeathmatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lw          $t7, 0x158($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X158);
    // 0x80800004: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800008: sb          $t6, 0x20($t7)
    MEM_B(0X20, ctx->r15) = ctx->r14;
    // 0x8080000C: lw          $t8, 0x158($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X158);
    // 0x80800010: sb          $zero, 0x21($t8)
    MEM_B(0X21, ctx->r24) = 0;
    // 0x80800014: lw          $t9, 0x158($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X158);
    // 0x80800018: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    // 0x8080001C: lw          $t0, 0x158($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X158);
    // 0x80800020: jr          $ra
    // 0x80800024: sb          $zero, 0x23($t0)
    MEM_B(0X23, ctx->r8) = 0;
    return;
    // 0x80800024: sb          $zero, 0x23($t0)
    MEM_B(0X23, ctx->r8) = 0;
;}
RECOMP_FUNC void func_80108C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108C90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80108C94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80108C98: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80108C9C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80108CA0: jal         0x80089750
    // 0x80108CA4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    _gemarkersDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80108CA4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80108CA8: bne         $v0, $zero, L_80108CB8
    if (ctx->r2 != 0) {
        // 0x80108CAC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80108CB8;
    }
    // 0x80108CAC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80108CB0: b           L_80108CE4
    // 0x80108CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80108CE4;
    // 0x80108CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80108CB8:
    // 0x80108CB8: jalr        $a3
    // 0x80108CBC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(ctx->r7)(rdram, ctx);
        goto after_1;
    // 0x80108CBC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_1:
    // 0x80108CC0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80108CC4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80108CC8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80108CCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80108CD0: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x80108CD4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80108CD8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80108CDC: jalr        $t9
    // 0x80108CE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80108CE0: nop

    after_2:
L_80108CE4:
    // 0x80108CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80108CE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80108CEC: jr          $ra
    // 0x80108CF0: nop

    return;
    // 0x80108CF0: nop

;}
RECOMP_FUNC void chdiggerbossshell_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1492, 0X560) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1492, 0X560));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1492, 0X560));
;}
RECOMP_FUNC void func_80800034_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800040: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80800044: bnel        $t7, $zero, L_80800080
    if (ctx->r15 != 0) {
        // 0x80800048: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80800080;
    }
    goto skip_0;
    // 0x80800048: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8080004C: jal         0x80091A58
    // 0x80800050: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80800050: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800054: bnel        $v0, $zero, L_80800080
    if (ctx->r2 != 0) {
        // 0x80800058: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80800080;
    }
    goto skip_1;
    // 0x80800058: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x8080005C: jal         0x80084D78
    // 0x80800060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bakaztorpedo_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800064: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800068: nop

    // 0x8080006C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800070: nop

    // 0x80800074: bc1fl       L_80800090
    if (!c1cs) {
        // 0x80800078: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800090;
    }
    goto skip_2;
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8080007C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80800080:
    // 0x80800080: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800084: jal         0x800F9BC4
    // 0x80800088: sw          $t8, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->r24;
    func_800F9BC4(rdram, ctx);
        goto after_2;
    // 0x80800088: sw          $t8, 0x15C($t9)
    MEM_W(0X15C, ctx->r25) = ctx->r24;
    after_2:
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800090:
    // 0x80800090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void _subaddietaxi_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A570: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A570);
    return;
    // 0x8008A574: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _suexpression_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089820: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x80089820);
    return;
    // 0x80089824: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_80104118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104118: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010411C: jr          $ra
    // 0x80104120: addiu       $v0, $v0, 0x6BE8
    ctx->r2 = ADD32(ctx->r2, 0X6BE8);
    return;
    // 0x80104120: addiu       $v0, $v0, 0x6BE8
    ctx->r2 = ADD32(ctx->r2, 0X6BE8);
;}
RECOMP_FUNC void func_800DC528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC52C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC530: jal         0x800E9054
    // 0x800DC534: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E9054(rdram, ctx);
        goto after_0;
    // 0x800DC534: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800DC538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC53C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC540: jr          $ra
    // 0x800DC544: nop

    return;
    // 0x800DC544: nop

;}
RECOMP_FUNC void func_800E7FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7FF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E7FFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E8000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8004: sw          $a1, -0x2A20($at)
    MEM_W(-0X2A20, ctx->r1) = ctx->r5;
    // 0x800E8008: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E800C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x800E8010: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800E8014: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800E8018: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E801C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x800E8020: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800E8024: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800E8028: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x800E802C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800E8030: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x800E8034: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800E8038: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x800E803C: bne         $a1, $at, L_800E8050
    if (ctx->r5 != ctx->r1) {
        // 0x800E8040: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_800E8050;
    }
    // 0x800E8040: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800E8044: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800E8048: b           L_800E8058
    // 0x800E804C: addiu       $a0, $a0, 0x3418
    ctx->r4 = ADD32(ctx->r4, 0X3418);
        goto L_800E8058;
    // 0x800E804C: addiu       $a0, $a0, 0x3418
    ctx->r4 = ADD32(ctx->r4, 0X3418);
L_800E8050:
    // 0x800E8050: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800E8054: addiu       $a0, $a0, 0x3428
    ctx->r4 = ADD32(ctx->r4, 0X3428);
L_800E8058:
    // 0x800E8058: jal         0x8002E330
    // 0x800E805C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800E805C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E8060: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800E8064: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x800E8068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E806C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E8070: jr          $ra
    // 0x800E8074: nop

    return;
    // 0x800E8074: nop

;}
RECOMP_FUNC void func_808007B8_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007C0: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x808007C4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808007C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007CC: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808007D0: beql        $t7, $zero, L_808007F4
    if (ctx->r15 == 0) {
        // 0x808007D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007F4;
    }
    goto skip_0;
    // 0x808007D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808007D8: jal         0x800856B8
    // 0x808007DC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808007DC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808007E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808007E4: lhu         $t8, 0x6E($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6E);
    // 0x808007E8: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808007EC: sh          $t9, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r25;
    // 0x808007F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007F4:
    // 0x808007F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007F8: jr          $ra
    // 0x808007FC: nop

    return;
    // 0x808007FC: nop

;}
RECOMP_FUNC void func_808014E8_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808014EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808014F0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808014F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808014F8: jal         0x80100094
    // 0x808014FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808014FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801500: jal         0x800D8FF8
    // 0x80801504: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801504: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801508: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8080150C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80801510: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801514: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801518: beql        $t7, $at, L_80801568
    if (ctx->r15 == ctx->r1) {
        // 0x8080151C: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80801568;
    }
    goto skip_0;
    // 0x8080151C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80801520: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80801524: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x80801528: jal         0x800CEAD0
    // 0x8080152C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_2;
    // 0x8080152C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x80801530: beql        $v0, $zero, L_80801568
    if (ctx->r2 == 0) {
        // 0x80801534: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80801568;
    }
    goto skip_1;
    // 0x80801534: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x80801538: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x8080153C: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x80801540: bltzl       $t1, L_80801568
    if (SIGNED(ctx->r9) < 0) {
        // 0x80801544: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80801568;
    }
    goto skip_2;
    // 0x80801544: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x80801548: jal         0x8010A570
    // 0x8080154C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x8080154C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801554: jal         0x80101FDC
    // 0x80801558: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80801558: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x8080155C: jal         0x80089CA8
    // 0x80801560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80801560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801564: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80801568:
    // 0x80801568: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080156C: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x80801570: beq         $t2, $at, L_8080159C
    if (ctx->r10 == ctx->r1) {
        // 0x80801574: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080159C;
    }
    // 0x80801574: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801578: beq         $t2, $at, L_808015BC
    if (ctx->r10 == ctx->r1) {
        // 0x8080157C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015BC;
    }
    // 0x8080157C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801580: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801584: beq         $t2, $at, L_80801750
    if (ctx->r10 == ctx->r1) {
        // 0x80801588: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80801750;
    }
    // 0x80801588: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080158C: beql        $t2, $at, L_808017D8
    if (ctx->r10 == ctx->r1) {
        // 0x80801590: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808017D8;
    }
    goto skip_3;
    // 0x80801590: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80801594: b           L_808017D8
    // 0x80801598: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808017D8;
    // 0x80801598: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080159C:
    // 0x8080159C: jal         0x80801C1C
    // 0x808015A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C1C_chmonsterinterior(rdram, ctx);
        goto after_6;
    // 0x808015A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808015A4: beq         $v0, $zero, L_808017D4
    if (ctx->r2 == 0) {
        // 0x808015A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808017D4;
    }
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015AC: jal         0x80101FDC
    // 0x808015B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808015B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808015B4: b           L_808017D8
    // 0x808015B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808017D8;
    // 0x808015B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808015BC:
    // 0x808015BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808015C0: jal         0x8010C93C
    // 0x808015C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8010C93C(rdram, ctx);
        goto after_8;
    // 0x808015C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_8:
    // 0x808015C8: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x808015CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015D0: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x808015D4: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x808015D8: bgez        $t5, L_80801638
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808015DC: nop
    
            goto L_80801638;
    }
    // 0x808015DC: nop

    // 0x808015E0: jal         0x80089BF0
    // 0x808015E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x808015E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_9:
    // 0x808015E8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x808015EC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808015F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1E3C) << 16);
    // 0x808015F4: lwc1        $f6, 0x1E3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1E3C));
    // 0x808015F8: lwc1        $f4, 0x28($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X28);
    // 0x808015FC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80801600: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801604: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080160C: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x80801610: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    // 0x80801614: jal         0x80102BF8
    // 0x80801618: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    func_80102BF8(rdram, ctx);
        goto after_10;
    // 0x80801618: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    after_10:
    // 0x8080161C: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x80801620: ori         $a1, $a1, 0x25
    ctx->r5 = ctx->r5 | 0X25;
    // 0x80801624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801628: jal         0x8010C3A8
    // 0x8080162C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_8010C3A8(rdram, ctx);
        goto after_11;
    // 0x8080162C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x80801630: b           L_8080171C
    // 0x80801634: nop

        goto L_8080171C;
    // 0x80801634: nop

L_80801638:
    // 0x80801638: jal         0x80089F78
    // 0x8080163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x8080163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801640: beq         $v0, $zero, L_80801678
    if (ctx->r2 == 0) {
        // 0x80801644: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801678;
    }
    // 0x80801644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801648: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080164C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801650: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80801654: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80801658: addiu       $t7, $zero, 0x4802
    ctx->r15 = ADD32(0, 0X4802);
    // 0x8080165C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801660: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80801664: jal         0x80089F90
    // 0x80801668: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x80801668: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x8080166C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80801670: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    // 0x80801674: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
L_80801678:
    // 0x80801678: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080167C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1E40) << 16);
    // 0x80801680: lwc1        $f16, 0x1E40($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1E40));
    // 0x80801684: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x80801688: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8080168C: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x80801690: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80801694: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080169C: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x808016A0: jal         0x80089F88
    // 0x808016A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x808016A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_14:
    // 0x808016A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808016AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808016B0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808016B4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808016B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808016BC: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x808016C0: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x808016C4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808016C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016CC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x808016D0: jal         0x80089F80
    // 0x808016D4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x808016D4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x808016D8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808016DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808016E0: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808016E4: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808016E8: lwc1        $f14, 0x30($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808016EC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808016F0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808016F4: jal         0x800F15F8
    // 0x808016F8: nop

    func_800F15F8(rdram, ctx);
        goto after_16;
    // 0x808016F8: nop

    after_16:
    // 0x808016FC: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80801700: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801708: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x8080170C: bltz        $t4, L_8080171C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80801710: nop
    
            goto L_8080171C;
    }
    // 0x80801710: nop

    // 0x80801714: jal         0x8010B990
    // 0x80801718: addiu       $a1, $zero, 0x325
    ctx->r5 = ADD32(0, 0X325);
    func_8010B990(rdram, ctx);
        goto after_17;
    // 0x80801718: addiu       $a1, $zero, 0x325
    ctx->r5 = ADD32(0, 0X325);
    after_17:
L_8080171C:
    // 0x8080171C: jal         0x800D9078
    // 0x80801720: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_18;
    // 0x80801720: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_18:
    // 0x80801724: beq         $v0, $zero, L_808017D4
    if (ctx->r2 == 0) {
        // 0x80801728: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808017D4;
    }
    // 0x80801728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080172C: jal         0x80101FDC
    // 0x80801730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x80801730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_19:
    // 0x80801734: lbu         $t5, 0x64($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X64);
    // 0x80801738: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1E44) << 16);
    // 0x8080173C: lwc1        $f16, 0x1E44($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1E44));
    // 0x80801740: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x80801744: sb          $t6, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r14;
    // 0x80801748: b           L_808017D4
    // 0x8080174C: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
        goto L_808017D4;
    // 0x8080174C: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
L_80801750:
    // 0x80801750: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80801754: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80801758: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080175C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80801760: bltz        $t9, L_808017BC
    if (SIGNED(ctx->r25) < 0) {
        // 0x80801764: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_808017BC;
    }
    // 0x80801764: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801768: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080176C: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80801770: jal         0x800F10B4
    // 0x80801774: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_20;
    // 0x80801774: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_20:
    // 0x80801778: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1E48) << 16);
    // 0x8080177C: lwc1        $f18, 0x1E48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1E48));
    // 0x80801780: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80801784: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801788: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8080178C: nop

    // 0x80801790: bc1f        L_808017BC
    if (!c1cs) {
        // 0x80801794: nop
    
            goto L_808017BC;
    }
    // 0x80801794: nop

    // 0x80801798: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x8080179C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1320, 0X2030) << 16);
    // 0x808017A0: addiu       $a3, $a3, 0x2030
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1320, 0X2030));
    // 0x808017A4: andi        $t0, $a1, 0x1
    ctx->r8 = ctx->r5 & 0X1;
    // 0x808017A8: jal         0x8010D930
    // 0x808017AC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_8010D930(rdram, ctx);
        goto after_21;
    // 0x808017AC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_21:
    // 0x808017B0: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808017B4: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x808017B8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_808017BC:
    // 0x808017BC: jal         0x80801C78
    // 0x808017C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C78_chmonsterinterior(rdram, ctx);
        goto after_22;
    // 0x808017C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808017C4: beql        $v0, $zero, L_808017D8
    if (ctx->r2 == 0) {
        // 0x808017C8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808017D8;
    }
    goto skip_4;
    // 0x808017C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x808017CC: jal         0x800FFAB0
    // 0x808017D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_23;
    // 0x808017D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
L_808017D4:
    // 0x808017D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808017D8:
    // 0x808017D8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808017DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808017E0: jr          $ra
    // 0x808017E4: nop

    return;
    // 0x808017E4: nop

;}
RECOMP_FUNC void _idglowa_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D98: syscall     739
    recomp_syscall_handler(rdram, ctx, 0x80088D98);
    return;
    // 0x80088D9C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chburgerstand_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(936, 0XD00) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0xD00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(936, 0XD00));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0xD00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(936, 0XD00));
;}
RECOMP_FUNC void func_800AC978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC978: addiu       $sp, $sp, -0x1C0
    ctx->r29 = ADD32(ctx->r29, -0X1C0);
    // 0x800AC97C: sw          $a3, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r7;
    // 0x800AC980: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800AC984: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AC988: lwc1        $f4, 0x1CC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1CC);
    // 0x800AC98C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x800AC990: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x800AC994: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800AC998: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x800AC99C: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800AC9A0: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800AC9A4: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800AC9A8: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800AC9AC: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800AC9B0: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800AC9B4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800AC9B8: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x800AC9BC: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800AC9C0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800AC9C4: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800AC9C8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800AC9CC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800AC9D0: sw          $a0, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r4;
    // 0x800AC9D4: sw          $a1, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r5;
    // 0x800AC9D8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800AC9DC: addiu       $t0, $sp, 0x1A4
    ctx->r8 = ADD32(ctx->r29, 0X1A4);
    // 0x800AC9E0: addiu       $v1, $sp, 0x198
    ctx->r3 = ADD32(ctx->r29, 0X198);
    // 0x800AC9E4: addiu       $v0, $sp, 0x1A4
    ctx->r2 = ADD32(ctx->r29, 0X1A4);
    // 0x800AC9E8: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
L_800AC9EC:
    // 0x800AC9EC: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800AC9F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AC9F4: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800AC9F8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800AC9FC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800ACA00: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800ACA04: swc1        $f10, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f10.u32l;
    // 0x800ACA08: lwc1        $f4, -0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, -0X4);
    // 0x800ACA0C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800ACA10: bne         $at, $zero, L_800AC9EC
    if (ctx->r1 != 0) {
        // 0x800ACA14: swc1        $f6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
            goto L_800AC9EC;
    }
    // 0x800ACA14: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x800ACA18: lw          $t6, 0x1C4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C4);
    // 0x800ACA1C: addiu       $v0, $sp, 0x1A4
    ctx->r2 = ADD32(ctx->r29, 0X1A4);
    // 0x800ACA20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ACA24: lhu         $t7, 0x14($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X14);
    // 0x800ACA28: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800ACA2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ACA30: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800ACA34: addiu       $v1, $sp, 0x198
    ctx->r3 = ADD32(ctx->r29, 0X198);
    // 0x800ACA38: bgez        $t7, L_800ACA4C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800ACA3C: cvt.s.w     $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800ACA4C;
    }
    // 0x800ACA3C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800ACA40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ACA44: nop

    // 0x800ACA48: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_800ACA4C:
    // 0x800ACA4C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_800ACA50:
    // 0x800ACA50: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800ACA54: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800ACA58: addu        $t9, $s0, $a0
    ctx->r25 = ADD32(ctx->r16, ctx->r4);
    // 0x800ACA5C: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x800ACA60: nop

    // 0x800ACA64: bc1t        L_800ACA80
    if (c1cs) {
        // 0x800ACA68: nop
    
            goto L_800ACA80;
    }
    // 0x800ACA68: nop

    // 0x800ACA6C: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800ACA70: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x800ACA74: nop

    // 0x800ACA78: bc1f        L_800ACA88
    if (!c1cs) {
        // 0x800ACA7C: nop
    
            goto L_800ACA88;
    }
    // 0x800ACA7C: nop

L_800ACA80:
    // 0x800ACA80: b           L_800AD164
    // 0x800ACA84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AD164;
    // 0x800ACA84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ACA88:
    // 0x800ACA88: bne         $v1, $v0, L_800ACA50
    if (ctx->r3 != ctx->r2) {
        // 0x800ACA8C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800ACA50;
    }
    // 0x800ACA8C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800ACA90: sw          $zero, 0x184($sp)
    MEM_W(0X184, ctx->r29) = 0;
    // 0x800ACA94: jal         0x800EFD24
    // 0x800ACA98: addiu       $a0, $sp, 0x188
    ctx->r4 = ADD32(ctx->r29, 0X188);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800ACA98: addiu       $a0, $sp, 0x188
    ctx->r4 = ADD32(ctx->r29, 0X188);
    after_0:
    // 0x800ACA9C: addiu       $t1, $sp, 0x1B4
    ctx->r9 = ADD32(ctx->r29, 0X1B4);
    // 0x800ACAA0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800ACAA4: lw          $a0, 0x1C0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C0);
    // 0x800ACAA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800ACAAC: addiu       $a2, $sp, 0x198
    ctx->r6 = ADD32(ctx->r29, 0X198);
    // 0x800ACAB0: jal         0x800AA4D4
    // 0x800ACAB4: addiu       $a3, $sp, 0x1BC
    ctx->r7 = ADD32(ctx->r29, 0X1BC);
    func_800AA4D4(rdram, ctx);
        goto after_1;
    // 0x800ACAB4: addiu       $a3, $sp, 0x1BC
    ctx->r7 = ADD32(ctx->r29, 0X1BC);
    after_1:
    // 0x800ACAB8: lw          $v0, 0x1BC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1BC);
    // 0x800ACABC: lw          $t2, 0x1B4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B4);
    // 0x800ACAC0: addiu       $s6, $sp, 0x104
    ctx->r22 = ADD32(ctx->r29, 0X104);
    // 0x800ACAC4: addiu       $s5, $sp, 0x98
    ctx->r21 = ADD32(ctx->r29, 0X98);
    // 0x800ACAC8: sltu        $at, $v0, $t2
    ctx->r1 = ctx->r2 < ctx->r10 ? 1 : 0;
    // 0x800ACACC: beq         $at, $zero, L_800AD13C
    if (ctx->r1 == 0) {
        // 0x800ACAD0: sw          $v0, 0x1B8($sp)
        MEM_W(0X1B8, ctx->r29) = ctx->r2;
            goto L_800AD13C;
    }
    // 0x800ACAD0: sw          $v0, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->r2;
    // 0x800ACAD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ACAD8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800ACADC: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x800ACAE0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800ACAE4: addiu       $fp, $sp, 0x140
    ctx->r30 = ADD32(ctx->r29, 0X140);
    // 0x800ACAE8: addiu       $s4, $sp, 0xD4
    ctx->r20 = ADD32(ctx->r29, 0XD4);
L_800ACAEC:
    // 0x800ACAEC: lw          $t3, 0x1B8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B8);
    // 0x800ACAF0: lw          $t6, 0x1C0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C0);
    // 0x800ACAF4: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800ACAF8: lhu         $t8, 0x10($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X10);
    // 0x800ACAFC: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    // 0x800ACB00: lhu         $t1, 0x2($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X2);
    // 0x800ACB04: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800ACB08: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800ACB0C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800ACB10: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800ACB14: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800ACB18: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800ACB1C: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800ACB20: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800ACB24: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x800ACB28: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800ACB2C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800ACB30: sltu        $at, $v0, $t3
    ctx->r1 = ctx->r2 < ctx->r11 ? 1 : 0;
    // 0x800ACB34: beq         $at, $zero, L_800AD124
    if (ctx->r1 == 0) {
        // 0x800ACB38: sw          $t3, 0x170($sp)
        MEM_W(0X170, ctx->r29) = ctx->r11;
            goto L_800AD124;
    }
    // 0x800ACB38: sw          $t3, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r11;
    // 0x800ACB3C: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
L_800ACB40:
    // 0x800ACB40: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800ACB44: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    // 0x800ACB48: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x800ACB4C: bnel        $t6, $zero, L_800AD114
    if (ctx->r14 != 0) {
        // 0x800ACB50: lw          $t4, 0x170($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X170);
            goto L_800AD114;
    }
    goto skip_0;
    // 0x800ACB50: lw          $t4, 0x170($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X170);
    skip_0:
    // 0x800ACB54: lw          $s1, 0x1C4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C4);
    // 0x800ACB58: sw          $v0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r2;
    // 0x800ACB5C: lw          $s0, 0x174($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X174);
    // 0x800ACB60: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
L_800ACB64:
    // 0x800ACB64: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x800ACB68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800ACB6C: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x800ACB70: jal         0x800EE88C
    // 0x800ACB74: addu        $a1, $t7, $s1
    ctx->r5 = ADD32(ctx->r15, ctx->r17);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x800ACB74: addu        $a1, $t7, $s1
    ctx->r5 = ADD32(ctx->r15, ctx->r17);
    after_2:
    // 0x800ACB78: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x800ACB7C: addiu       $t9, $sp, 0xBC
    ctx->r25 = ADD32(ctx->r29, 0XBC);
    // 0x800ACB80: sltu        $at, $s2, $t9
    ctx->r1 = ctx->r18 < ctx->r25 ? 1 : 0;
    // 0x800ACB84: bne         $at, $zero, L_800ACB64
    if (ctx->r1 != 0) {
        // 0x800ACB88: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800ACB64;
    }
    // 0x800ACB88: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800ACB8C: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x800ACB90: jal         0x800EE7F8
    // 0x800ACB94: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800ACB94: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x800ACB98: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x800ACB9C: jal         0x800EE7F8
    // 0x800ACBA0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x800ACBA0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x800ACBA4: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x800ACBA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800ACBAC:
    // 0x800ACBAC: addiu       $v1, $sp, 0xD4
    ctx->r3 = ADD32(ctx->r29, 0XD4);
    // 0x800ACBB0: addiu       $v0, $sp, 0xC8
    ctx->r2 = ADD32(ctx->r29, 0XC8);
L_800ACBB4:
    // 0x800ACBB4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800ACBB8: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800ACBBC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800ACBC0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800ACBC4: nop

    // 0x800ACBC8: bc1fl       L_800ACBD8
    if (!c1cs) {
        // 0x800ACBCC: lwc1        $f10, 0x0($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
            goto L_800ACBD8;
    }
    goto skip_1;
    // 0x800ACBCC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x800ACBD0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800ACBD4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
L_800ACBD8:
    // 0x800ACBD8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800ACBDC: nop

    // 0x800ACBE0: bc1fl       L_800ACBF0
    if (!c1cs) {
        // 0x800ACBE4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800ACBF0;
    }
    goto skip_2;
    // 0x800ACBE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_2:
    // 0x800ACBE8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800ACBEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800ACBF0:
    // 0x800ACBF0: bne         $v0, $s4, L_800ACBB4
    if (ctx->r2 != ctx->r20) {
        // 0x800ACBF4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800ACBB4;
    }
    // 0x800ACBF4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800ACBF8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x800ACBFC: addiu       $t1, $sp, 0xBC
    ctx->r9 = ADD32(ctx->r29, 0XBC);
    // 0x800ACC00: sltu        $at, $a1, $t1
    ctx->r1 = ctx->r5 < ctx->r9 ? 1 : 0;
    // 0x800ACC04: bnel        $at, $zero, L_800ACBAC
    if (ctx->r1 != 0) {
        // 0x800ACC08: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800ACBAC;
    }
    goto skip_3;
    // 0x800ACC08: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_3:
    // 0x800ACC0C: lwc1        $f4, 0x198($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X198);
    // 0x800ACC10: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800ACC14: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800ACC18: lwc1        $f10, 0x1A4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1A4);
    // 0x800ACC1C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800ACC20: nop

    // 0x800ACC24: bc1t        L_800ACC40
    if (c1cs) {
        // 0x800ACC28: nop
    
            goto L_800ACC40;
    }
    // 0x800ACC28: nop

    // 0x800ACC2C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800ACC30: lwc1        $f4, 0x19C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X19C);
    // 0x800ACC34: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800ACC38: bc1fl       L_800ACC4C
    if (!c1cs) {
        // 0x800ACC3C: c.lt.s      $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
            goto L_800ACC4C;
    }
    goto skip_4;
    // 0x800ACC3C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    skip_4:
L_800ACC40:
    // 0x800ACC40: b           L_800AD110
    // 0x800ACC44: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
        goto L_800AD110;
    // 0x800ACC44: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
    // 0x800ACC48: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
L_800ACC4C:
    // 0x800ACC4C: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800ACC50: lwc1        $f10, 0x1A8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x800ACC54: bc1t        L_800ACC70
    if (c1cs) {
        // 0x800ACC58: nop
    
            goto L_800ACC70;
    }
    // 0x800ACC58: nop

    // 0x800ACC5C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800ACC60: lwc1        $f4, 0x1A0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1A0);
    // 0x800ACC64: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800ACC68: bc1fl       L_800ACC7C
    if (!c1cs) {
        // 0x800ACC6C: c.lt.s      $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
            goto L_800ACC7C;
    }
    goto skip_5;
    // 0x800ACC6C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    skip_5:
L_800ACC70:
    // 0x800ACC70: b           L_800AD110
    // 0x800ACC74: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
        goto L_800AD110;
    // 0x800ACC74: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
    // 0x800ACC78: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
L_800ACC7C:
    // 0x800ACC7C: lwc1        $f8, 0xD0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800ACC80: lwc1        $f10, 0x1AC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1AC);
    // 0x800ACC84: bc1t        L_800ACCA0
    if (c1cs) {
        // 0x800ACC88: nop
    
            goto L_800ACCA0;
    }
    // 0x800ACC88: nop

    // 0x800ACC8C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800ACC90: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800ACC94: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x800ACC98: bc1f        L_800ACCA8
    if (!c1cs) {
        // 0x800ACC9C: nop
    
            goto L_800ACCA8;
    }
    // 0x800ACC9C: nop

L_800ACCA0:
    // 0x800ACCA0: b           L_800AD110
    // 0x800ACCA4: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
        goto L_800AD110;
    // 0x800ACCA4: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
L_800ACCA8:
    // 0x800ACCA8: jal         0x800EFB24
    // 0x800ACCAC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x800ACCAC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x800ACCB0: addiu       $a0, $sp, 0x14C
    ctx->r4 = ADD32(ctx->r29, 0X14C);
    // 0x800ACCB4: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x800ACCB8: jal         0x800EFB24
    // 0x800ACCBC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x800ACCBC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_6:
    // 0x800ACCC0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800ACCC4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800ACCC8: jal         0x800EE97C
    // 0x800ACCCC: addiu       $a2, $sp, 0x14C
    ctx->r6 = ADD32(ctx->r29, 0X14C);
    func_800EE97C(rdram, ctx);
        goto after_7;
    // 0x800ACCCC: addiu       $a2, $sp, 0x14C
    ctx->r6 = ADD32(ctx->r29, 0X14C);
    after_7:
    // 0x800ACCD0: jal         0x800EF2A0
    // 0x800ACCD4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_8;
    // 0x800ACCD4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_8:
    // 0x800ACCD8: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800ACCDC: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800ACCE0: addiu       $a0, $sp, 0x11C
    ctx->r4 = ADD32(ctx->r29, 0X11C);
    // 0x800ACCE4: c.eq.s      $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f26.fl == ctx->f4.fl;
    // 0x800ACCE8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800ACCEC: lwc1        $f10, 0x1CC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1CC);
    // 0x800ACCF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800ACCF4: bc1fl       L_800ACD28
    if (!c1cs) {
        // 0x800ACCF8: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800ACD28;
    }
    goto skip_6;
    // 0x800ACCF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_6:
    // 0x800ACCFC: c.eq.s      $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f26.fl == ctx->f6.fl;
    // 0x800ACD00: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800ACD04: bc1fl       L_800ACD28
    if (!c1cs) {
        // 0x800ACD08: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800ACD28;
    }
    goto skip_7;
    // 0x800ACD08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_7:
    // 0x800ACD0C: c.eq.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl == ctx->f8.fl;
    // 0x800ACD10: nop

    // 0x800ACD14: bc1fl       L_800ACD28
    if (!c1cs) {
        // 0x800ACD18: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800ACD28;
    }
    goto skip_8;
    // 0x800ACD18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_8:
    // 0x800ACD1C: b           L_800AD110
    // 0x800ACD20: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
        goto L_800AD110;
    // 0x800ACD20: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
    // 0x800ACD24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_800ACD28:
    // 0x800ACD28: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800ACD2C: jal         0x800EFB24
    // 0x800ACD30: sub.s       $f22, $f10, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f4.fl;
    func_800EFB24(rdram, ctx);
        goto after_9;
    // 0x800ACD30: sub.s       $f22, $f10, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f4.fl;
    after_9:
    // 0x800ACD34: lw          $t2, 0x174($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X174);
    // 0x800ACD38: addiu       $a0, $sp, 0x11C
    ctx->r4 = ADD32(ctx->r29, 0X11C);
    // 0x800ACD3C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800ACD40: sll         $t4, $t3, 15
    ctx->r12 = S32(ctx->r11 << 15);
    // 0x800ACD44: bgezl       $t4, L_800ACD8C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800ACD48: addiu       $a0, $sp, 0x11C
        ctx->r4 = ADD32(ctx->r29, 0X11C);
            goto L_800ACD8C;
    }
    goto skip_9;
    // 0x800ACD48: addiu       $a0, $sp, 0x11C
    ctx->r4 = ADD32(ctx->r29, 0X11C);
    skip_9:
    // 0x800ACD4C: jal         0x800EEAA4
    // 0x800ACD50: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_10;
    // 0x800ACD50: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_10:
    // 0x800ACD54: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x800ACD58: nop

    // 0x800ACD5C: bc1fl       L_800ACD8C
    if (!c1cs) {
        // 0x800ACD60: addiu       $a0, $sp, 0x11C
        ctx->r4 = ADD32(ctx->r29, 0X11C);
            goto L_800ACD8C;
    }
    goto skip_10;
    // 0x800ACD60: addiu       $a0, $sp, 0x11C
    ctx->r4 = ADD32(ctx->r29, 0X11C);
    skip_10:
    // 0x800ACD64: lwc1        $f24, 0x104($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800ACD68: lwc1        $f20, 0x108($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800ACD6C: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800ACD70: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = -ctx->f24.fl;
    // 0x800ACD74: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x800ACD78: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
    // 0x800ACD7C: swc1        $f24, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f24.u32l;
    // 0x800ACD80: swc1        $f20, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f20.u32l;
    // 0x800ACD84: swc1        $f18, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f18.u32l;
    // 0x800ACD88: addiu       $a0, $sp, 0x11C
    ctx->r4 = ADD32(ctx->r29, 0X11C);
L_800ACD8C:
    // 0x800ACD8C: jal         0x800EEAA4
    // 0x800ACD90: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_11;
    // 0x800ACD90: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_11:
    // 0x800ACD94: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800ACD98: jal         0x800F2100
    // 0x800ACD9C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_12;
    // 0x800ACD9C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_12:
    // 0x800ACDA0: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800ACDA4: lwc1        $f12, 0x104($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800ACDA8: bc1f        L_800ACDB8
    if (!c1cs) {
        // 0x800ACDAC: nop
    
            goto L_800ACDB8;
    }
    // 0x800ACDAC: nop

    // 0x800ACDB0: b           L_800AD110
    // 0x800ACDB4: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
        goto L_800AD110;
    // 0x800ACDB4: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
L_800ACDB8:
    // 0x800ACDB8: mul.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800ACDBC: lwc1        $f10, 0x0($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800ACDC0: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800ACDC4: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800ACDC8: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    // 0x800ACDCC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800ACDD0: lwc1        $f10, 0x4($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X4);
    // 0x800ACDD4: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800ACDD8: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800ACDDC: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    // 0x800ACDE0: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800ACDE4: lwc1        $f10, 0x8($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X8);
    // 0x800ACDE8: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800ACDEC: jal         0x800F2100
    // 0x800ACDF0: swc1        $f8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f8.u32l;
    mlAbsF(rdram, ctx);
        goto after_13;
    // 0x800ACDF0: swc1        $f8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x800ACDF4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800ACDF8: jal         0x800F2100
    // 0x800ACDFC: lwc1        $f12, 0x108($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X108);
    mlAbsF(rdram, ctx);
        goto after_14;
    // 0x800ACDFC: lwc1        $f12, 0x108($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X108);
    after_14:
    // 0x800ACE00: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800ACE04: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800ACE08: bc1f        L_800ACE18
    if (!c1cs) {
        // 0x800ACE0C: nop
    
            goto L_800ACE18;
    }
    // 0x800ACE0C: nop

    // 0x800ACE10: b           L_800ACE18
    // 0x800ACE14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800ACE18;
    // 0x800ACE14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800ACE18:
    // 0x800ACE18: jal         0x800F2100
    // 0x800ACE1C: lwc1        $f12, 0x10C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10C);
    mlAbsF(rdram, ctx);
        goto after_15;
    // 0x800ACE1C: lwc1        $f12, 0x10C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10C);
    after_15:
    // 0x800ACE20: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x800ACE24: addu        $t6, $s6, $t5
    ctx->r14 = ADD32(ctx->r22, ctx->r13);
    // 0x800ACE28: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800ACE2C: jal         0x800F2100
    // 0x800ACE30: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_16;
    // 0x800ACE30: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_16:
    // 0x800ACE34: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800ACE38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800ACE3C: bc1fl       L_800ACE4C
    if (!c1cs) {
        // 0x800ACE40: addiu       $v0, $s0, 0x1
        ctx->r2 = ADD32(ctx->r16, 0X1);
            goto L_800ACE4C;
    }
    goto skip_11;
    // 0x800ACE40: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    skip_11:
    // 0x800ACE44: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800ACE48: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_800ACE4C:
    // 0x800ACE4C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800ACE50: mfhi        $t8
    ctx->r24 = hi;
    // 0x800ACE54: sll         $v0, $t8, 2
    ctx->r2 = S32(ctx->r24 << 2);
    // 0x800ACE58: addu        $t9, $sp, $v0
    ctx->r25 = ADD32(ctx->r29, ctx->r2);
    // 0x800ACE5C: addu        $t1, $s5, $v0
    ctx->r9 = ADD32(ctx->r21, ctx->r2);
    // 0x800ACE60: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800ACE64: lwc1        $f10, 0xBC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XBC);
    // 0x800ACE68: addu        $v1, $fp, $v0
    ctx->r3 = ADD32(ctx->r30, ctx->r2);
    // 0x800ACE6C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x800ACE70: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800ACE74: lw          $a3, 0xC($v1)
    ctx->r7 = MEM_W(ctx->r3, 0XC);
    // 0x800ACE78: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    // 0x800ACE7C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800ACE80: jal         0x800EFA4C
    // 0x800ACE84: nop

    func_800EFA4C(rdram, ctx);
        goto after_17;
    // 0x800ACE84: nop

    after_17:
    // 0x800ACE88: addiu       $v0, $s0, 0x2
    ctx->r2 = ADD32(ctx->r16, 0X2);
    // 0x800ACE8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800ACE90: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800ACE94: mfhi        $t2
    ctx->r10 = hi;
    // 0x800ACE98: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
    // 0x800ACE9C: addu        $t4, $sp, $v0
    ctx->r12 = ADD32(ctx->r29, ctx->r2);
    // 0x800ACEA0: addu        $t5, $s5, $v0
    ctx->r13 = ADD32(ctx->r21, ctx->r2);
    // 0x800ACEA4: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800ACEA8: lwc1        $f4, 0xBC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XBC);
    // 0x800ACEAC: addu        $v1, $fp, $v0
    ctx->r3 = ADD32(ctx->r30, ctx->r2);
    // 0x800ACEB0: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x800ACEB4: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800ACEB8: lw          $a3, 0xC($v1)
    ctx->r7 = MEM_W(ctx->r3, 0XC);
    // 0x800ACEBC: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
    // 0x800ACEC0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800ACEC4: jal         0x800EFA4C
    // 0x800ACEC8: nop

    func_800EFA4C(rdram, ctx);
        goto after_18;
    // 0x800ACEC8: nop

    after_18:
    // 0x800ACECC: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800ACED0: lwc1        $f18, 0xFC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800ACED4: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800ACED8: lwc1        $f20, 0xF0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800ACEDC: mul.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800ACEE0: lwc1        $f22, 0xF8($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800ACEE4: lwc1        $f24, 0xEC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800ACEE8: mul.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800ACEEC: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    // 0x800ACEF0: mul.s       $f6, $f22, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x800ACEF4: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800ACEF8: mul.s       $f8, $f16, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x800ACEFC: div.s       $f12, $f28, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f28.fl, ctx->f10.fl);
    // 0x800ACF00: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800ACF04: mul.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800ACF08: c.le.s      $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f30.fl <= ctx->f2.fl;
    // 0x800ACF0C: nop

    // 0x800ACF10: bc1fl       L_800ACF90
    if (!c1cs) {
        // 0x800ACF14: lwc1        $f24, 0x1CC($sp)
        ctx->f24.u32l = MEM_W(ctx->r29, 0X1CC);
            goto L_800ACF90;
    }
    goto skip_12;
    // 0x800ACF14: lwc1        $f24, 0x1CC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1CC);
    skip_12:
    // 0x800ACF18: c.le.s      $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f2.fl <= ctx->f28.fl;
    // 0x800ACF1C: nop

    // 0x800ACF20: bc1fl       L_800ACF90
    if (!c1cs) {
        // 0x800ACF24: lwc1        $f24, 0x1CC($sp)
        ctx->f24.u32l = MEM_W(ctx->r29, 0X1CC);
            goto L_800ACF90;
    }
    goto skip_13;
    // 0x800ACF24: lwc1        $f24, 0x1CC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1CC);
    skip_13:
    // 0x800ACF28: mul.s       $f10, $f18, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800ACF2C: nop

    // 0x800ACF30: mul.s       $f6, $f22, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800ACF34: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800ACF38: mul.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800ACF3C: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
    // 0x800ACF40: nop

    // 0x800ACF44: bc1f        L_800ACF8C
    if (!c1cs) {
        // 0x800ACF48: nop
    
            goto L_800ACF8C;
    }
    // 0x800ACF48: nop

    // 0x800ACF4C: c.le.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl <= ctx->f28.fl;
    // 0x800ACF50: nop

    // 0x800ACF54: bc1fl       L_800ACF90
    if (!c1cs) {
        // 0x800ACF58: lwc1        $f24, 0x1CC($sp)
        ctx->f24.u32l = MEM_W(ctx->r29, 0X1CC);
            goto L_800ACF90;
    }
    goto skip_14;
    // 0x800ACF58: lwc1        $f24, 0x1CC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1CC);
    skip_14:
    // 0x800ACF5C: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800ACF60: lw          $t6, 0x174($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X174);
    // 0x800ACF64: addiu       $a0, $sp, 0x188
    ctx->r4 = ADD32(ctx->r29, 0X188);
    // 0x800ACF68: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800ACF6C: c.le.s      $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f4.fl <= ctx->f28.fl;
    // 0x800ACF70: nop

    // 0x800ACF74: bc1fl       L_800ACF90
    if (!c1cs) {
        // 0x800ACF78: lwc1        $f24, 0x1CC($sp)
        ctx->f24.u32l = MEM_W(ctx->r29, 0X1CC);
            goto L_800ACF90;
    }
    goto skip_15;
    // 0x800ACF78: lwc1        $f24, 0x1CC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1CC);
    skip_15:
    // 0x800ACF7C: jal         0x800EF04C
    // 0x800ACF80: sw          $t6, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r14;
    func_800EF04C(rdram, ctx);
        goto after_19;
    // 0x800ACF80: sw          $t6, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r14;
    after_19:
    // 0x800ACF84: b           L_800AD110
    // 0x800ACF88: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
        goto L_800AD110;
    // 0x800ACF88: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
L_800ACF8C:
    // 0x800ACF8C: lwc1        $f24, 0x1CC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1CC);
L_800ACF90:
    // 0x800ACF90: addiu       $s1, $sp, 0x11C
    ctx->r17 = ADD32(ctx->r29, 0X11C);
    // 0x800ACF94: mul.s       $f22, $f24, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800ACF98: nop

L_800ACF9C:
    // 0x800ACF9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800ACFA0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800ACFA4: jal         0x800EFB24
    // 0x800ACFA8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_20;
    // 0x800ACFA8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_20:
    // 0x800ACFAC: jal         0x800EEFD4
    // 0x800ACFB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEFD4(rdram, ctx);
        goto after_21;
    // 0x800ACFB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x800ACFB4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800ACFB8: addiu       $t7, $sp, 0x140
    ctx->r15 = ADD32(ctx->r29, 0X140);
    // 0x800ACFBC: bc1fl       L_800ACFE4
    if (!c1cs) {
        // 0x800ACFC0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800ACFE4;
    }
    goto skip_16;
    // 0x800ACFC0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_16:
    // 0x800ACFC4: lw          $t8, 0x174($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X174);
    // 0x800ACFC8: addiu       $a0, $sp, 0x188
    ctx->r4 = ADD32(ctx->r29, 0X188);
    // 0x800ACFCC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800ACFD0: jal         0x800EF04C
    // 0x800ACFD4: sw          $t8, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r24;
    func_800EF04C(rdram, ctx);
        goto after_22;
    // 0x800ACFD4: sw          $t8, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r24;
    after_22:
    // 0x800ACFD8: b           L_800ACFF4
    // 0x800ACFDC: addiu       $t9, $sp, 0x140
    ctx->r25 = ADD32(ctx->r29, 0X140);
        goto L_800ACFF4;
    // 0x800ACFDC: addiu       $t9, $sp, 0x140
    ctx->r25 = ADD32(ctx->r29, 0X140);
    // 0x800ACFE0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_800ACFE4:
    // 0x800ACFE4: sltu        $at, $s1, $t7
    ctx->r1 = ctx->r17 < ctx->r15 ? 1 : 0;
    // 0x800ACFE8: bne         $at, $zero, L_800ACF9C
    if (ctx->r1 != 0) {
        // 0x800ACFEC: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_800ACF9C;
    }
    // 0x800ACFEC: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x800ACFF0: addiu       $t9, $sp, 0x140
    ctx->r25 = ADD32(ctx->r29, 0X140);
L_800ACFF4:
    // 0x800ACFF4: sltu        $at, $s1, $t9
    ctx->r1 = ctx->r17 < ctx->r25 ? 1 : 0;
    // 0x800ACFF8: beq         $at, $zero, L_800AD008
    if (ctx->r1 == 0) {
        // 0x800ACFFC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AD008;
    }
    // 0x800ACFFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD000: b           L_800AD110
    // 0x800AD004: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
        goto L_800AD110;
    // 0x800AD004: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
L_800AD008:
    // 0x800AD008: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    // 0x800AD00C: addiu       $s1, $sp, 0x11C
    ctx->r17 = ADD32(ctx->r29, 0X11C);
    // 0x800AD010: addiu       $s0, $sp, 0x140
    ctx->r16 = ADD32(ctx->r29, 0X140);
L_800AD014:
    // 0x800AD014: addiu       $s3, $v0, 0x1
    ctx->r19 = ADD32(ctx->r2, 0X1);
    // 0x800AD018: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AD01C: div         $zero, $s3, $at
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r1)));
    // 0x800AD020: mfhi        $t1
    ctx->r9 = hi;
    // 0x800AD024: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800AD028: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800AD02C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800AD030: addu        $a1, $s5, $t2
    ctx->r5 = ADD32(ctx->r21, ctx->r10);
    // 0x800AD034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD038: jal         0x800EFB24
    // 0x800AD03C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_23;
    // 0x800AD03C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_23:
    // 0x800AD040: jal         0x800EEFD4
    // 0x800AD044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEFD4(rdram, ctx);
        goto after_24;
    // 0x800AD044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x800AD048: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800AD04C: jal         0x800EF2A0
    // 0x800AD050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_25;
    // 0x800AD050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x800AD054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD058: jal         0x800EEAA4
    // 0x800AD05C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_26;
    // 0x800AD05C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_26:
    // 0x800AD060: c.le.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl <= ctx->f0.fl;
    // 0x800AD064: nop

    // 0x800AD068: bc1fl       L_800AD0F8
    if (!c1cs) {
        // 0x800AD06C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AD0F8;
    }
    goto skip_17;
    // 0x800AD06C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_17:
    // 0x800AD070: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800AD074: c.le.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl <= ctx->f20.fl;
    // 0x800AD078: nop

    // 0x800AD07C: bc1fl       L_800AD0F8
    if (!c1cs) {
        // 0x800AD080: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AD0F8;
    }
    goto skip_18;
    // 0x800AD080: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_18:
    // 0x800AD084: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800AD088: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800AD08C: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x800AD090: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AD094: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AD098: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x800AD09C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AD0A0: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800AD0A4: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800AD0A8: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800AD0AC: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x800AD0B0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AD0B4: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800AD0B8: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AD0BC: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AD0C0: jal         0x800EEFD4
    // 0x800AD0C4: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    func_800EEFD4(rdram, ctx);
        goto after_27;
    // 0x800AD0C4: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    after_27:
    // 0x800AD0C8: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800AD0CC: nop

    // 0x800AD0D0: bc1fl       L_800AD0F8
    if (!c1cs) {
        // 0x800AD0D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AD0F8;
    }
    goto skip_19;
    // 0x800AD0D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_19:
    // 0x800AD0D8: lw          $t3, 0x174($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X174);
    // 0x800AD0DC: addiu       $a0, $sp, 0x188
    ctx->r4 = ADD32(ctx->r29, 0X188);
    // 0x800AD0E0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800AD0E4: jal         0x800EF04C
    // 0x800AD0E8: sw          $t3, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r11;
    func_800EF04C(rdram, ctx);
        goto after_28;
    // 0x800AD0E8: sw          $t3, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r11;
    after_28:
    // 0x800AD0EC: b           L_800AD110
    // 0x800AD0F0: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
        goto L_800AD110;
    // 0x800AD0F0: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
    // 0x800AD0F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800AD0F8:
    // 0x800AD0F8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800AD0FC: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x800AD100: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800AD104: bne         $s3, $at, L_800AD014
    if (ctx->r19 != ctx->r1) {
        // 0x800AD108: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800AD014;
    }
    // 0x800AD108: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800AD10C: lw          $v0, 0x174($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X174);
L_800AD110:
    // 0x800AD110: lw          $t4, 0x170($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X170);
L_800AD114:
    // 0x800AD114: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800AD118: sltu        $at, $v0, $t4
    ctx->r1 = ctx->r2 < ctx->r12 ? 1 : 0;
    // 0x800AD11C: bnel        $at, $zero, L_800ACB40
    if (ctx->r1 != 0) {
        // 0x800AD120: lw          $t4, 0x8($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X8);
            goto L_800ACB40;
    }
    goto skip_20;
    // 0x800AD120: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    skip_20:
L_800AD124:
    // 0x800AD124: lw          $t5, 0x1B8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AD128: lw          $t8, 0x1B4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B4);
    // 0x800AD12C: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800AD130: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x800AD134: bne         $at, $zero, L_800ACAEC
    if (ctx->r1 != 0) {
        // 0x800AD138: sw          $t6, 0x1B8($sp)
        MEM_W(0X1B8, ctx->r29) = ctx->r14;
            goto L_800ACAEC;
    }
    // 0x800AD138: sw          $t6, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->r14;
L_800AD13C:
    // 0x800AD13C: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800AD140: lw          $a0, 0x1D0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1D0);
    // 0x800AD144: beql        $t7, $zero, L_800AD158
    if (ctx->r15 == 0) {
        // 0x800AD148: lw          $a0, 0x184($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X184);
            goto L_800AD158;
    }
    goto skip_21;
    // 0x800AD148: lw          $a0, 0x184($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X184);
    skip_21:
    // 0x800AD14C: jal         0x800EF410
    // 0x800AD150: addiu       $a1, $sp, 0x188
    ctx->r5 = ADD32(ctx->r29, 0X188);
    func_800EF410(rdram, ctx);
        goto after_29;
    // 0x800AD150: addiu       $a1, $sp, 0x188
    ctx->r5 = ADD32(ctx->r29, 0X188);
    after_29:
    // 0x800AD154: lw          $a0, 0x184($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X184);
L_800AD158:
    // 0x800AD158: jal         0x800AA3B4
    // 0x800AD15C: lw          $a1, 0x1C4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C4);
    func_800AA3B4(rdram, ctx);
        goto after_30;
    // 0x800AD15C: lw          $a1, 0x1C4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C4);
    after_30:
    // 0x800AD160: lw          $v0, 0x184($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X184);
L_800AD164:
    // 0x800AD164: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800AD168: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800AD16C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800AD170: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800AD174: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800AD178: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800AD17C: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x800AD180: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800AD184: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800AD188: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800AD18C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800AD190: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800AD194: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800AD198: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800AD19C: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x800AD1A0: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x800AD1A4: jr          $ra
    // 0x800AD1A8: addiu       $sp, $sp, 0x1C0
    ctx->r29 = ADD32(ctx->r29, 0X1C0);
    return;
    // 0x800AD1A8: addiu       $sp, $sp, 0x1C0
    ctx->r29 = ADD32(ctx->r29, 0X1C0);
;}
RECOMP_FUNC void _suquiz_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A830: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A830);
    return;
    // 0x8008A834: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _cheggsplode_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087348: syscall     552
    recomp_syscall_handler(rdram, ctx, 0x80087348);
    return;
    // 0x8008734C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bsbansack_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006FC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800700: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1E20) << 16);
    // 0x80800704: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800708: jr          $ra
    // 0x8080070C: lw          $v0, 0x1E20($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E20));
    return;
    // 0x8080070C: lw          $v0, 0x1E20($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E20));
;}
RECOMP_FUNC void func_8010EBE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010EBE4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010EBE8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8010EBEC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8010EBF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8010EBF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010EBF8: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x8010EBFC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8010EC00: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8010EC04: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8010EC08: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8010EC0C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8010EC10: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8010EC14: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8010EC18: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010EC1C: jal         0x800B2344
    // 0x8010EC20: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    func_800B2344(rdram, ctx);
        goto after_0;
    // 0x8010EC20: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010EC24: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x8010EC28: addiu       $fp, $fp, 0x7080
    ctx->r30 = ADD32(ctx->r30, 0X7080);
    // 0x8010EC2C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8010EC30: lbu         $t7, 0x11($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X11);
    // 0x8010EC34: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8010EC38: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8010EC3C: addu        $a1, $t6, $s7
    ctx->r5 = ADD32(ctx->r14, ctx->r23);
    // 0x8010EC40: addiu       $s4, $s0, 0x18
    ctx->r20 = ADD32(ctx->r16, 0X18);
    // 0x8010EC44: beq         $t7, $zero, L_8010EE20
    if (ctx->r15 == 0) {
        // 0x8010EC48: sw          $a1, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r5;
            goto L_8010EE20;
    }
    // 0x8010EC48: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x8010EC4C: sltu        $at, $s7, $a1
    ctx->r1 = ctx->r23 < ctx->r5 ? 1 : 0;
    // 0x8010EC50: beq         $at, $zero, L_8010EE98
    if (ctx->r1 == 0) {
        // 0x8010EC54: lui         $at, 0x4380
        ctx->r1 = S32(0X4380 << 16);
            goto L_8010EE98;
    }
    // 0x8010EC54: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8010EC58: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010EC5C: addiu       $s6, $zero, 0x4000
    ctx->r22 = ADD32(0, 0X4000);
    // 0x8010EC60: lhu         $t8, 0x6($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X6);
L_8010EC64:
    // 0x8010EC64: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010EC68: addiu       $s0, $t0, 0x709C
    ctx->r16 = ADD32(ctx->r8, 0X709C);
    // 0x8010EC6C: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x8010EC70: bnel        $t9, $zero, L_8010EE04
    if (ctx->r25 != 0) {
        // 0x8010EC74: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_8010EE04;
    }
    goto skip_0;
    // 0x8010EC74: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x8010EC78: lw          $a2, 0x14($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X14);
    // 0x8010EC7C: lw          $s2, 0x4($fp)
    ctx->r18 = MEM_W(ctx->r30, 0X4);
    // 0x8010EC80: lw          $s3, 0x8($fp)
    ctx->r19 = MEM_W(ctx->r30, 0X8);
    // 0x8010EC84: sltu        $at, $s0, $a2
    ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
    // 0x8010EC88: beq         $at, $zero, L_8010ED94
    if (ctx->r1 == 0) {
        // 0x8010EC8C: lw          $s5, 0xC($fp)
        ctx->r21 = MEM_W(ctx->r30, 0XC);
            goto L_8010ED94;
    }
    // 0x8010EC8C: lw          $s5, 0xC($fp)
    ctx->r21 = MEM_W(ctx->r30, 0XC);
    // 0x8010EC90: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
L_8010EC94:
    // 0x8010EC94: lh          $t2, 0x0($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X0);
    // 0x8010EC98: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8010EC9C: lh          $t4, 0x2($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X2);
    // 0x8010ECA0: subu        $v0, $t1, $t2
    ctx->r2 = SUB32(ctx->r9, ctx->r10);
    // 0x8010ECA4: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010ECA8: subu        $v1, $t3, $t4
    ctx->r3 = SUB32(ctx->r11, ctx->r12);
    // 0x8010ECAC: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8010ECB0: lh          $t6, 0x4($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X4);
    // 0x8010ECB4: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x8010ECB8: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x8010ECBC: mflo        $t7
    ctx->r15 = lo;
    // 0x8010ECC0: nop

    // 0x8010ECC4: nop

    // 0x8010ECC8: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010ECCC: mflo        $t8
    ctx->r24 = lo;
    // 0x8010ECD0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8010ECD4: nop

    // 0x8010ECD8: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010ECDC: mflo        $t0
    ctx->r8 = lo;
    // 0x8010ECE0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x8010ECE4: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8010ECE8: beql        $at, $zero, L_8010ED88
    if (ctx->r1 == 0) {
        // 0x8010ECEC: addiu       $s0, $s0, 0x28
        ctx->r16 = ADD32(ctx->r16, 0X28);
            goto L_8010ED88;
    }
    goto skip_1;
    // 0x8010ECEC: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    skip_1:
    // 0x8010ECF0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8010ECF4: lui         $s1, 0x1
    ctx->r17 = S32(0X1 << 16);
    // 0x8010ECF8: jal         0x8002DCA0
    // 0x8010ECFC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8010ECFC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x8010ED00: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8010ED04: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8010ED08: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010ED0C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8010ED10: nop

    // 0x8010ED14: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8010ED18: beql        $at, $zero, L_8010ED48
    if (ctx->r1 == 0) {
        // 0x8010ED1C: lw          $t8, 0x18($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X18);
            goto L_8010ED48;
    }
    goto skip_2;
    // 0x8010ED1C: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    skip_2:
    // 0x8010ED20: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x8010ED24: subu        $t4, $v1, $a0
    ctx->r12 = SUB32(ctx->r3, ctx->r4);
    // 0x8010ED28: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010ED2C: mflo        $t5
    ctx->r13 = lo;
    // 0x8010ED30: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x8010ED34: subu        $v0, $s6, $t6
    ctx->r2 = SUB32(ctx->r22, ctx->r14);
    // 0x8010ED38: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8010ED3C: sra         $t7, $s1, 14
    ctx->r15 = S32(SIGNED(ctx->r17) >> 14);
    // 0x8010ED40: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8010ED44: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
L_8010ED48:
    // 0x8010ED48: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x8010ED4C: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x8010ED50: multu       $t8, $s1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010ED54: lw          $a2, 0x14($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X14);
    // 0x8010ED58: mflo        $t9
    ctx->r25 = lo;
    // 0x8010ED5C: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8010ED60: addu        $s2, $s2, $t0
    ctx->r18 = ADD32(ctx->r18, ctx->r8);
    // 0x8010ED64: multu       $t1, $s1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010ED68: mflo        $t2
    ctx->r10 = lo;
    // 0x8010ED6C: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8010ED70: addu        $s3, $s3, $t3
    ctx->r19 = ADD32(ctx->r19, ctx->r11);
    // 0x8010ED74: multu       $t4, $s1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010ED78: mflo        $t5
    ctx->r13 = lo;
    // 0x8010ED7C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8010ED80: addu        $s5, $s5, $t6
    ctx->r21 = ADD32(ctx->r21, ctx->r14);
    // 0x8010ED84: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
L_8010ED88:
    // 0x8010ED88: sltu        $at, $s0, $a2
    ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
    // 0x8010ED8C: bnel        $at, $zero, L_8010EC94
    if (ctx->r1 != 0) {
        // 0x8010ED90: lw          $t1, 0x0($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X0);
            goto L_8010EC94;
    }
    goto skip_3;
    // 0x8010ED90: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_8010ED94:
    // 0x8010ED94: lbu         $t7, 0x6($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0X6);
    // 0x8010ED98: multu       $t7, $s2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010ED9C: mflo        $v0
    ctx->r2 = lo;
    // 0x8010EDA0: sra         $t8, $v0, 8
    ctx->r24 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8010EDA4: slti        $at, $t8, 0x100
    ctx->r1 = SIGNED(ctx->r24) < 0X100 ? 1 : 0;
    // 0x8010EDA8: bne         $at, $zero, L_8010EDB4
    if (ctx->r1 != 0) {
        // 0x8010EDAC: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8010EDB4;
    }
    // 0x8010EDAC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8010EDB0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8010EDB4:
    // 0x8010EDB4: sb          $v0, 0xC($s4)
    MEM_B(0XC, ctx->r20) = ctx->r2;
    // 0x8010EDB8: lbu         $t9, 0x7($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X7);
    // 0x8010EDBC: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010EDC0: mflo        $v0
    ctx->r2 = lo;
    // 0x8010EDC4: sra         $t0, $v0, 8
    ctx->r8 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8010EDC8: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x8010EDCC: bne         $at, $zero, L_8010EDD8
    if (ctx->r1 != 0) {
        // 0x8010EDD0: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8010EDD8;
    }
    // 0x8010EDD0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8010EDD4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8010EDD8:
    // 0x8010EDD8: sb          $v0, 0xD($s4)
    MEM_B(0XD, ctx->r20) = ctx->r2;
    // 0x8010EDDC: lbu         $t1, 0x8($s7)
    ctx->r9 = MEM_BU(ctx->r23, 0X8);
    // 0x8010EDE0: multu       $t1, $s5
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010EDE4: mflo        $v0
    ctx->r2 = lo;
    // 0x8010EDE8: sra         $t2, $v0, 8
    ctx->r10 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8010EDEC: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
    // 0x8010EDF0: bne         $at, $zero, L_8010EDFC
    if (ctx->r1 != 0) {
        // 0x8010EDF4: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8010EDFC;
    }
    // 0x8010EDF4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8010EDF8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8010EDFC:
    // 0x8010EDFC: sb          $v0, 0xE($s4)
    MEM_B(0XE, ctx->r20) = ctx->r2;
    // 0x8010EE00: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_8010EE04:
    // 0x8010EE04: addiu       $s7, $s7, 0xA
    ctx->r23 = ADD32(ctx->r23, 0XA);
    // 0x8010EE08: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x8010EE0C: sltu        $at, $s7, $t3
    ctx->r1 = ctx->r23 < ctx->r11 ? 1 : 0;
    // 0x8010EE10: bnel        $at, $zero, L_8010EC64
    if (ctx->r1 != 0) {
        // 0x8010EE14: lhu         $t8, 0x6($s4)
        ctx->r24 = MEM_HU(ctx->r20, 0X6);
            goto L_8010EC64;
    }
    goto skip_4;
    // 0x8010EE14: lhu         $t8, 0x6($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X6);
    skip_4:
    // 0x8010EE18: b           L_8010EE9C
    // 0x8010EE1C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8010EE9C;
    // 0x8010EE1C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8010EE20:
    // 0x8010EE20: sltu        $at, $s7, $a1
    ctx->r1 = ctx->r23 < ctx->r5 ? 1 : 0;
    // 0x8010EE24: lw          $v0, 0x4($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X4);
    // 0x8010EE28: lw          $v1, 0x8($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X8);
    // 0x8010EE2C: beq         $at, $zero, L_8010EE98
    if (ctx->r1 == 0) {
        // 0x8010EE30: lw          $a0, 0xC($fp)
        ctx->r4 = MEM_W(ctx->r30, 0XC);
            goto L_8010EE98;
    }
    // 0x8010EE30: lw          $a0, 0xC($fp)
    ctx->r4 = MEM_W(ctx->r30, 0XC);
    // 0x8010EE34: lhu         $t4, 0x6($s4)
    ctx->r12 = MEM_HU(ctx->r20, 0X6);
L_8010EE38:
    // 0x8010EE38: andi        $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 & 0X1000;
    // 0x8010EE3C: bnel        $t5, $zero, L_8010EE84
    if (ctx->r13 != 0) {
        // 0x8010EE40: lw          $t5, 0x48($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X48);
            goto L_8010EE84;
    }
    goto skip_5;
    // 0x8010EE40: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    skip_5:
    // 0x8010EE44: lbu         $t6, 0x6($s7)
    ctx->r14 = MEM_BU(ctx->r23, 0X6);
    // 0x8010EE48: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010EE4C: mflo        $t7
    ctx->r15 = lo;
    // 0x8010EE50: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x8010EE54: sb          $t8, 0xC($s4)
    MEM_B(0XC, ctx->r20) = ctx->r24;
    // 0x8010EE58: lbu         $t9, 0x7($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X7);
    // 0x8010EE5C: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010EE60: mflo        $t0
    ctx->r8 = lo;
    // 0x8010EE64: sra         $t1, $t0, 8
    ctx->r9 = S32(SIGNED(ctx->r8) >> 8);
    // 0x8010EE68: sb          $t1, 0xD($s4)
    MEM_B(0XD, ctx->r20) = ctx->r9;
    // 0x8010EE6C: lbu         $t2, 0x8($s7)
    ctx->r10 = MEM_BU(ctx->r23, 0X8);
    // 0x8010EE70: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010EE74: mflo        $t3
    ctx->r11 = lo;
    // 0x8010EE78: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x8010EE7C: sb          $t4, 0xE($s4)
    MEM_B(0XE, ctx->r20) = ctx->r12;
    // 0x8010EE80: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
L_8010EE84:
    // 0x8010EE84: addiu       $s7, $s7, 0xA
    ctx->r23 = ADD32(ctx->r23, 0XA);
    // 0x8010EE88: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x8010EE8C: sltu        $at, $s7, $t5
    ctx->r1 = ctx->r23 < ctx->r13 ? 1 : 0;
    // 0x8010EE90: bnel        $at, $zero, L_8010EE38
    if (ctx->r1 != 0) {
        // 0x8010EE94: lhu         $t4, 0x6($s4)
        ctx->r12 = MEM_HU(ctx->r20, 0X6);
            goto L_8010EE38;
    }
    goto skip_6;
    // 0x8010EE94: lhu         $t4, 0x6($s4)
    ctx->r12 = MEM_HU(ctx->r20, 0X6);
    skip_6:
L_8010EE98:
    // 0x8010EE98: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8010EE9C:
    // 0x8010EE9C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010EEA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8010EEA4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8010EEA8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8010EEAC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8010EEB0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8010EEB4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8010EEB8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8010EEBC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8010EEC0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8010EEC4: jr          $ra
    // 0x8010EEC8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8010EEC8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _sumultiscore_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899A0: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x800899A0);
    return;
    // 0x800899A4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D78: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D78);
    return;
    // 0x80087D7C: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void func_80017764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017764: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80017768: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001776C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80017770: jr          $ra
    // 0x80017774: lhu         $v0, -0xA00($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0XA00);
    return;
    // 0x80017774: lhu         $v0, -0xA00($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0XA00);
;}
RECOMP_FUNC void func_80800528_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800528: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8080052C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800530: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800534: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80800538: jal         0x80100094
    // 0x8080053C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080053C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800540: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80800544: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80800548: jal         0x80100094
    // 0x8080054C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080054C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800550: jal         0x800D8FF8
    // 0x80800554: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800554: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x80800558: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x8080055C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80800560: lbu         $t6, 0x8F4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8F4);
    // 0x80800564: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80800568: bnel        $v1, $t6, L_808007AC
    if (ctx->r3 != ctx->r14) {
        // 0x8080056C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808007AC;
    }
    goto skip_0;
    // 0x8080056C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800570: lbu         $v0, 0x8F5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8F5);
    // 0x80800574: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800578: beq         $v0, $at, L_808005A0
    if (ctx->r2 == ctx->r1) {
        // 0x8080057C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808005A0;
    }
    // 0x8080057C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800580: beq         $v0, $at, L_808005B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800584: lw          $t8, 0x88($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X88);
            goto L_808005B0;
    }
    // 0x80800584: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x80800588: beq         $v0, $v1, L_808005A0
    if (ctx->r2 == ctx->r3) {
        // 0x8080058C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808005A0;
    }
    // 0x8080058C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800590: beq         $v0, $at, L_808005B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800594: nop
    
            goto L_808005B0;
    }
    // 0x80800594: nop

    // 0x80800598: b           L_808005C4
    // 0x8080059C: nop

        goto L_808005C4;
    // 0x8080059C: nop

L_808005A0:
    // 0x808005A0: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x808005A4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x808005A8: b           L_808005C4
    // 0x808005AC: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
        goto L_808005C4;
    // 0x808005AC: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
L_808005B0:
    // 0x808005B0: jal         0x80106790
    // 0x808005B4: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x808005B4: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    after_3:
    // 0x808005B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808005BC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x808005C0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_808005C4:
    // 0x808005C4: jal         0x80089E68
    // 0x808005C8: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    _susplinet_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x808005C8: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_4:
    // 0x808005CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005D0: jal         0x80089E78
    // 0x808005D4: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    _susplinet_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808005D4: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_5:
    // 0x808005D8: jal         0x80105AE8
    // 0x808005DC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80105AE8(rdram, ctx);
        goto after_6;
    // 0x808005DC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_6:
    // 0x808005E0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808005E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005E8: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x808005EC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808005F0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808005F4: jal         0x80089E70
    // 0x808005F8: nop

    _susplinet_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x808005F8: nop

    after_7:
    // 0x808005FC: jal         0x80089EA8
    // 0x80800600: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    _susplinet_entrypoint_17(rdram, ctx);
        goto after_8;
    // 0x80800600: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_8:
    // 0x80800604: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80800608: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080060C: jal         0x80089E58
    // 0x80800610: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    _susplinet_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x80800610: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_9:
    // 0x80800614: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80800618: jal         0x80089E60
    // 0x8080061C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _susplinet_entrypoint_8(rdram, ctx);
        goto after_10;
    // 0x8080061C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800620: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800624: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80800628: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8080062C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800630: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800634: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80800638: jal         0x800EF5A0
    // 0x8080063C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800EF5A0(rdram, ctx);
        goto after_11;
    // 0x8080063C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_11:
    // 0x80800640: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800644: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800648: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080064C: bne         $t0, $at, L_80800670
    if (ctx->r8 != ctx->r1) {
        // 0x80800650: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_80800670;
    }
    // 0x80800650: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800654: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800658: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080065C: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    // 0x80800660: jal         0x800EFA4C
    // 0x80800664: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_12;
    // 0x80800664: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_12:
    // 0x80800668: b           L_80800680
    // 0x8080066C: nop

        goto L_80800680;
    // 0x8080066C: nop

L_80800670:
    // 0x80800670: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800674: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800678: jal         0x800EFA4C
    // 0x8080067C: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_13;
    // 0x8080067C: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    after_13:
L_80800680:
    // 0x80800680: jal         0x80089E50
    // 0x80800684: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    _susplinet_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x80800684: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    after_14:
    // 0x80800688: beql        $v0, $zero, L_80800698
    if (ctx->r2 == 0) {
        // 0x8080068C: lbu         $t1, 0x8F6($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X8F6);
            goto L_80800698;
    }
    goto skip_1;
    // 0x8080068C: lbu         $t1, 0x8F6($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X8F6);
    skip_1:
    // 0x80800690: sb          $zero, 0x8F6($s0)
    MEM_B(0X8F6, ctx->r16) = 0;
    // 0x80800694: lbu         $t1, 0x8F6($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X8F6);
L_80800698:
    // 0x80800698: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x8080069C: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x808006A0: beql        $t1, $zero, L_80800708
    if (ctx->r9 == 0) {
        // 0x808006A4: lwc1        $f18, 0x44($t4)
        ctx->f18.u32l = MEM_W(ctx->r12, 0X44);
            goto L_80800708;
    }
    goto skip_2;
    // 0x808006A4: lwc1        $f18, 0x44($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X44);
    skip_2:
    // 0x808006A8: lwc1        $f12, 0x44($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X44);
    // 0x808006AC: jal         0x800F1DCC
    // 0x808006B0: lwc1        $f14, 0x904($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X904);
    func_800F1DCC(rdram, ctx);
        goto after_15;
    // 0x808006B0: lwc1        $f14, 0x904($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X904);
    after_15:
    // 0x808006B4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808006B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808006BC: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808006C0: lwc1        $f18, 0x904($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X904);
    // 0x808006C4: lwc1        $f14, 0x908($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X908);
    // 0x808006C8: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808006CC: nop

    // 0x808006D0: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808006D4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x808006D8: swc1        $f6, 0x904($s0)
    MEM_W(0X904, ctx->r16) = ctx->f6.u32l;
    // 0x808006DC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x808006E0: lwc1        $f12, 0x48($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X48);
    // 0x808006E4: jal         0x800F1DCC
    // 0x808006E8: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_16;
    // 0x808006E8: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_16:
    // 0x808006EC: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808006F0: lwc1        $f8, 0x908($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X908);
    // 0x808006F4: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808006F8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808006FC: b           L_80800720
    // 0x80800700: swc1        $f16, 0x908($s0)
    MEM_W(0X908, ctx->r16) = ctx->f16.u32l;
        goto L_80800720;
    // 0x80800700: swc1        $f16, 0x908($s0)
    MEM_W(0X908, ctx->r16) = ctx->f16.u32l;
    // 0x80800704: lwc1        $f18, 0x44($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X44);
L_80800708:
    // 0x80800708: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080070C: swc1        $f18, 0x904($s0)
    MEM_W(0X904, ctx->r16) = ctx->f18.u32l;
    // 0x80800710: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80800714: lwc1        $f4, 0x48($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X48);
    // 0x80800718: sb          $t6, 0x8F6($s0)
    MEM_B(0X8F6, ctx->r16) = ctx->r14;
    // 0x8080071C: swc1        $f4, 0x908($s0)
    MEM_W(0X908, ctx->r16) = ctx->f4.u32l;
L_80800720:
    // 0x80800720: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800724: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800728: lw          $a1, 0x904($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X904);
    // 0x8080072C: lw          $a2, 0x908($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X908);
    // 0x80800730: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800734: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80800738: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8080073C: jal         0x800EF4E4
    // 0x80800740: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_17;
    // 0x80800740: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_17:
    // 0x80800744: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800748: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080074C: lw          $a1, 0x904($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X904);
    // 0x80800750: lw          $a2, 0x908($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X908);
    // 0x80800754: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800758: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8080075C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800760: jal         0x800EF4E4
    // 0x80800764: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_18;
    // 0x80800764: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_18:
    // 0x80800768: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x8080076C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800770: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800774: jal         0x800EF04C
    // 0x80800778: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_19;
    // 0x80800778: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
    // 0x8080077C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800780: jal         0x800EF04C
    // 0x80800784: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_20;
    // 0x80800784: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_20:
    // 0x80800788: addiu       $s0, $sp, 0x54
    ctx->r16 = ADD32(ctx->r29, 0X54);
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800790: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800794: jal         0x800A516C
    // 0x80800798: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800A516C(rdram, ctx);
        goto after_21;
    // 0x80800798: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_21:
    // 0x8080079C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808007A0: jal         0x800856A8
    // 0x808007A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _capod_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x808007A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_22:
    // 0x808007A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007AC:
    // 0x808007AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007B0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x808007B4: jr          $ra
    // 0x808007B8: nop

    return;
    // 0x808007B8: nop

;}
RECOMP_FUNC void func_80800284_chcanarymarycage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800284: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080028C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800290: jal         0x80100094
    // 0x80800294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800298: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080029C: jal         0x800DA298
    // 0x808002A0: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808002A0: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_1:
    // 0x808002A4: bnel        $v0, $zero, L_808002C0
    if (ctx->r2 != 0) {
        // 0x808002A8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808002C0;
    }
    goto skip_0;
    // 0x808002A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808002AC: jal         0x80088848
    // 0x808002B0: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808002B0: nop

    after_2:
    // 0x808002B4: beq         $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x808002B8: nop
    
            goto L_808002C8;
    }
    // 0x808002B8: nop

    // 0x808002BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808002C0:
    // 0x808002C0: jal         0x80800000
    // 0x808002C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800000_chcanarymarycage(rdram, ctx);
        goto after_3;
    // 0x808002C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
L_808002C8:
    // 0x808002C8: jal         0x8008A020
    // 0x808002CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808002CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x808002D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_80800018_chdiggerbossshell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080001C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800028: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x8080002C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800030: jal         0x800EFB8C
    // 0x80800034: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFB8C(rdram, ctx);
        goto after_0;
    // 0x80800034: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800038: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080003C: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800040: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800044: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800048: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080004C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80800058: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x8080005C: jal         0x80102D78
    // 0x80800060: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x80800060: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800064: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800068: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x8080006C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1492, 0X550) << 16);
    // 0x80800070: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800074: lwc1        $f18, 0x550($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1492, 0X550));
    // 0x80800078: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080007C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80800080: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800084: jal         0x8002DCA0
    // 0x80800088: div.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80800088: div.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    after_2:
    // 0x8080008C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800090: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800094: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80800098: jal         0x800EEC30
    // 0x8080009C: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    func_800EEC30(rdram, ctx);
        goto after_3;
    // 0x8080009C: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    after_3:
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void fxdialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800068: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080006C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80800070: nop

    // 0x80800074: bc1f        L_80800094
    if (!c1cs) {
        // 0x80800078: nop
    
            goto L_80800094;
    }
    // 0x80800078: nop

    // 0x8080007C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800080: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2858, 0X290) << 16);
    // 0x80800084: addiu       $v0, $v0, 0x290
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2858, 0X290));
    // 0x80800088: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8080008C: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x80800090: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
L_80800094:
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082598: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082598);
    return;
    // 0x8008259C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void gcfrontend_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001A8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808001AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808001B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2650, 0XD80) << 16);
    // 0x808001B4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808001B8: jr          $ra
    // 0x808001BC: lbu         $v0, 0xD80($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2650, 0XD80));
    return;
    // 0x808001BC: lbu         $v0, 0xD80($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2650, 0XD80));
;}
RECOMP_FUNC void _bsbtrot_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C10: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C10);
    return;
    // 0x80082C14: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80801250_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801250: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801254: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801258: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x8080125C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801260: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80801264: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80801268: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8080126C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80801270: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80801274: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801278: jal         0x800D8FF8
    // 0x8080127C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080127C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801280: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80801284: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801288: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8080128C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80801290: jal         0x800EFB24
    // 0x80801294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x80801294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801298: jal         0x800EEF94
    // 0x8080129C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEF94(rdram, ctx);
        goto after_2;
    // 0x8080129C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808012A0: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808012A4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808012A8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808012AC: add.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x808012B0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808012B4: nop

    // 0x808012B8: bc1fl       L_808012E8
    if (!c1cs) {
        // 0x808012BC: add.s       $f10, $f22, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f22.fl;
            goto L_808012E8;
    }
    goto skip_0;
    // 0x808012BC: add.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f22.fl;
    skip_0:
    // 0x808012C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808012C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808012C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012CC: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x808012D0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808012D4: jal         0x80801210
    // 0x808012D8: nop

    func_80801210_chpiranha(rdram, ctx);
        goto after_3;
    // 0x808012D8: nop

    after_3:
    // 0x808012DC: b           L_80801300
    // 0x808012E0: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
        goto L_80801300;
    // 0x808012E0: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x808012E4: add.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f22.fl;
L_808012E8:
    // 0x808012E8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808012EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012F0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808012F4: jal         0x80801210
    // 0x808012F8: nop

    func_80801210_chpiranha(rdram, ctx);
        goto after_4;
    // 0x808012F8: nop

    after_4:
    // 0x808012FC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
L_80801300:
    // 0x80801300: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80801304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801308: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8080130C: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80801310: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80801314: nop

    // 0x80801318: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8080131C: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80801320: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80801324: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80801328: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8080132C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801330: mul.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80801334: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80801338: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8080133C: nop

    // 0x80801340: mul.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80801344: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80801348: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8080134C: swc1        $f8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f8.u32l;
    // 0x80801350: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80801354: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801358: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8080135C: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80801360: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80801364: nop

    // 0x80801368: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8080136C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80801370: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80801374: swc1        $f10, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f10.u32l;
    // 0x80801378: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8080137C: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80801380: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80801384: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80801388: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8080138C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80801390: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x80801394: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801398: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8080139C: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x808013A0: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x808013A4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808013A8: mul.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x808013AC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x808013B0: jal         0x800EEF94
    // 0x808013B4: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    func_800EEF94(rdram, ctx);
        goto after_5;
    // 0x808013B4: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    after_5:
    // 0x808013B8: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x808013BC: nop

    // 0x808013C0: bc1fl       L_808013DC
    if (!c1cs) {
        // 0x808013C4: lw          $s0, 0x64($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X64);
            goto L_808013DC;
    }
    goto skip_1;
    // 0x808013C4: lw          $s0, 0x64($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x808013C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808013CC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808013D0: jal         0x80801210
    // 0x808013D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801210_chpiranha(rdram, ctx);
        goto after_6;
    // 0x808013D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x808013D8: lw          $s0, 0x64($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X64);
L_808013DC:
    // 0x808013DC: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x808013E0: beql        $s0, $zero, L_80801404
    if (ctx->r16 == 0) {
        // 0x808013E4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801404;
    }
    goto skip_2;
    // 0x808013E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x808013E8: jal         0x800EFD24
    // 0x808013EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFD24(rdram, ctx);
        goto after_7;
    // 0x808013EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x808013F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808013F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808013F8: jal         0x800F18FC
    // 0x808013FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F18FC(rdram, ctx);
        goto after_8;
    // 0x808013FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x80801400: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80801404:
    // 0x80801404: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801408: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080140C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801410: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80801414: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80801418: jr          $ra
    // 0x8080141C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8080141C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800B2768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2768: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x800B276C: bne         $v1, $zero, L_800B277C
    if (ctx->r3 != 0) {
        // 0x800B2770: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B277C;
    }
    // 0x800B2770: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B2774: jr          $ra
    // 0x800B2778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B2778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B277C:
    // 0x800B277C: jr          $ra
    // 0x800B2780: nop

    return;
    // 0x800B2780: nop

;}
RECOMP_FUNC void func_80801154_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080115C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80801160: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80801164: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80801168: bltz        $t8, L_80801178
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080116C: nop
    
            goto L_80801178;
    }
    // 0x8080116C: nop

    // 0x80801170: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x80801174: ori         $a1, $a1, 0x6
    ctx->r5 = ctx->r5 | 0X6;
L_80801178:
    // 0x80801178: jal         0x8010B990
    // 0x8080117C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010B990(rdram, ctx);
        goto after_0;
    // 0x8080117C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801180: andi        $t9, $v0, 0x30
    ctx->r25 = ctx->r2 & 0X30;
    // 0x80801184: beq         $t9, $zero, L_808011AC
    if (ctx->r25 == 0) {
        // 0x80801188: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808011AC;
    }
    // 0x80801188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080118C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801190: jal         0x801096C8
    // 0x80801194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_801096C8(rdram, ctx);
        goto after_1;
    // 0x80801194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080119C: jal         0x808010AC
    // 0x808011A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808010AC_chonearmbandit(rdram, ctx);
        goto after_2;
    // 0x808011A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808011A4: b           L_808011AC
    // 0x808011A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011AC;
    // 0x808011A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011AC:
    // 0x808011AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011B4: jr          $ra
    // 0x808011B8: nop

    return;
    // 0x808011B8: nop

    // 0x808011BC: nop

;}
RECOMP_FUNC void baeggfire_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800414: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080041C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800420: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800424: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800428: jal         0x80084AC0
    // 0x8080042C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    _baeggcursor_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080042C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800434: beq         $v0, $at, L_80800450
    if (ctx->r2 == ctx->r1) {
        // 0x80800438: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800450;
    }
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800440: jal         0x80084AC8
    // 0x80800444: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    _baeggcursor_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800444: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_1:
    // 0x80800448: b           L_80800468
    // 0x8080044C: nop

        goto L_80800468;
    // 0x8080044C: nop

L_80800450:
    // 0x80800450: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x80800454: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800458: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x8080045C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800460: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x80800464: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_80800468:
    // 0x80800468: jal         0x800A4C68
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_2;
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800470: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800474: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800478: jal         0x800C5008
    // 0x8080047C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800C5008(rdram, ctx);
        goto after_3;
    // 0x8080047C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80800480: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800484: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800488: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8080048C: jal         0x800EFA4C
    // 0x80800490: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800490: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_4:
    // 0x80800494: jal         0x800A4C68
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_5;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080049C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808004A4: jal         0x800C4E58
    // 0x808004A8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800C4E58(rdram, ctx);
        goto after_6;
    // 0x808004A8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: jal         0x800A4CE8
    // 0x808004B4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800A4CE8(rdram, ctx);
        goto after_7;
    // 0x808004B4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_7:
    // 0x808004B8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808004BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808004C0: jal         0x800EFB24
    // 0x808004C4: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x808004C4: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x808004C8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808004CC: jal         0x800EF368
    // 0x808004D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800EF368(rdram, ctx);
        goto after_9;
    // 0x808004D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
    // 0x808004D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808004E0: jr          $ra
    // 0x808004E4: nop

    return;
    // 0x808004E4: nop

;}
