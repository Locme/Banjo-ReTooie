#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800288_chklungoforcefield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800288: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080028C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800290: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800294: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800298: lbu         $t6, 0x9B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9B);
    // 0x8080029C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002A0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x808002A4: jal         0x800E8C58
    // 0x808002A8: lbu         $a0, 0x24($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X24);
    func_800E8C58(rdram, ctx);
        goto after_0;
    // 0x808002A8: lbu         $a0, 0x24($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X24);
    after_0:
    // 0x808002AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002B4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808002B8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002BC: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x808002C0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808002C4: lui         $a2, 0x437F
    ctx->r6 = S32(0X437F << 16);
    // 0x808002C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808002CC: jal         0x800F10B4
    // 0x808002D0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808002D0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x808002D4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x808002D8: jal         0x800E3A58
    // 0x808002DC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800E3A58(rdram, ctx);
        goto after_2;
    // 0x808002DC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x808002E0: jal         0x80101970
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101970(rdram, ctx);
        goto after_3;
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002E8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808002EC: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808002F0: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808002F4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x808002F8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808002FC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800300: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800304: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80800308: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080030C: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80800310: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800314: addiu       $a0, $a0, 0x15D0
    ctx->r4 = ADD32(ctx->r4, 0X15D0);
    // 0x80800318: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080031C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800320: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800324: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800328: nop

    // 0x8080032C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800330: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800334: nop

    // 0x80800338: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8080033C: beql        $t9, $zero, L_8080038C
    if (ctx->r25 == 0) {
        // 0x80800340: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_8080038C;
    }
    goto skip_0;
    // 0x80800340: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x80800344: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800348: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080034C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800350: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800354: nop

    // 0x80800358: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8080035C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800360: nop

    // 0x80800364: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800368: bne         $t9, $zero, L_80800380
    if (ctx->r25 != 0) {
        // 0x8080036C: nop
    
            goto L_80800380;
    }
    // 0x8080036C: nop

    // 0x80800370: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80800374: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800378: b           L_80800398
    // 0x8080037C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80800398;
    // 0x8080037C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80800380:
    // 0x80800380: b           L_80800398
    // 0x80800384: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80800398;
    // 0x80800384: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800388: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_8080038C:
    // 0x8080038C: nop

    // 0x80800390: bltz        $t9, L_80800380
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800394: nop
    
            goto L_80800380;
    }
    // 0x80800394: nop

L_80800398:
    // 0x80800398: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8080039C: jal         0x800DF47C
    // 0x808003A0: sb          $t9, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r25;
    func_800DF47C(rdram, ctx);
        goto after_4;
    // 0x808003A0: sb          $t9, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r25;
    after_4:
    // 0x808003A4: jal         0x801018D8
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801018D8(rdram, ctx);
        goto after_5;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808003AC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808003B0: jal         0x8010347C
    // 0x808003B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_6;
    // 0x808003B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x808003B8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808003BC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808003C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808003C4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808003C8: jal         0x800DE448
    // 0x808003CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800DE448(rdram, ctx);
        goto after_7;
    // 0x808003CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x808003D0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x808003D4: sb          $t0, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r8;
    // 0x808003D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

    // 0x808003EC: nop

;}
RECOMP_FUNC void _chdiggergroundgen_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CA0: syscall     220
    recomp_syscall_handler(rdram, ctx, 0x80085CA0);
    return;
    // 0x80085CA4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800320_chfactoryworkerwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800328: jal         0x80100094
    // 0x8080032C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080032C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800330: jal         0x80101068
    // 0x80800334: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80101068(rdram, ctx);
        goto after_1;
    // 0x80800334: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800338: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080033C: swc1        $f0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f0.u32l;
    // 0x80800340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800344: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800348: jr          $ra
    // 0x8080034C: nop

    return;
    // 0x8080034C: nop

;}
RECOMP_FUNC void func_808002B0_chgate1doors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C0: jal         0x800DA298
    // 0x808002C4: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808002C4: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    after_0:
    // 0x808002C8: beq         $v0, $zero, L_808002F8
    if (ctx->r2 == 0) {
        // 0x808002CC: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808002F8;
    }
    // 0x808002CC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808002D0: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808002D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: jal         0x8010A570
    // 0x808002E0: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x808002E0: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: jal         0x80101FDC
    // 0x808002EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808002EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808002F0: b           L_80800324
    // 0x808002F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800324;
    // 0x808002F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002F8:
    // 0x808002F8: addiu       $a1, $zero, 0x128
    ctx->r5 = ADD32(0, 0X128);
    // 0x808002FC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800300: jal         0x80089C20
    // 0x80800304: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800304: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800308: beql        $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x8080030C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800324;
    }
    goto skip_0;
    // 0x8080030C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800310: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80800314: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80800318: sw          $t6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r14;
    // 0x8080031C: sw          $t7, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r15;
    // 0x80800320: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800324:
    // 0x80800324: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800328: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080032C: jr          $ra
    // 0x80800330: nop

    return;
    // 0x80800330: nop

;}
RECOMP_FUNC void _chweldarhead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086700: syscall     357
    recomp_syscall_handler(rdram, ctx, 0x80086700);
    return;
    // 0x80086704: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800054_changlerbossbubble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800060: jal         0x800D8FF8
    // 0x80800064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800068: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080006C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800070: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800074: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
    // 0x80800078: jal         0x800EFD4C
    // 0x8080007C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    func_800EFD4C(rdram, ctx);
        goto after_1;
    // 0x8080007C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x80800080: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800084: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800090: beq         $t6, $at, L_808000AC
    if (ctx->r14 == ctx->r1) {
        // 0x80800094: lui         $a1, 0x40
        ctx->r5 = S32(0X40 << 16);
            goto L_808000AC;
    }
    // 0x80800094: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x80800098: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080009C: beql        $t6, $at, L_808000D4
    if (ctx->r14 == ctx->r1) {
        // 0x808000A0: lw          $a0, 0x6C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X6C);
            goto L_808000D4;
    }
    goto skip_0;
    // 0x808000A0: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x808000A4: b           L_80800184
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800184;
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000AC:
    // 0x808000AC: jal         0x8010B990
    // 0x808000B0: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    func_8010B990(rdram, ctx);
        goto after_2;
    // 0x808000B0: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    after_2:
    // 0x808000B4: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x808000B8: beql        $t7, $zero, L_80800184
    if (ctx->r15 == 0) {
        // 0x808000BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800184;
    }
    goto skip_1;
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808000C0: jal         0x80800334
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800334_changlerbossbubble(rdram, ctx);
        goto after_3;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000C8: b           L_80800184
    // 0x808000CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800184;
    // 0x808000CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D0: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
L_808000D4:
    // 0x808000D4: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x808000D8: jal         0x800F54F0
    // 0x808000DC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800F54F0(rdram, ctx);
        goto after_4;
    // 0x808000DC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_4:
    // 0x808000E0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808000E4: jal         0x80800450
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800450_changlerbossbubble(rdram, ctx);
        goto after_5;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F0: jal         0x80015E80
    // 0x808000F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80015E80(rdram, ctx);
        goto after_6;
    // 0x808000F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x808000F8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x808000FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800100: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800104: beql        $v0, $t9, L_80800118
    if (ctx->r2 == ctx->r25) {
        // 0x80800108: lw          $t1, 0x1C($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X1C);
            goto L_80800118;
    }
    goto skip_2;
    // 0x80800108: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    skip_2:
    // 0x8080010C: bne         $v0, $t0, L_80800158
    if (ctx->r2 != ctx->r8) {
        // 0x80800110: nop
    
            goto L_80800158;
    }
    // 0x80800110: nop

    // 0x80800114: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
L_80800118:
    // 0x80800118: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8080011C: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x80800120: bne         $at, $zero, L_80800144
    if (ctx->r1 != 0) {
        // 0x80800124: sw          $t2, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r10;
            goto L_80800144;
    }
    // 0x80800124: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
    // 0x80800128: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8080012C: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x80800130: andi        $t4, $a0, 0x1FF
    ctx->r12 = ctx->r4 & 0X1FF;
    // 0x80800134: jal         0x800F7B9C
    // 0x80800138: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800F7B9C(rdram, ctx);
        goto after_7;
    // 0x80800138: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_7:
    // 0x8080013C: b           L_80800184
    // 0x80800140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800184;
    // 0x80800140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800144:
    // 0x80800144: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800148: addiu       $a1, $zero, 0x7B
    ctx->r5 = ADD32(0, 0X7B);
    // 0x8080014C: andi        $t5, $a0, 0x1FF
    ctx->r13 = ctx->r4 & 0X1FF;
    // 0x80800150: jal         0x800F7B9C
    // 0x80800154: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_800F7B9C(rdram, ctx);
        goto after_8;
    // 0x80800154: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_8:
L_80800158:
    // 0x80800158: jal         0x800D9078
    // 0x8080015C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D9078(rdram, ctx);
        goto after_9;
    // 0x8080015C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_9:
    // 0x80800160: beql        $v0, $zero, L_80800184
    if (ctx->r2 == 0) {
        // 0x80800164: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800184;
    }
    goto skip_3;
    // 0x80800164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800168: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080016C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800170: beql        $a0, $zero, L_80800184
    if (ctx->r4 == 0) {
        // 0x80800174: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800184;
    }
    goto skip_4;
    // 0x80800174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800178: jal         0x8010114C
    // 0x8080017C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_10;
    // 0x8080017C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80800180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800184:
    // 0x80800184: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800188: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void func_80800018_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080001C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800020: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800024: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080002C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800030: jal         0x80100094
    // 0x80800034: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800034: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800038: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8080003C: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x80800040: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800044: bltzl       $t8, L_8080042C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800048: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080042C;
    }
    goto skip_0;
    // 0x80800048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080004C: jal         0x800D8FF8
    // 0x80800050: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800050: nop

    after_1:
    // 0x80800054: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800058: jal         0x800D9078
    // 0x8080005C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x8080005C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x80800060: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800064: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800068: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8080006C: sltiu       $at, $t1, 0x7
    ctx->r1 = ctx->r9 < 0X7 ? 1 : 0;
    // 0x80800070: beq         $at, $zero, L_808003D4
    if (ctx->r1 == 0) {
        // 0x80800074: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_808003D4;
    }
    // 0x80800074: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800078: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1024, 0XDE0) << 16);
    // 0x8080007C: addu        $at, $at, $t1
    gpr jr_addend_80800084 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800080: lw          $t1, 0xDE0($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1024, 0XDE0));
    // 0x80800084: jr          $t1
    // 0x80800088: nop

    switch (jr_addend_80800084 >> 2) {
        case 0: goto L_8080008C; break;
        case 1: goto L_808000AC; break;
        case 2: goto L_808000F4; break;
        case 3: goto L_80800244; break;
        case 4: goto L_80800264; break;
        case 5: goto L_808002A0; break;
        case 6: goto L_808003BC; break;
        default: switch_error(__func__, 0x80800084, 0x80800DE0);
    }
    // 0x80800088: nop

L_8080008C:
    // 0x8080008C: jal         0x8080082C
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080082C_chseaweedbaddy(rdram, ctx);
        goto after_3;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800094: beq         $v0, $zero, L_808003D4
    if (ctx->r2 == 0) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D4;
    }
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x80800710
    // 0x808000A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_4;
    // 0x808000A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808000A4: b           L_808003D8
    // 0x808000A8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
        goto L_808003D8;
    // 0x808000A8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_808000AC:
    // 0x808000AC: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x808000B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1024, 0XF44) << 16);
    // 0x808000B8: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x808000BC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808000C0: addiu       $a2, $a2, 0xF44
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1024, 0XF44));
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000CC: jal         0x80089D20
    // 0x808000D0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808000D0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x808000D4: jal         0x80101DDC
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_6;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000DC: beq         $v0, $zero, L_808003D4
    if (ctx->r2 == 0) {
        // 0x808000E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D4;
    }
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x80800710
    // 0x808000E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_7;
    // 0x808000E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808000EC: b           L_808003D8
    // 0x808000F0: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
        goto L_808003D8;
    // 0x808000F0: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_808000F4:
    // 0x808000F4: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x808000F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000FC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800100: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800104: jal         0x8010D254
    // 0x80800108: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    func_8010D254(rdram, ctx);
        goto after_8;
    // 0x80800108: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x8080010C: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x80800118: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8080011C: bgez        $t4, L_80800170
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800120: nop
    
            goto L_80800170;
    }
    // 0x80800120: nop

    // 0x80800124: jal         0x80089BF0
    // 0x80800128: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x80800128: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_9:
    // 0x8080012C: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800130: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800134: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80800138: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8080013C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800140: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800144: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80800148: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8080014C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800150: jal         0x800EEB9C
    // 0x80800154: nop

    func_800EEB9C(rdram, ctx);
        goto after_10;
    // 0x80800154: nop

    after_10:
    // 0x80800158: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x8080015C: ori         $a1, $a1, 0x5027
    ctx->r5 = ctx->r5 | 0X5027;
    // 0x80800160: jal         0x8010B990
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_11;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800168: b           L_80800224
    // 0x8080016C: nop

        goto L_80800224;
    // 0x8080016C: nop

