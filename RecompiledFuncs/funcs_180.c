#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bskazshock_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800754: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800758: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(272, 0X7B4) << 16);
    // 0x8080075C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800760: jr          $ra
    // 0x80800764: lw          $v0, 0x7B4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(272, 0X7B4));
    return;
    // 0x80800764: lw          $v0, 0x7B4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(272, 0X7B4));
;}
RECOMP_FUNC void _bahitspline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D68: syscall     135
    recomp_syscall_handler(rdram, ctx, 0x80084D68);
    return;
    // 0x80084D6C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800CFBC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFBC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CFBCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CFBD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CFBD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CFBD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CFBDC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800CFBE0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800CFBE4: jal         0x8010108C
    // 0x800CFBE8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_8010108C(rdram, ctx);
        goto after_0;
    // 0x800CFBE8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_0:
    // 0x800CFBEC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800CFBF0: jal         0x800CF888
    // 0x800CFBF4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800CF888(rdram, ctx);
        goto after_1;
    // 0x800CFBF4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800CFBF8: beq         $v0, $zero, L_800CFC08
    if (ctx->r2 == 0) {
        // 0x800CFBFC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800CFC08;
    }
    // 0x800CFBFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CFC00: jal         0x8008A4B0
    // 0x800CFC04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x800CFC04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_800CFC08:
    // 0x800CFC08: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800CFC0C: jal         0x800CF8D0
    // 0x800CFC10: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800CF8D0(rdram, ctx);
        goto after_3;
    // 0x800CFC10: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x800CFC14: beq         $v0, $zero, L_800CFC28
    if (ctx->r2 == 0) {
        // 0x800CFC18: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800CFC28;
    }
    // 0x800CFC18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CFC1C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x800CFC20: jal         0x8010108C
    // 0x800CFC24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8010108C(rdram, ctx);
        goto after_4;
    // 0x800CFC24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_800CFC28:
    // 0x800CFC28: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800CFC2C: jal         0x800CF918
    // 0x800CFC30: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800CF918(rdram, ctx);
        goto after_5;
    // 0x800CFC30: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x800CFC34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CFC38: beq         $v0, $at, L_800CFC4C
    if (ctx->r2 == ctx->r1) {
        // 0x800CFC3C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800CFC4C;
    }
    // 0x800CFC3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CFC40: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x800CFC44: jal         0x8010108C
    // 0x800CFC48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8010108C(rdram, ctx);
        goto after_6;
    // 0x800CFC48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
L_800CFC4C:
    // 0x800CFC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CFC50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CFC54: jr          $ra
    // 0x800CFC58: nop

    return;
    // 0x800CFC58: nop

;}
RECOMP_FUNC void func_80800000_sukickball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3166, 0X1200) << 16);
    // 0x80800008: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800010: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800014: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800018: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8080001C: addiu       $t7, $t7, 0x1200
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3166, 0X1200));
    // 0x80800020: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800024: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80800028: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8080002C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800030: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800034: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800038: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8080003C: jal         0x800DF830
    // 0x80800040: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    func_800DF830(rdram, ctx);
        goto after_0;
    // 0x80800040: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    after_0:
    // 0x80800044: jal         0x801039E4
    // 0x80800048: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_801039E4(rdram, ctx);
        goto after_1;
    // 0x80800048: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8080004C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800050: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800054: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800058: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080005C: jal         0x800DE448
    // 0x80800060: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800DE448(rdram, ctx);
        goto after_2;
    // 0x80800060: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800068: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void _bamovegoto_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DF8: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084DF8);
    return;
    // 0x80084DFC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800348_badrone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080034C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800350: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80800354: jal         0x800846E8
    // 0x80800358: sb          $a1, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r5;
    _badata_entrypoint_21(rdram, ctx);
        goto after_0;
    // 0x80800358: sb          $a1, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r5;
    after_0:
    // 0x8080035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800364: jr          $ra
    // 0x80800368: nop

    return;
    // 0x80800368: nop

;}
RECOMP_FUNC void func_8009EAF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EAF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EAF8: jr          $ra
    // 0x8009EAFC: sb          $a0, 0x7076($at)
    MEM_B(0X7076, ctx->r1) = ctx->r4;
    return;
    // 0x8009EAFC: sb          $a0, 0x7076($at)
    MEM_B(0X7076, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8008FC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FC70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FC78: jal         0x800F54E4
    // 0x8008FC7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FC7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FC80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FC84: jal         0x800F81A8
    // 0x8008FC88: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F81A8(rdram, ctx);
        goto after_1;
    // 0x8008FC88: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008FC8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FC90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FC94: jr          $ra
    // 0x8008FC98: nop

    return;
    // 0x8008FC98: nop

;}
RECOMP_FUNC void func_80802058_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802058: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8080205C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80802060: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80802064: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80802068: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8080206C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80802070: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80802074: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80802078: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8080207C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80802080: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80802084: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802088: jal         0x80100094
    // 0x8080208C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080208C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802090: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80802094: addiu       $s1, $v0, 0x43C
    ctx->r17 = ADD32(ctx->r2, 0X43C);
    // 0x80802098: addiu       $s2, $v0, 0x46C
    ctx->r18 = ADD32(ctx->r2, 0X46C);
    // 0x8080209C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808020A0: addiu       $fp, $zero, 0xC
    ctx->r30 = ADD32(0, 0XC);
    // 0x808020A4: addiu       $s6, $sp, 0x60
    ctx->r22 = ADD32(ctx->r29, 0X60);
    // 0x808020A8: addiu       $s4, $sp, 0x6C
    ctx->r20 = ADD32(ctx->r29, 0X6C);
