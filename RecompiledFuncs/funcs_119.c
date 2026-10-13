#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808021BC_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808021C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808021C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808021C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808021CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808021D0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808021D4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808021D8: lui         $a2, 0xC47A
    ctx->r6 = S32(0XC47A << 16);
    // 0x808021DC: jal         0x800C6920
    // 0x808021E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6920(rdram, ctx);
        goto after_0;
    // 0x808021E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x808021E4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x808021E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808021EC: jal         0x800EE7F8
    // 0x808021F0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808021F0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_1:
    // 0x808021F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808021F8: jal         0x80102424
    // 0x808021FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808021FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80802200: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80802204: jal         0x800F54E4
    // 0x80802208: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80802208: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8080220C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802210: jal         0x800F5A00
    // 0x80802214: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x80802214: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80802218: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080221C: jal         0x800F1DF4
    // 0x80802220: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_5;
    // 0x80802220: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80802224: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80802228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080222C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802230: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802234: jr          $ra
    // 0x80802238: nop

    return;
    // 0x80802238: nop

;}
RECOMP_FUNC void func_80102950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102958: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8010295C: jal         0x800136E4
    // 0x80102960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x80102960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80102964: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80102968: swc1        $f0, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f0.u32l;
    // 0x8010296C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102974: jr          $ra
    // 0x80102978: nop

    return;
    // 0x80102978: nop

;}
RECOMP_FUNC void func_800A32EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A32EC: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A32F0: jr          $ra
    // 0x800A32F4: lbu         $v0, 0x2B($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2B);
    return;
    // 0x800A32F4: lbu         $v0, 0x2B($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2B);
;}
RECOMP_FUNC void func_808006A8_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006B0: jal         0x80800688
    // 0x808006B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800688_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x808006B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808006B8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808006BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006C0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x808006C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006C8: srl         $t8, $t7, 9
    ctx->r24 = S32(U32(ctx->r15) >> 9);
    // 0x808006CC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808006D0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808006D4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x808006D8: jr          $ra
    // 0x808006DC: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    return;
    // 0x808006DC: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
;}
RECOMP_FUNC void subaddieitem_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800010: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80800014: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
    // 0x80800018: sh          $a2, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r6;
    // 0x8080001C: sb          $a3, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r7;
    // 0x80800020: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80800024: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x80800028: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8080002C: jal         0x8008A020
    // 0x80800030: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800030: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80800034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800038: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void func_8009AD2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD2C: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8009AD30: jr          $ra
    // 0x8009AD34: sw          $a1, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r5;
    return;
    // 0x8009AD34: sw          $a1, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808001C4_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808001CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D0: bne         $a1, $at, L_808001E8
    if (ctx->r5 != ctx->r1) {
        // 0x808001D4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808001E8;
    }
    // 0x808001D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001D8: jal         0x80800110
    // 0x808001DC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800110_chcactusofstrength(rdram, ctx);
        goto after_0;
    // 0x808001DC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808001E0: b           L_808001F0
    // 0x808001E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001F0;
    // 0x808001E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001E8:
    // 0x808001E8: b           L_808001F0
    // 0x808001EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001F0;
    // 0x808001EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001F0:
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void boot___osDequeueThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800A91F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A91F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A91F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A91FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A9200: bltz        $a0, L_800A9294
    if (SIGNED(ctx->r4) < 0) {
        // 0x800A9204: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800A9294;
    }
    // 0x800A9204: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A9208: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A920C: addiu       $v0, $v0, 0x76D0
    ctx->r2 = ADD32(ctx->r2, 0X76D0);
    // 0x800A9210: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800A9214: addu        $s0, $v0, $t6
    ctx->r16 = ADD32(ctx->r2, ctx->r14);
    // 0x800A9218: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x800A921C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A9220: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800A9224: beq         $t7, $at, L_800A9294
    if (ctx->r15 == ctx->r1) {
        // 0x800A9228: addu        $s1, $v0, $t8
        ctx->r17 = ADD32(ctx->r2, ctx->r24);
            goto L_800A9294;
    }
    // 0x800A9228: addu        $s1, $v0, $t8
    ctx->r17 = ADD32(ctx->r2, ctx->r24);
    // 0x800A922C: jal         0x8010FBD4
    // 0x800A9230: lw          $a0, 0x58($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X58);
    func_8010FBD4(rdram, ctx);
        goto after_0;
    // 0x800A9230: lw          $a0, 0x58($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X58);
    after_0:
    // 0x800A9234: sw          $zero, 0x58($s1)
    MEM_W(0X58, ctx->r17) = 0;
    // 0x800A9238: jal         0x800A8984
    // 0x800A923C: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    func_800A8984(rdram, ctx);
        goto after_1;
    // 0x800A923C: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    after_1:
    // 0x800A9240: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800A9244: bne         $v0, $a0, L_800A9258
    if (ctx->r2 != ctx->r4) {
        // 0x800A9248: nop
    
            goto L_800A9258;
    }
    // 0x800A9248: nop

    // 0x800A924C: jal         0x800A8948
    // 0x800A9250: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    func_800A8948(rdram, ctx);
        goto after_2;
    // 0x800A9250: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    after_2:
    // 0x800A9254: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
L_800A9258:
    // 0x800A9258: jal         0x800CA364
    // 0x800A925C: nop

    func_800CA364(rdram, ctx);
        goto after_3;
    // 0x800A925C: nop

    after_3:
    // 0x800A9260: sw          $zero, 0x38($s1)
    MEM_W(0X38, ctx->r17) = 0;
    // 0x800A9264: lh          $t9, 0x8($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X8);
    // 0x800A9268: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A926C: addiu       $v1, $v1, 0x76D0
    ctx->r3 = ADD32(ctx->r3, 0X76D0);
    // 0x800A9270: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x800A9274: lbu         $t0, 0x4($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4);
    // 0x800A9278: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800A927C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800A9280: sb          $t1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r9;
    // 0x800A9284: sh          $t2, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r10;
    // 0x800A9288: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x800A928C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800A9290: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_800A9294:
    // 0x800A9294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9298: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A929C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A92A0: jr          $ra
    // 0x800A92A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A92A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800B27A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B27A0: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x800B27A4: bne         $v1, $zero, L_800B27B4
    if (ctx->r3 != 0) {
        // 0x800B27A8: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B27B4;
    }
    // 0x800B27A8: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B27AC: jr          $ra
    // 0x800B27B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B27B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B27B4:
    // 0x800B27B4: jr          $ra
    // 0x800B27B8: nop

    return;
    // 0x800B27B8: nop

;}
RECOMP_FUNC void func_800DF8F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF8F8: jr          $ra
    // 0x800DF8FC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    return;
    // 0x800DF8FC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
;}
RECOMP_FUNC void gcboundDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800334: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800338: lw          $s2, 0x74($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X74);
    // 0x8080033C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80800340: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800344: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80800348: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8080034C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800350: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80800354: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800358: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8080035C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800360: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800364: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80800368: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8080036C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800370: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80800374: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800378: jal         0x808013D4
    // 0x8080037C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_808013D4_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x8080037C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x80800380: beq         $v0, $zero, L_808003FC
    if (ctx->r2 == 0) {
        // 0x80800384: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808003FC;
    }
    // 0x80800384: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800388: lw          $fp, 0x6C($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X6C);
    // 0x8080038C: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
L_80800390:
    // 0x80800390: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800394: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800398: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8080039C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x808003A0: jal         0x80801484
    // 0x808003A4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    func_80801484_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x808003A4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_1:
    // 0x808003A8: beq         $v0, $zero, L_808003E0
    if (ctx->r2 == 0) {
        // 0x808003AC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808003E0;
    }
    // 0x808003AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003B0: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x808003B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003B8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x808003BC: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x808003C0: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x808003C4: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // 0x808003C8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808003CC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x808003D0: jal         0x808001A8
    // 0x808003D4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_808001A8_gcboundDll(rdram, ctx);
        goto after_2;
    // 0x808003D4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_2:
    // 0x808003D8: beq         $s2, $zero, L_80800448
    if (ctx->r18 == 0) {
        // 0x808003DC: addiu       $s6, $zero, 0x1
        ctx->r22 = ADD32(0, 0X1);
            goto L_80800448;
    }
    // 0x808003DC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_808003E0:
    // 0x808003E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808003E8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808003EC: jal         0x808013D4
    // 0x808003F0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_808013D4_gcboundDll(rdram, ctx);
        goto after_3;
    // 0x808003F0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x808003F4: bne         $v0, $zero, L_80800390
    if (ctx->r2 != 0) {
        // 0x808003F8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800390;
    }
    // 0x808003F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808003FC:
    // 0x808003FC: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x80800400: beq         $s2, $zero, L_8080040C
    if (ctx->r18 == 0) {
        // 0x80800404: lw          $fp, 0x6C($sp)
        ctx->r30 = MEM_W(ctx->r29, 0X6C);
            goto L_8080040C;
    }
    // 0x80800404: lw          $fp, 0x6C($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X6C);
    // 0x80800408: bne         $s6, $zero, L_80800448
    if (ctx->r22 != 0) {
        // 0x8080040C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800448;
    }
L_8080040C:
    // 0x8080040C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800410: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80800414: jal         0x80800280
    // 0x80800418: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80800280_gcboundDll(rdram, ctx);
        goto after_4;
    // 0x80800418: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_4:
    // 0x8080041C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80800420: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800424: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800428: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8080042C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80800430: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x80800434: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // 0x80800438: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080043C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80800440: jal         0x808001A8
    // 0x80800444: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_808001A8_gcboundDll(rdram, ctx);
        goto after_5;
    // 0x80800444: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_5:
L_80800448:
    // 0x80800448: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8080044C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800450: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80800454: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800458: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8080045C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800460: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80800464: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80800468: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8080046C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80800470: jr          $ra
    // 0x80800474: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800474: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void baeggsetup_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080059C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005A0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808005A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808005AC: jal         0x80086D30
    // 0x808005B0: lw          $a1, 0x184($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X184);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808005B0: lw          $a1, 0x184($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X184);
    after_0:
    // 0x808005B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005BC: jr          $ra
    // 0x808005C0: nop

    return;
    // 0x808005C0: nop

;}
RECOMP_FUNC void _batimer_isAt_falling(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085308: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x80085308);
    return;
    // 0x8008530C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800168_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080016C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800170: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800174: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800178: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080017C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800180: bne         $a1, $at, L_80800220
    if (ctx->r5 != ctx->r1) {
        // 0x80800184: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800220;
    }
    // 0x80800184: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800188: jal         0x800DA298
    // 0x8080018C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080018C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_0:
    // 0x80800190: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800194: bnel        $a1, $zero, L_808001AC
    if (ctx->r5 != 0) {
        // 0x80800198: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_808001AC;
    }
    goto skip_0;
    // 0x80800198: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    skip_0:
    // 0x8080019C: jal         0x80088848
    // 0x808001A0: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808001A0: nop

    after_1:
    // 0x808001A4: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x808001A8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_808001AC:
    // 0x808001AC: sltiu       $t7, $a1, 0x1
    ctx->r15 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x808001B0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x808001B4: jal         0x800BF744
    // 0x808001B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x808001B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x808001BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808001C0: jal         0x800BF744
    // 0x808001C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800BF744(rdram, ctx);
        goto after_3;
    // 0x808001C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x808001C8: sltiu       $a1, $s0, 0x1
    ctx->r5 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x808001CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001D0: jal         0x800BF744
    // 0x808001D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800BF744(rdram, ctx);
        goto after_4;
    // 0x808001D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x808001D8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808001DC: jal         0x800BF744
    // 0x808001E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800BF744(rdram, ctx);
        goto after_5;
    // 0x808001E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x808001E4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x808001E8: jal         0x800BF744
    // 0x808001EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800BF744(rdram, ctx);
        goto after_6;
    // 0x808001EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808001F0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x808001F4: jal         0x800BF744
    // 0x808001F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800BF744(rdram, ctx);
        goto after_7;
    // 0x808001F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x808001FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800200: jal         0x80100094
    // 0x80800204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80800204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800208: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8080020C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800210: bne         $s0, $zero, L_80800220
    if (ctx->r16 != 0) {
        // 0x80800214: swc1        $f4, 0x28($t8)
        MEM_W(0X28, ctx->r24) = ctx->f4.u32l;
            goto L_80800220;
    }
    // 0x80800214: swc1        $f4, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f4.u32l;
    // 0x80800218: jal         0x8080024C
    // 0x8080021C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_8080024C_chpowerhutwitchy(rdram, ctx);
        goto after_9;
    // 0x8080021C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_9:
