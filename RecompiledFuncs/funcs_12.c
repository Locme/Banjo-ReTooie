#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void sujiggy_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001CC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808001D0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x808001D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3354, 0X8F1) << 16);
    // 0x808001D8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808001DC: jr          $ra
    // 0x808001E0: lbu         $v0, 0x8F1($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8F1));
    return;
    // 0x808001E0: lbu         $v0, 0x8F1($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8F1));
;}
RECOMP_FUNC void chnutsnbolts_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1304, 0XE70) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xE70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1304, 0XE70));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xE70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1304, 0XE70));
;}
RECOMP_FUNC void _gcstatusDll_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088378: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088378);
    return;
    // 0x8008837C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_800DC090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC090: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DC094: addiu       $v1, $v1, -0x3810
    ctx->r3 = ADD32(ctx->r3, -0X3810);
    // 0x800DC098: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800DC09C: lui         $at, 0x19
    ctx->r1 = S32(0X19 << 16);
    // 0x800DC0A0: ori         $at, $at, 0x660D
    ctx->r1 = ctx->r1 | 0X660D;
    // 0x800DC0A4: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DC0A8: lui         $at, 0x3C6E
    ctx->r1 = S32(0X3C6E << 16);
    // 0x800DC0AC: ori         $at, $at, 0xF35F
    ctx->r1 = ctx->r1 | 0XF35F;
    // 0x800DC0B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800DC0B4: addu        $v0, $t7, $at
    ctx->r2 = ADD32(ctx->r15, ctx->r1);
    // 0x800DC0B8: jr          $ra
    // 0x800DC0BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    return;
    // 0x800DC0BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_80800C90_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C9C: jal         0x80100094
    // 0x80800CA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CA4: jal         0x800D8FF8
    // 0x80800CA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800CA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800CAC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CB8: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x80800CBC: beq         $v0, $at, L_80800D20
    if (ctx->r2 == ctx->r1) {
        // 0x80800CC0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800D20;
    }
    // 0x80800CC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CC4: beq         $v0, $at, L_80800CDC
    if (ctx->r2 == ctx->r1) {
        // 0x80800CC8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800CDC;
    }
    // 0x80800CC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800CCC: beql        $v0, $at, L_80800D6C
    if (ctx->r2 == ctx->r1) {
        // 0x80800CD0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800D6C;
    }
    goto skip_0;
    // 0x80800CD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80800CD4: b           L_80800DA8
    // 0x80800CD8: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
        goto L_80800DA8;
    // 0x80800CD8: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
L_80800CDC:
    // 0x80800CDC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800CE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800CE4: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800CE8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800CEC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800CF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800CF4: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80800CF8: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x80800CFC: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800D00: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80800D04: nop

    // 0x80800D08: bc1fl       L_80800DAC
    if (!c1cs) {
        // 0x80800D0C: lui         $at, 0x4360
        ctx->r1 = S32(0X4360 << 16);
            goto L_80800DAC;
    }
    goto skip_1;
    // 0x80800D0C: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    skip_1:
    // 0x80800D10: swc1        $f12, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f12.u32l;
    // 0x80800D14: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800D18: b           L_80800DA8
    // 0x80800D1C: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
        goto L_80800DA8;
    // 0x80800D1C: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
L_80800D20:
    // 0x80800D20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D24: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800D28: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800D2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800D30: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800D34: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800D38: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800D3C: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80800D40: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x80800D44: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800D48: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800D4C: nop

    // 0x80800D50: bc1fl       L_80800DAC
    if (!c1cs) {
        // 0x80800D54: lui         $at, 0x4360
        ctx->r1 = S32(0X4360 << 16);
            goto L_80800DAC;
    }
    goto skip_2;
    // 0x80800D54: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    skip_2:
    // 0x80800D58: swc1        $f12, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f12.u32l;
    // 0x80800D5C: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800D60: b           L_80800DA8
    // 0x80800D64: sb          $t7, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r15;
        goto L_80800DA8;
    // 0x80800D64: sb          $t7, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r15;
    // 0x80800D68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800D6C:
    // 0x80800D6C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800D70: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800D74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800D78: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800D7C: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800D80: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800D84: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80800D88: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800D8C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800D90: nop

    // 0x80800D94: bc1fl       L_80800DAC
    if (!c1cs) {
        // 0x80800D98: lui         $at, 0x4360
        ctx->r1 = S32(0X4360 << 16);
            goto L_80800DAC;
    }
    goto skip_3;
    // 0x80800D98: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    skip_3:
    // 0x80800D9C: swc1        $f12, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f12.u32l;
    // 0x80800DA0: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800DA4: sb          $zero, 0x4($v1)
    MEM_B(0X4, ctx->r3) = 0;
L_80800DA8:
    // 0x80800DA8: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
L_80800DAC:
    // 0x80800DAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800DB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DB8: mul.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80800DBC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80800DC0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80800DC4: sb          $t3, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r11;
    // 0x80800DC8: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800DCC: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800DD0: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80800DD4: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800DD8: addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
    // 0x80800DDC: sb          $v0, 0x99($a0)
    MEM_B(0X99, ctx->r4) = ctx->r2;
    // 0x80800DE0: sb          $v0, 0x9A($a0)
    MEM_B(0X9A, ctx->r4) = ctx->r2;
    // 0x80800DE4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80800DE8: nop

    // 0x80800DEC: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x80800DF0: sb          $t1, 0x98($a0)
    MEM_B(0X98, ctx->r4) = ctx->r9;
    // 0x80800DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DFC: jr          $ra
    // 0x80800E00: nop

    return;
    // 0x80800E00: nop

;}
RECOMP_FUNC void func_800FC63C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC63C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC644: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FC648: jal         0x800FC508
    // 0x800FC64C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    func_800FC508(rdram, ctx);
        goto after_0;
    // 0x800FC64C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_0:
    // 0x800FC650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC658: jr          $ra
    // 0x800FC65C: nop

    return;
    // 0x800FC65C: nop

;}
RECOMP_FUNC void func_8009CEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CEE8: lw          $v0, 0xF0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CEEC: lbu         $t6, 0x80($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X80);
    // 0x8009CEF0: beq         $t6, $zero, L_8009CEFC
    if (ctx->r14 == 0) {
        // 0x8009CEF4: nop
    
            goto L_8009CEFC;
    }
    // 0x8009CEF4: nop

    // 0x8009CEF8: sb          $zero, 0x81($v0)
    MEM_B(0X81, ctx->r2) = 0;
L_8009CEFC:
    // 0x8009CEFC: jr          $ra
    // 0x8009CF00: nop

    return;
    // 0x8009CF00: nop

