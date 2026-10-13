#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800148_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080014C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800150: jal         0x801065A4
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801065A4(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800158: beq         $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x8080015C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800168;
    }
    // 0x8080015C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800160: jal         0x80088898
    // 0x80800164: nop

    _glidmake_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800164: nop

    after_1:
L_80800168:
    // 0x80800168: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800170: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800174: jal         0x800888A0
    // 0x80800178: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    _glidmake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800178: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    after_2:
    // 0x8080017C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800180: jal         0x8010647C
    // 0x80800184: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010647C(rdram, ctx);
        goto after_3;
    // 0x80800184: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080018C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800190: jr          $ra
    // 0x80800194: nop

    return;
    // 0x80800194: nop

;}
RECOMP_FUNC void func_80800910_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800918: jal         0x80800198
    // 0x8080091C: nop

    bssnowball_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080091C: nop

    after_0:
    // 0x80800920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800928: jr          $ra
    // 0x8080092C: nop

    return;
    // 0x8080092C: nop

;}
RECOMP_FUNC void chmole_prehist_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1836, 0XF0) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1836, 0XF0));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1836, 0XF0));
;}
RECOMP_FUNC void bsbtrot_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080104C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801050: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2E70) << 16);
    // 0x80801054: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801058: jr          $ra
    // 0x8080105C: lw          $v0, 0x2E70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2E70));
    return;
    // 0x8080105C: lw          $v0, 0x2E70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2E70));
;}
RECOMP_FUNC void _bskazjump_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834A8: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x800834A8);
    return;
    // 0x800834AC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _sumumbofx_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089878: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089878);
    return;
    // 0x8008987C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _sujiggy_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6D8: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6D8);
    return;
    // 0x8008A6DC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084048: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084048);
    return;
    // 0x8008404C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void chpoolkids_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1092, 0X1438) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1438
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1092, 0X1438));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1438
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1092, 0X1438));
;}
RECOMP_FUNC void dbmorph_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: jr          $ra
    // 0x8080004C: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    return;
    // 0x8080004C: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
;}
RECOMP_FUNC void func_800EE8CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE8CC: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x800EE8D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800EE8D4: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x800EE8D8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800EE8DC: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x800EE8E0: jr          $ra
    // 0x800EE8E4: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    return;
    // 0x800EE8E4: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void bstaxi_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A04: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A08: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(392, 0X2198) << 16);
    // 0x80800A0C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A10: jr          $ra
    // 0x80800A14: lw          $v0, 0x2198($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X2198));
    return;
    // 0x80800A14: lw          $v0, 0x2198($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X2198));
;}
RECOMP_FUNC void func_808012C8_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808012CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808012D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808012D4: bne         $a1, $zero, L_808012EC
    if (ctx->r5 != 0) {
        // 0x808012D8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_808012EC;
    }
    // 0x808012D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808012DC: jal         0x800D395C
    // 0x808012E0: nop

    func_800D395C(rdram, ctx);
        goto after_0;
    // 0x808012E0: nop

    after_0:
    // 0x808012E4: beql        $v0, $zero, L_80801320
    if (ctx->r2 == 0) {
        // 0x808012E8: lbu         $t0, 0x65($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X65);
            goto L_80801320;
    }
    goto skip_0;
    // 0x808012E8: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    skip_0:
L_808012EC:
    // 0x808012EC: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808012F0: lbu         $a1, 0x79($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X79);
    // 0x808012F4: addiu       $a0, $zero, 0x18B1
    ctx->r4 = ADD32(0, 0X18B1);
    // 0x808012F8: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x808012FC: srl         $t9, $a1, 4
    ctx->r25 = S32(U32(ctx->r5) >> 4);
    // 0x80801300: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80801304: addiu       $a1, $t9, 0x12
    ctx->r5 = ADD32(ctx->r25, 0X12);
    // 0x80801308: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080130C: jal         0x800861A0
    // 0x80801310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80801314: b           L_80801334
    // 0x80801318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801334;
    // 0x80801318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080131C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
L_80801320:
    // 0x80801320: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801324: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80801328: jal         0x800861A8
    // 0x8080132C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080132C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_2:
    // 0x80801330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801334:
    // 0x80801334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080133C: jr          $ra
    // 0x80801340: nop

    return;
    // 0x80801340: nop

;}
RECOMP_FUNC void func_800CD23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD23C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800CD240: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CD244: lwc1        $f4, -0x4FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4FF0);
    // 0x800CD248: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800CD24C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800CD250: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800CD254: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800CD258: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CD25C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800CD260: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800CD264: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800CD268: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800CD26C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800CD270: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800CD274: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800CD278: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800CD27C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800CD280: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800CD284: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800CD288: jal         0x800BD708
    // 0x800CD28C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800BD708(rdram, ctx);
        goto after_0;
    // 0x800CD28C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800CD290: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800CD294: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CD298: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800CD29C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800CD2A0: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800CD2A4: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800CD2A8: bne         $at, $zero, L_800CD358
    if (ctx->r1 != 0) {
        // 0x800CD2AC: sw          $t8, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r24;
            goto L_800CD358;
    }
    // 0x800CD2AC: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x800CD2B0: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x800CD2B4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800CD2B8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_800CD2BC:
    // 0x800CD2BC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800CD2C0: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CD2C4: bne         $at, $zero, L_800CD340
    if (ctx->r1 != 0) {
        // 0x800CD2C8: sw          $a0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r4;
            goto L_800CD340;
    }
    // 0x800CD2C8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800CD2CC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
L_800CD2D0:
    // 0x800CD2D0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CD2D4: bne         $at, $zero, L_800CD32C
    if (ctx->r1 != 0) {
        // 0x800CD2D8: sw          $v0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r2;
            goto L_800CD32C;
    }
    // 0x800CD2D8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CD2DC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
L_800CD2E0:
    // 0x800CD2E0: jal         0x800BDAD4
    // 0x800CD2E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BDAD4(rdram, ctx);
        goto after_1;
    // 0x800CD2E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800CD2E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CD2EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CD2F0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800CD2F4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800CD2F8: jal         0x800EA628
    // 0x800CD2FC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800EA628(rdram, ctx);
        goto after_2;
    // 0x800CD2FC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800CD300: beql        $v0, $zero, L_800CD310
    if (ctx->r2 == 0) {
        // 0x800CD304: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_800CD310;
    }
    goto skip_0;
    // 0x800CD304: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x800CD308: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800CD30C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_800CD310:
    // 0x800CD310: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800CD314: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CD318: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CD31C: beq         $at, $zero, L_800CD2E0
    if (ctx->r1 == 0) {
        // 0x800CD320: sw          $v0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r2;
            goto L_800CD2E0;
    }
    // 0x800CD320: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CD324: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800CD328: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_800CD32C:
    // 0x800CD32C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CD330: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CD334: beql        $at, $zero, L_800CD2D0
    if (ctx->r1 == 0) {
        // 0x800CD338: lw          $v0, 0x50($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X50);
            goto L_800CD2D0;
    }
    goto skip_1;
    // 0x800CD338: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    skip_1:
    // 0x800CD33C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
L_800CD340:
    // 0x800CD340: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800CD344: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800CD348: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800CD34C: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CD350: beq         $at, $zero, L_800CD2BC
    if (ctx->r1 == 0) {
        // 0x800CD354: sw          $t1, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r9;
            goto L_800CD2BC;
    }
    // 0x800CD354: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
L_800CD358:
    // 0x800CD358: jal         0x800BDC44
    // 0x800CD35C: nop

    func_800BDC44(rdram, ctx);
        goto after_3;
    // 0x800CD35C: nop

    after_3:
    // 0x800CD360: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CD364: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CD368: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800CD36C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800CD370: jal         0x800EA628
    // 0x800CD374: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800EA628(rdram, ctx);
        goto after_4;
    // 0x800CD374: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_4:
    // 0x800CD378: beq         $v0, $zero, L_800CD384
    if (ctx->r2 == 0) {
        // 0x800CD37C: lw          $s0, 0x1C($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X1C);
            goto L_800CD384;
    }
    // 0x800CD37C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD380: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_800CD384:
    // 0x800CD384: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800CD388: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x800CD38C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800CD390: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800CD394: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800CD398: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800CD39C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD3A0: jr          $ra
    // 0x800CD3A4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800CD3A4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8001A270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A278: jal         0x8001A1E0
    // 0x8001A27C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_8001A1E0(rdram, ctx);
        goto after_0;
    // 0x8001A27C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_0:
    // 0x8001A280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A288: jr          $ra
    // 0x8001A28C: nop

    return;
    // 0x8001A28C: nop

;}
RECOMP_FUNC void _bsbreegullbash_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AE8: syscall     26
    recomp_syscall_handler(rdram, ctx, 0x80082AE8);
    return;
    // 0x80082AEC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800358_basub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800358: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x8080035C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x80800360: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800364: bnel        $a1, $t6, L_80800388
    if (ctx->r5 != ctx->r14) {
        // 0x80800368: lw          $t9, 0x30($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X30);
            goto L_80800388;
    }
    goto skip_0;
    // 0x80800368: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    skip_0:
    // 0x8080036C: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80800370: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x80800374: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x80800378: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080037C: jr          $ra
    // 0x80800380: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    return;
    // 0x80800380: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    // 0x80800384: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
L_80800388:
    // 0x80800388: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8080038C: addiu       $a3, $v1, 0x8
    ctx->r7 = ADD32(ctx->r3, 0X8);
    // 0x80800390: bnel        $a1, $t9, L_808003B4
    if (ctx->r5 != ctx->r25) {
        // 0x80800394: addiu       $v0, $zero, 0x28
        ctx->r2 = ADD32(0, 0X28);
            goto L_808003B4;
    }
    goto skip_1;
    // 0x80800394: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    skip_1:
    // 0x80800398: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x8080039C: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x808003A0: lw          $t0, 0x28($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X28);
    // 0x808003A4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x808003A8: jr          $ra
    // 0x808003AC: sw          $t1, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r9;
    return;
    // 0x808003AC: sw          $t1, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r9;
    // 0x808003B0: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
