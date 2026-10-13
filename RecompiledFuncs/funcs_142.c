#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800E0440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0440: jr          $ra
    // 0x800E0444: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    return;
    // 0x800E0444: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
;}
RECOMP_FUNC void func_8009E9F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E9F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E9F4: jr          $ra
    // 0x8009E9F8: swc1        $f12, 0x7048($at)
    MEM_W(0X7048, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x8009E9F8: swc1        $f12, 0x7048($at)
    MEM_W(0X7048, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800020_chlavafall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800024: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800030: bne         $a1, $at, L_80800088
    if (ctx->r5 != ctx->r1) {
        // 0x80800034: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800088;
    }
    // 0x80800034: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800038: lw          $t6, 0x24($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X24);
    // 0x8080003C: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80800040: bnel        $t7, $zero, L_80800094
    if (ctx->r15 != 0) {
        // 0x80800044: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800094;
    }
    goto skip_0;
    // 0x80800044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800048: lhu         $a0, 0x1A($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X1A);
    // 0x8080004C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80800050: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x80800054: jal         0x800F6AA4
    // 0x80800058: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800F6AA4(rdram, ctx);
        goto after_0;
    // 0x80800058: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x8080005C: bne         $v0, $zero, L_80800090
    if (ctx->r2 != 0) {
        // 0x80800060: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800090;
    }
    // 0x80800060: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800064: lhu         $a0, 0x1A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1A);
    // 0x80800068: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8080006C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800070: srl         $t9, $a0, 5
    ctx->r25 = S32(U32(ctx->r4) >> 5);
    // 0x80800074: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80800078: jal         0x800F79DC
    // 0x8080007C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    func_800F79DC(rdram, ctx);
        goto after_1;
    // 0x8080007C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    after_1:
    // 0x80800080: b           L_80800094
    // 0x80800084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800094;
    // 0x80800084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800088:
    // 0x80800088: b           L_80800094
    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800094;
    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800090:
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

    // 0x808000A4: nop

    // 0x808000A8: nop

    // 0x808000AC: nop

;}
RECOMP_FUNC void ncbaswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: jr          $ra
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chswitch_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800680: jr          $ra
    // 0x80800684: sw          $a1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r5;
    return;
    // 0x80800684: sw          $a1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _ncbaspiral_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089190: syscall     764
    recomp_syscall_handler(rdram, ctx, 0x80089190);
    return;
    // 0x80089194: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chgruntyfireballbig_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1500, 0X680) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x680
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1500, 0X680));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x680
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1500, 0X680));
;}
RECOMP_FUNC void gczoombox_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080368C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80803690: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80803694: beq         $a0, $zero, L_808036A0
    if (ctx->r4 == 0) {
        // 0x80803698: sw          $a1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r5;
            goto L_808036A0;
    }
    // 0x80803698: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8080369C: sh          $t7, 0x1BC($a0)
    MEM_H(0X1BC, ctx->r4) = ctx->r15;
L_808036A0:
    // 0x808036A0: jr          $ra
    // 0x808036A4: nop

    return;
    // 0x808036A4: nop

;}
RECOMP_FUNC void func_800A8B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8B24: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A8B28: lw          $t6, 0x7674($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7674);
    // 0x800A8B2C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A8B30: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800A8B34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A8B38: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A8B3C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A8B40: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8B44: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800A8B48: lw          $a0, 0x7688($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7688);
    // 0x800A8B4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A8B50: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800A8B54: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x800A8B58: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A8B5C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800A8B60: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800A8B64: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x800A8B68: jal         0x80015CC0
    // 0x800A8B6C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80015CC0(rdram, ctx);
        goto after_0;
    // 0x800A8B6C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A8B70: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800A8B74: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800A8B78: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800A8B7C: jal         0x800E7FB0
    // 0x800A8B80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_800E7FB0(rdram, ctx);
        goto after_1;
    // 0x800A8B80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800A8B84: jal         0x800E7EC0
    // 0x800A8B88: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800E7EC0(rdram, ctx);
        goto after_2;
    // 0x800A8B88: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x800A8B8C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A8B90: jal         0x800157EC
    // 0x800A8B94: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800157EC(rdram, ctx);
        goto after_3;
    // 0x800A8B94: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x800A8B98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8B9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800A8BA0: jr          $ra
    // 0x800A8BA4: nop

    return;
    // 0x800A8BA4: nop

;}
RECOMP_FUNC void func_808036C8_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808036CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808036D0: jal         0x80100094
    // 0x808036D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808036D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808036D8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808036DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808036E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808036E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808036E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808036EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808036F0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808036F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808036F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808036FC: sb          $t6, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r14;
    // 0x80803700: sh          $t7, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = ctx->r15;
    // 0x80803704: addiu       $a0, $v0, 0x88
    ctx->r4 = ADD32(ctx->r2, 0X88);
    // 0x80803708: jal         0x80088FA0
    // 0x8080370C: swc1        $f4, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->f4.u32l;
    _mlwave_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080370C: swc1        $f4, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x80803710: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80803714: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x80803718: jal         0x80088FD8
    // 0x8080371C: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
    _mlwave_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x8080371C: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
    after_2:
    // 0x80803720: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80803724: jal         0x800BF744
    // 0x80803728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_3;
    // 0x80803728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080372C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803730: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803734: jr          $ra
    // 0x80803738: nop

    return;
    // 0x80803738: nop

;}
RECOMP_FUNC void func_808008D4_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808008D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008E4: jal         0x8008CABC
    // 0x808008E8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808008E8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x808008EC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808008F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F4: jal         0x8009D3A8
    // 0x808008F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x808008F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808008FC: jal         0x80800000
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsvan(rdram, ctx);
        goto after_2;
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800908: jal         0x8009BB24
    // 0x8080090C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_3;
    // 0x8080090C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80800910: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800914: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080091C: beq         $v0, $zero, L_8080093C
    if (ctx->r2 == 0) {
        // 0x80800920: nop
    
            goto L_8080093C;
    }
    // 0x80800920: nop

    // 0x80800924: beq         $v0, $at, L_80800964
    if (ctx->r2 == ctx->r1) {
        // 0x80800928: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800964;
    }
    // 0x80800928: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080092C: beq         $v0, $at, L_808009A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800930: nop
    
            goto L_808009A0;
    }
    // 0x80800930: nop

    // 0x80800934: b           L_808009A0
    // 0x80800938: nop

        goto L_808009A0;
    // 0x80800938: nop

L_8080093C:
    // 0x8080093C: jal         0x8008DF8C
    // 0x80800940: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_4;
    // 0x80800940: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_4:
    // 0x80800944: beq         $v0, $zero, L_808009A0
    if (ctx->r2 == 0) {
        // 0x80800948: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009A0;
    }
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080094C: lui         $a1, 0x3F31
    ctx->r5 = S32(0X3F31 << 16);
    // 0x80800950: jal         0x8008CED4
    // 0x80800954: ori         $a1, $a1, 0xA36E
    ctx->r5 = ctx->r5 | 0XA36E;
    baanim_setEnd(rdram, ctx);
        goto after_5;
    // 0x80800954: ori         $a1, $a1, 0xA36E
    ctx->r5 = ctx->r5 | 0XA36E;
    after_5:
    // 0x80800958: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080095C: b           L_808009A0
    // 0x80800960: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_808009A0;
    // 0x80800960: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800964:
    // 0x80800964: jal         0x8008E078
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_6;
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080096C: beq         $v0, $zero, L_808009A0
    if (ctx->r2 == 0) {
        // 0x80800970: nop
    
            goto L_808009A0;
    }
    // 0x80800970: nop

    // 0x80800974: jal         0x800A2EAC
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2EAC(rdram, ctx);
        goto after_7;
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800980: jal         0x8009B9B0
    // 0x80800984: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x80800984: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080098C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800990: jal         0x8008CF1C
    // 0x80800994: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_9;
    // 0x80800994: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x80800998: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8080099C: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_808009A0:
    // 0x808009A0: jal         0x8008E078
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_10;
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808009A8: beq         $v0, $zero, L_80800A04
    if (ctx->r2 == 0) {
        // 0x808009AC: nop
    
            goto L_80800A04;
    }
    // 0x808009AC: nop

    // 0x808009B0: jal         0x8009EF10
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_11;
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808009B8: bgtzl       $v0, L_808009E0
    if (SIGNED(ctx->r2) > 0) {
        // 0x808009BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009E0;
    }
    goto skip_0;
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808009C0: lw          $t8, 0x15C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X15C);
    // 0x808009C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808009C8: bne         $t8, $at, L_80800A04
    if (ctx->r24 != ctx->r1) {
        // 0x808009CC: nop
    
            goto L_80800A04;
    }
    // 0x808009CC: nop

    // 0x808009D0: jal         0x8008B324
    // 0x808009D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_12;
    // 0x808009D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x808009D8: beq         $v0, $zero, L_80800A04
    if (ctx->r2 == 0) {
        // 0x808009DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A04;
    }
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009E0:
    // 0x808009E0: jal         0x80095738
    // 0x808009E4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    baflag_isTrue(rdram, ctx);
        goto after_13;
    // 0x808009E4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_13:
    // 0x808009E8: beq         $v0, $zero, L_80800A00
    if (ctx->r2 == 0) {
        // 0x808009EC: addiu       $t9, $zero, 0x11A
        ctx->r25 = ADD32(0, 0X11A);
            goto L_80800A00;
    }
    // 0x808009EC: addiu       $t9, $zero, 0x11A
    ctx->r25 = ADD32(0, 0X11A);
    // 0x808009F0: jal         0x800848C8
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_28(rdram, ctx);
        goto after_14;
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808009F8: b           L_80800A04
    // 0x808009FC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_80800A04;
    // 0x808009FC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80800A00:
    // 0x80800A00: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800A04:
    // 0x80800A04: jal         0x8008E35C
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_15;
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800A0C: beq         $v0, $zero, L_80800A18
    if (ctx->r2 == 0) {
        // 0x80800A10: addiu       $t0, $zero, 0x11D
        ctx->r8 = ADD32(0, 0X11D);
            goto L_80800A18;
    }
    // 0x80800A10: addiu       $t0, $zero, 0x11D
    ctx->r8 = ADD32(0, 0X11D);
    // 0x80800A14: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80800A18:
    // 0x80800A18: jal         0x808000BC
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000BC_bsvan(rdram, ctx);
        goto after_16;
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800A20: jal         0x808003BC
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsvan_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A2C: jal         0x8009E5C8
    // 0x80800A30: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_18;
    // 0x80800A30: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_18:
    // 0x80800A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A40: jr          $ra
    // 0x80800A44: nop

    return;
    // 0x80800A44: nop

;}
RECOMP_FUNC void chpickups_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0XA60) << 16);
    // 0x8080007C: jr          $ra
    // 0x80800080: addiu       $v0, $v0, 0xA60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0XA60));
    return;
    // 0x80800080: addiu       $v0, $v0, 0xA60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0XA60));
;}
RECOMP_FUNC void func_8009F860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F860: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8009F864: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8009F868: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8009F86C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009F870: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8009F874: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8009F878: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8009F87C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8009F880: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8009F884: jal         0x800A3148
    // 0x8009F888: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    func_800A3148(rdram, ctx);
        goto after_0;
    // 0x8009F888: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x8009F88C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8009F890: jal         0x800F4200
    // 0x8009F894: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F4200(rdram, ctx);
        goto after_1;
    // 0x8009F894: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x8009F898: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009F89C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009F8A0: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8009F8A4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8009F8A8: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009F8AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009F8B0: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8009F8B4: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8009F8B8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8009F8BC: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x8009F8C0: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009F8C4: add.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8009F8C8: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8009F8CC: add.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x8009F8D0: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8009F8D4: nop

    // 0x8009F8D8: bc1fl       L_8009F8EC
    if (!c1cs) {
        // 0x8009F8DC: add.s       $f10, $f2, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f6.fl;
            goto L_8009F8EC;
    }
    goto skip_0;
    // 0x8009F8DC: add.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f6.fl;
    skip_0:
    // 0x8009F8E0: b           L_8009FA0C
    // 0x8009F8E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009FA0C;
    // 0x8009F8E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009F8E8: add.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f6.fl;
L_8009F8EC:
    // 0x8009F8EC: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8009F8F0: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8009F8F4: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8009F8F8: nop

    // 0x8009F8FC: bc1fl       L_8009F910
    if (!c1cs) {
        // 0x8009F900: lwc1        $f4, 0x0($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8009F910;
    }
    goto skip_1;
    // 0x8009F900: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x8009F904: b           L_8009FA0C
    // 0x8009F908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009FA0C;
    // 0x8009F908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009F90C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
