#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _glsplinecs_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088468: syscall     685
    recomp_syscall_handler(rdram, ctx, 0x80088468);
    return;
    // 0x8008846C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80112788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112788: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8011278C: jr          $ra
    // 0x80112790: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
    return;
    // 0x80112790: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80112794: nop

    // 0x80112798: nop

    // 0x8011279C: nop

;}
RECOMP_FUNC void _glgamestore_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884D0: syscall     688
    recomp_syscall_handler(rdram, ctx, 0x800884D0);
    return;
    // 0x800884D4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chweather_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(732, 0X5A8) << 16);
    // 0x80800118: jr          $ra
    // 0x8080011C: addiu       $v0, $v0, 0x5A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X5A8));
    return;
    // 0x8080011C: addiu       $v0, $v0, 0x5A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X5A8));
;}
RECOMP_FUNC void func_808000A8_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808000AC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808000B0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X700C) << 16);
    // 0x808000B8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808000BC: jr          $ra
    // 0x808000C0: lwc1        $f0, 0x700C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X700C));
    return;
    // 0x808000C0: lwc1        $f0, 0x700C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X700C));
;}
RECOMP_FUNC void func_80801740_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801748: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x8080174C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801750: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801754: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80801758: bgez        $t8, L_80801770
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080175C: addiu       $a1, $a3, 0x4
        ctx->r5 = ADD32(ctx->r7, 0X4);
            goto L_80801770;
    }
    // 0x8080175C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80801760: jal         0x8008A0D8
    // 0x80801764: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _subaddieskeleton_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801764: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80801768: b           L_808017A8
    // 0x8080176C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808017A8;
    // 0x8080176C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801770:
    // 0x80801770: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801774: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80801778: jal         0x800EE7F8
    // 0x8080177C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080177C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80801780: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801784: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    // 0x80801788: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080178C: lwc1        $f4, 0x38($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X38);
    // 0x80801790: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80801794: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801798: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8080179C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x808017A0: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x808017A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808017A8:
    // 0x808017A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808017AC: jr          $ra
    // 0x808017B0: nop

    return;
    // 0x808017B0: nop

;}
RECOMP_FUNC void func_8080032C_chweldarbossfusebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800334: jal         0x80101080
    // 0x80800338: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800338: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080033C: jal         0x80106790
    // 0x80800340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800348: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080034C: jal         0x800866D0
    // 0x80800350: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x80800350: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_2:
    // 0x80800354: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800358: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1380, 0X660) << 16);
    // 0x8080035C: addiu       $a2, $a2, 0x660
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1380, 0X660));
    // 0x80800360: jal         0x80089D18
    // 0x80800364: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800364: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x80800368: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8080036C: jal         0x800BF744
    // 0x80800370: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_4;
    // 0x80800370: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080037C: jr          $ra
    // 0x80800380: nop

    return;
    // 0x80800380: nop

;}
RECOMP_FUNC void func_80800998_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800998: jr          $ra
    // 0x8080099C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080099C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800F3880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F3884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F3888: jal         0x80098E64
    // 0x800F388C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80098E64(rdram, ctx);
        goto after_0;
    // 0x800F388C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F3890: jal         0x8001B084
    // 0x800F3894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x800F3894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800F3898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F389C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F38A0: jr          $ra
    // 0x800F38A4: nop

    return;
    // 0x800F38A4: nop

;}
RECOMP_FUNC void ncpod_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F30: jal         0x80110024
    // 0x80800F34: nop

    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80800F34: nop

    after_0:
    // 0x80800F38: jal         0x80089638
    // 0x80800F3C: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    _ncpoducam_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800F3C: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x80800F40: jal         0x80089680
    // 0x80800F44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncpoducam_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800F44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F50: jr          $ra
    // 0x80800F54: nop

    return;
    // 0x80800F54: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825E8: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825E8);
    return;
    // 0x800825EC: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_800BD570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD578: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD57C: jal         0x80087C58
    // 0x800BD580: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    _gccubeDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800BD580: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    after_0:
    // 0x800BD584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BD58C: jr          $ra
    // 0x800BD590: nop

    return;
    // 0x800BD590: nop

;}
RECOMP_FUNC void func_80800114_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080011C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800120: jal         0x80084128
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x8009E6C4
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E6C4(rdram, ctx);
        goto after_1;
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800134: bne         $v0, $zero, L_80800160
    if (ctx->r2 != 0) {
        // 0x80800138: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800160;
    }
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: jal         0x8009BCB4
    // 0x80800140: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_2;
    // 0x80800140: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_2:
    // 0x80800144: lui         $a1, 0x4305
    ctx->r5 = S32(0X4305 << 16);
    // 0x80800148: ori         $a1, $a1, 0x547B
    ctx->r5 = ctx->r5 | 0X547B;
    // 0x8080014C: jal         0x8009BCC4
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: jal         0x800961AC
    // 0x8080015C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_4;
    // 0x8080015C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
L_80800160:
    // 0x80800160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080016C: jr          $ra
    // 0x80800170: nop

    return;
    // 0x80800170: nop

;}
RECOMP_FUNC void func_800A2D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A2D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2D34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A2D38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A2D3C: jal         0x8008CABC
    // 0x800A2D40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x800A2D40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A2D44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A2D48: jal         0x8008B348
    // 0x800A2D4C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x800A2D4C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800A2D50: beq         $v0, $zero, L_800A2D60
    if (ctx->r2 == 0) {
        // 0x800A2D54: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800A2D60;
    }
    // 0x800A2D54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A2D58: jal         0x800A2FCC
    // 0x800A2D5C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800A2FCC(rdram, ctx);
        goto after_2;
    // 0x800A2D5C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
L_800A2D60:
    // 0x800A2D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A2D68: jr          $ra
    // 0x800A2D6C: nop

    return;
    // 0x800A2D6C: nop

;}
RECOMP_FUNC void func_80012164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001216C: jal         0x80087888
    // 0x80012170: nop

    _cosection_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80012170: nop

    after_0:
    // 0x80012174: jal         0x8001253C
    // 0x80012178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001253C(rdram, ctx);
        goto after_1;
    // 0x80012178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8001217C: jal         0x80012520
    // 0x80012180: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80012520(rdram, ctx);
        goto after_2;
    // 0x80012180: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80012184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001218C: jr          $ra
    // 0x80012190: nop

    return;
    // 0x80012190: nop

;}
RECOMP_FUNC void func_80800DA4_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DB0: jal         0x800839E8
    // 0x80800DB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800DB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800DB8: beq         $v0, $zero, L_80800DC4
    if (ctx->r2 == 0) {
        // 0x80800DBC: addiu       $t6, $zero, 0x154
        ctx->r14 = ADD32(0, 0X154);
            goto L_80800DC4;
    }
    // 0x80800DBC: addiu       $t6, $zero, 0x154
    ctx->r14 = ADD32(0, 0X154);
    // 0x80800DC0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800DC4:
    // 0x80800DC4: jal         0x8080076C
    // 0x80800DC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8080076C_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x80800DC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800DCC: jal         0x8080078C
    // 0x80800DD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8080078C_bskaztorpedo(rdram, ctx);
        goto after_2;
    // 0x80800DD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800DD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800DD8: jal         0x8009E5C8
    // 0x80800DDC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80800DDC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DE8: jr          $ra
    // 0x80800DEC: nop

    return;
    // 0x80800DEC: nop

;}
RECOMP_FUNC void func_80800C94_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800CA0: jal         0x80082840
    // 0x80800CA4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800CA4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800CA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CAC: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80800CB0: addiu       $a2, $zero, 0x85
    ctx->r6 = ADD32(0, 0X85);
    // 0x80800CB4: jal         0x80084C50
    // 0x80800CB8: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    _bafly_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80800CB8: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CC4: jr          $ra
    // 0x80800CC8: nop

    return;
    // 0x80800CC8: nop

;}
RECOMP_FUNC void func_8010B800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B800: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010B804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B808: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010B80C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8010B810: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8010B814: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8010B818: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x8010B81C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8010B820: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8010B824: srl         $v1, $v0, 25
    ctx->r3 = S32(U32(ctx->r2) >> 25);
    // 0x8010B828: beq         $v1, $zero, L_8010B890
    if (ctx->r3 == 0) {
        // 0x8010B82C: addiu       $a1, $v1, -0x1
        ctx->r5 = ADD32(ctx->r3, -0X1);
            goto L_8010B890;
    }
    // 0x8010B82C: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x8010B830: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x8010B834: srl         $t6, $a2, 26
    ctx->r14 = S32(U32(ctx->r6) >> 26);
    // 0x8010B838: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    // 0x8010B83C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010B840: jal         0x800CC338
    // 0x8010B844: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800CC338(rdram, ctx);
        goto after_0;
    // 0x8010B844: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B848: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010B84C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010B850: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8010B854: bne         $v0, $at, L_8010B86C
    if (ctx->r2 != ctx->r1) {
        // 0x8010B858: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8010B86C;
    }
    // 0x8010B858: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010B85C: jal         0x800EE7F8
    // 0x8010B860: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8010B860: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8010B864: b           L_8010B894
    // 0x8010B868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010B894;
    // 0x8010B868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010B86C:
    // 0x8010B86C: lhu         $t1, 0x72($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X72);
    // 0x8010B870: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8010B874: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8010B878: andi        $t0, $t9, 0x3F0
    ctx->r8 = ctx->r25 & 0X3F0;
    // 0x8010B87C: andi        $t2, $t1, 0xFC0F
    ctx->r10 = ctx->r9 & 0XFC0F;
    // 0x8010B880: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8010B884: sh          $t3, 0x72($a3)
    MEM_H(0X72, ctx->r7) = ctx->r11;
    // 0x8010B888: b           L_8010B894
    // 0x8010B88C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010B894;
    // 0x8010B88C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010B890:
    // 0x8010B890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010B894:
    // 0x8010B894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B898: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010B89C: jr          $ra
    // 0x8010B8A0: nop

    return;
    // 0x8010B8A0: nop

