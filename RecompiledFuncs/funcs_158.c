#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _cothemedll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087880: syscall     635
    recomp_syscall_handler(rdram, ctx, 0x80087880);
    return;
    // 0x80087884: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chstarspinnerplanet_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DF0: syscall     243
    recomp_syscall_handler(rdram, ctx, 0x80085DF0);
    return;
    // 0x80085DF4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808003B8_bsstonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C0: jal         0x80091A58
    // 0x808003C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x808003C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x808003C8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808003CC: beq         $t6, $zero, L_808003E4
    if (ctx->r14 == 0) {
        // 0x808003D0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808003E4;
    }
    // 0x808003D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808003D4: jal         0x800DA298
    // 0x808003D8: addiu       $a0, $zero, 0x65A
    ctx->r4 = ADD32(0, 0X65A);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808003D8: addiu       $a0, $zero, 0x65A
    ctx->r4 = ADD32(0, 0X65A);
    after_1:
    // 0x808003DC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808003E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_808003E4:
    // 0x808003E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003EC: jr          $ra
    // 0x808003F0: nop

    return;
    // 0x808003F0: nop

;}
RECOMP_FUNC void chpoolkids_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1092, 0X1480) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x1480
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1092, 0X1480));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x1480
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1092, 0X1480));
;}
RECOMP_FUNC void bsbtrot_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801060: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801068: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080106C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801070: jal         0x8008CABC
    // 0x80801074: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801074: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80801078: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080107C: jal         0x8008AF24
    // 0x80801080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80801080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801088: jal         0x8008AED4
    // 0x8080108C: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x8080108C: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_2:
    // 0x80801090: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80801094: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80801098: jal         0x8008B1BC
    // 0x8080109C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x8080109C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808010A0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808010A4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808010A8: jal         0x8008B1C8
    // 0x808010AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x808010AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808010B0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808010B4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808010B8: jal         0x8008B24C
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_5;
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808010C0: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x808010C4: ori         $a2, $a2, 0xE704
    ctx->r6 = ctx->r6 | 0XE704;
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010CC: jal         0x8008B1D4
    // 0x808010D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x808010D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808010D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010D8: jal         0x8008B134
    // 0x808010DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x808010DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808010E0: jal         0x8008B064
    // 0x808010E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x808010E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808010E8: jal         0x80800538
    // 0x808010EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_9;
    // 0x808010EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x808010F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010F4: jal         0x8008CA4C
    // 0x808010F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_10;
    // 0x808010F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808010FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801100: jal         0x8009C908
    // 0x80801104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_11;
    // 0x80801104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80801108: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080110C: jal         0x8009D2D8
    // 0x80801110: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_12;
    // 0x80801110: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x80801114: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801118: jal         0x8009B800
    // 0x8080111C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_13;
    // 0x8080111C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_13:
    // 0x80801120: jal         0x8009EF04
    // 0x80801124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_14;
    // 0x80801124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80801128: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080112C: nop

    // 0x80801130: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80801134: nop

    // 0x80801138: bc1t        L_80801154
    if (c1cs) {
        // 0x8080113C: nop
    
            goto L_80801154;
    }
    // 0x8080113C: nop

    // 0x80801140: jal         0x8009EEB8
    // 0x80801144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_15;
    // 0x80801144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80801148: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080114C: jal         0x8009C914
    // 0x80801150: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_16;
    // 0x80801150: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
L_80801154:
    // 0x80801154: jal         0x8009C990
    // 0x80801158: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_17;
    // 0x80801158: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x8080115C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801160: jal         0x8009B9C0
    // 0x80801164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_18;
    // 0x80801164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80801168: jal         0x80800438
    // 0x8080116C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800438_bsbtrot(rdram, ctx);
        goto after_19;
    // 0x8080116C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80801170: jal         0x8009C990
    // 0x80801174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_20;
    // 0x80801174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80801178: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080117C: jal         0x8009BB00
    // 0x80801180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_21;
    // 0x80801180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x80801184: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080118C: jal         0x8009BA68
    // 0x80801190: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_22;
    // 0x80801190: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_22:
    // 0x80801194: lui         $a1, 0x442D
    ctx->r5 = S32(0X442D << 16);
    // 0x80801198: ori         $a1, $a1, 0x6000
    ctx->r5 = ctx->r5 | 0X6000;
    // 0x8080119C: jal         0x8009BA58
    // 0x808011A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_23;
    // 0x808011A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x808011A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808011A8: jal         0x8009BCB4
    // 0x808011AC: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_24;
    // 0x808011AC: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_24:
    // 0x808011B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808011B4: addiu       $a1, $zero, 0x4432
    ctx->r5 = ADD32(0, 0X4432);
    // 0x808011B8: jal         0x8009DE38
    // 0x808011BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_25;
    // 0x808011BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_25:
    // 0x808011C0: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x808011C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808011CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808011D0: jr          $ra
    // 0x808011D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808011D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void glsplinenode_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800014: jal         0x800D035C
    // 0x80800018: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void func_80801A4C_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A4C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80801A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801A5C: jal         0x800D8FF8
    // 0x80801A60: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80801A60: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80801A64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801A68: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80801A6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801A70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801A74: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80801A78: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80801A7C: nop

    // 0x80801A80: bc1fl       L_80801B20
    if (!c1cs) {
        // 0x80801A84: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80801B20;
    }
    goto skip_0;
    // 0x80801A84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x80801A88: lui         $at, 0x4178
    ctx->r1 = S32(0X4178 << 16);
    // 0x80801A8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801A90: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80801A94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5118) << 16);
    // 0x80801A98: mul.s       $f14, $f12, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80801A9C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80801AA0: nop

    // 0x80801AA4: bc1f        L_80801ADC
    if (!c1cs) {
        // 0x80801AA8: nop
    
            goto L_80801ADC;
    }
    // 0x80801AA8: nop

    // 0x80801AAC: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80801AB0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5114) << 16);
    // 0x80801AB4: lwc1        $f10, 0x5114($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5114));
    // 0x80801AB8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801ABC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801AC0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801AC4: nop

    // 0x80801AC8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80801ACC: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80801AD0: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    // 0x80801AD4: b           L_80801BDC
    // 0x80801AD8: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
        goto L_80801BDC;
    // 0x80801AD8: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
L_80801ADC:
    // 0x80801ADC: lwc1        $f8, 0x5118($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5118));
    // 0x80801AE0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801AE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801AE8: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80801AEC: nop

    // 0x80801AF0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80801AF4: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80801AF8: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x80801AFC: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80801B00: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80801B04: nop

    // 0x80801B08: bc1f        L_80801BDC
    if (!c1cs) {
        // 0x80801B0C: nop
    
            goto L_80801BDC;
    }
    // 0x80801B0C: nop

    // 0x80801B10: swc1        $f14, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f14.u32l;
    // 0x80801B14: b           L_80801BDC
    // 0x80801B18: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
        goto L_80801BDC;
    // 0x80801B18: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80801B1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80801B20:
    // 0x80801B20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5124) << 16);
    // 0x80801B24: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80801B28: nop

    // 0x80801B2C: bc1fl       L_80801BCC
    if (!c1cs) {
        // 0x80801B30: lwc1        $f8, 0x50($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
            goto L_80801BCC;
    }
    goto skip_1;
    // 0x80801B30: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    skip_1:
    // 0x80801B34: lui         $at, 0x4178
    ctx->r1 = S32(0X4178 << 16);
    // 0x80801B38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801B3C: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80801B40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5120) << 16);
    // 0x80801B44: mul.s       $f14, $f12, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80801B48: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80801B4C: nop

    // 0x80801B50: bc1f        L_80801B88
    if (!c1cs) {
        // 0x80801B54: nop
    
            goto L_80801B88;
    }
    // 0x80801B54: nop

    // 0x80801B58: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80801B5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X511C) << 16);
    // 0x80801B60: lwc1        $f16, 0x511C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X511C));
    // 0x80801B64: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801B68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801B6C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80801B70: nop

    // 0x80801B74: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80801B78: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80801B7C: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x80801B80: b           L_80801BDC
    // 0x80801B84: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
        goto L_80801BDC;
    // 0x80801B84: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
L_80801B88:
    // 0x80801B88: lwc1        $f10, 0x5120($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5120));
    // 0x80801B8C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801B90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801B94: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80801B98: nop

    // 0x80801B9C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80801BA0: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80801BA4: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    // 0x80801BA8: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80801BAC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80801BB0: nop

    // 0x80801BB4: bc1f        L_80801BDC
    if (!c1cs) {
        // 0x80801BB8: nop
    
            goto L_80801BDC;
    }
    // 0x80801BB8: nop

    // 0x80801BBC: swc1        $f14, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f14.u32l;
    // 0x80801BC0: b           L_80801BDC
    // 0x80801BC4: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
        goto L_80801BDC;
    // 0x80801BC4: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80801BC8: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
L_80801BCC:
    // 0x80801BCC: lwc1        $f10, 0x5124($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5124));
    // 0x80801BD0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801BD4: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x80801BD8: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
L_80801BDC:
    // 0x80801BDC: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80801BE0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801BE4: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x80801BE8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80801BEC: nop

    // 0x80801BF0: bc1fl       L_80801C08
    if (!c1cs) {
        // 0x80801BF4: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80801C08;
    }
    goto skip_2;
    // 0x80801BF4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_2:
    // 0x80801BF8: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
    // 0x80801BFC: b           L_80801C24
    // 0x80801C00: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
        goto L_80801C24;
    // 0x80801C00: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80801C04: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80801C08:
    // 0x80801C08: nop

    // 0x80801C0C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80801C10: nop

    // 0x80801C14: bc1f        L_80801C24
    if (!c1cs) {
        // 0x80801C18: nop
    
            goto L_80801C24;
    }
    // 0x80801C18: nop

    // 0x80801C1C: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
    // 0x80801C20: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
L_80801C24:
    // 0x80801C24: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80801C28: lwc1        $f18, 0x48($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80801C2C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80801C30: swc1        $f6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f6.u32l;
    // 0x80801C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C3C: jr          $ra
    // 0x80801C40: nop

    return;
    // 0x80801C40: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012B4: jal         0x8009BC6C
    // 0x808012B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x808012B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808012BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808012C0: jal         0x8009BF5C
    // 0x808012C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x808012C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x808012C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808012CC: jal         0x8009C4CC
    // 0x808012D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x808012D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808012D4: jal         0x808000D4
    // 0x808012D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstaxi_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808012D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808012DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012E4: jr          $ra
    // 0x808012E8: nop

    return;
    // 0x808012E8: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080069C: jal         0x800E7188
    // 0x808006A0: nop

    func_800E7188(rdram, ctx);
        goto after_0;
    // 0x808006A0: nop

    after_0:
    // 0x808006A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006AC: jr          $ra
    // 0x808006B0: nop

    return;
    // 0x808006B0: nop

;}
RECOMP_FUNC void func_808004DC_bskazwingwhack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004E8: jal         0x800832E0
    // 0x808004EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808004EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F4: addiu       $a1, $zero, 0x137
    ctx->r5 = ADD32(0, 0X137);
    // 0x808004F8: jal         0x8008CCBC
    // 0x808004FC: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x808004FC: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_1:
    // 0x80800500: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80800504: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800510: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800514: jal         0x8009FFD8
    // 0x80800518: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800518: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80800524: jal         0x8009C99C
    // 0x80800528: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80800528: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_3:
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800530: jal         0x8009BA9C
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080053C: jal         0x8009B9B0
    // 0x80800540: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x80800540: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800544: jal         0x8009E4AC
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_6;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800554: jal         0x8009E5A4
    // 0x80800558: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8009E5A4(rdram, ctx);
        goto after_7;
    // 0x80800558: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800560: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800564: jal         0x8009E55C
    // 0x80800568: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_8009E55C(rdram, ctx);
        goto after_8;
    // 0x80800568: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_8:
    // 0x8080056C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800570: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800574: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800578: jr          $ra
    // 0x8080057C: nop

    return;
    // 0x8080057C: nop

