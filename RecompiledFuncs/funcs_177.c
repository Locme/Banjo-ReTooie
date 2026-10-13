#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void basudie_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080027C: jal         0x8009BC6C
    // 0x80800280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800284: jal         0x800A4E30
    // 0x80800288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_1;
    // 0x80800288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080028C: jal         0x800A4C68
    // 0x80800290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4C68(rdram, ctx);
        goto after_2;
    // 0x80800290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800298: jal         0x800C53EC
    // 0x8080029C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C53EC(rdram, ctx);
        goto after_3;
    // 0x8080029C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808002A0: jal         0x800951B4
    // 0x808002A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800951B4(rdram, ctx);
        goto after_4;
    // 0x808002A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002B0: jr          $ra
    // 0x808002B4: nop

    return;
    // 0x808002B4: nop

;}
RECOMP_FUNC void chfairgroundworker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(840, 0X308) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x308
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(840, 0X308));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x308
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(840, 0X308));
;}
RECOMP_FUNC void baboost_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808000A0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000A8: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000B0: sub.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x808000B4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_808000B8:
    // 0x808000B8: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x808000BC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808000C0: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // 0x808000C4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808000C8: nop

    // 0x808000CC: bc1f        L_808000E0
    if (!c1cs) {
        // 0x808000D0: nop
    
            goto L_808000E0;
    }
    // 0x808000D0: nop

    // 0x808000D4: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    // 0x808000D8: jr          $ra
    // 0x808000DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808000DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000E0:
    // 0x808000E0: bne         $at, $zero, L_808000B8
    if (ctx->r1 != 0) {
        // 0x808000E4: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_808000B8;
    }
    // 0x808000E4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x808000E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000EC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808000F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000F4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808000F8: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x808000FC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80800100: addu        $a2, $v1, $t6
    ctx->r6 = ADD32(ctx->r3, ctx->r14);
    // 0x80800104: bc1fl       L_8080011C
    if (!c1cs) {
        // 0x80800108: lwc1        $f10, 0x8($a2)
        ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
            goto L_8080011C;
    }
    goto skip_0;
    // 0x80800108: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    skip_0:
    // 0x8080010C: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x80800110: jr          $ra
    // 0x80800114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800118: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
L_8080011C:
    // 0x8080011C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800120: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80800124: nop

    // 0x80800128: bc1fl       L_8080013C
    if (!c1cs) {
        // 0x8080012C: lwc1        $f16, 0xC($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
            goto L_8080013C;
    }
    goto skip_1;
    // 0x8080012C: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    skip_1:
    // 0x80800130: jr          $ra
    // 0x80800134: swc1        $f12, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f12.u32l;
    return;
    // 0x80800134: swc1        $f12, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f12.u32l;
    // 0x80800138: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
L_8080013C:
    // 0x8080013C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800140: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80800144: nop

    // 0x80800148: bc1fl       L_8080015C
    if (!c1cs) {
        // 0x8080014C: lwc1        $f18, 0x10($a2)
        ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
            goto L_8080015C;
    }
    goto skip_2;
    // 0x8080014C: lwc1        $f18, 0x10($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
    skip_2:
    // 0x80800150: jr          $ra
    // 0x80800154: swc1        $f12, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f12.u32l;
    return;
    // 0x80800154: swc1        $f12, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f12.u32l;
    // 0x80800158: lwc1        $f18, 0x10($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
L_8080015C:
    // 0x8080015C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800160: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x80800164: nop

    // 0x80800168: bc1fl       L_8080017C
    if (!c1cs) {
        // 0x8080016C: lwc1        $f4, 0x14($a2)
        ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
            goto L_8080017C;
    }
    goto skip_3;
    // 0x8080016C: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    skip_3:
    // 0x80800170: jr          $ra
    // 0x80800174: swc1        $f12, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f12.u32l;
    return;
    // 0x80800174: swc1        $f12, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f12.u32l;
    // 0x80800178: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
L_8080017C:
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800180: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800184: nop

    // 0x80800188: bc1fl       L_808001A0
    if (!c1cs) {
        // 0x8080018C: swc1        $f12, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
            goto L_808001A0;
    }
    goto skip_4;
    // 0x8080018C: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    skip_4:
    // 0x80800190: swc1        $f12, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f12.u32l;
    // 0x80800194: jr          $ra
    // 0x80800198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080019C: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
L_808001A0:
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void chpotogoldgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080104C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801050: jal         0x800D395C
    // 0x80801054: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D395C(rdram, ctx);
        goto after_0;
    // 0x80801054: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801058: beq         $v0, $zero, L_8080107C
    if (ctx->r2 == 0) {
        // 0x8080105C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8080107C;
    }
    // 0x8080105C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801060: jal         0x80106790
    // 0x80801064: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801064: nop

    after_1:
    // 0x80801068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080106C: jal         0x80800434
    // 0x80801070: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_2;
    // 0x80801070: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_2:
    // 0x80801074: b           L_80801094
    // 0x80801078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801094;
    // 0x80801078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080107C:
    // 0x8080107C: jal         0x80106790
    // 0x80801080: nop

    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80801080: nop

    after_3:
    // 0x80801084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801088: jal         0x80800434
    // 0x8080108C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_4;
    // 0x8080108C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x80801090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801094:
    // 0x80801094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801098: jr          $ra
    // 0x8080109C: nop

    return;
    // 0x8080109C: nop

;}
RECOMP_FUNC void func_80093FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093FD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093FD8: addiu       $at, $zero, 0x607
    ctx->r1 = ADD32(0, 0X607);
    // 0x80093FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093FE0: bne         $a1, $at, L_80094054
    if (ctx->r5 != ctx->r1) {
        // 0x80093FE4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80094054;
    }
    // 0x80093FE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80093FE8: jal         0x800EA05C
    // 0x80093FEC: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80093FEC: nop

    after_0:
    // 0x80093FF0: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80093FF4: addiu       $a3, $a3, 0x7DF0
    ctx->r7 = ADD32(ctx->r7, 0X7DF0);
    // 0x80093FF8: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x80093FFC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80094000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80094004: beq         $a2, $t6, L_80094030
    if (ctx->r6 == ctx->r14) {
        // 0x80094008: lui         $t7, 0x8011
        ctx->r15 = S32(0X8011 << 16);
            goto L_80094030;
    }
    // 0x80094008: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8009400C: addiu       $v1, $t7, 0x7DF0
    ctx->r3 = ADD32(ctx->r15, 0X7DF0);
    // 0x80094010: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
L_80094014:
    // 0x80094014: beql        $v0, $a0, L_80094034
    if (ctx->r2 == ctx->r4) {
        // 0x80094018: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80094034;
    }
    goto skip_0;
    // 0x80094018: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    skip_0:
    // 0x8009401C: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x80094020: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80094024: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80094028: bne         $a2, $a0, L_80094014
    if (ctx->r6 != ctx->r4) {
        // 0x8009402C: nop
    
            goto L_80094014;
    }
    // 0x8009402C: nop

L_80094030:
    // 0x80094030: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
L_80094034:
    // 0x80094034: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80094038: jal         0x80093F30
    // 0x8009403C: lh          $a0, 0x2($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X2);
    func_80093F30(rdram, ctx);
        goto after_1;
    // 0x8009403C: lh          $a0, 0x2($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X2);
    after_1:
    // 0x80094040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80094044: jal         0x800941C8
    // 0x80094048: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800941C8(rdram, ctx);
        goto after_2;
    // 0x80094048: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8009404C: b           L_80094064
    // 0x80094050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80094064;
    // 0x80094050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80094054:
    // 0x80094054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80094058: jal         0x800941C8
    // 0x8009405C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800941C8(rdram, ctx);
        goto after_3;
    // 0x8009405C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80094060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80094064:
    // 0x80094064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094068: jr          $ra
    // 0x8009406C: nop

    return;
    // 0x8009406C: nop

;}
RECOMP_FUNC void func_80800E44_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E44: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800E48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E50: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800E54: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800E58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E60: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800E64: beq         $t6, $at, L_80800EF8
    if (ctx->r14 == ctx->r1) {
        // 0x80800E68: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800EF8;
    }
    // 0x80800E68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E6C: beq         $t6, $at, L_80800E94
    if (ctx->r14 == ctx->r1) {
        // 0x80800E70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E94;
    }
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E74: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800E78: beq         $t6, $at, L_80800EA4
    if (ctx->r14 == ctx->r1) {
        // 0x80800E7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EA4;
    }
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E80: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800E84: beq         $t6, $at, L_80800EA4
    if (ctx->r14 == ctx->r1) {
        // 0x80800E88: nop
    
            goto L_80800EA4;
    }
    // 0x80800E88: nop

    // 0x80800E8C: b           L_80800EFC
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800EFC;
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E94:
    // 0x80800E94: jal         0x80800294
    // 0x80800E98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800294_chhumba(rdram, ctx);
        goto after_0;
    // 0x80800E98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E9C: b           L_80800EFC
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800EFC;
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800EA4:
    // 0x80800EA4: jal         0x80800238
    // 0x80800EA8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80800238_chhumba(rdram, ctx);
        goto after_1;
    // 0x80800EA8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80800EAC: jal         0x80090658
    // 0x80800EB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_2;
    // 0x80800EB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800EB4: jal         0x80088AE0
    // 0x80800EB8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    _fxsplash_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800EB8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800EBC: jal         0x800889D8
    // 0x80800EC0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    _fxsplash25d_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800EC0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80800EC4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1688, 0X2590) << 16);
    // 0x80800EC8: addiu       $a2, $a2, 0x2590
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1688, 0X2590));
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED0: jal         0x80089D18
    // 0x80800ED4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800ED4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800ED8: jal         0x808007F8
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007F8_chhumba(rdram, ctx);
        goto after_6;
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800EE0: jal         0x800FC660
    // 0x80800EE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_7;
    // 0x80800EE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_7:
    // 0x80800EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EEC: addiu       $a1, $zero, 0x11B4
    ctx->r5 = ADD32(0, 0X11B4);
    // 0x80800EF0: jal         0x80800338
    // 0x80800EF4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_8;
    // 0x80800EF4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_8:
L_80800EF8:
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800EFC:
    // 0x80800EFC: jal         0x80101FDC
    // 0x80800F00: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x80800F00: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_9:
    // 0x80800F04: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80800F08: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800F0C: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x80800F10: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    // 0x80800F14: beq         $at, $zero, L_8080124C
    if (ctx->r1 == 0) {
        // 0x80800F18: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8080124C;
    }
    // 0x80800F18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800F1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X247C) << 16);
    // 0x80800F20: addu        $at, $at, $t9
    gpr jr_addend_80800F28 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800F24: lw          $t9, 0x247C($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1688, 0X247C));
    // 0x80800F28: jr          $t9
    // 0x80800F2C: nop

    switch (jr_addend_80800F28 >> 2) {
        case 0: goto L_80800F30; break;
        case 1: goto L_80800F40; break;
        case 2: goto L_80800F94; break;
        case 3: goto L_80800FA4; break;
        case 4: goto L_80801008; break;
        case 5: goto L_8080124C; break;
        case 6: goto L_80801024; break;
        case 7: goto L_80801048; break;
        case 8: goto L_8080124C; break;
        case 9: goto L_808010B4; break;
        case 10: goto L_8080124C; break;
        case 11: goto L_8080115C; break;
        case 12: goto L_80801180; break;
        case 13: goto L_8080124C; break;
        case 14: goto L_808011E4; break;
        case 15: goto L_80801230; break;
        case 16: goto L_80800F64; break;
        default: switch_error(__func__, 0x80800F28, 0x8080247C);
    }
    // 0x80800F2C: nop

