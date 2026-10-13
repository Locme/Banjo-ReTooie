#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsbwhirl_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DE0: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DE0);
    return;
    // 0x80082DE4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800140_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800148: jal         0x80091A58
    // 0x8080014C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x8080014C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void func_80800068_bsmummove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080006C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800078: jal         0x8008CABC
    // 0x8080007C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080007C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800080: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800084: jal         0x80083808
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsmum_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080008C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: jal         0x8009E710
    // 0x80800098: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    bs_getPreviousState(rdram, ctx);
        goto after_2;
    // 0x80800098: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8080009C: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x808000A0: bne         $v0, $at, L_808000F0
    if (ctx->r2 != ctx->r1) {
        // 0x808000A4: nop
    
            goto L_808000F0;
    }
    // 0x808000A4: nop

    // 0x808000A8: jal         0x8008CAC8
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_3;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000B0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808000B4: jal         0x8009BB5C
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_4;
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000BC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808000C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000C4: nop

    // 0x808000C8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808000CC: nop

    // 0x808000D0: bc1f        L_808000F0
    if (!c1cs) {
        // 0x808000D4: nop
    
            goto L_808000F0;
    }
    // 0x808000D4: nop

    // 0x808000D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000E8: jal         0x800849E0
    // 0x808000EC: nop

    _badust_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808000EC: nop

    after_5:
L_808000F0:
    // 0x808000F0: jal         0x8008AF24
    // 0x808000F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_reset(rdram, ctx);
        goto after_6;
    // 0x808000F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x808000F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000FC: jal         0x8008AED4
    // 0x80800100: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    anctrl_setIndex(rdram, ctx);
        goto after_7;
    // 0x80800100: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    after_7:
    // 0x80800104: lui         $a1, 0x3F28
    ctx->r5 = S32(0X3F28 << 16);
    // 0x80800108: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x8080010C: jal         0x8008B1BC
    // 0x80800110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_8;
    // 0x80800110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80800114: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800118: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080011C: jal         0x8008B1C8
    // 0x80800120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_9;
    // 0x80800120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80800124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800128: jal         0x8008B24C
    // 0x8080012C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setStart(rdram, ctx);
        goto after_10;
    // 0x8080012C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x80800130: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800134: jal         0x8008B134
    // 0x80800138: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_11;
    // 0x80800138: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x8080013C: jal         0x8008B064
    // 0x80800140: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_12;
    // 0x80800140: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80800144: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800148: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800154: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800158: jal         0x8009FFD8
    // 0x8080015C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_13;
    // 0x8080015C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x80800160: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800164: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x8008C9BC
    // 0x80800170: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_14;
    // 0x80800170: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_14:
    // 0x80800174: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(320, 0X5A0) << 16);
    // 0x80800178: lwc1        $f8, 0x5A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(320, 0X5A0));
    // 0x8080017C: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x80800180: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x8080018C: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x80800190: jal         0x8008C9F0
    // 0x80800194: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_15;
    // 0x80800194: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x8008CA30
    // 0x808001A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_16;
    // 0x808001A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_16:
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808001AC: jal         0x8009BFE4
    // 0x808001B0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_17;
    // 0x808001B0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_17:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808001BC: jal         0x8009C554
    // 0x808001C0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_18;
    // 0x808001C0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_18:
    // 0x808001C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001C8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808001CC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808001D0: jr          $ra
    // 0x808001D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808001D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080181C_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080181C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801824: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801828: jal         0x80100094
    // 0x8080182C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080182C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801830: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801834: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801838: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8080183C: lwc1        $f12, 0x24($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X24);
    // 0x80801840: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801844: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80801848: nop

    // 0x8080184C: bc1fl       L_8080186C
    if (!c1cs) {
        // 0x80801850: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8080186C;
    }
    goto skip_0;
    // 0x80801850: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80801854: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801858: jal         0x800F0E00
    // 0x8080185C: nop

    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x8080185C: nop

    after_1:
    // 0x80801860: b           L_8080186C
    // 0x80801864: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8080186C;
    // 0x80801864: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80801868: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8080186C:
    // 0x8080186C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X2268) << 16);
    // 0x80801870: lwc1        $f4, 0x2268($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2268));
    // 0x80801874: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80801878: jal         0x80107C00
    // 0x8080187C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_80107C00(rdram, ctx);
        goto after_2;
    // 0x8080187C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80801880: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80801884: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80801888: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8080188C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80801890: lwc1        $f12, 0x24($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X24);
    // 0x80801894: lwc1        $f14, 0xC($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80801898: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8080189C: jal         0x800F15F8
    // 0x808018A0: nop

    func_800F15F8(rdram, ctx);
        goto after_3;
    // 0x808018A0: nop

    after_3:
    // 0x808018A4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808018A8: swc1        $f0, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f0.u32l;
    // 0x808018AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808018B4: jr          $ra
    // 0x808018B8: nop

    return;
    // 0x808018B8: nop

;}
RECOMP_FUNC void func_80800248_bskazfly(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x80800264: addiu       $a1, $zero, 0xAB
    ctx->r5 = ADD32(0, 0XAB);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x80800264: addiu       $a1, $zero, 0xAB
    ctx->r5 = ADD32(0, 0XAB);
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
RECOMP_FUNC void func_80800240_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800248: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080024C: jal         0x80089828
    // 0x80800250: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800250: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800254: beq         $v0, $zero, L_80800264
    if (ctx->r2 == 0) {
        // 0x80800258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800264;
    }
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: jal         0x800897C8
    // 0x80800260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80800264:
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: jal         0x80100094
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: jal         0x8008A2B0
    // 0x80800278: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800278: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8080027C: beq         $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x80800280: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800298;
    }
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: jal         0x80100094
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x8008A2C0
    // 0x80800294: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800294: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
L_80800298:
    // 0x80800298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080029C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808019D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808019E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808019E4: jal         0x80100094
    // 0x808019E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808019E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808019EC: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x808019F0: srl         $t6, $a0, 28
    ctx->r14 = S32(U32(ctx->r4) >> 28);
    // 0x808019F4: jal         0x8008A240
    // 0x808019F8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808019F8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x808019FC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A00: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801A04: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80801A08: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80801A0C: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x80801A10: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80801A14: addu        $t0, $a2, $v1
    ctx->r8 = ADD32(ctx->r6, ctx->r3);
    // 0x80801A18: bnel        $t9, $zero, L_80801A2C
    if (ctx->r25 != 0) {
        // 0x80801A1C: lh          $t1, 0xA($t0)
        ctx->r9 = MEM_H(ctx->r8, 0XA);
            goto L_80801A2C;
    }
    goto skip_0;
    // 0x80801A1C: lh          $t1, 0xA($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XA);
    skip_0:
    // 0x80801A20: b           L_80801A6C
    // 0x80801A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801A6C;
    // 0x80801A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801A28: lh          $t1, 0xA($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XA);
L_80801A2C:
    // 0x80801A2C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80801A30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801A34: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80801A38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801A3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801A40: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801A44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801A48: jal         0x80101E14
    // 0x80801A4C: nop

    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x80801A4C: nop

    after_2:
    // 0x80801A50: beq         $v0, $zero, L_80801A68
    if (ctx->r2 == 0) {
        // 0x80801A54: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801A68;
    }
    // 0x80801A54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801A58: jal         0x80801A7C
    // 0x80801A5C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    sucoaster_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x80801A5C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801A60: b           L_80801A6C
    // 0x80801A64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801A6C;
    // 0x80801A64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801A68:
    // 0x80801A68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801A6C:
    // 0x80801A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A74: jr          $ra
    // 0x80801A78: nop

    return;
    // 0x80801A78: nop

;}
RECOMP_FUNC void func_800C79EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79EC: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x800C79F0: lbu         $v1, 0x3($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X3);
    // 0x800C79F4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800C79F8: beql        $at, $zero, L_800C7A0C
    if (ctx->r1 == 0) {
        // 0x800C79FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C7A0C;
    }
    goto skip_0;
    // 0x800C79FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x800C7A00: jr          $ra
    // 0x800C7A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C7A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7A08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800C7A0C:
    // 0x800C7A0C: bnel        $v0, $at, L_800C7A24
    if (ctx->r2 != ctx->r1) {
        // 0x800C7A10: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800C7A24;
    }
    goto skip_1;
    // 0x800C7A10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x800C7A14: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800C7A18: jr          $ra
    // 0x800C7A1C: addiu       $v0, $v0, -0x6F28
    ctx->r2 = ADD32(ctx->r2, -0X6F28);
    return;
    // 0x800C7A1C: addiu       $v0, $v0, -0x6F28
    ctx->r2 = ADD32(ctx->r2, -0X6F28);
    // 0x800C7A20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800C7A24:
    // 0x800C7A24: bne         $v0, $at, L_800C7A34
    if (ctx->r2 != ctx->r1) {
        // 0x800C7A28: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_800C7A34;
    }
    // 0x800C7A28: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800C7A2C: jr          $ra
    // 0x800C7A30: addiu       $v0, $v0, -0x6F18
    ctx->r2 = ADD32(ctx->r2, -0X6F18);
    return;
    // 0x800C7A30: addiu       $v0, $v0, -0x6F18
    ctx->r2 = ADD32(ctx->r2, -0X6F18);
L_800C7A34:
    // 0x800C7A34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C7A38: bne         $v1, $at, L_800C7A4C
    if (ctx->r3 != ctx->r1) {
        // 0x800C7A3C: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_800C7A4C;
    }
    // 0x800C7A3C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800C7A40: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800C7A44: jr          $ra
    // 0x800C7A48: addiu       $v0, $v0, -0x6F00
    ctx->r2 = ADD32(ctx->r2, -0X6F00);
    return;
    // 0x800C7A48: addiu       $v0, $v0, -0x6F00
    ctx->r2 = ADD32(ctx->r2, -0X6F00);
L_800C7A4C:
    // 0x800C7A4C: addiu       $v0, $v0, -0x6F08
    ctx->r2 = ADD32(ctx->r2, -0X6F08);
    // 0x800C7A50: jr          $ra
    // 0x800C7A54: nop

    return;
    // 0x800C7A54: nop

