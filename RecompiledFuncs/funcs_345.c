#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void fxsparkle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080003C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800044: jal         0x80088AD0
    // 0x80800048: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _fxspgold_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800048: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080004C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800050: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2794, 0X3AC) << 16);
    // 0x80800054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800058: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8080005C: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80800060: lw          $v1, 0x3AC($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(2794, 0X3AC));
    // 0x80800064: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800068: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080006C: beq         $v1, $zero, L_8080007C
    if (ctx->r3 == 0) {
        // 0x80800070: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_8080007C;
    }
    // 0x80800070: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800074: jal         0x800BABB8
    // 0x80800078: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800078: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_1:
L_8080007C:
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800080: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void func_80800784_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080078C: lw          $a2, 0x2C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X2C);
    // 0x80800790: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800794: beq         $a2, $zero, L_808007AC
    if (ctx->r6 == 0) {
        // 0x80800798: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808007AC;
    }
    // 0x80800798: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080079C: jal         0x800B5450
    // 0x808007A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800B5450(rdram, ctx);
        goto after_0;
    // 0x808007A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808007A4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808007A8: sw          $zero, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = 0;
L_808007AC:
    // 0x808007AC: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x808007B0: beq         $v0, $zero, L_808007C8
    if (ctx->r2 == 0) {
        // 0x808007B4: addiu       $a0, $v0, -0x1
        ctx->r4 = ADD32(ctx->r2, -0X1);
            goto L_808007C8;
    }
    // 0x808007B4: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x808007B8: jal         0x800E1720
    // 0x808007BC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800E1720(rdram, ctx);
        goto after_1;
    // 0x808007BC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x808007C0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808007C4: sw          $zero, 0x30($a1)
    MEM_W(0X30, ctx->r5) = 0;
L_808007C8:
    // 0x808007C8: lbu         $a0, 0x24($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X24);
    // 0x808007CC: beql        $a0, $zero, L_808007E8
    if (ctx->r4 == 0) {
        // 0x808007D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007E8;
    }
    goto skip_0;
    // 0x808007D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808007D4: jal         0x80089D48
    // 0x808007D8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808007D8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x808007DC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808007E0: sb          $v0, 0x24($a1)
    MEM_B(0X24, ctx->r5) = ctx->r2;
    // 0x808007E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007E8:
    // 0x808007E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007EC: jr          $ra
    // 0x808007F0: nop

    return;
    // 0x808007F0: nop

;}
RECOMP_FUNC void _gcmapDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088120: syscall     672
    recomp_syscall_handler(rdram, ctx, 0x80088120);
    return;
    // 0x80088124: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bskazegghead_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083418: syscall     61
    recomp_syscall_handler(rdram, ctx, 0x80083418);
    return;
    // 0x8008341C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080025C_chtimetable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800268: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080026C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800270: jal         0x808000B0
    // 0x80800274: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808000B0_chtimetable(rdram, ctx);
        goto after_0;
    // 0x80800274: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800278: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8080027C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80800280: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800284: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1592, 0X73C) << 16);
    // 0x80800288: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8080028C: jal         0x800DA544
    // 0x80800290: lw          $a0, 0x73C($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1592, 0X73C));
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800290: lw          $a0, 0x73C($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1592, 0X73C));
    after_1:
    // 0x80800294: jal         0x800DA544
    // 0x80800298: addiu       $a0, $zero, 0x6B7
    ctx->r4 = ADD32(0, 0X6B7);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800298: addiu       $a0, $zero, 0x6B7
    ctx->r4 = ADD32(0, 0X6B7);
    after_2:
    // 0x8080029C: jal         0x800887A8
    // 0x808002A0: nop

    _glcutDll_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808002A0: nop

    after_3:
    // 0x808002A4: jal         0x800887E0
    // 0x808002A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _glcutDll_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x808002A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x808002AC: jal         0x800887F8
    // 0x808002B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _glcutDll_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x808002B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808002B4: jal         0x80088858
    // 0x808002B8: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    _glcutDll_entrypoint_22(rdram, ctx);
        goto after_6;
    // 0x808002B8: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    after_6:
    // 0x808002BC: jal         0x80088828
    // 0x808002C0: nop

    _glcutDll_entrypoint_16(rdram, ctx);
        goto after_7;
    // 0x808002C0: nop

    after_7:
    // 0x808002C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002CC: jr          $ra
    // 0x808002D0: nop

    return;
    // 0x808002D0: nop

;}
RECOMP_FUNC void sumole_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801630: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801638: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080163C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80801640: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801644: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80801648: addiu       $a1, $zero, 0xD7D
    ctx->r5 = ADD32(0, 0XD7D);
    // 0x8080164C: jal         0x800DC128
    // 0x80801650: addiu       $a0, $zero, 0xD7B
    ctx->r4 = ADD32(0, 0XD7B);
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x80801650: addiu       $a0, $zero, 0xD7B
    ctx->r4 = ADD32(0, 0XD7B);
    after_0:
    // 0x80801654: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80801658: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8080165C: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80801660: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801664: beq         $a3, $at, L_80801748
    if (ctx->r7 == ctx->r1) {
        // 0x80801668: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80801748;
    }
    // 0x80801668: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8080166C: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80801670: beq         $a3, $at, L_80801688
    if (ctx->r7 == ctx->r1) {
        // 0x80801674: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_80801688;
    }
    // 0x80801674: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80801678: beq         $a3, $at, L_808016E8
    if (ctx->r7 == ctx->r1) {
        // 0x8080167C: nop
    
            goto L_808016E8;
    }
    // 0x8080167C: nop

    // 0x80801680: b           L_808017A8
    // 0x80801684: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_808017A8;
    // 0x80801684: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80801688:
    // 0x80801688: jal         0x8010D278
    // 0x8080168C: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    func_8010D278(rdram, ctx);
        goto after_1;
    // 0x8080168C: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_1:
    // 0x80801690: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80801694: bne         $v0, $at, L_808016B8
    if (ctx->r2 != ctx->r1) {
        // 0x80801698: lh          $a1, 0x1E($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X1E);
            goto L_808016B8;
    }
    // 0x80801698: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x8080169C: addiu       $a0, $zero, 0xD71
    ctx->r4 = ADD32(0, 0XD71);
    // 0x808016A0: jal         0x800DC128
    // 0x808016A4: addiu       $a1, $zero, 0xD73
    ctx->r5 = ADD32(0, 0XD73);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x808016A4: addiu       $a1, $zero, 0xD73
    ctx->r5 = ADD32(0, 0XD73);
    after_2:
    // 0x808016A8: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x808016AC: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808016B0: b           L_808017A4
    // 0x808016B4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_808017A4;
    // 0x808016B4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_808016B8:
    // 0x808016B8: jal         0x8010D278
    // 0x808016BC: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    func_8010D278(rdram, ctx);
        goto after_3;
    // 0x808016BC: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_3:
    // 0x808016C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808016C4: bne         $v0, $at, L_808017A4
    if (ctx->r2 != ctx->r1) {
        // 0x808016C8: lh          $a1, 0x1E($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X1E);
            goto L_808017A4;
    }
    // 0x808016C8: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x808016CC: addiu       $a0, $zero, 0xD6F
    ctx->r4 = ADD32(0, 0XD6F);
    // 0x808016D0: jal         0x800DC128
    // 0x808016D4: addiu       $a1, $zero, 0xD71
    ctx->r5 = ADD32(0, 0XD71);
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x808016D4: addiu       $a1, $zero, 0xD71
    ctx->r5 = ADD32(0, 0XD71);
    after_4:
    // 0x808016D8: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x808016DC: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808016E0: b           L_808017A4
    // 0x808016E4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_808017A4;
    // 0x808016E4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_808016E8:
    // 0x808016E8: jal         0x8010D278
    // 0x808016EC: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    func_8010D278(rdram, ctx);
        goto after_5;
    // 0x808016EC: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_5:
    // 0x808016F0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808016F4: bne         $v0, $at, L_80801718
    if (ctx->r2 != ctx->r1) {
        // 0x808016F8: lh          $a1, 0x1E($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X1E);
            goto L_80801718;
    }
    // 0x808016F8: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x808016FC: addiu       $a0, $zero, 0xD73
    ctx->r4 = ADD32(0, 0XD73);
    // 0x80801700: jal         0x800DC128
    // 0x80801704: addiu       $a1, $zero, 0xD75
    ctx->r5 = ADD32(0, 0XD75);
    func_800DC128(rdram, ctx);
        goto after_6;
    // 0x80801704: addiu       $a1, $zero, 0xD75
    ctx->r5 = ADD32(0, 0XD75);
    after_6:
    // 0x80801708: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8080170C: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80801710: b           L_808017A4
    // 0x80801714: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
        goto L_808017A4;
    // 0x80801714: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_80801718:
    // 0x80801718: jal         0x8010D278
    // 0x8080171C: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    func_8010D278(rdram, ctx);
        goto after_7;
    // 0x8080171C: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_7:
    // 0x80801720: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801724: bne         $v0, $at, L_808017A4
    if (ctx->r2 != ctx->r1) {
        // 0x80801728: lh          $a1, 0x1E($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X1E);
            goto L_808017A4;
    }
    // 0x80801728: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x8080172C: addiu       $a0, $zero, 0xD75
    ctx->r4 = ADD32(0, 0XD75);
    // 0x80801730: jal         0x800DC128
    // 0x80801734: addiu       $a1, $zero, 0xD77
    ctx->r5 = ADD32(0, 0XD77);
    func_800DC128(rdram, ctx);
        goto after_8;
    // 0x80801734: addiu       $a1, $zero, 0xD77
    ctx->r5 = ADD32(0, 0XD77);
    after_8:
    // 0x80801738: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8080173C: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80801740: b           L_808017A4
    // 0x80801744: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_808017A4;
    // 0x80801744: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_80801748:
    // 0x80801748: jal         0x8010D278
    // 0x8080174C: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    func_8010D278(rdram, ctx);
        goto after_9;
    // 0x8080174C: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_9:
    // 0x80801750: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80801754: bne         $v0, $at, L_80801778
    if (ctx->r2 != ctx->r1) {
        // 0x80801758: lh          $a1, 0x1E($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X1E);
            goto L_80801778;
    }
    // 0x80801758: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x8080175C: addiu       $a0, $zero, 0xD79
    ctx->r4 = ADD32(0, 0XD79);
    // 0x80801760: jal         0x800DC128
    // 0x80801764: addiu       $a1, $zero, 0xD7B
    ctx->r5 = ADD32(0, 0XD7B);
    func_800DC128(rdram, ctx);
        goto after_10;
    // 0x80801764: addiu       $a1, $zero, 0xD7B
    ctx->r5 = ADD32(0, 0XD7B);
    after_10:
    // 0x80801768: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8080176C: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80801770: b           L_808017A4
    // 0x80801774: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
        goto L_808017A4;
    // 0x80801774: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80801778:
    // 0x80801778: jal         0x8010D278
    // 0x8080177C: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    func_8010D278(rdram, ctx);
        goto after_11;
    // 0x8080177C: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_11:
    // 0x80801780: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80801784: bne         $v0, $at, L_808017A4
    if (ctx->r2 != ctx->r1) {
        // 0x80801788: lh          $a1, 0x1E($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X1E);
            goto L_808017A4;
    }
    // 0x80801788: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x8080178C: addiu       $a0, $zero, 0xD77
    ctx->r4 = ADD32(0, 0XD77);
    // 0x80801790: jal         0x800DC128
    // 0x80801794: addiu       $a1, $zero, 0xD79
    ctx->r5 = ADD32(0, 0XD79);
    func_800DC128(rdram, ctx);
        goto after_12;
    // 0x80801794: addiu       $a1, $zero, 0xD79
    ctx->r5 = ADD32(0, 0XD79);
    after_12:
    // 0x80801798: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8080179C: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808017A0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_808017A4:
    // 0x808017A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808017A8:
    // 0x808017A8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808017AC: jal         0x80801B34
    // 0x808017B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sumole_entrypoint_17(rdram, ctx);
        goto after_13;
    // 0x808017B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x808017B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808017B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808017BC: jr          $ra
    // 0x808017C0: nop

    return;
    // 0x808017C0: nop

;}
RECOMP_FUNC void func_80102FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102FDC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80102FE0: jr          $ra
    // 0x80102FE4: swc1        $f12, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80102FE4: swc1        $f12, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80102BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102BAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80102BB0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80102BB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80102BB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80102BBC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80102BC0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80102BC4: lwc1        $f14, 0x54($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80102BC8: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80102BCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80102BD0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80102BD4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80102BD8: jal         0x800F1FF0
    // 0x80102BDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_0;
    // 0x80102BDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80102BE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80102BE4: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x80102BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80102BEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80102BF0: jr          $ra
    // 0x80102BF4: nop

    return;
    // 0x80102BF4: nop

;}
RECOMP_FUNC void func_80805C1C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805C1C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80805C20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80805C24: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9BA4) << 16);
    // 0x80805C28: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80805C2C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80805C30: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80805C34: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80805C38: jal         0x800DC298
    // 0x80805C3C: lwc1        $f12, -0x645C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9BA4));
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80805C3C: lwc1        $f12, -0x645C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9BA4));
    after_0:
    // 0x80805C40: beql        $v0, $zero, L_80805D58
    if (ctx->r2 == 0) {
        // 0x80805C44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80805D58;
    }
    goto skip_0;
    // 0x80805C44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80805C48: jal         0x80802228
    // 0x80805C4C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80805C4C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x80805C50: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80805C54: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80805C58: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80805C5C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80805C60: jal         0x800DC178
    // 0x80805C64: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80805C64: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x80805C68: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80805C6C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80805C70: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80805C74: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80805C78: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80805C7C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80805C80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80805C84: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80805C88: jal         0x800EFA4C
    // 0x80805C8C: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80805C8C: nop

    after_3:
    // 0x80805C90: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x80805C94: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80805C98: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80805C9C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80805CA0: jal         0x800DC178
    // 0x80805CA4: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80805CA4: nop

    after_4:
    // 0x80805CA8: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80805CAC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80805CB0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80805CB4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80805CB8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80805CBC: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x80805CC0: jal         0x800EF934
    // 0x80805CC4: lw          $a2, 0x48($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X48);
    func_800EF934(rdram, ctx);
        goto after_5;
    // 0x80805CC4: lw          $a2, 0x48($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X48);
    after_5:
    // 0x80805CC8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80805CCC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80805CD0: jal         0x800EF04C
    // 0x80805CD4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80805CD4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_6:
    // 0x80805CD8: jal         0x800B53A4
    // 0x80805CDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_7;
    // 0x80805CDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80805CE0: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(1480, 0XA0B4) << 16);
    // 0x80805CE4: addiu       $t8, $t8, -0x5F4C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1480, 0XA0B4));
    // 0x80805CE8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80805CEC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80805CF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80805CF4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80805CF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80805CFC: jal         0x800BABB8
    // 0x80805D00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_8;
    // 0x80805D00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x80805D04: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80805D08: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80805D0C: addiu       $t5, $zero, 0x190
    ctx->r13 = ADD32(0, 0X190);
    // 0x80805D10: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80805D14: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80805D18: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80805D1C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80805D20: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80805D24: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    // 0x80805D28: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80805D2C: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x80805D30: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80805D34: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x80805D38: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80805D3C: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x80805D40: jal         0x800BA994
    // 0x80805D44: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    func_800BA994(rdram, ctx);
        goto after_9;
    // 0x80805D44: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    after_9:
    // 0x80805D48: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80805D4C: jal         0x800BA22C
    // 0x80805D50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_10;
    // 0x80805D50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80805D54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805D58:
    // 0x80805D58: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80805D5C: jr          $ra
    // 0x80805D60: nop

    return;
    // 0x80805D60: nop