L_80800F30:
    // 0x80800F30: jal         0x80800B40
    // 0x80800F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B40_chhumba(rdram, ctx);
        goto after_10;
    // 0x80800F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800F38: b           L_80801250
    // 0x80800F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80800F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F40:
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800F48: jal         0x80800028
    // 0x80800F4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800028_chhumba(rdram, ctx);
        goto after_11;
    // 0x80800F4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80800F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F54: jal         0x80800294
    // 0x80800F58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800294_chhumba(rdram, ctx);
        goto after_12;
    // 0x80800F58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800F5C: b           L_80801250
    // 0x80800F60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80800F60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F64:
    // 0x80800F64: jal         0x80800C20
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C20_chhumba(rdram, ctx);
        goto after_13;
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800F6C: beq         $v0, $zero, L_80800F84
    if (ctx->r2 == 0) {
        // 0x80800F70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F84;
    }
    // 0x80800F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F74: jal         0x80800C6C
    // 0x80800F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C6C_chhumba(rdram, ctx);
        goto after_14;
    // 0x80800F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800F7C: b           L_80801250
    // 0x80800F80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80800F80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F84:
    // 0x80800F84: jal         0x80800E44
    // 0x80800F88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800E44_chhumba(rdram, ctx);
        goto after_15;
    // 0x80800F88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x80800F8C: b           L_80801250
    // 0x80800F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80800F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F94:
    // 0x80800F94: jal         0x80090658
    // 0x80800F98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_16;
    // 0x80800F98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80800F9C: b           L_80801250
    // 0x80800FA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80800FA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FA4:
    // 0x80800FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA8: jal         0x80800238
    // 0x80800FAC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80800238_chhumba(rdram, ctx);
        goto after_17;
    // 0x80800FAC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_17:
    // 0x80800FB0: jal         0x80090768
    // 0x80800FB4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80090768(rdram, ctx);
        goto after_18;
    // 0x80800FB4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_18:
    // 0x80800FB8: jal         0x8008FDEC
    // 0x80800FBC: nop

    func_8008FDEC(rdram, ctx);
        goto after_19;
    // 0x80800FBC: nop

    after_19:
    // 0x80800FC0: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80800FC4: jal         0x80106790
    // 0x80800FC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_20;
    // 0x80800FC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x80800FCC: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x80800FD0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800FD4: jal         0x800EE7F8
    // 0x80800FD8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_21;
    // 0x80800FD8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_21:
    // 0x80800FDC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800FE8: lbu         $t1, 0x74($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X74);
    // 0x80800FEC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80800FF0: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x80800FF4: sb          $t2, 0x74($v1)
    MEM_B(0X74, ctx->r3) = ctx->r10;
    // 0x80800FF8: jal         0x808000D4
    // 0x80800FFC: lw          $a3, 0x3C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X3C);
    func_808000D4_chhumba(rdram, ctx);
        goto after_22;
    // 0x80800FFC: lw          $a3, 0x3C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X3C);
    after_22:
    // 0x80801000: b           L_80801250
    // 0x80801004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80801004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801008:
    // 0x80801008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080100C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80801010: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80801014: jal         0x808000D4
    // 0x80801018: lw          $a3, 0x3C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X3C);
    func_808000D4_chhumba(rdram, ctx);
        goto after_23;
    // 0x80801018: lw          $a3, 0x3C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X3C);
    after_23:
    // 0x8080101C: b           L_80801250
    // 0x80801020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80801020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801024:
    // 0x80801024: jal         0x80090658
    // 0x80801028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_24;
    // 0x80801028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_24:
    // 0x8080102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801030: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801034: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80801038: jal         0x8080015C
    // 0x8080103C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080015C_chhumba(rdram, ctx);
        goto after_25;
    // 0x8080103C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_25:
    // 0x80801040: b           L_80801250
    // 0x80801044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80801044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801048:
    // 0x80801048: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080104C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801050: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80801054: jal         0x800FC6B0
    // 0x80801058: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_800FC6B0(rdram, ctx);
        goto after_26;
    // 0x80801058: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_26:
    // 0x8080105C: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80801060: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80801064: bgez        $t5, L_8080109C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80801068: nop
    
            goto L_8080109C;
    }
    // 0x80801068: nop

    // 0x8080106C: jal         0x8009EA2C
    // 0x80801070: nop

    func_8009EA2C(rdram, ctx);
        goto after_27;
    // 0x80801070: nop

    after_27:
    // 0x80801074: bne         $v0, $zero, L_8080109C
    if (ctx->r2 != 0) {
        // 0x80801078: nop
    
            goto L_8080109C;
    }
    // 0x80801078: nop

    // 0x8080107C: jal         0x8009EAAC
    // 0x80801080: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8009EAAC(rdram, ctx);
        goto after_28;
    // 0x80801080: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_28:
    // 0x80801084: jal         0x8008FD48
    // 0x80801088: nop

    func_8008FD48(rdram, ctx);
        goto after_29;
    // 0x80801088: nop

    after_29:
    // 0x8080108C: jal         0x800907EC
    // 0x80801090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800907EC(rdram, ctx);
        goto after_30;
    // 0x80801090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
    // 0x80801094: b           L_80801250
    // 0x80801098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80801098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080109C:
    // 0x8080109C: jal         0x80800384
    // 0x808010A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800384_chhumba(rdram, ctx);
        goto after_31;
    // 0x808010A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808010A4: jal         0x800907EC
    // 0x808010A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800907EC(rdram, ctx);
        goto after_32;
    // 0x808010A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_32:
    // 0x808010AC: b           L_80801250
    // 0x808010B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x808010B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808010B4:
    // 0x808010B4: jal         0x80090658
    // 0x808010B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_33;
    // 0x808010B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_33:
    // 0x808010BC: jal         0x80800414
    // 0x808010C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800414_chhumba(rdram, ctx);
        goto after_34;
    // 0x808010C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x808010C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010C8: jal         0x800DA9E4
    // 0x808010CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_35;
    // 0x808010CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x808010D0: bne         $v0, $zero, L_80801130
    if (ctx->r2 != 0) {
        // 0x808010D4: nop
    
            goto L_80801130;
    }
    // 0x808010D4: nop

    // 0x808010D8: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x808010DC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808010E0: bgez        $t8, L_80801110
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808010E4: nop
    
            goto L_80801110;
    }
    // 0x808010E4: nop

    // 0x808010E8: jal         0x80090708
    // 0x808010EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_36;
    // 0x808010EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_36:
    // 0x808010F0: jal         0x808003CC
    // 0x808010F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003CC_chhumba(rdram, ctx);
        goto after_37;
    // 0x808010F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x808010F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801100: jal         0x80800338
    // 0x80801104: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80800338_chhumba(rdram, ctx);
        goto after_38;
    // 0x80801104: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_38:
    // 0x80801108: b           L_80801250
    // 0x8080110C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x8080110C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801110:
    // 0x80801110: jal         0x808003CC
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003CC_chhumba(rdram, ctx);
        goto after_39;
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80801118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080111C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801120: jal         0x80800338
    // 0x80801124: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80800338_chhumba(rdram, ctx);
        goto after_40;
    // 0x80801124: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_40:
    // 0x80801128: b           L_80801250
    // 0x8080112C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x8080112C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801130:
    // 0x80801130: jal         0x80800D2C
    // 0x80801134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D2C_chhumba(rdram, ctx);
        goto after_41;
    // 0x80801134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80801138: bnel        $v0, $zero, L_80801250
    if (ctx->r2 != 0) {
        // 0x8080113C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801250;
    }
    goto skip_0;
    // 0x8080113C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801140: jal         0x808001E4
    // 0x80801144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_chhumba(rdram, ctx);
        goto after_42;
    // 0x80801144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080114C: jal         0x80800E44
    // 0x80801150: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800E44_chhumba(rdram, ctx);
        goto after_43;
    // 0x80801150: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_43:
    // 0x80801154: b           L_80801250
    // 0x80801158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80801158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080115C:
    // 0x8080115C: jal         0x80090658
    // 0x80801160: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_44;
    // 0x80801160: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_44:
    // 0x80801164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801168: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080116C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80801170: jal         0x8080015C
    // 0x80801174: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080015C_chhumba(rdram, ctx);
        goto after_45;
    // 0x80801174: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_45:
    // 0x80801178: b           L_80801250
    // 0x8080117C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x8080117C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801180:
    // 0x80801180: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801184: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801188: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8080118C: jal         0x800FC6B0
    // 0x80801190: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    func_800FC6B0(rdram, ctx);
        goto after_46;
    // 0x80801190: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_46:
    // 0x80801194: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80801198: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8080119C: bgez        $t1, L_808011D4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808011A0: nop
    
            goto L_808011D4;
    }
    // 0x808011A0: nop

    // 0x808011A4: jal         0x8009EA2C
    // 0x808011A8: nop

    func_8009EA2C(rdram, ctx);
        goto after_47;
    // 0x808011A8: nop

    after_47:
    // 0x808011AC: beq         $v0, $zero, L_808011D4
    if (ctx->r2 == 0) {
        // 0x808011B0: nop
    
            goto L_808011D4;
    }
    // 0x808011B0: nop

    // 0x808011B4: jal         0x8009EAAC
    // 0x808011B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8009EAAC(rdram, ctx);
        goto after_48;
    // 0x808011B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_48:
    // 0x808011BC: jal         0x8008FD48
    // 0x808011C0: nop

    func_8008FD48(rdram, ctx);
        goto after_49;
    // 0x808011C0: nop

    after_49:
    // 0x808011C4: jal         0x800907EC
    // 0x808011C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800907EC(rdram, ctx);
        goto after_50;
    // 0x808011C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_50:
    // 0x808011CC: b           L_80801250
    // 0x808011D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x808011D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011D4:
    // 0x808011D4: jal         0x800907EC
    // 0x808011D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800907EC(rdram, ctx);
        goto after_51;
    // 0x808011D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_51:
    // 0x808011DC: b           L_80801250
    // 0x808011E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x808011E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011E4:
    // 0x808011E4: jal         0x80090658
    // 0x808011E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_52;
    // 0x808011E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_52:
    // 0x808011EC: addiu       $a0, $zero, 0x1D1
    ctx->r4 = ADD32(0, 0X1D1);
    // 0x808011F0: jal         0x800DA9E4
    // 0x808011F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_53;
    // 0x808011F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_53:
    // 0x808011F8: bne         $v0, $zero, L_80801214
    if (ctx->r2 != 0) {
        // 0x808011FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801214;
    }
    // 0x808011FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801200: addiu       $a1, $zero, 0x11B6
    ctx->r5 = ADD32(0, 0X11B6);
    // 0x80801204: jal         0x80800338
    // 0x80801208: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_54;
    // 0x80801208: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_54:
    // 0x8080120C: b           L_80801250
    // 0x80801210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x80801210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801214:
    // 0x80801214: jal         0x808001E4
    // 0x80801218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_chhumba(rdram, ctx);
        goto after_55;
    // 0x80801218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x8080121C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801220: jal         0x80800E44
    // 0x80801224: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800E44_chhumba(rdram, ctx);
        goto after_56;
    // 0x80801224: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_56:
    // 0x80801228: b           L_80801250
    // 0x8080122C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801250;
    // 0x8080122C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801230:
    // 0x80801230: addiu       $a0, $zero, 0x505
    ctx->r4 = ADD32(0, 0X505);
    // 0x80801234: jal         0x800DA9E4
    // 0x80801238: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_57;
    // 0x80801238: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_57:
    // 0x8080123C: bnel        $v0, $zero, L_80801250
    if (ctx->r2 != 0) {
        // 0x80801240: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801250;
    }
    goto skip_1;
    // 0x80801240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801244: jal         0x80800B40
    // 0x80801248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B40_chhumba(rdram, ctx);
        goto after_58;
    // 0x80801248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