;}
RECOMP_FUNC void func_800D8898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D889C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D88A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D88A4: jal         0x800B3248
    // 0x800D88A8: lw          $a0, -0x3FE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3FE0);
    freelist_free(rdram, ctx);
        goto after_0;
    // 0x800D88A8: lw          $a0, -0x3FE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3FE0);
    after_0:
    // 0x800D88AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D88B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D88B4: sw          $zero, -0x3FE0($at)
    MEM_W(-0X3FE0, ctx->r1) = 0;
    // 0x800D88B8: jr          $ra
    // 0x800D88BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D88BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void bamovespline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x80800320: jr          $ra
    // 0x80800324: sh          $a1, 0x94($t6)
    MEM_H(0X94, ctx->r14) = ctx->r5;
    return;
    // 0x80800324: sh          $a1, 0x94($t6)
    MEM_H(0X94, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800ECC_sudeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ECC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800ED0: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80800ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800ED8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800EDC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800EE0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80800EE4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800EE8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800EEC: jal         0x800EE7F8
    // 0x80800EF0: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800EF0: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80800EF4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800EF8: jal         0x800EE7F8
    // 0x80800EFC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800EFC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x80800F00: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800F04: addiu       $v1, $sp, 0x34
    ctx->r3 = ADD32(ctx->r29, 0X34);
    // 0x80800F08: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800F0C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800F10: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800F14: beq         $v0, $a0, L_80800F40
    if (ctx->r2 == ctx->r4) {
        // 0x80800F18: lwc1        $f18, 0x0($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
            goto L_80800F40;
    }
    // 0x80800F18: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
L_80800F1C:
    // 0x80800F1C: sub.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80800F20: lwc1        $f14, -0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800F24: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800F28: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800F2C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80800F30: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x80800F34: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800F38: bne         $v0, $a0, L_80800F1C
    if (ctx->r2 != ctx->r4) {
        // 0x80800F3C: swc1        $f14, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->f14.u32l;
            goto L_80800F1C;
    }
    // 0x80800F3C: swc1        $f14, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f14.u32l;
L_80800F40:
    // 0x80800F40: lwc1        $f14, -0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800F44: sub.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80800F48: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800F4C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80800F50: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80800F54: swc1        $f14, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f14.u32l;
    // 0x80800F58: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80800F5C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800F60: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80800F64: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800F68: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F70: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80800F74: nop

    // 0x80800F78: bc1t        L_80800F98
    if (c1cs) {
        // 0x80800F7C: nop
    
            goto L_80800F98;
    }
    // 0x80800F7C: nop

    // 0x80800F80: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800F84: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800F88: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800F8C: nop

    // 0x80800F90: bc1fl       L_80800FA4
    if (!c1cs) {
        // 0x80800F94: lwc1        $f18, 0x0($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
            goto L_80800FA4;
    }
    goto skip_0;
    // 0x80800F94: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
L_80800F98:
    // 0x80800F98: b           L_80801018
    // 0x80800F9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801018;
    // 0x80800F9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800FA0: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
L_80800FA4:
    // 0x80800FA4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800FA8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800FAC: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800FB0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800FB4: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80800FB8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800FBC: bc1t        L_80800FD4
    if (c1cs) {
        // 0x80800FC0: nop
    
            goto L_80800FD4;
    }
    // 0x80800FC0: nop

    // 0x80800FC4: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80800FC8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800FCC: bc1fl       L_80800FE0
    if (!c1cs) {
        // 0x80800FD0: lwc1        $f10, 0x8($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
            goto L_80800FE0;
    }
    goto skip_1;
    // 0x80800FD0: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    skip_1:
L_80800FD4:
    // 0x80800FD4: b           L_80801018
    // 0x80800FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801018;
    // 0x80800FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800FDC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
L_80800FE0:
    // 0x80800FE0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800FE4: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800FE8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800FEC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800FF0: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80800FF4: nop

    // 0x80800FF8: bc1t        L_80801010
    if (c1cs) {
        // 0x80800FFC: nop
    
            goto L_80801010;
    }
    // 0x80800FFC: nop

    // 0x80801000: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80801004: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801008: bc1f        L_80801018
    if (!c1cs) {
        // 0x8080100C: nop
    
            goto L_80801018;
    }
    // 0x8080100C: nop

L_80801010:
    // 0x80801010: b           L_80801018
    // 0x80801014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801018;
    // 0x80801014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801018:
    // 0x80801018: jr          $ra
    // 0x8080101C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080101C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bsdie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080039C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808003A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(156, 0X960) << 16);
    // 0x808003A4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808003A8: jr          $ra
    // 0x808003AC: lw          $v0, 0x960($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(156, 0X960));
    return;
    // 0x808003AC: lw          $v0, 0x960($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(156, 0X960));
;}
RECOMP_FUNC void bsrest_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800468: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080046C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800470: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800474: jal         0x8008E35C
    // 0x80800478: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    player_inWater(rdram, ctx);
        goto after_0;
    // 0x80800478: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8080047C: beq         $v0, $zero, L_80800488
    if (ctx->r2 == 0) {
        // 0x80800480: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800488;
    }
    // 0x80800480: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800484: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
L_80800488:
    // 0x80800488: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080048C: jal         0x8080032C
    // 0x80800490: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    static_344_8080032C(rdram, ctx);
        goto after_1;
    // 0x80800490: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800494: beq         $v0, $zero, L_808004A8
    if (ctx->r2 == 0) {
        // 0x80800498: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808004A8;
    }
    // 0x80800498: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080049C: jal         0x8080069C
    // 0x808004A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bsrest_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x808004A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808004A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808004A8:
    // 0x808004A8: jal         0x8009E5C8
    // 0x808004AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808004AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808004B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004B8: jr          $ra
    // 0x808004BC: nop

    return;
    // 0x808004BC: nop

;}
RECOMP_FUNC void func_80801710_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801710: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801714: jr          $ra
    // 0x80801718: sb          $t6, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r14;
    return;
    // 0x80801718: sb          $t6, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80802394_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080239C: jal         0x801015D0
    // 0x808023A0: nop

    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x808023A0: nop

    after_0:
    // 0x808023A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808023A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808023AC: jr          $ra
    // 0x808023B0: nop

    return;
    // 0x808023B0: nop

;}
RECOMP_FUNC void func_800D4398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D439C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D43A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D43A4: jal         0x800D41D8
    // 0x800D43A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D41D8(rdram, ctx);
        goto after_0;
    // 0x800D43A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D43AC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800D43B0: beq         $v0, $at, L_800D43CC
    if (ctx->r2 == ctx->r1) {
        // 0x800D43B4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D43CC;
    }
    // 0x800D43B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D43B8: jal         0x800C6E38
    // 0x800D43BC: nop

    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x800D43BC: nop

    after_1:
    // 0x800D43C0: bne         $v0, $zero, L_800D43CC
    if (ctx->r2 != 0) {
        // 0x800D43C4: nop
    
            goto L_800D43CC;
    }
    // 0x800D43C4: nop

    // 0x800D43C8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800D43CC:
    // 0x800D43CC: jal         0x800D1ACC
    // 0x800D43D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800D1ACC(rdram, ctx);
        goto after_2;
    // 0x800D43D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800D43D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D43D8: sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2 << 1);
    // 0x800D43DC: jal         0x800D1960
    // 0x800D43E0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800D1960(rdram, ctx);
        goto after_3;
    // 0x800D43E0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x800D43E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D43E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D43EC: jr          $ra
    // 0x800D43F0: nop

    return;
    // 0x800D43F0: nop

    // 0x800D43F4: nop

    // 0x800D43F8: nop

    // 0x800D43FC: nop

;}
RECOMP_FUNC void func_80801144_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801148: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080114C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801150: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801154: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801158: jal         0x80800350
    // 0x8080115C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    bsstatue_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080115C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x80801160: jal         0x80097AD0
    // 0x80801164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_1;
    // 0x80801164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801168: beq         $v0, $zero, L_8080117C
    if (ctx->r2 == 0) {
        // 0x8080116C: nop
    
            goto L_8080117C;
    }
    // 0x8080116C: nop

    // 0x80801170: jal         0x800848A8
    // 0x80801174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_2;
    // 0x80801174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801178: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8080117C:
    // 0x8080117C: jal         0x8009EF10
    // 0x80801180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_3;
    // 0x80801180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801188: bne         $v0, $at, L_80801194
    if (ctx->r2 != ctx->r1) {
        // 0x8080118C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801194;
    }
    // 0x8080118C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801190: addiu       $s1, $zero, 0xFA
    ctx->r17 = ADD32(0, 0XFA);
L_80801194:
    // 0x80801194: jal         0x80091A58
    // 0x80801198: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_4;
    // 0x80801198: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x8080119C: beql        $v0, $zero, L_808011C0
    if (ctx->r2 == 0) {
        // 0x808011A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011C0;
    }
    goto skip_0;
    // 0x808011A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808011A4: jal         0x80800104
    // 0x808011A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800104_bsstatue(rdram, ctx);
        goto after_5;
    // 0x808011A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808011AC: beq         $v0, $zero, L_808011BC
    if (ctx->r2 == 0) {
        // 0x808011B0: addiu       $s1, $zero, 0xFC
        ctx->r17 = ADD32(0, 0XFC);
            goto L_808011BC;
    }
    // 0x808011B0: addiu       $s1, $zero, 0xFC
    ctx->r17 = ADD32(0, 0XFC);
    // 0x808011B4: b           L_808011BC
    // 0x808011B8: addiu       $s1, $zero, 0xF8
    ctx->r17 = ADD32(0, 0XF8);
        goto L_808011BC;
    // 0x808011B8: addiu       $s1, $zero, 0xF8
    ctx->r17 = ADD32(0, 0XF8);
L_808011BC:
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808011C0:
    // 0x808011C0: jal         0x80091A58
    // 0x808011C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_6;
    // 0x808011C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x808011C8: beq         $v0, $zero, L_808011D4
    if (ctx->r2 == 0) {
        // 0x808011CC: nop
    
            goto L_808011D4;
    }
    // 0x808011CC: nop

    // 0x808011D0: addiu       $s1, $zero, 0xFB
    ctx->r17 = ADD32(0, 0XFB);
L_808011D4:
    // 0x808011D4: jal         0x80800078
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800078_bsstatue(rdram, ctx);
        goto after_7;
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808011DC: beq         $v0, $zero, L_808011E8
    if (ctx->r2 == 0) {
        // 0x808011E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011E8;
    }
    // 0x808011E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011E4: addiu       $s1, $zero, 0xFD
    ctx->r17 = ADD32(0, 0XFD);
L_808011E8:
    // 0x808011E8: jal         0x8009E5C8
    // 0x808011EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x808011EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x808011F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808011F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808011FC: jr          $ra
    // 0x80801200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808010E0_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010E4: andi        $t7, $a2, 0x2
    ctx->r15 = ctx->r6 & 0X2;
    // 0x808010E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808010F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808010F4: beq         $t7, $zero, L_80801118
    if (ctx->r15 == 0) {
        // 0x808010F8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801118;
    }
    // 0x808010F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808010FC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801100: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80801104: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801108: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080110C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80801110: jal         0x800E1610
    // 0x80801114: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_800E1610(rdram, ctx);
        goto after_0;
    // 0x80801114: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_0:
L_80801118:
    // 0x80801118: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8080111C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801120: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80801124: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80801128: beql        $t9, $zero, L_8080113C
    if (ctx->r25 == 0) {
        // 0x8080112C: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_8080113C;
    }
    goto skip_0;
    // 0x8080112C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801130: jal         0x80018820
    // 0x80801134: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_1;
    // 0x80801134: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_1:
    // 0x80801138: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_8080113C:
    // 0x8080113C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80801140: beq         $t0, $zero, L_80801158
    if (ctx->r8 == 0) {
        // 0x80801144: andi        $t2, $t1, 0x8
        ctx->r10 = ctx->r9 & 0X8;
            goto L_80801158;
    }
    // 0x80801144: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x80801148: beql        $t2, $zero, L_8080115C
    if (ctx->r10 == 0) {
        // 0x8080114C: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_8080115C;
    }
    goto skip_1;
    // 0x8080114C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80801150: jal         0x800FFAB0
    // 0x80801154: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80801154: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
L_80801158:
    // 0x80801158: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_8080115C:
    // 0x8080115C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80801160: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x80801164: beql        $t4, $zero, L_8080117C
    if (ctx->r12 == 0) {
        // 0x80801168: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080117C;
    }
    goto skip_2;
    // 0x80801168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8080116C: lbu         $t6, 0x65($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X65);
    // 0x80801170: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80801174: sb          $t7, 0x65($t5)
    MEM_B(0X65, ctx->r13) = ctx->r15;
    // 0x80801178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080117C:
    // 0x8080117C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801180: jr          $ra
    // 0x80801184: nop

    return;
    // 0x80801184: nop

;}
RECOMP_FUNC void func_80800034_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: lw          $v0, 0x164($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X164);
    // 0x80800038: slti        $t6, $v0, 0x4
    ctx->r14 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8080003C: jr          $ra
    // 0x80800040: xori        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 ^ 0X1;
    return;
    // 0x80800040: xori        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 ^ 0X1;
;}
RECOMP_FUNC void func_800D3F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3F2C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3F34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800D3F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3F3C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800D3F40: jal         0x800DA544
    // 0x800D3F44: lhu         $a0, -0x4A46($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4A46);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x800D3F44: lhu         $a0, -0x4A46($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4A46);
    after_0:
    // 0x800D3F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3F50: jr          $ra
    // 0x800D3F54: nop

    return;
    // 0x800D3F54: nop

;}
RECOMP_FUNC void func_80800528_chgoldstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800528: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080052C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800530: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800534: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800538: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8080053C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800540: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80800544: bltzl       $t8, L_80800830
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800548: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800830;
    }
    goto skip_0;
    // 0x80800548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080054C: jal         0x80100094
    // 0x80800550: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800550: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800558: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x8080055C: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800560: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80800564: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x80800568: beq         $at, $zero, L_808007CC
    if (ctx->r1 == 0) {
        // 0x8080056C: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_808007CC;
    }
    // 0x8080056C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800570: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2136, 0X868) << 16);
    // 0x80800574: addu        $at, $at, $t1
    gpr jr_addend_8080057C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800578: lw          $t1, 0x868($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2136, 0X868));
    // 0x8080057C: jr          $t1
    // 0x80800580: nop

    switch (jr_addend_8080057C >> 2) {
        case 0: goto L_80800584; break;
        case 1: goto L_808005C0; break;
        case 2: goto L_808005D0; break;
        case 3: goto L_808006EC; break;
        case 4: goto L_80800788; break;
        case 5: goto L_808007A8; break;
        default: switch_error(__func__, 0x8080057C, 0x80800868);
    }
    // 0x80800580: nop

L_80800584:
    // 0x80800584: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x80800588: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080058C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800590: lui         $a1, 0x4370
    ctx->r5 = S32(0X4370 << 16);
    // 0x80800594: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800598: jal         0x80089F20
    // 0x8080059C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080059C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_1:
    // 0x808005A0: jal         0x800DA298
    // 0x808005A4: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808005A4: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_2:
    // 0x808005A8: beq         $v0, $zero, L_808007CC
    if (ctx->r2 == 0) {
        // 0x808005AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007CC;
    }
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: jal         0x80800150
    // 0x808005B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800150_chgoldstatue(rdram, ctx);
        goto after_3;
    // 0x808005B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808005B8: b           L_808007D0
    // 0x808005BC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
        goto L_808007D0;
    // 0x808005BC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_808005C0:
    // 0x808005C0: jal         0x8080032C
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080032C_chgoldstatue(rdram, ctx);
        goto after_4;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808005C8: b           L_808007D0
    // 0x808005CC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
        goto L_808007D0;
    // 0x808005CC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_808005D0:
    // 0x808005D0: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x808005D4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808005D8: jal         0x80101E14
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808005E0: beq         $v0, $zero, L_808005F0
    if (ctx->r2 == 0) {
        // 0x808005E4: nop
    
            goto L_808005F0;
    }
    // 0x808005E4: nop

    // 0x808005E8: jal         0x80086AF0
    // 0x808005EC: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x808005EC: nop

    after_6:
L_808005F0:
    // 0x808005F0: jal         0x80101F24
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_7;
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808005F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2136, 0X880) << 16);
    // 0x808005FC: lwc1        $f2, 0x880($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2136, 0X880));
    // 0x80800600: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800604: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800608: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080060C: bc1f        L_80800618
    if (!c1cs) {
        // 0x80800610: nop
    
            goto L_80800618;
    }
    // 0x80800610: nop

    // 0x80800614: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80800618:
    // 0x80800618: jal         0x80101E14
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800620: beq         $v0, $zero, L_80800644
    if (ctx->r2 == 0) {
        // 0x80800624: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800644;
    }
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800628: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2136, 0X890) << 16);
    // 0x8080062C: addiu       $a2, $a2, 0x890
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2136, 0X890));
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: jal         0x80089D18
    // 0x80800638: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800638: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x8080063C: b           L_8080069C
    // 0x80800640: lui         $a1, 0x3EC7
    ctx->r5 = S32(0X3EC7 << 16);
        goto L_8080069C;
    // 0x80800640: lui         $a1, 0x3EC7
    ctx->r5 = S32(0X3EC7 << 16);
L_80800644:
    // 0x80800644: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2136, 0X940) << 16);
    // 0x80800648: jal         0x80101E4C
    // 0x8080064C: addiu       $a1, $a1, 0x940
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2136, 0X940));
    func_80101E4C(rdram, ctx);
        goto after_10;
    // 0x8080064C: addiu       $a1, $a1, 0x940
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2136, 0X940));
    after_10:
    // 0x80800650: beq         $v0, $zero, L_80800674
    if (ctx->r2 == 0) {
        // 0x80800654: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800674;
    }
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2136, 0X8A0) << 16);
    // 0x8080065C: addiu       $a2, $a2, 0x8A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2136, 0X8A0));
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800664: jal         0x80089D18
    // 0x80800668: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800668: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_11:
    // 0x8080066C: b           L_8080069C
    // 0x80800670: lui         $a1, 0x3EC7
    ctx->r5 = S32(0X3EC7 << 16);
        goto L_8080069C;
    // 0x80800670: lui         $a1, 0x3EC7
    ctx->r5 = S32(0X3EC7 << 16);
L_80800674:
    // 0x80800674: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2136, 0X954) << 16);
    // 0x80800678: jal         0x80101E4C
    // 0x8080067C: addiu       $a1, $a1, 0x954
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2136, 0X954));
    func_80101E4C(rdram, ctx);
        goto after_12;
    // 0x8080067C: addiu       $a1, $a1, 0x954
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2136, 0X954));
    after_12:
    // 0x80800680: beq         $v0, $zero, L_80800698
    if (ctx->r2 == 0) {
        // 0x80800684: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800698;
    }
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2136, 0X8B8) << 16);
    // 0x8080068C: addiu       $a2, $a2, 0x8B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2136, 0X8B8));
    // 0x80800690: jal         0x80089D18
    // 0x80800694: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800694: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_13:
L_80800698:
    // 0x80800698: lui         $a1, 0x3EC7
    ctx->r5 = S32(0X3EC7 << 16);
L_8080069C:
    // 0x8080069C: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    // 0x808006A0: jal         0x80101E14
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808006A8: beq         $v0, $zero, L_808006C4
    if (ctx->r2 == 0) {
        // 0x808006AC: nop
    
            goto L_808006C4;
    }
    // 0x808006AC: nop

    // 0x808006B0: jal         0x800DA544
    // 0x808006B4: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_15;
    // 0x808006B4: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_15:
    // 0x808006B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808006BC: jal         0x800898C0
    // 0x808006C0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_16;
    // 0x808006C0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_16:
L_808006C4:
    // 0x808006C4: jal         0x8080032C
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080032C_chgoldstatue(rdram, ctx);
        goto after_17;
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808006CC: jal         0x80101DDC
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_18;
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808006D4: beq         $v0, $zero, L_808007CC
    if (ctx->r2 == 0) {
        // 0x808006D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007CC;
    }
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: jal         0x80800150
    // 0x808006E0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800150_chgoldstatue(rdram, ctx);
        goto after_19;
    // 0x808006E0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_19:
    // 0x808006E4: b           L_808007D0
    // 0x808006E8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
        goto L_808007D0;
    // 0x808006E8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_808006EC:
    // 0x808006EC: jal         0x8080032C
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080032C_chgoldstatue(rdram, ctx);
        goto after_20;
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808006F4: jal         0x80101F24
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_21;
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808006FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2136, 0X884) << 16);
    // 0x80800700: lwc1        $f2, 0x884($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2136, 0X884));
    // 0x80800704: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800710: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800714: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800718: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2136, 0X890) << 16);
    // 0x8080071C: bc1f        L_80800728
    if (!c1cs) {
        // 0x80800720: nop
    
            goto L_80800728;
    }
    // 0x80800720: nop

    // 0x80800724: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80800728:
    // 0x80800728: jal         0x80089D20
    // 0x8080072C: addiu       $a2, $a2, 0x890
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2136, 0X890));
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x8080072C: addiu       $a2, $a2, 0x890
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2136, 0X890));
    after_22:
    // 0x80800730: lui         $a1, 0x3EAE
    ctx->r5 = S32(0X3EAE << 16);
    // 0x80800734: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80800738: jal         0x80101E14
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_23;
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800740: beq         $v0, $zero, L_80800764
    if (ctx->r2 == 0) {
        // 0x80800744: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800764;
    }
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800748: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080074C: jal         0x800898C0
    // 0x80800750: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_24;
    // 0x80800750: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_24:
    // 0x80800754: jal         0x800DA544
    // 0x80800758: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_25;
    // 0x80800758: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_25:
    // 0x8080075C: b           L_808007D0
    // 0x80800760: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
        goto L_808007D0;
    // 0x80800760: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_80800764:
    // 0x80800764: lui         $a1, 0x3EC7
    ctx->r5 = S32(0X3EC7 << 16);
    // 0x80800768: jal         0x80101E14
    // 0x8080076C: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    func_80101E14(rdram, ctx);
        goto after_26;
    // 0x8080076C: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    after_26:
    // 0x80800770: beq         $v0, $zero, L_808007CC
    if (ctx->r2 == 0) {
        // 0x80800774: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007CC;
    }
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800778: jal         0x80800150
    // 0x8080077C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800150_chgoldstatue(rdram, ctx);
        goto after_27;
    // 0x8080077C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_27:
    // 0x80800780: b           L_808007D0
    // 0x80800784: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
        goto L_808007D0;
    // 0x80800784: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_80800788:
    // 0x80800788: jal         0x8010C500
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_28;
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800790: bne         $v0, $zero, L_808007CC
    if (ctx->r2 != 0) {
        // 0x80800794: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007CC;
    }
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: jal         0x80800150
    // 0x8080079C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800150_chgoldstatue(rdram, ctx);
        goto after_29;
    // 0x8080079C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_29:
    // 0x808007A0: b           L_808007D0
    // 0x808007A4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
        goto L_808007D0;
    // 0x808007A4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_808007A8:
    // 0x808007A8: jal         0x8010C500
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_30;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808007B0: beql        $v0, $zero, L_808007D0
    if (ctx->r2 == 0) {
        // 0x808007B4: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_808007D0;
    }
    goto skip_1;
    // 0x808007B4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x808007B8: jal         0x800F54E4
    // 0x808007BC: nop

    func_800F54E4(rdram, ctx);
        goto after_31;
    // 0x808007BC: nop

    after_31:
    // 0x808007C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007C4: jal         0x800F7B9C
    // 0x808007C8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_800F7B9C(rdram, ctx);
        goto after_32;
    // 0x808007C8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_32:
L_808007CC:
    // 0x808007CC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_808007D0:
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808007D8: beq         $t5, $zero, L_8080082C
    if (ctx->r13 == 0) {
        // 0x808007DC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8080082C;
    }
    // 0x808007DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808007E0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2136, 0X968) << 16);
    // 0x808007E4: addiu       $a3, $a3, 0x968
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2136, 0X968));
    // 0x808007E8: jal         0x80089D50
    // 0x808007EC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_33;
    // 0x808007EC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_33:
    // 0x808007F0: lw          $t8, 0x70($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X70);
    // 0x808007F4: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x808007F8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2136, 0X97C) << 16);
    // 0x808007FC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80800800: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800804: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800808: addiu       $a3, $a3, 0x97C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2136, 0X97C));
    // 0x8080080C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800810: jal         0x80089D68
    // 0x80800814: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_34;
    // 0x80800814: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    after_34:
    // 0x80800818: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080081C: andi        $t0, $v0, 0x1FF
    ctx->r8 = ctx->r2 & 0X1FF;
    // 0x80800820: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80800824: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80800828: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
L_8080082C:
    // 0x8080082C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800830:
    // 0x80800830: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800834: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800838: jr          $ra
    // 0x8080083C: nop

    return;
    // 0x8080083C: nop

;}
RECOMP_FUNC void _bsmum_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083850: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083850);
    return;
    // 0x80083854: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_800CFA70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFA70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CFA74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CFA78: jal         0x800CF918
    // 0x800CFA7C: nop

    func_800CF918(rdram, ctx);
        goto after_0;
    // 0x800CFA7C: nop

    after_0:
    // 0x800CFA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CFA84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CFA88: jr          $ra
    // 0x800CFA8C: nop

    return;
    // 0x800CFA8C: nop

;}
RECOMP_FUNC void _chevilspirit_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D60: syscall     236
    recomp_syscall_handler(rdram, ctx, 0x80085D60);
    return;
    // 0x80085D64: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bskazstilt_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801148: jal         0x8080013C
    // 0x8080114C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080013C_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x8080114C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801150: jal         0x80082FE0
    // 0x80801154: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801154: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080115C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801160: jr          $ra
    // 0x80801164: nop

    return;
    // 0x80801164: nop

;}
RECOMP_FUNC void func_8001575C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001575C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015760: jr          $ra
    // 0x80015764: lw          $v0, -0x7078($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7078);
    return;
    // 0x80015764: lw          $v0, -0x7078($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7078);
;}
RECOMP_FUNC void suegg_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009E4: jal         0x80100094
    // 0x808009E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808009F0: jal         0x800A940C
    // 0x808009F4: lh          $a0, 0x3A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X3A);
    func_800A940C(rdram, ctx);
        goto after_1;
    // 0x808009F4: lh          $a0, 0x3A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X3A);
    after_1:
    // 0x808009F8: jal         0x800C5190
    // 0x808009FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C5190(rdram, ctx);
        goto after_2;
    // 0x808009FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800A00: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800A04: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800A08: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800A0C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A10: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800A14: nop

    // 0x80800A18: bc1fl       L_80800A28
    if (!c1cs) {
        // 0x80800A1C: add.s       $f4, $f2, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
            goto L_80800A28;
    }
    goto skip_0;
    // 0x80800A1C: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    skip_0:
    // 0x80800A20: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80800A24: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
L_80800A28:
    // 0x80800A28: lwc1        $f6, 0x30($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X30);
    // 0x80800A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800A30: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800A34: nop

    // 0x80800A38: bc1f        L_80800A44
    if (!c1cs) {
        // 0x80800A3C: nop
    
            goto L_80800A44;
    }
    // 0x80800A3C: nop

    // 0x80800A40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A44:
    // 0x80800A44: bnel        $v0, $zero, L_80800A60
    if (ctx->r2 != 0) {
        // 0x80800A48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800A60;
    }
    goto skip_1;
    // 0x80800A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800A4C: jal         0x800DA298
    // 0x80800A50: addiu       $a0, $zero, 0x662
    ctx->r4 = ADD32(0, 0X662);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800A50: addiu       $a0, $zero, 0x662
    ctx->r4 = ADD32(0, 0X662);
    after_3:
    // 0x80800A54: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800A58: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A60:
    // 0x80800A60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A64: jr          $ra
    // 0x80800A68: nop

    return;
    // 0x80800A68: nop

;}
RECOMP_FUNC void badrone_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080036C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800374: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x80800378: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8080037C: jal         0x800846F8
    // 0x80800380: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    _badata_entrypoint_23(rdram, ctx);
        goto after_0;
    // 0x80800380: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    after_0:
    // 0x80800384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void func_8009FE78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FE78: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x8009FE7C: jr          $ra
    // 0x8009FE80: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    return;
    // 0x8009FE80: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