;}
RECOMP_FUNC void ncbapan_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080009C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A8: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    // 0x808000AC: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x808000B0: jal         0x801120CC
    // 0x808000B4: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    func_801120CC(rdram, ctx);
        goto after_0;
    // 0x808000B4: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    after_0:
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x808000C0: jal         0x80111B8C
    // 0x808000C4: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_1;
    // 0x808000C4: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_1:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x801124D0
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_2;
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x80115858
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80115858(rdram, ctx);
        goto after_3;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x80115870
    // 0x808000E8: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80115870(rdram, ctx);
        goto after_4;
    // 0x808000E8: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_4:
    // 0x808000EC: jal         0x80800048
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800048_ncbapan(rdram, ctx);
        goto after_5;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void func_80110DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110DA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110DA8: jal         0x80115460
    // 0x80110DAC: nop

    func_80115460(rdram, ctx);
        goto after_0;
    // 0x80110DAC: nop

    after_0:
    // 0x80110DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110DB8: jr          $ra
    // 0x80110DBC: nop

    return;
    // 0x80110DBC: nop

;}
RECOMP_FUNC void func_8080091C_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080091C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800924: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800928: jal         0x80100094
    // 0x8080092C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080092C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800930: addiu       $a2, $v0, 0x154
    ctx->r6 = ADD32(ctx->r2, 0X154);
    // 0x80800934: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800938: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080093C: jal         0x80100094
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800944: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800948: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1172, 0X11F4) << 16);
    // 0x8080094C: addiu       $v1, $a0, 0x11F4
    ctx->r3 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1172, 0X11F4));
    // 0x80800950: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80800954: sb          $zero, 0x19($v0)
    MEM_B(0X19, ctx->r2) = 0;
    // 0x80800958: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8080095C: beql        $t6, $zero, L_8080098C
    if (ctx->r14 == 0) {
        // 0x80800960: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080098C;
    }
    goto skip_0;
    // 0x80800960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800964: lbu         $t7, 0xA($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XA);
L_80800968:
    // 0x80800968: beql        $t7, $zero, L_80800978
    if (ctx->r15 == 0) {
        // 0x8080096C: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_80800978;
    }
    goto skip_1;
    // 0x8080096C: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    skip_1:
    // 0x80800970: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80800974: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_80800978:
    // 0x80800978: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8080097C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80800980: bnel        $t8, $zero, L_80800968
    if (ctx->r24 != 0) {
        // 0x80800984: lbu         $t7, 0xA($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0XA);
            goto L_80800968;
    }
    goto skip_2;
    // 0x80800984: lbu         $t7, 0xA($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XA);
    skip_2:
    // 0x80800988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080098C:
    // 0x8080098C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800990: jr          $ra
    // 0x80800994: nop

    return;
    // 0x80800994: nop

;}
RECOMP_FUNC void func_808010B4_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010BC: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x808010C0: addiu       $at, $zero, 0x2AA
    ctx->r1 = ADD32(0, 0X2AA);
    // 0x808010C4: addiu       $t8, $zero, 0x1B0
    ctx->r24 = ADD32(0, 0X1B0);
    // 0x808010C8: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x808010CC: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x808010D0: beq         $t7, $at, L_808010E8
    if (ctx->r15 == ctx->r1) {
        // 0x808010D4: addiu       $at, $zero, 0x2AB
        ctx->r1 = ADD32(0, 0X2AB);
            goto L_808010E8;
    }
    // 0x808010D4: addiu       $at, $zero, 0x2AB
    ctx->r1 = ADD32(0, 0X2AB);
    // 0x808010D8: beq         $t7, $at, L_808010F0
    if (ctx->r15 == ctx->r1) {
        // 0x808010DC: addiu       $t9, $zero, 0x1B1
        ctx->r25 = ADD32(0, 0X1B1);
            goto L_808010F0;
    }
    // 0x808010DC: addiu       $t9, $zero, 0x1B1
    ctx->r25 = ADD32(0, 0X1B1);
    // 0x808010E0: b           L_808010F4
    // 0x808010E4: nop

        goto L_808010F4;
    // 0x808010E4: nop

L_808010E8:
    // 0x808010E8: b           L_808010F4
    // 0x808010EC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
        goto L_808010F4;
    // 0x808010EC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_808010F0:
    // 0x808010F0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_808010F4:
    // 0x808010F4: jal         0x80088F08
    // 0x808010F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _idworld_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808010F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x808010FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801104: jr          $ra
    // 0x80801108: nop

    return;
    // 0x80801108: nop

;}
RECOMP_FUNC void func_800B7BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7BB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7BB4: lw          $a0, -0x7D50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D50);
    // 0x800B7BB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7BBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7BC0: beq         $a0, $zero, L_800B7BD0
    if (ctx->r4 == 0) {
        // 0x800B7BC4: nop
    
            goto L_800B7BD0;
    }
    // 0x800B7BC4: nop

    // 0x800B7BC8: jal         0x80088938
    // 0x800B7BCC: nop

    _fxleaves_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800B7BCC: nop

    after_0:
L_800B7BD0:
    // 0x800B7BD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7BD4: lw          $a0, -0x7D4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D4C);
    // 0x800B7BD8: beq         $a0, $zero, L_800B7BE8
    if (ctx->r4 == 0) {
        // 0x800B7BDC: nop
    
            goto L_800B7BE8;
    }
    // 0x800B7BDC: nop

    // 0x800B7BE0: jal         0x800888E8
    // 0x800B7BE4: nop

    _fxrain_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x800B7BE4: nop

    after_1:
L_800B7BE8:
    // 0x800B7BE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B7BEC: lw          $t6, 0x7128($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7128);
    // 0x800B7BF0: beql        $t6, $zero, L_800B7C04
    if (ctx->r14 == 0) {
        // 0x800B7BF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B7C04;
    }
    goto skip_0;
    // 0x800B7BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B7BF8: jal         0x800B956C
    // 0x800B7BFC: nop

    func_800B956C(rdram, ctx);
        goto after_2;
    // 0x800B7BFC: nop

    after_2:
    // 0x800B7C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B7C04:
    // 0x800B7C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7C08: jr          $ra
    // 0x800B7C0C: nop

    return;
    // 0x800B7C0C: nop

;}
RECOMP_FUNC void func_8080045C_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080045C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800464: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800468: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080046C: jal         0x80100094
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800478: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x8080047C: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x80800480: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800484: jal         0x8008A0C0
    // 0x80800488: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    _subaddiemarker_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800488: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080048C: jal         0x800DA298
    // 0x80800490: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800490: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_2:
    // 0x80800494: bne         $v0, $zero, L_808004C0
    if (ctx->r2 != 0) {
        // 0x80800498: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_808004C0;
    }
    // 0x80800498: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A0: jal         0x80102424
    // 0x808004A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808004A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808004A8: lui         $a1, 0x3E5D
    ctx->r5 = S32(0X3E5D << 16);
    // 0x808004AC: ori         $a1, $a1, 0x1746
    ctx->r5 = ctx->r5 | 0X1746;
    // 0x808004B0: jal         0x80101EE4
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_4;
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808004B8: b           L_808004E4
    // 0x808004BC: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
        goto L_808004E4;
    // 0x808004BC: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
L_808004C0:
    // 0x808004C0: addiu       $a0, $zero, 0x210
    ctx->r4 = ADD32(0, 0X210);
    // 0x808004C4: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x808004C8: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x808004CC: jal         0x80108A30
    // 0x808004D0: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    func_80108A30(rdram, ctx);
        goto after_5;
    // 0x808004D0: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    after_5:
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: jal         0x80102424
    // 0x808004DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808004DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808004E0: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
L_808004E4:
    // 0x808004E4: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x808004E8: ori         $t8, $t7, 0x30
    ctx->r24 = ctx->r15 | 0X30;
    // 0x808004EC: jal         0x800EA05C
    // 0x808004F0: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
    func_800EA05C(rdram, ctx);
        goto after_7;
    // 0x808004F0: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
    after_7:
    // 0x808004F4: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x808004F8: beql        $v0, $at, L_8080050C
    if (ctx->r2 == ctx->r1) {
        // 0x808004FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080050C;
    }
    goto skip_0;
    // 0x808004FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800500: jal         0x8010A624
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_8;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080050C:
    // 0x8080050C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800510: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800514: jr          $ra
    // 0x80800518: nop

    return;
    // 0x80800518: nop

;}
RECOMP_FUNC void func_80802480_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802488: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080248C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80802490: jal         0x80100094
    // 0x80802494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802498: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x8080249C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1240, 0X38A0) << 16);
    // 0x808024A0: addiu       $t8, $t8, 0x38A0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1240, 0X38A0));
    // 0x808024A4: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x808024A8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x808024AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808024B0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x808024B4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808024B8: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x808024BC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x808024C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024C4: bnel        $a2, $t9, L_808024D8
    if (ctx->r6 != ctx->r25) {
        // 0x808024C8: lw          $t0, 0x10($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X10);
            goto L_808024D8;
    }
    goto skip_0;
    // 0x808024C8: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x808024CC: b           L_80802550
    // 0x808024D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802550;
    // 0x808024D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808024D4: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
L_808024D8:
    // 0x808024D8: addiu       $v1, $a1, 0x10
    ctx->r3 = ADD32(ctx->r5, 0X10);
    // 0x808024DC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808024E0: bne         $a2, $t0, L_808024F0
    if (ctx->r6 != ctx->r8) {
        // 0x808024E4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_808024F0;
    }
    // 0x808024E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808024E8: b           L_80802550
    // 0x808024EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802550;
    // 0x808024EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808024F0:
    // 0x808024F0: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x808024F4: bnel        $a2, $t1, L_80802508
    if (ctx->r6 != ctx->r9) {
        // 0x808024F8: lw          $t2, 0x10($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X10);
            goto L_80802508;
    }
    goto skip_1;
    // 0x808024F8: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    skip_1:
    // 0x808024FC: b           L_80802550
    // 0x80802500: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80802550;
    // 0x80802500: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80802504: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
L_80802508:
    // 0x80802508: bnel        $a2, $t2, L_8080251C
    if (ctx->r6 != ctx->r10) {
        // 0x8080250C: lw          $t3, 0x18($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X18);
            goto L_8080251C;
    }
    goto skip_2;
    // 0x8080250C: lw          $t3, 0x18($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X18);
    skip_2:
    // 0x80802510: b           L_80802550
    // 0x80802514: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_80802550;
    // 0x80802514: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80802518: lw          $t3, 0x18($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X18);
L_8080251C:
    // 0x8080251C: bnel        $a2, $t3, L_80802530
    if (ctx->r6 != ctx->r11) {
        // 0x80802520: lw          $t4, 0x20($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X20);
            goto L_80802530;
    }
    goto skip_3;
    // 0x80802520: lw          $t4, 0x20($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X20);
    skip_3:
    // 0x80802524: b           L_80802550
    // 0x80802528: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
        goto L_80802550;
    // 0x80802528: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x8080252C: lw          $t4, 0x20($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X20);
L_80802530:
    // 0x80802530: bnel        $a2, $t4, L_80802544
    if (ctx->r6 != ctx->r12) {
        // 0x80802534: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80802544;
    }
    goto skip_4;
    // 0x80802534: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    skip_4:
    // 0x80802538: b           L_80802550
    // 0x8080253C: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
        goto L_80802550;
    // 0x8080253C: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
    // 0x80802540: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80802544:
    // 0x80802544: bne         $a0, $a1, L_808024F0
    if (ctx->r4 != ctx->r5) {
        // 0x80802548: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_808024F0;
    }
    // 0x80802548: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8080254C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80802550:
    // 0x80802550: jr          $ra
    // 0x80802554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80802554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800110_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080011C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800120: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800124: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800128: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080012C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800130: bnel        $t7, $at, L_808001B4
    if (ctx->r15 != ctx->r1) {
        // 0x80800134: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001B4;
    }
    goto skip_0;
    // 0x80800134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800138: jal         0x8008FCC8
    // 0x8080013C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_8008FCC8(rdram, ctx);
        goto after_0;
    // 0x8080013C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800140: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800144: beq         $v0, $at, L_80800160
    if (ctx->r2 == ctx->r1) {
        // 0x80800148: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800160;
    }
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800150: beq         $v0, $at, L_80800168
    if (ctx->r2 == ctx->r1) {
        // 0x80800154: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80800168;
    }
    // 0x80800154: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800158: b           L_80800168
    // 0x8080015C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
        goto L_80800168;
    // 0x8080015C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_80800160:
    // 0x80800160: b           L_80800168
    // 0x80800164: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80800168;
    // 0x80800164: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800168:
    // 0x80800168: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080016C: beq         $a2, $at, L_808001B0
    if (ctx->r6 == ctx->r1) {
        // 0x80800170: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_808001B0;
    }
    // 0x80800170: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800174: jal         0x80102424
    // 0x80800178: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800178: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x8080017C: jal         0x800880D0
    // 0x80800180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x80103110
    // 0x8080018C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x8080018C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800190: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800194: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800198: addiu       $a0, $zero, 0x13B
    ctx->r4 = ADD32(0, 0X13B);
    // 0x8080019C: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808001A0: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x808001A4: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x808001A8: jal         0x80101180
    // 0x808001AC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80101180(rdram, ctx);
        goto after_4;
    // 0x808001AC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_4:
L_808001B0:
    // 0x808001B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001B4:
    // 0x808001B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
RECOMP_FUNC void func_800C72EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C72EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C72F0: addiu       $v0, $v0, -0x56FC
    ctx->r2 = ADD32(ctx->r2, -0X56FC);
    // 0x800C72F4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800C72F8: beq         $t6, $zero, L_800C7308
    if (ctx->r14 == 0) {
        // 0x800C72FC: nop
    
            goto L_800C7308;
    }
    // 0x800C72FC: nop

    // 0x800C7300: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800C7304: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800C7308:
    // 0x800C7308: jr          $ra
    // 0x800C730C: nop

    return;
    // 0x800C730C: nop

;}
RECOMP_FUNC void _chnests_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A78: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085A78);
    return;
    // 0x80085A7C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080111C_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080111C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801124: jal         0x8009EA64
    // 0x80801128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA64(rdram, ctx);
        goto after_0;
    // 0x80801128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080112C: addiu       $at, $zero, 0x38A
    ctx->r1 = ADD32(0, 0X38A);
    // 0x80801130: bne         $v0, $at, L_8080114C
    if (ctx->r2 != ctx->r1) {
        // 0x80801134: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080114C;
    }
    // 0x80801134: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801138: jal         0x800907C0
    // 0x8080113C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800907C0(rdram, ctx);
        goto after_1;
    // 0x8080113C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80801140: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801144: jal         0x800906DC
    // 0x80801148: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    func_800906DC(rdram, ctx);
        goto after_2;
    // 0x80801148: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    after_2:
L_8080114C:
    // 0x8080114C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801154: jr          $ra
    // 0x80801158: nop

    return;
    // 0x80801158: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5E0: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5E0);
    return;
    // 0x8008A5E4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _chpumproomswitch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E90: syscall     254
    recomp_syscall_handler(rdram, ctx, 0x80085E90);
    return;
    // 0x80085E94: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80100AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100AC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100AC8: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80100ACC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80100AD0: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80100AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100AD8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100ADC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80100AE0: jal         0x800B301C
    // 0x80100AE4: lw          $a0, 0x5A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A60);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x80100AE4: lw          $a0, 0x5A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A60);
    after_0:
    // 0x80100AE8: lbu         $t7, 0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8);
    // 0x80100AEC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80100AF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100AF4: bne         $t7, $zero, L_80100B04
    if (ctx->r15 != 0) {
        // 0x80100AF8: nop
    
            goto L_80100B04;
    }
    // 0x80100AF8: nop

    // 0x80100AFC: b           L_80100B2C
    // 0x80100B00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100B2C;
    // 0x80100B00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100B04:
    // 0x80100B04: lw          $a0, 0x5A64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A64);
    // 0x80100B08: jal         0x800B301C
    // 0x80100B0C: lbu         $a1, 0x8($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X8);
    freelist_at(rdram, ctx);
        goto after_1;
    // 0x80100B0C: lbu         $a1, 0x8($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X8);
    after_1:
    // 0x80100B10: lbu         $t8, 0x8($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X8);
    // 0x80100B14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80100B18: beq         $t8, $zero, L_80100B28
    if (ctx->r24 == 0) {
        // 0x80100B1C: nop
    
            goto L_80100B28;
    }
    // 0x80100B1C: nop

    // 0x80100B20: b           L_80100B28
    // 0x80100B24: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
        goto L_80100B28;
    // 0x80100B24: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_80100B28:
    // 0x80100B28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80100B2C:
    // 0x80100B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100B34: jr          $ra
    // 0x80100B38: nop

    return;
    // 0x80100B38: nop

;}
RECOMP_FUNC void func_800F15F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F15F8: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x800F15FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F1600: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800F1604: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x800F1608: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F160C: bc1f        L_800F1628
    if (!c1cs) {
        // 0x800F1610: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_800F1628;
    }
    // 0x800F1610: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F1614: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F1618: jal         0x800F13F0
    // 0x800F161C: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    func_800F13F0(rdram, ctx);
        goto after_0;
    // 0x800F161C: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    after_0:
    // 0x800F1620: b           L_800F1650
    // 0x800F1624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800F1650;
    // 0x800F1624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F1628:
    // 0x800F1628: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x800F162C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F1630: bc1fl       L_800F164C
    if (!c1cs) {
        // 0x800F1634: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_800F164C;
    }
    goto skip_0;
    // 0x800F1634: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_0:
    // 0x800F1638: jal         0x800F0E00
    // 0x800F163C: sub.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f6.fl;
    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x800F163C: sub.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f6.fl;
    after_1:
    // 0x800F1640: b           L_800F1650
    // 0x800F1644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800F1650;
    // 0x800F1644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F1648: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_800F164C:
    // 0x800F164C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F1650:
    // 0x800F1650: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800F1654: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F1658: jr          $ra
    // 0x800F165C: nop

    return;
    // 0x800F165C: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808013BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808013C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808013C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808013CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808013D0: jal         0x8009D3A8
    // 0x808013D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x808013D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013D8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808013DC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808013E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013E4: jal         0x800A2CE8
    // 0x808013E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_1;
    // 0x808013E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x808013EC: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x808013F0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808013F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013F8: jal         0x800A2CE8
    // 0x808013FC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_2;
    // 0x808013FC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80801400: jal         0x80800000
    // 0x80801404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bstaxi(rdram, ctx);
        goto after_3;
    // 0x80801404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801408: jal         0x8009EF10
    // 0x8080140C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_4;
    // 0x8080140C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801410: bne         $v0, $zero, L_8080141C
    if (ctx->r2 != 0) {
        // 0x80801414: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080141C;
    }
    // 0x80801414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801418: addiu       $s1, $zero, 0x125
    ctx->r17 = ADD32(0, 0X125);
L_8080141C:
    // 0x8080141C: jal         0x80800064
    // 0x80801420: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800064_bstaxi(rdram, ctx);
        goto after_5;
    // 0x80801420: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80801424: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801428: jal         0x8008E148
    // 0x8080142C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_6;
    // 0x8080142C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801430: beq         $v0, $zero, L_8080143C
    if (ctx->r2 == 0) {
        // 0x80801434: nop
    
            goto L_8080143C;
    }
    // 0x80801434: nop

    // 0x80801438: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8080143C:
    // 0x8080143C: jal         0x8008E260
    // 0x80801440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_7;
    // 0x80801440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801444: beq         $v0, $zero, L_80801450
    if (ctx->r2 == 0) {
        // 0x80801448: nop
    
            goto L_80801450;
    }
    // 0x80801448: nop

    // 0x8080144C: addiu       $s1, $zero, 0x3D
    ctx->r17 = ADD32(0, 0X3D);
L_80801450:
    // 0x80801450: jal         0x8008E35C
    // 0x80801454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_8;
    // 0x80801454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801458: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x8080145C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x8080145C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801460: addiu       $s1, $zero, 0x4C
    ctx->r17 = ADD32(0, 0X4C);
L_80801464:
    // 0x80801464: jal         0x800A02DC
    // 0x80801468: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A02DC(rdram, ctx);
        goto after_9;
    // 0x80801468: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x8080146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801470: jal         0x8009E5C8
    // 0x80801474: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x80801474: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80801478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080147C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801480: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801484: jr          $ra
    // 0x80801488: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801488: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chhotwatersteam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086748: syscall     363
    recomp_syscall_handler(rdram, ctx, 0x80086748);
    return;
    // 0x8008674C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BC5B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC5B0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BC5B4: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800BC5B8: addiu       $t8, $t8, -0x58D0
    ctx->r24 = ADD32(ctx->r24, -0X58D0);
    // 0x800BC5BC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BC5C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BC5C4: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800BC5C8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BC5CC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BC5D0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BC5D4: lui         $t4, 0xFFFC
    ctx->r12 = S32(0XFFFC << 16);
    // 0x800BC5D8: ori         $t4, $t4, 0xFFFC
    ctx->r12 = ctx->r12 | 0XFFFC;
    // 0x800BC5DC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800BC5E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800BC5E4: lui         $t3, 0xF700
    ctx->r11 = S32(0XF700 << 16);
    // 0x800BC5E8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800BC5EC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800BC5F0: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800BC5F4: addu        $t2, $a1, $a3
    ctx->r10 = ADD32(ctx->r5, ctx->r7);
    // 0x800BC5F8: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800BC5FC: addiu       $t5, $t1, 0x8
    ctx->r13 = ADD32(ctx->r9, 0X8);
    // 0x800BC600: blez        $t2, L_800BC610
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BC604: sw          $t5, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r13;
            goto L_800BC610;
    }
    // 0x800BC604: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800BC608: b           L_800BC614
    // 0x800BC60C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800BC614;
    // 0x800BC60C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800BC610:
    // 0x800BC610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BC614:
    // 0x800BC614: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800BC618: andi        $t3, $v0, 0x3FF
    ctx->r11 = ctx->r2 & 0X3FF;
    // 0x800BC61C: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x800BC620: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x800BC624: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800BC628: blez        $v1, L_800BC638
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BC62C: lui         $at, 0xF600
        ctx->r1 = S32(0XF600 << 16);
            goto L_800BC638;
    }
    // 0x800BC62C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800BC630: b           L_800BC63C
    // 0x800BC634: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_800BC63C;
    // 0x800BC634: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_800BC638:
    // 0x800BC638: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BC63C:
    // 0x800BC63C: andi        $t7, $a0, 0x3FF
    ctx->r15 = ctx->r4 & 0X3FF;
    // 0x800BC640: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BC644: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800BC648: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800BC64C: blez        $a1, L_800BC65C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800BC650: sw          $t5, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r13;
            goto L_800BC65C;
    }
    // 0x800BC650: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800BC654: b           L_800BC660
    // 0x800BC658: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800BC660;
    // 0x800BC658: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800BC65C:
    // 0x800BC65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BC660:
    // 0x800BC660: blez        $a2, L_800BC670
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BC664: andi        $t8, $v0, 0x3FF
        ctx->r24 = ctx->r2 & 0X3FF;
            goto L_800BC670;
    }
    // 0x800BC664: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x800BC668: b           L_800BC674
    // 0x800BC66C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_800BC674;
    // 0x800BC66C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800BC670:
    // 0x800BC670: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BC674:
    // 0x800BC674: andi        $t6, $a0, 0x3FF
    ctx->r14 = ctx->r4 & 0X3FF;
    // 0x800BC678: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BC67C: sll         $t3, $t8, 14
    ctx->r11 = S32(ctx->r24 << 14);
    // 0x800BC680: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x800BC684: jr          $ra
    // 0x800BC688: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    return;
    // 0x800BC688: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800BC68C: nop

;}
RECOMP_FUNC void func_80800838_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800838: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080083C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800840: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800844: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800848: jal         0x801039E4
    // 0x8080084C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_801039E4(rdram, ctx);
        goto after_0;
    // 0x8080084C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800850: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800854: jal         0x800B2768
    // 0x80800858: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2768(rdram, ctx);
        goto after_1;
    // 0x80800858: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080085C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800864: jal         0x80103CB8
    // 0x80800868: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80103CB8(rdram, ctx);
        goto after_2;
    // 0x80800868: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x8080086C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800870: jal         0x800B2840
    // 0x80800874: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800B2840(rdram, ctx);
        goto after_3;
    // 0x80800874: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800878: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8080087C: jal         0x80800724
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800724_chlakemonster(rdram, ctx);
        goto after_4;
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800884: jal         0x801015D0
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_5;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080088C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800890: lbu         $t7, 0x17($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X17);
    // 0x80800894: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800898: sb          $t8, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r24;
    // 0x8080089C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x808008A0: jal         0x800AE0E8
    // 0x808008A4: lh          $a0, 0x10($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X10);
    func_800AE0E8(rdram, ctx);
        goto after_6;
    // 0x808008A4: lh          $a0, 0x10($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X10);
    after_6:
    // 0x808008A8: beql        $v0, $zero, L_808008D8
    if (ctx->r2 == 0) {
        // 0x808008AC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008D8;
    }
    goto skip_0;
    // 0x808008AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808008B0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x808008B4: jal         0x800AE080
    // 0x808008B8: lh          $a0, 0x10($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X10);
    func_800AE080(rdram, ctx);
        goto after_7;
    // 0x808008B8: lh          $a0, 0x10($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X10);
    after_7:
    // 0x808008BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808008C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808008C4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808008C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808008CC: jal         0x80087998
    // 0x808008D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    _dbmorph_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x808008D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x808008D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008D8:
    // 0x808008D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808008E0: jr          $ra
    // 0x808008E4: nop

    return;
    // 0x808008E4: nop

;}
RECOMP_FUNC void func_8001E170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E170: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001E174: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E178: addiu       $v0, $v0, -0x27A0
    ctx->r2 = ADD32(ctx->r2, -0X27A0);
    // 0x8001E17C: addiu       $a1, $a1, -0x27B0
    ctx->r5 = ADD32(ctx->r5, -0X27B0);
    // 0x8001E180: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8001E184:
    // 0x8001E184: lbu         $t6, 0x30($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X30);
    // 0x8001E188: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001E18C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001E190: sb          $t6, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r14;
    // 0x8001E194: lbu         $t7, 0x2D($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2D);
    // 0x8001E198: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x8001E19C: lbu         $t8, 0x2E($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2E);
    // 0x8001E1A0: sb          $t8, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r24;
    // 0x8001E1A4: lbu         $t9, 0x2F($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2F);
    // 0x8001E1A8: bne         $a1, $v0, L_8001E184
    if (ctx->r5 != ctx->r2) {
        // 0x8001E1AC: sb          $t9, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r25;
            goto L_8001E184;
    }
    // 0x8001E1AC: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x8001E1B0: jr          $ra
    // 0x8001E1B4: nop

    return;
    // 0x8001E1B4: nop

