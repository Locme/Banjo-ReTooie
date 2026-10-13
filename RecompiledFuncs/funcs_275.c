#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800090_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: addiu       $a0, $zero, 0x9DA
    ctx->r4 = ADD32(0, 0X9DA);
    // 0x8080009C: jal         0x800DA564
    // 0x808000A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800CB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800CBC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800CC0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800CC4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800CC8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800CCC: jal         0x800BF704
    // 0x80800CD0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80800CD0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800CD4: lbu         $v1, 0x77($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X77);
    // 0x80800CD8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800CDC: bne         $v1, $zero, L_80800CEC
    if (ctx->r3 != 0) {
        // 0x80800CE0: nop
    
            goto L_80800CEC;
    }
    // 0x80800CE0: nop

    // 0x80800CE4: b           L_80800D3C
    // 0x80800CE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80800D3C;
    // 0x80800CE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800CEC:
    // 0x80800CEC: blez        $v1, L_80800D38
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800CF0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80800D38;
    }
    // 0x80800CF0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800CF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800CF8: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
L_80800CFC:
    // 0x80800CFC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800D00: addu        $v0, $t6, $s0
    ctx->r2 = ADD32(ctx->r14, ctx->r16);
    // 0x80800D04: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x80800D08: jal         0x800EFED0
    // 0x80800D0C: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    func_800EFED0(rdram, ctx);
        goto after_1;
    // 0x80800D0C: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    after_1:
    // 0x80800D10: beql        $v0, $zero, L_80800D24
    if (ctx->r2 == 0) {
        // 0x80800D14: lbu         $t7, 0x77($s2)
        ctx->r15 = MEM_BU(ctx->r18, 0X77);
            goto L_80800D24;
    }
    goto skip_0;
    // 0x80800D14: lbu         $t7, 0x77($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X77);
    skip_0:
    // 0x80800D18: b           L_80800D3C
    // 0x80800D1C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80800D3C;
    // 0x80800D1C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800D20: lbu         $t7, 0x77($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X77);
L_80800D24:
    // 0x80800D24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800D28: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80800D2C: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800D30: bnel        $at, $zero, L_80800CFC
    if (ctx->r1 != 0) {
        // 0x80800D34: lw          $t6, 0x68($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X68);
            goto L_80800CFC;
    }
    goto skip_1;
    // 0x80800D34: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    skip_1:
L_80800D38:
    // 0x80800D38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800D3C:
    // 0x80800D3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800D40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800D44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800D48: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D4C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800D50: jr          $ra
    // 0x80800D54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800D54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _dbmorph_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087980: syscall     643
    recomp_syscall_handler(rdram, ctx, 0x80087980);
    return;
    // 0x80087984: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _batimer_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085300: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x80085300);
    return;
    // 0x80085304: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080000C_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800010: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800018: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080001C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800020: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800024: jal         0x80100094
    // 0x80800028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080002C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800030: jal         0x800DA298
    // 0x80800034: addiu       $a0, $zero, 0x36F
    ctx->r4 = ADD32(0, 0X36F);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a0, $zero, 0x36F
    ctx->r4 = ADD32(0, 0X36F);
    after_1:
    // 0x80800038: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x8080003C: nop
    
            goto L_80800068;
    }
    // 0x8080003C: nop

    // 0x80800040: jal         0x80088848
    // 0x80800044: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800044: nop

    after_2:
    // 0x80800048: bne         $v0, $zero, L_80800068
    if (ctx->r2 != 0) {
        // 0x8080004C: nop
    
            goto L_80800068;
    }
    // 0x8080004C: nop

    // 0x80800050: jal         0x800861A8
    // 0x80800054: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800058: jal         0x800FFAB0
    // 0x8080005C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x8080005C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80800060: b           L_80800284
    // 0x80800064: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800284;
    // 0x80800064: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800068:
    // 0x80800068: jal         0x80800BE0
    // 0x8080006C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800BE0_chstatueboss(rdram, ctx);
        goto after_5;
    // 0x8080006C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80800070: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800074: jal         0x80109F08
    // 0x80800078: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    func_80109F08(rdram, ctx);
        goto after_6;
    // 0x80800078: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    after_6:
    // 0x8080007C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80800080: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800084: sh          $zero, 0x8A($v0)
    MEM_H(0X8A, ctx->r2) = 0;
    // 0x80800088: lh          $t6, 0x8A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8A);
    // 0x8080008C: addiu       $s1, $v0, 0x10C
    ctx->r17 = ADD32(ctx->r2, 0X10C);
    // 0x80800090: sh          $t6, 0x88($v0)
    MEM_H(0X88, ctx->r2) = ctx->r14;
L_80800094:
    // 0x80800094: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800098: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080009C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000A0: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x808000A4: addiu       $a2, $s0, 0x32
    ctx->r6 = ADD32(ctx->r16, 0X32);
    // 0x808000A8: jal         0x8008A0C8
    // 0x808000AC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808000AC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_7:
    // 0x808000B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808000B4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x808000B8: bne         $at, $zero, L_80800094
    if (ctx->r1 != 0) {
        // 0x808000BC: addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
            goto L_80800094;
    }
    // 0x808000BC: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x808000C0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808000C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808000C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808000CC: addiu       $a3, $a3, 0xF4
    ctx->r7 = ADD32(ctx->r7, 0XF4);
    // 0x808000D0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x808000D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000D8: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // 0x808000DC: jal         0x8008A0C8
    // 0x808000E0: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x808000E0: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_8:
    // 0x808000E4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808000E8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x808000EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808000F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000F4: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // 0x808000F8: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x808000FC: jal         0x8008A0C8
    // 0x80800100: addiu       $a3, $a3, 0x16C
    ctx->r7 = ADD32(ctx->r7, 0X16C);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800100: addiu       $a3, $a3, 0x16C
    ctx->r7 = ADD32(ctx->r7, 0X16C);
    after_9:
    // 0x80800104: jal         0x800F54E4
    // 0x80800108: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800108: nop

    after_10:
    // 0x8080010C: jal         0x80088848
    // 0x80800110: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_11;
    // 0x80800110: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_11:
    // 0x80800114: beq         $v0, $zero, L_80800150
    if (ctx->r2 == 0) {
        // 0x80800118: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800150;
    }
    // 0x80800118: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080011C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80800120: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800124:
    // 0x80800124: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800128: jal         0x80801640
    // 0x8080012C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801640_chstatueboss(rdram, ctx);
        goto after_12;
    // 0x8080012C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80800130: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800134: bnel        $s0, $s1, L_80800124
    if (ctx->r16 != ctx->r17) {
        // 0x80800138: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800124;
    }
    goto skip_0;
    // 0x80800138: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x8080013C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800140: jal         0x80102424
    // 0x80800144: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x80800144: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_13:
    // 0x80800148: b           L_80800284
    // 0x8080014C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800284;
    // 0x8080014C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800150:
    // 0x80800150: jal         0x800DA298
    // 0x80800154: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80800154: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_14:
    // 0x80800158: bne         $v0, $zero, L_808001D4
    if (ctx->r2 != 0) {
        // 0x8080015C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808001D4;
    }
    // 0x8080015C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800160: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800164: jal         0x800F608C
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_15;
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x8080016C: jal         0x800F497C
    // 0x80800170: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F497C(rdram, ctx);
        goto after_16;
    // 0x80800170: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_16:
    // 0x80800174: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800178: jal         0x800F49A8
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F49A8(rdram, ctx);
        goto after_17;
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800180: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80800184: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x80800188: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080018C: jal         0x800F49D4
    // 0x80800190: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_18;
    // 0x80800190: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    after_18:
    // 0x80800194: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800198: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080019C: jal         0x800F4A58
    // 0x808001A0: lui         $a2, 0x4302
    ctx->r6 = S32(0X4302 << 16);
    func_800F4A58(rdram, ctx);
        goto after_19;
    // 0x808001A0: lui         $a2, 0x4302
    ctx->r6 = S32(0X4302 << 16);
    after_19:
    // 0x808001A4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x808001A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001B0: sb          $v0, 0x1CD($t0)
    MEM_B(0X1CD, ctx->r8) = ctx->r2;
    // 0x808001B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x808001B8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808001BC: jal         0x80085708
    // 0x808001C0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    _capod_entrypoint_13(rdram, ctx);
        goto after_20;
    // 0x808001C0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_20:
    // 0x808001C4: jal         0x800861A8
    // 0x808001C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x808001C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_21:
    // 0x808001CC: b           L_80800284
    // 0x808001D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800284;
    // 0x808001D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808001D4:
    // 0x808001D4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x808001D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808001DC:
    // 0x808001DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001E0: jal         0x80801640
    // 0x808001E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801640_chstatueboss(rdram, ctx);
        goto after_22;
    // 0x808001E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
    // 0x808001E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001EC: bnel        $s0, $s1, L_808001DC
    if (ctx->r16 != ctx->r17) {
        // 0x808001F0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808001DC;
    }
    goto skip_1;
    // 0x808001F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x808001F4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808001F8: jal         0x800F608C
    // 0x808001FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_23;
    // 0x808001FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800200: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800204: jal         0x800F8294
    // 0x80800208: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800F8294(rdram, ctx);
        goto after_24;
    // 0x80800208: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_24:
    // 0x8080020C: jal         0x800F497C
    // 0x80800210: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F497C(rdram, ctx);
        goto after_25;
    // 0x80800210: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_25:
    // 0x80800214: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800218: jal         0x80800DA8
    // 0x8080021C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_26;
    // 0x8080021C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_26:
    // 0x80800220: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80800224: addiu       $t1, $zero, 0xB2
    ctx->r9 = ADD32(0, 0XB2);
    // 0x80800228: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080022C: addiu       $a1, $zero, 0xF41
    ctx->r5 = ADD32(0, 0XF41);
    // 0x80800230: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800234: jal         0x8008A208
    // 0x80800238: addiu       $a3, $s2, 0x4
    ctx->r7 = ADD32(ctx->r18, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_27;
    // 0x80800238: addiu       $a3, $s2, 0x4
    ctx->r7 = ADD32(ctx->r18, 0X4);
    after_27:
    // 0x8080023C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800240: jal         0x80108B04
    // 0x80800244: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80108B04(rdram, ctx);
        goto after_28;
    // 0x80800244: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_28:
    // 0x80800248: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080024C: jal         0x80108B04
    // 0x80800250: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80108B04(rdram, ctx);
        goto after_29;
    // 0x80800250: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_29:
    // 0x80800254: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80800258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800260: sb          $v0, 0x1CC($t2)
    MEM_B(0X1CC, ctx->r10) = ctx->r2;
    // 0x80800264: sb          $v0, 0x1CD($t2)
    MEM_B(0X1CD, ctx->r10) = ctx->r2;
    // 0x80800268: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8080026C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80800270: jal         0x80085708
    // 0x80800274: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    _capod_entrypoint_13(rdram, ctx);
        goto after_30;
    // 0x80800274: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_30:
    // 0x80800278: jal         0x800FDC28
    // 0x8080027C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_31;
    // 0x8080027C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_31:
    // 0x80800280: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800284:
    // 0x80800284: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800288: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8080028C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800290: jr          $ra
    // 0x80800294: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800294: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _gczoombox_entrypoint_38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C10: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087C10);
    return;
    // 0x80087C14: addi        $t0, $zero, 0x98
    ctx->r8 = ADD32(0, 0X98);
;}
RECOMP_FUNC void func_80800540_choctopus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800544: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800548: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8080054C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80800550: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80800554: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80800558: jal         0x80106790
    // 0x8080055C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080055C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800560: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800564: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800568: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x8080056C: jal         0x8008A008
    // 0x80800570: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    _subaddiecustomhits_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800570: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    after_1:
    // 0x80800574: beq         $v0, $zero, L_80800584
    if (ctx->r2 == 0) {
        // 0x80800578: nop
    
            goto L_80800584;
    }
    // 0x80800578: nop

    // 0x8080057C: b           L_80800770
    // 0x80800580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800770;
    // 0x80800580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800584:
    // 0x80800584: jal         0x800CB854
    // 0x80800588: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    func_800CB854(rdram, ctx);
        goto after_2;
    // 0x80800588: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_2:
    // 0x8080058C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800590: beq         $v0, $at, L_808005AC
    if (ctx->r2 == ctx->r1) {
        // 0x80800594: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005AC;
    }
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080059C: beq         $v0, $at, L_808005E4
    if (ctx->r2 == ctx->r1) {
        // 0x808005A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005E4;
    }
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A4: b           L_8080061C
    // 0x808005A8: nop

        goto L_8080061C;
    // 0x808005A8: nop

