#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800030_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800038: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1080, 0XB00) << 16);
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800040: jal         0x80086038
    // 0x80800044: addiu       $a1, $a1, 0xB00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1080, 0XB00));
    _chpowerhut_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a1, $a1, 0xB00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1080, 0XB00));
    after_0:
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: jal         0x80100094
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800054: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_800A5430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5430: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A5434: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A5438: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800A543C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800A5440: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A5444: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800A5448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A544C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800A5450: neg.s       $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = -ctx->f12.fl;
    // 0x800A5454: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x800A5458: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x800A545C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800A5460: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800A5464: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800A5468: jal         0x800EF4E4
    // 0x800A546C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_0;
    // 0x800A546C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800A5470: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800A5474: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800A5478: jal         0x800EE780
    // 0x800A547C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_800EE780(rdram, ctx);
        goto after_1;
    // 0x800A547C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x800A5480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5484: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A5488: jr          $ra
    // 0x800A548C: nop

    return;
    // 0x800A548C: nop

;}
RECOMP_FUNC void func_800EC360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC360: jr          $ra
    // 0x800EC364: sh          $a1, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r5;
    return;
    // 0x800EC364: sh          $a1, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80800000_chlighthalo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lbu         $a2, 0x34($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X34);
    // 0x8080000C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800010: beq         $a2, $zero, L_80800020
    if (ctx->r6 == 0) {
        // 0x80800014: andi        $a0, $a2, 0xFF
        ctx->r4 = ctx->r6 & 0XFF;
            goto L_80800020;
    }
    // 0x80800014: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80800018: jal         0x800E8830
    // 0x8080001C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    func_800E8830(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    after_0:
L_80800020:
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_800E3EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3EFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E3F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3F04: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800E3F08: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x800E3F0C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800E3F10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3F14: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3F18: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800E3F1C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3F20: jal         0x800CAD9C
    // 0x800E3F24: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800CAD9C(rdram, ctx);
        goto after_0;
    // 0x800E3F24: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x800E3F28: jal         0x800BCC58
    // 0x800E3F2C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800BCC58(rdram, ctx);
        goto after_1;
    // 0x800E3F2C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E3F30: beq         $v0, $zero, L_800E3F78
    if (ctx->r2 == 0) {
        // 0x800E3F34: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_800E3F78;
    }
    // 0x800E3F34: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800E3F38: bne         $v1, $zero, L_800E3F78
    if (ctx->r3 != 0) {
        // 0x800E3F3C: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_800E3F78;
    }
    // 0x800E3F3C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800E3F40: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800E3F44: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3F48: jal         0x800EFA4C
    // 0x800E3F4C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x800E3F4C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800E3F50: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800E3F54: jal         0x800BCC28
    // 0x800E3F58: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800BCC28(rdram, ctx);
        goto after_3;
    // 0x800E3F58: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x800E3F5C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3F60: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3F64: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800E3F68: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800E3F6C: jal         0x800CAD9C
    // 0x800E3F70: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800CAD9C(rdram, ctx);
        goto after_4;
    // 0x800E3F70: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x800E3F74: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800E3F78:
    // 0x800E3F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3F7C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800E3F80: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800E3F84: jr          $ra
    // 0x800E3F88: nop

    return;
    // 0x800E3F88: nop

;}
RECOMP_FUNC void func_8008D9A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D9A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D9A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D9AC: jal         0x800A4CA8
    // 0x8008D9B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x8008D9B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008D9B4: jal         0x80089418
    // 0x8008D9B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncba1p_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x8008D9B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008D9BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008D9C0: bne         $v0, $at, L_8008D9D0
    if (ctx->r2 != ctx->r1) {
        // 0x8008D9C4: nop
    
            goto L_8008D9D0;
    }
    // 0x8008D9C4: nop

    // 0x8008D9C8: b           L_8008DA14
    // 0x8008D9CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008DA14;
    // 0x8008D9CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D9D0:
    // 0x8008D9D0: jal         0x800A4D40
    // 0x8008D9D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4D40(rdram, ctx);
        goto after_2;
    // 0x8008D9D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8008D9D8: bne         $v0, $zero, L_8008D9E8
    if (ctx->r2 != 0) {
        // 0x8008D9DC: nop
    
            goto L_8008D9E8;
    }
    // 0x8008D9DC: nop

    // 0x8008D9E0: b           L_8008DA14
    // 0x8008D9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008DA14;
    // 0x8008D9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D9E8:
    // 0x8008D9E8: jal         0x8008E078
    // 0x8008D9EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x8008D9EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8008D9F0: bnel        $v0, $zero, L_8008DA14
    if (ctx->r2 != 0) {
        // 0x8008D9F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008DA14;
    }
    goto skip_0;
    // 0x8008D9F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8008D9F8: jal         0x8008E35C
    // 0x8008D9FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    player_inWater(rdram, ctx);
        goto after_4;
    // 0x8008D9FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x8008DA00: bnel        $v0, $zero, L_8008DA14
    if (ctx->r2 != 0) {
        // 0x8008DA04: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008DA14;
    }
    goto skip_1;
    // 0x8008DA04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8008DA08: b           L_8008DA14
    // 0x8008DA0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008DA14;
    // 0x8008DA0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008DA10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DA14:
    // 0x8008DA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DA18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DA1C: jr          $ra
    // 0x8008DA20: nop

    return;
    // 0x8008DA20: nop

;}
RECOMP_FUNC void _chboilerid_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860B0: syscall     276
    recomp_syscall_handler(rdram, ctx, 0x800860B0);
    return;
    // 0x800860B4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800D0CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0CC8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D0CCC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800D0CD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D0CD4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D0CD8: jr          $ra
    // 0x800D0CDC: lbu         $v0, -0x54C2($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X54C2);
    return;
    // 0x800D0CDC: lbu         $v0, -0x54C2($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X54C2);
;}
RECOMP_FUNC void func_80802ED8_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802ED8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802EDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802EE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802EE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802EE8: jal         0x80100094
    // 0x80802EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802EF0: jal         0x800EA05C
    // 0x80802EF4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80802EF4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802EF8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80802EFC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80802F00: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    // 0x80802F04: sb          $t6, 0x2D($t7)
    MEM_B(0X2D, ctx->r15) = ctx->r14;
    // 0x80802F08: jal         0x800D211C
    // 0x80802F0C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800D211C(rdram, ctx);
        goto after_2;
    // 0x80802F0C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80802F10: slti        $at, $v0, 0x226
    ctx->r1 = SIGNED(ctx->r2) < 0X226 ? 1 : 0;
    // 0x80802F14: beq         $at, $zero, L_80802F34
    if (ctx->r1 == 0) {
        // 0x80802F18: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80802F34;
    }
    // 0x80802F18: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80802F1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802F20: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    // 0x80802F24: addiu       $a2, $zero, 0x226
    ctx->r6 = ADD32(0, 0X226);
    // 0x80802F28: jal         0x800D2054
    // 0x80802F2C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800D2054(rdram, ctx);
        goto after_3;
    // 0x80802F2C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x80802F30: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_80802F34:
    // 0x80802F34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80802F38: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802F3C: lui         $a2, 0x42DC
    ctx->r6 = S32(0X42DC << 16);
    // 0x80802F40: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802F44: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80802F48: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80802F4C: jal         0x800EFA4C
    // 0x80802F50: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80802F50: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_4:
    // 0x80802F54: jal         0x80800000
    // 0x80802F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chflysaucer(rdram, ctx);
        goto after_5;
    // 0x80802F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802F5C: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x80802F60: beq         $at, $zero, L_8080313C
    if (ctx->r1 == 0) {
        // 0x80802F64: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_8080313C;
    }
    // 0x80802F64: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80802F68: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80802F6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4214) << 16);
    // 0x80802F70: addu        $at, $at, $t8
    gpr jr_addend_80802F78 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80802F74: lw          $t8, 0x4214($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4214));
    // 0x80802F78: jr          $t8
    // 0x80802F7C: nop

    switch (jr_addend_80802F78 >> 2) {
        case 0: goto L_80802F80; break;
        case 1: goto L_80803104; break;
        case 2: goto L_80803054; break;
        case 3: goto L_80803080; break;
        case 4: goto L_808030AC; break;
        case 5: goto L_808030D8; break;
        case 6: goto L_80803020; break;
        default: switch_error(__func__, 0x80802F78, 0x80804214);
    }
    // 0x80802F7C: nop