;}
RECOMP_FUNC void func_80800B28_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B28: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800B2C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80800B30: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(3094, 0X2A40) << 16);
    // 0x80800B34: addiu       $t8, $t8, 0x2A40
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(3094, 0X2A40));
    // 0x80800B38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800B3C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800B40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800B44: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800B48: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80800B4C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800B50: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800B54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800B58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B5C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800B60: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80800B64: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800B68: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80800B6C: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80800B70: jal         0x80800A98
    // 0x80800B74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80800A98_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x80800B74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800B78: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80800B7C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80800B80: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800B84: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800B88: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800B8C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80800B90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800B94: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80800B98: jal         0x80800710
    // 0x80800B9C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80800710_ncpoddialog(rdram, ctx);
        goto after_1;
    // 0x80800B9C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x80800BA0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800BA4: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800BA8: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80800BAC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800BB0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800BB4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80800BB8: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80800BBC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800BC0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80800BC4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800BC8: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800BCC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800BD0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800BD4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800BD8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800BDC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800BE0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800BE4: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800BE8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800BEC: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80800BF0: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800BF4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800BF8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800BFC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800C00: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80800C04: beq         $a1, $at, L_80800C18
    if (ctx->r5 == ctx->r1) {
        // 0x80800C08: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C18;
    }
    // 0x80800C08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C0C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800C10: bnel        $a1, $at, L_80800D08
    if (ctx->r5 != ctx->r1) {
        // 0x80800C14: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800D08;
    }
    goto skip_0;
    // 0x80800C14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_80800C18:
    // 0x80800C18: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80800C1C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800C20: addiu       $t1, $t0, 0x14
    ctx->r9 = ADD32(ctx->r8, 0X14);
    // 0x80800C24: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80800C28: nop

    // 0x80800C2C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800C30: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800C34: nop

    // 0x80800C38: bc1t        L_80800CB4
    if (c1cs) {
        // 0x80800C3C: nop
    
            goto L_80800CB4;
    }
    // 0x80800C3C: nop

    // 0x80800C40: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80800C44: addiu       $t3, $t2, -0x14
    ctx->r11 = ADD32(ctx->r10, -0X14);
    // 0x80800C48: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80800C4C: nop

    // 0x80800C50: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800C54: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80800C58: nop

    // 0x80800C5C: bc1t        L_80800CB4
    if (c1cs) {
        // 0x80800C60: nop
    
            goto L_80800CB4;
    }
    // 0x80800C60: nop

    // 0x80800C64: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x80800C68: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800C6C: addiu       $t5, $t4, 0x14
    ctx->r13 = ADD32(ctx->r12, 0X14);
    // 0x80800C70: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80800C74: nop

    // 0x80800C78: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800C7C: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80800C80: nop

    // 0x80800C84: bc1t        L_80800CB4
    if (c1cs) {
        // 0x80800C88: nop
    
            goto L_80800CB4;
    }
    // 0x80800C88: nop

    // 0x80800C8C: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80800C90: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800C94: addiu       $t7, $t6, -0x14
    ctx->r15 = ADD32(ctx->r14, -0X14);
    // 0x80800C98: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80800C9C: nop

    // 0x80800CA0: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800CA4: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80800CA8: nop

    // 0x80800CAC: bc1fl       L_80800CC0
    if (!c1cs) {
        // 0x80800CB0: c.lt.s      $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
            goto L_80800CC0;
    }
    goto skip_1;
    // 0x80800CB0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    skip_1:
L_80800CB4:
    // 0x80800CB4: b           L_80800D08
    // 0x80800CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D08;
    // 0x80800CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800CBC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
L_80800CC0:
    // 0x80800CC0: nop

    // 0x80800CC4: bc1t        L_80800CFC
    if (c1cs) {
        // 0x80800CC8: nop
    
            goto L_80800CFC;
    }
    // 0x80800CC8: nop

    // 0x80800CCC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80800CD0: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800CD4: bc1t        L_80800CFC
    if (c1cs) {
        // 0x80800CD8: nop
    
            goto L_80800CFC;
    }
    // 0x80800CD8: nop

    // 0x80800CDC: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80800CE0: nop

    // 0x80800CE4: bc1t        L_80800CFC
    if (c1cs) {
        // 0x80800CE8: nop
    
            goto L_80800CFC;
    }
    // 0x80800CE8: nop

    // 0x80800CEC: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x80800CF0: nop

    // 0x80800CF4: bc1fl       L_80800D08
    if (!c1cs) {
        // 0x80800CF8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800D08;
    }
    goto skip_2;
    // 0x80800CF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
L_80800CFC:
    // 0x80800CFC: b           L_80800D08
    // 0x80800D00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D08;
    // 0x80800D00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800D04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D08:
    // 0x80800D08: jr          $ra
    // 0x80800D0C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800D0C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void boot___ll_mod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A08: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80002A0C: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80002A10: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80002A14: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80002A18: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80002A1C: ld          $t7, 0x10($sp)
    ctx->r15 = LD(ctx->r29, 0X10);
    // 0x80002A20: ld          $t6, 0x8($sp)
    ctx->r14 = LD(ctx->r29, 0X8);
    // 0x80002A24: ddiv        $zero, $t6, $t7
    DDIV(S64(ctx->r14), S64(ctx->r15), &lo, &hi);
    // 0x80002A28: nop

    // 0x80002A2C: bne         $t7, $zero, L_80002A38
    if (ctx->r15 != 0) {
        // 0x80002A30: nop
    
            goto L_80002A38;
    }
    // 0x80002A30: nop

    // 0x80002A34: break       7
    do_break(2147494452);
L_80002A38:
    // 0x80002A38: daddiu      $at, $zero, -0x1
    ctx->r1 = 0 + -0X1;
    // 0x80002A3C: bne         $t7, $at, L_80002A54
    if (ctx->r15 != ctx->r1) {
        // 0x80002A40: daddiu      $at, $zero, 0x1
        ctx->r1 = 0 + 0X1;
            goto L_80002A54;
    }
    // 0x80002A40: daddiu      $at, $zero, 0x1
    ctx->r1 = 0 + 0X1;
    // 0x80002A44: dsll32      $at, $at, 31
    ctx->r1 = ctx->r1 << (31 + 32);
    // 0x80002A48: bne         $t6, $at, L_80002A54
    if (ctx->r14 != ctx->r1) {
        // 0x80002A4C: nop
    
            goto L_80002A54;
    }
    // 0x80002A4C: nop

    // 0x80002A50: break       6
    do_break(2147494480);
L_80002A54:
    // 0x80002A54: mfhi        $t8
    ctx->r24 = hi;
    // 0x80002A58: sd          $t8, 0x0($sp)
    SD(ctx->r24, 0X0, ctx->r29);
    // 0x80002A5C: bgez        $t8, L_80002A6C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80002A60: nop
    
            goto L_80002A6C;
    }
    // 0x80002A60: nop

    // 0x80002A64: bgtz        $t7, L_80002A84
    if (SIGNED(ctx->r15) > 0) {
        // 0x80002A68: nop
    
            goto L_80002A84;
    }
    // 0x80002A68: nop

L_80002A6C:
    // 0x80002A6C: ld          $t9, 0x0($sp)
    ctx->r25 = LD(ctx->r29, 0X0);
    // 0x80002A70: blez        $t9, L_80002A94
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80002A74: nop
    
            goto L_80002A94;
    }
    // 0x80002A74: nop

    // 0x80002A78: ld          $t0, 0x10($sp)
    ctx->r8 = LD(ctx->r29, 0X10);
    // 0x80002A7C: bgez        $t0, L_80002A94
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80002A80: nop
    
            goto L_80002A94;
    }
    // 0x80002A80: nop

L_80002A84:
    // 0x80002A84: ld          $t1, 0x0($sp)
    ctx->r9 = LD(ctx->r29, 0X0);
    // 0x80002A88: ld          $t2, 0x10($sp)
    ctx->r10 = LD(ctx->r29, 0X10);
    // 0x80002A8C: daddu       $t3, $t1, $t2
    ctx->r11 = ctx->r9 + ctx->r10;
    // 0x80002A90: sd          $t3, 0x0($sp)
    SD(ctx->r11, 0X0, ctx->r29);
L_80002A94:
    // 0x80002A94: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80002A98: lw          $v1, 0x4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4);
    // 0x80002A9C: jr          $ra
    // 0x80002AA0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80002AA0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80802F58_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802F60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802F64: jal         0x80100094
    // 0x80802F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802F6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802F70: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3D28) << 16);
    // 0x80802F74: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802F78: addiu       $a2, $a2, 0x3D28
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3D28));
    // 0x80802F7C: jal         0x80089D18
    // 0x80802F80: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80802F80: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80802F84: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802F88: lh          $t7, 0x24($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X24);
    // 0x80802F8C: bnel        $t7, $zero, L_80802FC0
    if (ctx->r15 != 0) {
        // 0x80802F90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802FC0;
    }
    goto skip_0;
    // 0x80802F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802F94: jal         0x800C0638
    // 0x80802F98: nop

    func_800C0638(rdram, ctx);
        goto after_2;
    // 0x80802F98: nop

    after_2:
    // 0x80802F9C: bne         $v0, $zero, L_80802FBC
    if (ctx->r2 != 0) {
        // 0x80802FA0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80802FBC;
    }
    // 0x80802FA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802FA4: addiu       $a1, $zero, 0x1630
    ctx->r5 = ADD32(0, 0X1630);
    // 0x80802FA8: jal         0x80803158
    // 0x80802FAC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_80803158_chklungo(rdram, ctx);
        goto after_3;
    // 0x80802FAC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_3:
    // 0x80802FB0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80802FB4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802FB8: sh          $t8, 0x24($t9)
    MEM_H(0X24, ctx->r25) = ctx->r24;
L_80802FBC:
    // 0x80802FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802FC0:
    // 0x80802FC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802FC4: jr          $ra
    // 0x80802FC8: nop

    return;
    // 0x80802FC8: nop

;}
RECOMP_FUNC void ovl_shift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082494: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082498: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8008249C: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // 0x800824A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800824A4: lhu         $t1, 0x2E($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X2E);
    // 0x800824A8: lhu         $t2, 0x8($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X8);
    // 0x800824AC: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800824B0: addiu       $t0, $t0, 0x2540
    ctx->r8 = ADD32(ctx->r8, 0X2540);
    // 0x800824B4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800824B8: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800824BC: sll         $t1, $t2, 3
    ctx->r9 = S32(ctx->r10 << 3);
    // 0x800824C0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800824C4: sra         $t3, $a1, 2
    ctx->r11 = S32(SIGNED(ctx->r5) >> 2);
    // 0x800824C8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800824CC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800824D0: add         $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800824D4: add         $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
