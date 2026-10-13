#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800040_baeggfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800044: sb          $zero, 0x12($t6)
    MEM_B(0X12, ctx->r14) = 0;
    // 0x80800048: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x8080004C: sb          $zero, 0x11($t7)
    MEM_B(0X11, ctx->r15) = 0;
    // 0x80800050: lw          $t8, 0x6C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X6C);
    // 0x80800054: jr          $ra
    // 0x80800058: sb          $zero, 0x13($t8)
    MEM_B(0X13, ctx->r24) = 0;
    return;
    // 0x80800058: sb          $zero, 0x13($t8)
    MEM_B(0X13, ctx->r24) = 0;
;}
RECOMP_FUNC void func_80800000_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x8009E69C
    // 0x80800014: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E69C(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800018: bnel        $v0, $zero, L_80800058
    if (ctx->r2 != 0) {
        // 0x8080001C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800058;
    }
    goto skip_0;
    // 0x8080001C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800020: jal         0x8009BC90
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800028: jal         0x8009BC6C
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: jal         0x800961AC
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080003C: jal         0x8009F258
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_func_8009F258(rdram, ctx);
        goto after_4;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800044: jal         0x800A1040
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1040(rdram, ctx);
        goto after_5;
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080004C: jal         0x800832E8
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800058:
    // 0x80800058: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void badrone_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800030: lw          $a1, 0x54($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X54);
    // 0x80800034: jal         0x800EE7F8
    // 0x80800038: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_0:
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800044: jr          $ra
    // 0x80800048: nop

    return;
    // 0x80800048: nop

;}
RECOMP_FUNC void func_8008DEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DEA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008DEA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DEAC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008DEB0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8008DEB4: jal         0x8009C128
    // 0x8008DEB8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8008DEB8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8008DEBC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DEC0: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8008DEC4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008DEC8: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8008DECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008DED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DED4: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8008DED8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8008DEDC: nop

    // 0x8008DEE0: bc1f        L_8008DEEC
    if (!c1cs) {
        // 0x8008DEE4: nop
    
            goto L_8008DEEC;
    }
    // 0x8008DEE4: nop

    // 0x8008DEE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DEEC:
    // 0x8008DEEC: beq         $v0, $zero, L_8008DF10
    if (ctx->r2 == 0) {
        // 0x8008DEF0: nop
    
            goto L_8008DF10;
    }
    // 0x8008DEF0: nop

    // 0x8008DEF4: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8008DEF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008DEFC: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x8008DF00: nop

    // 0x8008DF04: bc1f        L_8008DF10
    if (!c1cs) {
        // 0x8008DF08: nop
    
            goto L_8008DF10;
    }
    // 0x8008DF08: nop

    // 0x8008DF0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DF10:
    // 0x8008DF10: jr          $ra
    // 0x8008DF14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008DF14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsclimb_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800530: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800534: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800538: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080053C: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800540: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800544: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800548: jal         0x8008CB3C
    // 0x8080054C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x8080054C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: jal         0x8008CA4C
    // 0x80800558: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8008CA4C(rdram, ctx);
        goto after_1;
    // 0x80800558: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8080055C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800560: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: jal         0x8008C9BC
    // 0x8080056C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_2;
    // 0x8080056C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_2:
    // 0x80800570: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(144, 0X8B4) << 16);
    // 0x80800574: lwc1        $f4, 0x8B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(144, 0X8B4));
    // 0x80800578: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x8080057C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800588: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x8080058C: jal         0x8008C9F0
    // 0x80800590: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_3;
    // 0x80800590: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800594: jal         0x808000E8
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000E8_bsclimb(rdram, ctx);
        goto after_4;
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080059C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005A8: jr          $ra
    // 0x808005AC: nop

    return;
    // 0x808005AC: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084288: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084288);
    return;
    // 0x8008428C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800078_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8080007C: addiu       $v1, $v1, 0x7610
    ctx->r3 = ADD32(ctx->r3, 0X7610);
    // 0x80800080: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x80800084: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800088: bnel        $t6, $at, L_808000A4
    if (ctx->r14 != ctx->r1) {
        // 0x8080008C: lbu         $v0, 0x0($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X0);
            goto L_808000A4;
    }
    goto skip_0;
    // 0x8080008C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    skip_0:
    // 0x80800090: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80800094: sltiu       $t7, $v0, 0x51
    ctx->r15 = ctx->r2 < 0X51 ? 1 : 0;
    // 0x80800098: jr          $ra
    // 0x8080009C: xori        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 ^ 0X1;
    return;
    // 0x8080009C: xori        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 ^ 0X1;
    // 0x808000A0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
L_808000A4:
    // 0x808000A4: sltiu       $t8, $v0, 0x16
    ctx->r24 = ctx->r2 < 0X16 ? 1 : 0;
    // 0x808000A8: xori        $v0, $t8, 0x1
    ctx->r2 = ctx->r24 ^ 0X1;
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_80800000_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800010: beq         $a1, $at, L_8080002C
    if (ctx->r5 == ctx->r1) {
        // 0x80800014: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080002C;
    }
    // 0x80800014: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800018: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080001C: beq         $a1, $at, L_80800078
    if (ctx->r5 == ctx->r1) {
        // 0x80800020: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800078;
    }
    // 0x80800020: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800024: b           L_80800094
    // 0x80800028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800094;
    // 0x80800028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080002C:
    // 0x8080002C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80800030: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    // 0x80800034: jal         0x800D731C
    // 0x80800038: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800D731C(rdram, ctx);
        goto after_0;
    // 0x80800038: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080003C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800040: jal         0x801015D0
    // 0x80800044: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x80800044: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800048: lbu         $a3, 0x1F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1F);
    // 0x8080004C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800050: beql        $a3, $zero, L_80800094
    if (ctx->r7 == 0) {
        // 0x80800054: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800094;
    }
    goto skip_0;
    // 0x80800054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800058: lbu         $a2, 0x79($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X79);
    // 0x8080005C: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800064: srl         $t8, $a2, 4
    ctx->r24 = S32(U32(ctx->r6) >> 4);
    // 0x80800068: jal         0x800DBE60
    // 0x8080006C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_800DBE60(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_2:
    // 0x80800070: b           L_80800094
    // 0x80800074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800094;
    // 0x80800074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800078:
    // 0x80800078: jal         0x80800978
    // 0x8080007C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800978_chfiregen(rdram, ctx);
        goto after_3;
    // 0x8080007C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800080: b           L_80800094
    // 0x80800084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800094;
    // 0x80800084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800088: b           L_80800094
    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800094;
    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800094:
    // 0x80800094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800098: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void func_808038EC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808038EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808038F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808038F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808038F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808038FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80803900: jal         0x80016BDC
    // 0x80803904: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80016BDC(rdram, ctx);
        goto after_0;
    // 0x80803904: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80803908: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080390C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80803910: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80803914: addiu       $a1, $a1, -0x7E98
    ctx->r5 = ADD32(ctx->r5, -0X7E98);
    // 0x80803918: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8080391C: jal         0x800C9E20
    // 0x80803920: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800C9E20(rdram, ctx);
        goto after_1;
    // 0x80803920: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80803924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803928: jal         0x80800478
    // 0x8080392C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800478_chgameselect(rdram, ctx);
        goto after_2;
    // 0x8080392C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80803930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803938: jr          $ra
    // 0x8080393C: nop

    return;
    // 0x8080393C: nop

;}
RECOMP_FUNC void func_800B2C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2C1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B2C20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B2C24: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x800B2C28: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800B2C2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B2C30: sll         $a0, $t6, 16
    ctx->r4 = S32(ctx->r14 << 16);
    // 0x800B2C34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B2C38: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B2C3C: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2C40: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800B2C44: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800B2C48: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B2C4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B2C50: jal         0x8001B798
    // 0x800B2C54: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800B2C54: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800B2C58: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800B2C5C: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2C60: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800B2C64: jal         0x800B2A58
    // 0x800B2C68: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800B2A58(rdram, ctx);
        goto after_1;
    // 0x800B2C68: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x800B2C6C: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800B2C70: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x800B2C74: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800B2C78: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x800B2C7C: div         $zero, $t0, $a2
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r6)));
    // 0x800B2C80: bne         $a2, $zero, L_800B2C8C
    if (ctx->r6 != 0) {
        // 0x800B2C84: nop
    
            goto L_800B2C8C;
    }
    // 0x800B2C84: nop

    // 0x800B2C88: break       7
    do_break(2148215944);
L_800B2C8C:
    // 0x800B2C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2C90: bne         $a2, $at, L_800B2CA4
    if (ctx->r6 != ctx->r1) {
        // 0x800B2C94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B2CA4;
    }
    // 0x800B2C94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2C98: bne         $t0, $at, L_800B2CA4
    if (ctx->r8 != ctx->r1) {
        // 0x800B2C9C: nop
    
            goto L_800B2CA4;
    }
    // 0x800B2C9C: nop

    // 0x800B2CA0: break       6
    do_break(2148215968);
L_800B2CA4:
    // 0x800B2CA4: mflo        $s0
    ctx->r16 = lo;
    // 0x800B2CA8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800B2CAC: slt         $at, $s3, $s0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B2CB0: beq         $at, $zero, L_800B2CFC
    if (ctx->r1 == 0) {
        // 0x800B2CB4: nop
    
            goto L_800B2CFC;
    }
    // 0x800B2CB4: nop

L_800B2CB8:
    // 0x800B2CB8: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800B2CBC: addiu       $s1, $s0, -0x1
    ctx->r17 = ADD32(ctx->r16, -0X1);
    // 0x800B2CC0: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800B2CC4: multu       $s0, $a2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2CC8: mflo        $t1
    ctx->r9 = lo;
    // 0x800B2CCC: addu        $a0, $v1, $t1
    ctx->r4 = ADD32(ctx->r3, ctx->r9);
    // 0x800B2CD0: nop

    // 0x800B2CD4: multu       $s1, $a2
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2CD8: mflo        $t2
    ctx->r10 = lo;
    // 0x800B2CDC: addu        $a1, $v1, $t2
    ctx->r5 = ADD32(ctx->r3, ctx->r10);
    // 0x800B2CE0: jal         0x8001BBC8
    // 0x800B2CE4: nop

    aligned4_memcpy(rdram, ctx);
        goto after_2;
    // 0x800B2CE4: nop

    after_2:
    // 0x800B2CE8: slt         $at, $s3, $s1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800B2CEC: bne         $at, $zero, L_800B2CB8
    if (ctx->r1 != 0) {
        // 0x800B2CF0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800B2CB8;
    }
    // 0x800B2CF0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800B2CF4: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800B2CF8: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
L_800B2CFC:
    // 0x800B2CFC: multu       $s3, $a2
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2D00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B2D04: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B2D08: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B2D0C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B2D10: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2D14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B2D18: mflo        $t3
    ctx->r11 = lo;
    // 0x800B2D1C: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x800B2D20: jr          $ra
    // 0x800B2D24: nop

    return;
    // 0x800B2D24: nop

;}
RECOMP_FUNC void func_800E94E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E94E4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800E94E8: addiu       $a1, $t6, -0x2970
    ctx->r5 = ADD32(ctx->r14, -0X2970);
    // 0x800E94EC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800E94F0: addiu       $a2, $a2, -0x28D2
    ctx->r6 = ADD32(ctx->r6, -0X28D2);
    // 0x800E94F4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800E94F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800E94FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800E9500:
    // 0x800E9500: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800E9504: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800E9508: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x800E950C: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    // 0x800E9510: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E9514: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800E9518: sh          $v0, 0x18E($a1)
    MEM_H(0X18E, ctx->r5) = ctx->r2;
    // 0x800E951C: bne         $at, $zero, L_800E9500
    if (ctx->r1 != 0) {
        // 0x800E9520: sh          $v0, 0x22E($a1)
        MEM_H(0X22E, ctx->r5) = ctx->r2;
            goto L_800E9500;
    }
    // 0x800E9520: sh          $v0, 0x22E($a1)
    MEM_H(0X22E, ctx->r5) = ctx->r2;
    // 0x800E9524: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9528: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E952C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9530: addiu       $a0, $a0, 0x2DA8
    ctx->r4 = ADD32(ctx->r4, 0X2DA8);
    // 0x800E9534: addiu       $v1, $v1, 0x2650
    ctx->r3 = ADD32(ctx->r3, 0X2650);
    // 0x800E9538: sw          $zero, 0x2558($at)
    MEM_W(0X2558, ctx->r1) = 0;
    // 0x800E953C: sw          $zero, 0x255C($at)
    MEM_W(0X255C, ctx->r1) = 0;
    // 0x800E9540: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800E9544:
    // 0x800E9544: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E9548: sb          $v0, -0x6($v1)
    MEM_B(-0X6, ctx->r3) = ctx->r2;
    // 0x800E954C: sb          $v0, -0x5($v1)
    MEM_B(-0X5, ctx->r3) = ctx->r2;
    // 0x800E9550: sb          $v0, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r2;
    // 0x800E9554: sb          $v0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r2;
    // 0x800E9558: sb          $v0, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r2;
    // 0x800E955C: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // 0x800E9560: sb          $v0, -0x8($v1)
    MEM_B(-0X8, ctx->r3) = ctx->r2;
    // 0x800E9564: bne         $v1, $a0, L_800E9544
    if (ctx->r3 != ctx->r4) {
        // 0x800E9568: sb          $v0, -0x7($v1)
        MEM_B(-0X7, ctx->r3) = ctx->r2;
            goto L_800E9544;
    }
    // 0x800E9568: sb          $v0, -0x7($v1)
    MEM_B(-0X7, ctx->r3) = ctx->r2;
    // 0x800E956C: jr          $ra
    // 0x800E9570: nop

    return;
    // 0x800E9570: nop

