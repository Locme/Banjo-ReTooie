#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void ncbaglide_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080000C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8080001C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800020: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x80800024: jal         0x80111590
    // 0x80800028: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80111590(rdram, ctx);
        goto after_0;
    // 0x80800028: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800034: jal         0x80111B8C
    // 0x80800038: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_1;
    // 0x80800038: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_1:
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x80115858
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80115858(rdram, ctx);
        goto after_2;
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x80115870
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80115870(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x801124D0
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_4;
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800060: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800064: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800068: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void bsbshock_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(116, 0X870) << 16);
    // 0x808004F8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004FC: jr          $ra
    // 0x80800500: lw          $v0, 0x870($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(116, 0X870));
    return;
    // 0x80800500: lw          $v0, 0x870($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(116, 0X870));
;}
RECOMP_FUNC void _bsblongleg_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829F8: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x800829F8);
    return;
    // 0x800829FC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _gsmaker_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825B8: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825B8);
    return;
    // 0x800825BC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800262DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800262DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800262E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800262E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800262E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800262EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800262F0: lbu         $t7, 0x2B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2B);
    // 0x800262F4: addiu       $t6, $zero, 0xFC
    ctx->r14 = ADD32(0, 0XFC);
    // 0x800262F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800262FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80026300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80026304: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80026308: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8002630C: jal         0x8002ACE0
    // 0x80026310: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_8002ACE0(rdram, ctx);
        goto after_0;
    // 0x80026310: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80026314: b           L_8002631C
    // 0x80026318: nop

        goto L_8002631C;
    // 0x80026318: nop

L_8002631C:
    // 0x8002631C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026320: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026324: jr          $ra
    // 0x80026328: nop

    return;
    // 0x80026328: nop

    // 0x8002632C: nop

;}
RECOMP_FUNC void func_800E7C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7C28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E7C2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E7C30: jal         0x8001A0A8
    // 0x800E7C34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8001A0A8(rdram, ctx);
        goto after_0;
    // 0x800E7C34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E7C38: beq         $v0, $zero, L_800E7CE4
    if (ctx->r2 == 0) {
        // 0x800E7C3C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_800E7CE4;
    }
    // 0x800E7C3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800E7C40: jal         0x800A8184
    // 0x800E7C44: nop

    func_800A8184(rdram, ctx);
        goto after_1;
    // 0x800E7C44: nop

    after_1:
    // 0x800E7C48: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E7C4C: bnel        $v0, $at, L_800E7C68
    if (ctx->r2 != ctx->r1) {
        // 0x800E7C50: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800E7C68;
    }
    goto skip_0;
    // 0x800E7C50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x800E7C54: jal         0x800EA358
    // 0x800E7C58: nop

    func_800EA358(rdram, ctx);
        goto after_2;
    // 0x800E7C58: nop

    after_2:
    // 0x800E7C5C: beql        $v0, $zero, L_800E7CE8
    if (ctx->r2 == 0) {
        // 0x800E7C60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800E7CE8;
    }
    goto skip_1;
    // 0x800E7C60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800E7C64: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_800E7C68:
    // 0x800E7C68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800E7C6C: addiu       $t0, $t0, 0x7750
    ctx->r8 = ADD32(ctx->r8, 0X7750);
    // 0x800E7C70: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E7C74: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x800E7C78: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800E7C7C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E7C80: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E7C84: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x800E7C88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800E7C8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E7C90: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800E7C94: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800E7C98: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x800E7C9C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800E7CA0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800E7CA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E7CA8: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800E7CAC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800E7CB0: lh          $t4, 0x7752($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7752);
    // 0x800E7CB4: lh          $a3, 0x0($t0)
    ctx->r7 = MEM_H(ctx->r8, 0X0);
    // 0x800E7CB8: jal         0x800E7A90
    // 0x800E7CBC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800E7A90(rdram, ctx);
        goto after_3;
    // 0x800E7CBC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x800E7CC0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800E7CC4: lh          $t5, 0x7752($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7752);
    // 0x800E7CC8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800E7CCC: lh          $a3, 0x7750($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X7750);
    // 0x800E7CD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800E7CD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800E7CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E7CDC: jal         0x800BC5B0
    // 0x800E7CE0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800BC5B0(rdram, ctx);
        goto after_4;
    // 0x800E7CE0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_4:
L_800E7CE4:
    // 0x800E7CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E7CE8:
    // 0x800E7CE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E7CEC: jr          $ra
    // 0x800E7CF0: nop

    return;
    // 0x800E7CF0: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836A0: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836A0);
    return;
    // 0x800836A4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _gspropctrl_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BD0: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BD0);
    return;
    // 0x80088BD4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800E7368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7368: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E736C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800E7370: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800E7374: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E7378: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800E737C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800E7380: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E7384: addiu       $s0, $zero, 0x1F
    ctx->r16 = ADD32(0, 0X1F);
    // 0x800E7388: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800E738C:
    // 0x800E738C: sllv        $t7, $t6, $s0
    ctx->r15 = S32(ctx->r14 << (ctx->r16 & 31));
    // 0x800E7390: and         $t8, $t7, $s1
    ctx->r24 = ctx->r15 & ctx->r17;
    // 0x800E7394: beq         $t8, $zero, L_800E73A4
    if (ctx->r24 == 0) {
        // 0x800E7398: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800E73A4;
    }
    // 0x800E7398: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E739C: b           L_800E73A8
    // 0x800E73A0: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
        goto L_800E73A8;
    // 0x800E73A0: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
L_800E73A4:
    // 0x800E73A4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_800E73A8:
    // 0x800E73A8: jal         0x800E6A58
    // 0x800E73AC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    func_800E6A58(rdram, ctx);
        goto after_0;
    // 0x800E73AC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_0:
    // 0x800E73B0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800E73B4: bgezl       $s0, L_800E738C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800E73B8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800E738C;
    }
    goto skip_0;
    // 0x800E73B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x800E73BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E73C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E73C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800E73C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800E73CC: jr          $ra
    // 0x800E73D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E73D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _sulights_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8E8: syscall     854
    recomp_syscall_handler(rdram, ctx, 0x8008A8E8);
    return;
    // 0x8008A8EC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void gcnewoption_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080147C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80801480: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80801484: jr          $ra
    // 0x80801488: sh          $zero, 0xB0($t7)
    MEM_H(0XB0, ctx->r15) = 0;
    return;
    // 0x80801488: sh          $zero, 0xB0($t7)
    MEM_H(0XB0, ctx->r15) = 0;
;}
RECOMP_FUNC void func_800BABB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BABB8: addiu       $sp, $sp, -0x188
    ctx->r29 = ADD32(ctx->r29, -0X188);
    // 0x800BABBC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800BABC0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800BABC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BABC8: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800BABCC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800BABD0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800BABD4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800BABD8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800BABDC: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800BABE0: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800BABE4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800BABE8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800BABEC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800BABF0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800BABF4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800BABF8: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x800BABFC: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800BAC00: sw          $a2, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r6;
    // 0x800BAC04: beq         $a0, $zero, L_800BAC1C
    if (ctx->r4 == 0) {
        // 0x800BAC08: sw          $zero, 0x17C($sp)
        MEM_W(0X17C, ctx->r29) = 0;
            goto L_800BAC1C;
    }
    // 0x800BAC08: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
    // 0x800BAC0C: beql        $a1, $zero, L_800BAC20
    if (ctx->r5 == 0) {
        // 0x800BAC10: lw          $s0, 0x198($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X198);
            goto L_800BAC20;
    }
    goto skip_0;
    // 0x800BAC10: lw          $s0, 0x198($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X198);
    skip_0:
    // 0x800BAC14: jal         0x800EE940
    // 0x800BAC18: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    func_800EE940(rdram, ctx);
        goto after_0;
    // 0x800BAC18: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    after_0:
L_800BAC1C:
    // 0x800BAC1C: lw          $s0, 0x198($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X198);
L_800BAC20:
    // 0x800BAC20: bnel        $s0, $zero, L_800BAC34
    if (ctx->r16 != 0) {
        // 0x800BAC24: lh          $v0, 0x0($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X0);
            goto L_800BAC34;
    }
    goto skip_1;
    // 0x800BAC24: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    skip_1:
    // 0x800BAC28: b           L_800BBC80
    // 0x800BAC2C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_800BBC80;
    // 0x800BAC2C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800BAC30: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
L_800BAC34:
    // 0x800BAC34: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BAC38: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800BAC3C: beq         $v0, $zero, L_800BBC64
    if (ctx->r2 == 0) {
        // 0x800BAC40: addiu       $s5, $zero, 0x3
        ctx->r21 = ADD32(0, 0X3);
            goto L_800BBC64;
    }
    // 0x800BAC40: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x800BAC44: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800BAC48: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800BAC4C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800BAC50: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x800BAC54: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BAC58: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
L_800BAC5C:
    // 0x800BAC5C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800BAC60: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x800BAC64: beq         $at, $zero, L_800BBC54
    if (ctx->r1 == 0) {
        // 0x800BAC68: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800BBC54;
    }
    // 0x800BAC68: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BAC6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800BAC70: addu        $at, $at, $t7
    gpr jr_addend_800BAC78 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BAC74: lw          $t7, 0x56CC($at)
    ctx->r15 = ADD32(ctx->r1, 0X56CC);
    // 0x800BAC78: jr          $t7
    // 0x800BAC7C: nop

    switch (jr_addend_800BAC78 >> 2) {
        case 0: goto L_800BAC80; break;
        case 1: goto L_800BAD3C; break;
        case 2: goto L_800BAD4C; break;
        case 3: goto L_800BAD64; break;
        case 4: goto L_800BAD84; break;
        case 5: goto L_800BAD98; break;
        case 6: goto L_800BADC4; break;
        case 7: goto L_800BADD4; break;
        case 8: goto L_800BAE08; break;
        case 9: goto L_800BAE1C; break;
        case 10: goto L_800BAEDC; break;
        case 11: goto L_800BAF78; break;
        case 12: goto L_800BB010; break;
        case 13: goto L_800BB098; break;
        case 14: goto L_800BB0E8; break;
        case 15: goto L_800BB104; break;
        case 16: goto L_800BB130; break;
        case 17: goto L_800BB160; break;
        case 18: goto L_800BB184; break;
        case 19: goto L_800BB1A8; break;
        case 20: goto L_800BB250; break;
        case 21: goto L_800BB284; break;
        case 22: goto L_800BB294; break;
        case 23: goto L_800BB2D0; break;
        case 24: goto L_800BB318; break;
        case 25: goto L_800BB334; break;
        case 26: goto L_800BB350; break;
        case 27: goto L_800BB3C8; break;
        case 28: goto L_800BB3F4; break;
        case 29: goto L_800BB440; break;
        case 30: goto L_800BB484; break;
        case 31: goto L_800BB4BC; break;
        case 32: goto L_800BB4FC; break;
        case 33: goto L_800BB51C; break;
        case 34: goto L_800BB5D8; break;
        case 35: goto L_800BB620; break;
        case 36: goto L_800BB684; break;
        case 37: goto L_800BB6E8; break;
        case 38: goto L_800BB720; break;
        case 39: goto L_800BB758; break;
        case 40: goto L_800BB788; break;
        case 41: goto L_800BB798; break;
        case 42: goto L_800BB850; break;
        case 43: goto L_800BB8A4; break;
        case 44: goto L_800BB984; break;
        case 45: goto L_800BB9EC; break;
        case 46: goto L_800BBA5C; break;
        case 47: goto L_800BBB64; break;
        case 48: goto L_800BBB84; break;
        case 49: goto L_800BBBC0; break;
        case 50: goto L_800BBBD0; break;
        case 51: goto L_800BBBE0; break;
        default: switch_error(__func__, 0x800BAC78, 0x801256CC);
    }
    // 0x800BAC7C: nop

L_800BAC80:
    // 0x800BAC80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BAC84: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800BAC88: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BAC8C: beq         $v1, $s5, L_800BACE8
    if (ctx->r3 == ctx->r21) {
        // 0x800BAC90: lh          $t8, 0x0($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X0);
            goto L_800BACE8;
    }
    // 0x800BAC90: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
L_800BAC94:
    // 0x800BAC94: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800BAC98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BAC9C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800BACA0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BACA4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BACA8: mul.s       $f18, $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800BACAC: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BACB0: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800BACB4: nop

    // 0x800BACB8: sh          $t0, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r8;
    // 0x800BACBC: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    // 0x800BACC0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800BACC4: nop

    // 0x800BACC8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BACCC: mul.s       $f18, $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800BACD0: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BACD4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800BACD8: nop

    // 0x800BACDC: sh          $t3, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r11;
    // 0x800BACE0: bne         $v1, $s5, L_800BAC94
    if (ctx->r3 != ctx->r21) {
        // 0x800BACE4: lh          $t8, 0x0($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X0);
            goto L_800BAC94;
    }
    // 0x800BACE4: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
L_800BACE8:
    // 0x800BACE8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800BACEC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800BACF0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BACF4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BACF8: mul.s       $f18, $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800BACFC: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BAD00: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800BAD04: nop

    // 0x800BAD08: sh          $t0, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r8;
    // 0x800BAD0C: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    // 0x800BAD10: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800BAD14: nop

    // 0x800BAD18: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BAD1C: mul.s       $f18, $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800BAD20: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BAD24: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800BAD28: nop

    // 0x800BAD2C: sh          $t3, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r11;
    // 0x800BAD30: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800BAD34: b           L_800BBC54
    // 0x800BAD38: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BAD38: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BAD3C:
    // 0x800BAD3C: andi        $t4, $v0, 0xFF00
    ctx->r12 = ctx->r2 & 0XFF00;
    // 0x800BAD40: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800BAD44: b           L_800BBC54
    // 0x800BAD48: sb          $t5, 0x83($s1)
    MEM_B(0X83, ctx->r17) = ctx->r13;
        goto L_800BBC54;
    // 0x800BAD48: sb          $t5, 0x83($s1)
    MEM_B(0X83, ctx->r17) = ctx->r13;
L_800BAD4C:
    // 0x800BAD4C: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800BAD50: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BAD54: sh          $t6, 0xAA($s1)
    MEM_H(0XAA, ctx->r17) = ctx->r14;
    // 0x800BAD58: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x800BAD5C: b           L_800BBC54
    // 0x800BAD60: sw          $t7, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->r15;
        goto L_800BBC54;
    // 0x800BAD60: sw          $t7, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->r15;
L_800BAD64:
    // 0x800BAD64: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800BAD68: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BAD6C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BAD70: nop

    // 0x800BAD74: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BAD78: mul.s       $f0, $f18, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800BAD7C: b           L_800BBC54
    // 0x800BAD80: swc1        $f0, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->f0.u32l;
        goto L_800BBC54;
    // 0x800BAD80: swc1        $f0, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->f0.u32l;
L_800BAD84:
    // 0x800BAD84: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BAD88: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BAD8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BAD90: b           L_800BBC54
    // 0x800BAD94: sh          $v0, 0xAC($s1)
    MEM_H(0XAC, ctx->r17) = ctx->r2;
        goto L_800BBC54;
    // 0x800BAD94: sh          $v0, 0xAC($s1)
    MEM_H(0XAC, ctx->r17) = ctx->r2;
L_800BAD98:
    // 0x800BAD98: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BAD9C: lwc1        $f4, 0x4($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800BADA0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BADA4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BADA8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BADAC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BADB0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BADB4: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BADB8: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800BADBC: b           L_800BBC54
    // 0x800BADC0: sh          $t0, 0xAC($s1)
    MEM_H(0XAC, ctx->r17) = ctx->r8;
        goto L_800BBC54;
    // 0x800BADC0: sh          $t0, 0xAC($s1)
    MEM_H(0XAC, ctx->r17) = ctx->r8;
L_800BADC4:
    // 0x800BADC4: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x800BADC8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BADCC: b           L_800BBC54
    // 0x800BADD0: sh          $t1, 0xA8($s1)
    MEM_H(0XA8, ctx->r17) = ctx->r9;
        goto L_800BBC54;
    // 0x800BADD0: sh          $t1, 0xA8($s1)
    MEM_H(0XA8, ctx->r17) = ctx->r9;
L_800BADD4:
    // 0x800BADD4: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x800BADD8: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x800BADDC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BADE0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800BADE4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800BADE8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BADEC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BADF0: mul.s       $f0, $f4, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800BADF4: nop

    // 0x800BADF8: mul.s       $f2, $f10, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800BADFC: swc1        $f0, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = ctx->f0.u32l;
    // 0x800BAE00: b           L_800BBC54
    // 0x800BAE04: swc1        $f2, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f2.u32l;
        goto L_800BBC54;
    // 0x800BAE04: swc1        $f2, 0xB8($s1)
    MEM_W(0XB8, ctx->r17) = ctx->f2.u32l;
L_800BAE08:
    // 0x800BAE08: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BAE0C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BAE10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BAE14: b           L_800BBC54
    // 0x800BAE18: sh          $v0, 0xAE($s1)
    MEM_H(0XAE, ctx->r17) = ctx->r2;
        goto L_800BBC54;
    // 0x800BAE18: sh          $v0, 0xAE($s1)
    MEM_H(0XAE, ctx->r17) = ctx->r2;
L_800BAE1C:
    // 0x800BAE1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BAE20: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800BAE24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BAE28: beq         $v1, $s5, L_800BAE84
    if (ctx->r3 == ctx->r21) {
        // 0x800BAE2C: lh          $t4, 0x0($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X0);
            goto L_800BAE84;
    }
    // 0x800BAE2C: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
L_800BAE30:
    // 0x800BAE30: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800BAE34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BAE38: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800BAE3C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BAE40: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BAE44: mul.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BAE48: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BAE4C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800BAE50: nop

    // 0x800BAE54: sh          $t6, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r14;
    // 0x800BAE58: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x800BAE5C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800BAE60: nop

    // 0x800BAE64: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BAE68: mul.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BAE6C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BAE70: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800BAE74: nop

    // 0x800BAE78: sh          $t9, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r25;
    // 0x800BAE7C: bne         $v1, $s5, L_800BAE30
    if (ctx->r3 != ctx->r21) {
        // 0x800BAE80: lh          $t4, 0x0($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X0);
            goto L_800BAE30;
    }
    // 0x800BAE80: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