L_800824D8:
    // 0x800824D8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800824DC: bne         $t0, $t1, L_800824D8
    if (ctx->r8 != ctx->r9) {
        // 0x800824E0: sw          $t2, -0x8($t0)
        MEM_W(-0X8, ctx->r8) = ctx->r10;
            goto L_800824D8;
    }
    // 0x800824E0: sw          $t2, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r10;
    // 0x800824E4: jal         0x8002E660
    // 0x800824E8: nop

    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800824E8: nop

    after_0:
    // 0x800824EC: jal         0x80030AB0
    // 0x800824F0: nop

    osInvalICache_recomp(rdram, ctx);
        goto after_1;
    // 0x800824F0: nop

    after_1:
    // 0x800824F4: lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14);
    // 0x800824F8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x800824FC: addiu       $t0, $a0, 0x38
    ctx->r8 = ADD32(ctx->r4, 0X38);
    // 0x80082500: sh          $t0, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r8;
    // 0x80082504: srl         $t0, $t0, 16
    ctx->r8 = S32(U32(ctx->r8) >> 16);
    // 0x80082508: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8008250C: jal         0x8002E660
    // 0x80082510: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x80082510: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    after_2:
    // 0x80082514: jal         0x80030AB0
    // 0x80082518: nop

    osInvalICache_recomp(rdram, ctx);
        goto after_3;
    // 0x80082518: nop

    after_3:
    // 0x8008251C: lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14);
    // 0x80082520: jal         0x80082088
    // 0x80082524: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_80082088(rdram, ctx);
        goto after_4;
    // 0x80082524: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80082528: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8008252C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80082530: jr          $ra
    // 0x80082534: nop

    return;
    // 0x80082534: nop

;}
RECOMP_FUNC void _chmoley_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086908: syscall     396
    recomp_syscall_handler(rdram, ctx, 0x80086908);
    return;
    // 0x8008690C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bsbeemain_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080111C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801120: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(80, 0X12D0) << 16);
    // 0x80801124: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801128: jr          $ra
    // 0x8080112C: lw          $v0, 0x12D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X12D0));
    return;
    // 0x8080112C: lw          $v0, 0x12D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X12D0));
;}
RECOMP_FUNC void func_80800874_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800874: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800878: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080087C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800880: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800884: jal         0x8008CABC
    // 0x80800888: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800888: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x8080088C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800890: jal         0x80082840
    // 0x80800894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: jal         0x8009D3A8
    // 0x808008A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_2;
    // 0x808008A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808008A4: jal         0x80800058
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800058_bsbeemain(rdram, ctx);
        goto after_3;
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B0: jal         0x8009BB24
    // 0x808008B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_4;
    // 0x808008B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x808008B8: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808008BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C4: beq         $v0, $zero, L_808008E8
    if (ctx->r2 == 0) {
        // 0x808008C8: nop
    
            goto L_808008E8;
    }
    // 0x808008C8: nop

    // 0x808008CC: beq         $v0, $at, L_80800918
    if (ctx->r2 == ctx->r1) {
        // 0x808008D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800918;
    }
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008D8: beq         $v0, $at, L_80800964
    if (ctx->r2 == ctx->r1) {
        // 0x808008DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800964;
    }
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E0: b           L_80800990
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800990;
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008E8:
    // 0x808008E8: jal         0x8008DF8C
    // 0x808008EC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_5;
    // 0x808008EC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_5:
    // 0x808008F0: beq         $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x808008F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080098C;
    }
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F8: lui         $a1, 0x3F37
    ctx->r5 = S32(0X3F37 << 16);
    // 0x808008FC: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800900: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800904: jal         0x8008CF1C
    // 0x80800908: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_6;
    // 0x80800908: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    after_6:
    // 0x8080090C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800910: b           L_8080098C
    // 0x80800914: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_8080098C;
    // 0x80800914: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800918:
    // 0x80800918: jal         0x8009D3A8
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_7;
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800920: jal         0x8008E078
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_8;
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800928: beql        $v0, $zero, L_80800990
    if (ctx->r2 == 0) {
        // 0x8080092C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800990;
    }
    goto skip_0;
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800930: jal         0x80800000
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbeemain(rdram, ctx);
        goto after_9;
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080093C: jal         0x8009B9B0
    // 0x80800940: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x80800940: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80800944: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800948: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800950: jal         0x8008CF1C
    // 0x80800954: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_11;
    // 0x80800954: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_11:
    // 0x80800958: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8080095C: b           L_8080098C
    // 0x80800960: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_8080098C;
    // 0x80800960: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800964:
    // 0x80800964: jal         0x8009D3A8
    // 0x80800968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_12;
    // 0x80800968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8080096C: jal         0x8008B324
    // 0x80800970: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_13;
    // 0x80800970: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_13:
    // 0x80800974: beq         $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x80800978: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080098C;
    }
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080097C: jal         0x8009B9B0
    // 0x80800980: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x80800980: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_14:
    // 0x80800984: addiu       $t8, $zero, 0x85
    ctx->r24 = ADD32(0, 0X85);
    // 0x80800988: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8080098C:
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800990:
    // 0x80800990: jal         0x800919F4
    // 0x80800994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_15;
    // 0x80800994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800998: beq         $v0, $zero, L_808009A8
    if (ctx->r2 == 0) {
        // 0x8080099C: nop
    
            goto L_808009A8;
    }
    // 0x8080099C: nop

    // 0x808009A0: jal         0x80084550
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_808009A8:
    // 0x808009A8: jal         0x8008E078
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_17;
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808009B0: beq         $v0, $zero, L_80800A1C
    if (ctx->r2 == 0) {
        // 0x808009B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A1C;
    }
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009BC: jal         0x80095738
    // 0x808009C0: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    baflag_isTrue(rdram, ctx);
        goto after_18;
    // 0x808009C0: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_18:
    // 0x808009C4: beq         $v0, $zero, L_808009DC
    if (ctx->r2 == 0) {
        // 0x808009C8: nop
    
            goto L_808009DC;
    }
    // 0x808009C8: nop

    // 0x808009CC: jal         0x800848C8
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_28(rdram, ctx);
        goto after_19;
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808009D4: b           L_80800A40
    // 0x808009D8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_80800A40;
    // 0x808009D8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_808009DC:
    // 0x808009DC: jal         0x8009EF10
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_20;
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808009E4: blez        $v0, L_808009F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808009E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009F4;
    }
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009EC: addiu       $t9, $zero, 0x86
    ctx->r25 = ADD32(0, 0X86);
    // 0x808009F0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_808009F4:
    // 0x808009F4: jal         0x80091A58
    // 0x808009F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_21;
    // 0x808009F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_21:
    // 0x808009FC: beq         $v0, $zero, L_80800A0C
    if (ctx->r2 == 0) {
        // 0x80800A00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A0C;
    }
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A04: addiu       $t0, $zero, 0x87
    ctx->r8 = ADD32(0, 0X87);
    // 0x80800A08: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80800A0C:
    // 0x80800A0C: jal         0x800A02DC
    // 0x80800A10: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800A02DC(rdram, ctx);
        goto after_22;
    // 0x80800A10: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_22:
    // 0x80800A14: b           L_80800A40
    // 0x80800A18: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_80800A40;
    // 0x80800A18: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80800A1C:
    // 0x80800A1C: jal         0x80095748
    // 0x80800A20: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isFalse(rdram, ctx);
        goto after_23;
    // 0x80800A20: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_23:
    // 0x80800A24: beq         $v0, $zero, L_80800A40
    if (ctx->r2 == 0) {
        // 0x80800A28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A40;
    }
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A2C: jal         0x80091A58
    // 0x80800A30: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_24;
    // 0x80800A30: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_24:
    // 0x80800A34: beq         $v0, $zero, L_80800A40
    if (ctx->r2 == 0) {
        // 0x80800A38: addiu       $t1, $zero, 0x8C
        ctx->r9 = ADD32(0, 0X8C);
            goto L_80800A40;
    }
    // 0x80800A38: addiu       $t1, $zero, 0x8C
    ctx->r9 = ADD32(0, 0X8C);
    // 0x80800A3C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80800A40:
    // 0x80800A40: jal         0x8008E35C
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_25;
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800A48: beq         $v0, $zero, L_80800A58
    if (ctx->r2 == 0) {
        // 0x80800A4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A58;
    }
    // 0x80800A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A50: addiu       $t2, $zero, 0x8C
    ctx->r10 = ADD32(0, 0X8C);
    // 0x80800A54: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80800A58:
    // 0x80800A58: jal         0x8009E5C8
    // 0x80800A5C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_26;
    // 0x80800A5C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_26:
    // 0x80800A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A6C: jr          $ra
    // 0x80800A70: nop

    return;
    // 0x80800A70: nop

;}
RECOMP_FUNC void func_800C7170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7170: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7174: sw          $zero, -0x552C($at)
    MEM_W(-0X552C, ctx->r1) = 0;
    // 0x800C7178: sw          $zero, -0x5530($at)
    MEM_W(-0X5530, ctx->r1) = 0;
    // 0x800C717C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7180: sw          $zero, -0x5528($at)
    MEM_W(-0X5528, ctx->r1) = 0;
    // 0x800C7184: jr          $ra
    // 0x800C7188: sw          $zero, -0x5524($at)
    MEM_W(-0X5524, ctx->r1) = 0;
    return;
    // 0x800C7188: sw          $zero, -0x5524($at)
    MEM_W(-0X5524, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80800518_chjigsaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800518: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080051C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80800520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800524: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800528: beq         $a1, $at, L_80800584
    if (ctx->r5 == ctx->r1) {
        // 0x8080052C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800584;
    }
    // 0x8080052C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800530: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80800534: beq         $a1, $at, L_808005A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800538: lw          $t4, 0x30($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X30);
            goto L_808005A8;
    }
    // 0x80800538: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8080053C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80800540: beq         $a1, $at, L_808005BC
    if (ctx->r5 == ctx->r1) {
        // 0x80800544: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_808005BC;
    }
    // 0x80800544: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800548: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080054C: beq         $a1, $at, L_808005E4
    if (ctx->r5 == ctx->r1) {
        // 0x80800550: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_808005E4;
    }
    // 0x80800550: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800554: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800558: beq         $a1, $at, L_80800574
    if (ctx->r5 == ctx->r1) {
        // 0x8080055C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800574;
    }
    // 0x8080055C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800560: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x80800564: beq         $a1, $at, L_80800618
    if (ctx->r5 == ctx->r1) {
        // 0x80800568: nop
    
            goto L_80800618;
    }
    // 0x80800568: nop

    // 0x8080056C: b           L_808006B0
    // 0x80800570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006B0;
    // 0x80800570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800574:
    // 0x80800574: jal         0x80800000
    // 0x80800578: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800000_chjigsaw(rdram, ctx);
        goto after_0;
    // 0x80800578: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x8080057C: b           L_808006B0
    // 0x80800580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B0;
    // 0x80800580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800584:
    // 0x80800584: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800588: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8080058C: lbu         $t1, 0x65($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X65);
    // 0x80800590: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800594: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x80800598: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x8080059C: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x808005A0: b           L_808006AC
    // 0x808005A4: sb          $t3, 0x65($t0)
    MEM_B(0X65, ctx->r8) = ctx->r11;
        goto L_808006AC;
    // 0x808005A4: sb          $t3, 0x65($t0)
    MEM_B(0X65, ctx->r8) = ctx->r11;