L_80802F80:
    // 0x80802F80: jal         0x80088848
    // 0x80802F84: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x80802F84: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_6:
    // 0x80802F88: beq         $v0, $zero, L_80802FA4
    if (ctx->r2 == 0) {
        // 0x80802F8C: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80802FA4;
    }
    // 0x80802F8C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80802F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802F94: jal         0x80801568
    // 0x80802F98: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80801568_chflysaucer(rdram, ctx);
        goto after_7;
    // 0x80802F98: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_7:
    // 0x80802F9C: b           L_80803140
    // 0x80802FA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x80802FA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802FA4:
    // 0x80802FA4: jal         0x800D395C
    // 0x80802FA8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800D395C(rdram, ctx);
        goto after_8;
    // 0x80802FA8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_8:
    // 0x80802FAC: beq         $v0, $zero, L_80802FE4
    if (ctx->r2 == 0) {
        // 0x80802FB0: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80802FE4;
    }
    // 0x80802FB0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80802FB4: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x80802FB8: bnel        $v1, $at, L_80802FE8
    if (ctx->r3 != ctx->r1) {
        // 0x80802FBC: addiu       $at, $zero, 0xD6
        ctx->r1 = ADD32(0, 0XD6);
            goto L_80802FE8;
    }
    goto skip_0;
    // 0x80802FBC: addiu       $at, $zero, 0xD6
    ctx->r1 = ADD32(0, 0XD6);
    skip_0:
    // 0x80802FC0: jal         0x80801034
    // 0x80802FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801034_chflysaucer(rdram, ctx);
        goto after_9;
    // 0x80802FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80802FC8: jal         0x808005FC
    // 0x80802FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005FC_chflysaucer(rdram, ctx);
        goto after_10;
    // 0x80802FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80802FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802FD4: jal         0x80801568
    // 0x80802FD8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801568_chflysaucer(rdram, ctx);
        goto after_11;
    // 0x80802FD8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80802FDC: b           L_80803140
    // 0x80802FE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x80802FE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802FE4:
    // 0x80802FE4: addiu       $at, $zero, 0xD6
    ctx->r1 = ADD32(0, 0XD6);
L_80802FE8:
    // 0x80802FE8: bne         $v1, $at, L_80803010
    if (ctx->r3 != ctx->r1) {
        // 0x80802FEC: nop
    
            goto L_80803010;
    }
    // 0x80802FEC: nop

    // 0x80802FF0: jal         0x800DA298
    // 0x80802FF4: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_800DA298(rdram, ctx);
        goto after_12;
    // 0x80802FF4: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_12:
    // 0x80802FF8: beq         $v0, $zero, L_80803010
    if (ctx->r2 == 0) {
        // 0x80802FFC: nop
    
            goto L_80803010;
    }
    // 0x80802FFC: nop

    // 0x80803000: jal         0x80801034
    // 0x80803004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801034_chflysaucer(rdram, ctx);
        goto after_13;
    // 0x80803004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80803008: b           L_80803140
    // 0x8080300C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x8080300C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803010:
    // 0x80803010: jal         0x800FFAB0
    // 0x80803014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x80803014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80803018: b           L_80803140
    // 0x8080301C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x8080301C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803020:
    // 0x80803020: addiu       $at, $zero, 0xD6
    ctx->r1 = ADD32(0, 0XD6);
    // 0x80803024: bne         $v1, $at, L_80803044
    if (ctx->r3 != ctx->r1) {
        // 0x80803028: nop
    
            goto L_80803044;
    }
    // 0x80803028: nop

    // 0x8080302C: jal         0x80801034
    // 0x80803030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801034_chflysaucer(rdram, ctx);
        goto after_15;
    // 0x80803030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80803034: jal         0x80801130
    // 0x80803038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801130_chflysaucer(rdram, ctx);
        goto after_16;
    // 0x80803038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080303C: b           L_80803140
    // 0x80803040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x80803040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803044:
    // 0x80803044: jal         0x800FFAB0
    // 0x80803048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_17;
    // 0x80803048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080304C: b           L_80803140
    // 0x80803050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x80803050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803054:
    // 0x80803054: addiu       $at, $zero, 0x13C
    ctx->r1 = ADD32(0, 0X13C);
    // 0x80803058: bne         $v1, $at, L_80803070
    if (ctx->r3 != ctx->r1) {
        // 0x8080305C: nop
    
            goto L_80803070;
    }
    // 0x8080305C: nop

    // 0x80803060: jal         0x808017D0
    // 0x80803064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chflysaucer(rdram, ctx);
        goto after_18;
    // 0x80803064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80803068: b           L_80803140
    // 0x8080306C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x8080306C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803070:
    // 0x80803070: jal         0x800FFAB0
    // 0x80803074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_19;
    // 0x80803074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80803078: b           L_80803140
    // 0x8080307C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x8080307C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803080:
    // 0x80803080: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x80803084: bne         $v1, $at, L_8080309C
    if (ctx->r3 != ctx->r1) {
        // 0x80803088: nop
    
            goto L_8080309C;
    }
    // 0x80803088: nop

    // 0x8080308C: jal         0x808017D0
    // 0x80803090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chflysaucer(rdram, ctx);
        goto after_20;
    // 0x80803090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80803094: b           L_80803140
    // 0x80803098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x80803098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080309C:
    // 0x8080309C: jal         0x800FFAB0
    // 0x808030A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_21;
    // 0x808030A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808030A4: b           L_80803140
    // 0x808030A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x808030A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808030AC:
    // 0x808030AC: addiu       $at, $zero, 0x13B
    ctx->r1 = ADD32(0, 0X13B);
    // 0x808030B0: bne         $v1, $at, L_808030C8
    if (ctx->r3 != ctx->r1) {
        // 0x808030B4: nop
    
            goto L_808030C8;
    }
    // 0x808030B4: nop

    // 0x808030B8: jal         0x808017D0
    // 0x808030BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chflysaucer(rdram, ctx);
        goto after_22;
    // 0x808030BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808030C0: b           L_80803140
    // 0x808030C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x808030C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808030C8:
    // 0x808030C8: jal         0x800FFAB0
    // 0x808030CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_23;
    // 0x808030CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808030D0: b           L_80803140
    // 0x808030D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x808030D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808030D8:
    // 0x808030D8: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x808030DC: bne         $v1, $at, L_808030F4
    if (ctx->r3 != ctx->r1) {
        // 0x808030E0: nop
    
            goto L_808030F4;
    }
    // 0x808030E0: nop

    // 0x808030E4: jal         0x808017D0
    // 0x808030E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chflysaucer(rdram, ctx);
        goto after_24;
    // 0x808030E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808030EC: b           L_80803140
    // 0x808030F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x808030F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808030F4:
    // 0x808030F4: jal         0x800FFAB0
    // 0x808030F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_25;
    // 0x808030F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808030FC: b           L_80803140
    // 0x80803100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803140;
    // 0x80803100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803104:
    // 0x80803104: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x80803108: bne         $v1, $at, L_8080313C
    if (ctx->r3 != ctx->r1) {
        // 0x8080310C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1692, 0X4230) << 16);
            goto L_8080313C;
    }
    // 0x8080310C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4230) << 16);
    // 0x80803110: jal         0x800DC298
    // 0x80803114: lwc1        $f12, 0x4230($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4230));
    func_800DC298(rdram, ctx);
        goto after_26;
    // 0x80803114: lwc1        $f12, 0x4230($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4230));
    after_26:
    // 0x80803118: beq         $v0, $zero, L_80803128
    if (ctx->r2 == 0) {
        // 0x8080311C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80803128;
    }
    // 0x8080311C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803120: b           L_80803128
    // 0x80803124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80803128;
    // 0x80803124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80803128:
    // 0x80803128: jal         0x800DA3B8
    // 0x8080312C: addiu       $a0, $zero, 0x6E9
    ctx->r4 = ADD32(0, 0X6E9);
    func_800DA3B8(rdram, ctx);
        goto after_27;
    // 0x8080312C: addiu       $a0, $zero, 0x6E9
    ctx->r4 = ADD32(0, 0X6E9);
    after_27:
    // 0x80803130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803134: jal         0x80801568
    // 0x80803138: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801568_chflysaucer(rdram, ctx);
        goto after_28;
    // 0x80803138: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_28:
L_8080313C:
    // 0x8080313C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803140:
    // 0x80803140: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803144: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803148: jr          $ra
    // 0x8080314C: nop

    return;
    // 0x8080314C: nop

;}
RECOMP_FUNC void func_800A16F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A16F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A16F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A16FC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x800A1700: jal         0x80085338
    // 0x800A1704: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    _batimer_set(rdram, ctx);
        goto after_0;
    // 0x800A1704: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_0:
    // 0x800A1708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A170C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1710: jr          $ra
    // 0x800A1714: nop

    return;
    // 0x800A1714: nop

;}
RECOMP_FUNC void _subaddiejoy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BB8: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BB8);
    return;
    // 0x80089BBC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void idtwinklecolour_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800010: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800014: lh          $t7, 0x20($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X20);
    // 0x80800018: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8080001C: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x80800020: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800024: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800028: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8080002C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800030: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800034: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
    // 0x80800038: mflo        $t8
    ctx->r24 = lo;
    // 0x8080003C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80800040: lbu         $t1, 0xD($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0XD);
    // 0x80800044: beql        $t1, $zero, L_80800200
    if (ctx->r9 == 0) {
        // 0x80800048: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800200;
    }
    goto skip_0;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8080004C:
    // 0x8080004C: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x80800050: lh          $t3, 0xE($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XE);
    // 0x80800054: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800058: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8080005C: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80800060: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800064: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800068: bne         $at, $zero, L_8080004C
    if (ctx->r1 != 0) {
        // 0x8080006C: sw          $t4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r12;
            goto L_8080004C;
    }
    // 0x8080006C: sw          $t4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r12;
    // 0x80800070: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80800074: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800078: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8080007C: multu       $t5, $t5
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800080: lw          $t3, 0x14($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X14);
    // 0x80800084: mflo        $t7
    ctx->r15 = lo;
    // 0x80800088: nop

    // 0x8080008C: nop

    // 0x80800090: multu       $t6, $t6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800094: mflo        $t8
    ctx->r24 = lo;
    // 0x80800098: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8080009C: nop

    // 0x808000A0: multu       $t1, $t1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000A4: mflo        $t2
    ctx->r10 = lo;
    // 0x808000A8: addu        $v0, $t9, $t2
    ctx->r2 = ADD32(ctx->r25, ctx->r10);
    // 0x808000AC: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808000B0: bnel        $at, $zero, L_80800200
    if (ctx->r1 != 0) {
        // 0x808000B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800200;
    }
    goto skip_1;
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808000B8: lh          $a0, 0x22($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X22);
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C0: blezl       $a0, L_80800110
    if (SIGNED(ctx->r4) <= 0) {
        // 0x808000C4: lh          $t2, 0x20($a3)
        ctx->r10 = MEM_H(ctx->r7, 0X20);
            goto L_80800110;
    }
    goto skip_2;
    // 0x808000C4: lh          $t2, 0x20($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X20);
    skip_2:
    // 0x808000C8: lw          $v0, 0x24($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X24);
    // 0x808000CC: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
L_808000D0:
    // 0x808000D0: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x808000D4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x808000D8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x808000DC: bne         $t4, $v1, L_80800104
    if (ctx->r12 != ctx->r3) {
        // 0x808000E0: nop
    
            goto L_80800104;
    }
    // 0x808000E0: nop

    // 0x808000E4: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x808000E8: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
    // 0x808000EC: bne         $t5, $t6, L_80800104
    if (ctx->r13 != ctx->r14) {
        // 0x808000F0: nop
    
            goto L_80800104;
    }
    // 0x808000F0: nop

    // 0x808000F4: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x808000F8: lh          $t8, 0x4($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X4);
    // 0x808000FC: beql        $t7, $t8, L_80800200
    if (ctx->r15 == ctx->r24) {
        // 0x80800100: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800200;
    }
    goto skip_3;
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_80800104:
    // 0x80800104: bne         $at, $zero, L_808000D0
    if (ctx->r1 != 0) {
        // 0x80800108: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_808000D0;
    }
    // 0x80800108: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x8080010C: lh          $t2, 0x20($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X20);
