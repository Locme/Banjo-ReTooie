#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8011001C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011001C: jr          $ra
    // 0x80110020: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    return;
    // 0x80110020: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
;}
RECOMP_FUNC void idtwinklea_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080002C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800030: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800034: jal         0x80088F00
    // 0x80800038: addiu       $a0, $a2, -0xC8
    ctx->r4 = ADD32(ctx->r6, -0XC8);
    _idworld_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a0, $a2, -0xC8
    ctx->r4 = ADD32(ctx->r6, -0XC8);
    after_0:
    // 0x8080003C: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x80800040: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800068;
    }
    // 0x80800040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800044: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800048: jal         0x80088E18
    // 0x8080004C: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    _idtwinkle_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080004C: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80800050: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800054: addiu       $a2, $a2, -0x7148
    ctx->r6 = ADD32(ctx->r6, -0X7148);
    // 0x80800058: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080005C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800060: jal         0x80088660
    // 0x80800064: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800064: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80800068:
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_80800700_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800700: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800708: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080070C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800710: jal         0x8008A110
    // 0x80800714: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800714: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800718: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080071C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800720: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800724: beq         $a1, $at, L_80800750
    if (ctx->r5 == ctx->r1) {
        // 0x80800728: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800750;
    }
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080072C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80800730: beq         $a1, $at, L_80800788
    if (ctx->r5 == ctx->r1) {
        // 0x80800734: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80800788;
    }
    // 0x80800734: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80800738: beq         $a1, $at, L_808007D4
    if (ctx->r5 == ctx->r1) {
        // 0x8080073C: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_808007D4;
    }
    // 0x8080073C: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80800740: beq         $a1, $at, L_8080076C
    if (ctx->r5 == ctx->r1) {
        // 0x80800744: nop
    
            goto L_8080076C;
    }
    // 0x80800744: nop

    // 0x80800748: b           L_80800810
    // 0x8080074C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800810;
    // 0x8080074C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800750:
    // 0x80800750: jal         0x8010A570
    // 0x80800754: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80800754: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800758: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080075C: jal         0x8008A148
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800764: b           L_80800810
    // 0x80800768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800810;
    // 0x80800768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080076C:
    // 0x8080076C: jal         0x8008A148
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800778: jal         0x8008A128
    // 0x8080077C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    _sucoaster_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x8080077C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_4:
    // 0x80800780: b           L_80800810
    // 0x80800784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800810;
    // 0x80800784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800788:
    // 0x80800788: jal         0x8008A148
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800790: jal         0x8010A570
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800798: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x8080079C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808007A0: bltzl       $t8, L_808007C8
    if (SIGNED(ctx->r24) < 0) {
        // 0x808007A4: lbu         $t0, 0x65($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X65);
            goto L_808007C8;
    }
    goto skip_0;
    // 0x808007A4: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x808007A8: jal         0x80800850
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800850_ch2dbaddy(rdram, ctx);
        goto after_7;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808007B0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007BC: jal         0x801032B0
    // 0x808007C0: lhu         $a1, 0x6($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X6);
    func_801032B0(rdram, ctx);
        goto after_8;
    // 0x808007C0: lhu         $a1, 0x6($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X6);
    after_8:
    // 0x808007C4: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
L_808007C8:
    // 0x808007C8: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x808007CC: b           L_8080080C
    // 0x808007D0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_8080080C;
    // 0x808007D0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_808007D4:
    // 0x808007D4: jal         0x8008A148
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808007DC: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E4: ori         $t5, $t3, 0x1
    ctx->r13 = ctx->r11 | 0X1;
    // 0x808007E8: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x808007EC: andi        $t6, $t5, 0xEF
    ctx->r14 = ctx->r13 & 0XEF;
    // 0x808007F0: jal         0x8010A570
    // 0x808007F4: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    func_8010A570(rdram, ctx);
        goto after_10;
    // 0x808007F4: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    after_10:
    // 0x808007F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1356, 0XAE4) << 16);
    // 0x808007FC: addiu       $a2, $a2, 0xAE4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1356, 0XAE4));
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800804: jal         0x80089D18
    // 0x80800808: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800808: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_11:
L_8080080C:
    // 0x8080080C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800810:
    // 0x80800810: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800818: jr          $ra
    // 0x8080081C: nop

    return;
    // 0x8080081C: nop

;}
RECOMP_FUNC void func_808031D0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808031D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808031D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808031D8: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x808031DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808031E0: sh          $zero, 0xE0($v0)
    MEM_H(0XE0, ctx->r2) = 0;
    // 0x808031E4: jal         0x800A0D94
    // 0x808031E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A0D94(rdram, ctx);
        goto after_0;
    // 0x808031E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808031EC: jal         0x80807C8C
    // 0x808031F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808031F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808031F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808031F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808031FC: jr          $ra
    // 0x80803200: nop

    return;
    // 0x80803200: nop

;}
RECOMP_FUNC void func_80800194_chpumproomswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080019C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001A4: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x808001A8: jal         0x800DA298
    // 0x808001AC: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808001AC: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_0:
    // 0x808001B0: bnel        $v0, $zero, L_808001CC
    if (ctx->r2 != 0) {
        // 0x808001B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808001CC;
    }
    goto skip_0;
    // 0x808001B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808001B8: jal         0x80088840
    // 0x808001BC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x808001BC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x808001C0: beql        $v0, $zero, L_808001D8
    if (ctx->r2 == 0) {
        // 0x808001C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001D8;
    }
    goto skip_1;
    // 0x808001C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808001C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808001CC:
    // 0x808001CC: jal         0x80101FDC
    // 0x808001D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808001D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808001D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001D8:
    // 0x808001D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001DC: jr          $ra
    // 0x808001E0: nop

    return;
    // 0x808001E0: nop

;}
RECOMP_FUNC void _bababykaz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084470: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x80084470);
    return;
    // 0x80084474: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80802400_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802400: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80802404: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80802408: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8080240C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80802410: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80802414: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80802418: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080241C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80802420: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80802424: lw          $a0, 0x18($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X18);
    // 0x80802428: srl         $t7, $a0, 28
    ctx->r15 = S32(U32(ctx->r4) >> 28);
    // 0x8080242C: jal         0x8008A240
    // 0x80802430: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80802430: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x80802434: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80802438: jal         0x80802760
    // 0x8080243C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    func_80802760_sucoaster(rdram, ctx);
        goto after_1;
    // 0x8080243C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_1:
    // 0x80802440: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802444: jal         0x800F57F0
    // 0x80802448: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800F57F0(rdram, ctx);
        goto after_2;
    // 0x80802448: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x8080244C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80802450: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80802454: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80802458: lh          $t9, 0xC($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XC);
    // 0x8080245C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80802460: lhu         $t1, 0x4A($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4A);
    // 0x80802464: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80802468: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080246C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80802470: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802474: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80802478: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8080247C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80802480: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802484: bgez        $t1, L_80802498
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80802488: nop
    
            goto L_80802498;
    }
    // 0x80802488: nop

    // 0x8080248C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802490: nop

    // 0x80802494: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80802498:
    // 0x80802498: mul.s       $f24, $f10, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8080249C: jal         0x800D8FF8
    // 0x808024A0: lwc1        $f20, 0x24($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X24);
    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x808024A0: lwc1        $f20, 0x24($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X24);
    after_3:
    // 0x808024A4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808024A8: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x808024AC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808024B0: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x808024B4: nop

    // 0x808024B8: bc1fl       L_80802500
    if (!c1cs) {
        // 0x808024BC: lwc1        $f16, 0x50($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
            goto L_80802500;
    }
    goto skip_0;
    // 0x808024BC: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x808024C0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808024C4: nop

L_808024C8:
    // 0x808024C8: mul.s       $f6, $f26, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x808024CC: jal         0x80107C00
    // 0x808024D0: add.s       $f24, $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f6.fl;
    func_80107C00(rdram, ctx);
        goto after_4;
    // 0x808024D0: add.s       $f24, $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f6.fl;
    after_4:
    // 0x808024D4: mul.s       $f8, $f0, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x808024D8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808024DC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x808024E0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808024E4: jal         0x800F15F8
    // 0x808024E8: nop

    func_800F15F8(rdram, ctx);
        goto after_5;
    // 0x808024E8: nop

    after_5:
    // 0x808024EC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x808024F0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808024F4: bc1t        L_808024C8
    if (c1cs) {
        // 0x808024F8: nop
    
            goto L_808024C8;
    }
    // 0x808024F8: nop

    // 0x808024FC: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
L_80802500:
    // 0x80802500: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80802504: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80802508: add.s       $f24, $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f16.fl;
    // 0x8080250C: jal         0x800EFC7C
    // 0x80802510: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFC7C(rdram, ctx);
        goto after_6;
    // 0x80802510: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_6:
    // 0x80802514: mul.s       $f4, $f24, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80802518: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8080251C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802520: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80802524: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80802528: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8080252C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80802530: nop

    // 0x80802534: bc1fl       L_80802544
    if (!c1cs) {
        // 0x80802538: ldc1        $f26, 0x28($sp)
        CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
            goto L_80802544;
    }
    goto skip_1;
    // 0x80802538: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    skip_1:
    // 0x8080253C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802540: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
L_80802544:
    // 0x80802544: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80802548: jr          $ra
    // 0x8080254C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8080254C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80802F30_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802F38: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3D18) << 16);
    // 0x80802F3C: addiu       $a2, $a2, 0x3D18
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3D18));
    // 0x80802F40: jal         0x80089D18
    // 0x80802F44: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80802F44: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80802F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802F50: jr          $ra
    // 0x80802F54: nop

    return;
    // 0x80802F54: nop

;}
RECOMP_FUNC void chevilmumbo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803620: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1676, 0X44F0) << 16);
    // 0x80803624: jr          $ra
    // 0x80803628: addiu       $v0, $v0, 0x44F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1676, 0X44F0));
    return;
    // 0x80803628: addiu       $v0, $v0, 0x44F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1676, 0X44F0));
;}
RECOMP_FUNC void func_808004F8_chtntbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808004FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800500: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800504: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800508: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8080050C: jal         0x801084B0
    // 0x80800510: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80800510: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x80800514: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800518: jal         0x8010D254
    // 0x8080051C: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x8080051C: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    after_1:
    // 0x80800520: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800524: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800528: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080052C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800530: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80800534: jal         0x80103EAC
    // 0x80800538: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80103EAC(rdram, ctx);
        goto after_2;
    // 0x80800538: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_2:
    // 0x8080053C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800540: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800544: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80800548: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080054C: jal         0x800EFB8C
    // 0x80800550: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EFB8C(rdram, ctx);
        goto after_3;
    // 0x80800550: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800554: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800558: jal         0x800F0E00
    // 0x8080055C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_4;
    // 0x8080055C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_4:
    // 0x80800560: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800564: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800568: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x8080056C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800570: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800574: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800580: c.le.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
    // 0x80800584: nop

    // 0x80800588: bc1fl       L_808005A0
    if (!c1cs) {
        // 0x8080058C: swc1        $f2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
            goto L_808005A0;
    }
    goto skip_0;
    // 0x8080058C: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    skip_0:
    // 0x80800590: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800594: nop

    // 0x80800598: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8080059C: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