L_808003B4:
    // 0x808003B4: lw          $t2, 0x2C($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X2C);
    // 0x808003B8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x808003BC: bnel        $a1, $t2, L_808003E0
    if (ctx->r5 != ctx->r10) {
        // 0x808003C0: lw          $t5, 0x30($a3)
        ctx->r13 = MEM_W(ctx->r7, 0X30);
            goto L_808003E0;
    }
    goto skip_2;
    // 0x808003C0: lw          $t5, 0x30($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X30);
    skip_2:
    // 0x808003C4: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x808003C8: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x808003CC: lw          $t3, 0x28($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X28);
    // 0x808003D0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x808003D4: jr          $ra
    // 0x808003D8: sw          $t4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r12;
    return;
    // 0x808003D8: sw          $t4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r12;
    // 0x808003DC: lw          $t5, 0x30($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X30);
L_808003E0:
    // 0x808003E0: bnel        $a1, $t5, L_80800404
    if (ctx->r5 != ctx->r13) {
        // 0x808003E4: lw          $t8, 0x34($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X34);
            goto L_80800404;
    }
    goto skip_3;
    // 0x808003E4: lw          $t8, 0x34($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X34);
    skip_3:
    // 0x808003E8: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x808003EC: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x808003F0: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x808003F4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808003F8: jr          $ra
    // 0x808003FC: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
    return;
    // 0x808003FC: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
    // 0x80800400: lw          $t8, 0x34($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X34);
L_80800404:
    // 0x80800404: bnel        $a1, $t8, L_80800428
    if (ctx->r5 != ctx->r24) {
        // 0x80800408: lw          $t1, 0x38($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X38);
            goto L_80800428;
    }
    goto skip_4;
    // 0x80800408: lw          $t1, 0x38($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X38);
    skip_4:
    // 0x8080040C: sw          $zero, 0x34($a3)
    MEM_W(0X34, ctx->r7) = 0;
    // 0x80800410: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x80800414: lw          $t9, 0x28($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X28);
    // 0x80800418: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8080041C: jr          $ra
    // 0x80800420: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
    return;
    // 0x80800420: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
    // 0x80800424: lw          $t1, 0x38($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X38);
L_80800428:
    // 0x80800428: bne         $a1, $t1, L_80800448
    if (ctx->r5 != ctx->r9) {
        // 0x8080042C: nop
    
            goto L_80800448;
    }
    // 0x8080042C: nop

    // 0x80800430: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x80800434: lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X130);
    // 0x80800438: lw          $t2, 0x28($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X28);
    // 0x8080043C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80800440: jr          $ra
    // 0x80800444: sw          $t3, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r11;
    return;
    // 0x80800444: sw          $t3, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r11;
L_80800448:
    // 0x80800448: bne         $a2, $v0, L_808003B4
    if (ctx->r6 != ctx->r2) {
        // 0x8080044C: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_808003B4;
    }
    // 0x8080044C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80800450: jr          $ra
    // 0x80800454: nop

    return;
    // 0x80800454: nop

;}
RECOMP_FUNC void _chaliendad_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865F8: syscall     347
    recomp_syscall_handler(rdram, ctx, 0x800865F8);
    return;
    // 0x800865FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800CF8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF8D0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800CF8D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800CF8D8: addiu       $v0, $v0, -0x518C
    ctx->r2 = ADD32(ctx->r2, -0X518C);
    // 0x800CF8DC: addiu       $v1, $v1, -0x5194
    ctx->r3 = ADD32(ctx->r3, -0X5194);
    // 0x800CF8E0: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
L_800CF8E4:
    // 0x800CF8E4: bnel        $a0, $t6, L_800CF904
    if (ctx->r4 != ctx->r14) {
        // 0x800CF8E8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800CF904;
    }
    goto skip_0;
    // 0x800CF8E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x800CF8EC: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x800CF8F0: bnel        $a1, $t7, L_800CF904
    if (ctx->r5 != ctx->r15) {
        // 0x800CF8F4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800CF904;
    }
    goto skip_1;
    // 0x800CF8F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_1:
    // 0x800CF8F8: jr          $ra
    // 0x800CF8FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800CF8FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CF900: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800CF904:
    // 0x800CF904: bnel        $v1, $v0, L_800CF8E4
    if (ctx->r3 != ctx->r2) {
        // 0x800CF908: lh          $t6, 0x0($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X0);
            goto L_800CF8E4;
    }
    goto skip_2;
    // 0x800CF908: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    skip_2:
    // 0x800CF90C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF910: jr          $ra
    // 0x800CF914: nop

    return;
    // 0x800CF914: nop

;}
RECOMP_FUNC void func_808007D0_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007DC: lbu         $v0, 0x60($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X60);
    // 0x808007E0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808007E4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808007E8: beq         $v0, $at, L_80800808
    if (ctx->r2 == ctx->r1) {
        // 0x808007EC: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800808;
    }
    // 0x808007EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808007F0: beq         $v0, $at, L_80800808
    if (ctx->r2 == ctx->r1) {
        // 0x808007F4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800808;
    }
    // 0x808007F4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808007F8: beql        $v0, $at, L_80800844
    if (ctx->r2 == ctx->r1) {
        // 0x808007FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800844;
    }
    goto skip_0;
    // 0x808007FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800800: b           L_80800844
    // 0x80800804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800844;
    // 0x80800804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800808:
    // 0x80800808: jal         0x8001B798
    // 0x8080080C: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x8080080C: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x80800810: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800814: jal         0x80089DE0
    // 0x80800818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suspline_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080081C: jal         0x80089DA8
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suspline_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800824: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800828: jal         0x80089DC0
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suspline_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800830: jal         0x80089DE8
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suspline_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800838: jal         0x80089E00
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suspline_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800844:
    // 0x80800844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800848: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080084C: jr          $ra
    // 0x80800850: nop

    return;
    // 0x80800850: nop

;}
RECOMP_FUNC void func_80026238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026238: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002623C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026240: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026244: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80026248: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002624C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80026250: lbu         $t7, 0x2B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2B);
    // 0x80026254: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80026258: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002625C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80026260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80026264: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80026268: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8002626C: jal         0x8002ACE0
    // 0x80026270: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_8002ACE0(rdram, ctx);
        goto after_0;
    // 0x80026270: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80026274: b           L_8002627C
    // 0x80026278: nop

        goto L_8002627C;
    // 0x80026278: nop

L_8002627C:
    // 0x8002627C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026280: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026284: jr          $ra
    // 0x80026288: nop

    return;
    // 0x80026288: nop

;}
RECOMP_FUNC void func_80800B64_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B70: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800B74: jal         0x80088078
    // 0x80800B78: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800B78: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800B7C: beq         $v0, $zero, L_80800BAC
    if (ctx->r2 == 0) {
        // 0x80800B80: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800BAC;
    }
    // 0x80800B80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B84: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800B88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B90: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800B94: beq         $t7, $at, L_80800BA4
    if (ctx->r15 == ctx->r1) {
        // 0x80800B98: nop
    
            goto L_80800BA4;
    }
    // 0x80800B98: nop

    // 0x80800B9C: jal         0x80800C08
    // 0x80800BA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800C08_chbottlesfamily(rdram, ctx);
        goto after_1;
    // 0x80800BA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80800BA4:
    // 0x80800BA4: b           L_80800BB0
    // 0x80800BA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800BB0;
    // 0x80800BA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800BAC:
    // 0x80800BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BB0:
    // 0x80800BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BB8: jr          $ra
    // 0x80800BBC: nop

    return;
    // 0x80800BBC: nop

;}
RECOMP_FUNC void _chlagoonufoint_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A60: syscall     190
    recomp_syscall_handler(rdram, ctx, 0x80085A60);
    return;
    // 0x80085A64: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808000C8_chgobihailfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000D4: jal         0x80086770
    // 0x808000D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _chgobicommon_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808000D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000DC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808000E0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000E4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000E8: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x808000EC: beq         $at, $zero, L_808002E4
    if (ctx->r1 == 0) {
        // 0x808000F0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808002E4;
    }
    // 0x808000F0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1208, 0X700) << 16);
    // 0x808000F8: addu        $at, $at, $t8
    gpr jr_addend_80800100 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000FC: lw          $t8, 0x700($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1208, 0X700));
    // 0x80800100: jr          $t8
    // 0x80800104: nop

    switch (jr_addend_80800100 >> 2) {
        case 0: goto L_80800108; break;
        case 1: goto L_808001A0; break;
        case 2: goto L_808002E4; break;
        case 3: goto L_808002E4; break;
        case 4: goto L_808001D4; break;
        case 5: goto L_80800248; break;
        case 6: goto L_8080029C; break;
        case 7: goto L_808002CC; break;
        default: switch_error(__func__, 0x80800100, 0x80800700);
    }
    // 0x80800104: nop

L_80800108:
    // 0x80800108: jal         0x800D9078
    // 0x8080010C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x8080010C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800110: beq         $v0, $zero, L_80800130
    if (ctx->r2 == 0) {
        // 0x80800114: addiu       $a1, $zero, 0x126E
        ctx->r5 = ADD32(0, 0X126E);
            goto L_80800130;
    }
    // 0x80800114: addiu       $a1, $zero, 0x126E
    ctx->r5 = ADD32(0, 0X126E);
    // 0x80800118: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080011C: addiu       $t9, $zero, 0x38
    ctx->r25 = ADD32(0, 0X38);
    // 0x80800120: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800124: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800128: jal         0x8008A208
    // 0x8080012C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x8080012C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