;}
RECOMP_FUNC void bawandglow_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E4: lw          $t7, 0x148($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X148);
    // 0x808000E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000F0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808000F4: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x808000F8: lw          $a1, 0x184($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X184);
    // 0x808000FC: jal         0x80086D30
    // 0x80800100: addiu       $a0, $a0, 0x53C0
    ctx->r4 = ADD32(ctx->r4, 0X53C0);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800100: addiu       $a0, $a0, 0x53C0
    ctx->r4 = ADD32(ctx->r4, 0X53C0);
    after_0:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_80800120_chdinotraindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800124: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800130: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800134: beq         $a1, $at, L_80800150
    if (ctx->r5 == ctx->r1) {
        // 0x80800138: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800150;
    }
    // 0x80800138: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080013C: addiu       $at, $zero, 0x9D
    ctx->r1 = ADD32(0, 0X9D);
    // 0x80800140: beq         $a1, $at, L_80800190
    if (ctx->r5 == ctx->r1) {
        // 0x80800144: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800190;
    }
    // 0x80800144: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800148: b           L_808001A0
    // 0x8080014C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_808001A0;
    // 0x8080014C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800150:
    // 0x80800150: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800154: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: lhu         $t7, 0x76($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X76);
    // 0x80800160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800164: addiu       $v0, $zero, 0x94A
    ctx->r2 = ADD32(0, 0X94A);
    // 0x80800168: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x8080016C: bne         $t8, $at, L_8080017C
    if (ctx->r24 != ctx->r1) {
        // 0x80800170: nop
    
            goto L_8080017C;
    }
    // 0x80800170: nop

    // 0x80800174: b           L_8080017C
    // 0x80800178: addiu       $v0, $zero, 0x949
    ctx->r2 = ADD32(0, 0X949);
        goto L_8080017C;
    // 0x80800178: addiu       $v0, $zero, 0x949
    ctx->r2 = ADD32(0, 0X949);
L_8080017C:
    // 0x8080017C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80800180: jal         0x80103140
    // 0x80800184: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800184: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800188: b           L_8080019C
    // 0x8080018C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_8080019C;
    // 0x8080018C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800190:
    // 0x80800190: jal         0x800FFAB0
    // 0x80800194: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800194: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800198: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_8080019C:
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808001A0:
    // 0x808001A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808001A4: jal         0x80086248
    // 0x808001A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808001A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B4: jr          $ra
    // 0x808001B8: nop

    return;
    // 0x808001B8: nop

;}
RECOMP_FUNC void bschokedie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808002A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(136, 0X2B0) << 16);
    // 0x808002A4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808002A8: jr          $ra
    // 0x808002AC: lw          $v0, 0x2B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(136, 0X2B0));
    return;
    // 0x808002AC: lw          $v0, 0x2B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(136, 0X2B0));
;}
RECOMP_FUNC void _chweldarbossfusebox_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086640: syscall     351
    recomp_syscall_handler(rdram, ctx, 0x80086640);
    return;
    // 0x80086644: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _gczoomboxdata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088420: syscall     682
    recomp_syscall_handler(rdram, ctx, 0x80088420);
    return;
    // 0x80088424: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chchuffycont_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C48: syscall     433
    recomp_syscall_handler(rdram, ctx, 0x80086C48);
    return;
    // 0x80086C4C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80021AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021AD0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80021AD4: bne         $a1, $zero, L_80021AE8
    if (ctx->r5 != 0) {
        // 0x80021AD8: nop
    
            goto L_80021AE8;
    }
    // 0x80021AD8: nop

    // 0x80021ADC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80021AE0: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x80021AE4: lbu         $a1, -0x15CB($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X15CB);
L_80021AE8:
    // 0x80021AE8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021AEC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80021AF0: sb          $zero, -0x15CD($at)
    MEM_B(-0X15CD, ctx->r1) = 0;
    // 0x80021AF4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021AF8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80021AFC: sb          $zero, -0x15CC($at)
    MEM_B(-0X15CC, ctx->r1) = 0;
    // 0x80021B00: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80021B04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80021B08: beq         $a2, $at, L_80021B3C
    if (ctx->r6 == ctx->r1) {
        // 0x80021B0C: nop
    
            goto L_80021B3C;
    }
    // 0x80021B0C: nop

    // 0x80021B10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80021B14: beq         $a2, $at, L_80021B64
    if (ctx->r6 == ctx->r1) {
        // 0x80021B18: nop
    
            goto L_80021B64;
    }
    // 0x80021B18: nop

    // 0x80021B1C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80021B20: beq         $a2, $at, L_80021B8C
    if (ctx->r6 == ctx->r1) {
        // 0x80021B24: nop
    
            goto L_80021B8C;
    }
    // 0x80021B24: nop

    // 0x80021B28: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80021B2C: beq         $a2, $at, L_80021BB4
    if (ctx->r6 == ctx->r1) {
        // 0x80021B30: nop
    
            goto L_80021BB4;
    }
    // 0x80021B30: nop

    // 0x80021B34: b           L_80021BEC
    // 0x80021B38: nop

        goto L_80021BEC;
    // 0x80021B38: nop

L_80021B3C:
    // 0x80021B3C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80021B40: lbu         $t6, -0x15D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X15D0);
    // 0x80021B44: beq         $t6, $zero, L_80021B5C
    if (ctx->r14 == 0) {
        // 0x80021B48: nop
    
            goto L_80021B5C;
    }
    // 0x80021B48: nop

    // 0x80021B4C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021B50: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80021B54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80021B58: sb          $t7, -0x15CC($at)
    MEM_B(-0X15CC, ctx->r1) = ctx->r15;
L_80021B5C:
    // 0x80021B5C: b           L_80021BEC
    // 0x80021B60: nop

        goto L_80021BEC;
    // 0x80021B60: nop

L_80021B64:
    // 0x80021B64: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80021B68: lbu         $t8, -0x15D0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X15D0);
    // 0x80021B6C: beq         $t8, $zero, L_80021B84
    if (ctx->r24 == 0) {
        // 0x80021B70: nop
    
            goto L_80021B84;
    }
    // 0x80021B70: nop

    // 0x80021B74: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021B78: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80021B7C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80021B80: sb          $t9, -0x15CD($at)
    MEM_B(-0X15CD, ctx->r1) = ctx->r25;
L_80021B84:
    // 0x80021B84: b           L_80021BEC
    // 0x80021B88: nop

        goto L_80021BEC;
    // 0x80021B88: nop

L_80021B8C:
    // 0x80021B8C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80021B90: lbu         $t0, -0x15CF($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X15CF);
    // 0x80021B94: bne         $t0, $zero, L_80021BAC
    if (ctx->r8 != 0) {
        // 0x80021B98: nop
    
            goto L_80021BAC;
    }
    // 0x80021B98: nop

    // 0x80021B9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021BA0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80021BA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80021BA8: sb          $t1, -0x15CD($at)
    MEM_B(-0X15CD, ctx->r1) = ctx->r9;
L_80021BAC:
    // 0x80021BAC: b           L_80021BEC
    // 0x80021BB0: nop

        goto L_80021BEC;
    // 0x80021BB0: nop

L_80021BB4:
    // 0x80021BB4: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80021BB8: lbu         $t2, -0x15CF($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X15CF);
    // 0x80021BBC: bne         $t2, $zero, L_80021BE4
    if (ctx->r10 != 0) {
        // 0x80021BC0: nop
    
            goto L_80021BE4;
    }
    // 0x80021BC0: nop

    // 0x80021BC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021BC8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80021BCC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80021BD0: sb          $t3, -0x15CD($at)
    MEM_B(-0X15CD, ctx->r1) = ctx->r11;
    // 0x80021BD4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021BD8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80021BDC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80021BE0: sb          $t4, -0x15CC($at)
    MEM_B(-0X15CC, ctx->r1) = ctx->r12;
L_80021BE4:
    // 0x80021BE4: b           L_80021BEC
    // 0x80021BE8: nop

        goto L_80021BEC;
    // 0x80021BE8: nop

L_80021BEC:
    // 0x80021BEC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80021BF0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80021BF4: sb          $a1, -0x15CB($at)
    MEM_B(-0X15CB, ctx->r1) = ctx->r5;
    // 0x80021BF8: b           L_80021C00
    // 0x80021BFC: nop

        goto L_80021C00;
    // 0x80021BFC: nop

L_80021C00:
    // 0x80021C00: jr          $ra
    // 0x80021C04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80021C04: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80021C08: nop

    // 0x80021C0C: nop

;}
RECOMP_FUNC void func_80800168_chlagoonufoext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080016C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800170: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800174: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800178: jal         0x80089D48
    // 0x8080017C: lbu         $a0, 0x34($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X34);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080017C: lbu         $a0, 0x34($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X34);
    after_0:
    // 0x80800180: sb          $v0, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r2;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x80100094
    // 0x8080018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: jal         0x8008A2B0
    // 0x80800198: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800198: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8080019C: beq         $v0, $zero, L_808001B8
    if (ctx->r2 == 0) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B8;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x80100094
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x8008A2C0
    // 0x808001B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808001B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
L_808001B8:
    // 0x808001B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_808000B0_chtimetable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1592, 0X730) << 16);
    // 0x808000B4: lw          $t6, 0x730($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(1592, 0X730));
    // 0x808000B8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1592, 0X744) << 16);
    // 0x808000BC: bne         $a0, $t6, L_808000CC
    if (ctx->r4 != ctx->r14) {
        // 0x808000C0: nop
    
            goto L_808000CC;
    }
    // 0x808000C0: nop

    // 0x808000C4: jr          $ra
    // 0x808000C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808000C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000CC:
    // 0x808000CC: lw          $t7, 0x744($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(1592, 0X744));
    // 0x808000D0: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1592, 0X758) << 16);
    // 0x808000D4: bne         $a0, $t7, L_808000E4
    if (ctx->r4 != ctx->r15) {
        // 0x808000D8: nop
    
            goto L_808000E4;
    }
    // 0x808000D8: nop

    // 0x808000DC: jr          $ra
    // 0x808000E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808000E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000E4:
    // 0x808000E4: lw          $t8, 0x758($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(1592, 0X758));
    // 0x808000E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1592, 0X76C) << 16);
    // 0x808000EC: addiu       $v0, $v0, 0x76C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1592, 0X76C));
    // 0x808000F0: bne         $a0, $t8, L_80800100
    if (ctx->r4 != ctx->r24) {
        // 0x808000F4: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_80800100;
    }
    // 0x808000F4: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x808000F8: jr          $ra
    // 0x808000FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x808000FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800100:
    // 0x80800100: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
L_80800104:
    // 0x80800104: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800108: bnel        $a0, $t9, L_8080011C
    if (ctx->r4 != ctx->r25) {
        // 0x8080010C: lw          $t0, 0x14($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X14);
            goto L_8080011C;
    }
    goto skip_0;
    // 0x8080010C: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    skip_0:
    // 0x80800110: jr          $ra
    // 0x80800114: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800114: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800118: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
L_8080011C:
    // 0x8080011C: bnel        $a0, $t0, L_80800130
    if (ctx->r4 != ctx->r8) {
        // 0x80800120: lw          $t1, 0x28($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X28);
            goto L_80800130;
    }
    goto skip_1;
    // 0x80800120: lw          $t1, 0x28($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X28);
    skip_1:
    // 0x80800124: jr          $ra
    // 0x80800128: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x80800128: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8080012C: lw          $t1, 0x28($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X28);
L_80800130:
    // 0x80800130: bnel        $a0, $t1, L_80800144
    if (ctx->r4 != ctx->r9) {
        // 0x80800134: lw          $t2, 0x3C($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X3C);
            goto L_80800144;
    }
    goto skip_2;
    // 0x80800134: lw          $t2, 0x3C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X3C);
    skip_2:
    // 0x80800138: jr          $ra
    // 0x8080013C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x8080013C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80800140: lw          $t2, 0x3C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X3C);
L_80800144:
    // 0x80800144: bnel        $a0, $t2, L_80800158
    if (ctx->r4 != ctx->r10) {
        // 0x80800148: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800158;
    }
    goto skip_3;
    // 0x80800148: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x8080014C: jr          $ra
    // 0x80800150: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x80800150: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x80800154: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80800158:
    // 0x80800158: bne         $v1, $a1, L_80800104
    if (ctx->r3 != ctx->r5) {
        // 0x8080015C: addiu       $v0, $v0, 0x50
        ctx->r2 = ADD32(ctx->r2, 0X50);
            goto L_80800104;
    }
    // 0x8080015C: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80800160: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void sueggmove_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080008C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800090: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800094: jal         0x80106790
    // 0x80800098: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800098: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080009C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: sw          $t6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r14;
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_800BFC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFC34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BFC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BFC3C: jal         0x800D674C
    // 0x800BFC40: nop

    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x800BFC40: nop

    after_0:
    // 0x800BFC44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFC48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BFC4C: jr          $ra
    // 0x800BFC50: nop

    return;
    // 0x800BFC50: nop

;}
RECOMP_FUNC void ncpod_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808003EC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808003F0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808003F4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808003F8: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x808003FC: jal         0x808002E8
    // 0x80800400: lw          $a1, 0xC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XC);
    func_808002E8_ncpod(rdram, ctx);
        goto after_0;
    // 0x80800400: lw          $a1, 0xC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XC);
    after_0:
    // 0x80800404: beq         $v0, $zero, L_8080049C
    if (ctx->r2 == 0) {
        // 0x80800408: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080049C;
    }
    // 0x80800408: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080040C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80800410: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800414: lhu         $t7, 0x18($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X18);
    // 0x80800418: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8080041C: beq         $t8, $zero, L_808004BC
    if (ctx->r24 == 0) {
        // 0x80800420: nop
    
            goto L_808004BC;
    }
    // 0x80800420: nop

    // 0x80800424: jal         0x80101074
    // 0x80800428: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80101074(rdram, ctx);
        goto after_1;
    // 0x80800428: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8080042C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80800430: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800434: jal         0x8010114C
    // 0x80800438: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_8010114C(rdram, ctx);
        goto after_2;
    // 0x80800438: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x8080043C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800440: beq         $v0, $at, L_8080045C
    if (ctx->r2 == ctx->r1) {
        // 0x80800444: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080045C;
    }
    // 0x80800444: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800448: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080044C: beq         $v0, $at, L_80800464
    if (ctx->r2 == ctx->r1) {
        // 0x80800450: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800464;
    }
    // 0x80800450: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800454: b           L_8080046C
    // 0x80800458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
        goto L_8080046C;
    // 0x80800458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