;}
RECOMP_FUNC void func_80800068_chquizremotectrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080006C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800074: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x80800078: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080007C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800080: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x80800084: beq         $t6, $at, L_8080009C
    if (ctx->r14 == ctx->r1) {
        // 0x80800088: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080009C;
    }
    // 0x80800088: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080008C: beq         $t6, $at, L_808000E4
    if (ctx->r14 == ctx->r1) {
        // 0x80800090: addiu       $a0, $s0, 0x50
        ctx->r4 = ADD32(ctx->r16, 0X50);
            goto L_808000E4;
    }
    // 0x80800090: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x80800094: b           L_8080011C
    // 0x80800098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080011C;
    // 0x80800098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080009C:
    // 0x8080009C: jal         0x800D90A4
    // 0x808000A0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    after_0:
    // 0x808000A4: beq         $v0, $zero, L_808000B4
    if (ctx->r2 == 0) {
        // 0x808000A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000B4;
    }
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x80800000
    // 0x808000B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_chquizremotectrl(rdram, ctx);
        goto after_1;
    // 0x808000B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_808000B4:
    // 0x808000B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000C8: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808000CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808000D4: jal         0x800F10B4
    // 0x808000D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808000D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808000DC: b           L_80800118
    // 0x808000E0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_80800118;
    // 0x808000E0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_808000E4:
    // 0x808000E4: jal         0x800D91EC
    // 0x808000E8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800D91EC(rdram, ctx);
        goto after_3;
    // 0x808000E8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_3:
    // 0x808000EC: beq         $v0, $zero, L_808000FC
    if (ctx->r2 == 0) {
        // 0x808000F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000FC;
    }
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x80800000
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_chquizremotectrl(rdram, ctx);
        goto after_4;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_808000FC:
    // 0x808000FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800100: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800104: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800108: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8080010C: jal         0x800F10B4
    // 0x80800110: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800110: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x80800114: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80800118:
    // 0x80800118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080011C:
    // 0x8080011C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800120: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800124: jr          $ra
    // 0x80800128: nop

    return;
    // 0x80800128: nop

;}
RECOMP_FUNC void func_80800000_glsavegame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8001ACCC
    // 0x8080000C: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080000C: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void func_800F651C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F651C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6520: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6524: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6528: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F652C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6534: jal         0x8009BB00
    // 0x800F6538: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_0;
    // 0x800F6538: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F653C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F6540: nop

    // 0x800F6544: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800F6548: nop

    // 0x800F654C: bc1f        L_800F655C
    if (!c1cs) {
        // 0x800F6550: nop
    
            goto L_800F655C;
    }
    // 0x800F6550: nop

    // 0x800F6554: b           L_800F6580
    // 0x800F6558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F6580;
    // 0x800F6558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F655C:
    // 0x800F655C: jal         0x8009E6F8
    // 0x800F6560: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    bs_getCurrentState(rdram, ctx);
        goto after_1;
    // 0x800F6560: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800F6564: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F6568: bne         $v0, $at, L_800F6578
    if (ctx->r2 != ctx->r1) {
        // 0x800F656C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F6578;
    }
    // 0x800F656C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6570: b           L_800F6580
    // 0x800F6574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F6580;
    // 0x800F6574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F6578:
    // 0x800F6578: jal         0x8009E674
    // 0x800F657C: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    func_8009E674(rdram, ctx);
        goto after_2;
    // 0x800F657C: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_2:
L_800F6580:
    // 0x800F6580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6588: jr          $ra
    // 0x800F658C: nop

    return;
    // 0x800F658C: nop

;}
RECOMP_FUNC void func_800FACA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FACA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800FACA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FACA8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800FACAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800FACB0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800FACB4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800FACB8: jal         0x800EE7F8
    // 0x800FACBC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800FACBC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800FACC0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800FACC4: jal         0x800EE7F8
    // 0x800FACC8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800FACC8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800FACCC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800FACD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FACD4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800FACD8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800FACDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FACE0: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FACE4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FACE8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800FACEC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800FACF0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800FACF4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800FACF8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800FACFC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800FAD00: jal         0x800C6A7C
    // 0x800FAD04: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6A7C(rdram, ctx);
        goto after_2;
    // 0x800FAD04: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x800FAD08: beq         $v0, $zero, L_800FAD58
    if (ctx->r2 == 0) {
        // 0x800FAD0C: lwc1        $f4, 0x38($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
            goto L_800FAD58;
    }
    // 0x800FAD0C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FAD10: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800FAD14: nop

    // 0x800FAD18: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800FAD1C: nop

    // 0x800FAD20: bc1fl       L_800FAD3C
    if (!c1cs) {
        // 0x800FAD24: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_800FAD3C;
    }
    goto skip_0;
    // 0x800FAD24: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x800FAD28: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800FAD2C: sll         $t7, $t6, 15
    ctx->r15 = S32(ctx->r14 << 15);
    // 0x800FAD30: bgezl       $t7, L_800FAD5C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800FAD34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FAD5C;
    }
    goto skip_1;
    // 0x800FAD34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800FAD38: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_800FAD3C:
    // 0x800FAD3C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FAD40: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800FAD44: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800FAD48: nop

    // 0x800FAD4C: bc1fl       L_800FAD5C
    if (!c1cs) {
        // 0x800FAD50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FAD5C;
    }
    goto skip_2;
    // 0x800FAD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800FAD54: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
L_800FAD58:
    // 0x800FAD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FAD5C:
    // 0x800FAD5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800FAD60: jr          $ra
    // 0x800FAD64: nop

    return;
    // 0x800FAD64: nop

;}
RECOMP_FUNC void func_808011D4_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808011D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808011E0: jal         0x80100094
    // 0x808011E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808011E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808011E8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808011EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808011F0: lhu         $t6, 0x72($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X72);
    // 0x808011F4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808011F8: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x808011FC: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x80801200: beq         $at, $zero, L_80801308
    if (ctx->r1 == 0) {
        // 0x80801204: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801308;
    }
    // 0x80801204: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801208: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X24A4) << 16);
    // 0x8080120C: addu        $at, $at, $t8
    gpr jr_addend_80801214 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801210: lw          $t8, 0x24A4($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2204, 0X24A4));
    // 0x80801214: jr          $t8
    // 0x80801218: nop

    switch (jr_addend_80801214 >> 2) {
        case 0: goto L_8080121C; break;
        case 1: goto L_80801234; break;
        case 2: goto L_80801308; break;
        case 3: goto L_8080126C; break;
        case 4: goto L_80801308; break;
        case 5: goto L_80801308; break;
        case 6: goto L_80801308; break;
        case 7: goto L_8080127C; break;
        case 8: goto L_80801300; break;
        case 9: goto L_808012DC; break;
        default: switch_error(__func__, 0x80801214, 0x808024A4);
    }
    // 0x80801218: nop

L_8080121C:
    // 0x8080121C: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    // 0x80801220: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80801224: jal         0x800D24E8
    // 0x80801228: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_1;
    // 0x80801228: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080122C: b           L_8080130C
    // 0x80801230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080130C;
    // 0x80801230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801234:
    // 0x80801234: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    // 0x80801238: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8080123C: jal         0x800D24E8
    // 0x80801240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_2;
    // 0x80801240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80801244: jal         0x80801128
    // 0x80801248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80801128_chtntmineshoot(rdram, ctx);
        goto after_3;
    // 0x80801248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8080124C: jal         0x800CEAD0
    // 0x80801250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_4;
    // 0x80801250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80801254: beq         $v0, $zero, L_80801308
    if (ctx->r2 == 0) {
        // 0x80801258: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801308;
    }
    // 0x80801258: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080125C: jal         0x80800E64
    // 0x80801260: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_5;
    // 0x80801260: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80801264: b           L_8080130C
    // 0x80801268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080130C;
    // 0x80801268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080126C:
    // 0x8080126C: jal         0x80801318
    // 0x80801270: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80801318_chtntmineshoot(rdram, ctx);
        goto after_6;
    // 0x80801270: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x80801274: b           L_8080130C
    // 0x80801278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080130C;
    // 0x80801278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080127C:
    // 0x8080127C: jal         0x800D8FF8
    // 0x80801280: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x80801280: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_7:
    // 0x80801284: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801288: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X24CC) << 16);
    // 0x8080128C: lwc1        $f14, 0x24CC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2204, 0X24CC));
    // 0x80801290: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80801294: jal         0x800F13F0
    // 0x80801298: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800F13F0(rdram, ctx);
        goto after_8;
    // 0x80801298: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_8:
    // 0x8080129C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808012A0: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    // 0x808012A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808012A8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x808012AC: jal         0x800D2498
    // 0x808012B0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    func_800D2498(rdram, ctx);
        goto after_9;
    // 0x808012B0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_9:
    // 0x808012B4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808012B8: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    // 0x808012BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808012C0: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808012C4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808012C8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808012CC: jal         0x800D2498
    // 0x808012D0: nop

    func_800D2498(rdram, ctx);
        goto after_10;
    // 0x808012D0: nop

    after_10:
    // 0x808012D4: b           L_8080130C
    // 0x808012D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080130C;
    // 0x808012D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808012DC:
    // 0x808012DC: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808012E0: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    // 0x808012E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808012E8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808012EC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808012F0: jal         0x800D2498
    // 0x808012F4: nop

    func_800D2498(rdram, ctx);
        goto after_11;
    // 0x808012F4: nop

    after_11:
    // 0x808012F8: b           L_8080130C
    // 0x808012FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080130C;
    // 0x808012FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801300:
    // 0x80801300: jal         0x8080146C
    // 0x80801304: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8080146C_chtntmineshoot(rdram, ctx);
        goto after_12;
    // 0x80801304: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_12:
L_80801308:
    // 0x80801308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080130C:
    // 0x8080130C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801310: jr          $ra
    // 0x80801314: nop

    return;
    // 0x80801314: nop

