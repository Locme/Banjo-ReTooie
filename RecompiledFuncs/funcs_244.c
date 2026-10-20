#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080003C_chfoodwarn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080004C: jal         0x80800000
    // 0x80800050: addiu       $a2, $a0, 0x28
    ctx->r6 = ADD32(ctx->r4, 0X28);
    func_80800000_chfoodwarn(rdram, ctx);
        goto after_0;
    // 0x80800050: addiu       $a2, $a0, 0x28
    ctx->r6 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080005C: jal         0x80800000
    // 0x80800060: addiu       $a2, $a0, 0x18
    ctx->r6 = ADD32(ctx->r4, 0X18);
    func_80800000_chfoodwarn(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a2, $a0, 0x18
    ctx->r6 = ADD32(ctx->r4, 0X18);
    after_1:
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void chgameselect_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021CC: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(804, 0X8298) << 16);
    // 0x808021D0: jr          $ra
    // 0x808021D4: addiu       $v0, $v0, -0x7D68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X8298));
    return;
    // 0x808021D4: addiu       $v0, $v0, -0x7D68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X8298));
;}
RECOMP_FUNC void chswitch_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800204: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080020C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800210: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800214: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800218: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080021C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800220: bnel        $t7, $at, L_808002A4
    if (ctx->r15 != ctx->r1) {
        // 0x80800224: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002A4;
    }
    goto skip_0;
    // 0x80800224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800228: jal         0x80101DDC
    // 0x8080022C: nop

    func_80101DDC(rdram, ctx);
        goto after_0;
    // 0x8080022C: nop

    after_0:
    // 0x80800230: beql        $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x80800234: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002A4;
    }
    goto skip_1;
    // 0x80800234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800238: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x8080023C: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800240: bltzl       $t0, L_808002A4
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800244: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002A4;
    }
    goto skip_2;
    // 0x80800244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800248: jal         0x800D9078
    // 0x8080024C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x8080024C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    after_1:
    // 0x80800250: beql        $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x80800254: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002A4;
    }
    goto skip_3;
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800258: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800264: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80800268: jal         0x80102424
    // 0x8080026C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x8080026C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    after_2:
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: jal         0x80103110
    // 0x80800278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080027C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80800280: jal         0x800F7F98
    // 0x80800284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_4;
    // 0x80800284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800288: jal         0x800DA544
    // 0x8080028C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x8080028C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800298: jal         0x8010108C
    // 0x8080029C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_6;
    // 0x8080029C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808002A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A4:
    // 0x808002A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

;}
RECOMP_FUNC void _bsbanpackwhack_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826A8: syscall     6
    recomp_syscall_handler(rdram, ctx, 0x800826A8);
    return;
    // 0x800826AC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80803598_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080359C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808035A0: jal         0x80106790
    // 0x808035A4: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808035A4: nop

    after_0:
    // 0x808035A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808035AC: jal         0x80102424
    // 0x808035B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808035B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x808035B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808035B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808035BC: jr          $ra
    // 0x808035C0: nop

    return;
    // 0x808035C0: nop

;}
RECOMP_FUNC void func_808001B4_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808001B8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x808001BC: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x808001C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808001C4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808001C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808001CC: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x808001D0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808001D4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808001D8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808001DC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808001E0: jal         0x80100094
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001EC: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x808001F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001F4: jal         0x80800080
    // 0x808001F8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_80800080_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x808001F8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x808001FC: lh          $a0, 0x2A($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2A);
    // 0x80800200: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800204: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800208: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080020C: beq         $at, $zero, L_80800360
    if (ctx->r1 == 0) {
        // 0x80800210: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_80800360;
    }
    // 0x80800210: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80800214: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800218: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x8080021C: lui         $s3, 0x9C4
    ctx->r19 = S32(0X9C4 << 16);
    // 0x80800220: ori         $s3, $s3, 0x4E2
    ctx->r19 = ctx->r19 | 0X4E2;
    // 0x80800224: slt         $at, $t8, $s5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80800228: beq         $at, $zero, L_80800360
    if (ctx->r1 == 0) {
        // 0x8080022C: lui         $s2, 0x8080
        ctx->r18 = S32(RELOC_HI16(1692, 0X4294) << 16);
            goto L_80800360;
    }
    // 0x8080022C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1692, 0X4294) << 16);
    // 0x80800230: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3E44) << 16);
    // 0x80800234: lwc1        $f20, 0x3E44($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3E44));
    // 0x80800238: addiu       $s2, $s2, 0x4294
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1692, 0X4294));
    // 0x8080023C: lbu         $a2, 0x3($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X3);
L_80800240:
    // 0x80800240: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80800244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800248: andi        $t9, $a2, 0x1
    ctx->r25 = ctx->r6 & 0X1;
    // 0x8080024C: beql        $t9, $zero, L_80800324
    if (ctx->r25 == 0) {
        // 0x80800250: lbu         $a1, 0x2($v1)
        ctx->r5 = MEM_BU(ctx->r3, 0X2);
            goto L_80800324;
    }
    goto skip_0;
    // 0x80800250: lbu         $a1, 0x2($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X2);
    skip_0:
    // 0x80800254: lbu         $a3, 0x2($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X2);
    // 0x80800258: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080025C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800260: sll         $t0, $a3, 3
    ctx->r8 = S32(ctx->r7 << 3);
    // 0x80800264: addu        $v0, $s2, $t0
    ctx->r2 = ADD32(ctx->r18, ctx->r8);
    // 0x80800268: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080026C: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x80800270: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80800274: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800278: sra         $t4, $t3, 5
    ctx->r12 = S32(SIGNED(ctx->r11) >> 5);
    // 0x8080027C: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x80800280: sll         $t6, $t5, 11
    ctx->r14 = S32(ctx->r13 << 11);
    // 0x80800284: andi        $t2, $t1, 0x7FF
    ctx->r10 = ctx->r9 & 0X7FF;
    // 0x80800288: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8080028C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800290: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800294: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800298: nop

    // 0x8080029C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808002A0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x808002A4: nop

    // 0x808002A8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x808002AC: beql        $t9, $zero, L_808002FC
    if (ctx->r25 == 0) {
        // 0x808002B0: mfc1        $t9, $f8
        ctx->r25 = (int32_t)ctx->f8.u32l;
            goto L_808002FC;
    }
    goto skip_1;
    // 0x808002B0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x808002B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808002BC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808002C0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808002C4: nop

    // 0x808002C8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x808002CC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x808002D0: nop

    // 0x808002D4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x808002D8: bne         $t9, $zero, L_808002F0
    if (ctx->r25 != 0) {
        // 0x808002DC: nop
    
            goto L_808002F0;
    }
    // 0x808002DC: nop

    // 0x808002E0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x808002E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808002E8: b           L_80800308
    // 0x808002EC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80800308;
    // 0x808002EC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_808002F0:
    // 0x808002F0: b           L_80800308
    // 0x808002F4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80800308;
    // 0x808002F4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808002F8: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
L_808002FC:
    // 0x808002FC: nop

    // 0x80800300: bltz        $t9, L_808002F0
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800304: nop
    
            goto L_808002F0;
    }
    // 0x80800304: nop

L_80800308:
    // 0x80800308: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8080030C: sll         $t1, $t9, 21
    ctx->r9 = S32(ctx->r25 << 21);
    // 0x80800310: jal         0x800C4140
    // 0x80800314: addu        $a0, $t1, $t7
    ctx->r4 = ADD32(ctx->r9, ctx->r15);
    func_800C4140(rdram, ctx);
        goto after_2;
    // 0x80800314: addu        $a0, $t1, $t7
    ctx->r4 = ADD32(ctx->r9, ctx->r15);
    after_2:
    // 0x80800318: b           L_80800330
    // 0x8080031C: lh          $t3, 0x2A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2A);
        goto L_80800330;
    // 0x8080031C: lh          $t3, 0x2A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2A);
    // 0x80800320: lbu         $a1, 0x2($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X2);
L_80800324:
    // 0x80800324: jal         0x80803AF0
    // 0x80800328: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    func_80803AF0_chflysaucer(rdram, ctx);
        goto after_3;
    // 0x80800328: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    after_3:
    // 0x8080032C: lh          $t3, 0x2A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2A);
L_80800330:
    // 0x80800330: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80800334: sh          $t4, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r12;
    // 0x80800338: lh          $a0, 0x2A($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2A);
    // 0x8080033C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80800340: slt         $at, $a0, $s4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80800344: beq         $at, $zero, L_80800360
    if (ctx->r1 == 0) {
        // 0x80800348: sll         $t2, $a0, 3
        ctx->r10 = S32(ctx->r4 << 3);
            goto L_80800360;
    }
    // 0x80800348: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x8080034C: addu        $v1, $t5, $t2
    ctx->r3 = ADD32(ctx->r13, ctx->r10);
    // 0x80800350: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x80800354: slt         $at, $t6, $s5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80800358: bnel        $at, $zero, L_80800240
    if (ctx->r1 != 0) {
        // 0x8080035C: lbu         $a2, 0x3($v1)
        ctx->r6 = MEM_BU(ctx->r3, 0X3);
            goto L_80800240;
    }
    goto skip_2;
    // 0x8080035C: lbu         $a2, 0x3($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X3);
    skip_2:
L_80800360:
    // 0x80800360: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800364: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800368: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080036C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800370: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800374: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800378: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8080037C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800380: jr          $ra
    // 0x80800384: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800384: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_808001F0_chfactorymaindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001F8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808001FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800200: beq         $a1, $at, L_808002EC
    if (ctx->r5 == ctx->r1) {
        // 0x80800204: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_808002EC;
    }
    // 0x80800204: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800208: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x8080020C: beq         $a1, $at, L_80800224
    if (ctx->r5 == ctx->r1) {
        // 0x80800210: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800224;
    }
    // 0x80800210: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800214: beq         $a1, $at, L_8080027C
    if (ctx->r5 == ctx->r1) {
        // 0x80800218: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080027C;
    }
    // 0x80800218: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080021C: b           L_80800324
    // 0x80800220: nop

        goto L_80800324;
    // 0x80800220: nop

L_80800224:
    // 0x80800224: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80800228: bne         $a2, $at, L_80800274
    if (ctx->r6 != ctx->r1) {
        // 0x8080022C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800274;
    }
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x80101FDC
    // 0x80800234: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800234: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800238: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080023C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2320, 0X4AC) << 16);
    // 0x80800240: lwc1        $f12, 0x4AC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2320, 0X4AC));
    // 0x80800244: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800248: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8080024C: jal         0x800F10B4
    // 0x80800250: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800250: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80800254: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800258: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x8080025C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800260: addiu       $a3, $zero, 0x2910
    ctx->r7 = ADD32(0, 0X2910);
    // 0x80800264: jal         0x80085708
    // 0x80800268: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800268: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_2:
    // 0x8080026C: b           L_80800324
    // 0x80800270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800324;
    // 0x80800270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800274:
    // 0x80800274: b           L_80800324
    // 0x80800278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800324;
    // 0x80800278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080027C:
    // 0x8080027C: jal         0x800EA05C
    // 0x80800280: nop

    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x80800280: nop

    after_3:
    // 0x80800284: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x80800288: bne         $v0, $at, L_808002E4
    if (ctx->r2 != ctx->r1) {
        // 0x8080028C: nop
    
            goto L_808002E4;
    }
    // 0x8080028C: nop

    // 0x80800290: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800294: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808002A0: bne         $t7, $at, L_808002E4
    if (ctx->r15 != ctx->r1) {
        // 0x808002A4: nop
    
            goto L_808002E4;
    }
    // 0x808002A4: nop

    // 0x808002A8: jal         0x80101FDC
    // 0x808002AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808002AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808002B0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2320, 0X4B0) << 16);
    // 0x808002B8: lwc1        $f12, 0x4B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2320, 0X4B0));
    // 0x808002BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002C0: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x808002C4: jal         0x800F10B4
    // 0x808002C8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x808002C8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x808002CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002D0: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x808002D4: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x808002D8: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    // 0x808002DC: jal         0x80085708
    // 0x808002E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x808002E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_6:
L_808002E4:
    // 0x808002E4: b           L_80800324
    // 0x808002E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800324;
    // 0x808002E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002EC:
    // 0x808002EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808002F0: bne         $a2, $at, L_8080031C
    if (ctx->r6 != ctx->r1) {
        // 0x808002F4: nop
    
            goto L_8080031C;
    }
    // 0x808002F4: nop

    // 0x808002F8: jal         0x800EA05C
    // 0x808002FC: nop

    func_800EA05C(rdram, ctx);
        goto after_7;
    // 0x808002FC: nop

    after_7:
    // 0x80800300: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x80800304: bne         $v0, $at, L_8080031C
    if (ctx->r2 != ctx->r1) {
        // 0x80800308: addiu       $a0, $zero, 0x100
        ctx->r4 = ADD32(0, 0X100);
            goto L_8080031C;
    }
    // 0x80800308: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x8080030C: jal         0x800887D8
    // 0x80800310: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x80800310: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_8:
    // 0x80800314: b           L_80800324
    // 0x80800318: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800324;
    // 0x80800318: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080031C:
    // 0x8080031C: b           L_80800324
    // 0x80800320: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800324;
    // 0x80800320: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800324:
    // 0x80800324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800328: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080032C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void bsdronefalldie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001DC: jal         0x8009E6EC
    // 0x808001E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808001E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001E4: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x808001E8: beql        $v0, $at, L_808001FC
    if (ctx->r2 == ctx->r1) {
        // 0x808001EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001F0: jal         0x80099AA8
    // 0x808001F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099AA8(rdram, ctx);
        goto after_1;
    // 0x808001F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001FC:
    // 0x808001FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800200: jr          $ra
    // 0x80800204: nop

    return;
    // 0x80800204: nop

;}
RECOMP_FUNC void chwandglow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003CC: jal         0x80106790
    // 0x808003D0: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808003D0: nop

    after_0:
    // 0x808003D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003D8: jal         0x8080011C
    // 0x808003DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080011C_chwandglow(rdram, ctx);
        goto after_1;
    // 0x808003DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x808003E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003E8: jr          $ra
    // 0x808003EC: nop

    return;
    // 0x808003EC: nop

;}
RECOMP_FUNC void func_80800738_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800738_chfactorycrusher");
    // 0x80800738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080073C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800740: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800744: jal         0x800F54E4
    // 0x80800748: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800748: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080074C: jal         0x800F6478
    // 0x80800750: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x80800750: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800754: bne         $v0, $zero, L_80800764
    if (ctx->r2 != 0) {
        // 0x80800758: nop
    
            goto L_80800764;
    }
    // 0x80800758: nop

    // 0x8080075C: b           L_808007F0
    // 0x80800760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007F0;
    // 0x80800760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800764:
    // 0x80800764: jal         0x800F54E4
    // 0x80800768: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800768: nop

    after_2:
    // 0x8080076C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800770: jal         0x800F5A00
    // 0x80800774: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x80800774: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800778: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080077C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1136, 0XA3C) << 16);
    // 0x80800780: lwc1        $f4, 0xA3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1136, 0XA3C));
    // 0x80800784: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80800788: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1136, 0XA40) << 16);
    // 0x8080078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800790: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800794: nop

    // 0x80800798: bc1f        L_808007F0
    if (!c1cs) {
        // 0x8080079C: nop
    
            goto L_808007F0;
    }
    // 0x8080079C: nop

    // 0x808007A0: lwc1        $f6, 0xA40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1136, 0XA40));
    // 0x808007A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1136, 0XA44) << 16);
    // 0x808007A8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808007AC: nop

    // 0x808007B0: bc1f        L_808007F0
    if (!c1cs) {
        // 0x808007B4: nop
    
            goto L_808007F0;
    }
    // 0x808007B4: nop

    // 0x808007B8: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
    // 0x808007BC: lwc1        $f8, 0xA44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1136, 0XA44));
    // 0x808007C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1136, 0XA48) << 16);
    // 0x808007C4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808007C8: nop

    // 0x808007CC: bc1f        L_808007F0
    if (!c1cs) {
        // 0x808007D0: nop
    
            goto L_808007F0;
    }
    // 0x808007D0: nop

    // 0x808007D4: lwc1        $f10, 0xA48($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1136, 0XA48));
    // 0x808007D8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808007DC: nop

    // 0x808007E0: bc1f        L_808007F0
    if (!c1cs) {
        // 0x808007E4: nop
    
            goto L_808007F0;
    }
    // 0x808007E4: nop

    // 0x808007E8: b           L_808007F0
    // 0x808007EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007F0;
    // 0x808007EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007F0:
    // 0x808007F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007F8: jr          $ra
    // 0x808007FC: nop

    return;
    // 0x808007FC: nop

;}
RECOMP_FUNC void func_80803C3C_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803C3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803C44: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80803C48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803C4C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80803C50: beq         $t6, $at, L_80803C68
    if (ctx->r14 == ctx->r1) {
        // 0x80803C54: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80803C68;
    }
    // 0x80803C54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803C58: beq         $t6, $at, L_80803CAC
    if (ctx->r14 == ctx->r1) {
        // 0x80803C5C: nop
    
            goto L_80803CAC;
    }
    // 0x80803C5C: nop

    // 0x80803C60: b           L_80803CB8
    // 0x80803C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803CB8;
    // 0x80803C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803C68:
    // 0x80803C68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80803C6C: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80803C70: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80803C74: nop

    // 0x80803C78: bc1f        L_80803C9C
    if (!c1cs) {
        // 0x80803C7C: nop
    
            goto L_80803C9C;
    }
    // 0x80803C7C: nop

    // 0x80803C80: jal         0x800D8FF8
    // 0x80803C84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80803C84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803C88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803C8C: lwc1        $f8, 0x58($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80803C90: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80803C94: b           L_80803CB4
    // 0x80803C98: swc1        $f10, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f10.u32l;
        goto L_80803CB4;
    // 0x80803C98: swc1        $f10, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f10.u32l;
L_80803C9C:
    // 0x80803C9C: jal         0x80803BF0
    // 0x80803CA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80803BF0_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x80803CA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80803CA4: b           L_80803CB8
    // 0x80803CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803CB8;
    // 0x80803CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803CAC:
    // 0x80803CAC: jal         0x80089CC0
    // 0x80803CB0: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    _subaddiefade_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80803CB0: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    after_2:
L_80803CB4:
    // 0x80803CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803CB8:
    // 0x80803CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803CBC: jr          $ra
    // 0x80803CC0: nop

    return;
    // 0x80803CC0: nop

;}
RECOMP_FUNC void func_80098BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098BE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80098BE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80098BE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80098BEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098BF0: jal         0x800A9420
    // 0x80098BF4: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800A9420(rdram, ctx);
        goto after_0;
    // 0x80098BF4: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x80098BF8: beq         $v0, $zero, L_80098C34
    if (ctx->r2 == 0) {
        // 0x80098BFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80098C34;
    }
    // 0x80098BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098C00: jal         0x8009AD78
    // 0x80098C04: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8009AD78(rdram, ctx);
        goto after_1;
    // 0x80098C04: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80098C08: beql        $v0, $zero, L_80098C1C
    if (ctx->r2 == 0) {
        // 0x80098C0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80098C1C;
    }
    goto skip_0;
    // 0x80098C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80098C10: jal         0x80084AB8
    // 0x80098C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggcursor_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80098C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80098C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80098C1C:
    // 0x80098C1C: jal         0x8009AD78
    // 0x80098C20: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8009AD78(rdram, ctx);
        goto after_3;
    // 0x80098C20: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
    // 0x80098C24: beql        $v0, $zero, L_80098C38
    if (ctx->r2 == 0) {
        // 0x80098C28: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80098C38;
    }
    goto skip_1;
    // 0x80098C28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80098C2C: jal         0x800843B0
    // 0x80098C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsfirstp_entrypoint_37(rdram, ctx);
        goto after_4;
    // 0x80098C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80098C34:
    // 0x80098C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80098C38:
    // 0x80098C38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80098C3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098C40: jr          $ra
    // 0x80098C44: nop

    return;
    // 0x80098C44: nop

;}
RECOMP_FUNC void func_800904C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800904C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800904CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800904D0: jal         0x800F54E4
    // 0x800904D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800904D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800904D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800904DC: jal         0x800F7B9C
    // 0x800904E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F7B9C(rdram, ctx);
        goto after_1;
    // 0x800904E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800904E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800904E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800904EC: jr          $ra
    // 0x800904F0: nop

    return;
    // 0x800904F0: nop

;}
RECOMP_FUNC void func_800B37E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B37E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B37E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B37EC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B37F0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B37F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B37F8: addiu       $t6, $a0, 0x18
    ctx->r14 = ADD32(ctx->r4, 0X18);
    // 0x800B37FC: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x800B3800: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x800B3804: addiu       $s1, $a1, 0x18
    ctx->r17 = ADD32(ctx->r5, 0X18);
    // 0x800B3808: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B380C: sltu        $at, $s1, $t7
    ctx->r1 = ctx->r17 < ctx->r15 ? 1 : 0;
    // 0x800B3810: beq         $at, $zero, L_800B3868
    if (ctx->r1 == 0) {
        // 0x800B3814: or          $s2, $a1, $zero
        ctx->r18 = ctx->r5 | 0;
            goto L_800B3868;
    }
    // 0x800B3814: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800B3818: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800B381C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B3820: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x800B3824: beq         $at, $zero, L_800B3868
    if (ctx->r1 == 0) {
        // 0x800B3828: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800B3868;
    }
    // 0x800B3828: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
L_800B382C:
    // 0x800B382C: jal         0x8001BBC8
    // 0x800B3830: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    aligned4_memcpy(rdram, ctx);
        goto after_0;
    // 0x800B3830: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_0:
    // 0x800B3834: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x800B3838: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x800B383C: addiu       $t0, $t9, 0x1C
    ctx->r8 = ADD32(ctx->r25, 0X1C);
    // 0x800B3840: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
    // 0x800B3844: lw          $t1, 0x10($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X10);
    // 0x800B3848: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x800B384C: beql        $at, $zero, L_800B386C
    if (ctx->r1 == 0) {
        // 0x800B3850: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800B386C;
    }
    goto skip_0;
    // 0x800B3850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800B3854: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x800B3858: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800B385C: sltu        $at, $t0, $t2
    ctx->r1 = ctx->r8 < ctx->r10 ? 1 : 0;
    // 0x800B3860: bnel        $at, $zero, L_800B382C
    if (ctx->r1 != 0) {
        // 0x800B3864: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800B382C;
    }
    goto skip_1;
    // 0x800B3864: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    skip_1:
L_800B3868:
    // 0x800B3868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800B386C:
    // 0x800B386C: jal         0x800EE830
    // 0x800B3870: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE830(rdram, ctx);
        goto after_1;
    // 0x800B3870: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800B3874: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B3878: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B387C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3880: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B3884: jr          $ra
    // 0x800B3888: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B3888: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsbanbflip_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080038C: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    // 0x80800390: jal         0x80800064
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    __bsbanbflip_set_substate(rdram, ctx);
        goto after_0;
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080039C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void func_80098640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098640: lw          $t6, 0xE0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE0);
    // 0x80098644: jr          $ra
    // 0x80098648: lbu         $v0, 0x2D($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2D);
    return;
    // 0x80098648: lbu         $v0, 0x2D($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2D);
;}
RECOMP_FUNC void chbilldrillplate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1192, 0X10DC) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x10DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1192, 0X10DC));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x10DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1192, 0X10DC));
;}
RECOMP_FUNC void bskazstilt_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005C4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(292, 0X1210) << 16);
    // 0x808005C8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005CC: jr          $ra
    // 0x808005D0: lw          $v0, 0x1210($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1210));
    return;
    // 0x808005D0: lw          $v0, 0x1210($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1210));
;}
RECOMP_FUNC void func_800A0150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A0154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A0158: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A015C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A0160: jal         0x800FC240
    // 0x800A0164: addiu       $a1, $zero, 0xFA0
    ctx->r5 = ADD32(0, 0XFA0);
    func_800FC240(rdram, ctx);
        goto after_0;
    // 0x800A0164: addiu       $a1, $zero, 0xFA0
    ctx->r5 = ADD32(0, 0XFA0);
    after_0:
    // 0x800A0168: jal         0x800FC660
    // 0x800A016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FC660(rdram, ctx);
        goto after_1;
    // 0x800A016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A0170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A0178: jr          $ra
    // 0x800A017C: nop

    return;
    // 0x800A017C: nop

;}
RECOMP_FUNC void bamovegoto_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000F8: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x808000FC: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800100: jal         0x800EE7F8
    // 0x80800104: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800104: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    after_0:
    // 0x80800108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: lw          $a1, 0xC8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC8);
    // 0x80800110: jal         0x8009C0F8
    // 0x80800114: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    func_8009C0F8(rdram, ctx);
        goto after_1;
    // 0x80800114: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    after_1:
    // 0x80800118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: jal         0x80800000
    // 0x80800120: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800000_bamovegoto(rdram, ctx);
        goto after_2;
    // 0x80800120: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080012C: jr          $ra
    // 0x80800130: nop

    return;
    // 0x80800130: nop

;}
RECOMP_FUNC void func_808066A0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808066A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808066A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808066A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808066AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808066B0: jal         0x80100094
    // 0x808066B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808066B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808066B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808066BC: jal         0x80806D84
    // 0x808066C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80806D84_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x808066C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x808066C4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808066C8: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x808066CC: addiu       $a0, $zero, 0x10A
    ctx->r4 = ADD32(0, 0X10A);
    // 0x808066D0: jal         0x800D2498
    // 0x808066D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_2;
    // 0x808066D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808066D8: lbu         $t6, 0x5C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5C);
    // 0x808066DC: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x808066E0: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x808066E4: beq         $at, $zero, L_80806A60
    if (ctx->r1 == 0) {
        // 0x808066E8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80806A60;
    }
    // 0x808066E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808066EC: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9BC8) << 16);
    // 0x808066F0: addu        $at, $at, $t7
    gpr jr_addend_808066F8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808066F4: lw          $t7, -0x6438($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9BC8));
    // 0x808066F8: jr          $t7
    // 0x808066FC: nop

    switch (jr_addend_808066F8 >> 2) {
        case 0: goto L_80806700; break;
        case 1: goto L_80806720; break;
        case 2: goto L_80806754; break;
        case 3: goto L_80806768; break;
        case 4: goto L_8080689C; break;
        case 5: goto L_808068DC; break;
        case 6: goto L_80806958; break;
        case 7: goto L_80806A60; break;
        case 8: goto L_808069E8; break;
        case 9: goto L_80806A08; break;
        default: switch_error(__func__, 0x808066F8, 0x80809BC8);
    }
    // 0x808066FC: nop

L_80806700:
    // 0x80806700: jal         0x80806B38
    // 0x80806704: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80806B38_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80806704: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80806708: jal         0x80802228
    // 0x8080670C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x8080670C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80806710: jal         0x808056B8
    // 0x80806714: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808056B8_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80806714: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80806718: b           L_80806A64
    // 0x8080671C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80806A64;
    // 0x8080671C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80806720:
    // 0x80806720: jal         0x80802228
    // 0x80806724: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80806724: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80806728: jal         0x808056B8
    // 0x8080672C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808056B8_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x8080672C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80806730: jal         0x800D9078
    // 0x80806734: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x80806734: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    after_8:
    // 0x80806738: beq         $v0, $zero, L_80806A60
    if (ctx->r2 == 0) {
        // 0x8080673C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80806A60;
    }
    // 0x8080673C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80806740: jal         0x80109FE8
    // 0x80806744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_9;
    // 0x80806744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80806748: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8080674C: b           L_80806A60
    // 0x80806750: sb          $t8, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r24;
        goto L_80806A60;
    // 0x80806750: sb          $t8, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r24;
