#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800314_gclevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2662, 0X3D0) << 16);
    // 0x80800318: lh          $t6, 0x3D0($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(2662, 0X3D0));
    // 0x8080031C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2662, 0X3D8) << 16);
    // 0x80800320: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2662, 0X3D0) << 16);
    // 0x80800324: bne         $a0, $t6, L_80800334
    if (ctx->r4 != ctx->r14) {
        // 0x80800328: nop
    
            goto L_80800334;
    }
    // 0x80800328: nop

    // 0x8080032C: jr          $ra
    // 0x80800330: addiu       $v0, $v0, 0x3D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2662, 0X3D0));
    return;
    // 0x80800330: addiu       $v0, $v0, 0x3D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2662, 0X3D0));
L_80800334:
    // 0x80800334: lh          $t7, 0x3D8($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(2662, 0X3D8));
    // 0x80800338: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2662, 0X3E0) << 16);
    // 0x8080033C: addiu       $v1, $v1, 0x3E0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2662, 0X3E0));
    // 0x80800340: bne         $a0, $t7, L_80800354
    if (ctx->r4 != ctx->r15) {
        // 0x80800344: lui         $v0, 0x8080
        ctx->r2 = S32(RELOC_HI16(2662, 0X420) << 16);
            goto L_80800354;
    }
    // 0x80800344: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2662, 0X420) << 16);
    // 0x80800348: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2662, 0X3D8) << 16);
    // 0x8080034C: jr          $ra
    // 0x80800350: addiu       $v0, $v0, 0x3D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2662, 0X3D8));
    return;
    // 0x80800350: addiu       $v0, $v0, 0x3D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2662, 0X3D8));
L_80800354:
    // 0x80800354: addiu       $v0, $v0, 0x420
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2662, 0X420));
    // 0x80800358: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
L_8080035C:
    // 0x8080035C: bnel        $a0, $t8, L_80800370
    if (ctx->r4 != ctx->r24) {
        // 0x80800360: lh          $t9, 0x8($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X8);
            goto L_80800370;
    }
    goto skip_0;
    // 0x80800360: lh          $t9, 0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X8);
    skip_0:
    // 0x80800364: jr          $ra
    // 0x80800368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080036C: lh          $t9, 0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X8);
L_80800370:
    // 0x80800370: bnel        $a0, $t9, L_80800384
    if (ctx->r4 != ctx->r25) {
        // 0x80800374: lh          $t0, 0x10($v1)
        ctx->r8 = MEM_H(ctx->r3, 0X10);
            goto L_80800384;
    }
    goto skip_1;
    // 0x80800374: lh          $t0, 0x10($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X10);
    skip_1:
    // 0x80800378: jr          $ra
    // 0x8080037C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    return;
    // 0x8080037C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80800380: lh          $t0, 0x10($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X10);
L_80800384:
    // 0x80800384: bnel        $a0, $t0, L_80800398
    if (ctx->r4 != ctx->r8) {
        // 0x80800388: lh          $t1, 0x18($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X18);
            goto L_80800398;
    }
    goto skip_2;
    // 0x80800388: lh          $t1, 0x18($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X18);
    skip_2:
    // 0x8080038C: jr          $ra
    // 0x80800390: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    return;
    // 0x80800390: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80800394: lh          $t1, 0x18($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X18);
L_80800398:
    // 0x80800398: bnel        $a0, $t1, L_808003AC
    if (ctx->r4 != ctx->r9) {
        // 0x8080039C: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_808003AC;
    }
    goto skip_3;
    // 0x8080039C: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    skip_3:
    // 0x808003A0: jr          $ra
    // 0x808003A4: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    return;
    // 0x808003A4: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x808003A8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
L_808003AC:
    // 0x808003AC: bnel        $v1, $v0, L_8080035C
    if (ctx->r3 != ctx->r2) {
        // 0x808003B0: lh          $t8, 0x0($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X0);
            goto L_8080035C;
    }
    goto skip_4;
    // 0x808003B0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    skip_4:
    // 0x808003B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003B8: jr          $ra
    // 0x808003BC: nop

    return;
    // 0x808003BC: nop

;}
RECOMP_FUNC void _bsturn_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084108: syscall     103
    recomp_syscall_handler(rdram, ctx, 0x80084108);
    return;
    // 0x8008410C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void plcamera_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800F5EF8
    // 0x8080000C: nop

    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800014: jal         0x80110014
    // 0x80800018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x80800018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080001C: jal         0x801108A0
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_801108A0(rdram, ctx);
        goto after_2;
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800024: jal         0x8010FD88
    // 0x80800028: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8010FD88(rdram, ctx);
        goto after_3;
    // 0x80800028: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_80800224_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080022C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800230: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x80800234: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80800238: jal         0x80086880
    // 0x8080023C: addiu       $a3, $zero, 0xD5
    ctx->r7 = ADD32(0, 0XD5);
    _chdoormake_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080023C: addiu       $a3, $zero, 0xD5
    ctx->r7 = ADD32(0, 0XD5);
    after_0:
    // 0x80800240: beq         $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x80800244: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800270;
    }
    // 0x80800244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800248: jal         0x800868C0
    // 0x8080024C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080024C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800250: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800254: jal         0x800868A8
    // 0x80800258: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800258: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_2:
    // 0x8080025C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800264: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800268: jal         0x800868C8
    // 0x8080026C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x8080026C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_3:
L_80800270:
    // 0x80800270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800278: jr          $ra
    // 0x8080027C: nop

    return;
    // 0x8080027C: nop

;}
RECOMP_FUNC void badrone_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80800194: sw          $a1, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r5;
    // 0x80800198: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x8080019C: jr          $ra
    // 0x808001A0: sw          $a2, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r6;
    return;
    // 0x808001A0: sw          $a2, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r6;
;}
RECOMP_FUNC void badata_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A54: jal         0x80800000
    // 0x80800A58: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800A58: nop

    after_0:
    // 0x80800A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(473, 0X1640) << 16);
    // 0x80800A64: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80800A68: lbu         $v0, 0x1640($at)
    ctx->r2 = MEM_BU(ctx->r1, (int16_t)RELOC_LO16(473, 0X1640));
    // 0x80800A6C: jr          $ra
    // 0x80800A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800E44_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800E4C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800E58: jal         0x80088718
    // 0x80800E5C: lw          $a1, 0xCC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XCC);
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800E5C: lw          $a1, 0xCC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XCC);
    after_0:
    // 0x80800E60: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x80800E64: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    // 0x80800E68: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800E6C: beq         $a1, $t7, L_80800E94
    if (ctx->r5 == ctx->r15) {
        // 0x80800E70: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_80800E94;
    }
    // 0x80800E70: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80800E74: addiu       $a0, $v0, 0x3
    ctx->r4 = ADD32(ctx->r2, 0X3);
    // 0x80800E78: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
L_80800E7C:
    // 0x80800E7C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80800E80: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800E84: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80800E88: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80800E8C: bnel        $a1, $t9, L_80800E7C
    if (ctx->r5 != ctx->r25) {
        // 0x80800E90: lbu         $t8, 0x1($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X1);
            goto L_80800E7C;
    }
    goto skip_0;
    // 0x80800E90: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    skip_0:
L_80800E94:
    // 0x80800E94: addu        $t0, $v1, $a2
    ctx->r8 = ADD32(ctx->r3, ctx->r6);
    // 0x80800E98: lbu         $a1, 0x2($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X2);
    // 0x80800E9C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800EA0: addiu       $a1, $a1, -0x31
    ctx->r5 = ADD32(ctx->r5, -0X31);
    // 0x80800EA4: lw          $a0, 0xCC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XCC);
    // 0x80800EA8: jal         0x80088728
    // 0x80800EAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800EAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800EB0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EB4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800EB8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80800EBC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_80800EC0:
    // 0x80800EC0: lb          $t2, 0x60($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X60);
    // 0x80800EC4: bnel        $a1, $t2, L_80800ED8
    if (ctx->r5 != ctx->r10) {
        // 0x80800EC8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800ED8;
    }
    goto skip_1;
    // 0x80800EC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80800ECC: b           L_80800EE4
    // 0x80800ED0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800EE4;
    // 0x80800ED0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800ED4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800ED8:
    // 0x80800ED8: bne         $v1, $a0, L_80800EC0
    if (ctx->r3 != ctx->r4) {
        // 0x80800EDC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80800EC0;
    }
    // 0x80800EDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800EE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800EE4:
    // 0x80800EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800EEC: jr          $ra
    // 0x80800EF0: nop

    return;
    // 0x80800EF0: nop

;}
RECOMP_FUNC void sukickball_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ECC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800ED0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800ED4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800ED8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EDC: jal         0x80102D78
    // 0x80800EE0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_0;
    // 0x80800EE0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_0:
    // 0x80800EE4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800EE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800EEC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800EF0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800EF4: bnel        $t7, $at, L_80800F14
    if (ctx->r15 != ctx->r1) {
        // 0x80800EF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F14;
    }
    goto skip_0;
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800EFC: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800F00: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x80800F04: jal         0x80800F40
    // 0x80800F08: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    sukickball_entrypoint_15(rdram, ctx);
        goto after_1;
    // 0x80800F08: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x80800F0C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F14:
    // 0x80800F14: jal         0x80102CF4
    // 0x80800F18: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102CF4(rdram, ctx);
        goto after_2;
    // 0x80800F18: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_2:
    // 0x80800F1C: bne         $v0, $zero, L_80800F2C
    if (ctx->r2 != 0) {
        // 0x80800F20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F2C;
    }
    // 0x80800F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F24: jal         0x80102B2C
    // 0x80800F28: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102B2C(rdram, ctx);
        goto after_3;
    // 0x80800F28: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_3:
L_80800F2C:
    // 0x80800F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F38: jr          $ra
    // 0x80800F3C: nop

    return;
    // 0x80800F3C: nop

;}
RECOMP_FUNC void cheggfire_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2108, 0X3BC) << 16);
    // 0x8080025C: jr          $ra
    // 0x80800260: addiu       $v0, $v0, 0x3BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2108, 0X3BC));
    return;
    // 0x80800260: addiu       $v0, $v0, 0x3BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2108, 0X3BC));
;}
RECOMP_FUNC void func_8080045C_gcmapDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080045C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800460: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80800464: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800468: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080046C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80800470: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800478: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080047C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800480: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80800484: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800488: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080048C: beq         $t8, $zero, L_808004A8
    if (ctx->r24 == 0) {
        // 0x80800490: sw          $t8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r24;
            goto L_808004A8;
    }
    // 0x80800490: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80800494: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80800498: jal         0x800B2198
    // 0x8080049C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_800B2198(rdram, ctx);
        goto after_0;
    // 0x8080049C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x808004A0: b           L_80800598
    // 0x808004A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800598;
    // 0x808004A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004A8:
    // 0x808004A8: jal         0x800EA05C
    // 0x808004AC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x808004AC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x808004B0: addiu       $at, $zero, 0x159
    ctx->r1 = ADD32(0, 0X159);
    // 0x808004B4: beq         $v0, $at, L_80800574
    if (ctx->r2 == ctx->r1) {
        // 0x808004B8: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_80800574;
    }
    // 0x808004B8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808004BC: addiu       $at, $zero, 0x1A7
    ctx->r1 = ADD32(0, 0X1A7);
    // 0x808004C0: beq         $v0, $at, L_808004E8
    if (ctx->r2 == ctx->r1) {
        // 0x808004C4: addiu       $t0, $zero, -0x4650
        ctx->r8 = ADD32(0, -0X4650);
            goto L_808004E8;
    }
    // 0x808004C4: addiu       $t0, $zero, -0x4650
    ctx->r8 = ADD32(0, -0X4650);
    // 0x808004C8: addiu       $at, $zero, 0x1A8
    ctx->r1 = ADD32(0, 0X1A8);
    // 0x808004CC: beq         $v0, $at, L_80800518
    if (ctx->r2 == ctx->r1) {
        // 0x808004D0: addiu       $t6, $zero, -0x4E20
        ctx->r14 = ADD32(0, -0X4E20);
            goto L_80800518;
    }
    // 0x808004D0: addiu       $t6, $zero, -0x4E20
    ctx->r14 = ADD32(0, -0X4E20);
    // 0x808004D4: addiu       $at, $zero, 0x1A9
    ctx->r1 = ADD32(0, 0X1A9);
    // 0x808004D8: beq         $v0, $at, L_80800548
    if (ctx->r2 == ctx->r1) {
        // 0x808004DC: addiu       $t2, $zero, 0x3E8
        ctx->r10 = ADD32(0, 0X3E8);
            goto L_80800548;
    }
    // 0x808004DC: addiu       $t2, $zero, 0x3E8
    ctx->r10 = ADD32(0, 0X3E8);
    // 0x808004E0: b           L_80800598
    // 0x808004E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800598;
    // 0x808004E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004E8:
    // 0x808004E8: addiu       $t1, $zero, -0x1770
    ctx->r9 = ADD32(0, -0X1770);
    // 0x808004EC: addiu       $t2, $zero, -0x3E80
    ctx->r10 = ADD32(0, -0X3E80);
    // 0x808004F0: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x808004F4: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x808004F8: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x808004FC: addiu       $t3, $zero, 0xBB8
    ctx->r11 = ADD32(0, 0XBB8);
    // 0x80800500: addiu       $t4, $zero, 0x2EE0
    ctx->r12 = ADD32(0, 0X2EE0);
    // 0x80800504: addiu       $t5, $zero, 0x3A98
    ctx->r13 = ADD32(0, 0X3A98);
    // 0x80800508: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8080050C: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x80800510: b           L_80800594
    // 0x80800514: sw          $t5, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r13;
        goto L_80800594;
    // 0x80800514: sw          $t5, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r13;