L_80800170:
    // 0x80800170: jal         0x80089F78
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800178: beq         $v0, $zero, L_808001CC
    if (ctx->r2 == 0) {
        // 0x8080017C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001CC;
    }
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: jal         0x80102D78
    // 0x80800184: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102D78(rdram, ctx);
        goto after_13;
    // 0x80800184: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x80800188: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080018C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800190: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800194: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800198: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x8080019C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001A0: addiu       $t5, $zero, 0x5000
    ctx->r13 = ADD32(0, 0X5000);
    // 0x808001A4: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x808001A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808001AC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: jal         0x80089F90
    // 0x808001B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_14;
    // 0x808001B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x808001BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808001C0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x808001C4: lhu         $t6, 0x6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X6);
    // 0x808001C8: sw          $t6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r14;
L_808001CC:
    // 0x808001CC: jal         0x800D8FF8
    // 0x808001D0: nop

    func_800D8FF8(rdram, ctx);
        goto after_15;
    // 0x808001D0: nop

    after_15:
    // 0x808001D4: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x808001D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001DC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x808001E0: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808001E4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808001E8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x808001EC: lwc1        $f12, 0xC($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XC);
    // 0x808001F0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808001F4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x808001F8: jal         0x800F1FF0
    // 0x808001FC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_16;
    // 0x808001FC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x80800200: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80800204: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800208: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080020C: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    // 0x80800210: jal         0x800EEB9C
    // 0x80800214: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    func_800EEB9C(rdram, ctx);
        goto after_17;
    // 0x80800214: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    after_17:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x8010B990
    // 0x80800220: addiu       $a1, $zero, 0x5307
    ctx->r5 = ADD32(0, 0X5307);
    func_8010B990(rdram, ctx);
        goto after_18;
    // 0x80800220: addiu       $a1, $zero, 0x5307
    ctx->r5 = ADD32(0, 0X5307);
    after_18:
L_80800224:
    // 0x80800224: jal         0x80800910
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800910_chseaweedbaddy(rdram, ctx);
        goto after_19;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080022C: beq         $v0, $zero, L_808003D4
    if (ctx->r2 == 0) {
        // 0x80800230: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D4;
    }
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: jal         0x80800710
    // 0x80800238: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_20;
    // 0x80800238: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_20:
    // 0x8080023C: b           L_808003D8
    // 0x80800240: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
        goto L_808003D8;
    // 0x80800240: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_80800244:
    // 0x80800244: jal         0x80101DDC
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_21;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080024C: beq         $v0, $zero, L_808003D4
    if (ctx->r2 == 0) {
        // 0x80800250: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D4;
    }
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x80800710
    // 0x80800258: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_22;
    // 0x80800258: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_22:
    // 0x8080025C: b           L_808003D8
    // 0x80800260: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
        goto L_808003D8;
    // 0x80800260: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_80800264:
    // 0x80800264: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1024, 0XF50) << 16);
    // 0x80800268: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8080026C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800270: addiu       $a2, $a2, 0xF50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1024, 0XF50));
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x80089D20
    // 0x8080027C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x8080027C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_23:
    // 0x80800280: jal         0x80101DDC
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_24;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800288: beq         $v0, $zero, L_808003D4
    if (ctx->r2 == 0) {
        // 0x8080028C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D4;
    }
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x80800710
    // 0x80800294: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_25;
    // 0x80800294: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_25:
    // 0x80800298: b           L_808003D8
    // 0x8080029C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
        goto L_808003D8;
    // 0x8080029C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_808002A0:
    // 0x808002A0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808002A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80089F78
    // 0x808002B0: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_26;
    // 0x808002B0: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    after_26:
    // 0x808002B4: beq         $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x808002B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800308;
    }
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: jal         0x80102D78
    // 0x808002C0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_27;
    // 0x808002C0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_27:
    // 0x808002C4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x808002C8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808002CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808002D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808002D4: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x808002D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808002DC: addiu       $t0, $zero, 0x5000
    ctx->r8 = ADD32(0, 0X5000);
    // 0x808002E0: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x808002E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808002E8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: jal         0x80089F90
    // 0x808002F4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_28;
    // 0x808002F4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_28:
    // 0x808002F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808002FC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80800300: lhu         $t1, 0x6($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X6);
    // 0x80800304: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
L_80800308:
    // 0x80800308: addiu       $t3, $s0, 0x18
    ctx->r11 = ADD32(ctx->r16, 0X18);
    // 0x8080030C: jal         0x800D8FF8
    // 0x80800310: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    func_800D8FF8(rdram, ctx);
        goto after_29;
    // 0x80800310: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_29:
    // 0x80800314: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80800318: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080031C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80800320: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800324: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800328: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8080032C: lwc1        $f12, 0xC($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80800330: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800334: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80800338: jal         0x800F1FF0
    // 0x8080033C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_30;
    // 0x8080033C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_30:
    // 0x80800340: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80800344: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800348: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080034C: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    // 0x80800350: jal         0x800EEB9C
    // 0x80800354: swc1        $f0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f0.u32l;
    func_800EEB9C(rdram, ctx);
        goto after_31;
    // 0x80800354: swc1        $f0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f0.u32l;
    after_31:
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: jal         0x8010B990
    // 0x80800360: addiu       $a1, $zero, 0x5307
    ctx->r5 = ADD32(0, 0X5307);
    func_8010B990(rdram, ctx);
        goto after_32;
    // 0x80800360: addiu       $a1, $zero, 0x5307
    ctx->r5 = ADD32(0, 0X5307);
    after_32:
    // 0x80800364: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800368: jal         0x800EEB40
    // 0x8080036C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EEB40(rdram, ctx);
        goto after_33;
    // 0x8080036C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_33:
    // 0x80800370: lui         $at, 0x45C8
    ctx->r1 = S32(0X45C8 << 16);
    // 0x80800374: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800380: nop

    // 0x80800384: bc1f        L_8080039C
    if (!c1cs) {
        // 0x80800388: nop
    
            goto L_8080039C;
    }
    // 0x80800388: nop

    // 0x8080038C: jal         0x80800710
    // 0x80800390: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_34;
    // 0x80800390: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_34:
    // 0x80800394: b           L_808003D8
    // 0x80800398: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
        goto L_808003D8;
    // 0x80800398: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_8080039C:
    // 0x8080039C: jal         0x8080082C
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080082C_chseaweedbaddy(rdram, ctx);
        goto after_35;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808003A4: beq         $v0, $zero, L_808003D4
    if (ctx->r2 == 0) {
        // 0x808003A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D4;
    }
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x80800710
    // 0x808003B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_36;
    // 0x808003B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_36:
    // 0x808003B4: b           L_808003D8
    // 0x808003B8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
        goto L_808003D8;
    // 0x808003B8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_808003BC:
    // 0x808003BC: jal         0x80101DDC
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_37;
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x808003C4: beq         $v0, $zero, L_808003D4
    if (ctx->r2 == 0) {
        // 0x808003C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D4;
    }
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: jal         0x80800710
    // 0x808003D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_38;
    // 0x808003D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
L_808003D4:
    // 0x808003D4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_808003D8:
    // 0x808003D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003DC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808003E0: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808003E4: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808003E8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808003EC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x808003F0: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808003F4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808003F8: jal         0x800F15F8
    // 0x808003FC: nop

    func_800F15F8(rdram, ctx);
        goto after_39;
    // 0x808003FC: nop

    after_39:
    // 0x80800400: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800404: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800408: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080040C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800410: jal         0x800136E4
    // 0x80800414: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_40;
    // 0x80800414: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_40:
    // 0x80800418: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x8080041C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800420: jal         0x80800CE0
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CE0_chseaweedbaddy(rdram, ctx);
        goto after_41;
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80800428: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080042C:
    // 0x8080042C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800430: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800434: jr          $ra
    // 0x80800438: nop

    return;
    // 0x80800438: nop

;}
RECOMP_FUNC void func_800D52A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D52A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D52A8: jr          $ra
    // 0x800D52AC: lbu         $v0, -0x4BD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4BD0);
    return;
    // 0x800D52AC: lbu         $v0, -0x4BD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4BD0);
;}
RECOMP_FUNC void func_80800314_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800318: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080031C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800320: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800324: jal         0x80100094
    // 0x80800328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080032C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800330: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800334: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800338: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080033C: sltiu       $at, $t8, 0x22
    ctx->r1 = ctx->r24 < 0X22 ? 1 : 0;
    // 0x80800340: beq         $at, $zero, L_80800924
    if (ctx->r1 == 0) {
        // 0x80800344: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800924;
    }
    // 0x80800344: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800348: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2DF0) << 16);
    // 0x8080034C: addu        $at, $at, $t8
    gpr jr_addend_80800354 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800350: lw          $t8, 0x2DF0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2DF0));
    // 0x80800354: jr          $t8
    // 0x80800358: nop

    switch (jr_addend_80800354 >> 2) {
        case 0: goto L_8080035C; break;
        case 1: goto L_8080046C; break;
        case 2: goto L_80800494; break;
        case 3: goto L_808004B4; break;
        case 4: goto L_808004D8; break;
        case 5: goto L_80800504; break;
        case 6: goto L_80800504; break;
        case 7: goto L_80800540; break;
        case 8: goto L_80800924; break;
        case 9: goto L_80800924; break;
        case 10: goto L_80800604; break;
        case 11: goto L_80800624; break;
        case 12: goto L_80800924; break;
        case 13: goto L_80800660; break;
        case 14: goto L_80800688; break;
        case 15: goto L_80800924; break;
        case 16: goto L_808006AC; break;
        case 17: goto L_808006CC; break;
        case 18: goto L_80800700; break;
        case 19: goto L_80800504; break;
        case 20: goto L_80800504; break;
        case 21: goto L_80800720; break;
        case 22: goto L_80800924; break;
        case 23: goto L_80800924; break;
        case 24: goto L_80800798; break;
        case 25: goto L_808007B8; break;
        case 26: goto L_808007EC; break;
        case 27: goto L_80800828; break;
        case 28: goto L_80800850; break;
        case 29: goto L_80800924; break;
        case 30: goto L_80800874; break;
        case 31: goto L_80800894; break;
        case 32: goto L_808008C8; break;
        case 33: goto L_8080090C; break;
        default: switch_error(__func__, 0x80800354, 0x80802DF0);
    }
    // 0x80800358: nop

L_8080035C:
    // 0x8080035C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x80800360: jal         0x800F54E4
    // 0x80800364: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800364: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    after_1:
    // 0x80800368: jal         0x800F5410
    // 0x8080036C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_2;
    // 0x8080036C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800370: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800374: beq         $v0, $at, L_8080039C
    if (ctx->r2 == ctx->r1) {
        // 0x80800378: lw          $t0, 0x48($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X48);
            goto L_8080039C;
    }
    // 0x80800378: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8080037C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800380: beq         $v0, $at, L_808003AC
    if (ctx->r2 == ctx->r1) {
        // 0x80800384: addiu       $t1, $zero, 0x13E1
        ctx->r9 = ADD32(0, 0X13E1);
            goto L_808003AC;
    }
    // 0x80800384: addiu       $t1, $zero, 0x13E1
    ctx->r9 = ADD32(0, 0X13E1);
    // 0x80800388: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080038C: beq         $v0, $at, L_808003B8
    if (ctx->r2 == ctx->r1) {
        // 0x80800390: addiu       $t2, $zero, 0x1456
        ctx->r10 = ADD32(0, 0X1456);
            goto L_808003B8;
    }
    // 0x80800390: addiu       $t2, $zero, 0x1456
    ctx->r10 = ADD32(0, 0X1456);
    // 0x80800394: b           L_808003C0
    // 0x80800398: nop

        goto L_808003C0;
    // 0x80800398: nop