;}
RECOMP_FUNC void func_808004E4_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808004E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808004EC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808004F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004F4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808004F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808004FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800500: addiu       $a0, $zero, 0x37F
    ctx->r4 = ADD32(0, 0X37F);
    // 0x80800504: jal         0x801084B0
    // 0x80800508: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80800508: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x8080050C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800510: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800514: jal         0x80100094
    // 0x80800518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080051C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800520: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800524: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800528: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8080052C: addu        $t9, $v0, $s1
    ctx->r25 = ADD32(ctx->r2, ctx->r17);
    // 0x80800530: sw          $t7, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r15;
    // 0x80800534: jal         0x80800350
    // 0x80800538: sb          $t8, 0xAC($t9)
    MEM_B(0XAC, ctx->r25) = ctx->r24;
    func_80800350_chdodgemcontrol(rdram, ctx);
        goto after_2;
    // 0x80800538: sb          $t8, 0xAC($t9)
    MEM_B(0XAC, ctx->r25) = ctx->r24;
    after_2:
    // 0x8080053C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80800540: andi        $t3, $s1, 0x1FF
    ctx->r11 = ctx->r17 & 0X1FF;
    // 0x80800544: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x80800548: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x8080054C: sb          $v0, 0xB6($t1)
    MEM_B(0XB6, ctx->r9) = ctx->r2;
    // 0x80800550: lhu         $t4, 0x6E($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X6E);
    // 0x80800554: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x80800558: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x8080055C: sh          $t6, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r14;
L_80800560:
    // 0x80800560: jal         0x808003B0
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003B0_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800568: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8080056C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800570: jal         0x8080040C
    // 0x80800574: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8080040C_chdodgemcontrol(rdram, ctx);
        goto after_4;
    // 0x80800574: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x80800578: beq         $v0, $zero, L_80800560
    if (ctx->r2 == 0) {
        // 0x8080057C: nop
    
            goto L_80800560;
    }
    // 0x8080057C: nop

    // 0x80800580: addiu       $a2, $s2, 0x4
    ctx->r6 = ADD32(ctx->r18, 0X4);
    // 0x80800584: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800588: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080058C: jal         0x800EE7F8
    // 0x80800590: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800590: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_5:
    // 0x80800594: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80800598: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8080059C: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x808005A0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808005A4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x808005A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808005AC: jal         0x800EE7F8
    // 0x808005B0: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x808005B0: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_6:
    // 0x808005B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005BC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808005C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808005C4: jr          $ra
    // 0x808005C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808005C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80800000_chfantasytrashcanbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x800EA090
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA090(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800018: bne         $v0, $at, L_80800034
    if (ctx->r2 != ctx->r1) {
        // 0x8080001C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800034;
    }
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: jal         0x80101FDC
    // 0x80800028: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x8080002C: b           L_8080003C
    // 0x80800030: nop

        goto L_8080003C;
    // 0x80800030: nop

L_80800034:
    // 0x80800034: jal         0x80101FDC
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_8080003C:
    // 0x8080003C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2352, 0X230) << 16);
    // 0x80800040: lwc1        $f6, 0x230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2352, 0X230));
    // 0x80800044: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800048: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080004C: addiu       $t6, $zero, 0x80A
    ctx->r14 = ADD32(0, 0X80A);
    // 0x80800050: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800054: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800058: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800064: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800068: jal         0x80086898
    // 0x8080006C: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080006C: nop

    after_3:
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: jal         0x800868C0
    // 0x80800078: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800078: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: jal         0x800868A8
    // 0x80800084: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800084: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_5:
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800090: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800094: jal         0x800868C8
    // 0x80800098: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80800098: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_6:
    // 0x8080009C: jal         0x800F54E4
    // 0x808000A0: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x808000A0: nop

    after_7:
    // 0x808000A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000A8: jal         0x800F64A4
    // 0x808000AC: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800F64A4(rdram, ctx);
        goto after_8;
    // 0x808000AC: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_8:
    // 0x808000B0: bnel        $v0, $zero, L_808000DC
    if (ctx->r2 != 0) {
        // 0x808000B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000DC;
    }
    goto skip_0;
    // 0x808000B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000B8: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808000BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808000C8: bne         $t8, $at, L_808000D8
    if (ctx->r24 != ctx->r1) {
        // 0x808000CC: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_808000D8;
    }
    // 0x808000CC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808000D0: jal         0x8010108C
    // 0x808000D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_9;
    // 0x808000D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
L_808000D8:
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000DC:
    // 0x808000DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void func_80801CE4_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801CE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801CF0: jal         0x8008CAEC
    // 0x80801CF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_isStopped(rdram, ctx);
        goto after_0;
    // 0x80801CF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80801CF8: bnel        $v0, $zero, L_80801D10
    if (ctx->r2 != 0) {
        // 0x80801CFC: addiu       $t6, $zero, 0x2B
        ctx->r14 = ADD32(0, 0X2B);
            goto L_80801D10;
    }
    goto skip_0;
    // 0x80801CFC: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    skip_0:
    // 0x80801D00: jal         0x80085280
    // 0x80801D04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baswim_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801D04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801D08: beq         $v0, $zero, L_80801D14
    if (ctx->r2 == 0) {
        // 0x80801D0C: addiu       $t6, $zero, 0x2B
        ctx->r14 = ADD32(0, 0X2B);
            goto L_80801D14;
    }
    // 0x80801D0C: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
L_80801D10:
    // 0x80801D10: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80801D14:
    // 0x80801D14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801D18: jal         0x8009E5C8
    // 0x80801D1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80801D1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80801D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D28: jr          $ra
    // 0x80801D2C: nop

    return;
    // 0x80801D2C: nop

;}
RECOMP_FUNC void func_808002F4_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002FC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800300: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800304: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800308: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080030C: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x80800310: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800314: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800318: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080031C: blez        $t6, L_80800360
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800320: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80800360;
    }
    // 0x80800320: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800324: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800328:
    // 0x80800328: jal         0x80800064
    // 0x8080032C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800064_chwarppad(rdram, ctx);
        goto after_0;
    // 0x8080032C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80800330: beql        $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x80800334: lw          $t7, 0x1C($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X1C);
            goto L_80800350;
    }
    goto skip_0;
    // 0x80800334: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
    skip_0:
    // 0x80800338: bnel        $s1, $s3, L_8080034C
    if (ctx->r17 != ctx->r19) {
        // 0x8080033C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080034C;
    }
    goto skip_1;
    // 0x8080033C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80800340: b           L_80800364
    // 0x80800344: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80800364;
    // 0x80800344: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800348: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080034C:
    // 0x8080034C: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
L_80800350:
    // 0x80800350: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800354: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80800358: beql        $at, $zero, L_80800328
    if (ctx->r1 == 0) {
        // 0x8080035C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800328;
    }
    goto skip_2;
    // 0x8080035C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
L_80800360:
    // 0x80800360: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800364:
    // 0x80800364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800368: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080036C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800370: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800374: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800378: jr          $ra
    // 0x8080037C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080037C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chsilo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E60: syscall     462
    recomp_syscall_handler(rdram, ctx, 0x80086E60);
    return;
    // 0x80086E64: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void sumumbofx_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801370: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80801374: jr          $ra
    // 0x80801378: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80801378: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800944_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800944: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080094C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800950: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(804, 0X7DE4) << 16);
    // 0x80800954: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800958: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080095C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800960: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800964: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800968: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8080096C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800970: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800974: lw          $v0, 0x7DE4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(804, 0X7DE4));
    // 0x80800978: beql        $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x8080097C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080098C;
    }
    goto skip_0;
    // 0x8080097C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800980: jalr        $v0
    // 0x80800984: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80800984: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080098C:
    // 0x8080098C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800990: jr          $ra
    // 0x80800994: nop

    return;
    // 0x80800994: nop

;}
RECOMP_FUNC void func_80800FAC_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800FB8: jal         0x80100094
    // 0x80800FBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800FC0: beq         $v0, $zero, L_80800FD0
    if (ctx->r2 == 0) {
        // 0x80800FC4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800FD0;
    }
    // 0x80800FC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FC8: jal         0x800897C8
    // 0x80800FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800FD0:
    // 0x80800FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FD8: jr          $ra
    // 0x80800FDC: nop

    return;
    // 0x80800FDC: nop

;}
RECOMP_FUNC void func_800F56AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F56AC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F56B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F56B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F56B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F56BC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F56C0: jal         0x80096694
    // 0x800F56C4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80096694(rdram, ctx);
        goto after_0;
    // 0x800F56C4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F56C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F56CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F56D0: jr          $ra
    // 0x800F56D4: nop

    return;
    // 0x800F56D4: nop

;}
RECOMP_FUNC void func_80801844_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801844: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801848: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080184C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80801850: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80801854: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801858: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080185C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801860: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801864: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801868: lbu         $s0, 0x79($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X79);
    // 0x8080186C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801870: srl         $t7, $s0, 4
    ctx->r15 = S32(U32(ctx->r16) >> 4);
    // 0x80801874: jal         0x80100094
    // 0x80801878: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801878: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    after_0:
    // 0x8080187C: lbu         $s4, 0xC2($v0)
    ctx->r20 = MEM_BU(ctx->r2, 0XC2);
    // 0x80801880: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801884: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801888: blez        $s4, L_80801900
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8080188C: or          $s5, $s0, $zero
        ctx->r21 = ctx->r16 | 0;
            goto L_80801900;
    }
    // 0x8080188C: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x80801890: sll         $t8, $s5, 4
    ctx->r24 = S32(ctx->r21 << 4);
    // 0x80801894: andi        $s5, $t8, 0xF0
    ctx->r21 = ctx->r24 & 0XF0;
    // 0x80801898: addiu       $s3, $sp, 0x30
    ctx->r19 = ADD32(ctx->r29, 0X30);