L_808020AC:
    // 0x808020AC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x808020B0: addiu       $s0, $s3, 0x3
    ctx->r16 = ADD32(ctx->r19, 0X3);
    // 0x808020B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808020B8: bne         $t6, $zero, L_808020CC
    if (ctx->r14 != 0) {
        // 0x808020BC: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808020CC;
    }
    // 0x808020BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808020C0: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x808020C4: beql        $t7, $zero, L_8080216C
    if (ctx->r15 == 0) {
        // 0x808020C8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8080216C;
    }
    goto skip_0;
    // 0x808020C8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
L_808020CC:
    // 0x808020CC: jal         0x80801904
    // 0x808020D0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80801904_chinflatableboss(rdram, ctx);
        goto after_1;
    // 0x808020D0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_1:
    // 0x808020D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808020D8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808020DC: jal         0x80802590
    // 0x808020E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80802590_chinflatableboss(rdram, ctx);
        goto after_2;
    // 0x808020E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x808020E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808020E8: sltu        $a2, $zero, $a0
    ctx->r6 = 0 < ctx->r4 ? 1 : 0;
    // 0x808020EC: beql        $a2, $zero, L_80802108
    if (ctx->r6 == 0) {
        // 0x808020F0: lw          $t8, 0x70($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X70);
            goto L_80802108;
    }
    goto skip_1;
    // 0x808020F0: lw          $t8, 0x70($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X70);
    skip_1:
    // 0x808020F4: jal         0x800BA198
    // 0x808020F8: nop

    func_800BA198(rdram, ctx);
        goto after_3;
    // 0x808020F8: nop

    after_3:
    // 0x808020FC: slti        $a2, $v0, 0x8
    ctx->r6 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80802100: xori        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 ^ 0X1;
    // 0x80802104: lw          $t8, 0x70($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X70);
L_80802108:
    // 0x80802108: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x8080210C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(832, 0X2FF8) << 16);
    // 0x80802110: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80802114: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802118: addiu       $a3, $a3, 0x2FF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(832, 0X2FF8));
    // 0x8080211C: jal         0x80089D68
    // 0x80802120: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80802120: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
    // 0x80802124: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x80802128: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8080212C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80802130: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80802134: beql        $a0, $zero, L_8080216C
    if (ctx->r4 == 0) {
        // 0x80802138: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8080216C;
    }
    goto skip_2;
    // 0x80802138: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x8080213C: lw          $a3, 0x38($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X38);
    // 0x80802140: jal         0x800BBD18
    // 0x80802144: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800BBD18(rdram, ctx);
        goto after_5;
    // 0x80802144: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80802148: jal         0x800BA28C
    // 0x8080214C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800BA28C(rdram, ctx);
        goto after_6;
    // 0x8080214C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x80802150: beq         $v0, $zero, L_80802168
    if (ctx->r2 == 0) {
        // 0x80802154: sll         $t0, $s3, 2
        ctx->r8 = S32(ctx->r19 << 2);
            goto L_80802168;
    }
    // 0x80802154: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x80802158: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8080215C: jal         0x800BA2C4
    // 0x80802160: addu        $s0, $s7, $t0
    ctx->r16 = ADD32(ctx->r23, ctx->r8);
    func_800BA2C4(rdram, ctx);
        goto after_7;
    // 0x80802160: addu        $s0, $s7, $t0
    ctx->r16 = ADD32(ctx->r23, ctx->r8);
    after_7:
    // 0x80802164: sw          $v0, 0x43C($s0)
    MEM_W(0X43C, ctx->r16) = ctx->r2;
L_80802168:
    // 0x80802168: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8080216C:
    // 0x8080216C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80802170: bne         $s3, $fp, L_808020AC
    if (ctx->r19 != ctx->r30) {
        // 0x80802174: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_808020AC;
    }
    // 0x80802174: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80802178: lw          $t1, 0x434($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X434);
    // 0x8080217C: addiu       $s0, $sp, 0x54
    ctx->r16 = ADD32(ctx->r29, 0X54);
    // 0x80802180: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802184: bne         $t1, $zero, L_80802198
    if (ctx->r9 != 0) {
        // 0x80802188: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80802198;
    }
    // 0x80802188: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080218C: lbu         $t2, 0x438($s7)
    ctx->r10 = MEM_BU(ctx->r23, 0X438);
    // 0x80802190: beql        $t2, $zero, L_80802238
    if (ctx->r10 == 0) {
        // 0x80802194: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80802238;
    }
    goto skip_3;
    // 0x80802194: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_3:
L_80802198:
    // 0x80802198: jal         0x8008A0E8
    // 0x8080219C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x8080219C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_8:
    // 0x808021A0: lw          $a2, 0x434($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X434);
    // 0x808021A4: sltu        $t3, $zero, $a2
    ctx->r11 = 0 < ctx->r6 ? 1 : 0;
    // 0x808021A8: beq         $t3, $zero, L_808021D8
    if (ctx->r11 == 0) {
        // 0x808021AC: or          $a2, $t3, $zero
        ctx->r6 = ctx->r11 | 0;
            goto L_808021D8;
    }
    // 0x808021AC: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x808021B0: jal         0x80101F24
    // 0x808021B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80101F24(rdram, ctx);
        goto after_9;
    // 0x808021B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_9:
    // 0x808021B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2D6C) << 16);
    // 0x808021BC: lwc1        $f4, 0x2D6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(832, 0X2D6C));
    // 0x808021C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808021C4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808021C8: nop

    // 0x808021CC: bc1fl       L_808021DC
    if (!c1cs) {
        // 0x808021D0: lw          $t4, 0x70($s5)
        ctx->r12 = MEM_W(ctx->r21, 0X70);
            goto L_808021DC;
    }
    goto skip_4;
    // 0x808021D0: lw          $t4, 0x70($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X70);
    skip_4:
    // 0x808021D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_808021D8:
    // 0x808021D8: lw          $t4, 0x70($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X70);
