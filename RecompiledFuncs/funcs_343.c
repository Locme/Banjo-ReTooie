#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _fxdialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B40: syscall     725
    recomp_syscall_handler(rdram, ctx, 0x80088B40);
    return;
    // 0x80088B44: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801A30_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A38: jal         0x808002D4
    // 0x80801A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801A40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801A44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801A48: sb          $zero, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = 0;
    // 0x80801A4C: jal         0x80801680
    // 0x80801A50: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    func_80801680_bsbansack(rdram, ctx);
        goto after_1;
    // 0x80801A50: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80801A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A5C: jr          $ra
    // 0x80801A60: nop

    return;
    // 0x80801A60: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808009F0: jal         0x808008CC
    // 0x808009F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808008CC_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x808009F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009F8: jal         0x80800000
    // 0x808009FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x808009FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A08: jr          $ra
    // 0x80800A0C: nop

    return;
    // 0x80800A0C: nop

;}
RECOMP_FUNC void func_80801634_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801634: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801638: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080163C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801640: jal         0x808006F0
    // 0x80801644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080164C: addiu       $a1, $zero, 0x1D2
    ctx->r5 = ADD32(0, 0X1D2);
    // 0x80801650: jal         0x8008CB3C
    // 0x80801654: lui         $a2, 0x4108
    ctx->r6 = S32(0X4108 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801654: lui         $a2, 0x4108
    ctx->r6 = S32(0X4108 << 16);
    after_1:
    // 0x80801658: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080165C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801664: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801668: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080166C: jal         0x8009FFD8
    // 0x80801670: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801670: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80801674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801678: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x8080167C: jal         0x8009C99C
    // 0x80801680: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80801680: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_3:
    // 0x80801684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801688: jal         0x8009B9B0
    // 0x8080168C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x8080168C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80801690: jal         0x800909CC
    // 0x80801694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_5;
    // 0x80801694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801698: jal         0x80800000
    // 0x8080169C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bstrexlarge(rdram, ctx);
        goto after_6;
    // 0x8080169C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808016A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808016A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808016A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808016AC: jr          $ra
    // 0x808016B0: nop

    return;
    // 0x808016B0: nop

;}
RECOMP_FUNC void func_8009EA94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EA98: jr          $ra
    // 0x8009EA9C: swc1        $f12, 0x706C($at)
    MEM_W(0X706C, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x8009EA9C: swc1        $f12, 0x706C($at)
    MEM_W(0X706C, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800A8190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8190: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8194: jr          $ra
    // 0x800A8198: lbu         $v0, 0x764C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X764C);
    return;
    // 0x800A8198: lbu         $v0, 0x764C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X764C);
;}
RECOMP_FUNC void _ncpod_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089590: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089590);
    return;
    // 0x80089594: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void _chfantasysafe_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087678: syscall     603
    recomp_syscall_handler(rdram, ctx, 0x80087678);
    return;
    // 0x8008767C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _badronemem_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084900: syscall     123
    recomp_syscall_handler(rdram, ctx, 0x80084900);
    return;
    // 0x80084904: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gczoombox_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803814: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803818: beq         $a0, $zero, L_80803840
    if (ctx->r4 == 0) {
        // 0x8080381C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80803840;
    }
    // 0x8080381C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803820: lbu         $v0, 0x171($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X171);
    // 0x80803824: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80803828: beq         $v0, $zero, L_80803840
    if (ctx->r2 == 0) {
        // 0x8080382C: nop
    
            goto L_80803840;
    }
    // 0x8080382C: nop

    // 0x80803830: beq         $v0, $at, L_80803840
    if (ctx->r2 == ctx->r1) {
        // 0x80803834: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80803840;
    }
    // 0x80803834: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80803838: bne         $v0, $at, L_80803848
    if (ctx->r2 != ctx->r1) {
        // 0x8080383C: addiu       $v1, $zero, 0x6
        ctx->r3 = ADD32(0, 0X6);
            goto L_80803848;
    }
    // 0x8080383C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
L_80803840:
    // 0x80803840: b           L_808038B4
    // 0x80803844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808038B4;
    // 0x80803844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803848:
    // 0x80803848: bnel        $v1, $v0, L_8080386C
    if (ctx->r3 != ctx->r2) {
        // 0x8080384C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8080386C;
    }
    goto skip_0;
    // 0x8080384C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_0:
    // 0x80803850: lbu         $t6, 0x170($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X170);
    // 0x80803854: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80803858: bnel        $t6, $at, L_8080386C
    if (ctx->r14 != ctx->r1) {
        // 0x8080385C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8080386C;
    }
    goto skip_1;
    // 0x8080385C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_1:
    // 0x80803860: b           L_808038B4
    // 0x80803864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808038B4;
    // 0x80803864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80803868: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_8080386C:
    // 0x8080386C: bne         $v0, $at, L_8080388C
    if (ctx->r2 != ctx->r1) {
        // 0x80803870: nop
    
            goto L_8080388C;
    }
    // 0x80803870: nop

    // 0x80803874: lbu         $t7, 0x1E5($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E5);
    // 0x80803878: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8080387C: sb          $t9, 0x171($a0)
    MEM_B(0X171, ctx->r4) = ctx->r25;
    // 0x80803880: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80803884: b           L_808038A0
    // 0x80803888: sb          $t8, 0x1E5($a0)
    MEM_B(0X1E5, ctx->r4) = ctx->r24;
        goto L_808038A0;
    // 0x80803888: sb          $t8, 0x1E5($a0)
    MEM_B(0X1E5, ctx->r4) = ctx->r24;
L_8080388C:
    // 0x8080388C: beq         $v1, $v0, L_808038A0
    if (ctx->r3 == ctx->r2) {
        // 0x80803890: nop
    
            goto L_808038A0;
    }
    // 0x80803890: nop

    // 0x80803894: jal         0x808004D0
    // 0x80803898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808004D0_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80803898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080389C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808038A0:
    // 0x808038A0: jal         0x808033D0
    // 0x808038A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gczoombox_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x808038A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808038A8: jal         0x80803430
    // 0x808038AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gczoombox_entrypoint_17(rdram, ctx);
        goto after_2;
    // 0x808038AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808038B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808038B4:
    // 0x808038B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808038B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808038BC: jr          $ra
    // 0x808038C0: nop

    return;
    // 0x808038C0: nop

;}
RECOMP_FUNC void _fxstep_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A10: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A10);
    return;
    // 0x80088A14: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void bafpctrl_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF0: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800BF4: jr          $ra
    // 0x80800BF8: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
    return;
    // 0x80800BF8: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
;}
RECOMP_FUNC void bamovethrust_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000C4: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808000C8: jr          $ra
    // 0x808000CC: swc1        $f12, 0x84($t6)
    MEM_W(0X84, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808000CC: swc1        $f12, 0x84($t6)
    MEM_W(0X84, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800F7BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7BC8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7BCC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7BD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7BD4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7BD8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7BE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F7BE4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F7BE8: jal         0x8009AD14
    // 0x800F7BEC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD14(rdram, ctx);
        goto after_0;
    // 0x800F7BEC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7BF0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7BF4: jal         0x8009E7C8
    // 0x800F7BF8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009E7C8(rdram, ctx);
        goto after_1;
    // 0x800F7BF8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800F7BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7C00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7C04: jr          $ra
    // 0x800F7C08: nop

    return;
    // 0x800F7C08: nop

;}
RECOMP_FUNC void func_80800294_sucoasterhit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80800298: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080029C: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x808002A0: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x808002A4: jal         0x80106790
    // 0x808002A8: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808002A8: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    after_0:
    // 0x808002AC: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x808002B0: jal         0x80088658
    // 0x808002B4: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    _glhittableDll_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808002B4: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_1:
    // 0x808002B8: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x808002BC: jal         0x80088640
    // 0x808002C0: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    _glhittableDll_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808002C0: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_2:
    // 0x808002C4: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x808002C8: jal         0x80088650
    // 0x808002CC: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    _glhittableDll_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808002CC: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_3:
    // 0x808002D0: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x808002D4: jal         0x80088638
    // 0x808002D8: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    _glhittableDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808002D8: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_4:
    // 0x808002DC: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x808002E0: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x808002E4: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x808002E8: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002F0: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x808002F4: sltiu       $t9, $t8, 0x1
    ctx->r25 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x808002F8: jal         0x80100094
    // 0x808002FC: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x808002FC: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    after_5:
    // 0x80800300: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80800304: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80800308: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x8080030C: beql        $t0, $zero, L_80800350
    if (ctx->r8 == 0) {
        // 0x80800310: addiu       $t3, $sp, 0x8C
        ctx->r11 = ADD32(ctx->r29, 0X8C);
            goto L_80800350;
    }
    goto skip_0;
    // 0x80800310: addiu       $t3, $sp, 0x8C
    ctx->r11 = ADD32(ctx->r29, 0X8C);
    skip_0:
    // 0x80800314: lhu         $a0, 0x1A($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X1A);
    // 0x80800318: srl         $t2, $a0, 5
    ctx->r10 = S32(U32(ctx->r4) >> 5);
    // 0x8080031C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80800320: jal         0x800F70EC
    // 0x80800324: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    func_800F70EC(rdram, ctx);
        goto after_6;
    // 0x80800324: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    after_6:
    // 0x80800328: beq         $v0, $zero, L_80800340
    if (ctx->r2 == 0) {
        // 0x8080032C: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_80800340;
    }
    // 0x8080032C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800330: jal         0x800F6C1C
    // 0x80800334: nop

    func_800F6C1C(rdram, ctx);
        goto after_7;
    // 0x80800334: nop

    after_7:
    // 0x80800338: bnel        $v0, $zero, L_80800350
    if (ctx->r2 != 0) {
        // 0x8080033C: addiu       $t3, $sp, 0x8C
        ctx->r11 = ADD32(ctx->r29, 0X8C);
            goto L_80800350;
    }
    goto skip_1;
    // 0x8080033C: addiu       $t3, $sp, 0x8C
    ctx->r11 = ADD32(ctx->r29, 0X8C);
    skip_1:
L_80800340:
    // 0x80800340: jal         0x80088648
    // 0x80800344: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    _glhittableDll_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x80800344: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_8:
    // 0x80800348: bne         $v0, $zero, L_80800860
    if (ctx->r2 != 0) {
        // 0x8080034C: addiu       $t3, $sp, 0x8C
        ctx->r11 = ADD32(ctx->r29, 0X8C);
            goto L_80800860;
    }
    // 0x8080034C: addiu       $t3, $sp, 0x8C
    ctx->r11 = ADD32(ctx->r29, 0X8C);
L_80800350:
    // 0x80800350: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800354: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80800358: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x8080035C: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x80800360: jal         0x80800208
    // 0x80800364: addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    func_80800208_sucoasterhit(rdram, ctx);
        goto after_9;
    // 0x80800364: addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    after_9:
    // 0x80800368: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x8080036C: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x80800370: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80800374: beq         $t4, $zero, L_80800860
    if (ctx->r12 == 0) {
        // 0x80800378: lw          $t8, 0x9C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X9C);
            goto L_80800860;
    }
    // 0x80800378: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8080037C: beq         $t5, $zero, L_8080038C
    if (ctx->r13 == 0) {
        // 0x80800380: lw          $t9, 0x8C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X8C);
            goto L_8080038C;
    }
    // 0x80800380: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x80800384: b           L_808003C0
    // 0x80800388: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
        goto L_808003C0;
    // 0x80800388: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
L_8080038C:
    // 0x8080038C: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80800390: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80800394: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x80800398: mflo        $v0
    ctx->r2 = lo;
    // 0x8080039C: bne         $t6, $zero, L_808003A8
    if (ctx->r14 != 0) {
        // 0x808003A0: nop
    
            goto L_808003A8;
    }
    // 0x808003A0: nop

    // 0x808003A4: break       7
    do_break(2155873188);
L_808003A8:
    // 0x808003A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808003AC: bne         $t6, $at, L_808003C0
    if (ctx->r14 != ctx->r1) {
        // 0x808003B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808003C0;
    }
    // 0x808003B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808003B4: bne         $t7, $at, L_808003C0
    if (ctx->r15 != ctx->r1) {
        // 0x808003B8: nop
    
            goto L_808003C0;
    }
    // 0x808003B8: nop

    // 0x808003BC: break       6
    do_break(2155873212);
L_808003C0:
    // 0x808003C0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x808003C4: lbu         $t1, 0x5C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X5C);
    // 0x808003C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003CC: jal         0x800F0E28
    // 0x808003D0: subu        $a1, $t1, $v0
    ctx->r5 = SUB32(ctx->r9, ctx->r2);
    func_800F0E28(rdram, ctx);
        goto after_10;
    // 0x808003D0: subu        $a1, $t1, $v0
    ctx->r5 = SUB32(ctx->r9, ctx->r2);
    after_10:
    // 0x808003D4: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x808003D8: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x808003DC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x808003E0: sb          $v0, 0x5C($t4)
    MEM_B(0X5C, ctx->r12) = ctx->r2;
    // 0x808003E4: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x808003E8: lbu         $t5, 0x5C($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X5C);
    // 0x808003EC: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x808003F0: beq         $t5, $zero, L_80800420
    if (ctx->r13 == 0) {
        // 0x808003F4: andi        $t6, $t7, 0x1
        ctx->r14 = ctx->r15 & 0X1;
            goto L_80800420;
    }
    // 0x808003F4: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x808003F8: bne         $t6, $zero, L_80800420
    if (ctx->r14 != 0) {
        // 0x808003FC: lw          $t8, 0x90($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X90);
            goto L_80800420;
    }
    // 0x808003FC: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80800400: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80800404: bne         $at, $zero, L_80800420
    if (ctx->r1 != 0) {
        // 0x80800408: lw          $t9, 0x94($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X94);
            goto L_80800420;
    }
    // 0x80800408: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x8080040C: bgez        $t9, L_8080041C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800410: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8080041C;
    }
    // 0x80800410: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80800414: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x80800418: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8080041C:
    // 0x8080041C: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