L_8080189C:
    // 0x8080189C: addiu       $a0, $zero, 0x305
    ctx->r4 = ADD32(0, 0X305);
    // 0x808018A0: jal         0x801084B0
    // 0x808018A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x808018A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x808018A8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808018AC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x808018B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808018B4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x808018B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808018BC: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x808018C0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x808018C4: lbu         $t3, 0x79($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X79);
    // 0x808018C8: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x808018CC: or          $t5, $s5, $t4
    ctx->r13 = ctx->r21 | ctx->r12;
    // 0x808018D0: sb          $t5, 0x79($v0)
    MEM_B(0X79, ctx->r2) = ctx->r13;
    // 0x808018D4: jal         0x80801928
    // 0x808018D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80801928_chdodgemcontrol(rdram, ctx);
        goto after_2;
    // 0x808018D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x808018DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018E0: jal         0x80108944
    // 0x808018E4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80108944(rdram, ctx);
        goto after_3;
    // 0x808018E4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x808018E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808018EC: jal         0x80801744
    // 0x808018F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801744_chdodgemcontrol(rdram, ctx);
        goto after_4;
    // 0x808018F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x808018F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808018F8: bne         $s1, $s4, L_8080189C
    if (ctx->r17 != ctx->r20) {
        // 0x808018FC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8080189C;
    }
    // 0x808018FC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80801900:
    // 0x80801900: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801904: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80801908: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080190C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801910: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801914: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801918: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8080191C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80801920: jr          $ra
    // 0x80801924: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801924: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800F70_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F7C: jal         0x808001A8
    // 0x80800F80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800F80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F88: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x80800F8C: jal         0x8008CB3C
    // 0x80800F90: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800F90: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80800F94: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80800F98: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800FA4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800FA8: jal         0x8009FFD8
    // 0x80800FAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800FAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800FB0: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800FB4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FBC: jal         0x8008C9BC
    // 0x80800FC0: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_3;
    // 0x80800FC0: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_3:
    // 0x80800FC4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(427, 0X1B54) << 16);
    // 0x80800FC8: lwc1        $f4, 0x1B54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(427, 0X1B54));
    // 0x80800FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD0: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800FD4: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x80800FD8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800FDC: jal         0x8008C9F0
    // 0x80800FE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x80800FE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE8: jal         0x8008CA30
    // 0x80800FEC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_5;
    // 0x80800FEC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80800FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FF4: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80800FF8: jal         0x8009C99C
    // 0x80800FFC: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_6;
    // 0x80800FFC: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_6:
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801004: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80801008: jal         0x8009BFE4
    // 0x8080100C: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_7;
    // 0x8080100C: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_7:
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801014: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80801018: jal         0x8009C554
    // 0x8080101C: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_8;
    // 0x8080101C: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_8:
    // 0x80801020: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801024: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801028: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080102C: jr          $ra
    // 0x80801030: nop

    return;
    // 0x80801030: nop

;}
RECOMP_FUNC void func_800951F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800951F4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800951F8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800951FC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80095200: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80095204: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80095208: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8009520C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80095210: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80095214: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80095218: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8009521C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80095220: jal         0x800D8FF8
    // 0x80095224: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80095224: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x80095228: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009522C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80095230: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80095234: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80095238: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009523C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80095240: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x80095244: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80095248: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_8009524C:
    // 0x8009524C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095250: jal         0x80094F88
    // 0x80095254: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80094F88(rdram, ctx);
        goto after_1;
    // 0x80095254: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80095258: lw          $t6, 0x78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X78);
    // 0x8009525C: addu        $v0, $t6, $s2
    ctx->r2 = ADD32(ctx->r14, ctx->r18);
    // 0x80095260: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x80095264: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80095268: beq         $at, $zero, L_80095338
    if (ctx->r1 == 0) {
        // 0x8009526C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80095338;
    }
    // 0x8009526C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80095270: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095274: addu        $at, $at, $t7
    gpr jr_addend_8009527C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80095278: lw          $t7, 0x4D50($at)
    ctx->r15 = ADD32(ctx->r1, 0X4D50);
    // 0x8009527C: jr          $t7
    // 0x80095280: nop

    switch (jr_addend_8009527C >> 2) {
        case 0: goto L_80095338; break;
        case 1: goto L_80095284; break;
        case 2: goto L_800952C0; break;
        case 3: goto L_800952C8; break;
        case 4: goto L_800952C8; break;
        case 5: goto L_80095304; break;
        default: switch_error(__func__, 0x8009527C, 0x80124D50);
    }
    // 0x80095280: nop

L_80095284:
    // 0x80095284: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80095288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009528C: div.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80095290: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80095294: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80095298: nop

    // 0x8009529C: bc1fl       L_800952B0
    if (!c1cs) {
        // 0x800952A0: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_800952B0;
    }
    goto skip_0;
    // 0x800952A0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_0:
    // 0x800952A4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800952A8: sb          $s3, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r19;
    // 0x800952AC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_800952B0:
    // 0x800952B0: jal         0x80095004
    // 0x800952B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80095004(rdram, ctx);
        goto after_2;
    // 0x800952B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800952B8: b           L_8009533C
    // 0x800952BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8009533C;
    // 0x800952BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800952C0:
    // 0x800952C0: b           L_80095338
    // 0x800952C4: sb          $s5, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r21;
        goto L_80095338;
    // 0x800952C4: sb          $s5, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r21;
L_800952C8:
    // 0x800952C8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800952CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800952D0: div.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f22.fl, ctx->f8.fl);
    // 0x800952D4: sub.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800952D8: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x800952DC: nop

    // 0x800952E0: bc1fl       L_800952F4
    if (!c1cs) {
        // 0x800952E4: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_800952F4;
    }
    goto skip_1;
    // 0x800952E4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_1:
    // 0x800952E8: mov.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = ctx->f24.fl;
    // 0x800952EC: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x800952F0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_800952F4:
    // 0x800952F4: jal         0x80095004
    // 0x800952F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80095004(rdram, ctx);
        goto after_3;
    // 0x800952F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800952FC: b           L_8009533C
    // 0x80095300: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8009533C;
    // 0x80095300: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80095304:
    // 0x80095304: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80095308: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009530C: div.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80095310: add.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80095314: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80095318: nop

    // 0x8009531C: bc1fl       L_80095330
    if (!c1cs) {
        // 0x80095320: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_80095330;
    }
    goto skip_2;
    // 0x80095320: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_2:
    // 0x80095324: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x80095328: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x8009532C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_80095330:
    // 0x80095330: jal         0x80095004
    // 0x80095334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80095004(rdram, ctx);
        goto after_4;
    // 0x80095334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
L_80095338:
    // 0x80095338: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8009533C:
    // 0x8009533C: bne         $s0, $s4, L_8009524C
    if (ctx->r16 != ctx->r20) {
        // 0x80095340: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_8009524C;
    }
    // 0x80095340: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80095344: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80095348: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8009534C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80095350: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80095354: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80095358: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8009535C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80095360: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80095364: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80095368: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8009536C: jr          $ra
    // 0x80095370: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80095370: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80095374: nop

    // 0x80095378: nop

    // 0x8009537C: nop

;}
RECOMP_FUNC void func_800BD030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD038: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BD03C: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD040: lbu         $a1, 0x8($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X8);
    // 0x800BD044: jal         0x800BCCC0
    // 0x800BD048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    static_16_800BCCC0(rdram, ctx);
        goto after_0;
    // 0x800BD048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BD04C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD050: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800BD054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BD058: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800BD05C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800BD060: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800BD064: addu        $t3, $a1, $t8
    ctx->r11 = ADD32(ctx->r5, ctx->r24);
    // 0x800BD068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD06C: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800BD070: sltu        $v0, $zero, $t0
    ctx->r2 = 0 < ctx->r8 ? 1 : 0;
    // 0x800BD074: beq         $v0, $zero, L_800BD094
    if (ctx->r2 == 0) {
        // 0x800BD078: nop
    
            goto L_800BD094;
    }
    // 0x800BD078: nop

    // 0x800BD07C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800BD080: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800BD084: srl         $t5, $t4, 1
    ctx->r13 = S32(U32(ctx->r12) >> 1);
    // 0x800BD088: subu        $v0, $t2, $t5
    ctx->r2 = SUB32(ctx->r10, ctx->r13);
    // 0x800BD08C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800BD090: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
L_800BD094:
    // 0x800BD094: jr          $ra
    // 0x800BD098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800BD098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chclinker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873A8: syscall     560
    recomp_syscall_handler(rdram, ctx, 0x800873A8);
    return;
    // 0x800873AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80804694_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080469C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808046A0: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    // 0x808046A4: jal         0x80801658
    // 0x808046A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801658_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808046A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808046AC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808046B0: jal         0x80802BE8
    // 0x808046B4: lw          $a0, 0x30($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X30);
    func_80802BE8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x808046B4: lw          $a0, 0x30($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X30);
    after_1:
    // 0x808046B8: jal         0x800886D0
    // 0x808046BC: nop

    _glglobalsettings_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808046BC: nop

    after_2:
    // 0x808046C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808046C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808046C8: jr          $ra
    // 0x808046CC: nop

    return;
    // 0x808046CC: nop

;}
RECOMP_FUNC void _bsdie_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FA8: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082FA8);
    return;
    // 0x80082FAC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_801015BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801015BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801015C0: jr          $ra
    // 0x801015C4: sh          $zero, 0x5A94($at)
    MEM_H(0X5A94, ctx->r1) = 0;
    return;
    // 0x801015C4: sh          $zero, 0x5A94($at)
    MEM_H(0X5A94, ctx->r1) = 0;
;}
RECOMP_FUNC void _baeggaim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A98: syscall     127
    recomp_syscall_handler(rdram, ctx, 0x80084A98);
    return;
    // 0x80084A9C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800950_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800950: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800954: addiu       $t7, $a1, -0x2
    ctx->r15 = ADD32(ctx->r5, -0X2);
    // 0x80800958: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080095C: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x80800960: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800964: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800968: beq         $at, $zero, L_80800B48
    if (ctx->r1 == 0) {
        // 0x8080096C: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800B48;
    }
    // 0x8080096C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800970: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800974: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1D0C) << 16);
    // 0x80800978: addu        $at, $at, $t7
    gpr jr_addend_80800980 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080097C: lw          $t7, 0x1D0C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1D0C));
    // 0x80800980: jr          $t7
    // 0x80800984: nop

    switch (jr_addend_80800980 >> 2) {
        case 0: goto L_80800988; break;
        case 1: goto L_808009E0; break;
        case 2: goto L_80800B48; break;
        case 3: goto L_80800B48; break;
        case 4: goto L_80800A94; break;
        case 5: goto L_808009F0; break;
        case 6: goto L_80800A80; break;
        case 7: goto L_80800AC4; break;
        case 8: goto L_808009F0; break;
        case 9: goto L_80800A80; break;
        case 10: goto L_80800AC4; break;
        default: switch_error(__func__, 0x80800980, 0x80801D0C);
    }
    // 0x80800984: nop