L_808021DC:
    // 0x808021DC: lbu         $a0, 0x438($s7)
    ctx->r4 = MEM_BU(ctx->r23, 0X438);
    // 0x808021E0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(832, 0X2FF8) << 16);
    // 0x808021E4: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x808021E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808021EC: addiu       $a3, $a3, 0x2FF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(832, 0X2FF8));
    // 0x808021F0: jal         0x80089D68
    // 0x808021F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x808021F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x808021F8: lw          $a0, 0x434($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X434);
    // 0x808021FC: sb          $v0, 0x438($s7)
    MEM_B(0X438, ctx->r23) = ctx->r2;
    // 0x80802200: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802204: beq         $a0, $zero, L_80802234
    if (ctx->r4 == 0) {
        // 0x80802208: addiu       $a2, $s7, 0x28
        ctx->r6 = ADD32(ctx->r23, 0X28);
            goto L_80802234;
    }
    // 0x80802208: addiu       $a2, $s7, 0x28
    ctx->r6 = ADD32(ctx->r23, 0X28);
    // 0x8080220C: lw          $a3, 0x38($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X38);
    // 0x80802210: jal         0x800BBD18
    // 0x80802214: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800BBD18(rdram, ctx);
        goto after_11;
    // 0x80802214: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x80802218: jal         0x800BA28C
    // 0x8080221C: lw          $a0, 0x434($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X434);
    func_800BA28C(rdram, ctx);
        goto after_12;
    // 0x8080221C: lw          $a0, 0x434($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X434);
    after_12:
    // 0x80802220: beql        $v0, $zero, L_80802238
    if (ctx->r2 == 0) {
        // 0x80802224: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80802238;
    }
    goto skip_5;
    // 0x80802224: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x80802228: jal         0x800BA2C4
    // 0x8080222C: lw          $a0, 0x434($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X434);
    func_800BA2C4(rdram, ctx);
        goto after_13;
    // 0x8080222C: lw          $a0, 0x434($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X434);
    after_13:
    // 0x80802230: sw          $v0, 0x434($s7)
    MEM_W(0X434, ctx->r23) = ctx->r2;
L_80802234:
    // 0x80802234: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80802238:
    // 0x80802238: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080223C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80802240: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80802244: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80802248: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080224C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80802250: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80802254: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80802258: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8080225C: jr          $ra
    // 0x80802260: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80802260: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800F0EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0EF0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800F0EF4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800F0EF8: addiu       $v1, $v1, -0x3
    ctx->r3 = ADD32(ctx->r3, -0X3);
    // 0x800F0EFC: blez        $v1, L_800F0F94
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800F0F00: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F0F94;
    }
    // 0x800F0F00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F0F04: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800F0F08: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800F0F0C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800F0F10: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800F0F14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800F0F18:
    // 0x800F0F18: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800F0F1C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F0F20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F0F24: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800F0F28: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800F0F2C: nop

    // 0x800F0F30: bc1fl       L_800F0F5C
    if (!c1cs) {
        // 0x800F0F34: sub.s       $f10, $f2, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_800F0F5C;
    }
    goto skip_0;
    // 0x800F0F34: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    skip_0:
    // 0x800F0F38: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
L_800F0F3C:
    // 0x800F0F3C: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x800F0F40: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800F0F44: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800F0F48: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x800F0F4C: nop

    // 0x800F0F50: bc1tl       L_800F0F3C
    if (c1cs) {
        // 0x800F0F54: add.s       $f6, $f2, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
            goto L_800F0F3C;
    }
    goto skip_1;
    // 0x800F0F54: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    skip_1:
    // 0x800F0F58: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
L_800F0F5C:
    // 0x800F0F5C: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x800F0F60: nop

    // 0x800F0F64: bc1f        L_800F0F8C
    if (!c1cs) {
        // 0x800F0F68: nop
    
            goto L_800F0F8C;
    }
    // 0x800F0F68: nop

    // 0x800F0F6C: sub.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f14.fl;
L_800F0F70:
    // 0x800F0F70: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x800F0F74: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800F0F78: sub.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800F0F7C: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x800F0F80: nop

    // 0x800F0F84: bc1tl       L_800F0F70
    if (c1cs) {
        // 0x800F0F88: sub.s       $f16, $f2, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_800F0F70;
    }
    goto skip_2;
    // 0x800F0F88: sub.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f14.fl;
    skip_2:
L_800F0F8C:
    // 0x800F0F8C: bne         $v0, $v1, L_800F0F18
    if (ctx->r2 != ctx->r3) {
        // 0x800F0F90: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800F0F18;
    }
    // 0x800F0F90: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800F0F94:
    // 0x800F0F94: jr          $ra
    // 0x800F0F98: nop

    return;
    // 0x800F0F98: nop

;}
RECOMP_FUNC void gcaudiolist_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800040: jal         0x800C4B70
    // 0x80800044: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800C4B70(rdram, ctx);
        goto after_0;
    // 0x80800044: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800048: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2638, 0XF0) << 16);
    // 0x80800050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800054: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800058: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8080005C: jal         0x800C4AF0
    // 0x80800060: lw          $a1, 0xF0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(2638, 0XF0));
    func_800C4AF0(rdram, ctx);
        goto after_1;
    // 0x80800060: lw          $a1, 0xF0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(2638, 0XF0));
    after_1:
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

    // 0x80800074: nop

    // 0x80800078: nop

    // 0x8080007C: nop