L_80800110:
    // 0x80800110: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x80800114: lh          $t1, 0x0($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X0);
    // 0x80800118: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080011C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800120: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800128: mflo        $t3
    ctx->r11 = lo;
    // 0x8080012C: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80800130: sh          $t1, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r9;
    // 0x80800134: lh          $t7, 0x20($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X20);
    // 0x80800138: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x8080013C: lh          $t5, 0x2($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X2);
    // 0x80800140: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800144: mflo        $t8
    ctx->r24 = lo;
    // 0x80800148: addu        $t2, $t6, $t8
    ctx->r10 = ADD32(ctx->r14, ctx->r24);
    // 0x8080014C: sh          $t5, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r13;
    // 0x80800150: lh          $t1, 0x20($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X20);
    // 0x80800154: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
    // 0x80800158: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x8080015C: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800160: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80800164: mflo        $t4
    ctx->r12 = lo;
    // 0x80800168: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x8080016C: sh          $t9, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r25;
    // 0x80800170: lh          $t8, 0x20($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X20);
    // 0x80800174: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x80800178: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080017C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800180: mflo        $t5
    ctx->r13 = lo;
    // 0x80800184: addu        $t2, $t6, $t5
    ctx->r10 = ADD32(ctx->r14, ctx->r13);
    // 0x80800188: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x8080018C: lh          $t4, 0x20($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X20);
    // 0x80800190: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
    // 0x80800194: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800198: mflo        $t9
    ctx->r25 = lo;
    // 0x8080019C: addu        $t7, $t3, $t9
    ctx->r15 = ADD32(ctx->r11, ctx->r25);
    // 0x808001A0: sb          $t1, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r9;
    // 0x808001A4: lh          $t5, 0x20($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X20);
    // 0x808001A8: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x808001AC: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001B0: mflo        $t2
    ctx->r10 = lo;
    // 0x808001B4: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x808001B8: sb          $t8, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r24;
    // 0x808001BC: lh          $t9, 0x20($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X20);
    // 0x808001C0: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
    // 0x808001C4: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001C8: mflo        $t1
    ctx->r9 = lo;
    // 0x808001CC: addu        $t7, $t3, $t1
    ctx->r15 = ADD32(ctx->r11, ctx->r9);
    // 0x808001D0: sb          $zero, 0xD($t7)
    MEM_B(0XD, ctx->r15) = 0;
    // 0x808001D4: jal         0x800DC214
    // 0x808001D8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800DC214(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x808001DC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x808001E0: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x808001E4: lh          $t6, 0x20($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X20);
    // 0x808001E8: lw          $t5, 0x24($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X24);
    // 0x808001EC: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001F0: mflo        $t2
    ctx->r10 = lo;
    // 0x808001F4: addu        $t8, $t5, $t2
    ctx->r24 = ADD32(ctx->r13, ctx->r10);
    // 0x808001F8: sb          $v0, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r2;
    // 0x808001FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800200:
    // 0x80800200: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void plcamera_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D8: jal         0x800F5EF8
    // 0x808002DC: nop

    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x808002DC: nop

    after_0:
    // 0x808002E0: jal         0x80110014
    // 0x808002E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x808002E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808002E8: jal         0x801106A0
    // 0x808002EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_801106A0(rdram, ctx);
        goto after_2;
    // 0x808002EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808002F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002F8: jr          $ra
    // 0x808002FC: nop

    return;
    // 0x808002FC: nop

;}
RECOMP_FUNC void _chtiptup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F10: syscall     260
    recomp_syscall_handler(rdram, ctx, 0x80085F10);
    return;
    // 0x80085F14: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80803954_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080395C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80803960: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80803964: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803968: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080396C: beq         $t6, $at, L_80803988
    if (ctx->r14 == ctx->r1) {
        // 0x80803970: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80803988;
    }
    // 0x80803970: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80803974: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803978: beq         $t6, $at, L_80803998
    if (ctx->r14 == ctx->r1) {
        // 0x8080397C: addiu       $a0, $a2, 0x58
        ctx->r4 = ADD32(ctx->r6, 0X58);
            goto L_80803998;
    }
    // 0x8080397C: addiu       $a0, $a2, 0x58
    ctx->r4 = ADD32(ctx->r6, 0X58);
    // 0x80803980: b           L_808039C8
    // 0x80803984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808039C8;
    // 0x80803984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803988:
    // 0x80803988: jal         0x80103110
    // 0x8080398C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x8080398C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803990: b           L_808039C8
    // 0x80803994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808039C8;
    // 0x80803994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803998:
    // 0x80803998: jal         0x800D90A4
    // 0x8080399C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x8080399C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808039A0: beq         $v0, $zero, L_808039C4
    if (ctx->r2 == 0) {
        // 0x808039A4: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_808039C4;
    }
    // 0x808039A4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808039A8: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x808039AC: jal         0x800C8B84
    // 0x808039B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C8B84(rdram, ctx);
        goto after_2;
    // 0x808039B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x808039B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808039B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808039BC: jal         0x80101FDC
    // 0x808039C0: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808039C0: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    after_3:
L_808039C4:
    // 0x808039C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808039C8:
    // 0x808039C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808039CC: jr          $ra
    // 0x808039D0: nop

    return;
    // 0x808039D0: nop

;}
RECOMP_FUNC void chtoxicroomprops_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800958: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2492, 0XA84) << 16);
    // 0x8080095C: jr          $ra
    // 0x80800960: addiu       $v0, $v0, 0xA84
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2492, 0XA84));
    return;
    // 0x80800960: addiu       $v0, $v0, 0xA84
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2492, 0XA84));
    // 0x80800964: nop

    // 0x80800968: nop

    // 0x8080096C: nop

;}
RECOMP_FUNC void func_80800108_chfactorylobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080010C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800114: bne         $a1, $at, L_80800140
    if (ctx->r5 != ctx->r1) {
        // 0x80800118: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800140;
    }
    // 0x80800118: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080011C: lh          $t6, 0x20($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X20);
    // 0x80800120: addiu       $at, $zero, 0x1370
    ctx->r1 = ADD32(0, 0X1370);
    // 0x80800124: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800128: bne         $t6, $at, L_80800138
    if (ctx->r14 != ctx->r1) {
        // 0x8080012C: nop
    
            goto L_80800138;
    }
    // 0x8080012C: nop

    // 0x80800130: jal         0x8010108C
    // 0x80800134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_0;
    // 0x80800134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_80800138:
    // 0x80800138: b           L_80800148
    // 0x8080013C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800148;
    // 0x8080013C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800140:
    // 0x80800140: jal         0x80086248
    // 0x80800144: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800144: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80800148:
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080014C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

    // 0x80800158: nop

    // 0x8080015C: nop