L_80800518:
    // 0x80800518: addiu       $t7, $zero, -0x1F40
    ctx->r15 = ADD32(0, -0X1F40);
    // 0x8080051C: addiu       $t8, $zero, -0xBB8
    ctx->r24 = ADD32(0, -0XBB8);
    // 0x80800520: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80800524: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80800528: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8080052C: addiu       $t9, $zero, 0x1B58
    ctx->r25 = ADD32(0, 0X1B58);
    // 0x80800530: addiu       $t0, $zero, 0x7D0
    ctx->r8 = ADD32(0, 0X7D0);
    // 0x80800534: addiu       $t1, $zero, 0x3A98
    ctx->r9 = ADD32(0, 0X3A98);
    // 0x80800538: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8080053C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80800540: b           L_80800594
    // 0x80800544: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
        goto L_80800594;
    // 0x80800544: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
L_80800548:
    // 0x80800548: addiu       $t3, $zero, -0x2EE0
    ctx->r11 = ADD32(0, -0X2EE0);
    // 0x8080054C: addiu       $t4, $zero, -0x32C8
    ctx->r12 = ADD32(0, -0X32C8);
    // 0x80800550: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80800554: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80800558: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    // 0x8080055C: addiu       $t5, $zero, 0x4268
    ctx->r13 = ADD32(0, 0X4268);
    // 0x80800560: addiu       $t6, $zero, 0x2EE0
    ctx->r14 = ADD32(0, 0X2EE0);
    // 0x80800564: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80800568: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8080056C: b           L_80800594
    // 0x80800570: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
        goto L_80800594;
    // 0x80800570: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
L_80800574:
    // 0x80800574: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
    // 0x80800578: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x8080057C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80800580: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80800584: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800588: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x8080058C: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x80800590: sw          $v1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r3;
L_80800594:
    // 0x80800594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800598:
    // 0x80800598: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080059C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005A0: jr          $ra
    // 0x808005A4: nop

    return;
    // 0x808005A4: nop

;}
RECOMP_FUNC void cheggnormal_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800310: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800318: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080031C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800320: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800324: jal         0x8008A488
    // 0x80800328: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800328: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080032C: addiu       $a0, $zero, 0x15A
    ctx->r4 = ADD32(0, 0X15A);
    // 0x80800330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800334: jal         0x8008A3D0
    // 0x80800338: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800338: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8080033C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800344: jal         0x80100094
    // 0x80800348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080034C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800350: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800354: sb          $t6, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r14;
    // 0x80800358: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2124, 0X4C4) << 16);
    // 0x8080035C: lwc1        $f4, 0x4C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2124, 0X4C4));
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800368: jal         0x8008A380
    // 0x8080036C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    _suegg_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080036C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: jal         0x8008A460
    // 0x80800378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080037C: lui         $a1, 0xC509
    ctx->r5 = S32(0XC509 << 16);
    // 0x80800380: lui         $a2, 0xC6AB
    ctx->r6 = S32(0XC6AB << 16);
    // 0x80800384: ori         $a2, $a2, 0xE000
    ctx->r6 = ctx->r6 | 0XE000;
    // 0x80800388: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8080038C: jal         0x8008A468
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: jal         0x8008A470
    // 0x8080039C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x8080039C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x808003A0: lbu         $t7, 0x72($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X72);
    // 0x808003A4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808003A8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808003AC: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x808003B0: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x808003B4: sb          $t9, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r25;
    // 0x808003B8: lbu         $t0, 0x39($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X39);
    // 0x808003BC: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x808003C0: sb          $t1, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r9;
    // 0x808003C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003D0: jr          $ra
    // 0x808003D4: nop

    return;
    // 0x808003D4: nop

;}
RECOMP_FUNC void func_800DBA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBA84: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DBA88: addiu       $a2, $a2, -0x3820
    ctx->r6 = ADD32(ctx->r6, -0X3820);
    // 0x800DBA8C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800DBA90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DBA94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBA98: bne         $t6, $zero, L_800DBAB4
    if (ctx->r14 != 0) {
        // 0x800DBA9C: addiu       $a0, $zero, 0x54
        ctx->r4 = ADD32(0, 0X54);
            goto L_800DBAB4;
    }
    // 0x800DBA9C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    // 0x800DBAA0: jal         0x800B3268
    // 0x800DBAA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x800DBAA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x800DBAA8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DBAAC: addiu       $a2, $a2, -0x3820
    ctx->r6 = ADD32(ctx->r6, -0X3820);
    // 0x800DBAB0: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800DBAB4:
    // 0x800DBAB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800DBAB8: jal         0x800B3044
    // 0x800DBABC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    freelist_next(rdram, ctx);
        goto after_1;
    // 0x800DBABC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x800DBAC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800DBAC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800DBAC8: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x800DBACC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800DBAD0: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800DBAD4: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x800DBAD8: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x800DBADC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800DBAE0: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x800DBAE4: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x800DBAE8: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x800DBAEC: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800DBAF0: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x800DBAF4: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x800DBAF8: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x800DBAFC: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x800DBB00: sh          $zero, 0x10($v1)
    MEM_H(0X10, ctx->r3) = 0;
    // 0x800DBB04: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x800DBB08: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x800DBB0C: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x800DBB10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DBB14: lbu         $v0, 0x23($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X23);
    // 0x800DBB18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800DBB1C: jr          $ra
    // 0x800DBB20: nop

    return;
    // 0x800DBB20: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808028F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808028F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808028FC: jal         0x800BF704
    // 0x80802900: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80802900: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802904: lbu         $t6, 0x77($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X77);
    // 0x80802908: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8080290C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802910: bne         $t6, $zero, L_80802920
    if (ctx->r14 != 0) {
        // 0x80802914: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_80802920;
    }
    // 0x80802914: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80802918: b           L_80802988
    // 0x8080291C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802988;
    // 0x8080291C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802920:
    // 0x80802920: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80802924: lw          $t8, 0x68($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X68);
    // 0x80802928: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080292C: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80802930: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80802934: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80802938: lw          $t0, 0x4C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4C);
    // 0x8080293C: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x80802940: beql        $t1, $zero, L_80802988
    if (ctx->r9 == 0) {
        // 0x80802944: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802988;
    }
    goto skip_0;
    // 0x80802944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80802948: lw          $t2, 0x68($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X68);
    // 0x8080294C: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x80802950: lhu         $a0, 0x40($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X40);
    // 0x80802954: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802958: jal         0x800D6B0C
    // 0x8080295C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800D6B0C(rdram, ctx);
        goto after_1;
    // 0x8080295C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_1:
    // 0x80802960: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80802964: beq         $v0, $zero, L_80802984
    if (ctx->r2 == 0) {
        // 0x80802968: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80802984;
    }
    // 0x80802968: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080296C: lw          $t4, 0x68($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X68);
    // 0x80802970: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80802974: jal         0x800D62E4
    // 0x80802978: lhu         $a0, 0x40($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X40);
    func_800D62E4(rdram, ctx);
        goto after_2;
    // 0x80802978: lhu         $a0, 0x40($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X40);
    after_2:
    // 0x8080297C: b           L_80802988
    // 0x80802980: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802988;
    // 0x80802980: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802984:
    // 0x80802984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802988:
    // 0x80802988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080298C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802990: jr          $ra
    // 0x80802994: nop

    return;
    // 0x80802994: nop

    // 0x80802998: nop

    // 0x8080299C: nop

;}
RECOMP_FUNC void _suspline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DA0: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DA0);
    return;
    // 0x80089DA4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void scinfobar_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800428: jr          $ra
    // 0x8080042C: sb          $a1, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r5;
    return;
    // 0x8080042C: sb          $a1, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_808008FC_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800900: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800908: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080090C: jal         0x800DA298
    // 0x80800910: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800910: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    after_0:
    // 0x80800914: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1624, 0XD10) << 16);
    // 0x80800918: addiu       $a3, $a3, 0xD10
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1624, 0XD10));
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800920: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800924: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800928: jal         0x80089D50
    // 0x8080092C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080092C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800930: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x80800934: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800938: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8080093C: srl         $t6, $a0, 10
    ctx->r14 = S32(U32(ctx->r4) >> 10);
    // 0x80800940: beq         $t6, $at, L_80800958
    if (ctx->r14 == ctx->r1) {
        // 0x80800944: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800958;
    }
    // 0x80800944: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800948: beq         $t6, $at, L_80800978
    if (ctx->r14 == ctx->r1) {
        // 0x8080094C: nop
    
            goto L_80800978;
    }
    // 0x8080094C: nop

    // 0x80800950: b           L_80800A88
    // 0x80800954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A88;
    // 0x80800954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800958:
    // 0x80800958: beq         $v1, $zero, L_80800A84
    if (ctx->r3 == 0) {
        // 0x8080095C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A84;
    }
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800960: jal         0x80101FDC
    // 0x80800964: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800964: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800968: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
    // 0x8080096C: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800970: b           L_80800A84
    // 0x80800974: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
        goto L_80800A84;
    // 0x80800974: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
L_80800978:
    // 0x80800978: bne         $v1, $zero, L_80800994
    if (ctx->r3 != 0) {
        // 0x8080097C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800994;
    }
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800980: jal         0x80101FDC
    // 0x80800984: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800984: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800988: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    // 0x8080098C: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80800990: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
L_80800994:
    // 0x80800994: jal         0x8010D254
    // 0x80800998: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8010D254(rdram, ctx);
        goto after_4;
    // 0x80800998: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x8080099C: jal         0x80090248
    // 0x808009A0: nop

    func_80090248(rdram, ctx);
        goto after_5;
    // 0x808009A0: nop

    after_5:
    // 0x808009A4: beq         $v0, $zero, L_80800A54
    if (ctx->r2 == 0) {
        // 0x808009A8: lwc1        $f2, 0x28($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800A54;
    }
    // 0x808009A8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808009AC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x808009B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1624, 0XB20) << 16);
    // 0x808009B8: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x808009BC: nop

    // 0x808009C0: bc1f        L_80800A54
    if (!c1cs) {
        // 0x808009C4: nop
    
            goto L_80800A54;
    }
    // 0x808009C4: nop

    // 0x808009C8: lwc1        $f6, 0xB20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1624, 0XB20));
    // 0x808009CC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808009D0: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x808009D4: nop

    // 0x808009D8: bc1f        L_80800A54
    if (!c1cs) {
        // 0x808009DC: nop
    
            goto L_80800A54;
    }
    // 0x808009DC: nop

    // 0x808009E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808009E4: nop

    // 0x808009E8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808009EC: nop

    // 0x808009F0: bc1f        L_80800A54
    if (!c1cs) {
        // 0x808009F4: nop
    
            goto L_80800A54;
    }
    // 0x808009F4: nop

    // 0x808009F8: jal         0x800DA298
    // 0x808009FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808009FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80800A00: beq         $v0, $zero, L_80800A2C
    if (ctx->r2 == 0) {
        // 0x80800A04: nop
    
            goto L_80800A2C;
    }
    // 0x80800A04: nop

    // 0x80800A08: jal         0x800D8FF8
    // 0x80800A0C: nop

    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x80800A0C: nop

    after_7:
    // 0x80800A10: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x80800A14: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A18: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800A1C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800A20: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80800A24: b           L_80800A4C
    // 0x80800A28: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
        goto L_80800A4C;
    // 0x80800A28: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