L_80800130:
    // 0x80800130: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800134: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800138: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080013C: nop

    // 0x80800140: bc1f        L_808002E4
    if (!c1cs) {
        // 0x80800144: nop
    
            goto L_808002E4;
    }
    // 0x80800144: nop

    // 0x80800148: jal         0x80105834
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_3;
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800150: jal         0x80105A5C
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_4;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800158: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x8080015C: nop
    
            goto L_808002E4;
    }
    // 0x8080015C: nop

    // 0x80800160: jal         0x800FFAB0
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800168: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x8080016C: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x80800170: addiu       $a2, $zero, 0x47
    ctx->r6 = ADD32(0, 0X47);
    // 0x80800174: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x80800178: bgez        $t2, L_80800190
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8080017C: addiu       $a0, $zero, 0x129
        ctx->r4 = ADD32(0, 0X129);
            goto L_80800190;
    }
    // 0x8080017C: addiu       $a0, $zero, 0x129
    ctx->r4 = ADD32(0, 0X129);
    // 0x80800180: jal         0x80088868
    // 0x80800184: addiu       $a0, $zero, 0x129
    ctx->r4 = ADD32(0, 0X129);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_6;
    // 0x80800184: addiu       $a0, $zero, 0x129
    ctx->r4 = ADD32(0, 0X129);
    after_6:
    // 0x80800188: b           L_808002E4
    // 0x8080018C: nop

        goto L_808002E4;
    // 0x8080018C: nop

L_80800190:
    // 0x80800190: jal         0x800887D8
    // 0x80800194: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80800194: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    after_7:
    // 0x80800198: b           L_808002E4
    // 0x8080019C: nop

        goto L_808002E4;
    // 0x8080019C: nop

L_808001A0:
    // 0x808001A0: jal         0x80105834
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_8;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001A8: jal         0x80105A5C
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_9;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001B0: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x808001B4: nop
    
            goto L_808002E4;
    }
    // 0x808001B4: nop

    // 0x808001B8: jal         0x800DA544
    // 0x808001BC: addiu       $a0, $zero, 0x1C6
    ctx->r4 = ADD32(0, 0X1C6);
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x808001BC: addiu       $a0, $zero, 0x1C6
    ctx->r4 = ADD32(0, 0X1C6);
    after_10:
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: jal         0x80102424
    // 0x808001C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808001C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x808001CC: b           L_808002E4
    // 0x808001D0: nop

        goto L_808002E4;
    // 0x808001D0: nop

L_808001D4:
    // 0x808001D4: jal         0x800878B0
    // 0x808001D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x808001D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_12:
    // 0x808001DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001E0: beq         $v0, $at, L_808002E4
    if (ctx->r2 == ctx->r1) {
        // 0x808001E4: nop
    
            goto L_808002E4;
    }
    // 0x808001E4: nop

    // 0x808001E8: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x808001EC: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x808001F0: bgez        $t5, L_808002E4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808001F4: nop
    
            goto L_808002E4;
    }
    // 0x808001F4: nop

    // 0x808001F8: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x808001FC: addiu       $a1, $zero, 0x12C3
    ctx->r5 = ADD32(0, 0X12C3);
    // 0x80800200: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800204: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80800208: bltz        $t8, L_8080022C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080020C: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_8080022C;
    }
    // 0x8080020C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800210: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    // 0x80800214: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800218: addiu       $t2, $zero, 0x38
    ctx->r10 = ADD32(0, 0X38);
    // 0x8080021C: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x80800220: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
    // 0x80800224: jal         0x8008A208
    // 0x80800228: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800228: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_13:
L_8080022C:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x80102424
    // 0x80800234: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800234: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_14:
    // 0x80800238: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1208, 0X720) << 16);
    // 0x8080023C: lwc1        $f8, 0x720($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1208, 0X720));
    // 0x80800240: b           L_808002E4
    // 0x80800244: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_808002E4;
    // 0x80800244: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800248:
    // 0x80800248: jal         0x800878B0
    // 0x8080024C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x8080024C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_15:
    // 0x80800250: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800254: beq         $v0, $at, L_80800270
    if (ctx->r2 == ctx->r1) {
        // 0x80800258: nop
    
            goto L_80800270;
    }
    // 0x80800258: nop

    // 0x8080025C: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80800260: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1208, 0X724) << 16);
    // 0x80800264: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80800268: bltz        $t5, L_80800290
    if (SIGNED(ctx->r13) < 0) {
        // 0x8080026C: nop
    
            goto L_80800290;
    }
    // 0x8080026C: nop

L_80800270:
    // 0x80800270: jal         0x800D9078
    // 0x80800274: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_16;
    // 0x80800274: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_16:
    // 0x80800278: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x8080027C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E4;
    }
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x80102424
    // 0x80800284: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x80800284: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_17:
    // 0x80800288: b           L_808002E4
    // 0x8080028C: nop

        goto L_808002E4;
    // 0x8080028C: nop

L_80800290:
    // 0x80800290: lwc1        $f10, 0x724($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1208, 0X724));
    // 0x80800294: b           L_808002E4
    // 0x80800298: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_808002E4;
    // 0x80800298: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_8080029C:
    // 0x8080029C: jal         0x80101DDC
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_18;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808002A4: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x808002A8: nop
    
            goto L_808002E4;
    }
    // 0x808002A8: nop

    // 0x808002AC: jal         0x800FFA88
    // 0x808002B0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_800FFA88(rdram, ctx);
        goto after_19;
    // 0x808002B0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_19:
    // 0x808002B4: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: jal         0x80102424
    // 0x808002C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x808002C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_20:
    // 0x808002C4: b           L_808002E4
    // 0x808002C8: nop

        goto L_808002E4;
    // 0x808002C8: nop

L_808002CC:
    // 0x808002CC: jal         0x80101DDC
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_21;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808002D4: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x808002D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E4;
    }
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: jal         0x80102424
    // 0x808002E0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x808002E0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_22:
L_808002E4:
    // 0x808002E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1208, 0X728) << 16);
    // 0x808002E8: lwc1        $f18, 0x728($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1208, 0X728));
    // 0x808002EC: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002F8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808002FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800300: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800304: jal         0x80085778
    // 0x80800308: nop

    _chbadshad_entrypoint_2(rdram, ctx);
        goto after_23;
    // 0x80800308: nop

    after_23:
    // 0x8080030C: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800310: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x80800314: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80800318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080031C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800320: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800324: jr          $ra
    // 0x80800328: nop

    return;
    // 0x80800328: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AC8: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AC8);
    return;
    // 0x80089ACC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chboilerboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(932, 0X2C54) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x2C54
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2C54));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x2C54
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2C54));
;}
RECOMP_FUNC void _chvolcanobits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086418: syscall     322
    recomp_syscall_handler(rdram, ctx, 0x80086418);
    return;
    // 0x8008641C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800144_chminegrilldoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080014C: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800150: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800154: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800158: bnel        $t7, $at, L_8080016C
    if (ctx->r15 != ctx->r1) {
        // 0x8080015C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080016C;
    }
    goto skip_0;
    // 0x8080015C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800160: jal         0x80086240
    // 0x80800164: nop

    _chdoor_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800164: nop

    after_0:
    // 0x80800168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080016C:
    // 0x8080016C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800170: jr          $ra
    // 0x80800174: nop

    return;
    // 0x80800174: nop

;}
RECOMP_FUNC void func_80012EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012EA0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80012EA4: addiu       $v0, $v0, -0x35C0
    ctx->r2 = ADD32(ctx->r2, -0X35C0);
    // 0x80012EA8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80012EAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012EB4: bne         $t6, $zero, L_80012ECC
    if (ctx->r14 != 0) {
        // 0x80012EB8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80012ECC;
    }
    // 0x80012EB8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80012EBC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80012EC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80012EC4: jal         0x8002E510
    // 0x80012EC8: addiu       $a0, $a0, 0x59F8
    ctx->r4 = ADD32(ctx->r4, 0X59F8);
    osStartThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80012EC8: addiu       $a0, $a0, 0x59F8
    ctx->r4 = ADD32(ctx->r4, 0X59F8);
    after_0:
L_80012ECC:
    // 0x80012ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012ED4: jr          $ra
    // 0x80012ED8: nop

    return;
    // 0x80012ED8: nop

;}
RECOMP_FUNC void func_80801668_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801668: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080166C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801670: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801674: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80801678: jal         0x80801640
    // 0x8080167C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80801640_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080167C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80801680: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80801684: swc1        $f0, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f0.u32l;
    // 0x80801688: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080168C: swc1        $f4, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f4.u32l;
    // 0x80801690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801698: jr          $ra
    // 0x8080169C: nop

    return;
    // 0x8080169C: nop

;}
RECOMP_FUNC void func_800F8914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8914: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F8918: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F891C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800F8920: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F8924: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800F8928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F892C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800F8930: jal         0x800F5A00
    // 0x800F8934: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x800F8934: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    after_0:
    // 0x800F8938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F893C: jal         0x800F5B38
    // 0x800F8940: addiu       $a1, $s0, 0x30
    ctx->r5 = ADD32(ctx->r16, 0X30);
    func_800F5B38(rdram, ctx);
        goto after_1;
    // 0x800F8940: addiu       $a1, $s0, 0x30
    ctx->r5 = ADD32(ctx->r16, 0X30);
    after_1:
    // 0x800F8944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F8948: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800F894C: jal         0x80087928
    // 0x800F8950: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    _plcamera_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x800F8950: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x800F8954: jal         0x800F9214
    // 0x800F8958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F9214(rdram, ctx);
        goto after_3;
    // 0x800F8958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800F895C: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800F8960: jal         0x800F5410
    // 0x800F8964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F5410(rdram, ctx);
        goto after_4;
    // 0x800F8964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800F8968: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800F896C: jal         0x800F65D0
    // 0x800F8970: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F65D0(rdram, ctx);
        goto after_5;
    // 0x800F8970: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800F8974: jal         0x800EA05C
    // 0x800F8978: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_6;
    // 0x800F8978: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    after_6:
    // 0x800F897C: jal         0x800EA090
    // 0x800F8980: sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    func_800EA090(rdram, ctx);
        goto after_7;
    // 0x800F8980: sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    after_7:
    // 0x800F8984: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800F8988: sb          $v0, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r2;
    // 0x800F898C: sb          $t6, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r14;
    // 0x800F8990: jal         0x800F58F8
    // 0x800F8994: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F58F8(rdram, ctx);
        goto after_8;
    // 0x800F8994: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x800F8998: sb          $v0, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r2;
    // 0x800F899C: jal         0x800F5924
    // 0x800F89A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F5924(rdram, ctx);
        goto after_9;
    // 0x800F89A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x800F89A4: sb          $v0, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r2;
    // 0x800F89A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F89AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F89B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F89B4: jr          $ra
    // 0x800F89B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F89B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F5EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5EF8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5F00: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5F08: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5F0C: jal         0x800A4C88
    // 0x800F5F10: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A4C88(rdram, ctx);
        goto after_0;
    // 0x800F5F10: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5F1C: jr          $ra
    // 0x800F5F20: nop

    return;
    // 0x800F5F20: nop

