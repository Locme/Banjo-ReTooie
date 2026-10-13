#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chworlddoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877C8: syscall     627
    recomp_syscall_handler(rdram, ctx, 0x800877C8);
    return;
    // 0x800877CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsdronesuckunder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080004C: jal         0x800961A0
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800961A0(rdram, ctx);
        goto after_0;
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void _bawandglow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853C0: syscall     160
    recomp_syscall_handler(rdram, ctx, 0x800853C0);
    return;
    // 0x800853C4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void dbskeleton_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: lh          $a3, 0x4($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X4);
    // 0x80800084: addiu       $a2, $a0, 0x8
    ctx->r6 = ADD32(ctx->r4, 0X8);
    // 0x80800088: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8080008C: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x80800090: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80800094: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80800098: sltu        $at, $a2, $t8
    ctx->r1 = ctx->r6 < ctx->r24 ? 1 : 0;
    // 0x8080009C: beq         $at, $zero, L_808000C8
    if (ctx->r1 == 0) {
        // 0x808000A0: or          $a3, $t6, $zero
        ctx->r7 = ctx->r14 | 0;
            goto L_808000C8;
    }
    // 0x808000A0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x808000A4: lh          $t9, 0xC($a2)
    ctx->r25 = MEM_H(ctx->r6, 0XC);
L_808000A8:
    // 0x808000A8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x808000AC: addu        $t0, $a3, $v0
    ctx->r8 = ADD32(ctx->r7, ctx->r2);
    // 0x808000B0: bne         $a1, $t9, L_808000C0
    if (ctx->r5 != ctx->r25) {
        // 0x808000B4: sltu        $at, $a2, $t0
        ctx->r1 = ctx->r6 < ctx->r8 ? 1 : 0;
            goto L_808000C0;
    }
    // 0x808000B4: sltu        $at, $a2, $t0
    ctx->r1 = ctx->r6 < ctx->r8 ? 1 : 0;
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808000BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C0:
    // 0x808000C0: bnel        $at, $zero, L_808000A8
    if (ctx->r1 != 0) {
        // 0x808000C4: lh          $t9, 0xC($a2)
        ctx->r25 = MEM_H(ctx->r6, 0XC);
            goto L_808000A8;
    }
    goto skip_0;
    // 0x808000C4: lh          $t9, 0xC($a2)
    ctx->r25 = MEM_H(ctx->r6, 0XC);
    skip_0:
L_808000C8:
    // 0x808000C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_800EC368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC368: jr          $ra
    // 0x800EC36C: sh          $a1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r5;
    return;
    // 0x800EC36C: sh          $a1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80808560_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808560: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80808564: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808568: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080856C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808570: jal         0x80100094
    // 0x80808574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808578: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080857C: jal         0x808086A8
    // 0x80808580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808086A8_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80808580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80808584: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80808588: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080858C: jal         0x80102FDC
    // 0x80808590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x80808590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80808594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808598: jal         0x80800180
    // 0x8080859C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x8080859C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
    // 0x808085A0: jal         0x808027F4
    // 0x808085A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808027F4_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x808085A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808085A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808085AC: jal         0x80109FE8
    // 0x808085B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_5;
    // 0x808085B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808085B4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808085B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808085BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808085C0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x808085C4: sb          $t6, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r14;
    // 0x808085C8: swc1        $f4, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->f4.u32l;
    // 0x808085CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808085D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808085D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808085D8: jr          $ra
    // 0x808085DC: nop

    return;
    // 0x808085DC: nop

;}
RECOMP_FUNC void func_80015ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015ECC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015ED0: addiu       $v0, $v0, -0x6540
    ctx->r2 = ADD32(ctx->r2, -0X6540);
    // 0x80015ED4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80015ED8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80015EDC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80015EE0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80015EE4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80015EE8: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80015EEC: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80015EF0: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80015EF4: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x80015EF8: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x80015EFC: sw          $t0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r8;
    // 0x80015F00: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x80015F04: jr          $ra
    // 0x80015F08: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    return;
    // 0x80015F08: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void bavan_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800014: addiu       $a1, $zero, 0x505
    ctx->r5 = ADD32(0, 0X505);
    // 0x80800018: jal         0x8009DE38
    // 0x8080001C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_0;
    // 0x8080001C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x80800020: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800024: jal         0x8009C128
    // 0x80800028: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8080002C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800030: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800034: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80800038: jal         0x801013A8
    // 0x8080003C: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    func_801013A8(rdram, ctx);
        goto after_2;
    // 0x8080003C: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    after_2:
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800044: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void chwaterfallgrillswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1936, 0X90) << 16);
    // 0x80800088: jr          $ra
    // 0x8080008C: addiu       $v0, $v0, 0x90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1936, 0X90));
    return;
    // 0x8080008C: addiu       $v0, $v0, 0x90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1936, 0X90));
;}
RECOMP_FUNC void func_800F7B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7B1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7B20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F7B24: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F7B28: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F7B2C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7B30: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x800F7B34: lw          $s0, 0x5490($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5490);
    // 0x800F7B38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F7B3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F7B40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F7B44: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800F7B48: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F7B4C: jal         0x8009ACF4
    // 0x800F7B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009ACF4(rdram, ctx);
        goto after_0;
    // 0x800F7B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800F7B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7B58: jal         0x8009AD04
    // 0x800F7B5C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8009AD04(rdram, ctx);
        goto after_1;
    // 0x800F7B5C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800F7B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7B64: jal         0x8009AD20
    // 0x800F7B68: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8009AD20(rdram, ctx);
        goto after_2;
    // 0x800F7B68: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x800F7B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7B70: jal         0x8009AD44
    // 0x800F7B74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009AD44(rdram, ctx);
        goto after_3;
    // 0x800F7B74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x800F7B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7B7C: jal         0x8009E7C8
    // 0x800F7B80: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    func_8009E7C8(rdram, ctx);
        goto after_4;
    // 0x800F7B80: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_4:
    // 0x800F7B84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7B88: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F7B8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F7B90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7B94: jr          $ra
    // 0x800F7B98: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    return;
    // 0x800F7B98: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_808010BC_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808010C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808010C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808010C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808010CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010D0: jal         0x80100094
    // 0x808010D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808010D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808010D8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808010DC: jal         0x800DA298
    // 0x808010E0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808010E0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x808010E4: bnel        $v0, $zero, L_80801154
    if (ctx->r2 != 0) {
        // 0x808010E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801154;
    }
    goto skip_0;
    // 0x808010E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808010EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808010F0: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x808010F4: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x808010F8: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x808010FC: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80801100: bne         $at, $zero, L_80801150
    if (ctx->r1 != 0) {
        // 0x80801104: slti        $at, $t7, 0xF
        ctx->r1 = SIGNED(ctx->r15) < 0XF ? 1 : 0;
            goto L_80801150;
    }
    // 0x80801104: slti        $at, $t7, 0xF
    ctx->r1 = SIGNED(ctx->r15) < 0XF ? 1 : 0;
    // 0x80801108: beq         $at, $zero, L_80801150
    if (ctx->r1 == 0) {
        // 0x8080110C: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_80801150;
    }
    // 0x8080110C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80801110: addiu       $v1, $t7, -0x3
    ctx->r3 = ADD32(ctx->r15, -0X3);
    // 0x80801114: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80801118: lbu         $t0, 0x487($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X487);
    // 0x8080111C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801120: addiu       $a1, $zero, 0x1086
    ctx->r5 = ADD32(0, 0X1086);
    // 0x80801124: beq         $t0, $at, L_80801150
    if (ctx->r8 == ctx->r1) {
        // 0x80801128: addiu       $a2, $zero, 0x10E
        ctx->r6 = ADD32(0, 0X10E);
            goto L_80801150;
    }
    // 0x80801128: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x8080112C: addiu       $t1, $zero, 0x3A
    ctx->r9 = ADD32(0, 0X3A);
    // 0x80801130: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801134: jal         0x8008A208
    // 0x80801138: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80801138: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x8080113C: jal         0x800DA544
    // 0x80801140: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80801140: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80801144: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80801148: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x8080114C: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