L_80800A2C:
    // 0x80800A2C: jal         0x800D8FF8
    // 0x80800A30: nop

    func_800D8FF8(rdram, ctx);
        goto after_8;
    // 0x80800A30: nop

    after_8:
    // 0x80800A34: lui         $at, 0x43FC
    ctx->r1 = S32(0X43FC << 16);
    // 0x80800A38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A3C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800A40: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800A44: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80800A48: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
L_80800A4C:
    // 0x80800A4C: jal         0x800907C0
    // 0x80800A50: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800907C0(rdram, ctx);
        goto after_9;
    // 0x80800A50: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_9:
L_80800A54:
    // 0x80800A54: jal         0x800DA298
    // 0x80800A58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800A58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80800A5C: beq         $v0, $zero, L_80800A78
    if (ctx->r2 == 0) {
        // 0x80800A60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A78;
    }
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A68: jal         0x80101CDC
    // 0x80800A6C: lui         $a1, 0x4204
    ctx->r5 = S32(0X4204 << 16);
    func_80101CDC(rdram, ctx);
        goto after_11;
    // 0x80800A6C: lui         $a1, 0x4204
    ctx->r5 = S32(0X4204 << 16);
    after_11:
    // 0x80800A70: b           L_80800A88
    // 0x80800A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A88;
    // 0x80800A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A78:
    // 0x80800A78: lui         $a1, 0x4116
    ctx->r5 = S32(0X4116 << 16);
    // 0x80800A7C: jal         0x80101CDC
    // 0x80800A80: ori         $a1, $a1, 0xDB6E
    ctx->r5 = ctx->r5 | 0XDB6E;
    func_80101CDC(rdram, ctx);
        goto after_12;
    // 0x80800A80: ori         $a1, $a1, 0xDB6E
    ctx->r5 = ctx->r5 | 0XDB6E;
    after_12:
L_80800A84:
    // 0x80800A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A88:
    // 0x80800A88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A90: jr          $ra
    // 0x80800A94: nop

    return;
    // 0x80800A94: nop

;}
RECOMP_FUNC void func_80800018_chboxingglove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800028: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800030: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800034: beq         $t6, $at, L_8080005C
    if (ctx->r14 == ctx->r1) {
        // 0x80800038: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080005C;
    }
    // 0x80800038: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080003C: beq         $t6, $at, L_808000FC
    if (ctx->r14 == ctx->r1) {
        // 0x80800040: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000FC;
    }
    // 0x80800040: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800044: beq         $t6, $at, L_8080011C
    if (ctx->r14 == ctx->r1) {
        // 0x80800048: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080011C;
    }
    // 0x80800048: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080004C: beq         $t6, $at, L_8080013C
    if (ctx->r14 == ctx->r1) {
        // 0x80800050: nop
    
            goto L_8080013C;
    }
    // 0x80800050: nop

    // 0x80800054: b           L_80800158
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800158;
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080005C:
    // 0x8080005C: jal         0x808004F8
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004F8_chboxingglove(rdram, ctx);
        goto after_0;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800064: bnel        $v0, $zero, L_80800158
    if (ctx->r2 != 0) {
        // 0x80800068: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800158;
    }
    goto skip_0;
    // 0x80800068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080006C: jal         0x8008FF18
    // 0x80800070: nop

    func_8008FF18(rdram, ctx);
        goto after_1;
    // 0x80800070: nop

    after_1:
    // 0x80800074: bnel        $v0, $zero, L_80800090
    if (ctx->r2 != 0) {
        // 0x80800078: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_80800090;
    }
    goto skip_1;
    // 0x80800078: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x8080007C: jal         0x8010D248
    // 0x80800080: nop

    func_8010D248(rdram, ctx);
        goto after_2;
    // 0x80800080: nop

    after_2:
    // 0x80800084: bne         $v0, $zero, L_8080009C
    if (ctx->r2 != 0) {
        // 0x80800088: nop
    
            goto L_8080009C;
    }
    // 0x80800088: nop

    // 0x8080008C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_80800090:
    // 0x80800090: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800094: bltzl       $t9, L_80800158
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800098: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800158;
    }
    goto skip_2;
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_8080009C:
    // 0x8080009C: jal         0x800D90A4
    // 0x808000A0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x808000A0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x808000A4: beql        $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x808000A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800158;
    }
    goto skip_3;
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808000AC: jal         0x8010D254
    // 0x808000B0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8010D254(rdram, ctx);
        goto after_4;
    // 0x808000B0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x808000B4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808000B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000BC: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808000C0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808000CC: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x808000D0: nop

    // 0x808000D4: bc1t        L_808000EC
    if (c1cs) {
        // 0x808000D8: nop
    
            goto L_808000EC;
    }
    // 0x808000D8: nop

    // 0x808000DC: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x808000E0: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x808000E4: bltzl       $t2, L_80800158
    if (SIGNED(ctx->r10) < 0) {
        // 0x808000E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800158;
    }
    goto skip_4;
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_808000EC:
    // 0x808000EC: jal         0x808002E0
    // 0x808000F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808002E0_chboxingglove(rdram, ctx);
        goto after_5;
    // 0x808000F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808000F4: b           L_80800158
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800158;
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000FC:
    // 0x808000FC: jal         0x800D90A4
    // 0x80800100: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_6;
    // 0x80800100: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x80800104: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x80800108: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800154;
    }
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x808002E0
    // 0x80800110: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808002E0_chboxingglove(rdram, ctx);
        goto after_7;
    // 0x80800110: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800114: b           L_80800158
    // 0x80800118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800158;
    // 0x80800118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080011C:
    // 0x8080011C: jal         0x80101DDC
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_8;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800124: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800154;
    }
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x808002E0
    // 0x80800130: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808002E0_chboxingglove(rdram, ctx);
        goto after_9;
    // 0x80800130: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800134: b           L_80800158
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800158;
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080013C:
    // 0x8080013C: jal         0x800D90A4
    // 0x80800140: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_10;
    // 0x80800140: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_10:
    // 0x80800144: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x80800148: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800154;
    }
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x808002E0
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808002E0_chboxingglove(rdram, ctx);
        goto after_11;
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
L_80800154:
    // 0x80800154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800158:
    // 0x80800158: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void bskazjump_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800474: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800478: jal         0x800C6E38
    // 0x8080047C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8080047C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80800480: beq         $v0, $zero, L_80800490
    if (ctx->r2 == 0) {
        // 0x80800484: nop
    
            goto L_80800490;
    }
    // 0x80800484: nop

    // 0x80800488: jal         0x800C6DA0
    // 0x8080048C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800C6DA0(rdram, ctx);
        goto after_1;
    // 0x8080048C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_1:
L_80800490:
    // 0x80800490: jal         0x8009BC6C
    // 0x80800494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x80800494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800498: jal         0x800832E8
    // 0x8080049C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080049C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808004A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004A8: jr          $ra
    // 0x808004AC: nop

    return;
    // 0x808004AC: nop

;}
RECOMP_FUNC void capod_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800568: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080056C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800570: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800574: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800578: jal         0x8008FFE8
    // 0x8080057C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x8080057C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800580: beq         $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x80800584: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808005B0;
    }
    // 0x80800584: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800588: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8080058C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800590: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800594: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800598: jal         0x800895C8
    // 0x8080059C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    _ncpod_entrypoint_33(rdram, ctx);
        goto after_1;
    // 0x8080059C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x808005A0: beql        $v0, $zero, L_808005B4
    if (ctx->r2 == 0) {
        // 0x808005A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808005B4;
    }
    goto skip_0;
    // 0x808005A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808005A8: b           L_808005B4
    // 0x808005AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005B4;
    // 0x808005AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B0:
    // 0x808005B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005B4:
    // 0x808005B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005BC: jr          $ra
    // 0x808005C0: nop

    return;
    // 0x808005C0: nop

;}
RECOMP_FUNC void func_80092C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092C98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80092C9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80092CA0: lw          $t7, 0x50($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X50);
    // 0x80092CA4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80092CA8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80092CAC: jal         0x800DBEFC
    // 0x80092CB0: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_0;
    // 0x80092CB0: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_0:
    // 0x80092CB4: jal         0x800EEEA8
    // 0x80092CB8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EEEA8(rdram, ctx);
        goto after_1;
    // 0x80092CB8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80092CBC: beq         $v0, $zero, L_80092CCC
    if (ctx->r2 == 0) {
        // 0x80092CC0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80092CCC;
    }
    // 0x80092CC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80092CC4: jal         0x8009C128
    // 0x80092CC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x80092CC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80092CCC:
    // 0x80092CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092CD4: jr          $ra
    // 0x80092CD8: nop

    return;
    // 0x80092CD8: nop

;}
RECOMP_FUNC void func_80800790_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800790: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800794: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800798: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080079C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007A0: jal         0x80100094
    // 0x808007A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007A8: jal         0x800F54E4
    // 0x808007AC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808007AC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808007B0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808007B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808007B8: jal         0x800BF744
    // 0x808007BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x808007BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808007C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808007C4: jal         0x800BF744
    // 0x808007C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_3;
    // 0x808007C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808007CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007D0: jal         0x800F4CEC
    // 0x808007D4: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    func_800F4CEC(rdram, ctx);
        goto after_4;
    // 0x808007D4: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    after_4:
    // 0x808007D8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808007DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007E4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808007E8: bne         $t7, $at, L_8080089C
    if (ctx->r15 != ctx->r1) {
        // 0x808007EC: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8080089C;
    }
    // 0x808007EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808007F8: addiu       $a2, $zero, 0x320
    ctx->r6 = ADD32(0, 0X320);
    // 0x808007FC: jal         0x8008A2F0
    // 0x80800800: addiu       $a3, $zero, 0x1AE
    ctx->r7 = ADD32(0, 0X1AE);
    _susubgame_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800800: addiu       $a3, $zero, 0x1AE
    ctx->r7 = ADD32(0, 0X1AE);
    after_5:
    // 0x80800804: beq         $v0, $zero, L_80800838
    if (ctx->r2 == 0) {
        // 0x80800808: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800838;
    }
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080080C: jal         0x800861A8
    // 0x80800810: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800810: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80800814: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080081C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800820: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800824: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800828: jal         0x8008A2D0
    // 0x8080082C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x8080082C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_7:
    // 0x80800830: b           L_8080087C
    // 0x80800834: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_8080087C;
    // 0x80800834: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800838:
    // 0x80800838: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080083C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800844: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800848: jal         0x8008A2C8
    // 0x8080084C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x8080084C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_8:
    // 0x80800850: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800854: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x80800858: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080085C: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800860: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800864: jal         0x8008A208
    // 0x80800868: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80800868: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x8080086C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800870: jal         0x800F82D4
    // 0x80800874: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_10;
    // 0x80800874: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800878: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8080087C:
    // 0x8080087C: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x80800880: jal         0x800F7C58
    // 0x80800884: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F7C58(rdram, ctx);
        goto after_11;
    // 0x80800884: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080088C: jal         0x80101FDC
    // 0x80800890: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x80800890: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80800894: b           L_808008E0
    // 0x80800898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008E0;
    // 0x80800898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080089C:
    // 0x8080089C: jal         0x800F8300
    // 0x808008A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F8300(rdram, ctx);
        goto after_13;
    // 0x808008A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x808008A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808008B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808008B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808008B8: jal         0x8008A2C8
    // 0x808008BC: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_14;
    // 0x808008BC: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_14:
    // 0x808008C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808008C4: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x808008C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808008CC: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x808008D0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x808008D4: jal         0x8008A208
    // 0x808008D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x808008D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x808008DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008E0:
    // 0x808008E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808008E8: jr          $ra
    // 0x808008EC: nop

    return;
    // 0x808008EC: nop

;}
RECOMP_FUNC void func_8080070C_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080070C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800714: jal         0x80085230
    // 0x80800718: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800718: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080071C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800720: jal         0x8009BF5C
    // 0x80800724: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800724: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800728: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080072C: jal         0x8009C4CC
    // 0x80800730: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x80800730: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080073C: jr          $ra
    // 0x80800740: nop

    return;
    // 0x80800740: nop

;}
RECOMP_FUNC void func_800F6C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6C1C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6C20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6C24: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6C28: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6C2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6C34: jal         0x8009E6F8
    // 0x800F6C38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F6C38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6C3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6C40: jal         0x8009CB44
    // 0x800F6C44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8009CB44(rdram, ctx);
        goto after_1;
    // 0x800F6C44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800F6C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6C4C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F6C50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F6C54: jr          $ra
    // 0x800F6C58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F6C58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002241C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002241C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80022420: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80022424: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80022428: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002242C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80022430: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80022434: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80022438: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8002243C: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