L_8080039C:
    // 0x8080039C: addiu       $t9, $zero, 0x13E1
    ctx->r25 = ADD32(0, 0X13E1);
    // 0x808003A0: addiu       $t0, $zero, 0x13E0
    ctx->r8 = ADD32(0, 0X13E0);
    // 0x808003A4: b           L_808003C0
    // 0x808003A8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_808003C0;
    // 0x808003A8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_808003AC:
    // 0x808003AC: addiu       $t0, $zero, 0x1454
    ctx->r8 = ADD32(0, 0X1454);
    // 0x808003B0: b           L_808003C0
    // 0x808003B4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_808003C0;
    // 0x808003B4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_808003B8:
    // 0x808003B8: addiu       $t0, $zero, 0x1455
    ctx->r8 = ADD32(0, 0X1455);
    // 0x808003BC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_808003C0:
    // 0x808003C0: beq         $t0, $zero, L_808003EC
    if (ctx->r8 == 0) {
        // 0x808003C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003EC;
    }
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x808003CC: sll         $a3, $t0, 16
    ctx->r7 = S32(ctx->r8 << 16);
    // 0x808003D0: sra         $t3, $a3, 16
    ctx->r11 = S32(SIGNED(ctx->r7) >> 16);
    // 0x808003D4: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x808003D8: addiu       $a1, $zero, 0x3D9
    ctx->r5 = ADD32(0, 0X3D9);
    // 0x808003DC: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x808003E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808003E4: jal         0x80802730
    // 0x808003E8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_80802730_chfantasyathlete(rdram, ctx);
        goto after_3;
    // 0x808003E8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
L_808003EC:
    // 0x808003EC: jal         0x800F54E4
    // 0x808003F0: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808003F0: nop

    after_4:
    // 0x808003F4: jal         0x800F6720
    // 0x808003F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6720(rdram, ctx);
        goto after_5;
    // 0x808003F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808003FC: bnel        $v0, $zero, L_80800928
    if (ctx->r2 != 0) {
        // 0x80800400: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800928;
    }
    goto skip_0;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800404: jal         0x800DA298
    // 0x80800408: addiu       $a0, $zero, 0x3D9
    ctx->r4 = ADD32(0, 0X3D9);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800408: addiu       $a0, $zero, 0x3D9
    ctx->r4 = ADD32(0, 0X3D9);
    after_6:
    // 0x8080040C: beql        $v0, $zero, L_80800928
    if (ctx->r2 == 0) {
        // 0x80800410: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800928;
    }
    goto skip_1;
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800414: jal         0x800F54E4
    // 0x80800418: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800418: nop

    after_7:
    // 0x8080041C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800420: jal         0x800F5A00
    // 0x80800424: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5A00(rdram, ctx);
        goto after_8;
    // 0x80800424: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_8:
    // 0x80800428: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8080042C: addiu       $t5, $sp, 0x38
    ctx->r13 = ADD32(ctx->r29, 0X38);
    // 0x80800430: addiu       $t6, $s0, 0x2C
    ctx->r14 = ADD32(ctx->r16, 0X2C);
    // 0x80800434: lwc1        $f4, 0x24($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80800438: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8080043C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800444: addiu       $a1, $a3, 0xC
    ctx->r5 = ADD32(ctx->r7, 0XC);
    // 0x80800448: addiu       $a2, $a3, 0x18
    ctx->r6 = ADD32(ctx->r7, 0X18);
    // 0x8080044C: jal         0x80801114
    // 0x80800450: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80801114_chfantasyathlete(rdram, ctx);
        goto after_9;
    // 0x80800450: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x80800454: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x80800458: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: jal         0x8080094C
    // 0x80800460: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_10;
    // 0x80800460: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800464: b           L_80800928
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080046C:
    // 0x8080046C: jal         0x800F54E4
    // 0x80800470: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80800470: nop

    after_11:
    // 0x80800474: jal         0x800F6C5C
    // 0x80800478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_12;
    // 0x80800478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x8080047C: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x80800480: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: jal         0x8080094C
    // 0x80800488: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_13;
    // 0x80800488: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x8080048C: b           L_80800928
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800494:
    // 0x80800494: jal         0x800D90A4
    // 0x80800498: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_14;
    // 0x80800498: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_14:
    // 0x8080049C: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x808004A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x8080094C
    // 0x808004A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_15;
    // 0x808004A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x808004AC: b           L_80800928
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004B4:
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004C0: addiu       $a3, $zero, 0x13E2
    ctx->r7 = ADD32(0, 0X13E2);
    // 0x808004C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808004C8: jal         0x80802730
    // 0x808004CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80802730_chfantasyathlete(rdram, ctx);
        goto after_16;
    // 0x808004CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_16:
    // 0x808004D0: b           L_80800928
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004D8:
    // 0x808004D8: jal         0x80802950
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802950_chfantasyathlete(rdram, ctx);
        goto after_17;
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808004E0: beql        $v0, $zero, L_80800928
    if (ctx->r2 == 0) {
        // 0x808004E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800928;
    }
    goto skip_2;
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808004E8: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: srl         $t7, $a1, 10
    ctx->r15 = S32(U32(ctx->r5) >> 10);
    // 0x808004F4: jal         0x8080094C
    // 0x808004F8: addiu       $a1, $t7, 0x1
    ctx->r5 = ADD32(ctx->r15, 0X1);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_18;
    // 0x808004F8: addiu       $a1, $t7, 0x1
    ctx->r5 = ADD32(ctx->r15, 0X1);
    after_18:
    // 0x808004FC: b           L_80800928
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800504:
    // 0x80800504: jal         0x80801718
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801718_chfantasyathlete(rdram, ctx);
        goto after_19;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080050C: jal         0x80105834
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_20;
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800514: jal         0x80105A5C
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_21;
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080051C: beql        $v0, $zero, L_80800928
    if (ctx->r2 == 0) {
        // 0x80800520: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800928;
    }
    goto skip_3;
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800524: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: srl         $t8, $a1, 10
    ctx->r24 = S32(U32(ctx->r5) >> 10);
    // 0x80800530: jal         0x8080094C
    // 0x80800534: addiu       $a1, $t8, 0x1
    ctx->r5 = ADD32(ctx->r24, 0X1);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_22;
    // 0x80800534: addiu       $a1, $t8, 0x1
    ctx->r5 = ADD32(ctx->r24, 0X1);
    after_22:
    // 0x80800538: b           L_80800928
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800540:
    // 0x80800540: jal         0x800F54E4
    // 0x80800544: nop

    func_800F54E4(rdram, ctx);
        goto after_23;
    // 0x80800544: nop

    after_23:
    // 0x80800548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080054C: jal         0x800F64A4
    // 0x80800550: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800F64A4(rdram, ctx);
        goto after_24;
    // 0x80800550: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_24:
    // 0x80800554: beql        $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x80800558: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808005D4;
    }
    goto skip_4;
    // 0x80800558: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_4:
    // 0x8080055C: jal         0x800F54E4
    // 0x80800560: nop

    func_800F54E4(rdram, ctx);
        goto after_25;
    // 0x80800560: nop

    after_25:
    // 0x80800564: jal         0x800F5C94
    // 0x80800568: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5C94(rdram, ctx);
        goto after_26;
    // 0x80800568: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x8080056C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800570: bnel        $v0, $at, L_808005D4
    if (ctx->r2 != ctx->r1) {
        // 0x80800574: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808005D4;
    }
    goto skip_5;
    // 0x80800574: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_5:
    // 0x80800578: jal         0x800D90A4
    // 0x8080057C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_27;
    // 0x8080057C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_27:
    // 0x80800580: beql        $v0, $zero, L_80800928
    if (ctx->r2 == 0) {
        // 0x80800584: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800928;
    }
    goto skip_6;
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x80800588: jal         0x800DA298
    // 0x8080058C: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    func_800DA298(rdram, ctx);
        goto after_28;
    // 0x8080058C: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    after_28:
    // 0x80800590: beq         $v0, $zero, L_808005A0
    if (ctx->r2 == 0) {
        // 0x80800594: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005A0;
    }
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: b           L_808005A4
    // 0x8080059C: addiu       $v0, $zero, 0x1435
    ctx->r2 = ADD32(0, 0X1435);
        goto L_808005A4;
    // 0x8080059C: addiu       $v0, $zero, 0x1435
    ctx->r2 = ADD32(0, 0X1435);
L_808005A0:
    // 0x808005A0: addiu       $v0, $zero, 0x1434
    ctx->r2 = ADD32(0, 0X1434);
L_808005A4:
    // 0x808005A4: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x808005A8: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x808005AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808005B0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808005B4: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x808005B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005BC: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x808005C0: jal         0x80802730
    // 0x808005C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80802730_chfantasyathlete(rdram, ctx);
        goto after_29;
    // 0x808005C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_29:
    // 0x808005C8: b           L_80800928
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_808005D4:
    // 0x808005D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005D8: addiu       $t2, $zero, 0x13E4
    ctx->r10 = ADD32(0, 0X13E4);
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x808005E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808005E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808005EC: addiu       $a1, $zero, 0x3DA
    ctx->r5 = ADD32(0, 0X3DA);
    // 0x808005F0: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x808005F4: jal         0x80802730
    // 0x808005F8: addiu       $a3, $zero, 0x13E3
    ctx->r7 = ADD32(0, 0X13E3);
    func_80802730_chfantasyathlete(rdram, ctx);
        goto after_30;
    // 0x808005F8: addiu       $a3, $zero, 0x13E3
    ctx->r7 = ADD32(0, 0X13E3);
    after_30:
    // 0x808005FC: b           L_80800928
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800604:
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800608: jal         0x80105B0C
    // 0x8080060C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80105B0C(rdram, ctx);
        goto after_31;
    // 0x8080060C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_31:
    // 0x80800610: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800614: jal         0x80802950
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802950_chfantasyathlete(rdram, ctx);
        goto after_32;
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x8080061C: b           L_80800928
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800624:
    // 0x80800624: lwc1        $f8, 0x4C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: addiu       $a1, $v1, 0x34
    ctx->r5 = ADD32(ctx->r3, 0X34);
    // 0x80800630: addiu       $a2, $v1, 0x40
    ctx->r6 = ADD32(ctx->r3, 0X40);
    // 0x80800634: addiu       $a3, $v1, 0x28
    ctx->r7 = ADD32(ctx->r3, 0X28);
    // 0x80800638: jal         0x8080298C
    // 0x8080063C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8080298C_chfantasyathlete(rdram, ctx);
        goto after_33;
    // 0x8080063C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_33:
    // 0x80800640: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x80800644: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: jal         0x8080094C
    // 0x8080064C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_34;
    // 0x8080064C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_34:
    // 0x80800650: jal         0x800DA544
    // 0x80800654: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    func_800DA544(rdram, ctx);
        goto after_35;
    // 0x80800654: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    after_35:
    // 0x80800658: b           L_80800928
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800660:
    // 0x80800660: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800664: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800670: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800674: addiu       $a3, $zero, 0x13E7
    ctx->r7 = ADD32(0, 0X13E7);
    // 0x80800678: jal         0x80802730
    // 0x8080067C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80802730_chfantasyathlete(rdram, ctx);
        goto after_36;
    // 0x8080067C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_36:
    // 0x80800680: b           L_80800928
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800688:
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800694: addiu       $a3, $zero, 0x13E6
    ctx->r7 = ADD32(0, 0X13E6);
    // 0x80800698: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080069C: jal         0x80802730
    // 0x808006A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80802730_chfantasyathlete(rdram, ctx);
        goto after_37;
    // 0x808006A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_37:
    // 0x808006A4: b           L_80800928
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006AC:
    // 0x808006AC: jal         0x80802950
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802950_chfantasyathlete(rdram, ctx);
        goto after_38;
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x808006B4: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x808006B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006BC: jal         0x8080094C
    // 0x808006C0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_39;
    // 0x808006C0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_39:
    // 0x808006C4: b           L_80800928
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006CC:
    // 0x808006CC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808006D0: jal         0x8010C9B0
    // 0x808006D4: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010C9B0(rdram, ctx);
        goto after_40;
    // 0x808006D4: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_40:
    // 0x808006D8: beq         $v0, $zero, L_808006EC
    if (ctx->r2 == 0) {
        // 0x808006DC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808006EC;
    }
    // 0x808006DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808006E0: jal         0x80016B30
    // 0x808006E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_41;
    // 0x808006E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x808006E8: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x808006EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
