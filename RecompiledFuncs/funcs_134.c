#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void sukickball_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002F8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808002FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800300: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800304: jal         0x80100094
    // 0x80800308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080030C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800310: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800314: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800318: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080031C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800320: nop

    // 0x80800324: bc1f        L_80800398
    if (!c1cs) {
        // 0x80800328: nop
    
            goto L_80800398;
    }
    // 0x80800328: nop

    // 0x8080032C: jal         0x801022E4
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800334: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x80800338: bnel        $v0, $at, L_80800368
    if (ctx->r2 != ctx->r1) {
        // 0x8080033C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800368;
    }
    goto skip_0;
    // 0x8080033C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x80800340: jal         0x80104248
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_2;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800348: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080034C: jal         0x8008AED4
    // 0x80800350: addiu       $a1, $zero, 0x1D7
    ctx->r5 = ADD32(0, 0X1D7);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800350: addiu       $a1, $zero, 0x1D7
    ctx->r5 = ADD32(0, 0X1D7);
    after_3:
    // 0x80800354: jal         0x80104248
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_4;
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080035C: jal         0x8008B064
    // 0x80800360: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x80800360: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800364: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800368:
    // 0x80800368: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080036C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800370: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800374: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800378: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8080037C: jal         0x800F10B4
    // 0x80800380: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800380: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x80800384: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800388: jal         0x80101CDC
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_7;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800390: b           L_808003E0
    // 0x80800394: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_808003E0;
    // 0x80800394: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_80800398:
    // 0x80800398: jal         0x801022E4
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_8;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808003A0: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x808003A4: beql        $v0, $at, L_808003E0
    if (ctx->r2 == ctx->r1) {
        // 0x808003A8: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_808003E0;
    }
    goto skip_1;
    // 0x808003A8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x808003AC: jal         0x80104248
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_9;
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003B8: jal         0x8008AED4
    // 0x808003BC: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    anctrl_setIndex(rdram, ctx);
        goto after_10;
    // 0x808003BC: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_10:
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: jal         0x80101CDC
    // 0x808003C8: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80101CDC(rdram, ctx);
        goto after_11;
    // 0x808003C8: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_11:
    // 0x808003CC: jal         0x80104248
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_12;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808003D4: jal         0x8008B064
    // 0x808003D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_start(rdram, ctx);
        goto after_13;
    // 0x808003D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x808003DC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_808003E0:
    // 0x808003E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x808003EC: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x808003F0: nop

    // 0x808003F4: bc1fl       L_80800444
    if (!c1cs) {
        // 0x808003F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800444;
    }
    goto skip_2;
    // 0x808003F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808003FC: jal         0x80101E14
    // 0x80800400: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x80800400: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_14:
    // 0x80800404: bne         $v0, $zero, L_80800418
    if (ctx->r2 != 0) {
        // 0x80800408: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800418;
    }
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: jal         0x80101E14
    // 0x80800410: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x80800410: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_15:
    // 0x80800414: beq         $v0, $zero, L_80800440
    if (ctx->r2 == 0) {
        // 0x80800418: lui         $a0, 0xE627
        ctx->r4 = S32(0XE627 << 16);
            goto L_80800440;
    }
L_80800418:
    // 0x80800418: lui         $a0, 0xE627
    ctx->r4 = S32(0XE627 << 16);
    // 0x8080041C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x80800420: ori         $a2, $a2, 0x640
    ctx->r6 = ctx->r6 | 0X640;
    // 0x80800424: ori         $a0, $a0, 0xD4AE
    ctx->r4 = ctx->r4 | 0XD4AE;
    // 0x80800428: jal         0x800C4140
    // 0x8080042C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_16;
    // 0x8080042C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_16:
    // 0x80800430: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800434: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800438: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8080043C: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
L_80800440:
    // 0x80800440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800444:
    // 0x80800444: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800448: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080044C: jr          $ra
    // 0x80800450: nop

    return;
    // 0x80800450: nop

;}
RECOMP_FUNC void _baeggcursor_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AD8: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084AD8);
    return;
    // 0x80084ADC: xori        $t0, $zero, 0x14
    ctx->r8 = 0 ^ 0X14;
;}
RECOMP_FUNC void func_80801218_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080121C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801224: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801228: jal         0x80800300
    // 0x8080122C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_80800300_bswasher(rdram, ctx);
        goto after_0;
    // 0x8080122C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801230: jal         0x8009640C
    // 0x80801234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009640C(rdram, ctx);
        goto after_1;
    // 0x80801234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801238: beq         $v0, $zero, L_80801248
    if (ctx->r2 == 0) {
        // 0x8080123C: nop
    
            goto L_80801248;
    }
    // 0x8080123C: nop

    // 0x80801240: jal         0x800A2EAC
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2EAC(rdram, ctx);
        goto after_2;
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80801248:
    // 0x80801248: jal         0x80085158
    // 0x8080124C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baspin_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080124C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801250: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801254: bne         $v0, $at, L_80801264
    if (ctx->r2 != ctx->r1) {
        // 0x80801258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801264;
    }
    // 0x80801258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080125C: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80801260: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80801264:
    // 0x80801264: jal         0x8009E5C8
    // 0x80801268: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80801268: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8080126C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801270: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801274: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801278: jr          $ra
    // 0x8080127C: nop

    return;
    // 0x8080127C: nop

;}
RECOMP_FUNC void _bsmumsplat_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838C8: syscall     79
    recomp_syscall_handler(rdram, ctx, 0x800838C8);
    return;
    // 0x800838CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _badrone_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084860: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084860);
    return;
    // 0x80084864: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void gcnewoption_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080143C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80801440: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80801444: lh          $v0, 0xB0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0XB0);
    // 0x80801448: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8080144C: jr          $ra
    // 0x80801450: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
    return;
    // 0x80801450: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80012530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012530: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80012534: jr          $ra
    // 0x80012538: lw          $v0, 0x3380($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3380);
    return;
    // 0x80012538: lw          $v0, 0x3380($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3380);
