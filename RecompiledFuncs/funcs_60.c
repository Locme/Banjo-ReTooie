#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chfantasybounce_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(820, 0XA8) << 16);
    // 0x8080004C: jr          $ra
    // 0x80800050: addiu       $v0, $v0, 0xA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(820, 0XA8));
    return;
    // 0x80800050: addiu       $v0, $v0, 0xA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(820, 0XA8));
    // 0x80800054: nop

    // 0x80800058: nop

    // 0x8080005C: nop

;}
RECOMP_FUNC void func_8080009C_bsdronegoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A4: jal         0x800A3274
    // 0x808000A8: nop

    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x808000A8: nop

    after_0:
    // 0x808000AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B0: xori        $t6, $v0, 0x12
    ctx->r14 = ctx->r2 ^ 0X12;
    // 0x808000B4: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808000BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _idflashbaddie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DC8: syscall     741
    recomp_syscall_handler(rdram, ctx, 0x80088DC8);
    return;
    // 0x80088DCC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bstaxi_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808015F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(392, 0X21D8) << 16);
    // 0x808015F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808015F8: jr          $ra
    // 0x808015FC: lw          $v0, 0x21D8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21D8));
    return;
    // 0x808015FC: lw          $v0, 0x21D8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21D8));
;}
RECOMP_FUNC void func_80801358_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801358: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080135C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801360: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801364: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801368: jal         0x80106790
    // 0x8080136C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080136C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80801370: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80801374: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80801378: jal         0x80800A90
    // 0x8080137C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800A90_chfishshootgame(rdram, ctx);
        goto after_1;
    // 0x8080137C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801380: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801384: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801388: jal         0x800F18FC
    // 0x8080138C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800F18FC(rdram, ctx);
        goto after_2;
    // 0x8080138C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80801390: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801394: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80801398: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080139C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x808013A0: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x808013A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808013A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808013AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808013B0: jr          $ra
    // 0x808013B4: nop

    return;
    // 0x808013B4: nop

;}
RECOMP_FUNC void func_800139F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800139F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800139FC: lwc1        $f14, 0x16FC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16FC);
    // 0x80013A00: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80013A04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80013A08: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
    // 0x80013A0C: jal         0x80013818
    // 0x80013A10: nop

    func_80013818(rdram, ctx);
        goto after_0;
    // 0x80013A10: nop

    after_0:
    // 0x80013A14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80013A18: or          $ra, $a3, $zero
    ctx->r31 = ctx->r7 | 0;
    // 0x80013A1C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80013A20: bc1t        L_80013A30
    if (c1cs) {
        // 0x80013A24: nop
    
            goto L_80013A30;
    }
    // 0x80013A24: nop

    // 0x80013A28: jr          $ra
    // 0x80013A2C: div.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    return;
    // 0x80013A2C: div.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
L_80013A30:
    // 0x80013A30: c.olt.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80013A34: bc1tl       L_80013A50
    if (c1cs) {
        // 0x80013A38: lui         $t0, 0xFF00
        ctx->r8 = S32(0XFF00 << 16);
            goto L_80013A50;
    }
    goto skip_0;
    // 0x80013A38: lui         $t0, 0xFF00
    ctx->r8 = S32(0XFF00 << 16);
    skip_0:
    // 0x80013A3C: lui         $t0, 0x7F00
    ctx->r8 = S32(0X7F00 << 16);
    // 0x80013A40: mtc1        $t0, $f0
    ctx->f0.u32l = ctx->r8;
    // 0x80013A44: jr          $ra
    // 0x80013A48: nop

    return;
    // 0x80013A48: nop

    // 0x80013A4C: lui         $t0, 0xFF00
    ctx->r8 = S32(0XFF00 << 16);
L_80013A50:
    // 0x80013A50: mtc1        $t0, $f0
    ctx->f0.u32l = ctx->r8;
    // 0x80013A54: jr          $ra
    // 0x80013A58: nop

    return;
    // 0x80013A58: nop

;}
RECOMP_FUNC void func_80800000_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lui         $a1, 0xC48C
    ctx->r5 = S32(0XC48C << 16);
    // 0x80800010: lui         $a2, 0x460C
    ctx->r6 = S32(0X460C << 16);
    // 0x80800014: lui         $a3, 0x44C7
    ctx->r7 = S32(0X44C7 << 16);
    // 0x80800018: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8080001C: ori         $a2, $a2, 0xA800
    ctx->r6 = ctx->r6 | 0XA800;
    // 0x80800020: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800024: jal         0x800EFA4C
    // 0x80800028: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_80800398_chLagoonInnBlockedWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080039C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808003A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003A4: bne         $a1, $at, L_808003BC
    if (ctx->r5 != ctx->r1) {
        // 0x808003A8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808003BC;
    }
    // 0x808003A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003AC: jal         0x8080025C
    // 0x808003B0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8080025C_chLagoonInnBlockedWall(rdram, ctx);
        goto after_0;
    // 0x808003B0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808003B4: b           L_808003C0
    // 0x808003B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003C0;
    // 0x808003B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003BC:
    // 0x808003BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003C0:
    // 0x808003C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003C8: jr          $ra
    // 0x808003CC: nop

    return;
    // 0x808003CC: nop

;}
RECOMP_FUNC void func_8080019C_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808001A4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808001A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808001AC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808001B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808001B8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x808001BC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x808001C0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x808001C4: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x808001C8: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x808001CC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x808001D0: addiu       $a0, $a0, -0x5A88
    ctx->r4 = ADD32(ctx->r4, -0X5A88);
    // 0x808001D4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808001D8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x808001DC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808001E0: jal         0x80086D58
    // 0x808001E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x808001E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x808001E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void func_80800084_chdinofoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080008C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800090: jal         0x800F54E4
    // 0x80800094: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800094: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800098: jal         0x800F6438
    // 0x8080009C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x8080009C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000A0: beql        $v0, $zero, L_808000D0
    if (ctx->r2 == 0) {
        // 0x808000A4: lhu         $t6, 0x72($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X72);
            goto L_808000D0;
    }
    goto skip_0;
    // 0x808000A4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x808000A8: jal         0x800F54E4
    // 0x808000AC: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808000AC: nop

    after_2:
    // 0x808000B0: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808000B4: ori         $a2, $a2, 0xCC00
    ctx->r6 = ctx->r6 | 0XCC00;
    // 0x808000B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000BC: jal         0x8010D09C
    // 0x808000C0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_8010D09C(rdram, ctx);
        goto after_3;
    // 0x808000C0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x808000C4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808000C8: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x808000CC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_808000D0:
    // 0x808000D0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000D4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000D8: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x808000DC: beq         $at, $zero, L_80800248
    if (ctx->r1 == 0) {
        // 0x808000E0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800248;
    }
    // 0x808000E0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1040, 0X7A4) << 16);
    // 0x808000E8: addu        $at, $at, $t8
    gpr jr_addend_808000F0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000EC: lw          $t8, 0x7A4($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1040, 0X7A4));
    // 0x808000F0: jr          $t8
    // 0x808000F4: nop

    switch (jr_addend_808000F0 >> 2) {
        case 0: goto L_808000F8; break;
        case 1: goto L_80800138; break;
        case 2: goto L_80800174; break;
        case 3: goto L_808001AC; break;
        case 4: goto L_808001FC; break;
        case 5: goto L_8080021C; break;
        default: switch_error(__func__, 0x808000F0, 0x808007A4);
    }
    // 0x808000F4: nop

L_808000F8:
    // 0x808000F8: jal         0x80800480
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800480_chdinofoot(rdram, ctx);
        goto after_4;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800100: bne         $v0, $zero, L_80800248
    if (ctx->r2 != 0) {
        // 0x80800104: nop
    
            goto L_80800248;
    }
    // 0x80800104: nop

    // 0x80800108: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x8080010C: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x80800110: bltz        $t1, L_80800248
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800114: nop
    
            goto L_80800248;
    }
    // 0x80800114: nop

    // 0x80800118: jal         0x800D90A4
    // 0x8080011C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_5;
    // 0x8080011C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_5:
    // 0x80800120: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800248;
    }
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x80102424
    // 0x8080012C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x8080012C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800130: b           L_80800248
    // 0x80800134: nop

        goto L_80800248;
    // 0x80800134: nop

L_80800138:
    // 0x80800138: jal         0x800D90A4
    // 0x8080013C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x8080013C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_7:
    // 0x80800140: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800144: addiu       $a0, $zero, 0x18B9
        ctx->r4 = ADD32(0, 0X18B9);
            goto L_80800248;
    }
    // 0x80800144: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x80800148: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080014C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800150: jal         0x800861A0
    // 0x80800154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80102424
    // 0x80800160: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800160: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800164: jal         0x8010A590
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_10;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080016C: b           L_80800248
    // 0x80800170: nop

        goto L_80800248;
    // 0x80800170: nop

L_80800174:
    // 0x80800174: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800178: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x8080017C: bltzl       $t4, L_80800194
    if (SIGNED(ctx->r12) < 0) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800194;
    }
    goto skip_1;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800184: jal         0x8080055C
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080055C_chdinofoot(rdram, ctx);
        goto after_11;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080018C: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800190: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800248;
    }
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800194:
    // 0x80800194: jal         0x80102424
    // 0x80800198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80800198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x8080019C: jal         0x8010A590
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_13;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001A4: b           L_80800248
    // 0x808001A8: nop

        goto L_80800248;
    // 0x808001A8: nop

L_808001AC:
    // 0x808001AC: jal         0x808006BC
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006BC_chdinofoot(rdram, ctx);
        goto after_14;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808001B4: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x808001B8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808001BC: jal         0x80101E14
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808001C4: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x808001C8: nop
    
            goto L_808001D4;
    }
    // 0x808001C8: nop

    // 0x808001CC: jal         0x8010A570
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_16;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_808001D4:
    // 0x808001D4: jal         0x80101DDC
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_17;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808001DC: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x808001E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800248;
    }
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x80102424
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x808001EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1040, 0X7BC) << 16);
    // 0x808001F0: lwc1        $f6, 0x7BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1040, 0X7BC));
    // 0x808001F4: b           L_80800248
    // 0x808001F8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800248;
    // 0x808001F8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808001FC:
    // 0x808001FC: jal         0x800D9078
    // 0x80800200: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_19;
    // 0x80800200: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_19:
    // 0x80800204: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800208: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800248;
    }
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x80102424
    // 0x80800210: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x80800210: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_20:
    // 0x80800214: b           L_80800248
    // 0x80800218: nop

        goto L_80800248;
    // 0x80800218: nop

L_8080021C:
    // 0x8080021C: jal         0x808006BC
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006BC_chdinofoot(rdram, ctx);
        goto after_21;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800224: jal         0x80101DDC
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_22;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8080022C: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800230: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800248;
    }
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: jal         0x80102424
    // 0x80800238: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_23;
    // 0x80800238: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_23:
    // 0x8080023C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1040, 0X7C0) << 16);
    // 0x80800240: lwc1        $f8, 0x7C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1040, 0X7C0));
    // 0x80800244: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800248:
    // 0x80800248: jal         0x80101F24
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_24;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800250: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1040, 0X860) << 16);
    // 0x80800254: addiu       $a1, $a1, 0x860
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1040, 0X860));
    // 0x80800258: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080025C: jal         0x800F3780
    // 0x80800260: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800F3780(rdram, ctx);
        goto after_25;
    // 0x80800260: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_25:
    // 0x80800264: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800268: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800274: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800278: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080027C: jal         0x80089C98
    // 0x80800280: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_26;
    // 0x80800280: nop

    after_26:
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080028C: jal         0x80085770
    // 0x80800290: lui         $a2, 0x4108
    ctx->r6 = S32(0X4108 << 16);
    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_27;
    // 0x80800290: lui         $a2, 0x4108
    ctx->r6 = S32(0X4108 << 16);
    after_27:
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080029C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002A0: jr          $ra
    // 0x808002A4: nop

    return;
    // 0x808002A4: nop