L_808005A0:
    // 0x808005A0: jal         0x80102D78
    // 0x808005A4: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    func_80102D78(rdram, ctx);
        goto after_5;
    // 0x808005A4: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x808005A8: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808005AC: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808005B0: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808005B4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x808005B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1892, 0X8C0) << 16);
    // 0x808005BC: lwc1        $f8, 0x8C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1892, 0X8C0));
    // 0x808005C0: add.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x808005C4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808005C8: jal         0x8002DCA0
    // 0x808005CC: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x808005CC: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    after_6:
    // 0x808005D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808005D4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808005D8: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x808005DC: jal         0x800EEC30
    // 0x808005E0: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    func_800EEC30(rdram, ctx);
        goto after_7;
    // 0x808005E0: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    after_7:
    // 0x808005E4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808005E8: jal         0x80089CD8
    // 0x808005EC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808005EC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_8:
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F4: jal         0x80089CE8
    // 0x808005F8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x808005F8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x808005FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1892, 0XA78) << 16);
    // 0x80800600: addiu       $a2, $a2, 0xA78
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1892, 0XA78));
    // 0x80800604: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800608: jal         0x80089D18
    // 0x8080060C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x8080060C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x80800610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800614: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800618: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8080061C: jr          $ra
    // 0x80800620: nop

    return;
    // 0x80800620: nop

;}
RECOMP_FUNC void chcrashmat_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2440, 0XA0) << 16);
    // 0x80800094: jr          $ra
    // 0x80800098: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2440, 0XA0));
    return;
    // 0x80800098: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2440, 0XA0));
    // 0x8080009C: nop

;}
RECOMP_FUNC void func_80800274_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080027C: jal         0x80085808
    // 0x80800280: addiu       $a1, $zero, 0xA4B
    ctx->r5 = ADD32(0, 0XA4B);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800280: addiu       $a1, $zero, 0xA4B
    ctx->r5 = ADD32(0, 0XA4B);
    after_0:
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

;}
RECOMP_FUNC void subaddieitem_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080005C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80800060: jal         0x80090658
    // 0x80800064: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_0;
    // 0x80800064: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800068: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080006C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800070: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800074: sb          $v0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r2;
    // 0x80800078: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8080007C: addiu       $a0, $a1, 0x8
    ctx->r4 = ADD32(ctx->r5, 0X8);
    // 0x80800080: jal         0x8008A020
    // 0x80800084: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800084: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    after_1:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080008C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void vector_at(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B28CC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800B28D0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800B28D4: multu       $a1, $t7
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B28D8: mflo        $t8
    ctx->r24 = lo;
    // 0x800B28DC: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x800B28E0: jr          $ra
    // 0x800B28E4: nop

    return;
    // 0x800B28E4: nop

;}
RECOMP_FUNC void _bapackctrl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084768: syscall     119
    recomp_syscall_handler(rdram, ctx, 0x80084768);
    return;
    // 0x8008476C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F4A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4A58: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F4A5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4A60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4A64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4A6C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4A70: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800F4A74: jal         0x80084858
    // 0x800F4A78: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _badrone_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x800F4A78: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4A80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4A84: jr          $ra
    // 0x800F4A88: nop

    return;
    // 0x800F4A88: nop

;}
RECOMP_FUNC void func_808007E4_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808007EC: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x808007F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007F4: addu        $a0, $a1, $at
    ctx->r4 = ADD32(ctx->r5, ctx->r1);
    // 0x808007F8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808007FC: jal         0x8001E210
    // 0x80800800: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x80800800: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800804: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800808: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8080080C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800810: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80800814: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80800818: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8080081C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80800820: sh          $t7, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r15;
    // 0x80800824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800828: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void plsu_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: jal         0x808000B8
    // 0x8080013C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    plsu_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080013C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80800140: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800144: bne         $v0, $at, L_80800154
    if (ctx->r2 != ctx->r1) {
        // 0x80800148: nop
    
            goto L_80800154;
    }
    // 0x80800148: nop

    // 0x8080014C: b           L_80800174
    // 0x80800150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800174;
    // 0x80800150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800154:
    // 0x80800154: jal         0x808000B8
    // 0x80800158: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    plsu_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800158: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x8080015C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800160: bnel        $v0, $at, L_80800174
    if (ctx->r2 != ctx->r1) {
        // 0x80800164: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800174;
    }
    goto skip_0;
    // 0x80800164: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800168: b           L_80800174
    // 0x8080016C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800174;
    // 0x8080016C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800174:
    // 0x80800174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void baeggsetup_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800690: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800694: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(504, 0X834) << 16);
    // 0x80800698: lwc1        $f4, 0x834($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X834));
    // 0x8080069C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808006A4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x808006A8: jal         0x80094510
    // 0x808006AC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_80094510(rdram, ctx);
        goto after_0;
    // 0x808006AC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808006B0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x808006B4: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x808006B8: beq         $at, $zero, L_80800724
    if (ctx->r1 == 0) {
        // 0x808006BC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800724;
    }
    // 0x808006BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808006C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(504, 0X838) << 16);
    // 0x808006C4: addu        $at, $at, $t6
    gpr jr_addend_808006CC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808006C8: lw          $t6, 0x838($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(504, 0X838));
    // 0x808006CC: jr          $t6
    // 0x808006D0: nop

    switch (jr_addend_808006CC >> 2) {
        case 0: goto L_808006D4; break;
        case 1: goto L_808006E0; break;
        case 2: goto L_808006EC; break;
        case 3: goto L_808006F8; break;
        case 4: goto L_80800704; break;
        case 5: goto L_80800710; break;
        case 6: goto L_8080071C; break;
        default: switch_error(__func__, 0x808006CC, 0x80800838);
    }
    // 0x808006D0: nop

L_808006D4:
    // 0x808006D4: addiu       $t7, $zero, 0x42B
    ctx->r15 = ADD32(0, 0X42B);
    // 0x808006D8: b           L_80800724
    // 0x808006DC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_80800724;
    // 0x808006DC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_808006E0:
    // 0x808006E0: addiu       $t8, $zero, 0x42B
    ctx->r24 = ADD32(0, 0X42B);
    // 0x808006E4: b           L_80800724
    // 0x808006E8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_80800724;
    // 0x808006E8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_808006EC:
    // 0x808006EC: addiu       $t9, $zero, 0x42B
    ctx->r25 = ADD32(0, 0X42B);
    // 0x808006F0: b           L_80800724
    // 0x808006F4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_80800724;
    // 0x808006F4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_808006F8:
    // 0x808006F8: addiu       $t0, $zero, 0x42B
    ctx->r8 = ADD32(0, 0X42B);
    // 0x808006FC: b           L_80800724
    // 0x80800700: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
        goto L_80800724;
    // 0x80800700: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80800704:
    // 0x80800704: addiu       $t1, $zero, 0x42B
    ctx->r9 = ADD32(0, 0X42B);
    // 0x80800708: b           L_80800724
    // 0x8080070C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
        goto L_80800724;
    // 0x8080070C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80800710:
    // 0x80800710: addiu       $t2, $zero, 0x42B
    ctx->r10 = ADD32(0, 0X42B);
    // 0x80800714: b           L_80800724
    // 0x80800718: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_80800724;
    // 0x80800718: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8080071C:
    // 0x8080071C: addiu       $t3, $zero, 0x42B
    ctx->r11 = ADD32(0, 0X42B);
    // 0x80800720: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80800724:
    // 0x80800724: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80800728: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080072C: beql        $t4, $zero, L_8080077C
    if (ctx->r12 == 0) {
        // 0x80800730: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080077C;
    }
    goto skip_0;
    // 0x80800730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800734: jal         0x8009C128
    // 0x80800738: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800738: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8080073C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800740: jal         0x8009DAAC
    // 0x80800744: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009DAAC(rdram, ctx);
        goto after_2;
    // 0x80800744: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800748: jal         0x800C4B64
    // 0x8080074C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_800C4B64(rdram, ctx);
        goto after_3;
    // 0x8080074C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800750: jal         0x800C4B70
    // 0x80800754: addiu       $a0, $zero, 0x6D60
    ctx->r4 = ADD32(0, 0X6D60);
    func_800C4B70(rdram, ctx);
        goto after_4;
    // 0x80800754: addiu       $a0, $zero, 0x6D60
    ctx->r4 = ADD32(0, 0X6D60);
    after_4:
    // 0x80800758: jal         0x800C4B7C
    // 0x8080075C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800C4B7C(rdram, ctx);
        goto after_5;
    // 0x8080075C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800760: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(504, 0X860) << 16);
    // 0x80800764: addiu       $a3, $a3, 0x860
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(504, 0X860));
    // 0x80800768: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8080076C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800770: jal         0x8010D930
    // 0x80800774: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_8010D930(rdram, ctx);
        goto after_6;
    // 0x80800774: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_6:
    // 0x80800778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080077C:
    // 0x8080077C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800780: jr          $ra
    // 0x80800784: nop

    return;
    // 0x80800784: nop

;}
RECOMP_FUNC void _bssnowball_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A60: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A60);
    return;
    // 0x80083A64: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800D0B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0B38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0B40: jal         0x800D0908
    // 0x800D0B44: nop

    func_800D0908(rdram, ctx);
        goto after_0;
    // 0x800D0B44: nop

    after_0:
    // 0x800D0B48: beq         $v0, $zero, L_800D0B58
    if (ctx->r2 == 0) {
        // 0x800D0B4C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D0B58;
    }
    // 0x800D0B4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D0B50: jal         0x800DA524
    // 0x800D0B54: nop

    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x800D0B54: nop

    after_1:
L_800D0B58:
    // 0x800D0B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0B5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D0B60: jr          $ra
    // 0x800D0B64: nop

    return;
    // 0x800D0B64: nop

;}
RECOMP_FUNC void _chcredits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B10: syscall     416
    recomp_syscall_handler(rdram, ctx, 0x80086B10);
    return;
    // 0x80086B14: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bstrexsmall_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808015AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B88) << 16);
    // 0x808015B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808015B4: jr          $ra
    // 0x808015B8: lw          $v0, 0x1B88($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B88));
    return;
    // 0x808015B8: lw          $v0, 0x1B88($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B88));