L_80806754:
    // 0x80806754: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80806758: jal         0x80108B04
    // 0x8080675C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_10;
    // 0x8080675C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80806760: b           L_80806A64
    // 0x80806764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80806A64;
    // 0x80806764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80806768:
    // 0x80806768: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8080676C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80806770: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80806774: beq         $t9, $zero, L_808067B4
    if (ctx->r25 == 0) {
        // 0x80806778: addiu       $a3, $t9, 0x4
        ctx->r7 = ADD32(ctx->r25, 0X4);
            goto L_808067B4;
    }
    // 0x80806778: addiu       $a3, $t9, 0x4
    ctx->r7 = ADD32(ctx->r25, 0X4);
    // 0x8080677C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80806780: jal         0x8008A0D0
    // 0x80806784: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80806784: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_11:
    // 0x80806788: beq         $v0, $zero, L_808067B4
    if (ctx->r2 == 0) {
        // 0x8080678C: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_808067B4;
    }
    // 0x8080678C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80806790: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80806794: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80806798: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080679C: lwc1        $f4, 0x48($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X48);
    // 0x808067A0: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x808067A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808067A8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808067AC: jal         0x800EF1B8
    // 0x808067B0: nop

    func_800EF1B8(rdram, ctx);
        goto after_12;
    // 0x808067B0: nop

    after_12:
L_808067B4:
    // 0x808067B4: lui         $a1, 0x3EA8
    ctx->r5 = S32(0X3EA8 << 16);
    // 0x808067B8: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x808067BC: jal         0x80101E14
    // 0x808067C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x808067C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_13:
    // 0x808067C4: beq         $v0, $zero, L_8080680C
    if (ctx->r2 == 0) {
        // 0x808067C8: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8080680C;
    }
    // 0x808067C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808067CC: lbu         $t1, 0x41($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X41);
    // 0x808067D0: beql        $t1, $zero, L_808067E4
    if (ctx->r9 == 0) {
        // 0x808067D4: lh          $v1, 0x6C($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X6C);
            goto L_808067E4;
    }
    goto skip_0;
    // 0x808067D4: lh          $v1, 0x6C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6C);
    skip_0:
    // 0x808067D8: b           L_808067E4
    // 0x808067DC: lh          $v1, 0x6A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6A);
        goto L_808067E4;
    // 0x808067DC: lh          $v1, 0x6A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6A);
    // 0x808067E0: lh          $v1, 0x6C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6C);
L_808067E4:
    // 0x808067E4: jal         0x80802248
    // 0x808067E8: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_14;
    // 0x808067E8: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    after_14:
    // 0x808067EC: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x808067F0: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x808067F4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808067F8: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x808067FC: or          $a2, $t4, $t5
    ctx->r6 = ctx->r12 | ctx->r13;
    // 0x80806800: jal         0x8010108C
    // 0x80806804: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8010108C(rdram, ctx);
        goto after_15;
    // 0x80806804: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_15:
    // 0x80806808: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
L_8080680C:
    // 0x8080680C: jal         0x80101DDC
    // 0x80806810: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x80806810: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_16:
    // 0x80806814: beql        $v0, $zero, L_80806A64
    if (ctx->r2 == 0) {
        // 0x80806818: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80806A64;
    }
    goto skip_1;
    // 0x80806818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8080681C: lbu         $t6, 0x5E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5E);
    // 0x80806820: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80806824: bne         $t6, $zero, L_80806880
    if (ctx->r14 != 0) {
        // 0x80806828: nop
    
            goto L_80806880;
    }
    // 0x80806828: nop

    // 0x8080682C: lbu         $t7, 0x5D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5D);
    // 0x80806830: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80806834: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80806838: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080683C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80806840: bne         $t9, $zero, L_8080685C
    if (ctx->r25 != 0) {
        // 0x80806844: sb          $t8, 0x5D($s0)
        MEM_B(0X5D, ctx->r16) = ctx->r24;
            goto L_8080685C;
    }
    // 0x80806844: sb          $t8, 0x5D($s0)
    MEM_B(0X5D, ctx->r16) = ctx->r24;
    // 0x80806848: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080684C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80806850: sb          $t0, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r8;
    // 0x80806854: b           L_80806A60
    // 0x80806858: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
        goto L_80806A60;
    // 0x80806858: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
L_8080685C:
    // 0x8080685C: jal         0x80800180
    // 0x80806860: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_17;
    // 0x80806860: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_17:
    // 0x80806864: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80806868: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8080686C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80806870: sb          $t1, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r9;
    // 0x80806874: sb          $t2, 0x5E($s0)
    MEM_B(0X5E, ctx->r16) = ctx->r10;
    // 0x80806878: b           L_80806A60
    // 0x8080687C: swc1        $f16, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f16.u32l;
        goto L_80806A60;
    // 0x8080687C: swc1        $f16, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f16.u32l;
L_80806880:
    // 0x80806880: jal         0x80800180
    // 0x80806884: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_18;
    // 0x80806884: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_18:
    // 0x80806888: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8080688C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80806890: sb          $t3, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r11;
    // 0x80806894: b           L_80806A60
    // 0x80806898: swc1        $f18, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f18.u32l;
        goto L_80806A60;
    // 0x80806898: swc1        $f18, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f18.u32l;
L_8080689C:
    // 0x8080689C: lbu         $t4, 0x69($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X69);
    // 0x808068A0: lbu         $t5, 0x2($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X2);
    // 0x808068A4: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x808068A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808068AC: bne         $t4, $t5, L_808068C4
    if (ctx->r12 != ctx->r13) {
        // 0x808068B0: nop
    
            goto L_808068C4;
    }
    // 0x808068B0: nop

    // 0x808068B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808068B8: sb          $t6, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r14;
    // 0x808068BC: b           L_80806A60
    // 0x808068C0: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
        goto L_80806A60;
    // 0x808068C0: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
L_808068C4:
    // 0x808068C4: jal         0x800D9078
    // 0x808068C8: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    func_800D9078(rdram, ctx);
        goto after_19;
    // 0x808068C8: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    after_19:
    // 0x808068CC: beq         $v0, $zero, L_80806A60
    if (ctx->r2 == 0) {
        // 0x808068D0: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_80806A60;
    }
    // 0x808068D0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x808068D4: b           L_80806A60
    // 0x808068D8: sb          $t7, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r15;
        goto L_80806A60;
    // 0x808068D8: sb          $t7, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r15;
L_808068DC:
    // 0x808068DC: jal         0x80101DDC
    // 0x808068E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80101DDC(rdram, ctx);
        goto after_20;
    // 0x808068E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_20:
    // 0x808068E4: beql        $v0, $zero, L_80806A64
    if (ctx->r2 == 0) {
        // 0x808068E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80806A64;
    }
    goto skip_2;
    // 0x808068E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x808068EC: lbu         $t8, 0x69($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X69);
    // 0x808068F0: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x808068F4: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x808068F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808068FC: bnel        $t8, $t9, L_80806918
    if (ctx->r24 != ctx->r25) {
        // 0x80806900: lbu         $t1, 0x5E($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X5E);
            goto L_80806918;
    }
    goto skip_3;
    // 0x80806900: lbu         $t1, 0x5E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X5E);
    skip_3:
    // 0x80806904: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80806908: sb          $t0, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r8;
    // 0x8080690C: b           L_80806A60
    // 0x80806910: swc1        $f6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f6.u32l;
        goto L_80806A60;
    // 0x80806910: swc1        $f6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f6.u32l;
    // 0x80806914: lbu         $t1, 0x5E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X5E);
L_80806918:
    // 0x80806918: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8080691C: bne         $t1, $zero, L_80806950
    if (ctx->r9 != 0) {
        // 0x80806920: nop
    
            goto L_80806950;
    }
    // 0x80806920: nop

    // 0x80806924: lbu         $t2, 0x5D($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X5D);
    // 0x80806928: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8080692C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80806930: bne         $t2, $zero, L_80806948
    if (ctx->r10 != 0) {
        // 0x80806934: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_80806948;
    }
    // 0x80806934: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80806938: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080693C: sb          $t3, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r11;
    // 0x80806940: b           L_80806A60
    // 0x80806944: swc1        $f8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f8.u32l;
        goto L_80806A60;
    // 0x80806944: swc1        $f8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f8.u32l;
L_80806948:
    // 0x80806948: b           L_80806A60
    // 0x8080694C: sb          $t4, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r12;
        goto L_80806A60;
    // 0x8080694C: sb          $t4, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r12;
L_80806950:
    // 0x80806950: b           L_80806A60
    // 0x80806954: sb          $t5, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r13;
        goto L_80806A60;
    // 0x80806954: sb          $t5, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r13;