L_8080124C:
    // 0x8080124C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801250:
    // 0x80801250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801254: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801258: jr          $ra
    // 0x8080125C: nop

    return;
    // 0x8080125C: nop

;}
RECOMP_FUNC void _chLagoonInnBlockedWall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870E0: syscall     513
    recomp_syscall_handler(rdram, ctx, 0x800870E0);
    return;
    // 0x800870E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80804848_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804848: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080484C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804850: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804854: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80804858: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    // 0x8080485C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80804860: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80804864: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80804868: jal         0x80804488
    // 0x8080486C: addiu       $a3, $s0, 0x11C
    ctx->r7 = ADD32(ctx->r16, 0X11C);
    func_80804488_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080486C: addiu       $a3, $s0, 0x11C
    ctx->r7 = ADD32(ctx->r16, 0X11C);
    after_0:
    // 0x80804870: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80804874: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80804878: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080487C: jal         0x80804488
    // 0x80804880: addiu       $a3, $s0, 0x124
    ctx->r7 = ADD32(ctx->r16, 0X124);
    func_80804488_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80804880: addiu       $a3, $s0, 0x124
    ctx->r7 = ADD32(ctx->r16, 0X124);
    after_1:
    // 0x80804884: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80804888: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080488C: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x80804890: beq         $v0, $at, L_808048B0
    if (ctx->r2 == ctx->r1) {
        // 0x80804894: nop
    
            goto L_808048B0;
    }
    // 0x80804894: nop

    // 0x80804898: beq         $v0, $zero, L_808048E4
    if (ctx->r2 == 0) {
        // 0x8080489C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808048E4;
    }
    // 0x8080489C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808048A0: beq         $v0, $at, L_8080497C
    if (ctx->r2 == ctx->r1) {
        // 0x808048A4: addiu       $a0, $s0, 0x12C
        ctx->r4 = ADD32(ctx->r16, 0X12C);
            goto L_8080497C;
    }
    // 0x808048A4: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x808048A8: b           L_808049E4
    // 0x808048AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808049E4;
    // 0x808048AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808048B0:
    // 0x808048B0: jal         0x808045FC
    // 0x808048B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_808045FC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808048B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808048B8: addiu       $a0, $s0, 0x148
    ctx->r4 = ADD32(ctx->r16, 0X148);
    // 0x808048BC: jal         0x808045FC
    // 0x808048C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_808045FC_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x808048C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808048C4: addiu       $a0, $s0, 0x164
    ctx->r4 = ADD32(ctx->r16, 0X164);
    // 0x808048C8: jal         0x808045FC
    // 0x808048CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_808045FC_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x808048CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808048D0: addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    // 0x808048D4: jal         0x808045FC
    // 0x808048D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_808045FC_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x808048D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x808048DC: b           L_808049E4
    // 0x808048E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808049E4;
    // 0x808048E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808048E4:
    // 0x808048E4: lw          $v0, 0x118($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X118);
    // 0x808048E8: beq         $v0, $zero, L_808048FC
    if (ctx->r2 == 0) {
        // 0x808048EC: nop
    
            goto L_808048FC;
    }
    // 0x808048EC: nop

    // 0x808048F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808048F4: b           L_8080490C
    // 0x808048F8: nop

        goto L_8080490C;
    // 0x808048F8: nop

L_808048FC:
    // 0x808048FC: jal         0x8009EF34
    // 0x80804900: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    bastick_getY(rdram, ctx);
        goto after_6;
    // 0x80804900: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80804904: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80804908: lw          $v0, 0x118($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X118);
L_8080490C:
    // 0x8080490C: beq         $v0, $zero, L_80804928
    if (ctx->r2 == 0) {
        // 0x80804910: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80804928;
    }
    // 0x80804910: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80804914: jal         0x8009EF34
    // 0x80804918: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    bastick_getY(rdram, ctx);
        goto after_7;
    // 0x80804918: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_7:
    // 0x8080491C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80804920: b           L_80804930
    // 0x80804924: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
        goto L_80804930;
    // 0x80804924: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_80804928:
    // 0x80804928: lwc1        $f4, 0x124($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8080492C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
L_80804930:
    // 0x80804930: lw          $a1, 0x11C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X11C);
    // 0x80804934: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80804938: jal         0x808045FC
    // 0x8080493C: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    func_808045FC_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x8080493C: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    after_8:
    // 0x80804940: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80804944: addiu       $a0, $s0, 0x148
    ctx->r4 = ADD32(ctx->r16, 0X148);
    // 0x80804948: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080494C: jal         0x808045FC
    // 0x80804950: nop

    func_808045FC_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80804950: nop

    after_9:
    // 0x80804954: jal         0x8009EF28
    // 0x80804958: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    bastick_getX(rdram, ctx);
        goto after_10;
    // 0x80804958: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x8080495C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80804960: jal         0x808045FC
    // 0x80804964: addiu       $a0, $s0, 0x164
    ctx->r4 = ADD32(ctx->r16, 0X164);
    func_808045FC_bsfirstp(rdram, ctx);
        goto after_11;
    // 0x80804964: addiu       $a0, $s0, 0x164
    ctx->r4 = ADD32(ctx->r16, 0X164);
    after_11:
    // 0x80804968: addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    // 0x8080496C: jal         0x808045FC
    // 0x80804970: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808045FC_bsfirstp(rdram, ctx);
        goto after_12;
    // 0x80804970: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80804974: b           L_808049E4
    // 0x80804978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808049E4;
    // 0x80804978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080497C:
    // 0x8080497C: lw          $t6, 0x118($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X118);
    // 0x80804980: beql        $t6, $zero, L_80804998
    if (ctx->r14 == 0) {
        // 0x80804984: lwc1        $f0, 0x124($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X124);
            goto L_80804998;
    }
    goto skip_0;
    // 0x80804984: lwc1        $f0, 0x124($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X124);
    skip_0:
    // 0x80804988: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080498C: b           L_8080499C
    // 0x80804990: lw          $a1, 0x11C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X11C);
        goto L_8080499C;
    // 0x80804990: lw          $a1, 0x11C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X11C);
    // 0x80804994: lwc1        $f0, 0x124($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X124);
L_80804998:
    // 0x80804998: lw          $a1, 0x11C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X11C);
L_8080499C:
    // 0x8080499C: jal         0x808045FC
    // 0x808049A0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_808045FC_bsfirstp(rdram, ctx);
        goto after_13;
    // 0x808049A0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x808049A4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808049A8: addiu       $a0, $s0, 0x148
    ctx->r4 = ADD32(ctx->r16, 0X148);
    // 0x808049AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808049B0: jal         0x808045FC
    // 0x808049B4: nop

    func_808045FC_bsfirstp(rdram, ctx);
        goto after_14;
    // 0x808049B4: nop

    after_14:
    // 0x808049B8: jal         0x8009EF28
    // 0x808049BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    bastick_getX(rdram, ctx);
        goto after_15;
    // 0x808049BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_15:
    // 0x808049C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808049C4: jal         0x808045FC
    // 0x808049C8: addiu       $a0, $s0, 0x164
    ctx->r4 = ADD32(ctx->r16, 0X164);
    func_808045FC_bsfirstp(rdram, ctx);
        goto after_16;
    // 0x808049C8: addiu       $a0, $s0, 0x164
    ctx->r4 = ADD32(ctx->r16, 0X164);
    after_16:
    // 0x808049CC: jal         0x8009EF34
    // 0x808049D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    bastick_getY(rdram, ctx);
        goto after_17;
    // 0x808049D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_17:
    // 0x808049D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808049D8: jal         0x808045FC
    // 0x808049DC: addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    func_808045FC_bsfirstp(rdram, ctx);
        goto after_18;
    // 0x808049DC: addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    after_18:
    // 0x808049E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808049E4:
    // 0x808049E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808049E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808049EC: jr          $ra
    // 0x808049F0: nop

    return;
    // 0x808049F0: nop

;}
RECOMP_FUNC void func_800EB750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB750: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EB754: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800EB758: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800EB75C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800EB760: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800EB764: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EB768: addiu       $s1, $s1, 0x2E9C
    ctx->r17 = ADD32(ctx->r17, 0X2E9C);
    // 0x800EB76C: addiu       $s0, $s0, 0x2E80
    ctx->r16 = ADD32(ctx->r16, 0X2E80);
    // 0x800EB770: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800EB774:
    // 0x800EB774: beql        $a0, $zero, L_800EB78C
    if (ctx->r4 == 0) {
        // 0x800EB778: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800EB78C;
    }
    goto skip_0;
    // 0x800EB778: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800EB77C: jal         0x800B2D28
    // 0x800EB780: nop

    vector_free(rdram, ctx);
        goto after_0;
    // 0x800EB780: nop

    after_0:
    // 0x800EB784: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800EB788: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800EB78C:
    // 0x800EB78C: bnel        $s0, $s1, L_800EB774
    if (ctx->r16 != ctx->r17) {
        // 0x800EB790: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800EB774;
    }
    goto skip_1;
    // 0x800EB790: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800EB794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB798: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800EB79C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800EB7A0: jr          $ra
    // 0x800EB7A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800EB7A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800034_chexplodingchainlinks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800040: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800044: jal         0x800E3A58
    // 0x80800048: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800E3A58(rdram, ctx);
        goto after_0;
    // 0x80800048: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8080004C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800050: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800054: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    // 0x80800058: jal         0x80101870
    // 0x8080005C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x8080005C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void func_8080047C_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080047C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800484: jal         0x800C0638
    // 0x80800488: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800C0638(rdram, ctx);
        goto after_0;
    // 0x80800488: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080048C: bnel        $v0, $zero, L_808004F0
    if (ctx->r2 != 0) {
        // 0x80800490: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004F0;
    }
    goto skip_0;
    // 0x80800490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800494: jal         0x800DA298
    // 0x80800498: addiu       $a0, $zero, 0xD4E
    ctx->r4 = ADD32(0, 0XD4E);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800498: addiu       $a0, $zero, 0xD4E
    ctx->r4 = ADD32(0, 0XD4E);
    after_1:
    // 0x8080049C: bnel        $v0, $zero, L_808004F0
    if (ctx->r2 != 0) {
        // 0x808004A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004F0;
    }
    goto skip_1;
    // 0x808004A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808004A4: jal         0x80088848
    // 0x808004A8: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808004A8: nop

    after_2:
    // 0x808004AC: bnel        $v0, $zero, L_808004F0
    if (ctx->r2 != 0) {
        // 0x808004B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004F0;
    }
    goto skip_2;
    // 0x808004B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x808004B4: jal         0x800D035C
    // 0x808004B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_3;
    // 0x808004B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x808004BC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x808004C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004C4: jal         0x800D2498
    // 0x808004C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_4;
    // 0x808004C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808004CC: jal         0x8008A698
    // 0x808004D0: nop

    _sujiggy_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808004D0: nop

    after_5:
    // 0x808004D4: jal         0x8008A6A8
    // 0x808004D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sujiggy_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808004D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808004DC: addiu       $a0, $zero, 0x106
    ctx->r4 = ADD32(0, 0X106);
    // 0x808004E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004E4: jal         0x800D2498
    // 0x808004E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_7;
    // 0x808004E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x808004EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004F0:
    // 0x808004F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004F4: jr          $ra
    // 0x808004F8: nop

    return;
    // 0x808004F8: nop