L_808005AC:
    // 0x808005AC: jal         0x80103F38
    // 0x808005B0: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80103F38(rdram, ctx);
        goto after_3;
    // 0x808005B0: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x808005B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1028, 0X8B8) << 16);
    // 0x808005B8: lwc1        $f6, 0x8B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1028, 0X8B8));
    // 0x808005BC: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x808005C0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x808005C4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808005C8: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x808005CC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808005D0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808005D4: jal         0x800EFFB4
    // 0x808005D8: nop

    func_800EFFB4(rdram, ctx);
        goto after_4;
    // 0x808005D8: nop

    after_4:
    // 0x808005DC: b           L_80800774
    // 0x808005E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80800774;
    // 0x808005E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808005E4:
    // 0x808005E4: jal         0x80103F38
    // 0x808005E8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_80103F38(rdram, ctx);
        goto after_5;
    // 0x808005E8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x808005EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1028, 0X8BC) << 16);
    // 0x808005F0: lwc1        $f18, 0x8BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1028, 0X8BC));
    // 0x808005F4: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x808005F8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x808005FC: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800600: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80800604: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80800608: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080060C: jal         0x800EFFB4
    // 0x80800610: nop

    func_800EFFB4(rdram, ctx);
        goto after_6;
    // 0x80800610: nop

    after_6:
    // 0x80800614: b           L_80800750
    // 0x80800618: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800750;
    // 0x80800618: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080061C:
    // 0x8080061C: jal         0x80103D98
    // 0x80800620: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    func_80103D98(rdram, ctx);
        goto after_7;
    // 0x80800620: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_7:
    // 0x80800624: bne         $v0, $zero, L_80800634
    if (ctx->r2 != 0) {
        // 0x80800628: sw          $v0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r2;
            goto L_80800634;
    }
    // 0x80800628: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8080062C: b           L_80800770
    // 0x80800630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800770;
    // 0x80800630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800634:
    // 0x80800634: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800638: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x8080063C: jal         0x800F1DF4
    // 0x80800640: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    func_800F1DF4(rdram, ctx);
        goto after_8;
    // 0x80800640: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    after_8:
    // 0x80800644: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800648: jal         0x800F1DCC
    // 0x8080064C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_9;
    // 0x8080064C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_9:
    // 0x80800650: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800654: jal         0x800F2100
    // 0x80800658: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    mlAbsF(rdram, ctx);
        goto after_10;
    // 0x80800658: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x8080065C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800660: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800664: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80800668: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080066C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800670: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x80800674: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800678: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8080067C: bc1f        L_80800688
    if (!c1cs) {
        // 0x80800680: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800688;
    }
    // 0x80800680: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800684: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_80800688:
    // 0x80800688: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8080068C: ori         $t6, $v1, 0x2
    ctx->r14 = ctx->r3 | 0X2;
    // 0x80800690: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800694: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80800698: bc1fl       L_808006A8
    if (!c1cs) {
        // 0x8080069C: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_808006A8;
    }
    goto skip_0;
    // 0x8080069C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_0:
    // 0x808006A0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x808006A4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_808006A8:
    // 0x808006A8: ori         $t7, $v1, 0x10
    ctx->r15 = ctx->r3 | 0X10;
    // 0x808006AC: bc1fl       L_808006BC
    if (!c1cs) {
        // 0x808006B0: c.lt.s      $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
            goto L_808006BC;
    }
    goto skip_1;
    // 0x808006B0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    skip_1:
    // 0x808006B4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x808006B8: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
L_808006BC:
    // 0x808006BC: ori         $t8, $v1, 0x4
    ctx->r24 = ctx->r3 | 0X4;
    // 0x808006C0: bc1f        L_808006CC
    if (!c1cs) {
        // 0x808006C4: nop
    
            goto L_808006CC;
    }
    // 0x808006C4: nop

    // 0x808006C8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_808006CC:
    // 0x808006CC: jal         0x800EFC7C
    // 0x808006D0: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    func_800EFC7C(rdram, ctx);
        goto after_11;
    // 0x808006D0: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    after_11:
    // 0x808006D4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808006D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006DC: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808006E0: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E8: mul.s       $f2, $f18, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x808006EC: ori         $t9, $v1, 0x201
    ctx->r25 = ctx->r3 | 0X201;
    // 0x808006F0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x808006F4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808006F8: nop

    // 0x808006FC: bc1f        L_80800708
    if (!c1cs) {
        // 0x80800700: nop
    
            goto L_80800708;
    }
    // 0x80800700: nop

    // 0x80800704: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80800708:
    // 0x80800708: jal         0x801040A8
    // 0x8080070C: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    func_801040A8(rdram, ctx);
        goto after_12;
    // 0x8080070C: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    after_12:
    // 0x80800710: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80800714: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x80800718: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x8080071C: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80800720: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80800724: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80800728: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080072C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800730: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800734: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    // 0x80800738: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8080073C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80800740: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80800744: jal         0x800B1F8C
    // 0x80800748: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    func_800B1F8C(rdram, ctx);
        goto after_13;
    // 0x80800748: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_13:
    // 0x8080074C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800750:
    // 0x80800750: beql        $v0, $zero, L_80800770
    if (ctx->r2 == 0) {
        // 0x80800754: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80800770;
    }
    goto skip_2;
    // 0x80800754: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_2:
    // 0x80800758: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080075C: andi        $t3, $v0, 0x1FF
    ctx->r11 = ctx->r2 & 0X1FF;
    // 0x80800760: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x80800764: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800768: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
    // 0x8080076C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800770:
    // 0x80800770: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800774:
    // 0x80800774: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800778: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8080077C: jr          $ra
    // 0x80800780: nop

    return;
    // 0x80800780: nop