;}
RECOMP_FUNC void func_808007D4_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808007E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808007E8: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x808007EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007F0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x808007F4: beq         $v0, $zero, L_80800820
    if (ctx->r2 == 0) {
        // 0x808007F8: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80800820;
    }
    // 0x808007F8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808007FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800800: beq         $v0, $at, L_80800860
    if (ctx->r2 == ctx->r1) {
        // 0x80800804: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800860;
    }
    // 0x80800804: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800808: beq         $v0, $at, L_80800828
    if (ctx->r2 == ctx->r1) {
        // 0x8080080C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800828;
    }
    // 0x8080080C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800810: beql        $v0, $at, L_8080082C
    if (ctx->r2 == ctx->r1) {
        // 0x80800814: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_8080082C;
    }
    goto skip_0;
    // 0x80800814: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800818: b           L_80800870
    // 0x8080081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800870;
    // 0x8080081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800820:
    // 0x80800820: jal         0x800856B0
    // 0x80800824: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800824: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
L_80800828:
    // 0x80800828: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_8080082C:
    // 0x8080082C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800830: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800834: jal         0x800856E0
    // 0x80800838: sw          $t8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r24;
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800838: sw          $t8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r24;
    after_1:
    // 0x8080083C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800840: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80800844: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800848: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8080084C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80800850: jal         0x800880A8
    // 0x80800854: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800854: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_2:
    // 0x80800858: jal         0x800880B8
    // 0x8080085C: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x8080085C: nop

    after_3:
L_80800860:
    // 0x80800860: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800864: jal         0x800856D8
    // 0x80800868: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800868: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8080086C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800870:
    // 0x80800870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800874: jr          $ra
    // 0x80800878: nop

    return;
    // 0x80800878: nop

;}
RECOMP_FUNC void _chgobihailfire_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086328: syscall     308
    recomp_syscall_handler(rdram, ctx, 0x80086328);
    return;
    // 0x8008632C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bstnt_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FA8: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083FA8);
    return;
    // 0x80083FAC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_800D8954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8958: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x800D895C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D8960: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800D8964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8968: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D896C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800D8970: jal         0x800B32C0
    // 0x800D8974: lw          $a0, -0x3FE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3FE0);
    freelist_erase(rdram, ctx);
        goto after_0;
    // 0x800D8974: lw          $a0, -0x3FE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3FE0);
    after_0:
    // 0x800D8978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D897C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8980: jr          $ra
    // 0x800D8984: nop

    return;
    // 0x800D8984: nop

;}
RECOMP_FUNC void bafly_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080060C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800610: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800614: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800618: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080061C: lw          $t6, 0x8C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8C);
    // 0x80800620: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(528, 0XD94) << 16);
    // 0x80800624: lwc1        $f0, 0xD94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(528, 0XD94));
    // 0x80800628: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x8080062C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800630: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800634: beq         $t7, $zero, L_80800648
    if (ctx->r15 == 0) {
        // 0x80800638: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80800648;
    }
    // 0x80800638: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8080063C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(528, 0XD98) << 16);
    // 0x80800640: lwc1        $f4, 0xD98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(528, 0XD98));
    // 0x80800644: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
L_80800648:
    // 0x80800648: jal         0x800A4CA8
    // 0x8080064C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x8080064C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80800650: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800654: jal         0x80110818
    // 0x80800658: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80110818(rdram, ctx);
        goto after_1;
    // 0x80800658: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x8080065C: jal         0x8009C984
    // 0x80800660: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_get(rdram, ctx);
        goto after_2;
    // 0x80800660: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800664: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800668: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080066C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800670: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800674: jal         0x800F1DCC
    // 0x80800678: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x80800678: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_3:
    // 0x8080067C: jal         0x800F2100
    // 0x80800680: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x80800680: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x80800684: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800688: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(528, 0XD9C) << 16);
    // 0x8080068C: lwc1        $f10, 0xD9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(528, 0XD9C));
    // 0x80800690: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800694: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800698: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x8080069C: jal         0x800F10B4
    // 0x808006A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x808006A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x808006A4: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808006A8: lw          $v0, 0x8C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8C);
    // 0x808006AC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x808006B0: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808006B4: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808006B8: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x808006BC: sub.s       $f12, $f2, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x808006C0: jal         0x800F2100
    // 0x808006C4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x808006C4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x808006C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(528, 0XDA0) << 16);
    // 0x808006CC: lwc1        $f2, 0xDA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(528, 0XDA0));
    // 0x808006D0: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808006D4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808006D8: nop

    // 0x808006DC: bc1fl       L_8080070C
    if (!c1cs) {
        // 0x808006E0: lw          $v0, 0x8C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8C);
            goto L_8080070C;
    }
    goto skip_0;
    // 0x808006E0: lw          $v0, 0x8C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8C);
    skip_0:
    // 0x808006E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808006E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(528, 0XDA4) << 16);
    // 0x808006EC: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x808006F0: nop

    // 0x808006F4: bc1f        L_80800704
    if (!c1cs) {
        // 0x808006F8: nop
    
            goto L_80800704;
    }
    // 0x808006F8: nop

    // 0x808006FC: b           L_80800708
    // 0x80800700: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_80800708;
    // 0x80800700: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80800704:
    // 0x80800704: lwc1        $f12, 0xDA4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(528, 0XDA4));
L_80800708:
    // 0x80800708: lw          $v0, 0x8C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8C);