;}
RECOMP_FUNC void func_8080299C_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080299C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x808029A0: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x808029A4: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x808029A8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808029AC: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x808029B0: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x808029B4: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x808029B8: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x808029BC: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x808029C0: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808029C4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808029C8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808029CC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808029D0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808029D4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808029D8: jal         0x80100094
    // 0x808029DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808029DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808029E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808029E4: jal         0x800B53A4
    // 0x808029E8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x808029E8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x808029EC: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x808029F0: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1240, 0X38A0) << 16);
    // 0x808029F4: addiu       $t9, $t9, 0x38A0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1240, 0X38A0));
    // 0x808029F8: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x808029FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80802A00: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80802A04: addiu       $t8, $t7, 0x7E
    ctx->r24 = ADD32(ctx->r15, 0X7E);
    // 0x80802A08: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802A0C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80802A10: jal         0x800BAB80
    // 0x80802A14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BAB80(rdram, ctx);
        goto after_2;
    // 0x80802A14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80802A18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802A1C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80802A20: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80802A24: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80802A28: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80802A2C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80802A30: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80802A34: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80802A38: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80802A3C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80802A40: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80802A44: addiu       $s2, $s1, 0x4
    ctx->r18 = ADD32(ctx->r17, 0X4);
    // 0x80802A48: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(1240, 0X3CC0) << 16);
    // 0x80802A4C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80802A50: addiu       $s4, $s4, 0x3CC0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(1240, 0X3CC0));
    // 0x80802A54: addiu       $s1, $sp, 0x74
    ctx->r17 = ADD32(ctx->r29, 0X74);
    // 0x80802A58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802A5C: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x80802A60: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_80802A64:
    // 0x80802A64: jal         0x800DC178
    // 0x80802A68: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80802A68: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_3:
    // 0x80802A6C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80802A70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802A74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802A78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802A7C: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80802A80: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80802A84: jal         0x800EEB9C
    // 0x80802A88: nop

    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x80802A88: nop

    after_4:
    // 0x80802A8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802A90: jal         0x800EF04C
    // 0x80802A94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80802A94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80802A98: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80802A9C: jal         0x800DC178
    // 0x80802AA0: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80802AA0: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_6:
    // 0x80802AA4: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80802AA8: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80802AAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802AB0: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80802AB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80802AB8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80802ABC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80802AC0: jal         0x800BABB8
    // 0x80802AC4: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80802AC4: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x80802AC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802ACC: bnel        $s0, $s5, L_80802A64
    if (ctx->r16 != ctx->r21) {
        // 0x80802AD0: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_80802A64;
    }
    goto skip_0;
    // 0x80802AD0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_0:
    // 0x80802AD4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80802AD8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80802ADC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80802AE0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80802AE4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80802AE8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80802AEC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80802AF0: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80802AF4: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80802AF8: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80802AFC: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80802B00: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x80802B04: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80802B08: jr          $ra
    // 0x80802B0C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80802B0C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80802F3C_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F3C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80802F40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802F44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802F48: jal         0x800169A8
    // 0x80802F4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800169A8(rdram, ctx);
        goto after_0;
    // 0x80802F4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802F50: jal         0x800D9004
    // 0x80802F54: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800D9004(rdram, ctx);
        goto after_1;
    // 0x80802F54: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802F58: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80802F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802F60: jal         0x80100094
    // 0x80802F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80802F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80802F68: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80802F6C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80802F70: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80802F74: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80802F78: beq         $t6, $at, L_80803550
    if (ctx->r14 == ctx->r1) {
        // 0x80802F7C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80803550;
    }
    // 0x80802F7C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80802F80: beql        $t6, $at, L_80803554
    if (ctx->r14 == ctx->r1) {
        // 0x80802F84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803554;
    }
    goto skip_0;
    // 0x80802F84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802F88: jal         0x808007BC
    // 0x80802F8C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_808007BC_chjiggygamenew(rdram, ctx);
        goto after_3;
    // 0x80802F8C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x80802F90: beq         $v0, $zero, L_80803550
    if (ctx->r2 == 0) {
        // 0x80802F94: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_80803550;
    }
    // 0x80802F94: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80802F98: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80802F9C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80802FA0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80802FA4: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x80802FA8: beq         $t7, $at, L_8080320C
    if (ctx->r15 == ctx->r1) {
        // 0x80802FAC: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_8080320C;
    }
    // 0x80802FAC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80802FB0: lb          $a0, 0x2($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X2);
    // 0x80802FB4: jal         0x80015D60
    // 0x80802FB8: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    func_80015D60(rdram, ctx);
        goto after_4;
    // 0x80802FB8: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    after_4:
    // 0x80802FBC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80802FC0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80802FC4: addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    // 0x80802FC8: lb          $a0, 0x3($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X3);
    // 0x80802FCC: jal         0x80015D60
    // 0x80802FD0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80015D60(rdram, ctx);
        goto after_5;
    // 0x80802FD0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80802FD4: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80802FD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80802FDC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80802FE0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80802FE4: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x80802FE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802FEC: bc1tl       L_80803014
    if (c1cs) {
        // 0x80802FF0: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80803014;
    }
    goto skip_1;
    // 0x80802FF0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80802FF4: lwc1        $f6, 0x3C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80802FF8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80802FFC: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80803000: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80803004: nop

    // 0x80803008: bc1f        L_80803020
    if (!c1cs) {
        // 0x8080300C: nop
    
            goto L_80803020;
    }
    // 0x8080300C: nop

    // 0x80803010: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_80803014:
    // 0x80803014: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80803018: b           L_80803060
    // 0x8080301C: swc1        $f2, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f2.u32l;
        goto L_80803060;
    // 0x8080301C: swc1        $f2, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f2.u32l;
L_80803020:
    // 0x80803020: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3AA8) << 16);
    // 0x80803024: lwc1        $f4, 0x3AA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3AA8));
    // 0x80803028: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x8080302C: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80803030: mul.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80803034: jal         0x800F2100
    // 0x80803038: nop

    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x80803038: nop

    after_6:
    // 0x8080303C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803040: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80803044: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80803048: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080304C: add.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80803050: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80803054: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80803058: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080305C: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_80803060:
    // 0x80803060: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80803064: nop

    // 0x80803068: c.eq.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl == ctx->f4.fl;
    // 0x8080306C: nop

    // 0x80803070: bc1t        L_80803098
    if (c1cs) {
        // 0x80803074: nop
    
            goto L_80803098;
    }
    // 0x80803074: nop

    // 0x80803078: lwc1        $f6, 0x40($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X40);
    // 0x8080307C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80803080: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3AAC) << 16);
    // 0x80803084: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80803088: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8080308C: nop

    // 0x80803090: bc1f        L_808030A0
    if (!c1cs) {
        // 0x80803094: nop
    
            goto L_808030A0;
    }
    // 0x80803094: nop

L_80803098:
    // 0x80803098: b           L_808030DC
    // 0x8080309C: swc1        $f2, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f2.u32l;
        goto L_808030DC;
    // 0x8080309C: swc1        $f2, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f2.u32l;
L_808030A0:
    // 0x808030A0: lwc1        $f4, 0x3AAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3AAC));
    // 0x808030A4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x808030A8: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x808030AC: mul.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x808030B0: jal         0x800F2100
    // 0x808030B4: nop

    mlAbsF(rdram, ctx);
        goto after_7;
    // 0x808030B4: nop

    after_7:
    // 0x808030B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808030BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808030C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808030C4: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808030C8: add.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x808030CC: lwc1        $f6, 0x34($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X34);
    // 0x808030D0: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808030D4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808030D8: swc1        $f10, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f10.u32l;
L_808030DC:
    // 0x808030DC: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808030E0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808030E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808030E8: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x808030EC: lwc1        $f8, 0x34($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X34);
    // 0x808030F0: swc1        $f16, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f16.u32l;
    // 0x808030F4: swc1        $f14, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f14.u32l;
    // 0x808030F8: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x808030FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80803100: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80803104: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80803108: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080310C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803110: lui         $at, 0x431A
    ctx->r1 = S32(0X431A << 16);
    // 0x80803114: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803118: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080311C: nop

    // 0x80803120: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80803124: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80803128: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8080312C: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80803130: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x80803134: lwc1        $f10, 0x30($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80803138: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080313C: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80803140: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80803144: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80803148: bc1f        L_80803158
    if (!c1cs) {
        // 0x8080314C: swc1        $f4, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
            goto L_80803158;
    }
    // 0x8080314C: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x80803150: b           L_8080315C
    // 0x80803154: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8080315C;
    // 0x80803154: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80803158:
    // 0x80803158: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8080315C:
    // 0x8080315C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80803160: nop

    // 0x80803164: bc1fl       L_80803178
    if (!c1cs) {
        // 0x80803168: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_80803178;
    }
    goto skip_2;
    // 0x80803168: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_2:
    // 0x8080316C: b           L_80803194
    // 0x80803170: swc1        $f14, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f14.u32l;
        goto L_80803194;
    // 0x80803170: swc1        $f14, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f14.u32l;
    // 0x80803174: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_80803178:
    // 0x80803178: nop

    // 0x8080317C: bc1fl       L_80803190
    if (!c1cs) {
        // 0x80803180: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80803190;
    }
    goto skip_3;
    // 0x80803180: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_3:
    // 0x80803184: b           L_80803190
    // 0x80803188: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80803190;
    // 0x80803188: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8080318C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80803190:
    // 0x80803190: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_80803194:
    // 0x80803194: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80803198: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8080319C: lui         $at, 0xC307
    ctx->r1 = S32(0XC307 << 16);
    // 0x808031A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808031A4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x808031A8: nop

    // 0x808031AC: bc1fl       L_808031C0
    if (!c1cs) {
        // 0x808031B0: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_808031C0;
    }
    goto skip_4;
    // 0x808031B0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_4:
    // 0x808031B4: b           L_808031C0
    // 0x808031B8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_808031C0;
    // 0x808031B8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x808031BC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_808031C0:
    // 0x808031C0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x808031C4: nop

    // 0x808031C8: bc1fl       L_808031DC
    if (!c1cs) {
        // 0x808031CC: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_808031DC;
    }
    goto skip_5;
    // 0x808031CC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_5:
    // 0x808031D0: b           L_808031F8
    // 0x808031D4: swc1        $f14, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f14.u32l;
        goto L_808031F8;
    // 0x808031D4: swc1        $f14, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f14.u32l;
    // 0x808031D8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_808031DC:
    // 0x808031DC: nop

    // 0x808031E0: bc1fl       L_808031F4
    if (!c1cs) {
        // 0x808031E4: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_808031F4;
    }
    goto skip_6;
    // 0x808031E4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_6:
    // 0x808031E8: b           L_808031F4
    // 0x808031EC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_808031F4;
    // 0x808031EC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x808031F0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_808031F4:
    // 0x808031F4: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_808031F8:
    // 0x808031F8: jal         0x800EE780
    // 0x808031FC: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EE780(rdram, ctx);
        goto after_8;
    // 0x808031FC: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_8:
    // 0x80803200: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80803204: srl         $t3, $v1, 10
    ctx->r11 = S32(U32(ctx->r3) >> 10);
    // 0x80803208: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_8080320C:
    // 0x8080320C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80803210: bne         $at, $zero, L_808032BC
    if (ctx->r1 != 0) {
        // 0x80803214: slti        $at, $v1, 0x5
        ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
            goto L_808032BC;
    }
    // 0x80803214: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x80803218: beq         $at, $zero, L_808032BC
    if (ctx->r1 == 0) {
        // 0x8080321C: nop
    
            goto L_808032BC;
    }
    // 0x8080321C: nop

    // 0x80803220: jal         0x8008A740
    // 0x80803224: nop

    _sujiggy_entrypoint_21(rdram, ctx);
        goto after_9;
    // 0x80803224: nop

    after_9:
    // 0x80803228: beq         $v0, $zero, L_808032BC
    if (ctx->r2 == 0) {
        // 0x8080322C: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_808032BC;
    }
    // 0x8080322C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80803230: lhu         $v0, 0x0($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0X0);
    // 0x80803234: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80803238: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x8080323C: beql        $t5, $zero, L_80803284
    if (ctx->r13 == 0) {
        // 0x80803240: andi        $t1, $v0, 0x1
        ctx->r9 = ctx->r2 & 0X1;
            goto L_80803284;
    }
    goto skip_7;
    // 0x80803240: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    skip_7:
    // 0x80803244: lw          $t7, 0x38($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X38);
    // 0x80803248: addiu       $a0, $zero, 0x487
    ctx->r4 = ADD32(0, 0X487);
    // 0x8080324C: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80803250: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80803254: bnel        $t8, $zero, L_80803284
    if (ctx->r24 != 0) {
        // 0x80803258: andi        $t1, $v0, 0x1
        ctx->r9 = ctx->r2 & 0X1;
            goto L_80803284;
    }
    goto skip_8;
    // 0x80803258: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    skip_8:
    // 0x8080325C: jal         0x800C3F14
    // 0x80803260: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    func_800C3F14(rdram, ctx);
        goto after_10;
    // 0x80803260: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_10:
    // 0x80803264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803268: jal         0x80102424
    // 0x8080326C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x8080326C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80803270: jal         0x80800368
    // 0x80803274: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80800368_chjiggygamenew(rdram, ctx);
        goto after_12;
    // 0x80803274: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_12:
    // 0x80803278: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8080327C: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x80803280: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
L_80803284:
    // 0x80803284: beq         $t1, $zero, L_808032BC
    if (ctx->r9 == 0) {
        // 0x80803288: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_808032BC;
    }
    // 0x80803288: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8080328C: lw          $t3, 0x38($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X38);
    // 0x80803290: addiu       $a0, $zero, 0x487
    ctx->r4 = ADD32(0, 0X487);
    // 0x80803294: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80803298: bne         $t4, $zero, L_808032BC
    if (ctx->r12 != 0) {
        // 0x8080329C: nop
    
            goto L_808032BC;
    }
    // 0x8080329C: nop

    // 0x808032A0: jal         0x800C3F14
    // 0x808032A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800C3F14(rdram, ctx);
        goto after_13;
    // 0x808032A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
    // 0x808032A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032AC: jal         0x80102424
    // 0x808032B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x808032B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x808032B4: jal         0x80800424
    // 0x808032B8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80800424_chjiggygamenew(rdram, ctx);
        goto after_15;
    // 0x808032B8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_15:
L_808032BC:
    // 0x808032BC: jal         0x8080000C
    // 0x808032C0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8080000C_chjiggygamenew(rdram, ctx);
        goto after_16;
    // 0x808032C0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_16:
    // 0x808032C4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808032C8: sw          $v0, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->r2;
    // 0x808032CC: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
    // 0x808032D0: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x808032D4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808032D8: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x808032DC: beq         $at, $zero, L_80803544
    if (ctx->r1 == 0) {
        // 0x808032E0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80803544;
    }
    // 0x808032E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808032E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3AB0) << 16);
    // 0x808032E8: addu        $at, $at, $t7
    gpr jr_addend_808032F0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808032EC: lw          $t7, 0x3AB0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(772, 0X3AB0));
    // 0x808032F0: jr          $t7
    // 0x808032F4: nop

    switch (jr_addend_808032F0 >> 2) {
        case 0: goto L_808032F8; break;
        case 1: goto L_8080339C; break;
        case 2: goto L_808034C0; break;
        case 3: goto L_808034C0; break;
        case 4: goto L_808034E8; break;
        case 5: goto L_80803504; break;
        case 6: goto L_80803544; break;
        case 7: goto L_80803544; break;
        default: switch_error(__func__, 0x808032F0, 0x80803AB0);
    }
    // 0x808032F4: nop

