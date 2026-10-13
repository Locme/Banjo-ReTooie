#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsstonehead_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C28: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C28);
    return;
    // 0x80083C2C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _sudialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A298: syscall     833
    recomp_syscall_handler(rdram, ctx, 0x8008A298);
    return;
    // 0x8008A29C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800C06C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C06C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C06C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C06CC: jal         0x800C0638
    // 0x800C06D0: nop

    func_800C0638(rdram, ctx);
        goto after_0;
    // 0x800C06D0: nop

    after_0:
    // 0x800C06D4: beq         $v0, $zero, L_800C0700
    if (ctx->r2 == 0) {
        // 0x800C06D8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C0700;
    }
    // 0x800C06D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C06DC: addiu       $v0, $v0, -0x7750
    ctx->r2 = ADD32(ctx->r2, -0X7750);
    // 0x800C06E0: lbu         $t7, 0x15E($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X15E);
    // 0x800C06E4: lb          $t1, 0x166($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X166);
    // 0x800C06E8: ori         $t9, $t7, 0x20
    ctx->r25 = ctx->r15 | 0X20;
    // 0x800C06EC: sb          $t9, 0x15E($v0)
    MEM_B(0X15E, ctx->r2) = ctx->r25;
    // 0x800C06F0: andi        $t0, $t9, 0xEF
    ctx->r8 = ctx->r25 & 0XEF;
    // 0x800C06F4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800C06F8: sb          $t0, 0x15E($v0)
    MEM_B(0X15E, ctx->r2) = ctx->r8;
    // 0x800C06FC: sb          $t2, 0x166($v0)
    MEM_B(0X166, ctx->r2) = ctx->r10;
L_800C0700:
    // 0x800C0700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0708: jr          $ra
    // 0x800C070C: nop

    return;
    // 0x800C070C: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A0: jr          $ra
    // 0x808005A4: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    return;
    // 0x808005A4: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
;}
RECOMP_FUNC void func_800C067C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C067C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0684: jal         0x800C064C
    // 0x800C0688: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800C064C(rdram, ctx);
        goto after_0;
    // 0x800C0688: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C068C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C0690: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0694: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    // 0x800C0698: beq         $v0, $t6, L_800C06A8
    if (ctx->r2 == ctx->r14) {
        // 0x800C069C: nop
    
            goto L_800C06A8;
    }
    // 0x800C069C: nop

    // 0x800C06A0: b           L_800C06B4
    // 0x800C06A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C06B4;
    // 0x800C06A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C06A8:
    // 0x800C06A8: jal         0x80087E58
    // 0x800C06AC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _gcdialogexec_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x800C06AC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x800C06B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C06B4:
    // 0x800C06B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C06B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C06BC: jr          $ra
    // 0x800C06C0: nop

    return;
    // 0x800C06C0: nop

;}
RECOMP_FUNC void _chhoopswoop_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F08: syscall     259
    recomp_syscall_handler(rdram, ctx, 0x80085F08);
    return;
    // 0x80085F0C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801948_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801948: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080194C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801950: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801954: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801958: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x8080195C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1008, 0X1D18) << 16);
    // 0x80801960: addiu       $a3, $a3, 0x1D18
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1008, 0X1D18));
    // 0x80801964: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x80801968: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8080196C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801970: jal         0x8010D930
    // 0x80801974: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8010D930(rdram, ctx);
        goto after_0;
    // 0x80801974: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80801978: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x8080197C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80801980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801984: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80801988: bgez        $t9, L_808019D4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8080198C: addiu       $a1, $zero, 0x771
        ctx->r5 = ADD32(0, 0X771);
            goto L_808019D4;
    }
    // 0x8080198C: addiu       $a1, $zero, 0x771
    ctx->r5 = ADD32(0, 0X771);
    // 0x80801990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801994: jal         0x80801A50
    // 0x80801998: addiu       $a1, $zero, 0x771
    ctx->r5 = ADD32(0, 0X771);
    func_80801A50_chballoonburst(rdram, ctx);
        goto after_1;
    // 0x80801998: addiu       $a1, $zero, 0x771
    ctx->r5 = ADD32(0, 0X771);
    after_1:
    // 0x8080199C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019A0: addiu       $a1, $zero, 0x772
    ctx->r5 = ADD32(0, 0X772);
    // 0x808019A4: jal         0x80801A50
    // 0x808019A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80801A50_chballoonburst(rdram, ctx);
        goto after_2;
    // 0x808019A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x808019AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019B0: addiu       $a1, $zero, 0x773
    ctx->r5 = ADD32(0, 0X773);
    // 0x808019B4: jal         0x80801A50
    // 0x808019B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80801A50_chballoonburst(rdram, ctx);
        goto after_3;
    // 0x808019B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x808019BC: jal         0x80801ABC
    // 0x808019C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801ABC_chballoonburst(rdram, ctx);
        goto after_4;
    // 0x808019C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808019C4: jal         0x80801A10
    // 0x808019C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A10_chballoonburst(rdram, ctx);
        goto after_5;
    // 0x808019C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808019CC: b           L_80801A00
    // 0x808019D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801A00;
    // 0x808019D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808019D4:
    // 0x808019D4: jal         0x80801A50
    // 0x808019D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80801A50_chballoonburst(rdram, ctx);
        goto after_6;
    // 0x808019D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x808019DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019E0: addiu       $a1, $zero, 0x772
    ctx->r5 = ADD32(0, 0X772);
    // 0x808019E4: jal         0x80801A50
    // 0x808019E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80801A50_chballoonburst(rdram, ctx);
        goto after_7;
    // 0x808019E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
    // 0x808019EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019F0: addiu       $a1, $zero, 0x773
    ctx->r5 = ADD32(0, 0X773);
    // 0x808019F4: jal         0x80801A50
    // 0x808019F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80801A50_chballoonburst(rdram, ctx);
        goto after_8;
    // 0x808019F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x808019FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A00:
    // 0x80801A00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801A08: jr          $ra
    // 0x80801A0C: nop

    return;
    // 0x80801A0C: nop