L_80800420:
    // 0x80800420: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
    // 0x80800424: xori        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 ^ 0X2;
    // 0x80800428: sltiu       $v1, $t1, 0x1
    ctx->r3 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8080042C: beql        $v1, $zero, L_80800444
    if (ctx->r3 == 0) {
        // 0x80800430: lw          $t2, 0x88($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X88);
            goto L_80800444;
    }
    goto skip_2;
    // 0x80800430: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    skip_2:
    // 0x80800434: lbu         $v1, 0x5C($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X5C);
    // 0x80800438: sltiu       $t4, $v1, 0x1
    ctx->r12 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8080043C: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80800440: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
L_80800444:
    // 0x80800444: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    // 0x80800448: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x8080044C: beql        $t3, $zero, L_80800464
    if (ctx->r11 == 0) {
        // 0x80800450: lw          $t5, 0x94($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X94);
            goto L_80800464;
    }
    goto skip_3;
    // 0x80800450: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    skip_3:
    // 0x80800454: bnel        $v1, $zero, L_80800464
    if (ctx->r3 != 0) {
        // 0x80800458: lw          $t5, 0x94($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X94);
            goto L_80800464;
    }
    goto skip_4;
    // 0x80800458: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    skip_4:
    // 0x8080045C: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x80800460: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
L_80800464:
    // 0x80800464: beql        $t5, $zero, L_808005D8
    if (ctx->r13 == 0) {
        // 0x80800468: lw          $v0, 0x88($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X88);
            goto L_808005D8;
    }
    goto skip_5;
    // 0x80800468: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    skip_5:
    // 0x8080046C: jal         0x8008A340
    // 0x80800470: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    _sueggmisc_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800470: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    after_11:
    // 0x80800474: beq         $v0, $zero, L_808004A8
    if (ctx->r2 == 0) {
        // 0x80800478: lw          $t7, 0x78($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X78);
            goto L_808004A8;
    }
    // 0x80800478: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8080047C: jal         0x80106790
    // 0x80800480: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    func_80106790(rdram, ctx);
        goto after_12;
    // 0x80800480: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    after_12:
    // 0x80800484: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800488: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080048C: jal         0x8008A408
    // 0x80800490: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    _suegg_entrypoint_18(rdram, ctx);
        goto after_13;
    // 0x80800490: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_13:
    // 0x80800494: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800498: jal         0x8008A410
    // 0x8080049C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    _suegg_entrypoint_19(rdram, ctx);
        goto after_14;
    // 0x8080049C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_14:
    // 0x808004A0: b           L_80800540
    // 0x808004A4: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
        goto L_80800540;
    // 0x808004A4: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
L_808004A8:
    // 0x808004A8: beq         $t7, $zero, L_8080052C
    if (ctx->r15 == 0) {
        // 0x808004AC: lw          $a0, 0xA4($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XA4);
            goto L_8080052C;
    }
    // 0x808004AC: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x808004B0: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x808004B4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808004B8: lhu         $a0, 0x1A($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X1A);
    // 0x808004BC: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x808004C0: jal         0x800F57F0
    // 0x808004C4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800F57F0(rdram, ctx);
        goto after_15;
    // 0x808004C4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_15:
    // 0x808004C8: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x808004CC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808004D0: lhu         $a0, 0x1A($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X1A);
    // 0x808004D4: srl         $t0, $a0, 5
    ctx->r8 = S32(U32(ctx->r4) >> 5);
    // 0x808004D8: jal         0x800F5D70
    // 0x808004DC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800F5D70(rdram, ctx);
        goto after_16;
    // 0x808004DC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_16:
    // 0x808004E0: jal         0x800EEFD4
    // 0x808004E4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800EEFD4(rdram, ctx);
        goto after_17;
    // 0x808004E4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_17:
    // 0x808004E8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808004EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004F0: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x808004F4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808004F8: nop

    // 0x808004FC: bc1fl       L_80800540
    if (!c1cs) {
        // 0x80800500: lw          $a1, 0x9C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X9C);
            goto L_80800540;
    }
    goto skip_6;
    // 0x80800500: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    skip_6:
    // 0x80800504: lhu         $a0, 0x1A($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X1A);
    // 0x80800508: srl         $t4, $a0, 5
    ctx->r12 = S32(U32(ctx->r4) >> 5);
    // 0x8080050C: jal         0x800F5F24
    // 0x80800510: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800F5F24(rdram, ctx);
        goto after_18;
    // 0x80800510: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_18:
    // 0x80800514: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800518: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080051C: jal         0x800EEB9C
    // 0x80800520: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_19;
    // 0x80800520: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_19:
    // 0x80800524: b           L_80800540
    // 0x80800528: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
        goto L_80800540;
    // 0x80800528: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
L_8080052C:
    // 0x8080052C: jal         0x800EC398
    // 0x80800530: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800EC398(rdram, ctx);
        goto after_20;
    // 0x80800530: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_20:
    // 0x80800534: jal         0x800EFD24
    // 0x80800538: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800EFD24(rdram, ctx);
        goto after_21;
    // 0x80800538: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_21:
    // 0x8080053C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
L_80800540:
    // 0x80800540: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800544: jal         0x800F1DF4
    // 0x80800548: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_22;
    // 0x80800548: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_22:
    // 0x8080054C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800550: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800554: jal         0x800F1EA4
    // 0x80800558: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800F1EA4(rdram, ctx);
        goto after_23;
    // 0x80800558: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_23:
    // 0x8080055C: bne         $v0, $zero, L_8080056C
    if (ctx->r2 != 0) {
        // 0x80800560: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_8080056C;
    }
    // 0x80800560: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800564: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800568: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
L_8080056C:
    // 0x8080056C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800570: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800574: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800578: jal         0x800DC178
    // 0x8080057C: nop

    func_800DC178(rdram, ctx);
        goto after_24;
    // 0x8080057C: nop

    after_24:
    // 0x80800580: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800584: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80800588: jal         0x800136E4
    // 0x8080058C: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    func_800136E4(rdram, ctx);
        goto after_25;
    // 0x8080058C: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    after_25:
    // 0x80800590: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80800594: jal         0x800858E0
    // 0x80800598: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    _chbounce_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x80800598: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_26:
    // 0x8080059C: jal         0x800858D8
    // 0x808005A0: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    _chbounce_entrypoint_2(rdram, ctx);
        goto after_27;
    // 0x808005A0: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    after_27:
    // 0x808005A4: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x808005A8: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x808005AC: jal         0x800858F0
    // 0x808005B0: addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
    _chbounce_entrypoint_5(rdram, ctx);
        goto after_28;
    // 0x808005B0: addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
    after_28:
    // 0x808005B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808005B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005BC: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x808005C0: jal         0x800136E4
    // 0x808005C4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_29;
    // 0x808005C4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_29:
    // 0x808005C8: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x808005CC: swc1        $f0, 0x54($t2)
    MEM_W(0X54, ctx->r10) = ctx->f0.u32l;
    // 0x808005D0: swc1        $f0, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f0.u32l;
    // 0x808005D4: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
L_808005D8:
    // 0x808005D8: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x808005DC: sltiu       $v1, $t3, 0x1
    ctx->r3 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x808005E0: bne         $v1, $zero, L_808005F4
    if (ctx->r3 != 0) {
        // 0x808005E4: nop
    
            goto L_808005F4;
    }
    // 0x808005E4: nop

    // 0x808005E8: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x808005EC: sltu        $t7, $zero, $v1
    ctx->r15 = 0 < ctx->r3 ? 1 : 0;
    // 0x808005F0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_808005F4:
    // 0x808005F4: beq         $v1, $zero, L_80800684
    if (ctx->r3 == 0) {
        // 0x808005F8: sw          $v1, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r3;
            goto L_80800684;
    }
    // 0x808005F8: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    // 0x808005FC: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x80800600: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800604: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80800608: beq         $t6, $at, L_8080064C
    if (ctx->r14 == ctx->r1) {
        // 0x8080060C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080064C;
    }
    // 0x8080060C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800610: bne         $t6, $at, L_80800684
    if (ctx->r14 != ctx->r1) {
        // 0x80800614: lw          $a0, 0x9C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X9C);
            goto L_80800684;
    }
    // 0x80800614: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80800618: jal         0x80109600
    // 0x8080061C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    func_80109600(rdram, ctx);
        goto after_30;
    // 0x8080061C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    after_30:
    // 0x80800620: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80800624: addiu       $at, $zero, 0x26D
    ctx->r1 = ADD32(0, 0X26D);
    // 0x80800628: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x8080062C: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80800630: srl         $t0, $t9, 22
    ctx->r8 = S32(U32(ctx->r25) >> 22);
    // 0x80800634: bnel        $t0, $at, L_80800688
    if (ctx->r8 != ctx->r1) {
        // 0x80800638: lw          $t3, 0x90($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X90);
            goto L_80800688;
    }
    goto skip_7;
    // 0x80800638: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    skip_7:
    // 0x8080063C: jal         0x800860D0
    // 0x80800640: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    _chflamer_entrypoint_1(rdram, ctx);
        goto after_31;
    // 0x80800640: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    after_31:
    // 0x80800644: b           L_80800688
    // 0x80800648: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
        goto L_80800688;
    // 0x80800648: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
L_8080064C:
    // 0x8080064C: jal         0x80109600
    // 0x80800650: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    func_80109600(rdram, ctx);
        goto after_32;
    // 0x80800650: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    after_32:
    // 0x80800654: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x80800658: addiu       $at, $zero, 0x26E
    ctx->r1 = ADD32(0, 0X26E);
    // 0x8080065C: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x80800660: lw          $t4, 0x24($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X24);
    // 0x80800664: srl         $t2, $t4, 22
    ctx->r10 = S32(U32(ctx->r12) >> 22);
    // 0x80800668: bnel        $t2, $at, L_80800688
    if (ctx->r10 != ctx->r1) {
        // 0x8080066C: lw          $t3, 0x90($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X90);
            goto L_80800688;
    }
    goto skip_8;
    // 0x8080066C: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    skip_8:
    // 0x80800670: jal         0x800EC370
    // 0x80800674: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800EC370(rdram, ctx);
        goto after_33;
    // 0x80800674: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_33:
    // 0x80800678: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x8080067C: jal         0x80085F80
    // 0x80800680: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _chfreezy_entrypoint_1(rdram, ctx);
        goto after_34;
    // 0x80800680: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_34:
L_80800684:
    // 0x80800684: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