L_800BAE84:
    // 0x800BAE84: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800BAE88: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800BAE8C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BAE90: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BAE94: mul.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BAE98: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BAE9C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800BAEA0: nop

    // 0x800BAEA4: sh          $t6, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r14;
    // 0x800BAEA8: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x800BAEAC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800BAEB0: nop

    // 0x800BAEB4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BAEB8: mul.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BAEBC: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BAEC0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800BAEC4: nop

    // 0x800BAEC8: sh          $t9, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r25;
    // 0x800BAECC: sb          $zero, 0x5($s1)
    MEM_B(0X5, ctx->r17) = 0;
    // 0x800BAED0: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800BAED4: b           L_800BBC54
    // 0x800BAED8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BAED8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BAEDC:
    // 0x800BAEDC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800BAEE0: sb          $t0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r8;
    // 0x800BAEE4: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x800BAEE8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800BAEEC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800BAEF0: nop

    // 0x800BAEF4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BAEF8: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800BAEFC: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BAF00: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800BAF04: nop

    // 0x800BAF08: sh          $t3, 0x28($s1)
    MEM_H(0X28, ctx->r17) = ctx->r11;
    // 0x800BAF0C: lh          $t4, -0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, -0X6);
    // 0x800BAF10: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800BAF14: nop

    // 0x800BAF18: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BAF1C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BAF20: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BAF24: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800BAF28: nop

    // 0x800BAF2C: sh          $t6, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r14;
    // 0x800BAF30: lh          $t7, -0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X4);
    // 0x800BAF34: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800BAF38: nop

    // 0x800BAF3C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BAF40: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800BAF44: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BAF48: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BAF4C: nop

    // 0x800BAF50: sh          $t9, 0x2C($s1)
    MEM_H(0X2C, ctx->r17) = ctx->r25;
    // 0x800BAF54: lh          $t0, -0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, -0X2);
    // 0x800BAF58: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800BAF5C: nop

    // 0x800BAF60: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BAF64: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BAF68: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BAF6C: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x800BAF70: b           L_800BBC54
    // 0x800BAF74: sh          $t2, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r10;
        goto L_800BBC54;
    // 0x800BAF74: sh          $t2, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r10;
L_800BAF78:
    // 0x800BAF78: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800BAF7C: sb          $zero, 0x5($s1)
    MEM_B(0X5, ctx->r17) = 0;
    // 0x800BAF80: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BAF84: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800BAF88: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x800BAF8C: addiu       $s3, $s1, 0x2E
    ctx->r19 = ADD32(ctx->r17, 0X2E);
    // 0x800BAF90: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BAF94: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800BAF98: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x800BAF9C: swc1        $f0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f0.u32l;
    // 0x800BAFA0: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BAFA4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800BAFA8: nop

    // 0x800BAFAC: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x800BAFB0: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800BAFB4: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x800BAFB8: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x800BAFBC: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800BAFC0: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800BAFC4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800BAFC8: jal         0x800EFA6C
    // 0x800BAFCC: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    func_800EFA6C(rdram, ctx);
        goto after_1;
    // 0x800BAFCC: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    after_1:
    // 0x800BAFD0: lwc1        $f0, 0x158($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X158);
    // 0x800BAFD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800BAFD8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800BAFDC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800BAFE0: nop

    // 0x800BAFE4: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x800BAFE8: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800BAFEC: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x800BAFF0: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x800BAFF4: sra         $t3, $a3, 16
    ctx->r11 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800BAFF8: sra         $t2, $a2, 16
    ctx->r10 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800BAFFC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800BB000: jal         0x800EFA6C
    // 0x800BB004: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    func_800EFA6C(rdram, ctx);
        goto after_2;
    // 0x800BB004: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    after_2:
    // 0x800BB008: b           L_800BBC54
    // 0x800BB00C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB00C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB010:
    // 0x800BB010: lh          $s2, 0x0($s0)
    ctx->r18 = MEM_H(ctx->r16, 0X0);
    // 0x800BB014: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BB018: sb          $zero, 0x5($s1)
    MEM_B(0X5, ctx->r17) = 0;
    // 0x800BB01C: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x800BB020: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x800BB024: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BB028: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB02C: addiu       $s3, $s1, 0x2E
    ctx->r19 = ADD32(ctx->r17, 0X2E);
    // 0x800BB030: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800BB034: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BB038: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x800BB03C: nop

    // 0x800BB040: sll         $t5, $s2, 16
    ctx->r13 = S32(ctx->r18 << 16);
    // 0x800BB044: sra         $s2, $t5, 16
    ctx->r18 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800BB048: negu        $a1, $s2
    ctx->r5 = SUB32(0, ctx->r18);
    // 0x800BB04C: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800BB050: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800BB054: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x800BB058: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800BB05C: jal         0x800EFA6C
    // 0x800BB060: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    func_800EFA6C(rdram, ctx);
        goto after_3;
    // 0x800BB060: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    after_3:
    // 0x800BB064: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800BB068: sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18 << 16);
    // 0x800BB06C: sll         $a3, $s2, 16
    ctx->r7 = S32(ctx->r18 << 16);
    // 0x800BB070: sra         $t2, $a3, 16
    ctx->r10 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800BB074: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800BB078: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800BB07C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800BB080: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800BB084: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x800BB088: jal         0x800EFA6C
    // 0x800BB08C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFA6C(rdram, ctx);
        goto after_4;
    // 0x800BB08C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x800BB090: b           L_800BBC54
    // 0x800BB094: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB094: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB098:
    // 0x800BB098: sb          $v1, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r3;
    // 0x800BB09C: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800BB0A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB0A4: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800BB0A8: nop

    // 0x800BB0AC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB0B0: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BB0B4: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BB0B8: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800BB0BC: nop

    // 0x800BB0C0: sh          $t5, 0x28($s1)
    MEM_H(0X28, ctx->r17) = ctx->r13;
    // 0x800BB0C4: lh          $t6, -0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, -0X2);
    // 0x800BB0C8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800BB0CC: nop

    // 0x800BB0D0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB0D4: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800BB0D8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BB0DC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800BB0E0: b           L_800BBC54
    // 0x800BB0E4: sh          $t8, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r24;
        goto L_800BBC54;
    // 0x800BB0E4: sh          $t8, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r24;
L_800BB0E8:
    // 0x800BB0E8: sb          $v1, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r3;
    // 0x800BB0EC: lwc1        $f12, 0x54($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800BB0F0: jal         0x800DC178
    // 0x800BB0F4: lwc1        $f14, 0x58($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X58);
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x800BB0F4: lwc1        $f14, 0x58($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X58);
    after_5:
    // 0x800BB0F8: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x800BB0FC: b           L_800BBC54
    // 0x800BB100: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB100: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB104:
    // 0x800BB104: andi        $a0, $v0, 0xFF00
    ctx->r4 = ctx->r2 & 0XFF00;
    // 0x800BB108: sra         $t9, $a0, 8
    ctx->r25 = S32(SIGNED(ctx->r4) >> 8);
    // 0x800BB10C: jal         0x800B53A4
    // 0x800BB110: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800B53A4(rdram, ctx);
        goto after_6;
    // 0x800BB110: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_6:
    // 0x800BB114: beq         $s6, $zero, L_800BB128
    if (ctx->r22 == 0) {
        // 0x800BB118: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800BB128;
    }
    // 0x800BB118: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800BB11C: addiu       $a0, $v0, 0x12
    ctx->r4 = ADD32(ctx->r2, 0X12);
    // 0x800BB120: jal         0x800EE940
    // 0x800BB124: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EE940(rdram, ctx);
        goto after_7;
    // 0x800BB124: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_7:
L_800BB128:
    // 0x800BB128: b           L_800BBC54
    // 0x800BB12C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB12C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB130:
    // 0x800BB130: andi        $a0, $v0, 0xFF00
    ctx->r4 = ctx->r2 & 0XFF00;
    // 0x800BB134: sra         $t0, $a0, 8
    ctx->r8 = S32(SIGNED(ctx->r4) >> 8);
    // 0x800BB138: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800BB13C: jal         0x800B53A4
    // 0x800BB140: sw          $t0, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r8;
    func_800B53A4(rdram, ctx);
        goto after_8;
    // 0x800BB140: sw          $t0, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r8;
    after_8:
    // 0x800BB144: beq         $s6, $zero, L_800BB158
    if (ctx->r22 == 0) {
        // 0x800BB148: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800BB158;
    }
    // 0x800BB148: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800BB14C: addiu       $a0, $v0, 0x12
    ctx->r4 = ADD32(ctx->r2, 0X12);
    // 0x800BB150: jal         0x800EE940
    // 0x800BB154: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EE940(rdram, ctx);
        goto after_9;
    // 0x800BB154: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_9:
L_800BB158:
    // 0x800BB158: b           L_800BBC54
    // 0x800BB15C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB15C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB160:
    // 0x800BB160: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800BB164: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x800BB168: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x800BB16C: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800BB170: jal         0x800EFA6C
    // 0x800BB174: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    func_800EFA6C(rdram, ctx);
        goto after_10;
    // 0x800BB174: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    after_10:
    // 0x800BB178: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800BB17C: b           L_800BBC54
    // 0x800BB180: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB180: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB184:
    // 0x800BB184: andi        $t1, $v0, 0xFF00
    ctx->r9 = ctx->r2 & 0XFF00;
    // 0x800BB188: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x800BB18C: beq         $t2, $zero, L_800BB19C
    if (ctx->r10 == 0) {
        // 0x800BB190: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800BB19C;
    }
    // 0x800BB190: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB194: b           L_800BBC54
    // 0x800BB198: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
        goto L_800BBC54;
    // 0x800BB198: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
L_800BB19C:
    // 0x800BB19C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800BB1A0: b           L_800BBC58
    // 0x800BB1A4: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
        goto L_800BBC58;
    // 0x800BB1A4: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
L_800BB1A8:
    // 0x800BB1A8: addiu       $t3, $zero, 0x586
    ctx->r11 = ADD32(0, 0X586);
    // 0x800BB1AC: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
    // 0x800BB1B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800BB1B4: lwc1        $f18, 0x579C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X579C);
    // 0x800BB1B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800BB1BC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800BB1C0: addiu       $t5, $zero, 0x300
    ctx->r13 = ADD32(0, 0X300);
    // 0x800BB1C4: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x800BB1C8: sh          $t4, 0xA8($s1)
    MEM_H(0XA8, ctx->r17) = ctx->r12;
    // 0x800BB1CC: sh          $t5, 0xA2($s1)
    MEM_H(0XA2, ctx->r17) = ctx->r13;
    // 0x800BB1D0: sh          $t6, 0xA4($s1)
    MEM_H(0XA4, ctx->r17) = ctx->r14;
    // 0x800BB1D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800BB1D8: swc1        $f18, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->f18.u32l;
    // 0x800BB1DC: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
    // 0x800BB1E0: lwc1        $f4, 0x57A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X57A0);
    // 0x800BB1E4: addiu       $t7, $s1, 0x34
    ctx->r15 = ADD32(ctx->r17, 0X34);
    // 0x800BB1E8: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    // 0x800BB1EC: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x800BB1F0: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x800BB1F4: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x800BB1F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BB1FC: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x800BB200: addiu       $s2, $s1, 0x46
    ctx->r18 = ADD32(ctx->r17, 0X46);
    // 0x800BB204: jal         0x800EFA6C
    // 0x800BB208: addiu       $s3, $s1, 0x3A
    ctx->r19 = ADD32(ctx->r17, 0X3A);
    func_800EFA6C(rdram, ctx);
        goto after_11;
    // 0x800BB208: addiu       $s3, $s1, 0x3A
    ctx->r19 = ADD32(ctx->r17, 0X3A);
    after_11:
    // 0x800BB20C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BB210: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x800BB214: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BB218: jal         0x800EFA6C
    // 0x800BB21C: addiu       $a3, $zero, 0x190
    ctx->r7 = ADD32(0, 0X190);
    func_800EFA6C(rdram, ctx);
        goto after_12;
    // 0x800BB21C: addiu       $a3, $zero, 0x190
    ctx->r7 = ADD32(0, 0X190);
    after_12:
    // 0x800BB220: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x800BB224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BB228: addiu       $a2, $zero, -0x3E8
    ctx->r6 = ADD32(0, -0X3E8);
    // 0x800BB22C: jal         0x800EFA6C
    // 0x800BB230: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800EFA6C(rdram, ctx);
        goto after_13;
    // 0x800BB230: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x800BB234: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800BB238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BB23C: addiu       $a2, $zero, -0x320
    ctx->r6 = ADD32(0, -0X320);
    // 0x800BB240: jal         0x800EFA6C
    // 0x800BB244: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800EFA6C(rdram, ctx);
        goto after_14;
    // 0x800BB244: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x800BB248: b           L_800BBC54
    // 0x800BB24C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB24C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB250:
    // 0x800BB250: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800BB254: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x800BB258: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB25C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800BB260: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800BB264: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB268: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BB26C: mul.s       $f0, $f10, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800BB270: nop

    // 0x800BB274: mul.s       $f2, $f6, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800BB278: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x800BB27C: b           L_800BBC54
    // 0x800BB280: swc1        $f2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f2.u32l;
        goto L_800BBC54;
    // 0x800BB280: swc1        $f2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f2.u32l;
L_800BB284:
    // 0x800BB284: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x800BB288: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BB28C: b           L_800BBC54
    // 0x800BB290: sh          $t0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r8;
        goto L_800BBC54;
    // 0x800BB290: sh          $t0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r8;
L_800BB294:
    // 0x800BB294: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x800BB298: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BB29C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800BB2A0: nop

    // 0x800BB2A4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB2A8: mul.s       $f12, $f8, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800BB2AC: jal         0x800DC298
    // 0x800BB2B0: nop

    func_800DC298(rdram, ctx);
        goto after_15;
    // 0x800BB2B0: nop

    after_15:
    // 0x800BB2B4: beq         $v0, $zero, L_800BB2C8
    if (ctx->r2 == 0) {
        // 0x800BB2B8: nop
    
            goto L_800BB2C8;
    }
    // 0x800BB2B8: nop

    // 0x800BB2BC: lhu         $t2, 0x0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X0);
    // 0x800BB2C0: ori         $t3, $t2, 0x800
    ctx->r11 = ctx->r10 | 0X800;
    // 0x800BB2C4: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
L_800BB2C8:
    // 0x800BB2C8: b           L_800BBC54
    // 0x800BB2CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB2CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB2D0:
    // 0x800BB2D0: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x800BB2D4: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800BB2D8: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x800BB2DC: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800BB2E0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800BB2E4: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BB2E8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB2EC: sh          $v1, 0x86($s1)
    MEM_H(0X86, ctx->r17) = ctx->r3;
    // 0x800BB2F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800BB2F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BB2F8: sh          $v0, 0x84($s1)
    MEM_H(0X84, ctx->r17) = ctx->r2;
    // 0x800BB2FC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB300: mul.s       $f0, $f18, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800BB304: nop

    // 0x800BB308: mul.s       $f2, $f4, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800BB30C: swc1        $f0, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f0.u32l;
    // 0x800BB310: b           L_800BBC54
    // 0x800BB314: swc1        $f2, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f2.u32l;
        goto L_800BBC54;
    // 0x800BB314: swc1        $f2, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f2.u32l;
L_800BB318:
    // 0x800BB318: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x800BB31C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BB320: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB324: sh          $v1, 0x86($s1)
    MEM_H(0X86, ctx->r17) = ctx->r3;
    // 0x800BB328: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BB32C: b           L_800BBC54
    // 0x800BB330: sh          $v0, 0x84($s1)
    MEM_H(0X84, ctx->r17) = ctx->r2;
        goto L_800BBC54;
    // 0x800BB330: sh          $v0, 0x84($s1)
    MEM_H(0X84, ctx->r17) = ctx->r2;
L_800BB334:
    // 0x800BB334: andi        $a1, $v0, 0xFF00
    ctx->r5 = ctx->r2 & 0XFF00;
    // 0x800BB338: sra         $t6, $a1, 8
    ctx->r14 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800BB33C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800BB340: jal         0x800BA22C
    // 0x800BB344: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BA22C(rdram, ctx);
        goto after_16;
    // 0x800BB344: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x800BB348: b           L_800BBC54
    // 0x800BB34C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB34C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB350:
    // 0x800BB350: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800BB354: addiu       $a0, $s1, 0x34
    ctx->r4 = ADD32(ctx->r17, 0X34);
    // 0x800BB358: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BB35C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800BB360: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BB364: addiu       $s3, $s1, 0x3A
    ctx->r19 = ADD32(ctx->r17, 0X3A);
    // 0x800BB368: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB36C: mul.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800BB370: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BB374: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BB378: nop

    // 0x800BB37C: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x800BB380: jal         0x800EFA6C
    // 0x800BB384: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    func_800EFA6C(rdram, ctx);
        goto after_17;
    // 0x800BB384: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    after_17:
    // 0x800BB388: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x800BB38C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800BB390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BB394: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800BB398: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BB39C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB3A0: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x800BB3A4: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BB3A8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800BB3AC: nop

    // 0x800BB3B0: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x800BB3B4: jal         0x800EFA6C
    // 0x800BB3B8: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    func_800EFA6C(rdram, ctx);
        goto after_18;
    // 0x800BB3B8: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    after_18:
    // 0x800BB3BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB3C0: b           L_800BBC54
    // 0x800BB3C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB3C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB3C8:
    // 0x800BB3C8: andi        $a0, $v0, 0xFF00
    ctx->r4 = ctx->r2 & 0XFF00;
    // 0x800BB3CC: sra         $t5, $a0, 8
    ctx->r13 = S32(SIGNED(ctx->r4) >> 8);
    // 0x800BB3D0: jal         0x800BA2E8
    // 0x800BB3D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_800BA2E8(rdram, ctx);
        goto after_19;
    // 0x800BB3D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_19:
    // 0x800BB3D8: beq         $s6, $zero, L_800BB3EC
    if (ctx->r22 == 0) {
        // 0x800BB3DC: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800BB3EC;
    }
    // 0x800BB3DC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800BB3E0: addiu       $a0, $v0, 0x12
    ctx->r4 = ADD32(ctx->r2, 0X12);
    // 0x800BB3E4: jal         0x800EE940
    // 0x800BB3E8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EE940(rdram, ctx);
        goto after_20;
    // 0x800BB3E8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_20:
L_800BB3EC:
    // 0x800BB3EC: b           L_800BBC54
    // 0x800BB3F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB3F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB3F4:
    // 0x800BB3F4: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BB3F8: lhu         $t6, 0x2($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X2);
    // 0x800BB3FC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BB400: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800BB404: beql        $v0, $t6, L_800BBC58
    if (ctx->r2 == ctx->r14) {
        // 0x800BB408: lh          $v0, 0x0($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X0);
            goto L_800BBC58;
    }
    goto skip_2;
    // 0x800BB408: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    skip_2:
    // 0x800BB40C: jal         0x800D738C
    // 0x800BB410: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    func_800D738C(rdram, ctx);
        goto after_21;
    // 0x800BB410: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    after_21:
    // 0x800BB414: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x800BB418: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800BB41C: bne         $t7, $at, L_800BB438
    if (ctx->r15 != ctx->r1) {
        // 0x800BB420: sb          $v0, 0xA($s1)
        MEM_B(0XA, ctx->r17) = ctx->r2;
            goto L_800BB438;
    }
    // 0x800BB420: sb          $v0, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r2;
    // 0x800BB424: jal         0x800D674C
    // 0x800BB428: lhu         $a0, 0x2($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X2);
    func_800D674C(rdram, ctx);
        goto after_22;
    // 0x800BB428: lhu         $a0, 0x2($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X2);
    after_22:
    // 0x800BB42C: jal         0x800AF5A0
    // 0x800BB430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AF5A0(rdram, ctx);
        goto after_23;
    // 0x800BB430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x800BB434: sb          $v0, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r2;
L_800BB438:
    // 0x800BB438: b           L_800BBC54
    // 0x800BB43C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB43C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB440:
    // 0x800BB440: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800BB444: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x800BB448: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800BB44C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BB450: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB454: jal         0x800DC178
    // 0x800BB458: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800DC178(rdram, ctx);
        goto after_24;
    // 0x800BB458: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_24:
    // 0x800BB45C: mul.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800BB460: lh          $t0, 0x14($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X14);
    // 0x800BB464: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB468: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BB46C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BB470: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800BB474: nop

    // 0x800BB478: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800BB47C: b           L_800BBC54
    // 0x800BB480: sh          $t5, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r13;
        goto L_800BBC54;
    // 0x800BB480: sh          $t5, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r13;
L_800BB484:
    // 0x800BB484: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BB488: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x800BB48C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB490: andi        $a1, $v0, 0xFF00
    ctx->r5 = ctx->r2 & 0XFF00;
    // 0x800BB494: andi        $a3, $v1, 0xFF00
    ctx->r7 = ctx->r3 & 0XFF00;
    // 0x800BB498: srl         $t7, $a3, 8
    ctx->r15 = S32(U32(ctx->r7) >> 8);
    // 0x800BB49C: srl         $t6, $a1, 8
    ctx->r14 = S32(U32(ctx->r5) >> 8);
    // 0x800BB4A0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800BB4A4: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800BB4A8: addiu       $a0, $s1, 0x80
    ctx->r4 = ADD32(ctx->r17, 0X80);
    // 0x800BB4AC: jal         0x800F31EC
    // 0x800BB4B0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_800F31EC(rdram, ctx);
        goto after_25;
    // 0x800BB4B0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_25:
    // 0x800BB4B4: b           L_800BBC54
    // 0x800BB4B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB4B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB4BC:
    // 0x800BB4BC: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BB4C0: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x800BB4C4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB4C8: andi        $a1, $v0, 0xFF00
    ctx->r5 = ctx->r2 & 0XFF00;
    // 0x800BB4CC: andi        $a3, $v1, 0xFF00
    ctx->r7 = ctx->r3 & 0XFF00;
    // 0x800BB4D0: srl         $t9, $a3, 8
    ctx->r25 = S32(U32(ctx->r7) >> 8);
    // 0x800BB4D4: srl         $t8, $a1, 8
    ctx->r24 = S32(U32(ctx->r5) >> 8);
    // 0x800BB4D8: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x800BB4DC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800BB4E0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800BB4E4: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800BB4E8: addiu       $a0, $s1, 0x80
    ctx->r4 = ADD32(ctx->r17, 0X80);
    // 0x800BB4EC: jal         0x800F31FC
    // 0x800BB4F0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_800F31FC(rdram, ctx);
        goto after_26;
    // 0x800BB4F0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_26:
    // 0x800BB4F4: b           L_800BBC54
    // 0x800BB4F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB4F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB4FC:
    // 0x800BB4FC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800BB500: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x800BB504: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x800BB508: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800BB50C: jal         0x800EFA6C
    // 0x800BB510: addiu       $a0, $s1, 0x4C
    ctx->r4 = ADD32(ctx->r17, 0X4C);
    func_800EFA6C(rdram, ctx);
        goto after_27;
    // 0x800BB510: addiu       $a0, $s1, 0x4C
    ctx->r4 = ADD32(ctx->r17, 0X4C);
    after_27:
    // 0x800BB514: b           L_800BBC54
    // 0x800BB518: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB518: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB51C:
    // 0x800BB51C: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x800BB520: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x800BB524: lh          $t0, 0x4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4);
    // 0x800BB528: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800BB52C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800BB530: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x800BB534: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BB538: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800BB53C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800BB540: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB544: mul.s       $f0, $f6, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800BB548: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800BB54C: mul.s       $f2, $f8, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800BB550: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB554: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB558: mul.s       $f12, $f18, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800BB55C: nop

    // 0x800BB560: mul.s       $f14, $f4, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800BB564: nop

    // 0x800BB568: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800BB56C: nop

    // 0x800BB570: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800BB574: nop

    // 0x800BB578: mul.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800BB57C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BB580: mul.s       $f4, $f6, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800BB584: nop

    // 0x800BB588: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800BB58C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800BB590: nop

    // 0x800BB594: sh          $t6, 0x9A($s1)
    MEM_H(0X9A, ctx->r17) = ctx->r14;
    // 0x800BB598: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BB59C: mul.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x800BB5A0: nop

    // 0x800BB5A4: mul.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800BB5A8: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800BB5AC: nop

    // 0x800BB5B0: sh          $t8, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r24;
    // 0x800BB5B4: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BB5B8: mul.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x800BB5BC: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800BB5C0: nop

    // 0x800BB5C4: sh          $t1, 0x9E($s1)
    MEM_H(0X9E, ctx->r17) = ctx->r9;
    // 0x800BB5C8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BB5CC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800BB5D0: b           L_800BBC54
    // 0x800BB5D4: sh          $t3, 0xA0($s1)
    MEM_H(0XA0, ctx->r17) = ctx->r11;
        goto L_800BBC54;
    // 0x800BB5D4: sh          $t3, 0xA0($s1)
    MEM_H(0XA0, ctx->r17) = ctx->r11;
L_800BB5D8:
    // 0x800BB5D8: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x800BB5DC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BB5E0: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800BB5E4: nop

    // 0x800BB5E8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BB5EC: mul.s       $f0, $f6, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800BB5F0: nop

    // 0x800BB5F4: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800BB5F8: nop

    // 0x800BB5FC: mul.s       $f0, $f4, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x800BB600: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800BB604: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800BB608: nop

    // 0x800BB60C: sh          $v0, 0x9A($s1)
    MEM_H(0X9A, ctx->r17) = ctx->r2;
    // 0x800BB610: sh          $v0, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r2;
    // 0x800BB614: sh          $v0, 0x9E($s1)
    MEM_H(0X9E, ctx->r17) = ctx->r2;
    // 0x800BB618: b           L_800BBC54
    // 0x800BB61C: sh          $v0, 0xA0($s1)
    MEM_H(0XA0, ctx->r17) = ctx->r2;
        goto L_800BBC54;
    // 0x800BB61C: sh          $v0, 0xA0($s1)
    MEM_H(0XA0, ctx->r17) = ctx->r2;
L_800BB620:
    // 0x800BB620: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x800BB624: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x800BB628: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB62C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800BB630: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800BB634: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB638: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB63C: mul.s       $f0, $f18, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800BB640: nop

    // 0x800BB644: mul.s       $f2, $f4, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800BB648: nop

    // 0x800BB64C: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800BB650: nop

    // 0x800BB654: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800BB658: nop

    // 0x800BB65C: mul.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800BB660: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BB664: mul.s       $f4, $f6, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800BB668: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800BB66C: nop

    // 0x800BB670: sh          $t8, 0x9A($s1)
    MEM_H(0X9A, ctx->r17) = ctx->r24;
    // 0x800BB674: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BB678: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800BB67C: b           L_800BBC54
    // 0x800BB680: sh          $t1, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r9;
        goto L_800BBC54;
    // 0x800BB680: sh          $t1, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r9;
L_800BB684:
    // 0x800BB684: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x800BB688: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x800BB68C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB690: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800BB694: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800BB698: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB69C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB6A0: mul.s       $f0, $f18, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800BB6A4: nop

    // 0x800BB6A8: mul.s       $f2, $f4, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800BB6AC: nop

    // 0x800BB6B0: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800BB6B4: nop

    // 0x800BB6B8: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800BB6BC: nop

    // 0x800BB6C0: mul.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800BB6C4: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BB6C8: mul.s       $f4, $f6, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800BB6CC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800BB6D0: nop

    // 0x800BB6D4: sh          $t4, 0x9E($s1)
    MEM_H(0X9E, ctx->r17) = ctx->r12;
    // 0x800BB6D8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BB6DC: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800BB6E0: b           L_800BBC54
    // 0x800BB6E4: sh          $t6, 0xA0($s1)
    MEM_H(0XA0, ctx->r17) = ctx->r14;
        goto L_800BBC54;
    // 0x800BB6E4: sh          $t6, 0xA0($s1)
    MEM_H(0XA0, ctx->r17) = ctx->r14;
L_800BB6E8:
    // 0x800BB6E8: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    // 0x800BB6EC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800BB6F0: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x800BB6F4: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x800BB6F8: jal         0x800EFA6C
    // 0x800BB6FC: addiu       $s2, $s1, 0x46
    ctx->r18 = ADD32(ctx->r17, 0X46);
    func_800EFA6C(rdram, ctx);
        goto after_28;
    // 0x800BB6FC: addiu       $s2, $s1, 0x46
    ctx->r18 = ADD32(ctx->r17, 0X46);
    after_28:
    // 0x800BB700: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BB704: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    // 0x800BB708: lh          $a2, 0x8($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X8);
    // 0x800BB70C: jal         0x800EFA6C
    // 0x800BB710: lh          $a3, 0xA($s0)
    ctx->r7 = MEM_H(ctx->r16, 0XA);
    func_800EFA6C(rdram, ctx);
        goto after_29;
    // 0x800BB710: lh          $a3, 0xA($s0)
    ctx->r7 = MEM_H(ctx->r16, 0XA);
    after_29:
    // 0x800BB714: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800BB718: b           L_800BBC54
    // 0x800BB71C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB71C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB720:
    // 0x800BB720: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    // 0x800BB724: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800BB728: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BB72C: lh          $a3, 0x2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2);
    // 0x800BB730: jal         0x800EFA6C
    // 0x800BB734: addiu       $s2, $s1, 0x46
    ctx->r18 = ADD32(ctx->r17, 0X46);
    func_800EFA6C(rdram, ctx);
        goto after_30;
    // 0x800BB734: addiu       $s2, $s1, 0x46
    ctx->r18 = ADD32(ctx->r17, 0X46);
    after_30:
    // 0x800BB738: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BB73C: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x800BB740: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BB744: jal         0x800EFA6C
    // 0x800BB748: lh          $a3, 0x6($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X6);
    func_800EFA6C(rdram, ctx);
        goto after_31;
    // 0x800BB748: lh          $a3, 0x6($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X6);
    after_31:
    // 0x800BB74C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800BB750: b           L_800BBC54
    // 0x800BB754: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB754: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB758:
    // 0x800BB758: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800BB75C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BB760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BB764: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800BB768: nop

    // 0x800BB76C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB770: mul.s       $f0, $f18, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800BB774: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800BB778: jal         0x800BABA0
    // 0x800BB77C: nop

    func_800BABA0(rdram, ctx);
        goto after_32;
    // 0x800BB77C: nop

    after_32:
    // 0x800BB780: b           L_800BBC54
    // 0x800BB784: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB784: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB788:
    // 0x800BB788: jal         0x800B5534
    // 0x800BB78C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B5534(rdram, ctx);
        goto after_33;
    // 0x800BB78C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_33:
    // 0x800BB790: b           L_800BBC54
    // 0x800BB794: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB794: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB798:
    // 0x800BB798: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800BB79C: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x800BB7A0: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    // 0x800BB7A4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800BB7A8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800BB7AC: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x800BB7B0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB7B4: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800BB7B8: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BB7BC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800BB7C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB7C4: mul.s       $f12, $f4, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800BB7C8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800BB7CC: mul.s       $f14, $f10, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800BB7D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BB7D4: swc1        $f12, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f12.u32l;
    // 0x800BB7D8: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x800BB7DC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BB7E0: swc1        $f14, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f14.u32l;
    // 0x800BB7E4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB7E8: mul.s       $f2, $f6, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800BB7EC: nop

    // 0x800BB7F0: mul.s       $f16, $f8, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800BB7F4: bc1t        L_800BB80C
    if (c1cs) {
        // 0x800BB7F8: nop
    
            goto L_800BB80C;
    }
    // 0x800BB7F8: nop

    // 0x800BB7FC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800BB800: nop

    // 0x800BB804: bc1f        L_800BB828
    if (!c1cs) {
        // 0x800BB808: nop
    
            goto L_800BB828;
    }
    // 0x800BB808: nop

L_800BB80C:
    // 0x800BB80C: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    // 0x800BB810: jal         0x800DC178
    // 0x800BB814: swc1        $f16, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_34;
    // 0x800BB814: swc1        $f16, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f16.u32l;
    after_34:
    // 0x800BB818: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB81C: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800BB820: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x800BB824: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB828:
    // 0x800BB828: mul.s       $f18, $f2, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x800BB82C: nop

    // 0x800BB830: mul.s       $f4, $f16, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x800BB834: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BB838: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BB83C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800BB840: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800BB844: sh          $t0, 0xA2($s1)
    MEM_H(0XA2, ctx->r17) = ctx->r8;
    // 0x800BB848: b           L_800BBC54
    // 0x800BB84C: sh          $t5, 0xA4($s1)
    MEM_H(0XA4, ctx->r17) = ctx->r13;
        goto L_800BBC54;
    // 0x800BB84C: sh          $t5, 0xA4($s1)
    MEM_H(0XA4, ctx->r17) = ctx->r13;
L_800BB850:
    // 0x800BB850: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800BB854: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x800BB858: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB85C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800BB860: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800BB864: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB868: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB86C: mul.s       $f0, $f18, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800BB870: nop

    // 0x800BB874: mul.s       $f2, $f4, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800BB878: nop

    // 0x800BB87C: mul.s       $f8, $f0, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800BB880: nop

    // 0x800BB884: mul.s       $f18, $f2, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x800BB888: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BB88C: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BB890: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BB894: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800BB898: sh          $t9, 0xA2($s1)
    MEM_H(0XA2, ctx->r17) = ctx->r25;
    // 0x800BB89C: b           L_800BBC54
    // 0x800BB8A0: sh          $t2, 0xA4($s1)
    MEM_H(0XA4, ctx->r17) = ctx->r10;
        goto L_800BBC54;
    // 0x800BB8A0: sh          $t2, 0xA4($s1)
    MEM_H(0XA4, ctx->r17) = ctx->r10;
L_800BB8A4:
    // 0x800BB8A4: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x800BB8A8: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800BB8AC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800BB8B0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800BB8B4: nop

    // 0x800BB8B8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB8BC: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x800BB8C0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BB8C4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800BB8C8: nop

    // 0x800BB8CC: sh          $t4, 0xC4($s1)
    MEM_H(0XC4, ctx->r17) = ctx->r12;
    // 0x800BB8D0: lh          $t5, -0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, -0XA);
    // 0x800BB8D4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800BB8D8: nop

    // 0x800BB8DC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB8E0: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800BB8E4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BB8E8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800BB8EC: nop

    // 0x800BB8F0: sh          $t7, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r15;
    // 0x800BB8F4: lh          $t8, -0x8($s0)
    ctx->r24 = MEM_H(ctx->r16, -0X8);
    // 0x800BB8F8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800BB8FC: nop

    // 0x800BB900: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BB904: mul.s       $f4, $f6, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800BB908: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BB90C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800BB910: nop

    // 0x800BB914: sh          $t1, 0xC8($s1)
    MEM_H(0XC8, ctx->r17) = ctx->r9;
    // 0x800BB918: lh          $t2, -0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, -0X6);
    // 0x800BB91C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800BB920: nop

    // 0x800BB924: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB928: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800BB92C: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800BB930: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800BB934: nop

    // 0x800BB938: sh          $t0, 0xCA($s1)
    MEM_H(0XCA, ctx->r17) = ctx->r8;
    // 0x800BB93C: lh          $t4, -0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, -0X4);
    // 0x800BB940: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800BB944: nop

    // 0x800BB948: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB94C: mul.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800BB950: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BB954: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800BB958: nop

    // 0x800BB95C: sh          $t6, 0xCC($s1)
    MEM_H(0XCC, ctx->r17) = ctx->r14;
    // 0x800BB960: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x800BB964: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BB968: nop

    // 0x800BB96C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB970: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x800BB974: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BB978: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800BB97C: b           L_800BBC54
    // 0x800BB980: sh          $t9, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r25;
        goto L_800BBC54;
    // 0x800BB980: sh          $t9, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r25;