L_8009F910:
    // 0x8009F910: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8009F914: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009F918: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8009F91C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8009F920: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009F924: sub.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8009F928: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8009F92C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8009F930: jal         0x800EFA4C
    // 0x8009F934: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x8009F934: nop

    after_2:
    // 0x8009F938: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009F93C: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009F940: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009F944: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8009F948: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8009F94C: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009F950: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8009F954: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8009F958: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8009F95C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8009F960: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8009F964: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8009F968: add.s       $f20, $f16, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8009F96C: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x8009F970: nop

    // 0x8009F974: bc1f        L_8009F984
    if (!c1cs) {
        // 0x8009F978: nop
    
            goto L_8009F984;
    }
    // 0x8009F978: nop

    // 0x8009F97C: b           L_8009FA0C
    // 0x8009F980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009FA0C;
    // 0x8009F980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009F984:
    // 0x8009F984: jal         0x8002DCA0
    // 0x8009F988: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8009F988: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8009F98C: jal         0x800D8FF8
    // 0x8009F990: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x8009F990: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_4:
    // 0x8009F994: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8009F998: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8009F99C: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8009F9A0: jal         0x800F13F0
    // 0x8009F9A4: sub.s       $f14, $f16, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f20.fl;
    func_800F13F0(rdram, ctx);
        goto after_5;
    // 0x8009F9A4: sub.s       $f14, $f16, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f20.fl;
    after_5:
    // 0x8009F9A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009F9AC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8009F9B0: c.eq.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl == ctx->f6.fl;
    // 0x8009F9B4: nop

    // 0x8009F9B8: bc1fl       L_8009F9E8
    if (!c1cs) {
        // 0x8009F9BC: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_8009F9E8;
    }
    goto skip_2;
    // 0x8009F9BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    skip_2:
    // 0x8009F9C0: jal         0x800DC0C0
    // 0x8009F9C4: nop

    func_800DC0C0(rdram, ctx);
        goto after_6;
    // 0x8009F9C4: nop

    after_6:
    // 0x8009F9C8: jal         0x800DC0C0
    // 0x8009F9CC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x8009F9CC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_7:
    // 0x8009F9D0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8009F9D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009F9D8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8009F9DC: jal         0x800EFA4C
    // 0x8009F9E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x8009F9E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x8009F9E4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_8009F9E8:
    // 0x8009F9E8: jal         0x800EF368
    // 0x8009F9EC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800EF368(rdram, ctx);
        goto after_9;
    // 0x8009F9EC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x8009F9F0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8009F9F4: jal         0x800EF04C
    // 0x8009F9F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x8009F9F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_10:
    // 0x8009F9FC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8009FA00: jal         0x800F4648
    // 0x8009FA04: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F4648(rdram, ctx);
        goto after_11;
    // 0x8009FA04: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_11:
    // 0x8009FA08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009FA0C:
    // 0x8009FA0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009FA10: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8009FA14: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8009FA18: jr          $ra
    // 0x8009FA1C: nop

    return;
    // 0x8009FA1C: nop

;}
RECOMP_FUNC void chbounce_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void _chbaddieDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085928: syscall     181
    recomp_syscall_handler(rdram, ctx, 0x80085928);
    return;
    // 0x8008592C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8010BCC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BCC8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010BCCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010BCD0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8010BCD4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8010BCD8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8010BCDC: lhu         $t6, 0x62($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X62);
    // 0x8010BCE0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8010BCE4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8010BCE8: bne         $t6, $zero, L_8010BCF8
    if (ctx->r14 != 0) {
        // 0x8010BCEC: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_8010BCF8;
    }
    // 0x8010BCEC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8010BCF0: b           L_8010BD9C
    // 0x8010BCF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010BD9C;
    // 0x8010BCF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010BCF8:
    // 0x8010BCF8: jal         0x800EE7F8
    // 0x8010BCFC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8010BCFC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x8010BD00: lh          $t7, 0x88($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X88);
    // 0x8010BD04: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8010BD08: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8010BD0C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8010BD10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010BD14: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010BD18: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8010BD1C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8010BD20: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8010BD24: lh          $t9, 0x88($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X88);
    // 0x8010BD28: lh          $t8, 0x8A($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X8A);
    // 0x8010BD2C: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8010BD30: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8010BD34: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8010BD38: nop

    // 0x8010BD3C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010BD40: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8010BD44: jal         0x8010A40C
    // 0x8010BD48: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    func_8010A40C(rdram, ctx);
        goto after_1;
    // 0x8010BD48: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8010BD4C: lhu         $t1, 0x62($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X62);
    // 0x8010BD50: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8010BD54: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8010BD58: bgez        $t1, L_8010BD6C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8010BD5C: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8010BD6C;
    }
    // 0x8010BD5C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010BD60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010BD64: nop

    // 0x8010BD68: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_8010BD6C:
    // 0x8010BD6C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8010BD70: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8010BD74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010BD78: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8010BD7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010BD80: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8010BD84: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8010BD88: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8010BD8C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8010BD90: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010BD94: jal         0x8010BB5C
    // 0x8010BD98: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8010BB5C(rdram, ctx);
        goto after_2;
    // 0x8010BD98: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_2:
L_8010BD9C:
    // 0x8010BD9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010BDA0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8010BDA4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8010BDA8: jr          $ra
    // 0x8010BDAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8010BDAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800BD0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD0DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BD0E0: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BD0E4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BD0E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD0EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BD0F0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800BD0F4: jal         0x8001ACCC
    // 0x800BD0F8: addiu       $a0, $t6, 0x2C
    ctx->r4 = ADD32(ctx->r14, 0X2C);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800BD0F8: addiu       $a0, $t6, 0x2C
    ctx->r4 = ADD32(ctx->r14, 0X2C);
    after_0:
    // 0x800BD0FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BD100: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x800BD104: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800BD108: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800BD10C: sb          $t8, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r24;
    // 0x800BD110: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x800BD114: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800BD118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800BD11C: jal         0x800BD138
    // 0x800BD120: sb          $t9, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r25;
    func_800BD138(rdram, ctx);
        goto after_1;
    // 0x800BD120: sb          $t9, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r25;
    after_1:
    // 0x800BD124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD128: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD12C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BD130: jr          $ra
    // 0x800BD134: nop

    return;
    // 0x800BD134: nop

;}
RECOMP_FUNC void func_80800200_chclimbbase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800204: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800208: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080020C: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800210: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800214: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800218: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080021C: addiu       $t8, $t7, 0x19
    ctx->r24 = ADD32(ctx->r15, 0X19);
    // 0x80800220: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80800224: nop

    // 0x80800228: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080022C: jal         0x8010D254
    // 0x80800230: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800230: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80800234: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800238: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8080023C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800240: jal         0x800EFB24
    // 0x80800244: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x80800244: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80800248: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8080024C: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800250: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800254: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800258: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080025C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800260: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800264: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80800268: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8080026C: nop

    // 0x80800270: bc1fl       L_8080037C
    if (!c1cs) {
        // 0x80800274: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080037C;
    }
    goto skip_0;
    // 0x80800274: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800278: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080027C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800280: nop

    // 0x80800284: bc1fl       L_8080037C
    if (!c1cs) {
        // 0x80800288: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080037C;
    }
    goto skip_1;
    // 0x80800288: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8080028C: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800290: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x80800294: nop

    // 0x80800298: bc1fl       L_8080037C
    if (!c1cs) {
        // 0x8080029C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080037C;
    }
    goto skip_2;
    // 0x8080029C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x808002A0: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x808002A4: addiu       $at, $zero, 0x16E
    ctx->r1 = ADD32(0, 0X16E);
    // 0x808002A8: sll         $t9, $v0, 11
    ctx->r25 = S32(ctx->r2 << 11);
    // 0x808002AC: srl         $t0, $t9, 20
    ctx->r8 = S32(U32(ctx->r25) >> 20);
    // 0x808002B0: beq         $t0, $at, L_8080031C
    if (ctx->r8 == ctx->r1) {
        // 0x808002B4: addiu       $at, $zero, 0x1F9
        ctx->r1 = ADD32(0, 0X1F9);
            goto L_8080031C;
    }
    // 0x808002B4: addiu       $at, $zero, 0x1F9
    ctx->r1 = ADD32(0, 0X1F9);
    // 0x808002B8: bnel        $t0, $at, L_8080037C
    if (ctx->r8 != ctx->r1) {
        // 0x808002BC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080037C;
    }
    goto skip_3;
    // 0x808002BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808002C0: jal         0x800F54E4
    // 0x808002C4: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808002C4: nop

    after_2:
    // 0x808002C8: lhu         $t1, 0x76($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X76);
    // 0x808002CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808002D4: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x808002D8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x808002DC: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x808002E0: bgez        $t2, L_808002F8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808002E4: cvt.s.w     $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
            goto L_808002F8;
    }
    // 0x808002E4: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808002E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808002EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808002F0: nop

    // 0x808002F4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_808002F8:
    // 0x808002F8: lw          $t3, 0x6C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X6C);
    // 0x808002FC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800300: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80800304: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800308: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8080030C: jal         0x800F7F50
    // 0x80800310: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_800F7F50(rdram, ctx);
        goto after_3;
    // 0x80800310: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_3:
    // 0x80800314: b           L_8080037C
    // 0x80800318: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8080037C;
    // 0x80800318: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080031C:
    // 0x8080031C: jal         0x800F54E4
    // 0x80800320: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800320: nop

    after_4:
    // 0x80800324: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080032C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800330: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800334: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80800338: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x8080033C: bgez        $t7, L_80800354
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800340: cvt.s.w     $f18, $f18
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80800354;
    }
    // 0x80800340: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800344: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800348: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080034C: nop

    // 0x80800350: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80800354:
    // 0x80800354: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
    // 0x80800358: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8080035C: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800360: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800364: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80800368: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8080036C: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800370: jal         0x800F7F00
    // 0x80800374: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800F7F00(rdram, ctx);
        goto after_5;
    // 0x80800374: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80800378: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080037C:
    // 0x8080037C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800380: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800384: jr          $ra
    // 0x80800388: nop

    return;
    // 0x80800388: nop

;}
RECOMP_FUNC void func_80800000_chweather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800008: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void bsbwhirl_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D84: jal         0x80800200
    // 0x80800D88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800200_bsbwhirl(rdram, ctx);
        goto after_0;
    // 0x80800D88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D8C: jal         0x80800008
    // 0x80800D90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800008_bsbwhirl(rdram, ctx);
        goto after_1;
    // 0x80800D90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D94: jal         0x80082FE8
    // 0x80800D98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800D98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DA4: jr          $ra
    // 0x80800DA8: nop

    return;
    // 0x80800DA8: nop

;}
RECOMP_FUNC void chlensflare_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800678: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2296, 0X928) << 16);
    // 0x8080067C: jr          $ra
    // 0x80800680: addiu       $v0, $v0, 0x928
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2296, 0X928));
    return;
    // 0x80800680: addiu       $v0, $v0, 0x928
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2296, 0X928));
    // 0x80800684: nop

    // 0x80800688: nop

    // 0x8080068C: nop

;}
RECOMP_FUNC void func_8080070C_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080070C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800710: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800714: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080071C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800720: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800724: jal         0x8001210C
    // 0x80800728: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80800728: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x8080072C: bne         $v0, $zero, L_80800760
    if (ctx->r2 != 0) {
        // 0x80800730: nop
    
            goto L_80800760;
    }
    // 0x80800730: nop

    // 0x80800734: jal         0x800DC0C0
    // 0x80800738: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80800738: nop

    after_1:
    // 0x8080073C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800740: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800748: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080074C: nop

    // 0x80800750: bc1f        L_80800760
    if (!c1cs) {
        // 0x80800754: nop
    
            goto L_80800760;
    }
    // 0x80800754: nop

    // 0x80800758: jal         0x8009FC34
    // 0x8080075C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009FC34(rdram, ctx);
        goto after_2;
    // 0x8080075C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800760:
    // 0x80800760: jal         0x8009EF10
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_3;
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800768: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080076C: bne         $v0, $at, L_80800778
    if (ctx->r2 != ctx->r1) {
        // 0x80800770: nop
    
            goto L_80800778;
    }
    // 0x80800770: nop

    // 0x80800774: addiu       $s1, $zero, 0x15E
    ctx->r17 = ADD32(0, 0X15E);
L_80800778:
    // 0x80800778: jal         0x8008E35C
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_4;
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800780: bne         $v0, $zero, L_8080078C
    if (ctx->r2 != 0) {
        // 0x80800784: nop
    
            goto L_8080078C;
    }
    // 0x80800784: nop

    // 0x80800788: addiu       $s1, $zero, 0xBB
    ctx->r17 = ADD32(0, 0XBB);
L_8080078C:
    // 0x8080078C: jal         0x80097AD0
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_5;
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800794: beql        $v0, $zero, L_808007AC
    if (ctx->r2 == 0) {
        // 0x80800798: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007AC;
    }
    goto skip_0;
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080079C: jal         0x800848A8
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_6;
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808007A4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007AC:
    // 0x808007AC: jal         0x80091A58
    // 0x808007B0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_7;
    // 0x808007B0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_7:
    // 0x808007B4: beq         $v0, $zero, L_808007C0
    if (ctx->r2 == 0) {
        // 0x808007B8: nop
    
            goto L_808007C0;
    }
    // 0x808007B8: nop

    // 0x808007BC: addiu       $s1, $zero, 0x15F
    ctx->r17 = ADD32(0, 0X15F);