L_80022440:
    // 0x80022440: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80022444: lhu         $t8, 0x38($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X38);
    // 0x80022448: sltiu       $at, $t8, 0x1A
    ctx->r1 = ctx->r24 < 0X1A ? 1 : 0;
    // 0x8002244C: beq         $at, $zero, L_80022CB0
    if (ctx->r1 == 0) {
        // 0x80022450: nop
    
            goto L_80022CB0;
    }
    // 0x80022450: nop

    // 0x80022454: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80022458: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002245C: addu        $at, $at, $t8
    gpr jr_addend_80022464 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80022460: lw          $t8, 0x19A0($at)
    ctx->r24 = ADD32(ctx->r1, 0X19A0);
    // 0x80022464: jr          $t8
    // 0x80022468: nop

    switch (jr_addend_80022464 >> 2) {
        case 0: goto L_8002246C; break;
        case 1: goto L_80022CA8; break;
        case 2: goto L_80022858; break;
        case 3: goto L_80022CA8; break;
        case 4: goto L_80022CA8; break;
        case 5: goto L_800224A4; break;
        case 6: goto L_800224FC; break;
        case 7: goto L_80022870; break;
        case 8: goto L_80022CB0; break;
        case 9: goto L_8002247C; break;
        case 10: goto L_80022888; break;
        case 11: goto L_80022CB0; break;
        case 12: goto L_80022C38; break;
        case 13: goto L_80022C70; break;
        case 14: goto L_80022CA0; break;
        case 15: goto L_80022A08; break;
        case 16: goto L_80022A38; break;
        case 17: goto L_80022AC0; break;
        case 18: goto L_80022CB0; break;
        case 19: goto L_80022CB0; break;
        case 20: goto L_80022CB0; break;
        case 21: goto L_80022858; break;
        case 22: goto L_80022590; break;
        case 23: goto L_800226D0; break;
        case 24: goto L_800228F8; break;
        case 25: goto L_80022974; break;
        default: switch_error(__func__, 0x80022464, 0x800419A0);
    }
    // 0x80022468: nop

L_8002246C:
    // 0x8002246C: jal         0x80022D1C
    // 0x80022470: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    func_80022D1C(rdram, ctx);
        goto after_0;
    // 0x80022470: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_0:
    // 0x80022474: b           L_80022CB0
    // 0x80022478: nop

        goto L_80022CB0;
    // 0x80022478: nop

L_8002247C:
    // 0x8002247C: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80022480: sh          $t9, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r25;
    // 0x80022484: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80022488: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8002248C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80022490: addiu       $a0, $t0, 0x48
    ctx->r4 = ADD32(ctx->r8, 0X48);
    // 0x80022494: jal         0x80026500
    // 0x80022498: lw          $a2, 0x5C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X5C);
    func_80026500(rdram, ctx);
        goto after_1;
    // 0x80022498: lw          $a2, 0x5C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X5C);
    after_1:
    // 0x8002249C: b           L_80022CB0
    // 0x800224A0: nop

        goto L_80022CB0;
    // 0x800224A0: nop

L_800224A4:
    // 0x800224A4: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x800224A8: lw          $t2, 0x3C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X3C);
    // 0x800224AC: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800224B0: jal         0x80026FF0
    // 0x800224B4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80026FF0(rdram, ctx);
        goto after_2;
    // 0x800224B4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_2:
    // 0x800224B8: jal         0x80027090
    // 0x800224BC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80027090(rdram, ctx);
        goto after_3;
    // 0x800224BC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_3:
    // 0x800224C0: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800224C4: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x800224C8: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x800224CC: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800224D0: lbu         $t6, 0x3B($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X3B);
    // 0x800224D4: beq         $t6, $zero, L_800224E8
    if (ctx->r14 == 0) {
        // 0x800224D8: nop
    
            goto L_800224E8;
    }
    // 0x800224D8: nop

    // 0x800224DC: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800224E0: jal         0x8002A6A4
    // 0x800224E4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_8002A6A4(rdram, ctx);
        goto after_4;
    // 0x800224E4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_4:
L_800224E8:
    // 0x800224E8: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800224EC: jal         0x80029670
    // 0x800224F0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_80029670(rdram, ctx);
        goto after_5;
    // 0x800224F0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_5:
    // 0x800224F4: b           L_80022CB0
    // 0x800224F8: nop

        goto L_80022CB0;
    // 0x800224F8: nop

L_800224FC:
    // 0x800224FC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80022500: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x80022504: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80022508: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8002250C: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80022510: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80022514: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80022518: lbu         $t2, 0x38($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X38);
    // 0x8002251C: bne         $t2, $zero, L_80022530
    if (ctx->r10 != 0) {
        // 0x80022520: nop
    
            goto L_80022530;
    }
    // 0x80022520: nop

    // 0x80022524: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80022528: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002252C: sb          $t3, 0x38($t4)
    MEM_B(0X38, ctx->r12) = ctx->r11;
L_80022530:
    // 0x80022530: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80022534: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x80022538: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x8002253C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80022540: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80022544: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80022548: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x8002254C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80022550: sw          $t0, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r8;
    // 0x80022554: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80022558: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8002255C: lbu         $t3, 0x44($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X44);
    // 0x80022560: sb          $t3, 0x34($t4)
    MEM_B(0X34, ctx->r12) = ctx->r11;
    // 0x80022564: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80022568: jal         0x80029D54
    // 0x8002256C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_80029D54(rdram, ctx);
        goto after_6;
    // 0x8002256C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_6:
    // 0x80022570: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80022574: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80022578: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002257C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80022580: jal         0x80026BE0
    // 0x80022584: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    func_80026BE0(rdram, ctx);
        goto after_7;
    // 0x80022584: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_7:
    // 0x80022588: b           L_80022CB0
    // 0x8002258C: nop

        goto L_80022CB0;
    // 0x8002258C: nop

L_80022590:
    // 0x80022590: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80022594: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x80022598: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x8002259C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800225A0: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x800225A4: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x800225A8: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800225AC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800225B0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800225B4: lw          $t9, 0x74($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X74);
    // 0x800225B8: jalr        $t9
    // 0x800225BC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800225BC: nop

    after_8:
    // 0x800225C0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800225C4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800225C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800225CC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800225D0: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800225D4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800225D8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800225DC: nop

    // 0x800225E0: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800225E4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800225E8: beq         $t1, $zero, L_8002263C
    if (ctx->r9 == 0) {
        // 0x800225EC: nop
    
            goto L_8002263C;
    }
    // 0x800225EC: nop

    // 0x800225F0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800225F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800225F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800225FC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80022600: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80022604: nop

    // 0x80022608: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002260C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80022610: nop

    // 0x80022614: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x80022618: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8002261C: bne         $t1, $zero, L_80022634
    if (ctx->r9 != 0) {
        // 0x80022620: nop
    
            goto L_80022634;
    }
    // 0x80022620: nop

    // 0x80022624: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80022628: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002262C: b           L_8002264C
    // 0x80022630: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_8002264C;
    // 0x80022630: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80022634:
    // 0x80022634: b           L_8002264C
    // 0x80022638: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_8002264C;
    // 0x80022638: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_8002263C:
    // 0x8002263C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80022640: nop

    // 0x80022644: bltz        $t1, L_80022634
    if (SIGNED(ctx->r9) < 0) {
        // 0x80022648: nop
    
            goto L_80022634;
    }
    // 0x80022648: nop

L_8002264C:
    // 0x8002264C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80022650: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80022654: sb          $t1, 0x3A($t2)
    MEM_B(0X3A, ctx->r10) = ctx->r9;
    // 0x80022658: nop

    // 0x8002265C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80022660: jal         0x80029D54
    // 0x80022664: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_80029D54(rdram, ctx);
        goto after_9;
    // 0x80022664: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_9:
    // 0x80022668: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8002266C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80022670: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80022674: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80022678: jal         0x80029F5C
    // 0x8002267C: lw          $a1, 0x1C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X1C);
    func_80029F5C(rdram, ctx);
        goto after_10;
    // 0x8002267C: lw          $a1, 0x1C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X1C);
    after_10:
    // 0x80022680: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80022684: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80022688: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002268C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80022690: jal         0x80026BE0
    // 0x80022694: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80026BE0(rdram, ctx);
        goto after_11;
    // 0x80022694: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_11:
    // 0x80022698: addiu       $t4, $zero, 0x16
    ctx->r12 = ADD32(0, 0X16);
    // 0x8002269C: sh          $t4, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r12;
    // 0x800226A0: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800226A4: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800226A8: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800226AC: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x800226B0: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800226B4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800226B8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800226BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800226C0: jal         0x80026500
    // 0x800226C4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_12;
    // 0x800226C4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_12:
    // 0x800226C8: b           L_80022CB0
    // 0x800226CC: nop

        goto L_80022CB0;
    // 0x800226CC: nop

L_800226D0:
    // 0x800226D0: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800226D4: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x800226D8: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x800226DC: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800226E0: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x800226E4: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x800226E8: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x800226EC: lbu         $t2, 0x44($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X44);
    // 0x800226F0: sb          $t2, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r10;
    // 0x800226F4: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x800226F8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800226FC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80022700: lw          $t9, 0x74($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X74);
    // 0x80022704: jalr        $t9
    // 0x80022708: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x80022708: nop

    after_13:
    // 0x8002270C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80022710: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80022714: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80022718: swc1        $f8, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f8.u32l;
    // 0x8002271C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80022720: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80022724: lbu         $t8, 0x4F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4F);
    // 0x80022728: lwc1        $f16, 0x2C($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X2C);
    // 0x8002272C: lwc1        $f18, 0x30($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X30);
    // 0x80022730: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x80022734: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x80022738: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8002273C: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80022740: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80022744: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80022748: lwc1        $f10, 0x14($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X14);
    // 0x8002274C: addiu       $a0, $t5, 0x4
    ctx->r4 = ADD32(ctx->r13, 0X4);
    // 0x80022750: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80022754: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80022758: jal         0x80026E90
    // 0x8002275C: nop

    func_80026E90(rdram, ctx);
        goto after_14;
    // 0x8002275C: nop

    after_14:
    // 0x80022760: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80022764: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x80022768: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x8002276C: sll         $t4, $t9, 3
    ctx->r12 = S32(ctx->r25 << 3);
    // 0x80022770: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x80022774: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80022778: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8002277C: lbu         $t8, 0x11($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X11);
    // 0x80022780: beq         $t8, $zero, L_80022818
    if (ctx->r24 == 0) {
        // 0x80022784: nop
    
            goto L_80022818;
    }
    // 0x80022784: nop

    // 0x80022788: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8002278C: lbu         $t1, 0x4F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4F);
    // 0x80022790: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80022794: lw          $t0, 0x60($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X60);
    // 0x80022798: sll         $t5, $t1, 3
    ctx->r13 = S32(ctx->r9 << 3);
    // 0x8002279C: lw          $t6, 0x20($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X20);
    // 0x800227A0: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x800227A4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800227A8: lbu         $t4, 0x36($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X36);
    // 0x800227AC: lbu         $t8, 0x14($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X14);
    // 0x800227B0: addu        $t2, $t0, $t5
    ctx->r10 = ADD32(ctx->r8, ctx->r13);
    // 0x800227B4: lbu         $t9, 0x12($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X12);
    // 0x800227B8: subu        $t7, $t4, $t8
    ctx->r15 = SUB32(ctx->r12, ctx->r24);
    // 0x800227BC: addu        $a0, $t9, $t7
    ctx->r4 = ADD32(ctx->r25, ctx->r15);
    // 0x800227C0: jal         0x80028B74
    // 0x800227C4: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    func_80028B74(rdram, ctx);
        goto after_15;
    // 0x800227C4: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    after_15:
    // 0x800227C8: lui         $at, 0x43DC
    ctx->r1 = S32(0X43DC << 16);
    // 0x800227CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800227D0: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800227D4: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x800227D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800227DC: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800227E0: lw          $t5, 0x60($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X60);
    // 0x800227E4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800227E8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800227EC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800227F0: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x800227F4: lwc1        $f8, 0x14($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X14);
    // 0x800227F8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800227FC: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80022800: lwc1        $f4, 0x30($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X30);
    // 0x80022804: addiu       $a0, $t1, 0x4
    ctx->r4 = ADD32(ctx->r9, 0X4);
    // 0x80022808: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8002280C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80022810: jal         0x8002A7E0
    // 0x80022814: nop

    func_8002A7E0(rdram, ctx);
        goto after_16;
    // 0x80022814: nop

    after_16:
L_80022818:
    // 0x80022818: addiu       $t4, $zero, 0x17
    ctx->r12 = ADD32(0, 0X17);
    // 0x8002281C: sh          $t4, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r12;
    // 0x80022820: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80022824: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80022828: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8002282C: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x80022830: lbu         $t7, 0x4F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4F);
    // 0x80022834: sb          $t7, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r15;
    // 0x80022838: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8002283C: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80022840: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80022844: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80022848: jal         0x80026500
    // 0x8002284C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_17;
    // 0x8002284C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_17:
    // 0x80022850: b           L_80022CB0
    // 0x80022854: nop

        goto L_80022CB0;
    // 0x80022854: nop

L_80022858:
    // 0x80022858: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8002285C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80022860: jal         0x80023008
    // 0x80022864: addiu       $a1, $t0, 0x38
    ctx->r5 = ADD32(ctx->r8, 0X38);
    func_80023008(rdram, ctx);
        goto after_18;
    // 0x80022864: addiu       $a1, $t0, 0x38
    ctx->r5 = ADD32(ctx->r8, 0X38);
    after_18:
    // 0x80022868: b           L_80022CB0
    // 0x8002286C: nop

        goto L_80022CB0;
    // 0x8002286C: nop

L_80022870:
    // 0x80022870: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80022874: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80022878: jal         0x80024A5C
    // 0x8002287C: addiu       $a1, $t2, 0x38
    ctx->r5 = ADD32(ctx->r10, 0X38);
    func_80024A5C(rdram, ctx);
        goto after_19;
    // 0x8002287C: addiu       $a1, $t2, 0x38
    ctx->r5 = ADD32(ctx->r10, 0X38);
    after_19:
    // 0x80022880: b           L_80022CB0
    // 0x80022884: nop

        goto L_80022CB0;
    // 0x80022884: nop

L_80022888:
    // 0x80022888: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8002288C: lh          $t3, 0x3C($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X3C);
    // 0x80022890: sh          $t3, 0x34($t5)
    MEM_H(0X34, ctx->r13) = ctx->r11;
    // 0x80022894: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80022898: lw          $t1, 0x64($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X64);
    // 0x8002289C: beq         $t1, $zero, L_800228F0
    if (ctx->r9 == 0) {
        // 0x800228A0: sw          $t1, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r9;
            goto L_800228F0;
    }
    // 0x800228A0: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
L_800228A4:
    // 0x800228A4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800228A8: jal         0x80029D54
    // 0x800228AC: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_80029D54(rdram, ctx);
        goto after_20;
    // 0x800228AC: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_20:
    // 0x800228B0: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800228B4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800228B8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800228BC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800228C0: jal         0x80029F5C
    // 0x800228C4: lw          $a1, 0x1C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X1C);
    func_80029F5C(rdram, ctx);
        goto after_21;
    // 0x800228C4: lw          $a1, 0x1C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X1C);
    after_21:
    // 0x800228C8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800228CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800228D0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800228D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800228D8: jal         0x80026BE0
    // 0x800228DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80026BE0(rdram, ctx);
        goto after_22;
    // 0x800228DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_22:
    // 0x800228E0: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800228E4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800228E8: bne         $t9, $zero, L_800228A4
    if (ctx->r25 != 0) {
        // 0x800228EC: sw          $t9, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r25;
            goto L_800228A4;
    }
    // 0x800228EC: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_800228F0:
    // 0x800228F0: b           L_80022CB0
    // 0x800228F4: nop

        goto L_80022CB0;
    // 0x800228F4: nop

L_800228F8:
    // 0x800228F8: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800228FC: lwc1        $f16, 0x3C($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x80022900: swc1        $f16, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->f16.u32l;
    // 0x80022904: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80022908: lwc1        $f8, 0x40($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X40);
    // 0x8002290C: swc1        $f8, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->f8.u32l;
    // 0x80022910: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80022914: lw          $t3, 0x64($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X64);
    // 0x80022918: beq         $t3, $zero, L_8002296C
    if (ctx->r11 == 0) {
        // 0x8002291C: sw          $t3, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r11;
            goto L_8002296C;
    }
    // 0x8002291C: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_80022920:
    // 0x80022920: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80022924: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80022928: lbu         $t6, 0x38($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X38);
    // 0x8002292C: beq         $t6, $at, L_80022954
    if (ctx->r14 == ctx->r1) {
        // 0x80022930: nop
    
            goto L_80022954;
    }
    // 0x80022930: nop

    // 0x80022934: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80022938: jal         0x80029E64
    // 0x8002293C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_80029E64(rdram, ctx);
        goto after_23;
    // 0x8002293C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_23:
    // 0x80022940: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80022944: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80022948: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002294C: jal         0x80026F40
    // 0x80022950: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80026F40(rdram, ctx);
        goto after_24;
    // 0x80022950: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_24:
L_80022954:
    // 0x80022954: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80022958: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8002295C: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80022960: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80022964: bne         $t8, $zero, L_80022920
    if (ctx->r24 != 0) {
        // 0x80022968: nop
    
            goto L_80022920;
    }
    // 0x80022968: nop

L_8002296C:
    // 0x8002296C: b           L_80022CB0
    // 0x80022970: nop

        goto L_80022CB0;
    // 0x80022970: nop

L_80022974:
    // 0x80022974: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80022978: lbu         $t7, 0x3D($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X3D);
    // 0x8002297C: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80022980: beq         $at, $zero, L_800229D0
    if (ctx->r1 == 0) {
        // 0x80022984: nop
    
            goto L_800229D0;
    }
    // 0x80022984: nop

    // 0x80022988: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8002298C: jal         0x8002A940
    // 0x80022990: lbu         $a0, 0x3C($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X3C);
    func_8002A940(rdram, ctx);
        goto after_25;
    // 0x80022990: lbu         $a0, 0x3C($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X3C);
    after_25:
    // 0x80022994: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80022998: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8002299C: beq         $t2, $zero, L_800229C8
    if (ctx->r10 == 0) {
        // 0x800229A0: nop
    
            goto L_800229C8;
    }
    // 0x800229A0: nop

    // 0x800229A4: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x800229A8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800229AC: lbu         $t5, 0x3E($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X3E);
    // 0x800229B0: lbu         $t1, 0x3D($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X3D);
    // 0x800229B4: addiu       $a2, $t3, 0x40
    ctx->r6 = ADD32(ctx->r11, 0X40);
    // 0x800229B8: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800229BC: andi        $t4, $t1, 0x7
    ctx->r12 = ctx->r9 & 0X7;
    // 0x800229C0: jal         0x8002AA30
    // 0x800229C4: or          $a1, $t6, $t4
    ctx->r5 = ctx->r14 | ctx->r12;
    func_8002AA30(rdram, ctx);
        goto after_26;
    // 0x800229C4: or          $a1, $t6, $t4
    ctx->r5 = ctx->r14 | ctx->r12;
    after_26:
L_800229C8:
    // 0x800229C8: b           L_80022A00
    // 0x800229CC: nop

        goto L_80022A00;
    // 0x800229CC: nop

L_800229D0:
    // 0x800229D0: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x800229D4: jal         0x8002A9B8
    // 0x800229D8: lbu         $a0, 0x3C($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X3C);
    func_8002A9B8(rdram, ctx);
        goto after_27;
    // 0x800229D8: lbu         $a0, 0x3C($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X3C);
    after_27:
    // 0x800229DC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800229E0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800229E4: beq         $t9, $zero, L_80022A00
    if (ctx->r25 == 0) {
        // 0x800229E8: nop
    
            goto L_80022A00;
    }
    // 0x800229E8: nop

    // 0x800229EC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800229F0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800229F4: lbu         $a1, 0x3D($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X3D);
    // 0x800229F8: jal         0x8002AA74
    // 0x800229FC: addiu       $a2, $t7, 0x40
    ctx->r6 = ADD32(ctx->r15, 0X40);
    func_8002AA74(rdram, ctx);
        goto after_28;
    // 0x800229FC: addiu       $a2, $t7, 0x40
    ctx->r6 = ADD32(ctx->r15, 0X40);
    after_28:
L_80022A00:
    // 0x80022A00: b           L_80022CB0
    // 0x80022A04: nop

        goto L_80022CB0;
    // 0x80022A04: nop

L_80022A08:
    // 0x80022A08: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80022A0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80022A10: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x80022A14: beq         $t2, $at, L_80022A30
    if (ctx->r10 == ctx->r1) {
        // 0x80022A18: nop
    
            goto L_80022A30;
    }
    // 0x80022A18: nop

    // 0x80022A1C: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80022A20: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80022A24: sw          $t5, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r13;
    // 0x80022A28: jal         0x80024DD8
    // 0x80022A2C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    func_80024DD8(rdram, ctx);
        goto after_29;
    // 0x80022A2C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_29:
L_80022A30:
    // 0x80022A30: b           L_80022CB0
    // 0x80022A34: nop

        goto L_80022CB0;
    // 0x80022A34: nop

L_80022A38:
    // 0x80022A38: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80022A3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80022A40: lw          $t4, 0x2C($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X2C);
    // 0x80022A44: bne         $t4, $at, L_80022AB8
    if (ctx->r12 != ctx->r1) {
        // 0x80022A48: nop
    
            goto L_80022AB8;
    }
    // 0x80022A48: nop

    // 0x80022A4C: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80022A50: lw          $t8, 0x64($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X64);
    // 0x80022A54: beq         $t8, $zero, L_80022AB0
    if (ctx->r24 == 0) {
        // 0x80022A58: sw          $t8, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r24;
            goto L_80022AB0;
    }
    // 0x80022A58: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
L_80022A5C:
    // 0x80022A5C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80022A60: jal         0x80026FF0
    // 0x80022A64: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80026FF0(rdram, ctx);
        goto after_30;
    // 0x80022A64: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_30:
    // 0x80022A68: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80022A6C: jal         0x80027090
    // 0x80022A70: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80027090(rdram, ctx);
        goto after_31;
    // 0x80022A70: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_31:
    // 0x80022A74: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80022A78: lbu         $t7, 0x3B($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X3B);
    // 0x80022A7C: beq         $t7, $zero, L_80022A90
    if (ctx->r15 == 0) {
        // 0x80022A80: nop
    
            goto L_80022A90;
    }
    // 0x80022A80: nop

    // 0x80022A84: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80022A88: jal         0x8002A6A4
    // 0x80022A8C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_8002A6A4(rdram, ctx);
        goto after_32;
    // 0x80022A8C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_32:
L_80022A90:
    // 0x80022A90: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80022A94: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80022A98: jal         0x80029670
    // 0x80022A9C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80029670(rdram, ctx);
        goto after_33;
    // 0x80022A9C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_33:
    // 0x80022AA0: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80022AA4: lw          $t2, 0x64($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X64);
    // 0x80022AA8: bne         $t2, $zero, L_80022A5C
    if (ctx->r10 != 0) {
        // 0x80022AAC: sw          $t2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r10;
            goto L_80022A5C;
    }
    // 0x80022AAC: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_80022AB0:
    // 0x80022AB0: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80022AB4: sw          $zero, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = 0;
L_80022AB8:
    // 0x80022AB8: b           L_80022CB0
    // 0x80022ABC: nop

        goto L_80022CB0;
    // 0x80022ABC: nop

L_80022AC0:
    // 0x80022AC0: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80022AC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80022AC8: lw          $t6, 0x2C($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X2C);
    // 0x80022ACC: bne         $t6, $at, L_80022C30
    if (ctx->r14 != ctx->r1) {
        // 0x80022AD0: nop
    
            goto L_80022C30;
    }
    // 0x80022AD0: nop

    // 0x80022AD4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80022AD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022ADC: jal         0x800266B0
    // 0x80022AE0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_800266B0(rdram, ctx);
        goto after_34;
    // 0x80022AE0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_34:
    // 0x80022AE4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80022AE8: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80022AEC: jal         0x800266B0
    // 0x80022AF0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_800266B0(rdram, ctx);
        goto after_35;
    // 0x80022AF0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_35:
    // 0x80022AF4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80022AF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80022AFC: jal         0x800266B0
    // 0x80022B00: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_800266B0(rdram, ctx);
        goto after_36;
    // 0x80022B00: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_36:
    // 0x80022B04: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80022B08: lw          $t3, 0x64($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X64);
    // 0x80022B0C: beq         $t3, $zero, L_80022B54
    if (ctx->r11 == 0) {
        // 0x80022B10: sw          $t3, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r11;
            goto L_80022B54;
    }
    // 0x80022B10: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_80022B14:
    // 0x80022B14: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80022B18: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80022B1C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    // 0x80022B20: jal         0x800298E4
    // 0x80022B24: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800298E4(rdram, ctx);
        goto after_37;
    // 0x80022B24: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_37:
    // 0x80022B28: beq         $v0, $zero, L_80022B44
    if (ctx->r2 == 0) {
        // 0x80022B2C: nop
    
            goto L_80022B44;
    }
    // 0x80022B2C: nop

    // 0x80022B30: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80022B34: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80022B38: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    // 0x80022B3C: jal         0x8002976C
    // 0x80022B40: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_8002976C(rdram, ctx);
        goto after_38;
    // 0x80022B40: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_38:
L_80022B44:
    // 0x80022B44: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80022B48: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80022B4C: bne         $t9, $zero, L_80022B14
    if (ctx->r25 != 0) {
        // 0x80022B50: sw          $t9, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r25;
            goto L_80022B14;
    }
    // 0x80022B50: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_80022B54:
    // 0x80022B54: sb          $zero, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = 0;
L_80022B58:
    // 0x80022B58: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80022B5C: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x80022B60: lw          $t0, 0x60($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X60);
    // 0x80022B64: sll         $t5, $t2, 3
    ctx->r13 = S32(ctx->r10 << 3);
    // 0x80022B68: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x80022B6C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80022B70: addu        $t1, $t0, $t5
    ctx->r9 = ADD32(ctx->r8, ctx->r13);
    // 0x80022B74: lbu         $t6, 0xA($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XA);
    // 0x80022B78: sb          $t6, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r14;
    // 0x80022B7C: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80022B80: lbu         $t8, 0x4F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4F);
    // 0x80022B84: lw          $t3, 0x60($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X60);
    // 0x80022B88: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80022B8C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80022B90: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80022B94: addu        $t7, $t3, $t9
    ctx->r15 = ADD32(ctx->r11, ctx->r25);
    // 0x80022B98: lbu         $t2, 0x9($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X9);
    // 0x80022B9C: bne         $t2, $zero, L_80022BCC
    if (ctx->r10 != 0) {
        // 0x80022BA0: nop
    
            goto L_80022BCC;
    }
    // 0x80022BA0: nop

    // 0x80022BA4: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80022BA8: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x80022BAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80022BB0: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x80022BB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80022BB8: sllv        $t4, $t1, $t6
    ctx->r12 = S32(ctx->r9 << (ctx->r14 & 31));
    // 0x80022BBC: xor         $t8, $t4, $at
    ctx->r24 = ctx->r12 ^ ctx->r1;
    // 0x80022BC0: and         $t3, $t5, $t8
    ctx->r11 = ctx->r13 & ctx->r24;
    // 0x80022BC4: b           L_80022BE8
    // 0x80022BC8: sw          $t3, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r11;
        goto L_80022BE8;
    // 0x80022BC8: sw          $t3, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r11;
L_80022BCC:
    // 0x80022BCC: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80022BD0: lbu         $t2, 0x4F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4F);
    // 0x80022BD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80022BD8: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x80022BDC: sllv        $t6, $t1, $t2
    ctx->r14 = S32(ctx->r9 << (ctx->r10 & 31));
    // 0x80022BE0: or          $t4, $t7, $t6
    ctx->r12 = ctx->r15 | ctx->r14;
    // 0x80022BE4: sw          $t4, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r12;
L_80022BE8:
    // 0x80022BE8: lbu         $t5, 0x4F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4F);
    // 0x80022BEC: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80022BF0: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x80022BF4: slti        $at, $t3, 0x20
    ctx->r1 = SIGNED(ctx->r11) < 0X20 ? 1 : 0;
    // 0x80022BF8: bne         $at, $zero, L_80022B58
    if (ctx->r1 != 0) {
        // 0x80022BFC: sb          $t8, 0x4F($sp)
        MEM_B(0X4F, ctx->r29) = ctx->r24;
            goto L_80022B58;
    }
    // 0x80022BFC: sb          $t8, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r24;
    // 0x80022C00: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80022C04: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80022C08: sw          $t0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r8;
    // 0x80022C0C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80022C10: sh          $t2, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r10;
    // 0x80022C14: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80022C18: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80022C1C: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80022C20: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80022C24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80022C28: jal         0x80026500
    // 0x80022C2C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_39;
    // 0x80022C2C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_39:
L_80022C30:
    // 0x80022C30: b           L_80022CB0
    // 0x80022C34: nop

        goto L_80022CB0;
    // 0x80022C34: nop

L_80022C38:
    // 0x80022C38: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80022C3C: lbu         $t6, 0x3C($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X3C);
    // 0x80022C40: sb          $t6, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r14;
    // 0x80022C44: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80022C48: lbu         $t8, 0x4F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4F);
    // 0x80022C4C: lw          $t5, 0x60($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X60);
    // 0x80022C50: sll         $t3, $t8, 3
    ctx->r11 = S32(ctx->r24 << 3);
    // 0x80022C54: lbu         $t9, 0x3D($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X3D);
    // 0x80022C58: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80022C5C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80022C60: addu        $t0, $t5, $t3
    ctx->r8 = ADD32(ctx->r13, ctx->r11);
    // 0x80022C64: sb          $t9, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r25;
    // 0x80022C68: b           L_80022CB0
    // 0x80022C6C: nop

        goto L_80022CB0;
    // 0x80022C6C: nop

L_80022C70:
    // 0x80022C70: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80022C74: lw          $t2, 0x3C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X3C);
    // 0x80022C78: sw          $t2, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r10;
    // 0x80022C7C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80022C80: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80022C84: sw          $t7, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r15;
    // 0x80022C88: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80022C8C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80022C90: jal         0x8002A024
    // 0x80022C94: lw          $a1, 0x20($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X20);
    func_8002A024(rdram, ctx);
        goto after_40;
    // 0x80022C94: lw          $a1, 0x20($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X20);
    after_40:
    // 0x80022C98: b           L_80022CB0
    // 0x80022C9C: nop

        goto L_80022CB0;
    // 0x80022C9C: nop

L_80022CA0:
    // 0x80022CA0: b           L_80022CB0
    // 0x80022CA4: nop

        goto L_80022CB0;
    // 0x80022CA4: nop

L_80022CA8:
    // 0x80022CA8: b           L_80022CB0
    // 0x80022CAC: nop

        goto L_80022CB0;
    // 0x80022CAC: nop

L_80022CB0:
    // 0x80022CB0: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80022CB4: addiu       $a0, $t8, 0x48
    ctx->r4 = ADD32(ctx->r24, 0X48);
    // 0x80022CB8: jal         0x8002645C
    // 0x80022CBC: addiu       $a1, $t8, 0x38
    ctx->r5 = ADD32(ctx->r24, 0X38);
    func_8002645C(rdram, ctx);
        goto after_41;
    // 0x80022CBC: addiu       $a1, $t8, 0x38
    ctx->r5 = ADD32(ctx->r24, 0X38);
    after_41:
    // 0x80022CC0: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80022CC4: sw          $v0, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r2;
    // 0x80022CC8: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80022CCC: lw          $t9, 0x28($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X28);
    // 0x80022CD0: beq         $t9, $zero, L_80022440
    if (ctx->r25 == 0) {
        // 0x80022CD4: nop
    
            goto L_80022440;
    }
    // 0x80022CD4: nop

    // 0x80022CD8: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80022CDC: lw          $t2, 0x1C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1C);
    // 0x80022CE0: lw          $t1, 0x28($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X28);
    // 0x80022CE4: addu        $t7, $t2, $t1
    ctx->r15 = ADD32(ctx->r10, ctx->r9);
    // 0x80022CE8: sw          $t7, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r15;
    // 0x80022CEC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80022CF0: b           L_80022D00
    // 0x80022CF4: lw          $v0, 0x28($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X28);
        goto L_80022D00;
    // 0x80022CF4: lw          $v0, 0x28($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X28);
    // 0x80022CF8: b           L_80022D00
    // 0x80022CFC: nop

        goto L_80022D00;
    // 0x80022CFC: nop

L_80022D00:
    // 0x80022D00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80022D04: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80022D08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80022D0C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80022D10: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80022D14: jr          $ra
    // 0x80022D18: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80022D18: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80802534_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080253C: jal         0x80090248
    // 0x80802540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090248(rdram, ctx);
        goto after_0;
    // 0x80802540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802544: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80802548: beq         $t6, $zero, L_80802564
    if (ctx->r14 == 0) {
        // 0x8080254C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80802564;
    }
    // 0x8080254C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80802550: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80802554: jal         0x8008FA2C
    // 0x80802558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA2C(rdram, ctx);
        goto after_1;
    // 0x80802558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080255C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80802560: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80802564:
    // 0x80802564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080256C: jr          $ra
    // 0x80802570: nop

    return;
    // 0x80802570: nop

;}
RECOMP_FUNC void func_800D2970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2970: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D2974: addiu       $v0, $v0, -0x4CE0
    ctx->r2 = ADD32(ctx->r2, -0X4CE0);
    // 0x800D2978: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
    // 0x800D297C: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x800D2980: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800D2984: jr          $ra
    // 0x800D2988: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x800D2988: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80115324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80115328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011532C: jal         0x8001BAFC
    // 0x80115330: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    defrag(rdram, ctx);
        goto after_0;
    // 0x80115330: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    after_0:
    // 0x80115334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80115338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011533C: jr          $ra
    // 0x80115340: nop

    return;
    // 0x80115340: nop

    // 0x80115344: nop

    // 0x80115348: nop

    // 0x8011534C: nop

;}
RECOMP_FUNC void func_800CA060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA060: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CA064: lw          $a0, -0x54A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54A0);
    // 0x800CA068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA06C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA070: beql        $a0, $zero, L_800CA08C
    if (ctx->r4 == 0) {
        // 0x800CA074: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CA08C;
    }
    goto skip_0;
    // 0x800CA074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CA078: jal         0x800B2D28
    // 0x800CA07C: nop

    vector_free(rdram, ctx);
        goto after_0;
    // 0x800CA07C: nop

    after_0:
    // 0x800CA080: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CA084: sw          $zero, -0x54A0($at)
    MEM_W(-0X54A0, ctx->r1) = 0;
    // 0x800CA088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CA08C:
    // 0x800CA08C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA090: jr          $ra
    // 0x800CA094: nop

    return;
    // 0x800CA094: nop

;}
RECOMP_FUNC void func_80800024_chweldarbossfusebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800030: jal         0x800DA298
    // 0x80800034: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800034: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    after_0:
    // 0x80800038: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080003C: jal         0x800BF744
    // 0x80800040: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800BF744(rdram, ctx);
        goto after_1;
    // 0x80800040: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800048: lui         $a3, 0xC509
    ctx->r7 = S32(0XC509 << 16);
    // 0x8080004C: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800050: lui         $a1, 0xC4E1
    ctx->r5 = S32(0XC4E1 << 16);
    // 0x80800054: lui         $a2, 0x4496
    ctx->r6 = S32(0X4496 << 16);
    // 0x80800058: jal         0x800EFA4C
    // 0x8080005C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x8080005C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x80800060: jal         0x80103014
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80103014(rdram, ctx);
        goto after_3;
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800068: jal         0x80089D00
    // 0x8080006C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x8080006C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800070: jal         0x800DA298
    // 0x80800074: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800074: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    after_5:
    // 0x80800078: beql        $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x8080007C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080008C;
    }
    goto skip_0;
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800080: jal         0x800FFAB0
    // 0x80800084: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800084: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080008C:
    // 0x8080008C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void func_80800570_chfantasylakebits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800570: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800574: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080057C: beq         $a1, $at, L_808005B4
    if (ctx->r5 == ctx->r1) {
        // 0x80800580: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808005B4;
    }
    // 0x80800580: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800584: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800588: beq         $a1, $at, L_808005F0
    if (ctx->r5 == ctx->r1) {
        // 0x8080058C: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_808005F0;
    }
    // 0x8080058C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800590: beq         $a1, $at, L_80800644
    if (ctx->r5 == ctx->r1) {
        // 0x80800594: addiu       $at, $zero, 0x36
        ctx->r1 = ADD32(0, 0X36);
            goto L_80800644;
    }
    // 0x80800594: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x80800598: beq         $a1, $at, L_80800634
    if (ctx->r5 == ctx->r1) {
        // 0x8080059C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800634;
    }
    // 0x8080059C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808005A0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808005A4: beq         $a1, $at, L_808006A0
    if (ctx->r5 == ctx->r1) {
        // 0x808005A8: addiu       $a0, $zero, 0x327
        ctx->r4 = ADD32(0, 0X327);
            goto L_808006A0;
    }
    // 0x808005A8: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    // 0x808005AC: b           L_808006D8
    // 0x808005B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006D8;
    // 0x808005B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005B4:
    // 0x808005B4: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x808005B8: bne         $a2, $at, L_808005E8
    if (ctx->r6 != ctx->r1) {
        // 0x808005BC: nop
    
            goto L_808005E8;
    }
    // 0x808005BC: nop

    // 0x808005C0: jal         0x80085710
    // 0x808005C4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808005C4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x808005C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808005CC: jal         0x80800344
    // 0x808005D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800344_chfantasylakebits(rdram, ctx);
        goto after_1;
    // 0x808005D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x808005D4: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    // 0x808005D8: jal         0x800887D8
    // 0x808005DC: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808005DC: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_2:
    // 0x808005E0: b           L_808006D8
    // 0x808005E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808006D8;
    // 0x808005E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808005E8:
    // 0x808005E8: b           L_808006D8
    // 0x808005EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808006D8;
    // 0x808005EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808005F0:
    // 0x808005F0: lhu         $v0, 0x72($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X72);
    // 0x808005F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808005FC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800600: bne         $t6, $at, L_80800618
    if (ctx->r14 != ctx->r1) {
        // 0x80800604: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800618;
    }
    // 0x80800604: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800608: jal         0x80800344
    // 0x8080060C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800344_chfantasylakebits(rdram, ctx);
        goto after_3;
    // 0x8080060C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800610: b           L_808006D8
    // 0x80800614: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808006D8;
    // 0x80800614: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800618:
    // 0x80800618: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080061C: bne         $v0, $at, L_8080062C
    if (ctx->r2 != ctx->r1) {
        // 0x80800620: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080062C;
    }
    // 0x80800620: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800624: jal         0x80800344
    // 0x80800628: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800344_chfantasylakebits(rdram, ctx);
        goto after_4;
    // 0x80800628: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