L_80800988:
    // 0x80800988: jal         0x800DA298
    // 0x8080098C: addiu       $a0, $zero, 0x6EC
    ctx->r4 = ADD32(0, 0X6EC);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080098C: addiu       $a0, $zero, 0x6EC
    ctx->r4 = ADD32(0, 0X6EC);
    after_0:
    // 0x80800990: bne         $v0, $zero, L_808009A4
    if (ctx->r2 != 0) {
        // 0x80800994: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009A4;
    }
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800998: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x8080099C: jal         0x80801290
    // 0x808009A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801290_chfantasyeyeball(rdram, ctx);
        goto after_1;
    // 0x808009A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_808009A4:
    // 0x808009A4: jal         0x800DA298
    // 0x808009A8: addiu       $a0, $zero, 0x6D4
    ctx->r4 = ADD32(0, 0X6D4);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808009A8: addiu       $a0, $zero, 0x6D4
    ctx->r4 = ADD32(0, 0X6D4);
    after_2:
    // 0x808009AC: bnel        $v0, $zero, L_80800B4C
    if (ctx->r2 != 0) {
        // 0x808009B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B4C;
    }
    goto skip_0;
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808009B4: jal         0x800DA544
    // 0x808009B8: addiu       $a0, $zero, 0x6D4
    ctx->r4 = ADD32(0, 0X6D4);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x808009B8: addiu       $a0, $zero, 0x6D4
    ctx->r4 = ADD32(0, 0X6D4);
    after_3:
    // 0x808009BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808009C0: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x808009C4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808009C8: addiu       $a1, $zero, 0x141A
    ctx->r5 = ADD32(0, 0X141A);
    // 0x808009CC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808009D0: jal         0x8008A208
    // 0x808009D4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808009D4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808009D8: b           L_80800B4C
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B4C;
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009E0:
    // 0x808009E0: jal         0x808016B4
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016B4_chfantasyeyeball(rdram, ctx);
        goto after_5;
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808009E8: b           L_80800B48
    // 0x808009EC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_80800B48;
    // 0x808009EC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_808009F0:
    // 0x808009F0: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808009F4: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x808009F8: bgezl       $t1, L_80800A38
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808009FC: lui         $a0, 0xB31B
        ctx->r4 = S32(0XB31B << 16);
            goto L_80800A38;
    }
    goto skip_1;
    // 0x808009FC: lui         $a0, 0xB31B
    ctx->r4 = S32(0XB31B << 16);
    skip_1:
    // 0x80800A00: jal         0x800DA298
    // 0x80800A04: addiu       $a0, $zero, 0x6D5
    ctx->r4 = ADD32(0, 0X6D5);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800A04: addiu       $a0, $zero, 0x6D5
    ctx->r4 = ADD32(0, 0X6D5);
    after_6:
    // 0x80800A08: bnel        $v0, $zero, L_80800A38
    if (ctx->r2 != 0) {
        // 0x80800A0C: lui         $a0, 0xB31B
        ctx->r4 = S32(0XB31B << 16);
            goto L_80800A38;
    }
    goto skip_2;
    // 0x80800A0C: lui         $a0, 0xB31B
    ctx->r4 = S32(0XB31B << 16);
    skip_2:
    // 0x80800A10: jal         0x800DA544
    // 0x80800A14: addiu       $a0, $zero, 0x6D5
    ctx->r4 = ADD32(0, 0X6D5);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x80800A14: addiu       $a0, $zero, 0x6D5
    ctx->r4 = ADD32(0, 0X6D5);
    after_7:
    // 0x80800A18: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800A1C: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x80800A20: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800A24: addiu       $a1, $zero, 0x141B
    ctx->r5 = ADD32(0, 0X141B);
    // 0x80800A28: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800A2C: jal         0x8008A208
    // 0x80800A30: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800A30: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800A34: lui         $a0, 0xB31B
    ctx->r4 = S32(0XB31B << 16);
L_80800A38:
    // 0x80800A38: lui         $a2, 0x1B58
    ctx->r6 = S32(0X1B58 << 16);
    // 0x80800A3C: ori         $a2, $a2, 0x1F4
    ctx->r6 = ctx->r6 | 0X1F4;
    // 0x80800A40: ori         $a0, $a0, 0x5DB8
    ctx->r4 = ctx->r4 | 0X5DB8;
    // 0x80800A44: jal         0x800C4140
    // 0x80800A48: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_9;
    // 0x80800A48: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80800A4C: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80800A50: sll         $t5, $t3, 11
    ctx->r13 = S32(ctx->r11 << 11);
    // 0x80800A54: bgezl       $t5, L_80800B4C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800A58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B4C;
    }
    goto skip_3;
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800A5C: jal         0x80800FEC
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800FEC_chfantasyeyeball(rdram, ctx);
        goto after_10;
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800A64: lui         $a1, 0x402D
    ctx->r5 = S32(0X402D << 16);
    // 0x80800A68: ori         $a1, $a1, 0x4FDF
    ctx->r5 = ctx->r5 | 0X4FDF;
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A70: jal         0x80801290
    // 0x80800A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801290_chfantasyeyeball(rdram, ctx);
        goto after_11;
    // 0x80800A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80800A78: b           L_80800B4C
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B4C;
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A80:
    // 0x80800A80: lui         $a0, 0x4CBB
    ctx->r4 = S32(0X4CBB << 16);
    // 0x80800A84: jal         0x800C3F48
    // 0x80800A88: ori         $a0, $a0, 0x5CEE
    ctx->r4 = ctx->r4 | 0X5CEE;
    func_800C3F48(rdram, ctx);
        goto after_12;
    // 0x80800A88: ori         $a0, $a0, 0x5CEE
    ctx->r4 = ctx->r4 | 0X5CEE;
    after_12:
    // 0x80800A8C: b           L_80800B4C
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B4C;
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A94:
    // 0x80800A94: lui         $a0, 0x4CBB
    ctx->r4 = S32(0X4CBB << 16);
    // 0x80800A98: jal         0x800C3F48
    // 0x80800A9C: ori         $a0, $a0, 0x5CED
    ctx->r4 = ctx->r4 | 0X5CED;
    func_800C3F48(rdram, ctx);
        goto after_13;
    // 0x80800A9C: ori         $a0, $a0, 0x5CED
    ctx->r4 = ctx->r4 | 0X5CED;
    after_13:
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: jal         0x8008A4B0
    // 0x80800AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x80800AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB0: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80800AB4: jal         0x80801290
    // 0x80800AB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801290_chfantasyeyeball(rdram, ctx);
        goto after_15;
    // 0x80800AB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80800ABC: b           L_80800B4C
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B4C;
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AC4:
    // 0x80800AC4: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800AC8: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800ACC: bgezl       $t8, L_80800B34
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800AD0: lbu         $t0, 0x65($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X65);
            goto L_80800B34;
    }
    goto skip_4;
    // 0x80800AD0: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    skip_4:
    // 0x80800AD4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80800AD8: beq         $a0, $zero, L_80800AFC
    if (ctx->r4 == 0) {
        // 0x80800ADC: nop
    
            goto L_80800AFC;
    }
    // 0x80800ADC: nop

    // 0x80800AE0: jal         0x80106790
    // 0x80800AE4: nop

    func_80106790(rdram, ctx);
        goto after_16;
    // 0x80800AE4: nop

    after_16:
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AEC: jal         0x80800F78
    // 0x80800AF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800F78_chfantasyeyeball(rdram, ctx);
        goto after_17;
    // 0x80800AF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x80800AF4: b           L_80800B34
    // 0x80800AF8: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
        goto L_80800B34;
    // 0x80800AF8: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
L_80800AFC:
    // 0x80800AFC: jal         0x800DA298
    // 0x80800B00: addiu       $a0, $zero, 0x6BD
    ctx->r4 = ADD32(0, 0X6BD);
    func_800DA298(rdram, ctx);
        goto after_18;
    // 0x80800B00: addiu       $a0, $zero, 0x6BD
    ctx->r4 = ADD32(0, 0X6BD);
    after_18:
    // 0x80800B04: bnel        $v0, $zero, L_80800B34
    if (ctx->r2 != 0) {
        // 0x80800B08: lbu         $t0, 0x65($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X65);
            goto L_80800B34;
    }
    goto skip_5;
    // 0x80800B08: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    skip_5:
    // 0x80800B0C: jal         0x800DA544
    // 0x80800B10: addiu       $a0, $zero, 0x6BD
    ctx->r4 = ADD32(0, 0X6BD);
    func_800DA544(rdram, ctx);
        goto after_19;
    // 0x80800B10: addiu       $a0, $zero, 0x6BD
    ctx->r4 = ADD32(0, 0X6BD);
    after_19:
    // 0x80800B14: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800B18: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x80800B1C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800B20: addiu       $a1, $zero, 0x141C
    ctx->r5 = ADD32(0, 0X141C);
    // 0x80800B24: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800B28: jal         0x8008A208
    // 0x80800B2C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_20;
    // 0x80800B2C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_20:
    // 0x80800B30: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
L_80800B34:
    // 0x80800B34: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800B38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B3C: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80800B40: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800B44: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_80800B48:
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B4C:
    // 0x80800B4C: jal         0x80102424
    // 0x80800B50: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_21;
    // 0x80800B50: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_21:
    // 0x80800B54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B60: jr          $ra
    // 0x80800B64: nop

    return;
    // 0x80800B64: nop

