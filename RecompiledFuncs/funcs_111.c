#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _gcmapDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088108: syscall     672
    recomp_syscall_handler(rdram, ctx, 0x80088108);
    return;
    // 0x8008810C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void ncbapan_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: jr          $ra
    // 0x8080010C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080010C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800F26B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F26B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F26B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F26B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800F26BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800F26C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800F26C4: jal         0x800F274C
    // 0x800F26C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F274C(rdram, ctx);
        goto after_0;
    // 0x800F26C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F26CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800F26D0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F26D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F26D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800F26DC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800F26E0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F26E4: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x800F26E8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F26EC: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x800F26F0: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x800F26F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F26F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F26FC: jr          $ra
    // 0x800F2700: nop

    return;
    // 0x800F2700: nop

;}
RECOMP_FUNC void func_80800A18_bstaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A20: sltiu       $at, $a1, 0x5
    ctx->r1 = ctx->r5 < 0X5 ? 1 : 0;
    // 0x80800A24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A2C: beq         $at, $zero, L_80800AE8
    if (ctx->r1 == 0) {
        // 0x80800A30: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80800AE8;
    }
    // 0x80800A30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800A34: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800A38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1F0C) << 16);
    // 0x80800A3C: addu        $at, $at, $t6
    gpr jr_addend_80800A44 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800A40: lw          $t6, 0x1F0C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(392, 0X1F0C));
    // 0x80800A44: jr          $t6
    // 0x80800A48: nop

    switch (jr_addend_80800A44 >> 2) {
        case 0: goto L_80800A4C; break;
        case 1: goto L_80800A70; break;
        case 2: goto L_80800AA0; break;
        case 3: goto L_80800AB8; break;
        case 4: goto L_80800AD4; break;
        default: switch_error(__func__, 0x80800A44, 0x80801F0C);
    }
    // 0x80800A48: nop

L_80800A4C:
    // 0x80800A4C: lbu         $t7, 0x15C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15C);
    // 0x80800A50: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A58: bnel        $t7, $at, L_80800AEC
    if (ctx->r15 != ctx->r1) {
        // 0x80800A5C: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80800AEC;
    }
    goto skip_0;
    // 0x80800A5C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800A60: jal         0x80084788
    // 0x80800A64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800A64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800A68: b           L_80800AEC
    // 0x80800A6C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_80800AEC;
    // 0x80800A6C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800A70:
    // 0x80800A70: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80800A74: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
    // 0x80800A78: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A80: jal         0x8008CCBC
    // 0x80800A84: addiu       $a1, $zero, 0x121
    ctx->r5 = ADD32(0, 0X121);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80800A84: addiu       $a1, $zero, 0x121
    ctx->r5 = ADD32(0, 0X121);
    after_1:
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A90: jal         0x80098140
    // 0x80800A94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_2;
    // 0x80800A94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800A98: b           L_80800AEC
    // 0x80800A9C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_80800AEC;
    // 0x80800A9C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800AA0:
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: addiu       $a1, $zero, 0x12B
    ctx->r5 = ADD32(0, 0X12B);
    // 0x80800AA8: jal         0x8008CB3C
    // 0x80800AAC: lui         $a2, 0x4090
    ctx->r6 = S32(0X4090 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_3;
    // 0x80800AAC: lui         $a2, 0x4090
    ctx->r6 = S32(0X4090 << 16);
    after_3:
    // 0x80800AB0: b           L_80800AEC
    // 0x80800AB4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_80800AEC;
    // 0x80800AB4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800AB8:
    // 0x80800AB8: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800ABC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC4: jal         0x8008CCBC
    // 0x80800AC8: addiu       $a1, $zero, 0x12D
    ctx->r5 = ADD32(0, 0X12D);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_4;
    // 0x80800AC8: addiu       $a1, $zero, 0x12D
    ctx->r5 = ADD32(0, 0X12D);
    after_4:
    // 0x80800ACC: b           L_80800AEC
    // 0x80800AD0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_80800AEC;
    // 0x80800AD0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800AD4:
    // 0x80800AD4: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800AD8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE0: jal         0x8008CCBC
    // 0x80800AE4: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_5;
    // 0x80800AE4: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_5:
L_80800AE8:
    // 0x80800AE8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800AEC:
    // 0x80800AEC: sb          $t8, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r24;
    // 0x80800AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AFC: jr          $ra
    // 0x80800B00: nop

    return;
    // 0x80800B00: nop

;}
RECOMP_FUNC void func_808014F8_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801500: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801504: jal         0x80085298
    // 0x80801508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baswim_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80801508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080150C: jal         0x80800104
    // 0x80801510: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800104_bsbswim(rdram, ctx);
        goto after_1;
    // 0x80801510: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080151C: jr          $ra
    // 0x80801520: nop

    return;
    // 0x80801520: nop

;}
RECOMP_FUNC void _glglobaldata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885C0: syscall     694
    recomp_syscall_handler(rdram, ctx, 0x800885C0);
    return;
    // 0x800885C4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bstntswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FD8: syscall     100
    recomp_syscall_handler(rdram, ctx, 0x80083FD8);
    return;
    // 0x80083FDC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void dbzone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: beq         $a2, $zero, L_80800100
    if (ctx->r6 == 0) {
        // 0x80800004: andi        $a3, $a2, 0x3
        ctx->r7 = ctx->r6 & 0X3;
            goto L_80800100;
    }
    // 0x80800004: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x80800008: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x8080000C: beq         $a3, $zero, L_80800050
    if (ctx->r7 == 0) {
        // 0x80800010: addu        $v1, $a3, $a2
        ctx->r3 = ADD32(ctx->r7, ctx->r6);
            goto L_80800050;
    }
    // 0x80800010: addu        $v1, $a3, $a2
    ctx->r3 = ADD32(ctx->r7, ctx->r6);
    // 0x80800014: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x80800018: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
L_8080001C:
    // 0x8080001C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80800020: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80800024: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800028: mflo        $t7
    ctx->r15 = lo;
    // 0x8080002C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80800030: lbu         $t9, 0xC($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XC);
    // 0x80800034: beq         $t9, $zero, L_80800044
    if (ctx->r25 == 0) {
        // 0x80800038: nop
    
            goto L_80800044;
    }
    // 0x80800038: nop

    // 0x8080003C: jr          $ra
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: bne         $v1, $a2, L_8080001C
    if (ctx->r3 != ctx->r6) {
        // 0x80800048: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8080001C;
    }
    // 0x80800048: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8080004C: beq         $a2, $zero, L_80800100
    if (ctx->r6 == 0) {
        // 0x80800050: addiu       $a3, $zero, 0xE
        ctx->r7 = ADD32(0, 0XE);
            goto L_80800100;
    }
L_80800050:
    // 0x80800050: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80800054: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
L_80800058:
    // 0x80800058: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x8080005C: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80800060: multu       $t0, $a3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800064: mflo        $t1
    ctx->r9 = lo;
    // 0x80800068: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8080006C: lbu         $t3, 0xC($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XC);
    // 0x80800070: beql        $t3, $zero, L_80800084
    if (ctx->r11 == 0) {
        // 0x80800074: lbu         $t4, 0x1($a1)
        ctx->r12 = MEM_BU(ctx->r5, 0X1);
            goto L_80800084;
    }
    goto skip_0;
    // 0x80800074: lbu         $t4, 0x1($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1);
    skip_0:
    // 0x80800078: jr          $ra
    // 0x8080007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8080007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800080: lbu         $t4, 0x1($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1);
L_80800084:
    // 0x80800084: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800088: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080008C: mflo        $t5
    ctx->r13 = lo;
    // 0x80800090: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80800094: lbu         $t7, 0xC($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XC);
    // 0x80800098: beql        $t7, $zero, L_808000AC
    if (ctx->r15 == 0) {
        // 0x8080009C: lbu         $t8, 0x1($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X1);
            goto L_808000AC;
    }
    goto skip_1;
    // 0x8080009C: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    skip_1:
    // 0x808000A0: jr          $ra
    // 0x808000A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808000A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000A8: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