L_8080062C:
    // 0x8080062C: b           L_808006D8
    // 0x80800630: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808006D8;
    // 0x80800630: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800634:
    // 0x80800634: jal         0x80800344
    // 0x80800638: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800344_chfantasylakebits(rdram, ctx);
        goto after_5;
    // 0x80800638: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8080063C: b           L_808006D8
    // 0x80800640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006D8;
    // 0x80800640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800644:
    // 0x80800644: lhu         $t7, 0x64($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X64);
    // 0x80800648: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080064C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800650: beq         $t8, $zero, L_80800698
    if (ctx->r24 == 0) {
        // 0x80800654: nop
    
            goto L_80800698;
    }
    // 0x80800654: nop

    // 0x80800658: jal         0x801015D0
    // 0x8080065C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_801015D0(rdram, ctx);
        goto after_6;
    // 0x8080065C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_6:
    // 0x80800660: jal         0x800E3980
    // 0x80800664: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800E3980(rdram, ctx);
        goto after_7;
    // 0x80800664: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_7:
    // 0x80800668: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080066C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800670: jal         0x800F1DF4
    // 0x80800674: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_8;
    // 0x80800674: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x80800678: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080067C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800680: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800684: lwc1        $f12, 0x54($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X54);
    // 0x80800688: swc1        $f0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->f0.u32l;
    // 0x8080068C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80800690: jal         0x800DF500
    // 0x80800694: nop

    func_800DF500(rdram, ctx);
        goto after_9;
    // 0x80800694: nop

    after_9:
L_80800698:
    // 0x80800698: b           L_808006D8
    // 0x8080069C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006D8;
    // 0x8080069C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006A0:
    // 0x808006A0: jal         0x800DA298
    // 0x808006A4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x808006A4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_10:
    // 0x808006A8: beq         $v0, $zero, L_808006C4
    if (ctx->r2 == 0) {
        // 0x808006AC: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_808006C4;
    }
    // 0x808006AC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808006B0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808006B4: jal         0x80800344
    // 0x808006B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800344_chfantasylakebits(rdram, ctx);
        goto after_11;
    // 0x808006B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x808006BC: b           L_808006D8
    // 0x808006C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006D8;
    // 0x808006C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006C4:
    // 0x808006C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808006C8: jal         0x80800344
    // 0x808006CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800344_chfantasylakebits(rdram, ctx);
        goto after_12;
    // 0x808006CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808006D0: b           L_808006D8
    // 0x808006D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006D8;
    // 0x808006D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006D8:
    // 0x808006D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006E0: jr          $ra
    // 0x808006E4: nop

    return;
    // 0x808006E4: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080051C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800524: sb          $a1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r5;
    // 0x80800528: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8080052C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800530: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800534: beq         $v0, $at, L_80800544
    if (ctx->r2 == ctx->r1) {
        // 0x80800538: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800544;
    }
    // 0x80800538: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080053C: bnel        $v0, $at, L_80800558
    if (ctx->r2 != ctx->r1) {
        // 0x80800540: lw          $v0, 0x18($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X18);
            goto L_80800558;
    }
    goto skip_0;
    // 0x80800540: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    skip_0:
L_80800544:
    // 0x80800544: jal         0x80800230
    // 0x80800548: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    gsmaker_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800548: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    after_0:
    // 0x8080054C: b           L_808005B4
    // 0x80800550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005B4;
    // 0x80800550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800554: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
L_80800558:
    // 0x80800558: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8080055C: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    // 0x80800560: bne         $v1, $v0, L_8080059C
    if (ctx->r3 != ctx->r2) {
        // 0x80800564: nop
    
            goto L_8080059C;
    }
    // 0x80800564: nop

    // 0x80800568: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080056C: jal         0x80800230
    // 0x80800570: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    gsmaker_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800570: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800574: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800578: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x8080057C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800584: bne         $a2, $v1, L_80800594
    if (ctx->r6 != ctx->r3) {
        // 0x80800588: nop
    
            goto L_80800594;
    }
    // 0x80800588: nop

    // 0x8080058C: b           L_808005B4
    // 0x80800590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005B4;
    // 0x80800590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800594:
    // 0x80800594: b           L_808005B4
    // 0x80800598: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
        goto L_808005B4;
    // 0x80800598: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
L_8080059C:
    // 0x8080059C: bnel        $a2, $v0, L_808005B4
    if (ctx->r6 != ctx->r2) {
        // 0x808005A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808005B4;
    }
    goto skip_1;
    // 0x808005A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x808005A4: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
    // 0x808005A8: b           L_808005B4
    // 0x808005AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005B4;
    // 0x808005AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005B4:
    // 0x808005B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005BC: jr          $ra
    // 0x808005C0: nop

    return;
    // 0x808005C0: nop

;}
RECOMP_FUNC void _ncbafixpos_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089330: syscall     774
    recomp_syscall_handler(rdram, ctx, 0x80089330);
    return;
    // 0x80089334: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_808007A8_bskazstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007B0: jal         0x80082FE8
    // 0x808007B4: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808007B4: nop

    after_0:
    // 0x808007B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007C0: jr          $ra
    // 0x808007C4: nop

    return;
    // 0x808007C4: nop

;}
RECOMP_FUNC void chexploder_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801634: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801638: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080163C: beq         $a0, $zero, L_80801650
    if (ctx->r4 == 0) {
        // 0x80801640: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_80801650;
    }
    // 0x80801640: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80801644: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80801648: b           L_80801654
    // 0x8080164C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_80801654;
    // 0x8080164C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_80801650:
    // 0x80801650: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80801654:
    // 0x80801654: sh          $a1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r5;
    // 0x80801658: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8080165C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80801660: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801664: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x80801668: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8080166C: nop

    // 0x80801670: sh          $t8, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r24;
    // 0x80801674: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80801678: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080167C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80801680: nop

    // 0x80801684: sh          $t0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r8;
    // 0x80801688: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8080168C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80801690: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80801694: beq         $t4, $zero, L_808016A4
    if (ctx->r12 == 0) {
        // 0x80801698: sh          $t2, 0x32($sp)
        MEM_H(0X32, ctx->r29) = ctx->r10;
            goto L_808016A4;
    }
    // 0x80801698: sh          $t2, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r10;
    // 0x8080169C: jal         0x8010A570
    // 0x808016A0: nop

    func_8010A570(rdram, ctx);
        goto after_0;
    // 0x808016A0: nop

    after_0:
L_808016A4:
    // 0x808016A4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x808016A8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x808016AC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x808016B0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808016B4: addiu       $a0, $a0, 0x6668
    ctx->r4 = ADD32(ctx->r4, 0X6668);
    // 0x808016B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808016BC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808016C0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808016C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808016C8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808016CC: jal         0x80086D58
    // 0x808016D0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808016D0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_1:
    // 0x808016D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808016D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808016DC: jr          $ra
    // 0x808016E0: nop

    return;
    // 0x808016E0: nop

;}
RECOMP_FUNC void func_80800090_chmole_mine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1600, 0XC0) << 16);
    // 0x8080009C: jal         0x800899F0
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1600, 0XC0));
    _sumole_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1600, 0XC0));
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
RECOMP_FUNC void func_80110D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110D88: jal         0x8011396C
    // 0x80110D8C: nop

    func_8011396C(rdram, ctx);
        goto after_0;
    // 0x80110D8C: nop

    after_0:
    // 0x80110D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110D98: jr          $ra
    // 0x80110D9C: nop

    return;
    // 0x80110D9C: nop

;}
RECOMP_FUNC void _bstimeout_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F20: syscall     98
    recomp_syscall_handler(rdram, ctx, 0x80083F20);
    return;
    // 0x80083F24: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _mlwave_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FC0: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FC0);
    return;
    // 0x80088FC4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80804DA0_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804DA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804DA8: jal         0x8080009C
    // 0x80804DAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_0;
    // 0x80804DAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80804DB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804DB4: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80804DB8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80804DBC: nop

    // 0x80804DC0: bc1fl       L_80804DE4
    if (!c1cs) {
        // 0x80804DC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80804DE4;
    }
    goto skip_0;
    // 0x80804DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80804DC8: jal         0x808000F4
    // 0x80804DCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000F4_chstoneballcontrol(rdram, ctx);
        goto after_1;
    // 0x80804DCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80804DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80804DD4: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80804DD8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80804DDC: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x80804DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804DE4:
    // 0x80804DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804DE8: jr          $ra
    // 0x80804DEC: nop

    return;
    // 0x80804DEC: nop

;}
RECOMP_FUNC void func_8008AEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AEB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008AEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008AEBC: jal         0x8001BAFC
    // 0x8008AEC0: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x8008AEC0: nop

    after_0:
    // 0x8008AEC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008AEC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AECC: jr          $ra
    // 0x8008AED0: nop

    return;
    // 0x8008AED0: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802298: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080229C: jal         0x8009BD88
    // 0x808022A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009BD88(rdram, ctx);
        goto after_0;
    // 0x808022A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808022A4: jal         0x8009BC6C
    // 0x808022A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x808022A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808022AC: jal         0x8008E95C
    // 0x808022B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E95C(rdram, ctx);
        goto after_2;
    // 0x808022B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808022B4: jal         0x800951B4
    // 0x808022B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_3;
    // 0x808022B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808022BC: jal         0x8080061C
    // 0x808022C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_4;
    // 0x808022C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808022C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808022C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808022CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808022D0: jr          $ra
    // 0x808022D4: nop

    return;
    // 0x808022D4: nop

;}
RECOMP_FUNC void chstoneballcontrol_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801938: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1608, 0X50D4) << 16);
    // 0x8080193C: jr          $ra
    // 0x80801940: addiu       $v0, $v0, 0x50D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1608, 0X50D4));
    return;
    // 0x80801940: addiu       $v0, $v0, 0x50D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1608, 0X50D4));
;}
RECOMP_FUNC void func_80800084_chlensflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080008C: jal         0x800EA05C
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800094: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2296, 0X8F0) << 16);
    // 0x80800098: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: addiu       $v1, $v1, 0x8F0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2296, 0X8F0));
    // 0x808000A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000A4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_808000A8:
    // 0x808000A8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x808000AC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x808000B0: bne         $a2, $a0, L_808000C8
    if (ctx->r6 != ctx->r4) {
        // 0x808000B4: nop
    
            goto L_808000C8;
    }
    // 0x808000B4: nop

    // 0x808000B8: jal         0x800FFAB0
    // 0x808000BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x808000BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x808000C0: b           L_808000F0
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F0;
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C8:
    // 0x808000C8: bne         $v0, $a0, L_808000D8
    if (ctx->r2 != ctx->r4) {
        // 0x808000CC: nop
    
            goto L_808000D8;
    }
    // 0x808000CC: nop

    // 0x808000D0: b           L_808000E0
    // 0x808000D4: sw          $a1, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r5;
        goto L_808000E0;
    // 0x808000D4: sw          $a1, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r5;