;}
RECOMP_FUNC void func_80800000_fxripple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080000C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800010: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80800014: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800018: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080001C: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80800020: beq         $t7, $zero, L_80800040
    if (ctx->r15 == 0) {
        // 0x80800024: nop
    
            goto L_80800040;
    }
    // 0x80800024: nop

    // 0x80800028: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8080002C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800030: nop

    // 0x80800034: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800038: b           L_8080005C
    // 0x8080003C: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
        goto L_8080005C;
    // 0x8080003C: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
L_80800040:
    // 0x80800040: jal         0x800FB2AC
    // 0x80800044: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800FB2AC(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800048: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080004C: bne         $v0, $zero, L_8080005C
    if (ctx->r2 != 0) {
        // 0x80800050: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8080005C;
    }
    // 0x80800050: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800054: b           L_80800084
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800084;
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080005C:
    // 0x8080005C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800060: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800064: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    // 0x80800068: jal         0x800FB338
    // 0x8080006C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800FB338(rdram, ctx);
        goto after_1;
    // 0x8080006C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800070: beq         $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x80800074: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800080;
    }
    // 0x80800074: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800078: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8080007C: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
L_80800080:
    // 0x80800080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800084:
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800088: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void badust_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800428: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8080042C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800430: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800434: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800438: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8080043C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800440: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800444: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800448: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x8080044C: jal         0x800EFA4C
    // 0x80800450: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800450: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80800454: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x80800458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080045C: jal         0x8009C128
    // 0x80800460: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800460: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x80800464: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800468: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8080046C: jal         0x800EFCD8
    // 0x80800470: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    func_800EFCD8(rdram, ctx);
        goto after_2;
    // 0x80800470: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_2:
    // 0x80800474: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800478: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800484: jal         0x800EF04C
    // 0x80800488: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80800488: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8080048C: jal         0x80088970
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _fxdlsmoke_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800494: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800498: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080049C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808004A0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808004A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808004A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004AC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808004B0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808004B4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808004B8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808004BC: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x808004C0: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808004C4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x808004C8: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x808004CC: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x808004D0: sll         $t3, $a3, 16
    ctx->r11 = S32(ctx->r7 << 16);
    // 0x808004D4: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    // 0x808004D8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x808004DC: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x808004E0: jal         0x800BA930
    // 0x808004E4: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    func_800BA930(rdram, ctx);
        goto after_5;
    // 0x808004E4: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    after_5:
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808004F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808004FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800500: jal         0x800BA450
    // 0x80800504: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800BA450(rdram, ctx);
        goto after_6;
    // 0x80800504: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_6:
    // 0x80800508: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC78) << 16);
    // 0x8080050C: lwc1        $f0, 0xC78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC78));
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800514: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800518: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080051C: jal         0x800BA7C4
    // 0x80800520: nop

    func_800BA7C4(rdram, ctx);
        goto after_7;
    // 0x80800520: nop

    after_7:
    // 0x80800524: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800528: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800530: jal         0x800BA7FC
    // 0x80800534: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    func_800BA7FC(rdram, ctx);
        goto after_8;
    // 0x80800534: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_8:
    // 0x80800538: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x8080053C: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800540: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800544: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800548: jal         0x800BA8F8
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BA8F8(rdram, ctx);
        goto after_9;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800550: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x80800554: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800560: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800564: jal         0x800BA5BC
    // 0x80800568: nop

    func_800BA5BC(rdram, ctx);
        goto after_10;
    // 0x80800568: nop

    after_10:
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: jal         0x800BA22C
    // 0x80800574: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_11;
    // 0x80800574: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800578: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080057C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800580: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800584: jr          $ra
    // 0x80800588: nop

    return;
    // 0x80800588: nop

;}
RECOMP_FUNC void ncba1p_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800888: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8080088C: jr          $ra
    // 0x80800890: lw          $v0, 0x4C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4C);
    return;
    // 0x80800890: lw          $v0, 0x4C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4C);
;}
RECOMP_FUNC void func_80800DC8_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800DD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DD4: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800DD8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1528, 0XF94) << 16);
    // 0x80800DDC: addiu       $t7, $t7, 0xF94
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1528, 0XF94));
    // 0x80800DE0: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80800DE4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800DE8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800DEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DF0: jal         0x800BBCB8
    // 0x80800DF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800DF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800DF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E00: jr          $ra
    // 0x80800E04: nop

    return;
    // 0x80800E04: nop

;}
RECOMP_FUNC void _bsledge_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837E8: syscall     74
    recomp_syscall_handler(rdram, ctx, 0x800837E8);
    return;
    // 0x800837EC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_808015D4_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808015D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015DC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808015E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808015E4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x808015E8: jal         0x80100094
    // 0x808015EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808015EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808015F0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x808015F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808015F8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808015FC: addu        $t6, $v0, $a3
    ctx->r14 = ADD32(ctx->r2, ctx->r7);
    // 0x80801600: lbu         $v1, 0xA($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XA);
    // 0x80801604: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801608: beql        $v1, $zero, L_80801644
    if (ctx->r3 == 0) {
        // 0x8080160C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801644;
    }
    goto skip_0;
    // 0x8080160C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801610: beq         $v1, $at, L_80801634
    if (ctx->r3 == ctx->r1) {
        // 0x80801614: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_80801634;
    }
    // 0x80801614: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80801618: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080161C: bnel        $v1, $at, L_80801644
    if (ctx->r3 != ctx->r1) {
        // 0x80801620: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801644;
    }
    goto skip_1;
    // 0x80801620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801624: jal         0x80800CF8
    // 0x80801628: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800CF8_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x80801628: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8080162C: b           L_80801644
    // 0x80801630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801644;
    // 0x80801630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801634:
    // 0x80801634: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80801638: jal         0x80801578
    // 0x8080163C: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    func_80801578_chcollballcontrol(rdram, ctx);
        goto after_2;
    // 0x8080163C: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    after_2:
    // 0x80801640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801644:
    // 0x80801644: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801648: jr          $ra
    // 0x8080164C: nop

    return;
    // 0x8080164C: nop

;}
RECOMP_FUNC void func_800CD3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD3A8: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800CD3AC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800CD3B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CD3B4: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800CD3B8: lwc1        $f4, -0x4FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4FF0);
    // 0x800CD3BC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800CD3C0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800CD3C4: add.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x800CD3C8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800CD3CC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800CD3D0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800CD3D4: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x800CD3D8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800CD3DC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800CD3E0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800CD3E4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800CD3E8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800CD3EC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800CD3F0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800CD3F4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800CD3F8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800CD3FC: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x800CD400: jal         0x800BD708
    // 0x800CD404: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800BD708(rdram, ctx);
        goto after_0;
    // 0x800CD404: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800CD408: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800CD40C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800CD410: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800CD414: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800CD418: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x800CD41C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800CD420: bne         $at, $zero, L_800CD4E0
    if (ctx->r1 != 0) {
        // 0x800CD424: sw          $t8, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r24;
            goto L_800CD4E0;
    }
    // 0x800CD424: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x800CD428: addiu       $s2, $sp, 0x7C
    ctx->r18 = ADD32(ctx->r29, 0X7C);
    // 0x800CD42C: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x800CD430: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x800CD434: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800CD438: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
L_800CD43C:
    // 0x800CD43C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800CD440: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CD444: bne         $at, $zero, L_800CD4C8
    if (ctx->r1 != 0) {
        // 0x800CD448: sw          $a0, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r4;
            goto L_800CD4C8;
    }
    // 0x800CD448: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800CD44C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
L_800CD450:
    // 0x800CD450: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CD454: bne         $at, $zero, L_800CD4B4
    if (ctx->r1 != 0) {
        // 0x800CD458: sw          $v0, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r2;
            goto L_800CD4B4;
    }
    // 0x800CD458: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x800CD45C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
L_800CD460:
    // 0x800CD460: jal         0x800BDAD4
    // 0x800CD464: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800BDAD4(rdram, ctx);
        goto after_1;
    // 0x800CD464: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800CD468: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800CD46C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CD470: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800CD474: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800CD478: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x800CD47C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CD480: jal         0x800EAA2C
    // 0x800CD484: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_800EAA2C(rdram, ctx);
        goto after_2;
    // 0x800CD484: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_2:
    // 0x800CD488: beql        $v0, $zero, L_800CD498
    if (ctx->r2 == 0) {
        // 0x800CD48C: lw          $v0, 0x84($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X84);
            goto L_800CD498;
    }
    goto skip_0;
    // 0x800CD48C: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    skip_0:
    // 0x800CD490: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800CD494: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
L_800CD498:
    // 0x800CD498: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x800CD49C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CD4A0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CD4A4: beq         $at, $zero, L_800CD460
    if (ctx->r1 == 0) {
        // 0x800CD4A8: sw          $v0, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r2;
            goto L_800CD460;
    }
    // 0x800CD4A8: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x800CD4AC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800CD4B0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
L_800CD4B4:
    // 0x800CD4B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CD4B8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CD4BC: beql        $at, $zero, L_800CD450
    if (ctx->r1 == 0) {
        // 0x800CD4C0: lw          $v0, 0x78($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X78);
            goto L_800CD450;
    }
    goto skip_1;
    // 0x800CD4C0: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    skip_1:
    // 0x800CD4C4: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
L_800CD4C8:
    // 0x800CD4C8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800CD4CC: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800CD4D0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800CD4D4: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CD4D8: beq         $at, $zero, L_800CD43C
    if (ctx->r1 == 0) {
        // 0x800CD4DC: sw          $t1, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r9;
            goto L_800CD43C;
    }
    // 0x800CD4DC: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
L_800CD4E0:
    // 0x800CD4E0: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x800CD4E4: jal         0x800BDC44
    // 0x800CD4E8: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    func_800BDC44(rdram, ctx);
        goto after_3;
    // 0x800CD4E8: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    after_3:
    // 0x800CD4EC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800CD4F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CD4F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800CD4F8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800CD4FC: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x800CD500: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CD504: jal         0x800EAA2C
    // 0x800CD508: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_800EAA2C(rdram, ctx);
        goto after_4;
    // 0x800CD508: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_4:
    // 0x800CD50C: beq         $v0, $zero, L_800CD518
    if (ctx->r2 == 0) {
        // 0x800CD510: ldc1        $f20, 0x28($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
            goto L_800CD518;
    }
    // 0x800CD510: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800CD514: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