L_808000AC:
    // 0x808000AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x808000B0: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000B4: mflo        $t9
    ctx->r25 = lo;
    // 0x808000B8: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x808000BC: lbu         $t1, 0xC($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XC);
    // 0x808000C0: beql        $t1, $zero, L_808000D4
    if (ctx->r9 == 0) {
        // 0x808000C4: lbu         $t2, 0x1($a1)
        ctx->r10 = MEM_BU(ctx->r5, 0X1);
            goto L_808000D4;
    }
    goto skip_2;
    // 0x808000C4: lbu         $t2, 0x1($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1);
    skip_2:
    // 0x808000C8: jr          $ra
    // 0x808000CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808000CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000D0: lbu         $t2, 0x1($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1);
L_808000D4:
    // 0x808000D4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x808000D8: multu       $t2, $a3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000DC: mflo        $t3
    ctx->r11 = lo;
    // 0x808000E0: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x808000E4: lbu         $t5, 0xC($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XC);
    // 0x808000E8: beq         $t5, $zero, L_808000F8
    if (ctx->r13 == 0) {
        // 0x808000EC: nop
    
            goto L_808000F8;
    }
    // 0x808000EC: nop

    // 0x808000F0: jr          $ra
    // 0x808000F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808000F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000F8:
    // 0x808000F8: bne         $a2, $zero, L_80800058
    if (ctx->r6 != 0) {
        // 0x808000FC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80800058;
    }
    // 0x808000FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80800100:
    // 0x80800100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_80800BA4_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BA8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800BAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BB0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800BB4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800BB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800BBC: beq         $a1, $at, L_80800CC4
    if (ctx->r5 == ctx->r1) {
        // 0x80800BC0: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800CC4;
    }
    // 0x80800BC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800BC4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800BC8: beq         $a1, $at, L_80800C6C
    if (ctx->r5 == ctx->r1) {
        // 0x80800BCC: lui         $s0, 0x8080
        ctx->r16 = S32(RELOC_HI16(1528, 0XF4C) << 16);
            goto L_80800C6C;
    }
    // 0x80800BCC: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1528, 0XF4C) << 16);
    // 0x80800BD0: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800BD4: beq         $a1, $at, L_80800C1C
    if (ctx->r5 == ctx->r1) {
        // 0x80800BD8: lw          $s1, 0x28($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X28);
            goto L_80800C1C;
    }
    // 0x80800BD8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800BDC: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800BE0: bne         $a1, $at, L_80800CEC
    if (ctx->r5 != ctx->r1) {
        // 0x80800BE4: nop
    
            goto L_80800CEC;
    }
    // 0x80800BE4: nop

    // 0x80800BE8: jal         0x80101080
    // 0x80800BEC: nop

    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800BEC: nop

    after_0:
    // 0x80800BF0: jal         0x80106790
    // 0x80800BF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800BF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800BF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800BFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C04: jal         0x800866A0
    // 0x80800C08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800C08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80800C0C: jal         0x80089CA8
    // 0x80800C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800C14: b           L_80800CF8
    // 0x80800C18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CF8;
    // 0x80800C18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C1C:
    // 0x80800C1C: jal         0x80800D0C
    // 0x80800C20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800D0C_chfireicestorm(rdram, ctx);
        goto after_4;
    // 0x80800C20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800C24: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x80800C28: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80800C2C: bnel        $t7, $zero, L_80800CF8
    if (ctx->r15 != 0) {
        // 0x80800C30: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800CF8;
    }
    goto skip_0;
    // 0x80800C30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800C34: lhu         $s0, 0x1A($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X1A);
    // 0x80800C38: srl         $a0, $s0, 5
    ctx->r4 = S32(U32(ctx->r16) >> 5);
    // 0x80800C3C: jal         0x800F6438
    // 0x80800C40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F6438(rdram, ctx);
        goto after_5;
    // 0x80800C40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_5:
    // 0x80800C44: beql        $v0, $zero, L_80800CF8
    if (ctx->r2 == 0) {
        // 0x80800C48: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800CF8;
    }
    goto skip_1;
    // 0x80800C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800C4C: jal         0x800F6478
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6478(rdram, ctx);
        goto after_6;
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800C54: beq         $v0, $zero, L_80800CF4
    if (ctx->r2 == 0) {
        // 0x80800C58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CF4;
    }
    // 0x80800C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C5C: jal         0x800F7B9C
    // 0x80800C60: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800F7B9C(rdram, ctx);
        goto after_7;
    // 0x80800C60: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_7:
    // 0x80800C64: b           L_80800CF8
    // 0x80800C68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CF8;
    // 0x80800C68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C6C:
    // 0x80800C6C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1528, 0XF54) << 16);
    // 0x80800C70: addiu       $s1, $s1, 0xF54
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1528, 0XF54));
    // 0x80800C74: addiu       $s0, $s0, 0xF4C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1528, 0XF4C));
L_80800C78:
    // 0x80800C78: jal         0x80085728
    // 0x80800C7C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_17(rdram, ctx);
        goto after_8;
    // 0x80800C7C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x80800C80: beq         $v0, $zero, L_80800CB4
    if (ctx->r2 == 0) {
        // 0x80800C84: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800CB4;
    }
    // 0x80800C84: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800C88: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800C8C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1528, 0XF54) << 16);
    // 0x80800C90: addiu       $a3, $a3, 0xF54
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1528, 0XF54));
    // 0x80800C94: lw          $a1, 0x70($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X70);
    // 0x80800C98: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800C9C: addiu       $a2, $t9, 0x4
    ctx->r6 = ADD32(ctx->r25, 0X4);
    // 0x80800CA0: andi        $t0, $a1, 0x1
    ctx->r8 = ctx->r5 & 0X1;
    // 0x80800CA4: jal         0x8010D930
    // 0x80800CA8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_8010D930(rdram, ctx);
        goto after_9;
    // 0x80800CA8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_9:
    // 0x80800CAC: b           L_80800CF8
    // 0x80800CB0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800CF8;
    // 0x80800CB0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800CB4:
    // 0x80800CB4: bne         $s0, $s1, L_80800C78
    if (ctx->r16 != ctx->r17) {
        // 0x80800CB8: nop
    
            goto L_80800C78;
    }
    // 0x80800CB8: nop

    // 0x80800CBC: b           L_80800CF8
    // 0x80800CC0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800CF8;
    // 0x80800CC0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800CC4:
    // 0x80800CC4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80800CC8: jal         0x80106790
    // 0x80800CCC: lw          $a0, 0x3C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X3C);
    func_80106790(rdram, ctx);
        goto after_10;
    // 0x80800CCC: lw          $a0, 0x3C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X3C);
    after_10:
    // 0x80800CD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CD4: jal         0x80800558
    // 0x80800CD8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800558_chfireicestorm(rdram, ctx);
        goto after_11;
    // 0x80800CD8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800CDC: jal         0x800FFAB0
    // 0x80800CE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x80800CE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_12:
    // 0x80800CE4: b           L_80800CF8
    // 0x80800CE8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800CF8;
    // 0x80800CE8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800CEC:
    // 0x80800CEC: b           L_80800CF8
    // 0x80800CF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800CF8;
    // 0x80800CF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CF4:
    // 0x80800CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CF8:
    // 0x80800CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CFC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800D00: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800D04: jr          $ra
    // 0x80800D08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800D08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bstaxi_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808014C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808014C8: jal         0x80800144
    // 0x808014CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bstaxi_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808014CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808014D0: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x808014D4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808014D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808014DC: jal         0x8008CCBC
    // 0x808014E0: addiu       $a1, $zero, 0x128
    ctx->r5 = ADD32(0, 0X128);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x808014E0: addiu       $a1, $zero, 0x128
    ctx->r5 = ADD32(0, 0X128);
    after_1:
    // 0x808014E4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808014E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808014EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808014F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808014F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808014F8: jal         0x8009FFD8
    // 0x808014FC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808014FC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80801500: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801504: jal         0x8009B9B0
    // 0x80801508: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80801508: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080150C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801510: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801514: jr          $ra
    // 0x80801518: nop

    return;
    // 0x80801518: nop