L_8080070C:
    // 0x8080070C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800710: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80800714: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80800718: lw          $v0, 0x8C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8C);
    // 0x8080071C: lbu         $s0, 0x9($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X9);
    // 0x80800720: beq         $s0, $zero, L_80800778
    if (ctx->r16 == 0) {
        // 0x80800724: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80800778;
    }
    // 0x80800724: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80800728: jal         0x800C31DC
    // 0x8080072C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    func_800C31DC(rdram, ctx);
        goto after_7;
    // 0x8080072C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    after_7:
    // 0x80800730: lw          $t8, 0x8C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8C);
    // 0x80800734: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80800738: jal         0x800C31DC
    // 0x8080073C: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    func_800C31DC(rdram, ctx);
        goto after_8;
    // 0x8080073C: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    after_8:
    // 0x80800740: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80800744: jal         0x800C3058
    // 0x80800748: addiu       $a1, $zero, 0x1770
    ctx->r5 = ADD32(0, 0X1770);
    func_800C3058(rdram, ctx);
        goto after_9;
    // 0x80800748: addiu       $a1, $zero, 0x1770
    ctx->r5 = ADD32(0, 0X1770);
    after_9:
    // 0x8080074C: jal         0x800C3D78
    // 0x80800750: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C3D78(rdram, ctx);
        goto after_10;
    // 0x80800750: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_10:
    // 0x80800754: bne         $v0, $zero, L_80800778
    if (ctx->r2 != 0) {
        // 0x80800758: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80800778;
    }
    // 0x80800758: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8080075C: jal         0x800C301C
    // 0x80800760: addiu       $a1, $zero, 0x4A3
    ctx->r5 = ADD32(0, 0X4A3);
    func_800C301C(rdram, ctx);
        goto after_11;
    // 0x80800760: addiu       $a1, $zero, 0x4A3
    ctx->r5 = ADD32(0, 0X4A3);
    after_11:
    // 0x80800764: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80800768: jal         0x800C330C
    // 0x8080076C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_12;
    // 0x8080076C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x80800770: jal         0x800C3BDC
    // 0x80800774: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C3BDC(rdram, ctx);
        goto after_13;
    // 0x80800774: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_13:
L_80800778:
    // 0x80800778: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080077C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800780: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800784: jr          $ra
    // 0x80800788: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800788: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _plcamera_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878E0: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x800878E0);
    return;
    // 0x800878E4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8008C270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C270: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8008C274: jr          $ra
    // 0x8008C278: sb          $t6, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r14;
    return;
    // 0x8008C278: sb          $t6, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void bastick_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009F118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F11C: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009F120: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009F124: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8009F128: sb          $zero, 0x64($t6)
    MEM_B(0X64, ctx->r14) = 0;
    // 0x8009F12C: lw          $t7, 0x128($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X128);
    // 0x8009F130: sb          $zero, 0x65($t7)
    MEM_B(0X65, ctx->r15) = 0;
    // 0x8009F134: lw          $t8, 0x128($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X128);
    // 0x8009F138: swc1        $f4, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f4.u32l;
    // 0x8009F13C: lw          $v0, 0x128($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X128);
    // 0x8009F140: lwc1        $f0, 0x38($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8009F144: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x8009F148: lw          $t9, 0x128($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X128);
    // 0x8009F14C: swc1        $f0, 0x60($t9)
    MEM_W(0X60, ctx->r25) = ctx->f0.u32l;
    // 0x8009F150: lw          $t0, 0x128($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X128);
    // 0x8009F154: swc1        $f0, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f0.u32l;
    // 0x8009F158: lw          $t1, 0x128($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X128);
    // 0x8009F15C: swc1        $f0, 0x54($t1)
    MEM_W(0X54, ctx->r9) = ctx->f0.u32l;
    // 0x8009F160: lw          $t3, 0x128($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X128);
    // 0x8009F164: sb          $t2, 0x67($t3)
    MEM_B(0X67, ctx->r11) = ctx->r10;
    // 0x8009F168: lw          $t4, 0x128($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X128);
    // 0x8009F16C: sw          $zero, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = 0;
    // 0x8009F170: lw          $t5, 0x128($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X128);
    // 0x8009F174: jal         0x8009F1E0
    // 0x8009F178: sb          $zero, 0x66($t5)
    MEM_B(0X66, ctx->r13) = 0;
    bastick_resetZones(rdram, ctx);
        goto after_0;
    // 0x8009F178: sb          $zero, 0x66($t5)
    MEM_B(0X66, ctx->r13) = 0;
    after_0:
    // 0x8009F17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009F184: jr          $ra
    // 0x8009F188: nop

    return;
    // 0x8009F188: nop

;}
RECOMP_FUNC void func_80025668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025668: jr          $ra
    // 0x8002566C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x8002566C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_80800B5C_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B64: jal         0x800F54E4
    // 0x80800B68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800B68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800B70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B74: jal         0x800F64A4
    // 0x80800B78: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80800B78: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_1:
    // 0x80800B7C: bne         $v0, $zero, L_80800B8C
    if (ctx->r2 != 0) {
        // 0x80800B80: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B8C;
    }
    // 0x80800B80: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B84: b           L_80800B9C
    // 0x80800B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B9C;
    // 0x80800B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B8C:
    // 0x80800B8C: jal         0x800F640C
    // 0x80800B90: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800F640C(rdram, ctx);
        goto after_2;
    // 0x80800B90: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800B94: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800B98: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80800B9C:
    // 0x80800B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BA4: jr          $ra
    // 0x80800BA8: nop

    return;
    // 0x80800BA8: nop

    // 0x80800BAC: nop

;}
RECOMP_FUNC void _bsdronejump_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083108: syscall     44
    recomp_syscall_handler(rdram, ctx, 0x80083108);
    return;
    // 0x8008310C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080024C_chlagoonbilldrillcover(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800250: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800254: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800258: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080025C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800260: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800264: jal         0x800EE7F8
    // 0x80800268: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800268: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8080026C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800270: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800274: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800280: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800284: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800288: jal         0x80086670
    // 0x8080028C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080028C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800290: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1444, 0X378) << 16);
    // 0x80800294: addiu       $t6, $t6, 0x378
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1444, 0X378));
    // 0x80800298: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080029C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808002A0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808002A4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002A8: jal         0x800BBCB8
    // 0x808002AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x808002AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808002B0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1444, 0X3B0) << 16);
    // 0x808002B4: addiu       $a2, $a2, 0x3B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1444, 0X3B0));
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: jal         0x80089D18
    // 0x808002C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808002C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x808002C4: jal         0x8010A624
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_4;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002CC: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002D8: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x808002DC: jal         0x80108B04
    // 0x808002E0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x808002E0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_5:
    // 0x808002E4: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x808002E8: srl         $t9, $a0, 7
    ctx->r25 = S32(U32(ctx->r4) >> 7);
    // 0x808002EC: jal         0x800DA544
    // 0x808002F0: addiu       $a0, $t9, 0x3C2
    ctx->r4 = ADD32(ctx->r25, 0X3C2);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x808002F0: addiu       $a0, $t9, 0x3C2
    ctx->r4 = ADD32(ctx->r25, 0X3C2);
    after_6:
    // 0x808002F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800300: jr          $ra
    // 0x80800304: nop

    return;
    // 0x80800304: nop

    // 0x80800308: nop

    // 0x8080030C: nop