;}
RECOMP_FUNC void ncpodfixpos_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
    // 0x80800190: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x80800194: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80800198: jr          $ra
    // 0x8080019C: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    return;
    // 0x8080019C: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_808007F4_sudeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808007F8: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x808007FC: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x80800800: lw          $s5, 0x1020($s5)
    ctx->r21 = MEM_W(ctx->r21, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x80800804: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800808: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8080080C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800810: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x80800814: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80800818: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x8080081C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80800820: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80800824: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800828: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8080082C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800830: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x80800834: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80800838: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x8080083C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800840: beq         $a1, $zero, L_80800908
    if (ctx->r5 == 0) {
        // 0x80800844: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800908;
    }
    // 0x80800844: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800848: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x8080084C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800850: nop

L_80800854:
    // 0x80800854: jal         0x800E9E88
    // 0x80800858: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x80800858: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080085C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800860: jal         0x800E9EB4
    // 0x80800864: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_1;
    // 0x80800864: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_1:
    // 0x80800868: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8080086C: beq         $at, $zero, L_808008F8
    if (ctx->r1 == 0) {
        // 0x80800870: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_808008F8;
    }
    // 0x80800870: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800874: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
L_80800878:
    // 0x80800878: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8080087C: beql        $t7, $zero, L_808008EC
    if (ctx->r15 == 0) {
        // 0x80800880: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_808008EC;
    }
    goto skip_0;
    // 0x80800880: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_0:
    // 0x80800884: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80800888: jal         0x8008A340
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmisc_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800890: beql        $v0, $zero, L_808008EC
    if (ctx->r2 == 0) {
        // 0x80800894: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_808008EC;
    }
    goto skip_1;
    // 0x80800894: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x80800898: jal         0x80106790
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008A0: lw          $t8, 0x64($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X64);
    // 0x808008A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808008A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808008AC: sll         $t0, $t8, 14
    ctx->r8 = S32(ctx->r24 << 14);
    // 0x808008B0: bltz        $t0, L_808008E8
    if (SIGNED(ctx->r8) < 0) {
        // 0x808008B4: addiu       $t1, $v0, 0x4
        ctx->r9 = ADD32(ctx->r2, 0X4);
            goto L_808008E8;
    }
    // 0x808008B4: addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // 0x808008B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808008BC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808008C0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808008C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808008C8: jal         0x80800E44
    // 0x808008CC: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    func_80800E44_sudeflect(rdram, ctx);
        goto after_4;
    // 0x808008CC: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    after_4:
    // 0x808008D0: beq         $v0, $zero, L_808008E8
    if (ctx->r2 == 0) {
        // 0x808008D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008E8;
    }
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808008DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808008E0: jal         0x8010108C
    // 0x808008E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_5;
    // 0x808008E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_808008E8:
    // 0x808008E8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_808008EC:
    // 0x808008EC: sltu        $at, $s1, $s3
    ctx->r1 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x808008F0: bnel        $at, $zero, L_80800878
    if (ctx->r1 != 0) {
        // 0x808008F4: lw          $t6, 0x8($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X8);
            goto L_80800878;
    }
    goto skip_2;
    // 0x808008F4: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    skip_2:
L_808008F8:
    // 0x808008F8: lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X4);
    // 0x808008FC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80800900: bne         $a1, $zero, L_80800854
    if (ctx->r5 != 0) {
        // 0x80800904: nop
    
            goto L_80800854;
    }
    // 0x80800904: nop

L_80800908:
    // 0x80800908: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8080090C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80800910: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80800914: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800918: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080091C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800920: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800924: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80800928: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x8080092C: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80800930: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x80800934: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x80800938: jr          $ra
    // 0x8080093C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080093C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800D3EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3EF4: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3EF8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D3EFC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D3F00: lhu         $v0, -0x4A48($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4A48);
    // 0x800D3F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3F0C: beql        $v0, $zero, L_800D3F20
    if (ctx->r2 == 0) {
        // 0x800D3F10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3F20;
    }
    goto skip_0;
    // 0x800D3F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3F14: jal         0x800DA544
    // 0x800D3F18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x800D3F18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x800D3F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3F20:
    // 0x800D3F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3F24: jr          $ra
    // 0x800D3F28: nop

    return;
    // 0x800D3F28: nop

;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880A8: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x800880A8);
    return;
    // 0x800880AC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void anseq_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080044C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800450: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80800454: jal         0x8001B798
    // 0x80800458: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80800458: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void func_808003E4_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2132, 0X4B8) << 16);
    // 0x808003E8: b           L_80800428
    // 0x808003EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800428;
    // 0x808003EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808003F4: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x808003F8: jal         0x80800264
    // 0x808003FC: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800264_chfaircoinbox(rdram, ctx);
        goto after_0;
    // 0x808003FC: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x80800400: b           L_80800428
    // 0x80800404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800428;
    // 0x80800404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800408: addiu       $a0, $a0, 0x4B8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2132, 0X4B8));
    // 0x8080040C: jal         0x80088090
    // 0x80800410: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800410: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_1:
    // 0x80800414: b           L_80800428
    // 0x80800418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800428;
    // 0x80800418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080041C: b           L_80800428
    // 0x80800420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800428;
    // 0x80800420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800428:
    // 0x80800428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080042C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800430: jr          $ra
    // 0x80800434: nop

    return;
    // 0x80800434: nop

;}
RECOMP_FUNC void func_808069C8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808069C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808069CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808069D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808069D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808069D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808069DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808069E0: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x808069E4: addiu       $s2, $a0, 0x1
    ctx->r18 = ADD32(ctx->r4, 0X1);
    // 0x808069E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_808069EC:
    // 0x808069EC: sllv        $t7, $t6, $s0
    ctx->r15 = S32(ctx->r14 << (ctx->r16 & 31));
    // 0x808069F0: and         $t8, $t7, $s2
    ctx->r24 = ctx->r15 & ctx->r18;
    // 0x808069F4: beq         $t8, $zero, L_80806A04
    if (ctx->r24 == 0) {
        // 0x808069F8: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80806A04;
    }
    // 0x808069F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808069FC: b           L_80806A04
    // 0x80806A00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
        goto L_80806A04;
    // 0x80806A00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
L_80806A04:
    // 0x80806A04: jal         0x80088340
    // 0x80806A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80806A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80806A0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80806A10: bnel        $s0, $s1, L_808069EC
    if (ctx->r16 != ctx->r17) {
        // 0x80806A14: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808069EC;
    }
    goto skip_0;
    // 0x80806A14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x80806A18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80806A1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80806A20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80806A24: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80806A28: jr          $ra
    // 0x80806A2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80806A2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ncbasub_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800F7620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7620: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800F7624: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800F7628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F762C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F7630: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F7634: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F763C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F7640: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800F7644: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800F7648: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800F764C: jal         0x80085490
    // 0x800F7650: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800F7650: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F7654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F765C: jr          $ra
    // 0x800F7660: nop

    return;
    // 0x800F7660: nop

;}
RECOMP_FUNC void func_800C13C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C13C4: lhu         $t6, 0x7C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X7C);
    // 0x800C13C8: jr          $ra
    // 0x800C13CC: and         $v0, $t6, $a1
    ctx->r2 = ctx->r14 & ctx->r5;
    return;
    // 0x800C13CC: and         $v0, $t6, $a1
    ctx->r2 = ctx->r14 & ctx->r5;
;}
RECOMP_FUNC void chfactorymaindoor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080048C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2320, 0X564) << 16);
    // 0x80800490: jr          $ra
    // 0x80800494: addiu       $v0, $v0, 0x564
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2320, 0X564));
    return;
    // 0x80800494: addiu       $v0, $v0, 0x564
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2320, 0X564));
    // 0x80800498: nop

    // 0x8080049C: nop