;}
RECOMP_FUNC void _bsbbuster_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827B0: syscall     13
    recomp_syscall_handler(rdram, ctx, 0x800827B0);
    return;
    // 0x800827B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800F58CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F58CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F58D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F58D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F58D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F58DC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F58E0: jal         0x80096394
    // 0x800F58E4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80096394(rdram, ctx);
        goto after_0;
    // 0x800F58E4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F58E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F58EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F58F0: jr          $ra
    // 0x800F58F4: nop

    return;
    // 0x800F58F4: nop

;}
RECOMP_FUNC void func_80803638_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080363C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803640: jal         0x80088518
    // 0x80803644: nop

    _glsavegame_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80803644: nop

    after_0:
    // 0x80803648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080364C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803650: jr          $ra
    // 0x80803654: nop

    return;
    // 0x80803654: nop

;}
RECOMP_FUNC void func_808015CC_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015CC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808015D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808015D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808015D8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808015DC: lbu         $v0, 0x213($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X213);
    // 0x808015E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808015E4: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x808015E8: beql        $v0, $zero, L_80801628
    if (ctx->r2 == 0) {
        // 0x808015EC: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80801628;
    }
    goto skip_0;
    // 0x808015EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x808015F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808015F4: beq         $v0, $at, L_80801638
    if (ctx->r2 == ctx->r1) {
        // 0x808015F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801638;
    }
    // 0x808015F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808015FC: beq         $v0, $at, L_8080160C
    if (ctx->r2 == ctx->r1) {
        // 0x80801600: lwc1        $f16, 0x40($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
            goto L_8080160C;
    }
    // 0x80801600: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80801604: b           L_80801644
    // 0x80801608: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
        goto L_80801644;
    // 0x80801608: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_8080160C:
    // 0x8080160C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801610: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801614: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80801618: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080161C: b           L_80801644
    // 0x80801620: nop

        goto L_80801644;
    // 0x80801620: nop

    // 0x80801624: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80801628:
    // 0x80801628: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080162C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801630: b           L_80801644
    // 0x80801634: nop

        goto L_80801644;
    // 0x80801634: nop

L_80801638:
    // 0x80801638: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3094, 0X2A00) << 16);
    // 0x8080163C: lwc1        $f16, 0x2A00($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3094, 0X2A00));
    // 0x80801640: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_80801644:
    // 0x80801644: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3094, 0X2A04) << 16);
    // 0x80801648: lwc1        $f0, 0x2A04($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3094, 0X2A04));
    // 0x8080164C: lwc1        $f12, 0x20C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20C);
    // 0x80801650: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3094, 0X2A08) << 16);
    // 0x80801654: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80801658: nop

    // 0x8080165C: bc1f        L_80801684
    if (!c1cs) {
        // 0x80801660: nop
    
            goto L_80801684;
    }
    // 0x80801660: nop

    // 0x80801664: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801668: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080166C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80801670: jal         0x800F10B4
    // 0x80801674: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80801674: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x80801678: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
    // 0x8080167C: b           L_808016B0
    // 0x80801680: lwc1        $f12, 0x20C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20C);
        goto L_808016B0;
    // 0x80801680: lwc1        $f12, 0x20C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20C);
L_80801684:
    // 0x80801684: lwc1        $f14, 0x2A08($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3094, 0X2A08));
    // 0x80801688: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080168C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80801690: nop

    // 0x80801694: bc1fl       L_808016B4
    if (!c1cs) {
        // 0x80801698: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808016B4;
    }
    goto skip_1;
    // 0x80801698: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x8080169C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x808016A0: jal         0x800F10B4
    // 0x808016A4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808016A4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x808016A8: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
    // 0x808016AC: lwc1        $f12, 0x20C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20C);
L_808016B0:
    // 0x808016B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_808016B4:
    // 0x808016B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808016B8: nop

    // 0x808016BC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x808016C0: nop

    // 0x808016C4: bc1fl       L_80801738
    if (!c1cs) {
        // 0x808016C8: swc1        $f2, 0x20C($s0)
        MEM_W(0X20C, ctx->r16) = ctx->f2.u32l;
            goto L_80801738;
    }
    goto skip_2;
    // 0x808016C8: swc1        $f2, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f2.u32l;
    skip_2:
    // 0x808016CC: lbu         $t6, 0x213($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X213);
    // 0x808016D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808016D4: addiu       $t7, $s0, 0x58
    ctx->r15 = ADD32(ctx->r16, 0X58);
    // 0x808016D8: bne         $t6, $at, L_808016EC
    if (ctx->r14 != ctx->r1) {
        // 0x808016DC: nop
    
            goto L_808016EC;
    }
    // 0x808016DC: nop

    // 0x808016E0: swc1        $f2, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f2.u32l;
    // 0x808016E4: b           L_80801780
    // 0x808016E8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
        goto L_80801780;
    // 0x808016E8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_808016EC:
    // 0x808016EC: jal         0x800D8FF8
    // 0x808016F0: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x808016F0: nop

    after_2:
    // 0x808016F4: lwc1        $f4, 0x154($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X154);
    // 0x808016F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808016FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801700: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801704: lw          $a2, 0x20C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20C);
    // 0x80801708: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8080170C: addiu       $t8, $t8, -0x6EE8
    ctx->r24 = ADD32(ctx->r24, -0X6EE8);
    // 0x80801710: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    // 0x80801714: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80801718: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8080171C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80801720: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80801724: jal         0x80089140
    // 0x80801728: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    _mlspline_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80801728: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8080172C: b           L_80801780
    // 0x80801730: swc1        $f0, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f0.u32l;
        goto L_80801780;
    // 0x80801730: swc1        $f0, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f0.u32l;
    // 0x80801734: swc1        $f2, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f2.u32l;
L_80801738:
    // 0x80801738: jal         0x80110024
    // 0x8080173C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_80110024(rdram, ctx);
        goto after_4;
    // 0x8080173C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x80801740: lb          $a3, 0x211($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X211);
    // 0x80801744: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801748: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8080174C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801750: jal         0x800894E8
    // 0x80801754: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    _ncpod_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80801754: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    after_5:
    // 0x80801758: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080175C: bne         $v0, $at, L_8080176C
    if (ctx->r2 != ctx->r1) {
        // 0x80801760: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080176C;
    }
    // 0x80801760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801764: b           L_808017E0
    // 0x80801768: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808017E0;
    // 0x80801768: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080176C:
    // 0x8080176C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80801770: jal         0x80800338
    // 0x80801774: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800338_ncpoddialog(rdram, ctx);
        goto after_6;
    // 0x80801774: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80801778: addiu       $t9, $s0, 0x58
    ctx->r25 = ADD32(ctx->r16, 0X58);
    // 0x8080177C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_80801780:
    // 0x80801780: lwc1        $f12, 0x20C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20C);
    // 0x80801784: addiu       $a3, $s0, 0x170
    ctx->r7 = ADD32(ctx->r16, 0X170);
    // 0x80801788: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080178C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801790: jal         0x800890F8
    // 0x80801794: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _mlspline_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80801794: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x80801798: lwc1        $f12, 0x20C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20C);
    // 0x8080179C: addiu       $a3, $s0, 0x17C
    ctx->r7 = ADD32(ctx->r16, 0X17C);
    // 0x808017A0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x808017A4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808017A8: jal         0x800890F8
    // 0x808017AC: addiu       $a2, $s0, 0xD0
    ctx->r6 = ADD32(ctx->r16, 0XD0);
    _mlspline_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x808017AC: addiu       $a2, $s0, 0xD0
    ctx->r6 = ADD32(ctx->r16, 0XD0);
    after_8:
    // 0x808017B0: jal         0x80110024
    // 0x808017B4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_80110024(rdram, ctx);
        goto after_9;
    // 0x808017B4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_9:
    // 0x808017B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808017BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808017C0: jal         0x80089500
    // 0x808017C4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _ncpod_entrypoint_8(rdram, ctx);
        goto after_10;
    // 0x808017C4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x808017C8: jal         0x80110024
    // 0x808017CC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_80110024(rdram, ctx);
        goto after_11;
    // 0x808017CC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x808017D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808017D4: jal         0x80089508
    // 0x808017D8: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    _ncpod_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x808017D8: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    after_12:
    // 0x808017DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808017E0:
    // 0x808017E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808017E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808017E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808017EC: jr          $ra
    // 0x808017F0: nop

    return;
    // 0x808017F0: nop

