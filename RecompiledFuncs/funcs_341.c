#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void cadbfunc_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F08: jal         0x80800E80
    // 0x80800F0C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_80800E80_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800F0C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80800F10: bne         $v0, $zero, L_80800F20
    if (ctx->r2 != 0) {
        // 0x80800F14: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800F20;
    }
    // 0x80800F14: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800F18: b           L_80800F2C
    // 0x80800F1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F2C;
    // 0x80800F1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F20:
    // 0x80800F20: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800F24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800F28: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80800F2C:
    // 0x80800F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F34: jr          $ra
    // 0x80800F38: nop

    return;
    // 0x80800F38: nop

;}
RECOMP_FUNC void func_800FDC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDC28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FDC2C: addiu       $v0, $v0, 0x59C0
    ctx->r2 = ADD32(ctx->r2, 0X59C0);
    // 0x800FDC30: lbu         $t6, 0x40($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X40);
    // 0x800FDC34: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x800FDC38: beq         $a0, $t6, L_800FDC50
    if (ctx->r4 == ctx->r14) {
        // 0x800FDC3C: nop
    
            goto L_800FDC50;
    }
    // 0x800FDC3C: nop

    // 0x800FDC40: bne         $t7, $zero, L_800FDC50
    if (ctx->r15 != 0) {
        // 0x800FDC44: sb          $a0, 0x40($v0)
        MEM_B(0X40, ctx->r2) = ctx->r4;
            goto L_800FDC50;
    }
    // 0x800FDC44: sb          $a0, 0x40($v0)
    MEM_B(0X40, ctx->r2) = ctx->r4;
    // 0x800FDC48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800FDC4C: sb          $t8, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r24;
L_800FDC50:
    // 0x800FDC50: jr          $ra
    // 0x800FDC54: nop

    return;
    // 0x800FDC54: nop

;}
RECOMP_FUNC void func_8010203C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010203C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102044: jal         0x80102394
    // 0x80102048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80102394(rdram, ctx);
        goto after_0;
    // 0x80102048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010204C: bne         $v0, $zero, L_80102060
    if (ctx->r2 != 0) {
        // 0x80102050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80102060;
    }
    // 0x80102050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102054: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80102058: b           L_80102070
    // 0x8010205C: nop

        goto L_80102070;
    // 0x8010205C: nop

L_80102060:
    // 0x80102060: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80102064: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80102068: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8010206C: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
L_80102070:
    // 0x80102070: jr          $ra
    // 0x80102074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800136E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800136E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800136E8: lwc1        $f0, 0x16B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X16B8);
    // 0x800136EC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800136F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800136F4: nop

    // 0x800136F8: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800136FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80013700: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80013704: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80013708: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001370C: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80013710: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80013714: bc1f        L_80013720
    if (!c1cs) {
        // 0x80013718: nop
    
            goto L_80013720;
    }
    // 0x80013718: nop

    // 0x8001371C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_80013720:
    // 0x80013720: jr          $ra
    // 0x80013724: nop

    return;
    // 0x80013724: nop

;}
RECOMP_FUNC void _bsbeefly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082848: syscall     16
    recomp_syscall_handler(rdram, ctx, 0x80082848);
    return;
    // 0x8008284C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gclevel_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088240: syscall     676
    recomp_syscall_handler(rdram, ctx, 0x80088240);
    return;
    // 0x80088244: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800A06E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A06E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A06EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A06F0: jal         0x80092B80
    // 0x800A06F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80092B80(rdram, ctx);
        goto after_0;
    // 0x800A06F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A06F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A06FC: jal         0x800A0714
    // 0x800A0700: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A0714(rdram, ctx);
        goto after_1;
    // 0x800A0700: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800A0704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A070C: jr          $ra
    // 0x800A0710: nop

    return;
    // 0x800A0710: nop

;}
RECOMP_FUNC void func_80801238_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801238: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080123C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801240: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801244: jal         0x808001FC
    // 0x80801248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001FC_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80801248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080124C: lui         $a2, 0x3FB0
    ctx->r6 = S32(0X3FB0 << 16);
    // 0x80801250: ori         $a2, $a2, 0xA3D7
    ctx->r6 = ctx->r6 | 0XA3D7;
    // 0x80801254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801258: jal         0x8008CB3C
    // 0x8080125C: addiu       $a1, $zero, 0x1E5
    ctx->r5 = ADD32(0, 0X1E5);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080125C: addiu       $a1, $zero, 0x1E5
    ctx->r5 = ADD32(0, 0X1E5);
    after_1:
    // 0x80801260: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801264: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080126C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801270: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801274: jal         0x8009FFD8
    // 0x80801278: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801278: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8080127C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801280: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80801284: jal         0x8009C99C
    // 0x80801288: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80801288: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_3:
    // 0x8080128C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80801290: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801298: jal         0x8008C9BC
    // 0x8080129C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_4;
    // 0x8080129C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_4:
    // 0x808012A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(372, 0X1588) << 16);
    // 0x808012A4: lwc1        $f4, 0x1588($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(372, 0X1588));
    // 0x808012A8: lui         $a2, 0x4422
    ctx->r6 = S32(0X4422 << 16);
    // 0x808012AC: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x808012B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012B4: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x808012B8: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x808012BC: jal         0x8008C9F0
    // 0x808012C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_5;
    // 0x808012C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x808012C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012C8: jal         0x8008CA30
    // 0x808012CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_6;
    // 0x808012CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x808012D0: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x808012D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808012D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808012DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808012E0: jr          $ra
    // 0x808012E4: nop

    return;
    // 0x808012E4: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080168C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801690: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801694: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801698: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080169C: jal         0x80100094
    // 0x808016A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808016A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808016A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808016A8: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x808016AC: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x808016B0: beq         $t6, $zero, L_808016D0
    if (ctx->r14 == 0) {
        // 0x808016B4: nop
    
            goto L_808016D0;
    }
    // 0x808016B4: nop

    // 0x808016B8: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x808016BC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808016C0: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808016C4: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x808016C8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808016CC: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
L_808016D0:
    // 0x808016D0: jal         0x800DB9B0
    // 0x808016D4: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x808016D4: nop

    after_1:
    // 0x808016D8: beq         $v0, $zero, L_808016E8
    if (ctx->r2 == 0) {
        // 0x808016DC: nop
    
            goto L_808016E8;
    }
    // 0x808016DC: nop

    // 0x808016E0: b           L_808017CC
    // 0x808016E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808017CC;
    // 0x808016E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808016E8:
    // 0x808016E8: jal         0x801072A8
    // 0x808016EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801072A8(rdram, ctx);
        goto after_2;
    // 0x808016EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808016F0: beq         $v0, $zero, L_80801700
    if (ctx->r2 == 0) {
        // 0x808016F4: nop
    
            goto L_80801700;
    }
    // 0x808016F4: nop

    // 0x808016F8: b           L_808017CC
    // 0x808016FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808017CC;
    // 0x808016FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801700:
    // 0x80801700: jal         0x80802760
    // 0x80801704: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80802760_sucoaster(rdram, ctx);
        goto after_3;
    // 0x80801704: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80801708: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080170C: bne         $v0, $at, L_8080171C
    if (ctx->r2 != ctx->r1) {
        // 0x80801710: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080171C;
    }
    // 0x80801710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801714: b           L_808017CC
    // 0x80801718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808017CC;
    // 0x80801718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080171C:
    // 0x8080171C: jal         0x8080202C
    // 0x80801720: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8080202C_sucoaster(rdram, ctx);
        goto after_4;
    // 0x80801720: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801724: beq         $v0, $zero, L_808017C8
    if (ctx->r2 == 0) {
        // 0x80801728: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808017C8;
    }
    // 0x80801728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080172C: jal         0x80802594
    // 0x80801730: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80802594_sucoaster(rdram, ctx);
        goto after_5;
    // 0x80801730: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80801734: beq         $v0, $zero, L_80801750
    if (ctx->r2 == 0) {
        // 0x80801738: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801750;
    }
    // 0x80801738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080173C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801740: jal         0x80801004
    // 0x80801744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80801744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80801748: b           L_808017CC
    // 0x8080174C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808017CC;
    // 0x8080174C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80801750:
    // 0x80801750: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
    // 0x80801754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801758: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x8080175C: beq         $t3, $zero, L_8080176C
    if (ctx->r11 == 0) {
        // 0x80801760: nop
    
            goto L_8080176C;
    }
    // 0x80801760: nop

    // 0x80801764: b           L_808017CC
    // 0x80801768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808017CC;
    // 0x80801768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080176C:
    // 0x8080176C: jal         0x808015F8
    // 0x80801770: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808015F8_sucoaster(rdram, ctx);
        goto after_7;
    // 0x80801770: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80801774: beql        $v0, $zero, L_808017CC
    if (ctx->r2 == 0) {
        // 0x80801778: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808017CC;
    }
    goto skip_0;
    // 0x80801778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8080177C: jal         0x80089F00
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suchase_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801784: beql        $v0, $zero, L_808017CC
    if (ctx->r2 == 0) {
        // 0x80801788: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808017CC;
    }
    goto skip_1;
    // 0x80801788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8080178C: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
    // 0x80801790: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801798: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x8080179C: bne         $t5, $at, L_808017B0
    if (ctx->r13 != ctx->r1) {
        // 0x808017A0: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_808017B0;
    }
    // 0x808017A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808017A4: jal         0x80801004
    // 0x808017A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x808017A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808017AC: bne         $v0, $zero, L_808017C0
    if (ctx->r2 != 0) {
        // 0x808017B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808017C0;
    }