L_800CD518:
    // 0x800CD518: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800CD51C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x800CD520: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800CD524: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800CD528: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800CD52C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800CD530: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800CD534: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800CD538: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800CD53C: jr          $ra
    // 0x800CD540: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800CD540: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void _bsbreegullbash_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AF0: syscall     26
    recomp_syscall_handler(rdram, ctx, 0x80082AF0);
    return;
    // 0x80082AF4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855E0: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855E0);
    return;
    // 0x800855E4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800060_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800068: jal         0x80088848
    // 0x8080006C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080006C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800070: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800074: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8080008C;
    }
    // 0x80800074: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800078: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080007C: jal         0x8080094C
    // 0x80800080: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_1;
    // 0x80800080: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_1:
    // 0x80800084: b           L_80800308
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800308;
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080008C:
    // 0x8080008C: jal         0x80100094
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800094: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800098: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x8080009C: jal         0x800D0A9C
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_3;
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808000A4: bne         $v0, $zero, L_808002FC
    if (ctx->r2 != 0) {
        // 0x808000A8: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_808002FC;
    }
    // 0x808000A8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x808000AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808000B0: jal         0x80801654
    // 0x808000B4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80801654_chfantasyathlete(rdram, ctx);
        goto after_4;
    // 0x808000B4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x808000B8: addiu       $a0, $zero, 0x47B
    ctx->r4 = ADD32(0, 0X47B);
    // 0x808000BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808000C0: jal         0x800882C0
    // 0x808000C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x808000C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x808000C8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808000CC: jal         0x80088C00
    // 0x808000D0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808000D0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x808000D4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808000D8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808000DC: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x808000E0: jal         0x80088C00
    // 0x808000E4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808000E4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_7:
    // 0x808000E8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x808000EC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808000F0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808000F4: addiu       $t6, $v0, 0x74
    ctx->r14 = ADD32(ctx->r2, 0X74);
    // 0x808000F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000FC: addiu       $a2, $v0, 0x68
    ctx->r6 = ADD32(ctx->r2, 0X68);
    // 0x80800100: jal         0x808015D8
    // 0x80800104: addiu       $a3, $v0, 0x5C
    ctx->r7 = ADD32(ctx->r2, 0X5C);
    func_808015D8_chfantasyathlete(rdram, ctx);
        goto after_8;
    // 0x80800104: addiu       $a3, $v0, 0x5C
    ctx->r7 = ADD32(ctx->r2, 0X5C);
    after_8:
    // 0x80800108: jal         0x800DA298
    // 0x8080010C: addiu       $a0, $zero, 0x3DD
    ctx->r4 = ADD32(0, 0X3DD);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x8080010C: addiu       $a0, $zero, 0x3DD
    ctx->r4 = ADD32(0, 0X3DD);
    after_9:
    // 0x80800110: beq         $v0, $zero, L_8080013C
    if (ctx->r2 == 0) {
        // 0x80800114: addiu       $a0, $zero, 0x47A
        ctx->r4 = ADD32(0, 0X47A);
            goto L_8080013C;
    }
    // 0x80800114: addiu       $a0, $zero, 0x47A
    ctx->r4 = ADD32(0, 0X47A);
    // 0x80800118: jal         0x800EA090
    // 0x8080011C: nop

    func_800EA090(rdram, ctx);
        goto after_10;
    // 0x8080011C: nop

    after_10:
    // 0x80800120: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800124: beq         $v0, $at, L_80800208
    if (ctx->r2 == ctx->r1) {
        // 0x80800128: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800208;
    }
    // 0x80800128: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080012C: jal         0x8080094C
    // 0x80800130: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_11;
    // 0x80800130: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_11:
    // 0x80800134: b           L_80800208
    // 0x80800138: nop

        goto L_80800208;
    // 0x80800138: nop

L_8080013C:
    // 0x8080013C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800140: jal         0x800882C0
    // 0x80800144: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80800144: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_12:
    // 0x80800148: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080014C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800150: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80800154: jal         0x80088C00
    // 0x80800158: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800158: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_13:
    // 0x8080015C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800160: jal         0x80088C00
    // 0x80800164: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80800164: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_14:
    // 0x80800168: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8080016C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800170: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800174: addiu       $t7, $v0, 0x4C
    ctx->r15 = ADD32(ctx->r2, 0X4C);
    // 0x80800178: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080017C: addiu       $a2, $v0, 0x40
    ctx->r6 = ADD32(ctx->r2, 0X40);
    // 0x80800180: jal         0x808015D8
    // 0x80800184: addiu       $a3, $v0, 0x34
    ctx->r7 = ADD32(ctx->r2, 0X34);
    func_808015D8_chfantasyathlete(rdram, ctx);
        goto after_15;
    // 0x80800184: addiu       $a3, $v0, 0x34
    ctx->r7 = ADD32(ctx->r2, 0X34);
    after_15:
    // 0x80800188: jal         0x800DA298
    // 0x8080018C: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    func_800DA298(rdram, ctx);
        goto after_16;
    // 0x8080018C: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_16:
    // 0x80800190: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x80800194: addiu       $a0, $zero, 0x478
        ctx->r4 = ADD32(0, 0X478);
            goto L_808001BC;
    }
    // 0x80800194: addiu       $a0, $zero, 0x478
    ctx->r4 = ADD32(0, 0X478);
    // 0x80800198: jal         0x800EA090
    // 0x8080019C: nop

    func_800EA090(rdram, ctx);
        goto after_17;
    // 0x8080019C: nop

    after_17:
    // 0x808001A0: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x808001A4: beq         $v0, $at, L_80800208
    if (ctx->r2 == ctx->r1) {
        // 0x808001A8: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800208;
    }
    // 0x808001A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808001AC: jal         0x8080094C
    // 0x808001B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_18;
    // 0x808001B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_18:
    // 0x808001B4: b           L_80800208
    // 0x808001B8: nop

        goto L_80800208;
    // 0x808001B8: nop

L_808001BC:
    // 0x808001BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808001C0: jal         0x800882C0
    // 0x808001C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_19;
    // 0x808001C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_19:
    // 0x808001C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808001CC: jal         0x80088C00
    // 0x808001D0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_20;
    // 0x808001D0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_20:
    // 0x808001D4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808001D8: jal         0x80088C00
    // 0x808001DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x808001DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_21:
    // 0x808001E0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808001E4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808001E8: addiu       $t9, $a1, 0x24
    ctx->r25 = ADD32(ctx->r5, 0X24);
    // 0x808001EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808001F0: addiu       $a2, $a1, 0x18
    ctx->r6 = ADD32(ctx->r5, 0X18);
    // 0x808001F4: jal         0x808015D8
    // 0x808001F8: addiu       $a3, $a1, 0xC
    ctx->r7 = ADD32(ctx->r5, 0XC);
    func_808015D8_chfantasyathlete(rdram, ctx);
        goto after_22;
    // 0x808001F8: addiu       $a3, $a1, 0xC
    ctx->r7 = ADD32(ctx->r5, 0XC);
    after_22:
    // 0x808001FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800200: jal         0x8080094C
    // 0x80800204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_23;
    // 0x80800204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
L_80800208:
    // 0x80800208: jal         0x800EA090
    // 0x8080020C: nop

    func_800EA090(rdram, ctx);
        goto after_24;
    // 0x8080020C: nop

    after_24:
    // 0x80800210: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80800214: bne         $v0, $at, L_8080028C
    if (ctx->r2 != ctx->r1) {
        // 0x80800218: nop
    
            goto L_8080028C;
    }
    // 0x80800218: nop

    // 0x8080021C: jal         0x800F54E4
    // 0x80800220: nop

    func_800F54E4(rdram, ctx);
        goto after_25;
    // 0x80800220: nop

    after_25:
    // 0x80800224: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800228: jal         0x800F608C
    // 0x8080022C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800F608C(rdram, ctx);
        goto after_26;
    // 0x8080022C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_26:
    // 0x80800230: jal         0x800DA298
    // 0x80800234: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    func_800DA298(rdram, ctx);
        goto after_27;
    // 0x80800234: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    after_27:
    // 0x80800238: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x8080023C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8080027C;
    }
    // 0x8080023C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800240: jal         0x800DA298
    // 0x80800244: addiu       $a0, $zero, 0x6D7
    ctx->r4 = ADD32(0, 0X6D7);
    func_800DA298(rdram, ctx);
        goto after_28;
    // 0x80800244: addiu       $a0, $zero, 0x6D7
    ctx->r4 = ADD32(0, 0X6D7);
    after_28:
    // 0x80800248: beq         $v0, $zero, L_80800264
    if (ctx->r2 == 0) {
        // 0x8080024C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800264;
    }
    // 0x8080024C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800250: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800254: jal         0x8080094C
    // 0x80800258: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_29;
    // 0x80800258: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_29:
    // 0x8080025C: b           L_8080026C
    // 0x80800260: nop

        goto L_8080026C;
    // 0x80800260: nop

L_80800264:
    // 0x80800264: jal         0x8080094C
    // 0x80800268: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_30;
    // 0x80800268: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_30:
L_8080026C:
    // 0x8080026C: jal         0x800DA524
    // 0x80800270: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    func_800DA524(rdram, ctx);
        goto after_31;
    // 0x80800270: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    after_31:
    // 0x80800274: b           L_80800308
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800308;
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080027C:
    // 0x8080027C: jal         0x8080094C
    // 0x80800280: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_32;
    // 0x80800280: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_32:
    // 0x80800284: b           L_80800308
    // 0x80800288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800308;
    // 0x80800288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080028C:
    // 0x8080028C: jal         0x800EA090
    // 0x80800290: nop

    func_800EA090(rdram, ctx);
        goto after_33;
    // 0x80800290: nop

    after_33:
    // 0x80800294: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800298: bnel        $v0, $at, L_80800308
    if (ctx->r2 != ctx->r1) {
        // 0x8080029C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800308;
    }
    goto skip_0;
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002A0: jal         0x800DA298
    // 0x808002A4: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    func_800DA298(rdram, ctx);
        goto after_34;
    // 0x808002A4: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    after_34:
    // 0x808002A8: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808002AC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808002EC;
    }
    // 0x808002AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808002B0: jal         0x800DA298
    // 0x808002B4: addiu       $a0, $zero, 0x6D7
    ctx->r4 = ADD32(0, 0X6D7);
    func_800DA298(rdram, ctx);
        goto after_35;
    // 0x808002B4: addiu       $a0, $zero, 0x6D7
    ctx->r4 = ADD32(0, 0X6D7);
    after_35:
    // 0x808002B8: beq         $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808002BC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808002D4;
    }
    // 0x808002BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808002C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808002C4: jal         0x8080094C
    // 0x808002C8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_36;
    // 0x808002C8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_36:
    // 0x808002CC: b           L_808002DC
    // 0x808002D0: nop

        goto L_808002DC;
    // 0x808002D0: nop

L_808002D4:
    // 0x808002D4: jal         0x8080094C
    // 0x808002D8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_37;
    // 0x808002D8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_37:
L_808002DC:
    // 0x808002DC: jal         0x800DA524
    // 0x808002E0: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    func_800DA524(rdram, ctx);
        goto after_38;
    // 0x808002E0: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    after_38:
    // 0x808002E4: b           L_80800308
    // 0x808002E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800308;
    // 0x808002E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002EC:
    // 0x808002EC: jal         0x8080094C
    // 0x808002F0: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_39;
    // 0x808002F0: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_39:
    // 0x808002F4: b           L_80800308
    // 0x808002F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800308;
    // 0x808002F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002FC:
    // 0x808002FC: jal         0x800FFA88
    // 0x80800300: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_40;
    // 0x80800300: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_40:
    // 0x80800304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800308:
    // 0x80800308: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080030C: jr          $ra
    // 0x80800310: nop

    return;
    // 0x80800310: nop

;}
RECOMP_FUNC void func_800A4878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4878: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A487C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A4880: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4884: jal         0x800A4CA8
    // 0x800A4888: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x800A4888: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A488C: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x800A4890: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800A4894: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A4898: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x800A489C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A48A0: beq         $t7, $zero, L_800A48B8
    if (ctx->r15 == 0) {
        // 0x800A48A4: nop
    
            goto L_800A48B8;
    }
    // 0x800A48A4: nop

    // 0x800A48A8: jal         0x80110EFC
    // 0x800A48AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110EFC(rdram, ctx);
        goto after_1;
    // 0x800A48AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A48B0: b           L_800A4968
    // 0x800A48B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A4968;
    // 0x800A48B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A48B8:
    // 0x800A48B8: jal         0x800A4D40
    // 0x800A48BC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800A4D40(rdram, ctx);
        goto after_2;
    // 0x800A48BC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x800A48C0: beq         $v0, $zero, L_800A48F8
    if (ctx->r2 == 0) {
        // 0x800A48C4: nop
    
            goto L_800A48F8;
    }
    // 0x800A48C4: nop

    // 0x800A48C8: jal         0x8009CC68
    // 0x800A48CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CC68(rdram, ctx);
        goto after_3;
    // 0x800A48CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800A48D0: bne         $v0, $zero, L_800A48F8
    if (ctx->r2 != 0) {
        // 0x800A48D4: nop
    
            goto L_800A48F8;
    }
    // 0x800A48D4: nop

    // 0x800A48D8: jal         0x800F65D0
    // 0x800A48DC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F65D0(rdram, ctx);
        goto after_4;
    // 0x800A48DC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_4:
    // 0x800A48E0: beq         $v0, $zero, L_800A48F8
    if (ctx->r2 == 0) {
        // 0x800A48E4: nop
    
            goto L_800A48F8;
    }
    // 0x800A48E4: nop

    // 0x800A48E8: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x800A48EC: lbu         $t9, 0x3B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3B);
    // 0x800A48F0: beq         $t9, $zero, L_800A4900
    if (ctx->r25 == 0) {
        // 0x800A48F4: nop
    
            goto L_800A4900;
    }
    // 0x800A48F4: nop

