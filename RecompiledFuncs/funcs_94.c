#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chdoormake_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080094C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800950: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800954: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800958: jal         0x80100094
    // 0x8080095C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080095C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800960: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800964: lhu         $t6, 0x22($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X22);
    // 0x80800968: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8080096C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80800970: sb          $t6, 0x20($t9)
    MEM_B(0X20, ctx->r25) = ctx->r14;
    // 0x80800974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080097C: jr          $ra
    // 0x80800980: nop

    return;
    // 0x80800980: nop

    // 0x80800984: nop

    // 0x80800988: nop

    // 0x8080098C: nop

;}
RECOMP_FUNC void func_800D9FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9FFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800DA000: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800DA004: lw          $t6, -0x466C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X466C);
    // 0x800DA008: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DA00C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DA010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DA014: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x800DA018: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x800DA01C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_800DA020:
    // 0x800DA020: jal         0x800DA524
    // 0x800DA024: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x800DA024: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x800DA028: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800DA02C: bne         $s0, $s1, L_800DA020
    if (ctx->r16 != ctx->r17) {
        // 0x800DA030: nop
    
            goto L_800DA020;
    }
    // 0x800DA030: nop

    // 0x800DA034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA038: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DA03C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DA040: jr          $ra
    // 0x800DA044: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800DA044: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bskazfly_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BDC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801BE0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(236, 0X1CC8) << 16);
    // 0x80801BE4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801BE8: jr          $ra
    // 0x80801BEC: lw          $v0, 0x1CC8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1CC8));
    return;
    // 0x80801BEC: lw          $v0, 0x1CC8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1CC8));
;}
RECOMP_FUNC void bsdronegoto_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080041C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800420: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800424: jal         0x80800000
    // 0x80800428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_bsdronegoto(rdram, ctx);
        goto after_0;
    // 0x80800428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080042C: jal         0x80091E6C
    // 0x80800430: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80091E6C(rdram, ctx);
        goto after_1;
    // 0x80800430: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800434: jal         0x80087AC0
    // 0x80800438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcgoto_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x80800438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8080043C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800444: jr          $ra
    // 0x80800448: nop

    return;
    // 0x80800448: nop

;}
RECOMP_FUNC void func_808008A0_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808008AC: jal         0x80106790
    // 0x808008B0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808008B0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808008B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808008B8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808008BC: jal         0x80800238
    // 0x808008C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80800238_chhumba(rdram, ctx);
        goto after_1;
    // 0x808008C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x808008C4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x808008C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X245C) << 16);
    // 0x808008CC: lwc1        $f6, 0x245C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X245C));
    // 0x808008D0: lwc1        $f0, 0x38($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X38);
    // 0x808008D4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808008D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X2460) << 16);
    // 0x808008DC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808008E0: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808008E4: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x808008E8: nop

    // 0x808008EC: bc1fl       L_80800924
    if (!c1cs) {
        // 0x808008F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800924;
    }
    goto skip_0;
    // 0x808008F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808008F4: lwc1        $f10, 0x2460($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X2460));
    // 0x808008F8: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x808008FC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800900: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800904: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800908: jal         0x800F0064
    // 0x8080090C: nop

    func_800F0064(rdram, ctx);
        goto after_2;
    // 0x8080090C: nop

    after_2:
    // 0x80800910: beql        $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x80800914: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800924;
    }
    goto skip_1;
    // 0x80800914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800918: b           L_80800924
    // 0x8080091C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800924;
    // 0x8080091C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800924:
    // 0x80800924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800928: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080092C: jr          $ra
    // 0x80800930: nop

    return;
    // 0x80800930: nop

;}
RECOMP_FUNC void _chweather_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A00: syscall     185
    recomp_syscall_handler(rdram, ctx, 0x80085A00);
    return;
    // 0x80085A04: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_808011DC_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808011E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808011E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808011EC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808011F0: jal         0x800B53A4
    // 0x808011F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x808011F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808011F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808011FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801200: jal         0x800BA670
    // 0x80801204: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800BA670(rdram, ctx);
        goto after_1;
    // 0x80801204: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80801208: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8080120C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(792, 0X14B4) << 16);
    // 0x80801210: addiu       $t6, $t6, 0x14B4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(792, 0X14B4));
    // 0x80801214: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80801218: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x8080121C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801220: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801224: jal         0x800BABB8
    // 0x80801228: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80801228: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8080122C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801230: jal         0x800BA22C
    // 0x80801234: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80801234: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80801238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080123C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801240: jr          $ra
    // 0x80801244: nop

    return;
    // 0x80801244: nop

;}
RECOMP_FUNC void func_801018A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801018A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801018A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801018AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801018B0: jal         0x80101970
    // 0x801018B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80101970(rdram, ctx);
        goto after_0;
    // 0x801018B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801018B8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x801018BC: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x801018C0: jal         0x80101808
    // 0x801018C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101808(rdram, ctx);
        goto after_1;
    // 0x801018C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801018C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801018CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801018D0: jr          $ra
    // 0x801018D4: nop

    return;
    // 0x801018D4: nop