;}
RECOMP_FUNC void func_808000F4_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000FC: jal         0x808000C8
    // 0x80800100: nop

    func_808000C8_chstoneballcontrol(rdram, ctx);
        goto after_0;
    // 0x80800100: nop

    after_0:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_8080067C_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080067C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800684: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800688: jal         0x80100094
    // 0x8080068C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080068C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800690: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800694: jal         0x80088840
    // 0x80800698: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800698: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_1:
    // 0x8080069C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808006A0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808006A4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808006A8: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x808006AC: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x808006B0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808006B4: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808006B8: beq         $t8, $at, L_808006F8
    if (ctx->r24 == ctx->r1) {
        // 0x808006BC: lui         $a3, 0x42C8
        ctx->r7 = S32(0X42C8 << 16);
            goto L_808006F8;
    }
    // 0x808006BC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x808006C0: jal         0x8008FB10
    // 0x808006C4: addiu       $a0, $t6, 0x4
    ctx->r4 = ADD32(ctx->r14, 0X4);
    func_8008FB10(rdram, ctx);
        goto after_2;
    // 0x808006C4: addiu       $a0, $t6, 0x4
    ctx->r4 = ADD32(ctx->r14, 0X4);
    after_2:
    // 0x808006C8: jal         0x800F54E4
    // 0x808006CC: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808006CC: nop

    after_3:
    // 0x808006D0: jal         0x800F55FC
    // 0x808006D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F55FC(rdram, ctx);
        goto after_4;
    // 0x808006D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808006D8: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x808006DC: bgez        $t9, L_808006F8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808006E0: lui         $a1, 0xBF80
        ctx->r5 = S32(0XBF80 << 16);
            goto L_808006F8;
    }
    // 0x808006E0: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    // 0x808006E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006E8: addiu       $a2, $zero, 0x1D9
    ctx->r6 = ADD32(0, 0X1D9);
    // 0x808006EC: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x808006F0: jal         0x800902E4
    // 0x808006F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800902E4(rdram, ctx);
        goto after_5;
    // 0x808006F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_5:
L_808006F8:
    // 0x808006F8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808006FC: lhu         $t1, 0x72($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X72);
    // 0x80800700: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80800704: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80800708: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x8080070C: beq         $at, $zero, L_80800904
    if (ctx->r1 == 0) {
        // 0x80800710: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80800904;
    }
    // 0x80800710: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800714: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(760, 0X1088) << 16);
    // 0x80800718: addu        $at, $at, $t3
    gpr jr_addend_80800720 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8080071C: lw          $t3, 0x1088($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(760, 0X1088));
    // 0x80800720: jr          $t3
    // 0x80800724: nop

    switch (jr_addend_80800720 >> 2) {
        case 0: goto L_80800728; break;
        case 1: goto L_808007A4; break;
        case 2: goto L_808007F4; break;
        case 3: goto L_80800880; break;
        case 4: goto L_808008E4; break;
        case 5: goto L_808008F4; break;
        default: switch_error(__func__, 0x80800720, 0x80801088);
    }
    // 0x80800724: nop

L_80800728:
    // 0x80800728: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080072C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(760, 0X1138) << 16);
    // 0x80800730: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x80800734: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800738: addiu       $a2, $a2, 0x1138
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(760, 0X1138));
    // 0x8080073C: jal         0x80089D20
    // 0x80800740: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800740: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_6:
    // 0x80800744: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800748: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(760, 0X1144) << 16);
    // 0x8080074C: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x80800750: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800754: addiu       $a2, $a2, 0x1144
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(760, 0X1144));
    // 0x80800758: jal         0x80089D20
    // 0x8080075C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x8080075C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_7:
    // 0x80800760: jal         0x800F54E4
    // 0x80800764: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800764: nop

    after_8:
    // 0x80800768: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080076C: jal         0x80800194
    // 0x80800770: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800194_chnastycavemen(rdram, ctx);
        goto after_9;
    // 0x80800770: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80800774: beq         $v0, $zero, L_80800904
    if (ctx->r2 == 0) {
        // 0x80800778: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800904;
    }
    // 0x80800778: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080077C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(760, 0X1150) << 16);
    // 0x80800780: addiu       $a2, $a2, 0x1150
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(760, 0X1150));
    // 0x80800784: jal         0x80089D18
    // 0x80800788: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800788: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_10:
    // 0x8080078C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800790: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800794: jal         0x80800268
    // 0x80800798: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800268_chnastycavemen(rdram, ctx);
        goto after_11;
    // 0x80800798: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8080079C: b           L_80800904
    // 0x808007A0: nop

        goto L_80800904;
    // 0x808007A0: nop

L_808007A4:
    // 0x808007A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007A8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(760, 0X1158) << 16);
    // 0x808007AC: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x808007B0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x808007B4: addiu       $a2, $a2, 0x1158
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(760, 0X1158));
    // 0x808007B8: jal         0x80089D20
    // 0x808007BC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x808007BC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_12:
    // 0x808007C0: jal         0x80101DDC
    // 0x808007C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80101DDC(rdram, ctx);
        goto after_13;
    // 0x808007C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_13:
    // 0x808007C8: beq         $v0, $zero, L_80800904
    if (ctx->r2 == 0) {
        // 0x808007CC: lw          $t4, 0x18($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X18);
            goto L_80800904;
    }
    // 0x808007CC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x808007D0: beq         $t4, $zero, L_808007E0
    if (ctx->r12 == 0) {
        // 0x808007D4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808007E0;
    }
    // 0x808007D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007D8: b           L_808007E4
    // 0x808007DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_808007E4;
    // 0x808007DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_808007E0:
    // 0x808007E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_808007E4:
    // 0x808007E4: jal         0x80800268
    // 0x808007E8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_80800268_chnastycavemen(rdram, ctx);
        goto after_14;
    // 0x808007E8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_14:
    // 0x808007EC: b           L_80800904
    // 0x808007F0: nop

        goto L_80800904;
    // 0x808007F0: nop

L_808007F4:
    // 0x808007F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(760, 0X1174) << 16);
    // 0x808007FC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(760, 0X1164) << 16);
    // 0x80800800: addiu       $a3, $a3, 0x1164
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(760, 0X1164));
    // 0x80800804: addiu       $a2, $a2, 0x1174
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(760, 0X1174));
    // 0x80800808: jal         0x80089D28
    // 0x8080080C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x8080080C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_15:
    // 0x80800810: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80800814: lw          $v1, 0x74($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X74);
    // 0x80800818: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8080081C: bgez        $t8, L_80800904
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800820: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80800904;
    }
    // 0x80800820: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80800824: bgez        $t9, L_80800904
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800828: nop
    
            goto L_80800904;
    }
    // 0x80800828: nop

    // 0x8080082C: jal         0x8080010C
    // 0x80800830: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_8080010C_chnastycavemen(rdram, ctx);
        goto after_16;
    // 0x80800830: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_16:
    // 0x80800834: bnel        $v0, $zero, L_80800848
    if (ctx->r2 != 0) {
        // 0x80800838: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_80800848;
    }
    goto skip_0;
    // 0x80800838: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x8080083C: jal         0x80085710
    // 0x80800840: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_17;
    // 0x80800840: nop

    after_17:
    // 0x80800844: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_80800848:
    // 0x80800848: lbu         $t1, 0x74($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X74);
    // 0x8080084C: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x80800850: sb          $t2, 0x74($t0)
    MEM_B(0X74, ctx->r8) = ctx->r10;
    // 0x80800854: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80800858: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x8080085C: lbu         $t5, 0x74($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X74);
    // 0x80800860: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80800864: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80800868: sll         $t6, $t8, 6
    ctx->r14 = S32(ctx->r24 << 6);
    // 0x8080086C: andi        $t9, $t6, 0x40
    ctx->r25 = ctx->r14 & 0X40;
    // 0x80800870: andi        $t1, $t5, 0xFFBF
    ctx->r9 = ctx->r13 & 0XFFBF;
    // 0x80800874: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800878: b           L_80800904
    // 0x8080087C: sb          $t2, 0x74($t3)
    MEM_B(0X74, ctx->r11) = ctx->r10;
        goto L_80800904;
    // 0x8080087C: sb          $t2, 0x74($t3)
    MEM_B(0X74, ctx->r11) = ctx->r10;
L_80800880:
    // 0x80800880: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800884: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(760, 0X118C) << 16);
    // 0x80800888: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(760, 0X117C) << 16);
    // 0x8080088C: addiu       $a3, $a3, 0x117C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(760, 0X117C));
    // 0x80800890: addiu       $a2, $a2, 0x118C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(760, 0X118C));
    // 0x80800894: jal         0x80089D28
    // 0x80800898: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x80800898: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_18:
    // 0x8080089C: lui         $a1, 0x3D16
    ctx->r5 = S32(0X3D16 << 16);
    // 0x808008A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008A4: jal         0x80101E14
    // 0x808008A8: ori         $a1, $a1, 0x52BD
    ctx->r5 = ctx->r5 | 0X52BD;
    func_80101E14(rdram, ctx);
        goto after_19;
    // 0x808008A8: ori         $a1, $a1, 0x52BD
    ctx->r5 = ctx->r5 | 0X52BD;
    after_19:
    // 0x808008AC: beq         $v0, $zero, L_808008C0
    if (ctx->r2 == 0) {
        // 0x808008B0: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_808008C0;
    }
    // 0x808008B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808008B4: lbu         $t7, 0x65($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X65);
    // 0x808008B8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808008BC: sb          $t8, 0x65($t0)
    MEM_B(0X65, ctx->r8) = ctx->r24;
L_808008C0:
    // 0x808008C0: jal         0x80101DDC
    // 0x808008C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80101DDC(rdram, ctx);
        goto after_20;
    // 0x808008C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_20:
    // 0x808008C8: beq         $v0, $zero, L_80800904
    if (ctx->r2 == 0) {
        // 0x808008CC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800904;
    }
    // 0x808008CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808008D4: jal         0x80800268
    // 0x808008D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_80800268_chnastycavemen(rdram, ctx);
        goto after_21;
    // 0x808008D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_21:
    // 0x808008DC: b           L_80800904
    // 0x808008E0: nop

        goto L_80800904;
    // 0x808008E0: nop

L_808008E4:
    // 0x808008E4: jal         0x808003FC
    // 0x808008E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808003FC_chnastycavemen(rdram, ctx);
        goto after_22;
    // 0x808008E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_22:
    // 0x808008EC: b           L_80800904
    // 0x808008F0: nop

        goto L_80800904;
    // 0x808008F0: nop