;}
RECOMP_FUNC void func_80801758_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801758: jr          $ra
    // 0x8080175C: sw          $a1, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r5;
    return;
    // 0x8080175C: sw          $a1, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _ncbaledge_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891D0: syscall     766
    recomp_syscall_handler(rdram, ctx, 0x800891D0);
    return;
    // 0x800891D4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bstaxi_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EA0: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083EA0);
    return;
    // 0x80083EA4: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_80800400_chtntdetonator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800400: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800404: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800408: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080040C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800410: beq         $a1, $at, L_8080042C
    if (ctx->r5 == ctx->r1) {
        // 0x80800414: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_8080042C;
    }
    // 0x80800414: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800418: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080041C: beql        $a1, $at, L_80800534
    if (ctx->r5 == ctx->r1) {
        // 0x80800420: lw          $a1, 0x38($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X38);
            goto L_80800534;
    }
    goto skip_0;
    // 0x80800420: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x80800424: b           L_80800578
    // 0x80800428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800578;
    // 0x80800428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080042C:
    // 0x8080042C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800430: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800434: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    // 0x80800438: beq         $a0, $zero, L_80800450
    if (ctx->r4 == 0) {
        // 0x8080043C: nop
    
            goto L_80800450;
    }
    // 0x8080043C: nop

    // 0x80800440: jal         0x80106790
    // 0x80800444: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800444: nop

    after_0:
    // 0x80800448: b           L_80800450
    // 0x8080044C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800450;
    // 0x8080044C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800450:
    // 0x80800450: lw          $a1, 0x6C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6C);
    // 0x80800454: addiu       $a3, $zero, 0x145
    ctx->r7 = ADD32(0, 0X145);
    // 0x80800458: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080045C: sll         $t7, $a1, 11
    ctx->r15 = S32(ctx->r5 << 11);
    // 0x80800460: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800464: beq         $t8, $a3, L_80800488
    if (ctx->r24 == ctx->r7) {
        // 0x80800468: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_80800488;
    }
    // 0x80800468: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8080046C: addiu       $at, $zero, 0x14A
    ctx->r1 = ADD32(0, 0X14A);
    // 0x80800470: beq         $t8, $at, L_808004B0
    if (ctx->r24 == ctx->r1) {
        // 0x80800474: addiu       $at, $zero, 0x14B
        ctx->r1 = ADD32(0, 0X14B);
            goto L_808004B0;
    }
    // 0x80800474: addiu       $at, $zero, 0x14B
    ctx->r1 = ADD32(0, 0X14B);
    // 0x80800478: beq         $t8, $at, L_808004A8
    if (ctx->r24 == ctx->r1) {
        // 0x8080047C: nop
    
            goto L_808004A8;
    }
    // 0x8080047C: nop

    // 0x80800480: b           L_808004B8
    // 0x80800484: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_808004B8;
    // 0x80800484: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80800488:
    // 0x80800488: lhu         $v0, 0x76($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X76);
    // 0x8080048C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(904, 0X790) << 16);
    // 0x80800490: srl         $t9, $v0, 7
    ctx->r25 = S32(U32(ctx->r2) >> 7);
    // 0x80800494: addiu       $v0, $t9, -0x32
    ctx->r2 = ADD32(ctx->r25, -0X32);
    // 0x80800498: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x8080049C: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x808004A0: b           L_808004B4
    // 0x808004A4: lh          $a2, 0x790($a2)
    ctx->r6 = MEM_H(ctx->r6, (int16_t)RELOC_LO16(904, 0X790));
        goto L_808004B4;
    // 0x808004A4: lh          $a2, 0x790($a2)
    ctx->r6 = MEM_H(ctx->r6, (int16_t)RELOC_LO16(904, 0X790));
L_808004A8:
    // 0x808004A8: b           L_808004B4
    // 0x808004AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_808004B4;
    // 0x808004AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_808004B0:
    // 0x808004B0: addiu       $a2, $zero, 0x41
    ctx->r6 = ADD32(0, 0X41);
L_808004B4:
    // 0x808004B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_808004B8:
    // 0x808004B8: beql        $a2, $at, L_80800514
    if (ctx->r6 == ctx->r1) {
        // 0x808004BC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800514;
    }
    goto skip_1;
    // 0x808004BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x808004C0: bne         $a3, $a1, L_808004FC
    if (ctx->r7 != ctx->r5) {
        // 0x808004C4: sw          $zero, 0x28($sp)
        MEM_W(0X28, ctx->r29) = 0;
            goto L_808004FC;
    }
    // 0x808004C4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x808004C8: lhu         $v0, 0x76($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X76);
    // 0x808004CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004D0: addiu       $a0, $zero, 0x2A3
    ctx->r4 = ADD32(0, 0X2A3);
    // 0x808004D4: srl         $t1, $v0, 7
    ctx->r9 = S32(U32(ctx->r2) >> 7);
    // 0x808004D8: addiu       $v0, $t1, -0x32
    ctx->r2 = ADD32(ctx->r9, -0X32);
    // 0x808004DC: bne         $v0, $at, L_808004FC
    if (ctx->r2 != ctx->r1) {
        // 0x808004E0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808004FC;
    }
    // 0x808004E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004E4: jal         0x80089C30
    // 0x808004E8: sh          $a2, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r6;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808004E8: sh          $a2, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r6;
    after_1:
    // 0x808004EC: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004F0: lh          $a2, 0x32($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X32);
            goto L_808004FC;
    }
    // 0x808004F0: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
    // 0x808004F4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x808004F8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_808004FC:
    // 0x808004FC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80800500: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800504: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800508: jal         0x80085708
    // 0x8080050C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x8080050C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_2:
    // 0x80800510: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800514:
    // 0x80800514: jal         0x80102424
    // 0x80800518: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800518: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8080051C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800520: jal         0x8008A4B0
    // 0x80800524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800528: b           L_80800578
    // 0x8080052C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800578;
    // 0x8080052C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800530: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
L_80800534:
    // 0x80800534: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80800538: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8080053C: jal         0x800EEEA8
    // 0x80800540: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EEEA8(rdram, ctx);
        goto after_5;
    // 0x80800540: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_5:
    // 0x80800544: beq         $v0, $zero, L_80800558
    if (ctx->r2 == 0) {
        // 0x80800548: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800558;
    }
    // 0x80800548: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080054C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800550: b           L_8080055C
    // 0x80800554: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8080055C;
    // 0x80800554: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80800558:
    // 0x80800558: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8080055C:
    // 0x8080055C: jal         0x80101010
    // 0x80800560: nop

    func_80101010(rdram, ctx);
        goto after_6;
    // 0x80800560: nop

    after_6:
    // 0x80800564: b           L_80800578
    // 0x80800568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800578;
    // 0x80800568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080056C: b           L_80800578
    // 0x80800570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800578;
    // 0x80800570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800578:
    // 0x80800578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080057C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800580: jr          $ra
    // 0x80800584: nop

    return;
    // 0x80800584: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_41(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802D24: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x80802D28: sh          $a1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r5;
    // 0x80802D2C: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x80802D30: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80802D34: bgez        $t6, L_80802D44
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80802D38: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80802D44;
    }
    // 0x80802D38: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80802D3C: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80802D40: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80802D44:
    // 0x80802D44: subu        $t8, $a1, $t7
    ctx->r24 = SUB32(ctx->r5, ctx->r15);
    // 0x80802D48: sh          $t8, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r24;
    // 0x80802D4C: lh          $v1, 0x8($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X8);
    // 0x80802D50: bgezl       $v1, L_80802D68
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80802D54: lh          $t9, 0x4($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X4);
            goto L_80802D68;
    }
    goto skip_0;
    // 0x80802D54: lh          $t9, 0x4($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4);
    skip_0:
    // 0x80802D58: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x80802D5C: lh          $v1, 0x8($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X8);
    // 0x80802D60: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x80802D64: lh          $t9, 0x4($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4);
L_80802D68:
    // 0x80802D68: subu        $a2, $t9, $v0
    ctx->r6 = SUB32(ctx->r25, ctx->r2);
    // 0x80802D6C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80802D70: beq         $at, $zero, L_80802D7C
    if (ctx->r1 == 0) {
        // 0x80802D74: nop
    
            goto L_80802D7C;
    }
    // 0x80802D74: nop

    // 0x80802D78: sh          $a2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r6;
L_80802D7C:
    // 0x80802D7C: jal         0x808010E0
    // 0x80802D80: nop

    func_808010E0_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80802D80: nop

    after_0:
    // 0x80802D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802D8C: jr          $ra
    // 0x80802D90: nop

    return;
    // 0x80802D90: nop

;}
RECOMP_FUNC void func_80092010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092010: jr          $ra
    // 0x80092014: addiu       $v0, $zero, 0x118
    ctx->r2 = ADD32(0, 0X118);
    return;
    // 0x80092014: addiu       $v0, $zero, 0x118
    ctx->r2 = ADD32(0, 0X118);
;}
RECOMP_FUNC void _gcmapsects_lagoontop_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FE0: syscall     663
    recomp_syscall_handler(rdram, ctx, 0x80087FE0);
    return;
    // 0x80087FE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsdronebitten_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083038: syscall     39
    recomp_syscall_handler(rdram, ctx, 0x80083038);
    return;
    // 0x8008303C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800A24_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A2C: jal         0x800839B8
    // 0x80800A30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800A30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A34: jal         0x80800270
    // 0x80800A38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800270_bsswim(rdram, ctx);
        goto after_1;
    // 0x80800A38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A44: jr          $ra
    // 0x80800A48: nop

    return;
    // 0x80800A48: nop

;}
RECOMP_FUNC void func_80801B8C_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801B90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801B9C: jal         0x80100094
    // 0x80801BA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801BA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801BA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801BA8: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80801BAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X231C) << 16);
    // 0x80801BB0: swc1        $f4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f4.u32l;
    // 0x80801BB4: lwc1        $f6, 0x231C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X231C));
    // 0x80801BB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801BBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801BC0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80801BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BC8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80801BCC: jal         0x80800524
    // 0x80801BD0: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    func_80800524_chchuffy(rdram, ctx);
        goto after_1;
    // 0x80801BD0: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    after_1:
    // 0x80801BD4: jal         0x800EA05C
    // 0x80801BD8: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80801BD8: nop

    after_2:
    // 0x80801BDC: addiu       $at, $zero, 0xD7
    ctx->r1 = ADD32(0, 0XD7);
    // 0x80801BE0: bne         $v0, $at, L_80801C40
    if (ctx->r2 != ctx->r1) {
        // 0x80801BE4: nop
    
            goto L_80801C40;
    }
    // 0x80801BE4: nop

    // 0x80801BE8: jal         0x80800110
    // 0x80801BEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800110_chchuffy(rdram, ctx);
        goto after_3;
    // 0x80801BEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80801BF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801BF4: bne         $v0, $at, L_80801C30
    if (ctx->r2 != ctx->r1) {
        // 0x80801BF8: nop
    
            goto L_80801C30;
    }
    // 0x80801BF8: nop

    // 0x80801BFC: jal         0x800DA298
    // 0x80801C00: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80801C00: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_4:
    // 0x80801C04: bne         $v0, $zero, L_80801C20
    if (ctx->r2 != 0) {
        // 0x80801C08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C20;
    }
    // 0x80801C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C10: jal         0x808017D4
    // 0x80801C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_5;
    // 0x80801C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80801C18: b           L_80801C4C
    // 0x80801C1C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
        goto L_80801C4C;
    // 0x80801C1C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
L_80801C20:
    // 0x80801C20: jal         0x808017D4
    // 0x80801C24: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_6;
    // 0x80801C24: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80801C28: b           L_80801C4C
    // 0x80801C2C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
        goto L_80801C4C;
    // 0x80801C2C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
L_80801C30:
    // 0x80801C30: jal         0x808018F8
    // 0x80801C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018F8_chchuffy(rdram, ctx);
        goto after_7;
    // 0x80801C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801C38: b           L_80801C4C
    // 0x80801C3C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
        goto L_80801C4C;
    // 0x80801C3C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
L_80801C40:
    // 0x80801C40: jal         0x808018F8
    // 0x80801C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018F8_chchuffy(rdram, ctx);
        goto after_8;
    // 0x80801C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801C48: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
L_80801C4C:
    // 0x80801C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C50: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80801C54: bltzl       $t8, L_80801C68
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801C58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801C68;
    }
    goto skip_0;
    // 0x80801C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801C5C: jal         0x80108B04
    // 0x80801C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_9;
    // 0x80801C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80801C64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801C68:
    // 0x80801C68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801C6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801C70: jr          $ra
    // 0x80801C74: nop

    return;
    // 0x80801C74: nop

;}
RECOMP_FUNC void func_8080031C_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800320: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800328: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080032C: bne         $a1, $at, L_80800374
    if (ctx->r5 != ctx->r1) {
        // 0x80800330: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800374;
    }
    // 0x80800330: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800334: jal         0x80100094
    // 0x80800338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080033C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800340: jal         0x80800704
    // 0x80800344: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800704_chstonepillar(rdram, ctx);
        goto after_1;
    // 0x80800344: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800348: jal         0x80088840
    // 0x8080034C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_2;
    // 0x8080034C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x80800350: beq         $v0, $zero, L_8080037C
    if (ctx->r2 == 0) {
        // 0x80800354: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8080037C;
    }
    // 0x80800354: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800358: lh          $t7, 0x2C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2C);
    // 0x8080035C: bnel        $t7, $zero, L_80800380
    if (ctx->r15 != 0) {
        // 0x80800360: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800380;
    }
    goto skip_0;
    // 0x80800360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800364: jal         0x808006AC
    // 0x80800368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808006AC_chstonepillar(rdram, ctx);
        goto after_3;
    // 0x80800368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8080036C: b           L_80800380
    // 0x80800370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800380;
    // 0x80800370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800374:
    // 0x80800374: b           L_80800380
    // 0x80800378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800380;
    // 0x80800378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080037C:
    // 0x8080037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800380:
    // 0x80800380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800384: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800388: jr          $ra
    // 0x8080038C: nop

    return;
    // 0x8080038C: nop