L_808032F8:
    // 0x808032F8: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    // 0x808032FC: blez        $v1, L_8080338C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80803300: slti        $at, $v1, 0x29
        ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
            goto L_8080338C;
    }
    // 0x80803300: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x80803304: beq         $at, $zero, L_8080338C
    if (ctx->r1 == 0) {
        // 0x80803308: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_8080338C;
    }
    // 0x80803308: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8080330C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80803310: andi        $t1, $t9, 0x8000
    ctx->r9 = ctx->r25 & 0X8000;
    // 0x80803314: beql        $t1, $zero, L_80803390
    if (ctx->r9 == 0) {
        // 0x80803318: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_80803390;
    }
    goto skip_9;
    // 0x80803318: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    skip_9:
    // 0x8080331C: lw          $t2, 0x38($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X38);
    // 0x80803320: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x80803324: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x80803328: bnel        $t3, $zero, L_80803390
    if (ctx->r11 != 0) {
        // 0x8080332C: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_80803390;
    }
    goto skip_10;
    // 0x8080332C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    skip_10:
    // 0x80803330: jal         0x80800030
    // 0x80803334: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80800030_chjiggygamenew(rdram, ctx);
        goto after_17;
    // 0x80803334: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_17:
    // 0x80803338: beq         $v0, $zero, L_8080338C
    if (ctx->r2 == 0) {
        // 0x8080333C: lw          $t4, 0x2C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X2C);
            goto L_8080338C;
    }
    // 0x8080333C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80803340: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x80803344: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803348: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8080334C: bne         $v0, $at, L_80803364
    if (ctx->r2 != ctx->r1) {
        // 0x80803350: sw          $t6, 0x28($t4)
        MEM_W(0X28, ctx->r12) = ctx->r14;
            goto L_80803364;
    }
    // 0x80803350: sw          $t6, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r14;
    // 0x80803354: jal         0x800FC660
    // 0x80803358: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_800FC660(rdram, ctx);
        goto after_18;
    // 0x80803358: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_18:
    // 0x8080335C: b           L_80803370
    // 0x80803360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80803370;
    // 0x80803360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803364:
    // 0x80803364: jal         0x800C3E88
    // 0x80803368: addiu       $a0, $zero, 0x47F
    ctx->r4 = ADD32(0, 0X47F);
    func_800C3E88(rdram, ctx);
        goto after_19;
    // 0x80803368: addiu       $a0, $zero, 0x47F
    ctx->r4 = ADD32(0, 0X47F);
    after_19:
    // 0x8080336C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803370:
    // 0x80803370: jal         0x80102424
    // 0x80803374: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x80803374: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_20:
    // 0x80803378: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8080337C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80803380: lw          $a1, 0x2C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X2C);
    // 0x80803384: jal         0x80800030
    // 0x80803388: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_80800030_chjiggygamenew(rdram, ctx);
        goto after_21;
    // 0x80803388: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_21:
L_8080338C:
    // 0x8080338C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80803390:
    // 0x80803390: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80803394: b           L_8080354C
    // 0x80803398: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
        goto L_8080354C;
    // 0x80803398: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
L_8080339C:
    // 0x8080339C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x808033A0: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x808033A4: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x808033A8: beql        $t1, $zero, L_808033F8
    if (ctx->r9 == 0) {
        // 0x808033AC: lw          $v1, 0x2C($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X2C);
            goto L_808033F8;
    }
    goto skip_11;
    // 0x808033AC: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    skip_11:
    // 0x808033B0: lw          $t2, 0x38($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X38);
    // 0x808033B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808033B8: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x808033BC: bnel        $t3, $zero, L_808033F8
    if (ctx->r11 != 0) {
        // 0x808033C0: lw          $v1, 0x2C($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X2C);
            goto L_808033F8;
    }
    goto skip_12;
    // 0x808033C0: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
    skip_12:
    // 0x808033C4: jal         0x80102424
    // 0x808033C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x808033C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_22:
    // 0x808033CC: jal         0x80800158
    // 0x808033D0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80800158_chjiggygamenew(rdram, ctx);
        goto after_23;
    // 0x808033D0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_23:
    // 0x808033D4: jal         0x800FC660
    // 0x808033D8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    func_800FC660(rdram, ctx);
        goto after_24;
    // 0x808033D8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_24:
    // 0x808033DC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808033E0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808033E4: sw          $t5, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r13;
    // 0x808033E8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x808033EC: b           L_8080354C
    // 0x808033F0: lhu         $v0, 0x0($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0X0);
        goto L_8080354C;
    // 0x808033F0: lhu         $v0, 0x0($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0X0);
    // 0x808033F4: lw          $v1, 0x2C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X2C);
L_808033F8:
    // 0x808033F8: slti        $at, $v1, 0x15
    ctx->r1 = SIGNED(ctx->r3) < 0X15 ? 1 : 0;
    // 0x808033FC: bne         $at, $zero, L_8080354C
    if (ctx->r1 != 0) {
        // 0x80803400: slti        $at, $v1, 0x29
        ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
            goto L_8080354C;
    }
    // 0x80803400: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x80803404: beq         $at, $zero, L_8080354C
    if (ctx->r1 == 0) {
        // 0x80803408: andi        $t7, $v0, 0x8000
        ctx->r15 = ctx->r2 & 0X8000;
            goto L_8080354C;
    }
    // 0x80803408: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x8080340C: beql        $t7, $zero, L_80803550
    if (ctx->r15 == 0) {
        // 0x80803410: sw          $v0, 0x38($t0)
        MEM_W(0X38, ctx->r8) = ctx->r2;
            goto L_80803550;
    }
    goto skip_13;
    // 0x80803410: sw          $v0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r2;
    skip_13:
    // 0x80803414: lw          $t8, 0x38($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X38);
    // 0x80803418: addiu       $a1, $v1, -0x15
    ctx->r5 = ADD32(ctx->r3, -0X15);
    // 0x8080341C: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80803420: bnel        $t9, $zero, L_80803550
    if (ctx->r25 != 0) {
        // 0x80803424: sw          $v0, 0x38($t0)
        MEM_W(0X38, ctx->r8) = ctx->r2;
            goto L_80803550;
    }
    goto skip_14;
    // 0x80803424: sw          $v0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r2;
    skip_14:
    // 0x80803428: jal         0x8080020C
    // 0x8080342C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8080020C_chjiggygamenew(rdram, ctx);
        goto after_25;
    // 0x8080342C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_25:
    // 0x80803430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803434: bne         $v0, $at, L_80803460
    if (ctx->r2 != ctx->r1) {
        // 0x80803438: addiu       $t1, $zero, 0xE
        ctx->r9 = ADD32(0, 0XE);
            goto L_80803460;
    }
    // 0x80803438: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x8080343C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80803440: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80803444: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80803448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080344C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80803450: jal         0x80102424
    // 0x80803454: sw          $t2, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r10;
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x80803454: sw          $t2, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r10;
    after_26:
    // 0x80803458: b           L_80803498
    // 0x8080345C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
        goto L_80803498;
    // 0x8080345C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80803460:
    // 0x80803460: bne         $v0, $zero, L_80803490
    if (ctx->r2 != 0) {
        // 0x80803464: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_80803490;
    }
    // 0x80803464: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80803468: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8080346C: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80803470: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80803474: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80803478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080347C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803480: jal         0x80102424
    // 0x80803484: sw          $t4, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r12;
    func_80102424(rdram, ctx);
        goto after_27;
    // 0x80803484: sw          $t4, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r12;
    after_27:
    // 0x80803488: b           L_80803498
    // 0x8080348C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
        goto L_80803498;
    // 0x8080348C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80803490:
    // 0x80803490: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80803494: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80803498:
    // 0x80803498: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080349C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x808034A0: addiu       $a1, $a1, -0x39C4
    ctx->r5 = ADD32(ctx->r5, -0X39C4);
    // 0x808034A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808034A8: jal         0x800C9E20
    // 0x808034AC: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    func_800C9E20(rdram, ctx);
        goto after_28;
    // 0x808034AC: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    after_28:
    // 0x808034B0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808034B4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808034B8: b           L_8080354C
    // 0x808034BC: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
        goto L_8080354C;
    // 0x808034BC: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
L_808034C0:
    // 0x808034C0: jal         0x80101DDC
    // 0x808034C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_29;
    // 0x808034C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808034C8: beq         $v0, $zero, L_808034D8
    if (ctx->r2 == 0) {
        // 0x808034CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808034D8;
    }
    // 0x808034CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808034D0: jal         0x80102424
    // 0x808034D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_30;
    // 0x808034D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_30:
L_808034D8:
    // 0x808034D8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x808034DC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808034E0: b           L_8080354C
    // 0x808034E4: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
        goto L_8080354C;
    // 0x808034E4: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
L_808034E8:
    // 0x808034E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808034EC: jal         0x80102424
    // 0x808034F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_31;
    // 0x808034F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x808034F4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x808034F8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808034FC: b           L_8080354C
    // 0x80803500: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
        goto L_8080354C;
    // 0x80803500: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
L_80803504:
    // 0x80803504: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(772, 0X3E98) << 16);
    // 0x80803508: addiu       $a2, $a2, 0x3E98
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(772, 0X3E98));
    // 0x8080350C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803514: jal         0x80089D20
    // 0x80803518: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_32;
    // 0x80803518: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_32:
    // 0x8080351C: jal         0x80101DDC
    // 0x80803520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_33;
    // 0x80803520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80803524: beq         $v0, $zero, L_80803534
    if (ctx->r2 == 0) {
        // 0x80803528: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803534;
    }
    // 0x80803528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080352C: jal         0x80102424
    // 0x80803530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_34;
    // 0x80803530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
L_80803534:
    // 0x80803534: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80803538: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8080353C: b           L_8080354C
    // 0x80803540: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
        goto L_8080354C;
    // 0x80803540: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
L_80803544:
    // 0x80803544: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80803548: lhu         $v0, 0x0($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X0);
L_8080354C:
    // 0x8080354C: sw          $v0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r2;
L_80803550:
    // 0x80803550: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803554:
    // 0x80803554: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803558: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080355C: jr          $ra
    // 0x80803560: nop

    return;
    // 0x80803560: nop

;}
RECOMP_FUNC void _ncpoddialog_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089610: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x80089610);
    return;
    // 0x80089614: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_8080075C_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800760: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1272, 0X9F0) << 16);
    // 0x80800764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800768: addiu       $t6, $t6, 0x9F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1272, 0X9F0));
    // 0x8080076C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80800770: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    // 0x80800774: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1272, 0X9FC) << 16);
    // 0x80800778: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x8080077C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80800780: addiu       $a2, $a2, 0x9FC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1272, 0X9FC));
    // 0x80800784: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800788: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x8080078C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80800790: jal         0x80089D28
    // 0x80800794: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800794: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    after_0:
    // 0x80800798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080079C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007A0: jr          $ra
    // 0x808007A4: nop

    return;
    // 0x808007A4: nop

;}
RECOMP_FUNC void bsbansnooze_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006C0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(49, 0XA88) << 16);
    // 0x808006C4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006C8: jr          $ra
    // 0x808006CC: lw          $v0, 0xA88($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XA88));
    return;
    // 0x808006CC: lw          $v0, 0xA88($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XA88));
;}
RECOMP_FUNC void func_80800A1C_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800A20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A2C: jal         0x80100094
    // 0x80800A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A34: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800A38: jal         0x8010CD28
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_1;
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A40: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800A44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A48: jal         0x800136E4
    // 0x80800A4C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80800A4C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_2:
    // 0x80800A50: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800A54: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800A58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A5C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800A60: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800A64: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800A68: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80800A6C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A74: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800A78: jal         0x80089F90
    // 0x80800A7C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800A7C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_3:
    // 0x80800A80: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800A84: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A8C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800A90: jal         0x80102BF8
    // 0x80800A94: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    func_80102BF8(rdram, ctx);
        goto after_4;
    // 0x80800A94: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_4:
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A9C: jal         0x8010B990
    // 0x80800AA0: addiu       $a1, $zero, 0x325
    ctx->r5 = ADD32(0, 0X325);
    func_8010B990(rdram, ctx);
        goto after_5;
    // 0x80800AA0: addiu       $a1, $zero, 0x325
    ctx->r5 = ADD32(0, 0X325);
    after_5:
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA8: addiu       $a1, $zero, 0x4004
    ctx->r5 = ADD32(0, 0X4004);
    // 0x80800AAC: jal         0x8010B990
    // 0x80800AB0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8010B990(rdram, ctx);
        goto after_6;
    // 0x80800AB0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_6:
    // 0x80800AB4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800ABC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800AC0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80800AC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800AC8: jr          $ra
    // 0x80800ACC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800ACC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80801188_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801188: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080118C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801190: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801194: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801198: jal         0x80800AEC
    // 0x8080119C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_80800AEC_bssub(rdram, ctx);
        goto after_0;
    // 0x8080119C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808011A0: jal         0x8080102C
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080102C_bssub(rdram, ctx);
        goto after_1;
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808011A8: jal         0x80800634
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800634_bssub(rdram, ctx);
        goto after_2;
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808011B0: jal         0x80800768
    // 0x808011B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800768_bssub(rdram, ctx);
        goto after_3;
    // 0x808011B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808011B8: jal         0x80800254
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800254_bssub(rdram, ctx);
        goto after_4;
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808011C0: jal         0x80800834
    // 0x808011C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800834_bssub(rdram, ctx);
        goto after_5;
    // 0x808011C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808011C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808011CC: lwc1        $f6, 0x16C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808011D0: addiu       $t6, $zero, 0x131
    ctx->r14 = ADD32(0, 0X131);
    // 0x808011D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011D8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808011DC: nop

    // 0x808011E0: bc1f        L_808011EC
    if (!c1cs) {
        // 0x808011E4: nop
    
            goto L_808011EC;
    }
    // 0x808011E4: nop

    // 0x808011E8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808011EC:
    // 0x808011EC: jal         0x8009E5C8
    // 0x808011F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808011F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808011F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808011FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801200: jr          $ra
    // 0x80801204: nop

    return;
    // 0x80801204: nop