L_80800688:
    // 0x80800688: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x8080068C: beql        $t3, $zero, L_808006E0
    if (ctx->r11 == 0) {
        // 0x80800690: lw          $t6, 0x9C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X9C);
            goto L_808006E0;
    }
    goto skip_9;
    // 0x80800690: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    skip_9:
    // 0x80800694: lhu         $t7, 0x72($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X72);
    // 0x80800698: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080069C: srl         $t6, $t7, 10
    ctx->r14 = S32(U32(ctx->r15) >> 10);
    // 0x808006A0: bnel        $t6, $at, L_808006E0
    if (ctx->r14 != ctx->r1) {
        // 0x808006A4: lw          $t6, 0x9C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X9C);
            goto L_808006E0;
    }
    goto skip_10;
    // 0x808006A4: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    skip_10:
    // 0x808006A8: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x808006AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006B0: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x808006B4: sll         $t0, $t9, 11
    ctx->r8 = S32(ctx->r25 << 11);
    // 0x808006B8: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x808006BC: bnel        $t1, $at, L_808006E0
    if (ctx->r9 != ctx->r1) {
        // 0x808006C0: lw          $t6, 0x9C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X9C);
            goto L_808006E0;
    }
    goto skip_11;
    // 0x808006C0: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    skip_11:
    // 0x808006C4: jal         0x8010965C
    // 0x808006C8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_8010965C(rdram, ctx);
        goto after_35;
    // 0x808006C8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_35:
    // 0x808006CC: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x808006D0: lbu         $t3, 0x19($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X19);
    // 0x808006D4: ori         $t7, $t3, 0x20
    ctx->r15 = ctx->r11 | 0X20;
    // 0x808006D8: sb          $t7, 0x19($t4)
    MEM_B(0X19, ctx->r12) = ctx->r15;
    // 0x808006DC: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
L_808006E0:
    // 0x808006E0: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x808006E4: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x808006E8: lbu         $v0, 0x5C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5C);
    // 0x808006EC: beq         $v0, $zero, L_808006FC
    if (ctx->r2 == 0) {
        // 0x808006F0: nop
    
            goto L_808006FC;
    }
    // 0x808006F0: nop

    // 0x808006F4: beql        $t8, $zero, L_80800828
    if (ctx->r24 == 0) {
        // 0x808006F8: lw          $t5, 0x80($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X80);
            goto L_80800828;
    }
    goto skip_12;
    // 0x808006F8: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    skip_12:
L_808006FC:
    // 0x808006FC: beq         $v0, $zero, L_80800710
    if (ctx->r2 == 0) {
        // 0x80800700: lw          $t9, 0x8C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X8C);
            goto L_80800710;
    }
    // 0x80800700: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x80800704: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800708: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x8080070C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_80800710:
    // 0x80800710: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80800714: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800718: addiu       $t5, $zero, 0x63
    ctx->r13 = ADD32(0, 0X63);
    // 0x8080071C: beql        $t1, $at, L_8080072C
    if (ctx->r9 == ctx->r1) {
        // 0x80800720: lw          $t2, 0x8C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X8C);
            goto L_8080072C;
    }
    goto skip_13;
    // 0x80800720: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    skip_13:
    // 0x80800724: sb          $t5, 0x5C($a0)
    MEM_B(0X5C, ctx->r4) = ctx->r13;
    // 0x80800728: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
L_8080072C:
    // 0x8080072C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800730: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x80800734: bnel        $t2, $at, L_808007C8
    if (ctx->r10 != ctx->r1) {
        // 0x80800738: lw          $t8, 0x8C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X8C);
            goto L_808007C8;
    }
    goto skip_14;
    // 0x80800738: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    skip_14:
    // 0x8080073C: beql        $t3, $zero, L_808007C8
    if (ctx->r11 == 0) {
        // 0x80800740: lw          $t8, 0x8C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X8C);
            goto L_808007C8;
    }
    goto skip_15;
    // 0x80800740: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    skip_15:
    // 0x80800744: jal         0x8010A430
    // 0x80800748: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    func_8010A430(rdram, ctx);
        goto after_36;
    // 0x80800748: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    after_36:
    // 0x8080074C: beql        $v0, $zero, L_808007C8
    if (ctx->r2 == 0) {
        // 0x80800750: lw          $t8, 0x8C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X8C);
            goto L_808007C8;
    }
    goto skip_16;
    // 0x80800750: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    skip_16:
    // 0x80800754: jal         0x800F54E4
    // 0x80800758: nop

    func_800F54E4(rdram, ctx);
        goto after_37;
    // 0x80800758: nop

    after_37:
    // 0x8080075C: jal         0x800F5F24
    // 0x80800760: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5F24(rdram, ctx);
        goto after_38;
    // 0x80800760: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_38:
    // 0x80800764: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800768: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8080076C: addiu       $a0, $a0, -0x710C
    ctx->r4 = ADD32(ctx->r4, -0X710C);
    // 0x80800770: jal         0x800EB860
    // 0x80800774: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    func_800EB860(rdram, ctx);
        goto after_39;
    // 0x80800774: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    after_39:
    // 0x80800778: jal         0x800EC708
    // 0x8080077C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    func_800EC708(rdram, ctx);
        goto after_40;
    // 0x8080077C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_40:
    // 0x80800780: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80800784: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x80800788: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8080078C: lwc1        $f10, 0x8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80800790: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800794: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80800798: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8080079C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x808007A0: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x808007A4: lw          $t4, 0xC($t7)
    ctx->r12 = MEM_W(ctx->r15, 0XC);
    // 0x808007A8: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x808007AC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808007B0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808007B4: jal         0x80086D50
    // 0x808007B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_41;
    // 0x808007B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_41:
    // 0x808007BC: jal         0x800EB874
    // 0x808007C0: nop

    func_800EB874(rdram, ctx);
        goto after_42;
    // 0x808007C0: nop

    after_42:
    // 0x808007C4: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
L_808007C8:
    // 0x808007C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007CC: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x808007D0: beq         $t8, $zero, L_808007F4
    if (ctx->r24 == 0) {
        // 0x808007D4: lw          $a1, 0xA4($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XA4);
            goto L_808007F4;
    }
    // 0x808007D4: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x808007D8: beq         $t8, $at, L_80800804
    if (ctx->r24 == ctx->r1) {
        // 0x808007DC: lw          $t0, 0x9C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X9C);
            goto L_80800804;
    }
    // 0x808007DC: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x808007E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007E4: beq         $t8, $at, L_80800818
    if (ctx->r24 == ctx->r1) {
        // 0x808007E8: lw          $t1, 0x9C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X9C);
            goto L_80800818;
    }
    // 0x808007E8: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x808007EC: b           L_80800828
    // 0x808007F0: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
        goto L_80800828;
    // 0x808007F0: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
L_808007F4:
    // 0x808007F4: jal         0x8080000C
    // 0x808007F8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_8080000C_sucoasterhit(rdram, ctx);
        goto after_43;
    // 0x808007F8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_43:
    // 0x808007FC: b           L_80800828
    // 0x80800800: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
        goto L_80800828;
    // 0x80800800: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
L_80800804:
    // 0x80800804: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80800808: jal         0x80800114
    // 0x8080080C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    func_80800114_sucoasterhit(rdram, ctx);
        goto after_44;
    // 0x8080080C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    after_44:
    // 0x80800810: b           L_80800828
    // 0x80800814: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
        goto L_80800828;
    // 0x80800814: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
L_80800818:
    // 0x80800818: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8080081C: jal         0x808001C8
    // 0x80800820: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    func_808001C8_sucoasterhit(rdram, ctx);
        goto after_45;
    // 0x80800820: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    after_45:
    // 0x80800824: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
L_80800828:
    // 0x80800828: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x8080082C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(3302, 0XCC4) << 16);
    // 0x80800830: beq         $t5, $zero, L_80800860
    if (ctx->r13 == 0) {
        // 0x80800834: addiu       $a2, $t2, 0x4
        ctx->r6 = ADD32(ctx->r10, 0X4);
            goto L_80800860;
    }
    // 0x80800834: addiu       $a2, $t2, 0x4
    ctx->r6 = ADD32(ctx->r10, 0X4);
    // 0x80800838: lw          $a1, 0x70($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X70);
    // 0x8080083C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800840: addiu       $a3, $a3, 0xCC4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(3302, 0XCC4));
    // 0x80800844: andi        $t3, $a1, 0x1
    ctx->r11 = ctx->r5 & 0X1;
    // 0x80800848: jal         0x8010D930
    // 0x8080084C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8010D930(rdram, ctx);
        goto after_46;
    // 0x8080084C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_46:
    // 0x80800850: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80800854: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800858: jal         0x80089BF8
    // 0x8080085C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _subaddiejoy_entrypoint_10(rdram, ctx);
        goto after_47;
    // 0x8080085C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_47:
L_80800860:
    // 0x80800860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800864: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80800868: jr          $ra
    // 0x8080086C: nop

    return;
    // 0x8080086C: nop

;}
RECOMP_FUNC void _susubgame_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2C0: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2C0);
    return;
    // 0x8008A2C4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chdoubloon_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087458: syscall     572
    recomp_syscall_handler(rdram, ctx, 0x80087458);
    return;
    // 0x8008745C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808001D0_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001DC: jal         0x808019C8
    // 0x808001E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808019C8_chalienkids(rdram, ctx);
        goto after_0;
    // 0x808001E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001E4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808001E8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808001EC: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x808001F0: sltiu       $at, $t8, 0xF
    ctx->r1 = ctx->r24 < 0XF ? 1 : 0;
    // 0x808001F4: beq         $at, $zero, L_80800344
    if (ctx->r1 == 0) {
        // 0x808001F8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800344;
    }
    // 0x808001F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808001FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1324, 0X1C8C) << 16);
    // 0x80800200: addu        $at, $at, $t8
    gpr jr_addend_80800208 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800204: lw          $t8, 0x1C8C($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1324, 0X1C8C));
    // 0x80800208: jr          $t8
    // 0x8080020C: nop

    switch (jr_addend_80800208 >> 2) {
        case 0: goto L_80800210; break;
        case 1: goto L_80800220; break;
        case 2: goto L_80800344; break;
        case 3: goto L_80800344; break;
        case 4: goto L_80800344; break;
        case 5: goto L_80800250; break;
        case 6: goto L_80800278; break;
        case 7: goto L_80800344; break;
        case 8: goto L_80800344; break;
        case 9: goto L_80800344; break;
        case 10: goto L_80800344; break;
        case 11: goto L_80800344; break;
        case 12: goto L_80800344; break;
        case 13: goto L_808002EC; break;
        case 14: goto L_80800330; break;
        default: switch_error(__func__, 0x80800208, 0x80801C8C);
    }
    // 0x8080020C: nop

L_80800210:
    // 0x80800210: jal         0x80801884
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801884_chalienkids(rdram, ctx);
        goto after_1;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800218: b           L_80800344
    // 0x8080021C: nop

        goto L_80800344;
    // 0x8080021C: nop

L_80800220:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x80801158
    // 0x80800228: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    func_80801158_chalienkids(rdram, ctx);
        goto after_2;
    // 0x80800228: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    after_2:
    // 0x8080022C: beq         $v0, $zero, L_80800344
    if (ctx->r2 == 0) {
        // 0x80800230: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800344;
    }
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: jal         0x80102424
    // 0x80800238: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800238: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: jal         0x8008A4B0
    // 0x80800244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800248: b           L_80800344
    // 0x8080024C: nop

        goto L_80800344;
    // 0x8080024C: nop

L_80800250:
    // 0x80800250: jal         0x800D9078
    // 0x80800254: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x80800254: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_5:
    // 0x80800258: beq         $v0, $zero, L_80800344
    if (ctx->r2 == 0) {
        // 0x8080025C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800344;
    }
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: jal         0x80102424
    // 0x80800264: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800264: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x80800268: lbu         $t9, 0x77($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X77);
    // 0x8080026C: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x80800270: b           L_80800344
    // 0x80800274: sb          $t0, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r8;
        goto L_80800344;
    // 0x80800274: sb          $t0, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r8;