;}
RECOMP_FUNC void func_8080499C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080499C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808049A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808049A4: beq         $a0, $at, L_808049C0
    if (ctx->r4 == ctx->r1) {
        // 0x808049A8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808049C0;
    }
    // 0x808049A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808049AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808049B0: beq         $a0, $at, L_808049D0
    if (ctx->r4 == ctx->r1) {
        // 0x808049B4: nop
    
            goto L_808049D0;
    }
    // 0x808049B4: nop

    // 0x808049B8: b           L_808049DC
    // 0x808049BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808049DC;
    // 0x808049BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808049C0:
    // 0x808049C0: jal         0x800886E0
    // 0x808049C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _glglobalsettings_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808049C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808049C8: b           L_808049DC
    // 0x808049CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808049DC;
    // 0x808049CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808049D0:
    // 0x808049D0: jal         0x80088700
    // 0x808049D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _glglobalsettings_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808049D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x808049D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808049DC:
    // 0x808049DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808049E0: jr          $ra
    // 0x808049E4: nop

    return;
    // 0x808049E4: nop

;}
RECOMP_FUNC void chfactorydrums_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C98: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2252, 0X1208) << 16);
    // 0x80800C9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CA0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800CA4: addiu       $t6, $t6, 0x1208
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2252, 0X1208));
    // 0x80800CA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800CB4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800CB8: jal         0x800BBCB8
    // 0x80800CBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800CBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800CC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CC8: jr          $ra
    // 0x80800CCC: nop

    return;
    // 0x80800CCC: nop

;}
RECOMP_FUNC void func_80800990_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800998: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x8080099C: jal         0x800DA980
    // 0x808009A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_0;
    // 0x808009A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808009A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009AC: jr          $ra
    // 0x808009B0: nop

    return;
    // 0x808009B0: nop

    // 0x808009B4: nop

    // 0x808009B8: nop

    // 0x808009BC: nop

;}
RECOMP_FUNC void func_80801650_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801650: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801658: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080165C: jal         0x80100094
    // 0x80801660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801664: jal         0x800DC0C0
    // 0x80801668: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80801668: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080166C: jal         0x800EA05C
    // 0x80801670: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80801670: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80801674: addiu       $at, $zero, 0x12D
    ctx->r1 = ADD32(0, 0X12D);
    // 0x80801678: bne         $v0, $at, L_80801698
    if (ctx->r2 != ctx->r1) {
        // 0x8080167C: lwc1        $f2, 0x18($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80801698;
    }
    // 0x8080167C: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80801680: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801684: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801688: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x8080168C: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80801690: beql        $t8, $at, L_8080174C
    if (ctx->r24 == ctx->r1) {
        // 0x80801694: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080174C;
    }
    goto skip_0;
    // 0x80801694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80801698:
    // 0x80801698: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8080169C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1840, 0X4CC8) << 16);
    // 0x808016A0: addiu       $t1, $t1, 0x4CC8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1840, 0X4CC8));
    // 0x808016A4: lbu         $v0, 0x39($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X39);
    // 0x808016A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808016AC: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x808016B0: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x808016B4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808016B8: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x808016BC: nop

    // 0x808016C0: bc1fl       L_80801704
    if (!c1cs) {
        // 0x808016C4: lwc1        $f6, 0x4($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
            goto L_80801704;
    }
    goto skip_1;
    // 0x808016C4: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x808016C8: beq         $v0, $at, L_80801700
    if (ctx->r2 == ctx->r1) {
        // 0x808016CC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80801700;
    }
    // 0x808016CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808016D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808016D4: jal         0x800DC298
    // 0x808016D8: nop

    func_800DC298(rdram, ctx);
        goto after_3;
    // 0x808016D8: nop

    after_3:
    // 0x808016DC: bne         $v0, $zero, L_808016F0
    if (ctx->r2 != 0) {
        // 0x808016E0: lw          $t2, 0x1C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X1C);
            goto L_808016F0;
    }
    // 0x808016E0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x808016E4: lbu         $t3, 0x39($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X39);
    // 0x808016E8: bne         $t3, $zero, L_808016F8
    if (ctx->r11 != 0) {
        // 0x808016EC: nop
    
            goto L_808016F8;
    }
    // 0x808016EC: nop

L_808016F0:
    // 0x808016F0: b           L_80801740
    // 0x808016F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80801740;
    // 0x808016F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808016F8:
    // 0x808016F8: b           L_80801740
    // 0x808016FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_80801740;
    // 0x808016FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80801700:
    // 0x80801700: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
L_80801704:
    // 0x80801704: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801708: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080170C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80801710: nop

    // 0x80801714: bc1f        L_80801740
    if (!c1cs) {
        // 0x80801718: nop
    
            goto L_80801740;
    }
    // 0x80801718: nop

    // 0x8080171C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801720: jal         0x800DC298
    // 0x80801724: nop

    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80801724: nop

    after_4:
    // 0x80801728: beq         $v0, $zero, L_80801738
    if (ctx->r2 == 0) {
        // 0x8080172C: nop
    
            goto L_80801738;
    }
    // 0x8080172C: nop

    // 0x80801730: b           L_80801740
    // 0x80801734: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80801740;
    // 0x80801734: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80801738:
    // 0x80801738: b           L_80801740
    // 0x8080173C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80801740;
    // 0x8080173C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80801740:
    // 0x80801740: jal         0x80108B04
    // 0x80801744: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x80801744: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80801748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080174C:
    // 0x8080174C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801750: jr          $ra
    // 0x80801754: nop

    return;
    // 0x80801754: nop

;}
RECOMP_FUNC void func_800C00E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C00E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C00E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C00E8: jal         0x800C0638
    // 0x800C00EC: nop

    func_800C0638(rdram, ctx);
        goto after_0;
    // 0x800C00EC: nop

    after_0:
    // 0x800C00F0: beq         $v0, $zero, L_800C0100
    if (ctx->r2 == 0) {
        // 0x800C00F4: nop
    
            goto L_800C0100;
    }
    // 0x800C00F4: nop

    // 0x800C00F8: jal         0x800FECB8
    // 0x800C00FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FECB8(rdram, ctx);
        goto after_1;
    // 0x800C00FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
L_800C0100:
    // 0x800C0100: jal         0x800C0658
    // 0x800C0104: nop

    func_800C0658(rdram, ctx);
        goto after_2;
    // 0x800C0104: nop

    after_2:
    // 0x800C0108: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C010C: jal         0x80087E60
    // 0x800C0110: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    _gcdialogexec_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x800C0110: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    after_3:
    // 0x800C0114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0118: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C011C: addiu       $v0, $v0, -0x7750
    ctx->r2 = ADD32(ctx->r2, -0X7750);
    // 0x800C0120: sb          $zero, 0x15C($v0)
    MEM_B(0X15C, ctx->r2) = 0;
    // 0x800C0124: sb          $zero, 0x180($v0)
    MEM_B(0X180, ctx->r2) = 0;
    // 0x800C0128: jr          $ra
    // 0x800C012C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C012C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800484_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800484: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800488: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8080048C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800490: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800494: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800498: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8080049C: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    // 0x808004A0: jal         0x80100094
    // 0x808004A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004A8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x808004AC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x808004B0: slti        $at, $a2, 0x31
    ctx->r1 = SIGNED(ctx->r6) < 0X31 ? 1 : 0;
    // 0x808004B4: bne         $at, $zero, L_808004F0
    if (ctx->r1 != 0) {
        // 0x808004B8: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_808004F0;
    }
    // 0x808004B8: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808004BC: beq         $a2, $at, L_80800680
    if (ctx->r6 == ctx->r1) {
        // 0x808004C0: addiu       $v1, $sp, 0x60
        ctx->r3 = ADD32(ctx->r29, 0X60);
            goto L_80800680;
    }
    // 0x808004C0: addiu       $v1, $sp, 0x60
    ctx->r3 = ADD32(ctx->r29, 0X60);
    // 0x808004C4: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x808004C8: beq         $a2, $at, L_808009C4
    if (ctx->r6 == ctx->r1) {
        // 0x808004CC: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_808009C4;
    }
    // 0x808004CC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808004D0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808004D4: beq         $a2, $at, L_80800534
    if (ctx->r6 == ctx->r1) {
        // 0x808004D8: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_80800534;
    }
    // 0x808004D8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x808004DC: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x808004E0: beq         $a2, $at, L_808009F0
    if (ctx->r6 == ctx->r1) {
        // 0x808004E4: nop
    
            goto L_808009F0;
    }
    // 0x808004E4: nop

    // 0x808004E8: b           L_80800A54
    // 0x808004EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A54;
    // 0x808004EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004F0:
    // 0x808004F0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808004F4: beq         $a2, $at, L_80800974
    if (ctx->r6 == ctx->r1) {
        // 0x808004F8: lw          $t9, 0x60($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X60);
            goto L_80800974;
    }
    // 0x808004F8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x808004FC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800500: beq         $a2, $at, L_80800944
    if (ctx->r6 == ctx->r1) {
        // 0x80800504: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_80800944;
    }
    // 0x80800504: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80800508: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8080050C: beq         $a2, $at, L_80800858
    if (ctx->r6 == ctx->r1) {
        // 0x80800510: addiu       $v1, $sp, 0x60
        ctx->r3 = ADD32(ctx->r29, 0X60);
            goto L_80800858;
    }
    // 0x80800510: addiu       $v1, $sp, 0x60
    ctx->r3 = ADD32(ctx->r29, 0X60);
    // 0x80800514: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80800518: beq         $a2, $at, L_808008DC
    if (ctx->r6 == ctx->r1) {
        // 0x8080051C: addiu       $v1, $sp, 0x60
        ctx->r3 = ADD32(ctx->r29, 0X60);
            goto L_808008DC;
    }
    // 0x8080051C: addiu       $v1, $sp, 0x60
    ctx->r3 = ADD32(ctx->r29, 0X60);
    // 0x80800520: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80800524: beq         $a2, $at, L_80800870
    if (ctx->r6 == ctx->r1) {
        // 0x80800528: addiu       $v1, $sp, 0x60
        ctx->r3 = ADD32(ctx->r29, 0X60);
            goto L_80800870;
    }
    // 0x80800528: addiu       $v1, $sp, 0x60
    ctx->r3 = ADD32(ctx->r29, 0X60);
    // 0x8080052C: b           L_80800A54
    // 0x80800530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A54;
    // 0x80800530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800534:
    // 0x80800534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800538: jal         0x800D0A9C
    // 0x8080053C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x8080053C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    after_1:
    // 0x80800540: beq         $v0, $zero, L_80800574
    if (ctx->r2 == 0) {
        // 0x80800544: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_80800574;
    }
    // 0x80800544: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80800548: jal         0x800D0B68
    // 0x8080054C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x8080054C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800550: bne         $v0, $zero, L_80800574
    if (ctx->r2 != 0) {
        // 0x80800554: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80800574;
    }
    // 0x80800554: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800558: jal         0x80101FDC
    // 0x8080055C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x8080055C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x80800560: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800564: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800568: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8080056C: b           L_80800A50
    // 0x80800570: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
        goto L_80800A50;
    // 0x80800570: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