L_8080045C:
    // 0x8080045C: b           L_808004BC
    // 0x80800460: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808004BC;
    // 0x80800460: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800464:
    // 0x80800464: b           L_808004BC
    // 0x80800468: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808004BC;
    // 0x80800468: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8080046C:
    // 0x8080046C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80800470: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800474: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80800478: jal         0x80800314
    // 0x8080047C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80800314_ncpod(rdram, ctx);
        goto after_3;
    // 0x8080047C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x80800480: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800484: bne         $v0, $at, L_80800494
    if (ctx->r2 != ctx->r1) {
        // 0x80800488: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800494;
    }
    // 0x80800488: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080048C: b           L_808004BC
    // 0x80800490: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808004BC;
    // 0x80800490: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800494:
    // 0x80800494: b           L_808004BC
    // 0x80800498: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808004BC;
    // 0x80800498: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8080049C:
    // 0x8080049C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x808004A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004A4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x808004A8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808004AC: jal         0x80800314
    // 0x808004B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80800314_ncpod(rdram, ctx);
        goto after_4;
    // 0x808004B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_4:
    // 0x808004B4: b           L_808004C0
    // 0x808004B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004C0;
    // 0x808004B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004BC:
    // 0x808004BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004C0:
    // 0x808004C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004C8: jr          $ra
    // 0x808004CC: nop

    return;
    // 0x808004CC: nop

;}
RECOMP_FUNC void func_80800450_changlerbossbubble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800458: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080045C: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x80800460: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80800464: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80800468: jal         0x800F5BF0
    // 0x8080046C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F5BF0(rdram, ctx);
        goto after_0;
    // 0x8080046C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80800470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800478: jr          $ra
    // 0x8080047C: nop

    return;
    // 0x8080047C: nop

;}
RECOMP_FUNC void _badust_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A10: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x80084A10);
    return;
    // 0x80084A14: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void subaddiefade_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800400: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x80800404: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800408: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080040C: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800410: bgez        $t8, L_80800438
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800414: nop
    
            goto L_80800438;
    }
    // 0x80800414: nop

    // 0x80800418: jal         0x80800450
    // 0x8080041C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80800450_subaddiefade(rdram, ctx);
        goto after_0;
    // 0x8080041C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800420: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800424: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800428: jal         0x800F2F20
    // 0x8080042C: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    func_800F2F20(rdram, ctx);
        goto after_1;
    // 0x8080042C: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    after_1:
    // 0x80800430: b           L_80800444
    // 0x80800434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800444;
    // 0x80800434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800438:
    // 0x80800438: jal         0x800F2F3C
    // 0x8080043C: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    func_800F2F3C(rdram, ctx);
        goto after_2;
    // 0x8080043C: addiu       $a0, $a2, 0x98
    ctx->r4 = ADD32(ctx->r6, 0X98);
    after_2:
    // 0x80800440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800444:
    // 0x80800444: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800448: jr          $ra
    // 0x8080044C: nop

    return;
    // 0x8080044C: nop

;}
RECOMP_FUNC void func_80800140_chquicksandbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800140_chquicksandbaddy");
    tooie_enemy_strafe(rdram, ctx);
    // 0x80800140: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80800144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800148: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080014C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800154: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800158: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8080015C: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x80800160: beq         $at, $zero, L_80800B58
    if (ctx->r1 == 0) {
        // 0x80800164: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800B58;
    }
    // 0x80800164: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800168: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080016C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1896, 0X1264) << 16);
    // 0x80800170: addu        $at, $at, $t7
    gpr jr_addend_80800178 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800174: lw          $t7, 0x1264($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1896, 0X1264));
    // 0x80800178: jr          $t7
    // 0x8080017C: nop

    switch (jr_addend_80800178 >> 2) {
        case 0: goto L_80800180; break;
        case 1: goto L_80800364; break;
        case 2: goto L_808004D8; break;
        case 3: goto L_808007DC; break;
        case 4: goto L_8080095C; break;
        case 5: goto L_80800AD8; break;
        case 6: goto L_80800B18; break;
        default: switch_error(__func__, 0x80800178, 0x80801264);
    }
    // 0x8080017C: nop

L_80800180:
    // 0x80800180: jal         0x8010D254
    // 0x80800184: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800184: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    after_0:
    // 0x80800188: jal         0x800D90A4
    // 0x8080018C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x8080018C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_1:
    // 0x80800190: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x80800194: nop
    
            goto L_808001BC;
    }
    // 0x80800194: nop

    // 0x80800198: jal         0x800E3980
    // 0x8080019C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    func_800E3980(rdram, ctx);
        goto after_2;
    // 0x8080019C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    after_2:
    // 0x808001A0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001A4: jal         0x800F1DF4
    // 0x808001A8: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x808001A8: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    after_3:
    // 0x808001AC: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: jal         0x80102424
    // 0x808001B8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808001B8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
L_808001BC:
    // 0x808001BC: jal         0x80800DBC
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DBC_chquicksandbaddy(rdram, ctx);
        goto after_5;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001C4: beq         $v0, $zero, L_808002B0
    if (ctx->r2 == 0) {
        // 0x808001C8: lwc1        $f16, 0xB8($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
            goto L_808002B0;
    }
    // 0x808001C8: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x808001CC: jal         0x800F54E4
    // 0x808001D0: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808001D0: nop

    after_6:
    // 0x808001D4: jal         0x800F6AA4
    // 0x808001D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6AA4(rdram, ctx);
        goto after_7;
    // 0x808001D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808001DC: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001E0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808001EC;
    }
    // 0x808001E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808001E4: b           L_808001F0
    // 0x808001E8: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
        goto L_808001F0;
    // 0x808001E8: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
L_808001EC:
    // 0x808001EC: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
L_808001F0:
    // 0x808001F0: jal         0x800F54E4
    // 0x808001F4: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x808001F4: nop

    after_8:
    // 0x808001F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001FC: jal         0x800F7B9C
    // 0x80800200: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    func_800F7B9C(rdram, ctx);
        goto after_9;
    // 0x80800200: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_9:
    // 0x80800204: beq         $v0, $zero, L_80800354
    if (ctx->r2 == 0) {
        // 0x80800208: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800354;
    }
    // 0x80800208: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080020C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800210: jal         0x800EE7F8
    // 0x80800214: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80800214: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    after_10:
    // 0x80800218: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1896, 0X12E0) << 16);
    // 0x8080021C: addiu       $a2, $a2, 0x12E0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1896, 0X12E0));
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x80089D18
    // 0x80800228: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800228: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_11:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x8008A4B0
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800238: jal         0x800F54E4
    // 0x8080023C: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x8080023C: nop

    after_13:
    // 0x80800240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800244: jal         0x800F5A00
    // 0x80800248: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800F5A00(rdram, ctx);
        goto after_14;
    // 0x80800248: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_14:
    // 0x8080024C: jal         0x800F54E4
    // 0x80800250: nop

    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x80800250: nop

    after_15:
    // 0x80800254: jal         0x800F5628
    // 0x80800258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5628(rdram, ctx);
        goto after_16;
    // 0x80800258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x8080025C: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800260: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800264: jal         0x8008FC00
    // 0x80800268: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    func_8008FC00(rdram, ctx);
        goto after_17;
    // 0x80800268: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_17:
    // 0x8080026C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800270: bne         $v0, $at, L_80800298
    if (ctx->r2 != ctx->r1) {
        // 0x80800274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800298;
    }
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x80102424
    // 0x80800280: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x80800280: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_18:
    // 0x80800284: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800288: nop

    // 0x8080028C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800290: b           L_80800354
    // 0x80800294: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
        goto L_80800354;
    // 0x80800294: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_80800298:
    // 0x80800298: jal         0x80102424
    // 0x8080029C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_19;
    // 0x8080029C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_19:
    // 0x808002A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002A8: b           L_80800354
    // 0x808002AC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80800354;
    // 0x808002AC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_808002B0:
    // 0x808002B0: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808002B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1896, 0X1284) << 16);
    // 0x808002B8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x808002BC: nop

    // 0x808002C0: bc1f        L_8080034C
    if (!c1cs) {
        // 0x808002C4: nop
    
            goto L_8080034C;
    }
    // 0x808002C4: nop

    // 0x808002C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1896, 0X1280) << 16);
    // 0x808002CC: lwc1        $f18, 0x1280($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1896, 0X1280));
    // 0x808002D0: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x808002D4: jal         0x800D90A4
    // 0x808002D8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    func_800D90A4(rdram, ctx);
        goto after_20;
    // 0x808002D8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_20:
    // 0x808002DC: beq         $v0, $zero, L_80800354
    if (ctx->r2 == 0) {
        // 0x808002E0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800354;
    }
    // 0x808002E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002E8: jal         0x800F54E4
    // 0x808002EC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_800F54E4(rdram, ctx);
        goto after_21;
    // 0x808002EC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_21:
    // 0x808002F0: jal         0x800F56AC
    // 0x808002F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F56AC(rdram, ctx);
        goto after_22;
    // 0x808002F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x808002F8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x808002FC: beql        $v0, $at, L_80800358
    if (ctx->r2 == ctx->r1) {
        // 0x80800300: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800358;
    }
    goto skip_0;
    // 0x80800300: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800304: jal         0x800F54E4
    // 0x80800308: nop

    func_800F54E4(rdram, ctx);
        goto after_23;
    // 0x80800308: nop

    after_23:
    // 0x8080030C: jal         0x800F6C5C
    // 0x80800310: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_24;
    // 0x80800310: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_24:
    // 0x80800314: beql        $v0, $zero, L_80800358
    if (ctx->r2 == 0) {
        // 0x80800318: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800358;
    }
    goto skip_1;
    // 0x80800318: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x8080031C: jal         0x800F54E4
    // 0x80800320: nop

    func_800F54E4(rdram, ctx);
        goto after_25;
    // 0x80800320: nop

    after_25:
    // 0x80800324: jal         0x800F5628
    // 0x80800328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5628(rdram, ctx);
        goto after_26;
    // 0x80800328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x8080032C: swc1        $f0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f0.u32l;
    // 0x80800330: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800334: jal         0x800EE7F8
    // 0x80800338: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    func_800EE7F8(rdram, ctx);
        goto after_27;
    // 0x80800338: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    after_27:
    // 0x8080033C: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800340: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80800344: b           L_80800354
    // 0x80800348: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_80800354;
    // 0x80800348: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_8080034C:
    // 0x8080034C: lwc1        $f6, 0x1284($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1896, 0X1284));
    // 0x80800350: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800354:
    // 0x80800354: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800358:
    // 0x80800358: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x8080035C: b           L_80800B58
    // 0x80800360: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80800B58;
    // 0x80800360: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80800364:
    // 0x80800364: jal         0x800D90A4
    // 0x80800368: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_28;
    // 0x80800368: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_28:
    // 0x8080036C: beq         $v0, $zero, L_808004C8
    if (ctx->r2 == 0) {
        // 0x80800370: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004C8;
    }
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800378: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1896, 0X12F0) << 16);
    // 0x8080037C: addiu       $a2, $a2, 0x12F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1896, 0X12F0));
    // 0x80800380: jal         0x80089D18
    // 0x80800384: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_29;
    // 0x80800384: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_29:
    // 0x80800388: jal         0x800EA05C
    // 0x8080038C: nop

    func_800EA05C(rdram, ctx);
        goto after_30;
    // 0x8080038C: nop

    after_30:
    // 0x80800390: addiu       $at, $zero, 0xB9
    ctx->r1 = ADD32(0, 0XB9);
    // 0x80800394: beql        $v0, $at, L_808003B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800398: addiu       $a2, $s0, 0x18
        ctx->r6 = ADD32(ctx->r16, 0X18);
            goto L_808003B0;
    }
    goto skip_2;
    // 0x80800398: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    skip_2:
    // 0x8080039C: jal         0x800EA05C
    // 0x808003A0: nop

    func_800EA05C(rdram, ctx);
        goto after_31;
    // 0x808003A0: nop

    after_31:
    // 0x808003A4: addiu       $at, $zero, 0xC4
    ctx->r1 = ADD32(0, 0XC4);
    // 0x808003A8: bne         $v0, $at, L_80800404
    if (ctx->r2 != ctx->r1) {
        // 0x808003AC: addiu       $a2, $s0, 0x18
        ctx->r6 = ADD32(ctx->r16, 0X18);
            goto L_80800404;
    }
    // 0x808003AC: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
L_808003B0:
    // 0x808003B0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: jal         0x80800CFC
    // 0x808003BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800CFC_chquicksandbaddy(rdram, ctx);
        goto after_32;
    // 0x808003BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_32:
    // 0x808003C0: beql        $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808003C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800408;
    }
    goto skip_3;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808003C8: jal         0x800F54E4
    // 0x808003CC: nop

    func_800F54E4(rdram, ctx);
        goto after_33;
    // 0x808003CC: nop

    after_33:
    // 0x808003D0: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x808003D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003D8: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x808003DC: beq         $t5, $zero, L_808003EC
    if (ctx->r13 == 0) {
        // 0x808003E0: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_808003EC;
    }
    // 0x808003E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808003E4: b           L_808003EC
    // 0x808003E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_808003EC;
    // 0x808003E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_808003EC:
    // 0x808003EC: jal         0x800F7D90
    // 0x808003F0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800F7D90(rdram, ctx);
        goto after_34;
    // 0x808003F0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_34:
    // 0x808003F4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808003F8: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x808003FC: b           L_80800490
    // 0x80800400: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
        goto L_80800490;
    // 0x80800400: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_80800404:
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800408:
    // 0x80800408: jal         0x80801154
    // 0x8080040C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    func_80801154_chquicksandbaddy(rdram, ctx);
        goto after_35;
    // 0x8080040C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_35:
    // 0x80800410: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800414: beq         $v0, $at, L_80800458
    if (ctx->r2 == ctx->r1) {
        // 0x80800418: nop
    
            goto L_80800458;
    }
    // 0x80800418: nop

    // 0x8080041C: jal         0x800F54E4
    // 0x80800420: nop

    func_800F54E4(rdram, ctx);
        goto after_36;
    // 0x80800420: nop

    after_36:
    // 0x80800424: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80800428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080042C: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x80800430: beq         $t9, $zero, L_80800440
    if (ctx->r25 == 0) {
        // 0x80800434: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80800440;
    }
    // 0x80800434: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800438: b           L_80800440
    // 0x8080043C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80800440;
    // 0x8080043C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80800440:
    // 0x80800440: jal         0x800F7D90
    // 0x80800444: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    func_800F7D90(rdram, ctx);
        goto after_37;
    // 0x80800444: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    after_37:
    // 0x80800448: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x8080044C: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80800450: b           L_80800490
    // 0x80800454: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_80800490;
    // 0x80800454: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_80800458:
    // 0x80800458: jal         0x800F54E4
    // 0x8080045C: nop

    func_800F54E4(rdram, ctx);
        goto after_38;
    // 0x8080045C: nop

    after_38:
    // 0x80800460: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x80800464: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800468: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x8080046C: beq         $t3, $zero, L_8080047C
    if (ctx->r11 == 0) {
        // 0x80800470: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8080047C;
    }
    // 0x80800470: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800474: b           L_8080047C
    // 0x80800478: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8080047C;
    // 0x80800478: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8080047C:
    // 0x8080047C: jal         0x800F7C58
    // 0x80800480: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_800F7C58(rdram, ctx);
        goto after_39;
    // 0x80800480: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_39:
    // 0x80800484: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800488: andi        $t5, $t4, 0xFFF7
    ctx->r13 = ctx->r12 & 0XFFF7;
    // 0x8080048C: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80800490:
    // 0x80800490: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    // 0x80800494: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x80800498: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080049C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808004A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004A4: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x808004A8: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x808004AC: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
    // 0x808004B0: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808004BC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x808004C0: jal         0x80102424
    // 0x808004C4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_80102424(rdram, ctx);
        goto after_40;
    // 0x808004C4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_40:
L_808004C8:
    // 0x808004C8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808004CC: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x808004D0: b           L_80800B58
    // 0x808004D4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80800B58;
    // 0x808004D4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_808004D8:
    // 0x808004D8: jal         0x800D90A4
    // 0x808004DC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_41;
    // 0x808004DC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_41:
    // 0x808004E0: beql        $v0, $zero, L_8080059C
    if (ctx->r2 == 0) {
        // 0x808004E4: lw          $t0, 0x74($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X74);
            goto L_8080059C;
    }
    goto skip_4;
    // 0x808004E4: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    skip_4:
    // 0x808004E8: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x808004EC: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x808004F0: bgez        $t3, L_80800514
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808004F4: nop
    
            goto L_80800514;
    }
    // 0x808004F4: nop

    // 0x808004F8: jal         0x800F54E4
    // 0x808004FC: nop

    func_800F54E4(rdram, ctx);
        goto after_42;
    // 0x808004FC: nop

    after_42:
    // 0x80800500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800504: jal         0x800F5A00
    // 0x80800508: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    func_800F5A00(rdram, ctx);
        goto after_43;
    // 0x80800508: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_43:
    // 0x8080050C: b           L_80800520
    // 0x80800510: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_80800520;
    // 0x80800510: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800514:
    // 0x80800514: jal         0x800E3980
    // 0x80800518: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    func_800E3980(rdram, ctx);
        goto after_44;
    // 0x80800518: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    after_44:
    // 0x8080051C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800520:
    // 0x80800520: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800524: jal         0x800F1DF4
    // 0x80800528: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    func_800F1DF4(rdram, ctx);
        goto after_45;
    // 0x80800528: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_45:
    // 0x8080052C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: jal         0x80102424
    // 0x80800538: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_46;
    // 0x80800538: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_46:
    // 0x8080053C: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80800540: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80800544: bgezl       $t6, L_80800564
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800548: lw          $v0, 0x70($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X70);
            goto L_80800564;
    }
    goto skip_5;
    // 0x80800548: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    skip_5:
    // 0x8080054C: lbu         $t7, 0x79($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X79);
    // 0x80800550: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x80800554: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x80800558: beq         $at, $zero, L_808007C4
    if (ctx->r1 == 0) {
        // 0x8080055C: nop
    
            goto L_808007C4;
    }
    // 0x8080055C: nop

    // 0x80800560: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
L_80800564:
    // 0x80800564: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80800568: srl         $t9, $a1, 26
    ctx->r25 = S32(U32(ctx->r5) >> 26);
    // 0x8080056C: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80800570: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80800574: jal         0x800CC63C
    // 0x80800578: addiu       $a1, $t9, -0x1
    ctx->r5 = ADD32(ctx->r25, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_47;
    // 0x80800578: addiu       $a1, $t9, -0x1
    ctx->r5 = ADD32(ctx->r25, -0X1);
    after_47:
    // 0x8080057C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800580: jal         0x800EE7F8
    // 0x80800584: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_48;
    // 0x80800584: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_48:
    // 0x80800588: jal         0x80800CC0
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chquicksandbaddy(rdram, ctx);
        goto after_49;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80800590: b           L_808007C4
    // 0x80800594: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
        goto L_808007C4;
    // 0x80800594: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80800598: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
L_8080059C:
    // 0x8080059C: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x808005A0: bgezl       $t2, L_808005C0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808005A4: lbu         $t6, 0x74($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X74);
            goto L_808005C0;
    }
    goto skip_6;
    // 0x808005A4: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    skip_6:
    // 0x808005A8: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x808005AC: srl         $t4, $t3, 4
    ctx->r12 = S32(U32(ctx->r11) >> 4);
    // 0x808005B0: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x808005B4: beq         $at, $zero, L_808007C4
    if (ctx->r1 == 0) {
        // 0x808005B8: nop
    
            goto L_808007C4;
    }
    // 0x808005B8: nop

    // 0x808005BC: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
L_808005C0:
    // 0x808005C0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808005C4: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x808005C8: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
    // 0x808005CC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x808005D0: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
L_808005D4:
    // 0x808005D4: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x808005D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808005DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808005E0: srl         $t9, $t8, 4
    ctx->r25 = S32(U32(ctx->r24) >> 4);
    // 0x808005E4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x808005E8: bgez        $t9, L_808005FC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808005EC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_808005FC;
    }
    // 0x808005EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808005F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005F4: nop

    // 0x808005F8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_808005FC:
    // 0x808005FC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800600: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800604: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80800608: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8080060C: jal         0x800EE7F8
    // 0x80800610: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_50;
    // 0x80800610: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    after_50:
    // 0x80800614: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800618: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080061C: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800624: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800628: jal         0x80103EAC
    // 0x8080062C: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    func_80103EAC(rdram, ctx);
        goto after_51;
    // 0x8080062C: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    after_51:
    // 0x80800630: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800634: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80800638: jal         0x800EEB9C
    // 0x8080063C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800EEB9C(rdram, ctx);
        goto after_52;
    // 0x8080063C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_52:
    // 0x80800640: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80800644: jal         0x800EF04C
    // 0x80800648: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    func_800EF04C(rdram, ctx);
        goto after_53;
    // 0x80800648: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    after_53:
    // 0x8080064C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80800650: jal         0x800EE7F8
    // 0x80800654: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_800EE7F8(rdram, ctx);
        goto after_54;
    // 0x80800654: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_54:
    // 0x80800658: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8080065C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80800660: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80800664: jal         0x800C6A7C
    // 0x80800668: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6A7C(rdram, ctx);
        goto after_55;
    // 0x80800668: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_55:
    // 0x8080066C: beq         $v0, $zero, L_808006CC
    if (ctx->r2 == 0) {
        // 0x80800670: addiu       $a0, $sp, 0x64
        ctx->r4 = ADD32(ctx->r29, 0X64);
            goto L_808006CC;
    }
    // 0x80800670: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80800674: jal         0x800EF334
    // 0x80800678: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_800EF334(rdram, ctx);
        goto after_56;
    // 0x80800678: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_56:
    // 0x8080067C: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80800680: jal         0x800EF04C
    // 0x80800684: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_800EF04C(rdram, ctx);
        goto after_57;
    // 0x80800684: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_57:
    // 0x80800688: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8080068C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800690: jal         0x800EFB24
    // 0x80800694: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_800EFB24(rdram, ctx);
        goto after_58;
    // 0x80800694: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_58:
    // 0x80800698: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080069C: jal         0x800EF04C
    // 0x808006A0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800EF04C(rdram, ctx);
        goto after_59;
    // 0x808006A0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_59:
    // 0x808006A4: jal         0x80800CC0
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chquicksandbaddy(rdram, ctx);
        goto after_60;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x808006AC: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x808006B0: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x808006B4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x808006B8: andi        $t2, $t1, 0xFFBF
    ctx->r10 = ctx->r9 & 0XFFBF;
    // 0x808006BC: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x808006C0: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
    // 0x808006C4: b           L_808007C4
    // 0x808006C8: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
        goto L_808007C4;
    // 0x808006C8: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
L_808006CC:
    // 0x808006CC: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x808006D0: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x808006D4: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x808006D8: srl         $t5, $a2, 26
    ctx->r13 = S32(U32(ctx->r6) >> 26);
    // 0x808006DC: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x808006E0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x808006E4: jal         0x800CC338
    // 0x808006E8: addiu       $a2, $t5, -0x1
    ctx->r6 = ADD32(ctx->r13, -0X1);
    func_800CC338(rdram, ctx);
        goto after_61;
    // 0x808006E8: addiu       $a2, $t5, -0x1
    ctx->r6 = ADD32(ctx->r13, -0X1);
    after_61:
    // 0x808006EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808006F0: bnel        $v0, $at, L_80800774
    if (ctx->r2 != ctx->r1) {
        // 0x808006F4: lbu         $v0, 0x79($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X79);
            goto L_80800774;
    }
    goto skip_7;
    // 0x808006F4: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    skip_7:
    // 0x808006F8: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x808006FC: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80800700: srl         $t6, $a1, 26
    ctx->r14 = S32(U32(ctx->r5) >> 26);
    // 0x80800704: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80800708: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8080070C: jal         0x800CC63C
    // 0x80800710: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_62;
    // 0x80800710: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    after_62:
    // 0x80800714: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800718: jal         0x800F1DF4
    // 0x8080071C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_63;
    // 0x8080071C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_63:
    // 0x80800720: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800724: jal         0x80103EAC
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_64;
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x8080072C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800730: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80800734: jal         0x800EEB9C
    // 0x80800738: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EEB9C(rdram, ctx);
        goto after_65;
    // 0x80800738: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_65:
    // 0x8080073C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800740: jal         0x800EF04C
    // 0x80800744: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EF04C(rdram, ctx);
        goto after_66;
    // 0x80800744: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_66:
    // 0x80800748: jal         0x80800CC0
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chquicksandbaddy(rdram, ctx);
        goto after_67;
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x80800750: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x80800754: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x80800758: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8080075C: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x80800760: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80800764: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    // 0x80800768: b           L_808007C4
    // 0x8080076C: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
        goto L_808007C4;
    // 0x8080076C: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
    // 0x80800770: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
L_80800774:
    // 0x80800774: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80800778: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080077C: srl         $t1, $v0, 4
    ctx->r9 = S32(U32(ctx->r2) >> 4);
    // 0x80800780: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80800784: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80800788: andi        $t5, $v0, 0xFF0F
    ctx->r13 = ctx->r2 & 0XFF0F;
    // 0x8080078C: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80800790: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
    // 0x80800794: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800798: srl         $t1, $t8, 31
    ctx->r9 = S32(U32(ctx->r24) >> 31);
    // 0x8080079C: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x808007A0: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
    // 0x808007A4: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x808007A8: andi        $t5, $t4, 0xFFBF
    ctx->r13 = ctx->r12 & 0XFFBF;
    // 0x808007AC: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x808007B0: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
    // 0x808007B4: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x808007B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808007BC: bne         $v0, $at, L_808005D4
    if (ctx->r2 != ctx->r1) {
        // 0x808007C0: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_808005D4;
    }
    // 0x808007C0: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
L_808007C4:
    // 0x808007C4: jal         0x80103014
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_68;
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x808007CC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808007D0: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x808007D4: b           L_80800B58
    // 0x808007D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80800B58;
    // 0x808007D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_808007DC:
    // 0x808007DC: jal         0x800F54E4
    // 0x808007E0: nop

    func_800F54E4(rdram, ctx);
        goto after_69;
    // 0x808007E0: nop

    after_69:
    // 0x808007E4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808007E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007EC: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808007F0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808007F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007F8: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808007FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800800: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800804: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080080C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800810: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800814: jal         0x800F4F34
    // 0x80800818: nop

    func_800F4F34(rdram, ctx);
        goto after_70;
    // 0x80800818: nop

    after_70:
    // 0x8080081C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1896, 0X1300) << 16);
    // 0x80800820: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1896, 0X1310) << 16);
    // 0x80800824: addiu       $a3, $a3, 0x1310
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1896, 0X1310));
    // 0x80800828: addiu       $a2, $a2, 0x1300
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1896, 0X1300));
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800830: jal         0x80089D28
    // 0x80800834: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_71;
    // 0x80800834: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_71:
    // 0x80800838: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x8080083C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800840: jal         0x80101E14
    // 0x80800844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_72;
    // 0x80800844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_72:
    // 0x80800848: beq         $v0, $zero, L_80800870
    if (ctx->r2 == 0) {
        // 0x8080084C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800870;
    }
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800850: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800854: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x80800858: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x8080085C: ori         $a0, $a0, 0x5DB2
    ctx->r4 = ctx->r4 | 0X5DB2;
    // 0x80800860: jal         0x800C4140
    // 0x80800864: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800C4140(rdram, ctx);
        goto after_73;
    // 0x80800864: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_73:
    // 0x80800868: b           L_80800900
    // 0x8080086C: nop

        goto L_80800900;
    // 0x8080086C: nop

L_80800870:
    // 0x80800870: lui         $a1, 0x3F30
    ctx->r5 = S32(0X3F30 << 16);
    // 0x80800874: jal         0x80101E14
    // 0x80800878: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    func_80101E14(rdram, ctx);
        goto after_74;
    // 0x80800878: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    after_74:
    // 0x8080087C: beq         $v0, $zero, L_808008A4
    if (ctx->r2 == 0) {
        // 0x80800880: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A4;
    }
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800884: lui         $a0, 0x797B
    ctx->r4 = S32(0X797B << 16);
    // 0x80800888: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x8080088C: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x80800890: ori         $a0, $a0, 0x5DB2
    ctx->r4 = ctx->r4 | 0X5DB2;
    // 0x80800894: jal         0x800C4140
    // 0x80800898: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800C4140(rdram, ctx);
        goto after_75;
    // 0x80800898: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_75:
    // 0x8080089C: b           L_80800900
    // 0x808008A0: nop

        goto L_80800900;
    // 0x808008A0: nop