L_808005A8:
    // 0x808005A8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x808005AC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x808005B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808005B4: b           L_808006AC
    // 0x808005B8: swc1        $f6, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f6.u32l;
        goto L_808006AC;
    // 0x808005B8: swc1        $f6, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f6.u32l;
L_808005BC:
    // 0x808005BC: beq         $t6, $zero, L_808005D8
    if (ctx->r14 == 0) {
        // 0x808005C0: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_808005D8;
    }
    // 0x808005C0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808005C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808005C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808005D0: b           L_808006AC
    // 0x808005D4: swc1        $f8, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f8.u32l;
        goto L_808006AC;
    // 0x808005D4: swc1        $f8, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f8.u32l;
L_808005D8:
    // 0x808005D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808005DC: b           L_808006AC
    // 0x808005E0: swc1        $f10, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f10.u32l;
        goto L_808006AC;
    // 0x808005E0: swc1        $f10, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f10.u32l;
L_808005E4:
    // 0x808005E4: lwc1        $f16, 0x50($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X50);
    // 0x808005E8: lw          $a2, 0x70($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X70);
    // 0x808005EC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808005F0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808005F4: andi        $t2, $a2, 0x1
    ctx->r10 = ctx->r6 & 0X1;
    // 0x808005F8: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x808005FC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800600: jal         0x800867B8
    // 0x80800604: nop

    _chjigsawcollect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800604: nop

    after_1:
    // 0x80800608: jal         0x800FFAB0
    // 0x8080060C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080060C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800610: b           L_808006B0
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B0;
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800618:
    // 0x80800618: jal         0x800C8A98
    // 0x8080061C: nop

    func_800C8A98(rdram, ctx);
        goto after_3;
    // 0x8080061C: nop

    after_3:
    // 0x80800620: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80800624: andi        $t0, $v0, 0x1FF
    ctx->r8 = ctx->r2 & 0X1FF;
    // 0x80800628: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080062C: lhu         $t5, 0x6E($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6E);
    // 0x80800630: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x80800634: or          $t7, $t0, $t6
    ctx->r15 = ctx->r8 | ctx->r14;
    // 0x80800638: sh          $t7, 0x6E($t4)
    MEM_H(0X6E, ctx->r12) = ctx->r15;
    // 0x8080063C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800640: lwc1        $f4, 0x50($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X50);
    // 0x80800644: lw          $a2, 0x6C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X6C);
    // 0x80800648: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080064C: andi        $t1, $a2, 0x1FF
    ctx->r9 = ctx->r6 & 0X1FF;
    // 0x80800650: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80800654: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800658: jal         0x800CF9E4
    // 0x8080065C: nop

    func_800CF9E4(rdram, ctx);
        goto after_4;
    // 0x8080065C: nop

    after_4:
    // 0x80800660: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800664: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800668: jal         0x800EE7F8
    // 0x8080066C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8080066C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_5:
    // 0x80800670: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800674: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800678: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080067C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800680: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800684: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800688: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8080068C: lw          $a0, 0x6C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X6C);
    // 0x80800690: andi        $t3, $a0, 0x1FF
    ctx->r11 = ctx->r4 & 0X1FF;
    // 0x80800694: jal         0x800C8CB8
    // 0x80800698: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_6;
    // 0x80800698: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_6:
    // 0x8080069C: b           L_808006B0
    // 0x808006A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B0;
    // 0x808006A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808006A4: b           L_808006B0
    // 0x808006A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006B0;
    // 0x808006A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006AC:
    // 0x808006AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006B0:
    // 0x808006B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006B8: jr          $ra
    // 0x808006BC: nop

    return;
    // 0x808006BC: nop

;}
RECOMP_FUNC void _bsbpeck_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AC8: syscall     25
    recomp_syscall_handler(rdram, ctx, 0x80082AC8);
    return;
    // 0x80082ACC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chtrashcangame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087688: syscall     604
    recomp_syscall_handler(rdram, ctx, 0x80087688);
    return;
    // 0x8008768C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void ncpod_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808005B8: jr          $ra
    // 0x808005BC: swc1        $f12, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x808005BC: swc1        $f12, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80104124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104124: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80104128: jr          $ra
    // 0x8010412C: addiu       $v0, $v0, 0x4400
    ctx->r2 = ADD32(ctx->r2, 0X4400);
    return;
    // 0x8010412C: addiu       $v0, $v0, 0x4400
    ctx->r2 = ADD32(ctx->r2, 0X4400);
;}
RECOMP_FUNC void func_800BA994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA994: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BA998: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800BA99C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800BA9A0: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BA9A4: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800BA9A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BA9AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BA9B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800BA9B4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800BA9B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BA9BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BA9C0: sb          $t8, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r24;
    // 0x800BA9C4: jal         0x800136E4
    // 0x800BA9C8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x800BA9C8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x800BA9CC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800BA9D0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800BA9D4: nop

    // 0x800BA9D8: sh          $t0, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = ctx->r8;
    // 0x800BA9DC: lh          $t1, 0x36($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X36);
    // 0x800BA9E0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800BA9E4: jal         0x800136E4
    // 0x800BA9E8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x800BA9E8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_1:
    // 0x800BA9EC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800BA9F0: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800BA9F4: nop

    // 0x800BA9F8: sh          $t3, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r11;
    // 0x800BA9FC: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x800BAA00: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800BAA04: jal         0x800136E4
    // 0x800BAA08: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x800BAA08: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_2:
    // 0x800BAA0C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800BAA10: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800BAA14: nop

    // 0x800BAA18: sh          $t6, 0xC8($s0)
    MEM_H(0XC8, ctx->r16) = ctx->r14;
    // 0x800BAA1C: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x800BAA20: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BAA24: jal         0x800136E4
    // 0x800BAA28: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x800BAA28: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_3:
    // 0x800BAA2C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800BAA30: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800BAA34: nop

    // 0x800BAA38: sh          $t9, 0xCA($s0)
    MEM_H(0XCA, ctx->r16) = ctx->r25;
    // 0x800BAA3C: lh          $t0, 0x2E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2E);
    // 0x800BAA40: sh          $t0, 0xCC($s0)
    MEM_H(0XCC, ctx->r16) = ctx->r8;
    // 0x800BAA44: lh          $t1, 0x3A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3A);
    // 0x800BAA48: sh          $t1, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r9;
    // 0x800BAA4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BAA50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BAA54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BAA58: jr          $ra
    // 0x800BAA5C: nop

    return;
    // 0x800BAA5C: nop

;}
RECOMP_FUNC void func_80800058_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080005C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800064: jal         0x808019C8
    // 0x80800068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808019C8_chalienkids(rdram, ctx);
        goto after_0;
    // 0x80800068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080006C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800070: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800074: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80800078: sltiu       $at, $t8, 0xF
    ctx->r1 = ctx->r24 < 0XF ? 1 : 0;
    // 0x8080007C: beq         $at, $zero, L_80800150
    if (ctx->r1 == 0) {
        // 0x80800080: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800150;
    }
    // 0x80800080: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800084: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1324, 0X1C50) << 16);
    // 0x80800088: addu        $at, $at, $t8
    gpr jr_addend_80800090 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080008C: lw          $t8, 0x1C50($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1324, 0X1C50));
    // 0x80800090: jr          $t8
    // 0x80800094: nop

    switch (jr_addend_80800090 >> 2) {
        case 0: goto L_80800098; break;
        case 1: goto L_808000A8; break;
        case 2: goto L_80800150; break;
        case 3: goto L_808000D8; break;
        case 4: goto L_80800150; break;
        case 5: goto L_80800150; break;
        case 6: goto L_80800150; break;
        case 7: goto L_80800150; break;
        case 8: goto L_80800150; break;
        case 9: goto L_80800150; break;
        case 10: goto L_80800150; break;
        case 11: goto L_80800150; break;
        case 12: goto L_80800150; break;
        case 13: goto L_80800128; break;
        case 14: goto L_8080013C; break;
        default: switch_error(__func__, 0x80800090, 0x80801C50);
    }
    // 0x80800094: nop

L_80800098:
    // 0x80800098: jal         0x80801884
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801884_chalienkids(rdram, ctx);
        goto after_1;
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000A0: b           L_80800150
    // 0x808000A4: nop

        goto L_80800150;
    // 0x808000A4: nop

L_808000A8:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x80801158
    // 0x808000B0: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    func_80801158_chalienkids(rdram, ctx);
        goto after_2;
    // 0x808000B0: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    after_2:
    // 0x808000B4: beq         $v0, $zero, L_80800150
    if (ctx->r2 == 0) {
        // 0x808000B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800150;
    }
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: jal         0x80102424
    // 0x808000C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808000C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x8008A4B0
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000D0: b           L_80800150
    // 0x808000D4: nop

        goto L_80800150;
    // 0x808000D4: nop

L_808000D8:
    // 0x808000D8: jal         0x80101DDC
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000E0: beq         $v0, $zero, L_80800150
    if (ctx->r2 == 0) {
        // 0x808000E4: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80800150;
    }
    // 0x808000E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808000E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000EC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808000F0: jal         0x8008A0E0
    // 0x808000F4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808000F4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_6:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: jal         0x80102424
    // 0x80800100: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800100: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_7:
    // 0x80800104: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800108: addiu       $t9, $zero, 0xB7
    ctx->r25 = ADD32(0, 0XB7);
    // 0x8080010C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800110: addiu       $a1, $zero, 0x1284
    ctx->r5 = ADD32(0, 0X1284);
    // 0x80800114: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800118: jal         0x8008A208
    // 0x8080011C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x8080011C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80800120: b           L_80800150
    // 0x80800124: nop

        goto L_80800150;
    // 0x80800124: nop

L_80800128:
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x8010B990
    // 0x80800130: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    func_8010B990(rdram, ctx);
        goto after_9;
    // 0x80800130: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    after_9:
    // 0x80800134: b           L_80800150
    // 0x80800138: nop

        goto L_80800150;
    // 0x80800138: nop

L_8080013C:
    // 0x8080013C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1324, 0X1E60) << 16);
    // 0x80800140: addiu       $a1, $a1, 0x1E60
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1324, 0X1E60));
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x8080184C
    // 0x8080014C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8080184C_chalienkids(rdram, ctx);
        goto after_10;
    // 0x8080014C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
L_80800150:
    // 0x80800150: jal         0x808016D4
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016D4_chalienkids(rdram, ctx);
        goto after_11;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800158: jal         0x8080158C
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080158C_chalienkids(rdram, ctx);
        goto after_12;
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800160: jal         0x80801628
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801628_chalienkids(rdram, ctx);
        goto after_13;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800168: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080016C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800170: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void func_800D3D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D3D08: jr          $ra
    // 0x800D3D0C: lbu         $v0, -0x4C0C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4C0C);
    return;
    // 0x800D3D0C: lbu         $v0, -0x4C0C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4C0C);