L_80800574:
    // 0x80800574: jal         0x80090708
    // 0x80800578: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_4;
    // 0x80800578: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8080057C: jal         0x800DA544
    // 0x80800580: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800580: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800584: jal         0x800D395C
    // 0x80800588: nop

    func_800D395C(rdram, ctx);
        goto after_6;
    // 0x80800588: nop

    after_6:
    // 0x8080058C: beq         $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x80800590: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_808005D4;
    }
    // 0x80800590: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800594: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800598: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8080059C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808005A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808005A4: jal         0x8008A2C8
    // 0x808005A8: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x808005A8: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    after_7:
    // 0x808005AC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x808005B0: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x808005B4: addiu       $a1, $zero, 0x1049
    ctx->r5 = ADD32(0, 0X1049);
    // 0x808005B8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x808005BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808005C0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808005C4: jal         0x8008A208
    // 0x808005C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x808005C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x808005CC: b           L_80800A54
    // 0x808005D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A54;
    // 0x808005D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005D4:
    // 0x808005D4: jal         0x800DA298
    // 0x808005D8: addiu       $a0, $zero, 0x6E5
    ctx->r4 = ADD32(0, 0X6E5);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808005D8: addiu       $a0, $zero, 0x6E5
    ctx->r4 = ADD32(0, 0X6E5);
    after_9:
    // 0x808005DC: beq         $v0, $zero, L_80800628
    if (ctx->r2 == 0) {
        // 0x808005E0: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80800628;
    }
    // 0x808005E0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808005E4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x808005E8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808005EC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808005F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808005F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808005F8: jal         0x8008A2C8
    // 0x808005FC: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_10;
    // 0x808005FC: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    after_10:
    // 0x80800600: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80800604: addiu       $t1, $zero, 0x22
    ctx->r9 = ADD32(0, 0X22);
    // 0x80800608: addiu       $a1, $zero, 0x102D
    ctx->r5 = ADD32(0, 0X102D);
    // 0x8080060C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800610: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800614: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800618: jal         0x8008A208
    // 0x8080061C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x8080061C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80800620: b           L_80800A54
    // 0x80800624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A54;
    // 0x80800624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800628:
    // 0x80800628: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8080062C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800630: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800634: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800638: jal         0x8008A2D0
    // 0x8080063C: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x8080063C: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    after_12:
    // 0x80800640: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80800644: jal         0x800D0A9C
    // 0x80800648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_13;
    // 0x80800648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x8080064C: bne         $v0, $zero, L_8080065C
    if (ctx->r2 != 0) {
        // 0x80800650: lw          $t2, 0x58($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X58);
            goto L_8080065C;
    }
    // 0x80800650: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80800654: b           L_80800660
    // 0x80800658: addiu       $a1, $zero, 0x102C
    ctx->r5 = ADD32(0, 0X102C);
        goto L_80800660;
    // 0x80800658: addiu       $a1, $zero, 0x102C
    ctx->r5 = ADD32(0, 0X102C);
L_8080065C:
    // 0x8080065C: addiu       $a1, $zero, 0x102D
    ctx->r5 = ADD32(0, 0X102D);
L_80800660:
    // 0x80800660: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80800664: addiu       $t3, $zero, 0x22
    ctx->r11 = ADD32(0, 0X22);
    // 0x80800668: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080066C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800670: jal         0x8008A208
    // 0x80800674: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80800674: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80800678: b           L_80800A54
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A54;
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800680:
    // 0x80800680: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x80800684: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x80800688: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8080068C: bgez        $v0, L_808006B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80800690: sw          $t4, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r12;
            goto L_808006B0;
    }
    // 0x80800690: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x80800694: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80800698: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8080069C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x808006A0: jal         0x800EE7F8
    // 0x808006A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x808006A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_15:
    // 0x808006A8: b           L_808006F4
    // 0x808006AC: addiu       $a0, $zero, 0x4AE
    ctx->r4 = ADD32(0, 0X4AE);
        goto L_808006F4;
    // 0x808006AC: addiu       $a0, $zero, 0x4AE
    ctx->r4 = ADD32(0, 0X4AE);
L_808006B0:
    // 0x808006B0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x808006B4: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x808006B8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x808006BC: addu        $a1, $t0, $t5
    ctx->r5 = ADD32(ctx->r8, ctx->r13);
    // 0x808006C0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x808006C4: jal         0x800EE7F8
    // 0x808006C8: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x808006C8: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    after_16:
    // 0x808006CC: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x808006D0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x808006D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808006D8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x808006DC: sb          $t6, 0x2D0($t9)
    MEM_B(0X2D0, ctx->r25) = ctx->r14;
    // 0x808006E0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x808006E4: lw          $t2, 0x2C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2C);
    // 0x808006E8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x808006EC: sw          $t3, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r11;
    // 0x808006F0: addiu       $a0, $zero, 0x4AE
    ctx->r4 = ADD32(0, 0X4AE);
L_808006F4:
    // 0x808006F4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808006F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808006FC: jal         0x80108528
    // 0x80800700: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_80108528(rdram, ctx);
        goto after_17;
    // 0x80800700: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_17:
    // 0x80800704: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80800708: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080070C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800710: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80800714: sw          $t5, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r13;
    // 0x80800718: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8080071C: bltzl       $t7, L_80800744
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800720: lw          $t6, 0x48($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X48);
            goto L_80800744;
    }
    goto skip_0;
    // 0x80800720: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x80800724: jal         0x800E3980
    // 0x80800728: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    func_800E3980(rdram, ctx);
        goto after_18;
    // 0x80800728: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_18:
    // 0x8080072C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800730: jal         0x80102D78
    // 0x80800734: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80102D78(rdram, ctx);
        goto after_19;
    // 0x80800734: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_19:
    // 0x80800738: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8080073C: swc1        $f0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->f0.u32l;
    // 0x80800740: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_80800744:
    // 0x80800744: lhu         $t2, 0x6E($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X6E);
    // 0x80800748: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(792, 0X1400) << 16);
    // 0x8080074C: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x80800750: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80800754: or          $t1, $t9, $t3
    ctx->r9 = ctx->r25 | ctx->r11;
    // 0x80800758: sh          $t1, 0x6E($a3)
    MEM_H(0X6E, ctx->r7) = ctx->r9;
    // 0x8080075C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80800760: addiu       $t8, $t8, 0x1400
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(792, 0X1400));
    // 0x80800764: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800768: sw          $t4, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r12;
    // 0x8080076C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80800770: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x80800774: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800778: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8080077C: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80800780: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800784: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80800788: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x8080078C: jal         0x80103140
    // 0x80800790: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80103140(rdram, ctx);
        goto after_20;
    // 0x80800790: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_20:
    // 0x80800794: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800798: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x8080079C: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x808007A0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x808007A4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x808007A8: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808007AC: jal         0x800DC178
    // 0x808007B0: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    func_800DC178(rdram, ctx);
        goto after_21;
    // 0x808007B0: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    after_21:
    // 0x808007B4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808007B8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x808007BC: swc1        $f0, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f0.u32l;
    // 0x808007C0: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x808007C4: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x808007C8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x808007CC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x808007D0: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808007D4: jal         0x800DC178
    // 0x808007D8: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    func_800DC178(rdram, ctx);
        goto after_22;
    // 0x808007D8: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_22:
    // 0x808007DC: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x808007E0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808007E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808007E8: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x808007EC: swc1        $f0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->f0.u32l;
    // 0x808007F0: swc1        $f0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f0.u32l;
    // 0x808007F4: swc1        $f18, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f18.u32l;
    // 0x808007F8: swc1        $f4, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f4.u32l;
    // 0x808007FC: lh          $t1, 0xA($v1)
    ctx->r9 = MEM_H(ctx->r3, 0XA);
    // 0x80800800: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80800804: nop

    // 0x80800808: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080080C: swc1        $f8, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f8.u32l;
    // 0x80800810: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80800814: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80800818: bgezl       $t4, L_8080082C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080081C: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_8080082C;
    }
    goto skip_1;
    // 0x8080081C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x80800820: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80800824: sw          $t5, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r13;
    // 0x80800828: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_8080082C:
    // 0x8080082C: bgez        $t8, L_80800848
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800830: nop
    
            goto L_80800848;
    }
    // 0x80800830: nop

    // 0x80800834: lw          $t6, 0x6C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X6C);
    // 0x80800838: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080083C: andi        $t2, $t6, 0x1FF
    ctx->r10 = ctx->r14 & 0X1FF;
    // 0x80800840: bne         $t2, $at, L_80800850
    if (ctx->r10 != ctx->r1) {
        // 0x80800844: nop
    
            goto L_80800850;
    }
    // 0x80800844: nop