L_80800278:
    // 0x80800278: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8080027C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800280: jal         0x80101E14
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_7;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800288: beq         $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x8080028C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800298;
    }
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x8010A85C
    // 0x80800294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_8;
    // 0x80800294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_80800298:
    // 0x80800298: jal         0x80101DDC
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_9;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002A0: beq         $v0, $zero, L_80800344
    if (ctx->r2 == 0) {
        // 0x808002A4: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80800344;
    }
    // 0x808002A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002AC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x808002B0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x808002B4: jal         0x8008A0E0
    // 0x808002B8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x808002B8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_10:
    // 0x808002BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002C0: addiu       $t1, $zero, 0xB7
    ctx->r9 = ADD32(0, 0XB7);
    // 0x808002C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808002C8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808002CC: addiu       $a1, $zero, 0x1285
    ctx->r5 = ADD32(0, 0X1285);
    // 0x808002D0: jal         0x8008A208
    // 0x808002D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x808002D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: jal         0x80102424
    // 0x808002E0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x808002E0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_12:
    // 0x808002E4: b           L_80800344
    // 0x808002E8: nop

        goto L_80800344;
    // 0x808002E8: nop

L_808002EC:
    // 0x808002EC: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x808002F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808002F4: andi        $t2, $v0, 0x1FF
    ctx->r10 = ctx->r2 & 0X1FF;
    // 0x808002F8: beql        $t2, $zero, L_80800320
    if (ctx->r10 == 0) {
        // 0x808002FC: addiu       $a1, $zero, 0x1005
        ctx->r5 = ADD32(0, 0X1005);
            goto L_80800320;
    }
    goto skip_0;
    // 0x808002FC: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    skip_0:
    // 0x80800300: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800304: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80800308: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x8080030C: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x80800310: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80800314: b           L_80800320
    // 0x80800318: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
        goto L_80800320;
    // 0x80800318: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    // 0x8080031C: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
L_80800320:
    // 0x80800320: jal         0x8010B990
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_13;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800328: b           L_80800344
    // 0x8080032C: nop

        goto L_80800344;
    // 0x8080032C: nop

L_80800330:
    // 0x80800330: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1324, 0X1E80) << 16);
    // 0x80800334: addiu       $a1, $a1, 0x1E80
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1324, 0X1E80));
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: jal         0x8080184C
    // 0x80800340: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8080184C_chalienkids(rdram, ctx);
        goto after_14;
    // 0x80800340: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_14:
L_80800344:
    // 0x80800344: jal         0x808016D4
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016D4_chalienkids(rdram, ctx);
        goto after_15;
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080034C: jal         0x8080158C
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080158C_chalienkids(rdram, ctx);
        goto after_16;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800354: jal         0x80801628
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801628_chalienkids(rdram, ctx);
        goto after_17;
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080035C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800360: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800364: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800368: jr          $ra
    // 0x8080036C: nop

    return;
    // 0x8080036C: nop

;}
RECOMP_FUNC void bsbpeck_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x8009E710
    // 0x80800014: sw          $zero, 0x164($a0)
    MEM_W(0X164, ctx->r4) = 0;
    bs_getPreviousState(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $zero, 0x164($a0)
    MEM_W(0X164, ctx->r4) = 0;
    after_0:
    // 0x80800018: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080001C: beq         $v0, $at, L_80800058
    if (ctx->r2 == ctx->r1) {
        // 0x80800020: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800058;
    }
    // 0x80800020: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800024: beq         $v0, $at, L_8080004C
    if (ctx->r2 == ctx->r1) {
        // 0x80800028: addiu       $at, $zero, 0x2F
        ctx->r1 = ADD32(0, 0X2F);
            goto L_8080004C;
    }
    // 0x80800028: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x8080002C: beq         $v0, $at, L_80800058
    if (ctx->r2 == ctx->r1) {
        // 0x80800030: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80800058;
    }
    // 0x80800030: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800034: beq         $v0, $at, L_80800058
    if (ctx->r2 == ctx->r1) {
        // 0x80800038: addiu       $at, $zero, 0x57
        ctx->r1 = ADD32(0, 0X57);
            goto L_80800058;
    }
    // 0x80800038: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8080003C: beq         $v0, $at, L_80800058
    if (ctx->r2 == ctx->r1) {
        // 0x80800040: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800058;
    }
    // 0x80800040: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800044: bne         $v0, $at, L_80800058
    if (ctx->r2 != ctx->r1) {
        // 0x80800048: nop
    
            goto L_80800058;
    }
    // 0x80800048: nop

L_8080004C:
    // 0x8080004C: lw          $t6, 0x164($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X164);
    // 0x80800050: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800054: sw          $t7, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r15;
L_80800058:
    // 0x80800058: jal         0x8009557C
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009557C(rdram, ctx);
        goto after_1;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800064: bne         $v0, $at, L_80800074
    if (ctx->r2 != ctx->r1) {
        // 0x80800068: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800074;
    }
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: jal         0x80095588
    // 0x80800070: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80095588(rdram, ctx);
        goto after_2;
    // 0x80800070: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_80800074:
    // 0x80800074: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800078: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: jal         0x8008CDB8
    // 0x80800084: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    baanim_playForDuration_once(rdram, ctx);
        goto after_3;
    // 0x80800084: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_3:
    // 0x80800088: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8080008C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800098: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080009C: jal         0x8009FFD8
    // 0x808000A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_4;
    // 0x808000A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    // 0x808000AC: jal         0x8009C99C
    // 0x808000B0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_5;
    // 0x808000B0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_5:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x800A0CF4
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_6;
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x8009BCB4
    // 0x808000C8: lui         $a1, 0xC4AF
    ctx->r5 = S32(0XC4AF << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_7;
    // 0x808000C8: lui         $a1, 0xC4AF
    ctx->r5 = S32(0XC4AF << 16);
    after_7:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x8009BA58
    // 0x808000D4: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_8;
    // 0x808000D4: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    after_8:
    // 0x808000D8: jal         0x8009E4AC
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_9;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000E8: jal         0x8009E55C
    // 0x808000EC: lui         $a2, 0x420C
    ctx->r6 = S32(0X420C << 16);
    func_8009E55C(rdram, ctx);
        goto after_10;
    // 0x808000EC: lui         $a2, 0x420C
    ctx->r6 = S32(0X420C << 16);
    after_10:
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F8: jal         0x8009E55C
    // 0x808000FC: lui         $a2, 0x4228
    ctx->r6 = S32(0X4228 << 16);
    func_8009E55C(rdram, ctx);
        goto after_11;
    // 0x808000FC: lui         $a2, 0x4228
    ctx->r6 = S32(0X4228 << 16);
    after_11:
    // 0x80800100: lui         $at, 0x42D2
    ctx->r1 = S32(0X42D2 << 16);
    // 0x80800104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800110: lui         $a2, 0xC218
    ctx->r6 = S32(0XC218 << 16);
    // 0x80800114: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800118: jal         0x8009E4FC
    // 0x8080011C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8009E4FC(rdram, ctx);
        goto after_12;
    // 0x8080011C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80800120: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x80800124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800130: lui         $a2, 0xC218
    ctx->r6 = S32(0XC218 << 16);
    // 0x80800134: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800138: jal         0x8009E4FC
    // 0x8080013C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8009E4FC(rdram, ctx);
        goto after_13;
    // 0x8080013C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x80800140: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800144: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x80095760
    // 0x80800150: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    baflag_set(rdram, ctx);
        goto after_14;
    // 0x80800150: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_14:
    // 0x80800154: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800158: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080015C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void func_80808C48_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808C48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808C4C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80808C50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80808C54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808C58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80808C5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808C60: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    // 0x80808C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80808C68: jal         0x80808CAC
    // 0x80808C6C: swc1        $f4, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f4.u32l;
    func_80808CAC_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808C6C: swc1        $f4, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80808C70: jal         0x80808D80
    // 0x80808C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808D80_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80808C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80808C78: jal         0x8008CABC
    // 0x80808C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_2;
    // 0x80808C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80808C80: jal         0x8008B304
    // 0x80808C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B304(rdram, ctx);
        goto after_3;
    // 0x80808C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80808C88: jal         0x8008D04C
    // 0x80808C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D04C(rdram, ctx);
        goto after_4;
    // 0x80808C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80808C90: jal         0x8008B304
    // 0x80808C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B304(rdram, ctx);
        goto after_5;
    // 0x80808C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80808C98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80808C9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80808CA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80808CA4: jr          $ra
    // 0x80808CA8: nop

    return;
    // 0x80808CA8: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80800170: jr          $ra
    // 0x80800174: lbu         $v0, -0x4BF2($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4BF2);
    return;
    // 0x80800174: lbu         $v0, -0x4BF2($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4BF2);
;}
RECOMP_FUNC void func_80800014_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800020: jal         0x800D3948
    // 0x80800024: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80800024: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080002C: beq         $v0, $zero, L_80800084
    if (ctx->r2 == 0) {
        // 0x80800030: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800084;
    }
    // 0x80800030: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800034: beq         $a1, $zero, L_8080005C
    if (ctx->r5 == 0) {
        // 0x80800038: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8080005C;
    }
    // 0x80800038: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080003C: beq         $a1, $at, L_80800064
    if (ctx->r5 == ctx->r1) {
        // 0x80800040: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800064;
    }
    // 0x80800040: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800044: beq         $a1, $at, L_8080006C
    if (ctx->r5 == ctx->r1) {
        // 0x80800048: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080006C;
    }
    // 0x80800048: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080004C: beq         $a1, $at, L_80800074
    if (ctx->r5 == ctx->r1) {
        // 0x80800050: nop
    
            goto L_80800074;
    }
    // 0x80800050: nop

    // 0x80800054: b           L_80800088
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800088;
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080005C:
    // 0x8080005C: b           L_80800088
    // 0x80800060: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
        goto L_80800088;
    // 0x80800060: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
L_80800064:
    // 0x80800064: b           L_80800088
    // 0x80800068: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
        goto L_80800088;
    // 0x80800068: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
L_8080006C:
    // 0x8080006C: b           L_80800088
    // 0x80800070: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
        goto L_80800088;
    // 0x80800070: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
L_80800074:
    // 0x80800074: b           L_80800088
    // 0x80800078: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
        goto L_80800088;
    // 0x80800078: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8080007C: b           L_80800088
    // 0x80800080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800088;
    // 0x80800080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800084:
    // 0x80800084: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
L_80800088:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080008C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void _chdinofamilymissing_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087460: syscall     573
    recomp_syscall_handler(rdram, ctx, 0x80087460);
    return;
    // 0x80087464: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chwumbawigwam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087478: syscall     576
    recomp_syscall_handler(rdram, ctx, 0x80087478);
    return;
    // 0x8008747C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A8FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A8FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A8FE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8FE8: jal         0x800A877C
    // 0x800A8FEC: lh          $a0, 0x76D2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X76D2);
    func_800A877C(rdram, ctx);
        goto after_0;
    // 0x800A8FEC: lh          $a0, 0x76D2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X76D2);
    after_0:
    // 0x800A8FF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8FF4: addiu       $a1, $a1, 0x76D0
    ctx->r5 = ADD32(ctx->r5, 0X76D0);
    // 0x800A8FF8: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    // 0x800A8FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9004: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800A9008: jr          $ra
    // 0x800A900C: sh          $t6, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r14;
    return;
    // 0x800A900C: sh          $t6, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r14;
;}
RECOMP_FUNC void mlspline_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801780: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801784: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80801788: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8080178C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3006, 0X1C6C) << 16);
    // 0x80801790: lwc1        $f4, 0x1C6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3006, 0X1C6C));
    // 0x80801794: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80801798: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8080179C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808017A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808017A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808017A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808017AC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x808017B0: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808017B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808017B8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x808017BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808017C0: jal         0x80801488
    // 0x808017C4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_80801488_mlspline(rdram, ctx);
        goto after_0;
    // 0x808017C4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x808017C8: jal         0x800F2100
    // 0x808017CC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x808017CC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x808017D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808017D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808017D8: jr          $ra
    // 0x808017DC: nop

    return;
    // 0x808017DC: nop

;}
RECOMP_FUNC void _ncfixposrot_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089200: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x80089200);
    return;
    // 0x80089204: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chexploder_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866A0: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x800866A0);
    return;
    // 0x800866A4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800F4F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4F98: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4FA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4FA8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4FAC: jal         0x80084460
    // 0x800F4FB0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _baattach_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800F4FB0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4FBC: jr          $ra
    // 0x800F4FC0: nop

    return;
    // 0x800F4FC0: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080387C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80803880: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB494) << 16);
    // 0x80803884: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80803888: jr          $ra
    // 0x8080388C: lw          $v0, -0x4B6C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB494));
    return;
    // 0x8080388C: lw          $v0, -0x4B6C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB494));