L_80800220:
    // 0x80800220: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1080, 0XB00) << 16);
    // 0x80800224: addiu       $a3, $a3, 0xB00
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1080, 0XB00));
    // 0x80800228: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080022C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800230: jal         0x80086050
    // 0x80800234: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    _chpowerhut_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800234: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_10:
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080023C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800240: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void _bsdronevanish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083178: syscall     48
    recomp_syscall_handler(rdram, ctx, 0x80083178);
    return;
    // 0x8008317C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80090794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009079C: jal         0x800F54E4
    // 0x800907A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800907A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800907A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800907A8: jal         0x800F5D9C
    // 0x800907AC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F5D9C(rdram, ctx);
        goto after_1;
    // 0x800907AC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800907B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800907B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800907B8: jr          $ra
    // 0x800907BC: nop

    return;
    // 0x800907BC: nop

;}
RECOMP_FUNC void func_800F9BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9BAC: jal         0x800D9240
    // 0x800F9BB0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_800D9240(rdram, ctx);
        goto after_0;
    // 0x800F9BB0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x800F9BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F9BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9BBC: jr          $ra
    // 0x800F9BC0: nop

    return;
    // 0x800F9BC0: nop

;}
RECOMP_FUNC void func_800F9F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9F2C: bgez        $a1, L_800F9F4C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800F9F30: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_800F9F4C;
    }
    // 0x800F9F30: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800F9F34: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F9F38: addiu       $t7, $t7, 0x5530
    ctx->r15 = ADD32(ctx->r15, 0X5530);
    // 0x800F9F3C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F9F40: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800F9F44: b           L_800F9F6C
    // 0x800F9F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800F9F6C;
    // 0x800F9F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800F9F4C:
    // 0x800F9F4C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800F9F50: addiu       $t9, $t9, 0x5530
    ctx->r25 = ADD32(ctx->r25, 0X5530);
    // 0x800F9F54: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800F9F58: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x800F9F5C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800F9F60: beq         $at, $zero, L_800F9F6C
    if (ctx->r1 == 0) {
        // 0x800F9F64: nop
    
            goto L_800F9F6C;
    }
    // 0x800F9F64: nop

    // 0x800F9F68: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_800F9F6C:
    // 0x800F9F6C: jr          $ra
    // 0x800F9F70: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    return;
    // 0x800F9F70: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_80801184_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801188: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080118C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801190: bne         $a1, $at, L_80801260
    if (ctx->r5 != ctx->r1) {
        // 0x80801194: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80801260;
    }
    // 0x80801194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801198: sltiu       $at, $a2, 0x9
    ctx->r1 = ctx->r6 < 0X9 ? 1 : 0;
    // 0x8080119C: beq         $at, $zero, L_808011CC
    if (ctx->r1 == 0) {
        // 0x808011A0: sll         $t6, $a2, 2
        ctx->r14 = S32(ctx->r6 << 2);
            goto L_808011CC;
    }
    // 0x808011A0: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x808011A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X1334) << 16);
    // 0x808011A8: addu        $at, $at, $t6
    gpr jr_addend_808011B0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808011AC: lw          $t6, 0x1334($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1640, 0X1334));
    // 0x808011B0: jr          $t6
    // 0x808011B4: nop

    switch (jr_addend_808011B0 >> 2) {
        case 0: goto L_808011D4; break;
        case 1: goto L_808011CC; break;
        case 2: goto L_80801200; break;
        case 3: goto L_808011CC; break;
        case 4: goto L_808011E4; break;
        case 5: goto L_808011CC; break;
        case 6: goto L_808011B8; break;
        case 7: goto L_808011CC; break;
        case 8: goto L_80801210; break;
        default: switch_error(__func__, 0x808011B0, 0x80801334);
    }
    // 0x808011B4: nop

L_808011B8:
    // 0x808011B8: jal         0x800DA544
    // 0x808011BC: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x808011BC: addiu       $a0, $zero, 0x4FC
    ctx->r4 = ADD32(0, 0X4FC);
    after_0:
    // 0x808011C0: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    // 0x808011C4: jal         0x800887D8
    // 0x808011C8: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808011C8: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_1:
L_808011CC:
    // 0x808011CC: b           L_80801264
    // 0x808011D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801264;
    // 0x808011D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808011D4:
    // 0x808011D4: jal         0x80088830
    // 0x808011D8: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_2;
    // 0x808011D8: nop

    after_2:
    // 0x808011DC: b           L_80801264
    // 0x808011E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801264;
    // 0x808011E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808011E4:
    // 0x808011E4: jal         0x80085718
    // 0x808011E8: nop

    _capod_entrypoint_15(rdram, ctx);
        goto after_3;
    // 0x808011E8: nop

    after_3:
    // 0x808011EC: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    // 0x808011F0: jal         0x800887D8
    // 0x808011F4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808011F4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_4:
    // 0x808011F8: b           L_80801264
    // 0x808011FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801264;
    // 0x808011FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801200:
    // 0x80801200: jal         0x80088830
    // 0x80801204: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x80801204: nop

    after_5:
    // 0x80801208: b           L_80801264
    // 0x8080120C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801264;
    // 0x8080120C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801210:
    // 0x80801210: jal         0x80088860
    // 0x80801214: nop

    _glcutDll_entrypoint_23(rdram, ctx);
        goto after_6;
    // 0x80801214: nop

    after_6:
    // 0x80801218: beq         $v0, $zero, L_80801230
    if (ctx->r2 == 0) {
        // 0x8080121C: nop
    
            goto L_80801230;
    }
    // 0x8080121C: nop

    // 0x80801220: jal         0x80088830
    // 0x80801224: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_7;
    // 0x80801224: nop

    after_7:
    // 0x80801228: b           L_80801264
    // 0x8080122C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801264;
    // 0x8080122C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801230:
    // 0x80801230: jal         0x800DB9B0
    // 0x80801234: nop

    func_800DB9B0(rdram, ctx);
        goto after_8;
    // 0x80801234: nop

    after_8:
    // 0x80801238: beq         $v0, $zero, L_80801248
    if (ctx->r2 == 0) {
        // 0x8080123C: nop
    
            goto L_80801248;
    }
    // 0x8080123C: nop

    // 0x80801240: jal         0x80088830
    // 0x80801244: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_9;
    // 0x80801244: nop

    after_9:
L_80801248:
    // 0x80801248: jal         0x80085710
    // 0x8080124C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_10;
    // 0x8080124C: nop

    after_10:
    // 0x80801250: jal         0x800FFAB0
    // 0x80801254: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_11;
    // 0x80801254: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_11:
    // 0x80801258: b           L_80801264
    // 0x8080125C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801264;
    // 0x8080125C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801260:
    // 0x80801260: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801264:
    // 0x80801264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080126C: jr          $ra
    // 0x80801270: nop

    return;
    // 0x80801270: nop

;}
RECOMP_FUNC void _suegg_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3A0: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3A0);
    return;
    // 0x8008A3A4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800C7E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7E28: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x800C7E2C: addiu       $a1, $a0, 0x14
    ctx->r5 = ADD32(ctx->r4, 0X14);
    // 0x800C7E30: addiu       $t7, $a0, 0xC
    ctx->r15 = ADD32(ctx->r4, 0XC);
    // 0x800C7E34: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800C7E38: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800C7E3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C7E40: addu        $a3, $t6, $a0
    ctx->r7 = ADD32(ctx->r14, ctx->r4);
    // 0x800C7E44: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x800C7E48: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C7E4C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800C7E50: beq         $t7, $a3, L_800C7FB8
    if (ctx->r15 == ctx->r7) {
        // 0x800C7E54: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800C7FB8;
    }
    // 0x800C7E54: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800C7E58: subu        $a3, $t0, $a1
    ctx->r7 = SUB32(ctx->r8, ctx->r5);
    // 0x800C7E5C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800C7E60: divu        $zero, $a3, $at
    lo = S32(U32(ctx->r7) / U32(ctx->r1)); hi = S32(U32(ctx->r7) % U32(ctx->r1));
    // 0x800C7E64: mfhi        $t8
    ctx->r24 = hi;
    // 0x800C7E68: beql        $t8, $zero, L_800C7EE8
    if (ctx->r24 == 0) {
        // 0x800C7E6C: lwc1        $f0, 0x0($t0)
        ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
            goto L_800C7EE8;
    }
    goto skip_0;
    // 0x800C7E6C: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x800C7E70: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C7E74: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C7E78: addiu       $v1, $a1, 0xC
    ctx->r3 = ADD32(ctx->r5, 0XC);
    // 0x800C7E7C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800C7E80: nop

    // 0x800C7E84: bc1f        L_800C7EDC
    if (!c1cs) {
        // 0x800C7E88: nop
    
            goto L_800C7EDC;
    }
    // 0x800C7E88: nop

    // 0x800C7E8C: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7E90: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C7E94: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800C7E98: nop

    // 0x800C7E9C: bc1f        L_800C7EDC
    if (!c1cs) {
        // 0x800C7EA0: nop
    
            goto L_800C7EDC;
    }
    // 0x800C7EA0: nop

    // 0x800C7EA4: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C7EA8: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C7EAC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800C7EB0: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800C7EB4: nop

    // 0x800C7EB8: bc1f        L_800C7EDC
    if (!c1cs) {
        // 0x800C7EBC: nop
    
            goto L_800C7EDC;
    }
    // 0x800C7EBC: nop

    // 0x800C7EC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C7EC4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800C7EC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C7ECC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C7ED0: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C7ED4: jr          $ra
    // 0x800C7ED8: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800C7ED8: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
L_800C7EDC:
    // 0x800C7EDC: beq         $v1, $t0, L_800C7FB8
    if (ctx->r3 == ctx->r8) {
        // 0x800C7EE0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800C7FB8;
    }
    // 0x800C7EE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C7EE4: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
L_800C7EE8:
    // 0x800C7EE8: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C7EEC: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x800C7EF0: nop

    // 0x800C7EF4: bc1fl       L_800C7F4C
    if (!c1cs) {
        // 0x800C7EF8: lwc1        $f8, 0xC($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
            goto L_800C7F4C;
    }
    goto skip_1;
    // 0x800C7EF8: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    skip_1:
    // 0x800C7EFC: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800C7F00: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C7F04: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x800C7F08: nop

    // 0x800C7F0C: bc1fl       L_800C7F4C
    if (!c1cs) {
        // 0x800C7F10: lwc1        $f8, 0xC($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
            goto L_800C7F4C;
    }
    goto skip_2;
    // 0x800C7F10: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    skip_2:
    // 0x800C7F14: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800C7F18: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C7F1C: c.eq.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl == ctx->f6.fl;
    // 0x800C7F20: nop

    // 0x800C7F24: bc1f        L_800C7F48
    if (!c1cs) {
        // 0x800C7F28: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800C7F48;
    }
    // 0x800C7F28: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800C7F2C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800C7F30: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800C7F34: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C7F38: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C7F3C: div.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800C7F40: jr          $ra
    // 0x800C7F44: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800C7F44: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
L_800C7F48:
    // 0x800C7F48: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
L_800C7F4C:
    // 0x800C7F4C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800C7F50: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x800C7F54: nop

    // 0x800C7F58: bc1fl       L_800C7FB0
    if (!c1cs) {
        // 0x800C7F5C: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_800C7FB0;
    }
    goto skip_3;
    // 0x800C7F5C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    skip_3:
    // 0x800C7F60: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800C7F64: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C7F68: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x800C7F6C: nop

    // 0x800C7F70: bc1fl       L_800C7FB0
    if (!c1cs) {
        // 0x800C7F74: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_800C7FB0;
    }
    goto skip_4;
    // 0x800C7F74: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    skip_4:
    // 0x800C7F78: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800C7F7C: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C7F80: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x800C7F84: nop

    // 0x800C7F88: bc1f        L_800C7FAC
    if (!c1cs) {
        // 0x800C7F8C: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800C7FAC;
    }
    // 0x800C7F8C: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800C7F90: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800C7F94: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800C7F98: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C7F9C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C7FA0: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C7FA4: jr          $ra
    // 0x800C7FA8: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800C7FA8: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