L_80800848:
    // 0x80800848: jal         0x80089CA0
    // 0x8080084C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_23;
    // 0x8080084C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_23:
L_80800850:
    // 0x80800850: b           L_80800A54
    // 0x80800854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A54;
    // 0x80800854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800858:
    // 0x80800858: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080085C: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x80800860: jal         0x80800BA8
    // 0x80800864: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    func_80800BA8_chminisubgame(rdram, ctx);
        goto after_24;
    // 0x80800864: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    after_24:
    // 0x80800868: b           L_80800A54
    // 0x8080086C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A54;
    // 0x8080086C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800870:
    // 0x80800870: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x80800874: addiu       $at, $zero, 0x102C
    ctx->r1 = ADD32(0, 0X102C);
    // 0x80800878: beq         $a1, $at, L_808008AC
    if (ctx->r5 == ctx->r1) {
        // 0x8080087C: addiu       $at, $zero, 0x1032
        ctx->r1 = ADD32(0, 0X1032);
            goto L_808008AC;
    }
    // 0x8080087C: addiu       $at, $zero, 0x1032
    ctx->r1 = ADD32(0, 0X1032);
    // 0x80800880: beq         $a1, $at, L_808008A4
    if (ctx->r5 == ctx->r1) {
        // 0x80800884: lw          $t9, 0x58($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X58);
            goto L_808008A4;
    }
    // 0x80800884: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80800888: addiu       $at, $zero, 0x1033
    ctx->r1 = ADD32(0, 0X1033);
    // 0x8080088C: beq         $a1, $at, L_808008B4
    if (ctx->r5 == ctx->r1) {
        // 0x80800890: addiu       $at, $zero, 0x104C
        ctx->r1 = ADD32(0, 0X104C);
            goto L_808008B4;
    }
    // 0x80800890: addiu       $at, $zero, 0x104C
    ctx->r1 = ADD32(0, 0X104C);
    // 0x80800894: beql        $a1, $at, L_808008B8
    if (ctx->r5 == ctx->r1) {
        // 0x80800898: lh          $t3, 0x2($v1)
        ctx->r11 = MEM_H(ctx->r3, 0X2);
            goto L_808008B8;
    }
    goto skip_2;
    // 0x80800898: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    skip_2:
    // 0x8080089C: b           L_808008CC
    // 0x808008A0: nop

        goto L_808008CC;
    // 0x808008A0: nop

L_808008A4:
    // 0x808008A4: b           L_80800A54
    // 0x808008A8: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
        goto L_80800A54;
    // 0x808008A8: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
L_808008AC:
    // 0x808008AC: b           L_80800A54
    // 0x808008B0: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
        goto L_80800A54;
    // 0x808008B0: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_808008B4:
    // 0x808008B4: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
L_808008B8:
    // 0x808008B8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x808008BC: bne         $t3, $zero, L_808008CC
    if (ctx->r11 != 0) {
        // 0x808008C0: nop
    
            goto L_808008CC;
    }
    // 0x808008C0: nop

    // 0x808008C4: b           L_80800A54
    // 0x808008C8: lw          $v0, 0x28($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X28);
        goto L_80800A54;
    // 0x808008C8: lw          $v0, 0x28($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X28);
L_808008CC:
    // 0x808008CC: jal         0x800D211C
    // 0x808008D0: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_800D211C(rdram, ctx);
        goto after_25;
    // 0x808008D0: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_25:
    // 0x808008D4: b           L_80800A58
    // 0x808008D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A58;
    // 0x808008D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008DC:
    // 0x808008DC: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x808008E0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808008E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808008E8: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x808008EC: sh          $t4, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r12;
    // 0x808008F0: bne         $v0, $at, L_80800910
    if (ctx->r2 != ctx->r1) {
        // 0x808008F4: sh          $t5, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r13;
            goto L_80800910;
    }
    // 0x808008F4: sh          $t5, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r13;
    // 0x808008F8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808008FC: addiu       $a1, $t0, 0x30C
    ctx->r5 = ADD32(ctx->r8, 0X30C);
    // 0x80800900: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80800904: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    // 0x80800908: jal         0x8008A2D0
    // 0x8080090C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_26;
    // 0x8080090C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_26:
L_80800910:
    // 0x80800910: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800914: jal         0x80108B04
    // 0x80800918: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80108B04(rdram, ctx);
        goto after_27;
    // 0x80800918: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_27:
    // 0x8080091C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80800920: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80800924: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    // 0x80800928: beql        $a0, $zero, L_80800A54
    if (ctx->r4 == 0) {
        // 0x8080092C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800A54;
    }
    goto skip_3;
    // 0x8080092C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800930: jal         0x8010114C
    // 0x80800934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_28;
    // 0x80800934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
    // 0x80800938: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8080093C: b           L_80800A50
    // 0x80800940: sw          $zero, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = 0;
        goto L_80800A50;
    // 0x80800940: sw          $zero, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = 0;
L_80800944:
    // 0x80800944: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800948: bne         $t6, $at, L_8080096C
    if (ctx->r14 != ctx->r1) {
        // 0x8080094C: lw          $t2, 0x58($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X58);
            goto L_8080096C;
    }
    // 0x8080094C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80800950: lw          $a0, 0x3C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X3C);
    // 0x80800954: beq         $a0, $zero, L_8080096C
    if (ctx->r4 == 0) {
        // 0x80800958: nop
    
            goto L_8080096C;
    }
    // 0x80800958: nop

    // 0x8080095C: jal         0x80106790
    // 0x80800960: nop

    func_80106790(rdram, ctx);
        goto after_29;
    // 0x80800960: nop

    after_29:
    // 0x80800964: jal         0x80085738
    // 0x80800968: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    _capod_entrypoint_19(rdram, ctx);
        goto after_30;
    // 0x80800968: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    after_30:
L_8080096C:
    // 0x8080096C: b           L_80800A54
    // 0x80800970: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800A54;
    // 0x80800970: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800974:
    // 0x80800974: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800978: bne         $t9, $at, L_808009BC
    if (ctx->r25 != ctx->r1) {
        // 0x8080097C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808009BC;
    }
    // 0x8080097C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800980: jal         0x80090708
    // 0x80800984: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    func_80090708(rdram, ctx);
        goto after_31;
    // 0x80800984: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    after_31:
    // 0x80800988: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8080098C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800990: jal         0x8008A2C0
    // 0x80800994: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_32;
    // 0x80800994: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    after_32:
    // 0x80800998: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080099C: jal         0x80101FDC
    // 0x808009A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_33;
    // 0x808009A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_33:
    // 0x808009A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808009A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808009AC: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x808009B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x808009B4: b           L_80800A54
    // 0x808009B8: swc1        $f10, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f10.u32l;
        goto L_80800A54;
    // 0x808009B8: swc1        $f10, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f10.u32l;
L_808009BC:
    // 0x808009BC: b           L_80800A54
    // 0x808009C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800A54;
    // 0x808009C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808009C4:
    // 0x808009C4: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x808009C8: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x808009CC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808009D0: andi        $t1, $a2, 0xFFFF
    ctx->r9 = ctx->r6 & 0XFFFF;
    // 0x808009D4: and         $t4, $a3, $at
    ctx->r12 = ctx->r7 & ctx->r1;
    // 0x808009D8: srl         $a3, $t4, 16
    ctx->r7 = S32(U32(ctx->r12) >> 16);
    // 0x808009DC: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x808009E0: jal         0x8008A2B8
    // 0x808009E4: addiu       $a1, $t0, 0x30C
    ctx->r5 = ADD32(ctx->r8, 0X30C);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_34;
    // 0x808009E4: addiu       $a1, $t0, 0x30C
    ctx->r5 = ADD32(ctx->r8, 0X30C);
    after_34:
    // 0x808009E8: b           L_80800A58
    // 0x808009EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A58;
    // 0x808009EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009F0:
    // 0x808009F0: jal         0x800D395C
    // 0x808009F4: nop

    func_800D395C(rdram, ctx);
        goto after_35;
    // 0x808009F4: nop

    after_35:
    // 0x808009F8: bne         $v0, $zero, L_80800A08
    if (ctx->r2 != 0) {
        // 0x808009FC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800A08;
    }
    // 0x808009FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800A00: b           L_80800A54
    // 0x80800A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A54;
    // 0x80800A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A08:
    // 0x80800A08: addiu       $a1, $zero, 0x5AA
    ctx->r5 = ADD32(0, 0X5AA);
    // 0x80800A0C: jal         0x800BF99C
    // 0x80800A10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800BF99C(rdram, ctx);
        goto after_36;
    // 0x80800A10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_36:
    // 0x80800A14: addiu       $a0, $zero, 0x4AE
    ctx->r4 = ADD32(0, 0X4AE);
    // 0x80800A18: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80800A1C: jal         0x80101180
    // 0x80800A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_37;
    // 0x80800A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_37:
    // 0x80800A24: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80800A28: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x80800A2C: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800A30: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800A34: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800A38: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800A3C: jal         0x8008A208
    // 0x80800A40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_38;
    // 0x80800A40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_38:
    // 0x80800A44: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800A48: jal         0x80101FDC
    // 0x80800A4C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_39;
    // 0x80800A4C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_39:
L_80800A50:
    // 0x80800A50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A54:
    // 0x80800A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A58:
    // 0x80800A58: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800A5C: jr          $ra
    // 0x80800A60: nop

    return;
    // 0x80800A60: nop

;}
RECOMP_FUNC void _ncbadeflect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089440: syscall     779
    recomp_syscall_handler(rdram, ctx, 0x80089440);
    return;
    // 0x80089444: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808012F8_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808012FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801300: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801304: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801308: jal         0x8008CABC
    // 0x8080130C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080130C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80801310: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80801314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801318: jal         0x8009D3A8
    // 0x8080131C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x8080131C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801320: jal         0x80800164
    // 0x80801324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bstnt(rdram, ctx);
        goto after_2;
    // 0x80801324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080132C: jal         0x8009BB24
    // 0x80801330: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_3;
    // 0x80801330: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80801334: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80801338: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080133C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801340: beq         $v0, $zero, L_80801360
    if (ctx->r2 == 0) {
        // 0x80801344: nop
    
            goto L_80801360;
    }
    // 0x80801344: nop

    // 0x80801348: beq         $v0, $at, L_80801388
    if (ctx->r2 == ctx->r1) {
        // 0x8080134C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801388;
    }
    // 0x8080134C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801350: beq         $v0, $at, L_808013C4
    if (ctx->r2 == ctx->r1) {
        // 0x80801354: nop
    
            goto L_808013C4;
    }
    // 0x80801354: nop

    // 0x80801358: b           L_808013C4
    // 0x8080135C: nop

        goto L_808013C4;
    // 0x8080135C: nop