;}
RECOMP_FUNC void bawandglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: jal         0x800F53E4
    // 0x80800018: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F53E4(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080001C: beql        $v0, $zero, L_80800030
    if (ctx->r2 == 0) {
        // 0x80800020: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800030;
    }
    goto skip_0;
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800024: lw          $t6, 0x148($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X148);
    // 0x80800028: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800030:
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_808020B8_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808020BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808020C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808020C4: lw          $a0, 0x18($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X18);
    // 0x808020C8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808020CC: srl         $t6, $a0, 28
    ctx->r14 = S32(U32(ctx->r4) >> 28);
    // 0x808020D0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808020D4: jal         0x8008A240
    // 0x808020D8: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808020D8: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808020DC: lh          $t7, 0x50($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X50);
    // 0x808020E0: lh          $t8, 0x52($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X52);
    // 0x808020E4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808020E8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x808020EC: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x808020F0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x808020F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808020F8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x808020FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802100: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80802104: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80802108: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080210C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80802110: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80802114: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80802118: jal         0x80102BF8
    // 0x8080211C: nop

    func_80102BF8(rdram, ctx);
        goto after_1;
    // 0x8080211C: nop

    after_1:
    // 0x80802120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802128: jr          $ra
    // 0x8080212C: nop

    return;
    // 0x8080212C: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E90: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E90);
    return;
    // 0x80083E94: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void bababykaz_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800194: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800198: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080019C: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x808001A0: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x808001A4: jal         0x800EA068
    // 0x808001A8: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    func_800EA068(rdram, ctx);
        goto after_0;
    // 0x808001A8: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    after_0:
    // 0x808001AC: beq         $v0, $zero, L_808001C4
    if (ctx->r2 == 0) {
        // 0x808001B0: nop
    
            goto L_808001C4;
    }
    // 0x808001B0: nop

    // 0x808001B4: jal         0x800FC660
    // 0x808001B8: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    func_800FC660(rdram, ctx);
        goto after_1;
    // 0x808001B8: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    after_1:
    // 0x808001BC: b           L_808001D0
    // 0x808001C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001D0;
    // 0x808001C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001C4:
    // 0x808001C4: jal         0x800C77DC
    // 0x808001C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C77DC(rdram, ctx);
        goto after_2;
    // 0x808001C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x808001CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001D0:
    // 0x808001D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001D4: jr          $ra
    // 0x808001D8: nop

    return;
    // 0x808001D8: nop

;}
RECOMP_FUNC void _ncbaledge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891C0: syscall     766
    recomp_syscall_handler(rdram, ctx, 0x800891C0);
    return;
    // 0x800891C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsthrow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EE8: syscall     97
    recomp_syscall_handler(rdram, ctx, 0x80083EE8);
    return;
    // 0x80083EEC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chquicksandbaddy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F60: syscall     482
    recomp_syscall_handler(rdram, ctx, 0x80086F60);
    return;
    // 0x80086F64: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800125B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800125B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800125B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800125B8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800125BC: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x800125C0: ori         $a1, $a1, 0x2A00
    ctx->r5 = ctx->r5 | 0X2A00;
    // 0x800125C4: jal         0x8002D6E0
    // 0x800125C8: addiu       $a0, $a0, 0x6A88
    ctx->r4 = ADD32(ctx->r4, 0X6A88);
    _bzero(rdram, ctx);
        goto after_0;
    // 0x800125C8: addiu       $a0, $a0, 0x6A88
    ctx->r4 = ADD32(ctx->r4, 0X6A88);
    after_0:
    // 0x800125CC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800125D0: addiu       $v0, $v0, 0x6A78
    ctx->r2 = ADD32(ctx->r2, 0X6A78);
    // 0x800125D4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800125D8: addiu       $t6, $t6, 0x6A88
    ctx->r14 = ADD32(ctx->r14, 0X6A88);
    // 0x800125DC: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x800125E0: ori         $t7, $t7, 0x2A00
    ctx->r15 = ctx->r15 | 0X2A00;
    // 0x800125E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800125E8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800125EC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800125F0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800125F4: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x800125F8: lw          $v1, 0x300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X300);
    // 0x800125FC: lui         $t9, 0x2E6
    ctx->r25 = S32(0X2E6 << 16);
    // 0x80012600: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012604: beq         $v1, $zero, L_80012624
    if (ctx->r3 == 0) {
        // 0x80012608: ori         $t9, $t9, 0xD354
        ctx->r25 = ctx->r25 | 0XD354;
            goto L_80012624;
    }
    // 0x80012608: ori         $t9, $t9, 0xD354
    ctx->r25 = ctx->r25 | 0XD354;
    // 0x8001260C: beq         $v1, $at, L_80012624
    if (ctx->r3 == ctx->r1) {
        // 0x80012610: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80012624;
    }
    // 0x80012610: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80012614: beq         $v1, $at, L_80012630
    if (ctx->r3 == ctx->r1) {
        // 0x80012618: lui         $t0, 0x2E6
        ctx->r8 = S32(0X2E6 << 16);
            goto L_80012630;
    }
    // 0x80012618: lui         $t0, 0x2E6
    ctx->r8 = S32(0X2E6 << 16);
    // 0x8001261C: b           L_8001263C
    // 0x80012620: nop

        goto L_8001263C;
    // 0x80012620: nop

L_80012624:
    // 0x80012624: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80012628: b           L_8001263C
    // 0x8001262C: sw          $t9, 0x1398($at)
    MEM_W(0X1398, ctx->r1) = ctx->r25;
        goto L_8001263C;
    // 0x8001262C: sw          $t9, 0x1398($at)
    MEM_W(0X1398, ctx->r1) = ctx->r25;
L_80012630:
    // 0x80012630: ori         $t0, $t0, 0x25C
    ctx->r8 = ctx->r8 | 0X25C;
    // 0x80012634: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80012638: sw          $t0, 0x1398($at)
    MEM_W(0X1398, ctx->r1) = ctx->r8;
L_8001263C:
    // 0x8001263C: jal         0x8001268C
    // 0x80012640: nop

    func_8001268C(rdram, ctx);
        goto after_1;
    // 0x80012640: nop

    after_1:
    // 0x80012644: jal         0x800DC380
    // 0x80012648: nop

    func_800DC380(rdram, ctx);
        goto after_2;
    // 0x80012648: nop

    after_2:
    // 0x8001264C: jal         0x80016C00
    // 0x80012650: nop

    func_80016C00(rdram, ctx);
        goto after_3;
    // 0x80012650: nop

    after_3:
    // 0x80012654: jal         0x80012F0C
    // 0x80012658: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80012F0C(rdram, ctx);
        goto after_4;
    // 0x80012658: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x8001265C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012660: jal         0x80012F34
    // 0x80012664: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80012F34(rdram, ctx);
        goto after_5;
    // 0x80012664: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80012668: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001266C: jal         0x80012F34
    // 0x80012670: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80012F34(rdram, ctx);
        goto after_6;
    // 0x80012670: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80012674: jal         0x80012EA0
    // 0x80012678: nop

    func_80012EA0(rdram, ctx);
        goto after_7;
    // 0x80012678: nop

    after_7:
    // 0x8001267C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012684: jr          $ra
    // 0x80012688: nop

    return;
    // 0x80012688: nop

;}
RECOMP_FUNC void func_80800CC0_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CC8: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800CCC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800CD4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800CD8: beql        $t7, $zero, L_80800CFC
    if (ctx->r15 == 0) {
        // 0x80800CDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800CFC;
    }
    goto skip_0;
    // 0x80800CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800CE0: jal         0x800856B8
    // 0x80800CE4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800CE4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800CE8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800CEC: lhu         $t8, 0x6E($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6E);
    // 0x80800CF0: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800CF4: sh          $t9, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r25;
    // 0x80800CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CFC:
    // 0x80800CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D00: jr          $ra
    // 0x80800D04: nop

    return;
    // 0x80800D04: nop