L_800C7FAC:
    // 0x800C7FAC: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
L_800C7FB0:
    // 0x800C7FB0: bne         $v1, $a2, L_800C7EE8
    if (ctx->r3 != ctx->r6) {
        // 0x800C7FB4: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800C7EE8;
    }
    // 0x800C7FB4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800C7FB8:
    // 0x800C7FB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C7FBC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C7FC0: nop

    // 0x800C7FC4: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
    // 0x800C7FC8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800C7FCC: jr          $ra
    // 0x800C7FD0: nop

    return;
    // 0x800C7FD0: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801194: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801198: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B68) << 16);
    // 0x8080119C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808011A0: jr          $ra
    // 0x808011A4: lw          $v0, 0x1B68($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B68));
    return;
    // 0x808011A4: lw          $v0, 0x1B68($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B68));
;}
RECOMP_FUNC void bashoes_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800864: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080086C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800870: jal         0x800B53A4
    // 0x80800874: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800874: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80800878: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080087C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800880: jal         0x8009C128
    // 0x80800884: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800884: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800888: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(592, 0XAD0) << 16);
    // 0x8080088C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800890: addiu       $t6, $t6, 0xAD0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(592, 0XAD0));
    // 0x80800894: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800898: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080089C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008A0: jal         0x800BABB8
    // 0x808008A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808008A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x808008A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808008B0: jr          $ra
    // 0x808008B4: nop

    return;
    // 0x808008B4: nop

;}
RECOMP_FUNC void func_808007F4_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800800: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800804: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800808: jal         0x80100094
    // 0x8080080C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080080C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800814: jal         0x808008A4
    // 0x80800818: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_808008A4_chspotlight(rdram, ctx);
        goto after_1;
    // 0x80800818: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080081C: bne         $v0, $zero, L_8080086C
    if (ctx->r2 != 0) {
        // 0x80800820: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8080086C;
    }
    // 0x80800820: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800828: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080082C: jal         0x80101FDC
    // 0x80800830: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800830: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800834: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800838: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8080083C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800840: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80800844: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80800848: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8080084C: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x80800850: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x80800854: beql        $a0, $zero, L_80800894
    if (ctx->r4 == 0) {
        // 0x80800858: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800894;
    }
    goto skip_0;
    // 0x80800858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080085C: jal         0x800C8FE0
    // 0x80800860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_3;
    // 0x80800860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800864: b           L_80800894
    // 0x80800868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800894;
    // 0x80800868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080086C:
    // 0x8080086C: jal         0x80800580
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800580_chspotlight(rdram, ctx);
        goto after_4;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800874: jal         0x80800730
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800730_chspotlight(rdram, ctx);
        goto after_5;
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: jal         0x80800600
    // 0x80800884: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80800600_chspotlight(rdram, ctx);
        goto after_6;
    // 0x80800884: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800888: jal         0x808006B8
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006B8_chspotlight(rdram, ctx);
        goto after_7;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800894:
    // 0x80800894: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800898: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080089C: jr          $ra
    // 0x808008A0: nop

    return;
    // 0x808008A0: nop

;}
RECOMP_FUNC void sccustom_banjo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800004: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8080000C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800010: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80800014: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800018: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x8080001C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80800020: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800024: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80800028: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8080002C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800030: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800034: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800038: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080003C: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80800040: jal         0x800D674C
    // 0x80800044: addiu       $a0, $zero, 0xB4D
    ctx->r4 = ADD32(0, 0XB4D);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a0, $zero, 0xB4D
    ctx->r4 = ADD32(0, 0XB4D);
    after_0:
    // 0x80800048: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x8080004C: jal         0x8008A5D8
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800054: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800058: jal         0x8008A610
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800060: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800064: jal         0x8008A618
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080006C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800070: jal         0x8008A620
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800078: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080007C: jal         0x8008A5F0
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800084: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80800088: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8080008C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800090: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // 0x80800094: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800098: sll         $s2, $v0, 2
    ctx->r18 = S32(ctx->r2 << 2);
    // 0x8080009C: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x808000A0: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x808000A4: sll         $s6, $fp, 2
    ctx->r22 = S32(ctx->r30 << 2);
    // 0x808000A8: addiu       $s7, $zero, 0x100
    ctx->r23 = ADD32(0, 0X100);
    // 0x808000AC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808000B0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x808000B4: addiu       $s2, $s2, 0x28
    ctx->r18 = ADD32(ctx->r18, 0X28);
    // 0x808000B8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808000BC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x808000C0: nop

    // 0x808000C4: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808000C8: beq         $at, $zero, L_8080010C
    if (ctx->r1 == 0) {
        // 0x808000CC: subu        $t8, $v1, $s5
        ctx->r24 = SUB32(ctx->r3, ctx->r21);
            goto L_8080010C;
    }
    // 0x808000CC: subu        $t8, $v1, $s5
    ctx->r24 = SUB32(ctx->r3, ctx->r21);
    // 0x808000D0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808000D4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x808000D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808000E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000E4: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x808000E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000F0: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x808000F4: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x808000F8: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x808000FC: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800100: mfc1        $s7, $f6
    ctx->r23 = (int32_t)ctx->f6.u32l;
    // 0x80800104: b           L_8080010C
    // 0x80800108: nop

        goto L_8080010C;
    // 0x80800108: nop

L_8080010C:
    // 0x8080010C: bltz        $v0, L_808001D8
    if (SIGNED(ctx->r2) < 0) {
        // 0x80800110: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808001D8;
    }
    // 0x80800110: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800114:
    // 0x80800114: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x80800118: addiu       $t1, $s0, 0x1
    ctx->r9 = ADD32(ctx->r16, 0X1);
    // 0x8080011C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800120: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800124: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800128: mfc1        $s1, $f4
    ctx->r17 = (int32_t)ctx->f4.u32l;
    // 0x8080012C: nop

    // 0x80800130: slt         $at, $s5, $s1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80800134: beq         $at, $zero, L_80800140
    if (ctx->r1 == 0) {
        // 0x80800138: nop
    
            goto L_80800140;
    }
    // 0x80800138: nop

    // 0x8080013C: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
L_80800140:
    // 0x80800140: beq         $s4, $fp, L_80800158
    if (ctx->r20 == ctx->r30) {
        // 0x80800144: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800158;
    }
    // 0x80800144: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800148: beq         $s4, $at, L_80800170
    if (ctx->r20 == ctx->r1) {
        // 0x8080014C: nop
    
            goto L_80800170;
    }
    // 0x8080014C: nop

    // 0x80800150: b           L_80800178
    // 0x80800154: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
        goto L_80800178;
    // 0x80800154: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
L_80800158:
    // 0x80800158: bne         $s3, $t1, L_80800168
    if (ctx->r19 != ctx->r9) {
        // 0x8080015C: nop
    
            goto L_80800168;
    }
    // 0x8080015C: nop

    // 0x80800160: b           L_80800188
    // 0x80800164: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_80800188;
    // 0x80800164: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80800168:
    // 0x80800168: b           L_80800188
    // 0x8080016C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
        goto L_80800188;
    // 0x8080016C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
L_80800170:
    // 0x80800170: b           L_80800188
    // 0x80800174: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
        goto L_80800188;
    // 0x80800174: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
L_80800178:
    // 0x80800178: beq         $at, $zero, L_80800188
    if (ctx->r1 == 0) {
        // 0x8080017C: addiu       $v0, $zero, 0x78
        ctx->r2 = ADD32(0, 0X78);
            goto L_80800188;
    }
    // 0x8080017C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x80800180: b           L_80800188
    // 0x80800184: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_80800188;
    // 0x80800184: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80800188:
    // 0x80800188: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080018C: mflo        $a0
    ctx->r4 = lo;
    // 0x80800190: sra         $t2, $a0, 8
    ctx->r10 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80800194: jal         0x800E257C
    // 0x80800198: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800E257C(rdram, ctx);
        goto after_6;
    // 0x80800198: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_6:
    // 0x8080019C: jal         0x800E253C
    // 0x808001A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800E253C(rdram, ctx);
        goto after_7;
    // 0x808001A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x808001A4: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x808001A8: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x808001AC: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x808001B0: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x808001B4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x808001B8: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x808001BC: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x808001C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001C4: jal         0x800E30E0
    // 0x808001C8: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    func_800E30E0(rdram, ctx);
        goto after_8;
    // 0x808001C8: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    after_8:
    // 0x808001CC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808001D0: bgez        $s0, L_80800114
    if (SIGNED(ctx->r16) >= 0) {
        // 0x808001D4: addiu       $s2, $s2, -0x14
        ctx->r18 = ADD32(ctx->r18, -0X14);
            goto L_80800114;
    }
    // 0x808001D4: addiu       $s2, $s2, -0x14
    ctx->r18 = ADD32(ctx->r18, -0X14);
L_808001D8:
    // 0x808001D8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x808001DC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808001E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001E4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808001E8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808001EC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808001F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808001F4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808001F8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808001FC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80800200: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80800204: jr          $ra
    // 0x80800208: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80800208: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800C7AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7AE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7AEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C7AF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C7AF4: jal         0x800C7980
    // 0x800C7AF8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800C7980(rdram, ctx);
        goto after_0;
    // 0x800C7AF8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C7AFC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800C7B00: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C7B04: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800C7B08: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x800C7B0C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C7B10: jal         0x80089130
    // 0x800C7B14: addiu       $a1, $v1, 0x14
    ctx->r5 = ADD32(ctx->r3, 0X14);
    _mlspline_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x800C7B14: addiu       $a1, $v1, 0x14
    ctx->r5 = ADD32(ctx->r3, 0X14);
    after_1:
    // 0x800C7B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7B1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7B20: jr          $ra
    // 0x800C7B24: nop

    return;
    // 0x800C7B24: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801074: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801078: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(104, 0X14B0) << 16);
    // 0x8080107C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801080: jr          $ra
    // 0x80801084: lw          $v0, 0x14B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14B0));
    return;
    // 0x80801084: lw          $v0, 0x14B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14B0));
;}
RECOMP_FUNC void func_800C7A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A58: jr          $ra
    // 0x800C7A5C: nop

    return;
    // 0x800C7A5C: nop

;}
RECOMP_FUNC void ncbabee_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800094: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080009C: jal         0x80110840
    // 0x808000A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x808000A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000A4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x8011607C
    // 0x808000B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8011607C(rdram, ctx);
        goto after_1;
    // 0x808000B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x801107F0
    // 0x808000BC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_801107F0(rdram, ctx);
        goto after_2;
    // 0x808000BC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_2:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80800070
    // 0x808000C8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_80800070_ncbabee(rdram, ctx);
        goto after_3;
    // 0x808000C8: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_3:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808000D4: jal         0x80115444
    // 0x808000D8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_80115444(rdram, ctx);
        goto after_4;
    // 0x808000D8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x808000DC: jal         0x800F5AE0
    // 0x808000E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F5AE0(rdram, ctx);
        goto after_5;
    // 0x808000E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808000E4: jal         0x80013728
    // 0x808000E8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_6;
    // 0x808000E8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x808000EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000F4: jal         0x80115828
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115828(rdram, ctx);
        goto after_7;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800100: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80800104: jal         0x800EFB24
    // 0x80800108: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80800108: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_8:
    // 0x8080010C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800110: jal         0x800F1A88
    // 0x80800114: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F1A88(rdram, ctx);
        goto after_9;
    // 0x80800114: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_9:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x80115750
    // 0x80800120: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80115750(rdram, ctx);
        goto after_10;
    // 0x80800120: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_10:
    // 0x80800124: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800128: jal         0x801112B0
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801112B0(rdram, ctx);
        goto after_11;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800130: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800134: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800138: jal         0x800136E4
    // 0x8080013C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_12;
    // 0x8080013C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_12:
    // 0x80800140: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80800144: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800148: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8080014C: jal         0x800EEBF0
    // 0x80800150: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    func_800EEBF0(rdram, ctx);
        goto after_13;
    // 0x80800150: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_13:
    // 0x80800154: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80800158: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8080015C: jal         0x800EE780
    // 0x80800160: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800EE780(rdram, ctx);
        goto after_14;
    // 0x80800160: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_14:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x80111FD4
    // 0x8080016C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_80111FD4(rdram, ctx);
        goto after_15;
    // 0x8080016C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_15:
    // 0x80800170: beql        $v0, $zero, L_80800184
    if (ctx->r2 == 0) {
        // 0x80800174: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800184;
    }
    goto skip_0;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800178: jal         0x801138F4
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_16;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800184:
    // 0x80800184: jal         0x80112524
    // 0x80800188: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_80112524(rdram, ctx);
        goto after_17;
    // 0x80800188: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_17:
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800194: jal         0x80110A68
    // 0x80800198: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_80110A68(rdram, ctx);
        goto after_18;
    // 0x80800198: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_18:
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: jal         0x80110790
    // 0x808001A4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80110790(rdram, ctx);
        goto after_19;
    // 0x808001A4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_19:
    // 0x808001A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001B0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x808001B4: jr          $ra
    // 0x808001B8: nop

    return;
    // 0x808001B8: nop

    // 0x808001BC: nop