;}
RECOMP_FUNC void func_80802720_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802728: jal         0x80104248
    // 0x8080272C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x8080272C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802730: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802734: jal         0x8008AED4
    // 0x80802738: addiu       $a1, $zero, 0x105
    ctx->r5 = ADD32(0, 0X105);
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x80802738: addiu       $a1, $zero, 0x105
    ctx->r5 = ADD32(0, 0X105);
    after_1:
    // 0x8080273C: lui         $a1, 0x4B18
    ctx->r5 = S32(0X4B18 << 16);
    // 0x80802740: ori         $a1, $a1, 0x9680
    ctx->r5 = ctx->r5 | 0X9680;
    // 0x80802744: jal         0x80101CDC
    // 0x80802748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101CDC(rdram, ctx);
        goto after_2;
    // 0x80802748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080274C: jal         0x808026D0
    // 0x80802750: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808026D0_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x80802750: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80802754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080275C: jr          $ra
    // 0x80802760: nop

    return;
    // 0x80802760: nop

;}
RECOMP_FUNC void chdodgemcontrol_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1752, 0X4DB4) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x4DB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1752, 0X4DB4));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x4DB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1752, 0X4DB4));
;}
RECOMP_FUNC void func_808008BC_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808008C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808008C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808008CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008D0: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x808008D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808008D8: jal         0x800EE7F8
    // 0x808008DC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808008DC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x808008E0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808008E4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808008E8: jal         0x800EF1B8
    // 0x808008EC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808008EC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_1:
    // 0x808008F0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808008F4: jal         0x800EE7F8
    // 0x808008F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808008F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808008FC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800900: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800904: jal         0x800EF1B8
    // 0x80800908: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x80800908: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    after_3:
    // 0x8080090C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800910: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800914: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800918: jal         0x800BEF00
    // 0x8080091C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_4;
    // 0x8080091C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_4:
    // 0x80800920: beq         $v0, $zero, L_8080095C
    if (ctx->r2 == 0) {
        // 0x80800924: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080095C;
    }
    // 0x80800924: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800928: jal         0x800EE7F8
    // 0x8080092C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8080092C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x80800930: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800934: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800938: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080093C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800940: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800944: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800948: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080094C: jal         0x800EF1B8
    // 0x80800950: nop

    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x80800950: nop

    after_6:
    // 0x80800954: jal         0x80103014
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_7;
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_8080095C:
    // 0x8080095C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800960: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800964: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800968: jr          $ra
    // 0x8080096C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080096C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bskazcrouch_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800788: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080078C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(224, 0X7C0) << 16);
    // 0x80800790: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800794: jr          $ra
    // 0x80800798: lw          $v0, 0x7C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(224, 0X7C0));
    return;
    // 0x80800798: lw          $v0, 0x7C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(224, 0X7C0));
;}
RECOMP_FUNC void chheggy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B68: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2456, 0X1F58) << 16);
    // 0x80801B6C: jr          $ra
    // 0x80801B70: addiu       $v0, $v0, 0x1F58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2456, 0X1F58));
    return;
    // 0x80801B70: addiu       $v0, $v0, 0x1F58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2456, 0X1F58));
;}
RECOMP_FUNC void func_80800000_chfactorybtwmdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8080000C: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x80800010: jal         0x8010C500
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800018: beq         $v0, $zero, L_8080004C
    if (ctx->r2 == 0) {
        // 0x8080001C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080004C;
    }
    // 0x8080001C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: jal         0x800F54E4
    // 0x80800024: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800024: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800028: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080002C: jal         0x800F64A4
    // 0x80800030: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800F64A4(rdram, ctx);
        goto after_2;
    // 0x80800030: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x80800034: beq         $v0, $zero, L_8080004C
    if (ctx->r2 == 0) {
        // 0x80800038: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080004C;
    }
    // 0x80800038: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800040: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800044: b           L_80800058
    // 0x80800048: swc1        $f6, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f6.u32l;
        goto L_80800058;
    // 0x80800048: swc1        $f6, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f6.u32l;
L_8080004C:
    // 0x8080004C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800050: nop

    // 0x80800054: swc1        $f8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f8.u32l;
L_80800058:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_80802590_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802590: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80802594: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80802598: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8080259C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808025A0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x808025A4: jal         0x801040A8
    // 0x808025A8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    func_801040A8(rdram, ctx);
        goto after_0;
    // 0x808025A8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    after_0:
    // 0x808025AC: jal         0x800AE0B8
    // 0x808025B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AE0B8(rdram, ctx);
        goto after_1;
    // 0x808025B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808025B4: bne         $v0, $zero, L_808025CC
    if (ctx->r2 != 0) {
        // 0x808025B8: lw          $a0, 0x5C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X5C);
            goto L_808025CC;
    }
    // 0x808025B8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808025BC: jal         0x800EE7F8
    // 0x808025C0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808025C0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x808025C4: b           L_80802668
    // 0x808025C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802668;
    // 0x808025C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808025CC:
    // 0x808025CC: jal         0x801039E4
    // 0x808025D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_3;
    // 0x808025D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808025D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808025D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808025DC: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808025E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808025E4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808025E8: jal         0x800EFA4C
    // 0x808025EC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x808025EC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x808025F0: jal         0x800B2824
    // 0x808025F4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800B2824(rdram, ctx);
        goto after_5;
    // 0x808025F4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x808025F8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808025FC: jal         0x801040A8
    // 0x80802600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801040A8(rdram, ctx);
        goto after_6;
    // 0x80802600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802604: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80802608: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8080260C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80802610: addiu       $t7, $sp, 0x48
    ctx->r15 = ADD32(ctx->r29, 0X48);
    // 0x80802614: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80802618: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080261C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80802620: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80802624: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80802628: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8080262C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x80802630: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80802634: jal         0x800B0D80
    // 0x80802638: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800B0D80(rdram, ctx);
        goto after_7;
    // 0x80802638: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_7:
    // 0x8080263C: bne         $v0, $zero, L_80802658
    if (ctx->r2 != 0) {
        // 0x80802640: lw          $a2, 0x38($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X38);
            goto L_80802658;
    }
    // 0x80802640: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80802644: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80802648: jal         0x800EE7F8
    // 0x8080264C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x8080264C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_8:
    // 0x80802650: b           L_80802668
    // 0x80802654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802668;
    // 0x80802654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802658:
    // 0x80802658: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080265C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80802660: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80802664: nop

L_80802668:
    // 0x80802668: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080266C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80802670: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80802674: jr          $ra
    // 0x80802678: nop

    return;
    // 0x80802678: nop

;}
RECOMP_FUNC void func_800EBED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBED4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EBED8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EBEDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EBEE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EBEE4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800EBEE8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800EBEEC: jal         0x800EBD78
    // 0x800EBEF0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800EBD78(rdram, ctx);
        goto after_0;
    // 0x800EBEF0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800EBEF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EBEF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800EBEFC: jal         0x8002D6E0
    // 0x800EBF00: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    _bzero(rdram, ctx);
        goto after_1;
    // 0x800EBF00: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_1:
    // 0x800EBF04: jal         0x800EC854
    // 0x800EBF08: nop

    func_800EC854(rdram, ctx);
        goto after_2;
    // 0x800EBF08: nop

    after_2:
    // 0x800EBF0C: lhu         $t9, 0x12($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X12);
    // 0x800EBF10: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800EBF14: lhu         $t6, 0x24($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X24);
    // 0x800EBF18: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800EBF1C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800EBF20: sh          $t1, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r9;
    // 0x800EBF24: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800EBF28: andi        $t7, $t6, 0x3F
    ctx->r15 = ctx->r14 & 0X3F;
    // 0x800EBF2C: lbu         $t2, 0x13($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X13);
    // 0x800EBF30: sll         $t5, $t3, 6
    ctx->r13 = S32(ctx->r11 << 6);
    // 0x800EBF34: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x800EBF38: sh          $t9, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r25;
    // 0x800EBF3C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800EBF40: lbu         $t7, 0x2A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2A);
    // 0x800EBF44: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800EBF48: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x800EBF4C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800EBF50: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x800EBF54: addiu       $t6, $t6, -0x44B0
    ctx->r14 = ADD32(ctx->r14, -0X44B0);
    // 0x800EBF58: ori         $t9, $t7, 0x2
    ctx->r25 = ctx->r15 | 0X2;
    // 0x800EBF5C: sb          $t4, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r12;
    // 0x800EBF60: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    // 0x800EBF64: sb          $t9, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r25;
    // 0x800EBF68: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800EBF6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800EBF70: jal         0x800EBE74
    // 0x800EBF74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EBE74(rdram, ctx);
        goto after_3;
    // 0x800EBF74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800EBF78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EBF7C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800EBF80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EBF84: jr          $ra
    // 0x800EBF88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800EBF88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _bsblongleg_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A48: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A48);
    return;
    // 0x80082A4C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80801200_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801200: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801204: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080120C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801210: jal         0x800BEA88
    // 0x80801214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x80801214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80801218: jal         0x80088848
    // 0x8080121C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x8080121C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801220: beq         $v0, $zero, L_80801250
    if (ctx->r2 == 0) {
        // 0x80801224: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801250;
    }
    // 0x80801224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801228: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x8080122C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801230: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801234: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80801238: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x8080123C: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
    // 0x80801240: jal         0x80101FDC
    // 0x80801244: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80801244: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80801248: b           L_80801310
    // 0x8080124C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
        goto L_80801310;
    // 0x8080124C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80801250:
    // 0x80801250: jal         0x80088840
    // 0x80801254: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80801254: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_3:
    // 0x80801258: beq         $v0, $zero, L_808012AC
    if (ctx->r2 == 0) {
        // 0x8080125C: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_808012AC;
    }
    // 0x8080125C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80801260: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801268: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080126C: jal         0x80101FDC
    // 0x80801270: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80801270: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x80801274: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80801278: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080127C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801280: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80801284: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80801288: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X1478) << 16);
    // 0x8080128C: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x80801290: lwc1        $f12, 0x1478($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X1478));
    // 0x80801294: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801298: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080129C: jal         0x800DC178
    // 0x808012A0: nop

    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x808012A0: nop

    after_5:
    // 0x808012A4: b           L_8080130C
    // 0x808012A8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_8080130C;
    // 0x808012A8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_808012AC:
    // 0x808012AC: jal         0x800DA298
    // 0x808012B0: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808012B0: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    after_6:
    // 0x808012B4: bne         $v0, $zero, L_808012EC
    if (ctx->r2 != 0) {
        // 0x808012B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012EC;
    }
    // 0x808012B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012BC: lbu         $t2, 0x79($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X79);
    // 0x808012C0: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x808012C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808012C8: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x808012CC: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x808012D0: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
    // 0x808012D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808012DC: jal         0x80101FDC
    // 0x808012E0: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808012E0: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    after_7:
    // 0x808012E4: b           L_80801344
    // 0x808012E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801344;
    // 0x808012E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808012EC:
    // 0x808012EC: lbu         $t5, 0x79($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X79);
    // 0x808012F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808012F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808012F8: andi        $t6, $t5, 0xFF0F
    ctx->r14 = ctx->r13 & 0XFF0F;
    // 0x808012FC: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80801300: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
    // 0x80801304: jal         0x80101FDC
    // 0x80801308: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80801308: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    after_8:
L_8080130C:
    // 0x8080130C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80801310:
    // 0x80801310: addiu       $a1, $zero, 0x659
    ctx->r5 = ADD32(0, 0X659);
    // 0x80801314: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801318: jal         0x80088F28
    // 0x8080131C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x8080131C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x80801320: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80801324: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801328: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080132C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80801330: bne         $t9, $at, L_80801340
    if (ctx->r25 != ctx->r1) {
        // 0x80801334: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1284, 0X174C) << 16);
            goto L_80801340;
    }
    // 0x80801334: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1284, 0X174C) << 16);
    // 0x80801338: jal         0x800C4AF0
    // 0x8080133C: addiu       $a1, $a1, 0x174C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1284, 0X174C));
    func_800C4AF0(rdram, ctx);
        goto after_10;
    // 0x8080133C: addiu       $a1, $a1, 0x174C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1284, 0X174C));
    after_10:
L_80801340:
    // 0x80801340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801344:
    // 0x80801344: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080134C: jr          $ra
    // 0x80801350: nop

    return;
    // 0x80801350: nop

;}
RECOMP_FUNC void func_80801494_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801494: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801498: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080149C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808014A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808014A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808014A8: jal         0x80100094
    // 0x808014AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808014AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808014B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808014B4: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808014B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808014BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014C0: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808014C4: beq         $t6, $at, L_808014E0
    if (ctx->r14 == ctx->r1) {
        // 0x808014C8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808014E0;
    }
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808014CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808014D0: beq         $t6, $at, L_80801524
    if (ctx->r14 == ctx->r1) {
        // 0x808014D4: nop
    
            goto L_80801524;
    }
    // 0x808014D4: nop

    // 0x808014D8: b           L_80801530
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801530;
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808014E0:
    // 0x808014E0: jal         0x80100074
    // 0x808014E4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x808014E4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_1:
    // 0x808014E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014EC: jal         0x80100094
    // 0x808014F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808014F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808014F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808014F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808014FC: sb          $zero, 0x3C($v0)
    MEM_B(0X3C, ctx->r2) = 0;
    // 0x80801500: sb          $zero, 0x3D($v0)
    MEM_B(0X3D, ctx->r2) = 0;
    // 0x80801504: sb          $zero, 0x3E($v0)
    MEM_B(0X3E, ctx->r2) = 0;
    // 0x80801508: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080150C: jal         0x80090658
    // 0x80801510: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    func_80090658(rdram, ctx);
        goto after_3;
    // 0x80801510: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    after_3:
    // 0x80801514: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80801518: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8080151C: b           L_8080152C
    // 0x80801520: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_8080152C;
    // 0x80801520: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80801524:
    // 0x80801524: jal         0x800FDC28
    // 0x80801528: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_4;
    // 0x80801528: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
L_8080152C:
    // 0x8080152C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801530:
    // 0x80801530: jal         0x80102424
    // 0x80801534: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80801534: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80801538: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8080153C: sltiu       $at, $t0, 0x8
    ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x80801540: beq         $at, $zero, L_8080169C
    if (ctx->r1 == 0) {
        // 0x80801544: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8080169C;
    }
    // 0x80801544: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80801548: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F98) << 16);
    // 0x8080154C: addu        $at, $at, $t0
    gpr jr_addend_80801554 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80801550: lw          $t0, 0x1F98($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F98));
    // 0x80801554: jr          $t0
    // 0x80801558: nop

    switch (jr_addend_80801554 >> 2) {
        case 0: goto L_8080169C; break;
        case 1: goto L_80801574; break;
        case 2: goto L_808015A0; break;
        case 3: goto L_808015CC; break;
        case 4: goto L_80801620; break;
        case 5: goto L_80801644; break;
        case 6: goto L_80801654; break;
        case 7: goto L_8080155C; break;
        default: switch_error(__func__, 0x80801554, 0x80801F98);
    }
    // 0x80801558: nop

L_8080155C:
    // 0x8080155C: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x80801560: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80801564: jal         0x80101EE4
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_6;
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080156C: b           L_808016A0
    // 0x80801570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016A0;
    // 0x80801570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801574:
    // 0x80801574: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80801578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080157C: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x80801580: jal         0x80090658
    // 0x80801584: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    func_80090658(rdram, ctx);
        goto after_7;
    // 0x80801584: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    after_7:
    // 0x80801588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080158C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801590: jal         0x80100074
    // 0x80801594: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_8;
    // 0x80801594: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80801598: b           L_808016A0
    // 0x8080159C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016A0;
    // 0x8080159C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808015A0:
    // 0x808015A0: jal         0x808013E8
    // 0x808015A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808013E8_chlakemonster(rdram, ctx);
        goto after_9;
    // 0x808015A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808015A8: jal         0x800FDC28
    // 0x808015AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_10;
    // 0x808015AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x808015B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808015B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808015B8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808015BC: jal         0x80085708
    // 0x808015C0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    _capod_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x808015C0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_11:
    // 0x808015C4: b           L_808016A0
    // 0x808015C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016A0;
    // 0x808015C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808015CC:
    // 0x808015CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808015D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808015D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x808015D8: jal         0x80085708
    // 0x808015DC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x808015DC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_12:
    // 0x808015E0: jal         0x800F54E4
    // 0x808015E4: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x808015E4: nop

    after_13:
    // 0x808015E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808015EC: jal         0x800F7B9C
    // 0x808015F0: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    func_800F7B9C(rdram, ctx);
        goto after_14;
    // 0x808015F0: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    after_14:
    // 0x808015F4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x808015F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808015FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801600: jal         0x8009086C
    // 0x80801604: sb          $t3, 0x3D($t4)
    MEM_B(0X3D, ctx->r12) = ctx->r11;
    func_8009086C(rdram, ctx);
        goto after_15;
    // 0x80801604: sb          $t3, 0x3D($t4)
    MEM_B(0X3D, ctx->r12) = ctx->r11;
    after_15:
    // 0x80801608: jal         0x80090658
    // 0x8080160C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_16;
    // 0x8080160C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x80801610: jal         0x80090708
    // 0x80801614: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_17;
    // 0x80801614: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_17:
    // 0x80801618: b           L_808016A0
    // 0x8080161C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016A0;
    // 0x8080161C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801620:
    // 0x80801620: jal         0x808013E8
    // 0x80801624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808013E8_chlakemonster(rdram, ctx);
        goto after_18;
    // 0x80801624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80801628: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080162C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801630: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80801634: jal         0x80085708
    // 0x80801638: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    _capod_entrypoint_13(rdram, ctx);
        goto after_19;
    // 0x80801638: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_19:
    // 0x8080163C: b           L_808016A0
    // 0x80801640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016A0;
    // 0x80801640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801644:
    // 0x80801644: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80801648: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x8080164C: b           L_8080169C
    // 0x80801650: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
        goto L_8080169C;
    // 0x80801650: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