;}
RECOMP_FUNC void func_80100A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100A78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80100A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100A80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80100A84: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100A88: lh          $a1, 0x1A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1A);
    // 0x80100A8C: jal         0x800B301C
    // 0x80100A90: lw          $a0, 0x5A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A60);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x80100A90: lw          $a0, 0x5A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A60);
    after_0:
    // 0x80100A94: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x80100A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100A9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80100AA0: beq         $t6, $zero, L_80100AB8
    if (ctx->r14 == 0) {
        // 0x80100AA4: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80100AB8;
    }
    // 0x80100AA4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80100AA8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80100AAC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80100AB0: b           L_80100AB8
    // 0x80100AB4: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
        goto L_80100AB8;
    // 0x80100AB4: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
L_80100AB8:
    // 0x80100AB8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80100ABC: jr          $ra
    // 0x80100AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80100AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801B88_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B88: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801B8C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801B90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80801B98: jal         0x800EC398
    // 0x80801B9C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EC398(rdram, ctx);
        goto after_0;
    // 0x80801B9C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80801BA0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80801BA4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801BA8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80801BAC: jal         0x800F18FC
    // 0x80801BB0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800F18FC(rdram, ctx);
        goto after_1;
    // 0x80801BB0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80801BB4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801BB8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80801BBC: jal         0x800EEBF0
    // 0x80801BC0: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_800EEBF0(rdram, ctx);
        goto after_2;
    // 0x80801BC0: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_2:
    // 0x80801BC4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801BC8: jal         0x800EF04C
    // 0x80801BCC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80801BCC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80801BD0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(932, 0X2E44) << 16);
    // 0x80801BD4: addiu       $t6, $t6, 0x2E44
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(932, 0X2E44));
    // 0x80801BD8: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80801BDC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801BE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801BE4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801BE8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801BEC: jal         0x800BBCB8
    // 0x80801BF0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x80801BF0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_4:
    // 0x80801BF4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(932, 0X2E6C) << 16);
    // 0x80801BF8: addiu       $t7, $t7, 0x2E6C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(932, 0X2E6C));
    // 0x80801BFC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801C00: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801C04: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801C08: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801C0C: jal         0x800BBCB8
    // 0x80801C10: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x80801C10: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80801C14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801C1C: jr          $ra
    // 0x80801C20: nop

    return;
    // 0x80801C20: nop

;}
RECOMP_FUNC void _gczoomboxdata_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088438: syscall     682
    recomp_syscall_handler(rdram, ctx, 0x80088438);
    return;
    // 0x8008843C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800F8128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F812C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8130: jal         0x800F80D8
    // 0x800F8134: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F80D8(rdram, ctx);
        goto after_0;
    // 0x800F8134: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F8138: jal         0x800A91A8
    // 0x800F813C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A91A8(rdram, ctx);
        goto after_1;
    // 0x800F813C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800F8140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8148: jr          $ra
    // 0x800F814C: nop

    return;
    // 0x800F814C: nop

;}
RECOMP_FUNC void func_808000C0_chLagoonInnBlockedWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: jal         0x8010A63C
    // 0x808000CC: nop

    func_8010A63C(rdram, ctx);
        goto after_0;
    // 0x808000CC: nop

    after_0:
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void func_80098480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098480: lw          $t6, 0xAC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XAC);
    // 0x80098484: sb          $a1, 0x28($t6)
    MEM_B(0X28, ctx->r14) = ctx->r5;
    // 0x80098488: lw          $t7, 0xAC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XAC);
    // 0x8009848C: jr          $ra
    // 0x80098490: sb          $a2, 0x2A($t7)
    MEM_B(0X2A, ctx->r15) = ctx->r6;
    return;
    // 0x80098490: sb          $a2, 0x2A($t7)
    MEM_B(0X2A, ctx->r15) = ctx->r6;
;}
RECOMP_FUNC void func_80800284_chweldarbossfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800288: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080028C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800290: beq         $a1, $at, L_808002B4
    if (ctx->r5 == ctx->r1) {
        // 0x80800294: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808002B4;
    }
    // 0x80800294: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800298: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080029C: bne         $a1, $at, L_808002C4
    if (ctx->r5 != ctx->r1) {
        // 0x808002A0: nop
    
            goto L_808002C4;
    }
    // 0x808002A0: nop

    // 0x808002A4: jal         0x808002E0
    // 0x808002A8: nop

    func_808002E0_chweldarbossfireball(rdram, ctx);
        goto after_0;
    // 0x808002A8: nop

    after_0:
    // 0x808002AC: b           L_808002D0
    // 0x808002B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002D0;
    // 0x808002B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002B4:
    // 0x808002B4: jal         0x80800214
    // 0x808002B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800214_chweldarbossfireball(rdram, ctx);
        goto after_1;
    // 0x808002B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808002BC: b           L_808002D0
    // 0x808002C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002D0;
    // 0x808002C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002C4:
    // 0x808002C4: b           L_808002D0
    // 0x808002C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002D0;
    // 0x808002C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002D0:
    // 0x808002D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_800E2720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2720: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800E2724: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800E2728: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E272C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E2730: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E2734: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800E2738: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800E273C: beq         $t6, $zero, L_800E2760
    if (ctx->r14 == 0) {
        // 0x800E2740: sw          $a3, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r7;
            goto L_800E2760;
    }
    // 0x800E2740: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800E2744: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800E2748: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800E274C: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800E2750: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x800E2754: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800E2758: b           L_800E2778
    // 0x800E275C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
        goto L_800E2778;
    // 0x800E275C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_800E2760:
    // 0x800E2760: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E2764: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E2768: nop

    // 0x800E276C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800E2770: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800E2774: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
L_800E2778:
    // 0x800E2778: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E277C: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x800E2780: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800E2784: lw          $a0, -0x2B10($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B10);
    // 0x800E2788: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800E278C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800E2790: jal         0x800E1C00
    // 0x800E2794: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    func_800E1C00(rdram, ctx);
        goto after_0;
    // 0x800E2794: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800E2798: bne         $v0, $zero, L_800E27A8
    if (ctx->r2 != 0) {
        // 0x800E279C: nop
    
            goto L_800E27A8;
    }
    // 0x800E279C: nop

    // 0x800E27A0: b           L_800E2890
    // 0x800E27A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E2890;
    // 0x800E27A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E27A8:
    // 0x800E27A8: jal         0x800E401C
    // 0x800E27AC: nop

    func_800E401C(rdram, ctx);
        goto after_1;
    // 0x800E27AC: nop

    after_1:
    // 0x800E27B0: jal         0x80018EFC
    // 0x800E27B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mlMtxSet(rdram, ctx);
        goto after_2;
    // 0x800E27B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800E27B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E27BC: lwc1        $f12, -0x2B68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B68);
    // 0x800E27C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800E27C4: nop

    // 0x800E27C8: c.eq.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl == ctx->f12.fl;
    // 0x800E27CC: nop

    // 0x800E27D0: bc1tl       L_800E27E4
    if (c1cs) {
        // 0x800E27D4: lwc1        $f12, 0x40($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
            goto L_800E27E4;
    }
    goto skip_0;
    // 0x800E27D4: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x800E27D8: jal         0x8001907C
    // 0x800E27DC: nop

    mlMtxRotRoll(rdram, ctx);
        goto after_3;
    // 0x800E27DC: nop

    after_3:
    // 0x800E27E0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
L_800E27E4:
    // 0x800E27E4: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800E27E8: jal         0x800191F8
    // 0x800E27EC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    func_800191F8(rdram, ctx);
        goto after_4;
    // 0x800E27EC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x800E27F0: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800E27F4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800E27F8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800E27FC: bne         $t8, $zero, L_800E280C
    if (ctx->r24 != 0) {
        // 0x800E2800: lwc1        $f14, 0x50($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
            goto L_800E280C;
    }
    // 0x800E2800: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800E2804: beq         $t9, $zero, L_800E2828
    if (ctx->r25 == 0) {
        // 0x800E2808: nop
    
            goto L_800E2828;
    }
    // 0x800E2808: nop