L_808017B0:
    // 0x808017B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808017B8: jal         0x80801004
    // 0x808017BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x808017BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
L_808017C0:
    // 0x808017C0: b           L_808017CC
    // 0x808017C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808017CC;
    // 0x808017C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808017C8:
    // 0x808017C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808017CC:
    // 0x808017CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808017D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808017D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808017D8: jr          $ra
    // 0x808017DC: nop

    return;
    // 0x808017DC: nop

;}
RECOMP_FUNC void _chonearmbandit_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D10: syscall     229
    recomp_syscall_handler(rdram, ctx, 0x80085D10);
    return;
    // 0x80085D14: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8001A148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A150: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001A154: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001A158: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001A15C: jal         0x8001A0F0
    // 0x8001A160: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001A0F0(rdram, ctx);
        goto after_0;
    // 0x8001A160: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001A164: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A168: addiu       $v1, $v1, -0x4128
    ctx->r3 = ADD32(ctx->r3, -0X4128);
    // 0x8001A16C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8001A170: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8001A174: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001A178: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8001A17C: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8001A180: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001A184: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8001A188: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001A18C: addiu       $t7, $t7, -0x4308
    ctx->r15 = ADD32(ctx->r15, -0X4308);
    // 0x8001A190: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A194: mfhi        $t9
    ctx->r25 = hi;
    // 0x8001A198: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x8001A19C: jal         0x8001A11C
    // 0x8001A1A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8001A11C(rdram, ctx);
        goto after_1;
    // 0x8001A1A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8001A1A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A1A8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8001A1AC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001A1B0: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x8001A1B4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8001A1B8: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x8001A1BC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A1C0: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    // 0x8001A1C4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A1C8: jal         0x80013D10
    // 0x8001A1CC: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
    func_80013D10(rdram, ctx);
        goto after_2;
    // 0x8001A1CC: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
    after_2:
    // 0x8001A1D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A1D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001A1D8: jr          $ra
    // 0x8001A1DC: nop

    return;
    // 0x8001A1DC: nop

;}
RECOMP_FUNC void func_8080040C_chjigsawbitcont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800414: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800418: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080041C: jal         0x80106790
    // 0x80800420: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800420: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80800424: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080042C: jal         0x80100094
    // 0x80800430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800434: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800438: lh          $t7, 0x24($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X24);
    // 0x8080043C: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1644, 0X9B6) << 16);
    // 0x80800440: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80800444: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80800448: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x8080044C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80800450: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x80800454: lw          $t4, 0x6C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X6C);
    // 0x80800458: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8080045C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80800460: lh          $t2, 0x9B6($t2)
    ctx->r10 = MEM_H(ctx->r10, (int16_t)RELOC_LO16(1644, 0X9B6));
    // 0x80800464: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x80800468: jal         0x800DA544
    // 0x8080046C: addu        $a0, $t2, $t5
    ctx->r4 = ADD32(ctx->r10, ctx->r13);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x8080046C: addu        $a0, $t2, $t5
    ctx->r4 = ADD32(ctx->r10, ctx->r13);
    after_2:
    // 0x80800470: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
    // 0x80800474: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800478: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1644, 0X9A8) << 16);
    // 0x8080047C: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80800480: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800484: addiu       $t0, $t0, 0x9A8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1644, 0X9A8));
    // 0x80800488: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8080048C: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x80800490: lh          $a1, 0x24($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X24);
    // 0x80800494: bnel        $a1, $v0, L_808004C8
    if (ctx->r5 != ctx->r2) {
        // 0x80800498: lw          $t1, 0x64($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X64);
            goto L_808004C8;
    }
    goto skip_0;
    // 0x80800498: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x8080049C: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x808004A0: jal         0x800D0BD4
    // 0x808004A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0BD4(rdram, ctx);
        goto after_3;
    // 0x808004A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808004A8: jal         0x800FC660
    // 0x808004AC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x808004AC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_4:
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: jal         0x80108B04
    // 0x808004B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x808004B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_5:
    // 0x808004BC: b           L_80800554
    // 0x808004C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800554;
    // 0x808004C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004C4: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
L_808004C8:
    // 0x808004C8: sll         $t4, $t1, 11
    ctx->r12 = S32(ctx->r9 << 11);
    // 0x808004CC: bltzl       $t4, L_8080050C
    if (SIGNED(ctx->r12) < 0) {
        // 0x808004D0: mtc1        $v0, $f8
        ctx->f8.u32l = ctx->r2;
            goto L_8080050C;
    }
    goto skip_1;
    // 0x808004D0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    skip_1:
    // 0x808004D4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x808004D8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x808004DC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x808004E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808004E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808004E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808004EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808004F0: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808004F4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808004F8: jal         0x800FC660
    // 0x808004FC: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    func_800FC660(rdram, ctx);
        goto after_6;
    // 0x808004FC: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    after_6:
    // 0x80800500: b           L_80800548
    // 0x80800504: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
        goto L_80800548;
    // 0x80800504: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80800508: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
L_8080050C:
    // 0x8080050C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800510: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800514: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800518: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8080051C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800520: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800524: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800528: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    // 0x8080052C: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800530: addiu       $a2, $zero, 0x1F40
    ctx->r6 = ADD32(0, 0X1F40);
    // 0x80800534: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800538: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8080053C: jal         0x800FCAE0
    // 0x80800540: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    func_800FCAE0(rdram, ctx);
        goto after_7;
    // 0x80800540: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    after_7:
    // 0x80800544: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
L_80800548:
    // 0x80800548: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8080054C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x80800550: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800554:
    // 0x80800554: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800558: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080055C: jr          $ra
    // 0x80800560: nop

    return;
    // 0x80800560: nop