L_80801654:
    // 0x80801654: jal         0x80090658
    // 0x80801658: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_20;
    // 0x80801658: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x8080165C: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80801660: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80801664: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80801668: jal         0x800C6E38
    // 0x8080166C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_800C6E38(rdram, ctx);
        goto after_21;
    // 0x8080166C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_21:
    // 0x80801670: bne         $v0, $zero, L_80801690
    if (ctx->r2 != 0) {
        // 0x80801674: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801690;
    }
    // 0x80801674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080167C: addiu       $a1, $zero, 0x1819
    ctx->r5 = ADD32(0, 0X1819);
    // 0x80801680: jal         0x80801448
    // 0x80801684: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801448_chlakemonster(rdram, ctx);
        goto after_22;
    // 0x80801684: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x80801688: b           L_808016A0
    // 0x8080168C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016A0;
    // 0x8080168C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801690:
    // 0x80801690: addiu       $a1, $zero, 0x180E
    ctx->r5 = ADD32(0, 0X180E);
    // 0x80801694: jal         0x80801448
    // 0x80801698: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801448_chlakemonster(rdram, ctx);
        goto after_23;
    // 0x80801698: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
L_8080169C:
    // 0x8080169C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808016A0:
    // 0x808016A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808016A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808016A8: jr          $ra
    // 0x808016AC: nop

    return;
    // 0x808016AC: nop

;}
RECOMP_FUNC void func_808003F8_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808003FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800400: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800404: addiu       $t8, $t7, -0x7
    ctx->r24 = ADD32(ctx->r15, -0X7);
    // 0x80800408: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x8080040C: beq         $at, $zero, L_80800430
    if (ctx->r1 == 0) {
        // 0x80800410: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800430;
    }
    // 0x80800410: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800414: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X4FD0) << 16);
    // 0x80800418: addu        $at, $at, $t8
    gpr jr_addend_80800420 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080041C: lw          $t8, 0x4FD0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X4FD0));
    // 0x80800420: jr          $t8
    // 0x80800424: nop

    switch (jr_addend_80800420 >> 2) {
        case 0: goto L_80800428; break;
        case 1: goto L_80800428; break;
        case 2: goto L_80800428; break;
        case 3: goto L_80800428; break;
        case 4: goto L_80800428; break;
        case 5: goto L_80800428; break;
        case 6: goto L_80800428; break;
        default: switch_error(__func__, 0x80800420, 0x80804FD0);
    }
    // 0x80800424: nop

L_80800428:
    // 0x80800428: jr          $ra
    // 0x8080042C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8080042C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800430:
    // 0x80800430: jr          $ra
    // 0x80800434: nop

    return;
    // 0x80800434: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802180: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80802184: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802188: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080218C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80802190: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80802194: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80802198: lbu         $t1, 0x77($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X77);
    // 0x8080219C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808021A0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x808021A4: blezl       $t1, L_8080223C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x808021A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080223C;
    }
    goto skip_0;
    // 0x808021A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808021AC: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
L_808021B0:
    // 0x808021B0: lw          $t7, 0x4C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4C);
    // 0x808021B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808021B8: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808021BC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x808021C0: bgezl       $t9, L_80802230
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808021C4: addiu       $t0, $t0, 0x58
        ctx->r8 = ADD32(ctx->r8, 0X58);
            goto L_80802230;
    }
    goto skip_1;
    // 0x808021C4: addiu       $t0, $t0, 0x58
    ctx->r8 = ADD32(ctx->r8, 0X58);
    skip_1:
    // 0x808021C8: lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X40);
    // 0x808021CC: jal         0x800D674C
    // 0x808021D0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x808021D0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x808021D4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808021D8: jal         0x800B2720
    // 0x808021DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2720(rdram, ctx);
        goto after_1;
    // 0x808021DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808021E0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808021E4: jal         0x800B2840
    // 0x808021E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800B2840(rdram, ctx);
        goto after_2;
    // 0x808021E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x808021EC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x808021F0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x808021F4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808021F8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808021FC: lw          $t4, 0x68($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X68);
    // 0x80802200: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80802204: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802208: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x8080220C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80802210: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802214: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80802218: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8080221C: jal         0x800AD894
    // 0x80802220: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_800AD894(rdram, ctx);
        goto after_3;
    // 0x80802220: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80802224: b           L_80802240
    // 0x80802228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80802240;
    // 0x80802228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080222C: addiu       $t0, $t0, 0x58
    ctx->r8 = ADD32(ctx->r8, 0X58);
L_80802230:
    // 0x80802230: bne         $at, $zero, L_808021B0
    if (ctx->r1 != 0) {
        // 0x80802234: addiu       $v0, $v0, 0x58
        ctx->r2 = ADD32(ctx->r2, 0X58);
            goto L_808021B0;
    }
    // 0x80802234: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x80802238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080223C:
    // 0x8080223C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802240:
    // 0x80802240: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802244: jr          $ra
    // 0x80802248: nop

    return;
    // 0x80802248: nop

;}
RECOMP_FUNC void func_800A2F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A2F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2F98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A2F9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A2FA0: lw          $t7, 0x124($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X124);
    // 0x800A2FA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2FA8: jal         0x800889F0
    // 0x800A2FAC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _fxstep_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800A2FAC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x800A2FB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A2FB4: jal         0x800A2EEC
    // 0x800A2FB8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800A2EEC(rdram, ctx);
        goto after_1;
    // 0x800A2FB8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800A2FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A2FC4: jr          $ra
    // 0x800A2FC8: nop

    return;
    // 0x800A2FC8: nop

;}
RECOMP_FUNC void func_808003D8_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003E0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808003E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003EC: beq         $a1, $at, L_80800478
    if (ctx->r5 == ctx->r1) {
        // 0x808003F0: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80800478;
    }
    // 0x808003F0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808003F4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808003F8: beq         $a1, $at, L_80800580
    if (ctx->r5 == ctx->r1) {
        // 0x808003FC: addiu       $v0, $sp, 0x40
        ctx->r2 = ADD32(ctx->r29, 0X40);
            goto L_80800580;
    }
    // 0x808003FC: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80800400: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80800404: beq         $a1, $at, L_8080045C
    if (ctx->r5 == ctx->r1) {
        // 0x80800408: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080045C;
    }
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800410: beq         $a1, $at, L_80800444
    if (ctx->r5 == ctx->r1) {
        // 0x80800414: addiu       $v0, $sp, 0x40
        ctx->r2 = ADD32(ctx->r29, 0X40);
            goto L_80800444;
    }
    // 0x80800414: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80800418: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x8080041C: beq         $a1, $at, L_80800594
    if (ctx->r5 == ctx->r1) {
        // 0x80800420: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1096, 0X18D8) << 16);
            goto L_80800594;
    }
    // 0x80800420: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1096, 0X18D8) << 16);
    // 0x80800424: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80800428: beq         $a1, $at, L_808005A8
    if (ctx->r5 == ctx->r1) {
        // 0x8080042C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005A8;
    }
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800434: beq         $a1, $at, L_808005D0
    if (ctx->r5 == ctx->r1) {
        // 0x80800438: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D0;
    }
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: b           L_80800610
    // 0x80800440: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800610;
    // 0x80800440: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800444:
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8080044C: jal         0x8080077C
    // 0x80800450: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_8080077C_chnicecavemen(rdram, ctx);
        goto after_0;
    // 0x80800450: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x80800454: b           L_80800610
    // 0x80800458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800610;
    // 0x80800458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080045C:
    // 0x8080045C: jal         0x80100094
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800468: jal         0x8008A080
    // 0x8080046C: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    _subaddiepalette_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080046C: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    after_2:
    // 0x80800470: b           L_80800610
    // 0x80800474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800610;
    // 0x80800474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800478:
    // 0x80800478: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8080047C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800480: beq         $v0, $at, L_80800518
    if (ctx->r2 == ctx->r1) {
        // 0x80800484: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80800518;
    }
    // 0x80800484: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800488: beq         $v0, $at, L_808004A0
    if (ctx->r2 == ctx->r1) {
        // 0x8080048C: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_808004A0;
    }
    // 0x8080048C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800490: beq         $v0, $at, L_808004A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800494: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_808004A0;
    }
    // 0x80800494: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80800498: bne         $v0, $at, L_80800578
    if (ctx->r2 != ctx->r1) {
        // 0x8080049C: nop
    
            goto L_80800578;
    }
    // 0x8080049C: nop