;}
RECOMP_FUNC void func_800F6224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6224: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800F6228: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F622C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800F6230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F6234: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800F6238: addiu       $v1, $v1, 0x5490
    ctx->r3 = ADD32(ctx->r3, 0X5490);
    // 0x800F623C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800F6240: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800F6244:
    // 0x800F6244: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800F6248: bne         $t6, $zero, L_800F62E4
    if (ctx->r14 != 0) {
        // 0x800F624C: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_800F62E4;
    }
    // 0x800F624C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800F6250: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6254: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F6258: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F625C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x800F6260: jal         0x800918F8
    // 0x800F6264: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    bakey_getControllerIndex(rdram, ctx);
        goto after_0;
    // 0x800F6264: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F626C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800F6270: jal         0x800A907C
    // 0x800F6274: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_800A907C(rdram, ctx);
        goto after_1;
    // 0x800F6274: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_1:
    // 0x800F6278: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800F627C: jal         0x800F43A8
    // 0x800F6280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F43A8(rdram, ctx);
        goto after_2;
    // 0x800F6280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800F6284: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800F6288: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800F628C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F6290: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800F6294: jal         0x80091BF0
    // 0x800F6298: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    bakey_setControllerIndex(rdram, ctx);
        goto after_3;
    // 0x800F6298: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    after_3:
    // 0x800F629C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F62A0: jal         0x800F3BB0
    // 0x800F62A4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F3BB0(rdram, ctx);
        goto after_4;
    // 0x800F62A4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_4:
    // 0x800F62A8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800F62AC: jal         0x800F452C
    // 0x800F62B0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F452C(rdram, ctx);
        goto after_5;
    // 0x800F62B0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x800F62B4: jal         0x8009C990
    // 0x800F62B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    yaw_getIdeal(rdram, ctx);
        goto after_6;
    // 0x800F62B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x800F62BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800F62C0: jal         0x8009C914
    // 0x800F62C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    yaw_setIdeal(rdram, ctx);
        goto after_7;
    // 0x800F62C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x800F62C8: jal         0x8009C974
    // 0x800F62CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    yaw_applyIdeal(rdram, ctx);
        goto after_8;
    // 0x800F62CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x800F62D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800F62D4: jal         0x800A92A8
    // 0x800F62D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A92A8(rdram, ctx);
        goto after_9;
    // 0x800F62D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x800F62DC: b           L_800F62F4
    // 0x800F62E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800F62F4;
    // 0x800F62E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800F62E4:
    // 0x800F62E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800F62E8: bne         $s0, $v0, L_800F6244
    if (ctx->r16 != ctx->r2) {
        // 0x800F62EC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800F6244;
    }
    // 0x800F62EC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800F62F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F62F4:
    // 0x800F62F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F62F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F62FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800F6300: jr          $ra
    // 0x800F6304: nop

    return;
    // 0x800F6304: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C08: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801C0C: slti        $at, $a1, 0x51
    ctx->r1 = SIGNED(ctx->r5) < 0X51 ? 1 : 0;
    // 0x80801C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C14: bne         $at, $zero, L_80801C4C
    if (ctx->r1 != 0) {
        // 0x80801C18: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80801C4C;
    }
    // 0x80801C18: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801C1C: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x80801C20: beq         $a1, $at, L_80801DF8
    if (ctx->r5 == ctx->r1) {
        // 0x80801C24: addiu       $at, $zero, 0x94
        ctx->r1 = ADD32(0, 0X94);
            goto L_80801DF8;
    }
    // 0x80801C24: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x80801C28: beq         $a1, $at, L_80801E8C
    if (ctx->r5 == ctx->r1) {
        // 0x80801C2C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80801E8C;
    }
    // 0x80801C2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801C30: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801C34: beq         $a1, $at, L_80801EDC
    if (ctx->r5 == ctx->r1) {
        // 0x80801C38: addiu       $at, $zero, 0x9A
        ctx->r1 = ADD32(0, 0X9A);
            goto L_80801EDC;
    }
    // 0x80801C38: addiu       $at, $zero, 0x9A
    ctx->r1 = ADD32(0, 0X9A);
    // 0x80801C3C: beql        $a1, $at, L_80801F34
    if (ctx->r5 == ctx->r1) {
        // 0x80801C40: lhu         $t5, 0x72($a3)
        ctx->r13 = MEM_HU(ctx->r7, 0X72);
            goto L_80801F34;
    }
    goto skip_0;
    // 0x80801C40: lhu         $t5, 0x72($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X72);
    skip_0:
    // 0x80801C44: b           L_80801F60
    // 0x80801C48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801F60;
    // 0x80801C48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801C4C:
    // 0x80801C4C: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80801C50: bne         $at, $zero, L_80801C94
    if (ctx->r1 != 0) {
        // 0x80801C54: slti        $at, $a1, 0x5
        ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
            goto L_80801C94;
    }
    // 0x80801C54: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80801C58: bne         $at, $zero, L_80801C80
    if (ctx->r1 != 0) {
        // 0x80801C5C: addiu       $t6, $a1, -0x29
        ctx->r14 = ADD32(ctx->r5, -0X29);
            goto L_80801C80;
    }
    // 0x80801C5C: addiu       $t6, $a1, -0x29
    ctx->r14 = ADD32(ctx->r5, -0X29);
    // 0x80801C60: sltiu       $at, $t6, 0x28
    ctx->r1 = ctx->r14 < 0X28 ? 1 : 0;
    // 0x80801C64: beq         $at, $zero, L_80801C8C
    if (ctx->r1 == 0) {
        // 0x80801C68: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801C8C;
    }
    // 0x80801C68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801C6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2884) << 16);
    // 0x80801C70: addu        $at, $at, $t6
    gpr jr_addend_80801C78 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801C74: lw          $t6, 0x2884($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2884));
    // 0x80801C78: jr          $t6
    // 0x80801C7C: nop

    switch (jr_addend_80801C78 >> 2) {
        case 0: goto L_80801E44; break;
        case 1: goto L_80801E68; break;
        case 2: goto L_80801D08; break;
        case 3: goto L_80801C8C; break;
        case 4: goto L_80801C8C; break;
        case 5: goto L_80801C8C; break;
        case 6: goto L_80801C8C; break;
        case 7: goto L_80801C8C; break;
        case 8: goto L_80801C8C; break;
        case 9: goto L_80801C8C; break;
        case 10: goto L_80801C8C; break;
        case 11: goto L_80801C8C; break;
        case 12: goto L_80801C8C; break;
        case 13: goto L_80801C8C; break;
        case 14: goto L_80801C8C; break;
        case 15: goto L_80801EEC; break;
        case 16: goto L_80801C8C; break;
        case 17: goto L_80801C8C; break;
        case 18: goto L_80801C8C; break;
        case 19: goto L_80801C8C; break;
        case 20: goto L_80801C8C; break;
        case 21: goto L_80801C8C; break;
        case 22: goto L_80801C8C; break;
        case 23: goto L_80801C8C; break;
        case 24: goto L_80801C8C; break;
        case 25: goto L_80801F5C; break;
        case 26: goto L_80801C8C; break;
        case 27: goto L_80801C8C; break;
        case 28: goto L_80801C8C; break;
        case 29: goto L_80801C8C; break;
        case 30: goto L_80801C8C; break;
        case 31: goto L_80801C8C; break;
        case 32: goto L_80801C8C; break;
        case 33: goto L_80801C8C; break;
        case 34: goto L_80801C8C; break;
        case 35: goto L_80801C8C; break;
        case 36: goto L_80801DDC; break;
        case 37: goto L_80801C8C; break;
        case 38: goto L_80801C8C; break;
        case 39: goto L_80801D70; break;
        default: switch_error(__func__, 0x80801C78, 0x80802884);
    }
    // 0x80801C7C: nop

L_80801C80:
    // 0x80801C80: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801C84: beql        $a1, $at, L_80801CF4
    if (ctx->r5 == ctx->r1) {
        // 0x80801C88: lbu         $t5, 0x64($a3)
        ctx->r13 = MEM_BU(ctx->r7, 0X64);
            goto L_80801CF4;
    }
    goto skip_1;
    // 0x80801C88: lbu         $t5, 0x64($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X64);
    skip_1:
L_80801C8C:
    // 0x80801C8C: b           L_80801F60
    // 0x80801C90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801F60;
    // 0x80801C90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801C94:
    // 0x80801C94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801C98: beq         $a1, $at, L_80801CB8
    if (ctx->r5 == ctx->r1) {
        // 0x80801C9C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801CB8;
    }
    // 0x80801C9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801CA0: beq         $a1, $at, L_80801CB8
    if (ctx->r5 == ctx->r1) {
        // 0x80801CA4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801CB8;
    }
    // 0x80801CA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801CA8: beql        $a1, $at, L_80801CDC
    if (ctx->r5 == ctx->r1) {
        // 0x80801CAC: lbu         $t0, 0x64($a3)
        ctx->r8 = MEM_BU(ctx->r7, 0X64);
            goto L_80801CDC;
    }
    goto skip_2;
    // 0x80801CAC: lbu         $t0, 0x64($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X64);
    skip_2:
    // 0x80801CB0: b           L_80801F60
    // 0x80801CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801F60;
    // 0x80801CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801CB8:
    // 0x80801CB8: lw          $t7, 0x78($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X78);
    // 0x80801CBC: sll         $t9, $t7, 29
    ctx->r25 = S32(ctx->r15 << 29);
    // 0x80801CC0: bltzl       $t9, L_80801F60
    if (SIGNED(ctx->r25) < 0) {
        // 0x80801CC4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801F60;
    }
    goto skip_3;
    // 0x80801CC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80801CC8: jal         0x8008A310
    // 0x80801CCC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _sucoasterplayer_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801CCC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80801CD0: b           L_80801F60
    // 0x80801CD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801F60;
    // 0x80801CD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801CD8: lbu         $t0, 0x64($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X64);
L_80801CDC:
    // 0x80801CDC: andi        $t2, $t0, 0xFFBF
    ctx->r10 = ctx->r8 & 0XFFBF;
    // 0x80801CE0: sb          $t2, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r10;
    // 0x80801CE4: andi        $t3, $t2, 0xFE
    ctx->r11 = ctx->r10 & 0XFE;
    // 0x80801CE8: b           L_80801F5C
    // 0x80801CEC: sb          $t3, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r11;
        goto L_80801F5C;
    // 0x80801CEC: sb          $t3, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r11;
    // 0x80801CF0: lbu         $t5, 0x64($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X64);
L_80801CF4:
    // 0x80801CF4: ori         $t8, $t5, 0x40
    ctx->r24 = ctx->r13 | 0X40;
    // 0x80801CF8: sb          $t8, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r24;
    // 0x80801CFC: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80801D00: b           L_80801F5C
    // 0x80801D04: sb          $t9, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r25;
        goto L_80801F5C;
    // 0x80801D04: sb          $t9, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r25;