;}
RECOMP_FUNC void func_808013E8_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013E8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808013EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808013F0: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x808013F4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808013F8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x808013FC: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80801400: jal         0x80100094
    // 0x80801404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801408: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1700, 0X2588) << 16);
    // 0x8080140C: addiu       $t7, $t7, 0x2588
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1700, 0X2588));
    // 0x80801410: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80801414: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x80801418: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8080141C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80801420: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80801424: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1700, 0X2594) << 16);
    // 0x80801428: addiu       $t2, $t2, 0x2594
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1700, 0X2594));
    // 0x8080142C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80801430: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80801434: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80801438: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // 0x8080143C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80801440: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80801444: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80801448: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080144C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801450: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80801454: jal         0x8010D254
    // 0x80801458: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80801458: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    after_1:
    // 0x8080145C: lui         $a2, 0xC428
    ctx->r6 = S32(0XC428 << 16);
    // 0x80801460: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x80801464: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80801468: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080146C: jal         0x800EFA4C
    // 0x80801470: lui         $a3, 0xC31B
    ctx->r7 = S32(0XC31B << 16);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80801470: lui         $a3, 0xC31B
    ctx->r7 = S32(0XC31B << 16);
    after_2:
    // 0x80801474: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80801478: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8080147C: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80801480: addiu       $t8, $sp, 0x58
    ctx->r24 = ADD32(ctx->r29, 0X58);
    // 0x80801484: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80801488: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080148C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801490: lui         $a1, 0x442F
    ctx->r5 = S32(0X442F << 16);
    // 0x80801494: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80801498: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080149C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x808014A0: jal         0x80089870
    // 0x808014A4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808014A4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_3:
    // 0x808014A8: jal         0x800EFD24
    // 0x808014AC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x808014AC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_4:
    // 0x808014B0: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x808014B4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x808014B8: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x808014BC: addiu       $t4, $sp, 0x58
    ctx->r12 = ADD32(ctx->r29, 0X58);
    // 0x808014C0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808014C4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808014C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014CC: lui         $a1, 0x4461
    ctx->r5 = S32(0X4461 << 16);
    // 0x808014D0: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x808014D4: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x808014D8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x808014DC: jal         0x80089870
    // 0x808014E0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x808014E0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_5:
    // 0x808014E4: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x808014E8: lui         $a1, 0x4320
    ctx->r5 = S32(0X4320 << 16);
    // 0x808014EC: lui         $a2, 0xC316
    ctx->r6 = S32(0XC316 << 16);
    // 0x808014F0: jal         0x800EFA4C
    // 0x808014F4: lui         $a3, 0x4382
    ctx->r7 = S32(0X4382 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x808014F4: lui         $a3, 0x4382
    ctx->r7 = S32(0X4382 << 16);
    after_6:
    // 0x808014F8: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x808014FC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80801500: lui         $a1, 0x443B
    ctx->r5 = S32(0X443B << 16);
    // 0x80801504: addiu       $t2, $zero, 0x37
    ctx->r10 = ADD32(0, 0X37);
    // 0x80801508: addiu       $t5, $sp, 0x58
    ctx->r13 = ADD32(ctx->r29, 0X58);
    // 0x8080150C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801510: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801514: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80801518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080151C: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    // 0x80801520: addiu       $a3, $zero, 0x2D
    ctx->r7 = ADD32(0, 0X2D);
    // 0x80801524: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80801528: jal         0x80089870
    // 0x8080152C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x8080152C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_7:
    // 0x80801530: lui         $a2, 0x4422
    ctx->r6 = S32(0X4422 << 16);
    // 0x80801534: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80801538: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8080153C: lui         $a1, 0x4320
    ctx->r5 = S32(0X4320 << 16);
    // 0x80801540: jal         0x800EFA4C
    // 0x80801544: lui         $a3, 0x436B
    ctx->r7 = S32(0X436B << 16);
    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x80801544: lui         $a3, 0x436B
    ctx->r7 = S32(0X436B << 16);
    after_8:
    // 0x80801548: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8080154C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80801550: lui         $a1, 0x4389
    ctx->r5 = S32(0X4389 << 16);
    // 0x80801554: addiu       $t6, $zero, 0x41
    ctx->r14 = ADD32(0, 0X41);
    // 0x80801558: addiu       $t7, $sp, 0x58
    ctx->r15 = ADD32(ctx->r29, 0X58);
    // 0x8080155C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801560: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801564: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080156C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80801570: addiu       $a3, $zero, 0x37
    ctx->r7 = ADD32(0, 0X37);
    // 0x80801574: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80801578: jal         0x80089870
    // 0x8080157C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x8080157C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_9:
    // 0x80801580: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80801584: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801588: lhu         $v0, 0x72($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X72);
    // 0x8080158C: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80801590: beq         $t3, $at, L_808015A8
    if (ctx->r11 == ctx->r1) {
        // 0x80801594: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808015A8;
    }
    // 0x80801594: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801598: beq         $t3, $at, L_808015E8
    if (ctx->r11 == ctx->r1) {
        // 0x8080159C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808015E8;
    }
    // 0x8080159C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808015A0: b           L_80801638
    // 0x808015A4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
        goto L_80801638;
    // 0x808015A4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_808015A8:
    // 0x808015A8: jal         0x80089918
    // 0x808015AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_10;
    // 0x808015AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808015B0: beq         $v0, $zero, L_808015E0
    if (ctx->r2 == 0) {
        // 0x808015B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015E0;
    }
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015B8: lui         $a1, 0x4093
    ctx->r5 = S32(0X4093 << 16);
    // 0x808015BC: jal         0x80089868
    // 0x808015C0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_11;
    // 0x808015C0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_11:
    // 0x808015C4: beq         $v0, $zero, L_808015E0
    if (ctx->r2 == 0) {
        // 0x808015C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015E0;
    }
    // 0x808015C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015CC: jal         0x800898D0
    // 0x808015D0: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _sumumbofx_entrypoint_18(rdram, ctx);
        goto after_12;
    // 0x808015D0: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_12:
    // 0x808015D4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808015D8: jal         0x808017D4
    // 0x808015DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_13;
    // 0x808015DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
L_808015E0:
    // 0x808015E0: b           L_80801634
    // 0x808015E4: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
        goto L_80801634;
    // 0x808015E4: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
L_808015E8:
    // 0x808015E8: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808015EC: jal         0x80101E14
    // 0x808015F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x808015F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_14:
    // 0x808015F4: beq         $v0, $zero, L_80801604
    if (ctx->r2 == 0) {
        // 0x808015F8: nop
    
            goto L_80801604;
    }
    // 0x808015F8: nop

    // 0x808015FC: jal         0x80086AF0
    // 0x80801600: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x80801600: nop

    after_15:
L_80801604:
    // 0x80801604: jal         0x80101DDC
    // 0x80801608: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x80801608: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_16:
    // 0x8080160C: beq         $v0, $zero, L_80801630
    if (ctx->r2 == 0) {
        // 0x80801610: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801630;
    }
    // 0x80801610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801614: jal         0x800898C0
    // 0x80801618: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_17;
    // 0x80801618: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_17:
    // 0x8080161C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80801620: jal         0x808017D4
    // 0x80801624: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_18;
    // 0x80801624: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
    // 0x80801628: jal         0x80090708
    // 0x8080162C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_19;
    // 0x8080162C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
L_80801630:
    // 0x80801630: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
L_80801634:
    // 0x80801634: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_80801638:
    // 0x80801638: jal         0x800EE7F8
    // 0x8080163C: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_20;
    // 0x8080163C: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    after_20:
    // 0x80801640: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80801644: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801648: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080164C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801650: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80801654: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801658: jal         0x80089898
    // 0x8080165C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    _sumumbofx_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x8080165C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_21:
    // 0x80801660: jal         0x800898B0
    // 0x80801664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_22;
    // 0x80801664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80801668: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080166C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801670: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80801674: jr          $ra
    // 0x80801678: nop

    return;
    // 0x80801678: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D40: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D40);
    return;
    // 0x80082D44: addi        $t0, $zero, 0xC0
    ctx->r8 = ADD32(0, 0XC0);
;}
RECOMP_FUNC void ncba1p_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080052C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800534: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800538: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080053C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800540: sw          $t6, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->r14;
    // 0x80800544: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80800548: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8080054C: jal         0x80800564
    // 0x80800550: sb          $zero, 0x50($t8)
    MEM_B(0X50, ctx->r24) = 0;
    ncba1p_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800550: sb          $zero, 0x50($t8)
    MEM_B(0X50, ctx->r24) = 0;
    after_0:
    // 0x80800554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800558: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080055C: jr          $ra
    // 0x80800560: nop

    return;
    // 0x80800560: nop