;}
RECOMP_FUNC void func_80111FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111FD4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80111FD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80111FDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80111FE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80111FE4: jal         0x80110898
    // 0x80111FE8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_80110898(rdram, ctx);
        goto after_0;
    // 0x80111FE8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80111FEC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80111FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111FF4: jal         0x801107F0
    // 0x80111FF8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x80111FF8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80111FFC: jal         0x8010FFD0
    // 0x80112000: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8010FFD0(rdram, ctx);
        goto after_2;
    // 0x80112000: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80112004: beq         $v0, $zero, L_8011203C
    if (ctx->r2 == 0) {
        // 0x80112008: nop
    
            goto L_8011203C;
    }
    // 0x80112008: nop

    // 0x8011200C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80112010: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x80112014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112018: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8011201C: swc1        $f4, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f4.u32l;
    // 0x80112020: jal         0x80113640
    // 0x80112024: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    func_80113640(rdram, ctx);
        goto after_3;
    // 0x80112024: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    after_3:
    // 0x80112028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011202C: jal         0x80110770
    // 0x80112030: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80110770(rdram, ctx);
        goto after_4;
    // 0x80112030: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x80112034: b           L_801120B8
    // 0x80112038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801120B8;
    // 0x80112038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8011203C:
    // 0x8011203C: jal         0x80111A98
    // 0x80112040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80111A98(rdram, ctx);
        goto after_5;
    // 0x80112040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80112044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112048: jal         0x80111ABC
    // 0x8011204C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80111ABC(rdram, ctx);
        goto after_6;
    // 0x8011204C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_6:
    // 0x80112050: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80112054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112058: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8011205C: addiu       $t7, $v0, 0x88
    ctx->r15 = ADD32(ctx->r2, 0X88);
    // 0x80112060: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80112064: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80112068: jal         0x80111F70
    // 0x8011206C: addiu       $a3, $v0, 0x78
    ctx->r7 = ADD32(ctx->r2, 0X78);
    func_80111F70(rdram, ctx);
        goto after_7;
    // 0x8011206C: addiu       $a3, $v0, 0x78
    ctx->r7 = ADD32(ctx->r2, 0X78);
    after_7:
    // 0x80112070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112074: jal         0x8011106C
    // 0x80112078: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8011106C(rdram, ctx);
        goto after_8;
    // 0x80112078: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_8:
    // 0x8011207C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80112080: jal         0x800EF04C
    // 0x80112084: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x80112084: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x80112088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011208C: jal         0x80110770
    // 0x80112090: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80110770(rdram, ctx);
        goto after_10;
    // 0x80112090: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_10:
    // 0x80112094: jal         0x8011329C
    // 0x80112098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8011329C(rdram, ctx);
        goto after_11;
    // 0x80112098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8011209C: beql        $v0, $zero, L_801120B8
    if (ctx->r2 == 0) {
        // 0x801120A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801120B8;
    }
    goto skip_0;
    // 0x801120A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801120A4: jal         0x80111C04
    // 0x801120A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80111C04(rdram, ctx);
        goto after_12;
    // 0x801120A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x801120AC: b           L_801120B8
    // 0x801120B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801120B8;
    // 0x801120B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801120B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801120B8:
    // 0x801120B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801120BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801120C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801120C4: jr          $ra
    // 0x801120C8: nop

    return;
    // 0x801120C8: nop

;}
RECOMP_FUNC void func_80015878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015878: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001587C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015880: addiu       $v0, $v0, -0x6848
    ctx->r2 = ADD32(ctx->r2, -0X6848);
    // 0x80015884: addiu       $v1, $v1, -0x6888
    ctx->r3 = ADD32(ctx->r3, -0X6888);
    // 0x80015888: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
L_8001588C:
    // 0x8001588C: blezl       $t6, L_8001589C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80015890: lh          $t7, 0x2($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X2);
            goto L_8001589C;
    }
    goto skip_0;
    // 0x80015890: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    skip_0:
    // 0x80015894: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80015898: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
L_8001589C:
    // 0x8001589C: blezl       $t7, L_800158AC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800158A0: lh          $t8, 0x4($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X4);
            goto L_800158AC;
    }
    goto skip_1;
    // 0x800158A0: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    skip_1:
    // 0x800158A4: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800158A8: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
L_800158AC:
    // 0x800158AC: blezl       $t8, L_800158BC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800158B0: lh          $t9, 0x6($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X6);
            goto L_800158BC;
    }
    goto skip_2;
    // 0x800158B0: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    skip_2:
    // 0x800158B4: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x800158B8: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
L_800158BC:
    // 0x800158BC: blezl       $t9, L_800158CC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800158C0: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800158CC;
    }
    goto skip_3;
    // 0x800158C0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    skip_3:
    // 0x800158C4: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x800158C8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800158CC:
    // 0x800158CC: bnel        $v1, $v0, L_8001588C
    if (ctx->r3 != ctx->r2) {
        // 0x800158D0: lh          $t6, 0x0($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X0);
            goto L_8001588C;
    }
    goto skip_4;
    // 0x800158D0: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    skip_4:
    // 0x800158D4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800158D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800158DC: jr          $ra
    // 0x800158E0: sh          $t0, -0xA20($at)
    MEM_H(-0XA20, ctx->r1) = ctx->r8;
    return;
    // 0x800158E0: sh          $t0, -0xA20($at)
    MEM_H(-0XA20, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void _chgate1doors_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FC0: syscall     487
    recomp_syscall_handler(rdram, ctx, 0x80086FC0);
    return;
    // 0x80086FC4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chlighthalo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087740: syscall     616
    recomp_syscall_handler(rdram, ctx, 0x80087740);
    return;
    // 0x80087744: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chboggykidshome_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1396, 0X468) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x468
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1396, 0X468));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x468
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1396, 0X468));
;}
RECOMP_FUNC void func_808004E0_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004E8: jal         0x80106790
    // 0x808004EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808004EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x808004F0: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x808004F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808004F8: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808004FC: bltz        $t8, L_8080051C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800500: nop
    
            goto L_8080051C;
    }
    // 0x80800500: nop

    // 0x80800504: jal         0x800CEAA8
    // 0x80800508: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800CEAA8(rdram, ctx);
        goto after_1;
    // 0x80800508: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x8080050C: beq         $v0, $zero, L_8080051C
    if (ctx->r2 == 0) {
        // 0x80800510: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_8080051C;
    }
    // 0x80800510: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800514: jal         0x800CE88C
    // 0x80800518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x80800518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8080051C:
    // 0x8080051C: jal         0x80803598
    // 0x80800520: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80803598_chjiggygamenew(rdram, ctx);
        goto after_3;
    // 0x80800520: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x80800524: jal         0x8008A740
    // 0x80800528: nop

    _sujiggy_entrypoint_21(rdram, ctx);
        goto after_4;
    // 0x80800528: nop

    after_4:
    // 0x8080052C: beq         $v0, $zero, L_80800664
    if (ctx->r2 == 0) {
        // 0x80800530: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80800664;
    }
    // 0x80800530: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800534: jal         0x8008A758
    // 0x80800538: nop

    _sujiggy_entrypoint_24(rdram, ctx);
        goto after_5;
    // 0x80800538: nop

    after_5:
    // 0x8080053C: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800540: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800544: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800548: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080054C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800550: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x80800554: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x80800558: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080055C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800560: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80800564: nop

    // 0x80800568: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x8080056C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800570: bne         $v0, $zero, L_808005A4
    if (ctx->r2 != 0) {
        // 0x80800574: sh          $t5, 0x6E($s0)
        MEM_H(0X6E, ctx->r16) = ctx->r13;
            goto L_808005A4;
    }
    // 0x80800574: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
    // 0x80800578: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080057C: jal         0x800C9C34
    // 0x80800580: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    func_800C9C34(rdram, ctx);
        goto after_6;
    // 0x80800580: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    after_6:
    // 0x80800584: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39A0) << 16);
    // 0x80800588: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8080058C: addiu       $a1, $a1, -0x3950
    ctx->r5 = ADD32(ctx->r5, -0X3950);
    // 0x80800590: lwc1        $f12, 0x39A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39A0));
    // 0x80800594: jal         0x800C9DE4
    // 0x80800598: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_800C9DE4(rdram, ctx);
        goto after_7;
    // 0x80800598: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_7:
    // 0x8080059C: b           L_80800694
    // 0x808005A0: addiu       $a1, $zero, 0x1564
    ctx->r5 = ADD32(0, 0X1564);
        goto L_80800694;
    // 0x808005A0: addiu       $a1, $zero, 0x1564
    ctx->r5 = ADD32(0, 0X1564);