;}
RECOMP_FUNC void func_8010C754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C75C: jal         0x8010C710
    // 0x8010C760: nop

    func_8010C710(rdram, ctx);
        goto after_0;
    // 0x8010C760: nop

    after_0:
    // 0x8010C764: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8010C768: jal         0x8002DCA0
    // 0x8010C76C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8010C76C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x8010C770: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010C774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C77C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8010C780: jr          $ra
    // 0x8010C784: nop

    return;
    // 0x8010C784: nop

;}
RECOMP_FUNC void chminisubgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(792, 0X146C) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x146C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(792, 0X146C));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x146C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(792, 0X146C));
;}
RECOMP_FUNC void func_80800210_choctopus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800218: jal         0x808007E4
    // 0x8080021C: nop

    func_808007E4_choctopus(rdram, ctx);
        goto after_0;
    // 0x8080021C: nop

    after_0:
    // 0x80800220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800228: jr          $ra
    // 0x8080022C: nop

    return;
    // 0x8080022C: nop

;}
RECOMP_FUNC void func_808008F0_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008F8: jal         0x80099B94
    // 0x808008FC: nop

    func_80099B94(rdram, ctx);
        goto after_0;
    // 0x808008FC: nop

    after_0:
    // 0x80800900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800908: jr          $ra
    // 0x8080090C: nop

    return;
    // 0x8080090C: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C40: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087C40);
    return;
    // 0x80087C44: addi        $t0, $zero, 0xB0
    ctx->r8 = ADD32(0, 0XB0);
;}
RECOMP_FUNC void func_800EA370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA378: jal         0x800EA3A0
    // 0x800EA37C: nop

    func_800EA3A0(rdram, ctx);
        goto after_0;
    // 0x800EA37C: nop

    after_0:
    // 0x800EA380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA388: jr          $ra
    // 0x800EA38C: nop

    return;
    // 0x800EA38C: nop

;}
RECOMP_FUNC void func_80116914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116914: addiu       $sp, $sp, -0x5F8
    ctx->r29 = ADD32(ctx->r29, -0X5F8);
    // 0x80116918: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8011691C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80116920: addiu       $s1, $sp, 0x5B0
    ctx->r17 = ADD32(ctx->r29, 0X5B0);
    // 0x80116924: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80116928: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8011692C: sw          $a1, 0x5FC($sp)
    MEM_W(0X5FC, ctx->r29) = ctx->r5;
    // 0x80116930: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80116934: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80116938: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8011693C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80116940: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80116944: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80116948: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8011694C: sw          $a2, 0x600($sp)
    MEM_W(0X600, ctx->r29) = ctx->r6;
    // 0x80116950: sw          $a3, 0x604($sp)
    MEM_W(0X604, ctx->r29) = ctx->r7;
    // 0x80116954: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x80116958: jal         0x8002D6E0
    // 0x8011695C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bzero(rdram, ctx);
        goto after_0;
    // 0x8011695C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80116960: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x80116964: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x80116968: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8011696C: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x80116970: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80116974: beq         $v0, $zero, L_801169AC
    if (ctx->r2 == 0) {
        // 0x80116978: or          $ra, $t6, $zero
        ctx->r31 = ctx->r14 | 0;
            goto L_801169AC;
    }
    // 0x80116978: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x8011697C: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
L_80116980:
    // 0x80116980: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80116984: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x80116988: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8011698C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80116990: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x80116994: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80116998: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8011699C: bne         $v1, $ra, L_80116980
    if (ctx->r3 != ctx->r31) {
        // 0x801169A0: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_80116980;
    }
    // 0x801169A0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801169A4: beql        $ra, $zero, L_80116A1C
    if (ctx->r31 == 0) {
        // 0x801169A8: lw          $t7, 0x5FC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5FC);
            goto L_80116A1C;
    }
    goto skip_0;
    // 0x801169A8: lw          $t7, 0x5FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5FC);
    skip_0:
L_801169AC:
    // 0x801169AC: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x801169B0: addiu       $ra, $ra, -0x4
    ctx->r31 = ADD32(ctx->r31, -0X4);
    // 0x801169B4: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    // 0x801169B8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801169BC: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x801169C0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801169C4: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x801169C8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801169CC: lw          $t7, -0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, -0XC);
    // 0x801169D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801169D4: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x801169D8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801169DC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x801169E0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801169E4: lw          $t7, -0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X8);
    // 0x801169E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801169EC: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x801169F0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801169F4: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x801169F8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801169FC: lw          $t7, -0x4($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X4);
    // 0x80116A00: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80116A04: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x80116A08: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80116A0C: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80116A10: bne         $ra, $zero, L_801169AC
    if (ctx->r31 != 0) {
        // 0x80116A14: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_801169AC;
    }
    // 0x80116A14: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80116A18: lw          $t7, 0x5FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5FC);
L_80116A1C:
    // 0x80116A1C: lw          $t8, 0x5B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5B0);
    // 0x80116A20: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x80116A24: addiu       $a0, $sp, 0x5B4
    ctx->r4 = ADD32(ctx->r29, 0X5B4);
    // 0x80116A28: bne         $t7, $t8, L_80116A44
    if (ctx->r15 != ctx->r24) {
        // 0x80116A2C: addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
            goto L_80116A44;
    }
    // 0x80116A2C: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80116A30: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x80116A34: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x80116A38: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x80116A3C: b           L_80116EFC
    // 0x80116A40: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_80116EFC;
    // 0x80116A40: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80116A44:
    // 0x80116A44: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
L_80116A48:
    // 0x80116A48: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80116A4C: bnel        $t9, $zero, L_80116A64
    if (ctx->r25 != 0) {
        // 0x80116A50: sltu        $at, $s0, $a3
        ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
            goto L_80116A64;
    }
    goto skip_1;
    // 0x80116A50: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    skip_1:
    // 0x80116A54: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80116A58: bne         $a3, $v0, L_80116A48
    if (ctx->r7 != ctx->r2) {
        // 0x80116A5C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80116A48;
    }
    // 0x80116A5C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80116A60: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
L_80116A64:
    // 0x80116A64: beq         $at, $zero, L_80116A70
    if (ctx->r1 == 0) {
        // 0x80116A68: or          $s4, $a3, $zero
        ctx->r20 = ctx->r7 | 0;
            goto L_80116A70;
    }
    // 0x80116A68: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80116A6C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
L_80116A70:
    // 0x80116A70: addiu       $ra, $zero, 0x10
    ctx->r31 = ADD32(0, 0X10);
    // 0x80116A74: addiu       $v1, $sp, 0x5F0
    ctx->r3 = ADD32(ctx->r29, 0X5F0);
L_80116A78:
    // 0x80116A78: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80116A7C: bnel        $t6, $zero, L_80116A94
    if (ctx->r14 != 0) {
        // 0x80116A80: sltu        $at, $ra, $s0
        ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
            goto L_80116A94;
    }
    goto skip_2;
    // 0x80116A80: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
    skip_2:
    // 0x80116A84: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x80116A88: bne         $ra, $zero, L_80116A78
    if (ctx->r31 != 0) {
        // 0x80116A8C: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_80116A78;
    }
    // 0x80116A8C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80116A90: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
L_80116A94:
    // 0x80116A94: beq         $at, $zero, L_80116AA0
    if (ctx->r1 == 0) {
        // 0x80116A98: sw          $ra, 0x5A8($sp)
        MEM_W(0X5A8, ctx->r29) = ctx->r31;
            goto L_80116AA0;
    }
    // 0x80116A98: sw          $ra, 0x5A8($sp)
    MEM_W(0X5A8, ctx->r29) = ctx->r31;
    // 0x80116A9C: or          $s0, $ra, $zero
    ctx->r16 = ctx->r31 | 0;
L_80116AA0:
    // 0x80116AA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80116AA4: sltu        $at, $a3, $ra
    ctx->r1 = ctx->r7 < ctx->r31 ? 1 : 0;
    // 0x80116AA8: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x80116AAC: beq         $at, $zero, L_80116ADC
    if (ctx->r1 == 0) {
        // 0x80116AB0: sllv        $v0, $t7, $a3
        ctx->r2 = S32(ctx->r15 << (ctx->r7 & 31));
            goto L_80116ADC;
    }
    // 0x80116AB0: sllv        $v0, $t7, $a3
    ctx->r2 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x80116AB4: sll         $t8, $ra, 2
    ctx->r24 = S32(ctx->r31 << 2);
    // 0x80116AB8: addiu       $t9, $sp, 0x5B0
    ctx->r25 = ADD32(ctx->r29, 0X5B0);
    // 0x80116ABC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
L_80116AC0:
    // 0x80116AC0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80116AC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80116AC8: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80116ACC: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x80116AD0: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80116AD4: bne         $at, $zero, L_80116AC0
    if (ctx->r1 != 0) {
        // 0x80116AD8: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80116AC0;
    }
    // 0x80116AD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80116ADC:
    // 0x80116ADC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80116AE0: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x80116AE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80116AE8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80116AEC: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x80116AF0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80116AF4: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x80116AF8: addiu       $fp, $sp, 0x5B4
    ctx->r30 = ADD32(ctx->r29, 0X5B4);
    // 0x80116AFC: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x80116B00: beq         $ra, $zero, L_80116B8C
    if (ctx->r31 == 0) {
        // 0x80116B04: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_80116B8C;
    }
    // 0x80116B04: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80116B08: andi        $a1, $ra, 0x3
    ctx->r5 = ctx->r31 & 0X3;
    // 0x80116B0C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80116B10: beq         $a1, $zero, L_80116B48
    if (ctx->r5 == 0) {
        // 0x80116B14: addu        $v0, $a1, $ra
        ctx->r2 = ADD32(ctx->r5, ctx->r31);
            goto L_80116B48;
    }
    // 0x80116B14: addu        $v0, $a1, $ra
    ctx->r2 = ADD32(ctx->r5, ctx->r31);
    // 0x80116B18: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80116B1C: addiu       $t6, $sp, 0x5B0
    ctx->r14 = ADD32(ctx->r29, 0X5B0);
    // 0x80116B20: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
L_80116B24:
    // 0x80116B24: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80116B28: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80116B2C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80116B30: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x80116B34: sw          $a3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r7;
    // 0x80116B38: bne         $a0, $v1, L_80116B24
    if (ctx->r4 != ctx->r3) {
        // 0x80116B3C: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_80116B24;
    }
    // 0x80116B3C: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80116B40: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x80116B44: beq         $v1, $t8, L_80116B8C
    if (ctx->r3 == ctx->r24) {
        // 0x80116B48: addiu       $v0, $sp, 0x5B0
        ctx->r2 = ADD32(ctx->r29, 0X5B0);
            goto L_80116B8C;
    }
L_80116B48:
    // 0x80116B48: addiu       $v0, $sp, 0x5B0
    ctx->r2 = ADD32(ctx->r29, 0X5B0);
L_80116B4C:
    // 0x80116B4C: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x80116B50: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x80116B54: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80116B58: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x80116B5C: sw          $a3, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->r7;
    // 0x80116B60: lw          $t6, 0x4($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X4);
    // 0x80116B64: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    // 0x80116B68: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x80116B6C: sw          $a3, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->r7;
    // 0x80116B70: lw          $t7, -0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X8);
    // 0x80116B74: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x80116B78: sw          $a3, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->r7;
    // 0x80116B7C: lw          $t8, -0x4($fp)
    ctx->r24 = MEM_W(ctx->r30, -0X4);
    // 0x80116B80: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x80116B84: bne         $v1, $v0, L_80116B4C
    if (ctx->r3 != ctx->r2) {
        // 0x80116B88: sw          $a3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r7;
            goto L_80116B4C;
    }
    // 0x80116B88: sw          $a3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r7;
L_80116B8C:
    // 0x80116B8C: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x80116B90: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80116B94: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80116B98: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    // 0x80116B9C: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