L_80801150:
    // 0x80801150: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801154:
    // 0x80801154: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080115C: jr          $ra
    // 0x80801160: nop

    return;
    // 0x80801160: nop

;}
RECOMP_FUNC void anseq_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001EC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(26, 0X494) << 16);
    // 0x808001F0: lw          $t6, 0x494($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(26, 0X494));
    // 0x808001F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808001F8: jr          $ra
    // 0x808001FC: sb          $a1, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r5;
    return;
    // 0x808001FC: sb          $a1, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800BEE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEE40: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800BEE44: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800BEE48: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BEE4C: addiu       $s0, $s0, -0x7A50
    ctx->r16 = ADD32(ctx->r16, -0X7A50);
    // 0x800BEE50: lbu         $t6, 0x2A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2A);
    // 0x800BEE54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BEE58: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800BEE5C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800BEE60: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800BEE64: beq         $t6, $zero, L_800BEEBC
    if (ctx->r14 == 0) {
        // 0x800BEE68: sw          $a3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r7;
            goto L_800BEEBC;
    }
    // 0x800BEE68: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800BEE6C: jal         0x800EFD24
    // 0x800BEE70: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800BEE70: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x800BEE74: lbu         $t7, 0x29($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X29);
    // 0x800BEE78: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800BEE7C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800BEE80: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BEE84: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800BEE88: lw          $a1, 0x10($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X10);
    // 0x800BEE8C: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x800BEE90: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800BEE94: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800BEE98: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800BEE9C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800BEEA0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800BEEA4: jal         0x800AD894
    // 0x800BEEA8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_800AD894(rdram, ctx);
        goto after_1;
    // 0x800BEEA8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800BEEAC: beql        $v0, $zero, L_800BEEC0
    if (ctx->r2 == 0) {
        // 0x800BEEB0: lbu         $t2, 0x77($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X77);
            goto L_800BEEC0;
    }
    goto skip_0;
    // 0x800BEEB0: lbu         $t2, 0x77($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X77);
    skip_0:
    // 0x800BEEB4: b           L_800BEEEC
    // 0x800BEEB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800BEEEC;
    // 0x800BEEB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800BEEBC:
    // 0x800BEEBC: lbu         $t2, 0x77($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X77);
L_800BEEC0:
    // 0x800BEEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BEEC4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800BEEC8: beq         $t2, $zero, L_800BEEEC
    if (ctx->r10 == 0) {
        // 0x800BEECC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BEEEC;
    }
    // 0x800BEECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BEED0: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800BEED4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800BEED8: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800BEEDC: jal         0x80087FA8
    // 0x800BEEE0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _gcmapsects_entrypoint_21(rdram, ctx);
        goto after_2;
    // 0x800BEEE0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800BEEE4: b           L_800BEEF0
    // 0x800BEEE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800BEEF0;
    // 0x800BEEE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BEEEC:
    // 0x800BEEEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BEEF0:
    // 0x800BEEF0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800BEEF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800BEEF8: jr          $ra
    // 0x800BEEFC: nop

    return;
    // 0x800BEEFC: nop

;}
RECOMP_FUNC void func_80800310_glsplinecs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800318: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080031C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800320: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800324: jal         0x80105494
    // 0x80800328: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80800328: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080032C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800330: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800334: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800338: sll         $t6, $a0, 21
    ctx->r14 = S32(ctx->r4 << 21);
    // 0x8080033C: sra         $a0, $t6, 22
    ctx->r4 = S32(SIGNED(ctx->r14) >> 22);
    // 0x80800340: jal         0x800D7520
    // 0x80800344: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    func_800D7520(rdram, ctx);
        goto after_1;
    // 0x80800344: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x80800348: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8080034C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2698, 0X15E4) << 16);
    // 0x80800350: lwc1        $f10, 0x15E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2698, 0X15E4));
    // 0x80800354: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80800358: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080035C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800360: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800364: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800368: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080036C: jal         0x800C7AE4
    // 0x80800370: nop

    func_800C7AE4(rdram, ctx);
        goto after_2;
    // 0x80800370: nop

    after_2:
    // 0x80800374: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800378: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080037C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800380: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80800384: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800388: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080038C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800390: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800394: swc1        $f10, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f10.u32l;
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080039C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void mlwave_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B0: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808001B4: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808001B8: jal         0x800F13C4
    // 0x808001BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F13C4(rdram, ctx);
        goto after_0;
    // 0x808001BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808001C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001CC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808001D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001D8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808001DC: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808001E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808001E4: bc1fl       L_808001FC
    if (!c1cs) {
        // 0x808001E8: lwc1        $f0, 0x8($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001E8: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x808001EC: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808001F0: b           L_808001FC
    // 0x808001F4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_808001FC;
    // 0x808001F4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x808001F8: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
L_808001FC:
    // 0x808001FC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800200: jal         0x800F10B4
    // 0x80800204: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800204: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080020C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void func_80800068_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080006C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800078: jal         0x8009E6C4
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E6C4(rdram, ctx);
        goto after_0;
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800080: bnel        $v0, $zero, L_808000F0
    if (ctx->r2 != 0) {
        // 0x80800084: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F0;
    }
    goto skip_0;
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800088: jal         0x800832E0
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: jal         0x8009BCB4
    // 0x80800098: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_2;
    // 0x80800098: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_2:
    // 0x8080009C: lui         $a1, 0x4305
    ctx->r5 = S32(0X4305 << 16);
    // 0x808000A0: ori         $a1, $a1, 0x547B
    ctx->r5 = ctx->r5 | 0X547B;
    // 0x808000A4: jal         0x8009BCC4
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000AC: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x808000B0: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x8009F1C8
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000C8: jal         0x8009F1C8
    // 0x808000CC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_5;
    // 0x808000CC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x800961AC
    // 0x808000D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_6;
    // 0x808000D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E0: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808000E4: jal         0x800A106C
    // 0x808000E8: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_800A106C(rdram, ctx);
        goto after_7;
    // 0x808000E8: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_7:
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F0:
    // 0x808000F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void basquash_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: lw          $t6, 0x11C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X11C);
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F8: sb          $zero, 0x2($t6)
    MEM_B(0X2, ctx->r14) = 0;
    // 0x808000FC: lw          $t7, 0x11C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X11C);
    // 0x80800100: jal         0x80800008
    // 0x80800104: sb          $zero, 0x1($t7)
    MEM_B(0X1, ctx->r15) = 0;
    func_80800008_basquash(rdram, ctx);
        goto after_0;
    // 0x80800104: sb          $zero, 0x1($t7)
    MEM_B(0X1, ctx->r15) = 0;
    after_0:
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080010C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void func_8080144C_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080144C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80801450: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x80801454: addiu       $s5, $sp, 0x8C
    ctx->r21 = ADD32(ctx->r29, 0X8C);
    // 0x80801458: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8080145C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80801460: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x80801464: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x80801468: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x8080146C: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80801470: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80801474: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80801478: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8080147C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801480: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801484: jal         0x8010D254
    // 0x80801488: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80801488: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x8080148C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801490: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801494: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1688, 0X26FC) << 16);
    // 0x80801498: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080149C: c.le.s      $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f26.fl <= ctx->f4.fl;
    // 0x808014A0: addiu       $s0, $s0, 0x26FC
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1688, 0X26FC));
    // 0x808014A4: bc1fl       L_808014C0
    if (!c1cs) {
        // 0x808014A8: mtc1        $at, $f20
        ctx->f20.u32l = ctx->r1;
            goto L_808014C0;
    }
    goto skip_0;
    // 0x808014A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    skip_0:
    // 0x808014AC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808014B0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808014B4: b           L_808014C4
    // 0x808014B8: nop

        goto L_808014C4;
    // 0x808014B8: nop

    // 0x808014BC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