;}
RECOMP_FUNC void func_80803794_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803794: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80803798: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080379C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808037A0: jal         0x800D8FF8
    // 0x808037A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808037A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808037A8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808037AC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808037B0: beql        $a0, $zero, L_808037DC
    if (ctx->r4 == 0) {
        // 0x808037B4: sw          $zero, 0x40($sp)
        MEM_W(0X40, ctx->r29) = 0;
            goto L_808037DC;
    }
    goto skip_0;
    // 0x808037B4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    skip_0:
    // 0x808037B8: jal         0x80106790
    // 0x808037BC: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808037BC: nop

    after_1:
    // 0x808037C0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808037C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808037C8: jal         0x80100094
    // 0x808037CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808037CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808037D0: b           L_808037E0
    // 0x808037D4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
        goto L_808037E0;
    // 0x808037D4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808037D8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_808037DC:
    // 0x808037DC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_808037E0:
    // 0x808037E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037E4: jal         0x80100094
    // 0x808037E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808037E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808037EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808037F0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808037F4: jal         0x800897D8
    // 0x808037F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x808037F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808037FC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80803800: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80803804: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80803808: sltiu       $at, $t8, 0x19
    ctx->r1 = ctx->r24 < 0X19 ? 1 : 0;
    // 0x8080380C: beq         $at, $zero, L_80803F74
    if (ctx->r1 == 0) {
        // 0x80803810: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80803F74;
    }
    // 0x80803810: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80803814: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X45A0) << 16);
    // 0x80803818: addu        $at, $at, $t8
    gpr jr_addend_80803820 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080381C: lw          $t8, 0x45A0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X45A0));
    // 0x80803820: jr          $t8
    // 0x80803824: nop

    switch (jr_addend_80803820 >> 2) {
        case 0: goto L_80803A10; break;
        case 1: goto L_80803F74; break;
        case 2: goto L_80803F74; break;
        case 3: goto L_80803BF0; break;
        case 4: goto L_80803C10; break;
        case 5: goto L_80803C9C; break;
        case 6: goto L_80803CF4; break;
        case 7: goto L_80803D34; break;
        case 8: goto L_80803D98; break;
        case 9: goto L_80803DF0; break;
        case 10: goto L_80803E38; break;
        case 11: goto L_80803E6C; break;
        case 12: goto L_80803E94; break;
        case 13: goto L_80803ECC; break;
        case 14: goto L_80803F74; break;
        case 15: goto L_80803F74; break;
        case 16: goto L_80803EE4; break;
        case 17: goto L_80803F74; break;
        case 18: goto L_80803944; break;
        case 19: goto L_80803978; break;
        case 20: goto L_808039AC; break;
        case 21: goto L_808039CC; break;
        case 22: goto L_80803828; break;
        case 23: goto L_80803F74; break;
        case 24: goto L_80803910; break;
        default: switch_error(__func__, 0x80803820, 0x808045A0);
    }
    // 0x80803824: nop

L_80803828:
    // 0x80803828: jal         0x800DA298
    // 0x8080382C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x8080382C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80803830: beq         $v0, $zero, L_80803858
    if (ctx->r2 == 0) {
        // 0x80803834: nop
    
            goto L_80803858;
    }
    // 0x80803834: nop

    // 0x80803838: jal         0x80090270
    // 0x8080383C: nop

    func_80090270(rdram, ctx);
        goto after_6;
    // 0x8080383C: nop

    after_6:
    // 0x80803840: bne         $v0, $zero, L_80803F74
    if (ctx->r2 != 0) {
        // 0x80803844: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803848: jal         0x80802CE8
    // 0x8080384C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_80802CE8_chhandcart(rdram, ctx);
        goto after_7;
    // 0x8080384C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_7:
    // 0x80803850: b           L_80803F74
    // 0x80803854: nop

        goto L_80803F74;
    // 0x80803854: nop

L_80803858:
    // 0x80803858: jal         0x800DA298
    // 0x8080385C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x8080385C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80803860: bne         $v0, $zero, L_80803F74
    if (ctx->r2 != 0) {
        // 0x80803864: nop
    
            goto L_80803F74;
    }
    // 0x80803864: nop

    // 0x80803868: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080386C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803870: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80803874: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80803878: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080387C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80803880: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80803884: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80803888: jal         0x8008A1C8
    // 0x8080388C: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    _subaddiedialog_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x8080388C: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    after_9:
    // 0x80803890: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803894: nop
    
            goto L_80803F74;
    }
    // 0x80803894: nop

    // 0x80803898: jal         0x80090178
    // 0x8080389C: addiu       $a0, $zero, 0x4001
    ctx->r4 = ADD32(0, 0X4001);
    func_80090178(rdram, ctx);
        goto after_10;
    // 0x8080389C: addiu       $a0, $zero, 0x4001
    ctx->r4 = ADD32(0, 0X4001);
    after_10:
    // 0x808038A0: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x808038A4: addiu       $a0, $zero, 0x42A
        ctx->r4 = ADD32(0, 0X42A);
            goto L_80803F74;
    }
    // 0x808038A4: addiu       $a0, $zero, 0x42A
    ctx->r4 = ADD32(0, 0X42A);
    // 0x808038A8: jal         0x800DA9E4
    // 0x808038AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_11;
    // 0x808038AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808038B0: bne         $v0, $zero, L_808038CC
    if (ctx->r2 != 0) {
        // 0x808038B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808038CC;
    }
    // 0x808038B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038B8: addiu       $a1, $zero, 0xF7E
    ctx->r5 = ADD32(0, 0XF7E);
    // 0x808038BC: jal         0x808023B4
    // 0x808038C0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_12;
    // 0x808038C0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_12:
    // 0x808038C4: b           L_80803F74
    // 0x808038C8: nop

        goto L_80803F74;
    // 0x808038C8: nop

L_808038CC:
    // 0x808038CC: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808038D0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x808038D4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808038D8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808038DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808038E0: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x808038E4: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x808038E8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808038EC: jal         0x8008A1E0
    // 0x808038F0: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x808038F0: nop

    after_13:
    // 0x808038F4: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x808038F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x808038F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038FC: addiu       $a1, $zero, 0xFA7
    ctx->r5 = ADD32(0, 0XFA7);
    // 0x80803900: jal         0x808023B4
    // 0x80803904: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_14;
    // 0x80803904: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_14:
    // 0x80803908: b           L_80803F74
    // 0x8080390C: nop

        goto L_80803F74;
    // 0x8080390C: nop

L_80803910:
    // 0x80803910: jal         0x80802BC8
    // 0x80803914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BC8_chhandcart(rdram, ctx);
        goto after_15;
    // 0x80803914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80803918: jal         0x80105A5C
    // 0x8080391C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_16;
    // 0x8080391C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80803920: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803924: nop
    
            goto L_80803F74;
    }
    // 0x80803924: nop

    // 0x80803928: jal         0x800DA544
    // 0x8080392C: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    func_800DA544(rdram, ctx);
        goto after_17;
    // 0x8080392C: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_17:
    // 0x80803930: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    // 0x80803934: jal         0x800887D8
    // 0x80803938: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_18;
    // 0x80803938: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_18:
    // 0x8080393C: b           L_80803F74
    // 0x80803940: nop

        goto L_80803F74;
    // 0x80803940: nop

L_80803944:
    // 0x80803944: jal         0x80802BC8
    // 0x80803948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BC8_chhandcart(rdram, ctx);
        goto after_19;
    // 0x80803948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080394C: jal         0x80105A5C
    // 0x80803950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_20;
    // 0x80803950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80803954: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803958: nop
    
            goto L_80803F74;
    }
    // 0x80803958: nop

    // 0x8080395C: jal         0x80105634
    // 0x80803960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105634(rdram, ctx);
        goto after_21;
    // 0x80803960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80803964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803968: jal         0x808031D0
    // 0x8080396C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_22;
    // 0x8080396C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_22:
    // 0x80803970: b           L_80803F74
    // 0x80803974: nop

        goto L_80803F74;
    // 0x80803974: nop

L_80803978:
    // 0x80803978: jal         0x80803448
    // 0x8080397C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803448_chhandcart(rdram, ctx);
        goto after_23;
    // 0x8080397C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80803980: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803984: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803988: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8080398C: jal         0x80101E14
    // 0x80803990: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_24;
    // 0x80803990: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_24:
    // 0x80803994: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803998: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080399C: jal         0x808031D0
    // 0x808039A0: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_25;
    // 0x808039A0: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_25:
    // 0x808039A4: b           L_80803F74
    // 0x808039A8: nop

        goto L_80803F74;
    // 0x808039A8: nop

L_808039AC:
    // 0x808039AC: jal         0x80101DDC
    // 0x808039B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_26;
    // 0x808039B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808039B4: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x808039B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x808039B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039BC: jal         0x808031D0
    // 0x808039C0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_27;
    // 0x808039C0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_27:
    // 0x808039C4: b           L_80803F74
    // 0x808039C8: nop

        goto L_80803F74;
    // 0x808039C8: nop

L_808039CC:
    // 0x808039CC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808039D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808039D4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808039D8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808039DC: nop

    // 0x808039E0: bc1f        L_808039F4
    if (!c1cs) {
        // 0x808039E4: nop
    
            goto L_808039F4;
    }
    // 0x808039E4: nop

    // 0x808039E8: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x808039EC: b           L_80803F74
    // 0x808039F0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80803F74;
    // 0x808039F0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808039F4:
    // 0x808039F4: jal         0x80088830
    // 0x808039F8: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_28;
    // 0x808039F8: nop

    after_28:
    // 0x808039FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803A00: jal         0x808031D0
    // 0x80803A04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_29;
    // 0x80803A04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_29:
    // 0x80803A08: b           L_80803F74
    // 0x80803A0C: nop

        goto L_80803F74;
    // 0x80803A0C: nop

L_80803A10:
    // 0x80803A10: jal         0x80803698
    // 0x80803A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803698_chhandcart(rdram, ctx);
        goto after_30;
    // 0x80803A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80803A18: jal         0x80803514
    // 0x80803A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803514_chhandcart(rdram, ctx);
        goto after_31;
    // 0x80803A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80803A20: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80803A24: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80803A28: bltz        $t5, L_80803F74
    if (SIGNED(ctx->r13) < 0) {
        // 0x80803A2C: nop
    
            goto L_80803F74;
    }
    // 0x80803A2C: nop

    // 0x80803A30: jal         0x80090178
    // 0x80803A34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_32;
    // 0x80803A34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_32:
    // 0x80803A38: beq         $v0, $zero, L_80803B34
    if (ctx->r2 == 0) {
        // 0x80803A3C: nop
    
            goto L_80803B34;
    }
    // 0x80803A3C: nop

    // 0x80803A40: jal         0x800DA298
    // 0x80803A44: addiu       $a0, $zero, 0x508
    ctx->r4 = ADD32(0, 0X508);
    func_800DA298(rdram, ctx);
        goto after_33;
    // 0x80803A44: addiu       $a0, $zero, 0x508
    ctx->r4 = ADD32(0, 0X508);
    after_33:
    // 0x80803A48: beql        $v0, $zero, L_80803AB0
    if (ctx->r2 == 0) {
        // 0x80803A4C: lwc1        $f10, 0x48($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80803AB0;
    }
    goto skip_1;
    // 0x80803A4C: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    skip_1:
    // 0x80803A50: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803A54: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80803A58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80803A5C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80803A60: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803A64: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80803A68: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x80803A6C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80803A70: jal         0x8008A1E0
    // 0x80803A74: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_34;
    // 0x80803A74: nop

    after_34:
    // 0x80803A78: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803A7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803A80: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80803A84: addiu       $a1, $zero, 0xFAD
    ctx->r5 = ADD32(0, 0XFAD);
    // 0x80803A88: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x80803A8C: bgez        $t0, L_80803A9C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80803A90: nop
    
            goto L_80803A9C;
    }
    // 0x80803A90: nop

    // 0x80803A94: b           L_80803A9C
    // 0x80803A98: addiu       $a1, $zero, 0xFAE
    ctx->r5 = ADD32(0, 0XFAE);
        goto L_80803A9C;
    // 0x80803A98: addiu       $a1, $zero, 0xFAE
    ctx->r5 = ADD32(0, 0XFAE);
L_80803A9C:
    // 0x80803A9C: jal         0x808023B4
    // 0x80803AA0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_35;
    // 0x80803AA0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_35:
    // 0x80803AA4: b           L_80803F74
    // 0x80803AA8: nop

        goto L_80803F74;
    // 0x80803AA8: nop

    // 0x80803AAC: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
L_80803AB0:
    // 0x80803AB0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80803AB4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80803AB8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80803ABC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803AC0: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80803AC4: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x80803AC8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80803ACC: jal         0x8008A1C8
    // 0x80803AD0: nop

    _subaddiedialog_entrypoint_3(rdram, ctx);
        goto after_36;
    // 0x80803AD0: nop

    after_36:
    // 0x80803AD4: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803AD8: nop
    
            goto L_80803F74;
    }
    // 0x80803AD8: nop

    // 0x80803ADC: jal         0x800DA544
    // 0x80803AE0: addiu       $a0, $zero, 0x508
    ctx->r4 = ADD32(0, 0X508);
    func_800DA544(rdram, ctx);
        goto after_37;
    // 0x80803AE0: addiu       $a0, $zero, 0x508
    ctx->r4 = ADD32(0, 0X508);
    after_37:
    // 0x80803AE4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80803AE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803AEC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80803AF0: jal         0x80800858
    // 0x80803AF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800858_chhandcart(rdram, ctx);
        goto after_38;
    // 0x80803AF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_38:
    // 0x80803AF8: jal         0x800DA298
    // 0x80803AFC: addiu       $a0, $zero, 0x57A
    ctx->r4 = ADD32(0, 0X57A);
    func_800DA298(rdram, ctx);
        goto after_39;
    // 0x80803AFC: addiu       $a0, $zero, 0x57A
    ctx->r4 = ADD32(0, 0X57A);
    after_39:
    // 0x80803B00: beq         $v0, $zero, L_80803B20
    if (ctx->r2 == 0) {
        // 0x80803B04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803B20;
    }
    // 0x80803B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803B0C: addiu       $a1, $zero, 0xF80
    ctx->r5 = ADD32(0, 0XF80);
    // 0x80803B10: jal         0x808023B4
    // 0x80803B14: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_40;
    // 0x80803B14: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_40:
    // 0x80803B18: b           L_80803F74
    // 0x80803B1C: nop

        goto L_80803F74;
    // 0x80803B1C: nop