;}
RECOMP_FUNC void ovl_reset_syscalls(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082428: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008242C: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80082430: lhu         $t0, 0x2C($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X2C);
    // 0x80082434: lhu         $t2, 0x2E($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X2E);
    // 0x80082438: sll         $t1, $a1, 25
    ctx->r9 = S32(ctx->r5 << 25);
    // 0x8008243C: sll         $t0, $t0, 6
    ctx->r8 = S32(ctx->r8 << 6);
    // 0x80082440: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x80082444: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80082448: addiu       $t1, $t1, 0x2540
    ctx->r9 = ADD32(ctx->r9, 0X2540);
    // 0x8008244C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80082450: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x80082454: ori         $t0, $t0, 0xC
    ctx->r8 = ctx->r8 | 0XC;
    // 0x80082458: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8008245C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80082460: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
L_80082464:
    // 0x80082464: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80082468: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8008246C: beql        $t1, $t2, L_80082464
    if (ctx->r9 == ctx->r10) {
        // 0x80082470: lw          $t2, 0x8($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X8);
            goto L_80082464;
    }
    goto skip_0;
    // 0x80082470: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    skip_0:
    // 0x80082474: jal         0x8002E660
    // 0x80082478: sub         $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80082478: sub         $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_0:
    // 0x8008247C: jal         0x80030AB0
    // 0x80082480: nop

    osInvalICache_recomp(rdram, ctx);
        goto after_1;
    // 0x80082480: nop

    after_1:
    // 0x80082484: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80082488: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8008248C: jr          $ra
    // 0x80082490: nop

    return;
    // 0x80082490: nop

;}
RECOMP_FUNC void func_800D9470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9470: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800D9474: lwc1        $f14, 0xC($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800D9478: mfc1        $t0, $f20
    ctx->r8 = (int32_t)ctx->f20.u32l;
    // 0x800D947C: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800D9480: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800D9484: lwc1        $f12, 0x8($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800D9488: mfc1        $t1, $f22
    ctx->r9 = (int32_t)ctx->f22.u32l;
    // 0x800D948C: mul.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800D9490: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800D9494: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800D9498: mfc1        $t2, $f24
    ctx->r10 = (int32_t)ctx->f24.u32l;
    // 0x800D949C: mul.s       $f20, $f4, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800D94A0: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800D94A4: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800D94A8: add.s       $f24, $f16, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D94AC: mul.s       $f22, $f6, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D94B0: sub.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f20.fl;
    // 0x800D94B4: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800D94B8: add.s       $f24, $f24, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f22.fl;
    // 0x800D94BC: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800D94C0: swc1        $f24, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f24.u32l;
    // 0x800D94C4: mul.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800D94C8: sub.s       $f24, $f18, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800D94CC: mul.s       $f22, $f6, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D94D0: add.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x800D94D4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800D94D8: add.s       $f24, $f24, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f22.fl;
    // 0x800D94DC: mul.s       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800D94E0: swc1        $f24, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f24.u32l;
    // 0x800D94E4: mul.s       $f20, $f4, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800D94E8: sub.s       $f24, $f16, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800D94EC: mul.s       $f22, $f6, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800D94F0: add.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x800D94F4: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D94F8: add.s       $f24, $f24, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f22.fl;
    // 0x800D94FC: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800D9500: swc1        $f24, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f24.u32l;
    // 0x800D9504: mul.s       $f20, $f4, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800D9508: add.s       $f24, $f16, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D950C: mul.s       $f22, $f6, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800D9510: add.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x800D9514: sub.s       $f24, $f22, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x800D9518: swc1        $f24, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f24.u32l;
    // 0x800D951C: mtc1        $t0, $f20
    ctx->f20.u32l = ctx->r8;
    // 0x800D9520: mtc1        $t1, $f22
    ctx->f22.u32l = ctx->r9;
    // 0x800D9524: jr          $ra
    // 0x800D9528: mtc1        $t2, $f24
    ctx->f24.u32l = ctx->r10;
    return;
    // 0x800D9528: mtc1        $t2, $f24
    ctx->f24.u32l = ctx->r10;
;}
RECOMP_FUNC void func_80800878_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800878: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080087C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800880: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800884: jal         0x80800000
    // 0x80800888: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800000_bsride(rdram, ctx);
        goto after_0;
    // 0x80800888: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080088C: lui         $a2, 0x3F54
    ctx->r6 = S32(0X3F54 << 16);
    // 0x80800890: ori         $a2, $a2, 0x7AE1
    ctx->r6 = ctx->r6 | 0X7AE1;
    // 0x80800894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800898: jal         0x8008CB3C
    // 0x8080089C: addiu       $a1, $zero, 0x481
    ctx->r5 = ADD32(0, 0X481);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080089C: addiu       $a1, $zero, 0x481
    ctx->r5 = ADD32(0, 0X481);
    after_1:
    // 0x808008A0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x808008A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808008B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808008B4: jal         0x8009FFD8
    // 0x808008B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808008B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C0: jal         0x8009B9B0
    // 0x808008C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x808008C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008CC: jal         0x800A34E4
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A34E4(rdram, ctx);
        goto after_4;
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: jal         0x800961AC
    // 0x808008DC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800961AC(rdram, ctx);
        goto after_5;
    // 0x808008DC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x808008E0: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E8: jal         0x808006D0
    // 0x808008EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808006D0_bsride(rdram, ctx);
        goto after_6;
    // 0x808008EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808008F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008FC: jr          $ra
    // 0x80800900: nop

    return;
    // 0x80800900: nop

;}
RECOMP_FUNC void _chbaddiesetup_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D70: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D70);
    return;
    // 0x80086D74: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80102CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102CA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102CAC: lwc1        $f14, 0x50($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80102CB0: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80102CB4: jal         0x800F20BC
    // 0x80102CB8: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    func_800F20BC(rdram, ctx);
        goto after_0;
    // 0x80102CB8: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_0:
    // 0x80102CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102CC4: jr          $ra
    // 0x80102CC8: nop

    return;
    // 0x80102CC8: nop

;}
RECOMP_FUNC void func_80809DD0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809DD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80809DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809DD8: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80809DDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80809DE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80809DE4: lw          $t6, 0xA0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA0);
    // 0x80809DE8: bnel        $a1, $t6, L_80809DFC
    if (ctx->r5 != ctx->r14) {
        // 0x80809DEC: lw          $v1, 0x10($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X10);
            goto L_80809DFC;
    }
    goto skip_0;
    // 0x80809DEC: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x80809DF0: b           L_80809E00
    // 0x80809DF4: lwc1        $f14, 0xC4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC4);
        goto L_80809E00;
    // 0x80809DF4: lwc1        $f14, 0xC4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x80809DF8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
L_80809DFC:
    // 0x80809DFC: lwc1        $f14, 0x180($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X180);
L_80809E00:
    // 0x80809E00: beq         $v1, $zero, L_80809E18
    if (ctx->r3 == 0) {
        // 0x80809E04: nop
    
            goto L_80809E18;
    }
    // 0x80809E04: nop

    // 0x80809E08: beql        $v1, $a1, L_80809E24
    if (ctx->r3 == ctx->r5) {
        // 0x80809E0C: lwc1        $f12, 0x148($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X148);
            goto L_80809E24;
    }
    goto skip_1;
    // 0x80809E0C: lwc1        $f12, 0x148($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X148);
    skip_1:
    // 0x80809E10: b           L_80809EEC
    // 0x80809E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80809EEC;
    // 0x80809E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80809E18:
    // 0x80809E18: b           L_80809EE8
    // 0x80809E1C: sw          $zero, 0x254($v0)
    MEM_W(0X254, ctx->r2) = 0;
        goto L_80809EE8;
    // 0x80809E1C: sw          $zero, 0x254($v0)
    MEM_W(0X254, ctx->r2) = 0;
    // 0x80809E20: lwc1        $f12, 0x148($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X148);