;}
RECOMP_FUNC void func_800C2A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2A08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2A10: jal         0x800C28D8
    // 0x800C2A14: nop

    func_800C28D8(rdram, ctx);
        goto after_0;
    // 0x800C2A14: nop

    after_0:
    // 0x800C2A18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C2A1C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C2A20: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800C2A24: jal         0x800C4308
    // 0x800C2A28: nop

    func_800C4308(rdram, ctx);
        goto after_1;
    // 0x800C2A28: nop

    after_1:
    // 0x800C2A2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C2A30: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C2A34: jal         0x800C4B64
    // 0x800C2A38: nop

    func_800C4B64(rdram, ctx);
        goto after_2;
    // 0x800C2A38: nop

    after_2:
    // 0x800C2A3C: jal         0x800C4B70
    // 0x800C2A40: addiu       $a0, $zero, 0x55F0
    ctx->r4 = ADD32(0, 0X55F0);
    func_800C4B70(rdram, ctx);
        goto after_3;
    // 0x800C2A40: addiu       $a0, $zero, 0x55F0
    ctx->r4 = ADD32(0, 0X55F0);
    after_3:
    // 0x800C2A44: jal         0x800C4B7C
    // 0x800C2A48: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_800C4B7C(rdram, ctx);
        goto after_4;
    // 0x800C2A48: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_4:
    // 0x800C2A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2A54: jr          $ra
    // 0x800C2A58: nop

    return;
    // 0x800C2A58: nop

;}
RECOMP_FUNC void func_80800110_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080011C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800120: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800128: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080012C: beq         $t6, $at, L_8080013C
    if (ctx->r14 == ctx->r1) {
        // 0x80800130: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080013C;
    }
    // 0x80800130: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800134: bnel        $t6, $at, L_80800190
    if (ctx->r14 != ctx->r1) {
        // 0x80800138: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800190;
    }
    goto skip_0;
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8080013C:
    // 0x8080013C: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x80800140: addiu       $at, $zero, 0x1D9
    ctx->r1 = ADD32(0, 0X1D9);
    // 0x80800144: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800148: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x8080014C: srl         $t9, $t8, 20
    ctx->r25 = S32(U32(ctx->r24) >> 20);
    // 0x80800150: bne         $t9, $at, L_80800168
    if (ctx->r25 != ctx->r1) {
        // 0x80800154: nop
    
            goto L_80800168;
    }
    // 0x80800154: nop

    // 0x80800158: jal         0x800888C8
    // 0x8080015C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080015C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80800160: jal         0x800FC6B0
    // 0x80800164: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_1;
    // 0x80800164: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
L_80800168:
    // 0x80800168: jal         0x800F54E4
    // 0x8080016C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080016C: nop

    after_2:
    // 0x80800170: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80800174: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800178: sll         $t0, $a1, 11
    ctx->r8 = S32(ctx->r5 << 11);
    // 0x8080017C: jal         0x800F6388
    // 0x80800180: srl         $a1, $t0, 20
    ctx->r5 = S32(U32(ctx->r8) >> 20);
    func_800F6388(rdram, ctx);
        goto after_3;
    // 0x80800180: srl         $a1, $t0, 20
    ctx->r5 = S32(U32(ctx->r8) >> 20);
    after_3:
    // 0x80800184: jal         0x800FFAB0
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080018C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800190:
    // 0x80800190: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800194: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800198: jr          $ra
    // 0x8080019C: nop

    return;
    // 0x8080019C: nop

;}
RECOMP_FUNC void func_80803184_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803184: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80803188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080318C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80803190: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803194: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80803198: jal         0x80100094
    // 0x8080319C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080319C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808031A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808031A4: bne         $s0, $at, L_808031B4
    if (ctx->r16 != ctx->r1) {
        // 0x808031A8: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_808031B4;
    }
    // 0x808031A8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808031AC: b           L_80803294
    // 0x808031B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803294;
    // 0x808031B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808031B4:
    // 0x808031B4: jal         0x800F6478
    // 0x808031B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x808031B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808031BC: bne         $v0, $zero, L_808031CC
    if (ctx->r2 != 0) {
        // 0x808031C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808031CC;
    }
    // 0x808031C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031C4: b           L_80803294
    // 0x808031C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803294;
    // 0x808031C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808031CC:
    // 0x808031CC: jal         0x800F5BF0
    // 0x808031D0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5BF0(rdram, ctx);
        goto after_2;
    // 0x808031D0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x808031D4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808031D8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808031DC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808031E0: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    // 0x808031E4: jal         0x800EE7F8
    // 0x808031E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808031E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x808031EC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x808031F0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808031F4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x808031F8: jal         0x800EF1B8
    // 0x808031FC: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x808031FC: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_4:
    // 0x80803200: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80803204: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80803208: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8080320C: jal         0x800F0008
    // 0x80803210: lui         $a3, 0x432F
    ctx->r7 = S32(0X432F << 16);
    func_800F0008(rdram, ctx);
        goto after_5;
    // 0x80803210: lui         $a3, 0x432F
    ctx->r7 = S32(0X432F << 16);
    after_5:
    // 0x80803214: beq         $v0, $zero, L_80803290
    if (ctx->r2 == 0) {
        // 0x80803218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803290;
    }
    // 0x80803218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080321C: jal         0x800F64A4
    // 0x80803220: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_800F64A4(rdram, ctx);
        goto after_6;
    // 0x80803220: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_6:
    // 0x80803224: beq         $v0, $zero, L_80803258
    if (ctx->r2 == 0) {
        // 0x80803228: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80803258;
    }
    // 0x80803228: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8080322C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803230: jal         0x800F7B9C
    // 0x80803234: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    func_800F7B9C(rdram, ctx);
        goto after_7;
    // 0x80803234: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    after_7:
    // 0x80803238: jal         0x800F54E4
    // 0x8080323C: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x8080323C: nop

    after_8:
    // 0x80803240: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80803244: sh          $v0, 0x78($t7)
    MEM_H(0X78, ctx->r15) = ctx->r2;
    // 0x80803248: jal         0x80803DD8
    // 0x8080324C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80803DD8_chweldarboss(rdram, ctx);
        goto after_9;
    // 0x8080324C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_9:
    // 0x80803250: b           L_80803294
    // 0x80803254: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80803294;
    // 0x80803254: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80803258:
    // 0x80803258: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4A94) << 16);
    // 0x8080325C: addiu       $a2, $a2, 0x4A94
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4A94));
    // 0x80803260: jal         0x80089D18
    // 0x80803264: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80803264: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80803268: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x8080326C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80803270: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80803274: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80803278: jal         0x80018820
    // 0x8080327C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80018820(rdram, ctx);
        goto after_11;
    // 0x8080327C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80803280: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80803284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80803288: b           L_80803294
    // 0x8080328C: sh          $s0, 0x76($t8)
    MEM_H(0X76, ctx->r24) = ctx->r16;
        goto L_80803294;
    // 0x8080328C: sh          $s0, 0x76($t8)
    MEM_H(0X76, ctx->r24) = ctx->r16;
L_80803290:
    // 0x80803290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803294:
    // 0x80803294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080329C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808032A0: jr          $ra
    // 0x808032A4: nop

    return;
    // 0x808032A4: nop

;}
RECOMP_FUNC void func_80800450_chmumbohealspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800450: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800454: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x80800458: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080045C: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x80800460: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800468: beq         $at, $zero, L_80800720
    if (ctx->r1 == 0) {
        // 0x8080046C: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_80800720;
    }
    // 0x8080046C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800470: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800474: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2424, 0X89C) << 16);
    // 0x80800478: addu        $at, $at, $t7
    gpr jr_addend_80800480 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080047C: lw          $t7, 0x89C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2424, 0X89C));
    // 0x80800480: jr          $t7
    // 0x80800484: nop

    switch (jr_addend_80800480 >> 2) {
        case 0: goto L_80800720; break;
        case 1: goto L_80800488; break;
        case 2: goto L_8080049C; break;
        case 3: goto L_80800558; break;
        case 4: goto L_80800580; break;
        case 5: goto L_808005A0; break;
        case 6: goto L_808005C0; break;
        case 7: goto L_808005D4; break;
        case 8: goto L_808005E8; break;
        case 9: goto L_808006CC; break;
        case 10: goto L_808006FC; break;
        default: switch_error(__func__, 0x80800480, 0x8080089C);
    }
    // 0x80800484: nop