;}
RECOMP_FUNC void func_808007B4_cheggclockwork(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007BC: jal         0x80100094
    // 0x808007C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007C4: jal         0x8001B754
    // 0x808007C8: lh          $a0, 0x2C($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2C);
    func_8001B754(rdram, ctx);
        goto after_1;
    // 0x808007C8: lh          $a0, 0x2C($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2C);
    after_1:
    // 0x808007CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007D4: jr          $ra
    // 0x808007D8: nop

    return;
    // 0x808007D8: nop

;}
RECOMP_FUNC void _bsdronefired_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830C8: syscall     42
    recomp_syscall_handler(rdram, ctx, 0x800830C8);
    return;
    // 0x800830CC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80012BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012BB4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80012BB8: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80012BBC: addiu       $t0, $t0, -0x65D0
    ctx->r8 = ADD32(ctx->r8, -0X65D0);
    // 0x80012BC0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80012BC4: lw          $s1, 0x4($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X4);
    // 0x80012BC8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80012BCC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80012BD0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80012BD4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80012BD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80012BDC: beq         $s1, $zero, L_80012C34
    if (ctx->r17 == 0) {
        // 0x80012BE0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80012C34;
    }
    // 0x80012BE0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80012BE4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_80012BE8:
    // 0x80012BE8: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x80012BEC: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80012BF0: bne         $at, $zero, L_80012C34
    if (ctx->r1 != 0) {
        // 0x80012BF4: addiu       $v1, $v0, 0x200
        ctx->r3 = ADD32(ctx->r2, 0X200);
            goto L_80012C34;
    }
    // 0x80012BF4: addiu       $v1, $v0, 0x200
    ctx->r3 = ADD32(ctx->r2, 0X200);
    // 0x80012BF8: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80012BFC: bne         $at, $zero, L_80012C28
    if (ctx->r1 != 0) {
        // 0x80012C00: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_80012C28;
    }
    // 0x80012C00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80012C04: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x80012C08: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80012C0C: lw          $t7, -0x5EB8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5EB8);
    // 0x80012C10: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x80012C14: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
    // 0x80012C18: jal         0x8002E330
    // 0x80012C1C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80012C1C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    after_0:
    // 0x80012C20: b           L_80012D3C
    // 0x80012C24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80012D3C;
    // 0x80012C24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80012C28:
    // 0x80012C28: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80012C2C: bnel        $s0, $zero, L_80012BE8
    if (ctx->r16 != 0) {
        // 0x80012C30: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80012BE8;
    }
    goto skip_0;
    // 0x80012C30: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_0:
L_80012C34:
    // 0x80012C34: lw          $s0, 0x8($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X8);
    // 0x80012C38: bne         $s0, $zero, L_80012C50
    if (ctx->r16 != 0) {
        // 0x80012C3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80012C50;
    }
    // 0x80012C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80012C40: jal         0x8002E330
    // 0x80012C44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80012C44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80012C48: b           L_80012D3C
    // 0x80012C4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80012D3C;
    // 0x80012C4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80012C50:
    // 0x80012C50: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80012C54: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80012C58: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80012C5C: jal         0x80020E74
    // 0x80012C60: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    func_80020E74(rdram, ctx);
        goto after_2;
    // 0x80012C60: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    after_2:
    // 0x80012C64: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80012C68: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80012C6C: addiu       $t0, $t0, -0x65D0
    ctx->r8 = ADD32(ctx->r8, -0X65D0);
    // 0x80012C70: beq         $a2, $zero, L_80012C90
    if (ctx->r6 == 0) {
        // 0x80012C74: lw          $a3, 0x48($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X48);
            goto L_80012C90;
    }
    // 0x80012C74: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80012C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80012C7C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80012C80: jal         0x80020E40
    // 0x80012C84: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    func_80020E40(rdram, ctx);
        goto after_3;
    // 0x80012C84: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    after_3:
    // 0x80012C88: b           L_80012CBC
    // 0x80012C8C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
        goto L_80012CBC;
    // 0x80012C8C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
L_80012C90:
    // 0x80012C90: lw          $s1, 0x4($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X4);
    // 0x80012C94: beql        $s1, $zero, L_80012CB4
    if (ctx->r17 == 0) {
        // 0x80012C98: sw          $s0, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r16;
            goto L_80012CB4;
    }
    goto skip_1;
    // 0x80012C98: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
    skip_1:
    // 0x80012C9C: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
    // 0x80012CA0: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // 0x80012CA4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80012CA8: b           L_80012CBC
    // 0x80012CAC: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
        goto L_80012CBC;
    // 0x80012CAC: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    // 0x80012CB0: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
L_80012CB4:
    // 0x80012CB4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80012CB8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80012CBC:
    // 0x80012CBC: andi        $s1, $a3, 0x1
    ctx->r17 = ctx->r7 & 0X1;
    // 0x80012CC0: subu        $a3, $a3, $s1
    ctx->r7 = SUB32(ctx->r7, ctx->r17);
    // 0x80012CC4: sw          $a3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r7;
    // 0x80012CC8: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x80012CCC: lw          $t3, -0x5EB8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5EB8);
    // 0x80012CD0: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x80012CD4: addiu       $t1, $t1, -0x5EB4
    ctx->r9 = ADD32(ctx->r9, -0X5EB4);
    // 0x80012CD8: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    // 0x80012CDC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80012CE0: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x80012CE4: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80012CE8: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80012CEC: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80012CF0: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80012CF4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80012CF8: addiu       $t7, $t7, -0x6B78
    ctx->r15 = ADD32(ctx->r15, -0X6B78);
    // 0x80012CFC: addiu       $t5, $t5, -0x6A80
    ctx->r13 = ADD32(ctx->r13, -0X6A80);
    // 0x80012D00: addiu       $t6, $zero, 0x200
    ctx->r14 = ADD32(0, 0X200);
    // 0x80012D04: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80012D08: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80012D0C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80012D10: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80012D14: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80012D18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80012D1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80012D20: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80012D24: jal         0x8002E450
    // 0x80012D28: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    osPiStartDma_recomp(rdram, ctx);
        goto after_4;
    // 0x80012D28: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_4:
    // 0x80012D2C: jal         0x8002E330
    // 0x80012D30: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x80012D30: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x80012D34: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80012D38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80012D3C:
    // 0x80012D3C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80012D40: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80012D44: jr          $ra
    // 0x80012D48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80012D48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800A9EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9EC0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9EC4: lui         $t6, 0x3
    ctx->r14 = S32(0X3 << 16);
    // 0x800A9EC8: addiu       $a1, $a1, 0x7770
    ctx->r5 = ADD32(ctx->r5, 0X7770);
    // 0x800A9ECC: ori         $t6, $t6, 0xE800
    ctx->r14 = ctx->r14 | 0XE800;
    // 0x800A9ED0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A9ED4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9ED8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800A9EDC: addiu       $v0, $v0, -0x5B68
    ctx->r2 = ADD32(ctx->r2, -0X5B68);
    // 0x800A9EE0: addiu       $v1, $v1, -0x5B80
    ctx->r3 = ADD32(ctx->r3, -0X5B80);
    // 0x800A9EE4: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_800A9EE8:
    // 0x800A9EE8: bnel        $a0, $t7, L_800A9F04
    if (ctx->r4 != ctx->r15) {
        // 0x800A9EEC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A9F04;
    }
    goto skip_0;
    // 0x800A9EEC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x800A9EF0: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x800A9EF4: sll         $t9, $t8, 10
    ctx->r25 = S32(ctx->r24 << 10);
    // 0x800A9EF8: jr          $ra
    // 0x800A9EFC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    return;
    // 0x800A9EFC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800A9F00: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800A9F04:
    // 0x800A9F04: bnel        $v1, $v0, L_800A9EE8
    if (ctx->r3 != ctx->r2) {
        // 0x800A9F08: lh          $t7, 0x0($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X0);
            goto L_800A9EE8;
    }
    goto skip_1;
    // 0x800A9F08: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    skip_1:
    // 0x800A9F0C: jr          $ra
    // 0x800A9F10: nop

    return;
    // 0x800A9F10: nop

;}
RECOMP_FUNC void bsmumsplat_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(324, 0X1E0) << 16);
    // 0x808001D4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808001D8: jr          $ra
    // 0x808001DC: lw          $v0, 0x1E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(324, 0X1E0));
    return;
    // 0x808001DC: lw          $v0, 0x1E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(324, 0X1E0));
;}
RECOMP_FUNC void _babounce_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845F0: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x800845F0);
    return;
    // 0x800845F4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800234_chbottlesparty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800234: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800238: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080023C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800240: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800244: jal         0x800DA298
    // 0x80800248: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800248: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_0:
    // 0x8080024C: beq         $v0, $zero, L_80800264
    if (ctx->r2 == 0) {
        // 0x80800250: nop
    
            goto L_80800264;
    }
    // 0x80800250: nop

    // 0x80800254: jal         0x800DA298
    // 0x80800258: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800258: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_1:
    // 0x8080025C: beq         $v0, $zero, L_80800274
    if (ctx->r2 == 0) {
        // 0x80800260: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1508, 0X400) << 16);
            goto L_80800274;
    }
    // 0x80800260: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1508, 0X400) << 16);