;}
RECOMP_FUNC void _bamovegoto_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DE0: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084DE0);
    return;
    // 0x80084DE4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void fxegg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080014C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800150: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800154: jal         0x800B5BE4
    // 0x80800158: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800158: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x8080015C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800160: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800164: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800168: addiu       $a2, $zero, 0x9E5
    ctx->r6 = ADD32(0, 0X9E5);
    // 0x8080016C: jal         0x808000F8
    // 0x80800170: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_808000F8_fxegg(rdram, ctx);
        goto after_1;
    // 0x80800170: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800178: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8080017C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void func_800A1658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1658: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A165C: addiu       $v1, $v1, 0x7090
    ctx->r3 = ADD32(ctx->r3, 0X7090);
    // 0x800A1660: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
    // 0x800A1664: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A1668: bnel        $a0, $t6, L_800A1688
    if (ctx->r4 != ctx->r14) {
        // 0x800A166C: sb          $t7, 0x7($v1)
        MEM_B(0X7, ctx->r3) = ctx->r15;
            goto L_800A1688;
    }
    goto skip_0;
    // 0x800A166C: sb          $t7, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r15;
    skip_0:
    // 0x800A1670: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x800A1674: beq         $v0, $zero, L_800A168C
    if (ctx->r2 == 0) {
        // 0x800A1678: nop
    
            goto L_800A168C;
    }
    // 0x800A1678: nop

    // 0x800A167C: beq         $a0, $v0, L_800A168C
    if (ctx->r4 == ctx->r2) {
        // 0x800A1680: nop
    
            goto L_800A168C;
    }
    // 0x800A1680: nop

    // 0x800A1684: sb          $t7, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r15;
L_800A1688:
    // 0x800A1688: sb          $a0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r4;
L_800A168C:
    // 0x800A168C: jr          $ra
    // 0x800A1690: nop

    return;
    // 0x800A1690: nop

;}
RECOMP_FUNC void func_800C8D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8D4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C8D50: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8D58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C8D5C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8D60: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8D64: jal         0x800B28CC
    // 0x800C8D68: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C8D68: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x800C8D6C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800C8D70: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C8D74: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C8D78: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800C8D7C: nop

    // 0x800C8D80: sh          $t7, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r15;
    // 0x800C8D84: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800C8D88: lh          $t1, 0x18($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X18);
    // 0x800C8D8C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C8D90: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800C8D94: nop

    // 0x800C8D98: sh          $t9, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r25;
    // 0x800C8D9C: lh          $t0, 0x1A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1A);
    // 0x800C8DA0: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800C8DA4: beql        $at, $zero, L_800C8DB4
    if (ctx->r1 == 0) {
        // 0x800C8DA8: lh          $v1, 0x1A($sp)
        ctx->r3 = MEM_H(ctx->r29, 0X1A);
            goto L_800C8DB4;
    }
    goto skip_0;
    // 0x800C8DA8: lh          $v1, 0x1A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1A);
    skip_0:
    // 0x800C8DAC: sh          $t1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r9;
    // 0x800C8DB0: lh          $v1, 0x1A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1A);
L_800C8DB4:
    // 0x800C8DB4: lh          $a0, 0x18($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X18);
    // 0x800C8DB8: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x800C8DBC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800C8DC0: beql        $at, $zero, L_800C8DD8
    if (ctx->r1 == 0) {
        // 0x800C8DC4: sh          $v1, 0x1A($sp)
        MEM_H(0X1A, ctx->r29) = ctx->r3;
            goto L_800C8DD8;
    }
    goto skip_1;
    // 0x800C8DC4: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    skip_1:
    // 0x800C8DC8: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x800C8DCC: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C8DD0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800C8DD4: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
L_800C8DD8:
    // 0x800C8DD8: bne         $a0, $v1, L_800C8DE4
    if (ctx->r4 != ctx->r3) {
        // 0x800C8DDC: sh          $a0, 0x18($sp)
        MEM_H(0X18, ctx->r29) = ctx->r4;
            goto L_800C8DE4;
    }
    // 0x800C8DDC: sh          $a0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r4;
    // 0x800C8DE0: sh          $t5, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r13;
L_800C8DE4:
    // 0x800C8DE4: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800C8DE8: lh          $t7, 0x18($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X18);
    // 0x800C8DEC: lh          $t9, 0x1A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X1A);
    // 0x800C8DF0: lh          $t0, 0x18($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X18);
    // 0x800C8DF4: bnel        $t6, $t7, L_800C8E0C
    if (ctx->r14 != ctx->r15) {
        // 0x800C8DF8: sh          $t0, 0x6($v0)
        MEM_H(0X6, ctx->r2) = ctx->r8;
            goto L_800C8E0C;
    }
    goto skip_2;
    // 0x800C8DF8: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
    skip_2:
    // 0x800C8DFC: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x800C8E00: beql        $t8, $t9, L_800C8E48
    if (ctx->r24 == ctx->r25) {
        // 0x800C8E04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8E48;
    }
    goto skip_3;
    // 0x800C8E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800C8E08: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
L_800C8E0C:
    // 0x800C8E0C: lh          $t1, 0x1A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X1A);
    // 0x800C8E10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C8E14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C8E18: sh          $t1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r9;
    // 0x800C8E1C: lh          $t3, 0x18($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X18);
    // 0x800C8E20: lh          $t2, 0x1A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1A);
    // 0x800C8E24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C8E28: sb          $t6, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r14;
    // 0x800C8E2C: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800C8E30: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800C8E34: sb          $t6, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r14;
    // 0x800C8E38: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C8E3C: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800C8E40: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800C8E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8E48:
    // 0x800C8E48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C8E4C: jr          $ra
    // 0x800C8E50: nop

    return;
    // 0x800C8E50: nop

;}
RECOMP_FUNC void func_800DF33C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF33C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800DF340: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF344: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800DF348: jr          $ra
    // 0x800DF34C: lw          $v0, -0x37B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X37B0);
    return;
    // 0x800DF34C: lw          $v0, -0x37B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X37B0);