L_808008F4:
    // 0x808008F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(760, 0X10A0) << 16);
    // 0x808008F8: lwc1        $f4, 0x10A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(760, 0X10A0));
    // 0x808008FC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800900: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
L_80800904:
    // 0x80800904: jal         0x808004C4
    // 0x80800908: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808004C4_chnastycavemen(rdram, ctx);
        goto after_23;
    // 0x80800908: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_23:
    // 0x8080090C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80800910: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800914: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800918: lhu         $v0, 0x72($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X72);
    // 0x8080091C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80800920: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80800924: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x80800928: bne         $t9, $at, L_80800940
    if (ctx->r25 != ctx->r1) {
        // 0x8080092C: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80800940;
    }
    // 0x8080092C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80800930: jal         0x80085770
    // 0x80800934: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_24;
    // 0x80800934: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_24:
    // 0x80800938: b           L_8080095C
    // 0x8080093C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080095C;
    // 0x8080093C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800940:
    // 0x80800940: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800944: beq         $v0, $at, L_80800958
    if (ctx->r2 == ctx->r1) {
        // 0x80800948: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800958;
    }
    // 0x80800948: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080094C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800950: jal         0x80085770
    // 0x80800954: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_25;
    // 0x80800954: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_25:
L_80800958:
    // 0x80800958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080095C:
    // 0x8080095C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800960: jr          $ra
    // 0x80800964: nop

    return;
    // 0x80800964: nop

;}
RECOMP_FUNC void _ncpoducam_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089668: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089668);
    return;
    // 0x8008966C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bsride_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080028C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800290: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(348, 0X9C0) << 16);
    // 0x80800294: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800298: jr          $ra
    // 0x8080029C: lw          $v0, 0x9C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(348, 0X9C0));
    return;
    // 0x8080029C: lw          $v0, 0x9C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(348, 0X9C0));
;}
RECOMP_FUNC void _chrainbow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087620: syscall     598
    recomp_syscall_handler(rdram, ctx, 0x80087620);
    return;
    // 0x80087624: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gcboundDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EC8: syscall     661
    recomp_syscall_handler(rdram, ctx, 0x80087EC8);
    return;
    // 0x80087ECC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bawasher_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853F0: syscall     161
    recomp_syscall_handler(rdram, ctx, 0x800853F0);
    return;
    // 0x800853F4: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80800190_chfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800194: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800198: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x8080019C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A4: beq         $a1, $at, L_808001D0
    if (ctx->r5 == ctx->r1) {
        // 0x808001A8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808001D0;
    }
    // 0x808001A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808001AC: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x808001B0: beq         $a1, $at, L_80800200
    if (ctx->r5 == ctx->r1) {
        // 0x808001B4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80800200;
    }
    // 0x808001B4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808001B8: beq         $a1, $at, L_80800214
    if (ctx->r5 == ctx->r1) {
        // 0x808001BC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800214;
    }
    // 0x808001BC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808001C0: beq         $a1, $at, L_80800244
    if (ctx->r5 == ctx->r1) {
        // 0x808001C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800244;
    }
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: b           L_80800278
    // 0x808001CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800278;
    // 0x808001CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001D0:
    // 0x808001D0: jal         0x8080003C
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080003C_chfreezy(rdram, ctx);
        goto after_0;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808001D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001DC: jal         0x80089B90
    // 0x808001E0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sufreezy_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808001E0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808001E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001E8: jal         0x80089B88
    // 0x808001EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    _sufreezy_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808001EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x808001F0: jal         0x808006C0
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006C0_chfreezy(rdram, ctx);
        goto after_3;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001F8: b           L_80800278
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800278;
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800200:
    // 0x80800200: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800204: jal         0x80089B98
    // 0x80800208: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sufreezy_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800208: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8080020C: b           L_80800278
    // 0x80800210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800278;
    // 0x80800210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800214:
    // 0x80800214: jal         0x8080003C
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080003C_chfreezy(rdram, ctx);
        goto after_5;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080021C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800220: jal         0x80089BA0
    // 0x80800224: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sufreezy_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800224: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800228: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080022C: jal         0x80089B88
    // 0x80800230: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    _sufreezy_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800230: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_7:
    // 0x80800234: jal         0x800FFAB0
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080023C: b           L_80800278
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800278;
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800244:
    // 0x80800244: jal         0x80100094
    // 0x80800248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080024C: jal         0x8008A038
    // 0x80800250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x80800254: bnel        $v0, $zero, L_80800278
    if (ctx->r2 != 0) {
        // 0x80800258: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800278;
    }
    goto skip_0;
    // 0x80800258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080025C: jal         0x800FFAB0
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_11;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800264: b           L_80800278
    // 0x80800268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800278;
    // 0x80800268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080026C: b           L_80800278
    // 0x80800270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800278;
    // 0x80800270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800274: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800278:
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080027C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800280: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800284: jr          $ra
    // 0x80800288: nop

    return;
    // 0x80800288: nop

;}
RECOMP_FUNC void baswim_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C0: lw          $v0, 0x134($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X134);
    // 0x808002C4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002C8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808002CC: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x808002D0: nop

    // 0x808002D4: bc1f        L_808002E0
    if (!c1cs) {
        // 0x808002D8: nop
    
            goto L_808002E0;
    }
    // 0x808002D8: nop

    // 0x808002DC: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
L_808002E0:
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void gsattract_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: jr          $ra
    // 0x808001F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808001F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chboggygirl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1536, 0XCF0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xCF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1536, 0XCF0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xCF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1536, 0XCF0));
;}
RECOMP_FUNC void func_80800CA0_chfloaty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800CA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800CA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800CAC: jal         0x8010C710
    // 0x80800CB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8010C710(rdram, ctx);
        goto after_0;
    // 0x80800CB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800CB4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800CB8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2416, 0XDF0) << 16);
    // 0x80800CBC: lwc1        $f2, 0xDF0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2416, 0XDF0));
    // 0x80800CC0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800CC4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80800CC8: nop

    // 0x80800CCC: bc1fl       L_80800D10
    if (!c1cs) {
        // 0x80800CD0: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_80800D10;
    }
    goto skip_0;
    // 0x80800CD0: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80800CD4: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800CD8: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800CDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CE0: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800CE4: bgezl       $t8, L_80800D9C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800CE8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800D9C;
    }
    goto skip_1;
    // 0x80800CE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800CEC: jal         0x800FCAE0
    // 0x80800CF0: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    func_800FCAE0(rdram, ctx);
        goto after_1;
    // 0x80800CF0: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    after_1:
    // 0x80800CF4: jal         0x800FCA90
    // 0x80800CF8: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FCA90(rdram, ctx);
        goto after_2;
    // 0x80800CF8: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_2:
    // 0x80800CFC: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800D00: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80800D04: b           L_80800D98
    // 0x80800D08: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
        goto L_80800D98;
    // 0x80800D08: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800D0C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_80800D10:
    // 0x80800D10: lui         $a3, 0x46AB
    ctx->r7 = S32(0X46AB << 16);
    // 0x80800D14: ori         $a3, $a3, 0xE000
    ctx->r7 = ctx->r7 | 0XE000;
    // 0x80800D18: sll         $t1, $v0, 12
    ctx->r9 = S32(ctx->r2 << 12);
    // 0x80800D1C: srl         $v0, $t1, 31
    ctx->r2 = S32(U32(ctx->r9) >> 31);
    // 0x80800D20: beq         $v0, $zero, L_80800D5C
    if (ctx->r2 == 0) {
        // 0x80800D24: nop
    
            goto L_80800D5C;
    }
    // 0x80800D24: nop

    // 0x80800D28: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800D2C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800D30: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800D34: jal         0x800F10B4
    // 0x80800D38: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800D38: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80800D3C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800D40: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800D44: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    // 0x80800D48: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800D4C: jal         0x800FCAE0
    // 0x80800D50: nop

    func_800FCAE0(rdram, ctx);
        goto after_4;
    // 0x80800D50: nop

    after_4:
    // 0x80800D54: b           L_80800D9C
    // 0x80800D58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D9C;
    // 0x80800D58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D5C:
    // 0x80800D5C: bne         $v0, $zero, L_80800D98
    if (ctx->r2 != 0) {
        // 0x80800D60: lui         $a3, 0x46AB
        ctx->r7 = S32(0X46AB << 16);
            goto L_80800D98;
    }
    // 0x80800D60: lui         $a3, 0x46AB
    ctx->r7 = S32(0X46AB << 16);
    // 0x80800D64: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800D68: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800D6C: ori         $a3, $a3, 0xE000
    ctx->r7 = ctx->r7 | 0XE000;
    // 0x80800D70: jal         0x800F10B4
    // 0x80800D74: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800D74: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x80800D78: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800D7C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800D80: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800D84: jal         0x800FC618
    // 0x80800D88: nop

    func_800FC618(rdram, ctx);
        goto after_6;
    // 0x80800D88: nop

    after_6:
    // 0x80800D8C: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800D90: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80800D94: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_80800D98:
    // 0x80800D98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D9C:
    // 0x80800D9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800DA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800DA4: jr          $ra
    // 0x80800DA8: nop

    return;
    // 0x80800DA8: nop

;}
RECOMP_FUNC void func_808072C8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808072C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808072CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808072D0: jal         0x800A3404
    // 0x808072D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800A3404(rdram, ctx);
        goto after_0;
    // 0x808072D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808072D8: beql        $v0, $zero, L_808072FC
    if (ctx->r2 == 0) {
        // 0x808072DC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_808072FC;
    }
    goto skip_0;
    // 0x808072DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_0:
    // 0x808072E0: jal         0x800DB9B0
    // 0x808072E4: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x808072E4: nop

    after_1:
    // 0x808072E8: beql        $v0, $zero, L_808072FC
    if (ctx->r2 == 0) {
        // 0x808072EC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_808072FC;
    }
    goto skip_1;
    // 0x808072EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_1:
    // 0x808072F0: b           L_808072FC
    // 0x808072F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_808072FC;
    // 0x808072F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808072F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_808072FC:
    // 0x808072FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80807300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80807304: jal         0x8009337C
    // 0x80807308: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8009337C(rdram, ctx);
        goto after_2;
    // 0x80807308: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x8080730C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80807310: jal         0x800936E8
    // 0x80807314: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800936E8(rdram, ctx);
        goto after_3;
    // 0x80807314: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80807318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080731C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80807320: jr          $ra
    // 0x80807324: nop

    return;
    // 0x80807324: nop