L_808014C0:
    // 0x808014C0: nop

L_808014C4:
    // 0x808014C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X24C4) << 16);
    // 0x808014C8: lwc1        $f6, 0x24C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X24C4));
    // 0x808014CC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x808014D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808014D4: mul.s       $f22, $f6, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x808014D8: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(1688, 0X272C) << 16);
    // 0x808014DC: add.s       $f0, $f20, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x808014E0: addiu       $s4, $s4, 0x272C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(1688, 0X272C));
    // 0x808014E4: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x808014E8: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
    // 0x808014EC: mul.s       $f24, $f0, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x808014F0: addiu       $s1, $sp, 0x98
    ctx->r17 = ADD32(ctx->r29, 0X98);
    // 0x808014F4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
L_808014F8:
    // 0x808014F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808014FC: jal         0x800EFA20
    // 0x80801500: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x80801500: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80801504: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801508: jal         0x800EE7F8
    // 0x8080150C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080150C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80801510: swc1        $f22, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f22.u32l;
    // 0x80801514: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801518: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080151C: jal         0x800EFB24
    // 0x80801520: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x80801520: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x80801524: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80801528: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8080152C: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80801530: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80801534: lwc1        $f0, 0x90($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80801538: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8080153C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80801540: c.lt.s      $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f18.fl < ctx->f24.fl;
    // 0x80801544: nop

    // 0x80801548: bc1fl       L_808015A0
    if (!c1cs) {
        // 0x8080154C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808015A0;
    }
    goto skip_1;
    // 0x8080154C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x80801550: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801554: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80801558: bc1fl       L_808015A0
    if (!c1cs) {
        // 0x8080155C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808015A0;
    }
    goto skip_2;
    // 0x8080155C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_2:
    // 0x80801560: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80801564: nop

    // 0x80801568: bc1fl       L_808015A0
    if (!c1cs) {
        // 0x8080156C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808015A0;
    }
    goto skip_3;
    // 0x8080156C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_3:
    // 0x80801570: jal         0x800F54E4
    // 0x80801574: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80801574: nop

    after_4:
    // 0x80801578: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8080157C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801580: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801584: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801588: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080158C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801590: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801594: jal         0x800F7F50
    // 0x80801598: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800F7F50(rdram, ctx);
        goto after_5;
    // 0x80801598: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x8080159C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_808015A0:
    // 0x808015A0: bnel        $s0, $s4, L_808014F8
    if (ctx->r16 != ctx->r20) {
        // 0x808015A4: mfc1        $a2, $f26
        ctx->r6 = (int32_t)ctx->f26.u32l;
            goto L_808014F8;
    }
    goto skip_4;
    // 0x808015A4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    skip_4:
    // 0x808015A8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x808015AC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808015B0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808015B4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808015B8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808015BC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808015C0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808015C4: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x808015C8: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x808015CC: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x808015D0: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x808015D4: jr          $ra
    // 0x808015D8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x808015D8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void gczoombox_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808033B0: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x808033B4: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x808033B8: jr          $ra
    // 0x808033BC: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x808033BC: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800991B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800991B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800991B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800991B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800991BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800991C0: jal         0x800EA068
    // 0x800991C4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800EA068(rdram, ctx);
        goto after_0;
    // 0x800991C4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x800991C8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800991CC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800991D0: jal         0x800DA298
    // 0x800991D4: addiu       $a0, $zero, 0x6B5
    ctx->r4 = ADD32(0, 0X6B5);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x800991D4: addiu       $a0, $zero, 0x6B5
    ctx->r4 = ADD32(0, 0X6B5);
    after_1:
    // 0x800991D8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800991DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800991E0: jal         0x80091E80
    // 0x800991E4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80091E80(rdram, ctx);
        goto after_2;
    // 0x800991E4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_2:
    // 0x800991E8: beql        $v0, $zero, L_80099534
    if (ctx->r2 == 0) {
        // 0x800991EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80099534;
    }
    goto skip_0;
    // 0x800991EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800991F0: jal         0x80092AB0
    // 0x800991F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092AB0(rdram, ctx);
        goto after_3;
    // 0x800991F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800991F8: jal         0x80099970
    // 0x800991FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099970(rdram, ctx);
        goto after_4;
    // 0x800991FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80099200: jal         0x8009CF04
    // 0x80099204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CF04(rdram, ctx);
        goto after_5;
    // 0x80099204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80099208: jal         0x800917D4
    // 0x8009920C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastatetimerlist_update(rdram, ctx);
        goto after_6;
    // 0x8009920C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80099210: jal         0x800A0DDC
    // 0x80099214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0DDC(rdram, ctx);
        goto after_7;
    // 0x80099214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80099218: jal         0x80091D14
    // 0x8009921C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bakey_update(rdram, ctx);
        goto after_8;
    // 0x8009921C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80099220: jal         0x8009EFF8
    // 0x80099224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_update(rdram, ctx);
        goto after_9;
    // 0x80099224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80099228: jal         0x8009819C
    // 0x8009922C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_update(rdram, ctx);
        goto after_10;
    // 0x8009922C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80099230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099234: jal         0x8009AD78
    // 0x80099238: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009AD78(rdram, ctx);
        goto after_11;
    // 0x80099238: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x8009923C: beq         $v0, $zero, L_8009924C
    if (ctx->r2 == 0) {
        // 0x80099240: nop
    
            goto L_8009924C;
    }
    // 0x80099240: nop

    // 0x80099244: jal         0x80084980
    // 0x80099248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x80099248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_8009924C:
    // 0x8009924C: jal         0x8009E83C
    // 0x80099250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E83C(rdram, ctx);
        goto after_13;
    // 0x80099250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80099254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099258: jal         0x80091E80
    // 0x8009925C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80091E80(rdram, ctx);
        goto after_14;
    // 0x8009925C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80099260: beql        $v0, $zero, L_80099284
    if (ctx->r2 == 0) {
        // 0x80099264: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099284;
    }
    goto skip_1;
    // 0x80099264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80099268: jal         0x8008E454
    // 0x8009926C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E454(rdram, ctx);
        goto after_15;
    // 0x8009926C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80099270: beql        $v0, $zero, L_80099284
    if (ctx->r2 == 0) {
        // 0x80099274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099284;
    }
    goto skip_2;
    // 0x80099274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80099278: jal         0x8009B590
    // 0x8009927C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B590(rdram, ctx);
        goto after_16;
    // 0x8009927C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80099280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80099284:
    // 0x80099284: jal         0x8009AD78
    // 0x80099288: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8009AD78(rdram, ctx);
        goto after_17;
    // 0x80099288: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_17:
    // 0x8009928C: beq         $v0, $zero, L_8009929C
    if (ctx->r2 == 0) {
        // 0x80099290: nop
    
            goto L_8009929C;
    }
    // 0x80099290: nop

    // 0x80099294: jal         0x80085360
    // 0x80099298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _batranslate_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x80099298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