;}
RECOMP_FUNC void func_80808D54_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808D54: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80808D58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808D5C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80808D60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80808D64: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80808D68: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80808D6C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80808D70: jal         0x80100094
    // 0x80808D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808D78: jal         0x800D8FF8
    // 0x80808D7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80808D7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80808D80: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80808D84: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80808D88: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80808D8C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80808D90: jal         0x800EF934
    // 0x80808D94: lw          $a2, 0x48($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X48);
    func_800EF934(rdram, ctx);
        goto after_2;
    // 0x80808D94: lw          $a2, 0x48($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X48);
    after_2:
    // 0x80808D98: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80808D9C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80808DA0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80808DA4: jal         0x800EF04C
    // 0x80808DA8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80808DA8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_3:
    // 0x80808DAC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80808DB0: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80808DB4: jal         0x800EF934
    // 0x80808DB8: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_800EF934(rdram, ctx);
        goto after_4;
    // 0x80808DB8: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_4:
    // 0x80808DBC: addiu       $a1, $s0, 0xD4
    ctx->r5 = ADD32(ctx->r16, 0XD4);
    // 0x80808DC0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80808DC4: jal         0x800EF04C
    // 0x80808DC8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80808DC8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x80808DCC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80808DD0: jal         0x800EEAD4
    // 0x80808DD4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x80808DD4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_6:
    // 0x80808DD8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80808DDC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80808DE0: jal         0x800EECE0
    // 0x80808DE4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EECE0(rdram, ctx);
        goto after_7;
    // 0x80808DE4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80808DE8: beq         $v0, $zero, L_80808E40
    if (ctx->r2 == 0) {
        // 0x80808DEC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80808E40;
    }
    // 0x80808DEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80808DF0: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80808DF4: lwc1        $f12, 0xE0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x80808DF8: jal         0x800F1DCC
    // 0x80808DFC: lwc1        $f14, 0x48($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_8;
    // 0x80808DFC: lwc1        $f14, 0x48($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X48);
    after_8:
    // 0x80808E00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80808E04: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80808E08: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80808E0C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80808E10: nop

    // 0x80808E14: bc1fl       L_80808E30
    if (!c1cs) {
        // 0x80808E18: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80808E30;
    }
    goto skip_0;
    // 0x80808E18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80808E1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80808E20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80808E24: b           L_80808E34
    // 0x80808E28: nop

        goto L_80808E34;
    // 0x80808E28: nop

    // 0x80808E2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80808E30:
    // 0x80808E30: nop

L_80808E34:
    // 0x80808E34: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80808E38: b           L_80808E4C
    // 0x80808E3C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
        goto L_80808E4C;
    // 0x80808E3C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
L_80808E40:
    // 0x80808E40: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80808E44: nop

    // 0x80808E48: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
L_80808E4C:
    // 0x80808E4C: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80808E50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80808E54: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80808E58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80808E5C: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80808E60: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80808E64: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80808E68: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80808E6C: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x80808E70: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80808E74: lwc1        $f10, 0xC8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80808E78: sll         $t2, $a1, 1
    ctx->r10 = S32(ctx->r5 << 1);
    // 0x80808E7C: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80808E80: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80808E84: nop

    // 0x80808E88: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80808E8C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80808E90: swc1        $f16, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f16.u32l;
    // 0x80808E94: lwc1        $f0, 0xC8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80808E98: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80808E9C: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80808EA0: nop

    // 0x80808EA4: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x80808EA8: bne         $at, $zero, L_80808ED8
    if (ctx->r1 != 0) {
        // 0x80808EAC: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80808ED8;
    }
    // 0x80808EAC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80808EB0: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80808EB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80808EB8: nop

    // 0x80808EBC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80808EC0: swc1        $f6, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f6.u32l;
    // 0x80808EC4: lwc1        $f10, 0xC8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80808EC8: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80808ECC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80808ED0: b           L_80808F04
    // 0x80808ED4: sh          $v1, 0xD0($t3)
    MEM_H(0XD0, ctx->r11) = ctx->r3;
        goto L_80808F04;
    // 0x80808ED4: sh          $v1, 0xD0($t3)
    MEM_H(0XD0, ctx->r11) = ctx->r3;
L_80808ED8:
    // 0x80808ED8: bgez        $a0, L_80808F00
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80808EDC: lui         $at, 0x4600
        ctx->r1 = S32(0X4600 << 16);
            goto L_80808F00;
    }
    // 0x80808EDC: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80808EE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80808EE4: nop

    // 0x80808EE8: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80808EEC: swc1        $f18, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f18.u32l;
    // 0x80808EF0: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80808EF4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80808EF8: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80808EFC: nop

L_80808F00:
    // 0x80808F00: sh          $v1, 0xD0($t3)
    MEM_H(0XD0, ctx->r11) = ctx->r3;
L_80808F04:
    // 0x80808F04: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C58) << 16);
    // 0x80808F08: lwc1        $f10, -0x63A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C58));
    // 0x80808F0C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C5C) << 16);
    // 0x80808F10: lwc1        $f18, -0x63A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C5C));
    // 0x80808F14: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80808F18: lwc1        $f6, 0xC0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x80808F1C: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80808F20: nop

    // 0x80808F24: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80808F28: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80808F2C: swc1        $f10, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->f10.u32l;
    // 0x80808F30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80808F34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80808F38: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80808F3C: jr          $ra
    // 0x80808F40: nop

    return;
    // 0x80808F40: nop

;}
RECOMP_FUNC void func_80800128_bashoes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800134: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800138: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080013C: jal         0x80084428
    // 0x80800140: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    _baalarm_new(rdram, ctx);
        goto after_0;
    // 0x80800140: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800144: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800148: jal         0x80095774
    // 0x8080014C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    baflag_clear(rdram, ctx);
        goto after_1;
    // 0x8080014C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800154: jal         0x800A0DB8
    // 0x80800158: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800A0DB8(rdram, ctx);
        goto after_2;
    // 0x80800158: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080015C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800160: beql        $t6, $zero, L_80800174
    if (ctx->r14 == 0) {
        // 0x80800164: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800174;
    }
    goto skip_0;
    // 0x80800164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800168: jal         0x80800020
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800020_bashoes(rdram, ctx);
        goto after_3;
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800174:
    // 0x80800174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void idglowa_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x80800004: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80800008: addu        $v0, $t7, $a1
    ctx->r2 = ADD32(ctx->r15, ctx->r5);
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800010: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800014: beq         $at, $zero, L_808000D8
    if (ctx->r1 == 0) {
        // 0x80800018: lwc1        $f0, 0x4($t6)
        ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
            goto L_808000D8;
    }
    // 0x80800018: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
L_8080001C:
    // 0x8080001C: lbu         $t8, 0xF($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF);
    // 0x80800020: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80800024: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800028: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8080002C: bgez        $t8, L_80800040
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800030: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800040;
    }
    // 0x80800030: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800034: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800038: nop

    // 0x8080003C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800040:
    // 0x80800040: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800044: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800048: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080004C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800050: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80800054: nop

    // 0x80800058: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8080005C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800060: nop

    // 0x80800064: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80800068: beql        $t0, $zero, L_808000B8
    if (ctx->r8 == 0) {
        // 0x8080006C: mfc1        $t0, $f16
        ctx->r8 = (int32_t)ctx->f16.u32l;
            goto L_808000B8;
    }
    goto skip_0;
    // 0x8080006C: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80800070: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800074: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800078: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8080007C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80800080: nop

    // 0x80800084: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800088: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8080008C: nop

    // 0x80800090: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80800094: bne         $t0, $zero, L_808000AC
    if (ctx->r8 != 0) {
        // 0x80800098: nop
    
            goto L_808000AC;
    }
    // 0x80800098: nop

    // 0x8080009C: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x808000A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808000A4: b           L_808000C4
    // 0x808000A8: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_808000C4;
    // 0x808000A8: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_808000AC:
    // 0x808000AC: b           L_808000C4
    // 0x808000B0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_808000C4;
    // 0x808000B0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808000B4: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
L_808000B8:
    // 0x808000B8: nop

    // 0x808000BC: bltz        $t0, L_808000AC
    if (SIGNED(ctx->r8) < 0) {
        // 0x808000C0: nop
    
            goto L_808000AC;
    }
    // 0x808000C0: nop

L_808000C4:
    // 0x808000C4: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x808000C8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808000CC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x808000D0: bne         $at, $zero, L_8080001C
    if (ctx->r1 != 0) {
        // 0x808000D4: sb          $t0, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r8;
            goto L_8080001C;
    }
    // 0x808000D4: sb          $t0, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r8;
L_808000D8:
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void chdoormake_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808004C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004C8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808004CC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808004D0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x808004D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004D8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x808004DC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x808004E0: jal         0x80800000
    // 0x808004E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_chdoormake(rdram, ctx);
        goto after_0;
    // 0x808004E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808004E8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808004EC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808004F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808004F4: jal         0x800EE940
    // 0x808004F8: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    func_800EE940(rdram, ctx);
        goto after_1;
    // 0x808004F8: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    after_1:
    // 0x808004FC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800500: jal         0x800EE7F8
    // 0x80800504: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800504: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800508: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080050C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800510: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800514: jal         0x800EF214
    // 0x80800518: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    func_800EF214(rdram, ctx);
        goto after_3;
    // 0x80800518: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x8080051C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800520: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800524: jal         0x800EE940
    // 0x80800528: addiu       $a0, $a0, 0x16
    ctx->r4 = ADD32(ctx->r4, 0X16);
    func_800EE940(rdram, ctx);
        goto after_4;
    // 0x80800528: addiu       $a0, $a0, 0x16
    ctx->r4 = ADD32(ctx->r4, 0X16);
    after_4:
    // 0x8080052C: jal         0x808008C4
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008C4_chdoormake(rdram, ctx);
        goto after_5;
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800534: bne         $v0, $zero, L_8080054C
    if (ctx->r2 != 0) {
        // 0x80800538: lw          $t8, 0x48($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X48);
            goto L_8080054C;
    }
    // 0x80800538: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8080053C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800540: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800544: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800548: bne         $t7, $at, L_80800594
    if (ctx->r15 != ctx->r1) {
        // 0x8080054C: andi        $t9, $t8, 0x1
        ctx->r25 = ctx->r24 & 0X1;
            goto L_80800594;
    }
L_8080054C:
    // 0x8080054C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80800550: beq         $t9, $zero, L_80800568
    if (ctx->r25 == 0) {
        // 0x80800554: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800568;
    }
    // 0x80800554: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800558: jal         0x800FFAB0
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800560: b           L_808005A0
    // 0x80800564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005A0;
    // 0x80800564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800568:
    // 0x80800568: jal         0x800EE7F8
    // 0x8080056C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080056C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_7:
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800574: jal         0x80101FDC
    // 0x80800578: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80800578: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x8080057C: jal         0x80103014
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_9;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800584: jal         0x808000B8
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B8_chdoormake(rdram, ctx);
        goto after_10;
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080058C: b           L_808005A0
    // 0x80800590: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808005A0;
    // 0x80800590: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800594:
    // 0x80800594: jal         0x808000B8
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B8_chdoormake(rdram, ctx);
        goto after_11;
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080059C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005A0:
    // 0x808005A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808005AC: jr          $ra
    // 0x808005B0: nop

    return;
    // 0x808005B0: nop