L_800A48F8:
    // 0x800A48F8: b           L_800A4964
    // 0x800A48FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A4964;
    // 0x800A48FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A4900:
    // 0x800A4900: jal         0x80097B4C
    // 0x800A4904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097B4C(rdram, ctx);
        goto after_5;
    // 0x800A4904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800A4908: beq         $v0, $zero, L_800A4920
    if (ctx->r2 == 0) {
        // 0x800A490C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800A4920;
    }
    // 0x800A490C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A4910: jal         0x80110EFC
    // 0x800A4914: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80110EFC(rdram, ctx);
        goto after_6;
    // 0x800A4914: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x800A4918: b           L_800A4968
    // 0x800A491C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A4968;
    // 0x800A491C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4920:
    // 0x800A4920: jal         0x80097B70
    // 0x800A4924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_rotate_camera_left(rdram, ctx);
        goto after_7;
    // 0x800A4924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800A4928: beq         $v0, $zero, L_800A4940
    if (ctx->r2 == 0) {
        // 0x800A492C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800A4940;
    }
    // 0x800A492C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A4930: jal         0x80110EFC
    // 0x800A4934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80110EFC(rdram, ctx);
        goto after_8;
    // 0x800A4934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800A4938: b           L_800A4968
    // 0x800A493C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A4968;
    // 0x800A493C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4940:
    // 0x800A4940: jal         0x80097B94
    // 0x800A4944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_rotate_camera_right(rdram, ctx);
        goto after_9;
    // 0x800A4944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800A4948: beq         $v0, $zero, L_800A4960
    if (ctx->r2 == 0) {
        // 0x800A494C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800A4960;
    }
    // 0x800A494C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A4950: jal         0x80110EFC
    // 0x800A4954: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80110EFC(rdram, ctx);
        goto after_10;
    // 0x800A4954: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x800A4958: b           L_800A4968
    // 0x800A495C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A4968;
    // 0x800A495C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4960:
    // 0x800A4960: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A4964:
    // 0x800A4964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4968:
    // 0x800A4968: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A496C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A4970: jr          $ra
    // 0x800A4974: nop

    return;
    // 0x800A4974: nop

;}
RECOMP_FUNC void func_800F58F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F58F8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F58FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5900: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5908: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F590C: jal         0x800A3354
    // 0x800F5910: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A3354(rdram, ctx);
        goto after_0;
    // 0x800F5910: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F591C: jr          $ra
    // 0x800F5920: nop

    return;
    // 0x800F5920: nop

;}
RECOMP_FUNC void func_8010D790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D790: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8010D794: addiu       $a0, $a0, 0x4730
    ctx->r4 = ADD32(ctx->r4, 0X4730);
    // 0x8010D798: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010D79C: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x8010D7A0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8010D7A4:
    // 0x8010D7A4: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x8010D7A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010D7AC: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8010D7B0: blez        $a1, L_8010D7D8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8010D7B4: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_8010D7D8;
    }
    // 0x8010D7B4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010D7B8: addiu       $t7, $t7, 0x6F90
    ctx->r15 = ADD32(ctx->r15, 0X6F90);
    // 0x8010D7BC: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
L_8010D7C0:
    // 0x8010D7C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8010D7C4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8010D7C8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8010D7CC: sb          $zero, -0x8($a2)
    MEM_B(-0X8, ctx->r6) = 0;
    // 0x8010D7D0: bne         $at, $zero, L_8010D7C0
    if (ctx->r1 != 0) {
        // 0x8010D7D4: sw          $a3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r7;
            goto L_8010D7C0;
    }
    // 0x8010D7D4: sw          $a3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r7;
L_8010D7D8:
    // 0x8010D7D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8010D7DC: bne         $v0, $t0, L_8010D7A4
    if (ctx->r2 != ctx->r8) {
        // 0x8010D7E0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8010D7A4;
    }
    // 0x8010D7E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8010D7E4: jr          $ra
    // 0x8010D7E8: nop

    return;
    // 0x8010D7E8: nop

;}
RECOMP_FUNC void func_8080012C_fxstep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800130: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800134: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800138: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080013C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800140: lbu         $t6, 0x26($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X26);
    // 0x80800144: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80800148: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080014C: beq         $t6, $zero, L_8080015C
    if (ctx->r14 == 0) {
        // 0x80800150: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_8080015C;
    }
    // 0x80800150: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800154: b           L_80800160
    // 0x80800158: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_80800160;
    // 0x80800158: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8080015C:
    // 0x8080015C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
L_80800160:
    // 0x80800160: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800164: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800168: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080016C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800170: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800174: jal         0x800DC178
    // 0x80800178: add.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800178: add.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f0.fl;
    after_0:
    // 0x8080017C: lbu         $v0, 0x26($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X26);
    // 0x80800180: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800184: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800188: beq         $v0, $zero, L_80800198
    if (ctx->r2 == 0) {
        // 0x8080018C: addiu       $a1, $s1, 0x4
        ctx->r5 = ADD32(ctx->r17, 0X4);
            goto L_80800198;
    }
    // 0x8080018C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80800190: b           L_80800198
    // 0x80800194: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
        goto L_80800198;
    // 0x80800194: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
L_80800198:
    // 0x80800198: beql        $v0, $zero, L_808001AC
    if (ctx->r2 == 0) {
        // 0x8080019C: lbu         $s0, 0x25($s1)
        ctx->r16 = MEM_BU(ctx->r17, 0X25);
            goto L_808001AC;
    }
    goto skip_0;
    // 0x8080019C: lbu         $s0, 0x25($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X25);
    skip_0:
    // 0x808001A0: b           L_808001AC
    // 0x808001A4: lbu         $s0, 0x24($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X24);
        goto L_808001AC;
    // 0x808001A4: lbu         $s0, 0x24($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X24);
    // 0x808001A8: lbu         $s0, 0x25($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X25);
L_808001AC:
    // 0x808001AC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x808001B0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x808001B4: jal         0x800C35E8
    // 0x808001B8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800C35E8(rdram, ctx);
        goto after_1;
    // 0x808001B8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x808001BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001C0: jal         0x800C301C
    // 0x808001C4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C301C(rdram, ctx);
        goto after_2;
    // 0x808001C4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x808001C8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808001CC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x808001D0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808001D4: jal         0x800C31DC
    // 0x808001D8: nop

    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x808001D8: nop

    after_3:
    // 0x808001DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x808001E0: jal         0x800C3058
    // 0x808001E4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800C3058(rdram, ctx);
        goto after_4;
    // 0x808001E4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x808001E8: jal         0x800C3BDC
    // 0x808001EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C3BDC(rdram, ctx);
        goto after_5;
    // 0x808001EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_5:
    // 0x808001F0: lbu         $t7, 0x26($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X26);
    // 0x808001F4: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x808001F8: sb          $t8, 0x26($s1)
    MEM_B(0X26, ctx->r17) = ctx->r24;
    // 0x808001FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800200: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800204: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800208: jr          $ra
    // 0x8080020C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080020C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080A03C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080A03C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8080A040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080A044: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080A048: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x8080A04C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8080A050: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8080A054: jal         0x800F3BB0
    // 0x8080A058: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    func_800F3BB0(rdram, ctx);
        goto after_0;
    // 0x8080A058: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8080A05C: lw          $s0, 0x6C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X6C);
    // 0x8080A060: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8080A064: lwc1        $f4, 0x29C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X29C);
    // 0x8080A068: addiu       $s0, $s0, 0x254
    ctx->r16 = ADD32(ctx->r16, 0X254);
    // 0x8080A06C: jal         0x8009C984
    // 0x8080A070: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x8080A070: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080A074: jal         0x800137F4
    // 0x8080A078: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800137F4(rdram, ctx);
        goto after_2;
    // 0x8080A078: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x8080A07C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080A080: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8080A084: jal         0x80013788
    // 0x8080A088: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    func_80013788(rdram, ctx);
        goto after_3;
    // 0x8080A088: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8080A08C: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x8080A090: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8080A094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080A098: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8080A09C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8080A0A0: jal         0x800EE7B4
    // 0x8080A0A4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    func_800EE7B4(rdram, ctx);
        goto after_4;
    // 0x8080A0A4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x8080A0A8: addiu       $a1, $s0, 0x2C
    ctx->r5 = ADD32(ctx->r16, 0X2C);
    // 0x8080A0AC: addiu       $a2, $s0, 0x38
    ctx->r6 = ADD32(ctx->r16, 0X38);
    // 0x8080A0B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080A0B4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8080A0B8: jal         0x80809EF8
    // 0x8080A0BC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80809EF8_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x8080A0BC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_5:
    // 0x8080A0C0: beq         $v0, $zero, L_8080A138
    if (ctx->r2 == 0) {
        // 0x8080A0C4: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8080A138;
    }
    // 0x8080A0C4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8080A0C8: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8080A0CC: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8080A0D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080A0D4: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x8080A0D8: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x8080A0DC: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8080A0E0: jal         0x800EF030
    // 0x8080A0E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EF030(rdram, ctx);
        goto after_6;
    // 0x8080A0E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x8080A0E8: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA5AC) << 16);
    // 0x8080A0EC: lwc1        $f8, -0x5A54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA5AC));
    // 0x8080A0F0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080A0F4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8080A0F8: nop

    // 0x8080A0FC: bc1f        L_8080A120
    if (!c1cs) {
        // 0x8080A100: nop
    
            goto L_8080A120;
    }
    // 0x8080A100: nop

    // 0x8080A104: beq         $v0, $zero, L_8080A118
    if (ctx->r2 == 0) {
        // 0x8080A108: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8080A118;
    }
    // 0x8080A108: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080A10C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8080A110: b           L_8080A140
    // 0x8080A114: sw          $t9, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r25;
        goto L_8080A140;
    // 0x8080A114: sw          $t9, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r25;
L_8080A118:
    // 0x8080A118: b           L_8080A140
    // 0x8080A11C: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
        goto L_8080A140;
    // 0x8080A11C: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
L_8080A120:
    // 0x8080A120: beq         $v0, $zero, L_8080A130
    if (ctx->r2 == 0) {
        // 0x8080A124: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_8080A130;
    }
    // 0x8080A124: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8080A128: b           L_8080A140
    // 0x8080A12C: sw          $t1, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r9;
        goto L_8080A140;
    // 0x8080A12C: sw          $t1, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r9;