;}
RECOMP_FUNC void _badust_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A30: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x80084A30);
    return;
    // 0x80084A34: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80801658_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080165C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801660: jal         0x80106790
    // 0x80801664: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801664: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801668: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080166C: beql        $t6, $zero, L_80801688
    if (ctx->r14 == 0) {
        // 0x80801670: lbu         $t0, 0x65($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X65);
            goto L_80801688;
    }
    goto skip_0;
    // 0x80801670: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
    skip_0:
    // 0x80801674: lbu         $t8, 0x65($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X65);
    // 0x80801678: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8080167C: b           L_80801690
    // 0x80801680: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
        goto L_80801690;
    // 0x80801680: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
    // 0x80801684: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
L_80801688:
    // 0x80801688: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x8080168C: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
L_80801690:
    // 0x80801690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801698: jr          $ra
    // 0x8080169C: nop

    return;
    // 0x8080169C: nop

;}
RECOMP_FUNC void func_80801C74_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801C78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801C80: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x80801C84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801C88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801C8C: lw          $t6, 0xA8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XA8);
    // 0x80801C90: bnel        $t6, $at, L_80801D20
    if (ctx->r14 != ctx->r1) {
        // 0x80801C94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801D20;
    }
    goto skip_0;
    // 0x80801C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801C98: lw          $v0, 0xAC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XAC);
    // 0x80801C9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801CA0: beq         $v0, $zero, L_80801CB8
    if (ctx->r2 == 0) {
        // 0x80801CA4: nop
    
            goto L_80801CB8;
    }
    // 0x80801CA4: nop

    // 0x80801CA8: beq         $v0, $a1, L_80801CC0
    if (ctx->r2 == ctx->r5) {
        // 0x80801CAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CC0;
    }
    // 0x80801CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CB0: b           L_80801D20
    // 0x80801CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801D20;
    // 0x80801CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801CB8:
    // 0x80801CB8: b           L_80801D1C
    // 0x80801CBC: sw          $zero, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = 0;
        goto L_80801D1C;
    // 0x80801CBC: sw          $zero, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = 0;
L_80801CC0:
    // 0x80801CC0: sw          $a1, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r5;
    // 0x80801CC4: jal         0x80801D70
    // 0x80801CC8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80801D70_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80801CC8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80801CCC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801CD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CD8: lw          $v0, 0xA4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XA4);
    // 0x80801CDC: beq         $v0, $zero, L_80801D08
    if (ctx->r2 == 0) {
        // 0x80801CE0: nop
    
            goto L_80801D08;
    }
    // 0x80801CE0: nop

    // 0x80801CE4: bne         $v0, $at, L_80801D1C
    if (ctx->r2 != ctx->r1) {
        // 0x80801CE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D1C;
    }
    // 0x80801CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CEC: jal         0x80084AE8
    // 0x80801CF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _baeggcursor_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80801CF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80801CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CF8: jal         0x80802438
    // 0x80801CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802438_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80801CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801D00: b           L_80801D20
    // 0x80801D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801D20;
    // 0x80801D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801D08:
    // 0x80801D08: jal         0x80084AE8
    // 0x80801D0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baeggcursor_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80801D0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D14: jal         0x80802438
    // 0x80801D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802438_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80801D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80801D1C:
    // 0x80801D1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801D20:
    // 0x80801D20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801D28: jr          $ra
    // 0x80801D2C: nop

    return;
    // 0x80801D2C: nop

;}
RECOMP_FUNC void func_8009BD88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BD88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BD8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BD90: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x8009BD94: jal         0x8009BDAC
    // 0x8009BD98: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_8009BDAC(rdram, ctx);
        goto after_0;
    // 0x8009BD98: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_0:
    // 0x8009BD9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BDA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BDA4: jr          $ra
    // 0x8009BDA8: nop

    return;
    // 0x8009BDA8: nop

;}
RECOMP_FUNC void func_801073AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801073AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801073B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801073B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801073B8: jal         0x80107388
    // 0x801073BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80107388(rdram, ctx);
        goto after_0;
    // 0x801073BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801073C0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801073C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801073C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801073CC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x801073D0: jal         0x80102424
    // 0x801073D4: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x801073D4: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    after_1:
    // 0x801073D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801073DC: addiu       $a1, $zero, 0x8F
    ctx->r5 = ADD32(0, 0X8F);
    // 0x801073E0: jal         0x8010108C
    // 0x801073E4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_8010108C(rdram, ctx);
        goto after_2;
    // 0x801073E4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x801073E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801073EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801073F0: jr          $ra
    // 0x801073F4: nop

    return;
    // 0x801073F4: nop

;}
RECOMP_FUNC void func_8008BD94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BD94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008BD98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008BD9C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008BDA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008BDA4: lbu         $t6, 0x1B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008BDA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008BDAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008BDB0: bnel        $t6, $at, L_8008BDE8
    if (ctx->r14 != ctx->r1) {
        // 0x8008BDB4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8008BDE8;
    }
    goto skip_0;
    // 0x8008BDB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8008BDB8: jal         0x8008BC94
    // 0x8008BDBC: nop

    func_8008BC94(rdram, ctx);
        goto after_0;
    // 0x8008BDBC: nop

    after_0:
    // 0x8008BDC0: beql        $v0, $zero, L_8008BDE8
    if (ctx->r2 == 0) {
        // 0x8008BDC4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8008BDE8;
    }
    goto skip_1;
    // 0x8008BDC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x8008BDC8: lbu         $t7, 0x8($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X8);
    // 0x8008BDCC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008BDD0: beql        $t7, $zero, L_8008BDE4
    if (ctx->r15 == 0) {
        // 0x8008BDD4: sb          $t8, 0x8($s0)
        MEM_B(0X8, ctx->r16) = ctx->r24;
            goto L_8008BDE4;
    }
    goto skip_2;
    // 0x8008BDD4: sb          $t8, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r24;
    skip_2:
    // 0x8008BDD8: b           L_8008BDE4
    // 0x8008BDDC: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
        goto L_8008BDE4;
    // 0x8008BDDC: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // 0x8008BDE0: sb          $t8, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r24;