L_80116BA0:
    // 0x80116BA0: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80116BA4: beq         $a3, $zero, L_80116BC8
    if (ctx->r7 == 0) {
        // 0x80116BA8: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_80116BC8;
    }
    // 0x80116BA8: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80116BAC: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x80116BB0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80116BB4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80116BB8: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80116BBC: sw          $ra, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r31;
    // 0x80116BC0: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80116BC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80116BC8:
    // 0x80116BC8: lw          $t9, 0x5FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5FC);
    // 0x80116BCC: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x80116BD0: sltu        $at, $ra, $t9
    ctx->r1 = ctx->r31 < ctx->r25 ? 1 : 0;
    // 0x80116BD4: bnel        $at, $zero, L_80116BA0
    if (ctx->r1 != 0) {
        // 0x80116BD8: lw          $a3, 0x0($fp)
        ctx->r7 = MEM_W(ctx->r30, 0X0);
            goto L_80116BA0;
    }
    goto skip_3;
    // 0x80116BD8: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    skip_3:
    // 0x80116BDC: lw          $t6, 0x5A8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5A8);
    // 0x80116BE0: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80116BE4: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x80116BE8: slt         $at, $t6, $s4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80116BEC: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80116BF0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80116BF4: negu        $t2, $s0
    ctx->r10 = SUB32(0, ctx->r16);
    // 0x80116BF8: sw          $zero, 0x544($sp)
    MEM_W(0X544, ctx->r29) = 0;
    // 0x80116BFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80116C00: bne         $at, $zero, L_80116EFC
    if (ctx->r1 != 0) {
        // 0x80116C04: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80116EFC;
    }
    // 0x80116C04: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80116C08: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80116C0C: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x80116C10: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80116C14: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80116C18: addiu       $s2, $s2, 0x7388
    ctx->r18 = ADD32(ctx->r18, 0X7388);
    // 0x80116C1C: addiu       $s7, $s7, 0x4A80
    ctx->r23 = ADD32(ctx->r23, 0X4A80);
    // 0x80116C20: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80116C24: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x80116C28: addiu       $s3, $sp, 0x584
    ctx->r19 = ADD32(ctx->r29, 0X584);
    // 0x80116C2C: lw          $s6, 0x0($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X0);
L_80116C30:
    // 0x80116C30: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80116C34: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x80116C38: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80116C3C: beq         $s6, $zero, L_80116EE0
    if (ctx->r22 == 0) {
        // 0x80116C40: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_80116EE0;
    }
    // 0x80116C40: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x80116C44: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x80116C48: addu        $t3, $t5, $t9
    ctx->r11 = ADD32(ctx->r13, ctx->r25);
    // 0x80116C4C: addiu       $t8, $sp, 0xC4
    ctx->r24 = ADD32(ctx->r29, 0XC4);
    // 0x80116C50: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80116C54: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80116C58: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80116C5C: addiu       $t6, $s4, 0x1F
    ctx->r14 = ADD32(ctx->r20, 0X1F);
    // 0x80116C60: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80116C64: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80116C68: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80116C6C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
L_80116C70:
    // 0x80116C70: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x80116C74: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80116C78: beq         $at, $zero, L_80116D98
    if (ctx->r1 == 0) {
        // 0x80116C7C: addiu       $s1, $s6, 0x1
        ctx->r17 = ADD32(ctx->r22, 0X1);
            goto L_80116D98;
    }
    // 0x80116C7C: addiu       $s1, $s6, 0x1
    ctx->r17 = ADD32(ctx->r22, 0X1);
    // 0x80116C80: addiu       $t9, $sp, 0x544
    ctx->r25 = ADD32(ctx->r29, 0X544);
    // 0x80116C84: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x80116C88: lw          $t7, 0x5A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A8);
L_80116C8C:
    // 0x80116C8C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80116C90: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80116C94: subu        $t0, $t7, $v1
    ctx->r8 = SUB32(ctx->r15, ctx->r3);
    // 0x80116C98: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x80116C9C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80116CA0: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80116CA4: beq         $at, $zero, L_80116CB0
    if (ctx->r1 == 0) {
        // 0x80116CA8: or          $t2, $v1, $zero
        ctx->r10 = ctx->r3 | 0;
            goto L_80116CB0;
    }
    // 0x80116CA8: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x80116CAC: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_80116CB0:
    // 0x80116CB0: subu        $v0, $s4, $t2
    ctx->r2 = SUB32(ctx->r20, ctx->r10);
    // 0x80116CB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80116CB8: sllv        $a0, $t6, $v0
    ctx->r4 = S32(ctx->r14 << (ctx->r2 & 31));
    // 0x80116CBC: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x80116CC0: beq         $at, $zero, L_80116D10
    if (ctx->r1 == 0) {
        // 0x80116CC4: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80116D10;
    }
    // 0x80116CC4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80116CC8: addiu       $a3, $v0, 0x1
    ctx->r7 = ADD32(ctx->r2, 0X1);
    // 0x80116CCC: subu        $v1, $a0, $s6
    ctx->r3 = SUB32(ctx->r4, ctx->r22);
    // 0x80116CD0: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x80116CD4: addiu       $t9, $sp, 0x5B0
    ctx->r25 = ADD32(ctx->r29, 0X5B0);
    // 0x80116CD8: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x80116CDC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80116CE0: beq         $at, $zero, L_80116D10
    if (ctx->r1 == 0) {
        // 0x80116CE4: addu        $a2, $t8, $t9
        ctx->r6 = ADD32(ctx->r24, ctx->r25);
            goto L_80116D10;
    }
    // 0x80116CE4: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
L_80116CE8:
    // 0x80116CE8: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x80116CEC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80116CF0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80116CF4: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80116CF8: beql        $at, $zero, L_80116D14
    if (ctx->r1 == 0) {
        // 0x80116CFC: lw          $v1, 0x0($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X0);
            goto L_80116D14;
    }
    goto skip_4;
    // 0x80116CFC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    skip_4:
    // 0x80116D00: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80116D04: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x80116D08: bne         $at, $zero, L_80116CE8
    if (ctx->r1 != 0) {
        // 0x80116D0C: subu        $v1, $v0, $a0
        ctx->r3 = SUB32(ctx->r2, ctx->r4);
            goto L_80116CE8;
    }
    // 0x80116D0C: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
L_80116D10:
    // 0x80116D10: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_80116D14:
    // 0x80116D14: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80116D18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80116D1C: sllv        $t0, $t7, $a3
    ctx->r8 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x80116D20: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80116D24: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x80116D28: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80116D2C: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    // 0x80116D30: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80116D34: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x80116D38: sw          $a0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r4;
    // 0x80116D3C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80116D40: addiu       $s5, $a2, 0x4
    ctx->r21 = ADD32(ctx->r6, 0X4);
    // 0x80116D44: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80116D48: beq         $t4, $zero, L_80116D88
    if (ctx->r12 == 0) {
        // 0x80116D4C: sw          $a0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r4;
            goto L_80116D88;
    }
    // 0x80116D4C: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x80116D50: sw          $ra, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r31;
    // 0x80116D54: addiu       $t6, $a3, 0x10
    ctx->r14 = ADD32(ctx->r7, 0X10);
    // 0x80116D58: sb          $s0, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r16;
    // 0x80116D5C: sb          $t6, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r14;
    // 0x80116D60: sw          $a0, 0x588($sp)
    MEM_W(0X588, ctx->r29) = ctx->r4;
    // 0x80116D64: lw          $t8, -0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, -0X4);
    // 0x80116D68: subu        $t9, $t2, $s0
    ctx->r25 = SUB32(ctx->r10, ctx->r16);
    // 0x80116D6C: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x80116D70: srlv        $t7, $ra, $t9
    ctx->r15 = S32(U32(ctx->r31) >> (ctx->r25 & 31));
    // 0x80116D74: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x80116D78: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80116D7C: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80116D80: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x80116D84: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
L_80116D88:
    // 0x80116D88: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x80116D8C: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80116D90: bnel        $at, $zero, L_80116C8C
    if (ctx->r1 != 0) {
        // 0x80116D94: lw          $t7, 0x5A8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5A8);
            goto L_80116C8C;
    }
    goto skip_5;
    // 0x80116D94: lw          $t7, 0x5A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A8);
    skip_5:
L_80116D98:
    // 0x80116D98: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80116D9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80116DA0: subu        $v1, $s4, $t2
    ctx->r3 = SUB32(ctx->r20, ctx->r10);
    // 0x80116DA4: sllv        $a1, $t8, $t2
    ctx->r5 = S32(ctx->r24 << (ctx->r10 & 31));
    // 0x80116DA8: sltu        $at, $fp, $t7
    ctx->r1 = ctx->r30 < ctx->r15 ? 1 : 0;
    // 0x80116DAC: sb          $v1, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r3;
    // 0x80116DB0: bne         $at, $zero, L_80116DC4
    if (ctx->r1 != 0) {
        // 0x80116DB4: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80116DC4;
    }
    // 0x80116DB4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80116DB8: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x80116DBC: b           L_80116E40
    // 0x80116DC0: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
        goto L_80116E40;
    // 0x80116DC0: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
L_80116DC4:
    // 0x80116DC4: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x80116DC8: lw          $t6, 0x600($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X600);
    // 0x80116DCC: lw          $a0, 0x600($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X600);
    // 0x80116DD0: lw          $t8, 0x608($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X608);
    // 0x80116DD4: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x80116DD8: beq         $at, $zero, L_80116E08
    if (ctx->r1 == 0) {
        // 0x80116DDC: sltiu       $at, $v0, 0x100
        ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
            goto L_80116E08;
    }
    // 0x80116DDC: sltiu       $at, $v0, 0x100
    ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x80116DE0: beq         $at, $zero, L_80116DF4
    if (ctx->r1 == 0) {
        // 0x80116DE4: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_80116DF4;
    }
    // 0x80116DE4: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80116DE8: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80116DEC: b           L_80116DF8
    // 0x80116DF0: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
        goto L_80116DF8;
    // 0x80116DF0: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
L_80116DF4:
    // 0x80116DF4: sb          $t7, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r15;
L_80116DF8:
    // 0x80116DF8: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x80116DFC: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80116E00: b           L_80116E40
    // 0x80116E04: sh          $t9, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r25;
        goto L_80116E40;
    // 0x80116E04: sh          $t9, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r25;
L_80116E08:
    // 0x80116E08: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x80116E0C: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80116E10: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x80116E14: lw          $t6, 0x604($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X604);
    // 0x80116E18: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80116E1C: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
    // 0x80116E20: lw          $t8, -0x4($fp)
    ctx->r24 = MEM_W(ctx->r30, -0X4);
    // 0x80116E24: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x80116E28: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x80116E2C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80116E30: negu        $t6, $t8
    ctx->r14 = SUB32(0, ctx->r24);
    // 0x80116E34: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80116E38: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80116E3C: sh          $t8, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r24;
L_80116E40:
    // 0x80116E40: srlv        $a3, $ra, $t2
    ctx->r7 = S32(U32(ctx->r31) >> (ctx->r10 & 31));
    // 0x80116E44: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x80116E48: beq         $at, $zero, L_80116E78
    if (ctx->r1 == 0) {
        // 0x80116E4C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80116E78;
    }
    // 0x80116E4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80116E50: sllv        $v0, $t9, $v1
    ctx->r2 = S32(ctx->r25 << (ctx->r3 & 31));
L_80116E54:
    // 0x80116E54: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x80116E58: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x80116E5C: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80116E60: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x80116E64: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x80116E68: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80116E6C: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x80116E70: bne         $at, $zero, L_80116E54
    if (ctx->r1 != 0) {
        // 0x80116E74: sw          $t9, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r25;
            goto L_80116E54;
    }
    // 0x80116E74: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
L_80116E78:
    // 0x80116E78: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80116E7C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80116E80: and         $t6, $ra, $a3
    ctx->r14 = ctx->r31 & ctx->r7;
    // 0x80116E84: beq         $t6, $zero, L_80116E9C
    if (ctx->r14 == 0) {
        // 0x80116E88: srl         $t8, $a3, 1
        ctx->r24 = S32(U32(ctx->r7) >> 1);
            goto L_80116E9C;
    }
L_80116E88:
    // 0x80116E88: srl         $t8, $a3, 1
    ctx->r24 = S32(U32(ctx->r7) >> 1);
    // 0x80116E8C: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x80116E90: and         $t7, $ra, $t8
    ctx->r15 = ctx->r31 & ctx->r24;
    // 0x80116E94: bne         $t7, $zero, L_80116E88
    if (ctx->r15 != 0) {
        // 0x80116E98: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_80116E88;
    }
    // 0x80116E98: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_80116E9C:
    // 0x80116E9C: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x80116EA0: and         $t9, $ra, $a1
    ctx->r25 = ctx->r31 & ctx->r5;
    // 0x80116EA4: beq         $t9, $v0, L_80116ED4
    if (ctx->r25 == ctx->r2) {
        // 0x80116EA8: or          $a1, $s6, $zero
        ctx->r5 = ctx->r22 | 0;
            goto L_80116ED4;
    }
    // 0x80116EA8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