L_800E280C:
    // 0x800E280C: beq         $t0, $zero, L_800E2820
    if (ctx->r8 == 0) {
        // 0x800E2810: lwc1        $f12, 0x54($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
            goto L_800E2820;
    }
    // 0x800E2810: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800E2814: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800E2818: b           L_800E2820
    // 0x800E281C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_800E2820;
    // 0x800E281C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_800E2820:
    // 0x800E2820: jal         0x80019D30
    // 0x800E2824: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    mlMtxScale_xyz(rdram, ctx);
        goto after_5;
    // 0x800E2824: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    after_5:
L_800E2828:
    // 0x800E2828: jal         0x80018C28
    // 0x800E282C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_6;
    // 0x800E282C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x800E2830: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E2834: lui         $t2, 0xDA38
    ctx->r10 = S32(0XDA38 << 16);
    // 0x800E2838: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800E283C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800E2840: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800E2844: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800E2848: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x800E284C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2850: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800E2854: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x800E2858: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x800E285C: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800E2860: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800E2864: jal         0x800E2630
    // 0x800E2868: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800E2630(rdram, ctx);
        goto after_7;
    // 0x800E2868: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_7:
    // 0x800E286C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E2870: lui         $t7, 0xD838
    ctx->r15 = S32(0XD838 << 16);
    // 0x800E2874: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800E2878: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E287C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800E2880: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800E2884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E2888: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800E288C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800E2890:
    // 0x800E2890: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E2894: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E2898: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800E289C: jr          $ra
    // 0x800E28A0: nop

    return;
    // 0x800E28A0: nop

;}
RECOMP_FUNC void func_8080017C_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800188: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x8080018C: addiu       $a2, $zero, 0x373
    ctx->r6 = ADD32(0, 0X373);
    // 0x80800190: jal         0x80800FA4
    // 0x80800194: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_80800FA4_chalienkids(rdram, ctx);
        goto after_0;
    // 0x80800194: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x80800198: jal         0x800DA298
    // 0x8080019C: addiu       $a0, $zero, 0x373
    ctx->r4 = ADD32(0, 0X373);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080019C: addiu       $a0, $zero, 0x373
    ctx->r4 = ADD32(0, 0X373);
    after_1:
    // 0x808001A0: bnel        $v0, $zero, L_808001C4
    if (ctx->r2 != 0) {
        // 0x808001A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001C4;
    }
    goto skip_0;
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001A8: jal         0x80088848
    // 0x808001AC: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808001AC: nop

    after_2:
    // 0x808001B0: bne         $v0, $zero, L_808001C0
    if (ctx->r2 != 0) {
        // 0x808001B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808001C0;
    }
    // 0x808001B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001B8: jal         0x8010A85C
    // 0x808001BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A85C(rdram, ctx);
        goto after_3;
    // 0x808001BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_808001C0:
    // 0x808001C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001C4:
    // 0x808001C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C8: jr          $ra
    // 0x808001CC: nop

    return;
    // 0x808001CC: nop

;}
RECOMP_FUNC void _bareact_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F70: syscall     145
    recomp_syscall_handler(rdram, ctx, 0x80084F70);
    return;
    // 0x80084F74: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80800424_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080042C: jal         0x80106790
    // 0x80800430: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800430: nop

    after_0:
    // 0x80800434: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800438: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080043C: jal         0x80100094
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800444: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800448: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080044C: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x80800450: lw          $a2, 0x24($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X24);
    // 0x80800454: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800458: addiu       $a1, $zero, 0x7F4
    ctx->r5 = ADD32(0, 0X7F4);
    // 0x8080045C: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80800460: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x80800464: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80800468: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x8080046C: lhu         $a0, 0x4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X4);
    // 0x80800470: addu        $t4, $a3, $t0
    ctx->r12 = ADD32(ctx->r7, ctx->r8);
    // 0x80800474: beq         $a0, $at, L_80800494
    if (ctx->r4 == ctx->r1) {
        // 0x80800478: addiu       $at, $zero, 0x1FFF
        ctx->r1 = ADD32(0, 0X1FFF);
            goto L_80800494;
    }
    // 0x80800478: addiu       $at, $zero, 0x1FFF
    ctx->r1 = ADD32(0, 0X1FFF);
    // 0x8080047C: bnel        $a0, $at, L_808004A4
    if (ctx->r4 != ctx->r1) {
        // 0x80800480: lb          $a0, 0x0($v1)
        ctx->r4 = MEM_B(ctx->r3, 0X0);
            goto L_808004A4;
    }
    goto skip_0;
    // 0x80800480: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    skip_0:
    // 0x80800484: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x80800488: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080048C: b           L_808004A0
    // 0x80800490: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
        goto L_808004A0;
    // 0x80800490: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_80800494:
    // 0x80800494: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x80800498: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8080049C: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_808004A0:
    // 0x808004A0: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
L_808004A4:
    // 0x808004A4: bgez        $a0, L_808004B4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x808004A8: addiu       $t2, $a0, 0x4
        ctx->r10 = ADD32(ctx->r4, 0X4);
            goto L_808004B4;
    }
    // 0x808004A8: addiu       $t2, $a0, 0x4
    ctx->r10 = ADD32(ctx->r4, 0X4);
    // 0x808004AC: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x808004B0: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
L_808004B4:
    // 0x808004B4: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x808004B8: bne         $at, $zero, L_808004C4
    if (ctx->r1 != 0) {
        // 0x808004BC: addiu       $t3, $a0, -0x4
        ctx->r11 = ADD32(ctx->r4, -0X4);
            goto L_808004C4;
    }
    // 0x808004BC: addiu       $t3, $a0, -0x4
    ctx->r11 = ADD32(ctx->r4, -0X4);
    // 0x808004C0: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
L_808004C4:
    // 0x808004C4: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
    // 0x808004C8: jal         0x808007E4
    // 0x808004CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_2;
    // 0x808004CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x808004D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004D8: jr          $ra
    // 0x808004DC: nop

    return;
    // 0x808004DC: nop

;}
RECOMP_FUNC void func_800CBA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBA44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBA48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBA4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CBA50: jal         0x80087EF8
    // 0x800CBA54: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    _gcboundDll_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x800CBA54: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    after_0:
    // 0x800CBA58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBA5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CBA60: jr          $ra
    // 0x800CBA64: nop

    return;
    // 0x800CBA64: nop

;}
RECOMP_FUNC void _bsmumstill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838D8: syscall     80
    recomp_syscall_handler(rdram, ctx, 0x800838D8);
    return;
    // 0x800838DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D37D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D37D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D37D8: addiu       $v0, $v0, -0x4C10
    ctx->r2 = ADD32(ctx->r2, -0X4C10);
    // 0x800D37DC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800D37E0: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    // 0x800D37E4: lb          $t7, 0x1($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1);
    // 0x800D37E8: jr          $ra
    // 0x800D37EC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x800D37EC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void chdoormake_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080065C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800660: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800664: jal         0x80100094
    // 0x80800668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080066C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80800670: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800674: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800678: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080067C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800680: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80800684: nop

    // 0x80800688: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x8080068C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800694: jr          $ra
    // 0x80800698: nop

    return;
    // 0x80800698: nop

;}
RECOMP_FUNC void func_8010BAEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BAEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010BAF0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8010BAF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8010BAF8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8010BAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010BB00: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8010BB04: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8010BB08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010BB0C: jal         0x800EE7F8
    // 0x8010BB10: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8010BB10: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8010BB14: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8010BB18: jal         0x8010B990
    // 0x8010BB1C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8010B990(rdram, ctx);
        goto after_1;
    // 0x8010BB1C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8010BB20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8010BB24: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010BB28: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8010BB2C: and         $t6, $v0, $a0
    ctx->r14 = ctx->r2 & ctx->r4;
    // 0x8010BB30: beql        $t6, $a0, L_8010BB4C
    if (ctx->r14 == ctx->r4) {
        // 0x8010BB34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010BB4C;
    }
    goto skip_0;
    // 0x8010BB34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010BB38: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8010BB3C: jal         0x800EE7F8
    // 0x8010BB40: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8010BB40: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8010BB44: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8010BB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010BB4C:
    // 0x8010BB4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8010BB50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010BB54: jr          $ra
    // 0x8010BB58: nop

    return;
    // 0x8010BB58: nop