L_8008BDE4:
    // 0x8008BDE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8008BDE8:
    // 0x8008BDE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008BDEC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8008BDF0: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x8008BDF4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8008BDF8: nop

    // 0x8008BDFC: bc1f        L_8008BE78
    if (!c1cs) {
        // 0x8008BE00: nop
    
            goto L_8008BE78;
    }
    // 0x8008BE00: nop

    // 0x8008BE04: jal         0x8008BCB4
    // 0x8008BE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BCB4(rdram, ctx);
        goto after_1;
    // 0x8008BE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8008BE0C: beq         $v0, $zero, L_8008BE78
    if (ctx->r2 == 0) {
        // 0x8008BE10: nop
    
            goto L_8008BE78;
    }
    // 0x8008BE10: nop

    // 0x8008BE14: jal         0x800D674C
    // 0x8008BE18: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x8008BE18: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    after_2:
    tooie_run_anim_file(rdram, ctx);
    // 0x8008BE1C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8008BE20: jal         0x8008BD1C
    // 0x8008BE24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD1C(rdram, ctx);
        goto after_3;
    // 0x8008BE24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008BE28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008BE2C: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x8008BE30: lbu         $a2, 0x1E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1E);
    // 0x8008BE34: jal         0x800E0170
    // 0x8008BE38: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800E0170(rdram, ctx);
        goto after_4;
    // 0x8008BE38: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_4:
    // 0x8008BE3C: jal         0x8008BD1C
    // 0x8008BE40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD1C(rdram, ctx);
        goto after_5;
    // 0x8008BE40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8008BE44: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8008BE48: jal         0x8008BD3C
    // 0x8008BE4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD3C(rdram, ctx);
        goto after_6;
    // 0x8008BE4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8008BE50: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8008BE54: jal         0x8008BD1C
    // 0x8008BE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD1C(rdram, ctx);
        goto after_7;
    // 0x8008BE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8008BE5C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8008BE60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008BE64: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8008BE68: jal         0x800DFD64
    // 0x8008BE6C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800DFD64(rdram, ctx);
        goto after_8;
    // 0x8008BE6C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_8:
    // 0x8008BE70: b           L_8008BEA4
    // 0x8008BE74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008BEA4;
    // 0x8008BE74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008BE78:
    // 0x8008BE78: jal         0x800D674C
    // 0x8008BE7C: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    func_800D674C(rdram, ctx);
        goto after_9;
    // 0x8008BE7C: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    after_9:
    tooie_run_anim_file(rdram, ctx);
    // 0x8008BE80: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8008BE84: jal         0x8008BD1C
    // 0x8008BE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD1C(rdram, ctx);
        goto after_10;
    // 0x8008BE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8008BE8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008BE90: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x8008BE94: lbu         $a2, 0x1E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1E);
    // 0x8008BE98: jal         0x800E0170
    // 0x8008BE9C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800E0170(rdram, ctx);
        goto after_11;
    // 0x8008BE9C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_11:
    // 0x8008BEA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008BEA4:
    // 0x8008BEA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008BEA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008BEAC: jr          $ra
    // 0x8008BEB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008BEB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800137AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800137AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800137B0: lwc1        $f14, 0x16C8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16C8);
    // 0x800137B4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800137B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800137BC: b           L_80013818
    // 0x800137C0: nop

    func_80013818(rdram, ctx);
    return;
    // 0x800137C0: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CC8: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CC8);
    return;
    // 0x80083CCC: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void func_808057C8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808057C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808057CC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808057D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808057D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808057D8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808057DC: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x808057E0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808057E4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808057E8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808057EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808057F0: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808057F4: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x808057F8: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808057FC: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80805800: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80805804: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80805808: nop

    // 0x8080580C: bc1fl       L_8080582C
    if (!c1cs) {
        // 0x80805810: lwc1        $f16, 0x54($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
            goto L_8080582C;
    }
    goto skip_0;
    // 0x80805810: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80805814: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80805818: jal         0x8080549C
    // 0x8080581C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_8080549C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080581C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80805820: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80805824: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80805828: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
L_8080582C:
    // 0x8080582C: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80805830: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
    // 0x80805834: nop

    // 0x80805838: bc1tl       L_808058D4
    if (c1cs) {
        // 0x8080583C: lwc1        $f8, 0x0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
            goto L_808058D4;
    }
    goto skip_1;
    // 0x8080583C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80805840: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x80805844: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80805848: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080584C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80805850: bc1f        L_80805868
    if (!c1cs) {
        // 0x80805854: addiu       $a3, $sp, 0x54
        ctx->r7 = ADD32(ctx->r29, 0X54);
            goto L_80805868;
    }
    // 0x80805854: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x80805858: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080585C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80805860: b           L_80805870
    // 0x80805864: nop

        goto L_80805870;
    // 0x80805864: nop

L_80805868:
    // 0x80805868: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080586C: nop

L_80805870:
    // 0x80805870: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80805874: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80805878: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8080587C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80805880: mul.s       $f14, $f8, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80805884: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80805888: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080588C: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x80805890: nop

    // 0x80805894: bc1fl       L_808058D4
    if (!c1cs) {
        // 0x80805898: lwc1        $f8, 0x0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
            goto L_808058D4;
    }
    goto skip_2;
    // 0x80805898: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8080589C: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x808058A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x808058A4: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x808058A8: jal         0x80805644
    // 0x808058AC: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    func_80805644_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808058AC: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x808058B0: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808058B4: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808058B8: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808058BC: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808058C0: nop

    // 0x808058C4: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x808058C8: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x808058CC: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x808058D0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
L_808058D4:
    // 0x808058D4: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808058D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808058DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808058E0: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x808058E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808058E8: jr          $ra
    // 0x808058EC: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
    return;
    // 0x808058EC: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