L_80800264:
    // 0x80800264: jal         0x800FFAB0
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080026C: b           L_80800320
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800320;
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800274:
    // 0x80800274: lwc1        $f12, 0x400($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1508, 0X400));
    // 0x80800278: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1508, 0X404) << 16);
    // 0x8080027C: jal         0x800DC178
    // 0x80800280: lwc1        $f14, 0x404($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1508, 0X404));
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800280: lwc1        $f14, 0x404($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1508, 0X404));
    after_3:
    // 0x80800284: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800288: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8080028C: jal         0x800DC178
    // 0x80800290: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800290: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_4:
    // 0x80800294: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800298: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080029C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x808002A0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808002A4: addiu       $t9, $t7, -0x32
    ctx->r25 = ADD32(ctx->r15, -0X32);
    // 0x808002A8: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x808002AC: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x808002B0: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x808002B4: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
    // 0x808002B8: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
    // 0x808002BC: andi        $t7, $t3, 0xFE00
    ctx->r15 = ctx->r11 & 0XFE00;
    // 0x808002C0: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x808002C4: sltiu       $at, $t5, 0x5
    ctx->r1 = ctx->r13 < 0X5 ? 1 : 0;
    // 0x808002C8: bne         $at, $zero, L_808002D4
    if (ctx->r1 != 0) {
        // 0x808002CC: nop
    
            goto L_808002D4;
    }
    // 0x808002CC: nop

    // 0x808002D0: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
L_808002D4:
    // 0x808002D4: jal         0x800C8A98
    // 0x808002D8: nop

    func_800C8A98(rdram, ctx);
        goto after_5;
    // 0x808002D8: nop

    after_5:
    // 0x808002DC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808002E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002E4: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808002E8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808002EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002F0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808002F4: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x808002F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002FC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800300: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800304: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800308: jal         0x800C8E54
    // 0x8080030C: nop

    func_800C8E54(rdram, ctx);
        goto after_6;
    // 0x8080030C: nop

    after_6:
    // 0x80800310: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80800314: jal         0x800C8CB8
    // 0x80800318: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_7;
    // 0x80800318: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x8080031C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800320:
    // 0x80800320: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void batimer_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: lw          $t6, 0x13C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13C);
    // 0x808002E0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808002E4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x808002E8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x808002EC: swc1        $f12, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f12.u32l;
    // 0x808002F0: lw          $t8, 0x13C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X13C);
    // 0x808002F4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x808002F8: jr          $ra
    // 0x808002FC: swc1        $f12, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f12.u32l;
    return;
    // 0x808002FC: swc1        $f12, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bsjig_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831E0: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x800831E0);
    return;
    // 0x800831E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800E9DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9DDC: jal         0x800BE5C4
    // 0x800E9DE0: nop

    func_800BE5C4(rdram, ctx);
        goto after_0;
    // 0x800E9DE0: nop

    after_0:
    // 0x800E9DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9DE8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800E9DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9DF0: jr          $ra
    // 0x800E9DF4: nop

    return;
    // 0x800E9DF4: nop

;}
RECOMP_FUNC void func_80800264_chsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800268: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8080026C: jr          $ra
    // 0x80800270: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80800270: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void func_80093738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009373C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093740: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093744: jal         0x800D674C
    // 0x80093748: lh          $a0, 0x9C($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X9C);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80093748: lh          $a0, 0x9C($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X9C);
    after_0:
    // 0x8009374C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80093750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80093754: jr          $ra
    // 0x80093758: nop

    return;
    // 0x80093758: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D00: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D00);
    return;
    // 0x80087D04: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_800FFA3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFA3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FFA40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFA44: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800FFA48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FFA4C: jal         0x800FF3EC
    // 0x800FFA50: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800FF3EC(rdram, ctx);
        goto after_0;
    // 0x800FFA50: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800FFA54: jal         0x800FF4A4
    // 0x800FFA58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FF4A4(rdram, ctx);
        goto after_1;
    // 0x800FFA58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800FFA5C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFA60: lhu         $a0, 0x1A($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X1A);
    // 0x800FFA64: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x800FFA68: jal         0x801066C0
    // 0x800FFA6C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_801066C0(rdram, ctx);
        goto after_2;
    // 0x800FFA6C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x800FFA70: jal         0x800EBFF4
    // 0x800FFA74: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EBFF4(rdram, ctx);
        goto after_3;
    // 0x800FFA74: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x800FFA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFA7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FFA80: jr          $ra
    // 0x800FFA84: nop

    return;
    // 0x800FFA84: nop

;}
RECOMP_FUNC void _bscrashout_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F38: syscall     35
    recomp_syscall_handler(rdram, ctx, 0x80082F38);
    return;
    // 0x80082F3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808005A4_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A4: beq         $a1, $zero, L_808005C8
    if (ctx->r5 == 0) {
        // 0x808005A8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1852, 0X4FF0) << 16);
            goto L_808005C8;
    }
    // 0x808005A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X4FF0) << 16);
    // 0x808005AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005B0: beq         $a1, $at, L_808005EC
    if (ctx->r5 == ctx->r1) {
        // 0x808005B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808005EC;
    }
    // 0x808005B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005B8: beql        $a1, $at, L_80800618
    if (ctx->r5 == ctx->r1) {
        // 0x808005BC: lui         $at, 0x457A
        ctx->r1 = S32(0X457A << 16);
            goto L_80800618;
    }
    goto skip_0;
    // 0x808005BC: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    skip_0:
    // 0x808005C0: jr          $ra
    // 0x808005C4: nop

    return;
    // 0x808005C4: nop

L_808005C8:
    // 0x808005C8: lwc1        $f4, 0x4FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X4FF0));
    // 0x808005CC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x808005D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005D4: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x808005D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005DC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x808005E0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x808005E4: jr          $ra
    // 0x808005E8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x808005E8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
L_808005EC:
    // 0x808005EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X4FF4) << 16);
    // 0x808005F0: lwc1        $f10, 0x4FF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X4FF4));
    // 0x808005F4: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x808005F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X4FF8) << 16);
    // 0x80800600: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80800604: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80800608: lwc1        $f18, 0x4FF8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X4FF8));
    // 0x8080060C: jr          $ra
    // 0x80800610: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80800610: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x80800614: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
L_80800618:
    // 0x80800618: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080061C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800620: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800624: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800628: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8080062C: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80800630: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80800634: jr          $ra
    // 0x80800638: nop

    return;
    // 0x80800638: nop

;}
RECOMP_FUNC void func_80015190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80015194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015198: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001519C: addiu       $a0, $a0, -0x6FF0
    ctx->r4 = ADD32(ctx->r4, -0X6FF0);
    // 0x800151A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800151A4: jal         0x8002EAD0
    // 0x800151A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800151A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800151AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800151B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800151B4: jr          $ra
    // 0x800151B8: nop

    return;
    // 0x800151B8: nop

;}
RECOMP_FUNC void func_80800398_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080039C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003A0: beq         $a1, $zero, L_808003E0
    if (ctx->r5 == 0) {
        // 0x808003A4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_808003E0;
    }
    // 0x808003A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808003A8: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x808003AC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808003B0: bltzl       $t8, L_80800414
    if (SIGNED(ctx->r24) < 0) {
        // 0x808003B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800414;
    }
    goto skip_0;
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808003B8: jal         0x800F54E4
    // 0x808003BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808003BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003C4: jal         0x800F4CEC
    // 0x808003C8: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    func_800F4CEC(rdram, ctx);
        goto after_1;
    // 0x808003C8: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_1:
    // 0x808003CC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808003D0: lbu         $t0, 0x74($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X74);
    // 0x808003D4: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x808003D8: b           L_80800410
    // 0x808003DC: sb          $t1, 0x74($a2)
    MEM_B(0X74, ctx->r6) = ctx->r9;
        goto L_80800410;
    // 0x808003DC: sb          $t1, 0x74($a2)
    MEM_B(0X74, ctx->r6) = ctx->r9;
L_808003E0:
    // 0x808003E0: lw          $t2, 0x74($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X74);
    // 0x808003E4: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x808003E8: bgezl       $t4, L_80800414
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808003EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800414;
    }
    goto skip_1;
    // 0x808003EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808003F0: jal         0x800F54E4
    // 0x808003F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808003F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x808003F8: jal         0x800F4CC0
    // 0x808003FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_3;
    // 0x808003FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800400: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800404: lbu         $t5, 0x74($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X74);
    // 0x80800408: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x8080040C: sb          $t6, 0x74($a2)
    MEM_B(0X74, ctx->r6) = ctx->r14;