L_80809E24:
    // 0x80809E24: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80809E28: jal         0x800F2100
    // 0x80809E2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x80809E2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80809E30: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80809E34: jal         0x800F2100
    // 0x80809E38: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x80809E38: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80809E3C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA5A8) << 16);
    // 0x80809E40: lwc1        $f4, -0x5A58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA5A8));
    // 0x80809E44: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80809E48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80809E4C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80809E50: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80809E54: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80809E58: bc1fl       L_80809E90
    if (!c1cs) {
        // 0x80809E5C: lw          $t7, 0x254($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X254);
            goto L_80809E90;
    }
    goto skip_2;
    // 0x80809E5C: lw          $t7, 0x254($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X254);
    skip_2:
    // 0x80809E60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80809E64: nop

    // 0x80809E68: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80809E6C: nop

    // 0x80809E70: bc1fl       L_80809E84
    if (!c1cs) {
        // 0x80809E74: sw          $zero, 0x258($v0)
        MEM_W(0X258, ctx->r2) = 0;
            goto L_80809E84;
    }
    goto skip_3;
    // 0x80809E74: sw          $zero, 0x258($v0)
    MEM_W(0X258, ctx->r2) = 0;
    skip_3:
    // 0x80809E78: b           L_80809E84
    // 0x80809E7C: sw          $a1, 0x258($v0)
    MEM_W(0X258, ctx->r2) = ctx->r5;
        goto L_80809E84;
    // 0x80809E7C: sw          $a1, 0x258($v0)
    MEM_W(0X258, ctx->r2) = ctx->r5;
    // 0x80809E80: sw          $zero, 0x258($v0)
    MEM_W(0X258, ctx->r2) = 0;
L_80809E84:
    // 0x80809E84: b           L_80809EE8
    // 0x80809E88: sw          $zero, 0x254($v0)
    MEM_W(0X254, ctx->r2) = 0;
        goto L_80809EE8;
    // 0x80809E88: sw          $zero, 0x254($v0)
    MEM_W(0X254, ctx->r2) = 0;
    // 0x80809E8C: lw          $t7, 0x254($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X254);
L_80809E90:
    // 0x80809E90: bnel        $t7, $zero, L_80809EEC
    if (ctx->r15 != 0) {
        // 0x80809E94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80809EEC;
    }
    goto skip_4;
    // 0x80809E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80809E98: lw          $t8, 0x258($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X258);
    // 0x80809E9C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80809EA0: beql        $t8, $zero, L_80809ED0
    if (ctx->r24 == 0) {
        // 0x80809EA4: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80809ED0;
    }
    goto skip_5;
    // 0x80809EA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_5:
    // 0x80809EA8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80809EAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80809EB0: nop

    // 0x80809EB4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80809EB8: nop

    // 0x80809EBC: bc1fl       L_80809EEC
    if (!c1cs) {
        // 0x80809EC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80809EEC;
    }
    goto skip_6;
    // 0x80809EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x80809EC4: b           L_80809EE8
    // 0x80809EC8: sw          $a1, 0x254($v0)
    MEM_W(0X254, ctx->r2) = ctx->r5;
        goto L_80809EE8;
    // 0x80809EC8: sw          $a1, 0x254($v0)
    MEM_W(0X254, ctx->r2) = ctx->r5;
    // 0x80809ECC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80809ED0:
    // 0x80809ED0: nop

    // 0x80809ED4: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80809ED8: nop

    // 0x80809EDC: bc1fl       L_80809EEC
    if (!c1cs) {
        // 0x80809EE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80809EEC;
    }
    goto skip_7;
    // 0x80809EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80809EE4: sw          $a1, 0x254($v0)
    MEM_W(0X254, ctx->r2) = ctx->r5;
L_80809EE8:
    // 0x80809EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80809EEC:
    // 0x80809EEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80809EF0: jr          $ra
    // 0x80809EF4: nop

    return;
    // 0x80809EF4: nop

;}
RECOMP_FUNC void func_800B8C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8C50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B8C54: addiu       $v0, $v0, -0x7D40
    ctx->r2 = ADD32(ctx->r2, -0X7D40);
    // 0x800B8C58: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800B8C5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B8C60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B8C64: sb          $t9, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r25;
    // 0x800B8C68: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x800B8C6C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800B8C70: sb          $t9, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r25;
    // 0x800B8C74: sb          $zero, 0x9($v0)
    MEM_B(0X9, ctx->r2) = 0;
    // 0x800B8C78: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x800B8C7C: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x800B8C80: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x800B8C84: jr          $ra
    // 0x800B8C88: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x800B8C88: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void _chperspexboxswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871A8: syscall     531
    recomp_syscall_handler(rdram, ctx, 0x800871A8);
    return;
    // 0x800871AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800180_baeggfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800188: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x8080018C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800190: beq         $a1, $at, L_808001BC
    if (ctx->r5 == ctx->r1) {
        // 0x80800194: sw          $a1, 0x8($t6)
        MEM_W(0X8, ctx->r14) = ctx->r5;
            goto L_808001BC;
    }
    // 0x80800194: sw          $a1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r5;
    // 0x80800198: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080019C: beq         $a1, $at, L_808001DC
    if (ctx->r5 == ctx->r1) {
        // 0x808001A0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808001DC;
    }
    // 0x808001A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001A4: beq         $a1, $at, L_8080021C
    if (ctx->r5 == ctx->r1) {
        // 0x808001A8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080021C;
    }
    // 0x808001A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808001AC: beql        $a1, $at, L_80800234
    if (ctx->r5 == ctx->r1) {
        // 0x808001B0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800234;
    }
    goto skip_0;
    // 0x808001B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x808001B4: b           L_80800244
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800244;
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001BC:
    // 0x808001BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001C0: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x808001C4: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x808001C8: lw          $t8, 0x6C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X6C);
    // 0x808001CC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x808001D0: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    // 0x808001D4: b           L_80800240
    // 0x808001D8: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
        goto L_80800240;
    // 0x808001D8: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
L_808001DC:
    // 0x808001DC: lw          $t0, 0x6C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X6C);
    // 0x808001E0: lbu         $a1, 0x10($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X10);
    // 0x808001E4: jal         0x800944F8
    // 0x808001E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800944F8(rdram, ctx);
        goto after_0;
    // 0x808001E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001EC: beq         $v0, $zero, L_80800208
    if (ctx->r2 == 0) {
        // 0x808001F0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800208;
    }
    // 0x808001F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(516, 0X684) << 16);
    // 0x808001F8: lwc1        $f6, 0x684($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(516, 0X684));
    // 0x808001FC: lw          $t1, 0x6C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X6C);
    // 0x80800200: b           L_80800240
    // 0x80800204: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
        goto L_80800240;
    // 0x80800204: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
L_80800208:
    // 0x80800208: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(516, 0X688) << 16);
    // 0x8080020C: lwc1        $f8, 0x688($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(516, 0X688));
    // 0x80800210: lw          $t2, 0x6C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X6C);
    // 0x80800214: b           L_80800240
    // 0x80800218: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
        goto L_80800240;
    // 0x80800218: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
L_8080021C:
    // 0x8080021C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(516, 0X68C) << 16);
    // 0x80800220: lwc1        $f10, 0x68C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(516, 0X68C));
    // 0x80800224: lw          $t3, 0x6C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X6C);
    // 0x80800228: b           L_80800240
    // 0x8080022C: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
        goto L_80800240;
    // 0x8080022C: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80800230: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800234:
    // 0x80800234: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800238: lw          $t4, 0x6C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X6C);
    // 0x8080023C: swc1        $f16, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f16.u32l;