;}
RECOMP_FUNC void func_800DF41C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF41C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF420: jr          $ra
    // 0x800DF424: sw          $a0, -0x37DC($at)
    MEM_W(-0X37DC, ctx->r1) = ctx->r4;
    return;
    // 0x800DF424: sw          $a0, -0x37DC($at)
    MEM_W(-0X37DC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void suexpression_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E4: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x808005E8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808005EC: nop

    // 0x808005F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808005F4: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x808005F8: lh          $t7, 0x8($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8);
    // 0x808005FC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80800600: nop

    // 0x80800604: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800608: jr          $ra
    // 0x8080060C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    return;
    // 0x8080060C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_800AA220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA220: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AA224: addiu       $t7, $t7, 0x7780
    ctx->r15 = ADD32(ctx->r15, 0X7780);
    // 0x800AA228: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800AA22C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AA230: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800AA234: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800AA238: jr          $ra
    // 0x800AA23C: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    return;
    // 0x800AA23C: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_80110F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110F44: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80110F48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110F4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80110F50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80110F54: jal         0x80112524
    // 0x80110F58: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80110F58: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x80110F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80110F60: jal         0x801107F0
    // 0x80110F64: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x80110F64: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x80110F68: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80110F6C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80110F70: jal         0x800EFB24
    // 0x80110F74: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80110F74: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x80110F78: jal         0x80110840
    // 0x80110F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110840(rdram, ctx);
        goto after_3;
    // 0x80110F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80110F80: jal         0x800F53D0
    // 0x80110F84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_4;
    // 0x80110F84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80110F88: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80110F8C: jal         0x800EEFFC
    // 0x80110F90: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EEFFC(rdram, ctx);
        goto after_5;
    // 0x80110F90: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80110F94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80110F98: jal         0x800A4EFC
    // 0x80110F9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800A4EFC(rdram, ctx);
        goto after_6;
    // 0x80110F9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80110FA0: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80110FA4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80110FA8: bnel        $t6, $at, L_80110FBC
    if (ctx->r14 != ctx->r1) {
        // 0x80110FAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80110FBC;
    }
    goto skip_0;
    // 0x80110FAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80110FB0: jal         0x80089168
    // 0x80110FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _ncbastring_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80110FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80110FB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80110FBC:
    // 0x80110FBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80110FC0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80110FC4: jr          $ra
    // 0x80110FC8: nop

    return;
    // 0x80110FC8: nop

;}
RECOMP_FUNC void func_80801558_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801558: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8080155C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2336, 0X2540) << 16);
    // 0x80801560: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801564: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80801568: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8080156C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80801570: addiu       $t7, $t7, 0x2540
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2336, 0X2540));
    // 0x80801574: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80801578: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x8080157C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80801580: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80801584: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80801588: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2336, 0X254C) << 16);
    // 0x8080158C: addiu       $t2, $t2, 0x254C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2336, 0X254C));
    // 0x80801590: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80801594: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80801598: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8080159C: addiu       $t1, $sp, 0x44
    ctx->r9 = ADD32(ctx->r29, 0X44);
    // 0x808015A0: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x808015A4: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x808015A8: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x808015AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808015B0: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x808015B4: jal         0x8080206C
    // 0x808015B8: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_0;
    // 0x808015B8: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    after_0:
    // 0x808015BC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808015C0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808015C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808015C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808015CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808015D0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808015D4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808015D8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808015DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808015E0: jal         0x800F10B4
    // 0x808015E4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808015E4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x808015E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X24C4) << 16);
    // 0x808015EC: lwc1        $f8, 0x24C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2336, 0X24C4));
    // 0x808015F0: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808015F4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808015F8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808015FC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80801600: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80801604: jal         0x800F10B4
    // 0x80801608: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80801608: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8080160C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X24C8) << 16);
    // 0x80801610: lwc1        $f10, 0x24C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2336, 0X24C8));
    // 0x80801614: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80801618: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8080161C: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x80801620: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80801624: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80801628: jal         0x800F10B4
    // 0x8080162C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x8080162C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80801630: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X24CC) << 16);
    // 0x80801634: lwc1        $f16, 0x24CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2336, 0X24CC));
    // 0x80801638: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080163C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801640: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x80801644: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80801648: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8080164C: jal         0x800F10B4
    // 0x80801650: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80801650: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80801654: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X24D0) << 16);
    // 0x80801658: lwc1        $f18, 0x24D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2336, 0X24D0));
    // 0x8080165C: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80801660: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801664: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x80801668: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8080166C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80801670: jal         0x800F10B4
    // 0x80801674: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80801674: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80801678: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X24D4) << 16);
    // 0x8080167C: lwc1        $f4, 0x24D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2336, 0X24D4));
    // 0x80801680: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80801684: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801688: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x8080168C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80801690: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80801694: jal         0x800F10B4
    // 0x80801698: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80801698: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8080169C: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x808016A0: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x808016A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016A8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808016AC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808016B0: jal         0x800F3214
    // 0x808016B4: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800F3214(rdram, ctx);
        goto after_7;
    // 0x808016B4: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_7:
    // 0x808016B8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808016BC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x808016C0: jal         0x800BF48C
    // 0x808016C4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    func_800BF48C(rdram, ctx);
        goto after_8;
    // 0x808016C4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    after_8:
    // 0x808016C8: jal         0x800C8C90
    // 0x808016CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C8C90(rdram, ctx);
        goto after_9;
    // 0x808016CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808016D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808016D4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808016D8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808016DC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808016E0: jr          $ra
    // 0x808016E4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808016E4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _bsbkflamethrower_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829A8: syscall     23
    recomp_syscall_handler(rdram, ctx, 0x800829A8);
    return;
    // 0x800829AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _vpflicker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089048: syscall     757
    recomp_syscall_handler(rdram, ctx, 0x80089048);
    return;
    // 0x8008904C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bsstand_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CCC: jal         0x80800038
    // 0x80800CD0: nop

    func_80800038_bsstand(rdram, ctx);
        goto after_0;
    // 0x80800CD0: nop

    after_0:
    // 0x80800CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CDC: jr          $ra
    // 0x80800CE0: nop

    return;
    // 0x80800CE0: nop

;}
RECOMP_FUNC void func_80090460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090468: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009046C: jal         0x800F54E4
    // 0x80090470: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090470: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80090474: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090478: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8009047C: jal         0x800F79DC
    // 0x80090480: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F79DC(rdram, ctx);
        goto after_1;
    // 0x80090480: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80090484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009048C: jr          $ra
    // 0x80090490: nop

    return;
    // 0x80090490: nop

;}
RECOMP_FUNC void chtntbox_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1892, 0X9D0) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x9D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1892, 0X9D0));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x9D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1892, 0X9D0));
;}
RECOMP_FUNC void fxfontstring_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: jal         0x80800000
    // 0x80800030: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800000_fxfontstring(rdram, ctx);
        goto after_0;
    // 0x80800030: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800034: addiu       $t6, $zero, 0xFD
    ctx->r14 = ADD32(0, 0XFD);
    // 0x80800038: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8080003C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800040: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80800044: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80800048: beq         $t7, $zero, L_8080005C
    if (ctx->r15 == 0) {
        // 0x8080004C: addiu       $t9, $zero, 0x6C
        ctx->r25 = ADD32(0, 0X6C);
            goto L_8080005C;
    }
    // 0x8080004C: addiu       $t9, $zero, 0x6C
    ctx->r25 = ADD32(0, 0X6C);
    // 0x80800050: addiu       $t8, $zero, 0x68
    ctx->r24 = ADD32(0, 0X68);
    // 0x80800054: b           L_80800060
    // 0x80800058: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
        goto L_80800060;
    // 0x80800058: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_8080005C:
    // 0x8080005C: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