L_80806958:
    // 0x80806958: addiu       $a0, $zero, 0x4F2
    ctx->r4 = ADD32(0, 0X4F2);
    // 0x8080695C: jal         0x80089C30
    // 0x80806960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x80806960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80806964: bnel        $v0, $zero, L_80806A64
    if (ctx->r2 != 0) {
        // 0x80806968: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80806A64;
    }
    goto skip_4;
    // 0x80806968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x8080696C: jal         0x800D9078
    // 0x80806970: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    func_800D9078(rdram, ctx);
        goto after_22;
    // 0x80806970: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    after_22:
    // 0x80806974: beq         $v0, $zero, L_80806A60
    if (ctx->r2 == 0) {
        // 0x80806978: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80806A60;
    }
    // 0x80806978: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080697C: jal         0x80109FE8
    // 0x80806980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_23;
    // 0x80806980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x80806984: lbu         $t6, 0x5F($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5F);
    // 0x80806988: beq         $t6, $zero, L_808069AC
    if (ctx->r14 == 0) {
        // 0x8080698C: nop
    
            goto L_808069AC;
    }
    // 0x8080698C: nop

    // 0x80806990: lbu         $t7, 0x69($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X69);
    // 0x80806994: lbu         $t8, 0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2);
    // 0x80806998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080699C: beq         $t7, $t8, L_808069AC
    if (ctx->r15 == ctx->r24) {
        // 0x808069A0: nop
    
            goto L_808069AC;
    }
    // 0x808069A0: nop

    // 0x808069A4: b           L_80806A64
    // 0x808069A8: sb          $zero, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = 0;
        goto L_80806A64;
    // 0x808069A8: sb          $zero, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = 0;
L_808069AC:
    // 0x808069AC: jal         0x800878A0
    // 0x808069B0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_24;
    // 0x808069B0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_24:
    // 0x808069B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808069B8: beq         $v0, $at, L_808069D8
    if (ctx->r2 == ctx->r1) {
        // 0x808069BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808069D8;
    }
    // 0x808069BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808069C0: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x808069C4: sb          $t9, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r25;
    // 0x808069C8: jal         0x800F7B9C
    // 0x808069CC: addiu       $a1, $zero, 0x8E
    ctx->r5 = ADD32(0, 0X8E);
    func_800F7B9C(rdram, ctx);
        goto after_25;
    // 0x808069CC: addiu       $a1, $zero, 0x8E
    ctx->r5 = ADD32(0, 0X8E);
    after_25:
    // 0x808069D0: b           L_80806A64
    // 0x808069D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80806A64;
    // 0x808069D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808069D8:
    // 0x808069D8: jal         0x80806C08
    // 0x808069DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80806C08_chdiggerboss(rdram, ctx);
        goto after_26;
    // 0x808069DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_26:
    // 0x808069E0: b           L_80806A64
    // 0x808069E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80806A64;
    // 0x808069E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808069E8:
    // 0x808069E8: jal         0x80802228
    // 0x808069EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_27;
    // 0x808069EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_27:
    // 0x808069F0: jal         0x808056B8
    // 0x808069F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808056B8_chdiggerboss(rdram, ctx);
        goto after_28;
    // 0x808069F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_28:
    // 0x808069F8: jal         0x80806C08
    // 0x808069FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80806C08_chdiggerboss(rdram, ctx);
        goto after_29;
    // 0x808069FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_29:
    // 0x80806A00: b           L_80806A64
    // 0x80806A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80806A64;
    // 0x80806A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80806A08:
    // 0x80806A08: jal         0x80802228
    // 0x80806A0C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_30;
    // 0x80806A0C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_30:
    // 0x80806A10: jal         0x808056B8
    // 0x80806A14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808056B8_chdiggerboss(rdram, ctx);
        goto after_31;
    // 0x80806A14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_31:
    // 0x80806A18: jal         0x800D9078
    // 0x80806A1C: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    func_800D9078(rdram, ctx);
        goto after_32;
    // 0x80806A1C: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    after_32:
    // 0x80806A20: beql        $v0, $zero, L_80806A64
    if (ctx->r2 == 0) {
        // 0x80806A24: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80806A64;
    }
    goto skip_5;
    // 0x80806A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80806A28: lbu         $t0, 0x69($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X69);
    // 0x80806A2C: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
    // 0x80806A30: sb          $zero, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = 0;
    // 0x80806A34: bne         $t0, $t1, L_80806A58
    if (ctx->r8 != ctx->r9) {
        // 0x80806A38: nop
    
            goto L_80806A58;
    }
    // 0x80806A38: nop

    // 0x80806A3C: jal         0x80806F8C
    // 0x80806A40: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80806F8C_chdiggerboss(rdram, ctx);
        goto after_33;
    // 0x80806A40: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_33:
    // 0x80806A44: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80806A48: jal         0x80806EE4
    // 0x80806A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80806EE4_chdiggerboss(rdram, ctx);
        goto after_34;
    // 0x80806A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_34:
    // 0x80806A50: b           L_80806A64
    // 0x80806A54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80806A64;
    // 0x80806A54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80806A58:
    // 0x80806A58: b           L_80806A64
    // 0x80806A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80806A64;
    // 0x80806A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806A60:
    // 0x80806A60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80806A64:
    // 0x80806A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80806A68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80806A6C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80806A70: jr          $ra
    // 0x80806A74: nop

    return;
    // 0x80806A74: nop

;}
RECOMP_FUNC void _chmrtannoy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B58: syscall     422
    recomp_syscall_handler(rdram, ctx, 0x80086B58);
    return;
    // 0x80086B5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800D89C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D89C8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800D89CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D89D0: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800D89D4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800D89D8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D89DC: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800D89E0: jal         0x800D8988
    // 0x800D89E4: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    func_800D8988(rdram, ctx);
        goto after_0;
    // 0x800D89E4: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D89E8: lbu         $t8, 0x1A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1A);
    // 0x800D89EC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800D89F0: addiu       $a1, $t3, 0x8
    ctx->r5 = ADD32(ctx->r11, 0X8);
    // 0x800D89F4: bnel        $t8, $zero, L_800D8A08
    if (ctx->r24 != 0) {
        // 0x800D89F8: sb          $zero, 0x1A($t3)
        MEM_B(0X1A, ctx->r11) = 0;
            goto L_800D8A08;
    }
    goto skip_0;
    // 0x800D89F8: sb          $zero, 0x1A($t3)
    MEM_B(0X1A, ctx->r11) = 0;
    skip_0:
    // 0x800D89FC: b           L_800D8B70
    // 0x800D8A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D8B70;
    // 0x800D8A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D8A04: sb          $zero, 0x1A($t3)
    MEM_B(0X1A, ctx->r11) = 0;
L_800D8A08:
    // 0x800D8A08: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800D8A0C: jal         0x800EEAD4
    // 0x800D8A10: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    func_800EEAD4(rdram, ctx);
        goto after_1;
    // 0x800D8A10: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    after_1:
    // 0x800D8A14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D8A18: lwc1        $f4, 0x5CF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5CF0);
    // 0x800D8A1C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800D8A20: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800D8A24: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800D8A28: addiu       $t2, $sp, 0x58
    ctx->r10 = ADD32(ctx->r29, 0X58);
    // 0x800D8A2C: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x800D8A30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D8A34: bc1f        L_800D8A44
    if (!c1cs) {
        // 0x800D8A38: or          $t0, $t3, $zero
        ctx->r8 = ctx->r11 | 0;
            goto L_800D8A44;
    }
    // 0x800D8A38: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x800D8A3C: b           L_800D8B70
    // 0x800D8A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D8B70;
    // 0x800D8A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D8A44:
    // 0x800D8A44: lh          $t9, 0x14($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X14);
    // 0x800D8A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D8A4C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800D8A50: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x800D8A54: addu        $a3, $t4, $t1
    ctx->r7 = ADD32(ctx->r12, ctx->r9);
    // 0x800D8A58: addiu       $a0, $a3, 0x18
    ctx->r4 = ADD32(ctx->r7, 0X18);
    // 0x800D8A5C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D8A60: beq         $v0, $a1, L_800D8A88
    if (ctx->r2 == ctx->r5) {
        // 0x800D8A64: lh          $t5, 0x0($a0)
        ctx->r13 = MEM_H(ctx->r4, 0X0);
            goto L_800D8A88;
    }
    // 0x800D8A64: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
L_800D8A68:
    // 0x800D8A68: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800D8A6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D8A70: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D8A74: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D8A78: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800D8A7C: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800D8A80: bne         $v0, $a1, L_800D8A68
    if (ctx->r2 != ctx->r5) {
        // 0x800D8A84: lh          $t5, 0x0($a0)
        ctx->r13 = MEM_H(ctx->r4, 0X0);
            goto L_800D8A68;
    }
    // 0x800D8A84: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