;}
RECOMP_FUNC void func_80801014_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080101C: jal         0x80090A2C
    // 0x80801020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090A2C(rdram, ctx);
        goto after_0;
    // 0x80801020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801024: jal         0x800951B4
    // 0x80801028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x80801028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080102C: jal         0x808004B8
    // 0x80801030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080103C: jr          $ra
    // 0x80801040: nop

    return;
    // 0x80801040: nop

;}
RECOMP_FUNC void func_80800024_chmole_factory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800030: jal         0x800899D0
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumole_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800040: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800044: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800048: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x8080004C: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800050: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x80800054: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80800058: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8080005C: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800060: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800064: sh          $t2, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r10;
    // 0x80800068: bgez        $t4, L_8080007C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080006C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080007C;
    }
    // 0x8080006C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800074: nop

    // 0x80800078: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080007C:
    // 0x8080007C: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_80092BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092BE8: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092BEC: jr          $ra
    // 0x80092BF0: lwc1        $f0, 0x28($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X28);
    return;
    // 0x80092BF0: lwc1        $f0, 0x28($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X28);
;}
RECOMP_FUNC void _gcaudiolist_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880D8: syscall     670
    recomp_syscall_handler(rdram, ctx, 0x800880D8);
    return;
    // 0x800880DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gcfrontend_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080042C: jal         0x800D37D4
    // 0x80800430: nop

    func_800D37D4(rdram, ctx);
        goto after_0;
    // 0x80800430: nop

    after_0:
    // 0x80800434: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    // 0x80800438: jal         0x808002DC
    // 0x8080043C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_808002DC_gcfrontend(rdram, ctx);
        goto after_1;
    // 0x8080043C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x80800440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800448: jr          $ra
    // 0x8080044C: nop

    return;
    // 0x8080044C: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800084: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800088: jal         0x80100094
    // 0x8080008C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080008C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800090: lh          $t6, 0x5E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X5E);
    // 0x80800094: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800098: beql        $t6, $zero, L_808000B0
    if (ctx->r14 == 0) {
        // 0x8080009C: lbu         $v0, 0x62($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X62);
            goto L_808000B0;
    }
    goto skip_0;
    // 0x8080009C: lbu         $v0, 0x62($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X62);
    skip_0:
    // 0x808000A0: jal         0x80801054
    // 0x808000A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sumumbofx_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808000A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808000A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808000AC: lbu         $v0, 0x62($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X62);
L_808000B0:
    // 0x808000B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000B4: beq         $v0, $at, L_808000D8
    if (ctx->r2 == ctx->r1) {
        // 0x808000B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000D8;
    }
    // 0x808000B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000BC: bne         $v0, $at, L_808000D8
    if (ctx->r2 != ctx->r1) {
        // 0x808000C0: addiu       $a0, $zero, 0x1C
        ctx->r4 = ADD32(0, 0X1C);
            goto L_808000D8;
    }
    // 0x808000C0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x808000C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C8: jal         0x800FCAE0
    // 0x808000CC: addiu       $a2, $zero, 0x4E20
    ctx->r6 = ADD32(0, 0X4E20);
    func_800FCAE0(rdram, ctx);
        goto after_2;
    // 0x808000CC: addiu       $a2, $zero, 0x4E20
    ctx->r6 = ADD32(0, 0X4E20);
    after_2:
    // 0x808000D0: jal         0x800FCA90
    // 0x808000D4: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FCA90(rdram, ctx);
        goto after_3;
    // 0x808000D4: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_3:
L_808000D8:
    // 0x808000D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808000E0: jal         0x80100074
    // 0x808000E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_4;
    // 0x808000E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808000E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000F0: jr          $ra
    // 0x808000F4: nop

    return;
    // 0x808000F4: nop

;}
RECOMP_FUNC void chfactoryroofbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2280, 0XAA4) << 16);
    // 0x808007B0: jr          $ra
    // 0x808007B4: addiu       $v0, $v0, 0xAA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0XAA4));
    return;
    // 0x808007B4: addiu       $v0, $v0, 0xAA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0XAA4));
;}
RECOMP_FUNC void chfishshootgame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(740, 0X1A7C) << 16);
    // 0x808017A4: jr          $ra
    // 0x808017A8: addiu       $v0, $v0, 0x1A7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(740, 0X1A7C));
    return;
    // 0x808017A8: addiu       $v0, $v0, 0x1A7C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(740, 0X1A7C));
    // 0x808017AC: nop

;}
RECOMP_FUNC void _chhotwaterpoolbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086428: syscall     323
    recomp_syscall_handler(rdram, ctx, 0x80086428);
    return;
    // 0x8008642C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bskazshock_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083578: syscall     66
    recomp_syscall_handler(rdram, ctx, 0x80083578);
    return;
    // 0x8008357C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void __bastick_zoneCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EF40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EF48: jal         0x8001BBC8
    // 0x8009EF4C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    aligned4_memcpy(rdram, ctx);
        goto after_0;
    // 0x8009EF4C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_0:
    // 0x8009EF50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EF54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EF58: jr          $ra
    // 0x8009EF5C: nop

    return;
    // 0x8009EF5C: nop