L_8080A130:
    // 0x8080A130: b           L_8080A140
    // 0x8080A134: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
        goto L_8080A140;
    // 0x8080A134: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_8080A138:
    // 0x8080A138: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x8080A13C: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_8080A140:
    // 0x8080A140: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080A144: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080A148: jal         0x800EFB24
    // 0x8080A14C: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x8080A14C: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_7:
    // 0x8080A150: jal         0x800EEFFC
    // 0x8080A154: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EEFFC(rdram, ctx);
        goto after_8;
    // 0x8080A154: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_8:
    // 0x8080A158: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080A15C: jal         0x80013B7C
    // 0x8080A160: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_80013B7C(rdram, ctx);
        goto after_9;
    // 0x8080A160: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_9:
    // 0x8080A164: jal         0x80013728
    // 0x8080A168: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_10;
    // 0x8080A168: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_10:
    // 0x8080A16C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080A170: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080A174: jal         0x800F0DC0
    // 0x8080A178: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F0DC0(rdram, ctx);
        goto after_11;
    // 0x8080A178: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_11:
    // 0x8080A17C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x8080A180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080A184: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080A188: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8080A18C: jr          $ra
    // 0x8080A190: nop

    return;
    // 0x8080A190: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E58: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E58);
    return;
    // 0x80083E5C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_808000C4_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000DC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000E0: beq         $t6, $at, L_808000FC
    if (ctx->r14 == ctx->r1) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000FC;
    }
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000EC: beq         $t6, $at, L_80800230
    if (ctx->r14 == ctx->r1) {
        // 0x808000F0: nop
    
            goto L_80800230;
    }
    // 0x808000F0: nop

    // 0x808000F4: b           L_8080025C
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080025C;
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000FC:
    // 0x808000FC: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x80800100: jal         0x8010B990
    // 0x80800104: ori         $a1, $a1, 0x4007
    ctx->r5 = ctx->r5 | 0X4007;
    func_8010B990(rdram, ctx);
        goto after_0;
    // 0x80800104: ori         $a1, $a1, 0x4007
    ctx->r5 = ctx->r5 | 0X4007;
    after_0:
    // 0x80800108: jal         0x800D8FF8
    // 0x8080010C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080010C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800110: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800114: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800118: addiu       $t1, $zero, 0x95D
    ctx->r9 = ADD32(0, 0X95D);
    // 0x8080011C: addiu       $t0, $zero, 0x95C
    ctx->r8 = ADD32(0, 0X95C);
    // 0x80800120: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800124: bgez        $t9, L_80800134
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800134;
    }
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: b           L_80800138
    // 0x80800130: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
        goto L_80800138;
    // 0x80800130: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80800134:
    // 0x80800134: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80800138:
    // 0x80800138: jal         0x808007EC
    // 0x8080013C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808007EC_chphlegm(rdram, ctx);
        goto after_2;
    // 0x8080013C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800140: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800144: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800148: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080014C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800150: jal         0x800136E4
    // 0x80800154: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x80800154: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_3:
    // 0x80800158: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x8080015C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800160: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800164: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800168: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080016C: jal         0x800136E4
    // 0x80800170: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x80800170: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_4:
    // 0x80800174: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800178: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    // 0x80800184: andi        $t3, $t2, 0x28
    ctx->r11 = ctx->r10 & 0X28;
    // 0x80800188: beql        $t3, $zero, L_808001D4
    if (ctx->r11 == 0) {
        // 0x8080018C: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_808001D4;
    }
    goto skip_0;
    // 0x8080018C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80800190: jal         0x80800748
    // 0x80800194: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80800748_chphlegm(rdram, ctx);
        goto after_5;
    // 0x80800194: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80800198: jal         0x8010A570
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x80101FDC
    // 0x808001A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808001A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808001AC: jal         0x80089CA8
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001B4: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x808001C0: bgezl       $t6, L_808001D4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808001C4: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_808001D4;
    }
    goto skip_1;
    // 0x808001C4: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x808001C8: jal         0x80108B04
    // 0x808001CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_9;
    // 0x808001CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808001D0: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_808001D4:
    // 0x808001D4: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x808001D8: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x808001DC: bltzl       $t9, L_8080025C
    if (SIGNED(ctx->r25) < 0) {
        // 0x808001E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080025C;
    }
    goto skip_2;
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808001E4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808001E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001EC: nop

    // 0x808001F0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x808001F4: nop

    // 0x808001F8: bc1t        L_80800220
    if (c1cs) {
        // 0x808001FC: nop
    
            goto L_80800220;
    }
    // 0x808001FC: nop

    // 0x80800200: jal         0x800EEF94
    // 0x80800204: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EEF94(rdram, ctx);
        goto after_10;
    // 0x80800204: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80800208: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1064, 0XB30) << 16);
    // 0x8080020C: lwc1        $f16, 0xB30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1064, 0XB30));
    // 0x80800210: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800214: nop

    // 0x80800218: bc1fl       L_8080025C
    if (!c1cs) {
        // 0x8080021C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080025C;
    }
    goto skip_3;
    // 0x8080021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_80800220:
    // 0x80800220: jal         0x800FFAB0
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_11;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800228: b           L_8080025C
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080025C;
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800230:
    // 0x80800230: jal         0x800D8FF8
    // 0x80800234: nop

    func_800D8FF8(rdram, ctx);
        goto after_12;
    // 0x80800234: nop

    after_12:
    // 0x80800238: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080023C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800240: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800244: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800248: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080024C: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80800250: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800254: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080025C:
    // 0x8080025C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800260: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800264: jr          $ra
    // 0x80800268: nop

    return;
    // 0x80800268: nop

;}
RECOMP_FUNC void func_80800E10_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E18: jal         0x80100094
    // 0x80800E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E20: jal         0x800C2E04
    // 0x80800E24: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C2E04(rdram, ctx);
        goto after_1;
    // 0x80800E24: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800E28: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E2C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800E30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800E34: jal         0x800C330C
    // 0x80800E38: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    func_800C330C(rdram, ctx);
        goto after_2;
    // 0x80800E38: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    after_2:
    // 0x80800E3C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E44: jal         0x800C431C
    // 0x80800E48: lbu         $a0, 0xC($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0XC);
    func_800C431C(rdram, ctx);
        goto after_3;
    // 0x80800E48: lbu         $a0, 0xC($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0XC);
    after_3:
    // 0x80800E4C: jal         0x8008A2F8
    // 0x80800E50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800E50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80800E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E5C: jr          $ra
    // 0x80800E60: nop

    return;
    // 0x80800E60: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6B0: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6B0);
    return;
    // 0x8008A6B4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chboggy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087178: syscall     526
    recomp_syscall_handler(rdram, ctx, 0x80087178);
    return;
    // 0x8008717C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A5214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A521C: jal         0x800F54E4
    // 0x800A5220: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800A5220: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A5224: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A5228: jal         0x800878D0
    // 0x800A522C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _plcamera_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800A522C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A5230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5238: jr          $ra
    // 0x800A523C: nop

    return;
    // 0x800A523C: nop

;}
RECOMP_FUNC void func_80801114_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801114: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801118: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8080111C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801124: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80801128: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8080112C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80801130: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801134: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80801138: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080113C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80801140: jal         0x800F00A4
    // 0x80801144: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800F00A4(rdram, ctx);
        goto after_0;
    // 0x80801144: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80801148: beq         $v0, $zero, L_808011C4
    if (ctx->r2 == 0) {
        // 0x8080114C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808011C4;
    }
    // 0x8080114C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801150: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801154: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80801158: jal         0x800EFB24
    // 0x8080115C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x8080115C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80801160: jal         0x800EF2A0
    // 0x80801164: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EF2A0(rdram, ctx);
        goto after_2;
    // 0x80801164: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80801168: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080116C: jal         0x800F1CF0
    // 0x80801170: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F1CF0(rdram, ctx);
        goto after_3;
    // 0x80801170: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80801174: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080117C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80801180: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80801184: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80801188: bc1f        L_80801194
    if (!c1cs) {
        // 0x8080118C: nop
    
            goto L_80801194;
    }
    // 0x8080118C: nop

    // 0x80801190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801194:
    // 0x80801194: beq         $v0, $zero, L_808011B8
    if (ctx->r2 == 0) {
        // 0x80801198: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808011B8;
    }
    // 0x80801198: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080119C: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x808011A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808011A4: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x808011A8: nop

    // 0x808011AC: bc1fl       L_808011BC
    if (!c1cs) {
        // 0x808011B0: swc1        $f0, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
            goto L_808011BC;
    }
    goto skip_0;
    // 0x808011B0: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    skip_0:
    // 0x808011B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808011B8:
    // 0x808011B8: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
L_808011BC:
    // 0x808011BC: b           L_808011D4
    // 0x808011C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808011D4;
    // 0x808011C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808011C4:
    // 0x808011C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808011C8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x808011CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808011D0: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
L_808011D4:
    // 0x808011D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808011DC: jr          $ra
    // 0x808011E0: nop

    return;
    // 0x808011E0: nop

;}
RECOMP_FUNC void func_80800C18_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C20: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800C24: jal         0x80106790
    // 0x80800C28: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800C28: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80800C2C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800C30: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800C34: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(824, 0XE24) << 16);
    // 0x80800C38: addiu       $t7, $t7, 0xE24
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(824, 0XE24));
    // 0x80800C3C: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    // 0x80800C40: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x80800C44: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800C48: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800C4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800C50: jal         0x800BABB8
    // 0x80800C54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800C54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800C58: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(824, 0XE64) << 16);
    // 0x80800C5C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800C60: addiu       $a2, $a2, 0xE64
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(824, 0XE64));
    // 0x80800C64: jal         0x80089D18
    // 0x80800C68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800C68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800C6C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80800C70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C78: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800C7C: jal         0x800D1000
    // 0x80800C80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_3;
    // 0x80800C80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80800C84: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800C88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C8C: jal         0x800CEAA8
    // 0x80800C90: sw          $zero, 0x50($t8)
    MEM_W(0X50, ctx->r24) = 0;
    func_800CEAA8(rdram, ctx);
        goto after_4;
    // 0x80800C90: sw          $zero, 0x50($t8)
    MEM_W(0X50, ctx->r24) = 0;
    after_4:
    // 0x80800C94: beq         $v0, $zero, L_80800CA4
    if (ctx->r2 == 0) {
        // 0x80800C98: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800CA4;
    }
    // 0x80800C98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C9C: jal         0x800CE88C
    // 0x80800CA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_5;
    // 0x80800CA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_80800CA4:
    // 0x80800CA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CAC: jr          $ra
    // 0x80800CB0: nop

    return;
    // 0x80800CB0: nop

    // 0x80800CB4: nop

    // 0x80800CB8: nop

    // 0x80800CBC: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AA0: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AA0);
    return;
    // 0x80089AA4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800AB980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AB984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AB988: jal         0x8001ACCC
    // 0x800AB98C: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800AB98C: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    after_0:
    // 0x800AB990: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800AB994: addiu       $v1, $v1, 0x798C
    ctx->r3 = ADD32(ctx->r3, 0X798C);
    // 0x800AB998: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800AB99C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800AB9A0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AB9A4: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x800AB9A8: lui         $t0, 0x4000
    ctx->r8 = S32(0X4000 << 16);
    // 0x800AB9AC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800AB9B0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800AB9B4: sw          $t8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r24;
    // 0x800AB9B8: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800AB9BC: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x800AB9C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AB9C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AB9C8: jr          $ra
    // 0x800AB9CC: nop

    return;
    // 0x800AB9CC: nop