L_808007C0:
    // 0x808007C0: jal         0x80096500
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096500(rdram, ctx);
        goto after_8;
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808007C8: beq         $v0, $zero, L_808007E4
    if (ctx->r2 == 0) {
        // 0x808007CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007E4;
    }
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D0: jal         0x80091A58
    // 0x808007D4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_9;
    // 0x808007D4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x808007D8: beql        $v0, $zero, L_808007E8
    if (ctx->r2 == 0) {
        // 0x808007DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007E8;
    }
    goto skip_1;
    // 0x808007DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808007E0: addiu       $s1, $zero, 0xBD
    ctx->r17 = ADD32(0, 0XBD);
L_808007E4:
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007E8:
    // 0x808007E8: jal         0x8009E5C8
    // 0x808007EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x808007EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x808007F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808007F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808007FC: jr          $ra
    // 0x80800800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8009B3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B3B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B3BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B3C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009B3C4: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B3C8: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x8009B3CC: jal         0x800EE7F8
    // 0x8009B3D0: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009B3D0: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    after_0:
    // 0x8009B3D4: jal         0x800D8FF8
    // 0x8009B3D8: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8009B3D8: nop

    after_1:
    // 0x8009B3DC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8009B3E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009B3E4: lw          $a0, 0xC8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC8);
    // 0x8009B3E8: jal         0x800EF334
    // 0x8009B3EC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EF334(rdram, ctx);
        goto after_2;
    // 0x8009B3EC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_2:
    // 0x8009B3F0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8009B3F4: lw          $v0, 0xC8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0XC8);
    // 0x8009B3F8: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8009B3FC: jal         0x800EF04C
    // 0x8009B400: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x8009B400: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    after_3:
    // 0x8009B404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B40C: jr          $ra
    // 0x8009B410: nop

    return;
    // 0x8009B410: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801104: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801108: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080110C: jal         0x80800060
    // 0x80801110: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80801110: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801114: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801118: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080111C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801120: jal         0x80084468
    // 0x80801124: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _baattach_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80801124: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80801128: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x8080112C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801130: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801134: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    // 0x80801138: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8080113C: jal         0x80085150
    // 0x80801140: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _baspin_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80801140: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80801144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080114C: jr          $ra
    // 0x80801150: nop

    return;
    // 0x80801150: nop

;}
RECOMP_FUNC void _glhittableDll_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088658: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088658);
    return;
    // 0x8008865C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800718_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800718: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080071C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800720: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800724: jal         0x800EB854
    // 0x80800728: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EB854(rdram, ctx);
        goto after_0;
    // 0x80800728: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080072C: beq         $v0, $zero, L_80800750
    if (ctx->r2 == 0) {
        // 0x80800730: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800750;
    }
    // 0x80800730: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800734: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800738: beq         $v0, $at, L_80800750
    if (ctx->r2 == ctx->r1) {
        // 0x8080073C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800750;
    }
    // 0x8080073C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800740: beq         $v0, $at, L_8080079C
    if (ctx->r2 == ctx->r1) {
        // 0x80800744: nop
    
            goto L_8080079C;
    }
    // 0x80800744: nop

    // 0x80800748: b           L_808007A8
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007A8;
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800750:
    // 0x80800750: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80800754: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80800758: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x8080075C: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x80800760: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800764: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80800768: lbu         $t8, 0x13($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X13);
    // 0x8080076C: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80800770: jal         0x80101808
    // 0x80800774: sb          $t9, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r25;
    func_80101808(rdram, ctx);
        goto after_1;
    // 0x80800774: sb          $t9, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r25;
    after_1:
    // 0x80800778: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080077C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80800780: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80800784: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80800788: lbu         $t3, 0x13($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X13);
    // 0x8080078C: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x80800790: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800794: b           L_808007A4
    // 0x80800798: sb          $t5, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r13;
        goto L_808007A4;
    // 0x80800798: sb          $t5, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r13;
L_8080079C:
    // 0x8080079C: jal         0x808007B4
    // 0x808007A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808007B4_chevilspirit(rdram, ctx);
        goto after_2;
    // 0x808007A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
L_808007A4:
    // 0x808007A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007A8:
    // 0x808007A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007AC: jr          $ra
    // 0x808007B0: nop

    return;
    // 0x808007B0: nop

;}
RECOMP_FUNC void chmolehill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800698: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080069C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808006A8: lbu         $t0, 0x79($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X79);
    // 0x808006AC: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x808006B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006B4: andi        $t1, $t0, 0xFF0F
    ctx->r9 = ctx->r8 & 0XFF0F;
    // 0x808006B8: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808006BC: andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // 0x808006C0: srl         $t3, $v0, 4
    ctx->r11 = S32(U32(ctx->r2) >> 4);
    // 0x808006C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006C8: beq         $t3, $at, L_808006EC
    if (ctx->r11 == ctx->r1) {
        // 0x808006CC: sb          $t2, 0x79($a0)
        MEM_B(0X79, ctx->r4) = ctx->r10;
            goto L_808006EC;
    }
    // 0x808006CC: sb          $t2, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r10;
    // 0x808006D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006D4: beq         $t3, $at, L_808006EC
    if (ctx->r11 == ctx->r1) {
        // 0x808006D8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_808006EC;
    }
    // 0x808006D8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808006DC: beq         $t3, $at, L_8080070C
    if (ctx->r11 == ctx->r1) {
        // 0x808006E0: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8080070C;
    }
    // 0x808006E0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808006E4: b           L_8080072C
    // 0x808006E8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
        goto L_8080072C;
    // 0x808006E8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
L_808006EC:
    // 0x808006EC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808006F0: addiu       $a0, $a0, 0x6910
    ctx->r4 = ADD32(ctx->r4, 0X6910);
    // 0x808006F4: jal         0x80086D30
    // 0x808006F8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808006F8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x808006FC: jal         0x8080058C
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080058C_chmolehill(rdram, ctx);
        goto after_1;
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800704: b           L_8080072C
    // 0x80800708: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
        goto L_8080072C;
    // 0x80800708: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
L_8080070C:
    // 0x8080070C: lbu         $t4, 0x72($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X72);
    // 0x80800710: addiu       $a0, $a0, 0x6910
    ctx->r4 = ADD32(ctx->r4, 0X6910);
    // 0x80800714: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800718: andi        $t5, $t4, 0xFF03
    ctx->r13 = ctx->r12 & 0XFF03;
    // 0x8080071C: ori         $t6, $t5, 0x34
    ctx->r14 = ctx->r13 | 0X34;
    // 0x80800720: jal         0x80086D30
    // 0x80800724: sb          $t6, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r14;
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800724: sb          $t6, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r14;
    after_2:
    // 0x80800728: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
L_8080072C:
    // 0x8080072C: beql        $a0, $zero, L_8080074C
    if (ctx->r4 == 0) {
        // 0x80800730: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080074C;
    }
    goto skip_0;
    // 0x80800730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800734: jal         0x80106790
    // 0x80800738: nop

    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80800738: nop

    after_3:
    // 0x8080073C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800740: jal         0x800868F8
    // 0x80800744: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _chmoley_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800744: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080074C:
    // 0x8080074C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800754: jr          $ra
    // 0x80800758: nop

    return;
    // 0x80800758: nop

;}
RECOMP_FUNC void func_80800724_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800724: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800728: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8080072C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800730: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800734: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800738: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080073C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800740: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x80800744: jal         0x80100094
    // 0x80800748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080074C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800750: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800754: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800758: beq         $a2, $at, L_80800A48
    if (ctx->r6 == ctx->r1) {
        // 0x8080075C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_80800A48;
    }
    // 0x8080075C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800760: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800764: beq         $a2, $at, L_808009BC
    if (ctx->r6 == ctx->r1) {
        // 0x80800768: addiu       $v0, $sp, 0x40
        ctx->r2 = ADD32(ctx->r29, 0X40);
            goto L_808009BC;
    }
    // 0x80800768: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x8080076C: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80800770: beq         $a2, $at, L_808009EC
    if (ctx->r6 == ctx->r1) {
        // 0x80800774: addiu       $v0, $sp, 0x40
        ctx->r2 = ADD32(ctx->r29, 0X40);
            goto L_808009EC;
    }
    // 0x80800774: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80800778: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x8080077C: beq         $a2, $at, L_808009D4
    if (ctx->r6 == ctx->r1) {
        // 0x80800780: addiu       $v0, $sp, 0x40
        ctx->r2 = ADD32(ctx->r29, 0X40);
            goto L_808009D4;
    }
    // 0x80800780: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80800784: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800788: beq         $a2, $at, L_80800974
    if (ctx->r6 == ctx->r1) {
        // 0x8080078C: addiu       $at, $zero, 0x57
        ctx->r1 = ADD32(0, 0X57);
            goto L_80800974;
    }
    // 0x8080078C: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80800790: beq         $a2, $at, L_80800A58
    if (ctx->r6 == ctx->r1) {
        // 0x80800794: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_80800A58;
    }
    // 0x80800794: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800798: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080079C: beq         $a2, $at, L_808007B8
    if (ctx->r6 == ctx->r1) {
        // 0x808007A0: addiu       $a0, $zero, 0x4B
        ctx->r4 = ADD32(0, 0X4B);
            goto L_808007B8;
    }
    // 0x808007A0: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x808007A4: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x808007A8: beq         $a2, $at, L_80800A84
    if (ctx->r6 == ctx->r1) {
        // 0x808007AC: nop
    
            goto L_80800A84;
    }
    // 0x808007AC: nop

    // 0x808007B0: b           L_80800AE4
    // 0x808007B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AE4;
    // 0x808007B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007B8:
    // 0x808007B8: jal         0x800D0A9C
    // 0x808007BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x808007BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808007C0: beq         $v0, $zero, L_808007D4
    if (ctx->r2 == 0) {
        // 0x808007C4: addiu       $a0, $zero, 0x4B
        ctx->r4 = ADD32(0, 0X4B);
            goto L_808007D4;
    }
    // 0x808007C4: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x808007C8: jal         0x800D0B68
    // 0x808007CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x808007CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808007D0: beq         $v0, $zero, L_808007F4
    if (ctx->r2 == 0) {
        // 0x808007D4: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_808007F4;
    }
L_808007D4:
    // 0x808007D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x808007D8: jal         0x800D0A9C
    // 0x808007DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_3;
    // 0x808007DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x808007E0: beq         $v0, $zero, L_80800814
    if (ctx->r2 == 0) {
        // 0x808007E4: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_80800814;
    }
    // 0x808007E4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x808007E8: jal         0x800D0B68
    // 0x808007EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0B68(rdram, ctx);
        goto after_4;
    // 0x808007EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x808007F0: bne         $v0, $zero, L_80800814
    if (ctx->r2 != 0) {
        // 0x808007F4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800814;
    }