L_808000D8:
    // 0x808000D8: b           L_808000A8
    // 0x808000DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_808000A8;
    // 0x808000DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_808000E0:
    // 0x808000E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2296, 0X690) << 16);
    // 0x808000E4: lwc1        $f4, 0x690($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2296, 0X690));
    // 0x808000E8: swc1        $f4, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f4.u32l;
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F0:
    // 0x808000F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void func_8009032C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009032C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090334: jal         0x800F54E4
    // 0x80090338: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090338: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009033C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090340: jal         0x800F739C
    // 0x80090344: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F739C(rdram, ctx);
        goto after_1;
    // 0x80090344: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80090348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009034C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090350: jr          $ra
    // 0x80090354: nop

    return;
    // 0x80090354: nop

;}
RECOMP_FUNC void func_80103110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103110: beql        $a1, $zero, L_8010312C
    if (ctx->r5 == 0) {
        // 0x80103114: lbu         $t9, 0x7E($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X7E);
            goto L_8010312C;
    }
    goto skip_0;
    // 0x80103114: lbu         $t9, 0x7E($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X7E);
    skip_0:
    // 0x80103118: lbu         $t7, 0x7E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7E);
    // 0x8010311C: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80103120: jr          $ra
    // 0x80103124: sb          $t8, 0x7E($a0)
    MEM_B(0X7E, ctx->r4) = ctx->r24;
    return;
    // 0x80103124: sb          $t8, 0x7E($a0)
    MEM_B(0X7E, ctx->r4) = ctx->r24;
    // 0x80103128: lbu         $t9, 0x7E($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X7E);
L_8010312C:
    // 0x8010312C: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x80103130: sb          $t0, 0x7E($a0)
    MEM_B(0X7E, ctx->r4) = ctx->r8;
    // 0x80103134: jr          $ra
    // 0x80103138: nop

    return;
    // 0x80103138: nop

    // 0x8010313C: nop

;}
RECOMP_FUNC void func_80806068_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080606C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80806070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806074: beq         $a1, $v0, L_8080609C
    if (ctx->r5 == ctx->r2) {
        // 0x80806078: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080609C;
    }
    // 0x80806078: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080607C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80806080: beq         $a1, $at, L_80806124
    if (ctx->r5 == ctx->r1) {
        // 0x80806084: addiu       $a0, $a2, 0x1
        ctx->r4 = ADD32(ctx->r6, 0X1);
            goto L_80806124;
    }
    // 0x80806084: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x80806088: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080608C: beq         $a1, $at, L_80806190
    if (ctx->r5 == ctx->r1) {
        // 0x80806090: nop
    
            goto L_80806190;
    }
    // 0x80806090: nop

    // 0x80806094: b           L_8080619C
    // 0x80806098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080619C;
    // 0x80806098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080609C:
    // 0x8080609C: beq         $a2, $zero, L_808060C4
    if (ctx->r6 == 0) {
        // 0x808060A0: sw          $a2, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->r6;
            goto L_808060C4;
    }
    // 0x808060A0: sw          $a2, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r6;
    // 0x808060A4: beq         $a2, $v0, L_808060DC
    if (ctx->r6 == ctx->r2) {
        // 0x808060A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808060DC;
    }
    // 0x808060A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808060AC: beq         $a2, $at, L_808060F4
    if (ctx->r6 == ctx->r1) {
        // 0x808060B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808060F4;
    }
    // 0x808060B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808060B4: beq         $a2, $at, L_8080610C
    if (ctx->r6 == ctx->r1) {
        // 0x808060B8: nop
    
            goto L_8080610C;
    }
    // 0x808060B8: nop

    // 0x808060BC: b           L_8080619C
    // 0x808060C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080619C;
    // 0x808060C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808060C4:
    // 0x808060C4: jal         0x80088350
    // 0x808060C8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808060C8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x808060CC: jal         0x80088348
    // 0x808060D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808060D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808060D4: b           L_8080619C
    // 0x808060D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080619C;
    // 0x808060D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808060DC:
    // 0x808060DC: jal         0x80088350
    // 0x808060E0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808060E0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_2:
    // 0x808060E4: jal         0x80088348
    // 0x808060E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x808060E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x808060EC: b           L_8080619C
    // 0x808060F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080619C;
    // 0x808060F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808060F4:
    // 0x808060F4: jal         0x80088350
    // 0x808060F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x808060F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x808060FC: jal         0x80088348
    // 0x80806100: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80806100: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x80806104: b           L_8080619C
    // 0x80806108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080619C;
    // 0x80806108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080610C:
    // 0x8080610C: jal         0x80088350
    // 0x80806110: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80806110: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80806114: jal         0x80088348
    // 0x80806118: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80806118: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x8080611C: b           L_8080619C
    // 0x80806120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080619C;
    // 0x80806120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806124:
    // 0x80806124: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80806128: jal         0x80088330
    // 0x8080612C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _gcstatusDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x8080612C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_8:
    // 0x80806130: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80806134: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80806138: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080613C: beq         $a2, $at, L_80806154
    if (ctx->r6 == ctx->r1) {
        // 0x80806140: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80806154;
    }
    // 0x80806140: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80806144: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80806148: beq         $a2, $at, L_80806170
    if (ctx->r6 == ctx->r1) {
        // 0x8080614C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80806170;
    }
    // 0x8080614C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80806150: bne         $a2, $at, L_80806170
    if (ctx->r6 != ctx->r1) {
        // 0x80806154: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80806170;
    }
L_80806154:
    // 0x80806154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80806158: jal         0x80806068
    // 0x8080615C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80806068_chgameselect(rdram, ctx);
        goto after_9;
    // 0x8080615C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_9:
    // 0x80806160: jal         0x80088358
    // 0x80806164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80806164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80806168: b           L_8080619C
    // 0x8080616C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080619C;
    // 0x8080616C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806170:
    // 0x80806170: jal         0x800883A8
    // 0x80806174: nop

    _gcstatusDll_entrypoint_19(rdram, ctx);
        goto after_11;
    // 0x80806174: nop

    after_11:
    // 0x80806178: bnel        $v0, $zero, L_8080619C
    if (ctx->r2 != 0) {
        // 0x8080617C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080619C;
    }
    goto skip_0;
    // 0x8080617C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80806180: jal         0x80088358
    // 0x80806184: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _gcstatusDll_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80806184: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x80806188: b           L_8080619C
    // 0x8080618C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080619C;
    // 0x8080618C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806190:
    // 0x80806190: jal         0x80088358
    // 0x80806194: addiu       $a0, $a2, 0x2
    ctx->r4 = ADD32(ctx->r6, 0X2);
    _gcstatusDll_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x80806194: addiu       $a0, $a2, 0x2
    ctx->r4 = ADD32(ctx->r6, 0X2);
    after_13:
    // 0x80806198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080619C:
    // 0x8080619C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808061A0: jr          $ra
    // 0x808061A4: nop

    return;
    // 0x808061A4: nop

;}
RECOMP_FUNC void gcdialogexec_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801B68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801B6C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801B70: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801B74: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801B78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801B7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B80: lbu         $t6, 0x11C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X11C);
    // 0x80801B84: lbu         $t8, 0x11D($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X11D);
    // 0x80801B88: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80801B8C: andi        $t7, $t6, 0xFF3F
    ctx->r15 = ctx->r14 & 0XFF3F;
    // 0x80801B90: andi        $t9, $t8, 0xFF3F
    ctx->r25 = ctx->r24 & 0XFF3F;
    // 0x80801B94: sb          $t7, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r15;
    // 0x80801B98: jal         0x800C0638
    // 0x80801B9C: sb          $t9, 0x11D($a0)
    MEM_B(0X11D, ctx->r4) = ctx->r25;
    func_800C0638(rdram, ctx);
        goto after_0;
    // 0x80801B9C: sb          $t9, 0x11D($a0)
    MEM_B(0X11D, ctx->r4) = ctx->r25;
    after_0:
    // 0x80801BA0: beq         $v0, $zero, L_80801BB8
    if (ctx->r2 == 0) {
        // 0x80801BA4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80801BB8;
    }
    // 0x80801BA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801BA8: jal         0x80800A50
    // 0x80801BAC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_1;
    // 0x80801BAC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80801BB0: b           L_80801C48
    // 0x80801BB4: lbu         $t6, 0x161($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X161);
        goto L_80801C48;
    // 0x80801BB4: lbu         $t6, 0x161($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X161);
L_80801BB8:
    // 0x80801BB8: lbu         $t0, 0x15C($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X15C);
    // 0x80801BBC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801BC0: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80801BC4: beq         $t0, $at, L_80801C44
    if (ctx->r8 == ctx->r1) {
        // 0x80801BC8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80801C44;
    }
    // 0x80801BC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801BCC: lbu         $t1, 0x15F($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X15F);
    // 0x80801BD0: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x80801BD4: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x80801BD8: andi        $t2, $t1, 0xFFFC
    ctx->r10 = ctx->r9 & 0XFFFC;
    // 0x80801BDC: sb          $t2, 0x15F($s3)
    MEM_B(0X15F, ctx->r19) = ctx->r10;
L_80801BE0:
    // 0x80801BE0: lbu         $t3, 0x11C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X11C);
    // 0x80801BE4: andi        $t4, $t3, 0xFF3F
    ctx->r12 = ctx->r11 & 0XFF3F;
    // 0x80801BE8: sb          $t4, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = ctx->r12;
    // 0x80801BEC: lw          $a0, 0x120($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X120);
    // 0x80801BF0: beql        $a0, $zero, L_80801C20
    if (ctx->r4 == 0) {
        // 0x80801BF4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80801C20;
    }
    goto skip_0;
    // 0x80801BF4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x80801BF8: jal         0x80087BE8
    // 0x80801BFC: nop

    _gczoombox_entrypoint_33(rdram, ctx);
        goto after_2;
    // 0x80801BFC: nop

    after_2:
    // 0x80801C00: lw          $t6, 0x15C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X15C);
    // 0x80801C04: lbu         $t0, 0x15F($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X15F);
    // 0x80801C08: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x80801C0C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x80801C10: andi        $t1, $t0, 0xFFFC
    ctx->r9 = ctx->r8 & 0XFFFC;
    // 0x80801C14: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80801C18: sb          $t2, 0x15F($s3)
    MEM_B(0X15F, ctx->r19) = ctx->r10;
    // 0x80801C1C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80801C20:
    // 0x80801C20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801C24: bne         $s1, $s4, L_80801BE0
    if (ctx->r17 != ctx->r20) {
        // 0x80801C28: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80801BE0;
    }
    // 0x80801C28: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80801C2C: lw          $t3, 0x15C($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X15C);
    // 0x80801C30: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80801C34: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80801C38: beql        $t4, $zero, L_80801C48
    if (ctx->r12 == 0) {
        // 0x80801C3C: lbu         $t6, 0x161($s3)
        ctx->r14 = MEM_BU(ctx->r19, 0X161);
            goto L_80801C48;
    }
    goto skip_1;
    // 0x80801C3C: lbu         $t6, 0x161($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X161);
    skip_1:
    // 0x80801C40: sb          $t5, 0x15C($s3)
    MEM_B(0X15C, ctx->r19) = ctx->r13;
L_80801C44:
    // 0x80801C44: lbu         $t6, 0x161($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X161);
L_80801C48:
    // 0x80801C48: andi        $t8, $t6, 0xFF0F
    ctx->r24 = ctx->r14 & 0XFF0F;
    // 0x80801C4C: sb          $t8, 0x161($s3)
    MEM_B(0X161, ctx->r19) = ctx->r24;
    // 0x80801C50: andi        $t0, $t8, 0xF0
    ctx->r8 = ctx->r24 & 0XF0;
    // 0x80801C54: sb          $t0, 0x161($s3)
    MEM_B(0X161, ctx->r19) = ctx->r8;
    // 0x80801C58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801C5C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801C60: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801C64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801C68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801C70: jr          $ra
    // 0x80801C74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801C74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bsjump_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083290: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083290);
    return;
    // 0x80083294: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80809D94_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809D94: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80809D98: jr          $ra
    // 0x80809D9C: lwc1        $f0, 0x25C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X25C);
    return;
    // 0x80809D9C: lwc1        $f0, 0x25C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X25C);
;}
RECOMP_FUNC void _chgoldsnakehead_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085970: syscall     183
    recomp_syscall_handler(rdram, ctx, 0x80085970);
    return;
    // 0x80085974: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