;}
RECOMP_FUNC void _chbadshad_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085768: syscall     173
    recomp_syscall_handler(rdram, ctx, 0x80085768);
    return;
    // 0x8008576C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801F20_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801F28: jal         0x800845D0
    // 0x80801F2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801F2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801F30: jal         0x80800E54
    // 0x80801F34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstnt_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801F34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801F40: jr          $ra
    // 0x80801F44: nop

    return;
    // 0x80801F44: nop

;}
RECOMP_FUNC void func_800BA5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA5D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BA5D4: lw          $t8, 0x90($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X90);
    // 0x800BA5D8: lw          $v0, 0x8C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8C);
    // 0x800BA5DC: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800BA5E0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BA5E4: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x800BA5E8: beq         $at, $zero, L_800BA608
    if (ctx->r1 == 0) {
        // 0x800BA5EC: sh          $a1, 0x14($a0)
        MEM_H(0X14, ctx->r4) = ctx->r5;
            goto L_800BA608;
    }
    // 0x800BA5EC: sh          $a1, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r5;
    // 0x800BA5F0: sh          $a1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r5;
L_800BA5F4:
    // 0x800BA5F4: lw          $t9, 0x90($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X90);
    // 0x800BA5F8: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x800BA5FC: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x800BA600: bnel        $at, $zero, L_800BA5F4
    if (ctx->r1 != 0) {
        // 0x800BA604: sh          $a1, 0x8($v0)
        MEM_H(0X8, ctx->r2) = ctx->r5;
            goto L_800BA5F4;
    }
    goto skip_0;
    // 0x800BA604: sh          $a1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r5;
    skip_0:
L_800BA608:
    // 0x800BA608: jr          $ra
    // 0x800BA60C: nop

    return;
    // 0x800BA60C: nop

;}
RECOMP_FUNC void func_800D5424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5424: jr          $ra
    // 0x800D5428: addiu       $v0, $a0, -0x16
    ctx->r2 = ADD32(ctx->r4, -0X16);
    return;
    // 0x800D5428: addiu       $v0, $a0, -0x16
    ctx->r2 = ADD32(ctx->r4, -0X16);
;}
RECOMP_FUNC void func_808004D4_chcrystalbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808004E0: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x808004E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004E8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808004EC: jal         0x80089BF8
    // 0x808004F0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _subaddiejoy_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808004F0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x808004F4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808004F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800500: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80800504: jal         0x80086678
    // 0x80800508: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _chexploder_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800508: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x8080050C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800510: lbu         $t7, 0x64($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X64);
    // 0x80800514: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80800518: sb          $t8, 0x64($v0)
    MEM_B(0X64, ctx->r2) = ctx->r24;
    // 0x8080051C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800524: jr          $ra
    // 0x80800528: nop

    return;
    // 0x80800528: nop

;}
RECOMP_FUNC void func_808006DC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808006E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006E8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808006EC: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    // 0x808006F0: jal         0x800F2100
    // 0x808006F4: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x808006F4: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    after_0:
    // 0x808006F8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808006FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800700: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800704: bne         $t6, $at, L_80800724
    if (ctx->r14 != ctx->r1) {
        // 0x80800708: lwc1        $f2, 0x48($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80800724;
    }
    // 0x80800708: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080070C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA3C8) << 16);
    // 0x80800710: lwc1        $f12, -0x5C38($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA3C8));
    // 0x80800714: mul.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80800718: nop

    // 0x8080071C: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80800720: nop

L_80800724:
    // 0x80800724: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800728: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080072C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800730: lui         $at, 0x4148
    ctx->r1 = S32(0X4148 << 16);
    // 0x80800734: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80800738: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8080073C: nop

    // 0x80800740: bc1fl       L_80800754
    if (!c1cs) {
        // 0x80800744: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80800754;
    }
    goto skip_0;
    // 0x80800744: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_0:
    // 0x80800748: b           L_80800754
    // 0x8080074C: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
        goto L_80800754;
    // 0x8080074C: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
    // 0x80800750: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80800754:
    // 0x80800754: c.eq.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl == ctx->f16.fl;
    // 0x80800758: nop

    // 0x8080075C: bc1tl       L_808007A8
    if (c1cs) {
        // 0x80800760: swc1        $f16, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
            goto L_808007A8;
    }
    goto skip_1;
    // 0x80800760: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    skip_1:
    // 0x80800764: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800768: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8080076C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x80800770: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80800774: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80800778: jal         0x800136E4
    // 0x8080077C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x8080077C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_1:
    // 0x80800780: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800784: jal         0x80013970
    // 0x80800788: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_2;
    // 0x80800788: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x8080078C: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800790: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800794: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800798: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080079C: b           L_808007AC
    // 0x808007A0: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_808007AC;
    // 0x808007A0: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x808007A4: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
L_808007A8:
    // 0x808007A8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_808007AC:
    // 0x808007AC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808007B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007B4: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x808007B8: mul.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x808007BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808007C0: nop

    // 0x808007C4: bc1fl       L_808007D8
    if (!c1cs) {
        // 0x808007C8: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_808007D8;
    }
    goto skip_2;
    // 0x808007C8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_2:
    // 0x808007CC: b           L_808007D8
    // 0x808007D0: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
        goto L_808007D8;
    // 0x808007D0: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x808007D4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_808007D8:
    // 0x808007D8: c.eq.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl == ctx->f16.fl;
    // 0x808007DC: nop

    // 0x808007E0: bc1tl       L_80800818
    if (c1cs) {
        // 0x808007E4: swc1        $f16, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->f16.u32l;
            goto L_80800818;
    }
    goto skip_3;
    // 0x808007E4: swc1        $f16, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f16.u32l;
    skip_3:
    // 0x808007E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007EC: lwc1        $f8, 0x5C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x808007F0: mul.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x808007F4: jal         0x800136E4
    // 0x808007F8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x808007F8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x808007FC: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x80800800: jal         0x80013970
    // 0x80800804: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_4;
    // 0x80800804: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x80800808: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8080080C: b           L_8080081C
    // 0x80800810: swc1        $f18, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f18.u32l;
        goto L_8080081C;
    // 0x80800810: swc1        $f18, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f18.u32l;
    // 0x80800814: swc1        $f16, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f16.u32l;
L_80800818:
    // 0x80800818: swc1        $f16, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f16.u32l;
L_8080081C:
    // 0x8080081C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800820: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800824: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800828: jr          $ra
    // 0x8080082C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080082C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8080014C_chmole_maya(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800158: jal         0x800DA298
    // 0x8080015C: addiu       $a0, $zero, 0x506
    ctx->r4 = ADD32(0, 0X506);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080015C: addiu       $a0, $zero, 0x506
    ctx->r4 = ADD32(0, 0X506);
    after_0:
    // 0x80800160: beql        $v0, $zero, L_80800174
    if (ctx->r2 == 0) {
        // 0x80800164: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800174;
    }
    goto skip_0;
    // 0x80800164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800168: jal         0x800FFAB0
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
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
RECOMP_FUNC void func_800E4064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E4068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E406C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E4070: jal         0x800CA6FC
    // 0x800E4074: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA6FC(rdram, ctx);
        goto after_0;
    // 0x800E4074: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E4078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E407C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E4080: jr          $ra
    // 0x800E4084: nop

    return;
    // 0x800E4084: nop

;}
RECOMP_FUNC void bskazfly_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801ADC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801AE0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(236, 0X1CB8) << 16);
    // 0x80801AE4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801AE8: jr          $ra
    // 0x80801AEC: lw          $v0, 0x1CB8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1CB8));
    return;
    // 0x80801AEC: lw          $v0, 0x1CB8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1CB8));
;}
RECOMP_FUNC void func_80800390_chtoxicroomprops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800390: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800394: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800398: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080039C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808003A0: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x808003A4: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x808003A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808003AC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x808003B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003B4: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x808003B8: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x808003BC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808003C0: nop

    // 0x808003C4: bc1fl       L_808003D4
    if (!c1cs) {
        // 0x808003C8: lwc1        $f10, 0x4C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
            goto L_808003D4;
    }
    goto skip_0;
    // 0x808003C8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    skip_0:
    // 0x808003CC: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x808003D0: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_808003D4:
    // 0x808003D4: jal         0x800D8FF8
    // 0x808003D8: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808003D8: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    after_0:
    // 0x808003DC: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808003E0: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808003E4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808003E8: jal         0x800136E4
    // 0x808003EC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x808003EC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_1:
    // 0x808003F0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808003F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003F8: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808003FC: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80800400: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800404: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800408: nop

    // 0x8080040C: bc1fl       L_80800634
    if (!c1cs) {
        // 0x80800410: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800634;
    }
    goto skip_1;
    // 0x80800410: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800414: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800418: jal         0x800F13C4
    // 0x8080041C: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    func_800F13C4(rdram, ctx);
        goto after_2;
    // 0x8080041C: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    after_2:
    // 0x80800420: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800424: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800428: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8080042C: jal         0x800F13C4
    // 0x80800430: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    func_800F13C4(rdram, ctx);
        goto after_3;
    // 0x80800430: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    after_3:
    // 0x80800434: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800438: lui         $a3, 0x468C
    ctx->r7 = S32(0X468C << 16);
    // 0x8080043C: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80800440: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800444: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800448: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    // 0x8080044C: bc1fl       L_808005A4
    if (!c1cs) {
        // 0x80800450: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_808005A4;
    }
    goto skip_2;
    // 0x80800450: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    skip_2:
    // 0x80800454: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800458: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2492, 0X974) << 16);
    // 0x8080045C: lwc1        $f16, 0x974($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2492, 0X974));
    // 0x80800460: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800464: jal         0x800F10B4
    // 0x80800468: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800468: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8080046C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800470: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800474: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2492, 0X978) << 16);
    // 0x80800478: lwc1        $f18, 0x978($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2492, 0X978));
    // 0x8080047C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800480: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800484: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80800488: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080048C: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    // 0x80800490: jal         0x800F10B4
    // 0x80800494: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800494: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80800498: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2492, 0X97C) << 16);
    // 0x8080049C: lwc1        $f12, 0x97C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2492, 0X97C));
    // 0x808004A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2492, 0X980) << 16);
    // 0x808004A4: lwc1        $f14, 0x980($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2492, 0X980));
    // 0x808004A8: jal         0x800DC178
    // 0x808004AC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808004AC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x808004B0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808004B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2492, 0X984) << 16);
    // 0x808004B8: lwc1        $f8, 0x984($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2492, 0X984));
    // 0x808004BC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808004C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808004C4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808004C8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808004CC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808004D0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808004D4: nop

    // 0x808004D8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x808004DC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808004E0: nop

    // 0x808004E4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x808004E8: beql        $t7, $zero, L_80800538
    if (ctx->r15 == 0) {
        // 0x808004EC: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_80800538;
    }
    goto skip_3;
    // 0x808004EC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x808004F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808004F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808004F8: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808004FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800500: nop

    // 0x80800504: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800508: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8080050C: nop

    // 0x80800510: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800514: bne         $t7, $zero, L_8080052C
    if (ctx->r15 != 0) {
        // 0x80800518: nop
    
            goto L_8080052C;
    }
    // 0x80800518: nop

    // 0x8080051C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80800520: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800524: b           L_80800544
    // 0x80800528: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80800544;
    // 0x80800528: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8080052C:
    // 0x8080052C: b           L_80800544
    // 0x80800530: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80800544;
    // 0x80800530: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800534: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_80800538:
    // 0x80800538: nop

    // 0x8080053C: bltz        $t7, L_8080052C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800540: nop
    
            goto L_8080052C;
    }
    // 0x80800540: nop