L_808007F4:
    // 0x808007F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808007F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800800: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800804: jal         0x80101FDC
    // 0x80800808: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800808: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x8080080C: b           L_80800AE4
    // 0x80800810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AE4;
    // 0x80800810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800814:
    // 0x80800814: jal         0x80090708
    // 0x80800818: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_6;
    // 0x80800818: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8080081C: jal         0x800D395C
    // 0x80800820: nop

    func_800D395C(rdram, ctx);
        goto after_7;
    // 0x80800820: nop

    after_7:
    // 0x80800824: beq         $v0, $zero, L_80800868
    if (ctx->r2 == 0) {
        // 0x80800828: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800868;
    }
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800830: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800834: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800838: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080083C: jal         0x8008A2C8
    // 0x80800840: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x80800840: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_8:
    // 0x80800844: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800848: addiu       $t6, $zero, 0x99
    ctx->r14 = ADD32(0, 0X99);
    // 0x8080084C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800850: addiu       $a1, $zero, 0x144D
    ctx->r5 = ADD32(0, 0X144D);
    // 0x80800854: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800858: jal         0x8008A208
    // 0x8080085C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x8080085C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80800860: b           L_80800964
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800964;
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800868:
    // 0x80800868: jal         0x800DA298
    // 0x8080086C: addiu       $a0, $zero, 0x6E6
    ctx->r4 = ADD32(0, 0X6E6);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x8080086C: addiu       $a0, $zero, 0x6E6
    ctx->r4 = ADD32(0, 0X6E6);
    after_10:
    // 0x80800870: beq         $v0, $zero, L_808008E8
    if (ctx->r2 == 0) {
        // 0x80800874: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008E8;
    }
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800878: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800884: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800888: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080088C: jal         0x8008A2C8
    // 0x80800890: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_11;
    // 0x80800890: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_11:
    // 0x80800894: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80800898: jal         0x800D0A9C
    // 0x8080089C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_12;
    // 0x8080089C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808008A0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808008A4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x808008A8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x808008AC: jal         0x800D0A9C
    // 0x808008B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_13;
    // 0x808008B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x808008B4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808008B8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808008BC: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x808008C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808008C4: addiu       $t1, $zero, 0x99
    ctx->r9 = ADD32(0, 0X99);
    // 0x808008C8: subu        $a1, $t9, $t0
    ctx->r5 = SUB32(ctx->r25, ctx->r8);
    // 0x808008CC: addiu       $a1, $a1, 0x144B
    ctx->r5 = ADD32(ctx->r5, 0X144B);
    // 0x808008D0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808008D4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808008D8: jal         0x8008A208
    // 0x808008DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x808008DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x808008E0: b           L_80800964
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800964;
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008E8:
    // 0x808008E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808008EC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x808008F0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x808008F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808008F8: jal         0x8008A2D0
    // 0x808008FC: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x808008FC: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_15:
    // 0x80800900: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80800904: jal         0x800D0A9C
    // 0x80800908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_16;
    // 0x80800908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x8080090C: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800910: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80800914: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80800918: jal         0x800D0A9C
    // 0x8080091C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_17;
    // 0x8080091C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
    // 0x80800920: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80800924: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800928: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8080092C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800930: addiu       $t6, $zero, 0x99
    ctx->r14 = ADD32(0, 0X99);
    // 0x80800934: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    // 0x80800938: addiu       $a1, $a1, 0x1407
    ctx->r5 = ADD32(ctx->r5, 0X1407);
    // 0x8080093C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800940: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800944: jal         0x8008A208
    // 0x80800948: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x80800948: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x8080094C: jal         0x800DA544
    // 0x80800950: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_19;
    // 0x80800950: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800958: jal         0x80108B04
    // 0x8080095C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_20;
    // 0x8080095C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800964:
    // 0x80800964: jal         0x80800018
    // 0x80800968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800018_chwaspnestgame(rdram, ctx);
        goto after_21;
    // 0x80800968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x8080096C: b           L_80800AE4
    // 0x80800970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AE4;
    // 0x80800970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800974:
    // 0x80800974: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080097C: blez        $a2, L_80800994
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800980: nop
    
            goto L_80800994;
    }
    // 0x80800980: nop

    // 0x80800984: jal         0x80800C7C
    // 0x80800988: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800C7C_chwaspnestgame(rdram, ctx);
        goto after_22;
    // 0x80800988: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_22:
    // 0x8080098C: b           L_80800AE4
    // 0x80800990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AE4;
    // 0x80800990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800994:
    // 0x80800994: bgez        $a2, L_808009AC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80800998: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009AC;
    }
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080099C: jal         0x80800D7C
    // 0x808009A0: negu        $a1, $a2
    ctx->r5 = SUB32(0, ctx->r6);
    func_80800D7C_chwaspnestgame(rdram, ctx);
        goto after_23;
    // 0x808009A0: negu        $a1, $a2
    ctx->r5 = SUB32(0, ctx->r6);
    after_23:
    // 0x808009A4: b           L_80800AE4
    // 0x808009A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AE4;
    // 0x808009A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009AC:
    // 0x808009AC: jal         0x80800B80
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B80_chwaspnestgame(rdram, ctx);
        goto after_24;
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808009B4: b           L_80800AE4
    // 0x808009B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AE4;
    // 0x808009B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009BC:
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808009C4: jal         0x80800F98
    // 0x808009C8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80800F98_chwaspnestgame(rdram, ctx);
        goto after_25;
    // 0x808009C8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_25:
    // 0x808009CC: b           L_80800AE4
    // 0x808009D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AE4;
    // 0x808009D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009D4:
    // 0x808009D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D8: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808009DC: jal         0x80800EB8
    // 0x808009E0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80800EB8_chwaspnestgame(rdram, ctx);
        goto after_26;
    // 0x808009E0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_26:
    // 0x808009E4: b           L_80800AE8
    // 0x808009E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AE8;
    // 0x808009E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009EC:
    // 0x808009EC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x808009F0: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    // 0x808009F4: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x808009F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808009FC: jal         0x80101180
    // 0x80800A00: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    func_80101180(rdram, ctx);
        goto after_27;
    // 0x80800A00: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    after_27:
    // 0x80800A04: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800A08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800A0C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(776, 0X1F76) << 16);
    // 0x80800A10: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80800A14: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80800A18: lh          $a2, 0x1F76($a2)
    ctx->r6 = MEM_H(ctx->r6, (int16_t)RELOC_LO16(776, 0X1F76));
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A20: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800A24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800A28: jal         0x8008A2D0
    // 0x80800A2C: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_28;
    // 0x80800A2C: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_28:
    // 0x80800A30: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A38: jal         0x80108B04
    // 0x80800A3C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    func_80108B04(rdram, ctx);
        goto after_29;
    // 0x80800A3C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_29:
    // 0x80800A40: b           L_80800AE4
    // 0x80800A44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AE4;
    // 0x80800A44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A48:
    // 0x80800A48: jal         0x80800DE4
    // 0x80800A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DE4_chwaspnestgame(rdram, ctx);
        goto after_30;
    // 0x80800A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800A50: b           L_80800AE8
    // 0x80800A54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AE8;
    // 0x80800A54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A58:
    // 0x80800A58: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800A5C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800A60: and         $a3, $v0, $at
    ctx->r7 = ctx->r2 & ctx->r1;
    // 0x80800A64: srl         $t0, $a3, 16
    ctx->r8 = S32(U32(ctx->r7) >> 16);
    // 0x80800A68: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A70: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x80800A74: jal         0x8008A2B8
    // 0x80800A78: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_31;
    // 0x80800A78: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_31:
    // 0x80800A7C: b           L_80800AE8
    // 0x80800A80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AE8;
    // 0x80800A80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A84:
    // 0x80800A84: jal         0x800D395C
    // 0x80800A88: nop

    func_800D395C(rdram, ctx);
        goto after_32;
    // 0x80800A88: nop

    after_32:
    // 0x80800A8C: bne         $v0, $zero, L_80800A9C
    if (ctx->r2 != 0) {
        // 0x80800A90: addiu       $a0, $zero, 0x1E4
        ctx->r4 = ADD32(0, 0X1E4);
            goto L_80800A9C;
    }
    // 0x80800A90: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    // 0x80800A94: b           L_80800AE4
    // 0x80800A98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AE4;
    // 0x80800A98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A9C:
    // 0x80800A9C: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x80800AA0: jal         0x80101180
    // 0x80800AA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_33;
    // 0x80800AA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_33:
    // 0x80800AA8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800AAC: addiu       $t1, $zero, 0x99
    ctx->r9 = ADD32(0, 0X99);
    // 0x80800AB0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800AB4: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800AB8: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800ABC: jal         0x8008A208
    // 0x80800AC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_34;
    // 0x80800AC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_34:
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC8: jal         0x80101FDC
    // 0x80800ACC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_35;
    // 0x80800ACC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_35:
    // 0x80800AD0: b           L_80800AE4
    // 0x80800AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AE4;
    // 0x80800AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800AD8: b           L_80800AE4
    // 0x80800ADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AE4;
    // 0x80800ADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AE4:
    // 0x80800AE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800AE8:
    // 0x80800AE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800AEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800AF0: jr          $ra
    // 0x80800AF4: nop

    return;
    // 0x80800AF4: nop

;}
RECOMP_FUNC void func_80800180_chdrawbridgeswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800188: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080018C: addiu       $a1, $zero, 0x58E
    ctx->r5 = ADD32(0, 0X58E);
    // 0x80800190: jal         0x80800000
    // 0x80800194: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chdrawbridgeswitches(rdram, ctx);
        goto after_0;
    // 0x80800194: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800198: jal         0x80085818
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void _ncbaspline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089398: syscall     776
    recomp_syscall_handler(rdram, ctx, 0x80089398);
    return;
    // 0x8008939C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chfantasylakebits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087670: syscall     602
    recomp_syscall_handler(rdram, ctx, 0x80087670);
    return;
    // 0x80087674: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800000_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800008: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(208, 0X11F0) << 16);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800014: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800018: addiu       $t6, $t6, 0x11F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(208, 0X11F0));
    // 0x8080001C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080002C: jal         0x800BABB8
    // 0x80800030: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80800030: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80800034: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800038: jal         0x800BA3FC
    // 0x8080003C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800BA3FC(rdram, ctx);
        goto after_1;
    // 0x8080003C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800044: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void func_8008BBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BBC0: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8008BBC4: beq         $at, $zero, L_8008BBE8
    if (ctx->r1 == 0) {
        // 0x8008BBC8: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8008BBE8;
    }
    // 0x8008BBC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8008BBCC:
    // 0x8008BBCC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8008BBD0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8008BBD4: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8008BBD8: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8008BBDC: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x8008BBE0: bne         $at, $zero, L_8008BBCC
    if (ctx->r1 != 0) {
        // 0x8008BBE4: sh          $t6, -0x4($v0)
        MEM_H(-0X4, ctx->r2) = ctx->r14;
            goto L_8008BBCC;
    }
    // 0x8008BBE4: sh          $t6, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r14;
L_8008BBE8:
    // 0x8008BBE8: jr          $ra
    // 0x8008BBEC: nop

    return;
    // 0x8008BBEC: nop

;}
RECOMP_FUNC void bastick_getY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EF34: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009EF38: jr          $ra
    // 0x8009EF3C: lwc1        $f0, 0x58($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X58);
    return;
    // 0x8009EF3C: lwc1        $f0, 0x58($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X58);
;}
RECOMP_FUNC void func_80800874_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080087C: jal         0x8080081C
    // 0x80800880: nop

    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800880: nop

    after_0:
    // 0x80800884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080088C: jr          $ra
    // 0x80800890: nop

    return;
    // 0x80800890: nop

;}
RECOMP_FUNC void func_808000E8_bsclimb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000F4: jal         0x8009861C
    // 0x808000F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009861C(rdram, ctx);
        goto after_0;
    // 0x808000F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800100: bne         $v0, $at, L_80800118
    if (ctx->r2 != ctx->r1) {
        // 0x80800104: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800118;
    }
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x8009D2D8
    // 0x8080010C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_1;
    // 0x8080010C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800110: b           L_80800128
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800128;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800118:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x8009D2D8
    // 0x80800120: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8009D2D8(rdram, ctx);
        goto after_2;
    // 0x80800120: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800128:
    // 0x80800128: jal         0x8009C908
    // 0x8080012C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_3;
    // 0x8080012C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800138: jal         0x8009C99C
    // 0x8080013C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_4;
    // 0x8080013C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_4:
    // 0x80800140: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800144: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x8009F1C8
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_5;
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080015C: jal         0x8009F1C8
    // 0x80800160: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_6;
    // 0x80800160: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_6:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x8009B800
    // 0x8080016C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    baphysics_set_type(rdram, ctx);
        goto after_7;
    // 0x8080016C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_7:
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x8009BC5C
    // 0x80800178: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_8;
    // 0x80800178: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_8:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: jal         0x800961AC
    // 0x80800184: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800961AC(rdram, ctx);
        goto after_9;
    // 0x80800184: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800190: jal         0x800959C8
    // 0x80800194: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800959C8(rdram, ctx);
        goto after_10;
    // 0x80800194: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_10:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x800A4DA4
    // 0x808001A0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_800A4DA4(rdram, ctx);
        goto after_11;
    // 0x808001A0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_11:
    // 0x808001A4: jal         0x8008E0E8
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_12;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001AC: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x808001B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001BC;
    }
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: jal         0x80084788
    // 0x808001B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x808001B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
L_808001BC:
    // 0x808001BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C8: jr          $ra
    // 0x808001CC: nop

    return;
    // 0x808001CC: nop

;}
RECOMP_FUNC void _basudie_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085250: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085250);
    return;
    // 0x80085254: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _chmayafarmer_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A78: syscall     410
    recomp_syscall_handler(rdram, ctx, 0x80086A78);
    return;
    // 0x80086A7C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80093584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093584: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093588: sw          $zero, 0x94($t6)
    MEM_W(0X94, ctx->r14) = 0;
    // 0x8009358C: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x80093590: lw          $t7, 0x94($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X94);
    // 0x80093594: jr          $ra
    // 0x80093598: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    return;
    // 0x80093598: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_808001B8_basnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001C4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808001C8: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x808001CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001D4: lbu         $v1, 0x28($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X28);
    // 0x808001D8: beq         $v1, $zero, L_808001F0
    if (ctx->r3 == 0) {
        // 0x808001DC: nop
    
            goto L_808001F0;
    }
    // 0x808001DC: nop

    // 0x808001E0: beq         $v1, $at, L_80800210
    if (ctx->r3 == ctx->r1) {
        // 0x808001E4: nop
    
            goto L_80800210;
    }
    // 0x808001E4: nop

    // 0x808001E8: b           L_80800264
    // 0x808001EC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
        goto L_80800264;
    // 0x808001EC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_808001F0:
    // 0x808001F0: jal         0x800A1718
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_0;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808001F8: jal         0x80800084
    // 0x808001FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800084_basnowball(rdram, ctx);
        goto after_1;
    // 0x808001FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800200: lw          $t6, 0x110($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X110);
    // 0x80800204: swc1        $f0, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f0.u32l;
    // 0x80800208: b           L_80800260
    // 0x8080020C: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
        goto L_80800260;
    // 0x8080020C: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