;}
RECOMP_FUNC void func_80017840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017840: jr          $ra
    // 0x80017844: nop

    return;
    // 0x80017844: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EB0: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089EB0);
    return;
    // 0x80089EB4: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void _dbvtxnormal_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879F8: syscall     648
    recomp_syscall_handler(rdram, ctx, 0x800879F8);
    return;
    // 0x800879FC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080030C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800310: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800314: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x80800318: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8080031C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800320: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80800324: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80800328: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8080032C: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800330: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800334: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800338: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8080033C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800340: jal         0x800B5BE4
    // 0x80800344: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800344: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80800348: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(404, 0X22CC) << 16);
    // 0x8080034C: addiu       $t6, $t6, 0x22CC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(404, 0X22CC));
    // 0x80800350: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800354: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800358: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080035C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800360: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800364: jal         0x800BABB8
    // 0x80800368: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800368: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8080036C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(404, 0X2200) << 16);
    // 0x80800370: lwc1        $f20, 0x2200($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(404, 0X2200));
    // 0x80800374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800378: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080037C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800380: jal         0x800BA8F8
    // 0x80800384: nop

    func_800BA8F8(rdram, ctx);
        goto after_2;
    // 0x80800384: nop

    after_2:
    // 0x80800388: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x8080038C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800390: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800394: div.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800398: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080039C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003A0: jal         0x800BA5BC
    // 0x808003A4: nop

    func_800BA5BC(rdram, ctx);
        goto after_3;
    // 0x808003A4: nop

    after_3:
    // 0x808003A8: lui         $at, 0x43D7
    ctx->r1 = S32(0X43D7 << 16);
    // 0x808003AC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808003B0: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x808003B4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808003B8: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x808003BC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808003C0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808003C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808003C8: addiu       $s3, $zero, 0x168
    ctx->r19 = ADD32(0, 0X168);
    // 0x808003CC: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x808003D0: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
L_808003D4:
    // 0x808003D4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x808003D8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808003DC: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808003E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808003E4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808003E8: jal         0x800EFA4C
    // 0x808003EC: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x808003EC: nop

    after_4:
    // 0x808003F0: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808003F4: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808003F8: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x808003FC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800404: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800408: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080040C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800410: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800414: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80800418: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8080041C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800420: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x80800424: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80800428: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x8080042C: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80800430: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80800434: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x80800438: jal         0x800BA994
    // 0x8080043C: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    func_800BA994(rdram, ctx);
        goto after_5;
    // 0x8080043C: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    after_5:
    // 0x80800440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800444: jal         0x800BA22C
    // 0x80800448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x80800448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080044C: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80800450: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800454: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800458: jal         0x800EFA4C
    // 0x8080045C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x8080045C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80800460: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800464: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80800468: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8080046C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800470: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800474: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800478: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080047C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800480: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800484: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80800488: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8080048C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800490: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x80800494: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80800498: sll         $t3, $a3, 16
    ctx->r11 = S32(ctx->r7 << 16);
    // 0x8080049C: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    // 0x808004A0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x808004A4: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x808004A8: jal         0x800BA994
    // 0x808004AC: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    func_800BA994(rdram, ctx);
        goto after_8;
    // 0x808004AC: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    after_8:
    // 0x808004B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004B4: jal         0x800BA22C
    // 0x808004B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_9;
    // 0x808004B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808004BC: addiu       $s0, $s0, 0x2D
    ctx->r16 = ADD32(ctx->r16, 0X2D);
    // 0x808004C0: bnel        $s0, $s3, L_808003D4
    if (ctx->r16 != ctx->r19) {
        // 0x808004C4: mtc1        $s0, $f6
        ctx->f6.u32l = ctx->r16;
            goto L_808003D4;
    }
    goto skip_0;
    // 0x808004C4: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    skip_0:
    // 0x808004C8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x808004CC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808004D0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808004D4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808004D8: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x808004DC: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x808004E0: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x808004E4: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x808004E8: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x808004EC: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x808004F0: jr          $ra
    // 0x808004F4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x808004F4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80105C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105C48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80105C4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80105C50: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80105C54: addiu       $s2, $s2, 0x6ED0
    ctx->r18 = ADD32(ctx->r18, 0X6ED0);
    // 0x80105C58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80105C5C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80105C60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80105C64: jal         0x800B3034
    // 0x80105C68: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    freelist_capacity(rdram, ctx);
        goto after_0;
    // 0x80105C68: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x80105C6C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80105C70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80105C74: bne         $at, $zero, L_80105CAC
    if (ctx->r1 != 0) {
        // 0x80105C78: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80105CAC;
    }
    // 0x80105C78: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80105C7C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_80105C80:
    // 0x80105C80: jal         0x800B31B8
    // 0x80105C84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    freelist_is_element_alive(rdram, ctx);
        goto after_1;
    // 0x80105C84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80105C88: beq         $v0, $zero, L_80105C9C
    if (ctx->r2 == 0) {
        // 0x80105C8C: sll         $a0, $s0, 16
        ctx->r4 = S32(ctx->r16 << 16);
            goto L_80105C9C;
    }
    // 0x80105C8C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80105C90: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80105C94: jal         0x801060E4
    // 0x80105C98: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_801060E4(rdram, ctx);
        goto after_2;
    // 0x80105C98: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
L_80105C9C:
    // 0x80105C9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80105CA0: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80105CA4: bnel        $at, $zero, L_80105C80
    if (ctx->r1 != 0) {
        // 0x80105CA8: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_80105C80;
    }
    goto skip_0;
    // 0x80105CA8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_80105CAC:
    // 0x80105CAC: jal         0x800B3248
    // 0x80105CB0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    freelist_free(rdram, ctx);
        goto after_3;
    // 0x80105CB0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_3:
    // 0x80105CB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80105CB8: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x80105CBC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80105CC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80105CC4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80105CC8: jr          $ra
    // 0x80105CCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80105CCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _baduo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084930: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084930);
    return;
    // 0x80084934: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void cadbfunc_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B4: jal         0x80800120
    // 0x808001B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800120_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x808001B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001BC: bne         $v0, $zero, L_808001CC
    if (ctx->r2 != 0) {
        // 0x808001C0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808001CC;
    }
    // 0x808001C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808001C4: b           L_808001D8
    // 0x808001C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001D8;
    // 0x808001C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001CC:
    // 0x808001CC: jal         0x800EE7F8
    // 0x808001D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808001D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001D8:
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001E0: jr          $ra
    // 0x808001E4: nop

    return;
    // 0x808001E4: nop

;}
RECOMP_FUNC void gspropctrl_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X6);
    // 0x80800090: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800094: jr          $ra
    // 0x80800098: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80800098: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_808004F4_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800500: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800504: jal         0x8008CABC
    // 0x80800508: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800508: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x8080050C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800510: jal         0x800852C0
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800518: jal         0x800852C8
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800520: jal         0x800852D0
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800528: lui         $a1, 0x3F03
    ctx->r5 = S32(0X3F03 << 16);
    // 0x8080052C: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    // 0x80800530: jal         0x8008B348
    // 0x80800534: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x80800534: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800538: beq         $v0, $zero, L_80800550
    if (ctx->r2 == 0) {
        // 0x8080053C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800550;
    }
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: jal         0x800852B8
    // 0x80800544: lui         $a1, 0x43A0
    ctx->r5 = S32(0X43A0 << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800544: lui         $a1, 0x43A0
    ctx->r5 = S32(0X43A0 << 16);
    after_5:
    // 0x80800548: b           L_80800560
    // 0x8080054C: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
        goto L_80800560;
    // 0x8080054C: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
L_80800550:
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: jal         0x800852B8
    // 0x80800558: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800558: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_6:
    // 0x8080055C: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
L_80800560:
    // 0x80800560: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80800564: jal         0x8008B348
    // 0x80800568: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80800568: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x8080056C: beq         $v0, $zero, L_80800588
    if (ctx->r2 == 0) {
        // 0x80800570: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800588;
    }
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800574: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x80800578: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080057C: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    // 0x80800580: jal         0x8009DF18
    // 0x80800584: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF18(rdram, ctx);
        goto after_8;
    // 0x80800584: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_8:
L_80800588:
    // 0x80800588: lui         $a1, 0x3F2B
    ctx->r5 = S32(0X3F2B << 16);
    // 0x8080058C: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80800590: jal         0x8008B348
    // 0x80800594: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x80800594: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80800598: beq         $v0, $zero, L_808005B4
    if (ctx->r2 == 0) {
        // 0x8080059C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005B4;
    }
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: lui         $a2, 0x3FD9
    ctx->r6 = S32(0X3FD9 << 16);
    // 0x808005A4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808005A8: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    // 0x808005AC: jal         0x8009DF18
    // 0x808005B0: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF18(rdram, ctx);
        goto after_10;
    // 0x808005B0: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_10:
L_808005B4:
    // 0x808005B4: jal         0x80085280
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808005BC: beq         $v0, $zero, L_808005EC
    if (ctx->r2 == 0) {
        // 0x808005C0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808005EC;
    }
    // 0x808005C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005C8: beq         $v0, $at, L_80800614
    if (ctx->r2 == ctx->r1) {
        // 0x808005CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800614;
    }
    // 0x808005CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005D0: beq         $v0, $at, L_80800608
    if (ctx->r2 == ctx->r1) {
        // 0x808005D4: addiu       $t7, $zero, 0x82
        ctx->r15 = ADD32(0, 0X82);
            goto L_80800608;
    }
    // 0x808005D4: addiu       $t7, $zero, 0x82
    ctx->r15 = ADD32(0, 0X82);
    // 0x808005D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005DC: beq         $v0, $at, L_80800610
    if (ctx->r2 == ctx->r1) {
        // 0x808005E0: addiu       $t8, $zero, 0x90
        ctx->r24 = ADD32(0, 0X90);
            goto L_80800610;
    }
    // 0x808005E0: addiu       $t8, $zero, 0x90
    ctx->r24 = ADD32(0, 0X90);
    // 0x808005E4: b           L_80800614
    // 0x808005E8: nop

        goto L_80800614;
    // 0x808005E8: nop

L_808005EC:
    // 0x808005EC: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x808005F0: jal         0x8008B348
    // 0x808005F4: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    anctrl_isAt(rdram, ctx);
        goto after_12;
    // 0x808005F4: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    after_12:
    // 0x808005F8: beq         $v0, $zero, L_80800614
    if (ctx->r2 == 0) {
        // 0x808005FC: addiu       $t6, $zero, 0x2B
        ctx->r14 = ADD32(0, 0X2B);
            goto L_80800614;
    }
    // 0x808005FC: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x80800600: b           L_80800614
    // 0x80800604: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_80800614;
    // 0x80800604: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800608:
    // 0x80800608: b           L_80800614
    // 0x8080060C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80800614;
    // 0x8080060C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800610:
    // 0x80800610: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800614:
    // 0x80800614: jal         0x80085278
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080061C: beq         $v0, $zero, L_80800628
    if (ctx->r2 == 0) {
        // 0x80800620: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_80800628;
    }
    // 0x80800620: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x80800624: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800628:
    // 0x80800628: jal         0x8008E35C
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_14;
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800630: bne         $v0, $zero, L_80800640
    if (ctx->r2 != 0) {
        // 0x80800634: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800640;
    }
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080063C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80800640:
    // 0x80800640: jal         0x8009E5C8
    // 0x80800644: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x80800644: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x80800648: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080064C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800654: jr          $ra
    // 0x80800658: nop

    return;
    // 0x80800658: nop

;}
RECOMP_FUNC void func_800E589C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E589C: addiu       $sp, $sp, -0x5F8
    ctx->r29 = ADD32(ctx->r29, -0X5F8);
    // 0x800E58A0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800E58A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800E58A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800E58AC: addiu       $s1, $sp, 0x5B0
    ctx->r17 = ADD32(ctx->r29, 0X5B0);
    // 0x800E58B0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800E58B4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800E58B8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800E58BC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800E58C0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800E58C4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800E58C8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800E58CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800E58D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E58D4: sw          $a2, 0x600($sp)
    MEM_W(0X600, ctx->r29) = ctx->r6;
    // 0x800E58D8: sw          $a3, 0x604($sp)
    MEM_W(0X604, ctx->r29) = ctx->r7;
    // 0x800E58DC: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x800E58E0: jal         0x8002D6E0
    // 0x800E58E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bzero(rdram, ctx);
        goto after_0;
    // 0x800E58E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800E58E8: andi        $v0, $s3, 0x3
    ctx->r2 = ctx->r19 & 0X3;
    // 0x800E58EC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800E58F0: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x800E58F4: beq         $v0, $zero, L_800E592C
    if (ctx->r2 == 0) {
        // 0x800E58F8: or          $ra, $s3, $zero
        ctx->r31 = ctx->r19 | 0;
            goto L_800E592C;
    }
    // 0x800E58F8: or          $ra, $s3, $zero
    ctx->r31 = ctx->r19 | 0;
    // 0x800E58FC: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
L_800E5900:
    // 0x800E5900: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x800E5904: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800E5908: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800E590C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800E5910: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x800E5914: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800E5918: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800E591C: bne         $v1, $ra, L_800E5900
    if (ctx->r3 != ctx->r31) {
        // 0x800E5920: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_800E5900;
    }
    // 0x800E5920: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800E5924: beql        $ra, $zero, L_800E599C
    if (ctx->r31 == 0) {
        // 0x800E5928: lw          $t6, 0x5B0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X5B0);
            goto L_800E599C;
    }
    goto skip_0;
    // 0x800E5928: lw          $t6, 0x5B0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5B0);
    skip_0:
L_800E592C:
    // 0x800E592C: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x800E5930: addiu       $ra, $ra, -0x4
    ctx->r31 = ADD32(ctx->r31, -0X4);
    // 0x800E5934: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // 0x800E5938: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800E593C: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x800E5940: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800E5944: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800E5948: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800E594C: lw          $t6, -0xC($s7)
    ctx->r14 = MEM_W(ctx->r23, -0XC);
    // 0x800E5950: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800E5954: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x800E5958: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800E595C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800E5960: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800E5964: lw          $t6, -0x8($s7)
    ctx->r14 = MEM_W(ctx->r23, -0X8);
    // 0x800E5968: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800E596C: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x800E5970: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800E5974: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800E5978: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800E597C: lw          $t6, -0x4($s7)
    ctx->r14 = MEM_W(ctx->r23, -0X4);
    // 0x800E5980: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800E5984: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x800E5988: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800E598C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800E5990: bne         $ra, $zero, L_800E592C
    if (ctx->r31 != 0) {
        // 0x800E5994: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_800E592C;
    }
    // 0x800E5994: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800E5998: lw          $t6, 0x5B0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5B0);
L_800E599C:
    // 0x800E599C: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x800E59A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800E59A4: bne         $s3, $t6, L_800E59C4
    if (ctx->r19 != ctx->r14) {
        // 0x800E59A8: addiu       $v1, $sp, 0x5B4
        ctx->r3 = ADD32(ctx->r29, 0X5B4);
            goto L_800E59C4;
    }
    // 0x800E59A8: addiu       $v1, $sp, 0x5B4
    ctx->r3 = ADD32(ctx->r29, 0X5B4);
    // 0x800E59AC: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x800E59B0: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x800E59B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E59B8: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800E59BC: b           L_800E5E90
    // 0x800E59C0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_800E5E90;
    // 0x800E59C0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800E59C4:
    // 0x800E59C4: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x800E59C8: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800E59CC:
    // 0x800E59CC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800E59D0: bnel        $t7, $zero, L_800E59E8
    if (ctx->r15 != 0) {
        // 0x800E59D4: sltu        $at, $s0, $a3
        ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
            goto L_800E59E8;
    }
    goto skip_1;
    // 0x800E59D4: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    skip_1:
    // 0x800E59D8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800E59DC: bne         $a3, $v0, L_800E59CC
    if (ctx->r7 != ctx->r2) {
        // 0x800E59E0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800E59CC;
    }
    // 0x800E59E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800E59E4: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
L_800E59E8:
    // 0x800E59E8: beq         $at, $zero, L_800E59F4
    if (ctx->r1 == 0) {
        // 0x800E59EC: or          $s4, $a3, $zero
        ctx->r20 = ctx->r7 | 0;
            goto L_800E59F4;
    }
    // 0x800E59EC: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800E59F0: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
L_800E59F4:
    // 0x800E59F4: addiu       $ra, $zero, 0x10
    ctx->r31 = ADD32(0, 0X10);
    // 0x800E59F8: addiu       $v0, $sp, 0x5F0
    ctx->r2 = ADD32(ctx->r29, 0X5F0);
L_800E59FC:
    // 0x800E59FC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800E5A00: bnel        $t8, $zero, L_800E5A18
    if (ctx->r24 != 0) {
        // 0x800E5A04: sltu        $at, $ra, $s0
        ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
            goto L_800E5A18;
    }
    goto skip_2;
    // 0x800E5A04: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
    skip_2:
    // 0x800E5A08: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800E5A0C: bne         $ra, $zero, L_800E59FC
    if (ctx->r31 != 0) {
        // 0x800E5A10: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800E59FC;
    }
    // 0x800E5A10: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800E5A14: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
L_800E5A18:
    // 0x800E5A18: beq         $at, $zero, L_800E5A24
    if (ctx->r1 == 0) {
        // 0x800E5A1C: or          $fp, $ra, $zero
        ctx->r30 = ctx->r31 | 0;
            goto L_800E5A24;
    }
    // 0x800E5A1C: or          $fp, $ra, $zero
    ctx->r30 = ctx->r31 | 0;
    // 0x800E5A20: or          $s0, $ra, $zero
    ctx->r16 = ctx->r31 | 0;
L_800E5A24:
    // 0x800E5A24: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800E5A28: sltu        $at, $a3, $ra
    ctx->r1 = ctx->r7 < ctx->r31 ? 1 : 0;
    // 0x800E5A2C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800E5A30: beq         $at, $zero, L_800E5A60
    if (ctx->r1 == 0) {
        // 0x800E5A34: sllv        $a0, $t9, $a3
        ctx->r4 = S32(ctx->r25 << (ctx->r7 & 31));
            goto L_800E5A60;
    }
    // 0x800E5A34: sllv        $a0, $t9, $a3
    ctx->r4 = S32(ctx->r25 << (ctx->r7 & 31));
    // 0x800E5A38: sll         $t6, $ra, 2
    ctx->r14 = S32(ctx->r31 << 2);
    // 0x800E5A3C: addiu       $t7, $sp, 0x5B0
    ctx->r15 = ADD32(ctx->r29, 0X5B0);
    // 0x800E5A40: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
L_800E5A44:
    // 0x800E5A44: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800E5A48: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800E5A4C: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x800E5A50: subu        $a0, $a0, $t8
    ctx->r4 = SUB32(ctx->r4, ctx->r24);
    // 0x800E5A54: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800E5A58: bne         $at, $zero, L_800E5A44
    if (ctx->r1 != 0) {
        // 0x800E5A5C: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_800E5A44;
    }
    // 0x800E5A5C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_800E5A60:
    // 0x800E5A60: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800E5A64: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800E5A68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E5A6C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800E5A70: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800E5A74: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800E5A78: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800E5A7C: addiu       $s7, $sp, 0x5B4
    ctx->r23 = ADD32(ctx->r29, 0X5B4);
    // 0x800E5A80: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x800E5A84: beq         $ra, $zero, L_800E5B1C
    if (ctx->r31 == 0) {
        // 0x800E5A88: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800E5B1C;
    }
    // 0x800E5A88: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800E5A8C: andi        $t0, $ra, 0x3
    ctx->r8 = ctx->r31 & 0X3;
    // 0x800E5A90: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800E5A94: beq         $t0, $zero, L_800E5AD0
    if (ctx->r8 == 0) {
        // 0x800E5A98: addu        $v1, $t0, $ra
        ctx->r3 = ADD32(ctx->r8, ctx->r31);
            goto L_800E5AD0;
    }
    // 0x800E5A98: addu        $v1, $t0, $ra
    ctx->r3 = ADD32(ctx->r8, ctx->r31);
    // 0x800E5A9C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800E5AA0: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800E5AA4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
L_800E5AA8:
    // 0x800E5AA8: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800E5AAC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800E5AB0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800E5AB4: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x800E5AB8: sw          $a3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r7;
    // 0x800E5ABC: bne         $a1, $v0, L_800E5AA8
    if (ctx->r5 != ctx->r2) {
        // 0x800E5AC0: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_800E5AA8;
    }
    // 0x800E5AC0: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800E5AC4: addiu       $t6, $sp, 0x5B0
    ctx->r14 = ADD32(ctx->r29, 0X5B0);
    // 0x800E5AC8: beql        $v0, $t6, L_800E5B20
    if (ctx->r2 == ctx->r14) {
        // 0x800E5ACC: or          $s7, $s2, $zero
        ctx->r23 = ctx->r18 | 0;
            goto L_800E5B20;
    }
    goto skip_3;
    // 0x800E5ACC: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    skip_3:
L_800E5AD0:
    // 0x800E5AD0: sw          $s3, 0x5FC($sp)
    MEM_W(0X5FC, ctx->r29) = ctx->r19;
    // 0x800E5AD4: addiu       $v1, $sp, 0x5B0
    ctx->r3 = ADD32(ctx->r29, 0X5B0);
L_800E5AD8:
    // 0x800E5AD8: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800E5ADC: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x800E5AE0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800E5AE4: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800E5AE8: sw          $a3, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->r7;
    // 0x800E5AEC: lw          $t8, 0x4($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X4);
    // 0x800E5AF0: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // 0x800E5AF4: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x800E5AF8: sw          $a3, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->r7;
    // 0x800E5AFC: lw          $t9, -0x8($s7)
    ctx->r25 = MEM_W(ctx->r23, -0X8);
    // 0x800E5B00: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x800E5B04: sw          $a3, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->r7;
    // 0x800E5B08: lw          $t6, -0x4($s7)
    ctx->r14 = MEM_W(ctx->r23, -0X4);
    // 0x800E5B0C: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x800E5B10: bne         $v0, $v1, L_800E5AD8
    if (ctx->r2 != ctx->r3) {
        // 0x800E5B14: sw          $a3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r7;
            goto L_800E5AD8;
    }
    // 0x800E5B14: sw          $a3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r7;
    // 0x800E5B18: lw          $s3, 0x5FC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5FC);
L_800E5B1C:
    // 0x800E5B1C: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
L_800E5B20:
    // 0x800E5B20: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800E5B24: sw          $s3, 0x5FC($sp)
    MEM_W(0X5FC, ctx->r29) = ctx->r19;
    // 0x800E5B28: or          $t1, $s3, $zero
    ctx->r9 = ctx->r19 | 0;
    // 0x800E5B2C: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x800E5B30: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    // 0x800E5B34: lw          $a3, 0x0($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X0);
L_800E5B38:
    // 0x800E5B38: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800E5B3C: beq         $a3, $zero, L_800E5B60
    if (ctx->r7 == 0) {
        // 0x800E5B40: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_800E5B60;
    }
    // 0x800E5B40: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x800E5B44: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
    // 0x800E5B48: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800E5B4C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800E5B50: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800E5B54: sw          $ra, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r31;
    // 0x800E5B58: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800E5B5C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800E5B60:
    // 0x800E5B60: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800E5B64: sltu        $at, $ra, $t1
    ctx->r1 = ctx->r31 < ctx->r9 ? 1 : 0;
    // 0x800E5B68: bnel        $at, $zero, L_800E5B38
    if (ctx->r1 != 0) {
        // 0x800E5B6C: lw          $a3, 0x0($s7)
        ctx->r7 = MEM_W(ctx->r23, 0X0);
            goto L_800E5B38;
    }
    goto skip_4;
    // 0x800E5B6C: lw          $a3, 0x0($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X0);
    skip_4:
    // 0x800E5B70: slt         $at, $fp, $s4
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800E5B74: sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    // 0x800E5B78: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800E5B7C: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800E5B80: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800E5B84: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800E5B88: negu        $t2, $s0
    ctx->r10 = SUB32(0, ctx->r16);
    // 0x800E5B8C: sw          $zero, 0x544($sp)
    MEM_W(0X544, ctx->r29) = 0;
    // 0x800E5B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E5B94: bne         $at, $zero, L_800E5E78
    if (ctx->r1 != 0) {
        // 0x800E5B98: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800E5E78;
    }
    // 0x800E5B98: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800E5B9C: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x800E5BA0: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800E5BA4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800E5BA8: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x800E5BAC: addiu       $s3, $sp, 0x584
    ctx->r19 = ADD32(ctx->r29, 0X584);
    // 0x800E5BB0: lw          $s1, 0x614($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X614);
L_800E5BB4:
    // 0x800E5BB4: lw          $s6, 0x0($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X0);
    // 0x800E5BB8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800E5BBC: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x800E5BC0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800E5BC4: beq         $s6, $zero, L_800E5E64
    if (ctx->r22 == 0) {
        // 0x800E5BC8: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800E5E64;
    }
    // 0x800E5BC8: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800E5BCC: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x800E5BD0: addu        $t3, $t5, $t9
    ctx->r11 = ADD32(ctx->r13, ctx->r25);
    // 0x800E5BD4: addiu       $t8, $sp, 0xC4
    ctx->r24 = ADD32(ctx->r29, 0XC4);
    // 0x800E5BD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800E5BDC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800E5BE0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800E5BE4: addiu       $t6, $s4, 0x1F
    ctx->r14 = ADD32(ctx->r20, 0X1F);
    // 0x800E5BE8: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800E5BEC: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800E5BF0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800E5BF4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
L_800E5BF8:
    // 0x800E5BF8: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800E5BFC: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800E5C00: beq         $at, $zero, L_800E5D1C
    if (ctx->r1 == 0) {
        // 0x800E5C04: addiu       $s2, $s6, 0x1
        ctx->r18 = ADD32(ctx->r22, 0X1);
            goto L_800E5D1C;
    }
    // 0x800E5C04: addiu       $s2, $s6, 0x1
    ctx->r18 = ADD32(ctx->r22, 0X1);
    // 0x800E5C08: addiu       $t9, $sp, 0x544
    ctx->r25 = ADD32(ctx->r29, 0X544);
    // 0x800E5C0C: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x800E5C10: subu        $t0, $fp, $v1
    ctx->r8 = SUB32(ctx->r30, ctx->r3);