L_808006EC:
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F0: jal         0x8080094C
    // 0x808006F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_42;
    // 0x808006F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_42:
    // 0x808006F8: b           L_80800928
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800700:
    // 0x80800700: jal         0x80802950
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802950_chfantasyathlete(rdram, ctx);
        goto after_43;
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80800708: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x8080070C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: jal         0x8080094C
    // 0x80800714: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_44;
    // 0x80800714: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_44:
    // 0x80800718: b           L_80800928
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800720:
    // 0x80800720: jal         0x800F54E4
    // 0x80800724: nop

    func_800F54E4(rdram, ctx);
        goto after_45;
    // 0x80800724: nop

    after_45:
    // 0x80800728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080072C: jal         0x800F549C
    // 0x80800730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800F549C(rdram, ctx);
        goto after_46;
    // 0x80800730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_46:
    // 0x80800734: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: addiu       $a1, $zero, 0x3DB
    ctx->r5 = ADD32(0, 0X3DB);
    // 0x80800740: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800744: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80800748: addiu       $a3, $zero, 0x13E8
    ctx->r7 = ADD32(0, 0X13E8);
    // 0x8080074C: addiu       $t6, $zero, 0x13E9
    ctx->r14 = ADD32(0, 0X13E9);
    // 0x80800750: bc1f        L_80800784
    if (!c1cs) {
        // 0x80800754: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800784;
    }
    // 0x80800754: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800758: addiu       $t4, $zero, 0x1437
    ctx->r12 = ADD32(0, 0X1437);
    // 0x8080075C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800760: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80800764: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080076C: addiu       $a1, $zero, 0x448
    ctx->r5 = ADD32(0, 0X448);
    // 0x80800770: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80800774: jal         0x80802730
    // 0x80800778: addiu       $a3, $zero, 0x1437
    ctx->r7 = ADD32(0, 0X1437);
    func_80802730_chfantasyathlete(rdram, ctx);
        goto after_47;
    // 0x80800778: addiu       $a3, $zero, 0x1437
    ctx->r7 = ADD32(0, 0X1437);
    after_47:
    // 0x8080077C: b           L_80800928
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800784:
    // 0x80800784: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800788: jal         0x80802730
    // 0x8080078C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_80802730_chfantasyathlete(rdram, ctx);
        goto after_48;
    // 0x8080078C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_48:
    // 0x80800790: b           L_80800928
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800798:
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080079C: jal         0x80105B0C
    // 0x808007A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80105B0C(rdram, ctx);
        goto after_49;
    // 0x808007A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_49:
    // 0x808007A4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808007A8: jal         0x80802950
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802950_chfantasyathlete(rdram, ctx);
        goto after_50;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x808007B0: b           L_80800928
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007B8:
    // 0x808007B8: lwc1        $f16, 0x74($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X74);
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C0: addiu       $a1, $v1, 0x5C
    ctx->r5 = ADD32(ctx->r3, 0X5C);
    // 0x808007C4: addiu       $a2, $v1, 0x68
    ctx->r6 = ADD32(ctx->r3, 0X68);
    // 0x808007C8: addiu       $a3, $v1, 0x50
    ctx->r7 = ADD32(ctx->r3, 0X50);
    // 0x808007CC: jal         0x8080298C
    // 0x808007D0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_8080298C_chfantasyathlete(rdram, ctx);
        goto after_51;
    // 0x808007D0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_51:
    // 0x808007D4: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x808007D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007DC: jal         0x8080094C
    // 0x808007E0: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_52;
    // 0x808007E0: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_52:
    // 0x808007E4: b           L_80800928
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007EC:
    // 0x808007EC: jal         0x800FCCD4
    // 0x808007F0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FCCD4(rdram, ctx);
        goto after_53;
    // 0x808007F0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_53:
    // 0x808007F4: bnel        $v0, $zero, L_80800928
    if (ctx->r2 != 0) {
        // 0x808007F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800928;
    }
    goto skip_7;
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_7:
    // 0x808007FC: jal         0x800FCCD4
    // 0x80800800: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FCCD4(rdram, ctx);
        goto after_54;
    // 0x80800800: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_54:
    // 0x80800804: bnel        $v0, $zero, L_80800928
    if (ctx->r2 != 0) {
        // 0x80800808: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800928;
    }
    goto skip_8;
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_8:
    // 0x8080080C: jal         0x800EA05C
    // 0x80800810: nop

    func_800EA05C(rdram, ctx);
        goto after_55;
    // 0x80800810: nop

    after_55:
    // 0x80800814: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800818: jal         0x80087A58
    // 0x8080081C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_56;
    // 0x8080081C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_56:
    // 0x80800820: b           L_80800928
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800828:
    // 0x80800828: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080082C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800838: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080083C: addiu       $a3, $zero, 0x13EC
    ctx->r7 = ADD32(0, 0X13EC);
    // 0x80800840: jal         0x80802730
    // 0x80800844: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80802730_chfantasyathlete(rdram, ctx);
        goto after_57;
    // 0x80800844: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_57:
    // 0x80800848: b           L_80800928
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800850:
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080085C: addiu       $a3, $zero, 0x13EB
    ctx->r7 = ADD32(0, 0X13EB);
    // 0x80800860: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800864: jal         0x80802730
    // 0x80800868: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80802730_chfantasyathlete(rdram, ctx);
        goto after_58;
    // 0x80800868: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_58:
    // 0x8080086C: b           L_80800928
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800874:
    // 0x80800874: jal         0x80802950
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802950_chfantasyathlete(rdram, ctx);
        goto after_59;
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x8080087C: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x80800880: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800884: jal         0x8080094C
    // 0x80800888: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_60;
    // 0x80800888: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_60:
    // 0x8080088C: b           L_80800928
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800894:
    // 0x80800894: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800898: jal         0x8010C9B0
    // 0x8080089C: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010C9B0(rdram, ctx);
        goto after_61;
    // 0x8080089C: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_61:
    // 0x808008A0: beq         $v0, $zero, L_808008B4
    if (ctx->r2 == 0) {
        // 0x808008A4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808008B4;
    }
    // 0x808008A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808008A8: jal         0x80016B30
    // 0x808008AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_62;
    // 0x808008AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_62:
    // 0x808008B0: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x808008B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
L_808008B4:
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B8: jal         0x8080094C
    // 0x808008BC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_63;
    // 0x808008BC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_63:
    // 0x808008C0: b           L_80800928
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008C8:
    // 0x808008C8: jal         0x80801718
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801718_chfantasyathlete(rdram, ctx);
        goto after_64;
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x808008D0: jal         0x80105834
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_65;
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x808008D8: jal         0x80105A5C
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_66;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x808008E0: beql        $v0, $zero, L_80800928
    if (ctx->r2 == 0) {
        // 0x808008E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800928;
    }
    goto skip_9;
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_9:
    // 0x808008E8: jal         0x80802D38
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D38_chfantasyathlete(rdram, ctx);
        goto after_67;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x808008F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F4: jal         0x80800000
    // 0x808008F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_chfantasyathlete(rdram, ctx);
        goto after_68;
    // 0x808008F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_68:
    // 0x808008FC: jal         0x800FFA88
    // 0x80800900: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_69;
    // 0x80800900: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_69:
    // 0x80800904: b           L_80800928
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800928;
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080090C:
    // 0x8080090C: jal         0x80101DDC
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_70;
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_70:
    // 0x80800914: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x80800918: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x80800918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080091C: jal         0x8080094C
    // 0x80800920: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_8080094C_chfantasyathlete(rdram, ctx);
        goto after_71;
    // 0x80800920: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_71:
L_80800924:
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800928:
    // 0x80800928: jal         0x8010C908
    // 0x8080092C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_8010C908(rdram, ctx);
        goto after_72;
    // 0x8080092C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_72:
    // 0x80800930: jal         0x80801974
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801974_chfantasyathlete(rdram, ctx);
        goto after_73;
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_73:
    // 0x80800938: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080093C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800940: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800944: jr          $ra
    // 0x80800948: nop

    return;
    // 0x80800948: nop

;}
RECOMP_FUNC void func_80800624_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800628: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080062C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800630: jal         0x80103EF4
    // 0x80800634: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80103EF4(rdram, ctx);
        goto after_0;
    // 0x80800634: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800638: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080063C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800640: addiu       $t6, $zero, 0x20AE
    ctx->r14 = ADD32(0, 0X20AE);
    // 0x80800644: addiu       $t7, $zero, 0xA08
    ctx->r15 = ADD32(0, 0XA08);
    // 0x80800648: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080064C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: jal         0x80086898
    // 0x80800658: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800658: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_1:
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800660: jal         0x800868A8
    // 0x80800664: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800664: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_2:
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: jal         0x800868B0
    // 0x80800670: lui         $a1, 0x40E0
    ctx->r5 = S32(0X40E0 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800670: lui         $a1, 0x40E0
    ctx->r5 = S32(0X40E0 << 16);
    after_3:
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: jal         0x800868C0
    // 0x8080067C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x8080067C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800688: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080068C: jal         0x800868C8
    // 0x80800690: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800690: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_5:
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080069C: jal         0x800868D0
    // 0x808006A0: addiu       $a2, $zero, 0x19C
    ctx->r6 = ADD32(0, 0X19C);
    _chdoormake_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x808006A0: addiu       $a2, $zero, 0x19C
    ctx->r6 = ADD32(0, 0X19C);
    after_6:
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006AC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x808006B0: jal         0x800868C8
    // 0x808006B4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808006B4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_7:
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006C0: jal         0x800868D0
    // 0x808006C4: addiu       $a2, $zero, 0x19D
    ctx->r6 = ADD32(0, 0X19D);
    _chdoormake_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x808006C4: addiu       $a2, $zero, 0x19D
    ctx->r6 = ADD32(0, 0X19D);
    after_8:
    // 0x808006C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006D4: jr          $ra
    // 0x808006D8: nop

    return;
    // 0x808006D8: nop

;}
RECOMP_FUNC void func_800E46A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E46A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E46A8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800E46AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E46B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E46B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E46B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E46BC: jal         0x800F2D34
    // 0x800E46C0: addiu       $a0, $a0, -0x2AF0
    ctx->r4 = ADD32(ctx->r4, -0X2AF0);
    func_800F2D34(rdram, ctx);
        goto after_0;
    // 0x800E46C0: addiu       $a0, $a0, -0x2AF0
    ctx->r4 = ADD32(ctx->r4, -0X2AF0);
    after_0:
    // 0x800E46C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E46C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E46CC: jr          $ra
    // 0x800E46D0: nop

    return;
    // 0x800E46D0: nop

;}
RECOMP_FUNC void func_80800014_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800020: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800024: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080002C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800030: bnel        $t7, $at, L_80800068
    if (ctx->r15 != ctx->r1) {
        // 0x80800034: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800068;
    }
    goto skip_0;
    // 0x80800034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800038: jal         0x808002FC
    // 0x8080003C: nop

    func_808002FC_chexploder(rdram, ctx);
        goto after_0;
    // 0x8080003C: nop

    after_0:
    // 0x80800040: bne         $v0, $zero, L_80800064
    if (ctx->r2 != 0) {
        // 0x80800044: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800064;
    }
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: jal         0x80101FDC
    // 0x8080004C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x8080004C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800050: jal         0x80089CA8
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: jal         0x8010A800
    // 0x80800060: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_3;
    // 0x80800060: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_80800064:
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800068:
    // 0x80800068: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080006C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_80801760_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801760: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80801764: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2484, 0X71B1) << 16);
    // 0x80801768: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x8080176C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80801770: lw          $t7, 0x64($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X64);
    // 0x80801774: lb          $t8, 0x71B1($t8)
    ctx->r24 = MEM_B(ctx->r24, (int16_t)RELOC_LO16(2484, 0X71B1));
    // 0x80801778: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8080177C: jr          $ra
    // 0x80801780: sw          $t9, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r25;
    return;
    // 0x80801780: sw          $t9, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void fxairbub_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800028: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800030: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800034: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800038: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8080003C: jal         0x800B5BE4
    // 0x80800040: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800040: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80800044: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800048: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800050: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800054: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800058: nop

    // 0x8080005C: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80800060: jal         0x800BA568
    // 0x80800064: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    func_800BA568(rdram, ctx);
        goto after_1;
    // 0x80800064: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80800068: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080006C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800074: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80800078: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080007C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800080: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800084: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80800088: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080008C: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80800090: sra         $v0, $t4, 16
    ctx->r2 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80800094: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x80800098: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8080009C: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x808000A0: sra         $t2, $a3, 16
    ctx->r10 = S32(SIGNED(ctx->r7) >> 16);
    // 0x808000A4: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x808000A8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808000AC: jal         0x800BA6B0
    // 0x808000B0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800BA6B0(rdram, ctx);
        goto after_2;
    // 0x808000B0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x808000B4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x808000B8: addiu       $a1, $a1, -0x7638
    ctx->r5 = ADD32(ctx->r5, -0X7638);
    // 0x808000BC: jal         0x800BA544
    // 0x808000C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800BA544(rdram, ctx);
        goto after_3;
    // 0x808000C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x808000C4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2822, 0X100) << 16);
    // 0x808000C8: addiu       $t6, $t6, 0x100
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2822, 0X100));
    // 0x808000CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808000D4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808000D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000DC: jal         0x800BABB8
    // 0x808000E0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x808000E0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x808000E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

    // 0x808000F4: nop

    // 0x808000F8: nop

    // 0x808000FC: nop