L_808004A0:
    // 0x808004A0: jal         0x800F54E4
    // 0x808004A4: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808004A4: nop

    after_3:
    // 0x808004A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004AC: jal         0x800F7F98
    // 0x808004B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_4;
    // 0x808004B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808004B4: jal         0x80800C6C
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C6C_chnicecavemen(rdram, ctx);
        goto after_5;
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808004BC: bne         $v0, $zero, L_80800510
    if (ctx->r2 != 0) {
        // 0x808004C0: nop
    
            goto L_80800510;
    }
    // 0x808004C0: nop

    // 0x808004C4: jal         0x800DA298
    // 0x808004C8: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808004C8: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_6:
    // 0x808004CC: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x808004D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E0;
    }
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: addiu       $t6, $zero, 0x17D9
    ctx->r14 = ADD32(0, 0X17D9);
    // 0x808004D8: b           L_808004E8
    // 0x808004DC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
        goto L_808004E8;
    // 0x808004DC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_808004E0:
    // 0x808004E0: addiu       $t7, $zero, 0x17D4
    ctx->r15 = ADD32(0, 0X17D4);
    // 0x808004E4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_808004E8:
    // 0x808004E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808004EC: jal         0x80801464
    // 0x808004F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801464_chnicecavemen(rdram, ctx);
        goto after_7;
    // 0x808004F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x808004F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004F8: addiu       $t8, $zero, 0xA2
    ctx->r24 = ADD32(0, 0XA2);
    // 0x808004FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800500: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800504: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800508: jal         0x8008A208
    // 0x8080050C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x8080050C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_8:
L_80800510:
    // 0x80800510: b           L_80800610
    // 0x80800514: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800610;
    // 0x80800514: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800518:
    // 0x80800518: jal         0x800F54E4
    // 0x8080051C: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x8080051C: nop

    after_9:
    // 0x80800520: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800524: jal         0x800F64A4
    // 0x80800528: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800F64A4(rdram, ctx);
        goto after_10;
    // 0x80800528: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_10:
    // 0x8080052C: beq         $v0, $zero, L_80800540
    if (ctx->r2 == 0) {
        // 0x80800530: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800540;
    }
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: addiu       $t9, $zero, 0x1811
    ctx->r25 = ADD32(0, 0X1811);
    // 0x80800538: b           L_80800548
    // 0x8080053C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_80800548;
    // 0x8080053C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80800540:
    // 0x80800540: addiu       $t0, $zero, 0x17FD
    ctx->r8 = ADD32(0, 0X17FD);
    // 0x80800544: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80800548:
    // 0x80800548: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080054C: jal         0x80801464
    // 0x80800550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801464_chnicecavemen(rdram, ctx);
        goto after_11;
    // 0x80800550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80800554: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800558: addiu       $t1, $zero, 0xA2
    ctx->r9 = ADD32(0, 0XA2);
    // 0x8080055C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800560: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800564: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800568: jal         0x8008A208
    // 0x8080056C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x8080056C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x80800570: b           L_80800610
    // 0x80800574: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800610;
    // 0x80800574: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800578:
    // 0x80800578: b           L_80800610
    // 0x8080057C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800610;
    // 0x8080057C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800580:
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: jal         0x80800624
    // 0x80800588: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    func_80800624_chnicecavemen(rdram, ctx);
        goto after_13;
    // 0x80800588: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_13:
    // 0x8080058C: b           L_80800610
    // 0x80800590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800610;
    // 0x80800590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800594:
    // 0x80800594: addiu       $a0, $a0, 0x18D8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1096, 0X18D8));
    // 0x80800598: jal         0x80088090
    // 0x8080059C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x8080059C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_14:
    // 0x808005A0: b           L_80800610
    // 0x808005A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800610;
    // 0x808005A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005A8:
    // 0x808005A8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808005AC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808005B0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808005B4: andi        $t2, $a1, 0xFFFF
    ctx->r10 = ctx->r5 & 0XFFFF;
    // 0x808005B8: and         $t3, $a2, $at
    ctx->r11 = ctx->r6 & ctx->r1;
    // 0x808005BC: srl         $a2, $t3, 16
    ctx->r6 = S32(U32(ctx->r11) >> 16);
    // 0x808005C0: jal         0x808013D0
    // 0x808005C4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_808013D0_chnicecavemen(rdram, ctx);
        goto after_15;
    // 0x808005C4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_15:
    // 0x808005C8: b           L_80800614
    // 0x808005CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800614;
    // 0x808005CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005D0:
    // 0x808005D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005D4: jal         0x800897C0
    // 0x808005D8: addiu       $a2, $zero, 0xA2
    ctx->r6 = ADD32(0, 0XA2);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_16;
    // 0x808005D8: addiu       $a2, $zero, 0xA2
    ctx->r6 = ADD32(0, 0XA2);
    after_16:
    // 0x808005DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808005E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005E4: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x808005E8: jal         0x800897E8
    // 0x808005EC: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_17;
    // 0x808005EC: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_17:
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F4: jal         0x80089810
    // 0x808005F8: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_18;
    // 0x808005F8: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_18:
    // 0x808005FC: b           L_80800610
    // 0x80800600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800610;
    // 0x80800600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800604: b           L_80800610
    // 0x80800608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800610;
    // 0x80800608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080060C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800610:
    // 0x80800610: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800614:
    // 0x80800614: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800618: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080061C: jr          $ra
    // 0x80800620: nop

    return;
    // 0x80800620: nop

;}
RECOMP_FUNC void _chbilldrillplate_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086300: syscall     304
    recomp_syscall_handler(rdram, ctx, 0x80086300);
    return;
    // 0x80086304: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800BC8_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800BD4: jal         0x800D3948
    // 0x80800BD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80800BD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BDC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BE0: beq         $v0, $zero, L_80800C0C
    if (ctx->r2 == 0) {
        // 0x80800BE4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800C0C;
    }
    // 0x80800BE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BE8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800BEC: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80800BF0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1320, 0X1FF0) << 16);
    // 0x80800BF4: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80800BF8: lhu         $a1, 0x1FF0($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1320, 0X1FF0));
    // 0x80800BFC: jal         0x801032B0
    // 0x80800C00: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    func_801032B0(rdram, ctx);
        goto after_1;
    // 0x80800C00: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    after_1:
    // 0x80800C04: b           L_80800C2C
    // 0x80800C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C2C;
    // 0x80800C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C0C:
    // 0x80800C0C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80800C10: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x80800C14: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1320, 0X1FE8) << 16);
    // 0x80800C18: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80800C1C: lhu         $a1, 0x1FE8($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1320, 0X1FE8));
    // 0x80800C20: jal         0x801032B0
    // 0x80800C24: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_801032B0(rdram, ctx);
        goto after_2;
    // 0x80800C24: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_2:
    // 0x80800C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C2C:
    // 0x80800C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C30: jr          $ra
    // 0x80800C34: nop

    return;
    // 0x80800C34: nop

;}
RECOMP_FUNC void func_808003B4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808003C4: jal         0x8008D04C
    // 0x808003C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8008D04C(rdram, ctx);
        goto after_0;
    // 0x808003C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808003CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003D0: jal         0x8008AF24
    // 0x808003D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808003D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: jal         0x8008B1A0
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: jal         0x8008AED4
    // 0x808003EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x808003EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: jal         0x8008B1BC
    // 0x808003F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x808003F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800400: jal         0x8008B134
    // 0x80800404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800408: jal         0x8008B064
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800414: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080041C: jr          $ra
    // 0x80800420: nop

    return;
    // 0x80800420: nop

;}
RECOMP_FUNC void func_8009239C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009239C: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x800923A0: jr          $ra
    // 0x800923A4: lbu         $v0, 0x19($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X19);
    return;
    // 0x800923A4: lbu         $v0, 0x19($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X19);
;}
RECOMP_FUNC void func_8009BFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BFE4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BFE8: lw          $t6, 0xDC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XDC);
    // 0x8009BFEC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8009BFF0: swc1        $f12, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f12.u32l;
    // 0x8009BFF4: lw          $t7, 0xDC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XDC);
    // 0x8009BFF8: jr          $ra
    // 0x8009BFFC: swc1        $f14, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x8009BFFC: swc1        $f14, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80018BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018BB4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018BB8: lw          $v0, -0x4350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4350);
    // 0x80018BBC: jr          $ra
    // 0x80018BC0: addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    return;
    // 0x80018BC0: addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
;}
RECOMP_FUNC void chcredits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800268: addiu       $v0, $v0, 0x7610
    ctx->r2 = ADD32(ctx->r2, 0X7610);
    // 0x8080026C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80800270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800274: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800278: bne         $t6, $at, L_80800290
    if (ctx->r14 != ctx->r1) {
        // 0x8080027C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800290;
    }
    // 0x8080027C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800280: jal         0x8080003C
    // 0x80800284: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    func_8080003C_chcredits(rdram, ctx);
        goto after_0;
    // 0x80800284: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    after_0:
    // 0x80800288: b           L_80800298
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800298;
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800290:
    // 0x80800290: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800298:
    // 0x80800298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080029C: jr          $ra
    // 0x808002A0: nop

    return;
    // 0x808002A0: nop

;}