L_800E5C14:
    // 0x800E5C14: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x800E5C18: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800E5C1C: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x800E5C20: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800E5C24: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800E5C28: beq         $at, $zero, L_800E5C34
    if (ctx->r1 == 0) {
        // 0x800E5C2C: or          $t2, $v1, $zero
        ctx->r10 = ctx->r3 | 0;
            goto L_800E5C34;
    }
    // 0x800E5C2C: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x800E5C30: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_800E5C34:
    // 0x800E5C34: subu        $v0, $s4, $t2
    ctx->r2 = SUB32(ctx->r20, ctx->r10);
    // 0x800E5C38: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800E5C3C: sllv        $a0, $t7, $v0
    ctx->r4 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x800E5C40: sltu        $at, $s2, $a0
    ctx->r1 = ctx->r18 < ctx->r4 ? 1 : 0;
    // 0x800E5C44: beq         $at, $zero, L_800E5C94
    if (ctx->r1 == 0) {
        // 0x800E5C48: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800E5C94;
    }
    // 0x800E5C48: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800E5C4C: addiu       $a3, $v0, 0x1
    ctx->r7 = ADD32(ctx->r2, 0X1);
    // 0x800E5C50: subu        $v1, $a0, $s6
    ctx->r3 = SUB32(ctx->r4, ctx->r22);
    // 0x800E5C54: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x800E5C58: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800E5C5C: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800E5C60: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800E5C64: beq         $at, $zero, L_800E5C94
    if (ctx->r1 == 0) {
        // 0x800E5C68: addu        $a2, $t6, $t8
        ctx->r6 = ADD32(ctx->r14, ctx->r24);
            goto L_800E5C94;
    }
    // 0x800E5C68: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
L_800E5C6C:
    // 0x800E5C6C: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800E5C70: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800E5C74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800E5C78: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800E5C7C: beql        $at, $zero, L_800E5C98
    if (ctx->r1 == 0) {
        // 0x800E5C80: lw          $v1, 0x2C($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X2C);
            goto L_800E5C98;
    }
    goto skip_5;
    // 0x800E5C80: lw          $v1, 0x2C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X2C);
    skip_5:
    // 0x800E5C84: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800E5C88: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800E5C8C: bne         $at, $zero, L_800E5C6C
    if (ctx->r1 != 0) {
        // 0x800E5C90: subu        $v1, $v0, $a0
        ctx->r3 = SUB32(ctx->r2, ctx->r4);
            goto L_800E5C6C;
    }
    // 0x800E5C90: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
L_800E5C94:
    // 0x800E5C94: lw          $v1, 0x2C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X2C);
L_800E5C98:
    // 0x800E5C98: lw          $t7, 0x28($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X28);
    // 0x800E5C9C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800E5CA0: sllv        $t0, $t9, $a3
    ctx->r8 = S32(ctx->r25 << (ctx->r7 & 31));
    // 0x800E5CA4: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800E5CA8: addu        $t8, $v1, $t0
    ctx->r24 = ADD32(ctx->r3, ctx->r8);
    // 0x800E5CAC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800E5CB0: addu        $a2, $t7, $t6
    ctx->r6 = ADD32(ctx->r15, ctx->r14);
    // 0x800E5CB4: sw          $t9, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r25;
    // 0x800E5CB8: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x800E5CBC: sw          $a0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r4;
    // 0x800E5CC0: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800E5CC4: addiu       $s5, $a2, 0x4
    ctx->r21 = ADD32(ctx->r6, 0X4);
    // 0x800E5CC8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800E5CCC: beq         $t4, $zero, L_800E5D0C
    if (ctx->r12 == 0) {
        // 0x800E5CD0: sw          $a0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r4;
            goto L_800E5D0C;
    }
    // 0x800E5CD0: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x800E5CD4: sw          $ra, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r31;
    // 0x800E5CD8: addiu       $t7, $a3, 0x10
    ctx->r15 = ADD32(ctx->r7, 0X10);
    // 0x800E5CDC: sb          $s0, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r16;
    // 0x800E5CE0: sb          $t7, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r15;
    // 0x800E5CE4: sw          $a0, 0x588($sp)
    MEM_W(0X588, ctx->r29) = ctx->r4;
    // 0x800E5CE8: lw          $t6, -0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, -0X4);
    // 0x800E5CEC: subu        $t8, $t2, $s0
    ctx->r24 = SUB32(ctx->r10, ctx->r16);
    // 0x800E5CF0: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x800E5CF4: srlv        $t9, $ra, $t8
    ctx->r25 = S32(U32(ctx->r31) >> (ctx->r24 & 31));
    // 0x800E5CF8: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800E5CFC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800E5D00: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x800E5D04: lw          $t7, 0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4);
    // 0x800E5D08: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_800E5D0C:
    // 0x800E5D0C: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800E5D10: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800E5D14: bnel        $at, $zero, L_800E5C14
    if (ctx->r1 != 0) {
        // 0x800E5D18: subu        $t0, $fp, $v1
        ctx->r8 = SUB32(ctx->r30, ctx->r3);
            goto L_800E5C14;
    }
    goto skip_6;
    // 0x800E5D18: subu        $t0, $fp, $v1
    ctx->r8 = SUB32(ctx->r30, ctx->r3);
    skip_6:
L_800E5D1C:
    // 0x800E5D1C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800E5D20: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800E5D24: subu        $v1, $s4, $t2
    ctx->r3 = SUB32(ctx->r20, ctx->r10);
    // 0x800E5D28: sllv        $a1, $t6, $t2
    ctx->r5 = S32(ctx->r14 << (ctx->r10 & 31));
    // 0x800E5D2C: sltu        $at, $s7, $t9
    ctx->r1 = ctx->r23 < ctx->r25 ? 1 : 0;
    // 0x800E5D30: sb          $v1, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r3;
    // 0x800E5D34: bne         $at, $zero, L_800E5D48
    if (ctx->r1 != 0) {
        // 0x800E5D38: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800E5D48;
    }
    // 0x800E5D38: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800E5D3C: addiu       $t8, $zero, 0x63
    ctx->r24 = ADD32(0, 0X63);
    // 0x800E5D40: b           L_800E5DC4
    // 0x800E5D44: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
        goto L_800E5DC4;
    // 0x800E5D44: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
L_800E5D48:
    // 0x800E5D48: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x800E5D4C: lw          $t7, 0x600($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X600);
    // 0x800E5D50: lw          $a0, 0x600($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X600);
    // 0x800E5D54: lw          $t6, 0x608($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X608);
    // 0x800E5D58: sltu        $at, $v0, $t7
    ctx->r1 = ctx->r2 < ctx->r15 ? 1 : 0;
    // 0x800E5D5C: beq         $at, $zero, L_800E5D8C
    if (ctx->r1 == 0) {
        // 0x800E5D60: sltiu       $at, $v0, 0x100
        ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
            goto L_800E5D8C;
    }
    // 0x800E5D60: sltiu       $at, $v0, 0x100
    ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x800E5D64: beq         $at, $zero, L_800E5D78
    if (ctx->r1 == 0) {
        // 0x800E5D68: addiu       $t9, $zero, 0xF
        ctx->r25 = ADD32(0, 0XF);
            goto L_800E5D78;
    }
    // 0x800E5D68: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x800E5D6C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800E5D70: b           L_800E5D7C
    // 0x800E5D74: sb          $t6, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r14;
        goto L_800E5D7C;
    // 0x800E5D74: sb          $t6, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r14;
L_800E5D78:
    // 0x800E5D78: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
L_800E5D7C:
    // 0x800E5D7C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800E5D80: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800E5D84: b           L_800E5DC4
    // 0x800E5D88: sh          $t8, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r24;
        goto L_800E5DC4;
    // 0x800E5D88: sh          $t8, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r24;
L_800E5D8C:
    // 0x800E5D8C: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x800E5D90: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800E5D94: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x800E5D98: lw          $t7, 0x604($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X604);
    // 0x800E5D9C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800E5DA0: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
    // 0x800E5DA4: lw          $t6, -0x4($s7)
    ctx->r14 = MEM_W(ctx->r23, -0X4);
    // 0x800E5DA8: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800E5DAC: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800E5DB0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800E5DB4: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800E5DB8: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800E5DBC: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800E5DC0: sh          $t6, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r14;
L_800E5DC4:
    // 0x800E5DC4: srlv        $a3, $ra, $t2
    ctx->r7 = S32(U32(ctx->r31) >> (ctx->r10 & 31));
    // 0x800E5DC8: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800E5DCC: beq         $at, $zero, L_800E5DFC
    if (ctx->r1 == 0) {
        // 0x800E5DD0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800E5DFC;
    }
    // 0x800E5DD0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800E5DD4: sllv        $v0, $t8, $v1
    ctx->r2 = S32(ctx->r24 << (ctx->r3 & 31));
L_800E5DD8:
    // 0x800E5DD8: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x800E5DDC: sll         $t7, $a3, 3
    ctx->r15 = S32(ctx->r7 << 3);
    // 0x800E5DE0: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800E5DE4: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800E5DE8: lw          $t8, 0x4($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X4);
    // 0x800E5DEC: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x800E5DF0: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800E5DF4: bne         $at, $zero, L_800E5DD8
    if (ctx->r1 != 0) {
        // 0x800E5DF8: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_800E5DD8;
    }
    // 0x800E5DF8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
L_800E5DFC:
    // 0x800E5DFC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800E5E00: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800E5E04: and         $t7, $ra, $a3
    ctx->r15 = ctx->r31 & ctx->r7;
    // 0x800E5E08: beq         $t7, $zero, L_800E5E20
    if (ctx->r15 == 0) {
        // 0x800E5E0C: srl         $t6, $a3, 1
        ctx->r14 = S32(U32(ctx->r7) >> 1);
            goto L_800E5E20;
    }
L_800E5E0C:
    // 0x800E5E0C: srl         $t6, $a3, 1
    ctx->r14 = S32(U32(ctx->r7) >> 1);
    // 0x800E5E10: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x800E5E14: and         $t9, $ra, $t6
    ctx->r25 = ctx->r31 & ctx->r14;
    // 0x800E5E18: bne         $t9, $zero, L_800E5E0C
    if (ctx->r25 != 0) {
        // 0x800E5E1C: or          $a3, $t6, $zero
        ctx->r7 = ctx->r14 | 0;
            goto L_800E5E0C;
    }
    // 0x800E5E1C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_800E5E20:
    // 0x800E5E20: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x800E5E24: and         $t8, $ra, $a1
    ctx->r24 = ctx->r31 & ctx->r5;
    // 0x800E5E28: beq         $t8, $v0, L_800E5E58
    if (ctx->r24 == ctx->r2) {
        // 0x800E5E2C: or          $a1, $s6, $zero
        ctx->r5 = ctx->r22 | 0;
            goto L_800E5E58;
    }
    // 0x800E5E2C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
L_800E5E30:
    // 0x800E5E30: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x800E5E34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800E5E38: sllv        $t6, $t7, $t2
    ctx->r14 = S32(ctx->r15 << (ctx->r10 & 31));
    // 0x800E5E3C: lw          $t7, -0x4($t3)
    ctx->r15 = MEM_W(ctx->r11, -0X4);
    // 0x800E5E40: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x800E5E44: and         $t8, $ra, $t9
    ctx->r24 = ctx->r31 & ctx->r25;
    // 0x800E5E48: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800E5E4C: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
    // 0x800E5E50: bne         $t8, $t7, L_800E5E30
    if (ctx->r24 != ctx->r15) {
        // 0x800E5E54: addiu       $t3, $t3, -0x4
        ctx->r11 = ADD32(ctx->r11, -0X4);
            goto L_800E5E30;
    }
    // 0x800E5E54: addiu       $t3, $t3, -0x4
    ctx->r11 = ADD32(ctx->r11, -0X4);
L_800E5E58:
    // 0x800E5E58: bne         $s6, $zero, L_800E5BF8
    if (ctx->r22 != 0) {
        // 0x800E5E5C: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800E5BF8;
    }
    // 0x800E5E5C: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800E5E60: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_800E5E64:
    // 0x800E5E64: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E5E68: slt         $at, $fp, $s4
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800E5E6C: beq         $at, $zero, L_800E5BB4
    if (ctx->r1 == 0) {
        // 0x800E5E70: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800E5BB4;
    }
    // 0x800E5E70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E5E74: sw          $s5, 0x60C($sp)
    MEM_W(0X60C, ctx->r29) = ctx->r21;