L_80800410:
    // 0x80800410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800414:
    // 0x80800414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800418: jr          $ra
    // 0x8080041C: nop

    return;
    // 0x8080041C: nop

;}
RECOMP_FUNC void func_80105BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105BAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105BB4: jal         0x80105494
    // 0x80105BB8: nop

    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80105BB8: nop

    after_0:
    // 0x80105BBC: beql        $v0, $zero, L_80105BD4
    if (ctx->r2 == 0) {
        // 0x80105BC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105BD4;
    }
    goto skip_0;
    // 0x80105BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80105BC4: lbu         $t7, 0x18($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18);
    // 0x80105BC8: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80105BCC: sb          $t8, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r24;
    // 0x80105BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80105BD4:
    // 0x80105BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105BD8: jr          $ra
    // 0x80105BDC: nop

    return;
    // 0x80105BDC: nop

;}
RECOMP_FUNC void _ncbapivot_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089480: syscall     781
    recomp_syscall_handler(rdram, ctx, 0x80089480);
    return;
    // 0x80089484: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bsbeemain_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082880: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x80082880);
    return;
    // 0x80082884: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800F7C_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F88: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800F8C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800F90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F94: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800F98: nop

    // 0x80800F9C: bc1fl       L_80800FB0
    if (!c1cs) {
        // 0x80800FA0: lw          $t6, 0x64($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X64);
            goto L_80800FB0;
    }
    goto skip_0;
    // 0x80800FA0: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80800FA4: b           L_80801040
    // 0x80800FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801040;
    // 0x80800FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800FAC: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
L_80800FB0:
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FB8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800FBC: bgez        $t8, L_80800FF4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800FC0: nop
    
            goto L_80800FF4;
    }
    // 0x80800FC0: nop

    // 0x80800FC4: jal         0x80089BF0
    // 0x80800FC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800FC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800FCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X11D4) << 16);
    // 0x80800FD0: lwc1        $f8, 0x11D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11D4));
    // 0x80800FD4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800FD8: nop

    // 0x80800FDC: bc1f        L_80800FEC
    if (!c1cs) {
        // 0x80800FE0: nop
    
            goto L_80800FEC;
    }
    // 0x80800FE0: nop

    // 0x80800FE4: b           L_80801040
    // 0x80800FE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801040;
    // 0x80800FE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FEC:
    // 0x80800FEC: b           L_80801040
    // 0x80800FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801040;
    // 0x80800FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800FF4:
    // 0x80800FF4: jal         0x80089F78
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800FFC: beq         $v0, $zero, L_8080103C
    if (ctx->r2 == 0) {
        // 0x80801000: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080103C;
    }
    // 0x80801000: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801004: jal         0x8010C9B0
    // 0x80801008: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    func_8010C9B0(rdram, ctx);
        goto after_2;
    // 0x80801008: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_2:
    // 0x8080100C: beql        $v0, $zero, L_80801040
    if (ctx->r2 == 0) {
        // 0x80801010: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801040;
    }
    goto skip_1;
    // 0x80801010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80801014: jal         0x80089F00
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suchase_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080101C: beql        $v0, $zero, L_80801040
    if (ctx->r2 == 0) {
        // 0x80801020: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801040;
    }
    goto skip_2;
    // 0x80801020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80801024: jal         0x8010C500
    // 0x80801028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_4;
    // 0x80801028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080102C: beql        $v0, $zero, L_80801040
    if (ctx->r2 == 0) {
        // 0x80801030: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801040;
    }
    goto skip_3;
    // 0x80801030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80801034: b           L_80801040
    // 0x80801038: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801040;
    // 0x80801038: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080103C:
    // 0x8080103C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801040:
    // 0x80801040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801044: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801048: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080104C: jr          $ra
    // 0x80801050: nop

    return;
    // 0x80801050: nop

;}
RECOMP_FUNC void func_80800148_bskazwingwhack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080014C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800150: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800154: jal         0x800832E0
    // 0x80800158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: addiu       $a1, $zero, 0x138
    ctx->r5 = ADD32(0, 0X138);
    // 0x80800164: jal         0x8008CCBC
    // 0x80800168: lui         $a2, 0x3FA0
    ctx->r6 = S32(0X3FA0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80800168: lui         $a2, 0x3FA0
    ctx->r6 = S32(0X3FA0 << 16);
    after_1:
    // 0x8080016C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800170: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080017C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800180: jal         0x8009FFD8
    // 0x80800184: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800184: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x80800190: jal         0x8009C99C
    // 0x80800194: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80800194: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    after_3:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x80095760
    // 0x808001A0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    baflag_set(rdram, ctx);
        goto after_4;
    // 0x808001A0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_4:
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x80095760
    // 0x808001AC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_set(rdram, ctx);
        goto after_5;
    // 0x808001AC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x808001B0: jal         0x8009BB5C
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_6;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001B8: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x808001BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001C0: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x808001C4: jal         0x800F13F0
    // 0x808001C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F13F0(rdram, ctx);
        goto after_7;
    // 0x808001C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x808001CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001D0: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x808001D4: jal         0x8009B9B0
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: jal         0x800931AC
    // 0x808001E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800931AC(rdram, ctx);
        goto after_9;
    // 0x808001E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808001E8: jal         0x8009C984
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_10;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001F4: jal         0x8009328C
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009328C(rdram, ctx);
        goto after_11;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: jal         0x8009BA58
    // 0x80800204: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_12;
    // 0x80800204: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_12:
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x8009BCB4
    // 0x80800210: lui         $a1, 0xC348
    ctx->r5 = S32(0XC348 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_13;
    // 0x80800210: lui         $a1, 0xC348
    ctx->r5 = S32(0XC348 << 16);
    after_13:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x8009BCC4
    // 0x8080021C: lui         $a1, 0xC270
    ctx->r5 = S32(0XC270 << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_14;
    // 0x8080021C: lui         $a1, 0xC270
    ctx->r5 = S32(0XC270 << 16);
    after_14:
    // 0x80800220: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800224: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800228: addiu       $t7, $zero, 0x6590
    ctx->r15 = ADD32(0, 0X6590);
    // 0x8080022C: addiu       $t8, $zero, 0x6590
    ctx->r24 = ADD32(0, 0X6590);
    // 0x80800230: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800234: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800238: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x8080023C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x8009DEC0
    // 0x80800248: addiu       $a1, $zero, 0x459E
    ctx->r5 = ADD32(0, 0X459E);
    func_8009DEC0(rdram, ctx);
        goto after_15;
    // 0x80800248: addiu       $a1, $zero, 0x459E
    ctx->r5 = ADD32(0, 0X459E);
    after_15:
    // 0x8080024C: jal         0x8009E4AC
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_16;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: jal         0x8009E138
    // 0x8080025C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E138(rdram, ctx);
        goto after_17;
    // 0x8080025C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800260: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x80800264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800268: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080026C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800270: jr          $ra
    // 0x80800274: nop

    return;
    // 0x80800274: nop

;}
RECOMP_FUNC void chquiz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B48: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2484, 0X74DC) << 16);
    // 0x80803B4C: jr          $ra
    // 0x80803B50: addiu       $v0, $v0, 0x74DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2484, 0X74DC));
    return;
    // 0x80803B50: addiu       $v0, $v0, 0x74DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2484, 0X74DC));
;}
RECOMP_FUNC void func_80801FC0_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801FC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801FC8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801FCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801FD0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801FD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801FD8: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80801FDC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(832, 0X2F90) << 16);
    // 0x80801FE0: addiu       $t7, $t7, 0x2F90
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(832, 0X2F90));
    // 0x80801FE4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801FE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801FEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801FF0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80801FF4: jal         0x800BABB8
    // 0x80801FF8: nop

    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80801FF8: nop

    after_0:
    // 0x80801FFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802000: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802004: jr          $ra
    // 0x80802008: nop

    return;
    // 0x80802008: nop

;}
RECOMP_FUNC void func_80800664_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080066C: jal         0x80800000
    // 0x80800670: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_bskazpaddle(rdram, ctx);
        goto after_0;
    // 0x80800670: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800674: jal         0x800A4E30
    // 0x80800678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_1;
    // 0x80800678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080067C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800684: jr          $ra
    // 0x80800688: nop

    return;
    // 0x80800688: nop