L_80800488:
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: jal         0x80103110
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800494: b           L_80800724
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800724;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080049C:
    // 0x8080049C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x808004A0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x808004A4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x808004A8: jal         0x80086C68
    // 0x808004AC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808004AC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x808004B0: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x808004B4: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x808004B8: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004C4: jal         0x80089840
    // 0x808004C8: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808004C8: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_2:
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: jal         0x80100094
    // 0x808004D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808004D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808004D8: jal         0x80089850
    // 0x808004DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808004DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E4: jal         0x80100094
    // 0x808004E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x808004E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808004EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004F0: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    // 0x808004F4: jal         0x80089908
    // 0x808004F8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_6;
    // 0x808004F8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: jal         0x80100094
    // 0x80800504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80800504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800508: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x8080050C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800510: jal         0x80089900
    // 0x80800514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_8;
    // 0x80800514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080051C: jal         0x80100094
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800524: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800528: jal         0x800898B8
    // 0x8080052C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_10;
    // 0x8080052C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_10:
    // 0x80800530: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800534: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80800538: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    // 0x8080053C: jal         0x80085708
    // 0x80800540: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x80800540: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_11:
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: jal         0x8010A800
    // 0x8080054C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_12;
    // 0x8080054C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80800550: b           L_80800724
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800724;
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800558:
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: jal         0x80100094
    // 0x80800560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x80800560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800564: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800568: jal         0x800898D0
    // 0x8080056C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _sumumbofx_entrypoint_18(rdram, ctx);
        goto after_14;
    // 0x8080056C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_14:
    // 0x80800570: jal         0x80086AF0
    // 0x80800574: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x80800574: nop

    after_15:
    // 0x80800578: b           L_80800724
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800724;
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800580:
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: jal         0x80100094
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x8080058C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800590: jal         0x800898C8
    // 0x80800594: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_17;
    // 0x80800594: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_17:
    // 0x80800598: b           L_80800724
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800724;
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005A0:
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A4: jal         0x80100094
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_18;
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x808005AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005B0: jal         0x800898C0
    // 0x808005B4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_19;
    // 0x808005B4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_19:
    // 0x808005B8: b           L_80800724
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800724;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005C0:
    // 0x808005C0: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    // 0x808005C4: jal         0x800887D8
    // 0x808005C8: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_20;
    // 0x808005C8: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    after_20:
    // 0x808005CC: b           L_80800724
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800724;
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005D4:
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: jal         0x80089848
    // 0x808005DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_21;
    // 0x808005DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x808005E0: b           L_80800724
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800724;
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005E8:
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005EC: jal         0x80103110
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_22;
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x808005F4: jal         0x80086C68
    // 0x808005F8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_23;
    // 0x808005F8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_23:
    // 0x808005FC: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80800600: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80800604: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080060C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800610: jal         0x80089840
    // 0x80800614: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_24;
    // 0x80800614: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_24:
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080061C: jal         0x80100094
    // 0x80800620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_25;
    // 0x80800620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80800624: jal         0x80089850
    // 0x80800628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x80800628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: jal         0x80100094
    // 0x80800634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_27;
    // 0x80800634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80800638: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2424, 0X8D0) << 16);
    // 0x8080063C: addiu       $a2, $a2, 0x8D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2424, 0X8D0));
    // 0x80800640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800644: jal         0x80089908
    // 0x80800648: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_28;
    // 0x80800648: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    after_28:
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: jal         0x80100094
    // 0x80800654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_29;
    // 0x80800654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80800658: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x8080065C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800660: jal         0x80089900
    // 0x80800664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_30;
    // 0x80800664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: jal         0x80100094
    // 0x80800670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_31;
    // 0x80800670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x80800674: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800678: jal         0x800898C8
    // 0x8080067C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_32;
    // 0x8080067C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_32:
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: jal         0x80100094
    // 0x80800688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_33;
    // 0x80800688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x8080068C: lui         $a1, 0x43BB
    ctx->r5 = S32(0X43BB << 16);
    // 0x80800690: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800694: jal         0x80089858
    // 0x80800698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_3(rdram, ctx);
        goto after_34;
    // 0x80800698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_34:
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A0: jal         0x80100094
    // 0x808006A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_35;
    // 0x808006A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_35:
    // 0x808006A8: jal         0x80089860
    // 0x808006AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_4(rdram, ctx);
        goto after_36;
    // 0x808006AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_36:
    // 0x808006B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808006B8: addiu       $a3, $zero, 0x2900
    ctx->r7 = ADD32(0, 0X2900);
    // 0x808006BC: jal         0x80085708
    // 0x808006C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_37;
    // 0x808006C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_37:
    // 0x808006C4: b           L_80800724
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800724;
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006CC:
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D0: jal         0x80100094
    // 0x808006D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_38;
    // 0x808006D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x808006D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006DC: jal         0x800898C0
    // 0x808006E0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_39;
    // 0x808006E0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_39:
    // 0x808006E4: addiu       $a0, $zero, 0x52D
    ctx->r4 = ADD32(0, 0X52D);
    // 0x808006E8: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x808006EC: jal         0x80101180
    // 0x808006F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_40;
    // 0x808006F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_40:
    // 0x808006F4: b           L_80800724
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800724;
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006FC:
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: jal         0x80089848
    // 0x80800704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_41;
    // 0x80800704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_41:
    // 0x80800708: jal         0x800DA524
    // 0x8080070C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_42;
    // 0x8080070C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_42:
    // 0x80800710: jal         0x800DA544
    // 0x80800714: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_43;
    // 0x80800714: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_43:
    // 0x80800718: jal         0x800DA544
    // 0x8080071C: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA544(rdram, ctx);
        goto after_44;
    // 0x8080071C: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_44:
L_80800720:
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800724:
    // 0x80800724: jal         0x80102424
    // 0x80800728: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80102424(rdram, ctx);
        goto after_45;
    // 0x80800728: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_45:
    // 0x8080072C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800730: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800734: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800738: jr          $ra
    // 0x8080073C: nop

    return;
    // 0x8080073C: nop

;}
RECOMP_FUNC void func_80801174_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080117C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801180: addiu       $a0, $zero, 0x9CD
    ctx->r4 = ADD32(0, 0X9CD);
    // 0x80801184: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801188: jal         0x800DA7A8
    // 0x8080118C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_0;
    // 0x8080118C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80801190: addiu       $a0, $zero, 0x9CD
    ctx->r4 = ADD32(0, 0X9CD);
    // 0x80801194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801198: jal         0x800DA7A8
    // 0x8080119C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_1;
    // 0x8080119C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x808011A0: jal         0x800DA524
    // 0x808011A4: addiu       $a0, $zero, 0x9D6
    ctx->r4 = ADD32(0, 0X9D6);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x808011A4: addiu       $a0, $zero, 0x9D6
    ctx->r4 = ADD32(0, 0X9D6);
    after_2:
    // 0x808011A8: jal         0x800DA524
    // 0x808011AC: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x808011AC: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    after_3:
    // 0x808011B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808011B4: jal         0x80101FDC
    // 0x808011B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808011B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808011BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011C4: jr          $ra
    // 0x808011C8: nop

    return;
    // 0x808011C8: nop

;}
RECOMP_FUNC void func_80800B98_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B9C: blez        $a0, L_80800BBC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80800BA0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800BBC;
    }
    // 0x80800BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BA4: jal         0x80088400
    // 0x80800BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _gcextra_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BB0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80800BB4: beq         $at, $zero, L_80800BC4
    if (ctx->r1 == 0) {
        // 0x80800BB8: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_80800BC4;
    }
    // 0x80800BB8: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
L_80800BBC:
    // 0x80800BBC: b           L_80800BC8
    // 0x80800BC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80800BC8;
    // 0x80800BC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800BC4:
    // 0x80800BC4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80800BC8:
    // 0x80800BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BD0: jr          $ra
    // 0x80800BD4: nop

    return;
    // 0x80800BD4: nop

;}
RECOMP_FUNC void _vpmodule_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890B0: syscall     761
    recomp_syscall_handler(rdram, ctx, 0x800890B0);
    return;
    // 0x800890B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bssplitup_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004E8: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808004EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004F0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808004F4: jal         0x8008CDB8
    // 0x808004F8: addiu       $a1, $zero, 0x296
    ctx->r5 = ADD32(0, 0X296);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x808004F8: addiu       $a1, $zero, 0x296
    ctx->r5 = ADD32(0, 0X296);
    after_0:
    // 0x808004FC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800500: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080050C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800510: jal         0x8009FFD8
    // 0x80800514: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800514: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080051C: jal         0x8009B94C
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_2;
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800524: jal         0x8009C984
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_3;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080052C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800530: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800534: jal         0x800136E4
    // 0x80800538: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x80800538: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_4:
    // 0x8080053C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: jal         0x8009BA68
    // 0x80800548: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x80800548: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_5:
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: jal         0x800A0CF4
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_6;
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: addiu       $a1, $zero, 0x3EA
    ctx->r5 = ADD32(0, 0X3EA);
    // 0x80800560: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800564: jal         0x8009DF18
    // 0x80800568: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF18(rdram, ctx);
        goto after_7;
    // 0x80800568: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_7:
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
RECOMP_FUNC void func_80800E28_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E30: jal         0x80100094
    // 0x80800E34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1172, 0X1164) << 16);
    // 0x80800E3C: lwc1        $f12, 0x1164($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1172, 0X1164));
    // 0x80800E40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1172, 0X1168) << 16);
    // 0x80800E44: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800E48: lwc1        $f2, 0x1168($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1172, 0X1168));
    // 0x80800E4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800E50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800E54: addiu       $t2, $zero, 0x138
    ctx->r10 = ADD32(0, 0X138);
    // 0x80800E58: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80800E5C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800E60: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_80800E64:
    // 0x80800E64: lw          $a0, 0x24($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X24);
    // 0x80800E68: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x80800E6C: beql        $a0, $zero, L_80800EC0
    if (ctx->r4 == 0) {
        // 0x80800E70: lw          $v1, 0x30($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X30);
            goto L_80800EC0;
    }
    goto skip_0;
    // 0x80800E70: lw          $v1, 0x30($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X30);
    skip_0:
    // 0x80800E74: beql        $a0, $t0, L_80800E98
    if (ctx->r4 == ctx->r8) {
        // 0x80800E78: lwc1        $f4, 0x20($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
            goto L_80800E98;
    }
    goto skip_1;
    // 0x80800E78: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    skip_1:
    // 0x80800E7C: beql        $a0, $t1, L_80800EB8
    if (ctx->r4 == ctx->r9) {
        // 0x80800E80: sw          $a2, 0x24($a1)
        MEM_W(0X24, ctx->r5) = ctx->r6;
            goto L_80800EB8;
    }
    goto skip_2;
    // 0x80800E80: sw          $a2, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r6;
    skip_2:
    // 0x80800E84: beql        $a0, $a2, L_80800EC0
    if (ctx->r4 == ctx->r6) {
        // 0x80800E88: lw          $v1, 0x30($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X30);
            goto L_80800EC0;
    }
    goto skip_3;
    // 0x80800E88: lw          $v1, 0x30($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X30);
    skip_3:
    // 0x80800E8C: b           L_80800EC0
    // 0x80800E90: lw          $v1, 0x30($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X30);
        goto L_80800EC0;
    // 0x80800E90: lw          $v1, 0x30($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X30);
    // 0x80800E94: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
L_80800E98:
    // 0x80800E98: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80800E9C: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80800EA0: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80800EA4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800EA8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80800EAC: b           L_80800EBC
    // 0x80800EB0: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
        goto L_80800EBC;
    // 0x80800EB0: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    // 0x80800EB4: sw          $a2, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r6;
L_80800EB8:
    // 0x80800EB8: swc1        $f14, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f14.u32l;
L_80800EBC:
    // 0x80800EBC: lw          $v1, 0x30($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X30);
L_80800EC0:
    // 0x80800EC0: beq         $v1, $zero, L_80800F10
    if (ctx->r3 == 0) {
        // 0x80800EC4: nop
    
            goto L_80800F10;
    }
    // 0x80800EC4: nop

    // 0x80800EC8: beql        $v1, $t0, L_80800EEC
    if (ctx->r3 == ctx->r8) {
        // 0x80800ECC: lwc1        $f16, 0x2C($a1)
        ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
            goto L_80800EEC;
    }
    goto skip_4;
    // 0x80800ECC: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    skip_4:
    // 0x80800ED0: beql        $v1, $t1, L_80800F0C
    if (ctx->r3 == ctx->r9) {
        // 0x80800ED4: sw          $a2, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->r6;
            goto L_80800F0C;
    }
    goto skip_5;
    // 0x80800ED4: sw          $a2, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r6;
    skip_5:
    // 0x80800ED8: beq         $v1, $a2, L_80800F10
    if (ctx->r3 == ctx->r6) {
        // 0x80800EDC: nop
    
            goto L_80800F10;
    }
    // 0x80800EDC: nop

    // 0x80800EE0: b           L_80800F10
    // 0x80800EE4: nop

        goto L_80800F10;
    // 0x80800EE4: nop

    // 0x80800EE8: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