L_80800210:
    // 0x80800210: jal         0x80085478
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawobble_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800218: lw          $t7, 0x110($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X110);
    // 0x8080021C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800224: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800230: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800234: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800238: jal         0x8009E55C
    // 0x8080023C: nop

    func_8009E55C(rdram, ctx);
        goto after_3;
    // 0x8080023C: nop

    after_3:
    // 0x80800240: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800244: lw          $t8, 0x110($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X110);
    // 0x80800248: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x8080024C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800250: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    // 0x80800254: lw          $t9, 0x110($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X110);
    // 0x80800258: swc1        $f16, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f16.u32l;
    // 0x8080025C: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
L_80800260:
    // 0x80800260: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_80800264:
    // 0x80800264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800268: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x8080026C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80800270: beq         $t1, $at, L_80800288
    if (ctx->r9 == ctx->r1) {
        // 0x80800274: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800288;
    }
    // 0x80800274: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800278: beql        $t1, $at, L_8080029C
    if (ctx->r9 == ctx->r1) {
        // 0x8080027C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8080029C;
    }
    goto skip_0;
    // 0x8080027C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80800280: b           L_808003C4
    // 0x80800284: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003C4;
    // 0x80800284: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800288:
    // 0x80800288: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x8080028C: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80800290: b           L_808003C0
    // 0x80800294: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
        goto L_808003C0;
    // 0x80800294: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x80800298: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8080029C:
    // 0x8080029C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002A0: lw          $t2, 0x110($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X110);
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: swc1        $f4, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f4.u32l;
    // 0x808002AC: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x808002B0: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x808002B4: jal         0x800A1718
    // 0x808002B8: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    func_800A1718(rdram, ctx);
        goto after_4;
    // 0x808002B8: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    after_4:
    // 0x808002BC: jal         0x80800084
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800084_basnowball(rdram, ctx);
        goto after_5;
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808002C4: lw          $t3, 0x110($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X110);
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002CC: jal         0x80085448
    // 0x808002D0: swc1        $f0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f0.u32l;
    _bawobble_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808002D0: swc1        $f0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f0.u32l;
    after_6:
    // 0x808002D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(604, 0XFF0) << 16);
    // 0x808002D8: lwc1        $f0, 0xFF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0XFF0));
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002E8: jal         0x80085460
    // 0x808002EC: nop

    _bawobble_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x808002EC: nop

    after_7:
    // 0x808002F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002F4: lw          $t4, 0x110($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X110);
    // 0x808002F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002FC: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80800300: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800304: lwc1        $f12, 0x24($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X24);
    // 0x80800308: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x8080030C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800310: jal         0x800F10B4
    // 0x80800314: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800314: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80800318: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x8080031C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800320: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800324: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80800328: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8080032C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(604, 0XFF4) << 16);
    // 0x80800330: lwc1        $f10, 0xFF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0XFF4));
    // 0x80800334: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800338: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080033C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: bc1f        L_80800384
    if (!c1cs) {
        // 0x80800348: add.s       $f2, $f0, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f10.fl;
            goto L_80800384;
    }
    // 0x80800348: add.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8080034C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800350: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800354: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: jal         0x80085468
    // 0x80800360: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    _bawobble_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x80800360: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x80800364: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: addiu       $a1, $zero, 0x65A
    ctx->r5 = ADD32(0, 0X65A);
    // 0x80800370: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800374: jal         0x8009DB04
    // 0x80800378: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DB04(rdram, ctx);
        goto after_10;
    // 0x80800378: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_10:
    // 0x8080037C: b           L_808003A8
    // 0x80800380: nop

        goto L_808003A8;
    // 0x80800380: nop

L_80800384:
    // 0x80800384: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800388: jal         0x80085468
    // 0x8080038C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    _bawobble_entrypoint_5(rdram, ctx);
        goto after_11;
    // 0x8080038C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_11:
    // 0x80800390: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: addiu       $a1, $zero, 0x65B
    ctx->r5 = ADD32(0, 0X65B);
    // 0x8080039C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808003A0: jal         0x8009DB04
    // 0x808003A4: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DB04(rdram, ctx);
        goto after_12;
    // 0x808003A4: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_12:
L_808003A8:
    // 0x808003A8: jal         0x80085470
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawobble_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808003B0: jal         0x808000C0
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C0_basnowball(rdram, ctx);
        goto after_14;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808003B8: jal         0x80800110
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800110_basnowball(rdram, ctx);
        goto after_15;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_808003C0:
    // 0x808003C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003C4:
    // 0x808003C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800324: jal         0x800DA544
    // 0x80800328: addiu       $a0, $zero, 0xD4D
    ctx->r4 = ADD32(0, 0XD4D);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800328: addiu       $a0, $zero, 0xD4D
    ctx->r4 = ADD32(0, 0XD4D);
    after_0:
    // 0x8080032C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800334: jr          $ra
    // 0x80800338: nop

    return;
    // 0x80800338: nop

;}
RECOMP_FUNC void _bscarry_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E78: syscall     31
    recomp_syscall_handler(rdram, ctx, 0x80082E78);
    return;
    // 0x80082E7C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808000E8_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x808000F4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(752, 0X1118) << 16);
    // 0x808000F8: addiu       $t8, $t8, 0x1118
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(752, 0X1118));
    // 0x808000FC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800100: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800104: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80800108: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8080010C: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x80800110: beq         $a1, $zero, L_80800134
    if (ctx->r5 == 0) {
        // 0x80800114: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800134;
    }
    // 0x80800114: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800118: jal         0x800DA298
    // 0x8080011C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080011C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80800120: bne         $v0, $zero, L_80800134
    if (ctx->r2 != 0) {
        // 0x80800124: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800134;
    }
    // 0x80800124: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800128: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8080012C: jal         0x8008A298
    // 0x80800130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sudialog_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80800134:
    // 0x80800134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void func_80800044_chicywind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800048: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800050: lhu         $a2, 0x72($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X72);
    // 0x80800054: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800058: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080005C: srl         $t6, $a2, 10
    ctx->r14 = S32(U32(ctx->r6) >> 10);
    // 0x80800060: xori        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 ^ 0X2;
    // 0x80800064: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80800068: bne         $t7, $zero, L_80800080
    if (ctx->r15 != 0) {
        // 0x8080006C: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_80800080;
    }
    // 0x8080006C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80800070: bnel        $t7, $zero, L_80800094
    if (ctx->r15 != 0) {
        // 0x80800074: addiu       $a0, $zero, 0x21
        ctx->r4 = ADD32(0, 0X21);
            goto L_80800094;
    }
    goto skip_0;
    // 0x80800074: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    skip_0:
    // 0x80800078: lbu         $t8, 0x5F($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5F);
    // 0x8080007C: beq         $t8, $zero, L_80800090
    if (ctx->r24 == 0) {
        // 0x80800080: lui         $a3, 0x8080
        ctx->r7 = S32(RELOC_HI16(1280, 0X348) << 16);
            goto L_80800090;
    }
L_80800080:
    // 0x80800080: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1280, 0X348) << 16);
    // 0x80800084: addiu       $a3, $a3, 0x348
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1280, 0X348));
    // 0x80800088: jal         0x80089D50
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_80800090:
    // 0x80800090: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
L_80800094:
    // 0x80800094: jal         0x800D0B68
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080009C: beql        $v0, $zero, L_808000B8
    if (ctx->r2 == 0) {
        // 0x808000A0: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_808000B8;
    }
    goto skip_1;
    // 0x808000A0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x808000A4: jal         0x800FFAB0
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000AC: b           L_8080019C
    // 0x808000B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080019C;
    // 0x808000B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000B4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808000B8:
    // 0x808000B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000BC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000C0: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x808000C4: beq         $t9, $at, L_808000DC
    if (ctx->r25 == ctx->r1) {
        // 0x808000C8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000DC;
    }
    // 0x808000C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000CC: beq         $t9, $at, L_80800110
    if (ctx->r25 == ctx->r1) {
        // 0x808000D0: addiu       $a0, $s0, 0x58
        ctx->r4 = ADD32(ctx->r16, 0X58);
            goto L_80800110;
    }
    // 0x808000D0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x808000D4: b           L_8080019C
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080019C;
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000DC:
    // 0x808000DC: jal         0x8010C9B0
    // 0x808000E0: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    func_8010C9B0(rdram, ctx);
        goto after_3;
    // 0x808000E0: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_3:
    // 0x808000E4: beq         $v0, $zero, L_80800198
    if (ctx->r2 == 0) {
        // 0x808000E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800198;
    }
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: jal         0x80101FDC
    // 0x808000F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808000F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808000F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1280, 0X2E0) << 16);
    // 0x808000F8: lwc1        $f12, 0x2E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1280, 0X2E0));
    // 0x808000FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1280, 0X2E4) << 16);
    // 0x80800100: jal         0x800DC178
    // 0x80800104: lwc1        $f14, 0x2E4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1280, 0X2E4));
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800104: lwc1        $f14, 0x2E4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1280, 0X2E4));
    after_5:
    // 0x80800108: b           L_80800198
    // 0x8080010C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800198;
    // 0x8080010C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800110:
    // 0x80800110: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    // 0x80800114: jal         0x800D9078
    // 0x80800118: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x80800118: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_6:
    // 0x8080011C: beq         $v0, $zero, L_80800174
    if (ctx->r2 == 0) {
        // 0x80800120: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80800174;
    }
    // 0x80800120: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800124: jal         0x800EE7F8
    // 0x80800128: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800128: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x8080012C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800130: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800134: jal         0x800EF1B8
    // 0x80800138: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_8;
    // 0x80800138: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    after_8:
    // 0x8080013C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1280, 0X358) << 16);
    // 0x80800140: addiu       $t1, $t1, 0x358
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1280, 0X358));
    // 0x80800144: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800148: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080014C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800150: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800154: jal         0x800BBCB8
    // 0x80800158: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_9;
    // 0x80800158: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x8080015C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1280, 0X2E8) << 16);
    // 0x80800160: lwc1        $f12, 0x2E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1280, 0X2E8));
    // 0x80800164: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1280, 0X2EC) << 16);
    // 0x80800168: jal         0x800DC178
    // 0x8080016C: lwc1        $f14, 0x2EC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1280, 0X2EC));
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x8080016C: lwc1        $f14, 0x2EC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1280, 0X2EC));
    after_10:
    // 0x80800170: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800174:
    // 0x80800174: jal         0x808001AC
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001AC_chicywind(rdram, ctx);
        goto after_11;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080017C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800180: jal         0x8010C9B0
    // 0x80800184: addiu       $a1, $zero, 0x708
    ctx->r5 = ADD32(0, 0X708);
    func_8010C9B0(rdram, ctx);
        goto after_12;
    // 0x80800184: addiu       $a1, $zero, 0x708
    ctx->r5 = ADD32(0, 0X708);
    after_12:
    // 0x80800188: bne         $v0, $zero, L_80800198
    if (ctx->r2 != 0) {
        // 0x8080018C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800198;
    }
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: jal         0x80101FDC
    // 0x80800194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x80800194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
L_80800198:
    // 0x80800198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080019C:
    // 0x8080019C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