;}
RECOMP_FUNC void _bsdronebitten_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083048: syscall     39
    recomp_syscall_handler(rdram, ctx, 0x80083048);
    return;
    // 0x8008304C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800221B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800221B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800221B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800221B8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800221BC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800221C0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800221C4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800221C8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800221CC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800221D0: sw          $zero, 0x20($t8)
    MEM_W(0X20, ctx->r24) = 0;
    // 0x800221D4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800221D8: sw          $zero, 0x18($t9)
    MEM_W(0X18, ctx->r25) = 0;
    // 0x800221DC: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800221E0: lw          $t0, 0x11F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X11F4);
    // 0x800221E4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800221E8: sw          $t0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r8;
    // 0x800221EC: jal         0x80026100
    // 0x800221F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80026100(rdram, ctx);
        goto after_0;
    // 0x800221F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x800221F4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800221F8: addiu       $t2, $zero, 0x1E8
    ctx->r10 = ADD32(0, 0X1E8);
    // 0x800221FC: sw          $t2, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r10;
    // 0x80022200: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80022204: sw          $zero, 0x28($t4)
    MEM_W(0X28, ctx->r12) = 0;
    // 0x80022208: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8002220C: sw          $zero, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = 0;
    // 0x80022210: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80022214: addiu       $t6, $zero, 0x7FFF
    ctx->r14 = ADD32(0, 0X7FFF);
    // 0x80022218: sh          $t6, 0x34($t7)
    MEM_H(0X34, ctx->r15) = ctx->r14;
    // 0x8002221C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80022220: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80022224: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x80022228: sb          $t9, 0x37($t0)
    MEM_B(0X37, ctx->r8) = ctx->r25;
    // 0x8002222C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80022230: addiu       $t1, $zero, 0x3E80
    ctx->r9 = ADD32(0, 0X3E80);
    // 0x80022234: sw          $t1, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = ctx->r9;
    // 0x80022238: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8002223C: sw          $zero, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = 0;
    // 0x80022240: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80022244: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80022248: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8002224C: sw          $t5, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->r13;
    // 0x80022250: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80022254: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80022258: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8002225C: sw          $t8, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->r24;
    // 0x80022260: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80022264: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80022268: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8002226C: sw          $t1, 0x78($t2)
    MEM_W(0X78, ctx->r10) = ctx->r9;
    // 0x80022270: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80022274: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80022278: swc1        $f4, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = ctx->f4.u32l;
    // 0x8002227C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022280: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022284: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80022288: swc1        $f6, 0x80($t4)
    MEM_W(0X80, ctx->r12) = ctx->f6.u32l;
    // 0x8002228C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80022290: sw          $zero, 0x84($t5)
    MEM_W(0X84, ctx->r13) = 0;
    // 0x80022294: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80022298: sb          $zero, 0x89($t6)
    MEM_B(0X89, ctx->r14) = 0;
    // 0x8002229C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800222A0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800222A4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800222A8: sb          $t8, 0x88($t9)
    MEM_B(0X88, ctx->r25) = ctx->r24;
    // 0x800222AC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800222B0: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800222B4: sh          $t0, 0x38($t1)
    MEM_H(0X38, ctx->r9) = ctx->r8;
    // 0x800222B8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800222BC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800222C0: lbu         $t3, 0x8($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X8);
    // 0x800222C4: sb          $t3, 0x36($t4)
    MEM_B(0X36, ctx->r12) = ctx->r11;
    // 0x800222C8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800222CC: addiu       $t6, $zero, 0x38
    ctx->r14 = ADD32(0, 0X38);
    // 0x800222D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800222D4: lbu         $a3, 0x8($t5)
    ctx->r7 = MEM_BU(ctx->r13, 0X8);
    // 0x800222D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800222DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800222E0: jal         0x80020EE4
    // 0x800222E4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80020EE4(rdram, ctx);
        goto after_1;
    // 0x800222E4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800222E8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800222EC: sw          $v0, 0x60($t7)
    MEM_W(0X60, ctx->r15) = ctx->r2;
    // 0x800222F0: jal         0x8002A0CC
    // 0x800222F4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8002A0CC(rdram, ctx);
        goto after_2;
    // 0x800222F4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x800222F8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800222FC: addiu       $t9, $zero, 0x44
    ctx->r25 = ADD32(0, 0X44);
    // 0x80022300: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022304: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x80022308: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002230C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022310: jal         0x80020EE4
    // 0x80022314: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80020EE4(rdram, ctx);
        goto after_3;
    // 0x80022314: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80022318: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8002231C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80022320: sw          $zero, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = 0;
    // 0x80022324: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80022328: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8002232C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80022330: blez        $t2, L_80022390
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80022334: nop
    
            goto L_80022390;
    }
    // 0x80022334: nop

L_80022338:
    // 0x80022338: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8002233C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80022340: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80022344: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80022348: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002234C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80022350: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80022354: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80022358: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002235C: lw          $t8, 0x6C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X6C);
    // 0x80022360: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80022364: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80022368: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8002236C: sw          $t0, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->r8;
    // 0x80022370: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80022374: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80022378: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8002237C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80022380: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80022384: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80022388: bne         $at, $zero, L_80022338
    if (ctx->r1 != 0) {
        // 0x8002238C: nop
    
            goto L_80022338;
    }
    // 0x8002238C: nop

L_80022390:
    // 0x80022390: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80022394: sw          $zero, 0x64($t6)
    MEM_W(0X64, ctx->r14) = 0;
    // 0x80022398: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8002239C: sw          $zero, 0x68($t7)
    MEM_W(0X68, ctx->r15) = 0;
    // 0x800223A0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800223A4: addiu       $t9, $zero, 0x1C
    ctx->r25 = ADD32(0, 0X1C);
    // 0x800223A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800223AC: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x800223B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800223B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800223B8: jal         0x80020EE4
    // 0x800223BC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80020EE4(rdram, ctx);
        goto after_4;
    // 0x800223BC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x800223C0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800223C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800223C8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800223CC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800223D0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800223D4: jal         0x800263C0
    // 0x800223D8: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    func_800263C0(rdram, ctx);
        goto after_5;
    // 0x800223D8: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    after_5:
    // 0x800223DC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800223E0: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x800223E4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800223E8: lui         $t2, 0x8002
    ctx->r10 = S32(0X8002 << 16);
    // 0x800223EC: addiu       $t2, $t2, 0x241C
    ctx->r10 = ADD32(ctx->r10, 0X241C);
    // 0x800223F0: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x800223F4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800223F8: sw          $t3, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r11;
    // 0x800223FC: jal         0x80026860
    // 0x80022400: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80026860(rdram, ctx);
        goto after_6;
    // 0x80022400: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80022404: b           L_8002240C
    // 0x80022408: nop

        goto L_8002240C;
    // 0x80022408: nop

L_8002240C:
    // 0x8002240C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022410: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80022414: jr          $ra
    // 0x80022418: nop

    return;
    // 0x80022418: nop

;}
RECOMP_FUNC void func_80802114_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802114: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802118: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080211C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802120: jal         0x80800ECC
    // 0x80802124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80802124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080212C: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x80802130: jal         0x8008CB3C
    // 0x80802134: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80802134: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_1:
    // 0x80802138: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080213C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080214C: jal         0x8009FFD8
    // 0x80802150: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80802150: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80802154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802158: jal         0x8009B9B0
    // 0x8080215C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x8080215C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80802160: jal         0x800909CC
    // 0x80802164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_4;
    // 0x80802164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802168: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080216C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802170: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802174: jr          $ra
    // 0x80802178: nop

    return;
    // 0x80802178: nop