;}
RECOMP_FUNC void _bsmumattack_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083870: syscall     76
    recomp_syscall_handler(rdram, ctx, 0x80083870);
    return;
    // 0x80083874: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _babuzz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084790: syscall     120
    recomp_syscall_handler(rdram, ctx, 0x80084790);
    return;
    // 0x80084794: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void yaw_setVelocityBounded(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C99C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009C9A0: lw          $t6, 0xF8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C9A4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8009C9A8: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
    // 0x8009C9AC: lw          $t7, 0xF8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C9B0: jr          $ra
    // 0x8009C9B4: swc1        $f14, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x8009C9B4: swc1        $f14, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_8009CDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CDE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009CDE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009CDE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CDEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009CDF0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8009CDF4: beq         $a1, $at, L_8009CE28
    if (ctx->r5 == ctx->r1) {
        // 0x8009CDF8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8009CE28;
    }
    // 0x8009CDF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009CDFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009CE00: beq         $a1, $at, L_8009CE54
    if (ctx->r5 == ctx->r1) {
        // 0x8009CE04: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8009CE54;
    }
    // 0x8009CE04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009CE08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009CE0C: beq         $a1, $at, L_8009CE7C
    if (ctx->r5 == ctx->r1) {
        // 0x8009CE10: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8009CE7C;
    }
    // 0x8009CE10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009CE14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009CE18: beq         $a1, $at, L_8009CEA4
    if (ctx->r5 == ctx->r1) {
        // 0x8009CE1C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8009CEA4;
    }
    // 0x8009CE1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009CE20: b           L_8009CEC8
    // 0x8009CE24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8009CEC8;
    // 0x8009CE24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8009CE28:
    // 0x8009CE28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009CE2C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8009CE30: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8009CE34: jal         0x8009E7C8
    // 0x8009CE38: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8009E7C8(rdram, ctx);
        goto after_0;
    // 0x8009CE38: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x8009CE3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009CE40: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CE44: bne         $v0, $at, L_8009CEC8
    if (ctx->r2 != ctx->r1) {
        // 0x8009CE48: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8009CEC8;
    }
    // 0x8009CE48: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8009CE4C: b           L_8009CEC8
    // 0x8009CE50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8009CEC8;
    // 0x8009CE50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8009CE54:
    // 0x8009CE54: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8009CE58: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8009CE5C: jal         0x8009E7C8
    // 0x8009CE60: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8009E7C8(rdram, ctx);
        goto after_1;
    // 0x8009CE60: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x8009CE64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009CE68: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CE6C: bne         $v0, $at, L_8009CEC8
    if (ctx->r2 != ctx->r1) {
        // 0x8009CE70: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8009CEC8;
    }
    // 0x8009CE70: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8009CE74: b           L_8009CEC8
    // 0x8009CE78: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8009CEC8;
    // 0x8009CE78: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8009CE7C:
    // 0x8009CE7C: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x8009CE80: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8009CE84: jal         0x8009E7C8
    // 0x8009CE88: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x8009CE88: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x8009CE8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009CE90: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CE94: bne         $v0, $at, L_8009CEC8
    if (ctx->r2 != ctx->r1) {
        // 0x8009CE98: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8009CEC8;
    }
    // 0x8009CE98: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8009CE9C: b           L_8009CEC8
    // 0x8009CEA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8009CEC8;
    // 0x8009CEA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8009CEA4:
    // 0x8009CEA4: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    // 0x8009CEA8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8009CEAC: jal         0x8009E7C8
    // 0x8009CEB0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8009E7C8(rdram, ctx);
        goto after_3;
    // 0x8009CEB0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x8009CEB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009CEB8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CEBC: bne         $v0, $at, L_8009CEC8
    if (ctx->r2 != ctx->r1) {
        // 0x8009CEC0: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8009CEC8;
    }
    // 0x8009CEC0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8009CEC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8009CEC8:
    // 0x8009CEC8: beq         $v1, $zero, L_8009CED8
    if (ctx->r3 == 0) {
        // 0x8009CECC: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_8009CED8;
    }
    // 0x8009CECC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8009CED0: lw          $t7, 0xF0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XF0);
    // 0x8009CED4: sb          $a2, 0x81($t7)
    MEM_B(0X81, ctx->r15) = ctx->r6;
L_8009CED8:
    // 0x8009CED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CEDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009CEE0: jr          $ra
    // 0x8009CEE4: nop

    return;
    // 0x8009CEE4: nop

;}
RECOMP_FUNC void func_800C08C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C08C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C08C4: lw          $a0, -0x7510($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7510);
    // 0x800C08C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C08CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C08D0: beql        $a0, $zero, L_800C08EC
    if (ctx->r4 == 0) {
        // 0x800C08D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C08EC;
    }
    goto skip_0;
    // 0x800C08D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C08D8: jal         0x8001BAFC
    // 0x800C08DC: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800C08DC: nop

    after_0:
    // 0x800C08E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C08E4: sw          $v0, -0x7510($at)
    MEM_W(-0X7510, ctx->r1) = ctx->r2;
    // 0x800C08E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C08EC:
    // 0x800C08EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C08F0: jr          $ra
    // 0x800C08F4: nop

    return;
    // 0x800C08F4: nop

;}
RECOMP_FUNC void func_8080000C_chstarspinnerstar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800018: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080001C: jal         0x800D8FF8
    // 0x80800020: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800020: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800024: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800028: jal         0x800DA298
    // 0x8080002C: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    after_1:
    // 0x80800030: sltu        $s0, $zero, $v0
    ctx->r16 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800034: bnel        $s0, $zero, L_8080004C
    if (ctx->r16 != 0) {
        // 0x80800038: sw          $s0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r16;
            goto L_8080004C;
    }
    goto skip_0;
    // 0x80800038: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    skip_0:
    // 0x8080003C: jal         0x80088848
    // 0x80800040: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800040: nop

    after_2:
    // 0x80800044: sltu        $s0, $zero, $v0
    ctx->r16 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800048: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
L_8080004C:
    // 0x8080004C: jal         0x80800660
    // 0x80800050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800660_chstarspinnerstar(rdram, ctx);
        goto after_3;
    // 0x80800050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800058: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080005C: jal         0x80085E20
    // 0x80800060: lw          $a2, 0x30($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X30);
    _chstarspinnerctrl_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800060: lw          $a2, 0x30($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X30);
    after_4:
    // 0x80800064: lhu         $s0, 0x72($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X72);
    // 0x80800068: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
    // 0x8080006C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800070: srl         $t6, $s0, 10
    ctx->r14 = S32(U32(ctx->r16) >> 10);
    // 0x80800074: beq         $t6, $at, L_8080009C
    if (ctx->r14 == ctx->r1) {
        // 0x80800078: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_8080009C;
    }
    // 0x80800078: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8080007C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800080: beq         $t6, $at, L_808000DC
    if (ctx->r14 == ctx->r1) {
        // 0x80800084: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000DC;
    }
    // 0x80800084: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800088: beq         $t6, $at, L_808001CC
    if (ctx->r14 == ctx->r1) {
        // 0x8080008C: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_808001CC;
    }
    // 0x8080008C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80800090: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800094: b           L_80800274
    // 0x80800098: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80800274;
    // 0x80800098: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8080009C:
    // 0x8080009C: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000A0: beq         $t8, $zero, L_80800274
    if (ctx->r24 == 0) {
        // 0x808000A4: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80800274;
    }
    // 0x808000A4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x808000A8: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x808000AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808000B4: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x808000B8: bgezl       $t1, L_80800278
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808000BC: lbu         $t2, 0x65($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X65);
            goto L_80800278;
    }
    goto skip_1;
    // 0x808000BC: lbu         $t2, 0x65($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X65);
    skip_1:
    // 0x808000C0: jal         0x80101FDC
    // 0x808000C4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x808000C4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    after_5:
    // 0x808000C8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808000CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000D0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x808000D4: b           L_80800274
    // 0x808000D8: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
        goto L_80800274;
    // 0x808000D8: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
L_808000DC:
    // 0x808000DC: jal         0x800DA298
    // 0x808000E0: addiu       $a0, $zero, 0x679
    ctx->r4 = ADD32(0, 0X679);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808000E0: addiu       $a0, $zero, 0x679
    ctx->r4 = ADD32(0, 0X679);
    after_6:
    // 0x808000E4: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000E8: addiu       $s0, $zero, 0x50
        ctx->r16 = ADD32(0, 0X50);
            goto L_808000F4;
    }
    // 0x808000E8: addiu       $s0, $zero, 0x50
    ctx->r16 = ADD32(0, 0X50);
    // 0x808000EC: b           L_808000F4
    // 0x808000F0: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
        goto L_808000F4;
    // 0x808000F0: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
L_808000F4:
    // 0x808000F4: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x808000F8: lwc1        $f10, 0x28($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X28);
    // 0x808000FC: lwc1        $f16, 0x48($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80800100: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800104: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800108: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x8080010C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800110: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800114: jal         0x800136E4
    // 0x80800118: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x80800118: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_7:
    // 0x8080011C: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x80800120: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800124: jal         0x80800454
    // 0x80800128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800454_chstarspinnerstar(rdram, ctx);
        goto after_8;
    // 0x80800128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8080012C: lw          $t2, 0x64($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X64);
    // 0x80800130: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80800134: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800138: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x8080013C: bgez        $t4, L_8080014C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800140: sltu        $t5, $zero, $v0
        ctx->r13 = 0 < ctx->r2 ? 1 : 0;
            goto L_8080014C;
    }
    // 0x80800140: sltu        $t5, $zero, $v0
    ctx->r13 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800144: bne         $t5, $zero, L_808001BC
    if (ctx->r13 != 0) {
        // 0x80800148: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_808001BC;
    }
    // 0x80800148: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8080014C:
    // 0x8080014C: lwc1        $f6, 0x58($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80800150: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800158: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8080015C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800160: swc1        $f10, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f10.u32l;
    // 0x80800164: lwc1        $f18, 0x58($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80800168: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8080016C: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80800170: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800174: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800178: bc1tl       L_8080018C
    if (c1cs) {
        // 0x8080017C: lwc1        $f0, 0x2C($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
            goto L_8080018C;
    }
    goto skip_2;
    // 0x8080017C: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    skip_2:
    // 0x80800180: bnel        $t6, $zero, L_80800278
    if (ctx->r14 != 0) {
        // 0x80800184: lbu         $t2, 0x65($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X65);
            goto L_80800278;
    }
    goto skip_3;
    // 0x80800184: lbu         $t2, 0x65($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X65);
    skip_3:
    // 0x80800188: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
L_8080018C:
    // 0x8080018C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800190: nop

    // 0x80800194: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800198: nop

    // 0x8080019C: bc1f        L_808001AC
    if (!c1cs) {
        // 0x808001A0: nop
    
            goto L_808001AC;
    }
    // 0x808001A0: nop

    // 0x808001A4: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x808001A8: swc1        $f6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f6.u32l;
L_808001AC:
    // 0x808001AC: jal         0x80101FDC
    // 0x808001B0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x808001B0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_9:
    // 0x808001B4: b           L_80800274
    // 0x808001B8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80800274;
    // 0x808001B8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_808001BC:
    // 0x808001BC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808001C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001C4: b           L_80800274
    // 0x808001C8: swc1        $f8, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f8.u32l;
        goto L_80800274;
    // 0x808001C8: swc1        $f8, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f8.u32l;
L_808001CC:
    // 0x808001CC: jal         0x800DA298
    // 0x808001D0: addiu       $a0, $zero, 0x679
    ctx->r4 = ADD32(0, 0X679);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x808001D0: addiu       $a0, $zero, 0x679
    ctx->r4 = ADD32(0, 0X679);
    after_10:
    // 0x808001D4: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x808001D8: addiu       $s0, $zero, 0x50
        ctx->r16 = ADD32(0, 0X50);
            goto L_808001E4;
    }
    // 0x808001D8: addiu       $s0, $zero, 0x50
    ctx->r16 = ADD32(0, 0X50);
    // 0x808001DC: b           L_808001E4
    // 0x808001E0: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
        goto L_808001E4;
    // 0x808001E0: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
L_808001E4:
    // 0x808001E4: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x808001E8: lwc1        $f16, 0x28($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X28);
    // 0x808001EC: lwc1        $f4, 0x48($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X48);
    // 0x808001F0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001F4: mul.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x808001F8: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x808001FC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800200: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800204: jal         0x800136E4
    // 0x80800208: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_11;
    // 0x80800208: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_11:
    // 0x8080020C: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x80800210: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800214: jal         0x80800454
    // 0x80800218: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800454_chstarspinnerstar(rdram, ctx);
        goto after_12;
    // 0x80800218: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8080021C: beq         $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800220: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800234;
    }
    // 0x80800220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800224: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080022C: jal         0x80101FDC
    // 0x80800230: swc1        $f10, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f10.u32l;
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x80800230: swc1        $f10, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f10.u32l;
    after_13:
L_80800234:
    // 0x80800234: lw          $t7, 0x64($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X64);
    // 0x80800238: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8080023C: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800240: bgezl       $t9, L_8080026C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800244: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_8080026C;
    }
    goto skip_4;
    // 0x80800244: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_4:
    // 0x80800248: beq         $t0, $zero, L_80800268
    if (ctx->r8 == 0) {
        // 0x8080024C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800268;
    }
    // 0x8080024C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800250: jal         0x80101FDC
    // 0x80800254: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x80800254: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80800258: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080025C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800260: nop

    // 0x80800264: swc1        $f18, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f18.u32l;
L_80800268:
    // 0x80800268: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_8080026C:
    // 0x8080026C: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800270: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80800274:
    // 0x80800274: lbu         $t2, 0x65($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X65);
L_80800278:
    // 0x80800278: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080027C: lui         $a2, 0x44ED
    ctx->r6 = S32(0X44ED << 16);
    // 0x80800280: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x80800284: beq         $v0, $zero, L_8080029C
    if (ctx->r2 == 0) {
        // 0x80800288: sb          $t3, 0x65($s1)
        MEM_B(0X65, ctx->r17) = ctx->r11;
            goto L_8080029C;
    }
    // 0x80800288: sb          $t3, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r11;
    // 0x8080028C: lhu         $s0, 0x72($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X72);
    // 0x80800290: srl         $t4, $s0, 10
    ctx->r12 = S32(U32(ctx->r16) >> 10);
    // 0x80800294: slti        $t5, $t4, 0x2
    ctx->r13 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80800298: xori        $s0, $t5, 0x1
    ctx->r16 = ctx->r13 ^ 0X1;
L_8080029C:
    // 0x8080029C: bne         $s0, $zero, L_808002B4
    if (ctx->r16 != 0) {
        // 0x808002A0: ori         $a2, $a2, 0x8000
        ctx->r6 = ctx->r6 | 0X8000;
            goto L_808002B4;
    }
    // 0x808002A0: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x808002A4: bnel        $s0, $zero, L_80800310
    if (ctx->r16 != 0) {
        // 0x808002A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800310;
    }
    goto skip_5;
    // 0x808002A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x808002AC: lbu         $t6, 0x5F($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X5F);
    // 0x808002B0: beq         $t6, $zero, L_8080030C
    if (ctx->r14 == 0) {
        // 0x808002B4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(956, 0X6A0) << 16);
            goto L_8080030C;
    }
L_808002B4:
    // 0x808002B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(956, 0X6A0) << 16);
    // 0x808002B8: lwc1        $f4, 0x6A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(956, 0X6A0));
    // 0x808002BC: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x808002C0: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x808002C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002C8: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x808002CC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808002D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808002D4: jal         0x800F10B4
    // 0x808002D8: sub.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f6.fl;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x808002D8: sub.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f6.fl;
    after_15:
    // 0x808002DC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808002E0: jal         0x800C4B64
    // 0x808002E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800C4B64(rdram, ctx);
        goto after_16;
    // 0x808002E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_16:
    // 0x808002E8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(956, 0X6F8) << 16);
    // 0x808002EC: addiu       $a3, $a3, 0x6F8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(956, 0X6F8));
    // 0x808002F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002F4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x808002F8: jal         0x80089D50
    // 0x808002FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x808002FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_17:
    // 0x80800300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800304: jal         0x80089D30
    // 0x80800308: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x80800308: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_18:
L_8080030C:
    // 0x8080030C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800310:
    // 0x80800310: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800314: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800318: jr          $ra
    // 0x8080031C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080031C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void baswim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080014C: jal         0x8009F1E0
    // 0x80800150: nop

    bastick_resetZones(rdram, ctx);
        goto after_0;
    // 0x80800150: nop

    after_0:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
RECOMP_FUNC void func_80800BA8_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800BAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BB0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800BB4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800BB8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800BBC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800BC0: jal         0x80100094
    // 0x80800BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800BC8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800BCC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80800BD0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800BD4: slti        $at, $a3, 0xCED
    ctx->r1 = SIGNED(ctx->r7) < 0XCED ? 1 : 0;
    // 0x80800BD8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800BDC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80800BE0: bne         $at, $zero, L_80800C0C
    if (ctx->r1 != 0) {
        // 0x80800BE4: sw          $zero, 0x30($sp)
        MEM_W(0X30, ctx->r29) = 0;
            goto L_80800C0C;
    }
    // 0x80800BE4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80800BE8: addiu       $t7, $a3, -0x102C
    ctx->r15 = ADD32(ctx->r7, -0X102C);
    // 0x80800BEC: sltiu       $at, $t7, 0x21
    ctx->r1 = ctx->r15 < 0X21 ? 1 : 0;
    // 0x80800BF0: beq         $at, $zero, L_80800E90
    if (ctx->r1 == 0) {
        // 0x80800BF4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800E90;
    }
    // 0x80800BF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800BF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(792, 0X1378) << 16);
    // 0x80800BFC: addu        $at, $at, $t7
    gpr jr_addend_80800C04 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800C00: lw          $t7, 0x1378($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(792, 0X1378));
    // 0x80800C04: jr          $t7
    // 0x80800C08: nop

    switch (jr_addend_80800C04 >> 2) {
        case 0: goto L_80800C28; break;
        case 1: goto L_80800C28; break;
        case 2: goto L_80800C7C; break;
        case 3: goto L_80800CC0; break;
        case 4: goto L_80800DA8; break;
        case 5: goto L_80800DE8; break;
        case 6: goto L_80800DE8; break;
        case 7: goto L_80800DE8; break;
        case 8: goto L_80800DE8; break;
        case 9: goto L_80800E90; break;
        case 10: goto L_80800E90; break;
        case 11: goto L_80800E90; break;
        case 12: goto L_80800E90; break;
        case 13: goto L_80800E90; break;
        case 14: goto L_80800E90; break;
        case 15: goto L_80800E90; break;
        case 16: goto L_80800E90; break;
        case 17: goto L_80800E90; break;
        case 18: goto L_80800E90; break;
        case 19: goto L_80800E90; break;
        case 20: goto L_80800E90; break;
        case 21: goto L_80800E90; break;
        case 22: goto L_80800E90; break;
        case 23: goto L_80800E90; break;
        case 24: goto L_80800E90; break;
        case 25: goto L_80800E90; break;
        case 26: goto L_80800E90; break;
        case 27: goto L_80800E90; break;
        case 28: goto L_80800E90; break;
        case 29: goto L_80800C28; break;
        case 30: goto L_80800DE8; break;
        case 31: goto L_80800DE8; break;
        case 32: goto L_80800DE8; break;
        default: switch_error(__func__, 0x80800C04, 0x80801378);
    }
    // 0x80800C08: nop

L_80800C0C:
    // 0x80800C0C: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80800C10: beq         $a3, $at, L_80800DFC
    if (ctx->r7 == ctx->r1) {
        // 0x80800C14: addiu       $at, $zero, 0xCEC
        ctx->r1 = ADD32(0, 0XCEC);
            goto L_80800DFC;
    }
    // 0x80800C14: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80800C18: beq         $a3, $at, L_80800D14
    if (ctx->r7 == ctx->r1) {
        // 0x80800C1C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800D14;
    }
    // 0x80800C1C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C20: b           L_80800E94
    // 0x80800C24: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
        goto L_80800E94;
    // 0x80800C24: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80800C28:
    // 0x80800C28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C2C: addiu       $a1, $v1, 0x30C
    ctx->r5 = ADD32(ctx->r3, 0X30C);
    // 0x80800C30: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800C34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800C38: jal         0x8008A2C8
    // 0x80800C3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800C3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80800C40: jal         0x800DA298
    // 0x80800C44: addiu       $a0, $zero, 0x6E5
    ctx->r4 = ADD32(0, 0X6E5);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800C44: addiu       $a0, $zero, 0x6E5
    ctx->r4 = ADD32(0, 0X6E5);
    after_2:
    // 0x80800C48: bnel        $v0, $zero, L_80800C64
    if (ctx->r2 != 0) {
        // 0x80800C4C: addiu       $t8, $zero, 0xCEC
        ctx->r24 = ADD32(0, 0XCEC);
            goto L_80800C64;
    }
    goto skip_0;
    // 0x80800C4C: addiu       $t8, $zero, 0xCEC
    ctx->r24 = ADD32(0, 0XCEC);
    skip_0:
    // 0x80800C50: jal         0x800D395C
    // 0x80800C54: nop

    func_800D395C(rdram, ctx);
        goto after_3;
    // 0x80800C54: nop

    after_3:
    // 0x80800C58: beq         $v0, $zero, L_80800C6C
    if (ctx->r2 == 0) {
        // 0x80800C5C: addiu       $t9, $zero, 0x102E
        ctx->r25 = ADD32(0, 0X102E);
            goto L_80800C6C;
    }
    // 0x80800C5C: addiu       $t9, $zero, 0x102E
    ctx->r25 = ADD32(0, 0X102E);
    // 0x80800C60: addiu       $t8, $zero, 0xCEC
    ctx->r24 = ADD32(0, 0XCEC);
L_80800C64:
    // 0x80800C64: b           L_80800E90
    // 0x80800C68: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80800E90;
    // 0x80800C68: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_80800C6C:
    // 0x80800C6C: addiu       $t0, $zero, 0x46
    ctx->r8 = ADD32(0, 0X46);
    // 0x80800C70: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80800C74: b           L_80800E90
    // 0x80800C78: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
        goto L_80800E90;
    // 0x80800C78: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80800C7C:
    // 0x80800C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C80: bne         $a0, $at, L_80800CB8
    if (ctx->r4 != ctx->r1) {
        // 0x80800C84: addiu       $t3, $zero, 0xCEC
        ctx->r11 = ADD32(0, 0XCEC);
            goto L_80800CB8;
    }
    // 0x80800C84: addiu       $t3, $zero, 0xCEC
    ctx->r11 = ADD32(0, 0XCEC);
    // 0x80800C88: addiu       $t1, $zero, 0x102F
    ctx->r9 = ADD32(0, 0X102F);
    // 0x80800C8C: addiu       $t2, $zero, 0x46
    ctx->r10 = ADD32(0, 0X46);
    // 0x80800C90: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80800C94: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80800C98: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C9C: addiu       $a1, $v1, 0x30C
    ctx->r5 = ADD32(ctx->r3, 0X30C);
    // 0x80800CA0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80800CA4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800CA8: jal         0x8008A2D0
    // 0x80800CAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800CAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80800CB0: b           L_80800E94
    // 0x80800CB4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
        goto L_80800E94;
    // 0x80800CB4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80800CB8:
    // 0x80800CB8: b           L_80800E90
    // 0x80800CBC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
        goto L_80800E90;
    // 0x80800CBC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
L_80800CC0:
    // 0x80800CC0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80800CC4: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80800CC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800CCC: lw          $a0, 0x3C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X3C);
    // 0x80800CD0: beql        $a0, $zero, L_80800CF0
    if (ctx->r4 == 0) {
        // 0x80800CD4: addiu       $t6, $zero, 0xCEC
        ctx->r14 = ADD32(0, 0XCEC);
            goto L_80800CF0;
    }
    goto skip_1;
    // 0x80800CD4: addiu       $t6, $zero, 0xCEC
    ctx->r14 = ADD32(0, 0XCEC);
    skip_1:
    // 0x80800CD8: jal         0x8010114C
    // 0x80800CDC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8010114C(rdram, ctx);
        goto after_5;
    // 0x80800CDC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_5:
    // 0x80800CE0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80800CE4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800CE8: sw          $zero, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = 0;
    // 0x80800CEC: addiu       $t6, $zero, 0xCEC
    ctx->r14 = ADD32(0, 0XCEC);