L_8009929C:
    // 0x8009929C: jal         0x8009C25C
    // 0x800992A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C25C(rdram, ctx);
        goto after_19;
    // 0x800992A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x800992A4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800992A8: beq         $t7, $zero, L_800992B8
    if (ctx->r15 == 0) {
        // 0x800992AC: nop
    
            goto L_800992B8;
    }
    // 0x800992AC: nop

    // 0x800992B0: jal         0x8009561C
    // 0x800992B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009561C(rdram, ctx);
        goto after_20;
    // 0x800992B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
L_800992B8:
    // 0x800992B8: jal         0x80095C94
    // 0x800992BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095C94(rdram, ctx);
        goto after_21;
    // 0x800992BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x800992C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800992C4: jal         0x80091E80
    // 0x800992C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80091E80(rdram, ctx);
        goto after_22;
    // 0x800992C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x800992CC: beql        $v0, $zero, L_800992F0
    if (ctx->r2 == 0) {
        // 0x800992D0: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_800992F0;
    }
    goto skip_3;
    // 0x800992D0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    skip_3:
    // 0x800992D4: jal         0x8009BF34
    // 0x800992D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BF34(rdram, ctx);
        goto after_23;
    // 0x800992D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x800992DC: jal         0x8009C4A4
    // 0x800992E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_update(rdram, ctx);
        goto after_24;
    // 0x800992E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x800992E4: jal         0x8009D088
    // 0x800992E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D088(rdram, ctx);
        goto after_25;
    // 0x800992E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x800992EC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
L_800992F0:
    // 0x800992F0: beql        $t8, $zero, L_80099304
    if (ctx->r24 == 0) {
        // 0x800992F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099304;
    }
    goto skip_4;
    // 0x800992F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x800992F8: jal         0x80091110
    // 0x800992FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80091110(rdram, ctx);
        goto after_26;
    // 0x800992FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80099300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80099304:
    // 0x80099304: jal         0x80091E80
    // 0x80099308: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80091E80(rdram, ctx);
        goto after_27;
    // 0x80099308: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_27:
    // 0x8009930C: beq         $v0, $zero, L_8009931C
    if (ctx->r2 == 0) {
        // 0x80099310: nop
    
            goto L_8009931C;
    }
    // 0x80099310: nop

    // 0x80099314: jal         0x8008C894
    // 0x80099318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_update(rdram, ctx);
        goto after_28;
    // 0x80099318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
L_8009931C:
    // 0x8009931C: jal         0x800A2060
    // 0x80099320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2060(rdram, ctx);
        goto after_29;
    // 0x80099320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80099324: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80099328: beql        $t9, $zero, L_8009933C
    if (ctx->r25 == 0) {
        // 0x8009932C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009933C;
    }
    goto skip_5;
    // 0x8009932C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80099330: jal         0x800987CC
    // 0x80099334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800987CC(rdram, ctx);
        goto after_30;
    // 0x80099334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80099338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009933C:
    // 0x8009933C: jal         0x8009AD78
    // 0x80099340: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8009AD78(rdram, ctx);
        goto after_31;
    // 0x80099340: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_31:
    // 0x80099344: beql        $v0, $zero, L_80099358
    if (ctx->r2 == 0) {
        // 0x80099348: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80099358;
    }
    goto skip_6;
    // 0x80099348: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x8009934C: jal         0x80090A4C
    // 0x80099350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090A4C(rdram, ctx);
        goto after_32;
    // 0x80099350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80099354: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_80099358:
    // 0x80099358: beql        $t0, $zero, L_8009936C
    if (ctx->r8 == 0) {
        // 0x8009935C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009936C;
    }
    goto skip_7;
    // 0x8009935C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_7:
    // 0x80099360: jal         0x800951F4
    // 0x80099364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951F4(rdram, ctx);
        goto after_33;
    // 0x80099364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80099368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009936C:
    // 0x8009936C: jal         0x8009AD78
    // 0x80099370: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009AD78(rdram, ctx);
        goto after_34;
    // 0x80099370: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_34:
    // 0x80099374: beq         $v0, $zero, L_80099384
    if (ctx->r2 == 0) {
        // 0x80099378: nop
    
            goto L_80099384;
    }
    // 0x80099378: nop

    // 0x8009937C: jal         0x80084A30
    // 0x80099380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_13(rdram, ctx);
        goto after_35;
    // 0x80099380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
L_80099384:
    // 0x80099384: jal         0x8009C08C
    // 0x80099388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C08C(rdram, ctx);
        goto after_36;
    // 0x80099388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8009938C: jal         0x8008E6F0
    // 0x80099390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E6F0(rdram, ctx);
        goto after_37;
    // 0x80099390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80099394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099398: jal         0x8009AD78
    // 0x8009939C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8009AD78(rdram, ctx);
        goto after_38;
    // 0x8009939C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_38:
    // 0x800993A0: beq         $v0, $zero, L_800993B0
    if (ctx->r2 == 0) {
        // 0x800993A4: nop
    
            goto L_800993B0;
    }
    // 0x800993A4: nop

    // 0x800993A8: jal         0x80084D30
    // 0x800993AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bahold_entrypoint_3(rdram, ctx);
        goto after_39;
    // 0x800993AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