;}
RECOMP_FUNC void bswasher_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EB4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800EB8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1E40) << 16);
    // 0x80800EBC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800EC0: jr          $ra
    // 0x80800EC4: lw          $v0, 0x1E40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E40));
    return;
    // 0x80800EC4: lw          $v0, 0x1E40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E40));
;}
RECOMP_FUNC void _sumumbofx_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898D8: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898D8);
    return;
    // 0x800898DC: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_808004AC_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004B8: jal         0x80093230
    // 0x808004BC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80093230(rdram, ctx);
        goto after_0;
    // 0x808004BC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x808004C0: jal         0x8080008C
    // 0x808004C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080008C_bsride(rdram, ctx);
        goto after_1;
    // 0x808004C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808004C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004D0: jr          $ra
    // 0x808004D4: nop

    return;
    // 0x808004D4: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080054C: jal         0x80800018
    // 0x80800550: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80800018_glcutDll(rdram, ctx);
        goto after_0;
    // 0x80800550: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80800554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080055C: jr          $ra
    // 0x80800560: nop

    return;
    // 0x80800560: nop

;}
RECOMP_FUNC void chcauldronentrydoor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2004, 0X598) << 16);
    // 0x80800500: jr          $ra
    // 0x80800504: addiu       $v0, $v0, 0x598
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2004, 0X598));
    return;
    // 0x80800504: addiu       $v0, $v0, 0x598
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2004, 0X598));
    // 0x80800508: nop

    // 0x8080050C: nop

;}
RECOMP_FUNC void _gcgoto_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A80: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087A80);
    return;
    // 0x80087A84: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void bsblongleg_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808013A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(104, 0X14D0) << 16);
    // 0x808013AC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808013B0: jr          $ra
    // 0x808013B4: lw          $v0, 0x14D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14D0));
    return;
    // 0x808013B4: lw          $v0, 0x14D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14D0));
;}
RECOMP_FUNC void bsbreegullbash_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800260: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800264: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080026C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80800270: jal         0x8008CCBC
    // 0x80800274: lui         $a2, 0x3FE0
    ctx->r6 = S32(0X3FE0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x80800274: lui         $a2, 0x3FE0
    ctx->r6 = S32(0X3FE0 << 16);
    after_0:
    // 0x80800278: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8080027C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800288: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080028C: jal         0x8009FFD8
    // 0x80800290: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800290: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800294: jal         0x8009C990
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_2;
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080029C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002A0: jal         0x8009B9C0
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_3;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002A8: jal         0x8009E4AC
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_4;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002B8: jal         0x8009E4E0
    // 0x808002BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009E4E0(rdram, ctx);
        goto after_5;
    // 0x808002BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002C8: jal         0x8009E55C
    // 0x808002CC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_6;
    // 0x808002CC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: jal         0x8009B9B0
    // 0x808002D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x808002D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x808002DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002E8: jr          $ra
    // 0x808002EC: nop

    return;
    // 0x808002EC: nop

;}
RECOMP_FUNC void func_80800864_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800868: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080086C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800870: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800874: beq         $a1, $at, L_80800890
    if (ctx->r5 == ctx->r1) {
        // 0x80800878: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800890;
    }
    // 0x80800878: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080087C: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800880: beq         $a1, $at, L_808008B8
    if (ctx->r5 == ctx->r1) {
        // 0x80800884: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_808008B8;
    }
    // 0x80800884: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800888: b           L_808009BC
    // 0x8080088C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009BC;
    // 0x8080088C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800890:
    // 0x80800890: addiu       $a0, $zero, 0x316
    ctx->r4 = ADD32(0, 0X316);
    // 0x80800894: jal         0x801084B0
    // 0x80800898: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80800898: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8080089C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808008A0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808008A4: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x808008A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x808008AC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x808008B0: b           L_808009B8
    // 0x808008B4: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
        goto L_808009B8;
    // 0x808008B4: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
L_808008B8:
    // 0x808008B8: lw          $a0, 0x3C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X3C);
    // 0x808008BC: beql        $a0, $zero, L_808009BC
    if (ctx->r4 == 0) {
        // 0x808008C0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808009BC;
    }
    goto skip_0;
    // 0x808008C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808008C4: jal         0x80106790
    // 0x808008C8: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808008C8: nop

    after_1:
    // 0x808008CC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808008D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808008D4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x808008D8: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x808008DC: srl         $t3, $t2, 22
    ctx->r11 = S32(U32(ctx->r10) >> 22);
    // 0x808008E0: bnel        $t3, $zero, L_808009BC
    if (ctx->r11 != 0) {
        // 0x808008E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808009BC;
    }
    goto skip_1;
    // 0x808008E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808008E8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x808008EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008F0: lw          $v0, 0x18($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X18);
    // 0x808008F4: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x808008F8: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x808008FC: beq         $t7, $at, L_80800914
    if (ctx->r15 == ctx->r1) {
        // 0x80800900: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800914;
    }
    // 0x80800900: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800904: beql        $t7, $at, L_8080097C
    if (ctx->r15 == ctx->r1) {
        // 0x80800908: lbu         $t6, 0x65($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X65);
            goto L_8080097C;
    }
    goto skip_2;
    // 0x80800908: lbu         $t6, 0x65($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X65);
    skip_2:
    // 0x8080090C: b           L_808009BC
    // 0x80800910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x80800910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800914:
    // 0x80800914: lbu         $t9, 0x65($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X65);
    // 0x80800918: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080091C: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80800920: jal         0x80090178
    // 0x80800924: sb          $t0, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r8;
    func_80090178(rdram, ctx);
        goto after_2;
    // 0x80800924: sb          $t0, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r8;
    after_2:
    // 0x80800928: beq         $v0, $zero, L_80800950
    if (ctx->r2 == 0) {
        // 0x8080092C: lw          $t1, 0x20($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X20);
            goto L_80800950;
    }
    // 0x8080092C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80800930: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800938: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080093C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800940: jal         0x80087AD8
    // 0x80800944: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _gcsectionskip_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800944: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80800948: b           L_808009BC
    // 0x8080094C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x8080094C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800950:
    // 0x80800950: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x80800954: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80800958: addiu       $a1, $zero, 0x121E
    ctx->r5 = ADD32(0, 0X121E);
    // 0x8080095C: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80800960: bltzl       $t4, L_808009BC
    if (SIGNED(ctx->r12) < 0) {
        // 0x80800964: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808009BC;
    }
    goto skip_3;
    // 0x80800964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800968: jal         0x80800818
    // 0x8080096C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800818_chchuffy(rdram, ctx);
        goto after_4;
    // 0x8080096C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800970: b           L_808009BC
    // 0x80800974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x80800974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800978: lbu         $t6, 0x65($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X65);