L_80116EAC:
    // 0x80116EAC: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x80116EB0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80116EB4: sllv        $t8, $t6, $t2
    ctx->r24 = S32(ctx->r14 << (ctx->r10 & 31));
    // 0x80116EB8: lw          $t6, -0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, -0X4);
    // 0x80116EBC: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80116EC0: and         $t9, $ra, $t7
    ctx->r25 = ctx->r31 & ctx->r15;
    // 0x80116EC4: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80116EC8: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
    // 0x80116ECC: bne         $t9, $t6, L_80116EAC
    if (ctx->r25 != ctx->r14) {
        // 0x80116ED0: addiu       $t3, $t3, -0x4
        ctx->r11 = ADD32(ctx->r11, -0X4);
            goto L_80116EAC;
    }
    // 0x80116ED0: addiu       $t3, $t3, -0x4
    ctx->r11 = ADD32(ctx->r11, -0X4);
L_80116ED4:
    // 0x80116ED4: bne         $s6, $zero, L_80116C70
    if (ctx->r22 != 0) {
        // 0x80116ED8: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_80116C70;
    }
    // 0x80116ED8: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x80116EDC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_80116EE0:
    // 0x80116EE0: lw          $t8, 0x5A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5A8);
    // 0x80116EE4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80116EE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80116EEC: slt         $at, $t8, $s4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80116EF0: beql        $at, $zero, L_80116C30
    if (ctx->r1 == 0) {
        // 0x80116EF4: lw          $s6, 0x0($v0)
        ctx->r22 = MEM_W(ctx->r2, 0X0);
            goto L_80116C30;
    }
    goto skip_6;
    // 0x80116EF4: lw          $s6, 0x0($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X0);
    skip_6:
    // 0x80116EF8: sw          $s5, 0x60C($sp)
    MEM_W(0X60C, ctx->r29) = ctx->r21;
L_80116EFC:
    // 0x80116EFC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80116F00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80116F04: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80116F08: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80116F0C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80116F10: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80116F14: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80116F18: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80116F1C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80116F20: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80116F24: jr          $ra
    // 0x80116F28: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
    return;
    // 0x80116F28: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
    // 0x80116F2C: nop

;}
RECOMP_FUNC void bsbanpackwhack_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800104: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800108: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080010C: lui         $a2, 0x3FD9
    ctx->r6 = S32(0X3FD9 << 16);
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800114: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800118: jal         0x8008CCBC
    // 0x8080011C: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x8080011C: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    after_0:
    // 0x80800120: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800124: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800130: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800134: jal         0x8009FFD8
    // 0x80800138: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800138: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x8080013C: jal         0x8009BB00
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800144: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800148: jal         0x8008E078
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800150: beq         $v0, $zero, L_8080016C
    if (ctx->r2 == 0) {
        // 0x80800154: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080016C;
    }
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(37, 0X4B0) << 16);
    // 0x8080015C: lwc1        $f6, 0x4B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(37, 0X4B0));
    // 0x80800160: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800164: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800168: swc1        $f8, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f8.u32l;
L_8080016C:
    // 0x8080016C: jal         0x8009B9B0
    // 0x80800170: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800170: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_4:
    // 0x80800174: jal         0x8009C990
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_5;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080017C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800180: jal         0x8009B9C0
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_6;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: jal         0x8009BCC4
    // 0x80800190: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_7;
    // 0x80800190: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    after_7:
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: jal         0x80095760
    // 0x8080019C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_set(rdram, ctx);
        goto after_8;
    // 0x8080019C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_8:
    // 0x808001A0: jal         0x8009E4AC
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_9;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808001AC: nop

    // 0x808001B0: swc1        $f10, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f10.u32l;
    // 0x808001B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void func_808000FC_chhotfloorsmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800100: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800104: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800108: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x8080010C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800114: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800118: beq         $t6, $at, L_80800130
    if (ctx->r14 == ctx->r1) {
        // 0x8080011C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800130;
    }
    // 0x8080011C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800120: beql        $t6, $at, L_80800160
    if (ctx->r14 == ctx->r1) {
        // 0x80800124: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800160;
    }
    goto skip_0;
    // 0x80800124: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80800128: b           L_8080017C
    // 0x8080012C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
        goto L_8080017C;
    // 0x8080012C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_80800130:
    // 0x80800130: jal         0x800DA298
    // 0x80800134: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800134: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    after_0:
    // 0x80800138: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x8080013C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808001D4;
    }
    // 0x8080013C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800140: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800144: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800148: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080014C: jal         0x800DC178
    // 0x80800150: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800150: nop

    after_1:
    // 0x80800154: b           L_80800194
    // 0x80800158: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800194;
    // 0x80800158: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8080015C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800160:
    // 0x80800160: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800164: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800168: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080016C: jal         0x800DC178
    // 0x80800170: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800170: nop

    after_2:
    // 0x80800174: b           L_80800194
    // 0x80800178: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800194;
    // 0x80800178: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8080017C:
    // 0x8080017C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800180: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800184: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800188: jal         0x800DC178
    // 0x8080018C: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x8080018C: nop

    after_3:
    // 0x80800190: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800194:
    // 0x80800194: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80800198: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8080019C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808001A0: srl         $t7, $a0, 25
    ctx->r15 = S32(U32(ctx->r4) >> 25);
    // 0x808001A4: jal         0x800CD08C
    // 0x808001A8: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    func_800CD08C(rdram, ctx);
        goto after_4;
    // 0x808001A8: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    after_4:
    // 0x808001AC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808001B8: jal         0x808001E8
    // 0x808001BC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_808001E8_chhotfloorsmoke(rdram, ctx);
        goto after_5;
    // 0x808001BC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: jal         0x80101FDC
    // 0x808001C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x808001C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808001CC: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808001D0: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
L_808001D4:
    // 0x808001D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001E0: jr          $ra
    // 0x808001E4: nop

    return;
    // 0x808001E4: nop

;}
RECOMP_FUNC void chlavagargoyle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C7C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2324, 0XED8) << 16);
    // 0x80800C80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800C88: addiu       $t6, $t6, 0xED8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2324, 0XED8));
    // 0x80800C8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C98: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800C9C: jal         0x800BBCB8
    // 0x80800CA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800CA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800CA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CAC: jr          $ra
    // 0x80800CB0: nop

    return;
    // 0x80800CB0: nop

;}
RECOMP_FUNC void _anseq_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082658: syscall     3
    recomp_syscall_handler(rdram, ctx, 0x80082658);
    return;
    // 0x8008265C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void chglowbo_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808011B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X13A4) << 16);
    // 0x808011B4: jal         0x800DC178
    // 0x808011B8: lwc1        $f14, 0x13A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X13A4));
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x808011B8: lwc1        $f14, 0x13A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X13A4));
    after_0:
    // 0x808011BC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808011C0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1628, 0X1618) << 16);
    // 0x808011C4: addiu       $a1, $a1, 0x1618
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1628, 0X1618));
    // 0x808011C8: addiu       $a0, $zero, 0x2A0
    ctx->r4 = ADD32(0, 0X2A0);
    // 0x808011CC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808011D0: jal         0x80108474
    // 0x808011D4: nop

    func_80108474(rdram, ctx);
        goto after_1;
    // 0x808011D4: nop

    after_1:
    // 0x808011D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011E0: jr          $ra
    // 0x808011E4: nop

    return;
    // 0x808011E4: nop

;}
RECOMP_FUNC void func_8080099C_chlavagargoyle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080099C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009A0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2324, 0XE44) << 16);
    // 0x808009A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808009AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808009B0: addiu       $t7, $t7, 0xE44
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2324, 0XE44));
    // 0x808009B4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x808009B8: addiu       $t6, $sp, 0x18
    ctx->r14 = ADD32(ctx->r29, 0X18);
    // 0x808009BC: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x808009C0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x808009C4: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x808009C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808009CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808009D0: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x808009D4: jal         0x800DC128
    // 0x808009D8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x808009D8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    after_0:
    // 0x808009DC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808009E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808009E4: lw          $a0, 0x14($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X14);
    // 0x808009E8: jal         0x800C8CB8
    // 0x808009EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800C8CB8(rdram, ctx);
        goto after_1;
    // 0x808009EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808009F0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808009F4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x808009F8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x808009FC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800A00: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x80800A04: subu        $t5, $t4, $v1
    ctx->r13 = SUB32(ctx->r12, ctx->r3);
    // 0x80800A08: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80800A0C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80800A10: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800A14: jal         0x800C8E84
    // 0x80800A18: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    func_800C8E84(rdram, ctx);
        goto after_2;
    // 0x80800A18: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    after_2:
    // 0x80800A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A24: jr          $ra
    // 0x80800A28: nop

    return;
    // 0x80800A28: nop

;}
RECOMP_FUNC void func_80116568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116568: mfc1        $t9, $f20
    ctx->r25 = (int32_t)ctx->f20.u32l;
    // 0x8011656C: nop

    // 0x80116570: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x80116574: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x80116578: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x8011657C: nop

    // 0x80116580: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x80116584: nop

    // 0x80116588: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8011658C: lwc1        $f1, 0x4($a0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r4, 0X4);
    // 0x80116590: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80116594: lwc1        $f3, 0x10($a0)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r4, 0X10);
    // 0x80116598: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8011659C: lwc1        $f5, 0x18($a0)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r4, 0X18);
    // 0x801165A0: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x801165A4: lwc1        $f7, 0x24($a0)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r4, 0X24);
    // 0x801165A8: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x801165AC: lwc1        $f9, 0x30($a0)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r4, 0X30);
    // 0x801165B0: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x801165B4: lwc1        $f11, 0x38($a0)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r4, 0X38);