L_800BB984:
    // 0x800BB984: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800BB988: sb          $t1, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r9;
    // 0x800BB98C: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x800BB990: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BB994: addiu       $a0, $s1, 0xC8
    ctx->r4 = ADD32(ctx->r17, 0XC8);
    // 0x800BB998: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800BB99C: nop

    // 0x800BB9A0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB9A4: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800BB9A8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BB9AC: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800BB9B0: nop

    // 0x800BB9B4: sh          $t0, 0xC4($s1)
    MEM_H(0XC4, ctx->r17) = ctx->r8;
    // 0x800BB9B8: lh          $t4, -0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, -0X2);
    // 0x800BB9BC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800BB9C0: nop

    // 0x800BB9C4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BB9C8: mul.s       $f4, $f6, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800BB9CC: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BB9D0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800BB9D4: nop

    // 0x800BB9D8: sh          $t6, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r14;
    // 0x800BB9DC: jal         0x800EE940
    // 0x800BB9E0: lw          $a1, 0x190($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X190);
    func_800EE940(rdram, ctx);
        goto after_35;
    // 0x800BB9E0: lw          $a1, 0x190($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X190);
    after_35:
    // 0x800BB9E4: b           L_800BBC54
    // 0x800BB9E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800BBC54;
    // 0x800BB9E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BB9EC:
    // 0x800BB9EC: sb          $v1, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r3;
    // 0x800BB9F0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800BB9F4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800BB9F8: sh          $t7, 0xC8($s1)
    MEM_H(0XC8, ctx->r17) = ctx->r15;
    // 0x800BB9FC: lh          $t8, -0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, -0XA);
    // 0x800BBA00: sh          $t8, 0xC4($s1)
    MEM_H(0XC4, ctx->r17) = ctx->r24;
    // 0x800BBA04: lh          $t9, -0x8($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X8);
    // 0x800BBA08: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800BBA0C: nop

    // 0x800BBA10: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBA14: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800BBA18: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800BBA1C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800BBA20: nop

    // 0x800BBA24: sh          $t2, 0xCC($s1)
    MEM_H(0XCC, ctx->r17) = ctx->r10;
    // 0x800BBA28: lh          $t3, -0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, -0X6);
    // 0x800BBA2C: sh          $t3, 0xCA($s1)
    MEM_H(0XCA, ctx->r17) = ctx->r11;
    // 0x800BBA30: lh          $t0, -0x4($s0)
    ctx->r8 = MEM_H(ctx->r16, -0X4);
    // 0x800BBA34: sh          $t0, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r8;
    // 0x800BBA38: lh          $t4, -0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, -0X2);
    // 0x800BBA3C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800BBA40: nop

    // 0x800BBA44: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BBA48: mul.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800BBA4C: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BBA50: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800BBA54: b           L_800BBC54
    // 0x800BBA58: sh          $t6, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r14;
        goto L_800BBC54;
    // 0x800BBA58: sh          $t6, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r14;
L_800BBA5C:
    // 0x800BBA5C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800BBA60: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x800BBA64: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x800BBA68: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BBA6C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BBA70: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x800BBA74: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBA78: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BBA7C: addiu       $s0, $s0, 0xE
    ctx->r16 = ADD32(ctx->r16, 0XE);
    // 0x800BBA80: addiu       $a0, $s1, 0x6C
    ctx->r4 = ADD32(ctx->r17, 0X6C);
    // 0x800BBA84: addiu       $s2, $s1, 0x60
    ctx->r18 = ADD32(ctx->r17, 0X60);
    // 0x800BBA88: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBA8C: mul.s       $f0, $f8, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800BBA90: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800BBA94: mul.s       $f2, $f18, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800BBA98: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BBA9C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BBAA0: mul.s       $f12, $f4, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800BBAA4: nop

    // 0x800BBAA8: mul.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800BBAAC: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x800BBAB0: lh          $t2, -0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, -0X6);
    // 0x800BBAB4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800BBAB8: nop

    // 0x800BBABC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BBAC0: mul.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800BBAC4: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x800BBAC8: lh          $t3, -0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, -0X4);
    // 0x800BBACC: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800BBAD0: nop

    // 0x800BBAD4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBAD8: mul.s       $f6, $f18, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800BBADC: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x800BBAE0: lh          $t0, -0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, -0X2);
    // 0x800BBAE4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800BBAE8: nop

    // 0x800BBAEC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBAF0: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800BBAF4: nop

    // 0x800BBAF8: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800BBAFC: nop

    // 0x800BBB00: mul.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800BBB04: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x800BBB08: mul.s       $f4, $f12, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800BBB0C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800BBB10: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BBB14: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800BBB18: jal         0x800EFA4C
    // 0x800BBB1C: nop

    func_800EFA4C(rdram, ctx);
        goto after_36;
    // 0x800BBB1C: nop

    after_36:
    // 0x800BBB20: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BBB24: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBB28: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800BBB2C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BBB30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BBB34: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BBB38: nop

    // 0x800BBB3C: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800BBB40: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800BBB44: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BBB48: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800BBB4C: jal         0x800EFA4C
    // 0x800BBB50: nop

    func_800EFA4C(rdram, ctx);
        goto after_37;
    // 0x800BBB50: nop

    after_37:
    // 0x800BBB54: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800BBB58: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BBB5C: b           L_800BBC54
    // 0x800BBB60: swc1        $f10, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f10.u32l;
        goto L_800BBC54;
    // 0x800BBB60: swc1        $f10, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f10.u32l;
L_800BBB64:
    // 0x800BBB64: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x800BBB68: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BBB6C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800BBB70: nop

    // 0x800BBB74: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BBB78: mul.s       $f0, $f6, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800BBB7C: b           L_800BBC54
    // 0x800BBB80: swc1        $f0, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->f0.u32l;
        goto L_800BBC54;
    // 0x800BBB80: swc1        $f0, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->f0.u32l;
L_800BBB84:
    // 0x800BBB84: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800BBB88: jal         0x800DC128
    // 0x800BBB8C: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    func_800DC128(rdram, ctx);
        goto after_38;
    // 0x800BBB8C: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_38:
    // 0x800BBB90: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BBB94: lh          $t5, 0xCA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XCA);
    // 0x800BBB98: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BBB9C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBBA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BBBA4: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800BBBA8: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BBBAC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800BBBB0: nop

    // 0x800BBBB4: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x800BBBB8: b           L_800BBC54
    // 0x800BBBBC: sh          $t1, 0xCA($s1)
    MEM_H(0XCA, ctx->r17) = ctx->r9;
        goto L_800BBC54;
    // 0x800BBBBC: sh          $t1, 0xCA($s1)
    MEM_H(0XCA, ctx->r17) = ctx->r9;
L_800BBBC0:
    // 0x800BBBC0: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x800BBBC4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BBBC8: b           L_800BBC54
    // 0x800BBBCC: sb          $t2, 0x52($s1)
    MEM_B(0X52, ctx->r17) = ctx->r10;
        goto L_800BBC54;
    // 0x800BBBCC: sb          $t2, 0x52($s1)
    MEM_B(0X52, ctx->r17) = ctx->r10;
L_800BBBD0:
    // 0x800BBBD0: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800BBBD4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BBBD8: b           L_800BBC54
    // 0x800BBBDC: sb          $t3, 0x53($s1)
    MEM_B(0X53, ctx->r17) = ctx->r11;
        goto L_800BBC54;
    // 0x800BBBDC: sb          $t3, 0x53($s1)
    MEM_B(0X53, ctx->r17) = ctx->r11;
L_800BBBE0:
    // 0x800BBBE0: sb          $s4, 0x81($s1)
    MEM_B(0X81, ctx->r17) = ctx->r20;
    // 0x800BBBE4: sb          $s4, 0x82($s1)
    MEM_B(0X82, ctx->r17) = ctx->r20;
    // 0x800BBBE8: sb          $s4, 0x83($s1)
    MEM_B(0X83, ctx->r17) = ctx->r20;
    // 0x800BBBEC: sb          $s4, 0x80($s1)
    MEM_B(0X80, ctx->r17) = ctx->r20;
    // 0x800BBBF0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800BBBF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800BBBF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800BBBFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BBC00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BBC04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BBC08: jal         0x800BA930
    // 0x800BBC0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800BA930(rdram, ctx);
        goto after_39;
    // 0x800BBC0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_39:
    // 0x800BBC10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BBC14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BBC18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BBC1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BBC20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800BBC24: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800BBC28: jal         0x800BA450
    // 0x800BBC2C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800BA450(rdram, ctx);
        goto after_40;
    // 0x800BBC2C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_40:
    // 0x800BBC30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BBC34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BBC38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BBC3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BBC40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800BBC44: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800BBC48: jal         0x800BA834
    // 0x800BBC4C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800BA834(rdram, ctx);
        goto after_41;
    // 0x800BBC4C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_41:
    // 0x800BBC50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BBC54:
    // 0x800BBC54: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
L_800BBC58:
    // 0x800BBC58: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800BBC5C: bnel        $v0, $zero, L_800BAC5C
    if (ctx->r2 != 0) {
        // 0x800BBC60: andi        $t6, $v0, 0xFF
        ctx->r14 = ctx->r2 & 0XFF;
            goto L_800BAC5C;
    }
    goto skip_3;
    // 0x800BBC60: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    skip_3:
L_800BBC64:
    // 0x800BBC64: lw          $t0, 0x17C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X17C);
    // 0x800BBC68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BBC6C: beql        $t0, $zero, L_800BBC80
    if (ctx->r8 == 0) {
        // 0x800BBC70: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_800BBC80;
    }
    goto skip_4;
    // 0x800BBC70: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    skip_4:
    // 0x800BBC74: jal         0x800BA22C
    // 0x800BBC78: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_800BA22C(rdram, ctx);
        goto after_42;
    // 0x800BBC78: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_42:
    // 0x800BBC7C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_800BBC80:
    // 0x800BBC80: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800BBC84: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800BBC88: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800BBC8C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800BBC90: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800BBC94: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800BBC98: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800BBC9C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800BBCA0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800BBCA4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800BBCA8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800BBCAC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800BBCB0: jr          $ra
    // 0x800BBCB4: addiu       $sp, $sp, 0x188
    ctx->r29 = ADD32(ctx->r29, 0X188);
    return;
    // 0x800BBCB4: addiu       $sp, $sp, 0x188
    ctx->r29 = ADD32(ctx->r29, 0X188);
;}
RECOMP_FUNC void chjigsawbitcont_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800980: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1644, 0XA28) << 16);
    // 0x80800984: jr          $ra
    // 0x80800988: addiu       $v0, $v0, 0xA28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1644, 0XA28));
    return;
    // 0x80800988: addiu       $v0, $v0, 0xA28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1644, 0XA28));
    // 0x8080098C: nop

;}
RECOMP_FUNC void func_8008D370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D378: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D37C: jal         0x800C6E38
    // 0x8008D380: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D380: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x8008D384: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D388: beq         $t6, $zero, L_8008D3A0
    if (ctx->r14 == 0) {
        // 0x8008D38C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D3A0;
    }
    // 0x8008D38C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D390: jal         0x800A3304
    // 0x8008D394: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D394: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D398: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D39C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D3A0:
    // 0x8008D3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D3A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D3A8: jr          $ra
    // 0x8008D3AC: nop

    return;
    // 0x8008D3AC: nop

;}
RECOMP_FUNC void func_80800A24_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A24: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800A28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A34: jal         0x8008CABC
    // 0x80800A38: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800A38: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800A3C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80800A40: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800A44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A48: beq         $v1, $zero, L_80800A78
    if (ctx->r3 == 0) {
        // 0x80800A4C: nop
    
            goto L_80800A78;
    }
    // 0x80800A4C: nop

    // 0x80800A50: beq         $v1, $at, L_80800A94
    if (ctx->r3 == ctx->r1) {
        // 0x80800A54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A94;
    }
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A5C: beq         $v1, $at, L_80800BA8
    if (ctx->r3 == ctx->r1) {
        // 0x80800A60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BA8;
    }
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A68: beql        $v1, $at, L_80800C24
    if (ctx->r3 == ctx->r1) {
        // 0x80800A6C: sw          $v1, 0x160($s0)
        MEM_W(0X160, ctx->r16) = ctx->r3;
            goto L_80800C24;
    }
    goto skip_0;
    // 0x80800A6C: sw          $v1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r3;
    skip_0:
    // 0x80800A70: b           L_80800C24
    // 0x80800A74: sw          $v1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r3;
        goto L_80800C24;
    // 0x80800A74: sw          $v1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r3;
L_80800A78:
    // 0x80800A78: jal         0x8009E0DC
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E0DC(rdram, ctx);
        goto after_1;
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A84: jal         0x80095774
    // 0x80800A88: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x80800A88: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_2:
    // 0x80800A8C: b           L_80800C20
    // 0x80800A90: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
        goto L_80800C20;
    // 0x80800A90: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_80800A94:
    // 0x80800A94: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x80800A98: jal         0x8008CCBC
    // 0x80800A9C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_3;
    // 0x80800A9C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x80800AA0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80800AA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AB4: jal         0x8009FFD8
    // 0x80800AB8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_4;
    // 0x80800AB8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_4:
    // 0x80800ABC: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800AC0: lui         $a3, 0x4583
    ctx->r7 = S32(0X4583 << 16);
    // 0x80800AC4: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ACC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800AD0: jal         0x80084BD0
    // 0x80800AD4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _bafly_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800AD4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_5:
    // 0x80800AD8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800ADC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800AE0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800AEC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800AF0: jal         0x8009C914
    // 0x80800AF4: nop

    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80800AF4: nop

    after_6:
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AFC: jal         0x8009BF5C
    // 0x80800B00: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8009BF5C(rdram, ctx);
        goto after_7;
    // 0x80800B00: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B08: jal         0x8009C4CC
    // 0x80800B0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_8;
    // 0x80800B0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x80800B10: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: jal         0x8009BA9C
    // 0x80800B1C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_8009BA9C(rdram, ctx);
        goto after_9;
    // 0x80800B1C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_9:
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B24: jal         0x800A0CF4
    // 0x80800B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_10;
    // 0x80800B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B30: jal         0x800A4DA4
    // 0x80800B34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800A4DA4(rdram, ctx);
        goto after_11;
    // 0x80800B34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800B38: jal         0x800A4CA8
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_12;
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800B40: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800B44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B48: jal         0x800892B8
    // 0x80800B4C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _ncbadive_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x80800B4C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_13:
    // 0x80800B50: jal         0x800A4CA8
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_14;
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800B58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B5C: jal         0x800892E8
    // 0x80800B60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _ncbafly_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x80800B60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B68: addiu       $a1, $zero, 0x439
    ctx->r5 = ADD32(0, 0X439);
    // 0x80800B6C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800B70: jal         0x8009DF94
    // 0x80800B74: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF94(rdram, ctx);
        goto after_16;
    // 0x80800B74: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_16:
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: jal         0x80095774
    // 0x80800B80: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    baflag_clear(rdram, ctx);
        goto after_17;
    // 0x80800B80: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_17:
    // 0x80800B84: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B8C: jal         0x8009C128
    // 0x80800B90: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_8009C128(rdram, ctx);
        goto after_18;
    // 0x80800B90: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_18:
    // 0x80800B94: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80800B98: jal         0x80085948
    // 0x80800B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _chusefeather_entrypoint_1(rdram, ctx);
        goto after_19;
    // 0x80800B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800BA0: b           L_80800C20
    // 0x80800BA4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
        goto L_80800C20;
    // 0x80800BA4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_80800BA8:
    // 0x80800BA8: jal         0x8009B800
    // 0x80800BAC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    baphysics_set_type(rdram, ctx);
        goto after_20;
    // 0x80800BAC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_20:
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB4: jal         0x800A4DA4
    // 0x80800BB8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800A4DA4(rdram, ctx);
        goto after_21;
    // 0x80800BB8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_21:
    // 0x80800BBC: jal         0x800A4CA8
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_22;
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800BC4: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800BC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BCC: jal         0x800892B8
    // 0x80800BD0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _ncbadive_entrypoint_4(rdram, ctx);
        goto after_23;
    // 0x80800BD0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_23:
    // 0x80800BD4: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80800BD8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800BDC: jal         0x8008B1BC
    // 0x80800BE0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_24;
    // 0x80800BE0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_24:
    // 0x80800BE4: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80800BE8: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BF0: addiu       $a1, $zero, 0x4437
    ctx->r5 = ADD32(0, 0X4437);
    // 0x80800BF4: jal         0x8009DF94
    // 0x80800BF8: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF94(rdram, ctx);
        goto after_25;
    // 0x80800BF8: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_25:
    // 0x80800BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C00: jal         0x80095760
    // 0x80800C04: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    baflag_set(rdram, ctx);
        goto after_26;
    // 0x80800C04: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_26:
    // 0x80800C08: lui         $a2, 0x38D1
    ctx->r6 = S32(0X38D1 << 16);
    // 0x80800C0C: ori         $a2, $a2, 0xB717
    ctx->r6 = ctx->r6 | 0XB717;
    // 0x80800C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C14: jal         0x80085338
    // 0x80800C18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_27;
    // 0x80800C18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80800C1C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_80800C20:
    // 0x80800C20: sw          $v1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r3;
L_80800C24:
    // 0x80800C24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800C30: jr          $ra
    // 0x80800C34: nop

    return;
    // 0x80800C34: nop

;}
RECOMP_FUNC void _idtwinkle_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E08: syscall     742
    recomp_syscall_handler(rdram, ctx, 0x80088E08);
    return;
    // 0x80088E0C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080035C_chstoneballcoach(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800364: jal         0x800DC0C0
    // 0x80800368: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80800368: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080036C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800370: jal         0x80101EE4
    // 0x80800374: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101EE4(rdram, ctx);
        goto after_1;
    // 0x80800374: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080037C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

;}
RECOMP_FUNC void func_8080117C_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080117C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801180: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801184: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80801188: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080118C: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    // 0x80801190: jal         0x80088280
    // 0x80801194: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801194: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80801198: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080119C: jal         0x80088C00
    // 0x808011A0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808011A0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808011A4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x808011A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808011AC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x808011B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808011B4: jal         0x800D1000
    // 0x808011B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_2;
    // 0x808011B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x808011BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808011C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808011C4: jal         0x80802124
    // 0x808011C8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80802124_chpotogoldgame(rdram, ctx);
        goto after_3;
    // 0x808011C8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_3:
    // 0x808011CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808011D4: jr          $ra
    // 0x808011D8: nop

    return;
    // 0x808011D8: nop