;}
RECOMP_FUNC void bsdie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800090: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800094: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800098: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080009C: jal         0x8008CABC
    // 0x808000A0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808000A0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808000A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000A8: jal         0x8008AF24
    // 0x808000AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808000AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x8008B1A0
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: jal         0x8008AED4
    // 0x808000C4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x808000C4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x808000C8: lui         $a2, 0x3EAB
    ctx->r6 = S32(0X3EAB << 16);
    // 0x808000CC: ori         $a2, $a2, 0xD3C3
    ctx->r6 = ctx->r6 | 0XD3C3;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x8008B1D4
    // 0x808000D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x808000D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E0: jal         0x8008B1BC
    // 0x808000E4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808000E4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_5:
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: jal         0x8008B134
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000F4: jal         0x8008B064
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000FC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800100: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800104: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800108: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080010C: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80800110: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800114: swc1        $f0, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f0.u32l;
    // 0x80800118: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080011C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800120: lui         $a2, 0x43FF
    ctx->r6 = S32(0X43FF << 16);
    // 0x80800124: lui         $a3, 0xC4AF
    ctx->r7 = S32(0XC4AF << 16);
    // 0x80800128: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8080012C: jal         0x80085220
    // 0x80800130: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _basudie_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800130: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80800134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800138: jal         0x800A0CF4
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_9;
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800140: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800144: jal         0x8009D820
    // 0x80800148: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009D820(rdram, ctx);
        goto after_10;
    // 0x80800148: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
    // 0x8080014C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800150: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800154: jal         0x8009BFE4
    // 0x80800158: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_11;
    // 0x80800158: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_11:
    // 0x8080015C: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800164: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800168: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080016C: jr          $ra
    // 0x80800170: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800170: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800A6250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6250: addiu       $sp, $sp, -0x250
    ctx->r29 = ADD32(ctx->r29, -0X250);
    // 0x800A6254: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A6258: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800A625C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800A6260: sw          $a0, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r4;
    // 0x800A6264: sw          $a1, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r5;
    // 0x800A6268: sw          $a2, 0x258($sp)
    MEM_W(0X258, ctx->r29) = ctx->r6;
    // 0x800A626C: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x800A6270: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800A6274: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x800A6278: jal         0x800F53D0
    // 0x800A627C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x800A627C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800A6280: lw          $t8, 0x250($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X250);
    // 0x800A6284: sw          $v0, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r2;
    // 0x800A6288: lhu         $a0, 0x76($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X76);
    // 0x800A628C: srl         $t9, $a0, 7
    ctx->r25 = S32(U32(ctx->r4) >> 7);
    // 0x800A6290: jal         0x800F5410
    // 0x800A6294: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x800A6294: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x800A6298: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A629C: jal         0x80084F40
    // 0x800A62A0: addiu       $a1, $sp, 0x1BC
    ctx->r5 = ADD32(ctx->r29, 0X1BC);
    _bapreload_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x800A62A0: addiu       $a1, $sp, 0x1BC
    ctx->r5 = ADD32(ctx->r29, 0X1BC);
    after_2:
    // 0x800A62A4: jal         0x800D674C
    // 0x800A62A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x800A62A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800A62AC: sw          $v0, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->r2;
    // 0x800A62B0: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    // 0x800A62B4: jal         0x80092B04
    // 0x800A62B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092B04(rdram, ctx);
        goto after_4;
    // 0x800A62B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800A62BC: sw          $v0, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r2;
    // 0x800A62C0: jal         0x800F274C
    // 0x800A62C4: addiu       $a0, $sp, 0x210
    ctx->r4 = ADD32(ctx->r29, 0X210);
    func_800F274C(rdram, ctx);
        goto after_5;
    // 0x800A62C4: addiu       $a0, $sp, 0x210
    ctx->r4 = ADD32(ctx->r29, 0X210);
    after_5:
    // 0x800A62C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A62CC: jal         0x800EEAA4
    // 0x800A62D0: lw          $a1, 0x258($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X258);
    func_800EEAA4(rdram, ctx);
        goto after_6;
    // 0x800A62D0: lw          $a1, 0x258($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X258);
    after_6:
    // 0x800A62D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A62D8: lwc1        $f4, 0x55D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55D4);
    // 0x800A62DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A62E0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800A62E4: nop

    // 0x800A62E8: bc1tl       L_800A69E0
    if (c1cs) {
        // 0x800A62EC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800A69E0;
    }
    goto skip_0;
    // 0x800A62EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800A62F0: lwc1        $f12, 0x55D8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X55D8);
    // 0x800A62F4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800A62F8: nop

    // 0x800A62FC: bc1fl       L_800A6350
    if (!c1cs) {
        // 0x800A6300: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800A6350;
    }
    goto skip_1;
    // 0x800A6300: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x800A6304: jal         0x80013A7C
    // 0x800A6308: nop

    func_80013A7C(rdram, ctx);
        goto after_7;
    // 0x800A6308: nop

    after_7:
    // 0x800A630C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800A6310: addiu       $a0, $sp, 0x1AC
    ctx->r4 = ADD32(ctx->r29, 0X1AC);
    // 0x800A6314: lw          $a1, 0x258($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X258);
    // 0x800A6318: jal         0x800EE97C
    // 0x800A631C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE97C(rdram, ctx);
        goto after_8;
    // 0x800A631C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x800A6320: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800A6324: addiu       $a0, $sp, 0x168
    ctx->r4 = ADD32(ctx->r29, 0X168);
    // 0x800A6328: jal         0x800F254C
    // 0x800A632C: addiu       $a1, $sp, 0x1AC
    ctx->r5 = ADD32(ctx->r29, 0X1AC);
    func_800F254C(rdram, ctx);
        goto after_9;
    // 0x800A632C: addiu       $a1, $sp, 0x1AC
    ctx->r5 = ADD32(ctx->r29, 0X1AC);
    after_9:
    // 0x800A6330: addiu       $a0, $sp, 0x168
    ctx->r4 = ADD32(ctx->r29, 0X168);
    // 0x800A6334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800A6338: jal         0x800F23D0
    // 0x800A633C: lw          $a2, 0x258($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X258);
    func_800F23D0(rdram, ctx);
        goto after_10;
    // 0x800A633C: lw          $a2, 0x258($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X258);
    after_10:
    // 0x800A6340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A6344: jal         0x800EEAA4
    // 0x800A6348: lw          $a1, 0x258($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X258);
    func_800EEAA4(rdram, ctx);
        goto after_11;
    // 0x800A6348: lw          $a1, 0x258($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X258);
    after_11:
    // 0x800A634C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800A6350:
    // 0x800A6350: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A6354: lw          $v0, 0x258($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X258);
    // 0x800A6358: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800A635C: div.s       $f2, $f20, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800A6360: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A6364: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A6368: nop

    // 0x800A636C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A6370: sub.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x800A6374: swc1        $f6, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->f6.u32l;
    // 0x800A6378: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A637C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800A6380: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800A6384: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800A6388: nop

    // 0x800A638C: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800A6390: swc1        $f10, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->f10.u32l;
    // 0x800A6394: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A6398: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800A639C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A63A0: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800A63A4: nop

    // 0x800A63A8: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800A63AC: swc1        $f4, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->f4.u32l;
    // 0x800A63B0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A63B4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800A63B8: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800A63BC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A63C0: nop

    // 0x800A63C4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800A63C8: swc1        $f6, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->f6.u32l;
    // 0x800A63CC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800A63D0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A63D4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A63D8: nop

    // 0x800A63DC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800A63E0: sub.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x800A63E4: swc1        $f8, 0x224($sp)
    MEM_W(0X224, ctx->r29) = ctx->f8.u32l;
    // 0x800A63E8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A63EC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800A63F0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A63F4: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800A63F8: nop

    // 0x800A63FC: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800A6400: swc1        $f4, 0x228($sp)
    MEM_W(0X228, ctx->r29) = ctx->f4.u32l;
    // 0x800A6404: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A6408: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800A640C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800A6410: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800A6414: nop

    // 0x800A6418: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800A641C: swc1        $f6, 0x230($sp)
    MEM_W(0X230, ctx->r29) = ctx->f6.u32l;
    // 0x800A6420: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A6424: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800A6428: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x800A642C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A6430: nop

    // 0x800A6434: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800A6438: swc1        $f8, 0x234($sp)
    MEM_W(0X234, ctx->r29) = ctx->f8.u32l;
    // 0x800A643C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800A6440: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A6444: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A6448: nop

    // 0x800A644C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800A6450: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x800A6454: jal         0x80019CD4
    // 0x800A6458: swc1        $f10, 0x238($sp)
    MEM_W(0X238, ctx->r29) = ctx->f10.u32l;
    func_80019CD4(rdram, ctx);
        goto after_12;
    // 0x800A6458: swc1        $f10, 0x238($sp)
    MEM_W(0X238, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x800A645C: jal         0x80092BE8
    // 0x800A6460: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    func_80092BE8(rdram, ctx);
        goto after_13;
    // 0x800A6460: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    after_13:
    // 0x800A6464: jal         0x80018FE8
    // 0x800A6468: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlMtxRotYaw(rdram, ctx);
        goto after_14;
    // 0x800A6468: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_14:
    // 0x800A646C: jal         0x8009BFCC
    // 0x800A6470: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    func_8009BFCC(rdram, ctx);
        goto after_15;
    // 0x800A6470: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    after_15:
    // 0x800A6474: jal         0x80018F50
    // 0x800A6478: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlMtxRotPitch(rdram, ctx);
        goto after_16;
    // 0x800A6478: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_16:
    // 0x800A647C: jal         0x8009C53C
    // 0x800A6480: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    baroll_get(rdram, ctx);
        goto after_17;
    // 0x800A6480: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    after_17:
    // 0x800A6484: jal         0x8001907C
    // 0x800A6488: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlMtxRotRoll(rdram, ctx);
        goto after_18;
    // 0x800A6488: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_18:
    // 0x800A648C: addiu       $s0, $sp, 0x1D0
    ctx->r16 = ADD32(ctx->r29, 0X1D0);
    // 0x800A6490: jal         0x80018AD0
    // 0x800A6494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mlMtxGet(rdram, ctx);
        goto after_19;
    // 0x800A6494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x800A6498: addiu       $a1, $sp, 0x210
    ctx->r5 = ADD32(ctx->r29, 0X210);
    // 0x800A649C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800A64A0: jal         0x800F27D4
    // 0x800A64A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F27D4(rdram, ctx);
        goto after_20;
    // 0x800A64A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x800A64A8: lw          $t5, 0x1C8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C8);
    // 0x800A64AC: lw          $t6, 0x1C4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C4);
    // 0x800A64B0: beq         $t5, $t6, L_800A6538
    if (ctx->r13 == ctx->r14) {
        // 0x800A64B4: nop
    
            goto L_800A6538;
    }
    // 0x800A64B4: nop

    // 0x800A64B8: lw          $t7, 0x1BC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1BC);
    // 0x800A64BC: beq         $t7, $zero, L_800A64DC
    if (ctx->r15 == 0) {
        // 0x800A64C0: nop
    
            goto L_800A64DC;
    }
    // 0x800A64C0: nop

    // 0x800A64C4: jal         0x8008CA74
    // 0x800A64C8: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    func_8008CA74(rdram, ctx);
        goto after_21;
    // 0x800A64C8: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    after_21:
    // 0x800A64CC: jal         0x800DF41C
    // 0x800A64D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_22;
    // 0x800A64D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x800A64D4: b           L_800A6548
    // 0x800A64D8: nop

        goto L_800A6548;
    // 0x800A64D8: nop

L_800A64DC:
    // 0x800A64DC: jal         0x800DF330
    // 0x800A64E0: nop

    func_800DF330(rdram, ctx);
        goto after_23;
    // 0x800A64E0: nop

    after_23:
    // 0x800A64E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A64E8: jal         0x800B27E0
    // 0x800A64EC: lw          $a0, 0x1C4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C4);
    func_800B27E0(rdram, ctx);
        goto after_24;
    // 0x800A64EC: lw          $a0, 0x1C4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C4);
    after_24:
    // 0x800A64F0: sw          $v0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r2;
    // 0x800A64F4: jal         0x800B27E0
    // 0x800A64F8: lw          $a0, 0x1C8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C8);
    func_800B27E0(rdram, ctx);
        goto after_25;
    // 0x800A64F8: lw          $a0, 0x1C8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C8);
    after_25:
    // 0x800A64FC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A6500: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    // 0x800A6504: beq         $t8, $zero, L_800A6548
    if (ctx->r24 == 0) {
        // 0x800A6508: nop
    
            goto L_800A6548;
    }
    // 0x800A6508: nop

    // 0x800A650C: jal         0x80092E80
    // 0x800A6510: sw          $v0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r2;
    func_80092E80(rdram, ctx);
        goto after_26;
    // 0x800A6510: sw          $v0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r2;
    after_26:
    // 0x800A6514: lw          $a3, 0x15C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X15C);
    // 0x800A6518: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A651C: lw          $a1, 0x160($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X160);
    // 0x800A6520: jal         0x800AE708
    // 0x800A6524: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800AE708(rdram, ctx);
        goto after_27;
    // 0x800A6524: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_27:
    // 0x800A6528: jal         0x800DF72C
    // 0x800A652C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800DF72C(rdram, ctx);
        goto after_28;
    // 0x800A652C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_28:
    // 0x800A6530: b           L_800A6548
    // 0x800A6534: nop

        goto L_800A6548;
    // 0x800A6534: nop

L_800A6538:
    // 0x800A6538: jal         0x80092E80
    // 0x800A653C: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    func_80092E80(rdram, ctx);
        goto after_29;
    // 0x800A653C: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    after_29:
    // 0x800A6540: jal         0x800DF72C
    // 0x800A6544: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF72C(rdram, ctx);
        goto after_30;
    // 0x800A6544: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
L_800A6548:
    // 0x800A6548: jal         0x800A06E8
    // 0x800A654C: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    func_800A06E8(rdram, ctx);
        goto after_31;
    // 0x800A654C: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    after_31:
    // 0x800A6550: jal         0x800DF540
    // 0x800A6554: addiu       $a0, $sp, 0x210
    ctx->r4 = ADD32(ctx->r29, 0X210);
    func_800DF540(rdram, ctx);
        goto after_32;
    // 0x800A6554: addiu       $a0, $sp, 0x210
    ctx->r4 = ADD32(ctx->r29, 0X210);
    after_32:
    // 0x800A6558: jal         0x800A61D4
    // 0x800A655C: nop

    func_800A61D4(rdram, ctx);
        goto after_33;
    // 0x800A655C: nop

    after_33:
    // 0x800A6560: jal         0x800A7180
    // 0x800A6564: nop

    func_800A7180(rdram, ctx);
        goto after_34;
    // 0x800A6564: nop

    after_34:
    // 0x800A6568: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800A656C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800A6570: lui         $t7, 0xFF48
    ctx->r15 = S32(0XFF48 << 16);
    // 0x800A6574: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A6578: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A657C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800A6580: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A6584: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800A6588: ori         $t7, $t7, 0x12F
    ctx->r15 = ctx->r15 | 0X12F;
    // 0x800A658C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A6590: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800A6594: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A6598: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800A659C: jal         0x8001575C
    // 0x800A65A0: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    func_8001575C(rdram, ctx);
        goto after_35;
    // 0x800A65A0: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_35:
    // 0x800A65A4: lw          $a3, 0x144($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X144);
    // 0x800A65A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A65AC: addu        $t8, $v0, $at
    ctx->r24 = ADD32(ctx->r2, ctx->r1);
    // 0x800A65B0: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800A65B4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A65B8: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800A65BC: ori         $t5, $t5, 0x800
    ctx->r13 = ctx->r13 | 0X800;
    // 0x800A65C0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A65C4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800A65C8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A65CC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800A65D0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A65D4: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800A65D8: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x800A65DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800A65E0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800A65E4: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x800A65E8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800A65EC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800A65F0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A65F4: lui         $t6, 0xFFFE
    ctx->r14 = S32(0XFFFE << 16);
    // 0x800A65F8: ori         $t6, $t6, 0xFFFE
    ctx->r14 = ctx->r14 | 0XFFFE;
    // 0x800A65FC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A6600: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800A6604: lui         $t5, 0xF700
    ctx->r13 = S32(0XF700 << 16);
    // 0x800A6608: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800A660C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800A6610: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A6614: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800A6618: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x800A661C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800A6620: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800A6624: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A6628: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800A662C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A6630: lui         $t5, 0xF64B
    ctx->r13 = S32(0XF64B << 16);
    // 0x800A6634: ori         $t5, $t5, 0xC38C
    ctx->r13 = ctx->r13 | 0XC38C;
    // 0x800A6638: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A663C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800A6640: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A6644: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800A6648: jal         0x80092BDC
    // 0x800A664C: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    func_80092BDC(rdram, ctx);
        goto after_36;
    // 0x800A664C: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    after_36:
    // 0x800A6650: lw          $t6, 0x1C8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C8);
    // 0x800A6654: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800A6658: lw          $a0, 0x254($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X254);
    // 0x800A665C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A6660: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A6664: jal         0x800DE448
    // 0x800A6668: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800DE448(rdram, ctx);
        goto after_37;
    // 0x800A6668: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_37:
    // 0x800A666C: jal         0x80092738
    // 0x800A6670: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    func_80092738(rdram, ctx);
        goto after_38;
    // 0x800A6670: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    after_38:
    // 0x800A6674: beq         $v0, $zero, L_800A66C4
    if (ctx->r2 == 0) {
        // 0x800A6678: nop
    
            goto L_800A66C4;
    }
    // 0x800A6678: nop

    // 0x800A667C: jal         0x800844F8
    // 0x800A6680: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    _babackpack_entrypoint_2(rdram, ctx);
        goto after_39;
    // 0x800A6680: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    after_39:
    // 0x800A6684: jal         0x800DF540
    // 0x800A6688: addiu       $a0, $sp, 0x210
    ctx->r4 = ADD32(ctx->r29, 0X210);
    func_800DF540(rdram, ctx);
        goto after_40;
    // 0x800A6688: addiu       $a0, $sp, 0x210
    ctx->r4 = ADD32(ctx->r29, 0X210);
    after_40:
    // 0x800A668C: jal         0x800A61D4
    // 0x800A6690: nop

    func_800A61D4(rdram, ctx);
        goto after_41;
    // 0x800A6690: nop

    after_41:
    // 0x800A6694: jal         0x80084520
    // 0x800A6698: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    _babackpack_get_scale(rdram, ctx);
        goto after_42;
    // 0x800A6698: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    after_42:
    // 0x800A669C: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    // 0x800A66A0: jal         0x800844F0
    // 0x800A66A4: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    _babackpack_entrypoint_1(rdram, ctx);
        goto after_43;
    // 0x800A66A4: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_43:
    // 0x800A66A8: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A66AC: lw          $a0, 0x254($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X254);
    // 0x800A66B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A66B4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800A66B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A66BC: jal         0x800DE448
    // 0x800A66C0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800DE448(rdram, ctx);
        goto after_44;
    // 0x800A66C0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_44:
L_800A66C4:
    // 0x800A66C4: jal         0x800A7180
    // 0x800A66C8: nop

    func_800A7180(rdram, ctx);
        goto after_45;
    // 0x800A66C8: nop

    after_45:
    // 0x800A66CC: sw          $v0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r2;
    // 0x800A66D0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800A66D4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A66D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A66DC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800A66E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A66E4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A66E8: jal         0x800E7CF4
    // 0x800A66EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    func_800E7CF4(rdram, ctx);
        goto after_46;
    // 0x800A66EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    after_46:
    // 0x800A66F0: jal         0x800B2840
    // 0x800A66F4: lw          $a0, 0x1C8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C8);
    func_800B2840(rdram, ctx);
        goto after_47;
    // 0x800A66F4: lw          $a0, 0x1C8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C8);
    after_47:
    // 0x800A66F8: jal         0x800B2354
    // 0x800A66FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2354(rdram, ctx);
        goto after_48;
    // 0x800A66FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_48:
    // 0x800A6700: lw          $a0, 0x1CC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1CC);
    // 0x800A6704: jal         0x80092BDC
    // 0x800A6708: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    func_80092BDC(rdram, ctx);
        goto after_49;
    // 0x800A6708: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_49:
    // 0x800A670C: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A6710: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800A6714: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800A6718: mul.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A671C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6720: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A6724: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800A6728: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800A672C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800A6730: addiu       $t0, $sp, 0xC8
    ctx->r8 = ADD32(ctx->r29, 0XC8);
L_800A6734:
    // 0x800A6734: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A6738: or          $t3, $t4, $zero
    ctx->r11 = ctx->r12 | 0;
L_800A673C:
    // 0x800A673C: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x800A6740: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x800A6744: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6748: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x800A674C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A6750: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_800A6754:
    // 0x800A6754: beq         $a3, $zero, L_800A6764
    if (ctx->r7 == 0) {
        // 0x800A6758: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800A6764;
    }
    // 0x800A6758: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A675C: b           L_800A6768
    // 0x800A6760: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_800A6768;
    // 0x800A6760: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800A6764:
    // 0x800A6764: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_800A6768:
    // 0x800A6768: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800A676C: beq         $a2, $zero, L_800A677C
    if (ctx->r6 == 0) {
        // 0x800A6770: swc1        $f4, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
            goto L_800A677C;
    }
    // 0x800A6770: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800A6774: b           L_800A6780
    // 0x800A6778: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_800A6780;
    // 0x800A6778: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_800A677C:
    // 0x800A677C: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_800A6780:
    // 0x800A6780: mul.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800A6784: beq         $v0, $zero, L_800A6794
    if (ctx->r2 == 0) {
        // 0x800A6788: swc1        $f6, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
            goto L_800A6794;
    }
    // 0x800A6788: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x800A678C: b           L_800A6798
    // 0x800A6790: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_800A6798;
    // 0x800A6790: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800A6794:
    // 0x800A6794: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_800A6798:
    // 0x800A6798: multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A679C: mul.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800A67A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A67A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800A67A8: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800A67AC: mflo        $t5
    ctx->r13 = lo;
    // 0x800A67B0: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x800A67B4: bne         $v0, $t2, L_800A6754
    if (ctx->r2 != ctx->r10) {
        // 0x800A67B8: swc1        $f8, 0x8($t6)
        MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
            goto L_800A6754;
    }
    // 0x800A67B8: swc1        $f8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
    // 0x800A67BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800A67C0: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x800A67C4: bne         $at, $zero, L_800A673C
    if (ctx->r1 != 0) {
        // 0x800A67C8: addiu       $t3, $t3, 0x2
        ctx->r11 = ADD32(ctx->r11, 0X2);
            goto L_800A673C;
    }
    // 0x800A67C8: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x800A67CC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800A67D0: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x800A67D4: bne         $at, $zero, L_800A6734
    if (ctx->r1 != 0) {
        // 0x800A67D8: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_800A6734;
    }
    // 0x800A67D8: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x800A67DC: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
    // 0x800A67E0: addiu       $a0, $sp, 0x210
    ctx->r4 = ADD32(ctx->r29, 0X210);
L_800A67E4:
    // 0x800A67E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800A67E8: jal         0x800F23D0
    // 0x800A67EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F23D0(rdram, ctx);
        goto after_50;
    // 0x800A67EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_50:
    // 0x800A67F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A67F4: jal         0x800EF04C
    // 0x800A67F8: lw          $a1, 0x254($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X254);
    func_800EF04C(rdram, ctx);
        goto after_51;
    // 0x800A67F8: lw          $a1, 0x254($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X254);
    after_51:
    // 0x800A67FC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800A6800: addiu       $t7, $sp, 0x128
    ctx->r15 = ADD32(ctx->r29, 0X128);
    // 0x800A6804: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x800A6808: bnel        $at, $zero, L_800A67E4
    if (ctx->r1 != 0) {
        // 0x800A680C: addiu       $a0, $sp, 0x210
        ctx->r4 = ADD32(ctx->r29, 0X210);
            goto L_800A67E4;
    }
    goto skip_2;
    // 0x800A680C: addiu       $a0, $sp, 0x210
    ctx->r4 = ADD32(ctx->r29, 0X210);
    skip_2:
    // 0x800A6810: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
    // 0x800A6814: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
L_800A6818:
    // 0x800A6818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A681C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x800A6820: jal         0x800E4190
    // 0x800A6824: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_800E4190(rdram, ctx);
        goto after_52;
    // 0x800A6824: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_52:
    // 0x800A6828: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800A682C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A6830: addiu       $t9, $sp, 0xC8
    ctx->r25 = ADD32(ctx->r29, 0XC8);
    // 0x800A6834: beq         $t8, $zero, L_800A69DC
    if (ctx->r24 == 0) {
        // 0x800A6838: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_800A69DC;
    }
    // 0x800A6838: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800A683C: sltu        $at, $a1, $t9
    ctx->r1 = ctx->r5 < ctx->r25 ? 1 : 0;
    // 0x800A6840: bne         $at, $zero, L_800A6818
    if (ctx->r1 != 0) {
        // 0x800A6844: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800A6818;
    }
    // 0x800A6844: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800A6848: lwc1        $f14, 0x88($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800A684C: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800A6850: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x800A6854: addiu       $v0, $sp, 0xC8
    ctx->r2 = ADD32(ctx->r29, 0XC8);
    // 0x800A6858: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800A685C: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x800A6860: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_800A6864:
    // 0x800A6864: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800A6868: nop

    // 0x800A686C: bc1fl       L_800A6880
    if (!c1cs) {
        // 0x800A6870: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_800A6880;
    }
    goto skip_3;
    // 0x800A6870: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_3:
    // 0x800A6874: b           L_800A6890
    // 0x800A6878: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_800A6890;
    // 0x800A6878: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x800A687C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_800A6880:
    // 0x800A6880: nop

    // 0x800A6884: bc1fl       L_800A6894
    if (!c1cs) {
        // 0x800A6888: lwc1        $f0, 0x4($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
            goto L_800A6894;
    }
    goto skip_4;
    // 0x800A6888: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    skip_4:
    // 0x800A688C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_800A6890:
    // 0x800A6890: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
L_800A6894:
    // 0x800A6894: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800A6898: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800A689C: nop

    // 0x800A68A0: bc1fl       L_800A68B4
    if (!c1cs) {
        // 0x800A68A4: c.lt.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
            goto L_800A68B4;
    }
    goto skip_5;
    // 0x800A68A4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    skip_5:
    // 0x800A68A8: b           L_800A68C4
    // 0x800A68AC: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
        goto L_800A68C4;
    // 0x800A68AC: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x800A68B0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
L_800A68B4:
    // 0x800A68B4: nop

    // 0x800A68B8: bc1f        L_800A68C4
    if (!c1cs) {
        // 0x800A68BC: nop
    
            goto L_800A68C4;
    }
    // 0x800A68BC: nop

    // 0x800A68C0: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_800A68C4:
    // 0x800A68C4: bnel        $a1, $v0, L_800A6864
    if (ctx->r5 != ctx->r2) {
        // 0x800A68C8: lwc1        $f0, 0x0($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
            goto L_800A6864;
    }
    goto skip_6;
    // 0x800A68C8: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    skip_6:
    // 0x800A68CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A68D0: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x800A68D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A68D8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800A68DC: lui         $at, 0x4364
    ctx->r1 = S32(0X4364 << 16);
    // 0x800A68E0: bc1fl       L_800A68F0
    if (!c1cs) {
        // 0x800A68E4: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_800A68F0;
    }
    goto skip_7;
    // 0x800A68E4: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_7:
    // 0x800A68E8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x800A68EC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_800A68F0:
    // 0x800A68F0: nop

    // 0x800A68F4: bc1fl       L_800A6904
    if (!c1cs) {
        // 0x800A68F8: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_800A6904;
    }
    goto skip_8;
    // 0x800A68F8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_8:
    // 0x800A68FC: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x800A6900: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_800A6904:
    // 0x800A6904: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800A6908: bc1fl       L_800A6918
    if (!c1cs) {
        // 0x800A690C: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_800A6918;
    }
    goto skip_9;
    // 0x800A690C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_9:
    // 0x800A6910: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800A6914: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_800A6918:
    // 0x800A6918: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800A691C: bc1fl       L_800A692C
    if (!c1cs) {
        // 0x800A6920: c.lt.s      $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
            goto L_800A692C;
    }
    goto skip_10;
    // 0x800A6920: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    skip_10:
    // 0x800A6924: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x800A6928: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
L_800A692C:
    // 0x800A692C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A6930: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800A6934: bc1fl       L_800A6944
    if (!c1cs) {
        // 0x800A6938: c.lt.s      $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
            goto L_800A6944;
    }
    goto skip_11;
    // 0x800A6938: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    skip_11:
    // 0x800A693C: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x800A6940: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
L_800A6944:
    // 0x800A6944: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800A6948: bc1fl       L_800A6958
    if (!c1cs) {
        // 0x800A694C: c.lt.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
            goto L_800A6958;
    }
    goto skip_12;
    // 0x800A694C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    skip_12:
    // 0x800A6950: mov.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
    // 0x800A6954: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
L_800A6958:
    // 0x800A6958: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800A695C: bc1fl       L_800A696C
    if (!c1cs) {
        // 0x800A6960: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_800A696C;
    }
    goto skip_13;
    // 0x800A6960: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_13:
    // 0x800A6964: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x800A6968: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_800A696C:
    // 0x800A696C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800A6970: bc1fl       L_800A6980
    if (!c1cs) {
        // 0x800A6974: trunc.w.s   $f8, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
            goto L_800A6980;
    }
    goto skip_14;
    // 0x800A6974: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    skip_14:
    // 0x800A6978: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x800A697C: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
L_800A6980:
    // 0x800A6980: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x800A6984: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800A6988: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800A698C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800A6990: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x800A6994: swc1        $f14, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f14.u32l;
    // 0x800A6998: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    // 0x800A699C: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x800A69A0: jal         0x8001575C
    // 0x800A69A4: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    func_8001575C(rdram, ctx);
        goto after_53;
    // 0x800A69A4: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    after_53:
    // 0x800A69A8: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800A69AC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800A69B0: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800A69B4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800A69B8: lw          $t5, 0x260($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X260);
    // 0x800A69BC: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x800A69C0: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x800A69C4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A69C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800A69CC: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x800A69D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800A69D4: jal         0x800A5EC4
    // 0x800A69D8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    func_800A5EC4(rdram, ctx);
        goto after_54;
    // 0x800A69D8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_54:
L_800A69DC:
    // 0x800A69DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800A69E0:
    // 0x800A69E0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800A69E4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800A69E8: jr          $ra
    // 0x800A69EC: addiu       $sp, $sp, 0x250
    ctx->r29 = ADD32(ctx->r29, 0X250);
    return;
    // 0x800A69EC: addiu       $sp, $sp, 0x250
    ctx->r29 = ADD32(ctx->r29, 0X250);
;}
RECOMP_FUNC void func_800A58A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A58A8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A58AC: lw          $a3, -0x6AC0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6AC0);
    // 0x800A58B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A58B4: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800A58B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A58BC: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800A58C0: lbu         $t8, 0x3C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X3C);
    // 0x800A58C4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A58C8: beql        $a1, $t8, L_800A58E4
    if (ctx->r5 == ctx->r24) {
        // 0x800A58CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A58E4;
    }
    goto skip_0;
    // 0x800A58CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A58D0: beql        $a1, $zero, L_800A58E4
    if (ctx->r5 == 0) {
        // 0x800A58D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A58E4;
    }
    goto skip_1;
    // 0x800A58D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800A58D8: jal         0x80085570
    // 0x800A58DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _cadbmgrDll_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800A58DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800A58E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A58E4:
    // 0x800A58E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A58E8: jr          $ra
    // 0x800A58EC: nop

    return;
    // 0x800A58EC: nop