L_80801360:
    // 0x80801360: jal         0x8008DF8C
    // 0x80801364: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_4;
    // 0x80801364: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_4:
    // 0x80801368: beq         $v0, $zero, L_808013C4
    if (ctx->r2 == 0) {
        // 0x8080136C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013C4;
    }
    // 0x8080136C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801370: lui         $a1, 0x3F27
    ctx->r5 = S32(0X3F27 << 16);
    // 0x80801374: jal         0x8008CED4
    // 0x80801378: ori         $a1, $a1, 0x5F70
    ctx->r5 = ctx->r5 | 0X5F70;
    baanim_setEnd(rdram, ctx);
        goto after_5;
    // 0x80801378: ori         $a1, $a1, 0x5F70
    ctx->r5 = ctx->r5 | 0X5F70;
    after_5:
    // 0x8080137C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801380: b           L_808013C4
    // 0x80801384: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_808013C4;
    // 0x80801384: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80801388:
    // 0x80801388: jal         0x8008E078
    // 0x8080138C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_6;
    // 0x8080138C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801390: beq         $v0, $zero, L_808013C4
    if (ctx->r2 == 0) {
        // 0x80801394: nop
    
            goto L_808013C4;
    }
    // 0x80801394: nop

    // 0x80801398: jal         0x800A2EAC
    // 0x8080139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2EAC(rdram, ctx);
        goto after_7;
    // 0x8080139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808013A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013A4: jal         0x8009B9B0
    // 0x808013A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x808013A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x808013AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808013B4: jal         0x8008CF1C
    // 0x808013B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_9;
    // 0x808013B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x808013BC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808013C0: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_808013C4:
    // 0x808013C4: jal         0x8008E35C
    // 0x808013C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_10;
    // 0x808013C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808013CC: beq         $v0, $zero, L_808013D8
    if (ctx->r2 == 0) {
        // 0x808013D0: addiu       $t8, $zero, 0x111
        ctx->r24 = ADD32(0, 0X111);
            goto L_808013D8;
    }
    // 0x808013D0: addiu       $t8, $zero, 0x111
    ctx->r24 = ADD32(0, 0X111);
    // 0x808013D4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_808013D8:
    // 0x808013D8: jal         0x8008E078
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_11;
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808013E0: beq         $v0, $zero, L_8080143C
    if (ctx->r2 == 0) {
        // 0x808013E4: nop
    
            goto L_8080143C;
    }
    // 0x808013E4: nop

    // 0x808013E8: jal         0x8009EF10
    // 0x808013EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_12;
    // 0x808013EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808013F0: bgtzl       $v0, L_80801418
    if (SIGNED(ctx->r2) > 0) {
        // 0x808013F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801418;
    }
    goto skip_0;
    // 0x808013F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808013F8: lw          $t9, 0x15C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X15C);
    // 0x808013FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801400: bne         $t9, $at, L_8080143C
    if (ctx->r25 != ctx->r1) {
        // 0x80801404: nop
    
            goto L_8080143C;
    }
    // 0x80801404: nop

    // 0x80801408: jal         0x8008B324
    // 0x8080140C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_13;
    // 0x8080140C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_13:
    // 0x80801410: beq         $v0, $zero, L_8080143C
    if (ctx->r2 == 0) {
        // 0x80801414: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080143C;
    }
    // 0x80801414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801418:
    // 0x80801418: jal         0x80095738
    // 0x8080141C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    baflag_isTrue(rdram, ctx);
        goto after_14;
    // 0x8080141C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_14:
    // 0x80801420: beq         $v0, $zero, L_80801438
    if (ctx->r2 == 0) {
        // 0x80801424: addiu       $t0, $zero, 0x10C
        ctx->r8 = ADD32(0, 0X10C);
            goto L_80801438;
    }
    // 0x80801424: addiu       $t0, $zero, 0x10C
    ctx->r8 = ADD32(0, 0X10C);
    // 0x80801428: jal         0x800848C8
    // 0x8080142C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_28(rdram, ctx);
        goto after_15;
    // 0x8080142C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801430: b           L_8080143C
    // 0x80801434: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_8080143C;
    // 0x80801434: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80801438:
    // 0x80801438: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_8080143C:
    // 0x8080143C: jal         0x80800F94
    // 0x80801440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstnt_entrypoint_4(rdram, ctx);
        goto after_16;
    // 0x80801440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801448: jal         0x8009E5C8
    // 0x8080144C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_17;
    // 0x8080144C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_17:
    // 0x80801450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801454: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080145C: jr          $ra
    // 0x80801460: nop

    return;
    // 0x80801460: nop

;}
RECOMP_FUNC void func_800F8E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8E10: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800F8E14: jal         0x800B2D70
    // 0x800F8E18: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    vector_new(rdram, ctx);
        goto after_0;
    // 0x800F8E18: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x800F8E1C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800F8E20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8E24: sw          $v0, 0x54F0($at)
    MEM_W(0X54F0, ctx->r1) = ctx->r2;
    // 0x800F8E28: addiu       $v1, $v1, 0x54F8
    ctx->r3 = ADD32(ctx->r3, 0X54F8);
    // 0x800F8E2C: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x800F8E30: sb          $zero, 0x4($v1)
    MEM_B(0X4, ctx->r3) = 0;
    // 0x800F8E34: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x800F8E38: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800F8E3C: jal         0x800F911C
    // 0x800F8E40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F911C(rdram, ctx);
        goto after_1;
    // 0x800F8E40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800F8E44: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8E48: jal         0x800EFD24
    // 0x800F8E4C: addiu       $a0, $a0, 0x5500
    ctx->r4 = ADD32(ctx->r4, 0X5500);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x800F8E4C: addiu       $a0, $a0, 0x5500
    ctx->r4 = ADD32(ctx->r4, 0X5500);
    after_2:
    // 0x800F8E50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8E54: jal         0x800EFD24
    // 0x800F8E58: addiu       $a0, $a0, 0x5510
    ctx->r4 = ADD32(ctx->r4, 0X5510);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x800F8E58: addiu       $a0, $a0, 0x5510
    ctx->r4 = ADD32(ctx->r4, 0X5510);
    after_3:
    // 0x800F8E5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8E60: jal         0x800F9A44
    // 0x800F8E64: sw          $zero, 0x551C($at)
    MEM_W(0X551C, ctx->r1) = 0;
    func_800F9A44(rdram, ctx);
        goto after_4;
    // 0x800F8E64: sw          $zero, 0x551C($at)
    MEM_W(0X551C, ctx->r1) = 0;
    after_4:
    // 0x800F8E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8E6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8E70: jr          $ra
    // 0x800F8E74: nop

    return;
    // 0x800F8E74: nop

;}
RECOMP_FUNC void babounce_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8080011C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800120: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800128: jal         0x8009BADC
    // 0x8080012C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    func_8009BADC(rdram, ctx);
        goto after_0;
    // 0x8080012C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800130: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x8009BAE8
    // 0x8080013C: swc1        $f0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f0.u32l;
    func_8009BAE8(rdram, ctx);
        goto after_1;
    // 0x8080013C: swc1        $f0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f0.u32l;
    after_1:
    // 0x80800140: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x80800144: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80800148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080014C: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x80800150: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x80800154: sw          $zero, 0x10($t8)
    MEM_W(0X10, ctx->r24) = 0;
    // 0x80800158: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x8080015C: beq         $v0, $at, L_80800178
    if (ctx->r2 == ctx->r1) {
        // 0x80800160: sb          $v0, 0xD($t9)
        MEM_B(0XD, ctx->r25) = ctx->r2;
            goto L_80800178;
    }
    // 0x80800160: sb          $v0, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r2;
    // 0x80800164: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800168: beq         $v0, $at, L_808001A4
    if (ctx->r2 == ctx->r1) {
        // 0x8080016C: nop
    
            goto L_808001A4;
    }
    // 0x8080016C: nop

    // 0x80800170: b           L_808001AC
    // 0x80800174: nop

        goto L_808001AC;
    // 0x80800174: nop

L_80800178:
    // 0x80800178: jal         0x800A32EC
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A32EC(rdram, ctx);
        goto after_2;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800180: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800184: beq         $v0, $at, L_80800194
    if (ctx->r2 == ctx->r1) {
        // 0x80800188: nop
    
            goto L_80800194;
    }
    // 0x80800188: nop

    // 0x8080018C: jal         0x8009D9D4
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_3;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800194:
    // 0x80800194: jal         0x8009514C
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_4;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080019C: b           L_808001AC
    // 0x808001A0: nop

        goto L_808001AC;
    // 0x808001A0: nop