L_800993B0:
    // 0x800993B0: jal         0x800A10A0
    // 0x800993B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A10A0(rdram, ctx);
        goto after_40;
    // 0x800993B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x800993B8: jal         0x8009BDE4
    // 0x800993BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BDE4(rdram, ctx);
        goto after_41;
    // 0x800993BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x800993C0: jal         0x800A3A80
    // 0x800993C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3A80(rdram, ctx);
        goto after_42;
    // 0x800993C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x800993C8: jal         0x800A4B08
    // 0x800993CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4B08(rdram, ctx);
        goto after_43;
    // 0x800993CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x800993D0: lw          $t1, 0x158($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X158);
    // 0x800993D4: bne         $t1, $zero, L_800993EC
    if (ctx->r9 != 0) {
        // 0x800993D8: nop
    
            goto L_800993EC;
    }
    // 0x800993D8: nop

    // 0x800993DC: jal         0x80094864
    // 0x800993E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094864(rdram, ctx);
        goto after_44;
    // 0x800993E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x800993E4: b           L_800993F8
    // 0x800993E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800993F8;
    // 0x800993E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800993EC:
    // 0x800993EC: jal         0x80085510
    // 0x800993F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badeathmatch_entrypoint_3(rdram, ctx);
        goto after_45;
    // 0x800993F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x800993F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800993F8:
    // 0x800993F8: jal         0x8009AD78
    // 0x800993FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8009AD78(rdram, ctx);
        goto after_46;
    // 0x800993FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_46:
    // 0x80099400: beql        $v0, $zero, L_80099414
    if (ctx->r2 == 0) {
        // 0x80099404: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099414;
    }
    goto skip_8;
    // 0x80099404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_8:
    // 0x80099408: jal         0x80084638
    // 0x8009940C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bacough_entrypoint_5(rdram, ctx);
        goto after_47;
    // 0x8009940C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80099410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80099414:
    // 0x80099414: jal         0x8009AD78
    // 0x80099418: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8009AD78(rdram, ctx);
        goto after_48;
    // 0x80099418: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_48:
    // 0x8009941C: beql        $v0, $zero, L_80099430
    if (ctx->r2 == 0) {
        // 0x80099420: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099430;
    }
    goto skip_9;
    // 0x80099420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_9:
    // 0x80099424: jal         0x80084B08
    // 0x80099428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggcursor_entrypoint_11(rdram, ctx);
        goto after_49;
    // 0x80099428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x8009942C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80099430:
    // 0x80099430: jal         0x8009AD78
    // 0x80099434: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8009AD78(rdram, ctx);
        goto after_50;
    // 0x80099434: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_50:
    // 0x80099438: beql        $v0, $zero, L_8009944C
    if (ctx->r2 == 0) {
        // 0x8009943C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009944C;
    }
    goto skip_10;
    // 0x8009943C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_10:
    // 0x80099440: jal         0x800854D8
    // 0x80099444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bainvisible_entrypoint_6(rdram, ctx);
        goto after_51;
    // 0x80099444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80099448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009944C:
    // 0x8009944C: jal         0x8009AD78
    // 0x80099450: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8009AD78(rdram, ctx);
        goto after_52;
    // 0x80099450: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_52:
    // 0x80099454: beql        $v0, $zero, L_80099468
    if (ctx->r2 == 0) {
        // 0x80099458: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099468;
    }
    goto skip_11;
    // 0x80099458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_11:
    // 0x8009945C: jal         0x80084F20
    // 0x80099460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamum_entrypoint_3(rdram, ctx);
        goto after_53;
    // 0x80099460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80099464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80099468:
    // 0x80099468: jal         0x8009AD78
    // 0x8009946C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8009AD78(rdram, ctx);
        goto after_54;
    // 0x8009946C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_54:
    // 0x80099470: beql        $v0, $zero, L_80099484
    if (ctx->r2 == 0) {
        // 0x80099474: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099484;
    }
    goto skip_12;
    // 0x80099474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_12:
    // 0x80099478: jal         0x80084CF0
    // 0x8009947C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_15(rdram, ctx);
        goto after_55;
    // 0x8009947C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80099480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80099484:
    // 0x80099484: jal         0x8009AD78
    // 0x80099488: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8009AD78(rdram, ctx);
        goto after_56;
    // 0x80099488: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_56:
    // 0x8009948C: beql        $v0, $zero, L_800994A0
    if (ctx->r2 == 0) {
        // 0x80099490: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800994A0;
    }
    goto skip_13;
    // 0x80099490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_13:
    // 0x80099494: jal         0x800850D0
    // 0x80099498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basquash_entrypoint_4(rdram, ctx);
        goto after_57;
    // 0x80099498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_57:
    // 0x8009949C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800994A0:
    // 0x800994A0: jal         0x8009AD78
    // 0x800994A4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_8009AD78(rdram, ctx);
        goto after_58;
    // 0x800994A4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_58:
    // 0x800994A8: beq         $v0, $zero, L_800994B8
    if (ctx->r2 == 0) {
        // 0x800994AC: nop
    
            goto L_800994B8;
    }
    // 0x800994AC: nop

    // 0x800994B0: jal         0x80085040
    // 0x800994B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_13(rdram, ctx);
        goto after_59;
    // 0x800994B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
L_800994B8:
    // 0x800994B8: jal         0x80093448
    // 0x800994BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80093448(rdram, ctx);
        goto after_60;
    // 0x800994BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x800994C0: jal         0x800A2534
    // 0x800994C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2534(rdram, ctx);
        goto after_61;
    // 0x800994C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x800994C8: jal         0x800D3E40
    // 0x800994CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800D3E40(rdram, ctx);
        goto after_62;
    // 0x800994CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_62:
    // 0x800994D0: beq         $v0, $zero, L_80099500
    if (ctx->r2 == 0) {
        // 0x800994D4: nop
    
            goto L_80099500;
    }
    // 0x800994D4: nop

    // 0x800994D8: jal         0x8008DAA8
    // 0x800994DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DAA8(rdram, ctx);
        goto after_63;
    // 0x800994DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x800994E0: beq         $v0, $zero, L_80099500
    if (ctx->r2 == 0) {
        // 0x800994E4: nop
    
            goto L_80099500;
    }
    // 0x800994E4: nop

    // 0x800994E8: jal         0x8008E124
    // 0x800994EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E124(rdram, ctx);
        goto after_64;
    // 0x800994EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x800994F0: bne         $v0, $zero, L_80099500
    if (ctx->r2 != 0) {
        // 0x800994F4: nop
    
            goto L_80099500;
    }
    // 0x800994F4: nop

    // 0x800994F8: jal         0x800A18E8
    // 0x800994FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A18E8(rdram, ctx);
        goto after_65;
    // 0x800994FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
L_80099500:
    // 0x80099500: jal         0x80091F30
    // 0x80099504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80091F30(rdram, ctx);
        goto after_66;
    // 0x80099504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x80099508: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
    // 0x8009950C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80099510: beq         $v1, $zero, L_80099528
    if (ctx->r3 == 0) {
        // 0x80099514: nop
    
            goto L_80099528;
    }
    // 0x80099514: nop

    // 0x80099518: jalr        $v1
    // 0x8009951C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_67;
    // 0x8009951C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_67:
    // 0x80099520: lw          $t2, 0xB8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XB8);
    // 0x80099524: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80099528:
    // 0x80099528: jal         0x800989E4
    // 0x8009952C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800989E4(rdram, ctx);
        goto after_68;
    // 0x8009952C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x80099530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80099534:
    // 0x80099534: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80099538: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009953C: jr          $ra
    // 0x80099540: nop

    return;
    // 0x80099540: nop

;}
RECOMP_FUNC void func_800187B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800187B4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800187B8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800187BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800187C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800187C4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800187C8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800187CC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800187D0: jal         0x80018704
    // 0x800187D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80018704(rdram, ctx);
        goto after_0;
    // 0x800187D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x800187D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800187DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800187E0: jr          $ra
    // 0x800187E4: nop

    return;
    // 0x800187E4: nop

;}
RECOMP_FUNC void func_800D70D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D70D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D70D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D70D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D70DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800D70E0: jal         0x800D7050
    // 0x800D70E4: lh          $a0, -0x46F0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X46F0);
    func_800D7050(rdram, ctx);
        goto after_0;
    // 0x800D70E4: lh          $a0, -0x46F0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X46F0);
    after_0:
    // 0x800D70E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D70EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D70F0: jr          $ra
    // 0x800D70F4: nop

    return;
    // 0x800D70F4: nop