L_80801D08:
    // 0x80801D08: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801D10: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80801D14: jal         0x80100094
    // 0x80801D18: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801D18: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_1:
    // 0x80801D1C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80801D20: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80801D24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2924) << 16);
    // 0x80801D28: lbu         $t3, 0x64($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X64);
    // 0x80801D2C: sltiu       $t0, $a2, 0x1
    ctx->r8 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x80801D30: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x80801D34: andi        $t2, $t1, 0x40
    ctx->r10 = ctx->r9 & 0X40;
    // 0x80801D38: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x80801D3C: or          $t7, $t2, $t4
    ctx->r15 = ctx->r10 | ctx->r12;
    // 0x80801D40: andi        $t8, $t7, 0xFE
    ctx->r24 = ctx->r15 & 0XFE;
    // 0x80801D44: andi        $t6, $t0, 0x1
    ctx->r14 = ctx->r8 & 0X1;
    // 0x80801D48: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80801D4C: sb          $t7, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r15;
    // 0x80801D50: beq         $a2, $zero, L_80801F5C
    if (ctx->r6 == 0) {
        // 0x80801D54: sb          $t9, 0x64($a3)
        MEM_B(0X64, ctx->r7) = ctx->r25;
            goto L_80801F5C;
    }
    // 0x80801D54: sb          $t9, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r25;
    // 0x80801D58: lwc1        $f12, 0x2924($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2924));
    // 0x80801D5C: jal         0x800D9058
    // 0x80801D60: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_800D9058(rdram, ctx);
        goto after_2;
    // 0x80801D60: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801D64: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80801D68: b           L_80801F5C
    // 0x80801D6C: sb          $v0, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r2;
        goto L_80801F5C;
    // 0x80801D6C: sb          $v0, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r2;
L_80801D70:
    // 0x80801D70: lhu         $t0, 0x72($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X72);
    // 0x80801D74: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801D78: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801D7C: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80801D80: bne         $t1, $at, L_80801DD4
    if (ctx->r9 != ctx->r1) {
        // 0x80801D84: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80801DD4;
    }
    // 0x80801D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801D88: jal         0x80100094
    // 0x80801D8C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80801D8C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    after_3:
    // 0x80801D90: lw          $t3, 0x18($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18);
    // 0x80801D94: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80801D98: sll         $t4, $t3, 10
    ctx->r12 = S32(ctx->r11 << 10);
    // 0x80801D9C: bgez        $t4, L_80801DD4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80801DA0: nop
    
            goto L_80801DD4;
    }
    // 0x80801DA0: nop

    // 0x80801DA4: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80801DA8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80801DAC: srl         $t5, $a0, 28
    ctx->r13 = S32(U32(ctx->r4) >> 28);
    // 0x80801DB0: jal         0x8008A240
    // 0x80801DB4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80801DB4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_4:
    // 0x80801DB8: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80801DBC: lh          $t7, 0x58($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X58);
    // 0x80801DC0: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80801DC4: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80801DC8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80801DCC: b           L_80801F60
    // 0x80801DD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80801F60;
    // 0x80801DD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80801DD4:
    // 0x80801DD4: b           L_80801F60
    // 0x80801DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801F60;
    // 0x80801DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801DDC:
    // 0x80801DDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801DE0: jal         0x80107070
    // 0x80801DE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_5;
    // 0x80801DE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80801DE8: bnel        $v0, $zero, L_80801F60
    if (ctx->r2 != 0) {
        // 0x80801DEC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801F60;
    }
    goto skip_4;
    // 0x80801DEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x80801DF0: b           L_80801F60
    // 0x80801DF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801F60;
    // 0x80801DF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801DF8:
    // 0x80801DF8: beq         $a2, $zero, L_80801E14
    if (ctx->r6 == 0) {
        // 0x80801DFC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80801E14;
    }
    // 0x80801DFC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801E00: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801E04: beql        $a2, $at, L_80801E34
    if (ctx->r6 == ctx->r1) {
        // 0x80801E08: lbu         $t9, 0x77($a3)
        ctx->r25 = MEM_BU(ctx->r7, 0X77);
            goto L_80801E34;
    }
    goto skip_5;
    // 0x80801E08: lbu         $t9, 0x77($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X77);
    skip_5:
    // 0x80801E0C: b           L_80801F60
    // 0x80801E10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801F60;
    // 0x80801E10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E14:
    // 0x80801E14: jal         0x8010A590
    // 0x80801E18: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_8010A590(rdram, ctx);
        goto after_6;
    // 0x80801E18: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_6:
    // 0x80801E1C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801E20: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801E24: jal         0x80801004
    // 0x80801E28: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80801E28: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_7:
    // 0x80801E2C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80801E30: lbu         $t9, 0x77($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X77);
L_80801E34:
    // 0x80801E34: andi        $t0, $t9, 0xFFF0
    ctx->r8 = ctx->r25 & 0XFFF0;
    // 0x80801E38: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80801E3C: b           L_80801F5C
    // 0x80801E40: sb          $t1, 0x77($a3)
    MEM_B(0X77, ctx->r7) = ctx->r9;
        goto L_80801F5C;
    // 0x80801E40: sb          $t1, 0x77($a3)
    MEM_B(0X77, ctx->r7) = ctx->r9;
L_80801E44:
    // 0x80801E44: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801E48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801E4C: jal         0x80100094
    // 0x80801E50: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80801E50: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_8:
    // 0x80801E54: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801E58: jal         0x80802690
    // 0x80801E5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80802690_sucoaster(rdram, ctx);
        goto after_9;
    // 0x80801E5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80801E60: b           L_80801F60
    // 0x80801E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801F60;
    // 0x80801E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E68:
    // 0x80801E68: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801E6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801E70: jal         0x80100094
    // 0x80801E74: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x80801E74: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_10:
    // 0x80801E78: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801E7C: jal         0x80802728
    // 0x80801E80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80802728_sucoaster(rdram, ctx);
        goto after_11;
    // 0x80801E80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x80801E84: b           L_80801F60
    // 0x80801E88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801F60;
    // 0x80801E88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E8C:
    // 0x80801E8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801E90: jal         0x80100094
    // 0x80801E94: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80801E94: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_12:
    // 0x80801E98: bne         $v0, $zero, L_80801EA8
    if (ctx->r2 != 0) {
        // 0x80801E9C: lw          $a3, 0x50($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X50);
            goto L_80801EA8;
    }
    // 0x80801E9C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80801EA0: b           L_80801F60
    // 0x80801EA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801F60;
    // 0x80801EA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801EA8:
    // 0x80801EA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801EAC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801EB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801EB4: jal         0x80100094
    // 0x80801EB8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x80801EB8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x80801EBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801EC0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80801EC4: jal         0x800897F0
    // 0x80801EC8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    _suexpression_entrypoint_13(rdram, ctx);
        goto after_14;
    // 0x80801EC8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_14:
    // 0x80801ECC: jal         0x80101010
    // 0x80801ED0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_80101010(rdram, ctx);
        goto after_15;
    // 0x80801ED0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_15:
    // 0x80801ED4: b           L_80801F60
    // 0x80801ED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801F60;
    // 0x80801ED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801EDC:
    // 0x80801EDC: jal         0x80089F60
    // 0x80801EE0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x80801EE0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_16:
    // 0x80801EE4: b           L_80801F60
    // 0x80801EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801F60;
    // 0x80801EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801EEC:
    // 0x80801EEC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801EF4: jal         0x80100094
    // 0x80801EF8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_80100094(rdram, ctx);
        goto after_17;
    // 0x80801EF8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_17:
    // 0x80801EFC: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80801F00: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80801F04: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80801F08: lw          $a1, 0x6C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X6C);
    // 0x80801F0C: srl         $t3, $a0, 28
    ctx->r11 = S32(U32(ctx->r4) >> 28);
    // 0x80801F10: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80801F14: sll         $t2, $a1, 11
    ctx->r10 = S32(ctx->r5 << 11);
    // 0x80801F18: jal         0x8008A260
    // 0x80801F1C: srl         $a1, $t2, 20
    ctx->r5 = S32(U32(ctx->r10) >> 20);
    _sucoasterdata_entrypoint_5(rdram, ctx);
        goto after_18;
    // 0x80801F1C: srl         $a1, $t2, 20
    ctx->r5 = S32(U32(ctx->r10) >> 20);
    after_18:
    // 0x80801F20: jal         0x80101074
    // 0x80801F24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80101074(rdram, ctx);
        goto after_19;
    // 0x80801F24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x80801F28: b           L_80801F60
    // 0x80801F2C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80801F60;
    // 0x80801F2C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80801F30: lhu         $t5, 0x72($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X72);
L_80801F34:
    // 0x80801F34: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80801F38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801F3C: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x80801F40: beq         $t6, $at, L_80801F5C
    if (ctx->r14 == ctx->r1) {
        // 0x80801F44: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_80801F5C;
    }
    // 0x80801F44: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80801F48: jal         0x80801054
    // 0x80801F4C: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    sucoaster_entrypoint_10(rdram, ctx);
        goto after_20;
    // 0x80801F4C: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_20:
    // 0x80801F50: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801F54: jal         0x8008A4B0
    // 0x80801F58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80801F58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
L_80801F5C:
    // 0x80801F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801F60:
    // 0x80801F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F64: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801F68: jr          $ra
    // 0x80801F6C: nop

    return;
    // 0x80801F6C: nop

;}
RECOMP_FUNC void func_80800A04_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A04: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800A08: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800A0C: jr          $ra
    // 0x80800A10: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    return;
    // 0x80800A10: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