;}
RECOMP_FUNC void func_808024BC_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808024C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808024C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808024C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808024CC: jal         0x80100094
    // 0x808024D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808024D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808024D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024D8: jal         0x80801C7C
    // 0x808024DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80801C7C_chinflatableboss(rdram, ctx);
        goto after_1;
    // 0x808024DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808024E0: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x808024E4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(832, 0X2D80) << 16);
    // 0x808024E8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x808024EC: lh          $t7, 0x2D80($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(832, 0X2D80));
    // 0x808024F0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808024F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808024F8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808024FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802500: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80802504: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802508: swc1        $f6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f6.u32l;
    // 0x8080250C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80802510: lbu         $t8, 0x497($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X497);
    // 0x80802514: beq         $t8, $zero, L_80802524
    if (ctx->r24 == 0) {
        // 0x80802518: nop
    
            goto L_80802524;
    }
    // 0x80802518: nop

    // 0x8080251C: b           L_80802524
    // 0x80802520: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_80802524;
    // 0x80802520: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_80802524:
    // 0x80802524: jal         0x80800F84
    // 0x80802528: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_2;
    // 0x80802528: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x8080252C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(832, 0X2D80) << 16);
    // 0x80802530: lh          $t9, 0x2D80($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(832, 0X2D80));
    // 0x80802534: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80802538: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080253C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80802540: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80802544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802548: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080254C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802550: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80802554: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80802558: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080255C: jal         0x80101CDC
    // 0x80802560: nop

    func_80101CDC(rdram, ctx);
        goto after_3;
    // 0x80802560: nop

    after_3:
    // 0x80802564: jal         0x80104248
    // 0x80802568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_4;
    // 0x80802568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080256C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80802570: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802574: jal         0x8008B1C8
    // 0x80802578: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_5;
    // 0x80802578: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8080257C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802580: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802588: jr          $ra
    // 0x8080258C: nop

    return;
    // 0x8080258C: nop

;}
RECOMP_FUNC void _vpglow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089070: syscall     758
    recomp_syscall_handler(rdram, ctx, 0x80089070);
    return;
    // 0x80089074: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bafly_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C50: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C50);
    return;
    // 0x80084C54: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void chnests_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FB0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X14B8) << 16);
    // 0x80800FB4: jr          $ra
    // 0x80800FB8: addiu       $v0, $v0, 0x14B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X14B8));
    return;
    // 0x80800FB8: addiu       $v0, $v0, 0x14B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X14B8));
;}
RECOMP_FUNC void _glsavegame_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088538: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088538);
    return;
    // 0x8008853C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chskeletonexplode_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E30: syscall     459
    recomp_syscall_handler(rdram, ctx, 0x80086E30);
    return;
    // 0x80086E34: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80801464_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801464: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801468: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080146C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801470: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801474: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801478: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080147C: jal         0x80100094
    // 0x80801480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801488: jal         0x800EE7F8
    // 0x8080148C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080148C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80801490: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801494: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801498: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080149C: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x808014A0: jal         0x800136E4
    // 0x808014A4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x808014A4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_2:
    // 0x808014A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808014AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014B0: jal         0x800EF1B8
    // 0x808014B4: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x808014B4: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_3:
    // 0x808014B8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808014BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014C0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808014C4: jal         0x800EF1B8
    // 0x808014C8: lw          $a1, 0x48($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x808014C8: lw          $a1, 0x48($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X48);
    after_4:
    // 0x808014CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808014D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808014D4: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808014D8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x808014DC: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x808014E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808014E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808014E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808014EC: jr          $ra
    // 0x808014F0: nop

    return;
    // 0x808014F0: nop

;}
RECOMP_FUNC void func_8008FDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FDC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FDC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FDCC: jal         0x800F54E4
    // 0x8008FDD0: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FDD0: nop

    after_0:
    // 0x8008FDD4: jal         0x800F55FC
    // 0x8008FDD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F55FC(rdram, ctx);
        goto after_1;
    // 0x8008FDD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FDDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FDE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FDE4: jr          $ra
    // 0x8008FDE8: nop

    return;
    // 0x8008FDE8: nop

;}
RECOMP_FUNC void func_80800A50_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A58: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800A5C: jal         0x80800238
    // 0x80800A60: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80800238_chhumba(rdram, ctx);
        goto after_0;
    // 0x80800A60: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800A64: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A68: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800A6C: jal         0x8010D254
    // 0x80800A70: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80800A70: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800A74: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800A78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X246C) << 16);
    // 0x80800A7C: lwc1        $f6, 0x246C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X246C));
    // 0x80800A80: lwc1        $f0, 0x38($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80800A84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X2470) << 16);
    // 0x80800A88: lwc1        $f16, 0x2470($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X2470));
    // 0x80800A8C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800A90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X2474) << 16);
    // 0x80800A94: lwc1        $f6, 0x2474($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X2474));
    // 0x80800A98: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800A9C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800AA0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800AA4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800AA8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800AAC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800AB0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800AB4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800AB8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800ABC: jal         0x8010C9FC
    // 0x80800AC0: nop

    func_8010C9FC(rdram, ctx);
        goto after_2;
    // 0x80800AC0: nop

    after_2:
    // 0x80800AC4: bne         $v0, $zero, L_80800AD4
    if (ctx->r2 != 0) {
        // 0x80800AC8: nop
    
            goto L_80800AD4;
    }
    // 0x80800AC8: nop

    // 0x80800ACC: b           L_80800B30
    // 0x80800AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B30;
    // 0x80800AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AD4:
    // 0x80800AD4: jal         0x800F54E4
    // 0x80800AD8: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800AD8: nop

    after_3:
    // 0x80800ADC: jal         0x800F71D4
    // 0x80800AE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F71D4(rdram, ctx);
        goto after_4;
    // 0x80800AE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800AE4: bne         $v0, $zero, L_80800AF4
    if (ctx->r2 != 0) {
        // 0x80800AE8: nop
    
            goto L_80800AF4;
    }
    // 0x80800AE8: nop

    // 0x80800AEC: b           L_80800B30
    // 0x80800AF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B30;
    // 0x80800AF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AF4:
    // 0x80800AF4: jal         0x800EA05C
    // 0x80800AF8: nop

    func_800EA05C(rdram, ctx);
        goto after_5;
    // 0x80800AF8: nop

    after_5:
    // 0x80800AFC: addiu       $at, $zero, 0x120
    ctx->r1 = ADD32(0, 0X120);
    // 0x80800B00: bne         $v0, $at, L_80800B2C
    if (ctx->r2 != ctx->r1) {
        // 0x80800B04: lwc1        $f18, 0x24($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80800B2C;
    }
    // 0x80800B04: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800B08: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80800B0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B10: nop

    // 0x80800B14: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800B18: nop

    // 0x80800B1C: bc1fl       L_80800B30
    if (!c1cs) {
        // 0x80800B20: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800B30;
    }
    goto skip_0;
    // 0x80800B20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800B24: b           L_80800B30
    // 0x80800B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B30;
    // 0x80800B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B2C:
    // 0x80800B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B30:
    // 0x80800B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800B38: jr          $ra
    // 0x80800B3C: nop

    return;
    // 0x80800B3C: nop

;}
RECOMP_FUNC void func_8010FF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FF88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010FF8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010FF90: jal         0x80114C9C
    // 0x8010FF94: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    func_80114C9C(rdram, ctx);
        goto after_0;
    // 0x8010FF94: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    after_0:
    // 0x8010FF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010FF9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010FFA0: jr          $ra
    // 0x8010FFA4: nop

    return;
    // 0x8010FFA4: nop

;}
RECOMP_FUNC void func_808009AC_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808009B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009B8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808009BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808009C0: jal         0x80089D10
    // 0x808009C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808009C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808009C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(916, 0XC4C) << 16);
    // 0x808009CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808009D0: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    // 0x808009D4: addiu       $a2, $a2, 0xC4C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(916, 0XC4C));
    // 0x808009D8: jal         0x800C4350
    // 0x808009DC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x808009DC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_1:
    // 0x808009E0: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    // 0x808009E4: jal         0x800C301C
    // 0x808009E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C301C(rdram, ctx);
        goto after_2;
    // 0x808009E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x808009EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(916, 0XADC) << 16);
    // 0x808009F0: lwc1        $f12, 0xADC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(916, 0XADC));
    // 0x808009F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(916, 0XAE0) << 16);
    // 0x808009F8: jal         0x800DC178
    // 0x808009FC: lwc1        $f14, 0xAE0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(916, 0XAE0));
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808009FC: lwc1        $f14, 0xAE0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(916, 0XAE0));
    after_3:
    // 0x80800A00: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800A04: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    // 0x80800A08: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800A0C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800A10: jal         0x800C31DC
    // 0x80800A14: nop

    func_800C31DC(rdram, ctx);
        goto after_4;
    // 0x80800A14: nop

    after_4:
    // 0x80800A18: jal         0x800C3BDC
    // 0x80800A1C: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    func_800C3BDC(rdram, ctx);
        goto after_5;
    // 0x80800A1C: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    after_5:
    // 0x80800A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A28: jr          $ra
    // 0x80800A2C: nop

    return;
    // 0x80800A2C: nop

;}
RECOMP_FUNC void func_808005D0_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005D4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808005D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005E0: beq         $a1, $at, L_80800608
    if (ctx->r5 == ctx->r1) {
        // 0x808005E4: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800608;
    }
    // 0x808005E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808005E8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808005EC: beq         $a1, $at, L_8080065C
    if (ctx->r5 == ctx->r1) {
        // 0x808005F0: lh          $v0, 0x28($sp)
        ctx->r2 = MEM_H(ctx->r29, 0X28);
            goto L_8080065C;
    }
    // 0x808005F0: lh          $v0, 0x28($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X28);
    // 0x808005F4: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x808005F8: beq         $a1, $at, L_808006D0
    if (ctx->r5 == ctx->r1) {
        // 0x808005FC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808006D0;
    }
    // 0x808005FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800600: b           L_80800710
    // 0x80800604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800710;
    // 0x80800604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800608:
    // 0x80800608: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080060C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800610: beq         $t6, $zero, L_80800654
    if (ctx->r14 == 0) {
        // 0x80800614: nop
    
            goto L_80800654;
    }
    // 0x80800614: nop

    // 0x80800618: bne         $t6, $at, L_80800628
    if (ctx->r14 != ctx->r1) {
        // 0x8080061C: addiu       $a0, $zero, 0x9EF
        ctx->r4 = ADD32(0, 0X9EF);
            goto L_80800628;
    }
    // 0x8080061C: addiu       $a0, $zero, 0x9EF
    ctx->r4 = ADD32(0, 0X9EF);
    // 0x80800620: jal         0x800DA3B8
    // 0x80800624: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_0;
    // 0x80800624: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_80800628:
    // 0x80800628: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080062C: jal         0x80100094
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800634: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800638: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080063C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800640: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800644: jal         0x8008A2C8
    // 0x80800648: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800648: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8080064C: b           L_80800710
    // 0x80800650: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800710;
    // 0x80800650: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800654:
    // 0x80800654: b           L_80800710
    // 0x80800658: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800710;
    // 0x80800658: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080065C:
    // 0x8080065C: addiu       $at, $zero, 0xFF3
    ctx->r1 = ADD32(0, 0XFF3);
    // 0x80800660: beq         $v0, $at, L_8080069C
    if (ctx->r2 == ctx->r1) {
        // 0x80800664: addiu       $a0, $zero, 0x9EE
        ctx->r4 = ADD32(0, 0X9EE);
            goto L_8080069C;
    }
    // 0x80800664: addiu       $a0, $zero, 0x9EE
    ctx->r4 = ADD32(0, 0X9EE);
    // 0x80800668: addiu       $at, $zero, 0xFF4
    ctx->r1 = ADD32(0, 0XFF4);
    // 0x8080066C: beq         $v0, $at, L_80800680
    if (ctx->r2 == ctx->r1) {
        // 0x80800670: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800680;
    }
    // 0x80800670: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800674: addiu       $at, $zero, 0xFF5
    ctx->r1 = ADD32(0, 0XFF5);
    // 0x80800678: bnel        $v0, $at, L_80800710
    if (ctx->r2 != ctx->r1) {
        // 0x8080067C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800710;
    }
    goto skip_0;
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_80800680:
    // 0x80800680: jal         0x80100094
    // 0x80800684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800688: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080068C: jal         0x8008A2C0
    // 0x80800690: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800690: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80800694: b           L_80800710
    // 0x80800698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800710;
    // 0x80800698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080069C:
    // 0x8080069C: jal         0x800DA3B8
    // 0x808006A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_5;
    // 0x808006A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808006A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006A8: jal         0x8080000C
    // 0x808006AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080000C_chlagoonufoint(rdram, ctx);
        goto after_6;
    // 0x808006AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808006B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006B4: jal         0x80100094
    // 0x808006B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x808006B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808006BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006C0: jal         0x8008A2C0
    // 0x808006C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x808006C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x808006C8: b           L_80800710
    // 0x808006CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800710;
    // 0x808006CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006D0:
    // 0x808006D0: jal         0x80100094
    // 0x808006D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x808006D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808006D8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x808006DC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808006E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006E4: and         $a3, $v1, $at
    ctx->r7 = ctx->r3 & ctx->r1;
    // 0x808006E8: srl         $t7, $a3, 16
    ctx->r15 = S32(U32(ctx->r7) >> 16);
    // 0x808006EC: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x808006F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808006F4: jal         0x8008A2B8
    // 0x808006F8: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808006F8: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
    after_10:
    // 0x808006FC: b           L_80800714
    // 0x80800700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800714;
    // 0x80800700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800704: b           L_80800710
    // 0x80800708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800710;
    // 0x80800708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080070C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800710:
    // 0x80800710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800714:
    // 0x80800714: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800718: jr          $ra
    // 0x8080071C: nop

    return;
    // 0x8080071C: nop