L_8080097C:
    // 0x8080097C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800980: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80800984: jal         0x80090178
    // 0x80800988: sb          $t7, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r15;
    func_80090178(rdram, ctx);
        goto after_5;
    // 0x80800988: sb          $t7, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r15;
    after_5:
    // 0x8080098C: beq         $v0, $zero, L_808009B8
    if (ctx->r2 == 0) {
        // 0x80800990: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808009B8;
    }
    // 0x80800990: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800998: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080099C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x808009A0: jal         0x80087AD8
    // 0x808009A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _gcsectionskip_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808009A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x808009A8: b           L_808009BC
    // 0x808009AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x808009AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808009B0: b           L_808009BC
    // 0x808009B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009BC;
    // 0x808009B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009B8:
    // 0x808009B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009BC:
    // 0x808009BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009C4: jr          $ra
    // 0x808009C8: nop

    return;
    // 0x808009C8: nop

;}
RECOMP_FUNC void func_80806CC0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806CC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806CC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806CC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806CCC: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80806CD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80806CD4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80806CD8: lw          $a2, 0x64($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X64);
    // 0x80806CDC: bltz        $a2, L_80806CF8
    if (SIGNED(ctx->r6) < 0) {
        // 0x80806CE0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80806CF8;
    }
    // 0x80806CE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80806CE4: jal         0x800F7B9C
    // 0x80806CE8: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    func_800F7B9C(rdram, ctx);
        goto after_0;
    // 0x80806CE8: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    after_0:
    // 0x80806CEC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80806CF0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80806CF4: sw          $t8, 0x64($t9)
    MEM_W(0X64, ctx->r25) = ctx->r24;
L_80806CF8:
    // 0x80806CF8: jal         0x8080175C
    // 0x80806CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080175C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80806CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80806D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806D04: jal         0x800936E8
    // 0x80806D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800936E8(rdram, ctx);
        goto after_2;
    // 0x80806D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80806D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806D10: jal         0x8009337C
    // 0x80806D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009337C(rdram, ctx);
        goto after_3;
    // 0x80806D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80806D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806D1C: jal         0x80801B64
    // 0x80806D20: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801B64_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80806D20: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80806D24: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80806D28: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80806D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806D30: jal         0x80808DB0
    // 0x80806D34: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    func_80808DB0_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80806D34: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    after_5:
    // 0x80806D38: jal         0x80807C8C
    // 0x80806D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80806D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80806D40: jal         0x800A16BC
    // 0x80806D44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A16BC(rdram, ctx);
        goto after_7;
    // 0x80806D44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80806D48: jal         0x800844B8
    // 0x80806D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x80806D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80806D50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80806D54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80806D58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80806D5C: jr          $ra
    // 0x80806D60: nop

    return;
    // 0x80806D60: nop

;}
RECOMP_FUNC void _bsbbilldrill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082798: syscall     12
    recomp_syscall_handler(rdram, ctx, 0x80082798);
    return;
    // 0x8008279C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _capod_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085700: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085700);
    return;
    // 0x80085704: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_800B5E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5E04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B5E08: lw          $a0, -0x7E80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7E80);
    // 0x800B5E0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5E10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5E14: beql        $a0, $zero, L_800B5E30
    if (ctx->r4 == 0) {
        // 0x800B5E18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B5E30;
    }
    goto skip_0;
    // 0x800B5E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B5E1C: jal         0x800B2D28
    // 0x800B5E20: nop

    vector_free(rdram, ctx);
        goto after_0;
    // 0x800B5E20: nop

    after_0:
    // 0x800B5E24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B5E28: sw          $zero, -0x7E80($at)
    MEM_W(-0X7E80, ctx->r1) = 0;
    // 0x800B5E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B5E30:
    // 0x800B5E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B5E34: jr          $ra
    // 0x800B5E38: nop

    return;
    // 0x800B5E38: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808051F4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808051F8: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB550) << 16);
    // 0x808051FC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80805200: jr          $ra
    // 0x80805204: lw          $v0, -0x4AB0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB550));
    return;
    // 0x80805204: lw          $v0, -0x4AB0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB550));
;}
RECOMP_FUNC void _baeggsetup_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A50: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A50);
    return;
    // 0x80084A54: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chmoley_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1556, 0XC10) << 16);
    // 0x808009EC: jr          $ra
    // 0x808009F0: addiu       $v0, $v0, 0xC10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1556, 0XC10));
    return;
    // 0x808009F0: addiu       $v0, $v0, 0xC10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1556, 0XC10));
    // 0x808009F4: nop

    // 0x808009F8: nop

    // 0x808009FC: nop

;}