;}
RECOMP_FUNC void chdiggerboss_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808035AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808035B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808035B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808035B8: jal         0x80106790
    // 0x808035BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808035BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808035C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808035C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808035C8: jal         0x80100094
    // 0x808035CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808035CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808035D0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808035D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808035D8: jal         0x80100094
    // 0x808035DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808035DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808035E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808035E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808035E8: addiu       $a0, $v0, 0x10C
    ctx->r4 = ADD32(ctx->r2, 0X10C);
    // 0x808035EC: lbu         $t7, 0x40($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X40);
    // 0x808035F0: bnel        $t7, $at, L_80803604
    if (ctx->r15 != ctx->r1) {
        // 0x808035F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803604;
    }
    goto skip_0;
    // 0x808035F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808035F8: jal         0x80087DC0
    // 0x808035FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_3;
    // 0x808035FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80803600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803604:
    // 0x80803604: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803608: jr          $ra
    // 0x8080360C: nop

    return;
    // 0x8080360C: nop

;}
RECOMP_FUNC void func_80800CC4_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800CC8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800CCC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800CD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800CD4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800CD8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800CDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800CE0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80800CE4: jal         0x80100094
    // 0x80800CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CEC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800CF0: addiu       $at, $zero, 0xF18
    ctx->r1 = ADD32(0, 0XF18);
    // 0x80800CF4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800CF8: beq         $a2, $at, L_80800D20
    if (ctx->r6 == ctx->r1) {
        // 0x80800CFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D20;
    }
    // 0x80800CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D00: addiu       $at, $zero, 0xF42
    ctx->r1 = ADD32(0, 0XF42);
    // 0x80800D04: beq         $a2, $at, L_80800D50
    if (ctx->r6 == ctx->r1) {
        // 0x80800D08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D50;
    }
    // 0x80800D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D0C: addiu       $at, $zero, 0xF4F
    ctx->r1 = ADD32(0, 0XF4F);
    // 0x80800D10: beq         $a2, $at, L_80800D68
    if (ctx->r6 == ctx->r1) {
        // 0x80800D14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D68;
    }
    // 0x80800D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D18: b           L_80800D84
    // 0x80800D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800D84;
    // 0x80800D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D20:
    // 0x80800D20: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800D24: jal         0x80102424
    // 0x80800D28: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800D28: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800D2C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D34: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800D38: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    // 0x80800D3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800D40: jal         0x8008A2D0
    // 0x80800D44: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800D44: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    after_2:
    // 0x80800D48: b           L_80800D9C
    // 0x80800D4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D9C;
    // 0x80800D4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D50:
    // 0x80800D50: jal         0x8008A2C0
    // 0x80800D54: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800D54: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    after_3:
    // 0x80800D58: jal         0x80088830
    // 0x80800D5C: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x80800D5C: nop

    after_4:
    // 0x80800D60: b           L_80800D9C
    // 0x80800D64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D9C;
    // 0x80800D64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D68:
    // 0x80800D68: jal         0x8008A2C0
    // 0x80800D6C: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800D6C: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    after_5:
    // 0x80800D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D74: jal         0x80102424
    // 0x80800D78: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800D78: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800D7C: b           L_80800D9C
    // 0x80800D80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D9C;
    // 0x80800D80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D84:
    // 0x80800D84: jal         0x8008A2C0
    // 0x80800D88: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800D88: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    after_7:
    // 0x80800D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D90: jal         0x80102424
    // 0x80800D94: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800D94: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800D98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D9C:
    // 0x80800D9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800DA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800DA4: jr          $ra
    // 0x80800DA8: nop

    return;
    // 0x80800DA8: nop

;}
RECOMP_FUNC void func_80108ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108ED0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80108ED4: jr          $ra
    // 0x80108ED8: addiu       $v0, $v0, 0x45D0
    ctx->r2 = ADD32(ctx->r2, 0X45D0);
    return;
    // 0x80108ED8: addiu       $v0, $v0, 0x45D0
    ctx->r2 = ADD32(ctx->r2, 0X45D0);
;}
RECOMP_FUNC void func_808004E0_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004E8: jal         0x800A587C
    // 0x808004EC: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x808004EC: nop

    after_0:
    // 0x808004F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808004F4: beq         $v0, $at, L_8080050C
    if (ctx->r2 == ctx->r1) {
        // 0x808004F8: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8080050C;
    }
    // 0x808004F8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808004FC: beq         $v0, $at, L_8080051C
    if (ctx->r2 == ctx->r1) {
        // 0x80800500: nop
    
            goto L_8080051C;
    }
    // 0x80800500: nop

    // 0x80800504: b           L_8080052C
    // 0x80800508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080052C;
    // 0x80800508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080050C:
    // 0x8080050C: jal         0x800A586C
    // 0x80800510: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800510: nop

    after_1:
    // 0x80800514: b           L_8080052C
    // 0x80800518: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
        goto L_8080052C;
    // 0x80800518: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
L_8080051C:
    // 0x8080051C: jal         0x800A586C
    // 0x80800520: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x80800520: nop

    after_2:
    // 0x80800524: b           L_8080052C
    // 0x80800528: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_8080052C;
    // 0x80800528: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_8080052C:
    // 0x8080052C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800534: jr          $ra
    // 0x80800538: nop

    return;
    // 0x80800538: nop

;}
RECOMP_FUNC void func_8001BDAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BDAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001BDB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001BDB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001BDB8: jal         0x8001B3E8
    // 0x8001BDBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    heap_bytes_allocated(rdram, ctx);
        goto after_0;
    // 0x8001BDBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001BDC0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001BDC4: lw          $a0, -0x1670($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1670);
    // 0x8001BDC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BDCC: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x8001BDD0: beq         $a1, $zero, L_8001BE6C
    if (ctx->r5 == 0) {
        // 0x8001BDD4: addiu       $v1, $v1, -0x20
        ctx->r3 = ADD32(ctx->r3, -0X20);
            goto L_8001BE6C;
    }
    // 0x8001BDD4: addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
    // 0x8001BDD8: andi        $a2, $a1, 0x3
    ctx->r6 = ctx->r5 & 0X3;
    // 0x8001BDDC: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x8001BDE0: beq         $a2, $zero, L_8001BE10
    if (ctx->r6 == 0) {
        // 0x8001BDE4: addu        $v0, $a2, $a1
        ctx->r2 = ADD32(ctx->r6, ctx->r5);
            goto L_8001BE10;
    }
    // 0x8001BDE4: addu        $v0, $a2, $a1
    ctx->r2 = ADD32(ctx->r6, ctx->r5);
    // 0x8001BDE8: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
L_8001BDEC:
    // 0x8001BDEC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001BDF0: bne         $v1, $a0, L_8001BE00
    if (ctx->r3 != ctx->r4) {
        // 0x8001BDF4: nop
    
            goto L_8001BE00;
    }
    // 0x8001BDF4: nop

    // 0x8001BDF8: b           L_8001BE84
    // 0x8001BDFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BE84;
    // 0x8001BDFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BE00:
    // 0x8001BE00: bnel        $v0, $a1, L_8001BDEC
    if (ctx->r2 != ctx->r5) {
        // 0x8001BE04: lw          $v1, 0x10($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X10);
            goto L_8001BDEC;
    }
    goto skip_0;
    // 0x8001BE04: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x8001BE08: beql        $a1, $zero, L_8001BE70
    if (ctx->r5 == 0) {
        // 0x8001BE0C: lw          $t6, 0x4($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X4);
            goto L_8001BE70;
    }
    goto skip_1;
    // 0x8001BE0C: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    skip_1:
L_8001BE10:
    // 0x8001BE10: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
L_8001BE14:
    // 0x8001BE14: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8001BE18: bnel        $v1, $a0, L_8001BE2C
    if (ctx->r3 != ctx->r4) {
        // 0x8001BE1C: lw          $v1, 0x10($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X10);
            goto L_8001BE2C;
    }
    goto skip_2;
    // 0x8001BE1C: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
    skip_2:
    // 0x8001BE20: b           L_8001BE84
    // 0x8001BE24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BE84;
    // 0x8001BE24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BE28: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
L_8001BE2C:
    // 0x8001BE2C: bnel        $v1, $a0, L_8001BE40
    if (ctx->r3 != ctx->r4) {
        // 0x8001BE30: lw          $v1, 0x10($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X10);
            goto L_8001BE40;
    }
    goto skip_3;
    // 0x8001BE30: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
    skip_3:
    // 0x8001BE34: b           L_8001BE84
    // 0x8001BE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BE84;
    // 0x8001BE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BE3C: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
L_8001BE40:
    // 0x8001BE40: bnel        $v1, $a0, L_8001BE54
    if (ctx->r3 != ctx->r4) {
        // 0x8001BE44: lw          $v1, 0x10($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X10);
            goto L_8001BE54;
    }
    goto skip_4;
    // 0x8001BE44: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
    skip_4:
    // 0x8001BE48: b           L_8001BE84
    // 0x8001BE4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BE84;
    // 0x8001BE4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BE50: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
L_8001BE54:
    // 0x8001BE54: bne         $v1, $a0, L_8001BE64
    if (ctx->r3 != ctx->r4) {
        // 0x8001BE58: nop
    
            goto L_8001BE64;
    }
    // 0x8001BE58: nop

    // 0x8001BE5C: b           L_8001BE84
    // 0x8001BE60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BE84;
    // 0x8001BE60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BE64:
    // 0x8001BE64: bnel        $a1, $zero, L_8001BE14
    if (ctx->r5 != 0) {
        // 0x8001BE68: lw          $v1, 0x10($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X10);
            goto L_8001BE14;
    }
    goto skip_5;
    // 0x8001BE68: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
    skip_5:
L_8001BE6C:
    // 0x8001BE6C: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
L_8001BE70:
    // 0x8001BE70: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8001BE74: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8001BE78: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x8001BE7C: addiu       $t8, $t7, -0x10
    ctx->r24 = ADD32(ctx->r15, -0X10);
    // 0x8001BE80: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_8001BE84:
    // 0x8001BE84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001BE88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001BE8C: jr          $ra
    // 0x8001BE90: nop

    return;
    // 0x8001BE90: nop

;}
RECOMP_FUNC void _glglobalsettings_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088700: syscall     699
    recomp_syscall_handler(rdram, ctx, 0x80088700);
    return;
    // 0x80088704: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_808008C8_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808008CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808008D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808008D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808008DC: jal         0x80100094
    // 0x808008E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008E4: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x808008E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808008EC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808008F0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808008F4: bltzl       $t8, L_8080097C
    if (SIGNED(ctx->r24) < 0) {
        // 0x808008F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080097C;
    }
    goto skip_0;
    // 0x808008F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808008FC: jal         0x800F5A00
    // 0x80800900: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80800900: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    after_1:
    // 0x80800904: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1852, 0X557C) << 16);
    // 0x80800908: addiu       $a0, $a0, 0x557C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1852, 0X557C));
    // 0x8080090C: jal         0x800F1DF4
    // 0x80800910: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F1DF4(rdram, ctx);
        goto after_2;
    // 0x80800910: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800914: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800918: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8080091C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80800920: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x80800924: lbu         $a1, 0x55($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X55);
    // 0x80800928: swc1        $f2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f2.u32l;
    // 0x8080092C: jal         0x808005A4
    // 0x80800930: swc1        $f2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f2.u32l;
    func_808005A4_chdragonbrothers(rdram, ctx);
        goto after_3;
    // 0x80800930: swc1        $f2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f2.u32l;
    after_3:
    // 0x80800934: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x80800938: jal         0x808005A4
    // 0x8080093C: lbu         $a1, 0x55($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X55);
    func_808005A4_chdragonbrothers(rdram, ctx);
        goto after_4;
    // 0x8080093C: lbu         $a1, 0x55($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X55);
    after_4:
    // 0x80800940: jal         0x800F5EF8
    // 0x80800944: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800F5EF8(rdram, ctx);
        goto after_5;
    // 0x80800944: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_5:
    // 0x80800948: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080094C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80800950: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800954: jal         0x80089540
    // 0x80800958: addiu       $a3, $zero, 0x804
    ctx->r7 = ADD32(0, 0X804);
    _ncpod_entrypoint_16(rdram, ctx);
        goto after_6;
    // 0x80800958: addiu       $a3, $zero, 0x804
    ctx->r7 = ADD32(0, 0X804);
    after_6:
    // 0x8080095C: lbu         $t0, 0x74($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X74);
    // 0x80800960: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800964: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x80800968: jal         0x808006C8
    // 0x8080096C: sb          $t1, 0x74($s1)
    MEM_B(0X74, ctx->r17) = ctx->r9;
    func_808006C8_chdragonbrothers(rdram, ctx);
        goto after_7;
    // 0x8080096C: sb          $t1, 0x74($s1)
    MEM_B(0X74, ctx->r17) = ctx->r9;
    after_7:
    // 0x80800970: jal         0x800A5144
    // 0x80800974: nop

    func_800A5144(rdram, ctx);
        goto after_8;
    // 0x80800974: nop

    after_8:
    // 0x80800978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080097C:
    // 0x8080097C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800980: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800984: jr          $ra
    // 0x80800988: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800988: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _glcutDll_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088820: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088820);
    return;
    // 0x80088824: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_80800C98_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CA0: jal         0x808001FC
    // 0x80800CA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001FC_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80800CA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CA8: jal         0x800839C8
    // 0x80800CAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800CAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800CB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800CB4: jal         0x80800000
    // 0x80800CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_bsstatue(rdram, ctx);
        goto after_2;
    // 0x80800CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CC4: jr          $ra
    // 0x80800CC8: nop

    return;
    // 0x80800CC8: nop