L_808008A4:
    // 0x808008A4: lui         $a1, 0x3F47
    ctx->r5 = S32(0X3F47 << 16);
    // 0x808008A8: jal         0x80101E14
    // 0x808008AC: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    func_80101E14(rdram, ctx);
        goto after_76;
    // 0x808008AC: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    after_76:
    // 0x808008B0: beq         $v0, $zero, L_808008D8
    if (ctx->r2 == 0) {
        // 0x808008B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008D8;
    }
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B8: lui         $a0, 0x731B
    ctx->r4 = S32(0X731B << 16);
    // 0x808008BC: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x808008C0: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x808008C4: ori         $a0, $a0, 0x5DB2
    ctx->r4 = ctx->r4 | 0X5DB2;
    // 0x808008C8: jal         0x800C4140
    // 0x808008CC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800C4140(rdram, ctx);
        goto after_77;
    // 0x808008CC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_77:
    // 0x808008D0: b           L_80800900
    // 0x808008D4: nop

        goto L_80800900;
    // 0x808008D4: nop

L_808008D8:
    // 0x808008D8: lui         $a1, 0x3F5E
    ctx->r5 = S32(0X3F5E << 16);
    // 0x808008DC: jal         0x80101E14
    // 0x808008E0: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    func_80101E14(rdram, ctx);
        goto after_78;
    // 0x808008E0: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    after_78:
    // 0x808008E4: beq         $v0, $zero, L_80800900
    if (ctx->r2 == 0) {
        // 0x808008E8: lui         $a0, 0x6CBB
        ctx->r4 = S32(0X6CBB << 16);
            goto L_80800900;
    }
    // 0x808008E8: lui         $a0, 0x6CBB
    ctx->r4 = S32(0X6CBB << 16);
    // 0x808008EC: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x808008F0: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x808008F4: ori         $a0, $a0, 0x5DB2
    ctx->r4 = ctx->r4 | 0X5DB2;
    // 0x808008F8: jal         0x800C4140
    // 0x808008FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800C4140(rdram, ctx);
        goto after_79;
    // 0x808008FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_79:
L_80800900:
    // 0x80800900: jal         0x80101DDC
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_80;
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_80:
    // 0x80800908: beq         $v0, $zero, L_8080094C
    if (ctx->r2 == 0) {
        // 0x8080090C: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8080094C;
    }
    // 0x8080090C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800910: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800914: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800918: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080091C: jal         0x800DC178
    // 0x80800920: nop

    func_800DC178(rdram, ctx);
        goto after_81;
    // 0x80800920: nop

    after_81:
    // 0x80800924: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080092C: jal         0x80102424
    // 0x80800930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_82;
    // 0x80800930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_82:
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800938: jal         0x8008A4B0
    // 0x8080093C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_83;
    // 0x8080093C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_83:
    // 0x80800940: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1896, 0X1288) << 16);
    // 0x80800944: lwc1        $f10, 0x1288($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1896, 0X1288));
    // 0x80800948: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_8080094C:
    // 0x8080094C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800950: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80800954: b           L_80800B58
    // 0x80800958: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80800B58;
    // 0x80800958: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8080095C:
    // 0x8080095C: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800960: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800964: jal         0x800D91B8
    // 0x80800968: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    func_800D91B8(rdram, ctx);
        goto after_84;
    // 0x80800968: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    after_84:
    // 0x8080096C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1896, 0X1320) << 16);
    // 0x80800970: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1896, 0X1370) << 16);
    // 0x80800974: addiu       $v1, $v1, 0x1370
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1896, 0X1370));
    // 0x80800978: addiu       $v0, $v0, 0x1320
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1896, 0X1320));
    // 0x8080097C: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800980: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_80800984:
    // 0x80800984: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800988: nop

    // 0x8080098C: bc1fl       L_80800AC0
    if (!c1cs) {
        // 0x80800990: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80800AC0;
    }
    goto skip_8;
    // 0x80800990: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    skip_8:
    // 0x80800994: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800998: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8080099C: nop

    // 0x808009A0: bc1f        L_80800ABC
    if (!c1cs) {
        // 0x808009A4: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80800ABC;
    }
    // 0x808009A4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808009A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009AC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808009B0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x808009B4: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x808009B8: nop

    // 0x808009BC: bc1fl       L_808009E4
    if (!c1cs) {
        // 0x808009C0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_808009E4;
    }
    goto skip_9;
    // 0x808009C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_9:
    // 0x808009C4: jal         0x800F54E4
    // 0x808009C8: nop

    func_800F54E4(rdram, ctx);
        goto after_85;
    // 0x808009C8: nop

    after_85:
    // 0x808009CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009D0: jal         0x800F7B9C
    // 0x808009D4: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    func_800F7B9C(rdram, ctx);
        goto after_86;
    // 0x808009D4: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_86:
    // 0x808009D8: b           L_80800ACC
    // 0x808009DC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_80800ACC;
    // 0x808009DC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808009E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_808009E4:
    // 0x808009E4: lui         $a2, 0xBB8
    ctx->r6 = S32(0XBB8 << 16);
    // 0x808009E8: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x808009EC: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x808009F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1896, 0X128C) << 16);
    // 0x808009F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808009F8: bc1f        L_80800A10
    if (!c1cs) {
        // 0x808009FC: nop
    
            goto L_80800A10;
    }
    // 0x808009FC: nop

    // 0x80800A00: jal         0x800FC660
    // 0x80800A04: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800FC660(rdram, ctx);
        goto after_87;
    // 0x80800A04: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_87:
    // 0x80800A08: b           L_80800ACC
    // 0x80800A0C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_80800ACC;
    // 0x80800A0C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800A10:
    // 0x80800A10: lwc1        $f8, 0x128C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1896, 0X128C));
    // 0x80800A14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800A18: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800A1C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800A20: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800A24: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800A28: nop

    // 0x80800A2C: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800A30: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800A34: nop

    // 0x80800A38: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800A3C: beql        $a0, $zero, L_80800A8C
    if (ctx->r4 == 0) {
        // 0x80800A40: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80800A8C;
    }
    goto skip_10;
    // 0x80800A40: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_10:
    // 0x80800A44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800A48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800A4C: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80800A50: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800A54: nop

    // 0x80800A58: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800A5C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800A60: nop

    // 0x80800A64: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800A68: bne         $a0, $zero, L_80800A80
    if (ctx->r4 != 0) {
        // 0x80800A6C: nop
    
            goto L_80800A80;
    }
    // 0x80800A6C: nop

    // 0x80800A70: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80800A74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800A78: b           L_80800A98
    // 0x80800A7C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800A98;
    // 0x80800A7C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800A80:
    // 0x80800A80: b           L_80800A98
    // 0x80800A84: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800A98;
    // 0x80800A84: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800A88: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80800A8C:
    // 0x80800A8C: nop

    // 0x80800A90: bltz        $a0, L_80800A80
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800A94: nop
    
            goto L_80800A80;
    }
    // 0x80800A94: nop

L_80800A98:
    // 0x80800A98: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80800A9C: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x80800AA0: ori         $at, $at, 0x5DB2
    ctx->r1 = ctx->r1 | 0X5DB2;
    // 0x80800AA4: sll         $t1, $t0, 21
    ctx->r9 = S32(ctx->r8 << 21);
    // 0x80800AA8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800AAC: jal         0x800C4140
    // 0x80800AB0: addu        $a0, $t1, $at
    ctx->r4 = ADD32(ctx->r9, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_88;
    // 0x80800AB0: addu        $a0, $t1, $at
    ctx->r4 = ADD32(ctx->r9, ctx->r1);
    after_88:
    // 0x80800AB4: b           L_80800ACC
    // 0x80800AB8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_80800ACC;
    // 0x80800AB8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800ABC:
    // 0x80800ABC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80800AC0:
    // 0x80800AC0: bnel        $v0, $v1, L_80800984
    if (ctx->r2 != ctx->r3) {
        // 0x80800AC4: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_80800984;
    }
    goto skip_11;
    // 0x80800AC4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_11:
    // 0x80800AC8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800ACC:
    // 0x80800ACC: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x80800AD0: b           L_80800B58
    // 0x80800AD4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_80800B58;
    // 0x80800AD4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80800AD8:
    // 0x80800AD8: lui         $a1, 0x3DB8
    ctx->r5 = S32(0X3DB8 << 16);
    // 0x80800ADC: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80800AE0: jal         0x80101E14
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_89;
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_89:
    // 0x80800AE8: beq         $v0, $zero, L_80800B08
    if (ctx->r2 == 0) {
        // 0x80800AEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B08;
    }
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF0: lui         $a1, 0x3F68
    ctx->r5 = S32(0X3F68 << 16);
    // 0x80800AF4: jal         0x80101EE4
    // 0x80800AF8: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    func_80101EE4(rdram, ctx);
        goto after_90;
    // 0x80800AF8: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    after_90:
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B00: jal         0x80102424
    // 0x80800B04: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_91;
    // 0x80800B04: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_91:
L_80800B08:
    // 0x80800B08: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800B0C: srl         $t4, $v0, 10
    ctx->r12 = S32(U32(ctx->r2) >> 10);
    // 0x80800B10: b           L_80800B58
    // 0x80800B14: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_80800B58;
    // 0x80800B14: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_80800B18:
    // 0x80800B18: jal         0x80101DDC
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_92;
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_92:
    // 0x80800B20: beq         $v0, $zero, L_80800B4C
    if (ctx->r2 == 0) {
        // 0x80800B24: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80800B4C;
    }
    // 0x80800B24: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800B28: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800B2C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800B30: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800B34: jal         0x800DC178
    // 0x80800B38: nop

    func_800DC178(rdram, ctx);
        goto after_93;
    // 0x80800B38: nop

    after_93:
    // 0x80800B3C: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B44: jal         0x80102424
    // 0x80800B48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_94;
    // 0x80800B48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_94:
L_80800B4C:
    // 0x80800B4C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800B50: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80800B54: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80800B58:
    // 0x80800B58: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x80800B5C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1896, 0X12A4) << 16);
    // 0x80800B60: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80800B64: lhu         $t6, 0x12A4($t6)
    ctx->r14 = MEM_HU(ctx->r14, (int16_t)RELOC_LO16(1896, 0X12A4));
    // 0x80800B68: addiu       $at, $zero, 0x1E4
    ctx->r1 = ADD32(0, 0X1E4);
    // 0x80800B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B70: bnel        $t6, $at, L_80800CA4
    if (ctx->r14 != ctx->r1) {
        // 0x80800B74: lbu         $t0, 0x65($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X65);
            goto L_80800CA4;
    }
    goto skip_12;
    // 0x80800B74: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    skip_12:
    // 0x80800B78: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800B7C: lui         $a1, 0x3D8F
    ctx->r5 = S32(0X3D8F << 16);
    // 0x80800B80: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x80800B84: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80800B88: jal         0x80101E14
    // 0x80800B8C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_80101E14(rdram, ctx);
        goto after_95;
    // 0x80800B8C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_95:
    // 0x80800B90: bne         $v0, $zero, L_80800BA8
    if (ctx->r2 != 0) {
        // 0x80800B94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BA8;
    }
    // 0x80800B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B98: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x80800B9C: jal         0x80101E14
    // 0x80800BA0: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    func_80101E14(rdram, ctx);
        goto after_96;
    // 0x80800BA0: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    after_96:
    // 0x80800BA4: beq         $v0, $zero, L_80800BF8
    if (ctx->r2 == 0) {
        // 0x80800BA8: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800BF8;
    }
L_80800BA8:
    // 0x80800BA8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800BAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800BB0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800BB4: lui         $a2, 0xC3FA
    ctx->r6 = S32(0XC3FA << 16);
    // 0x80800BB8: jal         0x800C6920
    // 0x80800BBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6920(rdram, ctx);
        goto after_97;
    // 0x80800BBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_97:
    // 0x80800BC0: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800BC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BC8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800BCC: add.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800BD0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800BD4: jal         0x80800FC8
    // 0x80800BD8: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    func_80800FC8_chquicksandbaddy(rdram, ctx);
        goto after_98;
    // 0x80800BD8: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    after_98:
    // 0x80800BDC: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800BE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BE4: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x80800BE8: jal         0x80800F20
    // 0x80800BEC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    chquicksandbaddy_entrypoint_0(rdram, ctx);
        goto after_99;
    // 0x80800BEC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_99:
    // 0x80800BF0: b           L_80800CB0
    // 0x80800BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CB0;
    // 0x80800BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BF8:
    // 0x80800BF8: jal         0x80101F24
    // 0x80800BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_100;
    // 0x80800BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_100:
    // 0x80800C00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1896, 0X1290) << 16);
    // 0x80800C04: lwc1        $f4, 0x1290($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1896, 0X1290));
    // 0x80800C08: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800C0C: nop

    // 0x80800C10: bc1fl       L_80800CB0
    if (!c1cs) {
        // 0x80800C14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CB0;
    }
    goto skip_13;
    // 0x80800C14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x80800C18: jal         0x80101F24
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_101;
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_101:
    // 0x80800C20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1896, 0X1294) << 16);
    // 0x80800C24: lwc1        $f6, 0x1294($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1896, 0X1294));
    // 0x80800C28: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800C2C: nop

    // 0x80800C30: bc1fl       L_80800CB0
    if (!c1cs) {
        // 0x80800C34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CB0;
    }
    goto skip_14;
    // 0x80800C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x80800C38: jal         0x800DC0C0
    // 0x80800C3C: nop

    func_800DC0C0(rdram, ctx);
        goto after_102;
    // 0x80800C3C: nop

    after_102:
    // 0x80800C40: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800C44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C4C: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    // 0x80800C50: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800C54: nop

    // 0x80800C58: bc1fl       L_80800CB0
    if (!c1cs) {
        // 0x80800C5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CB0;
    }
    goto skip_15;
    // 0x80800C5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x80800C60: jal         0x8008A0D0
    // 0x80800C64: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_103;
    // 0x80800C64: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_103:
    // 0x80800C68: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800C6C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800C70: lui         $a2, 0xC3FA
    ctx->r6 = S32(0XC3FA << 16);
    // 0x80800C74: jal         0x800C6920
    // 0x80800C78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6920(rdram, ctx);
        goto after_104;
    // 0x80800C78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_104:
    // 0x80800C7C: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800C80: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800C84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800C88: add.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800C8C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800C90: jal         0x80800FC8
    // 0x80800C94: nop

    func_80800FC8_chquicksandbaddy(rdram, ctx);
        goto after_105;
    // 0x80800C94: nop

    after_105:
    // 0x80800C98: b           L_80800CB0
    // 0x80800C9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CB0;
    // 0x80800C9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CA0: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
L_80800CA4:
    // 0x80800CA4: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x80800CA8: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CB0:
    // 0x80800CB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CB4: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // 0x80800CB8: jr          $ra
    // 0x80800CBC: nop

    return;
    // 0x80800CBC: nop

;}
RECOMP_FUNC void func_8080000C_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800E0FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0FE8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800E0FEC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800E0FF0: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x800E0FF4: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x800E0FF8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800E0FFC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800E1000: blez        $v1, L_800E1108
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800E1004: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E1108;
    }
    // 0x800E1004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E1008: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800E100C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E1010: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800E1014: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