L_80803B20:
    // 0x80803B20: addiu       $a1, $zero, 0xFB7
    ctx->r5 = ADD32(0, 0XFB7);
    // 0x80803B24: jal         0x808023B4
    // 0x80803B28: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_41;
    // 0x80803B28: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_41:
    // 0x80803B2C: b           L_80803F74
    // 0x80803B30: nop

        goto L_80803F74;
    // 0x80803B30: nop

L_80803B34:
    // 0x80803B34: jal         0x800DA298
    // 0x80803B38: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800DA298(rdram, ctx);
        goto after_42;
    // 0x80803B38: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_42:
    // 0x80803B3C: beql        $v0, $zero, L_80803BA4
    if (ctx->r2 == 0) {
        // 0x80803B40: lwc1        $f6, 0x48($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80803BA4;
    }
    goto skip_2;
    // 0x80803B40: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    skip_2:
    // 0x80803B44: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803B48: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80803B4C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80803B50: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80803B54: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803B58: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80803B5C: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x80803B60: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80803B64: jal         0x8008A1E0
    // 0x80803B68: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_43;
    // 0x80803B68: nop

    after_43:
    // 0x80803B6C: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803B70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803B74: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80803B78: addiu       $a1, $zero, 0xFB1
    ctx->r5 = ADD32(0, 0XFB1);
    // 0x80803B7C: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x80803B80: bgez        $t7, L_80803B90
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80803B84: nop
    
            goto L_80803B90;
    }
    // 0x80803B84: nop

    // 0x80803B88: b           L_80803B90
    // 0x80803B8C: addiu       $a1, $zero, 0xFB2
    ctx->r5 = ADD32(0, 0XFB2);
        goto L_80803B90;
    // 0x80803B8C: addiu       $a1, $zero, 0xFB2
    ctx->r5 = ADD32(0, 0XFB2);
L_80803B90:
    // 0x80803B90: jal         0x808023B4
    // 0x80803B94: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_44;
    // 0x80803B94: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_44:
    // 0x80803B98: b           L_80803F74
    // 0x80803B9C: nop

        goto L_80803F74;
    // 0x80803B9C: nop

    // 0x80803BA0: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
L_80803BA4:
    // 0x80803BA4: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80803BA8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80803BAC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80803BB0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803BB4: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80803BB8: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x80803BBC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80803BC0: jal         0x8008A1C8
    // 0x80803BC4: nop

    _subaddiedialog_entrypoint_3(rdram, ctx);
        goto after_45;
    // 0x80803BC4: nop

    after_45:
    // 0x80803BC8: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803BCC: nop
    
            goto L_80803F74;
    }
    // 0x80803BCC: nop

    // 0x80803BD0: jal         0x800DA544
    // 0x80803BD4: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800DA544(rdram, ctx);
        goto after_46;
    // 0x80803BD4: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_46:
    // 0x80803BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BDC: addiu       $a1, $zero, 0xFB0
    ctx->r5 = ADD32(0, 0XFB0);
    // 0x80803BE0: jal         0x808023B4
    // 0x80803BE4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_47;
    // 0x80803BE4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_47:
    // 0x80803BE8: b           L_80803F74
    // 0x80803BEC: nop

        goto L_80803F74;
    // 0x80803BEC: nop

L_80803BF0:
    // 0x80803BF0: jal         0x80803514
    // 0x80803BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803514_chhandcart(rdram, ctx);
        goto after_48;
    // 0x80803BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80803BF8: jal         0x80803698
    // 0x80803BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803698_chhandcart(rdram, ctx);
        goto after_49;
    // 0x80803BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80803C00: jal         0x80802BC8
    // 0x80803C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BC8_chhandcart(rdram, ctx);
        goto after_50;
    // 0x80803C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x80803C08: b           L_80803F74
    // 0x80803C0C: nop

        goto L_80803F74;
    // 0x80803C0C: nop

L_80803C10:
    // 0x80803C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C14: jal         0x80803218
    // 0x80803C18: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80803218_chhandcart(rdram, ctx);
        goto after_51;
    // 0x80803C18: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_51:
    // 0x80803C1C: jal         0x80802BC8
    // 0x80803C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BC8_chhandcart(rdram, ctx);
        goto after_52;
    // 0x80803C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80803C24: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80803C28: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80803C2C: jal         0x80105998
    // 0x80803C30: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80105998(rdram, ctx);
        goto after_53;
    // 0x80803C30: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_53:
    // 0x80803C34: beq         $v0, $zero, L_80803C70
    if (ctx->r2 == 0) {
        // 0x80803C38: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_80803C70;
    }
    // 0x80803C38: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80803C3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80803C40: sb          $t0, 0x8F8($t1)
    MEM_B(0X8F8, ctx->r9) = ctx->r8;
    // 0x80803C44: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80803C48: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80803C4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803C50: lw          $t3, 0x64($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X64);
    // 0x80803C54: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80803C58: bgez        $t5, L_80803C68
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80803C5C: nop
    
            goto L_80803C68;
    }
    // 0x80803C5C: nop

    // 0x80803C60: b           L_80803C68
    // 0x80803C64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80803C68;
    // 0x80803C64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80803C68:
    // 0x80803C68: jal         0x80800A24
    // 0x80803C6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800A24_chhandcart(rdram, ctx);
        goto after_54;
    // 0x80803C6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_54:
L_80803C70:
    // 0x80803C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C74: jal         0x808036D0
    // 0x80803C78: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_808036D0_chhandcart(rdram, ctx);
        goto after_55;
    // 0x80803C78: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_55:
    // 0x80803C7C: jal         0x80105A5C
    // 0x80803C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_56;
    // 0x80803C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x80803C84: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803C88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C8C: jal         0x808031D0
    // 0x80803C90: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_57;
    // 0x80803C90: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_57:
    // 0x80803C94: b           L_80803F74
    // 0x80803C98: nop

        goto L_80803F74;
    // 0x80803C98: nop

L_80803C9C:
    // 0x80803C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CA0: jal         0x80803218
    // 0x80803CA4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80803218_chhandcart(rdram, ctx);
        goto after_58;
    // 0x80803CA4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_58:
    // 0x80803CA8: jal         0x80802BC8
    // 0x80803CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BC8_chhandcart(rdram, ctx);
        goto after_59;
    // 0x80803CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x80803CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CB4: jal         0x80803730
    // 0x80803CB8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80803730_chhandcart(rdram, ctx);
        goto after_60;
    // 0x80803CB8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_60:
    // 0x80803CBC: jal         0x80090248
    // 0x80803CC0: nop

    func_80090248(rdram, ctx);
        goto after_61;
    // 0x80803CC0: nop

    after_61:
    // 0x80803CC4: beq         $v0, $zero, L_80803CD4
    if (ctx->r2 == 0) {
        // 0x80803CC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803CD4;
    }
    // 0x80803CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CCC: jal         0x808031D0
    // 0x80803CD0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_62;
    // 0x80803CD0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_62:
L_80803CD4:
    // 0x80803CD4: jal         0x80105A5C
    // 0x80803CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_63;
    // 0x80803CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x80803CDC: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803CE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CE4: jal         0x808031D0
    // 0x80803CE8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_64;
    // 0x80803CE8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_64:
    // 0x80803CEC: b           L_80803F74
    // 0x80803CF0: nop

        goto L_80803F74;
    // 0x80803CF0: nop

L_80803CF4:
    // 0x80803CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CF8: jal         0x80803218
    // 0x80803CFC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80803218_chhandcart(rdram, ctx);
        goto after_65;
    // 0x80803CFC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_65:
    // 0x80803D00: jal         0x80802BC8
    // 0x80803D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BC8_chhandcart(rdram, ctx);
        goto after_66;
    // 0x80803D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x80803D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D0C: jal         0x80803730
    // 0x80803D10: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80803730_chhandcart(rdram, ctx);
        goto after_67;
    // 0x80803D10: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_67:
    // 0x80803D14: jal         0x80105A5C
    // 0x80803D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_68;
    // 0x80803D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x80803D1C: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803D20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D24: jal         0x808031D0
    // 0x80803D28: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_69;
    // 0x80803D28: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_69:
    // 0x80803D2C: b           L_80803F74
    // 0x80803D30: nop

        goto L_80803F74;
    // 0x80803D30: nop

L_80803D34:
    // 0x80803D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D38: jal         0x808036D0
    // 0x80803D3C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_808036D0_chhandcart(rdram, ctx);
        goto after_70;
    // 0x80803D3C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_70:
    // 0x80803D40: jal         0x80105A5C
    // 0x80803D44: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80105A5C(rdram, ctx);
        goto after_71;
    // 0x80803D44: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_71:
    // 0x80803D48: beq         $v0, $zero, L_80803D64
    if (ctx->r2 == 0) {
        // 0x80803D4C: nop
    
            goto L_80803D64;
    }
    // 0x80803D4C: nop

    // 0x80803D50: jal         0x80800EA0
    // 0x80803D54: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800EA0_chhandcart(rdram, ctx);
        goto after_72;
    // 0x80803D54: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_72:
    // 0x80803D58: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80803D5C: jal         0x80800EE4
    // 0x80803D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800EE4_chhandcart(rdram, ctx);
        goto after_73;
    // 0x80803D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_73:
L_80803D64:
    // 0x80803D64: jal         0x80803448
    // 0x80803D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803448_chhandcart(rdram, ctx);
        goto after_74;
    // 0x80803D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_74:
    // 0x80803D6C: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803D70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D74: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80803D78: jal         0x80101E14
    // 0x80803D7C: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_75;
    // 0x80803D7C: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_75:
    // 0x80803D80: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803D84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D88: jal         0x808031D0
    // 0x80803D8C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_76;
    // 0x80803D8C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_76:
    // 0x80803D90: b           L_80803F74
    // 0x80803D94: nop

        goto L_80803F74;
    // 0x80803D94: nop

L_80803D98:
    // 0x80803D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D9C: jal         0x808036D0
    // 0x80803DA0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_808036D0_chhandcart(rdram, ctx);
        goto after_77;
    // 0x80803DA0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_77:
    // 0x80803DA4: jal         0x80803698
    // 0x80803DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803698_chhandcart(rdram, ctx);
        goto after_78;
    // 0x80803DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x80803DAC: jal         0x80105A5C
    // 0x80803DB0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80105A5C(rdram, ctx);
        goto after_79;
    // 0x80803DB0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_79:
    // 0x80803DB4: beq         $v0, $zero, L_80803DD0
    if (ctx->r2 == 0) {
        // 0x80803DB8: nop
    
            goto L_80803DD0;
    }
    // 0x80803DB8: nop

    // 0x80803DBC: jal         0x80800EA0
    // 0x80803DC0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800EA0_chhandcart(rdram, ctx);
        goto after_80;
    // 0x80803DC0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_80:
    // 0x80803DC4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80803DC8: jal         0x80800EE4
    // 0x80803DCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800EE4_chhandcart(rdram, ctx);
        goto after_81;
    // 0x80803DCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_81:
L_80803DD0:
    // 0x80803DD0: jal         0x80101DDC
    // 0x80803DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_82;
    // 0x80803DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_82:
    // 0x80803DD8: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803DDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803DE0: jal         0x808031D0
    // 0x80803DE4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_83;
    // 0x80803DE4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_83:
    // 0x80803DE8: b           L_80803F74
    // 0x80803DEC: nop

        goto L_80803F74;
    // 0x80803DEC: nop

L_80803DF0:
    // 0x80803DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803DF4: jal         0x808036D0
    // 0x80803DF8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_808036D0_chhandcart(rdram, ctx);
        goto after_84;
    // 0x80803DF8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_84:
    // 0x80803DFC: jal         0x80803698
    // 0x80803E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803698_chhandcart(rdram, ctx);
        goto after_85;
    // 0x80803E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_85:
    // 0x80803E04: jal         0x80803514
    // 0x80803E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803514_chhandcart(rdram, ctx);
        goto after_86;
    // 0x80803E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_86:
    // 0x80803E0C: jal         0x80105A5C
    // 0x80803E10: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80105A5C(rdram, ctx);
        goto after_87;
    // 0x80803E10: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_87:
    // 0x80803E14: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803E18: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80803F74;
    }
    // 0x80803E18: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80803E1C: jal         0x80800EE4
    // 0x80803E20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800EE4_chhandcart(rdram, ctx);
        goto after_88;
    // 0x80803E20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_88:
    // 0x80803E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803E28: jal         0x808031D0
    // 0x80803E2C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_89;
    // 0x80803E2C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_89:
    // 0x80803E30: b           L_80803F74
    // 0x80803E34: nop

        goto L_80803F74;
    // 0x80803E34: nop

L_80803E38:
    // 0x80803E38: jal         0x80803448
    // 0x80803E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803448_chhandcart(rdram, ctx);
        goto after_90;
    // 0x80803E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_90:
    // 0x80803E40: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803E44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803E48: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80803E4C: jal         0x80101E14
    // 0x80803E50: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_91;
    // 0x80803E50: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_91:
    // 0x80803E54: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803E58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803E5C: jal         0x808031D0
    // 0x80803E60: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_92;
    // 0x80803E60: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_92:
    // 0x80803E64: b           L_80803F74
    // 0x80803E68: nop

        goto L_80803F74;
    // 0x80803E68: nop

L_80803E6C:
    // 0x80803E6C: jal         0x80803698
    // 0x80803E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803698_chhandcart(rdram, ctx);
        goto after_93;
    // 0x80803E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_93:
    // 0x80803E74: jal         0x80101DDC
    // 0x80803E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_94;
    // 0x80803E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_94:
    // 0x80803E7C: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803E80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F74;
    }
    // 0x80803E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803E84: jal         0x808031D0
    // 0x80803E88: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_95;
    // 0x80803E88: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_95:
    // 0x80803E8C: b           L_80803F74
    // 0x80803E90: nop

        goto L_80803F74;
    // 0x80803E90: nop

L_80803E94:
    // 0x80803E94: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803E98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80803E9C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80803EA0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80803EA4: nop

    // 0x80803EA8: bc1f        L_80803EBC
    if (!c1cs) {
        // 0x80803EAC: nop
    
            goto L_80803EBC;
    }
    // 0x80803EAC: nop

    // 0x80803EB0: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80803EB4: b           L_80803F74
    // 0x80803EB8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_80803F74;
    // 0x80803EB8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80803EBC:
    // 0x80803EBC: jal         0x80800214
    // 0x80803EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800214_chhandcart(rdram, ctx);
        goto after_96;
    // 0x80803EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_96:
    // 0x80803EC4: b           L_80803F74
    // 0x80803EC8: nop

        goto L_80803F74;
    // 0x80803EC8: nop