;}
RECOMP_FUNC void func_800F4AF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4AF4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4AF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4AFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4B04: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4B08: jal         0x800A4DA4
    // 0x800F4B0C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A4DA4(rdram, ctx);
        goto after_0;
    // 0x800F4B0C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4B18: jr          $ra
    // 0x800F4B1C: nop

    return;
    // 0x800F4B1C: nop

;}
RECOMP_FUNC void func_80800364_chtimetable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800368: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080036C: ori         $t7, $a2, 0x6
    ctx->r15 = ctx->r6 | 0X6;
    // 0x80800370: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800374: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800378: bne         $a1, $zero, L_808003C4
    if (ctx->r5 != 0) {
        // 0x8080037C: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_808003C4;
    }
    // 0x8080037C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80800380: jal         0x800DA298
    // 0x80800384: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800384: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_0:
    // 0x80800388: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x8080038C: addiu       $a1, $zero, 0xCF3
        ctx->r5 = ADD32(0, 0XCF3);
            goto L_808003C4;
    }
    // 0x8080038C: addiu       $a1, $zero, 0xCF3
    ctx->r5 = ADD32(0, 0XCF3);
    // 0x80800390: jal         0x80800308
    // 0x80800394: nop

    func_80800308_chtimetable(rdram, ctx);
        goto after_1;
    // 0x80800394: nop

    after_1:
    // 0x80800398: jal         0x800EA05C
    // 0x8080039C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x8080039C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x808003A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808003A4: bne         $a0, $v0, L_808003B4
    if (ctx->r4 != ctx->r2) {
        // 0x808003A8: nop
    
            goto L_808003B4;
    }
    // 0x808003A8: nop

    // 0x808003AC: b           L_808003C4
    // 0x808003B0: addiu       $a1, $zero, 0xCF4
    ctx->r5 = ADD32(0, 0XCF4);
        goto L_808003C4;
    // 0x808003B0: addiu       $a1, $zero, 0xCF4
    ctx->r5 = ADD32(0, 0XCF4);
L_808003B4:
    // 0x808003B4: jal         0x808002D4
    // 0x808003B8: nop

    func_808002D4_chtimetable(rdram, ctx);
        goto after_3;
    // 0x808003B8: nop

    after_3:
    // 0x808003BC: b           L_808003C4
    // 0x808003C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_808003C4;
    // 0x808003C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808003C4:
    // 0x808003C4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808003C8: addiu       $t9, $zero, 0x42
    ctx->r25 = ADD32(0, 0X42);
    // 0x808003CC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x808003D0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x808003D4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808003D8: jal         0x8008A208
    // 0x808003DC: addiu       $a3, $t8, 0x4
    ctx->r7 = ADD32(ctx->r24, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808003DC: addiu       $a3, $t8, 0x4
    ctx->r7 = ADD32(ctx->r24, 0X4);
    after_4:
    // 0x808003E0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808003E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808003E8: lbu         $t2, 0x74($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X74);
    // 0x808003EC: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x808003F0: sb          $t3, 0x74($t0)
    MEM_B(0X74, ctx->r8) = ctx->r11;
    // 0x808003F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003FC: jr          $ra
    // 0x80800400: nop

    return;
    // 0x80800400: nop

;}
RECOMP_FUNC void _chlagoonbits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FD8: syscall     268
    recomp_syscall_handler(rdram, ctx, 0x80085FD8);
    return;
    // 0x80085FDC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _sucoasterflydata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A278: syscall     832
    recomp_syscall_handler(rdram, ctx, 0x8008A278);
    return;
    // 0x8008A27C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bschokedie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E98: syscall     32
    recomp_syscall_handler(rdram, ctx, 0x80082E98);
    return;
    // 0x80082E9C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008B28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B28C: lbu         $v0, 0x1B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008B290: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x8008B294: jr          $ra
    // 0x8008B298: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8008B298: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_80800000_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800004: lbu         $t6, 0x7611($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7611);
    // 0x80800008: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080000C: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x80800010: bne         $t6, $at, L_8080002C
    if (ctx->r14 != ctx->r1) {
        // 0x80800014: lui         $v0, 0x8080
        ctx->r2 = S32(RELOC_HI16(1636, 0X1208) << 16);
            goto L_8080002C;
    }
    // 0x80800014: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1636, 0X1208) << 16);
    // 0x80800018: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8080001C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1636, 0X12C0) << 16);
    // 0x80800020: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80800024: jr          $ra
    // 0x80800028: lh          $v0, 0x12C0($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1636, 0X12C0));
    return;
    // 0x80800028: lh          $v0, 0x12C0($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1636, 0X12C0));
L_8080002C:
    // 0x8080002C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800030: lh          $v0, 0x1208($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1636, 0X1208));
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void _chalienkids_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086570: syscall     337
    recomp_syscall_handler(rdram, ctx, 0x80086570);
    return;
    // 0x80086574: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80804104_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804104: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804108: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080410C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804110: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80804114: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80804118: lh          $a3, 0x0($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X0);
    // 0x8080411C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804120: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x80804124: beq         $a3, $zero, L_80804134
    if (ctx->r7 == 0) {
        // 0x80804128: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80804134;
    }
    // 0x80804128: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8080412C: jal         0x80800424
    // 0x80804130: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    func_80800424_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804130: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    after_0:
L_80804134:
    // 0x80804134: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80804138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080413C: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x80804140: jal         0x8008CCBC
    // 0x80804144: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80804144: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    after_1:
    // 0x80804148: jal         0x800FC660
    // 0x8080414C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x8080414C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x80804150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804154: jal         0x80802A40
    // 0x80804158: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80802A40_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80804158: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
    // 0x8080415C: bne         $v0, $zero, L_8080416C
    if (ctx->r2 != 0) {
        // 0x80804160: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080416C;
    }
    // 0x80804160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804164: jal         0x8009D89C
    // 0x80804168: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009D89C(rdram, ctx);
        goto after_4;
    // 0x80804168: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
L_8080416C:
    // 0x8080416C: jal         0x800854C0
    // 0x80804170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bainvisible_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80804170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80804174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804178: jal         0x8009B9B0
    // 0x8080417C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x8080417C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80804180: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80804184: jal         0x80808F38
    // 0x80804188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808F38_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80804188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080418C: jal         0x800D3948
    // 0x80804190: nop

    func_800D3948(rdram, ctx);
        goto after_8;
    // 0x80804190: nop

    after_8:
    // 0x80804194: bne         $v0, $zero, L_808041A4
    if (ctx->r2 != 0) {
        // 0x80804198: nop
    
            goto L_808041A4;
    }
    // 0x80804198: nop

    // 0x8080419C: jal         0x80085208
    // 0x808041A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808041A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_808041A4:
    // 0x808041A4: jal         0x800EA068
    // 0x808041A8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800EA068(rdram, ctx);
        goto after_10;
    // 0x808041A8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_10:
    // 0x808041AC: bne         $v0, $zero, L_808041BC
    if (ctx->r2 != 0) {
        // 0x808041B0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808041BC;
    }
    // 0x808041B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808041B4: jal         0x800F7E64
    // 0x808041B8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F7E64(rdram, ctx);
        goto after_11;
    // 0x808041B8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_11:
L_808041BC:
    // 0x808041BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808041C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808041C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808041C8: jr          $ra
    // 0x808041CC: nop

    return;
    // 0x808041CC: nop

;}
RECOMP_FUNC void _bsstand_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B80: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B80);
    return;
    // 0x80083B84: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_8008B2D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B2D4: jr          $ra
    // 0x8008B2D8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    return;
    // 0x8008B2D8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
;}
RECOMP_FUNC void func_80808CD0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808CD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80808CD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808CD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80808CDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808CE0: jal         0x80100094
    // 0x80808CE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808CE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808CE8: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0XA1E8) << 16);
    // 0x80808CEC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80808CF0: addiu       $a3, $a3, -0x5E18
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0XA1E8));
    // 0x80808CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80808CFC: jal         0x80808D54
    // 0x80808D00: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    func_80808D54_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80808D00: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_1:
    // 0x80808D04: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0XA1DC) << 16);
    // 0x80808D08: addiu       $a3, $a3, -0x5E24
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0XA1DC));
    // 0x80808D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80808D14: jal         0x80808D54
    // 0x80808D18: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80808D54_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80808D18: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x80808D1C: jal         0x80808F44
    // 0x80808D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808F44_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80808D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80808D24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80808D28: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80808D2C: jal         0x800EE7F8
    // 0x80808D30: addiu       $a0, $a0, 0xD4
    ctx->r4 = ADD32(ctx->r4, 0XD4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80808D30: addiu       $a0, $a0, 0xD4
    ctx->r4 = ADD32(ctx->r4, 0XD4);
    after_4:
    // 0x80808D34: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80808D38: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80808D3C: swc1        $f4, 0xE0($t6)
    MEM_W(0XE0, ctx->r14) = ctx->f4.u32l;
    // 0x80808D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80808D44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80808D48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80808D4C: jr          $ra
    // 0x80808D50: nop

    return;
    // 0x80808D50: nop

;}
RECOMP_FUNC void _suchase_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EF8: syscall     814
    recomp_syscall_handler(rdram, ctx, 0x80089EF8);
    return;
    // 0x80089EFC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800018_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: jal         0x80088848
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080002C: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800030: beql        $a2, $zero, L_8080004C
    if (ctx->r6 == 0) {
        // 0x80800034: addiu       $a0, $zero, 0x3AD
        ctx->r4 = ADD32(0, 0X3AD);
            goto L_8080004C;
    }
    goto skip_0;
    // 0x80800034: addiu       $a0, $zero, 0x3AD
    ctx->r4 = ADD32(0, 0X3AD);
    skip_0:
    // 0x80800038: jal         0x80086B18
    // 0x8080003C: nop

    _chcredits_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080003C: nop

    after_1:
    // 0x80800040: xori        $a2, $v0, 0x61
    ctx->r6 = ctx->r2 ^ 0X61;
    // 0x80800044: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x80800048: addiu       $a0, $zero, 0x3AD
    ctx->r4 = ADD32(0, 0X3AD);
L_8080004C:
    // 0x8080004C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800050: jal         0x80088290
    // 0x80800054: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    _gccubesearch_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800054: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x80800058: jal         0x800CBC3C
    // 0x8080005C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800CBC3C(rdram, ctx);
        goto after_3;
    // 0x8080005C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800060: lbu         $t0, 0x70($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X70);
    // 0x80800064: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
    // 0x80800068: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8080006C: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80800070: andi        $t1, $t0, 0xFF01
    ctx->r9 = ctx->r8 & 0XFF01;
    // 0x80800074: andi        $t4, $t3, 0xFC0F
    ctx->r12 = ctx->r11 & 0XFC0F;
    // 0x80800078: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8080007C: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x80800080: sb          $t2, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r10;
    // 0x80800084: sh          $t5, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r13;
    // 0x80800088: jal         0x800DA298
    // 0x8080008C: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x8080008C: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    after_4:
    // 0x80800090: beq         $v0, $zero, L_808000A8
    if (ctx->r2 == 0) {
        // 0x80800094: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_808000A8;
    }
    // 0x80800094: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800098: addiu       $a0, $zero, 0x328
    ctx->r4 = ADD32(0, 0X328);
    // 0x8080009C: jal         0x800DA544
    // 0x808000A0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x808000A0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_5:
    // 0x808000A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_808000A8:
    // 0x808000A8: beq         $a2, $zero, L_808000B8
    if (ctx->r6 == 0) {
        // 0x808000AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000B8;
    }
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: b           L_808000BC
    // 0x808000B4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
        goto L_808000BC;
    // 0x808000B4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