L_80800544:
    // 0x80800544: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800548: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080054C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800550: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800554: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800558: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x8080055C: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x80800560: ori         $a2, $a2, 0xC8
    ctx->r6 = ctx->r6 | 0XC8;
    // 0x80800564: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80800568: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080056C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80800570: nop

    // 0x80800574: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800578: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080057C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800580: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80800584: nop

    // 0x80800588: sra         $t4, $t3, 5
    ctx->r12 = S32(SIGNED(ctx->r11) >> 5);
    // 0x8080058C: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x80800590: sll         $t6, $t5, 11
    ctx->r14 = S32(ctx->r13 << 11);
    // 0x80800594: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x80800598: jal         0x800C4140
    // 0x8080059C: addiu       $a0, $a0, 0x3FF
    ctx->r4 = ADD32(ctx->r4, 0X3FF);
    func_800C4140(rdram, ctx);
        goto after_7;
    // 0x8080059C: addiu       $a0, $a0, 0x3FF
    ctx->r4 = ADD32(ctx->r4, 0X3FF);
    after_7:
    // 0x808005A0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
L_808005A4:
    // 0x808005A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005B0: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808005B4: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x808005B8: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x808005BC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x808005C0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808005C4: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    // 0x808005C8: jal         0x800F10B4
    // 0x808005CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808005CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x808005D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005D4: jal         0x80089D30
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808005DC: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808005E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2492, 0X988) << 16);
    // 0x808005E8: lwc1        $f6, 0x988($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2492, 0X988));
    // 0x808005EC: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808005F0: lui         $a3, 0x468C
    ctx->r7 = S32(0X468C << 16);
    // 0x808005F4: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x808005F8: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    // 0x808005FC: jal         0x800F10B4
    // 0x80800600: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x80800600: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80800604: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080060C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800610: jal         0x80089D38
    // 0x80800614: nop

    _subaddieaudioloop_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800614: nop

    after_11:
    // 0x80800618: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2492, 0X9E0) << 16);
    // 0x8080061C: addiu       $a3, $a3, 0x9E0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2492, 0X9E0));
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800624: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800628: jal         0x80089D50
    // 0x8080062C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x8080062C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80800630: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800634:
    // 0x80800634: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800638: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080063C: jr          $ra
    // 0x80800640: nop

    return;
    // 0x80800640: nop

;}
RECOMP_FUNC void func_801028C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801028C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801028C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801028CC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801028D0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801028D4: jal         0x80102D78
    // 0x801028D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80102D78(rdram, ctx);
        goto after_0;
    // 0x801028D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801028DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801028E0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x801028E4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    // 0x801028E8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801028EC: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    // 0x801028F0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x801028F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801028F8: jal         0x800F1FF0
    // 0x801028FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_1;
    // 0x801028FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80102900: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80102904: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80102908: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x8010290C: jal         0x800F2094
    // 0x80102910: lwc1        $f14, 0x54($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X54);
    func_800F2094(rdram, ctx);
        goto after_2;
    // 0x80102910: lwc1        $f14, 0x54($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X54);
    after_2:
    // 0x80102914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80102918: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010291C: jr          $ra
    // 0x80102920: nop

    return;
    // 0x80102920: nop

;}
RECOMP_FUNC void chattract_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003E0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(812, 0X540) << 16);
    // 0x808003E4: addiu       $a1, $a1, 0x540
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(812, 0X540));
    // 0x808003E8: addiu       $a0, $zero, 0x4B5
    ctx->r4 = ADD32(0, 0X4B5);
    // 0x808003EC: jal         0x80108454
    // 0x808003F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108454(rdram, ctx);
        goto after_0;
    // 0x808003F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808003F4: beq         $v0, $zero, L_8080042C
    if (ctx->r2 == 0) {
        // 0x808003F8: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_8080042C;
    }
    // 0x808003F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808003FC: lhu         $t1, 0x76($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X76);
    // 0x80800400: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80800404: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800408: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x8080040C: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80800410: sh          $t3, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r11;
    // 0x80800414: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80800418: lhu         $t4, 0x12($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X12);
    // 0x8080041C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80800420: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x80800424: jal         0x800EC828
    // 0x80800428: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
    func_800EC828(rdram, ctx);
        goto after_1;
    // 0x80800428: sh          $t6, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r14;
    after_1:
L_8080042C:
    // 0x8080042C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800434: jr          $ra
    // 0x80800438: nop

    return;
    // 0x80800438: nop

    // 0x8080043C: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x808000B4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x808000B8: jr          $ra
    // 0x808000BC: sb          $a1, -0x4BFB($at)
    MEM_B(-0X4BFB, ctx->r1) = ctx->r5;
    return;
    // 0x808000BC: sb          $a1, -0x4BFB($at)
    MEM_B(-0X4BFB, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_8080000C_chcheatopage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: jal         0x80103110
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: jal         0x800DA298
    // 0x80800028: addiu       $a0, $zero, 0x666
    ctx->r4 = ADD32(0, 0X666);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a0, $zero, 0x666
    ctx->r4 = ADD32(0, 0X666);
    after_1:
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: jal         0x8010A5B0
    // 0x80800034: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    func_8010A5B0(rdram, ctx);
        goto after_2;
    // 0x80800034: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    after_2:
    // 0x80800038: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x8080003C: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800040: bgezl       $t8, L_80800060
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800044: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800060;
    }
    goto skip_0;
    // 0x80800044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800048: jal         0x800FC660
    // 0x8080004C: addiu       $a0, $zero, 0x77
    ctx->r4 = ADD32(0, 0X77);
    func_800FC660(rdram, ctx);
        goto after_3;
    // 0x8080004C: addiu       $a0, $zero, 0x77
    ctx->r4 = ADD32(0, 0X77);
    after_3:
    // 0x80800050: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800054: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800058: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x8080005C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800060:
    // 0x80800060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D88: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D88);
    return;
    // 0x80087D8C: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void chboggykidshome_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1396, 0X4B0) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x4B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1396, 0X4B0));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x4B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1396, 0X4B0));
;}
RECOMP_FUNC void func_800A1364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1368: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A136C: addiu       $v0, $v0, 0x7090
    ctx->r2 = ADD32(ctx->r2, 0X7090);
    // 0x800A1370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1374: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800A1378: jal         0x800D517C
    // 0x800A137C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_800D517C(rdram, ctx);
        goto after_0;
    // 0x800A137C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_0:
    // 0x800A1380: jal         0x8009E958
    // 0x800A1384: nop

    func_8009E958(rdram, ctx);
        goto after_1;
    // 0x800A1384: nop

    after_1:
    // 0x800A1388: jal         0x800A1240
    // 0x800A138C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A1240(rdram, ctx);
        goto after_2;
    // 0x800A138C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800A1390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1398: jr          $ra
    // 0x800A139C: nop

    return;
    // 0x800A139C: nop

;}
RECOMP_FUNC void func_80800434_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800434: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800438: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080043C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800440: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80800444: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800448: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8080044C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800450: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800454: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800458: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080045C: jal         0x80100094
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800464: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80800468: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080046C: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80800470: sltiu       $at, $t7, 0xD
    ctx->r1 = ctx->r15 < 0XD ? 1 : 0;
    // 0x80800474: beq         $at, $zero, L_80800A64
    if (ctx->r1 == 0) {
        // 0x80800478: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800A64;
    }
    // 0x80800478: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080047C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X2300) << 16);
    // 0x80800480: addu        $at, $at, $t7
    gpr jr_addend_80800488 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800484: lw          $t7, 0x2300($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2336, 0X2300));
    // 0x80800488: jr          $t7
    // 0x8080048C: nop

    switch (jr_addend_80800488 >> 2) {
        case 0: goto L_80800490; break;
        case 1: goto L_80800A64; break;
        case 2: goto L_808008E4; break;
        case 3: goto L_808004C8; break;
        case 4: goto L_8080056C; break;
        case 5: goto L_808005B0; break;
        case 6: goto L_8080068C; break;
        case 7: goto L_80800880; break;
        case 8: goto L_80800890; break;
        case 9: goto L_808008A0; break;
        case 10: goto L_808008B0; break;
        case 11: goto L_80800900; break;
        case 12: goto L_80800954; break;
        default: switch_error(__func__, 0x80800488, 0x80802300);
    }
    // 0x8080048C: nop

L_80800490:
    // 0x80800490: jal         0x800DA544
    // 0x80800494: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800494: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    after_1:
    // 0x80800498: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080049C: jal         0x80108B04
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808004A4: sb          $zero, 0x65($s1)
    MEM_B(0X65, ctx->r17) = 0;
    // 0x808004A8: sb          $zero, 0x66($s1)
    MEM_B(0X66, ctx->r17) = 0;
    // 0x808004AC: sb          $zero, 0x64($s1)
    MEM_B(0X64, ctx->r17) = 0;
    // 0x808004B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004B8: jal         0x80802124
    // 0x808004BC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80802124_chpotogoldgame(rdram, ctx);
        goto after_3;
    // 0x808004BC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_3:
    // 0x808004C0: b           L_80800A68
    // 0x808004C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x808004C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808004C8:
    // 0x808004C8: jal         0x800D211C
    // 0x808004CC: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_4;
    // 0x808004CC: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_4:
    // 0x808004D0: addiu       $s2, $zero, 0x64
    ctx->r18 = ADD32(0, 0X64);
    // 0x808004D4: bne         $v0, $s2, L_808004E4
    if (ctx->r2 != ctx->r18) {
        // 0x808004D8: addiu       $a0, $zero, 0x49
        ctx->r4 = ADD32(0, 0X49);
            goto L_808004E4;
    }
    // 0x808004D8: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x808004DC: b           L_8080052C
    // 0x808004E0: addiu       $s0, $zero, 0x1425
    ctx->r16 = ADD32(0, 0X1425);
        goto L_8080052C;
    // 0x808004E0: addiu       $s0, $zero, 0x1425
    ctx->r16 = ADD32(0, 0X1425);
L_808004E4:
    // 0x808004E4: jal         0x800D0A9C
    // 0x808004E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_5;
    // 0x808004E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808004EC: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004F0: addiu       $a0, $zero, 0x17
        ctx->r4 = ADD32(0, 0X17);
            goto L_808004FC;
    }
    // 0x808004F0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x808004F4: b           L_8080052C
    // 0x808004F8: addiu       $s0, $zero, 0x13D1
    ctx->r16 = ADD32(0, 0X13D1);
        goto L_8080052C;
    // 0x808004F8: addiu       $s0, $zero, 0x13D1
    ctx->r16 = ADD32(0, 0X13D1);
L_808004FC:
    // 0x808004FC: jal         0x800D0A9C
    // 0x80800500: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_6;
    // 0x80800500: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800504: beq         $v0, $zero, L_80800514
    if (ctx->r2 == 0) {
        // 0x80800508: nop
    
            goto L_80800514;
    }
    // 0x80800508: nop

    // 0x8080050C: b           L_8080052C
    // 0x80800510: addiu       $s0, $zero, 0x13D0
    ctx->r16 = ADD32(0, 0X13D0);
        goto L_8080052C;
    // 0x80800510: addiu       $s0, $zero, 0x13D0
    ctx->r16 = ADD32(0, 0X13D0);