;}
RECOMP_FUNC void func_800E1338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1338: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800E133C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E1340: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E1344: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E1348: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800E134C: jr          $ra
    // 0x800E1350: lwc1        $f0, -0x3048($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3048);
    return;
    // 0x800E1350: lwc1        $f0, -0x3048($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3048);
;}
RECOMP_FUNC void func_800E1788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1788: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E178C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E1790: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800E1794: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800E1798: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800E179C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E17A0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800E17A4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800E17A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E17AC: addiu       $s0, $s0, -0x3070
    ctx->r16 = ADD32(ctx->r16, -0X3070);
    // 0x800E17B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800E17B4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800E17B8: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
L_800E17BC:
    // 0x800E17BC: sb          $s2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r18;
    // 0x800E17C0: swc1        $f20, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f20.u32l;
    // 0x800E17C4: sb          $zero, 0x76($s0)
    MEM_B(0X76, ctx->r16) = 0;
    // 0x800E17C8: jal         0x800EFD24
    // 0x800E17CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800E17CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800E17D0: jal         0x800E1378
    // 0x800E17D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E1378(rdram, ctx);
        goto after_1;
    // 0x800E17D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800E17D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800E17DC: bne         $s1, $s3, L_800E17BC
    if (ctx->r17 != ctx->r19) {
        // 0x800E17E0: addiu       $s0, $s0, 0x7C
        ctx->r16 = ADD32(ctx->r16, 0X7C);
            goto L_800E17BC;
    }
    // 0x800E17E0: addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // 0x800E17E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800E17E8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800E17EC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E17F0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E17F4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800E17F8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800E17FC: jr          $ra
    // 0x800E1800: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800E1800: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bainput_should_wonderwing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800980DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800980E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800980E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800980E8: jal         0x80091A58
    // 0x800980EC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x800980EC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_0:
    // 0x800980F0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800980F4: beq         $t6, $zero, L_8009810C
    if (ctx->r14 == 0) {
        // 0x800980F8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8009810C;
    }
    // 0x800980F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800980FC: jal         0x8008D964
    // 0x80098100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D964(rdram, ctx);
        goto after_1;
    // 0x80098100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80098104: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80098108: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8009810C:
    // 0x8009810C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098114: jr          $ra
    // 0x80098118: nop

    return;
    // 0x80098118: nop

;}
RECOMP_FUNC void func_80800CF0_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800CFC: jal         0x80085808
    // 0x80800D00: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800D00: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_0:
    // 0x80800D04: jal         0x80085818
    // 0x80800D08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800D08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D14: jr          $ra
    // 0x80800D18: nop

    return;
    // 0x80800D18: nop

;}
RECOMP_FUNC void ncpoducam_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080173C: lbu         $v0, 0x60($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X60);
    // 0x80801740: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801744: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801748: beq         $v0, $at, L_80801778
    if (ctx->r2 == ctx->r1) {
        // 0x8080174C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80801778;
    }
    // 0x8080174C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801750: beq         $v0, $at, L_80801778
    if (ctx->r2 == ctx->r1) {
        // 0x80801754: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80801778;
    }
    // 0x80801754: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80801758: bnel        $v0, $at, L_80801794
    if (ctx->r2 != ctx->r1) {
        // 0x8080175C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80801794;
    }
    goto skip_0;
    // 0x8080175C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80801760: jal         0x8001B798
    // 0x80801764: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80801764: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    after_0:
    // 0x80801768: jal         0x80089E68
    // 0x8080176C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _susplinet_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x8080176C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801770: b           L_8080179C
    // 0x80801774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080179C;
    // 0x80801774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801778:
    // 0x80801778: jal         0x8001B798
    // 0x8080177C: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x8080177C: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_2:
    // 0x80801780: jal         0x80089DA8
    // 0x80801784: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suspline_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80801784: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80801788: b           L_8080179C
    // 0x8080178C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080179C;
    // 0x8080178C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801790: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80801794:
    // 0x80801794: nop

    // 0x80801798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080179C:
    // 0x8080179C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808017A0: jr          $ra
    // 0x808017A4: nop

    return;
    // 0x808017A4: nop

;}
RECOMP_FUNC void func_80800B24_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B2C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800B30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800B34: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80800B38: jal         0x800D0A9C
    // 0x80800B3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x80800B3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800B40: beq         $v0, $zero, L_80800B58
    if (ctx->r2 == 0) {
        // 0x80800B44: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800B58;
    }
    // 0x80800B44: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800B48: jal         0x800FFAB0
    // 0x80800B4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800B4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80800B50: b           L_80800B84
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B84;
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B58:
    // 0x80800B58: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    // 0x80800B5C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80800B60: jal         0x800EE7F8
    // 0x80800B64: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800B64: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80800B68: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800B6C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80800B70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B74: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80800B78: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800B7C: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    // 0x80800B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B84:
    // 0x80800B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B88: jr          $ra
    // 0x80800B8C: nop

    return;
    // 0x80800B8C: nop

;}
RECOMP_FUNC void chballoonburst_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1008, 0X1CD0) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x1CD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1008, 0X1CD0));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x1CD0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1008, 0X1CD0));
;}
RECOMP_FUNC void gldialog_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8080000C: xori        $t6, $v0, 0xFD
    ctx->r14 = ctx->r2 ^ 0XFD;
    // 0x80800010: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80800014: beq         $v0, $zero, L_80800028
    if (ctx->r2 == 0) {
        // 0x80800018: nop
    
            goto L_80800028;
    }
    // 0x80800018: nop

    // 0x8080001C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x80800020: xori        $t7, $v0, 0x6A
    ctx->r15 = ctx->r2 ^ 0X6A;
    // 0x80800024: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
L_80800028:
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void gsproplookup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80800004: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2886, 0X40) << 16);
    // 0x80800008: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x8080000C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800010: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800014: jr          $ra
    // 0x80800018: lh          $v0, 0x40($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2886, 0X40));
    return;
    // 0x80800018: lh          $v0, 0x40($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2886, 0X40));
;}
RECOMP_FUNC void func_80800218_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080021C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800224: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800228: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080022C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800230: bnel        $t7, $at, L_80800248
    if (ctx->r15 != ctx->r1) {
        // 0x80800234: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800248;
    }
    goto skip_0;
    // 0x80800234: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800238: lbu         $t9, 0x65($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X65);
    // 0x8080023C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80800240: sb          $t0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r8;
    // 0x80800244: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80800248:
    // 0x80800248: jal         0x80101FDC
    // 0x8080024C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x8080024C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800250: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80800254: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800258: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080025C: bnel        $t1, $at, L_80800274
    if (ctx->r9 != ctx->r1) {
        // 0x80800260: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800274;
    }
    goto skip_1;
    // 0x80800260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800264: lbu         $t2, 0x65($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X65);
    // 0x80800268: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x8080026C: sb          $t3, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r11;
    // 0x80800270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800274:
    // 0x80800274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800278: jr          $ra
    // 0x8080027C: nop

    return;
    // 0x8080027C: nop

;}
RECOMP_FUNC void func_80800850_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800850: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800858: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080085C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800860: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800864: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800868: jal         0x80100094
    // 0x8080086C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080086C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800870: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800874: jal         0x80800734
    // 0x80800878: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800734_chclockworkmouse(rdram, ctx);
        goto after_1;
    // 0x80800878: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080087C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800880: lbu         $t7, 0xFA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XFA);
    // 0x80800884: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80800888: beq         $at, $zero, L_808008CC
    if (ctx->r1 == 0) {
        // 0x8080088C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808008CC;
    }
    // 0x8080088C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800890: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3694) << 16);
    // 0x80800894: addu        $at, $at, $t7
    gpr jr_addend_8080089C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800898: lw          $t7, 0x3694($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3694));
    // 0x8080089C: jr          $t7
    // 0x808008A0: nop

    switch (jr_addend_8080089C >> 2) {
        case 0: goto L_808008A4; break;
        case 1: goto L_808008BC; break;
        case 2: goto L_808008B0; break;
        case 3: goto L_808008B0; break;
        case 4: goto L_808008B0; break;
        default: switch_error(__func__, 0x8080089C, 0x80803694);
    }
    // 0x808008A0: nop

L_808008A4:
    // 0x808008A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008A8: jal         0x80800700
    // 0x808008AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800700_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x808008AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
L_808008B0:
    // 0x808008B0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x808008B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808008B8: sb          $t8, 0xFA($t9)
    MEM_B(0XFA, ctx->r25) = ctx->r24;
L_808008BC:
    // 0x808008BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808008C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808008C4: jal         0x800856D0
    // 0x808008C8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808008C8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
L_808008CC:
    // 0x808008CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008D4: jr          $ra
    // 0x808008D8: nop

    return;
    // 0x808008D8: nop