;}
RECOMP_FUNC void subaddiemarker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800008: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080000C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800014: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080001C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3266, 0X1E0) << 16);
    // 0x80800020: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800024: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800028: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080002C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800030: addiu       $a1, $a1, 0x1E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3266, 0X1E0));
    // 0x80800034: jal         0x800882C0
    // 0x80800038: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x8080003C: blez        $v0, L_808000B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800040: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_808000B8;
    }
    // 0x80800040: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800044: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(3266, 0X1E0) << 16);
    // 0x80800048: addiu       $s0, $t6, 0x1E0
    ctx->r16 = ADD32(ctx->r14, (int16_t)RELOC_LO16(3266, 0X1E0));
    // 0x8080004C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800050: addu        $s2, $t7, $s0
    ctx->r18 = ADD32(ctx->r15, ctx->r16);
L_80800054:
    // 0x80800054: jal         0x80088C50
    // 0x80800058: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropmarker_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800058: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x8080005C: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
    // 0x80800060: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80800064: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800068: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8080006C: srl         $t0, $t9, 23
    ctx->r8 = S32(U32(ctx->r25) >> 23);
    // 0x80800070: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80800074: bgez        $t0, L_80800088
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800078: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800088;
    }
    // 0x80800078: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080007C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800080: nop

    // 0x80800084: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800088:
    // 0x80800088: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    // 0x8080008C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80800090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800094: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x80800098: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x8080009C: sw          $t3, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r11;
    // 0x808000A0: jal         0x800EE88C
    // 0x808000A4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x808000A4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x808000A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000AC: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808000B0: bne         $at, $zero, L_80800054
    if (ctx->r1 != 0) {
        // 0x808000B4: addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
            goto L_80800054;
    }
    // 0x808000B4: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
L_808000B8:
    // 0x808000B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000BC: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x808000C0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808000C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D0: jr          $ra
    // 0x808000D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080010C_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800110: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800114: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800118: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080011C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800120: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800124: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800128: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8080012C: addiu       $a0, $zero, 0x47E
    ctx->r4 = ADD32(0, 0X47E);
    // 0x80800130: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800134: jal         0x800882C0
    // 0x80800138: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800138: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x8080013C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800140: jal         0x8008A498
    // 0x80800144: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800144: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80800148: bne         $v0, $zero, L_80800160
    if (ctx->r2 != 0) {
        // 0x8080014C: nop
    
            goto L_80800160;
    }
    // 0x8080014C: nop

    // 0x80800150: jal         0x800FFA88
    // 0x80800154: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80800154: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x80800158: b           L_80800210
    // 0x8080015C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800210;
    // 0x8080015C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800160:
    // 0x80800160: blez        $s2, L_808001DC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80800164: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_808001DC;
    }
    // 0x80800164: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800168: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
L_8080016C:
    // 0x8080016C: jal         0x80088BE8
    // 0x80800170: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800170: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80800174: lhu         $t6, 0x76($s3)
    ctx->r14 = MEM_HU(ctx->r19, 0X76);
    // 0x80800178: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080017C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800180: bne         $v0, $t7, L_808001D4
    if (ctx->r2 != ctx->r15) {
        // 0x80800184: nop
    
            goto L_808001D4;
    }
    // 0x80800184: nop

    // 0x80800188: addiu       $s1, $s3, 0x18
    ctx->r17 = ADD32(ctx->r19, 0X18);
    // 0x8080018C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800190: jal         0x80088C00
    // 0x80800194: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800194: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80800198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080019C: jal         0x800F1DF4
    // 0x808001A0: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_5;
    // 0x808001A0: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    after_5:
    // 0x808001A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001AC: jal         0x800EF1B8
    // 0x808001B0: lui         $a2, 0xC28C
    ctx->r6 = S32(0XC28C << 16);
    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x808001B0: lui         $a2, 0xC28C
    ctx->r6 = S32(0XC28C << 16);
    after_6:
    // 0x808001B4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808001B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001BC: lwc1        $f4, 0x1C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x808001C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808001C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001C8: swc1        $f8, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f8.u32l;
    // 0x808001CC: b           L_808001DC
    // 0x808001D0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
        goto L_808001DC;
    // 0x808001D0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
L_808001D4:
    // 0x808001D4: bne         $s1, $s2, L_8080016C
    if (ctx->r17 != ctx->r18) {
        // 0x808001D8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080016C;
    }
    // 0x808001D8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808001DC:
    // 0x808001DC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x808001E0: bne         $t9, $zero, L_808001F8
    if (ctx->r25 != 0) {
        // 0x808001E4: nop
    
            goto L_808001F8;
    }
    // 0x808001E4: nop

    // 0x808001E8: jal         0x800FFA88
    // 0x808001EC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_7;
    // 0x808001EC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_7:
    // 0x808001F0: b           L_80800210
    // 0x808001F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800210;
    // 0x808001F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001F8:
    // 0x808001F8: jal         0x808009B8
    // 0x808001FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808009B8_chfantasycannon(rdram, ctx);
        goto after_8;
    // 0x808001FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x80800200: lbu         $t0, 0x65($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X65);
    // 0x80800204: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80800208: sb          $t1, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r9;
    // 0x8080020C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800210:
    // 0x80800210: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800214: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800218: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080021C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800220: jr          $ra
    // 0x80800224: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80800224: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800C1CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1CCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C1CD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C1CD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C1CD8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C1CDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C1CE0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800C1CE4: jal         0x800C13C4
    // 0x800C1CE8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800C13C4(rdram, ctx);
        goto after_0;
    // 0x800C1CE8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x800C1CEC: beq         $v0, $zero, L_800C1D6C
    if (ctx->r2 == 0) {
        // 0x800C1CF0: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_800C1D6C;
    }
    // 0x800C1CF0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1CF8: jal         0x800C1104
    // 0x800C1CFC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800C1104(rdram, ctx);
        goto after_1;
    // 0x800C1CFC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x800C1D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1D04: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800C1D08: jal         0x800C13C4
    // 0x800C1D0C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800C13C4(rdram, ctx);
        goto after_2;
    // 0x800C1D0C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x800C1D10: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800C1D14: beq         $v0, $zero, L_800C1D48
    if (ctx->r2 == 0) {
        // 0x800C1D18: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_800C1D48;
    }
    // 0x800C1D18: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1D1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C1D20: bnel        $v1, $at, L_800C1D70
    if (ctx->r3 != ctx->r1) {
        // 0x800C1D24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C1D70;
    }
    goto skip_0;
    // 0x800C1D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800C1D28: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800C1D2C: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800C1D30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C1D34: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C1D38: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C1D3C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800C1D40: b           L_800C1D70
    // 0x800C1D44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800C1D70;
    // 0x800C1D44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C1D48:
    // 0x800C1D48: bnel        $v1, $zero, L_800C1D70
    if (ctx->r3 != 0) {
        // 0x800C1D4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C1D70;
    }
    goto skip_1;
    // 0x800C1D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800C1D50: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x800C1D54: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800C1D58: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C1D5C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C1D60: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C1D64: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800C1D68: nop

L_800C1D6C:
    // 0x800C1D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C1D70:
    // 0x800C1D70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C1D74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C1D78: jr          $ra
    // 0x800C1D7C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x800C1D7C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}