L_80800514:
    // 0x80800514: jal         0x800DA298
    // 0x80800518: addiu       $a0, $zero, 0x1E2
    ctx->r4 = ADD32(0, 0X1E2);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800518: addiu       $a0, $zero, 0x1E2
    ctx->r4 = ADD32(0, 0X1E2);
    after_7:
    // 0x8080051C: beq         $v0, $zero, L_8080052C
    if (ctx->r2 == 0) {
        // 0x80800520: addiu       $s0, $zero, 0x13CD
        ctx->r16 = ADD32(0, 0X13CD);
            goto L_8080052C;
    }
    // 0x80800520: addiu       $s0, $zero, 0x13CD
    ctx->r16 = ADD32(0, 0X13CD);
    // 0x80800524: b           L_8080052C
    // 0x80800528: addiu       $s0, $zero, 0x13CF
    ctx->r16 = ADD32(0, 0X13CF);
        goto L_8080052C;
    // 0x80800528: addiu       $s0, $zero, 0x13CF
    ctx->r16 = ADD32(0, 0X13CF);
L_8080052C:
    // 0x8080052C: jal         0x800F54E4
    // 0x80800530: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800530: nop

    after_8:
    // 0x80800534: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800538: jal         0x800F8294
    // 0x8080053C: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    func_800F8294(rdram, ctx);
        goto after_9;
    // 0x8080053C: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    after_9:
    // 0x80800540: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800544: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800548: jal         0x8080219C
    // 0x8080054C: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_8080219C_chpotogoldgame(rdram, ctx);
        goto after_10;
    // 0x8080054C: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_10:
    // 0x80800550: sb          $zero, 0x65($s1)
    MEM_B(0X65, ctx->r17) = 0;
    // 0x80800554: sb          $zero, 0x66($s1)
    MEM_B(0X66, ctx->r17) = 0;
    // 0x80800558: sb          $zero, 0x64($s1)
    MEM_B(0X64, ctx->r17) = 0;
    // 0x8080055C: lbu         $t8, 0x65($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X65);
    // 0x80800560: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x80800564: b           L_80800A64
    // 0x80800568: sb          $t9, 0x65($s5)
    MEM_B(0X65, ctx->r21) = ctx->r25;
        goto L_80800A64;
    // 0x80800568: sb          $t9, 0x65($s5)
    MEM_B(0X65, ctx->r21) = ctx->r25;
L_8080056C:
    // 0x8080056C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800570: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800574: jal         0x8080219C
    // 0x80800578: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_8080219C_chpotogoldgame(rdram, ctx);
        goto after_11;
    // 0x80800578: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_11:
    // 0x8080057C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800580: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80800584: jal         0x800CE8D8
    // 0x80800588: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    func_800CE8D8(rdram, ctx);
        goto after_12;
    // 0x80800588: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    after_12:
    // 0x8080058C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800590: addiu       $a1, $a1, 0x75A8
    ctx->r5 = ADD32(ctx->r5, 0X75A8);
    // 0x80800594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800598: jal         0x800CE928
    // 0x8080059C: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    func_800CE928(rdram, ctx);
        goto after_13;
    // 0x8080059C: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    after_13:
    // 0x808005A0: jal         0x80088178
    // 0x808005A4: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_14;
    // 0x808005A4: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_14:
    // 0x808005A8: b           L_80800A68
    // 0x808005AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x808005AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808005B0:
    // 0x808005B0: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2336, 0X24F0) << 16);
    // 0x808005B4: addiu       $t1, $t1, 0x24F0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2336, 0X24F0));
    // 0x808005B8: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x808005BC: addiu       $t0, $sp, 0x5C
    ctx->r8 = ADD32(ctx->r29, 0X5C);
    // 0x808005C0: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x808005C4: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x808005C8: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x808005CC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808005D0: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x808005D4: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x808005D8: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x808005DC: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x808005E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_808005E4:
    // 0x808005E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808005E8:
    // 0x808005E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808005EC:
    // 0x808005EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808005F0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808005F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808005F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808005FC: jal         0x808013BC
    // 0x80800600: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_808013BC_chpotogoldgame(rdram, ctx);
        goto after_15;
    // 0x80800600: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_15:
    // 0x80800604: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800608: bnel        $s0, $s3, L_808005EC
    if (ctx->r16 != ctx->r19) {
        // 0x8080060C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808005EC;
    }
    goto skip_0;
    // 0x8080060C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x80800610: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800614: bnel        $s1, $s4, L_808005E8
    if (ctx->r17 != ctx->r20) {
        // 0x80800618: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808005E8;
    }
    goto skip_1;
    // 0x80800618: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_1:
    // 0x8080061C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800620: bnel        $s2, $s3, L_808005E4
    if (ctx->r18 != ctx->r19) {
        // 0x80800624: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_808005E4;
    }
    goto skip_2;
    // 0x80800624: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_2:
    // 0x80800628: jal         0x808011DC
    // 0x8080062C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_808011DC_chpotogoldgame(rdram, ctx);
        goto after_16;
    // 0x8080062C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_16:
    // 0x80800630: jal         0x8080227C
    // 0x80800634: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8080227C_chpotogoldgame(rdram, ctx);
        goto after_17;
    // 0x80800634: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_17:
    // 0x80800638: jal         0x800F54E4
    // 0x8080063C: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x8080063C: nop

    after_18:
    // 0x80800640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800644: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x80800648: jal         0x800F7C0C
    // 0x8080064C: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    func_800F7C0C(rdram, ctx);
        goto after_19;
    // 0x8080064C: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_19:
    // 0x80800650: jal         0x800F54E4
    // 0x80800654: nop

    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x80800654: nop

    after_20:
    // 0x80800658: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080065C: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x80800660: jal         0x800F7CF4
    // 0x80800664: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800F7CF4(rdram, ctx);
        goto after_21;
    // 0x80800664: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_21:
    // 0x80800668: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080066C: jal         0x800CE88C
    // 0x80800670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_22;
    // 0x80800670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80800674: jal         0x800FDC28
    // 0x80800678: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800FDC28(rdram, ctx);
        goto after_23;
    // 0x80800678: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_23:
    // 0x8080067C: jal         0x800DA544
    // 0x80800680: addiu       $a0, $zero, 0x1E2
    ctx->r4 = ADD32(0, 0X1E2);
    func_800DA544(rdram, ctx);
        goto after_24;
    // 0x80800680: addiu       $a0, $zero, 0x1E2
    ctx->r4 = ADD32(0, 0X1E2);
    after_24:
    // 0x80800684: b           L_80800A68
    // 0x80800688: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x80800688: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8080068C:
    // 0x8080068C: jal         0x8080206C
    // 0x80800690: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_25;
    // 0x80800690: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_25:
    // 0x80800694: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800698: jal         0x800D211C
    // 0x8080069C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_26;
    // 0x8080069C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_26:
    // 0x808006A0: addiu       $s2, $zero, 0x64
    ctx->r18 = ADD32(0, 0X64);
    // 0x808006A4: bne         $v0, $s2, L_80800724
    if (ctx->r2 != ctx->r18) {
        // 0x808006A8: addiu       $a0, $zero, 0x49
        ctx->r4 = ADD32(0, 0X49);
            goto L_80800724;
    }
    // 0x808006A8: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x808006AC: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    // 0x808006B0: beq         $at, $zero, L_808006C8
    if (ctx->r1 == 0) {
        // 0x808006B4: nop
    
            goto L_808006C8;
    }
    // 0x808006B4: nop

    // 0x808006B8: jal         0x800FC6B0
    // 0x808006BC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_27;
    // 0x808006BC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_27:
    // 0x808006C0: b           L_8080084C
    // 0x808006C4: addiu       $a1, $zero, 0x141E
    ctx->r5 = ADD32(0, 0X141E);
        goto L_8080084C;
    // 0x808006C4: addiu       $a1, $zero, 0x141E
    ctx->r5 = ADD32(0, 0X141E);
L_808006C8:
    // 0x808006C8: jal         0x800D211C
    // 0x808006CC: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_800D211C(rdram, ctx);
        goto after_28;
    // 0x808006CC: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_28:
    // 0x808006D0: lw          $t4, 0x20($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X20);
    // 0x808006D4: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808006D8: beq         $at, $zero, L_808006F0
    if (ctx->r1 == 0) {
        // 0x808006DC: nop
    
            goto L_808006F0;
    }
    // 0x808006DC: nop

    // 0x808006E0: jal         0x800FC6B0
    // 0x808006E4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_29;
    // 0x808006E4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_29:
    // 0x808006E8: b           L_8080084C
    // 0x808006EC: addiu       $a1, $zero, 0x1421
    ctx->r5 = ADD32(0, 0X1421);
        goto L_8080084C;
    // 0x808006EC: addiu       $a1, $zero, 0x1421
    ctx->r5 = ADD32(0, 0X1421);
L_808006F0:
    // 0x808006F0: jal         0x800D211C
    // 0x808006F4: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_800D211C(rdram, ctx);
        goto after_30;
    // 0x808006F4: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_30:
    // 0x808006F8: lw          $t5, 0x20($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X20);
    // 0x808006FC: bne         $v0, $t5, L_80800714
    if (ctx->r2 != ctx->r13) {
        // 0x80800700: nop
    
            goto L_80800714;
    }
    // 0x80800700: nop

    // 0x80800704: jal         0x800FC6B0
    // 0x80800708: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_31;
    // 0x80800708: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_31:
    // 0x8080070C: b           L_8080084C
    // 0x80800710: addiu       $a1, $zero, 0x1420
    ctx->r5 = ADD32(0, 0X1420);
        goto L_8080084C;
    // 0x80800710: addiu       $a1, $zero, 0x1420
    ctx->r5 = ADD32(0, 0X1420);
L_80800714:
    // 0x80800714: jal         0x800FC6B0
    // 0x80800718: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_32;
    // 0x80800718: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_32:
    // 0x8080071C: b           L_8080084C
    // 0x80800720: addiu       $a1, $zero, 0x141F
    ctx->r5 = ADD32(0, 0X141F);
        goto L_8080084C;
    // 0x80800720: addiu       $a1, $zero, 0x141F
    ctx->r5 = ADD32(0, 0X141F);
L_80800724:
    // 0x80800724: jal         0x800D0A9C
    // 0x80800728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_33;
    // 0x80800728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x8080072C: beq         $v0, $zero, L_808007A0
    if (ctx->r2 == 0) {
        // 0x80800730: addiu       $a0, $zero, 0x17
        ctx->r4 = ADD32(0, 0X17);
            goto L_808007A0;
    }
    // 0x80800730: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80800734: jal         0x800D211C
    // 0x80800738: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_34;
    // 0x80800738: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_34:
    // 0x8080073C: bne         $v0, $s0, L_80800754
    if (ctx->r2 != ctx->r16) {
        // 0x80800740: nop
    
            goto L_80800754;
    }
    // 0x80800740: nop

    // 0x80800744: jal         0x800FC6B0
    // 0x80800748: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_35;
    // 0x80800748: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_35:
    // 0x8080074C: b           L_8080084C
    // 0x80800750: addiu       $a1, $zero, 0x13D9
    ctx->r5 = ADD32(0, 0X13D9);
        goto L_8080084C;
    // 0x80800750: addiu       $a1, $zero, 0x13D9
    ctx->r5 = ADD32(0, 0X13D9);
L_80800754:
    // 0x80800754: jal         0x800D211C
    // 0x80800758: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_36;
    // 0x80800758: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_36:
    // 0x8080075C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800760: beq         $at, $zero, L_80800778
    if (ctx->r1 == 0) {
        // 0x80800764: nop
    
            goto L_80800778;
    }
    // 0x80800764: nop

    // 0x80800768: jal         0x800FC6B0
    // 0x8080076C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_37;
    // 0x8080076C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_37:
    // 0x80800770: b           L_8080084C
    // 0x80800774: addiu       $a1, $zero, 0x13D7
    ctx->r5 = ADD32(0, 0X13D7);
        goto L_8080084C;
    // 0x80800774: addiu       $a1, $zero, 0x13D7
    ctx->r5 = ADD32(0, 0X13D7);