L_800E5E78:
    // 0x800E5E78: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x800E5E7C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800E5E80: beq         $t6, $zero, L_800E5E90
    if (ctx->r14 == 0) {
        // 0x800E5E84: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800E5E90;
    }
    // 0x800E5E84: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800E5E88: xori        $v0, $fp, 0x1
    ctx->r2 = ctx->r30 ^ 0X1;
    // 0x800E5E8C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_800E5E90:
    // 0x800E5E90: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800E5E94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E5E98: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800E5E9C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800E5EA0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800E5EA4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800E5EA8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800E5EAC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800E5EB0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800E5EB4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800E5EB8: jr          $ra
    // 0x800E5EBC: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
    return;
    // 0x800E5EBC: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
;}
RECOMP_FUNC void func_80801C5C_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C64: jal         0x80100094
    // 0x80801C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801C6C: sw          $zero, 0x5BC($v0)
    MEM_W(0X5BC, ctx->r2) = 0;
    // 0x80801C70: sw          $zero, 0x5C0($v0)
    MEM_W(0X5C0, ctx->r2) = 0;
    // 0x80801C74: sw          $zero, 0x610($v0)
    MEM_W(0X610, ctx->r2) = 0;
    // 0x80801C78: sw          $zero, 0x614($v0)
    MEM_W(0X614, ctx->r2) = 0;
    // 0x80801C7C: sw          $zero, 0x664($v0)
    MEM_W(0X664, ctx->r2) = 0;
    // 0x80801C80: sw          $zero, 0x668($v0)
    MEM_W(0X668, ctx->r2) = 0;
    // 0x80801C84: sw          $zero, 0x568($v0)
    MEM_W(0X568, ctx->r2) = 0;
    // 0x80801C88: sw          $zero, 0x56C($v0)
    MEM_W(0X56C, ctx->r2) = 0;
    // 0x80801C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C94: jr          $ra
    // 0x80801C98: nop

    return;
    // 0x80801C98: nop

;}
RECOMP_FUNC void func_800CC338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC338: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CC33C: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800CC340: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CC344: lw          $t7, -0x517C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X517C);
    // 0x800CC348: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800CC34C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CC350: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CC354: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CC358: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CC35C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CC360: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CC364: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800CC368: jal         0x800CC4D4
    // 0x800CC36C: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    func_800CC4D4(rdram, ctx);
        goto after_0;
    // 0x800CC36C: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x800CC370: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CC374: beq         $v0, $at, L_800CC384
    if (ctx->r2 == ctx->r1) {
        // 0x800CC378: nop
    
            goto L_800CC384;
    }
    // 0x800CC378: nop

    // 0x800CC37C: b           L_800CC4BC
    // 0x800CC380: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800CC4BC;
    // 0x800CC380: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CC384:
    // 0x800CC384: jal         0x800CB8F0
    // 0x800CC388: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800CB8F0(rdram, ctx);
        goto after_1;
    // 0x800CC388: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800CC38C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800CC390: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800CC394: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC398: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800CC39C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800CC3A0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800CC3A4: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x800CC3A8: lh          $t0, 0xE($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XE);
    // 0x800CC3AC: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800CC3B0: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800CC3B4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800CC3B8: nop

    // 0x800CC3BC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CC3C0: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800CC3C4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800CC3C8: nop

    // 0x800CC3CC: bc1f        L_800CC410
    if (!c1cs) {
        // 0x800CC3D0: nop
    
            goto L_800CC410;
    }
    // 0x800CC3D0: nop

    // 0x800CC3D4: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800CC3D8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800CC3DC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800CC3E0: nop

    // 0x800CC3E4: bc1f        L_800CC410
    if (!c1cs) {
        // 0x800CC3E8: nop
    
            goto L_800CC410;
    }
    // 0x800CC3E8: nop

    // 0x800CC3EC: jal         0x800EFC7C
    // 0x800CC3F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_2;
    // 0x800CC3F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800CC3F4: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC3F8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CC3FC: nop

    // 0x800CC400: bc1f        L_800CC410
    if (!c1cs) {
        // 0x800CC404: nop
    
            goto L_800CC410;
    }
    // 0x800CC404: nop

    // 0x800CC408: b           L_800CC4BC
    // 0x800CC40C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
        goto L_800CC4BC;
    // 0x800CC40C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_800CC410:
    // 0x800CC410: jal         0x800CB910
    // 0x800CC414: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800CB910(rdram, ctx);
        goto after_3;
    // 0x800CC414: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x800CC418: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800CC41C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800CC420: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800CC424: beql        $at, $zero, L_800CC4BC
    if (ctx->r1 == 0) {
        // 0x800CC428: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800CC4BC;
    }
    goto skip_0;
    // 0x800CC428: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x800CC42C: lh          $t2, 0xE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE);
L_800CC430:
    // 0x800CC430: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CC434: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC438: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800CC43C: nop

    // 0x800CC440: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CC444: sub.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800CC448: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800CC44C: nop

    // 0x800CC450: bc1fl       L_800CC4AC
    if (!c1cs) {
        // 0x800CC454: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC4AC;
    }
    goto skip_1;
    // 0x800CC454: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_1:
    // 0x800CC458: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800CC45C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC460: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800CC464: nop

    // 0x800CC468: bc1fl       L_800CC4AC
    if (!c1cs) {
        // 0x800CC46C: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC4AC;
    }
    goto skip_2;
    // 0x800CC46C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_2:
    // 0x800CC470: jal         0x800EFC7C
    // 0x800CC474: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_4;
    // 0x800CC474: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800CC478: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC47C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800CC480: nop

    // 0x800CC484: bc1fl       L_800CC4AC
    if (!c1cs) {
        // 0x800CC488: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC4AC;
    }
    goto skip_3;
    // 0x800CC488: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_3:
    // 0x800CC48C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800CC490: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800CC494: subu        $v0, $s0, $t3
    ctx->r2 = SUB32(ctx->r16, ctx->r11);
    // 0x800CC498: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CC49C: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC4A0: b           L_800CC4C0
    // 0x800CC4A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800CC4C0;
    // 0x800CC4A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CC4A8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800CC4AC:
    // 0x800CC4AC: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800CC4B0: bnel        $at, $zero, L_800CC430
    if (ctx->r1 != 0) {
        // 0x800CC4B4: lh          $t2, 0xE($s0)
        ctx->r10 = MEM_H(ctx->r16, 0XE);
            goto L_800CC430;
    }
    goto skip_4;
    // 0x800CC4B4: lh          $t2, 0xE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE);
    skip_4:
    // 0x800CC4B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CC4BC:
    // 0x800CC4BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800CC4C0:
    // 0x800CC4C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CC4C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC4C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CC4CC: jr          $ra
    // 0x800CC4D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800CC4D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800D2E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2E4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D2E50: addiu       $v0, $v0, -0x4CA0
    ctx->r2 = ADD32(ctx->r2, -0X4CA0);
    // 0x800D2E54: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800D2E58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2E60: beql        $a0, $zero, L_800D2E80
    if (ctx->r4 == 0) {
        // 0x800D2E64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D2E80;
    }
    goto skip_0;
    // 0x800D2E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D2E68: jal         0x8001B084
    // 0x800D2E6C: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800D2E6C: nop

    after_0:
    // 0x800D2E70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D2E74: addiu       $v0, $v0, -0x4CA0
    ctx->r2 = ADD32(ctx->r2, -0X4CA0);
    // 0x800D2E78: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D2E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D2E80:
    // 0x800D2E80: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D2E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2E88: jr          $ra
    // 0x800D2E8C: nop

    return;
    // 0x800D2E8C: nop

;}
RECOMP_FUNC void chtntmineshoot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E04: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2204, 0X2690) << 16);
    // 0x80800E08: jr          $ra
    // 0x80800E0C: addiu       $v0, $v0, 0x2690
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2204, 0X2690));
    return;
    // 0x80800E0C: addiu       $v0, $v0, 0x2690
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2204, 0X2690));
;}
RECOMP_FUNC void _fxripple_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889B8: syscall     715
    recomp_syscall_handler(rdram, ctx, 0x800889B8);
    return;
    // 0x800889BC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808004BC_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004C4: jal         0x8008CABC
    // 0x808004C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808004D0: jal         0x8080040C
    // 0x808004D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8080040C_bsbanswim(rdram, ctx);
        goto after_1;
    // 0x808004D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808004D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808004DC: jal         0x8008B1BC
    // 0x808004E0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x808004E0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x808004E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004EC: jr          $ra
    // 0x808004F0: nop

    return;
    // 0x808004F0: nop

;}
RECOMP_FUNC void chfiregen_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080102C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X19FC) << 16);
    // 0x80801030: jr          $ra
    // 0x80801034: addiu       $v0, $v0, 0x19FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X19FC));
    return;
    // 0x80801034: addiu       $v0, $v0, 0x19FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X19FC));
;}
RECOMP_FUNC void func_808018D4_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808018D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808018E0: jal         0x800EFD24
    // 0x808018E4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x808018E4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808018E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808018EC: jal         0x80102D78
    // 0x808018F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x808018F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x808018F4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x808018F8: swc1        $f0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f0.u32l;
    // 0x808018FC: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80801900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801904: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801908: jr          $ra
    // 0x8080190C: nop

    return;
    // 0x8080190C: nop

;}
RECOMP_FUNC void func_80800114_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080011C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800120: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800124: jal         0x80095738
    // 0x80800128: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x80800128: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_0:
    // 0x8080012C: bne         $v0, $zero, L_80800218
    if (ctx->r2 != 0) {
        // 0x80800130: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800218;
    }
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80095738
    // 0x80800138: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x80800138: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_1:
    // 0x8080013C: bnel        $v0, $zero, L_8080021C
    if (ctx->r2 != 0) {
        // 0x80800140: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080021C;
    }
    goto skip_0;
    // 0x80800140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800144: jal         0x800C6E38
    // 0x80800148: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x80800148: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_2:
    // 0x8080014C: beql        $v0, $zero, L_8080021C
    if (ctx->r2 == 0) {
        // 0x80800150: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080021C;
    }
    goto skip_1;
    // 0x80800150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800154: lw          $t6, 0x90($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X90);
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800160: lwc1        $f2, 0x18($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80800164: jal         0x800919F4
    // 0x80800168: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    bakey_held(rdram, ctx);
        goto after_3;
    // 0x80800168: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8080016C: beq         $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x80800170: lwc1        $f2, 0x24($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8080019C;
    }
    // 0x80800170: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800174: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800178: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080017C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800180: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80800184: nop

    // 0x80800188: bc1fl       L_808001A0
    if (!c1cs) {
        // 0x8080018C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001A0;
    }
    goto skip_2;
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800190: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800194: nop

    // 0x80800198: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_8080019C:
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001A0:
    // 0x808001A0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x808001A4: jal         0x800919F4
    // 0x808001A8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    bakey_held(rdram, ctx);
        goto after_4;
    // 0x808001A8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x808001AC: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001B0: lwc1        $f2, 0x24($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
            goto L_808001DC;
    }
    // 0x808001B0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808001B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(532, 0X1090) << 16);
    // 0x808001B8: lwc1        $f8, 0x1090($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(532, 0X1090));
    // 0x808001BC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808001C0: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x808001C4: nop

    // 0x808001C8: bc1fl       L_808001E0
    if (!c1cs) {
        // 0x808001CC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808001E0;
    }
    goto skip_3;
    // 0x808001CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_3:
    // 0x808001D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001D4: nop

    // 0x808001D8: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
L_808001DC:
    // 0x808001DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808001E0:
    // 0x808001E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001E4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x808001E8: mul.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x808001EC: jal         0x800139F8
    // 0x808001F0: nop

    func_800139F8(rdram, ctx);
        goto after_5;
    // 0x808001F0: nop

    after_5:
    // 0x808001F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(532, 0X1094) << 16);
    // 0x808001F8: lwc1        $f18, 0x1094($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(532, 0X1094));
    // 0x808001FC: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800208: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080020C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800210: jal         0x808000DC
    // 0x80800214: nop

    func_808000DC_bafpctrl(rdram, ctx);
        goto after_6;
    // 0x80800214: nop

    after_6:
L_80800218:
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080021C:
    // 0x8080021C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800220: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800224: jr          $ra
    // 0x80800228: nop

    return;
    // 0x80800228: nop

;}
RECOMP_FUNC void func_800BDB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDB9C: bgez        $a0, L_800BDBB0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800BDBA0: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800BDBB0;
    }
    // 0x800BDBA0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BDBA4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BDBA8: jr          $ra
    // 0x800BDBAC: addiu       $v0, $v1, -0x7BBC
    ctx->r2 = ADD32(ctx->r3, -0X7BBC);
    return;
    // 0x800BDBAC: addiu       $v0, $v1, -0x7BBC
    ctx->r2 = ADD32(ctx->r3, -0X7BBC);