L_800D8A88:
    // 0x800D8A88: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800D8A8C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D8A90: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800D8A94: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D8A98: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800D8A9C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x800D8AA0: bne         $a2, $t2, L_800D8A44
    if (ctx->r6 != ctx->r10) {
        // 0x800D8AA4: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_800D8A44;
    }
    // 0x800D8AA4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800D8AA8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x800D8AAC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800D8AB0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800D8AB4: jal         0x800EFB24
    // 0x800D8AB8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x800D8AB8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_2:
    // 0x800D8ABC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800D8AC0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800D8AC4: jal         0x800EFB24
    // 0x800D8AC8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x800D8AC8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x800D8ACC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800D8AD0: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800D8AD4: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800D8AD8: lwc1        $f2, 0x0($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800D8ADC: lwc1        $f0, 0x4($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800D8AE0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800D8AE4: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800D8AE8: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x800D8AEC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800D8AF0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800D8AF4: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D8AF8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D8AFC: add.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D8B00: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800D8B04: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800D8B08: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800D8B0C: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800D8B10: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D8B14: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800D8B18: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800D8B1C: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800D8B20: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800D8B24: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800D8B28: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800D8B2C: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800D8B30: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D8B34: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800D8B38: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800D8B3C: jal         0x800EFA4C
    // 0x800D8B40: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x800D8B40: nop

    after_4:
    // 0x800D8B44: jal         0x80019CD4
    // 0x800D8B48: nop

    func_80019CD4(rdram, ctx);
        goto after_5;
    // 0x800D8B48: nop

    after_5:
    // 0x800D8B4C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x800D8B50: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x800D8B54: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x800D8B58: jal         0x80019750
    // 0x800D8B5C: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    func_80019750(rdram, ctx);
        goto after_6;
    // 0x800D8B5C: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    after_6:
    // 0x800D8B60: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x800D8B64: jal         0x80019224
    // 0x800D8B68: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80019224(rdram, ctx);
        goto after_7;
    // 0x800D8B68: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_7:
    // 0x800D8B6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D8B70:
    // 0x800D8B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8B74: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x800D8B78: jr          $ra
    // 0x800D8B7C: nop

    return;
    // 0x800D8B7C: nop

;}
RECOMP_FUNC void func_80801974_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801974: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801978: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080197C: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80801980: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801984: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801988: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080198C: beq         $a1, $at, L_808019E4
    if (ctx->r5 == ctx->r1) {
        // 0x80801990: addiu       $a2, $zero, 0x7
        ctx->r6 = ADD32(0, 0X7);
            goto L_808019E4;
    }
    // 0x80801990: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80801994: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80801998: beq         $a1, $at, L_808019DC
    if (ctx->r5 == ctx->r1) {
        // 0x8080199C: addiu       $at, $zero, 0xFA2
        ctx->r1 = ADD32(0, 0XFA2);
            goto L_808019DC;
    }
    // 0x8080199C: addiu       $at, $zero, 0xFA2
    ctx->r1 = ADD32(0, 0XFA2);
    // 0x808019A0: beq         $a1, $at, L_808019C0
    if (ctx->r5 == ctx->r1) {
        // 0x808019A4: addiu       $at, $zero, 0xFA3
        ctx->r1 = ADD32(0, 0XFA3);
            goto L_808019C0;
    }
    // 0x808019A4: addiu       $at, $zero, 0xFA3
    ctx->r1 = ADD32(0, 0XFA3);
    // 0x808019A8: beq         $a1, $at, L_808019C0
    if (ctx->r5 == ctx->r1) {
        // 0x808019AC: addiu       $at, $zero, 0xFA4
        ctx->r1 = ADD32(0, 0XFA4);
            goto L_808019C0;
    }
    // 0x808019AC: addiu       $at, $zero, 0xFA4
    ctx->r1 = ADD32(0, 0XFA4);
    // 0x808019B0: beq         $a1, $at, L_808019E8
    if (ctx->r5 == ctx->r1) {
        // 0x808019B4: addiu       $at, $zero, 0xFB3
        ctx->r1 = ADD32(0, 0XFB3);
            goto L_808019E8;
    }
    // 0x808019B4: addiu       $at, $zero, 0xFB3
    ctx->r1 = ADD32(0, 0XFB3);
    // 0x808019B8: beq         $a1, $at, L_808019DC
    if (ctx->r5 == ctx->r1) {
        // 0x808019BC: nop
    
            goto L_808019DC;
    }
    // 0x808019BC: nop

L_808019C0:
    // 0x808019C0: jal         0x800F54E4
    // 0x808019C4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808019C4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x808019C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808019CC: jal         0x800F7F98
    // 0x808019D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_1;
    // 0x808019D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808019D4: b           L_808019E8
    // 0x808019D8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
        goto L_808019E8;
    // 0x808019D8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_808019DC:
    // 0x808019DC: b           L_808019E8
    // 0x808019E0: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
        goto L_808019E8;
    // 0x808019E0: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
L_808019E4:
    // 0x808019E4: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
L_808019E8:
    // 0x808019E8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808019EC: addiu       $t7, $zero, 0x3F
    ctx->r15 = ADD32(0, 0X3F);
    // 0x808019F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808019F4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x808019F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808019FC: jal         0x8008A208
    // 0x80801A00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80801A00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80801A04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801A08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801A0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801A10: jr          $ra
    // 0x80801A14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80801A14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80800990_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800990: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800998: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080099C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808009A0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x808009A4: jal         0x8008A0E8
    // 0x808009A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808009A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x808009AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1284, 0X1490) << 16);
    // 0x808009B0: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x808009B4: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808009B8: addiu       $a2, $a2, 0x1490
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1284, 0X1490));
    // 0x808009BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009C0: jal         0x80089D20
    // 0x808009C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808009C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x808009C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009D0: jr          $ra
    // 0x808009D4: nop

    return;
    // 0x808009D4: nop

;}
RECOMP_FUNC void func_80092234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092234: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009223C: sb          $v0, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r2;
    // 0x80092240: lw          $t7, 0x50($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X50);
    // 0x80092244: jr          $ra
    // 0x80092248: sb          $v0, 0x16($t7)
    MEM_B(0X16, ctx->r15) = ctx->r2;
    return;
    // 0x80092248: sb          $v0, 0x16($t7)
    MEM_B(0X16, ctx->r15) = ctx->r2;
;}
RECOMP_FUNC void func_8080070C_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080070C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800714: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800718: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080071C: jal         0x80800990
    // 0x80800720: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800990_chmrsboggy(rdram, ctx);
        goto after_0;
    // 0x80800720: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800728: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8080072C: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    // 0x80800730: jr          $ra
    // 0x80800734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80096364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009636C: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096370: jal         0x800C6784
    // 0x80096374: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C6784(rdram, ctx);
        goto after_0;
    // 0x80096374: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80096378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009637C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096380: jr          $ra
    // 0x80096384: nop

    return;
    // 0x80096384: nop

;}
RECOMP_FUNC void func_800CFFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFFBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CFFC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CFFC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CFFC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CFFCC: jal         0x800D0820
    // 0x800CFFD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D0820(rdram, ctx);
        goto after_0;
    // 0x800CFFD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800CFFD4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CFFD8: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CFFDC: bnel        $at, $zero, L_800D0008
    if (ctx->r1 != 0) {
        // 0x800CFFE0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D0008;
    }
    goto skip_0;
    // 0x800CFFE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800CFFE4: jal         0x800D0894
    // 0x800CFFE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800D0894(rdram, ctx);
        goto after_1;
    // 0x800CFFE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800CFFEC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800CFFF0: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800CFFF4: bnel        $at, $zero, L_800D0008
    if (ctx->r1 != 0) {
        // 0x800CFFF8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D0008;
    }
    goto skip_1;
    // 0x800CFFF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800CFFFC: b           L_800D0008
    // 0x800D0000: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D0008;
    // 0x800D0000: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D0004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D0008:
    // 0x800D0008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D000C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D0010: jr          $ra
    // 0x800D0014: nop

    return;
    // 0x800D0014: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F90: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800F94: jal         0x8009D3A8
    // 0x80800F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x80800F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F9C: jal         0x808000CC
    // 0x80800FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000CC_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x80800FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800FA4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800FA8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB0: jal         0x800A2CE8
    // 0x80800FB4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_2;
    // 0x80800FB4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80800FB8: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800FBC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FC4: jal         0x800A2CE8
    // 0x80800FC8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_3;
    // 0x80800FC8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x80800FCC: jal         0x8009EF10
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_4;
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800FD4: bne         $v0, $zero, L_80800FF0
    if (ctx->r2 != 0) {
        // 0x80800FD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FF0;
    }
    // 0x80800FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FDC: jal         0x8009BCD4
    // 0x80800FE0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_5;
    // 0x80800FE0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80800FE4: beq         $v0, $zero, L_80800FF0
    if (ctx->r2 == 0) {
        // 0x80800FE8: addiu       $t6, $zero, 0xB3
        ctx->r14 = ADD32(0, 0XB3);
            goto L_80800FF0;
    }
    // 0x80800FE8: addiu       $t6, $zero, 0xB3
    ctx->r14 = ADD32(0, 0XB3);
    // 0x80800FEC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800FF0:
    // 0x80800FF0: jal         0x8008E148
    // 0x80800FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_6;
    // 0x80800FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800FF8: beq         $v0, $zero, L_8080100C
    if (ctx->r2 == 0) {
        // 0x80800FFC: nop
    
            goto L_8080100C;
    }
    // 0x80800FFC: nop

    // 0x80801000: jal         0x800848B0
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_7;
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801008: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_8080100C:
    // 0x8080100C: jal         0x8008DD04
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_8;
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801014: beq         $v0, $zero, L_80801020
    if (ctx->r2 == 0) {
        // 0x80801018: addiu       $t7, $zero, 0xAD
        ctx->r15 = ADD32(0, 0XAD);
            goto L_80801020;
    }
    // 0x80801018: addiu       $t7, $zero, 0xAD
    ctx->r15 = ADD32(0, 0XAD);
    // 0x8080101C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80801020:
    // 0x80801020: jal         0x808003B8
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003B8_bsstonehead(rdram, ctx);
        goto after_9;
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801028: beq         $v0, $zero, L_80801038
    if (ctx->r2 == 0) {
        // 0x8080102C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801038;
    }
    // 0x8080102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801030: addiu       $t8, $zero, 0xAE
    ctx->r24 = ADD32(0, 0XAE);
    // 0x80801034: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80801038:
    // 0x80801038: jal         0x80091A58
    // 0x8080103C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_10;
    // 0x8080103C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_10:
    // 0x80801040: beq         $v0, $zero, L_80801050
    if (ctx->r2 == 0) {
        // 0x80801044: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801050;
    }
    // 0x80801044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801048: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x8080104C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80801050:
    // 0x80801050: jal         0x80091A94
    // 0x80801054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_newlyReleased(rdram, ctx);
        goto after_11;
    // 0x80801054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80801058: beq         $v0, $zero, L_80801080
    if (ctx->r2 == 0) {
        // 0x8080105C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801080;
    }
    // 0x8080105C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801064: jal         0x80091940
    // 0x80801068: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bakey_func_80091940(rdram, ctx);
        goto after_12;
    // 0x80801068: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x8080106C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801074: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801078: jal         0x80084468
    // 0x8080107C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _baattach_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x8080107C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