;}
RECOMP_FUNC void func_800A0DDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0DDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A0DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A0DE4: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0DE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A0DEC: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800A0DF0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800A0DF4: nop

    // 0x800A0DF8: bc1tl       L_800A0E44
    if (c1cs) {
        // 0x800A0DFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A0E44;
    }
    goto skip_0;
    // 0x800A0DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A0E00: jal         0x800D8FF8
    // 0x800A0E04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800A0E04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A0E08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A0E0C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A0E10: lw          $v0, 0x138($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X138);
    // 0x800A0E14: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A0E18: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A0E1C: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x800A0E20: lw          $v0, 0x138($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X138);
    // 0x800A0E24: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A0E28: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800A0E2C: nop

    // 0x800A0E30: bc1fl       L_800A0E44
    if (!c1cs) {
        // 0x800A0E34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A0E44;
    }
    goto skip_1;
    // 0x800A0E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800A0E38: lbu         $t7, 0xC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC);
    // 0x800A0E3C: sb          $t7, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r15;
    // 0x800A0E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A0E44:
    // 0x800A0E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A0E48: jr          $ra
    // 0x800A0E4C: nop

    return;
    // 0x800A0E4C: nop

;}
RECOMP_FUNC void func_80800544_rtlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800544: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080054C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800550: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800554: jal         0x800C8800
    // 0x80800558: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800C8800(rdram, ctx);
        goto after_0;
    // 0x80800558: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8080055C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800560: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800564: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800568: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8080056C: nop

    // 0x80800570: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80800574: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800578: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080057C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80800580: nop

    // 0x80800584: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80800588: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080058C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800590: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80800594: nop

    // 0x80800598: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    // 0x8080059C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005A4: jr          $ra
    // 0x808005A8: nop

    return;
    // 0x808005A8: nop

;}
RECOMP_FUNC void func_801043D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801043D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801043DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801043E0: lh          $a1, 0x8E($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X8E);
    // 0x801043E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801043E8: bne         $a1, $zero, L_801043F8
    if (ctx->r5 != 0) {
        // 0x801043EC: nop
    
            goto L_801043F8;
    }
    // 0x801043EC: nop

    // 0x801043F0: b           L_80104400
    // 0x801043F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80104400;
    // 0x801043F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801043F8:
    // 0x801043F8: jal         0x800B301C
    // 0x801043FC: lw          $a0, 0x6E80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E80);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x801043FC: lw          $a0, 0x6E80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E80);
    after_0:
L_80104400:
    // 0x80104400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80104408: jr          $ra
    // 0x8010440C: nop

    return;
    // 0x8010440C: nop

;}
RECOMP_FUNC void func_8009561C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009561C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80095620: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80095624: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80095628: jal         0x800F3ED0
    // 0x8009562C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F3ED0(rdram, ctx);
        goto after_0;
    // 0x8009562C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80095630: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80095634: jal         0x8008E078
    // 0x80095638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x80095638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8009563C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80095640: jal         0x8009E6F8
    // 0x80095644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_2;
    // 0x80095644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80095648: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009564C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80095650: bne         $t6, $zero, L_80095688
    if (ctx->r14 != 0) {
        // 0x80095654: nop
    
            goto L_80095688;
    }
    // 0x80095654: nop

    // 0x80095658: jal         0x800F40EC
    // 0x8009565C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800F40EC(rdram, ctx);
        goto after_3;
    // 0x8009565C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x80095660: bne         $v0, $zero, L_80095688
    if (ctx->r2 != 0) {
        // 0x80095664: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80095688;
    }
    // 0x80095664: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80095668: addiu       $at, $zero, 0xBE
    ctx->r1 = ADD32(0, 0XBE);
    // 0x8009566C: beq         $v1, $at, L_80095688
    if (ctx->r3 == ctx->r1) {
        // 0x80095670: addiu       $at, $zero, 0x15C
        ctx->r1 = ADD32(0, 0X15C);
            goto L_80095688;
    }
    // 0x80095670: addiu       $at, $zero, 0x15C
    ctx->r1 = ADD32(0, 0X15C);
    // 0x80095674: beq         $v1, $at, L_80095688
    if (ctx->r3 == ctx->r1) {
        // 0x80095678: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80095688;
    }
    // 0x80095678: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8009567C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80095680: bne         $t7, $at, L_8009569C
    if (ctx->r15 != ctx->r1) {
        // 0x80095684: nop
    
            goto L_8009569C;
    }
    // 0x80095684: nop

L_80095688:
    // 0x80095688: jal         0x800956B8
    // 0x8009568C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800956B8(rdram, ctx);
        goto after_4;
    // 0x8009568C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80095690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80095694: jal         0x80095588
    // 0x80095698: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80095588(rdram, ctx);
        goto after_5;
    // 0x80095698: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_8009569C:
    // 0x8009569C: jal         0x80095490
    // 0x800956A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095490(rdram, ctx);
        goto after_6;
    // 0x800956A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800956A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800956A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800956AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800956B0: jr          $ra
    // 0x800956B4: nop

    return;
    // 0x800956B4: nop

;}
RECOMP_FUNC void bamovehover_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800068: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80800070: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800074: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80800078: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8080007C: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x80800080: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80800084: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800088: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8080008C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800090: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800094: jal         0x800D8FF8
    // 0x80800098: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800098: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x8080009C: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x808000A0: lw          $v0, 0xC8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC8);
    // 0x808000A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000A8: addiu       $a0, $v0, 0xAC
    ctx->r4 = ADD32(ctx->r2, 0XAC);
    // 0x808000AC: jal         0x800EF174
    // 0x808000B0: addiu       $a1, $v0, 0xB8
    ctx->r5 = ADD32(ctx->r2, 0XB8);
    func_800EF174(rdram, ctx);
        goto after_1;
    // 0x808000B0: addiu       $a1, $v0, 0xB8
    ctx->r5 = ADD32(ctx->r2, 0XB8);
    after_1:
    // 0x808000B4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808000B8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x808000BC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808000C0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808000C4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808000C8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808000CC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808000D0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808000D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808000D8: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x808000DC: lw          $t6, 0xC8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0XC8);
L_808000E0:
    // 0x808000E0: addu        $v0, $t6, $s1
    ctx->r2 = ADD32(ctx->r14, ctx->r17);
    // 0x808000E4: lwc1        $f4, 0xAC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x808000E8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808000EC: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808000F0: jal         0x800F2100
    // 0x808000F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x808000F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x808000F8: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x808000FC: addiu       $t7, $sp, 0x80
    ctx->r15 = ADD32(ctx->r29, 0X80);
    // 0x80800100: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800104: addu        $s0, $s1, $t7
    ctx->r16 = ADD32(ctx->r17, ctx->r15);
    // 0x80800108: bc1f        L_8080017C
    if (!c1cs) {
        // 0x8080010C: lui         $at, 0x435C
        ctx->r1 = S32(0X435C << 16);
            goto L_8080017C;
    }
    // 0x8080010C: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80800110: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800114: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800118: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8080011C: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800120: mul.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800124: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80800128: jal         0x800F10B4
    // 0x8080012C: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x8080012C: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    after_3:
    // 0x80800130: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800134: nop

    // 0x80800138: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8080013C: nop

    // 0x80800140: bc1fl       L_80800154
    if (!c1cs) {
        // 0x80800144: neg.s       $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
            goto L_80800154;
    }
    goto skip_0;
    // 0x80800144: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    skip_0:
    // 0x80800148: b           L_80800158
    // 0x8080014C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_80800158;
    // 0x8080014C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80800150: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
L_80800154:
    // 0x80800154: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_80800158:
    // 0x80800158: lw          $t8, 0xC8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XC8);
    // 0x8080015C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800160: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800164: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80800168: jal         0x800F15F8
    // 0x8080016C: lwc1        $f12, 0x10($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X10);
    func_800F15F8(rdram, ctx);
        goto after_4;
    // 0x8080016C: lwc1        $f12, 0x10($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X10);
    after_4:
    // 0x80800170: lw          $t0, 0xC8($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XC8);
    // 0x80800174: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80800178: swc1        $f0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f0.u32l;
L_8080017C:
    // 0x8080017C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800180: bnel        $s1, $s3, L_808000E0
    if (ctx->r17 != ctx->r19) {
        // 0x80800184: lw          $t6, 0xC8($s2)
        ctx->r14 = MEM_W(ctx->r18, 0XC8);
            goto L_808000E0;
    }
    goto skip_1;
    // 0x80800184: lw          $t6, 0xC8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0XC8);
    skip_1:
    // 0x80800188: lw          $v0, 0xC8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC8);
    // 0x8080018C: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x80800190: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800194: jal         0x800EF174
    // 0x80800198: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    func_800EF174(rdram, ctx);
        goto after_5;
    // 0x80800198: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    after_5:
    // 0x8080019C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x808001A0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808001A4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808001A8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808001AC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808001B0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808001B4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x808001B8: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x808001BC: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x808001C0: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x808001C4: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x808001C8: jr          $ra
    // 0x808001CC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x808001CC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80801420_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801420: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80801424: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80801428: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8080142C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80801430: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80801434: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80801438: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8080143C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80801440: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80801444: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80801448: jal         0x80100094
    // 0x8080144C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080144C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801450: lw          $t6, 0x6C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X6C);
    // 0x80801454: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801458: addiu       $s0, $v0, 0x1C
    ctx->r16 = ADD32(ctx->r2, 0X1C);
    // 0x8080145C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80801460: beq         $t7, $zero, L_808014E0
    if (ctx->r15 == 0) {
        // 0x80801464: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1804, 0X1B04) << 16);
            goto L_808014E0;
    }
    // 0x80801464: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1B04) << 16);
    // 0x80801468: lwc1        $f22, 0x1B04($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1B04));
    // 0x8080146C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80801470: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80801474: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x80801478: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
L_8080147C:
    // 0x8080147C: addiu       $s1, $s0, 0x18
    ctx->r17 = ADD32(ctx->r16, 0X18);
    // 0x80801480: addiu       $t8, $s0, 0x24
    ctx->r24 = ADD32(ctx->r16, 0X24);
    // 0x80801484: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80801488: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080148C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80801490: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80801494: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801498: jal         0x80801250
    // 0x8080149C: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    func_80801250_chpiranha(rdram, ctx);
        goto after_1;
    // 0x8080149C: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    after_1:
    // 0x808014A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014A4: jal         0x800EFC7C
    // 0x808014A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_2;
    // 0x808014A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808014AC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x808014B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808014B4: bc1fl       L_808014C8
    if (!c1cs) {
        // 0x808014B8: lw          $t9, 0x6C($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X6C);
            goto L_808014C8;
    }
    goto skip_0;
    // 0x808014B8: lw          $t9, 0x6C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X6C);
    skip_0:
    // 0x808014BC: jal         0x80800DD0
    // 0x808014C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800DD0_chpiranha(rdram, ctx);
        goto after_3;
    // 0x808014C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x808014C4: lw          $t9, 0x6C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X6C);
L_808014C8:
    // 0x808014C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808014CC: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x808014D0: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x808014D4: sltu        $at, $s2, $t0
    ctx->r1 = ctx->r18 < ctx->r8 ? 1 : 0;
    // 0x808014D8: bnel        $at, $zero, L_8080147C
    if (ctx->r1 != 0) {
        // 0x808014DC: lw          $a3, 0x2C($s0)
        ctx->r7 = MEM_W(ctx->r16, 0X2C);
            goto L_8080147C;
    }
    goto skip_1;
    // 0x808014DC: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    skip_1:
L_808014E0:
    // 0x808014E0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x808014E4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x808014E8: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x808014EC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808014F0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808014F4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x808014F8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x808014FC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80801500: jr          $ra
    // 0x80801504: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80801504: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80800940_sudeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800940: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80800944: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800948: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x8080094C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80800950: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800954: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800958: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8080095C: addiu       $s4, $sp, 0x60
    ctx->r20 = ADD32(ctx->r29, 0X60);
    // 0x80800960: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800964: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800968: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8080096C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80800970: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x80800974: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80800978: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8080097C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800980: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800984: lw          $s6, 0x1020($s6)
    ctx->r22 = MEM_W(ctx->r22, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x80800988: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8080098C: jal         0x800EE7F8
    // 0x80800990: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800990: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x80800994: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800998: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8080099C: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x808009A0: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x808009A4: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x808009A8: beql        $a0, $zero, L_80800A68
    if (ctx->r4 == 0) {
        // 0x808009AC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80800A68;
    }
    goto skip_0;
    // 0x808009AC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x808009B0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808009B4: addiu       $s5, $zero, 0x27A
    ctx->r21 = ADD32(0, 0X27A);
L_808009B8:
    // 0x808009B8: jal         0x800E9E88
    // 0x808009BC: nop

    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x808009BC: nop

    after_1:
    // 0x808009C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808009C4: jal         0x800E9EB4
    // 0x808009C8: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x808009C8: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_2:
    // 0x808009CC: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x808009D0: beq         $at, $zero, L_80800A54
    if (ctx->r1 == 0) {
        // 0x808009D4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80800A54;
    }
    // 0x808009D4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808009D8: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
L_808009DC:
    // 0x808009DC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808009E0: beql        $t7, $zero, L_80800A48
    if (ctx->r15 == 0) {
        // 0x808009E4: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800A48;
    }
    goto skip_1;
    // 0x808009E4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x808009E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808009EC: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x808009F0: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x808009F4: bnel        $s5, $t9, L_80800A48
    if (ctx->r21 != ctx->r25) {
        // 0x808009F8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800A48;
    }
    goto skip_2;
    // 0x808009F8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x808009FC: jal         0x80106790
    // 0x80800A00: nop

    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80800A00: nop

    after_3:
    // 0x80800A04: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x80800A08: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A0C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800A10: sll         $t2, $t0, 14
    ctx->r10 = S32(ctx->r8 << 14);
    // 0x80800A14: bltzl       $t2, L_80800A48
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800A18: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800A48;
    }
    goto skip_3;
    // 0x80800A18: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_3:
    // 0x80800A1C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800A20: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800A24: jal         0x800F0008
    // 0x80800A28: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    func_800F0008(rdram, ctx);
        goto after_4;
    // 0x80800A28: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    after_4:
    // 0x80800A2C: beq         $v0, $zero, L_80800A44
    if (ctx->r2 == 0) {
        // 0x80800A30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A44;
    }
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800A38: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800A3C: jal         0x8010108C
    // 0x80800A40: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_8010108C(rdram, ctx);
        goto after_5;
    // 0x80800A40: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_5:
L_80800A44:
    // 0x80800A44: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80800A48:
    // 0x80800A48: sltu        $at, $s1, $s3
    ctx->r1 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x80800A4C: bnel        $at, $zero, L_808009DC
    if (ctx->r1 != 0) {
        // 0x80800A50: lw          $t6, 0x8($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X8);
            goto L_808009DC;
    }
    goto skip_4;
    // 0x80800A50: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    skip_4:
L_80800A54:
    // 0x80800A54: lw          $a0, 0x4($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X4);
    // 0x80800A58: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80800A5C: bne         $a0, $zero, L_808009B8
    if (ctx->r4 != 0) {
        // 0x80800A60: nop
    
            goto L_808009B8;
    }
    // 0x80800A60: nop

    // 0x80800A64: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800A68:
    // 0x80800A68: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80800A6C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800A70: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800A74: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800A78: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800A7C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A80: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800A84: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800A88: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800A8C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80800A90: jr          $ra
    // 0x80800A94: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80800A94: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800F9C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9C40: jal         0x800F8B88
    // 0x800F9C44: nop

    func_800F8B88(rdram, ctx);
        goto after_0;
    // 0x800F9C44: nop

    after_0:
    // 0x800F9C48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F9C4C: bnel        $v0, $at, L_800F9C60
    if (ctx->r2 != ctx->r1) {
        // 0x800F9C50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9C60;
    }
    goto skip_0;
    // 0x800F9C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800F9C54: jal         0x800F9488
    // 0x800F9C58: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_800F9488(rdram, ctx);
        goto after_1;
    // 0x800F9C58: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_1:
    // 0x800F9C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9C60:
    // 0x800F9C60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9C64: jr          $ra
    // 0x800F9C68: nop

    return;
    // 0x800F9C68: nop

;}
RECOMP_FUNC void func_80800128_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080012C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800138: jal         0x80100094
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800140: jal         0x800D8FF8
    // 0x80800144: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800144: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800148: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8080014C: jal         0x8010D254
    // 0x80800150: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_8010D254(rdram, ctx);
        goto after_2;
    // 0x80800150: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x80800154: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800158: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8080015C: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800160: xori        $a2, $t6, 0x1
    ctx->r6 = ctx->r14 ^ 0X1;
    // 0x80800164: sltu        $a2, $zero, $a2
    ctx->r6 = 0 < ctx->r6 ? 1 : 0;
    // 0x80800168: bne         $a2, $zero, L_80800180
    if (ctx->r6 != 0) {
        // 0x8080016C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80800180;
    }
    // 0x8080016C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80800170: bnel        $a2, $zero, L_808001AC
    if (ctx->r6 != 0) {
        // 0x80800174: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001AC;
    }
    goto skip_0;
    // 0x80800174: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80800178: lbu         $t7, 0x5F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5F);
    // 0x8080017C: beq         $t7, $zero, L_808001A8
    if (ctx->r15 == 0) {
        // 0x80800180: lui         $a3, 0x8080
        ctx->r7 = S32(RELOC_HI16(1084, 0XDA4) << 16);
            goto L_808001A8;
    }
L_80800180:
    // 0x80800180: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1084, 0XDA4) << 16);
    // 0x80800184: addiu       $a3, $a3, 0xDA4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1084, 0XDA4));
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800190: jal         0x80089D50
    // 0x80800194: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800194: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_3:
    // 0x80800198: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x8080019C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x808001A0: srl         $t8, $v1, 10
    ctx->r24 = S32(U32(ctx->r3) >> 10);
    // 0x808001A4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_808001A8:
    // 0x808001A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_808001AC:
    // 0x808001AC: beq         $v1, $at, L_808001CC
    if (ctx->r3 == ctx->r1) {
        // 0x808001B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808001CC;
    }
    // 0x808001B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001B4: beq         $v1, $at, L_80800210
    if (ctx->r3 == ctx->r1) {
        // 0x808001B8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800210;
    }
    // 0x808001B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808001BC: beq         $v1, $at, L_808002C0
    if (ctx->r3 == ctx->r1) {
        // 0x808001C0: addiu       $a0, $t0, 0x1C
        ctx->r4 = ADD32(ctx->r8, 0X1C);
            goto L_808002C0;
    }
    // 0x808001C0: addiu       $a0, $t0, 0x1C
    ctx->r4 = ADD32(ctx->r8, 0X1C);
    // 0x808001C4: b           L_808002F8
    // 0x808001C8: nop

        goto L_808002F8;
    // 0x808001C8: nop