;}
RECOMP_FUNC void subaddiejoy_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080030C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800310: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x80800314: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80800318: jal         0x80016B54
    // 0x8080031C: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    func_80016B54(rdram, ctx);
        goto after_0;
    // 0x8080031C: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    after_0:
    // 0x80800320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void func_80800D60_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D60: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800D64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800D6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D70: jal         0x80100094
    // 0x80800D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D78: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800D7C: jal         0x8010A610
    // 0x80800D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A610(rdram, ctx);
        goto after_1;
    // 0x80800D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800D84: beq         $v0, $zero, L_8080102C
    if (ctx->r2 == 0) {
        // 0x80800D88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080102C;
    }
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D8C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800D90: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1792, 0X15DC) << 16);
    // 0x80800D94: addiu       $a3, $a3, 0x15DC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1792, 0X15DC));
    // 0x80800D98: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80800D9C: jal         0x80089D50
    // 0x80800DA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800DA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80800DA4: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DAC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800DB0: bltz        $t8, L_80800E08
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800DB4: nop
    
            goto L_80800E08;
    }
    // 0x80800DB4: nop

    // 0x80800DB8: jal         0x800DC0C0
    // 0x80800DBC: nop

    func_800DC0C0(rdram, ctx);
        goto after_3;
    // 0x80800DBC: nop

    after_3:
    // 0x80800DC0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800DC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DC8: nop

    // 0x80800DCC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800DD0: nop

    // 0x80800DD4: bc1f        L_80800E2C
    if (!c1cs) {
        // 0x80800DD8: nop
    
            goto L_80800E2C;
    }
    // 0x80800DD8: nop

    // 0x80800DDC: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800DE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800DE4: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800DE8: beq         $t0, $at, L_80800E2C
    if (ctx->r8 == ctx->r1) {
        // 0x80800DEC: nop
    
            goto L_80800E2C;
    }
    // 0x80800DEC: nop

    // 0x80800DF0: jal         0x8010A570
    // 0x80800DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80800DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800DF8: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800DFC: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x80800E00: b           L_80800E2C
    // 0x80800E04: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_80800E2C;
    // 0x80800E04: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_80800E08:
    // 0x80800E08: jal         0x80089BD8
    // 0x80800E0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800E0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800E10: bne         $v0, $zero, L_80800E2C
    if (ctx->r2 != 0) {
        // 0x80800E14: nop
    
            goto L_80800E2C;
    }
    // 0x80800E14: nop

    // 0x80800E18: jal         0x8010A570
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800E20: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800E24: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x80800E28: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_80800E2C:
    // 0x80800E2C: jal         0x8010A610
    // 0x80800E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A610(rdram, ctx);
        goto after_7;
    // 0x80800E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800E34: bne         $v0, $zero, L_80800E5C
    if (ctx->r2 != 0) {
        // 0x80800E38: lw          $t5, 0x4C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X4C);
            goto L_80800E5C;
    }
    // 0x80800E38: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80800E3C: lw          $a0, 0xDC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XDC);
    // 0x80800E40: beql        $a0, $zero, L_80801110
    if (ctx->r4 == 0) {
        // 0x80800E44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801110;
    }
    goto skip_0;
    // 0x80800E44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800E48: jal         0x800C8B84
    // 0x80800E4C: nop

    func_800C8B84(rdram, ctx);
        goto after_8;
    // 0x80800E4C: nop

    after_8:
    // 0x80800E50: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800E54: b           L_8080110C
    // 0x80800E58: sw          $zero, 0xDC($t6)
    MEM_W(0XDC, ctx->r14) = 0;
        goto L_8080110C;
    // 0x80800E58: sw          $zero, 0xDC($t6)
    MEM_W(0XDC, ctx->r14) = 0;
L_80800E5C:
    // 0x80800E5C: jal         0x800DC0C0
    // 0x80800E60: nop

    func_800DC0C0(rdram, ctx);
        goto after_9;
    // 0x80800E60: nop

    after_9:
    // 0x80800E64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800E68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1792, 0X1518) << 16);
    // 0x80800E70: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800E74: nop

    // 0x80800E78: bc1f        L_80800EA8
    if (!c1cs) {
        // 0x80800E7C: nop
    
            goto L_80800EA8;
    }
    // 0x80800E7C: nop

    // 0x80800E80: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800E84: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800E88: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80800E8C: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80800E90: xori        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 ^ 0X1;
    // 0x80800E94: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80800E98: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80800E9C: andi        $t5, $t4, 0xFFF7
    ctx->r13 = ctx->r12 & 0XFFF7;
    // 0x80800EA0: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800EA4: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
L_80800EA8:
    // 0x80800EA8: lwc1        $f8, 0x1518($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1792, 0X1518));
    // 0x80800EAC: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800EB0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1792, 0X151C) << 16);
    // 0x80800EB4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800EB8: nop

    // 0x80800EBC: bc1f        L_80800EDC
    if (!c1cs) {
        // 0x80800EC0: nop
    
            goto L_80800EDC;
    }
    // 0x80800EC0: nop

    // 0x80800EC4: jal         0x800D8FF8
    // 0x80800EC8: nop

    func_800D8FF8(rdram, ctx);
        goto after_10;
    // 0x80800EC8: nop

    after_10:
    // 0x80800ECC: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800ED0: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80800ED4: b           L_80800FC8
    // 0x80800ED8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_80800FC8;
    // 0x80800ED8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80800EDC:
    // 0x80800EDC: lwc1        $f12, 0x151C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1792, 0X151C));
    // 0x80800EE0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800EE4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800EE8: jal         0x800DC178
    // 0x80800EEC: nop

    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80800EEC: nop

    after_11:
    // 0x80800EF0: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x80800EF4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800EF8: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80800EFC: bgezl       $t9, L_80800FCC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800F00: lw          $t3, 0x4C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4C);
            goto L_80800FCC;
    }
    goto skip_1;
    // 0x80800F00: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x80800F04: jal         0x800B53A4
    // 0x80800F08: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800B53A4(rdram, ctx);
        goto after_12;
    // 0x80800F08: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_12:
    // 0x80800F0C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800F10: jal         0x800B53A4
    // 0x80800F14: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800B53A4(rdram, ctx);
        goto after_13;
    // 0x80800F14: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_13:
    // 0x80800F18: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800F1C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800F20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800F24: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800F28: jal         0x800DBEFC
    // 0x80800F2C: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_14;
    // 0x80800F2C: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    after_14:
    // 0x80800F30: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80800F34: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x80800F38: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800F3C: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x80800F40: jal         0x800DBEFC
    // 0x80800F44: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800DBEFC(rdram, ctx);
        goto after_15;
    // 0x80800F44: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_15:
    // 0x80800F48: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1792, 0X1608) << 16);
    // 0x80800F4C: addiu       $t2, $t2, 0x1608
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1792, 0X1608));
    // 0x80800F50: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800F54: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800F58: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800F5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800F60: jal         0x800BABB8
    // 0x80800F64: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_16;
    // 0x80800F64: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_16:
    // 0x80800F68: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800F6C: jal         0x800BA3FC
    // 0x80800F70: addiu       $a1, $zero, 0x9E7
    ctx->r5 = ADD32(0, 0X9E7);
    func_800BA3FC(rdram, ctx);
        goto after_17;
    // 0x80800F70: addiu       $a1, $zero, 0x9E7
    ctx->r5 = ADD32(0, 0X9E7);
    after_17:
    // 0x80800F74: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800F78: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800F7C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F80: jal         0x800BA1D0
    // 0x80800F84: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BA1D0(rdram, ctx);
        goto after_18;
    // 0x80800F84: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_18:
    // 0x80800F88: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(1792, 0X1608) << 16);
    // 0x80800F8C: addiu       $t4, $t4, 0x1608
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(1792, 0X1608));
    // 0x80800F90: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800F94: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800F98: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800FA0: jal         0x800BABB8
    // 0x80800FA4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_19;
    // 0x80800FA4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_19:
    // 0x80800FA8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800FAC: jal         0x800BA3FC
    // 0x80800FB0: addiu       $a1, $zero, 0x9E7
    ctx->r5 = ADD32(0, 0X9E7);
    func_800BA3FC(rdram, ctx);
        goto after_20;
    // 0x80800FB0: addiu       $a1, $zero, 0x9E7
    ctx->r5 = ADD32(0, 0X9E7);
    after_20:
    // 0x80800FB4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800FB8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FBC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800FC0: jal         0x800BA1D0
    // 0x80800FC4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BA1D0(rdram, ctx);
        goto after_21;
    // 0x80800FC4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_21:
L_80800FC8:
    // 0x80800FC8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
L_80800FCC:
    // 0x80800FCC: addiu       $t5, $s0, 0x28
    ctx->r13 = ADD32(ctx->r16, 0X28);
    // 0x80800FD0: lw          $a0, 0xDC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XDC);
    // 0x80800FD4: beql        $a0, $zero, L_80801110
    if (ctx->r4 == 0) {
        // 0x80800FD8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801110;
    }
    goto skip_2;
    // 0x80800FD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800FDC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80800FE0: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800FE4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x80800FE8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80800FEC: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800FF0: bgez        $t8, L_8080100C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800FF4: addiu       $a2, $zero, 0x40
        ctx->r6 = ADD32(0, 0X40);
            goto L_8080100C;
    }
    // 0x80800FF4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80800FF8: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x80800FFC: jal         0x800C8FB0
    // 0x80801000: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    func_800C8FB0(rdram, ctx);
        goto after_22;
    // 0x80801000: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_22:
    // 0x80801004: b           L_80801018
    // 0x80801008: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
        goto L_80801018;
    // 0x80801008: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
L_8080100C:
    // 0x8080100C: jal         0x800C8FB0
    // 0x80801010: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    func_800C8FB0(rdram, ctx);
        goto after_23;
    // 0x80801010: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_23:
    // 0x80801014: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
L_80801018:
    // 0x80801018: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080101C: jal         0x800C8CB8
    // 0x80801020: lw          $a0, 0xDC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XDC);
    func_800C8CB8(rdram, ctx);
        goto after_24;
    // 0x80801020: lw          $a0, 0xDC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XDC);
    after_24:
    // 0x80801024: b           L_80801110
    // 0x80801028: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801110;
    // 0x80801028: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080102C:
    // 0x8080102C: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80801030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801034: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80801038: bgez        $t2, L_80801060
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8080103C: nop
    
            goto L_80801060;
    }
    // 0x8080103C: nop

    // 0x80801040: jal         0x80089BD8
    // 0x80801044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_25;
    // 0x80801044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80801048: beq         $v0, $zero, L_808010C0
    if (ctx->r2 == 0) {
        // 0x8080104C: nop
    
            goto L_808010C0;
    }
    // 0x8080104C: nop

    // 0x80801050: jal         0x8010A590
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_26;
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80801058: b           L_808010C0
    // 0x8080105C: nop

        goto L_808010C0;
    // 0x8080105C: nop

L_80801060:
    // 0x80801060: jal         0x800DC0C0
    // 0x80801064: nop

    func_800DC0C0(rdram, ctx);
        goto after_27;
    // 0x80801064: nop

    after_27:
    // 0x80801068: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080106C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801070: nop

    // 0x80801074: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801078: nop

    // 0x8080107C: bc1t        L_808010B8
    if (c1cs) {
        // 0x80801080: nop
    
            goto L_808010B8;
    }
    // 0x80801080: nop

    // 0x80801084: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
    // 0x80801088: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080108C: srl         $t3, $t4, 10
    ctx->r11 = S32(U32(ctx->r12) >> 10);
    // 0x80801090: bne         $t3, $at, L_808010C0
    if (ctx->r11 != ctx->r1) {
        // 0x80801094: nop
    
            goto L_808010C0;
    }
    // 0x80801094: nop

    // 0x80801098: jal         0x800DC0C0
    // 0x8080109C: nop

    func_800DC0C0(rdram, ctx);
        goto after_28;
    // 0x8080109C: nop

    after_28:
    // 0x808010A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1792, 0X1520) << 16);
    // 0x808010A4: lwc1        $f6, 0x1520($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1792, 0X1520));
    // 0x808010A8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808010AC: nop

    // 0x808010B0: bc1f        L_808010C0
    if (!c1cs) {
        // 0x808010B4: nop
    
            goto L_808010C0;
    }
    // 0x808010B4: nop