;}
RECOMP_FUNC void bsstonehead_entrypoint_41(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808014B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808014B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808014B8: jal         0x80800060
    // 0x808014BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x808014BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808014C0: lui         $a2, 0x40C3
    ctx->r6 = S32(0X40C3 << 16);
    // 0x808014C4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808014C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014CC: jal         0x8008CB3C
    // 0x808014D0: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808014D0: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_1:
    // 0x808014D4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808014D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808014E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808014E8: jal         0x8009FFD8
    // 0x808014EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808014EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x808014F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014F4: jal         0x8009B9B0
    // 0x808014F8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x808014F8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808014FC: jal         0x800909CC
    // 0x80801500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_4;
    // 0x80801500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801508: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080150C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801510: jr          $ra
    // 0x80801514: nop

    return;
    // 0x80801514: nop

;}
RECOMP_FUNC void chfloaty_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2416, 0XE00) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xE00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2416, 0XE00));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xE00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2416, 0XE00));
;}
RECOMP_FUNC void func_80800298_suautobaddies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080029C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A0: jal         0x800DA298
    // 0x808002A4: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808002A4: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    after_0:
    // 0x808002A8: beql        $v0, $zero, L_808002E8
    if (ctx->r2 == 0) {
        // 0x808002AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E8;
    }
    goto skip_0;
    // 0x808002AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002B0: jal         0x800EA05C
    // 0x808002B4: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x808002B4: nop

    after_1:
    // 0x808002B8: addiu       $at, $zero, 0x19C
    ctx->r1 = ADD32(0, 0X19C);
    // 0x808002BC: beq         $v0, $at, L_808002E4
    if (ctx->r2 == ctx->r1) {
        // 0x808002C0: addiu       $at, $zero, 0x19D
        ctx->r1 = ADD32(0, 0X19D);
            goto L_808002E4;
    }
    // 0x808002C0: addiu       $at, $zero, 0x19D
    ctx->r1 = ADD32(0, 0X19D);
    // 0x808002C4: beql        $v0, $at, L_808002E8
    if (ctx->r2 == ctx->r1) {
        // 0x808002C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002E8;
    }
    goto skip_1;
    // 0x808002C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808002CC: jal         0x800EFD24
    // 0x808002D0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x808002D0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x808002D4: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    // 0x808002D8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808002DC: jal         0x80108474
    // 0x808002E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_3;
    // 0x808002E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_808002E4:
    // 0x808002E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002E8:
    // 0x808002E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002EC: jr          $ra
    // 0x808002F0: nop

    return;
    // 0x808002F0: nop

;}
RECOMP_FUNC void bsmum_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801100: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801104: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(308, 0X11B0) << 16);
    // 0x80801108: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080110C: jr          $ra
    // 0x80801110: lw          $v0, 0x11B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X11B0));
    return;
    // 0x80801110: lw          $v0, 0x11B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X11B0));
;}
RECOMP_FUNC void func_800EC358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC358: jr          $ra
    // 0x800EC35C: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    return;
    // 0x800EC35C: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_800F05F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F05F8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800F05FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0600: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800F0604: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800F0608: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F060C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F0610: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800F0614: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800F0618: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F061C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800F0620: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F0624: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800F0628: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800F062C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F0630: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800F0634: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800F0638: nop

    // 0x800F063C: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800F0640: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F0644: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800F0648: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x800F064C: nop

    // 0x800F0650: bc1f        L_800F0660
    if (!c1cs) {
        // 0x800F0654: nop
    
            goto L_800F0660;
    }
    // 0x800F0654: nop

    // 0x800F0658: b           L_800F0724
    // 0x800F065C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0724;
    // 0x800F065C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0660:
    // 0x800F0660: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800F0664: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800F0668: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800F066C: add.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800F0670: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800F0674: nop

    // 0x800F0678: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800F067C: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800F0680: add.s       $f14, $f0, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800F0684: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800F0688: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800F068C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800F0690: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800F0694: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800F0698: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800F069C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800F06A0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F06A4: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F06A8: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800F06AC: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800F06B0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800F06B4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F06B8: bc1f        L_800F06C8
    if (!c1cs) {
        // 0x800F06BC: nop
    
            goto L_800F06C8;
    }
    // 0x800F06BC: nop

    // 0x800F06C0: b           L_800F0724
    // 0x800F06C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0724;
    // 0x800F06C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F06C8:
    // 0x800F06C8: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800F06CC: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x800F06D0: jal         0x8002DCA0
    // 0x800F06D4: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F06D4: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800F06D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800F06DC: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F06E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F06E4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F06E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800F06EC: div.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F06F0: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800F06F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F06F8: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x800F06FC: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800F0700: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800F0704: bc1t        L_800F0724
    if (c1cs) {
        // 0x800F0708: swc1        $f10, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
            goto L_800F0724;
    }
    // 0x800F0708: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x800F070C: add.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x800F0710: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F0714: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800F0718: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800F071C: b           L_800F0724
    // 0x800F0720: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
        goto L_800F0724;
    // 0x800F0720: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
L_800F0724:
    // 0x800F0724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0728: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800F072C: jr          $ra
    // 0x800F0730: nop

    return;
    // 0x800F0730: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_45(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D8C: beql        $a1, $zero, L_80803DA8
    if (ctx->r5 == 0) {
        // 0x80803D90: lbu         $t9, 0x1E7($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X1E7);
            goto L_80803DA8;
    }
    goto skip_0;
    // 0x80803D90: lbu         $t9, 0x1E7($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E7);
    skip_0:
    // 0x80803D94: lbu         $t7, 0x1E7($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E7);
    // 0x80803D98: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80803D9C: jr          $ra
    // 0x80803DA0: sb          $t8, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r24;
    return;
    // 0x80803DA0: sb          $t8, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r24;
    // 0x80803DA4: lbu         $t9, 0x1E7($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E7);
L_80803DA8:
    // 0x80803DA8: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80803DAC: sb          $t0, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r8;
    // 0x80803DB0: jr          $ra
    // 0x80803DB4: nop

    return;
    // 0x80803DB4: nop

    // 0x80803DB8: nop

    // 0x80803DBC: nop