L_808001CC:
    // 0x808001CC: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x808001D0: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808001D4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808001D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808001DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808001E8: swc1        $f8, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f8.u32l;
    // 0x808001EC: lwc1        $f10, 0x1C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x808001F0: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x808001F4: nop

    // 0x808001F8: bc1f        L_808002F8
    if (!c1cs) {
        // 0x808001FC: nop
    
            goto L_808002F8;
    }
    // 0x808001FC: nop

    // 0x80800200: jal         0x80101FDC
    // 0x80800204: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800204: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    after_4:
    // 0x80800208: b           L_808002F8
    // 0x8080020C: nop

        goto L_808002F8;
    // 0x8080020C: nop

L_80800210:
    // 0x80800210: jal         0x800F54E4
    // 0x80800214: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800214: nop

    after_5:
    // 0x80800218: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080021C: jal         0x800D9078
    // 0x80800220: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x80800220: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x80800224: beq         $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800228: nop
    
            goto L_80800234;
    }
    // 0x80800228: nop

    // 0x8080022C: jal         0x808009A0
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    chboilerid_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80800234:
    // 0x80800234: jal         0x800F6C5C
    // 0x80800238: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F6C5C(rdram, ctx);
        goto after_8;
    // 0x80800238: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x8080023C: beq         $v0, $zero, L_808002F8
    if (ctx->r2 == 0) {
        // 0x80800240: nop
    
            goto L_808002F8;
    }
    // 0x80800240: nop

    // 0x80800244: jal         0x800F6478
    // 0x80800248: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F6478(rdram, ctx);
        goto after_9;
    // 0x80800248: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x8080024C: beq         $v0, $zero, L_808002F8
    if (ctx->r2 == 0) {
        // 0x80800250: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_808002F8;
    }
    // 0x80800250: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800254: jal         0x800F64A4
    // 0x80800258: addiu       $a1, $zero, 0x601
    ctx->r5 = ADD32(0, 0X601);
    func_800F64A4(rdram, ctx);
        goto after_10;
    // 0x80800258: addiu       $a1, $zero, 0x601
    ctx->r5 = ADD32(0, 0X601);
    after_10:
    // 0x8080025C: beq         $v0, $zero, L_808002F8
    if (ctx->r2 == 0) {
        // 0x80800260: nop
    
            goto L_808002F8;
    }
    // 0x80800260: nop

    // 0x80800264: jal         0x800F55FC
    // 0x80800268: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F55FC(rdram, ctx);
        goto after_11;
    // 0x80800268: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x8080026C: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80800270: bgez        $t9, L_808002F8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800274: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_808002F8;
    }
    // 0x80800274: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800278: jal         0x800F7B9C
    // 0x8080027C: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800F7B9C(rdram, ctx);
        goto after_12;
    // 0x8080027C: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_12:
    // 0x80800280: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800284: bne         $v0, $at, L_808002F8
    if (ctx->r2 != ctx->r1) {
        // 0x80800288: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_808002F8;
    }
    // 0x80800288: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8080028C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1084, 0XDB0) << 16);
    // 0x80800290: addiu       $t1, $t1, 0xDB0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1084, 0XDB0));
    // 0x80800294: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080029C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002A0: jal         0x800BBCB8
    // 0x808002A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_13;
    // 0x808002A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x808002A8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1084, 0XDE8) << 16);
    // 0x808002AC: addiu       $a1, $a1, 0xDE8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1084, 0XDE8));
    // 0x808002B0: jal         0x800C4AF0
    // 0x808002B4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800C4AF0(rdram, ctx);
        goto after_14;
    // 0x808002B4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_14:
    // 0x808002B8: b           L_808002F8
    // 0x808002BC: nop

        goto L_808002F8;
    // 0x808002BC: nop

L_808002C0:
    // 0x808002C0: jal         0x800D9078
    // 0x808002C4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    func_800D9078(rdram, ctx);
        goto after_15;
    // 0x808002C4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_15:
    // 0x808002C8: beq         $v0, $zero, L_808002F8
    if (ctx->r2 == 0) {
        // 0x808002CC: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_808002F8;
    }
    // 0x808002CC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x808002D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002DC: jal         0x80101FDC
    // 0x808002E0: swc1        $f16, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f16.u32l;
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x808002E0: swc1        $f16, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f16.u32l;
    after_16:
    // 0x808002E4: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    // 0x808002E8: jal         0x800DA3B8
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_17;
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x808002F0: jal         0x800CF494
    // 0x808002F4: nop

    func_800CF494(rdram, ctx);
        goto after_18;
    // 0x808002F4: nop

    after_18:
L_808002F8:
    // 0x808002F8: jal         0x80800418
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800418_chboilerid(rdram, ctx);
        goto after_19;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800300: jal         0x80800440
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800440_chboilerid(rdram, ctx);
        goto after_20;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800308: jal         0x80800468
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800468_chboilerid(rdram, ctx);
        goto after_21;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800310: jal         0x80800998
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800998_chboilerid(rdram, ctx);
        goto after_22;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800318: jal         0x800BEA88
    // 0x8080031C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_23;
    // 0x8080031C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x80800320: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800324: addiu       $a2, $a2, 0x6098
    ctx->r6 = ADD32(ctx->r6, 0X6098);
    // 0x80800328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080032C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80800330: jal         0x80088660
    // 0x80800334: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_24;
    // 0x80800334: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_24:
    // 0x80800338: jal         0x800BEA88
    // 0x8080033C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_25;
    // 0x8080033C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x80800340: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800344: addiu       $a2, $a2, 0x60A0
    ctx->r6 = ADD32(ctx->r6, 0X60A0);
    // 0x80800348: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080034C: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x80800350: jal         0x80088660
    // 0x80800354: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_26;
    // 0x80800354: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_26:
    // 0x80800358: jal         0x800BEA88
    // 0x8080035C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_27;
    // 0x8080035C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x80800360: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800364: addiu       $a2, $a2, 0x60A8
    ctx->r6 = ADD32(ctx->r6, 0X60A8);
    // 0x80800368: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080036C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80800370: jal         0x80088660
    // 0x80800374: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_28;
    // 0x80800374: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_28:
    // 0x80800378: jal         0x800BEA88
    // 0x8080037C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_29;
    // 0x8080037C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_29:
    // 0x80800380: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800384: addiu       $a2, $a2, 0x60B0
    ctx->r6 = ADD32(ctx->r6, 0X60B0);
    // 0x80800388: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080038C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x80800390: jal         0x80088660
    // 0x80800394: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_30;
    // 0x80800394: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_30:
    // 0x80800398: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080039C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003A0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808003A4: jr          $ra
    // 0x808003A8: nop

    return;
    // 0x808003A8: nop

;}
RECOMP_FUNC void basudie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80091EF0
    // 0x8080000C: nop

    func_80091EF0(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void idworldmake_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800438: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080043C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800440: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800444: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800448: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080044C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800450: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800454: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80800458: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8080045C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800460: jal         0x80088880
    // 0x80800464: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    _glidmake_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800464: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800468: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080046C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80800470: addiu       $s3, $v0, 0x2
    ctx->r19 = ADD32(ctx->r2, 0X2);
    // 0x80800474: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800478: blezl       $t6, L_80800770
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8080047C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800770;
    }
    goto skip_0;
    // 0x8080047C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
L_80800480:
    // 0x80800480: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x80800484: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80800488: slti        $at, $s0, 0x65
    ctx->r1 = SIGNED(ctx->r16) < 0X65 ? 1 : 0;
    // 0x8080048C: bnel        $t7, $a1, L_8080074C
    if (ctx->r15 != ctx->r5) {
        // 0x80800490: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_8080074C;
    }
    goto skip_1;
    // 0x80800490: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80800494: bne         $at, $zero, L_808004BC
    if (ctx->r1 != 0) {
        // 0x80800498: slti        $at, $s0, 0xC8
        ctx->r1 = SIGNED(ctx->r16) < 0XC8 ? 1 : 0;
            goto L_808004BC;
    }
    // 0x80800498: slti        $at, $s0, 0xC8
    ctx->r1 = SIGNED(ctx->r16) < 0XC8 ? 1 : 0;
    // 0x8080049C: beq         $at, $zero, L_808004BC
    if (ctx->r1 == 0) {
        // 0x808004A0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808004BC;
    }
    // 0x808004A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808004A8: addiu       $a3, $s0, -0x64
    ctx->r7 = ADD32(ctx->r16, -0X64);
    // 0x808004AC: jal         0x80800000
    // 0x808004B0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_1;
    // 0x808004B0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // 0x808004B4: b           L_8080074C
    // 0x808004B8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x808004B8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808004BC:
    // 0x808004BC: slti        $at, $s0, 0xC8
    ctx->r1 = SIGNED(ctx->r16) < 0XC8 ? 1 : 0;
    // 0x808004C0: bne         $at, $zero, L_808004E8
    if (ctx->r1 != 0) {
        // 0x808004C4: slti        $at, $s0, 0x12C
        ctx->r1 = SIGNED(ctx->r16) < 0X12C ? 1 : 0;
            goto L_808004E8;
    }
    // 0x808004C4: slti        $at, $s0, 0x12C
    ctx->r1 = SIGNED(ctx->r16) < 0X12C ? 1 : 0;
    // 0x808004C8: beq         $at, $zero, L_808004E8
    if (ctx->r1 == 0) {
        // 0x808004CC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808004E8;
    }
    // 0x808004CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004D4: addiu       $a3, $s0, -0xC8
    ctx->r7 = ADD32(ctx->r16, -0XC8);
    // 0x808004D8: jal         0x80800000
    // 0x808004DC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_2;
    // 0x808004DC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_2:
    // 0x808004E0: b           L_8080074C
    // 0x808004E4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x808004E4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808004E8:
    // 0x808004E8: slti        $at, $s0, 0x12C
    ctx->r1 = SIGNED(ctx->r16) < 0X12C ? 1 : 0;
    // 0x808004EC: bne         $at, $zero, L_80800514
    if (ctx->r1 != 0) {
        // 0x808004F0: slti        $at, $s0, 0x190
        ctx->r1 = SIGNED(ctx->r16) < 0X190 ? 1 : 0;
            goto L_80800514;
    }
    // 0x808004F0: slti        $at, $s0, 0x190
    ctx->r1 = SIGNED(ctx->r16) < 0X190 ? 1 : 0;
    // 0x808004F4: beq         $at, $zero, L_80800514
    if (ctx->r1 == 0) {
        // 0x808004F8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800514;
    }
    // 0x808004F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004FC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800500: addiu       $a3, $s0, -0x12C
    ctx->r7 = ADD32(ctx->r16, -0X12C);
    // 0x80800504: jal         0x80800000
    // 0x80800508: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_3;
    // 0x80800508: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_3:
    // 0x8080050C: b           L_8080074C
    // 0x80800510: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x80800510: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80800514:
    // 0x80800514: slti        $at, $s0, 0x190
    ctx->r1 = SIGNED(ctx->r16) < 0X190 ? 1 : 0;
    // 0x80800518: bne         $at, $zero, L_80800540
    if (ctx->r1 != 0) {
        // 0x8080051C: slti        $at, $s0, 0x1F4
        ctx->r1 = SIGNED(ctx->r16) < 0X1F4 ? 1 : 0;
            goto L_80800540;
    }
    // 0x8080051C: slti        $at, $s0, 0x1F4
    ctx->r1 = SIGNED(ctx->r16) < 0X1F4 ? 1 : 0;
    // 0x80800520: beq         $at, $zero, L_80800540
    if (ctx->r1 == 0) {
        // 0x80800524: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800540;
    }
    // 0x80800524: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800528: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080052C: addiu       $a3, $s0, -0x190
    ctx->r7 = ADD32(ctx->r16, -0X190);
    // 0x80800530: jal         0x80800000
    // 0x80800534: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_4;
    // 0x80800534: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_4:
    // 0x80800538: b           L_8080074C
    // 0x8080053C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x8080053C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80800540:
    // 0x80800540: slti        $at, $s0, 0x1F4
    ctx->r1 = SIGNED(ctx->r16) < 0X1F4 ? 1 : 0;
    // 0x80800544: bne         $at, $zero, L_8080056C
    if (ctx->r1 != 0) {
        // 0x80800548: slti        $at, $s0, 0x258
        ctx->r1 = SIGNED(ctx->r16) < 0X258 ? 1 : 0;
            goto L_8080056C;
    }
    // 0x80800548: slti        $at, $s0, 0x258
    ctx->r1 = SIGNED(ctx->r16) < 0X258 ? 1 : 0;
    // 0x8080054C: beq         $at, $zero, L_8080056C
    if (ctx->r1 == 0) {
        // 0x80800550: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080056C;
    }
    // 0x80800550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800554: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800558: addiu       $a3, $s0, -0x1F4
    ctx->r7 = ADD32(ctx->r16, -0X1F4);
    // 0x8080055C: jal         0x80800000
    // 0x80800560: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_5;
    // 0x80800560: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_5:
    // 0x80800564: b           L_8080074C
    // 0x80800568: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x80800568: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_8080056C:
    // 0x8080056C: slti        $at, $s0, 0x258
    ctx->r1 = SIGNED(ctx->r16) < 0X258 ? 1 : 0;
    // 0x80800570: bne         $at, $zero, L_80800598
    if (ctx->r1 != 0) {
        // 0x80800574: slti        $at, $s0, 0x2BC
        ctx->r1 = SIGNED(ctx->r16) < 0X2BC ? 1 : 0;
            goto L_80800598;
    }
    // 0x80800574: slti        $at, $s0, 0x2BC
    ctx->r1 = SIGNED(ctx->r16) < 0X2BC ? 1 : 0;
    // 0x80800578: beq         $at, $zero, L_80800598
    if (ctx->r1 == 0) {
        // 0x8080057C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800598;
    }
    // 0x8080057C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800580: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800584: addiu       $a3, $s0, -0x258
    ctx->r7 = ADD32(ctx->r16, -0X258);
    // 0x80800588: jal         0x80800000
    // 0x8080058C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_6;
    // 0x8080058C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_6:
    // 0x80800590: b           L_8080074C
    // 0x80800594: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x80800594: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80800598:
    // 0x80800598: slti        $at, $s0, 0x320
    ctx->r1 = SIGNED(ctx->r16) < 0X320 ? 1 : 0;
    // 0x8080059C: bne         $at, $zero, L_808005C4
    if (ctx->r1 != 0) {
        // 0x808005A0: slti        $at, $s0, 0x384
        ctx->r1 = SIGNED(ctx->r16) < 0X384 ? 1 : 0;
            goto L_808005C4;
    }
    // 0x808005A0: slti        $at, $s0, 0x384
    ctx->r1 = SIGNED(ctx->r16) < 0X384 ? 1 : 0;
    // 0x808005A4: beq         $at, $zero, L_808005C4
    if (ctx->r1 == 0) {
        // 0x808005A8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808005C4;
    }
    // 0x808005A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005AC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808005B0: addiu       $a3, $s0, -0x320
    ctx->r7 = ADD32(ctx->r16, -0X320);
    // 0x808005B4: jal         0x80800000
    // 0x808005B8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_7;
    // 0x808005B8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_7:
    // 0x808005BC: b           L_8080074C
    // 0x808005C0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x808005C0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808005C4:
    // 0x808005C4: slti        $at, $s0, 0x384
    ctx->r1 = SIGNED(ctx->r16) < 0X384 ? 1 : 0;
    // 0x808005C8: bne         $at, $zero, L_808005F0
    if (ctx->r1 != 0) {
        // 0x808005CC: slti        $at, $s0, 0x3E8
        ctx->r1 = SIGNED(ctx->r16) < 0X3E8 ? 1 : 0;
            goto L_808005F0;
    }
    // 0x808005CC: slti        $at, $s0, 0x3E8
    ctx->r1 = SIGNED(ctx->r16) < 0X3E8 ? 1 : 0;
    // 0x808005D0: beq         $at, $zero, L_808005F0
    if (ctx->r1 == 0) {
        // 0x808005D4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808005F0;
    }
    // 0x808005D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005D8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x808005DC: addiu       $a3, $s0, -0x384
    ctx->r7 = ADD32(ctx->r16, -0X384);
    // 0x808005E0: jal         0x80800000
    // 0x808005E4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_8;
    // 0x808005E4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_8:
    // 0x808005E8: b           L_8080074C
    // 0x808005EC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x808005EC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808005F0:
    // 0x808005F0: slti        $at, $s0, 0x3E8
    ctx->r1 = SIGNED(ctx->r16) < 0X3E8 ? 1 : 0;
    // 0x808005F4: bne         $at, $zero, L_8080061C
    if (ctx->r1 != 0) {
        // 0x808005F8: slti        $at, $s0, 0x44C
        ctx->r1 = SIGNED(ctx->r16) < 0X44C ? 1 : 0;
            goto L_8080061C;
    }
    // 0x808005F8: slti        $at, $s0, 0x44C
    ctx->r1 = SIGNED(ctx->r16) < 0X44C ? 1 : 0;
    // 0x808005FC: beq         $at, $zero, L_8080061C
    if (ctx->r1 == 0) {
        // 0x80800600: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080061C;
    }
    // 0x80800600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800604: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800608: addiu       $a3, $s0, -0x3E8
    ctx->r7 = ADD32(ctx->r16, -0X3E8);
    // 0x8080060C: jal         0x80800000
    // 0x80800610: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_9;
    // 0x80800610: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_9:
    // 0x80800614: b           L_8080074C
    // 0x80800618: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x80800618: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_8080061C:
    // 0x8080061C: slti        $at, $s0, 0x44C
    ctx->r1 = SIGNED(ctx->r16) < 0X44C ? 1 : 0;
    // 0x80800620: bne         $at, $zero, L_80800648
    if (ctx->r1 != 0) {
        // 0x80800624: slti        $at, $s0, 0x4B0
        ctx->r1 = SIGNED(ctx->r16) < 0X4B0 ? 1 : 0;
            goto L_80800648;
    }
    // 0x80800624: slti        $at, $s0, 0x4B0
    ctx->r1 = SIGNED(ctx->r16) < 0X4B0 ? 1 : 0;
    // 0x80800628: beq         $at, $zero, L_80800648
    if (ctx->r1 == 0) {
        // 0x8080062C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800648;
    }
    // 0x8080062C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800630: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80800634: addiu       $a3, $s0, -0x44C
    ctx->r7 = ADD32(ctx->r16, -0X44C);
    // 0x80800638: jal         0x80800000
    // 0x8080063C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_10;
    // 0x8080063C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_10:
    // 0x80800640: b           L_8080074C
    // 0x80800644: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x80800644: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80800648:
    // 0x80800648: slti        $at, $s0, 0x6A4
    ctx->r1 = SIGNED(ctx->r16) < 0X6A4 ? 1 : 0;
    // 0x8080064C: bne         $at, $zero, L_80800674
    if (ctx->r1 != 0) {
        // 0x80800650: slti        $at, $s0, 0x708
        ctx->r1 = SIGNED(ctx->r16) < 0X708 ? 1 : 0;
            goto L_80800674;
    }
    // 0x80800650: slti        $at, $s0, 0x708
    ctx->r1 = SIGNED(ctx->r16) < 0X708 ? 1 : 0;
    // 0x80800654: beq         $at, $zero, L_80800674
    if (ctx->r1 == 0) {
        // 0x80800658: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800674;
    }
    // 0x80800658: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080065C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80800660: addiu       $a3, $s0, -0x6A4
    ctx->r7 = ADD32(ctx->r16, -0X6A4);
    // 0x80800664: jal         0x80800000
    // 0x80800668: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_11;
    // 0x80800668: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_11:
    // 0x8080066C: b           L_8080074C
    // 0x80800670: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x80800670: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80800674:
    // 0x80800674: slti        $at, $s0, 0x708
    ctx->r1 = SIGNED(ctx->r16) < 0X708 ? 1 : 0;
    // 0x80800678: bne         $at, $zero, L_808006A0
    if (ctx->r1 != 0) {
        // 0x8080067C: slti        $at, $s0, 0x76C
        ctx->r1 = SIGNED(ctx->r16) < 0X76C ? 1 : 0;
            goto L_808006A0;
    }
    // 0x8080067C: slti        $at, $s0, 0x76C
    ctx->r1 = SIGNED(ctx->r16) < 0X76C ? 1 : 0;
    // 0x80800680: beq         $at, $zero, L_808006A0
    if (ctx->r1 == 0) {
        // 0x80800684: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808006A0;
    }
    // 0x80800684: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800688: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080068C: addiu       $a3, $s0, -0x708
    ctx->r7 = ADD32(ctx->r16, -0X708);
    // 0x80800690: jal         0x80800000
    // 0x80800694: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_12;
    // 0x80800694: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_12:
    // 0x80800698: b           L_8080074C
    // 0x8080069C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x8080069C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808006A0:
    // 0x808006A0: slti        $at, $s0, 0x76C
    ctx->r1 = SIGNED(ctx->r16) < 0X76C ? 1 : 0;
    // 0x808006A4: bne         $at, $zero, L_808006CC
    if (ctx->r1 != 0) {
        // 0x808006A8: slti        $at, $s0, 0x7CF
        ctx->r1 = SIGNED(ctx->r16) < 0X7CF ? 1 : 0;
            goto L_808006CC;
    }
    // 0x808006A8: slti        $at, $s0, 0x7CF
    ctx->r1 = SIGNED(ctx->r16) < 0X7CF ? 1 : 0;
    // 0x808006AC: beq         $at, $zero, L_808006CC
    if (ctx->r1 == 0) {
        // 0x808006B0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808006CC;
    }
    // 0x808006B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006B4: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x808006B8: addiu       $a3, $s0, -0x76C
    ctx->r7 = ADD32(ctx->r16, -0X76C);
    // 0x808006BC: jal         0x80800000
    // 0x808006C0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_13;
    // 0x808006C0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_13:
    // 0x808006C4: b           L_8080074C
    // 0x808006C8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x808006C8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808006CC:
    // 0x808006CC: slti        $at, $s0, 0x2BC
    ctx->r1 = SIGNED(ctx->r16) < 0X2BC ? 1 : 0;
    // 0x808006D0: bne         $at, $zero, L_808006F8
    if (ctx->r1 != 0) {
        // 0x808006D4: slti        $at, $s0, 0x320
        ctx->r1 = SIGNED(ctx->r16) < 0X320 ? 1 : 0;
            goto L_808006F8;
    }
    // 0x808006D4: slti        $at, $s0, 0x320
    ctx->r1 = SIGNED(ctx->r16) < 0X320 ? 1 : 0;
    // 0x808006D8: beq         $at, $zero, L_808006F8
    if (ctx->r1 == 0) {
        // 0x808006DC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808006F8;
    }
    // 0x808006DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006E0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808006E4: addiu       $a3, $s0, -0x2BC
    ctx->r7 = ADD32(ctx->r16, -0X2BC);
    // 0x808006E8: jal         0x80800000
    // 0x808006EC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_14;
    // 0x808006EC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_14:
    // 0x808006F0: b           L_8080074C
    // 0x808006F4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x808006F4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808006F8:
    // 0x808006F8: slti        $at, $s0, 0x4B0
    ctx->r1 = SIGNED(ctx->r16) < 0X4B0 ? 1 : 0;
    // 0x808006FC: bne         $at, $zero, L_80800724
    if (ctx->r1 != 0) {
        // 0x80800700: slti        $at, $s0, 0x6A4
        ctx->r1 = SIGNED(ctx->r16) < 0X6A4 ? 1 : 0;
            goto L_80800724;
    }
    // 0x80800700: slti        $at, $s0, 0x6A4
    ctx->r1 = SIGNED(ctx->r16) < 0X6A4 ? 1 : 0;
    // 0x80800704: beq         $at, $zero, L_80800724
    if (ctx->r1 == 0) {
        // 0x80800708: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800724;
    }
    // 0x80800708: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080070C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80800710: addiu       $a3, $s0, -0x4B0
    ctx->r7 = ADD32(ctx->r16, -0X4B0);
    // 0x80800714: jal         0x80800000
    // 0x80800718: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_15;
    // 0x80800718: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_15:
    // 0x8080071C: b           L_8080074C
    // 0x80800720: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_8080074C;
    // 0x80800720: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80800724:
    // 0x80800724: slti        $at, $s0, 0x898
    ctx->r1 = SIGNED(ctx->r16) < 0X898 ? 1 : 0;
    // 0x80800728: bne         $at, $zero, L_80800748
    if (ctx->r1 != 0) {
        // 0x8080072C: slti        $at, $s0, 0x8FC
        ctx->r1 = SIGNED(ctx->r16) < 0X8FC ? 1 : 0;
            goto L_80800748;
    }
    // 0x8080072C: slti        $at, $s0, 0x8FC
    ctx->r1 = SIGNED(ctx->r16) < 0X8FC ? 1 : 0;
    // 0x80800730: beq         $at, $zero, L_80800748
    if (ctx->r1 == 0) {
        // 0x80800734: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800748;
    }
    // 0x80800734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800738: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x8080073C: addiu       $a3, $s0, -0x898
    ctx->r7 = ADD32(ctx->r16, -0X898);
    // 0x80800740: jal         0x80800000
    // 0x80800744: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_80800000_idworldmake(rdram, ctx);
        goto after_16;
    // 0x80800744: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_16:
L_80800748:
    // 0x80800748: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_8080074C:
    // 0x8080074C: lh          $t8, 0x2($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2);
    // 0x80800750: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800754: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80800758: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8080075C: addu        $s3, $s3, $t9
    ctx->r19 = ADD32(ctx->r19, ctx->r25);
    // 0x80800760: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800764: bne         $at, $zero, L_80800480
    if (ctx->r1 != 0) {
        // 0x80800768: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80800480;
    }
    // 0x80800768: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8080076C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800770:
    // 0x80800770: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800774: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800778: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080077C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800780: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800784: jr          $ra
    // 0x80800788: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800788: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _gcboundDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EB8: syscall     661
    recomp_syscall_handler(rdram, ctx, 0x80087EB8);
    return;
    // 0x80087EBC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808005B8_bstaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005C4: jal         0x8009C4CC
    // 0x808005C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_0;
    // 0x808005C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x808005CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005D0: jal         0x8009BF5C
    // 0x808005D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x808005D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x808005D8: jal         0x808000D4
    // 0x808005DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstaxi_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808005DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808005E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005E8: jr          $ra
    // 0x808005EC: nop

    return;
    // 0x808005EC: nop

;}
RECOMP_FUNC void dbid_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080011C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800120: jal         0x808000C8
    // 0x80800124: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    dbid_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800124: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800128: beq         $v0, $zero, L_80800174
    if (ctx->r2 == 0) {
        // 0x8080012C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800174;
    }
    // 0x8080012C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800130: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80800134: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800138: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8080013C: blez        $t6, L_80800174
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800140: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800174;
    }
    // 0x80800140: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800144: lhu         $a2, 0x0($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X0);
    // 0x80800148: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
L_8080014C:
    // 0x8080014C: bnel        $t8, $a2, L_80800160
    if (ctx->r24 != ctx->r6) {
        // 0x80800150: lh          $t9, 0x2($a1)
        ctx->r25 = MEM_H(ctx->r5, 0X2);
            goto L_80800160;
    }
    goto skip_0;
    // 0x80800150: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    skip_0:
    // 0x80800154: b           L_80800178
    // 0x80800158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800178;
    // 0x80800158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080015C: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
L_80800160:
    // 0x80800160: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800164: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800168: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8080016C: bnel        $at, $zero, L_8080014C
    if (ctx->r1 != 0) {
        // 0x80800170: lh          $t8, 0x4($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X4);
            goto L_8080014C;
    }
    goto skip_1;
    // 0x80800170: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    skip_1:
L_80800174:
    // 0x80800174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800178:
    // 0x80800178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080017C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

    // 0x80800188: nop

    // 0x8080018C: nop

;}
RECOMP_FUNC void chplatuegrill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2460, 0X238) << 16);
    // 0x808001B0: jr          $ra
    // 0x808001B4: addiu       $v0, $v0, 0x238
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2460, 0X238));
    return;
    // 0x808001B4: addiu       $v0, $v0, 0x238
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2460, 0X238));
    // 0x808001B8: nop

    // 0x808001BC: nop

;}
RECOMP_FUNC void func_80800714_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800714: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080071C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800720: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800724: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800728: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x8080072C: bgezl       $t8, L_8080078C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800730: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080078C;
    }
    goto skip_0;
    // 0x80800730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800734: jal         0x800FECB8
    // 0x80800738: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800FECB8(rdram, ctx);
        goto after_0;
    // 0x80800738: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x8080073C: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800740: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800744: jal         0x800FE8AC
    // 0x80800748: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_800FE8AC(rdram, ctx);
        goto after_1;
    // 0x80800748: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_1:
    // 0x8080074C: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800754: addiu       $a2, $zero, 0x14D
    ctx->r6 = ADD32(0, 0X14D);
    // 0x80800758: srl         $t1, $a0, 7
    ctx->r9 = S32(U32(ctx->r4) >> 7);
    // 0x8080075C: jal         0x800FCAE0
    // 0x80800760: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800FCAE0(rdram, ctx);
        goto after_2;
    // 0x80800760: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_2:
    // 0x80800764: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800768: srl         $t2, $a0, 7
    ctx->r10 = S32(U32(ctx->r4) >> 7);
    // 0x8080076C: jal         0x800FCA90
    // 0x80800770: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800FCA90(rdram, ctx);
        goto after_3;
    // 0x80800770: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_3:
    // 0x80800774: lhu         $t3, 0x76($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X76);
    // 0x80800778: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080077C: andi        $t4, $t3, 0x7F
    ctx->r12 = ctx->r11 & 0X7F;
    // 0x80800780: jal         0x800DA524
    // 0x80800784: sh          $t4, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r12;
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x80800784: sh          $t4, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r12;
    after_4:
    // 0x80800788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080078C:
    // 0x8080078C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800790: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800794: jr          $ra
    // 0x80800798: nop

    return;
    // 0x80800798: nop

;}
RECOMP_FUNC void func_800EBD2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBD2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EBD30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EBD34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EBD38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800EBD3C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800EBD40: jal         0x800BDB9C
    // 0x800EBD44: lh          $a0, 0x1C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1C);
    func_800BDB9C(rdram, ctx);
        goto after_0;
    // 0x800EBD44: lh          $a0, 0x1C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1C);
    after_0:
    // 0x800EBD48: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800EBD4C: jal         0x800BDB9C
    // 0x800EBD50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800BDB9C(rdram, ctx);
        goto after_1;
    // 0x800EBD50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800EBD54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800EBD58: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800EBD5C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800EBD60: jal         0x800EBCD0
    // 0x800EBD64: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800EBCD0(rdram, ctx);
        goto after_2;
    // 0x800EBD64: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_2:
    // 0x800EBD68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EBD6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EBD70: jr          $ra
    // 0x800EBD74: nop

    return;
    // 0x800EBD74: nop

;}
RECOMP_FUNC void func_800F0CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0CB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F0CB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F0CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0CC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F0CC4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800F0CC8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800F0CCC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800F0CD0: jal         0x800EEAA4
    // 0x800F0CD4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_0;
    // 0x800F0CD4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800F0CD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F0CDC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800F0CE0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800F0CE4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800F0CE8: nop

    // 0x800F0CEC: bc1f        L_800F0CFC
    if (!c1cs) {
        // 0x800F0CF0: nop
    
            goto L_800F0CFC;
    }
    // 0x800F0CF0: nop

    // 0x800F0CF4: b           L_800F0D3C
    // 0x800F0CF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0D3C;
    // 0x800F0CF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0CFC:
    // 0x800F0CFC: jal         0x800EEAA4
    // 0x800F0D00: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EEAA4(rdram, ctx);
        goto after_1;
    // 0x800F0D00: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800F0D04: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800F0D08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800F0D0C: jal         0x800EEAA4
    // 0x800F0D10: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EEAA4(rdram, ctx);
        goto after_2;
    // 0x800F0D10: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x800F0D14: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F0D18: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F0D1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800F0D20: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800F0D24: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800F0D28: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800F0D2C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800F0D30: jal         0x800EF174
    // 0x800F0D34: nop

    func_800EF174(rdram, ctx);
        goto after_3;
    // 0x800F0D34: nop

    after_3:
    // 0x800F0D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0D3C:
    // 0x800F0D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0D40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F0D44: jr          $ra
    // 0x800F0D48: nop

    return;
    // 0x800F0D48: nop

    // 0x800F0D4C: nop

;}
RECOMP_FUNC void _gztrace_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A948: syscall     878
    recomp_syscall_handler(rdram, ctx, 0x8008A948);
    return;
    // 0x8008A94C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8009E74C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E74C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E754: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009E758: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E75C: jal         0x8009CBDC
    // 0x8009E760: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    func_8009CBDC(rdram, ctx);
        goto after_0;
    // 0x8009E760: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    after_0:
    // 0x8009E764: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E76C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E770: xor         $v0, $v0, $t7
    ctx->r2 = ctx->r2 ^ ctx->r15;
    // 0x8009E774: jr          $ra
    // 0x8009E778: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8009E778: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void chfantasydrillfield_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2348, 0X9C4) << 16);
    // 0x808008A4: jr          $ra
    // 0x808008A8: addiu       $v0, $v0, 0x9C4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2348, 0X9C4));
    return;
    // 0x808008A8: addiu       $v0, $v0, 0x9C4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2348, 0X9C4));
    // 0x808008AC: nop

;}
RECOMP_FUNC void _fxleaves_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088960: syscall     711
    recomp_syscall_handler(rdram, ctx, 0x80088960);
    return;
    // 0x80088964: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chfactoryrobot_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1140, 0X29B8) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x29B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1140, 0X29B8));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x29B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1140, 0X29B8));
;}
RECOMP_FUNC void func_8080012C_chquizremotectrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800134: jal         0x8008A888
    // 0x80800138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _suquiz_entrypoint_26(rdram, ctx);
        goto after_0;
    // 0x80800138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080013C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800140: jal         0x800A5854
    // 0x80800144: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800A5854(rdram, ctx);
        goto after_1;
    // 0x80800144: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080014C: beq         $v0, $at, L_8080018C
    if (ctx->r2 == ctx->r1) {
        // 0x80800150: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_8080018C;
    }
    // 0x80800150: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800154: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800158: beq         $v0, $at, L_80800174
    if (ctx->r2 == ctx->r1) {
        // 0x8080015C: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_80800174;
    }
    // 0x8080015C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800164: beq         $v0, $at, L_80800174
    if (ctx->r2 == ctx->r1) {
        // 0x80800168: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800174;
    }
    // 0x80800168: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8080016C: bnel        $v0, $at, L_808001A4
    if (ctx->r2 != ctx->r1) {
        // 0x80800170: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808001A4;
    }
    goto skip_0;
    // 0x80800170: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
L_80800174:
    // 0x80800174: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080017C: jal         0x80085708
    // 0x80800180: addiu       $a3, $zero, 0x834
    ctx->r7 = ADD32(0, 0X834);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800180: addiu       $a3, $zero, 0x834
    ctx->r7 = ADD32(0, 0X834);
    after_2:
    // 0x80800184: b           L_808001A4
    // 0x80800188: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_808001A4;
    // 0x80800188: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8080018C:
    // 0x8080018C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800194: addiu       $a3, $zero, 0x814
    ctx->r7 = ADD32(0, 0X814);
    // 0x80800198: jal         0x80085748
    // 0x8080019C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_21(rdram, ctx);
        goto after_3;
    // 0x8080019C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x808001A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808001A4:
    // 0x808001A4: jal         0x80800000
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_chquizremotectrl(rdram, ctx);
        goto after_4;
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001B4: jr          $ra
    // 0x808001B8: nop

    return;
    // 0x808001B8: nop

;}
RECOMP_FUNC void func_800C5BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C5BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5BAC: jal         0x8001B084
    // 0x800C5BB0: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800C5BB0: nop

    after_0:
    // 0x800C5BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C5BBC: jr          $ra
    // 0x800C5BC0: nop

    return;
    // 0x800C5BC0: nop

;}
RECOMP_FUNC void func_800EC030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC030: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800EC034: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800EC038: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
    // 0x800EC03C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800EC040: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x800EC044: sh          $t8, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r24;
    // 0x800EC048: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800EC04C: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x800EC050: jr          $ra
    // 0x800EC054: sh          $t0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r8;
    return;
    // 0x800EC054: sh          $t0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r8;