L_80803ECC:
    // 0x80803ECC: jal         0x80803514
    // 0x80803ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803514_chhandcart(rdram, ctx);
        goto after_97;
    // 0x80803ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_97:
    // 0x80803ED4: jal         0x80803698
    // 0x80803ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803698_chhandcart(rdram, ctx);
        goto after_98;
    // 0x80803ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_98:
    // 0x80803EDC: b           L_80803F74
    // 0x80803EE0: nop

        goto L_80803F74;
    // 0x80803EE0: nop

L_80803EE4:
    // 0x80803EE4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80803EE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803EEC: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803EF0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80803EF4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80803EF8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80803EFC: nop

    // 0x80803F00: bc1f        L_80803F1C
    if (!c1cs) {
        // 0x80803F04: nop
    
            goto L_80803F1C;
    }
    // 0x80803F04: nop

    // 0x80803F08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803F0C: nop

    // 0x80803F10: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80803F14: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80803F18: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
L_80803F1C:
    // 0x80803F1C: jal         0x80802BC8
    // 0x80803F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BC8_chhandcart(rdram, ctx);
        goto after_99;
    // 0x80803F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_99:
    // 0x80803F24: jal         0x80105A5C
    // 0x80803F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_100;
    // 0x80803F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_100:
    // 0x80803F2C: beq         $v0, $zero, L_80803F74
    if (ctx->r2 == 0) {
        // 0x80803F30: nop
    
            goto L_80803F74;
    }
    // 0x80803F30: nop

    // 0x80803F34: jal         0x80105634
    // 0x80803F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105634(rdram, ctx);
        goto after_101;
    // 0x80803F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_101:
    // 0x80803F3C: jal         0x80088238
    // 0x80803F40: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    _gclevel_entrypoint_3(rdram, ctx);
        goto after_102;
    // 0x80803F40: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_102:
    // 0x80803F44: beq         $v0, $zero, L_80803F5C
    if (ctx->r2 == 0) {
        // 0x80803F48: addiu       $a0, $zero, 0x136
        ctx->r4 = ADD32(0, 0X136);
            goto L_80803F5C;
    }
    // 0x80803F48: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    // 0x80803F4C: jal         0x800887D8
    // 0x80803F50: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_103;
    // 0x80803F50: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    after_103:
    // 0x80803F54: b           L_80803F74
    // 0x80803F58: nop

        goto L_80803F74;
    // 0x80803F58: nop

L_80803F5C:
    // 0x80803F5C: jal         0x80800AB0
    // 0x80803F60: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800AB0_chhandcart(rdram, ctx);
        goto after_104;
    // 0x80803F60: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_104:
    // 0x80803F64: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80803F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F6C: jal         0x800FFAB0
    // 0x80803F70: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    func_800FFAB0(rdram, ctx);
        goto after_105;
    // 0x80803F70: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    after_105:
L_80803F74:
    // 0x80803F74: jal         0x80802690
    // 0x80803F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802690_chhandcart(rdram, ctx);
        goto after_106;
    // 0x80803F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_106:
    // 0x80803F7C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80803F80: beql        $v0, $zero, L_80803FB4
    if (ctx->r2 == 0) {
        // 0x80803F84: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80803FB4;
    }
    goto skip_3;
    // 0x80803F84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80803F88: lbu         $a1, 0x8F5($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X8F5);
    // 0x80803F8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803F90: beq         $a1, $at, L_80803FA0
    if (ctx->r5 == ctx->r1) {
        // 0x80803F94: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80803FA0;
    }
    // 0x80803F94: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80803F98: bnel        $a1, $at, L_80803FB4
    if (ctx->r5 != ctx->r1) {
        // 0x80803F9C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80803FB4;
    }
    goto skip_4;
    // 0x80803F9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
L_80803FA0:
    // 0x80803FA0: jal         0x80800B00
    // 0x80803FA4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800B00_chhandcart(rdram, ctx);
        goto after_107;
    // 0x80803FA4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_107:
    // 0x80803FA8: jal         0x80800528
    // 0x80803FAC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800528_chhandcart(rdram, ctx);
        goto after_108;
    // 0x80803FAC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_108:
    // 0x80803FB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803FB4:
    // 0x80803FB4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80803FB8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80803FBC: jr          $ra
    // 0x80803FC0: nop

    return;
    // 0x80803FC0: nop

;}
RECOMP_FUNC void _chlaundry_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087298: syscall     543
    recomp_syscall_handler(rdram, ctx, 0x80087298);
    return;
    // 0x8008729C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801CCC_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CCC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801CD0: sh          $zero, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = 0;
    // 0x80801CD4: jr          $ra
    // 0x80801CD8: sh          $t6, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r14;
    return;
    // 0x80801CD8: sh          $t6, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_808007B0_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007B8: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808007BC: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x808007C0: bgezl       $t8, L_808007F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808007C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007F0;
    }
    goto skip_0;
    // 0x808007C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808007C8: jal         0x800F54E4
    // 0x808007CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808007CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808007D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007D4: jal         0x800F82D4
    // 0x808007D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x808007D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808007DC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808007E0: lbu         $t9, 0x65($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X65);
    // 0x808007E4: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x808007E8: sb          $t0, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r8;
    // 0x808007EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007F0:
    // 0x808007F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007F4: jr          $ra
    // 0x808007F8: nop

    return;
    // 0x808007F8: nop

;}
RECOMP_FUNC void chmusicmenu_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1824, 0X157C) << 16);
    // 0x808010B0: jr          $ra
    // 0x808010B4: addiu       $v0, $v0, 0x157C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1824, 0X157C));
    return;
    // 0x808010B4: addiu       $v0, $v0, 0x157C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1824, 0X157C));
;}
RECOMP_FUNC void func_800D2CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2CD0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D2CD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D2CD8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D2CDC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D2CE0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800D2CE4: jal         0x800BE58C
    // 0x800D2CE8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800BE58C(rdram, ctx);
        goto after_0;
    // 0x800D2CE8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800D2CEC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800D2CF0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800D2CF4: addiu       $s1, $s1, -0x4CA0
    ctx->r17 = ADD32(ctx->r17, -0X4CA0);
    // 0x800D2CF8: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x800D2CFC: jal         0x8001ACCC
    // 0x800D2D00: sll         $a0, $t6, 1
    ctx->r4 = S32(ctx->r14 << 1);
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x800D2D00: sll         $a0, $t6, 1
    ctx->r4 = S32(ctx->r14 << 1);
    after_1:
    // 0x800D2D04: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x800D2D08: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800D2D0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D2D10: blez        $t8, L_800D2D3C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800D2D14: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_800D2D3C;
    }
    // 0x800D2D14: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800D2D18: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_800D2D1C:
    // 0x800D2D1C: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x800D2D20: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D2D24: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800D2D28: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x800D2D2C: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x800D2D30: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800D2D34: bnel        $at, $zero, L_800D2D1C
    if (ctx->r1 != 0) {
        // 0x800D2D38: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_800D2D1C;
    }
    goto skip_0;
    // 0x800D2D38: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_0:
L_800D2D3C:
    // 0x800D2D3C: jal         0x800BE52C
    // 0x800D2D40: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800BE52C(rdram, ctx);
        goto after_2;
    // 0x800D2D40: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x800D2D44: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800D2D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D2D4C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800D2D50: slt         $at, $zero, $t3
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800D2D54: beq         $at, $zero, L_800D2E38
    if (ctx->r1 == 0) {
        // 0x800D2D58: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_800D2E38;
    }
    // 0x800D2D58: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800D2D5C: slt         $at, $zero, $a2
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r6) ? 1 : 0;
L_800D2D60:
    // 0x800D2D60: beq         $at, $zero, L_800D2E24
    if (ctx->r1 == 0) {
        // 0x800D2D64: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D2E24;
    }
    // 0x800D2D64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D2D68: slt         $at, $zero, $a0
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r4) ? 1 : 0;
L_800D2D6C:
    // 0x800D2D6C: beq         $at, $zero, L_800D2E14
    if (ctx->r1 == 0) {
        // 0x800D2D70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D2E14;
    }
    // 0x800D2D70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D2D74: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x800D2D78: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x800D2D7C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
L_800D2D80:
    // 0x800D2D80: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800D2D84: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800D2D88: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2D8C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800D2D90: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800D2D94: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800D2D98: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800D2D9C: mflo        $t5
    ctx->r13 = lo;
    // 0x800D2DA0: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800D2DA4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D2DA8: multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2DAC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800D2DB0: mflo        $t2
    ctx->r10 = lo;
    // 0x800D2DB4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800D2DB8: addu        $s0, $t0, $t3
    ctx->r16 = ADD32(ctx->r8, ctx->r11);
    // 0x800D2DBC: jal         0x800E9D68
    // 0x800D2DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9D68(rdram, ctx);
        goto after_3;
    // 0x800D2DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800D2DC4: beql        $v0, $zero, L_800D2DF4
    if (ctx->r2 == 0) {
        // 0x800D2DC8: lw          $v0, 0x54($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X54);
            goto L_800D2DF4;
    }
    goto skip_1;
    // 0x800D2DC8: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x800D2DCC: jal         0x800E9DC4
    // 0x800D2DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9DC4(rdram, ctx);
        goto after_4;
    // 0x800D2DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800D2DD4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800D2DD8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800D2DDC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800D2DE0: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x800D2DE4: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800D2DE8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800D2DEC: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x800D2DF0: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
L_800D2DF4:
    // 0x800D2DF4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800D2DF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D2DFC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D2E00: bnel        $at, $zero, L_800D2D80
    if (ctx->r1 != 0) {
        // 0x800D2E04: lw          $t4, 0x38($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X38);
            goto L_800D2D80;
    }
    goto skip_2;
    // 0x800D2E04: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    skip_2:
    // 0x800D2E08: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800D2E0C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800D2E10: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_800D2E14:
    // 0x800D2E14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D2E18: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800D2E1C: bnel        $at, $zero, L_800D2D6C
    if (ctx->r1 != 0) {
        // 0x800D2E20: slt         $at, $zero, $a0
        ctx->r1 = SIGNED(0) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800D2D6C;
    }
    goto skip_3;
    // 0x800D2E20: slt         $at, $zero, $a0
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r4) ? 1 : 0;
    skip_3:
L_800D2E24:
    // 0x800D2E24: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800D2E28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800D2E2C: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D2E30: bnel        $at, $zero, L_800D2D60
    if (ctx->r1 != 0) {
        // 0x800D2E34: slt         $at, $zero, $a2
        ctx->r1 = SIGNED(0) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800D2D60;
    }
    goto skip_4;
    // 0x800D2E34: slt         $at, $zero, $a2
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r6) ? 1 : 0;
    skip_4:
L_800D2E38:
    // 0x800D2E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2E3C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D2E40: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D2E44: jr          $ra
    // 0x800D2E48: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800D2E48: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80804218_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804218: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080421C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804220: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804228: jal         0x80106790
    // 0x8080422C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080422C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80804230: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80804234: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804238: andi        $t6, $a1, 0x1FF
    ctx->r14 = ctx->r5 & 0X1FF;
    // 0x8080423C: jal         0x80089AF8
    // 0x80804240: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80804240: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_1:
    // 0x80804244: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804248: bnel        $v0, $at, L_80804268
    if (ctx->r2 != ctx->r1) {
        // 0x8080424C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804268;
    }
    goto skip_0;
    // 0x8080424C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80804250: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80804254: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80804258: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x8080425C: jal         0x80089AB8
    // 0x80804260: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sukickball_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80804260: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x80804264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804268:
    // 0x80804268: jal         0x80102D78
    // 0x8080426C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_3;
    // 0x8080426C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x80804270: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80804274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804278: jal         0x80102CF4
    // 0x8080427C: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102CF4(rdram, ctx);
        goto after_4;
    // 0x8080427C: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_4:
    // 0x80804280: bne         $v0, $zero, L_8080429C
    if (ctx->r2 != 0) {
        // 0x80804284: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080429C;
    }
    // 0x80804284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080428C: jal         0x80102B2C
    // 0x80804290: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102B2C(rdram, ctx);
        goto after_5;
    // 0x80804290: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_5:
    // 0x80804294: b           L_808042F4
    // 0x80804298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808042F4;
    // 0x80804298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080429C:
    // 0x8080429C: jal         0x80102CF4
    // 0x808042A0: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102CF4(rdram, ctx);
        goto after_6;
    // 0x808042A0: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_6:
    // 0x808042A4: bne         $v0, $zero, L_808042C0
    if (ctx->r2 != 0) {
        // 0x808042A8: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_808042C0;
    }
    // 0x808042A8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808042AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808042B0: jal         0x80102B2C
    // 0x808042B4: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B2C(rdram, ctx);
        goto after_7;
    // 0x808042B4: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_7:
    // 0x808042B8: b           L_808042F4
    // 0x808042BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808042F4;
    // 0x808042BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808042C0:
    // 0x808042C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808042C4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x808042C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808042CC: jal         0x800DC178
    // 0x808042D0: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808042D0: nop

    after_8:
    // 0x808042D4: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x808042D8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x808042DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808042E0: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x808042E4: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x808042E8: jal         0x80800B4C
    // 0x808042EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_9;
    // 0x808042EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808042F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808042F4:
    // 0x808042F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808042F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808042FC: jr          $ra
    // 0x80804300: nop

    return;
    // 0x80804300: nop

;}
RECOMP_FUNC void bsstand_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D50: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800D54: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(368, 0XDB8) << 16);
    // 0x80800D58: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D5C: jr          $ra
    // 0x80800D60: lw          $v0, 0xDB8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(368, 0XDB8));
    return;
    // 0x80800D60: lw          $v0, 0xDB8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(368, 0XDB8));
    // 0x80800D64: nop

    // 0x80800D68: nop

    // 0x80800D6C: nop

;}
RECOMP_FUNC void func_8009BDAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BDAC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BDB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BDB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BDB8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8009BDBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009BDC0: jal         0x800917A8
    // 0x8009BDC4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bastatetimer_set(rdram, ctx);
        goto after_0;
    // 0x8009BDC4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8009BDC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009BDCC: jal         0x8009BD38
    // 0x8009BDD0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009BD38(rdram, ctx);
        goto after_1;
    // 0x8009BDD0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8009BDD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BDD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BDDC: jr          $ra
    // 0x8009BDE0: nop

    return;
    // 0x8009BDE0: nop