RECOMP_FUNC void _suexpression_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089798: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x80089798);
    return;
    // 0x8008979C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _fxstep_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A50: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A50);
    return;
    // 0x80088A54: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void suautobaddies_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800420: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800424: jal         0x800D395C
    // 0x80800428: nop

    func_800D395C(rdram, ctx);
        goto after_0;
    // 0x80800428: nop

    after_0:
    // 0x8080042C: bnel        $v0, $zero, L_80800484
    if (ctx->r2 != 0) {
        // 0x80800430: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800484;
    }
    goto skip_0;
    // 0x80800430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800434: jal         0x800DB9B0
    // 0x80800438: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x80800438: nop

    after_1:
    // 0x8080043C: bnel        $v0, $zero, L_80800484
    if (ctx->r2 != 0) {
        // 0x80800440: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800484;
    }
    goto skip_1;
    // 0x80800440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800444: jal         0x80088148
    // 0x80800448: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    _gcfrontend_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800448: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    after_2:
    // 0x8080044C: bnel        $v0, $zero, L_80800484
    if (ctx->r2 != 0) {
        // 0x80800450: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800484;
    }
    goto skip_2;
    // 0x80800450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800454: jal         0x800D035C
    // 0x80800458: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_3;
    // 0x80800458: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8080045C: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80800460: bne         $v0, $at, L_80800480
    if (ctx->r2 != ctx->r1) {
        // 0x80800464: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80800480;
    }
    // 0x80800464: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800468: addiu       $a0, $a0, 0x6D68
    ctx->r4 = ADD32(ctx->r4, 0X6D68);
    // 0x8080046C: addiu       $a1, $zero, 0x524
    ctx->r5 = ADD32(0, 0X524);
    // 0x80800470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800474: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800478: jal         0x80086D48
    // 0x8080047C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chbaddiesetup_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x8080047C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
L_80800480:
    // 0x80800480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800484:
    // 0x80800484: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800488: jr          $ra
    // 0x8080048C: nop

    return;
    // 0x8080048C: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800980: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800984: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(104, 0X1490) << 16);
    // 0x80800988: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080098C: jr          $ra
    // 0x80800990: lw          $v0, 0x1490($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X1490));
    return;
    // 0x80800990: lw          $v0, 0x1490($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X1490));
;}
RECOMP_FUNC void bsfirstp_entrypoint_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809BF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80809BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809BF8: jal         0x800A89F8
    // 0x80809BFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x80809BFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80809C00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80809C04: jal         0x800A4C68
    // 0x80809C08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A4C68(rdram, ctx);
        goto after_1;
    // 0x80809C08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80809C0C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80809C10: bnel        $v0, $t6, L_80809C24
    if (ctx->r2 != ctx->r14) {
        // 0x80809C14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80809C24;
    }
    goto skip_0;
    // 0x80809C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80809C18: jal         0x80809C30
    // 0x80809C1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80809C30_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80809C1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80809C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80809C24:
    // 0x80809C24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80809C28: jr          $ra
    // 0x80809C2C: nop

    return;
    // 0x80809C2C: nop

;}
RECOMP_FUNC void _badata_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084720: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084720);
    return;
    // 0x80084724: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void func_8080000C_chhellterskeltermouth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800018: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800024: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800028: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x8080002C: beq         $at, $zero, L_808001A8
    if (ctx->r1 == 0) {
        // 0x80800030: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808001A8;
    }
    // 0x80800030: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800034: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(976, 0X310) << 16);
    // 0x80800038: addu        $at, $at, $t8
    gpr jr_addend_80800040 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080003C: lw          $t8, 0x310($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(976, 0X310));
    // 0x80800040: jr          $t8
    // 0x80800044: nop

    switch (jr_addend_80800040 >> 2) {
        case 0: goto L_808001A8; break;
        case 1: goto L_80800048; break;
        case 2: goto L_808000CC; break;
        case 3: goto L_808000F8; break;
        case 4: goto L_80800184; break;
        default: switch_error(__func__, 0x80800040, 0x80800310);
    }
    // 0x80800044: nop

L_80800048:
    // 0x80800048: jal         0x800D9078
    // 0x8080004C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x80800050: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800054: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800058: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080005C: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x80800060: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800064: jal         0x800F12D4
    // 0x80800068: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x80800068: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8080006C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800070: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800074: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800078: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x8080007C: jal         0x800EFE50
    // 0x80800080: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_2;
    // 0x80800080: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x80800084: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80800088: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(976, 0X324) << 16);
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800090: beq         $t9, $zero, L_808000BC
    if (ctx->r25 == 0) {
        // 0x80800094: nop
    
            goto L_808000BC;
    }
    // 0x80800094: nop

    // 0x80800098: lwc1        $f4, 0x324($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(976, 0X324));
    // 0x8080009C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808000A0: jal         0x80101FDC
    // 0x808000A4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808000A4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x808000A8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(976, 0X378) << 16);
    // 0x808000AC: addiu       $a2, $a2, 0x378
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(976, 0X378));
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80089D18
    // 0x808000B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808000B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
L_808000BC:
    // 0x808000BC: jal         0x808002E4
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002E4_chhellterskeltermouth(rdram, ctx);
        goto after_5;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000C4: b           L_808001AC
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001AC;
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000CC:
    // 0x808000CC: jal         0x800D9078
    // 0x808000D0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x808000D0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x808000D4: beq         $v0, $zero, L_808001A8
    if (ctx->r2 == 0) {
        // 0x808000D8: lui         $at, 0x4020
        ctx->r1 = S32(0X4020 << 16);
            goto L_808001A8;
    }
    // 0x808000D8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x808000DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808000E8: jal         0x80101FDC
    // 0x808000EC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808000EC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_7:
    // 0x808000F0: b           L_808001AC
    // 0x808000F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001AC;
    // 0x808000F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000F8:
    // 0x808000F8: jal         0x800D9078
    // 0x808000FC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x808000FC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x80800100: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800104: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800108: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080010C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800110: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800114: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800118: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x8080011C: jal         0x800F12D4
    // 0x80800120: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F12D4(rdram, ctx);
        goto after_9;
    // 0x80800120: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x80800124: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800128: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080012C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800130: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800134: jal         0x800EFE50
    // 0x80800138: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_10;
    // 0x80800138: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_10:
    // 0x8080013C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800140: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(976, 0X328) << 16);
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: beq         $t0, $zero, L_80800174
    if (ctx->r8 == 0) {
        // 0x8080014C: nop
    
            goto L_80800174;
    }
    // 0x8080014C: nop

    // 0x80800150: lwc1        $f10, 0x328($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(976, 0X328));
    // 0x80800154: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800158: jal         0x80101FDC
    // 0x8080015C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x8080015C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_11:
    // 0x80800160: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(976, 0X378) << 16);
    // 0x80800164: addiu       $a2, $a2, 0x378
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(976, 0X378));
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x80089D18
    // 0x80800170: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800170: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_12:
L_80800174:
    // 0x80800174: jal         0x808002E4
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002E4_chhellterskeltermouth(rdram, ctx);
        goto after_13;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080017C: b           L_808001AC
    // 0x80800180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001AC;
    // 0x80800180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800184:
    // 0x80800184: jal         0x800D9078
    // 0x80800188: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_14;
    // 0x80800188: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_14:
    // 0x8080018C: beq         $v0, $zero, L_808001A8
    if (ctx->r2 == 0) {
        // 0x80800190: lui         $at, 0x4020
        ctx->r1 = S32(0X4020 << 16);
            goto L_808001A8;
    }
    // 0x80800190: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800194: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001A0: jal         0x80101FDC
    // 0x808001A4: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x808001A4: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_15:
L_808001A8:
    // 0x808001A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001AC:
    // 0x808001AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808001B4: jr          $ra
    // 0x808001B8: nop

    return;
    // 0x808001B8: nop

;}
RECOMP_FUNC void func_80800E2C_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E34: jal         0x808005F0
    // 0x80800E38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808005F0_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80800E38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E3C: jal         0x80082FE0
    // 0x80800E40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800E40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E4C: jr          $ra
    // 0x80800E50: nop

    return;
    // 0x80800E50: nop

;}
RECOMP_FUNC void func_80800000_chsunlightspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800DA298
    // 0x80800010: addiu       $a0, $zero, 0xE9
    ctx->r4 = ADD32(0, 0XE9);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0xE9
    ctx->r4 = ADD32(0, 0XE9);
    after_0:
    // 0x80800014: beq         $v0, $zero, L_8080002C
    if (ctx->r2 == 0) {
        // 0x80800018: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080002C;
    }
    // 0x80800018: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: jal         0x800FFA88
    // 0x80800020: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_1;
    // 0x80800020: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    after_1:
    // 0x80800024: b           L_8080003C
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080003C;
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080002C:
    // 0x8080002C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800030: jal         0x80800404
    // 0x80800034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800404_chsunlightspell(rdram, ctx);
        goto after_2;
    // 0x80800034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080003C:
    // 0x8080003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void _chjinjo_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BB0: syscall     425
    recomp_syscall_handler(rdram, ctx, 0x80086BB0);
    return;
    // 0x80086BB4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void babackpack_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080047C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800480: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800484: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80800488: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080048C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800490: jal         0x800DBEFC
    // 0x80800494: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_0;
    // 0x80800494: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_0:
    // 0x80800498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080049C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004A0: jr          $ra
    // 0x808004A4: nop

    return;
    // 0x808004A4: nop

;}
RECOMP_FUNC void baflag_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095760: lw          $t7, 0x80($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X80);
    // 0x80095764: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80095768: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8009576C: jr          $ra
    // 0x80095770: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    return;
    // 0x80095770: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8080110C_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080110C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801110: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80801114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801118: beq         $a1, $at, L_80801148
    if (ctx->r5 == ctx->r1) {
        // 0x8080111C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801148;
    }
    // 0x8080111C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801120: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80801124: beq         $a1, $at, L_8080115C
    if (ctx->r5 == ctx->r1) {
        // 0x80801128: lh          $a2, 0x22($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X22);
            goto L_8080115C;
    }
    // 0x80801128: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x8080112C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80801130: beq         $a1, $at, L_8080116C
    if (ctx->r5 == ctx->r1) {
        // 0x80801134: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_8080116C;
    }
    // 0x80801134: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801138: beq         $a1, $at, L_8080117C
    if (ctx->r5 == ctx->r1) {
        // 0x8080113C: nop
    
            goto L_8080117C;
    }
    // 0x8080113C: nop

    // 0x80801140: b           L_80801198
    // 0x80801144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801198;
    // 0x80801144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801148:
    // 0x80801148: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x8080114C: jal         0x808011A8
    // 0x80801150: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_808011A8_chballoonburst(rdram, ctx);
        goto after_0;
    // 0x80801150: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x80801154: b           L_80801198
    // 0x80801158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801198;
    // 0x80801158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080115C:
    // 0x8080115C: jal         0x80801254
    // 0x80801160: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    func_80801254_chballoonburst(rdram, ctx);
        goto after_1;
    // 0x80801160: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    after_1:
    // 0x80801164: b           L_8080119C
    // 0x80801168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080119C;
    // 0x80801168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080116C:
    // 0x8080116C: jal         0x80800BE8
    // 0x80801170: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80800BE8_chballoonburst(rdram, ctx);
        goto after_2;
    // 0x80801170: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x80801174: b           L_80801198
    // 0x80801178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801198;
    // 0x80801178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080117C:
    // 0x8080117C: jal         0x80801290
    // 0x80801180: nop

    func_80801290_chballoonburst(rdram, ctx);
        goto after_3;
    // 0x80801180: nop

    after_3:
    // 0x80801184: b           L_80801198
    // 0x80801188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801198;
    // 0x80801188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080118C: b           L_80801198
    // 0x80801190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801198;
    // 0x80801190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801198:
    // 0x80801198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080119C:
    // 0x8080119C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011A0: jr          $ra
    // 0x808011A4: nop

    return;
    // 0x808011A4: nop

;}
RECOMP_FUNC void chmumbohealspell_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080085C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2424, 0X900) << 16);
    // 0x80800860: jr          $ra
    // 0x80800864: addiu       $v0, $v0, 0x900
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2424, 0X900));
    return;
    // 0x80800864: addiu       $v0, $v0, 0x900
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2424, 0X900));
    // 0x80800868: nop

    // 0x8080086C: nop

;}
RECOMP_FUNC void func_808005FC_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800604: jal         0x80800174
    // 0x80800608: nop

    func_80800174_bstntswim(rdram, ctx);
        goto after_0;
    // 0x80800608: nop

    after_0:
    // 0x8080060C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800614: jr          $ra
    // 0x80800618: nop

    return;
    // 0x80800618: nop

;}
RECOMP_FUNC void _bsvan_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084140: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084140);
    return;
    // 0x80084144: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bawasher_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085420: syscall     161
    recomp_syscall_handler(rdram, ctx, 0x80085420);
    return;
    // 0x80085424: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800FC688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC68C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC690: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800FC694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800FC698: jal         0x800FC508
    // 0x800FC69C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800FC508(rdram, ctx);
        goto after_0;
    // 0x800FC69C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800FC6A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC6A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC6A8: jr          $ra
    // 0x800FC6AC: nop

    return;
    // 0x800FC6AC: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BC8: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082BC8);
    return;
    // 0x80082BCC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F6018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6018: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F601C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6020: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6028: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F602C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6030: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800F6034: jal         0x80091C80
    // 0x800F6038: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    bakey_setState(rdram, ctx);
        goto after_0;
    // 0x800F6038: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800F603C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6044: jr          $ra
    // 0x800F6048: nop

    return;
    // 0x800F6048: nop

;}
RECOMP_FUNC void _suegg_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3F0: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3F0);
    return;
    // 0x8008A3F4: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_8001E7CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7CC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E7D0: jr          $ra
    // 0x8001E7D4: lw          $v0, -0x16B8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X16B8);
    return;
    // 0x8001E7D4: lw          $v0, -0x16B8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X16B8);
    // 0x8001E7D8: nop

    // 0x8001E7DC: nop

;}
RECOMP_FUNC void chjollyroger_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1036, 0X13E8) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x13E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1036, 0X13E8));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x13E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1036, 0X13E8));
;}
RECOMP_FUNC void _sucoasterfly_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EE8: syscall     813
    recomp_syscall_handler(rdram, ctx, 0x80089EE8);
    return;
    // 0x80089EEC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _glglobalsettings_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886D0: syscall     699
    recomp_syscall_handler(rdram, ctx, 0x800886D0);
    return;
    // 0x800886D4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