L_808005A4:
    // 0x808005A4: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x808005A8: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x808005AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005B0: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x808005B4: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x808005B8: beq         $at, $zero, L_808005F0
    if (ctx->r1 == 0) {
        // 0x808005BC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_808005F0;
    }
    // 0x808005BC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x808005C0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808005C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808005C8: jal         0x800C9C34
    // 0x808005CC: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    func_800C9C34(rdram, ctx);
        goto after_8;
    // 0x808005CC: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    after_8:
    // 0x808005D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39A4) << 16);
    // 0x808005D4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x808005D8: addiu       $a1, $a1, -0x3950
    ctx->r5 = ADD32(ctx->r5, -0X3950);
    // 0x808005DC: lwc1        $f12, 0x39A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39A4));
    // 0x808005E0: jal         0x800C9DE4
    // 0x808005E4: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    func_800C9DE4(rdram, ctx);
        goto after_9;
    // 0x808005E4: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    after_9:
    // 0x808005E8: b           L_80800694
    // 0x808005EC: addiu       $a1, $zero, 0x1563
    ctx->r5 = ADD32(0, 0X1563);
        goto L_80800694;
    // 0x808005EC: addiu       $a1, $zero, 0x1563
    ctx->r5 = ADD32(0, 0X1563);
L_808005F0:
    // 0x808005F0: bne         $v0, $v1, L_80800630
    if (ctx->r2 != ctx->r3) {
        // 0x808005F4: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80800630;
    }
    // 0x808005F4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808005F8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808005FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800600: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x80800604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800608: jal         0x800C9C34
    // 0x8080060C: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    func_800C9C34(rdram, ctx);
        goto after_10;
    // 0x8080060C: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    after_10:
    // 0x80800610: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39A8) << 16);
    // 0x80800614: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80800618: addiu       $a1, $a1, -0x3950
    ctx->r5 = ADD32(ctx->r5, -0X3950);
    // 0x8080061C: lwc1        $f12, 0x39A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39A8));
    // 0x80800620: jal         0x800C9DE4
    // 0x80800624: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    func_800C9DE4(rdram, ctx);
        goto after_11;
    // 0x80800624: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    after_11:
    // 0x80800628: b           L_80800694
    // 0x8080062C: addiu       $a1, $zero, 0x1562
    ctx->r5 = ADD32(0, 0X1562);
        goto L_80800694;
    // 0x8080062C: addiu       $a1, $zero, 0x1562
    ctx->r5 = ADD32(0, 0X1562);
L_80800630:
    // 0x80800630: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800634: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x80800638: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080063C: jal         0x800C9C34
    // 0x80800640: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    func_800C9C34(rdram, ctx);
        goto after_12;
    // 0x80800640: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    after_12:
    // 0x80800644: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39AC) << 16);
    // 0x80800648: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8080064C: addiu       $a1, $a1, -0x3950
    ctx->r5 = ADD32(ctx->r5, -0X3950);
    // 0x80800650: lwc1        $f12, 0x39AC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39AC));
    // 0x80800654: jal         0x800C9DE4
    // 0x80800658: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_800C9DE4(rdram, ctx);
        goto after_13;
    // 0x80800658: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_13:
    // 0x8080065C: b           L_80800694
    // 0x80800660: addiu       $a1, $zero, 0x1561
    ctx->r5 = ADD32(0, 0X1561);
        goto L_80800694;
    // 0x80800660: addiu       $a1, $zero, 0x1561
    ctx->r5 = ADD32(0, 0X1561);
L_80800664:
    // 0x80800664: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800668: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x8080066C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800670: jal         0x800C9C34
    // 0x80800674: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    func_800C9C34(rdram, ctx);
        goto after_14;
    // 0x80800674: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    after_14:
    // 0x80800678: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39B0) << 16);
    // 0x8080067C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80800680: addiu       $a1, $a1, -0x3950
    ctx->r5 = ADD32(ctx->r5, -0X3950);
    // 0x80800684: lwc1        $f12, 0x39B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39B0));
    // 0x80800688: jal         0x800C9DE4
    // 0x8080068C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_800C9DE4(rdram, ctx);
        goto after_15;
    // 0x8080068C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_15:
    // 0x80800690: addiu       $a1, $zero, 0x14FA
    ctx->r5 = ADD32(0, 0X14FA);
L_80800694:
    // 0x80800694: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800698: jal         0x800C082C
    // 0x8080069C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800C082C(rdram, ctx);
        goto after_16;
    // 0x8080069C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_16:
    // 0x808006A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006A4: addiu       $t7, $zero, 0x97
    ctx->r15 = ADD32(0, 0X97);
    // 0x808006A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808006AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808006B0: addiu       $a2, $zero, 0x4C6
    ctx->r6 = ADD32(0, 0X4C6);
    // 0x808006B4: jal         0x8008A208
    // 0x808006B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x808006B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
    // 0x808006BC: jal         0x800C082C
    // 0x808006C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C082C(rdram, ctx);
        goto after_18;
    // 0x808006C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_18:
    // 0x808006C4: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x808006C8: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
    // 0x808006CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006D8: jr          $ra
    // 0x808006DC: nop

    return;
    // 0x808006DC: nop

;}
RECOMP_FUNC void func_800C5EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5EB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C5EBC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800C5EC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C5EC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C5EC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5ECC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C5ED0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C5ED4: beq         $t6, $zero, L_800C5EF8
    if (ctx->r14 == 0) {
        // 0x800C5ED8: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800C5EF8;
    }
    // 0x800C5ED8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C5EDC: jal         0x800AAD28
    // 0x800C5EE0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_800AAD28(rdram, ctx);
        goto after_0;
    // 0x800C5EE0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x800C5EE4: jal         0x800AAAE0
    // 0x800C5EE8: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    func_800AAAE0(rdram, ctx);
        goto after_1;
    // 0x800C5EE8: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    after_1:
    // 0x800C5EEC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x800C5EF0: jal         0x800FB508
    // 0x800C5EF4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800FB508(rdram, ctx);
        goto after_2;
    // 0x800C5EF4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_2:
L_800C5EF8:
    // 0x800C5EF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C5EFC: sb          $t7, 0x8E($s0)
    MEM_B(0X8E, ctx->r16) = ctx->r15;
    // 0x800C5F00: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C5F04: addiu       $a0, $s0, 0x64
    ctx->r4 = ADD32(ctx->r16, 0X64);
    // 0x800C5F08: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x800C5F0C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5F10: sh          $t9, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = ctx->r25;
    // 0x800C5F14: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C5F18: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x800C5F1C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800C5F20: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800C5F24: jal         0x800EE7F8
    // 0x800C5F28: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800C5F28: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800C5F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5F30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5F34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C5F38: jr          $ra
    // 0x800C5F3C: nop

    return;
    // 0x800C5F3C: nop

;}
RECOMP_FUNC void func_80028328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028328: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002832C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028330: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80028334: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80028338: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8002833C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80028340: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80028344: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80028348: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8002834C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80028350: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80028354: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80028358: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8002835C: lw          $t1, 0x20($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20);
    // 0x80028360: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80028364: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80028368: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8002836C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80028370: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80028374: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80028378: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002837C: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80028380: lw          $t7, 0x20($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X20);
    // 0x80028384: sltu        $at, $t5, $t7
    ctx->r1 = ctx->r13 < ctx->r15 ? 1 : 0;
    // 0x80028388: beq         $at, $zero, L_800283A8
    if (ctx->r1 == 0) {
        // 0x8002838C: nop
    
            goto L_800283A8;
    }
    // 0x8002838C: nop

    // 0x80028390: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80028394: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80028398: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8002839C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800283A0: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x800283A4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
L_800283A8:
    // 0x800283A8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800283AC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800283B0: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800283B4: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800283B8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800283BC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800283C0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800283C4: sltu        $at, $t1, $t7
    ctx->r1 = ctx->r9 < ctx->r15 ? 1 : 0;
    // 0x800283C8: beq         $at, $zero, L_800284B4
    if (ctx->r1 == 0) {
        // 0x800283CC: nop
    
            goto L_800284B4;
    }
    // 0x800283CC: nop

    // 0x800283D0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800283D4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800283D8: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x800283DC: sra         $t8, $t4, 1
    ctx->r24 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800283E0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800283E4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800283E8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800283EC: subu        $t0, $t6, $t9
    ctx->r8 = SUB32(ctx->r14, ctx->r25);
    // 0x800283F0: sra         $t5, $t0, 1
    ctx->r13 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800283F4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800283F8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800283FC: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x80028400: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80028404: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80028408: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002840C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80028410: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80028414: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x80028418: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x8002841C: sll         $t8, $t4, 12
    ctx->r24 = S32(ctx->r12 << 12);
    // 0x80028420: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80028424: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80028428: andi        $t0, $t9, 0xFFF
    ctx->r8 = ctx->r25 & 0XFFF;
    // 0x8002842C: or          $t5, $t6, $t0
    ctx->r13 = ctx->r14 | ctx->r8;
    // 0x80028430: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80028434: jal         0x8002E330
    // 0x80028438: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80028438: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x8002843C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80028440: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x80028444: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80028448: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x8002844C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80028450: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80028454: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80028458: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002845C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80028460: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80028464: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x80028468: andi        $t1, $t7, 0xFFF
    ctx->r9 = ctx->r15 & 0XFFF;
    // 0x8002846C: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x80028470: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80028474: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x80028478: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002847C: or          $t2, $t3, $at
    ctx->r10 = ctx->r11 | ctx->r1;
    // 0x80028480: andi        $t0, $t6, 0xFFF
    ctx->r8 = ctx->r14 & 0XFFF;
    // 0x80028484: or          $t8, $t2, $t0
    ctx->r24 = ctx->r10 | ctx->r8;
    // 0x80028488: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8002848C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80028490: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80028494: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80028498: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x8002849C: jal         0x8002E330
    // 0x800284A0: lw          $a0, 0x20($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X20);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800284A0: lw          $a0, 0x20($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X20);
    after_1:
    // 0x800284A4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800284A8: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x800284AC: b           L_80028500
    // 0x800284B0: nop

        goto L_80028500;
    // 0x800284B0: nop

L_800284B4:
    // 0x800284B4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800284B8: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800284BC: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x800284C0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800284C4: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800284C8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800284CC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800284D0: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x800284D4: andi        $t4, $t8, 0xFFF
    ctx->r12 = ctx->r24 & 0XFFF;
    // 0x800284D8: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x800284DC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800284E0: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800284E4: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x800284E8: or          $t1, $t9, $t7
    ctx->r9 = ctx->r25 | ctx->r15;
    // 0x800284EC: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800284F0: jal         0x8002E330
    // 0x800284F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800284F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800284F8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800284FC: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
L_80028500:
    // 0x80028500: b           L_80028510
    // 0x80028504: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
        goto L_80028510;
    // 0x80028504: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80028508: b           L_80028510
    // 0x8002850C: nop

        goto L_80028510;
    // 0x8002850C: nop

L_80028510:
    // 0x80028510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028514: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80028518: jr          $ra
    // 0x8002851C: nop

    return;
    // 0x8002851C: nop

;}
RECOMP_FUNC void func_8009375C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009375C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80093760: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80093764: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80093768: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8009376C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80093770: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80093774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093778: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x8009377C: beq         $a2, $zero, L_80093798
    if (ctx->r6 == 0) {
        // 0x80093780: sw          $t8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r24;
            goto L_80093798;
    }
    // 0x80093780: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80093784: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80093788: beq         $a2, $at, L_800937D8
    if (ctx->r6 == ctx->r1) {
        // 0x8009378C: nop
    
            goto L_800937D8;
    }
    // 0x8009378C: nop

    // 0x80093790: b           L_80093814
    // 0x80093794: nop

        goto L_80093814;
    // 0x80093794: nop

L_80093798:
    // 0x80093798: jal         0x80092B04
    // 0x8009379C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092B04(rdram, ctx);
        goto after_0;
    // 0x8009379C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800937A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800937A4: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x800937A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800937AC: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800937B0: jal         0x8008CABC
    // 0x800937B4: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x800937B4: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
    after_1:
    // 0x800937B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800937BC: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x800937C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800937C4: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
    // 0x800937C8: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    // 0x800937CC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800937D0: b           L_80093814
    // 0x800937D4: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
        goto L_80093814;
    // 0x800937D4: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