;}
RECOMP_FUNC void chmumbopad_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E3C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1720, 0X1110) << 16);
    // 0x80800E40: jr          $ra
    // 0x80800E44: addiu       $v0, $v0, 0x1110
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1720, 0X1110));
    return;
    // 0x80800E44: addiu       $v0, $v0, 0x1110
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1720, 0X1110));
    // 0x80800E48: nop

    // 0x80800E4C: nop

;}
RECOMP_FUNC void func_80800808_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800808: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080080C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800810: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800814: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800818: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080081C: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80800820: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800824: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800828: beq         $v0, $zero, L_80800854
    if (ctx->r2 == 0) {
        // 0x8080082C: addiu       $a1, $zero, 0x16
        ctx->r5 = ADD32(0, 0X16);
            goto L_80800854;
    }
    // 0x8080082C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80800830: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800834: beq         $v0, $at, L_8080085C
    if (ctx->r2 == ctx->r1) {
        // 0x80800838: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080085C;
    }
    // 0x80800838: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080083C: beq         $v0, $at, L_80800894
    if (ctx->r2 == ctx->r1) {
        // 0x80800840: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800894;
    }
    // 0x80800840: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800844: beq         $v0, $at, L_8080085C
    if (ctx->r2 == ctx->r1) {
        // 0x80800848: nop
    
            goto L_8080085C;
    }
    // 0x80800848: nop

    // 0x8080084C: b           L_808008A4
    // 0x80800850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008A4;
    // 0x80800850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800854:
    // 0x80800854: jal         0x800856B0
    // 0x80800858: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800858: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_8080085C:
    // 0x8080085C: jal         0x800856E0
    // 0x80800860: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800860: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800864: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800868: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1020, 0X1398) << 16);
    // 0x8080086C: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    // 0x80800870: addiu       $a0, $a0, 0x1398
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1020, 0X1398));
    // 0x80800874: jal         0x80088090
    // 0x80800878: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800878: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8080087C: jal         0x80088098
    // 0x80800880: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800880: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800884: jal         0x800880A0
    // 0x80800888: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800888: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x8080088C: jal         0x800880B8
    // 0x80800890: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800890: nop

    after_5:
L_80800894:
    // 0x80800894: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800898: jal         0x800856D8
    // 0x8080089C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x8080089C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x808008A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008A4:
    // 0x808008A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008AC: jr          $ra
    // 0x808008B0: nop

    return;
    // 0x808008B0: nop

;}
RECOMP_FUNC void func_80805878_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805878: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080587C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80805880: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80805884: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80805888: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080588C: sll         $t8, $t6, 10
    ctx->r24 = S32(ctx->r14 << 10);
    // 0x80805890: bgezl       $t8, L_808058E0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80805894: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808058E0;
    }
    goto skip_0;
    // 0x80805894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80805898: jal         0x80800FBC
    // 0x8080589C: nop

    func_80800FBC_chquiz(rdram, ctx);
        goto after_0;
    // 0x8080589C: nop

    after_0:
    // 0x808058A0: jal         0x808008D4
    // 0x808058A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008D4_chquiz(rdram, ctx);
        goto after_1;
    // 0x808058A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808058A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808058AC: jal         0x80100094
    // 0x808058B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808058B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808058B4: beq         $v0, $zero, L_808058C4
    if (ctx->r2 == 0) {
        // 0x808058B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808058C4;
    }
    // 0x808058B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808058BC: jal         0x800897C8
    // 0x808058C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808058C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808058C4:
    // 0x808058C4: jal         0x8008A840
    // 0x808058C8: nop

    _suquiz_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x808058C8: nop

    after_4:
    // 0x808058CC: bnel        $v0, $zero, L_808058E0
    if (ctx->r2 != 0) {
        // 0x808058D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808058E0;
    }
    goto skip_1;
    // 0x808058D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808058D4: jal         0x8008A7C8
    // 0x808058D8: nop

    _suquiz_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808058D8: nop

    after_5:
    // 0x808058DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808058E0:
    // 0x808058E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808058E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808058E8: jr          $ra
    // 0x808058EC: nop

    return;
    // 0x808058EC: nop

;}
RECOMP_FUNC void func_80802864_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802864: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080286C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802870: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802874: jal         0x80101E14
    // 0x80802878: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x80802878: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x8080287C: beq         $v0, $zero, L_808028D4
    if (ctx->r2 == 0) {
        // 0x80802880: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808028D4;
    }
    // 0x80802880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802884: jal         0x80100094
    // 0x80802888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080288C: lbu         $t6, 0x48($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X48);
    // 0x80802890: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80802894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802898: bne         $t6, $zero, L_808028B0
    if (ctx->r14 != 0) {
        // 0x8080289C: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_808028B0;
    }
    // 0x8080289C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808028A0: jal         0x80089D10
    // 0x808028A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808028A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x808028A8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808028AC: sb          $v0, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r2;
L_808028B0:
    // 0x808028B0: lbu         $a0, 0x48($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X48);
    // 0x808028B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3C84) << 16);
    // 0x808028B8: addiu       $a2, $a2, 0x3C84
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3C84));
    // 0x808028BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x808028C0: jal         0x800C4350
    // 0x808028C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4350(rdram, ctx);
        goto after_3;
    // 0x808028C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808028C8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808028CC: jal         0x800C3BDC
    // 0x808028D0: lbu         $a0, 0x48($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X48);
    func_800C3BDC(rdram, ctx);
        goto after_4;
    // 0x808028D0: lbu         $a0, 0x48($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X48);
    after_4:
L_808028D4:
    // 0x808028D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808028D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808028DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808028E0: jr          $ra
    // 0x808028E4: nop

    return;
    // 0x808028E4: nop

;}
RECOMP_FUNC void chwarppad_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(780, 0X12FC) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x12FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(780, 0X12FC));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x12FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(780, 0X12FC));
;}
RECOMP_FUNC void func_80800188_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080018C: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x80800190: beq         $a1, $at, L_808001BC
    if (ctx->r5 == ctx->r1) {
        // 0x80800194: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808001BC;
    }
    // 0x80800194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800198: addiu       $at, $zero, 0x18B
    ctx->r1 = ADD32(0, 0X18B);
    // 0x8080019C: beq         $a1, $at, L_808001BC
    if (ctx->r5 == ctx->r1) {
        // 0x808001A0: addiu       $at, $zero, 0x18E
        ctx->r1 = ADD32(0, 0X18E);
            goto L_808001BC;
    }
    // 0x808001A0: addiu       $at, $zero, 0x18E
    ctx->r1 = ADD32(0, 0X18E);
    // 0x808001A4: beq         $a1, $at, L_808001BC
    if (ctx->r5 == ctx->r1) {
        // 0x808001A8: addiu       $at, $zero, 0x194
        ctx->r1 = ADD32(0, 0X194);
            goto L_808001BC;
    }
    // 0x808001A8: addiu       $at, $zero, 0x194
    ctx->r1 = ADD32(0, 0X194);
    // 0x808001AC: beq         $a1, $at, L_808001BC
    if (ctx->r5 == ctx->r1) {
        // 0x808001B0: addiu       $at, $zero, 0x196
        ctx->r1 = ADD32(0, 0X196);
            goto L_808001BC;
    }
    // 0x808001B0: addiu       $at, $zero, 0x196
    ctx->r1 = ADD32(0, 0X196);
    // 0x808001B4: bnel        $a1, $at, L_80800248
    if (ctx->r5 != ctx->r1) {
        // 0x808001B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800248;
    }
    goto skip_0;
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_808001BC:
    // 0x808001BC: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x808001C0: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x808001C4: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x808001C8: beq         $at, $zero, L_80800244
    if (ctx->r1 == 0) {
        // 0x808001CC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800244;
    }
    // 0x808001CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808001D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1648, 0X7EC) << 16);
    // 0x808001D4: addu        $at, $at, $t7
    gpr jr_addend_808001DC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808001D8: lw          $t7, 0x7EC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1648, 0X7EC));
    // 0x808001DC: jr          $t7
    // 0x808001E0: nop

    switch (jr_addend_808001DC >> 2) {
        case 0: goto L_80800244; break;
        case 1: goto L_808001E4; break;
        case 2: goto L_80800204; break;
        case 3: goto L_80800214; break;
        case 4: goto L_8080022C; break;
        case 5: goto L_80800244; break;
        default: switch_error(__func__, 0x808001DC, 0x808007EC);
    }
    // 0x808001E0: nop