L_80800060:
    // 0x80800060: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void func_80801B94_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B9C: jal         0x80082FE8
    // 0x80801BA0: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801BA0: nop

    after_0:
    // 0x80801BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801BAC: jr          $ra
    // 0x80801BB0: nop

    return;
    // 0x80801BB0: nop

;}
RECOMP_FUNC void chfantasysafe_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800934: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2380, 0XAE8) << 16);
    // 0x80800938: jr          $ra
    // 0x8080093C: addiu       $v0, $v0, 0xAE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2380, 0XAE8));
    return;
    // 0x8080093C: addiu       $v0, $v0, 0xAE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2380, 0XAE8));
;}
RECOMP_FUNC void _gldialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088730: syscall     702
    recomp_syscall_handler(rdram, ctx, 0x80088730);
    return;
    // 0x80088734: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D00: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D00);
    return;
    // 0x80082D04: addi        $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
;}
RECOMP_FUNC void func_80807B4C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807B4C: jr          $ra
    // 0x80807B50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80807B50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808013B4_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808013B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808013C0: jal         0x80100094
    // 0x808013C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808013C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013C8: jal         0x80104200
    // 0x808013CC: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    func_80104200(rdram, ctx);
        goto after_1;
    // 0x808013CC: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x808013D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808013D4: jal         0x8008AF24
    // 0x808013D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x808013D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013E0: jal         0x8008B134
    // 0x808013E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_3;
    // 0x808013E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808013E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013EC: jal         0x8008AED4
    // 0x808013F0: addiu       $a1, $zero, 0x481
    ctx->r5 = ADD32(0, 0X481);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x808013F0: addiu       $a1, $zero, 0x481
    ctx->r5 = ADD32(0, 0X481);
    after_4:
    // 0x808013F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013F8: jal         0x8008B1BC
    // 0x808013FC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808013FC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80801400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801404: jal         0x8008B188
    // 0x80801408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_6;
    // 0x80801408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080140C: jal         0x8008B064
    // 0x80801410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80801410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801418: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080141C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801420: jr          $ra
    // 0x80801424: nop

    return;
    // 0x80801424: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800124: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800128: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800134: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800138: jal         0x8010FE14
    // 0x8080013C: addiu       $a2, $a1, 0xC
    ctx->r6 = ADD32(ctx->r5, 0XC);
    func_8010FE14(rdram, ctx);
        goto after_0;
    // 0x8080013C: addiu       $a2, $a1, 0xC
    ctx->r6 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void func_8080292C_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080292C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80802930: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80802934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802938: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080293C: bne         $a1, $at, L_80802C20
    if (ctx->r5 != ctx->r1) {
        // 0x80802940: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80802C20;
    }
    // 0x80802940: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80802944: jal         0x800D3948
    // 0x80802948: nop

    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80802948: nop

    after_0:
    // 0x8080294C: beql        $v0, $zero, L_80802960
    if (ctx->r2 == 0) {
        // 0x80802950: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_80802960;
    }
    goto skip_0;
    // 0x80802950: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    skip_0:
    // 0x80802954: b           L_80802960
    // 0x80802958: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80802960;
    // 0x80802958: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080295C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_80802960:
    // 0x80802960: jal         0x800B53A4
    // 0x80802964: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x80802964: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80802968: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8080296C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80802970: jal         0x80106790
    // 0x80802974: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80802974: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    after_2:
    // 0x80802978: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8080297C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2384, 0X3324) << 16);
    // 0x80802980: addiu       $t7, $t7, 0x3324
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2384, 0X3324));
    // 0x80802984: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80802988: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080298C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80802990: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80802994: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80802998: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080299C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808029A0: jal         0x800BABB8
    // 0x808029A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x808029A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x808029A8: jal         0x800D3948
    // 0x808029AC: nop

    func_800D3948(rdram, ctx);
        goto after_4;
    // 0x808029AC: nop

    after_4:
    // 0x808029B0: bne         $v0, $zero, L_808029E0
    if (ctx->r2 != 0) {
        // 0x808029B4: nop
    
            goto L_808029E0;
    }
    // 0x808029B4: nop

    // 0x808029B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808029BC: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2384, 0X3364) << 16);
    // 0x808029C0: addiu       $t8, $t8, 0x3364
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2384, 0X3364));
    // 0x808029C4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808029C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808029CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808029D0: jal         0x800BABB8
    // 0x808029D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x808029D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_5:
    // 0x808029D8: b           L_808029EC
    // 0x808029DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_808029EC;
    // 0x808029DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_808029E0:
    // 0x808029E0: jal         0x8008A0B0
    // 0x808029E4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    _subaddiemulti_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x808029E4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_6:
    // 0x808029E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_808029EC:
    // 0x808029EC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x808029F0: addiu       $at, $zero, 0x804
    ctx->r1 = ADD32(0, 0X804);
    // 0x808029F4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x808029F8: lhu         $a1, 0x14($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X14);
    // 0x808029FC: beq         $a1, $at, L_80802A68
    if (ctx->r5 == ctx->r1) {
        // 0x80802A00: addiu       $at, $zero, 0x805
        ctx->r1 = ADD32(0, 0X805);
            goto L_80802A68;
    }
    // 0x80802A00: addiu       $at, $zero, 0x805
    ctx->r1 = ADD32(0, 0X805);
    // 0x80802A04: beq         $a1, $at, L_80802A34
    if (ctx->r5 == ctx->r1) {
        // 0x80802A08: addiu       $at, $zero, 0x806
        ctx->r1 = ADD32(0, 0X806);
            goto L_80802A34;
    }
    // 0x80802A08: addiu       $at, $zero, 0x806
    ctx->r1 = ADD32(0, 0X806);
    // 0x80802A0C: beq         $a1, $at, L_80802A9C
    if (ctx->r5 == ctx->r1) {
        // 0x80802A10: addiu       $at, $zero, 0x99D
        ctx->r1 = ADD32(0, 0X99D);
            goto L_80802A9C;
    }
    // 0x80802A10: addiu       $at, $zero, 0x99D
    ctx->r1 = ADD32(0, 0X99D);
    // 0x80802A14: beq         $a1, $at, L_80802A34
    if (ctx->r5 == ctx->r1) {
        // 0x80802A18: addiu       $at, $zero, 0x99E
        ctx->r1 = ADD32(0, 0X99E);
            goto L_80802A34;
    }
    // 0x80802A18: addiu       $at, $zero, 0x99E
    ctx->r1 = ADD32(0, 0X99E);
    // 0x80802A1C: beq         $a1, $at, L_80802A68
    if (ctx->r5 == ctx->r1) {
        // 0x80802A20: addiu       $at, $zero, 0x99F
        ctx->r1 = ADD32(0, 0X99F);
            goto L_80802A68;
    }
    // 0x80802A20: addiu       $at, $zero, 0x99F
    ctx->r1 = ADD32(0, 0X99F);
    // 0x80802A24: beq         $a1, $at, L_80802A9C
    if (ctx->r5 == ctx->r1) {
        // 0x80802A28: nop
    
            goto L_80802A9C;
    }
    // 0x80802A28: nop

    // 0x80802A2C: b           L_80802AD0
    // 0x80802A30: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
        goto L_80802AD0;
    // 0x80802A30: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_80802A34:
    // 0x80802A34: jal         0x800D3948
    // 0x80802A38: nop

    func_800D3948(rdram, ctx);
        goto after_7;
    // 0x80802A38: nop

    after_7:
    // 0x80802A3C: bne         $v0, $zero, L_80802A50
    if (ctx->r2 != 0) {
        // 0x80802A40: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80802A50;
    }
    // 0x80802A40: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802A44: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2384, 0X3394) << 16);
    // 0x80802A48: jal         0x800BAB80
    // 0x80802A4C: addiu       $a1, $a1, 0x3394
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2384, 0X3394));
    func_800BAB80(rdram, ctx);
        goto after_8;
    // 0x80802A4C: addiu       $a1, $a1, 0x3394
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2384, 0X3394));
    after_8:
L_80802A50:
    // 0x80802A50: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80802A54: jal         0x800BA670
    // 0x80802A58: addiu       $a1, $zero, 0x920
    ctx->r5 = ADD32(0, 0X920);
    func_800BA670(rdram, ctx);
        goto after_9;
    // 0x80802A58: addiu       $a1, $zero, 0x920
    ctx->r5 = ADD32(0, 0X920);
    after_9:
    // 0x80802A5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80802A60: b           L_80802ACC
    // 0x80802A64: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
        goto L_80802ACC;
    // 0x80802A64: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_80802A68:
    // 0x80802A68: jal         0x800D3948
    // 0x80802A6C: nop

    func_800D3948(rdram, ctx);
        goto after_10;
    // 0x80802A6C: nop

    after_10:
    // 0x80802A70: bne         $v0, $zero, L_80802A84
    if (ctx->r2 != 0) {
        // 0x80802A74: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80802A84;
    }
    // 0x80802A74: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802A78: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2384, 0X3398) << 16);
    // 0x80802A7C: jal         0x800BAB80
    // 0x80802A80: addiu       $a1, $a1, 0x3398
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2384, 0X3398));
    func_800BAB80(rdram, ctx);
        goto after_11;
    // 0x80802A80: addiu       $a1, $a1, 0x3398
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2384, 0X3398));
    after_11:
L_80802A84:
    // 0x80802A84: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80802A88: jal         0x800BA670
    // 0x80802A8C: addiu       $a1, $zero, 0x921
    ctx->r5 = ADD32(0, 0X921);
    func_800BA670(rdram, ctx);
        goto after_12;
    // 0x80802A8C: addiu       $a1, $zero, 0x921
    ctx->r5 = ADD32(0, 0X921);
    after_12:
    // 0x80802A90: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80802A94: b           L_80802ACC
    // 0x80802A98: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
        goto L_80802ACC;
    // 0x80802A98: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_80802A9C:
    // 0x80802A9C: jal         0x800D3948
    // 0x80802AA0: nop

    func_800D3948(rdram, ctx);
        goto after_13;
    // 0x80802AA0: nop

    after_13:
    // 0x80802AA4: bne         $v0, $zero, L_80802AB8
    if (ctx->r2 != 0) {
        // 0x80802AA8: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80802AB8;
    }
    // 0x80802AA8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802AAC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2384, 0X339C) << 16);
    // 0x80802AB0: jal         0x800BAB80
    // 0x80802AB4: addiu       $a1, $a1, 0x339C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2384, 0X339C));
    func_800BAB80(rdram, ctx);
        goto after_14;
    // 0x80802AB4: addiu       $a1, $a1, 0x339C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2384, 0X339C));
    after_14:
L_80802AB8:
    // 0x80802AB8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80802ABC: jal         0x800BA670
    // 0x80802AC0: addiu       $a1, $zero, 0x922
    ctx->r5 = ADD32(0, 0X922);
    func_800BA670(rdram, ctx);
        goto after_15;
    // 0x80802AC0: addiu       $a1, $zero, 0x922
    ctx->r5 = ADD32(0, 0X922);
    after_15:
    // 0x80802AC4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80802AC8: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
L_80802ACC:
    // 0x80802ACC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_80802AD0:
    // 0x80802AD0: jal         0x80106790
    // 0x80802AD4: lw          $a0, 0x3C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X3C);
    func_80106790(rdram, ctx);
        goto after_16;
    // 0x80802AD4: lw          $a0, 0x3C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X3C);
    after_16:
    // 0x80802AD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802ADC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80802AE0: jal         0x80800144
    // 0x80802AE4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_80800144_chtrashcangame(rdram, ctx);
        goto after_17;
    // 0x80802AE4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_17:
    // 0x80802AE8: jal         0x800D3948
    // 0x80802AEC: nop

    func_800D3948(rdram, ctx);
        goto after_18;
    // 0x80802AEC: nop

    after_18:
    // 0x80802AF0: beq         $v0, $zero, L_80802B00
    if (ctx->r2 == 0) {
        // 0x80802AF4: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_80802B00;
    }
    // 0x80802AF4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80802AF8: b           L_80802B00
    // 0x80802AFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80802B00;
    // 0x80802AFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80802B00:
    // 0x80802B00: jal         0x800BA22C
    // 0x80802B04: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800BA22C(rdram, ctx);
        goto after_19;
    // 0x80802B04: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_19:
    // 0x80802B08: jal         0x800D3948
    // 0x80802B0C: nop

    func_800D3948(rdram, ctx);
        goto after_20;
    // 0x80802B0C: nop

    after_20:
    // 0x80802B10: bne         $v0, $zero, L_80802B20
    if (ctx->r2 != 0) {
        // 0x80802B14: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80802B20;
    }
    // 0x80802B14: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802B18: jal         0x800BA22C
    // 0x80802B1C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_21;
    // 0x80802B1C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_21:
L_80802B20:
    // 0x80802B20: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80802B24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80802B28: lw          $t5, 0x50($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X50);
    // 0x80802B2C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80802B30: sw          $t6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r14;
    // 0x80802B34: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802B38: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80802B3C: jal         0x80086468
    // 0x80802B40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _chscorepoints_entrypoint_2(rdram, ctx);
        goto after_22;
    // 0x80802B40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_22:
    // 0x80802B44: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80802B48: jal         0x800FFA88
    // 0x80802B4C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_23;
    // 0x80802B4C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_23:
    // 0x80802B50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FDC) << 16);
    // 0x80802B54: lwc1        $f12, 0x2FDC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FDC));
    // 0x80802B58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FE0) << 16);
    // 0x80802B5C: jal         0x800DC178
    // 0x80802B60: lwc1        $f14, 0x2FE0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FE0));
    func_800DC178(rdram, ctx);
        goto after_24;
    // 0x80802B60: lwc1        $f14, 0x2FE0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FE0));
    after_24:
    // 0x80802B64: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2FE4) << 16);
    // 0x80802B68: lwc1        $f4, 0x2FE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2FE4));
    // 0x80802B6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802B70: lui         $a2, 0x5DC
    ctx->r6 = S32(0X5DC << 16);
    // 0x80802B74: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80802B78: ori         $a2, $a2, 0x190
    ctx->r6 = ctx->r6 | 0X190;
    // 0x80802B7C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80802B80: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80802B84: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80802B88: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802B8C: nop

    // 0x80802B90: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80802B94: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802B98: nop

    // 0x80802B9C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802BA0: beql        $a0, $zero, L_80802BF0
    if (ctx->r4 == 0) {
        // 0x80802BA4: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_80802BF0;
    }
    goto skip_1;
    // 0x80802BA4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x80802BA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802BAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802BB0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80802BB4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80802BB8: nop

    // 0x80802BBC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80802BC0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80802BC4: nop

    // 0x80802BC8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80802BCC: bne         $a0, $zero, L_80802BE4
    if (ctx->r4 != 0) {
        // 0x80802BD0: nop
    
            goto L_80802BE4;
    }
    // 0x80802BD0: nop

    // 0x80802BD4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80802BD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80802BDC: b           L_80802BFC
    // 0x80802BE0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80802BFC;
    // 0x80802BE0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80802BE4:
    // 0x80802BE4: b           L_80802BFC
    // 0x80802BE8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80802BFC;
    // 0x80802BE8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80802BEC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_80802BF0:
    // 0x80802BF0: nop

    // 0x80802BF4: bltz        $a0, L_80802BE4
    if (SIGNED(ctx->r4) < 0) {
        // 0x80802BF8: nop
    
            goto L_80802BE4;
    }
    // 0x80802BF8: nop

L_80802BFC:
    // 0x80802BFC: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x80802C00: lui         $at, 0x1F
    ctx->r1 = S32(0X1F << 16);
    // 0x80802C04: ori         $at, $at, 0xFC1F
    ctx->r1 = ctx->r1 | 0XFC1F;
    // 0x80802C08: sll         $t0, $t9, 21
    ctx->r8 = S32(ctx->r25 << 21);
    // 0x80802C0C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80802C10: jal         0x800C4140
    // 0x80802C14: addu        $a0, $t0, $at
    ctx->r4 = ADD32(ctx->r8, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_25;
    // 0x80802C14: addu        $a0, $t0, $at
    ctx->r4 = ADD32(ctx->r8, ctx->r1);
    after_25:
    // 0x80802C18: b           L_80802C24
    // 0x80802C1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802C24;
    // 0x80802C1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802C20:
    // 0x80802C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802C24:
    // 0x80802C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802C28: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802C2C: jr          $ra
    // 0x80802C30: nop

    return;
    // 0x80802C30: nop

;}
RECOMP_FUNC void func_800D5234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5234: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5238: jr          $ra
    // 0x800D523C: sw          $a0, -0x4BE0($at)
    MEM_W(-0X4BE0, ctx->r1) = ctx->r4;
    return;
    // 0x800D523C: sw          $a0, -0x4BE0($at)
    MEM_W(-0X4BE0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void baattach_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8080000C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800010: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800014: beq         $t7, $zero, L_80800024
    if (ctx->r15 == 0) {
        // 0x80800018: nop
    
            goto L_80800024;
    }
    // 0x80800018: nop

    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800024:
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void func_80800894_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800894: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080089C: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808008A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808008A4: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808008A8: jal         0x8008CB10
    // 0x808008AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x808008AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808008B0: beq         $v0, $zero, L_808008BC
    if (ctx->r2 == 0) {
        // 0x808008B4: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_808008BC;
    }
    // 0x808008B4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808008B8: addiu       $a2, $zero, 0x15D
    ctx->r6 = ADD32(0, 0X15D);
L_808008BC:
    // 0x808008BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008C0: jal         0x8009E5C8
    // 0x808008C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x808008C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x808008C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008D0: jr          $ra
    // 0x808008D4: nop

    return;
    // 0x808008D4: nop

;}
RECOMP_FUNC void cheggice_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800284: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2120, 0X3E0) << 16);
    // 0x80800288: jr          $ra
    // 0x8080028C: addiu       $v0, $v0, 0x3E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2120, 0X3E0));
    return;
    // 0x8080028C: addiu       $v0, $v0, 0x3E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2120, 0X3E0));