L_800937D8:
    // 0x800937D8: jal         0x80093738
    // 0x800937DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80093738(rdram, ctx);
        goto after_2;
    // 0x800937DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800937E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800937E4: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x800937E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800937EC: lh          $t6, 0x90($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X90);
    // 0x800937F0: jal         0x8008D04C
    // 0x800937F4: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    func_8008D04C(rdram, ctx);
        goto after_3;
    // 0x800937F4: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    after_3:
    // 0x800937F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800937FC: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80093800: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80093804: sb          $t7, 0xA1($t8)
    MEM_B(0XA1, ctx->r24) = ctx->r15;
    // 0x80093808: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    // 0x8009380C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80093810: sw          $t9, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r25;
L_80093814:
    // 0x80093814: jal         0x800B27E0
    // 0x80093818: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800B27E0(rdram, ctx);
        goto after_4;
    // 0x80093818: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8009381C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80093820: jal         0x8008AEDC
    // 0x80093824: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008AEDC(rdram, ctx);
        goto after_5;
    // 0x80093824: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80093828: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    // 0x8009382C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80093830: jal         0x8008C200
    // 0x80093834: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_8008C200(rdram, ctx);
        goto after_6;
    // 0x80093834: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x80093838: jal         0x800AE080
    // 0x8009383C: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    func_800AE080(rdram, ctx);
        goto after_7;
    // 0x8009383C: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    after_7:
    // 0x80093840: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80093844: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80093848: jal         0x800AE598
    // 0x8009384C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800AE598(rdram, ctx);
        goto after_8;
    // 0x8009384C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_8:
    // 0x80093850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093854: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80093858: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009385C: jr          $ra
    // 0x80093860: nop

    return;
    // 0x80093860: nop

;}
RECOMP_FUNC void func_8009E674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E67C: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E680: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8009E684: jal         0x8009CA70
    // 0x8009E688: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    func_8009CA70(rdram, ctx);
        goto after_0;
    // 0x8009E688: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    after_0:
    // 0x8009E68C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E694: jr          $ra
    // 0x8009E698: nop

    return;
    // 0x8009E698: nop

;}
RECOMP_FUNC void func_808007FC_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800804: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800808: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080080C: jal         0x80100094
    // 0x80800810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800814: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80800818: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8080081C: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x80800820: bne         $t6, $zero, L_80800868
    if (ctx->r14 != 0) {
        // 0x80800824: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800868;
    }
    // 0x80800824: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800828: jal         0x80101808
    // 0x8080082C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80101808(rdram, ctx);
        goto after_1;
    // 0x8080082C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800830: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800834: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800838: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x8080083C: beql        $t7, $zero, L_8080086C
    if (ctx->r15 == 0) {
        // 0x80800840: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080086C;
    }
    goto skip_0;
    // 0x80800840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800844: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x80800848: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8080084C: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x80800850: bgezl       $t1, L_8080086C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800854: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080086C;
    }
    goto skip_1;
    // 0x80800854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800858: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8080085C: addiu       $a2, $v1, 0x4
    ctx->r6 = ADD32(ctx->r3, 0X4);
    // 0x80800860: jal         0x800DBEFC
    // 0x80800864: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x80800864: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    after_2:
L_80800868:
    // 0x80800868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080086C:
    // 0x8080086C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800870: jr          $ra
    // 0x80800874: nop

    return;
    // 0x80800874: nop

;}
RECOMP_FUNC void func_80801488_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080148C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801490: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801494: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80801498: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080149C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808014A0: nop

    // 0x808014A4: bc1fl       L_80801504
    if (!c1cs) {
        // 0x808014A8: lw          $v1, 0x30($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X30);
            goto L_80801504;
    }
    goto skip_0;
    // 0x808014A8: lw          $v1, 0x30($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X30);
    skip_0:
    // 0x808014AC: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    // 0x808014B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808014B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808014B8: bnel        $v1, $zero, L_808014E0
    if (ctx->r3 != 0) {
        // 0x808014BC: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_808014E0;
    }
    goto skip_1;
    // 0x808014BC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_1:
    // 0x808014C0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808014C4: jal         0x800E15CC
    // 0x808014C8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800E15CC(rdram, ctx);
        goto after_0;
    // 0x808014C8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x808014CC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808014D0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x808014D4: sw          $v1, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r3;
    // 0x808014D8: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x808014DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_808014E0:
    // 0x808014E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808014E4: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x808014E8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808014EC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808014F0: jal         0x800E13F0
    // 0x808014F4: nop

    func_800E13F0(rdram, ctx);
        goto after_1;
    // 0x808014F4: nop

    after_1:
    // 0x808014F8: b           L_80801520
    // 0x808014FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801520;
    // 0x808014FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801500: lw          $v1, 0x30($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X30);
L_80801504:
    // 0x80801504: beq         $v1, $zero, L_8080151C
    if (ctx->r3 == 0) {
        // 0x80801508: addiu       $a0, $v1, -0x1
        ctx->r4 = ADD32(ctx->r3, -0X1);
            goto L_8080151C;
    }
    // 0x80801508: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x8080150C: jal         0x800E1720
    // 0x80801510: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800E1720(rdram, ctx);
        goto after_2;
    // 0x80801510: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x80801514: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801518: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
L_8080151C:
    // 0x8080151C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801520:
    // 0x80801520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801524: jr          $ra
    // 0x80801528: nop

    return;
    // 0x80801528: nop

    // 0x8080152C: nop

;}
RECOMP_FUNC void func_808010E0_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010E8: lh          $t6, 0x238($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X238);
    // 0x808010EC: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x808010F0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x808010F4: bnel        $t6, $zero, L_80801108
    if (ctx->r14 != 0) {
        // 0x808010F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801108;
    }
    goto skip_0;
    // 0x808010F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808010FC: jal         0x80088410
    // 0x80801100: lh          $a0, 0x1DC($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X1DC);
    _gczoomboxdata_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801100: lh          $a0, 0x1DC($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X1DC);
    after_0:
    // 0x80801104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801108:
    // 0x80801108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080110C: jr          $ra
    // 0x80801110: nop

    return;
    // 0x80801110: nop

;}
RECOMP_FUNC void chfootwear_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2448, 0X8A8) << 16);
    // 0x808006B8: jr          $ra
    // 0x808006BC: addiu       $v0, $v0, 0x8A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2448, 0X8A8));
    return;
    // 0x808006BC: addiu       $v0, $v0, 0x8A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2448, 0X8A8));