;}
RECOMP_FUNC void func_80803718_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080371C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803720: jal         0x80088530
    // 0x80803724: nop

    _glsavegame_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80803724: nop

    after_0:
    // 0x80803728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080372C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803730: jr          $ra
    // 0x80803734: nop

    return;
    // 0x80803734: nop

;}
RECOMP_FUNC void func_80800048_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16B0) << 16);
    // 0x8080004C: lwc1        $f6, 0x16B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16B0));
    // 0x80800050: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x80800054: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80800058: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_80800080_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800084: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800088: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080008C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800090: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800098: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080009C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000A4: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808000A8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x808000AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000B4: jal         0x80089F18
    // 0x808000B8: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808000B8: nop

    after_0:
    // 0x808000BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1300, 0XEB8) << 16);
    // 0x808000C0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1300, 0XECC) << 16);
    // 0x808000C4: addiu       $a3, $a3, 0xECC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1300, 0XECC));
    // 0x808000C8: addiu       $a2, $a2, 0xEB8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1300, 0XEB8));
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x80089D28
    // 0x808000D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808000D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808000D8: jal         0x80089828
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000E4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808000E8: jal         0x800897D8
    // 0x808000EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808000EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808000F0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808000F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800100: bne         $t7, $at, L_80800110
    if (ctx->r15 != ctx->r1) {
        // 0x80800104: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1300, 0XEDC) << 16);
            goto L_80800110;
    }
    // 0x80800104: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1300, 0XEDC) << 16);
    // 0x80800108: jal         0x808009F0
    // 0x8080010C: addiu       $a1, $a1, 0xEDC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1300, 0XEDC));
    func_808009F0_chbottlesfamily(rdram, ctx);
        goto after_4;
    // 0x8080010C: addiu       $a1, $a1, 0xEDC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1300, 0XEDC));
    after_4:
L_80800110:
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void _ncbasub_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089708: syscall     789
    recomp_syscall_handler(rdram, ctx, 0x80089708);
    return;
    // 0x8008970C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8010A624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A624: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8010A628: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8010A62C: lbu         $t7, 0xB($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XB);
    // 0x8010A630: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x8010A634: jr          $ra
    // 0x8010A638: sb          $t8, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r24;
    return;
    // 0x8010A638: sb          $t8, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_8080141C_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080141C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801420: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801424: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801428: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8080142C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80801430: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    // 0x80801434: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x80801438: jal         0x80801370
    // 0x8080143C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80801370_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x8080143C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80801440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801448: jr          $ra
    // 0x8080144C: nop

    return;
    // 0x8080144C: nop

;}
RECOMP_FUNC void _bacough_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084638: syscall     117
    recomp_syscall_handler(rdram, ctx, 0x80084638);
    return;
    // 0x8008463C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80105998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105998: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8010599C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801059A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801059A4: jal         0x80105494
    // 0x801059A8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x801059A8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x801059AC: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801059B0: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801059B4: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801059B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801059BC: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x801059C0: nop

    // 0x801059C4: bc1fl       L_801059D8
    if (!c1cs) {
        // 0x801059C8: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_801059D8;
    }
    goto skip_0;
    // 0x801059C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x801059CC: b           L_80105A54
    // 0x801059D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80105A54;
    // 0x801059D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801059D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_801059D8:
    // 0x801059D8: nop

    // 0x801059DC: bc1fl       L_80105A20
    if (!c1cs) {
        // 0x801059E0: c.le.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
            goto L_80105A20;
    }
    goto skip_1;
    // 0x801059E0: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    skip_1:
    // 0x801059E4: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x801059E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801059EC: bc1f        L_801059F8
    if (!c1cs) {
        // 0x801059F0: nop
    
            goto L_801059F8;
    }
    // 0x801059F0: nop

    // 0x801059F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801059F8:
    // 0x801059F8: beq         $v0, $zero, L_80105A14
    if (ctx->r2 == 0) {
        // 0x801059FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80105A14;
    }
    // 0x801059FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80105A00: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80105A04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80105A08: bc1f        L_80105A14
    if (!c1cs) {
        // 0x80105A0C: nop
    
            goto L_80105A14;
    }
    // 0x80105A0C: nop

    // 0x80105A10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80105A14:
    // 0x80105A14: b           L_80105A50
    // 0x80105A18: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_80105A50;
    // 0x80105A18: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80105A1C: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
L_80105A20:
    // 0x80105A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80105A24: bc1f        L_80105A30
    if (!c1cs) {
        // 0x80105A28: nop
    
            goto L_80105A30;
    }
    // 0x80105A28: nop

    // 0x80105A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80105A30:
    // 0x80105A30: bne         $v0, $zero, L_80105A4C
    if (ctx->r2 != 0) {
        // 0x80105A34: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80105A4C;
    }
    // 0x80105A34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80105A38: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80105A3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80105A40: bc1fl       L_80105A50
    if (!c1cs) {
        // 0x80105A44: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80105A50;
    }
    goto skip_2;
    // 0x80105A44: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    skip_2:
    // 0x80105A48: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80105A4C:
    // 0x80105A4C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80105A50:
    // 0x80105A50: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80105A54:
    // 0x80105A54: jr          $ra
    // 0x80105A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80105138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105138: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010513C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80105140: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80105144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80105148: beq         $a1, $zero, L_80105158
    if (ctx->r5 == 0) {
        // 0x8010514C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80105158;
    }
    // 0x8010514C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80105150: b           L_80105160
    // 0x80105154: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
        goto L_80105160;
    // 0x80105154: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80105158:
    // 0x80105158: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8010515C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80105160:
    // 0x80105160: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80105164: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80105168: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8010516C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80105170: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    // 0x80105174: jal         0x800C696C
    // 0x80105178: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800C696C(rdram, ctx);
        goto after_0;
    // 0x80105178: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8010517C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80105180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80105184: jr          $ra
    // 0x80105188: nop

    return;
    // 0x80105188: nop