L_800BDBB0:
    // 0x800BDBB0: lw          $t7, -0x7BF0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7BF0);
    // 0x800BDBB4: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BDBB8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800BDBBC: jr          $ra
    // 0x800BDBC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800BDBC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8080003C_bssilowait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800040: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080004C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x80800050: jal         0x8008CBB0
    // 0x80800054: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    baanim_playForDuration_loop(rdram, ctx);
        goto after_0;
    // 0x80800054: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    after_0:
    // 0x80800058: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8080005C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800068: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080006C: jal         0x8009FFD8
    // 0x80800070: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800070: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: jal         0x8009B9B0
    // 0x8080007C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080007C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: jal         0x8009BA9C
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_3;
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800090: jal         0x8009BCB4
    // 0x80800094: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_4;
    // 0x80800094: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x8009BCC4
    // 0x808000A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_5;
    // 0x808000A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x80091E48
    // 0x808000AC: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    func_80091E48(rdram, ctx);
        goto after_6;
    // 0x808000AC: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_6:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80092880
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092880(rdram, ctx);
        goto after_7;
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808000BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_800A2534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2534: lw          $t6, 0xB4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB4);
    // 0x800A2538: jr          $ra
    // 0x800A253C: sb          $zero, 0x3($t6)
    MEM_B(0X3, ctx->r14) = 0;
    return;
    // 0x800A253C: sb          $zero, 0x3($t6)
    MEM_B(0X3, ctx->r14) = 0;
;}
RECOMP_FUNC void func_800F7D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7D38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7D3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F7D40: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7D44: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7D48: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7D4C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7D54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F7D58: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F7D5C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F7D60: jal         0x8009AD44
    // 0x800F7D64: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD44(rdram, ctx);
        goto after_0;
    // 0x800F7D64: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7D68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7D6C: jal         0x8009ACF4
    // 0x800F7D70: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8009ACF4(rdram, ctx);
        goto after_1;
    // 0x800F7D70: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800F7D74: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7D78: jal         0x8009E7C8
    // 0x800F7D7C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F7D7C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800F7D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7D84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7D88: jr          $ra
    // 0x800F7D8C: nop

    return;
    // 0x800F7D8C: nop

;}
RECOMP_FUNC void func_80800C88_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800C8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C90: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800C94: jal         0x80802484
    // 0x80800C98: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80800C98: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800C9C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800CA0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800CA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800CA8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80800CAC: jal         0x80800978
    // 0x80800CB0: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_80800978_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80800CB0: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800CB4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800CB8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800CBC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800CC0: lbu         $a1, 0x2B($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X2B);
    // 0x80800CC4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800CC8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800CCC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800CD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800CD4: jal         0x800E0AFC
    // 0x80800CD8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_2;
    // 0x80800CD8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80800CDC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800CE0: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800CE4: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800CE8: lbu         $a1, 0x2F($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X2F);
    // 0x80800CEC: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80800CF0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800CF4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80800CF8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800CFC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800D00: jal         0x800E0AFC
    // 0x80800D04: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x80800D04: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80800D08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800D10: jr          $ra
    // 0x80800D14: nop

    return;
    // 0x80800D14: nop

;}
RECOMP_FUNC void func_800D1B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1B34: slti        $at, $a0, 0x4BB
    ctx->r1 = SIGNED(ctx->r4) < 0X4BB ? 1 : 0;
    // 0x800D1B38: bne         $at, $zero, L_800D1B80
    if (ctx->r1 != 0) {
        // 0x800D1B3C: addiu       $at, $zero, 0x4D7
        ctx->r1 = ADD32(0, 0X4D7);
            goto L_800D1B80;
    }
    // 0x800D1B3C: addiu       $at, $zero, 0x4D7
    ctx->r1 = ADD32(0, 0X4D7);
    // 0x800D1B40: beq         $a0, $at, L_800D1C14
    if (ctx->r4 == ctx->r1) {
        // 0x800D1B44: addiu       $at, $zero, 0x4E2
        ctx->r1 = ADD32(0, 0X4E2);
            goto L_800D1C14;
    }
    // 0x800D1B44: addiu       $at, $zero, 0x4E2
    ctx->r1 = ADD32(0, 0X4E2);
    // 0x800D1B48: beq         $a0, $at, L_800D1BFC
    if (ctx->r4 == ctx->r1) {
        // 0x800D1B4C: addiu       $at, $zero, 0x4E3
        ctx->r1 = ADD32(0, 0X4E3);
            goto L_800D1BFC;
    }
    // 0x800D1B4C: addiu       $at, $zero, 0x4E3
    ctx->r1 = ADD32(0, 0X4E3);
    // 0x800D1B50: beq         $a0, $at, L_800D1C04
    if (ctx->r4 == ctx->r1) {
        // 0x800D1B54: addiu       $at, $zero, 0x4E4
        ctx->r1 = ADD32(0, 0X4E4);
            goto L_800D1C04;
    }
    // 0x800D1B54: addiu       $at, $zero, 0x4E4
    ctx->r1 = ADD32(0, 0X4E4);
    // 0x800D1B58: beq         $a0, $at, L_800D1C0C
    if (ctx->r4 == ctx->r1) {
        // 0x800D1B5C: addiu       $at, $zero, 0x515
        ctx->r1 = ADD32(0, 0X515);
            goto L_800D1C0C;
    }
    // 0x800D1B5C: addiu       $at, $zero, 0x515
    ctx->r1 = ADD32(0, 0X515);
    // 0x800D1B60: beq         $a0, $at, L_800D1C1C
    if (ctx->r4 == ctx->r1) {
        // 0x800D1B64: addiu       $at, $zero, 0x516
        ctx->r1 = ADD32(0, 0X516);
            goto L_800D1C1C;
    }
    // 0x800D1B64: addiu       $at, $zero, 0x516
    ctx->r1 = ADD32(0, 0X516);
    // 0x800D1B68: beq         $a0, $at, L_800D1C1C
    if (ctx->r4 == ctx->r1) {
        // 0x800D1B6C: addiu       $at, $zero, 0x523
        ctx->r1 = ADD32(0, 0X523);
            goto L_800D1C1C;
    }
    // 0x800D1B6C: addiu       $at, $zero, 0x523
    ctx->r1 = ADD32(0, 0X523);
    // 0x800D1B70: beq         $a0, $at, L_800D1BD4
    if (ctx->r4 == ctx->r1) {
        // 0x800D1B74: nop
    
            goto L_800D1BD4;
    }
    // 0x800D1B74: nop

    // 0x800D1B78: b           L_800D1C30
    // 0x800D1B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D1C30;
    // 0x800D1B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D1B80:
    // 0x800D1B80: addiu       $at, $zero, 0x1D9
    ctx->r1 = ADD32(0, 0X1D9);
    // 0x800D1B84: beq         $a0, $at, L_800D1BDC
    if (ctx->r4 == ctx->r1) {
        // 0x800D1B88: addiu       $at, $zero, 0x29F
        ctx->r1 = ADD32(0, 0X29F);
            goto L_800D1BDC;
    }
    // 0x800D1B88: addiu       $at, $zero, 0x29F
    ctx->r1 = ADD32(0, 0X29F);
    // 0x800D1B8C: beq         $a0, $at, L_800D1BCC
    if (ctx->r4 == ctx->r1) {
        // 0x800D1B90: addiu       $at, $zero, 0x3CA
        ctx->r1 = ADD32(0, 0X3CA);
            goto L_800D1BCC;
    }
    // 0x800D1B90: addiu       $at, $zero, 0x3CA
    ctx->r1 = ADD32(0, 0X3CA);
    // 0x800D1B94: beq         $a0, $at, L_800D1BE4
    if (ctx->r4 == ctx->r1) {
        // 0x800D1B98: addiu       $at, $zero, 0x3CB
        ctx->r1 = ADD32(0, 0X3CB);
            goto L_800D1BE4;
    }
    // 0x800D1B98: addiu       $at, $zero, 0x3CB
    ctx->r1 = ADD32(0, 0X3CB);
    // 0x800D1B9C: beq         $a0, $at, L_800D1BEC
    if (ctx->r4 == ctx->r1) {
        // 0x800D1BA0: addiu       $at, $zero, 0x40D
        ctx->r1 = ADD32(0, 0X40D);
            goto L_800D1BEC;
    }
    // 0x800D1BA0: addiu       $at, $zero, 0x40D
    ctx->r1 = ADD32(0, 0X40D);
    // 0x800D1BA4: beq         $a0, $at, L_800D1BF4
    if (ctx->r4 == ctx->r1) {
        // 0x800D1BA8: addiu       $at, $zero, 0x481
        ctx->r1 = ADD32(0, 0X481);
            goto L_800D1BF4;
    }
    // 0x800D1BA8: addiu       $at, $zero, 0x481
    ctx->r1 = ADD32(0, 0X481);
    // 0x800D1BAC: beq         $a0, $at, L_800D1BF4
    if (ctx->r4 == ctx->r1) {
        // 0x800D1BB0: addiu       $at, $zero, 0x4B7
        ctx->r1 = ADD32(0, 0X4B7);
            goto L_800D1BF4;
    }
    // 0x800D1BB0: addiu       $at, $zero, 0x4B7
    ctx->r1 = ADD32(0, 0X4B7);
    // 0x800D1BB4: beq         $a0, $at, L_800D1C24
    if (ctx->r4 == ctx->r1) {
        // 0x800D1BB8: addiu       $at, $zero, 0x4BA
        ctx->r1 = ADD32(0, 0X4BA);
            goto L_800D1C24;
    }
    // 0x800D1BB8: addiu       $at, $zero, 0x4BA
    ctx->r1 = ADD32(0, 0X4BA);
    // 0x800D1BBC: beq         $a0, $at, L_800D1C14
    if (ctx->r4 == ctx->r1) {
        // 0x800D1BC0: nop
    
            goto L_800D1C14;
    }
    // 0x800D1BC0: nop

    // 0x800D1BC4: b           L_800D1C30
    // 0x800D1BC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D1C30;
    // 0x800D1BC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D1BCC:
    // 0x800D1BCC: jr          $ra
    // 0x800D1BD0: addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    return;
    // 0x800D1BD0: addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
L_800D1BD4:
    // 0x800D1BD4: jr          $ra
    // 0x800D1BD8: addiu       $v0, $zero, 0x54
    ctx->r2 = ADD32(0, 0X54);
    return;
    // 0x800D1BD8: addiu       $v0, $zero, 0x54
    ctx->r2 = ADD32(0, 0X54);
L_800D1BDC:
    // 0x800D1BDC: jr          $ra
    // 0x800D1BE0: addiu       $v0, $zero, 0x4F
    ctx->r2 = ADD32(0, 0X4F);
    return;
    // 0x800D1BE0: addiu       $v0, $zero, 0x4F
    ctx->r2 = ADD32(0, 0X4F);
L_800D1BE4:
    // 0x800D1BE4: jr          $ra
    // 0x800D1BE8: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    return;
    // 0x800D1BE8: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
L_800D1BEC:
    // 0x800D1BEC: jr          $ra
    // 0x800D1BF0: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    return;
    // 0x800D1BF0: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
L_800D1BF4:
    // 0x800D1BF4: jr          $ra
    // 0x800D1BF8: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    return;
    // 0x800D1BF8: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
L_800D1BFC:
    // 0x800D1BFC: jr          $ra
    // 0x800D1C00: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    return;
    // 0x800D1C00: addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
L_800D1C04:
    // 0x800D1C04: jr          $ra
    // 0x800D1C08: addiu       $v0, $zero, 0x4A
    ctx->r2 = ADD32(0, 0X4A);
    return;
    // 0x800D1C08: addiu       $v0, $zero, 0x4A
    ctx->r2 = ADD32(0, 0X4A);
L_800D1C0C:
    // 0x800D1C0C: jr          $ra
    // 0x800D1C10: addiu       $v0, $zero, 0x4E
    ctx->r2 = ADD32(0, 0X4E);
    return;
    // 0x800D1C10: addiu       $v0, $zero, 0x4E
    ctx->r2 = ADD32(0, 0X4E);
L_800D1C14:
    // 0x800D1C14: jr          $ra
    // 0x800D1C18: addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
    return;
    // 0x800D1C18: addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
L_800D1C1C:
    // 0x800D1C1C: jr          $ra
    // 0x800D1C20: addiu       $v0, $zero, 0x52
    ctx->r2 = ADD32(0, 0X52);
    return;
    // 0x800D1C20: addiu       $v0, $zero, 0x52
    ctx->r2 = ADD32(0, 0X52);
L_800D1C24:
    // 0x800D1C24: jr          $ra
    // 0x800D1C28: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    return;
    // 0x800D1C28: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // 0x800D1C2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D1C30:
    // 0x800D1C30: jr          $ra
    // 0x800D1C34: nop

    return;
    // 0x800D1C34: nop

;}