;}
RECOMP_FUNC void func_800B2344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2344: lhu         $v0, 0x16($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X16);
    // 0x800B2348: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x800B234C: jr          $ra
    // 0x800B2350: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x800B2350: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_80800BE8_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800BEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800BF0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800BF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800BF8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800BFC: jal         0x80100094
    // 0x80800C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C04: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800C08: jal         0x800DA298
    // 0x80800C0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800C0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800C10: beq         $v0, $zero, L_80800C60
    if (ctx->r2 == 0) {
        // 0x80800C14: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_80800C60;
    }
    // 0x80800C14: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800C18: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80800C1C: lui         $a1, 0x44AF
    ctx->r5 = S32(0X44AF << 16);
    // 0x80800C20: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    // 0x80800C24: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    // 0x80800C28: lui         $a3, 0xC4AF
    ctx->r7 = S32(0XC4AF << 16);
    // 0x80800C2C: beq         $a0, $zero, L_80800C50
    if (ctx->r4 == 0) {
        // 0x80800C30: nop
    
            goto L_80800C50;
    }
    // 0x80800C30: nop

    // 0x80800C34: jal         0x80106790
    // 0x80800C38: nop

    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800C38: nop

    after_2:
    // 0x80800C3C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800C40: jal         0x800EE7F8
    // 0x80800C44: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800C44: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_3:
    // 0x80800C48: b           L_80800CB0
    // 0x80800C4C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
        goto L_80800CB0;
    // 0x80800C4C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80800C50:
    // 0x80800C50: jal         0x800EFA4C
    // 0x80800C54: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800C54: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x80800C58: b           L_80800CB0
    // 0x80800C5C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
        goto L_80800CB0;
    // 0x80800C5C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80800C60:
    // 0x80800C60: lui         $at, 0xC4E1
    ctx->r1 = S32(0XC4E1 << 16);
    // 0x80800C64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C68: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x80800C6C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C70: jal         0x800DC178
    // 0x80800C74: nop

    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800C74: nop

    after_5:
    // 0x80800C78: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800C7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C80: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800C84: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C88: jal         0x800DC178
    // 0x80800C8C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800C8C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80800C90: lui         $at, 0xC4E1
    ctx->r1 = S32(0XC4E1 << 16);
    // 0x80800C94: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C98: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x80800C9C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800CA0: jal         0x800DC178
    // 0x80800CA4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800CA4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80800CA8: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80800CAC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80800CB0:
    // 0x80800CB0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800CB4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800CB8: jal         0x800DC178
    // 0x80800CBC: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80800CBC: nop

    after_8:
    // 0x80800CC0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800CC4: addiu       $a0, $zero, 0x350
    ctx->r4 = ADD32(0, 0X350);
    // 0x80800CC8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800CCC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x80800CD0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800CD4: jal         0x80108528
    // 0x80800CD8: nop

    func_80108528(rdram, ctx);
        goto after_9;
    // 0x80800CD8: nop

    after_9:
    // 0x80800CDC: jal         0x800DC0C0
    // 0x80800CE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800DC0C0(rdram, ctx);
        goto after_10;
    // 0x80800CE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_10:
    // 0x80800CE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1008, 0X1C38) << 16);
    // 0x80800CE8: lwc1        $f6, 0x1C38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1008, 0X1C38));
    // 0x80800CEC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800CF0: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80800CF4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800CF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800CFC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80800D00: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800D04: bc1fl       L_80800D18
    if (!c1cs) {
        // 0x80800D08: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80800D18;
    }
    goto skip_0;
    // 0x80800D08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80800D0C: b           L_80800D34
    // 0x80800D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D34;
    // 0x80800D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800D14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80800D18:
    // 0x80800D18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80800D1C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800D20: nop

    // 0x80800D24: bc1f        L_80800D34
    if (!c1cs) {
        // 0x80800D28: nop
    
            goto L_80800D34;
    }
    // 0x80800D28: nop

    // 0x80800D2C: b           L_80800D34
    // 0x80800D30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D34;
    // 0x80800D30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D34:
    // 0x80800D34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800D38: beql        $t8, $at, L_80800D48
    if (ctx->r24 == ctx->r1) {
        // 0x80800D3C: subu        $t9, $a0, $v0
        ctx->r25 = SUB32(ctx->r4, ctx->r2);
            goto L_80800D48;
    }
    goto skip_1;
    // 0x80800D3C: subu        $t9, $a0, $v0
    ctx->r25 = SUB32(ctx->r4, ctx->r2);
    skip_1:
    // 0x80800D40: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80800D44: subu        $t9, $a0, $v0
    ctx->r25 = SUB32(ctx->r4, ctx->r2);
L_80800D48:
    // 0x80800D48: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x80800D4C: lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XC);
    // 0x80800D50: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80800D54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D58: sltiu       $t2, $v1, 0x1
    ctx->r10 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800D5C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80800D60: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80800D64: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x80800D68: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80800D6C: beq         $v0, $zero, L_80800D8C
    if (ctx->r2 == 0) {
        // 0x80800D70: sb          $t7, 0x65($s0)
        MEM_B(0X65, ctx->r16) = ctx->r15;
            goto L_80800D8C;
    }
    // 0x80800D70: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80800D74: beq         $v0, $at, L_80800DBC
    if (ctx->r2 == ctx->r1) {
        // 0x80800D78: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80800DBC;
    }
    // 0x80800D78: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800D7C: beq         $v0, $a0, L_80800DEC
    if (ctx->r2 == ctx->r4) {
        // 0x80800D80: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800DEC;
    }
    // 0x80800D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D84: b           L_80800E1C
    // 0x80800D88: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
        goto L_80800E1C;
    // 0x80800D88: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
L_80800D8C:
    // 0x80800D8C: jal         0x80102424
    // 0x80800D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D98: addiu       $a1, $zero, 0x78C
    ctx->r5 = ADD32(0, 0X78C);
    // 0x80800D9C: jal         0x801032B0
    // 0x80800DA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_801032B0(rdram, ctx);
        goto after_12;
    // 0x80800DA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80800DA4: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800DA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800DAC: nop

    // 0x80800DB0: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x80800DB4: b           L_80800E18
    // 0x80800DB8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
        goto L_80800E18;
    // 0x80800DB8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_80800DBC:
    // 0x80800DBC: jal         0x80102424
    // 0x80800DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x80800DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DC8: addiu       $a1, $zero, 0x78D
    ctx->r5 = ADD32(0, 0X78D);
    // 0x80800DCC: jal         0x801032B0
    // 0x80800DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_801032B0(rdram, ctx);
        goto after_14;
    // 0x80800DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80800DD4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800DD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800DDC: nop

    // 0x80800DE0: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    // 0x80800DE4: b           L_80800E18
    // 0x80800DE8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
        goto L_80800E18;
    // 0x80800DE8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_80800DEC:
    // 0x80800DEC: jal         0x80102424
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF8: addiu       $a1, $zero, 0x796
    ctx->r5 = ADD32(0, 0X796);
    // 0x80800DFC: jal         0x801032B0
    // 0x80800E00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_801032B0(rdram, ctx);
        goto after_16;
    // 0x80800E00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x80800E04: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800E08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800E0C: nop

    // 0x80800E10: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x80800E14: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_80800E18:
    // 0x80800E18: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