;}
RECOMP_FUNC void chpickups_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0X868) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x868
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X868));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x868
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X868));
;}
RECOMP_FUNC void func_80800334_chgate1doors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800334: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800338: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080033C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800340: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800344: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800348: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080034C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800350: beq         $t6, $at, L_80800374
    if (ctx->r14 == ctx->r1) {
        // 0x80800354: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800374;
    }
    // 0x80800354: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800358: beq         $t6, $at, L_808003F4
    if (ctx->r14 == ctx->r1) {
        // 0x8080035C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F4;
    }
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800360: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800364: beql        $t6, $at, L_8080043C
    if (ctx->r14 == ctx->r1) {
        // 0x80800368: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080043C;
    }
    goto skip_0;
    // 0x80800368: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080036C: b           L_8080043C
    // 0x80800370: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8080043C;
    // 0x80800370: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800374:
    // 0x80800374: jal         0x800DA298
    // 0x80800378: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800378: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    after_0:
    // 0x8080037C: beq         $v0, $zero, L_80800438
    if (ctx->r2 == 0) {
        // 0x80800380: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_80800438;
    }
    // 0x80800380: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800384: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800388: jal         0x800EEB9C
    // 0x8080038C: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x8080038C: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_1:
    // 0x80800390: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800394: jal         0x800EF04C
    // 0x80800398: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80800398: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x8080039C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1916, 0X474) << 16);
    // 0x808003A0: lwc1        $f4, 0x474($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1916, 0X474));
    // 0x808003A4: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x808003A8: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x808003AC: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x808003B0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x808003B4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808003B8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808003BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808003C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808003C4: addiu       $a2, $zero, -0x28
    ctx->r6 = ADD32(0, -0X28);
    // 0x808003C8: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x808003CC: jal         0x80109748
    // 0x808003D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80109748(rdram, ctx);
        goto after_3;
    // 0x808003D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: jal         0x80101FDC
    // 0x808003DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808003DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E4: jal         0x80103110
    // 0x808003E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x808003E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808003EC: b           L_8080043C
    // 0x808003F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8080043C;
    // 0x808003F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003F4:
    // 0x808003F4: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808003F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003FC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80800400: jal         0x80102CF4
    // 0x80800404: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_80102CF4(rdram, ctx);
        goto after_6;
    // 0x80800404: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x80800408: beq         $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x8080040C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800430;
    }
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: jal         0x80101FDC
    // 0x80800418: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800418: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x80103110
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_8;
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800428: b           L_8080043C
    // 0x8080042C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8080043C;
    // 0x8080042C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800430:
    // 0x80800430: jal         0x80102B2C
    // 0x80800434: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102B2C(rdram, ctx);
        goto after_9;
    // 0x80800434: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
L_80800438:
    // 0x80800438: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080043C:
    // 0x8080043C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800440: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800444: jr          $ra
    // 0x80800448: nop

    return;
    // 0x80800448: nop

;}
RECOMP_FUNC void _cosectionstor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087838: syscall     634
    recomp_syscall_handler(rdram, ctx, 0x80087838);
    return;
    // 0x8008783C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80108F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108F08: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80108F0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80108F10: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80108F14: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80108F18: jal         0x80106790
    // 0x80108F1C: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80108F1C: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80108F20: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80108F24: jal         0x80088658
    // 0x80108F28: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    _glhittableDll_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80108F28: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_1:
    // 0x80108F2C: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x80108F30: jal         0x80088640
    // 0x80108F34: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    _glhittableDll_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80108F34: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_2:
    // 0x80108F38: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80108F3C: jal         0x80088650
    // 0x80108F40: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    _glhittableDll_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80108F40: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_3:
    // 0x80108F44: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80108F48: jal         0x80088638
    // 0x80108F4C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    _glhittableDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80108F4C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_4:
    // 0x80108F50: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x80108F54: jal         0x80100368
    // 0x80108F58: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    func_80100368(rdram, ctx);
        goto after_5;
    // 0x80108F58: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    after_5:
    // 0x80108F5C: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80108F60: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x80108F64: lw          $v1, 0x24($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X24);
    // 0x80108F68: srl         $t7, $v1, 22
    ctx->r15 = S32(U32(ctx->r3) >> 22);
    // 0x80108F6C: sltiu       $t8, $t7, 0x1
    ctx->r24 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80108F70: beql        $t8, $zero, L_80108FB8
    if (ctx->r24 == 0) {
        // 0x80108F74: lw          $t0, 0x8C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X8C);
            goto L_80108FB8;
    }
    goto skip_0;
    // 0x80108F74: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    skip_0:
    // 0x80108F78: lhu         $a0, 0x1A($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X1A);
    // 0x80108F7C: srl         $t9, $a0, 5
    ctx->r25 = S32(U32(ctx->r4) >> 5);
    // 0x80108F80: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80108F84: jal         0x800F70EC
    // 0x80108F88: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    func_800F70EC(rdram, ctx);
        goto after_6;
    // 0x80108F88: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    after_6:
    // 0x80108F8C: beq         $v0, $zero, L_80108FA4
    if (ctx->r2 == 0) {
        // 0x80108F90: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_80108FA4;
    }
    // 0x80108F90: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80108F94: jal         0x800F6C1C
    // 0x80108F98: nop

    func_800F6C1C(rdram, ctx);
        goto after_7;
    // 0x80108F98: nop

    after_7:
    // 0x80108F9C: bnel        $v0, $zero, L_80108FB8
    if (ctx->r2 != 0) {
        // 0x80108FA0: lw          $t0, 0x8C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X8C);
            goto L_80108FB8;
    }
    goto skip_1;
    // 0x80108FA0: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    skip_1:
L_80108FA4:
    // 0x80108FA4: jal         0x80088648
    // 0x80108FA8: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    _glhittableDll_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x80108FA8: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_8:
    // 0x80108FAC: bnel        $v0, $zero, L_801094D4
    if (ctx->r2 != 0) {
        // 0x80108FB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801094D4;
    }
    goto skip_2;
    // 0x80108FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80108FB4: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
L_80108FB8:
    // 0x80108FB8: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x80108FBC: bnel        $t0, $zero, L_80108FEC
    if (ctx->r8 != 0) {
        // 0x80108FC0: lw          $t5, 0x90($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X90);
            goto L_80108FEC;
    }
    goto skip_3;
    // 0x80108FC0: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    skip_3:
    // 0x80108FC4: bne         $v0, $zero, L_80108FDC
    if (ctx->r2 != 0) {
        // 0x80108FC8: lw          $t1, 0xA4($sp)
        ctx->r9 = MEM_W(ctx->r29, 0XA4);
            goto L_80108FDC;
    }
    // 0x80108FC8: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x80108FCC: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x80108FD0: srl         $t3, $t2, 22
    ctx->r11 = S32(U32(ctx->r10) >> 22);
    // 0x80108FD4: bnel        $t3, $zero, L_801094D4
    if (ctx->r11 != 0) {
        // 0x80108FD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801094D4;
    }
    goto skip_4;
    // 0x80108FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_80108FDC:
    // 0x80108FDC: bgtz        $v0, L_80108FE8
    if (SIGNED(ctx->r2) > 0) {
        // 0x80108FE0: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80108FE8;
    }
    // 0x80108FE0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80108FE4: sw          $t4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r12;
L_80108FE8:
    // 0x80108FE8: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
L_80108FEC:
    // 0x80108FEC: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80108FF0: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80108FF4: beql        $t5, $zero, L_801090A0
    if (ctx->r13 == 0) {
        // 0x80108FF8: lw          $t5, 0x94($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X94);
            goto L_801090A0;
    }
    goto skip_5;
    // 0x80108FF8: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    skip_5:
    // 0x80108FFC: jal         0x80102FA0
    // 0x80109000: ori         $a1, $a1, 0x20
    ctx->r5 = ctx->r5 | 0X20;
    func_80102FA0(rdram, ctx);
        goto after_9;
    // 0x80109000: ori         $a1, $a1, 0x20
    ctx->r5 = ctx->r5 | 0X20;
    after_9:
    // 0x80109004: beq         $v0, $zero, L_80109014
    if (ctx->r2 == 0) {
        // 0x80109008: lw          $t6, 0x9C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X9C);
            goto L_80109014;
    }
    // 0x80109008: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8010900C: b           L_80109048
    // 0x80109010: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
        goto L_80109048;
    // 0x80109010: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
L_80109014:
    // 0x80109014: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80109018: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8010901C: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x80109020: mflo        $v0
    ctx->r2 = lo;
    // 0x80109024: bne         $t7, $zero, L_80109030
    if (ctx->r15 != 0) {
        // 0x80109028: nop
    
            goto L_80109030;
    }
    // 0x80109028: nop

    // 0x8010902C: break       7
    do_break(2148569132);
L_80109030:
    // 0x80109030: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80109034: bne         $t7, $at, L_80109048
    if (ctx->r15 != ctx->r1) {
        // 0x80109038: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80109048;
    }
    // 0x80109038: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8010903C: bne         $t8, $at, L_80109048
    if (ctx->r24 != ctx->r1) {
        // 0x80109040: nop
    
            goto L_80109048;
    }
    // 0x80109040: nop

    // 0x80109044: break       6
    do_break(2148569156);
L_80109048:
    // 0x80109048: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8010904C: addu        $a0, $t6, $t9
    ctx->r4 = ADD32(ctx->r14, ctx->r25);
    // 0x80109050: lbu         $t0, 0x5C($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X5C);
    // 0x80109054: subu        $v1, $t0, $v0
    ctx->r3 = SUB32(ctx->r8, ctx->r2);
    // 0x80109058: bgez        $v1, L_80109068
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8010905C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80109068;
    }
    // 0x8010905C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80109060: b           L_80109068
    // 0x80109064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80109068;
    // 0x80109064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80109068:
    // 0x80109068: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x8010906C: beq         $t1, $zero, L_8010909C
    if (ctx->r9 == 0) {
        // 0x80109070: sb          $v0, 0x5C($a0)
        MEM_B(0X5C, ctx->r4) = ctx->r2;
            goto L_8010909C;
    }
    // 0x80109070: sb          $v0, 0x5C($a0)
    MEM_B(0X5C, ctx->r4) = ctx->r2;
    // 0x80109074: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x80109078: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8010907C: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80109080: bnel        $at, $zero, L_801090A0
    if (ctx->r1 != 0) {
        // 0x80109084: lw          $t5, 0x94($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X94);
            goto L_801090A0;
    }
    goto skip_6;
    // 0x80109084: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    skip_6:
    // 0x80109088: bgez        $t3, L_80109098
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8010908C: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_80109098;
    }
    // 0x8010908C: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80109090: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x80109094: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80109098:
    // 0x80109098: sw          $t4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r12;
L_8010909C:
    // 0x8010909C: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