L_800E1018:
    // 0x800E1018: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800E101C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E1020: addu        $a1, $t7, $a2
    ctx->r5 = ADD32(ctx->r15, ctx->r6);
    // 0x800E1024: lbu         $t8, 0x10($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X10);
    // 0x800E1028: bnel        $a3, $t8, L_800E1100
    if (ctx->r7 != ctx->r24) {
        // 0x800E102C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800E1100;
    }
    goto skip_0;
    // 0x800E102C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
    // 0x800E1030: lbu         $t9, 0x11($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X11);
    // 0x800E1034: bnel        $t0, $t9, L_800E1100
    if (ctx->r8 != ctx->r25) {
        // 0x800E1038: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800E1100;
    }
    goto skip_1;
    // 0x800E1038: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
    // 0x800E103C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800E1040: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800E1044: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800E1048: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800E104C: nop

    // 0x800E1050: bc1fl       L_800E10B0
    if (!c1cs) {
        // 0x800E1054: c.lt.s      $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
            goto L_800E10B0;
    }
    goto skip_2;
    // 0x800E1054: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    skip_2:
    // 0x800E1058: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E105C: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800E1060: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x800E1064: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E1068: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800E106C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800E1070: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800E1074: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800E1078: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800E107C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800E1080: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800E1084: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800E1088: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800E108C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800E1090: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800E1094: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800E1098: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800E109C: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800E10A0: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800E10A4: b           L_800E10FC
    // 0x800E10A8: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
        goto L_800E10FC;
    // 0x800E10A8: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x800E10AC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
L_800E10B0:
    // 0x800E10B0: nop

    // 0x800E10B4: bc1fl       L_800E1100
    if (!c1cs) {
        // 0x800E10B8: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800E1100;
    }
    goto skip_3;
    // 0x800E10B8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_3:
    // 0x800E10BC: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800E10C0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E10C4: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800E10C8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E10CC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800E10D0: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800E10D4: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800E10D8: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800E10DC: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800E10E0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800E10E4: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800E10E8: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800E10EC: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800E10F0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800E10F4: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800E10F8: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
L_800E10FC:
    // 0x800E10FC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800E1100:
    // 0x800E1100: bne         $at, $zero, L_800E1018
    if (ctx->r1 != 0) {
        // 0x800E1104: addiu       $a2, $a2, 0x14
        ctx->r6 = ADD32(ctx->r6, 0X14);
            goto L_800E1018;
    }
    // 0x800E1104: addiu       $a2, $a2, 0x14
    ctx->r6 = ADD32(ctx->r6, 0X14);
L_800E1108:
    // 0x800E1108: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800E110C: jr          $ra
    // 0x800E1110: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800E1110: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80800FC0_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FC8: jal         0x80800AEC
    // 0x80800FCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800AEC_bssub(rdram, ctx);
        goto after_0;
    // 0x80800FCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800FD0: jal         0x80800254
    // 0x80800FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800254_bssub(rdram, ctx);
        goto after_1;
    // 0x80800FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800FD8: jal         0x80082FE8
    // 0x80800FDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800FDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FE8: jr          $ra
    // 0x80800FEC: nop

    return;
    // 0x80800FEC: nop

;}
RECOMP_FUNC void func_808012E0_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808012E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808012E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808012EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808012F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808012F4: jal         0x80100094
    // 0x808012F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808012F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808012FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801300: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801304: jal         0x80102424
    // 0x80801308: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80801308: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080130C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80801310: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80801314: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80801318: sltiu       $at, $t7, 0x1B
    ctx->r1 = ctx->r15 < 0X1B ? 1 : 0;
    // 0x8080131C: beq         $at, $zero, L_808015E0
    if (ctx->r1 == 0) {
        // 0x80801320: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808015E0;
    }
    // 0x80801320: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801324: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2C8C) << 16);
    // 0x80801328: addu        $at, $at, $t7
    gpr jr_addend_80801330 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080132C: lw          $t7, 0x2C8C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2C8C));
    // 0x80801330: jr          $t7
    // 0x80801334: nop

    switch (jr_addend_80801330 >> 2) {
        case 0: goto L_80801338; break;
        case 1: goto L_80801388; break;
        case 2: goto L_808015E0; break;
        case 3: goto L_808013AC; break;
        case 4: goto L_808013CC; break;
        case 5: goto L_80801434; break;
        case 6: goto L_8080146C; break;
        case 7: goto L_808015E0; break;
        case 8: goto L_808015E0; break;
        case 9: goto L_8080149C; break;
        case 10: goto L_808014D4; break;
        case 11: goto L_8080144C; break;
        case 12: goto L_808013CC; break;
        case 13: goto L_80801434; break;
        case 14: goto L_808015E0; break;
        case 15: goto L_808014F8; break;
        case 16: goto L_808015E0; break;
        case 17: goto L_80801508; break;
        case 18: goto L_80801528; break;
        case 19: goto L_808015E0; break;
        case 20: goto L_80801514; break;
        case 21: goto L_808015E0; break;
        case 22: goto L_80801548; break;
        case 23: goto L_80801584; break;
        case 24: goto L_808015A8; break;
        case 25: goto L_808015D4; break;
        case 26: goto L_808015D4; break;
        default: switch_error(__func__, 0x80801330, 0x80802C8C);
    }
    // 0x80801334: nop

L_80801338:
    // 0x80801338: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2DA0) << 16);
    // 0x8080133C: addiu       $a2, $a2, 0x2DA0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2DA0));
    // 0x80801340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801344: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801348: jal         0x80089D18
    // 0x8080134C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080134C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80801350: jal         0x800FDC28
    // 0x80801354: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_3;
    // 0x80801354: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80801358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080135C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801360: jal         0x808021E4
    // 0x80801364: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_4;
    // 0x80801364: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_4:
    // 0x80801368: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8080136C: jal         0x80106790
    // 0x80801370: lw          $a0, 0x9C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X9C);
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80801370: lw          $a0, 0x9C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X9C);
    after_5:
    // 0x80801374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801378: jal         0x80102424
    // 0x8080137C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x8080137C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80801380: b           L_808015E4
    // 0x80801384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x80801384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801388:
    // 0x80801388: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x8080138C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801390: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801394: jal         0x800861A0
    // 0x80801398: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80801398: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8080139C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808013A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808013A4: b           L_808015E0
    // 0x808013A8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808015E0;
    // 0x808013A8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808013AC:
    // 0x808013AC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808013B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808013B4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808013B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808013BC: jal         0x800DC178
    // 0x808013C0: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808013C0: nop

    after_8:
    // 0x808013C4: b           L_808015E0
    // 0x808013C8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808015E0;
    // 0x808013C8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808013CC:
    // 0x808013CC: lh          $t8, 0x90($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X90);
    // 0x808013D0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x808013D4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808013D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808013DC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808013E0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x808013E4: addu        $a1, $v1, $t9
    ctx->r5 = ADD32(ctx->r3, ctx->r25);
    // 0x808013E8: jal         0x800EEB40
    // 0x808013EC: addiu       $a1, $a1, 0xA4
    ctx->r5 = ADD32(ctx->r5, 0XA4);
    func_800EEB40(rdram, ctx);
        goto after_9;
    // 0x808013EC: addiu       $a1, $a1, 0xA4
    ctx->r5 = ADD32(ctx->r5, 0XA4);
    after_9:
    // 0x808013F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2CF8) << 16);
    // 0x808013F4: lwc1        $f6, 0x2CF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2CF8));
    // 0x808013F8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808013FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801400: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801404: nop

    // 0x80801408: bc1f        L_8080141C
    if (!c1cs) {
        // 0x8080140C: nop
    
            goto L_8080141C;
    }
    // 0x8080140C: nop

    // 0x80801410: lh          $t0, 0x90($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X90);
    // 0x80801414: xori        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 ^ 0X1;
    // 0x80801418: sh          $t1, 0x90($v1)
    MEM_H(0X90, ctx->r3) = ctx->r9;
L_8080141C:
    // 0x8080141C: jal         0x80109FE8
    // 0x80801420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_10;
    // 0x80801420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80801424: jal         0x808018E8
    // 0x80801428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018E8_changlerboss(rdram, ctx);
        goto after_11;
    // 0x80801428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080142C: b           L_808015E4
    // 0x80801430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x80801430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801434:
    // 0x80801434: lh          $t2, 0x90($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X90);
    // 0x80801438: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080143C: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80801440: sh          $t3, 0x90($v1)
    MEM_H(0X90, ctx->r3) = ctx->r11;
    // 0x80801444: b           L_808015E0
    // 0x80801448: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
        goto L_808015E0;
    // 0x80801448: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
L_8080144C:
    // 0x8080144C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801450: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801454: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801458: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080145C: jal         0x800DC178
    // 0x80801460: nop

    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80801460: nop

    after_12:
    // 0x80801464: b           L_808015E0
    // 0x80801468: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808015E0;
    // 0x80801468: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_8080146C:
    // 0x8080146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801470: jal         0x80801C50
    // 0x80801474: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80801C50_changlerboss(rdram, ctx);
        goto after_13;
    // 0x80801474: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_13:
    // 0x80801478: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8080147C: beq         $at, $zero, L_80801490
    if (ctx->r1 == 0) {
        // 0x80801480: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80801490;
    }
    // 0x80801480: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80801484: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80801488: b           L_808015E0
    // 0x8080148C: sh          $t4, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r12;
        goto L_808015E0;
    // 0x8080148C: sh          $t4, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r12;
L_80801490:
    // 0x80801490: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801494: b           L_808015E0
    // 0x80801498: sh          $t5, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r13;
        goto L_808015E0;
    // 0x80801498: sh          $t5, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r13;
L_8080149C:
    // 0x8080149C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808014A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808014A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014A8: jal         0x808027F8
    // 0x808014AC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_808027F8_changlerboss(rdram, ctx);
        goto after_14;
    // 0x808014AC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_14:
    // 0x808014B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014B4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x808014B8: jal         0x808021E4
    // 0x808014BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_15;
    // 0x808014BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_15:
    // 0x808014C0: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x808014C4: jal         0x800D2770
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D2770(rdram, ctx);
        goto after_16;
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808014CC: b           L_808015E4
    // 0x808014D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x808014D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808014D4:
    // 0x808014D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808014D8: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x808014DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808014E0: addiu       $a1, $zero, 0x102B
    ctx->r5 = ADD32(0, 0X102B);
    // 0x808014E4: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    // 0x808014E8: jal         0x8008A208
    // 0x808014EC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x808014EC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_17:
    // 0x808014F0: b           L_808015E4
    // 0x808014F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x808014F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808014F8:
    // 0x808014F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808014FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801500: b           L_808015E0
    // 0x80801504: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_808015E0;
    // 0x80801504: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80801508:
    // 0x80801508: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080150C: b           L_808015E0
    // 0x80801510: sh          $t7, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r15;
        goto L_808015E0;
    // 0x80801510: sh          $t7, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r15;
L_80801514:
    // 0x80801514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801518: jal         0x80109FE8
    // 0x8080151C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_18;
    // 0x8080151C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80801520: b           L_808015E4
    // 0x80801524: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x80801524: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801528:
    // 0x80801528: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080152C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801530: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80801534: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801538: jal         0x800DC178
    // 0x8080153C: nop

    func_800DC178(rdram, ctx);
        goto after_19;
    // 0x8080153C: nop

    after_19:
    // 0x80801540: b           L_808015E0
    // 0x80801544: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808015E0;
    // 0x80801544: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80801548:
    // 0x80801548: jal         0x800FDC28
    // 0x8080154C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_20;
    // 0x8080154C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80801550: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2F80) << 16);
    // 0x80801554: addiu       $a2, $a2, 0x2F80
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2F80));
    // 0x80801558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080155C: jal         0x80089D18
    // 0x80801560: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x80801560: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_21:
    // 0x80801564: jal         0x808027F8
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808027F8_changlerboss(rdram, ctx);
        goto after_22;
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8080156C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801570: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80801574: jal         0x808021E4
    // 0x80801578: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_23;
    // 0x80801578: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_23:
    // 0x8080157C: b           L_808015E4
    // 0x80801580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x80801580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801584:
    // 0x80801584: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801588: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x8080158C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801590: addiu       $a1, $zero, 0x1029
    ctx->r5 = ADD32(0, 0X1029);
    // 0x80801594: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    // 0x80801598: jal         0x8008A208
    // 0x8080159C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_24;
    // 0x8080159C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_24:
    // 0x808015A0: b           L_808015E4
    // 0x808015A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x808015A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808015A8:
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015AC: jal         0x80109FE8
    // 0x808015B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_25;
    // 0x808015B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x808015B4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808015B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808015BC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808015C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808015C4: jal         0x800DC178
    // 0x808015C8: nop

    func_800DC178(rdram, ctx);
        goto after_26;
    // 0x808015C8: nop

    after_26:
    // 0x808015CC: b           L_808015E0
    // 0x808015D0: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808015E0;
    // 0x808015D0: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808015D4:
    // 0x808015D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015D8: jal         0x80109FE8
    // 0x808015DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_27;
    // 0x808015DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
L_808015E0:
    // 0x808015E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808015E4:
    // 0x808015E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808015E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808015EC: jr          $ra
    // 0x808015F0: nop

    return;
    // 0x808015F0: nop

;}
RECOMP_FUNC void bsbanshack_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C9C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800CA0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(45, 0XD10) << 16);
    // 0x80800CA4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CA8: jr          $ra
    // 0x80800CAC: lw          $v0, 0xD10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XD10));
    return;
    // 0x80800CAC: lw          $v0, 0xD10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XD10));
;}