;}
RECOMP_FUNC void func_80800008_ncbapivot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x80112524
    // 0x80800014: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800014: nop

    after_0:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void func_801127C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801127C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801127CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801127D0: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801127D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801127D8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801127DC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801127E0: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801127E4: jal         0x800F1DCC
    // 0x801127E8: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x801127E8: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x801127EC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801127F0: jal         0x800F2100
    // 0x801127F4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x801127F4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x801127F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801127FC: lwc1        $f4, 0x6590($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6590);
    // 0x80112800: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80112804: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80112808: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8011280C: nop

    // 0x80112810: bc1fl       L_801128B0
    if (!c1cs) {
        // 0x80112814: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_801128B0;
    }
    goto skip_0;
    // 0x80112814: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80112818: jal         0x800D8FF8
    // 0x8011281C: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x8011281C: nop

    after_2:
    // 0x80112820: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80112824: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80112828: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8011282C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80112830: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80112834: lui         $a3, 0xC40C
    ctx->r7 = S32(0XC40C << 16);
    // 0x80112838: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8011283C: jal         0x800FF060
    // 0x80112840: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800FF060(rdram, ctx);
        goto after_3;
    // 0x80112840: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80112844: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80112848: jal         0x800F2100
    // 0x8011284C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x8011284C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80112850: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80112854: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80112858: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8011285C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80112860: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80112864: bc1fl       L_80112894
    if (!c1cs) {
        // 0x80112868: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_80112894;
    }
    goto skip_1;
    // 0x80112868: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x8011286C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80112870: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80112874: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80112878: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8011287C: nop

    // 0x80112880: bc1fl       L_80112894
    if (!c1cs) {
        // 0x80112884: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_80112894;
    }
    goto skip_2;
    // 0x80112884: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80112888: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8011288C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80112890: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_80112894:
    // 0x80112894: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80112898: jal         0x800136E4
    // 0x8011289C: add.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f2.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x8011289C: add.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f2.fl;
    after_5:
    // 0x801128A0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801128A4: b           L_801128C4
    // 0x801128A8: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
        goto L_801128C4;
    // 0x801128A8: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x801128AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_801128B0:
    // 0x801128B0: nop

    // 0x801128B4: swc1        $f0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
    // 0x801128B8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801128BC: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801128C0: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
L_801128C4:
    // 0x801128C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801128C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801128CC: jr          $ra
    // 0x801128D0: nop

    return;
    // 0x801128D0: nop

;}
RECOMP_FUNC void yaw_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C5A0: jr          $ra
    // 0x8009C5A4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x8009C5A4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void subaddierouteDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BAC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800BB0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800BB4: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80800BB8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800BBC: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80800BC0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80800BC4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800BC8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800BCC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80800BD0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80800BD4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80800BD8: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800BDC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800BE0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800BE4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800BE8: jal         0x80800564
    // 0x80800BEC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    func_80800564_subaddierouteDll(rdram, ctx);
        goto after_0;
    // 0x80800BEC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800BF0: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x80800BF4: lwc1        $f28, 0x70($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80800BF8: andi        $t6, $s3, 0x1000
    ctx->r14 = ctx->r19 & 0X1000;
    // 0x80800BFC: beql        $t6, $zero, L_80800C18
    if (ctx->r14 == 0) {
        // 0x80800C00: lwc1        $f28, 0x70($sp)
        ctx->f28.u32l = MEM_W(ctx->r29, 0X70);
            goto L_80800C18;
    }
    goto skip_0;
    // 0x80800C00: lwc1        $f28, 0x70($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X70);
    skip_0:
    // 0x80800C04: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x80800C08: jal         0x8080183C
    // 0x80800C0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8080183C_subaddierouteDll(rdram, ctx);
        goto after_1;
    // 0x80800C0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80800C10: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80800C14: lwc1        $f28, 0x70($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X70);
L_80800C18:
    // 0x80800C18: jal         0x800BE444
    // 0x80800C1C: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    func_800BE444(rdram, ctx);
        goto after_2;
    // 0x80800C1C: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_2:
    // 0x80800C20: andi        $t7, $s3, 0x800
    ctx->r15 = ctx->r19 & 0X800;
    // 0x80800C24: beq         $t7, $zero, L_80800C44
    if (ctx->r15 == 0) {
        // 0x80800C28: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80800C44;
    }
    // 0x80800C28: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800C2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C30: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800C34: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80800C38: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80800C3C: jal         0x80800D88
    // 0x80800C40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80800D88_subaddierouteDll(rdram, ctx);
        goto after_3;
    // 0x80800C40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
L_80800C44:
    // 0x80800C44: andi        $t8, $s3, 0x4000
    ctx->r24 = ctx->r19 & 0X4000;
    // 0x80800C48: beq         $t8, $zero, L_80800C58
    if (ctx->r24 == 0) {
        // 0x80800C4C: lwc1        $f0, 0x68($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
            goto L_80800C58;
    }
    // 0x80800C4C: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800C50: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x80800C54: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80800C58:
    // 0x80800C58: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800C5C: jal         0x800F1DCC
    // 0x80800C60: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    func_800F1DCC(rdram, ctx);
        goto after_4;
    // 0x80800C60: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    after_4:
    // 0x80800C64: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800C68: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800C6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C70: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800C74: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80800C78: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80800C7C: jal         0x8080160C
    // 0x80800C80: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_8080160C_subaddierouteDll(rdram, ctx);
        goto after_5;
    // 0x80800C80: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_5:
    // 0x80800C84: beql        $v0, $zero, L_80800C98
    if (ctx->r2 == 0) {
        // 0x80800C88: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80800C98;
    }
    goto skip_1;
    // 0x80800C88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
    // 0x80800C8C: b           L_80800D54
    // 0x80800C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D54;
    // 0x80800C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800C98:
    // 0x80800C98: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800C9C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80800CA0: c.lt.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl < ctx->f4.fl;
    // 0x80800CA4: lwc1        $f22, 0x68($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800CA8: bc1f        L_80800CC8
    if (!c1cs) {
        // 0x80800CAC: mov.s       $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
            goto L_80800CC8;
    }
    // 0x80800CAC: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80800CB0: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800CB4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800CB8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800CBC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800CC0: b           L_80800CD8
    // 0x80800CC4: nop

        goto L_80800CD8;
    // 0x80800CC4: nop

L_80800CC8:
    // 0x80800CC8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800CCC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800CD0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800CD4: nop

L_80800CD8:
    // 0x80800CD8: jal         0x800136E4
    // 0x80800CDC: add.s       $f12, $f22, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f22.fl + ctx->f24.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x80800CDC: add.s       $f12, $f22, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f22.fl + ctx->f24.fl;
    after_6:
    // 0x80800CE0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800CE4: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800CE8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800CEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800CF0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800CF4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80800CF8: jal         0x8080160C
    // 0x80800CFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_8080160C_subaddierouteDll(rdram, ctx);
        goto after_7;
    // 0x80800CFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_7:
    // 0x80800D00: beq         $v0, $zero, L_80800D10
    if (ctx->r2 == 0) {
        // 0x80800D04: nop
    
            goto L_80800D10;
    }
    // 0x80800D04: nop

    // 0x80800D08: b           L_80800D54
    // 0x80800D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D54;
    // 0x80800D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D10:
    // 0x80800D10: jal         0x800136E4
    // 0x80800D14: add.s       $f12, $f20, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f26.fl;
    func_800136E4(rdram, ctx);
        goto after_8;
    // 0x80800D14: add.s       $f12, $f20, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f26.fl;
    after_8:
    // 0x80800D18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800D1C: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800D20: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800D24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800D28: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800D2C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80800D30: jal         0x8080160C
    // 0x80800D34: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_8080160C_subaddierouteDll(rdram, ctx);
        goto after_9;
    // 0x80800D34: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_9:
    // 0x80800D38: beq         $v0, $zero, L_80800D48
    if (ctx->r2 == 0) {
        // 0x80800D3C: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80800D48;
    }
    // 0x80800D3C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80800D40: b           L_80800D54
    // 0x80800D44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D54;
    // 0x80800D44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D48:
    // 0x80800D48: bne         $s0, $zero, L_80800CD8
    if (ctx->r16 != 0) {
        // 0x80800D4C: nop
    
            goto L_80800CD8;
    }
    // 0x80800D4C: nop

    // 0x80800D50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D54:
    // 0x80800D54: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80800D58: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800D5C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800D60: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800D64: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800D68: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80800D6C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80800D70: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80800D74: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800D78: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80800D7C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80800D80: jr          $ra
    // 0x80800D84: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800D84: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _chanim_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859A0: syscall     184
    recomp_syscall_handler(rdram, ctx, 0x800859A0);
    return;
    // 0x800859A4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void gccubeDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808006A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808006AC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x808006B0: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x808006B4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808006B8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808006BC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x808006C0: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x808006C4: beq         $at, $zero, L_808006F4
    if (ctx->r1 == 0) {
        // 0x808006C8: nop
    
            goto L_808006F4;
    }
    // 0x808006C8: nop

L_808006CC:
    // 0x808006CC: jal         0x800E9C44
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9C44(rdram, ctx);
        goto after_0;
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808006D4: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x808006D8: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x808006DC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x808006E0: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x808006E4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x808006E8: sltu        $at, $s0, $t2
    ctx->r1 = ctx->r16 < ctx->r10 ? 1 : 0;
    // 0x808006EC: bne         $at, $zero, L_808006CC
    if (ctx->r1 != 0) {
        // 0x808006F0: nop
    
            goto L_808006CC;
    }
    // 0x808006F0: nop

L_808006F4:
    // 0x808006F4: jal         0x800E9C44
    // 0x808006F8: addiu       $a0, $s1, 0x34
    ctx->r4 = ADD32(ctx->r17, 0X34);
    func_800E9C44(rdram, ctx);
        goto after_1;
    // 0x808006F8: addiu       $a0, $s1, 0x34
    ctx->r4 = ADD32(ctx->r17, 0X34);
    after_1:
    // 0x808006FC: jal         0x8001B084
    // 0x80800700: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    heap_free(rdram, ctx);
        goto after_2;
    // 0x80800700: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x80800704: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80800708: jal         0x8001B084
    // 0x8080070C: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
    heap_free(rdram, ctx);
        goto after_3;
    // 0x8080070C: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
    after_3:
    // 0x80800710: sw          $zero, 0x44($s1)
    MEM_W(0X44, ctx->r17) = 0;
    // 0x80800714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800718: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080071C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800720: jr          $ra
    // 0x80800724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _gcmapsects_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F28: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F28);
    return;
    // 0x80087F2C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80024E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024E80: jr          $ra
    // 0x80024E84: nop

    return;
    // 0x80024E84: nop

;}
RECOMP_FUNC void func_80800000_fxstep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8080000C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80800010: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800014: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800018: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080001C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800020: nop

    // 0x80800024: bc1fl       L_80800050
    if (!c1cs) {
        // 0x80800028: lw          $a1, 0x0($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X0);
            goto L_80800050;
    }
    goto skip_0;
    // 0x80800028: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8080002C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800030: nop

    // 0x80800034: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800038: nop

    // 0x8080003C: bc1fl       L_80800050
    if (!c1cs) {
        // 0x80800040: lw          $a1, 0x0($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X0);
            goto L_80800050;
    }
    goto skip_1;
    // 0x80800040: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x80800044: b           L_80800068
    // 0x80800048: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800068;
    // 0x80800048: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8080004C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
L_80800050:
    // 0x80800050: bne         $a1, $zero, L_80800060
    if (ctx->r5 != 0) {
        // 0x80800054: nop
    
            goto L_80800060;
    }
    // 0x80800054: nop

    // 0x80800058: b           L_80800068
    // 0x8080005C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800068;
    // 0x8080005C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800060:
    // 0x80800060: jal         0x800C84B0
    // 0x80800064: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800C84B0(rdram, ctx);
        goto after_0;
    // 0x80800064: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
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
RECOMP_FUNC void _bswalk_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841E0: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x800841E0);
    return;
    // 0x800841E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800000_bswalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x8009EF1C
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800018: jal         0x8009EF10
    // 0x8080001C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x8080001C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800020: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800024: jal         0x8008DE24
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DE24(rdram, ctx);
        goto after_2;
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080002C: beq         $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x80800030: lwc1        $f12, 0x24($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80800098;
    }
    // 0x80800030: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: jal         0x8008E078
    // 0x8080003C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x8080003C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80800040: beq         $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x80800044: lwc1        $f12, 0x24($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80800098;
    }
    // 0x80800044: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800048: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: bne         $t6, $zero, L_80800068
    if (ctx->r14 != 0) {
        // 0x80800054: nop
    
            goto L_80800068;
    }
    // 0x80800054: nop

    // 0x80800058: jal         0x8009B9B0
    // 0x8080005C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x8080005C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800060: b           L_8080015C
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800068:
    // 0x80800068: jal         0x8009EF04
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_5;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800070: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800074: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800078: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080007C: jal         0x800F1214
    // 0x80800080: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_800F1214(rdram, ctx);
        goto after_6;
    // 0x80800080: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_6:
    // 0x80800084: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800088: jal         0x8009B9B0
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800090: b           L_8080015C
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800098:
    // 0x80800098: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8080009C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x808000A0: beq         $at, $zero, L_80800158
    if (ctx->r1 == 0) {
        // 0x808000A4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800158;
    }
    // 0x808000A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X14E0) << 16);
    // 0x808000AC: addu        $at, $at, $t7
    gpr jr_addend_808000B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808000B0: lw          $t7, 0x14E0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(435, 0X14E0));
    // 0x808000B4: jr          $t7
    // 0x808000B8: nop

    switch (jr_addend_808000B4 >> 2) {
        case 0: goto L_808000BC; break;
        case 1: goto L_808000D0; break;
        case 2: goto L_808000F4; break;
        case 3: goto L_80800118; break;
        case 4: goto L_8080013C; break;
        default: switch_error(__func__, 0x808000B4, 0x808014E0);
    }
    // 0x808000B8: nop