L_801165B8:
    // 0x801165B8: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x801165BC: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x801165C0: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x801165C4: mtc1        $t0, $f12
    ctx->f12.u32l = ctx->r8;
    // 0x801165C8: lh          $t0, -0x4($a1)
    ctx->r8 = MEM_H(ctx->r5, -0X4);
    // 0x801165CC: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // 0x801165D0: mtc1        $t0, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r8;
    // 0x801165D4: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x801165D8: lh          $t0, -0x2($a1)
    ctx->r8 = MEM_H(ctx->r5, -0X2);
    // 0x801165DC: mtc1        $t0, $f14
    ctx->f14.u32l = ctx->r8;
    // 0x801165E0: cvt.s.w     $f13, $f13
    CHECK_FR(ctx, 13);
    CHECK_FR(ctx, 13);
    ctx->f13.fl = CVT_S_W(ctx->f_odd[(13 - 1) * 2]);
    // 0x801165E4: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x801165E8: nop

    // 0x801165EC: mul.s       $f19, $f13, $f3
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 13);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f13.fl); NAN_CHECK(ctx->f3.fl); 
    ctx->f19.fl = MUL_S(ctx->f13.fl, ctx->f3.fl);
    // 0x801165F0: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x801165F4: add.s       $f15, $f18, $f9
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 9);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f9.fl); 
    ctx->f15.fl = ctx->f18.fl + ctx->f9.fl;
    // 0x801165F8: mul.s       $f20, $f14, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x801165FC: add.s       $f15, $f15, $f19
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 19);
    NAN_CHECK(ctx->f15.fl); NAN_CHECK(ctx->f19.fl); 
    ctx->f15.fl = ctx->f15.fl + ctx->f19.fl;
    // 0x80116600: mul.s       $f18, $f12, $f1
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f1.fl);
    // 0x80116604: add.s       $f15, $f15, $f20
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f15.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f15.fl = ctx->f15.fl + ctx->f20.fl;
    // 0x80116608: mul.s       $f19, $f13, $f4
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 13);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f13.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f19.fl = MUL_S(ctx->f13.fl, ctx->f4.fl);
    // 0x8011660C: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80116610: mul.s       $f20, $f14, $f7
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 7);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f7.fl); 
    ctx->f20.fl = MUL_S(ctx->f14.fl, ctx->f7.fl);
    // 0x80116614: add.s       $f16, $f16, $f19
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 19);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f19.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f19.fl;
    // 0x80116618: mul.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8011661C: add.s       $f16, $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80116620: mul.s       $f19, $f13, $f5
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 13);
    CHECK_FR(ctx, 5);
    NAN_CHECK(ctx->f13.fl); NAN_CHECK(ctx->f5.fl); 
    ctx->f19.fl = MUL_S(ctx->f13.fl, ctx->f5.fl);
    // 0x80116624: add.s       $f17, $f18, $f11
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 11);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f11.fl); 
    ctx->f17.fl = ctx->f18.fl + ctx->f11.fl;
    // 0x80116628: mul.s       $f20, $f14, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8011662C: add.s       $f17, $f17, $f19
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 19);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f19.fl); 
    ctx->f17.fl = ctx->f17.fl + ctx->f19.fl;
    // 0x80116630: round.w.s   $f15, $f15
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 15);
    ctx->f_odd[(15 - 1) * 2] = lroundf(ctx->f15.fl);
    // 0x80116634: add.s       $f17, $f17, $f20
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f17.fl = ctx->f17.fl + ctx->f20.fl;
    // 0x80116638: mfc1        $t0, $f15
    ctx->r8 = (int32_t)ctx->f_odd[(15 - 1) * 2];
    // 0x8011663C: round.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = lroundf(ctx->f16.fl);
    // 0x80116640: sh          $t0, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r8;
    // 0x80116644: round.w.s   $f17, $f17
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    ctx->f_odd[(17 - 1) * 2] = lroundf(ctx->f17.fl);
    // 0x80116648: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8011664C: mfc1        $t2, $f17
    ctx->r10 = (int32_t)ctx->f_odd[(17 - 1) * 2];
    // 0x80116650: sh          $t1, -0x4($a2)
    MEM_H(-0X4, ctx->r6) = ctx->r9;
    // 0x80116654: bgtz        $a3, L_801165B8
    if (SIGNED(ctx->r7) > 0) {
        // 0x80116658: sh          $t2, -0x2($a2)
        MEM_H(-0X2, ctx->r6) = ctx->r10;
            goto L_801165B8;
    }
    // 0x80116658: sh          $t2, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r10;
    // 0x8011665C: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x80116660: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x80116664: nor         $t1, $t1, $zero
    ctx->r9 = ~(ctx->r9 | 0);
    // 0x80116668: and         $t0, $t0, $t1
    ctx->r8 = ctx->r8 & ctx->r9;
    // 0x8011666C: nop

    // 0x80116670: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x80116674: nop

    // 0x80116678: mtc1        $t9, $f20
    ctx->f20.u32l = ctx->r25;
    // 0x8011667C: jr          $ra
    // 0x80116680: nop

    return;
    // 0x80116680: nop

;}
RECOMP_FUNC void _chboilerboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D78: syscall     238
    recomp_syscall_handler(rdram, ctx, 0x80085D78);
    return;
    // 0x80085D7C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _idwibble_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E78: syscall     745
    recomp_syscall_handler(rdram, ctx, 0x80088E78);
    return;
    // 0x80088E7C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808004E8_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004F0: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808004F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004FC: beq         $a1, $at, L_808006A0
    if (ctx->r5 == ctx->r1) {
        // 0x80800500: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_808006A0;
    }
    // 0x80800500: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800504: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800508: beq         $a1, $at, L_80800614
    if (ctx->r5 == ctx->r1) {
        // 0x8080050C: addiu       $v0, $sp, 0x38
        ctx->r2 = ADD32(ctx->r29, 0X38);
            goto L_80800614;
    }
    // 0x8080050C: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x80800510: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800514: beq         $a1, $at, L_80800538
    if (ctx->r5 == ctx->r1) {
        // 0x80800518: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800538;
    }
    // 0x80800518: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x8080051C: beq         $a1, $at, L_8080062C
    if (ctx->r5 == ctx->r1) {
        // 0x80800520: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1584, 0X1AB8) << 16);
            goto L_8080062C;
    }
    // 0x80800520: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1584, 0X1AB8) << 16);
    // 0x80800524: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80800528: beq         $a1, $at, L_80800660
    if (ctx->r5 == ctx->r1) {
        // 0x8080052C: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_80800660;
    }
    // 0x8080052C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80800530: b           L_80800728
    // 0x80800534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800728;
    // 0x80800534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800538:
    // 0x80800538: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080053C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800548: beq         $t6, $at, L_80800568
    if (ctx->r14 == ctx->r1) {
        // 0x8080054C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800568;
    }
    // 0x8080054C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800550: beq         $t6, $at, L_80800578
    if (ctx->r14 == ctx->r1) {
        // 0x80800554: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800578;
    }
    // 0x80800554: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800558: beq         $t6, $at, L_808005F0
    if (ctx->r14 == ctx->r1) {
        // 0x8080055C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F0;
    }
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800560: b           L_80800728
    // 0x80800564: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800728;
    // 0x80800564: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800568:
    // 0x80800568: jal         0x80800264
    // 0x8080056C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_0;
    // 0x8080056C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80800570: b           L_80800728
    // 0x80800574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800728;
    // 0x80800574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800578:
    // 0x80800578: jal         0x8080011C
    // 0x8080057C: nop

    func_8080011C_chnewmumbo(rdram, ctx);
        goto after_1;
    // 0x8080057C: nop

    after_1:
    // 0x80800580: jal         0x800DA298
    // 0x80800584: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800584: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800588: beq         $v0, $zero, L_808005C4
    if (ctx->r2 == 0) {
        // 0x8080058C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005C4;
    }
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800594: jal         0x8080073C
    // 0x80800598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080073C_chnewmumbo(rdram, ctx);
        goto after_3;
    // 0x80800598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005A4: jal         0x80800000
    // 0x808005A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chnewmumbo(rdram, ctx);
        goto after_4;
    // 0x808005A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: addiu       $a1, $zero, 0x11DB
    ctx->r5 = ADD32(0, 0X11DB);
    // 0x808005B4: jal         0x808000DC
    // 0x808005B8: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_5;
    // 0x808005B8: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_5:
    // 0x808005BC: b           L_80800728
    // 0x808005C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800728;
    // 0x808005C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005C4:
    // 0x808005C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005C8: jal         0x80800000
    // 0x808005CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chnewmumbo(rdram, ctx);
        goto after_6;
    // 0x808005CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D4: jal         0x8080073C
    // 0x808005D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080073C_chnewmumbo(rdram, ctx);
        goto after_7;
    // 0x808005D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: jal         0x80800264
    // 0x808005E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_8;
    // 0x808005E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_8:
    // 0x808005E8: b           L_80800728
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800728;
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F0:
    // 0x808005F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005F4: jal         0x80800000
    // 0x808005F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chnewmumbo(rdram, ctx);
        goto after_9;
    // 0x808005F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: addiu       $a1, $zero, 0x11DB
    ctx->r5 = ADD32(0, 0X11DB);
    // 0x80800604: jal         0x808000DC
    // 0x80800608: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_10;
    // 0x80800608: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_10:
    // 0x8080060C: b           L_80800728
    // 0x80800610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800728;
    // 0x80800610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800614:
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800618: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8080061C: jal         0x808014FC
    // 0x80800620: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_808014FC_chnewmumbo(rdram, ctx);
        goto after_11;
    // 0x80800620: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_11:
    // 0x80800624: b           L_80800728
    // 0x80800628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800728;
    // 0x80800628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080062C:
    // 0x8080062C: addiu       $a0, $a0, 0x1AB8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1584, 0X1AB8));
    // 0x80800630: jal         0x80088090
    // 0x80800634: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80800634: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_12:
    // 0x80800638: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x8080063C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1584, 0X1AC8) << 16);
    // 0x80800640: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800644: slti        $at, $t8, 0xE
    ctx->r1 = SIGNED(ctx->r24) < 0XE ? 1 : 0;
    // 0x80800648: beql        $at, $zero, L_80800728
    if (ctx->r1 == 0) {
        // 0x8080064C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800728;
    }
    goto skip_0;
    // 0x8080064C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800650: jal         0x80088098
    // 0x80800654: addiu       $a0, $a0, 0x1AC8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1584, 0X1AC8));
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x80800654: addiu       $a0, $a0, 0x1AC8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1584, 0X1AC8));
    after_13:
    // 0x80800658: b           L_80800728
    // 0x8080065C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800728;
    // 0x8080065C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800660:
    // 0x80800660: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800664: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800668: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x8080066C: and         $t0, $a2, $at
    ctx->r8 = ctx->r6 & ctx->r1;
    // 0x80800670: srl         $a1, $t0, 16
    ctx->r5 = S32(U32(ctx->r8) >> 16);
    // 0x80800674: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800678: jal         0x80088078
    // 0x8080067C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x8080067C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_14:
    // 0x80800680: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800684: beq         $v0, $zero, L_80800724
    if (ctx->r2 == 0) {
        // 0x80800688: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_80800724;
    }
    // 0x80800688: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: jal         0x80800000
    // 0x80800694: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80800000_chnewmumbo(rdram, ctx);
        goto after_15;
    // 0x80800694: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_15:
    // 0x80800698: b           L_80800728
    // 0x8080069C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800728;
    // 0x8080069C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006A0:
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A4: jal         0x80100094
    // 0x808006A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x808006A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808006AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808006B0: jal         0x801015D0
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_17;
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808006B8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808006BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006C0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808006C4: lbu         $t2, 0x1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1);
    // 0x808006C8: beq         $t2, $zero, L_808006E0
    if (ctx->r10 == 0) {
        // 0x808006CC: nop
    
            goto L_808006E0;
    }
    // 0x808006CC: nop

    // 0x808006D0: jal         0x800DF744
    // 0x808006D4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800DF744(rdram, ctx);
        goto after_18;
    // 0x808006D4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_18:
    // 0x808006D8: b           L_808006EC
    // 0x808006DC: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
        goto L_808006EC;
    // 0x808006DC: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
L_808006E0:
    // 0x808006E0: jal         0x800DF744
    // 0x808006E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_19;
    // 0x808006E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x808006E8: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
L_808006EC:
    // 0x808006EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006F0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808006F4: beq         $t3, $zero, L_8080070C
    if (ctx->r11 == 0) {
        // 0x808006F8: nop
    
            goto L_8080070C;
    }
    // 0x808006F8: nop

    // 0x808006FC: jal         0x800DF744
    // 0x80800700: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_20;
    // 0x80800700: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_20:
    // 0x80800704: b           L_80800728
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800728;
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080070C:
    // 0x8080070C: jal         0x800DF744
    // 0x80800710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_21;
    // 0x80800710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80800714: b           L_80800728
    // 0x80800718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800728;
    // 0x80800718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080071C: b           L_80800728
    // 0x80800720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800728;
    // 0x80800720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800724:
    // 0x80800724: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800728:
    // 0x80800728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080072C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800730: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800734: jr          $ra
    // 0x80800738: nop

    return;
    // 0x80800738: nop

;}
RECOMP_FUNC void bsbflap_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080068C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800698: jal         0x800C6DA0
    // 0x8080069C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    func_800C6DA0(rdram, ctx);
        goto after_0;
    // 0x8080069C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_0:
    // 0x808006A0: jal         0x8009BC6C
    // 0x808006A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x808006A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808006A8: jal         0x8009BC90
    // 0x808006AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_2;
    // 0x808006AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808006B0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x808006B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808006B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006BC: jal         0x800A0D14
    // 0x808006C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0D14(rdram, ctx);
        goto after_3;
    // 0x808006C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808006C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006CC: jr          $ra
    // 0x808006D0: nop

    return;
    // 0x808006D0: nop

;}
RECOMP_FUNC void func_80801448_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080144C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801450: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801454: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80801458: ori         $t6, $a2, 0x7
    ctx->r14 = ctx->r6 | 0X7;
    // 0x8080145C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80801460: addiu       $t8, $zero, 0xB3
    ctx->r24 = ADD32(0, 0XB3);
    // 0x80801464: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80801468: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080146C: jal         0x8008A208
    // 0x80801470: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80801470: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x80801474: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80801478: lbu         $t0, 0x74($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X74);
    // 0x8080147C: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x80801480: sb          $t1, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r9;
    // 0x80801484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801488: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080148C: jr          $ra
    // 0x80801490: nop

    return;
    // 0x80801490: nop

;}
RECOMP_FUNC void _capod_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856D0: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856D0);
    return;
    // 0x800856D4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