L_80800EEC:
    // 0x80800EEC: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80800EF0: div.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800EF4: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80800EF8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800EFC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80800F00: b           L_80800F10
    // 0x80800F04: sw          $t9, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r25;
        goto L_80800F10;
    // 0x80800F04: sw          $t9, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r25;
    // 0x80800F08: sw          $a2, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r6;
L_80800F0C:
    // 0x80800F0C: swc1        $f14, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f14.u32l;
L_80800F10:
    // 0x80800F10: bne         $a3, $t2, L_80800E64
    if (ctx->r7 != ctx->r10) {
        // 0x80800F14: addiu       $a1, $a1, 0x18
        ctx->r5 = ADD32(ctx->r5, 0X18);
            goto L_80800E64;
    }
    // 0x80800F14: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80800F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F20: jr          $ra
    // 0x80800F24: nop

    return;
    // 0x80800F24: nop

;}
RECOMP_FUNC void ncba1p_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800620: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800628: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080062C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800630: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800634: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800638: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080063C: lw          $v0, 0x4C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4C);
    // 0x80800640: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80800644: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800648: beq         $v0, $a2, L_80800660
    if (ctx->r2 == ctx->r6) {
        // 0x8080064C: nop
    
            goto L_80800660;
    }
    // 0x8080064C: nop

    // 0x80800650: beq         $v0, $v1, L_80800684
    if (ctx->r2 == ctx->r3) {
        // 0x80800654: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80800684;
    }
    // 0x80800654: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800658: b           L_808006A0
    // 0x8080065C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
        goto L_808006A0;
    // 0x8080065C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_80800660:
    // 0x80800660: bne         $t7, $a2, L_80800670
    if (ctx->r15 != ctx->r6) {
        // 0x80800664: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800670;
    }
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: b           L_8080069C
    // 0x8080066C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_8080069C;
    // 0x8080066C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80800670:
    // 0x80800670: jal         0x8080004C
    // 0x80800674: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    func_8080004C_ncba1p(rdram, ctx);
        goto after_0;
    // 0x80800674: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    after_0:
    // 0x80800678: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080067C: b           L_8080069C
    // 0x80800680: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_8080069C;
    // 0x80800680: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80800684:
    // 0x80800684: beq         $t8, $v1, L_8080069C
    if (ctx->r24 == ctx->r3) {
        // 0x80800688: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080069C;
    }
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: jal         0x8080004C
    // 0x80800690: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    func_8080004C_ncba1p(rdram, ctx);
        goto after_1;
    // 0x80800690: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_1:
    // 0x80800694: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800698: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8080069C:
    // 0x8080069C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_808006A0:
    // 0x808006A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: beq         $t9, $a2, L_808006D4
    if (ctx->r25 == ctx->r6) {
        // 0x808006AC: nop
    
            goto L_808006D4;
    }
    // 0x808006AC: nop

    // 0x808006B0: beql        $t9, $at, L_808007AC
    if (ctx->r25 == ctx->r1) {
        // 0x808006B4: lw          $a2, 0x0($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X0);
            goto L_808007AC;
    }
    goto skip_0;
    // 0x808006B4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x808006B8: beq         $t9, $v1, L_80800770
    if (ctx->r25 == ctx->r3) {
        // 0x808006BC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800770;
    }
    // 0x808006BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808006C4: beq         $t9, $at, L_8080078C
    if (ctx->r25 == ctx->r1) {
        // 0x808006C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080078C;
    }
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006CC: b           L_808007AC
    // 0x808006D0: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
        goto L_808007AC;
    // 0x808006D0: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
L_808006D4:
    // 0x808006D4: jal         0x80110728
    // 0x808006D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80110728(rdram, ctx);
        goto after_2;
    // 0x808006D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808006DC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x808006E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E8: lw          $t0, 0x4C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4C);
    // 0x808006EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808006F0: bne         $t0, $at, L_80800718
    if (ctx->r8 != ctx->r1) {
        // 0x808006F4: nop
    
            goto L_80800718;
    }
    // 0x808006F4: nop

    // 0x808006F8: jal         0x800EE7F8
    // 0x808006FC: addiu       $a0, $a2, 0x30
    ctx->r4 = ADD32(ctx->r6, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808006FC: addiu       $a0, $a2, 0x30
    ctx->r4 = ADD32(ctx->r6, 0X30);
    after_3:
    // 0x80800700: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80800704: addiu       $a0, $a2, 0x3C
    ctx->r4 = ADD32(ctx->r6, 0X3C);
    // 0x80800708: jal         0x800EE7F8
    // 0x8080070C: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080070C: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    after_4:
    // 0x80800710: b           L_80800754
    // 0x80800714: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_80800754;
    // 0x80800714: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800718:
    // 0x80800718: jal         0x801107F0
    // 0x8080071C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_801107F0(rdram, ctx);
        goto after_5;
    // 0x8080071C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_5:
    // 0x80800720: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800728: jal         0x80110818
    // 0x8080072C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_80110818(rdram, ctx);
        goto after_6;
    // 0x8080072C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_6:
    // 0x80800730: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800738: jal         0x801107F0
    // 0x8080073C: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_801107F0(rdram, ctx);
        goto after_7;
    // 0x8080073C: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_7:
    // 0x80800740: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800748: jal         0x80110818
    // 0x8080074C: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    func_80110818(rdram, ctx);
        goto after_8;
    // 0x8080074C: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    after_8:
    // 0x80800750: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800754:
    // 0x80800754: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800758: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8080075C: swc1        $f4, 0x48($t1)
    MEM_W(0X48, ctx->r9) = ctx->f4.u32l;
    // 0x80800760: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80800764: sb          $zero, 0x51($t2)
    MEM_B(0X51, ctx->r10) = 0;
    // 0x80800768: b           L_808007AC
    // 0x8080076C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
        goto L_808007AC;
    // 0x8080076C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
L_80800770:
    // 0x80800770: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800774: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80800778: swc1        $f6, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f6.u32l;
    // 0x8080077C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80800780: sb          $zero, 0x51($t4)
    MEM_B(0X51, ctx->r12) = 0;
    // 0x80800784: b           L_808007AC
    // 0x80800788: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
        goto L_808007AC;
    // 0x80800788: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
L_8080078C:
    // 0x8080078C: jal         0x801163A0
    // 0x80800790: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_801163A0(rdram, ctx);
        goto after_9;
    // 0x80800790: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: jal         0x80110728
    // 0x8080079C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80110728(rdram, ctx);
        goto after_10;
    // 0x8080079C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808007A0: b           L_808007AC
    // 0x808007A4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
        goto L_808007AC;
    // 0x808007A4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x808007A8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
L_808007AC:
    // 0x808007AC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x808007B0: sw          $t5, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r13;
    // 0x808007B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007C0: jr          $ra
    // 0x808007C4: nop

    return;
    // 0x808007C4: nop

;}
RECOMP_FUNC void func_80800040_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: jal         0x80085168
    // 0x8080004C: nop

    _bastatemem_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080004C: nop

    after_0:
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D28: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D28);
    return;
    // 0x80087D2C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_800D75DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D75DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D75E0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D75E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D75E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D75EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D75F0: lh          $a0, -0x400A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X400A);
    // 0x800D75F4: jal         0x8001B798
    // 0x800D75F8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800D75F8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800D75FC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800D7600: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7604: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D7608: bne         $a1, $at, L_800D7618
    if (ctx->r5 != ctx->r1) {
        // 0x800D760C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D7618;
    }
    // 0x800D760C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D7610: b           L_800D76F8
    // 0x800D7614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D76F8;
    // 0x800D7614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D7618:
    // 0x800D7618: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800D761C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800D7620: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x800D7624: jal         0x8001B798
    // 0x800D7628: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x800D7628: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800D762C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800D7630: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x800D7634: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D7638: bne         $a3, $zero, L_800D7648
    if (ctx->r7 != 0) {
        // 0x800D763C: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800D7648;
    }
    // 0x800D763C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800D7640: b           L_800D76F8
    // 0x800D7644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D76F8;
    // 0x800D7644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D7648:
    // 0x800D7648: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x800D764C: addu        $t8, $t8, $a3
    ctx->r24 = ADD32(ctx->r24, ctx->r7);
    // 0x800D7650: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800D7654: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    // 0x800D7658: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800D765C: sltu        $at, $a2, $a1
    ctx->r1 = ctx->r6 < ctx->r5 ? 1 : 0;
    // 0x800D7660: beq         $at, $zero, L_800D76F4
    if (ctx->r1 == 0) {
        // 0x800D7664: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800D76F4;
    }
    // 0x800D7664: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D7668: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800D766C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D7670: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800D7674: nop

    // 0x800D7678: bc1tl       L_800D76AC
    if (c1cs) {
        // 0x800D767C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800D76AC;
    }
    goto skip_0;
    // 0x800D767C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x800D7680: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800D7684: nop

    // 0x800D7688: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x800D768C: nop

    // 0x800D7690: bc1fl       L_800D76F8
    if (!c1cs) {
        // 0x800D7694: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800D76F8;
    }
    goto skip_1;
    // 0x800D7694: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_1:
    // 0x800D7698: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800D769C: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x800D76A0: nop

    // 0x800D76A4: bc1f        L_800D76F4
    if (!c1cs) {
        // 0x800D76A8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800D76F4;
    }
    // 0x800D76A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800D76AC:
    // 0x800D76AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800D76B0: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x800D76B4: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x800D76B8: beq         $at, $zero, L_800D76F4
    if (ctx->r1 == 0) {
        // 0x800D76BC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800D76F4;
    }
    // 0x800D76BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D76C0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800D76C4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800D76C8: nop

    // 0x800D76CC: bc1tl       L_800D76AC
    if (c1cs) {
        // 0x800D76D0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800D76AC;
    }
    goto skip_2;
    // 0x800D76D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_2:
    // 0x800D76D4: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x800D76D8: nop

    // 0x800D76DC: bc1fl       L_800D76F8
    if (!c1cs) {
        // 0x800D76E0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800D76F8;
    }
    goto skip_3;
    // 0x800D76E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_3:
    // 0x800D76E4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800D76E8: nop

    // 0x800D76EC: bc1tl       L_800D76AC
    if (c1cs) {
        // 0x800D76F0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800D76AC;
    }
    goto skip_4;
    // 0x800D76F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_4:
L_800D76F4:
    // 0x800D76F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D76F8:
    // 0x800D76F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D76FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7700: jr          $ra
    // 0x800D7704: nop

    return;
    // 0x800D7704: nop