;}
RECOMP_FUNC void func_800E9D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9D68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9D6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E9D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9D74: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9D78: jal         0x800B42A0
    // 0x800E9D7C: lw          $a0, 0x2DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB0);
    func_800B42A0(rdram, ctx);
        goto after_0;
    // 0x800E9D7C: lw          $a0, 0x2DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB0);
    after_0:
    // 0x800E9D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9D84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9D88: jr          $ra
    // 0x800E9D8C: nop

    return;
    // 0x800E9D8C: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x808004C4: jr          $ra
    // 0x808004C8: lh          $v0, 0x75EA($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X75EA);
    return;
    // 0x808004C8: lh          $v0, 0x75EA($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X75EA);
;}
RECOMP_FUNC void _chpiranha_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DD8: syscall     458
    recomp_syscall_handler(rdram, ctx, 0x80086DD8);
    return;
    // 0x80086DDC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsmummove_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838A8: syscall     78
    recomp_syscall_handler(rdram, ctx, 0x800838A8);
    return;
    // 0x800838AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800C1448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1448: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800C144C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C1450: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800C1454: jr          $ra
    // 0x800C1458: lw          $v0, -0x74F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74F8);
    return;
    // 0x800C1458: lw          $v0, -0x74F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74F8);
;}
RECOMP_FUNC void chbadshad_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800518: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8080051C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800524: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800528: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
    // 0x8080052C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80800530: beql        $t0, $v0, L_80800578
    if (ctx->r8 == ctx->r2) {
        // 0x80800534: mfc1        $a2, $f12
        ctx->r6 = (int32_t)ctx->f12.u32l;
            goto L_80800578;
    }
    goto skip_0;
    // 0x80800534: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    skip_0:
    // 0x80800538: lhu         $v1, 0x72($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X72);
    // 0x8080053C: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800540: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80800544:
    // 0x80800544: bnel        $v1, $v0, L_80800568
    if (ctx->r3 != ctx->r2) {
        // 0x80800548: lh          $v0, 0x2($a3)
        ctx->r2 = MEM_H(ctx->r7, 0X2);
            goto L_80800568;
    }
    goto skip_1;
    // 0x80800548: lh          $v0, 0x2($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X2);
    skip_1:
    // 0x8080054C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80800550: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800554: jal         0x80800490
    // 0x80800558: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    chbadshad_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800558: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8080055C: b           L_80800584
    // 0x80800560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800584;
    // 0x80800560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800564: lh          $v0, 0x2($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X2);
L_80800568:
    // 0x80800568: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8080056C: bne         $t0, $v0, L_80800544
    if (ctx->r8 != ctx->r2) {
        // 0x80800570: nop
    
            goto L_80800544;
    }
    // 0x80800570: nop

    // 0x80800574: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
L_80800578:
    // 0x80800578: jal         0x80800464
    // 0x8080057C: nop

    chbadshad_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080057C: nop

    after_1:
    // 0x80800580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800584:
    // 0x80800584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800588: jr          $ra
    // 0x8080058C: nop

    return;
    // 0x8080058C: nop

;}
RECOMP_FUNC void func_800E1294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E1298: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800E129C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800E12A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E12A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E12A8: beq         $a0, $zero, L_800E12F0
    if (ctx->r4 == 0) {
        // 0x800E12AC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800E12F0;
    }
    // 0x800E12AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800E12B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E12B4: beq         $a0, $at, L_800E12DC
    if (ctx->r4 == ctx->r1) {
        // 0x800E12B8: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_800E12DC;
    }
    // 0x800E12B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800E12BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E12C0: beq         $a0, $at, L_800E1308
    if (ctx->r4 == ctx->r1) {
        // 0x800E12C4: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_800E1308;
    }
    // 0x800E12C4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800E12C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E12CC: beql        $a0, $at, L_800E1320
    if (ctx->r4 == ctx->r1) {
        // 0x800E12D0: lwc1        $f4, 0x4($a3)
        ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
            goto L_800E1320;
    }
    goto skip_0;
    // 0x800E12D0: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    skip_0:
    // 0x800E12D4: b           L_800E132C
    // 0x800E12D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E132C;
    // 0x800E12D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E12DC:
    // 0x800E12DC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800E12E0: jal         0x800E1218
    // 0x800E12E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800E1218(rdram, ctx);
        goto after_0;
    // 0x800E12E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800E12E8: b           L_800E132C
    // 0x800E12EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E132C;
    // 0x800E12EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E12F0:
    // 0x800E12F0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800E12F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800E12F8: jal         0x800E1120
    // 0x800E12FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800E1120(rdram, ctx);
        goto after_1;
    // 0x800E12FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800E1300: b           L_800E132C
    // 0x800E1304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E132C;
    // 0x800E1304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E1308:
    // 0x800E1308: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800E130C: jal         0x800E119C
    // 0x800E1310: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800E119C(rdram, ctx);
        goto after_2;
    // 0x800E1310: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x800E1314: b           L_800E132C
    // 0x800E1318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E132C;
    // 0x800E1318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E131C: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
L_800E1320:
    // 0x800E1320: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800E1324: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
    // 0x800E1328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E132C:
    // 0x800E132C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E1330: jr          $ra
    // 0x800E1334: nop

    return;
    // 0x800E1334: nop

;}
RECOMP_FUNC void func_80801ADC_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801AE0: beq         $a0, $zero, L_80801B04
    if (ctx->r4 == 0) {
        // 0x80801AE4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80801B04;
    }
    // 0x80801AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801AE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801AEC: beq         $a0, $at, L_80801B24
    if (ctx->r4 == ctx->r1) {
        // 0x80801AF0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801B24;
    }
    // 0x80801AF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801AF4: beql        $a0, $at, L_80801B48
    if (ctx->r4 == ctx->r1) {
        // 0x80801AF8: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_80801B48;
    }
    goto skip_0;
    // 0x80801AF8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    skip_0:
    // 0x80801AFC: b           L_80801B64
    // 0x80801B00: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
        goto L_80801B64;
    // 0x80801B00: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_80801B04:
    // 0x80801B04: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80801B08: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801B0C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80801B10: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801B14: jal         0x800DC178
    // 0x80801B18: swc1        $f14, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f14.u32l;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80801B18: swc1        $f14, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f14.u32l;
    after_0:
    // 0x80801B1C: b           L_80801B70
    // 0x80801B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B70;
    // 0x80801B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B24:
    // 0x80801B24: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80801B28: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801B2C: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80801B30: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801B34: jal         0x800DC178
    // 0x80801B38: swc1        $f14, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f14.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80801B38: swc1        $f14, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f14.u32l;
    after_1:
    // 0x80801B3C: b           L_80801B70
    // 0x80801B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B70;
    // 0x80801B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B44: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