;}
RECOMP_FUNC void suegg_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800724: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800728: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080072C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800730: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800734: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800738: jal         0x80108474
    // 0x8080073C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_0;
    // 0x8080073C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800740: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800748: jal         0x80100094
    // 0x8080074C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080074C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800750: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800754: jal         0x8080000C
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080000C_suegg(rdram, ctx);
        goto after_2;
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080075C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800760: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800764: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800768: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
    // 0x8080076C: sb          $t7, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r15;
    // 0x80800770: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80800774: sh          $t6, 0x3A($s1)
    MEM_H(0X3A, ctx->r17) = ctx->r14;
    // 0x80800778: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    // 0x8080077C: jal         0x800D3E40
    // 0x80800780: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
    func_800D3E40(rdram, ctx);
        goto after_3;
    // 0x80800780: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
    after_3:
    // 0x80800784: beq         $v0, $zero, L_808007E4
    if (ctx->r2 == 0) {
        // 0x80800788: nop
    
            goto L_808007E4;
    }
    // 0x80800788: nop

    // 0x8080078C: jal         0x800DA298
    // 0x80800790: addiu       $a0, $zero, 0xA31
    ctx->r4 = ADD32(0, 0XA31);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800790: addiu       $a0, $zero, 0xA31
    ctx->r4 = ADD32(0, 0XA31);
    after_4:
    // 0x80800794: bne         $v0, $zero, L_808007E4
    if (ctx->r2 != 0) {
        // 0x80800798: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007E4;
    }
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080079C: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    // 0x808007A0: jal         0x8008A768
    // 0x808007A4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _sumissilehome_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808007A4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_5:
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007AC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808007B0: jal         0x8008A780
    // 0x808007B4: lh          $a2, 0x3A($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X3A);
    _sumissilehome_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808007B4: lh          $a2, 0x3A($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X3A);
    after_6:
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808007C0: jal         0x8008A770
    // 0x808007C4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _sumissilehome_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808007C4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_7:
    // 0x808007C8: lui         $a2, 0x45BB
    ctx->r6 = S32(0X45BB << 16);
    // 0x808007CC: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D4: jal         0x8008A778
    // 0x808007D8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _sumissilehome_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808007D8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x808007DC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x808007E0: sb          $t8, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r24;