L_808010B8:
    // 0x808010B8: jal         0x8010A590
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_29;
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
L_808010C0:
    // 0x808010C0: jal         0x8010A610
    // 0x808010C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A610(rdram, ctx);
        goto after_30;
    // 0x808010C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808010C8: beq         $v0, $zero, L_8080110C
    if (ctx->r2 == 0) {
        // 0x808010CC: lw          $t5, 0x4C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X4C);
            goto L_8080110C;
    }
    // 0x808010CC: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x808010D0: lw          $t6, 0xDC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XDC);
    // 0x808010D4: bnel        $t6, $zero, L_80801110
    if (ctx->r14 != 0) {
        // 0x808010D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801110;
    }
    goto skip_3;
    // 0x808010D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x808010DC: jal         0x800C8A98
    // 0x808010E0: nop

    func_800C8A98(rdram, ctx);
        goto after_31;
    // 0x808010E0: nop

    after_31:
    // 0x808010E4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x808010E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010EC: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x808010F0: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x808010F4: jal         0x800C8E54
    // 0x808010F8: sw          $v0, 0xDC($t7)
    MEM_W(0XDC, ctx->r15) = ctx->r2;
    func_800C8E54(rdram, ctx);
        goto after_32;
    // 0x808010F8: sw          $v0, 0xDC($t7)
    MEM_W(0XDC, ctx->r15) = ctx->r2;
    after_32:
    // 0x808010FC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80801100: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80801104: jal         0x800C8CB8
    // 0x80801108: lw          $a0, 0xDC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XDC);
    func_800C8CB8(rdram, ctx);
        goto after_33;
    // 0x80801108: lw          $a0, 0xDC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XDC);
    after_33:
L_8080110C:
    // 0x8080110C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801110:
    // 0x80801110: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801114: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801118: jr          $ra
    // 0x8080111C: nop

    return;
    // 0x8080111C: nop

;}
RECOMP_FUNC void _suegg_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3B0: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3B0);
    return;
    // 0x8008A3B4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _suinv_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A690: syscall     848
    recomp_syscall_handler(rdram, ctx, 0x8008A690);
    return;
    // 0x8008A694: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bashoes_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800910: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800914: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800918: jal         0x800B53A4
    // 0x8080091C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x8080091C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80800920: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800924: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800928: jal         0x80092E08
    // 0x8080092C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80092E08(rdram, ctx);
        goto after_1;
    // 0x8080092C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800930: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800934: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800938: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080093C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(592, 0XB90) << 16);
    // 0x80800940: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800944: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800948: addiu       $t6, $t6, 0xB90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(592, 0XB90));
    // 0x8080094C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800950: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800954: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80800958: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080095C: jal         0x800BABB8
    // 0x80800960: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800960: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80800964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800968: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080096C: jr          $ra
    // 0x80800970: nop

    return;
    // 0x80800970: nop

;}
RECOMP_FUNC void chufoextdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2044, 0X148) << 16);
    // 0x808000F0: jr          $ra
    // 0x808000F4: addiu       $v0, $v0, 0x148
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2044, 0X148));
    return;
    // 0x808000F4: addiu       $v0, $v0, 0x148
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2044, 0X148));
    // 0x808000F8: nop

    // 0x808000FC: nop

;}
RECOMP_FUNC void sccustom_banjo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003F8: jal         0x8008A620
    // 0x808003FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _scinfobar_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808003FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800400: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80800404: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80800408: jal         0x8008A610
    // 0x8080040C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x8080040C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800410: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080041C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800420: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800424: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800428: addiu       $t9, $t8, 0x28
    ctx->r25 = ADD32(ctx->r24, 0X28);
    // 0x8080042C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800430: nop

    // 0x80800434: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800438: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8080043C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800440: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80800444: jr          $ra
    // 0x80800448: nop

    return;
    // 0x80800448: nop

;}
RECOMP_FUNC void func_80801FAC_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801FB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801FB4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80801FB8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801FBC: beql        $v0, $zero, L_80801FDC
    if (ctx->r2 == 0) {
        // 0x80801FC0: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80801FDC;
    }
    goto skip_0;
    // 0x80801FC0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x80801FC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801FC8: beql        $v0, $at, L_80801FF0
    if (ctx->r2 == ctx->r1) {
        // 0x80801FCC: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80801FF0;
    }
    goto skip_1;
    // 0x80801FCC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_1:
    // 0x80801FD0: b           L_80802004
    // 0x80801FD4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
        goto L_80802004;
    // 0x80801FD4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801FD8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80801FDC:
    // 0x80801FDC: jal         0x800DC178
    // 0x80801FE0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80801FE0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_0:
    // 0x80801FE4: b           L_80802014
    // 0x80801FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802014;
    // 0x80801FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801FEC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_80801FF0:
    // 0x80801FF0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801FF4: jal         0x800DC178
    // 0x80801FF8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80801FF8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_1:
    // 0x80801FFC: b           L_80802014
    // 0x80802000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802014;
    // 0x80802000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802004:
    // 0x80802004: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802008: jal         0x800DC178
    // 0x8080200C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x8080200C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x80802010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802014:
    // 0x80802014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802018: jr          $ra
    // 0x8080201C: nop

    return;
    // 0x8080201C: nop

;}
RECOMP_FUNC void func_800AF5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF5A0: jr          $ra
    // 0x800AF5A4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    return;
    // 0x800AF5A4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
;}
RECOMP_FUNC void func_80800BA4_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BB0: jal         0x80102424
    // 0x80800BB4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800BB4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80800BB8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800BBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800BC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BC4: lhu         $t6, 0x6E($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X6E);
    // 0x80800BC8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1216, 0X1030) << 16);
    // 0x80800BCC: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x80800BD0: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800BD4: sh          $t7, 0x6E($a3)
    MEM_H(0X6E, ctx->r7) = ctx->r15;
    // 0x80800BD8: swc1        $f4, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f4.u32l;
    // 0x80800BDC: lh          $a1, 0x1030($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1216, 0X1030));
    // 0x80800BE0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80800BE4: jal         0x80085740
    // 0x80800BE8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    _capod_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800BE8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    after_1:
    // 0x80800BEC: jal         0x80800CDC
    // 0x80800BF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800CDC_chbiggafoot(rdram, ctx);
        goto after_2;
    // 0x80800BF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BFC: jr          $ra
    // 0x80800C00: nop

    return;
    // 0x80800C00: nop

;}
RECOMP_FUNC void func_8008D280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D288: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D28C: jal         0x800C6E38
    // 0x8008D290: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D290: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x8008D294: bne         $v0, $zero, L_8008D2A4
    if (ctx->r2 != 0) {
        // 0x8008D298: nop
    
            goto L_8008D2A4;
    }
    // 0x8008D298: nop

    // 0x8008D29C: b           L_8008D2F4
    // 0x8008D2A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D2F4;
    // 0x8008D2A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D2A4:
    // 0x8008D2A4: jal         0x800DA298
    // 0x8008D2A8: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8008D2A8: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_1:
    // 0x8008D2AC: beq         $v0, $zero, L_8008D2BC
    if (ctx->r2 == 0) {
        // 0x8008D2B0: nop
    
            goto L_8008D2BC;
    }
    // 0x8008D2B0: nop

    // 0x8008D2B4: b           L_8008D2F4
    // 0x8008D2B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D2F4;
    // 0x8008D2B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D2BC:
    // 0x8008D2BC: jal         0x800A3274
    // 0x8008D2C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3274(rdram, ctx);
        goto after_2;
    // 0x8008D2C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8008D2C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D2C8: beq         $v0, $at, L_8008D2D8
    if (ctx->r2 == ctx->r1) {
        // 0x8008D2CC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8008D2D8;
    }
    // 0x8008D2CC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008D2D0: bnel        $v0, $at, L_8008D2F4
    if (ctx->r2 != ctx->r1) {
        // 0x8008D2D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008D2F4;
    }
    goto skip_0;
    // 0x8008D2D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_8008D2D8:
    // 0x8008D2D8: jal         0x800A3304
    // 0x8008D2DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_3;
    // 0x8008D2DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8008D2E0: bnel        $v0, $zero, L_8008D2F4
    if (ctx->r2 != 0) {
        // 0x8008D2E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008D2F4;
    }
    goto skip_1;
    // 0x8008D2E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8008D2E8: b           L_8008D2F4
    // 0x8008D2EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D2F4;
    // 0x8008D2EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D2F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008D2F4:
    // 0x8008D2F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D2F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D2FC: jr          $ra
    // 0x8008D300: nop

    return;
    // 0x8008D300: nop

;}
RECOMP_FUNC void func_800F1074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F107C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800F1080: jal         0x800F13C4
    // 0x800F1084: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    func_800F13C4(rdram, ctx);
        goto after_0;
    // 0x800F1084: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x800F1088: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F108C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800F1090: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F1094: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F1098: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800F109C: jal         0x80013970
    // 0x800F10A0: nop

    func_80013970(rdram, ctx);
        goto after_1;
    // 0x800F10A0: nop

    after_1:
    // 0x800F10A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F10A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F10AC: jr          $ra
    // 0x800F10B0: nop

    return;
    // 0x800F10B0: nop

;}
RECOMP_FUNC void func_8080057C_chfactorylight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080057C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800580: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800584: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800588: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080058C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800590: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800594: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800598: beq         $a1, $at, L_808005B4
    if (ctx->r5 == ctx->r1) {
        // 0x8080059C: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_808005B4;
    }
    // 0x8080059C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808005A0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808005A4: beq         $a1, $at, L_80800680
    if (ctx->r5 == ctx->r1) {
        // 0x808005A8: nop
    
            goto L_80800680;
    }
    // 0x808005A8: nop

    // 0x808005AC: b           L_8080069C
    // 0x808005B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080069C;
    // 0x808005B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005B4:
    // 0x808005B4: beq         $a2, $zero, L_808005C4
    if (ctx->r6 == 0) {
        // 0x808005B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005C4;
    }
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005BC: b           L_808005C8
    // 0x808005C0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_808005C8;
    // 0x808005C0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_808005C4:
    // 0x808005C4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_808005C8:
    // 0x808005C8: jal         0x80100094
    // 0x808005CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005D0: lh          $t7, 0x7E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X7E);
    // 0x808005D4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808005D8: bltz        $t7, L_808005F4
    if (SIGNED(ctx->r15) < 0) {
        // 0x808005DC: nop
    
            goto L_808005F4;
    }
    // 0x808005DC: nop

    // 0x808005E0: jal         0x808008E4
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008E4_chfactorylight(rdram, ctx);
        goto after_1;
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808005E8: lbu         $t9, 0x7E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7E);
    // 0x808005EC: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x808005F0: sb          $t0, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r8;