;}
RECOMP_FUNC void func_80093DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093DF4: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093DF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80093DFC: lbu         $t7, 0xA2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA2);
    // 0x80093E00: bne         $a1, $t7, L_80093E10
    if (ctx->r5 != ctx->r15) {
        // 0x80093E04: nop
    
            goto L_80093E10;
    }
    // 0x80093E04: nop

    // 0x80093E08: jr          $ra
    // 0x80093E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80093E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80093E10:
    // 0x80093E10: jr          $ra
    // 0x80093E14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80093E14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80801B30_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B38: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80801B3C: sb          $t6, 0x171($a0)
    MEM_B(0X171, ctx->r4) = ctx->r14;
    // 0x80801B40: jal         0x80803410
    // 0x80801B44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gczoombox_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x80801B44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801B48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801B4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801B50: lbu         $t7, 0x1E4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E4);
    // 0x80801B54: swc1        $f4, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->f4.u32l;
    // 0x80801B58: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80801B5C: beql        $t8, $zero, L_80801B78
    if (ctx->r24 == 0) {
        // 0x80801B60: lh          $t1, 0x1B2($a0)
        ctx->r9 = MEM_H(ctx->r4, 0X1B2);
            goto L_80801B78;
    }
    goto skip_0;
    // 0x80801B60: lh          $t1, 0x1B2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X1B2);
    skip_0:
    // 0x80801B64: lh          $t9, 0x1B2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X1B2);
    // 0x80801B68: addiu       $t0, $t9, 0x8C
    ctx->r8 = ADD32(ctx->r25, 0X8C);
    // 0x80801B6C: b           L_80801B80
    // 0x80801B70: sh          $t0, 0x1AE($a0)
    MEM_H(0X1AE, ctx->r4) = ctx->r8;
        goto L_80801B80;
    // 0x80801B70: sh          $t0, 0x1AE($a0)
    MEM_H(0X1AE, ctx->r4) = ctx->r8;
    // 0x80801B74: lh          $t1, 0x1B2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X1B2);
L_80801B78:
    // 0x80801B78: addiu       $t2, $t1, -0x8C
    ctx->r10 = ADD32(ctx->r9, -0X8C);
    // 0x80801B7C: sh          $t2, 0x1AE($a0)
    MEM_H(0X1AE, ctx->r4) = ctx->r10;
L_80801B80:
    // 0x80801B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B88: jr          $ra
    // 0x80801B8C: nop

    return;
    // 0x80801B8C: nop

;}
RECOMP_FUNC void func_800D9058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9058: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800D905C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D9060: nop

    // 0x800D9064: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800D9068: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D906C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D9070: jr          $ra
    // 0x800D9074: nop

    return;
    // 0x800D9074: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80800004: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800008: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x8080000C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800010: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80800014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080001C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800020: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800024: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800028: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080002C: jal         0x80100074
    // 0x80800030: addiu       $a2, $t6, 0x64
    ctx->r6 = ADD32(ctx->r14, 0X64);
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800030: addiu       $a2, $t6, 0x64
    ctx->r6 = ADD32(ctx->r14, 0X64);
    after_0:
    // 0x80800034: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800038: jal         0x80100094
    // 0x8080003C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080003C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800040: lh          $t7, 0x2E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2E);
    // 0x80800044: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800048: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x8080004C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80800050: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800054: sh          $t8, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r24;
    // 0x80800058: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080005C: jal         0x800EE7F8
    // 0x80800060: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800060: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800064: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800068: sb          $zero, 0x63($t9)
    MEM_B(0X63, ctx->r25) = 0;
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void func_80800400_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800400: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800404: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800408: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080040C: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80800410: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800414: bltzl       $v0, L_80800550
    if (SIGNED(ctx->r2) < 0) {
        // 0x80800418: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800550;
    }
    goto skip_0;
    // 0x80800418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080041C: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80800420: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80800424: bgez        $t7, L_80800434
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800428: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80800434;
    }
    // 0x80800428: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8080042C: bltzl       $t9, L_80800550
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800430: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800550;
    }
    goto skip_1;
    // 0x80800430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
L_80800434:
    // 0x80800434: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x80800438: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1824, 0X14F4) << 16);
    // 0x8080043C: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80800440: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80800444: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80800448: lw          $v1, 0x14F4($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(1824, 0X14F4));
    // 0x8080044C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800450: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80800454: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x80800458: lb          $t4, 0x3($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X3);
    // 0x8080045C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80800460: beql        $t4, $at, L_80800550
    if (ctx->r12 == ctx->r1) {
        // 0x80800464: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800550;
    }
    goto skip_2;
    // 0x80800464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800468: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8080046C: sh          $t6, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r14;
    // 0x80800470: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x80800474: addiu       $t0, $sp, 0x36
    ctx->r8 = ADD32(ctx->r29, 0X36);
    // 0x80800478: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8080047C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800480: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x80800484: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80800488: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x8080048C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80800490: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x80800494: lb          $a1, 0x3($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X3);
    // 0x80800498: jal         0x800FEF94
    // 0x8080049C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800FEF94(rdram, ctx);
        goto after_0;
    // 0x8080049C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x808004A0: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
    // 0x808004A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808004A8: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    // 0x808004AC: bltzl       $t2, L_808004E4
    if (SIGNED(ctx->r10) < 0) {
        // 0x808004B0: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_808004E4;
    }
    goto skip_3;
    // 0x808004B0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    skip_3:
    // 0x808004B4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808004B8: jal         0x800FCDE0
    // 0x808004BC: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    func_800FCDE0(rdram, ctx);
        goto after_1;
    // 0x808004BC: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    after_1:
    // 0x808004C0: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    // 0x808004C4: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x808004C8: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x808004CC: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x808004D0: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x808004D4: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x808004D8: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    // 0x808004DC: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
    // 0x808004E0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_808004E4:
    // 0x808004E4: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x808004E8: bne         $t0, $zero, L_8080054C
    if (ctx->r8 != 0) {
        // 0x808004EC: lh          $t1, 0x36($sp)
        ctx->r9 = MEM_H(ctx->r29, 0X36);
            goto L_8080054C;
    }
    // 0x808004EC: lh          $t1, 0x36($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X36);
    // 0x808004F0: lui         $t2, 0x393
    ctx->r10 = S32(0X393 << 16);
    // 0x808004F4: ori         $t2, $t2, 0x8700
    ctx->r10 = ctx->r10 | 0X8700;
    // 0x808004F8: div         $zero, $t2, $t1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r9)));
    // 0x808004FC: mflo        $a1
    ctx->r5 = lo;
    // 0x80800500: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800504: bne         $t1, $zero, L_80800510
    if (ctx->r9 != 0) {
        // 0x80800508: nop
    
            goto L_80800510;
    }
    // 0x80800508: nop

    // 0x8080050C: break       7
    do_break(2155873548);