L_808007E4:
    // 0x808007E4: jal         0x8008A458
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808007EC: jal         0x8010A570
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_10;
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808007F4: jal         0x800F693C
    // 0x808007F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800F693C(rdram, ctx);
        goto after_11;
    // 0x808007F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_11:
    // 0x808007FC: beq         $v0, $zero, L_80800814
    if (ctx->r2 == 0) {
        // 0x80800800: nop
    
            goto L_80800814;
    }
    // 0x80800800: nop

    // 0x80800804: lbu         $t9, 0x75($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X75);
    // 0x80800808: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x8080080C: b           L_80800830
    // 0x80800810: sb          $t0, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r8;
        goto L_80800830;
    // 0x80800810: sb          $t0, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r8;
L_80800814:
    // 0x80800814: jal         0x800F690C
    // 0x80800818: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800F690C(rdram, ctx);
        goto after_12;
    // 0x80800818: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_12:
    // 0x8080081C: beql        $v0, $zero, L_80800834
    if (ctx->r2 == 0) {
        // 0x80800820: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800834;
    }
    goto skip_0;
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800824: lbu         $t1, 0x75($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X75);
    // 0x80800828: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x8080082C: sb          $t2, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r10;
L_80800830:
    // 0x80800830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800834:
    // 0x80800834: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800838: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080083C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800840: jr          $ra
    // 0x80800844: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800844: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808008A0_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008B0: jal         0x80100094
    // 0x808008B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008B8: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x808008BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808008C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808008C4: beq         $t6, $zero, L_808008D4
    if (ctx->r14 == 0) {
        // 0x808008C8: nop
    
            goto L_808008D4;
    }
    // 0x808008C8: nop

    // 0x808008CC: b           L_808008D4
    // 0x808008D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_808008D4;
    // 0x808008D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_808008D4:
    // 0x808008D4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808008D8: andi        $t7, $a0, 0x4000
    ctx->r15 = ctx->r4 & 0X4000;
    // 0x808008DC: beq         $t7, $zero, L_80800914
    if (ctx->r15 == 0) {
        // 0x808008E0: andi        $t8, $a0, 0x80
        ctx->r24 = ctx->r4 & 0X80;
            goto L_80800914;
    }
    // 0x808008E0: andi        $t8, $a0, 0x80
    ctx->r24 = ctx->r4 & 0X80;
    // 0x808008E4: beql        $t8, $zero, L_80800914
    if (ctx->r24 == 0) {
        // 0x808008E8: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80800914;
    }
    goto skip_0;
    // 0x808008E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    skip_0:
    // 0x808008EC: lhu         $a0, 0x2A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2A);
    // 0x808008F0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808008F4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x808008F8: andi        $t9, $a0, 0x7FFF
    ctx->r25 = ctx->r4 & 0X7FFF;
    // 0x808008FC: jal         0x800DA298
    // 0x80800900: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800900: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x80800904: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800908: bne         $v0, $zero, L_80800914
    if (ctx->r2 != 0) {
        // 0x8080090C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80800914;
    }
    // 0x8080090C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800910: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_80800914:
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: jal         0x80800B14
    // 0x8080091C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80800B14_chdoor(rdram, ctx);
        goto after_2;
    // 0x8080091C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800920: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800924: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80800928: srl         $t1, $t0, 26
    ctx->r9 = S32(U32(ctx->r8) >> 26);
    // 0x8080092C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80800930: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x80800934: beq         $at, $zero, L_808009D8
    if (ctx->r1 == 0) {
        // 0x80800938: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808009D8;
    }
    // 0x80800938: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8080093C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1148, 0X1558) << 16);
    // 0x80800940: addu        $at, $at, $t2
    gpr jr_addend_80800948 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80800944: lw          $t2, 0x1558($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1148, 0X1558));
    // 0x80800948: jr          $t2
    // 0x8080094C: nop

    switch (jr_addend_80800948 >> 2) {
        case 0: goto L_80800950; break;
        case 1: goto L_80800968; break;
        case 2: goto L_8080097C; break;
        case 3: goto L_80800994; break;
        case 4: goto L_808009CC; break;
        default: switch_error(__func__, 0x80800948, 0x80801558);
    }
    // 0x8080094C: nop

L_80800950:
    // 0x80800950: lh          $t3, 0x10($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X10);
    // 0x80800954: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800958: nop

    // 0x8080095C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800960: b           L_808009D8
    // 0x80800964: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
        goto L_808009D8;
    // 0x80800964: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
L_80800968:
    // 0x80800968: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080096C: jal         0x800EE88C
    // 0x80800970: addiu       $a1, $v1, 0x16
    ctx->r5 = ADD32(ctx->r3, 0X16);
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x80800970: addiu       $a1, $v1, 0x16
    ctx->r5 = ADD32(ctx->r3, 0X16);
    after_3:
    // 0x80800974: b           L_808009D8
    // 0x80800978: nop

        goto L_808009D8;
    // 0x80800978: nop

L_8080097C:
    // 0x8080097C: lh          $t4, 0x10($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X10);
    // 0x80800980: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80800984: nop

    // 0x80800988: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080098C: b           L_808009D8
    // 0x80800990: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
        goto L_808009D8;
    // 0x80800990: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_80800994:
    // 0x80800994: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800998: addiu       $a1, $v1, 0x16
    ctx->r5 = ADD32(ctx->r3, 0X16);
    // 0x8080099C: jal         0x800EE88C
    // 0x808009A0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800EE88C(rdram, ctx);
        goto after_4;
    // 0x808009A0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x808009A4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808009A8: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x808009AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009B0: lh          $t5, 0x1C($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1C);
    // 0x808009B4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x808009B8: nop

    // 0x808009BC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808009C0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808009C4: b           L_808009D8
    // 0x808009C8: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
        goto L_808009D8;
    // 0x808009C8: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
L_808009CC:
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: jal         0x80089C98
    // 0x808009D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808009D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_808009D8:
    // 0x808009D8: jal         0x80103014
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_6;
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808009E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009EC: jr          $ra
    // 0x808009F0: nop

    return;
    // 0x808009F0: nop

;}
RECOMP_FUNC void func_80094F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094F38: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80094F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80094F40: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80094F44: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80094F48: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80094F4C: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80094F50: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80094F54: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80094F58: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x80094F5C: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x80094F60: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80094F64: sb          $zero, 0x2($t2)
    MEM_B(0X2, ctx->r10) = 0;
    // 0x80094F68: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x80094F6C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80094F70: jr          $ra
    // 0x80094F74: sb          $zero, 0x3($t4)
    MEM_B(0X3, ctx->r12) = 0;
    return;
    // 0x80094F74: sb          $zero, 0x3($t4)
    MEM_B(0X3, ctx->r12) = 0;
    // 0x80094F78: nop

    // 0x80094F7C: nop

;}