L_80800778:
    // 0x80800778: bne         $s0, $s2, L_80800790
    if (ctx->r16 != ctx->r18) {
        // 0x8080077C: nop
    
            goto L_80800790;
    }
    // 0x8080077C: nop

    // 0x80800780: jal         0x800FC6B0
    // 0x80800784: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_38;
    // 0x80800784: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_38:
    // 0x80800788: b           L_8080084C
    // 0x8080078C: addiu       $a1, $zero, 0x1422
    ctx->r5 = ADD32(0, 0X1422);
        goto L_8080084C;
    // 0x8080078C: addiu       $a1, $zero, 0x1422
    ctx->r5 = ADD32(0, 0X1422);
L_80800790:
    // 0x80800790: jal         0x800FC6B0
    // 0x80800794: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_39;
    // 0x80800794: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_39:
    // 0x80800798: b           L_8080084C
    // 0x8080079C: addiu       $a1, $zero, 0x13D8
    ctx->r5 = ADD32(0, 0X13D8);
        goto L_8080084C;
    // 0x8080079C: addiu       $a1, $zero, 0x13D8
    ctx->r5 = ADD32(0, 0X13D8);
L_808007A0:
    // 0x808007A0: jal         0x800D0A9C
    // 0x808007A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_40;
    // 0x808007A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_40:
    // 0x808007A8: beq         $v0, $zero, L_808007F4
    if (ctx->r2 == 0) {
        // 0x808007AC: slti        $at, $s0, 0x4B
        ctx->r1 = SIGNED(ctx->r16) < 0X4B ? 1 : 0;
            goto L_808007F4;
    }
    // 0x808007AC: slti        $at, $s0, 0x4B
    ctx->r1 = SIGNED(ctx->r16) < 0X4B ? 1 : 0;
    // 0x808007B0: slti        $at, $s0, 0x5A
    ctx->r1 = SIGNED(ctx->r16) < 0X5A ? 1 : 0;
    // 0x808007B4: beq         $at, $zero, L_808007CC
    if (ctx->r1 == 0) {
        // 0x808007B8: nop
    
            goto L_808007CC;
    }
    // 0x808007B8: nop

    // 0x808007BC: jal         0x800FC6B0
    // 0x808007C0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_41;
    // 0x808007C0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_41:
    // 0x808007C4: b           L_8080084C
    // 0x808007C8: addiu       $a1, $zero, 0x13D5
    ctx->r5 = ADD32(0, 0X13D5);
        goto L_8080084C;
    // 0x808007C8: addiu       $a1, $zero, 0x13D5
    ctx->r5 = ADD32(0, 0X13D5);
L_808007CC:
    // 0x808007CC: bne         $s0, $s2, L_808007E4
    if (ctx->r16 != ctx->r18) {
        // 0x808007D0: nop
    
            goto L_808007E4;
    }
    // 0x808007D0: nop

    // 0x808007D4: jal         0x800FC6B0
    // 0x808007D8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_42;
    // 0x808007D8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_42:
    // 0x808007DC: b           L_8080084C
    // 0x808007E0: addiu       $a1, $zero, 0x1423
    ctx->r5 = ADD32(0, 0X1423);
        goto L_8080084C;
    // 0x808007E0: addiu       $a1, $zero, 0x1423
    ctx->r5 = ADD32(0, 0X1423);
L_808007E4:
    // 0x808007E4: jal         0x800FC6B0
    // 0x808007E8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_43;
    // 0x808007E8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_43:
    // 0x808007EC: b           L_8080084C
    // 0x808007F0: addiu       $a1, $zero, 0x13D6
    ctx->r5 = ADD32(0, 0X13D6);
        goto L_8080084C;
    // 0x808007F0: addiu       $a1, $zero, 0x13D6
    ctx->r5 = ADD32(0, 0X13D6);
L_808007F4:
    // 0x808007F4: beql        $at, $zero, L_80800810
    if (ctx->r1 == 0) {
        // 0x808007F8: slti        $at, $s0, 0x5A
        ctx->r1 = SIGNED(ctx->r16) < 0X5A ? 1 : 0;
            goto L_80800810;
    }
    goto skip_3;
    // 0x808007F8: slti        $at, $s0, 0x5A
    ctx->r1 = SIGNED(ctx->r16) < 0X5A ? 1 : 0;
    skip_3:
    // 0x808007FC: jal         0x800FC6B0
    // 0x80800800: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_44;
    // 0x80800800: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_44:
    // 0x80800804: b           L_8080084C
    // 0x80800808: addiu       $a1, $zero, 0x13D2
    ctx->r5 = ADD32(0, 0X13D2);
        goto L_8080084C;
    // 0x80800808: addiu       $a1, $zero, 0x13D2
    ctx->r5 = ADD32(0, 0X13D2);
    // 0x8080080C: slti        $at, $s0, 0x5A
    ctx->r1 = SIGNED(ctx->r16) < 0X5A ? 1 : 0;
L_80800810:
    // 0x80800810: beq         $at, $zero, L_80800828
    if (ctx->r1 == 0) {
        // 0x80800814: nop
    
            goto L_80800828;
    }
    // 0x80800814: nop

    // 0x80800818: jal         0x800FC6B0
    // 0x8080081C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_45;
    // 0x8080081C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_45:
    // 0x80800820: b           L_8080084C
    // 0x80800824: addiu       $a1, $zero, 0x13D3
    ctx->r5 = ADD32(0, 0X13D3);
        goto L_8080084C;
    // 0x80800824: addiu       $a1, $zero, 0x13D3
    ctx->r5 = ADD32(0, 0X13D3);
L_80800828:
    // 0x80800828: bne         $s0, $s2, L_80800840
    if (ctx->r16 != ctx->r18) {
        // 0x8080082C: nop
    
            goto L_80800840;
    }
    // 0x8080082C: nop

    // 0x80800830: jal         0x800FC6B0
    // 0x80800834: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_46;
    // 0x80800834: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_46:
    // 0x80800838: b           L_8080084C
    // 0x8080083C: addiu       $a1, $zero, 0x1424
    ctx->r5 = ADD32(0, 0X1424);
        goto L_8080084C;
    // 0x8080083C: addiu       $a1, $zero, 0x1424
    ctx->r5 = ADD32(0, 0X1424);
L_80800840:
    // 0x80800840: jal         0x800FC6B0
    // 0x80800844: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_47;
    // 0x80800844: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_47:
    // 0x80800848: addiu       $a1, $zero, 0x13D4
    ctx->r5 = ADD32(0, 0X13D4);
L_8080084C:
    // 0x8080084C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800850: jal         0x8080219C
    // 0x80800854: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_8080219C_chpotogoldgame(rdram, ctx);
        goto after_48;
    // 0x80800854: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_48:
    // 0x80800858: jal         0x800F54E4
    // 0x8080085C: nop

    func_800F54E4(rdram, ctx);
        goto after_49;
    // 0x8080085C: nop

    after_49:
    // 0x80800860: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800864: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x80800868: jal         0x800F7C0C
    // 0x8080086C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7C0C(rdram, ctx);
        goto after_50;
    // 0x8080086C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_50:
    // 0x80800870: jal         0x800FDC28
    // 0x80800874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_51;
    // 0x80800874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_51:
    // 0x80800878: b           L_80800A68
    // 0x8080087C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x8080087C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800880:
    // 0x80800880: jal         0x8080117C
    // 0x80800884: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8080117C_chpotogoldgame(rdram, ctx);
        goto after_52;
    // 0x80800884: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_52:
    // 0x80800888: b           L_80800A68
    // 0x8080088C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x8080088C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800890:
    // 0x80800890: jal         0x8080111C
    // 0x80800894: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8080111C_chpotogoldgame(rdram, ctx);
        goto after_53;
    // 0x80800894: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_53:
    // 0x80800898: b           L_80800A68
    // 0x8080089C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x8080089C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808008A0:
    // 0x808008A0: jal         0x8080117C
    // 0x808008A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8080117C_chpotogoldgame(rdram, ctx);
        goto after_54;
    // 0x808008A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_54:
    // 0x808008A8: b           L_80800A68
    // 0x808008AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x808008AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808008B0:
    // 0x808008B0: jal         0x800F54E4
    // 0x808008B4: nop

    func_800F54E4(rdram, ctx);
        goto after_55;
    // 0x808008B4: nop

    after_55:
    // 0x808008B8: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x808008BC: ori         $a1, $a1, 0x220
    ctx->r5 = ctx->r5 | 0X220;
    // 0x808008C0: jal         0x800F64A4
    // 0x808008C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F64A4(rdram, ctx);
        goto after_56;
    // 0x808008C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_56:
    // 0x808008C8: bne         $v0, $zero, L_80800A64
    if (ctx->r2 != 0) {
        // 0x808008CC: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800A64;
    }
    // 0x808008CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808008D0: addiu       $a1, $zero, 0x141D
    ctx->r5 = ADD32(0, 0X141D);
    // 0x808008D4: jal         0x8080219C
    // 0x808008D8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_8080219C_chpotogoldgame(rdram, ctx);
        goto after_57;
    // 0x808008D8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_57:
    // 0x808008DC: b           L_80800A68
    // 0x808008E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x808008E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808008E4:
    // 0x808008E4: jal         0x8080227C
    // 0x808008E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8080227C_chpotogoldgame(rdram, ctx);
        goto after_58;
    // 0x808008E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_58:
    // 0x808008EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808008F0: jal         0x80108B04
    // 0x808008F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_59;
    // 0x808008F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_59:
    // 0x808008F8: b           L_80800A68
    // 0x808008FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x808008FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800900:
    // 0x80800900: jal         0x800F54E4
    // 0x80800904: nop

    func_800F54E4(rdram, ctx);
        goto after_60;
    // 0x80800904: nop

    after_60:
    // 0x80800908: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080090C: jal         0x800F8294
    // 0x80800910: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    func_800F8294(rdram, ctx);
        goto after_61;
    // 0x80800910: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    after_61:
    // 0x80800914: jal         0x800D211C
    // 0x80800918: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_62;
    // 0x80800918: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_62:
    // 0x8080091C: addiu       $s2, $zero, 0x64
    ctx->r18 = ADD32(0, 0X64);
    // 0x80800920: bne         $v0, $s2, L_80800940
    if (ctx->r2 != ctx->r18) {
        // 0x80800924: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800940;
    }
    // 0x80800924: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800928: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080092C: addiu       $a1, $zero, 0x1439
    ctx->r5 = ADD32(0, 0X1439);
    // 0x80800930: jal         0x8080219C
    // 0x80800934: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_8080219C_chpotogoldgame(rdram, ctx);
        goto after_63;
    // 0x80800934: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_63:
    // 0x80800938: b           L_80800A68
    // 0x8080093C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x8080093C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800940:
    // 0x80800940: addiu       $a1, $zero, 0x1438
    ctx->r5 = ADD32(0, 0X1438);
    // 0x80800944: jal         0x8080219C
    // 0x80800948: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_8080219C_chpotogoldgame(rdram, ctx);
        goto after_64;
    // 0x80800948: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_64:
    // 0x8080094C: b           L_80800A68
    // 0x80800950: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80800A68;
    // 0x80800950: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800954:
    // 0x80800954: jal         0x8080206C
    // 0x80800958: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_65;
    // 0x80800958: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_65:
    // 0x8080095C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800960: jal         0x800D211C
    // 0x80800964: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_66;
    // 0x80800964: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_66:
    // 0x80800968: addiu       $s2, $zero, 0x64
    ctx->r18 = ADD32(0, 0X64);
    // 0x8080096C: bne         $v0, $s2, L_808009E8
    if (ctx->r2 != ctx->r18) {
        // 0x80800970: slti        $at, $s0, 0x64
        ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
            goto L_808009E8;
    }
    // 0x80800970: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    // 0x80800974: beq         $at, $zero, L_8080098C
    if (ctx->r1 == 0) {
        // 0x80800978: nop
    
            goto L_8080098C;
    }
    // 0x80800978: nop

    // 0x8080097C: jal         0x800FC6B0
    // 0x80800980: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_67;
    // 0x80800980: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_67:
    // 0x80800984: b           L_80800A50
    // 0x80800988: addiu       $a1, $zero, 0x143A
    ctx->r5 = ADD32(0, 0X143A);
        goto L_80800A50;
    // 0x80800988: addiu       $a1, $zero, 0x143A
    ctx->r5 = ADD32(0, 0X143A);