L_80800240:
    // 0x80800240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800244:
    // 0x80800244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800248: jr          $ra
    // 0x8080024C: nop

    return;
    // 0x8080024C: nop

;}
RECOMP_FUNC void func_80800798_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080079C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007A0: jal         0x800A587C
    // 0x808007A4: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x808007A4: nop

    after_0:
    // 0x808007A8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808007AC: beq         $v0, $at, L_808007CC
    if (ctx->r2 == ctx->r1) {
        // 0x808007B0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808007CC;
    }
    // 0x808007B0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808007B4: beq         $v0, $at, L_808007DC
    if (ctx->r2 == ctx->r1) {
        // 0x808007B8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_808007DC;
    }
    // 0x808007B8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808007BC: beq         $v0, $at, L_808007EC
    if (ctx->r2 == ctx->r1) {
        // 0x808007C0: nop
    
            goto L_808007EC;
    }
    // 0x808007C0: nop

    // 0x808007C4: b           L_808007FC
    // 0x808007C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007FC;
    // 0x808007C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007CC:
    // 0x808007CC: jal         0x800A586C
    // 0x808007D0: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x808007D0: nop

    after_1:
    // 0x808007D4: b           L_808007FC
    // 0x808007D8: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
        goto L_808007FC;
    // 0x808007D8: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_808007DC:
    // 0x808007DC: jal         0x800A586C
    // 0x808007E0: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x808007E0: nop

    after_2:
    // 0x808007E4: b           L_808007FC
    // 0x808007E8: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
        goto L_808007FC;
    // 0x808007E8: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
L_808007EC:
    // 0x808007EC: jal         0x800A586C
    // 0x808007F0: nop

    func_800A586C(rdram, ctx);
        goto after_3;
    // 0x808007F0: nop

    after_3:
    // 0x808007F4: b           L_808007FC
    // 0x808007F8: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
        goto L_808007FC;
    // 0x808007F8: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
L_808007FC:
    // 0x808007FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800804: jr          $ra
    // 0x80800808: nop

    return;
    // 0x80800808: nop

;}
RECOMP_FUNC void _badata_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846E0: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846E0);
    return;
    // 0x800846E4: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_80800CD8_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CE0: jal         0x80800060
    // 0x80800CE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800060_bstnt(rdram, ctx);
        goto after_0;
    // 0x80800CE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800CEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CF0: jal         0x80800B60
    // 0x80800CF4: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_80800B60_bstnt(rdram, ctx);
        goto after_1;
    // 0x80800CF4: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80800CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D00: jr          $ra
    // 0x80800D04: nop

    return;
    // 0x80800D04: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C08: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C08);
    return;
    // 0x80082C0C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _baswim_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852C8: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x800852C8);
    return;
    // 0x800852CC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void bsbeemain_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AB0: jal         0x800845D0
    // 0x80800AB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800AB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AB8: jal         0x80082830
    // 0x80800ABC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800ABC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AC8: jr          $ra
    // 0x80800ACC: nop

    return;
    // 0x80800ACC: nop

;}
RECOMP_FUNC void _bawobble_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085460: syscall     162
    recomp_syscall_handler(rdram, ctx, 0x80085460);
    return;
    // 0x80085464: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bswalk_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800300: jal         0x800A2EDC
    // 0x80800304: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800A2EDC(rdram, ctx);
        goto after_0;
    // 0x80800304: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x80800308: jal         0x8008E0E8
    // 0x8080030C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E0E8(rdram, ctx);
        goto after_1;
    // 0x8080030C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800310: beq         $v0, $zero, L_80800320
    if (ctx->r2 == 0) {
        // 0x80800314: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800320;
    }
    // 0x80800314: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800318: jal         0x80084788
    // 0x8080031C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8080031C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
L_80800320:
    // 0x80800320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void func_8080207C_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080207C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802084: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802088: jal         0x800D9078
    // 0x8080208C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x8080208C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80802090: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80802094: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80802098: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080209C: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x808020A0: lwc1        $f12, 0x28($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X28);
    // 0x808020A4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808020A8: lui         $a3, 0xC37A
    ctx->r7 = S32(0XC37A << 16);
    // 0x808020AC: jal         0x800F12D4
    // 0x808020B0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x808020B0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x808020B4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808020B8: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x808020BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808020C0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808020C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808020C8: jr          $ra
    // 0x808020CC: nop

    return;
    // 0x808020CC: nop

;}
RECOMP_FUNC void func_800A34AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A34AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A34B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A34B4: jal         0x800EE7F8
    // 0x800A34B8: lw          $a0, 0xA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XA0);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800A34B8: lw          $a0, 0xA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XA0);
    after_0:
    // 0x800A34BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A34C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A34C4: jr          $ra
    // 0x800A34C8: nop

    return;
    // 0x800A34C8: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080134C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801350: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801354: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801358: jal         0x80800060
    // 0x8080135C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x8080135C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801360: lui         $a2, 0x40C3
    ctx->r6 = S32(0X40C3 << 16);
    // 0x80801364: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080136C: jal         0x8008CB3C
    // 0x80801370: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801370: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_1:
    // 0x80801374: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80801378: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801384: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801388: jal         0x8009FFD8
    // 0x8080138C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080138C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80801390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801394: jal         0x8009B9B0
    // 0x80801398: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80801398: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808013A4: jal         0x80085338
    // 0x808013A8: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    _batimer_set(rdram, ctx);
        goto after_4;
    // 0x808013A8: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_4:
    // 0x808013AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808013B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808013B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808013B8: jr          $ra
    // 0x808013BC: nop

    return;
    // 0x808013BC: nop

;}
RECOMP_FUNC void chperspexboxswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2092, 0XD0) << 16);
    // 0x808000C4: jr          $ra
    // 0x808000C8: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2092, 0XD0));
    return;
    // 0x808000C8: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2092, 0XD0));
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_8080038C_sulights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800390: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800394: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800398: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x8080039C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808003A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808003A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808003AC: lwc1        $f18, 0x28($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X28);
    // 0x808003B0: beq         $v0, $a0, L_808003DC
    if (ctx->r2 == ctx->r4) {
        // 0x808003B4: lwc1        $f16, 0x1C($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_808003DC;
    }
    // 0x808003B4: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
L_808003B8:
    // 0x808003B8: mul.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x808003BC: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808003C0: lwc1        $f18, 0x2C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x808003C4: lwc1        $f16, 0x20($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X20);
    // 0x808003C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808003CC: swc1        $f12, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f12.u32l;
    // 0x808003D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808003D4: bne         $v0, $a0, L_808003B8
    if (ctx->r2 != ctx->r4) {
        // 0x808003D8: swc1        $f14, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->f14.u32l;
            goto L_808003B8;
    }
    // 0x808003D8: swc1        $f14, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f14.u32l;
L_808003DC:
    // 0x808003DC: mul.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x808003E0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808003E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808003E8: swc1        $f12, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f12.u32l;
    // 0x808003EC: swc1        $f14, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f14.u32l;
    // 0x808003F0: jr          $ra
    // 0x808003F4: nop

    return;
    // 0x808003F4: nop

;}