L_808000B8:
    // 0x808000B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_808000BC:
    // 0x808000BC: jal         0x80800654
    // 0x808000C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800654_chdippy(rdram, ctx);
        goto after_6;
    // 0x808000C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_6:
    // 0x808000C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000D0: jr          $ra
    // 0x808000D4: nop

    return;
    // 0x808000D4: nop

;}
RECOMP_FUNC void func_80018BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018BC4: lui         $at, 0xC700
    ctx->r1 = S32(0XC700 << 16);
    // 0x80018BC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80018BCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018BD0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80018BD4: lw          $a0, -0x4350($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4350);
    // 0x80018BD8: lwc1        $f2, 0x1740($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1740);
    // 0x80018BDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80018BE0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_80018BE4:
    // 0x80018BE4: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80018BE8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80018BEC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80018BF0: nop

    // 0x80018BF4: bc1t        L_80018C0C
    if (c1cs) {
        // 0x80018BF8: nop
    
            goto L_80018C0C;
    }
    // 0x80018BF8: nop

    // 0x80018BFC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80018C00: nop

    // 0x80018C04: bc1f        L_80018C14
    if (!c1cs) {
        // 0x80018C08: nop
    
            goto L_80018C14;
    }
    // 0x80018C08: nop

L_80018C0C:
    // 0x80018C0C: jr          $ra
    // 0x80018C10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80018C10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80018C14:
    // 0x80018C14: bne         $v1, $v0, L_80018BE4
    if (ctx->r3 != ctx->r2) {
        // 0x80018C18: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80018BE4;
    }
    // 0x80018C18: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80018C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018C20: jr          $ra
    // 0x80018C24: nop

    return;
    // 0x80018C24: nop

;}
RECOMP_FUNC void func_80800218_chdinofamilymother(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080021C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800220: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800224: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800228: beq         $a1, $at, L_80800414
    if (ctx->r5 == ctx->r1) {
        // 0x8080022C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800414;
    }
    // 0x8080022C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800230: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800234: beq         $a1, $at, L_80800270
    if (ctx->r5 == ctx->r1) {
        // 0x80800238: lh          $v0, 0x30($sp)
        ctx->r2 = MEM_H(ctx->r29, 0X30);
            goto L_80800270;
    }
    // 0x80800238: lh          $v0, 0x30($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X30);
    // 0x8080023C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800240: beq         $a1, $at, L_808002D4
    if (ctx->r5 == ctx->r1) {
        // 0x80800244: addiu       $t1, $v0, -0x180A
        ctx->r9 = ADD32(ctx->r2, -0X180A);
            goto L_808002D4;
    }
    // 0x80800244: addiu       $t1, $v0, -0x180A
    ctx->r9 = ADD32(ctx->r2, -0X180A);
    // 0x80800248: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8080024C: beq         $a1, $at, L_808004D4
    if (ctx->r5 == ctx->r1) {
        // 0x80800250: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_808004D4;
    }
    // 0x80800250: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800254: beq         $a1, $at, L_80800464
    if (ctx->r5 == ctx->r1) {
        // 0x80800258: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(2420, 0X13D0) << 16);
            goto L_80800464;
    }
    // 0x80800258: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2420, 0X13D0) << 16);
    // 0x8080025C: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80800260: beq         $a1, $at, L_80800488
    if (ctx->r5 == ctx->r1) {
        // 0x80800264: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800488;
    }
    // 0x80800264: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800268: b           L_808005DC
    // 0x8080026C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005DC;
    // 0x8080026C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800270:
    // 0x80800270: jal         0x801015D0
    // 0x80800274: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x80800274: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x80800278: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080027C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2420, 0X1344) << 16);
    // 0x80800280: addiu       $at, $zero, 0x3AC
    ctx->r1 = ADD32(0, 0X3AC);
    // 0x80800284: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080028C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800290: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800294: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80800298: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8080029C: lhu         $t0, 0x1344($t0)
    ctx->r8 = MEM_HU(ctx->r8, (int16_t)RELOC_LO16(2420, 0X1344));
    // 0x808002A0: beq         $t0, $at, L_808002C4
    if (ctx->r8 == ctx->r1) {
        // 0x808002A4: nop
    
            goto L_808002C4;
    }
    // 0x808002A4: nop

    // 0x808002A8: jal         0x800DF744
    // 0x808002AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x808002AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x808002B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808002B4: jal         0x800DF744
    // 0x808002B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808002B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808002BC: b           L_808005DC
    // 0x808002C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808002C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002C4:
    // 0x808002C4: jal         0x800DF744
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808002CC: b           L_808005DC
    // 0x808002D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808002D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002D4:
    // 0x808002D4: slti        $at, $v0, 0x17C7
    ctx->r1 = SIGNED(ctx->r2) < 0X17C7 ? 1 : 0;
    // 0x808002D8: bne         $at, $zero, L_80800300
    if (ctx->r1 != 0) {
        // 0x808002DC: addiu       $t2, $v0, -0x17BA
        ctx->r10 = ADD32(ctx->r2, -0X17BA);
            goto L_80800300;
    }
    // 0x808002DC: addiu       $t2, $v0, -0x17BA
    ctx->r10 = ADD32(ctx->r2, -0X17BA);
    // 0x808002E0: sltiu       $at, $t1, 0xF
    ctx->r1 = ctx->r9 < 0XF ? 1 : 0;
    // 0x808002E4: beq         $at, $zero, L_80800404
    if (ctx->r1 == 0) {
        // 0x808002E8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80800404;
    }
    // 0x808002E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808002EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X1294) << 16);
    // 0x808002F0: addu        $at, $at, $t1
    gpr jr_addend_808002F8 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x808002F4: lw          $t1, 0x1294($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2420, 0X1294));
    // 0x808002F8: jr          $t1
    // 0x808002FC: nop

    switch (jr_addend_808002F8 >> 2) {
        case 0: goto L_808003A0; break;
        case 1: goto L_80800404; break;
        case 2: goto L_80800404; break;
        case 3: goto L_80800404; break;
        case 4: goto L_80800404; break;
        case 5: goto L_80800404; break;
        case 6: goto L_80800404; break;
        case 7: goto L_80800404; break;
        case 8: goto L_8080033C; break;
        case 9: goto L_8080033C; break;
        case 10: goto L_8080033C; break;
        case 11: goto L_80800350; break;
        case 12: goto L_80800378; break;
        case 13: goto L_80800378; break;
        case 14: goto L_808003B4; break;
        default: switch_error(__func__, 0x808002F8, 0x80801294);
    }
    // 0x808002FC: nop

L_80800300:
    // 0x80800300: slti        $at, $v0, 0x1209
    ctx->r1 = SIGNED(ctx->r2) < 0X1209 ? 1 : 0;
    // 0x80800304: bne         $at, $zero, L_80800328
    if (ctx->r1 != 0) {
        // 0x80800308: sltiu       $at, $t2, 0xD
        ctx->r1 = ctx->r10 < 0XD ? 1 : 0;
            goto L_80800328;
    }
    // 0x80800308: sltiu       $at, $t2, 0xD
    ctx->r1 = ctx->r10 < 0XD ? 1 : 0;
    // 0x8080030C: beq         $at, $zero, L_80800404
    if (ctx->r1 == 0) {
        // 0x80800310: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80800404;
    }
    // 0x80800310: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800314: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X12D0) << 16);
    // 0x80800318: addu        $at, $at, $t2
    gpr jr_addend_80800320 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8080031C: lw          $t2, 0x12D0($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2420, 0X12D0));
    // 0x80800320: jr          $t2
    // 0x80800324: nop

    switch (jr_addend_80800320 >> 2) {
        case 0: goto L_8080033C; break;
        case 1: goto L_8080033C; break;
        case 2: goto L_80800350; break;
        case 3: goto L_80800364; break;
        case 4: goto L_80800378; break;
        case 5: goto L_8080038C; break;
        case 6: goto L_8080038C; break;
        case 7: goto L_808003A0; break;
        case 8: goto L_808003B4; break;
        case 9: goto L_808003F0; break;
        case 10: goto L_808003F0; break;
        case 11: goto L_808003F0; break;
        case 12: goto L_808003B4; break;
        default: switch_error(__func__, 0x80800320, 0x808012D0);
    }
    // 0x80800324: nop

L_80800328:
    // 0x80800328: addiu       $at, $zero, 0x1208
    ctx->r1 = ADD32(0, 0X1208);
    // 0x8080032C: beq         $v0, $at, L_808003E0
    if (ctx->r2 == ctx->r1) {
        // 0x80800330: nop
    
            goto L_808003E0;
    }
    // 0x80800330: nop

    // 0x80800334: b           L_80800404
    // 0x80800338: nop

        goto L_80800404;
    // 0x80800338: nop

L_8080033C:
    // 0x8080033C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800340: jal         0x808005EC
    // 0x80800344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_4;
    // 0x80800344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800348: b           L_808005DC
    // 0x8080034C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x8080034C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800350:
    // 0x80800350: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800354: jal         0x808005EC
    // 0x80800358: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_5;
    // 0x80800358: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x8080035C: b           L_808005DC
    // 0x80800360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800364:
    // 0x80800364: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800368: jal         0x808005EC
    // 0x8080036C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_6;
    // 0x8080036C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800370: b           L_808005DC
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800378:
    // 0x80800378: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080037C: jal         0x808005EC
    // 0x80800380: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_7;
    // 0x80800380: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x80800384: b           L_808005DC
    // 0x80800388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080038C:
    // 0x8080038C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800390: jal         0x808005EC
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_8;
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800398: b           L_808005DC
    // 0x8080039C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x8080039C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A0:
    // 0x808003A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003A4: jal         0x808005EC
    // 0x808003A8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_9;
    // 0x808003A8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_9:
    // 0x808003AC: b           L_808005DC
    // 0x808003B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808003B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003B4:
    // 0x808003B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003B8: jal         0x808005EC
    // 0x808003BC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_10;
    // 0x808003BC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_10:
    // 0x808003C0: jal         0x80088860
    // 0x808003C4: nop

    _glcutDll_entrypoint_23(rdram, ctx);
        goto after_11;
    // 0x808003C4: nop

    after_11:
    // 0x808003C8: beq         $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x808003CC: nop
    
            goto L_8080040C;
    }
    // 0x808003CC: nop

    // 0x808003D0: jal         0x80088830
    // 0x808003D4: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_12;
    // 0x808003D4: nop

    after_12:
    // 0x808003D8: b           L_808005DC
    // 0x808003DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808003DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003E0:
    // 0x808003E0: jal         0x80801228
    // 0x808003E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801228_chdinofamilymother(rdram, ctx);
        goto after_13;
    // 0x808003E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x808003E8: b           L_808005DC
    // 0x808003EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808003EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003F0:
    // 0x808003F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003F4: jal         0x808005EC
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_14;
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808003FC: b           L_808005DC
    // 0x80800400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800404:
    // 0x80800404: jal         0x80801228
    // 0x80800408: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801228_chdinofamilymother(rdram, ctx);
        goto after_15;
    // 0x80800408: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_15:
L_8080040C:
    // 0x8080040C: b           L_808005DC
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800414:
    // 0x80800414: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800418: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080041C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800420: beq         $v0, $zero, L_80800450
    if (ctx->r2 == 0) {
        // 0x80800424: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800450;
    }
    // 0x80800424: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800428: beq         $v0, $at, L_80800450
    if (ctx->r2 == ctx->r1) {
        // 0x8080042C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800450;
    }
    // 0x8080042C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800430: beq         $v0, $at, L_80800450
    if (ctx->r2 == ctx->r1) {
        // 0x80800434: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80800450;
    }
    // 0x80800434: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800438: bne         $v0, $at, L_8080045C
    if (ctx->r2 != ctx->r1) {
        // 0x8080043C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080045C;
    }
    // 0x8080043C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800440: jal         0x808005EC
    // 0x80800444: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_16;
    // 0x80800444: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_16:
    // 0x80800448: b           L_808005DC
    // 0x8080044C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808005DC;
    // 0x8080044C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800450:
    // 0x80800450: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800454: jal         0x8080119C
    // 0x80800458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080119C_chdinofamilymother(rdram, ctx);
        goto after_17;
    // 0x80800458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