L_808000BC:
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: jal         0x8009B9B0
    // 0x808000C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x808000C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x808000C8: b           L_8080015C
    // 0x808000CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x808000CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000D0:
    // 0x808000D0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808000D4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000D8: jal         0x800F1214
    // 0x808000DC: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    func_800F1214(rdram, ctx);
        goto after_9;
    // 0x808000DC: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_9:
    // 0x808000E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000E4: jal         0x8009B9B0
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808000EC: b           L_8080015C
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F4:
    // 0x808000F4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808000F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000FC: jal         0x800F1214
    // 0x80800100: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_800F1214(rdram, ctx);
        goto after_11;
    // 0x80800100: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_11:
    // 0x80800104: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800108: jal         0x8009B9B0
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800110: b           L_8080015C
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800118:
    // 0x80800118: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8080011C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800120: jal         0x800F1214
    // 0x80800124: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    func_800F1214(rdram, ctx);
        goto after_13;
    // 0x80800124: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    after_13:
    // 0x80800128: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080012C: jal         0x8009B9B0
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800134: b           L_8080015C
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080013C:
    // 0x8080013C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80800140: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800144: jal         0x800F1214
    // 0x80800148: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    func_800F1214(rdram, ctx);
        goto after_15;
    // 0x80800148: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    after_15:
    // 0x8080014C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800150: jal         0x8009B9B0
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_80800158:
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080015C:
    // 0x8080015C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800160: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void _suexpressmorph_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B50: syscall     803
    recomp_syscall_handler(rdram, ctx, 0x80089B50);
    return;
    // 0x80089B54: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800338_chcanarymarycage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080033C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800340: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800344: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800348: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080034C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800350: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1572, 0X668) << 16);
    // 0x80800354: addiu       $a2, $a2, 0x668
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1572, 0X668));
    // 0x80800358: jal         0x80089D18
    // 0x8080035C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080035C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800360: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800368: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080036C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800370: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800374: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800378: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x8080037C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800380: jal         0x800EEB9C
    // 0x80800384: nop

    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x80800384: nop

    after_1:
    // 0x80800388: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080038C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800390: nop

    // 0x80800394: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x80800398: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080039C: jal         0x800EF04C
    // 0x808003A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x808003A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808003A4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1572, 0X628) << 16);
    // 0x808003A8: addiu       $t6, $t6, 0x628
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1572, 0X628));
    // 0x808003AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003BC: jal         0x800BBCB8
    // 0x808003C0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x808003C0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_3:
    // 0x808003C4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x808003D0: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x808003D4: jal         0x80086678
    // 0x808003D8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _chexploder_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808003D8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x808003DC: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x808003E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003E4: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x808003E8: jal         0x800DA544
    // 0x808003EC: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x808003EC: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_5:
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: jal         0x80800000
    // 0x808003F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_chcanarymarycage(rdram, ctx);
        goto after_6;
    // 0x808003F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808003FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800400: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800404: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800408: jr          $ra
    // 0x8080040C: nop

    return;
    // 0x8080040C: nop

;}
RECOMP_FUNC void func_800DF7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF7F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF7FC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800DF800: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800DF804: addiu       $v0, $v0, -0x35E8
    ctx->r2 = ADD32(ctx->r2, -0X35E8);
    // 0x800DF808: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800DF80C: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x800DF810: jr          $ra
    // 0x800DF814: swc1        $f14, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f14.u32l;
    return;
    // 0x800DF814: swc1        $f14, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_808000F0_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808000F4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800100: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800104: jal         0x8009BB94
    // 0x80800108: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    func_8009BB94(rdram, ctx);
        goto after_0;
    // 0x80800108: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    after_0:
    // 0x8080010C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800110: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800114: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800118: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8080011C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800120: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x80800124: jal         0x800F10B4
    // 0x80800128: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800128: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080012C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800130: jal         0x8008E35C
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_2;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800138: beq         $v0, $zero, L_808001C4
    if (ctx->r2 == 0) {
        // 0x8080013C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(380, 0X16B8) << 16);
            goto L_808001C4;
    }
    // 0x8080013C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16B8) << 16);
    // 0x80800140: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800144: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800148: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8080014C: jal         0x800F1214
    // 0x80800150: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800150: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_3:
    // 0x80800154: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800158: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080015C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800160: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800164: jal         0x800F1214
    // 0x80800168: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_800F1214(rdram, ctx);
        goto after_4;
    // 0x80800168: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_4:
    // 0x8080016C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800170: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800174: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800178: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8080017C: jal         0x800F1214
    // 0x80800180: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_800F1214(rdram, ctx);
        goto after_5;
    // 0x80800180: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_5:
    // 0x80800184: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16B4) << 16);
    // 0x80800188: lwc1        $f14, 0x16B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16B4));
    // 0x8080018C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800190: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800194: jal         0x800F1214
    // 0x80800198: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    func_800F1214(rdram, ctx);
        goto after_6;
    // 0x80800198: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_6:
    // 0x8080019C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x8009C554
    // 0x808001A8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_7;
    // 0x808001A8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x808001B4: jal         0x8009C99C
    // 0x808001B8: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_8;
    // 0x808001B8: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_8:
    // 0x808001BC: b           L_808001F4
    // 0x808001C0: nop

        goto L_808001F4;
    // 0x808001C0: nop

L_808001C4:
    // 0x808001C4: lwc1        $f0, 0x16B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16B8));
    // 0x808001C8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808001CC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808001D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x808001DC: jal         0x8009C554
    // 0x808001E0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    baroll_setAngularVelocity(rdram, ctx);
        goto after_9;
    // 0x808001E0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808001EC: jal         0x8009C99C
    // 0x808001F0: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_10;
    // 0x808001F0: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_10:
L_808001F4:
    // 0x808001F4: jal         0x80084C90
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001FC: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800200: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800204: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800208: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16BC) << 16);
    // 0x8080020C: lwc1        $f14, 0x16BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16BC));
    // 0x80800210: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800214: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800218: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8080021C: jal         0x800F10B4
    // 0x80800220: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x80800220: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x80800224: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800230: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80800234: jal         0x8009BFE4
    // 0x80800238: nop

    func_8009BFE4(rdram, ctx);
        goto after_13;
    // 0x80800238: nop

    after_13:
    // 0x8080023C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800240: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800244: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800248: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8080024C: jr          $ra
    // 0x80800250: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800250: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void sumumbofx_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F2C: lh          $t6, 0x58($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X58);
    // 0x80800F30: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800F34: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80800F38: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80800F3C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800F40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800F44: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800F48: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800F4C: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80800F50: nop

    // 0x80800F54: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800F58: sub.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800F5C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800F60: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80800F64: jr          $ra
    // 0x80800F68: nop

    return;
    // 0x80800F68: nop

;}
RECOMP_FUNC void _subaddiefind_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C60: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C60);
    return;
    // 0x80089C64: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CC0: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CC0);
    return;
    // 0x80082CC4: addi        $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
;}
RECOMP_FUNC void func_80800930_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800930: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800938: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080093C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800940: jal         0x80100094
    // 0x80800944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800948: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8080094C: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x80800950: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800954: beql        $v1, $zero, L_80800A40
    if (ctx->r3 == 0) {
        // 0x80800958: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A40;
    }
    goto skip_0;
    // 0x80800958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080095C: beq         $v1, $at, L_8080097C
    if (ctx->r3 == ctx->r1) {
        // 0x80800960: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080097C;
    }
    // 0x80800960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800964: beq         $v1, $at, L_80800A3C
    if (ctx->r3 == ctx->r1) {
        // 0x80800968: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800A3C;
    }
    // 0x80800968: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080096C: beq         $v1, $at, L_808009E0
    if (ctx->r3 == ctx->r1) {
        // 0x80800970: nop
    
            goto L_808009E0;
    }
    // 0x80800970: nop

    // 0x80800974: b           L_80800A40
    // 0x80800978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A40;
    // 0x80800978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080097C:
    // 0x8080097C: jal         0x80101F24
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_1;
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800984: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1516, 0X1034) << 16);
    // 0x80800988: addiu       $a1, $a1, 0x1034
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1516, 0X1034));
    // 0x8080098C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800990: jal         0x800F3780
    // 0x80800994: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_2;
    // 0x80800994: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80800998: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1516, 0XF40) << 16);
    // 0x8080099C: lwc1        $f4, 0xF40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1516, 0XF40));
    // 0x808009A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808009A8: jal         0x80800A50
    // 0x808009AC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_80800A50_chnewshovel(rdram, ctx);
        goto after_3;
    // 0x808009AC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x808009B0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808009B4: jal         0x80101DDC
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_4;
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808009BC: beq         $v0, $zero, L_80800A3C
    if (ctx->r2 == 0) {
        // 0x808009C0: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_80800A3C;
    }
    // 0x808009C0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808009C4: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x808009C8: beq         $t7, $zero, L_80800A3C
    if (ctx->r15 == 0) {
        // 0x808009CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A3C;
    }
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: jal         0x808007F8
    // 0x808009D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808007F8_chnewshovel(rdram, ctx);
        goto after_5;
    // 0x808009D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808009D8: b           L_80800A40
    // 0x808009DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A40;
    // 0x808009DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009E0:
    // 0x808009E0: jal         0x80101F24
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_6;
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808009E8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1516, 0X104C) << 16);
    // 0x808009EC: addiu       $a1, $a1, 0x104C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1516, 0X104C));
    // 0x808009F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808009F4: jal         0x800F3780
    // 0x808009F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_7;
    // 0x808009F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x808009FC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800A00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A08: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800A0C: jal         0x80800A50
    // 0x80800A10: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    func_80800A50_chnewshovel(rdram, ctx);
        goto after_8;
    // 0x80800A10: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x80800A14: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800A18: jal         0x80101DDC
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_9;
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800A20: beq         $v0, $zero, L_80800A3C
    if (ctx->r2 == 0) {
        // 0x80800A24: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_80800A3C;
    }
    // 0x80800A24: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800A28: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x80800A2C: beq         $t9, $zero, L_80800A3C
    if (ctx->r25 == 0) {
        // 0x80800A30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A3C;
    }
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A34: jal         0x808007F8
    // 0x80800A38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808007F8_chnewshovel(rdram, ctx);
        goto after_10;
    // 0x80800A38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
L_80800A3C:
    // 0x80800A3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A40:
    // 0x80800A40: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800A44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A48: jr          $ra
    // 0x80800A4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800A4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80808CAC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808CAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808CB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808CB4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80808CB8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80808CBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80808CC0: jal         0x808024DC
    // 0x80808CC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_808024DC_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808CC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80808CC8: lw          $v1, 0x160($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X160);
    // 0x80808CCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80808CD0: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80808CD4: sw          $t7, 0x160($s1)
    MEM_W(0X160, ctx->r17) = ctx->r15;
    // 0x80808CD8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80808CDC: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80808CE0: addu        $s0, $t6, $v0
    ctx->r16 = ADD32(ctx->r14, ctx->r2);
    // 0x80808CE4: beql        $t8, $zero, L_80808D08
    if (ctx->r24 == 0) {
        // 0x80808CE8: lh          $a1, 0x0($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X0);
            goto L_80808D08;
    }
    goto skip_0;
    // 0x80808CE8: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x80808CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80808CF0: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80808CF4: jal         0x80800424
    // 0x80808CF8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_80800424_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80808CF8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x80808CFC: b           L_80808D14
    // 0x80808D00: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
        goto L_80808D14;
    // 0x80808D00: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80808D04: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
L_80808D08:
    // 0x80808D08: jal         0x808003B4
    // 0x80808D0C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_808003B4_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80808D0C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x80808D10: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
L_80808D14:
    // 0x80808D14: sw          $t9, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r25;
    // 0x80808D18: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x80808D1C: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80808D20: beql        $t0, $zero, L_80808D3C
    if (ctx->r8 == 0) {
        // 0x80808D24: andi        $t1, $v0, 0x2
        ctx->r9 = ctx->r2 & 0X2;
            goto L_80808D3C;
    }
    goto skip_1;
    // 0x80808D24: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    skip_1:
    // 0x80808D28: jal         0x808001FC
    // 0x80808D2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808001FC_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80808D2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80808D30: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80808D34: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x80808D38: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
L_80808D3C:
    // 0x80808D3C: beql        $t1, $zero, L_80808D58
    if (ctx->r9 == 0) {
        // 0x80808D40: lh          $t3, 0x8($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X8);
            goto L_80808D58;
    }
    goto skip_2;
    // 0x80808D40: lh          $t3, 0x8($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8);
    skip_2:
    // 0x80808D44: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80808D48: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80808D4C: sw          $t2, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r10;
    // 0x80808D50: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
    // 0x80808D54: lh          $t3, 0x8($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8);
L_80808D58:
    // 0x80808D58: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80808D5C: bnel        $t3, $zero, L_80808D70
    if (ctx->r11 != 0) {
        // 0x80808D60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80808D70;
    }
    goto skip_3;
    // 0x80808D60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80808D64: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80808D68: sw          $t4, 0x160($s1)
    MEM_W(0X160, ctx->r17) = ctx->r12;
    // 0x80808D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80808D70:
    // 0x80808D70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80808D74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80808D78: jr          $ra
    // 0x80808D7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80808D7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800AE124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800AE12C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800AE130: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AE134: beq         $a0, $zero, L_800AE14C
    if (ctx->r4 == 0) {
        // 0x800AE138: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE14C;
    }
    // 0x800AE138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE13C: jal         0x800AE080
    // 0x800AE140: nop

    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x800AE140: nop

    after_0:
    // 0x800AE144: b           L_800AE150
    // 0x800AE148: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
        goto L_800AE150;
    // 0x800AE148: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800AE14C:
    // 0x800AE14C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AE150:
    // 0x800AE150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE158: jr          $ra
    // 0x800AE15C: nop

    return;
    // 0x800AE15C: nop

;}
RECOMP_FUNC void func_80801A98_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801AA0: jal         0x800A4CA8
    // 0x80801AA4: nop

    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x80801AA4: nop

    after_0:
    // 0x80801AA8: jal         0x80089418
    // 0x80801AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncba1p_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80801AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AB4: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80801AB8: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80801ABC: jr          $ra
    // 0x80801AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80801AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808005B0_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808005BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808005C0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808005C4: jal         0x800EE88C
    // 0x808005C8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x808005C8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808005CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005D0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808005D4: jal         0x800F1DF4
    // 0x808005D8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_1;
    // 0x808005D8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x808005DC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808005E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005E4: jal         0x800136E4
    // 0x808005E8: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x808005E8: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_2:
    // 0x808005EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005F0: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x808005F4: jal         0x80102CF4
    // 0x808005F8: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102CF4(rdram, ctx);
        goto after_3;
    // 0x808005F8: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_3:
    // 0x808005FC: bne         $v0, $zero, L_80800614
    if (ctx->r2 != 0) {
        // 0x80800600: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800614;
    }
    // 0x80800600: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800604: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800608: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8080060C: jal         0x80102BF8
    // 0x80800610: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_80102BF8(rdram, ctx);
        goto after_4;
    // 0x80800610: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_4:
L_80800614:
    // 0x80800614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800618: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080061C: jr          $ra
    // 0x80800620: nop

    return;
    // 0x80800620: nop

;}