;}
RECOMP_FUNC void bsdronejump_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D4: jal         0x80099AA8
    // 0x808001D8: nop

    func_80099AA8(rdram, ctx);
        goto after_0;
    // 0x808001D8: nop

    after_0:
    // 0x808001DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001E4: jr          $ra
    // 0x808001E8: nop

    return;
    // 0x808001E8: nop

;}
RECOMP_FUNC void func_808000AC_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000BC: jal         0x80093360
    // 0x808000C0: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    func_80093360(rdram, ctx);
        goto after_0;
    // 0x808000C0: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_0:
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x8009C908
    // 0x808000CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_1;
    // 0x808000CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808000D8: jal         0x8009C99C
    // 0x808000DC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_2;
    // 0x808000DC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_2:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808000E8: jal         0x8009C554
    // 0x808000EC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_3;
    // 0x808000EC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_3:
    // 0x808000F0: jal         0x80084C68
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: lui         $a1, 0x4282
    ctx->r5 = S32(0X4282 << 16);
    // 0x80800100: jal         0x800959C8
    // 0x80800104: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_800959C8(rdram, ctx);
        goto after_5;
    // 0x80800104: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_5:
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x800961AC
    // 0x80800110: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800961AC(rdram, ctx);
        goto after_6;
    // 0x80800110: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void func_800CB948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB94C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB950: jal         0x800CB910
    // 0x800CB954: nop

    func_800CB910(rdram, ctx);
        goto after_0;
    // 0x800CB954: nop

    after_0:
    // 0x800CB958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB95C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB960: jr          $ra
    // 0x800CB964: nop

    return;
    // 0x800CB964: nop

;}
RECOMP_FUNC void func_80800620_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800620: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800624: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800628: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080062C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800630: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800634: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800638: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080063C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800640: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800644: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800648: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_8080064C:
    // 0x8080064C: jal         0x808006A4
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006A4_chchuffycont(rdram, ctx);
        goto after_0;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800654: beql        $v0, $zero, L_80800680
    if (ctx->r2 == 0) {
        // 0x80800658: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800680;
    }
    goto skip_0;
    // 0x80800658: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8080065C: bnel        $s1, $s3, L_8080067C
    if (ctx->r17 != ctx->r19) {
        // 0x80800660: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080067C;
    }
    goto skip_1;
    // 0x80800660: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80800664: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800668: jal         0x80800540
    // 0x8080066C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800540_chchuffycont(rdram, ctx);
        goto after_1;
    // 0x8080066C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800670: b           L_8080068C
    // 0x80800674: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080068C;
    // 0x80800674: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800678: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080067C:
    // 0x8080067C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800680:
    // 0x80800680: bne         $s0, $s2, L_8080064C
    if (ctx->r16 != ctx->r18) {
        // 0x80800684: nop
    
            goto L_8080064C;
    }
    // 0x80800684: nop

    // 0x80800688: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080068C:
    // 0x8080068C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800690: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800694: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800698: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080069C: jr          $ra
    // 0x808006A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808006A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808000DC_chlagoonbilldrillcover(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000E0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808000E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808000EC: beq         $a1, $at, L_80800180
    if (ctx->r5 == ctx->r1) {
        // 0x808000F0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800180;
    }
    // 0x808000F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808000F4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808000F8: beq         $a1, $at, L_80800114
    if (ctx->r5 == ctx->r1) {
        // 0x808000FC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800114;
    }
    // 0x808000FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800100: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800104: beq         $a1, $at, L_8080015C
    if (ctx->r5 == ctx->r1) {
        // 0x80800108: nop
    
            goto L_8080015C;
    }
    // 0x80800108: nop

    // 0x8080010C: b           L_8080023C
    // 0x80800110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080023C;
    // 0x80800110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800114:
    // 0x80800114: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800118: jal         0x8008A4B8
    // 0x8080011C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    _subaddieDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x8080011C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800120: beq         $v0, $zero, L_8080014C
    if (ctx->r2 == 0) {
        // 0x80800124: lw          $a3, 0x40($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X40);
            goto L_8080014C;
    }
    // 0x80800124: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80800128: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800130: jal         0x80103110
    // 0x80800134: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800134: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800138: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080013C: jal         0x80101FDC
    // 0x80800140: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800140: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800144: b           L_8080023C
    // 0x80800148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x80800148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080014C:
    // 0x8080014C: jal         0x8080024C
    // 0x80800150: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8080024C_chlagoonbilldrillcover(rdram, ctx);
        goto after_3;
    // 0x80800150: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x80800154: b           L_8080023C
    // 0x80800158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x80800158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080015C:
    // 0x8080015C: jal         0x80101080
    // 0x80800160: nop

    func_80101080(rdram, ctx);
        goto after_4;
    // 0x80800160: nop

    after_4:
    // 0x80800164: jal         0x80106790
    // 0x80800168: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800168: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8080016C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800170: jal         0x800866B8
    // 0x80800174: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80800174: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_6:
    // 0x80800178: b           L_8080023C
    // 0x8080017C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x8080017C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800180:
    // 0x80800180: lhu         $t6, 0x76($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X76);
    // 0x80800184: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80800188: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8080018C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800190: addiu       $t8, $t7, -0x32
    ctx->r24 = ADD32(ctx->r15, -0X32);
    // 0x80800194: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80800198: jal         0x800EE7F8
    // 0x8080019C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080019C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    after_7:
    // 0x808001A0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808001A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001A8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808001AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808001B0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808001B4: jal         0x800FFAB0
    // 0x808001B8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x808001B8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x808001BC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x808001C0: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x808001C4: beq         $at, $zero, L_80800238
    if (ctx->r1 == 0) {
        // 0x808001C8: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80800238;
    }
    // 0x808001C8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x808001CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1444, 0X310) << 16);
    // 0x808001D0: addu        $at, $at, $t9
    gpr jr_addend_808001D8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808001D4: lw          $t9, 0x310($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1444, 0X310));
    // 0x808001D8: jr          $t9
    // 0x808001DC: nop

    switch (jr_addend_808001D8 >> 2) {
        case 0: goto L_808001E0; break;
        case 1: goto L_808001E0; break;
        case 2: goto L_808001E0; break;
        case 3: goto L_80800200; break;
        case 4: goto L_80800218; break;
        default: switch_error(__func__, 0x808001D8, 0x80800310);
    }
    // 0x808001DC: nop

L_808001E0:
    // 0x808001E0: addiu       $a0, $v0, 0x13
    ctx->r4 = ADD32(ctx->r2, 0X13);
    // 0x808001E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808001E8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808001EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808001F0: jal         0x800D10D4
    // 0x808001F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D10D4(rdram, ctx);
        goto after_9;
    // 0x808001F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x808001F8: b           L_8080023C
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800200:
    // 0x80800200: addiu       $a0, $zero, 0x210
    ctx->r4 = ADD32(0, 0X210);
    // 0x80800204: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800208: jal         0x80108474
    // 0x8080020C: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80108474(rdram, ctx);
        goto after_10;
    // 0x8080020C: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_10:
    // 0x80800210: b           L_8080023C
    // 0x80800214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x80800214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800218:
    // 0x80800218: addiu       $a0, $zero, 0x210
    ctx->r4 = ADD32(0, 0X210);
    // 0x8080021C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800220: jal         0x80108474
    // 0x80800224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_11;
    // 0x80800224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80800228: b           L_8080023C
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800230: b           L_8080023C
    // 0x80800234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080023C;
    // 0x80800234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800238:
    // 0x80800238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080023C:
    // 0x8080023C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800240: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void func_80801B5C_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B5C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80801B60: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80801B64: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80801B68: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80801B6C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80801B70: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80801B74: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80801B78: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80801B7C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80801B80: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80801B84: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80801B88: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801B8C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801B90: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80801B94: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801B98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801B9C: blez        $t6, L_80801E30
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80801BA0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2590, 0X2FD8) << 16);
            goto L_80801E30;
    }
    // 0x80801BA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FD8) << 16);
    // 0x80801BA4: lwc1        $f28, 0x2FD8($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FD8));
    // 0x80801BA8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801BAC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80801BB0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FDC) << 16);
    // 0x80801BB4: lwc1        $f24, 0x2FDC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FDC));
    // 0x80801BB8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80801BBC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801BC0: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80801BC4: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x80801BC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801BCC:
    // 0x80801BCC: jal         0x80800000
    // 0x80801BD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80801BD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80801BD4: addiu       $s3, $s0, 0x1
    ctx->r19 = ADD32(ctx->r16, 0X1);
    // 0x80801BD8: mtc1        $s3, $f4
    ctx->f4.u32l = ctx->r19;
    // 0x80801BDC: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80801BE0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80801BE4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801BE8: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80801BEC: lwc1        $f8, 0x80($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X80);
    // 0x80801BF0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801BF4: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80801BF8: sub.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x80801BFC: mul.s       $f2, $f0, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80801C00: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80801C04: nop

    // 0x80801C08: bc1fl       L_80801C48
    if (!c1cs) {
        // 0x80801C0C: neg.s       $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
            goto L_80801C48;
    }
    goto skip_0;
    // 0x80801C0C: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    skip_0:
    // 0x80801C10: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x80801C14: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80801C18: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
    // 0x80801C1C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80801C20: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80801C24: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801C2C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801C30: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80801C34: jal         0x80087BC0
    // 0x80801C38: swc1        $f18, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f18.u32l;
    _gczoombox_entrypoint_28(rdram, ctx);
        goto after_1;
    // 0x80801C38: swc1        $f18, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x80801C3C: b           L_80801C70
    // 0x80801C40: sh          $s4, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r20;
        goto L_80801C70;
    // 0x80801C40: sh          $s4, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r20;
    // 0x80801C44: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
L_80801C48:
    // 0x80801C48: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x80801C4C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80801C50: addu        $s0, $s1, $t2
    ctx->r16 = ADD32(ctx->r17, ctx->r10);
    // 0x80801C54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801C58: bc1fl       L_80801C74
    if (!c1cs) {
        // 0x80801C5C: lh          $t3, 0x34($s1)
        ctx->r11 = MEM_H(ctx->r17, 0X34);
            goto L_80801C74;
    }
    goto skip_1;
    // 0x80801C5C: lh          $t3, 0x34($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X34);
    skip_1:
    // 0x80801C60: swc1        $f30, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f30.u32l;
    // 0x80801C64: jal         0x80087BC0
    // 0x80801C68: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_28(rdram, ctx);
        goto after_2;
    // 0x80801C68: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x80801C6C: sh          $s4, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r20;
L_80801C70:
    // 0x80801C70: lh          $t3, 0x34($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X34);
L_80801C74:
    // 0x80801C74: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x80801C78: addu        $s0, $s1, $t4
    ctx->r16 = ADD32(ctx->r17, ctx->r12);
    // 0x80801C7C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80801C80: nop

    // 0x80801C84: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801C88: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80801C8C: nop

    // 0x80801C90: bc1fl       L_80801CB0
    if (!c1cs) {
        // 0x80801C94: lwc1        $f0, 0x14($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
            goto L_80801CB0;
    }
    goto skip_2;
    // 0x80801C94: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    skip_2:
    // 0x80801C98: sub.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80801C9C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801CA0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80801CA4: nop

    // 0x80801CA8: sh          $t6, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r14;
    // 0x80801CAC: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
L_80801CB0:
    // 0x80801CB0: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80801CB4: mul.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80801CB8: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80801CBC: nop

    // 0x80801CC0: bc1f        L_80801D24
    if (!c1cs) {
        // 0x80801CC4: nop
    
            goto L_80801D24;
    }
    // 0x80801CC4: nop

    // 0x80801CC8: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80801CCC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80801CD0: nop

    // 0x80801CD4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801CD8: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80801CDC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801CE0: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80801CE4: nop

    // 0x80801CE8: bc1f        L_80801D24
    if (!c1cs) {
        // 0x80801CEC: nop
    
            goto L_80801D24;
    }
    // 0x80801CEC: nop

    // 0x80801CF0: jal         0x80087BC8
    // 0x80801CF4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_29(rdram, ctx);
        goto after_3;
    // 0x80801CF4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x80801CF8: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80801CFC: slti        $at, $v0, 0xEC
    ctx->r1 = SIGNED(ctx->r2) < 0XEC ? 1 : 0;
    // 0x80801D00: beq         $at, $zero, L_80801D50
    if (ctx->r1 == 0) {
        // 0x80801D04: sra         $t8, $v1, 16
        ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
            goto L_80801D50;
    }
    // 0x80801D04: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80801D08: addiu       $a1, $t8, 0x14
    ctx->r5 = ADD32(ctx->r24, 0X14);
    // 0x80801D0C: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80801D10: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80801D14: jal         0x80087BC0
    // 0x80801D18: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_28(rdram, ctx);
        goto after_4;
    // 0x80801D18: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_4:
    // 0x80801D1C: b           L_80801D54
    // 0x80801D20: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
        goto L_80801D54;
    // 0x80801D20: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
L_80801D24:
    // 0x80801D24: jal         0x80087BC8
    // 0x80801D28: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_29(rdram, ctx);
        goto after_5;
    // 0x80801D28: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_5:
    // 0x80801D2C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80801D30: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80801D34: bne         $at, $zero, L_80801D50
    if (ctx->r1 != 0) {
        // 0x80801D38: sra         $t1, $v1, 16
        ctx->r9 = S32(SIGNED(ctx->r3) >> 16);
            goto L_80801D50;
    }
    // 0x80801D38: sra         $t1, $v1, 16
    ctx->r9 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80801D3C: addiu       $a1, $t1, -0x14
    ctx->r5 = ADD32(ctx->r9, -0X14);
    // 0x80801D40: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80801D44: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80801D48: jal         0x80087BC0
    // 0x80801D4C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_28(rdram, ctx);
        goto after_6;
    // 0x80801D4C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_6:
L_80801D50:
    // 0x80801D50: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
L_80801D54:
    // 0x80801D54: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x80801D58: nop

    // 0x80801D5C: bc1tl       L_80801E20
    if (c1cs) {
        // 0x80801D60: lh          $t2, 0x2($s1)
        ctx->r10 = MEM_H(ctx->r17, 0X2);
            goto L_80801E20;
    }
    goto skip_3;
    // 0x80801D60: lh          $t2, 0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2);
    skip_3:
    // 0x80801D64: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80801D68: nop

    // 0x80801D6C: bc1fl       L_80801DB0
    if (!c1cs) {
        // 0x80801D70: c.lt.s      $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
            goto L_80801DB0;
    }
    goto skip_4;
    // 0x80801D70: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    skip_4:
    // 0x80801D74: sub.s       $f10, $f2, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f26.fl;
    // 0x80801D78: swc1        $f10, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f10.u32l;
    // 0x80801D7C: lwc1        $f16, 0x80($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80801D80: c.le.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl <= ctx->f20.fl;
    // 0x80801D84: nop

    // 0x80801D88: bc1fl       L_80801D9C
    if (!c1cs) {
        // 0x80801D8C: lbu         $t5, 0x1C($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X1C);
            goto L_80801D9C;
    }
    goto skip_5;
    // 0x80801D8C: lbu         $t5, 0x1C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X1C);
    skip_5:
    // 0x80801D90: b           L_80801DA4
    // 0x80801D94: swc1        $f20, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f20.u32l;
        goto L_80801DA4;
    // 0x80801D94: swc1        $f20, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f20.u32l;
    // 0x80801D98: lbu         $t5, 0x1C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X1C);
L_80801D9C:
    // 0x80801D9C: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80801DA0: sb          $t6, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r14;
L_80801DA4:
    // 0x80801DA4: b           L_80801DF4
    // 0x80801DA8: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
        goto L_80801DF4;
    // 0x80801DA8: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80801DAC: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
L_80801DB0:
    // 0x80801DB0: nop

    // 0x80801DB4: bc1fl       L_80801DF8
    if (!c1cs) {
        // 0x80801DB8: lh          $t0, 0x256($s1)
        ctx->r8 = MEM_H(ctx->r17, 0X256);
            goto L_80801DF8;
    }
    goto skip_6;
    // 0x80801DB8: lh          $t0, 0x256($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X256);
    skip_6:
    // 0x80801DBC: add.s       $f18, $f2, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f26.fl;
    // 0x80801DC0: swc1        $f18, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f18.u32l;
    // 0x80801DC4: lwc1        $f4, 0x80($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80801DC8: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x80801DCC: nop

    // 0x80801DD0: bc1fl       L_80801DE8
    if (!c1cs) {
        // 0x80801DD4: lbu         $t8, 0x1C($s1)
        ctx->r24 = MEM_BU(ctx->r17, 0X1C);
            goto L_80801DE8;
    }
    goto skip_7;
    // 0x80801DD4: lbu         $t8, 0x1C($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1C);
    skip_7:
    // 0x80801DD8: swc1        $f20, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f20.u32l;
    // 0x80801DDC: b           L_80801DF4
    // 0x80801DE0: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
        goto L_80801DF4;
    // 0x80801DE0: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80801DE4: lbu         $t8, 0x1C($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1C);
L_80801DE8:
    // 0x80801DE8: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80801DEC: sb          $t9, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r25;
    // 0x80801DF0: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
L_80801DF4:
    // 0x80801DF4: lh          $t0, 0x256($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X256);
L_80801DF8:
    // 0x80801DF8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801DFC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80801E00: nop

    // 0x80801E04: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801E08: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80801E0C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80801E10: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80801E14: jal         0x80087C10
    // 0x80801E18: nop

    _gczoombox_entrypoint_38(rdram, ctx);
        goto after_7;
    // 0x80801E18: nop

    after_7:
    // 0x80801E1C: lh          $t2, 0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2);
L_80801E20:
    // 0x80801E20: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80801E24: slt         $at, $s3, $t2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80801E28: bnel        $at, $zero, L_80801BCC
    if (ctx->r1 != 0) {
        // 0x80801E2C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801BCC;
    }
    goto skip_8;
    // 0x80801E2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_8:
L_80801E30:
    // 0x80801E30: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80801E34: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801E38: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801E3C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80801E40: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80801E44: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80801E48: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80801E4C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80801E50: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80801E54: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80801E58: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80801E5C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80801E60: jr          $ra
    // 0x80801E64: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80801E64: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