;}
RECOMP_FUNC void func_800F0274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0274: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F0278: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800F027C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0280: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800F0284: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800F0288: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F028C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800F0290: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800F0294: jal         0x800EFB24
    // 0x800F0298: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800F0298: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800F029C: jal         0x800EEFD4
    // 0x800F02A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EEFD4(rdram, ctx);
        goto after_1;
    // 0x800F02A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x800F02A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F02A8: lwc1        $f4, 0x5EB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EB4);
    // 0x800F02AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800F02B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800F02B4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F02B8: nop

    // 0x800F02BC: bc1f        L_800F02D4
    if (!c1cs) {
        // 0x800F02C0: nop
    
            goto L_800F02D4;
    }
    // 0x800F02C0: nop

    // 0x800F02C4: jal         0x800EE7F8
    // 0x800F02C8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800F02C8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x800F02CC: b           L_800F03A0
    // 0x800F02D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F03A0;
    // 0x800F02D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F02D4:
    // 0x800F02D4: jal         0x8002DCA0
    // 0x800F02D8: nop

    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800F02D8: nop

    after_3:
    // 0x800F02DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F02E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F02E4: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F02E8: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F02EC: div.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800F02F0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800F02F4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800F02F8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F02FC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800F0300: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800F0304: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800F0308: nop

    // 0x800F030C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800F0310: nop

    // 0x800F0314: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F0318: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800F031C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x800F0320: jal         0x800EFB24
    // 0x800F0324: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x800F0324: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x800F0328: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F032C: jal         0x800EEAA4
    // 0x800F0330: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EEAA4(rdram, ctx);
        goto after_5;
    // 0x800F0330: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x800F0334: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800F0338: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800F033C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800F0340: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x800F0344: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F0348: bc1fl       L_800F0364
    if (!c1cs) {
        // 0x800F034C: c.le.s      $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
            goto L_800F0364;
    }
    goto skip_0;
    // 0x800F034C: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    skip_0:
    // 0x800F0350: jal         0x800EE7F8
    // 0x800F0354: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x800F0354: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_6:
    // 0x800F0358: b           L_800F03A0
    // 0x800F035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F03A0;
    // 0x800F035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0360: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
L_800F0364:
    // 0x800F0364: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800F0368: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800F036C: bc1fl       L_800F0388
    if (!c1cs) {
        // 0x800F0370: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_800F0388;
    }
    goto skip_1;
    // 0x800F0370: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_1:
    // 0x800F0374: jal         0x800EE7F8
    // 0x800F0378: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x800F0378: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_7:
    // 0x800F037C: b           L_800F03A0
    // 0x800F0380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F03A0;
    // 0x800F0380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0384: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_800F0388:
    // 0x800F0388: jal         0x800EFA20
    // 0x800F038C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EFA20(rdram, ctx);
        goto after_8;
    // 0x800F038C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_8:
    // 0x800F0390: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800F0394: jal         0x800EF04C
    // 0x800F0398: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x800F0398: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_9:
    // 0x800F039C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F03A0:
    // 0x800F03A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800F03A4: jr          $ra
    // 0x800F03A8: nop

    return;
    // 0x800F03A8: nop

;}
RECOMP_FUNC void func_800CB854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB854: beq         $a0, $zero, L_800CB868
    if (ctx->r4 == 0) {
        // 0x800CB858: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800CB868;
    }
    // 0x800CB858: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CB85C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800CB860: lw          $t6, -0x518C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X518C);
    // 0x800CB864: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_800CB868:
    // 0x800CB868: jr          $ra
    // 0x800CB86C: lh          $v0, -0x5190($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5190);
    return;
    // 0x800CB86C: lh          $v0, -0x5190($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5190);
;}
RECOMP_FUNC void func_800C968C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C968C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9698: jal         0x800C91C8
    // 0x800C969C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800C91C8(rdram, ctx);
        goto after_0;
    // 0x800C969C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C96A0: bne         $v0, $zero, L_800C96B4
    if (ctx->r2 != 0) {
        // 0x800C96A4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800C96B4;
    }
    // 0x800C96A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C96A8: jal         0x800C9150
    // 0x800C96AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800C9150(rdram, ctx);
        goto after_1;
    // 0x800C96AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800C96B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800C96B4:
    // 0x800C96B4: jal         0x800881E0
    // 0x800C96B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gctransitionDll_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x800C96B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800C96BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C96C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C96C4: jr          $ra
    // 0x800C96C8: nop

    return;
    // 0x800C96C8: nop

;}
RECOMP_FUNC void gcgoto_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080065C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800664: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800668: jal         0x8008FD48
    // 0x8080066C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8008FD48(rdram, ctx);
        goto after_0;
    // 0x8080066C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800670: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800674: bne         $v0, $at, L_80800684
    if (ctx->r2 != ctx->r1) {
        // 0x80800678: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800684;
    }
    // 0x80800678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080067C: jal         0x808003D0
    // 0x80800680: ori         $a1, $zero, 0xC403
    ctx->r5 = 0 | 0XC403;
    func_808003D0_gcgoto(rdram, ctx);
        goto after_1;
    // 0x80800680: ori         $a1, $zero, 0xC403
    ctx->r5 = 0 | 0XC403;
    after_1:
L_80800684:
    // 0x80800684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080068C: jr          $ra
    // 0x80800690: nop

    return;
    // 0x80800690: nop

;}
RECOMP_FUNC void func_808000CC_chfactoryentrydoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000DC: bne         $a1, $at, L_80800124
    if (ctx->r5 != ctx->r1) {
        // 0x808000E0: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800124;
    }
    // 0x808000E0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808000E4: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x808000E8: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x808000EC: addiu       $v0, $zero, 0x972
    ctx->r2 = ADD32(0, 0X972);
    // 0x808000F0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808000F4: bne         $t7, $at, L_80800104
    if (ctx->r15 != ctx->r1) {
        // 0x808000F8: nop
    
            goto L_80800104;
    }
    // 0x808000F8: nop

    // 0x808000FC: b           L_80800104
    // 0x80800100: addiu       $v0, $zero, 0x971
    ctx->r2 = ADD32(0, 0X971);
        goto L_80800104;
    // 0x80800100: addiu       $v0, $zero, 0x971
    ctx->r2 = ADD32(0, 0X971);
L_80800104:
    // 0x80800104: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80800108: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x8080010C: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    // 0x80800110: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80800114: jal         0x80103140
    // 0x80800118: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800118: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080011C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800120: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800124:
    // 0x80800124: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800128: jal         0x80086248
    // 0x8080012C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080012C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void _sucoasterplayer_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A318: syscall     835
    recomp_syscall_handler(rdram, ctx, 0x8008A318);
    return;
    // 0x8008A31C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800DF410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF410: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF414: jr          $ra
    // 0x800DF418: sw          $a0, -0x365C($at)
    MEM_W(-0X365C, ctx->r1) = ctx->r4;
    return;
    // 0x800DF418: sw          $a0, -0x365C($at)
    MEM_W(-0X365C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _bsbeemain_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828B8: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x800828B8);
    return;
    // 0x800828BC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_808000A4_ncbafly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000AC: jal         0x80112550
    // 0x808000B0: nop

    func_80112550(rdram, ctx);
        goto after_0;
    // 0x808000B0: nop

    after_0:
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void func_8080000C_chjigsawcollect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080001C: jal         0x80100094
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800028: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8080002C: jal         0x800CFA70
    // 0x80800030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CFA70(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800034: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800038: beql        $v0, $at, L_80800078
    if (ctx->r2 == ctx->r1) {
        // 0x8080003C: sw          $zero, 0x10($s0)
        MEM_W(0X10, ctx->r16) = 0;
            goto L_80800078;
    }
    goto skip_0;
    // 0x8080003C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    skip_0:
    // 0x80800040: jal         0x800C8A98
    // 0x80800044: nop

    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80800044: nop

    after_2:
    // 0x80800048: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8080004C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800054: jal         0x800CF9E4
    // 0x80800058: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800CF9E4(rdram, ctx);
        goto after_3;
    // 0x80800058: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x8080005C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800060: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80800064: jal         0x800C8CB8
    // 0x80800068: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x80800068: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x8080006C: b           L_8080007C
    // 0x80800070: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
        goto L_8080007C;
    // 0x80800070: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x80800074: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
L_80800078:
    // 0x80800078: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
L_8080007C:
    // 0x8080007C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800080: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800084: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800088: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080008C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800090: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x80800094: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80800098: jal         0x800FC660
    // 0x8080009C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    func_800FC660(rdram, ctx);
        goto after_5;
    // 0x8080009C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x808000A0: jal         0x800FC660
    // 0x808000A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800FC660(rdram, ctx);
        goto after_6;
    // 0x808000A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_6:
    // 0x808000A8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808000AC: lbu         $t8, 0x65($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X65);
    // 0x808000B0: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808000B4: sb          $t9, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r25;
    // 0x808000B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void func_808015BC_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808015C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015C4: jal         0x80800448
    // 0x808015C8: nop

    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808015C8: nop

    after_0:
    // 0x808015CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808015D4: jr          $ra
    // 0x808015D8: nop

    return;
    // 0x808015D8: nop

;}
RECOMP_FUNC void func_808009A8_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009B4: jal         0x8080108C
    // 0x808009B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8080108C_chvolcanobits(rdram, ctx);
        goto after_0;
    // 0x808009B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808009BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808009C0: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C8: addiu       $a1, $zero, 0x42A
    ctx->r5 = ADD32(0, 0X42A);
    // 0x808009CC: srl         $t6, $a2, 7
    ctx->r14 = S32(U32(ctx->r6) >> 7);
    // 0x808009D0: jal         0x80089C70
    // 0x808009D4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    _subaddiefind_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808009D4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_1:
    // 0x808009D8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E0: jal         0x80085808
    // 0x808009E4: lh          $a1, 0x6($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X6);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808009E4: lh          $a1, 0x6($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X6);
    after_2:
    // 0x808009E8: jal         0x80085818
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808009F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009FC: jr          $ra
    // 0x80800A00: nop

    return;
    // 0x80800A00: nop

;}
RECOMP_FUNC void func_800A2018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2018: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A201C: bnel        $a1, $at, L_800A2038
    if (ctx->r5 != ctx->r1) {
        // 0x800A2020: lw          $v0, 0x108($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X108);
            goto L_800A2038;
    }
    goto skip_0;
    // 0x800A2020: lw          $v0, 0x108($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X108);
    skip_0:
    // 0x800A2024: lw          $v0, 0x108($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X108);
    // 0x800A2028: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x800A202C: jr          $ra
    // 0x800A2030: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    return;
    // 0x800A2030: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800A2034: lw          $v0, 0x108($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X108);
L_800A2038:
    // 0x800A2038: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800A203C: beq         $a1, $v1, L_800A2050
    if (ctx->r5 == ctx->r3) {
        // 0x800A2040: nop
    
            goto L_800A2050;
    }
    // 0x800A2040: nop

    // 0x800A2044: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x800A2048: lw          $t7, 0x108($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X108);
    // 0x800A204C: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
L_800A2050:
    // 0x800A2050: jr          $ra
    // 0x800A2054: nop

    return;
    // 0x800A2054: nop

;}