L_80800510:
    // 0x80800510: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800514: bne         $t1, $at, L_80800528
    if (ctx->r9 != ctx->r1) {
        // 0x80800518: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800528;
    }
    // 0x80800518: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080051C: bne         $t2, $at, L_80800528
    if (ctx->r10 != ctx->r1) {
        // 0x80800520: nop
    
            goto L_80800528;
    }
    // 0x80800520: nop

    // 0x80800524: break       6
    do_break(2155873572);
L_80800528:
    // 0x80800528: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x8080052C: jal         0x800FCED0
    // 0x80800530: nop

    func_800FCED0(rdram, ctx);
        goto after_2;
    // 0x80800530: nop

    after_2:
    // 0x80800534: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
    // 0x80800538: sll         $t4, $v0, 5
    ctx->r12 = S32(ctx->r2 << 5);
    // 0x8080053C: andi        $t6, $t4, 0x20
    ctx->r14 = ctx->r12 & 0X20;
    // 0x80800540: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80800544: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80800548: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
L_8080054C:
    // 0x8080054C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800550:
    // 0x80800550: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800554: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800558: jr          $ra
    // 0x8080055C: nop

    return;
    // 0x8080055C: nop

;}
RECOMP_FUNC void bsbanswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800380: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(53, 0XA30) << 16);
    // 0x80800384: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800388: jr          $ra
    // 0x8080038C: lw          $v0, 0xA30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(53, 0XA30));
    return;
    // 0x8080038C: lw          $v0, 0xA30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(53, 0XA30));
;}
RECOMP_FUNC void func_800F8300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8300: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8308: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F830C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8310: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8314: jal         0x800F45B0
    // 0x800F8318: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F45B0(rdram, ctx);
        goto after_0;
    // 0x800F8318: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F831C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8324: jr          $ra
    // 0x800F8328: nop

    return;
    // 0x800F8328: nop

;}
RECOMP_FUNC void func_800C3528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C352C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3530: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3534: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C353C: beq         $t6, $zero, L_800C3574
    if (ctx->r14 == 0) {
        // 0x800C3540: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C3574;
    }
    // 0x800C3540: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C3544: jal         0x800C1414
    // 0x800C3548: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3548: nop

    after_0:
    // 0x800C354C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3550: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C3554: beq         $t7, $zero, L_800C356C
    if (ctx->r15 == 0) {
        // 0x800C3558: nop
    
            goto L_800C356C;
    }
    // 0x800C3558: nop

    // 0x800C355C: jal         0x800C13A0
    // 0x800C3560: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800C13A0(rdram, ctx);
        goto after_1;
    // 0x800C3560: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_1:
    // 0x800C3564: b           L_800C3578
    // 0x800C3568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C3578;
    // 0x800C3568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C356C:
    // 0x800C356C: jal         0x800C13B0
    // 0x800C3570: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800C13B0(rdram, ctx);
        goto after_2;
    // 0x800C3570: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_2:
L_800C3574:
    // 0x800C3574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C3578:
    // 0x800C3578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C357C: jr          $ra
    // 0x800C3580: nop

    return;
    // 0x800C3580: nop

;}
RECOMP_FUNC void func_80800000_chmole_hailfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1828, 0XC0) << 16);
    // 0x8080000C: jal         0x800899E8
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1828, 0XC0));
    _sumole_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1828, 0XC0));
    after_0:
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x808005C4: lh          $t6, 0x75EC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X75EC);
    // 0x808005C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005D0: xor         $v0, $a0, $t6
    ctx->r2 = ctx->r4 ^ ctx->r14;
    // 0x808005D4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808005D8: beql        $v0, $zero, L_808005F4
    if (ctx->r2 == 0) {
        // 0x808005DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005F4;
    }
    goto skip_0;
    // 0x808005DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808005E0: jal         0x800DB9B0
    // 0x808005E4: nop

    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x808005E4: nop

    after_0:
    // 0x808005E8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x808005EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005F4:
    // 0x808005F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005F8: jr          $ra
    // 0x808005FC: nop

    return;
    // 0x808005FC: nop

;}
RECOMP_FUNC void suexpression_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800264: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x80800268: beql        $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x8080026C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080027C;
    }
    goto skip_0;
    // 0x8080026C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800270: jal         0x80089B58
    // 0x80800274: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    _suexpressmorph_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800274: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080027C:
    // 0x8080027C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800280: jr          $ra
    // 0x80800284: nop

    return;
    // 0x80800284: nop

;}
RECOMP_FUNC void bswasher_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801368: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080136C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1E80) << 16);
    // 0x80801370: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801374: jr          $ra
    // 0x80801378: lw          $v0, 0x1E80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E80));
    return;
    // 0x80801378: lw          $v0, 0x1E80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E80));