L_808001E4:
    // 0x808001E4: jal         0x800167F4
    // 0x808001E8: nop

    func_800167F4(rdram, ctx);
        goto after_0;
    // 0x808001E8: nop

    after_0:
    // 0x808001EC: beql        $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x808001F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800248;
    }
    goto skip_1;
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808001F4: jal         0x80085C00
    // 0x808001F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _chattract_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808001F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x808001FC: b           L_80800248
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800248;
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800204:
    // 0x80800204: jal         0x800DA544
    // 0x80800208: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800208: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_2:
    // 0x8080020C: b           L_80800248
    // 0x80800210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800248;
    // 0x80800210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800214:
    // 0x80800214: jal         0x800DA524
    // 0x80800218: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x80800218: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_3:
    // 0x8080021C: jal         0x800DA524
    // 0x80800220: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x80800220: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_4:
    // 0x80800224: b           L_80800248
    // 0x80800228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800248;
    // 0x80800228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080022C:
    // 0x8080022C: jal         0x800DA544
    // 0x80800230: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800230: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_5:
    // 0x80800234: jal         0x800DA524
    // 0x80800238: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA524(rdram, ctx);
        goto after_6;
    // 0x80800238: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_6:
    // 0x8080023C: jal         0x800DA524
    // 0x80800240: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    func_800DA524(rdram, ctx);
        goto after_7;
    // 0x80800240: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_7:
L_80800244:
    // 0x80800244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800248:
    // 0x80800248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080024C: jr          $ra
    // 0x80800250: nop

    return;
    // 0x80800250: nop

;}
RECOMP_FUNC void func_8080217C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080217C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802180: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802184: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80802188: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080218C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80802190: jal         0x8009EF10
    // 0x80802194: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x80802194: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x80802198: blez        $v0, L_808021A4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080219C: nop
    
            goto L_808021A4;
    }
    // 0x8080219C: nop

    // 0x808021A0: addiu       $s0, $zero, 0x108
    ctx->r16 = ADD32(0, 0X108);
L_808021A4:
    // 0x808021A4: jal         0x8008E35C
    // 0x808021A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    player_inWater(rdram, ctx);
        goto after_1;
    // 0x808021A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808021AC: beq         $v0, $zero, L_808021B8
    if (ctx->r2 == 0) {
        // 0x808021B0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808021B8;
    }
    // 0x808021B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808021B4: addiu       $s0, $zero, 0x111
    ctx->r16 = ADD32(0, 0X111);
L_808021B8:
    // 0x808021B8: jal         0x80800218
    // 0x808021BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800218_bstnt(rdram, ctx);
        goto after_2;
    // 0x808021BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808021C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808021C4: jal         0x80800F94
    // 0x808021C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bstnt_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808021C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x808021CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808021D0: jal         0x8009E5C8
    // 0x808021D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x808021D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x808021D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808021DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808021E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808021E4: jr          $ra
    // 0x808021E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808021E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808002B8_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808002BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808002C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808002C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808002C8: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x808002CC: addiu       $s0, $a1, -0x1
    ctx->r16 = ADD32(ctx->r5, -0X1);
    // 0x808002D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808002D4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x808002D8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x808002DC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808002E0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x808002E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808002E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808002EC: jal         0x80100094
    // 0x808002F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002F4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1632, 0X4B94) << 16);
    // 0x808002F8: addiu       $t6, $t6, 0x4B94
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1632, 0X4B94));
    // 0x808002FC: sll         $s6, $s0, 2
    ctx->r22 = S32(ctx->r16 << 2);
    // 0x80800300: addu        $s7, $s6, $t6
    ctx->r23 = ADD32(ctx->r22, ctx->r14);
    // 0x80800304: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800308: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x8080030C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800310: jal         0x80089EB0
    // 0x80800314: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _susplinet_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x80800314: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80800318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800320: jal         0x80100074
    // 0x80800324: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80100074(rdram, ctx);
        goto after_2;
    // 0x80800324: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80800328: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8080032C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800330: lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X0);
    // 0x80800334: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800338: jal         0x80089EB8
    // 0x8080033C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _susplinet_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x8080033C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80800340: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800344: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
L_80800348:
    // 0x80800348: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080034C: jal         0x80089E90
    // 0x80800350: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _susplinet_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80800350: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800354: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800358: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8080035C: blez        $s0, L_80800348
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80800360: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_80800348;
    }
    // 0x80800360: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80800364: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800368: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
L_8080036C:
    // 0x8080036C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800370: jal         0x80089E98
    // 0x80800374: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _susplinet_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x80800374: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800378: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080037C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800380: blez        $s0, L_8080036C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80800384: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_8080036C;
    }
    // 0x80800384: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80800388: jal         0x80089E80
    // 0x8080038C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _susplinet_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x8080038C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x80800390: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800394: jal         0x80089E88
    // 0x80800398: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _susplinet_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80800398: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_7:
    // 0x8080039C: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x808003A0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808003A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808003A8: blez        $t7, L_80800498
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808003AC: lui         $t8, 0x8080
        ctx->r24 = S32(RELOC_HI16(1632, 0X4B84) << 16);
            goto L_80800498;
    }
    // 0x808003AC: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1632, 0X4B84) << 16);
    // 0x808003B0: addiu       $t8, $t8, 0x4B84
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1632, 0X4B84));
    // 0x808003B4: addu        $s2, $s6, $t8
    ctx->r18 = ADD32(ctx->r22, ctx->r24);
    // 0x808003B8: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x808003BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_808003C0:
    // 0x808003C0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x808003C4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x808003C8: jal         0x800EE7F8
    // 0x808003CC: addu        $a1, $t9, $s1
    ctx->r5 = ADD32(ctx->r25, ctx->r17);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x808003CC: addu        $a1, $t9, $s1
    ctx->r5 = ADD32(ctx->r25, ctx->r17);
    after_8:
    // 0x808003D0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x808003D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808003D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003DC: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x808003E0: lh          $t2, 0x10($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X10);
    // 0x808003E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808003E8: sh          $t2, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r10;
    // 0x808003EC: sh          $s6, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r22;
    // 0x808003F0: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x808003F4: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x808003F8: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x808003FC: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80800400: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x80800404: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80800408: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8080040C: lh          $t8, 0x12($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X12);
    // 0x80800410: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80800414: beq         $t9, $zero, L_80800424
    if (ctx->r25 == 0) {
        // 0x80800418: nop
    
            goto L_80800424;
    }
    // 0x80800418: nop

    // 0x8080041C: b           L_80800424
    // 0x80800420: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80800424;
    // 0x80800420: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80800424:
    // 0x80800424: jal         0x80089E20
    // 0x80800428: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _susplinet_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800428: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_9:
    // 0x8080042C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80800430: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800434: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800438: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x8080043C: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x80800440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800444: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80800448: beq         $t3, $zero, L_80800458
    if (ctx->r11 == 0) {
        // 0x8080044C: nop
    
            goto L_80800458;
    }
    // 0x8080044C: nop

    // 0x80800450: b           L_80800458
    // 0x80800454: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80800458;
    // 0x80800454: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80800458:
    // 0x80800458: jal         0x80089E20
    // 0x8080045C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _susplinet_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x8080045C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
    // 0x80800460: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80800464: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80800468: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8080046C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800470: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800474: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80800478: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x8080047C: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x80800480: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x80800484: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80800488: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8080048C: bne         $at, $zero, L_808003C0
    if (ctx->r1 != 0) {
        // 0x80800490: sw          $t5, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r13;
            goto L_808003C0;
    }
    // 0x80800490: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80800494: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800498:
    // 0x80800498: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