;}
RECOMP_FUNC void bakaztorpedo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lw          $t6, 0xB0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB0);
    // 0x8080000C: jr          $ra
    // 0x80800010: lwc1        $f0, 0x10($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X10);
    return;
    // 0x80800010: lwc1        $f0, 0x10($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X10);
;}
RECOMP_FUNC void func_800D5944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5944: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D5948: jr          $ra
    // 0x800D594C: lw          $v0, -0x4818($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4818);
    return;
    // 0x800D594C: lw          $v0, -0x4818($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4818);
;}
RECOMP_FUNC void func_800DA980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA980: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DA984: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800DA988: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800DA98C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DA990: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800DA994: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DA998: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DA99C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800DA9A0: blez        $a1, L_800DA9C4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800DA9A4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800DA9C4;
    }
    // 0x800DA9A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800DA9A8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
L_800DA9AC:
    // 0x800DA9AC: jal         0x800DA298
    // 0x800DA9B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800DA9B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800DA9B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800DA9B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800DA9BC: bne         $s0, $s3, L_800DA9AC
    if (ctx->r16 != ctx->r19) {
        // 0x800DA9C0: addu        $s2, $s2, $v0
        ctx->r18 = ADD32(ctx->r18, ctx->r2);
            goto L_800DA9AC;
    }
    // 0x800DA9C0: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_800DA9C4:
    // 0x800DA9C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DA9C8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800DA9CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA9D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DA9D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DA9D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800DA9DC: jr          $ra
    // 0x800DA9E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800DA9E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bsvanswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841B0: syscall     106
    recomp_syscall_handler(rdram, ctx, 0x800841B0);
    return;
    // 0x800841B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800960_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800960: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800964: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800968: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080096C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800970: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x80800974: jal         0x80088840
    // 0x80800978: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80800978: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080097C: beq         $v0, $zero, L_808009C0
    if (ctx->r2 == 0) {
        // 0x80800980: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808009C0;
    }
    // 0x80800980: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800984: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80800988: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080098C: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800990: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80800994: andi        $t9, $t8, 0x410
    ctx->r25 = ctx->r24 & 0X410;
    // 0x80800998: beq         $t9, $zero, L_808009A4
    if (ctx->r25 == 0) {
        // 0x8080099C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808009A4;
    }
    // 0x8080099C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808009A0: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
L_808009A4:
    // 0x808009A4: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x808009A8: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x808009AC: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x808009B0: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x808009B4: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x808009B8: b           L_808009F4
    // 0x808009BC: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
        goto L_808009F4;
    // 0x808009BC: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
L_808009C0:
    // 0x808009C0: lw          $t5, 0x6C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X6C);
    // 0x808009C4: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808009C8: addiu       $v0, $t5, -0x1
    ctx->r2 = ADD32(ctx->r13, -0X1);
    // 0x808009CC: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x808009D0: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808009D4: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808009D8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808009DC: bne         $t6, $zero, L_808009F4
    if (ctx->r14 != 0) {
        // 0x808009E0: sh          $t0, 0x6E($s0)
        MEM_H(0X6E, ctx->r16) = ctx->r8;
            goto L_808009F4;
    }
    // 0x808009E0: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x808009E4: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x808009E8: ori         $t3, $t1, 0x8
    ctx->r11 = ctx->r9 | 0X8;
    // 0x808009EC: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    // 0x808009F0: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
L_808009F4:
    // 0x808009F4: jal         0x80108B04
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80108B04(rdram, ctx);
        goto after_1;
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808009FC: jal         0x80800410
    // 0x80800A00: nop

    func_80800410_chtoxicroombits(rdram, ctx);
        goto after_2;
    // 0x80800A00: nop

    after_2:
    // 0x80800A04: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x80800A08: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80800A0C: andi        $t7, $t8, 0xFF0F
    ctx->r15 = ctx->r24 & 0XFF0F;
    // 0x80800A10: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80800A14: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
    // 0x80800A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A24: jr          $ra
    // 0x80800A28: nop

    return;
    // 0x80800A28: nop

;}
RECOMP_FUNC void func_80800248_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800248: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080024C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800250: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800254: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800258: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080025C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800260: jal         0x8008CDB8
    // 0x80800264: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x80800264: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    after_0:
    // 0x80800268: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8080026C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800278: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080027C: jal         0x8009FFD8
    // 0x80800280: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800280: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800284: jal         0x8009EF04
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_2;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080028C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800290: nop

    // 0x80800294: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800298: nop

    // 0x8080029C: bc1t        L_808002B8
    if (c1cs) {
        // 0x808002A0: nop
    
            goto L_808002B8;
    }
    // 0x808002A0: nop

    // 0x808002A4: jal         0x8009EEB8
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_3;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002B0: jal         0x8009C914
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_4;
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808002B8:
    // 0x808002B8: jal         0x8009C990
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_5;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002C4: jal         0x8009B9C0
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_6;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: jal         0x8009BA9C
    // 0x808002D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_7;
    // 0x808002D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: jal         0x8009B9B0
    // 0x808002E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x808002E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: jal         0x8009BCB4
    // 0x808002EC: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_9;
    // 0x808002EC: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_9:
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: jal         0x800A0CF4
    // 0x808002F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_10;
    // 0x808002F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808002FC: jal         0x8009D874
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_11;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800304: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800308: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x8080030C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800310: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800318: jr          $ra
    // 0x8080031C: nop

    return;
    // 0x8080031C: nop

;}
RECOMP_FUNC void _glid_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088660: syscall     697
    recomp_syscall_handler(rdram, ctx, 0x80088660);
    return;
    // 0x80088664: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chfactorybattery_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087480: syscall     577
    recomp_syscall_handler(rdram, ctx, 0x80087480);
    return;
    // 0x80087484: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080154C_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080154C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801550: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801554: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801558: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080155C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801560: jal         0x8010C500
    // 0x80801564: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x80801564: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x80801568: bne         $v0, $zero, L_80801574
    if (ctx->r2 != 0) {
        // 0x8080156C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80801574;
    }
    // 0x8080156C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801570: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80801574:
    // 0x80801574: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80801578: addiu       $at, $zero, 0x2C2
    ctx->r1 = ADD32(0, 0X2C2);
    // 0x8080157C: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80801580: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x80801584: beq         $t8, $at, L_808015A4
    if (ctx->r24 == ctx->r1) {
        // 0x80801588: nop
    
            goto L_808015A4;
    }
    // 0x80801588: nop

    // 0x8080158C: jal         0x8010C9B0
    // 0x80801590: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    func_8010C9B0(rdram, ctx);
        goto after_1;
    // 0x80801590: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    after_1:
    // 0x80801594: bne         $v0, $zero, L_808015F8
    if (ctx->r2 != 0) {
        // 0x80801598: nop
    
            goto L_808015F8;
    }
    // 0x80801598: nop

    // 0x8080159C: b           L_808015F8
    // 0x808015A0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_808015F8;
    // 0x808015A0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_808015A4:
    // 0x808015A4: jal         0x80800CAC
    // 0x808015A8: nop

    func_80800CAC_chpiranha(rdram, ctx);
        goto after_2;
    // 0x808015A8: nop

    after_2:
    // 0x808015AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1B08) << 16);
    // 0x808015B0: lwc1        $f4, 0x1B08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1B08));
    // 0x808015B4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x808015B8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808015BC: nop

    // 0x808015C0: bc1f        L_808015F8
    if (!c1cs) {
        // 0x808015C4: nop
    
            goto L_808015F8;
    }
    // 0x808015C4: nop

    // 0x808015C8: jal         0x800DC128
    // 0x808015CC: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x808015CC: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_3:
    // 0x808015D0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x808015D4: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808015D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808015DC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808015E0: nop

    // 0x808015E4: bc1f        L_808015F8
    if (!c1cs) {
        // 0x808015E8: nop
    
            goto L_808015F8;
    }
    // 0x808015E8: nop

    // 0x808015EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808015F0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x808015F4: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_808015F8:
    // 0x808015F8: beq         $s1, $zero, L_80801624
    if (ctx->r17 == 0) {
        // 0x808015FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801624;
    }
    // 0x808015FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801600: jal         0x80800218
    // 0x80801604: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800218_chpiranha(rdram, ctx);
        goto after_4;
    // 0x80801604: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80801608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080160C: jal         0x80100094
    // 0x80801610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80801610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80801614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801618: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8080161C: jal         0x80800EFC
    // 0x80801620: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_80800EFC_chpiranha(rdram, ctx);
        goto after_6;
    // 0x80801620: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_6:
L_80801624:
    // 0x80801624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801628: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080162C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801630: jr          $ra
    // 0x80801634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void find_free_block(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AAE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001AAE8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001AAEC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001AAF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001AAF4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001AAF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001AAFC: beq         $a1, $zero, L_8001ABC4
    if (ctx->r5 == 0) {
        // 0x8001AB00: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8001ABC4;
    }
    // 0x8001AB00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001AB04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001AB08: beq         $a1, $at, L_8001AB24
    if (ctx->r5 == ctx->r1) {
        // 0x8001AB0C: lui         $s2, 0x8008
        ctx->r18 = S32(0X8008 << 16);
            goto L_8001AB24;
    }
    // 0x8001AB0C: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8001AB10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001AB14: beq         $a1, $at, L_8001AC70
    if (ctx->r5 == ctx->r1) {
        // 0x8001AB18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001AC70;
    }
    // 0x8001AB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AB1C: b           L_8001AC80
    // 0x8001AB20: nop

        goto L_8001AC80;
    // 0x8001AB20: nop