L_80800CF0:
    // 0x80800CF0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80800CF4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800CF8: addiu       $a1, $v1, 0x30C
    ctx->r5 = ADD32(ctx->r3, 0X30C);
    // 0x80800CFC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800D00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800D04: jal         0x8008A2C8
    // 0x80800D08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800D08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80800D0C: b           L_80800E94
    // 0x80800D10: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
        goto L_80800E94;
    // 0x80800D10: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80800D14:
    // 0x80800D14: jal         0x8008A2C0
    // 0x80800D18: addiu       $a1, $v1, 0x30C
    ctx->r5 = ADD32(ctx->r3, 0X30C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800D18: addiu       $a1, $v1, 0x30C
    ctx->r5 = ADD32(ctx->r3, 0X30C);
    after_7:
    // 0x80800D1C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800D20: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    // 0x80800D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D28: sw          $zero, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = 0;
    // 0x80800D2C: jal         0x800D2770
    // 0x80800D30: sw          $zero, 0x28($t7)
    MEM_W(0X28, ctx->r15) = 0;
    func_800D2770(rdram, ctx);
        goto after_8;
    // 0x80800D30: sw          $zero, 0x28($t7)
    MEM_W(0X28, ctx->r15) = 0;
    after_8:
    // 0x80800D34: jal         0x800FDC28
    // 0x80800D38: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800FDC28(rdram, ctx);
        goto after_9;
    // 0x80800D38: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_9:
    // 0x80800D3C: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    // 0x80800D40: jal         0x8009055C
    // 0x80800D44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009055C(rdram, ctx);
        goto after_10;
    // 0x80800D44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800D48: jal         0x80090708
    // 0x80800D4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_11;
    // 0x80800D4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80800D50: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800D54: jal         0x80101FDC
    // 0x80800D58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x80800D58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80800D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D60: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800D64: jal         0x800CE8D8
    // 0x80800D68: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_800CE8D8(rdram, ctx);
        goto after_13;
    // 0x80800D68: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_13:
    // 0x80800D6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D70: jal         0x800CE88C
    // 0x80800D74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_14;
    // 0x80800D74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800D78: jal         0x80088178
    // 0x80800D7C: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_15;
    // 0x80800D7C: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    after_15:
    // 0x80800D80: jal         0x800DA544
    // 0x80800D84: addiu       $a0, $zero, 0x6E5
    ctx->r4 = ADD32(0, 0X6E5);
    func_800DA544(rdram, ctx);
        goto after_16;
    // 0x80800D84: addiu       $a0, $zero, 0x6E5
    ctx->r4 = ADD32(0, 0X6E5);
    after_16:
    // 0x80800D88: jal         0x800DA524
    // 0x80800D8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA524(rdram, ctx);
        goto after_17;
    // 0x80800D8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x80800D90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D94: addiu       $a1, $zero, 0x5AA
    ctx->r5 = ADD32(0, 0X5AA);
    // 0x80800D98: jal         0x800BF99C
    // 0x80800D9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BF99C(rdram, ctx);
        goto after_18;
    // 0x80800D9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x80800DA0: b           L_80800E94
    // 0x80800DA4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
        goto L_80800E94;
    // 0x80800DA4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80800DA8:
    // 0x80800DA8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80800DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800DB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800DB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800DB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800DBC: jal         0x800D1000
    // 0x80800DC0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800D1000(rdram, ctx);
        goto after_19;
    // 0x80800DC0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_19:
    // 0x80800DC4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800DC8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800DCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800DD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800DD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800DD8: jal         0x8008A2D0
    // 0x80800DDC: addiu       $a1, $v1, 0x30C
    ctx->r5 = ADD32(ctx->r3, 0X30C);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_20;
    // 0x80800DDC: addiu       $a1, $v1, 0x30C
    ctx->r5 = ADD32(ctx->r3, 0X30C);
    after_20:
    // 0x80800DE0: b           L_80800E94
    // 0x80800DE4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
        goto L_80800E94;
    // 0x80800DE4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80800DE8:
    // 0x80800DE8: addiu       $t8, $zero, 0xCEB
    ctx->r24 = ADD32(0, 0XCEB);
    // 0x80800DEC: addiu       $t9, $zero, 0x46
    ctx->r25 = ADD32(0, 0X46);
    // 0x80800DF0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80800DF4: b           L_80800E90
    // 0x80800DF8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_80800E90;
    // 0x80800DF8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80800DFC:
    // 0x80800DFC: jal         0x800D395C
    // 0x80800E00: nop

    func_800D395C(rdram, ctx);
        goto after_21;
    // 0x80800E00: nop

    after_21:
    // 0x80800E04: beq         $v0, $zero, L_80800E38
    if (ctx->r2 == 0) {
        // 0x80800E08: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800E38;
    }
    // 0x80800E08: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800E0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E10: bne         $a0, $at, L_80800E28
    if (ctx->r4 != ctx->r1) {
        // 0x80800E14: nop
    
            goto L_80800E28;
    }
    // 0x80800E14: nop

    // 0x80800E18: jal         0x80088188
    // 0x80800E1C: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_22;
    // 0x80800E1C: nop

    after_22:
    // 0x80800E20: b           L_80800E94
    // 0x80800E24: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
        goto L_80800E94;
    // 0x80800E24: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80800E28:
    // 0x80800E28: jal         0x80088180
    // 0x80800E2C: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_23;
    // 0x80800E2C: nop

    after_23:
    // 0x80800E30: b           L_80800E94
    // 0x80800E34: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
        goto L_80800E94;
    // 0x80800E34: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80800E38:
    // 0x80800E38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E3C: bne         $a0, $at, L_80800E58
    if (ctx->r4 != ctx->r1) {
        // 0x80800E40: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800E58;
    }
    // 0x80800E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E44: addiu       $t0, $zero, 0x181
    ctx->r8 = ADD32(0, 0X181);
    // 0x80800E48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800E4C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80800E50: b           L_80800E68
    // 0x80800E54: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
        goto L_80800E68;
    // 0x80800E54: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80800E58:
    // 0x80800E58: addiu       $t2, $zero, 0x1A9
    ctx->r10 = ADD32(0, 0X1A9);
    // 0x80800E5C: addiu       $t3, $zero, 0x1B
    ctx->r11 = ADD32(0, 0X1B);
    // 0x80800E60: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80800E64: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_80800E68:
    // 0x80800E68: jal         0x8009055C
    // 0x80800E6C: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    func_8009055C(rdram, ctx);
        goto after_24;
    // 0x80800E6C: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    after_24:
    // 0x80800E70: jal         0x80090708
    // 0x80800E74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_25;
    // 0x80800E74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x80800E78: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800E7C: jal         0x80101FDC
    // 0x80800E80: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_26;
    // 0x80800E80: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_26:
    // 0x80800E84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800E88: jal         0x80087A58
    // 0x80800E8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_27;
    // 0x80800E8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_27:
L_80800E90:
    // 0x80800E90: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80800E94:
    // 0x80800E94: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80800E98: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E9C: beq         $t4, $zero, L_80800EB8
    if (ctx->r12 == 0) {
        // 0x80800EA0: or          $a1, $t4, $zero
        ctx->r5 = ctx->r12 | 0;
            goto L_80800EB8;
    }
    // 0x80800EA0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80800EA4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80800EA8: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80800EAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800EB0: jal         0x8008A208
    // 0x80800EB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_28;
    // 0x80800EB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
L_80800EB8:
    // 0x80800EB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EBC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800EC0: jr          $ra
    // 0x80800EC4: nop

    return;
    // 0x80800EC4: nop

;}
RECOMP_FUNC void func_80800020_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800028: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800030: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80800034: jal         0x8010C820
    // 0x80800038: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    func_8010C820(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_0:
    // 0x8080003C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800040: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800044: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800048: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x8080004C: beq         $at, $zero, L_8080014C
    if (ctx->r1 == 0) {
        // 0x80800050: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8080014C;
    }
    // 0x80800050: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800054: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1876, 0X8A0) << 16);
    // 0x80800058: addu        $at, $at, $t8
    gpr jr_addend_80800060 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080005C: lw          $t8, 0x8A0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1876, 0X8A0));
    // 0x80800060: jr          $t8
    // 0x80800064: nop

    switch (jr_addend_80800060 >> 2) {
        case 0: goto L_80800068; break;
        case 1: goto L_80800078; break;
        case 2: goto L_808000C4; break;
        case 3: goto L_808000E4; break;
        case 4: goto L_808000F4; break;
        case 5: goto L_80800144; break;
        default: switch_error(__func__, 0x80800060, 0x808008A0);
    }
    // 0x80800064: nop

L_80800068:
    // 0x80800068: jal         0x80800238
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800238_chfriendlystonehead(rdram, ctx);
        goto after_1;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800070: b           L_80800150
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800150;
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800078:
    // 0x80800078: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1876, 0X950) << 16);
    // 0x8080007C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80800080: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800084: addiu       $a2, $a2, 0x950
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1876, 0X950));
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x80089D20
    // 0x80800090: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800090: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800094: jal         0x80800284
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800284_chfriendlystonehead(rdram, ctx);
        goto after_3;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080009C: jal         0x808002BC
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002BC_chfriendlystonehead(rdram, ctx);
        goto after_4;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000A4: jal         0x80101DDC
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000AC: beq         $v0, $zero, L_8080014C
    if (ctx->r2 == 0) {
        // 0x808000B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080014C;
    }
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80102424
    // 0x808000B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808000B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808000BC: b           L_80800150
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800150;
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C4:
    // 0x808000C4: jal         0x80800284
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800284_chfriendlystonehead(rdram, ctx);
        goto after_7;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000CC: jal         0x808002BC
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002BC_chfriendlystonehead(rdram, ctx);
        goto after_8;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000D4: jal         0x80800540
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800540_chfriendlystonehead(rdram, ctx);
        goto after_9;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808000DC: b           L_80800150
    // 0x808000E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800150;
    // 0x808000E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000E4:
    // 0x808000E4: jal         0x808002BC
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002BC_chfriendlystonehead(rdram, ctx);
        goto after_10;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808000EC: b           L_80800150
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800150;
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F4:
    // 0x808000F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1876, 0X95C) << 16);
    // 0x808000F8: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x808000FC: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800100: addiu       $a2, $a2, 0x95C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1876, 0X95C));
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x80089D20
    // 0x8080010C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x8080010C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_11:
    // 0x80800110: jal         0x80800238
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800238_chfriendlystonehead(rdram, ctx);
        goto after_12;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800118: jal         0x80101DDC
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_13;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800120: beq         $v0, $zero, L_8080014C
    if (ctx->r2 == 0) {
        // 0x80800124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080014C;
    }
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x80102424
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800130: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800134: lbu         $t9, 0x2A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2A);
    // 0x80800138: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x8080013C: b           L_8080014C
    // 0x80800140: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
        goto L_8080014C;
    // 0x80800140: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
L_80800144:
    // 0x80800144: jal         0x808002BC
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002BC_chfriendlystonehead(rdram, ctx);
        goto after_15;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_8080014C:
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800150:
    // 0x80800150: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800154: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void chwaterfallfx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1524, 0X410) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1524, 0X410));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1524, 0X410));
;}
RECOMP_FUNC void _chpickups_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085870: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085870);
    return;
    // 0x80085874: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _ncbaclimb_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089260: syscall     768
    recomp_syscall_handler(rdram, ctx, 0x80089260);
    return;
    // 0x80089264: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _badata_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084688: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084688);
    return;
    // 0x8008468C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80804A7C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804A7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804A84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80804A88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80804A8C: jal         0x80100094
    // 0x80804A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804A94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80804A98: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80804A9C: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80804AA0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80804AA4: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80804AA8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80804AAC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80804AB0: jal         0x800E0AFC
    // 0x80804AB4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_1;
    // 0x80804AB4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80804AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804ABC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804AC0: jr          $ra
    // 0x80804AC4: nop

    return;
    // 0x80804AC4: nop

;}
RECOMP_FUNC void func_808013D4_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808013D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808013DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808013E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808013E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808013EC: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x808013F0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808013F4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808013F8: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x808013FC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80801400: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801404: jal         0x80801370
    // 0x80801408: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80801370_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x80801408: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8080140C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801410: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801414: jr          $ra
    // 0x80801418: nop

    return;
    // 0x80801418: nop

;}