L_8080049C:
    // 0x8080049C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004A0: jal         0x80089E90
    // 0x808004A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _susplinet_entrypoint_14(rdram, ctx);
        goto after_11;
    // 0x808004A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x808004A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808004AC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808004B0: blez        $s0, L_8080049C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x808004B4: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_8080049C;
    }
    // 0x808004B4: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x808004B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808004BC: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
    // 0x808004C0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_808004C4:
    // 0x808004C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004C8: jal         0x80089E98
    // 0x808004CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _susplinet_entrypoint_15(rdram, ctx);
        goto after_12;
    // 0x808004CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x808004D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808004D4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808004D8: bne         $s0, $s2, L_808004C4
    if (ctx->r16 != ctx->r18) {
        // 0x808004DC: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_808004C4;
    }
    // 0x808004DC: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x808004E0: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x808004E4: jal         0x800F0EF0
    // 0x808004E8: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    func_800F0EF0(rdram, ctx);
        goto after_13;
    // 0x808004E8: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    after_13:
    // 0x808004EC: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x808004F0: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x808004F4: sb          $zero, 0x8F6($v0)
    MEM_B(0X8F6, ctx->r2) = 0;
    // 0x808004F8: sb          $t7, 0x8F5($v0)
    MEM_B(0X8F5, ctx->r2) = ctx->r15;
    // 0x808004FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800500: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80800504: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80800508: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8080050C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800510: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800514: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800518: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080051C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800520: jr          $ra
    // 0x80800524: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800524: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8008B188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B188: lbu         $t9, 0x1B($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008B18C: sll         $t8, $a1, 7
    ctx->r24 = S32(ctx->r5 << 7);
    // 0x8008B190: andi        $t0, $t9, 0xFF7F
    ctx->r8 = ctx->r25 & 0XFF7F;
    // 0x8008B194: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8008B198: jr          $ra
    // 0x8008B19C: sb          $t1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r9;
    return;
    // 0x8008B19C: sb          $t1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void _glidmake_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088898: syscall     707
    recomp_syscall_handler(rdram, ctx, 0x80088898);
    return;
    // 0x8008889C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808009C4_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808009C8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808009CC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808009D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009D8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808009DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009E0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x808009E4: jal         0x80100094
    // 0x808009E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009EC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x808009F0: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x808009F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808009F8: beq         $a2, $at, L_80800ABC
    if (ctx->r6 == ctx->r1) {
        // 0x808009FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800ABC;
    }
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A00: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80800A04: beq         $a2, $at, L_80800B14
    if (ctx->r6 == ctx->r1) {
        // 0x80800A08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B14;
    }
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A0C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800A10: beq         $a2, $at, L_80800A40
    if (ctx->r6 == ctx->r1) {
        // 0x80800A14: addiu       $v0, $sp, 0x50
        ctx->r2 = ADD32(ctx->r29, 0X50);
            goto L_80800A40;
    }
    // 0x80800A14: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x80800A18: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800A1C: beq         $a2, $at, L_80800A58
    if (ctx->r6 == ctx->r1) {
        // 0x80800A20: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80800A58;
    }
    // 0x80800A20: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80800A24: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800A28: beq         $a2, $at, L_80800B50
    if (ctx->r6 == ctx->r1) {
        // 0x80800A2C: addiu       $at, $zero, 0x57
        ctx->r1 = ADD32(0, 0X57);
            goto L_80800B50;
    }
    // 0x80800A2C: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80800A30: beq         $a2, $at, L_80800B24
    if (ctx->r6 == ctx->r1) {
        // 0x80800A34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B24;
    }
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A38: b           L_80800BA0
    // 0x80800A3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BA0;
    // 0x80800A3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A40:
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800A48: jal         0x80800CC4
    // 0x80800A4C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80800CC4_chprisonbits(rdram, ctx);
        goto after_1;
    // 0x80800A4C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x80800A50: b           L_80800BA0
    // 0x80800A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BA0;
    // 0x80800A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A58:
    // 0x80800A58: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800A5C: bne         $t6, $at, L_80800AB4
    if (ctx->r14 != ctx->r1) {
        // 0x80800A60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AB4;
    }
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: jal         0x80100094
    // 0x80800A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A70: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    // 0x80800A74: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80800A78: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    // 0x80800A7C: jal         0x8008A2D0
    // 0x80800A80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800A80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80800A84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800A88: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80800A8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800A90: addiu       $a1, $zero, 0xF42
    ctx->r5 = ADD32(0, 0XF42);
    // 0x80800A94: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800A98: jal         0x8008A208
    // 0x80800A9C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800A9C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: jal         0x80102424
    // 0x80800AA8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800AA8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_5:
    // 0x80800AAC: b           L_80800BA0
    // 0x80800AB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BA0;
    // 0x80800AB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AB4:
    // 0x80800AB4: b           L_80800BA0
    // 0x80800AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BA0;
    // 0x80800AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800ABC:
    // 0x80800ABC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AC0: jal         0x800897C0
    // 0x80800AC4: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800AC4: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_6:
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ACC: jal         0x80100094
    // 0x80800AD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80800AD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800AD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AD8: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80800ADC: jal         0x800897E8
    // 0x80800AE0: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x80800AE0: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_8:
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE8: jal         0x80100094
    // 0x80800AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800AF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800AF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800AF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AFC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800B00: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800B04: jal         0x800897F8
    // 0x80800B08: nop

    _suexpression_entrypoint_14(rdram, ctx);
        goto after_10;
    // 0x80800B08: nop

    after_10:
    // 0x80800B0C: b           L_80800BA0
    // 0x80800B10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BA0;
    // 0x80800B10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B14:
    // 0x80800B14: jal         0x800897C8
    // 0x80800B18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x80800B18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800B1C: b           L_80800BA0
    // 0x80800B20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BA0;
    // 0x80800B20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B24:
    // 0x80800B24: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80800B28: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80800B2C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800B30: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x80800B34: and         $t9, $a3, $at
    ctx->r25 = ctx->r7 & ctx->r1;
    // 0x80800B38: srl         $a3, $t9, 16
    ctx->r7 = S32(U32(ctx->r25) >> 16);
    // 0x80800B3C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80800B40: jal         0x8008A2B8
    // 0x80800B44: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80800B44: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    after_12:
    // 0x80800B48: b           L_80800BA4
    // 0x80800B4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800BA4;
    // 0x80800B4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B50:
    // 0x80800B50: jal         0x8010CD28
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_13;
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800B58: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800B5C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800B60: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800B64: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800B68: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800B6C: jal         0x800EFA4C
    // 0x80800B70: nop

    func_800EFA4C(rdram, ctx);
        goto after_14;
    // 0x80800B70: nop

    after_14:
    // 0x80800B74: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1932, 0X1098) << 16);
    // 0x80800B78: addiu       $a0, $a0, 0x1098
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1932, 0X1098));
    // 0x80800B7C: jal         0x80088090
    // 0x80800B80: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80800B80: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_15:
    // 0x80800B84: jal         0x800880A0
    // 0x80800B88: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_16;
    // 0x80800B88: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_16:
    // 0x80800B8C: b           L_80800BA0
    // 0x80800B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BA0;
    // 0x80800B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800B94: b           L_80800BA0
    // 0x80800B98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BA0;
    // 0x80800B98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800B9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BA0:
    // 0x80800BA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BA4:
    // 0x80800BA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800BAC: jr          $ra
    // 0x80800BB0: nop

    return;
    // 0x80800BB0: nop

;}
RECOMP_FUNC void func_8080080C_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080080C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800814: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800818: jal         0x80100094
    // 0x8080081C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080081C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800820: beq         $v0, $zero, L_80800830
    if (ctx->r2 == 0) {
        // 0x80800824: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800830;
    }
    // 0x80800824: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800828: jal         0x800897C8
    // 0x8080082C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080082C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800830:
    // 0x80800830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800838: jr          $ra
    // 0x8080083C: nop

    return;
    // 0x8080083C: nop

;}
RECOMP_FUNC void rare_memcpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BBA0: blez        $a2, L_8001BBC0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001BBA4: nop
    
            goto L_8001BBC0;
    }
    // 0x8001BBA4: nop

L_8001BBA8:
    // 0x8001BBA8: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BBAC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001BBB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001BBB4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001BBB8: bgtz        $a2, L_8001BBA8
    if (SIGNED(ctx->r6) > 0) {
        // 0x8001BBBC: sb          $t6, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r14;
            goto L_8001BBA8;
    }
    // 0x8001BBBC: sb          $t6, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r14;
L_8001BBC0:
    // 0x8001BBC0: jr          $ra
    // 0x8001BBC4: nop

    return;
    // 0x8001BBC4: nop

;}
RECOMP_FUNC void badialog_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8080005C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800060: jr          $ra
    // 0x80800064: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80800064: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void _gcfrontend_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088140: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088140);
    return;
    // 0x80088144: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800CD0_chfactorydrums(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800CD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800CD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800CE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CE4: beq         $a1, $at, L_80800D0C
    if (ctx->r5 == ctx->r1) {
        // 0x80800CE8: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80800D0C;
    }
    // 0x80800CE8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800CEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800CF0: beq         $a1, $at, L_80800D44
    if (ctx->r5 == ctx->r1) {
        // 0x80800CF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D44;
    }
    // 0x80800CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800CFC: beq         $a1, $at, L_80800D68
    if (ctx->r5 == ctx->r1) {
        // 0x80800D00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D68;
    }
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D04: b           L_80800D74
    // 0x80800D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800D74;
    // 0x80800D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D0C:
    // 0x80800D0C: jal         0x8010A590
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_0;
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800D14: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800D18: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800D1C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800D20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800D24: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D28: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80800D2C: jal         0x800DC178
    // 0x80800D30: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800D30: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_1:
    // 0x80800D34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800D38: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800D3C: b           L_80800D70
    // 0x80800D40: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_80800D70;
    // 0x80800D40: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80800D44:
    // 0x80800D44: lui         $a1, 0x3EEF
    ctx->r5 = S32(0X3EEF << 16);
    // 0x80800D48: jal         0x80101CDC
    // 0x80800D4C: ori         $a1, $a1, 0x1AA0
    ctx->r5 = ctx->r5 | 0X1AA0;
    func_80101CDC(rdram, ctx);
        goto after_2;
    // 0x80800D4C: ori         $a1, $a1, 0x1AA0
    ctx->r5 = ctx->r5 | 0X1AA0;
    after_2:
    // 0x80800D50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800D54: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800D58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800D5C: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80800D60: b           L_80800D70
    // 0x80800D64: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
        goto L_80800D70;
    // 0x80800D64: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
L_80800D68:
    // 0x80800D68: jal         0x80107070
    // 0x80800D6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_3;
    // 0x80800D6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
L_80800D70:
    // 0x80800D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D74:
    // 0x80800D74: jal         0x80102424
    // 0x80800D78: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800D78: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D88: jr          $ra
    // 0x80800D8C: nop

    return;
    // 0x80800D8C: nop