L_80801B48:
    // 0x80801B48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801B4C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801B50: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801B54: jal         0x800DC178
    // 0x80801B58: swc1        $f14, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f14.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801B58: swc1        $f14, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f14.u32l;
    after_2:
    // 0x80801B5C: b           L_80801B70
    // 0x80801B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B70;
    // 0x80801B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B64:
    // 0x80801B64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801B68: nop

    // 0x80801B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B70:
    // 0x80801B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B74: jr          $ra
    // 0x80801B78: nop

    return;
    // 0x80801B78: nop

;}
RECOMP_FUNC void func_8080002C_chdiggerbossinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800030: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800038: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080003C: addiu       $a0, $zero, 0xA4F
    ctx->r4 = ADD32(0, 0XA4F);
    // 0x80800040: jal         0x800DA980
    // 0x80800044: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA980(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800048: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080004C: subu        $a1, $t6, $v0
    ctx->r5 = SUB32(ctx->r14, ctx->r2);
    // 0x80800050: addiu       $a0, $zero, 0x10B
    ctx->r4 = ADD32(0, 0X10B);
    // 0x80800054: jal         0x800D2498
    // 0x80800058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_1;
    // 0x80800058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080005C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1504, 0X278) << 16);
    // 0x80800060: addiu       $a3, $a3, 0x278
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1504, 0X278));
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080006C: jal         0x80089D50
    // 0x80800070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80800074: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80800078: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080007C: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800080: bnel        $t8, $at, L_808000E4
    if (ctx->r24 != ctx->r1) {
        // 0x80800084: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000E4;
    }
    goto skip_0;
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800088: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x8080008C: srl         $v1, $v0, 4
    ctx->r3 = S32(U32(ctx->r2) >> 4);
    // 0x80800090: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80800094: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80800098: andi        $t2, $v0, 0xFF0F
    ctx->r10 = ctx->r2 & 0XFF0F;
    // 0x8080009C: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x808000A0: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x808000A4: beq         $a0, $zero, L_808000E0
    if (ctx->r4 == 0) {
        // 0x808000A8: sb          $t3, 0x79($s0)
        MEM_B(0X79, ctx->r16) = ctx->r11;
            goto L_808000E0;
    }
    // 0x808000A8: sb          $t3, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r11;
    // 0x808000AC: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x808000B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80089C30
    // 0x808000B8: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808000B8: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    after_3:
    // 0x808000BC: beq         $v0, $zero, L_808000E0
    if (ctx->r2 == 0) {
        // 0x808000C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000E0;
    }
    // 0x808000C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_808000C4:
    // 0x808000C4: jal         0x8008A120
    // 0x808000C8: nop

    _sucoaster_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x808000C8: nop

    after_4:
    // 0x808000CC: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x808000D0: jal         0x80089C38
    // 0x808000D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808000D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x808000D8: bne         $v0, $zero, L_808000C4
    if (ctx->r2 != 0) {
        // 0x808000DC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000C4;
    }
    // 0x808000DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_808000E0:
    // 0x808000E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000E4:
    // 0x808000E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void func_8010FE14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FE14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010FE18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010FE1C: jal         0x800CA628
    // 0x8010FE20: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800CA628(rdram, ctx);
        goto after_0;
    // 0x8010FE20: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8010FE24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010FE28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010FE2C: jr          $ra
    // 0x8010FE30: nop

    return;
    // 0x8010FE30: nop

;}
RECOMP_FUNC void func_80800000_chpodiumbankaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800C6E38
    // 0x80800010: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x80800014: beq         $v0, $zero, L_8080002C
    if (ctx->r2 == 0) {
        // 0x80800018: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080002C;
    }
    // 0x80800018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: jal         0x80089C98
    // 0x80800020: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_1:
    // 0x80800024: b           L_80800038
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800038;
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080002C:
    // 0x8080002C: jal         0x80089C98
    // 0x80800030: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800030: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    after_2:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800038:
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void _chdinofamilysmall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876E0: syscall     609
    recomp_syscall_handler(rdram, ctx, 0x800876E0);
    return;
    // 0x800876E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_41(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D28: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083D28);
    return;
    // 0x80083D2C: addi        $t0, $zero, 0xA4
    ctx->r8 = ADD32(0, 0XA4);
;}
RECOMP_FUNC void _chjigsawcollect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867B0: syscall     376
    recomp_syscall_handler(rdram, ctx, 0x800867B0);
    return;
    // 0x800867B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gclevel_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080010C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800110: jal         0x80088268
    // 0x80800114: nop

    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800114: nop

    after_0:
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080011C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80800120: addiu       $v1, $v1, 0x762C
    ctx->r3 = ADD32(ctx->r3, 0X762C);
    // 0x80800124: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80800128: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8080012C: jr          $ra
    // 0x80800130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801B84_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801B88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801B94: sb          $zero, 0x167($a0)
    MEM_B(0X167, ctx->r4) = 0;
    // 0x80801B98: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x80801B9C: jal         0x8008CB3C
    // 0x80801BA0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80801BA0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_0:
    // 0x80801BA4: jal         0x80800000
    // 0x80801BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbswim(rdram, ctx);
        goto after_1;
    // 0x80801BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BB0: jal         0x8009B94C
    // 0x80801BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_2;
    // 0x80801BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BBC: jal         0x800852B0
    // 0x80801BC0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _baswim_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80801BC0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80801BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BC8: jal         0x8009BA9C
    // 0x80801BCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x80801BCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801BD0: jal         0x80800030
    // 0x80801BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_5;
    // 0x80801BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BDC: jal         0x80085298
    // 0x80801BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baswim_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x80801BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80801BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BE8: jal         0x80091104
    // 0x80801BEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80091104(rdram, ctx);
        goto after_7;
    // 0x80801BEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80801BF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801BF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801BF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801BFC: jr          $ra
    // 0x80801C00: nop

    return;
    // 0x80801C00: nop

;}
RECOMP_FUNC void babuzz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002AC: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x808002B0: jr          $ra
    // 0x808002B4: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808002B4: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void batranslate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
;}
RECOMP_FUNC void bsvanswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800828: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080082C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(431, 0X9A0) << 16);
    // 0x80800830: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800834: jr          $ra
    // 0x80800838: lw          $v0, 0x9A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(431, 0X9A0));
    return;
    // 0x80800838: lw          $v0, 0x9A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(431, 0X9A0));
;}
RECOMP_FUNC void func_800C28D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C28D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C28DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C28E0: jal         0x800C157C
    // 0x800C28E4: nop

    func_800C157C(rdram, ctx);
        goto after_0;
    // 0x800C28E4: nop

    after_0:
    // 0x800C28E8: jal         0x800C13E4
    // 0x800C28EC: nop

    func_800C13E4(rdram, ctx);
        goto after_1;
    // 0x800C28EC: nop

    after_1:
    // 0x800C28F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C28F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C28F8: jr          $ra
    // 0x800C28FC: nop

    return;
    // 0x800C28FC: nop