L_801090A0:
    // 0x801090A0: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x801090A4: beql        $t5, $zero, L_80109110
    if (ctx->r13 == 0) {
        // 0x801090A8: lw          $t9, 0x90($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X90);
            goto L_80109110;
    }
    goto skip_7;
    // 0x801090A8: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    skip_7:
    // 0x801090AC: jal         0x800EC398
    // 0x801090B0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800EC398(rdram, ctx);
        goto after_10;
    // 0x801090B0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_10:
    // 0x801090B4: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x801090B8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x801090BC: jal         0x800F1DF4
    // 0x801090C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_11;
    // 0x801090C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_11:
    // 0x801090C4: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x801090C8: jal         0x800858E0
    // 0x801090CC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    _chbounce_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x801090CC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_12:
    // 0x801090D0: jal         0x800858D8
    // 0x801090D4: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    _chbounce_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x801090D4: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    after_13:
    // 0x801090D8: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x801090DC: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x801090E0: lw          $t8, 0x64($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X64);
    // 0x801090E4: sll         $t6, $t8, 6
    ctx->r14 = S32(ctx->r24 << 6);
    // 0x801090E8: bgez        $t6, L_80109104
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801090EC: nop
    
            goto L_80109104;
    }
    // 0x801090EC: nop

    // 0x801090F0: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x801090F4: jal         0x800858F0
    // 0x801090F8: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    _chbounce_entrypoint_5(rdram, ctx);
        goto after_14;
    // 0x801090F8: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    after_14:
    // 0x801090FC: b           L_80109110
    // 0x80109100: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
        goto L_80109110;
    // 0x80109100: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
L_80109104:
    // 0x80109104: jal         0x800858F0
    // 0x80109108: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
    _chbounce_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x80109108: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
    after_15:
    // 0x8010910C: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
L_80109110:
    // 0x80109110: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x80109114: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80109118: beq         $t9, $zero, L_801094D0
    if (ctx->r25 == 0) {
        // 0x8010911C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801094D0;
    }
    // 0x8010911C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80109120: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80109124: beq         $t1, $at, L_80109158
    if (ctx->r9 == ctx->r1) {
        // 0x80109128: sw          $t2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r10;
            goto L_80109158;
    }
    // 0x80109128: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8010912C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80109130: bne         $t1, $at, L_80109174
    if (ctx->r9 != ctx->r1) {
        // 0x80109134: lw          $a0, 0x88($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X88);
            goto L_80109174;
    }
    // 0x80109134: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80109138: jal         0x80102FA0
    // 0x8010913C: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    func_80102FA0(rdram, ctx);
        goto after_16;
    // 0x8010913C: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    after_16:
    // 0x80109140: beq         $v0, $zero, L_80109174
    if (ctx->r2 == 0) {
        // 0x80109144: lw          $a0, 0x9C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X9C);
            goto L_80109174;
    }
    // 0x80109144: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80109148: jal         0x80109600
    // 0x8010914C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    func_80109600(rdram, ctx);
        goto after_17;
    // 0x8010914C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    after_17:
    // 0x80109150: b           L_80109178
    // 0x80109154: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
        goto L_80109178;
    // 0x80109154: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
L_80109158:
    // 0x80109158: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8010915C: jal         0x80102FA0
    // 0x80109160: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    func_80102FA0(rdram, ctx);
        goto after_18;
    // 0x80109160: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    after_18:
    // 0x80109164: beq         $v0, $zero, L_80109174
    if (ctx->r2 == 0) {
        // 0x80109168: lw          $a0, 0x9C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X9C);
            goto L_80109174;
    }
    // 0x80109168: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x8010916C: jal         0x80109600
    // 0x80109170: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    func_80109600(rdram, ctx);
        goto after_19;
    // 0x80109170: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    after_19:
L_80109174:
    // 0x80109174: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
L_80109178:
    // 0x80109178: jal         0x80102FA0
    // 0x8010917C: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    func_80102FA0(rdram, ctx);
        goto after_20;
    // 0x8010917C: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    after_20:
    // 0x80109180: beq         $v0, $zero, L_801091A8
    if (ctx->r2 == 0) {
        // 0x80109184: lw          $t3, 0xA4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XA4);
            goto L_801091A8;
    }
    // 0x80109184: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x80109188: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x8010918C: addiu       $at, $zero, 0x26D
    ctx->r1 = ADD32(0, 0X26D);
    // 0x80109190: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80109194: srl         $t5, $t4, 22
    ctx->r13 = S32(U32(ctx->r12) >> 22);
    // 0x80109198: bnel        $t5, $at, L_801091AC
    if (ctx->r13 != ctx->r1) {
        // 0x8010919C: lw          $a0, 0x88($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X88);
            goto L_801091AC;
    }
    goto skip_8;
    // 0x8010919C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    skip_8:
    // 0x801091A0: jal         0x800860D0
    // 0x801091A4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    _chflamer_entrypoint_1(rdram, ctx);
        goto after_21;
    // 0x801091A4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_21:
L_801091A8:
    // 0x801091A8: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
L_801091AC:
    // 0x801091AC: jal         0x80102FA0
    // 0x801091B0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_80102FA0(rdram, ctx);
        goto after_22;
    // 0x801091B0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_22:
    // 0x801091B4: beq         $v0, $zero, L_801091E8
    if (ctx->r2 == 0) {
        // 0x801091B8: lw          $t8, 0xA4($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA4);
            goto L_801091E8;
    }
    // 0x801091B8: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x801091BC: lw          $t7, 0x24($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X24);
    // 0x801091C0: addiu       $at, $zero, 0x26E
    ctx->r1 = ADD32(0, 0X26E);
    // 0x801091C4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x801091C8: srl         $t6, $t7, 22
    ctx->r14 = S32(U32(ctx->r15) >> 22);
    // 0x801091CC: bnel        $t6, $at, L_801091EC
    if (ctx->r14 != ctx->r1) {
        // 0x801091D0: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_801091EC;
    }
    goto skip_9;
    // 0x801091D0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_9:
    // 0x801091D4: jal         0x800EC370
    // 0x801091D8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EC370(rdram, ctx);
        goto after_23;
    // 0x801091D8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_23:
    // 0x801091DC: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x801091E0: jal         0x80085F80
    // 0x801091E4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    _chfreezy_entrypoint_1(rdram, ctx);
        goto after_24;
    // 0x801091E4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_24:
L_801091E8:
    // 0x801091E8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_801091EC:
    // 0x801091EC: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x801091F0: lbu         $v0, 0x5C($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X5C);
    // 0x801091F4: beq         $v0, $zero, L_80109218
    if (ctx->r2 == 0) {
        // 0x801091F8: nop
    
            goto L_80109218;
    }
    // 0x801091F8: nop

    // 0x801091FC: beq         $t0, $zero, L_80109434
    if (ctx->r8 == 0) {
        // 0x80109200: lw          $a0, 0x88($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X88);
            goto L_80109434;
    }
    // 0x80109200: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80109204: jal         0x80102FA0
    // 0x80109208: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_80102FA0(rdram, ctx);
        goto after_25;
    // 0x80109208: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_25:
    // 0x8010920C: beq         $v0, $zero, L_80109434
    if (ctx->r2 == 0) {
        // 0x80109210: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_80109434;
    }
    // 0x80109210: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80109214: lbu         $v0, 0x5C($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X5C);
L_80109218:
    // 0x80109218: beq         $v0, $zero, L_80109234
    if (ctx->r2 == 0) {
        // 0x8010921C: lw          $t1, 0x8C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X8C);
            goto L_80109234;
    }
    // 0x8010921C: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80109220: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80109224: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x80109228: sw          $t4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r12;
    // 0x8010922C: addiu       $t3, $t5, -0x1
    ctx->r11 = ADD32(ctx->r13, -0X1);
    // 0x80109230: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_80109234:
    // 0x80109234: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x80109238: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010923C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80109240: beq         $t7, $at, L_8010924C
    if (ctx->r15 == ctx->r1) {
        // 0x80109244: addiu       $t6, $zero, 0x63
        ctx->r14 = ADD32(0, 0X63);
            goto L_8010924C;
    }
    // 0x80109244: addiu       $t6, $zero, 0x63
    ctx->r14 = ADD32(0, 0X63);
    // 0x80109248: sb          $t6, 0x5C($t8)
    MEM_B(0X5C, ctx->r24) = ctx->r14;
L_8010924C:
    // 0x8010924C: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x80109250: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80109254: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x80109258: bnel        $t9, $at, L_80109428
    if (ctx->r25 != ctx->r1) {
        // 0x8010925C: lw          $a0, 0xA0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XA0);
            goto L_80109428;
    }
    goto skip_10;
    // 0x8010925C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    skip_10:
    // 0x80109260: beql        $t0, $zero, L_80109428
    if (ctx->r8 == 0) {
        // 0x80109264: lw          $a0, 0xA0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XA0);
            goto L_80109428;
    }
    goto skip_11;
    // 0x80109264: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    skip_11:
    // 0x80109268: jal         0x8010A430
    // 0x8010926C: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    func_8010A430(rdram, ctx);
        goto after_26;
    // 0x8010926C: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    after_26:
    // 0x80109270: beq         $v0, $zero, L_80109424
    if (ctx->r2 == 0) {
        // 0x80109274: lw          $a0, 0x9C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X9C);
            goto L_80109424;
    }
    // 0x80109274: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80109278: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    // 0x8010927C: jal         0x8010CD28
    // 0x80109280: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8010CD28(rdram, ctx);
        goto after_27;
    // 0x80109280: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_27:
    // 0x80109284: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80109288: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010928C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80109290: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80109294: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80109298: jal         0x800EE904
    // 0x8010929C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    func_800EE904(rdram, ctx);
        goto after_28;
    // 0x8010929C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    after_28:
    // 0x801092A0: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x801092A4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x801092A8: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    // 0x801092AC: beq         $a0, $zero, L_801092BC
    if (ctx->r4 == 0) {
        // 0x801092B0: nop
    
            goto L_801092BC;
    }
    // 0x801092B0: nop

    // 0x801092B4: jal         0x800DBEFC
    // 0x801092B8: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800DBEFC(rdram, ctx);
        goto after_29;
    // 0x801092B8: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_29:
L_801092BC:
    // 0x801092BC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801092C0: addiu       $a0, $a0, -0x710C
    ctx->r4 = ADD32(ctx->r4, -0X710C);
    // 0x801092C4: jal         0x800EB860
    // 0x801092C8: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    func_800EB860(rdram, ctx);
        goto after_30;
    // 0x801092C8: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    after_30:
    // 0x801092CC: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x801092D0: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801092D4: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x801092D8: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x801092DC: beq         $t4, $zero, L_80109350
    if (ctx->r12 == 0) {
        // 0x801092E0: nop
    
            goto L_80109350;
    }
    // 0x801092E0: nop

    // 0x801092E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801092E8: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x801092EC: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801092F0: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x801092F4: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x801092F8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x801092FC: bc1fl       L_80109328
    if (!c1cs) {
        // 0x80109300: lw          $t5, 0x8($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X8);
            goto L_80109328;
    }
    goto skip_12;
    // 0x80109300: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    skip_12:
    // 0x80109304: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80109308: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8010930C: bc1fl       L_80109328
    if (!c1cs) {
        // 0x80109310: lw          $t5, 0x8($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X8);
            goto L_80109328;
    }
    goto skip_13;
    // 0x80109310: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    skip_13:
    // 0x80109314: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80109318: nop

    // 0x8010931C: bc1t        L_80109350
    if (c1cs) {
        // 0x80109320: nop
    
            goto L_80109350;
    }
    // 0x80109320: nop

    // 0x80109324: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
L_80109328:
    // 0x80109328: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8010932C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80109330: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80109334: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80109338: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x8010933C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80109340: jal         0x80086D50
    // 0x80109344: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_31;
    // 0x80109344: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_31:
    // 0x80109348: b           L_8010941C
    // 0x8010934C: nop

        goto L_8010941C;
    // 0x8010934C: nop

L_80109350:
    // 0x80109350: jal         0x80102FA0
    // 0x80109354: lui         $a1, 0x8100
    ctx->r5 = S32(0X8100 << 16);
    func_80102FA0(rdram, ctx);
        goto after_32;
    // 0x80109354: lui         $a1, 0x8100
    ctx->r5 = S32(0X8100 << 16);
    after_32:
    // 0x80109358: beq         $v0, $zero, L_801093D8
    if (ctx->r2 == 0) {
        // 0x8010935C: nop
    
            goto L_801093D8;
    }
    // 0x8010935C: nop

    // 0x80109360: jal         0x800EC708
    // 0x80109364: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    func_800EC708(rdram, ctx);
        goto after_33;
    // 0x80109364: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_33:
    // 0x80109368: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8010936C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80109370: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80109374: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80109378: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8010937C: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80109380: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80109384: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80109388: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8010938C: jal         0x800882F8
    // 0x80109390: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    _gccubesearch_entrypoint_16(rdram, ctx);
        goto after_34;
    // 0x80109390: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_34:
    // 0x80109394: beq         $v0, $zero, L_801093D8
    if (ctx->r2 == 0) {
        // 0x80109398: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_801093D8;
    }
    // 0x80109398: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8010939C: jal         0x800EE88C
    // 0x801093A0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_800EE88C(rdram, ctx);
        goto after_35;
    // 0x801093A0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_35:
    // 0x801093A4: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x801093A8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x801093AC: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x801093B0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x801093B4: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x801093B8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x801093BC: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x801093C0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x801093C4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801093C8: jal         0x80086D50
    // 0x801093CC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_36;
    // 0x801093CC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_36:
    // 0x801093D0: b           L_8010941C
    // 0x801093D4: nop

        goto L_8010941C;
    // 0x801093D4: nop

L_801093D8:
    // 0x801093D8: jal         0x800EC708
    // 0x801093DC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    func_800EC708(rdram, ctx);
        goto after_37;
    // 0x801093DC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_37:
    // 0x801093E0: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x801093E4: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x801093E8: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x801093EC: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801093F0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x801093F4: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x801093F8: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801093FC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80109400: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80109404: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x80109408: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x8010940C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80109410: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80109414: jal         0x80086D50
    // 0x80109418: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_38;
    // 0x80109418: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_38:
L_8010941C:
    // 0x8010941C: jal         0x800EB874
    // 0x80109420: nop

    func_800EB874(rdram, ctx);
        goto after_39;
    // 0x80109420: nop

    after_39:
L_80109424:
    // 0x80109424: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_80109428:
    // 0x80109428: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x8010942C: jal         0x800EB210
    // 0x80109430: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    func_800EB210(rdram, ctx);
        goto after_40;
    // 0x80109430: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    after_40:
L_80109434:
    // 0x80109434: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x80109438: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8010943C: beql        $t4, $zero, L_801094D4
    if (ctx->r12 == 0) {
        // 0x80109440: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801094D4;
    }
    goto skip_14;
    // 0x80109440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x80109444: beq         $t5, $zero, L_801094D0
    if (ctx->r13 == 0) {
        // 0x80109448: lw          $t3, 0x9C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X9C);
            goto L_801094D0;
    }
    // 0x80109448: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8010944C: lw          $t7, 0x6C($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X6C);
    // 0x80109450: addiu       $at, $zero, 0x31E
    ctx->r1 = ADD32(0, 0X31E);
    // 0x80109454: addiu       $a2, $t3, 0x4
    ctx->r6 = ADD32(ctx->r11, 0X4);
    // 0x80109458: sll         $t6, $t7, 11
    ctx->r14 = S32(ctx->r15 << 11);
    // 0x8010945C: srl         $t8, $t6, 20
    ctx->r24 = S32(U32(ctx->r14) >> 20);
    // 0x80109460: bne         $t8, $at, L_80109470
    if (ctx->r24 != ctx->r1) {
        // 0x80109464: addiu       $a0, $zero, 0x415
        ctx->r4 = ADD32(0, 0X415);
            goto L_80109470;
    }
    // 0x80109464: addiu       $a0, $zero, 0x415
    ctx->r4 = ADD32(0, 0X415);
    // 0x80109468: b           L_80109470
    // 0x8010946C: addiu       $a0, $zero, 0x41F
    ctx->r4 = ADD32(0, 0X41F);
        goto L_80109470;
    // 0x8010946C: addiu       $a0, $zero, 0x41F
    ctx->r4 = ADD32(0, 0X41F);
L_80109470:
    // 0x80109470: jal         0x800C4B7C
    // 0x80109474: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800C4B7C(rdram, ctx);
        goto after_41;
    // 0x80109474: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_41:
    // 0x80109478: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8010947C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80109480: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80109484: lw          $a1, 0x70($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X70);
    // 0x80109488: addiu       $a3, $a3, 0x460C
    ctx->r7 = ADD32(ctx->r7, 0X460C);
    // 0x8010948C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80109490: andi        $t0, $a1, 0x1
    ctx->r8 = ctx->r5 & 0X1;
    // 0x80109494: jal         0x8010D930
    // 0x80109498: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_8010D930(rdram, ctx);
        goto after_42;
    // 0x80109498: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_42:
    // 0x8010949C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x801094A0: jal         0x80102FA0
    // 0x801094A4: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    func_80102FA0(rdram, ctx);
        goto after_43;
    // 0x801094A4: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    after_43:
    // 0x801094A8: bne         $v0, $zero, L_801094C0
    if (ctx->r2 != 0) {
        // 0x801094AC: lw          $a0, 0x88($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X88);
            goto L_801094C0;
    }
    // 0x801094AC: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x801094B0: jal         0x80102FA0
    // 0x801094B4: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    func_80102FA0(rdram, ctx);
        goto after_44;
    // 0x801094B4: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    after_44:
    // 0x801094B8: beql        $v0, $zero, L_801094D4
    if (ctx->r2 == 0) {
        // 0x801094BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801094D4;
    }
    goto skip_15;
    // 0x801094BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
L_801094C0:
    // 0x801094C0: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x801094C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801094C8: jal         0x80089BF8
    // 0x801094CC: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _subaddiejoy_entrypoint_10(rdram, ctx);
        goto after_45;
    // 0x801094CC: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_45:
L_801094D0:
    // 0x801094D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801094D4:
    // 0x801094D4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x801094D8: jr          $ra
    // 0x801094DC: nop

    return;
    // 0x801094DC: nop

;}
RECOMP_FUNC void bskazfly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800960: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800964: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(236, 0X1C48) << 16);
    // 0x80800968: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080096C: jr          $ra
    // 0x80800970: lw          $v0, 0x1C48($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C48));
    return;
    // 0x80800970: lw          $v0, 0x1C48($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C48));
;}
RECOMP_FUNC void bssplitup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800088: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080008C: jal         0x8008CAEC
    // 0x80800090: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_isStopped(rdram, ctx);
        goto after_0;
    // 0x80800090: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800094: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x80800098: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808000BC;
    }
    // 0x80800098: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080009C: jal         0x800F54E4
    // 0x808000A0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808000A0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_1:
    // 0x808000A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000A8: lw          $t7, 0x184($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X184);
    // 0x808000AC: beql        $v0, $t7, L_808000C0
    if (ctx->r2 == ctx->r15) {
        // 0x808000B0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000C0;
    }
    goto skip_0;
    // 0x808000B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808000B4: jal         0x800F457C
    // 0x808000B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F457C(rdram, ctx);
        goto after_2;
    // 0x808000B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_808000BC:
    // 0x808000BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808000C0:
    // 0x808000C0: jal         0x8009E5C8
    // 0x808000C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808000C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808000C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D0: jr          $ra
    // 0x808000D4: nop

    return;
    // 0x808000D4: nop

;}
RECOMP_FUNC void bssnowball_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CEC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800CF0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(356, 0X10B4) << 16);
    // 0x80800CF4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CF8: jr          $ra
    // 0x80800CFC: lw          $v0, 0x10B4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X10B4));
    return;
    // 0x80800CFC: lw          $v0, 0x10B4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X10B4));
;}
RECOMP_FUNC void func_80801FE4_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FE4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801FE8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801FEC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801FF0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80801FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801FF8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80801FFC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80802000: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80802004: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80802008: jal         0x800EE7F8
    // 0x8080200C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080200C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80802010: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80802014: jal         0x800EE7F8
    // 0x80802018: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80802018: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8080201C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80802020: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80802024: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80802028: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080202C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802030: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80802034: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80802038: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080203C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80802040: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80802044: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80802048: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8080204C: jal         0x800BEF00
    // 0x80802050: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80802050: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    after_2:
    // 0x80802054: beq         $v0, $zero, L_8080206C
    if (ctx->r2 == 0) {
        // 0x80802058: lwc1        $f4, 0x2C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8080206C;
    }
    // 0x80802058: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080205C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80802060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802064: b           L_80802070
    // 0x80802068: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
        goto L_80802070;
    // 0x80802068: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
L_8080206C:
    // 0x8080206C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802070:
    // 0x80802070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802074: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802078: jr          $ra
    // 0x8080207C: nop

    return;
    // 0x8080207C: nop

;}