;}
RECOMP_FUNC void func_808002D0_chlavaarchgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002DC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808002E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002E4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808002E8: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x808002EC: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x808002F0: beq         $at, $zero, L_808005B0
    if (ctx->r1 == 0) {
        // 0x808002F4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808005B0;
    }
    // 0x808002F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808002F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1956, 0X5E4) << 16);
    // 0x808002FC: addu        $at, $at, $t8
    gpr jr_addend_80800304 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800300: lw          $t8, 0x5E4($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1956, 0X5E4));
    // 0x80800304: jr          $t8
    // 0x80800308: nop

    switch (jr_addend_80800304 >> 2) {
        case 0: goto L_8080030C; break;
        case 1: goto L_80800320; break;
        case 2: goto L_808005B0; break;
        case 3: goto L_808003A8; break;
        case 4: goto L_808003BC; break;
        case 5: goto L_808005B0; break;
        case 6: goto L_8080045C; break;
        case 7: goto L_80800470; break;
        case 8: goto L_80800514; break;
        case 9: goto L_8080053C; break;
        default: switch_error(__func__, 0x80800304, 0x808005E4);
    }
    // 0x80800308: nop

L_8080030C:
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x80800288
    // 0x80800314: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800288_chlavaarchgrill(rdram, ctx);
        goto after_0;
    // 0x80800314: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800318: b           L_808005B4
    // 0x8080031C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005B4;
    // 0x8080031C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800320:
    // 0x80800320: jal         0x800D9078
    // 0x80800324: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80800324: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800328: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080032C: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x80800330: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800334: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800338: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080033C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800340: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800344: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800348: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080034C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800350: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800354: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800358: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080035C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800360: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800364: jal         0x800F12D4
    // 0x80800368: nop

    func_800F12D4(rdram, ctx);
        goto after_2;
    // 0x80800368: nop

    after_2:
    // 0x8080036C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1956, 0X688) << 16);
    // 0x80800370: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80800374: addiu       $a3, $a3, 0x688
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1956, 0X688));
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800380: jal         0x80089D50
    // 0x80800384: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800384: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800388: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: beql        $t9, $zero, L_808005B4
    if (ctx->r25 == 0) {
        // 0x80800394: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808005B4;
    }
    goto skip_0;
    // 0x80800394: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800398: jal         0x80101FDC
    // 0x8080039C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x8080039C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x808003A0: b           L_808005B4
    // 0x808003A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005B4;
    // 0x808003A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003A8:
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x80800288
    // 0x808003B0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800288_chlavaarchgrill(rdram, ctx);
        goto after_5;
    // 0x808003B0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x808003B4: b           L_808005B4
    // 0x808003B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005B4;
    // 0x808003B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003BC:
    // 0x808003BC: jal         0x800D9078
    // 0x808003C0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x808003C0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x808003C4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808003C8: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x808003CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003D0: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808003D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808003D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003DC: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808003E0: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808003E4: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003EC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x808003F0: div.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x808003F4: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x808003F8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x808003FC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800400: jal         0x800F12D4
    // 0x80800404: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F12D4(rdram, ctx);
        goto after_7;
    // 0x80800404: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x80800408: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8080040C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800410: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1956, 0X688) << 16);
    // 0x80800414: addiu       $a3, $a3, 0x688
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1956, 0X688));
    // 0x80800418: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x80089D50
    // 0x80800424: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800424: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80800428: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: beql        $t0, $zero, L_808005B4
    if (ctx->r8 == 0) {
        // 0x80800434: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808005B4;
    }
    goto skip_1;
    // 0x80800434: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800438: jal         0x80101FDC
    // 0x8080043C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x8080043C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_9:
    // 0x80800440: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1956, 0X698) << 16);
    // 0x80800444: addiu       $a2, $a2, 0x698
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1956, 0X698));
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: jal         0x80089D18
    // 0x80800450: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800450: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80800454: b           L_808005B4
    // 0x80800458: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005B4;
    // 0x80800458: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080045C:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: jal         0x80800288
    // 0x80800464: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800288_chlavaarchgrill(rdram, ctx);
        goto after_11;
    // 0x80800464: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_11:
    // 0x80800468: b           L_808005B4
    // 0x8080046C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005B4;
    // 0x8080046C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800470:
    // 0x80800470: jal         0x800D9078
    // 0x80800474: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_12;
    // 0x80800474: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_12:
    // 0x80800478: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080047C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800480: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800484: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x80800488: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080048C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800490: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800494: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800498: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080049C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808004A0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808004A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808004A8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808004AC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808004B0: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808004B4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808004B8: jal         0x800F12D4
    // 0x808004BC: nop

    func_800F12D4(rdram, ctx);
        goto after_13;
    // 0x808004BC: nop

    after_13:
    // 0x808004C0: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x808004C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808004C8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1956, 0X688) << 16);
    // 0x808004CC: addiu       $a3, $a3, 0x688
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1956, 0X688));
    // 0x808004D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: jal         0x80089D50
    // 0x808004DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x808004DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x808004E0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: beql        $t1, $zero, L_808005B4
    if (ctx->r9 == 0) {
        // 0x808004EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808005B4;
    }
    goto skip_2;
    // 0x808004EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808004F0: jal         0x80101FDC
    // 0x808004F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x808004F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808004F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1956, 0X698) << 16);
    // 0x808004FC: addiu       $a2, $a2, 0x698
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1956, 0X698));
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: jal         0x80089D18
    // 0x80800508: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x80800508: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x8080050C: b           L_808005B4
    // 0x80800510: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808005B4;
    // 0x80800510: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800514:
    // 0x80800514: jal         0x800D9078
    // 0x80800518: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D9078(rdram, ctx);
        goto after_17;
    // 0x80800518: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_17:
    // 0x8080051C: beq         $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x80800520: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005B0;
    }
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: jal         0x80101FDC
    // 0x80800528: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80101FDC(rdram, ctx);
        goto after_18;
    // 0x80800528: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_18:
    // 0x8080052C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800530: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800534: b           L_808005B0
    // 0x80800538: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808005B0;
    // 0x80800538: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_8080053C:
    // 0x8080053C: jal         0x800D9078
    // 0x80800540: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_19;
    // 0x80800540: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_19:
    // 0x80800544: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800548: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x8080054C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800550: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800554: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800558: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080055C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800560: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800564: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800568: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8080056C: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800570: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800574: jal         0x800F12D4
    // 0x80800578: nop

    func_800F12D4(rdram, ctx);
        goto after_20;
    // 0x80800578: nop

    after_20:
    // 0x8080057C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1956, 0X688) << 16);
    // 0x80800580: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80800584: addiu       $a3, $a3, 0x688
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1956, 0X688));
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080058C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800590: jal         0x80089D50
    // 0x80800594: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80800594: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_21:
    // 0x80800598: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: beql        $t2, $zero, L_808005B4
    if (ctx->r10 == 0) {
        // 0x808005A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808005B4;
    }
    goto skip_3;
    // 0x808005A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x808005A8: jal         0x80101FDC
    // 0x808005AC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80101FDC(rdram, ctx);
        goto after_22;
    // 0x808005AC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_22:
L_808005B0:
    // 0x808005B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005B4:
    // 0x808005B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808005BC: jr          $ra
    // 0x808005C0: nop

    return;
    // 0x808005C0: nop

;}
RECOMP_FUNC void func_808004BC_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004D0: beq         $a1, $at, L_808004F8
    if (ctx->r5 == ctx->r1) {
        // 0x808004D4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_808004F8;
    }
    // 0x808004D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808004D8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808004DC: beq         $a1, $at, L_80800518
    if (ctx->r5 == ctx->r1) {
        // 0x808004E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800518;
    }
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808004E8: beq         $a1, $at, L_80800548
    if (ctx->r5 == ctx->r1) {
        // 0x808004EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800548;
    }
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: b           L_80800590
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800590;
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004F8:
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x80102424
    // 0x80800500: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800500: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800508: jal         0x80800830
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800830_chtntmineshoot(rdram, ctx);
        goto after_1;
    // 0x8080050C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800510: b           L_8080059C
    // 0x80800514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080059C;
    // 0x80800514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800518:
    // 0x80800518: jal         0x80102424
    // 0x8080051C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x8080051C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: jal         0x80800830
    // 0x80800528: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800830_chtntmineshoot(rdram, ctx);
        goto after_3;
    // 0x80800528: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8080052C: jal         0x8010A570
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: jal         0x80800440
    // 0x8080053C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800440_chtntmineshoot(rdram, ctx);
        goto after_5;
    // 0x8080053C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800540: b           L_8080059C
    // 0x80800544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080059C;
    // 0x80800544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800548:
    // 0x80800548: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080054C: jal         0x80102424
    // 0x80800550: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800550: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_6:
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800558: jal         0x80800830
    // 0x8080055C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800830_chtntmineshoot(rdram, ctx);
        goto after_7;
    // 0x8080055C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800560: jal         0x8010A570
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_8;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: jal         0x80800440
    // 0x80800570: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800440_chtntmineshoot(rdram, ctx);
        goto after_9;
    // 0x80800570: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800574: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800578: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x8080057C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800580: jal         0x800187B4
    // 0x80800584: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    func_800187B4(rdram, ctx);
        goto after_10;
    // 0x80800584: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_10:
    // 0x80800588: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800590:
    // 0x80800590: jal         0x80102424
    // 0x80800594: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800594: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_11:
    // 0x80800598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080059C:
    // 0x8080059C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005A4: jr          $ra
    // 0x808005A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808005A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_808003C0_chtntdetonator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003CC: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x808003D0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(904, 0X754) << 16);
    // 0x808003D4: addiu       $t7, $t7, 0x754
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(904, 0X754));
    // 0x808003D8: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x808003DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808003E0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808003E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003E8: jal         0x800BBCB8
    // 0x808003EC: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x808003EC: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_0:
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003F8: jr          $ra
    // 0x808003FC: nop

    return;
    // 0x808003FC: nop