;}
RECOMP_FUNC void func_800EC9E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC9E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800EC9E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800EC9E8: jr          $ra
    // 0x800EC9EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800EC9EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void ncbawaypoint_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800020: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800024: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800028: lw          $v1, 0x5C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X5C);
    // 0x8080002C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80800030: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80800034: bne         $at, $zero, L_80800044
    if (ctx->r1 != 0) {
        // 0x80800038: sll         $t7, $v0, 5
        ctx->r15 = S32(ctx->r2 << 5);
            goto L_80800044;
    }
    // 0x80800038: sll         $t7, $v0, 5
    ctx->r15 = S32(ctx->r2 << 5);
    // 0x8080003C: b           L_80800088
    // 0x80800040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800088;
    // 0x80800040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800044:
    // 0x80800044: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x80800048: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080004C: jal         0x800EE7F8
    // 0x80800050: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800050: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800054: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800058: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080005C: jal         0x800EE7F8
    // 0x80800060: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x80800064: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800068: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800070: swc1        $f4, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f4.u32l;
    // 0x80800074: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800078: lw          $v1, 0x5C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X5C);
    // 0x8080007C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80800080: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80800084: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_80800088:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080008C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800288: jal         0x80800224
    // 0x8080028C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800224_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x8080028C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800290: bne         $v0, $zero, L_808002A0
    if (ctx->r2 != 0) {
        // 0x80800294: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808002A0;
    }
    // 0x80800294: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800298: b           L_808002AC
    // 0x8080029C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002AC;
    // 0x8080029C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002A0:
    // 0x808002A0: jal         0x800EE7F8
    // 0x808002A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808002A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808002A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002AC:
    // 0x808002AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002B4: jr          $ra
    // 0x808002B8: nop

    return;
    // 0x808002B8: nop

;}
RECOMP_FUNC void ncpoddialog_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808010C8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x808010CC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x808010D0: jal         0x80801094
    // 0x808010D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    ncpoddialog_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808010D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808010D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808010E0: jal         0x80801058
    // 0x808010E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80801058_ncpoddialog(rdram, ctx);
        goto after_1;
    // 0x808010E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808010E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808010EC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808010F0: bne         $v0, $at, L_80801100
    if (ctx->r2 != ctx->r1) {
        // 0x808010F4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80801100;
    }
    // 0x808010F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808010F8: b           L_8080113C
    // 0x808010FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080113C;
    // 0x808010FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801100:
    // 0x80801100: lbu         $v0, 0x210($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X210);
    // 0x80801104: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801108: beq         $v0, $at, L_80801134
    if (ctx->r2 == ctx->r1) {
        // 0x8080110C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801134;
    }
    // 0x8080110C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801110: bne         $v0, $at, L_80801134
    if (ctx->r2 != ctx->r1) {
        // 0x80801114: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80801134;
    }
    // 0x80801114: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801118: jal         0x808015CC
    // 0x8080111C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808015CC_ncpoddialog(rdram, ctx);
        goto after_2;
    // 0x8080111C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80801120: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801124: bne         $v0, $at, L_80801134
    if (ctx->r2 != ctx->r1) {
        // 0x80801128: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80801134;
    }
    // 0x80801128: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080112C: b           L_8080113C
    // 0x80801130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080113C;
    // 0x80801130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801134:
    // 0x80801134: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080113C:
    // 0x8080113C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801140: jr          $ra
    // 0x80801144: nop

    return;
    // 0x80801144: nop

;}
RECOMP_FUNC void _baflameline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B58: syscall     130
    recomp_syscall_handler(rdram, ctx, 0x80084B58);
    return;
    // 0x80084B5C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80800210_bsbflap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800218: lwc1        $f4, 0x170($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X170);
    // 0x8080021C: swc1        $f4, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f4.u32l;
    // 0x80800220: jal         0x800D8FF8
    // 0x80800224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800228: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080022C: lwc1        $f6, 0x170($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X170);
    // 0x80800230: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800234: swc1        $f8, 0x170($a0)
    MEM_W(0X170, ctx->r4) = ctx->f8.u32l;
    // 0x80800238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080023C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800240: jr          $ra
    // 0x80800244: nop

    return;
    // 0x80800244: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_45(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C48: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087C48);
    return;
    // 0x80087C4C: addi        $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
;}
RECOMP_FUNC void func_8080088C_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080088C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800890: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800894: addiu       $at, $zero, 0x1501
    ctx->r1 = ADD32(0, 0X1501);
    // 0x80800898: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080089C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008A0: beq         $a1, $at, L_808008D4
    if (ctx->r5 == ctx->r1) {
        // 0x808008A4: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808008D4;
    }
    // 0x808008A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808008A8: addiu       $at, $zero, 0x1503
    ctx->r1 = ADD32(0, 0X1503);
    // 0x808008AC: bnel        $a1, $at, L_808008F4
    if (ctx->r5 != ctx->r1) {
        // 0x808008B0: lw          $v0, 0x6C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X6C);
            goto L_808008F4;
    }
    goto skip_0;
    // 0x808008B0: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x808008B4: jal         0x80800BC0
    // 0x808008B8: nop

    func_80800BC0_chbottlesfamily(rdram, ctx);
        goto after_0;
    // 0x808008B8: nop

    after_0:
    // 0x808008BC: jal         0x8009032C
    // 0x808008C0: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    func_8009032C(rdram, ctx);
        goto after_1;
    // 0x808008C0: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_1:
    // 0x808008C4: jal         0x800FC6B0
    // 0x808008C8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_2;
    // 0x808008C8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_2:
    // 0x808008CC: b           L_8080090C
    // 0x808008D0: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
        goto L_8080090C;
    // 0x808008D0: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
L_808008D4:
    // 0x808008D4: jal         0x80800BC0
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BC0_chbottlesfamily(rdram, ctx);
        goto after_3;
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008DC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    // 0x808008E0: jal         0x800887D8
    // 0x808008E4: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808008E4: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    after_4:
    // 0x808008E8: b           L_8080090C
    // 0x808008EC: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
        goto L_8080090C;
    // 0x808008EC: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x808008F0: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
L_808008F4:
    // 0x808008F4: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x808008F8: beql        $t6, $zero, L_80800910
    if (ctx->r14 == 0) {
        // 0x808008FC: sll         $t7, $v0, 11
        ctx->r15 = S32(ctx->r2 << 11);
            goto L_80800910;
    }
    goto skip_1;
    // 0x808008FC: sll         $t7, $v0, 11
    ctx->r15 = S32(ctx->r2 << 11);
    skip_1:
    // 0x80800900: jal         0x80800BC0
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BC0_chbottlesfamily(rdram, ctx);
        goto after_5;
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800908: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
L_8080090C:
    // 0x8080090C: sll         $t7, $v0, 11
    ctx->r15 = S32(ctx->r2 << 11);
L_80800910:
    // 0x80800910: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800914: addiu       $at, $zero, 0x43C
    ctx->r1 = ADD32(0, 0X43C);
    // 0x80800918: bne         $t8, $at, L_80800980
    if (ctx->r24 != ctx->r1) {
        // 0x8080091C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800980;
    }
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800920: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800924: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800928: jal         0x800DC298
    // 0x8080092C: nop

    func_800DC298(rdram, ctx);
        goto after_6;
    // 0x8080092C: nop

    after_6:
    // 0x80800930: beq         $v0, $zero, L_80800948
    if (ctx->r2 == 0) {
        // 0x80800934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800948;
    }
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800938: jal         0x80800520
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800520_chbottlesfamily(rdram, ctx);
        goto after_7;
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800940: b           L_8080098C
    // 0x80800944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080098C;
    // 0x80800944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800948:
    // 0x80800948: jal         0x80101FDC
    // 0x8080094C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x8080094C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800950: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800954: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800958: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080095C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800960: jal         0x800DC178
    // 0x80800964: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80800964: nop

    after_9:
    // 0x80800968: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080096C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800970: nop

    // 0x80800974: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800978: b           L_80800988
    // 0x8080097C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800988;
    // 0x8080097C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800980:
    // 0x80800980: jal         0x80101FDC
    // 0x80800984: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x80800984: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_80800988:
    // 0x80800988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080098C:
    // 0x8080098C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800990: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800994: jr          $ra
    // 0x80800998: nop

    return;
    // 0x80800998: nop

;}