L_808005F4:
    // 0x808005F4: jal         0x800EA05C
    // 0x808005F8: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x808005F8: nop

    after_2:
    // 0x808005FC: addiu       $at, $zero, 0x10D
    ctx->r1 = ADD32(0, 0X10D);
    // 0x80800600: bne         $v0, $at, L_8080063C
    if (ctx->r2 != ctx->r1) {
        // 0x80800604: nop
    
            goto L_8080063C;
    }
    // 0x80800604: nop

    // 0x80800608: beq         $s3, $zero, L_80800618
    if (ctx->r19 == 0) {
        // 0x8080060C: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800618;
    }
    // 0x8080060C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800610: b           L_80800618
    // 0x80800614: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80800618;
    // 0x80800614: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80800618:
    // 0x80800618: jal         0x80101FDC
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800620: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800624: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800628: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1100, 0XB5C) << 16);
    // 0x8080062C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80800630: lwc1        $f6, 0xB5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1100, 0XB5C));
    // 0x80800634: b           L_80800654
    // 0x80800638: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80800654;
    // 0x80800638: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_8080063C:
    // 0x8080063C: beq         $s3, $zero, L_8080064C
    if (ctx->r19 == 0) {
        // 0x80800640: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8080064C;
    }
    // 0x80800640: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800644: b           L_8080064C
    // 0x80800648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8080064C;
    // 0x80800648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080064C:
    // 0x8080064C: jal         0x80101FDC
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80800654:
    // 0x80800654: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80800658: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x8080065C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800660:
    // 0x80800660: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800664: jal         0x800C8FE0
    // 0x80800668: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_5;
    // 0x80800668: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x8080066C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800670: bne         $s0, $s2, L_80800660
    if (ctx->r16 != ctx->r18) {
        // 0x80800674: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800660;
    }
    // 0x80800674: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800678: b           L_8080069C
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080069C;
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800680:
    // 0x80800680: jal         0x808008E4
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008E4_chfactorylight(rdram, ctx);
        goto after_6;
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800688: b           L_8080069C
    // 0x8080068C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080069C;
    // 0x8080068C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800690: b           L_8080069C
    // 0x80800694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080069C;
    // 0x80800694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080069C:
    // 0x8080069C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808006A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808006A8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808006AC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808006B0: jr          $ra
    // 0x808006B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808006B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80090C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090C0C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80090C10: jal         0x800CBB70
    // 0x80090C14: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800CBB70(rdram, ctx);
        goto after_0;
    // 0x80090C14: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80090C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090C1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090C20: jr          $ra
    // 0x80090C24: nop

    return;
    // 0x80090C24: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C80: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C80);
    return;
    // 0x80082C84: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void func_808003EC_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003F4: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x808003F8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808003FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800400: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800404: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    // 0x80800408: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x8080040C: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    // 0x80800410: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800414: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80800418: jal         0x800D0A9C
    // 0x8080041C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x8080041C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800420: beq         $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x80800424: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800430;
    }
    // 0x80800424: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800428: jal         0x800FFAB0
    // 0x8080042C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x8080042C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_80800430:
    // 0x80800430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800438: jr          $ra
    // 0x8080043C: nop

    return;
    // 0x8080043C: nop

;}
RECOMP_FUNC void func_800C0308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0308: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C030C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C0310: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C0314: addiu       $s0, $s0, -0x7750
    ctx->r16 = ADD32(ctx->r16, -0X7750);
    // 0x800C0318: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x800C031C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0320: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x800C0324: bgezl       $t8, L_800C03B0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C0328: lb          $t9, 0x166($s0)
        ctx->r25 = MEM_B(ctx->r16, 0X166);
            goto L_800C03B0;
    }
    goto skip_0;
    // 0x800C0328: lb          $t9, 0x166($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X166);
    skip_0:
    // 0x800C032C: lb          $t9, 0x166($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X166);
    // 0x800C0330: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    // 0x800C0334: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C0338: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C033C: sb          $t0, 0x166($s0)
    MEM_B(0X166, ctx->r16) = ctx->r8;
    // 0x800C0340: lb          $t1, 0x166($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X166);
    // 0x800C0344: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800C0348: beq         $a0, $zero, L_800C036C
    if (ctx->r4 == 0) {
        // 0x800C034C: lb          $v0, -0x5840($v0)
        ctx->r2 = MEM_B(ctx->r2, -0X5840);
            goto L_800C036C;
    }
    // 0x800C034C: lb          $v0, -0x5840($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X5840);
    // 0x800C0350: lh          $t2, 0x128($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X128);
    // 0x800C0354: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C0358: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x800C035C: sh          $t3, 0x128($s0)
    MEM_H(0X128, ctx->r16) = ctx->r11;
    // 0x800C0360: jal         0x80087C10
    // 0x800C0364: lh          $a1, 0x128($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X128);
    _gczoombox_entrypoint_38(rdram, ctx);
        goto after_0;
    // 0x800C0364: lh          $a1, 0x128($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X128);
    after_0:
    // 0x800C0368: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_800C036C:
    // 0x800C036C: lw          $a0, 0x124($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X124);
    // 0x800C0370: beql        $a0, $zero, L_800C0390
    if (ctx->r4 == 0) {
        // 0x800C0374: lb          $t6, 0x166($s0)
        ctx->r14 = MEM_B(ctx->r16, 0X166);
            goto L_800C0390;
    }
    goto skip_1;
    // 0x800C0374: lb          $t6, 0x166($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X166);
    skip_1:
    // 0x800C0378: lh          $t4, 0x12A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X12A);
    // 0x800C037C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C0380: sh          $t5, 0x12A($s0)
    MEM_H(0X12A, ctx->r16) = ctx->r13;
    // 0x800C0384: jal         0x80087C10
    // 0x800C0388: lh          $a1, 0x12A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X12A);
    _gczoombox_entrypoint_38(rdram, ctx);
        goto after_1;
    // 0x800C0388: lh          $a1, 0x12A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X12A);
    after_1:
    // 0x800C038C: lb          $t6, 0x166($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X166);
L_800C0390:
    // 0x800C0390: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800C0394: bnel        $t6, $at, L_800C0428
    if (ctx->r14 != ctx->r1) {
        // 0x800C0398: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0428;
    }
    goto skip_2;
    // 0x800C0398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800C039C: lbu         $t7, 0x15E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15E);
    // 0x800C03A0: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x800C03A4: b           L_800C0424
    // 0x800C03A8: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
        goto L_800C0424;
    // 0x800C03A8: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
    // 0x800C03AC: lb          $t9, 0x166($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X166);
L_800C03B0:
    // 0x800C03B0: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    // 0x800C03B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C03B8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800C03BC: sb          $t0, 0x166($s0)
    MEM_B(0X166, ctx->r16) = ctx->r8;
    // 0x800C03C0: lb          $t1, 0x166($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X166);
    // 0x800C03C4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800C03C8: beq         $a0, $zero, L_800C03EC
    if (ctx->r4 == 0) {
        // 0x800C03CC: lb          $v0, -0x5840($v0)
        ctx->r2 = MEM_B(ctx->r2, -0X5840);
            goto L_800C03EC;
    }
    // 0x800C03CC: lb          $v0, -0x5840($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X5840);
    // 0x800C03D0: lh          $t2, 0x128($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X128);
    // 0x800C03D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C03D8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C03DC: sh          $t3, 0x128($s0)
    MEM_H(0X128, ctx->r16) = ctx->r11;
    // 0x800C03E0: jal         0x80087C10
    // 0x800C03E4: lh          $a1, 0x128($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X128);
    _gczoombox_entrypoint_38(rdram, ctx);
        goto after_2;
    // 0x800C03E4: lh          $a1, 0x128($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X128);
    after_2:
    // 0x800C03E8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_800C03EC:
    // 0x800C03EC: lw          $a0, 0x124($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X124);
    // 0x800C03F0: beql        $a0, $zero, L_800C0410
    if (ctx->r4 == 0) {
        // 0x800C03F4: lb          $t6, 0x166($s0)
        ctx->r14 = MEM_B(ctx->r16, 0X166);
            goto L_800C0410;
    }
    goto skip_3;
    // 0x800C03F4: lb          $t6, 0x166($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X166);
    skip_3:
    // 0x800C03F8: lh          $t4, 0x12A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X12A);
    // 0x800C03FC: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C0400: sh          $t5, 0x12A($s0)
    MEM_H(0X12A, ctx->r16) = ctx->r13;
    // 0x800C0404: jal         0x80087C10
    // 0x800C0408: lh          $a1, 0x12A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X12A);
    _gczoombox_entrypoint_38(rdram, ctx);
        goto after_3;
    // 0x800C0408: lh          $a1, 0x12A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X12A);
    after_3:
    // 0x800C040C: lb          $t6, 0x166($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X166);
L_800C0410:
    // 0x800C0410: bnel        $t6, $zero, L_800C0428
    if (ctx->r14 != 0) {
        // 0x800C0414: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0428;
    }
    goto skip_4;
    // 0x800C0414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800C0418: lbu         $t7, 0x15E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15E);
    // 0x800C041C: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x800C0420: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
L_800C0424:
    // 0x800C0424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C0428:
    // 0x800C0428: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C042C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C0430: jr          $ra
    // 0x800C0434: nop

    return;
    // 0x800C0434: nop

;}
RECOMP_FUNC void func_800944F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800944F8: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800944FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80094500: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80094504: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80094508: jr          $ra
    // 0x8009450C: lbu         $v0, 0x7E3D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7E3D);
    return;
    // 0x8009450C: lbu         $v0, 0x7E3D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7E3D);
;}
RECOMP_FUNC void func_80802508_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080250C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802510: jal         0x800A3280
    // 0x80802514: nop

    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x80802514: nop

    after_0:
    // 0x80802518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080251C: lui         $t7, 0x8081
    ctx->r15 = S32(RELOC_HI16(439, 0XAFCC) << 16);
    // 0x80802520: addiu       $t7, $t7, -0x5034
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(439, 0XAFCC));
    // 0x80802524: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80802528: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8080252C: jr          $ra
    // 0x80802530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80802530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D3D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D28: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D3D2C: addiu       $v1, $v1, -0x4C10
    ctx->r3 = ADD32(ctx->r3, -0X4C10);
    // 0x800D3D30: lbu         $t6, 0x9($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X9);
    // 0x800D3D34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D3D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D3D3C: beql        $t6, $zero, L_800D3D50
    if (ctx->r14 == 0) {
        // 0x800D3D40: sb          $t7, 0x9($v1)
        MEM_B(0X9, ctx->r3) = ctx->r15;
            goto L_800D3D50;
    }
    goto skip_0;
    // 0x800D3D40: sb          $t7, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r15;
    skip_0:
    // 0x800D3D44: jr          $ra
    // 0x800D3D48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D3D48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D3D4C: sb          $t7, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r15;
L_800D3D50:
    // 0x800D3D50: jr          $ra
    // 0x800D3D54: nop

    return;
    // 0x800D3D54: nop

;}
RECOMP_FUNC void func_80800000_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800014: jal         0x80091A58
    // 0x80800018: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8080001C: beq         $v0, $zero, L_80800028
    if (ctx->r2 == 0) {
        // 0x80800020: nop
    
            goto L_80800028;
    }
    // 0x80800020: nop

    // 0x80800024: addiu       $s0, $zero, 0x16E
    ctx->r16 = ADD32(0, 0X16E);