;}
RECOMP_FUNC void _badrone_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848F0: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848F0);
    return;
    // 0x800848F4: addi        $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
;}
RECOMP_FUNC void func_8001E44C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E44C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E454: jal         0x8001D96C
    // 0x8001E458: nop

    func_8001D96C(rdram, ctx);
        goto after_0;
    // 0x8001E458: nop

    after_0:
    // 0x8001E45C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8001E460: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001E464: lw          $a3, -0x16B0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X16B0);
    // 0x8001E468: addiu       $a2, $a2, 0x18FC
    ctx->r6 = ADD32(ctx->r6, 0X18FC);
    // 0x8001E46C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8001E470: jal         0x8001D3D8
    // 0x8001E474: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_8001D3D8(rdram, ctx);
        goto after_1;
    // 0x8001E474: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_1:
    // 0x8001E478: jal         0x8001E2A0
    // 0x8001E47C: nop

    func_8001E2A0(rdram, ctx);
        goto after_2;
    // 0x8001E47C: nop

    after_2:
    // 0x8001E480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E488: jr          $ra
    // 0x8001E48C: nop

    return;
    // 0x8001E48C: nop

;}
RECOMP_FUNC void _idwave_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D30: syscall     736
    recomp_syscall_handler(rdram, ctx, 0x80088D30);
    return;
    // 0x80088D34: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808085E0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808085E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808085E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808085E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808085EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808085F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808085F4: jal         0x80100094
    // 0x808085F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808085F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808085FC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80808600: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80808604: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80808608: bne         $t6, $at, L_80808694
    if (ctx->r14 != ctx->r1) {
        // 0x8080860C: addiu       $a0, $zero, 0x4F6
        ctx->r4 = ADD32(0, 0X4F6);
            goto L_80808694;
    }
    // 0x8080860C: addiu       $a0, $zero, 0x4F6
    ctx->r4 = ADD32(0, 0X4F6);
    // 0x80808610: jal         0x801084B0
    // 0x80808614: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x80808614: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80808618: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080861C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80808620: sw          $t7, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->r15;
    // 0x80808624: jal         0x808087F0
    // 0x80808628: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808087F0_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80808628: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8080862C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80808630: jal         0x80802170
    // 0x80808634: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80802170_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80808634: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
    // 0x80808638: bne         $v0, $zero, L_80808668
    if (ctx->r2 != 0) {
        // 0x8080863C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80808668;
    }
    // 0x8080863C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80808640: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80808644: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80808648: jal         0x80102FDC
    // 0x8080864C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80102FDC(rdram, ctx);
        goto after_4;
    // 0x8080864C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80808650: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80808654: jal         0x80800180
    // 0x80808658: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80808658: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x8080865C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80808660: b           L_80808694
    // 0x80808664: sb          $t8, 0xCC($s0)
    MEM_B(0XCC, ctx->r16) = ctx->r24;
        goto L_80808694;
    // 0x80808664: sb          $t8, 0xCC($s0)
    MEM_B(0XCC, ctx->r16) = ctx->r24;
L_80808668:
    // 0x80808668: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x8080866C: jal         0x80102FDC
    // 0x80808670: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80102FDC(rdram, ctx);
        goto after_6;
    // 0x80808670: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_6:
    // 0x80808674: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80808678: jal         0x80800180
    // 0x8080867C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x8080867C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_7:
    // 0x80808680: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80808684: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80808688: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8080868C: sb          $t9, 0xCC($s0)
    MEM_B(0XCC, ctx->r16) = ctx->r25;
    // 0x80808690: swc1        $f4, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f4.u32l;
L_80808694:
    // 0x80808694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80808698: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080869C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808086A0: jr          $ra
    // 0x808086A4: nop

    return;
    // 0x808086A4: nop

;}
RECOMP_FUNC void func_80800640_charmouredcaveman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800640: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800644: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800648: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080064C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800650: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800654: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1116, 0XBA4) << 16);
    // 0x80800658: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1116, 0XBBC) << 16);
    // 0x8080065C: addiu       $a3, $a3, 0xBBC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1116, 0XBBC));
    // 0x80800660: addiu       $a2, $a2, 0xBA4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1116, 0XBA4));
    // 0x80800664: jal         0x80089D28
    // 0x80800668: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800668: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080066C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1116, 0XBB0) << 16);
    // 0x80800670: lui         $a3, 0x3F54
    ctx->r7 = S32(0X3F54 << 16);
    // 0x80800674: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800678: ori         $a3, $a3, 0x7AE1
    ctx->r7 = ctx->r7 | 0X7AE1;
    // 0x8080067C: addiu       $a2, $a2, 0xBB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1116, 0XBB0));
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: jal         0x80089D20
    // 0x80800688: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800688: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8080068C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80800690: beql        $t6, $zero, L_8080071C
    if (ctx->r14 == 0) {
        // 0x80800694: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080071C;
    }
    goto skip_0;
    // 0x80800694: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800698: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x8080069C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808006A0: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x808006A4: bgezl       $t9, L_8080071C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808006A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080071C;
    }
    goto skip_1;
    // 0x808006A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808006AC: jal         0x800EE7F8
    // 0x808006B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808006B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808006B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808006B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006BC: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808006C0: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808006C4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808006C8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808006CC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808006D0: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x808006D4: jal         0x800EE7F8
    // 0x808006D8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808006D8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x808006DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808006E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006E4: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808006E8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808006EC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1116, 0XB78) << 16);
    // 0x808006F0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808006F4: addiu       $t0, $t0, 0xB78
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1116, 0XB78));
    // 0x808006F8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808006FC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800700: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800704: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800708: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8080070C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80800710: jal         0x800BBCB8
    // 0x80800714: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x80800714: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80800718: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080071C:
    // 0x8080071C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800720: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800724: jr          $ra
    // 0x80800728: nop

    return;
    // 0x80800728: nop

;}
RECOMP_FUNC void _sccustom_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A648: syscall     846
    recomp_syscall_handler(rdram, ctx, 0x8008A648);
    return;
    // 0x8008A64C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void fxstep_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080061C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800620: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800624: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800628: jal         0x80800344
    // 0x8080062C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800344_fxstep(rdram, ctx);
        goto after_0;
    // 0x8080062C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80800630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800638: jr          $ra
    // 0x8080063C: nop

    return;
    // 0x8080063C: nop

;}
RECOMP_FUNC void boot___osSiDeviceBusy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