L_80801080:
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801084: jal         0x8009E5C8
    // 0x80801088: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x80801088: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x8080108C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801090: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801094: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801098: jr          $ra
    // 0x8080109C: nop

    return;
    // 0x8080109C: nop

;}
RECOMP_FUNC void _bapreload_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F38: syscall     143
    recomp_syscall_handler(rdram, ctx, 0x80084F38);
    return;
    // 0x80084F3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chwitchytents_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(816, 0X98) << 16);
    // 0x80800044: jr          $ra
    // 0x80800048: addiu       $v0, $v0, 0x98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(816, 0X98));
    return;
    // 0x80800048: addiu       $v0, $v0, 0x98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(816, 0X98));
    // 0x8080004C: nop

;}
RECOMP_FUNC void func_80807F9C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807FA4: jal         0x80807FBC
    // 0x80807FA8: nop

    func_80807FBC_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80807FA8: nop

    after_0:
    // 0x80807FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807FB4: jr          $ra
    // 0x80807FB8: nop

    return;
    // 0x80807FB8: nop

;}
RECOMP_FUNC void sucoasterhit_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3302, 0XCB0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xCB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3302, 0XCB0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xCB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3302, 0XCB0));
;}
RECOMP_FUNC void _glrecord_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886A8: syscall     698
    recomp_syscall_handler(rdram, ctx, 0x800886A8);
    return;
    // 0x800886AC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8010EECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010EECC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010EED0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010EED4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010EED8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010EEDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010EEE0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8010EEE4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8010EEE8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8010EEEC: jal         0x800DF8D4
    // 0x8010EEF0: sw          $a0, 0x7080($at)
    MEM_W(0X7080, ctx->r1) = ctx->r4;
    func_800DF8D4(rdram, ctx);
        goto after_0;
    // 0x8010EEF0: sw          $a0, 0x7080($at)
    MEM_W(0X7080, ctx->r1) = ctx->r4;
    after_0:
    // 0x8010EEF4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010EEF8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010EEFC: addiu       $v1, $v1, 0x7080
    ctx->r3 = ADD32(ctx->r3, 0X7080);
    // 0x8010EF00: addiu       $t6, $t6, 0x709C
    ctx->r14 = ADD32(ctx->r14, 0X709C);
    // 0x8010EF04: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
    // 0x8010EF08: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x8010EF0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010EF10: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8010EF14: jal         0x8010EACC
    // 0x8010EF18: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_8010EACC(rdram, ctx);
        goto after_1;
    // 0x8010EF18: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x8010EF1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010EF20: jal         0x800C87B8
    // 0x8010EF24: addiu       $a0, $a0, 0x7084
    ctx->r4 = ADD32(ctx->r4, 0X7084);
    func_800C87B8(rdram, ctx);
        goto after_2;
    // 0x8010EF24: addiu       $a0, $a0, 0x7084
    ctx->r4 = ADD32(ctx->r4, 0X7084);
    after_2:
    // 0x8010EF28: jal         0x800DF8B4
    // 0x8010EF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8B4(rdram, ctx);
        goto after_3;
    // 0x8010EF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010EF30: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8010EF34: jal         0x800DF8CC
    // 0x8010EF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8CC(rdram, ctx);
        goto after_4;
    // 0x8010EF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8010EF3C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8010EF40: jal         0x800DF8BC
    // 0x8010EF44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8BC(rdram, ctx);
        goto after_5;
    // 0x8010EF44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8010EF48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8010EF4C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8010EF50: jal         0x8010EBE4
    // 0x8010EF54: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_8010EBE4(rdram, ctx);
        goto after_6;
    // 0x8010EF54: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x8010EF58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010EF5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010EF60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8010EF64: jr          $ra
    // 0x8010EF68: nop

    return;
    // 0x8010EF68: nop

    // 0x8010EF6C: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089548: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089548);
    return;
    // 0x8008954C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void bsbwhirl_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E18: jal         0x800839C8
    // 0x80800E1C: nop

    _bsrest_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x80800E1C: nop

    after_0:
    // 0x80800E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E28: jr          $ra
    // 0x80800E2C: nop

    return;
    // 0x80800E2C: nop

;}
RECOMP_FUNC void func_80105A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105A9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105AA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105AA4: jal         0x80105494
    // 0x80105AA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80105AA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80105AAC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80105AB0: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x80105AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105AB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105ABC: jr          $ra
    // 0x80105AC0: nop

    return;
    // 0x80105AC0: nop

;}
RECOMP_FUNC void func_800B8CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8CBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B8CC0: addiu       $v0, $v0, -0x7D40
    ctx->r2 = ADD32(ctx->r2, -0X7D40);
    // 0x800B8CC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B8CC8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B8CCC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800B8CD0: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800B8CD4: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // 0x800B8CD8: jr          $ra
    // 0x800B8CDC: sb          $a2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r6;
    return;
    // 0x800B8CDC: sb          $a2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_800C9974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C997C: jal         0x800FC63C
    // 0x800C9980: nop

    func_800FC63C(rdram, ctx);
        goto after_0;
    // 0x800C9980: nop

    after_0:
    // 0x800C9984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C998C: jr          $ra
    // 0x800C9990: nop

    return;
    // 0x800C9990: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080356C: beq         $a1, $zero, L_80803584
    if (ctx->r5 == 0) {
        // 0x80803570: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80803584;
    }
    // 0x80803570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803574: lbu         $t7, 0x1E6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E6);
    // 0x80803578: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8080357C: b           L_80803590
    // 0x80803580: sb          $t8, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r24;
        goto L_80803590;
    // 0x80803580: sb          $t8, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r24;
L_80803584:
    // 0x80803584: lbu         $t9, 0x1E6($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E6);
    // 0x80803588: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x8080358C: sb          $t0, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r8;
L_80803590:
    // 0x80803590: jal         0x80802BF4
    // 0x80803594: nop

    func_80802BF4_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80803594: nop

    after_0:
    // 0x80803598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080359C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808035A0: jr          $ra
    // 0x808035A4: nop

    return;
    // 0x808035A4: nop

;}
RECOMP_FUNC void func_800FA508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA508: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FA50C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FA510: lbu         $t6, 0x57B0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X57B0);
    // 0x800FA514: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800FA518: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800FA51C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800FA520: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800FA524: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800FA528: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800FA52C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800FA530: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800FA534: beq         $t6, $zero, L_800FA5E0
    if (ctx->r14 == 0) {
        // 0x800FA538: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800FA5E0;
    }
    // 0x800FA538: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FA53C: jal         0x800A9C98
    // 0x800FA540: nop

    func_800A9C98(rdram, ctx);
        goto after_0;
    // 0x800FA540: nop

    after_0:
    // 0x800FA544: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x800FA548: bne         $v1, $zero, L_800FA55C
    if (ctx->r3 != 0) {
        // 0x800FA54C: nop
    
            goto L_800FA55C;
    }
    // 0x800FA54C: nop

    // 0x800FA550: jal         0x800DB9B0
    // 0x800FA554: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x800FA554: nop

    after_1:
    // 0x800FA558: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_800FA55C:
    // 0x800FA55C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800FA560: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800FA564: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800FA568: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800FA56C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800FA570: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800FA574: addiu       $s2, $s2, 0x39B4
    ctx->r18 = ADD32(ctx->r18, 0X39B4);
    // 0x800FA578: addiu       $s3, $s3, 0x3998
    ctx->r19 = ADD32(ctx->r19, 0X3998);
    // 0x800FA57C: addiu       $s4, $s4, 0x3D6C
    ctx->r20 = ADD32(ctx->r20, 0X3D6C);
    // 0x800FA580: addiu       $s5, $s5, 0x3DC0
    ctx->r21 = ADD32(ctx->r21, 0X3DC0);
    // 0x800FA584: addiu       $s0, $s0, 0x3880
    ctx->r16 = ADD32(ctx->r16, 0X3880);
    // 0x800FA588: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