;}
RECOMP_FUNC void func_80806E9C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806EA4: jal         0x800827D0
    // 0x80806EA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80806EA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80806EAC: jal         0x80807C8C
    // 0x80806EB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80806EB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80806EB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806EB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806EBC: jr          $ra
    // 0x80806EC0: nop

    return;
    // 0x80806EC0: nop

;}
RECOMP_FUNC void func_80800BCC_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BCC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800BD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800BD4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800BD8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800BDC: jal         0x80101080
    // 0x80800BE0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800BE0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800BE4: jal         0x80106790
    // 0x80800BE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800BE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800BEC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800BF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BF8: jal         0x800866A0
    // 0x80800BFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800BFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800C08: jal         0x800866A0
    // 0x80800C0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800C0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800C18: jal         0x800866A0
    // 0x80800C1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800C1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800C28: jal         0x800866A0
    // 0x80800C2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800C2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80800C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C34: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800C38: jal         0x800866A0
    // 0x80800C3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80800C3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800C40: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1024, 0XF9C) << 16);
    // 0x80800C44: addiu       $a1, $a1, 0xF9C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1024, 0XF9C));
    // 0x80800C48: jal         0x800866A8
    // 0x80800C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x80800C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C54: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800C58: jal         0x80086688
    // 0x80800C5C: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x80800C5C: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_8:
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C64: jal         0x800866C8
    // 0x80800C68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _chexploder_entrypoint_14(rdram, ctx);
        goto after_9;
    // 0x80800C68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800C6C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x80800C70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800C74: jal         0x80103DFC
    // 0x80800C78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80103DFC(rdram, ctx);
        goto after_10;
    // 0x80800C78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800C7C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1024, 0XF5C) << 16);
    // 0x80800C80: addiu       $t6, $t6, 0xF5C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1024, 0XF5C));
    // 0x80800C84: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    // 0x80800C88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800C94: jal         0x800BBCB8
    // 0x80800C98: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_11;
    // 0x80800C98: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_11:
    // 0x80800C9C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1024, 0XF90) << 16);
    // 0x80800CA0: addiu       $a2, $a2, 0xF90
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1024, 0XF90));
    // 0x80800CA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CA8: jal         0x80089D18
    // 0x80800CAC: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800CAC: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_12:
    // 0x80800CB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CB4: jal         0x80107070
    // 0x80800CB8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_13;
    // 0x80800CB8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x80800CBC: bnel        $v0, $zero, L_80800CD0
    if (ctx->r2 != 0) {
        // 0x80800CC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800CD0;
    }
    goto skip_0;
    // 0x80800CC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800CC4: jal         0x800FFAB0
    // 0x80800CC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x80800CC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800CCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CD0:
    // 0x80800CD0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CD4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800CD8: jr          $ra
    // 0x80800CDC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800CDC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void anseq_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(26, 0X490) << 16);
    // 0x80800380: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800384: jr          $ra
    // 0x80800388: sw          $a1, 0x490($at)
    MEM_W((int16_t)RELOC_LO16(26, 0X490), ctx->r1) = ctx->r5;
    return;
    // 0x80800388: sw          $a1, 0x490($at)
    MEM_W((int16_t)RELOC_LO16(26, 0X490), ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_8080004C_bawobble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: beq         $a1, $at, L_8080009C
    if (ctx->r5 == ctx->r1) {
        // 0x8080005C: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8080009C;
    }
    // 0x8080005C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800060: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80800064: bnel        $a1, $v1, L_808000A0
    if (ctx->r5 != ctx->r3) {
        // 0x80800068: lw          $t7, 0x154($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X154);
            goto L_808000A0;
    }
    goto skip_0;
    // 0x80800068: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
    skip_0:
    // 0x8080006C: lw          $v0, 0x154($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X154);
    // 0x80800070: lbu         $t6, 0xC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC);
    // 0x80800074: beql        $v1, $t6, L_808000A8
    if (ctx->r3 == ctx->r14) {
        // 0x80800078: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000A8;
    }
    goto skip_1;
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8080007C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800080: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800084: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80800088: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8080008C: jal         0x80800008
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800008_bawobble(rdram, ctx);
        goto after_0;
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800098: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_8080009C:
    // 0x8080009C: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
L_808000A0:
    // 0x808000A0: sb          $a2, 0xC($t7)
    MEM_B(0XC, ctx->r15) = ctx->r6;
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000A8:
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void _sueggmove_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A478: syscall     842
    recomp_syscall_handler(rdram, ctx, 0x8008A478);
    return;
    // 0x8008A47C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _chdoormake_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868D0: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x800868D0);
    return;
    // 0x800868D4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void bashoes_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800554: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800558: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x8080055C: jr          $ra
    // 0x80800560: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800560: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_808000F8_fxegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800100: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800104: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800108: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080010C: jal         0x800BA3FC
    // 0x80800110: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800BA3FC(rdram, ctx);
        goto after_0;
    // 0x80800110: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800114: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2834, 0X5B0) << 16);
    // 0x80800118: addiu       $t6, $t6, 0x5B0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2834, 0X5B0));
    // 0x8080011C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800120: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800124: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800128: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080012C: jal         0x800BABB8
    // 0x80800130: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800130: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void func_808004A8_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004B4: jal         0x800A8264
    // 0x808004B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A8264(rdram, ctx);
        goto after_0;
    // 0x808004B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808004BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004C0: bne         $v0, $zero, L_80800520
    if (ctx->r2 != 0) {
        // 0x808004C4: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80800520;
    }
    // 0x808004C4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x808004C8: bltz        $a3, L_80800518
    if (SIGNED(ctx->r7) < 0) {
        // 0x808004CC: nop
    
            goto L_80800518;
    }
    // 0x808004CC: nop

    // 0x808004D0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808004D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004DC: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808004E0: bgez        $t8, L_80800508
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808004E4: nop
    
            goto L_80800508;
    }
    // 0x808004E4: nop

    // 0x808004E8: jal         0x80088818
    // 0x808004EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _glcutDll_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x808004EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x808004F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808004F4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808004F8: jal         0x80088868
    // 0x808004FC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_2;
    // 0x808004FC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_2:
    // 0x80800500: b           L_80800524
    // 0x80800504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800524;
    // 0x80800504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800508:
    // 0x80800508: jal         0x800A7990
    // 0x8080050C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A7990(rdram, ctx);
        goto after_3;
    // 0x8080050C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800510: b           L_80800524
    // 0x80800514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800524;
    // 0x80800514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800518:
    // 0x80800518: jal         0x808003C4
    // 0x8080051C: nop

    func_808003C4_chintroticker(rdram, ctx);
        goto after_4;
    // 0x8080051C: nop

    after_4:
L_80800520:
    // 0x80800520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800524:
    // 0x80800524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800528: jr          $ra
    // 0x8080052C: nop

    return;
    // 0x8080052C: nop

;}
RECOMP_FUNC void bawobble_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000C4: sb          $zero, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = 0;
    // 0x808000C8: jal         0x80800008
    // 0x808000CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800008_bawobble(rdram, ctx);
        goto after_0;
    // 0x808000CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000D4: jal         0x8080004C
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080004C_bawobble(rdram, ctx);
        goto after_1;
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000EC: jal         0x80800158
    // 0x808000F0: nop

    bawobble_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808000F0: nop

    after_2:
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void _subaddierouteDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F70: syscall     818
    recomp_syscall_handler(rdram, ctx, 0x80089F70);
    return;
    // 0x80089F74: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8009C08C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C08C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C094: jal         0x8009C21C
    // 0x8009C098: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009C21C(rdram, ctx);
        goto after_0;
    // 0x8009C098: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009C09C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8009C0A0: lw          $a0, 0xE4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XE4);
    // 0x8009C0A4: jal         0x800EFD24
    // 0x8009C0A8: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8009C0A8: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_1:
    // 0x8009C0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C0B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C0B4: jr          $ra
    // 0x8009C0B8: nop

    return;
    // 0x8009C0B8: nop

;}
RECOMP_FUNC void func_800AF5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF5A8: jr          $ra
    // 0x800AF5AC: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    return;
    // 0x800AF5AC: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
;}