L_8080045C:
    // 0x8080045C: b           L_808005DC
    // 0x80800460: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808005DC;
    // 0x80800460: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800464:
    // 0x80800464: jal         0x80088098
    // 0x80800468: addiu       $a0, $a0, 0x13D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2420, 0X13D0));
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x80800468: addiu       $a0, $a0, 0x13D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2420, 0X13D0));
    after_18:
    // 0x8080046C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80800470: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2420, 0X13DC) << 16);
    // 0x80800474: addiu       $a0, $a0, 0x13DC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2420, 0X13DC));
    // 0x80800478: jal         0x80088090
    // 0x8080047C: lw          $a1, 0x38($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x8080047C: lw          $a1, 0x38($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X38);
    after_19:
    // 0x80800480: b           L_808005DC
    // 0x80800484: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808005DC;
    // 0x80800484: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800488:
    // 0x80800488: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8080048C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800490: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x80800494: and         $t5, $a2, $at
    ctx->r13 = ctx->r6 & ctx->r1;
    // 0x80800498: srl         $a1, $t5, 16
    ctx->r5 = S32(U32(ctx->r13) >> 16);
    // 0x8080049C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x808004A0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808004A4: jal         0x80088078
    // 0x808004A8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x808004A8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    after_20:
    // 0x808004AC: beq         $v0, $zero, L_808004CC
    if (ctx->r2 == 0) {
        // 0x808004B0: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_808004CC;
    }
    // 0x808004B0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808004B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808004BC: jal         0x8080119C
    // 0x808004C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080119C_chdinofamilymother(rdram, ctx);
        goto after_21;
    // 0x808004C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_21:
    // 0x808004C4: b           L_808005DC
    // 0x808004C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808005DC;
    // 0x808004C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808004CC:
    // 0x808004CC: b           L_808005DC
    // 0x808004D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808004D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004D4:
    // 0x808004D4: jal         0x800DA298
    // 0x808004D8: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    func_800DA298(rdram, ctx);
        goto after_22;
    // 0x808004D8: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    after_22:
    // 0x808004DC: beql        $v0, $zero, L_80800528
    if (ctx->r2 == 0) {
        // 0x808004E0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800528;
    }
    goto skip_0;
    // 0x808004E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x808004E4: jal         0x800DA298
    // 0x808004E8: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA298(rdram, ctx);
        goto after_23;
    // 0x808004E8: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_23:
    // 0x808004EC: bnel        $v0, $zero, L_80800528
    if (ctx->r2 != 0) {
        // 0x808004F0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800528;
    }
    goto skip_1;
    // 0x808004F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x808004F4: jal         0x800DA298
    // 0x808004F8: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    func_800DA298(rdram, ctx);
        goto after_24;
    // 0x808004F8: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    after_24:
    // 0x808004FC: beql        $v0, $zero, L_80800528
    if (ctx->r2 == 0) {
        // 0x80800500: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800528;
    }
    goto skip_2;
    // 0x80800500: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80800504: jal         0x800DA298
    // 0x80800508: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800DA298(rdram, ctx);
        goto after_25;
    // 0x80800508: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_25:
    // 0x8080050C: beq         $v0, $zero, L_80800524
    if (ctx->r2 == 0) {
        // 0x80800510: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800524;
    }
    // 0x80800510: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800514: jal         0x808005EC
    // 0x80800518: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_26;
    // 0x80800518: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_26:
    // 0x8080051C: b           L_808005DC
    // 0x80800520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800524:
    // 0x80800524: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800528:
    // 0x80800528: jal         0x808005EC
    // 0x8080052C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808005EC_chdinofamilymother(rdram, ctx);
        goto after_27;
    // 0x8080052C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_27:
    // 0x80800530: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800534: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800538: addiu       $a1, $zero, 0x17C3
    ctx->r5 = ADD32(0, 0X17C3);
    // 0x8080053C: beq         $v0, $zero, L_80800564
    if (ctx->r2 == 0) {
        // 0x80800540: addiu       $a2, $zero, 0xC
        ctx->r6 = ADD32(0, 0XC);
            goto L_80800564;
    }
    // 0x80800540: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800544: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800548: beq         $v0, $at, L_80800580
    if (ctx->r2 == ctx->r1) {
        // 0x8080054C: addiu       $a1, $zero, 0x17C4
        ctx->r5 = ADD32(0, 0X17C4);
            goto L_80800580;
    }
    // 0x8080054C: addiu       $a1, $zero, 0x17C4
    ctx->r5 = ADD32(0, 0X17C4);
    // 0x80800550: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800554: beq         $v0, $at, L_808005B8
    if (ctx->r2 == ctx->r1) {
        // 0x80800558: addiu       $a1, $zero, 0x17C5
        ctx->r5 = ADD32(0, 0X17C5);
            goto L_808005B8;
    }
    // 0x80800558: addiu       $a1, $zero, 0x17C5
    ctx->r5 = ADD32(0, 0X17C5);
    // 0x8080055C: b           L_808005DC
    // 0x80800560: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x80800560: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800564:
    // 0x80800564: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800568: addiu       $t8, $zero, 0x65
    ctx->r24 = ADD32(0, 0X65);
    // 0x8080056C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800570: jal         0x8008A208
    // 0x80800574: addiu       $a3, $t7, 0x18
    ctx->r7 = ADD32(ctx->r15, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_28;
    // 0x80800574: addiu       $a3, $t7, 0x18
    ctx->r7 = ADD32(ctx->r15, 0X18);
    after_28:
    // 0x80800578: b           L_808005DC
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800580:
    // 0x80800580: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80800584: addiu       $t9, $zero, 0x65
    ctx->r25 = ADD32(0, 0X65);
    // 0x80800588: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080058C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800590: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800594: jal         0x8008A208
    // 0x80800598: addiu       $a3, $v0, 0x18
    ctx->r7 = ADD32(ctx->r2, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_29;
    // 0x80800598: addiu       $a3, $v0, 0x18
    ctx->r7 = ADD32(ctx->r2, 0X18);
    after_29:
    // 0x8080059C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808005A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808005A8: jal         0x8080119C
    // 0x808005AC: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    func_8080119C_chdinofamilymother(rdram, ctx);
        goto after_30;
    // 0x808005AC: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    after_30:
    // 0x808005B0: b           L_808005DC
    // 0x808005B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808005B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B8:
    // 0x808005B8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x808005BC: addiu       $t0, $zero, 0x65
    ctx->r8 = ADD32(0, 0X65);
    // 0x808005C0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808005C4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808005C8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808005CC: jal         0x8008A208
    // 0x808005D0: addiu       $a3, $v0, 0x18
    ctx->r7 = ADD32(ctx->r2, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_31;
    // 0x808005D0: addiu       $a3, $v0, 0x18
    ctx->r7 = ADD32(ctx->r2, 0X18);
    after_31:
    // 0x808005D4: b           L_808005DC
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005DC;
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005DC:
    // 0x808005DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005E4: jr          $ra
    // 0x808005E8: nop

    return;
    // 0x808005E8: nop

;}
RECOMP_FUNC void func_8080000C_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800018: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080001C: jal         0x80100094
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080002C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800030: beql        $t6, $zero, L_80800054
    if (ctx->r14 == 0) {
        // 0x80800034: lw          $t1, 0x4($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X4);
            goto L_80800054;
    }
    goto skip_0;
    // 0x80800034: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80800038: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8080003C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800040: sllv        $t9, $t8, $v1
    ctx->r25 = S32(ctx->r24 << (ctx->r3 & 31));
    // 0x80800044: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800048: b           L_80800064
    // 0x8080004C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
        goto L_80800064;
    // 0x8080004C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80800050: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
L_80800054:
    // 0x80800054: sllv        $t3, $t2, $v1
    ctx->r11 = S32(ctx->r10 << (ctx->r3 & 31));
    // 0x80800058: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8080005C: and         $t5, $t1, $t4
    ctx->r13 = ctx->r9 & ctx->r12;
    // 0x80800060: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80800064:
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void func_800FE734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE734: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE738: jr          $ra
    // 0x800FE73C: sb          $a0, 0x59D7($at)
    MEM_B(0X59D7, ctx->r1) = ctx->r4;
    return;
    // 0x800FE73C: sb          $a0, 0x59D7($at)
    MEM_B(0X59D7, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_808000D4_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808000E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000E8: jal         0x80085300
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_get(rdram, ctx);
        goto after_0;
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808000F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x808000FC: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80800100: nop

    // 0x80800104: bc1fl       L_80800144
    if (!c1cs) {
        // 0x80800108: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800144;
    }
    goto skip_0;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080010C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800110: jal         0x80084F60
    // 0x80800114: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    _bapulse_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800114: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_1:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x80092744
    // 0x80800120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80092744(rdram, ctx);
        goto after_2;
    // 0x80800120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800124: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80800128: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800134: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80800138: jal         0x80092750
    // 0x8080013C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_80092750(rdram, ctx);
        goto after_3;
    // 0x8080013C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800144:
    // 0x80800144: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800148: jal         0x80085338
    // 0x8080014C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _batimer_set(rdram, ctx);
        goto after_4;
    // 0x8080014C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800150: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800154: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800158: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
RECOMP_FUNC void func_8009F300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F300: jr          $ra
    // 0x8009F304: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x8009F304: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800188_chlavaarchgrill3switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080018C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800194: jal         0x80800000
    // 0x80800198: addiu       $a1, $zero, 0xA1F
    ctx->r5 = ADD32(0, 0XA1F);
    func_80800000_chlavaarchgrill3switches(rdram, ctx);
        goto after_0;
    // 0x80800198: addiu       $a1, $zero, 0xA1F
    ctx->r5 = ADD32(0, 0XA1F);
    after_0:
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001A0: jal         0x80085810
    // 0x808001A4: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808001A4: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // 0x808001A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B0: jr          $ra
    // 0x808001B4: nop

    return;
    // 0x808001B4: nop

;}
RECOMP_FUNC void chalienkids_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1324, 0X216C) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x216C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1324, 0X216C));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x216C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1324, 0X216C));
;}
RECOMP_FUNC void bamovegoto_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001FC: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x80800200: jal         0x800EE7F8
    // 0x80800204: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800204: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    after_0:
    // 0x80800208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080020C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void _bskaztorpedo_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083788: syscall     72
    recomp_syscall_handler(rdram, ctx, 0x80083788);
    return;
    // 0x8008378C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _fxairbub_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889D0: syscall     716
    recomp_syscall_handler(rdram, ctx, 0x800889D0);
    return;
    // 0x800889D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808013B8_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013C0: jal         0x800D8FF8
    // 0x808013C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808013C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808013CC: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x808013D0: ori         $a1, $a1, 0x8
    ctx->r5 = ctx->r5 | 0X8;
    // 0x808013D4: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x808013D8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808013DC: jal         0x8010B990
    // 0x808013E0: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    func_8010B990(rdram, ctx);
        goto after_1;
    // 0x808013E0: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    after_1:
    // 0x808013E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808013E8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808013EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808013F0: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808013F4: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x808013F8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x808013FC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80801400: nop

    // 0x80801404: bc1fl       L_80801418
    if (!c1cs) {
        // 0x80801408: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801418;
    }
    goto skip_0;
    // 0x80801408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080140C: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80801410: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x80801414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801418:
    // 0x80801418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080141C: jr          $ra
    // 0x80801420: nop

    return;
    // 0x80801420: nop

;}
RECOMP_FUNC void func_80800684_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800684: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800688: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080068C: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800690: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800698: bne         $a1, $at, L_8080070C
    if (ctx->r5 != ctx->r1) {
        // 0x8080069C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8080070C;
    }
    // 0x8080069C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808006A0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808006A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006A8: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
    // 0x808006AC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808006B0: bne         $t7, $at, L_80800714
    if (ctx->r15 != ctx->r1) {
        // 0x808006B4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800714;
    }
    // 0x808006B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808006B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006BC: jal         0x8010D254
    // 0x808006C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x808006C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808006C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808006C8: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x808006CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006D0: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x808006D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808006D8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808006DC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808006E0: nop

    // 0x808006E4: bc1fl       L_80800718
    if (!c1cs) {
        // 0x808006E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800718;
    }
    goto skip_0;
    // 0x808006E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808006EC: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x808006F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808006F4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x808006F8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x808006FC: jal         0x80090494
    // 0x80800700: swc1        $f16, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f16.u32l;
    func_80090494(rdram, ctx);
        goto after_1;
    // 0x80800700: swc1        $f16, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f16.u32l;
    after_1:
    // 0x80800704: b           L_80800718
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800718;
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080070C:
    // 0x8080070C: b           L_80800718
    // 0x80800710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800718;
    // 0x80800710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800714:
    // 0x80800714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800718:
    // 0x80800718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080071C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800720: jr          $ra
    // 0x80800724: nop

    return;
    // 0x80800724: nop

;}