L_80800028:
    // 0x80800028: jal         0x8008E148
    // 0x8080002C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008E148(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800030: beq         $v0, $zero, L_8080003C
    if (ctx->r2 == 0) {
        // 0x80800034: nop
    
            goto L_8080003C;
    }
    // 0x80800034: nop

    // 0x80800038: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8080003C:
    // 0x8080003C: jal         0x8008E260
    // 0x80800040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008E260(rdram, ctx);
        goto after_2;
    // 0x80800040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800044: beq         $v0, $zero, L_80800050
    if (ctx->r2 == 0) {
        // 0x80800048: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800050;
    }
    // 0x80800048: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080004C: addiu       $s0, $zero, 0x3D
    ctx->r16 = ADD32(0, 0X3D);
L_80800050:
    // 0x80800050: jal         0x80091A30
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800058: beq         $v0, $zero, L_80800064
    if (ctx->r2 == 0) {
        // 0x8080005C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800064;
    }
    // 0x8080005C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800060: addiu       $s0, $zero, 0x16B
    ctx->r16 = ADD32(0, 0X16B);
L_80800064:
    // 0x80800064: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800068: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080006C: jr          $ra
    // 0x80800070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800000_chwallsnakebaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800018: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080001C: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80800020: beq         $at, $zero, L_80800268
    if (ctx->r1 == 0) {
        // 0x80800024: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800268;
    }
    // 0x80800024: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800028: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1856, 0X680) << 16);
    // 0x8080002C: addu        $at, $at, $t8
    gpr jr_addend_80800034 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800030: lw          $t8, 0x680($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1856, 0X680));
    // 0x80800034: jr          $t8
    // 0x80800038: nop

    switch (jr_addend_80800034 >> 2) {
        case 0: goto L_8080003C; break;
        case 1: goto L_80800190; break;
        case 2: goto L_80800190; break;
        case 3: goto L_80800224; break;
        case 4: goto L_80800224; break;
        default: switch_error(__func__, 0x80800034, 0x80800680);
    }
    // 0x80800038: nop

L_8080003C:
    // 0x8080003C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800040: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800044: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800048: nop

    // 0x8080004C: bc1f        L_8080006C
    if (!c1cs) {
        // 0x80800050: nop
    
            goto L_8080006C;
    }
    // 0x80800050: nop

    // 0x80800054: jal         0x800D8FF8
    // 0x80800058: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800058: nop

    after_0:
    // 0x8080005C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800060: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800064: b           L_80800268
    // 0x80800068: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80800268;
    // 0x80800068: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_8080006C:
    // 0x8080006C: jal         0x800F54E4
    // 0x80800070: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800070: nop

    after_1:
    // 0x80800074: jal         0x800F5F7C
    // 0x80800078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5F7C(rdram, ctx);
        goto after_2;
    // 0x80800078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080007C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80800080: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8080008C: srl         $v0, $t9, 31
    ctx->r2 = S32(U32(ctx->r25) >> 31);
    // 0x80800090: beq         $v0, $zero, L_808000B8
    if (ctx->r2 == 0) {
        // 0x80800094: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808000B8;
    }
    // 0x80800094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800098: jal         0x80089BD8
    // 0x8080009C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x8080009C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x808000A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000A4: beq         $v0, $at, L_808000E0
    if (ctx->r2 == ctx->r1) {
        // 0x808000A8: lwc1        $f2, 0x2C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_808000E0;
    }
    // 0x808000A8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000AC: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x808000B0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x808000B4: srl         $v0, $t1, 31
    ctx->r2 = S32(U32(ctx->r9) >> 31);
L_808000B8:
    // 0x808000B8: bnel        $v0, $zero, L_8080026C
    if (ctx->r2 != 0) {
        // 0x808000BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080026C;
    }
    goto skip_0;
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000C0: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x808000C4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x808000C8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000CC: srl         $t3, $a1, 7
    ctx->r11 = S32(U32(ctx->r5) >> 7);
    // 0x808000D0: jal         0x8010CA74
    // 0x808000D4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8010CA74(rdram, ctx);
        goto after_4;
    // 0x808000D4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_4:
    // 0x808000D8: beq         $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x808000DC: lwc1        $f2, 0x2C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_80800268;
    }
    // 0x808000DC: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
L_808000E0:
    // 0x808000E0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808000E4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x808000F0: nop

    // 0x808000F4: bc1fl       L_8080012C
    if (!c1cs) {
        // 0x808000F8: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8080012C;
    }
    goto skip_1;
    // 0x808000F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_1:
    // 0x808000FC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800100: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800108: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8080010C: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x80800110: nop

    // 0x80800114: bc1f        L_80800148
    if (!c1cs) {
        // 0x80800118: nop
    
            goto L_80800148;
    }
    // 0x80800118: nop

    // 0x8080011C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800120: b           L_80800148
    // 0x80800124: nop

        goto L_80800148;
    // 0x80800124: nop

    // 0x80800128: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8080012C:
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800130: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800134: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x80800138: nop

    // 0x8080013C: bc1f        L_80800148
    if (!c1cs) {
        // 0x80800140: nop
    
            goto L_80800148;
    }
    // 0x80800140: nop

    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800148:
    // 0x80800148: beql        $a1, $zero, L_8080026C
    if (ctx->r5 == 0) {
        // 0x8080014C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080026C;
    }
    goto skip_2;
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800150: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80800154: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800158: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080015C: bc1f        L_8080016C
    if (!c1cs) {
        // 0x80800160: nop
    
            goto L_8080016C;
    }
    // 0x80800160: nop

    // 0x80800164: b           L_8080016C
    // 0x80800168: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_8080016C;
    // 0x80800168: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8080016C:
    // 0x8080016C: jal         0x80102424
    // 0x80800170: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800170: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800174: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1856, 0X6F4) << 16);
    // 0x80800178: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080017C: addiu       $a2, $a2, 0x6F4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1856, 0X6F4));
    // 0x80800180: jal         0x80089D18
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800188: b           L_8080026C
    // 0x8080018C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080026C;
    // 0x8080018C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800190:
    // 0x80800190: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
    // 0x80800194: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80800198: jal         0x80101E14
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_7;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001A0: bne         $v0, $zero, L_808001B8
    if (ctx->r2 != 0) {
        // 0x808001A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B8;
    }
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: lui         $a1, 0x3E9E
    ctx->r5 = S32(0X3E9E << 16);
    // 0x808001AC: jal         0x80101E14
    // 0x808001B0: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x808001B0: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    after_8:
    // 0x808001B4: beq         $v0, $zero, L_808001CC
    if (ctx->r2 == 0) {
        // 0x808001B8: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1856, 0X700) << 16);
            goto L_808001CC;
    }
L_808001B8:
    // 0x808001B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1856, 0X700) << 16);
    // 0x808001BC: addiu       $a2, $a2, 0x700
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1856, 0X700));
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: jal         0x80089D18
    // 0x808001C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x808001C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
L_808001CC:
    // 0x808001CC: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x808001D0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808001D4: jal         0x80101E14
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_10;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001DC: beq         $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x808001E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F4;
    }
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1856, 0X710) << 16);
    // 0x808001E8: addiu       $a2, $a2, 0x710
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1856, 0X710));
    // 0x808001EC: jal         0x80089D18
    // 0x808001F0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x808001F0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_11:
L_808001F4:
    // 0x808001F4: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808001F8: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808001FC: jal         0x80101E14
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_12;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800204: beq         $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x80800208: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800268;
    }
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x80102424
    // 0x80800210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x80800210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800214: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1856, 0X694) << 16);
    // 0x80800218: lwc1        $f8, 0x694($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1856, 0X694));
    // 0x8080021C: b           L_80800268
    // 0x80800220: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80800268;
    // 0x80800220: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800224:
    // 0x80800224: jal         0x80101DDC
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_14;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080022C: beq         $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x80800230: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080023C;
    }
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: jal         0x80107070
    // 0x80800238: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_15;
    // 0x80800238: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
L_8080023C:
    // 0x8080023C: jal         0x80101F24
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_16;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800244: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1856, 0X698) << 16);
    // 0x80800248: lwc1        $f10, 0x698($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1856, 0X698));
    // 0x8080024C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800250: nop

    // 0x80800254: bc1fl       L_8080026C
    if (!c1cs) {
        // 0x80800258: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080026C;
    }
    goto skip_3;
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8080025C: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800260: andi        $t5, $t4, 0xFFF7
    ctx->r13 = ctx->r12 & 0XFFF7;
    // 0x80800264: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80800268:
    // 0x80800268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080026C:
    // 0x8080026C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800270: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800274: jr          $ra
    // 0x80800278: nop

    return;
    // 0x80800278: nop

;}
RECOMP_FUNC void func_800985C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800985C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800985C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800985CC: jal         0x8009C128
    // 0x800985D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800985D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800985D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800985D8: addiu       $a0, $a0, 0x7EB0
    ctx->r4 = ADD32(ctx->r4, 0X7EB0);
    // 0x800985DC: jal         0x800882A8
    // 0x800985E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gccubesearch_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x800985E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800985E4: bne         $v0, $zero, L_800985F4
    if (ctx->r2 != 0) {
        // 0x800985E8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800985F4;
    }
    // 0x800985E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800985EC: b           L_80098600
    // 0x800985F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80098600;
    // 0x800985F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800985F4:
    // 0x800985F4: jal         0x80088C00
    // 0x800985F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x800985F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800985FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80098600:
    // 0x80098600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098608: jr          $ra
    // 0x8009860C: nop

    return;
    // 0x8009860C: nop

;}
RECOMP_FUNC void func_80800B88_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800B94: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800B98: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80800B9C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800BA0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800BA4: beq         $v0, $zero, L_80800BC8
    if (ctx->r2 == 0) {
        // 0x80800BA8: addiu       $a1, $zero, 0x11
        ctx->r5 = ADD32(0, 0X11);
            goto L_80800BC8;
    }
    // 0x80800BA8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80800BAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800BB0: beq         $v0, $at, L_80800BE0
    if (ctx->r2 == ctx->r1) {
        // 0x80800BB4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800BE0;
    }
    // 0x80800BB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BB8: beql        $v0, $at, L_80800BDC
    if (ctx->r2 == ctx->r1) {
        // 0x80800BBC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800BDC;
    }
    goto skip_0;
    // 0x80800BBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x80800BC0: b           L_80800BF4
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800BF4;
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BC8:
    // 0x80800BC8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800BCC: jal         0x800856B0
    // 0x80800BD0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800BD0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800BD4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800BD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80800BDC:
    // 0x80800BDC: sw          $t6, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r14;
L_80800BE0:
    // 0x80800BE0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800BE4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BE8: jal         0x800856D0
    // 0x80800BEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800BEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BF4:
    // 0x80800BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BF8: jr          $ra
    // 0x80800BFC: nop

    return;
    // 0x80800BFC: nop

;}