L_800FA58C:
    // 0x800FA58C: xor         $v0, $s0, $s2
    ctx->r2 = ctx->r16 ^ ctx->r18;
    // 0x800FA590: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x800FA594: beql        $a1, $zero, L_800FA5D8
    if (ctx->r5 == 0) {
        // 0x800FA598: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800FA5D8;
    }
    goto skip_0;
    // 0x800FA598: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_0:
    // 0x800FA59C: beq         $v1, $zero, L_800FA5B8
    if (ctx->r3 == 0) {
        // 0x800FA5A0: xor         $v0, $s0, $s3
        ctx->r2 = ctx->r16 ^ ctx->r19;
            goto L_800FA5B8;
    }
    // 0x800FA5A0: xor         $v0, $s0, $s3
    ctx->r2 = ctx->r16 ^ ctx->r19;
    // 0x800FA5A4: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x800FA5A8: beq         $v1, $zero, L_800FA5B8
    if (ctx->r3 == 0) {
        // 0x800FA5AC: nop
    
            goto L_800FA5B8;
    }
    // 0x800FA5AC: nop

    // 0x800FA5B0: xor         $v1, $s0, $s4
    ctx->r3 = ctx->r16 ^ ctx->r20;
    // 0x800FA5B4: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
L_800FA5B8:
    // 0x800FA5B8: beq         $s1, $zero, L_800FA5C8
    if (ctx->r17 == 0) {
        // 0x800FA5BC: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800FA5C8;
    }
    // 0x800FA5BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800FA5C0: bnel        $v1, $zero, L_800FA5D8
    if (ctx->r3 != 0) {
        // 0x800FA5C4: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800FA5D8;
    }
    goto skip_1;
    // 0x800FA5C4: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_1:
L_800FA5C8:
    // 0x800FA5C8: lh          $a2, 0x6($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X6);
    // 0x800FA5CC: jal         0x8008A640
    // 0x800FA5D0: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    _scinfobar_entrypoint_24(rdram, ctx);
        goto after_2;
    // 0x800FA5D0: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    after_2:
    // 0x800FA5D4: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_800FA5D8:
    // 0x800FA5D8: bnel        $s0, $s5, L_800FA58C
    if (ctx->r16 != ctx->r21) {
        // 0x800FA5DC: lw          $a1, 0x18($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X18);
            goto L_800FA58C;
    }
    goto skip_2;
    // 0x800FA5DC: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    skip_2:
L_800FA5E0:
    // 0x800FA5E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800FA5E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FA5E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA5EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800FA5F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800FA5F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800FA5F8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800FA5FC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800FA600: jr          $ra
    // 0x800FA604: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800FA604: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800D3AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3AF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3AF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3AF8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D3AFC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D3B00: addiu       $a1, $a1, 0x1864
    ctx->r5 = ADD32(ctx->r5, 0X1864);
    // 0x800D3B04: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800D3B08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D3B0C: jal         0x800D3B6C
    // 0x800D3B10: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    func_800D3B6C(rdram, ctx);
        goto after_0;
    // 0x800D3B10: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    after_0:
    // 0x800D3B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3B1C: jr          $ra
    // 0x800D3B20: nop

    return;
    // 0x800D3B20: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083748: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083748);
    return;
    // 0x8008374C: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void _bsbee_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082838: syscall     15
    recomp_syscall_handler(rdram, ctx, 0x80082838);
    return;
    // 0x8008283C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800AD0_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800ADC: jal         0x80100094
    // 0x80800AE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800AE4: beq         $v0, $zero, L_80800AF4
    if (ctx->r2 == 0) {
        // 0x80800AE8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800AF4;
    }
    // 0x80800AE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800AEC: jal         0x800897C8
    // 0x80800AF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800AF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800AF4:
    // 0x80800AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AFC: jr          $ra
    // 0x80800B00: nop

    return;
    // 0x80800B00: nop

    // 0x80800B04: nop

    // 0x80800B08: nop

    // 0x80800B0C: nop

;}
RECOMP_FUNC void suflamefx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800060: jal         0x80100074
    // 0x80800064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_800CAF00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAF00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CAF04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CAF08: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800CAF0C: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800CAF10: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800CAF14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CAF18: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800CAF1C: jal         0x800136E4
    // 0x800CAF20: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x800CAF20: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x800CAF24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CAF28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CAF2C: jr          $ra
    // 0x800CAF30: nop

    return;
    // 0x800CAF30: nop

;}
RECOMP_FUNC void func_808046C4_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808046C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808046C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808046CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808046D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808046D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808046D8: jal         0x80100094
    // 0x808046DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808046DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808046E0: lbu         $t7, 0x64($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X64);
    // 0x808046E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808046E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808046EC: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x808046F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808046F4: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
    // 0x808046F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808046FC: jal         0x8010A590
    // 0x80804700: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x80804700: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80804704: jal         0x800EA05C
    // 0x80804708: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80804708: nop

    after_2:
    // 0x8080470C: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x80804710: beq         $v0, $at, L_80804764
    if (ctx->r2 == ctx->r1) {
        // 0x80804714: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_80804764;
    }
    // 0x80804714: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80804718: addiu       $at, $zero, 0xC6
    ctx->r1 = ADD32(0, 0XC6);
    // 0x8080471C: beq         $v0, $at, L_8080474C
    if (ctx->r2 == ctx->r1) {
        // 0x80804720: addiu       $at, $zero, 0xC8
        ctx->r1 = ADD32(0, 0XC8);
            goto L_8080474C;
    }
    // 0x80804720: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80804724: beq         $v0, $at, L_80804754
    if (ctx->r2 == ctx->r1) {
        // 0x80804728: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80804754;
    }
    // 0x80804728: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080472C: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x80804730: beq         $v0, $at, L_8080475C
    if (ctx->r2 == ctx->r1) {
        // 0x80804734: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8080475C;
    }
    // 0x80804734: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80804738: addiu       $at, $zero, 0x17F
    ctx->r1 = ADD32(0, 0X17F);
    // 0x8080473C: beq         $v0, $at, L_8080476C
    if (ctx->r2 == ctx->r1) {
        // 0x80804740: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8080476C;
    }
    // 0x80804740: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80804744: b           L_808047A8
    // 0x80804748: nop

        goto L_808047A8;
    // 0x80804748: nop

L_8080474C:
    // 0x8080474C: b           L_808047A8
    // 0x80804750: sb          $zero, 0x14($s1)
    MEM_B(0X14, ctx->r17) = 0;
        goto L_808047A8;
    // 0x80804750: sb          $zero, 0x14($s1)
    MEM_B(0X14, ctx->r17) = 0;
L_80804754:
    // 0x80804754: b           L_808047A8
    // 0x80804758: sb          $t9, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r25;
        goto L_808047A8;
    // 0x80804758: sb          $t9, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r25;
L_8080475C:
    // 0x8080475C: b           L_808047A8
    // 0x80804760: sb          $t0, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r8;
        goto L_808047A8;
    // 0x80804760: sb          $t0, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r8;
L_80804764:
    // 0x80804764: b           L_808047A8
    // 0x80804768: sb          $t1, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r9;
        goto L_808047A8;
    // 0x80804768: sb          $t1, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r9;
L_8080476C:
    // 0x8080476C: jal         0x80088368
    // 0x80804770: sb          $t2, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r10;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80804770: sb          $t2, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r10;
    after_3:
    // 0x80804774: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80804778: andi        $t3, $v1, 0x1FF
    ctx->r11 = ctx->r3 & 0X1FF;
    // 0x8080477C: sltu        $at, $t3, $v0
    ctx->r1 = ctx->r11 < ctx->r2 ? 1 : 0;
    // 0x80804780: beq         $at, $zero, L_808047A8
    if (ctx->r1 == 0) {
        // 0x80804784: nop
    
            goto L_808047A8;
    }
    // 0x80804784: nop

    // 0x80804788: lbu         $t5, 0x64($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X64);
    // 0x8080478C: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x80804790: andi        $t9, $t8, 0x18
    ctx->r25 = ctx->r24 & 0X18;
    // 0x80804794: ori         $t0, $t5, 0x20
    ctx->r8 = ctx->r13 | 0X20;
    // 0x80804798: andi        $t1, $t0, 0xE7
    ctx->r9 = ctx->r8 & 0XE7;
    // 0x8080479C: sb          $t0, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r8;
    // 0x808047A0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808047A4: sb          $t2, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r10;
L_808047A8:
    // 0x808047A8: jal         0x800BD0DC
    // 0x808047AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800BD0DC(rdram, ctx);
        goto after_4;
    // 0x808047AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x808047B0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x808047B4: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808047B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808047BC: andi        $t3, $a1, 0x1FF
    ctx->r11 = ctx->r5 & 0X1FF;
    // 0x808047C0: jal         0x800BD268
    // 0x808047C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800BD268(rdram, ctx);
        goto after_5;
    // 0x808047C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x808047C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808047CC: jal         0x800BD28C
    // 0x808047D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BD28C(rdram, ctx);
        goto after_6;
    // 0x808047D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808047D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808047D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808047DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808047E0: jr          $ra
    // 0x808047E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808047E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