L_808001A4:
    // 0x808001A4: jal         0x8009DA40
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009DA40(rdram, ctx);
        goto after_5;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_808001AC:
    // 0x808001AC: jal         0x80099A58
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_6;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001B4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x80084F78
    // 0x808001C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bareact_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808001C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x808001C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(467, 0X6B0) << 16);
    // 0x808001C8: lwc1        $f4, 0x6B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(467, 0X6B0));
    // 0x808001CC: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
    // 0x808001D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(467, 0X6B4) << 16);
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x808001DC: lw          $t1, 0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28);
    // 0x808001E0: lwc1        $f6, 0x6B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(467, 0X6B4));
    // 0x808001E4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808001E8: jal         0x800A32C4
    // 0x808001EC: swc1        $f6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f6.u32l;
    func_800A32C4(rdram, ctx);
        goto after_8;
    // 0x808001EC: swc1        $f6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f6.u32l;
    after_8:
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: jal         0x8009C128
    // 0x808001F8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_8009C128(rdram, ctx);
        goto after_9;
    // 0x808001F8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_9:
    // 0x808001FC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800200: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800204: jal         0x800F1E6C
    // 0x80800208: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800F1E6C(rdram, ctx);
        goto after_10;
    // 0x80800208: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_10:
    // 0x8080020C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800210: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: beq         $v1, $at, L_80800228
    if (ctx->r3 == ctx->r1) {
        // 0x8080021C: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80800228;
    }
    // 0x8080021C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80800220: bne         $v1, $at, L_80800308
    if (ctx->r3 != ctx->r1) {
        // 0x80800224: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800308;
    }
    // 0x80800224: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800228:
    // 0x80800228: jal         0x80800008
    // 0x8080022C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800008_babounce(rdram, ctx);
        goto after_11;
    // 0x8080022C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80800230: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800234: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800240: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800244: jal         0x8009FFD8
    // 0x80800248: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_12;
    // 0x80800248: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_12:
    // 0x8080024C: jal         0x800136E4
    // 0x80800250: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    func_800136E4(rdram, ctx);
        goto after_13;
    // 0x80800250: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    after_13:
    // 0x80800254: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800258: jal         0x8009C914
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_14;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800260: jal         0x80099A40
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A40(rdram, ctx);
        goto after_15;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800268: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x80099A34
    // 0x80800274: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    func_80099A34(rdram, ctx);
        goto after_16;
    // 0x80800274: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    after_16:
    // 0x80800278: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8080027C: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80800280: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: lwc1        $f8, 0x1C($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x8080028C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800290: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800294: jal         0x8009F3BC
    // 0x80800298: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8009F3BC(rdram, ctx);
        goto after_17;
    // 0x80800298: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_17:
    // 0x8080029C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x808002A0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808002A4: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x808002A8: jal         0x800EFB24
    // 0x808002AC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800EFB24(rdram, ctx);
        goto after_18;
    // 0x808002AC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_18:
    // 0x808002B0: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808002B4: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808002B8: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808002BC: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808002C0: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C8: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x808002CC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x808002D0: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x808002D4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x808002D8: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x808002DC: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x808002E0: jal         0x8009BA9C
    // 0x808002E4: swc1        $f2, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f2.u32l;
    func_8009BA9C(rdram, ctx);
        goto after_19;
    // 0x808002E4: swc1        $f2, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f2.u32l;
    after_19:
    // 0x808002E8: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808002F4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808002F8: jal         0x80085338
    // 0x808002FC: nop

    _batimer_set(rdram, ctx);
        goto after_20;
    // 0x808002FC: nop

    after_20:
    // 0x80800300: b           L_808003C8
    // 0x80800304: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
        goto L_808003C8;
    // 0x80800304: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
L_80800308:
    // 0x80800308: jal         0x80800008
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_babounce(rdram, ctx);
        goto after_21;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800310: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800314: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800318: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080031C: jal         0x800136E4
    // 0x80800320: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_22;
    // 0x80800320: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_22:
    // 0x80800324: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800328: jal         0x8009C914
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_23;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800330: jal         0x80084F90
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_4(rdram, ctx);
        goto after_24;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800338: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080033C: jal         0x8009B9B0
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_25;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x8009B9C0
    // 0x8080034C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_26;
    // 0x8080034C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_26:
    // 0x80800350: jal         0x8009BB00
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_27;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800358: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800360: jal         0x8009BA68
    // 0x80800364: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_28;
    // 0x80800364: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_28:
    // 0x80800368: jal         0x80084F88
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800370: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800374: jal         0x8009BA58
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_30;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8080037C: jal         0x80084F98
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_5(rdram, ctx);
        goto after_31;
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800384: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x80800388: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x80800394: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080039C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808003A0: jal         0x8009FFD8
    // 0x808003A4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_32;
    // 0x808003A4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_32:
    // 0x808003A8: jal         0x80084F80
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_2(rdram, ctx);
        goto after_33;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x808003B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003B4: bne         $v0, $at, L_808003C4
    if (ctx->r2 != ctx->r1) {
        // 0x808003B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C4;
    }
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003BC: jal         0x8009B800
    // 0x808003C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_34;
    // 0x808003C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_34:
L_808003C4:
    // 0x808003C4: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
L_808003C8:
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: jal         0x8009BCB4
    // 0x808003D0: lw          $a1, 0x1C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X1C);
    baphysics_set_gravity(rdram, ctx);
        goto after_35;
    // 0x808003D0: lw          $a1, 0x1C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X1C);
    after_35:
    // 0x808003D4: jal         0x8009BC90
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_36;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x808003DC: jal         0x8009C974
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_37;
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x808003E4: jal         0x8008E944
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_38;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x808003EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003F4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x808003F8: jr          $ra
    // 0x808003FC: nop

    return;
    // 0x808003FC: nop

;}
RECOMP_FUNC void func_808007CC_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007D4: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x808007D8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808007DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007E0: beql        $t6, $zero, L_808007FC
    if (ctx->r14 == 0) {
        // 0x808007E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007FC;
    }
    goto skip_0;
    // 0x808007E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808007E8: jal         0x800856B8
    // 0x808007EC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808007EC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808007F0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808007F4: sw          $zero, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = 0;
    // 0x808007F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007FC:
    // 0x808007FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800800: jr          $ra
    // 0x80800804: nop

    return;
    // 0x80800804: nop

;}
RECOMP_FUNC void chfireicestorm_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1528, 0XEA8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xEA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1528, 0XEA8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xEA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1528, 0XEA8));
;}
RECOMP_FUNC void bswalk_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800A04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A08: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800A0C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800A10: jal         0x8008CABC
    // 0x80800A14: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800A14: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800A18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A1C: jal         0x8009E710
    // 0x80800A20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x80800A20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800A24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A28: beq         $v0, $at, L_80800A44
    if (ctx->r2 == ctx->r1) {
        // 0x80800A2C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800A44;
    }
    // 0x80800A2C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800A30: beq         $v0, $at, L_80800A44
    if (ctx->r2 == ctx->r1) {
        // 0x80800A34: nop
    
            goto L_80800A44;
    }
    // 0x80800A34: nop

    // 0x80800A38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A3C: b           L_80800A58
    // 0x80800A40: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
        goto L_80800A58;
    // 0x80800A40: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_80800A44:
    // 0x80800A44: jal         0x8008AEDC
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_2;
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800A4C: jal         0x8008C0C8
    // 0x80800A50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C0C8(rdram, ctx);
        goto after_3;
    // 0x80800A50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800A54: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
L_80800A58:
    // 0x80800A58: jal         0x8008AF24
    // 0x80800A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_4;
    // 0x80800A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: jal         0x8008AED4
    // 0x80800A68: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x80800A68: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_5:
    // 0x80800A6C: lui         $a1, 0x3F28
    ctx->r5 = S32(0X3F28 << 16);
    // 0x80800A70: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x80800A74: jal         0x8008B1BC
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A7C: lui         $a1, 0x3E0F
    ctx->r5 = S32(0X3E0F << 16);
    // 0x80800A80: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x80800A84: jal         0x8008B1C8
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_7;
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A90: jal         0x8008B24C
    // 0x80800A94: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setStart(rdram, ctx);
        goto after_8;
    // 0x80800A94: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A9C: jal         0x8008B134
    // 0x80800AA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_9;
    // 0x80800AA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800AA4: jal         0x8008B064
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_10;
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800AAC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800AB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800AB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800ABC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AC0: jal         0x8009FFD8
    // 0x80800AC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_11;
    // 0x80800AC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x80800AC8: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800ACC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AD4: jal         0x8008C9BC
    // 0x80800AD8: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_12;
    // 0x80800AD8: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_12:
    // 0x80800ADC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X1500) << 16);
    // 0x80800AE0: lwc1        $f6, 0x1500($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0X1500));
    // 0x80800AE4: lui         $a3, 0x3F6B
    ctx->r7 = S32(0X3F6B << 16);
    // 0x80800AE8: ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // 0x80800AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AF0: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x80800AF4: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x80800AF8: jal         0x8008C9F0
    // 0x80800AFC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_13;
    // 0x80800AFC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x80800B00: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800B04: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800B08: jal         0x808001D8
    // 0x80800B0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808001D8_bswalk(rdram, ctx);
        goto after_14;
    // 0x80800B0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800B10: jal         0x8009F1E0
    // 0x80800B14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_15;
    // 0x80800B14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800B18: jal         0x8008E0E8
    // 0x80800B1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_16;
    // 0x80800B1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800B20: beq         $v0, $zero, L_80800B30
    if (ctx->r2 == 0) {
        // 0x80800B24: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800B30;
    }
    // 0x80800B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B28: jal         0x80084788
    // 0x80800B2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_17;
    // 0x80800B2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
L_80800B30:
    // 0x80800B30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B34: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B38: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800B3C: jr          $ra
    // 0x80800B40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800B40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chdiggerboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867C0: syscall     377
    recomp_syscall_handler(rdram, ctx, 0x800867C0);
    return;
    // 0x800867C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chhotfloorsmoke_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D68: syscall     237
    recomp_syscall_handler(rdram, ctx, 0x80085D68);
    return;
    // 0x80085D6C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80112354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80112358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011235C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80112360: jal         0x80112168
    // 0x80112364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80112168(rdram, ctx);
        goto after_0;
    // 0x80112364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80112368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8011236C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80112370: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80112374: lwc1        $f4, 0x28($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80112378: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8011237C: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x80112380: lwc1        $f6, 0x30($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X30);
    // 0x80112384: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    // 0x80112388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011238C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80112390: jr          $ra
    // 0x80112394: nop

    return;
    // 0x80112394: nop

;}
RECOMP_FUNC void _chfaircoinbox_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087280: syscall     541
    recomp_syscall_handler(rdram, ctx, 0x80087280);
    return;
    // 0x80087284: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bskazglide_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808009F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(244, 0XAE0) << 16);
    // 0x808009F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808009F8: jr          $ra
    // 0x808009FC: lw          $v0, 0xAE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAE0));
    return;
    // 0x808009FC: lw          $v0, 0xAE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAE0));
;}