;}
RECOMP_FUNC void _gspropprop_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C18: syscall     729
    recomp_syscall_handler(rdram, ctx, 0x80088C18);
    return;
    // 0x80088C1C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802DA8_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802DA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802DB0: jal         0x80088848
    // 0x80802DB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80802DB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802DB8: beql        $v0, $zero, L_80802DCC
    if (ctx->r2 == 0) {
        // 0x80802DBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802DCC;
    }
    goto skip_0;
    // 0x80802DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802DC0: jal         0x80800314
    // 0x80802DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800314_chfantasyathlete(rdram, ctx);
        goto after_1;
    // 0x80802DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80802DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802DCC:
    // 0x80802DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802DD0: jr          $ra
    // 0x80802DD4: nop

    return;
    // 0x80802DD4: nop

;}
RECOMP_FUNC void func_800B7DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7DC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7DCC: lw          $a0, -0x7D50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D50);
    // 0x800B7DD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7DD8: beq         $a0, $zero, L_800B7DF4
    if (ctx->r4 == 0) {
        // 0x800B7DDC: nop
    
            goto L_800B7DF4;
    }
    // 0x800B7DDC: nop

    // 0x800B7DE0: jal         0x80088930
    // 0x800B7DE4: nop

    _fxleaves_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800B7DE4: nop

    after_0:
    // 0x800B7DE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7DEC: jal         0x80088960
    // 0x800B7DF0: lw          $a0, -0x7D50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D50);
    _fxleaves_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x800B7DF0: lw          $a0, -0x7D50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D50);
    after_1:
L_800B7DF4:
    // 0x800B7DF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7DF8: lw          $a0, -0x7D4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D4C);
    // 0x800B7DFC: beq         $a0, $zero, L_800B7E18
    if (ctx->r4 == 0) {
        // 0x800B7E00: nop
    
            goto L_800B7E18;
    }
    // 0x800B7E00: nop

    // 0x800B7E04: jal         0x800888E0
    // 0x800B7E08: nop

    _fxrain_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x800B7E08: nop

    after_2:
    // 0x800B7E0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7E10: jal         0x80088920
    // 0x800B7E14: lw          $a0, -0x7D4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D4C);
    _fxrain_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x800B7E14: lw          $a0, -0x7D4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D4C);
    after_3:
L_800B7E18:
    // 0x800B7E18: jal         0x800B8FE0
    // 0x800B7E1C: nop

    func_800B8FE0(rdram, ctx);
        goto after_4;
    // 0x800B7E1C: nop

    after_4:
    // 0x800B7E20: jal         0x800B90E8
    // 0x800B7E24: nop

    func_800B90E8(rdram, ctx);
        goto after_5;
    // 0x800B7E24: nop

    after_5:
    // 0x800B7E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7E30: jr          $ra
    // 0x800B7E34: nop

    return;
    // 0x800B7E34: nop

;}
RECOMP_FUNC void func_800F6140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6140: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F6144: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F6148: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F614C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F6150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F6154: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800F6158: addiu       $s0, $s0, 0x5490
    ctx->r16 = ADD32(ctx->r16, 0X5490);
    // 0x800F615C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800F6160: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800F6164:
    // 0x800F6164: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800F6168: bne         $t6, $zero, L_800F61C0
    if (ctx->r14 != 0) {
        // 0x800F616C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800F61C0;
    }
    // 0x800F616C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F6170: jal         0x800A907C
    // 0x800F6174: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_800A907C(rdram, ctx);
        goto after_0;
    // 0x800F6174: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_0:
    // 0x800F6178: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800F617C: jal         0x800A9768
    // 0x800F6180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A9768(rdram, ctx);
        goto after_1;
    // 0x800F6180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800F6184: jal         0x800A93F8
    // 0x800F6188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A93F8(rdram, ctx);
        goto after_2;
    // 0x800F6188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800F618C: jal         0x800A93E4
    // 0x800F6190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A93E4(rdram, ctx);
        goto after_3;
    // 0x800F6190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800F6194: jal         0x800F43A8
    // 0x800F6198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F43A8(rdram, ctx);
        goto after_4;
    // 0x800F6198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800F619C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F61A0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800F61A4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x800F61A8: sb          $zero, 0x54B0($at)
    MEM_B(0X54B0, ctx->r1) = 0;
    // 0x800F61AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800F61B0: jal         0x80091BF0
    // 0x800F61B4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    bakey_setControllerIndex(rdram, ctx);
        goto after_5;
    // 0x800F61B4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x800F61B8: b           L_800F61D0
    // 0x800F61BC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_800F61D0;
    // 0x800F61BC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_800F61C0:
    // 0x800F61C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800F61C4: bne         $s1, $v0, L_800F6164
    if (ctx->r17 != ctx->r2) {
        // 0x800F61C8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800F6164;
    }
    // 0x800F61C8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800F61CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F61D0:
    // 0x800F61D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F61D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F61D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F61DC: jr          $ra
    // 0x800F61E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F61E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void vpglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000EC: jal         0x8001B084
    // 0x808000F0: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x808000F0: nop

    after_0:
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_800EA090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA090: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA094: jr          $ra
    // 0x800EA098: lh          $v0, 0x2DC8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2DC8);
    return;
    // 0x800EA098: lh          $v0, 0x2DC8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2DC8);
;}
RECOMP_FUNC void bsjump_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800910: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800914: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(216, 0X1120) << 16);
    // 0x80800918: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080091C: jr          $ra
    // 0x80800920: lw          $v0, 0x1120($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(216, 0X1120));
    return;
    // 0x80800920: lw          $v0, 0x1120($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(216, 0X1120));
;}
RECOMP_FUNC void func_8009BF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BF8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BF90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BF94: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BF98: jal         0x800136E4
    // 0x8009BF9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x8009BF9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009BFA0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8009BFA4: lw          $t7, 0xDC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XDC);
    // 0x8009BFA8: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8009BFAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BFB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BFB4: jr          $ra
    // 0x8009BFB8: nop

    return;
    // 0x8009BFB8: nop

;}
RECOMP_FUNC void func_8009BB5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BB5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BB60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BB64: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BB68: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8009BB6C: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009BB70: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8009BB74: nop

    // 0x8009BB78: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8009BB7C: jal         0x8002DCA0
    // 0x8009BB80: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8009BB80: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8009BB84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BB88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BB8C: jr          $ra
    // 0x8009BB90: nop

    return;
    // 0x8009BB90: nop

;}
RECOMP_FUNC void chbouncycastle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1000, 0X930) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x930
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1000, 0X930));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x930
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1000, 0X930));
;}
RECOMP_FUNC void _ncba1p_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089430: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x80089430);
    return;
    // 0x80089434: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