L_80800E1C:
    // 0x80800E1C: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800E20: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800E24: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80800E28: andi        $t6, $t4, 0xFE00
    ctx->r14 = ctx->r12 & 0XFE00;
    // 0x80800E2C: addiu       $a1, $t0, 0x18
    ctx->r5 = ADD32(ctx->r8, 0X18);
    // 0x80800E30: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
    // 0x80800E34: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80800E38: lw          $t3, 0x6C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X6C);
    // 0x80800E3C: andi        $t5, $t3, 0x1FF
    ctx->r13 = ctx->r11 & 0X1FF;
    // 0x80800E40: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80800E44: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    // 0x80800E48: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x80800E4C: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800E50: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x80800E54: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x80800E58: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x80800E5C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800E60: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x80800E64: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800E68: beql        $t6, $zero, L_80800ECC
    if (ctx->r14 == 0) {
        // 0x80800E6C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800ECC;
    }
    goto skip_2;
    // 0x80800E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800E70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E74: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800E78: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    // 0x80800E7C: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80800E80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800E84: jal         0x8008A2D0
    // 0x80800E88: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_17;
    // 0x80800E88: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_17:
    // 0x80800E8C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80800E90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800E94: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80800E98: beql        $t7, $at, L_80800EC0
    if (ctx->r15 == ctx->r1) {
        // 0x80800E9C: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_80800EC0;
    }
    goto skip_3;
    // 0x80800E9C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80800EA0: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    // 0x80800EA4: beql        $a0, $zero, L_80800EC0
    if (ctx->r4 == 0) {
        // 0x80800EA8: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_80800EC0;
    }
    goto skip_4;
    // 0x80800EA8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x80800EAC: jal         0x80106790
    // 0x80800EB0: nop

    func_80106790(rdram, ctx);
        goto after_18;
    // 0x80800EB0: nop

    after_18:
    // 0x80800EB4: jal         0x80801B6C
    // 0x80800EB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80801B6C_chballoonburst(rdram, ctx);
        goto after_19;
    // 0x80800EB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x80800EBC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_80800EC0:
    // 0x80800EC0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80800EC4: sw          $t9, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r25;
    // 0x80800EC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800ECC:
    // 0x80800ECC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800ED0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800ED4: jr          $ra
    // 0x80800ED8: nop

    return;
    // 0x80800ED8: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E48: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E48);
    return;
    // 0x80089E4C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void baduo_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800774: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800778: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080077C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800780: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800784: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800788: jal         0x800F6224
    // 0x8080078C: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F6224(rdram, ctx);
        goto after_0;
    // 0x8080078C: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x80800790: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800794: jal         0x800F53D0
    // 0x80800798: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x80800798: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080079C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808007A0: jal         0x8009C984
    // 0x808007A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_get(rdram, ctx);
        goto after_2;
    // 0x808007A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808007A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808007AC: jal         0x8009C914
    // 0x808007B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_3;
    // 0x808007B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x808007B4: jal         0x8009C984
    // 0x808007B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x808007B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x808007BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808007C0: jal         0x8009C914
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_5;
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808007C8: jal         0x8009C974
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_6;
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D4: jal         0x8009E5C8
    // 0x808007D8: addiu       $a1, $zero, 0xBA
    ctx->r5 = ADD32(0, 0XBA);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x808007D8: addiu       $a1, $zero, 0xBA
    ctx->r5 = ADD32(0, 0XBA);
    after_7:
    // 0x808007DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007E0: jal         0x80800008
    // 0x808007E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800008_baduo(rdram, ctx);
        goto after_8;
    // 0x808007E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007EC: jal         0x8080017C
    // 0x808007F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baduo_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x808007F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808007F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007F8: jal         0x8080017C
    // 0x808007FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baduo_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x808007FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800800: jal         0x800F911C
    // 0x80800804: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800F911C(rdram, ctx);
        goto after_11;
    // 0x80800804: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x80800808: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    // 0x8080080C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800810: jal         0x800F9098
    // 0x80800814: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800F9098(rdram, ctx);
        goto after_12;
    // 0x80800814: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_12:
    // 0x80800818: lw          $t6, 0x58($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X58);
    // 0x8080081C: jal         0x800F90EC
    // 0x80800820: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    func_800F90EC(rdram, ctx);
        goto after_13;
    // 0x80800820: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    after_13:
    // 0x80800824: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800828: jal         0x800D5034
    // 0x8080082C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800D5034(rdram, ctx);
        goto after_14;
    // 0x8080082C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_14:
    // 0x80800830: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800834: jal         0x800D5034
    // 0x80800838: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800D5034(rdram, ctx);
        goto after_15;
    // 0x80800838: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_15:
    // 0x8080083C: jal         0x800F8EE4
    // 0x80800840: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F8EE4(rdram, ctx);
        goto after_16;
    // 0x80800840: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_16:
    // 0x80800844: jal         0x800F8128
    // 0x80800848: lw          $a0, 0x184($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X184);
    func_800F8128(rdram, ctx);
        goto after_17;
    // 0x80800848: lw          $a0, 0x184($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X184);
    after_17:
    // 0x8080084C: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    // 0x80800850: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80800854: jal         0x80101180
    // 0x80800858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_18;
    // 0x80800858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x8080085C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800860: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800864: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800868: jr          $ra
    // 0x8080086C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080086C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C88: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C88);
    return;
    // 0x80083C8C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void glglobalsettings_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D0: jal         0x800157E0
    // 0x808003D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    set_widescreen(rdram, ctx);
        goto after_0;
    // 0x808003D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808003DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003E0: beq         $t6, $zero, L_808003F0
    if (ctx->r14 == 0) {
        // 0x808003E4: nop
    
            goto L_808003F0;
    }
    // 0x808003E4: nop

    // 0x808003E8: b           L_808003F0
    // 0x808003EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808003F0;
    // 0x808003EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808003F0:
    // 0x808003F0: jal         0x800DA3B8
    // 0x808003F4: addiu       $a0, $zero, 0xBB9
    ctx->r4 = ADD32(0, 0XBB9);
    func_800DA3B8(rdram, ctx);
        goto after_1;
    // 0x808003F4: addiu       $a0, $zero, 0xBB9
    ctx->r4 = ADD32(0, 0XBB9);
    after_1:
    // 0x808003F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800400: jr          $ra
    // 0x80800404: nop

    return;
    // 0x80800404: nop

;}
RECOMP_FUNC void func_800D27F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D27F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D27F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D27FC: jal         0x800D21D0
    // 0x800D2800: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D21D0(rdram, ctx);
        goto after_0;
    // 0x800D2800: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D2804: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2808: jal         0x800D23E8
    // 0x800D280C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800D23E8(rdram, ctx);
        goto after_1;
    // 0x800D280C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800D2810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2818: jr          $ra
    // 0x800D281C: nop

    return;
    // 0x800D281C: nop

;}
RECOMP_FUNC void func_80800574_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080057C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800580: jal         0x8008A2F8
    // 0x80800584: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800584: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080058C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800590: jr          $ra
    // 0x80800594: nop

    return;
    // 0x80800594: nop

;}
RECOMP_FUNC void bsstand_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800194: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800198: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080019C: jal         0x8009E710
    // 0x808001A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_0;
    // 0x808001A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001A4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x8009CBDC
    // 0x808001B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8009CBDC(rdram, ctx);
        goto after_1;
    // 0x808001B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808001B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808001B8: bnel        $v0, $at, L_808001CC
    if (ctx->r2 != ctx->r1) {
        // 0x808001BC: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_808001CC;
    }
    goto skip_0;
    // 0x808001BC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808001C0: jal         0x80098840
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80098840(rdram, ctx);
        goto after_2;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001C8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_808001CC:
    // 0x808001CC: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: bne         $t6, $at, L_808001F4
    if (ctx->r14 != ctx->r1) {
        // 0x808001D8: addiu       $a1, $zero, 0x6F
        ctx->r5 = ADD32(0, 0X6F);
            goto L_808001F4;
    }
    // 0x808001D8: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x808001E4: jal         0x8008CDB8
    // 0x808001E8: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    baanim_playForDuration_once(rdram, ctx);
        goto after_3;
    // 0x808001E8: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    after_3:
    // 0x808001EC: b           L_80800200
    // 0x808001F0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
        goto L_80800200;
    // 0x808001F0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_808001F4:
    // 0x808001F4: jal         0x8008CCBC
    // 0x808001F8: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_4;
    // 0x808001F8: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    after_4:
    // 0x808001FC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80800200:
    // 0x80800200: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080020C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800210: jal         0x8009FFD8
    // 0x80800214: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_5;
    // 0x80800214: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x8009B9B0
    // 0x80800220: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x80800220: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800224: jal         0x800909CC
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_7;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080022C: jal         0x8008E23C
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E23C(rdram, ctx);
        goto after_8;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800234: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x80800238: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8080024C;
    }
    // 0x80800238: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080023C: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80800240: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800244: b           L_80800258
    // 0x80800248: sw          $t8, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r24;
        goto L_80800258;
    // 0x80800248: sw          $t8, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r24;
L_8080024C:
    // 0x8080024C: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x80800250: sw          $t9, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r25;
    // 0x80800254: sw          $t0, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r8;
L_80800258:
    // 0x80800258: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x8080025C: sw          $zero, 0x168($s0)
    MEM_W(0X168, ctx->r16) = 0;
    // 0x80800260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800264: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800268: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