L_8001AB24:
    // 0x8001AB24: addiu       $s2, $s2, -0x1670
    ctx->r18 = ADD32(ctx->r18, -0X1670);
    // 0x8001AB28: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001AB2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001AB30: jal         0x8001B3E8
    // 0x8001AB34: lw          $s0, 0x14($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X14);
    heap_bytes_allocated(rdram, ctx);
        goto after_0;
    // 0x8001AB34: lw          $s0, 0x14($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X14);
    after_0:
    // 0x8001AB38: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8001AB3C: addiu       $t7, $s0, 0x20
    ctx->r15 = ADD32(ctx->r16, 0X20);
    // 0x8001AB40: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8001AB44: beq         $t7, $t9, L_8001AB8C
    if (ctx->r15 == ctx->r25) {
        // 0x8001AB48: nop
    
            goto L_8001AB8C;
    }
    // 0x8001AB48: nop

    // 0x8001AB4C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
L_8001AB50:
    // 0x8001AB50: subu        $t1, $t0, $s0
    ctx->r9 = SUB32(ctx->r8, ctx->r16);
    // 0x8001AB54: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x8001AB58: sltu        $at, $t2, $s3
    ctx->r1 = ctx->r10 < ctx->r19 ? 1 : 0;
    // 0x8001AB5C: bne         $at, $zero, L_8001AB70
    if (ctx->r1 != 0) {
        // 0x8001AB60: sltu        $at, $s1, $s0
        ctx->r1 = ctx->r17 < ctx->r16 ? 1 : 0;
            goto L_8001AB70;
    }
    // 0x8001AB60: sltu        $at, $s1, $s0
    ctx->r1 = ctx->r17 < ctx->r16 ? 1 : 0;
    // 0x8001AB64: beq         $at, $zero, L_8001AB70
    if (ctx->r1 == 0) {
        // 0x8001AB68: nop
    
            goto L_8001AB70;
    }
    // 0x8001AB68: nop

    // 0x8001AB6C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_8001AB70:
    // 0x8001AB70: jal         0x8001B3E8
    // 0x8001AB74: lw          $s0, 0x14($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X14);
    heap_bytes_allocated(rdram, ctx);
        goto after_1;
    // 0x8001AB74: lw          $s0, 0x14($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X14);
    after_1:
    // 0x8001AB78: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8001AB7C: addiu       $t3, $s0, 0x20
    ctx->r11 = ADD32(ctx->r16, 0X20);
    // 0x8001AB80: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8001AB84: bnel        $t3, $t5, L_8001AB50
    if (ctx->r11 != ctx->r13) {
        // 0x8001AB88: lw          $t0, 0x4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X4);
            goto L_8001AB50;
    }
    goto skip_0;
    // 0x8001AB88: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    skip_0:
L_8001AB8C:
    // 0x8001AB8C: bnel        $s1, $zero, L_8001ABA0
    if (ctx->r17 != 0) {
        // 0x8001AB90: lw          $t6, 0x4($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X4);
            goto L_8001ABA0;
    }
    goto skip_1;
    // 0x8001AB90: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    skip_1:
    // 0x8001AB94: b           L_8001AC80
    // 0x8001AB98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AC80;
    // 0x8001AB98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AB9C: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
L_8001ABA0:
    // 0x8001ABA0: subu        $t8, $t6, $s1
    ctx->r24 = SUB32(ctx->r14, ctx->r17);
    // 0x8001ABA4: addiu       $t7, $t8, -0x10
    ctx->r15 = ADD32(ctx->r24, -0X10);
    // 0x8001ABA8: sltu        $at, $t7, $s3
    ctx->r1 = ctx->r15 < ctx->r19 ? 1 : 0;
    // 0x8001ABAC: beq         $at, $zero, L_8001ABBC
    if (ctx->r1 == 0) {
        // 0x8001ABB0: nop
    
            goto L_8001ABBC;
    }
    // 0x8001ABB0: nop

    // 0x8001ABB4: b           L_8001AC80
    // 0x8001ABB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AC80;
    // 0x8001ABB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ABBC:
    // 0x8001ABBC: b           L_8001AC80
    // 0x8001ABC0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8001AC80;
    // 0x8001ABC0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8001ABC4:
    // 0x8001ABC4: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8001ABC8: addiu       $s2, $s2, -0x1670
    ctx->r18 = ADD32(ctx->r18, -0X1670);
    // 0x8001ABCC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8001ABD0: lw          $s0, 0x14($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X14);
    // 0x8001ABD4: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8001ABD8: subu        $t1, $t0, $s0
    ctx->r9 = SUB32(ctx->r8, ctx->r16);
    // 0x8001ABDC: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x8001ABE0: sltu        $at, $t2, $s3
    ctx->r1 = ctx->r10 < ctx->r19 ? 1 : 0;
    // 0x8001ABE4: beql        $at, $zero, L_8001AC4C
    if (ctx->r1 == 0) {
        // 0x8001ABE8: lw          $t2, 0x4($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X4);
            goto L_8001AC4C;
    }
    goto skip_2;
    // 0x8001ABE8: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x8001ABEC: jal         0x8001B3E8
    // 0x8001ABF0: nop

    heap_bytes_allocated(rdram, ctx);
        goto after_2;
    // 0x8001ABF0: nop

    after_2:
    // 0x8001ABF4: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x8001ABF8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8001ABFC: addiu       $t4, $v1, 0x20
    ctx->r12 = ADD32(ctx->r3, 0X20);
    // 0x8001AC00: addu        $t5, $v0, $t3
    ctx->r13 = ADD32(ctx->r2, ctx->r11);
    // 0x8001AC04: beql        $t4, $t5, L_8001AC4C
    if (ctx->r12 == ctx->r13) {
        // 0x8001AC08: lw          $t2, 0x4($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X4);
            goto L_8001AC4C;
    }
    goto skip_3;
    // 0x8001AC08: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    skip_3:
    // 0x8001AC0C: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
L_8001AC10:
    // 0x8001AC10: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8001AC14: subu        $t8, $t6, $v1
    ctx->r24 = SUB32(ctx->r14, ctx->r3);
    // 0x8001AC18: addiu       $t7, $t8, -0x10
    ctx->r15 = ADD32(ctx->r24, -0X10);
    // 0x8001AC1C: sltu        $at, $t7, $s3
    ctx->r1 = ctx->r15 < ctx->r19 ? 1 : 0;
    // 0x8001AC20: beql        $at, $zero, L_8001AC4C
    if (ctx->r1 == 0) {
        // 0x8001AC24: lw          $t2, 0x4($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X4);
            goto L_8001AC4C;
    }
    goto skip_4;
    // 0x8001AC24: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    skip_4:
    // 0x8001AC28: jal         0x8001B3E8
    // 0x8001AC2C: nop

    heap_bytes_allocated(rdram, ctx);
        goto after_3;
    // 0x8001AC2C: nop

    after_3:
    // 0x8001AC30: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x8001AC34: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8001AC38: addiu       $t9, $v1, 0x20
    ctx->r25 = ADD32(ctx->r3, 0X20);
    // 0x8001AC3C: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8001AC40: bnel        $t9, $t1, L_8001AC10
    if (ctx->r25 != ctx->r9) {
        // 0x8001AC44: lw          $t6, 0x4($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X4);
            goto L_8001AC10;
    }
    goto skip_5;
    // 0x8001AC44: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    skip_5:
    // 0x8001AC48: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
L_8001AC4C:
    // 0x8001AC4C: subu        $t3, $t2, $s0
    ctx->r11 = SUB32(ctx->r10, ctx->r16);
    // 0x8001AC50: addiu       $t4, $t3, -0x10
    ctx->r12 = ADD32(ctx->r11, -0X10);
    // 0x8001AC54: sltu        $at, $t4, $s3
    ctx->r1 = ctx->r12 < ctx->r19 ? 1 : 0;
    // 0x8001AC58: beq         $at, $zero, L_8001AC68
    if (ctx->r1 == 0) {
        // 0x8001AC5C: nop
    
            goto L_8001AC68;
    }
    // 0x8001AC5C: nop

    // 0x8001AC60: b           L_8001AC80
    // 0x8001AC64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AC80;
    // 0x8001AC64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001AC68:
    // 0x8001AC68: b           L_8001AC80
    // 0x8001AC6C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8001AC80;
    // 0x8001AC6C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8001AC70:
    // 0x8001AC70: jal         0x8001C0A0
    // 0x8001AC74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8001C0A0(rdram, ctx);
        goto after_4;
    // 0x8001AC74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x8001AC78: b           L_8001AC84
    // 0x8001AC7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001AC84;
    // 0x8001AC7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001AC80:
    // 0x8001AC80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001AC84:
    // 0x8001AC84: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001AC88: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001AC8C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AC90: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001AC94: jr          $ra
    // 0x8001AC98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001AC98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bainput_should_rotate_camera_right(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097B94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097B9C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80097BA0: jal         0x800979D8
    // 0x80097BA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    static_16_800979D8(rdram, ctx);
        goto after_0;
    // 0x80097BA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80097BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097BAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097BB0: jr          $ra
    // 0x80097BB4: nop

    return;
    // 0x80097BB4: nop

;}
RECOMP_FUNC void func_808007A4_chtrashcompactor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007B0: jal         0x80085808
    // 0x808007B4: addiu       $a1, $zero, 0x9F5
    ctx->r5 = ADD32(0, 0X9F5);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808007B4: addiu       $a1, $zero, 0x9F5
    ctx->r5 = ADD32(0, 0X9F5);
    after_0:
    // 0x808007B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007BC: jal         0x80085810
    // 0x808007C0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808007C0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // 0x808007C4: jal         0x80085818
    // 0x808007C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808007C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808007CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007D4: jr          $ra
    // 0x808007D8: nop

    return;
    // 0x808007D8: nop

;}
RECOMP_FUNC void func_808000BC_chtemplelobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C4: jal         0x808000E4
    // 0x808000C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000E4_chtemplelobbydoor(rdram, ctx);
        goto after_0;
    // 0x808000C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000CC: jal         0x80086240
    // 0x808000D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808000D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void func_801066C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801066C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801066C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801066C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801066CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801066D0: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    // 0x801066D4: jal         0x800B2EA0
    // 0x801066D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    vector_erase_unordered(rdram, ctx);
        goto after_0;
    // 0x801066D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x801066DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801066E0: jal         0x800B2928
    // 0x801066E4: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    vector_size(rdram, ctx);
        goto after_1;
    // 0x801066E4: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    after_1:
    // 0x801066E8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801066EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801066F0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801066F4: beql        $at, $zero, L_80106724
    if (ctx->r1 == 0) {
        // 0x801066F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106724;
    }
    goto skip_0;
    // 0x801066F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801066FC: jal         0x800B28CC
    // 0x80106700: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    vector_at(rdram, ctx);
        goto after_2;
    // 0x80106700: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    after_2:
    // 0x80106704: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80106708: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8010670C: lhu         $t0, 0x1A($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X1A);
    // 0x80106710: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x80106714: andi        $t1, $t0, 0x1F
    ctx->r9 = ctx->r8 & 0X1F;
    // 0x80106718: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8010671C: sh          $t2, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r10;
    // 0x80106720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106724:
    // 0x80106724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106728: jr          $ra
    // 0x8010672C: nop

    return;
    // 0x8010672C: nop

;}