;}
RECOMP_FUNC void chmonsterinterior_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1320, 0X1E80) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1E80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1320, 0X1E80));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1E80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1320, 0X1E80));
;}
RECOMP_FUNC void func_80800E34_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E34: jr          $ra
    // 0x80800E38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800E38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808009B0_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808009B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009C0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x808009C4: jal         0x8009D3A8
    // 0x808009C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x808009C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: jal         0x80800064
    // 0x808009D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800064_bssnowball(rdram, ctx);
        goto after_1;
    // 0x808009D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808009D8: jal         0x80800000
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bssnowball(rdram, ctx);
        goto after_2;
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808009E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(356, 0XF10) << 16);
    // 0x808009E4: lwc1        $f2, 0xF10($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(356, 0XF10));
    // 0x808009E8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808009EC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808009F0: nop

    // 0x808009F4: bc1fl       L_80800AA4
    if (!c1cs) {
        // 0x808009F8: lwc1        $f4, 0x28($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800AA4;
    }
    goto skip_0;
    // 0x808009F8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x808009FC: lwc1        $f4, 0x174($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X174);
    // 0x80800A00: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80800A04: nop

    // 0x80800A08: bc1fl       L_80800AA4
    if (!c1cs) {
        // 0x80800A0C: lwc1        $f4, 0x28($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800AA4;
    }
    goto skip_1;
    // 0x80800A0C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800A10: jal         0x8009BB5C
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_3;
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A18: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(356, 0XF14) << 16);
    // 0x80800A1C: lwc1        $f6, 0xF14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(356, 0XF14));
    // 0x80800A20: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800A24: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x80800A28: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800A2C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800A30: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    // 0x80800A34: jal         0x800F10B4
    // 0x80800A38: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800A38: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80800A3C: lbu         $t6, 0x164($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X164);
    // 0x80800A40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(356, 0XF1C) << 16);
    // 0x80800A44: beq         $t6, $zero, L_80800A5C
    if (ctx->r14 == 0) {
        // 0x80800A48: nop
    
            goto L_80800A5C;
    }
    // 0x80800A48: nop

    // 0x80800A4C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(356, 0XF18) << 16);
    // 0x80800A50: lwc1        $f8, 0xF18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(356, 0XF18));
    // 0x80800A54: b           L_80800A64
    // 0x80800A58: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
        goto L_80800A64;
    // 0x80800A58: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
L_80800A5C:
    // 0x80800A5C: lwc1        $f10, 0xF1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(356, 0XF1C));
    // 0x80800A60: add.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f10.fl;
L_80800A64:
    // 0x80800A64: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(356, 0XF20) << 16);
    // 0x80800A68: lwc1        $f0, 0xF20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(356, 0XF20));
    // 0x80800A6C: addiu       $t7, $zero, 0x6D60
    ctx->r15 = ADD32(0, 0X6D60);
    // 0x80800A70: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800A74: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A7C: addiu       $a1, $zero, 0x5F2
    ctx->r5 = ADD32(0, 0X5F2);
    // 0x80800A80: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80800A84: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800A88: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800A8C: jal         0x8009DBB0
    // 0x80800A90: nop

    func_8009DBB0(rdram, ctx);
        goto after_5;
    // 0x80800A90: nop

    after_5:
    // 0x80800A94: lbu         $t8, 0x164($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X164);
    // 0x80800A98: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x80800A9C: sb          $t9, 0x164($s0)
    MEM_B(0X164, ctx->r16) = ctx->r25;
    // 0x80800AA0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
L_80800AA4:
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA8: jal         0x8009EF10
    // 0x80800AAC: swc1        $f4, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f4.u32l;
    bastick_getZone(rdram, ctx);
        goto after_6;
    // 0x80800AAC: swc1        $f4, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f4.u32l;
    after_6:
    // 0x80800AB0: bne         $v0, $zero, L_80800ADC
    if (ctx->r2 != 0) {
        // 0x80800AB4: nop
    
            goto L_80800ADC;
    }
    // 0x80800AB4: nop

    // 0x80800AB8: jal         0x800850F0
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basnowball_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800AC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800AC4: addiu       $t0, $zero, 0x17D
    ctx->r8 = ADD32(0, 0X17D);
    // 0x80800AC8: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800ACC: nop

    // 0x80800AD0: bc1f        L_80800ADC
    if (!c1cs) {
        // 0x80800AD4: nop
    
            goto L_80800ADC;
    }
    // 0x80800AD4: nop

    // 0x80800AD8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80800ADC:
    // 0x80800ADC: jal         0x8008DD04
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_8;
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800AE4: beq         $v0, $zero, L_80800AF4
    if (ctx->r2 == 0) {
        // 0x80800AE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AF4;
    }
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AEC: addiu       $t1, $zero, 0x180
    ctx->r9 = ADD32(0, 0X180);
    // 0x80800AF0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80800AF4:
    // 0x80800AF4: jal         0x80091A58
    // 0x80800AF8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_9;
    // 0x80800AF8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x80800AFC: beq         $v0, $zero, L_80800B08
    if (ctx->r2 == 0) {
        // 0x80800B00: addiu       $t2, $zero, 0x17F
        ctx->r10 = ADD32(0, 0X17F);
            goto L_80800B08;
    }
    // 0x80800B00: addiu       $t2, $zero, 0x17F
    ctx->r10 = ADD32(0, 0X17F);
    // 0x80800B04: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_80800B08:
    // 0x80800B08: jal         0x808002F8
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bssnowball_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B14: jal         0x8009E5C8
    // 0x80800B18: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x80800B18: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x80800B1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B28: jr          $ra
    // 0x80800B2C: nop

    return;
    // 0x80800B2C: nop

;}
RECOMP_FUNC void _bsmumcast_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083888: syscall     77
    recomp_syscall_handler(rdram, ctx, 0x80083888);
    return;
    // 0x8008388C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808011A0_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A0: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x808011A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1312, 0X27D4) << 16);
    // 0x808011A8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808011AC: jr          $ra
    // 0x808011B0: lh          $v0, 0x27D4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1312, 0X27D4));
    return;
    // 0x808011B0: lh          $v0, 0x27D4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1312, 0X27D4));
;}
RECOMP_FUNC void _sumumbofx_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898B0: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898B0);
    return;
    // 0x800898B4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void sumultiscore_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x808000A4: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x808000A8: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x808000AC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808000B0: bne         $at, $zero, L_80800134
    if (ctx->r1 != 0) {
        // 0x808000B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800134;
    }
    // 0x808000B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000B8:
    // 0x808000B8: blez        $v0, L_80800128
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808000BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800128;
    }
    // 0x808000BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808000C0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808000C4: addu        $a1, $a0, $t6
    ctx->r5 = ADD32(ctx->r4, ctx->r14);
    // 0x808000C8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x808000CC: lw          $t8, -0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, -0X4);
    // 0x808000D0: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x808000D4: addu        $a3, $a0, $a1
    ctx->r7 = ADD32(ctx->r4, ctx->r5);
    // 0x808000D8: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808000DC: beq         $at, $zero, L_80800128
    if (ctx->r1 == 0) {
        // 0x808000E0: addu        $t2, $s0, $a1
        ctx->r10 = ADD32(ctx->r16, ctx->r5);
            goto L_80800128;
    }
    // 0x808000E0: addu        $t2, $s0, $a1
    ctx->r10 = ADD32(ctx->r16, ctx->r5);
    // 0x808000E4: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x808000E8: lw          $t1, -0x4($a3)
    ctx->r9 = MEM_W(ctx->r7, -0X4);
    // 0x808000EC: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