L_8080098C:
    // 0x8080098C: jal         0x800D211C
    // 0x80800990: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_800D211C(rdram, ctx);
        goto after_68;
    // 0x80800990: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_68:
    // 0x80800994: lw          $t6, 0x20($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X20);
    // 0x80800998: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080099C: beq         $at, $zero, L_808009B4
    if (ctx->r1 == 0) {
        // 0x808009A0: nop
    
            goto L_808009B4;
    }
    // 0x808009A0: nop

    // 0x808009A4: jal         0x800FC6B0
    // 0x808009A8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_69;
    // 0x808009A8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_69:
    // 0x808009AC: b           L_80800A50
    // 0x808009B0: addiu       $a1, $zero, 0x143D
    ctx->r5 = ADD32(0, 0X143D);
        goto L_80800A50;
    // 0x808009B0: addiu       $a1, $zero, 0x143D
    ctx->r5 = ADD32(0, 0X143D);
L_808009B4:
    // 0x808009B4: jal         0x800D211C
    // 0x808009B8: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_800D211C(rdram, ctx);
        goto after_70;
    // 0x808009B8: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_70:
    // 0x808009BC: lw          $t7, 0x20($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X20);
    // 0x808009C0: bne         $v0, $t7, L_808009D8
    if (ctx->r2 != ctx->r15) {
        // 0x808009C4: nop
    
            goto L_808009D8;
    }
    // 0x808009C4: nop

    // 0x808009C8: jal         0x800FC6B0
    // 0x808009CC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_71;
    // 0x808009CC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_71:
    // 0x808009D0: b           L_80800A50
    // 0x808009D4: addiu       $a1, $zero, 0x143C
    ctx->r5 = ADD32(0, 0X143C);
        goto L_80800A50;
    // 0x808009D4: addiu       $a1, $zero, 0x143C
    ctx->r5 = ADD32(0, 0X143C);
L_808009D8:
    // 0x808009D8: jal         0x800FC6B0
    // 0x808009DC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_72;
    // 0x808009DC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_72:
    // 0x808009E0: b           L_80800A50
    // 0x808009E4: addiu       $a1, $zero, 0x143B
    ctx->r5 = ADD32(0, 0X143B);
        goto L_80800A50;
    // 0x808009E4: addiu       $a1, $zero, 0x143B
    ctx->r5 = ADD32(0, 0X143B);
L_808009E8:
    // 0x808009E8: jal         0x800D211C
    // 0x808009EC: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_73;
    // 0x808009EC: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_73:
    // 0x808009F0: bne         $v0, $s0, L_80800A08
    if (ctx->r2 != ctx->r16) {
        // 0x808009F4: nop
    
            goto L_80800A08;
    }
    // 0x808009F4: nop

    // 0x808009F8: jal         0x800FC6B0
    // 0x808009FC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_74;
    // 0x808009FC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_74:
    // 0x80800A00: b           L_80800A50
    // 0x80800A04: addiu       $a1, $zero, 0x1440
    ctx->r5 = ADD32(0, 0X1440);
        goto L_80800A50;
    // 0x80800A04: addiu       $a1, $zero, 0x1440
    ctx->r5 = ADD32(0, 0X1440);
L_80800A08:
    // 0x80800A08: jal         0x800D211C
    // 0x80800A0C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_75;
    // 0x80800A0C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_75:
    // 0x80800A10: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800A14: beq         $at, $zero, L_80800A2C
    if (ctx->r1 == 0) {
        // 0x80800A18: nop
    
            goto L_80800A2C;
    }
    // 0x80800A18: nop

    // 0x80800A1C: jal         0x800FC6B0
    // 0x80800A20: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_76;
    // 0x80800A20: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_76:
    // 0x80800A24: b           L_80800A50
    // 0x80800A28: addiu       $a1, $zero, 0x143F
    ctx->r5 = ADD32(0, 0X143F);
        goto L_80800A50;
    // 0x80800A28: addiu       $a1, $zero, 0x143F
    ctx->r5 = ADD32(0, 0X143F);
L_80800A2C:
    // 0x80800A2C: bne         $s0, $s2, L_80800A44
    if (ctx->r16 != ctx->r18) {
        // 0x80800A30: nop
    
            goto L_80800A44;
    }
    // 0x80800A30: nop

    // 0x80800A34: jal         0x800FC6B0
    // 0x80800A38: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_77;
    // 0x80800A38: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_77:
    // 0x80800A3C: b           L_80800A50
    // 0x80800A40: addiu       $a1, $zero, 0x143E
    ctx->r5 = ADD32(0, 0X143E);
        goto L_80800A50;
    // 0x80800A40: addiu       $a1, $zero, 0x143E
    ctx->r5 = ADD32(0, 0X143E);
L_80800A44:
    // 0x80800A44: jal         0x800FC6B0
    // 0x80800A48: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_78;
    // 0x80800A48: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_78:
    // 0x80800A4C: addiu       $a1, $zero, 0x1441
    ctx->r5 = ADD32(0, 0X1441);
L_80800A50:
    // 0x80800A50: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800A54: jal         0x8080219C
    // 0x80800A58: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_8080219C_chpotogoldgame(rdram, ctx);
        goto after_79;
    // 0x80800A58: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_79:
    // 0x80800A5C: jal         0x800FDC28
    // 0x80800A60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_80;
    // 0x80800A60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_80:
L_80800A64:
    // 0x80800A64: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800A68:
    // 0x80800A68: jal         0x80101FDC
    // 0x80800A6C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_80101FDC(rdram, ctx);
        goto after_81;
    // 0x80800A6C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_81:
    // 0x80800A70: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800A74: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A78: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800A7C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800A80: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800A84: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A88: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800A8C: jr          $ra
    // 0x80800A90: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800A90: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void suspline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: beq         $a2, $zero, L_8080003C
    if (ctx->r6 == 0) {
        // 0x80800004: andi        $t4, $a1, 0x7
        ctx->r12 = ctx->r5 & 0X7;
            goto L_8080003C;
    }
    // 0x80800004: andi        $t4, $a1, 0x7
    ctx->r12 = ctx->r5 & 0X7;
    // 0x80800008: bgez        $a1, L_80800018
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8080000C: sra         $t6, $a1, 3
        ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
            goto L_80800018;
    }
    // 0x8080000C: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80800010: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x80800014: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_80800018:
    // 0x80800018: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8080001C: lbu         $t7, 0x7E($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X7E);
    // 0x80800020: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x80800024: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800028: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x8080002C: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80800030: sb          $t1, 0x7E($v0)
    MEM_B(0X7E, ctx->r2) = ctx->r9;
    // 0x80800034: jr          $ra
    // 0x80800038: addiu       $v0, $v0, 0x7E
    ctx->r2 = ADD32(ctx->r2, 0X7E);
    return;
    // 0x80800038: addiu       $v0, $v0, 0x7E
    ctx->r2 = ADD32(ctx->r2, 0X7E);
L_8080003C:
    // 0x8080003C: bgez        $a1, L_8080004C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80800040: sra         $t2, $a1, 3
        ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8080004C;
    }
    // 0x80800040: sra         $t2, $a1, 3
    ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80800044: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x80800048: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_8080004C:
    // 0x8080004C: addu        $v0, $a0, $t2
    ctx->r2 = ADD32(ctx->r4, ctx->r10);
    // 0x80800050: lbu         $t3, 0x7E($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X7E);
    // 0x80800054: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800058: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x8080005C: nor         $t9, $t6, $zero
    ctx->r25 = ~(ctx->r14 | 0);
    // 0x80800060: and         $t8, $t3, $t9
    ctx->r24 = ctx->r11 & ctx->r25;
    // 0x80800064: sb          $t8, 0x7E($v0)
    MEM_B(0X7E, ctx->r2) = ctx->r24;
    // 0x80800068: addiu       $v0, $v0, 0x7E
    ctx->r2 = ADD32(ctx->r2, 0X7E);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void func_808003B4_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003BC: jal         0x8009E6EC
    // 0x808003C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808003C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003C4: slti        $at, $v0, 0x52
    ctx->r1 = SIGNED(ctx->r2) < 0X52 ? 1 : 0;
    // 0x808003C8: bne         $at, $zero, L_808003EC
    if (ctx->r1 != 0) {
        // 0x808003CC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003EC;
    }
    // 0x808003CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003D0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808003D4: beq         $v0, $at, L_8080042C
    if (ctx->r2 == ctx->r1) {
        // 0x808003D8: addiu       $at, $zero, 0x82
        ctx->r1 = ADD32(0, 0X82);
            goto L_8080042C;
    }
    // 0x808003D8: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x808003DC: beq         $v0, $at, L_8080043C
    if (ctx->r2 == ctx->r1) {
        // 0x808003E0: nop
    
            goto L_8080043C;
    }
    // 0x808003E0: nop

    // 0x808003E4: b           L_8080045C
    // 0x808003E8: nop

        goto L_8080045C;
    // 0x808003E8: nop

L_808003EC:
    // 0x808003EC: slti        $at, $v0, 0x2F
    ctx->r1 = SIGNED(ctx->r2) < 0X2F ? 1 : 0;
    // 0x808003F0: bne         $at, $zero, L_8080040C
    if (ctx->r1 != 0) {
        // 0x808003F4: addiu       $t6, $v0, -0x20
        ctx->r14 = ADD32(ctx->r2, -0X20);
            goto L_8080040C;
    }
    // 0x808003F4: addiu       $t6, $v0, -0x20
    ctx->r14 = ADD32(ctx->r2, -0X20);
    // 0x808003F8: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x808003FC: beq         $v0, $at, L_8080042C
    if (ctx->r2 == ctx->r1) {
        // 0x80800400: nop
    
            goto L_8080042C;
    }
    // 0x80800400: nop

    // 0x80800404: b           L_8080045C
    // 0x80800408: nop

        goto L_8080045C;
    // 0x80800408: nop

L_8080040C:
    // 0x8080040C: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x80800410: beq         $at, $zero, L_8080045C
    if (ctx->r1 == 0) {
        // 0x80800414: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080045C;
    }
    // 0x80800414: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(372, 0X1520) << 16);
    // 0x8080041C: addu        $at, $at, $t6
    gpr jr_addend_80800424 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800420: lw          $t6, 0x1520($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(372, 0X1520));
    // 0x80800424: jr          $t6
    // 0x80800428: nop

    switch (jr_addend_80800424 >> 2) {
        case 0: goto L_8080042C; break;
        case 1: goto L_8080042C; break;
        case 2: goto L_8080045C; break;
        case 3: goto L_8080042C; break;
        case 4: goto L_8080042C; break;
        case 5: goto L_8080045C; break;
        case 6: goto L_8080045C; break;
        case 7: goto L_8080045C; break;
        case 8: goto L_8080045C; break;
        case 9: goto L_8080045C; break;
        case 10: goto L_8080045C; break;
        case 11: goto L_8080045C; break;
        case 12: goto L_8080045C; break;
        case 13: goto L_8080042C; break;
        case 14: goto L_8080042C; break;
        default: switch_error(__func__, 0x80800424, 0x80801520);
    }
    // 0x80800428: nop

L_8080042C:
    // 0x8080042C: jal         0x8009E830
    // 0x80800430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80800430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800434: b           L_80800468
    // 0x80800438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800468;
    // 0x80800438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080043C:
    // 0x8080043C: jal         0x8001211C
    // 0x80800440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x80800440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800444: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800448: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080044C: jal         0x8009E830
    // 0x80800450: sw          $v0, 0x168($a0)
    MEM_W(0X168, ctx->r4) = ctx->r2;
    func_8009E830(rdram, ctx);
        goto after_3;
    // 0x80800450: sw          $v0, 0x168($a0)
    MEM_W(0X168, ctx->r4) = ctx->r2;
    after_3:
    // 0x80800454: b           L_80800468
    // 0x80800458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800468;
    // 0x80800458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080045C:
    // 0x8080045C: jal         0x80099B94
    // 0x80800460: nop

    func_80099B94(rdram, ctx);
        goto after_4;
    // 0x80800460: nop

    after_4:
    // 0x80800464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800468:
    // 0x80800468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080046C: jr          $ra
    // 0x80800470: nop

    return;
    // 0x80800470: nop

;}