L_808000F0:
    // 0x808000F0: sw          $t0, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r8;
    // 0x808000F4: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x808000F8: lw          $t9, -0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, -0X4);
    // 0x808000FC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80800100: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x80800104: addiu       $t2, $t2, -0x4
    ctx->r10 = ADD32(ctx->r10, -0X4);
    // 0x80800108: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
    // 0x8080010C: blez        $v1, L_80800128
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800110: sw          $t9, 0x4($t2)
        MEM_W(0X4, ctx->r10) = ctx->r25;
            goto L_80800128;
    }
    // 0x80800110: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80800114: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80800118: lw          $t1, -0x4($a3)
    ctx->r9 = MEM_W(ctx->r7, -0X4);
    // 0x8080011C: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800120: bnel        $at, $zero, L_808000F0
    if (ctx->r1 != 0) {
        // 0x80800124: sw          $t1, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r9;
            goto L_808000F0;
    }
    goto skip_0;
    // 0x80800124: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    skip_0:
L_80800128:
    // 0x80800128: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080012C: bne         $v0, $a2, L_808000B8
    if (ctx->r2 != ctx->r6) {
        // 0x80800130: nop
    
            goto L_808000B8;
    }
    // 0x80800130: nop

L_80800134:
    // 0x80800134: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80800138: jr          $ra
    // 0x8080013C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8080013C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8010FDA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FDA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010FDAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010FDB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010FDB4: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8010FDB8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8010FDBC: sb          $t6, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r14;
    // 0x8010FDC0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8010FDC4: jal         0x800EE7F8
    // 0x8010FDC8: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8010FDC8: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_0:
    // 0x8010FDCC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8010FDD0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8010FDD4: jal         0x800EE7F8
    // 0x8010FDD8: addiu       $a0, $a3, 0x30
    ctx->r4 = ADD32(ctx->r7, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8010FDD8: addiu       $a0, $a3, 0x30
    ctx->r4 = ADD32(ctx->r7, 0X30);
    after_1:
    // 0x8010FDDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010FDE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010FDE4: jr          $ra
    // 0x8010FDE8: nop

    return;
    // 0x8010FDE8: nop

;}
RECOMP_FUNC void func_80801058_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801058: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080105C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801060: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801068: jal         0x80800E64
    // 0x8080106C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    bsmum_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x8080106C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801074: jal         0x8008DF8C
    // 0x80801078: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    func_8008DF8C(rdram, ctx);
        goto after_1;
    // 0x80801078: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    after_1:
    // 0x8080107C: beq         $v0, $zero, L_80801094
    if (ctx->r2 == 0) {
        // 0x80801080: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801094;
    }
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801084: jal         0x8009BF5C
    // 0x80801088: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    func_8009BF5C(rdram, ctx);
        goto after_2;
    // 0x80801088: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    after_2:
    // 0x8080108C: b           L_808010B8
    // 0x80801090: nop

        goto L_808010B8;
    // 0x80801090: nop

L_80801094:
    // 0x80801094: jal         0x8009BFD8
    // 0x80801098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_3;
    // 0x80801098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080109C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808010A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808010A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010A8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808010AC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808010B0: jal         0x8009BF5C
    // 0x808010B4: nop

    func_8009BF5C(rdram, ctx);
        goto after_4;
    // 0x808010B4: nop

    after_4:
L_808010B8:
    // 0x808010B8: jal         0x8008E35C
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_5;
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808010C0: beq         $v0, $zero, L_808010CC
    if (ctx->r2 == 0) {
        // 0x808010C4: addiu       $t6, $zero, 0xF4
        ctx->r14 = ADD32(0, 0XF4);
            goto L_808010CC;
    }
    // 0x808010C4: addiu       $t6, $zero, 0xF4
    ctx->r14 = ADD32(0, 0XF4);
    // 0x808010C8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808010CC:
    // 0x808010CC: jal         0x8008E078
    // 0x808010D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_6;
    // 0x808010D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808010D4: beq         $v0, $zero, L_808010E4
    if (ctx->r2 == 0) {
        // 0x808010D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010E4;
    }
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010DC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x808010E0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808010E4:
    // 0x808010E4: jal         0x8009E5C8
    // 0x808010E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x808010E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x808010EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808010F8: jr          $ra
    // 0x808010FC: nop

    return;
    // 0x808010FC: nop

;}
RECOMP_FUNC void func_800E9340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9340: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800E9344: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E9348: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800E934C: sll         $v0, $t6, 1
    ctx->r2 = S32(ctx->r14 << 1);
    // 0x800E9350: lui         $t8, 0x1A1
    ctx->r24 = S32(0X1A1 << 16);
    // 0x800E9354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9358: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E935C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800E9360: addiu       $t8, $t8, 0x4580
    ctx->r24 = ADD32(ctx->r24, 0X4580);
    // 0x800E9364: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800E9368: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E936C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800E9370: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x800E9374: jal         0x800E8E70
    // 0x800E9378: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800E8E70(rdram, ctx);
        goto after_0;
    // 0x800E9378: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x800E937C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800E9380: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800E9384: addiu       $t0, $t0, -0x2970
    ctx->r8 = ADD32(ctx->r8, -0X2970);
    // 0x800E9388: addiu       $t9, $v0, 0x4658
    ctx->r25 = ADD32(ctx->r2, 0X4658);
    // 0x800E938C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800E9390: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800E9394: jal         0x8001BBA0
    // 0x800E9398: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x800E9398: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_1:
    // 0x800E939C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E93A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E93A4: jr          $ra
    // 0x800E93A8: nop

    return;
    // 0x800E93A8: nop

;}
